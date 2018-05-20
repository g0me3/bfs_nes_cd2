;-------------C-O-N-S-T-A-N-T-S-----------------

DEBUG			EQU		0
OPTIMIZATION	EQU		1
BUGFIXES		EQU		1

LANG_EN			EQU		0
LANG_JP			EQU		1
LANR_RU			EQU		2

LANGUAGE		EQU		LANG_EN

;-------------------F-O-N-T---------------------

_0		EQU	$00
_1		EQU	$01
_2		EQU	$02
_3		EQU	$03
_4		EQU	$04
_5		EQU	$05
_6		EQU	$06
_7		EQU	$07
_8		EQU	$08
_9		EQU	$09

_exc	EQU	$0A
_apo	EQU	$0B
_col	EQU	$0C
_rar	EQU	$0E

_que	EQU	$0F
__		EQU	$10

_dot	EQU	$2C
_ddt	EQU	$31

_dsh	EQU	$40

_A		EQU	$11
_B		EQU	$12
_C		EQU	$13
_D		EQU	$14
_E		EQU	$15
_F		EQU	$16
_G		EQU	$17
_H		EQU	$18
_I		EQU	$19
_J		EQU	$1A
_K		EQU	$1B
_L		EQU	$1C
_M		EQU	$1D
_N		EQU	$1E
_O		EQU	$1F
_P		EQU	$20
_Q		EQU	$21
_R		EQU	$22
_S		EQU	$23
_T		EQU	$24
_U		EQU	$25
_V		EQU	$26
_W		EQU	$27
_X		EQU	$28
_Y		EQU	$29
_Z		EQU	$2A

_a		EQU	$36
_b		EQU	$37
_c		EQU	$38
_d		EQU	$39
_e		EQU	$3A
_f		EQU	$41
_g		EQU	$50
_h		EQU	$42
_i		EQU	$43
_j		EQU	$51
_k		EQU	$44
_l		EQU	$45
_m		EQU	$46
_n		EQU	$47
_o		EQU	$48
_p		EQU	$52
_q		EQU	$53
_r		EQU	$49
_s		EQU	$4A
_t		EQU	$3B
_u		EQU	$3C
_v		EQU	$3D
_w		EQU	$3E
_x		EQU	$3F
_y		EQU	$54
_z		EQU	$4B

_EOL	EQU	$FE

_WAIT	EQU	$FD
_RET	EQU	$FE
_STOP	EQU	$FF

	MAC		DICT_REC
{1}		SET		[[.-_dictionary]>>1]|$80
	.WORD	{1}_ptr
	ENDM

	MAC		DICT_DATA
{1}_ptr	SET		.
	ENDM

	MAC		SPR_LIB_IDX
{1}_idx	SET		[[.-_spr_lib_list]>>1]
	.WORD	{1}
	ENDM

	MAC		SPR_LIB_START
{1}		SET		.
SPR_LIB	SET		.
	ENDM

	MAC		SPR_IDX
{1}_idx	SET		[[.-SPR_LIB]>>1]
	.WORD	{1}
	ENDM

	MAC		APU_IDX
{1}_idx	SET		[[.-_apu_mus_lib]>>1]
	.WORD	{1}
	ENDM

;-----------G-A-M-E--S-P-E-C-I-F-I-C------------

	MAC	_CMD_IDX
{1}_idx	SET	[.-_scr_cmd_lib]>>1
	.WORD	{1}-1
	ENDM

; kill current script, stop execution
	MAC	KILL
#if DEBUG=1
_CNT_KILL	SET	_CNT_KILL+1
#endif
	.BYTE	_scr_cmd00_stop_idx
	ENDM

; exit current script, return control to the engine
; return back on the next frame
	MAC	SYNC
#if DEBUG=1
_CNT_SYNC	SET	_CNT_SYNC+1
#endif
	.BYTE	_scr_cmd01_sync_idx
	ENDM

; set script on hold for {1} frames
	MAC	SUSPEND
#if DEBUG=1
_CNT_SUSPEND	SET	_CNT_SUSPEND+1
#endif
	.BYTE	_scr_cmd02_suspend_idx
	.BYTE	{1}
	ENDM

; execute native code, then exit script, return control to the engine
	MAC	NJSR_SYNC
#if DEBUG=1
_CNT_NJSR_SYNC	SET	_CNT_NJSR_SYNC+1
#endif
	.BYTE	_scr_cmd03_ejsr_sync_idx
	.WORD	{1}
	ENDM

; queue new script and run it, {1} is the obj manager handler mode , {2}
; script pointer. note, all modes except 02 and 06 are the same simple
; script running modes but they differs in the program logic when handling
; collisions
;
; _OBJ_TYPE_AUTO		- general purpose global scripts with its own destructors
; _OBJ_TYPE_PLAYER		- only PLAYER objects
; _OBJ_TYPE_PBULLET		- objects used as projectiles by player
; _OBJ_TYPE_STUNA		- special kind anti-player stunning projectiles bouncing from enemy
; _OBJ_TYPE_BALL		- special object for basket game
; _OBJ_TYPE_ENEMY		- all harmless objects, including projectiles
; _OBJ_TYPE_EBULLET		- player damaging projectile
; _OBJ_TYPE_STUNB		- player stunning projectile
; _OBJ_TYPE_SOLID		- solid sprite objects, jumpable, throwable, harmless to player
; _OBJ_TYPE_TRIGGER		- harmless objects for collision test, disappear upon collision

; _OBJ_MODE_HIDE		- do not show object's sprite
; _OBJ_MODE_GRABABLE	- special flag for counting grabable objects for different ai handlers

; masks
_OBJ_TYPE_MASK		EQU	$0F
_OBJ_MODE_MASK		EQU	$F0
; types
_OBJ_TYPE_DISABLED	EQU	$00
_OBJ_TYPE_AUTO		EQU	$01
_OBJ_TYPE_PLAYER	EQU	$02
_OBJ_TYPE_PBULLET	EQU	$03
_OBJ_TYPE_STUNA		EQU	$04
_OBJ_TYPE_BALL		EQU	$05
_OBJ_TYPE_ENEMY		EQU	$06
_OBJ_TYPE_EBULLET	EQU	$07
_OBJ_TYPE_STUNB		EQU	$08
_OBJ_TYPE_SOLID		EQU	$09
_OBJ_TYPE_TRIGGER	EQU	$0A
;_OBJ_TYPE0B		EQU	$0B		; unused
;_OBJ_TYPE0C		EQU	$0C		; unused
;_OBJ_TYPE0D		EQU	$0D		; unused
;_OBJ_TYPE0E		EQU	$0E		; unused
;_OBJ_TYPE0F		EQU	$0F		; unused
; modes
_OBJ_MODE_HIDE		EQU	$80
_OBJ_MODE_GRABABLE	EQU	$40
;_OBJ_MODE20		EQU	$20		; unused
;_OBJ_MODE10		EQU	$10		; unused

	MAC	SRUN
