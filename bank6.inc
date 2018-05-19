
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
		STX		byte_F7
loc_98013:
		TYA
		PHA
		LDX		byte_F7
		LDA		_apu_active_chnls_flags
		AND		_apu_set_bitmasks,X
		BEQ		loc_98027
		JSR		_apu_playA
		JSR		_apu_playB
		JSR		_apu_playC
loc_98027:
		INC		byte_F7
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
		LDA		byte_7EE
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
		LDA		byte_7EF
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
		SBC		byte_FB
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
		SBC		byte_FB
		BCS		loc_981A7
loc_981A5:
		LDA		#$00
loc_981A7:
		ORA		_apu_vars12+3
		ORA		#$10
		STA		_APU_PULSE2_ENV
		LDA		byte_7ED
		LSR
		TAY
		LDA		byte_7EC
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
		LDA		byte_FB
		CMP		#$10
		BCS		loc_981E0
		INC		byte_FA
		LDA		byte_FA
		CMP		#$04
		BCC		locret_981E4
		LDA		#$00
		STA		byte_FA
		INC		byte_FB
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
		INC		byte_FA
		LDA		byte_FA
		CMP		#$04
		BCC		nullsub2
		LDA		#$00
		STA		byte_FA
		LDA		byte_FB
		BNE		loc_981FD
		STA		_apu_snd0_allow_flag
		BEQ		nullsub2
loc_981FD:
		DEC		byte_FB

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
		STY		byte_FB
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
		STA		byte_7EA
		LDA		#>[byte_992B5]
		STA		byte_7EB
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
		STA		byte_FD
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
		STA		byte_FB
		STA		byte_7EE
		STA		byte_7EF
		LDX		#$0C
loc_98358:
		TXA
		STA		byte_7F0,X
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
		LDY		byte_FD
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
		STA		byte_FD
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
		.WORD	_apu_cmdE3	; dummy
		.WORD	_apu_cmdE4	; dummy
		.WORD	_apu_cmdE5	; dummy
		.WORD	0
		.WORD	0
		.WORD	_apu_cmdE8
		.WORD	_apu_cmdE9
		.WORD	_apu_cmdEA
		.WORD	_apu_cmdEB
		.WORD	_apu_cmdEC
		.WORD	_apu_cmdED	; arg byte
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
		STA		byte_FD
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
		LDA		byte_7F0,X
		PHA
		LDA		byte_7F0,Y
		STA		byte_7F0,X
		PLA
		STA		byte_7F0,Y
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
		LDA		byte_7F0,Y
		ASL
		TAY
		LDA		off_99283,Y
		STA		byte_7EA
		LDA		off_99283+1,Y
		STA		byte_7EB
		RTS

; =============== S U B R O U T I N E =======================================
_apu_playB:
		LDX		byte_F7
		CPX		#$03
		BEQ		loc_98677
locret_98676:
		RTS
loc_98677:
		LDA		_apu_varsD,X
		BMI		locret_98676
		LDA		#$00
		STA		byte_7EE
		STA		byte_7EF
		LDA		byte_7EA
		STA		_apu_cur_pc
		LDA		byte_7EB
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
		INC		byte_7EF
		TYA
		AND		#$1F
		STA		_apu_vars6,X
		LDA		#$00
		STA		_apu_vars7,X
		INC		_apu_varsE,X
		JMP		loc_986F0
loc_986DE:
		INC		byte_7EE
		TYA
		AND		#$0F
		STA		byte_7ED
		JSR		_apu_stream_get_byte
		STA		byte_7EC
		INC		_apu_varsE+1
loc_986F0:
		LDA		_apu_cur_pc
		STA		byte_7EA
		LDA		_apu_cur_pc+1
		STA		byte_7EB
		RTS
loc_986FB:
		LDA		#$00
		STA		byte_7EE
		STA		byte_7EF
		STA		_apu_vars7,X
		STA		_apu_vars6,X
		INC		byte_7EF
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
		.BYTE	$E2,$04	; CMDE2
		.BYTE	$E1,$00	; CMDE1
		.BYTE	$E0,$01	; CMDE0
		.BYTE	$E9,$00	; CMDE9
		.BYTE	$E1,$02	; CMDE1
		.BYTE	$F0,$03	; LOOP_START
		.BYTE	$D5	; CMDD5
		.BYTE	$00	; DATA
		.BYTE	$DA,$FF	; CMDDA
		.BYTE	$EA,$04	; CMDEA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$DA,$03	; CMDDA
		.BYTE	$EA,$F4	; CMDEA
		.BYTE	$C0	; DATA
		.BYTE	$DB,$FD	; CMDDB
		.BYTE	$D6	; CMDD6
		.BYTE	$E9,$00	; CMDE9
		.BYTE	$F0,$06	; LOOP_START
		.BYTE	$E1,$01	; CMDE1
		.BYTE	$D9,$F4	; CMDD9
		.BYTE	$B7	; DATA
		.BYTE	$EA,$03	; CMDEA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus23:
		.BYTE	$10
		.WORD	_apu_mus23_A
_apu_mus23_A:
		.BYTE	$E2,$04	; CMDE2
		.BYTE	$E1,$02	; CMDE1
		.BYTE	$E0,$01	; CMDE0
		.BYTE	$D3	; CMDD3
		.BYTE	$F0,$08	; LOOP_START
		.BYTE	$EB,$B3	; CMDEB
		.BYTE	$71,$41	; DATA
		.BYTE	$DA,$04	; CMDDA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus24:
		.BYTE	$10
		.WORD	_apu_mus24_A
_apu_mus24_A:
		.BYTE	$E2,$04	; CMDE2
		.BYTE	$E1,$00	; CMDE1
		.BYTE	$E0,$01	; CMDE0
		.BYTE	$E9,$00	; CMDE9
		.BYTE	$D3	; CMDD3
		.BYTE	$EB,$93	; CMDEB
		.BYTE	$40,$50,$40,$50	; DATA
		.BYTE	$EB,$9B	; CMDEB
		.BYTE	$00,$10,$00,$10	; DATA
		.BYTE	$EC,$D4	; CMDEC
		.BYTE	$DB,$08	; CMDDB
		.BYTE	$F0,$10	; LOOP_START
		.BYTE	$70	; DATA
		.BYTE	$DA,$FF	; CMDDA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus25:
		.BYTE	$30
		.WORD	_apu_mus25_A
		.WORD	_apu_mus25_B
_apu_mus25_A:
		.BYTE	$E2,$04	; CMDE2
		.BYTE	$E1,$00	; CMDE1
		.BYTE	$E0,$01	; CMDE0
		.BYTE	$E9,$00	; CMDE9
		.BYTE	$DA,$06	; CMDDA
		.BYTE	$D9,$FB	; CMDD9
		.BYTE	$D3	; CMDD3
		.BYTE	$EB,$93	; CMDEB
		.BYTE	$41	; DATA
		.BYTE	$D9,$F8	; CMDD9
		.BYTE	$EB,$9B	; CMDEB
		.BYTE	$00	; DATA
		.BYTE	$D9,$F8	; CMDD9
		.BYTE	$D2	; CMDD2
		.BYTE	$F0,$02	; LOOP_START
		.BYTE	$EB,$93	; CMDEB
		.BYTE	$90	; DATA
		.BYTE	$EB,$9B	; CMDEB
		.BYTE	$00	; DATA
		.BYTE	$E9,$00	; CMDE9
		.BYTE	$F1	; DO_LOOP
		.BYTE	$EB,$95	; CMDEB
		.BYTE	$97,$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus25_B:
		.BYTE	$E2,$04	; CMDE2
		.BYTE	$E1,$00	; CMDE1
		.BYTE	$E0,$01	; CMDE0
		.BYTE	$E9,$00	; CMDE9
		.BYTE	$B2,$C1,$A2	; DATA
		.BYTE	$E9,$02	; CMDE9
		.BYTE	$92,$82	; DATA
		.BYTE	$E9,$05	; CMDE9
		.BYTE	$72,$62,$52,$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus26:
		.BYTE	$10
		.WORD	_apu_mus26_A
_apu_mus26_A:
		.BYTE	$E2,$04	; CMDE2
		.BYTE	$E1,$02	; CMDE1
		.BYTE	$E0,$01	; CMDE0
		.BYTE	$D5	; CMDD5
		.BYTE	$F0,$04	; LOOP_START
		.BYTE	$EB,$93	; CMDEB
		.BYTE	$73,$53,$43,$23,$43,$53 ;	DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus27:
		.BYTE	$20
		.WORD	_apu_mus27_A
_apu_mus27_A:
		.BYTE	$E2,$04	; CMDE2
		.BYTE	$E1,$02	; CMDE1
		.BYTE	$E0,$02	; CMDE0
		.BYTE	$E9,$00	; CMDE9
		.BYTE	$F0,$04	; LOOP_START
		.BYTE	$B2,$A2,$92	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus28:
		.BYTE	$20
		.WORD	_apu_mus28_A
_apu_mus28_A:
		.BYTE	$E2,$04	; CMDE2
		.BYTE	$E1,$02	; CMDE1
		.BYTE	$E0,$01	; CMDE0
		.BYTE	$E9,$00	; CMDE9
		.BYTE	$D9,$00	; CMDD9
		.BYTE	$F0,$0B	; LOOP_START
		.BYTE	$00	; DATA
		.BYTE	$DA,$01	; CMDDA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$D9,$00	; CMDD9
		.BYTE	$F0,$0B	; LOOP_START
		.BYTE	$B3	; DATA
		.BYTE	$DA,$FF	; CMDDA
		.BYTE	$EA,$01	; CMDEA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus29:
		.BYTE	$10
		.WORD	_apu_mus29_A
_apu_mus29_A:
		.BYTE	$E2,$04	; CMDE2
		.BYTE	$E1,$02	; CMDE1
		.BYTE	$E0,$01	; CMDE0
		.BYTE	$EB,$85	; CMDEB
		.BYTE	$E9,$0A	; CMDE9
		.BYTE	$D6	; CMDD6
		.BYTE	$F0,$03	; LOOP_START
		.BYTE	$71,$91,$B1	; DATA
		.BYTE	$EA,$02	; CMDEA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus2A:
		.BYTE	$10
		.WORD	_apu_mus2A_A
_apu_mus2A_A:
		.BYTE	$E2,$04	; CMDE2
		.BYTE	$E1,$03	; CMDE1
		.BYTE	$E0,$01	; CMDE0
		.BYTE	$EB,$93	; CMDEB
		.BYTE	$E9,$00	; CMDE9
		.BYTE	$D3	; CMDD3
		.BYTE	$F0,$03	; LOOP_START
		.BYTE	$40,$50	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$C1	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$F0,$10	; LOOP_START
		.BYTE	$41	; DATA
		.BYTE	$D8	; CMDD8
		.BYTE	$91	; DATA
		.BYTE	$D7	; CMDD7
		.BYTE	$01	; DATA
		.BYTE	$DA,$FE	; CMDDA
		.BYTE	$EA,$01	; CMDEA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus2B:
		.BYTE	$30
		.WORD	_apu_mus2B_A
		.WORD	_apu_mus2B_B
_apu_mus2B_A:
		.BYTE	$E2,$04	; CMDE2
		.BYTE	$E1,$03	; CMDE1
		.BYTE	$E0,$01	; CMDE0
		.BYTE	$E9,$00	; CMDE9
		.BYTE	$D1	; CMDD1
		.BYTE	$91,$C0	; DATA
		.BYTE	$D1	; CMDD1
		.BYTE	$D9,$00	; CMDD9
		.BYTE	$F0,$02	; LOOP_START
		.BYTE	$01,$01	; DATA
		.BYTE	$DA,$FF	; CMDDA
		.BYTE	$EA,$08	; CMDEA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus2B_B:
		.BYTE	$E0,$01	; CMDE0
		.BYTE	$E9,$00	; CMDE9
		.BYTE	$B1,$C0	; DATA
		.BYTE	$D9,$00	; CMDD9
		.BYTE	$F0,$02	; LOOP_START
		.BYTE	$A1,$B1	; DATA
		.BYTE	$DA,$01	; CMDDA
		.BYTE	$EA,$08	; CMDEA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus2C:
		.BYTE	$10
		.WORD	_apu_mus2C_A
_apu_mus2C_A:
		.BYTE	$E2,$04	; CMDE2
		.BYTE	$E1,$02	; CMDE1
		.BYTE	$E0,$02	; CMDE0
		.BYTE	$D3	; CMDD3
		.BYTE	$EB,$9D	; CMDEB
		.BYTE	$E9,$08	; CMDE9
		.BYTE	$71	; DATA
		.BYTE	$E9,$06	; CMDE9
		.BYTE	$90	; DATA
		.BYTE	$E9,$02	; CMDE9
		.BYTE	$B1	; DATA
		.BYTE	$E9,$05	; CMDE9
		.BYTE	$EB,$95	; CMDEB
		.BYTE	$D7	; CMDD7
		.BYTE	$01,$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus2D:
		.BYTE	$30
		.WORD	_apu_mus2D_A
		.WORD	_apu_mus2D_B
_apu_mus2D_A:
		.BYTE	$E2,$04	; CMDE2
		.BYTE	$E1,$00	; CMDE1
		.BYTE	$E0,$01	; CMDE0
		.BYTE	$E9,$03	; CMDE9
		.BYTE	$EB,$9D	; CMDEB
		.BYTE	$D2	; CMDD2
		.BYTE	$77	; DATA
		.BYTE	$EB,$95	; CMDEB
		.BYTE	$77,$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus2D_B:
		.BYTE	$E2,$04	; CMDE2
		.BYTE	$E1,$00	; CMDE1
		.BYTE	$E0,$01	; CMDE0
		.BYTE	$F0,$03	; LOOP_START
		.BYTE	$D9,$FC	; CMDD9
		.BYTE	$B0	; DATA
		.BYTE	$D9,$00	; CMDD9
		.BYTE	$B0	; DATA
		.BYTE	$EA,$02	; CMDEA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$E9,$08	; CMDE9
		.BYTE	$71,$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus2E:
		.BYTE	$10
		.WORD	_apu_mus2E_A
_apu_mus2E_A:
		.BYTE	$E2,$04	; CMDE2
		.BYTE	$E1,$03	; CMDE1
		.BYTE	$E0,$01	; CMDE0
		.BYTE	$EB,$93	; CMDEB
		.BYTE	$E9,$00	; CMDE9
		.BYTE	$D5	; CMDD5
		.BYTE	$F0,$03	; LOOP_START
		.BYTE	$40	; DATA
		.BYTE	$D8	; CMDD8
		.BYTE	$90	; DATA
		.BYTE	$D7	; CMDD7
		.BYTE	$00	; DATA
		.BYTE	$DA,$04	; CMDDA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$DA,$F4	; CMDDA
		.BYTE	$D5	; CMDD5
		.BYTE	$F0,$08	; LOOP_START
		.BYTE	$40	; DATA
		.BYTE	$D8	; CMDD8
		.BYTE	$90	; DATA
		.BYTE	$D7	; CMDD7
		.BYTE	$00	; DATA
		.BYTE	$DA,$FE	; CMDDA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F0,$08	; LOOP_START
		.BYTE	$40	; DATA
		.BYTE	$D8	; CMDD8
		.BYTE	$90	; DATA
		.BYTE	$D7	; CMDD7
		.BYTE	$00	; DATA
		.BYTE	$DA,$FE	; CMDDA
		.BYTE	$EA,$01	; CMDEA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus2F:
		.BYTE	$30
		.WORD	_apu_mus2F_A
		.WORD	_apu_mus2F_B
_apu_mus2F_A:
		.BYTE	$E2,$04	; CMDE2
		.BYTE	$E1,$02	; CMDE1
		.BYTE	$E0,$01	; CMDE0
		.BYTE	$D1	; CMDD1
		.BYTE	$00,$C0	; DATA
		.BYTE	$D1	; CMDD1
		.BYTE	$00,$C0,$C0	; DATA
		.BYTE	$D2	; CMDD2
		.BYTE	$00,$C0	; DATA
		.BYTE	$D1	; CMDD1
		.BYTE	$00,$C0,$C0,$C0	; DATA
		.BYTE	$DA,$FF	; CMDDA
		.BYTE	$EA,$01	; CMDEA
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus2F_B:
		.BYTE	$E2,$04	; CMDE2
		.BYTE	$E1,$02	; CMDE1
		.BYTE	$E0,$01	; CMDE0
		.BYTE	$D1	; CMDD1
		.BYTE	$C0,$00	; DATA
		.BYTE	$D1	; CMDD1
		.BYTE	$C0,$00,$00	; DATA
		.BYTE	$D2	; CMDD2
		.BYTE	$C0,$B0	; DATA
		.BYTE	$D1	; CMDD1
		.BYTE	$C0,$90,$B0,$90	; DATA
		.BYTE	$DA,$FF	; CMDDA
		.BYTE	$EA,$01	; CMDEA
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus30:
		.BYTE	$30
		.WORD	_apu_mus30_A
		.WORD	_apu_mus30_B
_apu_mus30_A:
		.BYTE	$E2,$04	; CMDE2
		.BYTE	$E1,$00	; CMDE1
		.BYTE	$E0,$01	; CMDE0
		.BYTE	$D4	; CMDD4
		.BYTE	$40,$90,$C1	; DATA
		.BYTE	$D7	; CMDD7
		.BYTE	$91,$A1,$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus30_B:
		.BYTE	$E2,$04	; CMDE2
		.BYTE	$E1,$02	; CMDE1
		.BYTE	$E0,$01	; CMDE0
		.BYTE	$B1,$A0,$C0,$71,$C0 ; DATA
		.BYTE	$FF	; STOP
_apu_mus31:
		.BYTE	$10
		.WORD	_apu_mus31_A
_apu_mus31_A:
		.BYTE	$E2,$04	; CMDE2
		.BYTE	$E1,$02	; CMDE1
		.BYTE	$E0,$01	; CMDE0
		.BYTE	$D9,$0C	; CMDD9
		.BYTE	$E9,$00	; CMDE9
		.BYTE	$F0,$03	; LOOP_START
		.BYTE	$D4	; CMDD4
		.BYTE	$40,$30	; DATA
		.BYTE	$D8	; CMDD8
		.BYTE	$00	; DATA
		.BYTE	$EA,$06	; CMDEA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus32:
		.BYTE	$10
		.WORD	_apu_mus32_A
_apu_mus32_A:
		.BYTE	$E2,$04	; CMDE2
		.BYTE	$E1,$02	; CMDE1
		.BYTE	$E0,$01	; CMDE0
		.BYTE	$D4	; CMDD4
		.BYTE	$D9,$FD	; CMDD9
		.BYTE	$EB,$8C	; CMDEB
		.BYTE	$41,$B1,$81	; DATA
		.BYTE	$EC,$D9	; CMDEC
		.BYTE	$00	; DATA
		.BYTE	$D7	; CMDD7
		.BYTE	$44,$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus33:
		.BYTE	$10
		.WORD	_apu_mus33_A
_apu_mus33_A:
		.BYTE	$E2,$04	; CMDE2
		.BYTE	$E1,$01	; CMDE1
		.BYTE	$E0,$01	; CMDE0
		.BYTE	$F0,$04	; LOOP_START
		.BYTE	$D3	; CMDD3
		.BYTE	$B2,$72	; DATA
		.BYTE	$D7	; CMDD7
		.BYTE	$22,$B2,$72	; DATA
		.BYTE	$DA,$05	; CMDDA
		.BYTE	$EA,$03	; CMDEA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus34:
		.BYTE	$10
		.WORD	_apu_mus34_A
_apu_mus34_A:
		.BYTE	$E2,$04	; CMDE2
		.BYTE	$E1,$01	; CMDE1
		.BYTE	$E0,$04	; CMDE0
		.BYTE	$F0,$02	; LOOP_START
		.BYTE	$D4	; CMDD4
		.BYTE	$70,$40,$70	; DATA
		.BYTE	$D7	; CMDD7
		.BYTE	$00	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$01,$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus35:
		.BYTE	$30
		.WORD	_apu_mus35_A
		.WORD	_apu_mus35_B
_apu_mus35_A:
		.BYTE	$E2,$04	; CMDE2
		.BYTE	$E1,$02	; CMDE1
		.BYTE	$E0,$01	; CMDE0
		.BYTE	$DB,$81	; CMDDB
		.BYTE	$D9,$05	; CMDD9
		.BYTE	$C1	; DATA
		.BYTE	$E9,$04	; CMDE9
		.BYTE	$D2	; CMDD2
		.BYTE	$00,$30,$60,$90,$60,$40 ;	DATA
		.BYTE	$E9,$00	; CMDE9
		.BYTE	$D2	; CMDD2
		.BYTE	$00,$30,$60,$90,$60,$40 ;	DATA
		.BYTE	$E9,$05	; CMDE9
		.BYTE	$D2	; CMDD2
		.BYTE	$00,$30,$60,$90,$60,$40,$C0 ; DATA
		.BYTE	$FF	; STOP
_apu_mus35_B:
		.BYTE	$E2,$04	; CMDE2
		.BYTE	$E1,$03	; CMDE1
		.BYTE	$E0,$01	; CMDE0
		.BYTE	$E9,$05	; CMDE9
		.BYTE	$52,$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus36:
		.BYTE	$10
		.WORD	_apu_mus36_A
_apu_mus36_A:
		.BYTE	$E2,$04	; CMDE2
		.BYTE	$E1,$02	; CMDE1
		.BYTE	$E0,$01	; CMDE0
		.BYTE	$E9,$00	; CMDE9
		.BYTE	$E0,$01	; CMDE0
		.BYTE	$F0,$04	; LOOP_START
		.BYTE	$D4	; CMDD4
		.BYTE	$00,$10,$20,$30,$40,$30,$20,$10 ;	DATA
		.BYTE	$EA,$04	; CMDEA
		.BYTE	$DA,$FF	; CMDDA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus37:
		.BYTE	$10
		.WORD	_apu_mus37_A
_apu_mus37_A:
		.BYTE	$E2,$04	; CMDE2
		.BYTE	$E1,$03	; CMDE1
		.BYTE	$E0,$01	; CMDE0
		.BYTE	$F0,$10	; LOOP_START
		.BYTE	$D9,$00	; CMDD9
		.BYTE	$D2	; CMDD2
		.BYTE	$B0,$A0	; DATA
		.BYTE	$DA,$02	; CMDDA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus38:
		.BYTE	$10
		.WORD	_apu_mus38_A
_apu_mus38_A:
		.BYTE	$E2,$04	; CMDE2
		.BYTE	$E1,$02	; CMDE1
		.BYTE	$E0,$01	; CMDE0
		.BYTE	$D5	; CMDD5
		.BYTE	$EB,$83	; CMDEB
		.BYTE	$B2	; DATA
		.BYTE	$EC,$75	; CMDEC
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus39:
		.BYTE	$20
		.WORD	_apu_mus39_A
_apu_mus39_A:
		.BYTE	$E2,$04	; CMDE2
		.BYTE	$E1,$02	; CMDE1
		.BYTE	$E0,$01	; CMDE0
		.BYTE	$E9,$0A	; CMDE9
		.BYTE	$F0,$02	; LOOP_START
		.BYTE	$60,$90,$80,$40	; DATA
		.BYTE	$E9,$00	; CMDE9
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F0,$04	; LOOP_START
		.BYTE	$40,$60,$20,$00	; DATA
		.BYTE	$EA,$04	; CMDEA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus3A:
		.BYTE	$10
		.WORD	_apu_mus3A_A
_apu_mus3A_A:
		.BYTE	$E0,$01	; CMDE0
		.BYTE	$E1,$02	; CMDE1
		.BYTE	$E2,$01	; CMDE2
		.BYTE	$E9,$00	; CMDE9
		.BYTE	$D4	; CMDD4
		.BYTE	$DB,$03	; CMDDB
		.BYTE	$F0,$06	; LOOP_START
		.BYTE	$B1,$C0	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus3B:
		.BYTE	$30
		.WORD	_apu_mus3B_A
		.WORD	_apu_mus3B_B
_apu_mus3B_A:
		.BYTE	$E2,$04	; CMDE2
		.BYTE	$E1,$02	; CMDE1
		.BYTE	$E0,$01	; CMDE0
		.BYTE	$E9,$00	; CMDE9
		.BYTE	$EB,$BD	; CMDEB
		.BYTE	$D3	; CMDD3
		.BYTE	$01,$72,$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus3B_B:
		.BYTE	$E2,$04	; CMDE2
		.BYTE	$E1,$03	; CMDE1
		.BYTE	$E0,$01	; CMDE0
		.BYTE	$E9,$00	; CMDE9
		.BYTE	$C1,$32,$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus3C:
		.BYTE	$10
		.WORD	_apu_mus3C_A
_apu_mus3C_A:
		.BYTE	$E2,$04	; CMDE2
		.BYTE	$E1,$02	; CMDE1
		.BYTE	$E0,$01	; CMDE0
		.BYTE	$E9,$00	; CMDE9
		.BYTE	$EB,$85	; CMDEB
		.BYTE	$D3	; CMDD3
		.BYTE	$52	; DATA
		.BYTE	$EB,$8D	; CMDEB
		.BYTE	$E9,$03	; CMDE9
		.BYTE	$D3	; CMDD3
		.BYTE	$52,$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus3D:
		.BYTE	$30
		.WORD	_apu_mus3D_A
		.WORD	_apu_mus3D_B
_apu_mus3D_A:
		.BYTE	$E2,$04	; CMDE2
		.BYTE	$E1,$00	; CMDE1
		.BYTE	$E0,$02	; CMDE0
		.BYTE	$F0,$02	; LOOP_START
		.BYTE	$D0	; CMDD0
		.BYTE	$90,$A0	; DATA
		.BYTE	$D7	; CMDD7
		.BYTE	$00	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus3D_B:
		.BYTE	$E2,$04	; CMDE2
		.BYTE	$E1,$03	; CMDE1
		.BYTE	$E0,$04	; CMDE0
		.BYTE	$D9,$FD	; CMDD9
		.BYTE	$B2,$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus3E:
		.BYTE	$30
		.WORD	_apu_mus3E_A
		.WORD	_apu_mus3E_B
_apu_mus3E_A:
		.BYTE	$E2,$04	; CMDE2
		.BYTE	$E1,$00	; CMDE1
		.BYTE	$E0,$04	; CMDE0
		.BYTE	$D2	; CMDD2
		.BYTE	$EB,$9D	; CMDEB
		.BYTE	$97,$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus3E_B:
		.BYTE	$E2,$04	; CMDE2
		.BYTE	$E1,$00	; CMDE1
		.BYTE	$E0,$04	; CMDE0
		.BYTE	$E9,$05	; CMDE9
		.BYTE	$81,$71,$61,$51,$41,$C0 ;	DATA
		.BYTE	$FF	; STOP
_apu_mus3F:
		.BYTE	$20
		.WORD	_apu_mus3F_A
_apu_mus3F_A:
		.BYTE	$E2,$04	; CMDE2
		.BYTE	$E1,$02	; CMDE1
		.BYTE	$E0,$01	; CMDE0
		.BYTE	$D9,$FC	; CMDD9
		.BYTE	$C0,$B1	; DATA
		.BYTE	$D9,$00	; CMDD9
		.BYTE	$C0,$93,$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus40:
		.BYTE	$20
		.WORD	_apu_mus40_A
_apu_mus40_A:
		.BYTE	$E2,$02	; CMDE2
		.BYTE	$E1,$02	; CMDE1
		.BYTE	$E0,$01	; CMDE0
		.BYTE	$00,$10,$20,$33,$C0 ; DATA
		.BYTE	$FF	; STOP
_apu_mus41:
		.BYTE	$20
		.WORD	_apu_mus41_A
_apu_mus41_A:
		.BYTE	$E2,$04	; CMDE2
		.BYTE	$E1,$02	; CMDE1
		.BYTE	$E0,$04	; CMDE0
		.BYTE	$21,$43,$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus42:
		.BYTE	$10
		.WORD	_apu_mus42_A
_apu_mus42_A:
		.BYTE	$E2,$04	; CMDE2
		.BYTE	$E1,$02	; CMDE1
		.BYTE	$E0,$01	; CMDE0
		.BYTE	$D3	; CMDD3
		.BYTE	$F0,$03	; LOOP_START
		.BYTE	$EB,$B3	; CMDEB
		.BYTE	$73,$93	; DATA
		.BYTE	$EA,$04	; CMDEA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus43:
		.BYTE	$30
		.WORD	_apu_mus43_A
		.WORD	_apu_mus43_B
_apu_mus43_B:
		.BYTE	$E0,$01	; CMDE0
		.BYTE	$E9,$03	; CMDE9
		.BYTE	$F0,$06	; LOOP_START
		.BYTE	$80,$90,$A0,$B0,$A0,$90,$80 ; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus43_A:
		.BYTE	$E2,$04	; CMDE2
		.BYTE	$E1,$03	; CMDE1
		.BYTE	$E0,$01	; CMDE0
		.BYTE	$D9,$F4	; CMDD9
		.BYTE	$F0,$06	; LOOP_START
		.BYTE	$E9,$00	; CMDE9
		.BYTE	$D3	; CMDD3
		.BYTE	$40,$10	; DATA
		.BYTE	$D8	; CMDD8
		.BYTE	$B0	; DATA
		.BYTE	$D7	; CMDD7
		.BYTE	$00,$20,$30,$10	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus44:
		.BYTE	$30
		.WORD	_apu_mus44_A
		.WORD	_apu_mus44_B
_apu_mus44_A:
		.BYTE	$E2,$04	; CMDE2
		.BYTE	$E1,$02	; CMDE1
		.BYTE	$E0,$02	; CMDE0
		.BYTE	$EB,$85	; CMDEB
		.BYTE	$D9,$F8	; CMDD9
		.BYTE	$D0	; CMDD0
		.BYTE	$92,$C0	; DATA
		.BYTE	$F0,$03	; LOOP_START
		.BYTE	$91,$C0	; DATA
		.BYTE	$EA,$04	; CMDEA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus44_B:
		.BYTE	$E2,$04	; CMDE2
		.BYTE	$E1,$03	; CMDE1
		.BYTE	$E0,$01	; CMDE0
		.BYTE	$D9,$FE	; CMDD9
		.BYTE	$B2,$C0	; DATA
		.BYTE	$F0,$04	; LOOP_START
		.BYTE	$A6	; DATA
		.BYTE	$EA,$04	; CMDEA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus45:
		.BYTE	$20
		.WORD	_apu_mus45_A
_apu_mus45_A:
		.BYTE	$E2,$04	; CMDE2
		.BYTE	$E1,$00	; CMDE1
		.BYTE	$E0,$01	; CMDE0
		.BYTE	$00,$01,$00,$00	; DATA
		.BYTE	$F0,$0A	; LOOP_START
		.BYTE	$B0,$90,$B0,$90,$B0 ; DATA
		.BYTE	$DA,$FF	; CMDDA
		.BYTE	$EA,$02	; CMDEA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus46:
		.BYTE	$30
		.WORD	_apu_mus46_A
		.WORD	_apu_mus46_B
