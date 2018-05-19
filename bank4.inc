
		ORG $8000

		BANK_START $04

		SECTION_START	0B

; =============== S C R I P T   R O U T I N E ===============================
_script_unref:
		NJSR				_obj_move_hor_animate
		NJSR				_native_sub104
		SBCC				byte_6800C
		NJSR				_native_sub105
byte_6800C:
		SJSR				_script_sub_68044
		SBCC				byte_6801F
		NJSR				_native_get_obj_y_delta
		SBPL				byte_6801C
		NJSR				_native_sub107
		SRET
byte_6801C:
		NJSR				_scr_flags_flush_clc
byte_6801F:
		SRET

; =============== S C R I P T   R O U T I N E ===============================
byte_68020:
		SYNC
		NJSR				_native_get_obj_y_delta
		SBNE				byte_6802F
		SJSR				_script_sub_6803E
		SBCS				byte_6802F
		OBJ_SET_X_DELTA		$00
byte_6802F:
		NJSR				_native_get_obj_hp
		SBEQ				byte_68020
		SRET

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_68036:
		SJSR				_script_sub_6803D
		SBCS				_script_sub_68036
		SRET

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_6803D:
		SYNC

; !FALLTHROUGH!

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_6803E:
		NJSR				_obj_move_hor_animate
		NJSR				_native_sub104

; !FALLTHROUGH!

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_68044:
		NJSR				_native_sub109
		NJSR				_native_get_obj_y_delta
		SBMI				byte_6805C
		NJSR				_obj_vert_animate
		NJSR				_native_sub10A
		SBCC				byte_68058
		OBJ_SET_Y_DELTA		$01
byte_68058:
		NJSR				_scr_flags_flush_clc
		SRET

; =============== S C R I P T   R O U T I N E ===============================
byte_6805C:
		NJSR				_native_sub10B
		SBCS				byte_68064
		OBJ_SET_Y_DELTA		$00
byte_68064:
		SRET

; =============== S C R I P T   R O U T I N E ===============================
byte_68065:
		NJMP				_native_get_obj_var0D
		SBMI				byte_68065
		SRET

; =============== S C R I P T   R O U T I N E ===============================
byte_6806C:
		NJSR				_native_sub13A
		NJSR				_native_sub134
		NJSR				_native_sub164
byte_68075:
		NJSR				_native_get_obj_var0D
		SBMI				byte_68081
		NJMP				_players_animB_sub0129_sub06_C
		SJMP				byte_68075
byte_68081:
		NJSR				_native_sub12B
		APU_LOAD			$24
		SRET

; =============== S C R I P T   R O U T I N E ===============================
byte_68087:
		APU_LOAD			$2D
		VAR_1C_SET			$00
		OBJ_SET_X_DELTA		$BD
		OBJ_SET_Y_DELTA		$BD
		NJSR				_players_animB_sub3_B_A
byte_68092:
		JMP_OBJ_ANIMATE
		SJMP				byte_68092
byte_68096:
		JMP_OBJ_ANIMATE
		NJSR				_native_sub109
		SJMP				byte_68096
_script_sub_6809D:
		SJSR				_script_sub_680E7
		OBJ_SET_X_DELTA		$00
		NJSR				_scr_param_4_clear
byte_680A5:
		SJSR				_script_sub_680C3
		LOOPA				$3C,byte_680A5
		LOOPB				$08,byte_680A5
		NJSR				_scr_param_10_set
byte_680B3:
		SJSR				_script_sub_680C3
		LOOPA				$78,byte_680B3
		NJSR				_scr_param_10_clear
		NJSR				_players_animB_sub0129_sub06_A
		VAR_1C_SET			$01
		SRET

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_680C3:
		SYNC
		NJSR				_native_get_obj_var0D
		SBPL				byte_680D4
		NJSR				_native_sub118
		SBCC				byte_680D3
		SJSR				_script_sub_68044
byte_680D3:
		SRET
byte_680D4:
		SJSR				_script_sub_68102
		VAR_1C_SET			$02
		OBJ_SET_X_DELTA		$C0
		NJSR				_native_sub11B
		NJSR				_native_sub11C
		NJSR				_native_sub11D
		SJMP				byte_68092
_script_sub_680E7:
		VAR_1C_SET			$00
		APU_LOAD			$2E
		OBJ_SET_X_DELTA		$F0
		OBJ_SET_Y_DELTA		$D0
		NJSR				_players_animB_sub3_B_A
		NJSR				_players_animB_sub0129_sub0E_A
byte_680F5:
		SJSR				_script_sub_6803D
		SBCC				byte_68101
		NJSR				_native_get_obj_var0D
		SBMI				byte_680F5
byte_68101:
		SRET
_script_sub_68102:
		OBJ_SET_Y_DELTA		$00
		NJSR				_native_sub134
		NJSR				_scr_param_10_clear
byte_6810A:
		SYNC
		NJSR				_players_animB_sub0129_sub06_C
		NJSR				_native_get_obj_var0D
		SBPL				byte_6810A
		APU_LOAD			$24
		SRET

; =============== O B J E C T   S C R I P T =================================
_obj_scr24:
		DESTR_PC_SET		byte_6818F
		SPR_LIB_SELECT		$07
		SPR_IDX_SELECT		$00
		OBJ_SET_SIZE		$08,$18
		OBJ_SET_HP			$02
		VAR_1C_SET			$01
		SJSR				_script201
		OBJ_SET_X_DELTA		$F0
		OBJ_SET_Y_DELTA		$00
		NJSR				_native_sub10E
		NJSR				_native_sub10F
byte_68132:
		SPR_IDX_SELECT		$00
		SJSR				_script_sub_6814C
		SPR_IDX_SELECT		$01
		SJSR				_script_sub_6814C
		SPR_IDX_SELECT		$02
		SJSR				_script_sub_6814C
		SPR_IDX_SELECT		$01
		SJSR				_script_sub_6814C
byte_68146:
		NJSR				_native_sub110
		SJMP				byte_68132
_script_sub_6814C:
		SYNC
		NJSR				_native_sub131
		SBCS				byte_6816A
		NJSR				_obj_move_hor_animate
		NJSR				_native_sub104
		SBCC				byte_6815F
		BREAK				byte_68146
byte_6815F:
		NJSR				_native_sub118
		SBCS				_script_sub_68036
		LOOPA				$08,_script_sub_6814C
		SRET
byte_6816A:
		NJSR				_native_sub132
		SPR_IDX_SELECT		$03
		SUSPEND				$08
		SPR_IDX_SELECT		$04
		APU_LOAD			$5E
		NJSR				_native_sub10C
		SBCC				byte_6817E
		NJSR				_native_sub10D
byte_6817E:
		SUSPEND				$08
		SPR_IDX_SELECT		$05
		SUSPEND				$08
		SPR_IDX_SELECT		$00
		SUSPEND				$08
		NJSR				_native_sub10E
		NJSR				_native_sub10F
		SRET
byte_6818F:
		SPR_IDX_SELECT		$06
		NJSR				_native_get_obj_hp
		SBNE				byte_68087
		SJSR				_script_sub_6809D
		SJMP				_obj_scr24

; =============== O B J E C T   S C R I P T =================================
_obj_scr25:
		DESTR_PC_SET		byte_68087
		SPR_LIB_SELECT		$07
		SPR_IDX_SELECT		$07
		OBJ_SET_HP			$01
		VAR_1C_SET			$01
		OBJ_SET_SIZE		$08,$18
		SJSR				_script201
		OBJ_SET_X_DELTA		$F0
		OBJ_SET_Y_DELTA		$00
		NJSR				_native_sub10E
		NJSR				_native_sub10F
byte_681B8:
		SPR_IDX_SELECT		$08
		SJSR				_script_sub_681D2
		SPR_IDX_SELECT		$09
		SJSR				_script_sub_681D2
		SPR_IDX_SELECT		$0A
		SJSR				_script_sub_681D2
		SPR_IDX_SELECT		$09
		SJSR				_script_sub_681D2
		NJSR				_native_sub110
		SJMP				byte_681B8
_script_sub_681D2:
		JMP_OBJ_ANIMATE
		NJSR				_native_sub115
		SBCC				byte_681DF
		NJSR				_native_sub17E
		SBCS				byte_681E4
byte_681DF:
		LOOPA				$08,_script_sub_681D2
		SRET
byte_681E4:
		LOOPA_RESET
		LOOPB_RESET
		NJSR				_native_sub10E
		NJSR				_native_sub10F
		BREAK				byte_681EF
byte_681EF:
		SPR_IDX_SELECT		$07
		SUSPEND				$10
		SPR_IDX_SELECT		$0C
		SUSPEND				$10
		APU_LOAD			$5F
		SPR_IDX_SELECT		$0D
		SRUN				$06,_script100
		SUSPEND				$10
		SPR_IDX_SELECT		$07
		SUSPEND				$10
byte_68205:
		SPR_IDX_SELECT		$08
		SJSR				_script_sub_6821C
		SPR_IDX_SELECT		$09
		SJSR				_script_sub_6821C
		SPR_IDX_SELECT		$0A
		SJSR				_script_sub_6821C
		SPR_IDX_SELECT		$09
		SJSR				_script_sub_6821C
		SJMP				byte_68205
_script_sub_6821C:
		SYNC
		NJSR				_obj_move_hor_animate
		NJSR				_native_sub104
		SBCS				byte_68231
		NJSR				_native_sub118
		SBCS				byte_68231
		LOOPA				$08,_script_sub_6821C
		SRET
byte_68231:
		LOOPA_RESET
		SPR_IDX_SELECT		$09
		OBJ_SET_Y_DELTA		$C0
		SJMP				_script_sub_68036

; =============== S C R I P T ===============================================
_script100:
		DESTR_PC_SET		byte_68252
		OBJ_SET_HP			$01
		VAR_1C_SET			$01
		OBJ_SET_SIZE		$08,$04
		SPR_LIB_SELECT		$07
		SPR_IDX_SELECT		$0E
		OBJ_MOVE_Y_POS		$F0
		OBJ_SET_X_DELTA		$30
		NJSR				_native_sub12E
		PARAM_80_CLEAR
		SJMP				byte_68092
byte_68252:
		OBJ_SET_X_DELTA		$0C
		OBJ_SET_Y_DELTA		$E0
		NJSR				_players_animB_sub3_B_A
		SJMP				byte_68096

; =============== O B J E C T   S C R I P T =================================
_obj_scr26:
		DESTR_PC_SET		byte_68087
		OBJ_MOVE_X_POS		$F8
		SPR_LIB_SELECT		$07
		SPR_IDX_SELECT		$4C
		OBJ_SET_HP			$01
		VAR_1C_SET			$01
		OBJ_SET_SIZE		$08,$0F
		PARAM_80_CLEAR
		SJSR				_script201
		NJSR				_native_sub10E
byte_68273:
		SYNC
		NJSR				_native_sub17E
		SBCC				byte_68273
		NJSR				_native_sub115
		SBCC				byte_68273
		APU_LOAD			$60
		OBJ_SET_SIZE		$08,$18
		SPR_IDX_SELECT		$0F
		SUSPEND				$04
		SPR_IDX_SELECT		$10
		SUSPEND				$04
		SPR_IDX_SELECT		$11
		SUSPEND				$04
		SPR_IDX_SELECT		$12
		SUSPEND				$08
		SPR_IDX_SELECT		$14
		OBJ_SET_Y_DELTA		$D0
		SUSPEND				$08
		SJSR				_script_sub_68036
		OBJ_SET_X_DELTA		$F0
		OBJ_SET_Y_DELTA		$00
		NJSR				_native_sub10F
byte_682A5:
		SPR_IDX_SELECT		$13
		SJSR				_script_sub_682BC
		SPR_IDX_SELECT		$14
		SJSR				_script_sub_682BC
		SPR_IDX_SELECT		$15
		SJSR				_script_sub_682BC
		SPR_IDX_SELECT		$14
		SJSR				_script_sub_682BC
		SJMP				byte_682A5
_script_sub_682BC:
		SYNC
		NJSR				_obj_move_hor_animate
		NJSR				_native_sub104
		SBCS				byte_682D1
		NJSR				_native_sub118
		SBCS				byte_682D1
		LOOPA				$08,_script_sub_682BC
		SRET
byte_682D1:
		LOOPA_RESET
		SPR_IDX_SELECT		$14
		OBJ_SET_Y_DELTA		$C0
		SJMP				_script_sub_68036

; =============== O B J E C T   S C R I P T =================================
_obj_scr27:
		DESTR_PC_SET		byte_68087
		SPR_LIB_SELECT		$07
		SPR_IDX_SELECT		$16
		OBJ_SET_HP			$01
		VAR_1C_SET			$01
		OBJ_SET_SIZE		$08,$10
		OBJ_SET_X_DELTA		$10
		OBJ_SET_Y_DELTA		$04
		SJSR				_script201
		NJSR				_native_sub10E
		NJSR				_native_sub10F
byte_682F4:
		SPR_IDX_SELECT		$16
		APU_LOAD			$61
		SJSR				_script_animate3
		SPR_IDX_SELECT		$17
		APU_LOAD			$61
		SJSR				_script_animate3
		LOOPA				$08,byte_682F4
byte_68306:
		SPR_IDX_SELECT		$18
		SJSR				_script_sub_6833A
		SPR_IDX_SELECT		$19
		SJSR				_script_sub_6833A
		LOOPA				$02,byte_68306
byte_68314:
		SPR_IDX_SELECT		$1A
		SJSR				_script_sub_6833A
		SPR_IDX_SELECT		$1B
		SJSR				_script_sub_6833A
		LOOPA				$02,byte_68314
		SRUN				$08,_script101
byte_68326:
		SPR_IDX_SELECT		$16
		SJSR				_script_sub_6833A
		SPR_IDX_SELECT		$17
		SJSR				_script_sub_6833A
		LOOPA				$02,byte_68326
		NJSR				_native_sub129
		SJMP				byte_682F4
_script_sub_6833A:
		APU_LOAD			$61
		SUSPEND				$03
		SRET

; =============== S C R I P T ===============================================
_script101:
		NJSR				_native_sub12B
		OBJ_MOVE_Y_POS		$08
		OBJ_SET_HP			$01
		VAR_1C_SET			$02
		OBJ_SET_SIZE		$02,$04
		SPR_LIB_SELECT		$07
		SPR_IDX_SELECT		$1C
		OBJ_SET_Y_DELTA		$08
		PARAM_80_CLEAR
		SJMP				byte_68096

; =============== O B J E C T   S C R I P T =================================
_obj_scr28:
		DESTR_PC_SET		byte_68087
		OBJ_MOVE_Y_POS		$FC
		SPR_LIB_SELECT		$07
		SPR_IDX_SELECT		$28
		OBJ_SET_SIZE		$08,$18
		OBJ_SET_HP			$01
		VAR_1C_SET			$01
		SJSR				_script201
		NJSR				_native_sub10E
byte_6836B:
		NJMP				_native_sub112
		SBCC				byte_6836B
		TARGET_DIR_SET		$00
byte_68373:
		NJSR				_native_sub10E
		SJSR				_script_sub_68408
		LOOPA				$03,byte_68373
		NJSR				_native_sub111
		TARGET_LOCK			$20
byte_68382:
		TARGET_DIR_SET		$FF
		SJSR				_script_sub_68408
		SJMP				byte_68382

; =============== O B J E C T   S C R I P T =================================
_obj_scr29:
		DESTR_PC_SET		byte_68087
		SPR_LIB_SELECT		$07
		SPR_IDX_SELECT		$26
		OBJ_SET_SIZE		$08,$18
		OBJ_SET_HP			$01
		VAR_1C_SET			$01
		SJSR				_script201
		OBJ_SET_X_DELTA		$F0
		OBJ_SET_Y_DELTA		$00
		NJSR				_native_sub10E
		NJSR				_native_sub10F
byte_683A5:
		SPR_IDX_SELECT		$25
		SJSR				_script_sub_683BF
		SPR_IDX_SELECT		$26
		SJSR				_script_sub_683BF
		SPR_IDX_SELECT		$27
		SJSR				_script_sub_683BF
		SPR_IDX_SELECT		$26
		SJSR				_script_sub_683BF
		NJSR				_native_sub110
		SJMP				byte_683A5
_script_sub_683BF:
		SYNC
		NJSR				_obj_move_hor_animate
		NJSR				_native_sub112
		SBCS				byte_683CE
		LOOPA				$08,_script_sub_683BF
		SRET
byte_683CE:
		LOOPA_RESET
		TARGET_SPD_SET		$30
		TARGET_LOCK			$20
		TARGET_DIR_SET		$FF
byte_683D5:
		SJSR				_script_sub_68408
		LOOPA				$02,byte_683D5
		NJSR				_native_sub113
		SBMI				byte_683E5
		SJSR				_script_sub_68408
byte_683E5:
		NJSR				_native_sub10E
		OBJ_SET_X_DELTA		$20
		NJSR				_native_sub10F
byte_683ED:
		APU_LOAD			$64
byte_683EF:
		SPR_IDX_SELECT		$29
byte_683F1:
		NJMP				_native_sub122
		LOOPA				$04,byte_683F1
		SPR_IDX_SELECT		$2A
byte_683FA:
		NJMP				_native_sub122
		LOOPA				$04,byte_683FA
		LOOPB				$02,byte_683EF
		SJMP				byte_683ED
_script_sub_68408:
		APU_LOAD			$64
		OBJ_SET_SIZE		$0C,$10
		SPR_IDX_SELECT		$29
		SJSR				_script_sub_6841E
		SPR_IDX_SELECT		$2A
		SJSR				_script_sub_6841E
		SPR_IDX_SELECT		$29
		SJSR				_script_sub_6841E
		SPR_IDX_SELECT		$2A
_script_sub_6841E:
		TARGET_FOLLOW
		SYNC
		LOOPB				$04,_script_sub_6841E
		SRET

; =============== O B J E C T   S C R I P T =================================
_obj_scr2A:
		DESTR_PC_SET		byte_68087
		NJSR				_scr_param_4_set
		SPR_LIB_SELECT		$07
		OBJ_SET_HP			$01
		VAR_1C_SET			$01
		OBJ_SET_SIZE		$08,$20
byte_68434:
		PARAM_80_CLEAR
		APU_LOAD			$65
		SPR_IDX_SELECT		$1D
		SUSPEND				$04
		SPR_IDX_SELECT		$1E
		SUSPEND				$04
		NJSR				_native_sub114
		NJSR				_scr_param_4_clear
		OBJ_SET_Y_DELTA		$B7
		SJSR				byte_6846D
		OBJ_SET_Y_DELTA		$00
		SJSR				byte_6846D
		NJSR				_scr_param_4_set
		NJSR				_native_sub114
		APU_LOAD			$65
		SPR_IDX_SELECT		$23
		SUSPEND				$04
		SPR_IDX_SELECT		$24
		SUSPEND				$04
		PARAM_80_SET
		SUSPEND				$F0
		NJSR				_native_sub113
		SBMI				byte_68434
		SUSPEND				$78
		SJMP				byte_68434
byte_6846D:
		SPR_IDX_SELECT		$1F
		SJSR				byte_6847E
		SPR_IDX_SELECT		$20
		SJSR				byte_6847E
		LOOPA				$02,byte_6846D
		FLIP_40_TOGGLE
		FLIP_80_TOGGLE
		SRET
byte_6847E:
		SYNC
		OBJ_INC_Y_DELTA
		OBJ_INC_Y_DELTA
		NJSR				_obj_vert_animate
		LOOPB				$09,byte_6847E
		SRET

; =============== O B J E C T   S C R I P T =================================
_obj_scr2B:
		OBJ_MOVE_X_POS		$F8
		DESTR_PC_SET		byte_68527
byte_6848E:
		SPR_LIB_SELECT		$07
		SPR_IDX_SELECT		$4C
		OBJ_SET_HP			$02
		VAR_1C_SET			$01
		PARAM_80_CLEAR
byte_68497:
		OBJ_SET_SIZE		$08,$0F
byte_6849A:
		SJSR				byte_68514
		NJSR				_native_sub115
		SBCC				byte_6849A
		NJSR				_native_sub116
		SBCC				byte_6849A
		NJSR				_native_sub10E
byte_684AC:
		OBJ_MOVE_Y_POS		$FE
		SJSR				byte_6851F
		OBJ_MOVE_Y_POS		$02
		APU_LOAD			$60
		SJSR				byte_6851F
		SJSR				byte_6851F
		LOOPA				$03,byte_684AC
		NJSR				_native_sub10E
		SPR_IDX_SELECT		$2B
		SJSR				byte_6851F
		SPR_IDX_SELECT		$2C
		SJSR				byte_6851F
		SPR_IDX_SELECT		$2D
		SJSR				byte_6851F
		SPR_IDX_SELECT		$2E
		SRUN				$07,_script102
		SBCC				byte_6849A
		NJSR				_native_sub117
		OBJ_SET_SIZE		$08,$28
byte_684E0:
		SJSR				byte_6851F
		SPR_IDX_SELECT		$2F
		SJSR				byte_6851F
		SPR_IDX_SELECT		$30
		LOOPA				$14,byte_684E0
		NJSR				_players_animB_sub0129_sub06_A
		SPR_IDX_SELECT		$2E
		SJSR				byte_6851F
		SPR_IDX_SELECT		$2D
		SJSR				byte_6851F
		SPR_IDX_SELECT		$2C
		SJSR				byte_6851F
		SPR_IDX_SELECT		$2B
		SJSR				byte_6851F
		SPR_IDX_SELECT		$4C
		OBJ_SET_SIZE		$08,$10
byte_6850A:
		SJSR				byte_6851F
		LOOPA				$0A,byte_6850A
		SJMP				byte_68497
byte_68514:
		SYNC
		NJSR				_native_sub118
		SBCC				byte_6851E
		SJSR				_script_sub_68036
byte_6851E:
		SRET
byte_6851F:
		SJSR				byte_68514
		LOOPB				$06,byte_6851F
		SRET
byte_68527:
		NJSR				_players_animB_sub0129_sub06_A
		SPR_IDX_SELECT		$31
		OBJ_SET_SIZE		$08,$1C
		NJSR				_native_get_obj_hp
		SBNE				byte_68087
		SJSR				_script_sub_6809D
		SJMP				byte_6848E

; =============== S C R I P T ===============================================
_script102:
		OBJ_SET_HP			$FF
		VAR_1C_SET			$02
		OBJ_SET_SIZE		$08,$10
byte_68542:
		NJSR				_native_sub04A_A
		OBJ_MOVE_Y_POS		$18
		NJMP				_native_sub119
		SJMP				byte_68542

; =============== O B J E C T   S C R I P T =================================
_obj_scr2D:
		DESTR_PC_SET		_obj_scr2D_destr
		SPR_LIB_SELECT		$07
		SPR_IDX_SELECT		$32
		OBJ_SET_HP			$02
		VAR_1C_SET			$01
		OBJ_SET_SIZE		$05,$20
		SJSR				_script201
		NJSR				_native_sub10E
byte_68561:
		SJSR				byte_68587
		OBJ_SET_X_DELTA		$E0
		NJSR				_native_sub10F
byte_68569:
		SJSR				byte_685AE
		LOOPA				$04,byte_68569
		SJSR				byte_6859D
		OBJ_SET_X_DELTA		$F0
		OBJ_SET_Y_DELTA		$CF
		SJSR				byte_685CD
		NJSR				_native_sub110
		OBJ_SET_X_DELTA		$10
		OBJ_SET_Y_DELTA		$CF
		SJSR				byte_685CD
		SJMP				byte_68561
byte_68587:
		OBJ_SET_X_DELTA		$00
		TARGET_DIR_SET		$18
		SJSR				byte_685AE
		TARGET_DIR_SET		$1A
		SJSR				byte_685AE
		TARGET_DIR_SET		$1C
		SJSR				byte_685AE
		TARGET_DIR_SET		$1E
		SJMP				byte_685AE
byte_6859D:
		OBJ_SET_X_DELTA		$00
		TARGET_DIR_SET		$1C
		SJSR				byte_685AE
		TARGET_DIR_SET		$1A
		SJSR				byte_685AE
		TARGET_DIR_SET		$18
		SJMP				byte_685AE
byte_685AE:
		SJSR				byte_685EA
		SPR_IDX_SELECT		$33
		SJSR				byte_685EA
		SPR_IDX_SELECT		$34
		SJSR				byte_685EA
		SPR_IDX_SELECT		$35
		SJSR				byte_685EA
		SPR_IDX_SELECT		$36
		SJSR				byte_685EA
		SPR_IDX_SELECT		$37
		SJSR				byte_685EA
		SPR_IDX_SELECT		$32
		SRET
byte_685CD:
		NJSR				_native_sub10F
		SPR_IDX_SELECT		$38
		SUSPEND				$06
		SPR_IDX_SELECT		$39
		SUSPEND				$06
		SPR_IDX_SELECT		$3A
		SUSPEND				$06
		TARGET_DIR_SET		$1E
byte_685DE:
		SJSR				byte_685AE
		NJSR				_native_get_obj_y_delta
		SBEQ				byte_685DE
		OBJ_SET_X_DELTA		$00
		SRET
byte_685EA:
		NJSR				_native_sub000
		NJSR				_native_get_obj_y_delta
		SBMI				byte_685F5
		APU_LOAD			$6B
byte_685F5:
		SYNC
		NJSR				_native_get_obj_y_delta
		SBEQ				byte_68613
		NJSR				_obj_move_hor_animate
		NJSR				_native_sub104
		SBCC				byte_6860A
		OBJ_SET_Y_DELTA		$CF
		SJMP				byte_68638
byte_6860A:
		NJSR				_native_sub118
		SBCS				byte_68636
		SJMP				byte_68638
byte_68613:
		NJSR				_obj_move_hor_animate
		NJSR				_native_sub104
		NJSR				_native_sub109
		NJSR				_native_get_obj_y_delta
		SBPL				byte_6862D
		NJSR				_native_sub10B
		SBCS				byte_68638
		OBJ_SET_Y_DELTA		$00
		SJMP				byte_68638
byte_6862D:
		NJSR				_obj_vert_animate
		NJSR				_native_sub10A
		SBCC				byte_68638
byte_68636:
		OBJ_SET_Y_DELTA		$01
byte_68638:
		LOOPB				$20,byte_685F5
		SRET

; =============== S U B R O U T I N E =======================================
_native_sub000:
		LDA		_scr_vars19,X
		STA		_scr_loopsB,X
		RTS

; =============== O B J E C T   S C R I P T =================================
_obj_scr2D_destr:
		SPR_IDX_SELECT		$3B
		NJSR				_native_get_obj_hp
		SBNE				byte_68087
		OBJ_SET_SIZE		$05,$18
		SJSR				_script_sub_680E7
		OBJ_SET_X_DELTA		$00
		NJSR				_scr_param_4_clear
byte_68657:
		SPR_IDX_SELECT		$3B
		SJSR				byte_6867F
		SPR_IDX_SELECT		$3C
		SJSR				byte_6867F
		LOOPB				$14,byte_68657
		NJSR				_scr_param_10_set
byte_68668:
		SPR_IDX_SELECT		$3B
		SJSR				byte_6867F
		SPR_IDX_SELECT		$3C
		SJSR				byte_6867F
		LOOPB				$05,byte_68668
		NJSR				_scr_param_10_clear
		NJSR				_players_animB_sub0129_sub06_A
		SJMP				_obj_scr2D
byte_6867F:
		SYNC
		NJSR				_native_get_obj_var0D
		SBPL				byte_68694
		NJSR				_native_sub118
		SBCC				byte_6868F
		SJSR				_script_sub_68044
byte_6868F:
		LOOPA				$0C,byte_6867F
		SRET
byte_68694:
		SPR_IDX_SELECT		$5C
		SJSR				_script_sub_68102
		VAR_1C_SET			$02
		OBJ_SET_X_DELTA		$C0
		NJSR				_native_sub11B
		NJSR				_native_sub11C
		NJSR				_native_sub11D
		SJMP				byte_68092

; =============== O B J E C T   S C R I P T =================================
_obj_scr2E:
		SJSR				_script202
byte_686AC:
		NJMP				_native_sub11E
		SBEQ				byte_686AC
		NJSR				_native_cmp40_obj_x_lo_pos
		SBCC				byte_686AC
		NJSR				_native_cmpC0_obj_x_lo_pos
		SBCS				byte_686AC
		SRUN				$06,_script103
		SUSPEND				$3D
		SJMP				byte_686AC

; =============== S C R I P T ===============================================
_script103:
		SUSPEND				$1E
		DESTR_PC_SET		byte_68087
		SPR_LIB_SELECT		$09
		OBJ_SET_HP			$01
		VAR_1C_SET			$01
		PARAM_80_CLEAR
		OBJ_SET_SIZE		$08,$14
		OBJ_SET_X_DELTA		$10
		OBJ_SET_X_POS		$80,$00
		NJSR				_native_sub001
		NJSR				_native_sub121
		NJSR				_native_sub110
		NJSR				_native_sub10F
byte_686E7:
		SPR_IDX_SELECT		$00
		SJSR				byte_6870C
		SPR_IDX_SELECT		$01
		SJSR				byte_6870C
		SPR_IDX_SELECT		$02
		SJSR				byte_6870C
		LOOPA				$03,byte_686E7
		SPR_IDX_SELECT		$03
		SJSR				byte_6870C
		SPR_IDX_SELECT		$04
		SJSR				byte_6870C
		SPR_IDX_SELECT		$05
		SJSR				byte_6870C
		SJMP				byte_686E7
byte_6870C:
		NJMP				_native_sub122
		LOOPA				$04,byte_6870C
		SRET

; =============== S U B R O U T I N E =======================================
_native_sub001:
		LDY		byte_AB
		LDA		_obj_flips,Y
		AND		#$40
		ORA		_obj_flips,X
		STA		_obj_flips,X
		RTS

; =============== O B J E C T   S C R I P T =================================
_obj_scr2F:
		NJMP				_native_sub11E
		SBNE				byte_68729
		KILL
byte_68729:
		DESTR_PC_SET		byte_68087
		SPR_LIB_SELECT		$09
		SPR_IDX_SELECT		$00
		OBJ_SET_HP			$01
		VAR_1C_SET			$01
		OBJ_SET_SIZE		$08,$14
		SJSR				_script201
		NJSR				_native_sub10E
		TARGET_DIR_SET		$20
byte_6873F:
		SPR_IDX_SELECT		$00
		SJSR				byte_68751
		SPR_IDX_SELECT		$01
		SJSR				byte_68751
		SPR_IDX_SELECT		$02
		SJSR				byte_68751
		SJMP				byte_6873F
byte_68751:
		NJSR				_native_sub123
		NJSR				_native_sub124
		NJSR				_native_sub125
		SBEQ				byte_68763
		NJSR				_native_sub126
		SJMP				byte_68766
byte_68763:
		NJSR				_native_sub127
byte_68766:
		NJSR				_obj_vert_animate
		JMP_OBJ_ANIMATE
		NJSR				_native_sub128
		SBCC				byte_68773
		BREAK				byte_68778
byte_68773:
		LOOPB				$04,byte_68751
		SRET
byte_68778:
		TARGET_LOCK			$18
		NJSR				_native_sub10E
		NJSR				_native_sub111
		LOOPA_RESET
byte_68781:
		SPR_IDX_SELECT		$00
		SJSR				byte_687A2
		SPR_IDX_SELECT		$01
		SJSR				byte_687A2
		SPR_IDX_SELECT		$02
		SJSR				byte_687A2
		SPR_IDX_SELECT		$03
		SJSR				byte_687A2
		SPR_IDX_SELECT		$04
		SJSR				byte_687A2
		SPR_IDX_SELECT		$05
		SJSR				byte_687A2
		SJMP				byte_68781
byte_687A2:
		SYNC
		TARGET_DIR_SET		$FF
		TARGET_FOLLOW
		LOOPA				$04,byte_687A2
		SRET

; =============== O B J E C T   S C R I P T =================================
_obj_scr2C:
		DESTR_PC_SET		byte_68087
		SPR_LIB_SELECT		$07
		SPR_IDX_SELECT		$4D
		OBJ_SET_HP			$02
		VAR_1C_SET			$01
		OBJ_SET_SIZE		$0C,$20
		SJSR				_script201
		OBJ_SET_Y_DELTA		$10
byte_687BE:
		APU_LOAD			$68
byte_687C0:
		NJMP				_obj_vert_animate
		LOOPA				$08,byte_687C0
		LOOPB				$04,byte_687BE
		NJSR				_native_sub129
		NJSR				_native_sub12A
		SSWITCH				_tmp_ptrE+1
		SCASE				byte_687BE
		SCASE				byte_687DA
		SCASE				byte_687DF
byte_687DA:
		SUSPEND				$78
		SJMP				byte_687BE
byte_687DF:
		SPR_IDX_SELECT		$4E
		SUSPEND				$10
		SPR_IDX_SELECT		$4F
		SRUN				$07,_script104
		SUSPEND				$10
		SPR_IDX_SELECT		$4E
		SUSPEND				$10
		SPR_IDX_SELECT		$4F
		SRUN				$07,_script105
		SUSPEND				$10
		SPR_IDX_SELECT		$4D
		SUSPEND				$10
		SJMP				byte_687BE

; =============== S C R I P T ===============================================
_script104:
		OBJ_SET_X_DELTA		$18
		SJMP				byte_68805

; =============== S C R I P T ===============================================
_script105:
		OBJ_SET_X_DELTA		$0C
byte_68805:
		OBJ_MOVE_X_POS		$1C
		OBJ_MOVE_Y_POS		$F8
		NJSR				_native_sub12B
		SPR_LIB_SELECT		$07
		OBJ_SET_Y_DELTA		$00
		PARAM_80_CLEAR
		OBJ_SET_HP			$01
		VAR_1C_SET			$01
		OBJ_SET_SIZE		$06,$08