#if DEBUG=1
_CNT_SRUN	SET	_CNT_SRUN+1
#endif
	.BYTE	_scr_cmd04_run_idx
	.BYTE	{1}
	.WORD	{2}
	ENDM

; execute native code, continue script operation
	MAC	NJSR
#if DEBUG=1
_CNT_NJSR	SET	_CNT_NJSR+1
#endif
	.BYTE	_scr_cmd05_ejsr_idx
	.WORD	{1}
	ENDM

	MAC	ASSERT_SHORT_OFS
#if DEBUG=1
TMP_CMD_PC	SET	.
TMP_OFS		SET	[{1}-TMP_CMD_PC-{2}]
	#if TMP_OFS<-128
		ECHO "long",{3},"at",TMP_CMD_PC,"jumps to",{1},"distance",TMP_OFS
	#endif
	#if TMP_OFS>127
		ECHO "long",{3},"at",TMP_CMD_PC,"jumps to",{1},"distance",TMP_OFS
	#endif
#endif
	ENDM

	MAC	ALERT_SHORT_OFS
#if DEBUG=1
TMP_CMD_PC	SET	.
TMP_OFS		SET	[{1}-TMP_CMD_PC-{2}]
	#if TMP_OFS>=-128&&TMP_OFS<=127
		ECHO "short",{3},"at",TMP_CMD_PC,"jumps to",{1},"distance",TMP_OFS
	#endif
#endif
	ENDM

; unconditional script branch
	MAC	SJMP
#if DEBUG=1
_CNT_SJMP	SET	_CNT_SJMP+1
#endif
	ALERT_SHORT_OFS		{1},3,"SJMP"
	.BYTE	_scr_cmd06_jmp_idx
	.WORD	{1}
	ENDM

	MAC	SJMPS
#if DEBUG=1
_CNT_SJMPS	SET	_CNT_SJMPS+1
#endif
#if OPTIMIZATION=1
	ASSERT_SHORT_OFS	{1},2,"SJMPS"
TMP_CMD_PC	SET	.
	.BYTE	_scr_cmd4A_jmp_short_idx
	.BYTE	[{1}-TMP_CMD_PC-2]&$FF
#else
	.BYTE	_scr_cmd06_jmp_idx
	.WORD	{1}
#endif
	ENDM

; call script subroutine (return with RET)
	MAC	SJSR
#if DEBUG=1
_CNT_SJSR	SET	_CNT_SJSR+1
#endif
#if OPTIMIZATION=1
	ALERT_SHORT_OFS		{1},3,"SJSR"
#endif
	.BYTE	_scr_cmd07_jsr_idx
	.WORD	{1}
	ENDM

	MAC	SJSRS
#if DEBUG=1
_CNT_SJSRS	SET	_CNT_SJSRS+1
#endif
#if OPTIMIZATION=1
	ASSERT_SHORT_OFS	{1},2,"SJSRS"
TMP_CMD_PC	SET	.
	.BYTE	_scr_cmd4B_jsr_short_idx
	.BYTE	[{1}-TMP_CMD_PC-2]&$FF
#else
	.BYTE	_scr_cmd07_jsr_idx
	.WORD	{1}
#endif
	ENDM

; return from script subroutine
	MAC	SRET
#if DEBUG=1
_CNT_SRET	SET	_CNT_SRET+1
#endif
	.BYTE	_scr_cmd08_ret_idx
	ENDM

; loop to script branch {1} times
	MAC	LOOP_A
#if DEBUG=1
_CNT_LOOP_A	SET	_CNT_LOOP_A+1
#endif
#if OPTIMIZATION=1
	ASSERT_SHORT_OFS	{2},3,"LOOP_A"
TMP_CMD_PC	SET	.
	.BYTE	_scr_cmd09_loopA_idx
	.BYTE	{1}
	.BYTE	[{2}-TMP_CMD_PC-3]&$FF
#else
	.BYTE	_scr_cmd09_loopA_idx
	.BYTE	{1}
	.WORD	{2}
#endif
	ENDM

; second loop operand
	MAC	LOOP_B
#if DEBUG=1
_CNT_LOOP_B	SET	_CNT_LOOP_B+1
#endif
#if OPTIMIZATION=1
	ASSERT_SHORT_OFS	{2},3,"LOOP_B"
TMP_CMD_PC	SET	.
	.BYTE	_scr_cmd0A_loopB_idx
	.BYTE	{1}
	.BYTE	[{2}-TMP_CMD_PC-3]&$FF
#else
	.BYTE	_scr_cmd0A_loopB_idx
	.BYTE	{1}
	.WORD	{2}
#endif
	ENDM

; helper branch macros
	MAC	SBRANCH
#if {3}=8
	ASSERT_SHORT_OFS	{1},2,"BRANCH"
TMP_CMD_PC	SET	.
	.BYTE	[_scr_cmd44_bne_short_idx+{2}]
	.BYTE	[{1}-TMP_CMD_PC-2]&$FF
#else
#if OPTIMIZATION=1
	ALERT_SHORT_OFS		{1},3,"BRANCH"
#endif
	.BYTE	[_scr_cmd0B_bne_idx+{2}]
	.WORD	{1}
#endif
	ENDM

; set of branches equivalent of 6502 set
; script if EQUAL branch
	MAC	SBNE
#if DEBUG=1
_CNT_SBNE	SET	_CNT_SBNE+1
#endif
		SBRANCH	{1},0,16
	ENDM

; script if CARRY=1 branch
	MAC	SBCC
#if DEBUG=1
_CNT_SBCC	SET	_CNT_SBCC+1
#endif
		SBRANCH	{1},1,16
	ENDM

; script if NEG=1 branch
	MAC	SBPL
#if DEBUG=1
_CNT_SBPL	SET	_CNT_SBPL+1
#endif
		SBRANCH	{1},2,16
	ENDM