_apu_mus46_A:
		.BYTE	$E2,$04	; CMDE2
		.BYTE	$E1,$02	; CMDE1
		.BYTE	$E0,$01	; CMDE0
		.BYTE	$F0,$04	; LOOP_START
		.BYTE	$D1	; CMDD1
		.BYTE	$EC,$21	; CMDEC
		.BYTE	$32	; DATA
		.BYTE	$EB,$85	; CMDEB
		.BYTE	$D7	; CMDD7
		.BYTE	$51,$31,$21,$C4	; DATA
		.BYTE	$EA,$03	; CMDEA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus46_B:
		.BYTE	$E2,$04	; CMDE2
		.BYTE	$E1,$02	; CMDE1
		.BYTE	$E0,$02	; CMDE0
		.BYTE	$D9,$FE	; CMDD9
		.BYTE	$F0,$04	; LOOP_START
		.BYTE	$C0,$B6	; DATA
		.BYTE	$EA,$04	; CMDEA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus47:
		.BYTE	$10
		.WORD	_apu_mus47_A
_apu_mus47_A:
		.BYTE	$E2,$04	; CMDE2
		.BYTE	$E1,$02	; CMDE1
		.BYTE	$E0,$02	; CMDE0
		.BYTE	$D3	; CMDD3
		.BYTE	$EB,$9D	; CMDEB
		.BYTE	$E9,$09	; CMDE9
		.BYTE	$74	; DATA
		.BYTE	$E9,$07	; CMDE9
		.BYTE	$EB,$95	; CMDEB
		.BYTE	$B4,$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus4A:
		.BYTE	$10
		.WORD	_apu_mus4A_A
_apu_mus4A_A:
		.BYTE	$E2,$04	; CMDE2
		.BYTE	$E1,$02	; CMDE1
		.BYTE	$E0,$01	; CMDE0
		.BYTE	$E9,$00	; CMDE9
		.BYTE	$D9,$07	; CMDD9
		.BYTE	$D3	; CMDD3
		.BYTE	$EB,$8B	; CMDEB
		.BYTE	$71	; DATA
		.BYTE	$E9,$02	; CMDE9
		.BYTE	$EB,$83	; CMDEB
		.BYTE	$71,$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus4B:
		.BYTE	$20
		.WORD	_apu_mus4B_A
_apu_mus4B_A:
		.BYTE	$E2,$04	; CMDE2
		.BYTE	$E1,$02	; CMDE1
		.BYTE	$E0,$02	; CMDE0
		.BYTE	$E9,$05	; CMDE9
		.BYTE	$F0,$14	; LOOP_START
		.BYTE	$50	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus4D:
		.BYTE	$20
		.WORD	_apu_mus4D_A
_apu_mus4D_A:
		.BYTE	$E2,$04	; CMDE2
		.BYTE	$E1,$02	; CMDE1
		.BYTE	$E0,$01	; CMDE0
		.BYTE	$70,$C2,$71,$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus4E:
		.BYTE	$30
		.WORD	_apu_mus4E_A
		.WORD	_apu_mus4E_B
_apu_mus4E_A:
		.BYTE	$E2,$04	; CMDE2
		.BYTE	$E1,$02	; CMDE1
		.BYTE	$E0,$01	; CMDE0
		.BYTE	$D1	; CMDD1
		.BYTE	$50,$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus4E_B:
		.BYTE	$E2,$04	; CMDE2
		.BYTE	$E1,$02	; CMDE1
		.BYTE	$E0,$01	; CMDE0
		.BYTE	$D9,$FF	; CMDD9
		.BYTE	$B2,$C0	; DATA
		.BYTE	$E9,$03	; CMDE9
		.BYTE	$93,$C1,$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus4F:
		.BYTE	$10
		.WORD	_apu_mus4F_A
_apu_mus4F_A:
		.BYTE	$E2,$04	; CMDE2
		.BYTE	$E1,$02	; CMDE1
		.BYTE	$E0,$01	; CMDE0
		.BYTE	$D3	; CMDD3
		.BYTE	$F0,$0A	; LOOP_START
		.BYTE	$EB,$B3	; CMDEB
		.BYTE	$73,$53	; DATA
		.BYTE	$DA,$02	; CMDDA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus50:
		.BYTE	$30
		.WORD	_apu_mus50_A
		.WORD	_apu_mus50_B
_apu_mus50_A:
		.BYTE	$E2,$04	; CMDE2
		.BYTE	$E1,$02	; CMDE1
		.BYTE	$E0,$01	; CMDE0
		.BYTE	$E9,$00	; CMDE9
		.BYTE	$DA,$0C	; CMDDA
		.BYTE	$D1	; CMDD1
		.BYTE	$91	; DATA
		.BYTE	$D1	; CMDD1
		.BYTE	$D9,$08	; CMDD9
		.BYTE	$F0,$02	; LOOP_START
		.BYTE	$00	; DATA
		.BYTE	$DA,$01	; CMDDA
		.BYTE	$EA,$05	; CMDEA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus50_B:
		.BYTE	$E2,$04	; CMDE2
		.BYTE	$E1,$00	; CMDE1
		.BYTE	$E0,$01	; CMDE0
		.BYTE	$B0,$C1,$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus51:
		.BYTE	$20
		.WORD	_apu_mus51_A
_apu_mus51_A:
		.BYTE	$E2,$04	; CMDE2
		.BYTE	$E1,$03	; CMDE1
		.BYTE	$E0,$01	; CMDE0
		.BYTE	$D9,$FE	; CMDD9
		.BYTE	$B2,$C0	; DATA
		.BYTE	$F0,$04	; LOOP_START
		.BYTE	$A6	; DATA
		.BYTE	$EA,$04	; CMDEA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus52:
		.BYTE	$10
		.WORD	_apu_mus52_A
_apu_mus52_A:
		.BYTE	$E2,$04	; CMDE2
		.BYTE	$E1,$02	; CMDE1
		.BYTE	$E0,$01	; CMDE0
		.BYTE	$EB,$94	; CMDEB
		.BYTE	$D4	; CMDD4
		.BYTE	$73,$C0	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$DB,$08	; CMDDB
		.BYTE	$27,$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus53:
		.BYTE	$10
		.WORD	_apu_mus53_A
_apu_mus53_A:
		.BYTE	$E2,$04	; CMDE2
		.BYTE	$E1,$02	; CMDE1
		.BYTE	$E0,$01	; CMDE0
		.BYTE	$D3	; CMDD3
		.BYTE	$EB,$8B	; CMDEB
		.BYTE	$73	; DATA
		.BYTE	$E0,$01	; CMDE0
		.BYTE	$F0,$02	; LOOP_START
		.BYTE	$D3	; CMDD3
		.BYTE	$D9,$07	; CMDD9
		.BYTE	$01,$21,$01,$21	; DATA
		.BYTE	$EA,$02	; CMDEA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus54:
		.BYTE	$10
		.WORD	_apu_mus54_A
_apu_mus54_A:
		.BYTE	$E2,$04	; CMDE2
		.BYTE	$E1,$03	; CMDE1
		.BYTE	$E0,$01	; CMDE0
		.BYTE	$E9,$00	; CMDE9
		.BYTE	$D9,$06	; CMDD9
		.BYTE	$F0,$05	; LOOP_START
		.BYTE	$D2	; CMDD2
		.BYTE	$50	; DATA
		.BYTE	$D7	; CMDD7
		.BYTE	$50	; DATA
		.BYTE	$DA,$01	; CMDDA
		.BYTE	$EA,$01	; CMDEA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus55:
		.BYTE	$10
		.WORD	_apu_mus55_A
_apu_mus55_A:
		.BYTE	$E2,$04	; CMDE2
		.BYTE	$E1,$00	; CMDE1
		.BYTE	$E0,$03	; CMDE0
		.BYTE	$EB,$BD	; CMDEB
		.BYTE	$D2	; CMDD2
		.BYTE	$0F,$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus56:
		.BYTE	$10
		.WORD	_apu_mus56_A
_apu_mus56_A:
		.BYTE	$E2,$04	; CMDE2
		.BYTE	$E1,$00	; CMDE1
		.BYTE	$E0,$01	; CMDE0
		.BYTE	$D9,$05	; CMDD9
		.BYTE	$D3	; CMDD3
		.BYTE	$EB,$8B	; CMDEB
		.BYTE	$51,$C0,$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus57:
		.BYTE	$10
		.WORD	_apu_mus57_A
_apu_mus57_A:
		.BYTE	$E2,$04	; CMDE2
		.BYTE	$E1,$00	; CMDE1
		.BYTE	$E0,$01	; CMDE0
		.BYTE	$D9,$05	; CMDD9
		.BYTE	$D3	; CMDD3
		.BYTE	$EB,$8B	; CMDEB
		.BYTE	$91,$C0,$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus58:
		.BYTE	$10
		.WORD	_apu_mus58_A
_apu_mus58_A:
		.BYTE	$E2,$04	; CMDE2
		.BYTE	$E1,$00	; CMDE1
		.BYTE	$E0,$01	; CMDE0
		.BYTE	$D9,$02	; CMDD9
		.BYTE	$D4	; CMDD4
		.BYTE	$EB,$8B	; CMDEB
		.BYTE	$41,$C0,$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus59:
		.BYTE	$10
		.WORD	_apu_mus59_A
_apu_mus59_A:
		.BYTE	$E2,$04	; CMDE2
		.BYTE	$E1,$00	; CMDE1
		.BYTE	$E0,$01	; CMDE0
		.BYTE	$D9,$05	; CMDD9
		.BYTE	$D2	; CMDD2
		.BYTE	$EB,$8B	; CMDEB
		.BYTE	$B1,$C0,$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus5A:
		.BYTE	$10
		.WORD	_apu_mus5A_A
_apu_mus5A_A:
		.BYTE	$E2,$04	; CMDE2
		.BYTE	$E1,$00	; CMDE1
		.BYTE	$E0,$01	; CMDE0
		.BYTE	$E9,$02	; CMDE9
		.BYTE	$D9,$05	; CMDD9
		.BYTE	$D4	; CMDD4
		.BYTE	$EB,$8B	; CMDEB
		.BYTE	$51,$C0,$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus5B:
		.BYTE	$10
		.WORD	_apu_mus5B_A
_apu_mus5B_A:
		.BYTE	$E2,$04	; CMDE2
		.BYTE	$E1,$00	; CMDE1
		.BYTE	$E0,$01	; CMDE0
		.BYTE	$D9,$07	; CMDD9
		.BYTE	$D3	; CMDD3
		.BYTE	$EB,$8B	; CMDEB
		.BYTE	$01,$C0,$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus5C:
		.BYTE	$20
		.WORD	_apu_mus5C_A
_apu_mus5C_A:
		.BYTE	$E2,$04	; CMDE2
		.BYTE	$E1,$00	; CMDE1
		.BYTE	$E0,$01	; CMDE0
		.BYTE	$E9,$05	; CMDE9
		.BYTE	$90,$C1,$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus5D:
		.BYTE	$20
		.WORD	_apu_mus5D_A
_apu_mus5D_A:
		.BYTE	$E2,$04	; CMDE2
		.BYTE	$E1,$00	; CMDE1
		.BYTE	$E0,$01	; CMDE0
		.BYTE	$E9,$03	; CMDE9
		.BYTE	$B0,$C1,$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus5E:
		.BYTE	$10
		.WORD	_apu_mus5E_A
_apu_mus5E_A:
		.BYTE	$E2,$04	; CMDE2
		.BYTE	$E1,$02	; CMDE1
		.BYTE	$E0,$01	; CMDE0
		.BYTE	$DB,$81	; CMDDB
		.BYTE	$D9,$08	; CMDD9
		.BYTE	$E9,$03	; CMDE9
		.BYTE	$D2	; CMDD2
		.BYTE	$00,$30,$60,$90,$60,$40 ;	DATA
		.BYTE	$E9,$00	; CMDE9
		.BYTE	$D2	; CMDD2
		.BYTE	$00,$30,$60,$90,$60,$40 ;	DATA
		.BYTE	$E9,$05	; CMDE9
		.BYTE	$D2	; CMDD2
		.BYTE	$00,$30,$60,$90,$60,$40,$C0 ; DATA
		.BYTE	$FF	; STOP
_apu_mus5F:
		.BYTE	$10
		.WORD	_apu_mus5F_A
_apu_mus5F_A:
		.BYTE	$E2,$04	; CMDE2
		.BYTE	$E1,$02	; CMDE1
		.BYTE	$E0,$02	; CMDE0
		.BYTE	$D3	; CMDD3
		.BYTE	$EB,$93	; CMDEB
		.BYTE	$91	; DATA
		.BYTE	$EB,$9B	; CMDEB
		.BYTE	$01,$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus60:
		.BYTE	$30
		.WORD	_apu_mus60_A
		.WORD	_apu_mus60_B
_apu_mus60_A:
		.BYTE	$E2,$04	; CMDE2
		.BYTE	$E1,$02	; CMDE1
		.BYTE	$E0,$01	; CMDE0
		.BYTE	$E9,$00	; CMDE9
		.BYTE	$DA,$0C	; CMDDA
		.BYTE	$D1	; CMDD1
		.BYTE	$91,$C0	; DATA
		.BYTE	$D1	; CMDD1
		.BYTE	$D9,$00	; CMDD9
		.BYTE	$F0,$02	; LOOP_START
		.BYTE	$01,$01	; DATA
		.BYTE	$DA,$FF	; CMDDA
		.BYTE	$EA,$08	; CMDEA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus60_B:
		.BYTE	$E2,$04	; CMDE2
		.BYTE	$E0,$01	; CMDE0
		.BYTE	$E9,$03	; CMDE9
		.BYTE	$01,$C0	; DATA
		.BYTE	$D9,$00	; CMDD9
		.BYTE	$F0,$02	; LOOP_START
		.BYTE	$11,$01	; DATA
		.BYTE	$DA,$01	; CMDDA
		.BYTE	$EA,$08	; CMDEA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus61:
		.BYTE	$10
		.WORD	_apu_mus61_A
_apu_mus61_A:
		.BYTE	$E2,$04	; CMDE2
		.BYTE	$E1,$00	; CMDE1
		.BYTE	$E0,$01	; CMDE0
		.BYTE	$D2	; CMDD2
		.BYTE	$71,$C0,$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus62:
		.BYTE	$30
		.WORD	_apu_mus62_A
		.WORD	_apu_mus62_B
_apu_mus62_A:
		.BYTE	$E2,$04	; CMDE2
		.BYTE	$E1,$00	; CMDE1
		.BYTE	$E0,$01	; CMDE0
		.BYTE	$D3	; CMDD3
		.BYTE	$EB,$85	; CMDEB
		.BYTE	$91	; DATA
		.BYTE	$D7	; CMDD7
		.BYTE	$91	; DATA
		.BYTE	$D8	; CMDD8
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus62_B:
		.BYTE	$E2,$04	; CMDE2
		.BYTE	$E1,$00	; CMDE1
		.BYTE	$E0,$01	; CMDE0
		.BYTE	$70,$C2,$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus63:
		.BYTE	$30
		.WORD	_apu_mus63_A
		.WORD	_apu_mus63_B
_apu_mus63_A:
		.BYTE	$E2,$04	; CMDE2
		.BYTE	$E1,$03	; CMDE1
		.BYTE	$E0,$01	; CMDE0
		.BYTE	$E9,$00	; CMDE9
		.BYTE	$D0	; CMDD0
		.BYTE	$91,$C0	; DATA
		.BYTE	$D1	; CMDD1
		.BYTE	$D9,$00	; CMDD9
		.BYTE	$F0,$02	; LOOP_START
		.BYTE	$92	; DATA
		.BYTE	$EA,$08	; CMDEA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus63_B:
		.BYTE	$E0,$01	; CMDE0
		.BYTE	$E9,$00	; CMDE9
		.BYTE	$B1,$C0	; DATA
		.BYTE	$D9,$00	; CMDD9
		.BYTE	$F0,$04	; LOOP_START
		.BYTE	$A1	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F0,$0F	; LOOP_START
		.BYTE	$B0	; DATA
		.BYTE	$EA,$01	; CMDEA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus64:
		.BYTE	$30
		.WORD	_apu_mus64_A
		.WORD	_apu_mus64_B
_apu_mus64_A:
		.BYTE	$E2,$04	; CMDE2
		.BYTE	$E1,$01	; CMDE1
		.BYTE	$E0,$01	; CMDE0
		.BYTE	$D6	; CMDD6
		.BYTE	$EB,$8D	; CMDEB
		.BYTE	$E9,$00	; CMDE9
		.BYTE	$F0,$04	; LOOP_START
		.BYTE	$81,$C1	; DATA
		.BYTE	$EA,$03	; CMDEA
		.BYTE	$DA,$FF	; CMDDA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus64_B:
		.BYTE	$E2,$04	; CMDE2
		.BYTE	$E1,$02	; CMDE1
		.BYTE	$E0,$01	; CMDE0
		.BYTE	$F0,$04	; LOOP_START
		.BYTE	$EA,$02	; CMDEA
		.BYTE	$70	; DATA
		.BYTE	$EA,$FE	; CMDEA
		.BYTE	$A0,$90,$50	; DATA
		.BYTE	$EA,$04	; CMDEA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus65:
		.BYTE	$20
		.WORD	_apu_mus65_A
_apu_mus65_A:
		.BYTE	$E2,$04	; CMDE2
		.BYTE	$E1,$02	; CMDE1
		.BYTE	$E0,$01	; CMDE0
		.BYTE	$E0,$02	; CMDE0
		.BYTE	$E9,$00	; CMDE9
		.BYTE	$51,$C0	; DATA
		.BYTE	$D9,$00	; CMDD9
		.BYTE	$F0,$03	; LOOP_START
		.BYTE	$81	; DATA
		.BYTE	$EA,$01	; CMDEA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$EA,$FD	; CMDEA
		.BYTE	$F0,$0F	; LOOP_START
		.BYTE	$A0	; DATA
		.BYTE	$EA,$01	; CMDEA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus66:
		.BYTE	$30
		.WORD	_apu_mus66_A
		.WORD	_apu_mus66_B
_apu_mus66_A:
		.BYTE	$E2,$04	; CMDE2
		.BYTE	$E1,$00	; CMDE1
		.BYTE	$E0,$01	; CMDE0
		.BYTE	$E9,$08	; CMDE9
		.BYTE	$DB,$81	; CMDDB
		.BYTE	$D9,$88	; CMDD9
		.BYTE	$D0	; CMDD0
		.BYTE	$00,$C3	; DATA
		.BYTE	$E9,$00	; CMDE9
		.BYTE	$D0	; CMDD0
		.BYTE	$01,$C1,$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus66_B:
		.BYTE	$E2,$04	; CMDE2
		.BYTE	$E1,$00	; CMDE1
		.BYTE	$E0,$01	; CMDE0
		.BYTE	$E9,$00	; CMDE9
		.BYTE	$DB,$81	; CMDDB
		.BYTE	$D9,$88	; CMDD9
		.BYTE	$C0,$B3,$C1,$31,$21,$11 ;	DATA
		.BYTE	$E9,$08	; CMDE9
		.BYTE	$01,$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus67:
		.BYTE	$20
		.WORD	_apu_mus67_A
_apu_mus67_A:
		.BYTE	$E2,$05	; CMDE2
		.BYTE	$E0,$02	; CMDE0
		.BYTE	$E9,$02	; CMDE9
		.BYTE	$71	; DATA
		.BYTE	$D9,$00	; CMDD9
		.BYTE	$E9,$01	; CMDE9
		.BYTE	$71	; DATA
		.BYTE	$E9,$00	; CMDE9
		.BYTE	$81	; DATA
		.BYTE	$E9,$00	; CMDE9
		.BYTE	$91	; DATA
		.BYTE	$E9,$00	; CMDE9
		.BYTE	$F0,$0F	; LOOP_START
		.BYTE	$A0	; DATA
		.BYTE	$EA,$01	; CMDEA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus68:
		.BYTE	$30
		.WORD	_apu_mus68_A
		.WORD	_apu_mus68_B
_apu_mus68_A:
		.BYTE	$E2,$04	; CMDE2
		.BYTE	$E1,$03	; CMDE1
		.BYTE	$E0,$01	; CMDE0
		.BYTE	$E9,$00	; CMDE9
		.BYTE	$D6	; CMDD6
		.BYTE	$E1,$00	; CMDE1
		.BYTE	$61,$C1	; DATA
		.BYTE	$E1,$03	; CMDE1
		.BYTE	$11,$C1,$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus68_B:
		.BYTE	$E2,$04	; CMDE2
		.BYTE	$E1,$02	; CMDE1
		.BYTE	$E0,$01	; CMDE0
		.BYTE	$E9,$03	; CMDE9
		.BYTE	$51,$C1,$73,$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus69:
		.BYTE	$10
		.WORD	_apu_mus69_A
_apu_mus69_A:
		.BYTE	$E2,$04	; CMDE2
		.BYTE	$E1,$03	; CMDE1
		.BYTE	$E0,$01	; CMDE0
		.BYTE	$E9,$00	; CMDE9
		.BYTE	$D4	; CMDD4
		.BYTE	$50	; DATA
		.BYTE	$D7	; CMDD7
		.BYTE	$B0,$80,$A0,$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus6A:
		.BYTE	$10
		.WORD	_apu_mus6A_A
_apu_mus6A_A:
		.BYTE	$E2,$04	; CMDE2
		.BYTE	$E1,$03	; CMDE1
		.BYTE	$E0,$01	; CMDE0
		.BYTE	$E9,$00	; CMDE9
		.BYTE	$D9,$FF	; CMDD9
		.BYTE	$D5	; CMDD5
		.BYTE	$70	; DATA
		.BYTE	$D8	; CMDD8
		.BYTE	$D8	; CMDD8
		.BYTE	$D8	; CMDD8
		.BYTE	$C0,$C0	; DATA
		.BYTE	$D8	; CMDD8
		.BYTE	$C0	; DATA
		.BYTE	$D7	; CMDD7
		.BYTE	$00,$20	; DATA
		.BYTE	$D7	; CMDD7
		.BYTE	$70,$70,$A0	; DATA
		.BYTE	$D7	; CMDD7
		.BYTE	$50	; DATA
		.BYTE	$D7	; CMDD7
		.BYTE	$B0,$80,$A0,$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus6B:
		.BYTE	$20
		.WORD	_apu_mus6B_A
_apu_mus6B_A:
		.BYTE	$E2,$04	; CMDE2
		.BYTE	$E1,$00	; CMDE1
		.BYTE	$E0,$01	; CMDE0
		.BYTE	$E9,$00	; CMDE9
		.BYTE	$51,$C0,$41,$C0,$31,$C0 ;	DATA
		.BYTE	$FF	; STOP
_apu_mus6C:
		.BYTE	$30
		.WORD	_apu_mus6C_A
		.WORD	_apu_mus6C_B
_apu_mus6C_A:
		.BYTE	$E2,$12	; CMDE2
		.BYTE	$E1,$02	; CMDE1
		.BYTE	$E0,$01	; CMDE0
		.BYTE	$F0,$02	; LOOP_START
		.BYTE	$D1	; CMDD1
		.BYTE	$21,$91	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus6C_B:
		.BYTE	$E0,$01	; CMDE0
		.BYTE	$E2,$04	; CMDE2
		.BYTE	$E9,$00	; CMDE9
		.BYTE	$F0,$02	; LOOP_START
		.BYTE	$B1	; DATA
		.BYTE	$D9,$FC	; CMDD9
		.BYTE	$B1	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus6D:
		.BYTE	$30
		.WORD	_apu_mus6D_A
		.WORD	_apu_mus6D_B
_apu_mus6D_A:
		.BYTE	$E2,$04	; CMDE2
		.BYTE	$E1,$00	; CMDE1
		.BYTE	$E0,$01	; CMDE0
		.BYTE	$D2	; CMDD2
		.BYTE	$00,$70,$00	; DATA
		.BYTE	$D6	; CMDD6
		.BYTE	$C3	; DATA
		.BYTE	$F0,$0F	; LOOP_START
		.BYTE	$90	; DATA
		.BYTE	$EA,$02	; CMDEA
		.BYTE	$DA,$FD	; CMDDA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus6D_B:
		.BYTE	$E2,$04	; CMDE2
		.BYTE	$E1,$00	; CMDE1
		.BYTE	$E0,$01	; CMDE0
		.BYTE	$80,$A0,$B0,$B0,$90,$C1,$01 ; DATA
		.BYTE	$EA,$02	; CMDEA
		.BYTE	$11	; DATA
		.BYTE	$EA,$02	; CMDEA
		.BYTE	$21	; DATA
		.BYTE	$EA,$02	; CMDEA
		.BYTE	$31	; DATA
		.BYTE	$EA,$02	; CMDEA
		.BYTE	$41	; DATA
		.BYTE	$EA,$02	; CMDEA
		.BYTE	$51	; DATA
		.BYTE	$EA,$02	; CMDEA
		.BYTE	$61	; DATA
		.BYTE	$EA,$02	; CMDEA
		.BYTE	$71,$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus6E:
		.BYTE	$20
		.WORD	_apu_mus6E_A
_apu_mus6E_A:
		.BYTE	$E2,$04	; CMDE2
		.BYTE	$E1,$03	; CMDE1
		.BYTE	$E0,$01	; CMDE0
		.BYTE	$E9,$00	; CMDE9
		.BYTE	$32,$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus6F:
		.BYTE	$30
		.WORD	_apu_mus6F_A
		.WORD	_apu_mus6F_B
_apu_mus6F_A:
		.BYTE	$E2,$04	; CMDE2
		.BYTE	$E1,$00	; CMDE1
		.BYTE	$E0,$01	; CMDE0
		.BYTE	$D3	; CMDD3
		.BYTE	$F0,$04	; LOOP_START
		.BYTE	$90,$A0,$90,$C0	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus6F_B:
		.BYTE	$E2,$04	; CMDE2
		.BYTE	$E1,$00	; CMDE1
		.BYTE	$E0,$01	; CMDE0
		.BYTE	$F0,$04	; LOOP_START
		.BYTE	$52,$C0	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus70:
		.BYTE	$10
		.WORD	_apu_mus70_A
_apu_mus70_A:
		.BYTE	$E2,$04	; CMDE2
		.BYTE	$E1,$02	; CMDE1
		.BYTE	$E0,$01	; CMDE0
		.BYTE	$E9,$00	; CMDE9
		.BYTE	$E0,$01	; CMDE0
		.BYTE	$D9,$F8	; CMDD9
		.BYTE	$F0,$10	; LOOP_START
		.BYTE	$D5	; CMDD5
		.BYTE	$00,$10,$20,$30,$40,$30,$20,$10 ;	DATA
		.BYTE	$EA,$01	; CMDEA
		.BYTE	$DA,$FF	; CMDDA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus71:
		.BYTE	$30
		.WORD	_apu_mus71_A
		.WORD	_apu_mus71_B
_apu_mus71_A:
		.BYTE	$E2,$04	; CMDE2
		.BYTE	$E1,$02	; CMDE1
		.BYTE	$E0,$04	; CMDE0
		.BYTE	$EB,$B5	; CMDEB
		.BYTE	$D4	; CMDD4
		.BYTE	$C0,$9B,$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus71_B:
		.BYTE	$E2,$04	; CMDE2
		.BYTE	$E1,$02	; CMDE1
		.BYTE	$E0,$01	; CMDE0
		.BYTE	$F0,$04	; LOOP_START
		.BYTE	$70,$A0,$90,$50	; DATA
		.BYTE	$EA,$04	; CMDEA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus72:
		.BYTE	$10
		.WORD	_apu_mus72_A
_apu_mus72_A:
		.BYTE	$E2,$00	; CMDE2
		.BYTE	$E1,$02	; CMDE1
		.BYTE	$E0,$01	; CMDE0
		.BYTE	$E9,$00	; CMDE9
		.BYTE	$D4	; CMDD4
		.BYTE	$B2,$71,$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus73:
		.BYTE	$30
		.WORD	_apu_mus73_A
		.WORD	_apu_mus73_B
_apu_mus73_A:
		.BYTE	$E2,$05	; CMDE2
		.BYTE	$E1,$02	; CMDE1
		.BYTE	$E0,$01	; CMDE0
		.BYTE	$E9,$00	; CMDE9
		.BYTE	$F0,$02	; LOOP_START
		.BYTE	$E9,$0A	; CMDE9
		.BYTE	$E0,$02	; CMDE0
		.BYTE	$CF	; DATA
		.BYTE	$E0,$01	; CMDE0
		.BYTE	$D5	; CMDD5
		.BYTE	$F0,$06	; LOOP_START
		.BYTE	$70	; DATA
		.BYTE	$DA,$01	; CMDDA
		.BYTE	$EA,$FF	; CMDEA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$DA,$FA	; CMDDA
		.BYTE	$D6	; CMDD6
		.BYTE	$F0,$04	; LOOP_START
		.BYTE	$00	; DATA
		.BYTE	$DA,$FF	; CMDDA
		.BYTE	$EA,$01	; CMDEA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$DA,$04	; CMDDA
		.BYTE	$90,$80	; DATA
		.BYTE	$D6	; CMDD6
		.BYTE	$01	; DATA
		.BYTE	$EA,$FF	; CMDEA
		.BYTE	$30	; DATA
		.BYTE	$EA,$FF	; CMDEA
		.BYTE	$40	; DATA
		.BYTE	$EA,$FF	; CMDEA
		.BYTE	$50	; DATA
		.BYTE	$EA,$FF	; CMDEA
		.BYTE	$62	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus73_B:
		.BYTE	$E2,$05	; CMDE2
		.BYTE	$E1,$03	; CMDE1
		.BYTE	$E0,$02	; CMDE0
		.BYTE	$E9,$0E	; CMDE9
		.BYTE	$A0,$90	; DATA
		.BYTE	$E9,$0C	; CMDE9
		.BYTE	$A0,$90	; DATA
		.BYTE	$E9,$09	; CMDE9
		.BYTE	$90,$70	; DATA
		.BYTE	$E9,$07	; CMDE9
		.BYTE	$80,$60	; DATA
		.BYTE	$E9,$04	; CMDE9
		.BYTE	$70,$50	; DATA
		.BYTE	$E9,$00	; CMDE9
		.BYTE	$F0,$14	; LOOP_START
		.BYTE	$80,$60,$70,$50	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$E9,$02	; CMDE9
		.BYTE	$70,$50	; DATA
		.BYTE	$E9,$04	; CMDE9
		.BYTE	$70,$50	; DATA
		.BYTE	$E9,$06	; CMDE9
		.BYTE	$80,$60	; DATA
		.BYTE	$E9,$08	; CMDE9
		.BYTE	$80,$60	; DATA
		.BYTE	$E9,$0A	; CMDE9
		.BYTE	$90,$70	; DATA
		.BYTE	$E9,$0C	; CMDE9
		.BYTE	$90,$70	; DATA
		.BYTE	$E9,$0E	; CMDE9
		.BYTE	$A0,$90	; DATA
		.BYTE	$E9,$0E	; CMDE9
		.BYTE	$A0,$90,$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus74:
		.BYTE	$30
		.WORD	_apu_mus74_A
		.WORD	_apu_mus74_B
