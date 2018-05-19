;-------------C-O-N-S-T-A-N-T-S-----------------

DEBUG			EQU		0
OPTIMIZATION	EQU		0
BUGFIXES		EQU		0

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

;-----------G-A-M-E--S-P-E-C-I-F-I-C------------

; kill current script, stop execution
	MAC	KILL
#if DEBUG=1
_CNT_KILL	SET	_CNT_KILL+1
#endif
	.BYTE	$00
	ENDM

; exit current script, return control to the engine
; return back on the next frame
	MAC	SYNC
#if DEBUG=1
_CNT_SYNC	SET	_CNT_SYNC+1
#endif
	.BYTE	$01
	ENDM

; set script on hold for {1} frames
	MAC	SUSPEND
#if DEBUG=1
_CNT_SUSPEND	SET	_CNT_SUSPEND+1
#endif
	.BYTE	$02
	.BYTE	{1}
	ENDM

; execute native code, then exit script, return control to the engine
	MAC	NJSR_SYNC
#if DEBUG=1
_CNT_NJSR_SYNC	SET	_CNT_NJSR_SYNC+1
#endif
	.BYTE	$03
	.WORD	{1}
	ENDM

; queue new script and run it, {1} is the obj manager handler mode , {2}
; script pointer. note, all modes except 02 and 06 are the same simple
; script running modes but they differs in the program logic when handling
; collisions
;
; _OBJ_SCR_AUTO		- general purpose global scripts with its own destructors
; _OBJ_SCR_PLAYER	- only PLAYER objects
; _OBJ_SCR_THROW	- throwable objects like boxes, used also as projectiles
; _OBJ_SCR_STUNA		- special kind anti-player stunning projectiles bouncing from enemy
; _OBJ_SCR_BALL		- special object for basket game
; _OBJ_SCR_ENEMY	- all harmless objects, including projectiles
; _OBJ_SCR_BULLET	- player damaging projectile
; _OBJ_SCR_STUNB	- player stunning projectile
; _OBJ_SCR_SOLID	- solid sprite objects, jumpable, throwable, harmless to player
; _OBJ_SCR_GRAB		- harmless objects to grab by the player, disappear upon collision

_OBJ_SCR_AUTO	EQU	$01
_OBJ_SCR_PLAYER	EQU	$02
_OBJ_SCR_THROW	EQU	$03
_OBJ_SCR_STUNA	EQU	$04
_OBJ_SCR_BALL	EQU	$05
_OBJ_SCR_ENEMY	EQU	$06
_OBJ_SCR_BULLET	EQU	$07
_OBJ_SCR_STUNB	EQU	$08
_OBJ_SCR_SOLID	EQU	$09
_OBJ_SCR_GRAB	EQU	$0A

	MAC	SRUN
#if DEBUG=1
_CNT_SRUN	SET	_CNT_SRUN+1
#endif
	.BYTE	$04
	.BYTE	{1}
	.WORD	{2}
	ENDM

; execute native code, continue script operation
	MAC	NJSR
#if DEBUG=1
_CNT_NJSR	SET	_CNT_NJSR+1
#endif
	.BYTE	$05
	.WORD	{1}
	ENDM

	MAC	ASSERT_SHORT_OFS
#if DEBUG=1
TMP_CMD_PC	SET	.
TMP_OFS		SET	[{1}-TMP_CMD_PC-{2}]
	#if TMP_OFS<-128
		ECHO	"long",{3},"at",TMP_CMD_PC,"jumps to",{1},"distance",TMP_OFS
	#endif
	#if TMP_OFS>127
		ECHO	"long",{3},"at",TMP_CMD_PC,"jumps to",{1},"distance",TMP_OFS
	#endif
#endif
	ENDM

	MAC	ALERT_SHORT_OFS
#if DEBUG=1
TMP_CMD_PC	SET	.
TMP_OFS		SET	[{1}-TMP_CMD_PC-{2}]
	#if TMP_OFS>=-128&&TMP_OFS<=127
		ECHO	"short",{3},"at",TMP_CMD_PC,"jumps to",{1},"distance",TMP_OFS
	#endif
#endif
	ENDM

; unconditional script branch
	MAC	SJMP
#if DEBUG=1
_CNT_SJMP	SET	_CNT_SJMP+1
#endif
	ALERT_SHORT_OFS		{1},3,"SJMP"
	.BYTE	$06
	.WORD	{1}
	ENDM

	MAC	SJMPS
#if DEBUG=1
_CNT_SJMPS	SET	_CNT_SJMPS+1
#endif
#if OPTIMIZATION=1
	ASSERT_SHORT_OFS	{1},2,"SJMPS"
