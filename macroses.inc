;-------------C-O-N-S-T-A-N-T-S-----------------

DEBUG			EQU		1

;-----------G-A-M-E--S-P-E-C-I-F-I-C------------

	MAC	_tlvl
{1}		SET	.
{1}._chrs:			.BYTE 0,0
{1}._lvl_start_X:	.BYTE 0
{1}._lvl_start_Y:	.BYTE 0
{1}._players_X:		.BYTE 0
{1}._players_Y:		.BYTE 0
{1}._flags:			.BYTE 0
{1}._layout_ptr:	.WORD 0
{1}._scrolls_ptr:	.WORD 0
{1}._tiles_ptr:		.WORD 0
{1}._prizes_ptr:	.WORD 0
{1}._enemies_ptr:	.WORD 0
{1}._mmc1_ctrl:		.BYTE 0
{1}._split_pos:		.BYTE 0
{1}._music_idx:		.BYTE 0
{1}.field_14:		.BYTE 0,0
{1}._bg_pal_ptr:	.WORD 0
{1}.field_18:		.BYTE 0
	ENDM

	MAC	_tscreen_res
{1}		SET	.
{1}._ppu_mode:		.BYTE 0
{1}._pal_bg_ptr:	.WORD 0
{1}._pal_spr_ptr:	.WORD 0
{1}._fill_tile:		.BYTE 0
{1}._attr_fill:		.BYTE 0
{1}._nt_ofs:		.BYTE 0
{1}._chr_banks:		.BYTE 0,0,0,0
{1}._scrolls:		.BYTE 0,0,0,0
{1}._sprites:		.BYTE 0,0,0,0
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

	MAC SECTION_START
_{1}_start	SET	.
	ENDM

	MAC SECTION_END
_{1}_end	SET .
		ECHO	" * block =",_{1}_end-_{1}_start,"[",${1},"]"
	ENDM

	MAC SECTION_ENDS
_{1}_end	SET .
		ECHO	" * block =",_{1}_end-_{1}_start,"[",{2},"]"
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