_apu_mus74_A:
		.BYTE	$E2,$00	; CMDE2
		.BYTE	$E1,$02	; CMDE1
		.BYTE	$E0,$01	; CMDE0
		.BYTE	$E9,$04	; CMDE9
		.BYTE	$F0,$0A	; LOOP_START
		.BYTE	$EA,$01	; CMDEA
		.BYTE	$C0	; DATA
		.BYTE	$D2	; CMDD2
		.BYTE	$70	; DATA
		.BYTE	$D2	; CMDD2
		.BYTE	$40	; DATA
		.BYTE	$D9,$FE	; CMDD9
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F0,$0A	; LOOP_START
		.BYTE	$EA,$FF	; CMDEA
		.BYTE	$C0	; DATA
		.BYTE	$D2	; CMDD2
		.BYTE	$70	; DATA
		.BYTE	$D2	; CMDD2
		.BYTE	$40	; DATA
		.BYTE	$D9,$02	; CMDD9
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F0,$19	; LOOP_START
		.BYTE	$C0	; DATA
		.BYTE	$D2	; CMDD2
		.BYTE	$70	; DATA
		.BYTE	$D2	; CMDD2
		.BYTE	$40	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus74_B:
		.BYTE	$E2,$00	; CMDE2
		.BYTE	$E1,$00	; CMDE1
		.BYTE	$E0,$01	; CMDE0
		.BYTE	$E9,$00	; CMDE9
		.BYTE	$F0,$0A	; LOOP_START
		.BYTE	$EA,$01	; CMDEA
		.BYTE	$00,$80,$C0	; DATA
		.BYTE	$D9,$FF	; CMDD9
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F0,$0A	; LOOP_START
		.BYTE	$EA,$FF	; CMDEA
		.BYTE	$00,$80,$C0	; DATA
		.BYTE	$D9,$01	; CMDD9
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F0,$19	; LOOP_START
		.BYTE	$00,$50,$C0	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
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
		.BYTE	$E2,$00	; CMDE2
		.BYTE	$E1,$01	; CMDE1
		.BYTE	$E0,$05	; CMDE0
		.BYTE	$E9,$03	; CMDE9
		.BYTE	$D9,$F4	; CMDD9
byte_994F4:
		.BYTE	$C1	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$30,$C0,$32,$C0,$30,$C0,$33,$C1,$22,$C0 ;	DATA
		.BYTE	$F0,$0E	; LOOP_START
		.BYTE	$20,$C0	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F2	; JSR
		.WORD	byte_995DE
		.BYTE	$C3	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$71,$C1,$A1	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$21,$C1,$03	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$A2,$C0,$93,$C1,$63 ; DATA
		.BYTE	$F2	; JSR
		.WORD	byte_995DE
		.BYTE	$C3	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$71,$C1,$A1	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$21,$C1,$23,$01,$C1,$03 ;	DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$A1	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$01,$C1,$32,$C0,$20,$C0,$20,$C2 ;	DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$A3	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$33,$22,$C0,$23,$C3 ; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$A1	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$01,$21,$C1,$23,$01,$C1,$21,$C1 ;	DATA
		.BYTE	$F0,$04	; LOOP_START
		.BYTE	$50,$C0	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$51,$C1,$47,$C1,$41,$C1,$01,$23,$41,$50,$C0,$50,$C0,$50,$C0,$52 ;	DATA
		.BYTE	$C0,$43,$71,$51,$41,$C1,$05,$C1
		.BYTE	$F0,$04	; LOOP_START
		.BYTE	$50,$C0	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$52,$C0,$74,$C0,$53,$31,$23,$35,$03,$21,$C1,$31,$C1,$71,$51,$C1 ;	DATA
		.BYTE	$51,$C1,$33,$51,$C1
		.BYTE	$F0,$04	; LOOP_START
		.BYTE	$80,$C0	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$82,$C0,$77,$C1,$73,$31,$53,$71,$80,$C0,$80,$C0,$80,$C0,$82,$C0 ;	DATA
		.BYTE	$73,$A1,$81,$71,$C1,$35,$C1
		.BYTE	$F0,$04	; LOOP_START
		.BYTE	$80,$C0	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$82,$C0,$A5,$83,$61,$51,$C1,$65,$33,$51,$C1,$61,$C1,$A1,$81,$C1 ;	DATA
		.BYTE	$83,$63,$81,$C1
		.BYTE	$F0,$04	; LOOP_START
		.BYTE	$B0,$C0	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$B2,$C0,$A7,$C1,$A3,$61,$81,$C1,$A1,$B0,$C0,$B0,$C0,$B0,$C0,$B2 ;	DATA
		.BYTE	$C0,$A3
		.BYTE	$D6	; CMDD6
		.BYTE	$11	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$B1,$A1,$C1,$65,$C1 ; DATA
		.BYTE	$F0,$04	; LOOP_START
		.BYTE	$B0,$C0	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$B2,$C0	; DATA
		.BYTE	$D6	; CMDD6
		.BYTE	$14,$CC	; DATA
		.BYTE	$F8	; JMP
		.WORD	byte_994F4
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
byte_995DE:
		.BYTE	$F0,$02	; LOOP_START
		.BYTE	$D4	; CMDD4
		.BYTE	$71,$C3	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$27,$C1	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F3	; RET
_apu_mus01_B:
		.BYTE	$E2,$01	; CMDE2
		.BYTE	$E1,$01	; CMDE1
		.BYTE	$E0,$05	; CMDE0
		.BYTE	$D9,$F4	; CMDD9
byte_995F0:
		.BYTE	$E9,$05	; CMDE9
		.BYTE	$C1	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$00,$C0,$02,$C0,$00,$C0,$03,$C1 ;	DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$A2,$C0	; DATA
		.BYTE	$F0,$0E	; LOOP_START
		.BYTE	$A0,$C0	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$E9,$09	; CMDE9
		.BYTE	$F2	; JSR
		.WORD	byte_996D1
		.BYTE	$D4	; CMDD4
		.BYTE	$F0,$08	; LOOP_START
		.BYTE	$00,$C0	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F2	; JSR
		.WORD	byte_996D1
		.BYTE	$D3	; CMDD3
		.BYTE	$F0,$08	; LOOP_START
		.BYTE	$90,$C0	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$E9,$05	; CMDE9
		.BYTE	$72,$C0,$50,$C0,$50,$C0,$C1,$53,$73,$53,$53,$C3,$51,$91,$91,$C1 ;	DATA
		.BYTE	$93,$91,$C1,$91,$C1
		.BYTE	$F0,$04	; LOOP_START
		.BYTE	$90,$C0	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$91,$C1	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$01	; DATA
		.BYTE	$E8	; CMDE8
		.BYTE	$F2	; JSR
		.WORD	byte_996DE
		.BYTE	$D3	; CMDD3
		.BYTE	$57,$C1	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$01,$C1,$01	; DATA
		.BYTE	$E8	; CMDE8
		.BYTE	$F2	; JSR
		.WORD	byte_996DE
		.BYTE	$D3	; CMDD3
		.BYTE	$53,$C3	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$01,$01,$C5	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$51,$81	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$01,$C1	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$51,$81	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$01,$C1	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$81	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$01,$31,$C1	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$81	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$01,$31,$C1	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$A1	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$21,$51,$C1	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$A3	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$21,$C1	; DATA
		.BYTE	$F0,$04	; LOOP_START
		.BYTE	$00,$C0	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$02,$C0,$37,$C1	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$A5,$8A,$A0	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$00,$20,$30,$50,$77,$C1 ;	DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$A5,$85,$C3	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$31,$31,$C5	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$81,$B1	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$31,$C1	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$81,$B1	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$31,$C1	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$B1	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$31,$61,$C1	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$B1	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$31,$61,$C1,$11,$51,$81,$C1,$13,$51,$C1 ;	DATA
		.BYTE	$F0,$04	; LOOP_START
		.BYTE	$30,$C0	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$31,$C1,$61	; DATA
		.BYTE	$E8	; CMDE8
		.BYTE	$F2	; JSR
		.WORD	byte_996E6
		.BYTE	$D3	; CMDD3
		.BYTE	$B7,$C1	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$61,$C1,$61	; DATA
		.BYTE	$E8	; CMDE8
		.BYTE	$F2	; JSR
		.WORD	byte_996E6
		.BYTE	$D3	; CMDD3
		.BYTE	$B3,$C3	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$61,$61,$C1,$A4,$CC ; DATA
		.BYTE	$F8	; JMP
		.WORD	byte_995F0
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
byte_996D1:
		.BYTE	$D4	; CMDD4
		.BYTE	$F0,$10	; LOOP_START
		.BYTE	$20,$C0	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$D4	; CMDD4
		.BYTE	$F0,$08	; LOOP_START
		.BYTE	$30,$C0	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F3	; RET
byte_996DE:
		.BYTE	$D4	; CMDD4
		.BYTE	$05,$C1	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$75,$51	; DATA
		.BYTE	$E8	; CMDE8
		.BYTE	$F3	; RET
byte_996E6:
		.BYTE	$D4	; CMDD4
		.BYTE	$65,$C1,$15	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$B1	; DATA
		.BYTE	$E8	; CMDE8
		.BYTE	$F3	; RET
_apu_mus01_C:
		.BYTE	$E2,$03	; CMDE2
		.BYTE	$E1,$00	; CMDE1
		.BYTE	$E0,$05	; CMDE0
		.BYTE	$E9,$00	; CMDE9
byte_996F6:
		.BYTE	$C1	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$90,$C0,$92,$C0,$90,$C0,$93,$C1 ;	DATA
		.BYTE	$F0,$03	; LOOP_START
		.BYTE	$F2	; JSR
		.WORD	byte_997FC
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F2	; JSR
		.WORD	byte_99807
		.BYTE	$D3	; CMDD3
		.BYTE	$01,$C3	; DATA
		.BYTE	$D2	; CMDD2
		.BYTE	$75,$C1,$71,$51,$C3,$53 ;	DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$91	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$31,$61	; DATA
		.BYTE	$F2	; JSR
		.WORD	byte_997FC
		.BYTE	$F2	; JSR
		.WORD	byte_99807
		.BYTE	$D3	; CMDD3
		.BYTE	$01,$C3,$75,$C1,$31,$53,$C1 ; DATA
		.BYTE	$E2,$02	; CMDE2
		.BYTE	$51,$51,$51,$51,$51 ; DATA
		.BYTE	$D2	; CMDD2
		.BYTE	$F0,$10	; LOOP_START
		.BYTE	$A1	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$D3	; CMDD3
		.BYTE	$51,$51,$C1,$51,$51,$51,$51 ; DATA
		.BYTE	$E2,$03	; CMDE2
		.BYTE	$56,$C0	; DATA
		.BYTE	$D2	; CMDD2
		.BYTE	$71,$91,$B5	; DATA
		.BYTE	$F0,$03	; LOOP_START
		.BYTE	$D3	; CMDD3
		.BYTE	$01	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$00,$C0	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$01	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$00,$C0	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$01	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$00,$C0	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$01	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$00,$C0	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$D3	; CMDD3
		.BYTE	$01	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$00,$C0	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$01	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$00,$C0	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$00,$C0,$01,$21,$31 ; DATA
		.BYTE	$E2,$02	; CMDE2
		.BYTE	$51,$51,$C1,$51,$51 ; DATA
		.BYTE	$E2,$03	; CMDE2
		.BYTE	$51,$71	; DATA
		.BYTE	$E2,$02	; CMDE2
		.BYTE	$81	; DATA
		.BYTE	$F0,$08	; LOOP_START
		.BYTE	$81	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F0,$08	; LOOP_START
		.BYTE	$A1	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$E2,$03	; CMDE2
		.BYTE	$A1,$C1	; DATA
		.BYTE	$D2	; CMDD2
		.BYTE	$A3	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$01,$25	; DATA
		.BYTE	$F0,$03	; LOOP_START
		.BYTE	$D3	; CMDD3
		.BYTE	$31	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$30,$C0	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$31	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$30,$C0	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$31	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$30,$C0	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$31	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$30,$C0	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$D3	; CMDD3
		.BYTE	$31	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$30,$C0	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$31	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$30,$C0	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$30,$C0,$31,$51,$61 ; DATA
		.BYTE	$E2,$02	; CMDE2
		.BYTE	$81,$81,$C1,$81,$81 ; DATA
		.BYTE	$E2,$03	; CMDE2
		.BYTE	$81,$A1	; DATA
		.BYTE	$E2,$02	; CMDE2
		.BYTE	$B1	; DATA
		.BYTE	$F0,$08	; LOOP_START
		.BYTE	$B1	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$D4	; CMDD4
		.BYTE	$F0,$08	; LOOP_START
		.BYTE	$11	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$E2,$03	; CMDE2
		.BYTE	$11,$C1	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$13,$31,$55	; DATA
		.BYTE	$F0,$03	; LOOP_START
		.BYTE	$D3	; CMDD3
		.BYTE	$61	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$60,$C0	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$61	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$60,$C0	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$61	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$60,$C0	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$61	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$60,$C0	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$D3	; CMDD3
		.BYTE	$61	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$60,$C0	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$61	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$60,$C0	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$60,$C0,$61,$81,$A1,$62,$CC ; DATA
		.BYTE	$F8	; JMP
		.WORD	byte_996F6
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
byte_997FC:
		.BYTE	$D2	; CMDD2
		.BYTE	$71,$C3	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$23	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$21	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$91,$A1	; DATA
		.BYTE	$F3	; RET
byte_99807:
		.BYTE	$D2	; CMDD2
		.BYTE	$A1,$C3	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$23	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$21	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$91,$A1	; DATA
		.BYTE	$F3	; RET
_apu_mus01_D:
		.BYTE	$E0,$05	; CMDE0
		.BYTE	$E9,$00	; CMDE9
byte_99816:
		.BYTE	$01,$21,$23,$21,$23,$21
		.BYTE	$F0,$02	; LOOP_START
		.BYTE	$03,$23,$01,$01,$23 ; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F0,$04	; LOOP_START
		.BYTE	$03,$33,$03,$33	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F0,$03	; LOOP_START
		.BYTE	$03,$33,$C1,$21,$33 ; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$03,$33,$C1,$20,$20,$23 ;	DATA
		.BYTE	$F2	; JSR
		.WORD	byte_9985A
		.BYTE	$F2	; JSR
		.WORD	byte_9986C
		.BYTE	$F2	; JSR
		.WORD	byte_99863
		.BYTE	$F2	; JSR
		.WORD	byte_9986C
		.BYTE	$F2	; JSR
		.WORD	byte_99863
		.BYTE	$F2	; JSR
		.WORD	byte_9986C
		.BYTE	$F2	; JSR
		.WORD	byte_9985A
		.BYTE	$03,$23,$21,$21,$01,$21,$CF ; DATA
		.BYTE	$F8	; JMP
		.WORD	byte_99816	; DATA
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
byte_9985A:
		.BYTE	$F0,$03	; LOOP_START
		.BYTE	$03,$23,$01,$01,$23 ; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F3	; RET
byte_99863:
		.BYTE	$F0,$07	; LOOP_START
		.BYTE	$03,$23,$01,$01,$23 ; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F3	; RET
byte_9986C:
		.BYTE	$C7,$21,$20,$20,$23	; DATA
		.BYTE	$F3	; RET
_apu_mus02:
		.BYTE	$0F
		.WORD	_apu_mus02_A
		.WORD	_apu_mus02_B
		.WORD	_apu_mus02_C
		.WORD	_apu_mus02_D
_apu_mus02_A:
		.BYTE	$E2,$00	; CMDE2
		.BYTE	$E1,$01	; CMDE1
		.BYTE	$E0,$06	; CMDE0
		.BYTE	$E9,$04	; CMDE9
		.BYTE	$D9,$EE	; CMDD9
byte_99885:
		.BYTE	$E1,$01	; CMDE1
		.BYTE	$F0,$02	; LOOP_START
		.BYTE	$F2	; JSR
		.WORD	byte_99929
		.BYTE	$D5	; CMDD5
		.BYTE	$40,$60,$70,$90,$C1,$90,$C0,$70,$C0,$60,$C0,$40,$C0,$20,$C0 ; DATA
		.BYTE	$F2	; JSR
		.WORD	byte_99929
		.BYTE	$D5	; CMDD5
		.BYTE	$40,$60,$70,$90,$C1,$90,$C0,$70,$60,$40,$C0,$20,$C2 ; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$E1,$02	; CMDE1
		.BYTE	$F2	; JSR
		.WORD	byte_9993C
		.BYTE	$D4	; CMDD4
		.BYTE	$B0,$A0,$B0,$C0	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$20,$C0	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$B0,$C0,$90,$C0	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$90,$70,$60,$40,$20,$C0 ;	DATA
		.BYTE	$F2	; JSR
		.WORD	byte_9993C
		.BYTE	$40,$30,$40,$60,$40,$60,$C0,$90,$C3,$73 ;	DATA
		.BYTE	$E1,$01	; CMDE1
		.BYTE	$F2	; JSR
		.WORD	byte_9994D
		.BYTE	$D5	; CMDD5
		.BYTE	$11	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$91	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$11	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$91	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$10,$20,$C0,$40,$C1,$10,$C0 ; DATA
		.BYTE	$F2	; JSR
		.WORD	byte_9994D
		.BYTE	$11	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$91	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$11	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$91	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$11	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$B1,$91,$71	; DATA
		.BYTE	$F2	; JSR
		.WORD	byte_99957
		.BYTE	$E1,$03	; CMDE1
		.BYTE	$D4	; CMDD4
		.BYTE	$60,$70,$90,$C0,$70,$90,$B0,$C0 ;	DATA
		.BYTE	$E1,$00	; CMDE1
		.BYTE	$D5	; CMDD5
		.BYTE	$10,$C0,$20,$C0,$42,$C0 ;	DATA
		.BYTE	$F2	; JSR
		.WORD	byte_99957
		.BYTE	$E1,$03	; CMDE1
		.BYTE	$D5	; CMDD5
		.BYTE	$60,$40,$20,$10	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$B0,$90,$70,$60,$40,$60,$40,$60,$43 ; DATA
		.BYTE	$F8	; JMP
		.WORD	byte_99885
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
byte_99929:
		.BYTE	$D5	; CMDD5
		.BYTE	$60,$40,$60,$C0,$20,$C0 ;	DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$90,$C0,$71,$90,$B0 ; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$10,$C0,$20,$C0	; DATA
		.BYTE	$F3	; RET
byte_9993C:
		.BYTE	$D4	; CMDD4
		.BYTE	$B0,$A0,$B0,$C0	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$20,$C0	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$B0,$C0,$91	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$61,$41,$21	; DATA
		.BYTE	$F3	; RET
byte_9994D:
		.BYTE	$D5	; CMDD5
		.BYTE	$63,$21	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$93,$B3	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$11	; DATA
		.BYTE	$E8	; CMDE8
		.BYTE	$F3	; RET
byte_99957:
		.BYTE	$E1,$03	; CMDE1
		.BYTE	$D4	; CMDD4
		.BYTE	$60,$70,$90,$C0,$70,$90,$B0,$C0 ;	DATA
		.BYTE	$E1,$00	; CMDE1
		.BYTE	$D5	; CMDD5
		.BYTE	$10,$C0	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$B0,$C0,$92,$C0	; DATA
		.BYTE	$F3	; RET
_apu_mus02_B:
		.BYTE	$E2,$01	; CMDE2
		.BYTE	$E1,$01	; CMDE1
		.BYTE	$E0,$06	; CMDE0
		.BYTE	$D9,$FA	; CMDD9
byte_99975:
		.BYTE	$E9,$09	; CMDE9
		.BYTE	$F0,$02	; LOOP_START
		.BYTE	$F2	; JSR
		.WORD	byte_999FC
		.BYTE	$C1	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$91,$B1	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$11,$21,$41,$61,$41 ; DATA
		.BYTE	$F2	; JSR
		.WORD	byte_999FC
		.BYTE	$C1	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$91,$B1	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$11,$20,$10,$20,$40,$20,$C2 ; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$E1,$02	; CMDE1
		.BYTE	$E9,$08	; CMDE9
		.BYTE	$F2	; JSR
		.WORD	byte_99A08
		.BYTE	$D4	; CMDD4
		.BYTE	$47,$27	; DATA
		.BYTE	$F2	; JSR
		.WORD	byte_99A08
		.BYTE	$E1,$01	; CMDE1
		.BYTE	$DA,$F4	; CMDDA
		.BYTE	$40,$30,$40,$60,$40,$60,$C0,$90,$C3,$73 ;	DATA
		.BYTE	$DA,$0C	; CMDDA
		.BYTE	$E2,$02	; CMDE2
		.BYTE	$F0,$02	; LOOP_START
		.BYTE	$D4	; CMDD4
		.BYTE	$21,$41,$61,$21,$41,$61,$41,$61 ;	DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$71,$61,$71,$61,$91,$71,$61,$41 ;	DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$E2,$01	; CMDE2
		.BYTE	$F2	; JSR
		.WORD	byte_99A0D
		.BYTE	$E1,$03	; CMDE1
		.BYTE	$D4	; CMDD4
		.BYTE	$20,$40,$60,$C0,$40,$60,$70,$C0 ;	DATA
		.BYTE	$E1,$00	; CMDE1
		.BYTE	$90,$C0,$B0,$C0	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$12,$C0	; DATA
		.BYTE	$F2	; JSR
		.WORD	byte_99A0D
		.BYTE	$E1,$01	; CMDE1
		.BYTE	$D5	; CMDD5
		.BYTE	$20,$10	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$B0,$90,$70,$60,$40,$20,$10,$20,$10,$20,$13 ; DATA
		.BYTE	$F8	; JMP
		.WORD	byte_99975
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
byte_999FC:
		.BYTE	$C1	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$61,$21	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$91,$C1,$71,$B1	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$41	; DATA
		.BYTE	$F3	; RET
byte_99A08:
		.BYTE	$D4	; CMDD4
		.BYTE	$77,$63,$23	; DATA
		.BYTE	$F3	; RET
byte_99A0D:
		.BYTE	$E1,$03	; CMDE1
		.BYTE	$D4	; CMDD4
		.BYTE	$20,$40,$60,$C0,$40,$60,$70,$C0 ;	DATA
		.BYTE	$E1,$00	; CMDE1
		.BYTE	$90,$C0,$70,$C0,$62,$C0 ;	DATA
		.BYTE	$F3	; RET
_apu_mus02_C:
		.BYTE	$E2,$03	; CMDE2
		.BYTE	$E1,$03	; CMDE1
		.BYTE	$E0,$06	; CMDE0
		.BYTE	$E9,$00	; CMDE9
		.BYTE	$D9,$FA	; CMDD9
byte_99A2B:
		.BYTE	$F0,$02	; LOOP_START
		.BYTE	$F2	; JSR
		.WORD	byte_99A86
		.BYTE	$D3	; CMDD3
		.BYTE	$F0,$03	; LOOP_START
		.BYTE	$91,$C1	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$91,$B0	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$10	; DATA
		.BYTE	$F2	; JSR
		.WORD	byte_99A86
		.BYTE	$D3	; CMDD3
		.BYTE	$F0,$03	; LOOP_START
		.BYTE	$91,$C1	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$D4	; CMDD4
		.BYTE	$21,$C1	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F0,$03	; LOOP_START
		.BYTE	$D3	; CMDD3
		.BYTE	$71,$C1,$71,$C1,$67 ; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$D3	; CMDD3
		.BYTE	$41,$C1,$42,$90,$C3,$93 ;	DATA
		.BYTE	$F0,$02	; LOOP_START
		.BYTE	$D3	; CMDD3
		.BYTE	$F0,$04	; LOOP_START
		.BYTE	$20,$C0	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F0,$03	; LOOP_START
		.BYTE	$70,$C0	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$93	; DATA
		.BYTE	$F0,$04	; LOOP_START
		.BYTE	$90,$C0	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$D2	; CMDD2
		.BYTE	$90,$C0,$B0,$C0	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$10,$C0	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F0,$04	; LOOP_START
		.BYTE	$D3	; CMDD3
		.BYTE	$21,$C1,$71,$C1,$90,$C0,$90,$C0,$92,$C0 ;	DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F8	; JMP
		.WORD	byte_99A2B
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
byte_99A86:
		.BYTE	$D4	; CMDD4
		.BYTE	$21,$C1,$01,$C1	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$B7	; DATA
		.BYTE	$F3	; RET
_apu_mus02_D:
		.BYTE	$E0,$06	; CMDE0
byte_99A90:
		.BYTE	$E9,$08	; CMDE9
		.BYTE	$F0,$20	; LOOP_START
		.BYTE	$31,$30,$30	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F0,$03	; LOOP_START
		.BYTE	$10	; DATA
		.BYTE	$F0,$0F	; LOOP_START
		.BYTE	$30	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F1	; DO_LOOP
		.BYTE	$10,$30,$30,$30	; DATA
		.BYTE	$F0,$04	; LOOP_START
		.BYTE	$30	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$10,$30,$30,$30	; DATA
		.BYTE	$E9,$00	; CMDE9
		.BYTE	$23	; DATA
		.BYTE	$F0,$08	; LOOP_START
		.BYTE	$01,$31,$21,$31	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F0,$03	; LOOP_START
		.BYTE	$33,$33,$21,$21,$23 ; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$33,$33,$20,$20,$20,$20,$21,$21 ;	DATA
		.BYTE	$F8	; JMP
		.WORD	byte_99A90
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus03:
		.BYTE	$0F
		.WORD	_apu_mus03_A
		.WORD	_apu_mus03_B
		.WORD	_apu_mus03_C
		.WORD	_apu_mus03_D
_apu_mus03_A:
		.BYTE	$E2,$00	; CMDE2
		.BYTE	$E1,$03	; CMDE1
		.BYTE	$E0,$06	; CMDE0
		.BYTE	$E9,$03	; CMDE9
		.BYTE	$D9,$F4	; CMDD9
byte_99ADE:
		.BYTE	$F2	; JSR
		.WORD	byte_99B96
		.BYTE	$C1	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$20,$C0,$22,$00,$C0,$00,$C0,$00,$50,$C0,$40,$C0 ;	DATA
		.BYTE	$F2	; JSR
		.WORD	byte_99B96
		.BYTE	$F2	; JSR
		.WORD	byte_99BA6
		.BYTE	$D5	; CMDD5
		.BYTE	$20,$C0,$20,$C0,$01,$00,$20,$C0 ;	DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$70,$C0,$70,$B0,$C0 ; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$00,$C0	; DATA
		.BYTE	$F2	; JSR
		.WORD	byte_99BB7
		.BYTE	$D4	; CMDD4
		.BYTE	$B1,$C0,$B1,$C0	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$01	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$B0,$70,$C0,$72,$91,$C1 ;	DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$20,$C0,$40,$20,$C0,$51,$50,$40,$C0,$22,$C0,$21,$C0,$22,$41,$20 ;	DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$70,$C0,$72,$90,$B0 ; DATA
		.BYTE	$F2	; JSR
		.WORD	byte_99BB7
		.BYTE	$B0,$C0,$B0,$C0,$B1 ; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$00	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$B0,$C0,$70,$C0,$70 ; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$50,$C0,$40,$C0,$C1,$20,$C0,$40,$20,$C0,$70 ; DATA
		.BYTE	$E8	; CMDE8
		.BYTE	$73	; DATA
		.BYTE	$E8	; CMDE8
		.BYTE	$E0,$03	; CMDE0
		.BYTE	$70,$50,$40,$20,$00 ; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$B0,$90,$70	; DATA
		.BYTE	$E0,$06	; CMDE0
		.BYTE	$F2	; JSR
		.WORD	byte_99BC6
		.BYTE	$D5	; CMDD5
		.BYTE	$20,$C0,$20,$C0,$20 ; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$B0,$C0	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$20,$C0,$20,$C0	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$B0,$90,$C0,$B0,$C0,$C0 ;	DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$20,$40,$20,$50,$40,$C0,$51,$50,$40,$C0,$23 ; DATA
		.BYTE	$F2	; JSR
		.WORD	byte_99BC6
		.BYTE	$50,$C0,$50,$C0,$40,$21,$70,$90,$C0,$90,$70,$C3 ;	DATA
		.BYTE	$F2	; JSR
		.WORD	byte_99BA6
		.BYTE	$F8	; JMP
		.WORD	byte_99ADE
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
byte_99B96:
		.BYTE	$C1	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$20,$C0,$22,$00,$C0,$00,$C0,$00,$20,$C0 ;	DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$B0,$C0	; DATA
		.BYTE	$F3	; RET
byte_99BA6:
		.BYTE	$C0	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$B0,$70,$20,$90,$50,$00,$70,$C0,$71,$20,$50,$40,$20,$C0 ;	DATA
		.BYTE	$F3	; RET
byte_99BB7:
		.BYTE	$D4	; CMDD4
		.BYTE	$70,$C0,$70,$C0,$70,$C0,$70,$C0,$50,$70,$C0,$73,$C0 ; DATA
		.BYTE	$F3	; RET
byte_99BC6:
		.BYTE	$D5	; CMDD5
		.BYTE	$40,$C0,$40,$C0,$40,$00,$C0,$40,$C0,$40,$C0,$00 ;	DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$A0,$C0	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$00,$C0,$C0	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$70,$90,$70	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$00,$20,$00	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$70	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$30,$40,$C0,$21,$00,$40,$00 ; DATA
		.BYTE	$F3	; RET
_apu_mus03_B:
		.BYTE	$E2,$00	; CMDE2
		.BYTE	$E1,$03	; CMDE1
		.BYTE	$E0,$06	; CMDE0
		.BYTE	$E9,$05	; CMDE9
		.BYTE	$D9,$F4	; CMDD9
byte_99BF7:
		.BYTE	$F0,$02	; LOOP_START
		.BYTE	$F2	; JSR
		.WORD	byte_99C29
		.BYTE	$F2	; JSR
		.WORD	byte_99C38
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F0,$08	; LOOP_START
		.BYTE	$F2	; JSR
		.WORD	byte_99C48
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F2	; JSR
		.WORD	byte_99C52
		.BYTE	$F0,$02	; LOOP_START
		.BYTE	$F2	; JSR
		.WORD	byte_99C48
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F2	; JSR
		.WORD	byte_99C52
		.BYTE	$D5	; CMDD5
		.BYTE	$20,$C0,$20,$C0,$00 ; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$B1	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$40,$50,$C0,$50,$40,$C3 ;	DATA
		.BYTE	$F2	; JSR
		.WORD	byte_99C38
		.BYTE	$F8	; JMP
		.WORD	byte_99BF7
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
byte_99C29:
		.BYTE	$C1	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$B0,$C0,$B2,$90,$C0,$90,$C0,$90,$B0,$C0,$70,$C0 ;	DATA
		.BYTE	$F3	; RET