TMP_CMD_PC	SET	.
	.BYTE	$4A
	.BYTE	[{1}-TMP_CMD_PC-2]&$FF
#else
	.BYTE	$06
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
	.BYTE	$07
	.WORD	{1}
	ENDM

	MAC	SJSRS
#if DEBUG=1
_CNT_SJSRS	SET	_CNT_SJSRS+1
#endif
#if OPTIMIZATION=1
	ASSERT_SHORT_OFS	{1},2,"SJSRS"
TMP_CMD_PC	SET	.
	.BYTE	$4B
	.BYTE	[{1}-TMP_CMD_PC-2]&$FF
#else
	.BYTE	$07
	.WORD	{1}
#endif
	ENDM

; return from script subroutine
	MAC	SRET
#if DEBUG=1
_CNT_SRET	SET	_CNT_SRET+1
#endif
	.BYTE	$08
	ENDM

; loop to script branch {1} times
	MAC	LOOPA
#if DEBUG=1
_CNT_LOOPA	SET	_CNT_LOOPA+1
#endif
#if OPTIMIZATION=1
	ASSERT_SHORT_OFS	{2},3,"LOOPA"
TMP_CMD_PC	SET	.
	.BYTE	$09
	.BYTE	{1}
	.BYTE	[{2}-TMP_CMD_PC-3]&$FF
#else
	.BYTE	$09
	.BYTE	{1}
	.WORD	{2}
#endif
	ENDM

; second loop operand
	MAC	LOOPB
#if DEBUG=1
_CNT_LOOPB	SET	_CNT_LOOPB+1
#endif
#if OPTIMIZATION=1
	ASSERT_SHORT_OFS	{2},3,"LOOPB"
TMP_CMD_PC	SET	.
	.BYTE	$0A
	.BYTE	{1}
	.BYTE	[{2}-TMP_CMD_PC-3]&$FF
#else
	.BYTE	$0A
	.BYTE	{1}
	.WORD	{2}
#endif
	ENDM

; helper branch macros
	MAC	SBRANCH
#if {3}=8
	ASSERT_SHORT_OFS	{1},2,"BRANCH"
TMP_CMD_PC	SET	.
	.BYTE	[$44+{2}]
	.BYTE	[{1}-TMP_CMD_PC-2]&$FF
#else
#if OPTIMIZATION=1
	ALERT_SHORT_OFS		{1},3,"BRANCH"
#endif
	.BYTE	[$0B+{2}]
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
	.BYTE	$11
	.BYTE	{1},{2}
	.WORD	{3}
	ENDM

; switch case construction, {1} index ram variable, first branch default
	MAC	SSWITCH
#if DEBUG=1
_CNT_SSWITCH	SET	_CNT_SSWITCH+1
#endif
	.BYTE	$12
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
	.BYTE	$13
	.BYTE	{1}
	.WORD	{2}
	ENDM

; {1} chr bank idx, {2} value
	MAC	CHR_SELECT
#if DEBUG=1
_CNT_CHR_SELECT	SET	_CNT_CHR_SELECT+1
#endif
	.BYTE	$14
	.BYTE	{1},{2}
	ENDM

; reset loop counter for loop A
	MAC	LOOPA_RESET
#if DEBUG=1
_CNT_LOOPA_RESET	SET	_CNT_LOOPA_RESET+1
#endif
	.BYTE	$15
	ENDM

; same for loop b
	MAC	LOOPB_RESET
#if DEBUG=1
_CNT_LOOPB_RESET	SET	_CNT_LOOPB_RESET+1
#endif
	.BYTE	$16
	ENDM

; play SE
	MAC	APU_LOAD
#if DEBUG=1
_CNT_APU_LOAD	SET	_CNT_APU_LOAD+1
#endif
	.BYTE	$17
	.BYTE	{1}
	ENDM

; do animation and return to the engine
; sync to the next frame
	MAC	OBJ_ANIMATE_SYNC
#if DEBUG=1
_CNT_OBJ_ANIMATE_SYNC	SET	_CNT_OBJ_ANIMATE_SYNC+1
#endif
	.BYTE	$18
	ENDM

; same as previous but continue with the script execution
	MAC	OBJ_ANIMATE
#if DEBUG=1
_CNT_OBJ_ANIMATE	SET	_CNT_OBJ_ANIMATE+1
#endif
	.BYTE	$19
	ENDM

; macro command for animating the flight objects locked on
; target (bats level 2, cards of cat boss, etc..)
	MAC	TARGET_FOLLOW
#if DEBUG=1
_CNT_TARGET_FOLLOW	SET	_CNT_TARGET_FOLLOW+1
#endif
	.BYTE	$1A
	ENDM