; script if NO EQUAL branch
	MAC	SBEQ
#if DEBUG=1
_CNT_SBEQ	SET	_CNT_SBEQ+1
#endif
		SBRANCH	{1},3,16
	ENDM

; script if CARRY=0 branch
	MAC	SBCS
#if DEBUG=1
_CNT_SBCS	SET	_CNT_SBCS+1
#endif
		SBRANCH	{1},4,16
	ENDM

; script if NEG=0 branch
	MAC	SBMI
#if DEBUG=1
_CNT_SBMI	SET	_CNT_SBMI+1
#endif
		SBRANCH	{1},5,16
	ENDM

; set of 8-bit ofs branches
#if OPTIMIZATION=1
	MAC	SBNES
#if DEBUG=1
_CNT_SBNES	SET	_CNT_SBNES+1
#endif
		SBRANCH	{1},0,8
	ENDM

	MAC	SBCCS
#if DEBUG=1
_CNT_SBCCS	SET	_CNT_SBCCS+1
#endif
		SBRANCH	{1},1,8
	ENDM

	MAC	SBPLS
#if DEBUG=1
_CNT_SBPLS	SET	_CNT_SBPLS+1
#endif
		SBRANCH	{1},2,8
	ENDM

	MAC	SBEQS
#if DEBUG=1
_CNT_SBEQS	SET	_CNT_SBEQS+1
#endif
		SBRANCH	{1},3,8
	ENDM

	MAC	SBCSS
#if DEBUG=1
_CNT_SBCSS	SET	_CNT_SBCSS+1
#endif
		SBRANCH	{1},4,8
	ENDM

	MAC	SBMIS
#if DEBUG=1
_CNT_SBMIS	SET	_CNT_SBMIS+1
#endif
		SBRANCH	{1},5,8
	ENDM
#else
	MAC	SBNES
#if DEBUG=1
_CNT_SBNES	SET	_CNT_SBNES+1
#endif
		SBRANCH	{1},0,16
	ENDM

	MAC	SBCCS
#if DEBUG=1
_CNT_SBCCS	SET	_CNT_SBCCS+1
#endif
		SBRANCH	{1},1,16
	ENDM

	MAC	SBPLS
#if DEBUG=1
_CNT_SBPLS	SET	_CNT_SBPLS+1
#endif
		SBRANCH	{1},2,16
	ENDM

	MAC	SBEQS
#if DEBUG=1
_CNT_SBEQS	SET	_CNT_SBEQS+1
#endif
		SBRANCH	{1},3,16
	ENDM

	MAC	SBCSS
#if DEBUG=1
_CNT_SBCSS	SET	_CNT_SBCSS+1
#endif
		SBRANCH	{1},4,16
	ENDM

	MAC	SBMIS
#if DEBUG=1
_CNT_SBMIS	SET	_CNT_SBMIS+1
#endif
		SBRANCH	{1},5,16
	ENDM
#endif

; test pads pad offset {1}, mask {2}, default branch if zero - {3}

_PAD0_HELD	EQU	$00
_PAD1_HELD	EQU	$01
; only used option
_PAD0_PRESS	EQU $04
_PAD1_PRESS	EQU $05

_PAD_A		EQU	$01
_PAD_B		EQU	$02
_PAD_SELECT	EQU	$04
_PAD_START	EQU	$08
_PAD_UP		EQU	$10
_PAD_DOWN	EQU	$20
_PAD_LEFT	EQU	$40
_PAD_RIGHT	EQU	$80
_PAD_ANY	EQU	$FF

	MAC	PADS_TEST
#if DEBUG=1
_CNT_PADS_TEST	SET	_CNT_PADS_TEST+1
#endif
	.BYTE	_scr_cmd11_pads_test_idx
	.BYTE	{1},{2}
	.WORD	{3}
	ENDM

; switch case construction, {1} index ram variable, first branch default
	MAC	SSWITCH
#if DEBUG=1
_CNT_SSWITCH	SET	_CNT_SSWITCH+1
#endif
	.BYTE	_scr_cmd12_switch_idx
	.WORD	{1}
	ENDM

; lets make it nice
	MAC	SCASE
	.WORD	{1}
	ENDM

; store operand, put {1} into {2} ram address
	MAC	STORE
#if DEBUG=1
_CNT_STORE	SET	_CNT_STORE+1
#endif
	.BYTE	_scr_cmd13_store_idx
	.BYTE	{1}
	.WORD	{2}
	ENDM

; {1} chr bank idx, {2} value
	MAC	CHR_SET
#if DEBUG=1
_CNT_CHR_SET	SET	_CNT_CHR_SET+1
#endif
	.BYTE	_scr_cmd14_chr_set_idx
	.BYTE	{1},{2}
	ENDM

; reset loop counter for loop A
	MAC	LOOP_A_STOP
#if DEBUG=1
_CNT_LOOP_A_STOP	SET	_CNT_LOOP_A_STOP+1
#endif
	.BYTE	_scr_cmd15_loopA_reset_idx
	ENDM

; same for loop b
	MAC	LOOP_B_STOP
#if DEBUG=1
_CNT_LOOP_B_STOP	SET	_CNT_LOOP_B_STOP+1
#endif
	.BYTE	_scr_cmd16_loopB_reset_idx
	ENDM

; play MUS/SE, 00 = mute, 01-21 - music, 22-78 - se (22-74 only exising)
; 79-7F - are special codes

_APU_UNMUTE_idx			EQU	$79
_APU_MUTE_idx			EQU	$7A
_APU_MUS_FADE_OUT_idx	EQU	$7B
_APU_MUS_FADE_IN_idx	EQU	$7C		; never used, the fade-in routine unreferenced
_APU_MUS_STOP_idx		EQU	$7D		; never used, the complete stop used instead
_APU_SND_STOP_idx		EQU	$7E		; never used, the same as previous
_APU_ALL_STOP_idx		EQU	$7F

	MAC	APU_SE_SET
#if DEBUG=1
_CNT_APU_SE_SET	SET	_CNT_APU_SE_SET+1
#endif
	.BYTE	_scr_cmd17_apu_load_idx
	.BYTE	{1}_idx
	ENDM

; do animation and return to the engine
; sync to the next frame
	MAC	ANIMATE_HV_SYNC
#if DEBUG=1
_CNT_ANIMATE_HV_SYNC	SET	_CNT_ANIMATE_HV_SYNC+1
#endif
	.BYTE	_scr_cmd18_obj_animate_sync_idx
	ENDM

