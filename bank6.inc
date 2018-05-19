
		ORG $8000

		BANK_START $06

; =============== S U B R O U T I N E =======================================
_apu_play:
		LDA		_apu_load_idx
		BMI		loc_98007
		JSR		_apu_load
loc_98007:
		LDY		#$06
		LDX		_apu_mus_allow_flag
		BEQ		loc_98011
		LDY		#$02
		LDX		#$04
loc_98011:
		STX		_apu_tmpF7
loc_98013:
		TYA
		PHA
		LDX		_apu_tmpF7
		LDA		_apu_active_chnls_flags
		AND		_apu_set_bitmasks,X
		BEQ		loc_98027
		JSR		_apu_playA
		JSR		_apu_playB
		JSR		_apu_playC
loc_98027:
		INC		_apu_tmpF7
		PLA
		TAY
		DEY
		BNE		loc_98013
		JSR		_apu_playD
		JSR		_apu_playE
		LDA		_apu_active_chnls_flags
		ORA		_apu_chnl_flags
		STA		_apu_active_chnls_flags
		LDA		#$00
		STA		_apu_chnl_flags
		RTS

; =============== S U B R O U T I N E =======================================
_apu_playC:
		LDY		_apu_varsD,X
		BMI		loc_98062
		LDA		_apu_vars9,X
		BNE		loc_98092
		TYA
		ASL
		TAY
		LDA		off_992B6,Y
		STA		_apu_cur_pc
		LDA		off_992B6+1,Y
		STA		_apu_cur_pc+1
		LDY		_apu_varsA,X
loc_98059:
		LDA		(_apu_cur_pc),Y
		INY
		CMP		#$FE
		BEQ		loc_98070
		BCC		loc_9807F
loc_98062:
		LDA		#$00
		STA		_apu_vars8,X
		LDA		_apu_varsD,X
		ORA		#$80
		STA		_apu_varsD,X
		RTS
loc_98070:
		LDA		(_apu_cur_pc),Y
		STA		_apu_vars13,X
		INY
		LDA		(_apu_cur_pc),Y
		STA		_apu_vars8,X
		INY
		JMP		loc_98059
loc_9807F:
		STA		_apu_vars9,X
		LDA		(_apu_cur_pc),Y
		STA		_apu_vars14,X
		INY
		LDA		(_apu_cur_pc),Y
		STA		_apu_vars15,X
		INY
		TYA
		STA		_apu_varsA,X
loc_98092:
		CLC
		LDA		_apu_vars13,X
		ADC		_apu_vars14,X
		STA		_apu_vars13,X
		LDA		_apu_vars8,X
		ADC		_apu_vars15,X
		STA		_apu_vars8,X
		DEC		_apu_vars9,X
		RTS

; =============== S U B R O U T I N E =======================================
_apu_playE:
		LDA		_apu_mus_allow_flag
		BNE		loc_980BE
		LDX		#$00
loc_980AF:
		LDA		_apu_active_chnls_flags
		AND		byte_980D0,X
		BNE		loc_980B9
		JSR		_apu_playE_A
loc_980B9:
		INX
		CPX		#$04
		BCC		loc_980AF
loc_980BE:
		LDX		#$04
loc_980C0:
		LDA		_apu_active_chnls_flags
		AND		_apu_set_bitmasks,X
		BEQ		loc_980CA
		JSR		_apu_playE_A
loc_980CA:
		INX
		CPX		#$06
		BCC		loc_980C0
		RTS
byte_980D0:
		.BYTE	$00,$10,$00,$20

; =============== S U B R O U T I N E =======================================
_apu_playE_A:
		TXA
		ASL
		TAY
		LDA		off_980E5,Y
		STA		_apu_tmpF2
		LDA		off_980E5+1,Y
		STA		_apu_tmpF3
		JMP		(_apu_tmpF2)

; =============== S U B R O U T I N E =======================================
nullsub6:
		RTS
off_980E5:
		.WORD	_apu_playE_A_sub0
		.WORD	_apu_playE_A_sub1
		.WORD	_apu_playE_A_sub2
		.WORD	_apu_playE_A_sub3
		.WORD	_apu_playE_A_sub4
		.WORD	_apu_playE_A_sub5

; =============== S U B R O U T I N E =======================================
_apu_playE_A_sub0:
		LDY		#$00
		JSR		_apu_playE_A_sub0_A
		JSR		_apu_playE_A_sub0_B
		JMP		nullsub6

; =============== S U B R O U T I N E =======================================
_apu_playE_A_sub1:
		LDA		_apu_var12
		BEQ		_apu_playE_A_sub4
		JSR		_apu_playE_A_sub1_A
		JMP		nullsub6
_apu_playE_A_sub4:
		LDY		#$04
		JSR		_apu_playE_A_sub0_A
		JSR		_apu_playE_A_sub0_B
		JMP		nullsub6

; =============== S U B R O U T I N E =======================================
_apu_playE_A_sub2:
		LDY		#$08
		JSR		_apu_playE_A_sub0_A
		JSR		_apu_playE_A_sub0_B
		JMP		nullsub6

; =============== S U B R O U T I N E =======================================
_apu_playE_A_sub3:
		LDA		_apu_var13
		BEQ		_j_nullsub6

; =============== S U B R O U T I N E =======================================
_apu_playE_A_sub5:
		LDY		#$0C
		JSR		_apu_playE_A_sub0_A
		JSR		_apu_playE_A_sub0_B

; =============== S U B R O U T I N E =======================================
_j_nullsub6:
		JMP		nullsub6

; =============== S U B R O U T I N E =======================================
_apu_playE_A_sub0_A:
		LDA		_apu_vars8,X
		LSR
		LSR
		LSR
		LSR
		SEC
		SBC		_apu_vars1,X
		BCC		loc_9813F
		SEC
		SBC		_apu_tmpFB
		BCS		loc_98141
loc_9813F:
		LDA		#$00
loc_98141:
		CPY		#$08
		BNE		loc_9814B
		ASL
		ASL
		ORA		#$80
		BNE		loc_98150
loc_9814B:
		ORA		_apu_vars12,X
		ORA		#$30
loc_98150:
		STA		_APU_PULSE1_ENV,Y
		RTS

; =============== S U B R O U T I N E =======================================
_apu_playE_A_sub0_B:
		LDA		_apu_varsE,X
		ORA		_apu_varsB,X
		BEQ		loc_98167
		LDA		_apu_varsC,X
		STA		_APU_PULSE1_SWEEP,Y
		LDA		#$00
		STA		_apu_varsB,X
loc_98167:
		LDA		_apu_varsE,X
		BNE		loc_9816D
		RTS
loc_9816D:
		LDA		#$00
		STA		_apu_varsE,X
		TYA
		PHA
		LDA		_apu_vars6,X
		STA		_apu_tmpF2
		LDA		_apu_vars7,X
		STA		_apu_tmpF3
		PLA
		TAY
		LSR		_apu_tmpF3
		ROR		_apu_tmpF2
		LDA		_apu_tmpF2
		STA		_APU_PULSE1_TIME,Y
		LDA		_apu_tmpF3
		AND		#$07
		ORA		#$F8
		STA		_APU_PULSE1_LEN,Y
		RTS

; =============== S U B R O U T I N E =======================================
_apu_playE_A_sub1_A:
		LDA		_apu_vars8+3
		LSR
		LSR
		LSR
		LSR
		SEC
		SBC		_apu_vars1+3
		BCC		loc_981A5
		SEC
		SBC		_apu_tmpFB
		BCS		loc_981A7
loc_981A5:
		LDA		#$00
loc_981A7:
		ORA		_apu_vars12+3
		ORA		#$10
		STA		_APU_PULSE2_ENV
		LDA		_apu_var11
		LSR
		TAY
		LDA		_apu_var10
		ROR
		STA		_APU_PULSE2_TIME
		TYA
		ORA		#$F8
		STA		_APU_PULSE2_LEN
		RTS

; =============== S U B R O U T I N E =======================================
_apu_playD:
		LDA		_apu_mus_allow_flag
		BNE		nullsub2
		LDA		_apu_snd1_allow_flag
		BEQ		locret_981E4
		LDA		_apu_tmpFB
		CMP		#$10
		BCS		loc_981E0
		INC		_apu_tmpFA
		LDA		_apu_tmpFA
		CMP		#$04
		BCC		locret_981E4
		LDA		#$00
		STA		_apu_tmpFA
		INC		_apu_tmpFB
		BNE		locret_981E4
loc_981E0:
		LDA		#$00
		STA		_apu_snd1_allow_flag
locret_981E4:
		RTS

; =============== S U B R O U T I N E =======================================
_apu_playF_unref:
		LDA		_apu_snd0_allow_flag
		BEQ		nullsub2
		INC		_apu_tmpFA
		LDA		_apu_tmpFA
		CMP		#$04
		BCC		nullsub2
		LDA		#$00
		STA		_apu_tmpFA
		LDA		_apu_tmpFB
		BNE		loc_981FD
		STA		_apu_snd0_allow_flag
		BEQ		nullsub2
loc_981FD:
		DEC		_apu_tmpFB

; =============== S U B R O U T I N E =======================================
nullsub2:
		RTS

; =============== S U B R O U T I N E =======================================
_apu_load:
		ORA		#$80
		STA		_apu_load_idx
		AND		#$7F
		BEQ		_apu_all_stop
		CMP		#$79
		BCS		loc_9820F
		JMP		_apu_load_data
loc_9820F:
		SBC		#$79
		ASL
		TAY
		LDA		_apu_stop_lib,Y
		STA		_apu_tmpF2
		LDA		_apu_stop_lib+1,Y
		STA		_apu_tmpF3
		JMP		(_apu_tmpF2)
_apu_stop_lib:
		.WORD	_apu_mus_allow
		.WORD	_apu_mus_mute
		.WORD	_apu_snd1_mute_snd0_allow
		.WORD	_apu_snd0_mute_snd1_allow
		.WORD	_apu_mus_stop
		.WORD	_apu_snd_stop
		.WORD	_apu_all_stop

; =============== S U B R O U T I N E =======================================
_apu_mus_allow:
		LDA		#$00
		STA		_apu_mus_allow_flag
		RTS

; =============== S U B R O U T I N E =======================================
_apu_mus_mute:
		LDA		#$01
		STA		_apu_mus_allow_flag
		LDA		#$00
		STA		_APU_PULSE1_ENV
		STA		_APU_PULSE2_ENV
		STA		_APU_TRI_TIME
		STA		_APU_TRI_LEN
		STA		_APU_NOISE_ENV
		RTS

; =============== S U B R O U T I N E =======================================
_apu_snd0_mute_snd1_allow:
		LDA		#$00
		STA		_apu_snd1_allow_flag
		LDA		#$01
		STA		_apu_snd0_allow_flag
		RTS

; =============== S U B R O U T I N E =======================================
_apu_snd1_mute_snd0_allow:
		LDA		#$00
		STA		_apu_snd0_allow_flag
		LDA		#$01
		STA		_apu_snd1_allow_flag
		RTS

; =============== S U B R O U T I N E =======================================
_apu_mus_stop:
		LDA		#$00
		STA		_apu_snd0_allow_flag
		STA		_apu_snd1_allow_flag
		LDX		#$00
		LDY		#$04
		JMP		_apu_chnls_stop

; =============== S U B R O U T I N E =======================================
_apu_snd_stop:
		LDX		#$04
		LDY		#$02

; =============== S U B R O U T I N E =======================================
_apu_chnls_stop:
		JSR		_apu_chnl_init
		INX
		DEY
		BNE		_apu_chnls_stop
		RTS

; =============== S U B R O U T I N E =======================================
_apu_all_stop:
		LDY		#$13
		LDA		#$00
loc_98278:
		STA		_APU_PULSE1_ENV,Y
		DEY
		BPL		loc_98278
		LDA		#$08
		STA		_APU_PULSE1_ENV
		STA		_APU_PULSE2_ENV
		LDA		#$40
		STA		_APU_TRI_COUNT
		LDA		#$10
		STA		_APU_NOISE_ENV
		LDA		#$8F
		STA		_APU_STATUS
		LDA		#$C0
		STA		_PAD1_REG
		LDA		#$00
		STA		_apu_cur_pc
		LDA		#$07
		STA		_apu_cur_pc+1
		LDA		#$FD
		STA		_apu_tmpF2
		LDA		#$00
		STA		_apu_tmpF3
		LDY		#$00
		STY		_apu_mus_allow_flag
		STY		_apu_snd0_allow_flag
		STY		_apu_snd1_allow_flag
		STY		_apu_tmpFB
loc_982B4:
		TYA
		STA		(_apu_cur_pc),Y
		INC		_apu_cur_pc
		BNE		loc_982BD
		INC		_apu_cur_pc+1
loc_982BD:
		SEC
		LDA		_apu_tmpF2
		SBC		#$01
		STA		_apu_tmpF2
		LDA		_apu_tmpF3
		SBC		#$00
		STA		_apu_tmpF3
		ORA		_apu_tmpF2
		BNE		loc_982B4
		LDA		#<[byte_992B5]
		STA		_apu_ptr0
		LDA		#>[byte_992B5]
		STA		_apu_ptr0+1
		LDX		#$00
loc_982DA:
		JSR		_apu_chnl_init
		INX
		CPX		#$04
		BNE		loc_982DA
		RTS

; =============== S U B R O U T I N E =======================================
_apu_chnl_init:
		LDA		byte_98328,X
		STA		_apu_chnl_sp,X
		LDA		#<[_apu_chnl_data_dummy]
		STA		_apu_chnl_pc_lo,X
		LDA		#>[_apu_chnl_data_dummy]
		STA		_apu_chnl_pc_hi,X
		LDA		#$00
		STA		_apu_vars1,X
		STA		_apu_vars2,X
		STA		_apu_vars3,X
		STA		_apu_vars4,X
		STA		_apu_chnl_delay,X
		STA		_apu_tmpFD
		STA		_apu_vars6,X
		STA		_apu_vars7,X
		STA		_apu_vars8,X
		STA		_apu_vars9,X
		STA		_apu_varsA,X
		STA		_apu_varsB,X
		LDA		#$08
		STA		_apu_varsC,X
		LDA		#$80
		STA		_apu_varsD,X
		LDA		#$00
		STA		_apu_varsE,X
		RTS
byte_98328:
		.BYTE	$00,$10,$20,$30,$40,$50

; =============== S U B R O U T I N E =======================================
_apu_load_data:
		ASL
		TAX
		LDA		_apu_mus_lib,X
		STA		_apu_cur_pc
		LDA		_apu_mus_lib+1,X
		STA		_apu_cur_pc+1
		LDY		#$00
		LDA		(_apu_cur_pc),Y
		STA		_apu_tmpF2
		STA		_apu_chnl_flags
		AND		#$30
		BNE		loc_9836C
		LDA		#$00
		STA		_apu_mus_allow_flag
		STA		_apu_snd0_allow_flag
		STA		_apu_snd1_allow_flag
		STA		_apu_tmpFB
		STA		_apu_var12
		STA		_apu_var13
		LDX		#$0C
loc_98358:
		TXA
		STA		_apu_varsF,X
		DEX
		BPL		loc_98358
		LDX		#$00
		LDY		#$04
		LDA		_apu_active_chnls_flags
		AND		#$30
		STA		_apu_active_chnls_flags
		JMP		loc_9837C
loc_9836C:
		LSR
		LSR
		LSR
		LSR
		STA		_apu_tmpF2
		LDA		_apu_active_chnls_flags
		AND		#$0F
		STA		_apu_active_chnls_flags
		LDX		#$04
		LDY		#$02
loc_9837C:
		STY		_apu_tmpF3
		LDY		#$01
loc_98380:
		JSR		_apu_chnl_init
		LSR		_apu_tmpF2
		BCC		loc_98393
		LDA		(_apu_cur_pc),Y
		STA		_apu_chnl_pc_lo,X
		INY
		LDA		(_apu_cur_pc),Y
		STA		_apu_chnl_pc_hi,X
		INY
loc_98393:
		INX
		DEC		_apu_tmpF3
		BNE		loc_98380
		LDA		#$F0
		STA		_APU_NOISE_ENV
		RTS

; =============== S U B R O U T I N E =======================================
_apu_playA:
		LDA		_apu_chnl_delay,X
		BEQ		loc_983A9
		DEC		_apu_chnl_delay,X
		BEQ		loc_983A9
		RTS
loc_983A9:
		LDA		_apu_chnl_pc_lo,X
		STA		_apu_cur_pc
		LDA		_apu_chnl_pc_hi,X
		STA		_apu_cur_pc+1

; =============== S U B R O U T I N E =======================================
_apu_cmd_fetch:
		JSR		_apu_stream_get_byte
		CMP		#$D0
		BCC		_apu_data_load
		SEC
		SBC		#$D0
		ASL
		TAY
		LDA		_apu_cmd_lib,Y
		STA		_apu_tmpF2
		LDA		_apu_cmd_lib+1,Y
		STA		_apu_tmpF3
		LDA		off_983D4+1
		PHA
		LDA		off_983D4
		PHA
		JMP		(_apu_tmpF2)
off_983D4:
		.WORD	_apu_cmd_fetch-1

; =============== S U B R O U T I N E =======================================
_apu_data_load:
		PHA
		CLC
		AND		#$0F
		ADC		#$01
		STA		_apu_chnl_delay,X
		LDY		_apu_vars10,X
		BEQ		loc_983F0
		LDA		#$00
loc_983E6:
		CLC
		ADC		_apu_chnl_delay,X
		DEY
		BNE		loc_983E6
		STA		_apu_chnl_delay,X
loc_983F0:
		PLA
		AND		#$F0
		CMP		#$C0
		BNE		loc_98416
		LDA		_apu_varsD,X
		ORA		#$80
		STA		_apu_varsD,X
		LDA		#$00
		STA		_apu_vars6,X
		STA		_apu_vars7,X
		STA		_apu_varsA,X
		STA		_apu_vars9,X
		STA		_apu_vars8,X
		INC		_apu_varsE,X
		JMP		loc_98493
loc_98416:
		LDY		_apu_tmpFD
		BEQ		loc_9841D
		JMP		loc_98493
loc_9841D:
		PHA
		LDA		#$00
		STA		_apu_varsA,X
		STA		_apu_vars9,X
		STA		_apu_vars13,X
		STA		_apu_vars8,X
		LDA		_apu_varsD,X
		AND		#$7F
		STA		_apu_varsD,X
		PLA
		LSR
		LSR
		LSR
		LSR
		CPX		#$03
		BNE		loc_98443
		JSR		_apu_data_load_A
		JMP		loc_98493
loc_98443:
		CPX		#$05
		BNE		loc_98460
		SEC
		SBC		_apu_vars3,X
		SEC
		SBC		_apu_vars4,X
		ASL
		AND		#$1E
		STA		_apu_vars6,X
		LDA		#$00
		STA		_apu_vars7,X
		INC		_apu_varsE,X
		JMP		loc_98493
loc_98460:
		CLC
		ADC		_apu_vars11,X
		CLC
		ADC		_apu_vars3,X
		CLC
		ADC		_apu_vars4,X
		ASL
		TAY
		LDA		_apu_freq_table,Y
		STA		_apu_vars6,X
		LDA		_apu_freq_table+1,Y
		STA		_apu_vars7,X
		LDY		#$00
		LDA		_apu_vars2,X
		BPL		loc_98482
		DEY
loc_98482:
		CLC
		ADC		_apu_vars6,X
		STA		_apu_vars6,X
		TYA
		ADC		_apu_vars7,X
		STA		_apu_vars7,X
		INC		_apu_varsE,X
loc_98493:
		LDA		#$00
		STA		_apu_tmpFD
		LDA		_apu_cur_pc
		STA		_apu_chnl_pc_lo,X
		LDA		_apu_cur_pc+1
		STA		_apu_chnl_pc_hi,X
		RTS
_apu_cmd_lib:
		.WORD	_apu_cmdD0
		.WORD	_apu_cmdD1
		.WORD	_apu_cmdD2
		.WORD	_apu_cmdD3
		.WORD	_apu_cmdD4
		.WORD	_apu_cmdD5
		.WORD	_apu_cmdD6
		.WORD	_apu_cmdD7
		.WORD	_apu_cmdD8
		.WORD	_apu_cmdD9
		.WORD	_apu_cmdDA
		.WORD	_apu_cmdDB
		.WORD	0
		.WORD	0
		.WORD	0
		.WORD	0
		.WORD	_apu_cmdE0
		.WORD	_apu_cmdE1
		.WORD	_apu_cmdE2
		.WORD	_apu_cmdE3	; unused
		.WORD	_apu_cmdE4	; unused
		.WORD	_apu_cmdE5	; unused
		.WORD	0
		.WORD	0
		.WORD	_apu_cmdE8
		.WORD	_apu_cmdE9
		.WORD	_apu_cmdEA
		.WORD	_apu_cmdEB
		.WORD	_apu_cmdEC
		.WORD	_apu_cmdED	; unused
		.WORD	0
		.WORD	0
		.WORD	_apu_cmdF0
		.WORD	_apu_cmdF1
		.WORD	_apu_cmdF2
		.WORD	_apu_cmdF3
		.WORD	0
		.WORD	0
		.WORD	0
		.WORD	0
		.WORD	_apu_cmdF8
		.WORD	0
		.WORD	0
		.WORD	0
		.WORD	0
		.WORD	0
		.WORD	0
		.WORD	_apu_cmdFF

; =============== S U B R O U T I N E =======================================
; arg none
_apu_cmdD0:
		LDA		#$00
		BEQ		_apu_cmdDX

; =============== S U B R O U T I N E =======================================
; arg none
_apu_cmdD1:
		LDA		#$0C
		BNE		_apu_cmdDX

; =============== S U B R O U T I N E =======================================
; arg none
_apu_cmdD2:
		LDA		#$18
		BNE		_apu_cmdDX

; =============== S U B R O U T I N E =======================================
; arg none
_apu_cmdD3:
		LDA		#$24
		BNE		_apu_cmdDX

; =============== S U B R O U T I N E =======================================
; arg none
_apu_cmdD4:
		LDA		#$30
		BNE		_apu_cmdDX

; =============== S U B R O U T I N E =======================================
; arg none
_apu_cmdD5:
		LDA		#$3C
		BNE		_apu_cmdDX

; =============== S U B R O U T I N E =======================================
; arg none
_apu_cmdD6:
		LDA		#$48

; =============== S U B R O U T I N E =======================================
_apu_cmdDX:
		STA		_apu_vars11,X
		RTS

; =============== S U B R O U T I N E =======================================
; arg none
_apu_cmdD7:
		CLC
		LDA		_apu_vars11,X
		ADC		#$0C
		STA		_apu_vars11,X
		RTS

; =============== S U B R O U T I N E =======================================
; arg none
_apu_cmdD8:
		SEC
		LDA		_apu_vars11,X
		SBC		#$0C
		STA		_apu_vars11,X
		RTS

; =============== S U B R O U T I N E =======================================
; arg byte
_apu_cmdD9:
		JSR		_apu_stream_get_byte
		STA		_apu_vars3,X
		RTS

; =============== S U B R O U T I N E =======================================
; arg byte
_apu_cmdDA:
		JSR		_apu_stream_get_byte
		CLC
		ADC		_apu_vars4,X
		STA		_apu_vars4,X
		RTS

; =============== S U B R O U T I N E =======================================
; arg byte
_apu_cmdDB:
		JSR		_apu_stream_get_byte
		STA		_apu_vars2,X
		RTS

; =============== S U B R O U T I N E =======================================
; arg byte
_apu_cmdE0:
		JSR		_apu_stream_get_byte
		STA		_apu_vars10,X
		RTS

; =============== S U B R O U T I N E =======================================
; arg byte
_apu_cmdE1:
		JSR		_apu_stream_get_byte
		ROR
		ROR
		ROR
		AND		#$C0
		STA		_apu_vars12,X
		RTS

; =============== S U B R O U T I N E =======================================
; arg byte
_apu_cmdE2:
		JSR		_apu_stream_get_byte
		ORA		#$80
		STA		_apu_varsD,X
		LDA		#$00
		STA		_apu_varsA,X
		STA		_apu_vars9,X
		RTS

; =============== S U B R O U T I N E =======================================
; dummy
_apu_cmdE3:
		JSR		_apu_stream_get_byte
		RTS

; =============== S U B R O U T I N E =======================================
; dummy
_apu_cmdE4:
		JSR		_apu_stream_get_byte
		RTS

; =============== S U B R O U T I N E =======================================
; dummy
_apu_cmdE5:
		JSR		_apu_stream_get_byte
		RTS

; =============== S U B R O U T I N E =======================================
; arg none
_apu_cmdE8:
		LDA		#$01
		STA		_apu_tmpFD
		RTS

; =============== S U B R O U T I N E =======================================
; arg byte
_apu_cmdE9:
		JSR		_apu_stream_get_byte
		STA		_apu_vars1,X
		RTS

; =============== S U B R O U T I N E =======================================
; arg byte
_apu_cmdEA:
		JSR		_apu_stream_get_byte
		CLC
		ADC		_apu_vars1,X
		STA		_apu_vars1,X
		RTS

; =============== S U B R O U T I N E =======================================
; arg byte
_apu_cmdEB:
		JSR		_apu_stream_get_byte
		STA		_apu_varsC,X
		INC		_apu_varsB,X
		RTS

; =============== S U B R O U T I N E =======================================
; arg none
_apu_cmdEC:
		LDA		#$08
		STA		_apu_varsC,X
		INC		_apu_varsB,X
		RTS

; =============== S U B R O U T I N E =======================================
; LOOP START arg byte ofs
_apu_cmdF0:
		JSR		_apu_stream_get_byte
		PHA
		JSR		_apu_chnl_push_pc
		PLA
		JMP		_apu_chnl_push_byte

; =============== S U B R O U T I N E =======================================
; DO LOOP args none
_apu_cmdF1:
		JSR		_apu_chnl_pop_byte
		SEC
		SBC		#$01
		BEQ		loc_985C5
		PHA
		JSR		_apu_chnl_pop_pc
		JSR		_apu_chnl_push_pc
		PLA
		JMP		_apu_chnl_push_byte
loc_985C5:
		JSR		_apu_chnl_pop_byte
		JMP		_apu_chnl_pop_byte

; =============== S U B R O U T I N E =======================================
; JSR arg ofs
_apu_cmdF2:
		JSR		_apu_stream_get_byte
		PHA
		JSR		_apu_stream_get_byte
		PHA
		JSR		_apu_chnl_push_pc
		PLA
		STA		_apu_cur_pc+1
		PLA
		STA		_apu_cur_pc
		RTS

; =============== S U B R O U T I N E =======================================
; RET arg none
_apu_cmdF3:
		JMP		_apu_chnl_pop_pc

; =============== S U B R O U T I N E =======================================
; JMP arg ofs
_apu_cmdF8:
		JSR		_apu_stream_get_byte
		PHA
		JSR		_apu_stream_get_byte
		STA		_apu_cur_pc+1
		PLA
		STA		_apu_cur_pc
		RTS

; =============== S U B R O U T I N E =======================================
; arg byte
_apu_cmdED:
		TXA
		PHA
		JSR		_apu_stream_get_byte
		PHA
		ROR
		ROR
		ROR
		ROR
		AND		#$0F
		TAX
		PLA
		AND		#$0F
		TAY
		LDA		_apu_varsF,X
		PHA
		LDA		_apu_varsF,Y
		STA		_apu_varsF,X
		PLA
		STA		_apu_varsF,Y
		PLA
		TAX
		RTS

; =============== S U B R O U T I N E =======================================
; STOP args none
_apu_cmdFF:
		LDA		_apu_active_chnls_flags
		AND		_apu_clear_bitmasks,X
		STA		_apu_active_chnls_flags
		JSR		_apu_chnl_init
		PLA
		PLA
		RTS
_apu_set_bitmasks:
		.BYTE	$01,$02,$04,$08,$10,$20,$40,$80
_apu_clear_bitmasks:
		.BYTE	$FE,$FD,$FB,$F7,$EF,$DF,$BF,$7F

; =============== S U B R O U T I N E =======================================
_apu_stream_get_byte:
		LDY		#$00
		LDA		(_apu_cur_pc),Y
		INC		_apu_cur_pc
		BNE		locret_98636
		INC		_apu_cur_pc+1
locret_98636:
		RTS

; =============== S U B R O U T I N E =======================================
_apu_chnl_push_pc:
		LDA		_apu_cur_pc+1
		JSR		_apu_chnl_push_byte
		LDA		_apu_cur_pc

; =============== S U B R O U T I N E =======================================
_apu_chnl_push_byte:
		LDY		_apu_chnl_sp,X
		STA		_apu_chnl_stack,Y
		INC		_apu_chnl_sp,X
		RTS

; =============== S U B R O U T I N E =======================================
_apu_chnl_pop_pc:
		JSR		_apu_chnl_pop_byte
		STA		_apu_cur_pc
		JSR		_apu_chnl_pop_byte
		STA		_apu_cur_pc+1
		RTS

; =============== S U B R O U T I N E =======================================
_apu_chnl_pop_byte:
		DEC		_apu_chnl_sp,X
		LDY		_apu_chnl_sp,X
		LDA		_apu_chnl_stack,Y
		RTS

; =============== S U B R O U T I N E =======================================
_apu_data_load_A:
		TAY
		LDA		_apu_varsF,Y
		ASL
		TAY
		LDA		off_99283,Y
		STA		_apu_ptr0
		LDA		off_99283+1,Y
		STA		_apu_ptr0+1
		RTS

; =============== S U B R O U T I N E =======================================
_apu_playB:
		LDX		_apu_tmpF7
		CPX		#$03
		BEQ		loc_98677