byte_99C38:
		.BYTE	$C1	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$B0,$C0,$B2,$90,$C0,$90,$C0,$90 ;	DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$00,$C0,$00,$C0	; DATA
		.BYTE	$F3	; RET
byte_99C48:
		.BYTE	$C1	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$20,$C0,$23,$02	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$B0,$C3	; DATA
		.BYTE	$F3	; RET
byte_99C52:
		.BYTE	$F0,$02	; LOOP_START
		.BYTE	$C1	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$40,$C0,$43,$22,$00,$C3 ;	DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F3	; RET
_apu_mus03_C:
		.BYTE	$E2,$04	; CMDE2
		.BYTE	$E1,$03	; CMDE1
		.BYTE	$E0,$06	; CMDE0
		.BYTE	$E9,$00	; CMDE9
byte_99C66:
		.BYTE	$F0,$0C	; LOOP_START
		.BYTE	$F2	; JSR
		.WORD	byte_99C9E
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F2	; JSR
		.WORD	byte_99CB5
		.BYTE	$F2	; JSR
		.WORD	byte_99C9E
		.BYTE	$D3	; CMDD3
		.BYTE	$70,$C0,$70,$C0,$90,$C0,$90,$C0,$B0,$C0,$B0,$C0,$70,$C0,$70,$C0 ;	DATA
		.BYTE	$F2	; JSR
		.WORD	byte_99CB5
		.BYTE	$70,$C0,$70,$C0,$70,$C0,$70,$C0,$70,$C0,$70,$C0,$70,$C0,$70,$C0 ;	DATA
		.BYTE	$F2	; JSR
		.WORD	byte_99C9E
		.BYTE	$F8	; JMP
		.WORD	byte_99C66
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
byte_99C9E:
		.BYTE	$D2	; CMDD2
		.BYTE	$73	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$71,$C0,$50,$C0,$50,$C0,$50,$70,$C0,$70 ;	DATA
		.BYTE	$E0,$01	; CMDE0
		.BYTE	$21,$01	; DATA
		.BYTE	$D2	; CMDD2
		.BYTE	$B0,$90	; DATA
		.BYTE	$E0,$06	; CMDE0
		.BYTE	$F3	; RET
byte_99CB5:
		.BYTE	$D3	; CMDD3
		.BYTE	$03	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$01,$C0	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$A0,$C0,$A0,$C0,$A0 ; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$00,$C0,$00	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$E0,$01	; CMDE0
		.BYTE	$71,$51,$40,$20	; DATA
		.BYTE	$E0,$06	; CMDE0
		.BYTE	$D3	; CMDD3
		.BYTE	$00,$C0,$00,$C0,$20,$C0,$20,$C0,$40,$C0,$40,$C0,$00,$C0,$00,$C0 ;	DATA
		.BYTE	$F3	; RET
_apu_mus03_D:
		.BYTE	$E9,$02	; CMDE9
		.BYTE	$E0,$06	; CMDE0
byte_99CE3:
		.BYTE	$F0,$03	; LOOP_START
		.BYTE	$F2	; JSR
		.WORD	byte_99D03
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F2	; JSR
		.WORD	byte_99D0F
		.BYTE	$F0,$07	; LOOP_START
		.BYTE	$F2	; JSR
		.WORD	byte_99D03
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F2	; JSR
		.WORD	byte_99D0F
		.BYTE	$F0,$07	; LOOP_START
		.BYTE	$F2	; JSR
		.WORD	byte_99D03
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F2	; JSR
		.WORD	byte_99D0F
		.BYTE	$F8	; JMP
		.WORD	byte_99CE3
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
byte_99D03:
		.BYTE	$01,$21,$20,$01,$00,$20,$30,$20,$30,$21,$21	; DATA
		.BYTE	$F3	; RET
byte_99D0F:
		.BYTE	$01,$21,$20,$01,$00,$20,$30,$20,$30,$20,$20,$20,$20	; DATA
		.BYTE	$F3	; RET
_apu_mus04:
		.BYTE	$0F
		.WORD	_apu_mus04_A
		.WORD	_apu_mus04_B
		.WORD	_apu_mus04_C
		.WORD	_apu_mus04_D
_apu_mus04_A:
		.BYTE	$E2,$00	; CMDE2
		.BYTE	$E1,$03	; CMDE1
		.BYTE	$E0,$05	; CMDE0
		.BYTE	$E9,$00	; CMDE9
		.BYTE	$D9,$E8	; CMDD9
byte_99D30:
		.BYTE	$F2	; JSR
		.WORD	byte_99D71
		.BYTE	$D4	; CMDD4
		.BYTE	$9B,$C3	; DATA
		.BYTE	$F2	; JSR
		.WORD	byte_99D71
		.BYTE	$91,$C5,$A7	; DATA
		.BYTE	$F0,$02	; LOOP_START
		.BYTE	$F0,$02	; LOOP_START
		.BYTE	$D4	; CMDD4
		.BYTE	$B3	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$21,$69	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$D5	; CMDD5
		.BYTE	$65,$7B	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$41,$71,$B3	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$45	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F0,$02	; LOOP_START
		.BYTE	$D5	; CMDD5
		.BYTE	$61,$11	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$A1	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$61,$11	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$A1	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$71,$11	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$D5	; CMDD5
		.BYTE	$A1,$61,$11,$A1,$61,$11,$B1,$61,$AB ; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$A3	; DATA
		.BYTE	$F8	; JMP
		.WORD	byte_99D30
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
byte_99D71:
		.BYTE	$D5	; CMDD5
		.BYTE	$31,$41,$31,$41,$01 ; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$91,$C1	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$33,$41,$31,$41,$01 ; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$91,$C3	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$31,$41,$31,$41,$21,$01 ;	DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$91	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$2D,$C3	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$11,$21,$11,$21	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$B1,$81,$C1	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$13,$21,$11,$21	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$B1,$81,$C5	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$41,$31,$41,$81,$43,$91 ;	DATA
		.BYTE	$E8	; CMDE8
		.BYTE	$F3	; RET
_apu_mus04_B:
		.BYTE	$E2,$00	; CMDE2
		.BYTE	$E1,$03	; CMDE1
		.BYTE	$E0,$05	; CMDE0
		.BYTE	$E9,$08	; CMDE9
		.BYTE	$D9,$E8	; CMDD9
		.BYTE	$C1	; DATA
		.BYTE	$F8	; JMP
		.WORD	byte_99D30
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus04_C:
		.BYTE	$E2,$03	; CMDE2
		.BYTE	$E1,$03	; CMDE1
		.BYTE	$E0,$05	; CMDE0
		.BYTE	$E9,$00	; CMDE9
byte_99DC2:
		.BYTE	$F0,$03	; LOOP_START
		.BYTE	$F2	; JSR
		.WORD	byte_99E1A
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F2	; JSR
		.WORD	byte_99E23
		.BYTE	$F0,$03	; LOOP_START
		.BYTE	$F2	; JSR
		.WORD	byte_99E2B
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F0,$04	; LOOP_START
		.BYTE	$F2	; JSR
		.WORD	byte_99E1A
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F2	; JSR
		.WORD	byte_99E23
		.BYTE	$F0,$02	; LOOP_START
		.BYTE	$F2	; JSR
		.WORD	byte_99E2B
		.BYTE	$F1	; DO_LOOP
		.BYTE	$D3	; CMDD3
		.BYTE	$41,$C3,$43,$41,$31,$41 ;	DATA
		.BYTE	$D2	; CMDD2
		.BYTE	$91,$C5,$A7	; DATA
		.BYTE	$F0,$02	; LOOP_START
		.BYTE	$F0,$02	; LOOP_START
		.BYTE	$D2	; CMDD2
		.BYTE	$B1,$C3	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$23,$61,$51,$61	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F0,$02	; LOOP_START
		.BYTE	$D3	; CMDD3
		.BYTE	$41,$C3,$73,$B1,$A1,$B1 ;	DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F0,$03	; LOOP_START
		.BYTE	$D3	; CMDD3
		.BYTE	$61,$C3,$61,$C3,$73 ; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$D3	; CMDD3
		.BYTE	$63,$C1	; DATA
		.BYTE	$D2	; CMDD2
		.BYTE	$61,$C1,$61,$71,$81 ; DATA
		.BYTE	$F8	; JMP
		.WORD	byte_99DC2
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
byte_99E1A:
		.BYTE	$D2	; CMDD2
		.BYTE	$91,$C3	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$03,$41,$31,$41	; DATA
		.BYTE	$F3	; RET
byte_99E23:
		.BYTE	$D3	; CMDD3
		.BYTE	$21,$C3,$53,$91,$81,$91 ;	DATA
		.BYTE	$F3	; RET
byte_99E2B:
		.BYTE	$D3	; CMDD3
		.BYTE	$41,$C3,$83,$B1,$A1,$B1 ;	DATA
		.BYTE	$F3	; RET
_apu_mus04_D:
		.BYTE	$E0,$05	; CMDE0
		.BYTE	$E9,$03	; CMDE9
byte_99E37:
		.BYTE	$F0,$06	; LOOP_START
		.BYTE	$F0,$03	; LOOP_START
		.BYTE	$01,$31,$21,$31,$01,$31,$21,$31 ;	DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$01,$31,$21,$31,$01,$21,$21,$21 ;	DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F0,$03	; LOOP_START
		.BYTE	$F0,$02	; LOOP_START
		.BYTE	$21,$31,$31	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$21,$31	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$33,$33,$21,$21,$21,$21 ;	DATA
		.BYTE	$F8	; JMP
		.WORD	byte_99E37
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus05:
		.BYTE	$0F
		.WORD	_apu_mus05_A
		.WORD	_apu_mus05_B
		.WORD	_apu_mus05_C
		.WORD	_apu_mus05_D
_apu_mus05_A:
		.BYTE	$E2,$00	; CMDE2
		.BYTE	$E1,$03	; CMDE1
		.BYTE	$E0,$04	; CMDE0
		.BYTE	$E9,$02	; CMDE9
		.BYTE	$D9,$ED	; CMDD9
byte_99E76:
		.BYTE	$F2	; JSR
		.WORD	byte_99EE6
		.BYTE	$D4	; CMDD4
		.BYTE	$91,$C1,$91,$C1,$91,$51,$C1,$91,$C1,$91,$C1,$51,$91,$C1 ;	DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$01,$C1	; DATA
		.BYTE	$F2	; JSR
		.WORD	byte_99EE6
		.BYTE	$D5	; CMDD5
		.BYTE	$01,$C1,$01,$C1,$01 ; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$91,$C1	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$01,$C1,$01,$C1	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$91	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$51,$41,$21,$C1	; DATA
		.BYTE	$F2	; JSR
		.WORD	byte_99EFA
		.BYTE	$D4	; CMDD4
		.BYTE	$B1,$C1,$B1,$71,$C7 ; DATA
		.BYTE	$F2	; JSR
		.WORD	byte_99EFA
		.BYTE	$D4	; CMDD4
		.BYTE	$B1,$C1,$B1,$71,$C1,$91,$B3 ; DATA
		.BYTE	$F2	; JSR
		.WORD	byte_99F2D
		.BYTE	$D5	; CMDD5
		.BYTE	$21,$01,$21,$33,$C1,$33,$75,$55,$33 ; DATA
		.BYTE	$F2	; JSR
		.WORD	byte_99F2D
		.BYTE	$F0,$02	; LOOP_START
		.BYTE	$C1	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$71	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$71	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$71	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$51,$21,$C1	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$73,$71	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$71	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$71	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$51,$21,$C1,$71	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F8	; JMP
		.WORD	byte_99E76
_unused_0:
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
byte_99EE6:
		.BYTE	$C1	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$A1,$B1	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$01,$21,$C1,$01	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$B1,$C1	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$71,$C1,$71,$91,$C1,$B3 ;	DATA
		.BYTE	$F3	; RET
byte_99EFA:
		.BYTE	$D4	; CMDD4
		.BYTE	$71,$C1,$71,$C1,$21,$C1,$21,$C1 ;	DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$70,$C0,$72,$C0,$23,$C9 ;	DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$51,$C1,$51,$C1,$51,$C1 ;	DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$41,$51,$C1,$73,$C5 ; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$71,$C1,$71,$C1,$21,$C1,$21,$C1 ;	DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$70,$C0,$72,$C0,$23,$C9 ;	DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$97	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$01,$C1	; DATA
		.BYTE	$F3	; RET
byte_99F2D:
		.BYTE	$C3	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$01,$C1,$01,$C1,$31,$C1 ;	DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$21,$C1,$21	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$A9	; DATA
		.BYTE	$F3	; RET
_apu_mus05_B:
		.BYTE	$E2,$00	; CMDE2
		.BYTE	$E1,$03	; CMDE1
		.BYTE	$E0,$04	; CMDE0
		.BYTE	$E9,$09	; CMDE9
		.BYTE	$D9,$ED	; CMDD9
		.BYTE	$DB,$FF	; CMDDB
		.BYTE	$C2	; DATA
		.BYTE	$F8	; JMP
		.WORD	byte_99E76
_apu_mus05_C:
		.BYTE	$E2,$04	; CMDE2
		.BYTE	$E1,$00	; CMDE1
		.BYTE	$E0,$04	; CMDE0
		.BYTE	$E9,$00	; CMDE9
		.BYTE	$D9,$05	; CMDD9
byte_99F56:
		.BYTE	$F0,$02	; LOOP_START
		.BYTE	$F2	; JSR
		.WORD	byte_99FEC
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F0,$02	; LOOP_START
		.BYTE	$F2	; JSR
		.WORD	byte_99FF9
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F0,$02	; LOOP_START
		.BYTE	$F2	; JSR
		.WORD	byte_99FEC
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F2	; JSR
		.WORD	byte_99FF9
		.BYTE	$D2	; CMDD2
		.BYTE	$51,$C1	; DATA
		.BYTE	$F2	; JSR
		.WORD	byte_9A01F
		.BYTE	$D3	; CMDD3
		.BYTE	$51	; DATA
		.BYTE	$D2	; CMDD2
		.BYTE	$51	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$21,$61	; DATA
		.BYTE	$D2	; CMDD2
		.BYTE	$61	; DATA
		.BYTE	$F0,$02	; LOOP_START
		.BYTE	$F2	; JSR
		.WORD	byte_99FEC
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F2	; JSR
		.WORD	byte_99FF9
		.BYTE	$F0,$03	; LOOP_START
		.BYTE	$F2	; JSR
		.WORD	byte_99FEC
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F2	; JSR
		.WORD	byte_99FF9
		.BYTE	$F0,$03	; LOOP_START
		.BYTE	$F2	; JSR
		.WORD	byte_99FEC
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F2	; JSR
		.WORD	byte_99FF9
		.BYTE	$F0,$03	; LOOP_START
		.BYTE	$F2	; JSR
		.WORD	byte_99FEC
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F2	; JSR
		.WORD	byte_99FF9
		.BYTE	$F2	; JSR
		.WORD	byte_99FEC
		.BYTE	$F2	; JSR
		.WORD	byte_9A006
		.BYTE	$D3	; CMDD3
		.BYTE	$00,$C0,$01	; DATA
		.BYTE	$F2	; JSR
		.WORD	byte_9A01F
		.BYTE	$D3	; CMDD3
		.BYTE	$01	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$71	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$03	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$03,$71	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$01	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$01	; DATA
		.BYTE	$D2	; CMDD2
		.BYTE	$A1	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$A3,$A1	; DATA
		.BYTE	$F2	; JSR
		.WORD	byte_9A006
		.BYTE	$F0,$02	; LOOP_START
		.BYTE	$D3	; CMDD3
		.BYTE	$00,$C0,$01	; DATA
		.BYTE	$F2	; JSR
		.WORD	byte_9A01F
		.BYTE	$D3	; CMDD3
		.BYTE	$01	; DATA
		.BYTE	$D2	; CMDD2
		.BYTE	$A0,$C0,$A1	; DATA
		.BYTE	$F2	; JSR
		.WORD	byte_9A01F
		.BYTE	$D2	; CMDD2
		.BYTE	$A1	; DATA
		.BYTE	$D2	; CMDD2
		.BYTE	$80,$C0,$81	; DATA
		.BYTE	$F2	; JSR
		.WORD	byte_9A01F
		.BYTE	$D2	; CMDD2
		.BYTE	$81	; DATA
		.BYTE	$D2	; CMDD2
		.BYTE	$A0,$C0,$A1	; DATA
		.BYTE	$F2	; JSR
		.WORD	byte_9A01F
		.BYTE	$D2	; CMDD2
		.BYTE	$A1	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F8	; JMP
		.WORD	byte_99F56
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
byte_99FEC:
		.BYTE	$D2	; CMDD2
		.BYTE	$72,$C0	; DATA
		.BYTE	$F2	; JSR
		.WORD	byte_9A01F
		.BYTE	$D3	; CMDD3
		.BYTE	$21,$C1,$71,$61,$71 ; DATA
		.BYTE	$F3	; RET
byte_99FF9:
		.BYTE	$D2	; CMDD2
		.BYTE	$52,$C0	; DATA
		.BYTE	$F2	; JSR
		.WORD	byte_9A01F
		.BYTE	$D3	; CMDD3
		.BYTE	$01,$C1,$51,$41,$51 ; DATA
		.BYTE	$F3	; RET
byte_9A006:
		.BYTE	$D2	; CMDD2
		.BYTE	$82,$C0	; DATA
		.BYTE	$F2	; JSR
		.WORD	byte_9A01F
		.BYTE	$D3	; CMDD3
		.BYTE	$31,$C1,$81,$71,$81 ; DATA
		.BYTE	$D2	; CMDD2
		.BYTE	$A2,$C0	; DATA
		.BYTE	$F2	; JSR
		.WORD	byte_9A01F
		.BYTE	$D3	; CMDD3
		.BYTE	$51,$C1,$A1,$91,$A1 ; DATA
		.BYTE	$F3	; RET
byte_9A01F:
		.BYTE	$E0,$01	; CMDE0
		.BYTE	$D4	; CMDD4
		.BYTE	$F0,$08	; LOOP_START
		.BYTE	$00	; DATA
		.BYTE	$DA,$FF	; CMDDA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$DA,$08	; CMDDA
		.BYTE	$E0,$04	; CMDE0
		.BYTE	$F3	; RET
_apu_mus05_D:
		.BYTE	$E0,$04	; CMDE0
		.BYTE	$E9,$03	; CMDE9
		.BYTE	$F0,$06	; LOOP_START
		.BYTE	$F2	; JSR
		.WORD	byte_9A06B
		.BYTE	$E9,$03	; CMDE9
		.BYTE	$01	; DATA
		.BYTE	$E9,$06	; CMDE9
		.BYTE	$31	; DATA
		.BYTE	$E9,$03	; CMDE9
		.BYTE	$21	; DATA
		.BYTE	$E9,$06	; CMDE9
		.BYTE	$31	; DATA
		.BYTE	$E9,$03	; CMDE9
		.BYTE	$01,$21,$21,$21	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F2	; JSR
		.WORD	byte_9A06B
		.BYTE	$E9,$06	; CMDE9
		.BYTE	$11	; DATA
		.BYTE	$E9,$03	; CMDE9
		.BYTE	$21,$21	; DATA
		.BYTE	$E9,$06	; CMDE9
		.BYTE	$11	; DATA
		.BYTE	$E9,$03	; CMDE9
		.BYTE	$21,$21	; DATA
		.BYTE	$E9,$06	; CMDE9
		.BYTE	$11	; DATA
		.BYTE	$E9,$03	; CMDE9
		.BYTE	$21	; DATA
		.BYTE	$F2	; JSR
		.WORD	byte_9A06B
		.BYTE	$F2	; JSR
		.WORD	byte_9A06B
		.BYTE	$F8	; JMP
		.WORD	_apu_mus05_D	; DATA
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
byte_9A06B:
		.BYTE	$F0,$03	; LOOP_START
		.BYTE	$01	; DATA
		.BYTE	$E9,$06	; CMDE9
		.BYTE	$31	; DATA
		.BYTE	$E9,$03	; CMDE9
		.BYTE	$21	; DATA
		.BYTE	$E9,$06	; CMDE9
		.BYTE	$31	; DATA
		.BYTE	$E9,$03	; CMDE9
		.BYTE	$01	; DATA
		.BYTE	$E9,$06	; CMDE9
		.BYTE	$31	; DATA
		.BYTE	$E9,$03	; CMDE9
		.BYTE	$21,$21	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F3	; RET
_apu_mus06:
		.BYTE	$0F
		.WORD	_apu_mus06_A
		.WORD	_apu_mus06_B
		.WORD	_apu_mus06_C
		.WORD	_apu_mus06_D
_apu_mus06_A:
		.BYTE	$E2,$00	; CMDE2
		.BYTE	$E1,$03	; CMDE1
		.BYTE	$E0,$06	; CMDE0
		.BYTE	$E9,$03	; CMDE9
		.BYTE	$D9,$F4	; CMDD9
		.BYTE	$CF,$CF	; DATA
byte_9A098:
		.BYTE	$F0,$02	; LOOP_START
		.BYTE	$F2	; JSR
		.WORD	byte_9A0FC
		.BYTE	$F0,$02	; LOOP_START
		.BYTE	$D4	; CMDD4
		.BYTE	$50,$70,$50,$70,$50,$C0,$71 ; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F2	; JSR
		.WORD	byte_9A0FC
		.BYTE	$F0,$02	; LOOP_START
		.BYTE	$D4	; CMDD4
		.BYTE	$50,$70,$50,$70,$50,$C0 ;	DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$01	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F2	; JSR
		.WORD	byte_9A10D
		.BYTE	$C1	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$71,$80,$C0,$90,$C0,$40,$50,$C0,$73,$C0 ;	DATA
		.BYTE	$F2	; JSR
		.WORD	byte_9A10D
		.BYTE	$D5	; CMDD5
		.BYTE	$70,$C0,$71,$50,$C0,$51,$40,$20,$30,$43,$C0 ; DATA
		.BYTE	$F2	; JSR
		.WORD	byte_9A11E
		.BYTE	$C1	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$A0	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$00	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$A0	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$00,$C1,$00,$20,$C0,$42,$01 ; DATA
		.BYTE	$F2	; JSR
		.WORD	byte_9A11E
		.BYTE	$C1	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$70,$90,$A0,$B0,$C1 ; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$02	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$00,$C3	; DATA
		.BYTE	$F8	; JMP
		.WORD	byte_9A098	; DATA
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
byte_9A0FC:
		.BYTE	$D4	; CMDD4
		.BYTE	$20,$40,$20,$40,$20,$C0,$70,$C0,$B1,$90,$C0,$70,$C0,$60,$C0 ; DATA
		.BYTE	$F3	; RET
byte_9A10D:
		.BYTE	$D5	; CMDD5
		.BYTE	$41,$20,$C0,$00,$C0 ; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$90,$C0	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$31,$20,$00,$C0	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$92	; DATA
		.BYTE	$F3	; RET
byte_9A11E:
		.BYTE	$D5	; CMDD5
		.BYTE	$50,$C0,$50,$C0,$30,$00,$C0,$50,$C0,$50,$C0,$50,$30,$00,$C0,$50 ;	DATA
		.BYTE	$F3	; RET
_apu_mus06_B:
		.BYTE	$E2,$00	; CMDE2
		.BYTE	$E1,$03	; CMDE1
		.BYTE	$E0,$06	; CMDE0
		.BYTE	$E9,$07	; CMDE9
		.BYTE	$D9,$F4	; CMDD9
		.BYTE	$F0,$02	; LOOP_START
		.BYTE	$F0,$04	; LOOP_START
		.BYTE	$D3	; CMDD3
		.BYTE	$B0,$C0	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F0,$04	; LOOP_START
		.BYTE	$D4	; CMDD4
		.BYTE	$00,$C0	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F1	; DO_LOOP
byte_9A149:
		.BYTE	$F0,$04	; LOOP_START
		.BYTE	$F0,$08	; LOOP_START
		.BYTE	$D3	; CMDD3
		.BYTE	$B0,$C0	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F0,$08	; LOOP_START
		.BYTE	$D3	; CMDD3
		.BYTE	$90,$C0	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F2	; JSR
		.WORD	byte_9A1A8
		.BYTE	$D4	; CMDD4
		.BYTE	$40,$C0,$40,$C0,$20,$C0,$20,$C0,$00,$C0,$00,$C0 ;	DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$70,$C0,$70,$C0	; DATA
		.BYTE	$F2	; JSR
		.WORD	byte_9A1A8
		.BYTE	$70,$C0,$70,$C0	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$70,$C0,$70,$C0	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$70,$C0,$70,$C0	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$70,$C0,$70,$C0	; DATA
		.BYTE	$F2	; JSR
		.WORD	byte_9A1B5
		.BYTE	$D4	; CMDD4
		.BYTE	$30,$C0,$30,$C0,$30,$C0,$30,$C0,$70,$C0,$70,$C0,$70,$C0,$70,$C0 ;	DATA
		.BYTE	$F2	; JSR
		.WORD	byte_9A1B5
		.BYTE	$D5	; CMDD5
		.BYTE	$02	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$00,$C1,$00,$C0,$03,$C3 ;	DATA
		.BYTE	$F8	; JMP
		.WORD	byte_9A149
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
byte_9A1A8:
		.BYTE	$F0,$04	; LOOP_START
		.BYTE	$D3	; CMDD3
		.BYTE	$90,$C0	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F0,$04	; LOOP_START
		.BYTE	$D4	; CMDD4
		.BYTE	$00,$C0	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F3	; RET
byte_9A1B5:
		.BYTE	$D4	; CMDD4
		.BYTE	$00,$C0,$00,$C0,$00,$C0,$00,$C0,$00,$C0,$00,$C0,$00,$C0,$00,$C0 ;	DATA
		.BYTE	$F3	; RET
_apu_mus06_C:
		.BYTE	$E2,$04	; CMDE2
		.BYTE	$E1,$03	; CMDE1
		.BYTE	$E0,$06	; CMDE0
		.BYTE	$E9,$00	; CMDE9
		.BYTE	$F0,$02	; LOOP_START
		.BYTE	$D3	; CMDD3
		.BYTE	$71	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$B0,$C0	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$21	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$70,$C0	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$91	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$90,$C0	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$21	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$20,$C0	; DATA
		.BYTE	$F1	; DO_LOOP
byte_9A1E6:
		.BYTE	$F2	; JSR
		.WORD	byte_9A280
		.BYTE	$F2	; JSR
		.WORD	byte_9A295
		.BYTE	$F2	; JSR
		.WORD	byte_9A280
		.BYTE	$F0,$02	; LOOP_START
		.BYTE	$D3	; CMDD3
		.BYTE	$51	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$90,$C0	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$01	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$50,$C0	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F2	; JSR
		.WORD	byte_9A280
		.BYTE	$F2	; JSR
		.WORD	byte_9A295
		.BYTE	$F2	; JSR
		.WORD	byte_9A280
		.BYTE	$D3	; CMDD3
		.BYTE	$51	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$90,$C0	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$01	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$50,$C0	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$51	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$90,$C0	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$01	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$50	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$40	; DATA
		.BYTE	$F2	; JSR
		.WORD	byte_9A2A3
		.BYTE	$D3	; CMDD3
		.BYTE	$71	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$70,$C0	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$51	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$50,$C0	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$41	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$40,$C0	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$01	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$00,$C0	; DATA
		.BYTE	$F2	; JSR
		.WORD	byte_9A2A3
		.BYTE	$F0,$02	; LOOP_START
		.BYTE	$D3	; CMDD3
		.BYTE	$71	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$70,$C0	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$D3	; CMDD3
		.BYTE	$70	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$70	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$70	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$70	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$50	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$50	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$40	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$40	; DATA
		.BYTE	$F2	; JSR
		.WORD	byte_9A2B4
		.BYTE	$D3	; CMDD3
		.BYTE	$81	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$80	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$80	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$00	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$80	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$30	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$A0	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$01	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$40	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$00,$00	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$40	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$01	; DATA
		.BYTE	$F2	; JSR
		.WORD	byte_9A2B4
		.BYTE	$00	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$B0	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$00	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$B0	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$01	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$00,$C0,$01,$41,$51,$61 ;	DATA
		.BYTE	$F8	; JMP
		.WORD	byte_9A1E6
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
byte_9A280:
		.BYTE	$D3	; CMDD3
		.BYTE	$71	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$B0,$C0	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$21	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$70,$C0	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$71	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$B0,$C0	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$21	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$20,$C0	; DATA
		.BYTE	$F3	; RET
byte_9A295:
		.BYTE	$F0,$02	; LOOP_START
		.BYTE	$D3	; CMDD3
		.BYTE	$51	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$90,$C0	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$01	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$50,$C0	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F3	; RET
byte_9A2A3:
		.BYTE	$F0,$02	; LOOP_START
		.BYTE	$D3	; CMDD3
		.BYTE	$51	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$50,$C0	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F0,$02	; LOOP_START
		.BYTE	$D3	; CMDD3
		.BYTE	$61	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$60,$C0	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F3	; RET
byte_9A2B4:
		.BYTE	$D3	; CMDD3
		.BYTE	$51	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$50	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$50,$80	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$50	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$00	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$00,$51	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$50	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$50,$80	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$50	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$01	; DATA
		.BYTE	$F3	; RET
_apu_mus06_D:
		.BYTE	$E9,$08	; CMDE9
		.BYTE	$E0,$06	; CMDE0
		.BYTE	$D2	; CMDD2
		.BYTE	$11,$30,$30	; DATA
		.BYTE	$F8	; JMP
		.WORD	_apu_mus06_D
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus07:
		.BYTE	$0F
		.WORD	_apu_mus07_A
		.WORD	_apu_mus07_B
		.WORD	_apu_mus07_C
		.WORD	_apu_mus07_D
_apu_mus07_A:
		.BYTE	$E2,$00	; CMDE2
		.BYTE	$E1,$03	; CMDE1
		.BYTE	$E0,$06	; CMDE0
		.BYTE	$E9,$02	; CMDE9
		.BYTE	$D9,$F2	; CMDD9
