/*
 * msr.h:  This file defines msr read and write functions.
 * Copyright (c) 2014, Jidong Xiao (jidong.xiao@gmail.com)
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms and conditions of the GNU General Public License,
 * version 2, as published by the Free Software Foundation.
 *
 * This program is distributed in the hope it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program; if not, write to the Free Software Foundation, Inc., 59 Temple
 * Place - Suite 330, Boston, MA 02111-1307 USA.
 *
 *
 */
#ifndef __MSR_H
#define __MSR_H

#include <inttypes.h>

#define MSR_IA32_MCG_STATUS             0x0000017a
#define MSR_IA32_EBL_CR_POWERON         0x0000002a 
#define MSR_IA32_MCG_CTL		0x0000017b
#define MSR_IA32_PERF_STATUS		0x00000198
#define MSR_IA32_MC0_MISC		0x00000403
#define MSR_VM_HSAVE_PA			0xc0010117
#define MSR_K7_EVNTSEL0			0xc0010000

#define MSR_IA32_UCODE_REV              0x0000008b	// Not readable until kernel 3.2
#define MSR_IA32_TSC_ADJUST             0x0000003b	// Not readable until kernel 3.8

/* PMUv2 related MSR */
/* Intel Core-based CPU performance counters */
#define MSR_CORE_PERF_FIXED_CTR0        0x00000309
#define MSR_CORE_PERF_FIXED_CTR1        0x0000030a
#define MSR_CORE_PERF_FIXED_CTR2        0x0000030b
#define MSR_CORE_PERF_FIXED_CTR_CTRL    0x0000038d
#define MSR_CORE_PERF_GLOBAL_STATUS     0x0000038e
#define MSR_CORE_PERF_GLOBAL_CTRL       0x0000038f
#define MSR_CORE_PERF_GLOBAL_OVF_CTRL   0x00000390

/* Custom MSRs */
#define MSR_KVM_API_MAGIC		0x87655678
#define MSR_KVM_WALL_CLOCK_NEW		0x4b564d00
#define MSR_KVM_SYSTEM_TIME_NEW		0x4b564d01
#define MSR_KVM_ASYNC_PF_EN		0x4b564d02
#define MSR_KVM_STEAL_TIME		0x4b564d03
#define MSR_P6_PERFCTR0			0x000000c1	// Used for detedting pmuv2

uint64_t rdmsr_on_cpu(uint32_t reg, int cpu);
void wrmsr_on_cpu(uint32_t reg, int cpu, uint64_t data);

#endif /* msr.h */