locret_98676:
		RTS
loc_98677:
		LDA		_apu_varsD,X
		BMI		locret_98676
		LDA		#$00
		STA		_apu_var12
		STA		_apu_var13
		LDA		_apu_ptr0
		STA		_apu_cur_pc
		LDA		_apu_ptr0+1
		STA		_apu_cur_pc+1
loc_9868E:
		JSR		_apu_stream_get_byte
		TAY
		CMP		#$FF
		BEQ		loc_986FB
		AND		#$E0
		BEQ		loc_986CA
		CMP		#$E0
		BEQ		loc_986BE
		CMP		#$40
		BEQ		loc_986DE
		CMP		#$80
		BEQ		loc_986AD
		CMP		#$A0
		BEQ		loc_986AD
		JMP		loc_986FB
loc_986AD:
		TYA
		AND		#$3F
		STA		_apu_varsD,X
		LDA		#$00
		STA		_apu_varsA,X
		STA		_apu_vars9,X
		JMP		loc_9868E
loc_986BE:
		TYA
		ROR
		ROR
		ROR
		AND		#$C0
		STA		_apu_vars12,X
		JMP		loc_9868E
loc_986CA:
		INC		_apu_var13
		TYA
		AND		#$1F
		STA		_apu_vars6,X
		LDA		#$00
		STA		_apu_vars7,X
		INC		_apu_varsE,X
		JMP		loc_986F0
loc_986DE:
		INC		_apu_var12
		TYA
		AND		#$0F
		STA		_apu_var11
		JSR		_apu_stream_get_byte
		STA		_apu_var10
		INC		_apu_varsE+1
loc_986F0:
		LDA		_apu_cur_pc
		STA		_apu_ptr0
		LDA		_apu_cur_pc+1
		STA		_apu_ptr0+1
		RTS
loc_986FB:
		LDA		#$00
		STA		_apu_var12
		STA		_apu_var13
		STA		_apu_vars7,X
		STA		_apu_vars6,X
		INC		_apu_var13
		RTS
_apu_freq_table:
		.WORD	$0000,$0000,$0000,$0000,$0000,$0000,$0000,$0000
		.WORD	$0000,$0FE2,$0EFE,$0E26,$0D5C,$0C9A,$0BE6,$0B3A
		.WORD	$0A9A,$0A00,$0972,$08EA,$086A,$07F0,$077E,$0712
		.WORD	$06AC,$064C,$05F2,$059C,$054C,$0500,$04B8,$0474
		.WORD	$0434,$03F8,$03BE,$0388,$0356,$0326,$02F8,$02CE
		.WORD	$02A4,$027E,$025A,$0238,$0218,$01FA,$01DE,$01C4
		.WORD	$01AA,$0192,$017A,$0166,$0152,$013E,$012C,$011C
		.WORD	$010C,$00FC,$00EE,$00E0,$00D4,$00C8,$00BC,$00B2
		.WORD	$00A8,$009E,$0096,$008C,$0084,$007E,$0076,$0070
		.WORD	$0068,$0062,$005E,$0058,$0052,$004E,$004A,$0046
		.WORD	$0042,$003E,$003A,$0036
_apu_mus_lib:
		.WORD	_apu_mus00
		.WORD	_apu_mus01
		.WORD	_apu_mus02
		.WORD	_apu_mus03
		.WORD	_apu_mus04
		.WORD	_apu_mus05
		.WORD	_apu_mus06
		.WORD	_apu_mus07
		.WORD	_apu_mus08
		.WORD	_apu_mus09
		.WORD	_apu_mus0A
		.WORD	_apu_mus0B
		.WORD	_apu_mus0C
		.WORD	_apu_mus0D
		.WORD	_apu_mus0E
		.WORD	_apu_mus0F
		.WORD	_apu_mus10
		.WORD	_apu_mus11
		.WORD	_apu_mus12
		.WORD	_apu_mus13
		.WORD	_apu_mus14
		.WORD	_apu_mus15
		.WORD	_apu_mus16
		.WORD	_apu_mus17
		.WORD	_apu_mus18
		.WORD	_apu_mus19
		.WORD	_apu_mus1A
		.WORD	_apu_mus1B
		.WORD	_apu_mus1C
		.WORD	_apu_mus1D
		.WORD	_apu_mus1E
		.WORD	_apu_mus1F
		.WORD	_apu_mus20
		.WORD	_apu_mus21
		.WORD	_apu_mus22
		.WORD	_apu_mus23
		.WORD	_apu_mus24
		.WORD	_apu_mus25
		.WORD	_apu_mus26
		.WORD	_apu_mus27
		.WORD	_apu_mus28
		.WORD	_apu_mus29
		.WORD	_apu_mus2A
		.WORD	_apu_mus2B
		.WORD	_apu_mus2C
		.WORD	_apu_mus2D
		.WORD	_apu_mus2E
		.WORD	_apu_mus2F
		.WORD	_apu_mus30
		.WORD	_apu_mus31
		.WORD	_apu_mus32
		.WORD	_apu_mus33
		.WORD	_apu_mus34
		.WORD	_apu_mus35
		.WORD	_apu_mus36
		.WORD	_apu_mus37
		.WORD	_apu_mus38
		.WORD	_apu_mus39
		.WORD	_apu_mus3A
		.WORD	_apu_mus3B
		.WORD	_apu_mus3C
		.WORD	_apu_mus3D
		.WORD	_apu_mus3E
		.WORD	_apu_mus3F
		.WORD	_apu_mus40
		.WORD	_apu_mus41
		.WORD	_apu_mus42
		.WORD	_apu_mus43
		.WORD	_apu_mus44
		.WORD	_apu_mus45
		.WORD	_apu_mus46
		.WORD	_apu_mus47
		.WORD	_apu_mus4A
		.WORD	_apu_mus4A
		.WORD	_apu_mus4A
		.WORD	_apu_mus4B
		.WORD	_apu_mus4D
		.WORD	_apu_mus4D
		.WORD	_apu_mus4E
		.WORD	_apu_mus4F
		.WORD	_apu_mus50
		.WORD	_apu_mus51
		.WORD	_apu_mus52
		.WORD	_apu_mus53
		.WORD	_apu_mus54
		.WORD	_apu_mus55
		.WORD	_apu_mus56
		.WORD	_apu_mus57
		.WORD	_apu_mus58
		.WORD	_apu_mus59
		.WORD	_apu_mus5A
		.WORD	_apu_mus5B
		.WORD	_apu_mus5C
		.WORD	_apu_mus5D
		.WORD	_apu_mus5E
		.WORD	_apu_mus5F
		.WORD	_apu_mus60
		.WORD	_apu_mus61
		.WORD	_apu_mus62
		.WORD	_apu_mus63
		.WORD	_apu_mus64
		.WORD	_apu_mus65
		.WORD	_apu_mus66
		.WORD	_apu_mus67
		.WORD	_apu_mus68
		.WORD	_apu_mus69
		.WORD	_apu_mus6A
		.WORD	_apu_mus6B
		.WORD	_apu_mus6C
		.WORD	_apu_mus6D
		.WORD	_apu_mus6E
		.WORD	_apu_mus6F
		.WORD	_apu_mus70
		.WORD	_apu_mus71
		.WORD	_apu_mus72
		.WORD	_apu_mus73
		.WORD	_apu_mus74
_apu_mus22:
		.BYTE	$10
		.WORD	_apu_mus22_A
_apu_mus22_A:
		CMDE2	$04
		CMDE1	$00
		CMDE0	$01
		CMDE9	$00
		CMDE1	$02
		LOOP_START	$03
			CMDD5
			DATA	$00
			CMDDA	$FF
			CMDEA	$04
		DO_LOOP
		CMDDA	$03
		CMDEA	$F4
		DATA	$C0
		CMDDB	$FD
		CMDD6
		CMDE9	$00
		LOOP_START	$06
			CMDE1	$01
			CMDD9	$F4
			DATA	$B7
			CMDEA	$03
		DO_LOOP
		DATA	$C0
		ASTOP
_apu_mus23:
		.BYTE	$10
		.WORD	_apu_mus23_A
_apu_mus23_A:
		CMDE2	$04
		CMDE1	$02
		CMDE0	$01
		CMDD3
		LOOP_START	$08
			CMDEB	$B3
			DATA	$71,$41
			CMDDA	$04
		DO_LOOP
		DATA	$C0
		ASTOP
_apu_mus24:
		.BYTE	$10
		.WORD	_apu_mus24_A
_apu_mus24_A:
		CMDE2	$04
		CMDE1	$00
		CMDE0	$01
		CMDE9	$00
		CMDD3
		CMDEB	$93
		DATA	$40,$50,$40,$50
		CMDEB	$9B
		DATA	$00,$10,$00,$10
		CMDEC	$D4
		CMDDB	$08
			LOOP_START	$10
			DATA	$70
			CMDDA	$FF
		DO_LOOP
		DATA	$C0
		ASTOP
_apu_mus25:
		.BYTE	$30
		.WORD	_apu_mus25_A
		.WORD	_apu_mus25_B
_apu_mus25_A:
		CMDE2	$04
		CMDE1	$00
		CMDE0	$01
		CMDE9	$00
		CMDDA	$06
		CMDD9	$FB
		CMDD3
		CMDEB	$93
		DATA	$41
		CMDD9	$F8
		CMDEB	$9B
		DATA	$00
		CMDD9	$F8
		CMDD2
		LOOP_START	$02
			CMDEB	$93
			DATA	$90
			CMDEB	$9B
			DATA	$00
			CMDE9	$00
		DO_LOOP
		CMDEB	$95
		DATA	$97,$C0
		ASTOP
_apu_mus25_B:
		CMDE2	$04
		CMDE1	$00
		CMDE0	$01
		CMDE9	$00
		DATA	$B2,$C1,$A2
		CMDE9	$02
		DATA	$92,$82
		CMDE9	$05
		DATA	$72,$62,$52,$C0
		ASTOP
_apu_mus26:
		.BYTE	$10
		.WORD	_apu_mus26_A
_apu_mus26_A:
		CMDE2	$04
		CMDE1	$02
		CMDE0	$01
		CMDD5
		LOOP_START	$04
			CMDEB	$93
			DATA	$73,$53,$43,$23,$43,$53
		DO_LOOP
		DATA	$C0
		ASTOP
_apu_mus27:
		.BYTE	$20
		.WORD	_apu_mus27_A
_apu_mus27_A:
		CMDE2	$04
		CMDE1	$02
		CMDE0	$02
		CMDE9	$00
		LOOP_START	$04
			DATA	$B2,$A2,$92
		DO_LOOP
		DATA	$C0
		ASTOP
_apu_mus28:
		.BYTE	$20
		.WORD	_apu_mus28_A
_apu_mus28_A:
		CMDE2	$04
		CMDE1	$02
		CMDE0	$01
		CMDE9	$00
		CMDD9	$00
		LOOP_START	$0B
			DATA	$00
			CMDDA	$01
		DO_LOOP
		CMDD9	$00
		LOOP_START	$0B
			DATA	$B3
			CMDDA	$FF
			CMDEA	$01
		DO_LOOP
		DATA	$C0
		ASTOP
_apu_mus29:
		.BYTE	$10
		.WORD	_apu_mus29_A
_apu_mus29_A:
		CMDE2	$04
		CMDE1	$02
		CMDE0	$01
		CMDEB	$85
		CMDE9	$0A
		CMDD6
		LOOP_START	$03
			DATA	$71,$91,$B1
			CMDEA	$02
		DO_LOOP
		DATA	$C0
		ASTOP
_apu_mus2A:
		.BYTE	$10
		.WORD	_apu_mus2A_A
_apu_mus2A_A:
		CMDE2	$04
		CMDE1	$03
		CMDE0	$01
		CMDEB	$93
		CMDE9	$00
		CMDD3
		LOOP_START	$03
			DATA	$40,$50
		DO_LOOP
		DATA	$C1
		CMDD4
		LOOP_START	$10
			DATA	$41
			CMDD8
			DATA	$91
			CMDD7
			DATA	$01
			CMDDA	$FE
			CMDEA	$01
		DO_LOOP
		DATA	$C0
		ASTOP
_apu_mus2B:
		.BYTE	$30
		.WORD	_apu_mus2B_A
		.WORD	_apu_mus2B_B
_apu_mus2B_A:
		CMDE2	$04
		CMDE1	$03
		CMDE0	$01
		CMDE9	$00
		CMDD1
		DATA	$91,$C0
		CMDD1
		CMDD9	$00
		LOOP_START	$02
			DATA	$01,$01
			CMDDA	$FF
			CMDEA	$08
		DO_LOOP
		DATA	$C0
		ASTOP
_apu_mus2B_B:
		CMDE0	$01
		CMDE9	$00
		DATA	$B1,$C0
		CMDD9	$00
		LOOP_START	$02
			DATA	$A1,$B1
			CMDDA	$01
			CMDEA	$08
		DO_LOOP
		DATA	$C0
		ASTOP
_apu_mus2C:
		.BYTE	$10
		.WORD	_apu_mus2C_A
_apu_mus2C_A:
		CMDE2	$04
		CMDE1	$02
		CMDE0	$02
		CMDD3
		CMDEB	$9D
		CMDE9	$08
		DATA	$71
		CMDE9	$06
		DATA	$90
		CMDE9	$02
		DATA	$B1
		CMDE9	$05
		CMDEB	$95
		CMDD7
		DATA	$01,$C0
		ASTOP
_apu_mus2D:
		.BYTE	$30
		.WORD	_apu_mus2D_A
		.WORD	_apu_mus2D_B
_apu_mus2D_A:
		CMDE2	$04
		CMDE1	$00
		CMDE0	$01
		CMDE9	$03
		CMDEB	$9D
		CMDD2
		DATA	$77
		CMDEB	$95
		DATA	$77,$C0
		ASTOP
_apu_mus2D_B:
		CMDE2	$04
		CMDE1	$00
		CMDE0	$01
		LOOP_START	$03
			CMDD9	$FC
			DATA	$B0
			CMDD9	$00
			DATA	$B0
			CMDEA	$02
		DO_LOOP
		CMDE9	$08
		DATA	$71,$C0
		ASTOP
_apu_mus2E:
		.BYTE	$10
		.WORD	_apu_mus2E_A
_apu_mus2E_A:
		CMDE2	$04
		CMDE1	$03
		CMDE0	$01
		CMDEB	$93
		CMDE9	$00
		CMDD5
		LOOP_START	$03
			DATA	$40
			CMDD8
			DATA	$90
			CMDD7
			DATA	$00
			CMDDA	$04
		DO_LOOP
		CMDDA	$F4
		CMDD5
		LOOP_START	$08
			DATA	$40
			CMDD8
			DATA	$90
			CMDD7
			DATA	$00
			CMDDA	$FE
		DO_LOOP
		LOOP_START	$08
			DATA	$40
			CMDD8
			DATA	$90
			CMDD7
			DATA	$00
			CMDDA	$FE
			CMDEA	$01
		DO_LOOP
		DATA	$C0
		ASTOP
_apu_mus2F:
		.BYTE	$30
		.WORD	_apu_mus2F_A
		.WORD	_apu_mus2F_B
_apu_mus2F_A:
		CMDE2	$04
		CMDE1	$02
		CMDE0	$01
		CMDD1
		DATA	$00,$C0
		CMDD1
		DATA	$00,$C0,$C0
		CMDD2
		DATA	$00,$C0
		CMDD1
		DATA	$00,$C0,$C0,$C0
		CMDDA	$FF
		CMDEA	$01
		DATA	$C0
		ASTOP
_apu_mus2F_B:
		CMDE2	$04
		CMDE1	$02
		CMDE0	$01
		CMDD1
		DATA	$C0,$00
		CMDD1
		DATA	$C0,$00,$00
		CMDD2
		DATA	$C0,$B0
		CMDD1
		DATA	$C0,$90,$B0,$90
		CMDDA	$FF
		CMDEA	$01
		DATA	$C0
		ASTOP
_apu_mus30:
		.BYTE	$30
		.WORD	_apu_mus30_A
		.WORD	_apu_mus30_B
_apu_mus30_A:
		CMDE2	$04
		CMDE1	$00
		CMDE0	$01
		CMDD4
		DATA	$40,$90,$C1
		CMDD7
		DATA	$91,$A1,$C0
		ASTOP
_apu_mus30_B:
		CMDE2	$04
		CMDE1	$02
		CMDE0	$01
		DATA	$B1,$A0,$C0,$71,$C0
		ASTOP
_apu_mus31:
		.BYTE	$10
		.WORD	_apu_mus31_A
_apu_mus31_A:
		CMDE2	$04
		CMDE1	$02
		CMDE0	$01
		CMDD9	$0C
		CMDE9	$00
		LOOP_START	$03
			CMDD4
			DATA	$40,$30
			CMDD8
			DATA	$00
			CMDEA	$06
		DO_LOOP
		DATA	$C0
		ASTOP
_apu_mus32:
		.BYTE	$10
		.WORD	_apu_mus32_A
_apu_mus32_A:
		CMDE2	$04
		CMDE1	$02
		CMDE0	$01
		CMDD4
		CMDD9	$FD
		CMDEB	$8C
		DATA	$41,$B1,$81
		CMDEC	$D9
		DATA	$00
		CMDD7
		DATA	$44,$C0
		ASTOP
_apu_mus33:
		.BYTE	$10
		.WORD	_apu_mus33_A
_apu_mus33_A:
		CMDE2	$04
		CMDE1	$01
		CMDE0	$01
		LOOP_START	$04
			CMDD3
			DATA	$B2,$72
			CMDD7
			DATA	$22,$B2,$72
			CMDDA	$05
			CMDEA	$03
		DO_LOOP
		DATA	$C0
		ASTOP
_apu_mus34:
		.BYTE	$10
		.WORD	_apu_mus34_A
_apu_mus34_A:
		CMDE2	$04
		CMDE1	$01
		CMDE0	$04
		LOOP_START	$02
			CMDD4
			DATA	$70,$40,$70
			CMDD7
			DATA	$00
		DO_LOOP
		DATA	$01,$C0
		ASTOP
_apu_mus35:
		.BYTE	$30
		.WORD	_apu_mus35_A
		.WORD	_apu_mus35_B
_apu_mus35_A:
		CMDE2	$04
		CMDE1	$02
		CMDE0	$01
		CMDDB	$81
		CMDD9	$05
		DATA	$C1
		CMDE9	$04
		CMDD2
		DATA	$00,$30,$60,$90,$60,$40
		CMDE9	$00
		CMDD2
		DATA	$00,$30,$60,$90,$60,$40
		CMDE9	$05
		CMDD2
		DATA	$00,$30,$60,$90,$60,$40,$C0
		ASTOP
_apu_mus35_B:
		CMDE2	$04
		CMDE1	$03
		CMDE0	$01
		CMDE9	$05
		DATA	$52,$C0
		ASTOP
_apu_mus36:
		.BYTE	$10
		.WORD	_apu_mus36_A
_apu_mus36_A:
		CMDE2	$04
		CMDE1	$02
		CMDE0	$01
		CMDE9	$00
		CMDE0	$01
		LOOP_START	$04
			CMDD4
			DATA	$00,$10,$20,$30,$40,$30,$20,$10
			CMDEA	$04
			CMDDA	$FF
		DO_LOOP
		DATA	$C0
		ASTOP
_apu_mus37:
		.BYTE	$10
		.WORD	_apu_mus37_A
_apu_mus37_A:
		CMDE2	$04
		CMDE1	$03
		CMDE0	$01
		LOOP_START	$10
			CMDD9	$00
			CMDD2
			DATA	$B0,$A0
			CMDDA	$02
		DO_LOOP
		DATA	$C0
		ASTOP
_apu_mus38:
		.BYTE	$10
		.WORD	_apu_mus38_A
_apu_mus38_A:
		CMDE2	$04
		CMDE1	$02
		CMDE0	$01
		CMDD5
		CMDEB	$83
		DATA	$B2
		CMDEC	$75
		DATA	$C0
		ASTOP
_apu_mus39:
		.BYTE	$20
		.WORD	_apu_mus39_A
_apu_mus39_A:
		CMDE2	$04
		CMDE1	$02
		CMDE0	$01
		CMDE9	$0A
		LOOP_START	$02
			DATA	$60,$90,$80,$40
			CMDE9	$00
		DO_LOOP
		LOOP_START	$04
			DATA	$40,$60,$20,$00
			CMDEA	$04
		DO_LOOP
		DATA	$C0
		ASTOP
_apu_mus3A:
		.BYTE	$10
		.WORD	_apu_mus3A_A
_apu_mus3A_A:
		CMDE0	$01
		CMDE1	$02
		CMDE2	$01
		CMDE9	$00
		CMDD4
		CMDDB	$03
		LOOP_START	$06
			DATA	$B1,$C0
		DO_LOOP
		DATA	$C0
		ASTOP
_apu_mus3B:
		.BYTE	$30
		.WORD	_apu_mus3B_A
		.WORD	_apu_mus3B_B
_apu_mus3B_A:
		CMDE2	$04
		CMDE1	$02
		CMDE0	$01
		CMDE9	$00
		CMDEB	$BD
		CMDD3
		DATA	$01,$72,$C0
		ASTOP
_apu_mus3B_B:
		CMDE2	$04
		CMDE1	$03
		CMDE0	$01
		CMDE9	$00
		DATA	$C1,$32,$C0
		ASTOP
_apu_mus3C:
		.BYTE	$10
		.WORD	_apu_mus3C_A
_apu_mus3C_A:
		CMDE2	$04
		CMDE1	$02
		CMDE0	$01
		CMDE9	$00
		CMDEB	$85
		CMDD3
		DATA	$52
		CMDEB	$8D
		CMDE9	$03
		CMDD3
		DATA	$52,$C0
		ASTOP
_apu_mus3D:
		.BYTE	$30
		.WORD	_apu_mus3D_A
		.WORD	_apu_mus3D_B
_apu_mus3D_A:
		CMDE2	$04
		CMDE1	$00
		CMDE0	$02
		LOOP_START	$02
			CMDD0
			DATA	$90,$A0
			CMDD7
			DATA	$00
		DO_LOOP
		DATA	$C0
		ASTOP
_apu_mus3D_B:
		CMDE2	$04
		CMDE1	$03
		CMDE0	$04
		CMDD9	$FD
		DATA	$B2,$C0
		ASTOP
_apu_mus3E:
		.BYTE	$30
		.WORD	_apu_mus3E_A
		.WORD	_apu_mus3E_B
_apu_mus3E_A:
		CMDE2	$04
		CMDE1	$00
		CMDE0	$04
		CMDD2
		CMDEB	$9D
		DATA	$97,$C0
		ASTOP
_apu_mus3E_B:
		CMDE2	$04
		CMDE1	$00
		CMDE0	$04
		CMDE9	$05
		DATA	$81,$71,$61,$51,$41,$C0
		ASTOP
_apu_mus3F:
		.BYTE	$20
		.WORD	_apu_mus3F_A
_apu_mus3F_A:
		CMDE2	$04
		CMDE1	$02
		CMDE0	$01
		CMDD9	$FC
		DATA	$C0,$B1
		CMDD9	$00
		DATA	$C0,$93,$C0
		ASTOP
_apu_mus40:
		.BYTE	$20
		.WORD	_apu_mus40_A
_apu_mus40_A:
		CMDE2	$02
		CMDE1	$02
		CMDE0	$01
		DATA	$00,$10,$20,$33,$C0
		ASTOP
_apu_mus41:
		.BYTE	$20
		.WORD	_apu_mus41_A
_apu_mus41_A:
		CMDE2	$04
		CMDE1	$02
		CMDE0	$04
		DATA	$21,$43,$C0
		ASTOP
_apu_mus42:
		.BYTE	$10
		.WORD	_apu_mus42_A
_apu_mus42_A:
		CMDE2	$04
		CMDE1	$02
		CMDE0	$01
		CMDD3
		LOOP_START	$03
			CMDEB	$B3
			DATA	$73,$93
			CMDEA	$04
		DO_LOOP
		DATA	$C0
		ASTOP
_apu_mus43:
		.BYTE	$30
		.WORD	_apu_mus43_A
		.WORD	_apu_mus43_B
_apu_mus43_B:
		CMDE0	$01
		CMDE9	$03
		LOOP_START	$06
			DATA	$80,$90,$A0,$B0,$A0,$90,$80
		DO_LOOP
		DATA	$C0
		ASTOP
_apu_mus43_A:
		CMDE2	$04
		CMDE1	$03
		CMDE0	$01
		CMDD9	$F4
		LOOP_START	$06
			CMDE9	$00
			CMDD3
			DATA	$40,$10
			CMDD8
			DATA	$B0
			CMDD7
			DATA	$00,$20,$30,$10
		DO_LOOP
		DATA	$C0
		ASTOP
_apu_mus44:
		.BYTE	$30
		.WORD	_apu_mus44_A
		.WORD	_apu_mus44_B
_apu_mus44_A:
		CMDE2	$04
		CMDE1	$02
		CMDE0	$02
		CMDEB	$85
		CMDD9	$F8
		CMDD0
		DATA	$92,$C0
		LOOP_START	$03
			DATA	$91,$C0
			CMDEA	$04
		DO_LOOP
		DATA	$C0
		ASTOP
_apu_mus44_B:
		CMDE2	$04
		CMDE1	$03
		CMDE0	$01
		CMDD9	$FE
		DATA	$B2,$C0
		LOOP_START	$04
			DATA	$A6
			CMDEA	$04
		DO_LOOP
		DATA	$C0
		ASTOP
_apu_mus45:
		.BYTE	$20
		.WORD	_apu_mus45_A
_apu_mus45_A:
		CMDE2	$04
		CMDE1	$00
		CMDE0	$01
		DATA	$00,$01,$00,$00
		LOOP_START	$0A
			DATA	$B0,$90,$B0,$90,$B0
			CMDDA	$FF
			CMDEA	$02
		DO_LOOP
		DATA	$C0
		ASTOP
_apu_mus46:
		.BYTE	$30
		.WORD	_apu_mus46_A
		.WORD	_apu_mus46_B
_apu_mus46_A:
		CMDE2	$04
		CMDE1	$02
		CMDE0	$01
		LOOP_START	$04
			CMDD1
			CMDEC	$21
			DATA	$32
			CMDEB	$85
			CMDD7
			DATA	$51,$31,$21,$C4
			CMDEA	$03
		DO_LOOP
		DATA	$C0
		ASTOP
_apu_mus46_B:
		CMDE2	$04
		CMDE1	$02
		CMDE0	$02
		CMDD9	$FE
		LOOP_START	$04
			DATA	$C0,$B6
			CMDEA	$04
		DO_LOOP
		DATA	$C0
		ASTOP
_apu_mus47:
		.BYTE	$10
		.WORD	_apu_mus47_A
_apu_mus47_A:
		CMDE2	$04
		CMDE1	$02
		CMDE0	$02
		CMDD3
		CMDEB	$9D
		CMDE9	$09
		DATA	$74
		CMDE9	$07
		CMDEB	$95
		DATA	$B4,$C0
		ASTOP
_apu_mus4A:
		.BYTE	$10
		.WORD	_apu_mus4A_A
_apu_mus4A_A:
		CMDE2	$04
		CMDE1	$02
		CMDE0	$01
		CMDE9	$00
		CMDD9	$07
		CMDD3
		CMDEB	$8B
		DATA	$71
		CMDE9	$02
		CMDEB	$83
		DATA	$71,$C0
		ASTOP
_apu_mus4B:
		.BYTE	$20
		.WORD	_apu_mus4B_A
_apu_mus4B_A:
		CMDE2	$04
		CMDE1	$02
		CMDE0	$02
		CMDE9	$05
		LOOP_START	$14
			DATA	$50
		DO_LOOP
		DATA	$C0
		ASTOP
_apu_mus4D:
		.BYTE	$20
		.WORD	_apu_mus4D_A
_apu_mus4D_A:
		CMDE2	$04
		CMDE1	$02
		CMDE0	$01
		DATA	$70,$C2,$71,$C0
		ASTOP
_apu_mus4E:
		.BYTE	$30
		.WORD	_apu_mus4E_A
		.WORD	_apu_mus4E_B
_apu_mus4E_A:
		CMDE2	$04
		CMDE1	$02
		CMDE0	$01
		CMDD1
		DATA	$50,$C0
		ASTOP
_apu_mus4E_B:
		CMDE2	$04
		CMDE1	$02
		CMDE0	$01
		CMDD9	$FF
		DATA	$B2,$C0
		CMDE9	$03
		DATA	$93,$C1,$C0
		ASTOP
_apu_mus4F:
		.BYTE	$10
		.WORD	_apu_mus4F_A
_apu_mus4F_A:
		CMDE2	$04
		CMDE1	$02
		CMDE0	$01
		CMDD3
		LOOP_START	$0A
			CMDEB	$B3
			DATA	$73,$53
			CMDDA	$02
		DO_LOOP
		DATA	$C0
		ASTOP
_apu_mus50:
		.BYTE	$30
		.WORD	_apu_mus50_A
		.WORD	_apu_mus50_B
_apu_mus50_A:
		CMDE2	$04
		CMDE1	$02
		CMDE0	$01
		CMDE9	$00
		CMDDA	$0C
		CMDD1
		DATA	$91
		CMDD1
		CMDD9	$08
		LOOP_START	$02
			DATA	$00
			CMDDA	$01
			CMDEA	$05
		DO_LOOP
		DATA	$C0
		ASTOP
_apu_mus50_B:
		CMDE2	$04
		CMDE1	$00
		CMDE0	$01
		DATA	$B0,$C1,$C0
		ASTOP
