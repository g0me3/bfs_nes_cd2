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
	.BYTE	$00
	ENDM

; exit current script, return control to the engine
; return back on the next frame
	MAC	SYNC
	.BYTE	$01
	ENDM

; set script on hold for {1} frames
	MAC	SUSPEND
	.BYTE	$02
	.BYTE	{1}
	ENDM

; execute native code, then exit script, return control to the engine
	MAC	NJSR_SYNC
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
	.BYTE	$04
	.BYTE	{1}
	.WORD	{2}
	ENDM

; execute native code, continue script operation
	MAC	NJSR
	.BYTE	$05
	.WORD	{1}
	ENDM

; unconditional script branch
	MAC	SJMP
	.BYTE	$06
	.WORD	{1}
	ENDM

; call script subroutine (return with RET)
	MAC	SJSR
	.BYTE	$07
	.WORD	{1}
	ENDM

; return from script subroutine
	MAC	SRET
	.BYTE	$08
	ENDM

; loop to script branch {1} times
	MAC	LOOPA
	.BYTE	$09
	.BYTE	{1}
	.WORD	{2}
	ENDM

; second loop operand
	MAC	LOOPB
	.BYTE	$0A
	.BYTE	{1}
	.WORD	{2}
	ENDM

; helper branch macros
	MAC	SBRANCH
#if OPTIMIZATION=1
TMP_CMD_PC	SET	.
	#if {3}=0
		#if {1}>=TMP_CMD_PC
			#if [{1}-TMP_CMD_PC-2]<=$7F
				.BYTE	[$44+{2}]
				.BYTE	[{1}-TMP_CMD_PC-2]
			#else
				ECHO	"long BRANCH at",TMP_CMD_PC,"jumps forward",{1},"distance",{1}-TMP_CMD_PC-2
			#endif
		#else
			#if [TMP_CMD_PC-{1}+2]<=$7F
				.BYTE	[$44+{2}]
				.BYTE	[-[TMP_CMD_PC-{1}+2]]&$FF
			#else
				ECHO	"long BRANCH at",TMP_CMD_PC,"jumps back",{1},"distance",[TMP_CMD_PC-{1}+2]
			#endif
		#endif
	#else
		.BYTE	[$0B+{2}]
		.WORD	{1}
	#endif
#else
	.BYTE	[$0B+{2}]
	.WORD	{1}
#endif
	ENDM

; set of branches equivalent of 6502 set
; script if EQUAL branch
	MAC	SBNE
		SBRANCH	{1},0,1
	ENDM

; script if CARRY=1 branch
	MAC	SBCC
		SBRANCH	{1},1,1
	ENDM

; script if NEG=1 branch
	MAC	SBPL
		SBRANCH	{1},2,1
	ENDM

; script if NO EQUAL branch
	MAC	SBEQ
		SBRANCH	{1},3,1
	ENDM

; script if CARRY=0 branch
	MAC	SBCS
		SBRANCH	{1},4,1
	ENDM

; script if NEG=0 branch
	MAC	SBMI
		SBRANCH	{1},5,1
	ENDM

; set of 8-bit ofs branches
#if OPTIMIZATION=1
	MAC	SBNES
		SBRANCH	{1},0,0
	ENDM

	MAC	SBCCS
		SBRANCH	{1},1,0
	ENDM

	MAC	SBPLS
		SBRANCH	{1},2,0
	ENDM

	MAC	SBEQS
		SBRANCH	{1},3,0
	ENDM

	MAC	SBCSS
		SBRANCH	{1},4,0
	ENDM

	MAC	SBMIS
		SBRANCH	{1},5,0
	ENDM
#else
	MAC	SBNES
		SBRANCH	{1},0,1
	ENDM

	MAC	SBCCS
		SBRANCH	{1},1,1
	ENDM

	MAC	SBPLS
		SBRANCH	{1},2,1
	ENDM

	MAC	SBEQS
		SBRANCH	{1},3,1
	ENDM

	MAC	SBCSS
		SBRANCH	{1},4,1
	ENDM

	MAC	SBMIS
		SBRANCH	{1},5,1
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
	.BYTE	$11
	.BYTE	{1},{2}
	.WORD	{3}
	ENDM

; switch case construction, {1} index ram variable, first branch default
	MAC	SSWITCH
	.BYTE	$12
	.WORD	{1}
	ENDM

; lets make it nice
	MAC	SCASE
	.WORD	{1}
	ENDM

; store operand, put {1} into {2} ram address
	MAC	STORE
	.BYTE	$13
	.BYTE	{1}
	.WORD	{2}
	ENDM

; {1} chr bank idx, {2} value
	MAC	CHR_SELECT
	.BYTE	$14
	.BYTE	{1},{2}
	ENDM

; reset loop counter for loop A
	MAC	LOOPA_RESET
	.BYTE	$15
	ENDM

; same for loop b
	MAC	LOOPB_RESET
	.BYTE	$16
	ENDM

; play SE
	MAC	APU_LOAD
	.BYTE	$17
	.BYTE	{1}
	ENDM

; do animation and return to the engine
; sync to the next frame
	MAC	OBJ_ANIMATE_SYNC
	.BYTE	$18
	ENDM

; same as previous but continue with the script execution
	MAC	OBJ_ANIMATE
	.BYTE	$19
	ENDM

; macro command for animating the flight objects locked on
; target (bats level 2, cards of cat boss, etc..)
	MAC	TARGET_FOLLOW
	.BYTE	$1A
	ENDM

; usually set if object is deactivated
	MAC	PARAM_80_CLEAR
	.BYTE	$1B
	ENDM

; deactivate
	MAC	PARAM_80_SET
	.BYTE	$1C
	ENDM

