optbl[0x7d] = &sSMP::op_mov_a_x;
optbl[0xdd] = &sSMP::op_mov_a_y;
optbl[0x5d] = &sSMP::op_mov_x_a;
optbl[0xfd] = &sSMP::op_mov_y_a;
optbl[0x9d] = &sSMP::op_mov_x_sp;
optbl[0xbd] = &sSMP::op_mov_sp_x;
optbl[0xe8] = &sSMP::op_mov_a_const;
optbl[0xcd] = &sSMP::op_mov_x_const;
optbl[0x8d] = &sSMP::op_mov_y_const;
optbl[0xe6] = &sSMP::op_mov_a_ix;
optbl[0xbf] = &sSMP::op_mov_a_ixinc;
optbl[0xe4] = &sSMP::op_mov_a_dp;
optbl[0xf8] = &sSMP::op_mov_x_dp;
optbl[0xeb] = &sSMP::op_mov_y_dp;
optbl[0xf4] = &sSMP::op_mov_a_dpx;
optbl[0xf9] = &sSMP::op_mov_x_dpy;
optbl[0xfb] = &sSMP::op_mov_y_dpx;
optbl[0xe5] = &sSMP::op_mov_a_addr;
optbl[0xe9] = &sSMP::op_mov_x_addr;
optbl[0xec] = &sSMP::op_mov_y_addr;
optbl[0xf5] = &sSMP::op_mov_a_addrx;
optbl[0xf6] = &sSMP::op_mov_a_addry;
optbl[0xe7] = &sSMP::op_mov_a_idpx;
optbl[0xf7] = &sSMP::op_mov_a_idpy;
optbl[0xfa] = &sSMP::op_mov_dp_dp;
optbl[0x8f] = &sSMP::op_mov_dp_const;
optbl[0xc6] = &sSMP::op_mov_ix_a;
optbl[0xaf] = &sSMP::op_mov_ixinc_a;
optbl[0xc4] = &sSMP::op_mov_dp_a;
optbl[0xd8] = &sSMP::op_mov_dp_x;
optbl[0xcb] = &sSMP::op_mov_dp_y;
optbl[0xd4] = &sSMP::op_mov_dpx_a;
optbl[0xd9] = &sSMP::op_mov_dpy_x;
optbl[0xdb] = &sSMP::op_mov_dpx_y;
optbl[0xc5] = &sSMP::op_mov_addr_a;
optbl[0xc9] = &sSMP::op_mov_addr_x;
optbl[0xcc] = &sSMP::op_mov_addr_y;
optbl[0xd5] = &sSMP::op_mov_addrx_a;
optbl[0xd6] = &sSMP::op_mov_addry_a;
optbl[0xc7] = &sSMP::op_mov_idpx_a;
optbl[0xd7] = &sSMP::op_mov_idpy_a;
optbl[0xba] = &sSMP::op_movw_ya_dp;
optbl[0xda] = &sSMP::op_movw_dp_ya;
optbl[0xaa] = &sSMP::op_mov1_c_bit;
optbl[0xca] = &sSMP::op_mov1_bit_c;
optbl[0x2f] = &sSMP::op_bra;
optbl[0xf0] = &sSMP::op_beq;
optbl[0xd0] = &sSMP::op_bne;
optbl[0xb0] = &sSMP::op_bcs;
optbl[0x90] = &sSMP::op_bcc;
optbl[0x70] = &sSMP::op_bvs;
optbl[0x50] = &sSMP::op_bvc;
optbl[0x30] = &sSMP::op_bmi;
optbl[0x10] = &sSMP::op_bpl;
optbl[0x03] = &sSMP::op_bbs0;
optbl[0x13] = &sSMP::op_bbc0;
optbl[0x23] = &sSMP::op_bbs1;
optbl[0x33] = &sSMP::op_bbc1;
optbl[0x43] = &sSMP::op_bbs2;
optbl[0x53] = &sSMP::op_bbc2;
optbl[0x63] = &sSMP::op_bbs3;
optbl[0x73] = &sSMP::op_bbc3;
optbl[0x83] = &sSMP::op_bbs4;
optbl[0x93] = &sSMP::op_bbc4;
optbl[0xa3] = &sSMP::op_bbs5;
optbl[0xb3] = &sSMP::op_bbc5;
optbl[0xc3] = &sSMP::op_bbs6;
optbl[0xd3] = &sSMP::op_bbc6;
optbl[0xe3] = &sSMP::op_bbs7;
optbl[0xf3] = &sSMP::op_bbc7;
optbl[0x2e] = &sSMP::op_cbne_dp;
optbl[0xde] = &sSMP::op_cbne_dpx;
optbl[0x6e] = &sSMP::op_dbnz_dp;
optbl[0xfe] = &sSMP::op_dbnz_y;
optbl[0x5f] = &sSMP::op_jmp_addr;
optbl[0x1f] = &sSMP::op_jmp_iaddrx;
optbl[0x3f] = &sSMP::op_call;
optbl[0x4f] = &sSMP::op_pcall;
optbl[0x01] = &sSMP::op_tcall_0;
optbl[0x11] = &sSMP::op_tcall_1;
optbl[0x21] = &sSMP::op_tcall_2;
optbl[0x31] = &sSMP::op_tcall_3;
optbl[0x41] = &sSMP::op_tcall_4;
optbl[0x51] = &sSMP::op_tcall_5;
optbl[0x61] = &sSMP::op_tcall_6;
optbl[0x71] = &sSMP::op_tcall_7;
optbl[0x81] = &sSMP::op_tcall_8;
optbl[0x91] = &sSMP::op_tcall_9;
optbl[0xa1] = &sSMP::op_tcall_10;
optbl[0xb1] = &sSMP::op_tcall_11;
optbl[0xc1] = &sSMP::op_tcall_12;
optbl[0xd1] = &sSMP::op_tcall_13;
optbl[0xe1] = &sSMP::op_tcall_14;
optbl[0xf1] = &sSMP::op_tcall_15;
optbl[0x0f] = &sSMP::op_brk;
optbl[0x6f] = &sSMP::op_ret;
optbl[0x7f] = &sSMP::op_reti;
optbl[0x88] = &sSMP::op_adc_a_const;
optbl[0x28] = &sSMP::op_and_a_const;
optbl[0x68] = &sSMP::op_cmp_a_const;
optbl[0xc8] = &sSMP::op_cmp_x_const;
optbl[0xad] = &sSMP::op_cmp_y_const;
optbl[0x48] = &sSMP::op_eor_a_const;
optbl[0x08] = &sSMP::op_or_a_const;
optbl[0xa8] = &sSMP::op_sbc_a_const;
optbl[0x86] = &sSMP::op_adc_a_ix;
optbl[0x26] = &sSMP::op_and_a_ix;
optbl[0x66] = &sSMP::op_cmp_a_ix;
optbl[0x46] = &sSMP::op_eor_a_ix;
optbl[0x06] = &sSMP::op_or_a_ix;
optbl[0xa6] = &sSMP::op_sbc_a_ix;
optbl[0x84] = &sSMP::op_adc_a_dp;
optbl[0x24] = &sSMP::op_and_a_dp;
optbl[0x64] = &sSMP::op_cmp_a_dp;
optbl[0x3e] = &sSMP::op_cmp_x_dp;
optbl[0x7e] = &sSMP::op_cmp_y_dp;
optbl[0x44] = &sSMP::op_eor_a_dp;
optbl[0x04] = &sSMP::op_or_a_dp;
optbl[0xa4] = &sSMP::op_sbc_a_dp;
optbl[0x94] = &sSMP::op_adc_a_dpx;
optbl[0x34] = &sSMP::op_and_a_dpx;
optbl[0x74] = &sSMP::op_cmp_a_dpx;
optbl[0x54] = &sSMP::op_eor_a_dpx;
optbl[0x14] = &sSMP::op_or_a_dpx;
optbl[0xb4] = &sSMP::op_sbc_a_dpx;
optbl[0x85] = &sSMP::op_adc_a_addr;
optbl[0x25] = &sSMP::op_and_a_addr;
optbl[0x65] = &sSMP::op_cmp_a_addr;
optbl[0x1e] = &sSMP::op_cmp_x_addr;
optbl[0x5e] = &sSMP::op_cmp_y_addr;
optbl[0x45] = &sSMP::op_eor_a_addr;
optbl[0x05] = &sSMP::op_or_a_addr;
optbl[0xa5] = &sSMP::op_sbc_a_addr;
optbl[0x95] = &sSMP::op_adc_a_addrx;
optbl[0x96] = &sSMP::op_adc_a_addry;
optbl[0x35] = &sSMP::op_and_a_addrx;
optbl[0x36] = &sSMP::op_and_a_addry;
optbl[0x75] = &sSMP::op_cmp_a_addrx;
optbl[0x76] = &sSMP::op_cmp_a_addry;
optbl[0x55] = &sSMP::op_eor_a_addrx;
optbl[0x56] = &sSMP::op_eor_a_addry;
optbl[0x15] = &sSMP::op_or_a_addrx;
optbl[0x16] = &sSMP::op_or_a_addry;
optbl[0xb5] = &sSMP::op_sbc_a_addrx;
optbl[0xb6] = &sSMP::op_sbc_a_addry;
optbl[0x87] = &sSMP::op_adc_a_idpx;
optbl[0x27] = &sSMP::op_and_a_idpx;
optbl[0x67] = &sSMP::op_cmp_a_idpx;
optbl[0x47] = &sSMP::op_eor_a_idpx;
optbl[0x07] = &sSMP::op_or_a_idpx;
optbl[0xa7] = &sSMP::op_sbc_a_idpx;
optbl[0x97] = &sSMP::op_adc_a_idpy;
optbl[0x37] = &sSMP::op_and_a_idpy;
optbl[0x77] = &sSMP::op_cmp_a_idpy;
optbl[0x57] = &sSMP::op_eor_a_idpy;
optbl[0x17] = &sSMP::op_or_a_idpy;
optbl[0xb7] = &sSMP::op_sbc_a_idpy;
optbl[0x99] = &sSMP::op_adc_ix_iy;
optbl[0x39] = &sSMP::op_and_ix_iy;
optbl[0x79] = &sSMP::op_cmp_ix_iy;
optbl[0x59] = &sSMP::op_eor_ix_iy;
optbl[0x19] = &sSMP::op_or_ix_iy;
optbl[0xb9] = &sSMP::op_sbc_ix_iy;
optbl[0x89] = &sSMP::op_adc_dp_dp;
optbl[0x29] = &sSMP::op_and_dp_dp;
optbl[0x69] = &sSMP::op_cmp_dp_dp;
optbl[0x49] = &sSMP::op_eor_dp_dp;
optbl[0x09] = &sSMP::op_or_dp_dp;
optbl[0xa9] = &sSMP::op_sbc_dp_dp;
optbl[0x98] = &sSMP::op_adc_dp_const;
optbl[0x38] = &sSMP::op_and_dp_const;
optbl[0x78] = &sSMP::op_cmp_dp_const;
optbl[0x58] = &sSMP::op_eor_dp_const;
optbl[0x18] = &sSMP::op_or_dp_const;
optbl[0xb8] = &sSMP::op_sbc_dp_const;
optbl[0x7a] = &sSMP::op_addw_ya_dp;
optbl[0x9a] = &sSMP::op_subw_ya_dp;
optbl[0x5a] = &sSMP::op_cmpw_ya_dp;
optbl[0x4a] = &sSMP::op_and1_bit;
optbl[0x6a] = &sSMP::op_and1_notbit;
optbl[0x8a] = &sSMP::op_eor1_bit;
optbl[0xea] = &sSMP::op_not1_bit;
optbl[0x0a] = &sSMP::op_or1_bit;
optbl[0x2a] = &sSMP::op_or1_notbit;
optbl[0xbc] = &sSMP::op_inc_a;
optbl[0x3d] = &sSMP::op_inc_x;
optbl[0xfc] = &sSMP::op_inc_y;
optbl[0x9c] = &sSMP::op_dec_a;
optbl[0x1d] = &sSMP::op_dec_x;
optbl[0xdc] = &sSMP::op_dec_y;
optbl[0x1c] = &sSMP::op_asl_a;
optbl[0x5c] = &sSMP::op_lsr_a;
optbl[0x3c] = &sSMP::op_rol_a;
optbl[0x7c] = &sSMP::op_ror_a;
optbl[0xab] = &sSMP::op_inc_dp;
optbl[0x8b] = &sSMP::op_dec_dp;
optbl[0x0b] = &sSMP::op_asl_dp;
optbl[0x4b] = &sSMP::op_lsr_dp;
optbl[0x2b] = &sSMP::op_rol_dp;
optbl[0x6b] = &sSMP::op_ror_dp;
optbl[0xbb] = &sSMP::op_inc_dpx;
optbl[0x9b] = &sSMP::op_dec_dpx;
optbl[0x1b] = &sSMP::op_asl_dpx;
optbl[0x5b] = &sSMP::op_lsr_dpx;
optbl[0x3b] = &sSMP::op_rol_dpx;
optbl[0x7b] = &sSMP::op_ror_dpx;
optbl[0xac] = &sSMP::op_inc_addr;
optbl[0x8c] = &sSMP::op_dec_addr;
optbl[0x0c] = &sSMP::op_asl_addr;
optbl[0x4c] = &sSMP::op_lsr_addr;
optbl[0x2c] = &sSMP::op_rol_addr;
optbl[0x6c] = &sSMP::op_ror_addr;
optbl[0x0e] = &sSMP::op_tset_addr_a;
optbl[0x4e] = &sSMP::op_tclr_addr_a;
optbl[0x3a] = &sSMP::op_incw_dp;
optbl[0x1a] = &sSMP::op_decw_dp;
optbl[0x00] = &sSMP::op_nop;
optbl[0xef] = &sSMP::op_sleep;
optbl[0xff] = &sSMP::op_stop;
optbl[0x9f] = &sSMP::op_xcn;
optbl[0xdf] = &sSMP::op_daa;
optbl[0xbe] = &sSMP::op_das;
optbl[0x60] = &sSMP::op_clrc;
optbl[0x20] = &sSMP::op_clrp;
optbl[0x80] = &sSMP::op_setc;
optbl[0x40] = &sSMP::op_setp;
optbl[0xe0] = &sSMP::op_clrv;
optbl[0xed] = &sSMP::op_notc;
optbl[0xa0] = &sSMP::op_ei;
optbl[0xc0] = &sSMP::op_di;
optbl[0x02] = &sSMP::op_set0_dp;
optbl[0x12] = &sSMP::op_clr0_dp;
optbl[0x22] = &sSMP::op_set1_dp;
optbl[0x32] = &sSMP::op_clr1_dp;
optbl[0x42] = &sSMP::op_set2_dp;
optbl[0x52] = &sSMP::op_clr2_dp;
optbl[0x62] = &sSMP::op_set3_dp;
optbl[0x72] = &sSMP::op_clr3_dp;
optbl[0x82] = &sSMP::op_set4_dp;
optbl[0x92] = &sSMP::op_clr4_dp;
optbl[0xa2] = &sSMP::op_set5_dp;
optbl[0xb2] = &sSMP::op_clr5_dp;
optbl[0xc2] = &sSMP::op_set6_dp;
optbl[0xd2] = &sSMP::op_clr6_dp;
optbl[0xe2] = &sSMP::op_set7_dp;
optbl[0xf2] = &sSMP::op_clr7_dp;
optbl[0x2d] = &sSMP::op_push_a;
optbl[0x4d] = &sSMP::op_push_x;
optbl[0x6d] = &sSMP::op_push_y;
optbl[0x0d] = &sSMP::op_push_p;
optbl[0xae] = &sSMP::op_pop_a;
optbl[0xce] = &sSMP::op_pop_x;
optbl[0xee] = &sSMP::op_pop_y;
optbl[0x8e] = &sSMP::op_pop_p;
optbl[0xcf] = &sSMP::op_mul_ya;
optbl[0x9e] = &sSMP::op_div_ya_x;