_apu_mus51:
		.BYTE	$20
		.WORD	_apu_mus51_A
_apu_mus51_A:
		CMDE2	$04
		CMDE1	$03
		CMDE0	$01
		CMDD9	$FE
		DATA	$B2,$C0
		LOOP_START	$04
			DATA	$A6
			CMDEA	$04
		DO_LOOP
		DATA	$C0
		ASTOP
_apu_mus52:
		.BYTE	$10
		.WORD	_apu_mus52_A
_apu_mus52_A:
		CMDE2	$04
		CMDE1	$02
		CMDE0	$01
		CMDEB	$94
		CMDD4
		DATA	$73,$C0
		CMDD5
		CMDDB	$08
		DATA	$27,$C0
		ASTOP
_apu_mus53:
		.BYTE	$10
		.WORD	_apu_mus53_A
_apu_mus53_A:
		CMDE2	$04
		CMDE1	$02
		CMDE0	$01
		CMDD3
		CMDEB	$8B
		DATA	$73
		CMDE0	$01
		LOOP_START	$02
			CMDD3
			CMDD9	$07
			DATA	$01,$21,$01,$21
			CMDEA	$02
		DO_LOOP
		DATA	$C0
		ASTOP
_apu_mus54:
		.BYTE	$10
		.WORD	_apu_mus54_A
_apu_mus54_A:
		CMDE2	$04
		CMDE1	$03
		CMDE0	$01
		CMDE9	$00
		CMDD9	$06
		LOOP_START	$05
			CMDD2
			DATA	$50
			CMDD7
			DATA	$50
			CMDDA	$01
			CMDEA	$01
		DO_LOOP
		DATA	$C0
		ASTOP
_apu_mus55:
		.BYTE	$10
		.WORD	_apu_mus55_A
_apu_mus55_A:
		CMDE2	$04
		CMDE1	$00
		CMDE0	$03
		CMDEB	$BD
		CMDD2
		DATA	$0F,$C0
		ASTOP
_apu_mus56:
		.BYTE	$10
		.WORD	_apu_mus56_A
_apu_mus56_A:
		CMDE2	$04
		CMDE1	$00
		CMDE0	$01
		CMDD9	$05
		CMDD3
		CMDEB	$8B
		DATA	$51,$C0,$C0
		ASTOP
_apu_mus57:
		.BYTE	$10
		.WORD	_apu_mus57_A
_apu_mus57_A:
		CMDE2	$04
		CMDE1	$00
		CMDE0	$01
		CMDD9	$05
		CMDD3
		CMDEB	$8B
		DATA	$91,$C0,$C0
		ASTOP
_apu_mus58:
		.BYTE	$10
		.WORD	_apu_mus58_A
_apu_mus58_A:
		CMDE2	$04
		CMDE1	$00
		CMDE0	$01
		CMDD9	$02
		CMDD4
		CMDEB	$8B
		DATA	$41,$C0,$C0
		ASTOP
_apu_mus59:
		.BYTE	$10
		.WORD	_apu_mus59_A
_apu_mus59_A:
		CMDE2	$04
		CMDE1	$00
		CMDE0	$01
		CMDD9	$05
		CMDD2
		CMDEB	$8B
		DATA	$B1,$C0,$C0
		ASTOP
_apu_mus5A:
		.BYTE	$10
		.WORD	_apu_mus5A_A
_apu_mus5A_A:
		CMDE2	$04
		CMDE1	$00
		CMDE0	$01
		CMDE9	$02
		CMDD9	$05
		CMDD4
		CMDEB	$8B
		DATA	$51,$C0,$C0
		ASTOP
_apu_mus5B:
		.BYTE	$10
		.WORD	_apu_mus5B_A
_apu_mus5B_A:
		CMDE2	$04
		CMDE1	$00
		CMDE0	$01
		CMDD9	$07
		CMDD3
		CMDEB	$8B
		DATA	$01,$C0,$C0
		ASTOP
_apu_mus5C:
		.BYTE	$20
		.WORD	_apu_mus5C_A
_apu_mus5C_A:
		CMDE2	$04
		CMDE1	$00
		CMDE0	$01
		CMDE9	$05
		DATA	$90,$C1,$C0
		ASTOP
_apu_mus5D:
		.BYTE	$20
		.WORD	_apu_mus5D_A
_apu_mus5D_A:
		CMDE2	$04
		CMDE1	$00
		CMDE0	$01
		CMDE9	$03
		DATA	$B0,$C1,$C0
		ASTOP
_apu_mus5E:
		.BYTE	$10
		.WORD	_apu_mus5E_A
_apu_mus5E_A:
		CMDE2	$04
		CMDE1	$02
		CMDE0	$01
		CMDDB	$81
		CMDD9	$08
		CMDE9	$03
		CMDD2
		DATA	$00,$30,$60,$90,$60,$40
		CMDE9	$00
		CMDD2
		DATA	$00,$30,$60,$90,$60,$40
		CMDE9	$05
		CMDD2
		DATA	$00,$30,$60,$90,$60,$40,$C0
		ASTOP
_apu_mus5F:
		.BYTE	$10
		.WORD	_apu_mus5F_A
_apu_mus5F_A:
		CMDE2	$04
		CMDE1	$02
		CMDE0	$02
		CMDD3
		CMDEB	$93
		DATA	$91
		CMDEB	$9B
		DATA	$01,$C0
		ASTOP
_apu_mus60:
		.BYTE	$30
		.WORD	_apu_mus60_A
		.WORD	_apu_mus60_B
_apu_mus60_A:
		CMDE2	$04
		CMDE1	$02
		CMDE0	$01
		CMDE9	$00
		CMDDA	$0C
		CMDD1
		DATA	$91,$C0
		CMDD1
		CMDD9	$00
		LOOP_START	$02
			DATA	$01,$01
			CMDDA	$FF
			CMDEA	$08
		DO_LOOP
		DATA	$C0
		ASTOP
_apu_mus60_B:
		CMDE2	$04
		CMDE0	$01
		CMDE9	$03
		DATA	$01,$C0
		CMDD9	$00
		LOOP_START	$02
			DATA	$11,$01
			CMDDA	$01
			CMDEA	$08
		DO_LOOP
		DATA	$C0
		ASTOP
_apu_mus61:
		.BYTE	$10
		.WORD	_apu_mus61_A
_apu_mus61_A:
		CMDE2	$04
		CMDE1	$00
		CMDE0	$01
		CMDD2
		DATA	$71,$C0,$C0
		ASTOP
_apu_mus62:
		.BYTE	$30
		.WORD	_apu_mus62_A
		.WORD	_apu_mus62_B
_apu_mus62_A:
		CMDE2	$04
		CMDE1	$00
		CMDE0	$01
		CMDD3
		CMDEB	$85
		DATA	$91
		CMDD7
		DATA	$91
		CMDD8
		DATA	$C0
		ASTOP
_apu_mus62_B:
		CMDE2	$04
		CMDE1	$00
		CMDE0	$01
		DATA	$70,$C2,$C0
		ASTOP
_apu_mus63:
		.BYTE	$30
		.WORD	_apu_mus63_A
		.WORD	_apu_mus63_B
_apu_mus63_A:
		CMDE2	$04
		CMDE1	$03
		CMDE0	$01
		CMDE9	$00
		CMDD0
		DATA	$91,$C0
		CMDD1
		CMDD9	$00
		LOOP_START	$02
			DATA	$92
			CMDEA	$08
		DO_LOOP
		DATA	$C0
		ASTOP
_apu_mus63_B:
		CMDE0	$01
		CMDE9	$00
		DATA	$B1,$C0
		CMDD9	$00
		LOOP_START	$04
			DATA	$A1
		DO_LOOP
		LOOP_START	$0F
			DATA	$B0
			CMDEA	$01
		DO_LOOP
		DATA	$C0
		ASTOP
_apu_mus64:
		.BYTE	$30
		.WORD	_apu_mus64_A
		.WORD	_apu_mus64_B
_apu_mus64_A:
		CMDE2	$04
		CMDE1	$01
		CMDE0	$01
		CMDD6
		CMDEB	$8D
		CMDE9	$00
		LOOP_START	$04
			DATA	$81,$C1
			CMDEA	$03
			CMDDA	$FF
		DO_LOOP
		DATA	$C0
		ASTOP
_apu_mus64_B:
		CMDE2	$04
		CMDE1	$02
		CMDE0	$01
		LOOP_START	$04
			CMDEA	$02
			DATA	$70
			CMDEA	$FE
			DATA	$A0,$90,$50
			CMDEA	$04
		DO_LOOP
		DATA	$C0
		ASTOP
_apu_mus65:
		.BYTE	$20
		.WORD	_apu_mus65_A
_apu_mus65_A:
		CMDE2	$04
		CMDE1	$02
		CMDE0	$01
		CMDE0	$02
		CMDE9	$00
		DATA	$51,$C0
		CMDD9	$00
		LOOP_START	$03
			DATA	$81
			CMDEA	$01
		DO_LOOP
		CMDEA	$FD
		LOOP_START	$0F
			DATA	$A0
			CMDEA	$01
		DO_LOOP
		DATA	$C0
		ASTOP
_apu_mus66:
		.BYTE	$30
		.WORD	_apu_mus66_A
		.WORD	_apu_mus66_B
_apu_mus66_A:
		CMDE2	$04
		CMDE1	$00
		CMDE0	$01
		CMDE9	$08
		CMDDB	$81
		CMDD9	$88
		CMDD0
		DATA	$00,$C3
		CMDE9	$00
		CMDD0
		DATA	$01,$C1,$C0
		ASTOP
_apu_mus66_B:
		CMDE2	$04
		CMDE1	$00
		CMDE0	$01
		CMDE9	$00
		CMDDB	$81
		CMDD9	$88
		DATA	$C0,$B3,$C1,$31,$21,$11
		CMDE9	$08
		DATA	$01,$C0
		ASTOP
_apu_mus67:
		.BYTE	$20
		.WORD	_apu_mus67_A
_apu_mus67_A:
		CMDE2	$05
		CMDE0	$02
		CMDE9	$02
		DATA	$71
		CMDD9	$00
		CMDE9	$01
		DATA	$71
		CMDE9	$00
		DATA	$81
		CMDE9	$00
		DATA	$91
		CMDE9	$00
		LOOP_START	$0F
			DATA	$A0
			CMDEA	$01
		DO_LOOP
		DATA	$C0
		ASTOP
_apu_mus68:
		.BYTE	$30
		.WORD	_apu_mus68_A
		.WORD	_apu_mus68_B
_apu_mus68_A:
		CMDE2	$04
		CMDE1	$03
		CMDE0	$01
		CMDE9	$00
		CMDD6
		CMDE1	$00
		DATA	$61,$C1
		CMDE1	$03
		DATA	$11,$C1,$C0
		ASTOP
_apu_mus68_B:
		CMDE2	$04
		CMDE1	$02
		CMDE0	$01
		CMDE9	$03
		DATA	$51,$C1,$73,$C0
		ASTOP
_apu_mus69:
		.BYTE	$10
		.WORD	_apu_mus69_A
_apu_mus69_A:
		CMDE2	$04
		CMDE1	$03
		CMDE0	$01
		CMDE9	$00
		CMDD4
		DATA	$50
		CMDD7
		DATA	$B0,$80,$A0,$C0
		ASTOP
_apu_mus6A:
		.BYTE	$10
		.WORD	_apu_mus6A_A
_apu_mus6A_A:
		CMDE2	$04
		CMDE1	$03
		CMDE0	$01
		CMDE9	$00
		CMDD9	$FF
		CMDD5
		DATA	$70
		CMDD8
		CMDD8
		CMDD8
		DATA	$C0,$C0
		CMDD8
		DATA	$C0
		CMDD7
		DATA	$00,$20
		CMDD7
		DATA	$70,$70,$A0
		CMDD7
		DATA	$50
		CMDD7
		DATA	$B0,$80,$A0,$C0
		ASTOP
_apu_mus6B:
		.BYTE	$20
		.WORD	_apu_mus6B_A
_apu_mus6B_A:
		CMDE2	$04
		CMDE1	$00
		CMDE0	$01
		CMDE9	$00
		DATA	$51,$C0,$41,$C0,$31,$C0
		ASTOP
_apu_mus6C:
		.BYTE	$30
		.WORD	_apu_mus6C_A
		.WORD	_apu_mus6C_B
_apu_mus6C_A:
		CMDE2	$12
		CMDE1	$02
		CMDE0	$01
		LOOP_START	$02
			CMDD1
			DATA	$21,$91
		DO_LOOP
		DATA	$C0
		ASTOP
_apu_mus6C_B:
		CMDE0	$01
		CMDE2	$04
		CMDE9	$00
		LOOP_START	$02
			DATA	$B1
			CMDD9	$FC
			DATA	$B1
		DO_LOOP
		DATA	$C0
		ASTOP
_apu_mus6D:
		.BYTE	$30
		.WORD	_apu_mus6D_A
		.WORD	_apu_mus6D_B
_apu_mus6D_A:
		CMDE2	$04
		CMDE1	$00
		CMDE0	$01
		CMDD2
		DATA	$00,$70,$00
		CMDD6
		DATA	$C3
		LOOP_START	$0F
			DATA	$90
			CMDEA	$02
			CMDDA	$FD
		DO_LOOP
		DATA	$C0
		ASTOP
_apu_mus6D_B:
		CMDE2	$04
		CMDE1	$00
		CMDE0	$01
		DATA	$80,$A0,$B0,$B0,$90,$C1,$01
		CMDEA	$02
		DATA	$11
		CMDEA	$02
		DATA	$21
		CMDEA	$02
		DATA	$31
		CMDEA	$02
		DATA	$41
		CMDEA	$02
		DATA	$51
		CMDEA	$02
		DATA	$61
		CMDEA	$02
		DATA	$71,$C0
		ASTOP
_apu_mus6E:
		.BYTE	$20
		.WORD	_apu_mus6E_A
_apu_mus6E_A:
		CMDE2	$04
		CMDE1	$03
		CMDE0	$01
		CMDE9	$00
		DATA	$32,$C0
		ASTOP
_apu_mus6F:
		.BYTE	$30
		.WORD	_apu_mus6F_A
		.WORD	_apu_mus6F_B
_apu_mus6F_A:
		CMDE2	$04
		CMDE1	$00
		CMDE0	$01
		CMDD3
		LOOP_START	$04
			DATA	$90,$A0,$90,$C0
		DO_LOOP
		DATA	$C0
		ASTOP
_apu_mus6F_B:
		CMDE2	$04
		CMDE1	$00
		CMDE0	$01
		LOOP_START	$04
			DATA	$52,$C0
		DO_LOOP
		DATA	$C0
		ASTOP
_apu_mus70:
		.BYTE	$10
		.WORD	_apu_mus70_A
_apu_mus70_A:
		CMDE2	$04
		CMDE1	$02
		CMDE0	$01
		CMDE9	$00
		CMDE0	$01
		CMDD9	$F8
		LOOP_START	$10
			CMDD5
			DATA	$00,$10,$20,$30,$40,$30,$20,$10
			CMDEA	$01
			CMDDA	$FF
		DO_LOOP
		DATA	$C0
		ASTOP
_apu_mus71:
		.BYTE	$30
		.WORD	_apu_mus71_A
		.WORD	_apu_mus71_B
_apu_mus71_A:
		CMDE2	$04
		CMDE1	$02
		CMDE0	$04
		CMDEB	$B5
		CMDD4
		DATA	$C0,$9B,$C0
		ASTOP
_apu_mus71_B:
		CMDE2	$04
		CMDE1	$02
		CMDE0	$01
		LOOP_START	$04
			DATA	$70,$A0,$90,$50
			CMDEA	$04
		DO_LOOP
		DATA	$C0
		ASTOP
_apu_mus72:
		.BYTE	$10
		.WORD	_apu_mus72_A
_apu_mus72_A:
		CMDE2	$00
		CMDE1	$02
		CMDE0	$01
		CMDE9	$00
		CMDD4
		DATA	$B2,$71,$C0
		ASTOP
_apu_mus73:
		.BYTE	$30
		.WORD	_apu_mus73_A
		.WORD	_apu_mus73_B
_apu_mus73_A:
		CMDE2	$05
		CMDE1	$02
		CMDE0	$01
		CMDE9	$00
		LOOP_START	$02
			CMDE9	$0A
			CMDE0	$02
			DATA	$CF
			CMDE0	$01
			CMDD5
			LOOP_START	$06
				DATA	$70
				CMDDA	$01
				CMDEA	$FF
			DO_LOOP
			CMDDA	$FA
			CMDD6
			LOOP_START	$04
				DATA	$00
				CMDDA	$FF
				CMDEA	$01
			DO_LOOP
			CMDDA	$04
			DATA	$90,$80
			CMDD6
			DATA	$01
			CMDEA	$FF
			DATA	$30
			CMDEA	$FF
			DATA	$40
			CMDEA	$FF
			DATA	$50
			CMDEA	$FF
			DATA	$62
		DO_LOOP
		DATA	$C0
		ASTOP
_apu_mus73_B:
		CMDE2	$05
		CMDE1	$03
		CMDE0	$02
		CMDE9	$0E
		DATA	$A0,$90
		CMDE9	$0C
		DATA	$A0,$90
		CMDE9	$09
		DATA	$90,$70
		CMDE9	$07
		DATA	$80,$60
		CMDE9	$04
		DATA	$70,$50
		CMDE9	$00
		LOOP_START	$14
			DATA	$80,$60,$70,$50
		DO_LOOP
		CMDE9	$02
		DATA	$70,$50
		CMDE9	$04
		DATA	$70,$50
		CMDE9	$06
		DATA	$80,$60
		CMDE9	$08
		DATA	$80,$60
		CMDE9	$0A
		DATA	$90,$70
		CMDE9	$0C
		DATA	$90,$70
		CMDE9	$0E
		DATA	$A0,$90
		CMDE9	$0E
		DATA	$A0,$90,$C0
		ASTOP
_apu_mus74:
		.BYTE	$30
		.WORD	_apu_mus74_A
		.WORD	_apu_mus74_B
_apu_mus74_A:
		CMDE2	$00
		CMDE1	$02
		CMDE0	$01
		CMDE9	$04
		LOOP_START	$0A
			CMDEA	$01
			DATA	$C0
			CMDD2
			DATA	$70
			CMDD2
			DATA	$40
			CMDD9	$FE
		DO_LOOP
		LOOP_START	$0A
			CMDEA	$FF
			DATA	$C0
			CMDD2
			DATA	$70
			CMDD2
			DATA	$40
			CMDD9	$02
		DO_LOOP
		LOOP_START	$19
			DATA	$C0
			CMDD2
			DATA	$70
			CMDD2
			DATA	$40
		DO_LOOP
		DATA	$C0
		ASTOP
_apu_mus74_B:
		CMDE2	$00
		CMDE1	$00
		CMDE0	$01
		CMDE9	$00
		LOOP_START	$0A
			CMDEA	$01
			DATA	$00,$80,$C0
			CMDD9	$FF
		DO_LOOP
		LOOP_START	$0A
			CMDEA	$FF
			DATA	$00,$80,$C0
			CMDD9	$01
		DO_LOOP
		LOOP_START	$19
			DATA	$00,$50,$C0
		DO_LOOP
		DATA	$C0
		ASTOP
_apu_mus00:
		.BYTE	0
_apu_chnl_data_dummy:
		.BYTE	$C0,$C0,$FF
off_99283:
		.WORD	byte_9929D
		.WORD	byte_992A0
		.WORD	byte_992A3
		.WORD	byte_992A6
		.WORD	byte_992A9
		.WORD	byte_992AC
		.WORD	byte_992AF
		.WORD	byte_992B2
		.WORD	byte_992B5
		.WORD	byte_992B5
		.WORD	byte_992B5
		.WORD	byte_992B5
		.WORD	byte_992B5
byte_9929D:
		.BYTE	$8B,$1D,$FF
byte_992A0:
		.BYTE	$8C,$07,$FF
byte_992A3:
		.BYTE	$8D,$17,$FF
byte_992A6:
		.BYTE	$8E,$05,$FF
byte_992A9:
		.BYTE	$8F,$12,$FF
byte_992AC:
		.BYTE	$8F,$1A,$FF
byte_992AF:
		.BYTE	$90,$16,$FF
byte_992B2:
		.BYTE	$91,$13,$FF
byte_992B5:
		.BYTE	$FF
off_992B6:
		.WORD	byte_992E0
		.WORD	byte_99323
		.WORD	byte_9935A
		.WORD	byte_99364
		.WORD	byte_99371
		.WORD	byte_99378
		.WORD	byte_99382
		.WORD	byte_993B6
		.WORD	byte_993EA
		.WORD	byte_993F7
		.WORD	byte_9940D
		.WORD	byte_99435
		.WORD	byte_99451
		.WORD	byte_99464
		.WORD	byte_99480
		.WORD	byte_9949C
		.WORD	byte_994B8
		.WORD	byte_994CE
		.WORD	_apu_mus01
		.WORD	_apu_mus01
		.WORD	_apu_mus01
byte_992E0:
		.BYTE	$FE,$00,$F0
		.BYTE	$01,$00,$08
		.BYTE	$02,$00,$00
		.BYTE	$04,$00,$E8
		.BYTE	$03,$00,$18
		.BYTE	$04,$00,$E8
		.BYTE	$03,$00,$18
		.BYTE	$04,$00,$E8
		.BYTE	$03,$00,$18
		.BYTE	$04,$00,$E8
		.BYTE	$03,$00,$18
		.BYTE	$04,$00,$F0
		.BYTE	$03,$00,$10
		.BYTE	$04,$00,$F0
		.BYTE	$03,$00,$10
		.BYTE	$04,$00,$F0
		.BYTE	$03,$00,$10
		.BYTE	$04,$00,$F8
		.BYTE	$03,$00,$08
		.BYTE	$04,$00,$F8
		.BYTE	$03,$00,$08
		.BYTE	$64,$C0,$FE
		.BYTE	$FF
byte_99323:
		.BYTE	$FE,$00,$F0
		.BYTE	$01,$00,$08
		.BYTE	$02,$00,$00
		.BYTE	$04,$00,$00
		.BYTE	$05,$DC,$EE
		.BYTE	$05,$B6,$0D
		.BYTE	$05,$6E,$F3
		.BYTE	$05,$49,$0A
		.BYTE	$05,$DC,$F6
		.BYTE	$05,$DB,$06
		.BYTE	$05,$25,$F9
		.BYTE	$05,$6D,$03
		.BYTE	$05,$93,$FC
		.BYTE	$05,$49,$02
		.BYTE	$05,$B7,$FD
		.BYTE	$05,$49,$02
		.BYTE	$05,$B7,$FD
		.BYTE	$64,$C0,$FE
		.BYTE	$FF
byte_9935A:
		.BYTE	$FE,$00,$F8
		.BYTE	$08,$00,$00
		.BYTE	$FE,$00,$00
		.BYTE	$FF
byte_99364:
		.BYTE	$FE,$00,$00
		.BYTE	$01,$00,$00
		.BYTE	$FE,$00,$F8
		.BYTE	$64,$00,$00
		.BYTE	$FF
byte_99371:
		.BYTE	$FE,$00,$F8
		.BYTE	$C8,$00,$00
		.BYTE	$FF
byte_99378:
		.BYTE	$FE,$00,$F8
		.BYTE	$06,$00,$00
		.BYTE	$FE,$00,$00
		.BYTE	$FF
byte_99382:
		.BYTE	$FE,$00,$F8
		.BYTE	$04,$00,$00
		.BYTE	$07,$DC,$EE
		.BYTE	$07,$B6,$0D
		.BYTE	$07,$6E,$F3
		.BYTE	$07,$49,$0A
		.BYTE	$07,$DC,$F6
		.BYTE	$07,$DB,$06
		.BYTE	$07,$25,$F9
		.BYTE	$07,$6D,$03
		.BYTE	$07,$93,$FC
		.BYTE	$07,$49,$02
		.BYTE	$07,$B7,$FD
		.BYTE	$07,$49,$02
		.BYTE	$07,$B7,$FD
		.BYTE	$20,$C0,$FE
		.BYTE	$FE,$00,$00
		.BYTE	$FF
byte_993B6:
		.BYTE	$FE,$00,$98
		.BYTE	$04,$00,$00
		.BYTE	$07,$DC,$EE
		.BYTE	$07,$B6,$0D
		.BYTE	$07,$6E,$F3
		.BYTE	$07,$49,$0A
		.BYTE	$07,$DC,$F6
		.BYTE	$07,$DB,$06
		.BYTE	$07,$25,$F9
		.BYTE	$07,$6D,$03
		.BYTE	$07,$93,$FC
		.BYTE	$07,$49,$02
		.BYTE	$07,$B7,$FD
		.BYTE	$07,$49,$02
		.BYTE	$07,$B7,$FD
		.BYTE	$20,$C0,$FE
		.BYTE	$FE,$00,$00
		.BYTE	$FF
byte_993EA:
		.BYTE	$FE,$00,$38
		.BYTE	$04,$00,$10
		.BYTE	$29,$13,$FD
		.BYTE	$FE,$00,$00
		.BYTE	$FF
byte_993F7:
		.BYTE	$FE,$00,$C0
		.BYTE	$04,$00,$F0
		.BYTE	$02,$00,$E4
		.BYTE	$01,$00,$C8
		.BYTE	$06,$00,$00
		.BYTE	$04,$00,$FC
		.BYTE	$FE,$00,$00
		.BYTE	$FF
byte_9940D:
		.BYTE	$FE,$00,$C0
		.BYTE	$02,$00,$F8
		.BYTE	$02,$00,$C0
		.BYTE	$02,$00,$00
		.BYTE	$01,$00,$50
		.BYTE	$03,$00,$E8
		.BYTE	$01,$00,$F0
		.BYTE	$02,$00,$00
		.BYTE	$01,$00,$28
		.BYTE	$0A,$34,$FB
		.BYTE	$14,$34,$FF
		.BYTE	$50,$CD,$FF
		.BYTE	$FE,$00,$00
		.BYTE	$FF
byte_99435:
		.BYTE	$FE,$00,$F8
		.BYTE	$01,$00,$00
		.BYTE	$01,$00,$E0
		.BYTE	$01,$00,$A8
		.BYTE	$01,$00,$C8
		.BYTE	$01,$00,$E0
		.BYTE	$01,$00,$E8
		.BYTE	$01,$00,$F0
		.BYTE	$FE,$00,$00
		.BYTE	$FF
byte_99451:
		.BYTE	$FE,$00,$C8
		.BYTE	$14,$00,$FC
		.BYTE	$0A,$00,$00
		.BYTE	$09,$8F,$FB
		.BYTE	$3C,$AB,$FE
		.BYTE	$FE,$00,$00
		.BYTE	$FF
byte_99464:
		.BYTE	$FE,$00,$E8
		.BYTE	$01,$00,$00
		.BYTE	$01,$00,$E8
		.BYTE	$01,$00,$A8
		.BYTE	$01,$00,$C8
		.BYTE	$01,$00,$E0
		.BYTE	$01,$00,$F0
		.BYTE	$18,$56,$FF
		.BYTE	$FE,$00,$00
		.BYTE	$FF
byte_99480:
		.BYTE	$FE,$00,$F8
		.BYTE	$01,$00,$00
		.BYTE	$01,$00,$E8
		.BYTE	$01,$00,$A8
		.BYTE	$01,$00,$C8
		.BYTE	$01,$00,$E0
		.BYTE	$01,$00,$E8
		.BYTE	$01,$00,$E8
		.BYTE	$FE,$00,$00
		.BYTE	$FF
byte_9949C:
		.BYTE	$FE,$00,$F8
		.BYTE	$01,$00,$00
		.BYTE	$01,$00,$E8
		.BYTE	$01,$00,$A8
		.BYTE	$01,$00,$C8
		.BYTE	$01,$00,$E0
		.BYTE	$01,$00,$E8
		.BYTE	$01,$00,$E8
		.BYTE	$FE,$00,$00
		.BYTE	$FF
byte_994B8:
		.BYTE	$FE,$00,$C0
		.BYTE	$04,$00,$F0
		.BYTE	$02,$00,$E4
		.BYTE	$01,$00,$C8
		.BYTE	$2A,$00,$00
		.BYTE	$28,$9A,$FF
		.BYTE	$FE,$00,$00
		.BYTE	$FF
byte_994CE:
		.BYTE	$FE,$00,$78
		.BYTE	$0A,$9A,$F9
		.BYTE	$0A,$00,$00
		.BYTE	$09,$56,$FD
		.BYTE	$3C,$78,$FF
		.BYTE	$FE,$00,$00
		.BYTE	$FF
_apu_mus01:
		.BYTE	$0F
		.WORD	_apu_mus01_A
		.WORD	_apu_mus01_B
		.WORD	_apu_mus01_C
		.WORD	_apu_mus01_D
_apu_mus01_A:
		CMDE2	$00
		CMDE1	$01
		CMDE0	$05
		CMDE9	$03
		CMDD9	$F4
