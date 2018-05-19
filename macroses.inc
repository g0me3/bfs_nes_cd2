;-------------C-O-N-S-T-A-N-T-S-----------------

DEBUG			EQU		1

;-----------G-A-M-E--S-P-E-C-I-F-I-C------------

;	stop script
	MAC	STOP
	.BYTE	$00
	ENDM

; flush registers and flags
	MAC	FLUSH
	.BYTE	$01
	ENDM

; delay frames
	MAC	DELAY
	.BYTE	$02
	.BYTE	{1}
	ENDM

; native code read operation, flags stored
	MAC	NJMP
	.BYTE	$03
	.WORD	{1}
	ENDM

; queue new script and run
	MAC	RUN
	.BYTE	$04
	.BYTE	{1}
	.WORD	{2}
	ENDM

; native code execute, no flags returned
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
	MAC	RET
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

; set of branches equivalent of 6502 set
; script if EQUAL branch
	MAC	SBEQ
	.BYTE	$0B
	.WORD	{1}
	ENDM

; script if CARRY=1 branch
	MAC	SBCS
	.BYTE	$0C
	.WORD	{1}
	ENDM

; script if NEG=1 branch
	MAC	SBMI
	.BYTE	$0D
	.WORD	{1}
	ENDM

; script if NO EQUAL branch
	MAC	SBNE
	.BYTE	$0E
	.WORD	{1}
	ENDM

; script if CARRY=0 branch
	MAC	SBCC
	.BYTE	$0F
	.WORD	{1}
	ENDM

; script if NEG=0 branch
	MAC	SBPL
	.BYTE	$10
	.WORD	{1}
	ENDM

; test pads pad offset {1}, mask {2}, branch if non-zero {3}
; $00 - pad1 held
; $01 - pad2 held
; $04 - pad1 press
; $05 - pad2 press

_PAD0_HELD	EQU	$00
_PAD1_HELD	EQU	$01
_PAD0_PRESS	EQU $04
_PAD1_PRESS	EQU $05

	MAC	TEST_PADS
	.BYTE	$11
	.BYTE	{1},{2}
	.WORD	{3}
	ENDM

; switch case construction, {1} index ram variable, first branch default
	MAC	SWITCH
	.BYTE	$12
	.WORD	{1}
	ENDM
; lets make it nice
	MAC	CASE
	.WORD	{1}
	ENDM

; store operand, put {1} into {2} ram address
	MAC	MOV
	.BYTE	$13
	.BYTE	{1}
	.WORD	{2}
	ENDM

; {1} chr bank idx, {2} value
	MAC	CHR_BANK
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

; do animations for one frame, delay with animations of some kind
; seems should return some values or flags
	MAC	JMP_OBJ_ANIMATE
	.BYTE	$18
	ENDM

; same as previous but without results
	MAC	JSR_OBJ_ANIMATE
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
	.BYTE	{1}
	ENDM

; select current sprite idx
	MAC	SPR_IDX_SELECT
	.BYTE	$1E
	.BYTE	{1}
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
	MAC	OBJ_SET_X_POS
	.BYTE	$25
	.BYTE	{1},{2}
	ENDM

; same for Y
	MAC	OBJ_SET_Y_POS
	.BYTE	$26
	.BYTE	{1},{2}
	ENDM

; add value to object's X position
	MAC	OBJ_MOVE_X_POS
	.BYTE	$27
	.BYTE	{1}
	ENDM

; same for Y
	MAC	OBJ_MOVE_Y_POS
	.BYTE	$28
	.BYTE	{0}
	ENDM

; set constant movement delta for X
	MAC	OBJ_SET_X_DELTA
	.BYTE	$29
	.BYTE	{0}
	ENDM

; same for Y
	MAC	OBJ_SET_Y_DELTA
	.BYTE	$2A
	.BYTE	{0}
	ENDM

; does some kind of acceleration, low nibble of delta
; added to x position with carry
	MAC	OBJ_INC_X_DELTA
	.BYTE	$2B
	ENDM

; same for Y
	MAC	OBJ_INC_Y_DELTA
	.BYTE	$2C
	ENDM

; same but with decrease
	MAC	OBJ_DEX_X_DELTA
	.BYTE	$2D
	ENDM

; same for Y
	MAC	OBJ_DEC_Y_DELTA
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
	MAC	OBJ_SET_SIZE
	.BYTE	$32
	.BYTE	{1},{2}
	ENDM

; some unk var by now something involving grabbing enemies or
; jumping on them
	MAC	VAR_1C_SET
	.BYTE	$33
	.BYTE	{1}
	ENDM

; define object's hitpoints
	MAC	OBJ_SET_HP
	.BYTE	$34
	.BYTE	{1}
	ENDM

; set the vert/hor flips for object instantly
	MAC	OBJ_SET_FLIP
	.BYTE	$35
	.BYTE	{1}
	ENDM

; unused flag settings
;	MAC	VAR_1E_SET
;	.BYTE	$36
;	.BYTE	{1}
;	ENDM

; they used MOV operands here for some reasons...
	MAC	MAIN_SUB_IDX_SET
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
	MAC	DRAW_MENU_CURSOR
	.BYTE	$3B
	.WORD	{1}
	ENDM

; never used, all menus are vertically oriented
	MAC	HOR_MENU_INPUT
	.BYTE	$3C
	.BYTE	{1},{2}
	ENDM

; same for vert menu, parameters are number of items in menu and default one
	MAC	VERT_MENU_INPUT
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

; set default script routine for object when destroyed
; called from object manager instantly if collision test
; passed
	MAC	DESTR_PC_SET
	.BYTE	$42
	.WORD	{1}
	ENDM

; other flags set cmd
	MAC	PARAM_40_SET
	.BYTE	$43
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

