/*
 * Copyright (C) 2012 - Virtual Open Systems and Columbia University
 * Author: Christoffer Dall <c.dall@virtualopensystems.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License, version 2, as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#ifndef __ARM_KVM_H__
#define __ARM_KVM_H__

#include <linux/types.h>
#include <asm/ptrace.h>

#define __KVM_HAVE_GUEST_DEBUG

#define KVM_REG_SIZE(id)						\
	(1U << (((id) & KVM_REG_SIZE_MASK) >> KVM_REG_SIZE_SHIFT))

/* Valid for svc_regs, abt_regs, und_regs, irq_regs in struct kvm_regs */
#define KVM_ARM_SVC_sp		svc_regs[0]
#define KVM_ARM_SVC_lr		svc_regs[1]
#define KVM_ARM_SVC_spsr	svc_regs[2]
#define KVM_ARM_ABT_sp		abt_regs[0]
#define KVM_ARM_ABT_lr		abt_regs[1]
#define KVM_ARM_ABT_spsr	abt_regs[2]
#define KVM_ARM_UND_sp		und_regs[0]
#define KVM_ARM_UND_lr		und_regs[1]
#define KVM_ARM_UND_spsr	und_regs[2]
#define KVM_ARM_IRQ_sp		irq_regs[0]
#define KVM_ARM_IRQ_lr		irq_regs[1]
#define KVM_ARM_IRQ_spsr	irq_regs[2]

/* Valid only for fiq_regs in struct kvm_regs */
#define KVM_ARM_FIQ_r8		fiq_regs[0]
#define KVM_ARM_FIQ_r9		fiq_regs[1]
#define KVM_ARM_FIQ_r10		fiq_regs[2]
#define KVM_ARM_FIQ_fp		fiq_regs[3]
#define KVM_ARM_FIQ_ip		fiq_regs[4]
#define KVM_ARM_FIQ_sp		fiq_regs[5]
#define KVM_ARM_FIQ_lr		fiq_regs[6]
#define KVM_ARM_FIQ_spsr	fiq_regs[7]

struct kvm_regs {
	struct pt_regs usr_regs;/* R0_usr - R14_usr, PC, CPSR */
	__u32 svc_regs[3];	/* SP_svc, LR_svc, SPSR_svc */
	__u32 abt_regs[3];	/* SP_abt, LR_abt, SPSR_abt */
	__u32 und_regs[3];	/* SP_und, LR_und, SPSR_und */
	__u32 irq_regs[3];	/* SP_irq, LR_irq, SPSR_irq */
	__u32 fiq_regs[8];	/* R8_fiq - R14_fiq, SPSR_fiq */
};

/* Supported Processor Types */
#define KVM_ARM_TARGET_CORTEX_A15	0
#define KVM_ARM_NUM_TARGETS		1

struct kvm_vcpu_init {
	__u32 target;
	__u32 features[7];
};

struct kvm_sregs {
};

struct kvm_fpu {
};

struct kvm_guest_debug_arch {
};

struct kvm_debug_exit_arch {
};

struct kvm_sync_regs {
};

struct kvm_arch_memory_slot {
};

/* If you need to interpret the index values, here is the key: */
#define KVM_REG_ARM_COPROC_MASK		0x000000000FFF0000
#define KVM_REG_ARM_COPROC_SHIFT	16
#define KVM_REG_ARM_32_OPC2_MASK	0x0000000000000007
#define KVM_REG_ARM_32_OPC2_SHIFT	0
#define KVM_REG_ARM_OPC1_MASK		0x0000000000000078
#define KVM_REG_ARM_OPC1_SHIFT		3
#define KVM_REG_ARM_CRM_MASK		0x0000000000000780
#define KVM_REG_ARM_CRM_SHIFT		7
#define KVM_REG_ARM_32_CRN_MASK		0x0000000000007800
#define KVM_REG_ARM_32_CRN_SHIFT	11

/* Normal registers are mapped as coprocessor 16. */
#define KVM_REG_ARM_CORE		(0x0010 << KVM_REG_ARM_COPROC_SHIFT)
#define KVM_REG_ARM_CORE_REG(name)	(offsetof(struct kvm_regs, name) / 4)

#endif /* __ARM_KVM_H__ */