byte_994F4:
		DATA	$C1
		CMDD5
		DATA	$30,$C0,$32,$C0,$30,$C0,$33,$C1,$22,$C0
		LOOP_START	$0E
			DATA	$20,$C0
		DO_LOOP
		AJSR	byte_995DE
		DATA	$C3
		CMDD4
		DATA	$71,$C1,$A1
		CMDD5
		DATA	$21,$C1,$03
		CMDD4
		DATA	$A2,$C0,$93,$C1,$63
		AJSR	byte_995DE
		DATA	$C3
		CMDD4
		DATA	$71,$C1,$A1
		CMDD5
		DATA	$21,$C1,$23,$01,$C1,$03
		CMDD4
		DATA	$A1
		CMDD5
		DATA	$01,$C1,$32,$C0,$20,$C0,$20,$C2
		CMDD4
		DATA	$A3
		CMDD5
		DATA	$33,$22,$C0,$23,$C3
		CMDD4
		DATA	$A1
		CMDD5
		DATA	$01,$21,$C1,$23,$01,$C1,$21,$C1
		LOOP_START	$04
			DATA	$50,$C0
		DO_LOOP
		DATA	$51,$C1,$47,$C1,$41,$C1,$01,$23,$41,$50,$C0,$50,$C0,$50,$C0,$52
		DATA	$C0,$43,$71,$51,$41,$C1,$05,$C1
		LOOP_START	$04
			DATA	$50,$C0
		DO_LOOP
		DATA	$52,$C0,$74,$C0,$53,$31,$23,$35,$03,$21,$C1,$31,$C1,$71,$51,$C1
		DATA	$51,$C1,$33,$51,$C1
		LOOP_START	$04
			DATA	$80,$C0
		DO_LOOP
		DATA	$82,$C0,$77,$C1,$73,$31,$53,$71,$80,$C0,$80,$C0,$80,$C0,$82,$C0
		DATA	$73,$A1,$81,$71,$C1,$35,$C1
		LOOP_START	$04
			DATA	$80,$C0
		DO_LOOP
		DATA	$82,$C0,$A5,$83,$61,$51,$C1,$65,$33,$51,$C1,$61,$C1,$A1,$81,$C1
		DATA	$83,$63,$81,$C1
		LOOP_START	$04
			DATA	$B0,$C0
		DO_LOOP
		DATA	$B2,$C0,$A7,$C1,$A3,$61,$81,$C1,$A1,$B0,$C0,$B0,$C0,$B0,$C0,$B2
		DATA	$C0,$A3
		CMDD6
		DATA	$11
		CMDD5
		DATA	$B1,$A1,$C1,$65,$C1
		LOOP_START	$04
			DATA	$B0,$C0
		DO_LOOP
		DATA	$B2,$C0
		CMDD6
		DATA	$14,$CC
		AJMP	byte_994F4
		DATA	$C0
		ASTOP
byte_995DE:
		LOOP_START	$02
			CMDD4
			DATA	$71,$C3
			CMDD5
			DATA	$27,$C1
		DO_LOOP
		ARET
_apu_mus01_B:
		CMDE2	$01
		CMDE1	$01
		CMDE0	$05
		CMDD9	$F4
byte_995F0:
		CMDE9	$05
		DATA	$C1
		CMDD5
		DATA	$00,$C0,$02,$C0,$00,$C0,$03,$C1
		CMDD3
		DATA	$A2,$C0
		LOOP_START	$0E
			DATA	$A0,$C0
		DO_LOOP
		CMDE9	$09
		AJSR	byte_996D1
		CMDD4
		LOOP_START	$08
			DATA	$00,$C0
		DO_LOOP
		AJSR	byte_996D1
		CMDD3
		LOOP_START	$08
			DATA	$90,$C0
		DO_LOOP
		CMDE9	$05
		DATA	$72,$C0,$50,$C0,$50,$C0,$C1,$53,$73,$53,$53,$C3,$51,$91,$91,$C1
		DATA	$93,$91,$C1,$91,$C1
		LOOP_START	$04
			DATA	$90,$C0
		DO_LOOP
		DATA	$91,$C1
		CMDD4
		DATA	$01
		CMDE8
		AJSR	byte_996DE
		CMDD3
		DATA	$57,$C1
		CMDD4
		DATA	$01,$C1,$01
		CMDE8
		AJSR	byte_996DE
		CMDD3
		DATA	$53,$C3
		CMDD4
		DATA	$01,$01,$C5
		CMDD3
		DATA	$51,$81
		CMDD4
		DATA	$01,$C1
		CMDD3
		DATA	$51,$81
		CMDD4
		DATA	$01,$C1
		CMDD3
		DATA	$81
		CMDD4
		DATA	$01,$31,$C1
		CMDD3
		DATA	$81
		CMDD4
		DATA	$01,$31,$C1
		CMDD3
		DATA	$A1
		CMDD4
		DATA	$21,$51,$C1
		CMDD3
		DATA	$A3
		CMDD4
		DATA	$21,$C1
		LOOP_START	$04
			DATA	$00,$C0
		DO_LOOP
		DATA	$02,$C0,$37,$C1
		CMDD3
		DATA	$A5,$8A,$A0
		CMDD4
		DATA	$00,$20,$30,$50,$77,$C1
		CMDD3
		DATA	$A5,$85,$C3
		CMDD4
		DATA	$31,$31,$C5
		CMDD3
		DATA	$81,$B1
		CMDD4
		DATA	$31,$C1
		CMDD3
		DATA	$81,$B1
		CMDD4
		DATA	$31,$C1
		CMDD3
		DATA	$B1
		CMDD4
		DATA	$31,$61,$C1
		CMDD3
		DATA	$B1
		CMDD4
		DATA	$31,$61,$C1,$11,$51,$81,$C1,$13,$51,$C1
		LOOP_START	$04
			DATA	$30,$C0
		DO_LOOP
		DATA	$31,$C1,$61
		CMDE8
		AJSR	byte_996E6
		CMDD3
		DATA	$B7,$C1
		CMDD4
		DATA	$61,$C1,$61
		CMDE8
		AJSR	byte_996E6
		CMDD3
		DATA	$B3,$C3
		CMDD4
		DATA	$61,$61,$C1,$A4,$CC
		AJMP	byte_995F0
		DATA	$C0
		ASTOP
byte_996D1:
		CMDD4
		LOOP_START	$10
			DATA	$20,$C0
		DO_LOOP
		CMDD4
		LOOP_START	$08
			DATA	$30,$C0
		DO_LOOP
		ARET
byte_996DE:
		CMDD4
		DATA	$05,$C1
		CMDD3
		DATA	$75,$51
		CMDE8
		ARET
byte_996E6:
		CMDD4
		DATA	$65,$C1,$15
		CMDD3
		DATA	$B1
		CMDE8
		ARET
_apu_mus01_C:
		CMDE2	$03
		CMDE1	$00
		CMDE0	$05
		CMDE9	$00
byte_996F6:
		DATA	$C1
		CMDD3
		DATA	$90,$C0,$92,$C0,$90,$C0,$93,$C1
		LOOP_START	$03
			AJSR	byte_997FC
		DO_LOOP
		AJSR	byte_99807
		CMDD3
		DATA	$01,$C3
		CMDD2
		DATA	$75,$C1,$71,$51,$C3,$53
		CMDD3
		DATA	$91
		CMDD4
		DATA	$31,$61
		AJSR	byte_997FC
		AJSR	byte_99807
		CMDD3
		DATA	$01,$C3,$75,$C1,$31,$53,$C1
		CMDE2	$02
		DATA	$51,$51,$51,$51,$51
		CMDD2
		LOOP_START	$10
			DATA	$A1
		DO_LOOP
		CMDD3
		DATA	$51,$51,$C1,$51,$51,$51,$51
		CMDE2	$03
		DATA	$56,$C0
		CMDD2
		DATA	$71,$91,$B5
		LOOP_START	$03
			CMDD3
			DATA	$01
			CMDD4
			DATA	$00,$C0
			CMDD3
			DATA	$01
			CMDD4
			DATA	$00,$C0
			CMDD3
			DATA	$01
			CMDD4
			DATA	$00,$C0
			CMDD3
			DATA	$01
			CMDD4
			DATA	$00,$C0
		DO_LOOP
		CMDD3
		DATA	$01
		CMDD4
		DATA	$00,$C0
		CMDD3
		DATA	$01
		CMDD4
		DATA	$00,$C0
		CMDD3
		DATA	$00,$C0,$01,$21,$31
		CMDE2	$02
		DATA	$51,$51,$C1,$51,$51
		CMDE2	$03
		DATA	$51,$71
		CMDE2	$02
		DATA	$81
		LOOP_START	$08
			DATA	$81
		DO_LOOP
		LOOP_START	$08
			DATA	$A1
		DO_LOOP
		CMDE2	$03
		DATA	$A1,$C1
		CMDD2
		DATA	$A3
		CMDD3
		DATA	$01,$25
		LOOP_START	$03
			CMDD3
			DATA	$31
			CMDD4
			DATA	$30,$C0
			CMDD3
			DATA	$31
			CMDD4
			DATA	$30,$C0
			CMDD3
			DATA	$31
			CMDD4
			DATA	$30,$C0
			CMDD3
			DATA	$31
			CMDD4
			DATA	$30,$C0
		DO_LOOP
		CMDD3
		DATA	$31
		CMDD4
		DATA	$30,$C0
		CMDD3
		DATA	$31
		CMDD4
		DATA	$30,$C0
		CMDD3
		DATA	$30,$C0,$31,$51,$61
		CMDE2	$02
		DATA	$81,$81,$C1,$81,$81
		CMDE2	$03
		DATA	$81,$A1
		CMDE2	$02
		DATA	$B1
		LOOP_START	$08
			DATA	$B1
		DO_LOOP
		CMDD4
		LOOP_START	$08
			DATA	$11
		DO_LOOP
		CMDE2	$03
		DATA	$11,$C1
		CMDD3
		DATA	$13,$31,$55
		LOOP_START	$03
			CMDD3
			DATA	$61
			CMDD4
			DATA	$60,$C0
			CMDD3
			DATA	$61
			CMDD4
			DATA	$60,$C0
			CMDD3
			DATA	$61
			CMDD4
			DATA	$60,$C0
			CMDD3
			DATA	$61
			CMDD4
			DATA	$60,$C0
		DO_LOOP
		CMDD3
		DATA	$61
		CMDD4
		DATA	$60,$C0
		CMDD3
		DATA	$61
		CMDD4
		DATA	$60,$C0
		CMDD3
		DATA	$60,$C0,$61,$81,$A1,$62,$CC
		AJMP	byte_996F6
		DATA	$C0
		ASTOP
byte_997FC:
		CMDD2
		DATA	$71,$C3
		CMDD3
		DATA	$23
		CMDD4
		DATA	$21
		CMDD3
		DATA	$91,$A1
		ARET
byte_99807:
		CMDD2
		DATA	$A1,$C3
		CMDD3
		DATA	$23
		CMDD4
		DATA	$21
		CMDD3
		DATA	$91,$A1
		ARET
_apu_mus01_D:
		CMDE0	$05
		CMDE9	$00
byte_99816:
		.BYTE	$01,$21,$23,$21,$23,$21
		LOOP_START	$02
			DATA	$03,$23,$01,$01,$23
		DO_LOOP
		LOOP_START	$04
			DATA	$03,$33,$03,$33
		DO_LOOP
		LOOP_START	$03
			DATA	$03,$33,$C1,$21,$33
		DO_LOOP
		DATA	$03,$33,$C1,$20,$20,$23
		AJSR	byte_9985A
		AJSR	byte_9986C
		AJSR	byte_99863
		AJSR	byte_9986C
		AJSR	byte_99863
		AJSR	byte_9986C
		AJSR	byte_9985A
		DATA	$03,$23,$21,$21,$01,$21,$CF
		AJMP	byte_99816
		DATA	$C0
		ASTOP
byte_9985A:
		LOOP_START	$03
			DATA	$03,$23,$01,$01,$23
		DO_LOOP
		ARET
byte_99863:
		LOOP_START	$07
			DATA	$03,$23,$01,$01,$23
		DO_LOOP
		ARET
byte_9986C:
		DATA	$C7,$21,$20,$20,$23
		ARET
_apu_mus02:
		.BYTE	$0F
		.WORD	_apu_mus02_A
		.WORD	_apu_mus02_B
		.WORD	_apu_mus02_C
		.WORD	_apu_mus02_D
_apu_mus02_A:
		CMDE2	$00
		CMDE1	$01
		CMDE0	$06
		CMDE9	$04
		CMDD9	$EE
byte_99885:
		CMDE1	$01
		LOOP_START	$02
			AJSR	byte_99929
			CMDD5
			DATA	$40,$60,$70,$90,$C1,$90,$C0,$70,$C0,$60,$C0,$40,$C0,$20,$C0
			AJSR	byte_99929
			CMDD5
			DATA	$40,$60,$70,$90,$C1,$90,$C0,$70,$60,$40,$C0,$20,$C2
		DO_LOOP
		CMDE1	$02
		AJSR	byte_9993C
		CMDD4
		DATA	$B0,$A0,$B0,$C0
		CMDD5
		DATA	$20,$C0
		CMDD4
		DATA	$B0,$C0,$90,$C0
		CMDD5
		DATA	$90,$70,$60,$40,$20,$C0
		AJSR	byte_9993C
		DATA	$40,$30,$40,$60,$40,$60,$C0,$90,$C3,$73
		CMDE1	$01
		AJSR	byte_9994D
		CMDD5
		DATA	$11
		CMDD4
		DATA	$91
		CMDD5
		DATA	$11
		CMDD4
		DATA	$91
		CMDD5
		DATA	$10,$20,$C0,$40,$C1,$10,$C0
		AJSR	byte_9994D
		DATA	$11
		CMDD4
		DATA	$91
		CMDD5
		DATA	$11
		CMDD4
		DATA	$91
		CMDD5
		DATA	$11
		CMDD4
		DATA	$B1,$91,$71
		AJSR	byte_99957
		CMDE1	$03
		CMDD4
		DATA	$60,$70,$90,$C0,$70,$90,$B0,$C0
		CMDE1	$00
		CMDD5
		DATA	$10,$C0,$20,$C0,$42,$C0
		AJSR	byte_99957
		CMDE1	$03
		CMDD5
		DATA	$60,$40,$20,$10
		CMDD4
		DATA	$B0,$90,$70,$60,$40,$60,$40,$60,$43
		AJMP	byte_99885
		DATA	$C0
		ASTOP
byte_99929:
		CMDD5
		DATA	$60,$40,$60,$C0,$20,$C0
		CMDD4
		DATA	$90,$C0,$71,$90,$B0
		CMDD5
		DATA	$10,$C0,$20,$C0
		ARET
byte_9993C:
		CMDD4
		DATA	$B0,$A0,$B0,$C0
		CMDD5
		DATA	$20,$C0
		CMDD4
		DATA	$B0,$C0,$91
		CMDD5
		DATA	$61,$41,$21
		ARET
byte_9994D:
		CMDD5
		DATA	$63,$21
		CMDD4
		DATA	$93,$B3
		CMDD5
		DATA	$11
		CMDE8
		ARET
byte_99957:
		CMDE1	$03
		CMDD4
		DATA	$60,$70,$90,$C0,$70,$90,$B0,$C0
		CMDE1	$00
		CMDD5
		DATA	$10,$C0
		CMDD4
		DATA	$B0,$C0,$92,$C0
		ARET
_apu_mus02_B:
		CMDE2	$01
		CMDE1	$01
		CMDE0	$06
		CMDD9	$FA
byte_99975:
		CMDE9	$09
		LOOP_START	$02
			AJSR	byte_999FC
			DATA	$C1
			CMDD3
			DATA	$91,$B1
			CMDD4
			DATA	$11,$21,$41,$61,$41
			AJSR	byte_999FC
			DATA	$C1
			CMDD3
			DATA	$91,$B1
			CMDD4
			DATA	$11,$20,$10,$20,$40,$20,$C2
		DO_LOOP
		CMDE1	$02
		CMDE9	$08
		AJSR	byte_99A08
		CMDD4
		DATA	$47,$27
		AJSR	byte_99A08
		CMDE1	$01
		CMDDA	$F4
		DATA	$40,$30,$40,$60,$40,$60,$C0,$90,$C3,$73
		CMDDA	$0C
		CMDE2	$02
		LOOP_START	$02
			CMDD4
			DATA	$21,$41,$61,$21,$41,$61,$41,$61
			CMDD4
			DATA	$71,$61,$71,$61,$91,$71,$61,$41
		DO_LOOP
		CMDE2	$01
		AJSR	byte_99A0D
		CMDE1	$03
		CMDD4
		DATA	$20,$40,$60,$C0,$40,$60,$70,$C0
		CMDE1	$00
		DATA	$90,$C0,$B0,$C0
		CMDD5
		DATA	$12,$C0
		AJSR	byte_99A0D
		CMDE1	$01
		CMDD5
		DATA	$20,$10
		CMDD4
		DATA	$B0,$90,$70,$60,$40,$20,$10,$20,$10,$20,$13
		AJMP	byte_99975
		DATA	$C0
		ASTOP
byte_999FC:
		DATA	$C1
		CMDD4
		DATA	$61,$21
		CMDD3
		DATA	$91,$C1,$71,$B1
		CMDD4
		DATA	$41
		ARET
byte_99A08:
		CMDD4
		DATA	$77,$63,$23
		ARET
byte_99A0D:
		CMDE1	$03
		CMDD4
		DATA	$20,$40,$60,$C0,$40,$60,$70,$C0
		CMDE1	$00
		DATA	$90,$C0,$70,$C0,$62,$C0
		ARET
_apu_mus02_C:
		CMDE2	$03
		CMDE1	$03
		CMDE0	$06
		CMDE9	$00
		CMDD9	$FA
byte_99A2B:
		LOOP_START	$02
			AJSR	byte_99A86
			CMDD3
			LOOP_START	$03
				DATA	$91,$C1
			DO_LOOP
			DATA	$91,$B0
			CMDD4
			DATA	$10
			AJSR	byte_99A86
			CMDD3
			LOOP_START	$03
				DATA	$91,$C1
			DO_LOOP
			CMDD4
			DATA	$21,$C1
		DO_LOOP
		LOOP_START	$03
			CMDD3
			DATA	$71,$C1,$71,$C1,$67
		DO_LOOP
		CMDD3
		DATA	$41,$C1,$42,$90,$C3,$93
		LOOP_START	$02
			CMDD3
			LOOP_START	$04
				DATA	$20,$C0
			DO_LOOP
			LOOP_START	$03
				DATA	$70,$C0
			DO_LOOP
			DATA	$93
			LOOP_START	$04
				DATA	$90,$C0
			DO_LOOP
			CMDD2
			DATA	$90,$C0,$B0,$C0
			CMDD3
			DATA	$10,$C0
		DO_LOOP
		LOOP_START	$04
			CMDD3
			DATA	$21,$C1,$71,$C1,$90,$C0,$90,$C0,$92,$C0
		DO_LOOP
		AJMP	byte_99A2B
		DATA	$C0
		ASTOP
byte_99A86:
		CMDD4
		DATA	$21,$C1,$01,$C1
		CMDD3
		DATA	$B7
		ARET
_apu_mus02_D:
		CMDE0	$06
byte_99A90:
		CMDE9	$08
		LOOP_START	$20
			DATA	$31,$30,$30
		DO_LOOP
		LOOP_START	$03
			DATA	$10
			LOOP_START	$0F
				DATA	$30
			DO_LOOP
		DO_LOOP
		DATA	$10,$30,$30,$30
		LOOP_START	$04
			DATA	$30
		DO_LOOP
		DATA	$10,$30,$30,$30
		CMDE9	$00
		DATA	$23
		LOOP_START	$08
			DATA	$01,$31,$21,$31
		DO_LOOP
		LOOP_START	$03
			DATA	$33,$33,$21,$21,$23
		DO_LOOP
		DATA	$33,$33,$20,$20,$20,$20,$21,$21
		AJMP	byte_99A90
		DATA	$C0
		ASTOP
_apu_mus03:
		.BYTE	$0F
		.WORD	_apu_mus03_A
		.WORD	_apu_mus03_B
		.WORD	_apu_mus03_C
		.WORD	_apu_mus03_D
_apu_mus03_A:
		CMDE2	$00
		CMDE1	$03
		CMDE0	$06
		CMDE9	$03
		CMDD9	$F4
byte_99ADE:
		AJSR	byte_99B96
		DATA	$C1
		CMDD5
		DATA	$20,$C0,$22,$00,$C0,$00,$C0,$00,$50,$C0,$40,$C0
		AJSR	byte_99B96
		AJSR	byte_99BA6
		CMDD5
		DATA	$20,$C0,$20,$C0,$01,$00,$20,$C0
		CMDD4
		DATA	$70,$C0,$70,$B0,$C0
		CMDD5
		DATA	$00,$C0
		AJSR	byte_99BB7
		CMDD4
		DATA	$B1,$C0,$B1,$C0
		CMDD5
		DATA	$01
		CMDD4
		DATA	$B0,$70,$C0,$72,$91,$C1
		CMDD5
		DATA	$20,$C0,$40,$20,$C0,$51,$50,$40,$C0,$22,$C0,$21,$C0,$22,$41,$20
		CMDD4
		DATA	$70,$C0,$72,$90,$B0
		AJSR	byte_99BB7
		DATA	$B0,$C0,$B0,$C0,$B1
		CMDD5
		DATA	$00
		CMDD4
		DATA	$B0,$C0,$70,$C0,$70
		CMDD5
		DATA	$50,$C0,$40,$C0,$C1,$20,$C0,$40,$20,$C0,$70
		CMDE8
		DATA	$73
		CMDE8
		CMDE0	$03
		DATA	$70,$50,$40,$20,$00
		CMDD4
		DATA	$B0,$90,$70
		CMDE0	$06
		AJSR	byte_99BC6
		CMDD5
		DATA	$20,$C0,$20,$C0,$20
		CMDD4
		DATA	$B0,$C0
		CMDD5
		DATA	$20,$C0,$20,$C0
		CMDD4
		DATA	$B0,$90,$C0,$B0,$C0,$C0
		CMDD5
		DATA	$20,$40,$20,$50,$40,$C0,$51,$50,$40,$C0,$23
		AJSR	byte_99BC6
		DATA	$50,$C0,$50,$C0,$40,$21,$70,$90,$C0,$90,$70,$C3
		AJSR	byte_99BA6
		AJMP	byte_99ADE
		DATA	$C0
		ASTOP
byte_99B96:
		DATA	$C1
		CMDD5
		DATA	$20,$C0,$22,$00,$C0,$00,$C0,$00,$20,$C0
		CMDD4
		DATA	$B0,$C0
		ARET
byte_99BA6:
		DATA	$C0
		CMDD5
		DATA	$B0,$70,$20,$90,$50,$00,$70,$C0,$71,$20,$50,$40,$20,$C0
		ARET
byte_99BB7:
		CMDD4
		DATA	$70,$C0,$70,$C0,$70,$C0,$70,$C0,$50,$70,$C0,$73,$C0
		ARET
byte_99BC6:
		CMDD5
		DATA	$40,$C0,$40,$C0,$40,$00,$C0,$40,$C0,$40,$C0,$00
		CMDD4
		DATA	$A0,$C0
		CMDD5
		DATA	$00,$C0,$C0
		CMDD4
		DATA	$70,$90,$70
		CMDD5
		DATA	$00,$20,$00
		CMDD4
		DATA	$70
		CMDD5
		DATA	$30,$40,$C0,$21,$00,$40,$00
		ARET
_apu_mus03_B:
		CMDE2	$00
		CMDE1	$03
		CMDE0	$06
		CMDE9	$05
		CMDD9	$F4
byte_99BF7:
		LOOP_START	$02
			AJSR	byte_99C29
			AJSR	byte_99C38
		DO_LOOP
		LOOP_START	$08
			AJSR	byte_99C48
		DO_LOOP
		AJSR	byte_99C52
		LOOP_START	$02
			AJSR	byte_99C48
		DO_LOOP
		AJSR	byte_99C52
		CMDD5
		DATA	$20,$C0,$20,$C0,$00
		CMDD4
		DATA	$B1
		CMDD5
		DATA	$40,$50,$C0,$50,$40,$C3
		AJSR	byte_99C38
		AJMP	byte_99BF7
		DATA	$C0
		ASTOP
byte_99C29:
		DATA	$C1
		CMDD4
		DATA	$B0,$C0,$B2,$90,$C0,$90,$C0,$90,$B0,$C0,$70,$C0
		ARET
byte_99C38:
		DATA	$C1
		CMDD4
		DATA	$B0,$C0,$B2,$90,$C0,$90,$C0,$90
		CMDD5
		DATA	$00,$C0,$00,$C0
		ARET
byte_99C48:
		DATA	$C1
		CMDD4
		DATA	$20,$C0,$23,$02
		CMDD3
		DATA	$B0,$C3
		ARET
byte_99C52:
		LOOP_START	$02
			DATA	$C1
			CMDD4
			DATA	$40,$C0,$43,$22,$00,$C3
		DO_LOOP
		ARET
_apu_mus03_C:
		CMDE2	$04
		CMDE1	$03
		CMDE0	$06
		CMDE9	$00
byte_99C66:
		LOOP_START	$0C
			AJSR	byte_99C9E
		DO_LOOP
		AJSR	byte_99CB5
		AJSR	byte_99C9E
		CMDD3
		DATA	$70,$C0,$70,$C0,$90,$C0,$90,$C0,$B0,$C0,$B0,$C0,$70,$C0,$70,$C0
		AJSR	byte_99CB5
		DATA	$70,$C0,$70,$C0,$70,$C0,$70,$C0,$70,$C0,$70,$C0,$70,$C0,$70,$C0
		AJSR	byte_99C9E
		AJMP	byte_99C66
		DATA	$C0
		ASTOP
byte_99C9E:
		CMDD2
		DATA	$73
		CMDD3
		DATA	$71,$C0,$50,$C0,$50,$C0,$50,$70,$C0,$70
		CMDE0	$01
		DATA	$21,$01
		CMDD2
		DATA	$B0,$90
		CMDE0	$06
		ARET
byte_99CB5:
		CMDD3
		DATA	$03
		CMDD4
		DATA	$01,$C0
		CMDD3
		DATA	$A0,$C0,$A0,$C0,$A0
		CMDD4
		DATA	$00,$C0,$00
		CMDD3
		CMDE0	$01
		DATA	$71,$51,$40,$20
		CMDE0	$06
		CMDD3
		DATA	$00,$C0,$00,$C0,$20,$C0,$20,$C0,$40,$C0,$40,$C0,$00,$C0,$00,$C0
		ARET
_apu_mus03_D:
		CMDE9	$02
		CMDE0	$06
byte_99CE3:
		LOOP_START	$03
			AJSR	byte_99D03
		DO_LOOP
		AJSR	byte_99D0F
		LOOP_START	$07
			AJSR	byte_99D03
		DO_LOOP
		AJSR	byte_99D0F
		LOOP_START	$07
			AJSR	byte_99D03
		DO_LOOP
		AJSR	byte_99D0F
		AJMP	byte_99CE3
		DATA	$C0
		ASTOP
byte_99D03:
		DATA	$01,$21,$20,$01,$00,$20,$30,$20,$30,$21,$21
		ARET
byte_99D0F:
		DATA	$01,$21,$20,$01,$00,$20,$30,$20,$30,$20,$20,$20,$20
		ARET
_apu_mus04:
		.BYTE	$0F
		.WORD	_apu_mus04_A
		.WORD	_apu_mus04_B
		.WORD	_apu_mus04_C
		.WORD	_apu_mus04_D
_apu_mus04_A:
		CMDE2	$00
		CMDE1	$03
		CMDE0	$05
		CMDE9	$00
		CMDD9	$E8
byte_99D30:
		AJSR	byte_99D71
		CMDD4
		DATA	$9B,$C3
		AJSR	byte_99D71
		DATA	$91,$C5,$A7
		LOOP_START	$02
			LOOP_START	$02
				CMDD4
				DATA	$B3
				CMDD5
				DATA	$21,$69
			DO_LOOP
			CMDD5
			DATA	$65,$7B
			CMDD4
			DATA	$41,$71,$B3
			CMDD5
			DATA	$45
		DO_LOOP
		LOOP_START	$02
			CMDD5
			DATA	$61,$11
			CMDD4
			DATA	$A1
			CMDD5
			DATA	$61,$11
			CMDD4
			DATA	$A1
			CMDD5
			DATA	$71,$11
		DO_LOOP
		CMDD5
		DATA	$A1,$61,$11,$A1,$61,$11,$B1,$61,$AB
		CMDD4
		DATA	$A3
		AJMP	byte_99D30
		DATA	$C0
		ASTOP
byte_99D71:
		CMDD5
		DATA	$31,$41,$31,$41,$01
		CMDD4
		DATA	$91,$C1
		CMDD5
		DATA	$33,$41,$31,$41,$01
		CMDD4
		DATA	$91,$C3
		CMDD5
		DATA	$31,$41,$31,$41,$21,$01
		CMDD4
		DATA	$91
		CMDD5
		DATA	$2D,$C3
		CMDD5
		DATA	$11,$21,$11,$21
		CMDD4
		DATA	$B1,$81,$C1
		CMDD5
		DATA	$13,$21,$11,$21
		CMDD4
		DATA	$B1,$81,$C5
		CMDD4
		DATA	$41,$31,$41,$81,$43,$91
		CMDE8
		ARET
_apu_mus04_B:
		CMDE2	$00
		CMDE1	$03
		CMDE0	$05
		CMDE9	$08
		CMDD9	$E8
		DATA	$C1
		AJMP	byte_99D30
		DATA	$C0
		ASTOP
_apu_mus04_C:
		CMDE2	$03
		CMDE1	$03
		CMDE0	$05
		CMDE9	$00