byte_68818:
		SPR_IDX_SELECT		$50
byte_6881A:
		JMP_OBJ_ANIMATE
		OBJ_INC_Y_DELTA
		OBJ_INC_Y_DELTA
		LOOPA				$08,byte_6881A
		SPR_IDX_SELECT		$51
byte_68823:
		JMP_OBJ_ANIMATE
		OBJ_INC_Y_DELTA
		OBJ_INC_Y_DELTA
		LOOPA				$08,byte_68823
		SJMP				byte_68818

; =============== O B J E C T   S C R I P T =================================
_obj_scr30:
		DESTR_PC_SET		byte_688AC
		SPR_LIB_SELECT		$07
		SPR_IDX_SELECT		$53
		OBJ_SET_HP			$02
		VAR_1C_SET			$01
		OBJ_SET_SIZE		$0A,$20
		SJSR				_script201
		NJSR				_native_sub10E
byte_68841:
		OBJ_SET_X_DELTA		$18
		SPR_IDX_SELECT		$52
		SJSR				byte_68867
		OBJ_SET_X_DELTA		$10
		SPR_IDX_SELECT		$53
		SJSR				byte_68867
		OBJ_SET_X_DELTA		$E8
		SPR_IDX_SELECT		$54
		SJSR				byte_68867
		OBJ_SET_X_DELTA		$F0
		SPR_IDX_SELECT		$53
		SJSR				byte_68867
byte_6885D:
		SPR_IDX_SELECT		$53
		SUSPEND				$1E
		NJSR				_native_sub110
		SJMP				byte_68841
byte_68867:
		LOOPA_RESET
		APU_LOAD			$40
		NJSR				_native_sub10F
byte_6886D:
		SYNC
		NJSR				_obj_move_hor_animate
		NJSR				_native_sub104
		SBCC				byte_6887A
		BREAK				byte_6885D
byte_6887A:
		NJSR				_native_sub118
		SBCS				_script_sub_68036
		LOOPA				$0E,byte_6886D
		NJSR				_native_sub116
		SBCS				byte_6888B
		SRET
byte_6888B:
		SPR_IDX_SELECT		$55
		OBJ_SET_X_DELTA		$30
		NJSR				_native_sub10E
		NJSR				_native_sub10F
byte_68895:
		SYNC
		NJSR				_obj_move_hor_animate
		NJSR				_native_sub104
		SBCS				byte_688A9
		NJSR				_native_sub118
		SBCS				_script_sub_68036
		LOOPA				$20,byte_68895
byte_688A9:
		BREAK				byte_68841
byte_688AC:
		SPR_IDX_SELECT		$56
		NJSR				_native_get_obj_hp
		SBNE				byte_68087
		SJSR				_script_sub_6809D
		SJMP				_obj_scr30

; =============== O B J E C T   S C R I P T =================================
_obj_scr31:
		DESTR_PC_SET		byte_68087
		SPR_LIB_SELECT		$07
		SPR_IDX_SELECT		$57
		OBJ_SET_SIZE		$0C,$18
		OBJ_SET_HP			$01
		VAR_1C_SET			$01
		SJSR				_script201
		NJSR				_native_sub10E
byte_688CE:
		OBJ_SET_X_DELTA		$E0
		OBJ_SET_Y_DELTA		$00
		NJSR				_native_sub10F
		APU_LOAD			$41
		SPR_IDX_SELECT		$57
byte_688D9:
		SJSR				byte_688F8
		NJSR				_native_sub116
		SBCS				byte_6890C
		LOOPA				$08,byte_688D9
		SPR_IDX_SELECT		$58
byte_688E8:
		SJSR				byte_688F8
		NJSR				_native_sub116
		SBCS				byte_6890C
		LOOPA				$08,byte_688E8
		SJMP				byte_688CE
byte_688F8:
		SYNC
		NJSR				_obj_move_hor_animate
		NJSR				_native_sub104
		SBCC				byte_68905
		NJSR				_native_sub110
byte_68905:
		NJSR				_native_sub118
		SBCS				_script_sub_68036
		SRET
byte_6890C:
		OBJ_SET_Y_DELTA		$C0
		SJSR				_script_sub_68036
byte_68911:
		NJSR				_obj_move_hor_animate
		NJSR				_native_sub104
		NJSR				_native_sub12C
		NJMP				_native_get_obj_x_delta
		SBEQ				byte_68911
		SUSPEND				$0A
		NJSR				_native_sub110
		OBJ_SET_X_DELTA		$E0
		OBJ_SET_Y_DELTA		$00
		NJSR				_native_sub10F
byte_6892C:
		APU_LOAD			$41
		SPR_IDX_SELECT		$57
byte_68930:
		SJSR				byte_688F8
		LOOPA				$08,byte_68930
		SPR_IDX_SELECT		$58
byte_68939:
		SJSR				byte_688F8
		LOOPA				$08,byte_68939
		SJMP				byte_6892C

; =============== O B J E C T   S C R I P T =================================
_obj_scr32:
		SUSPEND				$B4
		SRUN				$07,_script106
		SJMP				_obj_scr32

; =============== S C R I P T ===============================================
_script106:
		NJSR				_native_sub12B
		OBJ_MOVE_X_POS		$08
		OBJ_MOVE_Y_POS		$12
		SPR_LIB_SELECT		$07
		NJSR				_scr_param_4_set
		PARAM_80_CLEAR
		SPR_IDX_SELECT		$4B
		SUSPEND				$14
		SPR_IDX_SELECT		$69
		SUSPEND				$14
		NJSR				_scr_param_4_clear
		OBJ_SET_SIZE		$05,$10
		OBJ_SET_HP			$01
		VAR_1C_SET			$01
		SPR_IDX_SELECT		$59
		SUSPEND				$3C
		APU_LOAD			$4E
		SJMP				byte_68096

; =============== O B J E C T   S C R I P T =================================
_obj_scr33:
		DESTR_PC_SET		byte_689C0
		NJSR				_scr_param_4_set
		SPR_LIB_SELECT		$07
		OBJ_SET_HP			$01
		VAR_1C_SET			$01
		OBJ_SET_SIZE		$08,$14
byte_68983:
		SYNC
		NJSR				_native_sub128
		SBCC				byte_68983
		NJSR				_native_sub10E
		PARAM_80_CLEAR
		SPR_IDX_SELECT		$64
		SUSPEND				$08
		NJSR				_scr_param_4_clear
		SPR_IDX_SELECT		$65
		SUSPEND				$08
byte_68999:
		SRUN				$07,_script107
		SPR_IDX_SELECT		$66
		SUSPEND				$10
		APU_LOAD			$50
		SRUN				$07,_script108
		SPR_IDX_SELECT		$67
		SUSPEND				$10
		LOOPA				$02,byte_68999
		SPR_IDX_SELECT		$65
		SUSPEND				$08
		NJSR				_scr_param_4_set
		SPR_IDX_SELECT		$64
		SUSPEND				$08
		PARAM_80_SET
		SUSPEND				$5A
		SJMP				byte_68983
byte_689C0:
		SPR_IDX_SELECT		$40
		SJMP				byte_68087

; =============== S C R I P T ===============================================
_script107:
		OBJ_MOVE_Y_POS		$F2
		NJSR				_native_sub119
		OBJ_SET_HP			$01
		VAR_1C_SET			$01
		OBJ_SET_SIZE		$08,$0A
		SUSPEND				$10
		KILL

; =============== S C R I P T ===============================================
_script108:
		OBJ_SET_HP			$01
		VAR_1C_SET			$01
		OBJ_SET_SIZE		$06,$0F
		SPR_LIB_SELECT		$07
		SPR_IDX_SELECT		$68
		OBJ_SET_X_DELTA		$10
		OBJ_SET_Y_DELTA		$E0
		NJSR				_native_sub12E
		PARAM_80_CLEAR
		FLIP_40_CLEAR
byte_689E8:
		SJSR				byte_689FB
		FLIP_80_SET
		SJSR				byte_689FB
		FLIP_40_SET
		SJSR				byte_689FB
		FLIP_80_CLEAR
		SJSR				byte_689FB
		FLIP_40_CLEAR
		SJMP				byte_689E8
byte_689FB:
		JMP_OBJ_ANIMATE
		NJSR				_native_sub109
		LOOPA				$04,byte_689FB
		SRET

; =============== O B J E C T   S C R I P T =================================
_obj_scr34:
		DESTR_PC_SET		byte_68087
		SPR_LIB_SELECT		$07
		SPR_IDX_SELECT		$5E
		OBJ_SET_SIZE		$0C,$18
		OBJ_SET_HP			$01
		VAR_1C_SET			$01
		SJSR				_script201
		NJSR				_native_sub10E
		OBJ_SET_X_DELTA		$E8
		NJSR				_native_sub10F
byte_68A1D:
		APU_LOAD			$3E
byte_68A1F:
		SPR_IDX_SELECT		$5E
		SJSR				byte_68A69
		SPR_IDX_SELECT		$5F
		SJSR				byte_68A69
		SPR_IDX_SELECT		$5E
		SJSR				byte_68A69
		SPR_IDX_SELECT		$5F
		SJSR				byte_68A69
		LOOPB				$02,byte_68A1F
		NJSR				_native_sub110
		SJMP				byte_68A1D
byte_68A3D:
		SPR_IDX_SELECT		$60
		SUSPEND				$08
		SPR_IDX_SELECT		$63
		SUSPEND				$08
		LOOPB				$04,byte_68A3D
		OBJ_SET_X_DELTA		$20
		NJSR				_native_sub10F
byte_68A4E:
		SPR_IDX_SELECT		$62
		SJSR				byte_68A77
		APU_LOAD			$68
		SPR_IDX_SELECT		$63
		SJSR				byte_68A77
		SPR_IDX_SELECT		$41
		SJSR				byte_68A77
		APU_LOAD			$68
		SPR_IDX_SELECT		$42
		SJSR				byte_68A77
		SJMP				byte_68A4E
byte_68A69:
		NJSR				_native_sub116
		SBCC				byte_68A77
		NJSR				_native_sub10E
		LOOPA_RESET
		LOOPB_RESET
		BREAK				byte_68A3D
byte_68A77:
		SYNC
		NJSR				_obj_move_hor_animate
		NJSR				_native_sub104
		SBCC				byte_68A86
		LOOPA_RESET
		LOOPB_RESET
		NJSR				_native_sub110
byte_68A86:
		NJSR				_native_sub118
		SBCS				_script_sub_68036
		LOOPA				$07,byte_68A77
		SRET

; =============== O B J E C T   S C R I P T =================================
_obj_scr35:
		SJSR				_script202
byte_68A94:
		NJMP				_native_sub11E
		SBEQ				byte_68A94
		SUSPEND				$1E
		SRUN				$06,_script109
		SUSPEND				$1E
		SJMP				byte_68A94

; =============== O B J E C T   S C R I P T =================================
_obj_scr36:
		SJSR				_script202
byte_68AA8:
		NJMP				_native_sub11E
		SBEQ				byte_68AA8
		SUSPEND				$1E
		SRUN				$06,_script10A
		SUSPEND				$1E
		SJMP				byte_68AA8
byte_68AB9:
		DESTR_PC_SET		byte_68087
		SPR_LIB_SELECT		$09
		OBJ_SET_HP			$01
		VAR_1C_SET			$01
		PARAM_80_CLEAR
		OBJ_SET_SIZE		$10,$20
		OBJ_SET_X_POS		$80,$00
		NJSR				_native_sub001
		NJSR				_native_sub121
		NJSR				_native_sub110
		NJSR				_native_sub10F
		SRET

; =============== S C R I P T ===============================================
_script109:
		OBJ_SET_X_DELTA		$18
		SJSR				byte_68AB9
byte_68ADB:
		SPR_IDX_SELECT		$06
		SJSR				byte_68B01
		APU_LOAD			$39
		SPR_IDX_SELECT		$07
		SJSR				byte_68B0D
		SPR_IDX_SELECT		$08
		SJSR				byte_68B0D
		NJSR				_native_sub128
		SBCC				byte_68ADB
		SRUN				$06,_script10B
		SBCC				byte_68ADB
		OBJ_SET_X_DELTA		$20
		NJSR				_native_sub10F
		SJMP				byte_68B1A
byte_68B01:
		OBJ_SET_Y_DELTA		$DF
byte_68B03:
		OBJ_INC_Y_DELTA
		OBJ_INC_Y_DELTA
		JMP_OBJ_ANIMATE
		LOOPB				$20,byte_68B03
		OBJ_SET_Y_DELTA		$21
		SRET
byte_68B0D:
		OBJ_DEC_Y_DELTA
		OBJ_DEC_Y_DELTA
		JMP_OBJ_ANIMATE
		LOOPB				$10,byte_68B0D
		SRET

; =============== S C R I P T ===============================================
_script10A:
		OBJ_SET_X_DELTA		$20
		SJSR				byte_68AB9
byte_68B1A:
		SPR_IDX_SELECT		$09
		SJSR				byte_68B2E
		APU_LOAD			$39
		SPR_IDX_SELECT		$0A
		SJSR				byte_68B39
		SPR_IDX_SELECT		$0B
		SJSR				byte_68B39
		SJMP				byte_68B1A
byte_68B2E:
		OBJ_SET_Y_DELTA		$EF
byte_68B30:
		OBJ_INC_Y_DELTA
		JMP_OBJ_ANIMATE
		LOOPB				$20,byte_68B30
		OBJ_SET_Y_DELTA		$11
		SRET
byte_68B39:
		OBJ_DEC_Y_DELTA
		JMP_OBJ_ANIMATE
		LOOPB				$10,byte_68B39
		SRET

; =============== S C R I P T ===============================================
_script10B:
		DESTR_PC_SET		byte_68087
		OBJ_MOVE_Y_POS		$10
		OBJ_SET_HP			$01
		VAR_1C_SET			$01
		OBJ_SET_SIZE		$06,$0C
		SPR_LIB_SELECT		$07
		SPR_IDX_SELECT		$6A
		OBJ_SET_Y_DELTA		$08
		PARAM_80_CLEAR
byte_68B53:
		SYNC
		NJSR				_native_sub109
		NJSR				_native_sub10B
		SBCS				byte_68B53
		OBJ_SET_Y_DELTA		$00
		APU_LOAD			$3B
		SPR_IDX_SELECT		$6B
		SUSPEND				$08
		SPR_IDX_SELECT		$6C
		SUSPEND				$08
		SPR_IDX_SELECT		$6D
		SUSPEND				$08
		SPR_IDX_SELECT		$6F
		SUSPEND				$08
		OBJ_SET_X_DELTA		$10
		NJMP				_native_sub10E
		NJMP				_native_sub10F
byte_68B79:
		SPR_IDX_SELECT		$6E
		SJSR				byte_68B90
		SPR_IDX_SELECT		$6F
		SJSR				byte_68B90
		SPR_IDX_SELECT		$70
		SJSR				byte_68B90
		SPR_IDX_SELECT		$6F
		SJSR				byte_68B90
		SJMP				byte_68B79
byte_68B90:
		SYNC
		NJSR				_obj_move_hor_animate
		NJSR				_native_sub104
		SBCS				byte_68BA5
		NJSR				_native_sub118
		SBCS				byte_68BA5
		LOOPA				$08,byte_68B90
		SRET
byte_68BA5:
		LOOPA_RESET
		SPR_IDX_SELECT		$6F
		OBJ_SET_Y_DELTA		$C0
		SJSR				_script_sub_68036
		BREAK				byte_68B79

; =============== O B J E C T   S C R I P T =================================
_obj_scr37:
		DESTR_PC_SET		byte_68087
		SPR_LIB_SELECT		$07
		SPR_IDX_SELECT		$43
		OBJ_SET_SIZE		$0C,$18
		OBJ_SET_HP			$01
		VAR_1C_SET			$01
		SJSR				_script201
		NJSR				_native_sub10E
		OBJ_SET_X_DELTA		$10
		NJSR				_native_sub10F
byte_68BC9:
		SPR_IDX_SELECT		$44
		SJSR				byte_68C0D
		SPR_IDX_SELECT		$45
		SJSR				byte_68C0D
		SPR_IDX_SELECT		$46
		SJSR				byte_68C0D
		SPR_IDX_SELECT		$45
		SJSR				byte_68C0D
		SJMP				byte_68BC9
byte_68BE0:
		SPR_IDX_SELECT		$47
		SUSPEND				$05
		SPR_IDX_SELECT		$48
		SUSPEND				$05
		LOOPA				$04,byte_68BE0
		APU_LOAD			$6D
		SRUN				$07,_script10C
		SPR_IDX_SELECT		$49
		SUSPEND				$2A
byte_68BF6:
		SPR_IDX_SELECT		$44
		SJSR				byte_68C22
		SPR_IDX_SELECT		$45
		SJSR				byte_68C22
		SPR_IDX_SELECT		$46
		SJSR				byte_68C22
		SPR_IDX_SELECT		$45
		SJSR				byte_68C22
		SJMP				byte_68BF6
byte_68C0D:
		NJSR				_native_sub115
		SBCC				byte_68C22
		NJSR				_native_sub112
		SBCC				byte_68C22
		NJSR				_native_sub10E
		NJSR				_native_sub10F
		BREAK				byte_68BE0
byte_68C22:
		SYNC
		NJSR				_obj_move_hor_animate
		NJSR				_native_sub104
		SBCS				byte_68C37
		NJSR				_native_sub118
		SBCS				byte_68C37
		LOOPA				$0B,byte_68C22
		SRET
byte_68C37:
		LOOPA_RESET
		SPR_IDX_SELECT		$45
		OBJ_SET_Y_DELTA		$C0
		SJMP				_script_sub_68036

; =============== S C R I P T ===============================================
_script10C:
		OBJ_SET_HP			$01
		VAR_1C_SET			$01
		OBJ_SET_SIZE		$04,$08
		SPR_LIB_SELECT		$07
		SPR_IDX_SELECT		$4A
		OBJ_MOVE_Y_POS		$DF
		OBJ_SET_X_DELTA		$20
		OBJ_SET_Y_DELTA		$E0
		NJSR				_native_sub12E
		PARAM_80_CLEAR
		SJMP				byte_68096

; =============== O B J E C T   S C R I P T =================================
_obj_scr3C:
		SJSR				byte_68CCC
byte_68C5A:
		NJMP				_native_cmp20_obj_x_lo_pos
		SBCC				byte_68C5A
		NJSR				_native_cmpE0_obj_x_lo_pos
		SBCS				byte_68C5A
		OBJ_SET_Y_DELTA		$20
byte_68C68:
		SJSR				byte_68C8D
		LOOPA				$05,byte_68C68
		OBJ_SET_Y_DELTA		$00
byte_68C71:
		SJSR				byte_68C8D
		LOOPA				$04,byte_68C71
		OBJ_SET_X_DELTA		$20
		OBJ_SET_Y_DELTA		$F0
		NJSR				_native_sub10F
byte_68C7F:
		SJSR				byte_68C8D
		LOOPA				$02,byte_68C7F
		SRUN				$08,_script10D
		SJMP				byte_68C7F
byte_68C8D:
		SPR_IDX_SELECT		$71
		SJSR				_script_animate10
		SPR_IDX_SELECT		$72
		SJMP				_script_animate10

; =============== O B J E C T   S C R I P T =================================
_obj_scr3D:
		SJSR				byte_68CCC
		TARGET_DIR_SET		$20
byte_68C9C:
		SPR_IDX_SELECT		$71
		SJSR				byte_68CB1
		SPR_IDX_SELECT		$72
		SJSR				byte_68CB1
		LOOPA				$06,byte_68C9C
		SRUN				$08,_script10D
		SJMP				byte_68C9C
byte_68CB1:
		NJSR				_native_sub123
		NJSR				_native_sub124
		NJSR				_native_sub125
		SBEQ				byte_68CC3
		NJSR				_native_sub126
		SJMP				byte_68CC6
byte_68CC3:
		NJSR				_native_sub127
byte_68CC6:
		JMP_OBJ_ANIMATE
		LOOPB				$08,byte_68CB1
		SRET
byte_68CCC:
		DESTR_PC_SET		byte_68087
		SPR_LIB_SELECT		$07
		SPR_IDX_SELECT		$71
		OBJ_SET_HP			$01
		VAR_1C_SET			$01
		OBJ_SET_SIZE		$0A,$14
		SJSR				_script201
		NJSR				_native_sub10E
		SRET

; =============== S C R I P T ===============================================
_script10D:
		NJSR				_native_sub12B
		APU_LOAD			$29
		OBJ_MOVE_Y_POS		$08
		OBJ_SET_Y_DELTA		$10
		SPR_LIB_SELECT		$07
		PARAM_80_CLEAR
		OBJ_SET_HP			$01
		VAR_1C_SET			$02
		OBJ_SET_SIZE		$04,$08
byte_68CF4:
		SPR_IDX_SELECT		$73
		SJSR				_script_animate10
		SPR_IDX_SELECT		$7B
		SJSR				_script_animate10
		SJMP				byte_68CF4

; =============== O B J E C T   S C R I P T =================================
_obj_scr39:
		SPR_LIB_SELECT		$07
		SPR_IDX_SELECT		$77
		SJSR				_script201
		NJSR				_native_sub10E
byte_68D0B:
		DESTR_PC_SET		byte_68087
		OBJ_SET_SIZE		$0A,$0C
		OBJ_SET_HP			$01
		VAR_1C_SET			$01
		OBJ_SET_X_DELTA		$08
		NJSR				_native_sub10F
byte_68D1A:
		LOOPA_RESET
		SPR_IDX_SELECT		$77
		SJSR				byte_68D35
		SPR_IDX_SELECT		$78
		SJSR				byte_68D35
		SPR_IDX_SELECT		$77
		SJSR				byte_68D35
		SPR_IDX_SELECT		$79
		SJSR				byte_68D35
byte_68D2F:
		NJSR				_native_sub110
		SJMP				byte_68D1A
byte_68D35:
		SYNC
		NJSR				_native_sub131
		SBCC				byte_68D3F
		BREAK				byte_68D56
byte_68D3F:
		NJSR				_obj_move_hor_animate
		NJSR				_native_sub104
		SBCC				byte_68D4B
		BREAK				byte_68D2F
byte_68D4B:
		NJSR				_native_sub118
		SBCS				_script_sub_68036
		LOOPA				$0E,byte_68D35
		SRET
byte_68D56:
		DESTR_PC_SET		byte_68D6B
		OBJ_SET_SIZE		$0A,$0E
		SPR_IDX_SELECT		$7A
		NJSR				_native_sub132
byte_68D61:
		OBJ_SET_HP			$02
		SYNC
		LOOPB				$1E,byte_68D61
		SJMP				byte_68D0B
byte_68D6B:
		NJSR				_native_get_obj_hp
		SBNE				byte_68087
		NJSR				_scr_param_4_clear
		SJMP				byte_68D61

; =============== O B J E C T   S C R I P T =================================
_obj_scr3A:
		SJSR				_script202
byte_68D7A:
		SYNC
		NJSR				_native_cmp08_obj_x_lo_pos
		SBCS				byte_68D7A
		DESTR_PC_SET		byte_68087
		SPR_LIB_SELECT		$07
		SPR_IDX_SELECT		$75
		OBJ_SET_SIZE		$08,$20
		OBJ_SET_HP			$01
		VAR_1C_SET			$01
		PARAM_80_CLEAR
		OBJ_SET_X_DELTA		$30
		NJSR				_native_sub10E
		NJSR				_native_sub10F
byte_68D98:
		SPR_IDX_SELECT		$74
		SJSR				byte_68DA5
		SPR_IDX_SELECT		$76
		SJSR				byte_68DA5
		SJMP				byte_68D98
byte_68DA5:
		OBJ_SET_Y_DELTA		$E0
byte_68DA7:
		SYNC
		NJSR				_obj_move_hor_animate
		NJSR				_native_sub104
		SBCC				byte_68DB4
		NJSR				_native_sub110
byte_68DB4:
		SJSR				_script_sub_68044
		SBCS				byte_68DA7
		SPR_IDX_SELECT		$75
		SUSPEND				$04
		SRET

; =============== O B J E C T   S C R I P T =================================
_obj_scr38:
		DESTR_PC_SET		byte_68E18
		SPR_LIB_SELECT		$05
		SPR_IDX_SELECT		$3A
		SJSR				_script201
		NJSR				_native_sub10E
		OBJ_SET_SIZE		$06,$1C
		VAR_1C_SET			$01
byte_68DD1:
		OBJ_SET_HP			$01
		SPR_IDX_SELECT		$3A
		SUSPEND				$40
		SPR_IDX_SELECT		$3B
		SUSPEND				$10
byte_68DDB:
		LOOPA_RESET
		LOOPB_RESET
		NJSR				_scr_param_4_clear
		OBJ_SET_HP			$02
		SJSR				byte_68DF9
		SJSR				byte_68DF9
		SRUN				$07,_script10E
		SRUN				$07,_script10F
		SJSR				byte_68DF9
		SJSR				byte_68DF9
		SJMP				byte_68DD1
byte_68DF9:
		APU_LOAD			$6F
byte_68DFB:
		SPR_IDX_SELECT		$3C
		SUSPEND				$02
		SPR_IDX_SELECT		$3D
		SUSPEND				$02
		LOOPA				$02,byte_68DFB
byte_68E07:
		SPR_IDX_SELECT		$3E
		SUSPEND				$02
		SPR_IDX_SELECT		$3F
		SUSPEND				$02
		LOOPA				$02,byte_68E07
		LOOPB				$02,byte_68DFB
		SRET
byte_68E18:
		NJSR				_native_get_obj_hp
		SBEQ				byte_68DDB
		SPR_IDX_SELECT		$3A
		SJMP				byte_68087

; =============== S C R I P T ===============================================
_script10F:
		OBJ_SET_X_DELTA		$30
		OBJ_MOVE_X_POS		$08
		FLIP_40_CLEAR
		SJMP				byte_68E30

; =============== S C R I P T ===============================================
_script10E:
		OBJ_SET_X_DELTA		$D0
		OBJ_MOVE_X_POS		$F8
		FLIP_40_SET
byte_68E30:
		NJSR				_native_sub12B
		SPR_LIB_SELECT		$05
		OBJ_SET_SIZE		$04,$08
		OBJ_SET_HP			$01
		VAR_1C_SET			$01
		PARAM_80_CLEAR
byte_68E3D:
		SPR_IDX_SELECT		$05
		SJSR				byte_68E4A
		SPR_IDX_SELECT		$40
		SJSR				byte_68E4A
		SJMP				byte_68E3D
byte_68E4A:
		JMP_OBJ_ANIMATE
		NJSR				_native_sub104
		SBCS				byte_68E5C
		NJSR				_native_sub118
		SBCS				byte_68E5C
		LOOPA				$06,byte_68E4A
		SRET
byte_68E5C:
		KILL

; =============== O B J E C T   S C R I P T =================================
_obj_scr3F:
		STORE				$1E,_apu_load_idx_req
		SRUN				$01,_script110
		DESTR_PC_SET		byte_B6AF1
		NJSR				_native_sub134
		OBJ_MOVE_X_POS		$0A
		SPR_LIB_SELECT		$08
		SUSPEND				$80
		OBJ_SET_SIZE		$0A,$32
		OBJ_SET_HP			$06
		VAR_1C_SET			$01
		PARAM_80_CLEAR
		OBJ_SET_X_DELTA		$10
		NJSR				_native_sub10E
		NJSR				_native_sub10F
byte_68E81:
		SPR_IDX_SELECT		$18
		SJSR				_script206
		SPR_IDX_SELECT		$20
		SJSR				_script206
		LOOPA				$02,byte_68E81
		SJSR				byte_68F10
byte_68E92:
		NJSR				_native_sub12A
		SSWITCH				_tmp_ptrE+1
		SCASE				byte_68E9E
		SCASE				byte_68EB4
		SCASE				byte_68EB4
byte_68E9E:
		OBJ_SET_X_DELTA		$00
		OBJ_SET_Y_DELTA		$00
		NJSR				_native_sub10E
		NJSR				_native_sub113
		SBMI				byte_68EAE
		SJSR				byte_68F2E
byte_68EAE:
		SJSR				byte_68F2E
		SJSR				byte_68F10
byte_68EB4:
		OBJ_SET_X_DELTA		$20
		NJSR				_native_sub10F
		NJSR				_native_sub113
		SBMI				byte_68EC2
		SJSR				byte_68EC8
byte_68EC2:
		SJSR				byte_68EC8
		SJMP				byte_68E92
byte_68EC8:
		SPR_IDX_SELECT		$18
		SJSR				byte_68ECF
		SPR_IDX_SELECT		$20
byte_68ECF:
		SYNC
		SJSR				_script20A
		NJSR				_obj_move_hor_animate
		NJSR				_native_sub135
		SBCS				byte_68EDF
		NJSR				_native_sub110
byte_68EDF:
		NJSR				_native_sub118
		SBCS				byte_68EEA
		LOOPB				$0A,byte_68ECF
		SRET
byte_68EEA:
		NJSR				_scr_reset_slot
		NJSR				_native_cmp40_obj_y_lo_pos
		SBNE				byte_68F01
		NJSR				_native_cmpC0_obj_y_lo_pos
		SBNE				byte_68EFF
		NJSR				_native_sub113
		SBMI				byte_68F01
byte_68EFF:
		OBJ_SET_Y_DELTA		$AE
byte_68F01:
		SPR_IDX_SELECT		$23
		OBJ_SET_X_DELTA		$00
		SJSR				_script20B
		SPR_IDX_SELECT		$1E
		SJSR				_script205
		SJMP				byte_68E92
byte_68F10:
		OBJ_SET_X_DELTA		$00
		OBJ_SET_Y_DELTA		$00
		SPR_IDX_SELECT		$15
		SJSR				_script205
		SPR_IDX_SELECT		$16
		SJSR				_script205
		SPR_IDX_SELECT		$17
		SJSR				_script205
		SJSR				_script205
		SPR_IDX_SELECT		$16
		SJSR				_script205
		SPR_IDX_SELECT		$15
		SRET
byte_68F2E:
		SPR_IDX_SELECT		$19
		SJSR				_script203
		SPR_IDX_SELECT		$1A
		SJSR				_script203
		SPR_IDX_SELECT		$1B
		SJSR				_script208
		SPR_IDX_SELECT		$1C
		SJSR				_script204
		SPR_IDX_SELECT		$1D
		SJSR				_script203
		APU_LOAD			$3F
		SRUN				$07,_script111
		SPR_IDX_SELECT		$1E
		SJSR				_script205
		LOOPA				$02,byte_68F2E
		SRET

; =============== S C R I P T ===============================================
_script111:
		OBJ_MOVE_Y_POS		$E4
		OBJ_SET_X_DELTA		$20
		NJSR				_native_sub12E
		SPR_LIB_SELECT		$08
		OBJ_SET_SIZE		$05,$08
		OBJ_SET_HP			$01
		VAR_1C_SET			$01
		PARAM_80_CLEAR
byte_68F68:
		SPR_IDX_SELECT		$21
		SJSR				byte_68F75
		SPR_IDX_SELECT		$22
		SJSR				byte_68F75
		SJMP				byte_68F68
byte_68F75:
		JMP_OBJ_ANIMATE
		NJSR				_native_sub109
		LOOPA				$03,byte_68F75
		SRET

; =============== S C R I P T ===============================================
_script110:
		SUSPEND				$F0
byte_68F80:
		NJMP				_native_sub138
		SBCC				byte_68F80
		SUSPEND				$3C
		SRUN				$03,_script112
		SJMP				_script110

; =============== S C R I P T ===============================================
_script112:
		PARAM_40_SET
		DESTR_PC_SET		_script46
		NJSR				_native_sub12A
		SSWITCH				_tmp_ptrE+1
		SCASE				byte_68F9F
		SCASE				byte_68FA5
		SCASE				byte_68FAB
byte_68F9F:
		OBJ_SET_X_POS		$18,$00
		SJMP				byte_68FB1
byte_68FA5:
		OBJ_SET_X_POS		$A8,$00
		SJMP				byte_68FB1
byte_68FAB:
		OBJ_SET_X_POS		$98,$00
		NJSR				_native_sub110
byte_68FB1:
		OBJ_SET_Y_POS		$00,$00
		SYNC
		SPR_LIB_SELECT		$03
		SPR_IDX_SELECT		$00
		OBJ_SET_SIZE		$06,$10
		NJSR				_native_sub139
		PARAM_80_CLEAR
byte_68FC0:
		OBJ_SET_HP			$01
		VAR_1C_SET			$01
		OBJ_SET_X_DELTA		$00
		OBJ_SET_Y_DELTA		$01
		NJSR				_native_sub13A
byte_68FCB:
		SYNC
		NJSR				_native_sub109
		NJSR				_native_sub10B
		SBCC				byte_68FDE
		NJSR				_native_get_obj_hp
		SBEQ				byte_68FCB
		SJMP				byte_6A669
byte_68FDE:
		NJSR				_native_sub13B
		NJSR				_native_sub110
		OBJ_SET_X_DELTA		$08
		OBJ_SET_Y_DELTA		$00
		NJSR				_native_sub10F
byte_68FEB:
		SYNC
		NJSR				_native_get_obj_var0D
		SBPL				_script46
		NJSR				_obj_move_hor_animate
		NJSR				_native_sub13C
		NJSR				_native_sub118
		SBCC				byte_68FEB
		SJMP				byte_68FC0

; =============== O B J E C T   S C R I P T =================================
_obj_scr40:
		STORE				$1E,_apu_load_idx_req
		DESTR_PC_SET		byte_B6AF1
		NJSR				_native_sub134
		OBJ_MOVE_X_POS		$0F
		SPR_LIB_SELECT		$08
		SUSPEND				$80
		PARAM_80_CLEAR
		OBJ_SET_X_DELTA		$F8
		OBJ_SET_Y_DELTA		$10
