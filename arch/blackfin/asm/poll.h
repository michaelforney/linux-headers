/* SPDX-License-Identifier: GPL-2.0+ WITH Linux-syscall-note */
/*
 * Copyright 2004-2009 Analog Devices Inc.
 *
 * Licensed under the GPL-2 or later.
 *
 */

#ifndef __BFIN_POLL_H
#define __BFIN_POLL_H

#define POLLWRNORM	(__poll_t)4 /* POLLOUT */
#define POLLWRBAND	(__poll_t)256

#include <asm-generic/poll.h>

#endif /* __BFIN_POLL_H */
