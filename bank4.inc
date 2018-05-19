
		ORG $8000

		BANK_START $04

		.BYTE	$05		; NJSR
		.WORD	_obj_move_hor_animate
		.BYTE	$05		; NJSR
		.WORD	_native_sub104
		.BYTE	$0F		; SBCC
		.WORD	byte_6800C
		.BYTE	$05		; NJSR
		.WORD	_native_sub105
byte_6800C:
		.BYTE	$07
		.WORD	byte_68044
		.BYTE	$0F		; SBCC
		.WORD	byte_6801F
		.BYTE	$05		; NJSR
		.WORD	_native_get_obj_y_delta
		.BYTE	$10		; SBPL
		.WORD	byte_6801C
		.BYTE	$05		; NJSR
		.WORD	_native_sub107
		.BYTE	$08		; RET
byte_6801C:
		.BYTE	$05
		.WORD	_scr_flags_flush_clc
byte_6801F:
		.BYTE	$08
byte_68020:
		.BYTE	$01
		.BYTE	$05		; NJSR
		.WORD	_native_get_obj_y_delta
		.BYTE	$0E		; SBNE
		.WORD	byte_6802F
		.BYTE	$07		; SJSR
		.WORD	byte_6803E
		.BYTE	$0C		; SBCS
		.WORD	byte_6802F
		.BYTE	$29,$00		; OBJ_SET_X_DELTA
byte_6802F:
		.BYTE	$05
		.WORD	_native_get_obj_hp
		.BYTE	$0B		; SBEQ
		.WORD	byte_68020
		.BYTE	$08		; RET
byte_68036:
		.BYTE	$07
		.WORD	byte_6803D
		.BYTE	$0C		; SBCS
		.WORD	byte_68036
		.BYTE	$08		; RET
byte_6803D:
		.BYTE	$01
byte_6803E:
		.BYTE	$05
		.WORD	_obj_move_hor_animate
		.BYTE	$05		; NJSR
		.WORD	_native_sub104
byte_68044:
		.BYTE	$05
		.WORD	_native_sub109
		.BYTE	$05		; NJSR
		.WORD	_native_get_obj_y_delta
		.BYTE	$0D		; SBMI
		.WORD	byte_6805C
		.BYTE	$05		; NJSR
		.WORD	_obj_vert_animate
		.BYTE	$05		; NJSR
		.WORD	_native_sub10A
		.BYTE	$0F		; SBCC
		.WORD	byte_68058
		.BYTE	$2A,$01		; OBJ_SET_Y_DELTA
byte_68058:
		.BYTE	$05
		.WORD	_scr_flags_flush_clc
		.BYTE	$08		; RET
byte_6805C:
		.BYTE	$05
		.WORD	_native_sub10B
		.BYTE	$0C		; SBCS
		.WORD	byte_68064
		.BYTE	$2A,$00		; OBJ_SET_Y_DELTA
byte_68064:
		.BYTE	$08
byte_68065:
		.BYTE	$03
		.WORD	_native_get_obj_var0D
		.BYTE	$0D		; SBMI
		.WORD	byte_68065
		.BYTE	$08		; RET
byte_6806C:
		.BYTE	$05
		.WORD	_native_sub13A
		.BYTE	$05		; NJSR
		.WORD	_native_sub134
		.BYTE	$05		; NJSR
		.WORD	_native_sub164
byte_68075:
		.BYTE	$05
		.WORD	_native_get_obj_var0D
		.BYTE	$0D		; SBMI
		.WORD	byte_68081
		.BYTE	$03		; NJMP
		.WORD	_players_animB_sub0129_sub06_C
		.BYTE	$06		; SJMP
		.WORD	byte_68075
byte_68081:
		.BYTE	$05
		.WORD	_native_sub12B
		.BYTE	$17,$24		; APU_LOAD
		.BYTE	$08		; RET
byte_68087:
		.BYTE	$17,$2D
		.BYTE	$33,$00		; VAR_1C_SET
		.BYTE	$29,$BD		; OBJ_SET_X_DELTA
		.BYTE	$2A,$BD		; OBJ_SET_Y_DELTA
		.BYTE	$05		; NJSR
		.WORD	_players_animB_sub3_B_A
byte_68092:
		.BYTE	$18
		.BYTE	$06		; SJMP
		.WORD	byte_68092
byte_68096:
		.BYTE	$18
		.BYTE	$05		; NJSR
		.WORD	_native_sub109
		.BYTE	$06		; SJMP
		.WORD	byte_68096
byte_6809D:
		.BYTE	$07
		.WORD	byte_680E7
		.BYTE	$29,$00		; OBJ_SET_X_DELTA
		.BYTE	$05		; NJSR
		.WORD	_scr_param_4_clear
byte_680A5:
		.BYTE	$07
		.WORD	byte_680C3
		.BYTE	$09,$3C		; LOOPA
		.WORD	byte_680A5
		.BYTE	$0A,$08		; LOOPB
		.WORD	byte_680A5
		.BYTE	$05		; NJSR
		.WORD	_scr_param_10_set
byte_680B3:
		.BYTE	$07
		.WORD	byte_680C3
		.BYTE	$09,$78		; LOOPA
		.WORD	byte_680B3
		.BYTE	$05		; NJSR
		.WORD	_scr_param_10_clear
		.BYTE	$05		; NJSR
		.WORD	_players_animB_sub0129_sub06_A
		.BYTE	$33,$01		; VAR_1C_SET
		.BYTE	$08		; RET
byte_680C3:
		.BYTE	$01
		.BYTE	$05		; NJSR
		.WORD	_native_get_obj_var0D
		.BYTE	$10		; SBPL
		.WORD	byte_680D4
		.BYTE	$05		; NJSR
		.WORD	_native_sub118
		.BYTE	$0F		; SBCC
		.WORD	byte_680D3
		.BYTE	$07		; SJSR
		.WORD	byte_68044
byte_680D3:
		.BYTE	$08
byte_680D4:
		.BYTE	$07
		.WORD	byte_68102
		.BYTE	$33,$02		; VAR_1C_SET
		.BYTE	$29,$C0		; OBJ_SET_X_DELTA
		.BYTE	$05		; NJSR
		.WORD	_native_sub11B
		.BYTE	$05		; NJSR
		.WORD	_native_sub11C
		.BYTE	$05		; NJSR
		.WORD	_native_sub11D
		.BYTE	$06		; SJMP
		.WORD	byte_68092
byte_680E7:
		.BYTE	$33,$00
		.BYTE	$17,$2E		; APU_LOAD
		.BYTE	$29,$F0		; OBJ_SET_X_DELTA
		.BYTE	$2A,$D0		; OBJ_SET_Y_DELTA
		.BYTE	$05		; NJSR
		.WORD	_players_animB_sub3_B_A
		.BYTE	$05		; NJSR
		.WORD	_players_animB_sub0129_sub0E_A
byte_680F5:
		.BYTE	$07
		.WORD	byte_6803D
		.BYTE	$0F		; SBCC
		.WORD	byte_68101
		.BYTE	$05		; NJSR
		.WORD	_native_get_obj_var0D
		.BYTE	$0D		; SBMI
		.WORD	byte_680F5
byte_68101:
		.BYTE	$08
byte_68102:
		.BYTE	$2A,$00
		.BYTE	$05		; NJSR
		.WORD	_native_sub134
		.BYTE	$05		; NJSR
		.WORD	_scr_param_10_clear
byte_6810A:
		.BYTE	$01
		.BYTE	$05		; NJSR
		.WORD	_players_animB_sub0129_sub06_C
		.BYTE	$05		; NJSR
		.WORD	_native_get_obj_var0D
		.BYTE	$10		; SBPL
		.WORD	byte_6810A
		.BYTE	$17,$24		; APU_LOAD
		.BYTE	$08		; RET
_obj_scr24:
		.BYTE	$42
		.WORD	byte_6818F
		.BYTE	$1D,$07		; SPR_LIB_SELECT
		.BYTE	$1E,$00		; SPR_IDX_SELECT
		.BYTE	$32,$08,$18	; OBJ_SET_SIZE
		.BYTE	$34,$02		; OBJ_SET_HP
		.BYTE	$33,$01		; VAR_1C_SET
		.BYTE	$07		; SJSR
		.WORD	_script201
		.BYTE	$29,$F0		; OBJ_SET_X_DELTA
		.BYTE	$2A,$00		; OBJ_SET_Y_DELTA
		.BYTE	$05		; NJSR
		.WORD	_native_sub10E
		.BYTE	$05		; NJSR
		.WORD	_native_sub10F
byte_68132:
		.BYTE	$1E,$00
		.BYTE	$07		; SJSR
		.WORD	byte_6814C
		.BYTE	$1E,$01		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	byte_6814C
		.BYTE	$1E,$02		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	byte_6814C
		.BYTE	$1E,$01		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	byte_6814C
byte_68146:
		.BYTE	$05
		.WORD	_native_sub110
		.BYTE	$06		; SJMP
		.WORD	byte_68132
byte_6814C:
		.BYTE	$01
		.BYTE	$05		; NJSR
		.WORD	_native_sub131
		.BYTE	$0C		; SBCS
		.WORD	byte_6816A
		.BYTE	$05		; NJSR
		.WORD	_obj_move_hor_animate
		.BYTE	$05		; NJSR
		.WORD	_native_sub104
		.BYTE	$0F		; SBCC
		.WORD	byte_6815F
		.BYTE	$41		; BREAK
		.WORD	byte_68146
byte_6815F:
		.BYTE	$05
		.WORD	_native_sub118
		.BYTE	$0C		; SBCS
		.WORD	byte_68036
		.BYTE	$09,$08		; LOOPA
		.WORD	byte_6814C
		.BYTE	$08		; RET
byte_6816A:
		.BYTE	$05
		.WORD	_native_sub132
		.BYTE	$1E,$03		; SPR_IDX_SELECT
		.BYTE	$02,$08		; DELAY
		.BYTE	$1E,$04		; SPR_IDX_SELECT
		.BYTE	$17,$5E		; APU_LOAD
		.BYTE	$05		; NJSR
		.WORD	_native_sub10C
		.BYTE	$0F		; SBCC
		.WORD	byte_6817E
		.BYTE	$05		; NJSR
		.WORD	_native_sub10D
byte_6817E:
		.BYTE	$02,$08
		.BYTE	$1E,$05		; SPR_IDX_SELECT
		.BYTE	$02,$08		; DELAY
		.BYTE	$1E,$00		; SPR_IDX_SELECT
		.BYTE	$02,$08		; DELAY
		.BYTE	$05		; NJSR
		.WORD	_native_sub10E
		.BYTE	$05		; NJSR
		.WORD	_native_sub10F
		.BYTE	$08		; RET
byte_6818F:
		.BYTE	$1E,$06
		.BYTE	$05		; NJSR
		.WORD	_native_get_obj_hp
		.BYTE	$0E		; SBNE
		.WORD	byte_68087
		.BYTE	$07		; SJSR
		.WORD	byte_6809D
		.BYTE	$06		; SJMP
		.WORD	_obj_scr24
_obj_scr25:
		.BYTE	$42
		.WORD	byte_68087
		.BYTE	$1D,$07		; SPR_LIB_SELECT
		.BYTE	$1E,$07		; SPR_IDX_SELECT
		.BYTE	$34,$01		; OBJ_SET_HP
		.BYTE	$33,$01		; VAR_1C_SET
		.BYTE	$32,$08,$18	; OBJ_SET_SIZE
		.BYTE	$07		; SJSR
		.WORD	_script201
		.BYTE	$29,$F0		; OBJ_SET_X_DELTA
		.BYTE	$2A,$00		; OBJ_SET_Y_DELTA
		.BYTE	$05		; NJSR
		.WORD	_native_sub10E
		.BYTE	$05		; NJSR
		.WORD	_native_sub10F
byte_681B8:
		.BYTE	$1E,$08
		.BYTE	$07		; SJSR
		.WORD	byte_681D2
		.BYTE	$1E,$09		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	byte_681D2
		.BYTE	$1E,$0A		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	byte_681D2
		.BYTE	$1E,$09		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	byte_681D2
		.BYTE	$05		; NJSR
		.WORD	_native_sub110
		.BYTE	$06		; SJMP
		.WORD	byte_681B8
byte_681D2:
		.BYTE	$18
		.BYTE	$05		; NJSR
		.WORD	_native_sub115
		.BYTE	$0F		; SBCC
		.WORD	byte_681DF
		.BYTE	$05		; NJSR
		.WORD	_native_sub17E
		.BYTE	$0C		; SBCS
		.WORD	byte_681E4
byte_681DF:
		.BYTE	$09,$08
		.WORD	byte_681D2
		.BYTE	$08		; RET
byte_681E4:
		.BYTE	$15
		.BYTE	$16		; LOOPB_RESET
		.BYTE	$05		; NJSR
		.WORD	_native_sub10E
		.BYTE	$05		; NJSR
		.WORD	_native_sub10F
		.BYTE	$41		; BREAK
		.WORD	byte_681EF
byte_681EF:
		.BYTE	$1E,$07
		.BYTE	$02,$10		; DELAY
		.BYTE	$1E,$0C		; SPR_IDX_SELECT
		.BYTE	$02,$10		; DELAY
		.BYTE	$17,$5F		; APU_LOAD
		.BYTE	$1E,$0D		; SPR_IDX_SELECT
		.BYTE	$04,$06		; RUN
		.WORD	_script100
		.BYTE	$02,$10		; DELAY
		.BYTE	$1E,$07		; SPR_IDX_SELECT
		.BYTE	$02,$10		; DELAY
byte_68205:
		.BYTE	$1E,$08
		.BYTE	$07		; SJSR
		.WORD	byte_6821C
		.BYTE	$1E,$09		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	byte_6821C
		.BYTE	$1E,$0A		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	byte_6821C
		.BYTE	$1E,$09		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	byte_6821C
		.BYTE	$06		; SJMP
		.WORD	byte_68205
byte_6821C:
		.BYTE	$01
		.BYTE	$05		; NJSR
		.WORD	_obj_move_hor_animate
		.BYTE	$05		; NJSR
		.WORD	_native_sub104
		.BYTE	$0C		; SBCS
		.WORD	byte_68231
		.BYTE	$05		; NJSR
		.WORD	_native_sub118
		.BYTE	$0C		; SBCS
		.WORD	byte_68231
		.BYTE	$09,$08		; LOOPA
		.WORD	byte_6821C
		.BYTE	$08		; RET
byte_68231:
		.BYTE	$15
		.BYTE	$1E,$09		; SPR_IDX_SELECT
		.BYTE	$2A,$C0		; OBJ_SET_Y_DELTA
		.BYTE	$06		; SJMP
		.WORD	byte_68036
_script100:
		.BYTE	$42
		.WORD	byte_68252
		.BYTE	$34,$01		; OBJ_SET_HP
		.BYTE	$33,$01		; VAR_1C_SET
		.BYTE	$32,$08,$04	; OBJ_SET_SIZE
		.BYTE	$1D,$07		; SPR_LIB_SELECT
		.BYTE	$1E,$0E		; SPR_IDX_SELECT
		.BYTE	$28,$F0		; OBJ_MOVE_Y_POS
		.BYTE	$29,$30		; OBJ_SET_X_DELTA
		.BYTE	$05		; NJSR
		.WORD	_native_sub12E
		.BYTE	$1B		; PARAM_80_CLEAR
		.BYTE	$06		; SJMP
		.WORD	byte_68092
byte_68252:
		.BYTE	$29,$0C
		.BYTE	$2A,$E0		; OBJ_SET_Y_DELTA
		.BYTE	$05		; NJSR
		.WORD	_players_animB_sub3_B_A
		.BYTE	$06		; SJMP
		.WORD	byte_68096
_obj_scr26:
		.BYTE	$42
		.WORD	byte_68087
		.BYTE	$27,$F8		; OBJ_MOVE_X_POS
		.BYTE	$1D,$07		; SPR_LIB_SELECT
		.BYTE	$1E,$4C		; SPR_IDX_SELECT
		.BYTE	$34,$01		; OBJ_SET_HP
		.BYTE	$33,$01		; VAR_1C_SET
		.BYTE	$32,$08,$0F	; OBJ_SET_SIZE
		.BYTE	$1B		; PARAM_80_CLEAR
		.BYTE	$07		; SJSR
		.WORD	_script201
		.BYTE	$05		; NJSR
		.WORD	_native_sub10E
byte_68273:
		.BYTE	$01
		.BYTE	$05		; NJSR
		.WORD	_native_sub17E
		.BYTE	$0F		; SBCC
		.WORD	byte_68273
		.BYTE	$05		; NJSR
		.WORD	_native_sub115
		.BYTE	$0F		; SBCC
		.WORD	byte_68273
		.BYTE	$17,$60		; APU_LOAD
		.BYTE	$32,$08,$18	; OBJ_SET_SIZE
		.BYTE	$1E,$0F		; SPR_IDX_SELECT
		.BYTE	$02,$04		; DELAY
		.BYTE	$1E,$10		; SPR_IDX_SELECT
		.BYTE	$02,$04		; DELAY
		.BYTE	$1E,$11		; SPR_IDX_SELECT
		.BYTE	$02,$04		; DELAY
		.BYTE	$1E,$12		; SPR_IDX_SELECT
		.BYTE	$02,$08		; DELAY
		.BYTE	$1E,$14		; SPR_IDX_SELECT
		.BYTE	$2A,$D0		; OBJ_SET_Y_DELTA
		.BYTE	$02,$08		; DELAY
		.BYTE	$07		; SJSR
		.WORD	byte_68036
		.BYTE	$29,$F0		; OBJ_SET_X_DELTA
		.BYTE	$2A,$00		; OBJ_SET_Y_DELTA
		.BYTE	$05		; NJSR
		.WORD	_native_sub10F
byte_682A5:
		.BYTE	$1E,$13
		.BYTE	$07		; SJSR
		.WORD	byte_682BC
		.BYTE	$1E,$14		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	byte_682BC
		.BYTE	$1E,$15		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	byte_682BC
		.BYTE	$1E,$14		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	byte_682BC
		.BYTE	$06		; SJMP
		.WORD	byte_682A5
byte_682BC:
		.BYTE	$01
		.BYTE	$05		; NJSR
		.WORD	_obj_move_hor_animate
		.BYTE	$05		; NJSR
		.WORD	_native_sub104
		.BYTE	$0C		; SBCS
		.WORD	byte_682D1
		.BYTE	$05		; NJSR
		.WORD	_native_sub118
		.BYTE	$0C		; SBCS
		.WORD	byte_682D1
		.BYTE	$09,$08		; LOOPA
		.WORD	byte_682BC
		.BYTE	$08		; RET
byte_682D1:
		.BYTE	$15
		.BYTE	$1E,$14		; SPR_IDX_SELECT
		.BYTE	$2A,$C0		; OBJ_SET_Y_DELTA
		.BYTE	$06		; SJMP
		.WORD	byte_68036
_obj_scr27:
		.BYTE	$42
		.WORD	byte_68087
		.BYTE	$1D,$07		; SPR_LIB_SELECT
		.BYTE	$1E,$16		; SPR_IDX_SELECT
		.BYTE	$34,$01		; OBJ_SET_HP
		.BYTE	$33,$01		; VAR_1C_SET
		.BYTE	$32,$08,$10	; OBJ_SET_SIZE
		.BYTE	$29,$10		; OBJ_SET_X_DELTA
		.BYTE	$2A,$04		; OBJ_SET_Y_DELTA
		.BYTE	$07		; SJSR
		.WORD	_script201
		.BYTE	$05		; NJSR
		.WORD	_native_sub10E
		.BYTE	$05		; NJSR
		.WORD	_native_sub10F
byte_682F4:
		.BYTE	$1E,$16
		.BYTE	$17,$61		; APU_LOAD
		.BYTE	$07		; SJSR
		.WORD	_script_animate3
		.BYTE	$1E,$17		; SPR_IDX_SELECT
		.BYTE	$17,$61		; APU_LOAD
		.BYTE	$07		; SJSR
		.WORD	_script_animate3
		.BYTE	$09,$08		; LOOPA
		.WORD	byte_682F4
byte_68306:
		.BYTE	$1E,$18
		.BYTE	$07		; SJSR
		.WORD	byte_6833A
		.BYTE	$1E,$19		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	byte_6833A
		.BYTE	$09,$02		; LOOPA
		.WORD	byte_68306
byte_68314:
		.BYTE	$1E,$1A
		.BYTE	$07		; SJSR
		.WORD	byte_6833A
		.BYTE	$1E,$1B		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	byte_6833A
		.BYTE	$09,$02		; LOOPA
		.WORD	byte_68314
		.BYTE	$04,$08		; RUN
		.WORD	_script101
byte_68326:
		.BYTE	$1E,$16
		.BYTE	$07		; SJSR
		.WORD	byte_6833A
		.BYTE	$1E,$17		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	byte_6833A
		.BYTE	$09,$02		; LOOPA
		.WORD	byte_68326
		.BYTE	$05		; NJSR
		.WORD	_native_sub129
		.BYTE	$06		; SJMP
		.WORD	byte_682F4
byte_6833A:
		.BYTE	$17,$61
		.BYTE	$02,$03		; DELAY
		.BYTE	$08		; RET
_script101:
		.BYTE	$05
		.WORD	_native_sub12B
		.BYTE	$28,$08		; OBJ_MOVE_Y_POS
		.BYTE	$34,$01		; OBJ_SET_HP
		.BYTE	$33,$02		; VAR_1C_SET
		.BYTE	$32,$02,$04	; OBJ_SET_SIZE
		.BYTE	$1D,$07		; SPR_LIB_SELECT
		.BYTE	$1E,$1C		; SPR_IDX_SELECT
		.BYTE	$2A,$08		; OBJ_SET_Y_DELTA
		.BYTE	$1B		; PARAM_80_CLEAR
		.BYTE	$06		; SJMP
		.WORD	byte_68096
_obj_scr28:
		.BYTE	$42
		.WORD	byte_68087
		.BYTE	$28,$FC		; OBJ_MOVE_Y_POS
		.BYTE	$1D,$07		; SPR_LIB_SELECT
		.BYTE	$1E,$28		; SPR_IDX_SELECT
		.BYTE	$32,$08,$18	; OBJ_SET_SIZE
		.BYTE	$34,$01		; OBJ_SET_HP
		.BYTE	$33,$01		; VAR_1C_SET
		.BYTE	$07		; SJSR
		.WORD	_script201
		.BYTE	$05		; NJSR
		.WORD	_native_sub10E
byte_6836B:
		.BYTE	$03
		.WORD	_native_sub112
		.BYTE	$0F		; SBCC
		.WORD	byte_6836B
		.BYTE	$31,$00		; TARGET_DIR_SET
byte_68373:
		.BYTE	$05
		.WORD	_native_sub10E
		.BYTE	$07		; SJSR
		.WORD	byte_68408
		.BYTE	$09,$03		; LOOPA
		.WORD	byte_68373
		.BYTE	$05		; NJSR
		.WORD	_native_sub111
		.BYTE	$2F,$20		; TARGET_LOCK
byte_68382:
		.BYTE	$31,$FF
		.BYTE	$07		; SJSR
		.WORD	byte_68408
		.BYTE	$06		; SJMP
		.WORD	byte_68382
_obj_scr29:
		.BYTE	$42
		.WORD	byte_68087
		.BYTE	$1D,$07		; SPR_LIB_SELECT
		.BYTE	$1E,$26		; SPR_IDX_SELECT
		.BYTE	$32,$08,$18	; OBJ_SET_SIZE
		.BYTE	$34,$01		; OBJ_SET_HP
		.BYTE	$33,$01		; VAR_1C_SET
		.BYTE	$07		; SJSR
		.WORD	_script201
		.BYTE	$29,$F0		; OBJ_SET_X_DELTA
		.BYTE	$2A,$00		; OBJ_SET_Y_DELTA
		.BYTE	$05		; NJSR
		.WORD	_native_sub10E
		.BYTE	$05		; NJSR
		.WORD	_native_sub10F
byte_683A5:
		.BYTE	$1E,$25
		.BYTE	$07		; SJSR
		.WORD	byte_683BF
		.BYTE	$1E,$26		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	byte_683BF
		.BYTE	$1E,$27		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	byte_683BF
		.BYTE	$1E,$26		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	byte_683BF
		.BYTE	$05		; NJSR
		.WORD	_native_sub110
		.BYTE	$06		; SJMP
		.WORD	byte_683A5
byte_683BF:
		.BYTE	$01
		.BYTE	$05		; NJSR
		.WORD	_obj_move_hor_animate
		.BYTE	$05		; NJSR
		.WORD	_native_sub112
		.BYTE	$0C		; SBCS
		.WORD	byte_683CE
		.BYTE	$09,$08		; LOOPA
		.WORD	byte_683BF
		.BYTE	$08		; RET
byte_683CE:
		.BYTE	$15
		.BYTE	$30,$30		; TARGET_SPD_SET
		.BYTE	$2F,$20		; TARGET_LOCK
		.BYTE	$31,$FF		; TARGET_DIR_SET
byte_683D5:
		.BYTE	$07
		.WORD	byte_68408
		.BYTE	$09,$02		; LOOPA
		.WORD	byte_683D5
		.BYTE	$05		; NJSR
		.WORD	_native_sub113
		.BYTE	$0D		; SBMI
		.WORD	byte_683E5
		.BYTE	$07		; SJSR
		.WORD	byte_68408
byte_683E5:
		.BYTE	$05
		.WORD	_native_sub10E
		.BYTE	$29,$20		; OBJ_SET_X_DELTA
		.BYTE	$05		; NJSR
		.WORD	_native_sub10F
byte_683ED:
		.BYTE	$17,$64
byte_683EF:
		.BYTE	$1E,$29
byte_683F1:
		.BYTE	$03
		.WORD	_native_sub122
		.BYTE	$09,$04		; LOOPA
		.WORD	byte_683F1
		.BYTE	$1E,$2A		; SPR_IDX_SELECT
byte_683FA:
		.BYTE	$03
		.WORD	_native_sub122
		.BYTE	$09,$04		; LOOPA
		.WORD	byte_683FA
		.BYTE	$0A,$02		; LOOPB
		.WORD	byte_683EF
		.BYTE	$06		; SJMP
		.WORD	byte_683ED
byte_68408:
		.BYTE	$17,$64
		.BYTE	$32,$0C,$10	; OBJ_SET_SIZE
		.BYTE	$1E,$29		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	byte_6841E
		.BYTE	$1E,$2A		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	byte_6841E
		.BYTE	$1E,$29		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	byte_6841E
		.BYTE	$1E,$2A		; SPR_IDX_SELECT
byte_6841E:
		.BYTE	$1A
		.BYTE	$01		; FLUSH
		.BYTE	$0A,$04		; LOOPB
		.WORD	byte_6841E
		.BYTE	$08		; RET
_obj_scr2A:
		.BYTE	$42
		.WORD	byte_68087
		.BYTE	$05		; NJSR
		.WORD	_scr_param_4_set
		.BYTE	$1D,$07		; SPR_LIB_SELECT
		.BYTE	$34,$01		; OBJ_SET_HP
		.BYTE	$33,$01		; VAR_1C_SET
		.BYTE	$32,$08,$20	; OBJ_SET_SIZE
byte_68434:
		.BYTE	$1B
		.BYTE	$17,$65		; APU_LOAD
		.BYTE	$1E,$1D		; SPR_IDX_SELECT
		.BYTE	$02,$04		; DELAY
		.BYTE	$1E,$1E		; SPR_IDX_SELECT
		.BYTE	$02,$04		; DELAY
		.BYTE	$05		; NJSR
		.WORD	_native_sub114
		.BYTE	$05		; NJSR
		.WORD	_scr_param_4_clear
		.BYTE	$2A,$B7		; OBJ_SET_Y_DELTA
		.BYTE	$07		; SJSR
		.WORD	byte_6846D
		.BYTE	$2A,$00		; OBJ_SET_Y_DELTA
		.BYTE	$07		; SJSR
		.WORD	byte_6846D
		.BYTE	$05		; NJSR
		.WORD	_scr_param_4_set
		.BYTE	$05		; NJSR
		.WORD	_native_sub114
		.BYTE	$17,$65		; APU_LOAD
		.BYTE	$1E,$23		; SPR_IDX_SELECT
		.BYTE	$02,$04		; DELAY
		.BYTE	$1E,$24		; SPR_IDX_SELECT
		.BYTE	$02,$04		; DELAY
		.BYTE	$1C		; PARAM_80_SET
		.BYTE	$02,$F0		; DELAY
		.BYTE	$05		; NJSR
		.WORD	_native_sub113
		.BYTE	$0D		; SBMI
		.WORD	byte_68434
		.BYTE	$02,$78		; DELAY
		.BYTE	$06		; SJMP
		.WORD	byte_68434
byte_6846D:
		.BYTE	$1E,$1F
		.BYTE	$07		; SJSR
		.WORD	byte_6847E
		.BYTE	$1E,$20		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	byte_6847E
		.BYTE	$09,$02		; LOOPA
		.WORD	byte_6846D
		.BYTE	$23		; FLIP_40_TOGGLE
		.BYTE	$24		; FLIP_80_TOGGLE
		.BYTE	$08		; RET
byte_6847E:
		.BYTE	$01
		.BYTE	$2C		; OBJ_INC_Y_DELTA
		.BYTE	$2C		; OBJ_INC_Y_DELTA
		.BYTE	$05		; NJSR
		.WORD	_obj_vert_animate
		.BYTE	$0A,$09		; LOOPB
		.WORD	byte_6847E
		.BYTE	$08		; RET
_obj_scr2B:
		.BYTE	$27,$F8
		.BYTE	$42		; DESTR_PC_SET
		.WORD	byte_68527
byte_6848E:
		.BYTE	$1D,$07
		.BYTE	$1E,$4C		; SPR_IDX_SELECT
		.BYTE	$34,$02		; OBJ_SET_HP
		.BYTE	$33,$01		; VAR_1C_SET
		.BYTE	$1B		; PARAM_80_CLEAR
byte_68497:
		.BYTE	$32,$08,$0F
byte_6849A:
		.BYTE	$07
		.WORD	byte_68514
		.BYTE	$05		; NJSR
		.WORD	_native_sub115
		.BYTE	$0F		; SBCC
		.WORD	byte_6849A
		.BYTE	$05		; NJSR
		.WORD	_native_sub116
		.BYTE	$0F		; SBCC
		.WORD	byte_6849A
		.BYTE	$05		; NJSR
		.WORD	_native_sub10E
byte_684AC:
		.BYTE	$28,$FE
		.BYTE	$07		; SJSR
		.WORD	byte_6851F
		.BYTE	$28,$02		; OBJ_MOVE_Y_POS
		.BYTE	$17,$60		; APU_LOAD
		.BYTE	$07		; SJSR
		.WORD	byte_6851F
		.BYTE	$07		; SJSR
		.WORD	byte_6851F
		.BYTE	$09,$03		; LOOPA
		.WORD	byte_684AC
		.BYTE	$05		; NJSR
		.WORD	_native_sub10E
		.BYTE	$1E,$2B		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	byte_6851F
		.BYTE	$1E,$2C		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	byte_6851F
		.BYTE	$1E,$2D		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	byte_6851F
		.BYTE	$1E,$2E		; SPR_IDX_SELECT
		.BYTE	$04,$07		; RUN
		.WORD	_script102
		.BYTE	$0F		; SBCC
		.WORD	byte_6849A
		.BYTE	$05		; NJSR
		.WORD	_native_sub117
		.BYTE	$32,$08,$28	; OBJ_SET_SIZE
byte_684E0:
		.BYTE	$07
		.WORD	byte_6851F
		.BYTE	$1E,$2F		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	byte_6851F
		.BYTE	$1E,$30		; SPR_IDX_SELECT
		.BYTE	$09,$14		; LOOPA
		.WORD	byte_684E0
		.BYTE	$05		; NJSR
		.WORD	_players_animB_sub0129_sub06_A
		.BYTE	$1E,$2E		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	byte_6851F
		.BYTE	$1E,$2D		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	byte_6851F
		.BYTE	$1E,$2C		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	byte_6851F
		.BYTE	$1E,$2B		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	byte_6851F
		.BYTE	$1E,$4C		; SPR_IDX_SELECT
		.BYTE	$32,$08,$10	; OBJ_SET_SIZE
byte_6850A:
		.BYTE	$07
		.WORD	byte_6851F
		.BYTE	$09,$0A		; LOOPA
		.WORD	byte_6850A
		.BYTE	$06		; SJMP
		.WORD	byte_68497
byte_68514:
		.BYTE	$01
		.BYTE	$05		; NJSR
		.WORD	_native_sub118
		.BYTE	$0F		; SBCC
		.WORD	byte_6851E
		.BYTE	$07		; SJSR
		.WORD	byte_68036
byte_6851E:
		.BYTE	$08
byte_6851F:
		.BYTE	$07
		.WORD	byte_68514
		.BYTE	$0A,$06		; LOOPB
		.WORD	byte_6851F
		.BYTE	$08		; RET
byte_68527:
		.BYTE	$05
		.WORD	_players_animB_sub0129_sub06_A
		.BYTE	$1E,$31		; SPR_IDX_SELECT
		.BYTE	$32,$08,$1C	; OBJ_SET_SIZE
		.BYTE	$05		; NJSR
		.WORD	_native_get_obj_hp
		.BYTE	$0E		; SBNE
		.WORD	byte_68087
		.BYTE	$07		; SJSR
		.WORD	byte_6809D
		.BYTE	$06		; SJMP
		.WORD	byte_6848E
_script102:
		.BYTE	$34,$FF
		.BYTE	$33,$02		; VAR_1C_SET
		.BYTE	$32,$08,$10	; OBJ_SET_SIZE
byte_68542:
		.BYTE	$05
		.WORD	_native_sub04A_A
		.BYTE	$28,$18		; OBJ_MOVE_Y_POS
		.BYTE	$03		; NJMP
		.WORD	_native_sub119
		.BYTE	$06		; SJMP
		.WORD	byte_68542
_obj_scr2D:
		.BYTE	$42
		.WORD	byte_68644
		.BYTE	$1D,$07		; SPR_LIB_SELECT
		.BYTE	$1E,$32		; SPR_IDX_SELECT
		.BYTE	$34,$02		; OBJ_SET_HP
		.BYTE	$33,$01		; VAR_1C_SET
		.BYTE	$32,$05,$20	; OBJ_SET_SIZE
		.BYTE	$07		; SJSR
		.WORD	_script201
		.BYTE	$05		; NJSR
		.WORD	_native_sub10E
byte_68561:
		.BYTE	$07
		.WORD	byte_68587
		.BYTE	$29,$E0		; OBJ_SET_X_DELTA
		.BYTE	$05		; NJSR
		.WORD	_native_sub10F
byte_68569:
		.BYTE	$07
		.WORD	byte_685AE
		.BYTE	$09,$04		; LOOPA
		.WORD	byte_68569
		.BYTE	$07		; SJSR
		.WORD	byte_6859D
		.BYTE	$29,$F0		; OBJ_SET_X_DELTA
		.BYTE	$2A,$CF		; OBJ_SET_Y_DELTA
		.BYTE	$07		; SJSR
		.WORD	byte_685CD
		.BYTE	$05		; NJSR
		.WORD	_native_sub110
		.BYTE	$29,$10		; OBJ_SET_X_DELTA
		.BYTE	$2A,$CF		; OBJ_SET_Y_DELTA
		.BYTE	$07		; SJSR
		.WORD	byte_685CD
		.BYTE	$06		; SJMP
		.WORD	byte_68561
byte_68587:
		.BYTE	$29,$00
		.BYTE	$31,$18		; TARGET_DIR_SET
		.BYTE	$07		; SJSR
		.WORD	byte_685AE
		.BYTE	$31,$1A		; TARGET_DIR_SET
		.BYTE	$07		; SJSR
		.WORD	byte_685AE
		.BYTE	$31,$1C		; TARGET_DIR_SET
		.BYTE	$07		; SJSR
		.WORD	byte_685AE
		.BYTE	$31,$1E		; TARGET_DIR_SET
		.BYTE	$06		; SJMP
		.WORD	byte_685AE
byte_6859D:
		.BYTE	$29,$00
		.BYTE	$31,$1C		; TARGET_DIR_SET
		.BYTE	$07		; SJSR
		.WORD	byte_685AE
		.BYTE	$31,$1A		; TARGET_DIR_SET
		.BYTE	$07		; SJSR
		.WORD	byte_685AE
		.BYTE	$31,$18		; TARGET_DIR_SET
		.BYTE	$06		; SJMP
		.WORD	byte_685AE
byte_685AE:
		.BYTE	$07
		.WORD	byte_685EA
		.BYTE	$1E,$33		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	byte_685EA
		.BYTE	$1E,$34		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	byte_685EA
		.BYTE	$1E,$35		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	byte_685EA
		.BYTE	$1E,$36		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	byte_685EA
		.BYTE	$1E,$37		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	byte_685EA
		.BYTE	$1E,$32		; SPR_IDX_SELECT
		.BYTE	$08		; RET
byte_685CD:
		.BYTE	$05
		.WORD	_native_sub10F
		.BYTE	$1E,$38		; SPR_IDX_SELECT
		.BYTE	$02,$06		; DELAY
		.BYTE	$1E,$39		; SPR_IDX_SELECT
		.BYTE	$02,$06		; DELAY
		.BYTE	$1E,$3A		; SPR_IDX_SELECT
		.BYTE	$02,$06		; DELAY
		.BYTE	$31,$1E		; TARGET_DIR_SET
byte_685DE:
		.BYTE	$07
		.WORD	byte_685AE
		.BYTE	$05		; NJSR
		.WORD	_native_get_obj_y_delta
		.BYTE	$0B		; SBEQ
		.WORD	byte_685DE
		.BYTE	$29,$00		; OBJ_SET_X_DELTA
		.BYTE	$08		; RET
byte_685EA:
		.BYTE	$05
		.WORD	_native_sub000
		.BYTE	$05		; NJSR
		.WORD	_native_get_obj_y_delta
		.BYTE	$0D		; SBMI
		.WORD	byte_685F5
		.BYTE	$17,$6B		; APU_LOAD
byte_685F5:
		.BYTE	$01
		.BYTE	$05		; NJSR
		.WORD	_native_get_obj_y_delta
		.BYTE	$0B		; SBEQ
		.WORD	byte_68613
		.BYTE	$05		; NJSR
		.WORD	_obj_move_hor_animate
		.BYTE	$05		; NJSR
		.WORD	_native_sub104
		.BYTE	$0F		; SBCC
		.WORD	byte_6860A
		.BYTE	$2A,$CF		; OBJ_SET_Y_DELTA
		.BYTE	$06		; SJMP
		.WORD	byte_68638
byte_6860A:
		.BYTE	$05
		.WORD	_native_sub118
		.BYTE	$0C		; SBCS
		.WORD	byte_68636
		.BYTE	$06		; SJMP
		.WORD	byte_68638
byte_68613:
		.BYTE	$05
		.WORD	_obj_move_hor_animate
		.BYTE	$05		; NJSR
		.WORD	_native_sub104
		.BYTE	$05		; NJSR
		.WORD	_native_sub109
		.BYTE	$05		; NJSR
		.WORD	_native_get_obj_y_delta
		.BYTE	$10		; SBPL
		.WORD	byte_6862D
		.BYTE	$05		; NJSR
		.WORD	_native_sub10B
		.BYTE	$0C		; SBCS
		.WORD	byte_68638
		.BYTE	$2A,$00		; OBJ_SET_Y_DELTA
		.BYTE	$06		; SJMP
		.WORD	byte_68638
byte_6862D:
		.BYTE	$05
		.WORD	_obj_vert_animate
		.BYTE	$05		; NJSR
		.WORD	_native_sub10A
		.BYTE	$0F		; SBCC
		.WORD	byte_68638
byte_68636:
		.BYTE	$2A,$01
byte_68638:
		.BYTE	$0A,$20
		.WORD	byte_685F5
		.BYTE	$08		; RET

; =============== S U B	R O U T	I N E =======================================
_native_sub000:
		LDA		_scr_vars19,X
		STA		_scr_loopsB,X
		RTS
byte_68644:
		.BYTE	$1E,$3B
		.BYTE	$05		; NJSR
		.WORD	_native_get_obj_hp
		.BYTE	$0E		; SBNE
		.WORD	byte_68087
		.BYTE	$32,$05,$18	; OBJ_SET_SIZE
		.BYTE	$07		; SJSR
		.WORD	byte_680E7
		.BYTE	$29,$00		; OBJ_SET_X_DELTA
		.BYTE	$05		; NJSR
		.WORD	_scr_param_4_clear
byte_68657:
		.BYTE	$1E,$3B
		.BYTE	$07		; SJSR
		.WORD	byte_6867F
		.BYTE	$1E,$3C		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	byte_6867F
		.BYTE	$0A,$14		; LOOPB
		.WORD	byte_68657
		.BYTE	$05		; NJSR
		.WORD	_scr_param_10_set
byte_68668:
		.BYTE	$1E,$3B
		.BYTE	$07		; SJSR
		.WORD	byte_6867F
		.BYTE	$1E,$3C		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	byte_6867F
		.BYTE	$0A,$05		; LOOPB
		.WORD	byte_68668
		.BYTE	$05		; NJSR
		.WORD	_scr_param_10_clear
		.BYTE	$05		; NJSR
		.WORD	_players_animB_sub0129_sub06_A
		.BYTE	$06		; SJMP
		.WORD	_obj_scr2D
byte_6867F:
		.BYTE	$01
		.BYTE	$05		; NJSR
		.WORD	_native_get_obj_var0D
		.BYTE	$10		; SBPL
		.WORD	byte_68694
		.BYTE	$05		; NJSR
		.WORD	_native_sub118
		.BYTE	$0F		; SBCC
		.WORD	byte_6868F
		.BYTE	$07		; SJSR
		.WORD	byte_68044
byte_6868F:
		.BYTE	$09,$0C
		.WORD	byte_6867F
		.BYTE	$08		; RET
byte_68694:
		.BYTE	$1E,$5C
		.BYTE	$07		; SJSR
		.WORD	byte_68102
		.BYTE	$33,$02		; VAR_1C_SET
		.BYTE	$29,$C0		; OBJ_SET_X_DELTA
		.BYTE	$05		; NJSR
		.WORD	_native_sub11B
		.BYTE	$05		; NJSR
		.WORD	_native_sub11C
		.BYTE	$05		; NJSR
		.WORD	_native_sub11D
		.BYTE	$06		; SJMP
		.WORD	byte_68092
_obj_scr2E:
		.BYTE	$07
		.WORD	_script202
byte_686AC:
		.BYTE	$03
		.WORD	_native_sub11E
		.BYTE	$0B		; SBEQ
		.WORD	byte_686AC
		.BYTE	$05		; NJSR
		.WORD	_native_cmp40_obj_x_lo_pos
		.BYTE	$0F		; SBCC
		.WORD	byte_686AC
		.BYTE	$05		; NJSR
		.WORD	_native_cmpC0_obj_x_lo_pos
		.BYTE	$0C		; SBCS
		.WORD	byte_686AC
		.BYTE	$04,$06		; RUN
		.WORD	_script103
		.BYTE	$02,$3D		; DELAY
		.BYTE	$06		; SJMP
		.WORD	byte_686AC
_script103:
		.BYTE	$02,$1E
		.BYTE	$42		; DESTR_PC_SET
		.WORD	byte_68087
		.BYTE	$1D,$09		; SPR_LIB_SELECT
		.BYTE	$34,$01		; OBJ_SET_HP
		.BYTE	$33,$01		; VAR_1C_SET
		.BYTE	$1B		; PARAM_80_CLEAR
		.BYTE	$32,$08,$14	; OBJ_SET_SIZE
		.BYTE	$29,$10		; OBJ_SET_X_DELTA
		.BYTE	$25,$80,$00	; OBJ_SET_X_POS
		.BYTE	$05		; NJSR
		.WORD	_native_sub001
		.BYTE	$05		; NJSR
		.WORD	_native_sub121
		.BYTE	$05		; NJSR
		.WORD	_native_sub110
		.BYTE	$05		; NJSR
		.WORD	_native_sub10F
byte_686E7:
		.BYTE	$1E,$00
		.BYTE	$07		; SJSR
		.WORD	byte_6870C
		.BYTE	$1E,$01		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	byte_6870C
		.BYTE	$1E,$02		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	byte_6870C
		.BYTE	$09,$03		; LOOPA
		.WORD	byte_686E7
		.BYTE	$1E,$03		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	byte_6870C
		.BYTE	$1E,$04		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	byte_6870C
		.BYTE	$1E,$05		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	byte_6870C
		.BYTE	$06		; SJMP
		.WORD	byte_686E7
byte_6870C:
		.BYTE	$03
		.WORD	_native_sub122
		.BYTE	$09,$04		; LOOPA
		.WORD	byte_6870C
		.BYTE	$08		; RET

; =============== S U B	R O U T	I N E =======================================
_native_sub001:
		LDY		byte_AB
		LDA		_obj_flips,Y
		AND		#$40
		ORA		_obj_flips,X
		STA		_obj_flips,X
		RTS
_obj_scr2F:
		.BYTE	$03
		.WORD	_native_sub11E
		.BYTE	$0E		; SBNE
		.WORD	byte_68729
		.BYTE	$00		; STOP
byte_68729:
		.BYTE	$42
		.WORD	byte_68087
		.BYTE	$1D,$09		; SPR_LIB_SELECT
		.BYTE	$1E,$00		; SPR_IDX_SELECT
		.BYTE	$34,$01		; OBJ_SET_HP
		.BYTE	$33,$01		; VAR_1C_SET
		.BYTE	$32,$08,$14	; OBJ_SET_SIZE
		.BYTE	$07		; SJSR
		.WORD	_script201
		.BYTE	$05		; NJSR
		.WORD	_native_sub10E
		.BYTE	$31,$20		; TARGET_DIR_SET
byte_6873F:
		.BYTE	$1E,$00
		.BYTE	$07		; SJSR
		.WORD	byte_68751
		.BYTE	$1E,$01		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	byte_68751
		.BYTE	$1E,$02		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	byte_68751
		.BYTE	$06		; SJMP
		.WORD	byte_6873F
byte_68751:
		.BYTE	$05
		.WORD	_native_sub123
		.BYTE	$05		; NJSR
		.WORD	_native_sub124
		.BYTE	$05		; NJSR
		.WORD	_native_sub125
		.BYTE	$0B		; SBEQ
		.WORD	byte_68763
		.BYTE	$05		; NJSR
		.WORD	_native_sub126
		.BYTE	$06		; SJMP
		.WORD	byte_68766
byte_68763:
		.BYTE	$05
		.WORD	_native_sub127
byte_68766:
		.BYTE	$05
		.WORD	_obj_vert_animate
		.BYTE	$18		; JMP_OBJ_ANIMATE
		.BYTE	$05		; NJSR
		.WORD	_native_sub128
		.BYTE	$0F		; SBCC
		.WORD	byte_68773
		.BYTE	$41		; BREAK
		.WORD	byte_68778
byte_68773:
		.BYTE	$0A,$04
		.WORD	byte_68751
		.BYTE	$08		; RET
byte_68778:
		.BYTE	$2F,$18
		.BYTE	$05		; NJSR
		.WORD	_native_sub10E
		.BYTE	$05		; NJSR
		.WORD	_native_sub111
		.BYTE	$15		; LOOPA_RESET
byte_68781:
		.BYTE	$1E,$00
		.BYTE	$07		; SJSR
		.WORD	byte_687A2
		.BYTE	$1E,$01		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	byte_687A2
		.BYTE	$1E,$02		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	byte_687A2
		.BYTE	$1E,$03		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	byte_687A2
		.BYTE	$1E,$04		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	byte_687A2
		.BYTE	$1E,$05		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	byte_687A2
		.BYTE	$06		; SJMP
		.WORD	byte_68781
byte_687A2:
		.BYTE	$01
		.BYTE	$31,$FF		; TARGET_DIR_SET
		.BYTE	$1A		; TARGET_FOLLOW
		.BYTE	$09,$04		; LOOPA
		.WORD	byte_687A2
		.BYTE	$08		; RET
_obj_scr2C:
		.BYTE	$42
		.WORD	byte_68087
		.BYTE	$1D,$07		; SPR_LIB_SELECT
		.BYTE	$1E,$4D		; SPR_IDX_SELECT
		.BYTE	$34,$02		; OBJ_SET_HP
		.BYTE	$33,$01		; VAR_1C_SET
		.BYTE	$32,$0C,$20	; OBJ_SET_SIZE
		.BYTE	$07		; SJSR
		.WORD	_script201
		.BYTE	$2A,$10		; OBJ_SET_Y_DELTA
byte_687BE:
		.BYTE	$17,$68
byte_687C0:
		.BYTE	$03
		.WORD	_obj_vert_animate
		.BYTE	$09,$08		; LOOPA
		.WORD	byte_687C0
		.BYTE	$0A,$04		; LOOPB
		.WORD	byte_687BE
		.BYTE	$05		; NJSR
		.WORD	_native_sub129
		.BYTE	$05		; NJSR
		.WORD	_native_sub12A
		.BYTE	$12		; SWITCH
		.WORD	_tmp_ptrE+1
		.WORD	byte_687BE
		.WORD	byte_687DA
		.WORD	byte_687DF
byte_687DA:
		.BYTE	$02,$78
		.BYTE	$06		; SJMP
		.WORD	byte_687BE
byte_687DF:
		.BYTE	$1E,$4E
		.BYTE	$02,$10		; DELAY
		.BYTE	$1E,$4F		; SPR_IDX_SELECT
		.BYTE	$04,$07		; RUN
		.WORD	_script104
		.BYTE	$02,$10		; DELAY
		.BYTE	$1E,$4E		; SPR_IDX_SELECT
		.BYTE	$02,$10		; DELAY
		.BYTE	$1E,$4F		; SPR_IDX_SELECT
		.BYTE	$04,$07		; RUN
		.WORD	_script105
		.BYTE	$02,$10		; DELAY
		.BYTE	$1E,$4D		; SPR_IDX_SELECT
		.BYTE	$02,$10		; DELAY
		.BYTE	$06		; SJMP
		.WORD	byte_687BE
_script104:
		.BYTE	$29,$18
		.BYTE	$06		; SJMP
		.WORD	byte_68805
_script105:
		.BYTE	$29,$0C
byte_68805:
		.BYTE	$27,$1C
		.BYTE	$28,$F8		; OBJ_MOVE_Y_POS
		.BYTE	$05		; NJSR
		.WORD	_native_sub12B
		.BYTE	$1D,$07		; SPR_LIB_SELECT
		.BYTE	$2A,$00		; OBJ_SET_Y_DELTA
		.BYTE	$1B		; PARAM_80_CLEAR
		.BYTE	$34,$01		; OBJ_SET_HP
		.BYTE	$33,$01		; VAR_1C_SET
		.BYTE	$32,$06,$08	; OBJ_SET_SIZE
byte_68818:
		.BYTE	$1E,$50
byte_6881A:
		.BYTE	$18
		.BYTE	$2C		; OBJ_INC_Y_DELTA
		.BYTE	$2C		; OBJ_INC_Y_DELTA
		.BYTE	$09,$08		; LOOPA
		.WORD	byte_6881A
		.BYTE	$1E,$51		; SPR_IDX_SELECT
byte_68823:
		.BYTE	$18
		.BYTE	$2C		; OBJ_INC_Y_DELTA
		.BYTE	$2C		; OBJ_INC_Y_DELTA
		.BYTE	$09,$08		; LOOPA
		.WORD	byte_68823
		.BYTE	$06		; SJMP
		.WORD	byte_68818
_obj_scr30:
		.BYTE	$42
		.WORD	byte_688AC
		.BYTE	$1D,$07		; SPR_LIB_SELECT
		.BYTE	$1E,$53		; SPR_IDX_SELECT
		.BYTE	$34,$02		; OBJ_SET_HP
		.BYTE	$33,$01		; VAR_1C_SET
		.BYTE	$32,$0A,$20	; OBJ_SET_SIZE
		.BYTE	$07		; SJSR
		.WORD	_script201
		.BYTE	$05		; NJSR
		.WORD	_native_sub10E
byte_68841:
		.BYTE	$29,$18
		.BYTE	$1E,$52		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	byte_68867
		.BYTE	$29,$10		; OBJ_SET_X_DELTA
		.BYTE	$1E,$53		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	byte_68867
		.BYTE	$29,$E8		; OBJ_SET_X_DELTA
		.BYTE	$1E,$54		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	byte_68867
		.BYTE	$29,$F0		; OBJ_SET_X_DELTA
		.BYTE	$1E,$53		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	byte_68867
byte_6885D:
		.BYTE	$1E,$53
		.BYTE	$02,$1E		; DELAY
		.BYTE	$05		; NJSR
		.WORD	_native_sub110
		.BYTE	$06		; SJMP
		.WORD	byte_68841
byte_68867:
		.BYTE	$15
		.BYTE	$17,$40		; APU_LOAD
		.BYTE	$05		; NJSR
		.WORD	_native_sub10F
byte_6886D:
		.BYTE	$01
		.BYTE	$05		; NJSR
		.WORD	_obj_move_hor_animate
		.BYTE	$05		; NJSR
		.WORD	_native_sub104
		.BYTE	$0F		; SBCC
		.WORD	byte_6887A
		.BYTE	$41		; BREAK
		.WORD	byte_6885D
byte_6887A:
		.BYTE	$05
		.WORD	_native_sub118
		.BYTE	$0C		; SBCS
		.WORD	byte_68036
		.BYTE	$09,$0E		; LOOPA
		.WORD	byte_6886D
		.BYTE	$05		; NJSR
		.WORD	_native_sub116
		.BYTE	$0C		; SBCS
		.WORD	byte_6888B
		.BYTE	$08		; RET
byte_6888B:
		.BYTE	$1E,$55
		.BYTE	$29,$30		; OBJ_SET_X_DELTA
		.BYTE	$05		; NJSR
		.WORD	_native_sub10E
		.BYTE	$05		; NJSR
		.WORD	_native_sub10F
byte_68895:
		.BYTE	$01
		.BYTE	$05		; NJSR
		.WORD	_obj_move_hor_animate
		.BYTE	$05		; NJSR
		.WORD	_native_sub104
		.BYTE	$0C		; SBCS
		.WORD	byte_688A9
		.BYTE	$05		; NJSR
		.WORD	_native_sub118
		.BYTE	$0C		; SBCS
		.WORD	byte_68036
		.BYTE	$09,$20		; LOOPA
		.WORD	byte_68895
byte_688A9:
		.BYTE	$41
		.WORD	byte_68841
byte_688AC:
		.BYTE	$1E,$56
		.BYTE	$05		; NJSR
		.WORD	_native_get_obj_hp
		.BYTE	$0E		; SBNE
		.WORD	byte_68087
		.BYTE	$07		; SJSR
		.WORD	byte_6809D
		.BYTE	$06		; SJMP
		.WORD	_obj_scr30
_obj_scr31:
		.BYTE	$42
		.WORD	byte_68087
		.BYTE	$1D,$07		; SPR_LIB_SELECT
		.BYTE	$1E,$57		; SPR_IDX_SELECT
		.BYTE	$32,$0C,$18	; OBJ_SET_SIZE
		.BYTE	$34,$01		; OBJ_SET_HP
		.BYTE	$33,$01		; VAR_1C_SET
		.BYTE	$07		; SJSR
		.WORD	_script201
		.BYTE	$05		; NJSR
		.WORD	_native_sub10E
byte_688CE:
		.BYTE	$29,$E0
		.BYTE	$2A,$00		; OBJ_SET_Y_DELTA
		.BYTE	$05		; NJSR
		.WORD	_native_sub10F
		.BYTE	$17,$41		; APU_LOAD
		.BYTE	$1E,$57		; SPR_IDX_SELECT
byte_688D9:
		.BYTE	$07
		.WORD	byte_688F8
		.BYTE	$05		; NJSR
		.WORD	_native_sub116
		.BYTE	$0C		; SBCS
		.WORD	byte_6890C
		.BYTE	$09,$08		; LOOPA
		.WORD	byte_688D9
		.BYTE	$1E,$58		; SPR_IDX_SELECT
byte_688E8:
		.BYTE	$07
		.WORD	byte_688F8
		.BYTE	$05		; NJSR
		.WORD	_native_sub116
		.BYTE	$0C		; SBCS
		.WORD	byte_6890C
		.BYTE	$09,$08		; LOOPA
		.WORD	byte_688E8
		.BYTE	$06		; SJMP
		.WORD	byte_688CE
byte_688F8:
		.BYTE	$01
		.BYTE	$05		; NJSR
		.WORD	_obj_move_hor_animate
		.BYTE	$05		; NJSR
		.WORD	_native_sub104
		.BYTE	$0F		; SBCC
		.WORD	byte_68905
		.BYTE	$05		; NJSR
		.WORD	_native_sub110
byte_68905:
		.BYTE	$05
		.WORD	_native_sub118
		.BYTE	$0C		; SBCS
		.WORD	byte_68036
		.BYTE	$08		; RET
byte_6890C:
		.BYTE	$2A,$C0
		.BYTE	$07		; SJSR
		.WORD	byte_68036
byte_68911:
		.BYTE	$05
		.WORD	_obj_move_hor_animate
		.BYTE	$05		; NJSR
		.WORD	_native_sub104
		.BYTE	$05		; NJSR
		.WORD	_native_sub12C
		.BYTE	$03		; NJMP
		.WORD	_native_get_obj_x_delta
		.BYTE	$0B		; SBEQ
		.WORD	byte_68911
		.BYTE	$02,$0A		; DELAY
		.BYTE	$05		; NJSR
		.WORD	_native_sub110
		.BYTE	$29,$E0		; OBJ_SET_X_DELTA
		.BYTE	$2A,$00		; OBJ_SET_Y_DELTA
		.BYTE	$05		; NJSR
		.WORD	_native_sub10F
byte_6892C:
		.BYTE	$17,$41
		.BYTE	$1E,$57		; SPR_IDX_SELECT
byte_68930:
		.BYTE	$07
		.WORD	byte_688F8
		.BYTE	$09,$08		; LOOPA
		.WORD	byte_68930
		.BYTE	$1E,$58		; SPR_IDX_SELECT
byte_68939:
		.BYTE	$07
		.WORD	byte_688F8
		.BYTE	$09,$08		; LOOPA
		.WORD	byte_68939
		.BYTE	$06		; SJMP
		.WORD	byte_6892C
_obj_scr32:
		.BYTE	$02,$B4
		.BYTE	$04,$07		; RUN
		.WORD	_script106
		.BYTE	$06		; SJMP
		.WORD	_obj_scr32
_script106:
		.BYTE	$05
		.WORD	_native_sub12B
		.BYTE	$27,$08		; OBJ_MOVE_X_POS
		.BYTE	$28,$12		; OBJ_MOVE_Y_POS
		.BYTE	$1D,$07		; SPR_LIB_SELECT
		.BYTE	$05		; NJSR
		.WORD	_scr_param_4_set
		.BYTE	$1B		; PARAM_80_CLEAR
		.BYTE	$1E,$4B		; SPR_IDX_SELECT
		.BYTE	$02,$14		; DELAY
		.BYTE	$1E,$69		; SPR_IDX_SELECT
		.BYTE	$02,$14		; DELAY
		.BYTE	$05		; NJSR
		.WORD	_scr_param_4_clear
		.BYTE	$32,$05,$10	; OBJ_SET_SIZE
		.BYTE	$34,$01		; OBJ_SET_HP
		.BYTE	$33,$01		; VAR_1C_SET
		.BYTE	$1E,$59		; SPR_IDX_SELECT
		.BYTE	$02,$3C		; DELAY
		.BYTE	$17,$4E		; APU_LOAD
		.BYTE	$06		; SJMP
		.WORD	byte_68096
_obj_scr33:
		.BYTE	$42
		.WORD	byte_689C0
		.BYTE	$05		; NJSR
		.WORD	_scr_param_4_set
		.BYTE	$1D,$07		; SPR_LIB_SELECT
		.BYTE	$34,$01		; OBJ_SET_HP
		.BYTE	$33,$01		; VAR_1C_SET
		.BYTE	$32,$08,$14	; OBJ_SET_SIZE
byte_68983:
		.BYTE	$01
		.BYTE	$05		; NJSR
		.WORD	_native_sub128
		.BYTE	$0F		; SBCC
		.WORD	byte_68983
		.BYTE	$05		; NJSR
		.WORD	_native_sub10E
		.BYTE	$1B		; PARAM_80_CLEAR
		.BYTE	$1E,$64		; SPR_IDX_SELECT
		.BYTE	$02,$08		; DELAY
		.BYTE	$05		; NJSR
		.WORD	_scr_param_4_clear
		.BYTE	$1E,$65		; SPR_IDX_SELECT
		.BYTE	$02,$08		; DELAY
byte_68999:
		.BYTE	$04,$07
		.WORD	_script107
		.BYTE	$1E,$66		; SPR_IDX_SELECT
		.BYTE	$02,$10		; DELAY
		.BYTE	$17,$50		; APU_LOAD
		.BYTE	$04,$07		; RUN
		.WORD	_script108
		.BYTE	$1E,$67		; SPR_IDX_SELECT
		.BYTE	$02,$10		; DELAY
		.BYTE	$09,$02		; LOOPA
		.WORD	byte_68999
		.BYTE	$1E,$65		; SPR_IDX_SELECT
		.BYTE	$02,$08		; DELAY
		.BYTE	$05		; NJSR
		.WORD	_scr_param_4_set
		.BYTE	$1E,$64		; SPR_IDX_SELECT
		.BYTE	$02,$08		; DELAY
		.BYTE	$1C		; PARAM_80_SET
		.BYTE	$02,$5A		; DELAY
		.BYTE	$06		; SJMP
		.WORD	byte_68983
byte_689C0:
		.BYTE	$1E,$40
		.BYTE	$06		; SJMP
		.WORD	byte_68087
_script107:
		.BYTE	$28,$F2
		.BYTE	$05		; NJSR
		.WORD	_native_sub119
		.BYTE	$34,$01		; OBJ_SET_HP
		.BYTE	$33,$01		; VAR_1C_SET
		.BYTE	$32,$08,$0A	; OBJ_SET_SIZE
		.BYTE	$02,$10		; DELAY
		.BYTE	$00		; STOP
_script108:
		.BYTE	$34,$01
		.BYTE	$33,$01		; VAR_1C_SET
		.BYTE	$32,$06,$0F	; OBJ_SET_SIZE
		.BYTE	$1D,$07		; SPR_LIB_SELECT
		.BYTE	$1E,$68		; SPR_IDX_SELECT
		.BYTE	$29,$10		; OBJ_SET_X_DELTA
		.BYTE	$2A,$E0		; OBJ_SET_Y_DELTA
		.BYTE	$05		; NJSR
		.WORD	_native_sub12E
		.BYTE	$1B		; PARAM_80_CLEAR
		.BYTE	$1F		; FLIP_40_CLEAR
byte_689E8:
		.BYTE	$07
		.WORD	byte_689FB
		.BYTE	$22		; FLIP_80_SET
		.BYTE	$07		; SJSR
		.WORD	byte_689FB
		.BYTE	$20		; FLIP_40_SET
		.BYTE	$07		; SJSR
		.WORD	byte_689FB
		.BYTE	$21		; FLIP_80_CLEAR
		.BYTE	$07		; SJSR
		.WORD	byte_689FB
		.BYTE	$1F		; FLIP_40_CLEAR
		.BYTE	$06		; SJMP
		.WORD	byte_689E8
byte_689FB:
		.BYTE	$18
		.BYTE	$05		; NJSR
		.WORD	_native_sub109
		.BYTE	$09,$04		; LOOPA
		.WORD	byte_689FB
		.BYTE	$08		; RET
_obj_scr34:
		.BYTE	$42
		.WORD	byte_68087
		.BYTE	$1D,$07		; SPR_LIB_SELECT
		.BYTE	$1E,$5E		; SPR_IDX_SELECT
		.BYTE	$32,$0C,$18	; OBJ_SET_SIZE
		.BYTE	$34,$01		; OBJ_SET_HP
		.BYTE	$33,$01		; VAR_1C_SET
		.BYTE	$07		; SJSR
		.WORD	_script201
		.BYTE	$05		; NJSR
		.WORD	_native_sub10E
		.BYTE	$29,$E8		; OBJ_SET_X_DELTA
		.BYTE	$05		; NJSR
		.WORD	_native_sub10F
byte_68A1D:
		.BYTE	$17,$3E
byte_68A1F:
		.BYTE	$1E,$5E
		.BYTE	$07		; SJSR
		.WORD	byte_68A69
		.BYTE	$1E,$5F		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	byte_68A69
		.BYTE	$1E,$5E		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	byte_68A69
		.BYTE	$1E,$5F		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	byte_68A69
		.BYTE	$0A,$02		; LOOPB
		.WORD	byte_68A1F
		.BYTE	$05		; NJSR
		.WORD	_native_sub110
		.BYTE	$06		; SJMP
		.WORD	byte_68A1D
byte_68A3D:
		.BYTE	$1E,$60
		.BYTE	$02,$08		; DELAY
		.BYTE	$1E,$63		; SPR_IDX_SELECT
		.BYTE	$02,$08		; DELAY
		.BYTE	$0A,$04		; LOOPB
		.WORD	byte_68A3D
		.BYTE	$29,$20		; OBJ_SET_X_DELTA
		.BYTE	$05		; NJSR
		.WORD	_native_sub10F
byte_68A4E:
		.BYTE	$1E,$62
		.BYTE	$07		; SJSR
		.WORD	byte_68A77
		.BYTE	$17,$68		; APU_LOAD
		.BYTE	$1E,$63		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	byte_68A77
		.BYTE	$1E,$41		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	byte_68A77
		.BYTE	$17,$68		; APU_LOAD
		.BYTE	$1E,$42		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	byte_68A77
		.BYTE	$06		; SJMP
		.WORD	byte_68A4E
byte_68A69:
		.BYTE	$05
		.WORD	_native_sub116
		.BYTE	$0F		; SBCC
		.WORD	byte_68A77
		.BYTE	$05		; NJSR
		.WORD	_native_sub10E
		.BYTE	$15		; LOOPA_RESET
		.BYTE	$16		; LOOPB_RESET
		.BYTE	$41		; BREAK
		.WORD	byte_68A3D
byte_68A77:
		.BYTE	$01
		.BYTE	$05		; NJSR
		.WORD	_obj_move_hor_animate
		.BYTE	$05		; NJSR
		.WORD	_native_sub104
		.BYTE	$0F		; SBCC
		.WORD	byte_68A86
		.BYTE	$15		; LOOPA_RESET
		.BYTE	$16		; LOOPB_RESET
		.BYTE	$05		; NJSR
		.WORD	_native_sub110
byte_68A86:
		.BYTE	$05
		.WORD	_native_sub118
		.BYTE	$0C		; SBCS
		.WORD	byte_68036
		.BYTE	$09,$07		; LOOPA
		.WORD	byte_68A77
		.BYTE	$08		; RET
_obj_scr35:
		.BYTE	$07
		.WORD	_script202
byte_68A94:
		.BYTE	$03
		.WORD	_native_sub11E
		.BYTE	$0B		; SBEQ
		.WORD	byte_68A94
		.BYTE	$02,$1E		; DELAY
		.BYTE	$04,$06		; RUN
		.WORD	_script109
		.BYTE	$02,$1E		; DELAY
		.BYTE	$06		; SJMP
		.WORD	byte_68A94
_obj_scr36:
		.BYTE	$07
		.WORD	_script202
byte_68AA8:
		.BYTE	$03
		.WORD	_native_sub11E
		.BYTE	$0B		; SBEQ
		.WORD	byte_68AA8
		.BYTE	$02,$1E		; DELAY
		.BYTE	$04,$06		; RUN
		.WORD	_script10A
		.BYTE	$02,$1E		; DELAY
		.BYTE	$06		; SJMP
		.WORD	byte_68AA8
byte_68AB9:
		.BYTE	$42
		.WORD	byte_68087
		.BYTE	$1D,$09		; SPR_LIB_SELECT
		.BYTE	$34,$01		; OBJ_SET_HP
		.BYTE	$33,$01		; VAR_1C_SET
		.BYTE	$1B		; PARAM_80_CLEAR
		.BYTE	$32,$10,$20	; OBJ_SET_SIZE
		.BYTE	$25,$80,$00	; OBJ_SET_X_POS
		.BYTE	$05		; NJSR
		.WORD	_native_sub001
		.BYTE	$05		; NJSR
		.WORD	_native_sub121
		.BYTE	$05		; NJSR
		.WORD	_native_sub110
		.BYTE	$05		; NJSR
		.WORD	_native_sub10F
		.BYTE	$08		; RET
_script109:
		.BYTE	$29,$18
		.BYTE	$07		; SJSR
		.WORD	byte_68AB9
byte_68ADB:
		.BYTE	$1E,$06
		.BYTE	$07		; SJSR
		.WORD	byte_68B01
		.BYTE	$17,$39		; APU_LOAD
		.BYTE	$1E,$07		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	byte_68B0D
		.BYTE	$1E,$08		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	byte_68B0D
		.BYTE	$05		; NJSR
		.WORD	_native_sub128
		.BYTE	$0F		; SBCC
		.WORD	byte_68ADB
		.BYTE	$04,$06		; RUN
		.WORD	_script10B
		.BYTE	$0F		; SBCC
		.WORD	byte_68ADB
		.BYTE	$29,$20		; OBJ_SET_X_DELTA
		.BYTE	$05		; NJSR
		.WORD	_native_sub10F
		.BYTE	$06		; SJMP
		.WORD	byte_68B1A
byte_68B01:
		.BYTE	$2A,$DF
byte_68B03:
		.BYTE	$2C
		.BYTE	$2C		; OBJ_INC_Y_DELTA
		.BYTE	$18		; JMP_OBJ_ANIMATE
		.BYTE	$0A,$20		; LOOPB
		.WORD	byte_68B03
		.BYTE	$2A,$21		; OBJ_SET_Y_DELTA
		.BYTE	$08		; RET
byte_68B0D:
		.BYTE	$2E
		.BYTE	$2E		; OBJ_DEC_Y_DELTA
		.BYTE	$18		; JMP_OBJ_ANIMATE
		.BYTE	$0A,$10		; LOOPB
		.WORD	byte_68B0D
		.BYTE	$08		; RET
_script10A:
		.BYTE	$29,$20
		.BYTE	$07		; SJSR
		.WORD	byte_68AB9
byte_68B1A:
		.BYTE	$1E,$09
		.BYTE	$07		; SJSR
		.WORD	byte_68B2E
		.BYTE	$17,$39		; APU_LOAD
		.BYTE	$1E,$0A		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	byte_68B39
		.BYTE	$1E,$0B		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	byte_68B39
		.BYTE	$06		; SJMP
		.WORD	byte_68B1A
byte_68B2E:
		.BYTE	$2A,$EF
byte_68B30:
		.BYTE	$2C
		.BYTE	$18		; JMP_OBJ_ANIMATE
		.BYTE	$0A,$20		; LOOPB
		.WORD	byte_68B30
		.BYTE	$2A,$11		; OBJ_SET_Y_DELTA
		.BYTE	$08		; RET
byte_68B39:
		.BYTE	$2E
		.BYTE	$18		; JMP_OBJ_ANIMATE
		.BYTE	$0A,$10		; LOOPB
		.WORD	byte_68B39
		.BYTE	$08		; RET
_script10B:
		.BYTE	$42
		.WORD	byte_68087
		.BYTE	$28,$10		; OBJ_MOVE_Y_POS
		.BYTE	$34,$01		; OBJ_SET_HP
		.BYTE	$33,$01		; VAR_1C_SET
		.BYTE	$32,$06,$0C	; OBJ_SET_SIZE
		.BYTE	$1D,$07		; SPR_LIB_SELECT
		.BYTE	$1E,$6A		; SPR_IDX_SELECT
		.BYTE	$2A,$08		; OBJ_SET_Y_DELTA
		.BYTE	$1B		; PARAM_80_CLEAR
byte_68B53:
		.BYTE	$01
		.BYTE	$05		; NJSR
		.WORD	_native_sub109
		.BYTE	$05		; NJSR
		.WORD	_native_sub10B
		.BYTE	$0C		; SBCS
		.WORD	byte_68B53
		.BYTE	$2A,$00		; OBJ_SET_Y_DELTA
		.BYTE	$17,$3B		; APU_LOAD
		.BYTE	$1E,$6B		; SPR_IDX_SELECT
		.BYTE	$02,$08		; DELAY
		.BYTE	$1E,$6C		; SPR_IDX_SELECT
		.BYTE	$02,$08		; DELAY
		.BYTE	$1E,$6D		; SPR_IDX_SELECT
		.BYTE	$02,$08		; DELAY
		.BYTE	$1E,$6F		; SPR_IDX_SELECT
		.BYTE	$02,$08		; DELAY
		.BYTE	$29,$10		; OBJ_SET_X_DELTA
		.BYTE	$03		; NJMP
		.WORD	_native_sub10E
		.BYTE	$03		; NJMP
		.WORD	_native_sub10F
byte_68B79:
		.BYTE	$1E,$6E
		.BYTE	$07		; SJSR
		.WORD	byte_68B90
		.BYTE	$1E,$6F		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	byte_68B90
		.BYTE	$1E,$70		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	byte_68B90
		.BYTE	$1E,$6F		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	byte_68B90
		.BYTE	$06		; SJMP
		.WORD	byte_68B79
byte_68B90:
		.BYTE	$01
		.BYTE	$05		; NJSR
		.WORD	_obj_move_hor_animate
		.BYTE	$05		; NJSR
		.WORD	_native_sub104
		.BYTE	$0C		; SBCS
		.WORD	byte_68BA5
		.BYTE	$05		; NJSR
		.WORD	_native_sub118
		.BYTE	$0C		; SBCS
		.WORD	byte_68BA5
		.BYTE	$09,$08		; LOOPA
		.WORD	byte_68B90
		.BYTE	$08		; RET
byte_68BA5:
		.BYTE	$15
		.BYTE	$1E,$6F		; SPR_IDX_SELECT
		.BYTE	$2A,$C0		; OBJ_SET_Y_DELTA
		.BYTE	$07		; SJSR
		.WORD	byte_68036
		.BYTE	$41		; BREAK
		.WORD	byte_68B79
_obj_scr37:
		.BYTE	$42
		.WORD	byte_68087
		.BYTE	$1D,$07		; SPR_LIB_SELECT
		.BYTE	$1E,$43		; SPR_IDX_SELECT
		.BYTE	$32,$0C,$18	; OBJ_SET_SIZE
		.BYTE	$34,$01		; OBJ_SET_HP
		.BYTE	$33,$01		; VAR_1C_SET
		.BYTE	$07		; SJSR
		.WORD	_script201
		.BYTE	$05		; NJSR
		.WORD	_native_sub10E
		.BYTE	$29,$10		; OBJ_SET_X_DELTA
		.BYTE	$05		; NJSR
		.WORD	_native_sub10F
byte_68BC9:
		.BYTE	$1E,$44
		.BYTE	$07		; SJSR
		.WORD	byte_68C0D
		.BYTE	$1E,$45		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	byte_68C0D
		.BYTE	$1E,$46		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	byte_68C0D
		.BYTE	$1E,$45		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	byte_68C0D
		.BYTE	$06		; SJMP
		.WORD	byte_68BC9
byte_68BE0:
		.BYTE	$1E,$47
		.BYTE	$02,$05		; DELAY
		.BYTE	$1E,$48		; SPR_IDX_SELECT
		.BYTE	$02,$05		; DELAY
		.BYTE	$09,$04		; LOOPA
		.WORD	byte_68BE0
		.BYTE	$17,$6D		; APU_LOAD
		.BYTE	$04,$07		; RUN
		.WORD	_script10C
		.BYTE	$1E,$49		; SPR_IDX_SELECT
		.BYTE	$02,$2A		; DELAY
byte_68BF6:
		.BYTE	$1E,$44
		.BYTE	$07		; SJSR
		.WORD	byte_68C22
		.BYTE	$1E,$45		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	byte_68C22
		.BYTE	$1E,$46		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	byte_68C22
		.BYTE	$1E,$45		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	byte_68C22
		.BYTE	$06		; SJMP
		.WORD	byte_68BF6
byte_68C0D:
		.BYTE	$05
		.WORD	_native_sub115
		.BYTE	$0F		; SBCC
		.WORD	byte_68C22
		.BYTE	$05		; NJSR
		.WORD	_native_sub112
		.BYTE	$0F		; SBCC
		.WORD	byte_68C22
		.BYTE	$05		; NJSR
		.WORD	_native_sub10E
		.BYTE	$05		; NJSR
		.WORD	_native_sub10F
		.BYTE	$41		; BREAK
		.WORD	byte_68BE0
byte_68C22:
		.BYTE	$01
		.BYTE	$05		; NJSR
		.WORD	_obj_move_hor_animate
		.BYTE	$05		; NJSR
		.WORD	_native_sub104
		.BYTE	$0C		; SBCS
		.WORD	byte_68C37
		.BYTE	$05		; NJSR
		.WORD	_native_sub118
		.BYTE	$0C		; SBCS
		.WORD	byte_68C37
		.BYTE	$09,$0B		; LOOPA
		.WORD	byte_68C22
		.BYTE	$08		; RET
byte_68C37:
		.BYTE	$15
		.BYTE	$1E,$45		; SPR_IDX_SELECT
		.BYTE	$2A,$C0		; OBJ_SET_Y_DELTA
		.BYTE	$06		; SJMP
		.WORD	byte_68036
_script10C:
		.BYTE	$34,$01
		.BYTE	$33,$01		; VAR_1C_SET
		.BYTE	$32,$04,$08	; OBJ_SET_SIZE
		.BYTE	$1D,$07		; SPR_LIB_SELECT
		.BYTE	$1E,$4A		; SPR_IDX_SELECT
		.BYTE	$28,$DF		; OBJ_MOVE_Y_POS
		.BYTE	$29,$20		; OBJ_SET_X_DELTA
		.BYTE	$2A,$E0		; OBJ_SET_Y_DELTA
		.BYTE	$05		; NJSR
		.WORD	_native_sub12E
		.BYTE	$1B		; PARAM_80_CLEAR
		.BYTE	$06		; SJMP
		.WORD	byte_68096
_obj_scr3C:
		.BYTE	$07
		.WORD	byte_68CCC
byte_68C5A:
		.BYTE	$03
		.WORD	_native_cmp20_obj_x_lo_pos
		.BYTE	$0F		; SBCC
		.WORD	byte_68C5A
		.BYTE	$05		; NJSR
		.WORD	_native_cmpE0_obj_x_lo_pos
		.BYTE	$0C		; SBCS
		.WORD	byte_68C5A
		.BYTE	$2A,$20		; OBJ_SET_Y_DELTA
byte_68C68:
		.BYTE	$07
		.WORD	byte_68C8D
		.BYTE	$09,$05		; LOOPA
		.WORD	byte_68C68
		.BYTE	$2A,$00		; OBJ_SET_Y_DELTA
byte_68C71:
		.BYTE	$07
		.WORD	byte_68C8D
		.BYTE	$09,$04		; LOOPA
		.WORD	byte_68C71
		.BYTE	$29,$20		; OBJ_SET_X_DELTA
		.BYTE	$2A,$F0		; OBJ_SET_Y_DELTA
		.BYTE	$05		; NJSR
		.WORD	_native_sub10F
byte_68C7F:
		.BYTE	$07
		.WORD	byte_68C8D
		.BYTE	$09,$02		; LOOPA
		.WORD	byte_68C7F
		.BYTE	$04,$08		; RUN
		.WORD	_script10D
		.BYTE	$06		; SJMP
		.WORD	byte_68C7F
byte_68C8D:
		.BYTE	$1E,$71
		.BYTE	$07		; SJSR
		.WORD	_script_animate10
		.BYTE	$1E,$72		; SPR_IDX_SELECT
		.BYTE	$06		; SJMP
		.WORD	_script_animate10
_obj_scr3D:
		.BYTE	$07
		.WORD	byte_68CCC
		.BYTE	$31,$20		; TARGET_DIR_SET
byte_68C9C:
		.BYTE	$1E,$71
		.BYTE	$07		; SJSR
		.WORD	byte_68CB1
		.BYTE	$1E,$72		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	byte_68CB1
		.BYTE	$09,$06		; LOOPA
		.WORD	byte_68C9C
		.BYTE	$04,$08		; RUN
		.WORD	_script10D
		.BYTE	$06		; SJMP
		.WORD	byte_68C9C
byte_68CB1:
		.BYTE	$05
		.WORD	_native_sub123
		.BYTE	$05		; NJSR
		.WORD	_native_sub124
		.BYTE	$05		; NJSR
		.WORD	_native_sub125
		.BYTE	$0B		; SBEQ
		.WORD	byte_68CC3
		.BYTE	$05		; NJSR
		.WORD	_native_sub126
		.BYTE	$06		; SJMP
		.WORD	byte_68CC6
byte_68CC3:
		.BYTE	$05
		.WORD	_native_sub127
byte_68CC6:
		.BYTE	$18
		.BYTE	$0A,$08		; LOOPB
		.WORD	byte_68CB1
		.BYTE	$08		; RET
byte_68CCC:
		.BYTE	$42
		.WORD	byte_68087
		.BYTE	$1D,$07		; SPR_LIB_SELECT
		.BYTE	$1E,$71		; SPR_IDX_SELECT
		.BYTE	$34,$01		; OBJ_SET_HP
		.BYTE	$33,$01		; VAR_1C_SET
		.BYTE	$32,$0A,$14	; OBJ_SET_SIZE
		.BYTE	$07		; SJSR
		.WORD	_script201
		.BYTE	$05		; NJSR
		.WORD	_native_sub10E
		.BYTE	$08		; RET
_script10D:
		.BYTE	$05
		.WORD	_native_sub12B
		.BYTE	$17,$29		; APU_LOAD
		.BYTE	$28,$08		; OBJ_MOVE_Y_POS
		.BYTE	$2A,$10		; OBJ_SET_Y_DELTA
		.BYTE	$1D,$07		; SPR_LIB_SELECT
		.BYTE	$1B		; PARAM_80_CLEAR
		.BYTE	$34,$01		; OBJ_SET_HP
		.BYTE	$33,$02		; VAR_1C_SET
		.BYTE	$32,$04,$08	; OBJ_SET_SIZE
byte_68CF4:
		.BYTE	$1E,$73
		.BYTE	$07		; SJSR
		.WORD	_script_animate10
		.BYTE	$1E,$7B		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	_script_animate10
		.BYTE	$06		; SJMP
		.WORD	byte_68CF4
_obj_scr39:
		.BYTE	$1D,$07
		.BYTE	$1E,$77		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	_script201
		.BYTE	$05		; NJSR
		.WORD	_native_sub10E
byte_68D0B:
		.BYTE	$42
		.WORD	byte_68087
		.BYTE	$32,$0A,$0C	; OBJ_SET_SIZE
		.BYTE	$34,$01		; OBJ_SET_HP
		.BYTE	$33,$01		; VAR_1C_SET
		.BYTE	$29,$08		; OBJ_SET_X_DELTA
		.BYTE	$05		; NJSR
		.WORD	_native_sub10F
byte_68D1A:
		.BYTE	$15
		.BYTE	$1E,$77		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	byte_68D35
		.BYTE	$1E,$78		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	byte_68D35
		.BYTE	$1E,$77		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	byte_68D35
		.BYTE	$1E,$79		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	byte_68D35
byte_68D2F:
		.BYTE	$05
		.WORD	_native_sub110
		.BYTE	$06		; SJMP
		.WORD	byte_68D1A
byte_68D35:
		.BYTE	$01
		.BYTE	$05		; NJSR
		.WORD	_native_sub131
		.BYTE	$0F		; SBCC
		.WORD	byte_68D3F
		.BYTE	$41		; BREAK
		.WORD	byte_68D56
byte_68D3F:
		.BYTE	$05
		.WORD	_obj_move_hor_animate
		.BYTE	$05		; NJSR
		.WORD	_native_sub104
		.BYTE	$0F		; SBCC
		.WORD	byte_68D4B
		.BYTE	$41		; BREAK
		.WORD	byte_68D2F
byte_68D4B:
		.BYTE	$05
		.WORD	_native_sub118
		.BYTE	$0C		; SBCS
		.WORD	byte_68036
		.BYTE	$09,$0E		; LOOPA
		.WORD	byte_68D35
		.BYTE	$08		; RET
byte_68D56:
		.BYTE	$42
		.WORD	byte_68D6B
		.BYTE	$32,$0A,$0E	; OBJ_SET_SIZE
		.BYTE	$1E,$7A		; SPR_IDX_SELECT
		.BYTE	$05		; NJSR
		.WORD	_native_sub132
byte_68D61:
		.BYTE	$34,$02
		.BYTE	$01		; FLUSH
		.BYTE	$0A,$1E		; LOOPB
		.WORD	byte_68D61
		.BYTE	$06		; SJMP
		.WORD	byte_68D0B
byte_68D6B:
		.BYTE	$05
		.WORD	_native_get_obj_hp
		.BYTE	$0E		; SBNE
		.WORD	byte_68087
		.BYTE	$05		; NJSR
		.WORD	_scr_param_4_clear
		.BYTE	$06		; SJMP
		.WORD	byte_68D61
_obj_scr3A:
		.BYTE	$07
		.WORD	_script202
byte_68D7A:
		.BYTE	$01
		.BYTE	$05		; NJSR
		.WORD	_native_cmp08_obj_x_lo_pos
		.BYTE	$0C		; SBCS
		.WORD	byte_68D7A
		.BYTE	$42		; DESTR_PC_SET
		.WORD	byte_68087
		.BYTE	$1D,$07		; SPR_LIB_SELECT
		.BYTE	$1E,$75		; SPR_IDX_SELECT
		.BYTE	$32,$08,$20	; OBJ_SET_SIZE
		.BYTE	$34,$01		; OBJ_SET_HP
		.BYTE	$33,$01		; VAR_1C_SET
		.BYTE	$1B		; PARAM_80_CLEAR
		.BYTE	$29,$30		; OBJ_SET_X_DELTA
		.BYTE	$05		; NJSR
		.WORD	_native_sub10E
		.BYTE	$05		; NJSR
		.WORD	_native_sub10F
byte_68D98:
		.BYTE	$1E,$74
		.BYTE	$07		; SJSR
		.WORD	byte_68DA5
		.BYTE	$1E,$76		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	byte_68DA5
		.BYTE	$06		; SJMP
		.WORD	byte_68D98
byte_68DA5:
		.BYTE	$2A,$E0
byte_68DA7:
		.BYTE	$01
		.BYTE	$05		; NJSR
		.WORD	_obj_move_hor_animate
		.BYTE	$05		; NJSR
		.WORD	_native_sub104
		.BYTE	$0F		; SBCC
		.WORD	byte_68DB4
		.BYTE	$05		; NJSR
		.WORD	_native_sub110
byte_68DB4:
		.BYTE	$07
		.WORD	byte_68044
		.BYTE	$0C		; SBCS
		.WORD	byte_68DA7
		.BYTE	$1E,$75		; SPR_IDX_SELECT
		.BYTE	$02,$04		; DELAY
		.BYTE	$08		; RET
_obj_scr38:
		.BYTE	$42
		.WORD	byte_68E18
		.BYTE	$1D,$05		; SPR_LIB_SELECT
		.BYTE	$1E,$3A		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	_script201
		.BYTE	$05		; NJSR
		.WORD	_native_sub10E
		.BYTE	$32,$06,$1C	; OBJ_SET_SIZE
		.BYTE	$33,$01		; VAR_1C_SET
byte_68DD1:
		.BYTE	$34,$01
		.BYTE	$1E,$3A		; SPR_IDX_SELECT
		.BYTE	$02,$40		; DELAY
		.BYTE	$1E,$3B		; SPR_IDX_SELECT
		.BYTE	$02,$10		; DELAY
byte_68DDB:
		.BYTE	$15
		.BYTE	$16		; LOOPB_RESET
		.BYTE	$05		; NJSR
		.WORD	_scr_param_4_clear
		.BYTE	$34,$02		; OBJ_SET_HP
		.BYTE	$07		; SJSR
		.WORD	byte_68DF9
		.BYTE	$07		; SJSR
		.WORD	byte_68DF9
		.BYTE	$04,$07		; RUN
		.WORD	_script10E
		.BYTE	$04,$07		; RUN
		.WORD	_script10F
		.BYTE	$07		; SJSR
		.WORD	byte_68DF9
		.BYTE	$07		; SJSR
		.WORD	byte_68DF9
		.BYTE	$06		; SJMP
		.WORD	byte_68DD1
byte_68DF9:
		.BYTE	$17,$6F
byte_68DFB:
		.BYTE	$1E,$3C
		.BYTE	$02,$02		; DELAY
		.BYTE	$1E,$3D		; SPR_IDX_SELECT
		.BYTE	$02,$02		; DELAY
		.BYTE	$09,$02		; LOOPA
		.WORD	byte_68DFB
byte_68E07:
		.BYTE	$1E,$3E
		.BYTE	$02,$02		; DELAY
		.BYTE	$1E,$3F		; SPR_IDX_SELECT
		.BYTE	$02,$02		; DELAY
		.BYTE	$09,$02		; LOOPA
		.WORD	byte_68E07
		.BYTE	$0A,$02		; LOOPB
		.WORD	byte_68DFB
		.BYTE	$08		; RET
byte_68E18:
		.BYTE	$05
		.WORD	_native_get_obj_hp
		.BYTE	$0B		; SBEQ
		.WORD	byte_68DDB
		.BYTE	$1E,$3A		; SPR_IDX_SELECT
		.BYTE	$06		; SJMP
		.WORD	byte_68087
_script10F:
		.BYTE	$29,$30
		.BYTE	$27,$08		; OBJ_MOVE_X_POS
		.BYTE	$1F		; FLIP_40_CLEAR
		.BYTE	$06		; SJMP
		.WORD	byte_68E30
_script10E:
		.BYTE	$29,$D0
		.BYTE	$27,$F8		; OBJ_MOVE_X_POS
		.BYTE	$20		; FLIP_40_SET
byte_68E30:
		.BYTE	$05
		.WORD	_native_sub12B
		.BYTE	$1D,$05		; SPR_LIB_SELECT
		.BYTE	$32,$04,$08	; OBJ_SET_SIZE
		.BYTE	$34,$01		; OBJ_SET_HP
		.BYTE	$33,$01		; VAR_1C_SET
		.BYTE	$1B		; PARAM_80_CLEAR
byte_68E3D:
		.BYTE	$1E,$05
		.BYTE	$07		; SJSR
		.WORD	byte_68E4A
		.BYTE	$1E,$40		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	byte_68E4A
		.BYTE	$06		; SJMP
		.WORD	byte_68E3D
byte_68E4A:
		.BYTE	$18
		.BYTE	$05		; NJSR
		.WORD	_native_sub104
		.BYTE	$0C		; SBCS
		.WORD	byte_68E5C
		.BYTE	$05		; NJSR
		.WORD	_native_sub118
		.BYTE	$0C		; SBCS
		.WORD	byte_68E5C
		.BYTE	$09,$06		; LOOPA
		.WORD	byte_68E4A
		.BYTE	$08		; RET
byte_68E5C:
		.BYTE	$00
_obj_scr3F:
		.BYTE	$13,$1E
		.WORD	_apu_load_idx_req
		.BYTE	$04,$01		; RUN
		.WORD	_script110
		.BYTE	$42		; DESTR_PC_SET
		.WORD	byte_B6AF1
		.BYTE	$05		; NJSR
		.WORD	_native_sub134
		.BYTE	$27,$0A		; OBJ_MOVE_X_POS
		.BYTE	$1D,$08		; SPR_LIB_SELECT
		.BYTE	$02,$80		; DELAY
		.BYTE	$32,$0A,$32	; OBJ_SET_SIZE
		.BYTE	$34,$06		; OBJ_SET_HP
		.BYTE	$33,$01		; VAR_1C_SET
		.BYTE	$1B		; PARAM_80_CLEAR
		.BYTE	$29,$10		; OBJ_SET_X_DELTA
		.BYTE	$05		; NJSR
		.WORD	_native_sub10E
		.BYTE	$05		; NJSR
		.WORD	_native_sub10F
byte_68E81:
		.BYTE	$1E,$18
		.BYTE	$07		; SJSR
		.WORD	_script206
		.BYTE	$1E,$20		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	_script206
		.BYTE	$09,$02		; LOOPA
		.WORD	byte_68E81
		.BYTE	$07		; SJSR
		.WORD	byte_68F10
byte_68E92:
		.BYTE	$05
		.WORD	_native_sub12A
		.BYTE	$12		; SWITCH
		.WORD	_tmp_ptrE+1
		.WORD	byte_68E9E
		.WORD	byte_68EB4
		.WORD	byte_68EB4
byte_68E9E:
		.BYTE	$29,$00
		.BYTE	$2A,$00		; OBJ_SET_Y_DELTA
		.BYTE	$05		; NJSR
		.WORD	_native_sub10E
		.BYTE	$05		; NJSR
		.WORD	_native_sub113
		.BYTE	$0D		; SBMI
		.WORD	byte_68EAE
		.BYTE	$07		; SJSR
		.WORD	byte_68F2E
byte_68EAE:
		.BYTE	$07
		.WORD	byte_68F2E
		.BYTE	$07		; SJSR
		.WORD	byte_68F10
byte_68EB4:
		.BYTE	$29,$20
		.BYTE	$05		; NJSR
		.WORD	_native_sub10F
		.BYTE	$05		; NJSR
		.WORD	_native_sub113
		.BYTE	$0D		; SBMI
		.WORD	byte_68EC2
		.BYTE	$07		; SJSR
		.WORD	byte_68EC8
byte_68EC2:
		.BYTE	$07
		.WORD	byte_68EC8
		.BYTE	$06		; SJMP
		.WORD	byte_68E92
byte_68EC8:
		.BYTE	$1E,$18
		.BYTE	$07		; SJSR
		.WORD	byte_68ECF
		.BYTE	$1E,$20		; SPR_IDX_SELECT
byte_68ECF:
		.BYTE	$01
		.BYTE	$07		; SJSR
		.WORD	_script20A
		.BYTE	$05		; NJSR
		.WORD	_obj_move_hor_animate
		.BYTE	$05		; NJSR
		.WORD	_native_sub135
		.BYTE	$0C		; SBCS
		.WORD	byte_68EDF
		.BYTE	$05		; NJSR
		.WORD	_native_sub110
byte_68EDF:
		.BYTE	$05
		.WORD	_native_sub118
		.BYTE	$0C		; SBCS
		.WORD	byte_68EEA
		.BYTE	$0A,$0A		; LOOPB
		.WORD	byte_68ECF
		.BYTE	$08		; RET
byte_68EEA:
		.BYTE	$05
		.WORD	_scr_reset_slot
		.BYTE	$05		; NJSR
		.WORD	_native_cmp40_obj_y_lo_pos
		.BYTE	$0E		; SBNE
		.WORD	byte_68F01
		.BYTE	$05		; NJSR
		.WORD	_native_cmpC0_obj_y_lo_pos
		.BYTE	$0E		; SBNE
		.WORD	byte_68EFF
		.BYTE	$05		; NJSR
		.WORD	_native_sub113
		.BYTE	$0D		; SBMI
		.WORD	byte_68F01
byte_68EFF:
		.BYTE	$2A,$AE
byte_68F01:
		.BYTE	$1E,$23
		.BYTE	$29,$00		; OBJ_SET_X_DELTA
		.BYTE	$07		; SJSR
		.WORD	_script20B
		.BYTE	$1E,$1E		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	_script205
		.BYTE	$06		; SJMP
		.WORD	byte_68E92
byte_68F10:
		.BYTE	$29,$00
		.BYTE	$2A,$00		; OBJ_SET_Y_DELTA
		.BYTE	$1E,$15		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	_script205
		.BYTE	$1E,$16		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	_script205
		.BYTE	$1E,$17		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	_script205
		.BYTE	$07		; SJSR
		.WORD	_script205
		.BYTE	$1E,$16		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	_script205
		.BYTE	$1E,$15		; SPR_IDX_SELECT
		.BYTE	$08		; RET
byte_68F2E:
		.BYTE	$1E,$19
		.BYTE	$07		; SJSR
		.WORD	_script203
		.BYTE	$1E,$1A		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	_script203
		.BYTE	$1E,$1B		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	_script208
		.BYTE	$1E,$1C		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	_script204
		.BYTE	$1E,$1D		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	_script203
		.BYTE	$17,$3F		; APU_LOAD
		.BYTE	$04,$07		; RUN
		.WORD	_script111
		.BYTE	$1E,$1E		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	_script205
		.BYTE	$09,$02		; LOOPA
		.WORD	byte_68F2E
		.BYTE	$08		; RET
_script111:
		.BYTE	$28,$E4
		.BYTE	$29,$20		; OBJ_SET_X_DELTA
		.BYTE	$05		; NJSR
		.WORD	_native_sub12E
		.BYTE	$1D,$08		; SPR_LIB_SELECT
		.BYTE	$32,$05,$08	; OBJ_SET_SIZE
		.BYTE	$34,$01		; OBJ_SET_HP
		.BYTE	$33,$01		; VAR_1C_SET
		.BYTE	$1B		; PARAM_80_CLEAR
byte_68F68:
		.BYTE	$1E,$21
		.BYTE	$07		; SJSR
		.WORD	byte_68F75
		.BYTE	$1E,$22		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	byte_68F75
		.BYTE	$06		; SJMP
		.WORD	byte_68F68
byte_68F75:
		.BYTE	$18
		.BYTE	$05		; NJSR
		.WORD	_native_sub109
		.BYTE	$09,$03		; LOOPA
		.WORD	byte_68F75
		.BYTE	$08		; RET
_script110:
		.BYTE	$02,$F0
byte_68F80:
		.BYTE	$03
		.WORD	_native_sub138
		.BYTE	$0F		; SBCC
		.WORD	byte_68F80
		.BYTE	$02,$3C		; DELAY
		.BYTE	$04,$03		; RUN
		.WORD	_script112
		.BYTE	$06		; SJMP
		.WORD	_script110
_script112:
		.BYTE	$43
		.BYTE	$42		; DESTR_PC_SET
		.WORD	_script46
		.BYTE	$05		; NJSR
		.WORD	_native_sub12A
		.BYTE	$12		; SWITCH
		.WORD	_tmp_ptrE+1
		.WORD	byte_68F9F
		.WORD	byte_68FA5
		.WORD	byte_68FAB
byte_68F9F:
		.BYTE	$25,$18,$00
		.BYTE	$06		; SJMP
		.WORD	byte_68FB1
byte_68FA5:
		.BYTE	$25,$A8,$00
		.BYTE	$06		; SJMP
		.WORD	byte_68FB1
byte_68FAB:
		.BYTE	$25,$98,$00
		.BYTE	$05		; NJSR
		.WORD	_native_sub110
byte_68FB1:
		.BYTE	$26,$00,$00
		.BYTE	$01		; FLUSH
		.BYTE	$1D,$03		; SPR_LIB_SELECT
		.BYTE	$1E,$00		; SPR_IDX_SELECT
		.BYTE	$32,$06,$10	; OBJ_SET_SIZE
		.BYTE	$05		; NJSR
		.WORD	_native_sub139
		.BYTE	$1B		; PARAM_80_CLEAR
byte_68FC0:
		.BYTE	$34,$01
		.BYTE	$33,$01		; VAR_1C_SET
		.BYTE	$29,$00		; OBJ_SET_X_DELTA
		.BYTE	$2A,$01		; OBJ_SET_Y_DELTA
		.BYTE	$05		; NJSR
		.WORD	_native_sub13A
byte_68FCB:
		.BYTE	$01
		.BYTE	$05		; NJSR
		.WORD	_native_sub109
		.BYTE	$05		; NJSR
		.WORD	_native_sub10B
		.BYTE	$0F		; SBCC
		.WORD	byte_68FDE
		.BYTE	$05		; NJSR
		.WORD	_native_get_obj_hp
		.BYTE	$0B		; SBEQ
		.WORD	byte_68FCB
		.BYTE	$06		; SJMP
		.WORD	byte_6A669
byte_68FDE:
		.BYTE	$05
		.WORD	_native_sub13B
		.BYTE	$05		; NJSR
		.WORD	_native_sub110
		.BYTE	$29,$08		; OBJ_SET_X_DELTA
		.BYTE	$2A,$00		; OBJ_SET_Y_DELTA
		.BYTE	$05		; NJSR
		.WORD	_native_sub10F
byte_68FEB:
		.BYTE	$01
		.BYTE	$05		; NJSR
		.WORD	_native_get_obj_var0D
		.BYTE	$10		; SBPL
		.WORD	_script46
		.BYTE	$05		; NJSR
		.WORD	_obj_move_hor_animate
		.BYTE	$05		; NJSR
		.WORD	_native_sub13C
		.BYTE	$05		; NJSR
		.WORD	_native_sub118
		.BYTE	$0F		; SBCC
		.WORD	byte_68FEB
		.BYTE	$06		; SJMP
		.WORD	byte_68FC0
_obj_scr40:
		.BYTE	$13,$1E
		.WORD	_apu_load_idx_req
		.BYTE	$42		; DESTR_PC_SET
		.WORD	byte_B6AF1
		.BYTE	$05		; NJSR
		.WORD	_native_sub134
		.BYTE	$27,$0F		; OBJ_MOVE_X_POS
		.BYTE	$1D,$08		; SPR_LIB_SELECT
		.BYTE	$02,$80		; DELAY
		.BYTE	$1B		; PARAM_80_CLEAR
		.BYTE	$29,$F8		; OBJ_SET_X_DELTA
		.BYTE	$2A,$10		; OBJ_SET_Y_DELTA
byte_69016:
		.BYTE	$07
		.WORD	byte_690B0
		.BYTE	$09,$04		; LOOPA
		.WORD	byte_69016
		.BYTE	$32,$0E,$20	; OBJ_SET_SIZE
		.BYTE	$34,$06		; OBJ_SET_HP
		.BYTE	$33,$01		; VAR_1C_SET
byte_69024:
		.BYTE	$07
		.WORD	byte_69039
		.BYTE	$07		; SJSR
		.WORD	byte_6905E
		.BYTE	$07		; SJSR
		.WORD	byte_69039
		.BYTE	$07		; SJSR
		.WORD	byte_69076
		.BYTE	$07		; SJSR
		.WORD	byte_69039
		.BYTE	$07		; SJSR
		.WORD	byte_69076
		.BYTE	$06		; SJMP
		.WORD	byte_69024
byte_69039:
		.BYTE	$29,$00
		.BYTE	$2A,$00		; OBJ_SET_Y_DELTA
byte_6903D:
		.BYTE	$07
		.WORD	byte_690B0
		.BYTE	$09,$03		; LOOPA
		.WORD	byte_6903D
		.BYTE	$04,$07		; RUN
		.WORD	_script113
		.BYTE	$07		; SJSR
		.WORD	_script209
byte_6904B:
		.BYTE	$07
		.WORD	byte_690B0
		.BYTE	$09,$03		; LOOPA
		.WORD	byte_6904B
		.BYTE	$04,$07		; RUN
		.WORD	_script113
byte_69056:
		.BYTE	$07
		.WORD	byte_690B0
		.BYTE	$09,$03		; LOOPA
		.WORD	byte_69056
		.BYTE	$08		; RET
byte_6905E:
		.BYTE	$29,$E0
		.BYTE	$2A,$19		; OBJ_SET_Y_DELTA
		.BYTE	$05		; NJSR
		.WORD	_native_sub10F
byte_69065:
		.BYTE	$07
		.WORD	byte_690B0
		.BYTE	$05		; NJSR
		.WORD	_native_sub004
		.BYTE	$09,$06		; LOOPA
		.WORD	byte_69065
		.BYTE	$05		; NJSR
		.WORD	_native_sub110
		.BYTE	$05		; NJSR
		.WORD	_native_sub114
		.BYTE	$08		; RET
byte_69076:
		.BYTE	$29,$E0
		.BYTE	$2A,$20		; OBJ_SET_Y_DELTA
		.BYTE	$05		; NJSR
		.WORD	_native_sub10F
byte_6907D:
		.BYTE	$07
		.WORD	byte_690B0
		.BYTE	$05		; NJSR
		.WORD	_native_sub004
		.BYTE	$09,$03		; LOOPA
		.WORD	byte_6907D
		.BYTE	$05		; NJSR
		.WORD	_native_sub114
		.BYTE	$2A,$00		; OBJ_SET_Y_DELTA
		.BYTE	$17,$67		; APU_LOAD
byte_6908E:
		.BYTE	$1E,$0C
		.BYTE	$07		; SJSR
		.WORD	_script209
		.BYTE	$07		; SJSR
		.WORD	_script209
		.BYTE	$1E,$0D		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	_script209
		.BYTE	$07		; SJSR
		.WORD	_script209
		.BYTE	$09,$0C		; LOOPA
		.WORD	byte_6908E
		.BYTE	$05		; NJSR
		.WORD	_native_sub110
		.BYTE	$29,$00		; OBJ_SET_X_DELTA
		.BYTE	$2A,$E0		; OBJ_SET_Y_DELTA
		.BYTE	$07		; SJSR
		.WORD	byte_690B0
		.BYTE	$07		; SJSR
		.WORD	byte_690B0
		.BYTE	$08		; RET
byte_690B0:
		.BYTE	$17,$66
		.BYTE	$05		; NJSR
		.WORD	_native_sub002
		.BYTE	$1E,$09		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	byte_690CF
		.BYTE	$05		; NJSR
		.WORD	_native_sub003
		.BYTE	$1E,$0A		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	byte_690CF
		.BYTE	$05		; NJSR
		.WORD	_native_sub003
		.BYTE	$1E,$0B		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	byte_690CF
		.BYTE	$05		; NJSR
		.WORD	_native_sub002
		.BYTE	$1E,$0A		; SPR_IDX_SELECT
byte_690CF:
		.BYTE	$07
		.WORD	_script209
		.BYTE	$05		; NJSR
		.WORD	_native_sub005
		.BYTE	$0A,$04		; LOOPB
		.WORD	byte_690CF
		.BYTE	$08		; RET

; =============== S U B	R O U T	I N E =======================================
_native_sub002:
		CLC
		LDA		_obj_y_deltas,X
		ADC		#$10
		STA		_obj_y_deltas,X
		RTS

; =============== S U B	R O U T	I N E =======================================
_native_sub003:
		SEC
		LDA		_obj_y_deltas,X
		SBC		#$10
		STA		_obj_y_deltas,X
		RTS

; =============== S U B	R O U T	I N E =======================================
_native_sub004:
		SEC
		LDA		_obj_y_deltas,X
		SBC		#$0A
		STA		_obj_y_deltas,X
		RTS

; =============== S U B	R O U T	I N E =======================================
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
_script113:
		.BYTE	$43
		.BYTE	$42		; DESTR_PC_SET
		.WORD	byte_6915B
		.BYTE	$1D,$08		; SPR_LIB_SELECT
		.BYTE	$1E,$0E		; SPR_IDX_SELECT
		.BYTE	$34,$01		; OBJ_SET_HP
		.BYTE	$33,$01		; VAR_1C_SET
		.BYTE	$32,$06,$10	; OBJ_SET_SIZE
		.BYTE	$1B		; PARAM_80_CLEAR
		.BYTE	$03		; NJMP
		.WORD	_native_sub006
byte_69120:
		.BYTE	$05
		.WORD	_native_sub109
		.BYTE	$03		; NJMP
		.WORD	_obj_vert_animate
		.BYTE	$09,$20		; LOOPA
		.WORD	byte_69120
		.BYTE	$2F,$40		; TARGET_LOCK
		.BYTE	$05		; NJSR
		.WORD	_native_sub111
		.BYTE	$05		; NJSR
		.WORD	_native_sub13D
		.BYTE	$0F		; SBCC
		.WORD	_script1FE
		.BYTE	$07		; SJSR
		.WORD	_script1FF
		.BYTE	$29,$18		; OBJ_SET_X_DELTA
		.BYTE	$2A,$00		; OBJ_SET_Y_DELTA
		.BYTE	$05		; NJSR
		.WORD	_native_sub10F
byte_6913F:
		.BYTE	$07
		.WORD	_script_animate10
		.BYTE	$05		; NJSR
		.WORD	_native_sub007
		.BYTE	$0C		; SBCS
		.WORD	byte_6913F
		.BYTE	$05		; NJSR
		.WORD	_native_sub13B
byte_6914B:
		.BYTE	$01
		.BYTE	$05		; NJSR
		.WORD	_native_get_obj_var0D
		.BYTE	$10		; SBPL
		.WORD	byte_6915B
		.BYTE	$05		; NJSR
		.WORD	_native_sub008
		.BYTE	$0F		; SBCC
		.WORD	byte_6916B
		.BYTE	$06		; SJMP
		.WORD	byte_6914B
byte_6915B:
		.BYTE	$07
		.WORD	byte_6806C
		.BYTE	$05		; NJSR
		.WORD	_native_sub030
byte_69161:
		.BYTE	$18
		.BYTE	$05		; NJSR
		.WORD	_native_sub016
		.BYTE	$0B		; SBEQ
		.WORD	byte_69161
		.BYTE	$06		; SJMP
		.WORD	byte_68096
byte_6916B:
		.BYTE	$05
		.WORD	_native_sub13E
		.BYTE	$29,$10		; OBJ_SET_X_DELTA
		.BYTE	$2A,$E0		; OBJ_SET_Y_DELTA
		.BYTE	$05		; NJSR
		.WORD	_players_animB_sub3_B_A
		.BYTE	$06		; SJMP
		.WORD	byte_68096

; =============== S U B	R O U T	I N E =======================================
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

; =============== S U B	R O U T	I N E =======================================
_native_sub007:
		LDA		_obj_x_lo_poss,X
		BPL		loc_69194
		EOR		#$FF
loc_69194:
		CMP		#$10
		JMP		_scr_flags_flush_ex

; =============== S U B	R O U T	I N E =======================================
_native_sub008:
		LDA		#$03
		STA		_scr_idxAs,X
		TAY
		JSR		_obj_to_obj_collision_test
		JMP		_scr_flags_flush_ex
_obj_scr41:
		.BYTE	$13,$1E
		.WORD	_apu_load_idx_req
		.BYTE	$13,$10		; MOV
		.WORD	byte_9D
		.BYTE	$42		; DESTR_PC_SET
		.WORD	byte_B6AF1
		.BYTE	$05		; NJSR
		.WORD	_native_sub134
		.BYTE	$04,$01		; RUN
		.WORD	_script114
		.BYTE	$27,$20		; OBJ_MOVE_X_POS
		.BYTE	$1D,$08		; SPR_LIB_SELECT
		.BYTE	$32,$08,$20	; OBJ_SET_SIZE
		.BYTE	$34,$06		; OBJ_SET_HP
		.BYTE	$33,$01		; VAR_1C_SET
		.BYTE	$02,$80		; DELAY
		.BYTE	$1B		; PARAM_80_CLEAR
		.BYTE	$29,$E8		; OBJ_SET_X_DELTA
		.BYTE	$1E,$27		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	_script208
		.BYTE	$1E,$26		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	_script208
		.BYTE	$07		; SJSR
		.WORD	byte_691E3
		.BYTE	$05		; NJSR
		.WORD	_native_sub009
byte_691D7:
		.BYTE	$05
		.WORD	_native_sub12A
		.BYTE	$12		; SWITCH
		.WORD	_tmp_ptrE+1
		.WORD	byte_69223
		.WORD	byte_691EA
		.WORD	byte_69223
byte_691E3:
		.BYTE	$1E,$24
		.BYTE	$29,$00		; OBJ_SET_X_DELTA
		.BYTE	$06		; SJMP
		.WORD	_script206
byte_691EA:
		.BYTE	$05
		.WORD	_native_cmpC0_obj_y_lo_pos
		.BYTE	$0C		; SBCS
		.WORD	byte_69229
byte_691F0:
		.BYTE	$05
		.WORD	_native_cmp80_obj_x_lo_pos
		.BYTE	$0B		; SBEQ
		.WORD	byte_691FC
		.BYTE	$07		; SJSR
		.WORD	byte_691E3
		.BYTE	$05		; NJSR
		.WORD	_native_sub10E
byte_691FC:
		.BYTE	$29,$00
		.BYTE	$2A,$00		; OBJ_SET_Y_DELTA
		.BYTE	$1E,$28		; SPR_IDX_SELECT
		.BYTE	$17,$3C		; APU_LOAD
		.BYTE	$07		; SJSR
		.WORD	_script208
		.BYTE	$17,$3C		; APU_LOAD
		.BYTE	$07		; SJSR
		.WORD	_script208
byte_6920C:
		.BYTE	$1E,$29
		.BYTE	$17,$3D		; APU_LOAD
		.BYTE	$04,$07		; RUN
		.WORD	_script115
		.BYTE	$07		; SJSR
		.WORD	_script203
		.BYTE	$07		; SJSR
		.WORD	_script206
		.BYTE	$1E,$24		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	_script208
		.BYTE	$09,$02		; LOOPA
		.WORD	byte_6920C
byte_69223:
		.BYTE	$05
		.WORD	_native_cmp80_obj_y_lo_pos
		.BYTE	$0F		; SBCC
		.WORD	byte_691F0
byte_69229:
		.BYTE	$29,$18
		.BYTE	$05		; NJSR
		.WORD	_native_sub10F
byte_6922E:
		.BYTE	$01
		.BYTE	$1E,$25		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	byte_6927B
		.BYTE	$0A,$08		; LOOPB
		.WORD	byte_6922E
byte_69238:
		.BYTE	$01
		.BYTE	$1E,$26		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	byte_6927B
		.BYTE	$0A,$08		; LOOPB
		.WORD	byte_69238
byte_69242:
		.BYTE	$01
		.BYTE	$1E,$27		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	byte_6927B
		.BYTE	$0A,$08		; LOOPB
		.WORD	byte_69242
byte_6924C:
		.BYTE	$01
		.BYTE	$1E,$26		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	byte_6927B
		.BYTE	$0A,$08		; LOOPB
		.WORD	byte_6924C
		.BYTE	$09,$02		; LOOPA
		.WORD	byte_6922E
		.BYTE	$29,$00		; OBJ_SET_X_DELTA
byte_6925C:
		.BYTE	$05
		.WORD	_native_get_obj_y_delta
		.BYTE	$0E		; SBNE
		.WORD	byte_69269
		.BYTE	$01		; FLUSH
		.BYTE	$07		; SJSR
		.WORD	byte_6927B
		.BYTE	$06		; SJMP
		.WORD	byte_6925C
byte_69269:
		.BYTE	$05
		.WORD	_native_cmp80_obj_x_lo_pos
		.BYTE	$0E		; SBNE
		.WORD	byte_691D7
		.BYTE	$07		; SJSR
		.WORD	byte_691E3
		.BYTE	$05		; NJSR
		.WORD	_native_sub110
		.BYTE	$07		; SJSR
		.WORD	byte_691E3
		.BYTE	$06		; SJMP
		.WORD	byte_691D7
byte_6927B:
		.BYTE	$07
		.WORD	_script20A
		.BYTE	$05		; NJSR
		.WORD	_obj_move_hor_animate
		.BYTE	$05		; NJSR
		.WORD	_native_get_obj_y_delta
		.BYTE	$0B		; SBEQ
		.WORD	byte_69290
		.BYTE	$05		; NJSR
		.WORD	_native_sub118
		.BYTE	$0C		; SBCS
		.WORD	byte_6928E
		.BYTE	$08		; RET
byte_6928E:
		.BYTE	$2A,$B0
byte_69290:
		.BYTE	$1E,$26
		.BYTE	$05		; NJSR
		.WORD	_native_sub109
		.BYTE	$0D		; SBMI
		.WORD	byte_6929C
		.BYTE	$05		; NJSR
		.WORD	_obj_vert_animate
		.BYTE	$08		; RET
byte_6929C:
		.BYTE	$05
		.WORD	_native_sub10B
		.BYTE	$0C		; SBCS
		.WORD	byte_692A4
		.BYTE	$2A,$00		; OBJ_SET_Y_DELTA
byte_692A4:
		.BYTE	$08

; =============== S U B	R O U T	I N E =======================================
_native_sub009:
		LDA		_room_flags
		ORA		#$02
		STA		_room_flags
		RTS
_script114:
		.BYTE	$35,$08
byte_692AE:
		.BYTE	$03
		.WORD	_native_sub00A
		.BYTE	$0F		; SBCC
		.WORD	byte_692AE
		.BYTE	$04,$09		; RUN
		.WORD	_script116
		.BYTE	$06		; SJMP
		.WORD	byte_692AE

; =============== S U B	R O U T	I N E =======================================
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
		JMP		_scr_flags_flush_ex
_script116:
		.BYTE	$43
		.BYTE	$42		; DESTR_PC_SET
		.WORD	_script46
		.BYTE	$26,$00,$00	; OBJ_SET_Y_POS
		.BYTE	$1D,$03		; SPR_LIB_SELECT
		.BYTE	$1E,$00		; SPR_IDX_SELECT
		.BYTE	$32,$06,$10	; OBJ_SET_SIZE
		.BYTE	$34,$01		; OBJ_SET_HP
		.BYTE	$1B		; PARAM_80_CLEAR
byte_692F1:
		.BYTE	$03
		.WORD	_native_get_obj_var0D
		.BYTE	$10		; SBPL
		.WORD	_script46
		.BYTE	$06		; SJMP
		.WORD	byte_692F1
_script115:
		.BYTE	$28,$E9
		.BYTE	$29,$30		; OBJ_SET_X_DELTA
		.BYTE	$05		; NJSR
		.WORD	_native_sub141
		.BYTE	$1D,$08		; SPR_LIB_SELECT
		.BYTE	$32,$04,$06	; OBJ_SET_SIZE
		.BYTE	$34,$01		; OBJ_SET_HP
		.BYTE	$33,$01		; VAR_1C_SET
		.BYTE	$1B		; PARAM_80_CLEAR
byte_6930B:
		.BYTE	$1E,$2A
		.BYTE	$07		; SJSR
		.WORD	_script_animate10
		.BYTE	$1E,$2B		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	_script_animate10
		.BYTE	$06		; SJMP
		.WORD	byte_6930B
_obj_scr42:
		.BYTE	$13,$0E
		.WORD	_apu_load_idx_req
		.BYTE	$42		; DESTR_PC_SET
		.WORD	byte_694CA
		.BYTE	$05		; NJSR
		.WORD	_native_sub134
		.BYTE	$34,$07		; OBJ_SET_HP
		.BYTE	$33,$01		; VAR_1C_SET
		.BYTE	$13,$00		; MOV
		.WORD	byte_E0
		.BYTE	$07		; SJSR
		.WORD	byte_69531
		.BYTE	$06		; SJMP
		.WORD	byte_69350
byte_69330:
		.BYTE	$1E,$0F
		.BYTE	$32,$00,$00	; OBJ_SET_SIZE
		.BYTE	$29,$00		; OBJ_SET_X_DELTA
		.BYTE	$2A,$00		; OBJ_SET_Y_DELTA
byte_69339:
		.BYTE	$07
		.WORD	byte_69492
		.BYTE	$12		; SWITCH
		.WORD	byte_E0
		.WORD	byte_69343
		.WORD	byte_69339
byte_69343:
		.BYTE	$1C
		.BYTE	$39,$04,$87	; PAL_FADE_OUT
		.BYTE	$02,$1E		; DELAY
		.BYTE	$1C		; PARAM_80_SET
		.BYTE	$38,$04,$8F	; PAL_FADE_IN
		.BYTE	$07		; SJSR
		.WORD	byte_69531
byte_69350:
		.BYTE	$39,$04,$8F
		.BYTE	$02,$1E		; DELAY
		.BYTE	$25,$C8,$00	; OBJ_SET_X_POS
		.BYTE	$26,$90,$00	; OBJ_SET_Y_POS
		.BYTE	$1D,$08		; SPR_LIB_SELECT
		.BYTE	$1E,$0F		; SPR_IDX_SELECT
		.BYTE	$05		; NJSR
		.WORD	_native_sub00C
		.BYTE	$14,$00,$1B	; CHR_BANK
		.BYTE	$38,$04,$87	; PAL_FADE_IN
		.BYTE	$02,$10		; DELAY
		.BYTE	$1B		; PARAM_80_CLEAR
		.BYTE	$32,$14,$30	; OBJ_SET_SIZE
		.BYTE	$2A,$10		; OBJ_SET_Y_DELTA
byte_69370:
		.BYTE	$07
		.WORD	byte_69492
		.BYTE	$09,$30		; LOOPA
		.WORD	byte_69370
		.BYTE	$05		; NJSR
		.WORD	_native_sub129
		.BYTE	$0A,$02		; LOOPB
		.WORD	byte_69370
		.BYTE	$2A,$00		; OBJ_SET_Y_DELTA
byte_69380:
		.BYTE	$07
		.WORD	byte_69492
		.BYTE	$09,$1E		; LOOPA
		.WORD	byte_69380
		.BYTE	$1E,$10		; SPR_IDX_SELECT
		.BYTE	$17,$6C		; APU_LOAD
		.BYTE	$03		; NJMP
		.WORD	_native_sub142
		.BYTE	$05		; NJSR
		.WORD	_native_sub12A
		.BYTE	$12		; SWITCH
		.WORD	_tmp_ptrE+1
		.WORD	byte_69412
		.WORD	byte_693D6
		.WORD	byte_6939A
byte_6939A:
		.BYTE	$29,$F9
		.BYTE	$05		; NJSR
		.WORD	_native_sub113
		.BYTE	$0D		; SBMI
		.WORD	byte_693AF
byte_693A2:
		.BYTE	$07
		.WORD	byte_693BC
		.BYTE	$07		; SJSR
		.WORD	byte_693C9
		.BYTE	$09,$02		; LOOPA
		.WORD	byte_693A2
		.BYTE	$06		; SJMP
		.WORD	byte_69330
byte_693AF:
		.BYTE	$07
		.WORD	byte_693C9
		.BYTE	$07		; SJSR
		.WORD	byte_693BC
		.BYTE	$09,$02		; LOOPA
		.WORD	byte_693AF
		.BYTE	$06		; SJMP
		.WORD	byte_69330
byte_693BC:
		.BYTE	$2A,$D8
byte_693BE:
		.BYTE	$2C
		.BYTE	$07		; SJSR
		.WORD	byte_69492
		.BYTE	$0A,$4E		; LOOPB
		.WORD	byte_693BE
		.BYTE	$06		; SJMP
		.WORD	byte_6940D
byte_693C9:
		.BYTE	$2A,$28
byte_693CB:
		.BYTE	$2E
		.BYTE	$07		; SJSR
		.WORD	byte_69492
		.BYTE	$0A,$4E		; LOOPB
		.WORD	byte_693CB
		.BYTE	$06		; SJMP
		.WORD	byte_6940D
byte_693D6:
		.BYTE	$29,$E8
		.BYTE	$05		; NJSR
		.WORD	_native_sub113
		.BYTE	$0D		; SBMI
		.WORD	byte_693E7
		.BYTE	$07		; SJSR
		.WORD	byte_693F0
		.BYTE	$07		; SJSR
		.WORD	byte_69400
		.BYTE	$06		; SJMP
		.WORD	byte_69330
byte_693E7:
		.BYTE	$07
		.WORD	byte_69400
		.BYTE	$07		; SJSR
		.WORD	byte_693F0
		.BYTE	$06		; SJMP
		.WORD	byte_69330
byte_693F0:
		.BYTE	$2A,$E8
		.BYTE	$07		; SJSR
		.WORD	byte_693F5
byte_693F5:
		.BYTE	$2C
		.BYTE	$07		; SJSR
		.WORD	byte_69492
		.BYTE	$0A,$17		; LOOPB
		.WORD	byte_693F5
		.BYTE	$06		; SJMP
		.WORD	byte_6940D
byte_69400:
		.BYTE	$2A,$18
		.BYTE	$07		; SJSR
		.WORD	byte_69405
byte_69405:
		.BYTE	$2E
		.BYTE	$07		; SJSR
		.WORD	byte_69492
		.BYTE	$0A,$17		; LOOPB
		.WORD	byte_69405
byte_6940D:
		.BYTE	$04,$07
		.WORD	_script118
		.BYTE	$08		; RET
byte_69412:
		.BYTE	$04,$07
		.WORD	_script119
		.BYTE	$29,$00		; OBJ_SET_X_DELTA
		.BYTE	$2A,$00		; OBJ_SET_Y_DELTA
byte_6941A:
		.BYTE	$07
		.WORD	byte_69492
		.BYTE	$09,$78		; LOOPA
		.WORD	byte_6941A
		.BYTE	$29,$DC		; OBJ_SET_X_DELTA
		.BYTE	$2A,$0A		; OBJ_SET_Y_DELTA
byte_69425:
		.BYTE	$07
		.WORD	byte_69492
		.BYTE	$09,$21		; LOOPA
		.WORD	byte_69425
		.BYTE	$0A,$02		; LOOPB
		.WORD	byte_69412
		.BYTE	$06		; SJMP
		.WORD	byte_69330
_script118:
		.BYTE	$43
		.BYTE	$05		; NJSR
		.WORD	_native_sub143
		.BYTE	$12		; SWITCH
		.WORD	_tmp_ptrE+1
		.WORD	byte_69442
		.WORD	byte_69442
		.WORD	byte_69443
		.WORD	byte_69443
byte_69442:
		.BYTE	$00
byte_69443:
		.BYTE	$17,$2B
		.BYTE	$27,$D4		; OBJ_MOVE_X_POS
		.BYTE	$28,$E5		; OBJ_MOVE_Y_POS
		.BYTE	$42		; DESTR_PC_SET
		.WORD	byte_69B00
		.BYTE	$1D,$08		; SPR_LIB_SELECT
		.BYTE	$1E,$11		; SPR_IDX_SELECT
		.BYTE	$32,$06,$0D	; OBJ_SET_SIZE
		.BYTE	$34,$01		; OBJ_SET_HP
		.BYTE	$33,$01		; VAR_1C_SET
		.BYTE	$1B		; PARAM_80_CLEAR
		.BYTE	$35,$08		; OBJ_SET_FLIP
		.BYTE	$05		; NJSR
		.WORD	_native_sub13D
		.BYTE	$0F		; SBCC
		.WORD	byte_68096
		.BYTE	$07		; SJSR
		.WORD	byte_68036
		.BYTE	$2A,$EC		; OBJ_SET_Y_DELTA
		.BYTE	$1E,$12		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	byte_68036
		.BYTE	$1E,$11		; SPR_IDX_SELECT
		.BYTE	$06		; SJMP
		.WORD	byte_69AFA
_script119:
		.BYTE	$27,$0E
		.BYTE	$28,$CA		; OBJ_MOVE_Y_POS
		.BYTE	$1D,$08		; SPR_LIB_SELECT
		.BYTE	$1E,$13		; SPR_IDX_SELECT
		.BYTE	$03		; NJMP
		.WORD	_native_sub111
		.BYTE	$2F,$30		; TARGET_LOCK
		.BYTE	$32,$08,$10	; OBJ_SET_SIZE
		.BYTE	$34,$01		; OBJ_SET_HP
		.BYTE	$33,$01		; VAR_1C_SET
		.BYTE	$1B		; PARAM_80_CLEAR
		.BYTE	$35,$08		; OBJ_SET_FLIP
byte_69486:
		.BYTE	$01
		.BYTE	$31,$FF		; TARGET_DIR_SET
		.BYTE	$1A		; TARGET_FOLLOW
		.BYTE	$09,$04		; LOOPA
		.WORD	byte_69486
		.BYTE	$23		; FLIP_40_TOGGLE
		.BYTE	$06		; SJMP
		.WORD	byte_69486
byte_69492:
		.BYTE	$05
		.WORD	_native_sub144
		.BYTE	$0E		; SBNE
		.WORD	byte_6949E
		.BYTE	$17,$2F		; APU_LOAD
		.BYTE	$04,$01		; RUN
		.WORD	_script11A
byte_6949E:
		.BYTE	$05
		.WORD	_native_sub145
		.BYTE	$01		; FLUSH
		.BYTE	$05		; NJSR
		.WORD	_native_sub146
		.BYTE	$05		; NJSR
		.WORD	_native_sub147
		.BYTE	$05		; NJSR
		.WORD	_native_sub00D
		.BYTE	$08		; RET
_script11A:
		.BYTE	$13,$01
		.WORD	byte_E0
byte_694B0:
		.BYTE	$02,$04
		.BYTE	$05		; NJSR
		.WORD	_load_pal_patch00
		.BYTE	$02,$04		; DELAY
		.BYTE	$05		; NJSR
		.WORD	_ppu_pal_apply
		.BYTE	$0A,$04		; LOOPB
		.WORD	byte_694B0
		.BYTE	$13,$00		; MOV
		.WORD	byte_E0
		.BYTE	$00		; STOP

; =============== S U B	R O U T	I N E =======================================
_load_pal_patch00:
		LDA		#<[_pal_patch00]
		LDY		#>[_pal_patch00]
		JMP		_far_prg3_pal_patch_load
byte_694CA:
		.BYTE	$05
		.WORD	_scr_param_4_set
		.BYTE	$1C		; PARAM_80_SET
		.BYTE	$17,$70		; APU_LOAD
		.BYTE	$39,$04,$87	; PAL_FADE_OUT
		.BYTE	$02,$80		; DELAY
		.BYTE	$06		; SJMP
		.WORD	byte_B6B07

; =============== S U B	R O U T	I N E =======================================
_native_sub00B:
		LDA		#$40
		LDY		#$00

; =============== S U B	R O U T	I N E =======================================
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

; =============== S U B	R O U T	I N E =======================================
_native_sub00C:
		LDA		_hor_menu_pos
		STA		_ppu_scroll_shadow_hi
		LDA		_tmp48
		STA		_ppu_scroll_nt_vert
		RTS

; =============== S U B	R O U T	I N E =======================================
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
		.BYTE	$05
		.WORD	_native_sub00B
		.BYTE	$14,$00,$13	; CHR_BANK
		.BYTE	$04,$01		; RUN
		.WORD	_script11B
		.BYTE	$04,$01		; RUN
		.WORD	_script11C
		.BYTE	$02,$80		; DELAY
		.BYTE	$08		; RET
_script11B:
		.BYTE	$25,$48,$00
		.BYTE	$06		; SJMP
		.WORD	byte_6954B
_script11C:
		.BYTE	$25,$B8,$00
byte_6954B:
		.BYTE	$26,$6D,$00
		.BYTE	$32,$05,$0A	; OBJ_SET_SIZE
byte_69551:
		.BYTE	$1D,$08
		.BYTE	$22		; FLIP_80_SET
		.BYTE	$1B		; PARAM_80_CLEAR
		.BYTE	$1E,$3F		; SPR_IDX_SELECT
		.BYTE	$01		; FLUSH
		.BYTE	$01		; FLUSH
		.BYTE	$1E,$54		; SPR_IDX_SELECT
		.BYTE	$01		; FLUSH
		.BYTE	$01		; FLUSH
		.BYTE	$09,$20		; LOOPA
		.WORD	byte_69551
		.BYTE	$00		; STOP
_obj_scr43:
		.BYTE	$13,$0E
		.WORD	_apu_load_idx_req
		.BYTE	$42		; DESTR_PC_SET
		.WORD	byte_B6AF1
		.BYTE	$05		; NJSR
		.WORD	_native_sub134
		.BYTE	$27,$50		; OBJ_MOVE_X_POS
		.BYTE	$1D,$08		; SPR_LIB_SELECT
		.BYTE	$34,$08		; OBJ_SET_HP
		.BYTE	$33,$01		; VAR_1C_SET
		.BYTE	$32,$0C,$2C	; OBJ_SET_SIZE
		.BYTE	$02,$30		; DELAY
		.BYTE	$1B		; PARAM_80_CLEAR
		.BYTE	$29,$F0		; OBJ_SET_X_DELTA
byte_6957C:
		.BYTE	$1E,$35
		.BYTE	$07		; SJSR
		.WORD	_script207
		.BYTE	$1E,$36		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	_script207
		.BYTE	$1E,$37		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	_script207
		.BYTE	$1E,$36		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	_script207
		.BYTE	$09,$02		; LOOPA
		.WORD	byte_6957C
byte_69594:
		.BYTE	$07
		.WORD	byte_6963C
		.BYTE	$05		; NJSR
		.WORD	_native_sub148
		.BYTE	$12		; SWITCH
		.WORD	_tmp_ptrE+1
		.WORD	byte_695C1
		.WORD	byte_695A5
		.WORD	byte_6961F
		.WORD	byte_6961F
byte_695A5:
		.BYTE	$05
		.WORD	_native_cmp40_obj_y_lo_pos
		.BYTE	$0E		; SBNE
		.WORD	byte_695B9
		.BYTE	$05		; NJSR
		.WORD	_native_cmpC0_obj_y_lo_pos
		.BYTE	$0E		; SBNE
		.WORD	byte_695B7
		.BYTE	$05		; NJSR
		.WORD	_native_sub113
		.BYTE	$0D		; SBMI
		.WORD	byte_695B9
byte_695B7:
		.BYTE	$2A,$AE
byte_695B9:
		.BYTE	$1E,$36
		.BYTE	$07		; SJSR
		.WORD	_script20B
		.BYTE	$06		; SJMP
		.WORD	byte_69594
byte_695C1:
		.BYTE	$29,$18
		.BYTE	$05		; NJSR
		.WORD	_native_sub10F
byte_695C6:
		.BYTE	$1E,$35
		.BYTE	$07		; SJSR
		.WORD	byte_695DD
		.BYTE	$1E,$36		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	byte_695DD
		.BYTE	$1E,$37		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	byte_695DD
		.BYTE	$1E,$36		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	byte_695DD
		.BYTE	$06		; SJMP
		.WORD	byte_695C6
byte_695DD:
		.BYTE	$01
		.BYTE	$07		; SJSR
		.WORD	_script20A
		.BYTE	$05		; NJSR
		.WORD	_obj_move_hor_animate
		.BYTE	$05		; NJSR
		.WORD	_native_sub135
		.BYTE	$0F		; SBCC
		.WORD	byte_695F5
		.BYTE	$05		; NJSR
		.WORD	_native_sub118
		.BYTE	$0C		; SBCS
		.WORD	byte_695FC
		.BYTE	$09,$0A		; LOOPA
		.WORD	byte_695DD
		.BYTE	$08		; RET
byte_695F5:
		.BYTE	$05
		.WORD	_native_sub110
		.BYTE	$15		; LOOPA_RESET
		.BYTE	$41		; BREAK
		.WORD	byte_69594
byte_695FC:
		.BYTE	$1E,$36
		.BYTE	$2A,$D8		; OBJ_SET_Y_DELTA
byte_69600:
		.BYTE	$01
		.BYTE	$07		; SJSR
		.WORD	_script20A
		.BYTE	$05		; NJSR
		.WORD	_obj_move_hor_animate
		.BYTE	$05		; NJSR
		.WORD	_native_sub109
		.BYTE	$0D		; SBMI
		.WORD	byte_69613
		.BYTE	$05		; NJSR
		.WORD	_obj_vert_animate
		.BYTE	$06		; SJMP
		.WORD	byte_69600
byte_69613:
		.BYTE	$05
		.WORD	_native_sub10B
		.BYTE	$0C		; SBCS
		.WORD	byte_69600
		.BYTE	$2A,$00		; OBJ_SET_Y_DELTA
		.BYTE	$15		; LOOPA_RESET
		.BYTE	$41		; BREAK
		.WORD	byte_695C6
byte_6961F:
		.BYTE	$1E,$38
		.BYTE	$07		; SJSR
		.WORD	_script207
		.BYTE	$1E,$39		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	_script205
		.BYTE	$07		; SJSR
		.WORD	_script209
		.BYTE	$04,$07		; RUN
		.WORD	_script11D
		.BYTE	$1E,$3A		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	_script208
		.BYTE	$09,$02		; LOOPA
		.WORD	byte_6961F
		.BYTE	$06		; SJMP
		.WORD	byte_69594
byte_6963C:
		.BYTE	$1E,$34
		.BYTE	$29,$00		; OBJ_SET_X_DELTA
byte_69640:
		.BYTE	$07
		.WORD	_script209
		.BYTE	$09,$30		; LOOPA
		.WORD	byte_69640
		.BYTE	$08		; RET
_script11D:
		.BYTE	$43
		.BYTE	$17,$6E		; APU_LOAD
		.BYTE	$32,$06,$06	; OBJ_SET_SIZE
		.BYTE	$34,$01		; OBJ_SET_HP
		.BYTE	$33,$01		; VAR_1C_SET
		.BYTE	$1D,$08		; SPR_LIB_SELECT
		.BYTE	$1B		; PARAM_80_CLEAR
		.BYTE	$05		; NJSR
		.WORD	_native_sub141
		.BYTE	$28,$EF		; OBJ_MOVE_Y_POS
		.BYTE	$2F,$40		; TARGET_LOCK
		.BYTE	$05		; NJSR
		.WORD	_native_sub00E
		.BYTE	$05		; NJSR
		.WORD	_native_sub13D
		.BYTE	$0F		; SBCC
		.WORD	_script1FE
		.BYTE	$07		; SJSR
		.WORD	_script1FF
		.BYTE	$1E,$3B		; SPR_IDX_SELECT
		.BYTE	$29,$18		; OBJ_SET_X_DELTA
		.BYTE	$2A,$00		; OBJ_SET_Y_DELTA
		.BYTE	$05		; NJSR
		.WORD	_native_sub10F
byte_69671:
		.BYTE	$07
		.WORD	_script_animate10
		.BYTE	$05		; NJSR
		.WORD	_native_sub007
		.BYTE	$0C		; SBCS
		.WORD	byte_69671
		.BYTE	$42		; DESTR_PC_SET
		.WORD	byte_69B00
		.BYTE	$29,$00		; OBJ_SET_X_DELTA
		.BYTE	$06		; SJMP
		.WORD	byte_69AFA

; =============== S U B	R O U T	I N E =======================================
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
_obj_scr44:
		.BYTE	$13,$0E
		.WORD	_apu_load_idx_req
		.BYTE	$42		; DESTR_PC_SET
		.WORD	byte_B6AF1
		.BYTE	$05		; NJSR
		.WORD	_native_sub134
		.BYTE	$27,$60		; OBJ_MOVE_X_POS
		.BYTE	$1D,$08		; SPR_LIB_SELECT
		.BYTE	$34,$08		; OBJ_SET_HP
		.BYTE	$33,$01		; VAR_1C_SET
		.BYTE	$32,$08,$30	; OBJ_SET_SIZE
		.BYTE	$02,$40		; DELAY
		.BYTE	$1B		; PARAM_80_CLEAR
		.BYTE	$29,$F0		; OBJ_SET_X_DELTA
byte_69785:
		.BYTE	$17,$6A
		.BYTE	$1E,$2D		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	_script206
		.BYTE	$1E,$2E		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	_script206
		.BYTE	$17,$6A		; APU_LOAD
		.BYTE	$1E,$2F		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	_script206
		.BYTE	$1E,$30		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	_script206
		.BYTE	$17,$6A		; APU_LOAD
		.BYTE	$1E,$31		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	_script206
		.BYTE	$1E,$2C		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	_script206
		.BYTE	$09,$02		; LOOPA
		.WORD	byte_69785
byte_697AD:
		.BYTE	$07
		.WORD	byte_69859
		.BYTE	$05		; NJSR
		.WORD	_native_sub113
		.BYTE	$0D		; SBMI
		.WORD	byte_697BF
		.BYTE	$05		; NJSR
		.WORD	_native_cmpC0_obj_y_lo_pos
		.BYTE	$0B		; SBEQ
		.WORD	byte_697BF
		.BYTE	$07		; SJSR
		.WORD	byte_697D8
byte_697BF:
		.BYTE	$07
		.WORD	byte_69845
		.BYTE	$07		; SJSR
		.WORD	byte_697ED
		.BYTE	$05		; NJSR
		.WORD	_native_sub113
		.BYTE	$0D		; SBMI
		.WORD	byte_697CF
		.BYTE	$2A,$AC		; OBJ_SET_Y_DELTA
		.BYTE	$17,$54		; APU_LOAD
byte_697CF:
		.BYTE	$07
		.WORD	byte_697ED
		.BYTE	$05		; NJSR
		.WORD	_native_sub110
		.BYTE	$06		; SJMP
		.WORD	byte_697AD
byte_697D8:
		.BYTE	$29,$40
		.BYTE	$07		; SJSR
		.WORD	byte_697EF
		.BYTE	$07		; SJSR
		.WORD	byte_697EF
		.BYTE	$05		; NJSR
		.WORD	_native_sub110
		.BYTE	$07		; SJSR
		.WORD	byte_697EF
		.BYTE	$07		; SJSR
		.WORD	byte_697EF
		.BYTE	$05		; NJSR
		.WORD	_native_sub110
		.BYTE	$08		; RET
byte_697ED:
		.BYTE	$29,$20
byte_697EF:
		.BYTE	$05
		.WORD	_native_sub10F
		.BYTE	$1E,$2D		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	byte_69813
		.BYTE	$1E,$2E		; SPR_IDX_SELECT
		.BYTE	$17,$6A		; APU_LOAD
		.BYTE	$07		; SJSR
		.WORD	byte_69813
		.BYTE	$1E,$2F		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	byte_69813
		.BYTE	$1E,$30		; SPR_IDX_SELECT
		.BYTE	$17,$6A		; APU_LOAD
		.BYTE	$07		; SJSR
		.WORD	byte_69813
		.BYTE	$1E,$31		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	byte_69813
		.BYTE	$1E,$2C		; SPR_IDX_SELECT
		.BYTE	$17,$6A		; APU_LOAD
byte_69813:
		.BYTE	$01
		.BYTE	$07		; SJSR
		.WORD	_script20A
		.BYTE	$05		; NJSR
		.WORD	_obj_move_hor_animate
		.BYTE	$05		; NJSR
		.WORD	_native_sub149
		.BYTE	$0B		; SBEQ
		.WORD	byte_69840
		.BYTE	$05		; NJSR
		.WORD	_native_get_obj_y_delta
		.BYTE	$0B		; SBEQ
		.WORD	byte_6982C
		.BYTE	$05		; NJSR
		.WORD	_native_sub118
		.BYTE	$0F		; SBCC
		.WORD	byte_69840
byte_6982C:
		.BYTE	$05
		.WORD	_native_sub109
		.BYTE	$0D		; SBMI
		.WORD	byte_69838
		.BYTE	$05		; NJSR
		.WORD	_obj_vert_animate
		.BYTE	$06		; SJMP
		.WORD	byte_69840
byte_69838:
		.BYTE	$05
		.WORD	_native_sub10B
		.BYTE	$0C		; SBCS
		.WORD	byte_69840
		.BYTE	$2A,$00		; OBJ_SET_Y_DELTA
byte_69840:
		.BYTE	$09,$08
		.WORD	byte_69813
		.BYTE	$08		; RET
byte_69845:
		.BYTE	$29,$00
		.BYTE	$05		; NJSR
		.WORD	_native_sub14A
byte_6984A:
		.BYTE	$17,$54
		.BYTE	$2A,$D0		; OBJ_SET_Y_DELTA
		.BYTE	$07		; SJSR
		.WORD	_script20B
		.BYTE	$04,$07		; RUN
		.WORD	_script11E
		.BYTE	$09,$03		; LOOPA
		.WORD	byte_6984A
byte_69859:
		.BYTE	$29,$00
byte_6985B:
		.BYTE	$07
		.WORD	_script208
		.BYTE	$09,$03		; LOOPA
		.WORD	byte_6985B
		.BYTE	$08		; RET
_script11E:
		.BYTE	$43
		.BYTE	$05		; NJSR
		.WORD	_native_sub143
		.BYTE	$12		; SWITCH
		.WORD	_tmp_ptrE+1
		.WORD	byte_69870
		.WORD	byte_69875
		.WORD	byte_6987A
byte_69870:
		.BYTE	$29,$18
		.BYTE	$06		; SJMP
		.WORD	byte_6987C
byte_69875:
		.BYTE	$29,$24
		.BYTE	$06		; SJMP
		.WORD	byte_6987C
byte_6987A:
		.BYTE	$29,$30
byte_6987C:
		.BYTE	$1D,$08
		.BYTE	$32,$06,$10	; OBJ_SET_SIZE
		.BYTE	$34,$01		; OBJ_SET_HP
		.BYTE	$33,$01		; VAR_1C_SET
		.BYTE	$1B		; PARAM_80_CLEAR
		.BYTE	$2A,$D0		; OBJ_SET_Y_DELTA
		.BYTE	$05		; NJSR
		.WORD	_native_sub10F
		.BYTE	$05		; NJSR
		.WORD	_native_sub13D
		.BYTE	$0C		; SBCS
		.WORD	byte_698A7
byte_69891:
		.BYTE	$1E,$32
		.BYTE	$07		; SJSR
		.WORD	byte_6989E
		.BYTE	$1E,$33		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	byte_6989E
		.BYTE	$06		; SJMP
		.WORD	byte_69891
byte_6989E:
		.BYTE	$18
		.BYTE	$05		; NJSR
		.WORD	_native_sub109
		.BYTE	$09,$06		; LOOPA
		.WORD	byte_6989E
		.BYTE	$08		; RET
byte_698A7:
		.BYTE	$07
		.WORD	byte_698B5
		.BYTE	$2A,$E8		; OBJ_SET_Y_DELTA
		.BYTE	$07		; SJSR
		.WORD	byte_698B5
		.BYTE	$42		; DESTR_PC_SET
		.WORD	byte_69B00
		.BYTE	$06		; SJMP
		.WORD	byte_69AFA
byte_698B5:
		.BYTE	$1E,$32
		.BYTE	$07		; SJSR
		.WORD	byte_698C9
		.BYTE	$0F		; SBCC
		.WORD	byte_698C8
		.BYTE	$1E,$33		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	byte_698C9
		.BYTE	$0F		; SBCC
		.WORD	byte_698C8
		.BYTE	$06		; SJMP
		.WORD	byte_698B5
byte_698C8:
		.BYTE	$08
byte_698C9:
		.BYTE	$07
		.WORD	byte_6803D
		.BYTE	$0F		; SBCC
		.WORD	byte_698D3
		.BYTE	$09,$06		; LOOPA
		.WORD	byte_698C9
byte_698D3:
		.BYTE	$15
		.BYTE	$08		; RET
_obj_scr45:
		.BYTE	$13,$1E
		.WORD	_apu_load_idx_req
		.BYTE	$42		; DESTR_PC_SET
		.WORD	byte_69981
		.BYTE	$13,$40		; MOV
		.WORD	_ppu_scroll_shadow_lo
		.BYTE	$13,$05		; MOV
		.WORD	_ppu_scroll_nt_hor
		.BYTE	$34,$08		; OBJ_SET_HP
		.BYTE	$33,$01		; VAR_1C_SET
		.BYTE	$25,$88,$01	; OBJ_SET_X_POS
		.BYTE	$26,$78,$00	; OBJ_SET_Y_POS
		.BYTE	$04,$07		; RUN
		.WORD	_script11F
		.BYTE	$04,$06		; RUN
		.WORD	_script120
		.BYTE	$05		; NJSR
		.WORD	_native_sub14B
		.BYTE	$05		; NJSR
		.WORD	_native_sub134
		.BYTE	$1D,$08		; SPR_LIB_SELECT
		.BYTE	$1E,$00		; SPR_IDX_SELECT
		.BYTE	$02,$80		; DELAY
		.BYTE	$1B		; PARAM_80_CLEAR
		.BYTE	$32,$08,$20	; OBJ_SET_SIZE
byte_69906:
		.BYTE	$07
		.WORD	byte_69961
		.BYTE	$0A,$06		; LOOPB
		.WORD	byte_69906
byte_6990D:
		.BYTE	$05
		.WORD	_native_sub010
		.BYTE	$0E		; SBNE
		.WORD	byte_69924
		.BYTE	$29,$E0		; OBJ_SET_X_DELTA
		.BYTE	$1E,$00		; SPR_IDX_SELECT
		.BYTE	$13,$0B		; MOV
		.WORD	_pal_anim_mode_idx
		.BYTE	$07		; SJSR
		.WORD	byte_69969
		.BYTE	$07		; SJSR
		.WORD	byte_69969
		.BYTE	$06		; SJMP
		.WORD	byte_6994D
byte_69924:
		.BYTE	$05
		.WORD	_native_sub00F
		.BYTE	$0C		; SBCS
		.WORD	byte_6994D
		.BYTE	$05		; NJSR
		.WORD	_native_sub12A
		.BYTE	$12		; SWITCH
		.WORD	_tmp_ptrE+1
		.WORD	byte_69936
		.WORD	byte_6994D
		.WORD	byte_6995B
byte_69936:
		.BYTE	$29,$00
		.BYTE	$1E,$01		; SPR_IDX_SELECT
		.BYTE	$13,$00		; MOV
		.WORD	_pal_anim_mode_idx
		.BYTE	$07		; SJSR
		.WORD	byte_69969
		.BYTE	$05		; NJSR
		.WORD	_native_sub14C
		.BYTE	$07		; SJSR
		.WORD	byte_69969
		.BYTE	$07		; SJSR
		.WORD	byte_69969
		.BYTE	$07		; SJSR
		.WORD	byte_69969
byte_6994D:
		.BYTE	$29,$10
		.BYTE	$1E,$02		; SPR_IDX_SELECT
		.BYTE	$13,$0A		; MOV
		.WORD	_pal_anim_mode_idx
		.BYTE	$07		; SJSR
		.WORD	byte_69969
		.BYTE	$06		; SJMP
		.WORD	byte_6990D
byte_6995B:
		.BYTE	$07
		.WORD	byte_69961
		.BYTE	$06		; SJMP
		.WORD	byte_6990D
byte_69961:
		.BYTE	$29,$F0
		.BYTE	$1E,$00		; SPR_IDX_SELECT
		.BYTE	$13,$0B		; MOV
		.WORD	_pal_anim_mode_idx
byte_69969:
		.BYTE	$05
		.WORD	_native_sub011
		.BYTE	$05		; NJSR
		.WORD	_native_sub144
		.BYTE	$0E		; SBNE
		.WORD	byte_69978
		.BYTE	$17,$2F		; APU_LOAD
		.BYTE	$04,$01		; RUN
		.WORD	_script121
byte_69978:
		.BYTE	$05
		.WORD	_native_sub145
		.BYTE	$01		; FLUSH
		.BYTE	$09,$20		; LOOPA
		.WORD	byte_69969
		.BYTE	$08		; RET
byte_69981:
		.BYTE	$1E,$06
		.BYTE	$13,$00		; MOV
		.WORD	_pal_anim_mode_idx
		.BYTE	$17,$70		; APU_LOAD
byte_69989:
		.BYTE	$05
		.WORD	_native_sub012
		.BYTE	$02,$20		; DELAY
		.BYTE	$05		; NJSR
		.WORD	_native_sub012
		.BYTE	$02,$20		; DELAY
		.BYTE	$0A,$04		; LOOPB
		.WORD	byte_69989
		.BYTE	$06		; SJMP
		.WORD	byte_B6B07

; =============== S U B	R O U T	I N E =======================================
_native_sub00F:
		LDA		_obj_x_lo_poss,X
		CMP		#$A9
		JMP		_scr_flags_flush_ex

; =============== S U B	R O U T	I N E =======================================
_native_sub010:
		LDA		_obj_x_hi_poss,X
		JMP		_scr_flags_flush_ex

; =============== S U B	R O U T	I N E =======================================
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

; =============== S U B	R O U T	I N E =======================================
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
_script121:
		.BYTE	$05
		.WORD	_native_sub134
		.BYTE	$28,$FF		; OBJ_MOVE_Y_POS
		.BYTE	$1D,$08		; SPR_LIB_SELECT
		.BYTE	$1E,$03		; SPR_IDX_SELECT
		.BYTE	$1B		; PARAM_80_CLEAR
byte_699E5:
		.BYTE	$02,$04
		.BYTE	$05		; NJSR
		.WORD	_load_pal_patch01
		.BYTE	$02,$04		; DELAY
		.BYTE	$05		; NJSR
		.WORD	_ppu_pal_apply
		.BYTE	$0A,$04		; LOOPB
		.WORD	byte_699E5
		.BYTE	$00		; STOP

; =============== S U B	R O U T	I N E =======================================
_load_pal_patch01:
		LDA		#<[_pal_patch01]
		LDY		#>[_pal_patch01]
		JMP		_far_prg3_pal_patch_load
_script11F:
		.BYTE	$05
		.WORD	_native_sub134
		.BYTE	$28,$3F		; OBJ_MOVE_Y_POS
		.BYTE	$32,$24,$40	; OBJ_SET_SIZE
		.BYTE	$34,$01		; OBJ_SET_HP
		.BYTE	$33,$01		; VAR_1C_SET
byte_69A07:
		.BYTE	$01
		.BYTE	$07		; SJSR
		.WORD	byte_69A12
		.BYTE	$06		; SJMP
		.WORD	byte_69A07
byte_69A0E:
		.BYTE	$01
		.BYTE	$05		; NJSR
		.WORD	_scr_param_4_clear
byte_69A12:
		.BYTE	$05
		.WORD	_native_get_obj3_hp
		.BYTE	$0B		; SBEQ
		.WORD	byte_69A1B
		.BYTE	$32,$00,$00	; OBJ_SET_SIZE
byte_69A1B:
		.BYTE	$08
_script120:
		.BYTE	$05
		.WORD	_native_sub134
		.BYTE	$27,$94		; OBJ_MOVE_X_POS
		.BYTE	$28,$48		; OBJ_MOVE_Y_POS
		.BYTE	$1D,$08		; SPR_LIB_SELECT
		.BYTE	$1E,$08		; SPR_IDX_SELECT
		.BYTE	$32,$08,$20	; OBJ_SET_SIZE
		.BYTE	$34,$FF		; OBJ_SET_HP
		.BYTE	$33,$FF		; VAR_1C_SET
		.BYTE	$1B		; PARAM_80_CLEAR
		.BYTE	$07		; SJSR
		.WORD	byte_69A5B
byte_69A32:
		.BYTE	$05
		.WORD	_native_sub139
byte_69A35:
		.BYTE	$07
		.WORD	byte_69A0E
		.BYTE	$05		; NJSR
		.WORD	_native_sub14E
		.BYTE	$0B		; SBEQ
		.WORD	byte_69A35
		.BYTE	$07		; SJSR
		.WORD	byte_69A6E
		.BYTE	$17,$63		; APU_LOAD
		.BYTE	$04,$07		; RUN
		.WORD	_script122
		.BYTE	$07		; SJSR
		.WORD	byte_69A0E
		.BYTE	$04,$07		; RUN
		.WORD	_script123
byte_69A4E:
		.BYTE	$07
		.WORD	byte_69A0E
		.BYTE	$0A,$3C		; LOOPB
		.WORD	byte_69A4E
		.BYTE	$07		; SJSR
		.WORD	byte_69A5B
		.BYTE	$06		; SJMP
		.WORD	byte_69A32
byte_69A5B:
		.BYTE	$2A,$E0
byte_69A5D:
		.BYTE	$07
		.WORD	byte_69A0E
		.BYTE	$05		; NJSR
		.WORD	_obj_vert_animate
		.BYTE	$05		; NJSR
		.WORD	_native_sub013
		.BYTE	$05		; NJSR
		.WORD	_native_sub014
		.BYTE	$09,$18		; LOOPA
		.WORD	byte_69A5D
		.BYTE	$08		; RET
byte_69A6E:
		.BYTE	$2A,$40
byte_69A70:
		.BYTE	$07
		.WORD	byte_69A0E
		.BYTE	$05		; NJSR
		.WORD	_obj_vert_animate
		.BYTE	$05		; NJSR
		.WORD	_native_sub015
		.BYTE	$05		; NJSR
		.WORD	_native_sub013
		.BYTE	$09,$0C		; LOOPA
		.WORD	byte_69A70
		.BYTE	$08		; RET

; =============== S U B	R O U T	I N E =======================================
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
		LDA		word_69ABB,X
		STA		_tmp_ptr2
		LDA		off_69AB9,X
		LDY		off_69AB9+1,X
		JMP		_far_prg3_tlm_queue

; =============== S U B	R O U T	I N E =======================================
_native_sub014:
		INC		_scr_loopsB,X
		RTS

; =============== S U B	R O U T	I N E =======================================
_native_sub015:
		DEC		_scr_loopsB,X
		DEC		_scr_loopsB,X
		RTS
off_69AB9:
		.WORD	_tlm00
word_69ABB:
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
_script122:
		.BYTE	$29,$F0
		.BYTE	$06		; SJMP
		.WORD	byte_69AD8
_script123:
		.BYTE	$29,$10
byte_69AD8:
		.BYTE	$43
		.BYTE	$42		; DESTR_PC_SET
		.WORD	byte_69B00
		.BYTE	$2A,$D0		; OBJ_SET_Y_DELTA
		.BYTE	$1D,$08		; SPR_LIB_SELECT
		.BYTE	$1E,$07		; SPR_IDX_SELECT
		.BYTE	$32,$06,$10	; OBJ_SET_SIZE
		.BYTE	$34,$01		; OBJ_SET_HP
		.BYTE	$33,$01		; VAR_1C_SET
		.BYTE	$1B		; PARAM_80_CLEAR
		.BYTE	$35,$08		; OBJ_SET_FLIP
		.BYTE	$05		; NJSR
		.WORD	_native_sub13D
		.BYTE	$0F		; SBCC
		.WORD	byte_68096
		.BYTE	$07		; SJSR
		.WORD	byte_68036
		.BYTE	$2A,$E8		; OBJ_SET_Y_DELTA
		.BYTE	$07		; SJSR
		.WORD	byte_68036
byte_69AFA:
		.BYTE	$05
		.WORD	_native_sub13B
		.BYTE	$07		; SJSR
		.WORD	byte_68065
byte_69B00:
		.BYTE	$07
		.WORD	byte_6806C
		.BYTE	$35,$08		; OBJ_SET_FLIP
		.BYTE	$05		; NJSR
		.WORD	_native_sub030
byte_69B08:
		.BYTE	$18
		.BYTE	$05		; NJSR
		.WORD	_native_sub016
		.BYTE	$0B		; SBEQ
		.WORD	byte_69B08
		.BYTE	$06		; SJMP
		.WORD	byte_68096

; =============== S U B	R O U T	I N E =======================================
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
		JMP		_scr_flags_flush_ex
_obj_scr46:
		.BYTE	$05
		.WORD	_native_sub019
		.BYTE	$13,$00		; MOV
		.WORD	_ppu_scroll_nt_vert
		.BYTE	$13,$1F		; MOV
		.WORD	_apu_load_idx_req
		.BYTE	$04,$01		; RUN
		.WORD	_script124
		.BYTE	$04,$01		; RUN
		.WORD	_script125
		.BYTE	$04,$01		; RUN
		.WORD	_script126
		.BYTE	$04,$01		; RUN
		.WORD	_script127
		.BYTE	$05		; NJSR
		.WORD	_native_sub139
byte_69B49:
		.BYTE	$03
		.WORD	_native_sub14E
		.BYTE	$0B		; SBEQ
		.WORD	byte_69B49
		.BYTE	$14,$00,$1C	; CHR_BANK
		.BYTE	$14,$01,$0D	; CHR_BANK
		.BYTE	$13,$80		; MOV
		.WORD	_room_tileset_ptr
		.BYTE	$13,$99		; MOV
		.WORD	_room_tileset_ptr+1
byte_69B5D:
		.BYTE	$03
		.WORD	_native_sub14F
		.BYTE	$09,$0F		; LOOPA
		.WORD	byte_69B5D
		.BYTE	$0A,$10		; LOOPB
		.WORD	byte_69B5D
		.BYTE	$05		; NJSR
		.WORD	_pal_bg003_reload
		.BYTE	$42		; DESTR_PC_SET
		.WORD	byte_69D30
		.BYTE	$05		; NJSR
		.WORD	_native_sub134
		.BYTE	$1D,$08		; SPR_LIB_SELECT
		.BYTE	$1E,$51		; SPR_IDX_SELECT
		.BYTE	$34,$0A		; OBJ_SET_HP
		.BYTE	$33,$01		; VAR_1C_SET
		.BYTE	$32,$00,$00	; OBJ_SET_SIZE
		.BYTE	$05		; NJSR
		.WORD	_native_sub00C
		.BYTE	$38,$04,$C3	; PAL_FADE_IN
		.BYTE	$04,$06		; RUN
		.WORD	_script128
		.BYTE	$05		; NJSR
		.WORD	_native_sub14B
		.BYTE	$04,$06		; RUN
		.WORD	_script129
		.BYTE	$05		; NJSR
		.WORD	_native_sub150
		.BYTE	$02,$14		; DELAY
		.BYTE	$1B		; PARAM_80_CLEAR
		.BYTE	$32,$28,$70	; OBJ_SET_SIZE
		.BYTE	$05		; NJSR
		.WORD	_native_sub021
		.BYTE	$07		; SJSR
		.WORD	byte_69C88
		.BYTE	$2A,$F0		; OBJ_SET_Y_DELTA
		.BYTE	$04,$06		; RUN
		.WORD	_script12A
		.BYTE	$07		; SJSR
		.WORD	byte_69C7E
byte_69BA5:
		.BYTE	$07
		.WORD	byte_69D06
		.BYTE	$09,$30		; LOOPA
		.WORD	byte_69BA5
		.BYTE	$2A,$40		; OBJ_SET_Y_DELTA
byte_69BAE:
		.BYTE	$07
		.WORD	byte_69D06
		.BYTE	$09,$10		; LOOPA
		.WORD	byte_69BAE
		.BYTE	$07		; SJSR
		.WORD	byte_69C4E
byte_69BB8:
		.BYTE	$07
		.WORD	byte_69C88
byte_69BBB:
		.BYTE	$2A,$F0
		.BYTE	$04,$06		; RUN
		.WORD	_script12A
		.BYTE	$07		; SJSR
		.WORD	byte_69C7E
byte_69BC4:
		.BYTE	$07
		.WORD	byte_69D06
		.BYTE	$09,$C0		; LOOPA
		.WORD	byte_69BC4
		.BYTE	$2A,$00		; OBJ_SET_Y_DELTA
		.BYTE	$32,$00,$00	; OBJ_SET_SIZE
byte_69BD0:
		.BYTE	$07
		.WORD	byte_69CDC
		.BYTE	$0A,$3C		; LOOPB
		.WORD	byte_69BD0
		.BYTE	$04,$03		; RUN
		.WORD	_script12B
		.BYTE	$05		; NJSR
		.WORD	_native_sub01D
		.BYTE	$04,$01		; RUN
		.WORD	_script12C
byte_69BE2:
		.BYTE	$07
		.WORD	byte_69CDC
		.BYTE	$0A,$B4		; LOOPB
		.WORD	byte_69BE2
		.BYTE	$32,$28,$70	; OBJ_SET_SIZE
		.BYTE	$2A,$40		; OBJ_SET_Y_DELTA
byte_69BEE:
		.BYTE	$07
		.WORD	byte_69D06
		.BYTE	$09,$34		; LOOPA
		.WORD	byte_69BEE
		.BYTE	$07		; SJSR
		.WORD	byte_69C4E
		.BYTE	$05		; NJSR
		.WORD	_native_sub01C
		.BYTE	$0F		; SBCC
		.WORD	byte_69C10
		.BYTE	$05		; NJSR
		.WORD	_native_sub142
		.BYTE	$04,$07		; RUN
		.WORD	_script12D
byte_69C05:
		.BYTE	$07
		.WORD	byte_69CDC
		.BYTE	$0A,$3C		; LOOPB
		.WORD	byte_69C05
		.BYTE	$04,$07		; RUN
		.WORD	_script12D
byte_69C10:
		.BYTE	$05
		.WORD	_native_cmpC0_obj_x_lo_pos
		.BYTE	$0B		; SBEQ
		.WORD	byte_69BB8
		.BYTE	$05		; NJSR
		.WORD	_native_sub12A
		.BYTE	$12		; SWITCH
		.WORD	_tmp_ptrE+1
		.WORD	byte_69C22
		.WORD	byte_69C2F
		.WORD	byte_69C3C
byte_69C22:
		.BYTE	$12
		.WORD	byte_E0
		.WORD	byte_69C2F
		.WORD	byte_69C29
byte_69C29:
		.BYTE	$03
		.WORD	_native_sub151
		.BYTE	$06		; SJMP
		.WORD	byte_69C40
byte_69C2F:
		.BYTE	$12
		.WORD	byte_E1
		.WORD	byte_69C3C
		.WORD	byte_69C36
byte_69C36:
		.BYTE	$03
		.WORD	_native_sub14C
		.BYTE	$06		; SJMP
		.WORD	byte_69C40
byte_69C3C:
		.BYTE	$04,$01
		.WORD	_script12E
byte_69C40:
		.BYTE	$07
		.WORD	byte_69CDC
		.BYTE	$0A,$B4		; LOOPB
		.WORD	byte_69C40
		.BYTE	$09,$02		; LOOPA
		.WORD	byte_69C10
		.BYTE	$06		; SJMP
		.WORD	byte_69BBB
byte_69C4E:
		.BYTE	$17,$44
		.BYTE	$2A,$E0		; OBJ_SET_Y_DELTA
		.BYTE	$07		; SJSR
		.WORD	byte_69C76
		.BYTE	$2A,$E8		; OBJ_SET_Y_DELTA
		.BYTE	$07		; SJSR
		.WORD	byte_69C76
		.BYTE	$2A,$F0		; OBJ_SET_Y_DELTA
		.BYTE	$07		; SJSR
		.WORD	byte_69C76
		.BYTE	$2A,$F8		; OBJ_SET_Y_DELTA
		.BYTE	$07		; SJSR
		.WORD	byte_69C76
		.BYTE	$31,$06		; TARGET_DIR_SET
		.BYTE	$07		; SJSR
		.WORD	byte_69CB5
		.BYTE	$31,$04		; TARGET_DIR_SET
		.BYTE	$07		; SJSR
		.WORD	byte_69CB5
		.BYTE	$2A,$10		; OBJ_SET_Y_DELTA
		.BYTE	$07		; SJSR
		.WORD	byte_69C76
		.BYTE	$17,$44		; APU_LOAD
		.BYTE	$08		; RET
byte_69C76:
		.BYTE	$07
		.WORD	byte_69D06
		.BYTE	$09,$04		; LOOPA
		.WORD	byte_69C76
		.BYTE	$08		; RET
byte_69C7E:
		.BYTE	$31,$02
		.BYTE	$07		; SJSR
		.WORD	byte_69CB5
		.BYTE	$31,$00		; TARGET_DIR_SET
		.BYTE	$06		; SJMP
		.WORD	byte_69CB5
byte_69C88:
		.BYTE	$05
		.WORD	_native_sub01C
		.BYTE	$0C		; SBCS
		.WORD	byte_69CAD
byte_69C8E:
		.BYTE	$31,$08
		.BYTE	$07		; SJSR
		.WORD	byte_69CB5
byte_69C93:
		.BYTE	$07
		.WORD	byte_69CDC
		.BYTE	$0A,$3C		; LOOPB
		.WORD	byte_69C93
		.BYTE	$17,$30		; APU_LOAD
		.BYTE	$31,$0A		; TARGET_DIR_SET
		.BYTE	$07		; SJSR
		.WORD	byte_69CB5
byte_69CA1:
		.BYTE	$07
		.WORD	byte_69CDC
		.BYTE	$0A,$3C		; LOOPB
		.WORD	byte_69CA1
		.BYTE	$09,$03		; LOOPA
		.WORD	byte_69C8E
		.BYTE	$08		; RET
byte_69CAD:
		.BYTE	$07
		.WORD	byte_69CDC
		.BYTE	$0A,$F0		; LOOPB
		.WORD	byte_69CAD
		.BYTE	$08		; RET
byte_69CB5:
		.BYTE	$05
		.WORD	_native_sub017
byte_69CB8:
		.BYTE	$07
		.WORD	byte_69CDC
		.BYTE	$05		; NJSR
		.WORD	_native_sub152
		.BYTE	$0B		; SBEQ
		.WORD	byte_69CB8
		.BYTE	$08		; RET

; =============== S U B	R O U T	I N E =======================================
_native_sub017:
		LDY		_scr_vars19,X
		LDA		off_69CD0,Y
		STA		_tmp_ptr4B
		LDA		off_69CD0+1,Y
		STA		_tmp_ptr4B+1
		RTS
off_69CD0:
		.WORD	byte_51DE2
		.WORD	byte_51E02
		.WORD	byte_51DF2
		.WORD	byte_51E1B
		.WORD	byte_51DC0
		.WORD	byte_51DD1
byte_69CDC:
		.BYTE	$05
		.WORD	_native_sub144
		.BYTE	$0E		; SBNE
		.WORD	byte_69CFC
		.BYTE	$17,$2F		; APU_LOAD
		.BYTE	$04,$01		; RUN
		.WORD	_script12F
		.BYTE	$05		; NJSR
		.WORD	_native_sub01C
		.BYTE	$0F		; SBCC
		.WORD	byte_69CFC
		.BYTE	$05		; NJSR
		.WORD	_native_sub018
		.BYTE	$0E		; SBNE
		.WORD	byte_69CFC
		.BYTE	$13,$00		; MOV
		.WORD	byte_E2
		.BYTE	$04,$01		; RUN
		.WORD	_script130
byte_69CFC:
		.BYTE	$01
		.BYTE	$05		; NJSR
		.WORD	_native_sub145
		.BYTE	$08		; RET

; =============== S U B	R O U T	I N E =======================================
_native_sub018:
		LDA		byte_E2
		JMP		_scr_flags_flush_ex
byte_69D06:
		.BYTE	$07
		.WORD	byte_69CDC
		.BYTE	$05		; NJSR
		.WORD	_native_sub146
		.BYTE	$05		; NJSR
		.WORD	_native_sub147
		.BYTE	$08		; RET

; =============== S U B	R O U T	I N E =======================================
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

; =============== S U B	R O U T	I N E =======================================
_pal_bg003_reload:
		LDX		#$77
		LDA		#<[_pal_bg003]
		LDY		#>[_pal_bg003]
		JMP		_far_prg3_pal_bg_reload
byte_69D30:
		.BYTE	$2A,$00
		.BYTE	$04,$01		; RUN
		.WORD	_script12F
		.BYTE	$04,$01		; RUN
		.WORD	_script130
		.BYTE	$02,$B4		; DELAY
		.BYTE	$17,$70		; APU_LOAD
		.BYTE	$39,$04,$C7	; PAL_FADE_OUT
		.BYTE	$02,$80		; DELAY
		.BYTE	$06		; SJMP
		.WORD	byte_B6B07
_script130:
		.BYTE	$05
		.WORD	_native_sub01B
		.BYTE	$04,$01		; RUN
		.WORD	_script131
		.BYTE	$02,$13		; DELAY
		.BYTE	$09,$05		; LOOPA
		.WORD	_script130
		.BYTE	$17,$46		; APU_LOAD
		.BYTE	$03		; NJMP
		.WORD	_cat_boss_bg_patch0_draw
		.BYTE	$03		; NJMP
		.WORD	_cat_boss_bg_patch1_draw
byte_69D5B:
		.BYTE	$05
		.WORD	_native_sub01B
		.BYTE	$04,$01		; RUN
		.WORD	_script131
		.BYTE	$02,$13		; DELAY
		.BYTE	$09,$03		; LOOPA
		.WORD	byte_69D5B
		.BYTE	$00		; STOP
_script131:
		.BYTE	$04,$01
		.WORD	_script132
		.BYTE	$07		; SJSR
		.WORD	byte_6A052
		.BYTE	$00		; STOP
_script132:
		.BYTE	$1D,$08
		.BYTE	$1E,$4D		; SPR_IDX_SELECT
		.BYTE	$1B		; PARAM_80_CLEAR
		.BYTE	$03		; NJMP
		.WORD	_native_sub01A
		.BYTE	$06		; SJMP
		.WORD	byte_689E8

; =============== S U B	R O U T	I N E =======================================
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

; =============== S U B	R O U T	I N E =======================================
_native_get_rand3:
		JSR		_rand
		AND		#$03
		TAY
		RTS

; =============== S U B	R O U T	I N E =======================================
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

; =============== S U B	R O U T	I N E =======================================
_cat_boss_bg_patch0_draw:
		LDA		#$D6
		STA		_tmp_ptr44
		LDA		#$21
		STA		_tmp_ptr44+1
		LDA		#<[_cat_boss_bg_patch0]
		LDY		#>[_cat_boss_bg_patch0]
		JMP		_far_prg3_rect_draw

; =============== S U B	R O U T	I N E =======================================
_cat_boss_bg_patch1_draw:
		LDA		#$52
		STA		_tmp_ptr44
		LDA		#$22
		STA		_tmp_ptr44+1
		LDA		#<[_cat_boss_bg_patch1]
		LDY		#>[_cat_boss_bg_patch1]
		JMP		_far_prg3_rect_draw

; =============== S U B	R O U T	I N E =======================================
_native_sub01C:
		LDA		_obj_hps,X
		CMP		#$06
		JMP		_scr_flags_flush_ex

; =============== S U B	R O U T	I N E =======================================
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
_script12F:
		.BYTE	$02,$04
		.BYTE	$05		; NJSR
		.WORD	_pal_patch02_load
		.BYTE	$02,$04		; DELAY
		.BYTE	$05		; NJSR
		.WORD	_ppu_pal_apply
		.BYTE	$0A,$04		; LOOPB
		.WORD	_script12F
		.BYTE	$00		; STOP

; =============== S U B	R O U T	I N E =======================================
_pal_patch02_load:
		LDA		#<[_pal_patch02]
		LDY		#>[_pal_patch02]
		JMP		_far_prg3_pal_patch_load
byte_69E42:
		.BYTE	$07
		.WORD	_script209
		.BYTE	$06		; SJMP
		.WORD	byte_69A12
byte_69E48:
		.BYTE	$29,$00
		.BYTE	$2A,$00		; OBJ_SET_Y_DELTA
		.BYTE	$05		; NJSR
		.WORD	_native_sub139
byte_69E4F:
		.BYTE	$07
		.WORD	byte_69E42
		.BYTE	$05		; NJSR
		.WORD	_native_sub14E
		.BYTE	$0B		; SBEQ
		.WORD	byte_69E4F
		.BYTE	$08		; RET
_script128:
		.BYTE	$42
		.WORD	byte_69E8F
		.BYTE	$05		; NJSR
		.WORD	_native_sub134
		.BYTE	$34,$05		; OBJ_SET_HP
		.BYTE	$33,$01		; VAR_1C_SET
		.BYTE	$32,$06,$0C	; OBJ_SET_SIZE
		.BYTE	$27,$B2		; OBJ_MOVE_X_POS
		.BYTE	$28,$C2		; OBJ_MOVE_Y_POS
		.BYTE	$1D,$08		; SPR_LIB_SELECT
		.BYTE	$1E,$3E		; SPR_IDX_SELECT
		.BYTE	$1B		; PARAM_80_CLEAR
byte_69E6F:
		.BYTE	$07
		.WORD	byte_69E48
		.BYTE	$17,$45		; APU_LOAD
		.BYTE	$05		; NJSR
		.WORD	_native_sub153
		.BYTE	$1F		; FLIP_40_CLEAR
		.BYTE	$07		; SJSR
		.WORD	byte_69E87
		.BYTE	$05		; NJSR
		.WORD	_native_sub105
		.BYTE	$05		; NJSR
		.WORD	_native_sub129
		.BYTE	$07		; SJSR
		.WORD	byte_69E87
		.BYTE	$06		; SJMP
		.WORD	byte_69E6F
byte_69E87:
		.BYTE	$07
		.WORD	byte_69E42
		.BYTE	$09,$24		; LOOPA
		.WORD	byte_69E87
		.BYTE	$08		; RET
byte_69E8F:
		.BYTE	$13,$00
		.WORD	byte_E1
		.BYTE	$07		; SJSR
		.WORD	byte_6A069
		.BYTE	$00		; STOP
_script129:
		.BYTE	$42
		.WORD	byte_69EF8
		.BYTE	$05		; NJSR
		.WORD	_native_sub134
		.BYTE	$34,$05		; OBJ_SET_HP
		.BYTE	$33,$01		; VAR_1C_SET
		.BYTE	$32,$06,$0C	; OBJ_SET_SIZE
		.BYTE	$27,$2E		; OBJ_MOVE_X_POS
		.BYTE	$28,$C0		; OBJ_MOVE_Y_POS
		.BYTE	$1D,$08		; SPR_LIB_SELECT
		.BYTE	$1E,$4F		; SPR_IDX_SELECT
		.BYTE	$1B		; PARAM_80_CLEAR
byte_69EAD:
		.BYTE	$07
		.WORD	byte_69E48
		.BYTE	$17,$54		; APU_LOAD
		.BYTE	$29,$C8		; OBJ_SET_X_DELTA
		.BYTE	$2A,$20		; OBJ_SET_Y_DELTA
		.BYTE	$07		; SJSR
		.WORD	byte_69ECD
		.BYTE	$29,$EC		; OBJ_SET_X_DELTA
		.BYTE	$07		; SJSR
		.WORD	byte_69ED5
		.BYTE	$29,$14		; OBJ_SET_X_DELTA
		.BYTE	$07		; SJSR
		.WORD	byte_69ED5
		.BYTE	$29,$38		; OBJ_SET_X_DELTA
		.BYTE	$2A,$E0		; OBJ_SET_Y_DELTA
		.BYTE	$07		; SJSR
		.WORD	byte_69ECD
		.BYTE	$06		; SJMP
		.WORD	byte_69EAD
byte_69ECD:
		.BYTE	$07
		.WORD	byte_69E42
		.BYTE	$09,$20		; LOOPA
		.WORD	byte_69ECD
		.BYTE	$08		; RET
byte_69ED5:
		.BYTE	$2A,$B0
byte_69ED7:
		.BYTE	$07
		.WORD	byte_69E42
		.BYTE	$05		; NJSR
		.WORD	_native_sub109
		.BYTE	$09,$14		; LOOPA
		.WORD	byte_69ED7
byte_69EE1:
		.BYTE	$05
		.WORD	_native_sub129
		.BYTE	$05		; NJSR
		.WORD	_native_sub109
		.BYTE	$07		; SJSR
		.WORD	byte_69E42
		.BYTE	$05		; NJSR
		.WORD	_native_sub129
		.BYTE	$09,$14		; LOOPA
		.WORD	byte_69EE1
		.BYTE	$17,$6C		; APU_LOAD
		.BYTE	$0A,$02		; LOOPB
		.WORD	byte_69ED5
		.BYTE	$08		; RET
byte_69EF8:
		.BYTE	$13,$00
		.WORD	byte_E0
		.BYTE	$07		; SJSR
		.WORD	byte_6A069
		.BYTE	$00		; STOP
_script12D:
		.BYTE	$28,$90
		.BYTE	$35,$08		; OBJ_SET_FLIP
		.BYTE	$34,$01		; OBJ_SET_HP
		.BYTE	$33,$01		; VAR_1C_SET
		.BYTE	$32,$04,$10	; OBJ_SET_SIZE
		.BYTE	$1D,$08		; SPR_LIB_SELECT
		.BYTE	$1E,$46		; SPR_IDX_SELECT
		.BYTE	$1B		; PARAM_80_CLEAR
		.BYTE	$2A,$E8		; OBJ_SET_Y_DELTA
		.BYTE	$05		; NJSR
		.WORD	_native_sub01E
byte_69F15:
		.BYTE	$07
		.WORD	byte_6803D
		.BYTE	$0F		; SBCC
		.WORD	byte_69F23
		.BYTE	$09,$06		; LOOPA
		.WORD	byte_69F15
		.BYTE	$23		; FLIP_40_TOGGLE
		.BYTE	$06		; SJMP
		.WORD	byte_69F15
byte_69F23:
		.BYTE	$1E,$47
byte_69F25:
		.BYTE	$02,$04
		.BYTE	$22		; FLIP_80_SET
		.BYTE	$02,$04		; DELAY
		.BYTE	$20		; FLIP_40_SET
		.BYTE	$02,$04		; DELAY
		.BYTE	$21		; FLIP_80_CLEAR
		.BYTE	$02,$04		; DELAY
		.BYTE	$1F		; FLIP_40_CLEAR
		.BYTE	$09,$02		; LOOPA
		.WORD	byte_69F25
		.BYTE	$00		; STOP

; =============== S U B	R O U T	I N E =======================================
_native_sub01E:
		JSR		_native_sub143
		LDY		_tmp_ptrE+1
		LDA		byte_69F42,Y
		STA		_obj_x_deltas,X
		RTS
byte_69F42:
		.BYTE	$F0,$E4,$E8,$EC
_script12C:
		.BYTE	$26,$30,$00
		.BYTE	$1D,$08		; SPR_LIB_SELECT
		.BYTE	$1E,$49		; SPR_IDX_SELECT
		.BYTE	$1B		; PARAM_80_CLEAR
		.BYTE	$02,$AA		; DELAY
		.BYTE	$00		; STOP
_script12B:
		.BYTE	$28,$10
		.BYTE	$42		; DESTR_PC_SET
		.WORD	byte_69F7C
		.BYTE	$34,$01		; OBJ_SET_HP
		.BYTE	$33,$FF		; VAR_1C_SET
		.BYTE	$35,$08		; OBJ_SET_FLIP
		.BYTE	$32,$06,$0E	; OBJ_SET_SIZE
		.BYTE	$1D,$08		; SPR_LIB_SELECT
		.BYTE	$1E,$4C		; SPR_IDX_SELECT
		.BYTE	$1B		; PARAM_80_CLEAR
		.BYTE	$07		; SJSR
		.WORD	byte_68036
		.BYTE	$17,$2B		; APU_LOAD
		.BYTE	$2A,$F0		; OBJ_SET_Y_DELTA
		.BYTE	$07		; SJSR
		.WORD	byte_68036
		.BYTE	$17,$2B		; APU_LOAD
		.BYTE	$05		; NJSR
		.WORD	_native_sub13B
byte_69F73:
		.BYTE	$07
		.WORD	byte_69FB5
		.BYTE	$05		; NJSR
		.WORD	_native_get_obj_var0D
		.BYTE	$0D		; SBMI
		.WORD	byte_69F73
byte_69F7C:
		.BYTE	$05
		.WORD	_native_sub13A
		.BYTE	$05		; NJSR
		.WORD	_native_sub134
byte_69F82:
		.BYTE	$07
		.WORD	byte_69FB5
		.BYTE	$05		; NJSR
		.WORD	_players_animB_sub0129_sub06_C
		.BYTE	$05		; NJSR
		.WORD	_native_get_obj_var0D
		.BYTE	$10		; SBPL
		.WORD	byte_69F82
		.BYTE	$17,$24		; APU_LOAD
		.BYTE	$35,$08		; OBJ_SET_FLIP
		.BYTE	$05		; NJSR
		.WORD	_native_sub12B
		.BYTE	$05		; NJSR
		.WORD	_native_sub030
		.BYTE	$05		; NJSR
		.WORD	_native_sub154
		.BYTE	$34,$01		; OBJ_SET_HP
		.BYTE	$33,$FF		; VAR_1C_SET
byte_69F9F:
		.BYTE	$19
		.BYTE	$07		; SJSR
		.WORD	byte_69FB5
		.BYTE	$05		; NJSR
		.WORD	_native_sub016
		.BYTE	$0B		; SBEQ
		.WORD	byte_69F9F
		.BYTE	$17,$30		; APU_LOAD
byte_69FAB:
		.BYTE	$07
		.WORD	byte_69FB5
		.BYTE	$19		; JSR_OBJ_ANIMATE
		.BYTE	$05		; NJSR
		.WORD	_native_sub109
		.BYTE	$06		; SJMP
		.WORD	byte_69FAB
byte_69FB5:
		.BYTE	$03
		.WORD	_native_sub01F
		.BYTE	$0E		; SBNE
		.WORD	byte_69FBC
		.BYTE	$08		; RET
byte_69FBC:
		.BYTE	$05
		.WORD	_native_get_obj_var0D
		.BYTE	$0D		; SBMI
		.WORD	byte_69FCA
		.BYTE	$05		; NJSR
		.WORD	_native_sub033
		.BYTE	$28,$08		; OBJ_MOVE_Y_POS
		.BYTE	$05		; NJSR
		.WORD	_scr_param_4_clear
byte_69FCA:
		.BYTE	$05
		.WORD	_native_sub13A
		.BYTE	$34,$01		; OBJ_SET_HP
		.BYTE	$33,$01		; VAR_1C_SET
		.BYTE	$32,$0C,$0E	; OBJ_SET_SIZE
		.BYTE	$07		; SJSR
		.WORD	byte_6A069
		.BYTE	$00		; STOP

; =============== S U B	R O U T	I N E =======================================
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
		JMP		_scr_flags_flush_ex
byte_69FED:
		.BYTE	$4C,$4C,$4B,$4A
_script12E:
		.BYTE	$35,$08
		.BYTE	$27,$18		; OBJ_MOVE_X_POS
		.BYTE	$28,$F0		; OBJ_MOVE_Y_POS
		.BYTE	$1D,$08		; SPR_LIB_SELECT
		.BYTE	$1E,$48		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	byte_6A04B
		.BYTE	$27,$09		; OBJ_MOVE_X_POS
		.BYTE	$28,$F8		; OBJ_MOVE_Y_POS
		.BYTE	$07		; SJSR
		.WORD	byte_6A04B
		.BYTE	$27,$09		; OBJ_MOVE_X_POS
		.BYTE	$28,$08		; OBJ_MOVE_Y_POS
		.BYTE	$07		; SJSR
		.WORD	byte_6A04B
		.BYTE	$27,$05		; OBJ_MOVE_X_POS
		.BYTE	$28,$09		; OBJ_MOVE_Y_POS
		.BYTE	$07		; SJSR
		.WORD	byte_6A04B
		.BYTE	$27,$05		; OBJ_MOVE_X_POS
		.BYTE	$28,$07		; OBJ_MOVE_Y_POS
		.BYTE	$07		; SJSR
		.WORD	byte_6A04B
		.BYTE	$27,$07		; OBJ_MOVE_X_POS
		.BYTE	$28,$FE		; OBJ_MOVE_Y_POS
byte_6A01E:
		.BYTE	$07
		.WORD	byte_6A04B
		.BYTE	$09,$08		; LOOPA
		.WORD	byte_6A01E
		.BYTE	$04,$07		; RUN
		.WORD	_script133
		.BYTE	$0A,$03		; LOOPB
		.WORD	byte_6A01E
		.BYTE	$00		; STOP
_script133:
		.BYTE	$17,$6F
		.BYTE	$35,$08		; OBJ_SET_FLIP
		.BYTE	$34,$01		; OBJ_SET_HP
		.BYTE	$33,$01		; VAR_1C_SET
		.BYTE	$32,$04,$08	; OBJ_SET_SIZE
		.BYTE	$1D,$08		; SPR_LIB_SELECT
		.BYTE	$1E,$48		; SPR_IDX_SELECT
		.BYTE	$29,$40		; OBJ_SET_X_DELTA
		.BYTE	$05		; NJSR
		.WORD	_native_sub10E
		.BYTE	$05		; NJSR
		.WORD	_native_sub10F
byte_6A045:
		.BYTE	$07
		.WORD	byte_6A04B
		.BYTE	$06		; SJMP
		.WORD	byte_6A045
byte_6A04B:
		.BYTE	$1B
		.BYTE	$18		; JMP_OBJ_ANIMATE
		.BYTE	$18		; JMP_OBJ_ANIMATE
		.BYTE	$1C		; PARAM_80_SET
		.BYTE	$18		; JMP_OBJ_ANIMATE
		.BYTE	$18		; JMP_OBJ_ANIMATE
		.BYTE	$08		; RET
byte_6A052:
		.BYTE	$17,$46
		.BYTE	$1D,$08		; SPR_LIB_SELECT
		.BYTE	$1B		; PARAM_80_CLEAR
		.BYTE	$1E,$40		; SPR_IDX_SELECT
		.BYTE	$02,$08		; DELAY
		.BYTE	$1E,$41		; SPR_IDX_SELECT
		.BYTE	$02,$08		; DELAY
		.BYTE	$1E,$44		; SPR_IDX_SELECT
		.BYTE	$02,$08		; DELAY
		.BYTE	$1E,$45		; SPR_IDX_SELECT
		.BYTE	$02,$08		; DELAY
		.BYTE	$1C		; PARAM_80_SET
		.BYTE	$08		; RET
byte_6A069:
		.BYTE	$17,$46
		.BYTE	$1D,$08		; SPR_LIB_SELECT
		.BYTE	$1B		; PARAM_80_CLEAR
		.BYTE	$1E,$40		; SPR_IDX_SELECT
		.BYTE	$02,$08		; DELAY
		.BYTE	$1E,$41		; SPR_IDX_SELECT
		.BYTE	$02,$08		; DELAY
		.BYTE	$1E,$42		; SPR_IDX_SELECT
		.BYTE	$02,$08		; DELAY
		.BYTE	$1E,$43		; SPR_IDX_SELECT
		.BYTE	$02,$08		; DELAY
		.BYTE	$1C		; PARAM_80_SET
		.BYTE	$08		; RET
_script12A:
		.BYTE	$1D,$08
		.BYTE	$1B		; PARAM_80_CLEAR
byte_6A083:
		.BYTE	$17,$43
byte_6A085:
		.BYTE	$1E,$3F
		.BYTE	$03		; NJMP
		.WORD	_native_sub020
		.BYTE	$03		; NJMP
		.WORD	_native_sub020
		.BYTE	$1E,$54		; SPR_IDX_SELECT
		.BYTE	$03		; NJMP
		.WORD	_native_sub020
		.BYTE	$03		; NJMP
		.WORD	_native_sub020
		.BYTE	$09,$0A		; LOOPA
		.WORD	byte_6A085
		.BYTE	$06		; SJMP
		.WORD	byte_6A083

; =============== S U B	R O U T	I N E =======================================
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
_script124:
		.BYTE	$05
		.WORD	_native_sub134
		.BYTE	$35,$08		; OBJ_SET_FLIP
		.BYTE	$1D,$08		; SPR_LIB_SELECT
		.BYTE	$1E,$52		; SPR_IDX_SELECT
		.BYTE	$1B		; PARAM_80_CLEAR
		.BYTE	$26,$BC,$00	; OBJ_SET_Y_POS
byte_6A0DC:
		.BYTE	$25,$00,$00
		.BYTE	$07		; SJSR
		.WORD	byte_6A0F7
		.BYTE	$25,$20,$00	; OBJ_SET_X_POS
		.BYTE	$07		; SJSR
		.WORD	byte_6A0F7
		.BYTE	$25,$10,$00	; OBJ_SET_X_POS
		.BYTE	$07		; SJSR
		.WORD	byte_6A0F7
		.BYTE	$25,$30,$00	; OBJ_SET_X_POS
		.BYTE	$07		; SJSR
		.WORD	byte_6A0F7
		.BYTE	$06		; SJMP
		.WORD	byte_6A0DC
byte_6A0F7:
		.BYTE	$01
		.BYTE	$27,$40		; OBJ_MOVE_X_POS
		.BYTE	$09,$04		; LOOPA
		.WORD	byte_6A0F7
		.BYTE	$08		; RET
_script125:
		.BYTE	$31,$04
		.BYTE	$25,$20,$00	; OBJ_SET_X_POS
		.BYTE	$26,$20,$00	; OBJ_SET_Y_POS
		.BYTE	$07		; SJSR
		.WORD	byte_6A132
		.BYTE	$05		; NJSR
		.WORD	_pal_bg000_load
		.BYTE	$00		; STOP
_script126:
		.BYTE	$31,$02
		.BYTE	$25,$C0,$00	; OBJ_SET_X_POS
		.BYTE	$26,$20,$00	; OBJ_SET_Y_POS
		.BYTE	$07		; SJSR
		.WORD	byte_6A132
		.BYTE	$05		; NJSR
		.WORD	_pal_bg001_load
		.BYTE	$00		; STOP
_script127:
		.BYTE	$31,$01
		.BYTE	$25,$70,$00	; OBJ_SET_X_POS
		.BYTE	$26,$40,$00	; OBJ_SET_Y_POS
		.BYTE	$07		; SJSR
		.WORD	byte_6A132
		.BYTE	$05		; NJSR
		.WORD	_pal_bg002_load
		.BYTE	$39,$01,$C0	; PAL_FADE_OUT
		.BYTE	$05		; NJSR
		.WORD	_native_sub155
		.BYTE	$00		; STOP
byte_6A132:
		.BYTE	$05
		.WORD	_native_sub000
		.BYTE	$1D,$05		; SPR_LIB_SELECT
		.BYTE	$1E,$06		; SPR_IDX_SELECT
byte_6A139:
		.BYTE	$1C
		.BYTE	$01		; FLUSH
		.BYTE	$01		; FLUSH
		.BYTE	$1B		; PARAM_80_CLEAR
		.BYTE	$01		; FLUSH
		.BYTE	$01		; FLUSH
		.BYTE	$09,$10		; LOOPA
		.WORD	byte_6A139
		.BYTE	$0A,$06		; LOOPB
		.WORD	byte_6A139
		.BYTE	$1E,$07		; SPR_IDX_SELECT
		.BYTE	$17,$6D		; APU_LOAD
		.BYTE	$02,$10		; DELAY
		.BYTE	$08		; RET

; =============== S U B	R O U T	I N E =======================================
_pal_bg000_load:
		LDA		#<[_pal_bg000]
		LDY		#>[_pal_bg000]
		JMP		_far_prg3_bg_pal_load

; =============== S U B	R O U T	I N E =======================================
_pal_bg001_load:
		LDA		#<[_pal_bg001]
		LDY		#>[_pal_bg001]
		JMP		_far_prg3_bg_pal_load

; =============== S U B	R O U T	I N E =======================================
_pal_bg002_load:
		LDA		#<[_pal_bg002]
		LDY		#>[_pal_bg002]
		JMP		_far_prg3_bg_pal_load

; =============== S U B	R O U T	I N E =======================================
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
_obj_scr20:
		.BYTE	$07
		.WORD	byte_6A19A
		.BYTE	$05		; NJSR
		.WORD	_native_sub156
		.BYTE	$00		; STOP
_obj_scr21:
		.BYTE	$07
		.WORD	byte_6A193
		.BYTE	$00		; STOP
_obj_scr22:
		.BYTE	$07
		.WORD	byte_6A193
		.BYTE	$05		; NJSR
		.WORD	_native_sub157
		.BYTE	$00		; STOP
byte_6A189:
		.BYTE	$07
		.WORD	byte_6A193
		.BYTE	$05		; NJSR
		.WORD	_native_sub157
		.BYTE	$05		; NJSR
		.WORD	_native_sub157
		.BYTE	$00		; STOP
byte_6A193:
		.BYTE	$07
		.WORD	byte_6A19A
		.BYTE	$05		; NJSR
		.WORD	_native_sub158
		.BYTE	$08		; RET
byte_6A19A:
		.BYTE	$32,$06,$10
byte_6A19D:
		.BYTE	$34,$01
		.BYTE	$07		; SJSR
		.WORD	_script200
		.BYTE	$05		; NJSR
		.WORD	_native_sub159
		.BYTE	$0B		; SBEQ
		.WORD	byte_6A19D
		.BYTE	$08		; RET
		.BYTE	$28,$08		; OBJ_MOVE_Y_POS
byte_6A1AB:
		.BYTE	$17,$23
		.BYTE	$1D,$06		; SPR_LIB_SELECT
		.BYTE	$1B		; PARAM_80_CLEAR
		.BYTE	$1E,$04		; SPR_IDX_SELECT
		.BYTE	$02,$06		; DELAY
		.BYTE	$1E,$05		; SPR_IDX_SELECT
		.BYTE	$02,$06		; DELAY
		.BYTE	$1E,$06		; SPR_IDX_SELECT
		.BYTE	$02,$06		; DELAY
		.BYTE	$1E,$07		; SPR_IDX_SELECT
		.BYTE	$08		; RET
_obj_scr1B:
		.BYTE	$27,$50
		.BYTE	$27,$50		; OBJ_MOVE_X_POS
		.BYTE	$29,$F0		; OBJ_SET_X_DELTA
		.BYTE	$1D,$00		; SPR_LIB_SELECT
		.BYTE	$1B		; PARAM_80_CLEAR
byte_6A1C8:
		.BYTE	$1E,$23
		.BYTE	$07		; SJSR
		.WORD	_script_animate10
		.BYTE	$1E,$24		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	_script_animate10
		.BYTE	$1E,$25		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	_script_animate10
		.BYTE	$1E,$24		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	_script_animate10
		.BYTE	$09,$05		; LOOPA
		.WORD	byte_6A1C8
		.BYTE	$07		; SJSR
		.WORD	byte_6A204
		.BYTE	$31,$0C		; TARGET_DIR_SET
		.BYTE	$04,$0A		; RUN
		.WORD	_script134
		.BYTE	$07		; SJSR
		.WORD	byte_6A208
		.BYTE	$07		; SJSR
		.WORD	byte_6A204
		.BYTE	$31,$0C		; TARGET_DIR_SET
		.BYTE	$04,$0A		; RUN
		.WORD	_script135
		.BYTE	$07		; SJSR
		.WORD	byte_6A208
		.BYTE	$07		; SJSR
		.WORD	byte_6A204
		.BYTE	$05		; NJSR
		.WORD	_native_sub15A
byte_6A1FE:
		.BYTE	$07
		.WORD	byte_6A208
		.BYTE	$06		; SJMP
		.WORD	byte_6A1FE
byte_6A204:
		.BYTE	$1E,$1C
		.BYTE	$31,$00		; TARGET_DIR_SET
byte_6A208:
		.BYTE	$03
		.WORD	_native_sub15B
		.BYTE	$0A,$1E		; LOOPB
		.WORD	byte_6A208
		.BYTE	$08		; RET
_script134:
		.BYTE	$29,$DE
		.BYTE	$06		; SJMP
		.WORD	byte_6A217
_script135:
		.BYTE	$29,$E8
byte_6A217:
		.BYTE	$27,$F2
		.BYTE	$28,$F2		; OBJ_MOVE_Y_POS
		.BYTE	$2A,$D8		; OBJ_SET_Y_DELTA
		.BYTE	$07		; SJSR
		.WORD	byte_6A25D
		.BYTE	$07		; SJSR
		.WORD	byte_68020
		.BYTE	$05		; NJSR
		.WORD	_native_sub15C
		.BYTE	$00		; STOP
_obj_scr1F:
		.BYTE	$1D,$06
		.BYTE	$1E,$01		; SPR_IDX_SELECT
		.BYTE	$32,$06,$0C	; OBJ_SET_SIZE
		.BYTE	$34,$01		; OBJ_SET_HP
		.BYTE	$1B		; PARAM_80_CLEAR
		.BYTE	$07		; SJSR
		.WORD	_script200
		.BYTE	$05		; NJSR
		.WORD	_native_sub15D
_script151:
		.BYTE	$1D,$06
		.BYTE	$1E,$08		; SPR_IDX_SELECT
byte_6A23B:
		.BYTE	$05
		.WORD	_native_sub15E
		.BYTE	$17,$37		; APU_LOAD
byte_6A240:
		.BYTE	$28,$F0
		.BYTE	$29,$00		; OBJ_SET_X_DELTA
		.BYTE	$2A,$FC		; OBJ_SET_Y_DELTA
		.BYTE	$1B		; PARAM_80_CLEAR
byte_6A247:
		.BYTE	$07
		.WORD	_script_animate16
		.BYTE	$09,$04		; LOOPA
		.WORD	byte_6A247
		.BYTE	$02,$14		; DELAY
		.BYTE	$00		; STOP
		.BYTE	$2A,$D7		; OBJ_SET_Y_DELTA
_script41:
		.BYTE	$07
		.WORD	byte_6A25D
		.BYTE	$07		; SJSR
		.WORD	byte_68020
		.BYTE	$05		; NJSR
		.WORD	_native_sub15F
		.BYTE	$00		; STOP
byte_6A25D:
		.BYTE	$1D,$06
		.BYTE	$1E,$00		; SPR_IDX_SELECT
		.BYTE	$32,$04,$0A	; OBJ_SET_SIZE
		.BYTE	$34,$01		; OBJ_SET_HP
		.BYTE	$1B		; PARAM_80_CLEAR
		.BYTE	$08		; RET
byte_6A268:
		.BYTE	$1D,$06
		.BYTE	$1E,$03		; SPR_IDX_SELECT
		.BYTE	$32,$10,$20	; OBJ_SET_SIZE
		.BYTE	$34,$01		; OBJ_SET_HP
		.BYTE	$1B		; PARAM_80_CLEAR
		.BYTE	$07		; SJSR
		.WORD	_script200
		.BYTE	$06		; SJMP
		.WORD	byte_6A1AB
_obj_scr1D:
		.BYTE	$07
		.WORD	byte_6A268
		.BYTE	$42		; DESTR_PC_SET
		.WORD	byte_6A2A0
		.BYTE	$05		; NJSR
		.WORD	_native_sub13B
		.BYTE	$1D,$04		; SPR_LIB_SELECT
		.BYTE	$34,$01		; OBJ_SET_HP
		.BYTE	$32,$06,$0E	; OBJ_SET_SIZE
		.BYTE	$06		; SJMP
		.WORD	byte_6A2BD
byte_6A28B:
		.BYTE	$29,$00
		.BYTE	$05		; NJSR
		.WORD	_native_sub160
byte_6A290:
		.BYTE	$01
		.BYTE	$05		; NJSR
		.WORD	_native_get_obj_var0D
		.BYTE	$10		; SBPL
		.WORD	byte_6A2A0
		.BYTE	$07		; SJSR
		.WORD	byte_6A589
		.BYTE	$0F		; SBCC
		.WORD	byte_6A290
		.BYTE	$06		; SJMP
		.WORD	byte_6A2AE
byte_6A2A0:
		.BYTE	$07
		.WORD	byte_6806C
		.BYTE	$29,$10		; OBJ_SET_X_DELTA
		.BYTE	$2A,$8C		; OBJ_SET_Y_DELTA
		.BYTE	$05		; NJSR
		.WORD	_native_sub029
		.BYTE	$34,$01		; OBJ_SET_HP
		.BYTE	$33,$02		; VAR_1C_SET
byte_6A2AE:
		.BYTE	$05
		.WORD	_native_sub11C
		.BYTE	$05		; NJSR
		.WORD	_native_sub161
		.BYTE	$07		; SJSR
		.WORD	byte_6A2CF
		.BYTE	$05		; NJSR
		.WORD	_far_players_animB_sub0129_G
		.BYTE	$0D		; SBMI
		.WORD	byte_6A28B
byte_6A2BD:
		.BYTE	$2A,$E0
		.BYTE	$07		; SJSR
		.WORD	byte_6A2CF
		.BYTE	$2A,$F0		; OBJ_SET_Y_DELTA
		.BYTE	$07		; SJSR
		.WORD	byte_6A2CF
		.BYTE	$2A,$F8		; OBJ_SET_Y_DELTA
		.BYTE	$07		; SJSR
		.WORD	byte_6A2CF
		.BYTE	$06		; SJMP
		.WORD	byte_6A28B
byte_6A2CF:
		.BYTE	$03
		.WORD	_native_sub022
		.BYTE	$34,$01		; OBJ_SET_HP
		.BYTE	$33,$02		; VAR_1C_SET
		.BYTE	$05		; NJSR
		.WORD	_native_sub109
		.BYTE	$07		; SJSR
		.WORD	byte_6A557
		.BYTE	$0C		; SBCS
		.WORD	byte_6A2CF
		.BYTE	$08		; RET

; =============== S U B	R O U T	I N E =======================================
_native_sub022:
		LDA		#<[byte_6A2E7]
		LDY		#>[byte_6A2E7]
		JMP		_native_sub023
byte_6A2E7:
		.BYTE	$03,$00
		.BYTE	$04,$00
		.BYTE	$03,$40
		.BYTE	$04,$C0

; =============== S U B	R O U T	I N E =======================================
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
_obj_scr1E:
		.BYTE	$07
		.WORD	byte_6A268
		.BYTE	$05		; NJSR
		.WORD	_native_sub13B
		.BYTE	$05		; NJSR
		.WORD	_native_sub154
		.BYTE	$35,$20		; OBJ_SET_FLIP
		.BYTE	$1D,$05		; SPR_LIB_SELECT
		.BYTE	$1E,$08		; SPR_IDX_SELECT
		.BYTE	$32,$14,$0F	; OBJ_SET_SIZE
		.BYTE	$34,$01		; OBJ_SET_HP
		.BYTE	$14,$01,$00	; CHR_BANK
		.BYTE	$1B		; PARAM_80_CLEAR
		.BYTE	$2A,$D7		; OBJ_SET_Y_DELTA
		.BYTE	$07		; SJSR
		.WORD	byte_68036
byte_6A330:
		.BYTE	$03
		.WORD	_native_sub162
		.BYTE	$0C		; SBCS
		.WORD	byte_6A330
		.BYTE	$04,$01		; RUN
		.WORD	_script136
		.BYTE	$02,$B0		; DELAY
		.BYTE	$04,$01		; RUN
		.WORD	_script137
		.BYTE	$06		; SJMP
		.WORD	_script_idle
_script137:
		.BYTE	$04,$01
		.WORD	_script138
		.BYTE	$03		; NJMP
		.WORD	_native_sub117
		.BYTE	$02,$24		; DELAY
		.BYTE	$27,$C0		; OBJ_MOVE_X_POS
		.BYTE	$32,$40,$00	; OBJ_SET_SIZE
byte_6A351:
		.BYTE	$03
		.WORD	_native_sub024
		.BYTE	$06		; SJMP
		.WORD	byte_6A351

; =============== S U B	R O U T	I N E =======================================
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
_script138:
		.BYTE	$27,$86
		.BYTE	$28,$B0		; OBJ_MOVE_Y_POS
		.BYTE	$28,$AF		; OBJ_MOVE_Y_POS
		.BYTE	$1D,$00		; SPR_LIB_SELECT
		.BYTE	$1E,$10		; SPR_IDX_SELECT
byte_6A404:
		.BYTE	$17,$4B
byte_6A406:
		.BYTE	$03
		.WORD	_native_sub025
		.BYTE	$0F		; SBCC
		.WORD	_script_idle
		.BYTE	$09,$28		; LOOPA
		.WORD	byte_6A406
		.BYTE	$06		; SJMP
		.WORD	byte_6A404

; =============== S U B	R O U T	I N E =======================================
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
		JMP		_scr_flags_flush_ex
byte_6A455:
		.BYTE	$A8,$AA,$AC,$BF
_script136:
		.BYTE	$13,$10
		.WORD	_pal_anim_mode_idx
		.BYTE	$05		; NJSR
		.WORD	_native_sub026
		.BYTE	$28,$DA		; OBJ_MOVE_Y_POS
		.BYTE	$1D,$00		; SPR_LIB_SELECT
		.BYTE	$1B		; PARAM_80_CLEAR
		.BYTE	$29,$E7		; OBJ_SET_X_DELTA
		.BYTE	$2A,$E8		; OBJ_SET_Y_DELTA
byte_6A469:
		.BYTE	$07
		.WORD	byte_6A498
		.BYTE	$0A,$0F		; LOOPB
		.WORD	byte_6A469
byte_6A470:
		.BYTE	$29,$00
		.BYTE	$2A,$00		; OBJ_SET_Y_DELTA
		.BYTE	$07		; SJSR
		.WORD	byte_6A498
		.BYTE	$07		; SJSR
		.WORD	byte_6A498
		.BYTE	$2A,$20		; OBJ_SET_Y_DELTA
		.BYTE	$05		; NJSR
		.WORD	_native_sub14C
		.BYTE	$07		; SJSR
		.WORD	byte_6A498
		.BYTE	$2A,$F0		; OBJ_SET_Y_DELTA
		.BYTE	$07		; SJSR
		.WORD	byte_6A498
		.BYTE	$07		; SJSR
		.WORD	byte_6A498
		.BYTE	$09,$03		; LOOPA
		.WORD	byte_6A470
		.BYTE	$05		; NJSR
		.WORD	_native_sub12B
		.BYTE	$29,$E8		; OBJ_SET_X_DELTA
		.BYTE	$2A,$E8		; OBJ_SET_Y_DELTA
		.BYTE	$06		; SJMP
		.WORD	byte_68092
byte_6A498:
		.BYTE	$1E,$17
		.BYTE	$18		; JMP_OBJ_ANIMATE
		.BYTE	$18		; JMP_OBJ_ANIMATE
		.BYTE	$18		; JMP_OBJ_ANIMATE
		.BYTE	$1E,$18		; SPR_IDX_SELECT
		.BYTE	$18		; JMP_OBJ_ANIMATE
		.BYTE	$18		; JMP_OBJ_ANIMATE
		.BYTE	$18		; JMP_OBJ_ANIMATE
		.BYTE	$08		; RET

; =============== S U B	R O U T	I N E =======================================
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
		STA		_scr_vars1E,X
		RTS
_obj_scr09:
		.BYTE	$05
		.WORD	_native_sub154
		.BYTE	$05		; NJSR
		.WORD	_scr_param_4_set
		.BYTE	$1D,$05		; SPR_LIB_SELECT
		.BYTE	$1E,$09		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	_script201
byte_6A4D0:
		.BYTE	$05
		.WORD	_native_sub139
byte_6A4D3:
		.BYTE	$03
		.WORD	_native_sub14E
		.BYTE	$0B		; SBEQ
		.WORD	byte_6A4D3
		.BYTE	$17,$69		; APU_LOAD
		.BYTE	$02,$08		; DELAY
		.BYTE	$1E,$0A		; SPR_IDX_SELECT
		.BYTE	$02,$04		; DELAY
		.BYTE	$1E,$0B		; SPR_IDX_SELECT
		.BYTE	$02,$04		; DELAY
		.BYTE	$1E,$09		; SPR_IDX_SELECT
		.BYTE	$06		; SJMP
		.WORD	byte_6A4D0
_obj_scr07:
		.BYTE	$42
		.WORD	byte_6A59B
		.BYTE	$05		; NJSR
		.WORD	_native_sub139
		.BYTE	$27,$08		; OBJ_MOVE_X_POS
		.BYTE	$1D,$04		; SPR_LIB_SELECT
		.BYTE	$1E,$00		; SPR_IDX_SELECT
		.BYTE	$32,$06,$0E	; OBJ_SET_SIZE
		.BYTE	$07		; SJSR
		.WORD	_script201
byte_6A4FC:
		.BYTE	$1E,$00
		.BYTE	$35,$00		; OBJ_SET_FLIP
		.BYTE	$34,$01		; OBJ_SET_HP
		.BYTE	$29,$00		; OBJ_SET_X_DELTA
		.BYTE	$05		; NJSR
		.WORD	_native_sub160
byte_6A507:
		.BYTE	$01
		.BYTE	$05		; NJSR
		.WORD	_native_get_obj_var0D
		.BYTE	$10		; SBPL
		.WORD	byte_6A517
		.BYTE	$07		; SJSR
		.WORD	byte_6A589
		.BYTE	$0F		; SBCC
		.WORD	byte_6A507
		.BYTE	$06		; SJMP
		.WORD	byte_6A53E
byte_6A517:
		.BYTE	$05
		.WORD	_native_sub164
		.BYTE	$05		; NJSR
		.WORD	_native_sub134
byte_6A51D:
		.BYTE	$05
		.WORD	_native_get_obj_var0D
		.BYTE	$0D		; SBMI
		.WORD	byte_6A535
		.BYTE	$05		; NJSR
		.WORD	_native_get_obj_hp
		.BYTE	$0E		; SBNE
		.WORD	byte_6A52F
		.BYTE	$03		; NJMP
		.WORD	_native_sub02B
		.BYTE	$06		; SJMP
		.WORD	byte_6A51D
byte_6A52F:
		.BYTE	$05
		.WORD	_native_sub032
		.BYTE	$06		; SJMP
		.WORD	byte_6A4FC
byte_6A535:
		.BYTE	$29,$10
		.BYTE	$2A,$8C		; OBJ_SET_Y_DELTA
		.BYTE	$05		; NJSR
		.WORD	_native_sub029
		.BYTE	$17,$24		; APU_LOAD
byte_6A53E:
		.BYTE	$05
		.WORD	_native_sub11C
		.BYTE	$05		; NJSR
		.WORD	_native_sub161
		.BYTE	$34,$FF		; OBJ_SET_HP
		.BYTE	$33,$02		; VAR_1C_SET
		.BYTE	$1E,$00		; SPR_IDX_SELECT
byte_6A54A:
		.BYTE	$01
		.BYTE	$05		; NJSR
		.WORD	_native_sub109
		.BYTE	$07		; SJSR
		.WORD	byte_6A557
		.BYTE	$0C		; SBCS
		.WORD	byte_6A54A
		.BYTE	$06		; SJMP
		.WORD	byte_6A4FC
byte_6A557:
		.BYTE	$05
		.WORD	_native_sub154
		.BYTE	$05		; NJSR
		.WORD	_obj_move_hor_animate
		.BYTE	$05		; NJSR
		.WORD	_native_sub13C
		.BYTE	$0F		; SBCC
		.WORD	byte_6A569
		.BYTE	$05		; NJSR
		.WORD	_native_sub104
		.BYTE	$0F		; SBCC
		.WORD	byte_6A56B
byte_6A569:
		.BYTE	$29,$00
byte_6A56B:
		.BYTE	$05
		.WORD	_native_sub109
		.BYTE	$05		; NJSR
		.WORD	_native_get_obj_y_delta
		.BYTE	$0D		; SBMI
		.WORD	byte_6A589
		.BYTE	$05		; NJSR
		.WORD	_obj_vert_animate
		.BYTE	$05		; NJSR
		.WORD	_native_sub165
		.BYTE	$0C		; SBCS
		.WORD	byte_6A583
		.BYTE	$05		; NJSR
		.WORD	_native_sub10A
		.BYTE	$0F		; SBCC
		.WORD	byte_6A585
byte_6A583:
		.BYTE	$2A,$01
byte_6A585:
		.BYTE	$05
		.WORD	_scr_flags_flush_clc
		.BYTE	$08		; RET
byte_6A589:
		.BYTE	$05
		.WORD	_obj_vert_animate
		.BYTE	$05		; NJSR
		.WORD	_native_sub107
		.BYTE	$0F		; SBCC
		.WORD	byte_6A598
		.BYTE	$05		; NJSR
		.WORD	_native_sub118
		.BYTE	$0C		; SBCS
		.WORD	byte_6A59A
byte_6A598:
		.BYTE	$2A,$00
byte_6A59A:
		.BYTE	$08
byte_6A59B:
		.BYTE	$05
		.WORD	_native_sub154
		.BYTE	$29,$00		; OBJ_SET_X_DELTA
		.BYTE	$05		; NJSR
		.WORD	_native_get_obj_y_delta
		.BYTE	$10		; SBPL
		.WORD	byte_6A5A8
		.BYTE	$2A,$00		; OBJ_SET_Y_DELTA
byte_6A5A8:
		.BYTE	$07
		.WORD	byte_6A5BA
		.BYTE	$05		; NJSR
		.WORD	_native_sub027
		.BYTE	$0C		; SBCS
		.WORD	byte_6A5A8
		.BYTE	$05		; NJSR
		.WORD	_native_sub166
		.BYTE	$07		; SJSR
		.WORD	byte_6A5BA
		.BYTE	$06		; SJMP
		.WORD	byte_6A5A8
byte_6A5BA:
		.BYTE	$01
		.BYTE	$05		; NJSR
		.WORD	_native_get_obj_var0D
		.BYTE	$0D		; SBMI
		.WORD	byte_6A5C4
		.BYTE	$05		; NJSR
		.WORD	_native_sub028
byte_6A5C4:
		.BYTE	$08

; =============== S U B	R O U T	I N E =======================================
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
		JMP		_scr_flags_flush_ex

; =============== S U B	R O U T	I N E =======================================
_native_sub028:
		LDA		#$00
		STA		_obj_flips,X
		JMP		_native_sub033

; =============== S U B	R O U T	I N E =======================================
_native_sub029:
		LDA		_obj_vars0D,X
		AND		#$0F
		TAY
		LDA		_obj_flips,Y
		AND		#$40
		STA		_obj_flips,X
		JSR		_native_sub10F
		JMP		_native_sub167
_script46:
		.BYTE	$42
		.WORD	_script46
		.BYTE	$05		; NJSR
		.WORD	_native_sub134
		.BYTE	$05		; NJSR
		.WORD	_native_sub139
		.BYTE	$1D,$03		; SPR_LIB_SELECT
		.BYTE	$1E,$00		; SPR_IDX_SELECT
		.BYTE	$32,$06,$0F	; OBJ_SET_SIZE
		.BYTE	$34,$01		; OBJ_SET_HP
		.BYTE	$1B		; PARAM_80_CLEAR
byte_6A615:
		.BYTE	$05
		.WORD	_native_get_obj_var0D
		.BYTE	$0D		; SBMI
		.WORD	byte_6A630
		.BYTE	$05		; NJSR
		.WORD	_native_get_obj_hp
		.BYTE	$0B		; SBEQ
		.WORD	byte_6A627
		.BYTE	$05		; NJSR
		.WORD	_native_sub033
		.BYTE	$06		; SJMP
		.WORD	byte_6A669
byte_6A627:
		.BYTE	$05
		.WORD	_native_sub02B
		.BYTE	$03		; NJMP
		.WORD	_native_sub02E
		.BYTE	$06		; SJMP
		.WORD	byte_6A615
byte_6A630:
		.BYTE	$05
		.WORD	_native_sub13A
		.BYTE	$05		; NJSR
		.WORD	_native_sub12B
		.BYTE	$05		; NJSR
		.WORD	_native_sub02A
		.BYTE	$0B		; SBEQ
		.WORD	byte_6A653
		.BYTE	$17,$27		; APU_LOAD
		.BYTE	$05		; NJSR
		.WORD	_native_sub02F
		.BYTE	$2A,$F0		; OBJ_SET_Y_DELTA
byte_6A643:
		.BYTE	$1E,$00
		.BYTE	$05		; NJSR
		.WORD	_native_sub02E
		.BYTE	$18		; JMP_OBJ_ANIMATE
		.BYTE	$09,$08		; LOOPA
		.WORD	byte_6A643
		.BYTE	$05		; NJSR
		.WORD	_native_sub129
		.BYTE	$06		; SJMP
		.WORD	byte_6A643
byte_6A653:
		.BYTE	$1E,$00
		.BYTE	$17,$24		; APU_LOAD
		.BYTE	$05		; NJSR
		.WORD	_native_sub030
byte_6A65A:
		.BYTE	$18
		.BYTE	$05		; NJSR
		.WORD	_native_get_obj_hp
		.BYTE	$0D		; SBMI
		.WORD	byte_6A666
		.BYTE	$05		; NJSR
		.WORD	_native_sub105
		.BYTE	$34,$01		; OBJ_SET_HP
byte_6A666:
		.BYTE	$0B
		.WORD	byte_6A65A
byte_6A669:
		.BYTE	$03
		.WORD	_native_sub15E
		.BYTE	$1E,$03		; SPR_IDX_SELECT
		.BYTE	$01		; FLUSH
		.BYTE	$1E,$04		; SPR_IDX_SELECT
		.BYTE	$01		; FLUSH
		.BYTE	$1E,$05		; SPR_IDX_SELECT
		.BYTE	$01		; FLUSH
		.BYTE	$1E,$06		; SPR_IDX_SELECT
		.BYTE	$01		; FLUSH
		.BYTE	$1E,$07		; SPR_IDX_SELECT
		.BYTE	$01		; FLUSH
		.BYTE	$00		; STOP

; =============== S U B	R O U T	I N E =======================================
_native_sub02A:
		LDA		_scr_vars1C,X
		CMP		#$02
		JMP		_scr_flags_flush_ex

; =============== S U B	R O U T	I N E =======================================
_native_sub02B:
		JSR		_native_sub031
		JSR		_players_animB_sub0129_sub06_C
		BMI		_native_sub02C
		BEQ		_native_sub02C
		LDA		#$80
		STA		_scr_params,X
		RTS

; =============== S U B	R O U T	I N E =======================================
_native_sub02C:
		LDA		_obj_heigts,Y
		BEQ		_native_sub02D
		JSR		_native_sub13A
		JMP		_scr_param_4_set

; =============== S U B	R O U T	I N E =======================================
_native_sub02D:
		INC		_obj_y_lo_poss,X
		JSR		_native_sub166
		JMP		_scr_param_4_clear

; =============== S U B	R O U T	I N E =======================================
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

; =============== S U B	R O U T	I N E =======================================
_native_sub02F:
		LDA		_obj_vars0D,X
		AND		#$0F
		TAX
		JMP		loc_6A6E5

; =============== S U B	R O U T	I N E =======================================
_native_sub030:
		LDA		#$01
		STA		_scr_vars1C,X
		STA		_obj_hps,X
		LDA		_obj_vars0D,X
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

; =============== S U B	R O U T	I N E =======================================
_native_sub031:
		JSR		_native_get_obj_low_nibble_var0D
		LDA		_players_vars09,Y
		STA		_obj_spr_idxs,X
		RTS

; =============== S U B	R O U T	I N E =======================================
_native_sub032:
		JSR		_native_get_obj_low_nibble_var0D
		LDA		_obj_y_lo_poss,Y
		STA		_obj_y_lo_poss,X
		CLC
		SBC		_obj_heigts,X
		STA		_obj_y_lo_poss,Y

; =============== S U B	R O U T	I N E =======================================
_native_sub033:
		LDA		_obj_vars0D,X	; [code] used as data at a000
		AND		#$7F
		STA		_obj_vars0D,X
		JSR		_native_get_obj_low_nibble_var0D
		LDA		_obj_vars0D,Y
		AND		#$BF
		STA		_obj_vars0D,Y
		RTS
_script40:
		.BYTE	$1D,$00
		.BYTE	$1E,$0F		; SPR_IDX_SELECT
		.BYTE	$35,$0C		; OBJ_SET_FLIP
		.BYTE	$1B		; PARAM_80_CLEAR
byte_6A744:
		.BYTE	$29,$00
		.BYTE	$2A,$00		; OBJ_SET_Y_DELTA
		.BYTE	$07		; SJSR
		.WORD	byte_6A77C
		.BYTE	$29,$C0		; OBJ_SET_X_DELTA
		.BYTE	$2A,$00		; OBJ_SET_Y_DELTA
		.BYTE	$07		; SJSR
		.WORD	byte_6A77C
		.BYTE	$29,$A0		; OBJ_SET_X_DELTA
		.BYTE	$2A,$E0		; OBJ_SET_Y_DELTA
		.BYTE	$07		; SJSR
		.WORD	byte_6A77C
		.BYTE	$29,$C0		; OBJ_SET_X_DELTA
		.BYTE	$2A,$B0		; OBJ_SET_Y_DELTA
		.BYTE	$07		; SJSR
		.WORD	byte_6A77C
		.BYTE	$29,$00		; OBJ_SET_X_DELTA
		.BYTE	$2A,$B0		; OBJ_SET_Y_DELTA
		.BYTE	$07		; SJSR
		.WORD	byte_6A77C
		.BYTE	$29,$40		; OBJ_SET_X_DELTA
		.BYTE	$2A,$B0		; OBJ_SET_Y_DELTA
		.BYTE	$07		; SJSR
		.WORD	byte_6A77C
		.BYTE	$29,$60		; OBJ_SET_X_DELTA
		.BYTE	$2A,$E0		; OBJ_SET_Y_DELTA
		.BYTE	$07		; SJSR
		.WORD	byte_6A77C
		.BYTE	$29,$40		; OBJ_SET_X_DELTA
		.BYTE	$2A,$00		; OBJ_SET_Y_DELTA
		.BYTE	$06		; SJMP
		.WORD	byte_6A744
byte_6A77C:
		.BYTE	$05
		.WORD	_native_sub04A_A
		.BYTE	$18		; JMP_OBJ_ANIMATE
		.BYTE	$09,$04		; LOOPA
		.WORD	byte_6A77C
		.BYTE	$08		; RET
_obj_scr08:
		.BYTE	$05
		.WORD	_native_sub154
		.BYTE	$27,$08		; OBJ_MOVE_X_POS
		.BYTE	$1D,$05		; SPR_LIB_SELECT
		.BYTE	$1E,$00		; SPR_IDX_SELECT
		.BYTE	$32,$08,$07	; OBJ_SET_SIZE
		.BYTE	$34,$01		; OBJ_SET_HP
		.BYTE	$1B		; PARAM_80_CLEAR
		.BYTE	$07		; SJSR
		.WORD	_script20D
		.BYTE	$1E,$01		; SPR_IDX_SELECT
		.BYTE	$32,$08,$04	; OBJ_SET_SIZE
		.BYTE	$05		; NJSR
		.WORD	_native_sub169
		.BYTE	$07		; SJSR
		.WORD	_script20D
		.BYTE	$1E,$02		; SPR_IDX_SELECT
		.BYTE	$32,$08,$02	; OBJ_SET_SIZE
		.BYTE	$05		; NJSR
		.WORD	_native_sub169
		.BYTE	$07		; SJSR
		.WORD	_script20D
		.BYTE	$1E,$03		; SPR_IDX_SELECT
		.BYTE	$32,$08,$0F	; OBJ_SET_SIZE
		.BYTE	$05		; NJSR
		.WORD	_native_sub169
		.BYTE	$17,$4A		; APU_LOAD
		.BYTE	$29,$10		; OBJ_SET_X_DELTA
		.BYTE	$2A,$C0		; OBJ_SET_Y_DELTA
byte_6A7BB:
		.BYTE	$18
		.BYTE	$05		; NJSR
		.WORD	_native_sub109
		.BYTE	$05		; NJSR
		.WORD	_native_sub162
		.BYTE	$0C		; SBCS
		.WORD	byte_6A7BB
		.BYTE	$05		; NJSR
		.WORD	_native_sub169
		.BYTE	$06		; SJMP
		.WORD	byte_6A7BB
_obj_scr0A:
		.BYTE	$07
		.WORD	byte_6A7F1
		.BYTE	$07		; SJSR
		.WORD	byte_6A7FF
		.BYTE	$04,$01		; RUN
		.WORD	_script139
byte_6A7D5:
		.BYTE	$07
		.WORD	byte_6A812
		.BYTE	$07		; SJSR
		.WORD	byte_6A7FF
		.BYTE	$06		; SJMP
		.WORD	byte_6A7D5
_script139:
		.BYTE	$13,$34
		.WORD	_tmp_ptr4B
		.BYTE	$13,$9E		; MOV
		.WORD	_tmp_ptr4B+1
		.BYTE	$07		; SJSR
		.WORD	_script20C
		.BYTE	$17,$4E		; APU_LOAD
		.BYTE	$02,$08		; DELAY
		.BYTE	$07		; SJSR
		.WORD	_script20C
		.BYTE	$00		; STOP
byte_6A7F1:
		.BYTE	$05
		.WORD	_native_sub154
		.BYTE	$1D,$05		; SPR_LIB_SELECT
		.BYTE	$1E,$0C		; SPR_IDX_SELECT
		.BYTE	$32,$05,$0D	; OBJ_SET_SIZE
		.BYTE	$34,$01		; OBJ_SET_HP
		.BYTE	$1B		; PARAM_80_CLEAR
		.BYTE	$08		; RET
byte_6A7FF:
		.BYTE	$01
		.BYTE	$05		; NJSR
		.WORD	_native_sub162
		.BYTE	$0C		; SBCS
		.WORD	byte_6A7FF
		.BYTE	$1E,$0D		; SPR_IDX_SELECT
		.BYTE	$32,$05,$08	; OBJ_SET_SIZE
		.BYTE	$05		; NJSR
		.WORD	_native_sub169
		.BYTE	$05		; NJSR
		.WORD	_native_sub139
		.BYTE	$08		; RET
byte_6A812:
		.BYTE	$01
		.BYTE	$05		; NJSR
		.WORD	_native_sub162
		.BYTE	$0F		; SBCC
		.WORD	byte_6A812
byte_6A819:
		.BYTE	$05
		.WORD	_native_sub16A
		.BYTE	$02,$08		; DELAY
		.BYTE	$1E,$0E		; SPR_IDX_SELECT
		.BYTE	$32,$05,$0A	; OBJ_SET_SIZE
		.BYTE	$05		; NJSR
		.WORD	_native_sub162
		.BYTE	$0C		; SBCS
		.WORD	byte_6A82D
		.BYTE	$05		; NJSR
		.WORD	_native_sub169
		.BYTE	$08		; RET
byte_6A82D:
		.BYTE	$02,$04
		.BYTE	$1E,$0C		; SPR_IDX_SELECT
		.BYTE	$32,$05,$0D	; OBJ_SET_SIZE
		.BYTE	$05		; NJSR
		.WORD	_native_sub162
		.BYTE	$0C		; SBCS
		.WORD	byte_6A83D
		.BYTE	$05		; NJSR
		.WORD	_native_sub169
byte_6A83D:
		.BYTE	$08
_obj_scr0B:
		.BYTE	$07
		.WORD	byte_6A7F1
		.BYTE	$04,$09		; RUN
		.WORD	_script13A
		.BYTE	$05		; NJSR
		.WORD	_native_sub117
		.BYTE	$05		; NJSR
		.WORD	_native_sub134
		.BYTE	$27,$50		; OBJ_MOVE_X_POS
byte_6A84D:
		.BYTE	$07
		.WORD	byte_6A7FF
byte_6A850:
		.BYTE	$05
		.WORD	_native_sub14C
		.BYTE	$0B		; SBEQ
		.WORD	byte_6A863
		.BYTE	$05		; NJSR
		.WORD	_native_sub162
		.BYTE	$01		; FLUSH
		.BYTE	$0F		; SBCC
		.WORD	byte_6A850
		.BYTE	$07		; SJSR
		.WORD	byte_6A819
		.BYTE	$06		; SJMP
		.WORD	byte_6A84D
byte_6A863:
		.BYTE	$13,$42
		.WORD	_tmp_ptr4B
		.BYTE	$13,$9E		; MOV
		.WORD	_tmp_ptr4B+1
		.BYTE	$07		; SJSR
		.WORD	_script20C
		.BYTE	$04,$0A		; RUN
		.WORD	_script13B
		.BYTE	$17,$4F		; APU_LOAD
byte_6A874:
		.BYTE	$07
		.WORD	byte_6A812
		.BYTE	$07		; SJSR
		.WORD	byte_6A7FF
		.BYTE	$06		; SJMP
		.WORD	byte_6A874
_script13B:
		.BYTE	$27,$D0
		.BYTE	$06		; SJMP
		.WORD	byte_6A189
_script13A:
		.BYTE	$07
		.WORD	byte_6A7F1
		.BYTE	$05		; NJSR
		.WORD	_native_sub134
byte_6A888:
		.BYTE	$07
		.WORD	byte_6A7FF
		.BYTE	$07		; SJSR
		.WORD	byte_6A812
		.BYTE	$06		; SJMP
		.WORD	byte_6A888
_obj_scr0C:
		.BYTE	$07
		.WORD	byte_6A7F1
		.BYTE	$07		; SJSR
		.WORD	byte_6A7FF
		.BYTE	$13,$4F		; MOV
		.WORD	_tmp_ptr4B
		.BYTE	$13,$9E		; MOV
		.WORD	_tmp_ptr4B+1
		.BYTE	$07		; SJSR
		.WORD	_script20C
		.BYTE	$04,$0A		; RUN
		.WORD	_script13C
		.BYTE	$17,$4F		; APU_LOAD
byte_6A8A8:
		.BYTE	$07
		.WORD	byte_6A812
		.BYTE	$07		; SJSR
		.WORD	byte_6A7FF
		.BYTE	$06		; SJMP
		.WORD	byte_6A8A8
_script13C:
		.BYTE	$27,$C0
		.BYTE	$27,$B0		; OBJ_MOVE_X_POS
		.BYTE	$06		; SJMP
		.WORD	_obj_scr22
_obj_scr0D:
		.BYTE	$07
		.WORD	_script202
byte_6A8BB:
		.BYTE	$04,$01
		.WORD	_script13D
		.BYTE	$02,$5A		; DELAY
		.BYTE	$04,$01		; RUN
		.WORD	_script13E
		.BYTE	$02,$5A		; DELAY
		.BYTE	$06		; SJMP
		.WORD	byte_6A8BB
_script13D:
		.BYTE	$27,$E0
_script13E:
		.BYTE	$43
		.BYTE	$27,$10		; OBJ_MOVE_X_POS
		.BYTE	$1D,$05		; SPR_LIB_SELECT
		.BYTE	$1B		; PARAM_80_CLEAR
		.BYTE	$2A,$E0		; OBJ_SET_Y_DELTA
		.BYTE	$05		; NJSR
		.WORD	_native_sub12B
		.BYTE	$05		; NJSR
		.WORD	_native_sub13D
		.BYTE	$0F		; SBCC
		.WORD	byte_6A8EC
byte_6A8DD:
		.BYTE	$1E,$12
		.BYTE	$2E		; OBJ_DEC_Y_DELTA
		.BYTE	$18		; JMP_OBJ_ANIMATE
		.BYTE	$18		; JMP_OBJ_ANIMATE
		.BYTE	$18		; JMP_OBJ_ANIMATE
		.BYTE	$1E,$1A		; SPR_IDX_SELECT
		.BYTE	$2E		; OBJ_DEC_Y_DELTA
		.BYTE	$18		; JMP_OBJ_ANIMATE
		.BYTE	$18		; JMP_OBJ_ANIMATE
		.BYTE	$18		; JMP_OBJ_ANIMATE
		.BYTE	$06		; SJMP
		.WORD	byte_6A8DD
byte_6A8EC:
		.BYTE	$00
_obj_scr0E:
		.BYTE	$05
		.WORD	_native_sub16B
		.BYTE	$0B		; SBEQ
		.WORD	byte_6A8FD
byte_6A8F3:
		.BYTE	$05
		.WORD	_native_sub157
		.BYTE	$09,$05		; LOOPA
		.WORD	byte_6A8F3
		.BYTE	$05		; NJSR
		.WORD	_MAIN_START
byte_6A8FD:
		.BYTE	$05
		.WORD	_native_sub14A
		.BYTE	$25,$38,$00	; OBJ_SET_X_POS
byte_6A903:
		.BYTE	$05
		.WORD	_native_sub034
		.BYTE	$04,$09		; RUN
		.WORD	_script13F
		.BYTE	$09,$03		; LOOPA
		.WORD	byte_6A903
		.BYTE	$05		; NJSR
		.WORD	_native_sub150
		.BYTE	$05		; NJSR
		.WORD	_native_sub14A
		.BYTE	$25,$C8,$00	; OBJ_SET_X_POS
byte_6A917:
		.BYTE	$05
		.WORD	_native_sub034
		.BYTE	$04,$09		; RUN
		.WORD	_script13F
		.BYTE	$09,$03		; LOOPA
		.WORD	byte_6A917
		.BYTE	$05		; NJSR
		.WORD	_native_sub14B
byte_6A925:
		.BYTE	$03
		.WORD	_native_sub035
		.BYTE	$0E		; SBNE
		.WORD	byte_6A925
		.BYTE	$13,$5F		; MOV
		.WORD	_tmp_ptr4B
		.BYTE	$13,$9E		; MOV
		.WORD	_tmp_ptr4B+1
		.BYTE	$07		; SJSR
		.WORD	_script20C
		.BYTE	$05		; NJSR
		.WORD	_native_sub16C
		.BYTE	$25,$F0,$00	; OBJ_SET_X_POS
		.BYTE	$26,$C0,$00	; OBJ_SET_Y_POS
		.BYTE	$1C		; PARAM_80_SET
		.BYTE	$17,$23		; APU_LOAD
		.BYTE	$06		; SJMP
		.WORD	_obj_scr21

; =============== S U B	R O U T	I N E =======================================
_native_sub034:
		JSR		_native_sub143	; FLIP_40_SET
		LDY		_tmp_ptrE+1
		LDA		byte_6A951,Y
		STA		_obj_y_lo_poss,X
		RTS
byte_6A951:
		.BYTE	$40,$80,$C0

; =============== S U B	R O U T	I N E =======================================
_native_sub035:
		LDY		_obj_vars0D,X
		LDA		_obj_vars0D,Y
		LDY		_scr_vars1E,X
		AND		_obj_vars0D,Y
		AND		#$10
		JMP		_scr_flags_flush_ex
_script13F:
		.BYTE	$05
		.WORD	_native_sub154
		.BYTE	$1D,$05		; SPR_LIB_SELECT
		.BYTE	$1E,$14		; SPR_IDX_SELECT
		.BYTE	$32,$05,$0C	; OBJ_SET_SIZE
		.BYTE	$34,$01		; OBJ_SET_HP
		.BYTE	$1B		; PARAM_80_CLEAR
byte_6A972:
		.BYTE	$01
		.BYTE	$05		; NJSR
		.WORD	_native_sub162
		.BYTE	$0C		; SBCS
		.WORD	byte_6A972
		.BYTE	$1E,$15		; SPR_IDX_SELECT
		.BYTE	$32,$05,$06	; OBJ_SET_SIZE
		.BYTE	$05		; NJSR
		.WORD	_native_sub169
		.BYTE	$05		; NJSR
		.WORD	_native_sub139
byte_6A984:
		.BYTE	$01
		.BYTE	$05		; NJSR
		.WORD	_native_sub162
		.BYTE	$0F		; SBCC
		.WORD	byte_6A984
		.BYTE	$05		; NJSR
		.WORD	_native_sub16A
		.BYTE	$02,$08		; DELAY
		.BYTE	$1E,$16		; SPR_IDX_SELECT
		.BYTE	$32,$05,$08	; OBJ_SET_SIZE
		.BYTE	$05		; NJSR
		.WORD	_native_sub162
		.BYTE	$0C		; SBCS
		.WORD	byte_6A99E
		.BYTE	$05		; NJSR
		.WORD	_native_sub169
byte_6A99E:
		.BYTE	$02,$04
		.BYTE	$1E,$14		; SPR_IDX_SELECT
		.BYTE	$32,$05,$0C	; OBJ_SET_SIZE
		.BYTE	$05		; NJSR
		.WORD	_native_sub162
		.BYTE	$0C		; SBCS
		.WORD	byte_6A9AE
		.BYTE	$05		; NJSR
		.WORD	_native_sub169
byte_6A9AE:
		.BYTE	$06
		.WORD	byte_6A972
_obj_scr0F:
		.BYTE	$27,$FD
		.BYTE	$28,$03		; OBJ_MOVE_Y_POS
		.BYTE	$31,$20		; TARGET_DIR_SET
		.BYTE	$07		; SJSR
		.WORD	byte_6AA22
byte_6A9BA:
		.BYTE	$07
		.WORD	byte_6AA11
byte_6A9BD:
		.BYTE	$07
		.WORD	byte_6AA31
		.BYTE	$09,$84		; LOOPA
		.WORD	byte_6A9BD
		.BYTE	$07		; SJSR
		.WORD	byte_6AA11
byte_6A9C7:
		.BYTE	$07
		.WORD	byte_6AA31
		.BYTE	$09,$84		; LOOPA
		.WORD	byte_6A9C7
		.BYTE	$06		; SJMP
		.WORD	byte_6A9BA
_obj_scr10:
		.BYTE	$27,$03
		.BYTE	$28,$05		; OBJ_MOVE_Y_POS
		.BYTE	$31,$00		; TARGET_DIR_SET
		.BYTE	$07		; SJSR
		.WORD	byte_6AA22
byte_6A9DA:
		.BYTE	$07
		.WORD	byte_6AA11
byte_6A9DD:
		.BYTE	$07
		.WORD	byte_6AA31
		.BYTE	$09,$84		; LOOPA
		.WORD	byte_6A9DD
		.BYTE	$07		; SJSR
		.WORD	byte_6AA11
byte_6A9E7:
		.BYTE	$07
		.WORD	byte_6AA31
		.BYTE	$09,$84		; LOOPA
		.WORD	byte_6A9E7
		.BYTE	$06		; SJMP
		.WORD	byte_6A9DA
_obj_scr11:
		.BYTE	$27,$03
		.BYTE	$28,$05		; OBJ_MOVE_Y_POS
		.BYTE	$31,$00		; TARGET_DIR_SET
		.BYTE	$07		; SJSR
		.WORD	byte_6AA22
byte_6A9FA:
		.BYTE	$07
		.WORD	byte_6AA11
byte_6A9FD:
		.BYTE	$07
		.WORD	byte_6AA31
		.BYTE	$09,$58		; LOOPA
		.WORD	byte_6A9FD
		.BYTE	$07		; SJSR
		.WORD	byte_6AA11
byte_6AA07:
		.BYTE	$07
		.WORD	byte_6AA31
		.BYTE	$09,$58		; LOOPA
		.WORD	byte_6AA07
		.BYTE	$06		; SJMP
		.WORD	byte_6A9FA
byte_6AA11:
		.BYTE	$05
		.WORD	_native_sub123
		.BYTE	$05		; NJSR
		.WORD	_native_sub124
		.BYTE	$05		; NJSR
		.WORD	_native_sub126
		.BYTE	$07		; SJSR
		.WORD	byte_6AA31
		.BYTE	$09,$40		; LOOPA
		.WORD	byte_6AA11
		.BYTE	$08		; RET
byte_6AA22:
		.BYTE	$05
		.WORD	_native_sub154
		.BYTE	$1D,$05		; SPR_LIB_SELECT
		.BYTE	$1E,$13		; SPR_IDX_SELECT
		.BYTE	$32,$10,$0E	; OBJ_SET_SIZE
		.BYTE	$34,$01		; OBJ_SET_HP
		.BYTE	$06		; SJMP
		.WORD	_script201
byte_6AA31:
		.BYTE	$01
		.BYTE	$19		; JSR_OBJ_ANIMATE
		.BYTE	$05		; NJSR
		.WORD	_native_sub16D
		.BYTE	$05		; NJSR
		.WORD	_native_sub163
		.BYTE	$08		; RET
_obj_scr05:
		.BYTE	$27,$08
		.BYTE	$1D,$05		; SPR_LIB_SELECT
		.BYTE	$1E,$46		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	_script201
byte_6AA43:
		.BYTE	$02,$10
		.BYTE	$1E,$47		; SPR_IDX_SELECT
		.BYTE	$02,$10		; DELAY
byte_6AA49:
		.BYTE	$1E,$46		; SPR_IDX_SELECT
		.BYTE	$17,$50		; APU_LOAD
		.BYTE	$06		; SJMP
		.WORD	byte_6AA43
_obj_scr06:
		.BYTE	$05
		.WORD	_scr_param_4_set
		.BYTE	$05		; NJSR
		.WORD	_native_sub134
byte_6AA56:
		.BYTE	$07
		.WORD	byte_6AA67
		.BYTE	$13,$05		; MOV
		.WORD	_pal_anim_mode_idx
		.BYTE	$07		; SJSR
		.WORD	byte_6AA67
		.BYTE	$13,$07		; MOV
		.WORD	_pal_anim_mode_idx
		.BYTE	$06		; SJMP
		.WORD	byte_6AA56
byte_6AA67:
		.BYTE	$02,$F0
		.BYTE	$02,$F0		; DELAY
		.BYTE	$17,$35		; APU_LOAD
		.BYTE	$08		; RET
_obj_scr3E:
		.BYTE	$27,$F8
		.BYTE	$28,$FC		; OBJ_MOVE_Y_POS
		.BYTE	$07		; SJSR
		.WORD	_script202
byte_6AA75:
		.BYTE	$03
		.WORD	_native_sub036
		.BYTE	$0E		; SBNE
		.WORD	byte_6AA75
byte_6AA7B:
		.BYTE	$03
		.WORD	_native_sub036
		.BYTE	$0B		; SBEQ
		.WORD	byte_6AA7B
		.BYTE	$04,$06		; RUN
		.WORD	_script140
		.BYTE	$06		; SJMP
		.WORD	byte_6AA75

; =============== S U B	R O U T	I N E =======================================
_native_sub036:
		LDA		_pal_anim_mode_idx
		CMP		#$05
		JMP		_scr_flags_flush_ex
_script140:
		.BYTE	$1D,$07
		.BYTE	$1B		; PARAM_80_CLEAR
		.BYTE	$2F,$20		; TARGET_LOCK
		.BYTE	$32,$0C,$14	; OBJ_SET_SIZE
byte_6AA97:
		.BYTE	$34,$7F
		.BYTE	$33,$01		; VAR_1C_SET
		.BYTE	$31,$00		; TARGET_DIR_SET
		.BYTE	$07		; SJSR
		.WORD	byte_6AAC1
		.BYTE	$09,$14		; LOOPA
		.WORD	byte_6AA97
		.BYTE	$05		; NJSR
		.WORD	_native_sub10E
		.BYTE	$05		; NJSR
		.WORD	_native_sub111
		.BYTE	$17,$36		; APU_LOAD
byte_6AAAC:
		.BYTE	$31,$FF
		.BYTE	$07		; SJSR
		.WORD	byte_6AAC1
		.BYTE	$09,$14		; LOOPA
		.WORD	byte_6AAAC
		.BYTE	$0A,$03		; LOOPB
		.WORD	byte_6AA97
byte_6AAB9:
		.BYTE	$31,$FF
		.BYTE	$07		; SJSR
		.WORD	byte_6AAC1
		.BYTE	$06		; SJMP
		.WORD	byte_6AAB9
byte_6AAC1:
		.BYTE	$1E,$5A
		.BYTE	$07		; SJSR
		.WORD	byte_6AACE
		.BYTE	$07		; SJSR
		.WORD	byte_6AACE
		.BYTE	$1E,$5B		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	byte_6AACE
byte_6AACE:
		.BYTE	$05
		.WORD	_scr_param_4_clear
		.BYTE	$1A		; TARGET_FOLLOW
		.BYTE	$01		; FLUSH
		.BYTE	$08		; RET
_obj_scr12:
		.BYTE	$05
		.WORD	_native_sub154
		.BYTE	$28,$EC		; OBJ_MOVE_Y_POS
		.BYTE	$04,$01		; RUN
		.WORD	_script141
		.BYTE	$05		; NJSR
		.WORD	_native_sub117
		.BYTE	$34,$01		; OBJ_SET_HP
		.BYTE	$32,$16,$01	; OBJ_SET_SIZE
		.BYTE	$1D,$05		; SPR_LIB_SELECT
		.BYTE	$1E,$33		; SPR_IDX_SELECT
		.BYTE	$1B		; PARAM_80_CLEAR
byte_6AAEA:
		.BYTE	$1E,$33
		.BYTE	$07		; SJSR
		.WORD	byte_6AAFD
		.BYTE	$05		; NJSR
		.WORD	_native_get_obj_x_delta
		.BYTE	$0E		; SBNE
		.WORD	byte_6AAEA
		.BYTE	$1E,$34		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	byte_6AAFD
		.BYTE	$06		; SJMP
		.WORD	byte_6AAEA
byte_6AAFD:
		.BYTE	$01
		.BYTE	$05		; NJSR
		.WORD	_native_sub038
		.BYTE	$0E		; SBNE
		.WORD	byte_6AB0A
		.BYTE	$05		; NJSR
		.WORD	_native_sub109
		.BYTE	$06		; SJMP
		.WORD	byte_6AB0F
byte_6AB0A:
		.BYTE	$2A,$00
		.BYTE	$05		; NJSR
		.WORD	_native_sub037
byte_6AB0F:
		.BYTE	$19
		.BYTE	$05		; NJSR
		.WORD	_native_sub16D
		.BYTE	$09,$04		; LOOPA
		.WORD	byte_6AAFD
		.BYTE	$08		; RET

; =============== S U B	R O U T	I N E =======================================
_native_sub037:
		LDA		_obj_y_lo_poss,X
		AND		#$F0
		ORA		#$0C
		STA		_obj_y_lo_poss,X
		RTS

; =============== S U B	R O U T	I N E =======================================
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
		JMP		_scr_flags_flush_ex
_script141:
		.BYTE	$35,$08
		.BYTE	$05		; NJSR
		.WORD	_native_sub134
		.BYTE	$34,$01		; OBJ_SET_HP
		.BYTE	$32,$01,$08	; OBJ_SET_SIZE
byte_6AB55:
		.BYTE	$1D,$01
		.BYTE	$1E,$12		; SPR_IDX_SELECT
		.BYTE	$1B		; PARAM_80_CLEAR
byte_6AB5A:
		.BYTE	$07
		.WORD	byte_6ABA9
		.BYTE	$05		; NJSR
		.WORD	_native_sub03D
		.BYTE	$0C		; SBCS
		.WORD	byte_6AB5A
		.BYTE	$1E,$13		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	byte_6AB98
byte_6AB68:
		.BYTE	$07
		.WORD	byte_6ABA9
		.BYTE	$05		; NJSR
		.WORD	_native_sub03E
		.BYTE	$0C		; SBCS
		.WORD	byte_6AB77
		.BYTE	$05		; NJSR
		.WORD	_native_sub03B
		.BYTE	$06		; SJMP
		.WORD	byte_6AB55
byte_6AB77:
		.BYTE	$05
		.WORD	_native_sub03C
		.BYTE	$0E		; SBNE
		.WORD	byte_6AB90
		.BYTE	$0C		; SBCS
		.WORD	byte_6AB88
		.BYTE	$1E,$14		; SPR_IDX_SELECT
		.BYTE	$05		; NJSR
		.WORD	_native_sub039
		.BYTE	$06		; SJMP
		.WORD	byte_6AB68
byte_6AB88:
		.BYTE	$1E,$15
		.BYTE	$05		; NJSR
		.WORD	_native_sub03B
		.BYTE	$06		; SJMP
		.WORD	byte_6AB68
byte_6AB90:
		.BYTE	$1E,$13
		.BYTE	$05		; NJSR
		.WORD	_native_sub03A
		.BYTE	$06		; SJMP
		.WORD	byte_6AB68
byte_6AB98:
		.BYTE	$07
		.WORD	byte_6ABA9
		.BYTE	$05		; NJSR
		.WORD	_native_sub03E
		.BYTE	$0F		; SBCC
		.WORD	byte_6ABA6
		.BYTE	$09,$08		; LOOPA
		.WORD	byte_6AB98
		.BYTE	$08		; RET
byte_6ABA6:
		.BYTE	$41
		.WORD	byte_6AB55
byte_6ABA9:
		.BYTE	$05
		.WORD	_native_sub04A_A
		.BYTE	$27,$06		; OBJ_MOVE_X_POS
		.BYTE	$01		; FLUSH
		.BYTE	$08		; RET

; =============== S U B	R O U T	I N E =======================================
_native_sub039:
		LDA		#$30
		BNE		_native_sub03B_ex

; =============== S U B	R O U T	I N E =======================================
_native_sub03A:
		LDA		#$20
		BNE		_native_sub03B_ex

; =============== S U B	R O U T	I N E =======================================
_native_sub03B:
		LDA		#$10

; =============== S U B	R O U T	I N E =======================================
_native_sub03B_ex:
		PHA
		JSR		_native_get_obj_low_nibble_var1E
		PLA
		STA		_obj_x_deltas,Y
		RTS

; =============== S U B	R O U T	I N E =======================================
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
		JMP		_scr_flags_flush_ex

; =============== S U B	R O U T	I N E =======================================
_native_sub03D:
		LDY		#$01
loc_6ABDA:
		LDA		_obj_flips,Y
		AND		#$04
		BNE		loc_6AC1F
		LDA		_players_vars0D,Y
		BNE		loc_6AC1F
		LDA		_obj_vars0D,Y
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
		JMP		_scr_flags_flush_ex
loc_6AC1F:
		DEY
		BPL		loc_6ABDA
		CLC
		JMP		_scr_flags_flush_ex

; =============== S U B	R O U T	I N E =======================================
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
		JMP		_scr_flags_flush_ex

; =============== S U B	R O U T	I N E =======================================
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
_obj_scr13:
		.BYTE	$05
		.WORD	_native_sub13E
		.BYTE	$05		; NJSR
		.WORD	_native_sub154
		.BYTE	$34,$01		; OBJ_SET_HP
		.BYTE	$33,$01		; VAR_1C_SET
		.BYTE	$32,$09,$12	; OBJ_SET_SIZE
		.BYTE	$1D,$05		; SPR_LIB_SELECT
		.BYTE	$1E,$38		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	_script201
byte_6AC8A:
		.BYTE	$03
		.WORD	_native_sub116
		.BYTE	$0F		; SBCC
		.WORD	byte_6AC8A
		.BYTE	$2A,$18		; OBJ_SET_Y_DELTA
		.BYTE	$17,$71		; APU_LOAD
		.BYTE	$06		; SJMP
		.WORD	byte_68096
_obj_scr04:
		.BYTE	$1D,$05
		.BYTE	$1E,$45		; SPR_IDX_SELECT
		.BYTE	$1B		; PARAM_80_CLEAR
		.BYTE	$04,$07		; RUN
		.WORD	_script142
		.BYTE	$05		; NJSR
		.WORD	_native_sub117
byte_6ACA3:
		.BYTE	$17,$5E
		.BYTE	$1E,$45		; SPR_IDX_SELECT
		.BYTE	$02,$08		; DELAY
		.BYTE	$1E,$44		; SPR_IDX_SELECT
		.BYTE	$02,$09		; DELAY
		.BYTE	$1E,$43		; SPR_IDX_SELECT
		.BYTE	$02,$0B		; DELAY
		.BYTE	$1E,$42		; SPR_IDX_SELECT
		.BYTE	$02,$0E		; DELAY
		.BYTE	$1E,$43		; SPR_IDX_SELECT
		.BYTE	$02,$0B		; DELAY
		.BYTE	$1E,$44		; SPR_IDX_SELECT
		.BYTE	$02,$09		; DELAY
		.BYTE	$23		; FLIP_40_TOGGLE
		.BYTE	$06		; SJMP
		.WORD	byte_6ACA3
_script142:
		.BYTE	$05
		.WORD	_native_sub134
		.BYTE	$32,$06,$0C	; OBJ_SET_SIZE
		.BYTE	$34,$01		; OBJ_SET_HP
		.BYTE	$33,$01		; VAR_1C_SET
		.BYTE	$1D,$05		; SPR_LIB_SELECT
		.BYTE	$1E,$41		; SPR_IDX_SELECT
		.BYTE	$1B		; PARAM_80_CLEAR
byte_6ACD0:
		.BYTE	$03
		.WORD	_native_sub03F
		.BYTE	$06		; SJMP
		.WORD	byte_6ACD0

; =============== S U B	R O U T	I N E =======================================
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
_obj_scr16:
		.BYTE	$05
		.WORD	_native_sub154
		.BYTE	$34,$01		; OBJ_SET_HP
		.BYTE	$32,$05,$08	; OBJ_SET_SIZE
		.BYTE	$1D,$05		; SPR_LIB_SELECT
		.BYTE	$1B		; PARAM_80_CLEAR
		.BYTE	$05		; NJSR
		.WORD	_native_sub040
		.BYTE	$0E		; SBNE
		.WORD	byte_6AD4F
		.BYTE	$06		; SJMP
		.WORD	byte_6AD5C
byte_6AD40:
		.BYTE	$03
		.WORD	_native_sub041
		.BYTE	$0C		; SBCS
		.WORD	byte_6AD40
		.BYTE	$05		; NJSR
		.WORD	_native_sub040
		.BYTE	$0B		; SBEQ
		.WORD	byte_6AD4F
		.BYTE	$06		; SJMP
		.WORD	byte_6AD5C
byte_6AD4F:
		.BYTE	$1E,$2B
		.BYTE	$13,$0C		; MOV
		.WORD	_pal_anim_mode_idx
		.BYTE	$13,$04		; MOV
		.WORD	byte_7F
		.BYTE	$06		; SJMP
		.WORD	byte_6AD40
byte_6AD5C:
		.BYTE	$1E,$2C
		.BYTE	$13,$0E		; MOV
		.WORD	_pal_anim_mode_idx
		.BYTE	$13,$05		; MOV
		.WORD	byte_7F
		.BYTE	$06		; SJMP
		.WORD	byte_6AD40

; =============== S U B	R O U T	I N E =======================================
_native_sub040:
		LDA		byte_7F
		CMP		#$04
		JMP		_scr_flags_flush_ex

; =============== S U B	R O U T	I N E =======================================
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
		LDA		_obj_vars0D,Y
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
_obj_scr14:
		.BYTE	$05
		.WORD	_native_sub154
		.BYTE	$27,$08		; OBJ_MOVE_X_POS
		.BYTE	$35,$20		; OBJ_SET_FLIP
		.BYTE	$1D,$05		; SPR_LIB_SELECT
		.BYTE	$1E,$04		; SPR_IDX_SELECT
		.BYTE	$34,$01		; OBJ_SET_HP
		.BYTE	$1B		; PARAM_80_CLEAR
		.BYTE	$32,$10,$0F	; OBJ_SET_SIZE
		.BYTE	$07		; SJSR
		.WORD	_script201
byte_6ADB5:
		.BYTE	$2A,$F0
byte_6ADB7:
		.BYTE	$07
		.WORD	byte_6ADDD
		.BYTE	$09,$16		; LOOPA
		.WORD	byte_6ADB7
byte_6ADBE:
		.BYTE	$03
		.WORD	_obj_vert_animate
		.BYTE	$09,$0A		; LOOPA
		.WORD	byte_6ADBE
		.BYTE	$02,$78		; DELAY
		.BYTE	$2A,$40		; OBJ_SET_Y_DELTA
		.BYTE	$03		; NJMP
		.WORD	_obj_vert_animate
		.BYTE	$03		; NJMP
		.WORD	_obj_vert_animate
byte_6ADCF:
		.BYTE	$07
		.WORD	byte_6ADDD
		.BYTE	$09,$06		; LOOPA
		.WORD	byte_6ADCF
		.BYTE	$17,$51		; APU_LOAD
		.BYTE	$02,$78		; DELAY
		.BYTE	$06		; SJMP
		.WORD	byte_6ADB5
byte_6ADDD:
		.BYTE	$01
		.BYTE	$05		; NJSR
		.WORD	_obj_vert_animate
		.BYTE	$05		; NJSR
		.WORD	_native_sub16E
		.BYTE	$0F		; SBCC
		.WORD	byte_6ADEA
		.BYTE	$05		; NJSR
		.WORD	_native_sub042
byte_6ADEA:
		.BYTE	$08

; =============== S U B	R O U T	I N E =======================================
_native_sub042:
		LDY		byte_AB
		LDA		_obj_flips,Y
		AND		#$04
		BNE		locret_6ADF7
		JMP		_player_kill
locret_6ADF7:
		RTS
_obj_scr15:
		.BYTE	$05
		.WORD	_native_sub154
		.BYTE	$1D,$05		; SPR_LIB_SELECT
		.BYTE	$34,$01		; OBJ_SET_HP
		.BYTE	$1B		; PARAM_80_CLEAR
byte_6AE00:
		.BYTE	$1E,$2E
		.BYTE	$32,$10,$0F	; OBJ_SET_SIZE
byte_6AE05:
		.BYTE	$03
		.WORD	_native_sub162
		.BYTE	$0C		; SBCS
		.WORD	byte_6AE05
		.BYTE	$1E,$39		; SPR_IDX_SELECT
		.BYTE	$02,$78		; DELAY
		.BYTE	$32,$00,$00	; OBJ_SET_SIZE
		.BYTE	$1E,$22		; SPR_IDX_SELECT
		.BYTE	$02,$08		; DELAY
		.BYTE	$1E,$23		; SPR_IDX_SELECT
		.BYTE	$02,$1E		; DELAY
		.BYTE	$1E,$22		; SPR_IDX_SELECT
		.BYTE	$02,$04		; DELAY
		.BYTE	$1E,$39		; SPR_IDX_SELECT
		.BYTE	$02,$04		; DELAY
		.BYTE	$06		; SJMP
		.WORD	byte_6AE00
_obj_scr3B:
		.BYTE	$27,$08
		.BYTE	$1D,$05		; SPR_LIB_SELECT
		.BYTE	$32,$02,$30	; OBJ_SET_SIZE
byte_6AE2C:
		.BYTE	$1B
byte_6AE2D:
		.BYTE	$17,$53
		.BYTE	$1E,$29		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	byte_6AE46
		.BYTE	$1E,$2A		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	byte_6AE46
		.BYTE	$09,$1E		; LOOPA
		.WORD	byte_6AE2D
		.BYTE	$1C		; PARAM_80_SET
		.BYTE	$05		; NJSR
		.WORD	_scr_param_4_set
		.BYTE	$02,$78		; DELAY
		.BYTE	$06		; SJMP
		.WORD	byte_6AE2C
byte_6AE46:
		.BYTE	$34,$01
		.BYTE	$33,$01		; VAR_1C_SET
		.BYTE	$03		; NJMP
		.WORD	_scr_param_4_clear
		.BYTE	$0A,$02		; LOOPB
		.WORD	byte_6AE46
		.BYTE	$08		; RET
_obj_scr17:
		.BYTE	$05
		.WORD	_native_sub154
		.BYTE	$1D,$05		; SPR_LIB_SELECT
		.BYTE	$1E,$2D		; SPR_IDX_SELECT
		.BYTE	$32,$08,$10	; OBJ_SET_SIZE
		.BYTE	$07		; SJSR
		.WORD	_script201
byte_6AE5F:
		.BYTE	$03
		.WORD	_native_sub043
		.BYTE	$06		; SJMP
		.WORD	byte_6AE5F

; =============== S U B	R O U T	I N E =======================================
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
_obj_scr18:
		.BYTE	$05
		.WORD	_native_sub154
		.BYTE	$34,$01		; OBJ_SET_HP
		.BYTE	$1D,$05		; SPR_LIB_SELECT
		.BYTE	$1E,$31		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	_script201
		.BYTE	$29,$F0		; OBJ_SET_X_DELTA
byte_6AEDB:
		.BYTE	$1E,$30
		.BYTE	$02,$08		; DELAY
		.BYTE	$1E,$2F		; SPR_IDX_SELECT
		.BYTE	$02,$08		; DELAY
byte_6AEE3:
		.BYTE	$05
		.WORD	_native_sub138
		.BYTE	$0F		; SBCC
		.WORD	byte_6AEED
		.BYTE	$04,$07		; RUN
		.WORD	_script143
byte_6AEED:
		.BYTE	$07
		.WORD	_script_animate32
		.BYTE	$05		; NJSR
		.WORD	_native_sub105
		.BYTE	$05		; NJSR
		.WORD	_native_sub16F
		.BYTE	$0F		; SBCC
		.WORD	byte_6AEE3
		.BYTE	$1E,$30		; SPR_IDX_SELECT
		.BYTE	$02,$08		; DELAY
		.BYTE	$1E,$31		; SPR_IDX_SELECT
		.BYTE	$02,$08		; DELAY
byte_6AF01:
		.BYTE	$05
		.WORD	_native_sub138
		.BYTE	$0F		; SBCC
		.WORD	byte_6AF0B
		.BYTE	$04,$07		; RUN
		.WORD	_script144
byte_6AF0B:
		.BYTE	$07
		.WORD	_script_animate32
		.BYTE	$05		; NJSR
		.WORD	_native_sub105
		.BYTE	$05		; NJSR
		.WORD	_native_sub16F
		.BYTE	$0C		; SBCS
		.WORD	byte_6AF01
		.BYTE	$06		; SJMP
		.WORD	byte_6AEDB
_script143:
		.BYTE	$27,$EE
		.BYTE	$29,$D8		; OBJ_SET_X_DELTA
		.BYTE	$06		; SJMP
		.WORD	byte_6AF25
_script144:
		.BYTE	$27,$12
		.BYTE	$29,$28		; OBJ_SET_X_DELTA
byte_6AF25:
		.BYTE	$43
		.BYTE	$05		; NJSR
		.WORD	_native_sub12B
		.BYTE	$28,$24		; OBJ_MOVE_Y_POS
		.BYTE	$2A,$28		; OBJ_SET_Y_DELTA
		.BYTE	$32,$07,$0E	; OBJ_SET_SIZE
		.BYTE	$1D,$05		; SPR_LIB_SELECT
		.BYTE	$1E,$32		; SPR_IDX_SELECT
		.BYTE	$1B		; PARAM_80_CLEAR
		.BYTE	$34,$FF		; OBJ_SET_HP
		.BYTE	$33,$01		; VAR_1C_SET
byte_6AF39:
		.BYTE	$01
		.BYTE	$05		; NJSR
		.WORD	_native_get_obj_y_delta
		.BYTE	$0D		; SBMI
		.WORD	byte_6AF4C
		.BYTE	$05		; NJSR
		.WORD	_obj_vert_animate
		.BYTE	$05		; NJSR
		.WORD	_native_sub10A
		.BYTE	$0C		; SBCS
		.WORD	byte_6AF52
		.BYTE	$06		; SJMP
		.WORD	byte_6AF57
byte_6AF4C:
		.BYTE	$05
		.WORD	_native_sub10B
		.BYTE	$0C		; SBCS
		.WORD	byte_6AF57
byte_6AF52:
		.BYTE	$05
		.WORD	_native_sub129
		.BYTE	$17,$54		; APU_LOAD
byte_6AF57:
		.BYTE	$05
		.WORD	_obj_move_hor_animate
		.BYTE	$05		; NJSR
		.WORD	_native_sub104
		.BYTE	$0F		; SBCC
		.WORD	byte_6AF39
		.BYTE	$05		; NJSR
		.WORD	_native_sub105
		.BYTE	$17,$54		; APU_LOAD
		.BYTE	$06		; SJMP
		.WORD	byte_6AF39
_script177:
		.BYTE	$13,$00
		.WORD	_pal_anim_mode_idx
		.BYTE	$39,$04,$FF	; PAL_FADE_OUT
		.BYTE	$02,$14		; DELAY
		.BYTE	$13,$40		; MOV
		.WORD	_stage_flags
		.BYTE	$06		; SJMP
		.WORD	_script_idle
byte_6AF78:
		.BYTE	$25,$70,$00
		.BYTE	$13,$1E		; MOV
		.WORD	_stage4_seconds_cnt
		.BYTE	$13,$00		; MOV
		.WORD	byte_DE
		.BYTE	$13,$00		; MOV
		.WORD	byte_DF
		.BYTE	$1D,$00		; SPR_LIB_SELECT
		.BYTE	$1E,$10		; SPR_IDX_SELECT
		.BYTE	$08		; RET
byte_6AF8C:
		.BYTE	$17,$3A
		.BYTE	$05		; NJSR
		.WORD	_native_sub021
		.BYTE	$13,$3B		; MOV
		.WORD	_stage4_frames_cnt
		.BYTE	$08		; RET
byte_6AF96:
		.BYTE	$13,$FF
		.WORD	_stage4_frames_cnt
byte_6AF9A:
		.BYTE	$03
		.WORD	_native_sub044
		.BYTE	$09,$F0		; LOOPA
		.WORD	byte_6AF9A
byte_6AFA1:
		.BYTE	$06
		.WORD	byte_B6B07

; =============== S U B	R O U T	I N E =======================================
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
		JMP		_scr_flags_flush_ex
byte_6AFC1:
		.BYTE	$03
		.WORD	_native_sub044
		.BYTE	$09,$3C		; LOOPA
		.WORD	byte_6AFC1
		.BYTE	$14,$01,$0B	; CHR_BANK
		.BYTE	$03		; NJMP
		.WORD	_native_sub045
		.BYTE	$1D,$05		; SPR_LIB_SELECT
		.BYTE	$1E,$28		; SPR_IDX_SELECT
		.BYTE	$1B		; PARAM_80_CLEAR
		.BYTE	$25,$80,$00	; OBJ_SET_X_POS
		.BYTE	$26,$68,$00	; OBJ_SET_Y_POS
		.BYTE	$05		; NJSR
		.WORD	_native_sub046
		.BYTE	$02,$B4		; DELAY
		.BYTE	$05		; NJSR
		.WORD	_native_sub047
		.BYTE	$06		; SJMP
		.WORD	byte_6AFA1

; =============== S U B	R O U T	I N E =======================================
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
		LDA		_obj_vars0D,Y
		AND		#$40
		BEQ		loc_6B00A
		LDA		_obj_vars0D,Y
		AND		#$0F
		CMP		#$02
		BCC		loc_6B00A
		LDA		_obj_vars0D,Y
		AND		#$BF
		STA		_obj_vars0D,Y
loc_6B00A:
		DEY
		BPL		loc_6AFF2
		RTS

; =============== S U B	R O U T	I N E =======================================
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

; =============== S U B	R O U T	I N E =======================================
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
_obj_scr00:
		.BYTE	$05
		.WORD	_native_sub14A
		.BYTE	$04,$06		; RUN
		.WORD	_script145
		.BYTE	$04,$06		; RUN
		.WORD	_script146
		.BYTE	$04,$06		; RUN
		.WORD	_script147
		.BYTE	$04,$09		; RUN
		.WORD	_script148
		.BYTE	$04,$09		; RUN
		.WORD	_script149
		.BYTE	$07		; SJSR
		.WORD	byte_6AF78
		.BYTE	$13,$0A		; MOV
		.WORD	_stage4_seconds_cnt
		.BYTE	$26,$38,$00	; OBJ_SET_Y_POS
byte_6B05E:
		.BYTE	$03
		.WORD	_native_sub044
		.BYTE	$09,$3C		; LOOPA
		.WORD	byte_6B05E
		.BYTE	$07		; SJSR
		.WORD	byte_6AF8C
byte_6B068:
		.BYTE	$05
		.WORD	_native_sub170
		.BYTE	$0E		; SBNE
		.WORD	byte_6B074
		.BYTE	$03		; NJMP
		.WORD	_native_sub044
		.BYTE	$0B		; SBEQ
		.WORD	byte_6B068
byte_6B074:
		.BYTE	$05
		.WORD	_native_sub171
		.BYTE	$06		; SJMP
		.WORD	_script177
byte_6B07A:
		.BYTE	$04,$01
		.WORD	_script14A
		.BYTE	$05		; NJSR
		.WORD	_native_sub117
		.BYTE	$05		; NJSR
		.WORD	_native_sub134
		.BYTE	$34,$01		; OBJ_SET_HP
		.BYTE	$32,$08,$10	; OBJ_SET_SIZE
		.BYTE	$05		; NJSR
		.WORD	_native_sub113
		.BYTE	$0D		; SBMI
		.WORD	byte_6B095
		.BYTE	$25,$08,$01	; OBJ_SET_X_POS
		.BYTE	$06		; SJMP
		.WORD	byte_6B09B
byte_6B095:
		.BYTE	$25,$F8,$FF
		.BYTE	$05		; NJSR
		.WORD	_native_sub105
byte_6B09B:
		.BYTE	$08
byte_6B09C:
		.BYTE	$07
		.WORD	_script_animate16
		.BYTE	$05		; NJSR
		.WORD	_native_sub129
		.BYTE	$08		; RET
byte_6B0A3:
		.BYTE	$02,$1E
		.BYTE	$03		; NJMP
		.WORD	_native_sub105
		.BYTE	$08		; RET

; =============== S U B	R O U T	I N E =======================================
_native_sub048:
		JSR		_native_sub049

; =============== S U B	R O U T	I N E =======================================
_native_sub049:
		LDX		_scr_idx
		JSR		_native_sub049_A
		JMP		_native_sub049_B
_script145:
		.BYTE	$1D,$05
		.BYTE	$1E,$1E		; SPR_IDX_SELECT
		.BYTE	$1B		; PARAM_80_CLEAR
		.BYTE	$28,$40		; OBJ_MOVE_Y_POS
		.BYTE	$29,$BC		; OBJ_SET_X_DELTA
		.BYTE	$2A,$F8		; OBJ_SET_Y_DELTA
		.BYTE	$42		; DESTR_PC_SET
		.WORD	byte_6B109
		.BYTE	$07		; SJSR
		.WORD	byte_6B07A
byte_6B0C5:
		.BYTE	$07
		.WORD	byte_6B09C
		.BYTE	$0A,$04		; LOOPB
		.WORD	byte_6B0C5
		.BYTE	$07		; SJSR
		.WORD	byte_6B0A3
		.BYTE	$06		; SJMP
		.WORD	byte_6B0C5
_script146:
		.BYTE	$1D,$06
		.BYTE	$1E,$01		; SPR_IDX_SELECT
		.BYTE	$1B		; PARAM_80_CLEAR
		.BYTE	$28,$58		; OBJ_MOVE_Y_POS
		.BYTE	$29,$D2		; OBJ_SET_X_DELTA
		.BYTE	$2A,$F8		; OBJ_SET_Y_DELTA
		.BYTE	$42		; DESTR_PC_SET
		.WORD	byte_6B116
		.BYTE	$07		; SJSR
		.WORD	byte_6B07A
byte_6B0E3:
		.BYTE	$07
		.WORD	byte_6B09C
		.BYTE	$0A,$06		; LOOPB
		.WORD	byte_6B0E3
		.BYTE	$07		; SJSR
		.WORD	byte_6B0A3
		.BYTE	$06		; SJMP
		.WORD	byte_6B0E3
_script147:
		.BYTE	$28,$7F
		.BYTE	$29,$E4		; OBJ_SET_X_DELTA
		.BYTE	$2A,$F0		; OBJ_SET_Y_DELTA
		.BYTE	$42		; DESTR_PC_SET
		.WORD	byte_6B11F
		.BYTE	$07		; SJSR
		.WORD	byte_6B07A
byte_6B0FC:
		.BYTE	$07
		.WORD	byte_6B09C
		.BYTE	$0A,$0A		; LOOPB
		.WORD	byte_6B0FC
		.BYTE	$07		; SJSR
		.WORD	byte_6B0A3
		.BYTE	$06		; SJMP
		.WORD	byte_6B0FC
byte_6B109:
		.BYTE	$05
		.WORD	_players_animB_sub0129_sub06_A
		.BYTE	$05		; NJSR
		.WORD	_native_sub048
		.BYTE	$1D,$05		; SPR_LIB_SELECT
		.BYTE	$1E,$1F		; SPR_IDX_SELECT
		.BYTE	$06		; SJMP
		.WORD	byte_6A23B
byte_6B116:
		.BYTE	$05
		.WORD	_players_animB_sub0129_sub06_A
		.BYTE	$05		; NJSR
		.WORD	_native_sub049
		.BYTE	$06		; SJMP
		.WORD	_script151
byte_6B11F:
		.BYTE	$05
		.WORD	_players_animB_sub0129_sub06_A
		.BYTE	$00		; STOP
_script14A:
		.BYTE	$1D,$05
		.BYTE	$1B		; PARAM_80_CLEAR
byte_6B126:
		.BYTE	$1E,$1D
		.BYTE	$07		; SJSR
		.WORD	byte_6B13D
		.BYTE	$1E,$0F		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	byte_6B13D
		.BYTE	$1E,$10		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	byte_6B13D
		.BYTE	$1E,$11		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	byte_6B13D
		.BYTE	$06		; SJMP
		.WORD	byte_6B126
byte_6B13D:
		.BYTE	$03
		.WORD	_native_sub04A
		.BYTE	$0A,$06		; LOOPB
		.WORD	byte_6B13D
		.BYTE	$08		; RET

; =============== S U B	R O U T	I N E =======================================
_native_sub04A:
		JSR		_native_sub04A_A ; FLIP_40_SET
		CLC
		LDA		_obj_y_lo_poss,Y
		ADC		#$08
		STA		_obj_y_lo_poss,X
		RTS

; =============== S U B	R O U T	I N E =======================================
_native_get_player1_lives:
		LDA		_players_lives
		JMP		_scr_flags_flush_ex

; =============== S U B	R O U T	I N E =======================================
_native_get_player2_lives:
		LDA		_players_lives+1
		JMP		_scr_flags_flush_ex
_script148:
		.BYTE	$05
		.WORD	_native_get_player1_lives
		.BYTE	$0E		; SBNE
		.WORD	byte_6B191
		.BYTE	$25,$10,$00	; OBJ_SET_X_POS
		.BYTE	$06		; SJMP
		.WORD	byte_6B171
_script149:
		.BYTE	$05
		.WORD	_native_get_player2_lives
		.BYTE	$0E		; SBNE
		.WORD	byte_6B191
		.BYTE	$25,$F0,$00	; OBJ_SET_X_POS
byte_6B171:
		.BYTE	$43
		.BYTE	$42		; DESTR_PC_SET
		.WORD	byte_6B185
		.BYTE	$26,$C0,$00	; OBJ_SET_Y_POS
		.BYTE	$32,$06,$10	; OBJ_SET_SIZE
		.BYTE	$1D,$05		; SPR_LIB_SELECT
		.BYTE	$1E,$1B		; SPR_IDX_SELECT
		.BYTE	$1B		; PARAM_80_CLEAR
		.BYTE	$34,$01		; OBJ_SET_HP
		.BYTE	$07		; SJSR
		.WORD	byte_68065
byte_6B185:
		.BYTE	$07
		.WORD	byte_6806C
		.BYTE	$2A,$C0		; OBJ_SET_Y_DELTA
		.BYTE	$34,$01		; OBJ_SET_HP
		.BYTE	$33,$01		; VAR_1C_SET
		.BYTE	$06		; SJMP
		.WORD	byte_68092
byte_6B191:
		.BYTE	$00
_obj_scr02:
		.BYTE	$05
		.WORD	_native_sub04B
		.BYTE	$28,$40		; OBJ_MOVE_Y_POS
byte_6B197:
		.BYTE	$04,$06
		.WORD	_script14B
		.BYTE	$23		; FLIP_40_TOGGLE
		.BYTE	$28,$30		; OBJ_MOVE_Y_POS
		.BYTE	$09,$04		; LOOPA
		.WORD	byte_6B197
		.BYTE	$26,$13,$00	; OBJ_SET_Y_POS
		.BYTE	$07		; SJSR
		.WORD	byte_6AF78
		.BYTE	$07		; SJSR
		.WORD	byte_6AF8C
byte_6B1AB:
		.BYTE	$03
		.WORD	_native_sub044
		.BYTE	$0B		; SBEQ
		.WORD	byte_6B1AB
		.BYTE	$06		; SJMP
		.WORD	byte_6AFC1

; =============== S U B	R O U T	I N E =======================================
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
_script14B:
		.BYTE	$32,$08,$12
		.BYTE	$1D,$05		; SPR_LIB_SELECT
		.BYTE	$1B		; PARAM_80_CLEAR
		.BYTE	$29,$01		; OBJ_SET_X_DELTA
		.BYTE	$05		; NJSR
		.WORD	_native_sub10F
		.BYTE	$1F		; FLIP_40_CLEAR
byte_6B1EE:
		.BYTE	$1E,$17
		.BYTE	$1F		; FLIP_40_CLEAR
		.BYTE	$07		; SJSR
		.WORD	byte_6B207
		.BYTE	$1E,$18		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	byte_6B207
		.BYTE	$1E,$19		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	byte_6B207
		.BYTE	$1E,$18		; SPR_IDX_SELECT
		.BYTE	$20		; FLIP_40_SET
		.BYTE	$07		; SJSR
		.WORD	byte_6B207
		.BYTE	$06		; SJMP
		.WORD	byte_6B1EE
byte_6B207:
		.BYTE	$01
		.BYTE	$05		; NJSR
		.WORD	_native_sub04D
		.BYTE	$0E		; SBNE
		.WORD	byte_6B21A
		.BYTE	$05		; NJSR
		.WORD	_obj_move_hor_animate
		.BYTE	$05		; NJSR
		.WORD	_native_get_obj_hp
		.BYTE	$0B		; SBEQ
		.WORD	byte_6B21A
		.BYTE	$05		; NJSR
		.WORD	_native_sub04C
byte_6B21A:
		.BYTE	$09,$08
		.WORD	byte_6B207
		.BYTE	$08		; RET

; =============== S U B	R O U T	I N E =======================================
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

; =============== S U B	R O U T	I N E =======================================
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
		JMP		_scr_flags_flush_ex
_script47:
		.BYTE	$42
		.WORD	_script47
		.BYTE	$32,$06,$10	; OBJ_SET_SIZE
		.BYTE	$1D,$05		; SPR_LIB_SELECT
		.BYTE	$1E,$1B		; SPR_IDX_SELECT
		.BYTE	$1B		; PARAM_80_CLEAR
		.BYTE	$07		; SJSR
		.WORD	byte_6806C
		.BYTE	$05		; NJSR
		.WORD	_native_sub030
byte_6B27A:
		.BYTE	$18
		.BYTE	$05		; NJSR
		.WORD	_native_get_obj_hp
		.BYTE	$0B		; SBEQ
		.WORD	byte_6B27A
		.BYTE	$29,$08		; OBJ_SET_X_DELTA
		.BYTE	$2A,$E8		; OBJ_SET_Y_DELTA
		.BYTE	$05		; NJSR
		.WORD	_players_animB_sub67_A
		.BYTE	$06		; SJMP
		.WORD	byte_68096
_obj_scr03:
		.BYTE	$04,$01
		.WORD	_script14C
		.BYTE	$05		; NJSR
		.WORD	_native_sub04E
		.BYTE	$07		; SJSR
		.WORD	byte_6AF78
		.BYTE	$13,$3C		; MOV
		.WORD	_stage4_seconds_cnt
		.BYTE	$26,$18,$00	; OBJ_SET_Y_POS
byte_6B29C:
		.BYTE	$03
		.WORD	_native_sub044
		.BYTE	$09,$B4		; LOOPA
		.WORD	byte_6B29C
		.BYTE	$04,$05		; RUN
		.WORD	_script14D
		.BYTE	$04,$05		; RUN
		.WORD	_script14E
		.BYTE	$07		; SJSR
		.WORD	byte_6AF8C
byte_6B2AE:
		.BYTE	$03
		.WORD	_native_sub044
		.BYTE	$0B		; SBEQ
		.WORD	byte_6B2AE
		.BYTE	$06		; SJMP
		.WORD	byte_6AFC1

; =============== S U B	R O U T	I N E =======================================
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
_script14C:
		.BYTE	$28,$58
		.BYTE	$04,$09		; RUN
		.WORD	_script14F
		.BYTE	$05		; NJSR
		.WORD	_native_sub117
		.BYTE	$04,$09		; RUN
		.WORD	_script150
		.BYTE	$05		; NJSR
		.WORD	_native_sub117
		.BYTE	$32,$04,$04	; OBJ_SET_SIZE
		.BYTE	$29,$F0		; OBJ_SET_X_DELTA
		.BYTE	$1D,$05		; SPR_LIB_SELECT
		.BYTE	$1E,$1C		; SPR_IDX_SELECT
		.BYTE	$1B		; PARAM_80_CLEAR
		.BYTE	$02,$B4		; DELAY
byte_6B2F5:
		.BYTE	$05
		.WORD	_native_cmp40_obj_x_lo_pos
		.BYTE	$0F		; SBCC
		.WORD	byte_6B30D
		.BYTE	$05		; NJSR
		.WORD	_native_cmpC0_obj_x_lo_pos
		.BYTE	$0C		; SBCS
		.WORD	byte_6B30D
		.BYTE	$05		; NJSR
		.WORD	_native_sub12A
		.BYTE	$12		; SWITCH
		.WORD	_tmp_ptrE+1
		.WORD	byte_6B310
		.WORD	byte_6B310
		.WORD	byte_6B30D
byte_6B30D:
		.BYTE	$05
		.WORD	_native_sub110
byte_6B310:
		.BYTE	$18
		.BYTE	$09,$26		; LOOPA
		.WORD	byte_6B310
		.BYTE	$06		; SJMP
		.WORD	byte_6B2F5
byte_6B318:
		.BYTE	$32,$02,$02
		.BYTE	$34,$01		; OBJ_SET_HP
		.BYTE	$08		; RET
_script14F:
		.BYTE	$07
		.WORD	byte_6B318
byte_6B321:
		.BYTE	$01
		.BYTE	$05		; NJSR
		.WORD	_native_sub04A_A
		.BYTE	$27,$F1		; OBJ_MOVE_X_POS
		.BYTE	$28,$F2		; OBJ_MOVE_Y_POS
		.BYTE	$06		; SJMP
		.WORD	byte_6B321
_script150:
		.BYTE	$07
		.WORD	byte_6B318
byte_6B32F:
		.BYTE	$01
		.BYTE	$05		; NJSR
		.WORD	_native_sub04A_A
		.BYTE	$27,$0F		; OBJ_MOVE_X_POS
		.BYTE	$28,$F2		; OBJ_MOVE_Y_POS
		.BYTE	$06		; SJMP
		.WORD	byte_6B32F
_script14D:
		.BYTE	$25,$18,$00
		.BYTE	$06		; SJMP
		.WORD	byte_6B343
_script14E:
		.BYTE	$25,$E8,$00
byte_6B343:
		.BYTE	$42
		.WORD	byte_6B367
		.BYTE	$26,$40,$00	; OBJ_SET_Y_POS
		.BYTE	$32,$06,$0D	; OBJ_SET_SIZE
		.BYTE	$1D,$04		; SPR_LIB_SELECT
		.BYTE	$1B		; PARAM_80_CLEAR
		.BYTE	$06		; SJMP
		.WORD	byte_6B373
byte_6B352:
		.BYTE	$29,$00
		.BYTE	$05		; NJSR
		.WORD	_native_sub160
byte_6B357:
		.BYTE	$01
		.BYTE	$05		; NJSR
		.WORD	_native_get_obj_var0D
		.BYTE	$10		; SBPL
		.WORD	byte_6B367
		.BYTE	$07		; SJSR
		.WORD	byte_6A589
		.BYTE	$0F		; SBCC
		.WORD	byte_6B357
		.BYTE	$06		; SJMP
		.WORD	byte_6B373
byte_6B367:
		.BYTE	$07
		.WORD	byte_6806C
		.BYTE	$31,$00		; TARGET_DIR_SET
		.BYTE	$29,$08		; OBJ_SET_X_DELTA
		.BYTE	$2A,$B0		; OBJ_SET_Y_DELTA
		.BYTE	$05		; NJSR
		.WORD	_native_sub029
byte_6B373:
		.BYTE	$05
		.WORD	_native_sub11C
		.BYTE	$05		; NJSR
		.WORD	_native_sub161
		.BYTE	$05		; NJSR
		.WORD	_native_sub134
byte_6B37C:
		.BYTE	$07
		.WORD	byte_6B393
		.BYTE	$2A,$E0		; OBJ_SET_Y_DELTA
		.BYTE	$05		; NJSR
		.WORD	_native_cmp50_obj_y_lo_pos
		.BYTE	$0F		; SBCC
		.WORD	byte_6B37C
		.BYTE	$05		; NJSR
		.WORD	_far_players_animB_sub0129_G
		.BYTE	$0D		; SBMI
		.WORD	byte_6B352
		.BYTE	$07		; SJSR
		.WORD	byte_6B393
		.BYTE	$06		; SJMP
		.WORD	byte_6B352
byte_6B393:
		.BYTE	$03
		.WORD	_native_sub04F
		.BYTE	$05		; NJSR
		.WORD	_native_sub100
		.BYTE	$34,$01		; OBJ_SET_HP
		.BYTE	$33,$02		; VAR_1C_SET
		.BYTE	$07		; SJSR
		.WORD	byte_6A557
		.BYTE	$0C		; SBCS
		.WORD	byte_6B393
		.BYTE	$08		; RET

; =============== S U B	R O U T	I N E =======================================
_native_sub04F:
		LDA		#<[byte_6B3AB]
		LDY		#>[byte_6B3AB]
		JMP		_native_sub023
byte_6B3AB:
		.BYTE	$05,$00
		.BYTE	$06,$00
		.BYTE	$05,$40
		.BYTE	$06,$C0
_obj_scr01_bonus_room:
		.BYTE	$05
		.WORD	_native_sub052
		.BYTE	$05		; NJSR
		.WORD	loc_6B430
		.BYTE	$05		; NJSR
		.WORD	_native_sub142
byte_6B3BC:
		.BYTE	$05
		.WORD	_native_sub053
		.BYTE	$09,$04		; LOOPA
		.WORD	byte_6B3BC
		.BYTE	$26,$18,$00	; OBJ_SET_Y_POS
		.BYTE	$07		; SJSR
		.WORD	byte_6AF78
		.BYTE	$13,$0A		; MOV
		.WORD	_stage4_seconds_cnt
		.BYTE	$07		; SJSR
		.WORD	byte_6B415
		.BYTE	$05		; NJSR
		.WORD	_native_sub139
		.BYTE	$05		; NJSR
		.WORD	_native_sub051
		.BYTE	$07		; SJSR
		.WORD	byte_6B415
		.BYTE	$07		; SJSR
		.WORD	byte_6B418
		.BYTE	$05		; NJSR
		.WORD	_native_sub16A
		.BYTE	$07		; SJSR
		.WORD	byte_6B418
		.BYTE	$05		; NJSR
		.WORD	loc_6B430
		.BYTE	$05		; NJSR
		.WORD	_native_sub139
		.BYTE	$07		; SJSR
		.WORD	byte_6AF8C
byte_6B3EB:
		.BYTE	$05
		.WORD	_native_sub056
		.BYTE	$0E		; SBNE
		.WORD	byte_6B3FA
		.BYTE	$03		; NJMP
		.WORD	_native_sub044
		.BYTE	$0B		; SBEQ
		.WORD	byte_6B3EB
		.BYTE	$05		; NJSR
		.WORD	_native_sub057
byte_6B3FA:
		.BYTE	$05
		.WORD	_native_sub050
		.BYTE	$06		; SJMP
		.WORD	byte_6AF96

; =============== S U B	R O U T	I N E =======================================
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
byte_6B415:
		.BYTE	$07
		.WORD	byte_6B418
byte_6B418:
		.BYTE	$03
		.WORD	_native_sub044
		.BYTE	$09,$78		; LOOPA
		.WORD	byte_6B418
		.BYTE	$08		; RET

; =============== S U B	R O U T	I N E =======================================
_native_sub051:
		LDA		#$96
		STA		byte_436
		STA		byte_438
		LDA		#$97
		STA		byte_437
		STA		byte_439
loc_6B430:
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

; =============== S U B	R O U T	I N E =======================================
_native_sub052:
		LDY		#$03
		LDA		#$F4
loc_6B44E:
		STA		byte_436,Y
		DEY
		BPL		loc_6B44E
		RTS

; =============== S U B	R O U T	I N E =======================================
_native_sub053:
		JSR		_native_sub143
		LDY		_tmp_ptrE+1
		LDA		byte_6B49A,Y
		STA		_tmp_ptr4
		LDA		#$C0
		STA		_tmp_ptr2
		LDA		#$00
		STA		_tmp_ptr2+1
		STA		_tmp_ptr4+1
		STA		byte_6
		LDY		_scr_loopsA,X
		LDA		byte_6B4AA,Y
		PHA
		LDA		off_6B4A2,Y
		STA		_tmp_ptr0
		LDA		off_6B4A6,Y
		STA		_tmp_ptr0+1
		LDY		#$01
		JSR		_scr_load
		PLA
		STA		_scr_vars19,X
		LDY		_tmp_ptrE+1
		LDA		byte_6B49E,Y
		STA		_scr_delays,X
		LDA		off_6B4AE,Y
		STA		_scr_destr_lo_pcs,X
		LDA		off_6B4B2,Y
		STA		_scr_destr_hi_pcs,X
		RTS
byte_6B49A:
		.BYTE	$38,$68,$98,$C8
byte_6B49E:
		.BYTE	$08,$18,$28,$38
off_6B4A2:
		.BYTE	<[_script8]
		.BYTE	<[_script9]
		.BYTE	<[_scriptA]
		.BYTE	<[_scriptB]
off_6B4A6:
		.BYTE	>[_script8]
		.BYTE	>[_script9]
		.BYTE	>[_scriptA]
		.BYTE	>[_scriptB]
byte_6B4AA:
		.BYTE	$F4,$F5,$F6,$F7
off_6B4AE:
		.BYTE	<[byte_6B4B6]
		.BYTE	<[byte_6B4C8]
		.BYTE	<[byte_6B4DA]
		.BYTE	<[byte_6B4EC]
off_6B4B2:
		.BYTE	>[byte_6B4B6]
		.BYTE	>[byte_6B4C8]
		.BYTE	>[byte_6B4DA]
		.BYTE	>[byte_6B4EC]
byte_6B4B6:
		.BYTE	$21,$11,$11,$21,$14,$31,$43,$33,$34,$12,$34,$11,$13,$32,$32,$11
		.BYTE	$41,$00		; FLIP_80_CLEAR
byte_6B4C8:
		.BYTE	$03,$33,$41,$11,$12,$13,$12,$31,$41,$43,$23,$32,$14,$32,$14,$33
		.BYTE	$33,$00
byte_6B4DA:
		.BYTE	$01,$11,$23,$33,$43,$22,$14,$44,$33,$22,$31,$11,$43,$23,$43,$41
		.BYTE	$23,$00
byte_6B4EC:
		.BYTE	$42,$23,$33,$41,$23,$44,$33,$13,$22,$14,$12,$43,$21,$43,$24,$11
		.BYTE	$11,$00

; =============== S U B	R O U T	I N E =======================================
_native_sub054:
		LDY		#$03
		LDA		_obj_x_lo_poss,X
loc_6B503:
		CMP		byte_6B49A,Y
		BEQ		loc_6B50C
		DEY
		BPL		loc_6B503
		RTS
loc_6B50C:
		LDA		_scr_vars19,X
		STA		byte_436,Y
		RTS

; =============== S U B	R O U T	I N E =======================================
_native_sub055:
		LDA		#$00
		STA		_obj_x_deltas,X
		STA		_obj_y_deltas,X
		JSR		_scr_flags_flush_ex
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
		JMP		_scr_flags_flush_ex
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

; =============== S U B	R O U T	I N E =======================================
_native_sub055_sub0:
		LDA		#$20
		BNE		_native_sub055_sub0_ex

; =============== S U B	R O U T	I N E =======================================
_native_sub055_sub2:
		LDA		#$E0

; =============== S U B	R O U T	I N E =======================================
_native_sub055_sub0_ex:
		STA		_obj_x_deltas,X
		RTS

; =============== S U B	R O U T	I N E =======================================
_native_sub055_sub1:
		LDA		#$20
		BNE		_native_sub055_sub1_ex

; =============== S U B	R O U T	I N E =======================================
_native_sub055_sub3:
		LDA		#$E0

; =============== S U B	R O U T	I N E =======================================
_native_sub055_sub1_ex:
		STA		_obj_y_deltas,X

; =============== S U B	R O U T	I N E =======================================
nullsub5:
		RTS

; =============== S U B	R O U T	I N E =======================================
_native_sub056:
		LDY		#$00
		LDX		#$01
loc_6B566:
		LDA		_players_states,X
		CMP		#$04
		BEQ		loc_6B588
		CMP		#$18
		BEQ		loc_6B588
		LDA		_obj_vars0D,X
		AND		#$40
		BEQ		loc_6B589
		LDA		_obj_vars0D,X
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
		JMP		_scr_flags_flush_ex

; =============== S U B	R O U T	I N E =======================================
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
_script8:
		.BYTE	$1D,$05
		.BYTE	$1E,$37		; SPR_IDX_SELECT
		.BYTE	$06		; SJMP
		.WORD	byte_6B5BA
_script9:
		.BYTE	$1D,$06
		.BYTE	$1E,$01		; SPR_IDX_SELECT
		.BYTE	$06		; SJMP
		.WORD	byte_6B5BA
_scriptA:
		.BYTE	$1D,$05
		.BYTE	$1E,$24		; SPR_IDX_SELECT
		.BYTE	$06		; SJMP
		.WORD	byte_6B5BA
_scriptB:
		.BYTE	$1D,$05
		.BYTE	$1E,$25		; SPR_IDX_SELECT
byte_6B5BA:
		.BYTE	$1B
		.BYTE	$34,$01		; OBJ_SET_HP
		.BYTE	$32,$06,$0C	; OBJ_SET_SIZE
		.BYTE	$2A,$E0		; OBJ_SET_Y_DELTA
		.BYTE	$07		; SJSR
		.WORD	_script_animate10
		.BYTE	$02,$78		; DELAY
		.BYTE	$2A,$20		; OBJ_SET_Y_DELTA
		.BYTE	$07		; SJSR
		.WORD	_script_animate10
		.BYTE	$2A,$00		; OBJ_SET_Y_DELTA
		.BYTE	$1D,$03		; SPR_LIB_SELECT
		.BYTE	$1E,$00		; SPR_IDX_SELECT
byte_6B5D2:
		.BYTE	$03
		.WORD	_native_sub058
		.BYTE	$0E		; SBNE
		.WORD	byte_6B5D2
byte_6B5D8:
		.BYTE	$05
		.WORD	_native_sub055
		.BYTE	$07		; SJSR
		.WORD	_script_animate10
		.BYTE	$05		; NJSR
		.WORD	_native_sub058
		.BYTE	$0B		; SBEQ
		.WORD	byte_6B5D8
		.BYTE	$05		; NJSR
		.WORD	_native_sub054
byte_6B5E7:
		.BYTE	$03
		.WORD	_native_sub058
		.BYTE	$0E		; SBNE
		.WORD	byte_6B5E7
		.BYTE	$00		; STOP

; =============== S U B	R O U T	I N E =======================================
_native_sub058:
		LDY		_scr_idxAs,X
		LDA		_obj_vars0D,Y
		AND		#$10
		JMP		_scr_flags_flush_ex
_script42:
		.BYTE	$1D,$05
		.BYTE	$1E,$37		; SPR_IDX_SELECT
		.BYTE	$1B		; PARAM_80_CLEAR
		.BYTE	$05		; NJSR
		.WORD	_native_sub059
		.BYTE	$06		; SJMP
		.WORD	_script_idle
_script43:
		.BYTE	$1D,$06
		.BYTE	$1E,$01		; SPR_IDX_SELECT
		.BYTE	$1B		; PARAM_80_CLEAR
		.BYTE	$05		; NJSR
		.WORD	_native_sub05A
		.BYTE	$04,$01		; RUN
		.WORD	_script151
		.BYTE	$06		; SJMP
		.WORD	_script_idle
_script44:
		.BYTE	$1D,$05
		.BYTE	$1E,$24		; SPR_IDX_SELECT
		.BYTE	$1B		; PARAM_80_CLEAR
		.BYTE	$05		; NJSR
		.WORD	_native_sub05B
		.BYTE	$04,$01		; RUN
		.WORD	_script152
		.BYTE	$06		; SJMP
		.WORD	_script_idle
_script152:
		.BYTE	$1D,$05
		.BYTE	$1E,$35		; SPR_IDX_SELECT
		.BYTE	$06		; SJMP
		.WORD	byte_6A240
_script45:
		.BYTE	$1D,$05
		.BYTE	$1E,$25		; SPR_IDX_SELECT
		.BYTE	$1B		; PARAM_80_CLEAR
		.BYTE	$05		; NJSR
		.WORD	_native_sub05C
		.BYTE	$04,$01		; RUN
		.WORD	_script153
		.BYTE	$06		; SJMP
		.WORD	_script_idle
_script153:
		.BYTE	$1D,$05
		.BYTE	$1E,$36		; SPR_IDX_SELECT
		.BYTE	$06		; SJMP
		.WORD	byte_6A240

; =============== S U B	R O U T	I N E =======================================
_native_sub059:
		LDA		_continues
		CMP		#$09
		BCS		locret_6B647
		INC		_continues
locret_6B647:
		RTS

; =============== S U B	R O U T	I N E =======================================
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

; =============== S U B	R O U T	I N E =======================================
_native_sub05B:
		LDA		#$1E
		BNE		_native_sub05C_ex

; =============== S U B	R O U T	I N E =======================================
_native_sub05C:
		LDA		#$0A

; =============== S U B	R O U T	I N E =======================================
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
_script_cutscenes:
		.BYTE	$12
		.WORD	_cutscene_idx
		.WORD	_scr_cutscene00
		.WORD	_scr_cutscene01
		.WORD	_scr_cutscene02
		.WORD	_scr_cutscene03
		.WORD	_scr_cutscene04
		.WORD	_scr_cutscene05
		.WORD	_scr_cutscene06
		.WORD	_scr_cutscene07
		.WORD	_scr_cutscene08
		.WORD	_scr_cutscene09
		.WORD	_scr_cutscene0A
		.WORD	_scr_cutscene0B
		.WORD	_scr_cutscene0C
		.WORD	_scr_cutscene0D
		.WORD	_scr_cutscene0E
		.WORD	_scr_cutscene0F
		.WORD	_scr_cutscene10
		.WORD	_scr_cutscene11
		.WORD	_scr_cutscene12
_script154:
		.BYTE	$01
		.BYTE	$11,$04,$08	; TEST_PADS
		.WORD	_script154
byte_6B69F:
		.BYTE	$13,$04
		.WORD	_main_sub_idx
		.BYTE	$06		; SJMP
		.WORD	byte_6B6A9
byte_6B6A6:
		.BYTE	$05
		.WORD	_native_sub05D
byte_6B6A9:
		.BYTE	$17,$7B
		.BYTE	$02,$20		; DELAY
		.BYTE	$06		; SJMP
		.WORD	_script177
byte_6B6B0:
		.BYTE	$05
		.WORD	_native_sub05D
		.BYTE	$06		; SJMP
		.WORD	_script177

; =============== S U B	R O U T	I N E =======================================
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
		.BYTE	$05
		.WORD	_native_sub139
byte_6B6C5:
		.BYTE	$03
		.WORD	_native_sub14E
		.BYTE	$0B		; SBEQ
		.WORD	byte_6B6C5
		.BYTE	$08		; RET
byte_6B6CC:
		.BYTE	$03
		.WORD	_native_sub05F
byte_6B6CF:
		.BYTE	$03
		.WORD	_native_sub060
		.BYTE	$0E		; SBNE
		.WORD	byte_6B6CF
		.BYTE	$08		; RET

; =============== S U B	R O U T	I N E =======================================
_native_sub05E:
		LDY		_scr_vars19,X
		LDA		_scr_cur_slot_idx
		STA		byte_410,Y
		RTS

; =============== S U B	R O U T	I N E =======================================
_native_sub05F:
		LDY		_scr_vars19,X
		LDX		byte_410,Y
		LDA		_obj_vars0D,X
		AND		#$EF
		STA		_obj_vars0D,X
		RTS

; =============== S U B	R O U T	I N E =======================================
_native_sub060:
		LDY		_scr_vars19,X
		LDX		byte_410,Y
		LDA		_obj_vars0D,X
		AND		#$10
		JMP		_scr_flags_flush_ex
byte_6B6FC:
		.BYTE	$03
		.WORD	_native_sub061
		.BYTE	$0B		; SBEQ
		.WORD	byte_6B6FC
		.BYTE	$08		; RET

; =============== S U B	R O U T	I N E =======================================
_native_sub061:
		LDA		_wnd_msg_sub_idx
		JMP		_scr_flags_flush_ex
byte_6B708:
		.BYTE	$05
		.WORD	_native_sub062
		.BYTE	$03		; NJMP
		.WORD	_native_sub061
		.BYTE	$0B		; SBEQ
		.WORD	byte_6B708
		.BYTE	$08		; RET

; =============== S U B	R O U T	I N E =======================================
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

; =============== S U B	R O U T	I N E =======================================
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
		.BYTE	$05
		.WORD	_native_sub134
		.BYTE	$35,$08		; OBJ_SET_FLIP
		.BYTE	$08		; RET
byte_6B73A:
		.BYTE	$34,$1B
		.BYTE	$33,$1C		; VAR_1C_SET
		.BYTE	$07		; SJSR
		.WORD	byte_6B708
		.BYTE	$06		; SJMP
		.WORD	byte_6B6C2
byte_6B744:
		.BYTE	$34,$1F
		.BYTE	$33,$1E		; VAR_1C_SET
		.BYTE	$07		; SJSR
		.WORD	byte_6B708
		.BYTE	$1E,$1B		; SPR_IDX_SELECT
		.BYTE	$06		; SJMP
		.WORD	byte_6B6C2
byte_6B750:
		.BYTE	$07
		.WORD	byte_B7547
		.BYTE	$07		; SJSR
		.WORD	byte_B7547
		.BYTE	$1E,$1B		; SPR_IDX_SELECT
		.BYTE	$2A,$00		; OBJ_SET_Y_DELTA
		.BYTE	$06		; SJMP
		.WORD	byte_6B6C2
byte_6B75D:
		.BYTE	$07
		.WORD	byte_6B76F
		.BYTE	$05		; NJSR
		.WORD	_players_animB_sub0129_sub0E_A
		.BYTE	$1E,$0D		; SPR_IDX_SELECT
		.BYTE	$02,$78		; DELAY
		.BYTE	$05		; NJSR
		.WORD	_players_animB_sub0129_sub06_A
		.BYTE	$1E,$1B		; SPR_IDX_SELECT
		.BYTE	$06		; SJMP
		.WORD	byte_6B6C2
byte_6B76F:
		.BYTE	$32,$06,$16
		.BYTE	$08		; RET
byte_6B773:
		.BYTE	$05
		.WORD	_native_sub139
byte_6B776:
		.BYTE	$05
		.WORD	_native_sub173
		.BYTE	$03		; NJMP
		.WORD	_native_sub14E
		.BYTE	$0B		; SBEQ
		.WORD	byte_6B776
		.BYTE	$08		; RET
byte_6B780:
		.BYTE	$05
		.WORD	_native_sub063
		.BYTE	$05		; NJSR
		.WORD	_native_sub173
		.BYTE	$03		; NJMP
		.WORD	_native_sub061
		.BYTE	$0B		; SBEQ
		.WORD	byte_6B780
		.BYTE	$08		; RET
byte_6B78D:
		.BYTE	$34,$00
		.BYTE	$33,$03		; VAR_1C_SET
		.BYTE	$07		; SJSR
		.WORD	byte_6B780
		.BYTE	$06		; SJMP
		.WORD	byte_6B773
byte_6B797:
		.BYTE	$34,$06
		.BYTE	$33,$09		; VAR_1C_SET
		.BYTE	$07		; SJSR
		.WORD	byte_6B780
		.BYTE	$31,$06		; TARGET_DIR_SET
		.BYTE	$06		; SJMP
		.WORD	byte_6B773
byte_6B7A3:
		.BYTE	$1E,$29
		.BYTE	$07		; SJSR
		.WORD	_script_animate10
		.BYTE	$1E,$2A		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	_script_animate10
		.BYTE	$1E,$2B		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	_script_animate10
		.BYTE	$1E,$2A		; SPR_IDX_SELECT
		.BYTE	$06		; SJMP
		.WORD	_script_animate10
byte_6B7B7:
		.BYTE	$05
		.WORD	_native_sub139
byte_6B7BA:
		.BYTE	$05
		.WORD	_native_sub15B
		.BYTE	$03		; NJMP
		.WORD	_native_sub14E
		.BYTE	$0B		; SBEQ
		.WORD	byte_6B7BA
		.BYTE	$08		; RET
byte_6B7C4:
		.BYTE	$05
		.WORD	_native_sub063
		.BYTE	$05		; NJSR
		.WORD	_native_sub15B
		.BYTE	$03		; NJMP
		.WORD	_native_sub061
		.BYTE	$0B		; SBEQ
		.WORD	byte_6B7C4
		.BYTE	$08		; RET
byte_6B7D1:
		.BYTE	$34,$06
		.BYTE	$33,$09		; VAR_1C_SET
		.BYTE	$07		; SJSR
		.WORD	byte_6B7C4
		.BYTE	$31,$00		; TARGET_DIR_SET
		.BYTE	$06		; SJMP
		.WORD	byte_6B7B7
byte_6B7DD:
		.BYTE	$1E,$23
		.BYTE	$07		; SJSR
		.WORD	_script_animate10
		.BYTE	$1E,$24		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	_script_animate10
		.BYTE	$1E,$25		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	_script_animate10
		.BYTE	$1E,$24		; SPR_IDX_SELECT
		.BYTE	$06		; SJMP
		.WORD	_script_animate10
byte_6B7F1:
		.BYTE	$05
		.WORD	_native_sub139
		.BYTE	$29,$00		; OBJ_SET_X_DELTA
		.BYTE	$2A,$F8		; OBJ_SET_Y_DELTA
byte_6B7F8:
		.BYTE	$1E,$17
		.BYTE	$18		; JMP_OBJ_ANIMATE
		.BYTE	$18		; JMP_OBJ_ANIMATE
		.BYTE	$18		; JMP_OBJ_ANIMATE
		.BYTE	$1E,$18		; SPR_IDX_SELECT
		.BYTE	$18		; JMP_OBJ_ANIMATE
		.BYTE	$18		; JMP_OBJ_ANIMATE
		.BYTE	$18		; JMP_OBJ_ANIMATE
		.BYTE	$05		; NJSR
		.WORD	_native_sub129
		.BYTE	$05		; NJSR
		.WORD	_native_sub14E
		.BYTE	$0E		; SBNE
		.WORD	byte_6B823
		.BYTE	$0A,$28		; LOOPB
		.WORD	byte_6B7F8
byte_6B80F:
		.BYTE	$1E,$34
		.BYTE	$18		; JMP_OBJ_ANIMATE
		.BYTE	$18		; JMP_OBJ_ANIMATE
		.BYTE	$18		; JMP_OBJ_ANIMATE
		.BYTE	$1E,$35		; SPR_IDX_SELECT
		.BYTE	$18		; JMP_OBJ_ANIMATE
		.BYTE	$18		; JMP_OBJ_ANIMATE
		.BYTE	$18		; JMP_OBJ_ANIMATE
		.BYTE	$05		; NJSR
		.WORD	_native_sub129
		.BYTE	$0A,$02		; LOOPB
		.WORD	byte_6B80F
		.BYTE	$06		; SJMP
		.WORD	byte_6B7F8
byte_6B823:
		.BYTE	$16
		.BYTE	$08		; RET
byte_6B825:
		.BYTE	$1E,$17
		.BYTE	$07		; SJSR
		.WORD	byte_6B82C
		.BYTE	$1E,$18		; SPR_IDX_SELECT
byte_6B82C:
		.BYTE	$03
		.WORD	_native_sub122
		.BYTE	$0A,$03		; LOOPB
		.WORD	byte_6B82C
		.BYTE	$08		; RET
_scr_cutscene00:
		.BYTE	$04,$01
		.WORD	_script154
		.BYTE	$02,$1E		; DELAY
		.BYTE	$04,$01		; RUN
		.WORD	_script155
byte_6B83E:
		.BYTE	$03
		.WORD	_native_sub064
		.BYTE	$09,$80		; LOOPA
		.WORD	byte_6B83E
		.BYTE	$0A,$02		; LOOPB
		.WORD	byte_6B83E
		.BYTE	$00		; STOP

; =============== S U B	R O U T	I N E =======================================
_native_sub064:
		LDA		#$01
		LDX		#$00
		JSR		_native_sub065
		LDA		#$02
		INX

; =============== S U B	R O U T	I N E =======================================
_native_sub065:
		CLC
		ADC		_ppu_scroll_shadow_lo,X
		STA		_ppu_scroll_shadow_lo,X
		LDA		_ppu_scroll_nt_hor,X
		ADC		#$00
		STA		_ppu_scroll_nt_hor,X
		RTS
_script155:
		.BYTE	$05
		.WORD	_native_sub134
		.BYTE	$25,$F8,$FF	; OBJ_SET_X_POS
		.BYTE	$26,$30,$00	; OBJ_SET_Y_POS
		.BYTE	$29,$08		; OBJ_SET_X_DELTA
		.BYTE	$23		; FLIP_40_TOGGLE
		.BYTE	$1B		; PARAM_80_CLEAR
byte_6B86D:
		.BYTE	$07
		.WORD	byte_6B8AC
		.BYTE	$09,$12		; LOOPA
		.WORD	byte_6B86D
		.BYTE	$07		; SJSR
		.WORD	byte_6B8A0
		.BYTE	$2A,$08		; OBJ_SET_Y_DELTA
		.BYTE	$07		; SJSR
		.WORD	byte_6B8AC
		.BYTE	$07		; SJSR
		.WORD	byte_6B8AC
		.BYTE	$07		; SJSR
		.WORD	byte_6B8A0
		.BYTE	$2A,$F8		; OBJ_SET_Y_DELTA
		.BYTE	$07		; SJSR
		.WORD	byte_6B8AC
		.BYTE	$07		; SJSR
		.WORD	byte_6B8AC
		.BYTE	$13,$12		; MOV
		.WORD	_pal_anim_mode_idx
		.BYTE	$04,$01		; RUN
		.WORD	_script156
		.BYTE	$29,$08		; OBJ_SET_X_DELTA
		.BYTE	$2A,$00		; OBJ_SET_Y_DELTA
byte_6B896:
		.BYTE	$07
		.WORD	byte_6B8AC
		.BYTE	$09,$1E		; LOOPA
		.WORD	byte_6B896
		.BYTE	$06		; SJMP
		.WORD	byte_6B6A6
byte_6B8A0:
		.BYTE	$29,$00
		.BYTE	$2A,$00		; OBJ_SET_Y_DELTA
byte_6B8A4:
		.BYTE	$07
		.WORD	byte_6B8AC
		.BYTE	$09,$04		; LOOPA
		.WORD	byte_6B8A4
		.BYTE	$08		; RET
byte_6B8AC:
		.BYTE	$1E,$19
		.BYTE	$07		; SJSR
		.WORD	_script_animate10
		.BYTE	$1E,$1A		; SPR_IDX_SELECT
		.BYTE	$06		; SJMP
		.WORD	_script_animate10
_script156:
		.BYTE	$17,$55
		.BYTE	$02,$30		; DELAY
		.BYTE	$06		; SJMP
		.WORD	_script156
_scr_cutscene01:
		.BYTE	$04,$01
		.WORD	_script154
		.BYTE	$26,$C0,$00	; OBJ_SET_Y_POS
		.BYTE	$31,$00		; TARGET_DIR_SET
		.BYTE	$04,$01		; RUN
		.WORD	_script157
		.BYTE	$03		; NJMP
		.WORD	_native_sub05E
		.BYTE	$02,$1E		; DELAY
		.BYTE	$3F		; MSG_DISPLAY
		.WORD	byte_39941
		.BYTE	$5B
		.BYTE	$40		; MSG_WAIT
		.BYTE	$07		; SJSR
		.WORD	byte_6B6CC
		.BYTE	$3F		; MSG_DISPLAY
		.WORD	byte_399A8
		.BYTE	$56
		.BYTE	$07		; SJSR
		.WORD	byte_6B6CC
		.BYTE	$31,$03		; TARGET_DIR_SET
		.BYTE	$04,$01		; RUN
		.WORD	_script158
		.BYTE	$03		; NJMP
		.WORD	_native_sub05E
		.BYTE	$07		; SJSR
		.WORD	byte_6B6CC
		.BYTE	$3F		; MSG_DISPLAY
		.WORD	byte_399B7
		.BYTE	$58
		.BYTE	$07		; SJSR
		.WORD	byte_6B6CC
		.BYTE	$31,$00		; TARGET_DIR_SET
		.BYTE	$3F		; MSG_DISPLAY
		.WORD	byte_399C3
		.BYTE	$56
		.BYTE	$07		; SJSR
		.WORD	byte_6B6CC
		.BYTE	$31,$03		; TARGET_DIR_SET
		.BYTE	$3F		; MSG_DISPLAY
		.WORD	byte_399ED
		.BYTE	$58
		.BYTE	$07		; SJSR
		.WORD	byte_6B6CC
		.BYTE	$31,$02		; TARGET_DIR_SET
		.BYTE	$26,$A0,$00	; OBJ_SET_Y_POS
		.BYTE	$04,$01		; RUN
		.WORD	_script159
		.BYTE	$03		; NJMP
		.WORD	_native_sub05E
		.BYTE	$31,$00		; TARGET_DIR_SET
		.BYTE	$3F		; MSG_DISPLAY
		.WORD	byte_39A14
		.BYTE	$56
		.BYTE	$07		; SJSR
		.WORD	byte_6B6CC
		.BYTE	$31,$03		; TARGET_DIR_SET
		.BYTE	$3F		; MSG_DISPLAY
		.WORD	byte_39A2B
		.BYTE	$58
		.BYTE	$07		; SJSR
		.WORD	byte_6B6CC
		.BYTE	$03		; NJMP
		.WORD	_native_sub05F
		.BYTE	$31,$02		; TARGET_DIR_SET
		.BYTE	$3F		; MSG_DISPLAY
		.WORD	byte_39A66
		.BYTE	$59
		.BYTE	$07		; SJSR
		.WORD	byte_6B6CC
		.BYTE	$03		; NJMP
		.WORD	_native_sub05F
		.BYTE	$31,$04		; TARGET_DIR_SET
		.BYTE	$04,$01		; RUN
		.WORD	_script15A
		.BYTE	$03		; NJMP
		.WORD	_native_sub05E
		.BYTE	$07		; SJSR
		.WORD	byte_6B6CC
		.BYTE	$3F		; MSG_DISPLAY
		.WORD	byte_39AB3
		.BYTE	$5A
		.BYTE	$40		; MSG_WAIT
		.BYTE	$03		; NJMP
		.WORD	_native_sub05F
		.BYTE	$31,$01		; TARGET_DIR_SET
		.BYTE	$26,$C0,$00	; OBJ_SET_Y_POS
		.BYTE	$04,$01		; RUN
		.WORD	_script15B
		.BYTE	$03		; NJMP
		.WORD	_native_sub05E
		.BYTE	$07		; SJSR
		.WORD	byte_6B6CC
		.BYTE	$31,$00		; TARGET_DIR_SET
		.BYTE	$3F		; MSG_DISPLAY
		.WORD	byte_39AC0
		.BYTE	$56
		.BYTE	$07		; SJSR
		.WORD	byte_6B6CC
		.BYTE	$31,$01		; TARGET_DIR_SET
		.BYTE	$07		; SJSR
		.WORD	byte_6B6CC
		.BYTE	$3F		; MSG_DISPLAY
		.WORD	byte_39AE0
		.BYTE	$57
		.BYTE	$07		; SJSR
		.WORD	byte_6B6CC
		.BYTE	$31,$00		; TARGET_DIR_SET
		.BYTE	$3F		; MSG_DISPLAY
		.WORD	byte_39B0A
		.BYTE	$56
		.BYTE	$07		; SJSR
		.WORD	byte_6B6CC
		.BYTE	$31,$01		; TARGET_DIR_SET
		.BYTE	$3F		; MSG_DISPLAY
		.WORD	byte_39B16
		.BYTE	$57
		.BYTE	$07		; SJSR
		.WORD	byte_6B6CC
		.BYTE	$3F		; MSG_DISPLAY
		.WORD	byte_39B2A
		.BYTE	$56
		.BYTE	$31,$00		; TARGET_DIR_SET
		.BYTE	$05		; NJSR
		.WORD	_native_sub05F
		.BYTE	$31,$01		; TARGET_DIR_SET
		.BYTE	$05		; NJSR
		.WORD	_native_sub05F
		.BYTE	$40		; MSG_WAIT
		.BYTE	$3F		; MSG_DISPLAY
		.WORD	byte_39B35
		.BYTE	$5B
		.BYTE	$40		; MSG_WAIT
		.BYTE	$06		; SJMP
		.WORD	byte_6B69F
_script157:
		.BYTE	$25,$B8,$00
		.BYTE	$1D,$01		; SPR_LIB_SELECT
		.BYTE	$1E,$1B		; SPR_IDX_SELECT
		.BYTE	$1B		; PARAM_80_CLEAR
		.BYTE	$07		; SJSR
		.WORD	byte_6B6C2
		.BYTE	$07		; SJSR
		.WORD	byte_6B750
		.BYTE	$07		; SJSR
		.WORD	byte_6B73A
		.BYTE	$07		; SJSR
		.WORD	byte_6B73A
		.BYTE	$07		; SJSR
		.WORD	byte_6B744
		.BYTE	$07		; SJSR
		.WORD	byte_6B73A
		.BYTE	$07		; SJSR
		.WORD	byte_6B73A
		.BYTE	$20		; FLIP_40_SET
		.BYTE	$29,$10		; OBJ_SET_X_DELTA
		.BYTE	$2A,$00		; OBJ_SET_Y_DELTA
		.BYTE	$07		; SJSR
		.WORD	byte_B7533
		.BYTE	$07		; SJSR
		.WORD	byte_B7533
		.BYTE	$00		; STOP
_script15B:
		.BYTE	$07
		.WORD	byte_6B734
		.BYTE	$20		; FLIP_40_SET
		.BYTE	$25,$D8,$FF	; OBJ_SET_X_POS
		.BYTE	$07		; SJSR
		.WORD	byte_6B76F
		.BYTE	$1D,$02		; SPR_LIB_SELECT
		.BYTE	$1B		; PARAM_80_CLEAR
		.BYTE	$29,$10		; OBJ_SET_X_DELTA
		.BYTE	$07		; SJSR
		.WORD	byte_B7533
		.BYTE	$07		; SJSR
		.WORD	byte_B7533
		.BYTE	$1E,$05		; SPR_IDX_SELECT
		.BYTE	$2A,$C0		; OBJ_SET_Y_DELTA
		.BYTE	$34,$01		; OBJ_SET_HP
		.BYTE	$07		; SJSR
		.WORD	byte_68036
		.BYTE	$07		; SJSR
		.WORD	byte_B7555
		.BYTE	$1E,$1B		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	byte_6B6C2
		.BYTE	$07		; SJSR
		.WORD	byte_6B75D
		.BYTE	$07		; SJSR
		.WORD	byte_6B73A
		.BYTE	$07		; SJSR
		.WORD	byte_6B73A
		.BYTE	$29,$00		; OBJ_SET_X_DELTA
		.BYTE	$2A,$10		; OBJ_SET_Y_DELTA
		.BYTE	$07		; SJSR
		.WORD	byte_68036
		.BYTE	$07		; SJSR
		.WORD	byte_B7555
		.BYTE	$29,$10		; OBJ_SET_X_DELTA
byte_6B9F5:
		.BYTE	$07
		.WORD	byte_B7533
		.BYTE	$09,$06		; LOOPA
		.WORD	byte_6B9F5
		.BYTE	$00		; STOP
_script158:
		.BYTE	$07
		.WORD	byte_6B734
		.BYTE	$20		; FLIP_40_SET
		.BYTE	$25,$F0,$FF	; OBJ_SET_X_POS
		.BYTE	$1B		; PARAM_80_CLEAR
		.BYTE	$29,$10		; OBJ_SET_X_DELTA
byte_6BA07:
		.BYTE	$07
		.WORD	byte_6B7A3
		.BYTE	$09,$04		; LOOPA
		.WORD	byte_6BA07
		.BYTE	$1E,$28		; SPR_IDX_SELECT
		.BYTE	$31,$00		; TARGET_DIR_SET
		.BYTE	$07		; SJSR
		.WORD	byte_6B773
		.BYTE	$07		; SJSR
		.WORD	byte_6B78D
		.BYTE	$07		; SJSR
		.WORD	byte_6B78D
		.BYTE	$07		; SJSR
		.WORD	byte_6B797
		.BYTE	$31,$00		; TARGET_DIR_SET
byte_6BA20:
		.BYTE	$07
		.WORD	byte_6B7A3
		.BYTE	$09,$06		; LOOPA
		.WORD	byte_6BA20
		.BYTE	$00		; STOP
_script159:
		.BYTE	$07
		.WORD	byte_6B734
		.BYTE	$20		; FLIP_40_SET
		.BYTE	$25,$B8,$FF	; OBJ_SET_X_POS
		.BYTE	$07		; SJSR
		.WORD	byte_6B76F
		.BYTE	$29,$10		; OBJ_SET_X_DELTA
		.BYTE	$1B		; PARAM_80_CLEAR
byte_6BA35:
		.BYTE	$07
		.WORD	byte_6B7DD
		.BYTE	$09,$04		; LOOPA
		.WORD	byte_6BA35
		.BYTE	$2A,$C0		; OBJ_SET_Y_DELTA
		.BYTE	$34,$01		; OBJ_SET_HP
		.BYTE	$07		; SJSR
		.WORD	byte_68036
		.BYTE	$1E,$1C		; SPR_IDX_SELECT
		.BYTE	$31,$00		; TARGET_DIR_SET
		.BYTE	$07		; SJSR
		.WORD	byte_6B7B7
		.BYTE	$07		; SJSR
		.WORD	byte_6B7D1
		.BYTE	$1E,$24		; SPR_IDX_SELECT
		.BYTE	$2A,$C0		; OBJ_SET_Y_DELTA
		.BYTE	$34,$01		; OBJ_SET_HP
		.BYTE	$07		; SJSR
		.WORD	byte_68036
byte_6BA56:
		.BYTE	$07
		.WORD	byte_6B7DD
		.BYTE	$09,$08		; LOOPA
		.WORD	byte_6BA56
		.BYTE	$00		; STOP
_script15A:
		.BYTE	$07
		.WORD	byte_6B734
		.BYTE	$20		; FLIP_40_SET
		.BYTE	$25,$F8,$FF	; OBJ_SET_X_POS
		.BYTE	$26,$80,$00	; OBJ_SET_Y_POS
		.BYTE	$1B		; PARAM_80_CLEAR
		.BYTE	$29,$10		; OBJ_SET_X_DELTA
byte_6BA6B:
		.BYTE	$07
		.WORD	byte_6B825
		.BYTE	$09,$1A		; LOOPA
		.WORD	byte_6BA6B
		.BYTE	$05		; NJSR
		.WORD	_native_sub139
		.BYTE	$07		; SJSR
		.WORD	byte_6B7F1
		.BYTE	$29,$10		; OBJ_SET_X_DELTA
byte_6BA7A:
		.BYTE	$07
		.WORD	byte_6B825
		.BYTE	$09,$1A		; LOOPA
		.WORD	byte_6BA7A
		.BYTE	$00		; STOP
_scr_cutscene02:
		.BYTE	$04,$01
		.WORD	_script154
		.BYTE	$26,$C0,$00	; OBJ_SET_Y_POS
		.BYTE	$31,$05		; TARGET_DIR_SET
		.BYTE	$04,$01		; RUN
		.WORD	_script15C
		.BYTE	$03		; NJMP
		.WORD	_native_sub05E
		.BYTE	$02,$1E		; DELAY
		.BYTE	$31,$00		; TARGET_DIR_SET
		.BYTE	$04,$01		; RUN
		.WORD	_script15D
		.BYTE	$03		; NJMP
		.WORD	_native_sub05E
		.BYTE	$31,$01		; TARGET_DIR_SET
		.BYTE	$04,$01		; RUN
		.WORD	_script15E
		.BYTE	$03		; NJMP
		.WORD	_native_sub05E
		.BYTE	$07		; SJSR
		.WORD	byte_6B6CC
		.BYTE	$3F		; MSG_DISPLAY
		.WORD	byte_39B6D
		.BYTE	$56
		.BYTE	$40		; MSG_WAIT
		.BYTE	$31,$05		; TARGET_DIR_SET
		.BYTE	$3F		; MSG_DISPLAY
		.WORD	byte_39B90
		.BYTE	$5C
		.BYTE	$07		; SJSR
		.WORD	byte_6B6CC
		.BYTE	$31,$01		; TARGET_DIR_SET
		.BYTE	$3F		; MSG_DISPLAY
		.WORD	byte_39BC1
		.BYTE	$57
		.BYTE	$03		; NJMP
		.WORD	_native_sub05F
		.BYTE	$40		; MSG_WAIT
		.BYTE	$31,$05		; TARGET_DIR_SET
		.BYTE	$3F		; MSG_DISPLAY
		.WORD	byte_39BD4
		.BYTE	$5C
		.BYTE	$07		; SJSR
		.WORD	byte_6B6CC
		.BYTE	$31,$00		; TARGET_DIR_SET
		.BYTE	$3F		; MSG_DISPLAY
		.WORD	byte_39C3A
		.BYTE	$56
		.BYTE	$40		; MSG_WAIT
		.BYTE	$31,$05		; TARGET_DIR_SET
		.BYTE	$3F		; MSG_DISPLAY
		.WORD	byte_39C4E
		.BYTE	$5C
		.BYTE	$07		; SJSR
		.WORD	byte_6B6CC
		.BYTE	$03		; NJMP
		.WORD	_native_sub05F
		.BYTE	$31,$00		; TARGET_DIR_SET
		.BYTE	$03		; NJMP
		.WORD	_native_sub05F
		.BYTE	$31,$01		; TARGET_DIR_SET
		.BYTE	$07		; SJSR
		.WORD	byte_6B6CC
		.BYTE	$06		; SJMP
		.WORD	byte_6B69F
_script15D:
		.BYTE	$1D,$01
		.BYTE	$25,$C0,$FF	; OBJ_SET_X_POS
		.BYTE	$07		; SJSR
		.WORD	byte_6BB08
		.BYTE	$06		; SJMP
		.WORD	byte_6BB1B
_script15E:
		.BYTE	$1D,$02
		.BYTE	$25,$A8,$FF	; OBJ_SET_X_POS
		.BYTE	$07		; SJSR
		.WORD	byte_6BB08
		.BYTE	$07		; SJSR
		.WORD	byte_B7547
		.BYTE	$2A,$00		; OBJ_SET_Y_DELTA
		.BYTE	$07		; SJSR
		.WORD	byte_6B6C2
		.BYTE	$06		; SJMP
		.WORD	byte_6BB1B
byte_6BB08:
		.BYTE	$07
		.WORD	byte_6B734
		.BYTE	$20		; FLIP_40_SET
		.BYTE	$29,$10		; OBJ_SET_X_DELTA
		.BYTE	$1B		; PARAM_80_CLEAR
byte_6BB0F:
		.BYTE	$07
		.WORD	byte_B7533
		.BYTE	$09,$04		; LOOPA
		.WORD	byte_6BB0F
		.BYTE	$1E,$00		; SPR_IDX_SELECT
		.BYTE	$06		; SJMP
		.WORD	byte_6B6C2
byte_6BB1B:
		.BYTE	$07
		.WORD	byte_B7533
		.BYTE	$09,$08		; LOOPA
		.WORD	byte_6BB1B
		.BYTE	$07		; SJSR
		.WORD	byte_6B6C2
_script15C:
		.BYTE	$25,$D0,$00
		.BYTE	$26,$90,$00	; OBJ_SET_Y_POS
		.BYTE	$1D,$08		; SPR_LIB_SELECT
		.BYTE	$1E,$15		; SPR_IDX_SELECT
		.BYTE	$1B		; PARAM_80_CLEAR
		.BYTE	$07		; SJSR
		.WORD	byte_6B6C2
		.BYTE	$34,$15		; OBJ_SET_HP
		.BYTE	$33,$16		; VAR_1C_SET
		.BYTE	$07		; SJSR
		.WORD	byte_6B708
		.BYTE	$07		; SJSR
		.WORD	byte_6B6C2
		.BYTE	$07		; SJSR
		.WORD	byte_6B708
		.BYTE	$07		; SJSR
		.WORD	byte_6B6C2
		.BYTE	$07		; SJSR
		.WORD	byte_6B708
		.BYTE	$07		; SJSR
		.WORD	byte_6B6C2
		.BYTE	$29,$10		; OBJ_SET_X_DELTA
		.BYTE	$20		; FLIP_40_SET
byte_6BB4C:
		.BYTE	$1E,$18
		.BYTE	$07		; SJSR
		.WORD	_script_animate12
		.BYTE	$1E,$20		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	_script_animate12
		.BYTE	$09,$03		; LOOPA
		.WORD	byte_6BB4C
		.BYTE	$00		; STOP
_scr_cutscene03:
		.BYTE	$04,$01
		.WORD	_script154
		.BYTE	$31,$00		; TARGET_DIR_SET
		.BYTE	$04,$01		; RUN
		.WORD	_script15F
		.BYTE	$05		; NJSR
		.WORD	_native_sub05E
		.BYTE	$31,$01		; TARGET_DIR_SET
		.BYTE	$04,$01		; RUN
		.WORD	_script160
		.BYTE	$05		; NJSR
		.WORD	_native_sub05E
		.BYTE	$02,$30		; DELAY
		.BYTE	$31,$00		; TARGET_DIR_SET
		.BYTE	$07		; SJSR
		.WORD	byte_6B6CC
		.BYTE	$3F		; MSG_DISPLAY
		.WORD	byte_39C62
		.BYTE	$56
		.BYTE	$07		; SJSR
		.WORD	byte_6B6CC
		.BYTE	$31,$03		; TARGET_DIR_SET
		.BYTE	$04,$01		; RUN
		.WORD	_script161
		.BYTE	$03		; NJMP
		.WORD	_native_sub05E
		.BYTE	$07		; SJSR
		.WORD	byte_6B6CC
		.BYTE	$31,$05		; TARGET_DIR_SET
		.BYTE	$04,$01		; RUN
		.WORD	_script162
		.BYTE	$03		; NJMP
		.WORD	_native_sub05E
		.BYTE	$31,$03		; TARGET_DIR_SET
		.BYTE	$3F		; MSG_DISPLAY
		.WORD	byte_39C74
		.BYTE	$58
		.BYTE	$07		; SJSR
		.WORD	byte_6B6CC
		.BYTE	$31,$01		; TARGET_DIR_SET
		.BYTE	$3F		; MSG_DISPLAY
		.WORD	byte_39CBB
		.BYTE	$57
		.BYTE	$07		; SJSR
		.WORD	byte_6B6CC
		.BYTE	$31,$03		; TARGET_DIR_SET
		.BYTE	$3F		; MSG_DISPLAY
		.WORD	byte_39CE0
		.BYTE	$58
		.BYTE	$07		; SJSR
		.WORD	byte_6B6CC
		.BYTE	$31,$01		; TARGET_DIR_SET
		.BYTE	$3F		; MSG_DISPLAY
		.WORD	byte_39CF0
		.BYTE	$57
		.BYTE	$07		; SJSR
		.WORD	byte_6B6CC
		.BYTE	$31,$03		; TARGET_DIR_SET
byte_6BBBA:
		.BYTE	$3F
		.WORD	byte_39CFB
		.BYTE	$58
		.BYTE	$07		; SJSR
		.WORD	byte_6B6CC
		.BYTE	$07		; SJSR
		.WORD	byte_6BC7C
		.BYTE	$03		; NJMP
		.WORD	_native_sub066
		.BYTE	$3F		; MSG_DISPLAY
		.WORD	byte_39D27
		.BYTE	$58
		.BYTE	$07		; SJSR
		.WORD	byte_6B6CC
		.BYTE	$07		; SJSR
		.WORD	byte_6BC7C
		.BYTE	$12		; SWITCH
		.WORD	_hor_menu_pos
		.WORD	byte_6BBE2
		.WORD	byte_6BBD8
byte_6BBD8:
		.BYTE	$13,$01
		.WORD	byte_E1
		.BYTE	$03		; NJMP
		.WORD	_native_sub05F
		.BYTE	$06		; SJMP
		.WORD	byte_6BBBA
byte_6BBE2:
		.BYTE	$3F
		.WORD	byte_39D38
		.BYTE	$58
		.BYTE	$07		; SJSR
		.WORD	byte_6B6CC
		.BYTE	$17,$4D		; APU_LOAD
		.BYTE	$02,$3C		; DELAY
		.BYTE	$12		; SWITCH
		.WORD	byte_E0
		.WORD	byte_6BBF4
		.WORD	byte_6BC47
byte_6BBF4:
		.BYTE	$17,$46
byte_6BBF6:
		.BYTE	$05
		.WORD	_native_sub068
		.BYTE	$2B		; OBJ_INC_X_DELTA
		.BYTE	$02,$04		; DELAY
		.BYTE	$09,$03		; LOOPA
		.WORD	byte_6BBF6
		.BYTE	$02,$10		; DELAY
		.BYTE	$31,$01		; TARGET_DIR_SET
		.BYTE	$03		; NJMP
		.WORD	_native_sub05F
byte_6BC07:
		.BYTE	$2D
		.BYTE	$05		; NJSR
		.WORD	_native_sub068
		.BYTE	$02,$04		; DELAY
		.BYTE	$09,$03		; LOOPA
		.WORD	byte_6BC07
		.BYTE	$03		; NJMP
		.WORD	_ppu_pal_apply
		.BYTE	$17,$13		; APU_LOAD
		.BYTE	$31,$03		; TARGET_DIR_SET
		.BYTE	$3F		; MSG_DISPLAY
		.WORD	byte_39D45
		.BYTE	$58
		.BYTE	$07		; SJSR
		.WORD	byte_6B6CC
		.BYTE	$3F		; MSG_DISPLAY
		.WORD	byte_39D51
		.BYTE	$58
		.BYTE	$07		; SJSR
		.WORD	byte_6B6CC
		.BYTE	$31,$00		; TARGET_DIR_SET
		.BYTE	$07		; SJSR
		.WORD	byte_6B6CC
		.BYTE	$3F		; MSG_DISPLAY
		.WORD	byte_39D6C
		.BYTE	$56
		.BYTE	$07		; SJSR
		.WORD	byte_6B6CC
		.BYTE	$31,$03		; TARGET_DIR_SET
		.BYTE	$3F		; MSG_DISPLAY
		.WORD	byte_39D7D
		.BYTE	$58
		.BYTE	$07		; SJSR
		.WORD	byte_6B6CC
		.BYTE	$31,$00		; TARGET_DIR_SET
		.BYTE	$3F		; MSG_DISPLAY
		.WORD	byte_39D8D
		.BYTE	$56
		.BYTE	$07		; SJSR
		.WORD	byte_6B6CC
		.BYTE	$06		; SJMP
		.WORD	byte_6BC5E
byte_6BC47:
		.BYTE	$3F
		.WORD	byte_39D9F
		.BYTE	$58
		.BYTE	$07		; SJSR
		.WORD	byte_6B6CC
		.BYTE	$31,$05		; TARGET_DIR_SET
		.BYTE	$03		; NJMP
		.WORD	_native_sub05F
		.BYTE	$02,$3C		; DELAY
		.BYTE	$31,$03		; TARGET_DIR_SET
		.BYTE	$3F		; MSG_DISPLAY
		.WORD	byte_39DB9
		.BYTE	$58
		.BYTE	$07		; SJSR
		.WORD	byte_6B6CC
byte_6BC5E:
		.BYTE	$31,$00
		.BYTE	$3F		; MSG_DISPLAY
		.WORD	byte_39DD0
		.BYTE	$56
		.BYTE	$07		; SJSR
		.WORD	byte_6B6CC
		.BYTE	$31,$03		; TARGET_DIR_SET
		.BYTE	$3F		; MSG_DISPLAY
		.WORD	byte_39E15
		.BYTE	$58
		.BYTE	$07		; SJSR
		.WORD	byte_6B6CC
		.BYTE	$31,$00		; TARGET_DIR_SET
		.BYTE	$3F		; MSG_DISPLAY
		.WORD	byte_39E3E
		.BYTE	$56
		.BYTE	$07		; SJSR
		.WORD	byte_6B6CC
		.BYTE	$06		; SJMP
		.WORD	byte_6B69F
byte_6BC7C:
		.BYTE	$05
		.WORD	_menu_init
		.BYTE	$3B		; DRAW_MENU_CURSOR
		.WORD	_menu_data01
byte_6BC82:
		.BYTE	$01
		.BYTE	$05		; NJSR
		.WORD	_native_sub102
		.BYTE	$11,$04,$C0	; TEST_PADS
		.WORD	byte_6BC93
		.BYTE	$17,$31		; APU_LOAD
		.BYTE	$05		; NJSR
		.WORD	_native_sub067
		.BYTE	$3B		; DRAW_MENU_CURSOR
		.WORD	_menu_data01
byte_6BC93:
		.BYTE	$11,$04,$01
		.WORD	byte_6BC82
		.BYTE	$17,$32		; APU_LOAD
		.BYTE	$08		; RET

; =============== S U B	R O U T	I N E =======================================
_native_sub066:
		LDA		_hor_menu_pos
		STA		byte_E0
		LDA		#$00
		STA		byte_E1
		RTS

; =============== S U B	R O U T	I N E =======================================
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

; =============== S U B	R O U T	I N E =======================================
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
_script15F:
		.BYTE	$07
		.WORD	byte_6B734
		.BYTE	$25,$1C,$01	; OBJ_SET_X_POS
		.BYTE	$26,$A0,$00	; OBJ_SET_Y_POS
		.BYTE	$1D,$01		; SPR_LIB_SELECT
		.BYTE	$1B		; PARAM_80_CLEAR
		.BYTE	$29,$F0		; OBJ_SET_X_DELTA
byte_6BCD9:
		.BYTE	$07
		.WORD	byte_B7533
		.BYTE	$09,$04		; LOOPA
		.WORD	byte_6BCD9
		.BYTE	$1E,$1B		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	byte_6B6C2
		.BYTE	$07		; SJSR
		.WORD	byte_6B73A
		.BYTE	$12		; SWITCH
		.WORD	byte_E0
		.WORD	byte_6BCEF
		.WORD	byte_6BCF9
byte_6BCEF:
		.BYTE	$07
		.WORD	byte_6B750
		.BYTE	$07		; SJSR
		.WORD	byte_6B73A
		.BYTE	$20		; FLIP_40_SET
		.BYTE	$07		; SJSR
		.WORD	byte_6B744
byte_6BCF9:
		.BYTE	$07
		.WORD	byte_6B73A
		.BYTE	$07		; SJSR
		.WORD	byte_6B73A
_script160:
		.BYTE	$07
		.WORD	byte_6B734
		.BYTE	$25,$10,$01	; OBJ_SET_X_POS
		.BYTE	$26,$90,$00	; OBJ_SET_Y_POS
		.BYTE	$1D,$02		; SPR_LIB_SELECT
		.BYTE	$1B		; PARAM_80_CLEAR
		.BYTE	$29,$F0		; OBJ_SET_X_DELTA
		.BYTE	$07		; SJSR
		.WORD	byte_B7533
		.BYTE	$07		; SJSR
		.WORD	byte_B7533
		.BYTE	$1E,$1B		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	byte_6B6C2
		.BYTE	$07		; SJSR
		.WORD	byte_6B73A
		.BYTE	$07		; SJSR
		.WORD	byte_6B73A
		.BYTE	$12		; SWITCH
		.WORD	byte_E0
		.WORD	byte_6BD25
		.WORD	byte_6BD2D
byte_6BD25:
		.BYTE	$07
		.WORD	byte_6B76F
		.BYTE	$05		; NJSR
		.WORD	_players_animB_sub0129_sub0E_A
		.BYTE	$1E,$0D		; SPR_IDX_SELECT
byte_6BD2D:
		.BYTE	$06
		.WORD	_script_idle
_script161:
		.BYTE	$07
		.WORD	byte_6B734
		.BYTE	$25,$F8,$FF	; OBJ_SET_X_POS
		.BYTE	$26,$C0,$00	; OBJ_SET_Y_POS
		.BYTE	$20		; FLIP_40_SET
		.BYTE	$1B		; PARAM_80_CLEAR
		.BYTE	$29,$10		; OBJ_SET_X_DELTA
byte_6BD3D:
		.BYTE	$07
		.WORD	byte_6B7A3
		.BYTE	$09,$04		; LOOPA
		.WORD	byte_6BD3D
		.BYTE	$1E,$28		; SPR_IDX_SELECT
		.BYTE	$31,$00		; TARGET_DIR_SET
		.BYTE	$07		; SJSR
		.WORD	byte_6B773
		.BYTE	$07		; SJSR
		.WORD	byte_6B78D
		.BYTE	$07		; SJSR
		.WORD	byte_6B78D
byte_6BD51:
		.BYTE	$07
		.WORD	byte_6B78D
		.BYTE	$07		; SJSR
		.WORD	byte_6B78D
		.BYTE	$12		; SWITCH
		.WORD	byte_E1
		.WORD	byte_6BD5E
		.WORD	byte_6BD51
byte_6BD5E:
		.BYTE	$07
		.WORD	byte_6B78D
		.BYTE	$12		; SWITCH
		.WORD	byte_E0
		.WORD	byte_6BD68
		.WORD	byte_6BD6B
byte_6BD68:
		.BYTE	$07
		.WORD	byte_6B78D
byte_6BD6B:
		.BYTE	$07
		.WORD	byte_6B78D
		.BYTE	$07		; SJSR
		.WORD	byte_6B78D
		.BYTE	$07		; SJSR
		.WORD	byte_6B78D
_script162:
		.BYTE	$25,$88,$00
		.BYTE	$26,$A0,$00	; OBJ_SET_Y_POS
		.BYTE	$1E,$38		; SPR_IDX_SELECT
		.BYTE	$1B		; PARAM_80_CLEAR
		.BYTE	$07		; SJSR
		.WORD	byte_6B6C2
		.BYTE	$17,$46		; APU_LOAD
byte_6BD82:
		.BYTE	$1E,$39
		.BYTE	$02,$06		; DELAY
		.BYTE	$1E,$3A		; SPR_IDX_SELECT
		.BYTE	$02,$06		; DELAY
		.BYTE	$09,$02		; LOOPA
		.WORD	byte_6BD82
		.BYTE	$1E,$3B		; SPR_IDX_SELECT
		.BYTE	$02,$06		; DELAY
		.BYTE	$00		; STOP
_scr_cutscene04:
		.BYTE	$04,$01
		.WORD	_script154
		.BYTE	$31,$00		; TARGET_DIR_SET
		.BYTE	$04,$01		; RUN
		.WORD	_script163
		.BYTE	$05		; NJSR
		.WORD	_native_sub05E
		.BYTE	$31,$01		; TARGET_DIR_SET
		.BYTE	$04,$01		; RUN
		.WORD	_script164
		.BYTE	$05		; NJSR
		.WORD	_native_sub05E
		.BYTE	$31,$02		; TARGET_DIR_SET
		.BYTE	$04,$01		; RUN
		.WORD	_script165
		.BYTE	$05		; NJSR
		.WORD	_native_sub05E
		.BYTE	$31,$04		; TARGET_DIR_SET
		.BYTE	$04,$01		; RUN
		.WORD	_script166
		.BYTE	$03		; NJMP
		.WORD	_native_sub05E
		.BYTE	$02,$1E		; DELAY
		.BYTE	$31,$01		; TARGET_DIR_SET
		.BYTE	$3F		; MSG_DISPLAY
		.WORD	byte_39E63
		.BYTE	$57
		.BYTE	$07		; SJSR
		.WORD	byte_6B6CC
		.BYTE	$04,$01		; RUN
		.WORD	_script167
		.BYTE	$02,$3C		; DELAY
		.BYTE	$3F		; MSG_DISPLAY
		.WORD	byte_39E8E
		.BYTE	$5A
		.BYTE	$40		; MSG_WAIT
		.BYTE	$31,$00		; TARGET_DIR_SET
		.BYTE	$3F		; MSG_DISPLAY
		.WORD	byte_39E9C
		.BYTE	$56
		.BYTE	$07		; SJSR
		.WORD	byte_6B6CC
		.BYTE	$31,$02		; TARGET_DIR_SET
		.BYTE	$3F		; MSG_DISPLAY
		.WORD	byte_39EB1
		.BYTE	$59
		.BYTE	$07		; SJSR
		.WORD	byte_6B6CC
		.BYTE	$31,$00		; TARGET_DIR_SET
		.BYTE	$3F		; MSG_DISPLAY
		.WORD	byte_39EE5
		.BYTE	$56
		.BYTE	$07		; SJSR
		.WORD	byte_6B6CC
		.BYTE	$3F		; MSG_DISPLAY
		.WORD	byte_39EF7
		.BYTE	$5A
		.BYTE	$40		; MSG_WAIT
		.BYTE	$3F		; MSG_DISPLAY
		.WORD	byte_39EFD
		.BYTE	$56
		.BYTE	$07		; SJSR
		.WORD	byte_6B6CC
		.BYTE	$06		; SJMP
		.WORD	byte_6B6A6
_script163:
		.BYTE	$20
		.BYTE	$25,$48,$00	; OBJ_SET_X_POS
		.BYTE	$26,$80,$00	; OBJ_SET_Y_POS
		.BYTE	$1D,$01		; SPR_LIB_SELECT
		.BYTE	$1B		; PARAM_80_CLEAR
		.BYTE	$07		; SJSR
		.WORD	byte_6B6C2
		.BYTE	$07		; SJSR
		.WORD	byte_6B73A
		.BYTE	$07		; SJSR
		.WORD	byte_6B73A
		.BYTE	$07		; SJSR
		.WORD	byte_6B744
_script164:
		.BYTE	$20
		.BYTE	$25,$30,$00	; OBJ_SET_X_POS
		.BYTE	$26,$80,$00	; OBJ_SET_Y_POS
		.BYTE	$1D,$02		; SPR_LIB_SELECT
		.BYTE	$1B		; PARAM_80_CLEAR
		.BYTE	$07		; SJSR
		.WORD	byte_6B6C2
		.BYTE	$07		; SJSR
		.WORD	byte_6B73A
_script165:
		.BYTE	$25,$80,$00
		.BYTE	$26,$D0,$00	; OBJ_SET_Y_POS
		.BYTE	$1B		; PARAM_80_CLEAR
		.BYTE	$1E,$1C		; SPR_IDX_SELECT
		.BYTE	$31,$00		; TARGET_DIR_SET
		.BYTE	$07		; SJSR
		.WORD	byte_6B7B7
		.BYTE	$20		; FLIP_40_SET
		.BYTE	$07		; SJSR
		.WORD	byte_6B7D1
_script166:
		.BYTE	$20
		.BYTE	$1B		; PARAM_80_CLEAR
		.BYTE	$25,$70,$00	; OBJ_SET_X_POS
		.BYTE	$26,$90,$00	; OBJ_SET_Y_POS
byte_6BE3B:
		.BYTE	$07
		.WORD	byte_6B7F1
		.BYTE	$06		; SJMP
		.WORD	byte_6BE3B
_script167:
		.BYTE	$07
		.WORD	byte_6B734
		.BYTE	$25,$10,$01	; OBJ_SET_X_POS
		.BYTE	$26,$B0,$00	; OBJ_SET_Y_POS
		.BYTE	$1E,$3C		; SPR_IDX_SELECT
		.BYTE	$1B		; PARAM_80_CLEAR
		.BYTE	$29,$F8		; OBJ_SET_X_DELTA
byte_6BE4F:
		.BYTE	$18
		.BYTE	$09,$80		; LOOPA
		.WORD	byte_6BE4F
		.BYTE	$00		; STOP
_scr_cutscene05:
		.BYTE	$04,$01
		.WORD	_script154
		.BYTE	$31,$00		; TARGET_DIR_SET
		.BYTE	$04,$01		; RUN
		.WORD	_script168
		.BYTE	$05		; NJSR
		.WORD	_native_sub05E
		.BYTE	$31,$01		; TARGET_DIR_SET
		.BYTE	$04,$01		; RUN
		.WORD	_script169
		.BYTE	$03		; NJMP
		.WORD	_native_sub05E
		.BYTE	$02,$3C		; DELAY
		.BYTE	$07		; SJSR
		.WORD	byte_6B6CC
		.BYTE	$3F		; MSG_DISPLAY
		.WORD	byte_39F25
		.BYTE	$56
		.BYTE	$40		; MSG_WAIT
		.BYTE	$17,$51		; APU_LOAD
		.BYTE	$02,$3C		; DELAY
		.BYTE	$3F		; MSG_DISPLAY
		.WORD	byte_39F56
		.BYTE	$57
		.BYTE	$40		; MSG_WAIT
byte_6BE7E:
		.BYTE	$07
		.WORD	byte_6BECE
		.BYTE	$03		; NJMP
		.WORD	_ppu_pal_apply
		.BYTE	$02,$10		; DELAY
		.BYTE	$07		; SJSR
		.WORD	byte_6BECE
		.BYTE	$03		; NJMP
		.WORD	_pal_patch03_load
		.BYTE	$02,$04		; DELAY
		.BYTE	$09,$05		; LOOPA
		.WORD	byte_6BE7E
		.BYTE	$02,$B4		; DELAY
		.BYTE	$06		; SJMP
		.WORD	byte_6B6A6
_scr_cutscene07:
		.BYTE	$04,$01
		.WORD	_script154
		.BYTE	$31,$00		; TARGET_DIR_SET
		.BYTE	$04,$01		; RUN
		.WORD	_script16A
		.BYTE	$05		; NJSR
		.WORD	_native_sub05E
		.BYTE	$31,$01		; TARGET_DIR_SET
		.BYTE	$04,$01		; RUN
		.WORD	_script16B
		.BYTE	$03		; NJMP
		.WORD	_native_sub05E
		.BYTE	$02,$3C		; DELAY
		.BYTE	$31,$01		; TARGET_DIR_SET
		.BYTE	$3F		; MSG_DISPLAY
		.WORD	byte_3A099
		.BYTE	$57
		.BYTE	$07		; SJSR
		.WORD	byte_6B6CC
		.BYTE	$31,$00		; TARGET_DIR_SET
		.BYTE	$3F		; MSG_DISPLAY
		.WORD	byte_3A0B2
		.BYTE	$56
		.BYTE	$07		; SJSR
		.WORD	byte_6B6CC
		.BYTE	$06		; SJMP
		.WORD	byte_6B69F
_scr_cutscene08:
		.BYTE	$02,$3C
		.BYTE	$3F		; MSG_DISPLAY
		.WORD	byte_3A0E1
		.BYTE	$5B
		.BYTE	$40		; MSG_WAIT
		.BYTE	$06		; SJMP
		.WORD	byte_6B69F
byte_6BECE:
		.BYTE	$31,$00
		.BYTE	$05		; NJSR
		.WORD	_native_sub05F
		.BYTE	$31,$01		; TARGET_DIR_SET
		.BYTE	$05		; NJSR
		.WORD	_native_sub05F
		.BYTE	$08		; RET

; =============== S U B	R O U T	I N E =======================================
_pal_patch03_load:
		LDA		#<[_pal_patch03]
		LDY		#>[_pal_patch03]
		JMP		_far_prg3_pal_patch_load
_script168:
		.BYTE	$1D,$01
		.BYTE	$25,$F0,$FF	; OBJ_SET_X_POS
		.BYTE	$06		; SJMP
		.WORD	byte_6BEED
_script169:
		.BYTE	$1D,$02
		.BYTE	$25,$D8,$FF	; OBJ_SET_X_POS
byte_6BEED:
		.BYTE	$1E,$20
		.BYTE	$07		; SJSR
		.WORD	byte_6B734
		.BYTE	$20		; FLIP_40_SET
		.BYTE	$26,$C0,$00	; OBJ_SET_Y_POS
		.BYTE	$29,$10		; OBJ_SET_X_DELTA
		.BYTE	$1B		; PARAM_80_CLEAR
byte_6BEF9:
		.BYTE	$07
		.WORD	_script_animate10
		.BYTE	$09,$10		; LOOPA
		.WORD	byte_6BEF9
		.BYTE	$07		; SJSR
		.WORD	byte_6B6C2
byte_6BF03:
		.BYTE	$07
		.WORD	byte_6B6C2
		.BYTE	$1E,$1B		; SPR_IDX_SELECT
		.BYTE	$07		; SJSR
		.WORD	byte_6B6C2
		.BYTE	$1E,$20		; SPR_IDX_SELECT
		.BYTE	$09,$05		; LOOPA
		.WORD	byte_6BF03
		.BYTE	$06		; SJMP
		.WORD	_script_idle
_script16A:
		.BYTE	$25,$70,$00
		.BYTE	$26,$C0,$00	; OBJ_SET_Y_POS
		.BYTE	$1D,$01		; SPR_LIB_SELECT
		.BYTE	$1E,$1B		; SPR_IDX_SELECT
		.BYTE	$20		; FLIP_40_SET
		.BYTE	$1B		; PARAM_80_CLEAR
		.BYTE	$07		; SJSR
		.WORD	byte_6B6C2
		.BYTE	$07		; SJSR
		.WORD	byte_6B744
		.BYTE	$07		; SJSR
		.WORD	byte_6B73A
_script16B:
		.BYTE	$25,$58,$00
		.BYTE	$26,$C0,$00	; OBJ_SET_Y_POS
		.BYTE	$1D,$02		; SPR_LIB_SELECT
		.BYTE	$1E,$1B		; SPR_IDX_SELECT
		.BYTE	$20		; FLIP_40_SET
		.BYTE	$1B		; PARAM_80_CLEAR
		.BYTE	$07		; SJSR
		.WORD	byte_6B6C2
		.BYTE	$07		; SJSR
		.WORD	byte_6B73A
_scr_cutscene06:
		.BYTE	$04,$01
		.WORD	_script154
		.BYTE	$02,$3C		; DELAY
		.BYTE	$3F		; MSG_DISPLAY
		.WORD	byte_39F6C
		.BYTE	$5D
		.BYTE	$40		; MSG_WAIT
		.BYTE	$3F		; MSG_DISPLAY
		.WORD	byte_39F99
		.BYTE	$57
		.BYTE	$40		; MSG_WAIT
		.BYTE	$3F		; MSG_DISPLAY
		.WORD	byte_39FA1
		.BYTE	$5D
		.BYTE	$40		; MSG_WAIT
		.BYTE	$3F		; MSG_DISPLAY
		.WORD	byte_39FB0
		.BYTE	$56
		.BYTE	$40		; MSG_WAIT
		.BYTE	$3F		; MSG_DISPLAY
		.WORD	byte_39FCF
		.BYTE	$5D
		.BYTE	$40		; MSG_WAIT
		.BYTE	$3F		; MSG_DISPLAY
		.WORD	byte_3A023
		.BYTE	$57
		.BYTE	$40		; MSG_WAIT
		.BYTE	$3F		; MSG_DISPLAY
		.WORD	byte_3A03C
		.BYTE	$5D
		.BYTE	$40		; MSG_WAIT
		.BYTE	$06		; SJMP
		.WORD	byte_6B6A6
_scr_cutscene09:
		.BYTE	$04,$01
		.WORD	_script154
		.BYTE	$04,$01		; RUN
		.WORD	_script16C
		.BYTE	$31,$00		; TARGET_DIR_SET
		.BYTE	$04,$01		; RUN
		.WORD	_script16D
		.BYTE	$05		; NJSR
		.WORD	_native_sub05E
		.BYTE	$31,$01		; TARGET_DIR_SET
		.BYTE	$04,$01		; RUN
		.WORD	_script16E
		.BYTE	$05		; NJSR
		.WORD	_native_sub05E
		.BYTE	$31,$02		; TARGET_DIR_SET
		.BYTE	$04,$01		; RUN
		.WORD	_script16F
		.BYTE	$03		; NJMP
		.WORD	_native_sub05E
		.BYTE	$02,$3C		; DELAY
		.BYTE	$31,$02		; TARGET_DIR_SET
		.BYTE	$3F		; MSG_DISPLAY
		.WORD	byte_3A101
		.BYTE	$59
		.BYTE	$07		; SJSR
		.WORD	byte_6B6CC
		.BYTE	$31,$00		; TARGET_DIR_SET
		.BYTE	$3F		; MSG_DISPLAY
		.WORD	byte_3A129
		.BYTE	$56
		.BYTE	$07		; SJSR
		.WORD	byte_6B6CC
		.BYTE	$31,$01		; TARGET_DIR_SET
		.BYTE	$07		; SJSR
		.WORD	byte_6B6CC
		.BYTE	$3F		; MSG_DISPLAY
		.WORD	byte_3A13C
		.BYTE	$57
		.BYTE	$07		; SJSR
		.WORD	byte_6B6CC
		.BYTE	$31,$00		; TARGET_DIR_SET
		.BYTE	$3F		; MSG_DISPLAY
		.WORD	byte_3A15B
		.BYTE	$56
		.BYTE	$07		; SJSR
		.WORD	byte_6B6CC
		.BYTE	$31,$01		; TARGET_DIR_SET
		.BYTE	$07		; SJSR
		.WORD	byte_6B6CC
		.BYTE	$31,$01		; TARGET_DIR_SET
		.BYTE	$3F		; MSG_DISPLAY
		.WORD	byte_3A17E
		.BYTE	$57
		.BYTE	$07		; SJSR
		.WORD	byte_6B6CC
		.BYTE	$06		; SJMP
		.WORD	byte_6B69F

		BANK_END 4,$C000
