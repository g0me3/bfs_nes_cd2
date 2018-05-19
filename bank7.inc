
		ORG $C000

		BANK_START $07

;		INCBIN "..\copyrights.txt"

; =============== S U B R O U T I N E =======================================
_j_RESET:
		JMP		_RESET

; =============== S U B R O U T I N E =======================================
NMI:
		PHA
		TYA
		PHA
		TXA
		PHA
		LDA		#$00
		STA		_PPU_MASK
		STA		_PPU_OAM_ADDR
		STA		_wnd_split_flag
		LDA		#$06
		STA		_PPU_OAM_DMA
		LDA		_ppu_mask_shadow
		AND		#$18
		BEQ		loc_B4042
		JSR		_pal_dequeue
		JSR		_ppu_dequeue0
		LDA		_ppu_mask_shadow
		STA		_PPU_MASK
		LDX		#$00
		JSR		_ppu_scroll_reload
		LDA		_nmi_sync_req
		BEQ		loc_B4034
		JSR		_read_pads
loc_B4034:
		LDX		_spr_buf
		CPX		#$EF
		BCS		loc_B4042
		INC		_wnd_split_flag
loc_B403D:
		BIT		_PPU_STATUS
		BVS		loc_B403D
loc_B4042:
		LDA		_mmc1_busy
		BNE		loc_B406C
		LDX		_chr0_bank_req
		LDY		_chr1_bank_req
		JSR		_mmc1_chr_set
		LDA		_cur_prg_bank
		PHA
		LDA		#$06
		JSR		_mmc1_prg_set
		JSR		_apu_play
		LDX		_apu_load_idx_req
		BEQ		loc_B4068
		LDA		_apu_active_chnls_flags
		AND		#$0F
		BNE		loc_B4068
		STA		_apu_load_idx_req
		STX		_cur_mus_playing
		STX		_apu_load_idx
loc_B4068:
		PLA
		JSR		_mmc1_prg_set
loc_B406C:
		LDA		_pal_fade_req
		BEQ		loc_B40EA
		DEC		_pal_fade_delay
		BNE		loc_B40EA
		LDA		_pal_fade_speed
		STA		_pal_fade_delay
		LDY		#$00
		LDA		_pal_fade_req
		BMI		loc_B40B6
loc_B407E:
		LDA		_pal_fade_mask
		AND		_bitmasks,Y
		BEQ		loc_B40A4
		TYA
		PHA
		ASL
		ASL
		TAX
		LDY		#$04
loc_B408C:
		LDA		_pal_tmp_buf,X
		AND		#$0F
		ORA		_pal_fade_lvl
		CMP		_pal_tmp_buf,X
		BCC		loc_B409B
		LDA		_pal_tmp_buf,X
loc_B409B:
		STA		_pal_buf,X
		INX
		DEY
		BNE		loc_B408C
		PLA
		TAY
loc_B40A4:
		INY
		CPY		#$08
		BCC		loc_B407E
		CLC
		LDA		_pal_fade_lvl
		ADC		#$10
		STA		_pal_fade_lvl
		CMP		#$40
		BCS		loc_B40E6
		BCC		loc_B40EA
loc_B40B6:
		LDA		_pal_fade_mask
		AND		_bitmasks,Y
		BEQ		loc_B40D8
		TYA
		PHA
		ASL
		ASL
		TAX
		LDY		#$04
loc_B40C4:
		SEC
		LDA		_pal_buf,X
		SEC
		SBC		#$10
		BCS		loc_B40CF
		LDA		#$0F
loc_B40CF:
		STA		_pal_buf,X
		INX
		DEY
		BNE		loc_B40C4
		PLA
		TAY
loc_B40D8:
		INY
		CPY		#$08
		BCC		loc_B40B6
		SEC
		LDA		_pal_fade_lvl
		SBC		#$10
		STA		_pal_fade_lvl
		BPL		loc_B40EA
loc_B40E6:
		LDA		#$00
		STA		_pal_fade_req
loc_B40EA:
		LDX		_spr_buf
		CPX		#$50
		BCS		loc_B40F4
		JSR		_wnd_do_split
loc_B40F4:
		LDA		_nmi_sync_req
		BEQ		loc_B4100
		DEC		_nmi_sync_req
		INC		_nmi_frames_counter
		BNE		loc_B4100
		INC		_nmi_frames_counter+1
loc_B4100:
		PLA
		TAX
		PLA
		TAY
		PLA
		RTI

; =============== S U B R O U T I N E =======================================
_RESET:
		SEI
		LDA		#$08
		STA		_PPU_CTRL
		LDA		#$1E
		STA		_PPU_MASK
		LDX		#$02
loc_B4113:
		BIT		_PPU_STATUS
		BPL		loc_B4113
loc_B4118:
		BIT		_PPU_STATUS
		BMI		loc_B4118
		DEX
		BNE		loc_B4113
		LDX		#$13
		LDA		#$00
loc_B4124:
		STA		_APU_PULSE1_ENV,X
		DEX
		BPL		loc_B4124
		LDA		#$08
		STA		_APU_PULSE1_SWEEP
		STA		_APU_PULSE2_SWEEP
		LDA		#$8F
		STA		_APU_STATUS
		LDA		#$C0
		STA		_PAD1_REG
		LDA		#$00
		TAX
loc_B413F:
		STA		0,X
		STA		$100,X
		STA		$200,X
		STA		$300,X
		STA		$400,X
		STA		$500,X
		STA		$600,X
		STA		$700,X
		INX
		BNE		loc_B413F
		LDX		#$FF
		TXS
		STX		_spr_buf
		JSR		_mmc1_init
		LDA		#$00
		STA		_main_sub_idx
		LDA		#$1E
		STA		_ppu_mask_shadow
		LDA		#$08
		STA		_ppu_ctrl_shadow
		JSR		_nmi_on
		JMP		_MAIN_START
_bitmasks:
		.BYTE	$01,$02,$04,$08,$10,$20,$40,$80

; =============== S U B R O U T I N E =======================================
_read_pads:
		LDA		#$01
		STA		_PAD0_REG
		LDA		#$00
		STA		_PAD0_REG
		LDX		#$08
loc_B4188:
		LDA		_PAD0_REG
		ROR
		BCS		loc_B418F
		ROR
loc_B418F:
		ROR		_pads
		LDA		_PAD1_REG
		ROR
		BCS		loc_B4198
		ROR
loc_B4198:
		ROR		_pads+1
		DEX
		BNE		loc_B4188
		LDX		#$01
loc_B419F:
		LDA		_pads,X
		LDY		_pads_tmp,X
		STA		_pads_tmp,X
		TYA
		EOR		#$FF
		AND		_pads,X
		STA		_pads+4,X
		DEX
		BPL		loc_B419F
		RTS

; =============== S U B R O U T I N E =======================================
_set_pal_fade_in:
		STA		_pal_fade_mask
		STX		_pal_fade_speed
		STX		_pal_fade_delay
		LDA		#$00
		STA		_pal_fade_lvl
		LDA		#$10
		STA		_pal_fade_req
		RTS

; =============== S U B R O U T I N E =======================================
_set_pal_fade_out:
		STA		_pal_fade_mask
		STX		_pal_fade_speed
		STX		_pal_fade_delay
		LDA		#$40
		STA		_pal_fade_lvl
		LDA		#$F0
		STA		_pal_fade_req
		RTS

; =============== S U B R O U T I N E =======================================
_wait_for_pal_fade_is_over:
		LDA		#$01
		JSR		_wait_for_frames
		LDA		_pal_fade_req
		BNE		_wait_for_pal_fade_is_over
		LDA		#$01
		JSR		_wait_for_frames
		RTS

; =============== S U B R O U T I N E =======================================
_nmi_on:
		LDA		_ppu_ctrl_shadow
		ORA		#$80
		STA		_ppu_ctrl_shadow
		STA		_PPU_CTRL
		RTS

; =============== S U B R O U T I N E =======================================
_wait_for_frames:
		PHA
		JSR		_wnd_do_split
		INC		_nmi_sync_req
loc_B41ED:
		LDA		_nmi_sync_req
		BNE		loc_B41ED
		LDY		#$04
		LDA		_spr_buf_start
		BMI		loc_B41F9
		LDY		#$FC
loc_B41F9:
		STY		_spr_buf_start
		PLA
		SEC
		SBC		#$01
		BNE		_wait_for_frames
		RTS

; =============== S U B R O U T I N E =======================================
_wnd_do_split:
		LDA		_wnd_split_flag
		BEQ		locret_B422A
loc_B4206:
		BIT		_PPU_STATUS
		BVC		loc_B4206
		LDX		#$10
loc_B420D:
		DEX
		BNE		loc_B420D
		LDY		_wnd_split_ppu_ofs+1
		BEQ		loc_B421C
		LDA		_wnd_split_ppu_ofs
		STY		_PPU_ADDR
		STA		_PPU_ADDR
loc_B421C:
		LDX		#$01
		JSR		_ppu_scroll_reload
		LDX		_wnd_split_chr0_bank
		LDY		_wnd_split_chr1_bank
		JSR		_mmc1_chr_set
		DEC		_wnd_split_flag
locret_B422A:
		RTS

; =============== S U B R O U T I N E =======================================
_ppu_spr_mode8_set:
		LDA		_room_flags
		AND		#$01
		BNE		locret_B4237
		LDA		_ppu_mask_shadow
		AND		#$FD
		STA		_ppu_mask_shadow
locret_B4237:
		RTS

; =============== S U B R O U T I N E =======================================
_ppu_spr_mode16_set:
		LDA		_ppu_mask_shadow
		ORA		#$02
		STA		_ppu_mask_shadow
		RTS

; =============== S U B R O U T I N E =======================================
_render_off:
		LDA		#$F0
		STA		_spr_buf
		LDA		#$00
		STA		_wnd_split_flag
		LDA		_ppu_mask_shadow
		AND		#$E7
		STA		_ppu_mask_shadow
		LDA		#$01
		JMP		_wait_for_frames

; =============== S U B R O U T I N E =======================================
_render_on:
		LDA		_ppu_mask_shadow
		ORA		#$18
		STA		_ppu_mask_shadow
		LDA		#$01
		JMP		_wait_for_frames

; =============== S U B R O U T I N E =======================================
_ppu_increment_1:
		LDA		_ppu_ctrl_shadow
		AND		#$FB
		STA		_ppu_ctrl_shadow
		STA		_PPU_CTRL
		RTS

; =============== S U B R O U T I N E =======================================
_ppu_increment_32_unused:
		LDA		_ppu_ctrl_shadow
		ORA		#$04
		STA		_ppu_ctrl_shadow
		STA		_PPU_CTRL
		RTS

; =============== S U B R O U T I N E =======================================
_mmc1_init:
		LDX		#$7F
		STX		_unused_3
		STX		_unused_4
		STX		_cur_prg_bank
		LDA		#$1E

; =============== S U B R O U T I N E =======================================
_mmc1_ctrl_set:
		INC		_mmc1_busy
		STA		_mmc1_ctrl_shadow
		STA		$9FFF
		LSR
		STA		$9FFF
		LSR
		STA		$9FFF
		LSR
		STA		$9FFF
		LSR
		STA		$9FFF
		LDA		#$00
		STA		_mmc1_busy
		RTS

; =============== S U B R O U T I N E =======================================
_mmc1_chr_set:
		INC		_mmc1_busy
		TXA
		STA		$BFFF
		LSR
		STA		$BFFF
		LSR
		STA		$BFFF
		LSR
		STA		$BFFF
		LSR
		STA		$BFFF
		TYA
		STA		$DFFF
		LSR
		STA		$DFFF
		LSR
		STA		$DFFF
		LSR
		STA		$DFFF
		LSR
		STA		$DFFF
		DEC		_mmc1_busy
		RTS

; =============== S U B R O U T I N E =======================================
_mmc1_prg_set:
		PHP
		CMP		_cur_prg_bank
		BEQ		loc_B42E3
		STA		_cur_prg_bank
		INC		_mmc1_busy
		STA		$EFFF
		LSR
		STA		$EFFF
		LSR
		STA		$EFFF
		LSR
		STA		$EFFF
		LSR
		STA		$EFFF
		DEC		_mmc1_busy
loc_B42E3:
		PLP
		RTS

; =============== S U B R O U T I N E =======================================
_ppu_scroll_reload:
		LDA		_PPU_STATUS
		LDA		_ppu_scroll_shadow_lo,X
		STA		_PPU_SCROLL
		LDA		_ppu_scroll_shadow_hi,X
		STA		_PPU_SCROLL
		LDA		_ppu_scroll_nt_vert,X
		AND		#$01
		STA		_tmp1C
		LDA		_ppu_scroll_nt_hor,X
		LSR
		ROL		_tmp1C
		LDA		_ppu_ctrl_shadow
		AND		#$FC
		ORA		_tmp1C
		STA		_ppu_ctrl_shadow
		STA		_PPU_CTRL
		RTS

; =============== S U B R O U T I N E =======================================
_nt_fill:
		STA		_tmp_ptr0
		STX		_tmp_ptr0+1
		STY		_tmp_ptr2
		LDA		_PPU_STATUS
		JSR		_ppu_increment_1
		LDA		_tmp_ptr0
		STA		_PPU_ADDR
		LDY		#$00
		STY		_PPU_ADDR
		LDX		#$04
		CMP		#$20
		BCS		loc_B4327
		LDX		#$02
loc_B4327:
		LDA		_tmp_ptr0+1
loc_B4329:
		STA		_PPU_DATA
		DEY
		BNE		loc_B4329
		DEX
		BNE		loc_B4329
		LDY		_tmp_ptr2
		LDA		_tmp_ptr0
		CMP		#$20
		BCC		loc_B434C
		ORA		#$03
		STA		_PPU_ADDR
		LDA		#$C0
		STA		_PPU_ADDR
		LDX		#$40
loc_B4346:
		STY		_PPU_DATA
		DEX
		BNE		loc_B4346
loc_B434C:
		LDX		_tmp_ptr0+1
		RTS

; =============== S U B R O U T I N E =======================================
_ppu_dequeue0:
		LDA		_ppu_queue0_done_flag
		BEQ		loc_B4354
		RTS
loc_B4354:
		LDA		_ppu_ctrl_shadow
		AND		#$FB
		ORA		_ppu_queue0_increment_mode
		STA		_ppu_ctrl_shadow
		STA		_PPU_CTRL
		LDA		_PPU_STATUS
		LDY		#$00
loc_B4364:
		LDA		_ppu_queue0_buf,Y
		BNE		loc_B4372
		STA		_ppu_queue0_flag
		STA		_ppu_queue0_buf
		INC		_ppu_queue0_done_flag
		RTS
loc_B4372:
		STA		_PPU_ADDR
		INY
		LDA		_ppu_queue0_buf,Y
		STA		_PPU_ADDR
		INY
		LDX		_ppu_queue0_buf,Y
		INY
loc_B4381:
		LDA		_ppu_queue0_buf,Y
		STA		_PPU_DATA
		INY
		DEX
		BNE		loc_B4381
		BEQ		loc_B4364

; =============== S U B R O U T I N E =======================================
_tlm_queue_param:
		JSR		_get_param2

; =============== S U B R O U T I N E =======================================
_tlm_queue:
		STA		_tmp_ptr2
		AND		#$3F
		BNE		loc_B4398
		LDA		#$40
loc_B4398:
		STA		_tmp_ptr2+1
		LDA		_tmp_ptr2
		AND		#$40
		LSR
		LSR
		LSR
		LSR
		STA		_tmp_ptr4
		LDA		_ppu_mask_shadow
		AND		#$18
		BNE		loc_B43D9
		LDA		_ppu_ctrl_shadow
		AND		#$FB
		ORA		_tmp_ptr4
		STA		_ppu_ctrl_shadow
		STA		_PPU_CTRL
		LDA		_tmp_ptr44+1
		STA		_PPU_ADDR
		LDA		_tmp_ptr44
		STA		_PPU_ADDR
		LDY		#$FF
loc_B43C1:
		INY
		LDA		(_tmp_ptr0),Y
		STA		_PPU_DATA
		LDA		_tmp_ptr2
		BPL		loc_B43CC
		DEY
loc_B43CC:
		DEC		_tmp_ptr2+1
		BNE		loc_B43C1
		LDA		_tmp_ptr2
		BPL		loc_B43D5
		INY
loc_B43D5:
		INY
		JMP		_adc_tmp_ptr0
loc_B43D9:
		LDX		_ppu_queue0_flag
		BEQ		loc_B43F8
		LDA		_ppu_queue0_increment_mode
		CMP		_tmp_ptr4
		BNE		loc_B43EC
		TXA
		CLC
		ADC		_tmp_ptr2+1
		CMP		#$50
		BCC		loc_B43F8
loc_B43EC:
		LDA		#$00
		STA		_ppu_queue0_done_flag
		LDA		#$01
		JSR		_wait_for_frames
		LDX		_ppu_queue0_flag
loc_B43F8:
		LDA		#$01
		STA		_ppu_queue0_done_flag
		LDA		_tmp_ptr4
		STA		_ppu_queue0_increment_mode
		LDA		_tmp_ptr44+1
		STA		_ppu_queue0_buf,X
		INX
		LDA		_tmp_ptr44
		STA		_ppu_queue0_buf,X
		INX
		LDA		_tmp_ptr2+1
		STA		_ppu_queue0_buf,X
		INX
		LDA		_tmp_ptr2
		BPL		loc_B4426
		LDY		#$00
		LDA		(_tmp_ptr0),Y
loc_B441A:
		STA		_ppu_queue0_buf,X
		INX
		DEC		_tmp_ptr2+1
		BNE		loc_B441A
		LDY		#$01
		BNE		loc_B4433
loc_B4426:
		LDY		#$00
loc_B4428:
		LDA		(_tmp_ptr0),Y
		STA		_ppu_queue0_buf,X
		INY
		INX
		DEC		_tmp_ptr2+1
		BNE		loc_B4428
loc_B4433:
		LDA		#$00
		STA		_ppu_queue0_buf,X
		STX		_ppu_queue0_flag
		STA		_ppu_queue0_done_flag

; =============== S U B R O U T I N E =======================================
_adc_tmp_ptr0:
		TYA
		CLC
		ADC		_tmp_ptr0
		STA		_tmp_ptr0
		LDA		_tmp_ptr0+1
		ADC		#$00
		STA		_tmp_ptr0+1
		RTS

; =============== S U B R O U T I N E =======================================
_tlm_res_queue_param:
		JSR		_get_param2

; =============== S U B R O U T I N E =======================================
_tlm_res_queue:
		LDY		#$00
		LDA		(_tmp_ptr0),Y
		BNE		loc_B4454
		RTS
loc_B4454:
		STA		_tmp_ptr44+1
		INY
		LDA		(_tmp_ptr0),Y
		STA		_tmp_ptr44
		INY
		LDA		(_tmp_ptr0),Y
		TAX
		INY
		JSR		_adc_tmp_ptr0
		TXA
		JSR		_tlm_queue
		JMP		_tlm_res_queue

; =============== S U B R O U T I N E =======================================
_rect_draw_param:
		JSR		_get_param2

; =============== S U B R O U T I N E =======================================
_rect_draw:
		LDY		#$00
		LDA		(_tmp_ptr0),Y
		STA		byte_6
		INY
		LDA		(_tmp_ptr0),Y
		STA		byte_7
		INY
		JSR		_adc_tmp_ptr0
loc_B447C:
		LDA		byte_6
		JSR		_tlm_queue
		LDA		_tmp_ptr44
		CLC
		ADC		#$20
		STA		_tmp_ptr44
		BCC		loc_B448C
		INC		_tmp_ptr44+1
loc_B448C:
		LDA		byte_7
		BPL		loc_B44B8
		LDA		byte_6
		BPL		loc_B44A1
		DEC		_tmp_ptr0
		LDA		_tmp_ptr0
		CMP		#$FF
		BNE		loc_B44B8
		DEC		_tmp_ptr0+1
		JMP		loc_B44B8
loc_B44A1:
		LDA		byte_6
		AND		#$3F
		BNE		loc_B44A9
		LDA		#$40
loc_B44A9:
		STA		byte_8
		LDA		_tmp_ptr0
		SEC
		SBC		byte_8
		STA		_tmp_ptr0
		LDA		_tmp_ptr0+1
		SBC		#$00
		STA		_tmp_ptr0+1
loc_B44B8:
		DEC		byte_7
		LDA		byte_7
		AND		#$3F
		BNE		loc_B447C
		RTS

; =============== S U B R O U T I N E =======================================
_msg_frame_draw_param:
		JSR		_get_param2
		LDA		_tmp_ptr0
		STA		_tmpA
		LDA		_tmp_ptr0+1
		STA		_tmpA+1
		TYA
		PHA
		STX		_ram_buf0
		LDA		#$01
		STA		_ram_buf0+1
		LDY		#$00
		JSR		_msg_frame_fill
		JSR		_rect_draw_param
		.WORD	_ram_buf0
		PLA
		SEC
		SBC		#$02
		ORA		#$80
		STA		_ram_buf0+1
		LDY		#$03
		JSR		_msg_frame_fill
		JSR		_rect_draw_param
		.WORD	_ram_buf0
		LDA		#$01
		STA		_ram_buf0+1
		LDY		#$06
		JSR		_msg_frame_fill
		JSR		_rect_draw_param
		.WORD	_ram_buf0
		RTS

; =============== S U B R O U T I N E =======================================
_msg_frame_fill:
		LDA		(_tmpA),Y
		STA		_ram_buf0+2
		INY
		LDX		_ram_buf0
		DEX
		DEX
loc_B450E:
		LDA		(_tmpA),Y
		STA		_ram_buf0+2,X
		DEX
		BNE		loc_B450E
		INY
		LDX		_ram_buf0
		DEX
		LDA		(_tmpA),Y
		STA		_ram_buf0+2,X
		RTS

; =============== S U B R O U T I N E =======================================
_pal_dequeue:
		JSR		_ppu_increment_1
		LDA		_PPU_STATUS
		LDA		#$3F
		STA		_PPU_ADDR
		LDA		#$00
		STA		_PPU_ADDR
		TAY
loc_B4532:
		LDA		_pal_buf,Y
		STA		_PPU_DATA
		INY
		CPY		#$20
		BCC		loc_B4532
		LDA		#$3F
		STA		_PPU_ADDR
		LDA		#$00
		STA		_PPU_ADDR
		STA		_PPU_ADDR
		STA		_PPU_ADDR
		RTS

; =============== S U B R O U T I N E =======================================
_switch:
		STA		_tmp_ptr2
		PLA
		STA		_tmp_ptr0
		PLA
		STA		_tmp_ptr0+1

; =============== S U B R O U T I N E =======================================
_table_jump:
		LDA		_tmp_ptr2
		ASL
		TAY
		INY
		LDA		(_tmp_ptr0),Y
		INY
		STA		_tmp_ptr2
		LDA		(_tmp_ptr0),Y
		STA		_tmp_ptr2+1
		JMP		(_tmp_ptr2)

; =============== S U B R O U T I N E =======================================
_switch_param_ret:
		STA		_tmp_ptr2
		PLA
		STA		_tmp_ptr0
		PLA
		STA		_tmp_ptr0+1
		TXA
		PHA
		TYA
		PHA
		JMP		_table_jump

; =============== S U B R O U T I N E =======================================
_get_param2:
		STX		_tmpC
		STY		_tmpC+1
		PHA
		TSX
		LDA		$104,X
		STA		_tmp_ptrE
		CLC
		ADC		#$02
		STA		$104,X
		LDA		$105,X
		STA		_tmp_ptrE+1
		ADC		#$00
		STA		$105,X
		LDY		#$01
		LDA		(_tmp_ptrE),Y
		STA		_tmp_ptr0
		INY
		LDA		(_tmp_ptrE),Y
		STA		_tmp_ptr0+1
		PLA
		LDY		_tmpC+1
		LDX		_tmpC
		RTS

; =============== S U B R O U T I N E =======================================
_menu_init:
		LDA		#$00
		STA		_hor_menu_pos
		STA		_tmp49
		STA		_tmp_ptr4B
		STA		_tmp_ptr4B+1
		RTS

; =============== S U B R O U T I N E =======================================
_get_full_menu_input_unused:
		JSR		_get_param2
		LDY		#$00
		LDA		(_tmp_ptr0),Y
		JSR		_get_hor_menu_input
		PHP
		LDY		#$01
		LDA		(_tmp_ptr0),Y
		JSR		_get_vert_menu_input
		ROL
		PLP
		BCS		locret_B45C4
		LSR
locret_B45C4:
		RTS

; =============== S U B R O U T I N E =======================================
_menu_idx_changed:
		LDA		#$31
		JSR		_apu_se_req
		SEC
		RTS

; =============== S U B R O U T I N E =======================================
_menu_idx_unchanged:
		CLC
		RTS

; =============== S U B R O U T I N E =======================================
_get_hor_menu_input:
		TAY
		LDA		_hor_menu_pos
		STA		_tmp48
		LDA		_pads+4,X
		AND		#$40
		BEQ		loc_B45E4
		LDA		_hor_menu_pos
		BNE		loc_B45DF
		STY		_hor_menu_pos
loc_B45DF:
		DEC		_hor_menu_pos
		JMP		_menu_idx_changed
loc_B45E4:
		LDA		_pads+4,X
		AND		#$80
		BEQ		_menu_idx_unchanged
		INC		_hor_menu_pos
		CPY		_hor_menu_pos
		BEQ		loc_B45F2
		BCS		_menu_idx_changed
loc_B45F2:
		LDA		#$00
		STA		_hor_menu_pos
		BEQ		_menu_idx_changed

; =============== S U B R O U T I N E =======================================
_get_vert_menu_input:
		TAY
		LDA		_tmp49
		STA		_vert_menu_idx
		LDA		_pads+4,X
		AND		#$10
		BEQ		loc_B460E
		LDA		_tmp49
		BNE		loc_B4609
		STY		_tmp49
loc_B4609:
		DEC		_tmp49
		JMP		_menu_idx_changed
loc_B460E:
		LDA		_pads+4,X
		AND		#$20
		BEQ		_menu_idx_unchanged
		INC		_tmp49
		CPY		_tmp49
		BEQ		loc_B461C
		BCS		_menu_idx_changed
loc_B461C:
		LDA		#$00
		STA		_tmp49
		BEQ		_menu_idx_changed

; =============== S U B R O U T I N E =======================================
_draw_menu_cursor_param_unused:
		JSR		_get_param2

; =============== S U B R O U T I N E =======================================
_draw_menu_cursor:
		LDY		#$00
		LDA		(_tmp_ptr0),Y
		PHA
		INC		_tmp_ptr0
		BNE		loc_B4630
		INC		_tmp_ptr0+1
loc_B4630:
		INC		_tmp_ptr0
		BNE		loc_B4636
		INC		_tmp_ptr0+1
loc_B4636:
		LDA		_tmp_ptr4B
		ORA		_tmp_ptr4B+1
		BEQ		loc_B464C
		LDA		_tmp_ptr4B+1
		STA		_tmp_ptr44+1
		LDA		_tmp_ptr4B
		STA		_tmp_ptr44
		LDA		#$01
		JSR		_tlm_queue
		JMP		loc_B4652
loc_B464C:
		INC		_tmp_ptr0
		BNE		loc_B4652
		INC		_tmp_ptr0+1
loc_B4652:
		PLA
		LDX		#$00
		STX		_tmp_ptr2
		LDX		_tmp49
		BEQ		loc_B4666
		ASL
		TAY
loc_B465D:
		TYA
		CLC
		ADC		_tmp_ptr2
		STA		_tmp_ptr2
		DEX
		BNE		loc_B465D
loc_B4666:
		LDA		_hor_menu_pos
		ASL
		CLC
		ADC		_tmp_ptr2
		ADC		_tmp_ptr0
		STA		_tmp_ptr2
		LDA		_tmp_ptr0+1
		ADC		#$00
		STA		_tmp_ptr2+1
		LDY		#$01
		LDA		(_tmp_ptr2),Y
		STA		_tmp_ptr44
		STA		_tmp_ptr4B
		INY
		LDA		(_tmp_ptr2),Y
		STA		_tmp_ptr44+1
		STA		_tmp_ptr4B+1
		LDA		#$01
		JMP		_tlm_queue
_unused_1:
		.BYTE	$0A,$0A,$0A,$0A,$0A,$0A,$0A,$0A,$0A,$0A,$06,$0A,$06,$0A,$0A,$0A
_num_char_table1:
		.BYTE	$E8,$E9,$EA,$EB,$EC,$ED,$EE,$EF,$F0,$F1,$00,$00,$00,$00,$00,$00
		.BYTE	$01
_num_char_table0:
		.BYTE	$30,$31,$32,$33,$34,$35,$36,$37,$38,$39,$41,$42,$43,$44,$45,$46
		.BYTE	$00

; =============== S U B R O U T I N E =======================================
_printf_num9:
		AND		#$0F
		TAY
		LDA		_num_char_table0,Y
		STA		_ram_buf0
		LDA		#$01
		JSR		_tlm_queue_param
		.WORD	_ram_buf0
		RTS

; =============== S U B R O U T I N E =======================================
_obj_sys_calc00:
		LDX		#$00
		LDA		_tmp_ptr0+1
		ORA		_tmp_ptr2+1
		BNE		locret_B46F1
		LDA		_tmp_ptr2
		LDY		byte_9E
		JSR		_sub_minus16
		AND		#$F0
		STA		_tmp_ptr2
		CLC
		LDA		_tmp_ptr0
		ADC		byte_AC
		LSR
		LSR
		LSR
		LSR
		AND		#$0F
		ORA		_tmp_ptr2
		TAY
		LDX		byte_43A,Y
locret_B46F1:
		RTS

; =============== S U B R O U T I N E =======================================
_obj_sys_calc01:
		SEC
		LDA		_obj_y_lo_poss,X
		SBC		_obj_heigts,X
		BCC		loc_B4735
		LDA		_obj_y_lo_poss,X
		LDY		_obj_heigts,X
		JSR		_sub_minus16
		LDY		byte_9E
		JSR		_sub_minus16
		LDY		#$D0
		JSR		_obj_sys_calc02
		BCC		loc_B4735
		LDA		_obj_y_lo_poss,X
		LDY		_obj_heigts,X
		JSR		_sub_minus16
		LDY		byte_9E
		JSR		_sub_minus16
		LDY		#$10
		JSR		_add_plus16
		AND		#$F0
		LDY		_obj_heigts,X
		JSR		_add_plus16
		LDY		byte_9E
		JSR		_add_plus16
		STA		_obj_y_lo_poss,X
		SEC
		RTS
loc_B4735:
		CLC
		RTS

; =============== S U B R O U T I N E =======================================
_obj_sys_calc03:
		LDA		_obj_y_hi_poss,X
		BNE		loc_B4778
		STY		_tmp_ptr0
		LDA		_obj_y_lo_poss,X
		LDY		byte_9E
		JSR		_sub_minus16
		LDY		_tmp_ptr0
		JSR		_obj_sys_calc02
		BCC		loc_B4778
		LDA		#$00
		STA		_obj_y_accel,X
		LDA		_obj_y_lo_poss,X
		LDY		byte_9E
		JSR		_sub_minus16
		PHA
		LDA		_obj_y_hi_poss,X
		SBC		#$00
		STA		_obj_y_hi_poss,X
		PLA
		AND		#$F0
		LDY		byte_9E
		JSR		_add_plus16
		STA		_obj_y_lo_poss,X
		LDA		_obj_y_hi_poss,X
		ADC		#$00
		STA		_obj_y_hi_poss,X
		SEC
		RTS
loc_B4778:
		CLC
		RTS

; =============== S U B R O U T I N E =======================================
_obj_sys_calc02:
		AND		#$F0
		STA		_tmp_ptr4
		STY		_tmp_ptr4+1
		LDA		_obj_hps,X
		BEQ		loc_B47CD
		CLC
		LDA		_obj_x_lo_poss,X
		ADC		_obj_widths,X
		CLC
		ADC		byte_AC
		CLC
		ADC		#$0F
		AND		#$F0
		STA		_tmp_ptr2
		SEC
		LDA		_obj_x_lo_poss,X
		SBC		_obj_widths,X
		CLC
		ADC		byte_AC
		AND		#$F0
		STA		_tmp_ptr0
		LSR
		LSR
		LSR
		LSR
		ORA		_tmp_ptr4
		TAY
loc_B47AB:
		LDA		byte_43A,Y
		CMP		#$F9
		BEQ		loc_B47B6
		CMP		_tmp_ptr4+1
		BCS		loc_B47CF
loc_B47B6:
		TYA
		AND		#$F0
		STA		_tmp_ptr4
		INY
		TYA
		AND		#$0F
		ORA		_tmp_ptr4
		TAY
		CLC
		LDA		_tmp_ptr0
		ADC		#$10
		STA		_tmp_ptr0
		CMP		_tmp_ptr2
		BNE		loc_B47AB
loc_B47CD:
		CLC
		RTS
loc_B47CF:
		STA		_tmp_ptr4
		LDA		#$01
		SEC
		RTS

; =============== S U B R O U T I N E =======================================
_obj_sys_calc04:
		CLC
		LDA		_obj_x_lo_poss,X
		ADC		_obj_widths,X
		BCS		loc_B47FB
		JSR		_obj_sys_calc05
		BCC		loc_B47FB
		CLC
		LDA		_obj_x_lo_poss,X
		ADC		_obj_widths,X
		CLC
		ADC		byte_AC
		AND		#$F0
		SEC
		SBC		_obj_widths,X
		SEC
		SBC		byte_AC
		STA		_obj_x_lo_poss,X
		SEC
		RTS
loc_B47FB:
		CLC
		RTS

; =============== S U B R O U T I N E =======================================
_obj_sys_calc06:
		SEC
		LDA		_obj_x_lo_poss,X
		SBC		_obj_widths,X
		BCC		loc_B4826
		JSR		_obj_sys_calc05
		BCC		loc_B4826
		CLC
		LDA		_obj_x_lo_poss,X
		SBC		_obj_widths,X
		CLC
		ADC		byte_AC
		CLC
		ADC		#$10
		AND		#$F0
		SEC
		SBC		byte_AC
		CLC
		ADC		_obj_widths,X
		STA		_obj_x_lo_poss,X
		SEC
		RTS
loc_B4826:
		CLC
		RTS

; =============== S U B R O U T I N E =======================================
_obj_sys_calc05:
		CLC
		ADC		byte_AC
		AND		#$F0
		STA		byte_6
		LDA		_lvl_start_scroll_hor
		ADC		#$00
		STA		byte_7
		LDA		_obj_hps,X
		BEQ		loc_B48AA
		LDA		_obj_y_hi_poss,X
		BNE		loc_B48AA
		LDA		_obj_y_lo_poss,X
		BEQ		loc_B48AA
		LDY		byte_9E
		JSR		_sub_minus16
		LDY		#$0F
		JSR		_add_plus16
		AND		#$F0
		STA		_tmp_ptr4
		LDY		_obj_heigts,X
		BNE		loc_B4858
		INY
loc_B4858:
		LDA		_obj_y_lo_poss,X
		JSR		_sub_minus16
		BCS		loc_B4862
		LDA		#$00
loc_B4862:
		LDY		byte_B0
		JSR		_add_plus16
		AND		#$F0
		STA		byte_8
		LDA		_lvl_start_scroll_vert
		ADC		#$00
		STA		byte_9
		LDA		byte_6
		LSR
		LSR
		LSR
		LSR
		ORA		byte_8
		STA		_tmp_ptr4+1
loc_B487B:
		LDY		_tmp_ptr4+1
		LDA		byte_43A,Y
		CMP		#$F9
		BEQ		loc_B4888
		CMP		#$D0
		BCS		locret_B48AB
loc_B4888:
		LDA		_tmp_ptr4
		CMP		byte_8
		BEQ		loc_B48AA
		LDA		_tmp_ptr4+1
		LDY		#$10
		JSR		_add_plus16
		STA		_tmp_ptr4+1
		LDA		byte_8
		JSR		_add_plus16
		STA		byte_8
		LDA		byte_9
		ADC		#$00
		STA		byte_9
		LDA		_tmp_ptr4
		CMP		byte_8
		BNE		loc_B487B
