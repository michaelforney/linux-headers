/*
 * Copyright (C) 2012,2013 - ARM Ltd
 * Author: Marc Zyngier <marc.zyngier@arm.com>
 *
 * Derived from arch/arm/include/uapi/asm/kvm.h:
 * Copyright (C) 2012 - Virtual Open Systems and Columbia University
 * Author: Christoffer Dall <c.dall@virtualopensystems.com>
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

#ifndef __ARM_KVM_H__
#define __ARM_KVM_H__

#define KVM_SPSR_EL1	0
#define KVM_NR_SPSR	1

#ifndef __ASSEMBLY__
#include <asm/types.h>
#include <asm/ptrace.h>

#define __KVM_HAVE_GUEST_DEBUG
#define __KVM_HAVE_IRQ_LINE

#define KVM_REG_SIZE(id)						\
	(1U << (((id) & KVM_REG_SIZE_MASK) >> KVM_REG_SIZE_SHIFT))

struct kvm_regs {
	struct user_pt_regs regs;	/* sp = sp_el0 */

	__u64	sp_el1;
	__u64	elr_el1;

	__u64	spsr[KVM_NR_SPSR];

	struct user_fpsimd_state fp_regs;
};

/* Supported Processor Types */
#define KVM_ARM_TARGET_AEM_V8		0
#define KVM_ARM_TARGET_FOUNDATION_V8	1
#define KVM_ARM_TARGET_CORTEX_A57	2

#define KVM_ARM_NUM_TARGETS		3

/* KVM_ARM_SET_DEVICE_ADDR ioctl id encoding */
#define KVM_ARM_DEVICE_TYPE_SHIFT	0
#define KVM_ARM_DEVICE_TYPE_MASK	(0xffff << KVM_ARM_DEVICE_TYPE_SHIFT)
#define KVM_ARM_DEVICE_ID_SHIFT		16
#define KVM_ARM_DEVICE_ID_MASK		(0xffff << KVM_ARM_DEVICE_ID_SHIFT)

/* Supported device IDs */
#define KVM_ARM_DEVICE_VGIC_V2		0

/* Supported VGIC address types  */
#define KVM_VGIC_V2_ADDR_TYPE_DIST	0
#define KVM_VGIC_V2_ADDR_TYPE_CPU	1

#define KVM_VGIC_V2_DIST_SIZE		0x1000
#define KVM_VGIC_V2_CPU_SIZE		0x2000

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

/* KVM_IRQ_LINE irq field index values */
#define KVM_ARM_IRQ_TYPE_SHIFT		24
#define KVM_ARM_IRQ_TYPE_MASK		0xff
#define KVM_ARM_IRQ_VCPU_SHIFT		16
#define KVM_ARM_IRQ_VCPU_MASK		0xff
#define KVM_ARM_IRQ_NUM_SHIFT		0
#define KVM_ARM_IRQ_NUM_MASK		0xffff

/* irq_type field */
#define KVM_ARM_IRQ_TYPE_CPU		0
#define KVM_ARM_IRQ_TYPE_SPI		1
#define KVM_ARM_IRQ_TYPE_PPI		2

/* out-of-kernel GIC cpu interrupt injection irq_number field */
#define KVM_ARM_IRQ_CPU_IRQ		0
#define KVM_ARM_IRQ_CPU_FIQ		1

/* Highest supported SPI, from VGIC_NR_IRQS */
#define KVM_ARM_IRQ_GIC_MAX		127

#endif

#endif /* __ARM_KVM_H__ */