byte_9A2EC:
		.BYTE	$F0,$02	; LOOP_START
		.BYTE	$D4	; CMDD4
		.BYTE	$F0,$06	; LOOP_START
		.BYTE	$41,$30	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$41,$50,$C1,$40	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$C2	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$91,$C0,$81,$90,$C1 ; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$00	; DATA
		.BYTE	$E8	; CMDE8
		.BYTE	$F2	; JSR
		.WORD	byte_9A399
		.BYTE	$E1,$02	; CMDE1
		.BYTE	$C1	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$40	; DATA
		.BYTE	$E8	; CMDE8
		.BYTE	$F0,$03	; LOOP_START
		.BYTE	$D5	; CMDD5
		.BYTE	$41	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$80	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$D5	; CMDD5
		.BYTE	$31,$40,$C1	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$B2,$80,$C2	; DATA
		.BYTE	$E1,$03	; CMDE1
		.BYTE	$42,$91,$C0,$81,$90,$C1 ;	DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$00	; DATA
		.BYTE	$E8	; CMDE8
		.BYTE	$F2	; JSR
		.WORD	byte_9A399
		.BYTE	$E1,$02	; CMDE1
		.BYTE	$D5	; CMDD5
		.BYTE	$C1,$50	; DATA
		.BYTE	$E8	; CMDE8
		.BYTE	$F0,$03	; LOOP_START
		.BYTE	$D5	; CMDD5
		.BYTE	$51	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$80	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$D5	; CMDD5
		.BYTE	$31,$40,$C1,$92,$C3 ; DATA
		.BYTE	$F2	; JSR
		.WORD	byte_9A3A5
		.BYTE	$E1,$03	; CMDE1
		.BYTE	$D5	; CMDD5
		.BYTE	$01	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$B0	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$01	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$B0	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$01	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$90,$C1	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$12	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$B0	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$11	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$B0	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$11	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$A0,$C1	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$30	; DATA
		.BYTE	$E8	; CMDE8
		.BYTE	$F0,$04	; LOOP_START
		.BYTE	$31,$40	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$31,$C0,$41	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$B3,$C2	; DATA
		.BYTE	$E1,$02	; CMDE1
		.BYTE	$F0,$02	; LOOP_START
		.BYTE	$D3	; CMDD3
		.BYTE	$91,$B0	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$01	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$90	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$31,$42,$00	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$92,$41,$92,$40,$81,$90 ;	DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$E1,$03	; CMDE1
		.BYTE	$D5	; CMDD5
		.BYTE	$01	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$90,$B1	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$02	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$90,$B1	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$00,$31,$40,$31,$40,$C1,$43 ; DATA
		.BYTE	$F8	; JMP
		.WORD	byte_9A2EC
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
byte_9A399:
		.BYTE	$D5	; CMDD5
		.BYTE	$00,$C0,$00	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$B1,$C0,$A1,$C0,$B1,$C0 ;	DATA
		.BYTE	$F3	; RET
byte_9A3A5:
		.BYTE	$E1,$00	; CMDE1
		.BYTE	$F0,$02	; LOOP_START
		.BYTE	$D5	; CMDD5
		.BYTE	$91,$40,$81,$40,$C1,$70,$42 ; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$62,$21,$43,$C2	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F3	; RET
_apu_mus07_B:
		.BYTE	$E2,$00	; CMDE2
		.BYTE	$E1,$03	; CMDE1
		.BYTE	$E0,$06	; CMDE0
		.BYTE	$E9,$06	; CMDE9
		.BYTE	$D9,$F2	; CMDD9
byte_9A3C2:
		.BYTE	$F0,$02	; LOOP_START
		.BYTE	$D4	; CMDD4
		.BYTE	$F0,$06	; LOOP_START
		.BYTE	$01,$C0	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$01,$C2,$00	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F2	; JSR
		.WORD	byte_9A44E
		.BYTE	$E1,$02	; CMDE1
		.BYTE	$C1	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$80	; DATA
		.BYTE	$E8	; CMDE8
		.BYTE	$F0,$03	; LOOP_START
		.BYTE	$81,$40	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$81,$80,$C1,$82,$40,$C2 ;	DATA
		.BYTE	$E1,$03	; CMDE1
		.BYTE	$F2	; JSR
		.WORD	byte_9A44E
		.BYTE	$E1,$02	; CMDE1
		.BYTE	$C1,$80	; DATA
		.BYTE	$E8	; CMDE8
		.BYTE	$F0,$03	; LOOP_START
		.BYTE	$81,$50	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$81,$80,$C1	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$42,$C3	; DATA
		.BYTE	$E1,$00	; CMDE1
		.BYTE	$DB,$05	; CMDDB
		.BYTE	$DA,$F4	; CMDDA
		.BYTE	$F2	; JSR
		.WORD	byte_9A3A5
		.BYTE	$DA,$0C	; CMDDA
		.BYTE	$DB,$00	; CMDDB
		.BYTE	$E1,$03	; CMDE1
		.BYTE	$D4	; CMDD4
		.BYTE	$21,$C2,$26,$31,$C2,$36,$C1,$40 ;	DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$B1,$80,$41,$80,$B1 ; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$40,$C1,$93,$81,$C0,$91,$C0 ; DATA
		.BYTE	$E1,$03	; CMDE1
		.BYTE	$EA,$02	; CMDEA
		.BYTE	$F0,$02	; LOOP_START
		.BYTE	$C1	; DATA
		.BYTE	$F0,$02	; LOOP_START
		.BYTE	$D6	; CMDD6
		.BYTE	$00	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$B1,$90	; DATA
		.BYTE	$D6	; CMDD6
		.BYTE	$01	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$B0,$91	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$D6	; CMDD6
		.BYTE	$00	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$B1,$90	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$EA,$FE	; CMDEA
		.BYTE	$E1,$00	; CMDE1
		.BYTE	$D4	; CMDD4
		.BYTE	$41,$40,$41,$42,$40,$41,$40,$91,$90,$91,$90,$C1,$83 ; DATA
		.BYTE	$F8	; JMP
		.WORD	byte_9A3C2
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
byte_9A44E:
		.BYTE	$C2	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$41,$C0,$41,$40,$C1,$41,$C0,$40,$41,$C0,$41,$C0,$41,$C0 ;	DATA
		.BYTE	$F3	; RET
_apu_mus07_C:
		.BYTE	$E2,$03	; CMDE2
		.BYTE	$E1,$03	; CMDE1
		.BYTE	$E0,$06	; CMDE0
		.BYTE	$E9,$00	; CMDE9
		.BYTE	$D9,$FE	; CMDD9
byte_9A469:
		.BYTE	$F0,$06	; LOOP_START
		.BYTE	$F2	; JSR
		.WORD	byte_9A4D0
		.BYTE	$F1	; DO_LOOP
		.BYTE	$D3	; CMDD3
		.BYTE	$45,$41,$C0,$41,$C0 ; DATA
		.BYTE	$F2	; JSR
		.WORD	byte_9A4D6
		.BYTE	$F0,$02	; LOOP_START
		.BYTE	$F2	; JSR
		.WORD	byte_9A4D0
		.BYTE	$F1	; DO_LOOP
		.BYTE	$D3	; CMDD3
		.BYTE	$25,$21,$C0,$21,$C0 ; DATA
		.BYTE	$F2	; JSR
		.WORD	byte_9A4D6
		.BYTE	$F2	; JSR
		.WORD	byte_9A4D0
		.BYTE	$F2	; JSR
		.WORD	byte_9A4DF
		.BYTE	$F2	; JSR
		.WORD	byte_9A4D0
		.BYTE	$F2	; JSR
		.WORD	byte_9A4DF
		.BYTE	$D3	; CMDD3
		.BYTE	$22,$42,$52,$22,$32,$52,$72,$32,$42 ; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$42	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$42	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$42	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$41,$C0	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$41	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$42,$60,$82	; DATA
		.BYTE	$F0,$02	; LOOP_START
		.BYTE	$D3	; CMDD3
		.BYTE	$92,$92,$72,$72	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$62,$62,$52,$52	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$D3	; CMDD3
		.BYTE	$22	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$22	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$22	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$22	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$42	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$42	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$42	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$41	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$40	; DATA
		.BYTE	$F8	; JMP
		.WORD	byte_9A469
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
byte_9A4D0:
		.BYTE	$D3	; CMDD3
		.BYTE	$92,$82,$72,$62	; DATA
		.BYTE	$F3	; RET
byte_9A4D6:
		.BYTE	$D3	; CMDD3
		.BYTE	$41,$C2,$42	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$40	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$42	; DATA
		.BYTE	$F3	; RET
byte_9A4DF:
		.BYTE	$D3	; CMDD3
		.BYTE	$21,$C2,$42,$40	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$40,$C1	; DATA
		.BYTE	$F3	; RET
_apu_mus07_D:
		.BYTE	$E0,$06	; CMDE0
		.BYTE	$E9,$06	; CMDE9
byte_9A4EC:
		.BYTE	$12,$31,$30,$12,$31,$30
		.BYTE	$F8	; JMP
		.WORD	byte_9A4EC
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus08:
		.BYTE	$0F
		.WORD	_apu_mus08_A
		.WORD	_apu_mus08_B
		.WORD	_apu_mus08_C
		.WORD	_apu_mus08_D
_apu_mus08_A:
		.BYTE	$E2,$00	; CMDE2
		.BYTE	$E1,$00	; CMDE1
		.BYTE	$E0,$03	; CMDE0
		.BYTE	$E9,$00	; CMDE9
		.BYTE	$D9,$F4	; CMDD9
byte_9A50A:
		.BYTE	$F2	; JSR
		.WORD	byte_9A594
		.BYTE	$D5	; CMDD5
		.BYTE	$21,$51,$C1,$51,$51,$01,$C1,$01,$31,$21,$01 ; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$A1	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$01,$21	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$91,$C1	; DATA
		.BYTE	$F2	; JSR
		.WORD	byte_9A594
		.BYTE	$D5	; CMDD5
		.BYTE	$51,$01,$31,$01,$31,$21,$01 ; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$A1,$91,$51,$71,$91,$51,$C5 ; DATA
		.BYTE	$F0,$02	; LOOP_START
		.BYTE	$D3	; CMDD3
		.BYTE	$93	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$01,$C1,$07,$23,$01,$C1,$07 ; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$23,$51,$C1,$51,$C1,$51,$C1,$73,$51,$C1,$57 ; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$91,$C1,$91,$C1,$93,$71,$C1,$93,$71,$C1,$7B,$01,$C1,$21,$C1,$41 ;	DATA
		.BYTE	$C1,$57
		.BYTE	$D5	; CMDD5
		.BYTE	$53,$C3	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F2	; JSR
		.WORD	byte_9A5A5
		.BYTE	$D5	; CMDD5
		.BYTE	$51,$01,$31,$21,$01 ; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$A1,$91,$A1	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$01	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$91,$A1,$71,$91,$A1,$91,$C1 ; DATA
		.BYTE	$F2	; JSR
		.WORD	byte_9A5A5
		.BYTE	$D5	; CMDD5
		.BYTE	$51,$01,$31,$21,$01 ; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$A1,$91,$A1	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$01	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$91,$A1,$71,$51,$C5 ; DATA
		.BYTE	$F8	; JMP
		.WORD	byte_9A50A
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
byte_9A594:
		.BYTE	$D4	; CMDD4
		.BYTE	$51,$C1,$53,$71,$51,$C1,$51,$71,$91,$C1,$91,$71,$51,$C1,$51 ; DATA
		.BYTE	$F3	; RET
byte_9A5A5:
		.BYTE	$F0,$04	; LOOP_START
		.BYTE	$D5	; CMDD5
		.BYTE	$40,$50,$C1,$51,$C1 ; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F3	; RET
_apu_mus08_B:
		.BYTE	$E2,$03	; CMDE2
		.BYTE	$E1,$00	; CMDE1
		.BYTE	$E0,$06	; CMDE0
		.BYTE	$E9,$09	; CMDE9
byte_9A5B7:
		.BYTE	$F0,$05	; LOOP_START
		.BYTE	$F2	; JSR
		.WORD	byte_9A5D4
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F2	; JSR
		.WORD	byte_9A5E3
		.BYTE	$F0,$02	; LOOP_START
		.BYTE	$F2	; JSR
		.WORD	byte_9A5D4
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F2	; JSR
		.WORD	byte_9A5E3
		.BYTE	$F0,$05	; LOOP_START
		.BYTE	$F2	; JSR
		.WORD	byte_9A5D4
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F8	; JMP
		.WORD	byte_9A5B7
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
byte_9A5D4:
		.BYTE	$F0,$02	; LOOP_START
		.BYTE	$D3	; CMDD3
		.BYTE	$51,$90	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$00	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$90	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$00,$20,$00	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F3	; RET
byte_9A5E3:
		.BYTE	$F0,$02	; LOOP_START
		.BYTE	$D3	; CMDD3
		.BYTE	$A1	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$20,$50,$20,$50,$70,$50 ;	DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F0,$02	; LOOP_START
		.BYTE	$D4	; CMDD4
		.BYTE	$01,$40,$70,$40,$70,$90,$70 ; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F3	; RET
_apu_mus08_C:
		.BYTE	$E2,$03	; CMDE2
		.BYTE	$E1,$03	; CMDE1
		.BYTE	$E0,$03	; CMDE0
		.BYTE	$E9,$00	; CMDE9
byte_9A603:
		.BYTE	$F0,$03	; LOOP_START
		.BYTE	$F2	; JSR
		.WORD	byte_9A643
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F0,$02	; LOOP_START
		.BYTE	$F2	; JSR
		.WORD	byte_9A653
		.BYTE	$F2	; JSR
		.WORD	byte_9A643
		.BYTE	$F0,$02	; LOOP_START
		.BYTE	$D3	; CMDD3
		.BYTE	$23	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$90,$A0,$A1	; DATA
		.BYTE	$D2	; CMDD2
		.BYTE	$A3	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$90,$A0,$A1	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F0,$02	; LOOP_START
		.BYTE	$D3	; CMDD3
		.BYTE	$43	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$B0	; DATA
		.BYTE	$D6	; CMDD6
		.BYTE	$00,$01	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$03	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$B0	; DATA
		.BYTE	$D6	; CMDD6
		.BYTE	$00,$01	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F0,$02	; LOOP_START
		.BYTE	$F2	; JSR
		.WORD	byte_9A653
		.BYTE	$F2	; JSR
		.WORD	byte_9A643
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F2	; JSR
		.WORD	byte_9A653
		.BYTE	$F8	; JMP
		.WORD	byte_9A603
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
byte_9A643:
		.BYTE	$F0,$02	; LOOP_START
		.BYTE	$D3	; CMDD3
		.BYTE	$53	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$40,$50,$51	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$03	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$40,$50,$51	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F3	; RET
byte_9A653:
		.BYTE	$D3	; CMDD3
		.BYTE	$53	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$40,$50,$51	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$03	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$40,$50,$51	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$53,$03,$23,$43	; DATA
		.BYTE	$F3	; RET
_apu_mus08_D:
		.BYTE	$E0,$06	; CMDE0
		.BYTE	$E9,$00	; CMDE9
byte_9A669:
		.BYTE	$F0,$0E	; LOOP_START
		.BYTE	$01,$20,$20	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$31,$21,$21,$21	; DATA
		.BYTE	$F8	; JMP
		.WORD	byte_9A669
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus09:
		.BYTE	$0F
		.WORD	_apu_mus09_A
		.WORD	_apu_mus09_B
		.WORD	_apu_mus09_C
		.WORD	_apu_mus09_D
_apu_mus09_A:
		.BYTE	$E2,$00	; CMDE2
		.BYTE	$E1,$03	; CMDE1
		.BYTE	$E0,$07	; CMDE0
		.BYTE	$E9,$00	; CMDE9
		.BYTE	$D9,$F4	; CMDD9
byte_9A68B:
		.BYTE	$F0,$02	; LOOP_START
		.BYTE	$D4	; CMDD4
		.BYTE	$90,$C0,$40,$C0,$70,$C0,$40,$90,$C0,$90,$C0,$40,$70,$C0,$40,$C0 ;	DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$90,$C0,$40,$C0,$70,$C0,$40,$90,$C0,$90,$C0,$40 ;	DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$01	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$B0,$C0	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F0,$02	; LOOP_START
		.BYTE	$F2	; JSR
		.WORD	byte_9A713
		.BYTE	$C1	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$01	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$B0,$C0,$90,$C0	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$00	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$B0,$C0,$92,$70,$C0 ; DATA
		.BYTE	$F2	; JSR
		.WORD	byte_9A713
		.BYTE	$E1,$00	; CMDE1
		.BYTE	$C1	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$40,$20,$40,$70,$C1,$40,$20,$40 ;	DATA
		.BYTE	$E1,$03	; CMDE1
		.BYTE	$E2,$04	; CMDE2
		.BYTE	$70	; DATA
		.BYTE	$E8	; CMDE8
		.BYTE	$E0,$01	; CMDE0
		.BYTE	$73	; DATA
		.BYTE	$E8	; CMDE8
		.BYTE	$F0,$0C	; LOOP_START
		.BYTE	$71	; DATA
		.BYTE	$DA,$FF	; CMDDA
		.BYTE	$EA,$01	; CMDEA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$DA,$0C	; CMDDA
		.BYTE	$EA,$F4	; CMDEA
		.BYTE	$E0,$07	; CMDE0
		.BYTE	$E2,$00	; CMDE2
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F2	; JSR
		.WORD	byte_9A722
		.BYTE	$C1	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$20,$00,$20,$41,$C0,$70,$40,$70,$90,$C3 ;	DATA
		.BYTE	$F2	; JSR
		.WORD	byte_9A722
		.BYTE	$C1,$20,$00,$20,$41,$C0 ;	DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$70,$90,$C0,$90,$C3 ; DATA
		.BYTE	$F8	; JMP
		.WORD	byte_9A68B
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
byte_9A713:
		.BYTE	$C1	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$90,$70,$90,$C2,$40,$20,$C0,$40,$C0,$70,$C0,$90 ;	DATA
		.BYTE	$F3	; RET
byte_9A722:
		.BYTE	$D5	; CMDD5
		.BYTE	$90,$70,$90,$40,$C0,$70,$40,$00,$20,$C0,$00,$C0,$20,$42 ;	DATA
		.BYTE	$F3	; RET
_apu_mus09_B:
		.BYTE	$E2,$00	; CMDE2
		.BYTE	$E1,$03	; CMDE1
		.BYTE	$E0,$07	; CMDE0
		.BYTE	$E9,$05	; CMDE9
		.BYTE	$D9,$F4	; CMDD9
byte_9A73C:
		.BYTE	$F0,$02	; LOOP_START
		.BYTE	$F0,$03	; LOOP_START
		.BYTE	$D3	; CMDD3
		.BYTE	$90,$C0,$90	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$00	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$70,$90	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$00	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$70	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$90,$C0,$90	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$00,$41,$21	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F0,$02	; LOOP_START
		.BYTE	$F2	; JSR
		.WORD	byte_9A7A0
		.BYTE	$C1	; DATA
		.BYTE	$F0,$04	; LOOP_START
		.BYTE	$D3	; CMDD3
		.BYTE	$90,$C0	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$D4	; CMDD4
		.BYTE	$40,$21,$42	; DATA
		.BYTE	$F2	; JSR
		.WORD	byte_9A7A0
		.BYTE	$E1,$00	; CMDE1
		.BYTE	$F0,$02	; LOOP_START
		.BYTE	$C1	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$40,$20,$40,$70	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$E8	; CMDE8
		.BYTE	$73	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F0,$02	; LOOP_START
		.BYTE	$D3	; CMDD3
		.BYTE	$90,$C0,$91	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$70,$90,$C0,$01,$20,$C0,$00,$20,$40,$71 ;	DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$20,$C0,$21	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$20	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$20,$C0,$41	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$40,$C0	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$41,$70,$90,$C0	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F8	; JMP
		.WORD	byte_9A73C
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
byte_9A7A0:
		.BYTE	$C1	; DATA
		.BYTE	$F0,$05	; LOOP_START
		.BYTE	$D3	; CMDD3
		.BYTE	$90,$C0	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$90	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$01	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$90	; DATA
		.BYTE	$F3	; RET
_apu_mus09_C:
		.BYTE	$E2,$03	; CMDE2
		.BYTE	$E1,$03	; CMDE1
		.BYTE	$E0,$07	; CMDE0
		.BYTE	$E9,$00	; CMDE9
byte_9A7B5:
		.BYTE	$F0,$02	; LOOP_START
		.BYTE	$D2	; CMDD2
		.BYTE	$91	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$40	; DATA
		.BYTE	$D2	; CMDD2
		.BYTE	$90,$C0,$90	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$40	; DATA
		.BYTE	$D2	; CMDD2
		.BYTE	$90	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$00,$C0,$01,$51,$01 ; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$21,$70,$20,$C0,$20,$70,$20 ; DATA
		.BYTE	$D2	; CMDD2
		.BYTE	$70,$C0,$71	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$21	; DATA
		.BYTE	$D2	; CMDD2
		.BYTE	$71	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F0,$04	; LOOP_START
		.BYTE	$D2	; CMDD2
		.BYTE	$91	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$40	; DATA
		.BYTE	$D2	; CMDD2
		.BYTE	$90,$C0,$90	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$40	; DATA
		.BYTE	$D2	; CMDD2
		.BYTE	$90	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$00,$C0,$01,$71,$01 ; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$21,$60,$20,$C0,$20,$60,$20,$40,$C0,$41,$71,$91 ;	DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F0,$02	; LOOP_START
		.BYTE	$D2	; CMDD2
		.BYTE	$90,$C0,$91	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$70,$90,$C0,$01,$20,$C0,$00,$20,$40,$71 ;	DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$20,$C0,$21	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$20	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$20,$C0,$41	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$40,$C0	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$41,$70,$90,$C0	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F8	; JMP
		.WORD	byte_9A7B5
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus09_D:
		.BYTE	$E0,$07	; CMDE0
		.BYTE	$E9,$00	; CMDE9
byte_9A829:
		.BYTE	$F0,$03	; LOOP_START
		.BYTE	$01,$01,$23,$03,$21,$01 ;	DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$01,$01,$23,$01,$21,$20,$21,$20 ;	DATA
		.BYTE	$F8	; JMP
		.WORD	byte_9A829
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus0A:
		.BYTE	$0F
		.WORD	_apu_mus0A_A
		.WORD	_apu_mus0A_B
		.WORD	_apu_mus0A_C
		.WORD	_apu_mus0A_D
_apu_mus0A_A:
		.BYTE	$E2,$00	; CMDE2
		.BYTE	$E1,$03	; CMDE1
		.BYTE	$E0,$08	; CMDE0
		.BYTE	$E9,$03	; CMDE9
		.BYTE	$D9,$F2	; CMDD9
byte_9A852:
		.BYTE	$F0,$02	; LOOP_START
		.BYTE	$F2	; JSR
		.WORD	byte_9A8D3
		.BYTE	$D4	; CMDD4
		.BYTE	$50,$70,$C0,$03,$C0 ; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$00	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$B0,$C0,$72,$C1	; DATA
		.BYTE	$F2	; JSR
		.WORD	byte_9A8D3
		.BYTE	$D4	; CMDD4
		.BYTE	$50,$70,$C0,$03,$C0 ; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$00	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$B0	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$00	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$74	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$E1,$01	; CMDE1
		.BYTE	$D4	; CMDD4
		.BYTE	$82	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$02,$31,$22	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$A4,$B1	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$20,$51,$21,$34,$30,$20,$30,$09 ;	DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$80	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$00,$30,$00,$31,$58 ; DATA
		.BYTE	$E1,$00	; CMDE1
		.BYTE	$C0,$70,$C0,$50,$70,$50,$71 ; DATA
		.BYTE	$E1,$03	; CMDE1
		.BYTE	$51,$30,$01,$50,$30,$01,$32,$80,$C0,$70,$C0,$51,$30,$01,$50,$30 ;	DATA
		.BYTE	$01,$32
		.BYTE	$D6	; CMDD6
		.BYTE	$00	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$A0,$80,$70,$51,$30,$01,$50,$30,$01,$32,$A0,$C0,$80,$C0,$70,$50 ;	DATA
		.BYTE	$30,$50,$30,$00,$32,$00,$30,$00,$20,$20,$C0,$50
		.BYTE	$F8	; JMP
		.WORD	byte_9A852
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
byte_9A8D3:
		.BYTE	$D4	; CMDD4
		.BYTE	$70,$50,$40,$00,$C0 ; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$70	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$00,$C0,$30,$C0,$50,$C0,$30,$C0,$00,$C0 ;	DATA
		.BYTE	$F3	; RET
_apu_mus0A_B:
		.BYTE	$E2,$00	; CMDE2
		.BYTE	$E1,$03	; CMDE1
		.BYTE	$E0,$08	; CMDE0
		.BYTE	$E9,$06	; CMDE9
		.BYTE	$D9,$F2	; CMDD9
byte_9A8F1:
		.BYTE	$F0,$04	; LOOP_START
		.BYTE	$C1	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$70,$C1,$70,$C0,$70,$C1,$A0,$C1,$A0,$C0,$A0,$C1 ;	DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$90,$C1,$90,$C0,$90,$C1,$B0,$C1,$B0 ; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$00,$C0	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$C1	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$70,$C0,$70,$50,$C0,$70,$C0,$70,$50,$C0,$70,$50,$C0,$70,$C1,$70 ;	DATA
		.BYTE	$C0,$70,$50,$C0,$70,$C0,$00,$30,$70
		.BYTE	$D5	; CMDD5
		.BYTE	$00	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$70,$30,$70,$C1,$80,$C0,$80,$70,$C0,$80,$C0,$70,$80,$C0,$80,$70 ;	DATA
		.BYTE	$C0,$80,$C1,$A0,$C0,$A0,$80,$C0,$A0,$C0
		.BYTE	$E1,$00	; CMDE1
		.BYTE	$D5	; CMDD5
		.BYTE	$30,$C0,$20,$30,$20,$31 ;	DATA
		.BYTE	$E1,$03	; CMDE1
		.BYTE	$D4	; CMDD4
		.BYTE	$51,$30,$01,$50,$30,$01,$32,$80,$C0,$70,$C0,$51,$30,$01,$50,$30 ;	DATA
		.BYTE	$01,$32
		.BYTE	$D5	; CMDD5
		.BYTE	$00	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$A0,$80,$70,$51,$30,$01,$50,$30,$01,$32,$A0,$C0,$80,$C0,$70,$50 ;	DATA
		.BYTE	$30,$50,$30,$00,$32,$00,$30,$00,$20,$20,$C0,$50
		.BYTE	$F8	; JMP
		.WORD	byte_9A8F1
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus0A_C:
		.BYTE	$E2,$03	; CMDE2
		.BYTE	$E1,$03	; CMDE1
		.BYTE	$E0,$08	; CMDE0
		.BYTE	$E9,$01	; CMDE9
		.BYTE	$D9,$FE	; CMDD9
byte_9A993:
		.BYTE	$F0,$04	; LOOP_START
		.BYTE	$F0,$04	; LOOP_START
		.BYTE	$D3	; CMDD3
		.BYTE	$00	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$00	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F0,$04	; LOOP_START
		.BYTE	$D3	; CMDD3
		.BYTE	$30	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$30	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F0,$04	; LOOP_START
		.BYTE	$D3	; CMDD3
		.BYTE	$50	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$50	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F0,$04	; LOOP_START
		.BYTE	$D3	; CMDD3
		.BYTE	$70	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$70	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F0,$04	; LOOP_START
		.BYTE	$D3	; CMDD3
		.BYTE	$80	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$80	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F0,$04	; LOOP_START
		.BYTE	$D3	; CMDD3
		.BYTE	$A0	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$A0	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F0,$04	; LOOP_START
		.BYTE	$D3	; CMDD3
		.BYTE	$B0	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$B0	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$00	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$00	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$00	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$00	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$A0	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$A0	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$A0	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$A0	; DATA
		.BYTE	$F0,$08	; LOOP_START
		.BYTE	$D3	; CMDD3
		.BYTE	$80	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$80	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F0,$04	; LOOP_START
		.BYTE	$D3	; CMDD3
		.BYTE	$A0	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$A0	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$D3	; CMDD3
		.BYTE	$A0,$C6	; DATA
		.BYTE	$F0,$03	; LOOP_START
		.BYTE	$D4	; CMDD4
		.BYTE	$00	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$00	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$00	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$00	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$A0	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$A0	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$A0	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$A0	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$80	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$80	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$80	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$80	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$80,$C0,$A0,$C0	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$D4	; CMDD4
		.BYTE	$02	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$A2,$85,$A0,$A0,$C0,$A0 ;	DATA
		.BYTE	$F8	; JMP
		.WORD	byte_9A993
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus0A_D:
		.BYTE	$E0,$08	; CMDE0
		.BYTE	$E9,$01	; CMDE9
byte_9AA19:
		.BYTE	$F0,$2C	; LOOP_START
		.BYTE	$01,$21	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$01,$21,$01,$21,$00,$21,$20,$21,$20,$20 ;	DATA
		.BYTE	$F0,$03	; LOOP_START
		.BYTE	$01,$20,$00,$C1,$21,$01,$20,$00,$21,$21 ;	DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$22,$22,$22,$20,$20,$20,$20,$20,$00,$20 ;	DATA
		.BYTE	$F8	; JMP
		.WORD	byte_9AA19
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus0B:
		.BYTE	$0F
		.WORD	_apu_mus0B_A
		.WORD	_apu_mus0B_B
		.WORD	_apu_mus0B_C
		.WORD	_apu_mus0B_D
_apu_mus0B_A:
		.BYTE	$E2,$00	; CMDE2
		.BYTE	$E1,$01	; CMDE1
		.BYTE	$E0,$05	; CMDE0
		.BYTE	$E9,$00	; CMDE9
		.BYTE	$D9,$F4	; CMDD9