loc_B48AA:
		CLC
locret_B48AB:
		RTS

; =============== S U B R O U T I N E =======================================
_get_cur_room_scroll_flag:
		LDA		_cur_prg_bank
		PHA
		LDA		_lvl_start_scroll_vert+1
		ASL
		ASL
		ASL
		AND		#$38
		STA		_tmp_ptr0
		LDA		_lvl_start_scroll_hor+1
		AND		#$07
		ORA		_tmp_ptr0
		TAY
		LDA		#$03
		JSR		_mmc1_prg_set
		LDA		(_room_scrolls_ptr),Y
		TAY
		JMP		_mmc1_prg_restore

; =============== S U B R O U T I N E =======================================
_sys_scroll_sub00:
		LDA		byte_AC,X
		STA		byte_AC,Y
		LDA		_lvl_start_scroll_hor,X
		STA		_lvl_start_scroll_hor,Y
		LDA		byte_B0,X
		STA		byte_B0,Y
		LDA		_lvl_start_scroll_vert,X
		STA		_lvl_start_scroll_vert,Y
		RTS

; =============== S U B R O U T I N E =======================================
_add_plus16:
		STY		_tmp_ptrE
		CLC
		ADC		_tmp_ptrE
		BCS		loc_B48EA
		CMP		#$F0
		BCC		locret_B48ED
loc_B48EA:
		ADC		#$0F
		SEC
locret_B48ED:
		RTS

; =============== S U B R O U T I N E =======================================
_sub_minus16:
		STY		_tmp_ptrE
		SEC
		SBC		_tmp_ptrE
		BCC		loc_B48F9
		CMP		#$F0
		BCC		loc_B48FE
loc_B48F9:
		SEC
		SBC		#$10
		CLC
		RTS
loc_B48FE:
		SEC
		RTS

; =============== S U B R O U T I N E =======================================
_farcall:
		STA		_tmp_ptr0
		STY		_tmp_ptr0+1
		LDA		_cur_prg_bank
		PHA
		LDA		#>[_mmc1_prg_restore-1]
		PHA
		LDA		#<[_mmc1_prg_restore-1]
		PHA
		JMP		(_tmp_ptr0)

; =============== S U B R O U T I N E =======================================
_mmc1_prg_restore:
		PLA
		JMP		_mmc1_prg_set

; =============== S U B R O U T I N E =======================================
_sys_room_draw_sub00:
		LDA		_cur_prg_bank
		PHA
		LDA		_tmp_ptr4
		PHA
		LDA		_tmp_ptr4+1
		PHA
		TXA
		PHA
		JSR		_room_pos_calc
		JSR		_room_drawA_ex_C
		JSR		_sys_room_draw_sub02
		PLA
		TAX
		PLA
		STA		_tmp_ptr4+1
		PLA
		STA		_tmp_ptr4
		JMP		_mmc1_prg_restore

; =============== S U B R O U T I N E =======================================
_sys_room_draw_sub03:
		LDA		_cur_prg_bank
		PHA
		LDA		_tmp_ptr4
		PHA
		LDA		_tmp_ptr4+1
		PHA
		TXA
		PHA
		JSR		_room_pos_calc
		LDX		#$F9
		JSR		_sys_room_draw_sub02
		PLA
		TAX
		PLA
		STA		_tmp_ptr4+1
		PLA
		STA		_tmp_ptr4
		JMP		_mmc1_prg_restore

; =============== S U B R O U T I N E =======================================
_room_pos_calc:
		LDA		byte_6
		STA		_tmpA
		LDA		byte_7
		LSR
		ROR		_tmpA
		LSR
		ROR		_tmpA
		LSR
		ROR		_tmpA
		LSR
		ROR		_tmpA
		LDA		byte_8
		STA		_tmpC
		LDA		byte_9
		LSR
		ROR		_tmpC
		LSR
		ROR		_tmpC
		LSR
		ROR		_tmpC
		LSR
		ROR		_tmpC
		RTS

; =============== S U B R O U T I N E =======================================
_room_scroll_pos_calc:
		LDA		byte_AD
		STA		_tmpA
		LDA		_lvl_start_scroll_hor+1
		LSR
		ROR		_tmpA
		LSR
		ROR		_tmpA
		LSR
		ROR		_tmpA
		LSR
		ROR		_tmpA
		LDA		byte_B1
		STA		_tmpC
		LDA		_lvl_start_scroll_vert+1
		LSR
		ROR		_tmpC
		LSR
		ROR		_tmpC
		LSR
		ROR		_tmpC
		LSR
		ROR		_tmpC
		RTS

; =============== S U B R O U T I N E =======================================
_room_calc_sys00:
		LDA		_tmpA
		AND		#$0F
		STA		byte_84+4
		LDA		_tmpC
		ASL
		ASL
		ASL
		ASL
		ORA		byte_84+4
		STA		byte_84+4
		TAY
		RTS

; =============== S U B R O U T I N E =======================================
_room_drawA_ex_A:
		LDA		_tmpA
		ASL
		AND		#$1E
		STA		byte_84
		LDA		_tmpC
		ROR
		ROR
		ROR
		AND		#$C0
		ORA		byte_84
		STA		byte_84
		LDA		_tmpA
		LSR
		LSR
		AND		#$04
		STA		byte_84+1
		BEQ		loc_B49D0
		LDA		_mmc1_ctrl_shadow
		LSR
		BCC		loc_B49D0
		ASL		byte_84+1
loc_B49D0:
		LDA		_tmpC
		LSR
		LSR
		AND		#$03
		ORA		byte_84+1
		ORA		#$20
		STA		byte_84+1
		STA		byte_84+2
		LDA		byte_84
		LSR		byte_84+2
		ROR
		LSR		byte_84+2
		ROR
		TAY
		AND		#$07
		STA		byte_84+2
		TYA
		LSR
		LSR
		AND		#$38
		ORA		byte_84+2
		ORA		#$C0
		STA		byte_84+2
		LDA		byte_84+1
		ORA		#$23
		STA		byte_84+3
		JSR		_room_calc_sys00

; =============== S U B R O U T I N E =======================================
_room_attr_calc_sys00:
		LDA		_tmpA
		LSR
		AND		#$07
		STA		_tmp_ptr0+1
		LDA		_tmpA
		ASL
		ASL
		AND		#$40
		ORA		_tmp_ptr0+1
		STA		_tmp_ptr0+1
		LDA		_tmpC
		ASL
		ASL
		AND		#$38
		ORA		_tmp_ptr0+1
		TAY
		RTS

; =============== S U B R O U T I N E =======================================
_room_drawB_get_tiles_left_ptr:
		LDA		_room_tileset_ptr
		LDY		_room_tileset_ptr+1
		STA		_tmp_ptr0
		STA		_tmp_ptr2
		STY		_tmp_ptr0+1
		INY
		INY
		STY		_tmp_ptr2+1
		RTS

; =============== S U B R O U T I N E =======================================
_room_drawB_get_tiles_right_ptr:
		JSR		_room_drawB_get_tiles_left_ptr
		INC		_tmp_ptr0+1
		INC		_tmp_ptr2+1
		RTS

; =============== S U B R O U T I N E =======================================
_room_drawA_ex_C:
		LDA		_tmpA
		CMP		#$80
		BCS		loc_B4A58
		LDA		_tmpC
		CMP		#$80
		BCS		loc_B4A58
		LDA		#$03
		JSR		_mmc1_prg_set
		LDA		_tmpA
		LSR
		LSR
		LSR
		LSR
		AND		#$07
		STA		_tmp_ptr0
		LDA		_tmpC
		LSR
		AND		#$38
		ORA		_tmp_ptr0
		TAY
		LDA		(_room_layout_ptr),Y
		BNE		loc_B4A5C
loc_B4A58:
		LDX		#$D0
		SEC
		RTS
loc_B4A5C:
		TAX
		DEX
		JSR		_room_calc_sys00
		LDA		#$00
		JSR		_mmc1_prg_set
		LDA		_lvl_ofs_tbl_lo,X
		STA		_tmp_ptrE
		LDA		_lvl_ofs_tbl_hi,X
		TAX
		ROL
		ROL
		ROL
		AND		#$03
		CLC
		ADC		#$00
		JSR		_mmc1_prg_set
		TXA
		AND		#$3F
		ORA		#$80
		STA		_tmp_ptrE+1
		LDA		(_tmp_ptrE),Y
		TAX
		CLC
		RTS

; =============== S U B R O U T I N E =======================================
_room_drawA_ex_E:
		TAX
		LSR
		LSR
		TAY
		TXA
		AND		#$03
		TAX
		LDA		_room_tileset_ptr
		STA		_tmp_ptr0
		CLC
		LDA		_room_tileset_ptr+1
		ADC		#$04
		STA		_tmp_ptr0+1
		LDA		(_tmp_ptr0),Y
loc_B4A9B:
		DEX
		BMI		loc_B4AA3
		LSR
		LSR
		JMP		loc_B4A9B
loc_B4AA3:
		AND		#$03
		STA		_tmp_ptr0
		JSR		_room_attr_calc_sys00
		LDX		#$00
		LDA		_tmpA
		LSR
		BCC		loc_B4AB6
		INX
		ASL		_tmp_ptr0
		ASL		_tmp_ptr0
loc_B4AB6:
		LDA		_tmpC
		LSR
		BCC		loc_B4AC5
		INX
		INX
		ASL		_tmp_ptr0
		ASL		_tmp_ptr0
		ASL		_tmp_ptr0
		ASL		_tmp_ptr0
loc_B4AC5:
		LDA		byte_100,Y
		AND		byte_B4AD1,X
		ORA		_tmp_ptr0
		STA		byte_100,Y
		RTS
byte_B4AD1:
		.BYTE	$FC,$F3,$CF,$3F

; =============== S U B R O U T I N E =======================================
_sys_room_draw_sub04:
		STX		byte_91
		JSR		_room_drawA_ex_A
		STY		byte_84+5
		JSR		_room_calc_sys00
		JMP		_sys_room_draw_sub02_ex

; =============== S U B R O U T I N E =======================================
_sys_room_draw_sub02:
		STX		byte_91
		JSR		_room_drawA_ex_A
		STY		byte_84+5
		JSR		_room_calc_sys00
		LDA		byte_91
		STA		byte_43A,Y

; =============== S U B R O U T I N E =======================================
_sys_room_draw_sub02_ex:
		LDA		#$03
		JSR		_mmc1_prg_set
		LDA		byte_91
		JSR		_room_drawA_ex_E
		LDX		#$00
		JSR		_room_drawB_get_tiles_left_ptr
		JSR		_sys_room_draw_sub05
		INC		_tmp_ptr0+1
		INC		_tmp_ptr2+1
		INC		byte_84
		JSR		_sys_room_draw_sub05
		LDA		byte_84+3
		STA		_ram_buf0,X
		INX
		LDA		byte_84+2
		STA		_ram_buf0,X
		INX
		LDA		#$41
		STA		_ram_buf0,X
		INX
		LDY		byte_84+5
		LDA		byte_100,Y
		STA		_ram_buf0,X
		INX
		LDA		#$00
		STA		_ram_buf0,X
		LDA		#<[_ram_buf0]
		STA		_tmp_ptr0
		LDA		#>[_ram_buf0]
		STA		_tmp_ptr0+1
		JMP		_tlm_res_queue

; =============== S U B R O U T I N E =======================================
_sys_room_draw_sub05:
		LDA		byte_84+1
		STA		_ram_buf0,X
		INX
		LDA		byte_84
		STA		_ram_buf0,X
		INX
		LDA		#$42
		STA		_ram_buf0,X
		INX
		LDY		byte_91
		LDA		(_tmp_ptr0),Y
		STA		_ram_buf0,X
		INX
		LDA		(_tmp_ptr2),Y
		STA		_ram_buf0,X
		INX
		RTS

; =============== S U B R O U T I N E =======================================
_room_drawA_ex_init:
		STY		byte_84+5
		LDX		#$05
loc_B4B5C:
		LDA		byte_84,X
		STA		byte_8A,X
		DEX
		BPL		loc_B4B5C
		RTS

; =============== S U B R O U T I N E =======================================
_room_drawA:
		LDA		byte_8A+4
		AND		#$0F
		TAY
		LDX		#$00
loc_B4B6B:
		LDA		_room_tiles_tmp_buf,X
		STA		byte_43A,Y
		TYA
		CLC
		ADC		#$10
		TAY
		INX
		CPX		#$0F
		BCC		loc_B4B6B

; =============== S U B R O U T I N E =======================================
_room_objects_managerA:
		LDA		_tmpA
		STA		byte_82
		LDA		_tmpC
		STA		byte_83
		JSR		_room_drawA_ex_A
		JSR		_room_drawA_ex_init
		JSR		_room_drawA_ex_C
		BCC		loc_B4B91
		JMP		_room_drawB_reset_idx
loc_B4B91:
		LDX		#$00
loc_B4B93:
		LDA		(_tmp_ptrE),Y
		STA		_room_tiles_tmp_buf,X
		TYA
		CLC
		ADC		#$10
		TAY
		INX
		CPX		#$0F
		BCC		loc_B4B93
		LDA		#$03
		JSR		_mmc1_prg_set
loc_B4BA7:
		LDY		#$00
		LDA		(_room_prizes_ptr),Y
		CMP		_tmpA
		BNE		loc_B4BD0
		INY
		LDA		(_room_prizes_ptr),Y
		PHA
		AND		#$0F
		TAX
		PLA
		LSR
		LSR
		LSR
		LSR
		ORA		#$F0
		STA		_room_tiles_tmp_buf,X
		CLC
		LDA		_room_prizes_ptr
		ADC		#$02
		STA		_room_prizes_ptr
		LDA		_room_prizes_ptr+1
		ADC		#$00
		STA		_room_prizes_ptr+1
		JMP		loc_B4BA7
loc_B4BD0:
		LDA		#$03
		JSR		_mmc1_prg_set
loc_B4BD5:
		LDY		#$00
		LDA		(_room_enemies_ptr),Y
		CMP		_tmpA
		BNE		loc_B4BFC
		STA		byte_95
		INY
		LDA		(_room_enemies_ptr),Y
		STA		byte_96
		INY
		LDA		(_room_enemies_ptr),Y
		STA		byte_97
		JSR		_obj_scr_insert
		CLC
		LDA		_room_enemies_ptr
		ADC		#$03
		STA		_room_enemies_ptr
		LDA		_room_enemies_ptr+1
		ADC		#$00
		STA		_room_enemies_ptr+1
		JMP		loc_B4BD5
loc_B4BFC:
		LDA		#$03
		JSR		_mmc1_prg_set
		LDX		#$00
loc_B4C03:
		TXA
		PHA
		LDA		_room_tiles_tmp_buf,X
		JSR		_room_drawA_ex_E
		INC		_tmpC
		PLA
		TAX
		INX
		CPX		#$0F
		BCC		loc_B4C03
		LDA		#$01
		STA		_room_drawB_sub_idx
		JMP		_room_draw_next_idx

; =============== S U B R O U T I N E =======================================
_room_drawB_queue_tiles_left:
		JSR		_room_drawB_get_tiles_left_ptr
		JMP		_room_queue_tiles_ex

; =============== S U B R O U T I N E =======================================
_room_drawB_queue_tiles_right:
		JSR		_room_drawB_get_tiles_right_ptr
		INC		byte_8A

; =============== S U B R O U T I N E =======================================
_room_queue_tiles_ex:
		LDA		byte_8A
		LDY		byte_8A+1
		STY		_ram_buf0
		STA		_ram_buf0+1
		LDA		#$5E
		STA		_ram_buf0+2
		LDA		#$03
		JSR		_mmc1_prg_set
		LDX		#$03
		LDY		#$00
loc_B4C3E:
		TYA
		PHA
		LDA		_room_tiles_tmp_buf,Y
		TAY
		LDA		(_tmp_ptr0),Y
		STA		_ram_buf0,X
		INX
		LDA		(_tmp_ptr2),Y
		STA		_ram_buf0,X
		INX
		PLA
		TAY
		INY
		CPY		#$0F
		BCC		loc_B4C3E
		JMP		_room_draw_ram_buf_flush

; =============== S U B R O U T I N E =======================================
_room_drawB_sub5:
		LDX		#$00
loc_B4C5C:
		LDA		byte_8A+3
		STA		_ram_buf0,X
		INX
		LDA		byte_8A+2
		STA		_ram_buf0,X
		INX
		LDA		#$41
		STA		_ram_buf0,X
		INX
		LDY		byte_8A+5
		LDA		byte_100,Y
		STA		_ram_buf0,X
		INX
		CLC
		LDA		byte_8A+2
		ADC		#$08
		STA		byte_8A+2
		CLC
		LDA		byte_8A+5
		ADC		#$08
		STA		byte_8A+5
		CPX		#$20
		BCC		loc_B4C5C
		JSR		_room_draw_ram_buf_flush
		JMP		_room_drawB_reset_idx

; =============== S U B R O U T I N E =======================================
_room_objects_managerB:
		LDA		#$FF
		STA		byte_82
		STA		byte_83
		JSR		_room_drawA_ex_A
		JSR		_room_drawA_ex_init
		JSR		_room_drawA_ex_C
		BCC		loc_B4CA3
		JMP		_room_drawB_reset_idx
loc_B4CA3:
		LDA		(_tmp_ptrE),Y
		STA		byte_43A,Y
		INY
		TYA
		AND		#$0F
		BNE		loc_B4CA3
		LDA		#$03
		JSR		_mmc1_prg_set
loc_B4CB3:
		LDY		#$00
		LDA		(_room_prizes_ptr),Y
		BPL		loc_B4CEA
		AND		#$7F
		CMP		_tmpC
		BNE		loc_B4CEA
		INY
		LDA		(_room_prizes_ptr),Y
		PHA
		AND		#$0F
		STA		_tmp_ptr0
		LDA		_tmpC
		ASL
		ASL
		ASL
		ASL
		ORA		_tmp_ptr0
		TAX
		PLA
		LSR
		LSR
		LSR
		LSR
		ORA		#$F0
		STA		byte_43A,X
		CLC
		LDA		_room_prizes_ptr
		ADC		#$02
		STA		_room_prizes_ptr
		LDA		_room_prizes_ptr+1
		ADC		#$00
		STA		_room_prizes_ptr+1
		JMP		loc_B4CB3
loc_B4CEA:
		LDA		#$03
		JSR		_mmc1_prg_set
loc_B4CEF:
		LDY		#$00
		LDA		(_room_enemies_ptr),Y
		BPL		loc_B4D20
		CMP		#$FF
		BEQ		loc_B4D20
		TAX
		INY
		LDA		(_room_enemies_ptr),Y
		CMP		_tmpC
		BNE		loc_B4D20
		STA		byte_96
		INY
		LDA		(_room_enemies_ptr),Y
		STA		byte_97
		TXA
		AND		#$7F
		STA		byte_95
		JSR		_obj_scr_insert
		CLC
		LDA		_room_enemies_ptr
		ADC		#$03
		STA		_room_enemies_ptr
		LDA		_room_enemies_ptr+1
		ADC		#$00
		STA		_room_enemies_ptr+1
		JMP		loc_B4CEF
loc_B4D20:
		LDA		#$03
		JSR		_mmc1_prg_set
		LDX		byte_8A+4
loc_B4D27:
		TXA
		PHA
		LDA		byte_43A,X
		JSR		_room_drawA_ex_E
		INC		_tmpA
		PLA
		CLC
		ADC		#$01
		TAX
		AND		#$0F
		BNE		loc_B4D27
		LDA		#$07
		STA		_room_drawB_sub_idx
		JMP		_room_draw_next_idx

; =============== S U B R O U T I N E =======================================
_room_drawB_sub8:
		LDA		_room_tileset_ptr
		LDY		_room_tileset_ptr+1
		JMP		_room_drawB_sub9_A

; =============== S U B R O U T I N E =======================================
_room_drawB_sub9:
		CLC
		LDA		byte_8A
		ADC		#$20
		STA		byte_8A
		LDA		_room_tileset_ptr
		LDY		_room_tileset_ptr+1
		INY
		INY
		JSR		_room_drawB_sub9_A
		JMP		_room_drawB_sub9_B

; =============== S U B R O U T I N E =======================================
_room_drawB_sub9_A:
		STA		_tmp_ptr0
		STY		_tmp_ptr0+1
		INY
		STA		_tmp_ptr2
		STY		_tmp_ptr2+1
		LDA		#$03
		JSR		_mmc1_prg_set
		LDA		byte_8A
		LDY		byte_8A+1
		STY		_ram_buf0
		STA		_ram_buf0+1
		LDA		#$20
		STA		_ram_buf0+2
		LDX		#$03
		LDY		byte_8A+4
loc_B4D7C:
		TYA
		PHA
		LDA		byte_43A,Y
		TAY
		LDA		(_tmp_ptr0),Y
		STA		_ram_buf0,X
		INX
		LDA		(_tmp_ptr2),Y
		STA		_ram_buf0,X
		INX
		PLA
		CLC
		ADC		#$01
		TAY
		AND		#$0F
		BNE		loc_B4D7C
		JMP		_room_draw_ram_buf_flush

; =============== S U B R O U T I N E =======================================
_room_drawB_sub9_B:
		LDA		byte_8A+2
		LDY		byte_8A+3
		STY		_ram_buf0
		STA		_ram_buf0+1
		LDA		#$08
		STA		_ram_buf0+2
		LDX		#$03
		LDY		byte_8A+5
loc_B4DAD:
		LDA		byte_100,Y
		STA		_ram_buf0,X
		INX
		INY
		CPX		#$0B
		BCC		loc_B4DAD
		JSR		_room_draw_ram_buf_flush
		JMP		_room_drawB_reset_idx

; =============== S U B R O U T I N E =======================================
_room_drawB:
		LDA		_room_drawB_sub_idx
		JSR		_switch
		.WORD	_room_drawB_reset_idx
		.WORD	_room_drawA
		.WORD	_room_draw_next_idx
		.WORD	_room_drawB_queue_tiles_left
		.WORD	_room_drawB_queue_tiles_right
		.WORD	_room_drawB_sub5
		.WORD	_room_drawB_reset_idx
		.WORD	_room_objects_managerB
		.WORD	_room_drawB_sub8
		.WORD	_room_drawB_sub9

; =============== S U B R O U T I N E =======================================
_room_draw_ram_buf_flush:
		LDA		#$00
		STA		_ram_buf0,X
		LDA		#<[_ram_buf0]
		STA		_tmp_ptr0
		LDA		#>[_ram_buf0]
		STA		_tmp_ptr0+1
		JSR		_tlm_res_queue

; =============== S U B R O U T I N E =======================================
_room_draw_next_idx:
		INC		_room_drawB_sub_idx
		RTS

; =============== S U B R O U T I N E =======================================
_room_drawB_reset_idx:
		LDA		#$00
		STA		_room_drawB_sub_idx
		RTS

; =============== S U B R O U T I N E =======================================
_room_full_draw:
		DEC		_tmpA
		LDY		#$12
loc_B4DF4:
		TYA
		PHA
		LDA		_tmpA
		PHA
		LDA		_tmpC
		PHA
		JSR		_room_drawA
loc_B4DFF:
		JSR		_room_drawB
		LDA		_room_drawB_sub_idx
		BNE		loc_B4DFF
		PLA
		STA		_tmpC
		PLA
		STA		_tmpA
		PLA
		TAY
		INC		_tmpA
		DEY
		BNE		loc_B4DF4
		RTS

; =============== S U B R O U T I N E =======================================
_apu_wait_unref:
		LDA		#$01
		JSR		_wait_for_frames
		LDA		_apu_active_chnls_flags
		AND		#$0F
		BNE		_apu_wait_unref
		RTS

; =============== S U B R O U T I N E =======================================
_apu_mus_req:
		CMP		#$0F
		BEQ		loc_B4E2C
		CMP		#$79
		BCS		loc_B4E2E
		CMP		_cur_mus_playing
		BEQ		locret_B4E30
loc_B4E2C:
		STA		_cur_mus_playing
loc_B4E2E:
		STA		_apu_load_idx
locret_B4E30:
		RTS

; =============== S U B R O U T I N E =======================================
_apu_se_req:
		LDY		_apu_load_idx
		BMI		loc_B4E3D
		CPY		#$22
		BCC		locret_B4E52
		CPY		#$79
		BCS		locret_B4E52
loc_B4E3D:
		TAY
		CPY		#$72
		BEQ		loc_B4E4A
		CPY		#$72
		BEQ		loc_B4E4A
		CPY		#$72
		BNE		loc_B4E50
loc_B4E4A:
		LDA		_apu_active_chnls_flags
		AND		#$F0
		BNE		locret_B4E52
loc_B4E50:
		STY		_apu_load_idx
locret_B4E52:
		RTS

; =============== S U B R O U T I N E =======================================
_rand:
		LDA		_nmi_frames_counter
		ADC		_nmi_frames_counter+1
		ADC		_rand_seed
		STA		_rand_seed
		INC		_rand_seed
		RTS

; =============== S U B R O U T I N E =======================================
_rand_scale:
		JSR		_rand
		STA		_tmp_ptrE
		STY		_tmp_ptr2
		LDA		#$00
		STA		_tmp_ptrE+1
		LDY		#$08
loc_B4E6B:
		ASL		_tmp_ptrE
		ROL		_tmp_ptrE+1
		LDA		_tmp_ptrE+1
		SEC
		SBC		_tmp_ptr2
		BCC		loc_B4E7A
		STA		_tmp_ptrE+1
		INC		_tmp_ptrE
loc_B4E7A:
		DEY
		BNE		loc_B4E6B
		LDA		_tmp_ptrE
		LDY		_tmp_ptrE+1
		RTS

; =============== S U B R O U T I N E =======================================
_rle_unpack:
		JSR		_ppu_increment_1
		LDA		_PPU_STATUS
		STY		_PPU_ADDR
		STX		_PPU_ADDR
		LDY		#$00
		JSR		_stream_get_byte
		STA		_tmp_ptr2
loc_B4E95:
		JSR		_stream_get_byte
		CMP		_tmp_ptr2
		BEQ		loc_B4EA1
		STA		_PPU_DATA
		BNE		loc_B4E95
loc_B4EA1:
		JSR		_stream_get_byte
		TAX
		BEQ		locret_B4EB2
		JSR		_stream_get_byte
loc_B4EAA:
		STA		_PPU_DATA
		DEX
		BNE		loc_B4EAA
		BEQ		loc_B4E95
locret_B4EB2:
		RTS

; =============== S U B R O U T I N E =======================================
_stream_get_byte:
		LDA		(_tmp_ptr0),Y
		INC		_tmp_ptr0
		BNE		locret_B4EBB
		INC		_tmp_ptr0+1
locret_B4EBB:
		RTS

; =============== S U B R O U T I N E =======================================
_wnd_msg_handler:
		LDA		_wnd_msg_sub_idx
		JSR		_switch
		.WORD	nullsub1
		.WORD	_wnd_msg_sub1_char_put
		.WORD	_wnd_msg_sub2_pause
		.WORD	_wnd_msg_sub3_char_delay
		.WORD	_wnd_msg_sub4_reset
		.WORD	_wnd_msg_sub5_clear

; =============== S U B R O U T I N E =======================================
nullsub1:
		RTS

; =============== S U B R O U T I N E =======================================
_wnd_msg_sub1_char_put:
		LDA		#$00
		STA		_wnd_msg_char_send_flag

; =============== S U B R O U T I N E =======================================
_wnd_msg_char_printf:
		JSR		_wnd_msg_char_fetch
		LDA		_wnd_msg_dict_idx
		JSR		_wnd_msg_dict_special_check
		BEQ		_wnd_msg_char_printf
		CMP		#$FD
		BCC		_wnd_msg_common_char_printf
		SEC
		SBC		#$FD
		JSR		_switch
		.WORD	_wnd_msg_ctrl_wait
		.WORD	_wnd_msg_ctrl_return
		.WORD	_wnd_msg_ctrl_stop

; =============== S U B R O U T I N E =======================================
_wnd_msg_ctrl_return:
		INC		_cur_wnd_msg_row
		INC		_cur_wnd_msg_row
		LDA		#$00
		STA		_cur_wnd_msg_col
		LDA		_wnd_msg_next_dict_idx
		CMP		#$FF
		BNE		locret_B4F42

; =============== S U B R O U T I N E =======================================
_wnd_msg_ctrl_stop:
		LDA		#$00
		STA		_wnd_msg_sub_idx
		BEQ		locret_B4F42

; =============== S U B R O U T I N E =======================================
_wnd_msg_ctrl_wait:
		LDA		#$78
		STA		_wnd_msg_delay_timer
		INC		_wnd_msg_sub_idx
		INC		_wnd_msg_sub_idx
		RTS

; =============== S U B R O U T I N E =======================================
_wnd_msg_common_char_printf:
		CLC
		ADC		#$30
		TAY
		LDA		#$40
		CPY		#$80
		BCC		loc_B4F17
		TYA
		CLC
		ADC		#$10
loc_B4F17:
		JSR		_wnd_msg_char_queue
		INC		_cur_wnd_msg_col
		INC		_wnd_msg_char_send_flag
		LDA		_wnd_msg_delay_default
		STA		_wnd_msg_delay_timer
		BEQ		loc_B4F2E
		LDA		_wnd_msg_sub_idx
		CMP		#$04
		BCS		loc_B4F39
		LDA		_wnd_msg_skip_delay
		BEQ		loc_B4F36
loc_B4F2E:
		LDA		_wnd_msg_char_send_flag
		CMP		#$01
		BCC		_wnd_msg_char_printf
		BCS		locret_B4F42
loc_B4F36:
		JSR		_wnd_msg_skip_test
loc_B4F39:
		LDA		_wnd_msg_se_idx
		BEQ		loc_B4F40
		JSR		_apu_se_req
loc_B4F40:
		INC		_wnd_msg_sub_idx
locret_B4F42:
		RTS

; =============== S U B R O U T I N E =======================================
_wnd_msg_sub2_pause:
		JSR		_wnd_msg_skip_test
		DEC		_wnd_msg_delay_timer
		BNE		locret_B4F50
		LDA		#$80
		STA		_wnd_msg_delay_timer
		DEC		_wnd_msg_sub_idx
locret_B4F50:
		RTS

; =============== S U B R O U T I N E =======================================
_wnd_msg_skip_test:
		LDA		_pads
		ORA		_pads+1
		AND		#$02
		BEQ		locret_B4F5B
		INC		_wnd_msg_skip_delay
locret_B4F5B:
		RTS

; =============== S U B R O U T I N E =======================================
_wnd_msg_sub3_char_delay:
		LDA		_pads+4
		ORA		_pads+5
		AND		#$02
		BNE		_wnd_msg_sub4_reset
		DEC		_wnd_msg_delay_timer
		BEQ		_wnd_msg_sub4_reset
		RTS

; =============== S U B R O U T I N E =======================================
_wnd_msg_sub4_reset:
		LDX		#$00
		STX		_wnd_msg_dict_in_use_flag
		STX		_cur_wnd_msg_row
		STX		_cur_wnd_msg_col
		STX		_wnd_msg_skip_delay
		INC		_wnd_msg_sub_idx

; =============== S U B R O U T I N E =======================================
_wnd_msg_sub5_clear:
		JSR		_wnd_msg_char_pos_calc
		LDA		_wnd_msg_area_width
		ORA		#$80
		STA		_ram_buf0
		LDA		#$81
		STA		_ram_buf0+1
		LDA		#$40
		STA		_ram_buf0+2
		LDA		#<[_ram_buf0]
		STA		_tmp_ptr0
		LDA		#>[_ram_buf0]
		STA		_tmp_ptr0+1
		JSR		_rect_draw
		INC		_cur_wnd_msg_row
		LDX		_cur_wnd_msg_row
		CPX		_wnd_msg_area_heigth
		BNE		locret_B4FA7
		LDX		#$00
		STX		_cur_wnd_msg_row
		SEC
		LDA		_wnd_msg_sub_idx
		SBC		#$04
		STA		_wnd_msg_sub_idx
locret_B4FA7:
		RTS

; =============== S U B R O U T I N E =======================================
_wnd_msg_dict_special_check:
		CMP		#$6E
		BEQ		locret_B4FAE
		CMP		#$6F
locret_B4FAE:
		RTS

; =============== S U B R O U T I N E =======================================
_wnd_msg_char_queue:
		STY		_ram_buf0
		STA		_ram_buf0+1
		JSR		_wnd_msg_char_pos_calc
		LDA		#<[_ram_buf0]
		STA		_tmp_ptr0
		LDA		#>[_ram_buf0]
		STA		_tmp_ptr0+1
		LDA		#$42
		JMP		_tlm_queue

; =============== S U B R O U T I N E =======================================
_wnd_msg_char_pos_calc:
		LDA		#$00
		STA		_tmp_ptr0
		LDA		_cur_wnd_msg_row
		LSR
		ROR		_tmp_ptr0
		LSR
		ROR		_tmp_ptr0
		LSR
		ROR		_tmp_ptr0
		STA		_tmp_ptr0+1
		LDA		_tmp_ptr0
		ORA		_cur_wnd_msg_col
		CLC
		ADC		_wnd_msg_ppu_ofs
		STA		_tmp_ptr44
		LDA		_tmp_ptr0+1
		ADC		_wnd_msg_ppu_ofs+1
		STA		_tmp_ptr44+1
		RTS

; =============== S U B R O U T I N E =======================================
_wnd_msg_char_fetch:
		LDA		#$02
		JSR		_mmc1_prg_set
loc_B4FEB:
		LDY		#$01
		LDA		(_wnd_msg_ptr),Y
		STA		_wnd_msg_next_dict_idx
		DEY
		LDA		(_wnd_msg_ptr),Y
		STA		_wnd_msg_dict_idx
		INC		_wnd_msg_ptr
		BNE		loc_B4FFC
		INC		_wnd_msg_ptr+1
loc_B4FFC:
		CMP		#$FD
		BCS		loc_B501F
		CMP		#$80
		BCC		locret_B5030
		LDA		_wnd_msg_ptr
		STA		_wnd_msg_ptr_backup
		LDA		_wnd_msg_ptr+1
		STA		_wnd_msg_ptr_backup+1
		LDA		_wnd_msg_dict_idx
		ASL
		TAY
		LDA		_dictionary,Y
		STA		_wnd_msg_ptr
		LDA		_dictionary+1,Y
		STA		_wnd_msg_ptr+1
		INC		_wnd_msg_dict_in_use_flag
		JMP		loc_B4FEB
loc_B501F:
		LDA		_wnd_msg_dict_in_use_flag
		BEQ		locret_B5030
		LDA		_wnd_msg_ptr_backup
		STA		_wnd_msg_ptr
		LDA		_wnd_msg_ptr_backup+1
		STA		_wnd_msg_ptr+1
		DEC		_wnd_msg_dict_in_use_flag
		JMP		loc_B4FEB
locret_B5030:
		RTS
_bitmasks_0:
		.BYTE	$01,$02,$04,$08,$10,$20,$40,$80

; =============== S U B R O U T I N E =======================================
_pal_fade_out:
		LDX		#$04
		LDA		#$FF
		JSR		_set_pal_fade_out
		JSR		_wait_for_pal_fade_is_over

; =============== S U B R O U T I N E =======================================
_MAIN_START:
		LDX		#$FF
		TXS
		JSR		_render_off
		LDA		#$01
		STA		_ppu_queue0_done_flag
		LDX		#$00
		STX		byte_30
		STX		_ppu_queue0_increment_mode
		STX		_ppu_queue0_flag
		STX		_ppu_queue0_buf
		STX		_room_drawB_sub_idx
		STX		byte_92
		STX		_ingame_mode_idx
		STX		_wnd_split_ppu_ofs+1
		STX		_apu_load_idx_req
		STX		_wnd_msg_sub_idx
		STX		_stage_flags
		STX		_pal_anim_mode_idx
		STX		byte_7F
		JSR		_clear_stack
		JSR		_spr_reset
		JSR		_mmc1_init
		DEC		_ppu_queue0_done_flag
		JSR		_main_screen_init
		JSR		_main_screen_draw
		LDA		_main_sub_idx
		JSR		_switch
		.WORD	_main0_license
		.WORD	_main1_intro
		.WORD	_main2_title
		.WORD	_main3_cutscenes
		.WORD	_main4_ingame
		.WORD	_main5_stage_complete
		.WORD	_main4_ingame
		.WORD	_main7_game_over
		.WORD	_main8_continue
		.WORD	_main9_unused