byte_69016:
		SJSR				byte_690B0
		LOOPA				$04,byte_69016
		OBJ_SET_SIZE		$0E,$20
		OBJ_SET_HP			$06
		VAR_1C_SET			$01
byte_69024:
		SJSR				byte_69039
		SJSR				byte_6905E
		SJSR				byte_69039
		SJSR				byte_69076
		SJSR				byte_69039
		SJSR				byte_69076
		SJMP				byte_69024
byte_69039:
		OBJ_SET_X_DELTA		$00
		OBJ_SET_Y_DELTA		$00
byte_6903D:
		SJSR				byte_690B0
		LOOPA				$03,byte_6903D
		SRUN				$07,_script113
		SJSR				_script209
byte_6904B:
		SJSR				byte_690B0
		LOOPA				$03,byte_6904B
		SRUN				$07,_script113
byte_69056:
		SJSR				byte_690B0
		LOOPA				$03,byte_69056
		SRET
byte_6905E:
		OBJ_SET_X_DELTA		$E0
		OBJ_SET_Y_DELTA		$19
		NJSR				_native_sub10F
byte_69065:
		SJSR				byte_690B0
		NJSR				_native_sub004
		LOOPA				$06,byte_69065
		NJSR				_native_sub110
		NJSR				_native_sub114
		SRET
byte_69076:
		OBJ_SET_X_DELTA		$E0
		OBJ_SET_Y_DELTA		$20
		NJSR				_native_sub10F
byte_6907D:
		SJSR				byte_690B0
		NJSR				_native_sub004
		LOOPA				$03,byte_6907D
		NJSR				_native_sub114
		OBJ_SET_Y_DELTA		$00
		APU_LOAD			$67
byte_6908E:
		SPR_IDX_SELECT		$0C
		SJSR				_script209
		SJSR				_script209
		SPR_IDX_SELECT		$0D
		SJSR				_script209
		SJSR				_script209
		LOOPA				$0C,byte_6908E
		NJSR				_native_sub110
		OBJ_SET_X_DELTA		$00
		OBJ_SET_Y_DELTA		$E0
		SJSR				byte_690B0
		SJSR				byte_690B0
		SRET
byte_690B0:
		APU_LOAD			$66
		NJSR				_native_sub002
		SPR_IDX_SELECT		$09
		SJSR				byte_690CF
		NJSR				_native_sub003
		SPR_IDX_SELECT		$0A
		SJSR				byte_690CF
		NJSR				_native_sub003
		SPR_IDX_SELECT		$0B
		SJSR				byte_690CF
		NJSR				_native_sub002
		SPR_IDX_SELECT		$0A
byte_690CF:
		SJSR				_script209
		NJSR				_native_sub005
		LOOPB				$04,byte_690CF
		SRET

; =============== S U B R O U T I N E =======================================
_native_sub002:
		CLC
		LDA		_obj_y_deltas,X
		ADC		#$10
		STA		_obj_y_deltas,X
		RTS

; =============== S U B R O U T I N E =======================================
_native_sub003:
		SEC
		LDA		_obj_y_deltas,X
		SBC		#$10
		STA		_obj_y_deltas,X
		RTS

; =============== S U B R O U T I N E =======================================
_native_sub004:
		SEC
		LDA		_obj_y_deltas,X
		SBC		#$0A
		STA		_obj_y_deltas,X
		RTS

; =============== S U B R O U T I N E =======================================
_native_sub005:
		LDA		_obj_x_deltas,X
		BNE		locret_6910C
		LDY		#$18
		LDA		_obj_flips,X
		AND		#$40
		BNE		loc_69108
		LDY		#$E8
loc_69108:
		STY		_players_x_shifs
		STY		_players_x_shifs+1
locret_6910C:
		RTS


; =============== S C R I P T ===============================================
_script113:
		PARAM_40_SET
		DESTR_PC_SET		byte_6915B
		SPR_LIB_SELECT		$08
		SPR_IDX_SELECT		$0E
		OBJ_SET_HP			$01
		VAR_1C_SET			$01
		OBJ_SET_SIZE		$06,$10
		PARAM_80_CLEAR
		NJMP				_native_sub006
byte_69120:
		NJSR				_native_sub109
		NJMP				_obj_vert_animate
		LOOPA				$20,byte_69120
		TARGET_LOCK			$40
		NJSR				_native_sub111
		NJSR				_native_sub13D
		SBCC				_script1FE
		SJSR				_script1FF
		OBJ_SET_X_DELTA		$18
		OBJ_SET_Y_DELTA		$00
		NJSR				_native_sub10F
byte_6913F:
		SJSR				_script_animate10
		NJSR				_native_sub007
		SBCS				byte_6913F
		NJSR				_native_sub13B
byte_6914B:
		SYNC
		NJSR				_native_get_obj_var0D
		SBPL				byte_6915B
		NJSR				_native_sub008
		SBCC				byte_6916B
		SJMP				byte_6914B
byte_6915B:
		SJSR				byte_6806C
		NJSR				_native_sub030
byte_69161:
		JMP_OBJ_ANIMATE
		NJSR				_native_sub016
		SBEQ				byte_69161
		SJMP				byte_68096
byte_6916B:
		NJSR				_native_sub13E
		OBJ_SET_X_DELTA		$10
		OBJ_SET_Y_DELTA		$E0
		NJSR				_players_animB_sub3_B_A
		SJMP				byte_68096

; =============== S U B R O U T I N E =======================================
_native_sub006:
		LDY		#$40
		LDA		_obj_flips,X
		AND		#$40
		BNE		loc_69183
		LDY		#$C0
loc_69183:
		TYA
		STA		_obj_x_lo_poss,X
		LDA		#$00
		STA		_obj_y_lo_poss,X
		RTS

; =============== S U B R O U T I N E =======================================
_native_sub007:
		LDA		_obj_x_lo_poss,X
		BPL		loc_69194
		EOR		#$FF
loc_69194:
		CMP		#$10
		JMP		_scr_flags_update

; =============== S U B R O U T I N E =======================================
_native_sub008:
		LDA		#$03
		STA		_scr_idxAs,X
		TAY
		JSR		_obj_to_obj_collision_test
		JMP		_scr_flags_update


; =============== O B J E C T   S C R I P T =================================
_obj_scr41:
		STORE				$1E,_apu_load_idx_req
		STORE				$10,byte_9D
		DESTR_PC_SET		byte_B6AF1
		NJSR				_native_sub134
		SRUN				$01,_script114
		OBJ_MOVE_X_POS		$20
		SPR_LIB_SELECT		$08
		OBJ_SET_SIZE		$08,$20
		OBJ_SET_HP			$06
		VAR_1C_SET			$01
		SUSPEND				$80
		PARAM_80_CLEAR
		OBJ_SET_X_DELTA		$E8
		SPR_IDX_SELECT		$27
		SJSR				_script208
		SPR_IDX_SELECT		$26
		SJSR				_script208
		SJSR				byte_691E3
		NJSR				_native_sub009
byte_691D7:
		NJSR				_native_sub12A
		SSWITCH				_tmp_ptrE+1
		SCASE				byte_69223
		SCASE				byte_691EA
		SCASE				byte_69223
byte_691E3:
		SPR_IDX_SELECT		$24
		OBJ_SET_X_DELTA		$00
		SJMP				_script206
byte_691EA:
		NJSR				_native_cmpC0_obj_y_lo_pos
		SBCS				byte_69229
byte_691F0:
		NJSR				_native_cmp80_obj_x_lo_pos
		SBEQ				byte_691FC
		SJSR				byte_691E3
		NJSR				_native_sub10E
byte_691FC:
		OBJ_SET_X_DELTA		$00
		OBJ_SET_Y_DELTA		$00
		SPR_IDX_SELECT		$28
		APU_LOAD			$3C
		SJSR				_script208
		APU_LOAD			$3C
		SJSR				_script208
byte_6920C:
		SPR_IDX_SELECT		$29
		APU_LOAD			$3D
		SRUN				$07,_script115
		SJSR				_script203
		SJSR				_script206
		SPR_IDX_SELECT		$24
		SJSR				_script208
		LOOPA				$02,byte_6920C
byte_69223:
		NJSR				_native_cmp80_obj_y_lo_pos
		SBCC				byte_691F0
byte_69229:
		OBJ_SET_X_DELTA		$18
		NJSR				_native_sub10F
byte_6922E:
		SYNC
		SPR_IDX_SELECT		$25
		SJSR				byte_6927B
		LOOPB				$08,byte_6922E
byte_69238:
		SYNC
		SPR_IDX_SELECT		$26
		SJSR				byte_6927B
		LOOPB				$08,byte_69238
byte_69242:
		SYNC
		SPR_IDX_SELECT		$27
		SJSR				byte_6927B
		LOOPB				$08,byte_69242
byte_6924C:
		SYNC
		SPR_IDX_SELECT		$26
		SJSR				byte_6927B
		LOOPB				$08,byte_6924C
		LOOPA				$02,byte_6922E
		OBJ_SET_X_DELTA		$00
byte_6925C:
		NJSR				_native_get_obj_y_delta
		SBNE				byte_69269
		SYNC
		SJSR				byte_6927B
		SJMP				byte_6925C
byte_69269:
		NJSR				_native_cmp80_obj_x_lo_pos
		SBNE				byte_691D7
		SJSR				byte_691E3
		NJSR				_native_sub110
		SJSR				byte_691E3
		SJMP				byte_691D7
byte_6927B:
		SJSR				_script20A
		NJSR				_obj_move_hor_animate
		NJSR				_native_get_obj_y_delta
		SBEQ				byte_69290
		NJSR				_native_sub118
		SBCS				byte_6928E
		SRET
byte_6928E:
		OBJ_SET_Y_DELTA		$B0
byte_69290:
		SPR_IDX_SELECT		$26
		NJSR				_native_sub109
		SBMI				byte_6929C
		NJSR				_obj_vert_animate
		SRET
byte_6929C:
		NJSR				_native_sub10B
		SBCS				byte_692A4
		OBJ_SET_Y_DELTA		$00
byte_692A4:
		SRET

; =============== S U B R O U T I N E =======================================
_native_sub009:
		LDA		_room_flags
		ORA		#$02
		STA		_room_flags
		RTS


; =============== S C R I P T ===============================================
_script114:
		OBJ_SET_FLIP		$08
byte_692AE:
		NJMP				_native_sub00A
		SBCC				byte_692AE
		SRUN				$09,_script116
		SJMP				byte_692AE

; =============== S U B R O U T I N E =======================================
_native_sub00A:
		LDA		_obj_global_y_shift
		BEQ		loc_692DC
		LDY		_ppu_scroll_shadow_hi
		CPY		#$D0
		BEQ		loc_692CD
		CPY		#$80
		BEQ		loc_692CD
		CPY		#$30
		BNE		loc_692DC
loc_692CD:
		LDA		#$18
		LDY		_obj_x_lo_poss,X
		BMI		loc_692D6
		LDA		#$E8
loc_692D6:
		STA		_obj_x_lo_poss,X
		JMP		_native_sub138
loc_692DC:
		SEC
		JMP		_scr_flags_update


; =============== S C R I P T ===============================================
_script116:
		PARAM_40_SET
		DESTR_PC_SET		_script46
		OBJ_SET_Y_POS		$00,$00
		SPR_LIB_SELECT		$03
		SPR_IDX_SELECT		$00
		OBJ_SET_SIZE		$06,$10
		OBJ_SET_HP			$01
		PARAM_80_CLEAR
byte_692F1:
		NJMP				_native_get_obj_var0D
		SBPL				_script46
		SJMP				byte_692F1

; =============== S C R I P T ===============================================
_script115:
		OBJ_MOVE_Y_POS		$E9
		OBJ_SET_X_DELTA		$30
		NJSR				_native_sub141
		SPR_LIB_SELECT		$08
		OBJ_SET_SIZE		$04,$06
		OBJ_SET_HP			$01
		VAR_1C_SET			$01
		PARAM_80_CLEAR
byte_6930B:
		SPR_IDX_SELECT		$2A
		SJSR				_script_animate10
		SPR_IDX_SELECT		$2B
		SJSR				_script_animate10
		SJMP				byte_6930B

; =============== O B J E C T   S C R I P T =================================
_obj_scr42:
		STORE				$0E,_apu_load_idx_req
		DESTR_PC_SET		byte_694CA
		NJSR				_native_sub134
		OBJ_SET_HP			$07
		VAR_1C_SET			$01
		STORE				$00,byte_E0
		SJSR				byte_69531
		SJMP				byte_69350
byte_69330:
		SPR_IDX_SELECT		$0F
		OBJ_SET_SIZE		$00,$00
		OBJ_SET_X_DELTA		$00
		OBJ_SET_Y_DELTA		$00
byte_69339:
		SJSR				byte_69492
		SSWITCH				byte_E0
		SCASE				byte_69343
		SCASE				byte_69339
byte_69343:
		PARAM_80_SET
		PAL_FADE_OUT		$04,$87
		SUSPEND				$1E
		PARAM_80_SET
		PAL_FADE_IN			$04,$8F
		SJSR				byte_69531
byte_69350:
		PAL_FADE_OUT		$04,$8F
		SUSPEND				$1E
		OBJ_SET_X_POS		$C8,$00
		OBJ_SET_Y_POS		$90,$00
		SPR_LIB_SELECT		$08
		SPR_IDX_SELECT		$0F
		NJSR				_native_sub00C
		CHR_BANK			$00,$1B
		PAL_FADE_IN			$04,$87
		SUSPEND				$10
		PARAM_80_CLEAR
		OBJ_SET_SIZE		$14,$30
		OBJ_SET_Y_DELTA		$10
byte_69370:
		SJSR				byte_69492
		LOOPA				$30,byte_69370
		NJSR				_native_sub129
		LOOPB				$02,byte_69370
		OBJ_SET_Y_DELTA		$00
byte_69380:
		SJSR				byte_69492
		LOOPA				$1E,byte_69380
		SPR_IDX_SELECT		$10
		APU_LOAD			$6C
		NJMP				_native_bonus_room_4prizes_shuffle
		NJSR				_native_sub12A
		SSWITCH				_tmp_ptrE+1
		SCASE				byte_69412
		SCASE				byte_693D6
		SCASE				byte_6939A
byte_6939A:
		OBJ_SET_X_DELTA		$F9
		NJSR				_native_sub113
		SBMI				byte_693AF
byte_693A2:
		SJSR				byte_693BC
		SJSR				byte_693C9
		LOOPA				$02,byte_693A2
		SJMP				byte_69330
byte_693AF:
		SJSR				byte_693C9
		SJSR				byte_693BC
		LOOPA				$02,byte_693AF
		SJMP				byte_69330
byte_693BC:
		OBJ_SET_Y_DELTA		$D8
byte_693BE:
		OBJ_INC_Y_DELTA
		SJSR				byte_69492
		LOOPB				$4E,byte_693BE
		SJMP				byte_6940D
byte_693C9:
		OBJ_SET_Y_DELTA		$28
byte_693CB:
		OBJ_DEC_Y_DELTA
		SJSR				byte_69492
		LOOPB				$4E,byte_693CB
		SJMP				byte_6940D
byte_693D6:
		OBJ_SET_X_DELTA		$E8
		NJSR				_native_sub113
		SBMI				byte_693E7
		SJSR				byte_693F0
		SJSR				byte_69400
		SJMP				byte_69330
byte_693E7:
		SJSR				byte_69400
		SJSR				byte_693F0
		SJMP				byte_69330
byte_693F0:
		OBJ_SET_Y_DELTA		$E8
		SJSR				byte_693F5
byte_693F5:
		OBJ_INC_Y_DELTA
		SJSR				byte_69492
		LOOPB				$17,byte_693F5
		SJMP				byte_6940D
byte_69400:
		OBJ_SET_Y_DELTA		$18
		SJSR				byte_69405
byte_69405:
		OBJ_DEC_Y_DELTA
		SJSR				byte_69492
		LOOPB				$17,byte_69405
byte_6940D:
		SRUN				$07,_script118
		SRET
byte_69412:
		SRUN				$07,_script119
		OBJ_SET_X_DELTA		$00
		OBJ_SET_Y_DELTA		$00
byte_6941A:
		SJSR				byte_69492
		LOOPA				$78,byte_6941A
		OBJ_SET_X_DELTA		$DC
		OBJ_SET_Y_DELTA		$0A
byte_69425:
		SJSR				byte_69492
		LOOPA				$21,byte_69425
		LOOPB				$02,byte_69412
		SJMP				byte_69330

; =============== S C R I P T ===============================================
_script118:
		PARAM_40_SET
		NJSR				_native_get_bonus_room_prize_from_list
		SSWITCH				_tmp_ptrE+1
		SCASE				byte_69442
		SCASE				byte_69442
		SCASE				byte_69443
		SCASE				byte_69443
byte_69442:
		KILL
byte_69443:
		APU_LOAD			$2B
		OBJ_MOVE_X_POS		$D4
		OBJ_MOVE_Y_POS		$E5
		DESTR_PC_SET		byte_69B00
		SPR_LIB_SELECT		$08
		SPR_IDX_SELECT		$11
		OBJ_SET_SIZE		$06,$0D
		OBJ_SET_HP			$01
		VAR_1C_SET			$01
		PARAM_80_CLEAR
		OBJ_SET_FLIP		$08
		NJSR				_native_sub13D
		SBCC				byte_68096
		SJSR				_script_sub_68036
		OBJ_SET_Y_DELTA		$EC
		SPR_IDX_SELECT		$12
		SJSR				_script_sub_68036
		SPR_IDX_SELECT		$11
		SJMP				byte_69AFA

; =============== S C R I P T ===============================================
_script119:
		OBJ_MOVE_X_POS		$0E
		OBJ_MOVE_Y_POS		$CA
		SPR_LIB_SELECT		$08
		SPR_IDX_SELECT		$13
		NJMP				_native_sub111
		TARGET_LOCK			$30
		OBJ_SET_SIZE		$08,$10
		OBJ_SET_HP			$01
		VAR_1C_SET			$01
		PARAM_80_CLEAR
		OBJ_SET_FLIP		$08
byte_69486:
		SYNC
		TARGET_DIR_SET		$FF
		TARGET_FOLLOW
		LOOPA				$04,byte_69486
		FLIP_40_TOGGLE
		SJMP				byte_69486
byte_69492:
		NJSR				_native_sub144
		SBNE				byte_6949E
		APU_LOAD			$2F
		SRUN				$01,_script11A
byte_6949E:
		NJSR				_native_sub145
		SYNC
		NJSR				_native_sub146
		NJSR				_native_sub147
		NJSR				_native_sub00D
		SRET

; =============== S C R I P T ===============================================
_script11A:
		STORE				$01,byte_E0
byte_694B0:
		SUSPEND				$04
		NJSR				_load_pal_patch00
		SUSPEND				$04
		NJSR				_ppu_pal_apply
		LOOPB				$04,byte_694B0
		STORE				$00,byte_E0
		KILL

; =============== S U B R O U T I N E =======================================
_load_pal_patch00:
		LDA		#<[_pal_patch00]
		LDY		#>[_pal_patch00]
		JMP		_far_prg3_pal_patch_load

; =============== S C R I P T ===============================================
byte_694CA:
		NJSR				_scr_param_4_set
		PARAM_80_SET
		APU_LOAD			$70
		PAL_FADE_OUT		$04,$87
		SUSPEND				$80
		SJMP				byte_B6B07

; =============== S U B R O U T I N E =======================================
_native_sub00B:
		LDA		#$40
		LDY		#$00

; !FALLTHROUGH!

; =============== S U B R O U T I N E =======================================
_native_sub00B_ex:
		STA		_hor_menu_pos
		STY		_tmp48
		LDA		#$00
		LDY		#$01
		STA		_ppu_scroll_shadow_hi
		STY		_ppu_scroll_nt_vert
		STA		_ppu_scroll_shadow_lo
		STA		_ppu_scroll_nt_hor
		LDA		#$00
		STA		_wnd_split_ppu_ofs
		LDA		#$2B
		STA		_wnd_split_ppu_ofs+1
		RTS

; =============== S U B R O U T I N E =======================================
_native_sub00C:
		LDA		_hor_menu_pos
		STA		_ppu_scroll_shadow_hi
		LDA		_tmp48
		STA		_ppu_scroll_nt_vert
		RTS

; =============== S U B R O U T I N E =======================================
_native_sub00D:
		LDA		_nmi_frames_counter
		AND		#$3F
		BNE		locret_69520
		LDA		_nmi_frames_counter
		LSR
		LSR
		LSR
		LSR
		AND		#$0C
		TAX
		LDA		word_69521,X
		STA		_tmp_ptr44
		LDA		word_69521+1,X
		STA		_tmp_ptr44+1
		LDA		off_69523,X
		LDY		off_69523+1,X
		JMP		_far_prg3_rect_draw
locret_69520:
		RTS
word_69521:
		.WORD	$2272
off_69523:
		.WORD	_rect19
		.WORD	$223A
		.WORD	_rect1A
		.WORD	$2272
		.WORD	_rect1B
		.WORD	$223A
		.WORD	_rect1C

byte_69531:
		NJSR				_native_sub00B
		CHR_BANK			$00,$13
		SRUN				$01,_script11B
		SRUN				$01,_script11C
		SUSPEND				$80
		SRET

; =============== S C R I P T ===============================================
_script11B:
		OBJ_SET_X_POS		$48,$00
		SJMP				byte_6954B

; =============== S C R I P T ===============================================
_script11C:
		OBJ_SET_X_POS		$B8,$00
byte_6954B:
		OBJ_SET_Y_POS		$6D,$00
		OBJ_SET_SIZE		$05,$0A
byte_69551:
		SPR_LIB_SELECT		$08
		FLIP_80_SET
		PARAM_80_CLEAR
		SPR_IDX_SELECT		$3F
		SYNC
		SYNC
		SPR_IDX_SELECT		$54
		SYNC
		SYNC
		LOOPA				$20,byte_69551
		KILL

; =============== O B J E C T   S C R I P T =================================
_obj_scr43:
		STORE				$0E,_apu_load_idx_req
		DESTR_PC_SET		byte_B6AF1
		NJSR				_native_sub134
		OBJ_MOVE_X_POS		$50
		SPR_LIB_SELECT		$08
		OBJ_SET_HP			$08
		VAR_1C_SET			$01
		OBJ_SET_SIZE		$0C,$2C
		SUSPEND				$30
		PARAM_80_CLEAR
		OBJ_SET_X_DELTA		$F0
byte_6957C:
		SPR_IDX_SELECT		$35
		SJSR				_script207
		SPR_IDX_SELECT		$36
		SJSR				_script207
		SPR_IDX_SELECT		$37
		SJSR				_script207
		SPR_IDX_SELECT		$36
		SJSR				_script207
		LOOPA				$02,byte_6957C
byte_69594:
		SJSR				byte_6963C
		NJSR				_native_get_rand_clamp3
		SSWITCH				_tmp_ptrE+1
		SCASE				byte_695C1
		SCASE				byte_695A5
		SCASE				byte_6961F
		SCASE				byte_6961F
byte_695A5:
		NJSR				_native_cmp40_obj_y_lo_pos
		SBNE				byte_695B9
		NJSR				_native_cmpC0_obj_y_lo_pos
		SBNE				byte_695B7
		NJSR				_native_sub113
		SBMI				byte_695B9
byte_695B7:
		OBJ_SET_Y_DELTA		$AE
byte_695B9:
		SPR_IDX_SELECT		$36
		SJSR				_script20B
		SJMP				byte_69594
byte_695C1:
		OBJ_SET_X_DELTA		$18
		NJSR				_native_sub10F
byte_695C6:
		SPR_IDX_SELECT		$35
		SJSR				_script_sub_695DD
		SPR_IDX_SELECT		$36
		SJSR				_script_sub_695DD
		SPR_IDX_SELECT		$37
		SJSR				_script_sub_695DD
		SPR_IDX_SELECT		$36
		SJSR				_script_sub_695DD
		SJMP				byte_695C6

; =============== S C R I P T ===============================================
_script_sub_695DD:
		SYNC
		SJSR				_script20A
		NJSR				_obj_move_hor_animate
		NJSR				_native_sub135
		SBCC				byte_695F5
		NJSR				_native_sub118
		SBCS				byte_695FC
		LOOPA				$0A,_script_sub_695DD
		SRET
byte_695F5:
		NJSR				_native_sub110
		LOOPA_RESET
		BREAK				byte_69594
byte_695FC:
		SPR_IDX_SELECT		$36
		OBJ_SET_Y_DELTA		$D8
byte_69600:
		SYNC
		SJSR				_script20A
		NJSR				_obj_move_hor_animate
		NJSR				_native_sub109
		SBMI				byte_69613
		NJSR				_obj_vert_animate
		SJMP				byte_69600
byte_69613:
		NJSR				_native_sub10B
		SBCS				byte_69600
		OBJ_SET_Y_DELTA		$00
		LOOPA_RESET
		BREAK				byte_695C6
byte_6961F:
		SPR_IDX_SELECT		$38
		SJSR				_script207
		SPR_IDX_SELECT		$39
		SJSR				_script205
		SJSR				_script209
		SRUN				$07,_script11D
		SPR_IDX_SELECT		$3A
		SJSR				_script208
		LOOPA				$02,byte_6961F
		SJMP				byte_69594
byte_6963C:
		SPR_IDX_SELECT		$34
		OBJ_SET_X_DELTA		$00
byte_69640:
		SJSR				_script209
		LOOPA				$30,byte_69640
		SRET

; =============== S C R I P T ===============================================
_script11D:
		PARAM_40_SET
		APU_LOAD			$6E
		OBJ_SET_SIZE		$06,$06
		OBJ_SET_HP			$01
		VAR_1C_SET			$01
		SPR_LIB_SELECT		$08
		PARAM_80_CLEAR
		NJSR				_native_sub141
		OBJ_MOVE_Y_POS		$EF
		TARGET_LOCK			$40
		NJSR				_native_sub00E
		NJSR				_native_sub13D
		SBCC				_script1FE
		SJSR				_script1FF
		SPR_IDX_SELECT		$3B
		OBJ_SET_X_DELTA		$18
		OBJ_SET_Y_DELTA		$00
		NJSR				_native_sub10F
byte_69671:
		SJSR				_script_animate10
		NJSR				_native_sub007
		SBCS				byte_69671
		DESTR_PC_SET		byte_69B00
		OBJ_SET_X_DELTA		$00
		SJMP				byte_69AFA

; =============== S U B R O U T I N E =======================================
_native_sub00E:
		JSR		_native_sub111
		LDA		_obj_flips,X
		AND		#$40
		BEQ		loc_69693
		LDA		#<[byte_696AB]
		LDY		#>[byte_696AB]
		JMP		loc_69697
loc_69693:
		LDA		#<[byte_696EB]
		LDY		#>[byte_696EB]
loc_69697:
		STA		_tmp_ptr0
		STY		_tmp_ptr0+1
		LDY		_scr_vars18,X
		LDA		(_tmp_ptr0),Y
		STA		_scr_vars18,X
		TAY
		LDA		byte_6972B,Y
		STA		_obj_spr_idxs,X
		RTS

byte_696AB:
		.BYTE	$00,$01,$02,$03,$04,$05,$06,$07,$07,$07,$07,$07,$07,$07,$07,$07
		.BYTE	$07,$07,$07,$07,$07,$07,$07,$07,$07,$07,$07,$07,$07,$07,$07,$07
		.BYTE	$38,$38,$38,$38,$38,$38,$38,$38,$38,$38,$38,$38,$38,$38,$38,$38
		.BYTE	$38,$38,$38,$38,$38,$38,$38,$38,$38,$39,$3A,$3B,$3C,$3D,$3E,$3F
byte_696EB:
		.BYTE	$18,$18,$18,$18,$18,$18,$18,$18,$18,$18,$18,$18,$18,$18,$18,$18
		.BYTE	$18,$18,$18,$18,$18,$18,$18,$18,$18,$19,$1A,$1B,$1C,$1D,$1E,$1F
		.BYTE	$20,$21,$22,$23,$24,$25,$26,$27,$27,$27,$27,$27,$27,$27,$27,$27
		.BYTE	$27,$27,$27,$27,$27,$27,$27,$27,$27,$27,$27,$27,$27,$27,$27,$27
byte_6972B:
		.BYTE	$3B,$3B,$3B,$3D,$3D,$3D,$3D,$3D,$3D,$3D,$3D,$3D,$3D,$3D,$3D,$3D
		.BYTE	$3D,$3D,$3D,$3D,$3D,$3D,$3D,$3D,$3D,$3D,$3D,$3D,$3D,$3B,$3B,$3B
		.BYTE	$3B,$3B,$3B,$3C,$3C,$3C,$3C,$3C,$3C,$3C,$3C,$3C,$3C,$3C,$3C,$3C
		.BYTE	$3C,$3C,$3C,$3C,$3C,$3C,$3C,$3C,$3C,$3C,$3C,$3C,$3C,$3B,$3B,$3B

; =============== O B J E C T   S C R I P T =================================
_obj_scr44:
		STORE				$0E,_apu_load_idx_req
		DESTR_PC_SET		byte_B6AF1
		NJSR				_native_sub134
		OBJ_MOVE_X_POS		$60
		SPR_LIB_SELECT		$08
		OBJ_SET_HP			$08
		VAR_1C_SET			$01
		OBJ_SET_SIZE		$08,$30
		SUSPEND				$40
		PARAM_80_CLEAR
		OBJ_SET_X_DELTA		$F0
byte_69785:
		APU_LOAD			$6A
		SPR_IDX_SELECT		$2D
		SJSR				_script206
		SPR_IDX_SELECT		$2E
		SJSR				_script206
		APU_LOAD			$6A
		SPR_IDX_SELECT		$2F
		SJSR				_script206
		SPR_IDX_SELECT		$30
		SJSR				_script206
		APU_LOAD			$6A
		SPR_IDX_SELECT		$31
		SJSR				_script206
		SPR_IDX_SELECT		$2C
		SJSR				_script206
		LOOPA				$02,byte_69785
byte_697AD:
		SJSR				byte_69859
		NJSR				_native_sub113
		SBMI				byte_697BF
		NJSR				_native_cmpC0_obj_y_lo_pos
		SBEQ				byte_697BF
		SJSR				byte_697D8
byte_697BF:
		SJSR				byte_69845
		SJSR				byte_697ED
		NJSR				_native_sub113
		SBMI				byte_697CF
		OBJ_SET_Y_DELTA		$AC
		APU_LOAD			$54
byte_697CF:
		SJSR				byte_697ED
		NJSR				_native_sub110
		SJMP				byte_697AD
byte_697D8:
		OBJ_SET_X_DELTA		$40
		SJSR				byte_697EF
		SJSR				byte_697EF
		NJSR				_native_sub110
		SJSR				byte_697EF
		SJSR				byte_697EF
		NJSR				_native_sub110
		SRET
byte_697ED:
		OBJ_SET_X_DELTA		$20
byte_697EF:
		NJSR				_native_sub10F
		SPR_IDX_SELECT		$2D
		SJSR				byte_69813
		SPR_IDX_SELECT		$2E
		APU_LOAD			$6A
		SJSR				byte_69813
		SPR_IDX_SELECT		$2F
		SJSR				byte_69813
		SPR_IDX_SELECT		$30
		APU_LOAD			$6A
		SJSR				byte_69813
		SPR_IDX_SELECT		$31
		SJSR				byte_69813
		SPR_IDX_SELECT		$2C
		APU_LOAD			$6A
byte_69813:
		SYNC
		SJSR				_script20A
		NJSR				_obj_move_hor_animate
		NJSR				_native_sub149
		SBEQ				byte_69840
		NJSR				_native_get_obj_y_delta
		SBEQ				byte_6982C
		NJSR				_native_sub118
		SBCC				byte_69840
byte_6982C:
		NJSR				_native_sub109
		SBMI				byte_69838
		NJSR				_obj_vert_animate
		SJMP				byte_69840
byte_69838:
		NJSR				_native_sub10B
		SBCS				byte_69840
		OBJ_SET_Y_DELTA		$00
byte_69840:
		LOOPA				$08,byte_69813
		SRET
byte_69845:
		OBJ_SET_X_DELTA		$00
		NJSR				_native_bonus_room_3prizes_shuffle
byte_6984A:
		APU_LOAD			$54
		OBJ_SET_Y_DELTA		$D0
		SJSR				_script20B
		SRUN				$07,_script11E
		LOOPA				$03,byte_6984A
byte_69859:
		OBJ_SET_X_DELTA		$00
byte_6985B:
		SJSR				_script208
		LOOPA				$03,byte_6985B
		SRET

; =============== S C R I P T ===============================================
_script11E:
		PARAM_40_SET
		NJSR				_native_get_bonus_room_prize_from_list
		SSWITCH				_tmp_ptrE+1
		SCASE				byte_69870
		SCASE				byte_69875
		SCASE				byte_6987A
byte_69870:
		OBJ_SET_X_DELTA		$18
		SJMP				byte_6987C
byte_69875:
		OBJ_SET_X_DELTA		$24
		SJMP				byte_6987C
byte_6987A:
		OBJ_SET_X_DELTA		$30
byte_6987C:
		SPR_LIB_SELECT		$08
		OBJ_SET_SIZE		$06,$10
		OBJ_SET_HP			$01
		VAR_1C_SET			$01
		PARAM_80_CLEAR
		OBJ_SET_Y_DELTA		$D0
		NJSR				_native_sub10F
		NJSR				_native_sub13D
		SBCS				byte_698A7
byte_69891:
		SPR_IDX_SELECT		$32
		SJSR				byte_6989E
		SPR_IDX_SELECT		$33
		SJSR				byte_6989E
		SJMP				byte_69891