byte_9AA57:
		.BYTE	$F0,$02	; LOOP_START
		.BYTE	$F0,$02	; LOOP_START
		.BYTE	$D5	; CMDD5
		.BYTE	$00,$C0	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$70,$C2,$A0,$C0,$50,$C2 ;	DATA
		.BYTE	$D6	; CMDD6
		.BYTE	$00,$C0	; DATA
		.BYTE	$EA,$02	; CMDEA
		.BYTE	$D5	; CMDD5
		.BYTE	$70,$C0	; DATA
		.BYTE	$EA,$03	; CMDEA
		.BYTE	$A0,$C0	; DATA
		.BYTE	$EA,$02	; CMDEA
		.BYTE	$50,$C0	; DATA
		.BYTE	$EA,$F9	; CMDEA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F0,$02	; LOOP_START
		.BYTE	$D5	; CMDD5
		.BYTE	$30,$C0	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$A0,$C2	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$10,$C0	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$80,$C2	; DATA
		.BYTE	$D6	; CMDD6
		.BYTE	$30,$C0	; DATA
		.BYTE	$EA,$02	; CMDEA
		.BYTE	$D5	; CMDD5
		.BYTE	$A0,$C0	; DATA
		.BYTE	$EA,$03	; CMDEA
		.BYTE	$D6	; CMDD6
		.BYTE	$10,$C0	; DATA
		.BYTE	$EA,$02	; CMDEA
		.BYTE	$D5	; CMDD5
		.BYTE	$80,$C0	; DATA
		.BYTE	$EA,$F9	; CMDEA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F2	; JSR
		.WORD	byte_9AAF0
		.BYTE	$F2	; JSR
		.WORD	byte_9AAFD
		.BYTE	$F2	; JSR
		.WORD	byte_9AAF0
		.BYTE	$C1	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$80,$C0,$80,$C0,$81,$71,$81,$C1,$71 ; DATA
		.BYTE	$F2	; JSR
		.WORD	byte_9AAF0
		.BYTE	$F2	; JSR
		.WORD	byte_9AAFD
		.BYTE	$F2	; JSR
		.WORD	byte_9AAF0
		.BYTE	$C1	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$80,$C0,$80,$C0,$80,$C0,$81,$71,$53 ; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$3F	; DATA
		.BYTE	$F2	; JSR
		.WORD	byte_9AB07
		.BYTE	$D5	; CMDD5
		.BYTE	$1F,$C1	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$11	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$11	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$11,$61,$81,$C1	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$31	; DATA
		.BYTE	$E8	; CMDE8
		.BYTE	$D5	; CMDD5
		.BYTE	$3F	; DATA
		.BYTE	$F2	; JSR
		.WORD	byte_9AB07
		.BYTE	$D5	; CMDD5
		.BYTE	$1F,$C1	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$11	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$11	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$11,$21	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$21,$C1,$31	; DATA
		.BYTE	$F8	; JMP
		.WORD	byte_9AA57
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
byte_9AAF0:
		.BYTE	$D5	; CMDD5
		.BYTE	$01	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$A0,$C0,$91,$50,$C0,$C1,$51,$71,$51 ; DATA
		.BYTE	$F3	; RET
byte_9AAFD:
		.BYTE	$C1	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$31,$C1,$31,$21,$31,$C1,$21 ; DATA
		.BYTE	$F3	; RET
byte_9AB07:
		.BYTE	$C1	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$31	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$31	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$31,$71,$81,$C1	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$11	; DATA
		.BYTE	$E8	; CMDE8
		.BYTE	$F3	; RET
_apu_mus0B_B:
		.BYTE	$E2,$00	; CMDE2
		.BYTE	$E1,$01	; CMDE1
		.BYTE	$E0,$05	; CMDE0
		.BYTE	$E9,$08	; CMDE9
		.BYTE	$D9,$F4	; CMDD9
		.BYTE	$C1	; DATA
		.BYTE	$F8	; JMP
		.WORD	byte_9AA57
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus0B_C:
		.BYTE	$E2,$04	; CMDE2
		.BYTE	$E1,$00	; CMDE1
		.BYTE	$E0,$05	; CMDE0
		.BYTE	$E9,$00	; CMDE9
byte_9AB2D:
		.BYTE	$F2	; JSR
		.WORD	byte_9AB72
		.BYTE	$C7	; DATA
		.BYTE	$F2	; JSR
		.WORD	byte_9AB72
		.BYTE	$D3	; CMDD3
		.BYTE	$81,$A1	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$33	; DATA
		.BYTE	$F0,$04	; LOOP_START
		.BYTE	$D3	; CMDD3
		.BYTE	$51,$C3,$53	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$31,$51,$C1	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$A1,$C3,$A5	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$01,$C1	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F2	; JSR
		.WORD	byte_9AB87
		.BYTE	$D3	; CMDD3
		.BYTE	$10,$C0,$11	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$11	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$11,$C1,$11	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$11	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$31	; DATA
		.BYTE	$F2	; JSR
		.WORD	byte_9AB87
		.BYTE	$10,$C0,$11	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$11	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$11,$C1	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$21	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$31	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$31	; DATA
		.BYTE	$F8	; JMP
		.WORD	byte_9AB2D
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
byte_9AB72:
		.BYTE	$D3	; CMDD3
		.BYTE	$0B	; DATA
		.BYTE	$E8	; CMDE8
		.BYTE	$D3	; CMDD3
		.BYTE	$07	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$00,$C0,$01,$CF	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$3B	; DATA
		.BYTE	$E8	; CMDE8
		.BYTE	$D3	; CMDD3
		.BYTE	$37	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$30,$C0,$31,$C7	; DATA
		.BYTE	$F3	; RET
byte_9AB87:
		.BYTE	$D3	; CMDD3
		.BYTE	$30,$C0,$31	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$31	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$70,$80,$C0,$A2	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$03	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$30,$C0,$31	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$31	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$31,$C1,$31	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$31	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$11	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$10,$C0,$11	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$11	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$50,$60,$C0,$82,$A3 ; DATA
		.BYTE	$F3	; RET
_apu_mus0B_D:
		.BYTE	$E0,$05	; CMDE0
		.BYTE	$E9,$00	; CMDE9
byte_9ABB3:
		.BYTE	$F0,$08	; LOOP_START
		.BYTE	$E9,$00	; CMDE9
		.BYTE	$00	; DATA
		.BYTE	$E9,$07	; CMDE9
		.BYTE	$30,$30,$30	; DATA
		.BYTE	$E9,$00	; CMDE9
		.BYTE	$20,$30,$00	; DATA
		.BYTE	$E9,$07	; CMDE9
		.BYTE	$30,$30,$30,$30,$30 ; DATA
		.BYTE	$E9,$00	; CMDE9
		.BYTE	$21	; DATA
		.BYTE	$E9,$01	; CMDE9
		.BYTE	$21	; DATA
		.BYTE	$E9,$03	; CMDE9
		.BYTE	$21	; DATA
		.BYTE	$E9,$04	; CMDE9
		.BYTE	$21	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F0,$20	; LOOP_START
		.BYTE	$E9,$00	; CMDE9
		.BYTE	$00	; DATA
		.BYTE	$E9,$07	; CMDE9
		.BYTE	$30,$30,$30	; DATA
		.BYTE	$E9,$00	; CMDE9
		.BYTE	$20	; DATA
		.BYTE	$E9,$07	; CMDE9
		.BYTE	$30,$30,$30	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F8	; JMP
		.WORD	byte_9ABB3
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus0C:
		.BYTE	$0F	; DATA
		.WORD	_apu_mus0C_A
		.WORD	_apu_mus0C_B
		.WORD	_apu_mus0C_C
		.WORD	_apu_mus0C_D
_apu_mus0C_A:
		.BYTE	$E2,$00	; CMDE2
		.BYTE	$E1,$00	; CMDE1
		.BYTE	$E0,$07	; CMDE0
		.BYTE	$E9,$00	; CMDE9
		.BYTE	$D9,$EC	; CMDD9
byte_9AC01:
		.BYTE	$F2	; JSR
		.WORD	byte_9AC5B
		.BYTE	$D5	; CMDD5
		.BYTE	$52,$32,$79	; DATA
		.BYTE	$F2	; JSR
		.WORD	byte_9AC5B
		.BYTE	$52,$32,$09	; DATA
		.BYTE	$F0,$02	; LOOP_START
		.BYTE	$F2	; JSR
		.WORD	byte_9AC6E
		.BYTE	$F2	; JSR
		.WORD	byte_9AC7F
		.BYTE	$F2	; JSR
		.WORD	byte_9AC6E
		.BYTE	$F2	; JSR
		.WORD	byte_9AC8B
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F2	; JSR
		.WORD	byte_9AC95
		.BYTE	$C0	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$70,$80,$A0	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$00,$20,$C0,$30,$C0,$50,$C0,$70,$50,$C0,$30,$C0 ;	DATA
		.BYTE	$F2	; JSR
		.WORD	byte_9AC95
		.BYTE	$C1,$70,$C0,$50,$C0,$30,$C0,$50,$70,$C0,$50,$C0,$30,$00,$C0 ; DATA
		.BYTE	$F2	; JSR
		.WORD	byte_9AC9F
		.BYTE	$71,$50,$71,$50,$70,$50,$00,$C0,$00,$C0 ;	DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$A2	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$00,$C7	; DATA
		.BYTE	$F8	; JMP
		.WORD	byte_9AC01
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
byte_9AC5B:
		.BYTE	$C0	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$50,$30,$C0,$50,$30,$C0,$50,$C0 ;	DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$50,$C0,$30,$50,$C0,$70,$C0 ; DATA
		.BYTE	$F3	; RET
byte_9AC6E:
		.BYTE	$F0,$02	; LOOP_START
		.BYTE	$D5	; CMDD5
		.BYTE	$00	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$00,$C0,$30,$70,$C0 ; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$D5	; CMDD5
		.BYTE	$00,$C0,$20,$C0	; DATA
		.BYTE	$F3	; RET
byte_9AC7F:
		.BYTE	$D5	; CMDD5
		.BYTE	$32,$22,$03	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$A0,$C0,$A0	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$00,$C1	; DATA
		.BYTE	$F3	; RET
byte_9AC8B:
		.BYTE	$D5	; CMDD5
		.BYTE	$32,$52,$73,$50,$C0,$30,$20,$C1 ;	DATA
		.BYTE	$F3	; RET
byte_9AC95:
		.BYTE	$F0,$02	; LOOP_START
		.BYTE	$D5	; CMDD5
		.BYTE	$00,$30,$C0,$72,$C1 ; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F3	; RET
byte_9AC9F:
		.BYTE	$81,$30,$81,$30,$80,$30,$A1,$50,$A1,$50,$A0,$50,$C1	; DATA
		.BYTE	$D6	; CMDD6
		.BYTE	$00,$C0	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$A0,$C0,$70,$C0	; DATA
		.BYTE	$D6	; CMDD6
		.BYTE	$00	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$A0,$C0,$71,$A0,$C1,$51,$30,$51,$30,$50,$30 ; DATA
		.BYTE	$F3	; RET
_apu_mus0C_B:
		.BYTE	$E2,$00	; CMDE2
		.BYTE	$E1,$00	; CMDE1
		.BYTE	$E0,$07	; CMDE0
		.BYTE	$E9,$00	; CMDE9
		.BYTE	$D9,$EC	; CMDD9
byte_9ACCD:
		.BYTE	$F2	; JSR
		.WORD	byte_9AD45
		.BYTE	$D5	; CMDD5
		.BYTE	$22,$02,$39	; DATA
		.BYTE	$F2	; JSR
		.WORD	byte_9AD45
		.BYTE	$22,$02	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$79	; DATA
		.BYTE	$E9,$08	; CMDE9
		.BYTE	$C1	; DATA
		.BYTE	$F2	; JSR
		.WORD	byte_9AC6E
		.BYTE	$F2	; JSR
		.WORD	byte_9AC7F
		.BYTE	$F2	; JSR
		.WORD	byte_9AC6E
		.BYTE	$F2	; JSR
		.WORD	byte_9AD58
		.BYTE	$D5	; CMDD5
		.BYTE	$71,$50,$C0,$30,$20,$C1 ;	DATA
		.BYTE	$F2	; JSR
		.WORD	byte_9AC6E
		.BYTE	$F2	; JSR
		.WORD	byte_9AC7F
		.BYTE	$F2	; JSR
		.WORD	byte_9AC6E
		.BYTE	$F2	; JSR
		.WORD	byte_9AD58
		.BYTE	$71,$50,$C0,$30,$20 ; DATA
		.BYTE	$E9,$00	; CMDE9
		.BYTE	$F2	; JSR
		.WORD	byte_9AD5E
		.BYTE	$C0	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$30,$50,$70,$80,$A0,$C0 ;	DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$00,$C0,$20,$C0,$30,$20,$C0,$00,$C0 ; DATA
		.BYTE	$F2	; JSR
		.WORD	byte_9AD5E
		.BYTE	$C1,$30,$C0,$20,$C0,$00,$C0,$20,$30,$C0,$20,$C0,$00 ; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$70,$C0	; DATA
		.BYTE	$E9,$08	; CMDE9
		.BYTE	$C1	; DATA
		.BYTE	$F2	; JSR
		.WORD	byte_9AC9F
		.BYTE	$71,$50,$71,$50	; DATA
		.BYTE	$E9,$00	; CMDE9
		.BYTE	$D4	; CMDD4
		.BYTE	$70,$C0,$70,$C0,$52,$70,$C7 ; DATA
		.BYTE	$F8	; JMP
		.WORD	byte_9ACCD
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
byte_9AD45:
		.BYTE	$C0	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$20,$00,$C0,$20,$00,$C0,$20,$C0 ;	DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$20,$C0,$00,$20,$C0,$30,$C0 ; DATA
		.BYTE	$F3	; RET
byte_9AD58:
		.BYTE	$D5	; CMDD5
		.BYTE	$32,$52,$71	; DATA
		.BYTE	$E8	; CMDE8
		.BYTE	$F3	; RET
byte_9AD5E:
		.BYTE	$F0,$02	; LOOP_START
		.BYTE	$D4	; CMDD4
		.BYTE	$80	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$00,$C0,$33,$C0	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F3	; RET
_apu_mus0C_C:
		.BYTE	$E2,$04	; CMDE2
		.BYTE	$E1,$03	; CMDE1
		.BYTE	$E0,$07	; CMDE0
		.BYTE	$E9,$00	; CMDE9
		.BYTE	$D9,$04	; CMDD9
byte_9AD73:
		.BYTE	$F0,$06	; LOOP_START
		.BYTE	$D3	; CMDD3
		.BYTE	$00,$C0,$00,$C0,$30,$70,$C0 ; DATA
		.BYTE	$D2	; CMDD2
		.BYTE	$A0,$C0	; DATA
		.BYTE	$D2	; CMDD2
		.BYTE	$A0,$C0,$A0	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$20,$C0,$50,$C0	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$00,$C0,$00,$C0,$30,$70,$C0,$50,$C0 ; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$50,$C0,$70	; DATA
		.BYTE	$D2	; CMDD2
		.BYTE	$A0,$C0,$B0,$C0	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F0,$03	; LOOP_START
		.BYTE	$F2	; JSR
		.WORD	byte_9ADCC
		.BYTE	$D3	; CMDD3
		.BYTE	$00,$C0,$00,$C0	; DATA
		.BYTE	$D2	; CMDD2
		.BYTE	$A0,$C0,$A0,$C0	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$00,$20,$C0,$31,$20,$00,$C0 ; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F2	; JSR
		.WORD	byte_9ADCC
		.BYTE	$D3	; CMDD3
		.BYTE	$00,$C0,$00,$C0	; DATA
		.BYTE	$D2	; CMDD2
		.BYTE	$A2	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$00,$C0,$02,$30,$C0,$70,$C0 ; DATA
		.BYTE	$F8	; JMP
		.WORD	byte_9AD73
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
byte_9ADCC:
		.BYTE	$D2	; CMDD2
		.BYTE	$80,$C1,$81	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$80	; DATA
		.BYTE	$D2	; CMDD2
		.BYTE	$80,$C0	; DATA
		.BYTE	$D2	; CMDD2
		.BYTE	$A0,$C1,$A1	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$A0	; DATA
		.BYTE	$D2	; CMDD2
		.BYTE	$A0,$C0	; DATA
		.BYTE	$F3	; RET
_apu_mus0C_D:
		.BYTE	$E0,$07	; CMDE0
		.BYTE	$E9,$00	; CMDE9
byte_9ADE3:
		.BYTE	$F0,$0C	; LOOP_START
		.BYTE	$01,$22,$01,$20,$01,$21,$01,$21 ;	DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F0,$0E	; LOOP_START
		.BYTE	$01,$21,$00,$00,$21 ; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$21,$21,$21,$00,$20,$00,$20,$20,$00,$20,$20,$00,$20 ; DATA
		.BYTE	$F8	; JMP
		.WORD	byte_9ADE3
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus0D:
		.BYTE	$0F
		.WORD	_apu_mus0D_A
		.WORD	_apu_mus0D_B
		.WORD	_apu_mus0D_C
		.WORD	_apu_mus0D_D
_apu_mus0D_A:
		.BYTE	$E2,$00	; CMDE2
		.BYTE	$E1,$03	; CMDE1
		.BYTE	$E0,$05	; CMDE0
		.BYTE	$E9,$00	; CMDE9
		.BYTE	$D9,$F4	; CMDD9
		.BYTE	$C1	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$73,$60,$50,$40,$C0,$40,$C2,$51,$C1,$61,$C1,$71,$87,$C0 ;	DATA
		.BYTE	$FF	; STOP
_apu_mus0D_B:
		.BYTE	$E2,$00	; CMDE2
		.BYTE	$E1,$03	; CMDE1
		.BYTE	$E0,$05	; CMDE0
		.BYTE	$E9,$00	; CMDE9
		.BYTE	$D9,$F4	; CMDD9
		.BYTE	$C1	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$13,$00	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$B0,$A0,$C0,$A0,$C2,$B1,$C1 ; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$01,$C1,$11,$27,$C0 ; DATA
		.BYTE	$FF	; STOP
_apu_mus0D_C:
		.BYTE	$E2,$04	; CMDE2
		.BYTE	$E1,$03	; CMDE1
		.BYTE	$E0,$05	; CMDE0
		.BYTE	$E9,$00	; CMDE9
		.BYTE	$D9,$0C	; CMDD9
		.BYTE	$D2	; CMDD2
		.BYTE	$A5,$90,$80,$70,$C0,$70,$C2,$81,$C1,$91,$C1,$A1,$B7,$C0 ;	DATA
		.BYTE	$FF	; STOP
_apu_mus0D_D:
		.BYTE	$E0,$05	; CMDE0
		.BYTE	$E9,$00	; CMDE9
		.BYTE	$01,$21,$01,$20,$20,$21,$21,$01,$21,$01,$21,$01,$21 ; DATA
		.BYTE	$F0,$08	; LOOP_START
		.BYTE	$20	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus0E:
		.BYTE	$0F
		.WORD	_apu_mus0E_A
		.WORD	_apu_mus0E_B
		.WORD	_apu_mus0E_C
		.WORD	_apu_mus0E_D
_apu_mus0E_A:
		.BYTE	$E2,$00	; CMDE2
		.BYTE	$E1,$03	; CMDE1
		.BYTE	$E0,$08	; CMDE0
		.BYTE	$E9,$00	; CMDE9
		.BYTE	$D9,$EF	; CMDD9
byte_9AE8D:
		.BYTE	$F0,$02	; LOOP_START
		.BYTE	$E1,$03	; CMDE1
		.BYTE	$F0,$02	; LOOP_START
		.BYTE	$D5	; CMDD5
		.BYTE	$10,$00,$10	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$A0	; DATA
		.BYTE	$E8	; CMDE8
		.BYTE	$A3,$C0,$A0,$C0,$A0,$C0,$A0,$C0,$A0 ; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$E1,$00	; CMDE1
		.BYTE	$F0,$02	; LOOP_START
		.BYTE	$D4	; CMDD4
		.BYTE	$10,$20,$30,$40,$50,$10,$C0,$71 ;	DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$10,$20,$30,$40,$50,$C1 ;	DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F1	; DO_LOOP
		.BYTE	$E1,$03	; CMDE1
		.BYTE	$F2	; JSR
		.WORD	byte_9AF05
		.BYTE	$C0	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$60,$60,$C0,$60,$60,$C0,$71,$70,$60,$C4 ;	DATA
		.BYTE	$F2	; JSR
		.WORD	byte_9AF05
		.BYTE	$C0,$60,$60,$C0,$60,$60,$C0,$71,$70,$60,$C0,$A0,$90,$80,$70 ; DATA
		.BYTE	$F0,$02	; LOOP_START
		.BYTE	$D5	; CMDD5
		.BYTE	$A0,$90,$A0,$70	; DATA
		.BYTE	$E8	; CMDE8
		.BYTE	$73,$C0,$70,$C0,$70,$C0,$70,$C0,$70 ; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$D5	; CMDD5
		.BYTE	$70,$60,$50,$40,$C0,$50,$40,$30,$C0,$20,$20,$C0,$20,$20,$C0,$20 ;	DATA
		.BYTE	$F8	; JMP
		.WORD	byte_9AE8D
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
byte_9AF05:
		.BYTE	$C0	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$60,$60,$C0,$60,$60,$C0,$51,$50,$60,$C4 ;	DATA
		.BYTE	$F3	; RET
_apu_mus0E_B:
		.BYTE	$E2,$00	; CMDE2
		.BYTE	$E1,$03	; CMDE1
		.BYTE	$E0,$08	; CMDE0
		.BYTE	$E9,$01	; CMDE9
		.BYTE	$D9,$EF	; CMDD9
byte_9AF1C:
		.BYTE	$F0,$02	; LOOP_START
		.BYTE	$E1,$03	; CMDE1
		.BYTE	$F0,$02	; LOOP_START
		.BYTE	$D4	; CMDD4
		.BYTE	$72,$40	; DATA
		.BYTE	$E8	; CMDE8
		.BYTE	$43,$C0,$40,$C0,$40,$C0,$40,$C0,$40 ; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F0,$02	; LOOP_START
		.BYTE	$E1,$02	; CMDE1
		.BYTE	$E0,$04	; CMDE0
		.BYTE	$D6	; CMDD6
		.BYTE	$E9,$0E	; CMDE9
		.BYTE	$F0,$08	; LOOP_START
		.BYTE	$10,$20	; DATA
		.BYTE	$EA,$FF	; CMDEA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F0,$08	; LOOP_START
		.BYTE	$10,$20	; DATA
		.BYTE	$EA,$01	; CMDEA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$EA,$F8	; CMDEA
		.BYTE	$E0,$08	; CMDE0
		.BYTE	$E9,$01	; CMDE9
		.BYTE	$E1,$03	; CMDE1
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F2	; JSR
		.WORD	byte_9AF6E
		.BYTE	$F2	; JSR
		.WORD	byte_9AF89
		.BYTE	$D5	; CMDD5
		.BYTE	$10,$00	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$B0,$A0,$C0,$B0,$A0,$90,$C0,$80,$80,$C0,$80,$80,$C0,$80 ;	DATA
		.BYTE	$F8	; JMP
		.WORD	byte_9AF1C
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
byte_9AF6E:
		.BYTE	$F0,$02	; LOOP_START
		.BYTE	$C0	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$20,$20,$C0,$20,$20,$C0,$11,$10,$20,$C5 ;	DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$20,$20,$C0,$20,$20,$C0,$31,$30,$20,$C4 ;	DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F3	; RET
byte_9AF89:
		.BYTE	$F0,$02	; LOOP_START
		.BYTE	$D5	; CMDD5
		.BYTE	$42,$10	; DATA
		.BYTE	$E8	; CMDE8
		.BYTE	$13,$C0,$10,$C0,$10,$C0,$10,$C0,$10 ; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F3	; RET
_apu_mus0E_C:
		.BYTE	$E2,$04	; CMDE2
		.BYTE	$E1,$03	; CMDE1
		.BYTE	$E0,$08	; CMDE0
		.BYTE	$E9,$00	; CMDE9
		.BYTE	$D9,$07	; CMDD9
byte_9AFA4:
		.BYTE	$F0,$02	; LOOP_START
		.BYTE	$F0,$08	; LOOP_START
		.BYTE	$D2	; CMDD2
		.BYTE	$A0,$C0,$50,$C0	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F0,$08	; LOOP_START
		.BYTE	$D2	; CMDD2
		.BYTE	$90,$C0,$40,$C0	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F0,$02	; LOOP_START
		.BYTE	$C0	; DATA
		.BYTE	$D2	; CMDD2
		.BYTE	$A0,$A0,$C0,$A0,$A0,$C0,$91,$90,$A0,$C0,$A0 ; DATA
		.BYTE	$E0,$04	; CMDE0
		.BYTE	$D4	; CMDD4
		.BYTE	$A0,$90	; DATA
		.BYTE	$E0,$08	; CMDE0
		.BYTE	$80,$C0,$C0	; DATA
		.BYTE	$D2	; CMDD2
		.BYTE	$A0,$A0,$C0,$A0,$A0,$C0,$B1,$B0,$A0,$C0,$A0 ; DATA
		.BYTE	$E0,$04	; CMDE0
		.BYTE	$D3	; CMDD3
		.BYTE	$A0,$90	; DATA
		.BYTE	$E0,$08	; CMDE0
		.BYTE	$80,$C0	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F0,$08	; LOOP_START
		.BYTE	$D3	; CMDD3
		.BYTE	$70,$C0,$10,$C0	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$D3	; CMDD3
		.BYTE	$70,$60,$50,$40,$C0,$50,$40,$30,$C0,$20,$20,$C0,$20,$20,$C0,$20 ;	DATA
		.BYTE	$F8	; JMP
		.WORD	byte_9AFA4
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus0E_D:
		.BYTE	$E0,$08	; CMDE0
		.BYTE	$E9,$00	; CMDE9
byte_9B008:
		.BYTE	$F0,$02	; LOOP_START
		.BYTE	$F0,$02	; LOOP_START
		.BYTE	$01,$21,$01,$20,$20,$01,$21,$00,$00,$21 ;	DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F0,$02	; LOOP_START
		.BYTE	$01,$21,$01,$21,$01,$21,$01,$21 ;	DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F0,$04	; LOOP_START
		.BYTE	$00,$20,$20,$00,$20,$20,$00,$21,$00,$20,$C0,$03 ;	DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F0,$02	; LOOP_START
		.BYTE	$01,$21,$01,$20,$20,$01,$21,$00,$00,$21 ;	DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$20,$20,$20,$20,$00,$20,$20,$20,$00,$20,$20,$00,$20,$20,$00,$20 ;	DATA
		.BYTE	$F8	; JMP
		.WORD	byte_9B008
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus0F:
		.BYTE	$01
		.WORD	_apu_mus0F_A
_apu_mus0F_A:
		.BYTE	$E2,$00	; CMDE2
		.BYTE	$E1,$00	; CMDE1
		.BYTE	$E0,$05	; CMDE0
		.BYTE	$C0,$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus10:
		.BYTE	$0F
		.WORD	_apu_mus10_A
		.WORD	_apu_mus10_B
		.WORD	_apu_mus10_C
		.WORD	_apu_mus10_D
_apu_mus10_A:
		.BYTE	$E2,$00	; CMDE2
		.BYTE	$E1,$03	; CMDE1
		.BYTE	$E0,$05	; CMDE0
		.BYTE	$E9,$00	; CMDE9
		.BYTE	$D9,$F4	; CMDD9
		.BYTE	$C1	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$73,$50,$C1,$40,$C1,$21,$C3 ; DATA
		.BYTE	$D4	; CMDD4
byte_9B07D:
		.BYTE	$75,$41,$C0,$71,$C0,$91,$C3,$41,$71,$C0,$96,$C2,$41,$C0,$71,$C0
		.BYTE	$91,$C0,$A1,$90,$C1,$A2,$92,$70,$91,$C0 ;	DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$01,$C0,$23,$C1	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$91	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$01,$C0,$26,$C1,$32,$20,$31,$20,$31,$20,$31,$C0,$21,$C0,$01,$C0 ;	DATA
		.BYTE	$21,$C0,$70,$C0,$71,$C0
		.BYTE	$E1,$02	; CMDE1
		.BYTE	$E0,$01	; CMDE0
		.BYTE	$70	; DATA
		.BYTE	$E8	; CMDE8
		.BYTE	$E0,$02	; CMDE0
		.BYTE	$79,$50,$40,$20,$00 ; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$B0,$90,$70	; DATA
		.BYTE	$E0,$05	; CMDE0
		.BYTE	$E1,$03	; CMDE1
		.BYTE	$D5	; CMDD5
		.BYTE	$50,$C0,$51,$C0	; DATA
		.BYTE	$E1,$02	; CMDE1
		.BYTE	$E0,$01	; CMDE0
		.BYTE	$50	; DATA
		.BYTE	$E8	; CMDE8
		.BYTE	$E0,$02	; CMDE0
		.BYTE	$59,$30,$20,$00	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$A0,$90,$70,$50	; DATA
		.BYTE	$E0,$05	; CMDE0
		.BYTE	$E1,$03	; CMDE1
		.BYTE	$C1	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$73,$91,$C0,$B1,$C0 ; DATA
		.BYTE	$E1,$02	; CMDE1
		.BYTE	$73	; DATA
		.BYTE	$E8	; CMDE8
		.BYTE	$E0,$02	; CMDE0
		.BYTE	$70,$50,$40,$20,$00 ; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$B0,$90	; DATA
		.BYTE	$E1,$03	; CMDE1
		.BYTE	$72	; DATA
		.BYTE	$E0,$05	; CMDE0
		.BYTE	$E8	; CMDE8
		.BYTE	$73	; DATA
		.BYTE	$F8	; JMP
		.WORD	byte_9B07D+1
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus10_B:
		.BYTE	$E2,$00	; CMDE2
		.BYTE	$E1,$03	; CMDE1
		.BYTE	$E0,$05	; CMDE0
		.BYTE	$E9,$00	; CMDE9
		.BYTE	$D9,$F4	; CMDD9
		.BYTE	$C1	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$B3,$90,$C1,$70,$C1,$51,$C3 ; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$75	; DATA
byte_9B11A:
		.BYTE	$D4	; CMDD4
		.BYTE	$01,$C0,$41,$C0,$41,$C3,$01,$41,$C0,$46,$C2,$01,$C0,$41,$C0,$41 ;	DATA
		.BYTE	$C0,$41,$40,$C1,$42,$42,$40,$51,$C0,$91,$C0,$93,$C1,$51,$91,$C0
		.BYTE	$96,$C1,$92,$90,$91,$90,$91,$90,$91,$C0,$91,$C0,$91,$C0,$91,$C0
		.BYTE	$B0,$C0,$B1,$C0,$B5,$C0,$90,$C0,$91,$C0,$95,$C0,$C1,$B3
		.BYTE	$D5	; CMDD5
		.BYTE	$01,$C0,$21,$C0	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$B5,$C5	; DATA
		.BYTE	$F8	; JMP
		.WORD	byte_9B11A
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus10_C:
		.BYTE	$E2,$03	; CMDE2
		.BYTE	$E1,$03	; CMDE1
		.BYTE	$E0,$05	; CMDE0
		.BYTE	$E9,$00	; CMDE9
		.BYTE	$D2	; CMDD2
		.BYTE	$74,$C0,$71,$C0,$71,$C0,$71,$C3,$75 ; DATA
byte_9B178:
		.BYTE	$F0,$04	; LOOP_START
		.BYTE	$D3	; CMDD3
		.BYTE	$01,$C0	; DATA
		.BYTE	$D2	; CMDD2
		.BYTE	$B1,$C0,$91,$C0,$71,$C0 ;	DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F0,$04	; LOOP_START
		.BYTE	$D3	; CMDD3
		.BYTE	$51,$C0,$41,$C0,$21,$C0,$01,$C0 ;	DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$D3	; CMDD3
		.BYTE	$70,$C0,$71,$C0,$75,$C0,$50,$C0,$51,$C0,$55,$C0,$75,$71,$C0,$71 ;	DATA
		.BYTE	$C0,$71,$C3
		.BYTE	$D2	; CMDD2
		.BYTE	$75	; DATA
		.BYTE	$F8	; JMP
		.WORD	byte_9B178
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus10_D:
		.BYTE	$E0,$05	; CMDE0
		.BYTE	$E9,$00	; CMDE9
		.BYTE	$01,$25,$20,$22,$25,$25 ;	DATA