; usually set if object is deactivated
	MAC	PARAM_80_CLEAR
#if DEBUG=1
_CNT_PARAM_80_CLEAR	SET	_CNT_PARAM_80_CLEAR+1
#endif
	.BYTE	$1B
	ENDM

; deactivate
	MAC	PARAM_80_SET
#if DEBUG=1
_CNT_PARAM_80_SET	SET	_CNT_PARAM_80_SET+1
#endif
	.BYTE	$1C
	ENDM

; select sprite library for object
	MAC	SPR_LIB_SELECT
#if DEBUG=1
_CNT_SPR_LIB_SELECT	SET	_CNT_SPR_LIB_SELECT+1
#endif
	.BYTE	$1D
	.BYTE	{1}_idx
	ENDM

; select current sprite idx as integer value
	MAC	SPR_IDX_INT
#if DEBUG=1
_CNT_SPR_IDX_INT	SET	_CNT_SPR_IDX_INT+1
#endif
	.BYTE	$1E
	.BYTE	{1}
	ENDM

; the same using the mnemonic
	MAC	SPR_IDX_SELECT
#if DEBUG=1
_CNT_SPR_IDX_SELECT	SET	_CNT_SPR_IDX_SELECT+1
#endif
	.BYTE	$1E
	.BYTE	{1}_idx
	ENDM

	MAC	SPR_IDX_SELECTS
#if DEBUG=1
_CNT_SPR_IDX_SELECTS	SET	_CNT_SPR_IDX_SELECTS+1
#endif
	.BYTE	$1E
	.BYTE	{1}
	ENDM

; one of hor/vert sprite flipping flags
	MAC	FLIP_40_CLEAR
#if DEBUG=1
_CNT_FLIP_40_CLEAR	SET	_CNT_FLIP_40_CLEAR+1
#endif
	.BYTE	$1F
	ENDM

; same
	MAC	FLIP_40_SET
#if DEBUG=1
_CNT_FLIP_40_SET	SET	_CNT_FLIP_40_SET+1
#endif
	.BYTE	$20
	ENDM

; same
	MAC	FLIP_80_CLEAR
#if DEBUG=1
_CNT_FLIP_80_CLEAR	SET	_CNT_FLIP_80_CLEAR+1
#endif
	.BYTE	$21
	ENDM

; same
	MAC	FLIP_80_SET
#if DEBUG=1
_CNT_FLIP_80_SET	SET	_CNT_FLIP_80_SET+1
#endif
	.BYTE	$22
	ENDM

; similar but toggles
	MAC	FLIP_40_TOGGLE
#if DEBUG=1
_CNT_FLIP_40_TOGGLE	SET	_CNT_FLIP_40_TOGGLE+1
#endif
	.BYTE	$23
	ENDM

; same
	MAC	FLIP_80_TOGGLE
#if DEBUG=1
_CNT_FLIP_80_TOGGLE	SET	_CNT_FLIP_80_TOGGLE+1
#endif
	.BYTE	$24
	ENDM

; xpos is always 16-bit for clipping
	MAC	OBJ_X_POS_SET
#if DEBUG=1
_CNT_OBJ_X_POS_SET	SET	_CNT_OBJ_X_POS_SET+1
#endif
	.BYTE	$25
	.BYTE	{1},{2}
	ENDM

; same for Y
	MAC	OBJ_Y_POS_SET
#if DEBUG=1
_CNT_OBJ_Y_POS_SET	SET	_CNT_OBJ_Y_POS_SET+1
#endif
	.BYTE	$26
	.BYTE	{1},{2}
	ENDM

; add value to object's X position
	MAC	OBJ_X_POS_MOVE
#if DEBUG=1
_CNT_OBJ_X_POS_MOVE	SET	_CNT_OBJ_X_POS_MOVE+1
#endif
	.BYTE	$27
	.BYTE	{1}
	ENDM

; same for Y
	MAC	OBJ_Y_POS_MOVE
#if DEBUG=1
_CNT_OBJ_Y_POS_MOVE	SET	_CNT_OBJ_Y_POS_MOVE+1
#endif
	.BYTE	$28
	.BYTE	{0}
	ENDM

; set constant movement delta for X
	MAC	OBJ_X_DELTA_SET
#if DEBUG=1
_CNT_OBJ_X_DELTA_SET	SET	_CNT_OBJ_X_DELTA_SET+1
#endif
	.BYTE	$29
	.BYTE	{0}
	ENDM

; same for Y
	MAC	OBJ_Y_DELTA_SET
#if DEBUG=1
_CNT_OBJ_Y_DELTA_SET	SET	_CNT_OBJ_Y_DELTA_SET+1
#endif
	.BYTE	$2A
	.BYTE	{0}
	ENDM

