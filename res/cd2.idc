#include <idc.idc>
#include <functions.idc>

// ---------------------------------
// CHIP AND DALE 2 NES SCRIPTS
// ---------------------------------

static make_offset_custom(ea, exec) {
	auto ofs = Word(ea), bank = GetReg(ea,"ds")-1;
	if(ofs<0x800)
		ea = make_offset_ex(ea, 0, exec, 1);
	else if(ofs>=0xC000) {
		ea = make_offset_ex(ea, 7, exec, 1);
	} else {
		if((bank==7)&&(ofs<0xC000)) {
//			ea = make_offset_ex(ea, AskLong(0, "Enter Bank Nunber"), exec, 1);
			ea = ea + 2;
		} else
			ea = make_offset_ex(ea, bank, exec, 1);
	}
	return ea;
}

static make_offset_custom_b(ea, bank, exec) {
	auto ofs = Word(ea);
	if(ofs<0x800)
		ea = make_offset_ex(ea, 0, exec, 1);
	else if(ofs>=0xC000) {
		ea = make_offset_ex(ea, 7, exec, 1);
	} else {
		ea = make_offset_ex(ea, bank, exec, 1);
	}
	return ea;
}

static cd2_opcode_name(cmd) {
	auto ret = "";
	if(cmd == 0x00) {
		ret = "KILL";
	} else if(cmd == 0x01) {
		ret = "SYNC";
	} else if(cmd == 0x02) {
		ret = "SUSPEND";
	} else if(cmd == 0x03) {
		ret = "NJSR_SYNC";
	} else if(cmd == 0x04) {
		ret = "RUN";
	} else if(cmd == 0x05) {
		ret = "NJSR";
	} else if(cmd == 0x06) {
		ret = "SJMP";
	} else if(cmd == 0x07) {
		ret = "SJSR";
	} else if(cmd == 0x08) {
		ret = "SRET";
	} else if(cmd == 0x09) {
		ret = "LOOP_A";					// пупа и лупа писали скрипты...
	} else if(cmd == 0x0A) {
		ret = "LOOP_B";
	} else if(cmd == 0x0B) {
		ret = "SBNE";
	} else if(cmd == 0x0C) {
		ret = "SBCC";
	} else if(cmd == 0x0D) {
		ret = "SBPL";
	} else if(cmd == 0x0E) {
		ret = "SBEQ";
	} else if(cmd == 0x0F) {
		ret = "SBCS";
	} else if(cmd == 0x10) {
		ret = "SBMI";
	} else if(cmd == 0x11) {
		ret = "PADS_TEST";
	} else if(cmd == 0x12) {
		ret = "SWITCH";
	} else if(cmd == 0x13) {
		ret = "STORE";
	} else if(cmd == 0x14) {
		ret = "CHR_SET";
	} else if(cmd == 0x15) {
		ret = "LOOP_A_STOP";
	} else if(cmd == 0x16) {
		ret = "LOOP_B_STOP";
	} else if(cmd == 0x17) {
		ret = "APU_SE_SET";
	} else if(cmd == 0x18) {
		ret = "ANIMATE_HV_SYNC";
	} else if(cmd == 0x19) {
		ret = "ANIMATE_HV";
	} else if(cmd == 0x1A) {
		ret = "TARGET_FOLLOW";
	} else if(cmd == 0x1B) {
		ret = "SPRITE_ON";
	} else if(cmd == 0x1C) {
		ret = "SPRITE_OFF";
	} else if(cmd == 0x1D) {
		ret = "SPR_LIB_SET";
	} else if(cmd == 0x1E) {
		ret = "SPR_IDX_SET";
	} else if(cmd == 0x1F) {
		ret = "FLIP_H_OFF";
	} else if(cmd == 0x20) {
		ret = "FLIP_H_ON";
	} else if(cmd == 0x21) {
		ret = "FLIP_V_OFF";
	} else if(cmd == 0x22) {
		ret = "FLIP_V_ON";
	} else if(cmd == 0x23) {
		ret = "FLIP_H_TOGGLE";
	} else if(cmd == 0x24) {
		ret = "FLIP_V_TOGGLE";
	} else if(cmd == 0x25) {
		ret = "POS_X_SET";
	} else if(cmd == 0x26) {
		ret = "POS_Y_SET";
	} else if(cmd == 0x27) {
		ret = "POS_X_MOVE";
	} else if(cmd == 0x28) {
		ret = "POS_Y_MOVE";
	} else if(cmd == 0x29) {
		ret = "DELTA_X_SET";
	} else if(cmd == 0x2A) {
		ret = "DELTA_Y_SET";
	} else if(cmd == 0x2B) {
		ret = "DELTA_X_INC";		// что-то вроде акселерации, ускорения
	} else if(cmd == 0x2C) {
		ret = "DELTA_Y_INC";
	} else if(cmd == 0x2D) {
		ret = "DELTA_X_DEC";
	} else if(cmd == 0x2E) {
		ret = "DELTA_Y_DEC";
	} else if(cmd == 0x2F) {
		ret = "TARGET_LOCK";
	} else if(cmd == 0x30) {
		ret = "TIMER_A_SET";
	} else if(cmd == 0x31) {
		ret = "TIMER_B_SET";
	} else if(cmd == 0x32) {
		ret = "SIZE_SET";
	} else if(cmd == 0x33) {
		ret = "DAMAGE_SET";
	} else if(cmd == 0x34) {
		ret = "HP_SET";
	} else if(cmd == 0x35) {
		ret = "FLIPS_SET";
	} else if(cmd == 0x36) {
		ret = "VAR_1E_SET";				// unused
	} else if(cmd == 0x37) {
		ret = "MAIN_SUB_SET";			// unused, вместо этого используется команда MOV
	} else if(cmd == 0x38) {
		ret = "PAL_FADE_IN";
	} else if(cmd == 0x39) {
		ret = "PAL_FADE_OUT";
	} else if(cmd == 0x3A) {
		ret = "TLM_RES_QUEUE";			// unused
	} else if(cmd == 0x3B) {
		ret = "MENU_CURSOR_DRAW";
	} else if(cmd == 0x3C) {
		ret = "MENU_HOR_INPUT";			// unused
	} else if(cmd == 0x3D) {
		ret = "MENU_VERT_INPUT";
	} else if(cmd == 0x3E) {
		ret = "MSG_AREA_SET";			// unused
	} else if(cmd == 0x3F) {
		ret = "MSG_DISPLAY";
	} else if(cmd == 0x40) {
		ret = "MSG_WAIT";
	} else if(cmd == 0x41) {
		ret = "BREAK";
	} else if(cmd == 0x42) {
		ret = "DESTR_PC_SET";
	} else if(cmd == 0x43) {
		ret = "GRABABLE_ON";
	} else {
		ret = form("UNK%02X",cmd);
	}
	return ret;
}

