/*
 * Copyright (C) 2004, Microtronix Datacom Ltd.
 *
 * All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE, GOOD TITLE or
 * NON INFRINGEMENT.  See the GNU General Public License for more
 * details.
 */

#ifndef _ASM_NIOS2_SIGCONTEXT_H
#define _ASM_NIOS2_SIGCONTEXT_H

#include <asm/ptrace.h>

struct sigcontext {
	struct pt_regs regs;
	unsigned long  sc_mask;	/* old sigmask */
};

#endif