; =============== S U B R O U T I N E =======================================
_MAIN_LOOP_START:
		JSR		_obj_scr_manager
		JSR		_render_on
		LDX		#$04
		LDA		#$FF
		JSR		_set_pal_fade_in
		JSR		_wait_for_pal_fade_is_over
_loop:
		LDA		#$01
		JSR		_wait_for_frames
		LDA		_cutscene_idx
		BNE		loc_B50B6
		LDA		#$03
		JSR		_mmc1_prg_set
		JSR		_pal_anim_handlers
loc_B50B6:
		JSR		_obj_scr_manager
		JSR		_wnd_msg_handler
		LDA		_stage_flags
		BEQ		_loop
		JMP		_MAIN_START

; =============== S U B R O U T I N E =======================================
_main0_license:
		LDY		#$01
		JSR		_scr_load_param
		.WORD	_script_license
		JMP		_MAIN_LOOP_START

; =============== S U B R O U T I N E =======================================
_main9_unused:
		LDY		#$01
		JSR		_scr_load_param
		.WORD	_script_unused
		JMP		_MAIN_LOOP_START

; =============== S U B R O U T I N E =======================================
_main1_intro:
		LDY		#$01
		JSR		_scr_load_param
		.WORD	_script_intro
		LDA		#$7F
		JSR		_apu_mus_req
		JMP		_MAIN_LOOP_START

; =============== S U B R O U T I N E =======================================
_main2_title:
		LDY		#$01
		JSR		_scr_load_param
		.WORD	_script_title
		LDA		#$01
		JSR		_apu_mus_req
		JMP		_MAIN_LOOP_START
byte_B50F5:
		.BYTE	$01,$02,$03

; =============== S U B R O U T I N E =======================================
_main3_cutscenes:
		LDY		#$01
		JSR		_scr_load_param
		.WORD	_script_cutscenes
		JMP		_MAIN_LOOP_START

; =============== S U B R O U T I N E =======================================
_main5_stage_complete:
		LDA		#<[_script_stage_complete]
		STA		_tmp_ptr0
		LDA		#>[_script_stage_complete]
		STA		_tmp_ptr0+1
		LDA		#$00
		STA		_tmp_ptr2
		STA		_tmp_ptr2+1
		STA		_tmp_ptr4
		STA		_tmp_ptr4+1
		STA		byte_6
		LDX		#$02
		LDY		#$01
		JSR		_scr_load_ex
		JMP		_MAIN_LOOP_START

; =============== S U B R O U T I N E =======================================
_main7_game_over:
		LDY		#$01
		JSR		_scr_load_param
		.WORD	_script_game_over
		LDA		#$1D
		JSR		_apu_mus_req
		JMP		_MAIN_LOOP_START

; =============== S U B R O U T I N E =======================================
_main8_continue:
		LDY		#$01
		JSR		_scr_load_param
		.WORD	_script_continue
		JMP		_MAIN_LOOP_START

; =============== S U B R O U T I N E =======================================
_main4_ingame:
		LDA		#$02
		JSR		_mmc1_prg_set
		LDX		#$00
		JSR		_players_obj_insert
		LDX		#$01
		JSR		_players_obj_insert
		LDX		#$FF
		LDY		#$00
		JSR		_is_is_stage4_ingame
		BNE		loc_B5155
		LDX		#$3B
		LDY		#$03
loc_B5155:
		LDA		#$00
		STY		_stage4_minutes_cnt
		STA		_stage4_seconds_cnt
		STX		_stage4_frames_cnt
		JSR		_obj_scr_manager
		JSR		_hud_obj_managers
		JSR		_render_on
		LDX		#$04
		LDA		#$FF
		JSR		_set_pal_fade_in
		JSR		_wait_for_pal_fade_is_over

; =============== S U B R O U T I N E =======================================
_ingame_loop:
		LDA		#$01
		JSR		_wait_for_frames
		LDA		#$03
		JSR		_mmc1_prg_set
		JSR		_pal_anim_handlers
		LDA		_ingame_mode_idx
		JSR		_switch
		.WORD	_ingame_loop_idle
		.WORD	_ingame_loop_pause
		.WORD	_ingame_loop_status
		.WORD	_ingame_loop_engine

; =============== S U B R O U T I N E =======================================
_ingame_loop_idle:
		LDA		_pal_fade_req
		BNE		loc_B519A
		LDA		_main_sub_idx
		CMP		#$04
		BNE		loc_B519A
		LDA		_room_flags
		AND		#$08
		BEQ		_select_press_test
loc_B519A:
		JMP		_ingame_loop_engine
_select_press_test:
		LDA		_pads+4
		AND		#$04
		BNE		_status_display
		JMP		_start_press_test
_status_display:
		LDA		_spr_buf
		STA		_split_pos
		JSR		_render_off
		JSR		_ppu_spr_mode16_set
		JSR		_spr_reset
		LDA		_chr0_bank_req
		LDY		_chr1_bank_req
		STA		_chr0_backup
		STY		_chr1_backup
		LDA		#$1F
		STA		_chr0_bank_req
		LDA		#$1F
		STA		_chr1_bank_req
		LDA		_ppu_scroll_shadow_lo
		STA		_scroll_lo_backup
		LDA		_ppu_scroll_nt_hor
		STA		_scroll_shadow_lo_backup
		LDA		_ppu_scroll_shadow_hi
		STA		_scroll_hi_backup
		LDA		_ppu_scroll_nt_vert
		STA		_scroll_shadow_hi_backup
		LDA		#$00
		STA		_ppu_scroll_shadow_lo
		STA		_ppu_scroll_nt_hor
		STA		_ppu_scroll_shadow_hi
		STA		_ppu_scroll_nt_vert
		INC		_ppu_scroll_nt_hor
		INC		_ppu_scroll_nt_vert
		JSR		_main_screen8_draw_continue
		LDA		#$03
		JSR		_mmc1_prg_set
		LDY		#$1F
loc_B51EC:
		LDA		_pal_buf,Y
		STA		_pal_backup,Y
		LDA		_pal6,Y
		STA		_pal_buf,Y
		DEY
		BPL		loc_B51EC
		JSR		_status_screen_info_insert
		JSR		_render_on
		INC		_ingame_mode_idx
		JMP		_exit_ingame_idle_mode
_start_press_test:
		LDA		_pads+4
		AND		#$08
		BNE		_pause_start
		JMP		_ingame_loop_engine
_pause_start:
		LDA		#$34
		JSR		_apu_se_req
		LDA		#$04
		JSR		_wait_for_frames
_exit_ingame_idle_mode:
		INC		_ingame_mode_idx
		LDA		#$7A
		JSR		_apu_mus_req
		LDA		#$04
		JSR		_wait_for_frames
		JMP		_ingame_loop

; =============== S U B R O U T I N E =======================================
_ingame_loop_pause:
		LDA		_pads+4
		AND		#$08
		BNE		_j_return_back_ingame_idle
		JMP		_ingame_loop
_j_return_back_ingame_idle:
		JMP		_return_back_ingame_idle

; =============== S U B R O U T I N E =======================================
_ingame_loop_status:
		LDA		_pads+4
		AND		#$04
		BNE		_status_exit_start
		JMP		_ingame_loop
_status_exit_start:
		JSR		_render_off
		LDA		_chr0_backup
		LDY		_chr1_backup
		STA		_chr0_bank_req
		STY		_chr1_bank_req
		LDY		#$1F
loc_B524A:
		LDA		_pal_backup,Y
		STA		_pal_buf,Y
		DEY
		BPL		loc_B524A
		LDA		_scroll_lo_backup
		STA		_ppu_scroll_shadow_lo
		LDA		_scroll_shadow_lo_backup
		STA		_ppu_scroll_nt_hor
		LDA		_scroll_hi_backup
		STA		_ppu_scroll_shadow_hi
		LDA		_scroll_shadow_hi_backup
		STA		_ppu_scroll_nt_vert
		LDY		#$00
		STY		_tmpC
loc_B5267:
		LDA		#$10
		STA		_tmpA
loc_B526B:
		TYA
		PHA
		LDX		byte_43A,Y
		JSR		_sys_room_draw_sub02
		PLA
		TAY
		INY
		INC		_tmpA
		LDA		_tmpA
		CMP		#$20
		BCC		loc_B526B
		INC		_tmpC
		CPY		#$F0
		BCC		loc_B5267
		LDA		_mmc1_ctrl_shadow
		CMP		#$1E
		BNE		loc_B52C0
		LDA		byte_82
		BMI		loc_B52C0
		STA		_tmpA
		AND		#$10
		BEQ		loc_B52C0
		LDA		byte_83
		STA		_tmpC
		LDY		#$00
		STY		_tmp49
loc_B529C:
		TYA
		PHA
		LDX		_room_tiles_tmp_buf,Y
		LDY		_tmp49
		LDA		byte_43A,Y
		PHA
		JSR		_sys_room_draw_sub02
		PLA
		LDY		_tmp49
		STA		byte_43A,Y
		CLC
		LDA		_tmp49
		ADC		#$10
		STA		_tmp49
		INC		_tmpC
		PLA
		TAY
		INY
		CPY		#$0F
		BCC		loc_B529C
loc_B52C0:
		LDA		_split_pos
		STA		_spr_buf
		JSR		_obj_scr_manager
		JSR		_hud_obj_managers
		JSR		_ppu_spr_mode8_set
		JSR		_render_on
_return_back_ingame_idle:
		LDA		#$79
		JSR		_apu_mus_req
		LDA		#$00
		STA		_ingame_mode_idx

; =============== S U B R O U T I N E =======================================
_ingame_loop_engine:
		JSR		_obj_scr_manager
		JSR		_hud_obj_managers
		LDA		_stage_flags
		BMI		loc_B52F1
		AND		#$40
		BNE		loc_B52EB
		JMP		_ingame_loop
loc_B52EB:
		JSR		_players_restore_def_max_hps
		JMP		_pal_fade_out
loc_B52F1:
		LDA		_room_flags
		AND		#$08
		BNE		_j_stage_complete
		LDX		#$01
loc_B52F9:
		LDA		_players_lives,X
		BEQ		loc_B530A
		LDA		_obj_hps,X
		BEQ		_j_ingame_loop
		LDA		_obj_y_hi_poss,X
		BEQ		loc_B530A
_j_ingame_loop:
		JMP		_ingame_loop
loc_B530A:
		DEX
		BPL		loc_B52F9
		LDA		_players_lives
		ORA		_players_lives+1
		BNE		_j_stage_complete
		LDA		#$07
		STA		_main_sub_idx
		JMP		_pal_fade_out
_j_stage_complete:
		JMP		_stage_complete

; =============== S U B R O U T I N E =======================================
_players_restore_def_max_hps:
		LDA		_players_def_max_hps
		STA		_players_max_hps
		LDA		_players_def_max_hps+1
		STA		_players_max_hps+1
		RTS

; =============== S U B R O U T I N E =======================================
_status_screen_info_insert:
		JSR		_spr_reset
		LDA		#$02
		STA		_scr_idx
		LDA		#<[_num_char_table0]
		STA		_tmp_ptr42
		LDA		#>[_num_char_table0]
		STA		_tmp_ptr42+1
		LDA		#$01
		STA		_tmp49
loc_B5339:
		LDX		_tmp49
		LDA		_players_lives,X
		BEQ		loc_B536F
		LDY		_players_nums,X
		LDA		_status_screen_info_pos_list,Y
		STA		_obj_x_lo_poss+2
		LDX		_tmp49
		LDA		_players_rr_ptss,X
		LDX		#$10
		LDY		#$00
		JSR		_format_num99
		LDX		_tmp49
		SEC
		LDA		_players_lives,X
		SBC		#$01
		LDX		#$10
		LDY		#$0A
		JSR		_format_num99
		LDX		_tmp49
		LDA		_players_nums,X
		ASL
		TAX
		LDA		_status_spr_res0,X
		LDY		_status_spr_res0+1,X
		JSR		_status_screen_spr_insert
loc_B536F:
		DEC		_tmp49
		BPL		loc_B5339
		RTS

; =============== S U B R O U T I N E =======================================
_stage_complete_info_insert:
		LDA		#<[_num_char_table0]
		STA		_tmp_ptr42
		LDA		#>[_num_char_table0]
		STA		_tmp_ptr42+1
		LDA		#$0D
		LDX		#$60
		LDY		#$28
		JSR		_obj2_spr_insert
		LDA		#$01
		STA		_tmp49
loc_B5389:
		LDX		_tmp49
		LDA		_players_lives,X
		BEQ		loc_B53DC
		LDY		_players_nums,X
		LDA		_status_screen_info_pos_list,Y
		STA		_obj_x_lo_poss+2
		LDX		_tmp49
		LDA		_players_rr_ptss,X
		LDX		#$10
		LDY		#$00
		JSR		_format_num99
		LDX		_tmp49
		SEC
		LDA		_players_lives,X
		SBC		#$01
		LDX		#$10
		LDY		#$0A
		JSR		_format_num99
		LDX		_tmp49
		LDA		_players_rr_lvls,X
		LDX		#$10
		LDY		#$14
		JSR		_format_num99
		LDX		_tmp49
		LDA		_players_nums,X
		ASL
		TAX
		LDA		_status_spr_res1,X
		LDY		_status_spr_res1+1,X
		JSR		_status_screen_spr_insert
		LDX		_tmp49
		CLC
		LDA		_players_def_max_hps,X
		ADC		#$01
		STA		_obj_spr_idxs+2
		LDA		#$C0
		STA		_obj_y_lo_poss+2
		JSR		_obj_spr_lib_insert
loc_B53DC:
		DEC		_tmp49
		BPL		loc_B5389
		RTS
_status_screen_info_pos_list:
		.BYTE	$00,$48,$98

; =============== S U B R O U T I N E =======================================
_status_screen_spr_insert:
		STA		_tmp_ptrE
		STY		_tmp_ptrE+1
		LDY		#$00
loc_B53EA:
		LDA		(_tmp_ptrE),Y
		BMI		locret_B5401
		STA		_obj_spr_idxs+2
		INY
		LDA		(_tmp_ptrE),Y
		STA		_obj_y_lo_poss+2
		INY
		TYA
		PHA
		JSR		_obj_spr_lib_insert
		PLA
		TAY
		BNE		loc_B53EA
locret_B5401:
		RTS

; =============== S U B R O U T I N E =======================================
_obj2_spr_insert:
		STA		_obj_spr_idxs+2
		STX		_obj_x_lo_poss+2
		STY		_obj_y_lo_poss+2
		JMP		_obj_spr_lib_insert
_status_spr_res0:
		.WORD	0
		.WORD	_status_spr0_res0
		.WORD	_status_spr1_res0
_status_spr_res1:
		.WORD	0
		.WORD	_status_spr0_res1
		.WORD	_status_spr1_res1
_status_spr0_res0:
		.BYTE	$07,$50,$0B,$78,$0A,$90,$10,$98,$0E,$B0,$11,$B0,$FF
_status_spr1_res0:
		.BYTE	$08,$50,$0C,$78,$0A,$90,$10,$98,$0E,$B0,$11,$B0,$FF
_status_spr0_res1:
		.BYTE	$0B,$50,$0A,$68,$10,$70,$0E,$88,$11,$88,$09,$98,$12,$A0,$FF
_status_spr1_res1:
		.BYTE	$0C,$50,$0A,$68,$10,$70,$0E,$88,$11,$88,$09,$98,$12,$A0,$FF

; =============== S U B R O U T I N E =======================================
_format_num99:
		STY		_tmp_ptr2+1
		STX		_tmp_ptr4+1
		JSR		_int_to_dec99
		LDX		_tmp_ptr2+1
		LDA		#$00
		STA		_ram_buf0,X
		STA		_ram_buf0+2,X
		LDA		_tmp_ptr4+1
		STA		_ram_buf0+1,X
		INX
		INX
		INX
		LDA		#$02
		STA		_tmp_ptr4
loc_B546F:
		LDY		_tmp_ptr4
		LDA		_tmp_ptr0,Y
		BMI		loc_B5490
		TAY
		TXA
		PHA
		LDA		(_tmp_ptr42),Y
		STA		_ram_buf0,X
		LDY		#$10
		LDA		(_tmp_ptr42),Y
		STA		_ram_buf0+1,X
		LDX		_tmp_ptr2+1
		INC		_ram_buf0,X
		PLA
		TAX
		INX
		INX
		BNE		loc_B549B
loc_B5490:
		CLC
		LDY		_tmp_ptr2+1
		LDA		_ram_buf0+1,Y
		ADC		#$08
		STA		_ram_buf0+1,Y
loc_B549B:
		DEC		_tmp_ptr4
		BPL		loc_B546F
		LDA		#$00
		STA		_ram_buf0,X
		RTS

; =============== S U B R O U T I N E =======================================
_int_to_dec99:
		LDX		#$00
		STX		_tmp_ptr0
		STX		_tmp_ptr0+1
		STX		_tmp_ptr2
		LDY		#$FF
		LDX		#$02
loc_B54B1:
		CMP		_dec_char_list,X
		BCC		loc_B54BE
		SBC		_dec_char_list,X
		INC		_tmp_ptr0,X
		INY
		BPL		loc_B54B1
loc_B54BE:
		PHA
		TYA
		BPL		loc_B54C4
		STA		_tmp_ptr0,X
loc_B54C4:
		PLA
		DEX
		BNE		loc_B54B1
		STA		_tmp_ptr0,X
		RTS
_dec_char_list:
		.BYTE	$01,10,100

; =============== S U B R O U T I N E =======================================
_hud_obj_managers:
		LDA		#$02
		STA		_scr_idx
		LDA		_room_flags
		AND		#$08
		BNE		loc_B5514
		LDX		#$01
loc_B54DA:
		LDA		_players_lives,X
		BEQ		loc_B5509
		TXA
		PHA
		LDY		_players_nums,X
		LDA		_hud_heart_name_spr_list,Y
		STA		_obj_spr_idxs+2
		LDA		_hud_heart_name_spr_pos_list,Y
		STA		_obj_x_lo_poss+2
		LDA		#$D0
		STA		_obj_y_lo_poss+2
		JSR		_obj_spr_lib_insert
		PLA
		PHA
		TAX
		LDA		_obj_hps,X
		BEQ		loc_B5507
		CLC
		ADC		#$01
		STA		_obj_spr_idxs+2
		JSR		_obj_spr_lib_insert
loc_B5507:
		PLA
		TAX
loc_B5509:
		DEX
		BPL		loc_B54DA
		JSR		_is_is_stage4_ingame
		BNE		loc_B5514
		JSR		_stage4_hud_timer_insert
loc_B5514:
		LDA		_stage4_frames_cnt
		BMI		locret_B5554
		DEC		_stage4_frames_cnt
		BPL		locret_B5554
		LDA		#$3B
		STA		_stage4_frames_cnt
		DEC		_stage4_seconds_cnt
		BPL		loc_B5545
		LDA		#$3B
		STA		_stage4_seconds_cnt
		DEC		_stage4_minutes_cnt
		BPL		locret_B5554
		LDA		#$00
		STA		_stage4_minutes_cnt
		STA		_stage4_seconds_cnt
		STA		_stage4_frames_cnt
		DEC		_stage4_frames_cnt
		JSR		_is_is_stage4_ingame
		BNE		loc_B5545
		LDY		#$00
		JSR		_player_kill
		LDY		#$01
		JSR		_player_kill
loc_B5545:
		LDA		_stage4_minutes_cnt
		BNE		locret_B5554
		LDA		_stage4_seconds_cnt
		CMP		#$0A
		BCS		locret_B5554
		LDA		#$3A
		JSR		_apu_se_req
locret_B5554:
		RTS

; =============== S U B R O U T I N E =======================================
_is_is_stage4_ingame:
		LDA		_main_sub_idx
		CMP		#$04
		BNE		locret_B555F
		LDA		_stage
		CMP		#$03
locret_B555F:
		RTS

; =============== S U B R O U T I N E =======================================
_stage4_hud_timer_insert:
		LDY		#$0B
loc_B5562:
		LDA		_spr_hud_timer_raw,Y
		STA		_ram_buf0,Y
		DEY
		BPL		loc_B5562
		LDX		_stage4_minutes_cnt
		LDA		_num_char_table1,X
		STA		_ram_buf0+3
		LDA		_stage4_seconds_cnt
		JSR		_int_to_dec99
		LDX		_tmp_ptr0+1
		BMI		loc_B5582
		LDA		_num_char_table1,X
		STA		_ram_buf0+7
loc_B5582:
		LDX		_tmp_ptr0
		LDA		_num_char_table1,X
		STA		_ram_buf0+9
		LDA		#$C0
		STA		_obj_x_lo_poss+2
		LDA		#$18
		STA		_obj_y_lo_poss+2
		LDA		#$10
		STA		_obj_spr_idxs+2
		JMP		_obj_spr_lib_insert

; =============== S U B R O U T I N E =======================================
_player_kill:
		LDA		#$14
		CMP		_players_states
		BEQ		locret_B55C4
		CMP		_players_states+1
		BEQ		locret_B55C4
		LDA		_obj_hps,Y
		BEQ		locret_B55C4
		LDA		#$00
		STA		_obj_hps,Y
		STA		_obj_heigts,Y
		LDA		_players_vars07,Y
		ORA		#$80
		STA		_players_vars07,Y
		SEC
		LDA		_players_lives,Y
		SBC		#$01
		STA		_players_lives,Y
locret_B55C4:
		RTS
_hud_heart_name_spr_list:
		.BYTE	$00,$15,$16
_hud_heart_name_spr_pos_list:
		.BYTE	$00,$10,$D0
_spr_hud_timer_raw:
		.BYTE	$04,$00,$00,$E8,$01,$F2,$01,$E8,$01,$E8,$01,$00

; =============== S U B R O U T I N E =======================================
_stage_complete:
		LDA		_obj_hps
		STA		_players_max_hps
		LDA		_obj_hps+1
		STA		_players_max_hps+1
		INC		_stage_room_idx
		LDA		_room_flags
		AND		#$90
		BEQ		loc_B560D
		LDA		_stage
		SEC
		SBC		#$05
		BCC		loc_B55F8
		TAX
		LDA		_extra_stages_complete_flags
		ORA		_bitmasks_0,X
		STA		_extra_stages_complete_flags
loc_B55F8:
		LDX		#$00
		STX		_stage_room_idx
		INC		_stage
		LDA		_stage
		CMP		#$09
		BCC		loc_B5606
		STX		_stage
loc_B5606:
		JSR		_players_restore_def_max_hps
		LDA		#$05
		STA		_main_sub_idx
loc_B560D:
		JMP		_pal_fade_out
_main_screens_lib:
		.WORD	_screen_res0_license
		.WORD	_screen_res1_intro
		.WORD	_screen_res2_title
		.WORD	_screen_res3_ingame
		.WORD	_screen_res3_ingame
		.WORD	_screen_res5_stage_complete
		.WORD	_screen_res3_ingame
		.WORD	_screen_res7_game_over
		.WORD	_screen_res8_continue
		.WORD	_screen_res9

; =============== S U B R O U T I N E =======================================
_main_screen_draw:
		LDA		_main_sub_idx
		JSR		_switch
		.WORD	_main_screen0_draw_license
		.WORD	_main_screen1_draw_intro
		.WORD	_main_screen2_draw_title
		.WORD	_main_screen3_draw_cutscenes
		.WORD	_main_screen4_draw_ingame
		.WORD	_main_screen5_draw_stage_complete
		.WORD	_main_screen6_draw
		.WORD	_main_screen7_draw_game_over
		.WORD	_main_screen8_draw_continue
		.WORD	_screen_res0_license ; WRONG VALUE!

; =============== S U B R O U T I N E =======================================
_main_screen_init:
		LDA		_main_sub_idx
		ASL
		TAX
		LDA		_main_screens_lib,X
		STA		_tmp_ptr42
		LDA		_main_screens_lib+1,X
		STA		_tmp_ptr42+1
		LDY		#$00
		LDA		(_tmp_ptr42),Y
		AND		#$20
		STA		_tmp_ptr0
		LDA		_ppu_ctrl_shadow
		AND		#$DF
		ORA		_tmp_ptr0
		STA		_ppu_ctrl_shadow
		LDX		#$08
		AND		#$20
		BEQ		loc_B5663
		LDX		#$10
loc_B5663:
		STX		byte_28
		LDA		(_tmp_ptr42),Y
		AND		#$06
		STA		_tmp_ptr0
		LDA		_ppu_mask_shadow
		AND		#$F9
		ORA		_tmp_ptr0
		STA		_ppu_mask_shadow
		INY
		LDA		(_tmp_ptr42),Y
		STA		_tmp_ptr0
		INY
		LDA		(_tmp_ptr42),Y
		STA		_tmp_ptr0+1
		INY
		LDA		(_tmp_ptr42),Y
		STA		_tmp_ptr2
		INY
		LDA		(_tmp_ptr42),Y
		STA		_tmp_ptr2+1
		INY
		TYA
		PHA
		LDA		#$03
		JSR		_mmc1_prg_set
		LDY		#$0F
loc_B5691:
		LDA		(_tmp_ptr0),Y
		STA		_pal_tmp_buf,Y
		LDA		(_tmp_ptr2),Y
		STA		_pal_tmp_buf+$10,Y
		LDA		#$0F
		STA		_pal_buf,Y
		STA		_pal_buf+$10,Y
		DEY
		BPL		loc_B5691
		PLA
		TAY
		LDA		(_tmp_ptr42),Y
		STA		byte_46
		INY
		LDA		(_tmp_ptr42),Y
		STA		_tmp_ptr0
		INY
		TYA
		PHA
		LDA		(_tmp_ptr42),Y
		LDX		byte_46
		LDY		_tmp_ptr0
		JSR		_nt_fill
		LDA		#$20
		JSR		_nt_fill
		PLA
		TAY
		INY
		LDX		#$00
loc_B56C7:
		LDA		(_tmp_ptr42),Y
		STA		_chr0_bank_req,X
		INX
		INY
		CPX		#$04
		BCC		loc_B56C7
		LDA		(_tmp_ptr42),Y
		STA		_ppu_scroll_shadow_lo
		STA		_ppu_scroll_shadow_lo+1
		INY
		LDA		(_tmp_ptr42),Y
		STA		_ppu_scroll_nt_hor
		STA		_ppu_scroll_nt_hor+1
		INY
		LDA		(_tmp_ptr42),Y
		STA		_ppu_scroll_shadow_hi
		STA		_ppu_scroll_shadow_hi+1
		INY
		LDA		(_tmp_ptr42),Y
		STA		_ppu_scroll_nt_vert
		STA		_ppu_scroll_nt_vert+1
		INY
		LDX		#$00
loc_B56EF:
		LDA		(_tmp_ptr42),Y
		STA		_spr_buf,X
		INY
		INX
		CPX		#$04
		BCC		loc_B56EF
		LDA		#$00
		STA		_obj_global_x_shift
		STA		_obj_global_x_shift+1
		STA		_obj_global_y_shift
		STA		_obj_global_y_shift+1
		RTS
_screen_res9:
		.BYTE	$02					; _ppu_mode
		.WORD	_room_palA_12		; _pal_bg_ptr
		.WORD	_room_palA_12		; _pal_spr_ptr
		.BYTE	$84					; _fill_tile
		.BYTE	$00					; _attr_fill
		.BYTE	$24					; _nt_ofs
		.BYTE	$09,$09,$09,$09		; _chr_banks
		.BYTE	$00,$00,$10,$00		; _scrolls
		.BYTE	$F0,$00,$00,$00		; _sprites
_screen_res0_license:
		.BYTE	$02					; _ppu_mode
		.WORD	_pal0				; _pal_bg_ptr
		.WORD	_pal1				; _pal_spr_ptr
		.BYTE	$40					; _fill_tile
		.BYTE	$00					; _attr_fill
		.BYTE	$24					; _nt_ofs
		.BYTE	$1F,$1F,$1F,$1F		; _chr_banks
		.BYTE	$00,$00,$00,$00		; _scrolls
		.BYTE	$F0,$00,$00,$00		; _sprites

; =============== S U B R O U T I N E =======================================
_main_screen0_draw_license:
		LDA		#$03
		JSR		_mmc1_prg_set
		JSR		_tlm_res_queue_param
		.WORD	_tlm_res_license
		RTS
_screen_res1_intro:
		.BYTE	$22					; _ppu_mode
		.WORD	_pal0				; _pal_bg_ptr
		.WORD	_pal1				; _pal_spr_ptr
		.BYTE	$00					; _fill_tile
		.BYTE	$00					; _attr_fill
		.BYTE	$24					; _nt_ofs
		.BYTE	$1F,$1D,$1F,$1D		; _chr_banks
		.BYTE	$00,$01,$00,$00		; _scrolls
		.BYTE	$F0,$00,$00,$00		; _sprites

; =============== S U B R O U T I N E =======================================
_main_screen1_draw_intro:
		LDA		#$03
		JSR		_mmc1_prg_set
		LDX		#$02
loc_B5753:
		TXA
		PHA
		LDA		word_B5781,X
		STA		_tmp_ptr44
		LDA		word_B5781+1,X
		STA		_tmp_ptr44+1
		LDA		#$0F
loc_B5761:
		PHA
		JSR		_rect_draw_param
		.WORD	_rect_intro_bricks
		PLA
		SEC
		SBC		#$01
		BNE		loc_B5761
		PLA
		TAX
		DEX
		DEX
		BPL		loc_B5753
		LDA		#$21
		STA		_tmp_ptr44+1
		LDA		#$44
		STA		_tmp_ptr44
		JSR		_rect_draw_param
		.WORD	_rect_intro_silhouette
		RTS
word_B5781:
		.WORD	$2000
		.WORD	$2400
_screen_res2_title:
		.BYTE	$02					; _ppu_mode
		.WORD	_pal2				; _pal_bg_ptr
		.WORD	_pal3				; _pal_spr_ptr
		.BYTE	0					; _fill_tile
		.BYTE	0					; _attr_fill
		.BYTE	$24					; _nt_ofs
		.BYTE	$1E,$1F,$1F,$1F		; _chr_banks
		.BYTE	$00,$00,$00,$00		; _scrolls
		.BYTE	$A5,$60,$20,$08		; _sprites

; =============== S U B R O U T I N E =======================================
_main_screen2_draw_title:
		LDA		#$03
		JSR		_mmc1_prg_set
		LDX		#$00
		LDY		#$20
		LDA		#<[_rle_tlm_title]
		STA		_tmp_ptr0
		LDA		#>[_rle_tlm_title]
		STA		_tmp_ptr0+1
		JMP		_rle_unpack

; =============== S U B R O U T I N E =======================================
_main_screen3_draw_cutscenes:
		LDA		_cutscene_idx
		ASL
		TAX
		LDA		_cutscene_rooms_cfg_lib,X
		LDY		_cutscene_rooms_cfg_lib+1,X
		JSR		_room_cfg_load
		LDA		_split_pos
		CMP		#$4D
		BNE		loc_B580A
		LDA		#$03
		JSR		_mmc1_prg_set
		LDA		#$00
		STA		_tmp_ptr44
		LDA		#$24
		STA		_tmp_ptr44+1
		JSR		_rect_draw_param
		.WORD	_rect_frame_nt_clear
		JSR		_tlm_res_queue_param
		.WORD	_tlm_res_frame_attr_clear
		LDA		#$02
		JSR		_mmc1_prg_set
		LDA		#$41
		STA		_tmp_ptr44
		LDA		#$24
		STA		_tmp_ptr44+1
		LDX		#$1E
		LDY		#$08
		JSR		_msg_frame_draw_param
		.WORD	_msg_frame_tiles_list
		LDX		#$1C
		LDY		#$06
		STX		_wnd_msg_area_width
		STY		_wnd_msg_area_heigth
		LDA		#$62
		STA		_wnd_msg_ppu_ofs
		LDA		#$24
		STA		_wnd_msg_ppu_ofs+1
		LDA		#$1F
		STA		_chr0_bank_req
		LDA		#$01
		STA		_ppu_scroll_nt_hor
		LDA		#$10
		STA		_spr_buf+3
loc_B580A:
		JMP		_set_split

; =============== S U B R O U T I N E =======================================
_set_split:
		LDA		_split_pos
		STA		_spr_buf
		RTS
_screen_res5_stage_complete:
		.BYTE	2					; _ppu_mode
		.WORD	_pal4				; _pal_bg_ptr
		.WORD	_pal5				; _pal_spr_ptr
		.BYTE	$40					; _fill_tile
		.BYTE	0					; _attr_fill
		.BYTE	$24					; _nt_ofs
		.BYTE	$1E,$1F,$1E,$1F		; _chr_banks
		.BYTE	$00,$00,$00,$00		; _scrolls
		.BYTE	$F0,$00,$00,$00		; _sprites

; =============== S U B R O U T I N E =======================================
_main_screen5_draw_stage_complete:
		LDA		#$03
		JSR		_mmc1_prg_set
		LDX		#$00
		LDY		#$20
		LDA		#<[_rle_stage_complete]
		STA		_tmp_ptr0
		LDA		#>[_rle_stage_complete]
		STA		_tmp_ptr0+1
		JSR		_rle_unpack
		LDA		#$1B
		JSR		_apu_mus_req
		LDX		#$32
		LDA		_players_lives
		BEQ		loc_B584C
		LDA		_players_lives+1
		BEQ		loc_B584C
		LDX		#$1E
loc_B584C:
		STX		byte_E0
		LDA		#$00
		STA		_hor_menu_pos
		STA		_tmp48
		RTS
_screen_res7_game_over:
		.BYTE	2					; _ppu_mode
		.WORD	_pal6				; _pal_bg_ptr
		.WORD	_pal7				; _pal_spr_ptr
		.BYTE	$40					; _fill_tile
		.BYTE	0					; _attr_fill
		.BYTE	$24					; _nt_ofs
		.BYTE	$1F,$0B,$1F,$0B		; _chr_banks
		.BYTE	$00,$01,$00,$00		; _scrolls
		.BYTE	$F0,$00,$00,$00		; _sprites

; =============== S U B R O U T I N E =======================================
_main_screen7_draw_game_over:
		JSR		_main_screen8_draw_continue
		LDX		#$85
		JMP		_room_spr_pal_load
_screen_res8_continue:
		.BYTE	2					; _ppu_mode
		.WORD	_pal8				; _pal_bg_ptr
		.WORD	_palA				; _pal_spr_ptr
		.BYTE	$40					; _fill_tile
		.BYTE	0					; _attr_fill
		.BYTE	$24					; _nt_ofs
		.BYTE	$1F,$00,$1F,$00		; _chr_banks
		.BYTE	$00,$01,$00,$00		; _scrolls
		.BYTE	$F0,$00,$00,$00		; _sprites

; =============== S U B R O U T I N E =======================================
_main_screen8_draw_continue:
		LDA		#$03
		JSR		_mmc1_prg_set
		LDX		#$00
		LDY		#$24
		LDA		_mmc1_ctrl_shadow
		LSR
		BCC		loc_B5895
		LDY		#$28
loc_B5895:
		LDA		#<[_rle_tlm_continue]
		STA		_tmp_ptr0
		LDA		#>[_rle_tlm_continue]
		STA		_tmp_ptr0+1
		JMP		_rle_unpack
_screen_res3_ingame:
		.BYTE	2					; _ppu_mode
		.WORD	_room_pal00			; _pal_bg_ptr
		.WORD	_palA				; _pal_spr_ptr
		.BYTE	$40					; _fill_tile
		.BYTE	$FF					; _attr_fill
		.BYTE	$24					; _nt_ofs
		.BYTE	$1E,$1F,$1E,$1F		; _chr_banks
		.BYTE	$00,$00,$00,$00		; _scrolls
		.BYTE	$F0,$80,$20,$08		; _sprites

