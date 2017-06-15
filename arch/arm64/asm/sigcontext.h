/*
 * Copyright (C) 2012 ARM Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef __ASM_SIGCONTEXT_H
#define __ASM_SIGCONTEXT_H

#include <linux/types.h>

/*
 * Signal context structure - contains all info to do with the state
 * before the signal handler was invoked.
 */
struct sigcontext {
	__u64 fault_address;
	/* AArch64 registers */
	__u64 regs[31];
	__u64 sp;
	__u64 pc;
	__u64 pstate;
	/* 4K reserved for FP/SIMD state and future expansion */
	__u8 __reserved[4096] __attribute__((__aligned__(16)));
};

/*
 * Allocation of __reserved[]:
 * (Note: records do not necessarily occur in the order shown here.)
 *
 *	size		description
 *
 *	0x210		fpsimd_context
 *	 0x10		esr_context
 *	 0x10		terminator (null _aarch64_ctx)
 *
 *	0xdd0		(reserved for future allocation)
 *
 * New records that can exceed this space need to be opt-in for userspace, so
 * that an expanded signal frame is not generated unexpectedly.  The mechanism
 * for opting in will depend on the extension that generates each new record.
 * The above table documents the maximum set and sizes of records than can be
 * generated when userspace does not opt in for any such extension.
 */

/*
 * Header to be used at the beginning of structures extending the user
 * context. Such structures must be placed after the rt_sigframe on the stack
 * and be 16-byte aligned. The last structure must be a dummy one with the
 * magic and size set to 0.
 */
struct _aarch64_ctx {
	__u32 magic;
	__u32 size;
};

#define FPSIMD_MAGIC	0x46508001

struct fpsimd_context {
	struct _aarch64_ctx head;
	__u32 fpsr;
	__u32 fpcr;
	__uint128_t vregs[32];
};

/* ESR_EL1 context */
#define ESR_MAGIC	0x45535201

struct esr_context {
	struct _aarch64_ctx head;
	__u64 esr;
};

#endif /* __ASM_SIGCONTEXT_H */