byte_6989E:
		JMP_OBJ_ANIMATE
		NJSR				_native_sub109
		LOOPA				$06,byte_6989E
		SRET
byte_698A7:
		SJSR				byte_698B5
		OBJ_SET_Y_DELTA		$E8
		SJSR				byte_698B5
		DESTR_PC_SET		byte_69B00
		SJMP				byte_69AFA
byte_698B5:
		SPR_IDX_SELECT		$32
		SJSR				byte_698C9
		SBCC				byte_698C8
		SPR_IDX_SELECT		$33
		SJSR				byte_698C9
		SBCC				byte_698C8
		SJMP				byte_698B5
byte_698C8:
		SRET
byte_698C9:
		SJSR				_script_sub_6803D
		SBCC				byte_698D3
		LOOPA				$06,byte_698C9
byte_698D3:
		LOOPA_RESET
		SRET

; =============== O B J E C T   S C R I P T =================================
_obj_scr45:
		STORE				$1E,_apu_load_idx_req
		DESTR_PC_SET		byte_69981
		STORE				$40,_ppu_scroll_shadow_lo
		STORE				$05,_ppu_scroll_nt_hor
		OBJ_SET_HP			$08
		VAR_1C_SET			$01
		OBJ_SET_X_POS		$88,$01
		OBJ_SET_Y_POS		$78,$00
		SRUN				$07,_script11F
		SRUN				$06,_script120
		NJSR				_native_sub14B
		NJSR				_native_sub134
		SPR_LIB_SELECT		$08
		SPR_IDX_SELECT		$00
		SUSPEND				$80
		PARAM_80_CLEAR
		OBJ_SET_SIZE		$08,$20
byte_69906:
		SJSR				byte_69961
		LOOPB				$06,byte_69906
byte_6990D:
		NJSR				_native_sub010
		SBNE				byte_69924
		OBJ_SET_X_DELTA		$E0
		SPR_IDX_SELECT		$00
		STORE				$0B,_pal_anim_mode_idx
		SJSR				byte_69969
		SJSR				byte_69969
		SJMP				byte_6994D
byte_69924:
		NJSR				_native_sub00F
		SBCS				byte_6994D
		NJSR				_native_sub12A
		SSWITCH				_tmp_ptrE+1
		SCASE				byte_69936
		SCASE				byte_6994D
		SCASE				byte_6995B
byte_69936:
		OBJ_SET_X_DELTA		$00
		SPR_IDX_SELECT		$01
		STORE				$00,_pal_anim_mode_idx
		SJSR				byte_69969
		NJSR				_native_sub14C
		SJSR				byte_69969
		SJSR				byte_69969
		SJSR				byte_69969
byte_6994D:
		OBJ_SET_X_DELTA		$10
		SPR_IDX_SELECT		$02
		STORE				$0A,_pal_anim_mode_idx
		SJSR				byte_69969
		SJMP				byte_6990D
byte_6995B:
		SJSR				byte_69961
		SJMP				byte_6990D
byte_69961:
		OBJ_SET_X_DELTA		$F0
		SPR_IDX_SELECT		$00
		STORE				$0B,_pal_anim_mode_idx
byte_69969:
		NJSR				_native_sub011
		NJSR				_native_sub144
		SBNE				byte_69978
		APU_LOAD			$2F
		SRUN				$01,_script121
byte_69978:
		NJSR				_native_sub145
		SYNC
		LOOPA				$20,byte_69969
		SRET
byte_69981:
		SPR_IDX_SELECT		$06
		STORE				$00,_pal_anim_mode_idx
		APU_LOAD			$70
byte_69989:
		NJSR				_native_sub012
		SUSPEND				$20
		NJSR				_native_sub012
		SUSPEND				$20
		LOOPB				$04,byte_69989
		SJMP				byte_B6B07

; =============== S U B R O U T I N E =======================================
_native_sub00F:
		LDA		_obj_x_lo_poss,X
		CMP		#$A9
		JMP		_scr_flags_update

; =============== S U B R O U T I N E =======================================
_native_sub010:
		LDA		_obj_x_hi_poss,X
		JMP		_scr_flags_update

; =============== S U B R O U T I N E =======================================
_native_sub011:
		JSR		_native_sub146
		LDA		_obj_x_deltas,X
		BEQ		locret_699BB
		LDA		_ppu_scroll_shadow_lo
		AND		#$03
		BNE		locret_699BB
		LDA		#$62
		JSR		_apu_se_req
locret_699BB:
		RTS

; =============== S U B R O U T I N E =======================================
_native_sub012:
		LDA		#$56
		STA		_tmp_ptr44
		LDA		#$21
		STA		_tmp_ptr44+1
		INC		_scr_loopsA,X
		LDA		_scr_loopsA,X
		ASL
		AND		#$02
		TAX
		LDA		off_699D7,X
		LDY		off_699D7+1,X
		JMP		_far_prg3_rect_draw

off_699D7:
		.WORD	_rect17
		.WORD	_rect18

; =============== S C R I P T ===============================================
_script121:
		NJSR				_native_sub134
		OBJ_MOVE_Y_POS		$FF
		SPR_LIB_SELECT		$08
		SPR_IDX_SELECT		$03
		PARAM_80_CLEAR
byte_699E5:
		SUSPEND				$04
		NJSR				_load_pal_patch01
		SUSPEND				$04
		NJSR				_ppu_pal_apply
		LOOPB				$04,byte_699E5
		KILL

; =============== S U B R O U T I N E =======================================
_load_pal_patch01:
		LDA		#<[_pal_patch01]
		LDY		#>[_pal_patch01]
		JMP		_far_prg3_pal_patch_load

; =============== S C R I P T ===============================================
_script11F:
		NJSR				_native_sub134
		OBJ_MOVE_Y_POS		$3F
		OBJ_SET_SIZE		$24,$40
		OBJ_SET_HP			$01
		VAR_1C_SET			$01
byte_69A07:
		SYNC
		SJSR				byte_69A12
		SJMP				byte_69A07
byte_69A0E:
		SYNC
		NJSR				_scr_param_4_clear
byte_69A12:
		NJSR				_native_get_obj3_hp
		SBEQ				byte_69A1B
		OBJ_SET_SIZE		$00,$00
byte_69A1B:
		SRET

; =============== S C R I P T ===============================================
_script120:
		NJSR				_native_sub134
		OBJ_MOVE_X_POS		$94
		OBJ_MOVE_Y_POS		$48
		SPR_LIB_SELECT		$08
		SPR_IDX_SELECT		$08
		OBJ_SET_SIZE		$08,$20
		OBJ_SET_HP			$FF
		VAR_1C_SET			$FF
		PARAM_80_CLEAR
		SJSR				byte_69A5B
byte_69A32:
		NJSR				_native_sub139
byte_69A35:
		SJSR				byte_69A0E
		NJSR				_native_sub14E
		SBEQ				byte_69A35
		SJSR				byte_69A6E
		APU_LOAD			$63
		SRUN				$07,_script122
		SJSR				byte_69A0E
		SRUN				$07,_script123
byte_69A4E:
		SJSR				byte_69A0E
		LOOPB				$3C,byte_69A4E
		SJSR				byte_69A5B
		SJMP				byte_69A32
byte_69A5B:
		OBJ_SET_Y_DELTA		$E0
byte_69A5D:
		SJSR				byte_69A0E
		NJSR				_obj_vert_animate
		NJSR				_native_sub013
		NJSR				_native_sub014
		LOOPA				$18,byte_69A5D
		SRET
byte_69A6E:
		OBJ_SET_Y_DELTA		$40
byte_69A70:
		SJSR				byte_69A0E
		NJSR				_obj_vert_animate
		NJSR				_native_sub015
		NJSR				_native_sub013
		LOOPA				$0C,byte_69A70
		SRET

; =============== S U B R O U T I N E =======================================
_native_sub013:
		SEC
		LDA		_obj_y_lo_poss,X
		SBC		#$30
		STA		_obj_heigts,X
		LDA		_scr_loopsB,X
		AND		#$03
		BEQ		loc_69A92
		RTS
loc_69A92:
		LDA		#$EB
		STA		_tmp_ptr44
		LDA		#$20
		STA		_tmp_ptr44+1
		LDA		_scr_loopsB,X
		AND		#$1C
		TAX
		LDA		off_69AB9+2,X
		STA		_tmp_ptr2
		LDA		off_69AB9,X
		LDY		off_69AB9+1,X
		JMP		_far_prg3_tlm_queue

; =============== S U B R O U T I N E =======================================
_native_sub014:
		INC		_scr_loopsB,X
		RTS

; =============== S U B R O U T I N E =======================================
_native_sub015:
		DEC		_scr_loopsB,X
		DEC		_scr_loopsB,X
		RTS

off_69AB9:
		.WORD	_tlm00
		.WORD	$4F
		.WORD	_tlm01
		.WORD	$4E
		.WORD	_tlm02
		.WORD	$4D
		.WORD	_tlm03
		.WORD	$4C
		.WORD	_tlm04
		.WORD	$4B
		.WORD	_tlm05
		.WORD	$4A

; =============== S C R I P T ===============================================
_script122:
		OBJ_SET_X_DELTA		$F0
		SJMP				byte_69AD8

; =============== S C R I P T ===============================================
_script123:
		OBJ_SET_X_DELTA		$10
byte_69AD8:
		PARAM_40_SET
		DESTR_PC_SET		byte_69B00
		OBJ_SET_Y_DELTA		$D0
		SPR_LIB_SELECT		$08
		SPR_IDX_SELECT		$07
		OBJ_SET_SIZE		$06,$10
		OBJ_SET_HP			$01
		VAR_1C_SET			$01
		PARAM_80_CLEAR
		OBJ_SET_FLIP		$08
		NJSR				_native_sub13D
		SBCC				byte_68096
		SJSR				_script_sub_68036
		OBJ_SET_Y_DELTA		$E8
		SJSR				_script_sub_68036
byte_69AFA:
		NJSR				_native_sub13B
		SJSR				byte_68065
byte_69B00:
		SJSR				byte_6806C
		OBJ_SET_FLIP		$08
		NJSR				_native_sub030
byte_69B08:
		JMP_OBJ_ANIMATE
		NJSR				_native_sub016
		SBEQ				byte_69B08
		SJMP				byte_68096

; =============== S U B R O U T I N E =======================================
_native_sub016:
		LDA		_obj_hps,X
		BNE		loc_69B28
		LDA		#$08
		LDY		_obj_x_deltas,X
		BMI		loc_69B20
		LDA		#$F8
loc_69B20:
		STA		_obj_x_deltas,X
		LDA		#$00
		STA		_obj_y_deltas,X
loc_69B28:
		JMP		_scr_flags_update

; =============== O B J E C T   S C R I P T =================================
_obj_scr46:
		NJSR				_native_sub019
		STORE				$00,_ppu_scroll_nt_vert
		STORE				$1F,_apu_load_idx_req
		SRUN				$01,_script124
		SRUN				$01,_script125
		SRUN				$01,_script126
		SRUN				$01,_script127
		NJSR				_native_sub139
byte_69B49:
		NJMP				_native_sub14E
		SBEQ				byte_69B49
		CHR_BANK			$00,$1C
		CHR_BANK			$01,$0D
		STORE				<[_tileset05],_room_tileset_ptr
		STORE				>[_tileset05],_room_tileset_ptr+1
byte_69B5D:
		NJMP				_native_sub14F
		LOOPA				$0F,byte_69B5D
		LOOPB				$10,byte_69B5D
		NJSR				_pal_bg003_reload
		DESTR_PC_SET		byte_69D30
		NJSR				_native_sub134
		SPR_LIB_SELECT		$08
		SPR_IDX_SELECT		$51
		OBJ_SET_HP			$0A
		VAR_1C_SET			$01
		OBJ_SET_SIZE		$00,$00
		NJSR				_native_sub00C
		PAL_FADE_IN			$04,$C3
		SRUN				$06,_script128
		NJSR				_native_sub14B
		SRUN				$06,_script129
		NJSR				_native_sub150
		SUSPEND				$14
		PARAM_80_CLEAR
		OBJ_SET_SIZE		$28,$70
		NJSR				_native_sub021
		SJSR				byte_69C88
		OBJ_SET_Y_DELTA		$F0
		SRUN				$06,_script12A
		SJSR				byte_69C7E
byte_69BA5:
		SJSR				byte_69D06
		LOOPA				$30,byte_69BA5
		OBJ_SET_Y_DELTA		$40
byte_69BAE:
		SJSR				byte_69D06
		LOOPA				$10,byte_69BAE
		SJSR				byte_69C4E
byte_69BB8:
		SJSR				byte_69C88
byte_69BBB:
		OBJ_SET_Y_DELTA		$F0
		SRUN				$06,_script12A
		SJSR				byte_69C7E
byte_69BC4:
		SJSR				byte_69D06
		LOOPA				$C0,byte_69BC4
		OBJ_SET_Y_DELTA		$00
		OBJ_SET_SIZE		$00,$00
byte_69BD0:
		SJSR				byte_69CDC
		LOOPB				$3C,byte_69BD0
		SRUN				$03,_script12B
		NJSR				_native_sub01D
		SRUN				$01,_script12C
byte_69BE2:
		SJSR				byte_69CDC
		LOOPB				$B4,byte_69BE2
		OBJ_SET_SIZE		$28,$70
		OBJ_SET_Y_DELTA		$40
byte_69BEE:
		SJSR				byte_69D06
		LOOPA				$34,byte_69BEE
		SJSR				byte_69C4E
		NJSR				_native_sub01C
		SBCC				byte_69C10
		NJSR				_native_bonus_room_4prizes_shuffle
		SRUN				$07,_script12D
byte_69C05:
		SJSR				byte_69CDC
		LOOPB				$3C,byte_69C05
		SRUN				$07,_script12D
byte_69C10:
		NJSR				_native_cmpC0_obj_x_lo_pos
		SBEQ				byte_69BB8
		NJSR				_native_sub12A
		SSWITCH				_tmp_ptrE+1
		SCASE				byte_69C22
		SCASE				byte_69C2F
		SCASE				byte_69C3C
byte_69C22:
		SSWITCH				byte_E0
		SCASE				byte_69C2F
		SCASE				byte_69C29
byte_69C29:
		NJMP				_native_sub151
		SJMP				byte_69C40
byte_69C2F:
		SSWITCH				byte_E1
		SCASE				byte_69C3C
		SCASE				byte_69C36
byte_69C36:
		NJMP				_native_sub14C
		SJMP				byte_69C40
byte_69C3C:
		SRUN				$01,_script12E
byte_69C40:
		SJSR				byte_69CDC
		LOOPB				$B4,byte_69C40
		LOOPA				$02,byte_69C10
		SJMP				byte_69BBB
byte_69C4E:
		APU_LOAD			$44
		OBJ_SET_Y_DELTA		$E0
		SJSR				byte_69C76
		OBJ_SET_Y_DELTA		$E8
		SJSR				byte_69C76
		OBJ_SET_Y_DELTA		$F0
		SJSR				byte_69C76
		OBJ_SET_Y_DELTA		$F8
		SJSR				byte_69C76
		TARGET_DIR_SET		$06
		SJSR				byte_69CB5
		TARGET_DIR_SET		$04
		SJSR				byte_69CB5
		OBJ_SET_Y_DELTA		$10
		SJSR				byte_69C76
		APU_LOAD			$44
		SRET
byte_69C76:
		SJSR				byte_69D06
		LOOPA				$04,byte_69C76
		SRET
byte_69C7E:
		TARGET_DIR_SET		$02
		SJSR				byte_69CB5
		TARGET_DIR_SET		$00
		SJMP				byte_69CB5
byte_69C88:
		NJSR				_native_sub01C
		SBCS				byte_69CAD
byte_69C8E:
		TARGET_DIR_SET		$08
		SJSR				byte_69CB5
byte_69C93:
		SJSR				byte_69CDC
		LOOPB				$3C,byte_69C93
		APU_LOAD			$30
		TARGET_DIR_SET		$0A
		SJSR				byte_69CB5
byte_69CA1:
		SJSR				byte_69CDC
		LOOPB				$3C,byte_69CA1
		LOOPA				$03,byte_69C8E
		SRET
byte_69CAD:
		SJSR				byte_69CDC
		LOOPB				$F0,byte_69CAD
		SRET
byte_69CB5:
		NJSR				_native_sub017
byte_69CB8:
		SJSR				byte_69CDC
		NJSR				_native_sub152
		SBEQ				byte_69CB8
		SRET

; =============== S U B R O U T I N E =======================================
_native_sub017:
		LDY		_scr_vars19,X
		LDA		off_69CD0,Y
		STA		_tmp_ptr4B
		LDA		off_69CD0+1,Y
		STA		_tmp_ptr4B+1
		RTS
off_69CD0:
		.WORD	tlm_patch00
		.WORD	tlm_patch01
		.WORD	tlm_patch02
		.WORD	tlm_patch03
		.WORD	tlm_patch04
		.WORD	tlm_patch05
byte_69CDC:
		NJSR				_native_sub144
		SBNE				byte_69CFC
		APU_LOAD			$2F
		SRUN				$01,_script12F
		NJSR				_native_sub01C
		SBCC				byte_69CFC
		NJSR				_native_sub018
		SBNE				byte_69CFC
		STORE				$00,byte_E2
		SRUN				$01,_script130
byte_69CFC:
		SYNC
		NJSR				_native_sub145
		SRET

; =============== S U B R O U T I N E =======================================
_native_sub018:
		LDA		byte_E2
		JMP		_scr_flags_update
byte_69D06:
		SJSR				byte_69CDC
		NJSR				_native_sub146
		NJSR				_native_sub147
		SRET

; =============== S U B R O U T I N E =======================================
_native_sub019:
		LDA		#$01
		STA		byte_E0
		STA		byte_E1
		STA		byte_E2
		LDA		#$C0
		STA		_obj_x_lo_poss,X
		STA		_obj_y_lo_poss,X
		LDA		#$2C
		LDY		#$00
		JMP		_native_sub00B_ex

; =============== S U B R O U T I N E =======================================
_pal_bg003_reload:
		LDX		#$77
		LDA		#<[_pal_bg003]
		LDY		#>[_pal_bg003]
		JMP		_far_prg3_pal_bg_reload
byte_69D30:
		OBJ_SET_Y_DELTA		$00
		SRUN				$01,_script12F
		SRUN				$01,_script130
		SUSPEND				$B4
		APU_LOAD			$70
		PAL_FADE_OUT		$04,$C7
		SUSPEND				$80
		SJMP				byte_B6B07

; =============== S C R I P T ===============================================
_script130:
		NJSR				_native_sub01B
		SRUN				$01,_script131
		SUSPEND				$13
		LOOPA				$05,_script130
		APU_LOAD			$46
		NJMP				_cat_boss_bg_patch0_draw
		NJMP				_cat_boss_bg_patch1_draw
byte_69D5B:
		NJSR				_native_sub01B
		SRUN				$01,_script131
		SUSPEND				$13
		LOOPA				$03,byte_69D5B
		KILL

; =============== S C R I P T ===============================================
_script131:
		SRUN				$01,_script132
		SJSR				byte_6A052
		KILL

; =============== S C R I P T ===============================================
_script132:
		SPR_LIB_SELECT		$08
		SPR_IDX_SELECT		$4D
		PARAM_80_CLEAR
		NJMP				_native_sub01A
		SJMP				byte_689E8

; =============== S U B R O U T I N E =======================================
_native_sub01A:
		JSR		_native_get_rand3
		LDA		byte_69D98,Y
		STA		_obj_y_deltas,X
		JSR		_native_get_rand3
		LDA		byte_69F42,Y
		STA		_obj_x_deltas,X
		JSR		_rand
		LSR
		BCS		locret_69D97
		JMP		_native_sub105
locret_69D97:
		RTS
byte_69D98:
		.BYTE	$E8,$E0,$DC,$D8

; =============== S U B R O U T I N E =======================================
_native_get_rand3:
		JSR		_rand
		AND		#$03
		TAY
		RTS

; =============== S U B R O U T I N E =======================================
_native_sub01B:
		JSR		_rand
		AND		#$07
		TAY
		LDA		byte_69DD1,Y
		STA		_tmp_ptr0
		LDA		byte_69DD9,Y
		STA		_tmp_ptr2
		LDY		_scr_idxAs,X
		CLC
		LDA		_obj_x_lo_poss,Y
		ADC		_tmp_ptr0
		STA		_obj_x_lo_poss,X
		CLC
		LDA		_obj_y_lo_poss,Y
		ADC		_tmp_ptr2
		STA		_obj_y_lo_poss,X
		LDA		_obj_y_hi_poss,Y
		ADC		#$FF
		STA		_obj_y_hi_poss,X
		RTS
byte_69DD1:
		.BYTE	$D0,$E0,$F8,$10,$F0,$E0,$10,$00
byte_69DD9:
		.BYTE	$B0,$C0,$B0,$C0,$D0,$E0,$E0,$A0

; =============== S U B R O U T I N E =======================================
_cat_boss_bg_patch0_draw:
		LDA		#$D6
		STA		_tmp_ptr44
		LDA		#$21
		STA		_tmp_ptr44+1
		LDA		#<[_cat_boss_bg_patch0]
		LDY		#>[_cat_boss_bg_patch0]
		JMP		_far_prg3_rect_draw

; =============== S U B R O U T I N E =======================================
_cat_boss_bg_patch1_draw:
		LDA		#$52
		STA		_tmp_ptr44
		LDA		#$22
		STA		_tmp_ptr44+1
		LDA		#<[_cat_boss_bg_patch1]
		LDY		#>[_cat_boss_bg_patch1]
		JMP		_far_prg3_rect_draw

; =============== S U B R O U T I N E =======================================
_native_sub01C:
		LDA		_obj_hps,X
		CMP		#$06
		JMP		_scr_flags_update

; =============== S U B R O U T I N E =======================================
_native_sub01D:
		LDY		#$05
		JSR		_rand_scale
		LDA		byte_69E27,Y
		STA		_ppu_scroll_shadow_lo
		SEC
		LDA		_obj_x_lo_poss,X
		SBC		byte_69E22,Y
		STA		_obj_global_x_shift
loc_69E1A:
		LDA		_obj_x_hi_poss,X
		SBC		#$00
		STA		_obj_global_x_shift+1
		RTS
byte_69E22:
		.BYTE	$50,$80,$C0,$C0,$C0
byte_69E27:
		.BYTE	$70,$40,$00,$00,$00

; =============== S C R I P T ===============================================
_script12F:
		SUSPEND				$04
		NJSR				_pal_patch02_load
		SUSPEND				$04
		NJSR				_ppu_pal_apply
		LOOPB				$04,_script12F
		KILL

; =============== S U B R O U T I N E =======================================
_pal_patch02_load:
		LDA		#<[_pal_patch02]
		LDY		#>[_pal_patch02]
		JMP		_far_prg3_pal_patch_load
byte_69E42:
		SJSR				_script209
		SJMP				byte_69A12
byte_69E48:
		OBJ_SET_X_DELTA		$00
		OBJ_SET_Y_DELTA		$00
		NJSR				_native_sub139
byte_69E4F:
		SJSR				byte_69E42
		NJSR				_native_sub14E
		SBEQ				byte_69E4F
		SRET

; =============== S C R I P T ===============================================
_script128:
		DESTR_PC_SET		byte_69E8F
		NJSR				_native_sub134
		OBJ_SET_HP			$05
		VAR_1C_SET			$01
		OBJ_SET_SIZE		$06,$0C
		OBJ_MOVE_X_POS		$B2
		OBJ_MOVE_Y_POS		$C2
		SPR_LIB_SELECT		$08
		SPR_IDX_SELECT		$3E
		PARAM_80_CLEAR
byte_69E6F:
		SJSR				byte_69E48
		APU_LOAD			$45
		NJSR				_native_sub153
		FLIP_40_CLEAR
		SJSR				byte_69E87
		NJSR				_native_sub105
		NJSR				_native_sub129
		SJSR				byte_69E87
		SJMP				byte_69E6F
byte_69E87:
		SJSR				byte_69E42
		LOOPA				$24,byte_69E87
		SRET
byte_69E8F:
		STORE				$00,byte_E1
		SJSR				byte_6A069
		KILL

; =============== S C R I P T ===============================================
_script129:
		DESTR_PC_SET		byte_69EF8
		NJSR				_native_sub134
		OBJ_SET_HP			$05
		VAR_1C_SET			$01
		OBJ_SET_SIZE		$06,$0C
		OBJ_MOVE_X_POS		$2E
		OBJ_MOVE_Y_POS		$C0
		SPR_LIB_SELECT		$08
		SPR_IDX_SELECT		$4F
		PARAM_80_CLEAR
byte_69EAD:
		SJSR				byte_69E48
		APU_LOAD			$54
		OBJ_SET_X_DELTA		$C8
		OBJ_SET_Y_DELTA		$20
		SJSR				byte_69ECD
		OBJ_SET_X_DELTA		$EC
		SJSR				byte_69ED5
		OBJ_SET_X_DELTA		$14
		SJSR				byte_69ED5
		OBJ_SET_X_DELTA		$38
		OBJ_SET_Y_DELTA		$E0
		SJSR				byte_69ECD
		SJMP				byte_69EAD
byte_69ECD:
		SJSR				byte_69E42
		LOOPA				$20,byte_69ECD
		SRET
byte_69ED5:
		OBJ_SET_Y_DELTA		$B0
byte_69ED7:
		SJSR				byte_69E42
		NJSR				_native_sub109
		LOOPA				$14,byte_69ED7
byte_69EE1:
		NJSR				_native_sub129
		NJSR				_native_sub109
		SJSR				byte_69E42
		NJSR				_native_sub129
		LOOPA				$14,byte_69EE1
		APU_LOAD			$6C
		LOOPB				$02,byte_69ED5
		SRET
byte_69EF8:
		STORE				$00,byte_E0
		SJSR				byte_6A069
		KILL

; =============== S C R I P T ===============================================
_script12D:
		OBJ_MOVE_Y_POS		$90
		OBJ_SET_FLIP		$08
		OBJ_SET_HP			$01
		VAR_1C_SET			$01
		OBJ_SET_SIZE		$04,$10
		SPR_LIB_SELECT		$08
		SPR_IDX_SELECT		$46
		PARAM_80_CLEAR
		OBJ_SET_Y_DELTA		$E8
		NJSR				_native_sub01E
byte_69F15:
		SJSR				_script_sub_6803D
		SBCC				byte_69F23
		LOOPA				$06,byte_69F15
		FLIP_40_TOGGLE
		SJMP				byte_69F15
byte_69F23:
		SPR_IDX_SELECT		$47
byte_69F25:
		SUSPEND				$04
		FLIP_80_SET
		SUSPEND				$04
		FLIP_40_SET
		SUSPEND				$04
		FLIP_80_CLEAR
		SUSPEND				$04
		FLIP_40_CLEAR
		LOOPA				$02,byte_69F25
		KILL

; =============== S U B R O U T I N E =======================================
_native_sub01E:
		JSR		_native_get_bonus_room_prize_from_list
		LDY		_tmp_ptrE+1
		LDA		byte_69F42,Y
		STA		_obj_x_deltas,X
		RTS
byte_69F42:
		.BYTE	$F0,$E4,$E8,$EC

; =============== S C R I P T ===============================================
_script12C:
		OBJ_SET_Y_POS		$30,$00
		SPR_LIB_SELECT		$08
		SPR_IDX_SELECT		$49
		PARAM_80_CLEAR
		SUSPEND				$AA
		KILL

; =============== S C R I P T ===============================================
_script12B:
		OBJ_MOVE_Y_POS		$10
		DESTR_PC_SET		byte_69F7C
		OBJ_SET_HP			$01
		VAR_1C_SET			$FF
		OBJ_SET_FLIP		$08
		OBJ_SET_SIZE		$06,$0E
		SPR_LIB_SELECT		$08
		SPR_IDX_SELECT		$4C
		PARAM_80_CLEAR
		SJSR				_script_sub_68036
		APU_LOAD			$2B
		OBJ_SET_Y_DELTA		$F0
		SJSR				_script_sub_68036
		APU_LOAD			$2B
		NJSR				_native_sub13B
byte_69F73:
		SJSR				byte_69FB5
		NJSR				_native_get_obj_var0D
		SBMI				byte_69F73
byte_69F7C:
		NJSR				_native_sub13A
		NJSR				_native_sub134
byte_69F82:
		SJSR				byte_69FB5
		NJSR				_players_animB_sub0129_sub06_C
		NJSR				_native_get_obj_var0D
		SBPL				byte_69F82
		APU_LOAD			$24
		OBJ_SET_FLIP		$08
		NJSR				_native_sub12B
		NJSR				_native_sub030
		NJSR				_native_sub154
		OBJ_SET_HP			$01
		VAR_1C_SET			$FF
byte_69F9F:
		JSR_OBJ_ANIMATE
		SJSR				byte_69FB5
		NJSR				_native_sub016
		SBEQ				byte_69F9F
		APU_LOAD			$30
byte_69FAB:
		SJSR				byte_69FB5
		JSR_OBJ_ANIMATE
		NJSR				_native_sub109
		SJMP				byte_69FAB
byte_69FB5:
		NJMP				_native_sub01F
		SBNE				byte_69FBC
		SRET
byte_69FBC:
		NJSR				_native_get_obj_var0D
		SBMI				byte_69FCA
		NJSR				_native_sub033
		OBJ_MOVE_Y_POS		$08
		NJSR				_scr_param_4_clear
byte_69FCA:
		NJSR				_native_sub13A
		OBJ_SET_HP			$01
		VAR_1C_SET			$01
		OBJ_SET_SIZE		$0C,$0E
		SJSR				byte_6A069
		KILL

; =============== S U B R O U T I N E =======================================
_native_sub01F:
		LDA		_scr_vars20,X
		ROL
		ROL
		ROL
		AND		#$03
		TAY
		LDA		byte_69FED,Y
		STA		_obj_spr_idxs,X
		INC		_scr_vars20,X
		JMP		_scr_flags_update
byte_69FED:
		.BYTE	$4C,$4C,$4B,$4A

; =============== S C R I P T ===============================================
_script12E:
		OBJ_SET_FLIP		$08
		OBJ_MOVE_X_POS		$18
		OBJ_MOVE_Y_POS		$F0
		SPR_LIB_SELECT		$08
		SPR_IDX_SELECT		$48
		SJSR				byte_6A04B
		OBJ_MOVE_X_POS		$09
		OBJ_MOVE_Y_POS		$F8
		SJSR				byte_6A04B
		OBJ_MOVE_X_POS		$09
		OBJ_MOVE_Y_POS		$08
		SJSR				byte_6A04B
		OBJ_MOVE_X_POS		$05
		OBJ_MOVE_Y_POS		$09
		SJSR				byte_6A04B
		OBJ_MOVE_X_POS		$05
		OBJ_MOVE_Y_POS		$07
		SJSR				byte_6A04B
		OBJ_MOVE_X_POS		$07
		OBJ_MOVE_Y_POS		$FE
byte_6A01E:
		SJSR				byte_6A04B
		LOOPA				$08,byte_6A01E
		SRUN				$07,_script133
		LOOPB				$03,byte_6A01E
		KILL

; =============== S C R I P T ===============================================
_script133:
		APU_LOAD			$6F
		OBJ_SET_FLIP		$08
		OBJ_SET_HP			$01
		VAR_1C_SET			$01
		OBJ_SET_SIZE		$04,$08
		SPR_LIB_SELECT		$08
		SPR_IDX_SELECT		$48
		OBJ_SET_X_DELTA		$40
		NJSR				_native_sub10E
		NJSR				_native_sub10F
byte_6A045:
		SJSR				byte_6A04B
		SJMP				byte_6A045
byte_6A04B:
		PARAM_80_CLEAR
		JMP_OBJ_ANIMATE
		JMP_OBJ_ANIMATE
		PARAM_80_SET
		JMP_OBJ_ANIMATE
		JMP_OBJ_ANIMATE
		SRET
byte_6A052:
		APU_LOAD			$46
		SPR_LIB_SELECT		$08
		PARAM_80_CLEAR
		SPR_IDX_SELECT		$40
		SUSPEND				$08
		SPR_IDX_SELECT		$41
		SUSPEND				$08
		SPR_IDX_SELECT		$44
		SUSPEND				$08
		SPR_IDX_SELECT		$45
		SUSPEND				$08
		PARAM_80_SET
		SRET
byte_6A069:
		APU_LOAD			$46
		SPR_LIB_SELECT		$08
		PARAM_80_CLEAR
		SPR_IDX_SELECT		$40
		SUSPEND				$08
		SPR_IDX_SELECT		$41
		SUSPEND				$08
		SPR_IDX_SELECT		$42
		SUSPEND				$08
		SPR_IDX_SELECT		$43
		SUSPEND				$08
		PARAM_80_SET
		SRET

; =============== S C R I P T ===============================================
_script12A:
		SPR_LIB_SELECT		$08
		PARAM_80_CLEAR
byte_6A083:
		APU_LOAD			$43
byte_6A085:
		SPR_IDX_SELECT		$3F
		NJMP				_native_sub020
		NJMP				_native_sub020
		SPR_IDX_SELECT		$54
		NJMP				_native_sub020
		NJMP				_native_sub020
		LOOPA				$0A,byte_6A085
		SJMP				byte_6A083

; =============== S U B R O U T I N E =======================================
_native_sub020:
		LDY		_scr_idxAs,X
		LDA		_obj_y_deltas,Y
		BPL		loc_6A0C6
		CLC
		LDA		_obj_y_lo_poss,Y
		ADC		#$04
		STA		_obj_y_lo_poss,X
		LDA		_nmi_frames_counter
		LSR
		BCC		loc_6A0BC
		CLC
		LDA		_obj_x_lo_poss,Y
		ADC		#$18
		STA		_obj_x_lo_poss,X
		RTS