; =============== S U B R O U T I N E =======================================
_main_screen4_draw_ingame:
		LDX		_stage
		LDA		_stage_room_idx
		ASL
		ADC		byte_B5AAC,X
		TAX
		LDA		_room_cfg_lib,X
		LDY		_room_cfg_lib+1,X
		BMI		loc_B58D0
		STA		_cutscene_idx
		LDA		#$03
		STA		_main_sub_idx
		INC		_stage_room_idx
		JMP		_main_screen3_draw_cutscenes
loc_B58D0:
		PHA
		JSR		_main_screen4_draw_ingame_A
		PLA
		JSR		_room_cfg_load
		JMP		_set_split

; =============== S U B R O U T I N E =======================================
_main_screen6_draw:
		JSR		_main_screen4_draw_ingame_A
		LDA		#<[_room_cfgB_00]
		LDY		#>[_room_cfgB_00]
		JSR		_room_cfg_load
		JMP		_set_split

; =============== S U B R O U T I N E =======================================
_main_screen4_draw_ingame_A:
		LDA		#$81
		STA		_scr_params
		STA		_scr_params+1
		STA		_scr_params+2
		LDA		#$0C
		STA		_obj_flips+2
		LDA		#<[_script_idle]
		STA		_scr_lo_pcs+2
		LDA		#>[_script_idle]
		STA		_scr_hi_pcs+2
		RTS

; =============== S U B R O U T I N E =======================================
_room_cfg_load:
		STA		_tmp_ptr0
		STY		_tmp_ptr0+1
		LDA		#$02
		JSR		_mmc1_prg_set
		LDY		#$00
		LDA		(_tmp_ptr0),Y
		STA		_chr0_bank_req
		STA		_wnd_split_chr0_bank
		INY
		LDA		(_tmp_ptr0),Y
		STA		_chr1_bank_req
		STA		_wnd_split_chr1_bank
		INY
		LDA		#$00
		STA		byte_AC
		STA		byte_AD
		STA		byte_B0
		STA		byte_B1
		LDA		(_tmp_ptr0),Y
		STA		_lvl_start_scroll_hor
		STA		_lvl_start_scroll_hor+1
		STA		_ppu_scroll_nt_hor
		STA		_ppu_scroll_nt_hor+1
		INY
		LDA		(_tmp_ptr0),Y
		STA		_lvl_start_scroll_vert
		STA		_lvl_start_scroll_vert+1
		STA		_ppu_scroll_nt_vert
		STA		_ppu_scroll_nt_vert+1
		INY
		LDX		#$30
		LDA		(_tmp_ptr0),Y
		STA		_obj_x_lo_poss
		CMP		#$18
		BEQ		loc_B594E
		SEC
		LDA		#$00
		SBC		_obj_x_lo_poss
		TAX
loc_B594E:
		STX		_obj_x_lo_poss+1
		INY
		LDA		(_tmp_ptr0),Y
		STA		_obj_y_lo_poss
		STA		_obj_y_lo_poss+1
		INY
		LDA		(_tmp_ptr0),Y
		STA		_room_flags
		INY
		LDA		(_tmp_ptr0),Y
		STA		_room_layout_ptr
		INY
		LDA		(_tmp_ptr0),Y
		STA		_room_layout_ptr+1
		INY
		LDA		(_tmp_ptr0),Y
		STA		_room_scrolls_ptr
		INY
		LDA		(_tmp_ptr0),Y
		STA		_room_scrolls_ptr+1
		INY
		LDA		(_tmp_ptr0),Y
		STA		_room_tileset_ptr
		INY
		LDA		(_tmp_ptr0),Y
		STA		_room_tileset_ptr+1
		INY
		LDA		(_tmp_ptr0),Y
		STA		_room_prizes_ptr
		INY
		LDA		(_tmp_ptr0),Y
		STA		_room_prizes_ptr+1
		INY
		LDA		(_tmp_ptr0),Y
		STA		_room_enemies_ptr
		INY
		LDA		(_tmp_ptr0),Y
		STA		_room_enemies_ptr+1
		INY
		LDA		(_tmp_ptr0),Y
		JSR		_mmc1_ctrl_set
		INY
		LDA		(_tmp_ptr0),Y
		STA		_split_pos
		INY
		LDA		(_tmp_ptr0),Y
		JSR		_apu_mus_req
		INY
		LDA		(_tmp_ptr0),Y
		STA		byte_7F
		INY
		LDA		(_tmp_ptr0),Y
		STA		_pal_anim_mode_idx
		INY
		LDA		#$02
		JSR		_mmc1_prg_set
		LDA		(_tmp_ptr0),Y
		STA		_tmp_ptr2
		INY
		LDA		(_tmp_ptr0),Y
		STA		_tmp_ptr2+1
		INY
		TYA
		PHA
		LDA		#$03
		JSR		_mmc1_prg_set
		LDY		#$0F
loc_B59C5:
		LDA		(_tmp_ptr2),Y
		STA		_pal_tmp_buf,Y
		DEY
		BPL		loc_B59C5
		PLA
		TAY
		LDA		#$02
		JSR		_mmc1_prg_set
		LDA		(_tmp_ptr0),Y
		TAX
		JSR		_room_spr_pal_load
		LDA		_pal_anim_mode_idx
		BPL		loc_B59F1
		AND		#$3F
		STA		_pal_anim_mode_idx
		LDA		#$14
		LDY		#$00
loc_B59E6:
		STA		_pal_tmp_buf,Y
		INY
		INY
		INY
		INY
		CPY		#$20
		BCC		loc_B59E6
loc_B59F1:
		JSR		_ppu_spr_mode8_set
		JSR		_room_scroll_pos_calc
		JSR		_room_full_draw
		LDA		_room_flags
		AND		#$20
		BEQ		locret_B5A0A
		INC		_lvl_start_scroll_hor+1
		JSR		_room_scroll_pos_calc
		JSR		_room_full_draw
		DEC		_lvl_start_scroll_hor+1
locret_B5A0A:
		RTS

; =============== S U B R O U T I N E =======================================
_room_spr_pal_load:
		LDA		_cur_prg_bank
		PHA
		LDA		#$03
		JSR		_mmc1_prg_set
		LDA		#$00
		STA		_tmp_ptr2
loc_B5A17:
		LDY		_tmp_ptr2
		LDA		_room_spr_pal_ofs_list,Y
		TAY
		LDA		_room_spr_pal_lib,X
		STA		_pal_tmp_buf,Y
		INX
		INC		_tmp_ptr2
		CPY		#$1F
		BCC		loc_B5A17
		JMP		_mmc1_prg_restore

; =============== S U B R O U T I N E =======================================
_room_spr_pal_flush:
		JSR		_room_spr_pal_load
		LDX		#$06
loc_B5A32:
		LDY		_room_spr_pal_ofs_list,X
		LDA		_pal_tmp_buf,Y
		STA		_pal_buf,Y
		DEX
		BPL		loc_B5A32
		RTS

_room_spr_pal_ofs_list:
		.BYTE	$17,$19,$1A,$1B,$1D,$1E,$1F
_room_cfg_lib:
		.WORD	_room_cfg00
		.WORD	_room_cfg01
		.WORD	_room_cfg02
		.WORD	_room_cfg03
		.WORD	$02
		.WORD	_room_cfg05
		.WORD	_room_cfg06
		.WORD	_room_cfg07
		.WORD	_room_cfg08
		.WORD	_room_cfg09
		.WORD	_room_cfg0A
		.WORD	_room_cfg07
		.WORD	_room_cfg08
		.WORD	_room_cfg0D
		.WORD	_room_cfg0E
		.WORD	_room_cfg03
		.WORD	_room_cfg10
		.WORD	_room_cfg0E
		.WORD	$08
		.WORD	_room_cfg13
		.WORD	_room_cfg14
		.WORD	_room_cfg15
		.WORD	_room_cfg16
		.WORD	_room_cfg17
		.WORD	_room_cfg18
		.WORD	_room_cfg0A
		.WORD	_room_cfg1A
		.WORD	_room_cfg16
		.WORD	_room_cfg03
		.WORD	_room_cfg1A
		.WORD	_room_cfg16
		.WORD	_room_cfg1F
		.WORD	_room_cfg20
		.WORD	_room_cfg21
		.WORD	_room_cfg22
		.WORD	_room_cfg23
		.WORD	_room_cfg24
		.WORD	_room_cfg25
		.WORD	_room_cfg26
		.WORD	_room_cfg27
		.WORD	_room_cfg03
		.WORD	_room_cfg29
		.WORD	_room_cfg2A
		.WORD	_room_cfg2B
		.WORD	_room_cfg2C
		.WORD	_room_cfg03
		.WORD	_room_cfg2E
		.WORD	_room_cfg2F
		.WORD	_room_cfg30
		.WORD	$0E
		.WORD	_room_cfg32
byte_B5AAC:
		.BYTE	$00,$0C,$1A,$24,$28,$3E,$42,$4C,$56
_unref:
		.BYTE	$05,$02,$01,$01,$02,$01,$04,$04,$07
byte_B5ABE:
		.BYTE	$0F,$03,$FF,$04,$09,$0A,$0B,$0B,$0B
_cutscene_rooms_cfg_lib:
		.WORD	_cutscene_room_cfg00
		.WORD	_cutscene_room_cfg01
		.WORD	_cutscene_room_cfg02
		.WORD	_cutscene_room_cfg03
		.WORD	_cutscene_room_cfg04
		.WORD	_cutscene_room_cfg05
		.WORD	_cutscene_room_cfg06
		.WORD	_cutscene_room_cfg07
		.WORD	_cutscene_room_cfg07
		.WORD	_cutscene_room_cfg09
		.WORD	_cutscene_room_cfg0A
		.WORD	_cutscene_room_cfg0B
		.WORD	_cutscene_room_cfg0C
		.WORD	_cutscene_room_cfg0D
		.WORD	_cutscene_room_cfg0E
		.WORD	_cutscene_room_cfg0F
		.WORD	_cutscene_room_cfg10
		.WORD	_cutscene_room_cfg11
		.WORD	_cutscene_room_cfg12

; =============== S U B R O U T I N E =======================================
_native_sub171:
		LDY		#$04
		LDX		_stage
		LDA		byte_B5ABE,X
		STA		_cutscene_idx
		BMI		loc_B5AFA
		LDY		#$03
loc_B5AFA:
		STY		_main_sub_idx
		RTS

; =============== S U B R O U T I N E =======================================
_scr_flags_update:
		PHP
		PLA
		LDX		_scr_idx
		STA		_scr_flags,X
		RTS

_scr_cmd_lib:
		.WORD	_scr_cmd00_stop-1
		.WORD	_scr_cmd01_flush-1
		.WORD	_scr_cmd02_delay-1
		.WORD	_scr_cmd03_ejmp-1
		.WORD	_scr_cmd04_start-1
		.WORD	_scr_cmd05_ejsr-1
		.WORD	_scr_cmd06_jmp-1
		.WORD	_scr_cmd07_jsr-1
		.WORD	_scr_cmd08_ret-1
		.WORD	_scr_cmd09_loopA-1
		.WORD	_scr_cmd0A_loopB-1
		.WORD	_scr_cmd0B_beq-1
		.WORD	_scr_cmd0C_bcs-1
		.WORD	_scr_cmd0D_bmi-1
		.WORD	_scr_cmd0E_bne-1
		.WORD	_scr_cmd0F_bcc-1
		.WORD	_scr_cmd10_bpl-1
		.WORD	_scr_cmd11_test_pads-1
		.WORD	_scr_cmd12_switch-1
		.WORD	_scr_cmd13_sta-1
		.WORD	_scr_cmd14_chr_bank-1
		.WORD	_scr_cmd15_loopA_reset-1
		.WORD	_scr_cmd16_loopB_reset-1
		.WORD	_scr_cmd17_apu_load-1
		.WORD	_scr_cmd18_jmp_animate-1
		.WORD	_scr_cmd19_call_animate-1
		.WORD	_scr_cmd1A_target_follow-1
		.WORD	_scr_cmd1B_param80_clear-1
		.WORD	_scr_cmd1C_param80_set-1
		.WORD	_scr_cmd1D_spr_lib_select-1
		.WORD	_scr_cmd1E_spr_idx_select-1
		.WORD	_scr_cmd1F_flip40_clear-1
		.WORD	_scr_cmd20_flip40_set-1
		.WORD	_scr_cmd21_flip80_clear-1
		.WORD	_scr_cmd22_flip80_set-1
		.WORD	_scr_cmd23_flip40_toggle-1
		.WORD	_scr_cmd24_flip80_toggle-1
		.WORD	_scr_cmd25_obj_set_x_pos-1
		.WORD	_scr_cmd26_obj_set_y_pos-1
		.WORD	_scr_cmd27_obj_move_x_pos-1
		.WORD	_scr_cmd28_obj_move_y_pos-1
		.WORD	_scr_cmd29_obj_set_x_delta-1
		.WORD	_scr_cmd2A_obj_set_y_delta-1
		.WORD	_scr_cmd2B_obj_inc_x_delta-1
		.WORD	_scr_cmd2C_obj_inc_y_delta-1
		.WORD	_scr_cmd2D_obj_dec_x_delta-1
		.WORD	_scr_cmd2E_dec_y_delta-1
		.WORD	_scr_cmd2F_target_lock-1
		.WORD	_scr_cmd30_target_spd_set-1
		.WORD	_scr_cmd31_target_dir_set-1
		.WORD	_scr_cmd32_obj_set_size-1
		.WORD	_scr_cmd33_var1C_set-1
		.WORD	_scr_cmd34_obj_set_hp-1
		.WORD	_scr_cmd35_obj_set_flip-1
		.WORD	_scr_cmd36-1					; unused
		.WORD	_scr_cmd37_main_sub_idx_set-1
		.WORD	_scr_cmd38_pal_fade_in-1
		.WORD	_scr_cmd39_pal_fade_out-1
		.WORD	_scr_cmd3A_tlm_res_queue-1		; unused
		.WORD	_scr_cmd3B_draw_menu_cursor-1
		.WORD	_scr_cmd3C_hor_menu_input-1		; unused
		.WORD	_scr_cmd3D_vert_menu_input-1
		.WORD	_scr_cmd3E_msg_area_set-1		; unused
		.WORD	_scr_cmd3F_msg_display-1
		.WORD	_scr_cmd40_msg_wait-1
		.WORD	_scr_cmd41_break-1
		.WORD	_scr_cmd42_destr_pc_set-1
		.WORD	_scr_cmd43_param_40_set-1
#if OPTIMIZATION=1
		.WORD	_scr_cmd44_beq_short-1
		.WORD	_scr_cmd45_bcs_short-1
		.WORD	_scr_cmd46_bmi_short-1
		.WORD	_scr_cmd47_bne_short-1
		.WORD	_scr_cmd48_bcc_short-1
		.WORD	_scr_cmd49_bpl_short-1
#endif

; =============== S U B R O U T I N E =======================================
_unref_7:
		JMP		_scr_cmd_exec

; =============== S U B R O U T I N E =======================================
_scr_exec_priority:
		LDX		_scr_idx
		LDA		_scr_delays,X
		BEQ		_scr_cmd_exec
		DEC		_scr_delays,X
		RTS

; =============== S U B R O U T I N E =======================================
_scr_cmd_exec:
		LDX		_scr_idx
		LDA		_scr_lo_pcs,X
		STA		_scr_pc
		LDA		_scr_hi_pcs,X
		STA		_scr_pc+1

; =============== S U B R O U T I N E =======================================
_scr_cmd_fetch:
		LDX		_scr_idx
		JSR		_scr_getc
		ASL
		TAY
		LDA		_scr_cmd_lib+1,Y
		PHA
		LDA		_scr_cmd_lib,Y
		PHA
		RTS

; =============== S U B R O U T I N E =======================================
_scr_pc_flush:
		LDX		_scr_idx
		LDA		_scr_pc
		STA		_scr_lo_pcs,X
		LDA		_scr_pc+1
		STA		_scr_hi_pcs,X
		RTS

; =============== S U B R O U T I N E =======================================
_scr_getc:
		LDY		#$00
		LDA		(_scr_pc),Y
		TAY
		INC		_scr_pc
		BNE		loc_B5BCF
		INC		_scr_pc+1
loc_B5BCF:
		TYA
		RTS

_stack_slots_lib_lo:
		.BYTE	<[_stack_slot0]
		.BYTE	<[_stack_slot1]
		.BYTE	<[_stack_slot2]
		.BYTE	<[_stack_slot3]
		.BYTE	<[_stack_slot4]
		.BYTE	<[_stack_slot5]
		.BYTE	<[_stack_slot6]
		.BYTE	<[_stack_slot7]
		.BYTE	<[_stack_slot8]
		.BYTE	<[_stack_slot9]
		.BYTE	<[_stack_slotA]
		.BYTE	<[_stack_slotB]
_stack_slots_lib_hi:
		.BYTE	>[_stack_slot0]
		.BYTE	>[_stack_slot1]
		.BYTE	>[_stack_slot2]
		.BYTE	>[_stack_slot3]
		.BYTE	>[_stack_slot4]
		.BYTE	>[_stack_slot5]
		.BYTE	>[_stack_slot6]
		.BYTE	>[_stack_slot7]
		.BYTE	>[_stack_slot8]
		.BYTE	>[_stack_slot9]
		.BYTE	>[_stack_slotA]
		.BYTE	>[_stack_slotB]

; =============== S U B R O U T I N E =======================================
_scr_get_sp:
		LDX		_scr_idx
		LDA		_stack_slots_lib_lo,X
		STA		_tmp_ptr0
		LDA		_stack_slots_lib_hi,X
		STA		_tmp_ptr0+1
		LDY		_scr_sps,X
		RTS

; =============== S U B R O U T I N E =======================================
_scr_push:
		STA		(_tmp_ptr0),Y
		INY
		INC		_scr_sps,X
		RTS

; =============== S U B R O U T I N E =======================================
_scr_pop:
		DEC		_scr_sps,X
		DEY
		LDA		(_tmp_ptr0),Y
		RTS

; =============== S U B R O U T I N E =======================================
_scr_cmd00_stop:
		LDA		#$80
		STA		_scr_params,X
		STA		_scr_vars21,X
		RTS

; =============== S U B R O U T I N E =======================================
_scr_cmd01_flush:
		JMP		_scr_pc_flush

; =============== S U B R O U T I N E =======================================
_scr_cmd02_delay:
		JSR		_scr_getc
		STA		_scr_delays,X
		JMP		_scr_pc_flush

; =============== S U B R O U T I N E =======================================
_scr_cmd04_start:
		JSR		_scr_getc
		PHA
		JSR		_scr_getc
		STA		_tmp_ptr0
		JSR		_scr_getc
		STA		_tmp_ptr0+1
		LDA		_obj_y_lo_poss,X
		STA		_tmp_ptr2
		LDA		_obj_y_hi_poss,X
		STA		_tmp_ptr2+1
		LDA		_obj_x_lo_poss,X
		STA		_tmp_ptr4
		LDA		_obj_x_hi_poss,X
		STA		_tmp_ptr4+1
		LDA		_obj_flips,X
		AND		#$40
		STA		byte_6
		PLA
		TAY
		JSR		_scr_load
		JSR		_scr_flags_update
		JMP		_scr_cmd_fetch

; =============== S U B R O U T I N E =======================================
_scr_cmd03_ejmp:
		JSR		_scr_getc
		STA		_tmp_ptr0
		JSR		_scr_getc
		STA		_tmp_ptr0+1
		JSR		_scr_pc_flush
		JMP		(_tmp_ptr0)

; =============== S U B R O U T I N E =======================================
_scr_cmd05_ejsr:
		JSR		_scr_getc
		STA		_tmp_ptr0
		JSR		_scr_getc
		STA		_tmp_ptr0+1
		LDA		#>[_scr_cmd_fetch-1]
		PHA
		LDA		#<[_scr_cmd_fetch-1]
		PHA
		JMP		(_tmp_ptr0)

; =============== S U B R O U T I N E =======================================
_scr_cmd37_main_sub_idx_set:
		JSR		_scr_getc
		STA		_main_sub_idx
		JMP		_pal_fade_out

; =============== S U B R O U T I N E =======================================
_scr_cmd06_jmp:
		JSR		_scr_getc
		STA		_scr_lo_pcs,X
		JSR		_scr_getc
		STA		_scr_hi_pcs,X
		JMP		_scr_cmd_exec

; =============== S U B R O U T I N E =======================================
_scr_cmd07_jsr:
		JSR		_scr_getc
		STA		_scr_lo_pcs,X
		JSR		_scr_getc
		STA		_scr_hi_pcs,X
		JSR		_scr_get_sp
		LDA		_scr_pc+1
		JSR		_scr_push
		LDA		_scr_pc
		JSR		_scr_push
		JMP		_scr_cmd_exec

; =============== S U B R O U T I N E =======================================
_scr_cmd08_ret:
		JSR		_scr_get_sp
		JSR		_scr_pop
		STA		_scr_pc
		JSR		_scr_pop
		STA		_scr_pc+1
		JMP		_scr_cmd_fetch

; =============== S U B R O U T I N E =======================================
_scr_cmd41_break:
		JSR		_scr_get_sp
		DEC		_scr_sps,X
		DEC		_scr_sps,X
		JMP		_scr_cmd06_jmp

; =============== S U B R O U T I N E =======================================
_scr_cmd09_loopA:
		INC		_scr_loopsA,X
		JSR		_scr_getc
		CMP		_scr_loopsA,X
		BEQ		loc_B5CCF
		BCS		_scr_do_loop
loc_B5CCF:
		LDA		#$00
		STA		_scr_loopsA,X
		JMP		_scr_ofs_skip

; =============== S U B R O U T I N E =======================================
_scr_cmd0A_loopB:
		INC		_scr_loopsB,X
		JSR		_scr_getc
		CMP		_scr_loopsB,X
		BEQ		loc_B5CE4
		BCS		_scr_do_loop
loc_B5CE4:
		LDA		#$00
		STA		_scr_loopsB,X
		JMP		_scr_ofs_skip

; =============== S U B R O U T I N E =======================================
_scr_do_loop:
		JMP		_scr_cmd06_jmp

; =============== S U B R O U T I N E =======================================
_scr_cmd15_loopA_reset:
		LDA		#$00
		STA		_scr_loopsA,X
		JMP		_scr_cmd_fetch

; =============== S U B R O U T I N E =======================================
_scr_cmd16_loopB_reset:
		LDA		#$00
		STA		_scr_loopsB,X
		JMP		_scr_cmd_fetch

; =============== S U B R O U T I N E =======================================
_scr_cmd0B_beq:
		LDA		_scr_flags,X
		PHA
		PLP
		BEQ		_scr_ofs_skip
		JMP		_scr_cmd06_jmp

; =============== S U B R O U T I N E =======================================
_scr_cmd0C_bcs:
		LDA		_scr_flags,X
		PHA
		PLP
		BCS		_scr_ofs_skip
		JMP		_scr_cmd06_jmp

; =============== S U B R O U T I N E =======================================
_scr_cmd0D_bmi:
		LDA		_scr_flags,X
		PHA
		PLP
		BMI		_scr_ofs_skip
		JMP		_scr_cmd06_jmp

; =============== S U B R O U T I N E =======================================
_scr_cmd0E_bne:
		LDA		_scr_flags,X
		PHA
		PLP
		BNE		_scr_ofs_skip
		JMP		_scr_cmd06_jmp

; =============== S U B R O U T I N E =======================================
_scr_cmd0F_bcc:
		LDA		_scr_flags,X
		PHA
		PLP
		BCC		_scr_ofs_skip
		JMP		_scr_cmd06_jmp

; =============== S U B R O U T I N E =======================================
_scr_cmd10_bpl:
		LDA		_scr_flags,X
		PHA
		PLP
		BPL		_scr_ofs_skip
		JMP		_scr_cmd06_jmp

; =============== S U B R O U T I N E =======================================
_scr_ofs_skip:
		JSR		_scr_getc
		JSR		_scr_getc
		JMP		_scr_cmd_fetch

#if OPTIMIZATION=1
; =============== S U B R O U T I N E =======================================
_scr_cmd44_beq_short:
		LDA		_scr_flags,X
		PHA
		PLP
		BEQ		_scr_byte_skip
		BNE		_scr_short_jump

; =============== S U B R O U T I N E =======================================
_scr_cmd45_bcs_short:
		LDA		_scr_flags,X
		PHA
		PLP
		BCS		_scr_byte_skip
		BCC		_scr_short_jump

; =============== S U B R O U T I N E =======================================
_scr_cmd46_bmi_short:
		LDA		_scr_flags,X
		PHA
		PLP
		BMI		_scr_byte_skip
		BPL		_scr_short_jump

; =============== S U B R O U T I N E =======================================
_scr_cmd47_bne_short:
		LDA		_scr_flags,X
		PHA
		PLP
		BNE		_scr_byte_skip
		BEQ		_scr_short_jump

; =============== S U B R O U T I N E =======================================
_scr_cmd48_bcc_short:
		LDA		_scr_flags,X
		PHA
		PLP
		BCC		_scr_byte_skip
		BCS		_scr_short_jump

; =============== S U B R O U T I N E =======================================
_scr_cmd49_bpl_short:
		LDA		_scr_flags,X
		PHA
		PLP
		BPL		_scr_byte_skip
;		JMP		_scr_cmd06_jmp

; !FALLTHROUGH!

; =============== S U B R O U T I N E =======================================
_scr_short_jump:
		JSR		_scr_getc
		CLC
		ADC		_scr_pc
		STA		_scr_lo_pcs,X
		ADC		_scr_pc+1
		STA		_scr_hi_pcs,X
		JMP		_scr_cmd_exec

; =============== S U B R O U T I N E =======================================
_scr_byte_skip:
		JSR		_scr_getc
		JMP		_scr_cmd_fetch
#endif

; =============== S U B R O U T I N E =======================================
_scr_cmd11_test_pads:
		JSR		_scr_getc
		PHA
		JSR		_scr_getc
		STA		_tmp_ptr0
		PLA
		TAY
		LDA		_pads,Y
		AND		_tmp_ptr0
		BNE		_scr_ofs_skip
		JMP		_scr_cmd06_jmp

; =============== S U B R O U T I N E =======================================
_scr_cmd12_switch:
		JSR		_scr_getc
		STA		_tmp_ptr0
		JSR		_scr_getc
		STA		_tmp_ptr0+1
		LDY		#$00
		LDA		(_tmp_ptr0),Y
		ASL
		TAY
		LDA		(_scr_pc),Y
		TAX
		INY
		LDA		(_scr_pc),Y
		STA		_scr_pc+1
		STX		_scr_pc
		JMP		_scr_cmd_fetch

; =============== S U B R O U T I N E =======================================
_scr_cmd42_destr_pc_set:
		JSR		_scr_getc
		STA		_scr_destr_lo_pcs,X
		JSR		_scr_getc
		STA		_scr_destr_hi_pcs,X
		JMP		_scr_cmd_fetch

; =============== S U B R O U T I N E =======================================
_scr_cmd13_sta:
		JSR		_scr_getc
		PHA
		JSR		_scr_getw
		PLA
		LDY		#$00
		STA		(_tmp_ptr0),Y
		JMP		_scr_cmd_fetch

; =============== S U B R O U T I N E =======================================
_scr_cmd14_chr_bank:
		JSR		_scr_getc
		TAX
		JSR		_scr_getc
		STA		_chr0_bank_req,X
		JMP		_scr_cmd_fetch

; =============== S U B R O U T I N E =======================================
_scr_cmd17_apu_load:
		JSR		_scr_getc
		CMP		#$79
		BCS		loc_B5DB1
		CMP		#$22
		BCC		loc_B5DB1
		JSR		_apu_se_req
		JMP		_scr_cmd_fetch
loc_B5DB1:
		JSR		_apu_mus_req
		JMP		_scr_cmd_fetch

; =============== S U B R O U T I N E =======================================
_scr_cmd19_call_animate:
		JSR		_obj_move_hor_animate
		JSR		_obj_vert_animate
		JMP		_scr_cmd_fetch

; =============== S U B R O U T I N E =======================================
_scr_cmd18_jmp_animate:
		JSR		_obj_move_hor_animate
		JSR		_obj_vert_animate
		JMP		_scr_pc_flush

; =============== S U B R O U T I N E =======================================
_obj_move_hor_animate:
		LDA		_obj_x_deltas,X
		BEQ		locret_B5E1B
		BMI		loc_B5DEF
		JSR		_swap_4bit_nibbles
		PHA
		AND		#$F0
		CLC
		ADC		_obj_x_accel,X
		STA		_obj_x_accel,X
		PLA
		AND		#$07
		ADC		_obj_x_lo_poss,X
		STA		_obj_x_lo_poss,X
		LDA		_obj_x_hi_poss,X
		ADC		#$00
		STA		_obj_x_hi_poss,X
		RTS
loc_B5DEF:
		SEC
		LDA		#$00
		SBC		_obj_x_deltas,X
		JSR		_swap_4bit_nibbles
		PHA
		AND		#$F0
		STA		_tmp_ptr0
		PLA
		AND		#$07
		STA		_tmp_ptr0+1
		SEC
		LDA		_obj_x_accel,X
		SBC		_tmp_ptr0
		STA		_obj_x_accel,X
		LDA		_obj_x_lo_poss,X
		SBC		_tmp_ptr0+1
		STA		_obj_x_lo_poss,X
		LDA		_obj_x_hi_poss,X
		SBC		#$00
		STA		_obj_x_hi_poss,X
locret_B5E1B:
		RTS

; =============== S U B R O U T I N E =======================================
_obj_vert_animate:
		LDA		_obj_y_deltas,X
		BEQ		locret_B5E6E
		BMI		loc_B5E42
		JSR		_swap_4bit_nibbles
		PHA
		AND		#$F0
		CLC
		ADC		_obj_y_accel,X
		STA		_obj_y_accel,X
		PLA
		AND		#$07
		ADC		_obj_y_lo_poss,X
		STA		_obj_y_lo_poss,X
		LDA		_obj_y_hi_poss,X
		ADC		#$00
		STA		_obj_y_hi_poss,X
		RTS
loc_B5E42:
		SEC
		LDA		#$00
		SBC		_obj_y_deltas,X
		JSR		_swap_4bit_nibbles
		PHA
		AND		#$F0
		STA		_tmp_ptr0
		PLA
		AND		#$07
		STA		_tmp_ptr0+1
		SEC
		LDA		_obj_y_accel,X
		SBC		_tmp_ptr0
		STA		_obj_y_accel,X
		LDA		_obj_y_lo_poss,X
		SBC		_tmp_ptr0+1
		STA		_obj_y_lo_poss,X
		LDA		_obj_y_hi_poss,X
		SBC		#$00
		STA		_obj_y_hi_poss,X
locret_B5E6E:
		RTS

byte_B5E6F:
		.BYTE	$00,$00
		.BYTE	$19,$FF
		.BYTE	$32,$FB
		.BYTE	$4A,$F5
		.BYTE	$62,$ED
		.BYTE	$79,$E2
		.BYTE	$8E,$D5
		.BYTE	$A2,$C6
		.BYTE	$B5,$B5
		.BYTE	$C6,$A2
		.BYTE	$D5,$8E
		.BYTE	$E2,$79
		.BYTE	$ED,$62
		.BYTE	$F5,$4A
		.BYTE	$FB,$32
		.BYTE	$FF,$19

; =============== S U B R O U T I N E =======================================
_scr_cmd1A_target_follow:
		LDX		_scr_idx
		LDA		_scr_vars19,X
		BEQ		loc_B5EE8
		LDA		_scr_vars16,X
		JSR		_scr_cmd1A_A
		BEQ		loc_B5EE8
		STA		_tmp_ptr0
		LDA		#$00
		STA		_tmp_ptr2
		STA		_tmp_ptr4
loc_B5EA6:
		LDA		_scr_vars18,X
		AND		#$0F
		ASL
		TAY
		LDA		byte_B5E6F,Y
		CLC
		ADC		_obj_y_accel,X
		STA		_obj_y_accel,X
		BCC		loc_B5EBC
		JSR		_scr_cmd1A_B
loc_B5EBC:
		LDA		byte_B5E6F+1,Y
		BEQ		loc_B5ECA
		CLC
		ADC		_obj_x_accel,X
		STA		_obj_x_accel,X
		BCC		loc_B5ECD
loc_B5ECA:
		JSR		_scr_cmd1A_C
loc_B5ECD:
		DEC		_scr_vars19,X
		BEQ		loc_B5ED6
		DEC		_tmp_ptr0
		BNE		loc_B5EA6
loc_B5ED6:
		LDA		#$00
		STA		_tmp_ptr0+1
		LDA		_tmp_ptr2
		JSR		_scr_cmd1A_F
		LDA		#$00
		STA		_tmp_ptr0+1
		LDA		_tmp_ptr4
		JSR		_scr_cmd1A_D
loc_B5EE8:
		LDA		_scr_vars19,X
		JSR		_scr_flags_update
		JMP		_scr_cmd_fetch

; =============== S U B R O U T I N E =======================================
_scr_cmd1A_B:
		LDA		_scr_vars18,X
		AND		#$30
		BEQ		loc_B5F03
		CMP		#$10
		BEQ		loc_B5F06
		CMP		#$30
		BEQ		loc_B5F09
loc_B5F00:
		DEC		_tmp_ptr2
		RTS
loc_B5F03:
		INC		_tmp_ptr2
		RTS
loc_B5F06:
		DEC		_tmp_ptr4
		RTS
loc_B5F09:
		INC		_tmp_ptr4
		RTS

; =============== S U B R O U T I N E =======================================
_scr_cmd1A_C:
		LDA		_scr_vars18,X
		AND		#$30
		BEQ		loc_B5F09
		CMP		#$10
		BEQ		loc_B5F03
		CMP		#$20
		BEQ		loc_B5F06
		BNE		loc_B5F00

; =============== S U B R O U T I N E =======================================
_scr_cmd1A_F:
		BPL		loc_B5F21
		DEC		_tmp_ptr0+1
loc_B5F21:
		CLC
		ADC		_obj_y_lo_poss,X
		STA		_obj_y_lo_poss,X
		LDA		_tmp_ptr0+1
		ADC		_obj_y_hi_poss,X
		STA		_obj_y_hi_poss,X
		RTS

; =============== S U B R O U T I N E =======================================
_scr_cmd1A_D:
		BPL		loc_B5F35
		DEC		_tmp_ptr0+1
loc_B5F35:
		CLC
		ADC		_obj_x_lo_poss,X
		STA		_obj_x_lo_poss,X
		LDA		_tmp_ptr0+1
		ADC		_obj_x_hi_poss,X
		STA		_obj_x_hi_poss,X
		RTS

; =============== S U B R O U T I N E =======================================
_scr_cmd1A_A:
		TAY
		AND		#$F0
		CLC
		ADC		_scr_vars17,X
		STA		_scr_vars17,X
		TYA
		AND		#$0F
		ADC		#$00
		RTS

; =============== S U B R O U T I N E =======================================
_scr_cmd1B_param80_clear:
		JSR		_scr_param_80_clear
		JMP		_scr_cmd_fetch

; =============== S U B R O U T I N E =======================================
_scr_cmd1C_param80_set:
		JSR		_scr_param_80_set
		JMP		_scr_cmd_fetch

; =============== S U B R O U T I N E =======================================
_scr_cmd1D_spr_lib_select:
		JSR		_scr_getc
		STA		_obj_spr_libs,X
		JMP		_scr_cmd_fetch

; =============== S U B R O U T I N E =======================================
_scr_cmd1E_spr_idx_select:
		JSR		_scr_getc
		STA		_obj_spr_idxs,X
		JMP		_scr_cmd_fetch

; =============== S U B R O U T I N E =======================================
_scr_cmd_unref:
		JSR		_scr_getc
		STA		_scr_idxBs,X
		JMP		_scr_cmd_fetch