; select sprite library for object
	MAC	SPR_LIB_SELECT
	.BYTE	$1D
	.BYTE	{1}_idx
	ENDM

; select current sprite idx
	MAC	SPR_IDX_SELECT
	.BYTE	$1E
	.BYTE	{1}
	ENDM

	MAC	SPR_IDX_SELECTL
	.BYTE	$1E
	.BYTE	{1}_idx
	ENDM

	MAC	SPR_IDX_SELECTS
	.BYTE	$1E
	.BYTE	{1}_idx
	ENDM

; one of hor/vert sprite flipping flags
	MAC	FLIP_40_CLEAR
	.BYTE	$1F
	ENDM

; same
	MAC	FLIP_40_SET
	.BYTE	$20
	ENDM

; same
	MAC	FLIP_80_CLEAR
	.BYTE	$21
	ENDM

; same
	MAC	FLIP_80_SET
	.BYTE	$22
	ENDM

; similar but toggles
	MAC	FLIP_40_TOGGLE
	.BYTE	$23
	ENDM

; same
	MAC	FLIP_80_TOGGLE
	.BYTE	$24
	ENDM

; xpos is always 16-bit for clipping
	MAC	OBJ_X_POS_SET
	.BYTE	$25
	.BYTE	{1},{2}
	ENDM

; same for Y
	MAC	OBJ_Y_POS_SET
	.BYTE	$26
	.BYTE	{1},{2}
	ENDM

; add value to object's X position
	MAC	OBJ_X_POS_MOVE
	.BYTE	$27
	.BYTE	{1}
	ENDM

; same for Y
	MAC	OBJ_Y_POS_MOVE
	.BYTE	$28
	.BYTE	{0}
	ENDM

; set constant movement delta for X
	MAC	OBJ_X_DELTA_SET
	.BYTE	$29
	.BYTE	{0}
	ENDM

; same for Y
	MAC	OBJ_Y_DELTA_SET
	.BYTE	$2A
	.BYTE	{0}
	ENDM

; does some kind of acceleration, low nibble of delta
; added to x position with carry
	MAC	OBJ_X_DELTA_INC
	.BYTE	$2B
	ENDM

; same for Y
	MAC	OBJ_Y_DELTA_INC
	.BYTE	$2C
	ENDM

; same but with decrease
	MAC	OBJ_X_DELTA_DEC
	.BYTE	$2D
	ENDM

; same for Y
	MAC	OBJ_Y_DELTA_DEC
	.BYTE	$2E
	ENDM

; init object lock on target, {1} usually direction of target
	MAC	TARGET_LOCK
	.BYTE	$2F
	.BYTE	{1}
	ENDM

; set speed for traveling to target or some kind...
	MAC	TARGET_SPD_SET
	.BYTE	$30
	.BYTE	{1}
	ENDM

; other direction value for target lock
	MAC	TARGET_DIR_SET
	.BYTE	$31
	.BYTE	{1}
	ENDM

; set object dimensions for collision tests
	MAC	OBJ_SIZE_SET
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
	.BYTE	$33
	.BYTE	{1}
	ENDM

; define object's hitpoints. hp should be set even for undestructable
; objects because they threated as a existence of the object itself
; rather than activeness state flag
; NOTE, this var also used differently for cutscenes
	MAC	OBJ_HP_SET
	.BYTE	$34
	.BYTE	{1}
	ENDM

; set the vert/hor flips for object instantly
	MAC	OBJ_FLIP_SET
	.BYTE	$35
	.BYTE	{1}
	ENDM

; unused flag settings
;	MAC	VAR_1E_SET
;	.BYTE	$36
;	.BYTE	{1}
;	ENDM

; they used MOV operands here for some reasons...
	MAC	MAIN_SUB_SET
	.BYTE	$37
	.BYTE	{1}
	ENDM

; yes, it is parameters are speed and increment value
	MAC	PAL_FADE_IN
	.BYTE	$38
	.BYTE	{1},{2}
	ENDM

; same
	MAC	PAL_FADE_OUT
	.BYTE	$39
	.BYTE	{1},{2}
	ENDM

; never used, always used native handlers instead
	MAC	TLM_RES_QUEUE
	.BYTE	$3A
	.WORD	{1}
	ENDM

; yes, it is, parameter is an offset to menu data (options position and number)
	MAC	MENU_CURSOR_DRAW
	.BYTE	$3B
	.WORD	{1}
	ENDM

; never used, all menus are vertically oriented
	MAC	MENU_HOR_INPUT
	.BYTE	$3C
	.BYTE	{1},{2}
	ENDM

; same for vert menu, parameters are number of items in menu and default one
	MAC	MENU_VERT_INPUT
	.BYTE	$3D
	.BYTE	{1},{2}
	ENDM

; never used, msg area always the same and hardcoded in msg init routine
	MAC	MSG_AREA_SET
	.BYTE	$3E
	.WORD	{1}
	.BYTE	{2}
	ENDM

; displays the message in already defined window, {1} ptr to msg resource
; {2} is the APU SE index to make typing sound for every character
	MAC	MSG_DISPLAY
	.BYTE	$3F
	.WORD	{1}
	.BYTE	{2}
	ENDM

; wait until message is displayed
	MAC	MSG_WAIT
	.BYTE	$40
	ENDM

; break current subroutine and exit instantly, argument is return address
	MAC	BREAK
	.BYTE	$41
	.WORD	{1}
	ENDM

; set default script routine for object when destroyed or collision detected
; called from object manager instantly if collision test passed
;
	MAC	DESTR_PC_SET
	.BYTE	$42
	.WORD	{1}
	ENDM

; other flags set cmd
	MAC	PARAM_40_SET
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