byte_9B1B6:
		.BYTE	$E9,$05	; CMDE9
		.BYTE	$12,$31,$30	; DATA
		.BYTE	$F8	; JMP
		.WORD	byte_9B1B6
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus11:
		.BYTE	$0F
		.WORD	_apu_mus11_A
		.WORD	_apu_mus11_B
		.WORD	_apu_mus11_C
		.WORD	_apu_mus11_D
_apu_mus11_A:
		.BYTE	$E2,$00	; CMDE2
		.BYTE	$E1,$03	; CMDE1
		.BYTE	$E0,$05	; CMDE0
		.BYTE	$E9,$03	; CMDE9
		.BYTE	$D9,$F4	; CMDD9
byte_9B1D3:
		.BYTE	$F0,$02	; LOOP_START
		.BYTE	$F2	; JSR
		.WORD	byte_9B202
		.BYTE	$F2	; JSR
		.WORD	byte_9B20A
		.BYTE	$F2	; JSR
		.WORD	byte_9B202
		.BYTE	$F2	; JSR
		.WORD	byte_9B20D
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F0,$02	; LOOP_START
		.BYTE	$F0,$02	; LOOP_START
		.BYTE	$D4	; CMDD4
		.BYTE	$01,$41,$81	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$01,$41,$81,$C3	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F0,$02	; LOOP_START
		.BYTE	$D4	; CMDD4
		.BYTE	$11,$51,$91	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$11,$51,$91,$C3	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F8	; JMP
		.WORD	byte_9B1D3
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
byte_9B202:
		.BYTE	$D4	; CMDD4
		.BYTE	$22,$40,$53,$22,$40,$53 ;	DATA
		.BYTE	$F3	; RET
byte_9B20A:
		.BYTE	$D4	; CMDD4
		.BYTE	$8F	; DATA
		.BYTE	$F3	; RET
byte_9B20D:
		.BYTE	$D4	; CMDD4
		.BYTE	$AF	; DATA
		.BYTE	$F3	; RET
_apu_mus11_B:
		.BYTE	$E2,$00	; CMDE2
		.BYTE	$E1,$03	; CMDE1
		.BYTE	$E0,$05	; CMDE0
		.BYTE	$E9,$0A	; CMDE9
		.BYTE	$D9,$F4	; CMDD9
		.BYTE	$C1	; DATA
		.BYTE	$F8	; JMP
		.WORD	byte_9B1D3
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus11_C:
		.BYTE	$E2,$04	; CMDE2
		.BYTE	$E1,$03	; CMDE1
		.BYTE	$E0,$05	; CMDE0
		.BYTE	$E9,$00	; CMDE9
byte_9B228:
		.BYTE	$F0,$02	; LOOP_START
		.BYTE	$D3	; CMDD3
		.BYTE	$23	; DATA
		.BYTE	$D2	; CMDD2
		.BYTE	$93	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$23	; DATA
		.BYTE	$D2	; CMDD2
		.BYTE	$93	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$13	; DATA
		.BYTE	$D2	; CMDD2
		.BYTE	$83	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$13	; DATA
		.BYTE	$D2	; CMDD2
		.BYTE	$83	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$23	; DATA
		.BYTE	$D2	; CMDD2
		.BYTE	$93	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$23	; DATA
		.BYTE	$D2	; CMDD2
		.BYTE	$93	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$13	; DATA
		.BYTE	$D2	; CMDD2
		.BYTE	$73	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$13	; DATA
		.BYTE	$D2	; CMDD2
		.BYTE	$73	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F0,$02	; LOOP_START
		.BYTE	$F0,$02	; LOOP_START
		.BYTE	$D2	; CMDD2
		.BYTE	$90,$C0,$93,$C3,$90,$C0,$91,$C1 ;	DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F0,$02	; LOOP_START
		.BYTE	$D2	; CMDD2
		.BYTE	$A0,$C0,$A3,$C3,$A0,$C0,$A1,$C1 ;	DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F8	; JMP
		.WORD	byte_9B228
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus11_D:
		.BYTE	$E0,$05	; CMDE0
		.BYTE	$E9,$06	; CMDE9
byte_9B26F:
		.BYTE	$01,$21	; DATA
		.BYTE	$F8	; JMP
		.WORD	byte_9B26F
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus12:
		.BYTE	$0F
		.WORD	_apu_mus12_A
		.WORD	_apu_mus12_B
		.WORD	_apu_mus12_C
		.WORD	_apu_mus12_D
_apu_mus12_A:
		.BYTE	$E2,$00	; CMDE2
		.BYTE	$E1,$03	; CMDE1
		.BYTE	$E0,$04	; CMDE0
		.BYTE	$E9,$03	; CMDE9
		.BYTE	$D9,$EE	; CMDD9
byte_9B289:
		.BYTE	$F2	; JSR
		.WORD	byte_9B2A9
		.BYTE	$F2	; JSR
		.WORD	byte_9B2C8
		.BYTE	$D5	; CMDD5
		.BYTE	$41,$41,$C1,$65,$73,$B5,$97,$C1 ;	DATA
		.BYTE	$F2	; JSR
		.WORD	byte_9B2C8
		.BYTE	$41,$41,$C1,$65,$73,$B9,$91,$71,$61 ; DATA
		.BYTE	$F8	; JMP
		.WORD	byte_9B289
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
byte_9B2A9:
		.BYTE	$F0,$02	; LOOP_START
		.BYTE	$D4	; CMDD4
		.BYTE	$41,$61,$71,$41,$91,$A1,$91,$71,$B1,$C1,$B1,$99 ;	DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$41,$61,$71,$41,$91,$A1,$91,$71 ;	DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$41,$C1,$41,$39	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F3	; RET
byte_9B2C8:
		.BYTE	$D5	; CMDD5
		.BYTE	$45,$65,$73,$65,$75,$93 ;	DATA
		.BYTE	$F3	; RET
_apu_mus12_B:
		.BYTE	$E2,$00	; CMDE2
		.BYTE	$E1,$03	; CMDE1
		.BYTE	$E0,$04	; CMDE0
		.BYTE	$E9,$0A	; CMDE9
		.BYTE	$D9,$EE	; CMDD9
		.BYTE	$C1	; DATA
		.BYTE	$F8	; JMP
		.WORD	byte_9B289
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus12_C:
		.BYTE	$E2,$05	; CMDE2
		.BYTE	$E1,$03	; CMDE1
		.BYTE	$E0,$04	; CMDE0
		.BYTE	$E9,$01	; CMDE9
		.BYTE	$D9,$06	; CMDD9
byte_9B2EA:
		.BYTE	$F2	; JSR
		.WORD	byte_9B2F5
		.BYTE	$F2	; JSR
		.WORD	byte_9B30C
		.BYTE	$F8	; JMP
		.WORD	byte_9B2EA
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
byte_9B2F5:
		.BYTE	$F0,$02	; LOOP_START
		.BYTE	$F0,$08	; LOOP_START
		.BYTE	$D3	; CMDD3
		.BYTE	$41	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F0,$08	; LOOP_START
		.BYTE	$21	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F0,$08	; LOOP_START
		.BYTE	$D3	; CMDD3
		.BYTE	$01	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F0,$08	; LOOP_START
		.BYTE	$D2	; CMDD2
		.BYTE	$B1	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F3	; RET
byte_9B30C:
		.BYTE	$F0,$02	; LOOP_START
		.BYTE	$F0,$08	; LOOP_START
		.BYTE	$D2	; CMDD2
		.BYTE	$91	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F0,$08	; LOOP_START
		.BYTE	$B1	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F0,$08	; LOOP_START
		.BYTE	$D3	; CMDD3
		.BYTE	$01	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F0,$08	; LOOP_START
		.BYTE	$21	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F3	; RET
_apu_mus12_D:
		.BYTE	$E0,$04	; CMDE0
		.BYTE	$E9,$00	; CMDE9
byte_9B326:
		.BYTE	$03,$23	; DATA
		.BYTE	$F8	; JMP
		.WORD	byte_9B326
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus13:
		.BYTE	7
		.WORD	_apu_mus13_A
		.WORD	_apu_mus13_B
		.WORD	_apu_mus13_C
_apu_mus13_A:
		.BYTE	$E2,$00	; CMDE2
		.BYTE	$E1,$03	; CMDE1
		.BYTE	$E0,$0A	; CMDE0
		.BYTE	$E9,$03	; CMDE9
		.BYTE	$D9,$F6	; CMDD9
byte_9B33E:
		.BYTE	$F2	; JSR
		.WORD	byte_9B361
		.BYTE	$D4	; CMDD4
		.BYTE	$60,$C0,$20,$41,$00,$C0,$61,$60,$70,$90,$B0,$92 ;	DATA
		.BYTE	$F2	; JSR
		.WORD	byte_9B361
		.BYTE	$B0,$C0,$90,$C0,$B1,$90,$B0,$C0,$B0 ; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$15	; DATA
		.BYTE	$F8	; JMP
		.WORD	byte_9B33E
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
byte_9B361:
		.BYTE	$D4	; CMDD4
		.BYTE	$60,$C0,$20,$41,$00,$C0,$61,$60,$70,$90,$70,$60,$40,$20 ;	DATA
		.BYTE	$F3	; RET
_apu_mus13_B:
		.BYTE	$E2,$00	; CMDE2
		.BYTE	$E1,$03	; CMDE1
		.BYTE	$E0,$0A	; CMDE0
		.BYTE	$E9,$0A	; CMDE9
		.BYTE	$D9,$F6	; CMDD9
		.BYTE	$C0	; DATA
		.BYTE	$F8	; JMP
		.WORD	byte_9B33E
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus13_C:
		.BYTE	$E2,$04	; CMDE2
		.BYTE	$E1,$03	; CMDE1
		.BYTE	$E0,$0A	; CMDE0
		.BYTE	$E9,$01	; CMDE9
		.BYTE	$D9,$02	; CMDD9
byte_9B38B:
		.BYTE	$F2	; JSR
		.WORD	byte_9B3A5
		.BYTE	$E2,$03	; CMDE2
		.BYTE	$D3	; CMDD3
		.BYTE	$70,$71,$70,$C0,$70,$70,$70,$90,$91,$91,$70,$60,$40 ; DATA
		.BYTE	$E2,$04	; CMDE2
		.BYTE	$F8	; JMP
		.WORD	byte_9B38B
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
byte_9B3A5:
		.BYTE	$F0,$03	; LOOP_START
		.BYTE	$D3	; CMDD3
		.BYTE	$20,$90,$C0,$01,$70,$C0,$20,$C0,$20,$91,$01,$70,$C0 ; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F3	; RET
_apu_mus14:
		.BYTE	$0F,$C0,$B3,$57,$B4,$67,$B4,$CD,$B4	; DATA
_apu_mus14_A:
		.BYTE	$E2,$00	; CMDE2
		.BYTE	$E1,$03	; CMDE1
		.BYTE	$E0,$09	; CMDE0
		.BYTE	$E9,$00	; CMDE9
		.BYTE	$D9,$F2	; CMDD9
byte_9B3CA:
		.BYTE	$EA,$05	; CMDEA
		.BYTE	$F0,$04	; LOOP_START
		.BYTE	$D2	; CMDD2
		.BYTE	$90	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$40,$90	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$00,$40,$90,$80,$C0 ; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$40	; DATA
		.BYTE	$D2	; CMDD2
		.BYTE	$41	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$40	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$EA,$FB	; CMDEA
		.BYTE	$DA,$F4	; CMDDA
		.BYTE	$F2	; JSR
		.WORD	byte_9B449
		.BYTE	$F2	; JSR
		.WORD	byte_9B44F
		.BYTE	$F2	; JSR
		.WORD	byte_9B449
		.BYTE	$D5	; CMDD5
		.BYTE	$31,$40,$51,$40,$C5 ; DATA
		.BYTE	$F2	; JSR
		.WORD	byte_9B449
		.BYTE	$F2	; JSR
		.WORD	byte_9B44F
		.BYTE	$F2	; JSR
		.WORD	byte_9B449
		.BYTE	$31,$40,$51,$40,$C1,$40,$61,$80 ;	DATA
		.BYTE	$F0,$02	; LOOP_START
		.BYTE	$F0,$02	; LOOP_START
		.BYTE	$D5	; CMDD5
		.BYTE	$91	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$90	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F0,$02	; LOOP_START
		.BYTE	$D5	; CMDD5
		.BYTE	$71	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$90	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$D5	; CMDD5
		.BYTE	$61,$20,$41	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$90,$C1,$90,$B0	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$00	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$90	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$D5	; CMDD5
		.BYTE	$00	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$90	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$00	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$90	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$10	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$90	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$20	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$90	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$20	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$90	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$30	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$90	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$40,$C0,$40,$40,$C0,$44,$C1 ; DATA
		.BYTE	$DA,$0C	; CMDDA
		.BYTE	$F8	; JMP
		.WORD	byte_9B3CA
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
byte_9B449:
		.BYTE	$D4	; CMDD4
		.BYTE	$94	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$40,$C5	; DATA
		.BYTE	$F3	; RET
byte_9B44F:
		.BYTE	$D5	; CMDD5
		.BYTE	$31,$40,$21	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$B0,$C5	; DATA
		.BYTE	$F3	; RET
_apu_mus14_B:
		.BYTE	$E2,$00	; CMDE2
		.BYTE	$E1,$03	; CMDE1
		.BYTE	$E0,$09	; CMDE0
		.BYTE	$E9,$08	; CMDE9
		.BYTE	$D9,$F2	; CMDD9
		.BYTE	$C1	; DATA
		.BYTE	$F8	; JMP
		.WORD	byte_9B3CA
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus14_C:
		.BYTE	$E2,$04	; CMDE2
		.BYTE	$E1,$03	; CMDE1
		.BYTE	$E0,$09	; CMDE0
		.BYTE	$E9,$00	; CMDE9
		.BYTE	$D9,$0A	; CMDD9
byte_9B471:
		.BYTE	$F0,$04	; LOOP_START
		.BYTE	$D3	; CMDD3
		.BYTE	$90	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$40,$90	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$00,$40,$90,$80,$C0 ; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$40	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$41	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$40	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$DA,$F4	; CMDDA
		.BYTE	$F0,$04	; LOOP_START
		.BYTE	$D3	; CMDD3
		.BYTE	$90	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$40,$90	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$00,$C3	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$40	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$41	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$40	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$80	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$40,$B0,$C1,$42	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$40,$61,$80	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F0,$02	; LOOP_START
		.BYTE	$D2	; CMDD2
		.BYTE	$90,$C0,$90,$90,$C0,$90 ;	DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$00,$C0,$00,$01,$C0 ; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$24,$43,$C2	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$D3	; CMDD3
		.BYTE	$F0,$04	; LOOP_START
		.BYTE	$21,$C0	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$40,$C0,$40,$40,$C0,$42,$40,$61,$80 ; DATA
		.BYTE	$DA,$0C	; CMDDA
		.BYTE	$F8	; JMP
		.WORD	byte_9B471
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus14_D:
		.BYTE	$E0,$09	; CMDE0
		.BYTE	$E9,$00	; CMDE9
byte_9B4D1:
		.BYTE	$F0,$04	; LOOP_START
		.BYTE	$CB	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F0,$07	; LOOP_START
		.BYTE	$02,$22,$C1,$20,$01,$20 ;	DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$02,$22,$C1,$20,$21,$20 ;	DATA
		.BYTE	$F0,$02	; LOOP_START
		.BYTE	$F2	; JSR
		.WORD	byte_9B4FD
		.BYTE	$F2	; JSR
		.WORD	byte_9B502
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F2	; JSR
		.WORD	byte_9B4FD
		.BYTE	$21,$20,$01,$20,$C1,$20,$21,$20 ;	DATA
		.BYTE	$F8	; JMP
		.WORD	byte_9B4D1
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
byte_9B4FD:
		.BYTE	$02,$22,$02,$22	; DATA
		.BYTE	$F3	; RET
byte_9B502:
		.BYTE	$02,$22,$02,$20,$20,$20
		.BYTE	$F3	; RET
_apu_mus15:
		.BYTE	$0F
		.WORD	_apu_mus15_A
		.WORD	_apu_mus15_B
		.WORD	_apu_mus15_C
		.WORD	_apu_mus15_D
_apu_mus15_A:
		.BYTE	$E2,$00	; CMDE2
		.BYTE	$E1,$03	; CMDE1
		.BYTE	$E0,$09	; CMDE0
		.BYTE	$E9,$03	; CMDE9
		.BYTE	$D9,$F4	; CMDD9
byte_9B51C:
		.BYTE	$F0,$04	; LOOP_START
		.BYTE	$C0	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$70,$C0,$60,$C0,$50,$C0,$60 ; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F2	; JSR
		.WORD	byte_9B539
		.BYTE	$F2	; JSR
		.WORD	byte_9B547
		.BYTE	$F2	; JSR
		.WORD	byte_9B539
		.BYTE	$F2	; JSR
		.WORD	byte_9B554
		.BYTE	$F8	; JMP
		.WORD	byte_9B51C
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
byte_9B539:
		.BYTE	$D4	; CMDD4
		.BYTE	$70,$60,$70,$90,$C0,$A1,$71,$60,$70,$90,$C0,$A2 ;	DATA
		.BYTE	$F3	; RET
byte_9B547:
		.BYTE	$F0,$02	; LOOP_START
		.BYTE	$C0	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$10,$10,$C0,$10,$10,$C0,$10 ; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F3	; RET
byte_9B554:
		.BYTE	$F0,$02	; LOOP_START
		.BYTE	$C0	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$60,$60,$C0,$60,$60,$C0,$60 ; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F3	; RET
_apu_mus15_B:
		.BYTE	$E2,$00	; CMDE2
		.BYTE	$E1,$03	; CMDE1
		.BYTE	$E0,$09	; CMDE0
		.BYTE	$E9,$0A	; CMDE9
		.BYTE	$D9,$F4	; CMDD9
		.BYTE	$C1	; DATA
		.BYTE	$F8	; JMP
		.WORD	byte_9B51C
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus15_C:
		.BYTE	$E2,$04	; CMDE2
		.BYTE	$E1,$03	; CMDE1
		.BYTE	$E0,$09	; CMDE0
		.BYTE	$E9,$00	; CMDE9
byte_9B579:
		.BYTE	$D3	; CMDD3
		.BYTE	$00	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$40	; DATA
		.BYTE	$D2	; CMDD2
		.BYTE	$B0	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$30	; DATA
		.BYTE	$D2	; CMDD2
		.BYTE	$A0	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$20	; DATA
		.BYTE	$D2	; CMDD2
		.BYTE	$B0	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$30	; DATA
		.BYTE	$F8	; JMP
		.WORD	byte_9B579
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus15_D:
		.BYTE	$E0,$09	; CMDE0
		.BYTE	$E9,$00	; CMDE9
byte_9B592:
		.BYTE	$01,$21	; DATA
		.BYTE	$F8	; JMP
		.WORD	byte_9B592
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus16:
		.BYTE	$0F
		.WORD	_apu_mus16_A
		.WORD	_apu_mus16_B
		.WORD	_apu_mus16_C
		.WORD	_apu_mus16_D
_apu_mus16_A:
		.BYTE	$E2,$00	; CMDE2
		.BYTE	$E1,$03	; CMDE1
		.BYTE	$E0,$05	; CMDE0
		.BYTE	$E9,$03	; CMDE9
		.BYTE	$D9,$F4	; CMDD9
byte_9B5AC:
		.BYTE	$F2	; JSR
		.WORD	byte_9B5C9
		.BYTE	$F2	; JSR
		.WORD	byte_9B5DB
		.BYTE	$F2	; JSR
		.WORD	byte_9B5C9
		.BYTE	$F2	; JSR
		.WORD	byte_9B5ED
		.BYTE	$F2	; JSR
		.WORD	byte_9B5FF
		.BYTE	$F2	; JSR
		.WORD	byte_9B5ED
		.BYTE	$F2	; JSR
		.WORD	byte_9B5FF
		.BYTE	$F2	; JSR
		.WORD	byte_9B5DB
		.BYTE	$F8	; JMP
		.WORD	byte_9B5AC
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
byte_9B5C9:
		.BYTE	$D4	; CMDD4
		.BYTE	$71,$C1,$72,$60,$71,$C1,$72,$60,$71,$C1,$72,$60,$72,$60,$72,$80 ;	DATA
		.BYTE	$F3	; RET
byte_9B5DB:
		.BYTE	$D4	; CMDD4
		.BYTE	$91,$C1,$92,$80,$91,$C1,$92,$80,$91,$C1,$92,$80,$92,$80,$92,$80 ;	DATA
		.BYTE	$F3	; RET
byte_9B5ED:
		.BYTE	$D4	; CMDD4
		.BYTE	$91,$C1,$92,$80,$91,$C1,$92,$80,$91,$C1,$92,$80,$92,$80,$92,$A0 ;	DATA
		.BYTE	$F3	; RET
byte_9B5FF:
		.BYTE	$D4	; CMDD4
		.BYTE	$B1,$C1,$B2,$A0,$B1,$C1,$B2,$A0,$B1,$C1,$B2,$A0,$B2,$A0,$B2,$A0 ;	DATA
		.BYTE	$F3	; RET
_apu_mus16_B:
		.BYTE	$E2,$00	; CMDE2
		.BYTE	$E1,$03	; CMDE1
		.BYTE	$E0,$05	; CMDE0
		.BYTE	$E9,$09	; CMDE9
		.BYTE	$D9,$F4	; CMDD9
		.BYTE	$C0	; DATA
		.BYTE	$F8	; JMP
		.WORD	byte_9B5AC
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus16_C:
		.BYTE	$E2,$04	; CMDE2
		.BYTE	$E1,$03	; CMDE1
		.BYTE	$E0,$05	; CMDE0
		.BYTE	$E9,$02	; CMDE9
		.BYTE	$D9,$F1	; CMDD9
byte_9B62B:
		.BYTE	$F2	; JSR
		.WORD	byte_9B5C9
		.BYTE	$F2	; JSR
		.WORD	byte_9B5DB
		.BYTE	$F2	; JSR
		.WORD	byte_9B5C9
		.BYTE	$F2	; JSR
		.WORD	byte_9B5ED
		.BYTE	$F2	; JSR
		.WORD	byte_9B5FF
		.BYTE	$F2	; JSR
		.WORD	byte_9B5ED
		.BYTE	$F2	; JSR
		.WORD	byte_9B5FF
		.BYTE	$F2	; JSR
		.WORD	byte_9B5DB
		.BYTE	$F8	; JMP
		.WORD	byte_9B62B
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus16_D:
		.BYTE	$E0,$05	; CMDE0
		.BYTE	$E9,$00	; CMDE9
byte_9B64C:
		.BYTE	$03,$23	; DATA
		.BYTE	$F8	; JMP
		.WORD	byte_9B64C
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus17:
		.BYTE	$0F
		.WORD	_apu_mus17_A
		.WORD	_apu_mus17_B
		.WORD	_apu_mus17_C
		.WORD	_apu_mus17_D
_apu_mus17_A:
		.BYTE	$E2,$00	; CMDE2
		.BYTE	$E1,$03	; CMDE1
		.BYTE	$E0,$06	; CMDE0
		.BYTE	$E9,$03	; CMDE9
		.BYTE	$D9,$F4	; CMDD9
byte_9B666:
		.BYTE	$D5	; CMDD5
		.BYTE	$21,$01,$31,$01,$C5,$01,$21,$01,$31,$01,$C5,$90,$B0,$B1,$01,$21 ;	DATA
		.BYTE	$01,$C5,$01,$21,$01,$31,$01,$C1,$21,$31,$41,$51,$41,$71,$41,$C5
		.BYTE	$41,$51,$41,$71,$41,$C5
		.BYTE	$D6	; CMDD6
		.BYTE	$00,$10,$11	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$41,$71,$41,$C5,$41,$51,$41,$71,$41,$C1,$51,$41,$31 ; DATA
		.BYTE	$F8	; JMP
		.WORD	byte_9B666
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus17_B:
		.BYTE	$E2,$00	; CMDE2
		.BYTE	$E1,$03	; CMDE1
		.BYTE	$E0,$06	; CMDE0
		.BYTE	$E9,$0A	; CMDE9
		.BYTE	$D9,$F4	; CMDD9
		.BYTE	$C1	; DATA
		.BYTE	$F8	; JMP
		.WORD	byte_9B666
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus17_C:
		.BYTE	$E2,$04	; CMDE2
		.BYTE	$E1,$03	; CMDE1
		.BYTE	$E0,$06	; CMDE0
		.BYTE	$E9,$01	; CMDE9
byte_9B6BC:
		.BYTE	$F0,$0C	; LOOP_START
		.BYTE	$D3	; CMDD3
		.BYTE	$91,$C1	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$D3	; CMDD3
		.BYTE	$91,$C1,$91,$C1,$91,$A1,$B1 ; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$01	; DATA
		.BYTE	$F0,$0C	; LOOP_START
		.BYTE	$D4	; CMDD4
		.BYTE	$11,$C1	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$D4	; CMDD4
		.BYTE	$11,$C1,$11,$C1,$11,$01 ;	DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$B1,$A1	; DATA
		.BYTE	$F8	; JMP
		.WORD	byte_9B6BC
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus17_D:
		.BYTE	$E0,$06	; CMDE0
		.BYTE	$E9,$05	; CMDE9
byte_9B6E5:
		.BYTE	$31	; DATA
		.BYTE	$F8	; JMP
		.WORD	byte_9B6E5
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus18:
		.BYTE	$0F
		.WORD	_apu_mus18_A
		.WORD	_apu_mus18_B
		.WORD	_apu_mus18_C
		.WORD	_apu_mus18_D
_apu_mus18_A:
		.BYTE	$E2,$00	; CMDE2
		.BYTE	$E1,$03	; CMDE1
		.BYTE	$E0,$05	; CMDE0
		.BYTE	$E9,$03	; CMDE9
		.BYTE	$D9,$F4	; CMDD9
byte_9B6FE:
		.BYTE	$F0,$04	; LOOP_START
		.BYTE	$D4	; CMDD4
		.BYTE	$41,$51	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F0,$04	; LOOP_START
		.BYTE	$71,$91	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F0,$04	; LOOP_START
		.BYTE	$D4	; CMDD4
		.BYTE	$B1	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$01	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F0,$04	; LOOP_START
		.BYTE	$21,$41	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F0,$04	; LOOP_START
		.BYTE	$D4	; CMDD4
		.BYTE	$51,$71	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F0,$04	; LOOP_START
		.BYTE	$91,$A1	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F0,$04	; LOOP_START
		.BYTE	$D5	; CMDD5
		.BYTE	$01,$21	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F0,$04	; LOOP_START
		.BYTE	$41,$51	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F8	; JMP
		.WORD	byte_9B6FE
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus18_B:
		.BYTE	$E2,$00	; CMDE2
		.BYTE	$E1,$03	; CMDE1
		.BYTE	$E0,$05	; CMDE0
		.BYTE	$E9,$0A	; CMDE9
		.BYTE	$D9,$F4	; CMDD9
		.BYTE	$C1	; DATA
		.BYTE	$F8	; JMP
		.WORD	byte_9B6FE
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus18_C:
		.BYTE	$E2,$04	; CMDE2
		.BYTE	$E1,$03	; CMDE1
		.BYTE	$E0,$05	; CMDE0
		.BYTE	$E9,$01	; CMDE9
		.BYTE	$D9,$0C	; CMDD9
byte_9B74A:
		.BYTE	$F0,$10	; LOOP_START
		.BYTE	$D2	; CMDD2
		.BYTE	$91,$C1	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F0,$10	; LOOP_START
		.BYTE	$A1,$C1	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F8	; JMP
		.WORD	byte_9B74A
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus18_D:
		.BYTE	$E0,$05	; CMDE0
		.BYTE	$E9,$06	; CMDE9
byte_9B75E:
		.BYTE	$30	; DATA
		.BYTE	$F8	; JMP
		.WORD	byte_9B75E
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus19:
		.BYTE	$0F
		.WORD	_apu_mus19_A
		.WORD	_apu_mus19_B
		.WORD	_apu_mus19_C
		.WORD	_apu_mus19_D
_apu_mus19_A:
		.BYTE	$E2,$00	; CMDE2
		.BYTE	$E1,$03	; CMDE1
		.BYTE	$E0,$05	; CMDE0
		.BYTE	$E9,$03	; CMDE9
		.BYTE	$D9,$F0	; CMDD9
byte_9B777:
		.BYTE	$F0,$03	; LOOP_START
		.BYTE	$D4	; CMDD4
		.BYTE	$21,$31,$41	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$03	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$41,$C1,$53,$51,$91 ; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$01,$41,$C1,$21,$C1 ; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F0,$02	; LOOP_START
		.BYTE	$D5	; CMDD5
		.BYTE	$41,$41,$21,$C1,$41,$C1,$21,$41,$C1,$41,$21,$C1,$41,$C1,$21,$C1 ;	DATA
		.BYTE	$DA,$0C	; CMDDA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$DA,$E8	; CMDDA
		.BYTE	$F8	; JMP
		.WORD	byte_9B777
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus19_B:
		.BYTE	$E2,$00	; CMDE2
		.BYTE	$E1,$03	; CMDE1
		.BYTE	$E0,$05	; CMDE0
		.BYTE	$E9,$0A	; CMDE9
		.BYTE	$D9,$F0	; CMDD9
		.BYTE	$C1	; DATA
		.BYTE	$F8	; JMP
		.WORD	byte_9B777
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus19_C:
		.BYTE	$E2,$04	; CMDE2
		.BYTE	$E1,$03	; CMDE1
		.BYTE	$E0,$05	; CMDE0
		.BYTE	$E9,$01	; CMDE9
		.BYTE	$D9,$08	; CMDD9
byte_9B7C3:
		.BYTE	$F0,$03	; LOOP_START
		.BYTE	$D3	; CMDD3
		.BYTE	$01,$C3	; DATA
		.BYTE	$D2	; CMDD2
		.BYTE	$97	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$21,$C5,$21,$71,$C1,$71,$C1 ; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F0,$02	; LOOP_START
		.BYTE	$D3	; CMDD3
		.BYTE	$7F	; DATA
		.BYTE	$E8	; CMDE8
		.BYTE	$D3	; CMDD3
		.BYTE	$7F	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F8	; JMP
		.WORD	byte_9B7C3
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus19_D:
		.BYTE	$E0,$05	; CMDE0
		.BYTE	$E9,$02	; CMDE9
