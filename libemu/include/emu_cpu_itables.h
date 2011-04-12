/********************************************************************************
 *                               libemu
 *
 *                    - x86 shellcode emulation -
 *
 *
 * Copyright (C) 2007  Paul Baecher & Markus Koetter
 * 
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 * 
 * 
 *             contact nepenthesdev@users.sourceforge.net  
 *
 *******************************************************************************/

#ifndef HAVE_EMU_CPU_ITABLES_H
#define HAVE_EMU_CPU_ITABLES_H

// for i in $(seq 0 255); do printf "\t/* %02x */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},\n" $i; done >> emu_cpu_itables.h */


#include <emu_cpu_functions.h>
#include <emu_cpu_instruction.h>

#define II_SBIT 1
#define II_WBIT 1

#define II_XX_REG1_REG2 1
#define II_MOD_REG_RM 2
#define II_XX_YYY_REG 3
#define II_MOD_YYY_RM 4
#define II_UUUU_TTTN 5
#define II_XX_SREG3_ZZ 6  

#define II_IMM 1
#define II_IMM8 2
#define II_IMM16 3
#define II_IMM32 4

#define II_DISPF 1
#define II_DISP8 2
#define II_DISP16 3
#define II_DISP32 4

/*#define II_LEVEL8 1 -- implementation pending

#define II_TYPE 1 -- impementation pending*/

#define II_FPU_INSTR 1

extern int32_t instr_salc_d6(struct emu_cpu *c, struct emu_cpu_instruction *i);

