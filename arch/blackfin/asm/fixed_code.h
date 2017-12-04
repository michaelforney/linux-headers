/* SPDX-License-Identifier: GPL-2.0+ WITH Linux-syscall-note */
/*
 * This file defines the fixed addresses where userspace programs
 * can find atomic code sequences.
 *
 * Copyright 2007-2008 Analog Devices Inc.
 *
 * Licensed under the GPL-2 or later.
 */

#ifndef __BFIN_ASM_FIXED_CODE_H__
#define __BFIN_ASM_FIXED_CODE_H__


#ifndef CONFIG_PHY_RAM_BASE_ADDRESS
#define CONFIG_PHY_RAM_BASE_ADDRESS	0x0
#endif

#define FIXED_CODE_START	(CONFIG_PHY_RAM_BASE_ADDRESS + 0x400)

#define SIGRETURN_STUB		(CONFIG_PHY_RAM_BASE_ADDRESS + 0x400)

#define ATOMIC_SEQS_START	(CONFIG_PHY_RAM_BASE_ADDRESS + 0x410)

#define ATOMIC_XCHG32		(CONFIG_PHY_RAM_BASE_ADDRESS + 0x410)
#define ATOMIC_CAS32		(CONFIG_PHY_RAM_BASE_ADDRESS + 0x420)
#define ATOMIC_ADD32		(CONFIG_PHY_RAM_BASE_ADDRESS + 0x430)
#define ATOMIC_SUB32		(CONFIG_PHY_RAM_BASE_ADDRESS + 0x440)
#define ATOMIC_IOR32		(CONFIG_PHY_RAM_BASE_ADDRESS + 0x450)
#define ATOMIC_AND32		(CONFIG_PHY_RAM_BASE_ADDRESS + 0x460)
#define ATOMIC_XOR32		(CONFIG_PHY_RAM_BASE_ADDRESS + 0x470)

#define ATOMIC_SEQS_END		(CONFIG_PHY_RAM_BASE_ADDRESS + 0x480)

#define SAFE_USER_INSTRUCTION   (CONFIG_PHY_RAM_BASE_ADDRESS + 0x480)

#define FIXED_CODE_END		(CONFIG_PHY_RAM_BASE_ADDRESS + 0x490)

#endif /* __BFIN_ASM_FIXED_CODE_H__ */
