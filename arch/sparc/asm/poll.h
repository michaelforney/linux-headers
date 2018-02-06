/* SPDX-License-Identifier: GPL-2.0 WITH Linux-syscall-note */
#ifndef __SPARC_POLL_H
#define __SPARC_POLL_H

#define POLLWRNORM	POLLOUT
#define POLLWRBAND	(__poll_t)256
#define POLLMSG		(__poll_t)512
#define POLLREMOVE	(__poll_t)1024
#define POLLRDHUP       (__poll_t)2048

#include <asm-generic/poll.h>

#endif