; =============== S U B R O U T I N E =======================================
_scr_cmd36:
		JSR		_scr_getc
		STA		_scr_idxCs,X
		JMP		_scr_cmd_fetch

; =============== S U B R O U T I N E =======================================
_scr_cmd35_obj_set_flip:
		JSR		_scr_getc
		JMP		_scr_obj_flip_set

; =============== S U B R O U T I N E =======================================
_scr_cmd1F_flip40_clear:
		LDA		_obj_flips,X
		AND		#$BF
		JMP		_scr_obj_flip_set

; =============== S U B R O U T I N E =======================================
_scr_cmd20_flip40_set:
		LDA		_obj_flips,X
		ORA		#$40
		JMP		_scr_obj_flip_set

; =============== S U B R O U T I N E =======================================
_scr_cmd21_flip80_clear:
		LDA		_obj_flips,X
		AND		#$7F
		JMP		_scr_obj_flip_set

; =============== S U B R O U T I N E =======================================
_scr_cmd22_flip80_set:
		LDA		_obj_flips,X
		ORA		#$80
		JMP		_scr_obj_flip_set

; =============== S U B R O U T I N E =======================================
_scr_cmd23_flip40_toggle:
		LDA		_obj_flips,X
		EOR		#$40
		JMP		_scr_obj_flip_set

; =============== S U B R O U T I N E =======================================
_scr_cmd24_flip80_toggle:
		LDA		_obj_flips,X
		EOR		#$80

; =============== S U B R O U T I N E =======================================
_scr_obj_flip_set:
		STA		_obj_flips,X
		JMP		_scr_cmd_fetch

; =============== S U B R O U T I N E =======================================
_scr_cmd43_param_40_set:
		LDA		_scr_params,X
		ORA		#$40
		STA		_scr_params,X
		JMP		_scr_cmd_fetch

; =============== S U B R O U T I N E =======================================
_scr_cmd25_obj_set_x_pos:
		JSR		_scr_getc
		STA		_obj_x_lo_poss,X
		JSR		_scr_getc
		STA		_obj_x_hi_poss,X
		JMP		_scr_cmd_fetch

; =============== S U B R O U T I N E =======================================
_scr_cmd26_obj_set_y_pos:
		JSR		_scr_getc
		STA		_obj_y_lo_poss,X
		JSR		_scr_getc
		STA		_obj_y_hi_poss,X
		JMP		_scr_cmd_fetch

; =============== S U B R O U T I N E =======================================
_scr_cmd27_obj_move_x_pos:
		LDA		#$00
		STA		_tmp_ptr0
		JSR		_scr_getc
		BPL		loc_B5FF2
		DEC		_tmp_ptr0
loc_B5FF2:
		CLC
		ADC		_obj_x_lo_poss,X
		STA		_obj_x_lo_poss,X
		LDA		_obj_x_hi_poss,X
		ADC		_tmp_ptr0
loc_B5FFE:
		STA		_obj_x_hi_poss,X
		JMP		_scr_cmd_fetch

; =============== S U B R O U T I N E =======================================
_scr_cmd28_obj_move_y_pos:
		LDA		#$00
		STA		_tmp_ptr0
		JSR		_scr_getc
		BPL		loc_B600F
		DEC		_tmp_ptr0
loc_B600F:
		CLC
		ADC		_obj_y_lo_poss,X
		STA		_obj_y_lo_poss,X
		LDA		_obj_y_hi_poss,X
		ADC		_tmp_ptr0
		STA		_obj_y_hi_poss,X
		JMP		_scr_cmd_fetch

; =============== S U B R O U T I N E =======================================
_scr_cmd29_obj_set_x_delta:
		JSR		_scr_getc
		STA		_obj_x_deltas,X
		JMP		_scr_cmd_fetch

; =============== S U B R O U T I N E =======================================
_scr_cmd2A_obj_set_y_delta:
		JSR		_scr_getc
		STA		_obj_y_deltas,X
		JMP		_scr_cmd_fetch

; =============== S U B R O U T I N E =======================================
_scr_cmd2B_obj_inc_x_delta:
		INC		_obj_x_deltas,X
		JMP		_scr_cmd_fetch

; =============== S U B R O U T I N E =======================================
_scr_cmd2C_obj_inc_y_delta:
		INC		_obj_y_deltas,X
		JMP		_scr_cmd_fetch

; =============== S U B R O U T I N E =======================================
_scr_cmd2D_obj_dec_x_delta:
		DEC		_obj_x_deltas,X
		JMP		_scr_cmd_fetch

; =============== S U B R O U T I N E =======================================
_scr_cmd2E_dec_y_delta:
		DEC		_obj_y_deltas,X
		JMP		_scr_cmd_fetch

; =============== S U B R O U T I N E =======================================
_scr_cmd2F_target_lock:
		JSR		_scr_getc
		JSR		_swap_4bit_nibbles
		STA		_scr_vars16,X
		LDA		#$00
		STA		_scr_vars17,X
		STA		_obj_x_deltas,X
		STA		_obj_x_accel,X
		STA		_obj_y_deltas,X
		STA		_obj_y_accel,X
		JMP		_scr_cmd_fetch

; =============== S U B R O U T I N E =======================================
_swap_4bit_nibbles:
		TAY
		ASL
		ASL
		ASL
		ASL
		STA		_tmp_ptr0
		TYA
		LSR
		LSR
		LSR
		LSR
		ORA		_tmp_ptr0
		RTS

; =============== S U B R O U T I N E =======================================
_scr_cmd30_target_spd_set:
		JSR		_scr_getc
		STA		_scr_vars18,X
		JMP		_scr_cmd_fetch

; =============== S U B R O U T I N E =======================================
_scr_cmd31_target_dir_set:
		JSR		_scr_getc
		STA		_scr_vars19,X
		JMP		_scr_cmd_fetch

; =============== S U B R O U T I N E =======================================
_scr_cmd32_obj_set_size:
		JSR		_scr_getc
		STA		_obj_widths,X
		JSR		_scr_getc
		STA		_obj_heigts,X
		JMP		_scr_cmd_fetch

; =============== S U B R O U T I N E =======================================
_scr_cmd33_var1C_set:
		JSR		_scr_getc
		STA		_scr_vars1C,X
		JMP		_scr_cmd_fetch

; =============== S U B R O U T I N E =======================================
_scr_cmd34_obj_set_hp:
		JSR		_scr_getc
		STA		_obj_hps,X
		JMP		_scr_cmd_fetch

; =============== S U B R O U T I N E =======================================
_scr_cmd38_pal_fade_in:
		JSR		_scr_getc
		TAX
		JSR		_scr_getc
		JSR		_set_pal_fade_in
		JMP		_scr_cmd_fetch

; =============== S U B R O U T I N E =======================================
_scr_cmd39_pal_fade_out:
		JSR		_scr_getc
		TAX
		JSR		_scr_getc
		JSR		_set_pal_fade_out
		JMP		_scr_cmd_fetch

; =============== S U B R O U T I N E =======================================
_scr_cmd3A_tlm_res_queue:
		JSR		_scr_getw
		JSR		_tlm_res_queue
		JMP		_scr_cmd_fetch

; =============== S U B R O U T I N E =======================================
_scr_getw:
		JSR		_scr_getc
		STA		_tmp_ptr0
		JSR		_scr_getc
		STA		_tmp_ptr0+1
		RTS

; =============== S U B R O U T I N E =======================================
_scr_cmd3B_draw_menu_cursor:
		JSR		_scr_getw
		JSR		_draw_menu_cursor
		JMP		_scr_cmd_fetch

; =============== S U B R O U T I N E =======================================
_scr_flags_store:
		JSR		_scr_flags_update
		JMP		_scr_cmd_fetch

; =============== S U B R O U T I N E =======================================
_scr_cmd3C_hor_menu_input:
		JSR		_scr_getc
		TAX
		JSR		_scr_getc
		JSR		_get_hor_menu_input
		JMP		_scr_flags_store

; =============== S U B R O U T I N E =======================================
_scr_cmd3D_vert_menu_input:
		JSR		_scr_getc
		TAX
		JSR		_scr_getc
		JSR		_get_vert_menu_input
		JMP		_scr_flags_store

; =============== S U B R O U T I N E =======================================
_scr_cmd3E_msg_area_set:
		JSR		_scr_getc
		STA		_wnd_msg_area_width
		JSR		_scr_getc
		STA		_wnd_msg_area_heigth
		JSR		_scr_getc
		STA		_wnd_msg_ppu_ofs
		JSR		_scr_getc
		STA		_wnd_msg_ppu_ofs+1
		JMP		_scr_cmd_fetch

; =============== S U B R O U T I N E =======================================
_scr_cmd3F_msg_display:
		JSR		_scr_getc
		STA		_wnd_msg_ptr
		JSR		_scr_getc
		STA		_wnd_msg_ptr+1
		JSR		_scr_getc
		STA		_wnd_msg_se_idx
		LDA		#$04
		STA		_wnd_msg_sub_idx
		LDA		#$04
		STA		_wnd_msg_delay_default
		JMP		_scr_pc_flush

; =============== S U B R O U T I N E =======================================
_scr_cmd40_msg_wait:
		LDA		_wnd_msg_sub_idx
		BEQ		loc_B6140
		DEC		_scr_pc
		LDA		_scr_pc
		CMP		#$FF
		BNE		loc_B6140
		DEC		_scr_pc+1
loc_B6140:
		JMP		_scr_pc_flush

; =============== S U B R O U T I N E =======================================
_far_prg3_pal_bg_reload:
		STA		_tmp_ptr0
		STY		_tmp_ptr0+1
		JSR		_room_spr_pal_load
		LDA		_cur_prg_bank
		PHA
		LDA		#$03
		JSR		_mmc1_prg_set
		LDY		#$0F
loc_B6154:
		LDA		(_tmp_ptr0),Y
		STA		_pal_tmp_buf,Y
		DEY
		BPL		loc_B6154
		JMP		_mmc1_prg_restore

; =============== S U B R O U T I N E =======================================
_far_prg3_bg_pal_load:
		STA		_tmp_ptr0
		STY		_tmp_ptr0+1
		LDA		_cur_prg_bank
		PHA
		LDA		#$03
		JSR		_mmc1_prg_set
		LDY		#$0F
loc_B616D:
		LDA		(_tmp_ptr0),Y
		STA		_pal_tmp_buf,Y
		STA		_pal_buf,Y
		DEY
		BPL		loc_B616D
		JMP		_mmc1_prg_restore

; =============== S U B R O U T I N E =======================================
_far_prg3_spr_pal_load:
		STA		_tmp_ptr0
		STY		_tmp_ptr0+1
		LDA		_cur_prg_bank
		PHA
		LDA		#$03
		JSR		_mmc1_prg_set
		LDY		#$1F
loc_B6189:
		LDA		(_tmp_ptr0),Y
		STA		_pal_buf,Y
		DEY
		BPL		loc_B6189
		JMP		_mmc1_prg_restore

; =============== S U B R O U T I N E =======================================
_far_prg3_pal_patch_load:
		STA		_tmp_ptr0
		STY		_tmp_ptr0+1
		LDA		_cur_prg_bank
		PHA
		LDA		#$03
		JSR		_mmc1_prg_set
		LDY		#$00
loc_B61A2:
		LDA		(_tmp_ptr0),Y
		BMI		loc_B61C0
		INY
		TAX
		LDA		(_tmp_ptr0),Y
		STA		_pal_buf+1,X
		INY
		LDA		(_tmp_ptr0),Y
		STA		_pal_buf+2,X
		INY
		LDA		(_tmp_ptr0),Y
		STA		_pal_buf+3,X
		INY
		INX
		INX
		INX
		INX
		BNE		loc_B61A2
loc_B61C0:
		JMP		_mmc1_prg_restore

; =============== S U B R O U T I N E =======================================
_ppu_pal_apply:
		LDY		#$1F
loc_B61C5:
		LDA		_pal_tmp_buf,Y
		STA		_pal_buf,Y
		DEY
		BPL		loc_B61C5
		RTS

; =============== S U B R O U T I N E =======================================
_native_sub111:
		LDY		byte_AB
		JSR		_native_sub111_A
		JSR		_native_sub111_B
		STA		_scr_vars18,X
		RTS

; =============== S U B R O U T I N E =======================================
_native_sub111_A:
		LDA		#$00
		STA		_tmp_ptr0+1
		STA		_tmp_ptr2+1
		SEC
		LDA		_obj_y_lo_poss,Y
		SBC		_obj_y_lo_poss,X
		STA		_tmp_ptr0
		LDA		_obj_y_hi_poss,Y
		SBC		_obj_y_hi_poss,X
		BCS		loc_B61FD
		SEC
		LDA		#$00
		SBC		_tmp_ptr0
		STA		_tmp_ptr0
		LDA		#$80
		STA		_tmp_ptr0+1
loc_B61FD:
		SEC
		LDA		_obj_x_lo_poss,Y
		SBC		_obj_x_lo_poss,X
		STA		_tmp_ptr2
		LDA		_obj_x_hi_poss,Y
		SBC		_obj_x_hi_poss,X
		BCS		locret_B6219
		SEC
		LDA		#$00
		SBC		_tmp_ptr2
		STA		_tmp_ptr2
		LDA		#$80
		STA		_tmp_ptr2+1
locret_B6219:
		RTS
byte_B621A:
		.BYTE	$00,$01,$02,$03,$04,$05,$06,$07,$0F,$0E,$0D,$0C,$0B,$0A,$09,$08
		.BYTE	$10,$11,$12,$13,$14,$15,$16,$17,$1F,$1E,$1D,$1C,$1B,$1A,$19,$18
		.BYTE	$20,$21,$22,$23,$24,$25,$26,$27,$2F,$2E,$2D,$2C,$2B,$2A,$29,$28
		.BYTE	$30,$31,$32,$33,$34,$35,$36,$37,$3F,$3E,$3D,$3C,$3B,$3A,$39,$38

; =============== S U B R O U T I N E =======================================
_native_sub111_B:
		LDA		_tmp_ptr0
		CMP		_tmp_ptr2
		BEQ		loc_B6262
		BCS		loc_B6287
loc_B6262:
		LDA		_tmp_ptr2
		STA		byte_8
		LDA		_tmp_ptr0
		STA		_tmpA
		JSR		_native_sub111_B_A
		LDA		_tmp_ptr2+1
		BMI		loc_B627C
		LDA		_tmp_ptr0+1
		ASL
		LDA		#$00
		BCC		loc_B62AA
		LDA		#$38
		BNE		loc_B62AA
loc_B627C:
		LDA		_tmp_ptr0+1
		ASL
		LDA		#$18
		BCC		loc_B62AA
		LDA		#$20
		BNE		loc_B62AA
loc_B6287:
		LDA		_tmp_ptr0
		STA		byte_8
		LDA		_tmp_ptr2
		STA		_tmpA
		JSR		_native_sub111_B_A
		LDA		_tmp_ptr0+1
		BMI		loc_B62A1
		LDA		_tmp_ptr2+1
		ASL
		LDA		#$08
		BCC		loc_B62AA
		LDA		#$10
		BNE		loc_B62AA
loc_B62A1:
		LDA		_tmp_ptr2+1
		ASL
		LDA		#$30
		BCC		loc_B62AA
		LDA		#$28
loc_B62AA:
		CLC
		ADC		byte_6
		TAY
		LDA		byte_B621A,Y
		RTS

; =============== S U B R O U T I N E =======================================
_native_sub111_B_A:
		LDA		#$00
		STA		byte_6
		LSR		byte_8
		LSR		byte_8
		BNE		loc_B62BE
		INC		byte_8
loc_B62BE:
		LDA		_tmpA
		ASL
loc_B62C1:
		SEC
		SBC		byte_8
		BCC		loc_B62CA
		INC		byte_6
		BNE		loc_B62C1
loc_B62CA:
		LDA		byte_6
		CMP		#$08
		BCC		locret_B62D4
		LDA		#$07
		STA		byte_6
locret_B62D4:
		RTS

; =============== S U B R O U T I N E =======================================
_native_sub122:
		INC		_scr_vars20,X
		LDA		_scr_vars20,X
		AND		#$3F
		TAY
		LDA		byte_B62EA,Y
		STA		_obj_y_deltas,X
		JSR		_obj_move_hor_animate
		JMP		_obj_vert_animate
byte_B62EA:
		.BYTE	$E0,$E0,$E0,$E8,$E8,$E8,$F0,$F0,$F8,$F8,$F8,$F8,$F8,$F8,$F8,$00
		.BYTE	$00,$08,$08,$08,$08,$08,$08,$08,$10,$10,$18,$18,$18,$20,$20,$20
		.BYTE	$20,$20,$20,$18,$18,$18,$10,$10,$08,$08,$08,$08,$08,$08,$08,$00
		.BYTE	$00,$F8,$F8,$F8,$F8,$F8,$F8,$F8,$F0,$F0,$E8,$E8,$E8,$E0,$E0,$E0

; =============== S U B R O U T I N E =======================================
_native_sub123:
		JSR		_native_sub123_ex
		JSR		_switch
		.WORD	_native_sub123_sub0
		.WORD	_native_sub123_sub1
		.WORD	_native_sub123_sub2
		.WORD	_native_sub123_sub3

; =============== S U B R O U T I N E =======================================
_native_sub123_sub0:
		JSR		_native_sub123_sub0_A

; =============== S U B R O U T I N E =======================================
_native_sub123_sub3:
		JSR		_native_sub123_sub3_A
		STA		_obj_x_deltas,X
		RTS

; =============== S U B R O U T I N E =======================================
_native_sub123_sub2:
		JSR		_native_sub123_sub0_A

; =============== S U B R O U T I N E =======================================
_native_sub123_sub1:
		JSR		_native_sub123_sub3
		JMP		_native_sub105

; =============== S U B R O U T I N E =======================================
_native_sub124:
		JSR		_native_sub123_ex
		JSR		_switch
		.WORD	_native_sub124_sub0
		.WORD	_native_sub124_sub1
		.WORD	_native_sub124_sub2
		.WORD	_native_sub124_sub3

; =============== S U B R O U T I N E =======================================
_native_sub124_sub1:
		JSR		_native_sub123_sub0_A

; =============== S U B R O U T I N E =======================================
_native_sub124_sub0:
		JSR		_native_sub123_sub3_A
		STA		_obj_y_deltas,X
		RTS

; =============== S U B R O U T I N E =======================================
_native_sub124_sub3:
		JSR		_native_sub123_sub0_A

; =============== S U B R O U T I N E =======================================
_native_sub124_sub2:
		JSR		_native_sub124_sub0
		JMP		_native_sub129

; =============== S U B R O U T I N E =======================================
_native_sub123_ex:
		LDA		_scr_vars19,X
		STA		_tmp_ptrE
		LSR
		LSR
		LSR
		LSR
		LSR
		AND		#$03
		RTS

; =============== S U B R O U T I N E =======================================
_native_sub123_sub0_A:
		SEC
		LDA		#$00
		SBC		_tmp_ptrE
		STA		_tmp_ptrE
		RTS

; =============== S U B R O U T I N E =======================================
_native_sub123_sub3_A:
		LDA		_tmp_ptrE
		AND		#$1F
		TAY
		LDA		byte_B6392,Y
		RTS

; =============== S U B R O U T I N E =======================================
_native_sub126:
		INC		_scr_vars19,X
		RTS

; =============== S U B R O U T I N E =======================================
_native_sub127:
		DEC		_scr_vars19,X
		RTS
byte_B6392:
		.BYTE	$00,$00,$00,$01,$01,$02,$02,$03,$03,$04,$04,$05,$05,$06,$06,$07
		.BYTE	$07,$07,$08,$08,$08,$09,$09,$09,$0A,$0A,$0A,$0A,$0A,$0A,$0A,$0C

; =============== S U B R O U T I N E =======================================
_native_sub113:
		JSR		_rand
		JMP		_scr_flags_update

; =============== S U B R O U T I N E =======================================
_native_sub12A:
		LDY		#$03
		JMP		_rand_scale

; =============== S U B R O U T I N E =======================================
_native_get_rand_clamp3:
		JSR		_rand
		AND		#$03
		STA		_tmp_ptrE+1
		RTS

; =============== S U B R O U T I N E =======================================
_native_box_bonus_3prizes_shuffle:
		LDA		#$03
		BNE		_native_box_bonus_prizes_shuffle

; =============== S U B R O U T I N E =======================================
_native_box_bonus_4prizes_shuffle:
		LDA		#$04

; =============== S U B R O U T I N E =======================================
_native_box_bonus_prizes_shuffle:
		STA		_tmp_ptr0						; store number of shiffled objects
		LDY		#$00
loc_B63CF:
		TYA										; write initial list 0 1 2 (3)
		STA		_box_bonus_prizes_order_list,Y
		INY
		CPY		_tmp_ptr0
		BNE		loc_B63CF
		JSR		_rand							; select random number of passes
		AND		#$03							; (rand & 3) + 4
		SEC
		ADC		#$03
loc_B63E0:
		PHA
		LDX		#$00
loc_B63E3:
		LDA		_box_bonus_prizes_order_list,X	; fetch list one by one from 0 to 2(3)
		PHA
		LDY		_tmp_ptr0						; scale random by number of elements 0-2(3)
		JSR		_rand_scale
		LDA		_box_bonus_prizes_order_list,Y	; swap current with randomly selected element
		STA		_box_bonus_prizes_order_list,X
		PLA
		STA		_box_bonus_prizes_order_list,Y
		INX
		CPX		_tmp_ptr0						; repeat for all elements
		BNE		loc_B63E3
		PLA
		SEC
		SBC		#$01							; repeat more times the same process
		BNE		loc_B63E0
		RTS

; =============== S U B R O U T I N E =======================================
_native_get_box_bonus_prize_from_list:
		LDA		_box_bonus_prizes_order_list
		STA		_tmp_ptrE+1
		LDY		#$00
loc_B6406:
		LDA		_box_bonus_prizes_order_list+1,Y
		STA		_box_bonus_prizes_order_list,Y
		INY
		CPY		#$03
		BCC		loc_B6406
		RTS

; =============== S U B R O U T I N E =======================================
_scr_param_80_set:
		LDA		_scr_params,X
		ORA		#$80
		STA		_scr_params,X
		RTS

; =============== S U B R O U T I N E =======================================
_scr_param_80_clear:
		LDA		_scr_params,X
		AND		#$7F
		STA		_scr_params,X
		RTS

; =============== S U B R O U T I N E =======================================
_scr_param_10_clear:
		LDA		_obj_flips,X
		AND		#$EF
		STA		_obj_flips,X
		RTS

; =============== S U B R O U T I N E =======================================
_scr_param_10_set:
		LDA		_obj_flips,X
		ORA		#$10
		STA		_obj_flips,X
		RTS

; =============== S U B R O U T I N E =======================================
_scr_param_4_set:
		LDA		_obj_flips,X
		ORA		#$04
		STA		_obj_flips,X
		RTS

; =============== S U B R O U T I N E =======================================
_scr_param_4_clear:
		LDA		_obj_flips,X
		AND		#$FB
		STA		_obj_flips,X
		RTS

; =============== S U B R O U T I N E =======================================
_native_sub144:
		LDA		_obj_flips,X
		AND		#$04
		BEQ		loc_B6463
		LDA		_scr_idxCs,X
		AND		#$20
		EOR		#$20
		BEQ		loc_B6463
		ORA		_scr_idxCs,X
		STA		_scr_idxCs,X
		LDA		#$20
		STA		_scr_vars20,X
loc_B6463:
		JMP		_scr_flags_update

; =============== S U B R O U T I N E =======================================
_native_sub145:
		LDA		_scr_vars20,X
		BEQ		locret_B647E
		DEC		_scr_vars20,X
		BNE		locret_B647E
		LDA		_scr_idxCs,X
		AND		#$DF
		STA		_scr_idxCs,X
		JSR		_scr_param_4_clear
		JSR		_scr_param_10_clear
locret_B647E:
		RTS

; =============== S U B R O U T I N E =======================================
_native_idxBs_20_set:
		LDA		_scr_idxBs,X
		ORA		#$20
		STA		_scr_idxBs,X
		RTS

; =============== S U B R O U T I N E =======================================
_native_idxBs_10_clear:
		LDA		_scr_idxBs,X
		AND		#$EF
		STA		_scr_idxBs,X
		RTS

; =============== S U B R O U T I N E =======================================
_native_idxBs_10_set:
		LDA		_scr_idxBs,X
		ORA		#$10
		STA		_scr_idxBs,X
		RTS

; =============== S U B R O U T I N E =======================================
_native_idxBs_10_test:
		LDA		_scr_idxBs,X
		AND		#$10
		STA		_scr_idxBs,X
		JMP		_scr_flags_update

; =============== S U B R O U T I N E =======================================
_native_sub151:
		LDA		_scr_idxBs,X
		JMP		_native_sub14C_ex

; =============== S U B R O U T I N E =======================================
_native_sub14C:
		LDA		_scr_idxCs,X
		JMP		_native_sub14C_ex

; =============== S U B R O U T I N E =======================================
_native_sub155:
		LDA		_scr_idxAs,X

; =============== S U B R O U T I N E =======================================
_native_sub14C_ex:
		AND		#$0F
		TAY
		LDA		_scr_idxBs,Y
		PHA
		AND		#$EF
		STA		_scr_idxBs,Y
		PLA
		AND		#$10
		JMP		_scr_flags_update

; =============== S U B R O U T I N E =======================================
_native_sub134:
		LDA		_scr_idxCs,X
		AND		#$3F
		STA		_scr_idxCs,X
		RTS

; =============== S U B R O U T I N E =======================================
_native_sub12B:
		LDA		_scr_idxCs,X
		ORA		#$80
		STA		_scr_idxCs,X
		RTS

; =============== S U B R O U T I N E =======================================
_native_sub17D:
		LDA		_scr_idxCs,X
		AND		#$80
		JMP		_scr_flags_update

; =============== S U B R O U T I N E =======================================
_native_sub117:
		LDA		_scr_cur_slot_idx
		TAY
		ORA		#$50
		STA		_scr_idxCs,X
		TXA
		STA		_scr_idxCs,Y
		RTS

; =============== S U B R O U T I N E =======================================
_native_sub150:
		LDA		_scr_cur_slot_idx
		STA		_scr_idxBs,X
		RTS

; =============== S U B R O U T I N E =======================================
_native_sub14B:
		LDA		_scr_cur_slot_idx
		STA		_scr_idxCs,X
		RTS

; =============== S C R I P T ===============================================
_script1FE:
		SYNC
		TARGET_DIR_SET		$FF
		TARGET_FOLLOW
		SJMP				_script1FE

; =============== S C R I P T ===============================================
_script1FF:
		NJSR				_native_sub17C
		SBCC				_script1FE
		SYNC
		TARGET_DIR_SET		$FF
		TARGET_FOLLOW
		NJSR				_native_sub118
		SBCS				_script1FF
		SRET

; =============== S U B R O U T I N E =======================================
_native_sub17C:
		LDA		_scr_vars18,X
		CMP		#$20
		JMP		_scr_flags_update

; =============== S C R I P T ===============================================
_script_idle:
		SUSPEND				$FF
		SJMP				_script_idle

; =============== S C R I P T ===============================================
_script_animate32:
		JMP_OBJ_ANIMATE
		JMP_OBJ_ANIMATE
		JMP_OBJ_ANIMATE
		JMP_OBJ_ANIMATE
		JMP_OBJ_ANIMATE
		JMP_OBJ_ANIMATE
		JMP_OBJ_ANIMATE
		JMP_OBJ_ANIMATE
		JMP_OBJ_ANIMATE
		JMP_OBJ_ANIMATE
		JMP_OBJ_ANIMATE
		JMP_OBJ_ANIMATE
		JMP_OBJ_ANIMATE
		JMP_OBJ_ANIMATE
		JMP_OBJ_ANIMATE
		JMP_OBJ_ANIMATE

; !FALLTHROUGH!

; =============== S C R I P T ===============================================
_script_animate16:
		JMP_OBJ_ANIMATE
		JMP_OBJ_ANIMATE
		JMP_OBJ_ANIMATE
		JMP_OBJ_ANIMATE
		JMP_OBJ_ANIMATE
		JMP_OBJ_ANIMATE

; !FALLTHROUGH!

; =============== S C R I P T ===============================================
_script_animate12:
		JMP_OBJ_ANIMATE
		JMP_OBJ_ANIMATE

; !FALLTHROUGH!

; =============== S C R I P T ===============================================
_script_animate10:
		JMP_OBJ_ANIMATE
		JMP_OBJ_ANIMATE
		JMP_OBJ_ANIMATE
		JMP_OBJ_ANIMATE
		JMP_OBJ_ANIMATE

; !FALLTHROUGH!

; =============== S C R I P T ===============================================
_script_animate3:
		JMP_OBJ_ANIMATE
		JMP_OBJ_ANIMATE
		JMP_OBJ_ANIMATE
		SRET

; =============== S U B R O U T I N E =======================================
_native_sub109:
		LDA		_obj_y_deltas,X
		BMI		loc_B6548
		CMP		#$50
		BCS		locret_B6551
loc_B6548:
		CLC
		LDA		_obj_y_deltas,X
		ADC		#$03
		STA		_obj_y_deltas,X
locret_B6551:
		RTS

; =============== S U B R O U T I N E =======================================
_native_sub12C:
		LDA		_obj_x_deltas,X
		BMI		loc_B655E
		SEC
		SBC		#$02
		STA		_obj_x_deltas,X
		RTS
loc_B655E:
		CLC
		ADC		#$02
		STA		_obj_x_deltas,X
		RTS

; =============== S U B R O U T I N E =======================================
_unref_4:
		CLC
		LDA		_scr_vars18,X
		ADC		#$01
		AND		#$3F
		STA		_scr_vars18,X
		RTS

; =============== S U B R O U T I N E =======================================
_unref_5:
		SEC
		LDA		_scr_vars18,X
		SBC		#$01
		AND		#$3F
		STA		_scr_vars18,X
		RTS

; =============== S U B R O U T I N E =======================================
_scr_flags_flush:
		BCC		_scr_flags_flush_sec

; =============== S U B R O U T I N E =======================================
_scr_flags_flush_clc:
		CLC
		JMP		_scr_flags_update

; =============== S U B R O U T I N E =======================================
_scr_flags_flush_sec:
		SEC
		JMP		_scr_flags_update

; =============== S U B R O U T I N E =======================================
_native_sub10B:
		CLC
		LDA		_obj_y_lo_poss,X
		ADC		byte_B0
		STA		_tmp_ptrE
		JSR		_obj_vert_animate
		CLC
		LDA		_obj_y_lo_poss,X
		ADC		byte_B0
		EOR		_tmp_ptrE
		AND		#$F0
		BEQ		_scr_flags_flush_clc

; =============== S U B R O U T I N E =======================================
_native_sub118:
		LDA		_obj_hps,X
		BEQ		_scr_flags_flush_clc
		LDY		#$A0
		JSR		_obj_sys_calc03
		JMP		_scr_flags_update

; =============== S U B R O U T I N E =======================================
_native_sub10A:
		LDA		_obj_hps,X
		BEQ		_scr_flags_flush_sec
		JSR		_obj_sys_calc01
		JMP		_scr_flags_flush

; =============== S U B R O U T I N E =======================================
_native_sub104:
		LDA		_obj_hps,X
		BEQ		_scr_flags_flush_sec
		LDA		_obj_x_deltas,X
		BEQ		_scr_flags_flush_sec
		SEC
		LDA		_obj_x_deltas,X
; REDUNDANT: we only may get here if _obj_x_deltas=0 so this branch never
; taken
		BEQ		loc_B65CB
; -
		BMI		loc_B65CE
		JSR		_obj_sys_calc04
loc_B65CB:
		JMP		_scr_flags_flush
loc_B65CE:
		JSR		_obj_sys_calc06
		JMP		_scr_flags_flush

; =============== S U B R O U T I N E =======================================
_native_sub164:
		LDA		#$80
		STA		_scr_vars21,X
		RTS

; =============== S U B R O U T I N E =======================================
_native_sub13C:
		LDA		_obj_x_deltas,X
		BEQ		_scr_flags_flush_clc
		JSR		_players_animB_sub0129_sub12_A_B_A
		BCC		_scr_flags_flush_clc
		LDA		_obj_x_deltas,X
		BPL		loc_B65EF
		JSR		_players_animB_sub0129_E_A_A
		JMP		_scr_flags_flush_sec
loc_B65EF:
		JSR		_players_animB_sub0129_F_A_A
		JMP		_scr_flags_flush_sec

; =============== S U B R O U T I N E =======================================
_native_sub165:
		JSR		_players_animB_sub0129_sub12_A_B_A
		BCC		loc_B65FE
		JSR		_players_animB_sub0129_sub12_A_B_B
		SEC
loc_B65FE:
		JMP		_scr_flags_flush

; =============== S U B R O U T I N E =======================================
_native_sub107:
		JSR		_native_sub164
		INC		_obj_y_lo_poss,X
		JSR		_players_animB_sub0129_sub12_A_B_A
		PHP
		DEC		_obj_y_lo_poss,X
		PLP
		BCC		loc_B6619
		JSR		_players_animB_sub0129_sub05_A_B_A
		TYA
		STA		_scr_vars21,X
		SEC
loc_B6619:
		JMP		_scr_flags_update

; =============== S U B R O U T I N E =======================================
_native_sub131:
		LDA		#$40
		BNE		_native_sub131_ex

; =============== S U B R O U T I N E =======================================
_native_sub10C:
		LDA		#$20

; =============== S U B R O U T I N E =======================================
_native_sub131_ex:
		STA		_tmp_ptrE
		LDY		#$0B
loc_B6626:
		LDA		_scr_params,Y
		AND		#$0F
		CMP		#$03
		BNE		loc_B667C
		LDA		_obj_spr_libs,Y
		CMP		#$03
		BNE		loc_B667C
		LDA		_scr_idxBs,Y
		BMI		loc_B667C
		SEC
		LDA		_obj_x_lo_poss,X
		SBC		_obj_x_lo_poss,Y
		STA		_tmp_ptr0
		LDA		_obj_x_hi_poss,X
		SBC		_obj_x_hi_poss,Y
		BEQ		loc_B6665
		CMP		#$FF
		BNE		loc_B667C
		LDA		_obj_flips,X
		AND		#$40
		BEQ		loc_B667C
		LDA		_obj_x_deltas,Y
		BPL		loc_B667C
		CLC
		LDA		_tmp_ptr0
		ADC		_tmp_ptrE
		BCC		loc_B667C
		BCS		loc_B6677
loc_B6665:
		LDA		_obj_flips,X
		AND		#$40
		BNE		loc_B667C
		LDA		_obj_x_deltas,Y
		BMI		loc_B667C
		LDA		_tmp_ptr0
		CMP		_tmp_ptrE
		BCS		loc_B667C
loc_B6677:
		JSR		_native_sub115_ex
		BCC		loc_B6682
loc_B667C:
		DEY
		BPL		loc_B6626
		JMP		_scr_flags_flush_sec
loc_B6682:
		TYA
		STA		_scr_idxAs,X
		JMP		_scr_flags_flush_clc

; =============== S U B R O U T I N E =======================================
_native_sub10D:
		LDY		_scr_idxAs,X
		LDA		_scr_vars1C,Y
		CMP		#$02
		BEQ		locret_B6698
		LDA		#$FF
		STA		_obj_hps,Y
locret_B6698:
		RTS

; =============== S U B R O U T I N E =======================================
_native_sub16E:
		SEC
		LDA		_obj_widths,X
		ADC		#$06
		BNE		_native_sub16E_ex

; =============== S U B R O U T I N E =======================================
_native_sub116:
		LDA		#$30
		BNE		_native_sub16E_ex

; =============== S U B R O U T I N E =======================================
_native_sub128:
		LDA		#$40
		BNE		_native_sub16E_ex

; =============== S U B R O U T I N E =======================================
_native_sub17E:
		LDA		#$50
		BNE		_native_sub16E_ex

; =============== S U B R O U T I N E =======================================
_native_sub112:
		LDA		#$60