loc_6A0BC:
		SEC
		LDA		_obj_x_lo_poss,Y
		SBC		#$20
		STA		_obj_x_lo_poss,X
		RTS
loc_6A0C6:
		LDA		#$80
		STA		_scr_params,X
		STA		_scr_vars21,X
		RTS

; =============== S C R I P T ===============================================
_script124:
		NJSR				_native_sub134
		OBJ_SET_FLIP		$08
		SPR_LIB_SELECT		$08
		SPR_IDX_SELECT		$52
		PARAM_80_CLEAR
		OBJ_SET_Y_POS		$BC,$00
byte_6A0DC:
		OBJ_SET_X_POS		$00,$00
		SJSR				byte_6A0F7
		OBJ_SET_X_POS		$20,$00
		SJSR				byte_6A0F7
		OBJ_SET_X_POS		$10,$00
		SJSR				byte_6A0F7
		OBJ_SET_X_POS		$30,$00
		SJSR				byte_6A0F7
		SJMP				byte_6A0DC
byte_6A0F7:
		SYNC
		OBJ_MOVE_X_POS		$40
		LOOPA				$04,byte_6A0F7
		SRET

; =============== S C R I P T ===============================================
_script125:
		TARGET_DIR_SET		$04
		OBJ_SET_X_POS		$20,$00
		OBJ_SET_Y_POS		$20,$00
		SJSR				byte_6A132
		NJSR				_pal_bg000_load
		KILL

; =============== S C R I P T ===============================================
_script126:
		TARGET_DIR_SET		$02
		OBJ_SET_X_POS		$C0,$00
		OBJ_SET_Y_POS		$20,$00
		SJSR				byte_6A132
		NJSR				_pal_bg001_load
		KILL

; =============== S C R I P T ===============================================
_script127:
		TARGET_DIR_SET		$01
		OBJ_SET_X_POS		$70,$00
		OBJ_SET_Y_POS		$40,$00
		SJSR				byte_6A132
		NJSR				_pal_bg002_load
		PAL_FADE_OUT		$01,$C0
		NJSR				_native_sub155
		KILL
byte_6A132:
		NJSR				_native_sub000
		SPR_LIB_SELECT		$05
		SPR_IDX_SELECT		$06
byte_6A139:
		PARAM_80_SET
		SYNC
		SYNC
		PARAM_80_CLEAR
		SYNC
		SYNC
		LOOPA				$10,byte_6A139
		LOOPB				$06,byte_6A139
		SPR_IDX_SELECT		$07
		APU_LOAD			$6D
		SUSPEND				$10
		SRET

; =============== S U B R O U T I N E =======================================
_pal_bg000_load:
		LDA		#<[_pal_bg000]
		LDY		#>[_pal_bg000]
		JMP		_far_prg3_bg_pal_load

; =============== S U B R O U T I N E =======================================
_pal_bg001_load:
		LDA		#<[_pal_bg001]
		LDY		#>[_pal_bg001]
		JMP		_far_prg3_bg_pal_load

; =============== S U B R O U T I N E =======================================
_pal_bg002_load:
		LDA		#<[_pal_bg002]
		LDY		#>[_pal_bg002]
		JMP		_far_prg3_bg_pal_load

; =============== S U B R O U T I N E =======================================
_native_sub021:
		LDX		#$01
loc_6A165:
		LDA		_players_states,X
		CMP		#$04
		BNE		loc_6A173
		LDA		#$05
		STA		_players_states,X
		LDA		#$00
		STA		_players_vars0A,X
loc_6A173:
		DEX
		BPL		loc_6A165
		RTS

; =============== O B J E C T   S C R I P T =================================
_obj_scr20:
		SJSR				byte_6A19A
		NJSR				_native_sub156
		KILL

; =============== O B J E C T   S C R I P T =================================
_obj_scr21:
		SJSR				byte_6A193
		KILL

; =============== O B J E C T   S C R I P T =================================
_obj_scr22:
		SJSR				byte_6A193
		NJSR				_native_sub157
		KILL
byte_6A189:
		SJSR				byte_6A193
		NJSR				_native_sub157
		NJSR				_native_sub157
		KILL
byte_6A193:
		SJSR				byte_6A19A
		NJSR				_native_sub158
		SRET
byte_6A19A:
		OBJ_SET_SIZE		$06,$10
byte_6A19D:
		OBJ_SET_HP			$01
		SJSR				_script200
		NJSR				_native_sub159
		SBEQ				byte_6A19D
		SRET
		OBJ_MOVE_Y_POS		$08
byte_6A1AB:
		APU_LOAD			$23
		SPR_LIB_SELECT		$06
		PARAM_80_CLEAR
		SPR_IDX_SELECT		$04
		SUSPEND				$06
		SPR_IDX_SELECT		$05
		SUSPEND				$06
		SPR_IDX_SELECT		$06
		SUSPEND				$06
		SPR_IDX_SELECT		$07
		SRET

; =============== O B J E C T   S C R I P T =================================
_obj_scr1B:
		OBJ_MOVE_X_POS		$50
		OBJ_MOVE_X_POS		$50
		OBJ_SET_X_DELTA		$F0
		SPR_LIB_SELECT		$00
		PARAM_80_CLEAR
byte_6A1C8:
		SPR_IDX_SELECT		$23
		SJSR				_script_animate10
		SPR_IDX_SELECT		$24
		SJSR				_script_animate10
		SPR_IDX_SELECT		$25
		SJSR				_script_animate10
		SPR_IDX_SELECT		$24
		SJSR				_script_animate10
		LOOPA				$05,byte_6A1C8
		SJSR				byte_6A204
		TARGET_DIR_SET		$0C
		SRUN				$0A,_script134
		SJSR				byte_6A208
		SJSR				byte_6A204
		TARGET_DIR_SET		$0C
		SRUN				$0A,_script135
		SJSR				byte_6A208
		SJSR				byte_6A204
		NJSR				_native_sub15A
byte_6A1FE:
		SJSR				byte_6A208
		SJMP				byte_6A1FE
byte_6A204:
		SPR_IDX_SELECT		$1C
		TARGET_DIR_SET		$00
byte_6A208:
		NJMP				_native_sub15B
		LOOPB				$1E,byte_6A208
		SRET

; =============== S C R I P T ===============================================
_script134:
		OBJ_SET_X_DELTA		$DE
		SJMP				byte_6A217

; =============== S C R I P T ===============================================
_script135:
		OBJ_SET_X_DELTA		$E8
byte_6A217:
		OBJ_MOVE_X_POS		$F2
		OBJ_MOVE_Y_POS		$F2
		OBJ_SET_Y_DELTA		$D8
		SJSR				byte_6A25D
		SJSR				byte_68020
		NJSR				_native_sub15C
		KILL

; =============== O B J E C T   S C R I P T =================================
_obj_scr1F:
		SPR_LIB_SELECT		$06
		SPR_IDX_SELECT		$01
		OBJ_SET_SIZE		$06,$0C
		OBJ_SET_HP			$01
		PARAM_80_CLEAR
		SJSR				_script200
		NJSR				_native_sub15D

; =============== S C R I P T ===============================================
_script151:
		SPR_LIB_SELECT		$06
		SPR_IDX_SELECT		$08
byte_6A23B:
		NJSR				_native_sub15E
		APU_LOAD			$37
byte_6A240:
		OBJ_MOVE_Y_POS		$F0
		OBJ_SET_X_DELTA		$00
		OBJ_SET_Y_DELTA		$FC
		PARAM_80_CLEAR
byte_6A247:
		SJSR				_script_animate16
		LOOPA				$04,byte_6A247
		SUSPEND				$14
		KILL
		OBJ_SET_Y_DELTA		$D7
_script41:
		SJSR				byte_6A25D
		SJSR				byte_68020
		NJSR				_native_sub15F
		KILL
byte_6A25D:
		SPR_LIB_SELECT		$06
		SPR_IDX_SELECT		$00
		OBJ_SET_SIZE		$04,$0A
		OBJ_SET_HP			$01
		PARAM_80_CLEAR
		SRET
byte_6A268:
		SPR_LIB_SELECT		$06
		SPR_IDX_SELECT		$03
		OBJ_SET_SIZE		$10,$20
		OBJ_SET_HP			$01
		PARAM_80_CLEAR
		SJSR				_script200
		SJMP				byte_6A1AB

; =============== O B J E C T   S C R I P T =================================
_obj_scr1D:
		SJSR				byte_6A268
		DESTR_PC_SET		byte_6A2A0
		NJSR				_native_sub13B
		SPR_LIB_SELECT		$04
		OBJ_SET_HP			$01
		OBJ_SET_SIZE		$06,$0E
		SJMP				byte_6A2BD
byte_6A28B:
		OBJ_SET_X_DELTA		$00
		NJSR				_native_sub160
byte_6A290:
		SYNC
		NJSR				_native_get_obj_var0D
		SBPL				byte_6A2A0
		SJSR				byte_6A589
		SBCC				byte_6A290
		SJMP				byte_6A2AE
byte_6A2A0:
		SJSR				byte_6806C
		OBJ_SET_X_DELTA		$10
		OBJ_SET_Y_DELTA		$8C
		NJSR				_native_sub029
		OBJ_SET_HP			$01
		VAR_1C_SET			$02
byte_6A2AE:
		NJSR				_native_sub11C
		NJSR				_native_sub161
		SJSR				byte_6A2CF
		NJSR				_far_players_animB_sub0129_G
		SBMI				byte_6A28B
byte_6A2BD:
		OBJ_SET_Y_DELTA		$E0
		SJSR				byte_6A2CF
		OBJ_SET_Y_DELTA		$F0
		SJSR				byte_6A2CF
		OBJ_SET_Y_DELTA		$F8
		SJSR				byte_6A2CF
		SJMP				byte_6A28B
byte_6A2CF:
		NJMP				_native_sub022
		OBJ_SET_HP			$01
		VAR_1C_SET			$02
		NJSR				_native_sub109
		SJSR				byte_6A557
		SBCS				byte_6A2CF
		SRET

; =============== S U B R O U T I N E =======================================
_native_sub022:
		LDA		#<[byte_6A2E7]
		LDY		#>[byte_6A2E7]
		JMP		_native_sub023

byte_6A2E7:
		.BYTE	$03,$00
		.BYTE	$04,$00
		.BYTE	$03,$40
		.BYTE	$04,$C0

; =============== S U B R O U T I N E =======================================
_native_sub023:
		STA		_tmp_ptr0
		STY		_tmp_ptr0+1
		LDA		_scr_vars16,X
		INC		_scr_vars16,X
		INC		_scr_vars16,X
		LSR
		LSR
		LSR
		AND		#$06
		TAY
		LDA		(_tmp_ptr0),Y
		STA		_obj_spr_idxs,X
		INY
		LDA		_obj_flips,X
		AND		#$3F
		ORA		(_tmp_ptr0),Y
		STA		_obj_flips,X
		RTS

; =============== O B J E C T   S C R I P T =================================
_obj_scr1E:
		SJSR				byte_6A268
		NJSR				_native_sub13B
		NJSR				_native_sub154
		OBJ_SET_FLIP		$20
		SPR_LIB_SELECT		$05
		SPR_IDX_SELECT		$08
		OBJ_SET_SIZE		$14,$0F
		OBJ_SET_HP			$01
		CHR_BANK			$01,$00
		PARAM_80_CLEAR
		OBJ_SET_Y_DELTA		$D7
		SJSR				_script_sub_68036
byte_6A330:
		NJMP				_native_sub162
		SBCS				byte_6A330
		SRUN				$01,_script136
		SUSPEND				$B0
		SRUN				$01,_script137
		SJMP				_script_idle

; =============== S C R I P T ===============================================
_script137:
		SRUN				$01,_script138
		NJMP				_native_sub117
		SUSPEND				$24
		OBJ_MOVE_X_POS		$C0
		OBJ_SET_SIZE		$40,$00
byte_6A351:
		NJMP				_native_sub024
		SJMP				byte_6A351

; =============== S U B R O U T I N E =======================================
_native_sub024:
		LDA		_obj_heigts,X
		BEQ		loc_6A370
		LDY		#$01
loc_6A35E:
		LDA		_obj_flips,Y
		AND		#$04
		BNE		loc_6A36D
		JSR		_obj_to_obj_collision_test
		BCC		loc_6A36D
		JSR		_player_kill
loc_6A36D:
		DEY
		BPL		loc_6A35E
loc_6A370:
		JSR		_native_get_obj_low_nibble_var1E
		LDA		_scr_loopsB,Y
		CMP		#$F6
		BCS		locret_6A3DD
		SEC
		SBC		#$26
		BCC		locret_6A3DD
		TAX
		AND		#$0F
		BNE		locret_6A3DD
		TXA
		LSR
		LSR
		LSR
		AND		#$1E
		PHA
		TAX
		LDA		word_6A3DE,X
		STA		_tmp_ptr44
		LDA		word_6A3DE+1,X
		STA		_tmp_ptr44+1
		LDA		#$12
		STA		_tmp_ptr2
		LDA		#<[_tlm15]
		LDY		#>[_tlm15]
		JSR		_far_prg3_tlm_queue
		PLA
		BEQ		locret_6A3DD
		CMP		#$06
		BCC		loc_6A3B3
		LDX		_scr_idx
		CLC
		LDA		_obj_heigts,X
		ADC		#$08
		STA		_obj_heigts,X
loc_6A3B3:
		CLC
		LDA		_tmp_ptr44
		ADC		#$20
		STA		_tmp_ptr44
		LDA		_tmp_ptr44+1
		ADC		#$00
		STA		_tmp_ptr44+1
		LDA		#$92
		STA		_tmp_ptr2
		LDA		#<[_tlm16]
		LDY		#>[_tlm16]
		JSR		_far_prg3_tlm_queue
		LDX		_scr_idx
		LDA		_scr_idxAs,X
		TAX
		SEC
		LDA		_obj_y_lo_poss,X
		SBC		#$08
		STA		_obj_y_lo_poss,X
		JSR		_native_sub163
locret_6A3DD:
		RTS
word_6A3DE:
		.WORD	$2328
		.WORD	$2308
		.WORD	$22E8
		.WORD	$22C8
		.WORD	$22A8
		.WORD	$2288
		.WORD	$2268
		.WORD	$2248
		.WORD	$2228
		.WORD	$2208
		.WORD	$21E8
		.WORD	$21C8
		.WORD	$21A8
		.WORD	$2288

; =============== S C R I P T ===============================================
_script138:
		OBJ_MOVE_X_POS		$86
		OBJ_MOVE_Y_POS		$B0
		OBJ_MOVE_Y_POS		$AF
		SPR_LIB_SELECT		$00
		SPR_IDX_SELECT		$10
byte_6A404:
		APU_LOAD			$4B
byte_6A406:
		NJMP				_native_sub025
		SBCC				_script_idle
		LOOPA				$28,byte_6A406
		SJMP				byte_6A404

; =============== S U B R O U T I N E =======================================
_native_sub025:
		LDA		_nmi_frames_counter
		AND		#$03
		TAY
		LDA		byte_6A455,Y
		STA		_tmp_ptr0
		LDA		#$94
		STA		_ram_buf0
		LDA		#$00
		STA		_ram_buf0+1
		STA		_ram_buf0+2
		LDX		#$00
loc_6A42C:
		LDA		_tmp_ptr0
		STA		_ram_buf0+3,X
		LDA		#$22
		STA		_ram_buf0+4,X
		INX
		INX
		CPX		#$28
		BCC		loc_6A42C
		LDA		#$00
		STA		_ram_buf0+3,X
		LDA		#<[_obj_spr_lib_insert]
		LDY		#>[_obj_spr_lib_insert]
		JSR		_farcall
		LDX		_scr_idx
		INC		_scr_loopsB,X
		LDA		_scr_loopsB,X
		CMP		#$F6
		JMP		_scr_flags_update
byte_6A455:
		.BYTE	$A8,$AA,$AC,$BF

; =============== S C R I P T ===============================================
_script136:
		STORE				$10,_pal_anim_mode_idx
		NJSR				_native_sub026
		OBJ_MOVE_Y_POS		$DA
		SPR_LIB_SELECT		$00
		PARAM_80_CLEAR
		OBJ_SET_X_DELTA		$E7
		OBJ_SET_Y_DELTA		$E8
byte_6A469:
		SJSR				byte_6A498
		LOOPB				$0F,byte_6A469
byte_6A470:
		OBJ_SET_X_DELTA		$00
		OBJ_SET_Y_DELTA		$00
		SJSR				byte_6A498
		SJSR				byte_6A498
		OBJ_SET_Y_DELTA		$20
		NJSR				_native_sub14C
		SJSR				byte_6A498
		OBJ_SET_Y_DELTA		$F0
		SJSR				byte_6A498
		SJSR				byte_6A498
		LOOPA				$03,byte_6A470
		NJSR				_native_sub12B
		OBJ_SET_X_DELTA		$E8
		OBJ_SET_Y_DELTA		$E8
		SJMP				byte_68092
byte_6A498:
		SPR_IDX_SELECT		$17
		JMP_OBJ_ANIMATE
		JMP_OBJ_ANIMATE
		JMP_OBJ_ANIMATE
		SPR_IDX_SELECT		$18
		JMP_OBJ_ANIMATE
		JMP_OBJ_ANIMATE
		JMP_OBJ_ANIMATE
		SRET

; =============== S U B R O U T I N E =======================================
_native_sub026:
		LDY		#$0B
loc_6A4A5:
		LDA		_scr_params,Y
		AND		#$0F
		BEQ		loc_6A4BA
		LDA		_obj_spr_idxs,Y
		CMP		#$09
		BNE		loc_6A4BA
		LDA		_obj_spr_libs,Y
		CMP		#$05
		BEQ		loc_6A4BE
loc_6A4BA:
		DEY
		JMP		loc_6A4A5
loc_6A4BE:
		TYA
		STA		_scr_idxCs,X
		RTS

; =============== O B J E C T   S C R I P T =================================
_obj_scr09:
		NJSR				_native_sub154
		NJSR				_scr_param_4_set
		SPR_LIB_SELECT		$05
		SPR_IDX_SELECT		$09
		SJSR				_script201
byte_6A4D0:
		NJSR				_native_sub139
byte_6A4D3:
		NJMP				_native_sub14E
		SBEQ				byte_6A4D3
		APU_LOAD			$69
		SUSPEND				$08
		SPR_IDX_SELECT		$0A
		SUSPEND				$04
		SPR_IDX_SELECT		$0B
		SUSPEND				$04
		SPR_IDX_SELECT		$09
		SJMP				byte_6A4D0

; =============== O B J E C T   S C R I P T =================================
_obj_scr07:
		DESTR_PC_SET		byte_6A59B
		NJSR				_native_sub139
		OBJ_MOVE_X_POS		$08
		SPR_LIB_SELECT		$04
		SPR_IDX_SELECT		$00
		OBJ_SET_SIZE		$06,$0E
		SJSR				_script201
byte_6A4FC:
		SPR_IDX_SELECT		$00
		OBJ_SET_FLIP		$00
		OBJ_SET_HP			$01
		OBJ_SET_X_DELTA		$00
		NJSR				_native_sub160
byte_6A507:
		SYNC
		NJSR				_native_get_obj_var0D
		SBPL				byte_6A517
		SJSR				byte_6A589
		SBCC				byte_6A507
		SJMP				byte_6A53E
byte_6A517:
		NJSR				_native_sub164
		NJSR				_native_sub134
byte_6A51D:
		NJSR				_native_get_obj_var0D
		SBMI				byte_6A535
		NJSR				_native_get_obj_hp
		SBNE				byte_6A52F
		NJMP				_native_sub02B
		SJMP				byte_6A51D
byte_6A52F:
		NJSR				_native_sub032
		SJMP				byte_6A4FC
byte_6A535:
		OBJ_SET_X_DELTA		$10
		OBJ_SET_Y_DELTA		$8C
		NJSR				_native_sub029
		APU_LOAD			$24
byte_6A53E:
		NJSR				_native_sub11C
		NJSR				_native_sub161
		OBJ_SET_HP			$FF
		VAR_1C_SET			$02
		SPR_IDX_SELECT		$00
byte_6A54A:
		SYNC
		NJSR				_native_sub109
		SJSR				byte_6A557
		SBCS				byte_6A54A
		SJMP				byte_6A4FC
byte_6A557:
		NJSR				_native_sub154
		NJSR				_obj_move_hor_animate
		NJSR				_native_sub13C
		SBCC				byte_6A569
		NJSR				_native_sub104
		SBCC				byte_6A56B
byte_6A569:
		OBJ_SET_X_DELTA		$00
byte_6A56B:
		NJSR				_native_sub109
		NJSR				_native_get_obj_y_delta
		SBMI				byte_6A589
		NJSR				_obj_vert_animate
		NJSR				_native_sub165
		SBCS				byte_6A583
		NJSR				_native_sub10A
		SBCC				byte_6A585
byte_6A583:
		OBJ_SET_Y_DELTA		$01
byte_6A585:
		NJSR				_scr_flags_flush_clc
		SRET
byte_6A589:
		NJSR				_obj_vert_animate
		NJSR				_native_sub107
		SBCC				byte_6A598
		NJSR				_native_sub118
		SBCS				byte_6A59A
byte_6A598:
		OBJ_SET_Y_DELTA		$00
byte_6A59A:
		SRET
byte_6A59B:
		NJSR				_native_sub154
		OBJ_SET_X_DELTA		$00
		NJSR				_native_get_obj_y_delta
		SBPL				byte_6A5A8
		OBJ_SET_Y_DELTA		$00
byte_6A5A8:
		SJSR				byte_6A5BA
		NJSR				_native_sub027
		SBCS				byte_6A5A8
		NJSR				_native_sub166
		SJSR				byte_6A5BA
		SJMP				byte_6A5A8
byte_6A5BA:
		SYNC
		NJSR				_native_get_obj_var0D
		SBMI				byte_6A5C4
		NJSR				_native_sub028
byte_6A5C4:
		SRET

; =============== S U B R O U T I N E =======================================
_native_sub027:
		LDA		_obj_y_deltas,X
		BPL		loc_6A5CE
		CMP		#$B0
		BCC		loc_6A5D7
loc_6A5CE:
		DEC		_obj_y_deltas,X
		DEC		_obj_y_deltas,X
		DEC		_obj_y_deltas,X
loc_6A5D7:
		JSR		_obj_vert_animate
		JSR		_players_animB_sub0129_sub12_A_B_A
		BCC		loc_6A5E3
		JSR		_players_animB_sub0129_sub12_A_B_B
		SEC
loc_6A5E3:
		JMP		_scr_flags_update

; =============== S U B R O U T I N E =======================================
_native_sub028:
		LDA		#$00
		STA		_obj_flips,X
		JMP		_native_sub033

; =============== S U B R O U T I N E =======================================
_native_sub029:
		LDA		_scr_idxBs,X
		AND		#$0F
		TAY
		LDA		_obj_flips,Y
		AND		#$40
		STA		_obj_flips,X
		JSR		_native_sub10F
		JMP		_native_sub167
_script46:
		DESTR_PC_SET		_script46
		NJSR				_native_sub134
		NJSR				_native_sub139
		SPR_LIB_SELECT		$03
		SPR_IDX_SELECT		$00
		OBJ_SET_SIZE		$06,$0F
		OBJ_SET_HP			$01
		PARAM_80_CLEAR
byte_6A615:
		NJSR				_native_get_obj_var0D
		SBMI				byte_6A630
		NJSR				_native_get_obj_hp
		SBEQ				byte_6A627
		NJSR				_native_sub033
		SJMP				byte_6A669
byte_6A627:
		NJSR				_native_sub02B
		NJMP				_native_sub02E
		SJMP				byte_6A615
byte_6A630:
		NJSR				_native_sub13A
		NJSR				_native_sub12B
		NJSR				_native_sub02A
		SBEQ				byte_6A653
		APU_LOAD			$27
		NJSR				_native_sub02F
		OBJ_SET_Y_DELTA		$F0
byte_6A643:
		SPR_IDX_SELECT		$00
		NJSR				_native_sub02E
		JMP_OBJ_ANIMATE
		LOOPA				$08,byte_6A643
		NJSR				_native_sub129
		SJMP				byte_6A643
byte_6A653:
		SPR_IDX_SELECT		$00
		APU_LOAD			$24
		NJSR				_native_sub030
byte_6A65A:
		JMP_OBJ_ANIMATE
		NJSR				_native_get_obj_hp
		SBMI				byte_6A666
		NJSR				_native_sub105
		OBJ_SET_HP			$01
byte_6A666:
		SBEQ				byte_6A65A
byte_6A669:
		NJMP				_native_sub15E
		SPR_IDX_SELECT		$03
		SYNC
		SPR_IDX_SELECT		$04
		SYNC
		SPR_IDX_SELECT		$05
		SYNC
		SPR_IDX_SELECT		$06
		SYNC
		SPR_IDX_SELECT		$07
		SYNC
		KILL

; =============== S U B R O U T I N E =======================================
_native_sub02A:
		LDA		_scr_vars1C,X
		CMP		#$02
		JMP		_scr_flags_update

; =============== S U B R O U T I N E =======================================
_native_sub02B:
		JSR		_native_sub031
		JSR		_players_animB_sub0129_sub06_C
		BMI		_native_sub02C
		BEQ		_native_sub02C
		LDA		#$80
		STA		_scr_params,X
		RTS

; =============== S U B R O U T I N E =======================================
_native_sub02C:
		LDA		_obj_heigts,Y
		BEQ		_native_sub02D
		JSR		_native_sub13A
		JMP		_scr_param_4_set

; =============== S U B R O U T I N E =======================================
_native_sub02D:
		INC		_obj_y_lo_poss,X
		JSR		_native_sub166
		JMP		_scr_param_4_clear

; =============== S U B R O U T I N E =======================================
_native_sub02E:
		LDA		_nmi_frames_counter
		AND		#$04
		BEQ		locret_6A6BA
		LDA		_scr_vars1C,X
		CMP		#$02
		BNE		locret_6A6BA
		LDA		#$08
		STA		_obj_spr_idxs,X
locret_6A6BA:
		RTS

; =============== S U B R O U T I N E =======================================
_native_sub02F:
		LDA		_scr_idxBs,X
		AND		#$0F
		TAX
		JMP		loc_6A6E5

; =============== S U B R O U T I N E =======================================
_native_sub030:
		LDA		#$01
		STA		_scr_vars1C,X
		STA		_obj_hps,X
		LDA		_scr_idxBs,X
		AND		#$0F
		TAX
		LDY		#$00
loc_6A6D4:
		LDA		_pads,X
		AND		byte_6A700,Y
		CMP		byte_6A700,Y
		BEQ		loc_6A6F1
		INY
		INY
		INY
		CPY		#$0F
		BCC		loc_6A6D4
loc_6A6E5:
		LDY		#$09
		LDA		_obj_flips,X
		AND		#$40
		BEQ		loc_6A6F1
		INY
		INY
		INY
loc_6A6F1:
		LDX		_scr_idx
		LDA		byte_6A700+1,Y
		STA		_obj_x_deltas,X
		LDA		byte_6A700+2,Y
		STA		_obj_y_deltas,X
		RTS
byte_6A700:
		.BYTE	$50,$C0,$C0
		.BYTE	$90,$40,$C0
		.BYTE	$10,$00,$A0
		.BYTE	$40,$C0,$00
		.BYTE	$80,$40,$00

; =============== S U B R O U T I N E =======================================
_native_sub031:
		JSR		_native_get_obj_low_nibble_var0D
		LDA		_players_vars09,Y
		STA		_obj_spr_idxs,X
		RTS

; =============== S U B R O U T I N E =======================================
_native_sub032:
		JSR		_native_get_obj_low_nibble_var0D
		LDA		_obj_y_lo_poss,Y
		STA		_obj_y_lo_poss,X
		CLC
		SBC		_obj_heigts,X
		STA		_obj_y_lo_poss,Y

; =============== S U B R O U T I N E =======================================
_native_sub033:
		LDA		_scr_idxBs,X
		AND		#$7F
		STA		_scr_idxBs,X
		JSR		_native_get_obj_low_nibble_var0D
		LDA		_scr_idxBs,Y
		AND		#$BF
		STA		_scr_idxBs,Y
		RTS
_script40:
		SPR_LIB_SELECT		$00
		SPR_IDX_SELECT		$0F
		OBJ_SET_FLIP		$0C
		PARAM_80_CLEAR
byte_6A744:
		OBJ_SET_X_DELTA		$00
		OBJ_SET_Y_DELTA		$00
		SJSR				byte_6A77C
		OBJ_SET_X_DELTA		$C0
		OBJ_SET_Y_DELTA		$00
		SJSR				byte_6A77C
		OBJ_SET_X_DELTA		$A0
		OBJ_SET_Y_DELTA		$E0
		SJSR				byte_6A77C
		OBJ_SET_X_DELTA		$C0
		OBJ_SET_Y_DELTA		$B0
		SJSR				byte_6A77C
		OBJ_SET_X_DELTA		$00
		OBJ_SET_Y_DELTA		$B0
		SJSR				byte_6A77C
		OBJ_SET_X_DELTA		$40
		OBJ_SET_Y_DELTA		$B0
		SJSR				byte_6A77C
		OBJ_SET_X_DELTA		$60
		OBJ_SET_Y_DELTA		$E0
		SJSR				byte_6A77C
		OBJ_SET_X_DELTA		$40
		OBJ_SET_Y_DELTA		$00
		SJMP				byte_6A744
byte_6A77C:
		NJSR				_native_sub04A_A
		JMP_OBJ_ANIMATE
		LOOPA				$04,byte_6A77C
		SRET

; =============== O B J E C T   S C R I P T =================================
_obj_scr08:
		NJSR				_native_sub154
		OBJ_MOVE_X_POS		$08
		SPR_LIB_SELECT		$05
		SPR_IDX_SELECT		$00
		OBJ_SET_SIZE		$08,$07
		OBJ_SET_HP			$01
		PARAM_80_CLEAR
		SJSR				_script20D
		SPR_IDX_SELECT		$01
		OBJ_SET_SIZE		$08,$04
		NJSR				_native_sub169
		SJSR				_script20D
		SPR_IDX_SELECT		$02
		OBJ_SET_SIZE		$08,$02
		NJSR				_native_sub169
		SJSR				_script20D
		SPR_IDX_SELECT		$03
		OBJ_SET_SIZE		$08,$0F
		NJSR				_native_sub169
		APU_LOAD			$4A
		OBJ_SET_X_DELTA		$10
		OBJ_SET_Y_DELTA		$C0
byte_6A7BB:
		JMP_OBJ_ANIMATE
		NJSR				_native_sub109
		NJSR				_native_sub162
		SBCS				byte_6A7BB
		NJSR				_native_sub169
		SJMP				byte_6A7BB

; =============== O B J E C T   S C R I P T =================================
_obj_scr0A:
		SJSR				byte_6A7F1
		SJSR				byte_6A7FF
		SRUN				$01,_script139
byte_6A7D5:
		SJSR				byte_6A812
		SJSR				byte_6A7FF
		SJMP				byte_6A7D5

; =============== S C R I P T ===============================================
_script139:
		STORE				<[tlm_patch06],_tmp_ptr4B
		STORE				>[tlm_patch06],_tmp_ptr4B+1
		SJSR				_script20C
		APU_LOAD			$4E
		SUSPEND				$08
		SJSR				_script20C
		KILL
byte_6A7F1:
		NJSR				_native_sub154
		SPR_LIB_SELECT		$05
		SPR_IDX_SELECT		$0C
		OBJ_SET_SIZE		$05,$0D
		OBJ_SET_HP			$01
		PARAM_80_CLEAR
		SRET
byte_6A7FF:
		SYNC
		NJSR				_native_sub162
		SBCS				byte_6A7FF
		SPR_IDX_SELECT		$0D
		OBJ_SET_SIZE		$05,$08
		NJSR				_native_sub169
		NJSR				_native_sub139
		SRET
byte_6A812:
		SYNC
		NJSR				_native_sub162
		SBCC				byte_6A812
byte_6A819:
		NJSR				_native_sub16A
		SUSPEND				$08
		SPR_IDX_SELECT		$0E
		OBJ_SET_SIZE		$05,$0A
		NJSR				_native_sub162
		SBCS				byte_6A82D
		NJSR				_native_sub169
		SRET
byte_6A82D:
		SUSPEND				$04
		SPR_IDX_SELECT		$0C
		OBJ_SET_SIZE		$05,$0D
		NJSR				_native_sub162
		SBCS				byte_6A83D
		NJSR				_native_sub169
byte_6A83D:
		SRET

; =============== O B J E C T   S C R I P T =================================
_obj_scr0B:
		SJSR				byte_6A7F1
		SRUN				$09,_script13A
		NJSR				_native_sub117
		NJSR				_native_sub134
		OBJ_MOVE_X_POS		$50
byte_6A84D:
		SJSR				byte_6A7FF
byte_6A850:
		NJSR				_native_sub14C
		SBEQ				byte_6A863
		NJSR				_native_sub162
		SYNC
		SBCC				byte_6A850
		SJSR				byte_6A819
		SJMP				byte_6A84D
byte_6A863:
		STORE				<[tlm_patch07],_tmp_ptr4B
		STORE				>[tlm_patch07],_tmp_ptr4B+1
		SJSR				_script20C
		SRUN				$0A,_script13B
		APU_LOAD			$4F
byte_6A874:
		SJSR				byte_6A812
		SJSR				byte_6A7FF
		SJMP				byte_6A874

; =============== S C R I P T ===============================================
_script13B:
		OBJ_MOVE_X_POS		$D0
		SJMP				byte_6A189