; same as previous but continue with the script execution
	MAC	ANIMATE_HV
#if DEBUG=1
_CNT_ANIMATE_HV	SET	_CNT_ANIMATE_HV+1
#endif
	.BYTE	_scr_cmd19_obj_animate_idx
	ENDM

; macro command for animating the flight objects locked on
; target (bats level 2, cards of cat boss, etc..)
	MAC	TARGET_FOLLOW
#if DEBUG=1
_CNT_TARGET_FOLLOW	SET	_CNT_TARGET_FOLLOW+1
#endif
	.BYTE	_scr_cmd1A_target_follow_idx
	ENDM

; usually set if object is deactivated
	MAC	SPRITE_ON
#if DEBUG=1
_CNT_SPRITE_ON	SET	_CNT_SPRITE_ON+1
#endif
	.BYTE	_scr_cmd1C_obj_show_idx
	ENDM

; deactivate
	MAC	SPRITE_OFF
#if DEBUG=1
_CNT_SPRITE_OFF	SET	_CNT_SPRITE_OFF+1
#endif
	.BYTE	_scr_cmd1C_obj_hide_idx
	ENDM

; select sprite library for object
	MAC	SPR_LIB_SET
#if DEBUG=1
_CNT_SPR_LIB_SET	SET	_CNT_SPR_LIB_SET+1
#endif
	.BYTE	_scr_cmd1D_spr_lib_select_idx
	.BYTE	{1}_idx
	ENDM

; select current sprite idx as integer value
	MAC	SPR_IDX_INT_SET
#if DEBUG=1
_CNT_SPR_IDX_INT_SET	SET	_CNT_SPR_IDX_INT_SET+1
#endif
	.BYTE	_scr_cmd1E_spr_idx_select_idx
	.BYTE	{1}
	ENDM

; the same using the mnemonic
	MAC	SPR_IDX_SET
#if DEBUG=1
_CNT_SPR_IDX_SET	SET	_CNT_SPR_IDX_SET+1
#endif
	.BYTE	_scr_cmd1E_spr_idx_select_idx
	.BYTE	{1}_idx
	ENDM

; one of hor/vert sprite flipping flags
; flips flags:

_OBJ_FLIP_V		EQU	$80
_OBJ_FLIP_H		EQU	$40
_OBJ_UNDER_BG	EQU	$20
_OBJ_BLINK		EQU	$10
_OBJ_FLIPS08	EQU	$08
_OBJ_FLIPS04	EQU	$04
;_OBJ_FLIPS02	EQU	$02	; unused
;_OBJ_FLIPS01	EQU	$01	; unused

	MAC	FLIP_H_OFF
#if DEBUG=1
_CNT_FLIP_H_OFF	SET	_CNT_FLIP_H_OFF+1
#endif
	.BYTE	_scr_cmd1F_hflip_clear_idx
	ENDM

; same
	MAC	FLIP_H_ON
#if DEBUG=1
_CNT_FLIP_H_ON	SET	_CNT_FLIP_H_ON+1
#endif
	.BYTE	_scr_cmd1F_hflip_set_idx
	ENDM

; same
	MAC	FLIP_V_OFF
#if DEBUG=1
_CNT_FLIP_V_OFF	SET	_CNT_FLIP_V_OFF+1
#endif
	.BYTE	_scr_cmd21_vflip_clear_idx
	ENDM

; same
	MAC	FLIP_V_ON
#if DEBUG=1
_CNT_FLIP_V_ON	SET	_CNT_FLIP_V_ON+1
#endif
	.BYTE	_scr_cmd21_vflip_set_idx
	ENDM

; similar but toggles
	MAC	FLIP_H_TOGGLE
#if DEBUG=1
_CNT_FLIP_H_TOGGLE	SET	_CNT_FLIP_H_TOGGLE+1
#endif
	.BYTE	_scr_cmd23_hflip_toggle_idx
	ENDM

; same
	MAC	FLIP_V_TOGGLE
#if DEBUG=1
_CNT_FLIP_V_TOGGLE	SET	_CNT_FLIP_V_TOGGLE+1
#endif
	.BYTE	_scr_cmd23_vflip_toggle_idx
	ENDM

; xpos is always 16-bit for clipping
	MAC	POS_X_SET
#if DEBUG=1
_CNT_POS_X_SET	SET	_CNT_POS_X_SET+1
#endif
	.BYTE	_scr_cmd25_obj_set_x_pos_idx
	.BYTE	{1},{2}
	ENDM

; same for Y
	MAC	POS_Y_SET
#if DEBUG=1
_CNT_POS_Y_SET	SET	_CNT_POS_Y_SET+1
#endif
	.BYTE	_scr_cmd26_obj_set_y_pos_idx
	.BYTE	{1},{2}
	ENDM

; add value to object's X position
	MAC	POS_X_MOVE
#if DEBUG=1
_CNT_POS_X_MOVE	SET	_CNT_POS_X_MOVE+1
#endif
	.BYTE	_scr_cmd27_obj_move_x_pos_idx
	.BYTE	{1}
	ENDM

; same for Y
	MAC	POS_Y_MOVE
#if DEBUG=1
_CNT_POS_Y_MOVE	SET	_CNT_POS_Y_MOVE+1
#endif
	.BYTE	_scr_cmd28_obj_move_y_pos_idx
	.BYTE	{0}
	ENDM

; set constant movement delta for X
	MAC	DELTA_X_SET
#if DEBUG=1
_CNT_DELTA_X_SET	SET	_CNT_DELTA_X_SET+1
#endif
	.BYTE	_scr_cmd29_obj_set_x_delta_idx
	.BYTE	{0}
	ENDM

; same for Y
	MAC	DELTA_Y_SET
#if DEBUG=1
_CNT_DELTA_Y_SET	SET	_CNT_DELTA_Y_SET+1
#endif
	.BYTE	_scr_cmd2A_obj_set_y_delta_idx
	.BYTE	{0}
	ENDM

; does some kind of acceleration, low nibble of delta
; added to x position with carry
	MAC	DELTA_X_INC
#if DEBUG=1
_CNT_DELTA_X_INC	SET	_CNT_DELTA_X_INC+1
#endif
	.BYTE	_scr_cmd2B_obj_inc_x_delta_idx
	ENDM

; same for Y
	MAC	DELTA_Y_INC