; =============== S U B R O U T I N E =======================================
_native_sub16E_ex:
		STA		_tmp_ptrE
		LDY		byte_AB
		SEC
		LDA		_obj_x_lo_poss,X
		SBC		_obj_x_lo_poss,Y
		STA		_tmp_ptr0
		LDA		_obj_x_hi_poss,X
		SBC		_obj_x_hi_poss,Y
		BPL		loc_B66CB
		CLC
		LDA		#$01
		SBC		_tmp_ptr0
		STA		_tmp_ptr0
loc_B66CB:
		LDA		_tmp_ptr0
		CMP		_tmp_ptrE
		JMP		_scr_flags_update

; =============== S U B R O U T I N E =======================================
_native_sub115:
		LDY		byte_AB

; =============== S U B R O U T I N E =======================================
_native_sub115_ex:
		SEC
		LDA		_obj_y_lo_poss,X
		SBC		_obj_y_lo_poss,Y
		STA		_tmp_ptr0
		LDA		_obj_y_hi_poss,X
		SBC		_obj_y_hi_poss,Y
		BEQ		loc_B66F5
		CMP		#$FF
		BEQ		loc_B66EC
		JMP		_scr_flags_flush_sec
loc_B66EC:
		CLC
		LDA		_tmp_ptr0
		ADC		_obj_heigts,Y
		JMP		_scr_flags_flush
loc_B66F5:
		LDA		_tmp_ptr0
		CMP		_obj_heigts,X
		JMP		_scr_flags_update

; =============== S U B R O U T I N E =======================================
_native_sub132:
		LDY		_scr_idxAs,X
		JMP		_native_sub132_A

; =============== S U B R O U T I N E =======================================
_native_sub16F:
		LDY		byte_AB
		SEC
		LDA		_obj_x_lo_poss,X
		SBC		_obj_x_lo_poss,Y
		LDA		_obj_x_hi_poss,X
		SBC		_obj_x_hi_poss,Y
		JMP		_scr_flags_update

; =============== S U B R O U T I N E =======================================
_native_sub10E:
		LDA		_obj_x_hi_poss,X
		BMI		_native_sub10E_A
		BNE		_native_sub167
		LDY		byte_AB

; =============== S U B R O U T I N E =======================================
_native_sub132_A:
		LDA		_obj_x_lo_poss,Y
		CMP		_obj_x_lo_poss,X
		BCS		_native_sub10E_A

; =============== S U B R O U T I N E =======================================
_native_sub167:
		LDA		_obj_flips,X
		AND		#$BF
		STA		_obj_flips,X
		RTS

; =============== S U B R O U T I N E =======================================
_native_sub10E_A:
		LDA		_obj_flips,X
		ORA		#$40
		STA		_obj_flips,X
		RTS

; =============== S U B R O U T I N E =======================================
_native_sub110_A:
		LDA		_obj_flips,X
		EOR		#$40
		STA		_obj_flips,X
		RTS

; =============== S U B R O U T I N E =======================================
_native_sub125:
		LDA		_obj_flips,X
		AND		#$40
		JMP		_scr_flags_update

; =============== S U B R O U T I N E =======================================
_native_sub17B:
		LDA		_obj_flips,X
		ORA		#$20
		STA		_obj_flips,X
		RTS

; =============== S U B R O U T I N E =======================================
_native_sub110:
		JSR		_native_sub110_A

; =============== S U B R O U T I N E =======================================
_native_sub105:
		JMP		_native_sub105_A

; =============== S U B R O U T I N E =======================================
_native_sub129:
		SEC
		LDA		#$00
		SBC		_obj_y_deltas,X
		STA		_obj_y_deltas,X
		RTS

; =============== S U B R O U T I N E =======================================
_players_animB_sub67_A:
		LDY		_scr_idxAs,X
		LDA		_obj_x_lo_poss,X
		CMP		_obj_x_lo_poss,Y
		BCS		_native_sub11B_ex
		BCC		_native_sub10F_A

; =============== S U B R O U T I N E =======================================
_players_animB_sub3_B_A:
		LDY		_scr_idxAs,X
		LDA		_obj_x_deltas,Y
		BMI		_native_sub11B_ex
		BPL		_native_sub10F_A

; =============== S U B R O U T I N E =======================================
_native_sub11B:
		LDA		_obj_flips,X
		AND		#$40
		BNE		_native_sub11B_ex
		BEQ		_native_sub10F_A
		LDY		_scr_idxAs,X
		LDA		_obj_flips,Y
		STA		_obj_flips,X

; =============== S U B R O U T I N E =======================================
_native_sub10F:
		LDA		_obj_flips,X
		AND		#$40
		BNE		_native_sub10F_A

; =============== S U B R O U T I N E =======================================
_native_sub11B_ex:
		LDA		_obj_x_deltas,X
		BMI		nullsub9

; =============== S U B R O U T I N E =======================================
_native_sub105_A:
		SEC
		LDA		#$00
		SBC		_obj_x_deltas,X
		STA		_obj_x_deltas,X
		RTS

; =============== S U B R O U T I N E =======================================
_native_sub10F_A:
		LDA		_obj_x_deltas,X
		BMI		_native_sub105_A

; =============== S U B R O U T I N E =======================================
nullsub9:
		RTS

; =============== S U B R O U T I N E =======================================
_native_sub121:
		LDA		#$7E
		BNE		_native_sub141_ex

; =============== S U B R O U T I N E =======================================
_native_sub141:
		LDA		#$2C
		BNE		_native_sub141_ex

; =============== S U B R O U T I N E =======================================
_native_sub12E:
		LDA		#$13
		BNE		_native_sub141_ex

; =============== S U B R O U T I N E =======================================
_native_sub119:
		LDA		#$0C

; =============== S U B R O U T I N E =======================================
_native_sub141_ex:
		STA		_tmp_ptr0
		LDA		_obj_flips,X
		AND		#$40
		BNE		loc_B67D2
		SEC
		LDA		_obj_x_lo_poss,X
		SBC		_tmp_ptr0
		STA		_obj_x_lo_poss,X
		LDA		_obj_x_hi_poss,X
		SBC		#$00
		STA		_obj_x_hi_poss,X
		JMP		loc_B67E3
loc_B67D2:
		CLC
		LDA		_obj_x_lo_poss,X
		ADC		_tmp_ptr0
		STA		_obj_x_lo_poss,X
		LDA		_obj_x_hi_poss,X
		ADC		#$00
		STA		_obj_x_hi_poss,X
loc_B67E3:
		JSR		_native_sub10F
		JMP		_native_sub12B

; =============== S U B R O U T I N E =======================================
_native_cmp40_obj_y_lo_pos:
		LDA		#$40
		BNE		_native_cmp_obj_y_lo_pos

; =============== S U B R O U T I N E =======================================
_native_cmp50_obj_y_lo_pos:
		LDA		#$50
		BNE		_native_cmp_obj_y_lo_pos

; =============== S U B R O U T I N E =======================================
_native_cmp80_obj_y_lo_pos:
		LDA		#$80
		BNE		_native_cmp_obj_y_lo_pos

; =============== S U B R O U T I N E =======================================
_native_cmpC0_obj_y_lo_pos:
		LDA		#$C0

; =============== S U B R O U T I N E =======================================
_native_cmp_obj_y_lo_pos:
		CMP		_obj_y_lo_poss,X
		JMP		_scr_flags_update

; =============== S U B R O U T I N E =======================================
_native_cmp08_obj_x_lo_pos:
		LDA		#$08
		BNE		_native_cmp_obj_x_lo_pos

; =============== S U B R O U T I N E =======================================
_native_cmp20_obj_x_lo_pos:
		LDA		#$20
		BNE		_native_cmp_obj_x_lo_pos

; =============== S U B R O U T I N E =======================================
_native_cmp40_obj_x_lo_pos:
		LDA		#$40
		BNE		_native_cmp_obj_x_lo_pos

; =============== S U B R O U T I N E =======================================
_native_cmp50_obj_x_lo_pos_unref:
		LDA		#$50
		BNE		_native_cmp_obj_x_lo_pos

; =============== S U B R O U T I N E =======================================
_native_cmp80_obj_x_lo_pos:
		LDA		#$80
		BNE		_native_cmp_obj_x_lo_pos

; =============== S U B R O U T I N E =======================================
_native_cmpC0_obj_x_lo_pos:
		LDA		#$C0
		BNE		_native_cmp_obj_x_lo_pos

; =============== S U B R O U T I N E =======================================
_native_cmpE0_obj_x_lo_pos:
		LDA		#$E0

; =============== S U B R O U T I N E =======================================
_native_cmp_obj_x_lo_pos:
		CMP		_obj_x_lo_poss,X
		JMP		_scr_flags_update

; =============== S U B R O U T I N E =======================================
_native_get_obj_x_delta:
		LDA		_obj_x_deltas,X
		JMP		_scr_flags_update

; =============== S U B R O U T I N E =======================================
_native_get_obj_y_delta:
		LDA		_obj_y_deltas,X
		JMP		_scr_flags_update

; =============== S U B R O U T I N E =======================================
_native_sub135:
		LDA		_obj_x_deltas,X
		BPL		loc_B6836
		LDA		_obj_x_lo_poss,X
		CMP		#$20
		JMP		_scr_flags_flush
loc_B6836:
		LDA		_obj_x_lo_poss,X
		CMP		#$E0
		JMP		_scr_flags_update

; =============== S U B R O U T I N E =======================================
_native_sub149:
		LDA		_obj_x_hi_poss,X
		ORA		_obj_y_hi_poss,X
		JMP		_scr_flags_update

; =============== S U B R O U T I N E =======================================
_native_sub049_A:
		LDA		_scr_idxAs,X
		TAX

; =============== S U B R O U T I N E =======================================
_native_get_obj_low_nibble_var0D:
		LDA		_scr_idxBs,X
		AND		#$0F
		TAY
		RTS

; =============== S U B R O U T I N E =======================================
_native_get_obj_low_nibble_var1E:
		LDA		_scr_idxCs,X
		AND		#$0F
		TAY
		RTS

; =============== S U B R O U T I N E =======================================
_native_get_obj3_hp:
		LDA		_obj_hps+3
		JMP		_scr_flags_update

; =============== S U B R O U T I N E =======================================
_native_get_obj_var0D:
		LDA		_scr_idxBs,X
		JMP		_scr_flags_update

; =============== S U B R O U T I N E =======================================
_native_get_obj_hp:
		LDA		_obj_hps,X
		JMP		_scr_flags_update

; =============== S C R I P T ===============================================
_script200:
		NJMP				_native_get_obj_hp
		SBEQ				_script200
		SRET

; =============== S U B R O U T I N E =======================================
_native_sub04A_A:
		JSR		_native_get_obj_low_nibble_var1E
		LDA		_obj_x_lo_poss,Y
		STA		_obj_x_lo_poss,X
		LDA		_obj_x_hi_poss,Y
		STA		_obj_x_hi_poss,X
		LDA		_obj_flips,Y
		AND		#$80
		BEQ		loc_B6895
		LDA		_obj_y_lo_poss,Y
		STA		_obj_y_lo_poss,X
		LDA		_obj_y_hi_poss,Y
		STA		_obj_y_hi_poss,X
		RTS
loc_B6895:
		CLC
		LDA		_obj_y_lo_poss,Y
		SBC		_obj_heigts,Y
		STA		_obj_y_lo_poss,X
		LDA		_obj_y_hi_poss,Y
		SBC		#$00
		STA		_obj_y_hi_poss,X
		RTS

; =============== S U B R O U T I N E =======================================
_players_animB_sub0129_sub06_C:
		JSR		_native_get_obj_low_nibble_var0D
		LDA		_obj_flips,X
		AND		#$1F
		STA		_obj_flips,X
		LDA		_scr_params,X
		AND		#$0F
		CMP		#$02
		BEQ		loc_B68C0
		CMP		#$06
		BNE		loc_B68CA
loc_B68C0:
		LDA		_obj_flips,Y
		EOR		#$C0
		AND		#$E0
		JMP		loc_B68CF
loc_B68CA:
		LDA		_obj_flips,Y
		AND		#$20
loc_B68CF:
		ORA		_obj_flips,X
		STA		_obj_flips,X
		LDA		_obj_x_lo_poss,Y
		STA		_obj_x_lo_poss,X
		LDA		_obj_x_hi_poss,Y
		STA		_obj_x_hi_poss,X
		CLC
		LDA		_obj_y_lo_poss,Y
		SBC		_obj_heigts,Y
		STA		_obj_y_lo_poss,X
		LDA		_obj_y_hi_poss,Y
		SBC		#$00
		STA		_obj_y_hi_poss,X
		RTS

; =============== S U B R O U T I N E =======================================
_native_sub114:
		LDA		_obj_y_lo_poss,X
		AND		#$F0
		STA		_obj_y_lo_poss,X
		LDA		#$00
		STA		_obj_y_accel,X
		RTS

; =============== S U B R O U T I N E =======================================
_native_sub11C:
		LDA		_obj_flips,X
		AND		#$D3
		STA		_obj_flips,X
		LDA		#$02
		STA		_scr_vars1C,X
		JMP		_native_sub12B

; =============== S U B R O U T I N E =======================================
_native_sub15E:
		LDA		#$01
		BNE		_native_sub15E_ex

; =============== S U B R O U T I N E =======================================
_native_sub13A:
		LDA		#$03
		BNE		_native_sub15E_ex

; =============== S U B R O U T I N E =======================================
_native_sub13E:
		LDA		#$07
		BNE		_native_sub15E_ex

; =============== S U B R O U T I N E =======================================
_native_sub160:
		LDA		_scr_idxBs,X
		AND		#$DF
		STA		_scr_idxBs,X

; =============== S U B R O U T I N E =======================================
_native_sub13B:
		LDA		#$00
		STA		_scr_vars1C,X

; =============== S U B R O U T I N E =======================================
_native_sub166:
		LDA		#$09
		BNE		_native_sub15E_ex

; =============== S U B R O U T I N E =======================================
_native_sub16C:
		LDA		#$0A
		BNE		_native_sub15E_ex

; =============== S U B R O U T I N E =======================================
_native_sub161:
		LDA		#$05
		BNE		_native_sub15E_ex

; =============== S U B R O U T I N E =======================================
_native_sub11D:
		LDA		#$04

; =============== S U B R O U T I N E =======================================
_native_sub15E_ex:
		STA		_tmp_ptr0
		LDA		_scr_params,X
		AND		#$F0
		ORA		_tmp_ptr0
		STA		_scr_params,X
		RTS

; =============== S C R I P T ===============================================
_script201:
		PARAM_80_CLEAR

; !FALLTHROUGH!

; =============== S C R I P T ===============================================
_script202:
		NJMP				_native_sub17D
		SBNE				_script202
		SRET

; =============== S U B R O U T I N E =======================================
_far_prg3_rect_draw:
		STA		_tmp_ptr0
		STY		_tmp_ptr0+1
		LDA		_cur_prg_bank
		PHA
		LDA		#$03
		JSR		_mmc1_prg_set
		JSR		_rect_draw
		JMP		_mmc1_prg_restore

; =============== S U B R O U T I N E =======================================
_far_prg3_tlm_queue:
		STA		_tmp_ptr0
		STY		_tmp_ptr0+1
		LDA		_cur_prg_bank
		PHA
		LDA		#$03
		JSR		_mmc1_prg_set
		LDA		_tmp_ptr2
		JSR		_tlm_queue
		JMP		_mmc1_prg_restore

; =============== S U B R O U T I N E =======================================
_native_sub146:
		LDY		_obj_x_deltas,X
		BEQ		locret_B69D6
		LDA		_ppu_scroll_shadow_lo
		STA		_tmp_ptr2
		LDA		_ppu_scroll_nt_hor
		STA		_tmp_ptr2+1
		TYA
		BPL		loc_B69A7
		SEC
		LDA		#$00
		SBC		_obj_x_deltas,X
		JSR		_swap_4bit_nibbles
		PHA
		AND		#$F0
		CLC
		ADC		_obj_x_accel,X
		STA		_obj_x_accel,X
		PLA
		AND		#$07
		ADC		_ppu_scroll_shadow_lo
		STA		_ppu_scroll_shadow_lo
		LDA		_ppu_scroll_nt_hor
		ADC		#$00
		STA		_ppu_scroll_nt_hor
		JMP		loc_B69C9
loc_B69A7:
		JSR		_swap_4bit_nibbles
		PHA
		AND		#$F0
		STA		_tmp_ptr0
		PLA
		AND		#$07
		STA		_tmp_ptr0+1
		SEC
		LDA		_obj_x_accel,X
		SBC		_tmp_ptr0
		STA		_obj_x_accel,X
		LDA		_ppu_scroll_shadow_lo
		SBC		_tmp_ptr0+1
		STA		_ppu_scroll_shadow_lo
		LDA		_ppu_scroll_nt_hor
		SBC		#$00
		STA		_ppu_scroll_nt_hor
loc_B69C9:
		SEC
		LDA		_ppu_scroll_shadow_lo
		SBC		_tmp_ptr2
		STA		_obj_global_x_shift
		LDA		_ppu_scroll_nt_hor
		SBC		_tmp_ptr2+1
		STA		_obj_global_x_shift+1
locret_B69D6:
		RTS

; =============== S U B R O U T I N E =======================================
_native_sub147:
		LDA		_obj_y_deltas,X
		BEQ		locret_B6A45
		STA		_tmp_ptr0
		LDA		_ppu_scroll_shadow_hi
		STA		_tmp_ptr2
		LDA		_ppu_scroll_nt_vert
		STA		_tmp_ptr2+1
		LDA		_tmp_ptr0
		BMI		loc_B6A12
		JSR		_swap_4bit_nibbles
		PHA
		AND		#$07
		TAY
		PLA
		AND		#$F0
		STA		_tmp_ptr0
		SEC
		LDA		_obj_y_accel,X
		SBC		_tmp_ptr0
		STA		_obj_y_accel,X
		BCS		loc_B6A02
		INY
loc_B6A02:
		LDA		_ppu_scroll_shadow_hi
		JSR		_sub_minus16
		STA		_ppu_scroll_shadow_hi
		LDA		_ppu_scroll_nt_vert
		SBC		#$00
		STA		_ppu_scroll_nt_vert
		JMP		loc_B6A38
loc_B6A12:
		SEC
		LDA		#$00
		SBC		_tmp_ptr0
		JSR		_swap_4bit_nibbles
		PHA
		AND		#$07
		TAY
		PLA
		AND		#$F0
		CLC
		ADC		_obj_y_accel,X
		STA		_obj_y_accel,X
		BCC		loc_B6A2B
		INY
loc_B6A2B:
		LDA		_ppu_scroll_shadow_hi
		JSR		_add_plus16
		STA		_ppu_scroll_shadow_hi
		LDA		_ppu_scroll_nt_vert
		ADC		#$00
		STA		_ppu_scroll_nt_vert
loc_B6A38:
		SEC
		LDA		_ppu_scroll_shadow_hi
		SBC		_tmp_ptr2
		STA		_obj_global_y_shift
		LDA		_ppu_scroll_nt_vert
		SBC		_tmp_ptr2+1
		STA		_obj_global_y_shift+1
locret_B6A45:
		RTS

; =============== S U B R O U T I N E =======================================
_native_sub11E:
		LDX		#$00
		LDY		#$0B
loc_B6A4A:
		LDA		_scr_params,Y
		AND		#$0F
		CMP		#$06
		BNE		loc_B6A5B
		LDA		_obj_spr_libs,Y
		CMP		#$09
		BNE		loc_B6A5B
		INX
loc_B6A5B:
		DEY
		BPL		loc_B6A4A
		CPX		#$00
		JMP		_scr_flags_update

; =============== S U B R O U T I N E =======================================
_native_sub170:
		LDA		#$00
		BEQ		_native_sub138_ex

; =============== S U B R O U T I N E =======================================
_native_sub138:
		LDA		#$01
		BNE		_native_sub138_ex

; =============== S U B R O U T I N E =======================================
_native_sub13D:
		LDA		#$02

; =============== S U B R O U T I N E =======================================
_native_sub138_ex:
		STA		_tmp_ptr0
		LDX		#$00
		LDY		#$0B
loc_B6A73:
		LDA		_scr_params,Y
		AND		#$0F
		BEQ		loc_B6A82
		LDA		_scr_params,Y
		AND		#$40
		BEQ		loc_B6A82
		INX
loc_B6A82:
		DEY
		BPL		loc_B6A73
		CPX		_tmp_ptr0
		JMP		_scr_flags_update

; =============== S C R I P T ===============================================
_script203:
		SJSR				_script209
		LOOPB				$03,_script203
		SRET

; =============== S C R I P T ===============================================
_script204:
		SJSR				_script209
		LOOPB				$04,_script203
		SRET

; =============== S C R I P T ===============================================
_script205:
		SJSR				_script209
		LOOPB				$06,_script205
		SRET

; =============== S C R I P T ===============================================
_script206:
		SJSR				_script209
		LOOPB				$08,_script206
		SRET

; =============== S C R I P T ===============================================
_script207:
		SJSR				_script209
		LOOPB				$0A,_script207
		SRET

; =============== S C R I P T ===============================================
_script208:
		SJSR				_script209
		LOOPB				$10,_script208
		SRET

; =============== S C R I P T ===============================================
_script209:
		JMP_OBJ_ANIMATE

; =============== S C R I P T ===============================================
_script20A:
		NJSR				_native_sub144
		SBNE				byte_B6AC6
		APU_LOAD			$2F
		NJSR				_scr_param_10_set
byte_B6AC6:
		NJSR				_native_sub145
		SRET

; =============== S C R I P T ===============================================
_script20B:
		SJSR				byte_B6AD1
		SBCS				_script20B
		SRET
byte_B6AD1:
		SYNC
		SJSR				_script20A
		NJSR				_obj_move_hor_animate
		NJSR				_native_sub109
		NJSR				_native_get_obj_y_delta
		SBMI				byte_B6AE8
		NJSR				_obj_vert_animate
		NJSR				_scr_flags_flush_clc
		SRET
byte_B6AE8:
		NJSR				_native_sub10B
		SBCS				byte_B6AF0
		OBJ_SET_Y_DELTA		$00
byte_B6AF0:
		SRET

; =============== S C R I P T ===============================================
_obj_scr_common_small_boss_destr:
		APU_LOAD			$70
		OBJ_SET_X_DELTA		$F0
		OBJ_SET_Y_DELTA		$C0
		NJSR				_players_animB_sub3_B_A
		NJSR				_scr_param_10_set
byte_B6AFD:
		JMP_OBJ_ANIMATE
		NJSR				_native_sub109
		NJSR				_native_obj_cmp160_y_pos
		SBPL				byte_B6AFD
byte_B6B07:
		STORE				$80,_stage_flags
		SJMP				_script_idle

; =============== S U B R O U T I N E =======================================
_native_obj_cmp160_y_pos:
		SEC
		LDA		_obj_y_lo_poss,X
		SBC		#$60
		LDA		_obj_y_hi_poss,X
		SBC		#$01
		JMP		_scr_flags_update

; =============== S U B R O U T I N E =======================================
_native_sub14F:
		LDA		_cur_prg_bank
		PHA
		CLC
		LDA		_scr_loopsB,X
		ADC		#$40
		STA		_tmpA
		CLC
		LDA		_scr_loopsA,X
		ADC		#$20
		STA		_tmpC
		JSR		_room_drawA_ex_C
		JSR		_sys_room_draw_sub02
		CLC
		LDA		_tmpA
		ADC		#$10
		STA		_tmpA
		JSR		_room_drawA_ex_C
		JSR		_sys_room_draw_sub02
		JMP		_mmc1_prg_restore

; =============== S C R I P T ===============================================
_script20C:
		NJMP				_native_sub152
		SBEQ				_script20C
		SRET

; =============== S U B R O U T I N E =======================================
_far_sys_room_draw_sub02:
		STA		_tmpA
		STY		_tmpC
		LDA		#<[_sys_room_draw_sub02]
		LDY		#>[_sys_room_draw_sub02]
		JSR		_farcall
		RTS

; =============== S U B R O U T I N E =======================================
_native_sub152:
		LDA		_cur_prg_bank
		PHA
		LDA		#$03
		JSR		_mmc1_prg_set
		LDA		#$00
		STA		byte_97
		LDY		byte_97
		LDA		(_tmp_ptr4B),Y
		BEQ		loc_B6B97
		STA		byte_95
		INY
		LDA		(_tmp_ptr4B),Y
		STA		_tmpA
		INY
		LDA		(_tmp_ptr4B),Y
		STA		_tmpC
		INY
		STY		byte_97
loc_B6B79:
		LDY		byte_97
		LDA		(_tmp_ptr4B),Y
		INC		byte_97
		TAX
		LDA		_room_flags
		AND		#$20
		BEQ		loc_B6B8C
		JSR		_sys_room_draw_sub04
		JMP		loc_B6B8F
loc_B6B8C:
		JSR		_sys_room_draw_sub02
loc_B6B8F:
		INC		_tmpA
		DEC		byte_95
		BNE		loc_B6B79
		LDA		#$FF
loc_B6B97:
		JSR		_scr_flags_update
		CLC
		LDA		_tmp_ptr4B
		ADC		byte_97
		STA		_tmp_ptr4B
		LDA		_tmp_ptr4B+1
		ADC		#$00
		STA		_tmp_ptr4B+1
		JMP		_mmc1_prg_restore

; =============== S U B R O U T I N E =======================================
_far_players_animB_sub0129_sub16_E:
		LDA		_cur_prg_bank
		PHA
		LDA		#$02
		JSR		_mmc1_prg_set
		JSR		_players_animB_sub0129_sub16_E
		JMP		_mmc1_prg_restore

; =============== S U B R O U T I N E =======================================
_far_players_animB_sub0129_G:
		LDA		_cur_prg_bank
		PHA
		LDA		#$02
		JSR		_mmc1_prg_set
		JSR		_players_animB_sub0129_G
		JSR		_scr_flags_update
		JMP		_mmc1_prg_restore

; =============== S U B R O U T I N E =======================================
_native_sub16D:
		LDY		#$01
loc_B6BCB:
		TXA
		CMP		_scr_vars21,Y
		BNE		loc_B6BD7
		LDA		_obj_x_deltas,X
		STA		_players_x_shifs,Y
loc_B6BD7:
		DEY
		BPL		loc_B6BCB
		RTS

; =============== S U B R O U T I N E =======================================
_native_sub163:
		LDY		#$01
loc_B6BDD:
		TXA
		CMP		_scr_vars21,Y
		BNE		loc_B6BE6
		JSR		_native_sub163_A
loc_B6BE6:
		DEY
		BPL		loc_B6BDD
		RTS

; =============== S U B R O U T I N E =======================================
_native_sub169:
		LDY		_scr_idxAs,X
		BMI		nullsub4

; =============== S U B R O U T I N E =======================================
_native_sub163_A:
		CLC
		LDA		_obj_y_lo_poss,X
		SBC		_obj_heigts,X
		STA		_obj_y_lo_poss,Y

; =============== S U B R O U T I N E =======================================
nullsub4:
		RTS

; =============== S U B R O U T I N E =======================================
_native_sub162:
		LDY		#$0B
		TXA
loc_B6BFD:
		CMP		_scr_vars21,Y
		BEQ		loc_B6C06
		DEY
		BPL		loc_B6BFD
		CLC
loc_B6C06:
		TYA
		STA		_scr_idxAs,X
		JMP		_scr_flags_update

; =============== S C R I P T ===============================================
_script20D:
		NJMP				_native_sub162
		SBCC				_script20D
byte_B6C13:
		NJMP				_native_sub162
		SBCS				byte_B6C13
		SRET

; =============== S U B R O U T I N E =======================================
_native_sub15D:
		LDY		_scr_idxAs,X

; =============== S U B R O U T I N E =======================================
_native_sub049_B:
		LDA		_players_lives,Y
		CMP		#$0A
		BCS		locret_B6C2A
		CLC
		ADC		#$01
		STA		_players_lives,Y
locret_B6C2A:
		RTS

; =============== S U B R O U T I N E =======================================
_native_sub15F:
		LDY		_scr_idxAs,X
		LDA		_obj_hps,Y
		CMP		_players_def_max_hps,Y
		BCS		locret_B6C3C
		CLC
		ADC		#$01
		STA		_obj_hps,Y
locret_B6C3C:
		RTS

; =============== S U B R O U T I N E =======================================
_native_sub15C:
		LDY		_scr_idxAs,X
		LDA		_players_def_max_hps,Y
		STA		_obj_hps,Y
		RTS

; =============== S U B R O U T I N E =======================================
_native_sub158:
		LDY		_scr_idxAs,X
		LDA		_obj_flips,Y
		ORA		#$4C
		STA		_obj_flips,Y

; =============== S U B R O U T I N E =======================================
_native_sub15A_A:
		LDA		#$20
		JMP		_native_sub156_ex

; =============== S U B R O U T I N E =======================================
_native_sub156:
		LDY		_scr_idxAs,X
		LDA		_obj_flips,Y
		AND		#$BF
		ORA		#$0C
		STA		_obj_flips,Y
		LDA		#$E0

; =============== S U B R O U T I N E =======================================
_native_sub156_ex:
		STA		_obj_x_deltas,Y
		LDA		#$04
		STA		_players_vars0A,Y
		LDA		#$40
		STA		_players_vars07,Y
		LDA		#$14
		STA		_players_states,Y
		RTS

; =============== S U B R O U T I N E =======================================
_native_sub159:
		LDY		_scr_idxAs,X
		LDA		_players_states,Y
		CMP		#$05
		JMP		_scr_flags_update

; =============== S U B R O U T I N E =======================================
_native_sub157:
		INC		_stage_room_idx
		RTS

; =============== S U B R O U T I N E =======================================
_native_sub153:
		LDY		byte_AB
		LDA		_obj_x_lo_poss,Y
		STA		_tmp_ptr0
		LDA		_obj_x_hi_poss,Y
		STA		_tmp_ptr0+1
		LDA		_obj_y_lo_poss,Y
		STA		_tmp_ptr2
		LDA		_obj_y_hi_poss,Y
		STA		_tmp_ptr2+1
		SEC
		LDA		_tmp_ptr0
		SBC		_obj_x_lo_poss,X
		TAY
		LDA		_tmp_ptr0+1
		SBC		_obj_x_hi_poss,X
		JSR		_native_sub153_A
		STA		_obj_x_deltas,X
		SEC
		LDA		_tmp_ptr2
		SBC		_obj_y_lo_poss,X
		TAY
		LDA		_tmp_ptr2+1
		SBC		_obj_y_hi_poss,X
		JSR		_native_sub153_A
		STA		_obj_y_deltas,X
		JSR		_native_sub10E_A
		LDA		_obj_x_deltas,X
		BPL		loc_B6CD2
		JSR		_native_sub167
		SEC
		LDA		#$00
		SBC		_obj_x_deltas,X
loc_B6CD2:
		STA		byte_6
		LDA		_obj_y_deltas,X
		BPL		loc_B6CDF
		SEC
		LDA		#$00
		SBC		_obj_y_deltas,X
loc_B6CDF:
		ORA		byte_6
		AND		#$7C
		JMP		_scr_flags_update

; =============== S U B R O U T I N E =======================================
_native_sub153_A:
		STY		byte_6
		LSR
		ROR		byte_6
		LDA		byte_6
		RTS

; =============== S U B R O U T I N E =======================================
_native_sub16B:
		LDA		_players_lives
		BEQ		loc_B6CF4
		LDA		_players_lives+1
loc_B6CF4:
		JMP		_scr_flags_update

; =============== S U B R O U T I N E =======================================
_native_sub15A:
		LDY		#$01
loc_B6CF9:
		LDA		_players_states,Y
		CMP		#$04
		BNE		loc_B6D03
		JSR		_native_sub15A_A
loc_B6D03:
		DEY
		BPL		loc_B6CF9
		RTS

; =============== S U B R O U T I N E =======================================
_native_sub100:
		LDY		byte_E0
		LDA		_obj_y_lo_poss,X
		CMP		#$45
		BCS		loc_B6D14
		INC		_scr_vars19,X
		RTS
loc_B6D14:
		CMP		_obj_y_lo_poss,Y
		BCS		loc_B6D61
		LDA		_scr_vars19,X
		BEQ		locret_B6D68
		LDA		_obj_y_deltas,X
		BEQ		locret_B6D68
		BMI		locret_B6D68
		JSR		_obj_to_obj_collision_test
		BCC		locret_B6D68
		LDA		#$8B
		STA		_tmp_ptr44
		LDA		#$20
		STA		_tmp_ptr44+1
		JSR		_native_get_obj_low_nibble_var0D
		CPY		#$00
		BEQ		loc_B6D41
		LDA		#$9D
		STA		_tmp_ptr44
		LDA		#$20
		STA		_tmp_ptr44+1
loc_B6D41:
		TYA
		TAX
		LDA		byte_DE,X
		CMP		#$0A
		BCS		locret_B6D68
		STA		_tmp_ptr0
		INC		byte_DE,X
		SEC
		LDA		_tmp_ptr44
		SBC		_tmp_ptr0
		STA		_tmp_ptr44
		LDA		#<[byte_B6D69]
		STA		_tmp_ptr0
		LDA		#>[byte_B6D69]
		STA		_tmp_ptr0+1
		LDA		#$01
		JSR		_tlm_queue
loc_B6D61:
		LDX		_scr_idx
		LDA		#$00
		STA		_scr_vars19,X
locret_B6D68:
		RTS
byte_B6D69:
		.BYTE	$A0

; =============== S U B R O U T I N E =======================================
_obj_scr_manager:
		LDA		byte_B0
		BEQ		loc_B6D73
		EOR		#$FF
		SEC
		SBC		#$0F
loc_B6D73:
		STA		byte_9E
		LDA		#$00
		STA		_scr_idx
		LDX		#$04
		JSR		_spr_reset_ex
_scripts_manager_loop:
		LDX		_scr_idx
		LDA		_scr_params,X
		AND		#$0F
		BEQ		loc_B6DCF
		LDY		#<[loc_B6DA4-1]
		LDX		#>[loc_B6DA4-1]
		JSR		_switch_param_ret
		.WORD	0
		.WORD	_far_prg4_scr_exec_priority
		.WORD	_far_players_manager
		.WORD	_far_prg4_scr_exec_priority
		.WORD	_far_prg4_scr_exec_priority
		.WORD	_far_prg4_scr_exec_priority
		.WORD	_enemy_manager
		.WORD	_far_prg4_scr_exec_priority
		.WORD	_far_prg4_scr_exec_priority
		.WORD	_far_prg4_scr_exec_priority
		.WORD	_far_prg4_scr_exec_priority
loc_B6DA4:
		LDX		_scr_idx
		LDA		_scr_params,X
		AND		#$0F
		BEQ		loc_B6DCF
		JSR		_obj_out_of_screen_test
		LDA		_obj_flips,X
		AND		#$08
		BNE		loc_B6DBA
		JSR		_obj_global_shift
loc_B6DBA:
		LDA		_scr_params,X
		BMI		loc_B6DCF
		LDA		_obj_flips,X
		AND		#$10
		BEQ		loc_B6DCC
		LDA		_nmi_frames_counter
		LSR
		LSR
		BCC		loc_B6DCF
loc_B6DCC:
		JSR		_obj_spr_lib_insert
loc_B6DCF:
		INC		_scr_idx
		LDA		_scr_idx
		CMP		#$0C
		BCC		_scripts_manager_loop
		RTS

; =============== S U B R O U T I N E =======================================
_far_players_manager:
		LDA		#$02
		JSR		_mmc1_prg_set
		JMP		_players_manager

; =============== S U B R O U T I N E =======================================
_enemy_manager:
		LDX		_scr_idx
		LDA		_obj_hps,X
		BEQ		loc_B6DF9
		LDA		_obj_flips,X
		AND		#$04
		ORA		_obj_x_hi_poss,X
		ORA		_obj_y_hi_poss,X
		BNE		loc_B6DF9
		LDA		_obj_heigts,X
		BNE		loc_B6DFC
loc_B6DF9:
		JMP		_far_prg4_scr_exec_priority
loc_B6DFC:
		LDY		#$0B