; does some kind of acceleration, low nibble of delta
; added to x position with carry
	MAC	OBJ_X_DELTA_INC
#if DEBUG=1
_CNT_OBJ_X_DELTA_INC	SET	_CNT_OBJ_X_DELTA_INC+1
#endif
	.BYTE	$2B
	ENDM

; same for Y
	MAC	OBJ_Y_DELTA_INC
#if DEBUG=1
_CNT_OBJ_Y_DELTA_INC	SET	_CNT_OBJ_Y_DELTA_INC+1
#endif
	.BYTE	$2C
	ENDM

; same but with decrease
	MAC	OBJ_X_DELTA_DEC
#if DEBUG=1
_CNT_OBJ_X_DELTA_DEC	SET	_CNT_OBJ_X_DELTA_DEC+1
#endif
	.BYTE	$2D
	ENDM

; same for Y
	MAC	OBJ_Y_DELTA_DEC
#if DEBUG=1
_CNT_OBJ_Y_DELTA_DEC	SET	_CNT_OBJ_Y_DELTA_DEC+1
#endif
	.BYTE	$2E
	ENDM

; init object lock on target, {1} usually direction of target
	MAC	TARGET_LOCK
#if DEBUG=1
_CNT_TARGET_LOCK	SET	_CNT_TARGET_LOCK+1
#endif
	.BYTE	$2F
	.BYTE	{1}
	ENDM

; set speed for traveling to target or some kind...
	MAC	TARGET_SPD_SET
#if DEBUG=1
_CNT_TARGET_SPD_SET	SET	_CNT_TARGET_SPD_SET+1
#endif
	.BYTE	$30
	.BYTE	{1}
	ENDM

; other direction value for target lock
	MAC	TARGET_DIR_SET
#if DEBUG=1
_CNT_TARGET_DIR_SET	SET	_CNT_TARGET_DIR_SET+1
#endif
	.BYTE	$31
	.BYTE	{1}
	ENDM

; set object dimensions for collision tests
	MAC	OBJ_SIZE_SET
#if DEBUG=1
_CNT_OBJ_SIZE_SET	SET	_CNT_OBJ_SIZE_SET+1
#endif
	.BYTE	$32
	.BYTE	{1},{2}
	ENDM

; object damage type set. NOTE, that for cutscene scripts
; this variable utilized differently as one of the tmp
; counters
;
_OBJ_DMG_NONE	EQU	$00
_OBJ_DMG_KILL	EQU	$01
_OBJ_DMG_STUN	EQU	$02

	MAC	OBJ_DAMAGE_SET
#if DEBUG=1
_CNT_OBJ_DAMAGE_SET	SET	_CNT_OBJ_DAMAGE_SET+1
#endif
	.BYTE	$33
	.BYTE	{1}
	ENDM

; define object's hitpoints. hp should be set even for undestructable
; objects because they threated as a existence of the object itself
; rather than activeness state flag
; NOTE, this var also used differently for cutscenes
	MAC	OBJ_HP_SET
#if DEBUG=1
_CNT_OBJ_HP_SET	SET	_CNT_OBJ_HP_SET+1
#endif
	.BYTE	$34
	.BYTE	{1}
	ENDM

; set the vert/hor flips for object instantly
	MAC	OBJ_FLIP_SET
#if DEBUG=1
_CNT_OBJ_FLIP_SET	SET	_CNT_OBJ_FLIP_SET+1
#endif
	.BYTE	$35
	.BYTE	{1}
	ENDM

; unused flag settings
	MAC	OBJ_IDXC_SET
#if DEBUG=1
_CNT_OBJ_IDXC_SET	SET	_CNT_OBJ_IDXC_SET+1
#endif
	.BYTE	$36
	.BYTE	{1}
	ENDM

; they used MOV operands here for some reasons...
	MAC	MAIN_SUB_SET
#if DEBUG=1
_CNT_MAIN_SUB_SET	SET	_CNT_MAIN_SUB_SET+1
#endif
	.BYTE	$37
	.BYTE	{1}
	ENDM

; yes, it is parameters are speed and increment value
	MAC	PAL_FADE_IN
#if DEBUG=1
_CNT_PAL_FADE_IN	SET	_CNT_PAL_FADE_IN+1
#endif
	.BYTE	$38
	.BYTE	{1},{2}
	ENDM

; same
	MAC	PAL_FADE_OUT
#if DEBUG=1
_CNT_PAL_FADE_OUT	SET	_CNT_PAL_FADE_OUT+1
#endif
	.BYTE	$39
	.BYTE	{1},{2}
	ENDM