#if DEBUG=1
_CNT_DELTA_Y_INC	SET	_CNT_DELTA_Y_INC+1
#endif
	.BYTE	_scr_cmd2C_obj_inc_y_delta_idx
	ENDM

; same but with decrease
	MAC	DELTA_X_DEC
#if DEBUG=1
_CNT_DELTA_X_DEC	SET	_CNT_DELTA_X_DEC+1
#endif
	.BYTE	_scr_cmd2D_obj_dec_x_delta_idx
	ENDM

; same for Y
	MAC	DELTA_Y_DEC
#if DEBUG=1
_CNT_DELTA_Y_DEC	SET	_CNT_DELTA_Y_DEC+1
#endif
	.BYTE	_scr_cmd2E_dec_y_delta_idx
	ENDM

; init object lock on target, {1} usually direction of target
	MAC	TARGET_LOCK
#if DEBUG=1
_CNT_TARGET_LOCK	SET	_CNT_TARGET_LOCK+1
#endif
	.BYTE	_scr_cmd2F_target_lock_idx
	.BYTE	{1}
	ENDM

; set speed for traveling to target or some kind...
	MAC	TIMER_A_SET
#if DEBUG=1
_CNT_TIMER_A_SET	SET	_CNT_TIMER_A_SET+1
#endif
	.BYTE	_scr_cmd30_obj_timerAs_set_idx
	.BYTE	{1}
	ENDM

; other direction value for target lock
	MAC	TIMER_B_SET
#if DEBUG=1
_CNT_TIMER_B_SET	SET	_CNT_TIMER_B_SET+1
#endif
	.BYTE	_scr_cmd31_obj_timerBs_set_idx
	.BYTE	{1}
	ENDM

; set object dimensions for collision tests
	MAC	SIZE_SET
#if DEBUG=1
_CNT_SIZE_SET	SET	_CNT_SIZE_SET+1
#endif
	.BYTE	_scr_cmd32_obj_set_size_idx
	.BYTE	{1},{2}
	ENDM

; object damage type set. NOTE, that for cutscene scripts
; this variable utilized differently as one of the tmp
; counters
;
_OBJ_DMG_NONE	EQU	$00
_OBJ_DMG_KILL	EQU	$01
_OBJ_DMG_STUN	EQU	$02

	MAC	DAMAGE_SET
#if DEBUG=1
_CNT_DAMAGE_SET	SET	_CNT_DAMAGE_SET+1
#endif
	.BYTE	_scr_cmd33_damage_set_idx
	.BYTE	{1}
	ENDM

; define object's hitpoints. hp should be set even for undestructable
; objects because they threated as a existence of the object itself
; rather than activeness state flag
; NOTE, this var also used differently for cutscenes
	MAC	HP_SET
#if DEBUG=1
_CNT_HP_SET	SET	_CNT_HP_SET+1
#endif
	.BYTE	_scr_cmd34_obj_set_hp_idx
	.BYTE	{1}
	ENDM

; set the vert/hor flips for object instantly
	MAC	FLIPS_SET
#if DEBUG=1
_CNT_FLIPS_SET	SET	_CNT_FLIPS_SET+1
#endif
	.BYTE	_scr_cmd35_obj_flips_set_idx
	.BYTE	{1}
	ENDM

; unused flag settings
	MAC	IDXC_SET
#if DEBUG=1
_CNT_IDXC_SET	SET	_CNT_IDXC_SET+1
#endif
	.BYTE	_scr_cmd36_idxCs_set_idx
	.BYTE	{1}
	ENDM

; they used MOV operands here for some reasons...
	MAC	MAIN_SUB_SET
#if DEBUG=1
_CNT_MAIN_SUB_SET	SET	_CNT_MAIN_SUB_SET+1
#endif
	.BYTE	_scr_cmd37_main_sub_idx_set_idx
	.BYTE	{1}
	ENDM

; yes, it is parameters are speed and increment value
	MAC	PAL_FADE_IN
#if DEBUG=1
_CNT_PAL_FADE_IN	SET	_CNT_PAL_FADE_IN+1
#endif
	.BYTE	_scr_cmd38_pal_fade_in_idx
	.BYTE	{1},{2}
	ENDM

; same
	MAC	PAL_FADE_OUT
#if DEBUG=1
_CNT_PAL_FADE_OUT	SET	_CNT_PAL_FADE_OUT+1
#endif
	.BYTE	_scr_cmd39_pal_fade_out_idx
	.BYTE	{1},{2}
	ENDM

; never used, always used native handlers instead
	MAC	TLM_RES_QUEUE
#if DEBUG=1
_CNT_TLM_RES_QUEUE	SET	_CNT_TLM_RES_QUEUE+1
#endif
	.BYTE	_scr_cmd3A_tlm_res_queue_idx
	.WORD	{1}
	ENDM

; yes, it is, parameter is an offset to menu data (options position and number)
	MAC	MENU_CURSOR_DRAW
#if DEBUG=1
_CNT_MENU_CURSOR_DRAW	SET	_CNT_MENU_CURSOR_DRAW+1
#endif
	.BYTE	_scr_cmd3B_draw_menu_cursor_idx
	.WORD	{1}
	ENDM

; never used, all menus are vertically oriented
	MAC	MENU_HOR_INPUT
#if DEBUG=1
_CNT_MENU_HOR_INPUT	SET	_CNT_MENU_HOR_INPUT+1
#endif
	.BYTE	_scr_cmd3C_hor_menu_input_idx
	.BYTE	{1},{2}
	ENDM

; same for vert menu, parameters are number of items in menu and default one
	MAC	MENU_VERT_INPUT
#if DEBUG=1
_CNT_MENU_VERT_INPUT	SET	_CNT_MENU_VERT_INPUT+1
#endif
	.BYTE	_scr_cmd3D_vert_menu_input_idx
	.BYTE	{1},{2}
	ENDM

; never used, msg area always the same and hardcoded in msg init routine
	MAC	MSG_AREA_SET
#if DEBUG=1
_CNT_MSG_AREA_SET	SET	_CNT_MSG_AREA_SET+1
#endif
	.BYTE	_scr_cmd3E_msg_area_set_idx
	.WORD	{1}
	.BYTE	{2}
	ENDM

; displays the message in already defined window, {1} ptr to msg resource
; {2} is the APU SE index to make typing sound for every character
	MAC	MSG_DISPLAY