static cd2_opcode(ea) {
	auto cmd_opc = "", cmd, bank, tmp0, tmp1, tmp2;
	bank = GetReg(ea,"ds");

//	if(isCode(ea)) ea = BADADDR;

	if(ea != BADADDR) {
//		Message(" start at ea = 0x%08x!\n", ea);
		cmd = Byte(ea);
		cmd_opc = cd2_opcode_name(cmd);

		if((cmd == 0x00)||(cmd == 0x08)) {	// ret/exit/stop
			ea = make_data_array(ea, 1, cmd_opc);
		} else if(cmd==0x12) {	// switch
			ea = make_data_array(ea, 1, cmd_opc);
			ea = make_offset_custom(ea, 0);	// no exec
			make_offset_custom(ea, 0);	// no exec
			ea = Word(ea)+MK_FP(AskSelector(GetReg(ea,"ds")), 0);
		} else if((cmd == 0x01)||(cmd==0x15)||(cmd==0x16)||(cmd==0x18)||(cmd==0x19)||(cmd==0x1A)||(cmd==0x1B)||(cmd==0x1C)||(cmd==0x1F)||(cmd==0x20)||(cmd==0x21)||(cmd==0x22)||(cmd==0x23)||(cmd==0x24)||(cmd==0x2B)||(cmd==0x2C)||(cmd==0x2D)||(cmd==0x2E)||(cmd==0x40)||(cmd==0x43)||(cmd==0x44)) {	// no args
			ea = make_data_array(ea, 1, cmd_opc);
		} else if((cmd==2)||(cmd==0x17)||(cmd==0x1D)||(cmd==0x1E)||(cmd==0x27)||(cmd==0x28)||(cmd==0x29)||(cmd==0x2A)||(cmd==0x2F)||(cmd==0x30)||(cmd==0x31)||(cmd==0x33)||(cmd==0x34)||(cmd==0x35)||(cmd==0x36)||(cmd==0x37)) {	// 1b arg
			ea = make_data_array(ea, 2, cmd_opc);
		} else if((cmd==0x14)||(cmd==0x25)||(cmd==0x26)||(cmd==0x32)||(cmd==0x38)||(cmd==0x39)||(cmd==0x3C)||(cmd==0x3D)) {	// 2b arg
			ea = make_data_array(ea, 3, cmd_opc);
		} else if(cmd==0x3F) {	// ofs, 1b arg
			ea = make_data_array(ea, 1, cmd_opc);
			ea = make_offset_custom_b(ea, 2, 0); // no exec
			ea = make_data_array(ea, 1, "");
		} else if(cmd==0x3E) {	// 4b arg
			ea = make_data_array(ea, 5, cmd_opc);
		} else if(cmd==0x11) {	// 2b args, ofs
			ea = make_data_array(ea, 3, cmd_opc);
			ea = make_offset_custom(ea, 0);	// no exec
		} else if((cmd==0x04)||(cmd==0x09)||(cmd==0x0A)||(cmd==0x13)) {	// 1b args, ofs
			ea = make_data_array(ea, 2, cmd_opc);
			ea = make_offset_custom(ea, 0);	// no exec
		} else if((cmd==0x03)||(cmd==0x05)) {	// ofs
			ea = make_data_array(ea, 1, cmd_opc);
			ea = make_offset_custom(ea, 1);	// exec
		} else if((cmd==0x06)||(cmd==0x07)||(cmd==0x0B)||(cmd==0x0C)||(cmd==0x0D)||(cmd==0x0E)||(cmd==0x0F)||(cmd==0x10)||(cmd==0x3A)||(cmd==0x3B)||(cmd==0x42)||(cmd==0x41)) {	// ofs
			ea = make_data_array(ea, 1, cmd_opc);
			ea = make_offset_custom(ea, 0);	// no exec
		} else {
			Message(" unknown opcode at 0x%08x = %02x\n", ea, cmd);
		}
		return ea;
	} else
		return ea;
}