loc_B6DFE:
		LDA		_scr_params,Y
		AND		#$0F
		CMP		#$02
		BCC		loc_B6E20
		CMP		#$09
		BEQ		loc_B6E0F
		CMP		#$06
		BCS		loc_B6E20
loc_B6E0F:
		LDA		_obj_flips,Y
		AND		#$04
		BNE		loc_B6E20
		LDA		_scr_vars1C,Y
		BEQ		loc_B6E20
		JSR		_obj_to_obj_collision_test
		BCS		loc_B6E25
loc_B6E20:
		DEY
		BPL		loc_B6DFE
		BMI		_far_prg4_scr_exec_priority
loc_B6E25:
		LDA		_scr_vars1C,Y
		BPL		loc_B6E4A
		LDA		#$01
		STA		_scr_vars1C,Y
		LDA		_stage
		CMP		#$08
		BNE		loc_B6E4A
		LDA		_room_flags
		AND		#$80
		BEQ		loc_B6E4A
		CPX		#$03
		BNE		loc_B6E4A
		LDA		#$00
		STA		_obj_hps,Y
		STA		_scr_vars1C,Y
		JMP		_far_prg4_scr_exec_priority
loc_B6E4A:
		SEC
		LDA		_obj_hps,X
		SBC		_scr_vars1C,Y
		STA		_obj_hps,X
		BCS		loc_B6E5B
		LDA		#$00
		STA		_obj_hps,X
loc_B6E5B:
		LDA		_scr_vars1C,Y
		CMP		#$02
		BEQ		loc_B6E6A
		LDA		#$00
		STA		_obj_hps,Y
		STA		_scr_vars1C,Y
loc_B6E6A:
		JSR		_scr_param_4_set
		LDA		_obj_spr_libs,X
		CMP		#$08
		BNE		loc_B6E79
		LDA		_obj_hps,X
		BNE		_far_prg4_scr_exec_priority
loc_B6E79:
		LDA		_scr_destr_hi_pcs,X
		BPL		_far_prg4_scr_exec_priority
		JSR		_scr_destr_jump
		TYA
		STA		_scr_idxAs,X
		TXA
		STA		_scr_idxAs,Y

; =============== S U B R O U T I N E =======================================
_far_prg4_scr_exec_priority:
		LDA		#$04
		JSR		_mmc1_prg_set
		JMP		_scr_exec_priority

; =============== S U B R O U T I N E =======================================
_scr_destr_jump:
		LDA		_scr_destr_hi_pcs,X
		STA		_scr_hi_pcs,X
		LDA		_scr_destr_lo_pcs,X
		STA		_scr_lo_pcs,X

; =============== S U B R O U T I N E =======================================
_scr_reset_slot:
		LDA		#$00
		STA		_scr_delays,X
		STA		_scr_sps,X
		STA		_scr_loopsA,X
		STA		_scr_loopsB,X
		RTS

; =============== S U B R O U T I N E =======================================
_obj_to_obj_collision_test:
		LDA		_obj_heigts,Y
		BEQ		loc_B6F07
		CLC
		LDA		_obj_widths,X
		ADC		_obj_widths,Y
		STA		_tmp_ptr0
		SEC
		LDA		_obj_x_lo_poss,X
		SBC		_obj_x_lo_poss,Y
		STA		_tmp_ptr2
		LDA		_obj_x_hi_poss,X
		SBC		_obj_x_hi_poss,Y
		BEQ		loc_B6ED8
		CMP		#$FF
		BNE		loc_B6F07
		CLC
		LDA		_tmp_ptr2
		ADC		_tmp_ptr0
		BCC		loc_B6F07
		BCS		loc_B6EE0
loc_B6ED8:
		LDA		_tmp_ptr2
		CMP		_tmp_ptr0
		BEQ		loc_B6EE0
		BCS		loc_B6F07
loc_B6EE0:
		SEC
		LDA		_obj_y_lo_poss,X
		SBC		_obj_y_lo_poss,Y
		STA		_tmp_ptr2
		LDA		_obj_y_hi_poss,X
		SBC		_obj_y_hi_poss,Y
		BEQ		loc_B6EFC
		CMP		#$FF
		BNE		loc_B6F07
		CLC
		LDA		_tmp_ptr2
		ADC		_obj_heigts,Y
		RTS
loc_B6EFC:
		LDA		_tmp_ptr2
		CMP		_obj_heigts,X
		BEQ		loc_B6F05
		BCS		loc_B6F07
loc_B6F05:
		SEC
		RTS
loc_B6F07:
		CLC
		RTS

; =============== S U B R O U T I N E =======================================
_players_animB_sub0129_sub12_A_B_A:
		LDX		_scr_idx
		LDA		_obj_hps,X
		BEQ		loc_B6F86
		LDA		_obj_flips,X
		AND		#$08
		BNE		loc_B6F86
		LDY		#$0B
loc_B6F19:
		CPY		_scr_idx
		BEQ		loc_B6F83
		LDA		_scr_vars21,Y
		CMP		_scr_idx
		BEQ		loc_B6F83
		LDA		_scr_idxBs,X
		AND		#$40
		BEQ		loc_B6F36
		LDA		_scr_idxBs,X
		AND		#$0F
		STA		_tmp_ptr0
		CPY		_tmp_ptr0
		BEQ		loc_B6F83
loc_B6F36:
		CPX		#$02
		BCS		loc_B6F50
		LDA		_scr_vars1C,X
		CMP		#$02
		BNE		loc_B6F50
		LDA		_scr_params,Y
		AND		#$0F
		CMP		#$05
		BEQ		loc_B6F7E
		CMP		#$09
		BEQ		loc_B6F7E
		BNE		loc_B6F83
loc_B6F50:
		LDA		_scr_params,Y
		AND		#$0F
		CMP		#$02
		BCC		loc_B6F83
		BEQ		loc_B6F77
		CMP		#$05
		BEQ		loc_B6F7E
		CMP		#$09
		BEQ		loc_B6F7E
		CMP		#$06
		BNE		loc_B6F83
		LDA		_scr_idxBs,Y
		BMI		loc_B6F83
		LDA		_scr_idxCs,Y
		AND		#$30
		CMP		#$30
		BEQ		loc_B6F7E
		BNE		loc_B6F83
loc_B6F77:
		LDA		_obj_flips,Y
		AND		#$08
		BNE		loc_B6F83
loc_B6F7E:
		JSR		_obj_to_obj_collision_test
		BCS		loc_B6F88
loc_B6F83:
		DEY
		BPL		loc_B6F19
loc_B6F86:
		CLC
		RTS
loc_B6F88:
		LDA		_scr_params,X
		AND		#$0F
		CMP		#$05
		BNE		loc_B6FA9
		CPY		#$02
		BCS		loc_B6FA9
		LDA		_obj_flips,Y
		AND		#$04
		BNE		loc_B6FA9
		LDA		_players_vars0D,Y
		BNE		loc_B6FA9
		LDA		_players_vars07,Y
		ORA		#$08
		STA		_players_vars07,Y
loc_B6FA9:
		SEC
		RTS

; =============== S U B R O U T I N E =======================================
_obj_global_shift:
		SEC
		LDA		_obj_x_lo_poss,X
		SBC		_obj_global_x_shift
		STA		_obj_x_lo_poss,X
		LDA		_obj_x_hi_poss,X
		SBC		_obj_global_x_shift+1
		STA		_obj_x_hi_poss,X
		SEC
		LDA		_obj_y_lo_poss,X
		SBC		_obj_global_y_shift
		STA		_obj_y_lo_poss,X
		LDA		_obj_y_hi_poss,X
		SBC		_obj_global_y_shift+1
		STA		_obj_y_hi_poss,X
		RTS

; =============== S U B R O U T I N E =======================================
_clear_stack:
		LDA		#<[_stack_slot0]
		STA		_tmp_ptr0
		LDA		#>[_stack_slot0]
		STA		_tmp_ptr0+1
		LDY		#$00
loc_B6FD8:
		TYA
		STA		(_tmp_ptr0),Y
		INC		_tmp_ptr0
		BNE		loc_B6FE1
		INC		_tmp_ptr0+1
loc_B6FE1:
		LDA		_tmp_ptr0+1
		CMP		#$04
		BNE		loc_B6FEB
		LDA		_tmp_ptr0
		CMP		#$10
loc_B6FEB:
		BNE		loc_B6FD8
		RTS

; =============== S U B R O U T I N E =======================================
_scr_get_free_slot:
		LDX		#$00
loc_B6FF0:
		LDA		_scr_params,X
		AND		#$0F
		BEQ		loc_B6FFD
		INX
		CPX		#$0C
		BCC		loc_B6FF0
		RTS
loc_B6FFD:
		CLC
loc_B6FFE:
		STX		_scr_cur_slot_idx
		RTS

; =============== S U B R O U T I N E =======================================
_scr_load_param:
		JSR		_get_param2
		LDA		#$00
		STA		_tmp_ptr2
		STA		_tmp_ptr2+1
		STA		_tmp_ptr4
		STA		_tmp_ptr4+1
		STA		byte_6

; =============== S U B R O U T I N E =======================================
_scr_load:
		JSR		_scr_get_free_slot
		BCS		nullsub3

; =============== S U B R O U T I N E =======================================
_scr_load_ex:
		LDA		_tmp_ptr2
		STA		_obj_y_lo_poss,X
		LDA		_tmp_ptr2+1
		STA		_obj_y_hi_poss,X
		LDA		_tmp_ptr4
		STA		_obj_x_lo_poss,X
		LDA		_tmp_ptr4+1
		STA		_obj_x_hi_poss,X
		LDA		byte_6
		STA		_obj_flips,X
		TYA
		ORA		#$80
		STA		_scr_params,X
		STA		_scr_vars21,X
		LDA		_tmp_ptr0
		STA		_scr_lo_pcs,X
		LDA		_tmp_ptr0+1
		STA		_scr_hi_pcs,X
		LDA		#$00
		STA		_scr_delays,X
		STA		_scr_flags,X
		STA		_scr_destr_lo_pcs,X
		STA		_scr_destr_hi_pcs,X
		STA		_scr_loopsA,X
		STA		_scr_loopsB,X
		STA		_scr_sps,X
		STA		_scr_idxBs,X
		STA		_obj_spr_libs,X
		STA		_obj_x_deltas,X
		STA		_obj_y_deltas,X
		STA		_obj_x_accel,X
		STA		_obj_y_accel,X
		STA		_obj_widths,X
		STA		_obj_heigts,X
		STA		_obj_hps,X
		STA		_scr_vars1C,X
		STA		_scr_vars20,X
		LDA		#$40
		STA		_scr_idxCs,X
		LDA		_scr_idx
		STA		_scr_idxAs,X
		CLC

; =============== S U B R O U T I N E =======================================
nullsub3:
		RTS

; =============== S U B R O U T I N E =======================================
_obj_out_of_screen_test:
		LDA		_scr_idxCs,X
		BMI		loc_B70A0
		AND		#$40
		BNE		loc_B708F
		RTS
loc_B708F:
		LDA		_obj_x_hi_poss,X
		ORA		_obj_y_hi_poss,X
		BNE		locret_B709F
		LDA		_scr_idxCs,X
		ORA		#$80
		STA		_scr_idxCs,X
locret_B709F:
		RTS
loc_B70A0:
		LDA		_obj_x_hi_poss,X
		BNE		loc_B70BC
		LDA		_obj_y_hi_poss,X
		BMI		loc_B70B5
		BNE		loc_B70BC
		LDA		_obj_y_lo_poss,X
		CMP		#$ED
		BCC		locret_B70C7
		BCS		loc_B70BC
loc_B70B5:
		LDA		_obj_y_lo_poss,X
		CMP		#$B8
		BCS		locret_B70C7
loc_B70BC:
		LDA		#$80
		STA		_scr_params,X
		STA		_scr_vars21,X
		JSR		_players_animB_sub0129_sub06_A
locret_B70C7:
		RTS

; =============== S U B R O U T I N E =======================================
_spr_reset:
		LDX		#$00

; =============== S U B R O U T I N E =======================================
_spr_reset_ex:
		LDA		#$F0
loc_B70CC:
		STA		_spr_buf,X
		INX
		INX
		INX
		INX
		BNE		loc_B70CC
		LDX		_spr_buf_start
		STX		_spr_buf_pos
		RTS

; =============== S U B R O U T I N E =======================================
_players_animB_sub0129_sub0E_A:
		LDA		_scr_idxCs,X
		ORA		#$20
		STA		_scr_idxCs,X
		LDY		#$01
		JSR		_scr_load_param
		.WORD	_script40
		BCS		locret_B7100
		LDA		_scr_idx
		STA		_scr_idxCs,X
		TAY
		LDA		_scr_idxCs,Y
		AND		#$F0
		STA		_tmp_ptr0
		TXA
		ORA		_tmp_ptr0
		ORA		#$10
		STA		_scr_idxCs,Y
locret_B7100:
		RTS

; =============== S U B R O U T I N E =======================================
_unref_0:
		LDX		_scr_idx
		LDA		_scr_idxBs,X
		TAY
		AND		#$40
		BEQ		locret_B7134
		TYA
		AND		#$BF
		STA		_scr_idxBs,X
		JMP		loc_B7129

; =============== S U B R O U T I N E =======================================
_players_animB_sub0129_sub06_A:
		LDX		_scr_idx
		LDA		_scr_idxCs,X
		AND		#$DF
		STA		_scr_idxCs,X
		TAY
		AND		#$10
		BEQ		locret_B7134
		TYA
		AND		#$EF
		STA		_scr_idxCs,X
loc_B7129:
		AND		#$0F
		TAY
		LDA		#$80
		STA		_scr_params,Y
		STA		_scr_vars21,Y
locret_B7134:
		RTS

; =============== S U B R O U T I N E =======================================
_players_animB_sub0129_E_A_A:
		CLC
		LDA		_obj_widths,Y
		ADC		_obj_widths,X
		STA		_tmp_ptr0
		SEC
		LDA		_obj_x_lo_poss,Y
		ADC		_tmp_ptr0
		STA		_obj_x_lo_poss,X
		LDA		_obj_x_hi_poss,Y
		ADC		#$00
		STA		_obj_x_hi_poss,X
		RTS

; =============== S U B R O U T I N E =======================================
_players_animB_sub0129_F_A_A:
		CLC
		LDA		_obj_widths,Y
		ADC		_obj_widths,X
		STA		_tmp_ptr0
		CLC
		LDA		_obj_x_lo_poss,Y
		SBC		_tmp_ptr0
		STA		_obj_x_lo_poss,X
		LDA		_obj_x_hi_poss,Y
		SBC		#$00
		STA		_obj_x_hi_poss,X
		RTS

; =============== S U B R O U T I N E =======================================
_players_animB_sub0129_sub05_A_B_A:
		CLC
		LDA		_obj_y_lo_poss,Y
		SBC		_obj_heigts,Y
		STA		_obj_y_lo_poss,X
		LDA		_obj_y_hi_poss,Y
		SBC		#$00
		STA		_obj_y_hi_poss,X
		RTS

; =============== S U B R O U T I N E =======================================
_players_animB_sub0129_sub12_A_B_B:
		SEC
		LDA		_obj_y_lo_poss,Y
		ADC		_obj_heigts,X
		STA		_obj_y_lo_poss,X
		LDA		_obj_y_hi_poss,Y
		ADC		#$00
		STA		_obj_y_hi_poss,X
		RTS

; =============== S U B R O U T I N E =======================================
_obj_spr_lib_insert:
		LDA		#$05
		JSR		_mmc1_prg_set
		LDX		_scr_idx
		LDA		_obj_spr_libs,X
		ASL
		TAY
		LDA		_spr_lib_list,Y
		STA		_tmp_ptr2
		LDA		_spr_lib_list+1,Y
		STA		_tmp_ptr2+1
		LDA		_obj_spr_idxs,X
		ASL
		TAY
		LDA		(_tmp_ptr2),Y
		STA		_tmp_ptr0
		INY
		LDA		(_tmp_ptr2),Y
		STA		_tmp_ptr0+1
		LDA		_obj_y_lo_poss,X
		STA		_tmpC
		LDA		_obj_y_hi_poss,X
		STA		_tmpC+1
		LDA		_obj_x_lo_poss,X
		STA		_tmpA
		LDA		_obj_x_hi_poss,X
		STA		_tmpA+1
		LDA		_obj_flips,X
		STA		_tmp_ptr2+1
		BPL		loc_B71DE
		CLC
		LDA		_tmpC
		SBC		_obj_heigts,X
		STA		_tmpC
		LDA		_tmpC+1
		SBC		#$00
		STA		_tmpC+1
loc_B71DE:
		LDX		_spr_buf_pos
		LDY		#$00
loc_B71E2:
		LDA		(_tmp_ptr0),Y
		STA		_tmp_ptr4
		BNE		loc_B71EB
		STX		_spr_buf_pos
		RTS
loc_B71EB:
		LDA		#$00
		STA		byte_7
		STA		byte_9
		INY
		LDA		_tmp_ptr2+1
		AND		#$40
		BEQ		loc_B7201
		SEC
		LDA		#$F8
		SBC		(_tmp_ptr0),Y
		BMI		loc_B7205
		BPL		loc_B7207
loc_B7201:
		LDA		(_tmp_ptr0),Y
		BPL		loc_B7207
loc_B7205:
		DEC		byte_7
loc_B7207:
		STA		byte_6
		CLC
		LDA		byte_6
		ADC		_tmpA
		STA		byte_6
		LDA		byte_7
		ADC		_tmpA+1
		STA		byte_7
		INY
		LDA		_tmp_ptr2+1
		AND		#$80
		BEQ		loc_B7229
		SEC
		LDA		#$00
		SBC		byte_28
		SEC
		SBC		(_tmp_ptr0),Y
		BMI		loc_B722D
		BPL		loc_B722F
loc_B7229:
		LDA		(_tmp_ptr0),Y
		BPL		loc_B722F
loc_B722D:
		DEC		byte_9
loc_B722F:
		STA		byte_8
		CLC
		LDA		byte_8
		ADC		_tmpC
		STA		byte_8
		LDA		byte_9
		ADC		_tmpC+1
		STA		byte_9
		INY
loc_B723F:
		LDA		byte_7
		ORA		byte_9
		BEQ		loc_B7249
		INY
		INY
		BNE		loc_B726E
loc_B7249:
		LDA		(_tmp_ptr0),Y
		STA		_spr_buf+1,X
		INY
		LDA		(_tmp_ptr0),Y
		EOR		_tmp_ptr2+1
		STA		_spr_buf+2,X
		INY
		LDA		byte_6
		STA		_spr_buf+3,X
		LDA		byte_8
		STA		_spr_buf,X
		TXA
loc_B7262:
		CLC
		ADC		_spr_buf_start
		BNE		loc_B726D
		LDX		_spr_buf_start
		BMI		loc_B7262
		LDA		#$FC
loc_B726D:
		TAX
loc_B726E:
		LDA		_tmp_ptr4
		BMI		loc_B7298
		LDA		_tmp_ptr2+1
		AND		#$40
		BNE		loc_B7288
		CLC
		LDA		byte_6
		ADC		#$08
		STA		byte_6
		LDA		byte_7
		ADC		#$00
		STA		byte_7
		JMP		loc_B72BB
loc_B7288:
		SEC
		LDA		byte_6
		SBC		#$08
		STA		byte_6
		LDA		byte_7
		SBC		#$00
		STA		byte_7
		JMP		loc_B72BB
loc_B7298:
		LDA		_tmp_ptr2+1
		AND		#$80
		BNE		loc_B72AE
		CLC
		LDA		byte_8
		ADC		#$08
		STA		byte_8
		LDA		byte_9
		ADC		#$00
		STA		byte_9
		JMP		loc_B72BB
loc_B72AE:
		SEC
		LDA		byte_8
		SBC		#$08
		STA		byte_8
		LDA		byte_9
		SBC		#$00
		STA		byte_9
loc_B72BB:
		DEC		_tmp_ptr4
		LDA		_tmp_ptr4
		AND		#$7F
		BEQ		loc_B72C6
		JMP		loc_B723F
loc_B72C6:
		JMP		loc_B71E2

; =============== S C R I P T ===============================================
_script_unused:
		SUSPEND				$78
		STORE				$00,_main_sub_idx
		SJMP				_script177

; =============== S C R I P T ===============================================
_script_license:
		SUSPEND				$78
		STORE				$01,_main_sub_idx
		SJMP				_script177

; =============== S C R I P T ===============================================
_script_intro:
		OBJ_SET_X_POS		$C0,$00
		OBJ_SET_Y_POS		$C0,$FF
		SRUN				$01,_script170
		NJSR				_native_sub117
		SRUN				$01,_script171
		NJSR				_native_sub117
		SRUN				$01,_script172
		NJSR				_native_sub117
		SJSR				byte_B7360
		OBJ_SET_X_DELTA		$00
		OBJ_SET_Y_DELTA		$20
byte_B72FD:
		SJSR				byte_B7352
		LOOPA				$80,byte_B72FD
		OBJ_SET_X_DELTA		$EA
		OBJ_SET_Y_DELTA		$EA
byte_B7308:
		SJSR				byte_B7352
		LOOPA				$60,byte_B7308
		OBJ_SET_X_DELTA		$20
		OBJ_SET_Y_DELTA		$00
byte_B7313:
		SJSR				byte_B7352
		LOOPA				$40,byte_B7313
		OBJ_SET_X_DELTA		$EA
		OBJ_SET_Y_DELTA		$16
byte_B731E:
		SJSR				byte_B7352
		LOOPA				$30,byte_B731E
		OBJ_SET_X_DELTA		$E0
		OBJ_SET_Y_DELTA		$00
byte_B7329:
		SJSR				byte_B7352
		LOOPA				$80,byte_B7329
		APU_LOAD			$74
		STORE				$00,_ppu_scroll_nt_hor
		OBJ_SET_Y_POS		$68,$00
		OBJ_SET_X_DELTA		$20
byte_B733B:
		SJSR				byte_B7352
		LOOPA				$86,byte_B733B
		OBJ_SET_X_DELTA		$C0
byte_B7344:
		SJSR				byte_B7352
		LOOPA				$10,byte_B7344
		APU_LOAD			$73
		SUSPEND				$3C
		SJMP				byte_B7358
byte_B7352:
		JMP_OBJ_ANIMATE
		TEST_PADS			_PAD0_PRESS,_PAD_ANY,byte_B735F
byte_B7358:
		STORE				$02,_main_sub_idx
		SJMP				_script177
byte_B735F:
		SRET
byte_B7360:
		NJSR				_native_sub134
		NJSR				_native_sub17B
		OBJ_SET_SIZE		$20,$20
		SPR_IDX_SELECT		$00
		PARAM_80_CLEAR
		SRET

; =============== S C R I P T ===============================================
_script170:
		FLIP_40_SET
		SJMP				byte_B7373

; =============== S C R I P T ===============================================
_script172:
		FLIP_40_SET

; =============== S C R I P T ===============================================
_script171:
		FLIP_80_SET
byte_B7373:
		SJSR				byte_B7360
byte_B7376:
		NJMP				_native_sub17A
		SJMP				byte_B7376

; =============== S U B R O U T I N E =======================================
_native_sub17A:
		JSR		_native_get_obj_low_nibble_var1E
		LDA		_obj_x_lo_poss,Y
		STA		_obj_x_lo_poss,X
		LDA		_obj_x_hi_poss,Y
		STA		_obj_x_hi_poss,X
		LDA		_obj_flips,X
		AND		#$80
		BNE		loc_B739F
		LDA		_obj_y_lo_poss,Y
		STA		_obj_y_lo_poss,X
		LDA		_obj_y_hi_poss,Y
		STA		_obj_y_hi_poss,X
		RTS
loc_B739F:
		CLC
		LDA		_obj_y_lo_poss,Y
		ADC		_obj_heigts,Y
		STA		_obj_y_lo_poss,X
		LDA		_obj_y_hi_poss,Y
		ADC		#$00
		STA		_obj_y_hi_poss,X
		RTS

; =============== S C R I P T ===============================================
_script_title:
		OBJ_SET_X_POS		$C0,$00
		OBJ_SET_Y_POS		$6F,$00
		SPR_IDX_SELECT		$01
		PARAM_80_CLEAR
		NJSR				_game_vars_init
byte_B73BE:
		SYNC
		TEST_PADS			_PAD0_PRESS,_PAD_START,byte_B73BE
		APU_LOAD			$32
		NJMP				_title_clear_menu_area
		NJMP				_scr_players_num_menu_draw
		SJSR				byte_B73F1
		SSWITCH				_tmp49
		SCASE				_script_1_player_select
		SCASE				_script_2_players_select
_script_1_player_select:
		NJMP				_scr_players_sel_menu_draw
		SRUN				$01,_script173
		SRUN				$01,_script174
		SJSR				byte_B73F1
		NJSR				_scr_single_player_apply
_script_2_players_select:
		NJSR				_players_vars_init
		STORE				$03,_main_sub_idx
		SJMP				_script177
byte_B73F1:
		NJSR				_menu_init
		DRAW_MENU_CURSOR	_menu_title_player_num
byte_B73F7:
		SYNC
		TEST_PADS			_PAD0_PRESS,_PAD_UP|_PAD_DOWN|_PAD_SELECT,byte_B7405
		APU_LOAD			$31
		NJSR				_title_player_select_pal_toggle
		DRAW_MENU_CURSOR	_menu_title_player_num
byte_B7405:
		TEST_PADS			_PAD0_PRESS,_PAD_START|_PAD_A,byte_B73F7
		APU_LOAD			$32
		SRET

; =============== S C R I P T ===============================================
_script173:
		OBJ_SET_X_POS		$30,$00
		SPR_IDX_SELECT		$07
		SJMP				byte_B741A

; =============== S C R I P T ===============================================
_script174:
		OBJ_SET_X_POS		$B0,$00
		SPR_IDX_SELECT		$08
byte_B741A:
		OBJ_SET_Y_POS		$BA,$00
		PARAM_80_CLEAR
		SJMP				_script_idle

; =============== S U B R O U T I N E =======================================
_title_clear_menu_area:
		LDA		#$07
		STA		_tmp_ptr44
		LDA		#$23
		STA		_tmp_ptr44+1
		LDA		#$92
		JSR		_tlm_queue_param
		.WORD	_tlm_space
		RTS
_tlm_space:
		.BYTE	$40

; =============== S U B R O U T I N E =======================================
_scr_players_num_menu_draw:
		LDA		#$0D
		STA		_tmp_ptr44
		LDA		#$23
		STA		_tmp_ptr44+1
		LDA		#<[_rect_title_player_num_menu]
		LDY		#>[_rect_title_player_num_menu]
		JMP		_far_prg3_rect_draw

; =============== S U B R O U T I N E =======================================
_scr_players_sel_menu_draw:
		LDA		#$0D
		STA		_tmp_ptr44
		LDA		#$23
		STA		_tmp_ptr44+1
		LDA		#<[_rect_title_player_sel]
		LDY		#>[_rect_title_player_sel]
		JMP		_far_prg3_rect_draw

; =============== S U B R O U T I N E =======================================
_scr_single_player_apply:
		LDA		_tmp49
		BEQ		loc_B745C
		LDA		_players_nums
		LDY		_players_nums+1
		STY		_players_nums
		STA		_players_nums+1
loc_B745C:
		LDA		byte_B50F5
		STA		byte_70
		RTS

; =============== S U B R O U T I N E =======================================
_title_player_select_pal_toggle:
		LDY		_tmp49
		STY		_vert_menu_idx
		INY
		TYA
		AND		#$01
		STA		_tmp49
		BNE		loc_B7471
		JMP		_ppu_pal_apply
loc_B7471:
		LDA		#<[_res_pal0]
		LDY		#>[_res_pal0]
		JMP		_far_prg3_pal_patch_load
_menu_title_player_num:
		.BYTE	$01,$02
		.BYTE	$40,$3E
		.WORD	$230B
		.WORD	$234B

; =============== S C R I P T ===============================================
_script_game_over:
		OBJ_SET_X_POS		$80,$00
		OBJ_SET_Y_POS		$60,$00
		OBJ_SET_Y_DELTA		$04
		SPR_IDX_SELECT		$14
		PARAM_80_CLEAR
byte_B748B:
		JMP_OBJ_ANIMATE
		LOOPA				$80,byte_B748B
		SUSPEND				$78
		NJSR				_get_continues
		SBNE				byte_B74DD
		STORE				$08,_main_sub_idx
		SJMP				_script177

; =============== S C R I P T ===============================================
_script_continue:
		SRUN				$01,_script175
		NJSR				_native_sub150
		SRUN				$01,_script176
		NJSR				_native_sub14B
		NJSR				_menu_init
		NJSR				_continues_draw
byte_B74B3:
		VERT_MENU_INPUT		$00,$02
		DRAW_MENU_CURSOR	_menu_data02
		SYNC
		TEST_PADS			_PAD0_PRESS,_PAD_A,byte_B74B3
		APU_LOAD			$32
		NJSR				_native_sub151
		NJSR				_native_sub14C
		SSWITCH				_tmp49
		SCASE				byte_B74CE
		SCASE				byte_B74DD
byte_B74CE:
		NJSR				_continues_decrement
		NJSR				_players_vars_init
		SUSPEND				$78
		STORE				$04,_main_sub_idx
		SJMP				_script177
byte_B74DD:
		SUSPEND				$3C
		STORE				$02,_main_sub_idx
		SJMP				_script177

; =============== S C R I P T ===============================================
_script175:
		OBJ_SET_HP			$00
		OBJ_SET_X_POS		$70,$00
		SJMP				byte_B74F3

; =============== S C R I P T ===============================================
_script176:
		OBJ_SET_HP			$01
		OBJ_SET_X_POS		$90,$00
byte_B74F3:
		NJSR				_native_sub175
		SBNE				_script_idle
		OBJ_SET_Y_POS		$A0,$00
		OBJ_SET_SIZE		$06,$16
		NJSR				_native_idxBs_10_set
		NJSR				_players_animB_sub0129_sub0E_A
		OBJ_SET_FLIP		$60
		SPR_IDX_SELECT		$0D
		PARAM_80_CLEAR
byte_B750A:
		NJMP				_native_idxBs_10_test
		SBEQ				byte_B750A
		NJSR				_players_animB_sub0129_sub06_A
		SSWITCH				_tmp49
		SCASE				byte_B751A
		SCASE				byte_B752A
byte_B751A:
		SJSR				_script_sub_B7547
		SUSPEND				$05
		OBJ_SET_X_DELTA		$20
		OBJ_SET_Y_DELTA		$00
		SJSR				_script_sub_B7533
		SJSR				_script_sub_B7533
		KILL
byte_B752A:
		SPR_IDX_SELECT		$0C
		OBJ_SET_X_DELTA		$F0
		OBJ_SET_Y_DELTA		$DF
		SJMP				byte_68096
_script_sub_B7533:
		SPR_IDX_SELECT		$01
		SJSR				_script_animate10
		SPR_IDX_SELECT		$02
		SJSR				_script_animate10
		SPR_IDX_SELECT		$03
		SJSR				_script_animate10
		SPR_IDX_SELECT		$02
		SJMP				_script_animate10
_script_sub_B7547:
		OBJ_SET_Y_DELTA		$DF
		SPR_IDX_SELECT		$05
byte_B754B:
		NJSR				_native_sub109
		NJMP				_obj_vert_animate
		LOOPA				$15,byte_B754B
_script_sub_B7555:
		SPR_IDX_SELECT		$04
		SUSPEND				$0A
		SPR_IDX_SELECT		$00
		SRET
_menu_data02:
		.BYTE	$01,$02,$40,$3E,$6A,$25,$AA,$25

; =============== S U B R O U T I N E =======================================
_native_sub175:
		LDY		_obj_hps,X
		LDA		byte_70
		AND		byte_B50F5,Y
		BEQ		loc_B7574
		LDA		_players_nums,Y
		STA		_obj_spr_libs,X
loc_B7574:
		JMP		_scr_flags_update

; =============== S U B R O U T I N E =======================================
_game_vars_init:
		LDA		#$03
		STA		_continues
		LDA		byte_B50F5+2
		STA		byte_70
		LDA		#$00
		STA		_extra_stages_complete_flags
		STA		_cutscene_idx
		STA		_stage
		LDX		#$01
		STX		_players_nums
		INX
		STX		_players_nums+1
		LDX		#$01
loc_B7591:
		LDA		#$03
		STA		_players_def_max_hps,X
		LDA		#$00
		STA		_players_rr_lvls,X
		DEX
		BPL		loc_B7591
		RTS

; =============== S U B R O U T I N E =======================================
_players_vars_init:
		LDA		#$00
		STA		_stage_room_idx
		LDX		#$01
loc_B75A3:
		LDA		#$00
		STA		_players_lives,X
		STA		_players_rr_ptss,X
		LDA		_players_def_max_hps,X
		STA		_players_max_hps,X
		LDA		byte_70
		AND		byte_B50F5,X
		BEQ		loc_B75B8
		LDA		#$03
		STA		_players_lives,X
loc_B75B8:
		DEX
		BPL		loc_B75A3
		RTS

; =============== S U B R O U T I N E =======================================
_continues_decrement:
		DEC		_continues

; =============== S U B R O U T I N E =======================================
_continues_draw:
		LDA		#$F8
		STA		_tmp_ptr44
		LDA		#$26
		STA		_tmp_ptr44+1
		LDA		_continues
		JMP		_printf_num9

; =============== S U B R O U T I N E =======================================
_get_continues:
		LDA		_continues
		JMP		_scr_flags_update

; =============== S C R I P T ===============================================
_script_stage_complete:
		SJSR				byte_B75FB
		NJSR				_get_apu_achnls_active_flags
		SBEQ				_script_stage_complete
byte_B75D9:
		SJSR				byte_B75FB
		NJSR				_native_sub101
		SBEQ				byte_B75D9
byte_B75E2:
		NJMP				_stage_complete_info_insert
		NJSR				_native_sub102
		TEST_PADS			_PAD0_PRESS,_PAD_ANY,byte_B75E2
		STORE				$06,_main_sub_idx
		SRUN				$01,_script177
byte_B75F5:
		NJMP				_stage_complete_info_insert
		SJMP				byte_B75F5
byte_B75FB:
		NJMP				_stage_complete_info_insert
		LOOPB				$04,byte_B75FB
		SRET

; =============== S U B R O U T I N E =======================================
_get_apu_achnls_active_flags:
		LDA		_apu_active_chnls_flags
		AND		#$0F
		JMP		_scr_flags_update

; =============== S U B R O U T I N E =======================================
_native_sub101:
		LDX		#$01
loc_B760C:
		LDA		_players_rr_ptss,X
		BEQ		loc_B7641
		DEC		_players_rr_ptss,X
		INC		_hor_menu_pos,X
		LDA		#$38
		JSR		_apu_se_req
		LDA		_hor_menu_pos,X
		CMP		byte_E0
		BNE		loc_B7641
		INC		_players_rr_lvls,X
		LDA		#$20
		JSR		_apu_mus_req
		LDA		_players_def_max_hps,X
		CMP		#$05
		BCS		loc_B7641
		LDA		_players_rr_lvls,X
		CMP		#$03
		BEQ		loc_B763A
		CMP		#$05
		BEQ		loc_B763A
		CMP		#$07
		BNE		loc_B7641
loc_B763A:
		INC		_players_def_max_hps,X
		LDA		#$20
		JSR		_apu_mus_req
loc_B7641:
		DEX
		BPL		loc_B760C
		LDA		_players_rr_ptss
		ORA		_players_rr_ptss+1
		JMP		_scr_flags_update

; =============== S U B R O U T I N E =======================================
_native_sub102:
		LDA		#$00
		STA		_tmp_ptr0
		STA		_tmp_ptr0+1
		LDX		#$02
loc_B7653:
		LDA		_players_lives,X
		BEQ		loc_B7663
		LDA		_tmp_ptr0
		ORA		_pads,X
		STA		_tmp_ptr0
		LDA		_tmp_ptr0+1
		ORA		_pads+4,X
		STA		_tmp_ptr0+1
