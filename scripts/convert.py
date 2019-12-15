import re
import sys
import io
import subprocess
import pygit2

repo = pygit2.Repository('.')

pattern = re.compile(rb'^(arch/[^/]+/)?include/uapi/(.*\.h)$')

skipped = {}
parents = {}

def match(path):
	m = pattern.match(path)
	if not m:
		return None
	return (m.group(1) or b'include/') + m.group(2)

def process(data):
	p = subprocess.Popen(['sed', '-E', '-f', 'scripts/header.sed'], stdin=subprocess.PIPE, stdout=subprocess.PIPE)
	data1, _ = p.communicate(data)
	if p.returncode != 0:
		raise subprocess.CalledProcessError(p.returncode, p.args)
	p = subprocess.Popen(['scripts/unifdef', '-U__KERNEL__', '-D__EXPORTED_HEADERS__'], stdin=subprocess.PIPE, stdout=subprocess.PIPE)
	data2, _ = p.communicate(data1)
	if p.returncode > 1:
		return data1  # If unifdef failed, just use the sed output
	if p.returncode < 0:
		raise subprocess.CalledProcessError(p.returncode, p.args)
	return data2

def has_parent(a, b):
	while a:
		if a == b:
			return True
		a = parents.get(a)
	return False

stdin = sys.stdin.buffer
stdout = sys.stdout.buffer

while True:
	line = stdin.readline()
	if line.startswith(b'commit '):
		commit = io.BytesIO()
		commit.write(line)

		line = stdin.readline()
		mark = None
		if line.startswith(b'mark '):
			mark = line[len(b'mark '):-1]
			commit.write(line)
			line = stdin.readline()

		original_oid = None
		if line.startswith(b'original-oid '):
			original_oid = line[len(b'original-oid '):-1]
			line = stdin.readline()

		if line.startswith(b'author '):
			commit.write(line)
			line = stdin.readline()

		if line.startswith(b'committer '):
			commit.write(line)
			line = stdin.readline()

		if line.startswith(b'encoding '):
			commit.write(line)
			line = stdin.readline()

		if line.startswith(b'data '):
			commit.write(line)
			size = int(line[len(b'data '):-1].decode('ascii'))
			message = stdin.read(size)
			commit.write(message)
			line = stdin.readline()
			if line == b'\n':
				line = stdin.readline()
			commit.write(b'\n')

		from_ = None
		if line.startswith(b'from '):
			from_ = line[len('from '):-1]
			from_ = skipped.get(from_, from_)
			if from_:
				commit.write(b'from ' + from_ + b'\n')
			line = stdin.readline()

		keep = False

		merges = set()
		while line.startswith(b'merge '):
			merge = line[len('merge '):-1]
			merge = skipped.get(merge, merge)
			if merge and merge not in merges and not has_parent(from_, merge):
				if not keep:
					stdout.write(commit.getvalue())
					keep = True
				stdout.write(b'merge ' + merge + b'\n')
				merges.add(merge)
			line = stdin.readline()
		
		while True:
			if line.startswith(b'M '):
				_, mode, dataref, path = line.split()
				if dataref == b'inline':
					raise NotImplementedError('inline data not supported')
				if path == b'scripts/unifdef.c':
					if not keep:
						stdout.write(commit.getvalue())
						keep = True
					stdout.write(line)
				path = match(path)
				if not path:
					line = stdin.readline()
					continue
				data = process(repo.get(dataref.decode('ascii')).data)
				if not keep:
					stdout.write(commit.getvalue())
					keep = True
				stdout.write(b'M ' + mode + b' inline ' + path + b'\n')
				stdout.write(b'data ' + str(len(data)).encode('ascii') + b'\n')
				stdout.write(data)
				stdout.write(b'\n')
			elif line.startswith(b'D '):
				path = match(line[len(b'D '):-1])
				if not path:
					line = stdin.readline()
					continue;
				if not keep:
					stdout.write(commit.getvalue())
					keep = True
				stdout.write(b'D ' + path + b'\n')
			elif line == b'\n':
				break
			else:
				raise NotImplementedError(line)
			line = stdin.readline()

		if keep:
			stdout.write(b'\n')
			parents[mark] = from_
		else:
			skipped[mark] = from_
	elif line.startswith(b'reset ') or line.startswith(b'progress '):
		stdout.write(line)
	else:
		raise NotImplementedError(line)