struct emu_cpu_instruction_info ii_onebyte[0x100] = {
	/* 00 */ {instr_add_00, "add", {0, 0, II_MOD_REG_RM, 0, 0, 0, 0, 0}},
	/* 01 */ {instr_add_01, "add", {0, 0, II_MOD_REG_RM, 0, 0, 0, 0, 0}},
	/* 02 */ {instr_add_02, "add", {0, 0, II_MOD_REG_RM, 0, 0, 0, 0, 0}},
	/* 03 */ {instr_add_03, "add", {0, 0, II_MOD_REG_RM, 0, 0, 0, 0, 0}},
	/* 04 */ {instr_add_04, "add", {0, 0, 0, II_IMM8, 0, 0, 0, 0}},
	/* 05 */ {instr_add_05, "add", {0, 0, 0, II_IMM, 0, 0, 0, 0}},
	/* 06 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 07 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 08 */ {instr_or_08 , "or" , {0, 0, II_MOD_REG_RM, 0, 0, 0, 0}},  
	/* 09 */ {instr_or_09 , "or" , {0, 0, II_MOD_REG_RM, 0, 0, 0, 0}},  
	/* 0a */ {instr_or_0a , "or" , {0, 0, II_MOD_REG_RM, 0, 0, 0, 0}},  
	/* 0b */ {instr_or_0b , "or" , {0, 0, II_MOD_REG_RM, 0, 0, 0, 0}},  
	/* 0c */ {instr_or_0c , "or" , {0, 0, 0, II_IMM8, 0, 0, 0}},        
	/* 0d */ {instr_or_0d , "or" , {0, 0, 0, II_IMM, 0, 0, 0}},         
	/* 0e */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 0f */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 10 */ {instr_adc_10, "adc", {0, 0, II_MOD_REG_RM, 0, 0, 0, 0}},   
	/* 11 */ {instr_adc_11, "adc", {0, 0, II_MOD_REG_RM, 0, 0, 0, 0}},    
	/* 12 */ {instr_adc_12, "adc", {0, 0, II_MOD_REG_RM, 0, 0, 0, 0}},   
	/* 13 */ {instr_adc_13, "adc", {0, 0, II_MOD_REG_RM, 0, 0, 0, 0}},   
	/* 14 */ {instr_adc_14, "adc", {0, 0, 0, II_IMM8, 0, 0, 0}},         
	/* 15 */ {instr_adc_15, "adc", {0, 0, 0, II_IMM, 0, 0, 0}},          
	/* 16 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 17 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 18 */ {instr_sbb_18, "sbb", {0, 0, II_MOD_REG_RM, 0, 0, 0, 0}},         
	/* 19 */ {instr_sbb_19, "sbb", {0, 0, II_MOD_REG_RM, 0, 0, 0, 0}},         
	/* 1a */ {instr_sbb_1a, "sbb", {0, 0, II_MOD_REG_RM, 0, 0, 0, 0}},         
	/* 1b */ {instr_sbb_1b, "sbb", {0, 0, II_MOD_REG_RM, 0, 0, 0, 0}},         
	/* 1c */ {instr_sbb_1c, "sbb", {0, 0, 0, II_IMM8, 0, 0, 0}},               
	/* 1d */ {instr_sbb_1d, "sbb", {0, 0, 0, II_IMM, 0, 0, 0}},                
	/* 1e */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 1f */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 20 */ {instr_and_20, "and", {0, 0, II_MOD_REG_RM, 0, 0, 0, 0}},  
	/* 21 */ {instr_and_21, "and", {0, 0, II_MOD_REG_RM, 0, 0, 0, 0}},  
	/* 22 */ {instr_and_22, "and", {0, 0, II_MOD_REG_RM, 0, 0, 0, 0}},  
	/* 23 */ {instr_and_23, "and", {0, 0, II_MOD_REG_RM, 0, 0, 0, 0}},  
	/* 24 */ {instr_and_24, "and", {0, 0, 0, II_IMM8, 0, 0, 0}},        
	/* 25 */ {instr_and_25, "and", {0, 0, 0, II_IMM, 0, 0, 0}},         
	/* 26 */ {prefix_fn, "ES:", {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 27 */ {instr_daa_27, "daa", {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 28 */ {instr_sub_28, "sub", {0, 0, II_MOD_REG_RM, 0, 0, 0, 0}},     
	/* 29 */ {instr_sub_29, "sub", {0, 0, II_MOD_REG_RM, 0, 0, 0, 0}},     
	/* 2a */ {instr_sub_2a, "sub", {0, 0, II_MOD_REG_RM, 0, 0, 0, 0}},     
	/* 2b */ {instr_sub_2b, "sub", {0, 0, II_MOD_REG_RM, 0, 0, 0, 0}},     
	/* 2c */ {instr_sub_2c, "sub", {0, 0, 0, II_IMM8, 0, 0, 0}},           
	/* 2d */ {instr_sub_2d, "sub", {0, 0, 0, II_IMM, 0, 0, 0}},            
	/* 2e */ {prefix_fn, "CS:", {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 2f */ {instr_das_2f, "das", {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 30 */ {instr_xor_30, "xor", {0, 0, II_MOD_REG_RM, 0, 0, 0, 0}},         
	/* 31 */ {instr_xor_31, "xor", {0, 0, II_MOD_REG_RM, 0, 0, 0, 0}},         
	/* 32 */ {instr_xor_32, "xor", {0, 0, II_MOD_REG_RM, 0, 0, 0, 0}},         
	/* 33 */ {instr_xor_33, "xor", {0, 0, II_MOD_REG_RM, 0, 0, 0, 0}},         
	/* 34 */ {instr_xor_34, "xor", {0, 0, 0, II_IMM8, 0, 0, 0}},               
	/* 35 */ {instr_xor_35, "xor", {0, 0, 0, II_IMM, 0, 0, 0}},                
	/* 36 */ {prefix_fn, "SS:", {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 37 */ {instr_aaa_37, "aaa", {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 38 */ {instr_cmp_38, "cmp", {0, 0, II_MOD_REG_RM, 0, 0, 0, 0}},       
	/* 39 */ {instr_cmp_39, "cmp", {0, 0, II_MOD_REG_RM, 0, 0, 0, 0}},       
	/* 3a */ {instr_cmp_3a, "cmp", {0, 0, II_MOD_REG_RM, 0, 0, 0, 0}},       
	/* 3b */ {instr_cmp_3b, "cmp", {0, 0, II_MOD_REG_RM, 0, 0, 0, 0}},       
	/* 3c */ {instr_cmp_3c, "cmp", {0, 0, 0, II_IMM8, 0, 0, 0}},             
	/* 3d */ {instr_cmp_3d, "cmp", {0, 0, 0, II_IMM, 0, 0, 0}},              
	/* 3e */ {prefix_fn, "DS:", {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 3f */ {instr_aas_3f, "aas", {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 40 */ {instr_inc_4x, "inc", {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 41 */ {instr_inc_4x, "inc", {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 42 */ {instr_inc_4x, "inc", {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 43 */ {instr_inc_4x, "inc", {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 44 */ {instr_inc_4x, "inc", {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 45 */ {instr_inc_4x, "inc", {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 46 */ {instr_inc_4x, "inc", {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 47 */ {instr_inc_4x, "inc", {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 48 */ {instr_dec_4x, "dec", {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 49 */ {instr_dec_4x, "dec", {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 4a */ {instr_dec_4x, "dec", {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 4b */ {instr_dec_4x, "dec", {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 4c */ {instr_dec_4x, "dec", {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 4d */ {instr_dec_4x, "dec", {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 4e */ {instr_dec_4x, "dec", {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 4f */ {instr_dec_4x, "dec", {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 50 */ {instr_push_5x, "push", {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 51 */ {instr_push_5x, "push", {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 52 */ {instr_push_5x, "push", {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 53 */ {instr_push_5x, "push", {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 54 */ {instr_push_5x, "push", {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 55 */ {instr_push_5x, "push", {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 56 */ {instr_push_5x, "push", {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 57 */ {instr_push_5x, "push", {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 58 */ {instr_pop_5x, "pop", {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 59 */ {instr_pop_5x, "pop", {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 5a */ {instr_pop_5x, "pop", {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 5b */ {instr_pop_5x, "pop", {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 5c */ {instr_pop_5x, "pop", {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 5d */ {instr_pop_5x, "pop", {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 5e */ {instr_pop_5x, "pop", {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 5f */ {instr_pop_5x, "pop", {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 60 */ {instr_pushad_60, "pushad", {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 61 */ {instr_popad_61, "popad", {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 62 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 63 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 64 */ {prefix_fn, "FS:", {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 65 */ {prefix_fn, "GS:", {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 66 */ {prefix_fn, "OPSIZE:", {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 67 */ {prefix_fn, "ADSIZE:", {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 68 */ {instr_push_68, "push", {0, 0, 0, II_IMM, 0, 0, 0, 0}},
	/* 69 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 6a */ {instr_push_6a, "push", {0, 0, 0, II_IMM8, 0, 0, 0, 0}},
	/* 6b */ {instr_imul_6b, "imul", {0, 0, II_MOD_REG_RM, II_IMM8, 0, 0, 0, 0}},
	/* 6c */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 6d */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 6e */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 6f */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 70 */ {instr_jcc_70, "jcc", {0, 0, 0, 0, II_DISP8, 0, 0, 0}},
	/* 71 */ {instr_jcc_71, "jcc", {0, 0, 0, 0, II_DISP8, 0, 0, 0}},
	/* 72 */ {instr_jcc_72, "jcc", {0, 0, 0, 0, II_DISP8, 0, 0, 0}},
	/* 73 */ {instr_jcc_73, "jcc", {0, 0, 0, 0, II_DISP8, 0, 0, 0}},
	/* 74 */ {instr_jcc_74, "jcc", {0, 0, 0, 0, II_DISP8, 0, 0, 0}},
	/* 75 */ {instr_jcc_75, "jcc", {0, 0, 0, 0, II_DISP8, 0, 0, 0}},
	/* 76 */ {instr_jcc_76, "jcc", {0, 0, 0, 0, II_DISP8, 0, 0, 0}},
	/* 77 */ {instr_jcc_77, "jcc", {0, 0, 0, 0, II_DISP8, 0, 0, 0}},
	/* 78 */ {instr_jcc_78, "jcc", {0, 0, 0, 0, II_DISP8, 0, 0, 0}},
	/* 79 */ {instr_jcc_79, "jcc", {0, 0, 0, 0, II_DISP8, 0, 0, 0}},
	/* 7a */ {instr_jcc_7a, "jcc", {0, 0, 0, 0, II_DISP8, 0, 0, 0}},
	/* 7b */ {instr_jcc_7b, "jcc", {0, 0, 0, 0, II_DISP8, 0, 0, 0}},
	/* 7c */ {instr_jcc_7c, "jcc", {0, 0, 0, 0, II_DISP8, 0, 0, 0}},
	/* 7d */ {instr_jcc_7d, "jcc", {0, 0, 0, 0, II_DISP8, 0, 0, 0}},
	/* 7e */ {instr_jcc_7e, "jcc", {0, 0, 0, 0, II_DISP8, 0, 0, 0}},
	/* 7f */ {instr_jcc_7f, "jcc", {0, 0, 0, 0, II_DISP8, 0, 0, 0}},
	/* 80 */ {instr_group_1_80, "group1", {0, 0, II_MOD_REG_RM, II_IMM8, 0, 0, 0, 0}},
	/* 81 */ {instr_group_1_81, "group1", {0, 0, II_MOD_REG_RM, II_IMM, 0, 0, 0, 0}},
	/* 82 */ {instr_group_1_80, "group1", {0, 0, II_MOD_REG_RM, II_IMM8, 0, 0, 0, 0}},
	/* 83 */ {instr_group_1_83, "group1", {0, 0, II_MOD_REG_RM, II_IMM8, 0, 0, 0, 0}},
	/* 84 */ {instr_test_84, "test", {0, 0, II_MOD_REG_RM, 0, 0, 0, 0, 0}},
	/* 85 */ {instr_test_85, "test", {0, 0, II_MOD_REG_RM, 0, 0, 0, 0, 0}},
	/* 86 */ {instr_xchg_86, "xchg", {0, 0, II_MOD_REG_RM, 0, 0, 0, 0, 0}},
	/* 87 */ {instr_xchg_87, "xchg", {0, 0, II_MOD_REG_RM, 0, 0, 0, 0, 0}},
	/* 88 */ {instr_mov_88, "mov", {0, 0, II_MOD_REG_RM, 0, 0, 0, 0, 0}},
	/* 89 */ {instr_mov_89, "mov", {0, 0, II_MOD_REG_RM, 0, 0, 0, 0, 0}},
	/* 8a */ {instr_mov_8a, "mov", {0, 0, II_MOD_REG_RM, 0, 0, 0, 0, 0}},
	/* 8b */ {instr_mov_8b, "mov", {0, 0, II_MOD_REG_RM, 0, 0, 0, 0, 0}},
	/* 8c */ {instr_mov_8c, "mov", {0, 0, II_MOD_REG_RM, 0, 0, 0, 0, 0}},
	/* 8d */ {instr_lea_8d, "lea", {0, 0, II_MOD_REG_RM, 0, 0, 0, 0, 0}},
	/* 8e */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 8f */ {instr_group_10_8f, "group10", {0, 0, II_MOD_REG_RM, 0, 0, 0, 0, 0}},
	/* 90 */ {instr_xchg_9x, "xchg", {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 91 */ {instr_xchg_9x, "xchg", {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 92 */ {instr_xchg_9x, "xchg", {0, 0, 0, 0, 0, 0, 0}},  
	/* 93 */ {instr_xchg_9x, "xchg", {0, 0, 0, 0, 0, 0, 0}},  
	/* 94 */ {instr_xchg_9x, "xchg", {0, 0, 0, 0, 0, 0, 0}},  
	/* 95 */ {instr_xchg_9x, "xchg", {0, 0, 0, 0, 0, 0, 0}},  
	/* 96 */ {instr_xchg_9x, "xchg", {0, 0, 0, 0, 0, 0, 0}},  
	/* 97 */ {instr_xchg_9x, "xchg", {0, 0, 0, 0, 0, 0, 0}},  
	/* 98 */ {instr_cbw_98, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 99 */ {instr_cwd_99, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 9a */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 9b */ {instr_wait_9b, "wait", {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 9c */ {instr_pushf_9c, "pushf", {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 9d */ {instr_popf_9d, "popf", {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 9e */ {instr_sahf_9e, "sahf", {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 9f */ {instr_lahf_9f, "lahf", {0, 0, 0, 0, 0, 0, 0, 0}},
	/* a0 */ {instr_mov_a0, "mov", {0, 0, 0, 0, II_DISPF, 0, 0, 0}},
	/* a1 */ {instr_mov_a1, "mov", {0, 0, 0, 0, II_DISPF, 0, 0, 0}},
	/* a2 */ {instr_mov_a2, "mov", {0, 0, 0, 0, II_DISPF, 0, 0, 0}},
	/* a3 */ {instr_mov_a3, "mov", {0, 0, 0, 0, II_DISPF, 0, 0, 0}},
	/* a4 */ {instr_movsb, "movsb", {0, 0, 0, 0, 0, 0, 0, 0}},
	/* a5 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* a6 */ {instr_cmps_a6, "cmps", {0, 0, 0, 0, 0, 0, 0, 0}},
	/* a7 */ {instr_cmps_a7, "cmps", {0, 0, 0, 0, 0, 0, 0, 0}},
	/* a8 */ //{0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},	
	/* a9 */ //{0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	
	/* a8 */ {instr_test_a8, "test", {0, 0, 0, II_IMM8, 0, 0, 0, 0}}, /* re-enabled dzzie */
	/* a9 */ {instr_test_a9, "test", {0, 0, 0, II_IMM, 0, 0, 0, 0}}, /* re-enabled dzzie */
	
	/* aa */ {instr_stos_aa, "stos", {0, 0, 0, 0, 0, 0, 0, 0}},
	/* ab */ {instr_stos_ab, "stos", {0, 0, 0, 0, 0, 0, 0, 0}},
	/* ac */ {instr_lods_ac, "lods", {0, 0, 0, 0, 0, 0, 0, 0}},
	/* ad */ {instr_lods_ad, "lods", {0, 0, 0, 0, 0, 0, 0, 0}},
	/* ae */ {instr_scas_ae, "scas", {0, 0, 0, 0, 0, 0, 0, 0}},
	/* af */ {instr_scas_af, "scas", {0, 0, 0, 0, 0, 0, 0, 0}},
	/* b0 */ {instr_mov_bx_1, "mov", {0, 0, 0, II_IMM8, 0, 0, 0, 0}},
	/* b1 */ {instr_mov_bx_1, "mov", {0, 0, 0, II_IMM8, 0, 0, 0, 0}},
	/* b2 */ {instr_mov_bx_1, "mov", {0, 0, 0, II_IMM8, 0, 0, 0, 0}},
	/* b3 */ {instr_mov_bx_1, "mov", {0, 0, 0, II_IMM8, 0, 0, 0, 0}},
	/* b4 */ {instr_mov_bx_1, "mov", {0, 0, 0, II_IMM8, 0, 0, 0, 0}},
	/* b5 */ {instr_mov_bx_1, "mov", {0, 0, 0, II_IMM8, 0, 0, 0, 0}},
	/* b6 */ {instr_mov_bx_1, "mov", {0, 0, 0, II_IMM8, 0, 0, 0, 0}},
	/* b7 */ {instr_mov_bx_1, "mov", {0, 0, 0, II_IMM8, 0, 0, 0, 0}},
	/* b8 */ {instr_mov_bx_2, "mov", {0, 0, 0, II_IMM, 0, 0, 0, 0}},
	/* b9 */ {instr_mov_bx_2, "mov", {0, 0, 0, II_IMM, 0, 0, 0, 0}},
	/* ba */ {instr_mov_bx_2, "mov", {0, 0, 0, II_IMM, 0, 0, 0, 0}},
	/* bb */ {instr_mov_bx_2, "mov", {0, 0, 0, II_IMM, 0, 0, 0, 0}},
	/* bc */ {instr_mov_bx_2, "mov", {0, 0, 0, II_IMM, 0, 0, 0, 0}},
	/* bd */ {instr_mov_bx_2, "mov", {0, 0, 0, II_IMM, 0, 0, 0, 0}},
	/* be */ {instr_mov_bx_2, "mov", {0, 0, 0, II_IMM, 0, 0, 0, 0}},
	/* bf */ {instr_mov_bx_2, "mov", {0, 0, 0, II_IMM, 0, 0, 0, 0}},
	/* c0 */ {instr_group_2_c0, "group2", {0, 0, II_MOD_YYY_RM, II_IMM8, 0, 0, 0, 0}},
	/* c1 */ {instr_group_2_c1, "group2", {0, 0, II_MOD_YYY_RM, II_IMM8, 0, 0, 0, 0}},
	/* c2 */ {instr_ret_c2, "ret", {0, 0, 0, II_IMM16, 0, 0, 0, 0}},
	/* c3 */ {instr_ret_c3, "ret", {0, 0, 0, 0, 0, 0, 0, 0}},
	/* c4 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* c5 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* c6 */ {instr_mov_c6, "mov", {0, 0, II_MOD_REG_RM, II_IMM8, 0, 0, 0, 0}},
	/* c7 */ {instr_mov_c7, "mov", {0, 0, II_MOD_REG_RM, II_IMM, 0, 0, 0, 0}},
	/* c8 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* c9 */ {instr_leave, "leave", {0, 0, 0, 0, 0, 0, 0, 0}},
	/* ca */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* cb */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* cc */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* cd */ {instr_int_cd, "int", {0, 0, 0, II_IMM8, 0, 0, 0, 0}}, 
	/* ce */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* cf */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* d0 */ {instr_group_2_d0, "group2", {0, 0, II_MOD_YYY_RM, 0, 0, 0, 0, 0}},
	/* d1 */ {instr_group_2_d1, "group2", {0, 0, II_MOD_YYY_RM, 0, 0, 0, 0, 0}},
	/* d2 */ {instr_group_2_d2, "group2", {0, 0, II_MOD_YYY_RM, 0, 0, 0, 0, 0}},
	/* d3 */ {instr_group_2_d3, "group2", {0, 0, II_MOD_YYY_RM, 0, 0, 0, 0, 0}},
	/* d4 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* d5 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* d6 */ //{0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* d6 */ {instr_salc_d6, 0, {0, 0, 0, 0, 0, 0, 0, 0}}, /*dzzie*/

	/* d7 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* d8 */ {instr_esc_fpu_dx, 0, {0, 0, 0, 0, 0, 0, 0, II_FPU_INSTR}},
	/* d9 */ {instr_esc_fpu_dx, 0, {0, 0, 0, 0, 0, 0, 0, II_FPU_INSTR}},
	/* da */ {instr_esc_fpu_dx, 0, {0, 0, 0, 0, 0, 0, 0, II_FPU_INSTR}},
	/* db */ {instr_esc_fpu_dx, 0, {0, 0, 0, 0, 0, 0, 0, II_FPU_INSTR}},
	/* dc */ {instr_esc_fpu_dx, 0, {0, 0, 0, 0, 0, 0, 0, II_FPU_INSTR}},
	/* dd */ {instr_esc_fpu_dx, 0, {0, 0, 0, 0, 0, 0, 0, II_FPU_INSTR}},
	/* de */ {instr_esc_fpu_dx, 0, {0, 0, 0, 0, 0, 0, 0, II_FPU_INSTR}},
	/* df */ {instr_esc_fpu_dx, 0, {0, 0, 0, 0, 0, 0, 0, II_FPU_INSTR}},
	/* e0 */ {instr_loopcc_e0, "loopcc", {0, 0, 0, 0, II_DISP8, 0, 0, 0}},
	/* e1 */ {instr_loopcc_e1, "loopcc", {0, 0, 0, 0, II_DISP8, 0, 0, 0}},
	/* e2 */ {instr_loop_e2  , "loop",   {0, 0, 0, 0, II_DISP8, 0, 0, 0}},
	/* e3 */ {instr_jcc_e3, "jcc", {0, 0, 0, 0, II_DISP8, 0, 0, 0}},
	/* e4 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* e5 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* e6 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* e7 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* e8 */ {instr_call_e8, "call", {0, 0, 0, 0, II_DISPF, 0, 0, 0}},
	/* e9 */ {instr_jmp_e9, "jmp", {0, 0, 0, 0, II_DISPF, 0, 0, 0}},
	/* ea */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* eb */ {instr_jmp_eb, "jmp", {0, 0, 0, 0, II_DISP8, 0, 0, 0}},
	/* ec */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* ed */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* ee */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* ef */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* f0 */ {prefix_fn, "LOCK:", {0, 0, 0, 0, 0, 0, 0, 0}},
	/* f1 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* f2 */ {prefix_fn, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* f3 */ {prefix_fn, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* f4 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* f5 */ {instr_cmc_f5, "cmc", {0, 0, 0, 0, 0, 0, 0, 0}},
	/* f6 */ {instr_group_3_f6, "group3", {0, 0, II_MOD_REG_RM, 0, 0, 0, 1, 0}},
	/* f7 */ {instr_group_3_f7, "group3", {0, 0, II_MOD_REG_RM, 0, 0, 0, 1, 0}},
	/* f8 */ {instr_clc_f8, "clc", {0, 0, 0, 0, 0, 0, 0, 0}},
	/* f9 */ {instr_stc_f9, "stc", {0, 0, 0, 0, 0, 0, 0, 0}},
	/* fa */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* fb */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* fc */ {instr_cld_fc, "cld", {0, 0, 0, 0, 0, 0, 0, 0}},
	/* fd */ {instr_std_fd, "std", {0, 0, 0, 0, 0, 0, 0, 0}},
	/* fe */ {instr_group_4_fe, "group4", {0, 0, II_MOD_REG_RM, 0, 0, 0, 0, 0}},
	/* ff */ {instr_group_5_ff, "group5", {0, 0, II_MOD_REG_RM, 0, 0, 0, 0, 0}},
};

struct emu_cpu_instruction_info ii_twobyte[0x100] = {
	/* 00 */ {instr_sldt_0f00, "sldt", {0, 0, II_MOD_REG_RM, 0, 0, 0, 0, 0}},
	/* 01 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 02 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 03 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 04 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 05 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 06 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 07 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 08 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 09 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 0a */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 0b */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 0c */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 0d */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 0e */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 0f */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 10 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 11 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 12 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 13 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 14 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 15 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 16 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 17 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 18 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 19 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 1a */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 1b */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 1c */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 1d */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 1e */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 1f */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 20 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 21 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 22 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 23 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 24 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 25 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 26 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 27 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 28 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 29 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 2a */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 2b */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 2c */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 2d */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 2e */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 2f */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 30 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 31 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 32 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 33 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 34 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 35 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 36 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 37 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 38 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 39 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 3a */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 3b */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 3c */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 3d */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 3e */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 3f */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 40 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 41 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 42 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 43 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 44 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 45 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 46 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 47 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 48 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 49 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 4a */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 4b */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 4c */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 4d */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 4e */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 4f */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 50 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 51 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 52 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 53 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 54 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 55 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 56 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 57 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 58 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 59 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 5a */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 5b */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 5c */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 5d */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 5e */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 5f */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 60 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 61 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 62 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 63 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 64 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 65 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 66 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 67 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 68 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 69 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 6a */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 6b */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 6c */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 6d */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 6e */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 6f */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 70 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 71 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 72 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 73 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 74 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 75 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 76 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 77 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 78 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 79 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 7a */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 7b */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 7c */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 7d */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 7e */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 7f */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 80 */ {instr_jcc_0f80, "jcc", {0, 0, 0, 0, II_DISPF, 0, 0, 0}},
	/* 81 */ {instr_jcc_0f81, "jcc", {0, 0, 0, 0, II_DISPF, 0, 0, 0}},
	/* 82 */ {instr_jcc_0f82, "jcc", {0, 0, 0, 0, II_DISPF, 0, 0, 0}},
	/* 83 */ {instr_jcc_0f83, "jcc", {0, 0, 0, 0, II_DISPF, 0, 0, 0}},
	/* 84 */ {instr_jcc_0f84, "jcc", {0, 0, 0, 0, II_DISPF, 0, 0, 0}},
	/* 85 */ {instr_jcc_0f85, "jcc", {0, 0, 0, 0, II_DISPF, 0, 0, 0}},
	/* 86 */ {instr_jcc_0f86, "jcc", {0, 0, 0, 0, II_DISPF, 0, 0, 0}},
	/* 87 */ {instr_jcc_0f87, "jcc", {0, 0, 0, 0, II_DISPF, 0, 0, 0}},
	/* 88 */ {instr_jcc_0f88, "jcc", {0, 0, 0, 0, II_DISPF, 0, 0, 0}},
	/* 89 */ {instr_jcc_0f89, "jcc", {0, 0, 0, 0, II_DISPF, 0, 0, 0}},
	/* 8a */ {instr_jcc_0f8a, "jcc", {0, 0, 0, 0, II_DISPF, 0, 0, 0}},
	/* 8b */ {instr_jcc_0f8b, "jcc", {0, 0, 0, 0, II_DISPF, 0, 0, 0}},
	/* 8c */ {instr_jcc_0f8c, "jcc", {0, 0, 0, 0, II_DISPF, 0, 0, 0}},
	/* 8d */ {instr_jcc_0f8d, "jcc", {0, 0, 0, 0, II_DISPF, 0, 0, 0}},
	/* 8e */ {instr_jcc_0f8e, "jcc", {0, 0, 0, 0, II_DISPF, 0, 0, 0}},
	/* 8f */ {instr_jcc_0f8f, "jcc", {0, 0, 0, 0, II_DISPF, 0, 0, 0}},
	/* 90 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 91 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 92 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 93 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 94 */ {instr_setcc_0f94, "setz", {0, 0, II_MOD_REG_RM, 0, 0, 0, 0, 0}},
	/* 95 */ {instr_setcc_0f95, "setnz", {0, 0, II_MOD_REG_RM, 0, 0, 0, 0, 0}},
	/* 96 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 97 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 98 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 99 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 9a */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 9b */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 9c */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 9d */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 9e */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* 9f */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* a0 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* a1 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* a2 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* a3 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* a4 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* a5 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* a6 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* a7 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* a8 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* a9 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* aa */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* ab */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* ac */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* ad */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* ae */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* af */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* b0 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* b1 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* b2 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* b3 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* b4 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* b5 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* b6 */ {instr_movzx_0fb6, "movzx", {0, 0, II_MOD_REG_RM, 0, 0, 0, 0, 0}},   
	/* b7 */ {instr_movzx_0fb7, "movzx", {0, 0, II_MOD_REG_RM, 0, 0, 0, 0, 0}},   
	/* b8 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* b9 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* ba */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* bb */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* bc */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* bd */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* be */ {instr_movsx_0fbe, "movsx", {0, 0, II_MOD_REG_RM, 0, 0, 0, 0, 0}},
	/* bf */ {instr_movsx_0fbf, "movsx", {0, 0, II_MOD_REG_RM, 0, 0, 0, 0, 0}},
	/* c0 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* c1 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* c2 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* c3 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* c4 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* c5 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* c6 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* c7 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* c8 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* c9 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* ca */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* cb */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* cc */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* cd */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* ce */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* cf */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* d0 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* d1 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* d2 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* d3 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* d4 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* d5 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* d6 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* d7 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* d8 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* d9 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* da */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* db */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* dc */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* dd */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* de */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* df */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* e0 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* e1 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* e2 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* e3 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* e4 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* e5 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* e6 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* e7 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* e8 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* e9 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* ea */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* eb */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* ec */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* ed */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* ee */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* ef */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* f0 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* f1 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* f2 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* f3 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* f4 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* f5 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* f6 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* f7 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* f8 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* f9 */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* fa */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* fb */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* fc */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* fd */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* fe */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
	/* ff */ {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}},
};



#endif