; never used, always used native handlers instead
	MAC	TLM_RES_QUEUE
#if DEBUG=1
_CNT_TLM_RES_QUEUE	SET	_CNT_TLM_RES_QUEUE+1
#endif
	.BYTE	$3A
	.WORD	{1}
	ENDM

; yes, it is, parameter is an offset to menu data (options position and number)
	MAC	MENU_CURSOR_DRAW
#if DEBUG=1
_CNT_MENU_CURSOR_DRAW	SET	_CNT_MENU_CURSOR_DRAW+1
#endif
	.BYTE	$3B
	.WORD	{1}
	ENDM

; never used, all menus are vertically oriented
	MAC	MENU_HOR_INPUT
#if DEBUG=1
_CNT_MENU_HOR_INPUT	SET	_CNT_MENU_HOR_INPUT+1
#endif
	.BYTE	$3C
	.BYTE	{1},{2}
	ENDM

; same for vert menu, parameters are number of items in menu and default one
	MAC	MENU_VERT_INPUT
#if DEBUG=1
_CNT_MENU_VERT_INPUT	SET	_CNT_MENU_VERT_INPUT+1
#endif
	.BYTE	$3D
	.BYTE	{1},{2}
	ENDM

; never used, msg area always the same and hardcoded in msg init routine
	MAC	MSG_AREA_SET
#if DEBUG=1
_CNT_MSG_AREA_SET	SET	_CNT_MSG_AREA_SET+1
#endif
	.BYTE	$3E
	.WORD	{1}
	.BYTE	{2}
	ENDM

; displays the message in already defined window, {1} ptr to msg resource
; {2} is the APU SE index to make typing sound for every character
	MAC	MSG_DISPLAY
#if DEBUG=1
_CNT_MSG_DISPLAY	SET	_CNT_MSG_DISPLAY+1
#endif
	.BYTE	$3F
	.WORD	{1}
	.BYTE	{2}
	ENDM

; wait until message is displayed
	MAC	MSG_WAIT
#if DEBUG=1
_CNT_MSG_WAIT	SET	_CNT_MSG_WAIT+1
#endif
	.BYTE	$40
	ENDM

; break current subroutine and exit instantly, argument is return address
	MAC	BREAK
#if DEBUG=1
_CNT_BREAK	SET	_CNT_BREAK+1
#endif
	.BYTE	$41
	.WORD	{1}
	ENDM

; set default script routine for object when destroyed or collision detected
; called from object manager instantly if collision test passed
;
	MAC	DESTR_PC_SET
#if DEBUG=1
_CNT_DESTR_PC_SET	SET	_CNT_DESTR_PC_SET+1
#endif
	.BYTE	$42
	.WORD	{1}
	ENDM

; other flags set cmd
	MAC	PARAM_40_SET
#if DEBUG=1
_CNT_PARAM_40_SET	SET	_CNT_PARAM_40_SET+1
#endif
	.BYTE	$43
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
		ECHO	"BANK",CUR_PRG_BANK," ORG ",[CUR_BANK_START>>12],"{"
	ENDM

	MAC	BANK_END
	#if {1}=$00
_total_free	SET 0
	#endif
_bank{1}_free	SET	[{2}-.-32]
_total_free	SET [_total_free+_bank{1}_free]
	#if .>{2}-32
		ECHO	"} s =",[.-CUR_BANK_START],"EXCEEDED =",[0-_bank{1}_free]
	#else
		ECHO	"} s =",[.-CUR_BANK_START],"FREE =",_bank{1}_free
	#endif
	#if .<{2}-32
		ORG		{2}-33
		.BYTE	$FF
	#endif
		ORG		{2}-32
		SEI
		INC		[$FFE0+1]
		CLD
		JMP		_j_RESET
		.BYTE	$00,$00,$00,$00,$00,$00,$00,$00
		.BYTE	$1B
		.BYTE	$A4
		.BYTE	$ED
		.BYTE	$8B
		.BYTE	$33
		.BYTE	4
		.BYTE	0
		.BYTE	0
		.BYTE	8
		.BYTE	$E2
		.WORD NMI
		.WORD RESET
		.WORD RESET
	ENDM

	MAC	LAST_BANK_END
_bank{1}_free	SET	[{2}-.-32]
_total_free	SET [_total_free+_bank{1}_free]
	#if .>[{2}-32]
		ECHO	"} s =",[.-CUR_BANK_START],"EXCEEDED =",[0-_bank{1}_free]
	#else
		ECHO	"} s =",[.-CUR_BANK_START],"FREE =",_bank{1}_free
	#endif
		ECHO	"-------------";
		ECHO	"total free =",_total_free
		ECHO	""
	#if .<{2}-32
		ORG		{2}-33
		.BYTE	$FF
	#endif