byte_99DC2:
		LOOP_START	$03
		AJSR	byte_99E1A
		DO_LOOP
		AJSR	byte_99E23
		LOOP_START	$03
		AJSR	byte_99E2B
		DO_LOOP
		LOOP_START	$04
		AJSR	byte_99E1A
		DO_LOOP
		AJSR	byte_99E23
		LOOP_START	$02
		AJSR	byte_99E2B
		DO_LOOP
		CMDD3
		DATA	$41,$C3,$43,$41,$31,$41
		CMDD2
		DATA	$91,$C5,$A7
		LOOP_START	$02
		LOOP_START	$02
		CMDD2
		DATA	$B1,$C3
		CMDD3
		DATA	$23,$61,$51,$61
		DO_LOOP
		LOOP_START	$02
		CMDD3
		DATA	$41,$C3,$73,$B1,$A1,$B1
		DO_LOOP
		DO_LOOP
		LOOP_START	$03
		CMDD3
		DATA	$61,$C3,$61,$C3,$73
		DO_LOOP
		CMDD3
		DATA	$63,$C1
		CMDD2
		DATA	$61,$C1,$61,$71,$81
		AJMP	byte_99DC2
		DATA	$C0
		ASTOP
byte_99E1A:
		CMDD2
		DATA	$91,$C3
		CMDD3
		DATA	$03,$41,$31,$41
		ARET
byte_99E23:
		CMDD3
		DATA	$21,$C3,$53,$91,$81,$91
		ARET
byte_99E2B:
		CMDD3
		DATA	$41,$C3,$83,$B1,$A1,$B1
		ARET
_apu_mus04_D:
		CMDE0	$05
		CMDE9	$03
byte_99E37:
		LOOP_START	$06
		LOOP_START	$03
		DATA	$01,$31,$21,$31,$01,$31,$21,$31
		DO_LOOP
		DATA	$01,$31,$21,$31,$01,$21,$21,$21
		DO_LOOP
		LOOP_START	$03
		LOOP_START	$02
		DATA	$21,$31,$31
		DO_LOOP
		DATA	$21,$31
		DO_LOOP
		DATA	$33,$33,$21,$21,$21,$21
		AJMP	byte_99E37
		DATA	$C0
		ASTOP
_apu_mus05:
		.BYTE	$0F
		.WORD	_apu_mus05_A
		.WORD	_apu_mus05_B
		.WORD	_apu_mus05_C
		.WORD	_apu_mus05_D
_apu_mus05_A:
		CMDE2	$00
		CMDE1	$03
		CMDE0	$04
		CMDE9	$02
		CMDD9	$ED
byte_99E76:
		AJSR	byte_99EE6
		CMDD4
		DATA	$91,$C1,$91,$C1,$91,$51,$C1,$91,$C1,$91,$C1,$51,$91,$C1
		CMDD5
		DATA	$01,$C1
		AJSR	byte_99EE6
		CMDD5
		DATA	$01,$C1,$01,$C1,$01
		CMDD4
		DATA	$91,$C1
		CMDD5
		DATA	$01,$C1,$01,$C1
		CMDD4
		DATA	$91
		CMDD5
		DATA	$51,$41,$21,$C1
		AJSR	byte_99EFA
		CMDD4
		DATA	$B1,$C1,$B1,$71,$C7
		AJSR	byte_99EFA
		CMDD4
		DATA	$B1,$C1,$B1,$71,$C1,$91,$B3
		AJSR	byte_99F2D
		CMDD5
		DATA	$21,$01,$21,$33,$C1,$33,$75,$55,$33
		AJSR	byte_99F2D
		LOOP_START	$02
		DATA	$C1
		CMDD4
		DATA	$71
		CMDD5
		DATA	$71
		CMDD4
		DATA	$71
		CMDD5
		DATA	$51,$21,$C1
		CMDD4
		DATA	$73,$71
		CMDD5
		DATA	$71
		CMDD4
		DATA	$71
		CMDD5
		DATA	$51,$21,$C1,$71
		DO_LOOP
		AJMP	byte_99E76
_unused_0:
		DATA	$C0
		ASTOP
byte_99EE6:
		DATA	$C1
		CMDD4
		DATA	$A1,$B1
		CMDD5
		DATA	$01,$21,$C1,$01
		CMDD4
		DATA	$B1,$C1
		CMDD4
		DATA	$71,$C1,$71,$91,$C1,$B3
		ARET
byte_99EFA:
		CMDD4
		DATA	$71,$C1,$71,$C1,$21,$C1,$21,$C1
		CMDD4
		DATA	$70,$C0,$72,$C0,$23,$C9
		CMDD4
		DATA	$51,$C1,$51,$C1,$51,$C1
		CMDD4
		DATA	$41,$51,$C1,$73,$C5
		CMDD4
		DATA	$71,$C1,$71,$C1,$21,$C1,$21,$C1
		CMDD4
		DATA	$70,$C0,$72,$C0,$23,$C9
		CMDD4
		DATA	$97
		CMDD5
		DATA	$01,$C1
		ARET
byte_99F2D:
		DATA	$C3
		CMDD5
		DATA	$01,$C1,$01,$C1,$31,$C1
		CMDD5
		DATA	$21,$C1,$21
		CMDD4
		DATA	$A9
		ARET
_apu_mus05_B:
		CMDE2	$00
		CMDE1	$03
		CMDE0	$04
		CMDE9	$09
		CMDD9	$ED
		CMDDB	$FF
		DATA	$C2
		AJMP	byte_99E76
_apu_mus05_C:
		CMDE2	$04
		CMDE1	$00
		CMDE0	$04
		CMDE9	$00
		CMDD9	$05
byte_99F56:
		LOOP_START	$02
		AJSR	byte_99FEC
		DO_LOOP
		LOOP_START	$02
		AJSR	byte_99FF9
		DO_LOOP
		LOOP_START	$02
		AJSR	byte_99FEC
		DO_LOOP
		AJSR	byte_99FF9
		CMDD2
		DATA	$51,$C1
		AJSR	byte_9A01F
		CMDD3
		DATA	$51
		CMDD2
		DATA	$51
		CMDD3
		DATA	$21,$61
		CMDD2
		DATA	$61
		LOOP_START	$02
		AJSR	byte_99FEC
		DO_LOOP
		AJSR	byte_99FF9
		LOOP_START	$03
		AJSR	byte_99FEC
		DO_LOOP
		AJSR	byte_99FF9
		LOOP_START	$03
		AJSR	byte_99FEC
		DO_LOOP
		AJSR	byte_99FF9
		LOOP_START	$03
		AJSR	byte_99FEC
		DO_LOOP
		AJSR	byte_99FF9
		AJSR	byte_99FEC
		AJSR	byte_9A006
		CMDD3
		DATA	$00,$C0,$01
		AJSR	byte_9A01F
		CMDD3
		DATA	$01
		CMDD3
		DATA	$71
		CMDD4
		DATA	$03
		CMDD3
		DATA	$03,$71
		CMDD4
		DATA	$01
		CMDD3
		DATA	$01
		CMDD2
		DATA	$A1
		CMDD3
		DATA	$A3,$A1
		AJSR	byte_9A006
		LOOP_START	$02
		CMDD3
		DATA	$00,$C0,$01
		AJSR	byte_9A01F
		CMDD3
		DATA	$01
		CMDD2
		DATA	$A0,$C0,$A1
		AJSR	byte_9A01F
		CMDD2
		DATA	$A1
		CMDD2
		DATA	$80,$C0,$81
		AJSR	byte_9A01F
		CMDD2
		DATA	$81
		CMDD2
		DATA	$A0,$C0,$A1
		AJSR	byte_9A01F
		CMDD2
		DATA	$A1
		DO_LOOP
		AJMP	byte_99F56
		DATA	$C0
		ASTOP
byte_99FEC:
		CMDD2
		DATA	$72,$C0
		AJSR	byte_9A01F
		CMDD3
		DATA	$21,$C1,$71,$61,$71
		ARET
byte_99FF9:
		CMDD2
		DATA	$52,$C0
		AJSR	byte_9A01F
		CMDD3
		DATA	$01,$C1,$51,$41,$51
		ARET
byte_9A006:
		CMDD2
		DATA	$82,$C0
		AJSR	byte_9A01F
		CMDD3
		DATA	$31,$C1,$81,$71,$81
		CMDD2
		DATA	$A2,$C0
		AJSR	byte_9A01F
		CMDD3
		DATA	$51,$C1,$A1,$91,$A1
		ARET
byte_9A01F:
		CMDE0	$01
		CMDD4
		LOOP_START	$08
		DATA	$00
		CMDDA	$FF
		DO_LOOP
		CMDDA	$08
		CMDE0	$04
		ARET
_apu_mus05_D:
		CMDE0	$04
		CMDE9	$03
		LOOP_START	$06
		AJSR	byte_9A06B
		CMDE9	$03
		DATA	$01
		CMDE9	$06
		DATA	$31
		CMDE9	$03
		DATA	$21
		CMDE9	$06
		DATA	$31
		CMDE9	$03
		DATA	$01,$21,$21,$21
		DO_LOOP
		AJSR	byte_9A06B
		CMDE9	$06
		DATA	$11
		CMDE9	$03
		DATA	$21,$21
		CMDE9	$06
		DATA	$11
		CMDE9	$03
		DATA	$21,$21
		CMDE9	$06
		DATA	$11
		CMDE9	$03
		DATA	$21
		AJSR	byte_9A06B
		AJSR	byte_9A06B
		AJMP	_apu_mus05_D
		DATA	$C0
		ASTOP
byte_9A06B:
		LOOP_START	$03
		DATA	$01
		CMDE9	$06
		DATA	$31
		CMDE9	$03
		DATA	$21
		CMDE9	$06
		DATA	$31
		CMDE9	$03
		DATA	$01
		CMDE9	$06
		DATA	$31
		CMDE9	$03
		DATA	$21,$21
		DO_LOOP
		ARET
_apu_mus06:
		.BYTE	$0F
		.WORD	_apu_mus06_A
		.WORD	_apu_mus06_B
		.WORD	_apu_mus06_C
		.WORD	_apu_mus06_D
_apu_mus06_A:
		CMDE2	$00
		CMDE1	$03
		CMDE0	$06
		CMDE9	$03
		CMDD9	$F4
		DATA	$CF,$CF
byte_9A098:
		LOOP_START	$02
		AJSR	byte_9A0FC
		LOOP_START	$02
		CMDD4
		DATA	$50,$70,$50,$70,$50,$C0,$71
		DO_LOOP
		AJSR	byte_9A0FC
		LOOP_START	$02
		CMDD4
		DATA	$50,$70,$50,$70,$50,$C0
		CMDD5
		DATA	$01
		DO_LOOP
		DO_LOOP
		AJSR	byte_9A10D
		DATA	$C1
		CMDD4
		DATA	$71,$80,$C0,$90,$C0,$40,$50,$C0,$73,$C0
		AJSR	byte_9A10D
		CMDD5
		DATA	$70,$C0,$71,$50,$C0,$51,$40,$20,$30,$43,$C0
		AJSR	byte_9A11E
		DATA	$C1
		CMDD4
		DATA	$A0
		CMDD5
		DATA	$00
		CMDD4
		DATA	$A0
		CMDD5
		DATA	$00,$C1,$00,$20,$C0,$42,$01
		AJSR	byte_9A11E
		DATA	$C1
		CMDD4
		DATA	$70,$90,$A0,$B0,$C1
		CMDD5
		DATA	$02
		CMDD4
		DATA	$00,$C3
		AJMP	byte_9A098
		DATA	$C0
		ASTOP
byte_9A0FC:
		CMDD4
		DATA	$20,$40,$20,$40,$20,$C0,$70,$C0,$B1,$90,$C0,$70,$C0,$60,$C0
		ARET
byte_9A10D:
		CMDD5
		DATA	$41,$20,$C0,$00,$C0
		CMDD4
		DATA	$90,$C0
		CMDD5
		DATA	$31,$20,$00,$C0
		CMDD4
		DATA	$92
		ARET
byte_9A11E:
		CMDD5
		DATA	$50,$C0,$50,$C0,$30,$00,$C0,$50,$C0,$50,$C0,$50,$30,$00,$C0,$50
		ARET
_apu_mus06_B:
		CMDE2	$00
		CMDE1	$03
		CMDE0	$06
		CMDE9	$07
		CMDD9	$F4
		LOOP_START	$02
		LOOP_START	$04
		CMDD3
		DATA	$B0,$C0
		DO_LOOP
		LOOP_START	$04
		CMDD4
		DATA	$00,$C0
		DO_LOOP
		DO_LOOP
byte_9A149:
		LOOP_START	$04
		LOOP_START	$08
		CMDD3
		DATA	$B0,$C0
		DO_LOOP
		LOOP_START	$08
		CMDD3
		DATA	$90,$C0
		DO_LOOP
		DO_LOOP
		AJSR	byte_9A1A8
		CMDD4
		DATA	$40,$C0,$40,$C0,$20,$C0,$20,$C0,$00,$C0,$00,$C0
		CMDD3
		DATA	$70,$C0,$70,$C0
		AJSR	byte_9A1A8
		DATA	$70,$C0,$70,$C0
		CMDD4
		DATA	$70,$C0,$70,$C0
		CMDD3
		DATA	$70,$C0,$70,$C0
		CMDD4
		DATA	$70,$C0,$70,$C0
		AJSR	byte_9A1B5
		CMDD4
		DATA	$30,$C0,$30,$C0,$30,$C0,$30,$C0,$70,$C0,$70,$C0,$70,$C0,$70,$C0
		AJSR	byte_9A1B5
		CMDD5
		DATA	$02
		CMDD4
		DATA	$00,$C1,$00,$C0,$03,$C3
		AJMP	byte_9A149
		DATA	$C0
		ASTOP
byte_9A1A8:
		LOOP_START	$04
		CMDD3
		DATA	$90,$C0
		DO_LOOP
		LOOP_START	$04
		CMDD4
		DATA	$00,$C0
		DO_LOOP
		ARET
byte_9A1B5:
		CMDD4
		DATA	$00,$C0,$00,$C0,$00,$C0,$00,$C0,$00,$C0,$00,$C0,$00,$C0,$00,$C0
		ARET
_apu_mus06_C:
		CMDE2	$04
		CMDE1	$03
		CMDE0	$06
		CMDE9	$00
		LOOP_START	$02
		CMDD3
		DATA	$71
		CMDD5
		DATA	$B0,$C0
		CMDD3
		DATA	$21
		CMDD5
		DATA	$70,$C0
		CMDD3
		DATA	$91
		CMDD5
		DATA	$90,$C0
		CMDD3
		DATA	$21
		CMDD5
		DATA	$20,$C0
		DO_LOOP
byte_9A1E6:
		AJSR	byte_9A280
		AJSR	byte_9A295
		AJSR	byte_9A280
		LOOP_START	$02
		CMDD3
		DATA	$51
		CMDD5
		DATA	$90,$C0
		CMDD3
		DATA	$01
		CMDD5
		DATA	$50,$C0
		DO_LOOP
		AJSR	byte_9A280
		AJSR	byte_9A295
		AJSR	byte_9A280
		CMDD3
		DATA	$51
		CMDD5
		DATA	$90,$C0
		CMDD3
		DATA	$01
		CMDD5
		DATA	$50,$C0
		CMDD3
		DATA	$51
		CMDD5
		DATA	$90,$C0
		CMDD3
		DATA	$01
		CMDD5
		DATA	$50
		CMDD3
		DATA	$40
		AJSR	byte_9A2A3
		CMDD3
		DATA	$71
		CMDD5
		DATA	$70,$C0
		CMDD3
		DATA	$51
		CMDD5
		DATA	$50,$C0
		CMDD3
		DATA	$41
		CMDD5
		DATA	$40,$C0
		CMDD3
		DATA	$01
		CMDD5
		DATA	$00,$C0
		AJSR	byte_9A2A3
		LOOP_START	$02
		CMDD3
		DATA	$71
		CMDD5
		DATA	$70,$C0
		DO_LOOP
		CMDD3
		DATA	$70
		CMDD5
		DATA	$70
		CMDD3
		DATA	$70
		CMDD5
		DATA	$70
		CMDD3
		DATA	$50
		CMDD5
		DATA	$50
		CMDD3
		DATA	$40
		CMDD5
		DATA	$40
		AJSR	byte_9A2B4
		CMDD3
		DATA	$81
		CMDD5
		DATA	$80
		CMDD3
		DATA	$80
		CMDD4
		DATA	$00
		CMDD5
		DATA	$80
		CMDD4
		DATA	$30
		CMDD3
		DATA	$A0
		CMDD4
		DATA	$01
		CMDD5
		DATA	$40
		CMDD4
		DATA	$00,$00
		CMDD5
		DATA	$40
		CMDD4
		DATA	$01
		AJSR	byte_9A2B4
		DATA	$00
		CMDD3
		DATA	$B0
		CMDD4
		DATA	$00
		CMDD3
		DATA	$B0
		CMDD4
		DATA	$01
		CMDD3
		DATA	$00,$C0,$01,$41,$51,$61
		AJMP	byte_9A1E6
		DATA	$C0
		ASTOP
byte_9A280:
		CMDD3
		DATA	$71
		CMDD5
		DATA	$B0,$C0
		CMDD3
		DATA	$21
		CMDD5
		DATA	$70,$C0
		CMDD3
		DATA	$71
		CMDD5
		DATA	$B0,$C0
		CMDD3
		DATA	$21
		CMDD5
		DATA	$20,$C0
		ARET
byte_9A295:
		LOOP_START	$02
		CMDD3
		DATA	$51
		CMDD5
		DATA	$90,$C0
		CMDD3
		DATA	$01
		CMDD5
		DATA	$50,$C0
		DO_LOOP
		ARET
byte_9A2A3:
		LOOP_START	$02
		CMDD3
		DATA	$51
		CMDD5
		DATA	$50,$C0
		DO_LOOP
		LOOP_START	$02
		CMDD3
		DATA	$61
		CMDD5
		DATA	$60,$C0
		DO_LOOP
		ARET
byte_9A2B4:
		CMDD3
		DATA	$51
		CMDD5
		DATA	$50
		CMDD3
		DATA	$50,$80
		CMDD5
		DATA	$50
		CMDD4
		DATA	$00
		CMDD3
		DATA	$00,$51
		CMDD5
		DATA	$50
		CMDD3
		DATA	$50,$80
		CMDD5
		DATA	$50
		CMDD4
		DATA	$01
		ARET
_apu_mus06_D:
		CMDE9	$08
		CMDE0	$06
		CMDD2
		DATA	$11,$30,$30
		AJMP	_apu_mus06_D
		DATA	$C0
		ASTOP
_apu_mus07:
		.BYTE	$0F
		.WORD	_apu_mus07_A
		.WORD	_apu_mus07_B
		.WORD	_apu_mus07_C
		.WORD	_apu_mus07_D
_apu_mus07_A:
		CMDE2	$00
		CMDE1	$03
		CMDE0	$06
		CMDE9	$02
		CMDD9	$F2
byte_9A2EC:
		LOOP_START	$02
		CMDD4
		LOOP_START	$06
		DATA	$41,$30
		DO_LOOP
		DATA	$41,$50,$C1,$40
		DO_LOOP
		DATA	$C2
		CMDD4
		DATA	$91,$C0,$81,$90,$C1
		CMDD5
		DATA	$00
		CMDE8
		AJSR	byte_9A399
		CMDE1	$02
		DATA	$C1
		CMDD5
		DATA	$40
		CMDE8
		LOOP_START	$03
		CMDD5
		DATA	$41
		CMDD4
		DATA	$80
		DO_LOOP
		CMDD5
		DATA	$31,$40,$C1
		CMDD4
		DATA	$B2,$80,$C2
		CMDE1	$03
		DATA	$42,$91,$C0,$81,$90,$C1
		CMDD5
		DATA	$00
		CMDE8
		AJSR	byte_9A399
		CMDE1	$02
		CMDD5
		DATA	$C1,$50
		CMDE8
		LOOP_START	$03
		CMDD5
		DATA	$51
		CMDD4
		DATA	$80
		DO_LOOP
		CMDD5
		DATA	$31,$40,$C1,$92,$C3
		AJSR	byte_9A3A5
		CMDE1	$03
		CMDD5
		DATA	$01
		CMDD4
		DATA	$B0
		CMDD5
		DATA	$01
		CMDD4
		DATA	$B0
		CMDD5
		DATA	$01
		CMDD4
		DATA	$90,$C1
		CMDD5
		DATA	$12
		CMDD4
		DATA	$B0
		CMDD5
		DATA	$11
		CMDD4
		DATA	$B0
		CMDD5
		DATA	$11
		CMDD4
		DATA	$A0,$C1
		CMDD5
		DATA	$30
		CMDE8
		LOOP_START	$04
		DATA	$31,$40
		DO_LOOP
		DATA	$31,$C0,$41
		CMDD4
		DATA	$B3,$C2
		CMDE1	$02
		LOOP_START	$02
		CMDD3
		DATA	$91,$B0
		CMDD4
		DATA	$01
		CMDD3
		DATA	$90
		CMDD4
		DATA	$31,$42,$00
		CMDD4
		DATA	$92,$41,$92,$40,$81,$90
		DO_LOOP
		CMDE1	$03
		CMDD5
		DATA	$01
		CMDD4
		DATA	$90,$B1
		CMDD5
		DATA	$02
		CMDD4
		DATA	$90,$B1
		CMDD5
		DATA	$00,$31,$40,$31,$40,$C1,$43
		AJMP	byte_9A2EC
		DATA	$C0
		ASTOP
byte_9A399:
		CMDD5
		DATA	$00,$C0,$00
		CMDD4
		DATA	$B1,$C0,$A1,$C0,$B1,$C0
		ARET
byte_9A3A5:
		CMDE1	$00
		LOOP_START	$02
		CMDD5
		DATA	$91,$40,$81,$40,$C1,$70,$42
		CMDD5
		DATA	$62,$21,$43,$C2
		DO_LOOP
		ARET
_apu_mus07_B:
		CMDE2	$00
		CMDE1	$03
		CMDE0	$06
		CMDE9	$06
		CMDD9	$F2
byte_9A3C2:
		LOOP_START	$02
		CMDD4
		LOOP_START	$06
		DATA	$01,$C0
		DO_LOOP
		DATA	$01,$C2,$00
		DO_LOOP
		AJSR	byte_9A44E
		CMDE1	$02
		DATA	$C1
		CMDD4
		DATA	$80
		CMDE8
		LOOP_START	$03
		DATA	$81,$40
		DO_LOOP
		DATA	$81,$80,$C1,$82,$40,$C2
		CMDE1	$03
		AJSR	byte_9A44E
		CMDE1	$02
		DATA	$C1,$80
		CMDE8
		LOOP_START	$03
		DATA	$81,$50
		DO_LOOP
		DATA	$81,$80,$C1
		CMDD5
		DATA	$42,$C3
		CMDE1	$00
		CMDDB	$05
		CMDDA	$F4
		AJSR	byte_9A3A5
		CMDDA	$0C
		CMDDB	$00
		CMDE1	$03
		CMDD4
		DATA	$21,$C2,$26,$31,$C2,$36,$C1,$40
		CMDD3
		DATA	$B1,$80,$41,$80,$B1
		CMDD4
		DATA	$40,$C1,$93,$81,$C0,$91,$C0
		CMDE1	$03
		CMDEA	$02
		LOOP_START	$02
		DATA	$C1
		LOOP_START	$02
		CMDD6
		DATA	$00
		CMDD5
		DATA	$B1,$90
		CMDD6
		DATA	$01
		CMDD5
		DATA	$B0,$91
		DO_LOOP
		CMDD6
		DATA	$00
		CMDD5
		DATA	$B1,$90
		DO_LOOP
		CMDEA	$FE
		CMDE1	$00
		CMDD4
		DATA	$41,$40,$41,$42,$40,$41,$40,$91,$90,$91,$90,$C1,$83
		AJMP	byte_9A3C2
		DATA	$C0
		ASTOP
byte_9A44E:
		DATA	$C2
		CMDD4
		DATA	$41,$C0,$41,$40,$C1,$41,$C0,$40,$41,$C0,$41,$C0,$41,$C0
		ARET
_apu_mus07_C:
		CMDE2	$03
		CMDE1	$03
		CMDE0	$06
		CMDE9	$00
		CMDD9	$FE
byte_9A469:
		LOOP_START	$06
		AJSR	byte_9A4D0
		DO_LOOP
		CMDD3
		DATA	$45,$41,$C0,$41,$C0
		AJSR	byte_9A4D6
		LOOP_START	$02
		AJSR	byte_9A4D0
		DO_LOOP
		CMDD3
		DATA	$25,$21,$C0,$21,$C0
		AJSR	byte_9A4D6
		AJSR	byte_9A4D0
		AJSR	byte_9A4DF
		AJSR	byte_9A4D0
		AJSR	byte_9A4DF
		CMDD3
		DATA	$22,$42,$52,$22,$32,$52,$72,$32,$42
		CMDD4
		DATA	$42
		CMDD3
		DATA	$42
		CMDD4
		DATA	$42
		CMDD3
		DATA	$41,$C0
		CMDD4
		DATA	$41
		CMDD3
		DATA	$42,$60,$82
		LOOP_START	$02
		CMDD3
		DATA	$92,$92,$72,$72
		CMDD3
		DATA	$62,$62,$52,$52
		DO_LOOP
		CMDD3
		DATA	$22
		CMDD4
		DATA	$22
		CMDD3
		DATA	$22
		CMDD4
		DATA	$22
		CMDD3
		DATA	$42
		CMDD4
		DATA	$42
		CMDD3
		DATA	$42
		CMDD4
		DATA	$41
		CMDD3
		DATA	$40
		AJMP	byte_9A469
		DATA	$C0
		ASTOP
byte_9A4D0:
		CMDD3
		DATA	$92,$82,$72,$62
		ARET
byte_9A4D6:
		CMDD3
		DATA	$41,$C2,$42
		CMDD4
		DATA	$40
		CMDD3
		DATA	$42
		ARET
byte_9A4DF:
		CMDD3
		DATA	$21,$C2,$42,$40
		CMDD4
		DATA	$40,$C1
		ARET
_apu_mus07_D:
		CMDE0	$06
		CMDE9	$06
byte_9A4EC:
		.BYTE	$12,$31,$30,$12,$31,$30
		AJMP	byte_9A4EC
		DATA	$C0
		ASTOP
_apu_mus08:
		.BYTE	$0F
		.WORD	_apu_mus08_A
		.WORD	_apu_mus08_B
		.WORD	_apu_mus08_C
		.WORD	_apu_mus08_D
_apu_mus08_A:
		CMDE2	$00
		CMDE1	$00
		CMDE0	$03
		CMDE9	$00
		CMDD9	$F4
byte_9A50A:
		AJSR	byte_9A594
		CMDD5
		DATA	$21,$51,$C1,$51,$51,$01,$C1,$01,$31,$21,$01
		CMDD4
		DATA	$A1
		CMDD5
		DATA	$01,$21
		CMDD4
		DATA	$91,$C1
		AJSR	byte_9A594
		CMDD5
		DATA	$51,$01,$31,$01,$31,$21,$01
		CMDD4
		DATA	$A1,$91,$51,$71,$91,$51,$C5
		LOOP_START	$02
		CMDD3
		DATA	$93
		CMDD4
		DATA	$01,$C1,$07,$23,$01,$C1,$07
		CMDD4
		DATA	$23,$51,$C1,$51,$C1,$51,$C1,$73,$51,$C1,$57
		CMDD4
		DATA	$91,$C1,$91,$C1,$93,$71,$C1,$93,$71,$C1,$7B,$01,$C1,$21,$C1,$41
		DATA	$C1,$57
		CMDD5
		DATA	$53,$C3
		DO_LOOP
		AJSR	byte_9A5A5
		CMDD5
		DATA	$51,$01,$31,$21,$01
		CMDD4
		DATA	$A1,$91,$A1
		CMDD5
		DATA	$01
		CMDD4
		DATA	$91,$A1,$71,$91,$A1,$91,$C1
		AJSR	byte_9A5A5
		CMDD5
		DATA	$51,$01,$31,$21,$01
		CMDD4
		DATA	$A1,$91,$A1
		CMDD5
		DATA	$01
		CMDD4
		DATA	$91,$A1,$71,$51,$C5
		AJMP	byte_9A50A
		DATA	$C0
		ASTOP
byte_9A594:
		CMDD4
		DATA	$51,$C1,$53,$71,$51,$C1,$51,$71,$91,$C1,$91,$71,$51,$C1,$51
		ARET
byte_9A5A5:
		LOOP_START	$04
		CMDD5
		DATA	$40,$50,$C1,$51,$C1
		DO_LOOP
		ARET
_apu_mus08_B:
		CMDE2	$03
		CMDE1	$00
		CMDE0	$06
		CMDE9	$09
byte_9A5B7:
		LOOP_START	$05
		AJSR	byte_9A5D4
		DO_LOOP
		AJSR	byte_9A5E3
		LOOP_START	$02
		AJSR	byte_9A5D4
		DO_LOOP
		AJSR	byte_9A5E3
		LOOP_START	$05
		AJSR	byte_9A5D4
		DO_LOOP
		AJMP	byte_9A5B7
		DATA	$C0
		ASTOP
byte_9A5D4:
		LOOP_START	$02
		CMDD3
		DATA	$51,$90
		CMDD4
		DATA	$00
		CMDD3
		DATA	$90
		CMDD4
		DATA	$00,$20,$00
		DO_LOOP
		ARET
byte_9A5E3:
		LOOP_START	$02
		CMDD3
		DATA	$A1
		CMDD4
		DATA	$20,$50,$20,$50,$70,$50
		DO_LOOP
		LOOP_START	$02
		CMDD4
		DATA	$01,$40,$70,$40,$70,$90,$70
		DO_LOOP
		ARET