byte_9B7E4:
		.BYTE	$03,$23,$03,$21,$03,$01,$23,$23,$23	; DATA
		.BYTE	$F8	; JMP
		.WORD	byte_9B7E4
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus1A:
		.BYTE	$0F	; DATA
		.WORD	_apu_mus1A_A
		.WORD	_apu_mus1A_B
		.WORD	_apu_mus1A_C
		.WORD	_apu_mus1A_D
_apu_mus1A_A:
		.BYTE	$E2,$01	; CMDE2
		.BYTE	$E1,$03	; CMDE1
		.BYTE	$E0,$07	; CMDE0
		.BYTE	$E9,$03	; CMDE9
		.BYTE	$D9,$F4	; CMDD9
byte_9B805:
		.BYTE	$F0,$03	; LOOP_START
		.BYTE	$F2	; JSR
		.WORD	byte_9B88E
		.BYTE	$F2	; JSR
		.WORD	byte_9B899
		.BYTE	$F2	; JSR
		.WORD	byte_9B88E
		.BYTE	$D4	; CMDD4
		.BYTE	$51,$91	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$01,$21,$40,$21,$02,$21 ;	DATA
		.BYTE	$F2	; JSR
		.WORD	byte_9B88E
		.BYTE	$F2	; JSR
		.WORD	byte_9B899
		.BYTE	$F2	; JSR
		.WORD	byte_9B88E
		.BYTE	$D4	; CMDD4
		.BYTE	$51,$91	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$01,$21,$41,$50,$72,$40,$C0 ; DATA
		.BYTE	$F2	; JSR
		.WORD	byte_9B8A3
		.BYTE	$C1	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$71,$51,$41,$50,$71,$92,$C1 ; DATA
		.BYTE	$F2	; JSR
		.WORD	byte_9B8A3
		.BYTE	$F0,$05	; LOOP_START
		.BYTE	$70,$C0	; DATA
		.BYTE	$DA,$01	; CMDDA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$DA,$FB	; CMDDA
		.BYTE	$C1	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$72,$C0,$41,$50,$70,$C1,$40,$C0,$01 ; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$70,$C0,$90,$C0	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$00,$C0,$50,$40,$50,$01,$50,$40,$50,$03,$23,$41,$00 ; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$76,$71,$91	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$01,$51,$20	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$96,$91,$B1	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$21	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$0B	; DATA
		.BYTE	$E8	; CMDE8
		.BYTE	$E0,$01	; CMDE0
		.BYTE	$00	; DATA
		.BYTE	$E0,$03	; CMDE0
		.BYTE	$00,$20,$40,$50,$70,$90,$B0 ; DATA
		.BYTE	$D6	; CMDD6
		.BYTE	$01	; DATA
		.BYTE	$E8	; CMDE8
		.BYTE	$E0,$07	; CMDE0
		.BYTE	$03	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$00,$01,$00,$03,$C0 ; DATA
		.BYTE	$FF	; STOP
byte_9B88E:
		.BYTE	$C1	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$70,$C0,$50,$41,$72,$51,$41,$71 ;	DATA
		.BYTE	$F3	; RET
byte_9B899:
		.BYTE	$D4	; CMDD4
		.BYTE	$51,$91	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$01,$21,$42,$20,$C3 ; DATA
		.BYTE	$F3	; RET
byte_9B8A3:
		.BYTE	$C1	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$50,$C0,$40,$50,$C0,$02 ;	DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$91,$51,$91	; DATA
		.BYTE	$F3	; RET
_apu_mus1A_B:
		.BYTE	$E2,$01	; CMDE2
		.BYTE	$E1,$03	; CMDE1
		.BYTE	$E0,$07	; CMDE0
		.BYTE	$E9,$0A	; CMDE9
		.BYTE	$D9,$F4	; CMDD9
		.BYTE	$E0,$02	; CMDE0
		.BYTE	$C4	; DATA
		.BYTE	$E0,$07	; CMDE0
		.BYTE	$F8	; JMP
		.WORD	byte_9B805
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus1A_C:
		.BYTE	$E2,$03	; CMDE2
		.BYTE	$E1,$03	; CMDE1
		.BYTE	$E0,$07	; CMDE0
		.BYTE	$E9,$02	; CMDE9
		.BYTE	$F0,$03	; LOOP_START
		.BYTE	$F2	; JSR
		.WORD	byte_9B945
		.BYTE	$F2	; JSR
		.WORD	byte_9B94D
		.BYTE	$F2	; JSR
		.WORD	byte_9B945
		.BYTE	$D3	; CMDD3
		.BYTE	$51	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$51	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$51	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$51	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$71	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$70	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$71,$70,$90,$B0	; DATA
		.BYTE	$F2	; JSR
		.WORD	byte_9B945
		.BYTE	$F2	; JSR
		.WORD	byte_9B94D
		.BYTE	$F2	; JSR
		.WORD	byte_9B945
		.BYTE	$D3	; CMDD3
		.BYTE	$51	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$51	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$51	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$51	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$71	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$70	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$71,$90,$B1	; DATA
		.BYTE	$F2	; JSR
		.WORD	byte_9B95F
		.BYTE	$D3	; CMDD3
		.BYTE	$70,$70,$C3,$73,$51,$50,$50,$C1 ;	DATA
		.BYTE	$F2	; JSR
		.WORD	byte_9B95F
		.BYTE	$F0,$05	; LOOP_START
		.BYTE	$70,$C0	; DATA
		.BYTE	$DA,$01	; CMDDA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$DA,$FB	; CMDDA
		.BYTE	$C1,$72,$C0	; DATA
		.BYTE	$F0,$04	; LOOP_START
		.BYTE	$D4	; CMDD4
		.BYTE	$00,$C0	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F0,$04	; LOOP_START
		.BYTE	$D3	; CMDD3
		.BYTE	$A0,$C0	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F0,$04	; LOOP_START
		.BYTE	$90,$C0	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F0,$04	; LOOP_START
		.BYTE	$80,$C0	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F2	; JSR
		.WORD	byte_9B969
		.BYTE	$F2	; JSR
		.WORD	byte_9B969
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F2	; JSR
		.WORD	byte_9B945
		.BYTE	$D4	; CMDD4
		.BYTE	$03	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$00,$01,$00,$03,$C0 ; DATA
		.BYTE	$FF	; STOP
byte_9B945:
		.BYTE	$F0,$04	; LOOP_START
		.BYTE	$D3	; CMDD3
		.BYTE	$01	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$01	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F3	; RET
byte_9B94D:
		.BYTE	$D3	; CMDD3
		.BYTE	$51	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$51	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$51	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$51	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$71	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$70	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$71,$70,$50,$40	; DATA
		.BYTE	$F3	; RET
byte_9B95F:
		.BYTE	$D3	; CMDD3
		.BYTE	$A0,$A0,$C3,$A3,$91,$90,$90,$C1 ;	DATA
		.BYTE	$F3	; RET
byte_9B969:
		.BYTE	$F0,$04	; LOOP_START
		.BYTE	$D3	; CMDD3
		.BYTE	$71	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$71	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F3	; RET
_apu_mus1A_D:
		.BYTE	$E0,$07	; CMDE0
		.BYTE	$E9,$02	; CMDE9
		.BYTE	$F0,$30	; LOOP_START
		.BYTE	$F2	; JSR
		.WORD	byte_9B986
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F2	; JSR
		.WORD	byte_9B986
		.BYTE	$D2	; CMDD2
		.BYTE	$03,$20,$21,$20,$27,$C0 ;	DATA
		.BYTE	$FF	; STOP
byte_9B986:
		.BYTE	$D2	; CMDD2
		.BYTE	$03,$23,$03,$23	; DATA
		.BYTE	$F3	; RET
_apu_mus1B:
		.BYTE	7
		.WORD	_apu_mus1B_A
		.WORD	_apu_mus1B_B
		.WORD	_apu_mus1B_C
_apu_mus1B_A:
		.BYTE	$E2,$04	; CMDE2
		.BYTE	$E1,$03	; CMDE1
		.BYTE	$E0,$04	; CMDE0
		.BYTE	$E9,$00	; CMDE9
		.BYTE	$D9,$F4	; CMDD9
		.BYTE	$E0,$03	; CMDE0
		.BYTE	$D3	; CMDD3
		.BYTE	$00,$20,$40,$50,$70,$90,$B0 ; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$00,$20,$40,$50,$73,$C9,$00,$20,$40,$50,$70,$90,$B0 ; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$00,$20,$40,$50,$70,$90,$B0,$B1 ;	DATA
		.BYTE	$E0,$04	; CMDE0
		.BYTE	$D6	; CMDD6
		.BYTE	$01,$C0,$01,$C1,$00 ; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$A1,$C0,$A1,$C1,$A0,$91,$C0,$91,$C1,$90,$81,$C0,$81,$C1,$80,$C2 ;	DATA
		.BYTE	$73,$C0,$51,$C1,$42,$08
		.BYTE	$D6	; CMDD6
		.BYTE	$01,$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus1B_B:
		.BYTE	$E2,$04	; CMDE2
		.BYTE	$E1,$03	; CMDE1
		.BYTE	$E0,$04	; CMDE0
		.BYTE	$E9,$00	; CMDE9
		.BYTE	$D9,$F4	; CMDD9
		.BYTE	$E0,$03	; CMDE0
		.BYTE	$CA	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$70,$90,$B0	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$00,$20,$40,$50,$70,$90,$B0 ; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$00,$20,$40,$50,$73,$CB ;	DATA
		.BYTE	$E0,$04	; CMDE0
		.BYTE	$71,$C0,$71,$C1,$70,$71,$C0,$71,$C1,$70,$51,$C0,$51,$C1,$50,$51 ;	DATA
		.BYTE	$C0,$51,$C1,$50,$C2,$43,$C0,$21,$C1
		.BYTE	$D4	; CMDD4
		.BYTE	$72,$78	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$41,$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus1B_C:
		.BYTE	$E2,$04	; CMDE2
		.BYTE	$E1,$03	; CMDE1
		.BYTE	$E0,$04	; CMDE0
		.BYTE	$E9,$00	; CMDE9
		.BYTE	$E0,$03	; CMDE0
		.BYTE	$D3	; CMDD3
		.BYTE	$7F	; DATA
		.BYTE	$E8	; CMDE8
		.BYTE	$78	; DATA
		.BYTE	$E8	; CMDE8
		.BYTE	$7F	; DATA
		.BYTE	$E0,$04	; CMDE0
		.BYTE	$01,$C1,$01,$C1,$41,$C1,$41,$C1,$51,$C1,$51,$C1,$61,$C1,$61,$C1 ;	DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$73,$C2	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$70,$91,$C1,$B2	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$07,$C0,$01,$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus1C:
		.BYTE	$0F,$5C,$BA	; DATA
		.BYTE	$DD,$BA	; CMDDD
		.BYTE	$55,$BB,$B1,$BB	; DATA
_apu_mus1C_A:
		.BYTE	$E2,$00	; CMDE2
		.BYTE	$E1,$02	; CMDE1
		.BYTE	$E0,$05	; CMDE0
		.BYTE	$E9,$00	; CMDE9
		.BYTE	$D9,$F4	; CMDD9
byte_9BA66:
		.BYTE	$F2	; JSR
		.WORD	byte_9BAD2
		.BYTE	$C1	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$31,$23,$03,$20,$C0 ; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$91	; DATA
		.BYTE	$E8	; CMDE8
		.BYTE	$9F,$C1,$90,$C0,$91,$C1,$91,$C1,$A0,$C0 ;	DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$01	; DATA
		.BYTE	$F2	; JSR
		.WORD	byte_9BAD2
		.BYTE	$C1,$31,$23,$03,$20,$C0,$51 ; DATA
		.BYTE	$E8	; CMDE8
		.BYTE	$5F,$C1,$50,$C0,$51,$C1,$51,$C1,$50,$C0,$51,$C1,$70,$C0,$52,$C0 ;	DATA
		.BYTE	$50,$C0,$73,$50,$C0,$82,$C0,$82,$C0,$72,$C0,$52,$C0,$C1,$01,$21
		.BYTE	$01,$21,$31,$21,$01,$41,$C1,$41,$27,$C1,$C1,$21,$51,$21,$51,$91
		.BYTE	$C1,$71,$C1,$51,$C1,$71,$51,$C1,$41,$C1,$51,$C1,$51,$C3,$51,$C1
		.BYTE	$51,$51,$CD
		.BYTE	$F8	; JMP
		.WORD	byte_9BA66
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
byte_9BAD2:
		.BYTE	$C1	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$30,$C0,$23,$02,$C0,$20,$C0,$31 ;	DATA
		.BYTE	$F3	; RET
_apu_mus1C_B:
		.BYTE	$E2,$00	; CMDE2
		.BYTE	$E1,$02	; CMDE1
		.BYTE	$E0,$05	; CMDE0
		.BYTE	$E9,$01	; CMDE9
		.BYTE	$D9,$F4	; CMDD9
byte_9BAE7:
		.BYTE	$F2	; JSR
		.WORD	byte_9BB48
		.BYTE	$C1	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$01	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$A3,$93,$90,$C0,$51 ; DATA
		.BYTE	$E8	; CMDE8
		.BYTE	$5F,$C1,$50,$C0,$51,$C1,$51,$C1,$70,$C0,$91 ; DATA
		.BYTE	$F2	; JSR
		.WORD	byte_9BB48
		.BYTE	$C1	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$01	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$A3,$93,$A0,$C0	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$01	; DATA
		.BYTE	$E8	; CMDE8
		.BYTE	$0F,$C1,$00,$C0,$01,$C1,$01,$C1,$00,$C0,$01,$C1,$20,$C0,$22,$C0 ;	DATA
		.BYTE	$20,$C0,$23,$20,$C0
		.BYTE	$F0,$04	; LOOP_START
		.BYTE	$22,$C0	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$D4	; CMDD4
		.BYTE	$9F	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$01,$C1,$01,$07,$C1 ; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$7F,$C1	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$01,$C1,$01,$01,$C1,$01,$C1,$01,$C1,$01,$C3,$01,$C1,$01,$01,$CD ;	DATA
		.BYTE	$F8	; JMP
		.WORD	byte_9BAE7
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
byte_9BB48:
		.BYTE	$C1	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$00,$C0	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$A3,$92,$C0,$A0,$C0 ; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$01	; DATA
		.BYTE	$F3	; RET
_apu_mus1C_C:
		.BYTE	$E2,$04	; CMDE2
		.BYTE	$E1,$03	; CMDE1
		.BYTE	$E0,$05	; CMDE0
		.BYTE	$E9,$00	; CMDE9
byte_9BB5D:
		.BYTE	$F0,$08	; LOOP_START
		.BYTE	$D3	; CMDD3
		.BYTE	$51	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$51	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$21	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$21	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$31	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$31	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$41	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$41	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$DA,$F4	; CMDDA
		.BYTE	$F2	; JSR
		.WORD	byte_9BBA9
		.BYTE	$F0,$04	; LOOP_START
		.BYTE	$D3	; CMDD3
		.BYTE	$B1	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$B1	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F0,$04	; LOOP_START
		.BYTE	$D3	; CMDD3
		.BYTE	$91	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$91	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F0,$04	; LOOP_START
		.BYTE	$D4	; CMDD4
		.BYTE	$21	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$21	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F2	; JSR
		.WORD	byte_9BBA9
		.BYTE	$F0,$04	; LOOP_START
		.BYTE	$D4	; CMDD4
		.BYTE	$01	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$01	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$DA,$0C	; CMDDA
		.BYTE	$F0,$04	; LOOP_START
		.BYTE	$D3	; CMDD3
		.BYTE	$51	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$51	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$D3	; CMDD3
		.BYTE	$51,$C7	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$01,$21,$41	; DATA
		.BYTE	$F8	; JMP
		.WORD	byte_9BB5D
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
byte_9BBA9:
		.BYTE	$F0,$04	; LOOP_START
		.BYTE	$D3	; CMDD3
		.BYTE	$A1	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$A1	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F3	; RET
_apu_mus1C_D:
		.BYTE	$E0,$05	; CMDE0
		.BYTE	$E9,$00	; CMDE9
byte_9BBB5:
		.BYTE	$03,$23	; DATA
		.BYTE	$F8	; JMP
		.WORD	byte_9BBB5
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus1D:
		.BYTE	7
		.WORD	_apu_mus1D_A
		.WORD	_apu_mus1D_B
		.WORD	_apu_mus1D_C
_apu_mus1D_A:
		.BYTE	$E2,$00	; CMDE2
		.BYTE	$E1,$03	; CMDE1
		.BYTE	$E0,$06	; CMDE0
		.BYTE	$E9,$00	; CMDE9
		.BYTE	$D9,$F4	; CMDD9
byte_9BBCD:
		.BYTE	$F0,$08	; LOOP_START
		.BYTE	$D5	; CMDD5
		.BYTE	$00	; DATA
		.BYTE	$D6	; CMDD6
		.BYTE	$00	; DATA
		.BYTE	$DA,$FF	; CMDDA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$DA,$08	; CMDDA
		.BYTE	$D5	; CMDD5
		.BYTE	$41,$C0,$41,$C0,$41,$51,$C0 ; DATA
		.BYTE	$FF	; STOP
_apu_mus1D_B:
		.BYTE	$E2,$00	; CMDE2
		.BYTE	$E1,$03	; CMDE1
		.BYTE	$E0,$06	; CMDE0
		.BYTE	$E9,$08	; CMDE9
		.BYTE	$D9,$F4	; CMDD9
		.BYTE	$C0	; DATA
		.BYTE	$F8	; JMP
		.WORD	byte_9BBCD
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus1D_C:
		.BYTE	$E2,$04	; CMDE2
		.BYTE	$E1,$03	; CMDE1
		.BYTE	$E0,$06	; CMDE0
		.BYTE	$E9,$00	; CMDE9
		.BYTE	$D4	; CMDD4
		.BYTE	$F0,$09	; LOOP_START
		.BYTE	$01	; DATA
		.BYTE	$DA,$FF	; CMDDA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$DA,$09	; CMDDA
		.BYTE	$D3	; CMDD3
		.BYTE	$C0,$41,$C0,$41,$50,$C0 ;	DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$50	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$51,$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus1E:
		.BYTE	$0F,$18,$BC,$58,$BC,$68,$BC	; DATA
		.BYTE	$D1	; CMDD1
		.BYTE	$BC	; DATA
_apu_mus1E_A:
		.BYTE	$E2,$00	; CMDE2
		.BYTE	$E1,$03	; CMDE1
		.BYTE	$E0,$04	; CMDE0
		.BYTE	$E9,$00	; CMDE9
		.BYTE	$D9,$F4	; CMDD9
byte_9BC22:
		.BYTE	$F0,$04	; LOOP_START
		.BYTE	$D4	; CMDD4
		.BYTE	$91,$80,$70,$60,$C0,$51,$C1,$21,$C1,$21,$51,$21,$71,$21,$91,$81 ;	DATA
		.BYTE	$71,$51
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F0,$04	; LOOP_START
		.BYTE	$D5	; CMDD5
		.BYTE	$21,$10,$00	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$B0,$C0,$A1,$C1,$71,$C1,$71,$A1,$71 ; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$01	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$71	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$21,$11,$01	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$A1	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F8	; JMP
		.WORD	byte_9BC22
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus1E_B:
		.BYTE	$E2,$00	; CMDE2
		.BYTE	$E1,$03	; CMDE1
		.BYTE	$E0,$04	; CMDE0
		.BYTE	$E9,$08	; CMDE9
		.BYTE	$D9,$F4	; CMDD9
		.BYTE	$C1	; DATA
		.BYTE	$F8	; JMP
		.WORD	byte_9BC22
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus1E_C:
		.BYTE	$E2,$03	; CMDE2
		.BYTE	$E1,$03	; CMDE1
		.BYTE	$E0,$04	; CMDE0
		.BYTE	$E9,$00	; CMDE9
byte_9BC70:
		.BYTE	$F0,$02	; LOOP_START
		.BYTE	$D3	; CMDD3
		.BYTE	$21,$21,$51,$71,$21,$21,$51,$71,$21,$21,$71,$91,$51,$71,$51,$71 ;	DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$21,$21,$51,$71,$21,$21,$51,$71,$21,$21 ;	DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$01,$21	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$A1	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$01	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$71,$91	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F0,$02	; LOOP_START
		.BYTE	$D3	; CMDD3
		.BYTE	$71,$71,$A1	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$01	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$71,$71,$A1	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$01	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$71,$71	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$01,$21	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$A1	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$01	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$A1	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$01	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$71,$71,$A1	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$01	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$71,$71,$A1	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$01	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$71,$71	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$51,$71,$01,$21,$01,$21 ;	DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$F8	; JMP
		.WORD	byte_9BC70
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus1E_D:
		.BYTE	$E0,$04	; CMDE0
		.BYTE	$E9,$00	; CMDE9
byte_9BCD5:
		.BYTE	$03,$23,$03,$23,$03,$21,$23,$23,$21	; DATA
		.BYTE	$F8	; JMP
		.WORD	byte_9BCD5
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus1F:
		.BYTE	$0F
		.WORD	_apu_mus1F_A
		.WORD	_apu_mus1F_B
		.WORD	_apu_mus1F_C
		.WORD	_apu_mus1F_D
_apu_mus1F_A:
		.BYTE	$E2,$04	; CMDE2
		.BYTE	$E1,$03	; CMDE1
		.BYTE	$E0,$04	; CMDE0
		.BYTE	$E9,$02	; CMDE9
		.BYTE	$D9,$EA	; CMDD9
byte_9BCF6:
		.BYTE	$F2	; JSR
		.WORD	byte_9BD35
		.BYTE	$F2	; JSR
		.WORD	byte_9BD46
		.BYTE	$F2	; JSR
		.WORD	byte_9BD35
		.BYTE	$F2	; JSR
		.WORD	byte_9BD46
		.BYTE	$F2	; JSR
		.WORD	byte_9BD55
		.BYTE	$C1	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$51,$81,$51,$A1,$B1,$A1,$81 ; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$57	; DATA
		.BYTE	$E8	; CMDE8
		.BYTE	$50,$30,$10,$00	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$A0,$80,$60,$50	; DATA
		.BYTE	$F2	; JSR
		.WORD	byte_9BD55
		.BYTE	$C1,$51,$81,$51,$A1,$B1,$A1,$81,$A1,$81,$51 ; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$01	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$A1,$81	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$31,$51	; DATA
		.BYTE	$F8	; JMP
		.WORD	byte_9BCF6
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
byte_9BD35:
		.BYTE	$C3	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$01,$C1,$00,$C0,$01,$C1,$01,$C1,$01,$C1,$01,$33,$21,$01 ;	DATA
		.BYTE	$F3	; RET
byte_9BD46:
		.BYTE	$C1	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$00,$C0,$01,$C1,$00,$C0,$01,$C1,$01,$55,$35,$23 ;	DATA
		.BYTE	$F3	; RET
byte_9BD55:
		.BYTE	$C1	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$51,$81,$51,$81,$A1,$C1,$A1,$C1,$B5,$A1,$C1,$81,$C1 ; DATA
		.BYTE	$F3	; RET
_apu_mus1F_B:
		.BYTE	$E2,$04	; CMDE2
		.BYTE	$E1,$03	; CMDE1
		.BYTE	$E0,$04	; CMDE0
		.BYTE	$E9,$09	; CMDE9
		.BYTE	$D9,$EA	; CMDD9
		.BYTE	$C1	; DATA
		.BYTE	$F8	; JMP
		.WORD	byte_9BCF6
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus1F_C:
		.BYTE	$E2,$03	; CMDE2
		.BYTE	$E1,$03	; CMDE1
		.BYTE	$E0,$04	; CMDE0
		.BYTE	$E9,$00	; CMDE9
		.BYTE	$D9,$02	; CMDD9
byte_9BD7F:
		.BYTE	$F2	; JSR
		.WORD	byte_9BDB8
		.BYTE	$F2	; JSR
		.WORD	byte_9BDB8
		.BYTE	$F2	; JSR
		.WORD	byte_9BDB8
		.BYTE	$F2	; JSR
		.WORD	byte_9BDB8
		.BYTE	$F2	; JSR
		.WORD	byte_9BDB8
		.BYTE	$F2	; JSR
		.WORD	byte_9BDB8
		.BYTE	$F2	; JSR
		.WORD	byte_9BDB8
		.BYTE	$F2	; JSR
		.WORD	byte_9BDB8
		.BYTE	$DA,$F4	; CMDDA
		.BYTE	$F2	; JSR
		.WORD	byte_9BDC4
		.BYTE	$F2	; JSR
		.WORD	byte_9BDC4
		.BYTE	$F2	; JSR
		.WORD	byte_9BDC4
		.BYTE	$F2	; JSR
		.WORD	byte_9BDC4
		.BYTE	$F2	; JSR
		.WORD	byte_9BDC4
		.BYTE	$F2	; JSR
		.WORD	byte_9BDC4
		.BYTE	$F2	; JSR
		.WORD	byte_9BDC4
		.BYTE	$F2	; JSR
		.WORD	byte_9BDC4
		.BYTE	$DA,$0C	; CMDDA
		.BYTE	$F8	; JMP
		.WORD	byte_9BD7F
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
byte_9BDB8:
		.BYTE	$D3	; CMDD3
		.BYTE	$51,$51,$81,$51,$B1 ; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$01	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$A1,$81	; DATA
		.BYTE	$F3	; RET
byte_9BDC4:
		.BYTE	$D3	; CMDD3
		.BYTE	$A1,$A1	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$11	; DATA
		.BYTE	$D3	; CMDD3
		.BYTE	$A1	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$41,$51,$31,$11	; DATA
		.BYTE	$F3	; RET
_apu_mus1F_D:
		.BYTE	$E0,$04	; CMDE0
		.BYTE	$E9,$00	; CMDE9
byte_9BDD5:
		.BYTE	$03,$23	; DATA
		.BYTE	$F8	; JMP
		.WORD	byte_9BDD5
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus20:
		.BYTE	$0F
		.WORD	_apu_mus20_A
		.WORD	_apu_mus20_B
		.WORD	_apu_mus20_C
		.WORD	_apu_mus20_D
_apu_mus20_A:
		.BYTE	$E2,$00	; CMDE2
		.BYTE	$E1,$03	; CMDE1
		.BYTE	$E0,$03	; CMDE0
		.BYTE	$E9,$00	; CMDE9
		.BYTE	$D9,$F4	; CMDD9
		.BYTE	$C3	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$41	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$01	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$B1	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$01	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$71,$51,$C1,$41,$91,$C1,$91,$C1,$B0,$C0,$B2,$C0 ;	DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$25,$01,$C3	; DATA
		.BYTE	$D6	; CMDD6
		.BYTE	$23,$01,$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus20_B:
		.BYTE	$E2,$00	; CMDE2
		.BYTE	$E1,$03	; CMDE1
		.BYTE	$E0,$03	; CMDE0
		.BYTE	$E9,$00	; CMDE9
		.BYTE	$D9,$F4	; CMDD9
		.BYTE	$C3	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$00,$C0,$00,$C0,$00,$C0,$00,$C0,$01,$C1,$00,$C0,$01,$50,$C0,$50 ;	DATA
		.BYTE	$C0,$50,$C0,$51,$70,$C0,$71,$C1,$74,$C0,$71,$C3
		.BYTE	$D5	; CMDD5
		.BYTE	$72,$C0,$71,$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus20_C:
		.BYTE	$E2,$04	; CMDE2
		.BYTE	$E1,$03	; CMDE1
		.BYTE	$E0,$03	; CMDE0
		.BYTE	$E9,$00	; CMDE9
		.BYTE	$D3	; CMDD3
		.BYTE	$70,$50,$40,$20,$03,$C1,$01,$C3,$01,$C1,$51,$C1,$51,$C5,$77,$03 ;	DATA
		.BYTE	$C1,$02,$C0,$01,$C0
		.BYTE	$FF	; STOP
_apu_mus20_D:
		.BYTE	$E0,$03	; CMDE0
		.BYTE	$E9,$00	; CMDE9
		.BYTE	$C3,$03,$23,$01,$01,$21,$01,$23,$23,$01,$01,$21,$25,$25,$20,$20 ;	DATA
		.BYTE	$20,$20,$23,$C0
		.BYTE	$FF	; STOP
_apu_mus21:
		.BYTE	$0F
		.WORD	_apu_mus21_A
		.WORD	_apu_mus21_B
		.WORD	_apu_mus21_C
		.WORD	_apu_mus21_D
_apu_mus21_A:
		.BYTE	$E2,$00	; CMDE2
		.BYTE	$E1,$03	; CMDE1
		.BYTE	$E0,$03	; CMDE0
		.BYTE	$E9,$00	; CMDE9
		.BYTE	$D9,$F4	; CMDD9
		.BYTE	$C3	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$B1	; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$01,$C1,$11,$C1,$21,$C1,$31,$C1,$41,$C1,$51 ; DATA
		.BYTE	$F0,$08	; LOOP_START
		.BYTE	$D5	; CMDD5
		.BYTE	$70	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$B0	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus21_B:
		.BYTE	$E2,$00	; CMDE2
		.BYTE	$E1,$03	; CMDE1
		.BYTE	$E0,$03	; CMDE0
		.BYTE	$E9,$00	; CMDE9
		.BYTE	$D9,$F4	; CMDD9
		.BYTE	$C3	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$71,$81,$C1,$91,$C1,$A1,$C1,$B1,$C1 ; DATA
		.BYTE	$D5	; CMDD5
		.BYTE	$01,$C1,$11	; DATA
		.BYTE	$F0,$08	; LOOP_START
		.BYTE	$D5	; CMDD5
		.BYTE	$20	; DATA
		.BYTE	$D4	; CMDD4
		.BYTE	$70	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP
_apu_mus21_C:
		.BYTE	$E2,$04	; CMDE2
		.BYTE	$E1,$03	; CMDE1
		.BYTE	$E0,$03	; CMDE0
		.BYTE	$E9,$00	; CMDE9
		.BYTE	$D3	; CMDD3
		.BYTE	$70,$50,$40,$20,$01,$11,$C1,$21,$C1,$31,$C1,$41,$C1,$51,$C1,$61 ;	DATA
		.BYTE	$7F,$C0
		.BYTE	$FF	; STOP
_apu_mus21_D:
		.BYTE	$E0,$03	; CMDE0
		.BYTE	$E9,$00	; CMDE9
		.BYTE	$C3,$21,$03,$03,$23,$03,$03,$21 ;	DATA
		.BYTE	$F0,$10	; LOOP_START
		.BYTE	$30	; DATA
		.BYTE	$F1	; DO_LOOP
		.BYTE	$C0	; DATA
		.BYTE	$FF	; STOP

		BANK_END 6,$C000