RESET:
		ORG		{2}-32
		SEI
		INC		.
		CLD
		JMP		_j_RESET
		.BYTE	$00,$00,$00,$00,$00,$00,$00,$00
		.BYTE	$1B
		.BYTE	$B
		.BYTE	$ED
		.BYTE	$8B
		.BYTE	$33
		.BYTE	4
		.BYTE	0
		.BYTE	0
		.BYTE	8
		.BYTE	$49
		.WORD NMI
		.WORD RESET
		.WORD RESET
	ENDM

	MAC SECTION_START
_{1}_start	SET	.
	ENDM

	MAC SECTION_END
_{1}_end	SET .
		ECHO	" * block =",_{1}_end-_{1}_start,"[",{2},"]"
	ENDM

	MAC	FAR_PTR
{1}			SET	.
{1}_bank	SET	CUR_PRG_BANK
	ENDM

;---------------A-R-I-T-H-M---------------------

	; \t\tLDA\t\t(.*)\n\t\tSTA\t\t(.*)\n\t\tLDA\t\t\1\+1\n\t\tSTA\t\t\2\+1\n
	; \t\tMOVM\t\2,\1\n
	;
	MAC	MOVM
		LDA		{2}
		STA		{1}
		LDA		{2}+1
		STA		{1}+1
	ENDM

	; \t\tLDA\t\t#<\[(.*)\]\n\t\tSTA\t\t(.*)\n\t\tLDA\t\t#>\[\1\]\n\t\tSTA\t\t\2\+1\n
	; \t\tMOVO\t\2,\1\n
	; \t\tLDA\t\t#\$(..)\n\t\tSTA\t\t(.*)\n\t\tLDA\t\t#\$(..)\n\t\tSTA\t\t\2\+1\n
	; \t\tMOVO\t\2,$\3\1\n
	;
	;
	MAC	MOVO
		LDA		#<[{2}]
		STA		{1}
		LDA		#>[{2}]
		STA		{1}+1
	ENDM

	; \t\tINC\t\t(.*)\n\t\tBNE\t\t(.*)\n\t\tINC\t\t\1\+1\n\2:\n
	; \t\tINCW\t\1\n
	;
	MAC	INCW
		INC		{1}
		BNE		.1
		INC		{1}+1
.1:
	ENDM

	; \t\tINC\t\t(.*)\n\t\tBNE\t\t(.*)\n\t\tINC\t\t\1\+1\n\2:\t\tJMP\t\tloc(.*)\n
	; \t\tINC\t\t(.*)\n\t\tBNE\t\tloc\3\n\t\tINC\t\t\1\+1\n;\2:\n\t\tJMP\t\tloc\3\n
	; \t\tINC\t\t(.*)\n\t\tBNE\t\t(.*)\n\t\tINC\t\t\1\+1\n\t\tJMP\t\t\2\n
	; \t\tJINCW\t\1,\2\n
	;
	MAC	JINCW
		INC		{1}
		BNE		{2}
		INC		{1}+1
		JMP		{2}
	ENDM

	; \t\tLDA\t\t(.*)\n\t\tBNE\t\t(.*)\n\t\tDEC\t\t\1\+1\n\2:\n\t\tDEC\t\t\1\n
	; \t\tDECW\t\1\n
	;
	MAC	DECW
		LDA		{1}
		BNE		.1
		DEC		{1}+1
.1:
		DEC		{1}
	ENDM

	; \t\tLDA\t\t(.*)\n\t\tCLC\n\t\tADC\t\t(.*)\n\t\tSTA\t\t\1\n\t\tBCC\t\t(.*)\n\t\tINC\t\t\1\+1\n\3:
	; \t\tADDW8\t\1,\2\n\3:
	;
	MAC	ADDW8
		LDA		{1}
		CLC
		ADC		{2}
		STA		{1}
		BCC		.1
		INC		{1}+1
.1:
	ENDM

	; \t\tLDA\t\t(.*)\n\t\tCLC\n\t\tADC\t\t(.*)\n\t\tSTA\t\t\1\n\t\tBCC\t\t(.*)\n\t\tINC\t\t\1\+1\n\t\tJMP\t\t\3\n
	; \t\tJADDW8\t\1,\2,\3\n
	;
	MAC	JADDW8
		LDA		{1}
		CLC
		ADC		{2}
		STA		{1}
		BCC		{3}
		INC		{1}+1
		JMP		{3}
	ENDM

	; \t\tLDA\t\t(.*)\n\t\tCLC\n\t\tADC\t\t(.*)\n\t\tSTA\t\t\1\n\t\tBCS\t\t(.*)\n\t\tDEC\t\t\1\+1\n\3:\n
	; \t\tEADDW8\t\1,\2\n
	;
	MAC EADDW8
		LDA		{1}
		CLC
		ADC		{2}
		STA		{1}
		BCS		.1
		DEC		{1}+1