static cd2_apu_name(cmd) {
	auto ret = "";
	if(cmd == 0xFF) {
		ret = "STOP";
	} else if(cmd == 0xF0) {
		ret = "LOOP_START";
	} else if(cmd == 0xF1) {
		ret = "DO_LOOP";
	} else if(cmd == 0xF2) {
		ret = "JSR";
	} else if(cmd == 0xF3) {
		ret = "RET";
	} else if(cmd == 0xF8) {
		ret = "JMP";
	} else {
		ret = form("CMD%02X",cmd);
	}
	return ret;
}

static cd2_apu(ea) {
	auto cmd_opc = "", cmd, bank, tmp0, tmp1, tmp2, stop = 0;
	bank = GetReg(ea,"ds");
	tmp2 = ea;
	do {
		if(ea != BADADDR) {
			tmp0 = 0;
			tmp1 = ea;
			while((cmd = Byte(ea)) < 0xD0) {
				tmp0++;
				ea++;
			}
			if(tmp0>0) {
				ea = make_data_array(tmp1, tmp0, "DATA");
				cmd = Byte(ea);
			}
//			Message(" cmd == %04x\n", cmd);
			cmd_opc = cd2_apu_name(cmd);
			if((cmd == 0xF3)||(cmd == 0xFF)) {	// RET/STOP
				ea = make_data_array(ea, 1, cmd_opc);
				stop = 1;
				// stop here
			} else if(((cmd >= 0xD0)&&(cmd<=0xD8))||(cmd==0xE8)||(cmd==0xF1)) {	// no args
				ea = make_data_array(ea, 1, cmd_opc);
			} else if(((cmd >= 0xD9)&&(cmd<=0xE2))||((cmd>=0xE9)&&(cmd<=0xED))||(cmd==0xF0)) {	// 1b arg
				ea = make_data_array(ea, 2, cmd_opc);
			} else if(cmd==0xF2) {	// ofs
				ea = make_data_array(ea, 1, cmd_opc);
				ea = make_offset_custom_b(ea, 6, 0); // no exec
			} else if(cmd==0xF8) {	// ofs
				ea = make_data_array(ea, 1, cmd_opc);
				ea = make_offset_custom_b(ea, 6, 0); // no exec
				stop = 1;
				// stop here
			} else {
				Message(" unknown apu opcode at 0x%08x = %02x\n", ea, cmd);
			}
//			return ea;
		}
	} while (!stop);
//	return tmp2;
	return ea;
}

static cd2_script_selection(void) {
	Jump(cd2_opcode(ScreenEA()));
}

static cd2_apu_selection(void) {
	Jump(cd2_apu(ScreenEA()));
}

static main(void) {
	AddHotkey("Shift-O", "cd2_script_selection");
	AddHotkey("Shift-I", "cd2_apu_selection");
}