loc_B7663:
		DEX
		BPL		loc_B7653
		LDA		_tmp_ptr0
		STA		_pads
		LDA		_tmp_ptr0+1
		STA		_pads+4
		RTS

; =============== S C R I P T ===============================================
_script16D:
		FLIP_40_SET
		PARAM_80_CLEAR
		OBJ_SET_X_POS		$38,$00
		OBJ_SET_Y_POS		$A0,$00
		SPR_LIB_SELECT		$01
		SPR_IDX_SELECT		$1B
		SJSR				byte_6B6C2
		SJSR				byte_6B73A
		SJSR				byte_6B73A

; =============== S C R I P T ===============================================
_script16E:
		FLIP_40_SET
		PARAM_80_CLEAR
		OBJ_SET_X_POS		$28,$00
		OBJ_SET_Y_POS		$90,$00
		SPR_LIB_SELECT		$02
		SPR_IDX_SELECT		$1B
		SJSR				byte_6B6C2
		SJSR				byte_6B75D
		SJSR				byte_6B73A
		SJSR				byte_6B750
		SJSR				byte_6B73A

; =============== S C R I P T ===============================================
_script16F:
		FLIP_40_SET
		PARAM_80_CLEAR
		OBJ_SET_X_POS		$70,$00
		OBJ_SET_Y_POS		$C0,$00
		SPR_IDX_SELECT		$1C
		TARGET_DIR_SET		$00
		SJSR				byte_6B7B7
		SJSR				byte_6B7D1
		SJSR				byte_6B7B7

; =============== S C R I P T ===============================================
_script16C:
		OBJ_SET_X_POS		$A0,$00
		OBJ_SET_Y_POS		$70,$00
		PARAM_80_CLEAR
		OBJ_SET_X_DELTA		$F8
byte_B76BD:
		SPR_IDX_SELECT		$3D
		SJSR				_script_animate10
		SPR_IDX_SELECT		$3E
		SJSR				_script_animate10
		LOOPA				$08,byte_B76BD
		NJSR				_native_sub110
		SJMP				byte_B76BD

; =============== S C R I P T ===============================================
_scr_cutscene0A:
		OBJ_SET_Y_POS		$C0,$00
		SRUN				$01,_script178
		TARGET_DIR_SET		$00
		SRUN				$01,_script179
		NJSR				_native_sub05E
		TARGET_DIR_SET		$01
		SRUN				$01,_script17A
		NJMP				_native_sub05E
		TARGET_DIR_SET		$00
		SJSR				byte_6B6CC
		MSG_DISPLAY			_msg3F,$56
		SJSR				byte_6B6CC
		MSG_DISPLAY			_msg40,$5D
		MSG_WAIT
		TARGET_DIR_SET		$01
		MSG_DISPLAY			_msg41,$57
		SJSR				byte_6B6CC
		TARGET_DIR_SET		$00
		MSG_DISPLAY			_msg42,$56
		SJSR				byte_6B6CC
		MSG_DISPLAY			_msg43,$5D
		MSG_WAIT
		TARGET_DIR_SET		$01
		MSG_DISPLAY			_msg44,$57
		SJSR				byte_6B6CC
		TARGET_DIR_SET		$00
		MSG_DISPLAY			_msg45,$56
		SJSR				byte_6B6CC
		SJMP				byte_6B6A6

; =============== S C R I P T ===============================================
_script179:
		SPR_LIB_SELECT		$01
		SPR_IDX_SELECT		$16
		OBJ_SET_X_POS		$70,$00
		FLIP_40_SET
		PARAM_80_CLEAR
		SRUN				$01,_script17B
		NJSR				_native_sub150
		SUSPEND				$B4
		NJSR				_native_sub151
		SPR_IDX_SELECT		$09
		SUSPEND				$04
		SPR_IDX_SELECT		$0A
		SUSPEND				$10
		SPR_IDX_SELECT		$00
		SUSPEND				$3C
		SJSR				byte_6B6C2
		SJSR				byte_6B73A
		SJSR				byte_6B744
		SJSR				byte_6B744
		SJMP				_script_idle

; =============== S C R I P T ===============================================
_script17A:
		SPR_LIB_SELECT		$02
		SPR_IDX_SELECT		$00
		OBJ_SET_X_POS		$50,$00
		FLIP_40_SET
		PARAM_80_CLEAR
		SJSR				byte_6B6C2
		SJSR				byte_6B73A
		SJSR				byte_6B73A
		SJMP				_script_idle

; =============== S C R I P T ===============================================
_script178:
		SPR_IDX_SELECT		$42
		OBJ_SET_X_POS		$88,$00
		PARAM_80_CLEAR
		SJMP				_script_idle

; =============== S C R I P T ===============================================
_script17B:
		OBJ_MOVE_Y_POS		$EA
		SPR_IDX_SELECT		$43
		PARAM_80_CLEAR
		SJSR				byte_6B6C2
		OBJ_SET_X_DELTA		$0D
		OBJ_SET_Y_DELTA		$E8
byte_B7781:
		JMP_OBJ_ANIMATE
		OBJ_INC_Y_DELTA
		OBJ_INC_Y_DELTA
		LOOPA				$1E,byte_B7781
		SJMP				_script_idle

; =============== S C R I P T ===============================================
_scr_cutscene0B:
		NJSR				_native_sub174
		STORE				$00,_tmp49
		NJSR				_extra_stage_name0_load
		SSWITCH				_tmp_ptrE+1
		SCASE				byte_B77A0
		SCASE				byte_B7828
		SCASE				byte_B7899
		SCASE				byte_B78C8
byte_B77A0:
		TARGET_DIR_SET		$00
		SRUN				$01,_script17C
		NJSR				_native_sub05E
		TARGET_DIR_SET		$01
		SRUN				$01,_script17D
		NJSR				_native_sub05E
		TARGET_DIR_SET		$02
		SRUN				$01,_script17E
		NJMP				_native_sub05E
		SUSPEND				$3C
		MSG_DISPLAY			_msg46,$5D
		MSG_WAIT
		TARGET_DIR_SET		$01
		MSG_DISPLAY			_msg47,$57
		SJSR				byte_6B6CC
		MSG_DISPLAY			_msg48,$5D
		MSG_WAIT
		MSG_DISPLAY			_msg49,$57
		SJSR				byte_6B6CC
		TARGET_DIR_SET		$02
byte_B77D9:
		MSG_DISPLAY			_msg4A,$59
		SJSR				byte_6B6CC
		SJSR				byte_B780A
		MSG_DISPLAY			_msg4B,$59
		SJSR				byte_6B6CC
		SJSR				byte_6BC7C
		SSWITCH				_hor_menu_pos
		SCASE				byte_B77FE
		SCASE				byte_B77F4
byte_B77F4:
		STORE				$01,byte_E1
		NJMP				_native_sub05F
		SJMP				byte_B77D9
byte_B77FE:
		TARGET_DIR_SET		$00
		MSG_DISPLAY			_msg4C,$56
		SJSR				byte_6B6CC
		SJMP				byte_6B69F
byte_B780A:
		NJSR				_menu_init
		DRAW_MENU_CURSOR	_menu_data03
byte_B7810:
		SYNC
		NJSR				_native_sub102
		NJSR				_native_sub176
		SBCS				byte_B781D
		DRAW_MENU_CURSOR	_menu_data03
byte_B781D:
		TEST_PADS			_PAD0_PRESS,_PAD_A,byte_B7810
		APU_LOAD			$32
		NJSR				_extra_stage_name0_load
		SRET
byte_B7828:
		SRUN				$01,_script17F
		TARGET_DIR_SET		$01
		SRUN				$01,_script180
		NJSR				_native_sub05E
		TARGET_DIR_SET		$03
		SRUN				$01,_script181
		NJMP				_native_sub05E
		SUSPEND				$3C
byte_B7840:
		STORE				$00,_tmp49
		NJSR				_extra_stage_name0_load
		NJSR				_extra_stage_name1_load
		MSG_DISPLAY			_msg4D,$58
		SJSR				byte_6B6CC
		SJSR				byte_B787B
		MSG_DISPLAY			_msg1B,$58
		SJSR				byte_6B6CC
		SJSR				byte_6BC7C
		SSWITCH				_hor_menu_pos
		SCASE				byte_B786F
		SCASE				byte_B7865
byte_B7865:
		STORE				$01,byte_E1
		NJMP				_native_sub05F
		SJMP				byte_B7840
byte_B786F:
		TARGET_DIR_SET		$01
		MSG_DISPLAY			_msg4E,$57
		SJSR				byte_6B6CC
		SJMP				byte_6B69F
byte_B787B:
		NJSR				_menu_init
		DRAW_MENU_CURSOR	_menu_data04
byte_B7881:
		SYNC
		NJSR				_native_sub102
		NJSR				_native_sub177
		SBCS				byte_B788E
		DRAW_MENU_CURSOR	_menu_data04
byte_B788E:
		TEST_PADS			_PAD0_PRESS,_PAD_A,byte_B7881
		APU_LOAD			$32
		NJSR				_extra_stage_name0_load
		SRET
byte_B7899:
		SRUN				$01,_script154
		SRUN				$01,_script182
		TARGET_DIR_SET		$00
		SRUN				$01,_script183
		NJSR				_native_sub05E
		TARGET_DIR_SET		$02
		SRUN				$01,_script184
		NJMP				_native_sub05E
		SUSPEND				$3C
		MSG_DISPLAY			_msg4F,$59
		SJSR				byte_6B6CC
		TARGET_DIR_SET		$00
		MSG_DISPLAY			_msg50,$56
		SJSR				byte_6B6CC
		SJMP				byte_6B69F
byte_B78C8:
		NJSR				_native_sub178

; =============== S U B R O U T I N E =======================================
_native_sub178:
		LDA		#$08
		STA		_stage
		LDA		#$0C
		STA		_cutscene_idx
		JMP		_MAIN_START

; =============== S U B R O U T I N E =======================================
_native_sub174:
		LDX		#$00
		LDY		#$00
		LDA		#$03
		STA		_tmp_ptrE+1
loc_B78DE:
		LDA		_extra_stages_complete_flags
		AND		_bitmasks_0,X
		BNE		loc_B78ED
		CLC
		TXA
		STA		byte_436,Y
		INY
		DEC		_tmp_ptrE+1
loc_B78ED:
		INX
		CPX		#$03
		BCC		loc_B78DE
		RTS

; =============== S U B R O U T I N E =======================================
_native_sub176:
		LDA		#$03
		LDX		#$00
		JSR		_get_vert_menu_input
		JMP		_scr_flags_update

_menu_data03:
		.BYTE	$01,$03
		.BYTE	$40,$3E
		.WORD	$2463
		.WORD	$24A3
		.WORD	$24E3
_menu_data04:
		.BYTE	$01,$02
		.BYTE	$40,$3E
		.WORD	$2463
		.WORD	$24A3

; =============== S U B R O U T I N E =======================================
_native_sub177:
		LDA		#$02
		LDX		#$00
		JSR		_get_vert_menu_input
		JMP		_scr_flags_update

; =============== S U B R O U T I N E =======================================
_extra_stage_name0_load:
		LDY		_tmp49
		CLC
		LDA		byte_436,Y
		ADC		#$05
		STA		_stage
		CLC
		LDA		byte_436,Y
		ADC		#$82
		LDX		#$00
		JMP		_extra_stage_name_load

; =============== S U B R O U T I N E =======================================
_extra_stage_name1_load:
		CLC
		LDA		byte_437
		ADC		#$82
		LDX		#$10

; =============== S U B R O U T I N E =======================================
_extra_stage_name_load:
		ASL
		TAY
		LDA		_cur_prg_bank
		PHA
		LDA		#$02
		JSR		_mmc1_prg_set
		LDA		_dictionary,Y
		STA		_tmp_ptr0
		LDA		_dictionary+1,Y
		STA		_tmp_ptr0+1
		LDY		#$00
loc_B794C:
		LDA		(_tmp_ptr0),Y
		STA		_dict80_ptr,X
		INX
		INY
		CMP		#$FE
		BCC		loc_B794C
		JMP		_mmc1_prg_restore

; =============== S C R I P T ===============================================
_script17C:
		SJSR				byte_B79E1
		SJSR				byte_6B6C2
		SJSR				byte_6B744

; =============== S C R I P T ===============================================
_script17D:
		SJSR				byte_B79ED
		SJSR				byte_6B6C2
		SJSR				byte_6B73A
		SJSR				byte_6B73A

; =============== S C R I P T ===============================================
_script17E:
		SJSR				byte_B79FA
		SJSR				byte_6B7B7
byte_B7975:
		SJSR				byte_6B7D1
		SJSR				byte_6B7D1
		SJMP				byte_B7975

; =============== S C R I P T ===============================================
_script17F:
		SJSR				byte_B79E1
		SJMP				_script_idle

; =============== S C R I P T ===============================================
_script180:
		SJSR				byte_B79ED
		SJSR				byte_6B6C2
		SJSR				byte_6B73A

; =============== S C R I P T ===============================================
_script181:
		SPR_IDX_SELECT		$28
		TARGET_DIR_SET		$09
		OBJ_SET_X_POS		$18,$00
		OBJ_SET_Y_POS		$A0,$00
		FLIP_40_SET
		PARAM_80_CLEAR
		SRUN				$01,_script185
		SJSR				byte_6B773
byte_B79A0:
		SJSR				byte_6B797
		SJSR				byte_6B797
		SJMP				byte_B79A0

; =============== S C R I P T ===============================================
_script185:
		OBJ_MOVE_X_POS		$0B
		OBJ_MOVE_Y_POS		$F0
byte_B79AD:
		SPR_IDX_SELECT		$3F
		PARAM_80_CLEAR
		SJMP				_script_idle

; =============== S C R I P T ===============================================
_script183:
		SJSR				byte_B79E1
		SJSR				byte_6B6C2
		SJSR				byte_6B744

; =============== S C R I P T ===============================================
_script182:
		SJSR				byte_B79ED
		SJSR				byte_6B6C2

; =============== S C R I P T ===============================================
_script184:
		SJSR				byte_B79FA
		SRUN				$01,_script186
		TARGET_DIR_SET		$06
		SJSR				byte_6B7B7
		OBJ_SET_HP			$06
		VAR_1C_SET			$09
		SJSR				byte_6B7C4
		TARGET_DIR_SET		$06
		SJSR				byte_6B7B7

; =============== S C R I P T ===============================================
_script186:
		OBJ_MOVE_X_POS		$14
		OBJ_MOVE_Y_POS		$E5
		SJMP				byte_B79AD

byte_B79E1:
		SPR_LIB_SELECT		$01
		SPR_IDX_SELECT		$1B
		OBJ_SET_X_POS		$80,$00
		OBJ_SET_Y_POS		$D0,$00
		PARAM_80_CLEAR
		SRET
byte_B79ED:
		SPR_LIB_SELECT		$02
		SPR_IDX_SELECT		$1B
		OBJ_SET_X_POS		$38,$00
		OBJ_SET_Y_POS		$C0,$00
		FLIP_40_SET
		PARAM_80_CLEAR
		SRET
byte_B79FA:
		SPR_IDX_SELECT		$1C
		TARGET_DIR_SET		$00
		OBJ_SET_X_POS		$18,$00
		OBJ_SET_Y_POS		$A0,$00
		FLIP_40_SET
		PARAM_80_CLEAR
		SRET

; =============== S C R I P T ===============================================
_scr_cutscene0C:
		SRUN				$01,_script154
		SRUN				$01,_script187
		SRUN				$01,_script188
		TARGET_DIR_SET		$01
		SRUN				$01,_script189
		NJSR				_native_sub05E
		TARGET_DIR_SET		$03
		SRUN				$01,_script18A
		NJSR				_native_sub05E
		TARGET_DIR_SET		$04
		SRUN				$01,_script18B
		NJSR				_native_sub05E
		TARGET_DIR_SET		$00
		SRUN				$01,_script18C
		NJMP				_native_sub05E
		SUSPEND				$3C
		MSG_DISPLAY			_msg51,$56
		SJSR				byte_6B6CC
		TARGET_DIR_SET		$03
		MSG_DISPLAY			_msg52,$58
		SJSR				byte_6B6CC
		TARGET_DIR_SET		$04
		NJMP				_native_sub05F
		MSG_DISPLAY			_msg53,$5A
		MSG_WAIT
		SJSR				byte_6B6CC
		TARGET_DIR_SET		$03
		NJSR				_native_sub05F
		TARGET_DIR_SET		$04
		SJSR				byte_6B6CC
		TARGET_DIR_SET		$00
		MSG_DISPLAY			_msg54,$56
		SJSR				byte_6B6CC
		APU_LOAD			$4F
		NJSR				_native_sub103
		SJSR				byte_6BECE
		SUSPEND				$10
		SJMP				byte_6B6B0

; =============== S C R I P T ===============================================
_script18C:
		SPR_LIB_SELECT		$01
		SPR_IDX_SELECT		$1B
		OBJ_SET_X_POS		$70,$00
		OBJ_SET_Y_POS		$C0,$00
		FLIP_40_SET
		PARAM_80_CLEAR
		SJSR				byte_6B6C2
		FLIP_40_CLEAR
		SJSR				byte_6B744
		SJSR				byte_6B73A
		FLIP_40_SET
		SJMP				byte_B7A9F

; =============== S C R I P T ===============================================
_script189:
		SPR_LIB_SELECT		$02
		SPR_IDX_SELECT		$1B
		OBJ_SET_X_POS		$58,$00
		OBJ_SET_Y_POS		$C0,$00
		FLIP_40_SET
		PARAM_80_CLEAR
		SJSR				byte_6B6C2
byte_B7A9F:
		OBJ_SET_X_DELTA		$10
byte_B7AA1:
		SJSR				_script_sub_B7533
		SJMP				byte_B7AA1

; =============== S C R I P T ===============================================
_script18A:
		SPR_IDX_SELECT		$28
		TARGET_DIR_SET		$09
		OBJ_SET_X_POS		$10,$00
		OBJ_SET_Y_POS		$A0,$00
		FLIP_40_SET
		PARAM_80_CLEAR
		SRUN				$01,_script18D
		NJSR				_native_sub117
		SJSR				byte_6B773
		SJSR				byte_6B797
		NJSR				_players_animB_sub0129_sub06_A
		TARGET_DIR_SET		$00
		SJSR				byte_6B773

; =============== S C R I P T ===============================================
_script18B:
		OBJ_SET_X_POS		$80,$00
		OBJ_SET_Y_POS		$84,$00
		FLIP_40_SET
		PARAM_80_CLEAR
		SJSR				byte_6B7F1
		FLIP_40_CLEAR
		SJSR				byte_6B7F1
		OBJ_SET_X_DELTA		$F0
byte_B7AD9:
		SJSR				byte_6B825
		LOOPA				$10,byte_B7AD9
		SJSR				byte_6B7F1
		FLIP_40_SET
		OBJ_SET_X_DELTA		$10
byte_B7AE6:
		SJSR				byte_6B825
		LOOPA				$06,byte_B7AE6
		SRUN				$01,_script18E
		SJSR				byte_6B7F1

; =============== S C R I P T ===============================================
_script187:
		OBJ_SET_X_POS		$28,$00
		SJMP				byte_B7B0E

; =============== S C R I P T ===============================================
_script188:
		OBJ_SET_X_POS		$38,$00
		SJMP				byte_B7B0E

; =============== S C R I P T ===============================================
_script18D:
		OBJ_MOVE_X_POS		$0B
		OBJ_MOVE_Y_POS		$F0
		SPR_IDX_SELECT		$3F
		PARAM_80_CLEAR
		SJMP				_script_idle

; =============== S C R I P T ===============================================
_script18E:
		FLIP_40_CLEAR
		OBJ_SET_X_POS		$48,$00
byte_B7B0E:
		OBJ_SET_Y_POS		$64,$00
		SPR_IDX_SELECT		$40
		PARAM_80_CLEAR
		SJMP				_script_idle

; =============== S U B R O U T I N E =======================================
_native_sub103:
		LDA		#$91
		STA		_tmp_ptr44
		LDA		#$22
		STA		_tmp_ptr44+1
		LDA		#<[_rect222]
		LDY		#>[_rect222]
		JMP		_far_prg3_rect_draw

; =============== S C R I P T ===============================================
_scr_cutscene0D:
		SRUN				$01,_script154
		TARGET_DIR_SET		$00
		SRUN				$01,_script18F
		NJSR				_native_sub05E
		TARGET_DIR_SET		$01
		SRUN				$01,_script190
		NJSR				_native_sub05E
		TARGET_DIR_SET		$03
		SRUN				$01,_script191
		NJSR				_native_sub05E
		TARGET_DIR_SET		$04
		SRUN				$01,_script192
		NJMP				_native_sub05E
		SUSPEND				$3C
		TARGET_DIR_SET		$00
		MSG_DISPLAY			_msg55,$56
		SJSR				byte_6B6CC
		TARGET_DIR_SET		$01
		MSG_DISPLAY			_msg56,$57
		SJSR				byte_6B6CC
		TARGET_DIR_SET		$03
		MSG_DISPLAY			_msg57,$58
		SJSR				byte_6B6CC
		TARGET_DIR_SET		$00
		MSG_DISPLAY			_msg58,$56
		SJSR				byte_6B6CC
		MSG_DISPLAY			_msg59,$56
		NJSR				_native_sub05F
		TARGET_DIR_SET		$01
		NJSR				_native_sub05F
		TARGET_DIR_SET		$03
		NJMP				_native_sub05F
		SJSR				byte_6B6FC
		SJMP				byte_6B69F

; =============== S C R I P T ===============================================
_script18F:
		SPR_LIB_SELECT		$01
		SPR_IDX_SELECT		$1B
		OBJ_SET_X_POS		$70,$00
		OBJ_SET_Y_POS		$C0,$00
		FLIP_40_SET
		PARAM_80_CLEAR
		SJSR				byte_6B6C2
		SJSR				byte_6B73A
		SJMP				byte_B7BAF

; =============== S C R I P T ===============================================
_script190:
		SPR_LIB_SELECT		$02
		SPR_IDX_SELECT		$1B
		OBJ_SET_X_POS		$58,$00
		OBJ_SET_Y_POS		$C0,$00
		FLIP_40_SET
		PARAM_80_CLEAR
		SJSR				byte_6B6C2
byte_B7BAF:
		SJSR				byte_6B744
		SJSR				byte_6B744

; =============== S C R I P T ===============================================
_script191:
		SPR_IDX_SELECT		$28
		TARGET_DIR_SET		$00
		OBJ_SET_X_POS		$10,$00
		OBJ_SET_Y_POS		$A0,$00
		FLIP_40_SET
		PARAM_80_CLEAR
		SJSR				byte_6B773
		SJSR				byte_6B797
		SJSR				byte_6B797

; =============== S C R I P T ===============================================
_script192:
		OBJ_SET_X_POS		$60,$00
		OBJ_SET_Y_POS		$68,$00
		FLIP_40_SET
		PARAM_80_CLEAR
byte_B7BD2:
		SJSR				byte_6B7F1
		SJMP				byte_B7BD2

; =============== S C R I P T ===============================================
_scr_cutscene0E:
		SRUN				$01,_script154
		TARGET_DIR_SET		$05
		SRUN				$01,_script193
		NJSR				_native_sub05E
		TARGET_DIR_SET		$01
		SRUN				$01,_script194
		NJSR				_native_sub05E
		TARGET_DIR_SET		$00
		SRUN				$01,_script195
		NJMP				_native_sub05E
		SUSPEND				$60
		MSG_DISPLAY			_msg5A,$5D
		MSG_WAIT
		MSG_DISPLAY			_msg5B,$56
		SJSR				byte_6B6CC
		TARGET_DIR_SET		$01
		MSG_DISPLAY			_msg5C,$57
		SJSR				byte_6B6CC
		MSG_DISPLAY			_msg5D,$5D
		MSG_WAIT
		MSG_DISPLAY			_msg5E,$57
		SJSR				byte_6B6CC
		TARGET_DIR_SET		$00
		MSG_DISPLAY			_msg5F,$56
		SJSR				byte_6B6CC
		TARGET_DIR_SET		$05
		NJMP				_native_sub05F
		SJMP				byte_6B69F

; =============== S C R I P T ===============================================
_script193:
		NJSR				_native_idxBs_10_set
byte_B7C2E:
		STORE				$00,_ppu_scroll_nt_hor+1
		SYNC
		STORE				$01,_ppu_scroll_nt_hor+1
		SYNC
		NJSR				_native_idxBs_10_test
		SBEQ				byte_B7C2E
		KILL

; =============== S C R I P T ===============================================
_script195:
		SPR_LIB_SELECT		$01
		SPR_IDX_SELECT		$1B
		OBJ_SET_X_POS		$58,$00
		OBJ_SET_Y_POS		$C0,$00
		FLIP_40_SET
		PARAM_80_CLEAR
		SJSR				byte_6B6C2
		SJSR				byte_6B73A
		SJSR				byte_6B744

; =============== S C R I P T ===============================================
_script194:
		SPR_LIB_SELECT		$02
		SPR_IDX_SELECT		$1B
		OBJ_SET_X_POS		$40,$00
		OBJ_SET_Y_POS		$C0,$00
		FLIP_40_SET
		PARAM_80_CLEAR
		SJSR				byte_6B6C2
		SJSR				byte_6B73A
		SJSR				byte_6B744

; =============== S C R I P T ===============================================
_scr_cutscene0F:
		SRUN				$01,_script196
		TARGET_DIR_SET		$02
		SRUN				$01,_script197
		NJSR				_native_sub05E
		TARGET_DIR_SET		$00
		SRUN				$01,_script198
		NJMP				_native_sub05E
		SUSPEND				$3C
		TARGET_DIR_SET		$02
		MSG_DISPLAY			_msg60,$59
		SJSR				byte_6B6CC
		TARGET_DIR_SET		$00
		MSG_DISPLAY			_msg61,$56
		SJSR				byte_6B6CC
		TARGET_DIR_SET		$02
		MSG_DISPLAY			_msg62,$59
		SJSR				byte_6B6CC
		SJMP				byte_6B6B0

; =============== S C R I P T ===============================================
_script198:
		SPR_LIB_SELECT		$01
		SPR_IDX_SELECT		$1B
		OBJ_SET_X_POS		$B0,$00
		OBJ_SET_Y_POS		$C0,$00
		PARAM_80_CLEAR
		SJSR				byte_6B6C2
		SJSR				byte_6B73A

; =============== S C R I P T ===============================================
_script196:
		SPR_LIB_SELECT		$02
		SPR_IDX_SELECT		$1B
		OBJ_SET_X_POS		$D0,$00
		OBJ_SET_Y_POS		$90,$00
		PARAM_80_CLEAR
		SJMP				_script_idle

; =============== S C R I P T ===============================================
_script197:
		SPR_IDX_SELECT		$1C
		TARGET_DIR_SET		$00
		OBJ_SET_X_POS		$70,$00
		OBJ_SET_Y_POS		$C0,$00
		FLIP_40_SET
		PARAM_80_CLEAR
		SJSR				byte_6B7B7
		SJSR				byte_6B7D1
		SJSR				byte_6B7D1

; =============== S C R I P T ===============================================
_scr_cutscene10:
		SRUN				$01,_script199
		SRUN				$01,_script19A
		SUSPEND				$B4
		SUSPEND				$B4
		SJMP				byte_6B6A6

; =============== S C R I P T ===============================================
_script19A:
		SPR_LIB_SELECT		$01
		OBJ_SET_X_POS		$E0,$FF
		SJMP				byte_B7CF2

; =============== S C R I P T ===============================================
_script199:
		SPR_LIB_SELECT		$02
		OBJ_SET_X_POS		$C8,$FF
		SJMP				byte_B7CF2
byte_B7CF2:
		OBJ_SET_Y_POS		$C0,$00
		FLIP_40_SET
		PARAM_80_CLEAR
		OBJ_SET_X_DELTA		$10
byte_B7CF9:
		SJSR				_script_sub_B7533
		SJMP				byte_B7CF9

; =============== S C R I P T ===============================================
_scr_cutscene11:
		TARGET_DIR_SET		$00
		SRUN				$01,_script19B
		NJSR				_native_sub05E
		TARGET_DIR_SET		$01
		SRUN				$01,_script19C
		NJSR				_native_sub05E
		TARGET_DIR_SET		$02
		SRUN				$01,_script19D
		NJSR				_native_sub05E
		TARGET_DIR_SET		$03
		SRUN				$01,_script19E
		NJMP				_native_sub05E
		SUSPEND				$3C
		TARGET_DIR_SET		$02
		MSG_DISPLAY			_msg63,$59
		SJSR				byte_6B6CC
		TARGET_DIR_SET		$00
		NJSR				_native_sub05F
		TARGET_DIR_SET		$01
		SJSR				byte_6B6CC
		TARGET_DIR_SET		$03
		MSG_DISPLAY			_msg64,$58
		SJSR				byte_6B6CC
		TARGET_DIR_SET		$00
		MSG_DISPLAY			_msg65,$56
		SJSR				byte_6B6CC
		TARGET_DIR_SET		$01
		MSG_DISPLAY			_msg66,$57
		SJSR				byte_6B6CC
		TARGET_DIR_SET		$03
		MSG_DISPLAY			_msg67,$58
		SJSR				byte_6B6CC
		TARGET_DIR_SET		$02
		MSG_DISPLAY			_msg68,$59
		SJSR				byte_6B6CC
		TARGET_DIR_SET		$01
		MSG_DISPLAY			_msg69,$57
		SJSR				byte_6B6CC
		TARGET_DIR_SET		$03
		MSG_DISPLAY			_msg6A,$58
		SJSR				byte_6B6CC
		TARGET_DIR_SET		$00
		MSG_DISPLAY			_msg6B,$56
		SJSR				byte_6B6CC
		MSG_DISPLAY			_msg6C,$56
		TARGET_DIR_SET		$02
		NJMP				_native_sub05F
		TARGET_DIR_SET		$03
		NJMP				_native_sub05F
		SJSR				byte_6BECE
		SJSR				byte_6B6CC
		SUSPEND				$0A
		STORE				$18,_chr0_bank_req
		STORE				$00,_ppu_scroll_nt_hor
		STORE				$F0,_spr_buf
		SUSPEND				$3C
		SRUN				$01,_script15A
		SUSPEND				$F0
		SUSPEND				$F0
		SJMP				byte_6B6A6

; =============== S C R I P T ===============================================
_script19B:
		SPR_LIB_SELECT		$01
		SPR_IDX_SELECT		$1B
		OBJ_SET_X_POS		$70,$01
		OBJ_SET_Y_POS		$E0,$00
		PARAM_80_CLEAR
		SJSR				byte_6B6C2
		SJSR				byte_B7DE6
		SJSR				byte_6B73A
		SJSR				byte_6B73A
		SJSR				byte_6B73A
		SJSR				byte_6B73A

; =============== S C R I P T ===============================================
_script19C:
		SPR_LIB_SELECT		$02
		SPR_IDX_SELECT		$1B
		OBJ_SET_X_POS		$40,$01
		OBJ_SET_Y_POS		$E0,$00
		PARAM_80_CLEAR
		SJSR				byte_6B6C2
		SJSR				byte_B7DE6
		SJSR				byte_6B73A
		SJSR				byte_6B73A
		SJSR				byte_6B73A
byte_B7DE6:
		OBJ_SET_X_DELTA		$F0
byte_B7DE8:
		SJSR				_script_sub_B7533
		LOOPA				$06,byte_B7DE8
		SPR_IDX_SELECT		$1B
		SJMP				byte_6B6C2

; =============== S C R I P T ===============================================
_script19D:
		SPR_IDX_SELECT		$1C
		TARGET_DIR_SET		$00
		OBJ_SET_X_POS		$20,$00
		OBJ_SET_Y_POS		$A0,$00
		FLIP_40_SET
		PARAM_80_CLEAR
		SJSR				byte_6B7B7
		SJSR				byte_6B7D1
		SJSR				byte_6B7D1
		SJSR				byte_6B7D1

; =============== S C R I P T ===============================================
_script19E:
		SPR_IDX_SELECT		$28
		TARGET_DIR_SET		$09
		OBJ_SET_X_POS		$40,$00
		OBJ_SET_Y_POS		$C0,$00
		FLIP_40_SET
		PARAM_80_CLEAR
		SJSR				byte_6B773
		SJSR				byte_6B797
		SJSR				byte_6B78D
		SJSR				byte_6B797
		SJSR				byte_6B78D

; =============== S C R I P T ===============================================
_scr_cutscene12:
		SRUN				$01,_script19F
		SRUN				$01,_script1A0
		SRUN				$01,_script1A1
		SRUN				$01,_script1A2
		OBJ_SET_X_POS		$48,$00
		OBJ_SET_Y_POS		$40,$00
		PARAM_80_CLEAR
		FLIP_40_SET
		SJSR				byte_6B7F1

; =============== S C R I P T ===============================================
_script19F:
		SPR_LIB_SELECT		$01
		SPR_IDX_SELECT		$1B
		OBJ_SET_X_POS		$A0,$00
		OBJ_SET_Y_POS		$80,$00
		PARAM_80_CLEAR
		SJMP				_script_idle

; =============== S C R I P T ===============================================
_script1A0:
		SPR_LIB_SELECT		$02
		SPR_IDX_SELECT		$1B
		OBJ_SET_X_POS		$60,$00
		OBJ_SET_Y_POS		$80,$00
		FLIP_40_SET
		PARAM_80_CLEAR
		SJMP				_script_idle

; =============== S C R I P T ===============================================
_script1A1:
		SPR_IDX_SELECT		$1C
		TARGET_DIR_SET		$00
		OBJ_SET_X_POS		$40,$00
		OBJ_SET_Y_POS		$C8,$00
		FLIP_40_SET
		PARAM_80_CLEAR
		SJSR				byte_6B7B7

; =============== S C R I P T ===============================================
_script1A2:
		SPR_IDX_SELECT		$28
		TARGET_DIR_SET		$00
		OBJ_SET_X_POS		$C0,$00
		OBJ_SET_Y_POS		$50,$00
		PARAM_80_CLEAR
		SJSR				byte_6B773

; =============== S U B R O U T I N E =======================================
_native_sub15B:
		LDA		_obj_spr_idxs,X
		CMP		#$1C
		BEQ		loc_B7E84
		RTS
loc_B7E84:
		LDA		#<[byte_B7E8B]
		LDY		#>[byte_B7E8B]
		JMP		_native_sub15B_ex
byte_B7E8B:
		.BYTE	$1D,$1E,$FF
		.BYTE	$20,$1E,$FF
		.BYTE	$1D,$22,$FF
		.BYTE	$20,$1B,$FF
		.BYTE	$1D,$21,$FF

; =============== S U B R O U T I N E =======================================
_native_sub173:
		LDA		_obj_spr_idxs,X
		CMP		#$28
		BEQ		loc_B7EA2
		RTS
loc_B7EA2:
		LDA		#<[byte_B7EA9]
		LDY		#>[byte_B7EA9]
		JMP		_native_sub15B_ex
byte_B7EA9:
		.BYTE	$33,$32,$FF
		.BYTE	$2D,$32,$FF
		.BYTE	$2E,$FF,$FF
		.BYTE	$2F,$FF,$FF

; =============== S U B R O U T I N E =======================================
_native_sub15B_ex:
		STA		_tmp_ptrE
		STY		_tmp_ptrE+1
		LDA		_cur_prg_bank
		PHA
		LDA		_obj_spr_idxs,X
		PHA
		LDY		_scr_vars19,X
loc_B7EC3:
		LDX		_scr_idx
		LDA		(_tmp_ptrE),Y
		BMI		loc_B7ED6
		STA		_obj_spr_idxs,X
		TYA
		PHA
		JSR		_obj_spr_lib_insert
		PLA
		TAY
		INY
		BNE		loc_B7EC3
loc_B7ED6:
		PLA
		LDX		_scr_idx
		STA		_obj_spr_idxs,X
		JMP		_mmc1_prg_restore

		LAST_BANK_END 7,$10000

; total_banks	= 8
; total_size	= 8*16384
; total_free	= $394	(original)