_apu_mus08_C:
		CMDE2	$03
		CMDE1	$03
		CMDE0	$03
		CMDE9	$00
byte_9A603:
		LOOP_START	$03
		AJSR	byte_9A643
		DO_LOOP
		LOOP_START	$02
		AJSR	byte_9A653
		AJSR	byte_9A643
		LOOP_START	$02
		CMDD3
		DATA	$23
		CMDD5
		DATA	$90,$A0,$A1
		CMDD2
		DATA	$A3
		CMDD5
		DATA	$90,$A0,$A1
		DO_LOOP
		LOOP_START	$02
		CMDD3
		DATA	$43
		CMDD5
		DATA	$B0
		CMDD6
		DATA	$00,$01
		CMDD3
		DATA	$03
		CMDD5
		DATA	$B0
		CMDD6
		DATA	$00,$01
		DO_LOOP
		DO_LOOP
		LOOP_START	$02
		AJSR	byte_9A653
		AJSR	byte_9A643
		DO_LOOP
		AJSR	byte_9A653
		AJMP	byte_9A603
		DATA	$C0
		ASTOP
byte_9A643:
		LOOP_START	$02
		CMDD3
		DATA	$53
		CMDD5
		DATA	$40,$50,$51
		CMDD3
		DATA	$03
		CMDD5
		DATA	$40,$50,$51
		DO_LOOP
		ARET
byte_9A653:
		CMDD3
		DATA	$53
		CMDD5
		DATA	$40,$50,$51
		CMDD3
		DATA	$03
		CMDD5
		DATA	$40,$50,$51
		CMDD3
		DATA	$53,$03,$23,$43
		ARET
_apu_mus08_D:
		CMDE0	$06
		CMDE9	$00
byte_9A669:
		LOOP_START	$0E
		DATA	$01,$20,$20
		DO_LOOP
		DATA	$31,$21,$21,$21
		AJMP	byte_9A669
		DATA	$C0
		ASTOP
_apu_mus09:
		.BYTE	$0F
		.WORD	_apu_mus09_A
		.WORD	_apu_mus09_B
		.WORD	_apu_mus09_C
		.WORD	_apu_mus09_D
_apu_mus09_A:
		CMDE2	$00
		CMDE1	$03
		CMDE0	$07
		CMDE9	$00
		CMDD9	$F4
byte_9A68B:
		LOOP_START	$02
		CMDD4
		DATA	$90,$C0,$40,$C0,$70,$C0,$40,$90,$C0,$90,$C0,$40,$70,$C0,$40,$C0
		CMDD4
		DATA	$90,$C0,$40,$C0,$70,$C0,$40,$90,$C0,$90,$C0,$40
		CMDD5
		DATA	$01
		CMDD4
		DATA	$B0,$C0
		DO_LOOP
		LOOP_START	$02
		AJSR	byte_9A713
		DATA	$C1
		CMDD5
		DATA	$01
		CMDD4
		DATA	$B0,$C0,$90,$C0
		CMDD5
		DATA	$00
		CMDD4
		DATA	$B0,$C0,$92,$70,$C0
		AJSR	byte_9A713
		CMDE1	$00
		DATA	$C1
		CMDD5
		DATA	$40,$20,$40,$70,$C1,$40,$20,$40
		CMDE1	$03
		CMDE2	$04
		DATA	$70
		CMDE8
		CMDE0	$01
		DATA	$73
		CMDE8
		LOOP_START	$0C
		DATA	$71
		CMDDA	$FF
		CMDEA	$01
		DO_LOOP
		CMDDA	$0C
		CMDEA	$F4
		CMDE0	$07
		CMDE2	$00
		DO_LOOP
		AJSR	byte_9A722
		DATA	$C1
		CMDD5
		DATA	$20,$00,$20,$41,$C0,$70,$40,$70,$90,$C3
		AJSR	byte_9A722
		DATA	$C1,$20,$00,$20,$41,$C0
		CMDD4
		DATA	$70,$90,$C0,$90,$C3
		AJMP	byte_9A68B
		DATA	$C0
		ASTOP
byte_9A713:
		DATA	$C1
		CMDD4
		DATA	$90,$70,$90,$C2,$40,$20,$C0,$40,$C0,$70,$C0,$90
		ARET
byte_9A722:
		CMDD5
		DATA	$90,$70,$90,$40,$C0,$70,$40,$00,$20,$C0,$00,$C0,$20,$42
		ARET
_apu_mus09_B:
		CMDE2	$00
		CMDE1	$03
		CMDE0	$07
		CMDE9	$05
		CMDD9	$F4
byte_9A73C:
		LOOP_START	$02
		LOOP_START	$03
		CMDD3
		DATA	$90,$C0,$90
		CMDD4
		DATA	$00
		CMDD3
		DATA	$70,$90
		CMDD4
		DATA	$00
		CMDD3
		DATA	$70
		DO_LOOP
		DATA	$90,$C0,$90
		CMDD4
		DATA	$00,$41,$21
		DO_LOOP
		LOOP_START	$02
		AJSR	byte_9A7A0
		DATA	$C1
		LOOP_START	$04
		CMDD3
		DATA	$90,$C0
		DO_LOOP
		CMDD4
		DATA	$40,$21,$42
		AJSR	byte_9A7A0
		CMDE1	$00
		LOOP_START	$02
		DATA	$C1
		CMDD4
		DATA	$40,$20,$40,$70
		DO_LOOP
		CMDE8
		DATA	$73
		DO_LOOP
		LOOP_START	$02
		CMDD3
		DATA	$90,$C0,$91
		CMDD4
		DATA	$70,$90,$C0,$01,$20,$C0,$00,$20,$40,$71
		CMDD4
		DATA	$20,$C0,$21
		CMDD5
		DATA	$20
		CMDD4
		DATA	$20,$C0,$41
		CMDD5
		DATA	$40,$C0
		CMDD4
		DATA	$41,$70,$90,$C0
		DO_LOOP
		AJMP	byte_9A73C
		DATA	$C0
		ASTOP
byte_9A7A0:
		DATA	$C1
		LOOP_START	$05
		CMDD3
		DATA	$90,$C0
		DO_LOOP
		DATA	$90
		CMDD4
		DATA	$01
		CMDD3
		DATA	$90
		ARET
_apu_mus09_C:
		CMDE2	$03
		CMDE1	$03
		CMDE0	$07
		CMDE9	$00
byte_9A7B5:
		LOOP_START	$02
		CMDD2
		DATA	$91
		CMDD3
		DATA	$40
		CMDD2
		DATA	$90,$C0,$90
		CMDD3
		DATA	$40
		CMDD2
		DATA	$90
		CMDD3
		DATA	$00,$C0,$01,$51,$01
		CMDD3
		DATA	$21,$70,$20,$C0,$20,$70,$20
		CMDD2
		DATA	$70,$C0,$71
		CMDD3
		DATA	$21
		CMDD2
		DATA	$71
		DO_LOOP
		LOOP_START	$04
		CMDD2
		DATA	$91
		CMDD3
		DATA	$40
		CMDD2
		DATA	$90,$C0,$90
		CMDD3
		DATA	$40
		CMDD2
		DATA	$90
		CMDD3
		DATA	$00,$C0,$01,$71,$01
		CMDD3
		DATA	$21,$60,$20,$C0,$20,$60,$20,$40,$C0,$41,$71,$91
		DO_LOOP
		LOOP_START	$02
		CMDD2
		DATA	$90,$C0,$91
		CMDD3
		DATA	$70,$90,$C0,$01,$20,$C0,$00,$20,$40,$71
		CMDD3
		DATA	$20,$C0,$21
		CMDD4
		DATA	$20
		CMDD3
		DATA	$20,$C0,$41
		CMDD4
		DATA	$40,$C0
		CMDD3
		DATA	$41,$70,$90,$C0
		DO_LOOP
		AJMP	byte_9A7B5
		DATA	$C0
		ASTOP
_apu_mus09_D:
		CMDE0	$07
		CMDE9	$00
byte_9A829:
		LOOP_START	$03
		DATA	$01,$01,$23,$03,$21,$01
		DO_LOOP
		DATA	$01,$01,$23,$01,$21,$20,$21,$20
		AJMP	byte_9A829
		DATA	$C0
		ASTOP
_apu_mus0A:
		.BYTE	$0F
		.WORD	_apu_mus0A_A
		.WORD	_apu_mus0A_B
		.WORD	_apu_mus0A_C
		.WORD	_apu_mus0A_D
_apu_mus0A_A:
		CMDE2	$00
		CMDE1	$03
		CMDE0	$08
		CMDE9	$03
		CMDD9	$F2
byte_9A852:
		LOOP_START	$02
		AJSR	byte_9A8D3
		CMDD4
		DATA	$50,$70,$C0,$03,$C0
		CMDD5
		DATA	$00
		CMDD4
		DATA	$B0,$C0,$72,$C1
		AJSR	byte_9A8D3
		CMDD4
		DATA	$50,$70,$C0,$03,$C0
		CMDD5
		DATA	$00
		CMDD4
		DATA	$B0
		CMDD5
		DATA	$00
		CMDD4
		DATA	$74
		DO_LOOP
		CMDE1	$01
		CMDD4
		DATA	$82
		CMDD5
		DATA	$02,$31,$22
		CMDD4
		DATA	$A4,$B1
		CMDD5
		DATA	$20,$51,$21,$34,$30,$20,$30,$09
		CMDD4
		DATA	$80
		CMDD5
		DATA	$00,$30,$00,$31,$58
		CMDE1	$00
		DATA	$C0,$70,$C0,$50,$70,$50,$71
		CMDE1	$03
		DATA	$51,$30,$01,$50,$30,$01,$32,$80,$C0,$70,$C0,$51,$30,$01,$50,$30
		DATA	$01,$32
		CMDD6
		DATA	$00
		CMDD5
		DATA	$A0,$80,$70,$51,$30,$01,$50,$30,$01,$32,$A0,$C0,$80,$C0,$70,$50
		DATA	$30,$50,$30,$00,$32,$00,$30,$00,$20,$20,$C0,$50
		AJMP	byte_9A852
		DATA	$C0
		ASTOP
byte_9A8D3:
		CMDD4
		DATA	$70,$50,$40,$00,$C0
		CMDD3
		DATA	$70
		CMDD4
		DATA	$00,$C0,$30,$C0,$50,$C0,$30,$C0,$00,$C0
		ARET
_apu_mus0A_B:
		CMDE2	$00
		CMDE1	$03
		CMDE0	$08
		CMDE9	$06
		CMDD9	$F2
byte_9A8F1:
		LOOP_START	$04
		DATA	$C1
		CMDD3
		DATA	$70,$C1,$70,$C0,$70,$C1,$A0,$C1,$A0,$C0,$A0,$C1
		CMDD3
		DATA	$90,$C1,$90,$C0,$90,$C1,$B0,$C1,$B0
		CMDD4
		DATA	$00,$C0
		DO_LOOP
		DATA	$C1
		CMDD4
		DATA	$70,$C0,$70,$50,$C0,$70,$C0,$70,$50,$C0,$70,$50,$C0,$70,$C1,$70
		DATA	$C0,$70,$50,$C0,$70,$C0,$00,$30,$70
		CMDD5
		DATA	$00
		CMDD4
		DATA	$70,$30,$70,$C1,$80,$C0,$80,$70,$C0,$80,$C0,$70,$80,$C0,$80,$70
		DATA	$C0,$80,$C1,$A0,$C0,$A0,$80,$C0,$A0,$C0
		CMDE1	$00
		CMDD5
		DATA	$30,$C0,$20,$30,$20,$31
		CMDE1	$03
		CMDD4
		DATA	$51,$30,$01,$50,$30,$01,$32,$80,$C0,$70,$C0,$51,$30,$01,$50,$30
		DATA	$01,$32
		CMDD5
		DATA	$00
		CMDD4
		DATA	$A0,$80,$70,$51,$30,$01,$50,$30,$01,$32,$A0,$C0,$80,$C0,$70,$50
		DATA	$30,$50,$30,$00,$32,$00,$30,$00,$20,$20,$C0,$50
		AJMP	byte_9A8F1
		DATA	$C0
		ASTOP
_apu_mus0A_C:
		CMDE2	$03
		CMDE1	$03
		CMDE0	$08
		CMDE9	$01
		CMDD9	$FE
byte_9A993:
		LOOP_START	$04
		LOOP_START	$04
		CMDD3
		DATA	$00
		CMDD4
		DATA	$00
		DO_LOOP
		LOOP_START	$04
		CMDD3
		DATA	$30
		CMDD4
		DATA	$30
		DO_LOOP
		LOOP_START	$04
		CMDD3
		DATA	$50
		CMDD4
		DATA	$50
		DO_LOOP
		LOOP_START	$04
		CMDD3
		DATA	$70
		CMDD4
		DATA	$70
		DO_LOOP
		DO_LOOP
		LOOP_START	$04
		CMDD3
		DATA	$80
		CMDD4
		DATA	$80
		DO_LOOP
		LOOP_START	$04
		CMDD3
		DATA	$A0
		CMDD4
		DATA	$A0
		DO_LOOP
		LOOP_START	$04
		CMDD3
		DATA	$B0
		CMDD4
		DATA	$B0
		DO_LOOP
		DATA	$00
		CMDD5
		DATA	$00
		CMDD4
		DATA	$00
		CMDD5
		DATA	$00
		CMDD3
		DATA	$A0
		CMDD4
		DATA	$A0
		CMDD3
		DATA	$A0
		CMDD4
		DATA	$A0
		LOOP_START	$08
		CMDD3
		DATA	$80
		CMDD4
		DATA	$80
		DO_LOOP
		LOOP_START	$04
		CMDD3
		DATA	$A0
		CMDD4
		DATA	$A0
		DO_LOOP
		CMDD3
		DATA	$A0,$C6
		LOOP_START	$03
		CMDD4
		DATA	$00
		CMDD5
		DATA	$00
		CMDD4
		DATA	$00
		CMDD5
		DATA	$00
		CMDD3
		DATA	$A0
		CMDD4
		DATA	$A0
		CMDD3
		DATA	$A0
		CMDD4
		DATA	$A0
		CMDD3
		DATA	$80
		CMDD4
		DATA	$80
		CMDD3
		DATA	$80
		CMDD4
		DATA	$80
		CMDD3
		DATA	$80,$C0,$A0,$C0
		DO_LOOP
		CMDD4
		DATA	$02
		CMDD3
		DATA	$A2,$85,$A0,$A0,$C0,$A0
		AJMP	byte_9A993
		DATA	$C0
		ASTOP
_apu_mus0A_D:
		CMDE0	$08
		CMDE9	$01
byte_9AA19:
		LOOP_START	$2C
		DATA	$01,$21
		DO_LOOP
		DATA	$01,$21,$01,$21,$00,$21,$20,$21,$20,$20
		LOOP_START	$03
		DATA	$01,$20,$00,$C1,$21,$01,$20,$00,$21,$21
		DO_LOOP
		DATA	$22,$22,$22,$20,$20,$20,$20,$20,$00,$20
		AJMP	byte_9AA19
		DATA	$C0
		ASTOP
_apu_mus0B:
		.BYTE	$0F
		.WORD	_apu_mus0B_A
		.WORD	_apu_mus0B_B
		.WORD	_apu_mus0B_C
		.WORD	_apu_mus0B_D
_apu_mus0B_A:
		CMDE2	$00
		CMDE1	$01
		CMDE0	$05
		CMDE9	$00
		CMDD9	$F4
byte_9AA57:
		LOOP_START	$02
		LOOP_START	$02
		CMDD5
		DATA	$00,$C0
		CMDD4
		DATA	$70,$C2,$A0,$C0,$50,$C2
		CMDD6
		DATA	$00,$C0
		CMDEA	$02
		CMDD5
		DATA	$70,$C0
		CMDEA	$03
		DATA	$A0,$C0
		CMDEA	$02
		DATA	$50,$C0
		CMDEA	$F9
		DO_LOOP
		LOOP_START	$02
		CMDD5
		DATA	$30,$C0
		CMDD4
		DATA	$A0,$C2
		CMDD5
		DATA	$10,$C0
		CMDD4
		DATA	$80,$C2
		CMDD6
		DATA	$30,$C0
		CMDEA	$02
		CMDD5
		DATA	$A0,$C0
		CMDEA	$03
		CMDD6
		DATA	$10,$C0
		CMDEA	$02
		CMDD5
		DATA	$80,$C0
		CMDEA	$F9
		DO_LOOP
		DO_LOOP
		AJSR	byte_9AAF0
		AJSR	byte_9AAFD
		AJSR	byte_9AAF0
		DATA	$C1
		CMDD4
		DATA	$80,$C0,$80,$C0,$81,$71,$81,$C1,$71
		AJSR	byte_9AAF0
		AJSR	byte_9AAFD
		AJSR	byte_9AAF0
		DATA	$C1
		CMDD5
		DATA	$80,$C0,$80,$C0,$80,$C0,$81,$71,$53
		CMDD5
		DATA	$3F
		AJSR	byte_9AB07
		CMDD5
		DATA	$1F,$C1
		CMDD4
		DATA	$11
		CMDD5
		DATA	$11
		CMDD4
		DATA	$11,$61,$81,$C1
		CMDD5
		DATA	$31
		CMDE8
		CMDD5
		DATA	$3F
		AJSR	byte_9AB07
		CMDD5
		DATA	$1F,$C1
		CMDD4
		DATA	$11
		CMDD5
		DATA	$11
		CMDD4
		DATA	$11,$21
		CMDD5
		DATA	$21,$C1,$31
		AJMP	byte_9AA57
		DATA	$C0
		ASTOP
byte_9AAF0:
		CMDD5
		DATA	$01
		CMDD4
		DATA	$A0,$C0,$91,$50,$C0,$C1,$51,$71,$51
		ARET
byte_9AAFD:
		DATA	$C1
		CMDD5
		DATA	$31,$C1,$31,$21,$31,$C1,$21
		ARET
byte_9AB07:
		DATA	$C1
		CMDD4
		DATA	$31
		CMDD5
		DATA	$31
		CMDD4
		DATA	$31,$71,$81,$C1
		CMDD5
		DATA	$11
		CMDE8
		ARET
_apu_mus0B_B:
		CMDE2	$00
		CMDE1	$01
		CMDE0	$05
		CMDE9	$08
		CMDD9	$F4
		DATA	$C1
		AJMP	byte_9AA57
		DATA	$C0
		ASTOP
_apu_mus0B_C:
		CMDE2	$04
		CMDE1	$00
		CMDE0	$05
		CMDE9	$00
byte_9AB2D:
		AJSR	byte_9AB72
		DATA	$C7
		AJSR	byte_9AB72
		CMDD3
		DATA	$81,$A1
		CMDD4
		DATA	$33
		LOOP_START	$04
		CMDD3
		DATA	$51,$C3,$53
		CMDD4
		DATA	$31,$51,$C1
		CMDD3
		DATA	$A1,$C3,$A5
		CMDD4
		DATA	$01,$C1
		DO_LOOP
		AJSR	byte_9AB87
		CMDD3
		DATA	$10,$C0,$11
		CMDD4
		DATA	$11
		CMDD3
		DATA	$11,$C1,$11
		CMDD4
		DATA	$11
		CMDD3
		DATA	$31
		AJSR	byte_9AB87
		DATA	$10,$C0,$11
		CMDD4
		DATA	$11
		CMDD3
		DATA	$11,$C1
		CMDD4
		DATA	$21
		CMDD3
		DATA	$31
		CMDD4
		DATA	$31
		AJMP	byte_9AB2D
		DATA	$C0
		ASTOP
byte_9AB72:
		CMDD3
		DATA	$0B
		CMDE8
		CMDD3
		DATA	$07
		CMDD3
		DATA	$00,$C0,$01,$CF
		CMDD3
		DATA	$3B
		CMDE8
		CMDD3
		DATA	$37
		CMDD3
		DATA	$30,$C0,$31,$C7
		ARET
byte_9AB87:
		CMDD3
		DATA	$30,$C0,$31
		CMDD4
		DATA	$31
		CMDD3
		DATA	$70,$80,$C0,$A2
		CMDD4
		DATA	$03
		CMDD3
		DATA	$30,$C0,$31
		CMDD4
		DATA	$31
		CMDD3
		DATA	$31,$C1,$31
		CMDD4
		DATA	$31
		CMDD3
		DATA	$11
		CMDD3
		DATA	$10,$C0,$11
		CMDD4
		DATA	$11
		CMDD3
		DATA	$50,$60,$C0,$82,$A3
		ARET
_apu_mus0B_D:
		CMDE0	$05
		CMDE9	$00
byte_9ABB3:
		LOOP_START	$08
		CMDE9	$00
		DATA	$00
		CMDE9	$07
		DATA	$30,$30,$30
		CMDE9	$00
		DATA	$20,$30,$00
		CMDE9	$07
		DATA	$30,$30,$30,$30,$30
		CMDE9	$00
		DATA	$21
		CMDE9	$01
		DATA	$21
		CMDE9	$03
		DATA	$21
		CMDE9	$04
		DATA	$21
		DO_LOOP
		LOOP_START	$20
		CMDE9	$00
		DATA	$00
		CMDE9	$07
		DATA	$30,$30,$30
		CMDE9	$00
		DATA	$20
		CMDE9	$07
		DATA	$30,$30,$30
		DO_LOOP
		AJMP	byte_9ABB3
		DATA	$C0
		ASTOP
_apu_mus0C:
		DATA	$0F
		.WORD	_apu_mus0C_A
		.WORD	_apu_mus0C_B
		.WORD	_apu_mus0C_C
		.WORD	_apu_mus0C_D
_apu_mus0C_A:
		CMDE2	$00
		CMDE1	$00
		CMDE0	$07
		CMDE9	$00
		CMDD9	$EC
byte_9AC01:
		AJSR	byte_9AC5B
		CMDD5
		DATA	$52,$32,$79
		AJSR	byte_9AC5B
		DATA	$52,$32,$09
		LOOP_START	$02
		AJSR	byte_9AC6E
		AJSR	byte_9AC7F
		AJSR	byte_9AC6E
		AJSR	byte_9AC8B
		DO_LOOP
		AJSR	byte_9AC95
		DATA	$C0
		CMDD4
		DATA	$70,$80,$A0
		CMDD5
		DATA	$00,$20,$C0,$30,$C0,$50,$C0,$70,$50,$C0,$30,$C0
		AJSR	byte_9AC95
		DATA	$C1,$70,$C0,$50,$C0,$30,$C0,$50,$70,$C0,$50,$C0,$30,$00,$C0
		AJSR	byte_9AC9F
		DATA	$71,$50,$71,$50,$70,$50,$00,$C0,$00,$C0
		CMDD4
		DATA	$A2
		CMDD5
		DATA	$00,$C7
		AJMP	byte_9AC01
		DATA	$C0
		ASTOP
byte_9AC5B:
		DATA	$C0
		CMDD5
		DATA	$50,$30,$C0,$50,$30,$C0,$50,$C0
		CMDD5
		DATA	$50,$C0,$30,$50,$C0,$70,$C0
		ARET
byte_9AC6E:
		LOOP_START	$02
		CMDD5
		DATA	$00
		CMDD4
		DATA	$00,$C0,$30,$70,$C0
		DO_LOOP
		CMDD5
		DATA	$00,$C0,$20,$C0
		ARET
byte_9AC7F:
		CMDD5
		DATA	$32,$22,$03
		CMDD4
		DATA	$A0,$C0,$A0
		CMDD5
		DATA	$00,$C1
		ARET
byte_9AC8B:
		CMDD5
		DATA	$32,$52,$73,$50,$C0,$30,$20,$C1
		ARET
byte_9AC95:
		LOOP_START	$02
		CMDD5
		DATA	$00,$30,$C0,$72,$C1
		DO_LOOP
		ARET
byte_9AC9F:
		DATA	$81,$30,$81,$30,$80,$30,$A1,$50,$A1,$50,$A0,$50,$C1
		CMDD6
		DATA	$00,$C0
		CMDD5
		DATA	$A0,$C0,$70,$C0
		CMDD6
		DATA	$00
		CMDD5
		DATA	$A0,$C0,$71,$A0,$C1,$51,$30,$51,$30,$50,$30
		ARET
_apu_mus0C_B:
		CMDE2	$00
		CMDE1	$00
		CMDE0	$07
		CMDE9	$00
		CMDD9	$EC
byte_9ACCD:
		AJSR	byte_9AD45
		CMDD5
		DATA	$22,$02,$39
		AJSR	byte_9AD45
		DATA	$22,$02
		CMDD4
		DATA	$79
		CMDE9	$08
		DATA	$C1
		AJSR	byte_9AC6E
		AJSR	byte_9AC7F
		AJSR	byte_9AC6E
		AJSR	byte_9AD58
		CMDD5
		DATA	$71,$50,$C0,$30,$20,$C1
		AJSR	byte_9AC6E
		AJSR	byte_9AC7F
		AJSR	byte_9AC6E
		AJSR	byte_9AD58
		DATA	$71,$50,$C0,$30,$20
		CMDE9	$00
		AJSR	byte_9AD5E
		DATA	$C0
		CMDD4
		DATA	$30,$50,$70,$80,$A0,$C0
		CMDD5
		DATA	$00,$C0,$20,$C0,$30,$20,$C0,$00,$C0
		AJSR	byte_9AD5E
		DATA	$C1,$30,$C0,$20,$C0,$00,$C0,$20,$30,$C0,$20,$C0,$00
		CMDD4
		DATA	$70,$C0
		CMDE9	$08
		DATA	$C1
		AJSR	byte_9AC9F
		DATA	$71,$50,$71,$50
		CMDE9	$00
		CMDD4
		DATA	$70,$C0,$70,$C0,$52,$70,$C7
		AJMP	byte_9ACCD
		DATA	$C0
		ASTOP
byte_9AD45:
		DATA	$C0
		CMDD5
		DATA	$20,$00,$C0,$20,$00,$C0,$20,$C0
		CMDD5
		DATA	$20,$C0,$00,$20,$C0,$30,$C0
		ARET
byte_9AD58:
		CMDD5
		DATA	$32,$52,$71
		CMDE8
		ARET
byte_9AD5E:
		LOOP_START	$02
		CMDD4
		DATA	$80
		CMDD5
		DATA	$00,$C0,$33,$C0
		DO_LOOP
		ARET
_apu_mus0C_C:
		CMDE2	$04
		CMDE1	$03
		CMDE0	$07
		CMDE9	$00
		CMDD9	$04
byte_9AD73:
		LOOP_START	$06
		CMDD3
		DATA	$00,$C0,$00,$C0,$30,$70,$C0
		CMDD2
		DATA	$A0,$C0
		CMDD2
		DATA	$A0,$C0,$A0
		CMDD3
		DATA	$20,$C0,$50,$C0
		CMDD3
		DATA	$00,$C0,$00,$C0,$30,$70,$C0,$50,$C0
		CMDD3
		DATA	$50,$C0,$70
		CMDD2
		DATA	$A0,$C0,$B0,$C0
		DO_LOOP
		LOOP_START	$03
		AJSR	byte_9ADCC
		CMDD3
		DATA	$00,$C0,$00,$C0
		CMDD2
		DATA	$A0,$C0,$A0,$C0
		CMDD3
		DATA	$00,$20,$C0,$31,$20,$00,$C0
		DO_LOOP
		AJSR	byte_9ADCC
		CMDD3
		DATA	$00,$C0,$00,$C0
		CMDD2
		DATA	$A2
		CMDD3
		DATA	$00,$C0,$02,$30,$C0,$70,$C0
		AJMP	byte_9AD73
		DATA	$C0
		ASTOP
byte_9ADCC:
		CMDD2
		DATA	$80,$C1,$81
		CMDD3
		DATA	$80
		CMDD2
		DATA	$80,$C0
		CMDD2
		DATA	$A0,$C1,$A1
		CMDD3
		DATA	$A0
		CMDD2
		DATA	$A0,$C0
		ARET
_apu_mus0C_D:
		CMDE0	$07
		CMDE9	$00
byte_9ADE3:
		LOOP_START	$0C
		DATA	$01,$22,$01,$20,$01,$21,$01,$21
		DO_LOOP
		LOOP_START	$0E
		DATA	$01,$21,$00,$00,$21
		DO_LOOP
		DATA	$21,$21,$21,$00,$20,$00,$20,$20,$00,$20,$20,$00,$20
		AJMP	byte_9ADE3
		DATA	$C0
		ASTOP
_apu_mus0D:
		.BYTE	$0F
		.WORD	_apu_mus0D_A
		.WORD	_apu_mus0D_B
		.WORD	_apu_mus0D_C
		.WORD	_apu_mus0D_D
_apu_mus0D_A:
		CMDE2	$00
		CMDE1	$03
		CMDE0	$05
		CMDE9	$00
		CMDD9	$F4
		DATA	$C1
		CMDD4
		DATA	$73,$60,$50,$40,$C0,$40,$C2,$51,$C1,$61,$C1,$71,$87,$C0
		ASTOP
_apu_mus0D_B:
		CMDE2	$00
		CMDE1	$03
		CMDE0	$05
		CMDE9	$00
		CMDD9	$F4
		DATA	$C1
		CMDD4
		DATA	$13,$00
		CMDD3
		DATA	$B0,$A0,$C0,$A0,$C2,$B1,$C1
		CMDD4
		DATA	$01,$C1,$11,$27,$C0
		ASTOP
_apu_mus0D_C:
		CMDE2	$04
		CMDE1	$03
		CMDE0	$05
		CMDE9	$00
		CMDD9	$0C
		CMDD2
		DATA	$A5,$90,$80,$70,$C0,$70,$C2,$81,$C1,$91,$C1,$A1,$B7,$C0
		ASTOP