.1:
	ENDM

	; \t\tLDA\t\t(.*)\n\t\tCLC\n\t\tADC\t\t(.*)\n\t\tSTA\t\t\1\n\t\tBCS\t\t(.*)\n\t\tDEC\t\t\1\+1\n\t\tJMP\t\t\3\n
	; \t\tJEADDW8\t\1,\2,\3\n
	;
	MAC JEADDW8
		LDA		{1}
		CLC
		ADC		{2}
		STA		{1}
		BCS		{3}
		DEC		{1}+1
		JMP		{3}
	ENDM

	; \t\tLDA\t\t(.*)\n\t\tSEC\n\t\tSBC\t\t(.*)\n\t\tSTA\t\t\1\n\t\tBCS\t\t(.*)\n\t\tDEC\t\t\1\+1\n\3:
	; \t\tSUBW8\t\1,\2\n\3:
	;
	MAC	SUBW8
		LDA		{1}
		SEC
		SBC		{2}
		STA		{1}
		BCS		.1
		DEC		{1}+1
.1:
	ENDM

	; \t\tLDA\t\t(.*)\n\t\tSEC\n\t\tSBC\t\t(.*)\n\t\tSTA\t\t\1\n\t\tBCS\t\t(.*)\n\t\tDEC\t\t\1\+1\n\t\tJMP\t\t\3\n
	; \t\tJSUBW8\t\1,\2,\3\n
	;
	MAC	JSUBW8
		LDA		{1}
		SEC
		SBC		{2}
		STA		{1}
		BCS		{3}
		DEC		{1}+1
		JMP		{3}
	ENDM

	; \t\tLDA\t\t(.*)\n\t\tCLC\n\t\tADC\t\t#<\[(.*)\]\n\t\tSTA\t\t\1\n\t\tLDA\t\t\1\+1\n\t\tADC\t\t#>\[\2\]\n\t\tSTA\t\t\1\+1\n
	; \t\tADDWO16\t\1,\2\n
	;
	MAC	ADDWO16
		LDA		{1}
		CLC
		ADC		#<[{2}]
		STA		{1}
		LDA		{1}+1
		ADC		#>[{2}]
		STA		{1}+1
	ENDM

	; \t\tLDA\t\t(.*)\n\t\tSEC\n\t\tSBC\t\t(.*)\n\t\tSTA\t\t\1\n\t\tLDA\t\t\1\+1\n\t\tSBC\t\t\2\+1\n\t\tSTA\t\t\1\+1\n
	; \t\tSUBM16\t\1,\2\n
	;
	MAC	SUBM16
		LDA		{1}
		SEC
		SBC		{2}
		STA		{1}
		LDA		{1}+1
		SBC		{2}+1
		STA		{1}+1
	ENDM

	; \t\tLDA\t\t(.*)\n\t\tEOR\t\t#\$FF\n\t\tCLC\n\t\tADC\t\t#1\n\t\tSTA\t\t\1\n
	; \t\tNEGB\t\1\n
	;
	MAC	NEGB
		LDA		{1}
		EOR		#$FF
		CLC
		ADC		#1
		STA		{1}
	ENDM

	; \t\tLDA\t\t(.*)\n\t\tEOR\t\t\#\$FF\n\t\tSTA\t\t\1\n\t\tLDA\t\t\1\+1\n\t\tEOR\t\t\#\$FF\n\t\tSTA\t\t\1\+1\n\t\tINC\t\t\1\n\t\tBNE\t\t(.*)\n\t\tINC\t\t\1\+1\n\2:
	; \t\tNEGW\t\1\n\2:
	;
	MAC	NEGW
		LDA		{1}
		EOR		#$FF
		STA		{1}
		LDA		{1}+1
		EOR		#$FF
		STA		{1}+1
		INC		{1}
		BNE		.1
		INC		{1}+1