#if DEBUG=1
_CNT_MSG_DISPLAY	SET	_CNT_MSG_DISPLAY+1
#endif
	.BYTE	_scr_cmd3F_msg_display_idx
	.WORD	{1}
	.BYTE	{2}_idx
	ENDM

; wait until message is displayed
	MAC	MSG_WAIT
#if DEBUG=1
_CNT_MSG_WAIT	SET	_CNT_MSG_WAIT+1
#endif
	.BYTE	_scr_cmd40_msg_wait_idx
	ENDM

; break current subroutine and exit instantly, argument is return address
	MAC	BREAK
#if DEBUG=1
_CNT_BREAK	SET	_CNT_BREAK+1
#endif
	.BYTE	_scr_cmd41_break_idx
	.WORD	{1}
	ENDM

; set default script routine for object when destroyed or collision detected
; called from object manager instantly if collision test passed
;
	MAC	DESTR_PC_SET
#if DEBUG=1
_CNT_DESTR_PC_SET	SET	_CNT_DESTR_PC_SET+1
#endif
	.BYTE	_scr_cmd42_destr_pc_set_idx
	.WORD	{1}
	ENDM

; other flags set cmd
	MAC	GRABABLE_ON
#if DEBUG=1
_CNT_GRABABLE_ON	SET	_CNT_GRABABLE_ON+1
#endif
	.BYTE	_scr_cmd43_obj_grabable_idx
	ENDM

	MAC	DEBUG_LOG_INIT
#if DEBUG=1
_CNT_APU_SE_SET	SET	0
_CNT_BREAK	SET	0
_CNT_CHR_SET	SET	0
_CNT_DESTR_PC_SET	SET	0
_CNT_FLIP_H_OFF	SET	0
_CNT_FLIP_H_ON	SET	0
_CNT_FLIP_H_TOGGLE	SET	0
_CNT_FLIP_V_OFF	SET	0
_CNT_FLIP_V_ON	SET	0
_CNT_FLIP_V_TOGGLE	SET	0
_CNT_KILL	SET	0
_CNT_LOOP_A	SET	0
_CNT_LOOP_A_STOP	SET	0
_CNT_LOOP_B	SET	0
_CNT_LOOP_B_STOP	SET	0
_CNT_MAIN_SUB_SET	SET	0
_CNT_MENU_CURSOR_DRAW	SET	0
_CNT_MENU_HOR_INPUT	SET	0
_CNT_MENU_VERT_INPUT	SET	0
_CNT_MSG_AREA_SET	SET	0
_CNT_MSG_DISPLAY	SET	0
_CNT_MSG_WAIT	SET	0
_CNT_NJSR	SET	0
_CNT_NJSR_SYNC	SET	0
_CNT_ANIMATE_HV	SET	0
_CNT_ANIMATE_HV_SYNC	SET	0
_CNT_DAMAGE_SET	SET	0
_CNT_FLIPS_SET	SET	0
_CNT_IDXC_SET	SET	0
_CNT_HP_SET	SET	0
_CNT_SIZE_SET	SET	0
_CNT_DELTA_X_DEC	SET	0
_CNT_DELTA_X_INC	SET	0
_CNT_DELTA_X_SET	SET	0
_CNT_POS_X_MOVE	SET	0
_CNT_POS_X_SET	SET	0
_CNT_DELTA_Y_DEC	SET	0
_CNT_DELTA_Y_INC	SET	0
_CNT_DELTA_Y_SET	SET	0
_CNT_POS_Y_MOVE	SET	0
_CNT_POS_Y_SET	SET	0
_CNT_PADS_TEST	SET	0
_CNT_PAL_FADE_IN	SET	0
_CNT_PAL_FADE_OUT	SET	0
_CNT_GRABABLE_ON	SET	0
_CNT_SPRITE_ON	SET	0
_CNT_SPRITE_OFF	SET	0
_CNT_SBCC	SET	0
_CNT_SBCCS	SET	0
_CNT_SBCCS	SET	0
_CNT_SBCS	SET	0
_CNT_SBCSS	SET	0
_CNT_SBCSS	SET	0
_CNT_SBEQ	SET	0
_CNT_SBEQS	SET	0
_CNT_SBEQS	SET	0
_CNT_SBMI	SET	0
_CNT_SBMIS	SET	0
_CNT_SBMIS	SET	0
_CNT_SBNE	SET	0
_CNT_SBNES	SET	0
_CNT_SBNES	SET	0
_CNT_SBPL	SET	0
_CNT_SBPLS	SET	0
_CNT_SBPLS	SET	0
_CNT_SJMP	SET	0
_CNT_SJMPS	SET	0
_CNT_SJSR	SET	0
_CNT_SJSRS	SET	0
_CNT_SPR_IDX_INT_SET	SET	0
_CNT_SPR_IDX_SET	SET	0
_CNT_SPR_LIB_SET	SET	0
_CNT_SRET	SET	0
_CNT_SRUN	SET	0
_CNT_SSWITCH	SET	0
_CNT_STORE	SET	0
_CNT_SUSPEND	SET	0
_CNT_SYNC	SET	0
_CNT_TIMER_B_SET	SET	0
_CNT_TARGET_FOLLOW	SET	0
_CNT_TARGET_LOCK	SET	0
_CNT_TIMER_A_SET	SET	0
_CNT_TLM_RES_QUEUE	SET	0
#endif
	ENDM

	MAC	DEBUG_LOG_PRINT