_apu_mus0D_D:
		CMDE0	$05
		CMDE9	$00
		DATA	$01,$21,$01,$20,$20,$21,$21,$01,$21,$01,$21,$01,$21
		LOOP_START	$08
		DATA	$20
		DO_LOOP
		DATA	$C0
		ASTOP
_apu_mus0E:
		.BYTE	$0F
		.WORD	_apu_mus0E_A
		.WORD	_apu_mus0E_B
		.WORD	_apu_mus0E_C
		.WORD	_apu_mus0E_D
_apu_mus0E_A:
		CMDE2	$00
		CMDE1	$03
		CMDE0	$08
		CMDE9	$00
		CMDD9	$EF
byte_9AE8D:
		LOOP_START	$02
		CMDE1	$03
		LOOP_START	$02
		CMDD5
		DATA	$10,$00,$10
		CMDD4
		DATA	$A0
		CMDE8
		DATA	$A3,$C0,$A0,$C0,$A0,$C0,$A0,$C0,$A0
		DO_LOOP
		CMDE1	$00
		LOOP_START	$02
		CMDD4
		DATA	$10,$20,$30,$40,$50,$10,$C0,$71
		CMDD5
		DATA	$10,$20,$30,$40,$50,$C1
		DO_LOOP
		DO_LOOP
		CMDE1	$03
		AJSR	byte_9AF05
		DATA	$C0
		CMDD5
		DATA	$60,$60,$C0,$60,$60,$C0,$71,$70,$60,$C4
		AJSR	byte_9AF05
		DATA	$C0,$60,$60,$C0,$60,$60,$C0,$71,$70,$60,$C0,$A0,$90,$80,$70
		LOOP_START	$02
		CMDD5
		DATA	$A0,$90,$A0,$70
		CMDE8
		DATA	$73,$C0,$70,$C0,$70,$C0,$70,$C0,$70
		DO_LOOP
		CMDD5
		DATA	$70,$60,$50,$40,$C0,$50,$40,$30,$C0,$20,$20,$C0,$20,$20,$C0,$20
		AJMP	byte_9AE8D
		DATA	$C0
		ASTOP
byte_9AF05:
		DATA	$C0
		CMDD5
		DATA	$60,$60,$C0,$60,$60,$C0,$51,$50,$60,$C4
		ARET
_apu_mus0E_B:
		CMDE2	$00
		CMDE1	$03
		CMDE0	$08
		CMDE9	$01
		CMDD9	$EF
byte_9AF1C:
		LOOP_START	$02
		CMDE1	$03
		LOOP_START	$02
		CMDD4
		DATA	$72,$40
		CMDE8
		DATA	$43,$C0,$40,$C0,$40,$C0,$40,$C0,$40
		DO_LOOP
		LOOP_START	$02
		CMDE1	$02
		CMDE0	$04
		CMDD6
		CMDE9	$0E
		LOOP_START	$08
		DATA	$10,$20
		CMDEA	$FF
		DO_LOOP
		LOOP_START	$08
		DATA	$10,$20
		CMDEA	$01
		DO_LOOP
		CMDEA	$F8
		CMDE0	$08
		CMDE9	$01
		CMDE1	$03
		DO_LOOP
		DO_LOOP
		AJSR	byte_9AF6E
		AJSR	byte_9AF89
		CMDD5
		DATA	$10,$00
		CMDD4
		DATA	$B0,$A0,$C0,$B0,$A0,$90,$C0,$80,$80,$C0,$80,$80,$C0,$80
		AJMP	byte_9AF1C
		DATA	$C0
		ASTOP
byte_9AF6E:
		LOOP_START	$02
		DATA	$C0
		CMDD5
		DATA	$20,$20,$C0,$20,$20,$C0,$11,$10,$20,$C5
		CMDD5
		DATA	$20,$20,$C0,$20,$20,$C0,$31,$30,$20,$C4
		DO_LOOP
		ARET
byte_9AF89:
		LOOP_START	$02
		CMDD5
		DATA	$42,$10
		CMDE8
		DATA	$13,$C0,$10,$C0,$10,$C0,$10,$C0,$10
		DO_LOOP
		ARET
_apu_mus0E_C:
		CMDE2	$04
		CMDE1	$03
		CMDE0	$08
		CMDE9	$00
		CMDD9	$07
byte_9AFA4:
		LOOP_START	$02
		LOOP_START	$08
		CMDD2
		DATA	$A0,$C0,$50,$C0
		DO_LOOP
		LOOP_START	$08
		CMDD2
		DATA	$90,$C0,$40,$C0
		DO_LOOP
		DO_LOOP
		LOOP_START	$02
		DATA	$C0
		CMDD2
		DATA	$A0,$A0,$C0,$A0,$A0,$C0,$91,$90,$A0,$C0,$A0
		CMDE0	$04
		CMDD4
		DATA	$A0,$90
		CMDE0	$08
		DATA	$80,$C0,$C0
		CMDD2
		DATA	$A0,$A0,$C0,$A0,$A0,$C0,$B1,$B0,$A0,$C0,$A0
		CMDE0	$04
		CMDD3
		DATA	$A0,$90
		CMDE0	$08
		DATA	$80,$C0
		DO_LOOP
		LOOP_START	$08
		CMDD3
		DATA	$70,$C0,$10,$C0
		DO_LOOP
		CMDD3
		DATA	$70,$60,$50,$40,$C0,$50,$40,$30,$C0,$20,$20,$C0,$20,$20,$C0,$20
		AJMP	byte_9AFA4
		DATA	$C0
		ASTOP
_apu_mus0E_D:
		CMDE0	$08
		CMDE9	$00
byte_9B008:
		LOOP_START	$02
		LOOP_START	$02
		DATA	$01,$21,$01,$20,$20,$01,$21,$00,$00,$21
		DO_LOOP
		LOOP_START	$02
		DATA	$01,$21,$01,$21,$01,$21,$01,$21
		DO_LOOP
		DO_LOOP
		LOOP_START	$04
		DATA	$00,$20,$20,$00,$20,$20,$00,$21,$00,$20,$C0,$03
		DO_LOOP
		LOOP_START	$02
		DATA	$01,$21,$01,$20,$20,$01,$21,$00,$00,$21
		DO_LOOP
		DATA	$20,$20,$20,$20,$00,$20,$20,$20,$00,$20,$20,$00,$20,$20,$00,$20
		AJMP	byte_9B008
		DATA	$C0
		ASTOP
_apu_mus0F:
		.BYTE	$01
		.WORD	_apu_mus0F_A
_apu_mus0F_A:
		CMDE2	$00
		CMDE1	$00
		CMDE0	$05
		DATA	$C0,$C0
		ASTOP
_apu_mus10:
		.BYTE	$0F
		.WORD	_apu_mus10_A
		.WORD	_apu_mus10_B
		.WORD	_apu_mus10_C
		.WORD	_apu_mus10_D
_apu_mus10_A:
		CMDE2	$00
		CMDE1	$03
		CMDE0	$05
		CMDE9	$00
		CMDD9	$F4
		DATA	$C1
		CMDD5
		DATA	$73,$50,$C1,$40,$C1,$21,$C3
		CMDD4
byte_9B07D:
		.BYTE	$75,$41,$C0,$71,$C0,$91,$C3,$41,$71,$C0,$96,$C2,$41,$C0,$71,$C0
		DATA	$91,$C0,$A1,$90,$C1,$A2,$92,$70,$91,$C0
		CMDD5
		DATA	$01,$C0,$23,$C1
		CMDD4
		DATA	$91
		CMDD5
		DATA	$01,$C0,$26,$C1,$32,$20,$31,$20,$31,$20,$31,$C0,$21,$C0,$01,$C0
		DATA	$21,$C0,$70,$C0,$71,$C0
		CMDE1	$02
		CMDE0	$01
		DATA	$70
		CMDE8
		CMDE0	$02
		DATA	$79,$50,$40,$20,$00
		CMDD4
		DATA	$B0,$90,$70
		CMDE0	$05
		CMDE1	$03
		CMDD5
		DATA	$50,$C0,$51,$C0
		CMDE1	$02
		CMDE0	$01
		DATA	$50
		CMDE8
		CMDE0	$02
		DATA	$59,$30,$20,$00
		CMDD4
		DATA	$A0,$90,$70,$50
		CMDE0	$05
		CMDE1	$03
		DATA	$C1
		CMDD5
		DATA	$73,$91,$C0,$B1,$C0
		CMDE1	$02
		DATA	$73
		CMDE8
		CMDE0	$02
		DATA	$70,$50,$40,$20,$00
		CMDD4
		DATA	$B0,$90
		CMDE1	$03
		DATA	$72
		CMDE0	$05
		CMDE8
		DATA	$73
		AJMP	byte_9B07D+1
		DATA	$C0
		ASTOP
_apu_mus10_B:
		CMDE2	$00
		CMDE1	$03
		CMDE0	$05
		CMDE9	$00
		CMDD9	$F4
		DATA	$C1
		CMDD4
		DATA	$B3,$90,$C1,$70,$C1,$51,$C3
		CMDD3
		DATA	$75
byte_9B11A:
		CMDD4
		DATA	$01,$C0,$41,$C0,$41,$C3,$01,$41,$C0,$46,$C2,$01,$C0,$41,$C0,$41
		DATA	$C0,$41,$40,$C1,$42,$42,$40,$51,$C0,$91,$C0,$93,$C1,$51,$91,$C0
		.BYTE	$96,$C1,$92,$90,$91,$90,$91,$90,$91,$C0,$91,$C0,$91,$C0,$91,$C0
		.BYTE	$B0,$C0,$B1,$C0,$B5,$C0,$90,$C0,$91,$C0,$95,$C0,$C1,$B3
		CMDD5
		DATA	$01,$C0,$21,$C0
		CMDD4
		DATA	$B5,$C5
		AJMP	byte_9B11A
		DATA	$C0
		ASTOP
_apu_mus10_C:
		CMDE2	$03
		CMDE1	$03
		CMDE0	$05
		CMDE9	$00
		CMDD2
		DATA	$74,$C0,$71,$C0,$71,$C0,$71,$C3,$75
byte_9B178:
		LOOP_START	$04
		CMDD3
		DATA	$01,$C0
		CMDD2
		DATA	$B1,$C0,$91,$C0,$71,$C0
		DO_LOOP
		LOOP_START	$04
		CMDD3
		DATA	$51,$C0,$41,$C0,$21,$C0,$01,$C0
		DO_LOOP
		CMDD3
		DATA	$70,$C0,$71,$C0,$75,$C0,$50,$C0,$51,$C0,$55,$C0,$75,$71,$C0,$71
		DATA	$C0,$71,$C3
		CMDD2
		DATA	$75
		AJMP	byte_9B178
		DATA	$C0
		ASTOP
_apu_mus10_D:
		CMDE0	$05
		CMDE9	$00
		DATA	$01,$25,$20,$22,$25,$25
byte_9B1B6:
		CMDE9	$05
		DATA	$12,$31,$30
		AJMP	byte_9B1B6
		DATA	$C0
		ASTOP
_apu_mus11:
		.BYTE	$0F
		.WORD	_apu_mus11_A
		.WORD	_apu_mus11_B
		.WORD	_apu_mus11_C
		.WORD	_apu_mus11_D
_apu_mus11_A:
		CMDE2	$00
		CMDE1	$03
		CMDE0	$05
		CMDE9	$03
		CMDD9	$F4
byte_9B1D3:
		LOOP_START	$02
		AJSR	byte_9B202
		AJSR	byte_9B20A
		AJSR	byte_9B202
		AJSR	byte_9B20D
		DO_LOOP
		LOOP_START	$02
		LOOP_START	$02
		CMDD4
		DATA	$01,$41,$81
		CMDD5
		DATA	$01,$41,$81,$C3
		DO_LOOP
		LOOP_START	$02
		CMDD4
		DATA	$11,$51,$91
		CMDD5
		DATA	$11,$51,$91,$C3
		DO_LOOP
		DO_LOOP
		AJMP	byte_9B1D3
		DATA	$C0
		ASTOP
byte_9B202:
		CMDD4
		DATA	$22,$40,$53,$22,$40,$53
		ARET
byte_9B20A:
		CMDD4
		DATA	$8F
		ARET
byte_9B20D:
		CMDD4
		DATA	$AF
		ARET
_apu_mus11_B:
		CMDE2	$00
		CMDE1	$03
		CMDE0	$05
		CMDE9	$0A
		CMDD9	$F4
		DATA	$C1
		AJMP	byte_9B1D3
		DATA	$C0
		ASTOP
_apu_mus11_C:
		CMDE2	$04
		CMDE1	$03
		CMDE0	$05
		CMDE9	$00
byte_9B228:
		LOOP_START	$02
		CMDD3
		DATA	$23
		CMDD2
		DATA	$93
		CMDD3
		DATA	$23
		CMDD2
		DATA	$93
		CMDD3
		DATA	$13
		CMDD2
		DATA	$83
		CMDD3
		DATA	$13
		CMDD2
		DATA	$83
		CMDD3
		DATA	$23
		CMDD2
		DATA	$93
		CMDD3
		DATA	$23
		CMDD2
		DATA	$93
		CMDD3
		DATA	$13
		CMDD2
		DATA	$73
		CMDD3
		DATA	$13
		CMDD2
		DATA	$73
		DO_LOOP
		LOOP_START	$02
		LOOP_START	$02
		CMDD2
		DATA	$90,$C0,$93,$C3,$90,$C0,$91,$C1
		DO_LOOP
		LOOP_START	$02
		CMDD2
		DATA	$A0,$C0,$A3,$C3,$A0,$C0,$A1,$C1
		DO_LOOP
		DO_LOOP
		AJMP	byte_9B228
		DATA	$C0
		ASTOP
_apu_mus11_D:
		CMDE0	$05
		CMDE9	$06
byte_9B26F:
		DATA	$01,$21
		AJMP	byte_9B26F
		DATA	$C0
		ASTOP
_apu_mus12:
		.BYTE	$0F
		.WORD	_apu_mus12_A
		.WORD	_apu_mus12_B
		.WORD	_apu_mus12_C
		.WORD	_apu_mus12_D
_apu_mus12_A:
		CMDE2	$00
		CMDE1	$03
		CMDE0	$04
		CMDE9	$03
		CMDD9	$EE
byte_9B289:
		AJSR	byte_9B2A9
		AJSR	byte_9B2C8
		CMDD5
		DATA	$41,$41,$C1,$65,$73,$B5,$97,$C1
		AJSR	byte_9B2C8
		DATA	$41,$41,$C1,$65,$73,$B9,$91,$71,$61
		AJMP	byte_9B289
		DATA	$C0
		ASTOP
byte_9B2A9:
		LOOP_START	$02
		CMDD4
		DATA	$41,$61,$71,$41,$91,$A1,$91,$71,$B1,$C1,$B1,$99
		CMDD4
		DATA	$41,$61,$71,$41,$91,$A1,$91,$71
		CMDD5
		DATA	$41,$C1,$41,$39
		DO_LOOP
		ARET
byte_9B2C8:
		CMDD5
		DATA	$45,$65,$73,$65,$75,$93
		ARET
_apu_mus12_B:
		CMDE2	$00
		CMDE1	$03
		CMDE0	$04
		CMDE9	$0A
		CMDD9	$EE
		DATA	$C1
		AJMP	byte_9B289
		DATA	$C0
		ASTOP
_apu_mus12_C:
		CMDE2	$05
		CMDE1	$03
		CMDE0	$04
		CMDE9	$01
		CMDD9	$06
byte_9B2EA:
		AJSR	byte_9B2F5
		AJSR	byte_9B30C
		AJMP	byte_9B2EA
		DATA	$C0
		ASTOP
byte_9B2F5:
		LOOP_START	$02
		LOOP_START	$08
		CMDD3
		DATA	$41
		DO_LOOP
		LOOP_START	$08
		DATA	$21
		DO_LOOP
		LOOP_START	$08
		CMDD3
		DATA	$01
		DO_LOOP
		LOOP_START	$08
		CMDD2
		DATA	$B1
		DO_LOOP
		DO_LOOP
		ARET
byte_9B30C:
		LOOP_START	$02
		LOOP_START	$08
		CMDD2
		DATA	$91
		DO_LOOP
		LOOP_START	$08
		DATA	$B1
		DO_LOOP
		LOOP_START	$08
		CMDD3
		DATA	$01
		DO_LOOP
		LOOP_START	$08
		DATA	$21
		DO_LOOP
		DO_LOOP
		ARET
_apu_mus12_D:
		CMDE0	$04
		CMDE9	$00
byte_9B326:
		DATA	$03,$23
		AJMP	byte_9B326
		DATA	$C0
		ASTOP
_apu_mus13:
		.BYTE	7
		.WORD	_apu_mus13_A
		.WORD	_apu_mus13_B
		.WORD	_apu_mus13_C
_apu_mus13_A:
		CMDE2	$00
		CMDE1	$03
		CMDE0	$0A
		CMDE9	$03
		CMDD9	$F6
byte_9B33E:
		AJSR	byte_9B361
		CMDD4
		DATA	$60,$C0,$20,$41,$00,$C0,$61,$60,$70,$90,$B0,$92
		AJSR	byte_9B361
		DATA	$B0,$C0,$90,$C0,$B1,$90,$B0,$C0,$B0
		CMDD5
		DATA	$15
		AJMP	byte_9B33E
		DATA	$C0
		ASTOP
byte_9B361:
		CMDD4
		DATA	$60,$C0,$20,$41,$00,$C0,$61,$60,$70,$90,$70,$60,$40,$20
		ARET
_apu_mus13_B:
		CMDE2	$00
		CMDE1	$03
		CMDE0	$0A
		CMDE9	$0A
		CMDD9	$F6
		DATA	$C0
		AJMP	byte_9B33E
		DATA	$C0
		ASTOP
_apu_mus13_C:
		CMDE2	$04
		CMDE1	$03
		CMDE0	$0A
		CMDE9	$01
		CMDD9	$02
byte_9B38B:
		AJSR	byte_9B3A5
		CMDE2	$03
		CMDD3
		DATA	$70,$71,$70,$C0,$70,$70,$70,$90,$91,$91,$70,$60,$40
		CMDE2	$04
		AJMP	byte_9B38B
		DATA	$C0
		ASTOP
byte_9B3A5:
		LOOP_START	$03
		CMDD3
		DATA	$20,$90,$C0,$01,$70,$C0,$20,$C0,$20,$91,$01,$70,$C0
		DO_LOOP
		ARET
_apu_mus14:
		DATA	$0F
		.WORD	_apu_mus14_A
		.WORD	_apu_mus14_B
		.WORD	_apu_mus14_C
		.WORD	_apu_mus14_D
_apu_mus14_A:
		CMDE2	$00
		CMDE1	$03
		CMDE0	$09
		CMDE9	$00
		CMDD9	$F2
byte_9B3CA:
		CMDEA	$05
		LOOP_START	$04
		CMDD2
		DATA	$90
		CMDD3
		DATA	$40,$90
		CMDD4
		DATA	$00,$40,$90,$80,$C0
		CMDD3
		DATA	$40
		CMDD2
		DATA	$41
		CMDD3
		DATA	$40
		DO_LOOP
		CMDEA	$FB
		CMDDA	$F4
		AJSR	byte_9B449
		AJSR	byte_9B44F
		AJSR	byte_9B449
		CMDD5
		DATA	$31,$40,$51,$40,$C5
		AJSR	byte_9B449
		AJSR	byte_9B44F
		AJSR	byte_9B449
		DATA	$31,$40,$51,$40,$C1,$40,$61,$80
		LOOP_START	$02
		LOOP_START	$02
		CMDD5
		DATA	$91
		CMDD4
		DATA	$90
		DO_LOOP
		LOOP_START	$02
		CMDD5
		DATA	$71
		CMDD4
		DATA	$90
		DO_LOOP
		CMDD5
		DATA	$61,$20,$41
		CMDD4
		DATA	$90,$C1,$90,$B0
		CMDD5
		DATA	$00
		CMDD4
		DATA	$90
		DO_LOOP
		CMDD5
		DATA	$00
		CMDD4
		DATA	$90
		CMDD5
		DATA	$00
		CMDD4
		DATA	$90
		CMDD5
		DATA	$10
		CMDD4
		DATA	$90
		CMDD5
		DATA	$20
		CMDD4
		DATA	$90
		CMDD5
		DATA	$20
		CMDD4
		DATA	$90
		CMDD5
		DATA	$30
		CMDD4
		DATA	$90
		CMDD5
		DATA	$40,$C0,$40,$40,$C0,$44,$C1
		CMDDA	$0C
		AJMP	byte_9B3CA
		DATA	$C0
		ASTOP
byte_9B449:
		CMDD4
		DATA	$94
		CMDD5
		DATA	$40,$C5
		ARET
byte_9B44F:
		CMDD5
		DATA	$31,$40,$21
		CMDD4
		DATA	$B0,$C5
		ARET
_apu_mus14_B:
		CMDE2	$00
		CMDE1	$03
		CMDE0	$09
		CMDE9	$08
		CMDD9	$F2
		DATA	$C1
		AJMP	byte_9B3CA
		DATA	$C0
		ASTOP
_apu_mus14_C:
		CMDE2	$04
		CMDE1	$03
		CMDE0	$09
		CMDE9	$00
		CMDD9	$0A
byte_9B471:
		LOOP_START	$04
		CMDD3
		DATA	$90
		CMDD4
		DATA	$40,$90
		CMDD5
		DATA	$00,$40,$90,$80,$C0
		CMDD4
		DATA	$40
		CMDD3
		DATA	$41
		CMDD4
		DATA	$40
		DO_LOOP
		CMDDA	$F4
		LOOP_START	$04
		CMDD3
		DATA	$90
		CMDD4
		DATA	$40,$90
		CMDD5
		DATA	$00,$C3
		CMDD4
		DATA	$40
		CMDD3
		DATA	$41
		CMDD4
		DATA	$40
		CMDD3
		DATA	$80
		CMDD4
		DATA	$40,$B0,$C1,$42
		CMDD3
		DATA	$40,$61,$80
		DO_LOOP
		LOOP_START	$02
		CMDD2
		DATA	$90,$C0,$90,$90,$C0,$90
		CMDD3
		DATA	$00,$C0,$00,$01,$C0
		CMDD3
		DATA	$24,$43,$C2
		DO_LOOP
		CMDD3
		LOOP_START	$04
		DATA	$21,$C0
		DO_LOOP
		DATA	$40,$C0,$40,$40,$C0,$42,$40,$61,$80
		CMDDA	$0C
		AJMP	byte_9B471
		DATA	$C0
		ASTOP
_apu_mus14_D:
		CMDE0	$09
		CMDE9	$00
byte_9B4D1:
		LOOP_START	$04
		DATA	$CB
		DO_LOOP
		LOOP_START	$07
		DATA	$02,$22,$C1,$20,$01,$20
		DO_LOOP
		DATA	$02,$22,$C1,$20,$21,$20
		LOOP_START	$02
		AJSR	byte_9B4FD
		AJSR	byte_9B502
		DO_LOOP
		AJSR	byte_9B4FD
		DATA	$21,$20,$01,$20,$C1,$20,$21,$20
		AJMP	byte_9B4D1
		DATA	$C0
		ASTOP
byte_9B4FD:
		DATA	$02,$22,$02,$22
		ARET
byte_9B502:
		.BYTE	$02,$22,$02,$20,$20,$20
		ARET
_apu_mus15:
		.BYTE	$0F
		.WORD	_apu_mus15_A
		.WORD	_apu_mus15_B
		.WORD	_apu_mus15_C
		.WORD	_apu_mus15_D
_apu_mus15_A:
		CMDE2	$00
		CMDE1	$03
		CMDE0	$09
		CMDE9	$03
		CMDD9	$F4
byte_9B51C:
		LOOP_START	$04
		DATA	$C0
		CMDD4
		DATA	$70,$C0,$60,$C0,$50,$C0,$60
		DO_LOOP
		AJSR	byte_9B539
		AJSR	byte_9B547
		AJSR	byte_9B539
		AJSR	byte_9B554
		AJMP	byte_9B51C
		DATA	$C0
		ASTOP
byte_9B539:
		CMDD4
		DATA	$70,$60,$70,$90,$C0,$A1,$71,$60,$70,$90,$C0,$A2
		ARET
byte_9B547:
		LOOP_START	$02
		DATA	$C0
		CMDD5
		DATA	$10,$10,$C0,$10,$10,$C0,$10
		DO_LOOP
		ARET
byte_9B554:
		LOOP_START	$02
		DATA	$C0
		CMDD5
		DATA	$60,$60,$C0,$60,$60,$C0,$60
		DO_LOOP
		ARET
_apu_mus15_B:
		CMDE2	$00
		CMDE1	$03
		CMDE0	$09
		CMDE9	$0A
		CMDD9	$F4
		DATA	$C1
		AJMP	byte_9B51C
		DATA	$C0
		ASTOP
_apu_mus15_C:
		CMDE2	$04
		CMDE1	$03
		CMDE0	$09
		CMDE9	$00
byte_9B579:
		CMDD3
		DATA	$00
		CMDD4
		DATA	$40
		CMDD2
		DATA	$B0
		CMDD4
		DATA	$30
		CMDD2
		DATA	$A0
		CMDD4
		DATA	$20
		CMDD2
		DATA	$B0
		CMDD4
		DATA	$30
		AJMP	byte_9B579
		DATA	$C0
		ASTOP
_apu_mus15_D:
		CMDE0	$09
		CMDE9	$00
byte_9B592:
		DATA	$01,$21
		AJMP	byte_9B592
		DATA	$C0
		ASTOP
_apu_mus16:
		.BYTE	$0F
		.WORD	_apu_mus16_A
		.WORD	_apu_mus16_B
		.WORD	_apu_mus16_C
		.WORD	_apu_mus16_D
_apu_mus16_A:
		CMDE2	$00
		CMDE1	$03
		CMDE0	$05
		CMDE9	$03
		CMDD9	$F4
byte_9B5AC:
		AJSR	byte_9B5C9
		AJSR	byte_9B5DB
		AJSR	byte_9B5C9
		AJSR	byte_9B5ED
		AJSR	byte_9B5FF
		AJSR	byte_9B5ED
		AJSR	byte_9B5FF
		AJSR	byte_9B5DB
		AJMP	byte_9B5AC
		DATA	$C0
		ASTOP
byte_9B5C9:
		CMDD4
		DATA	$71,$C1,$72,$60,$71,$C1,$72,$60,$71,$C1,$72,$60,$72,$60,$72,$80
		ARET
byte_9B5DB:
		CMDD4
		DATA	$91,$C1,$92,$80,$91,$C1,$92,$80,$91,$C1,$92,$80,$92,$80,$92,$80
		ARET
byte_9B5ED:
		CMDD4
		DATA	$91,$C1,$92,$80,$91,$C1,$92,$80,$91,$C1,$92,$80,$92,$80,$92,$A0
		ARET
byte_9B5FF:
		CMDD4
		DATA	$B1,$C1,$B2,$A0,$B1,$C1,$B2,$A0,$B1,$C1,$B2,$A0,$B2,$A0,$B2,$A0
		ARET
_apu_mus16_B:
		CMDE2	$00
		CMDE1	$03
		CMDE0	$05
		CMDE9	$09
		CMDD9	$F4
		DATA	$C0
		AJMP	byte_9B5AC
		DATA	$C0
		ASTOP
_apu_mus16_C:
		CMDE2	$04
		CMDE1	$03
		CMDE0	$05
		CMDE9	$02
		CMDD9	$F1
byte_9B62B:
		AJSR	byte_9B5C9
		AJSR	byte_9B5DB
		AJSR	byte_9B5C9
		AJSR	byte_9B5ED
		AJSR	byte_9B5FF
		AJSR	byte_9B5ED
		AJSR	byte_9B5FF
		AJSR	byte_9B5DB
		AJMP	byte_9B62B
		DATA	$C0
		ASTOP
_apu_mus16_D:
		CMDE0	$05
		CMDE9	$00
byte_9B64C:
		DATA	$03,$23
		AJMP	byte_9B64C
		DATA	$C0
		ASTOP
_apu_mus17:
		.BYTE	$0F
		.WORD	_apu_mus17_A
		.WORD	_apu_mus17_B
		.WORD	_apu_mus17_C
		.WORD	_apu_mus17_D
_apu_mus17_A:
		CMDE2	$00
		CMDE1	$03
		CMDE0	$06
		CMDE9	$03
		CMDD9	$F4
byte_9B666:
		CMDD5
		DATA	$21,$01,$31,$01,$C5,$01,$21,$01,$31,$01,$C5,$90,$B0,$B1,$01,$21
		DATA	$01,$C5,$01,$21,$01,$31,$01,$C1,$21,$31,$41,$51,$41,$71,$41,$C5
		.BYTE	$41,$51,$41,$71,$41,$C5
		CMDD6
		DATA	$00,$10,$11
		CMDD5
		DATA	$41,$71,$41,$C5,$41,$51,$41,$71,$41,$C1,$51,$41,$31
		AJMP	byte_9B666
		DATA	$C0
		ASTOP
_apu_mus17_B:
		CMDE2	$00
		CMDE1	$03
		CMDE0	$06
		CMDE9	$0A
		CMDD9	$F4
		DATA	$C1
		AJMP	byte_9B666
		DATA	$C0
		ASTOP
_apu_mus17_C:
		CMDE2	$04
		CMDE1	$03
		CMDE0	$06
		CMDE9	$01