; =============== S C R I P T ===============================================
_script13A:
		SJSR				byte_6A7F1
		NJSR				_native_sub134
byte_6A888:
		SJSR				byte_6A7FF
		SJSR				byte_6A812
		SJMP				byte_6A888

; =============== O B J E C T   S C R I P T =================================
_obj_scr0C:
		SJSR				byte_6A7F1
		SJSR				byte_6A7FF
		STORE				<[tlm_patch08],_tmp_ptr4B
		STORE				>[tlm_patch08],_tmp_ptr4B+1
		SJSR				_script20C
		SRUN				$0A,_script13C
		APU_LOAD			$4F
byte_6A8A8:
		SJSR				byte_6A812
		SJSR				byte_6A7FF
		SJMP				byte_6A8A8

; =============== S C R I P T ===============================================
_script13C:
		OBJ_MOVE_X_POS		$C0
		OBJ_MOVE_X_POS		$B0
		SJMP				_obj_scr22

; =============== O B J E C T   S C R I P T =================================
_obj_scr0D:
		SJSR				_script202
byte_6A8BB:
		SRUN				$01,_script13D
		SUSPEND				$5A
		SRUN				$01,_script13E
		SUSPEND				$5A
		SJMP				byte_6A8BB

; =============== S C R I P T ===============================================
_script13D:
		OBJ_MOVE_X_POS		$E0

; =============== S C R I P T ===============================================
_script13E:
		PARAM_40_SET
		OBJ_MOVE_X_POS		$10
		SPR_LIB_SELECT		$05
		PARAM_80_CLEAR
		OBJ_SET_Y_DELTA		$E0
		NJSR				_native_sub12B
		NJSR				_native_sub13D
		SBCC				byte_6A8EC
byte_6A8DD:
		SPR_IDX_SELECT		$12
		OBJ_DEC_Y_DELTA
		JMP_OBJ_ANIMATE
		JMP_OBJ_ANIMATE
		JMP_OBJ_ANIMATE
		SPR_IDX_SELECT		$1A
		OBJ_DEC_Y_DELTA
		JMP_OBJ_ANIMATE
		JMP_OBJ_ANIMATE
		JMP_OBJ_ANIMATE
		SJMP				byte_6A8DD
byte_6A8EC:
		KILL

; =============== O B J E C T   S C R I P T =================================
_obj_scr0E:
		NJSR				_native_sub16B
		SBEQ				byte_6A8FD
byte_6A8F3:
		NJSR				_native_sub157
		LOOPA				$05,byte_6A8F3
		NJSR				_MAIN_START
byte_6A8FD:
		NJSR				_native_bonus_room_3prizes_shuffle
		OBJ_SET_X_POS		$38,$00
byte_6A903:
		NJSR				_native_sub034
		SRUN				$09,_script13F
		LOOPA				$03,byte_6A903
		NJSR				_native_sub150
		NJSR				_native_bonus_room_3prizes_shuffle
		OBJ_SET_X_POS		$C8,$00
byte_6A917:
		NJSR				_native_sub034
		SRUN				$09,_script13F
		LOOPA				$03,byte_6A917
		NJSR				_native_sub14B
byte_6A925:
		NJMP				_native_sub035
		SBNE				byte_6A925
		STORE				<[tlm_patch09],_tmp_ptr4B
		STORE				>[tlm_patch09],_tmp_ptr4B+1
		SJSR				_script20C
		NJSR				_native_sub16C
		OBJ_SET_X_POS		$F0,$00
		OBJ_SET_Y_POS		$C0,$00
		PARAM_80_SET
		APU_LOAD			$23
		SJMP				_obj_scr21

; =============== S U B R O U T I N E =======================================
_native_sub034:
		JSR		_native_get_bonus_room_prize_from_list
		LDY		_tmp_ptrE+1
		LDA		byte_6A951,Y
		STA		_obj_y_lo_poss,X
		RTS
byte_6A951:
		.BYTE	$40,$80,$C0

; =============== S U B R O U T I N E =======================================
_native_sub035:
		LDY		_scr_idxBs,X
		LDA		_scr_idxBs,Y
		LDY		_scr_idxCs,X
		AND		_scr_idxBs,Y
		AND		#$10
		JMP		_scr_flags_update

; =============== S C R I P T ===============================================
_script13F:
		NJSR				_native_sub154
		SPR_LIB_SELECT		$05
		SPR_IDX_SELECT		$14
		OBJ_SET_SIZE		$05,$0C
		OBJ_SET_HP			$01
		PARAM_80_CLEAR
byte_6A972:
		SYNC
		NJSR				_native_sub162
		SBCS				byte_6A972
		SPR_IDX_SELECT		$15
		OBJ_SET_SIZE		$05,$06
		NJSR				_native_sub169
		NJSR				_native_sub139
byte_6A984:
		SYNC
		NJSR				_native_sub162
		SBCC				byte_6A984
		NJSR				_native_sub16A
		SUSPEND				$08
		SPR_IDX_SELECT		$16
		OBJ_SET_SIZE		$05,$08
		NJSR				_native_sub162
		SBCS				byte_6A99E
		NJSR				_native_sub169
byte_6A99E:
		SUSPEND				$04
		SPR_IDX_SELECT		$14
		OBJ_SET_SIZE		$05,$0C
		NJSR				_native_sub162
		SBCS				byte_6A9AE
		NJSR				_native_sub169
byte_6A9AE:
		SJMP				byte_6A972

; =============== O B J E C T   S C R I P T =================================
_obj_scr0F:
		OBJ_MOVE_X_POS		$FD
		OBJ_MOVE_Y_POS		$03
		TARGET_DIR_SET		$20
		SJSR				byte_6AA22
byte_6A9BA:
		SJSR				byte_6AA11
byte_6A9BD:
		SJSR				byte_6AA31
		LOOPA				$84,byte_6A9BD
		SJSR				byte_6AA11
byte_6A9C7:
		SJSR				byte_6AA31
		LOOPA				$84,byte_6A9C7
		SJMP				byte_6A9BA

; =============== O B J E C T   S C R I P T =================================
_obj_scr10:
		OBJ_MOVE_X_POS		$03
		OBJ_MOVE_Y_POS		$05
		TARGET_DIR_SET		$00
		SJSR				byte_6AA22
byte_6A9DA:
		SJSR				byte_6AA11
byte_6A9DD:
		SJSR				byte_6AA31
		LOOPA				$84,byte_6A9DD
		SJSR				byte_6AA11
byte_6A9E7:
		SJSR				byte_6AA31
		LOOPA				$84,byte_6A9E7
		SJMP				byte_6A9DA

; =============== O B J E C T   S C R I P T =================================
_obj_scr11:
		OBJ_MOVE_X_POS		$03
		OBJ_MOVE_Y_POS		$05
		TARGET_DIR_SET		$00
		SJSR				byte_6AA22
byte_6A9FA:
		SJSR				byte_6AA11
byte_6A9FD:
		SJSR				byte_6AA31
		LOOPA				$58,byte_6A9FD
		SJSR				byte_6AA11
byte_6AA07:
		SJSR				byte_6AA31
		LOOPA				$58,byte_6AA07
		SJMP				byte_6A9FA
byte_6AA11:
		NJSR				_native_sub123
		NJSR				_native_sub124
		NJSR				_native_sub126
		SJSR				byte_6AA31
		LOOPA				$40,byte_6AA11
		SRET
byte_6AA22:
		NJSR				_native_sub154
		SPR_LIB_SELECT		$05
		SPR_IDX_SELECT		$13
		OBJ_SET_SIZE		$10,$0E
		OBJ_SET_HP			$01
		SJMP				_script201
byte_6AA31:
		SYNC
		JSR_OBJ_ANIMATE
		NJSR				_native_sub16D
		NJSR				_native_sub163
		SRET

; =============== O B J E C T   S C R I P T =================================
_obj_scr05:
		OBJ_MOVE_X_POS		$08
		SPR_LIB_SELECT		$05
		SPR_IDX_SELECT		$46
		SJSR				_script201
byte_6AA43:
		SUSPEND				$10
		SPR_IDX_SELECT		$47
		SUSPEND				$10
byte_6AA49:
		SPR_IDX_SELECT		$46
		APU_LOAD			$50
		SJMP				byte_6AA43

; =============== O B J E C T   S C R I P T =================================
_obj_scr06:
		NJSR				_scr_param_4_set
		NJSR				_native_sub134
byte_6AA56:
		SJSR				byte_6AA67
		STORE				$05,_pal_anim_mode_idx
		SJSR				byte_6AA67
		STORE				$07,_pal_anim_mode_idx
		SJMP				byte_6AA56
byte_6AA67:
		SUSPEND				$F0
		SUSPEND				$F0
		APU_LOAD			$35
		SRET

; =============== O B J E C T   S C R I P T =================================
_obj_scr3E:
		OBJ_MOVE_X_POS		$F8
		OBJ_MOVE_Y_POS		$FC
		SJSR				_script202
byte_6AA75:
		NJMP				_native_sub036
		SBNE				byte_6AA75
byte_6AA7B:
		NJMP				_native_sub036
		SBEQ				byte_6AA7B
		SRUN				$06,_script140
		SJMP				byte_6AA75

; =============== S U B R O U T I N E =======================================
_native_sub036:
		LDA		_pal_anim_mode_idx
		CMP		#$05
		JMP		_scr_flags_update

; =============== S C R I P T ===============================================
_script140:
		SPR_LIB_SELECT		$07
		PARAM_80_CLEAR
		TARGET_LOCK			$20
		OBJ_SET_SIZE		$0C,$14
byte_6AA97:
		OBJ_SET_HP			$7F
		VAR_1C_SET			$01
		TARGET_DIR_SET		$00
		SJSR				byte_6AAC1
		LOOPA				$14,byte_6AA97
		NJSR				_native_sub10E
		NJSR				_native_sub111
		APU_LOAD			$36
byte_6AAAC:
		TARGET_DIR_SET		$FF
		SJSR				byte_6AAC1
		LOOPA				$14,byte_6AAAC
		LOOPB				$03,byte_6AA97
byte_6AAB9:
		TARGET_DIR_SET		$FF
		SJSR				byte_6AAC1
		SJMP				byte_6AAB9
byte_6AAC1:
		SPR_IDX_SELECT		$5A
		SJSR				byte_6AACE
		SJSR				byte_6AACE
		SPR_IDX_SELECT		$5B
		SJSR				byte_6AACE
byte_6AACE:
		NJSR				_scr_param_4_clear
		TARGET_FOLLOW
		SYNC
		SRET

; =============== O B J E C T   S C R I P T =================================
_obj_scr12:
		NJSR				_native_sub154
		OBJ_MOVE_Y_POS		$EC
		SRUN				$01,_script141
		NJSR				_native_sub117
		OBJ_SET_HP			$01
		OBJ_SET_SIZE		$16,$01
		SPR_LIB_SELECT		$05
		SPR_IDX_SELECT		$33
		PARAM_80_CLEAR
byte_6AAEA:
		SPR_IDX_SELECT		$33
		SJSR				byte_6AAFD
		NJSR				_native_get_obj_x_delta
		SBNE				byte_6AAEA
		SPR_IDX_SELECT		$34
		SJSR				byte_6AAFD
		SJMP				byte_6AAEA
byte_6AAFD:
		SYNC
		NJSR				_native_sub038
		SBNE				byte_6AB0A
		NJSR				_native_sub109
		SJMP				byte_6AB0F
byte_6AB0A:
		OBJ_SET_Y_DELTA		$00
		NJSR				_native_sub037
byte_6AB0F:
		JSR_OBJ_ANIMATE
		NJSR				_native_sub16D
		LOOPA				$04,byte_6AAFD
		SRET

; =============== S U B R O U T I N E =======================================
_native_sub037:
		LDA		_obj_y_lo_poss,X
		AND		#$F0
		ORA		#$0C
		STA		_obj_y_lo_poss,X
		RTS

; =============== S U B R O U T I N E =======================================
_native_sub038:
		STX		byte_E3
		SEC
		LDA		_obj_x_lo_poss,X
		SBC		#$10
		STA		_tmp_ptr0
		LDA		_obj_x_hi_poss,X
		SBC		#$00
		STA		_tmp_ptr0+1
		CLC
		LDA		_obj_y_lo_poss,X
		ADC		#$14
		STA		_tmp_ptr2
		LDA		_obj_y_hi_poss,X
		ADC		#$00
		STA		_tmp_ptr2+1
		JSR		_obj_sys_calc00
		CPX		#$8F
		JMP		_scr_flags_update

; =============== S C R I P T ===============================================
_script141:
		OBJ_SET_FLIP		$08
		NJSR				_native_sub134
		OBJ_SET_HP			$01
		OBJ_SET_SIZE		$01,$08
byte_6AB55:
		SPR_LIB_SELECT		$01
		SPR_IDX_SELECT		$12
		PARAM_80_CLEAR
byte_6AB5A:
		SJSR				byte_6ABA9
		NJSR				_native_sub03D
		SBCS				byte_6AB5A
		SPR_IDX_SELECT		$13
		SJSR				byte_6AB98
byte_6AB68:
		SJSR				byte_6ABA9
		NJSR				_native_sub03E
		SBCS				byte_6AB77
		NJSR				_native_sub03B
		SJMP				byte_6AB55
byte_6AB77:
		NJSR				_native_sub03C
		SBNE				byte_6AB90
		SBCS				byte_6AB88
		SPR_IDX_SELECT		$14
		NJSR				_native_sub039
		SJMP				byte_6AB68
byte_6AB88:
		SPR_IDX_SELECT		$15
		NJSR				_native_sub03B
		SJMP				byte_6AB68
byte_6AB90:
		SPR_IDX_SELECT		$13
		NJSR				_native_sub03A
		SJMP				byte_6AB68
byte_6AB98:
		SJSR				byte_6ABA9
		NJSR				_native_sub03E
		SBCC				byte_6ABA6
		LOOPA				$08,byte_6AB98
		SRET
byte_6ABA6:
		BREAK				byte_6AB55
byte_6ABA9:
		NJSR				_native_sub04A_A
		OBJ_MOVE_X_POS		$06
		SYNC
		SRET

; =============== S U B R O U T I N E =======================================
_native_sub039:
		LDA		#$30
		BNE		_native_sub03B_ex

; =============== S U B R O U T I N E =======================================
_native_sub03A:
		LDA		#$20
		BNE		_native_sub03B_ex

; =============== S U B R O U T I N E =======================================
_native_sub03B:
		LDA		#$10

; =============== S U B R O U T I N E =======================================
_native_sub03B_ex:
		PHA
		JSR		_native_get_obj_low_nibble_var1E
		PLA
		STA		_obj_x_deltas,Y
		RTS

; =============== S U B R O U T I N E =======================================
_native_sub03C:
		LDY		_scr_idxAs,X
		LDA		_pads,Y
		AND		#$C0
		BEQ		loc_6ABD5
		SEC
		AND		#$80
		BNE		loc_6ABD5
		CLC
		LDA		#$FF
loc_6ABD5:
		JMP		_scr_flags_update

; =============== S U B R O U T I N E =======================================
_native_sub03D:
		LDY		#$01
loc_6ABDA:
		LDA		_obj_flips,Y
		AND		#$04
		BNE		loc_6AC1F
		LDA		_players_vars0D,Y
		BNE		loc_6AC1F
		LDA		_scr_idxBs,Y
		AND		#$40
		BNE		loc_6AC1F
		LDA		_players_states,Y
		CMP		#$05
		BNE		loc_6AC1F
		LDA		_players_states,Y
		CMP		#$13
		BCS		loc_6AC1F
		JSR		_native_sub03E_A
		BCS		loc_6AC1F
		LDA		_obj_x_lo_poss,X
		STA		_obj_x_lo_poss,Y
		LDA		_obj_x_hi_poss,X
		STA		_obj_x_hi_poss,Y
		LDA		_obj_spr_libs,Y
		STA		_obj_spr_libs,X
		TYA
		STA		_scr_idxAs,X
		LDA		#$13
		STA		_players_states,Y
		SEC
		JMP		_scr_flags_update
loc_6AC1F:
		DEY
		BPL		loc_6ABDA
		CLC
		JMP		_scr_flags_update

; =============== S U B R O U T I N E =======================================
_native_sub03E:
		LDY		_scr_idxAs,X
		LDA		_players_states,Y
		CMP		#$13
		BNE		loc_6AC3F
		JSR		_native_sub03E_A
		BCC		loc_6AC40
		LDA		#$05
		STA		_players_states,Y
		LDA		#$00
		STA		_players_vars0A,Y
loc_6AC3F:
		SEC
loc_6AC40:
		JMP		_scr_flags_update

; =============== S U B R O U T I N E =======================================
_native_sub03E_A:
		LDA		_obj_y_lo_poss,X
		CMP		_obj_y_lo_poss,Y
		BNE		loc_6AC74
		LDA		_obj_y_hi_poss,X
		CMP		_obj_y_hi_poss,Y
		BNE		loc_6AC74
		SEC
		LDA		_obj_x_lo_poss,X
		SBC		_obj_x_lo_poss,Y
		STA		_tmp_ptr0
		LDA		_obj_x_hi_poss,X
		SBC		_obj_x_hi_poss,Y
		BEQ		loc_6AC6F
		CMP		#$FF
		BNE		loc_6AC74
		SEC
		LDA		#$00
		SBC		_tmp_ptr0
		STA		_tmp_ptr0
loc_6AC6F:
		LDA		_tmp_ptr0
		CMP		#$04
		RTS
loc_6AC74:
		SEC
		RTS

; =============== O B J E C T   S C R I P T =================================
_obj_scr13:
		NJSR				_native_sub13E
		NJSR				_native_sub154
		OBJ_SET_HP			$01
		VAR_1C_SET			$01
		OBJ_SET_SIZE		$09,$12
		SPR_LIB_SELECT		$05
		SPR_IDX_SELECT		$38
		SJSR				_script201
byte_6AC8A:
		NJMP				_native_sub116
		SBCC				byte_6AC8A
		OBJ_SET_Y_DELTA		$18
		APU_LOAD			$71
		SJMP				byte_68096

; =============== O B J E C T   S C R I P T =================================
_obj_scr04:
		SPR_LIB_SELECT		$05
		SPR_IDX_SELECT		$45
		PARAM_80_CLEAR
		SRUN				$07,_script142
		NJSR				_native_sub117
byte_6ACA3:
		APU_LOAD			$5E
		SPR_IDX_SELECT		$45
		SUSPEND				$08
		SPR_IDX_SELECT		$44
		SUSPEND				$09
		SPR_IDX_SELECT		$43
		SUSPEND				$0B
		SPR_IDX_SELECT		$42
		SUSPEND				$0E
		SPR_IDX_SELECT		$43
		SUSPEND				$0B
		SPR_IDX_SELECT		$44
		SUSPEND				$09
		FLIP_40_TOGGLE
		SJMP				byte_6ACA3

; =============== S C R I P T ===============================================
_script142:
		NJSR				_native_sub134
		OBJ_SET_SIZE		$06,$0C
		OBJ_SET_HP			$01
		VAR_1C_SET			$01
		SPR_LIB_SELECT		$05
		SPR_IDX_SELECT		$41
		PARAM_80_CLEAR
byte_6ACD0:
		NJMP				_native_sub03F
		SJMP				byte_6ACD0

; =============== S U B R O U T I N E =======================================
_native_sub03F:
		JSR		_native_get_obj_low_nibble_var1E
		SEC
		LDA		_obj_spr_idxs,Y
		SBC		#$42
		TAX
		LDA		byte_6AD24,X
		STA		_tmp_ptr0
		LDA		byte_6AD28,X
		LDX		_scr_idx
		CLC
		ADC		_obj_y_lo_poss,Y
		STA		_obj_y_lo_poss,X
		LDA		_obj_y_hi_poss,Y
		ADC		#$00
		STA		_obj_y_hi_poss,X
		LDA		_obj_flips,Y
		AND		#$40
		BEQ		loc_6AD12
		CLC
		LDA		_obj_x_lo_poss,Y
		ADC		_tmp_ptr0
		STA		_obj_x_lo_poss,X
		LDA		_obj_x_hi_poss,Y
		ADC		#$00
		STA		_obj_x_hi_poss,X
		RTS
loc_6AD12:
		SEC
		LDA		_obj_x_lo_poss,Y
		SBC		_tmp_ptr0
		STA		_obj_x_lo_poss,X
		LDA		_obj_x_hi_poss,Y
		SBC		#$00
		STA		_obj_x_hi_poss,X
		RTS
byte_6AD24:
		.BYTE	$25,$20,$16,$00
byte_6AD28:
		.BYTE	$27,$2C,$34,$39

; =============== O B J E C T   S C R I P T =================================
_obj_scr16:
		NJSR				_native_sub154
		OBJ_SET_HP			$01
		OBJ_SET_SIZE		$05,$08
		SPR_LIB_SELECT		$05
		PARAM_80_CLEAR
		NJSR				_native_sub040
		SBNE				byte_6AD4F
		SJMP				byte_6AD5C
byte_6AD40:
		NJMP				_native_sub041
		SBCS				byte_6AD40
		NJSR				_native_sub040
		SBEQ				byte_6AD4F
		SJMP				byte_6AD5C
byte_6AD4F:
		SPR_IDX_SELECT		$2B
		STORE				$0C,_pal_anim_mode_idx
		STORE				$04,byte_7F
		SJMP				byte_6AD40
byte_6AD5C:
		SPR_IDX_SELECT		$2C
		STORE				$0E,_pal_anim_mode_idx
		STORE				$05,byte_7F
		SJMP				byte_6AD40

; =============== S U B R O U T I N E =======================================
_native_sub040:
		LDA		byte_7F
		CMP		#$04
		JMP		_scr_flags_update

; =============== S U B R O U T I N E =======================================
_native_sub041:
		LDY		#$0B
loc_6AD72:
		LDA		_scr_params,Y
		AND		#$0F
		CMP		#$03
		BNE		loc_6AD8C
		LDA		_obj_spr_libs,Y
		CMP		#$03
		BNE		loc_6AD8C
		LDA		_scr_idxBs,Y
		BMI		loc_6AD8C
		JSR		_obj_to_obj_collision_test
		BCS		loc_6AD92
loc_6AD8C:
		DEY
		BPL		loc_6AD72
		JMP		_scr_flags_flush_clc
loc_6AD92:
		LDA		_scr_vars1C,Y
		CMP		#$02
		BEQ		loc_6AD9E
		LDA		#$00
		STA		_obj_hps,Y
loc_6AD9E:
		JMP		_scr_flags_flush_sec

; =============== O B J E C T   S C R I P T =================================
_obj_scr14:
		NJSR				_native_sub154
		OBJ_MOVE_X_POS		$08
		OBJ_SET_FLIP		$20
		SPR_LIB_SELECT		$05
		SPR_IDX_SELECT		$04
		OBJ_SET_HP			$01
		PARAM_80_CLEAR
		OBJ_SET_SIZE		$10,$0F
		SJSR				_script201
byte_6ADB5:
		OBJ_SET_Y_DELTA		$F0
byte_6ADB7:
		SJSR				byte_6ADDD
		LOOPA				$16,byte_6ADB7
byte_6ADBE:
		NJMP				_obj_vert_animate
		LOOPA				$0A,byte_6ADBE
		SUSPEND				$78
		OBJ_SET_Y_DELTA		$40
		NJMP				_obj_vert_animate
		NJMP				_obj_vert_animate
byte_6ADCF:
		SJSR				byte_6ADDD
		LOOPA				$06,byte_6ADCF
		APU_LOAD			$51
		SUSPEND				$78
		SJMP				byte_6ADB5
byte_6ADDD:
		SYNC
		NJSR				_obj_vert_animate
		NJSR				_native_sub16E
		SBCC				byte_6ADEA
		NJSR				_native_sub042
byte_6ADEA:
		SRET

; =============== S U B R O U T I N E =======================================
_native_sub042:
		LDY		byte_AB
		LDA		_obj_flips,Y
		AND		#$04
		BNE		locret_6ADF7
		JMP		_player_kill
locret_6ADF7:
		RTS

; =============== O B J E C T   S C R I P T =================================
_obj_scr15:
		NJSR				_native_sub154
		SPR_LIB_SELECT		$05
		OBJ_SET_HP			$01
		PARAM_80_CLEAR
byte_6AE00:
		SPR_IDX_SELECT		$2E
		OBJ_SET_SIZE		$10,$0F
byte_6AE05:
		NJMP				_native_sub162
		SBCS				byte_6AE05
		SPR_IDX_SELECT		$39
		SUSPEND				$78
		OBJ_SET_SIZE		$00,$00
		SPR_IDX_SELECT		$22
		SUSPEND				$08
		SPR_IDX_SELECT		$23
		SUSPEND				$1E
		SPR_IDX_SELECT		$22
		SUSPEND				$04
		SPR_IDX_SELECT		$39
		SUSPEND				$04
		SJMP				byte_6AE00

; =============== O B J E C T   S C R I P T =================================
_obj_scr3B:
		OBJ_MOVE_X_POS		$08
		SPR_LIB_SELECT		$05
		OBJ_SET_SIZE		$02,$30
byte_6AE2C:
		PARAM_80_CLEAR
byte_6AE2D:
		APU_LOAD			$53
		SPR_IDX_SELECT		$29
		SJSR				byte_6AE46
		SPR_IDX_SELECT		$2A
		SJSR				byte_6AE46
		LOOPA				$1E,byte_6AE2D
		PARAM_80_SET
		NJSR				_scr_param_4_set
		SUSPEND				$78
		SJMP				byte_6AE2C
byte_6AE46:
		OBJ_SET_HP			$01
		VAR_1C_SET			$01
		NJMP				_scr_param_4_clear
		LOOPB				$02,byte_6AE46
		SRET

; =============== O B J E C T   S C R I P T =================================
_obj_scr17:
		NJSR				_native_sub154
		SPR_LIB_SELECT		$05
		SPR_IDX_SELECT		$2D
		OBJ_SET_SIZE		$08,$10
		SJSR				_script201
byte_6AE5F:
		NJMP				_native_sub043
		SJMP				byte_6AE5F

; =============== S U B R O U T I N E =======================================
_native_sub043:
		LDY		#$0B
loc_6AE67:
		LDA		_scr_params,Y
		AND		#$0F
		BEQ		loc_6AEC9
		LDA		_obj_spr_libs,Y
		CMP		#$04
		BNE		loc_6AEC9
		LDA		_scr_destr_hi_pcs,Y
		BEQ		locret_6AECC
		STY		byte_96
		LDX		byte_96
		JSR		_far_players_animB_sub0129_sub16_E
		LDX		_scr_idx
		LDY		byte_96
		BCS		locret_6AECC
		SEC
		LDA		_obj_y_lo_poss,Y
		SBC		_obj_heigts,Y
		CMP		_obj_y_lo_poss,X
		BCC		locret_6AECC
		SEC
		LDA		_obj_x_lo_poss,X
		SBC		_obj_x_lo_poss,Y
		STA		_tmp_ptr0
		LDA		_obj_x_hi_poss,X
		SBC		_obj_x_hi_poss,Y
		BEQ		loc_6AEB1
		CMP		#$FF
		BNE		locret_6AECC
		CLC
		LDA		_tmp_ptr0
		ADC		#$0C
		BCC		locret_6AECC
		BCS		loc_6AEB7
loc_6AEB1:
		LDA		_tmp_ptr0
		CMP		#$0C
		BCS		locret_6AECC
loc_6AEB7:
		LDA		_scr_destr_hi_pcs,Y
		STA		_scr_hi_pcs,Y
		LDA		_scr_destr_lo_pcs,Y
		STA		_scr_lo_pcs,Y
		LDA		#$00
		STA		_scr_destr_hi_pcs,Y
		RTS
loc_6AEC9:
		DEY
		BPL		loc_6AE67
locret_6AECC:
		RTS

; =============== O B J E C T   S C R I P T =================================
_obj_scr18:
		NJSR				_native_sub154
		OBJ_SET_HP			$01
		SPR_LIB_SELECT		$05
		SPR_IDX_SELECT		$31
		SJSR				_script201
		OBJ_SET_X_DELTA		$F0
byte_6AEDB:
		SPR_IDX_SELECT		$30
		SUSPEND				$08
		SPR_IDX_SELECT		$2F
		SUSPEND				$08
byte_6AEE3:
		NJSR				_native_sub138
		SBCC				byte_6AEED
		SRUN				$07,_script143
byte_6AEED:
		SJSR				_script_animate32
		NJSR				_native_sub105
		NJSR				_native_sub16F
		SBCC				byte_6AEE3
		SPR_IDX_SELECT		$30
		SUSPEND				$08
		SPR_IDX_SELECT		$31
		SUSPEND				$08
byte_6AF01:
		NJSR				_native_sub138
		SBCC				byte_6AF0B
		SRUN				$07,_script144
byte_6AF0B:
		SJSR				_script_animate32
		NJSR				_native_sub105
		NJSR				_native_sub16F
		SBCS				byte_6AF01
		SJMP				byte_6AEDB

; =============== S C R I P T ===============================================
_script143:
		OBJ_MOVE_X_POS		$EE
		OBJ_SET_X_DELTA		$D8
		SJMP				byte_6AF25

; =============== S C R I P T ===============================================
_script144:
		OBJ_MOVE_X_POS		$12
		OBJ_SET_X_DELTA		$28
byte_6AF25:
		PARAM_40_SET
		NJSR				_native_sub12B
		OBJ_MOVE_Y_POS		$24
		OBJ_SET_Y_DELTA		$28
		OBJ_SET_SIZE		$07,$0E
		SPR_LIB_SELECT		$05
		SPR_IDX_SELECT		$32
		PARAM_80_CLEAR
		OBJ_SET_HP			$FF
		VAR_1C_SET			$01
byte_6AF39:
		SYNC
		NJSR				_native_get_obj_y_delta
		SBMI				byte_6AF4C
		NJSR				_obj_vert_animate
		NJSR				_native_sub10A
		SBCS				byte_6AF52
		SJMP				byte_6AF57
byte_6AF4C:
		NJSR				_native_sub10B
		SBCS				byte_6AF57
byte_6AF52:
		NJSR				_native_sub129
		APU_LOAD			$54
byte_6AF57:
		NJSR				_obj_move_hor_animate
		NJSR				_native_sub104
		SBCC				byte_6AF39
		NJSR				_native_sub105
		APU_LOAD			$54
		SJMP				byte_6AF39

; =============== S C R I P T ===============================================
_script177:
		STORE				$00,_pal_anim_mode_idx
		PAL_FADE_OUT		$04,$FF
		SUSPEND				$14
		STORE				$40,_stage_flags
		SJMP				_script_idle
byte_6AF78:
		OBJ_SET_X_POS		$70,$00
		STORE				$1E,_stage4_seconds_cnt
		STORE				$00,byte_DE
		STORE				$00,byte_DF
		SPR_LIB_SELECT		$00
		SPR_IDX_SELECT		$10
		SRET
byte_6AF8C:
		APU_LOAD			$3A
		NJSR				_native_sub021
		STORE				$3B,_stage4_frames_cnt
		SRET
byte_6AF96:
		STORE				$FF,_stage4_frames_cnt
byte_6AF9A:
		NJMP				_native_sub044
		LOOPA				$F0,byte_6AF9A
byte_6AFA1:
		SJMP				byte_B6B07

; =============== S U B R O U T I N E =======================================
_native_sub044:
		LDA		#<[_num_char_table1]
		STA		_tmp_ptr42
		LDA		#>[_num_char_table1]
		STA		_tmp_ptr42+1
		LDX		#$00
		LDY		#$00
		LDA		_stage4_seconds_cnt
		JSR		_format_num99
		LDA		#<[_obj_spr_lib_insert]
		LDY		#>[_obj_spr_lib_insert]
		JSR		_farcall
		LDA		_stage4_seconds_cnt
		JMP		_scr_flags_update

byte_6AFC1:
		NJMP				_native_sub044
		LOOPA				$3C,byte_6AFC1
		CHR_BANK			$01,$0B
		NJMP				_native_sub045
		SPR_LIB_SELECT		$05
		SPR_IDX_SELECT		$28
		PARAM_80_CLEAR
		OBJ_SET_X_POS		$80,$00
		OBJ_SET_Y_POS		$68,$00
		NJSR				_native_sub046
		SUSPEND				$B4
		NJSR				_native_sub047
		SJMP				byte_6AFA1

; =============== S U B R O U T I N E =======================================
_native_sub045:
		LDY		#$04
		LDA		#$80
loc_6AFE8:
		STA		_scr_params,Y
		INY
		CPY		#$0C
		BCC		loc_6AFE8
		LDY		#$01
loc_6AFF2:
		LDA		_scr_idxBs,Y
		AND		#$40
		BEQ		loc_6B00A
		LDA		_scr_idxBs,Y
		AND		#$0F
		CMP		#$02
		BCC		loc_6B00A
		LDA		_scr_idxBs,Y
		AND		#$BF
		STA		_scr_idxBs,Y
loc_6B00A:
		DEY
		BPL		loc_6AFF2
		RTS

; =============== S U B R O U T I N E =======================================
_native_sub046:
		LDA		byte_DE
		CMP		byte_DF
		BEQ		locret_6B022
		LDY		#$00
		BCS		loc_6B019
		INY
loc_6B019:
		CLC
		LDA		_obj_spr_libs,Y
		ADC		#$25
		STA		_obj_spr_idxs,X
locret_6B022:
		RTS

; =============== S U B R O U T I N E =======================================
_native_sub047:
		LDA		_players_lives
		STA		byte_410
		LDA		_players_lives+1
		STA		byte_410+1
		LDA		byte_DE
		CMP		byte_DF
		BEQ		locret_6B03C
		LDX		#$00
		BCC		loc_6B038
		INX
loc_6B038:
		LDA		#$00
		STA		_players_lives,X