#if DEBUG=1
		ECHO " DEBUG STATS "
		ECHO "-------------"
		ECHO ""
		ECHO "_CNT_APU_SE_SET=",_CNT_APU_SE_SET
		ECHO "_CNT_BREAK=",_CNT_BREAK
		ECHO "_CNT_CHR_SET=",_CNT_CHR_SET
		ECHO "_CNT_DESTR_PC_SET=",_CNT_DESTR_PC_SET
		ECHO "_CNT_FLIP_H_OFF=",_CNT_FLIP_H_OFF
		ECHO "_CNT_FLIP_H_ON=",_CNT_FLIP_H_ON
		ECHO "_CNT_FLIP_H_TOGGLE=",_CNT_FLIP_H_TOGGLE
		ECHO "_CNT_FLIP_V_OFF=",_CNT_FLIP_V_OFF
		ECHO "_CNT_FLIP_V_ON=",_CNT_FLIP_V_ON
		ECHO "_CNT_FLIP_V_TOGGLE=",_CNT_FLIP_V_TOGGLE
		ECHO "_CNT_KILL=",_CNT_KILL
		ECHO "_CNT_LOOP_A=",_CNT_LOOP_A
		ECHO "_CNT_LOOP_A_STOP=",_CNT_LOOP_A_STOP
		ECHO "_CNT_LOOP_B=",_CNT_LOOP_B
		ECHO "_CNT_LOOP_B_STOP=",_CNT_LOOP_B_STOP
		ECHO "_CNT_MAIN_SUB_SET=",_CNT_MAIN_SUB_SET
		ECHO "_CNT_MENU_CURSOR_DRAW=",_CNT_MENU_CURSOR_DRAW
		ECHO "_CNT_MENU_HOR_INPUT=",_CNT_MENU_HOR_INPUT
		ECHO "_CNT_MENU_VERT_INPUT=",_CNT_MENU_VERT_INPUT
		ECHO "_CNT_MSG_AREA_SET=",_CNT_MSG_AREA_SET
		ECHO "_CNT_MSG_DISPLAY=",_CNT_MSG_DISPLAY
		ECHO "_CNT_MSG_WAIT=",_CNT_MSG_WAIT
		ECHO "_CNT_NJSR=",_CNT_NJSR
		ECHO "_CNT_NJSR_SYNC=",_CNT_NJSR_SYNC
		ECHO "_CNT_ANIMATE_HV=",_CNT_ANIMATE_HV
		ECHO "_CNT_ANIMATE_HV_SYNC=",_CNT_ANIMATE_HV_SYNC
		ECHO "_CNT_DAMAGE_SET=",_CNT_DAMAGE_SET
		ECHO "_CNT_FLIPS_SET=",_CNT_FLIPS_SET
		ECHO "_CNT_HP_SET=",_CNT_HP_SET
		ECHO "_CNT_IDXC_SET=",_CNT_IDXC_SET
		ECHO "_CNT_SIZE_SET=",_CNT_SIZE_SET
		ECHO "_CNT_DELTA_X_DEC=",_CNT_DELTA_X_DEC
		ECHO "_CNT_DELTA_X_INC=",_CNT_DELTA_X_INC
		ECHO "_CNT_DELTA_X_SET=",_CNT_DELTA_X_SET
		ECHO "_CNT_POS_X_MOVE=",_CNT_POS_X_MOVE
		ECHO "_CNT_POS_X_SET=",_CNT_POS_X_SET
		ECHO "_CNT_DELTA_Y_DEC=",_CNT_DELTA_Y_DEC
		ECHO "_CNT_DELTA_Y_INC=",_CNT_DELTA_Y_INC
		ECHO "_CNT_DELTA_Y_SET=",_CNT_DELTA_Y_SET
		ECHO "_CNT_POS_Y_MOVE=",_CNT_POS_Y_MOVE
		ECHO "_CNT_POS_Y_SET=",_CNT_POS_Y_SET
		ECHO "_CNT_PADS_TEST=",_CNT_PADS_TEST
		ECHO "_CNT_PAL_FADE_IN=",_CNT_PAL_FADE_IN
		ECHO "_CNT_PAL_FADE_OUT=",_CNT_PAL_FADE_OUT
		ECHO "_CNT_GRABABLE_ON=",_CNT_GRABABLE_ON
		ECHO "_CNT_SPRITE_ON=",_CNT_SPRITE_ON
		ECHO "_CNT_SPRITE_OFF=",_CNT_SPRITE_OFF
		ECHO "_CNT_SBCC=",_CNT_SBCC
		ECHO "_CNT_SBCCS=",_CNT_SBCCS
		ECHO "_CNT_SBCS=",_CNT_SBCS
		ECHO "_CNT_SBCSS=",_CNT_SBCSS
		ECHO "_CNT_SBEQ=",_CNT_SBEQ
		ECHO "_CNT_SBEQS=",_CNT_SBEQS
		ECHO "_CNT_SBMI=",_CNT_SBMI
		ECHO "_CNT_SBMIS=",_CNT_SBMIS
		ECHO "_CNT_SBNE=",_CNT_SBNE
		ECHO "_CNT_SBNES=",_CNT_SBNES
		ECHO "_CNT_SBPL=",_CNT_SBPL
		ECHO "_CNT_SBPLS=",_CNT_SBPLS
		ECHO "_CNT_SJMP=",_CNT_SJMP
		ECHO "_CNT_SJMPS=",_CNT_SJMPS
		ECHO "_CNT_SJSR=",_CNT_SJSR
		ECHO "_CNT_SJSRS=",_CNT_SJSRS
		ECHO "_CNT_SPR_IDX_INT_SET=",_CNT_SPR_IDX_INT_SET
		ECHO "_CNT_SPR_IDX_SET=",_CNT_SPR_IDX_SET
		ECHO "_CNT_SPR_LIB_SET=",_CNT_SPR_LIB_SET
		ECHO "_CNT_SRET=",_CNT_SRET
		ECHO "_CNT_SRUN=",_CNT_SRUN
		ECHO "_CNT_SSWITCH=",_CNT_SSWITCH
		ECHO "_CNT_STORE=",_CNT_STORE
		ECHO "_CNT_SUSPEND=",_CNT_SUSPEND
		ECHO "_CNT_SYNC=",_CNT_SYNC
		ECHO "_CNT_TIMER_B_SET=",_CNT_TIMER_B_SET
		ECHO "_CNT_TARGET_FOLLOW=",_CNT_TARGET_FOLLOW
		ECHO "_CNT_TARGET_LOCK=",_CNT_TARGET_LOCK
		ECHO "_CNT_TIMER_A_SET=",_CNT_TIMER_A_SET
		ECHO "_CNT_TLM_RES_QUEUE=",_CNT_TLM_RES_QUEUE
#endif
	ENDM