byte_9B6BC:
		LOOP_START	$0C
		CMDD3
		DATA	$91,$C1
		DO_LOOP
		CMDD3
		DATA	$91,$C1,$91,$C1,$91,$A1,$B1
		CMDD4
		DATA	$01
		LOOP_START	$0C
		CMDD4
		DATA	$11,$C1
		DO_LOOP
		CMDD4
		DATA	$11,$C1,$11,$C1,$11,$01
		CMDD3
		DATA	$B1,$A1
		AJMP	byte_9B6BC
		DATA	$C0
		ASTOP
_apu_mus17_D:
		CMDE0	$06
		CMDE9	$05
byte_9B6E5:
		DATA	$31
		AJMP	byte_9B6E5
		DATA	$C0
		ASTOP
_apu_mus18:
		.BYTE	$0F
		.WORD	_apu_mus18_A
		.WORD	_apu_mus18_B
		.WORD	_apu_mus18_C
		.WORD	_apu_mus18_D
_apu_mus18_A:
		CMDE2	$00
		CMDE1	$03
		CMDE0	$05
		CMDE9	$03
		CMDD9	$F4
byte_9B6FE:
		LOOP_START	$04
		CMDD4
		DATA	$41,$51
		DO_LOOP
		LOOP_START	$04
		DATA	$71,$91
		DO_LOOP
		LOOP_START	$04
		CMDD4
		DATA	$B1
		CMDD5
		DATA	$01
		DO_LOOP
		LOOP_START	$04
		DATA	$21,$41
		DO_LOOP
		LOOP_START	$04
		CMDD4
		DATA	$51,$71
		DO_LOOP
		LOOP_START	$04
		DATA	$91,$A1
		DO_LOOP
		LOOP_START	$04
		CMDD5
		DATA	$01,$21
		DO_LOOP
		LOOP_START	$04
		DATA	$41,$51
		DO_LOOP
		AJMP	byte_9B6FE
		DATA	$C0
		ASTOP
_apu_mus18_B:
		CMDE2	$00
		CMDE1	$03
		CMDE0	$05
		CMDE9	$0A
		CMDD9	$F4
		DATA	$C1
		AJMP	byte_9B6FE
		DATA	$C0
		ASTOP
_apu_mus18_C:
		CMDE2	$04
		CMDE1	$03
		CMDE0	$05
		CMDE9	$01
		CMDD9	$0C
byte_9B74A:
		LOOP_START	$10
		CMDD2
		DATA	$91,$C1
		DO_LOOP
		LOOP_START	$10
		DATA	$A1,$C1
		DO_LOOP
		AJMP	byte_9B74A
		DATA	$C0
		ASTOP
_apu_mus18_D:
		CMDE0	$05
		CMDE9	$06
byte_9B75E:
		DATA	$30
		AJMP	byte_9B75E
		DATA	$C0
		ASTOP
_apu_mus19:
		.BYTE	$0F
		.WORD	_apu_mus19_A
		.WORD	_apu_mus19_B
		.WORD	_apu_mus19_C
		.WORD	_apu_mus19_D
_apu_mus19_A:
		CMDE2	$00
		CMDE1	$03
		CMDE0	$05
		CMDE9	$03
		CMDD9	$F0
byte_9B777:
		LOOP_START	$03
		CMDD4
		DATA	$21,$31,$41
		CMDD5
		DATA	$03
		CMDD4
		DATA	$41,$C1,$53,$51,$91
		CMDD5
		DATA	$01,$41,$C1,$21,$C1
		DO_LOOP
		LOOP_START	$02
		CMDD5
		DATA	$41,$41,$21,$C1,$41,$C1,$21,$41,$C1,$41,$21,$C1,$41,$C1,$21,$C1
		CMDDA	$0C
		DO_LOOP
		CMDDA	$E8
		AJMP	byte_9B777
		DATA	$C0
		ASTOP
_apu_mus19_B:
		CMDE2	$00
		CMDE1	$03
		CMDE0	$05
		CMDE9	$0A
		CMDD9	$F0
		DATA	$C1
		AJMP	byte_9B777
		DATA	$C0
		ASTOP
_apu_mus19_C:
		CMDE2	$04
		CMDE1	$03
		CMDE0	$05
		CMDE9	$01
		CMDD9	$08
byte_9B7C3:
		LOOP_START	$03
		CMDD3
		DATA	$01,$C3
		CMDD2
		DATA	$97
		CMDD3
		DATA	$21,$C5,$21,$71,$C1,$71,$C1
		DO_LOOP
		LOOP_START	$02
		CMDD3
		DATA	$7F
		CMDE8
		CMDD3
		DATA	$7F
		DO_LOOP
		AJMP	byte_9B7C3
		DATA	$C0
		ASTOP
_apu_mus19_D:
		CMDE0	$05
		CMDE9	$02
byte_9B7E4:
		DATA	$03,$23,$03,$21,$03,$01,$23,$23,$23
		AJMP	byte_9B7E4
		DATA	$C0
		ASTOP
_apu_mus1A:
		.BYTE	$0F
		.WORD	_apu_mus1A_A
		.WORD	_apu_mus1A_B
		.WORD	_apu_mus1A_C
		.WORD	_apu_mus1A_D
_apu_mus1A_A:
		CMDE2	$01
		CMDE1	$03
		CMDE0	$07
		CMDE9	$03
		CMDD9	$F4
byte_9B805:
		LOOP_START	$03
		AJSR	byte_9B88E
		AJSR	byte_9B899
		AJSR	byte_9B88E
		CMDD4
		DATA	$51,$91
		CMDD5
		DATA	$01,$21,$40,$21,$02,$21
		AJSR	byte_9B88E
		AJSR	byte_9B899
		AJSR	byte_9B88E
		CMDD4
		DATA	$51,$91
		CMDD5
		DATA	$01,$21,$41,$50,$72,$40,$C0
		AJSR	byte_9B8A3
		DATA	$C1
		CMDD4
		DATA	$71,$51,$41,$50,$71,$92,$C1
		AJSR	byte_9B8A3
		LOOP_START	$05
		DATA	$70,$C0
		CMDDA	$01
		DO_LOOP
		CMDDA	$FB
		DATA	$C1
		CMDD5
		DATA	$72,$C0,$41,$50,$70,$C1,$40,$C0,$01
		CMDD4
		DATA	$70,$C0,$90,$C0
		CMDD5
		DATA	$00,$C0,$50,$40,$50,$01,$50,$40,$50,$03,$23,$41,$00
		CMDD4
		DATA	$76,$71,$91
		CMDD5
		DATA	$01,$51,$20
		CMDD4
		DATA	$96,$91,$B1
		CMDD5
		DATA	$21
		DO_LOOP
		DATA	$0B
		CMDE8
		CMDE0	$01
		DATA	$00
		CMDE0	$03
		DATA	$00,$20,$40,$50,$70,$90,$B0
		CMDD6
		DATA	$01
		CMDE8
		CMDE0	$07
		DATA	$03
		CMDD5
		DATA	$00,$01,$00,$03,$C0
		ASTOP
byte_9B88E:
		DATA	$C1
		CMDD4
		DATA	$70,$C0,$50,$41,$72,$51,$41,$71
		ARET
byte_9B899:
		CMDD4
		DATA	$51,$91
		CMDD5
		DATA	$01,$21,$42,$20,$C3
		ARET
byte_9B8A3:
		DATA	$C1
		CMDD5
		DATA	$50,$C0,$40,$50,$C0,$02
		CMDD4
		DATA	$91,$51,$91
		ARET
_apu_mus1A_B:
		CMDE2	$01
		CMDE1	$03
		CMDE0	$07
		CMDE9	$0A
		CMDD9	$F4
		CMDE0	$02
		DATA	$C4
		CMDE0	$07
		AJMP	byte_9B805
		DATA	$C0
		ASTOP
_apu_mus1A_C:
		CMDE2	$03
		CMDE1	$03
		CMDE0	$07
		CMDE9	$02
		LOOP_START	$03
		AJSR	byte_9B945
		AJSR	byte_9B94D
		AJSR	byte_9B945
		CMDD3
		DATA	$51
		CMDD4
		DATA	$51
		CMDD3
		DATA	$51
		CMDD4
		DATA	$51
		CMDD3
		DATA	$71
		CMDD4
		DATA	$70
		CMDD3
		DATA	$71,$70,$90,$B0
		AJSR	byte_9B945
		AJSR	byte_9B94D
		AJSR	byte_9B945
		CMDD3
		DATA	$51
		CMDD4
		DATA	$51
		CMDD3
		DATA	$51
		CMDD4
		DATA	$51
		CMDD3
		DATA	$71
		CMDD4
		DATA	$70
		CMDD3
		DATA	$71,$90,$B1
		AJSR	byte_9B95F
		CMDD3
		DATA	$70,$70,$C3,$73,$51,$50,$50,$C1
		AJSR	byte_9B95F
		LOOP_START	$05
		DATA	$70,$C0
		CMDDA	$01
		DO_LOOP
		CMDDA	$FB
		DATA	$C1,$72,$C0
		LOOP_START	$04
		CMDD4
		DATA	$00,$C0
		DO_LOOP
		LOOP_START	$04
		CMDD3
		DATA	$A0,$C0
		DO_LOOP
		LOOP_START	$04
		DATA	$90,$C0
		DO_LOOP
		LOOP_START	$04
		DATA	$80,$C0
		DO_LOOP
		AJSR	byte_9B969
		AJSR	byte_9B969
		DO_LOOP
		AJSR	byte_9B945
		CMDD4
		DATA	$03
		CMDD3
		DATA	$00,$01,$00,$03,$C0
		ASTOP
byte_9B945:
		LOOP_START	$04
		CMDD3
		DATA	$01
		CMDD4
		DATA	$01
		DO_LOOP
		ARET
byte_9B94D:
		CMDD3
		DATA	$51
		CMDD4
		DATA	$51
		CMDD3
		DATA	$51
		CMDD4
		DATA	$51
		CMDD3
		DATA	$71
		CMDD4
		DATA	$70
		CMDD3
		DATA	$71,$70,$50,$40
		ARET
byte_9B95F:
		CMDD3
		DATA	$A0,$A0,$C3,$A3,$91,$90,$90,$C1
		ARET
byte_9B969:
		LOOP_START	$04
		CMDD3
		DATA	$71
		CMDD4
		DATA	$71
		DO_LOOP
		ARET
_apu_mus1A_D:
		CMDE0	$07
		CMDE9	$02
		LOOP_START	$30
		AJSR	byte_9B986
		DO_LOOP
		AJSR	byte_9B986
		CMDD2
		DATA	$03,$20,$21,$20,$27,$C0
		ASTOP
byte_9B986:
		CMDD2
		DATA	$03,$23,$03,$23
		ARET
_apu_mus1B:
		.BYTE	$07
		.WORD	_apu_mus1B_A
		.WORD	_apu_mus1B_B
		.WORD	_apu_mus1B_C
_apu_mus1B_A:
		CMDE2	$04
		CMDE1	$03
		CMDE0	$04
		CMDE9	$00
		CMDD9	$F4
		CMDE0	$03
		CMDD3
		DATA	$00,$20,$40,$50,$70,$90,$B0
		CMDD4
		DATA	$00,$20,$40,$50,$73,$C9,$00,$20,$40,$50,$70,$90,$B0
		CMDD5
		DATA	$00,$20,$40,$50,$70,$90,$B0,$B1
		CMDE0	$04
		CMDD6
		DATA	$01,$C0,$01,$C1,$00
		CMDD5
		DATA	$A1,$C0,$A1,$C1,$A0,$91,$C0,$91,$C1,$90,$81,$C0,$81,$C1,$80,$C2
		DATA	$73,$C0,$51,$C1,$42,$08
		CMDD6
		DATA	$01,$C0
		ASTOP
_apu_mus1B_B:
		CMDE2	$04
		CMDE1	$03
		CMDE0	$04
		CMDE9	$00
		CMDD9	$F4
		CMDE0	$03
		DATA	$CA
		CMDD3
		DATA	$70,$90,$B0
		CMDD4
		DATA	$00,$20,$40,$50,$70,$90,$B0
		CMDD5
		DATA	$00,$20,$40,$50,$73,$CB
		CMDE0	$04
		DATA	$71,$C0,$71,$C1,$70,$71,$C0,$71,$C1,$70,$51,$C0,$51,$C1,$50,$51
		DATA	$C0,$51,$C1,$50,$C2,$43,$C0,$21,$C1
		CMDD4
		DATA	$72,$78
		CMDD5
		DATA	$41,$C0
		ASTOP
_apu_mus1B_C:
		CMDE2	$04
		CMDE1	$03
		CMDE0	$04
		CMDE9	$00
		CMDE0	$03
		CMDD3
		DATA	$7F
		CMDE8
		DATA	$78
		CMDE8
		DATA	$7F
		CMDE0	$04
		DATA	$01,$C1,$01,$C1,$41,$C1,$41,$C1,$51,$C1,$51,$C1,$61,$C1,$61,$C1
		CMDD4
		DATA	$73,$C2
		CMDD3
		DATA	$70,$91,$C1,$B2
		CMDD4
		DATA	$07,$C0,$01,$C0
		ASTOP
_apu_mus1C:
		.BYTE	$0F
		.WORD	_apu_mus1C_A
		.WORD	_apu_mus1C_B
		.WORD	_apu_mus1C_C
		.WORD	_apu_mus1C_D
_apu_mus1C_A:
		CMDE2	$00
		CMDE1	$02
		CMDE0	$05
		CMDE9	$00
		CMDD9	$F4
byte_9BA66:
		AJSR	byte_9BAD2
		DATA	$C1
		CMDD5
		DATA	$31,$23,$03,$20,$C0
		CMDD4
		DATA	$91
		CMDE8
		DATA	$9F,$C1,$90,$C0,$91,$C1,$91,$C1,$A0,$C0
		CMDD5
		DATA	$01
		AJSR	byte_9BAD2
		DATA	$C1,$31,$23,$03,$20,$C0,$51
		CMDE8
		DATA	$5F,$C1,$50,$C0,$51,$C1,$51,$C1,$50,$C0,$51,$C1,$70,$C0,$52,$C0
		DATA	$50,$C0,$73,$50,$C0,$82,$C0,$82,$C0,$72,$C0,$52,$C0,$C1,$01,$21
		.BYTE	$01,$21,$31,$21,$01,$41,$C1,$41,$27,$C1,$C1,$21,$51,$21,$51,$91
		.BYTE	$C1,$71,$C1,$51,$C1,$71,$51,$C1,$41,$C1,$51,$C1,$51,$C3,$51,$C1
		.BYTE	$51,$51,$CD
		AJMP	byte_9BA66
		DATA	$C0
		ASTOP
byte_9BAD2:
		DATA	$C1
		CMDD5
		DATA	$30,$C0,$23,$02,$C0,$20,$C0,$31
		ARET
_apu_mus1C_B:
		CMDE2	$00
		CMDE1	$02
		CMDE0	$05
		CMDE9	$01
		CMDD9	$F4
byte_9BAE7:
		AJSR	byte_9BB48
		DATA	$C1
		CMDD5
		DATA	$01
		CMDD4
		DATA	$A3,$93,$90,$C0,$51
		CMDE8
		DATA	$5F,$C1,$50,$C0,$51,$C1,$51,$C1,$70,$C0,$91
		AJSR	byte_9BB48
		DATA	$C1
		CMDD5
		DATA	$01
		CMDD4
		DATA	$A3,$93,$A0,$C0
		CMDD5
		DATA	$01
		CMDE8
		DATA	$0F,$C1,$00,$C0,$01,$C1,$01,$C1,$00,$C0,$01,$C1,$20,$C0,$22,$C0
		DATA	$20,$C0,$23,$20,$C0
		LOOP_START	$04
		DATA	$22,$C0
		DO_LOOP
		CMDD4
		DATA	$9F
		CMDD5
		DATA	$01,$C1,$01,$07,$C1
		CMDD4
		DATA	$7F,$C1
		CMDD5
		DATA	$01,$C1,$01,$01,$C1,$01,$C1,$01,$C1,$01,$C3,$01,$C1,$01,$01,$CD
		AJMP	byte_9BAE7
		DATA	$C0
		ASTOP
byte_9BB48:
		DATA	$C1
		CMDD5
		DATA	$00,$C0
		CMDD4
		DATA	$A3,$92,$C0,$A0,$C0
		CMDD5
		DATA	$01
		ARET
_apu_mus1C_C:
		CMDE2	$04
		CMDE1	$03
		CMDE0	$05
		CMDE9	$00
byte_9BB5D:
		LOOP_START	$08
		CMDD3
		DATA	$51
		CMDD4
		DATA	$51
		CMDD3
		DATA	$21
		CMDD4
		DATA	$21
		CMDD3
		DATA	$31
		CMDD4
		DATA	$31
		CMDD3
		DATA	$41
		CMDD4
		DATA	$41
		DO_LOOP
		CMDDA	$F4
		AJSR	byte_9BBA9
		LOOP_START	$04
		CMDD3
		DATA	$B1
		CMDD4
		DATA	$B1
		DO_LOOP
		LOOP_START	$04
		CMDD3
		DATA	$91
		CMDD4
		DATA	$91
		DO_LOOP
		LOOP_START	$04
		CMDD4
		DATA	$21
		CMDD5
		DATA	$21
		DO_LOOP
		AJSR	byte_9BBA9
		LOOP_START	$04
		CMDD4
		DATA	$01
		CMDD5
		DATA	$01
		DO_LOOP
		CMDDA	$0C
		LOOP_START	$04
		CMDD3
		DATA	$51
		CMDD4
		DATA	$51
		DO_LOOP
		CMDD3
		DATA	$51,$C7
		CMDD4
		DATA	$01,$21,$41
		AJMP	byte_9BB5D
		DATA	$C0
		ASTOP
byte_9BBA9:
		LOOP_START	$04
		CMDD3
		DATA	$A1
		CMDD4
		DATA	$A1
		DO_LOOP
		ARET
_apu_mus1C_D:
		CMDE0	$05
		CMDE9	$00
byte_9BBB5:
		DATA	$03,$23
		AJMP	byte_9BBB5
		DATA	$C0
		ASTOP
_apu_mus1D:
		.BYTE	7
		.WORD	_apu_mus1D_A
		.WORD	_apu_mus1D_B
		.WORD	_apu_mus1D_C
_apu_mus1D_A:
		CMDE2	$00
		CMDE1	$03
		CMDE0	$06
		CMDE9	$00
		CMDD9	$F4
byte_9BBCD:
		LOOP_START	$08
		CMDD5
		DATA	$00
		CMDD6
		DATA	$00
		CMDDA	$FF
		DO_LOOP
		CMDDA	$08
		CMDD5
		DATA	$41,$C0,$41,$C0,$41,$51,$C0
		ASTOP
_apu_mus1D_B:
		CMDE2	$00
		CMDE1	$03
		CMDE0	$06
		CMDE9	$08
		CMDD9	$F4
		DATA	$C0
		AJMP	byte_9BBCD
		DATA	$C0
		ASTOP
_apu_mus1D_C:
		CMDE2	$04
		CMDE1	$03
		CMDE0	$06
		CMDE9	$00
		CMDD4
		LOOP_START	$09
		DATA	$01
		CMDDA	$FF
		DO_LOOP
		CMDDA	$09
		CMDD3
		DATA	$C0,$41,$C0,$41,$50,$C0
		CMDD4
		DATA	$50
		CMDD3
		DATA	$51,$C0
		ASTOP
_apu_mus1E:
		BYTE	$0F
		.WORD	_apu_mus1E_A
		.WORD	_apu_mus1E_B
		.WORD	_apu_mus1E_C
		.WORD	_apu_mus1E_D
_apu_mus1E_A:
		CMDE2	$00
		CMDE1	$03
		CMDE0	$04
		CMDE9	$00
		CMDD9	$F4
byte_9BC22:
		LOOP_START	$04
		CMDD4
		DATA	$91,$80,$70,$60,$C0,$51,$C1,$21,$C1,$21,$51,$21,$71,$21,$91,$81
		DATA	$71,$51
		DO_LOOP
		LOOP_START	$04
		CMDD5
		DATA	$21,$10,$00
		CMDD4
		DATA	$B0,$C0,$A1,$C1,$71,$C1,$71,$A1,$71
		CMDD5
		DATA	$01
		CMDD4
		DATA	$71
		CMDD5
		DATA	$21,$11,$01
		CMDD4
		DATA	$A1
		DO_LOOP
		AJMP	byte_9BC22
		DATA	$C0
		ASTOP
_apu_mus1E_B:
		CMDE2	$00
		CMDE1	$03
		CMDE0	$04
		CMDE9	$08
		CMDD9	$F4
		DATA	$C1
		AJMP	byte_9BC22
		DATA	$C0
		ASTOP
_apu_mus1E_C:
		CMDE2	$03
		CMDE1	$03
		CMDE0	$04
		CMDE9	$00
byte_9BC70:
		LOOP_START	$02
		CMDD3
		DATA	$21,$21,$51,$71,$21,$21,$51,$71,$21,$21,$71,$91,$51,$71,$51,$71
		CMDD3
		DATA	$21,$21,$51,$71,$21,$21,$51,$71,$21,$21
		CMDD4
		DATA	$01,$21
		CMDD3
		DATA	$A1
		CMDD4
		DATA	$01
		CMDD3
		DATA	$71,$91
		DO_LOOP
		LOOP_START	$02
		CMDD3
		DATA	$71,$71,$A1
		CMDD4
		DATA	$01
		CMDD3
		DATA	$71,$71,$A1
		CMDD4
		DATA	$01
		CMDD3
		DATA	$71,$71
		CMDD4
		DATA	$01,$21
		CMDD3
		DATA	$A1
		CMDD4
		DATA	$01
		CMDD3
		DATA	$A1
		CMDD4
		DATA	$01
		CMDD3
		DATA	$71,$71,$A1
		CMDD4
		DATA	$01
		CMDD3
		DATA	$71,$71,$A1
		CMDD4
		DATA	$01
		CMDD3
		DATA	$71,$71
		CMDD4
		DATA	$51,$71,$01,$21,$01,$21
		DO_LOOP
		AJMP	byte_9BC70
		DATA	$C0
		ASTOP
_apu_mus1E_D:
		CMDE0	$04
		CMDE9	$00
byte_9BCD5:
		DATA	$03,$23,$03,$23,$03,$21,$23,$23,$21
		AJMP	byte_9BCD5
		DATA	$C0
		ASTOP
_apu_mus1F:
		.BYTE	$0F
		.WORD	_apu_mus1F_A
		.WORD	_apu_mus1F_B
		.WORD	_apu_mus1F_C
		.WORD	_apu_mus1F_D
_apu_mus1F_A:
		CMDE2	$04
		CMDE1	$03
		CMDE0	$04
		CMDE9	$02
		CMDD9	$EA
byte_9BCF6:
		AJSR	byte_9BD35
		AJSR	byte_9BD46
		AJSR	byte_9BD35
		AJSR	byte_9BD46
		AJSR	byte_9BD55
		DATA	$C1
		CMDD4
		DATA	$51,$81,$51,$A1,$B1,$A1,$81
		CMDD5
		DATA	$57
		CMDE8
		DATA	$50,$30,$10,$00
		CMDD4
		DATA	$A0,$80,$60,$50
		AJSR	byte_9BD55
		DATA	$C1,$51,$81,$51,$A1,$B1,$A1,$81,$A1,$81,$51
		CMDD5
		DATA	$01
		CMDD4
		DATA	$A1,$81
		CMDD5
		DATA	$31,$51
		AJMP	byte_9BCF6
		DATA	$C0
		ASTOP
byte_9BD35:
		DATA	$C3
		CMDD5
		DATA	$01,$C1,$00,$C0,$01,$C1,$01,$C1,$01,$C1,$01,$33,$21,$01
		ARET
byte_9BD46:
		DATA	$C1
		CMDD5
		DATA	$00,$C0,$01,$C1,$00,$C0,$01,$C1,$01,$55,$35,$23
		ARET
byte_9BD55:
		DATA	$C1
		CMDD4
		DATA	$51,$81,$51,$81,$A1,$C1,$A1,$C1,$B5,$A1,$C1,$81,$C1
		ARET
_apu_mus1F_B:
		CMDE2	$04
		CMDE1	$03
		CMDE0	$04
		CMDE9	$09
		CMDD9	$EA
		DATA	$C1
		AJMP	byte_9BCF6
		DATA	$C0
		ASTOP
_apu_mus1F_C:
		CMDE2	$03
		CMDE1	$03
		CMDE0	$04
		CMDE9	$00
		CMDD9	$02
byte_9BD7F:
		AJSR	byte_9BDB8
		AJSR	byte_9BDB8
		AJSR	byte_9BDB8
		AJSR	byte_9BDB8
		AJSR	byte_9BDB8
		AJSR	byte_9BDB8
		AJSR	byte_9BDB8
		AJSR	byte_9BDB8
		CMDDA	$F4
		AJSR	byte_9BDC4
		AJSR	byte_9BDC4
		AJSR	byte_9BDC4
		AJSR	byte_9BDC4
		AJSR	byte_9BDC4
		AJSR	byte_9BDC4
		AJSR	byte_9BDC4
		AJSR	byte_9BDC4
		CMDDA	$0C
		AJMP	byte_9BD7F
		DATA	$C0
		ASTOP
byte_9BDB8:
		CMDD3
		DATA	$51,$51,$81,$51,$B1
		CMDD4
		DATA	$01
		CMDD3
		DATA	$A1,$81
		ARET
byte_9BDC4:
		CMDD3
		DATA	$A1,$A1
		CMDD4
		DATA	$11
		CMDD3
		DATA	$A1
		CMDD4
		DATA	$41,$51,$31,$11
		ARET
_apu_mus1F_D:
		CMDE0	$04
		CMDE9	$00
byte_9BDD5:
		DATA	$03,$23
		AJMP	byte_9BDD5
		DATA	$C0
		ASTOP
_apu_mus20:
		.BYTE	$0F
		.WORD	_apu_mus20_A
		.WORD	_apu_mus20_B
		.WORD	_apu_mus20_C
		.WORD	_apu_mus20_D
_apu_mus20_A:
		CMDE2	$00
		CMDE1	$03
		CMDE0	$03
		CMDE9	$00
		CMDD9	$F4
		DATA	$C3
		CMDD4
		DATA	$41
		CMDD5
		DATA	$01
		CMDD4
		DATA	$B1
		CMDD5
		DATA	$01
		CMDD4
		DATA	$71,$51,$C1,$41,$91,$C1,$91,$C1,$B0,$C0,$B2,$C0
		CMDD5
		DATA	$25,$01,$C3
		CMDD6
		DATA	$23,$01,$C0
		ASTOP
_apu_mus20_B:
		CMDE2	$00
		CMDE1	$03
		CMDE0	$03
		CMDE9	$00
		CMDD9	$F4
		DATA	$C3
		CMDD4
		DATA	$00,$C0,$00,$C0,$00,$C0,$00,$C0,$01,$C1,$00,$C0,$01,$50,$C0,$50
		DATA	$C0,$50,$C0,$51,$70,$C0,$71,$C1,$74,$C0,$71,$C3
		CMDD5
		DATA	$72,$C0,$71,$C0
		ASTOP
_apu_mus20_C:
		CMDE2	$04
		CMDE1	$03
		CMDE0	$03
		CMDE9	$00
		CMDD3
		DATA	$70,$50,$40,$20,$03,$C1,$01,$C3,$01,$C1,$51,$C1,$51,$C5,$77,$03
		DATA	$C1,$02,$C0,$01,$C0
		ASTOP
_apu_mus20_D:
		CMDE0	$03
		CMDE9	$00
		DATA	$C3,$03,$23,$01,$01,$21,$01,$23,$23,$01,$01,$21,$25,$25,$20,$20
		DATA	$20,$20,$23,$C0
		ASTOP
_apu_mus21:
		.BYTE	$0F
		.WORD	_apu_mus21_A
		.WORD	_apu_mus21_B
		.WORD	_apu_mus21_C
		.WORD	_apu_mus21_D
_apu_mus21_A:
		CMDE2	$00
		CMDE1	$03
		CMDE0	$03
		CMDE9	$00
		CMDD9	$F4
		DATA	$C3
		CMDD4
		DATA	$B1
		CMDD5
		DATA	$01,$C1,$11,$C1,$21,$C1,$31,$C1,$41,$C1,$51
		LOOP_START	$08
		CMDD5
		DATA	$70
		CMDD4
		DATA	$B0
		DO_LOOP
		DATA	$C0
		ASTOP
_apu_mus21_B:
		CMDE2	$00
		CMDE1	$03
		CMDE0	$03
		CMDE9	$00
		CMDD9	$F4
		DATA	$C3
		CMDD4
		DATA	$71,$81,$C1,$91,$C1,$A1,$C1,$B1,$C1
		CMDD5
		DATA	$01,$C1,$11
		LOOP_START	$08
		CMDD5
		DATA	$20
		CMDD4
		DATA	$70
		DO_LOOP
		DATA	$C0
		ASTOP
_apu_mus21_C:
		CMDE2	$04
		CMDE1	$03
		CMDE0	$03
		CMDE9	$00
		CMDD3
		DATA	$70,$50,$40,$20,$01,$11,$C1,$21,$C1,$31,$C1,$41,$C1,$51,$C1,$61
		DATA	$7F,$C0
		ASTOP
_apu_mus21_D:
		CMDE0	$03
		CMDE9	$00
		DATA	$C3,$21,$03,$03,$23,$03,$03,$21
		LOOP_START	$10
		DATA	$30
		DO_LOOP
		DATA	$C0
		ASTOP

		BANK_END 6,$C000