locret_6B03C:
		RTS

; =============== O B J E C T   S C R I P T =================================
_obj_scr00:
		NJSR				_native_bonus_room_3prizes_shuffle
		SRUN				$06,_script145
		SRUN				$06,_script146
		SRUN				$06,_script147
		SRUN				$09,_script148
		SRUN				$09,_script149
		SJSR				byte_6AF78
		STORE				$0A,_stage4_seconds_cnt
		OBJ_SET_Y_POS		$38,$00
byte_6B05E:
		NJMP				_native_sub044
		LOOPA				$3C,byte_6B05E
		SJSR				byte_6AF8C
byte_6B068:
		NJSR				_native_sub170
		SBNE				byte_6B074
		NJMP				_native_sub044
		SBEQ				byte_6B068
byte_6B074:
		NJSR				_native_sub171
		SJMP				_script177
byte_6B07A:
		SRUN				$01,_script14A
		NJSR				_native_sub117
		NJSR				_native_sub134
		OBJ_SET_HP			$01
		OBJ_SET_SIZE		$08,$10
		NJSR				_native_sub113
		SBMI				byte_6B095
		OBJ_SET_X_POS		$08,$01
		SJMP				byte_6B09B
byte_6B095:
		OBJ_SET_X_POS		$F8,$FF
		NJSR				_native_sub105
byte_6B09B:
		SRET
byte_6B09C:
		SJSR				_script_animate16
		NJSR				_native_sub129
		SRET
byte_6B0A3:
		SUSPEND				$1E
		NJMP				_native_sub105
		SRET

; =============== S U B R O U T I N E =======================================
_native_sub048:
		JSR		_native_sub049

; =============== S U B R O U T I N E =======================================
_native_sub049:
		LDX		_scr_idx
		JSR		_native_sub049_A
		JMP		_native_sub049_B

; =============== S C R I P T ===============================================
_script145:
		SPR_LIB_SELECT		$05
		SPR_IDX_SELECT		$1E
		PARAM_80_CLEAR
		OBJ_MOVE_Y_POS		$40
		OBJ_SET_X_DELTA		$BC
		OBJ_SET_Y_DELTA		$F8
		DESTR_PC_SET		byte_6B109
		SJSR				byte_6B07A
byte_6B0C5:
		SJSR				byte_6B09C
		LOOPB				$04,byte_6B0C5
		SJSR				byte_6B0A3
		SJMP				byte_6B0C5

; =============== S C R I P T ===============================================
_script146:
		SPR_LIB_SELECT		$06
		SPR_IDX_SELECT		$01
		PARAM_80_CLEAR
		OBJ_MOVE_Y_POS		$58
		OBJ_SET_X_DELTA		$D2
		OBJ_SET_Y_DELTA		$F8
		DESTR_PC_SET		byte_6B116
		SJSR				byte_6B07A
byte_6B0E3:
		SJSR				byte_6B09C
		LOOPB				$06,byte_6B0E3
		SJSR				byte_6B0A3
		SJMP				byte_6B0E3

; =============== S C R I P T ===============================================
_script147:
		OBJ_MOVE_Y_POS		$7F
		OBJ_SET_X_DELTA		$E4
		OBJ_SET_Y_DELTA		$F0
		DESTR_PC_SET		byte_6B11F
		SJSR				byte_6B07A
byte_6B0FC:
		SJSR				byte_6B09C
		LOOPB				$0A,byte_6B0FC
		SJSR				byte_6B0A3
		SJMP				byte_6B0FC
byte_6B109:
		NJSR				_players_animB_sub0129_sub06_A
		NJSR				_native_sub048
		SPR_LIB_SELECT		$05
		SPR_IDX_SELECT		$1F
		SJMP				byte_6A23B
byte_6B116:
		NJSR				_players_animB_sub0129_sub06_A
		NJSR				_native_sub049
		SJMP				_script151
byte_6B11F:
		NJSR				_players_animB_sub0129_sub06_A
		KILL

; =============== S C R I P T ===============================================
_script14A:
		SPR_LIB_SELECT		$05
		PARAM_80_CLEAR
byte_6B126:
		SPR_IDX_SELECT		$1D
		SJSR				byte_6B13D
		SPR_IDX_SELECT		$0F
		SJSR				byte_6B13D
		SPR_IDX_SELECT		$10
		SJSR				byte_6B13D
		SPR_IDX_SELECT		$11
		SJSR				byte_6B13D
		SJMP				byte_6B126
byte_6B13D:
		NJMP				_native_sub04A
		LOOPB				$06,byte_6B13D
		SRET

; =============== S U B R O U T I N E =======================================
_native_sub04A:
		JSR		_native_sub04A_A ; FLIP_40_SET
		CLC
		LDA		_obj_y_lo_poss,Y
		ADC		#$08
		STA		_obj_y_lo_poss,X
		RTS

; =============== S U B R O U T I N E =======================================
_native_get_player1_lives:
		LDA		_players_lives
		JMP		_scr_flags_update

; =============== S U B R O U T I N E =======================================
_native_get_player2_lives:
		LDA		_players_lives+1
		JMP		_scr_flags_update

; =============== S C R I P T ===============================================
_script148:
		NJSR				_native_get_player1_lives
		SBNE				byte_6B191
		OBJ_SET_X_POS		$10,$00
		SJMP				byte_6B171

; =============== S C R I P T ===============================================
_script149:
		NJSR				_native_get_player2_lives
		SBNE				byte_6B191
		OBJ_SET_X_POS		$F0,$00
byte_6B171:
		PARAM_40_SET
		DESTR_PC_SET		byte_6B185
		OBJ_SET_Y_POS		$C0,$00
		OBJ_SET_SIZE		$06,$10
		SPR_LIB_SELECT		$05
		SPR_IDX_SELECT		$1B
		PARAM_80_CLEAR
		OBJ_SET_HP			$01
		SJSR				byte_68065
byte_6B185:
		SJSR				byte_6806C
		OBJ_SET_Y_DELTA		$C0
		OBJ_SET_HP			$01
		VAR_1C_SET			$01
		SJMP				byte_68092
byte_6B191:
		KILL

; =============== O B J E C T   S C R I P T =================================
_obj_scr02:
		NJSR				_native_sub04B
		OBJ_MOVE_Y_POS		$40
byte_6B197:
		SRUN				$06,_script14B
		FLIP_40_TOGGLE
		OBJ_MOVE_Y_POS		$30
		LOOPA				$04,byte_6B197
		OBJ_SET_Y_POS		$13,$00
		SJSR				byte_6AF78
		SJSR				byte_6AF8C
byte_6B1AB:
		NJMP				_native_sub044
		SBEQ				byte_6B1AB
		SJMP				byte_6AFC1

; =============== S U B R O U T I N E =======================================
_native_sub04B:
		LDY		#$10
loc_6B1B6:
		LDA		#$D0
		STA		byte_43A+3,Y
		STA		byte_43A+$C,Y
		CMP		byte_43A+1,Y
		BCC		loc_6B1CE
		CMP		byte_43A+$11,Y
		BCC		loc_6B1CE
		STA		byte_43A+1,Y
		STA		byte_43A+$E,Y
loc_6B1CE:
		TYA
		CLC
		ADC		#$10
		TAY
		CMP		#$F0
		BCC		loc_6B1B6
		LDY		#$0F
loc_6B1D9:
		LDA		#$D0
		STA		byte_43A,Y
		DEY
		BPL		loc_6B1D9
		RTS

; =============== S C R I P T ===============================================
_script14B:
		OBJ_SET_SIZE		$08,$12
		SPR_LIB_SELECT		$05
		PARAM_80_CLEAR
		OBJ_SET_X_DELTA		$01
		NJSR				_native_sub10F
		FLIP_40_CLEAR
byte_6B1EE:
		SPR_IDX_SELECT		$17
		FLIP_40_CLEAR
		SJSR				byte_6B207
		SPR_IDX_SELECT		$18
		SJSR				byte_6B207
		SPR_IDX_SELECT		$19
		SJSR				byte_6B207
		SPR_IDX_SELECT		$18
		FLIP_40_SET
		SJSR				byte_6B207
		SJMP				byte_6B1EE
byte_6B207:
		SYNC
		NJSR				_native_sub04D
		SBNE				byte_6B21A
		NJSR				_obj_move_hor_animate
		NJSR				_native_get_obj_hp
		SBEQ				byte_6B21A
		NJSR				_native_sub04C
byte_6B21A:
		LOOPA				$08,byte_6B207
		SRET

; =============== S U B R O U T I N E =======================================
_native_sub04C:
		JSR		_scr_param_4_clear
		JSR		_native_sub105
		INC		_obj_hps,X
		LDA		_obj_x_deltas,X
		BMI		loc_6B238
		LDA		_obj_x_deltas,X
		CMP		#$10
		BEQ		locret_6B237
		INC		_obj_x_deltas,X
locret_6B237:
		RTS
loc_6B238:
		LDA		_obj_x_deltas,X
		CMP		#$F0
		BEQ		locret_6B242
		DEC		_obj_x_deltas,X
locret_6B242:
		RTS

; =============== S U B R O U T I N E =======================================
_native_sub04D:
		LDY		_obj_x_lo_poss,X
		LDA		_obj_x_deltas,X
		BEQ		loc_6B266
		BMI		loc_6B255
		CPY		#$C0
		BNE		loc_6B266
		INC		byte_DE
		BNE		loc_6B25B
loc_6B255:
		CPY		#$40
		BNE		loc_6B266
		INC		byte_DF
loc_6B25B:
		JSR		_scr_param_4_set
		LDA		#$00
		STA		_obj_x_deltas,X
		STA		_obj_hps,X
loc_6B266:
		JMP		_scr_flags_update
_script47:
		DESTR_PC_SET		_script47
		OBJ_SET_SIZE		$06,$10
		SPR_LIB_SELECT		$05
		SPR_IDX_SELECT		$1B
		PARAM_80_CLEAR
		SJSR				byte_6806C
		NJSR				_native_sub030
byte_6B27A:
		JMP_OBJ_ANIMATE
		NJSR				_native_get_obj_hp
		SBEQ				byte_6B27A
		OBJ_SET_X_DELTA		$08
		OBJ_SET_Y_DELTA		$E8
		NJSR				_players_animB_sub67_A
		SJMP				byte_68096

; =============== O B J E C T   S C R I P T =================================
_obj_scr03:
		SRUN				$01,_script14C
		NJSR				_native_sub04E
		SJSR				byte_6AF78
		STORE				$3C,_stage4_seconds_cnt
		OBJ_SET_Y_POS		$18,$00
byte_6B29C:
		NJMP				_native_sub044
		LOOPA				$B4,byte_6B29C
		SRUN				$05,_script14D
		SRUN				$05,_script14E
		SJSR				byte_6AF8C
byte_6B2AE:
		NJMP				_native_sub044
		SBEQ				byte_6B2AE
		SJMP				byte_6AFC1

; =============== S U B R O U T I N E =======================================
_native_sub04E:
		LDA		_scr_cur_slot_idx
		STA		byte_E0
		LDY		#$00
loc_6B2BD:
		LDA		#$D0
		STA		byte_43A,Y
		STA		byte_43A+$F,Y
		TYA
		CLC
		ADC		#$10
		TAY
		CMP		#$F0
		BCC		loc_6B2BD
		LDY		#$0F
		LDA		#$D0
loc_6B2D2:
		STA		byte_43A,Y
		DEY
		BPL		loc_6B2D2
		RTS

; =============== S C R I P T ===============================================
_script14C:
		OBJ_MOVE_Y_POS		$58
		SRUN				$09,_script14F
		NJSR				_native_sub117
		SRUN				$09,_script150
		NJSR				_native_sub117
		OBJ_SET_SIZE		$04,$04
		OBJ_SET_X_DELTA		$F0
		SPR_LIB_SELECT		$05
		SPR_IDX_SELECT		$1C
		PARAM_80_CLEAR
		SUSPEND				$B4
byte_6B2F5:
		NJSR				_native_cmp40_obj_x_lo_pos
		SBCC				byte_6B30D
		NJSR				_native_cmpC0_obj_x_lo_pos
		SBCS				byte_6B30D
		NJSR				_native_sub12A
		SSWITCH				_tmp_ptrE+1
		SCASE				byte_6B310
		SCASE				byte_6B310
		SCASE				byte_6B30D
byte_6B30D:
		NJSR				_native_sub110
byte_6B310:
		JMP_OBJ_ANIMATE
		LOOPA				$26,byte_6B310
		SJMP				byte_6B2F5
byte_6B318:
		OBJ_SET_SIZE		$02,$02
		OBJ_SET_HP			$01
		SRET

; =============== S C R I P T ===============================================
_script14F:
		SJSR				byte_6B318
byte_6B321:
		SYNC
		NJSR				_native_sub04A_A
		OBJ_MOVE_X_POS		$F1
		OBJ_MOVE_Y_POS		$F2
		SJMP				byte_6B321

; =============== S C R I P T ===============================================
_script150:
		SJSR				byte_6B318
byte_6B32F:
		SYNC
		NJSR				_native_sub04A_A
		OBJ_MOVE_X_POS		$0F
		OBJ_MOVE_Y_POS		$F2
		SJMP				byte_6B32F

; =============== S C R I P T ===============================================
_script14D:
		OBJ_SET_X_POS		$18,$00
		SJMP				byte_6B343

; =============== S C R I P T ===============================================
_script14E:
		OBJ_SET_X_POS		$E8,$00
byte_6B343:
		DESTR_PC_SET		byte_6B367
		OBJ_SET_Y_POS		$40,$00
		OBJ_SET_SIZE		$06,$0D
		SPR_LIB_SELECT		$04
		PARAM_80_CLEAR
		SJMP				byte_6B373
byte_6B352:
		OBJ_SET_X_DELTA		$00
		NJSR				_native_sub160
byte_6B357:
		SYNC
		NJSR				_native_get_obj_var0D
		SBPL				byte_6B367
		SJSR				byte_6A589
		SBCC				byte_6B357
		SJMP				byte_6B373
byte_6B367:
		SJSR				byte_6806C
		TARGET_DIR_SET		$00
		OBJ_SET_X_DELTA		$08
		OBJ_SET_Y_DELTA		$B0
		NJSR				_native_sub029
byte_6B373:
		NJSR				_native_sub11C
		NJSR				_native_sub161
		NJSR				_native_sub134
byte_6B37C:
		SJSR				byte_6B393
		OBJ_SET_Y_DELTA		$E0
		NJSR				_native_cmp50_obj_y_lo_pos
		SBCC				byte_6B37C
		NJSR				_far_players_animB_sub0129_G
		SBMI				byte_6B352
		SJSR				byte_6B393
		SJMP				byte_6B352
byte_6B393:
		NJMP				_native_sub04F
		NJSR				_native_sub100
		OBJ_SET_HP			$01
		VAR_1C_SET			$02
		SJSR				byte_6A557
		SBCS				byte_6B393
		SRET

; =============== S U B R O U T I N E =======================================
_native_sub04F:
		LDA		#<[byte_6B3AB]
		LDY		#>[byte_6B3AB]
		JMP		_native_sub023

byte_6B3AB:
		.BYTE	$05,$00
		.BYTE	$06,$00
		.BYTE	$05,$40
		.BYTE	$06,$C0

; =============== O B J E C T   S C R I P T =================================
_obj_scr01_bonus_room:
		NJSR				_native_sub052
		NJSR				_native_sub051_ex
		NJSR				_native_bonus_room_4prizes_shuffle
byte_6B3BC:
		NJSR				_native_bonus_room_box_obj_insert
		LOOPA				$04,byte_6B3BC
		OBJ_SET_Y_POS		$18,$00
		SJSR				byte_6AF78
		STORE				$0A,_stage4_seconds_cnt
		SJSR				_script_sub_6B415
		NJSR				_native_sub139
		NJSR				_native_sub051
		SJSR				_script_sub_6B415
		SJSR				_script_sub_6B418
		NJSR				_native_sub16A
		SJSR				_script_sub_6B418
		NJSR				_native_sub051_ex
		NJSR				_native_sub139
		SJSR				byte_6AF8C
byte_6B3EB:
		NJSR				_native_sub056
		SBNE				byte_6B3FA
		NJMP				_native_sub044
		SBEQ				byte_6B3EB
		NJSR				_native_sub057
byte_6B3FA:
		NJSR				_native_sub050
		SJMP				byte_6AF96

; =============== S U B R O U T I N E =======================================
_native_sub050:
		LDA		_players_def_max_hps
		STA		_obj_hps
		LDA		_players_def_max_hps+1
		STA		_obj_hps+1
		LDA		byte_410
		STA		_players_lives
		LDA		byte_410+1
		STA		_players_lives+1
		RTS

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_6B415:
		SJSR				_script_sub_6B418

; !FALLTHROUGH!

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_6B418:
		NJMP				_native_sub044
		LOOPA				$78,_script_sub_6B418
		SRET

; =============== S U B R O U T I N E =======================================
_native_sub051:
		LDA		#$96
		STA		byte_436
		STA		byte_438
		LDA		#$97
		STA		byte_437
		STA		byte_439

; !FALLTHROUGH!

; =============== S U B R O U T I N E =======================================
_native_sub051_ex:
		LDA		#$03
loc_6B432:
		PHA
		TAY
		LDX		byte_436,Y
		LDA		byte_6B446,Y
		LDY		#$3B
		JSR		_far_sys_room_draw_sub02
		PLA
		SEC
		SBC		#$01
		BPL		loc_6B432
		RTS

byte_6B446:
		.BYTE	$03,$06,$09,$0C

; =============== S U B R O U T I N E =======================================
_native_sub052:
		LDY		#$03
		LDA		#$F4
loc_6B44E:
		STA		byte_436,Y
		DEY
		BPL		loc_6B44E
		RTS

; =============== S U B R O U T I N E =======================================
_native_bonus_room_box_obj_insert:
		JSR		_native_get_bonus_room_prize_from_list
		LDY		_tmp_ptrE+1
		LDA		_bonus_room_box_x_pos_list,Y
		STA		_tmp_ptr4
		LDA		#$C0
		STA		_tmp_ptr2
		LDA		#$00
		STA		_tmp_ptr2+1
		STA		_tmp_ptr4+1
		STA		byte_6
		LDY		_scr_loopsA,X
		LDA		_bonus_room_box_prize_list,Y
		PHA
		LDA		_bonus_room_box_obj_script_lib,Y
		STA		_tmp_ptr0
		LDA		off_6B4A6,Y
		STA		_tmp_ptr0+1
		LDY		#$01
		JSR		_scr_load
		PLA
		STA		_scr_vars19,X
		LDY		_tmp_ptrE+1
		LDA		_bonus_room_box_delay_list,Y
		STA		_scr_delays,X
		LDA		_bonus_room_box_anim_lib,Y
		STA		_scr_destr_lo_pcs,X
		LDA		off_6B4B2,Y
		STA		_scr_destr_hi_pcs,X
		RTS

_bonus_room_box_x_pos_list:
		.BYTE	$38,$68,$98,$C8
_bonus_room_box_delay_list:
		.BYTE	$08,$18,$28,$38
_bonus_room_box_obj_script_lib:
		.BYTE	<[_obj_scr_bonus_room_boxA]
		.BYTE	<[_obj_scr_bonus_room_boxB]
		.BYTE	<[_obj_scr_bonus_room_boxC]
		.BYTE	<[_obj_scr_bonus_room_boxD]
off_6B4A6:
		.BYTE	>[_obj_scr_bonus_room_boxA]
		.BYTE	>[_obj_scr_bonus_room_boxB]
		.BYTE	>[_obj_scr_bonus_room_boxC]
		.BYTE	>[_obj_scr_bonus_room_boxD]
_bonus_room_box_prize_list:
		.BYTE	$F4,$F5,$F6,$F7
_bonus_room_box_anim_lib:
		.BYTE	<[_obj_bonus_roomA_amin]
		.BYTE	<[_obj_bonus_roomB_amin]
		.BYTE	<[_obj_bonus_roomC_amin]
		.BYTE	<[_obj_bonus_roomD_amin]
off_6B4B2:
		.BYTE	>[_obj_bonus_roomA_amin]
		.BYTE	>[_obj_bonus_roomB_amin]
		.BYTE	>[_obj_bonus_roomC_amin]
		.BYTE	>[_obj_bonus_roomD_amin]
_obj_bonus_roomA_amin:
		.BYTE	$21,$11,$11,$21,$14,$31,$43,$33,$34,$12,$34,$11,$13,$32,$32,$11
		.BYTE	$41,$00
_obj_bonus_roomB_amin:
		.BYTE	$03,$33,$41,$11,$12,$13,$12,$31,$41,$43,$23,$32,$14,$32,$14,$33
		.BYTE	$33,$00
_obj_bonus_roomC_amin:
		.BYTE	$01,$11,$23,$33,$43,$22,$14,$44,$33,$22,$31,$11,$43,$23,$43,$41
		.BYTE	$23,$00
_obj_bonus_roomD_amin:
		.BYTE	$42,$23,$33,$41,$23,$44,$33,$13,$22,$14,$12,$43,$21,$43,$24,$11
		.BYTE	$11,$00

; =============== S U B R O U T I N E =======================================
_native_sub054:
		LDY		#$03
		LDA		_obj_x_lo_poss,X
loc_6B503:
		CMP		_bonus_room_box_x_pos_list,Y
		BEQ		loc_6B50C
		DEY
		BPL		loc_6B503
		RTS
loc_6B50C:
		LDA		_scr_vars19,X
		STA		byte_436,Y
		RTS

; =============== S U B R O U T I N E =======================================
_native_sub055:
		LDA		#$00
		STA		_obj_x_deltas,X
		STA		_obj_y_deltas,X
		JSR		_scr_flags_update
		LDA		_scr_destr_hi_pcs,X
		STA		_tmp_ptr0+1
		LDA		_scr_destr_lo_pcs,X
		STA		_tmp_ptr0
		LDA		_scr_vars20,X
		LSR
		TAY
		LDA		(_tmp_ptr0),Y
		BNE		loc_6B536
		LDA		#$FF
		JMP		_scr_flags_update
loc_6B536:
		BCS		loc_6B53C
		LSR
		LSR
		LSR
		LSR
loc_6B53C:
		INC		_scr_vars20,X
		AND		#$07
		JSR		_switch
		.WORD	nullsub5
		.WORD	_native_sub055_sub0
		.WORD	_native_sub055_sub1
		.WORD	_native_sub055_sub2
		.WORD	_native_sub055_sub3

; =============== S U B R O U T I N E =======================================
_native_sub055_sub0:
		LDA		#$20
		BNE		_native_sub055_sub0_ex

; =============== S U B R O U T I N E =======================================
_native_sub055_sub2:
		LDA		#$E0

; =============== S U B R O U T I N E =======================================
_native_sub055_sub0_ex:
		STA		_obj_x_deltas,X
		RTS

; =============== S U B R O U T I N E =======================================
_native_sub055_sub1:
		LDA		#$20
		BNE		_native_sub055_sub1_ex

; =============== S U B R O U T I N E =======================================
_native_sub055_sub3:
		LDA		#$E0

; =============== S U B R O U T I N E =======================================
_native_sub055_sub1_ex:
		STA		_obj_y_deltas,X

; =============== S U B R O U T I N E =======================================
nullsub5:
		RTS

; =============== S U B R O U T I N E =======================================
_native_sub056:
		LDY		#$00
		LDX		#$01
loc_6B566:
		LDA		_players_states,X
		CMP		#$04
		BEQ		loc_6B588
		CMP		#$18
		BEQ		loc_6B588
		LDA		_scr_idxBs,X
		AND		#$40
		BEQ		loc_6B589
		LDA		_scr_idxBs,X
		AND		#$0F
		TAY
		LDA		_obj_spr_libs,Y
		CMP		#$03
		BNE		loc_6B589
		LDA		#$04
		STA		_players_states,X
loc_6B588:
		INY
loc_6B589:
		DEX
		BPL		loc_6B566
		CPY		#$02
		JMP		_scr_flags_update

; =============== S U B R O U T I N E =======================================
_native_sub057:
		LDX		#$01
loc_6B593:
		LDA		_players_states,X
		CMP		#$18
		BCS		loc_6B59D
		LDA		#$04
		STA		_players_states,X
loc_6B59D:
		DEX
		BPL		loc_6B593
		RTS

; =============== S C R I P T ===============================================
_obj_scr_bonus_room_boxA:
		SPR_LIB_SELECT		$05
		SPR_IDX_SELECT		$37
		SJMP				_obj_scr_bonus_room_boxD89AB_ex

; =============== S C R I P T ===============================================
_obj_scr_bonus_room_boxB:
		SPR_LIB_SELECT		$06
		SPR_IDX_SELECT		$01
		SJMP				_obj_scr_bonus_room_boxD89AB_ex

; =============== S C R I P T ===============================================
_obj_scr_bonus_room_boxC:
		SPR_LIB_SELECT		$05
		SPR_IDX_SELECT		$24
		SJMP				_obj_scr_bonus_room_boxD89AB_ex

; =============== S C R I P T ===============================================
_obj_scr_bonus_room_boxD:
		SPR_LIB_SELECT		$05
		SPR_IDX_SELECT		$25

; !FALLTHROUGH!

; =============== S C R I P T ===============================================
_obj_scr_bonus_room_boxD89AB_ex:
		PARAM_80_CLEAR
		OBJ_SET_HP			$01
		OBJ_SET_SIZE		$06,$0C
		OBJ_SET_Y_DELTA		$E0
		SJSR				_script_animate10
		SUSPEND				$78
		OBJ_SET_Y_DELTA		$20
		SJSR				_script_animate10
		OBJ_SET_Y_DELTA		$00
		SPR_LIB_SELECT		$03
		SPR_IDX_SELECT		$00
byte_6B5D2:
		NJMP				_native_sub058
		SBNE				byte_6B5D2
byte_6B5D8:
		NJSR				_native_sub055
		SJSR				_script_animate10
		NJSR				_native_sub058
		SBEQ				byte_6B5D8
		NJSR				_native_sub054
byte_6B5E7:
		NJMP				_native_sub058
		SBNE				byte_6B5E7
		KILL

; =============== S U B R O U T I N E =======================================
_native_sub058:
		LDY		_scr_idxAs,X
		LDA		_scr_idxBs,Y
		AND		#$10
		JMP		_scr_flags_update

; =============== S C R I P T ===============================================
_script42:
		SPR_LIB_SELECT		$05
		SPR_IDX_SELECT		$37
		PARAM_80_CLEAR
		NJSR				_native_sub059
		SJMP				_script_idle

; =============== S C R I P T ===============================================
_script43:
		SPR_LIB_SELECT		$06
		SPR_IDX_SELECT		$01
		PARAM_80_CLEAR
		NJSR				_native_sub05A
		SRUN				$01,_script151
		SJMP				_script_idle

; =============== S C R I P T ===============================================
_script44:
		SPR_LIB_SELECT		$05
		SPR_IDX_SELECT		$24
		PARAM_80_CLEAR
		NJSR				_native_sub05B
		SRUN				$01,_script152
		SJMP				_script_idle

; =============== S C R I P T ===============================================
_script152:
		SPR_LIB_SELECT		$05
		SPR_IDX_SELECT		$35
		SJMP				byte_6A240

; =============== S C R I P T ===============================================
_script45:
		SPR_LIB_SELECT		$05
		SPR_IDX_SELECT		$25
		PARAM_80_CLEAR
		NJSR				_native_sub05C
		SRUN				$01,_script153
		SJMP				_script_idle

; =============== S C R I P T ===============================================
_script153:
		SPR_LIB_SELECT		$05
		SPR_IDX_SELECT		$36
		SJMP				byte_6A240

; =============== S U B R O U T I N E =======================================
_native_sub059:
		LDA		_continues
		CMP		#$09
		BCS		locret_6B647
		INC		_continues
locret_6B647:
		RTS

; =============== S U B R O U T I N E =======================================
_native_sub05A:
		LDY		_scr_idxAs,X
		LDA		byte_410,Y
		CMP		#$0A
		BCS		locret_6B658
		CLC
		ADC		#$01
		STA		byte_410,Y
locret_6B658:
		RTS

; =============== S U B R O U T I N E =======================================
_native_sub05B:
		LDA		#$1E
		BNE		_native_sub05C_ex

; =============== S U B R O U T I N E =======================================
_native_sub05C:
		LDA		#$0A

; =============== S U B R O U T I N E =======================================
_native_sub05C_ex:
		CLC
		LDY		_scr_idxAs,X
		ADC		_players_rr_ptss,Y
		CMP		#$64
		BCC		loc_6B66C
		LDA		#$63
loc_6B66C:
		STA		_players_rr_ptss,Y
		RTS

; =============== S C R I P T ===============================================
_script_cutscenes:
		SSWITCH				_cutscene_idx
		SCASE				_scr_cutscene00
		SCASE				_scr_cutscene01
		SCASE				_scr_cutscene02
		SCASE				_scr_cutscene03
		SCASE				_scr_cutscene04
		SCASE				_scr_cutscene05
		SCASE				_scr_cutscene06
		SCASE				_scr_cutscene07
		SCASE				_scr_cutscene08
		SCASE				_scr_cutscene09
		SCASE				_scr_cutscene0A
		SCASE				_scr_cutscene0B
		SCASE				_scr_cutscene0C
		SCASE				_scr_cutscene0D
		SCASE				_scr_cutscene0E
		SCASE				_scr_cutscene0F
		SCASE				_scr_cutscene10
		SCASE				_scr_cutscene11
		SCASE				_scr_cutscene12

; =============== S C R I P T ===============================================
_script154:
		SYNC
		TEST_PADS			_PAD0_PRESS,_PAD_START,_script154
byte_6B69F:
		STORE				$04,_main_sub_idx
		SJMP				byte_6B6A9
byte_6B6A6:
		NJSR				_native_sub05D
byte_6B6A9:
		APU_LOAD			$7B
		SUSPEND				$20
		SJMP				_script177
byte_6B6B0:
		NJSR				_native_sub05D
		SJMP				_script177

; =============== S U B R O U T I N E =======================================
_native_sub05D:
		LDX		_cutscene_idx
		INX
		CPX		#$13
		BCC		loc_6B6BF
		LDX		#$00
loc_6B6BF:
		STX		_cutscene_idx
		RTS
byte_6B6C2:
		NJSR				_native_sub139
byte_6B6C5:
		NJMP				_native_sub14E
		SBEQ				byte_6B6C5
		SRET
byte_6B6CC:
		NJMP				_native_sub05F
byte_6B6CF:
		NJMP				_native_sub060
		SBNE				byte_6B6CF
		SRET

; =============== S U B R O U T I N E =======================================
_native_sub05E:
		LDY		_scr_vars19,X
		LDA		_scr_cur_slot_idx
		STA		byte_410,Y
		RTS

; =============== S U B R O U T I N E =======================================
_native_sub05F:
		LDY		_scr_vars19,X
		LDX		byte_410,Y
		LDA		_scr_idxBs,X
		AND		#$EF
		STA		_scr_idxBs,X
		RTS

; =============== S U B R O U T I N E =======================================
_native_sub060:
		LDY		_scr_vars19,X
		LDX		byte_410,Y
		LDA		_scr_idxBs,X
		AND		#$10
		JMP		_scr_flags_update
byte_6B6FC:
		NJMP				_native_sub061
		SBEQ				byte_6B6FC
		SRET

; =============== S U B R O U T I N E =======================================
_native_sub061:
		LDA		_wnd_msg_sub_idx
		JMP		_scr_flags_update
byte_6B708:
		NJSR				_native_sub062
		NJMP				_native_sub061
		SBEQ				byte_6B708
		SRET

; =============== S U B R O U T I N E =======================================
_native_sub062:
		LDY		_obj_hps,X
		LDA		_cur_wnd_msg_col
		AND		#$02
		BEQ		loc_6B71E
		LDY		_scr_vars1C,X
loc_6B71E:
		TYA
		STA		_obj_spr_idxs,X
		RTS

; =============== S U B R O U T I N E =======================================
_native_sub063:
		LDY		_obj_hps,X
		LDA		_cur_wnd_msg_col
		AND		#$02
		BEQ		loc_6B72F
		LDY		_scr_vars1C,X
loc_6B72F:
		TYA
		STA		_scr_vars19,X
		RTS
byte_6B734:
		NJSR				_native_sub134
		OBJ_SET_FLIP		$08
		SRET
byte_6B73A:
		OBJ_SET_HP			$1B
		VAR_1C_SET			$1C
		SJSR				byte_6B708
		SJMP				byte_6B6C2
byte_6B744:
		OBJ_SET_HP			$1F
		VAR_1C_SET			$1E
		SJSR				byte_6B708
		SPR_IDX_SELECT		$1B
		SJMP				byte_6B6C2
byte_6B750:
		SJSR				_script_sub_B7547
		SJSR				_script_sub_B7547
		SPR_IDX_SELECT		$1B
		OBJ_SET_Y_DELTA		$00
		SJMP				byte_6B6C2
byte_6B75D:
		SJSR				byte_6B76F
		NJSR				_players_animB_sub0129_sub0E_A
		SPR_IDX_SELECT		$0D
		SUSPEND				$78
		NJSR				_players_animB_sub0129_sub06_A
		SPR_IDX_SELECT		$1B
		SJMP				byte_6B6C2
byte_6B76F:
		OBJ_SET_SIZE		$06,$16
		SRET
byte_6B773:
		NJSR				_native_sub139
byte_6B776:
		NJSR				_native_sub173
		NJMP				_native_sub14E
		SBEQ				byte_6B776
		SRET
byte_6B780:
		NJSR				_native_sub063
		NJSR				_native_sub173
		NJMP				_native_sub061
		SBEQ				byte_6B780
		SRET