;--------------------A-P-U----------------------

	MAC	CMDD0
	.BYTE	$D0
	ENDM

	MAC	CMDD1
	.BYTE	$D1
	ENDM

	MAC	CMDD2
	.BYTE	$D2
	ENDM

	MAC	CMDD3
	.BYTE	$D3
	ENDM

	MAC	CMDD4
	.BYTE	$D4
	ENDM

	MAC	CMDD5
	.BYTE	$D5
	ENDM

	MAC	CMDD6
	.BYTE	$D6
	ENDM

	MAC	CMDD7
	.BYTE	$D7
	ENDM

	MAC	CMDD8
	.BYTE	$D8
	ENDM

	MAC	CMDD9
	.BYTE	$D9
	.BYTE	{1}
	ENDM

	MAC	CMDDA
	.BYTE	$DA
	.BYTE	{1}
	ENDM

	MAC	CMDDB
	.BYTE	$DB
	.BYTE	{1}
	ENDM

	MAC	CMDE0
	.BYTE	$E0
	.BYTE	{1}
	ENDM

	MAC	CMDE1
	.BYTE	$E1
	.BYTE	{1}
	ENDM

	MAC	CMDE2
	.BYTE	$E2
	.BYTE	{1}
	ENDM

	MAC	CMDE8
	.BYTE	$E8
	ENDM

	MAC	CMDE9
	.BYTE	$E9
	.BYTE	{1}
	ENDM

	MAC	CMDEA
	.BYTE	$EA
	.BYTE	{1}
	ENDM

	MAC	CMDEB
	.BYTE	$EB
	.BYTE	{1}
	ENDM

	MAC	CMDEC
	.BYTE	$EC
	.BYTE	{1}
	ENDM

	MAC	LOOP_START
	.BYTE	$F0
	.BYTE	{1}
	ENDM

	MAC	DO_LOOP
	.BYTE	$F1
	ENDM

	MAC	AJSR
	.BYTE	$F2
	.WORD	{1}
	ENDM

	MAC	ARET
	.BYTE	$F3
	ENDM

	MAC	AJMP
	.BYTE	$F8
	.WORD	{1}
	ENDM

	MAC	ASTOP
	.BYTE	$FF
	ENDM

	MAC DATA
	.BYTE	{0}
	ENDM

;---------------M-A-C-R-O-S-E-S-----------------

	MAC BANK_START
CUR_PRG_BANK	SET {1}
CUR_BANK_START	SET .
		ECHO "BANK",CUR_PRG_BANK," ORG ",[CUR_BANK_START>>12],"{"
	ENDM

	MAC	BANK_END
	#if {1}=$00
_total_free	SET 0
	#endif
_bank{1}_free	SET	[{2}-.-32]
_total_free	SET [_total_free+_bank{1}_free]
	#if .>{2}-32
		ECHO "} s =",[.-CUR_BANK_START],"EXCEEDED =",[0-_bank{1}_free]
	#else
		ECHO "} s =",[.-CUR_BANK_START],"FREE =",_bank{1}_free
	#endif
	#if .<{2}-32
		ORG		{2}-33
		.BYTE	$FF
	#endif
		ORG		{2}-32
		SEI
		INC		MMC1RESET
		CLD
		JMP		_RESET
		.BYTE	$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00
		.BYTE	$00,$00
		.WORD NMI
		.WORD RESET
		.WORD RESET
	ENDM

	MAC	LAST_BANK_END
_bank{1}_free	SET	[{2}-.-32]
_total_free	SET [_total_free+_bank{1}_free]
	#if .>[{2}-32]
		ECHO "} s =",[.-CUR_BANK_START],"EXCEEDED =",[0-_bank{1}_free]
	#else
		ECHO "} s =",[.-CUR_BANK_START],"FREE =",_bank{1}_free
	#endif
		ECHO "-------------";
		ECHO "total free =",_total_free
		ECHO ""
	#if .<{2}-32
		ORG		{2}-33
		.BYTE	$FF
	#endif
		ORG		{2}-32
RESET:
		SEI
MMC1RESET:
		INC		MMC1RESET
		CLD
		JMP		_RESET
		.BYTE	$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00
		.BYTE	$00,$00
		.WORD NMI
		.WORD RESET
		.WORD RESET
	ENDM

	MAC SECTION_START
_{1}_start	SET	.
	ENDM

	MAC SECTION_END
_{1}_end	SET .
		ECHO " * block =",_{1}_end-_{1}_start,"[",{2},"]"
	ENDM

	MAC	FAR_PTR
{1}			SET	.
{1}_bank	SET	CUR_PRG_BANK
	ENDM

;---------------A-R-I-T-H-M---------------------

	; \t\tLDA\t\t(.*)\n\t\tADC\t\t\#\$00\n\t\tSTA\t\t\1\n
	; \t\tADCH\t\1\n
	;
	; adjust high hibble of 16-bit value when 8bit argument added
	;
	MAC	ADCH
#if OPTIMIZATION=1
		BCC		.1
		INC		{0}
.1:
#else
		LDA		{0}
		ADC		#$00
		STA		{0}
#endif
	ENDM

	; \t\tCLC\n\t\tLDA\t\t(.*)\n\t\tADC\t\t(.*)\n\t\tSTA\t\t\1\n\t\tLDA\t\t\1\+1\n\t\tADC\t\t\#\$00\n\t\tSTA\t\t\1\+1\n
	; \t\tADDWB\t\1,\2\n\3:
	;
	MAC	ADDWB
#if OPTIMIZATION=1
		LDA		{2}
		CLC
		ADC		{1}
		STA		{2}
		BCC		.1
		INC		{2}+1
.1:
#else
		CLC
		LDA		{2}
		ADC		{1}
		STA		{2}
		LDA		{2}+1
		ADC		#$00
		STA		{2}+1
#endif
	ENDM

	; \t\tLDA\t\t(.*)\n\t\tSBC\t\t\#\$00\n\t\tSTA\t\t\1\n
	; \t\tSBCH\t\1\n
	;
	; adjust high hibble of 16-bit value when 8bit argument added
	;
	MAC	SBCH
#if OPTIMIZATION=1
		BCS		.1
		DEC		{0}
.1:
#else
		LDA		{0}
		SBC		#$00
		STA		{0}
#endif
	ENDM

	; \t\tSEC\n\t\tLDA\t\t(.*)\n\t\tSBC\t\t(.*)\n\t\tSTA\t\t\1\n\t\tLDA\t\t\1\+1\n\t\tSBC\t\t\#\$00\n\t\tSTA\t\t\1\+1\n
	; \t\tSUBWB\t\1,\2\n\3:
	;
	MAC	SUBWB
#if OPTIMIZATION=1
		SEC
		LDA		{2}
		SBC		{1}
		STA		{2}
		BCS		.1
		DEC		{2}+1
.1
#else
		SEC
		LDA		{2}
		SBC		{1}
		STA		{2}
		LDA		{2}+1
		SBC		#$00
		STA		{2}+1
#endif
	ENDM