.1:
	ENDM

	; \t\tLDA\t\t(.*)\n\t\tSEC\n\t\tSBC\t\t#\$(..)\n\t\tLDA\t\t\1\+1\n\t\tSBC\t\t#\$(.)\n
	; \t\tCMPI16\t\1,\$\3\2\n
	;
	; \t\tLDA\t\t(.*)\n\t\tSEC\n\t\tSBC\t\t#(.)\n\t\tLDA\t\t\1\+1\n\t\tSBC\t\t#\$(..)\n
	; \t\tCMPI16\t\1,\$\30\2\n
	;
	; \t\tLDA\t\t(.*)\n\t\tSEC\n\t\tSBC\t\t#\$(..)\n\t\tLDA\t\t\1\+1\n\t\tSBC\t\t#(.)\n
	; \t\tCMPI16\t\1,\$0\3\2\n
	;
	; \t\tLDA\t\t(.*)\n\t\tSEC\n\t\tSBC\t\t#(.)\n\t\tLDA\t\t\1\+1\n\t\tSBC\t\t#(.)\n
	; \t\tCMPI16\t\1,\$0\30\2\n
	;
	; \t\tLDA\t\t(.*)\n\t\tSEC\n\t\tSBC\t\t#(.)\n\t\tLDA\t\t\1\+1\n\t\tSBC\t\t#\$(.)\n
	; \t\tCMPI16\t\1,\$\30\2\n
	;
	; \t\tLDA\t\t(.*)\n\t\tSEC\n\t\tSBC\t\t#\$(..)\n\t\tLDA\t\t\1\+1\n\t\tSBC\t\t#\$(..)\n
	; \t\tCMPI16\t\1,\$\3\2\n
	;
	MAC	CMPI16
		LDA		{1}
		SEC
		SBC		#<[{2}]
		LDA		{1}+1
		SBC		#>[{2}]
	ENDM

	; \t\tLDA\t\t(.*)\n\t\tSEC\n\t\tSBC\t\t(.*)\n\t\tLDA\t\t\1\+1\n\t\tSBC\t\t\2\+1\n
	; \t\tCMPM16\t\1,\2
	;
	MAC CMPM16
		LDA		{1}
		SEC
		SBC		{2}
		LDA		{1}+1
		SBC		{2}+1
	ENDM

	; \t\tLDA\t\t#0\n\t\tSTA\t\t(.*)\+1\n\t\tLDA\t\t(.*)\n\t\tASL\n\t\tROL\t\t\1\+1\n\t\tASL\n\t\tROL\t\t\1\+1\n\t\tASL\n\t\tROL\t\t\1\+1\n\t\tASL\n\t\tROL\t\t\1\+1\n\t\tASL\n\t\tROL\t\t\1\+1\n\t\tSTA\t\t\1\n
	; \t\tLSHW8\t\1,\2,5\n
	; \t\tLDA\t\t#0\n\t\tSTA\t\t(.*)\+1\n\t\tLDA\t\t(.*)\n\t\tASL\n\t\tROL\t\t\1\+1\n\t\t\tASL\n\t\tROL\t\t\1\+1\n\tASL\n\t\tROL\t\t\1\+1\n\t\tASL\n\t\tROL\t\t\1\+1\n\t\tSTA\t\t\1\n
	; \t\tLSHW8\t\1,\2,4\n
	; \t\tLDA\t\t#0\n\t\tSTA\t\t(.*)\+1\n\t\tLDA\t\t(.*)\n\t\tASL\n\t\tROL\t\t\1\+1\n\t\tASL\n\t\tROL\t\t\1\+1\n\t\tASL\n\t\tROL\t\t\1\+1\n\t\tSTA\t\t\1\n
	; \t\tLSHW8\t\1,\2,3\n
	; \t\tLDA\t\t#0\n\t\tSTA\t\t(.*)\+1\n\t\tLDA\t\t(.*)\n\t\tASL\n\t\tROL\t\t\1\+1\n\t\tASL\n\t\tROL\t\t\1\+1\n\t\tSTA\t\t\1\n
	; \t\tLSHW8\t\1,\2,2\n
	; \t\tLDA\t\t(.*)\n\t\tSTA\t\t(.*)\n\t\tLDA\t\t#\$00\n\t\tSTA\t\t\2\+1\n\t\tASL\t\t\2\n\t\tROL\t\t\2\+1\n\t\tASL\t\t\2\n\t\tROL\t\t\2\+1\n\t\tASL\t\t\2\n\t\tROL\t\t\2\+1\n
	; \t\tLSHW8\t\2,\1,3\n
	; \t\tLDA\t\t(.*)\n\t\tSTA\t\t(.*)\n\t\tLDA\t\t#\$00\n\t\tSTA\t\t\2\+1\n\t\tASL\t\t\2\n\t\tROL\t\t\2\+1\n\t\tASL\t\t\2\n\t\tROL\t\t\2\+1\n
	; \t\tLSHW8\t\2,\1,2\n
	;
	MAC	LSHW8
		LDA		#0
		STA		{1}+1
		LDA		{2}
		REPEAT	{3}
		ASL
		ROL		{1}+1
		REPEND
		STA		{1}
	ENDM