byte_6B78D:
		OBJ_SET_HP			$00
		VAR_1C_SET			$03
		SJSR				byte_6B780
		SJMP				byte_6B773
byte_6B797:
		OBJ_SET_HP			$06
		VAR_1C_SET			$09
		SJSR				byte_6B780
		TARGET_DIR_SET		$06
		SJMP				byte_6B773
byte_6B7A3:
		SPR_IDX_SELECT		$29
		SJSR				_script_animate10
		SPR_IDX_SELECT		$2A
		SJSR				_script_animate10
		SPR_IDX_SELECT		$2B
		SJSR				_script_animate10
		SPR_IDX_SELECT		$2A
		SJMP				_script_animate10
byte_6B7B7:
		NJSR				_native_sub139
byte_6B7BA:
		NJSR				_native_sub15B
		NJMP				_native_sub14E
		SBEQ				byte_6B7BA
		SRET
byte_6B7C4:
		NJSR				_native_sub063
		NJSR				_native_sub15B
		NJMP				_native_sub061
		SBEQ				byte_6B7C4
		SRET
byte_6B7D1:
		OBJ_SET_HP			$06
		VAR_1C_SET			$09
		SJSR				byte_6B7C4
		TARGET_DIR_SET		$00
		SJMP				byte_6B7B7
byte_6B7DD:
		SPR_IDX_SELECT		$23
		SJSR				_script_animate10
		SPR_IDX_SELECT		$24
		SJSR				_script_animate10
		SPR_IDX_SELECT		$25
		SJSR				_script_animate10
		SPR_IDX_SELECT		$24
		SJMP				_script_animate10
byte_6B7F1:
		NJSR				_native_sub139
		OBJ_SET_X_DELTA		$00
		OBJ_SET_Y_DELTA		$F8
byte_6B7F8:
		SPR_IDX_SELECT		$17
		JMP_OBJ_ANIMATE
		JMP_OBJ_ANIMATE
		JMP_OBJ_ANIMATE
		SPR_IDX_SELECT		$18
		JMP_OBJ_ANIMATE
		JMP_OBJ_ANIMATE
		JMP_OBJ_ANIMATE
		NJSR				_native_sub129
		NJSR				_native_sub14E
		SBNE				byte_6B823
		LOOPB				$28,byte_6B7F8
byte_6B80F:
		SPR_IDX_SELECT		$34
		JMP_OBJ_ANIMATE
		JMP_OBJ_ANIMATE
		JMP_OBJ_ANIMATE
		SPR_IDX_SELECT		$35
		JMP_OBJ_ANIMATE
		JMP_OBJ_ANIMATE
		JMP_OBJ_ANIMATE
		NJSR				_native_sub129
		LOOPB				$02,byte_6B80F
		SJMP				byte_6B7F8
byte_6B823:
		LOOPB_RESET
		SRET
byte_6B825:
		SPR_IDX_SELECT		$17
		SJSR				byte_6B82C
		SPR_IDX_SELECT		$18
byte_6B82C:
		NJMP				_native_sub122
		LOOPB				$03,byte_6B82C
		SRET

; =============== S C R I P T ===============================================
_scr_cutscene00:
		SRUN				$01,_script154
		SUSPEND				$1E
		SRUN				$01,_script155
byte_6B83E:
		NJMP				_native_sub064
		LOOPA				$80,byte_6B83E
		LOOPB				$02,byte_6B83E
		KILL

; =============== S U B R O U T I N E =======================================
_native_sub064:
		LDA		#$01
		LDX		#$00
		JSR		_native_sub065
		LDA		#$02
		INX

; =============== S U B R O U T I N E =======================================
_native_sub065:
		CLC
		ADC		_ppu_scroll_shadow_lo,X
		STA		_ppu_scroll_shadow_lo,X
		LDA		_ppu_scroll_nt_hor,X
		ADC		#$00
		STA		_ppu_scroll_nt_hor,X
		RTS

; =============== S C R I P T ===============================================
_script155:
		NJSR				_native_sub134
		OBJ_SET_X_POS		$F8,$FF
		OBJ_SET_Y_POS		$30,$00
		OBJ_SET_X_DELTA		$08
		FLIP_40_TOGGLE
		PARAM_80_CLEAR
byte_6B86D:
		SJSR				byte_6B8AC
		LOOPA				$12,byte_6B86D
		SJSR				byte_6B8A0
		OBJ_SET_Y_DELTA		$08
		SJSR				byte_6B8AC
		SJSR				byte_6B8AC
		SJSR				byte_6B8A0
		OBJ_SET_Y_DELTA		$F8
		SJSR				byte_6B8AC
		SJSR				byte_6B8AC
		STORE				$12,_pal_anim_mode_idx
		SRUN				$01,_script156
		OBJ_SET_X_DELTA		$08
		OBJ_SET_Y_DELTA		$00
byte_6B896:
		SJSR				byte_6B8AC
		LOOPA				$1E,byte_6B896
		SJMP				byte_6B6A6
byte_6B8A0:
		OBJ_SET_X_DELTA		$00
		OBJ_SET_Y_DELTA		$00
byte_6B8A4:
		SJSR				byte_6B8AC
		LOOPA				$04,byte_6B8A4
		SRET
byte_6B8AC:
		SPR_IDX_SELECT		$19
		SJSR				_script_animate10
		SPR_IDX_SELECT		$1A
		SJMP				_script_animate10

; =============== S C R I P T ===============================================
_script156:
		APU_LOAD			$55
		SUSPEND				$30
		SJMP				_script156

; =============== S C R I P T ===============================================
_scr_cutscene01:
		SRUN				$01,_script154
		OBJ_SET_Y_POS		$C0,$00
		TARGET_DIR_SET		$00
		SRUN				$01,_script157
		NJMP				_native_sub05E
		SUSPEND				$1E
		MSG_DISPLAY			_msg00,$5B
		MSG_WAIT
		SJSR				byte_6B6CC
		MSG_DISPLAY			_msg01,$56
		SJSR				byte_6B6CC
		TARGET_DIR_SET		$03
		SRUN				$01,_script158
		NJMP				_native_sub05E
		SJSR				byte_6B6CC
		MSG_DISPLAY			_msg02,$58
		SJSR				byte_6B6CC
		TARGET_DIR_SET		$00
		MSG_DISPLAY			_msg03,$56
		SJSR				byte_6B6CC
		TARGET_DIR_SET		$03
		MSG_DISPLAY			_msg04,$58
		SJSR				byte_6B6CC
		TARGET_DIR_SET		$02
		OBJ_SET_Y_POS		$A0,$00
		SRUN				$01,_script159
		NJMP				_native_sub05E
		TARGET_DIR_SET		$00
		MSG_DISPLAY			_msg05,$56
		SJSR				byte_6B6CC
		TARGET_DIR_SET		$03
		MSG_DISPLAY			_msg06,$58
		SJSR				byte_6B6CC
		NJMP				_native_sub05F
		TARGET_DIR_SET		$02
		MSG_DISPLAY			_msg07,$59
		SJSR				byte_6B6CC
		NJMP				_native_sub05F
		TARGET_DIR_SET		$04
		SRUN				$01,_script15A
		NJMP				_native_sub05E
		SJSR				byte_6B6CC
		MSG_DISPLAY			_msg08,$5A
		MSG_WAIT
		NJMP				_native_sub05F
		TARGET_DIR_SET		$01
		OBJ_SET_Y_POS		$C0,$00
		SRUN				$01,_script15B
		NJMP				_native_sub05E
		SJSR				byte_6B6CC
		TARGET_DIR_SET		$00
		MSG_DISPLAY			_msg09,$56
		SJSR				byte_6B6CC
		TARGET_DIR_SET		$01
		SJSR				byte_6B6CC
		MSG_DISPLAY			_msg0A,$57
		SJSR				byte_6B6CC
		TARGET_DIR_SET		$00
		MSG_DISPLAY			_msg0B,$56
		SJSR				byte_6B6CC
		TARGET_DIR_SET		$01
		MSG_DISPLAY			_msg0C,$57
		SJSR				byte_6B6CC
		MSG_DISPLAY			_msg0D,$56
		TARGET_DIR_SET		$00
		NJSR				_native_sub05F
		TARGET_DIR_SET		$01
		NJSR				_native_sub05F
		MSG_WAIT
		MSG_DISPLAY			_msg0E,$5B
		MSG_WAIT
		SJMP				byte_6B69F

; =============== S C R I P T ===============================================
_script157:
		OBJ_SET_X_POS		$B8,$00
		SPR_LIB_SELECT		$01
		SPR_IDX_SELECT		$1B
		PARAM_80_CLEAR
		SJSR				byte_6B6C2
		SJSR				byte_6B750
		SJSR				byte_6B73A
		SJSR				byte_6B73A
		SJSR				byte_6B744
		SJSR				byte_6B73A
		SJSR				byte_6B73A
		FLIP_40_SET
		OBJ_SET_X_DELTA		$10
		OBJ_SET_Y_DELTA		$00
		SJSR				_script_sub_B7533
		SJSR				_script_sub_B7533
		KILL

; =============== S C R I P T ===============================================
_script15B:
		SJSR				byte_6B734
		FLIP_40_SET
		OBJ_SET_X_POS		$D8,$FF
		SJSR				byte_6B76F
		SPR_LIB_SELECT		$02
		PARAM_80_CLEAR
		OBJ_SET_X_DELTA		$10
		SJSR				_script_sub_B7533
		SJSR				_script_sub_B7533
		SPR_IDX_SELECT		$05
		OBJ_SET_Y_DELTA		$C0
		OBJ_SET_HP			$01
		SJSR				_script_sub_68036
		SJSR				_script_sub_B7555
		SPR_IDX_SELECT		$1B
		SJSR				byte_6B6C2
		SJSR				byte_6B75D
		SJSR				byte_6B73A
		SJSR				byte_6B73A
		OBJ_SET_X_DELTA		$00
		OBJ_SET_Y_DELTA		$10
		SJSR				_script_sub_68036
		SJSR				_script_sub_B7555
		OBJ_SET_X_DELTA		$10
byte_6B9F5:
		SJSR				_script_sub_B7533
		LOOPA				$06,byte_6B9F5
		KILL

; =============== S C R I P T ===============================================
_script158:
		SJSR				byte_6B734
		FLIP_40_SET
		OBJ_SET_X_POS		$F0,$FF
		PARAM_80_CLEAR
		OBJ_SET_X_DELTA		$10
byte_6BA07:
		SJSR				byte_6B7A3
		LOOPA				$04,byte_6BA07
		SPR_IDX_SELECT		$28
		TARGET_DIR_SET		$00
		SJSR				byte_6B773
		SJSR				byte_6B78D
		SJSR				byte_6B78D
		SJSR				byte_6B797
		TARGET_DIR_SET		$00
byte_6BA20:
		SJSR				byte_6B7A3
		LOOPA				$06,byte_6BA20
		KILL

; =============== S C R I P T ===============================================
_script159:
		SJSR				byte_6B734
		FLIP_40_SET
		OBJ_SET_X_POS		$B8,$FF
		SJSR				byte_6B76F
		OBJ_SET_X_DELTA		$10
		PARAM_80_CLEAR
byte_6BA35:
		SJSR				byte_6B7DD
		LOOPA				$04,byte_6BA35
		OBJ_SET_Y_DELTA		$C0
		OBJ_SET_HP			$01
		SJSR				_script_sub_68036
		SPR_IDX_SELECT		$1C
		TARGET_DIR_SET		$00
		SJSR				byte_6B7B7
		SJSR				byte_6B7D1
		SPR_IDX_SELECT		$24
		OBJ_SET_Y_DELTA		$C0
		OBJ_SET_HP			$01
		SJSR				_script_sub_68036
byte_6BA56:
		SJSR				byte_6B7DD
		LOOPA				$08,byte_6BA56
		KILL

; =============== S C R I P T ===============================================
_script15A:
		SJSR				byte_6B734
		FLIP_40_SET
		OBJ_SET_X_POS		$F8,$FF
		OBJ_SET_Y_POS		$80,$00
		PARAM_80_CLEAR
		OBJ_SET_X_DELTA		$10
byte_6BA6B:
		SJSR				byte_6B825
		LOOPA				$1A,byte_6BA6B
		NJSR				_native_sub139
		SJSR				byte_6B7F1
		OBJ_SET_X_DELTA		$10
byte_6BA7A:
		SJSR				byte_6B825
		LOOPA				$1A,byte_6BA7A
		KILL

; =============== S C R I P T ===============================================
_scr_cutscene02:
		SRUN				$01,_script154
		OBJ_SET_Y_POS		$C0,$00
		TARGET_DIR_SET		$05
		SRUN				$01,_script15C
		NJMP				_native_sub05E
		SUSPEND				$1E
		TARGET_DIR_SET		$00
		SRUN				$01,_script15D
		NJMP				_native_sub05E
		TARGET_DIR_SET		$01
		SRUN				$01,_script15E
		NJMP				_native_sub05E
		SJSR				byte_6B6CC
		MSG_DISPLAY			_msg0F,$56
		MSG_WAIT
		TARGET_DIR_SET		$05
		MSG_DISPLAY			_msg10,$5C
		SJSR				byte_6B6CC
		TARGET_DIR_SET		$01
		MSG_DISPLAY			_msg11,$57
		NJMP				_native_sub05F
		MSG_WAIT
		TARGET_DIR_SET		$05
		MSG_DISPLAY			_msg12,$5C
		SJSR				byte_6B6CC
		TARGET_DIR_SET		$00
		MSG_DISPLAY			_msg13,$56
		MSG_WAIT
		TARGET_DIR_SET		$05
		MSG_DISPLAY			_msg14,$5C
		SJSR				byte_6B6CC
		NJMP				_native_sub05F
		TARGET_DIR_SET		$00
		NJMP				_native_sub05F
		TARGET_DIR_SET		$01
		SJSR				byte_6B6CC
		SJMP				byte_6B69F

; =============== S C R I P T ===============================================
_script15D:
		SPR_LIB_SELECT		$01
		OBJ_SET_X_POS		$C0,$FF
		SJSR				byte_6BB08
		SJMP				byte_6BB1B

; =============== S C R I P T ===============================================
_script15E:
		SPR_LIB_SELECT		$02
		OBJ_SET_X_POS		$A8,$FF
		SJSR				byte_6BB08
		SJSR				_script_sub_B7547
		OBJ_SET_Y_DELTA		$00
		SJSR				byte_6B6C2
		SJMP				byte_6BB1B
byte_6BB08:
		SJSR				byte_6B734
		FLIP_40_SET
		OBJ_SET_X_DELTA		$10
		PARAM_80_CLEAR
byte_6BB0F:
		SJSR				_script_sub_B7533
		LOOPA				$04,byte_6BB0F
		SPR_IDX_SELECT		$00
		SJMP				byte_6B6C2
byte_6BB1B:
		SJSR				_script_sub_B7533
		LOOPA				$08,byte_6BB1B
		SJSR				byte_6B6C2

; =============== S C R I P T ===============================================
_script15C:
		OBJ_SET_X_POS		$D0,$00
		OBJ_SET_Y_POS		$90,$00
		SPR_LIB_SELECT		$08
		SPR_IDX_SELECT		$15
		PARAM_80_CLEAR
		SJSR				byte_6B6C2
		OBJ_SET_HP			$15
		VAR_1C_SET			$16
		SJSR				byte_6B708
		SJSR				byte_6B6C2
		SJSR				byte_6B708
		SJSR				byte_6B6C2
		SJSR				byte_6B708
		SJSR				byte_6B6C2
		OBJ_SET_X_DELTA		$10
		FLIP_40_SET
byte_6BB4C:
		SPR_IDX_SELECT		$18
		SJSR				_script_animate12
		SPR_IDX_SELECT		$20
		SJSR				_script_animate12
		LOOPA				$03,byte_6BB4C
		KILL

; =============== S C R I P T ===============================================
_scr_cutscene03:
		SRUN				$01,_script154
		TARGET_DIR_SET		$00
		SRUN				$01,_script15F
		NJSR				_native_sub05E
		TARGET_DIR_SET		$01
		SRUN				$01,_script160
		NJSR				_native_sub05E
		SUSPEND				$30
		TARGET_DIR_SET		$00
		SJSR				byte_6B6CC
		MSG_DISPLAY			_msg15,$56
		SJSR				byte_6B6CC
		TARGET_DIR_SET		$03
		SRUN				$01,_script161
		NJMP				_native_sub05E
		SJSR				byte_6B6CC
		TARGET_DIR_SET		$05
		SRUN				$01,_script162
		NJMP				_native_sub05E
		TARGET_DIR_SET		$03
		MSG_DISPLAY			_msg16,$58
		SJSR				byte_6B6CC
		TARGET_DIR_SET		$01
		MSG_DISPLAY			_msg17,$57
		SJSR				byte_6B6CC
		TARGET_DIR_SET		$03
		MSG_DISPLAY			_msg18,$58
		SJSR				byte_6B6CC
		TARGET_DIR_SET		$01
		MSG_DISPLAY			_msg19,$57
		SJSR				byte_6B6CC
		TARGET_DIR_SET		$03
byte_6BBBA:
		MSG_DISPLAY			_msg1A,$58
		SJSR				byte_6B6CC
		SJSR				byte_6BC7C
		NJMP				_native_sub066
		MSG_DISPLAY			_msg1B,$58
		SJSR				byte_6B6CC
		SJSR				byte_6BC7C
		SSWITCH				_hor_menu_pos
		SCASE				byte_6BBE2
		SCASE				byte_6BBD8
byte_6BBD8:
		STORE				$01,byte_E1
		NJMP				_native_sub05F
		SJMP				byte_6BBBA
byte_6BBE2:
		MSG_DISPLAY			_msg1C,$58
		SJSR				byte_6B6CC
		APU_LOAD			$4D
		SUSPEND				$3C
		SSWITCH				byte_E0
		SCASE				byte_6BBF4
		SCASE				byte_6BC47
byte_6BBF4:
		APU_LOAD			$46
byte_6BBF6:
		NJSR				_native_sub068
		OBJ_INC_X_DELTA
		SUSPEND				$04
		LOOPA				$03,byte_6BBF6
		SUSPEND				$10
		TARGET_DIR_SET		$01
		NJMP				_native_sub05F
byte_6BC07:
		OBJ_DEX_X_DELTA
		NJSR				_native_sub068
		SUSPEND				$04
		LOOPA				$03,byte_6BC07
		NJMP				_ppu_pal_apply
		APU_LOAD			$13
		TARGET_DIR_SET		$03
		MSG_DISPLAY			_msg1D,$58
		SJSR				byte_6B6CC
		MSG_DISPLAY			_msg1E,$58
		SJSR				byte_6B6CC
		TARGET_DIR_SET		$00
		SJSR				byte_6B6CC
		MSG_DISPLAY			_msg1F,$56
		SJSR				byte_6B6CC
		TARGET_DIR_SET		$03
		MSG_DISPLAY			_msg20,$58
		SJSR				byte_6B6CC
		TARGET_DIR_SET		$00
		MSG_DISPLAY			_msg21,$56
		SJSR				byte_6B6CC
		SJMP				byte_6BC5E
byte_6BC47:
		MSG_DISPLAY			_msg22,$58
		SJSR				byte_6B6CC
		TARGET_DIR_SET		$05
		NJMP				_native_sub05F
		SUSPEND				$3C
		TARGET_DIR_SET		$03
		MSG_DISPLAY			_msg23,$58
		SJSR				byte_6B6CC
byte_6BC5E:
		TARGET_DIR_SET		$00
		MSG_DISPLAY			_msg24,$56
		SJSR				byte_6B6CC
		TARGET_DIR_SET		$03
		MSG_DISPLAY			_msg25,$58
		SJSR				byte_6B6CC
		TARGET_DIR_SET		$00
		MSG_DISPLAY			_msg26,$56
		SJSR				byte_6B6CC
		SJMP				byte_6B69F
byte_6BC7C:
		NJSR				_menu_init
		DRAW_MENU_CURSOR	_menu_data01
byte_6BC82:
		SYNC
		NJSR				_native_sub102
		TEST_PADS			_PAD0_PRESS,_PAD_LEFT|_PAD_RIGHT,byte_6BC93
		APU_LOAD			$31
		NJSR				_native_sub067
		DRAW_MENU_CURSOR	_menu_data01
byte_6BC93:
		TEST_PADS			_PAD0_PRESS,_PAD_A,byte_6BC82
		APU_LOAD			$32
		SRET

; =============== S U B R O U T I N E =======================================
_native_sub066:
		LDA		_hor_menu_pos
		STA		byte_E0
		LDA		#$00
		STA		byte_E1
		RTS

; =============== S U B R O U T I N E =======================================
_native_sub067:
		LDX		_hor_menu_pos
		STX		_tmp48
		INX
		TXA
		AND		#$01
		STA		_hor_menu_pos
		RTS
_menu_data01:
		.BYTE	$02,$01
		.BYTE	$40,$3E
		.BYTE	$E3,$24
		.BYTE	$E8,$24

; =============== S U B R O U T I N E =======================================
_native_sub068:
		LDA		_obj_x_deltas,X
		ASL
		TAX
		LDA		off_6BCC5,X
		LDY		off_6BCC5+1,X
		JMP		_far_prg3_spr_pal_load
off_6BCC5:
		.WORD	byte_53211
		.WORD	byte_53231
		.WORD	byte_53251

; =============== S C R I P T ===============================================
_script15F:
		SJSR				byte_6B734
		OBJ_SET_X_POS		$1C,$01
		OBJ_SET_Y_POS		$A0,$00
		SPR_LIB_SELECT		$01
		PARAM_80_CLEAR
		OBJ_SET_X_DELTA		$F0
byte_6BCD9:
		SJSR				_script_sub_B7533
		LOOPA				$04,byte_6BCD9
		SPR_IDX_SELECT		$1B
		SJSR				byte_6B6C2
		SJSR				byte_6B73A
		SSWITCH				byte_E0
		SCASE				byte_6BCEF
		SCASE				byte_6BCF9
byte_6BCEF:
		SJSR				byte_6B750
		SJSR				byte_6B73A
		FLIP_40_SET
		SJSR				byte_6B744
byte_6BCF9:
		SJSR				byte_6B73A
		SJSR				byte_6B73A

; =============== S C R I P T ===============================================
_script160:
		SJSR				byte_6B734
		OBJ_SET_X_POS		$10,$01
		OBJ_SET_Y_POS		$90,$00
		SPR_LIB_SELECT		$02
		PARAM_80_CLEAR
		OBJ_SET_X_DELTA		$F0
		SJSR				_script_sub_B7533
		SJSR				_script_sub_B7533
		SPR_IDX_SELECT		$1B
		SJSR				byte_6B6C2
		SJSR				byte_6B73A
		SJSR				byte_6B73A
		SSWITCH				byte_E0
		SCASE				byte_6BD25
		SCASE				byte_6BD2D
byte_6BD25:
		SJSR				byte_6B76F
		NJSR				_players_animB_sub0129_sub0E_A
		SPR_IDX_SELECT		$0D
byte_6BD2D:
		SJMP				_script_idle

; =============== S C R I P T ===============================================
_script161:
		SJSR				byte_6B734
		OBJ_SET_X_POS		$F8,$FF
		OBJ_SET_Y_POS		$C0,$00
		FLIP_40_SET
		PARAM_80_CLEAR
		OBJ_SET_X_DELTA		$10
byte_6BD3D:
		SJSR				byte_6B7A3
		LOOPA				$04,byte_6BD3D
		SPR_IDX_SELECT		$28
		TARGET_DIR_SET		$00
		SJSR				byte_6B773
		SJSR				byte_6B78D
		SJSR				byte_6B78D
byte_6BD51:
		SJSR				byte_6B78D
		SJSR				byte_6B78D
		SSWITCH				byte_E1
		SCASE				byte_6BD5E
		SCASE				byte_6BD51
byte_6BD5E:
		SJSR				byte_6B78D
		SSWITCH				byte_E0
		SCASE				byte_6BD68
		SCASE				byte_6BD6B
byte_6BD68:
		SJSR				byte_6B78D
byte_6BD6B:
		SJSR				byte_6B78D
		SJSR				byte_6B78D
		SJSR				byte_6B78D

; =============== S C R I P T ===============================================
_script162:
		OBJ_SET_X_POS		$88,$00
		OBJ_SET_Y_POS		$A0,$00
		SPR_IDX_SELECT		$38
		PARAM_80_CLEAR
		SJSR				byte_6B6C2
		APU_LOAD			$46
byte_6BD82:
		SPR_IDX_SELECT		$39
		SUSPEND				$06
		SPR_IDX_SELECT		$3A
		SUSPEND				$06
		LOOPA				$02,byte_6BD82
		SPR_IDX_SELECT		$3B
		SUSPEND				$06
		KILL

; =============== S C R I P T ===============================================
_scr_cutscene04:
		SRUN				$01,_script154
		TARGET_DIR_SET		$00
		SRUN				$01,_script163
		NJSR				_native_sub05E
		TARGET_DIR_SET		$01
		SRUN				$01,_script164
		NJSR				_native_sub05E
		TARGET_DIR_SET		$02
		SRUN				$01,_script165
		NJSR				_native_sub05E
		TARGET_DIR_SET		$04
		SRUN				$01,_script166
		NJMP				_native_sub05E
		SUSPEND				$1E
		TARGET_DIR_SET		$01
		MSG_DISPLAY			_msg27,$57
		SJSR				byte_6B6CC
		SRUN				$01,_script167
		SUSPEND				$3C
		MSG_DISPLAY			_msg28,$5A
		MSG_WAIT
		TARGET_DIR_SET		$00
		MSG_DISPLAY			_msg29,$56
		SJSR				byte_6B6CC
		TARGET_DIR_SET		$02
		MSG_DISPLAY			_msg2A,$59
		SJSR				byte_6B6CC
		TARGET_DIR_SET		$00
		MSG_DISPLAY			_msg2B,$56
		SJSR				byte_6B6CC
		MSG_DISPLAY			_msg2C,$5A
		MSG_WAIT
		MSG_DISPLAY			_msg2D,$56
		SJSR				byte_6B6CC
		SJMP				byte_6B6A6

; =============== S C R I P T ===============================================
_script163:
		FLIP_40_SET
		OBJ_SET_X_POS		$48,$00
		OBJ_SET_Y_POS		$80,$00
		SPR_LIB_SELECT		$01
		PARAM_80_CLEAR
		SJSR				byte_6B6C2
		SJSR				byte_6B73A
		SJSR				byte_6B73A
		SJSR				byte_6B744

; =============== S C R I P T ===============================================
_script164:
		FLIP_40_SET
		OBJ_SET_X_POS		$30,$00
		OBJ_SET_Y_POS		$80,$00
		SPR_LIB_SELECT		$02
		PARAM_80_CLEAR
		SJSR				byte_6B6C2
		SJSR				byte_6B73A

; =============== S C R I P T ===============================================
_script165:
		OBJ_SET_X_POS		$80,$00
		OBJ_SET_Y_POS		$D0,$00
		PARAM_80_CLEAR
		SPR_IDX_SELECT		$1C
		TARGET_DIR_SET		$00
		SJSR				byte_6B7B7
		FLIP_40_SET
		SJSR				byte_6B7D1

; =============== S C R I P T ===============================================
_script166:
		FLIP_40_SET
		PARAM_80_CLEAR
		OBJ_SET_X_POS		$70,$00
		OBJ_SET_Y_POS		$90,$00
byte_6BE3B:
		SJSR				byte_6B7F1
		SJMP				byte_6BE3B

; =============== S C R I P T ===============================================
_script167:
		SJSR				byte_6B734
		OBJ_SET_X_POS		$10,$01
		OBJ_SET_Y_POS		$B0,$00
		SPR_IDX_SELECT		$3C
		PARAM_80_CLEAR
		OBJ_SET_X_DELTA		$F8
byte_6BE4F:
		JMP_OBJ_ANIMATE
		LOOPA				$80,byte_6BE4F
		KILL

; =============== S C R I P T ===============================================
_scr_cutscene05:
		SRUN				$01,_script154
		TARGET_DIR_SET		$00
		SRUN				$01,_script168
		NJSR				_native_sub05E
		TARGET_DIR_SET		$01
		SRUN				$01,_script169
		NJMP				_native_sub05E
		SUSPEND				$3C
		SJSR				byte_6B6CC
		MSG_DISPLAY			_msg2E,$56
		MSG_WAIT
		APU_LOAD			$51
		SUSPEND				$3C
		MSG_DISPLAY			_msg2F,$57
		MSG_WAIT
byte_6BE7E:
		SJSR				byte_6BECE
		NJMP				_ppu_pal_apply
		SUSPEND				$10
		SJSR				byte_6BECE
		NJMP				_pal_patch03_load
		SUSPEND				$04
		LOOPA				$05,byte_6BE7E
		SUSPEND				$B4
		SJMP				byte_6B6A6

; =============== S C R I P T ===============================================
_scr_cutscene07:
		SRUN				$01,_script154
		TARGET_DIR_SET		$00
		SRUN				$01,_script16A
		NJSR				_native_sub05E
		TARGET_DIR_SET		$01
		SRUN				$01,_script16B
		NJMP				_native_sub05E
		SUSPEND				$3C
		TARGET_DIR_SET		$01
		MSG_DISPLAY			_msg37,$57
		SJSR				byte_6B6CC
		TARGET_DIR_SET		$00
		MSG_DISPLAY			_msg38,$56
		SJSR				byte_6B6CC
		SJMP				byte_6B69F

; =============== S C R I P T ===============================================
_scr_cutscene08:
		SUSPEND				$3C
		MSG_DISPLAY			_msg39,$5B
		MSG_WAIT
		SJMP				byte_6B69F
byte_6BECE:
		TARGET_DIR_SET		$00
		NJSR				_native_sub05F
		TARGET_DIR_SET		$01
		NJSR				_native_sub05F
		SRET

; =============== S U B R O U T I N E =======================================
_pal_patch03_load:
		LDA		#<[_pal_patch03]
		LDY		#>[_pal_patch03]
		JMP		_far_prg3_pal_patch_load

; =============== S C R I P T ===============================================
_script168:
		SPR_LIB_SELECT		$01
		OBJ_SET_X_POS		$F0,$FF
		SJMP				byte_6BEED

; =============== S C R I P T ===============================================
_script169:
		SPR_LIB_SELECT		$02
		OBJ_SET_X_POS		$D8,$FF
byte_6BEED:
		SPR_IDX_SELECT		$20
		SJSR				byte_6B734
		FLIP_40_SET
		OBJ_SET_Y_POS		$C0,$00
		OBJ_SET_X_DELTA		$10
		PARAM_80_CLEAR
byte_6BEF9:
		SJSR				_script_animate10
		LOOPA				$10,byte_6BEF9
		SJSR				byte_6B6C2
byte_6BF03:
		SJSR				byte_6B6C2
		SPR_IDX_SELECT		$1B
		SJSR				byte_6B6C2
		SPR_IDX_SELECT		$20
		LOOPA				$05,byte_6BF03
		SJMP				_script_idle

; =============== S C R I P T ===============================================
_script16A:
		OBJ_SET_X_POS		$70,$00
		OBJ_SET_Y_POS		$C0,$00
		SPR_LIB_SELECT		$01
		SPR_IDX_SELECT		$1B
		FLIP_40_SET
		PARAM_80_CLEAR
		SJSR				byte_6B6C2
		SJSR				byte_6B744
		SJSR				byte_6B73A

; =============== S C R I P T ===============================================
_script16B:
		OBJ_SET_X_POS		$58,$00
		OBJ_SET_Y_POS		$C0,$00
		SPR_LIB_SELECT		$02
		SPR_IDX_SELECT		$1B
		FLIP_40_SET
		PARAM_80_CLEAR
		SJSR				byte_6B6C2
		SJSR				byte_6B73A

; =============== S C R I P T ===============================================
_scr_cutscene06:
		SRUN				$01,_script154
		SUSPEND				$3C
		MSG_DISPLAY			_msg30,$5D
		MSG_WAIT
		MSG_DISPLAY			_msg31,$57
		MSG_WAIT
		MSG_DISPLAY			_msg32,$5D
		MSG_WAIT
		MSG_DISPLAY			_msg33,$56
		MSG_WAIT
		MSG_DISPLAY			_msg34,$5D
		MSG_WAIT
		MSG_DISPLAY			_msg35,$57
		MSG_WAIT
		MSG_DISPLAY			_msg36,$5D
		MSG_WAIT
		SJMP				byte_6B6A6

; =============== S C R I P T ===============================================
_scr_cutscene09:
		SRUN				$01,_script154
		SRUN				$01,_script16C
		TARGET_DIR_SET		$00
		SRUN				$01,_script16D
		NJSR				_native_sub05E
		TARGET_DIR_SET		$01
		SRUN				$01,_script16E
		NJSR				_native_sub05E
		TARGET_DIR_SET		$02
		SRUN				$01,_script16F
		NJMP				_native_sub05E
		SUSPEND				$3C
		TARGET_DIR_SET		$02
		MSG_DISPLAY			_msg3A,$59
		SJSR				byte_6B6CC
		TARGET_DIR_SET		$00
		MSG_DISPLAY			_msg3B,$56
		SJSR				byte_6B6CC
		TARGET_DIR_SET		$01
		SJSR				byte_6B6CC
		MSG_DISPLAY			_msg3C,$57
		SJSR				byte_6B6CC
		TARGET_DIR_SET		$00
		MSG_DISPLAY			_msg3D,$56
		SJSR				byte_6B6CC
		TARGET_DIR_SET		$01
		SJSR				byte_6B6CC
		TARGET_DIR_SET		$01
		MSG_DISPLAY			_msg3E,$57
		SJSR				byte_6B6CC
		SJMP				byte_6B69F

		SECTION_END		0B, "GAME SCRIPTS A"

		BANK_END 4,$C000
