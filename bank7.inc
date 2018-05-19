
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
		STA		$0000,X
		STA		$0100,X
		STA		$0200,X
		STA		$0300,X
		STA		$0400,X
		STA		$0500,X
		STA		$0600,X
		STA		$0700,X
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
; NOTE, redundant leftover, althought initialized at some points in the game,
; never actually used because initialized there where no split screen mode
; enabled... remove it
		LDY		_wnd_split_ppu_ofs+1
		BEQ		loc_B421C
		LDA		_wnd_split_ppu_ofs
		STY		_PPU_ADDR
		STA		_PPU_ADDR
loc_B421C:
; -
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

; !FALLTHROUGH!

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

; !FALLTHROUGH!

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

; !FALLTHROUGH!

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

; !FALLTHROUGH!

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

; !FALLTHROUGH!

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
		STA		_tmp47
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
		LDA		#_apu_mus31_idx
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
		LDA		_tmp47
		STA		_tmp48
		LDA		_pads+4,X
		AND		#$40
		BEQ		loc_B45E4
		LDA		_tmp47
		BNE		loc_B45DF
		STY		_tmp47
loc_B45DF:
		DEC		_tmp47
		JMP		_menu_idx_changed
loc_B45E4:
		LDA		_pads+4,X
		AND		#$80
		BEQ		_menu_idx_unchanged
		INC		_tmp47
		CPY		_tmp47
		BEQ		loc_B45F2
		BCS		_menu_idx_changed
loc_B45F2:
		LDA		#$00
		STA		_tmp47
		BEQ		_menu_idx_changed

; =============== S U B R O U T I N E =======================================
_get_vert_menu_input:
		TAY
		LDA		_tmp49
		STA		_tmp4A
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

; !FALLTHROUGH!

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
		LDA		_tmp47
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
		LDX		_screen_meta_buf,Y
locret_B46F1:
		RTS

; =============== S U B R O U T I N E =======================================
_obj_to_tile_collision_test_up:
		SEC
		LDA		_obj_y_lo_poss,X
		SBC		_obj_heights,X
		BCC		loc_B4735
		LDA		_obj_y_lo_poss,X
		LDY		_obj_heights,X
		JSR		_sub_minus16
		LDY		byte_9E
		JSR		_sub_minus16
		LDY		#$D0
		JSR		_obj_to_tile_vert_collision_test
		BCC		loc_B4735
		LDA		_obj_y_lo_poss,X
		LDY		_obj_heights,X
		JSR		_sub_minus16
		LDY		byte_9E
		JSR		_sub_minus16
		LDY		#$10
		JSR		_add_plus16
		AND		#$F0
		LDY		_obj_heights,X
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
_obj_to_tile_collision_test_down:
		LDA		_obj_y_hi_poss,X
		BNE		loc_B4778
		STY		_tmp_ptr0
		LDA		_obj_y_lo_poss,X
		LDY		byte_9E
		JSR		_sub_minus16
		LDY		_tmp_ptr0
		JSR		_obj_to_tile_vert_collision_test
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
_obj_to_tile_vert_collision_test:
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
		LDA		_screen_meta_buf,Y
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
_obj_to_tile_collision_test_right:
		CLC
		LDA		_obj_x_lo_poss,X
		ADC		_obj_widths,X
		BCS		loc_B47FB
		JSR		_obj_to_tile_hor_collision_test
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
_obj_to_tile_collision_test_left:
		SEC
		LDA		_obj_x_lo_poss,X
		SBC		_obj_widths,X
		BCC		loc_B4826
		JSR		_obj_to_tile_hor_collision_test
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
_obj_to_tile_hor_collision_test:
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
		LDY		_obj_heights,X
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
		LDA		_screen_meta_buf,Y
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
_sys_screen_cur_meta_update:
		LDA		_cur_prg_bank
		PHA
		LDA		_tmp_ptr4
		PHA
		LDA		_tmp_ptr4+1
		PHA
		TXA
		PHA
		JSR		_sys_screen_cur_meta_pos_calc
		JSR		_sys_room_cur_meta_data_read
		JSR		_sys_screen_cur_meta_draw
		PLA
		TAX
		PLA
		STA		_tmp_ptr4+1
		PLA
		STA		_tmp_ptr4
		JMP		_mmc1_prg_restore

; =============== S U B R O U T I N E =======================================
_sys_screen_rr_meta_draw:
		LDA		_cur_prg_bank
		PHA
		LDA		_tmp_ptr4
		PHA
		LDA		_tmp_ptr4+1
		PHA
		TXA
		PHA
		JSR		_sys_screen_cur_meta_pos_calc
		LDX		#$F9
		JSR		_sys_screen_cur_meta_draw
		PLA
		TAX
		PLA
		STA		_tmp_ptr4+1
		PLA
		STA		_tmp_ptr4
		JMP		_mmc1_prg_restore

; =============== S U B R O U T I N E =======================================
_sys_screen_cur_meta_pos_calc:
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

; !FALLTHROUGH!

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
_sys_room_cur_meta_data_read:
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
		JMP		_sys_screen_cur_meta_draw_ex

; =============== S U B R O U T I N E =======================================
_sys_screen_cur_meta_draw:
		STX		byte_91
		JSR		_room_drawA_ex_A
		STY		byte_84+5
		JSR		_room_calc_sys00
		LDA		byte_91
		STA		_screen_meta_buf,Y

; !FALLTHROUGH!

; =============== S U B R O U T I N E =======================================
_sys_screen_cur_meta_draw_ex:
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
		LDA		_screen_meta_row,X
		STA		_screen_meta_buf,Y
		TYA
		CLC
		ADC		#$10
		TAY
		INX
		CPX		#$0F
		BCC		loc_B4B6B

; !FALLTHROUGH!

; =============== S U B R O U T I N E =======================================
_room_objects_managerA:
		LDA		_tmpA
		STA		byte_82
		LDA		_tmpC
		STA		byte_83
		JSR		_room_drawA_ex_A
		JSR		_room_drawA_ex_init
		JSR		_sys_room_cur_meta_data_read
		BCC		loc_B4B91
		JMP		_room_drawB_reset_idx
loc_B4B91:
		LDX		#$00
loc_B4B93:
		LDA		(_tmp_ptrE),Y
		STA		_screen_meta_row,X
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
		STA		_screen_meta_row,X
		ADDWB	#$02,_room_prizes_ptr
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
		ADDWB	#$03,_room_enemies_ptr
		JMP		loc_B4BD5
loc_B4BFC:
		LDA		#$03
		JSR		_mmc1_prg_set
		LDX		#$00
loc_B4C03:
		TXA
		PHA
		LDA		_screen_meta_row,X
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

; !FALLTHROUGH!

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
		LDA		_screen_meta_row,Y
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
		JSR		_sys_room_cur_meta_data_read
		BCC		loc_B4CA3
		JMP		_room_drawB_reset_idx
loc_B4CA3:
		LDA		(_tmp_ptrE),Y
		STA		_screen_meta_buf,Y
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
		STA		_screen_meta_buf,X
		ADDWB	#$02,_room_prizes_ptr
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
		ADDWB	#$03,_room_enemies_ptr
		JMP		loc_B4CEF
loc_B4D20:
		LDA		#$03
		JSR		_mmc1_prg_set
		LDX		byte_8A+4
loc_B4D27:
		TXA
		PHA
		LDA		_screen_meta_buf,X
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
		LDA		_screen_meta_buf,Y
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

; !FALLTHROUGH!

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
		CMP		#_apu_mus0F_idx
		BEQ		loc_B4E2C
		CMP		#_APU_UNMUTE_idx
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
		CPY		#_apu_mus22_idx
		BCC		locret_B4E52
		CPY		#_APU_UNMUTE_idx
		BCS		locret_B4E52
loc_B4E3D:
		TAY
		CPY		#_apu_mus72_idx
; TODO: REDUNDANT, remove me!
		BEQ		loc_B4E4A
		CPY		#_apu_mus72_idx
		BEQ		loc_B4E4A
		CPY		#_apu_mus72_idx
; -
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

; !FALLTHROUGH!

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

; !FALLTHROUGH!

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
		.WORD	_main9_capcom_logo_unused

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
		LDY		#_OBJ_TYPE_AUTO
		JSR		_scr_load_param
		.WORD	_scr_license
		JMP		_MAIN_LOOP_START

; =============== S U B R O U T I N E =======================================
_main9_capcom_logo_unused:
		LDY		#_OBJ_TYPE_AUTO
		JSR		_scr_load_param
		.WORD	_scr_capcom_logo_unused
		JMP		_MAIN_LOOP_START

; =============== S U B R O U T I N E =======================================
_main1_intro:
		LDY		#_OBJ_TYPE_AUTO
		JSR		_scr_load_param
		.WORD	_scr_intro
		LDA		#_APU_ALL_STOP_idx
		JSR		_apu_mus_req
		JMP		_MAIN_LOOP_START

; =============== S U B R O U T I N E =======================================
_main2_title:
		LDY		#_OBJ_TYPE_AUTO
		JSR		_scr_load_param
		.WORD	_scr_title
		LDA		#_apu_mus01_idx
		JSR		_apu_mus_req
		JMP		_MAIN_LOOP_START

byte_B50F5:
		.BYTE	$01,$02,$03

; =============== S U B R O U T I N E =======================================
_main3_cutscenes:
		LDY		#_OBJ_TYPE_AUTO
		JSR		_scr_load_param
		.WORD	_scr_cutscenes_start
		JMP		_MAIN_LOOP_START

; =============== S U B R O U T I N E =======================================
_main5_stage_complete:
		LDA		#<[_scr_stage_complete]
		STA		_tmp_ptr0
		LDA		#>[_scr_stage_complete]
		STA		_tmp_ptr0+1
		LDA		#$00
		STA		_tmp_ptr2
		STA		_tmp_ptr2+1
		STA		_tmp_ptr4
		STA		_tmp_ptr4+1
		STA		byte_6
		LDX		#$02
		LDY		#_OBJ_TYPE_AUTO
		JSR		_scr_load_ex
		JMP		_MAIN_LOOP_START

; =============== S U B R O U T I N E =======================================
_main7_game_over:
		LDY		#_OBJ_TYPE_AUTO
		JSR		_scr_load_param
		.WORD	_scr_game_over
		LDA		#_apu_mus1D_idx
		JSR		_apu_mus_req
		JMP		_MAIN_LOOP_START

; =============== S U B R O U T I N E =======================================
_main8_continue:
		LDY		#_OBJ_TYPE_AUTO
		JSR		_scr_load_param
		.WORD	_scr_continue
		JMP		_MAIN_LOOP_START

; =============== S U B R O U T I N E =======================================
_main4_ingame:
		LDA		#$02
		JSR		_mmc1_prg_set
		LDX		#$00
		JSR		_players_insert
		LDX		#$01
		JSR		_players_insert
		LDX		#$FF
		LDY		#$00
		JSR		_is_it_stage4_ingame
		BNE		loc_B5155
		LDX		#$3B
		LDY		#$03
loc_B5155:
		LDA		#$00
		STY		_timer_minutes_cnt
		STA		_timer_seconds_cnt
		STX		_timer_frames_cnt
		JSR		_obj_scr_manager
		JSR		_hud_obj_managers
		JSR		_render_on
		LDX		#$04
		LDA		#$FF
		JSR		_set_pal_fade_in
		JSR		_wait_for_pal_fade_is_over

; !FALLTHROUGH!

; =============== S U B R O U T I N E =======================================
_ingame_loop:
#if DEBUG=1
		LDA		_ppu_mask_shadow
		EOR		#$02
		STA		_PPU_MASK
#endif
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
		LDA		#_apu_mus34_idx
		JSR		_apu_se_req
		LDA		#$04
		JSR		_wait_for_frames
_exit_ingame_idle_mode:
		INC		_ingame_mode_idx
		LDA		#_APU_MUTE_idx
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
		LDX		_screen_meta_buf,Y
		JSR		_sys_screen_cur_meta_draw
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
		LDX		_screen_meta_row,Y
		LDY		_tmp49
		LDA		_screen_meta_buf,Y
		PHA
		JSR		_sys_screen_cur_meta_draw
		PLA
		LDY		_tmp49
		STA		_screen_meta_buf,Y
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
		LDA		#_APU_UNMUTE_idx
		JSR		_apu_mus_req
		LDA		#$00
		STA		_ingame_mode_idx

; !FALLTHROUGH!

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
		BNE		_j_room_complete
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
		BNE		_j_room_complete
		LDA		#$07
		STA		_main_sub_idx
		JMP		_pal_fade_out
_j_room_complete:
		JMP		_room_complete

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
		LDA		#_spr_lib0_0D_idx
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
		ADC		#[_spr_lib0_02_hp_1_idx-1]
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
		.BYTE	_spr_lib0_07_idx,$50
		.BYTE	_spr_lib0_0B_idx,$78
		.BYTE	_spr_lib0_0A_idx,$90
		.BYTE	_spr_lib0_10_idx,$98
		.BYTE	_spr_lib0_0E_idx,$B0
		.BYTE	_spr_lib0_11_idx,$B0
		.BYTE	$FF
_status_spr1_res0:
		.BYTE	_spr_lib0_08_idx,$50
		.BYTE	_spr_lib0_0C_idx,$78
		.BYTE	_spr_lib0_0A_idx,$90
		.BYTE	_spr_lib0_10_idx,$98
		.BYTE	_spr_lib0_0E_idx,$B0
		.BYTE	_spr_lib0_11_idx,$B0
		.BYTE	$FF
_status_spr0_res1:
		.BYTE	_spr_lib0_0B_idx,$50
		.BYTE	_spr_lib0_0A_idx,$68
		.BYTE	_spr_lib0_10_idx,$70
		.BYTE	_spr_lib0_0E_idx,$88
		.BYTE	_spr_lib0_11_idx,$88
		.BYTE	_spr_lib0_09_idx,$98
		.BYTE	_spr_lib0_12_idx,$A0
		.BYTE	$FF
_status_spr1_res1:
		.BYTE	_spr_lib0_0C_idx,$50
		.BYTE	_spr_lib0_0A_idx,$68
		.BYTE	_spr_lib0_10_idx,$70
		.BYTE	_spr_lib0_0E_idx,$88
		.BYTE	_spr_lib0_11_idx,$88
		.BYTE	_spr_lib0_09_idx,$98
		.BYTE	_spr_lib0_12_idx,$A0
		.BYTE	$FF

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
		ADC		#[_spr_lib0_02_hp_1_idx-1]
		STA		_obj_spr_idxs+2
		JSR		_obj_spr_lib_insert
loc_B5507:
		PLA
		TAX
loc_B5509:
		DEX
		BPL		loc_B54DA
		JSR		_is_it_stage4_ingame
		BNE		loc_B5514
		JSR		_stage4_hud_timer_insert
loc_B5514:
		LDA		_timer_frames_cnt
		BMI		locret_B5554
		DEC		_timer_frames_cnt
		BPL		locret_B5554
		LDA		#$3B
		STA		_timer_frames_cnt
		DEC		_timer_seconds_cnt
		BPL		loc_B5545
		LDA		#$3B
		STA		_timer_seconds_cnt
		DEC		_timer_minutes_cnt
		BPL		locret_B5554
		LDA		#$00
		STA		_timer_minutes_cnt
		STA		_timer_seconds_cnt
		STA		_timer_frames_cnt
		DEC		_timer_frames_cnt
		JSR		_is_it_stage4_ingame
		BNE		loc_B5545
		LDY		#$00
		JSR		_player_kill
		LDY		#$01
		JSR		_player_kill
loc_B5545:
		LDA		_timer_minutes_cnt
		BNE		locret_B5554
		LDA		_timer_seconds_cnt
		CMP		#$0A
		BCS		locret_B5554
		LDA		#_apu_mus3A_idx
		JSR		_apu_se_req
locret_B5554:
		RTS

; =============== S U B R O U T I N E =======================================
_is_it_stage4_ingame:
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
		LDX		_timer_minutes_cnt
		LDA		_num_char_table1,X
		STA		_ram_buf0+3
		LDA		_timer_seconds_cnt
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
		LDA		#_spr_lib0_10_idx
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
		STA		_obj_heights,Y
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
		.BYTE	$00
		.BYTE	_spr_lib0_15_hud_C_letter_idx
		.BYTE	_spr_lib0_16_hud_D_letter_idx
_hud_heart_name_spr_pos_list:
		.BYTE	$00,$10,$D0
_spr_hud_timer_raw:
		.BYTE	$04,$00,$00,$E8,$01,$F2,$01,$E8,$01,$E8,$01,$00

; =============== S U B R O U T I N E =======================================
_room_complete:
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
		.WORD	_screen_res9_capcom_logo_unused

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
		STA		_tmp46
		INY
		LDA		(_tmp_ptr42),Y
		STA		_tmp_ptr0
		INY
		TYA
		PHA
		LDA		(_tmp_ptr42),Y
		LDX		_tmp46
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

_screen_res9_capcom_logo_unused:
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
		.BYTE	$02					; _ppu_mode
		.WORD	_pal4				; _pal_bg_ptr
		.WORD	_pal5				; _pal_spr_ptr
		.BYTE	$40					; _fill_tile
		.BYTE	$00					; _attr_fill
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
		LDA		#_apu_mus1B_idx
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
		STA		_tmp47
		STA		_tmp48
		RTS

_screen_res7_game_over:
		.BYTE	$02					; _ppu_mode
		.WORD	_pal6				; _pal_bg_ptr
		.WORD	_pal7				; _pal_spr_ptr
		.BYTE	$40					; _fill_tile
		.BYTE	$00					; _attr_fill
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
		.BYTE	$02					; _ppu_mode
		.WORD	_pal8				; _pal_bg_ptr
		.WORD	_palA				; _pal_spr_ptr
		.BYTE	$40					; _fill_tile
		.BYTE	$00					; _attr_fill
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
		.BYTE	$02					; _ppu_mode
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
		ADC		_lvl_stage_room_idx_ofs,X
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
		LDA		#_OBJ_MODE_HIDE|_OBJ_TYPE_AUTO
		STA		_scr_params
		STA		_scr_params+1
		STA		_scr_params+2
		LDA		#_OBJ_FLIPS08|_OBJ_FLIPS04
		STA		_obj_flips+2
		LDA		#<[_ssub_suspend_forever]
		STA		_scr_lo_pcs+2
		LDA		#>[_ssub_suspend_forever]
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

		MAC	LVL_OFS
{1}		SET	[.-_room_cfg_lib]
		ENDM

_room_cfg_lib:
		LVL_OFS	_stage0_ofs
#if DEBUG=1
		.WORD	_room_cfg09
#else
		.WORD	_room_cfg00	; 00 0	room 1
#endif
		.WORD	_room_cfg01	; 02 1	room 2
		.WORD	_room_cfg02	; 04 2	room 3
		.WORD	_room_cfg03	; 06 3	monterey refill
		.WORD	$02			; 08 4	boss 1 intro
		.WORD	_room_cfg05	; 0A 5	boss 1 water rabbit
		LVL_OFS	_stage1_ofs
		.WORD	_room_cfg06	; 0C 0	room 1 -> branch to 3 (2p only)
		.WORD	_room_cfg07	; 0E 1	room 2
		.WORD	_room_cfg08	; 10 2	boss
		.WORD	_room_cfg09	; 12 3	basket game
		.WORD	_room_cfg0A	; 14 4	box bonus
		.WORD	_room_cfg07	; 16 5	room 2
		.WORD	_room_cfg08	; 18 6	boss 2 bat panther
		LVL_OFS	_stage2_ofs
		.WORD	_room_cfg0D	; 1A 0	room 1 -> branch to 2
		.WORD	_room_cfg0E	; 1C 1	boss sea rat
		.WORD	_room_cfg03	; 1E 2	monerey refill
		.WORD	_room_cfg10	; 20 3	room 1 second half
		.WORD	_room_cfg0E	; 22 4	boss 3 sea rat
		LVL_OFS	_stage3_ofs
		.WORD	$08			; 24 0	stage 4 intro
		.WORD	_room_cfg13	; 26 1	room 1 (no boss)
		LVL_OFS	_stage4_ofs
		.WORD	_room_cfg14	; 28 0	room 1
		.WORD	_room_cfg15	; 2A 1	room 2 -> branch to 3 (2p) 8 (1p)
		.WORD	_room_cfg16	; 2C 2	boss 4 ghost mummy
		.WORD	_room_cfg17	; 2E 3	buttons room
		.WORD	_room_cfg18	; 30 4	coins game
		.WORD	_room_cfg0A	; 32 5	box bonus
		.WORD	_room_cfg1A	; 34 6	room 2 second half
		.WORD	_room_cfg16	; 36 7	boss 4 ghost mummy
		.WORD	_room_cfg03	; 38 8	monerey refill
		.WORD	_room_cfg1A	; 3A 9	room 2 second half
		.WORD	_room_cfg16	; 3C A	boss 4 ghost mummy
		LVL_OFS	_stage5_ofs
		.WORD	_room_cfg1F	; 3E 0	room 1
		.WORD	_room_cfg20	; 40 1	boss 5A ostrich
		LVL_OFS	_stage6_ofs
		.WORD	_room_cfg21	; 42 0	room 1
		.WORD	_room_cfg22	; 44 1	room 2
		.WORD	_room_cfg23	; 46 2	room 3
		.WORD	_room_cfg24	; 48 3	room 4
		.WORD	_room_cfg25	; 4A 4	boss 5B cat with cards
		LVL_OFS	_stage7_ofs
		.WORD	_room_cfg26	; 4C 0	room 1
		.WORD	_room_cfg27	; 4E 1	room 2 -> jump 3 or branch 2
		.WORD	_room_cfg03	; 50 2	monterey refill
		.WORD	_room_cfg29	; 52 3	room 3
		.WORD	_room_cfg2A	; 54 4	boss 5C wrecking lizard
		LVL_OFS	_stage8_ofs
		.WORD	_room_cfg2B	; 56 0	room 1
		.WORD	_room_cfg2C	; 58 1	room 2 -> jump 3 or branch 2
		.WORD	_room_cfg03	; 5A 2	monterey refill
		.WORD	_room_cfg2E	; 5C 3	room 3
		.WORD	_room_cfg2F	; 5E 4	room 4
		.WORD	_room_cfg30	; 60 5	room 5
		.WORD	$0E			; 62 6	final boss intro
		.WORD	_room_cfg32	; 64 7	final boss mecha cat

_lvl_stage_room_idx_ofs:
		.BYTE	_stage0_ofs
		.BYTE	_stage1_ofs
		.BYTE	_stage2_ofs
		.BYTE	_stage3_ofs
		.BYTE	_stage4_ofs
		.BYTE	_stage5_ofs
		.BYTE	_stage6_ofs
		.BYTE	_stage7_ofs
		.BYTE	_stage8_ofs
_unref:
		.BYTE	$05,$02,$01,$01,$02,$01,$04,$04,$07
_lvl_inro_cutscenes_list:
		.BYTE	$0F,$03,$FF,$04,$09,$0A,$0B,$0B,$0B

_cutscene_rooms_cfg_lib:
		.WORD	_cutscene_cfg00
		.WORD	_cutscene_cfg01
		.WORD	_cutscene_cfg02
		.WORD	_cutscene_cfg03
		.WORD	_cutscene_cfg04
		.WORD	_cutscene_cfg05
		.WORD	_cutscene_cfg06
		.WORD	_cutscene_cfg07
		.WORD	_cutscene_cfg07
		.WORD	_cutscene_cfg09
		.WORD	_cutscene_cfg0A
		.WORD	_cutscene_cfg0B
		.WORD	_cutscene_cfg0C
		.WORD	_cutscene_cfg0D
		.WORD	_cutscene_cfg0E
		.WORD	_cutscene_cfg0F
		.WORD	_cutscene_cfg10
		.WORD	_cutscene_cfg11
		.WORD	_cutscene_cfg12

; =============== S U B R O U T I N E =======================================
_nsub_lvl_intro_cutscene_start:
		LDY		#$04
		LDX		_stage
		LDA		_lvl_inro_cutscenes_list,X
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
		_CMD_IDX	_scr_cmd00_stop
		_CMD_IDX	_scr_cmd01_sync
		_CMD_IDX	_scr_cmd02_suspend
		_CMD_IDX	_scr_cmd03_ejsr_sync
		_CMD_IDX	_scr_cmd04_run
		_CMD_IDX	_scr_cmd05_ejsr
		_CMD_IDX	_scr_cmd06_jmp
		_CMD_IDX	_scr_cmd07_jsr
		_CMD_IDX	_scr_cmd08_ret
		_CMD_IDX	_scr_cmd09_loopA
		_CMD_IDX	_scr_cmd0A_loopB
		_CMD_IDX	_scr_cmd0B_bne
		_CMD_IDX	_scr_cmd0C_bcc
		_CMD_IDX	_scr_cmd0D_bpl
		_CMD_IDX	_scr_cmd0E_beq
		_CMD_IDX	_scr_cmd0F_bcs
		_CMD_IDX	_scr_cmd10_bmi
		_CMD_IDX	_scr_cmd11_pads_test
		_CMD_IDX	_scr_cmd12_switch
		_CMD_IDX	_scr_cmd13_store
		_CMD_IDX	_scr_cmd14_chr_set
		_CMD_IDX	_scr_cmd15_loopA_reset
		_CMD_IDX	_scr_cmd16_loopB_reset
		_CMD_IDX	_scr_cmd17_apu_load
		_CMD_IDX	_scr_cmd18_obj_animate_sync
		_CMD_IDX	_scr_cmd19_obj_animate
		_CMD_IDX	_scr_cmd1A_target_follow
		_CMD_IDX	_scr_cmd1C_obj_show
		_CMD_IDX	_scr_cmd1C_obj_hide
		_CMD_IDX	_scr_cmd1D_spr_lib_select
		_CMD_IDX	_scr_cmd1E_spr_idx_select
		_CMD_IDX	_scr_cmd1F_hflip_clear
		_CMD_IDX	_scr_cmd1F_hflip_set
		_CMD_IDX	_scr_cmd21_vflip_clear
		_CMD_IDX	_scr_cmd21_vflip_set
		_CMD_IDX	_scr_cmd23_hflip_toggle
		_CMD_IDX	_scr_cmd23_vflip_toggle
		_CMD_IDX	_scr_cmd25_obj_set_x_pos
		_CMD_IDX	_scr_cmd26_obj_set_y_pos
		_CMD_IDX	_scr_cmd27_obj_move_x_pos
		_CMD_IDX	_scr_cmd28_obj_move_y_pos
		_CMD_IDX	_scr_cmd29_obj_set_x_delta
		_CMD_IDX	_scr_cmd2A_obj_set_y_delta
		_CMD_IDX	_scr_cmd2B_obj_inc_x_delta
		_CMD_IDX	_scr_cmd2C_obj_inc_y_delta
		_CMD_IDX	_scr_cmd2D_obj_dec_x_delta
		_CMD_IDX	_scr_cmd2E_dec_y_delta
		_CMD_IDX	_scr_cmd2F_target_lock
		_CMD_IDX	_scr_cmd30_obj_timerAs_set
		_CMD_IDX	_scr_cmd31_obj_timerBs_set
		_CMD_IDX	_scr_cmd32_obj_set_size
		_CMD_IDX	_scr_cmd33_damage_set
		_CMD_IDX	_scr_cmd34_obj_set_hp
		_CMD_IDX	_scr_cmd35_obj_flips_set
		_CMD_IDX	_scr_cmd36_idxCs_set			; unused
		_CMD_IDX	_scr_cmd37_main_sub_idx_set
		_CMD_IDX	_scr_cmd38_pal_fade_in
		_CMD_IDX	_scr_cmd39_pal_fade_out
		_CMD_IDX	_scr_cmd3A_tlm_res_queue		; unused
		_CMD_IDX	_scr_cmd3B_draw_menu_cursor
		_CMD_IDX	_scr_cmd3C_hor_menu_input		; unused
		_CMD_IDX	_scr_cmd3D_vert_menu_input
		_CMD_IDX	_scr_cmd3E_msg_area_set			; unused
		_CMD_IDX	_scr_cmd3F_msg_display
		_CMD_IDX	_scr_cmd40_msg_wait
		_CMD_IDX	_scr_cmd41_break
		_CMD_IDX	_scr_cmd42_destr_pc_set
		_CMD_IDX	_scr_cmd43_obj_grabable
#if OPTIMIZATION=1
		_CMD_IDX	_scr_cmd44_bne_short
		_CMD_IDX	_scr_cmd45_bcc_short
		_CMD_IDX	_scr_cmd46_bpl_short
		_CMD_IDX	_scr_cmd47_beq_short
		_CMD_IDX	_scr_cmd48_bcs_short
		_CMD_IDX	_scr_cmd49_bmi_short
		_CMD_IDX	_scr_cmd4A_jmp_short
		_CMD_IDX	_scr_cmd4B_jsr_short
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

; !FALLTHROUGH!

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

#if OPTIMIZATION=1
; =============== S U B R O U T I N E =======================================
_scr_getc:
		LDY		#$00
		LDA		(_scr_pc),Y
		INC		_scr_pc
		BNE		loc_B5BD0
		INC		_scr_pc+1
loc_B5BD0:
		RTS
; =============== S U B R O U T I N E =======================================
_scr_getc_flags:
		LDY		#$00
		LDA		(_scr_pc),Y
		TAY
		INC		_scr_pc
		BNE		loc_B5BCF
		INC		_scr_pc+1
loc_B5BCF:
		TYA
		RTS
#else
; =============== S U B R O U T I N E =======================================
_scr_getc_flags:
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
#endif

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
		LDA		#_OBJ_MODE_HIDE|_OBJ_TYPE_DISABLED
		STA		_scr_params,X
		STA		_scr_vars21,X
		RTS

; =============== S U B R O U T I N E =======================================
_scr_cmd01_sync:
		JMP		_scr_pc_flush

; =============== S U B R O U T I N E =======================================
_scr_cmd02_suspend:
		JSR		_scr_getc
		STA		_scr_delays,X
		JMP		_scr_pc_flush

; =============== S U B R O U T I N E =======================================
_scr_cmd04_run:
		JSR		_scr_getc
		PHA
#if OPTIMIZATION=1
		JSR		_scr_getw
#else
		JSR		_scr_getc
		STA		_tmp_ptr0
		JSR		_scr_getc
		STA		_tmp_ptr0+1
#endif
		LDA		_obj_y_lo_poss,X
		STA		_tmp_ptr2
		LDA		_obj_y_hi_poss,X
		STA		_tmp_ptr2+1
		LDA		_obj_x_lo_poss,X
		STA		_tmp_ptr4
		LDA		_obj_x_hi_poss,X
		STA		_tmp_ptr4+1
		LDA		_obj_flips,X
		AND		#_OBJ_FLIP_H
		STA		byte_6
		PLA
		TAY
		JSR		_scr_load
		JSR		_scr_flags_update
		JMP		_scr_cmd_fetch

; =============== S U B R O U T I N E =======================================
_scr_cmd03_ejsr_sync:
#if OPTIMIZATION=1
		JSR		_scr_getw
#else
		JSR		_scr_getc
		STA		_tmp_ptr0
		JSR		_scr_getc
		STA		_tmp_ptr0+1
#endif
		JSR		_scr_pc_flush
		JMP		(_tmp_ptr0)

; =============== S U B R O U T I N E =======================================
_scr_cmd05_ejsr:
#if OPTIMIZATION=1
		JSR		_scr_getw
#else
		JSR		_scr_getc
		STA		_tmp_ptr0
		JSR		_scr_getc
		STA		_tmp_ptr0+1
#endif
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
; TODO: optimize me, put directly into PC, then jump to fetch instead of exec
		JSR		_scr_getc
		STA		_scr_lo_pcs,X
		JSR		_scr_getc
		STA		_scr_hi_pcs,X
		JMP		_scr_cmd_exec
; -

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
#if OPTIMIZATION=1
		JMP		_scr_byte_skip
#else
		JMP		_scr_ofs_skip
#endif

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
#if OPTIMIZATION=1
		JMP		_scr_byte_skip
#else
		JMP		_scr_ofs_skip
#endif

; =============== S U B R O U T I N E =======================================
_scr_do_loop:
#if OPTIMIZATION=1
		JMP		_scr_short_jmp
#else
		JMP		_scr_cmd06_jmp
#endif

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
_scr_cmd0B_bne:
		LDA		_scr_flags,X
		PHA
		PLP
		BEQ		_scr_ofs_skip
		JMP		_scr_cmd06_jmp

; =============== S U B R O U T I N E =======================================
_scr_cmd0C_bcc:
		LDA		_scr_flags,X
		PHA
		PLP
		BCS		_scr_ofs_skip
		JMP		_scr_cmd06_jmp

; =============== S U B R O U T I N E =======================================
_scr_cmd0D_bpl:
		LDA		_scr_flags,X
		PHA
		PLP
		BMI		_scr_ofs_skip
		JMP		_scr_cmd06_jmp

; =============== S U B R O U T I N E =======================================
_scr_cmd0E_beq:
		LDA		_scr_flags,X
		PHA
		PLP
		BNE		_scr_ofs_skip
		JMP		_scr_cmd06_jmp

; =============== S U B R O U T I N E =======================================
_scr_cmd0F_bcs:
		LDA		_scr_flags,X
		PHA
		PLP
		BCC		_scr_ofs_skip
		JMP		_scr_cmd06_jmp

; =============== S U B R O U T I N E =======================================
_scr_cmd10_bmi:
		LDA		_scr_flags,X
		PHA
		PLP
		BPL		_scr_ofs_skip
		JMP		_scr_cmd06_jmp

; =============== S U B R O U T I N E =======================================
_scr_ofs_skip:
#if OPTIMIZATION=1
		LDA		_scr_pc
		CLC
		ADC		#2
		STA		_scr_pc
		BCC		.ofs_skip
		INC		_scr_pc+1
.ofs_skip
#else
		JSR		_scr_getc
		JSR		_scr_getc
#endif
;
		JMP		_scr_cmd_fetch

; =============== S U B R O U T I N E =======================================
_scr_cmd11_pads_test:
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

#if OPTIMIZATION=1
; =============== S U B R O U T I N E =======================================
_scr_cmd44_bne_short:
		LDA		_scr_flags,X
		PHA
		PLP
		BEQ		_scr_byte_skip
		BNE		_scr_short_jmp

; =============== S U B R O U T I N E =======================================
_scr_cmd45_bcc_short:
		LDA		_scr_flags,X
		PHA
		PLP
		BCS		_scr_byte_skip
		BCC		_scr_short_jmp

; =============== S U B R O U T I N E =======================================
_scr_cmd46_bpl_short:
		LDA		_scr_flags,X
		PHA
		PLP
		BMI		_scr_byte_skip
		BPL		_scr_short_jmp

; =============== S U B R O U T I N E =======================================
_scr_cmd47_beq_short:
		LDA		_scr_flags,X
		PHA
		PLP
		BNE		_scr_byte_skip
		BEQ		_scr_short_jmp

; =============== S U B R O U T I N E =======================================
_scr_cmd48_bcs_short:
		LDA		_scr_flags,X
		PHA
		PLP
		BCC		_scr_byte_skip
		BCS		_scr_short_jmp

; =============== S U B R O U T I N E =======================================
_scr_cmd49_bmi_short:
		LDA		_scr_flags,X
		PHA
		PLP
		BPL		_scr_byte_skip
		BMI		_scr_short_jmp

; =============== S U B R O U T I N E =======================================
_scr_short_ofs:
		LDA		#$00
		STA		_tmp_ptr0
		JSR		_scr_getc_flags
		BPL		.positive
		DEC		_tmp_ptr0
.positive:
		CLC
		ADC		_scr_pc
		STA		_scr_lo_pcs,X
		LDA		_scr_pc+1
		ADC		_tmp_ptr0
		STA		_scr_hi_pcs,X
		RTS

; =============== S U B R O U T I N E =======================================
_scr_cmd4B_jsr_short:
		JSR		_scr_short_ofs
		JSR		_scr_get_sp
		LDA		_scr_pc+1
		JSR		_scr_push
		LDA		_scr_pc
		JSR		_scr_push
		JMP		_scr_cmd_exec

; !FALLTHROUGH!

; =============== S U B R O U T I N E =======================================
_scr_cmd4A_jmp_short:
_scr_short_jmp:
		JSR		_scr_short_ofs
		JMP		_scr_cmd_exec

; =============== S U B R O U T I N E =======================================
_scr_byte_skip:
		INC		_scr_pc
		BNE		.byte_skip
		INC		_scr_pc+1
.byte_skip
		JMP		_scr_cmd_fetch
#endif

; =============== S U B R O U T I N E =======================================
_scr_cmd12_switch:
#if OPTIMIZATION=1
		JSR		_scr_getw
#else
		JSR		_scr_getc
		STA		_tmp_ptr0
		JSR		_scr_getc
		STA		_tmp_ptr0+1
#endif
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
_scr_cmd13_store:
		JSR		_scr_getc
		PHA
		JSR		_scr_getw
		PLA
		LDY		#$00
		STA		(_tmp_ptr0),Y
		JMP		_scr_cmd_fetch

; =============== S U B R O U T I N E =======================================
_scr_cmd14_chr_set:
		JSR		_scr_getc
		TAX
		JSR		_scr_getc
		STA		_chr0_bank_req,X
		JMP		_scr_cmd_fetch

; =============== S U B R O U T I N E =======================================
_scr_cmd17_apu_load:
		JSR		_scr_getc
		CMP		#_APU_UNMUTE_idx
		BCS		loc_B5DB1
		CMP		#_apu_mus22_idx
		BCC		loc_B5DB1
		JSR		_apu_se_req
		JMP		_scr_cmd_fetch
loc_B5DB1:
		JSR		_apu_mus_req
		JMP		_scr_cmd_fetch

; =============== S U B R O U T I N E =======================================
_scr_cmd19_obj_animate:
		JSR		_obj_move_hor_animate
		JSR		_obj_vert_anim
		JMP		_scr_cmd_fetch

; =============== S U B R O U T I N E =======================================
_scr_cmd18_obj_animate_sync:
		JSR		_obj_move_hor_animate
		JSR		_obj_vert_anim
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
_obj_vert_anim:
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
		LDA		_obj_timerBs,X
		BEQ		loc_B5EE8
		LDA		_scr_vars16,X
		JSR		_scr_cmd1A_A
		BEQ		loc_B5EE8
		STA		_tmp_ptr0
		LDA		#$00
		STA		_tmp_ptr2
		STA		_tmp_ptr4
loc_B5EA6:
		LDA		_scr_timerAs,X
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
		DEC		_obj_timerBs,X
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
		LDA		_obj_timerBs,X
		JSR		_scr_flags_update
		JMP		_scr_cmd_fetch

; =============== S U B R O U T I N E =======================================
_scr_cmd1A_B:
		LDA		_scr_timerAs,X
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
		LDA		_scr_timerAs,X
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
_scr_cmd1C_obj_show:
		JSR		_scr_obj_show
		JMP		_scr_cmd_fetch

; =============== S U B R O U T I N E =======================================
_scr_cmd1C_obj_hide:
		JSR		_scr_obj_hide
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
_scr_cmd36_idxCs_set:
		JSR		_scr_getc
		STA		_scr_idxCs,X
		JMP		_scr_cmd_fetch

; =============== S U B R O U T I N E =======================================
_scr_cmd35_obj_flips_set:
		JSR		_scr_getc
		JMP		_scr_obj_flip_set

; =============== S U B R O U T I N E =======================================
_scr_cmd1F_hflip_clear:
		LDA		_obj_flips,X
		AND		#[~_OBJ_FLIP_H&$FF]
		JMP		_scr_obj_flip_set

; =============== S U B R O U T I N E =======================================
_scr_cmd1F_hflip_set:
		LDA		_obj_flips,X
		ORA		#_OBJ_FLIP_H
		JMP		_scr_obj_flip_set

; =============== S U B R O U T I N E =======================================
_scr_cmd21_vflip_clear:
		LDA		_obj_flips,X
		AND		#[~_OBJ_FLIP_V&$FF]
		JMP		_scr_obj_flip_set

; =============== S U B R O U T I N E =======================================
_scr_cmd21_vflip_set:
		LDA		_obj_flips,X
		ORA		#_OBJ_FLIP_V
		JMP		_scr_obj_flip_set

; =============== S U B R O U T I N E =======================================
_scr_cmd23_hflip_toggle:
		LDA		_obj_flips,X
		EOR		#_OBJ_FLIP_H
		JMP		_scr_obj_flip_set

; =============== S U B R O U T I N E =======================================
_scr_cmd23_vflip_toggle:
		LDA		_obj_flips,X
		EOR		#_OBJ_FLIP_V

; !FALLTHROUGH!

; =============== S U B R O U T I N E =======================================
_scr_obj_flip_set:
		STA		_obj_flips,X
		JMP		_scr_cmd_fetch

; =============== S U B R O U T I N E =======================================
_scr_cmd43_obj_grabable:
		LDA		_scr_params,X
		ORA		#_OBJ_MODE_GRABABLE
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
		JSR		_scr_getc_flags
; NOTE, here is the case why they need to backup A before incrementing the PC
; they need immediately flags to be set properly to handle negative values
; so do am I in my new short branches.
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
		JSR		_scr_getc_flags
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
_scr_cmd30_obj_timerAs_set:
		JSR		_scr_getc
		STA		_scr_timerAs,X
		JMP		_scr_cmd_fetch

; =============== S U B R O U T I N E =======================================
_scr_cmd31_obj_timerBs_set:
		JSR		_scr_getc
		STA		_obj_timerBs,X
		JMP		_scr_cmd_fetch

; =============== S U B R O U T I N E =======================================
_scr_cmd32_obj_set_size:
		JSR		_scr_getc
		STA		_obj_widths,X
		JSR		_scr_getc
		STA		_obj_heights,X
		JMP		_scr_cmd_fetch

; =============== S U B R O U T I N E =======================================
_scr_cmd33_damage_set:
		JSR		_scr_getc
		STA		_obj_damages,X
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

#if OPTIMIZATION=1
; =============== S U B R O U T I N E =======================================
_scr_getw:
		LDY		#$00
		LDA		(_scr_pc),Y
		STA		_tmp_ptr0
		INY
		LDA		(_scr_pc),Y
		STA		_tmp_ptr0+1
		LDA		_scr_pc
		CLC
		ADC		#2
		STA		_scr_pc
		BCC		.getwf
		INC		_scr_pc+1
.getwf
		RTS
#else
; =============== S U B R O U T I N E =======================================
_scr_getw:
		JSR		_scr_getc
		STA		_tmp_ptr0
		JSR		_scr_getc
		STA		_tmp_ptr0+1
		RTS
#endif

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
_nsub_obj_to_player_set_tangent:
		LDY		_players_macro_overlap_test_idx
		JSR		_get_obj_to_obj_vector
		JSR		_get_obj_to_obj_tangent
		STA		_scr_timerAs,X
		RTS

; =============== S U B R O U T I N E =======================================
_get_obj_to_obj_vector:
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

_tangent_tbl:
		.BYTE	$00,$01,$02,$03,$04,$05,$06,$07	; 00
		.BYTE	$0F,$0E,$0D,$0C,$0B,$0A,$09,$08	; 08
		.BYTE	$10,$11,$12,$13,$14,$15,$16,$17	; 10
		.BYTE	$1F,$1E,$1D,$1C,$1B,$1A,$19,$18	; 18
		.BYTE	$20,$21,$22,$23,$24,$25,$26,$27	; 20
		.BYTE	$2F,$2E,$2D,$2C,$2B,$2A,$29,$28	; 28
		.BYTE	$30,$31,$32,$33,$34,$35,$36,$37	; 30
		.BYTE	$3F,$3E,$3D,$3C,$3B,$3A,$39,$38	; 38

; =============== S U B R O U T I N E =======================================
_get_obj_to_obj_tangent:
		LDA		_tmp_ptr0					; compare X to Y len
		CMP		_tmp_ptr2
		BEQ		.x_less_equal_y
		BCS		.x_greater_y
.x_less_equal_y:
		LDA		_tmp_ptr2					; divide Y to X
		STA		byte_8						; multyply to 8 if X<4, X=1
		LDA		_tmp_ptr0					; if result > 7, clamp to 7
		STA		_tmpA
		JSR		_y_div_x_mul_8
		LDA		_tmp_ptr2+1
		BMI		loc_B627C
		LDA		_tmp_ptr0+1					; Y positive, X positive, idx = $00
		ASL									;             X negative, idx = $38
		LDA		#$00
		BCC		loc_B62AA
		LDA		#$38
		BNE		loc_B62AA
loc_B627C:
		LDA		_tmp_ptr0+1					; Y negative, X positive, idx = $18
		ASL									;             X negative, idx = $20
		LDA		#$18
		BCC		loc_B62AA
		LDA		#$20
		BNE		loc_B62AA
.x_greater_y:
		LDA		_tmp_ptr0					; divide X to Y
		STA		byte_8						; multiply to 8 if Y<4, Y=1
		LDA		_tmp_ptr2					; if result > 7 clamp to 7
		STA		_tmpA
		JSR		_y_div_x_mul_8
		LDA		_tmp_ptr0+1
		BMI		loc_B62A1
		LDA		_tmp_ptr2+1					; Y positive, X positive, idx = $08
		ASL									;             X negative, idx = $10
		LDA		#$08
		BCC		loc_B62AA
		LDA		#$10
		BNE		loc_B62AA
loc_B62A1:
		LDA		_tmp_ptr2+1					; Y positive, X positive, idx = $30
		ASL									;             X negative, idx = $38
		LDA		#$30
		BCC		loc_B62AA
		LDA		#$28
loc_B62AA:
		CLC									; calc idx
		ADC		byte_6
		TAY
		LDA		_tangent_tbl,Y
		RTS

; =============== S U B R O U T I N E =======================================
_y_div_x_mul_8:
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
_nsub_obj_hor_move_with_wave_patternt:
		INC		_scr_vars20,X
		LDA		_scr_vars20,X
		AND		#$3F
		TAY
		LDA		_vert_delta_wave_pattern_list,Y
		STA		_obj_y_deltas,X
		JSR		_obj_move_hor_animate
		JMP		_obj_vert_anim

_vert_delta_wave_pattern_list:
		.BYTE	$E0,$E0,$E0,$E8,$E8,$E8,$F0,$F0,$F8,$F8,$F8,$F8,$F8,$F8,$F8,$00
		.BYTE	$00,$08,$08,$08,$08,$08,$08,$08,$10,$10,$18,$18,$18,$20,$20,$20
		.BYTE	$20,$20,$20,$18,$18,$18,$10,$10,$08,$08,$08,$08,$08,$08,$08,$00
		.BYTE	$00,$F8,$F8,$F8,$F8,$F8,$F8,$F8,$F0,$F0,$E8,$E8,$E8,$E0,$E0,$E0

; =============== S U B R O U T I N E =======================================
_nsub_obj_circular_x_step:
		JSR		_get_tmp_ptrE_and_idx_from_timerBs
		JSR		_switch
		.WORD	_left_to_right_step
		.WORD	_right_to_left_step
		.WORD	_left_to_left_step
		.WORD	_right_to_right_step

; =============== S U B R O U T I N E =======================================
_left_to_right_step:
		JSR		_neg_tmp_ptrE

; !FALLTHROUGH!

; =============== S U B R O U T I N E =======================================
_right_to_right_step:
		JSR		_get_low_nibble_tmp_ptrE_tbl
		STA		_obj_x_deltas,X
		RTS

; =============== S U B R O U T I N E =======================================
_left_to_left_step:
		JSR		_neg_tmp_ptrE

; !FALLTHROUGH!

; =============== S U B R O U T I N E =======================================
_right_to_left_step:
		JSR		_right_to_right_step
		JMP		_j_nsub_complement_x_deltas

; =============== S U B R O U T I N E =======================================
_nsub_obj_circular_y_step:
		JSR		_get_tmp_ptrE_and_idx_from_timerBs
		JSR		_switch
		.WORD	_up_to_up_step
		.WORD	_down_to_up_step
		.WORD	_up_to_down_step
		.WORD	_down_to_down_step

; =============== S U B R O U T I N E =======================================
_down_to_up_step:
		JSR		_neg_tmp_ptrE

; !FALLTHROUGH!

; =============== S U B R O U T I N E =======================================
_up_to_up_step:
		JSR		_get_low_nibble_tmp_ptrE_tbl
		STA		_obj_y_deltas,X
		RTS

; =============== S U B R O U T I N E =======================================
_down_to_down_step:
		JSR		_neg_tmp_ptrE

; !FALLTHROUGH!

; =============== S U B R O U T I N E =======================================
_up_to_down_step:
		JSR		_up_to_up_step
		JMP		_nsub_complement_y_deltas

; =============== S U B R O U T I N E =======================================
_get_tmp_ptrE_and_idx_from_timerBs:
		LDA		_obj_timerBs,X
		STA		_tmp_ptrE
		LSR
		LSR
		LSR
		LSR
		LSR
		AND		#$03
		RTS

; =============== S U B R O U T I N E =======================================
_neg_tmp_ptrE:
		SEC
		LDA		#$00
		SBC		_tmp_ptrE
		STA		_tmp_ptrE
		RTS

; =============== S U B R O U T I N E =======================================
_get_low_nibble_tmp_ptrE_tbl:
		LDA		_tmp_ptrE
		AND		#$1F
		TAY
		LDA		_sinus_tbl,Y
		RTS

; =============== S U B R O U T I N E =======================================
_nsub_inc_timerBs:
		INC		_obj_timerBs,X
		RTS

; =============== S U B R O U T I N E =======================================
_nsub_dex_timerBs:
		DEC		_obj_timerBs,X
		RTS

_sinus_tbl:
		.BYTE	$00,$00,$00,$01,$01,$02,$02,$03,$03,$04,$04,$05,$05,$06,$06,$07
		.BYTE	$07,$07,$08,$08,$08,$09,$09,$09,$0A,$0A,$0A,$0A,$0A,$0A,$0A,$0C

; =============== S U B R O U T I N E =======================================
_nsub_get_rand_flags:
		JSR		_rand
		JMP		_scr_flags_update

; =============== S U B R O U T I N E =======================================
_nsub_get_rand_scale3:
		LDY		#$03
		JMP		_rand_scale

; =============== S U B R O U T I N E =======================================
_nsub_get_rand_clamp3:
		JSR		_rand
		AND		#$03
		STA		_tmp_ptrE+1
		RTS

; =============== S U B R O U T I N E =======================================
_nsub_box_bonus_3prizes_shuffle:
		LDA		#$03
		BNE		_nsub_box_bonus_prizes_shuffle

; =============== S U B R O U T I N E =======================================
_nsub_box_bonus_4prizes_shuffle:
		LDA		#$04

; =============== S U B R O U T I N E =======================================
_nsub_box_bonus_prizes_shuffle:
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
_nsub_get_box_bonus_prize_from_list:
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
_scr_obj_hide:
		LDA		_scr_params,X
		ORA		#_OBJ_MODE_HIDE
		STA		_scr_params,X
		RTS

; =============== S U B R O U T I N E =======================================
_scr_obj_show:
		LDA		_scr_params,X
		AND		#[~_OBJ_MODE_HIDE&$FF]
		STA		_scr_params,X
		RTS

; =============== S U B R O U T I N E =======================================
_nsub_obj_blink_clear:
		LDA		_obj_flips,X
		AND		#[~_OBJ_BLINK&$FF]
		STA		_obj_flips,X
		RTS

; =============== S U B R O U T I N E =======================================
_nsub_obj_blink_set:
		LDA		_obj_flips,X
		ORA		#_OBJ_BLINK
		STA		_obj_flips,X
		RTS

; =============== S U B R O U T I N E =======================================
_scr_flips_04_set:
		LDA		_obj_flips,X
		ORA		#_OBJ_FLIPS04
		STA		_obj_flips,X
		RTS

; =============== S U B R O U T I N E =======================================
_scr_flips_04_clear:
		LDA		_obj_flips,X
		AND		#[~_OBJ_FLIPS04&$FF]
		STA		_obj_flips,X
		RTS

; =============== S U B R O U T I N E =======================================
_nsub_sub144:
		LDA		_obj_flips,X
		AND		#_OBJ_FLIPS04
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
_nsub_sub145:
		LDA		_scr_vars20,X
		BEQ		locret_B647E
		DEC		_scr_vars20,X
		BNE		locret_B647E
		LDA		_scr_idxCs,X
		AND		#$DF
		STA		_scr_idxCs,X
		JSR		_scr_flips_04_clear
		JSR		_nsub_obj_blink_clear
locret_B647E:
		RTS

; =============== S U B R O U T I N E =======================================
_nsub_idxBs_20_set:
		LDA		_scr_idxBs,X
		ORA		#$20
		STA		_scr_idxBs,X
		RTS

; =============== S U B R O U T I N E =======================================
_nsub_idxBs_10_clear:
		LDA		_scr_idxBs,X
		AND		#$EF
		STA		_scr_idxBs,X
		RTS

; =============== S U B R O U T I N E =======================================
_nsub_idxBs_10_set:
		LDA		_scr_idxBs,X
		ORA		#$10
		STA		_scr_idxBs,X
		RTS

; =============== S U B R O U T I N E =======================================
_nsub_idxBs_10_test:
		LDA		_scr_idxBs,X
		AND		#$10
		STA		_scr_idxBs,X
		JMP		_scr_flags_update

; =============== S U B R O U T I N E =======================================
_nsub_idxBs_10_test_clear_from_idxBs:
		LDA		_scr_idxBs,X
		JMP		_nsub_idxBs_10_test_clear

; =============== S U B R O U T I N E =======================================
_nsub_idxBs_10_test_clear_from_idxCs:
		LDA		_scr_idxCs,X
		JMP		_nsub_idxBs_10_test_clear

; =============== S U B R O U T I N E =======================================
_nsub_idxBs_10_test_clear_from_idxAs:
		LDA		_scr_idxAs,X

; !FALLTHROUGH!

; =============== S U B R O U T I N E =======================================
_nsub_idxBs_10_test_clear:
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
_nsub_obj_idxCs_C0_clear:
		LDA		_scr_idxCs,X
		AND		#$3F
		STA		_scr_idxCs,X
		RTS

; =============== S U B R O U T I N E =======================================
_nsub_obj_idxCs_80_set:
		LDA		_scr_idxCs,X
		ORA		#$80
		STA		_scr_idxCs,X
		RTS

; =============== S U B R O U T I N E =======================================
_nsub_idxCs_80_test:
		LDA		_scr_idxCs,X
		AND		#$80
		JMP		_scr_flags_update

; =============== S U B R O U T I N E =======================================
_nsub_link_to_last_obj_slot:
		LDA		_last_scr_slot_idx			; last fetched slot for previous RUN operation
		TAY
		ORA		#$50						; write down this index in current obj var with
		STA		_scr_idxCs,X				; flags to mark it as master object
		TXA
		STA		_scr_idxCs,Y				; store idx of master object to slave object var
		RTS									; now two objects are linked

; =============== S U B R O U T I N E =======================================
_nsub_last_slot_idx_to_idxBs_store:
		LDA		_last_scr_slot_idx
		STA		_scr_idxBs,X
		RTS

; =============== S U B R O U T I N E =======================================
_nsub_last_slot_idx_to_idxCs_store:
		LDA		_last_scr_slot_idx
		STA		_scr_idxCs,X
		RTS

; =============== S C R I P T ===============================================
_ssub_target_follow_down_infinite:
		SYNC
		TIMER_B_SET			$FF
		TARGET_FOLLOW
		SJMPS				_ssub_target_follow_down_infinite

; =============== S C R I P T ===============================================
_ssub_target_follow_down_to_ground:
		NJSR				_nsub_vars18_cmp20
		SBCSS				_ssub_target_follow_down_infinite
		SYNC
		TIMER_B_SET			$FF
		TARGET_FOLLOW
		NJSR				_nsub_obj_to_tile_collision_test_down
		SBCCS				_ssub_target_follow_down_to_ground
		SRET

; =============== S U B R O U T I N E =======================================
_nsub_vars18_cmp20:
		LDA		_scr_timerAs,X
		CMP		#$20
		JMP		_scr_flags_update

; =============== S C R I P T ===============================================
_ssub_suspend_forever:
		SUSPEND				$FF
		SJMPS				_ssub_suspend_forever

; =============== S C R I P T ===============================================
_ssub_anim_sync_frames32:
		ANIMATE_HV_SYNC
		ANIMATE_HV_SYNC
		ANIMATE_HV_SYNC
		ANIMATE_HV_SYNC
		ANIMATE_HV_SYNC
		ANIMATE_HV_SYNC
		ANIMATE_HV_SYNC
		ANIMATE_HV_SYNC
		ANIMATE_HV_SYNC
		ANIMATE_HV_SYNC
		ANIMATE_HV_SYNC
		ANIMATE_HV_SYNC
		ANIMATE_HV_SYNC
		ANIMATE_HV_SYNC
		ANIMATE_HV_SYNC
		ANIMATE_HV_SYNC

; !FALLTHROUGH!

; =============== S C R I P T ===============================================
_ssub_anim_sync_frames16:
		ANIMATE_HV_SYNC
		ANIMATE_HV_SYNC
		ANIMATE_HV_SYNC
		ANIMATE_HV_SYNC
		ANIMATE_HV_SYNC
		ANIMATE_HV_SYNC

; !FALLTHROUGH!

; =============== S C R I P T ===============================================
_ssub_anim_sync_frames12:
		ANIMATE_HV_SYNC
		ANIMATE_HV_SYNC

; !FALLTHROUGH!

; =============== S C R I P T ===============================================
_ssub_anim_sync_frames10:
		ANIMATE_HV_SYNC
		ANIMATE_HV_SYNC
		ANIMATE_HV_SYNC
		ANIMATE_HV_SYNC
		ANIMATE_HV_SYNC

; !FALLTHROUGH!

; =============== S C R I P T ===============================================
_ssub_anim_sync_frames3:
		ANIMATE_HV_SYNC
		ANIMATE_HV_SYNC
		ANIMATE_HV_SYNC
		SRET

; =============== S U B R O U T I N E =======================================
_nsub_obj_jump_up_anim:
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
_nsub_obj_hor_slowdown:
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
		LDA		_scr_timerAs,X
		ADC		#$01
		AND		#$3F
		STA		_scr_timerAs,X
		RTS

; =============== S U B R O U T I N E =======================================
_unref_5:
		SEC
		LDA		_scr_timerAs,X
		SBC		#$01
		AND		#$3F
		STA		_scr_timerAs,X
		RTS

; =============== S U B R O U T I N E =======================================
_scr_cmd_neg_carry:
		BCC		_scr_cmd_set_carry

; !FALLTHROUGH!

; =============== S U B R O U T I N E =======================================
_scr_cmd_clear_carry:
		CLC
		JMP		_scr_flags_update

; =============== S U B R O U T I N E =======================================
_scr_cmd_set_carry:
		SEC
		JMP		_scr_flags_update

; =============== S U B R O U T I N E =======================================
; same as following routine but with optimization to perform ground collision
; test only at the edges of the macro tile grids, this will clearly save
; a lot of calculations since we usually don't have any obstacles in the middle
; of the macro-tiles grid... not sure why the rest of the same animations
; not using the same method...
;
_obj_to_tile_grid_collision_test_down:
		CLC
		LDA		_obj_y_lo_poss,X
		ADC		byte_B0
		STA		_tmp_ptrE
		JSR		_obj_vert_anim
		CLC
		LDA		_obj_y_lo_poss,X
		ADC		byte_B0
		EOR		_tmp_ptrE
		AND		#$F0
		BEQ		_scr_cmd_clear_carry

; !FALLTHROUGH!

; =============== S U B R O U T I N E =======================================
_nsub_obj_to_tile_collision_test_down:
		LDA		_obj_hps,X
		BEQ		_scr_cmd_clear_carry
		LDY		#$A0
		JSR		_obj_to_tile_collision_test_down
		JMP		_scr_flags_update

; =============== S U B R O U T I N E =======================================
_nsub_obj_to_tile_collision_test_up:
		LDA		_obj_hps,X
		BEQ		_scr_cmd_set_carry
		JSR		_obj_to_tile_collision_test_up
		JMP		_scr_cmd_neg_carry

; =============== S U B R O U T I N E =======================================
_nsub_obj_to_tile_collision_test_hor:
		LDA		_obj_hps,X
		BEQ		_scr_cmd_set_carry
		LDA		_obj_x_deltas,X
		BEQ		_scr_cmd_set_carry
		SEC
		LDA		_obj_x_deltas,X
; TODO: we only may get here if _obj_x_deltas=0 so this branch never taken
		BEQ		loc_B65CB
; -
		BMI		loc_B65CE
		JSR		_obj_to_tile_collision_test_right
loc_B65CB:
		JMP		_scr_cmd_neg_carry
loc_B65CE:
		JSR		_obj_to_tile_collision_test_left
		JMP		_scr_cmd_neg_carry

; =============== S U B R O U T I N E =======================================
_nsub_vars21_80_load:
		LDA		#$80
		STA		_scr_vars21,X
		RTS

; =============== S U B R O U T I N E =======================================
_nsub_obj_to_obj_thrown_test_hor_concat:
		LDA		_obj_x_deltas,X
		BEQ		_scr_cmd_clear_carry
		JSR		_obj_thrown_to_obj_collision_test
		BCC		_scr_cmd_clear_carry
		LDA		_obj_x_deltas,X
		BPL		loc_B65EF
		JSR		_nsub_obj_to_obj_x_concat_right
		JMP		_scr_cmd_set_carry
loc_B65EF:
		JSR		_nsub_obj_to_obj_x_concat_left
		JMP		_scr_cmd_set_carry

; =============== S U B R O U T I N E =======================================
_nsub_obj_to_obj_thrown_test_concat_down:
		JSR		_obj_thrown_to_obj_collision_test
		BCC		loc_B65FE
		JSR		_nsub_obj_to_obj_y_concat_down
		SEC
loc_B65FE:
		JMP		_scr_cmd_neg_carry

; =============== S U B R O U T I N E =======================================
_nsub_obj_to_obj_thrown_test_concat_up:
		JSR		_nsub_vars21_80_load
		INC		_obj_y_lo_poss,X
		JSR		_obj_thrown_to_obj_collision_test
		PHP
		DEC		_obj_y_lo_poss,X
		PLP
		BCC		loc_B6619
		JSR		_nsub_obj_to_obj_y_concat_up
		TYA
		STA		_scr_vars21,X
		SEC
loc_B6619:
		JMP		_scr_flags_update

; =============== S U B R O U T I N E =======================================
_nsub_obj_to_throw_collision_test_range40:
		LDA		#$40
		BNE		_nsub_obj_to_throw_collision_test

; =============== S U B R O U T I N E =======================================
_nsub_obj_to_throw_collision_test_range20:
		LDA		#$20

; !FALLTHROUGH!

; =============== S U B R O U T I N E =======================================
_nsub_obj_to_throw_collision_test:
		STA		_tmp_ptrE
		LDY		#$0B
loc_B6626:
		LDA		_scr_params,Y
		AND		#_OBJ_TYPE_MASK
		CMP		#_OBJ_TYPE_PBULLET
		BNE		loc_B667C
		LDA		_obj_spr_libs,Y
		CMP		#_spr_lib3_idx
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
		AND		#_OBJ_FLIP_H
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
		AND		#_OBJ_FLIP_H
		BNE		loc_B667C
		LDA		_obj_x_deltas,Y
		BMI		loc_B667C
		LDA		_tmp_ptr0
		CMP		_tmp_ptrE
		BCS		loc_B667C
loc_B6677:
		JSR		_nsub_obj_to_obj_y_collision_test
		BCC		loc_B6682
loc_B667C:
		DEY
		BPL		loc_B6626
		JMP		_scr_cmd_set_carry
loc_B6682:
		TYA
		STA		_scr_idxAs,X
		JMP		_scr_cmd_clear_carry

; =============== S U B R O U T I N E =======================================
_nsub_obj_stun_from_idxAs_test:
		LDY		_scr_idxAs,X
		LDA		_obj_damages,Y
		CMP		#_OBJ_DMG_STUN
		BEQ		locret_B6698
		LDA		#$FF
		STA		_obj_hps,Y
locret_B6698:
		RTS

; =============== S U B R O U T I N E =======================================
_nsub_obj_x_range_width_test_from_players_macro_overlap_test_idx:
		SEC
		LDA		_obj_widths,X
		ADC		#$06
		BNE		_nsub_obj_x_range_test_from_players_macro_overlap_test_idx

; =============== S U B R O U T I N E =======================================
_nsub_obj_x_range30_test_from_players_macro_overlap_test_idx:
		LDA		#$30
		BNE		_nsub_obj_x_range_test_from_players_macro_overlap_test_idx

; =============== S U B R O U T I N E =======================================
_nsub_obj_x_range40_test_from_players_macro_overlap_test_idx:
		LDA		#$40
		BNE		_nsub_obj_x_range_test_from_players_macro_overlap_test_idx

; =============== S U B R O U T I N E =======================================
_nsub_obj_x_range50_test_from_players_macro_overlap_test_idx:
		LDA		#$50
		BNE		_nsub_obj_x_range_test_from_players_macro_overlap_test_idx

; =============== S U B R O U T I N E =======================================
_nsub_obj_x_range60_test_from_players_macro_overlap_test_idx:
		LDA		#$60

; !FALLTHROUGH!

; =============== S U B R O U T I N E =======================================
_nsub_obj_x_range_test_from_players_macro_overlap_test_idx:
		STA		_tmp_ptrE
		LDY		_players_macro_overlap_test_idx
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
_nsub_obj_y_collision_test_from_players_macro_overlap_test_idx:
		LDY		_players_macro_overlap_test_idx

; !FALLTHROUGH!

; =============== S U B R O U T I N E =======================================
_nsub_obj_to_obj_y_collision_test:
		SEC
		LDA		_obj_y_lo_poss,X
		SBC		_obj_y_lo_poss,Y
		STA		_tmp_ptr0
		LDA		_obj_y_hi_poss,X
		SBC		_obj_y_hi_poss,Y
		BEQ		loc_B66F5
		CMP		#$FF
		BEQ		loc_B66EC
		JMP		_scr_cmd_set_carry
loc_B66EC:
		CLC
		LDA		_tmp_ptr0
		ADC		_obj_heights,Y
		JMP		_scr_cmd_neg_carry
loc_B66F5:
		LDA		_tmp_ptr0
		CMP		_obj_heights,X
		JMP		_scr_flags_update

; =============== S U B R O U T I N E =======================================
_nsub_sub132:
		LDY		_scr_idxAs,X
		JMP		_nsub_obj_to_obj_hor_turn

; =============== S U B R O U T I N E =======================================
_nsub_sub16F:
		LDY		_players_macro_overlap_test_idx
		SEC
		LDA		_obj_x_lo_poss,X
		SBC		_obj_x_lo_poss,Y
		LDA		_obj_x_hi_poss,X
		SBC		_obj_x_hi_poss,Y
		JMP		_scr_flags_update

; =============== S U B R O U T I N E =======================================
_nsub_sub10E:
		LDA		_obj_x_hi_poss,X
		BMI		_nsub_obj_hflips_set
		BNE		_nsub_obj_hflip_clear
		LDY		_players_macro_overlap_test_idx

; !FALLTHROUGH!

; =============== S U B R O U T I N E =======================================
_nsub_obj_to_obj_hor_turn:
		LDA		_obj_x_lo_poss,Y
		CMP		_obj_x_lo_poss,X
		BCS		_nsub_obj_hflips_set

; !FALLTHROUGH!

; =============== S U B R O U T I N E =======================================
_nsub_obj_hflip_clear:
		LDA		_obj_flips,X
		AND		#[~_OBJ_FLIP_H&$FF]
		STA		_obj_flips,X
		RTS

; =============== S U B R O U T I N E =======================================
_nsub_obj_hflips_set:
		LDA		_obj_flips,X
		ORA		#_OBJ_FLIP_H
		STA		_obj_flips,X
		RTS

; =============== S U B R O U T I N E =======================================
_nsub_obj_hflip_toggle:
		LDA		_obj_flips,X
		EOR		#_OBJ_FLIP_H
		STA		_obj_flips,X
		RTS

; =============== S U B R O U T I N E =======================================
_nsub_obj_hflip_test:
		LDA		_obj_flips,X
		AND		#_OBJ_FLIP_H
		JMP		_scr_flags_update

; =============== S U B R O U T I N E =======================================
_nsub_obj_under_bg_set:
		LDA		_obj_flips,X
		ORA		#_OBJ_UNDER_BG
		STA		_obj_flips,X
		RTS

; =============== S U B R O U T I N E =======================================
_nsub_obj_hor_move_reverse:
		JSR		_nsub_obj_hflip_toggle

; !FALLTHROUGH!

; TODO, optimize me, redundant JMP

; =============== S U B R O U T I N E =======================================
_j_nsub_complement_x_deltas:
		JMP		_nsub_complement_x_deltas

; =============== S U B R O U T I N E =======================================
_nsub_complement_y_deltas:
		SEC
		LDA		#$00
		SBC		_obj_y_deltas,X
		STA		_obj_y_deltas,X
		RTS

; =============== S U B R O U T I N E =======================================
_players_damaged_state_select_A:
		LDY		_scr_idxAs,X
		LDA		_obj_x_lo_poss,X
		CMP		_obj_x_lo_poss,Y
		BCS		_nsub_obj_right_to_left_delta_toggle
		BCC		_nsub_obj_left_to_right_delta_toggle

; =============== S U B R O U T I N E =======================================
_nsub_obj_from_idxAs_hor_delta_toggle:
		LDY		_scr_idxAs,X
		LDA		_obj_x_deltas,Y
		BMI		_nsub_obj_right_to_left_delta_toggle
		BPL		_nsub_obj_left_to_right_delta_toggle

; =============== S U B R O U T I N E =======================================
_nsub_sub11B:
		LDA		_obj_flips,X
		AND		#_OBJ_FLIP_H
		BNE		_nsub_obj_right_to_left_delta_toggle
		BEQ		_nsub_obj_left_to_right_delta_toggle
		LDY		_scr_idxAs,X
		LDA		_obj_flips,Y
		STA		_obj_flips,X

; !FALLTHROUGH!

; =============== S U B R O U T I N E =======================================
_nsub_obj_hor_delta_toggle:
		LDA		_obj_flips,X
		AND		#_OBJ_FLIP_H
		BNE		_nsub_obj_left_to_right_delta_toggle

; !FALLTHROUGH!

; =============== S U B R O U T I N E =======================================
_nsub_obj_right_to_left_delta_toggle:
		LDA		_obj_x_deltas,X
		BMI		nullsub9

; !FALLTHROUGH!

; =============== S U B R O U T I N E =======================================
_nsub_complement_x_deltas:
		SEC
		LDA		#$00
		SBC		_obj_x_deltas,X
		STA		_obj_x_deltas,X
		RTS

; =============== S U B R O U T I N E =======================================
_nsub_obj_left_to_right_delta_toggle:
		LDA		_obj_x_deltas,X
		BMI		_nsub_complement_x_deltas

; !FALLTHROUGH!

; =============== S U B R O U T I N E =======================================
nullsub9:
		RTS

; =============== S U B R O U T I N E =======================================
_nsub_obj_hor_bounce7E:
		LDA		#$7E
		BNE		_nsub_obj_hor_bounce_ex

; =============== S U B R O U T I N E =======================================
_nsub_obj_hor_bounce2C:
		LDA		#$2C
		BNE		_nsub_obj_hor_bounce_ex

; =============== S U B R O U T I N E =======================================
_nsub_obj_hor_bounce13:
		LDA		#$13
		BNE		_nsub_obj_hor_bounce_ex

; =============== S U B R O U T I N E =======================================
_nsub_obj_hor_bounce0C:
		LDA		#$0C

; !FALLTHROUGH!

; =============== S U B R O U T I N E =======================================
_nsub_obj_hor_bounce_ex:
		STA		_tmp_ptr0
		LDA		_obj_flips,X
		AND		#_OBJ_FLIP_H
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
		JSR		_nsub_obj_hor_delta_toggle
		JMP		_nsub_obj_idxCs_80_set

; =============== S U B R O U T I N E =======================================
_nsub_cmp40_obj_y_lo_pos:
		LDA		#$40
		BNE		_nsub_cmp_obj_y_lo_pos

; =============== S U B R O U T I N E =======================================
_nsub_cmp50_obj_y_lo_pos:
		LDA		#$50
		BNE		_nsub_cmp_obj_y_lo_pos

; =============== S U B R O U T I N E =======================================
_nsub_cmp80_obj_y_lo_pos:
		LDA		#$80
		BNE		_nsub_cmp_obj_y_lo_pos

; =============== S U B R O U T I N E =======================================
_nsub_cmpC0_obj_y_lo_pos:
		LDA		#$C0

; !FALLTHROUGH!

; =============== S U B R O U T I N E =======================================
_nsub_cmp_obj_y_lo_pos:
		CMP		_obj_y_lo_poss,X
		JMP		_scr_flags_update

; =============== S U B R O U T I N E =======================================
_nsub_cmp08_obj_x_lo_pos:
		LDA		#$08
		BNE		_nsub_cmp_obj_x_lo_pos

; =============== S U B R O U T I N E =======================================
_nsub_cmp20_obj_x_lo_pos:
		LDA		#$20
		BNE		_nsub_cmp_obj_x_lo_pos

; =============== S U B R O U T I N E =======================================
_nsub_cmp40_obj_x_lo_pos:
		LDA		#$40
		BNE		_nsub_cmp_obj_x_lo_pos

; =============== S U B R O U T I N E =======================================
_nsub_cmp50_obj_x_lo_pos_unref:
		LDA		#$50
		BNE		_nsub_cmp_obj_x_lo_pos

; =============== S U B R O U T I N E =======================================
_nsub_cmp80_obj_x_lo_pos:
		LDA		#$80
		BNE		_nsub_cmp_obj_x_lo_pos

; =============== S U B R O U T I N E =======================================
_nsub_cmpC0_obj_x_lo_pos:
		LDA		#$C0
		BNE		_nsub_cmp_obj_x_lo_pos

; =============== S U B R O U T I N E =======================================
_nsub_cmpE0_obj_x_lo_pos:
		LDA		#$E0

; !FALLTHROUGH!

; =============== S U B R O U T I N E =======================================
_nsub_cmp_obj_x_lo_pos:
		CMP		_obj_x_lo_poss,X
		JMP		_scr_flags_update

; =============== S U B R O U T I N E =======================================
_nsub_get_obj_x_delta:
		LDA		_obj_x_deltas,X
		JMP		_scr_flags_update

; =============== S U B R O U T I N E =======================================
_nsub_get_obj_y_delta:
		LDA		_obj_y_deltas,X
		JMP		_scr_flags_update

; =============== S U B R O U T I N E =======================================
_nsub_sub135:
		LDA		_obj_x_deltas,X
		BPL		loc_B6836
		LDA		_obj_x_lo_poss,X
		CMP		#$20
		JMP		_scr_cmd_neg_carry
loc_B6836:
		LDA		_obj_x_lo_poss,X
		CMP		#$E0
		JMP		_scr_flags_update

; =============== S U B R O U T I N E =======================================
_nsub_sub149:
		LDA		_obj_x_hi_poss,X
		ORA		_obj_y_hi_poss,X
		JMP		_scr_flags_update

; =============== S U B R O U T I N E =======================================
_nsub_get_idxBs_low_nibble_from_idxAs:
		LDA		_scr_idxAs,X
		TAX

; !FALLTHROUGH!

; =============== S U B R O U T I N E =======================================
_nsub_get_idxBs_low_nibble:
		LDA		_scr_idxBs,X
		AND		#$0F
		TAY
		RTS

; =============== S U B R O U T I N E =======================================
_nsub_get_link_obj_idx_from_idxCs:
		LDA		_scr_idxCs,X
		AND		#$0F
		TAY
		RTS

; =============== S U B R O U T I N E =======================================
_nsub_get_obj3_hp:
		LDA		_obj_hps+3
		JMP		_scr_flags_update

; =============== S U B R O U T I N E =======================================
_nsub_get_obj_idxBs:
		LDA		_scr_idxBs,X
		JMP		_scr_flags_update

; =============== S U B R O U T I N E =======================================
_nsub_get_obj_hp:
		LDA		_obj_hps,X
		JMP		_scr_flags_update

; =============== S C R I P T ===============================================
_ssub_wait_obj_hps_turns_zero:
		NJSR_SYNC			_nsub_get_obj_hp
		SBNES				_ssub_wait_obj_hps_turns_zero
		SRET

; =============== S U B R O U T I N E =======================================
_nsub_obj_linked_idxCs_follow:
		JSR		_nsub_get_link_obj_idx_from_idxCs
		LDA		_obj_x_lo_poss,Y
		STA		_obj_x_lo_poss,X
		LDA		_obj_x_hi_poss,Y
		STA		_obj_x_hi_poss,X
		LDA		_obj_flips,Y
		AND		#_OBJ_FLIP_V
		BEQ		loc_B6895
		LDA		_obj_y_lo_poss,Y
		STA		_obj_y_lo_poss,X
		LDA		_obj_y_hi_poss,Y
		STA		_obj_y_hi_poss,X
		RTS
loc_B6895:
		CLC
		LDA		_obj_y_lo_poss,Y
		SBC		_obj_heights,Y
		STA		_obj_y_lo_poss,X
		LDA		_obj_y_hi_poss,Y
		SBC		#$00
		STA		_obj_y_hi_poss,X
		RTS

; =============== S U B R O U T I N E =======================================
_players_state06_C:
		JSR		_nsub_get_idxBs_low_nibble
		LDA		_obj_flips,X
		AND		#[~[_OBJ_FLIP_V|_OBJ_FLIP_H|_OBJ_UNDER_BG]&$FF]
		STA		_obj_flips,X
		LDA		_scr_params,X
		AND		#_OBJ_TYPE_MASK
		CMP		#_OBJ_TYPE_PLAYER
		BEQ		loc_B68C0
		CMP		#_OBJ_TYPE_ENEMY
		BNE		loc_B68CA
loc_B68C0:
		LDA		_obj_flips,Y
		EOR		#_OBJ_FLIP_V|_OBJ_FLIP_H
		AND		#_OBJ_FLIP_V|_OBJ_FLIP_H|_OBJ_UNDER_BG
		JMP		loc_B68CF
loc_B68CA:
		LDA		_obj_flips,Y
		AND		#_OBJ_UNDER_BG
loc_B68CF:
		ORA		_obj_flips,X
		STA		_obj_flips,X
		LDA		_obj_x_lo_poss,Y
		STA		_obj_x_lo_poss,X
		LDA		_obj_x_hi_poss,Y
		STA		_obj_x_hi_poss,X
		CLC
		LDA		_obj_y_lo_poss,Y
		SBC		_obj_heights,Y
		STA		_obj_y_lo_poss,X
		LDA		_obj_y_hi_poss,Y
		SBC		#$00
		STA		_obj_y_hi_poss,X
		RTS

; =============== S U B R O U T I N E =======================================
_nsub_obj_y_lo_maskF0:
		LDA		_obj_y_lo_poss,X
		AND		#$F0
		STA		_obj_y_lo_poss,X
		LDA		#$00
		STA		_obj_y_accel,X
		RTS

; =============== S U B R O U T I N E =======================================
_nsub_obj_stun_no_extra_flips_init:
		LDA		_obj_flips,X
		AND		#[~[_OBJ_UNDER_BG|_OBJ_FLIPS08|_OBJ_FLIPS04]&$FF]
		STA		_obj_flips,X
		LDA		#_OBJ_DMG_STUN
		STA		_obj_damages,X
		JMP		_nsub_obj_idxCs_80_set

; =============== S U B R O U T I N E =======================================
_nsub_obj_type_change_auto:
		LDA		#_OBJ_TYPE_AUTO
		BNE		_nsub_obj_type_change

; =============== S U B R O U T I N E =======================================
_nsub_obj_type_change_pbullet:
		LDA		#_OBJ_TYPE_PBULLET
		BNE		_nsub_obj_type_change

; =============== S U B R O U T I N E =======================================
_nsub_obj_type_change_ebullet:
		LDA		#_OBJ_TYPE_EBULLET
		BNE		_nsub_obj_type_change

; =============== S U B R O U T I N E =======================================
_nsub_obj_type_change_solid_no_damage_idxBs_20_clear:
		LDA		_scr_idxBs,X
		AND		#$DF
		STA		_scr_idxBs,X

; !FALLTHROUGH!

; =============== S U B R O U T I N E =======================================
_nsub_obj_type_change_solid_no_damage:
		LDA		#_OBJ_DMG_NONE
		STA		_obj_damages,X

; !FALLTHROUGH!

; =============== S U B R O U T I N E =======================================
_nsub_obj_type_change_solid:
		LDA		#_OBJ_TYPE_SOLID
		BNE		_nsub_obj_type_change

; =============== S U B R O U T I N E =======================================
_nsub_obj_type_change_grab:
		LDA		#_OBJ_TYPE_TRIGGER
		BNE		_nsub_obj_type_change

; =============== S U B R O U T I N E =======================================
_nsub_obj_type_change_ball:
		LDA		#_OBJ_TYPE_BALL
		BNE		_nsub_obj_type_change

; =============== S U B R O U T I N E =======================================
_nsub_obj_type_change_stunA:
		LDA		#_OBJ_TYPE_STUNA

; !FALLTHROUGH!

; =============== S U B R O U T I N E =======================================
_nsub_obj_type_change:
		STA		_tmp_ptr0
		LDA		_scr_params,X
		AND		#_OBJ_MODE_MASK
		ORA		_tmp_ptr0
		STA		_scr_params,X
		RTS

; =============== S C R I P T ===============================================
_ssub_obj_show_wait_for_idxCs_80_set:
		SPRITE_ON

; !FALLTHROUGH!

; =============== S C R I P T ===============================================
_ssub_wait_for_idxCs_80_set:
		NJSR_SYNC			_nsub_idxCs_80_test
		SBEQS				_ssub_wait_for_idxCs_80_set
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
_nsub_sub146:
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
_nsub_sub147:
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
_nsub_sub11E:
		LDX		#$00
		LDY		#$0B
loc_B6A4A:
		LDA		_scr_params,Y
		AND		#_OBJ_TYPE_MASK
		CMP		#_OBJ_TYPE_ENEMY
		BNE		loc_B6A5B
		LDA		_obj_spr_libs,Y
		CMP		#_spr_lib9_idx
		BNE		loc_B6A5B
		INX
loc_B6A5B:
		DEY
		BPL		loc_B6A4A
		CPX		#$00
		JMP		_scr_flags_update

; =============== S U B R O U T I N E =======================================
_nsub_grabable_obj_num_00_cmp:
		LDA		#$00
		BEQ		_nsub_grabable_obj_num_cmp

; =============== S U B R O U T I N E =======================================
_nsub_grabable_obj_num_01_cmp:
		LDA		#$01
		BNE		_nsub_grabable_obj_num_cmp

; =============== S U B R O U T I N E =======================================
_nsub_grabable_obj_num_02_cmp:
		LDA		#$02

; !FALLTHROUGH!

; =============== S U B R O U T I N E =======================================
_nsub_grabable_obj_num_cmp:
		STA		_tmp_ptr0
		LDX		#$00
		LDY		#$0B
loc_B6A73:
		LDA		_scr_params,Y
		AND		#_OBJ_TYPE_MASK
		BEQ		loc_B6A82
		LDA		_scr_params,Y
		AND		#_OBJ_MODE_GRABABLE
		BEQ		loc_B6A82
		INX
loc_B6A82:
		DEY
		BPL		loc_B6A73
		CPX		_tmp_ptr0
		JMP		_scr_flags_update

; =============== S C R I P T ===============================================
_obj_scr_20A_anim_anim03_sync:
		SJSRS				_obj_scr_20A_anim_anim_sync
		LOOP_B				$03,_obj_scr_20A_anim_anim03_sync
		SRET

; =============== S C R I P T ===============================================
_obj_scr_20A_anim_anim04_sync:
		SJSRS				_obj_scr_20A_anim_anim_sync
		LOOP_B				$04,_obj_scr_20A_anim_anim03_sync
		SRET

; =============== S C R I P T ===============================================
_obj_scr_20A_anim_anim06_sync:
		SJSRS				_obj_scr_20A_anim_anim_sync
		LOOP_B				$06,_obj_scr_20A_anim_anim06_sync
		SRET

; =============== S C R I P T ===============================================
_obj_scr_20A_anim_anim08_sync:
		SJSRS				_obj_scr_20A_anim_anim_sync
		LOOP_B				$08,_obj_scr_20A_anim_anim08_sync
		SRET

; =============== S C R I P T ===============================================
_obj_scr_20A_anim_anim0A_sync:
		SJSRS				_obj_scr_20A_anim_anim_sync
		LOOP_B				$0A,_obj_scr_20A_anim_anim0A_sync
		SRET

; =============== S C R I P T ===============================================
_obj_scr_20A_anim_anim10_sync:
		SJSRS				_obj_scr_20A_anim_anim_sync
		LOOP_B				$10,_obj_scr_20A_anim_anim10_sync
		SRET

; =============== S C R I P T ===============================================
_obj_scr_20A_anim_anim_sync:
		ANIMATE_HV_SYNC

; !FALLTHROUGH!

; =============== S C R I P T ===============================================
_obj_scr_20A_anim:
		NJSR				_nsub_sub144
		SBEQS				byte_B6AC6
		APU_SE_SET			_apu_mus2F
		NJSR				_nsub_obj_blink_set
byte_B6AC6:
		NJSR				_nsub_sub145
		SRET

; =============== S C R I P T ===============================================
_obj_scr_20B:
		SJSRS				_ssub_B6AD1
		SBCCS				_obj_scr_20B
		SRET

; =============== S C R I P T   R O U T I N E ===============================
_ssub_B6AD1:
		SYNC
		SJSRS				_obj_scr_20A_anim
		NJSR				_obj_move_hor_animate
		NJSR				_nsub_obj_jump_up_anim
		NJSR				_nsub_get_obj_y_delta
		SBPLS				byte_B6AE8
		NJSR				_obj_vert_anim
		NJSR				_scr_cmd_clear_carry
		SRET
byte_B6AE8:
		NJSR				_obj_to_tile_grid_collision_test_down
		SBCCS				byte_B6AF0
		DELTA_Y_SET			$00
byte_B6AF0:
		SRET

; =============== S C R I P T ===============================================
_obj_scr_common_small_boss_destr:
		APU_SE_SET			_apu_mus70
		DELTA_X_SET			$F0
		DELTA_Y_SET			$C0
		NJSR				_nsub_obj_from_idxAs_hor_delta_toggle
		NJSR				_nsub_obj_blink_set
byte_B6AFD:
		ANIMATE_HV_SYNC
		NJSR				_nsub_obj_jump_up_anim
		NJSR				_nsub_obj_cmp160_y_pos
		SBMIS				byte_B6AFD

; !FALLTHROUGH!

; =============== S C R I P T ===============================================
_ssub_stage_complete_flag_set:
		STORE				$80,_stage_flags
		SJMP				_ssub_suspend_forever

; =============== S U B R O U T I N E =======================================
_nsub_obj_cmp160_y_pos:
		SEC
		LDA		_obj_y_lo_poss,X
		SBC		#$60
		LDA		_obj_y_hi_poss,X
		SBC		#$01
		JMP		_scr_flags_update

; =============== S U B R O U T I N E =======================================
_nsub_sub14F:
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
		JSR		_sys_room_cur_meta_data_read
		JSR		_sys_screen_cur_meta_draw
		CLC
		LDA		_tmpA
		ADC		#$10
		STA		_tmpA
		JSR		_sys_room_cur_meta_data_read
		JSR		_sys_screen_cur_meta_draw
		JMP		_mmc1_prg_restore

; =============== S C R I P T   R O U T I N E ===============================
; draws all macro-tiles patch lines from _tmp_ptr4B till the end
; of the data
;
_ssub_macro_patch_draw:
		NJSR_SYNC			_nsub_macro_patch_line_draw
		SBNES				_ssub_macro_patch_draw
		SRET

; =============== S U B R O U T I N E =======================================
_far_sys_screen_cur_meta_draw:
		STA		_tmpA
		STY		_tmpC
		LDA		#<[_sys_screen_cur_meta_draw]
		LDY		#>[_sys_screen_cur_meta_draw]
		JSR		_farcall
		RTS

; =============== S U B R O U T I N E =======================================
; draws macro-tiles patch from _tmp_ptr4B one line at once,
; return Z=1 if all patch lines are displayed (reached 00 in stream)
; return Z=0 if more lines left
;
_nsub_macro_patch_line_draw:
		LDA		_cur_prg_bank
		PHA
		LDA		#$03
		JSR		_mmc1_prg_set
		LDA		#$00
		STA		byte_97
		LDY		byte_97
#if BUGFIXES==1
		INC		byte_97
#endif
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
		JSR		_sys_screen_cur_meta_draw
loc_B6B8F:
		INC		_tmpA
		DEC		byte_95
		BNE		loc_B6B79
		LDA		#$FF
loc_B6B97:
		JSR		_scr_flags_update
		ADDWB	byte_97,_tmp_ptr4B
		JMP		_mmc1_prg_restore

; =============== S U B R O U T I N E =======================================
_far_players_state16_E:
		LDA		_cur_prg_bank
		PHA
		LDA		#$02
		JSR		_mmc1_prg_set
		JSR		_players_state16_E
		JMP		_mmc1_prg_restore

; =============== S U B R O U T I N E =======================================
_far_players_default_state_select_G:
		LDA		_cur_prg_bank
		PHA
		LDA		#$02
		JSR		_mmc1_prg_set
		JSR		_players_default_state_select_G
		JSR		_scr_flags_update
		JMP		_mmc1_prg_restore

; =============== S U B R O U T I N E =======================================
_nsub_players_obj_ride_x_delta_sync:
		LDY		#$01
loc_B6BCB:
		TXA
		CMP		_scr_vars21,Y
		BNE		loc_B6BD7
		LDA		_obj_x_deltas,X
		STA		_players_x_deltas,Y
loc_B6BD7:
		DEY
		BPL		loc_B6BCB
		RTS

; =============== S U B R O U T I N E =======================================
_nsub_players_obj_ride_y_sync:
		LDY		#$01
loc_B6BDD:
		TXA
		CMP		_scr_vars21,Y
		BNE		loc_B6BE6
		JSR		_nsub_obj_y_adjust_by_height
loc_B6BE6:
		DEY
		BPL		loc_B6BDD
		RTS

; =============== S U B R O U T I N E =======================================
_nsub_obj_y_adjust_by_height_from_idxAs:
		LDY		_scr_idxAs,X
		BMI		nullsub4

; =============== S U B R O U T I N E =======================================
_nsub_obj_y_adjust_by_height:
		CLC
		LDA		_obj_y_lo_poss,X
		SBC		_obj_heights,X
		STA		_obj_y_lo_poss,Y

; !FALLTHROUGH!

; =============== S U B R O U T I N E =======================================
nullsub4:
		RTS

; =============== S U B R O U T I N E =======================================
_nsub_obj_to_obj_jump_up_test:
		LDY		#$0B							; for all 12 objects
		TXA										; move current obj idx to A
loc_B6BFD:
		CMP		_scr_vars21,Y					; compare cur obj idx with
		BEQ		loc_B6C06						; obj link idx value
		DEY
		BPL		loc_B6BFD						; return object idx with identical
		CLC										; value C=1 or 0 and C=0 if no such
loc_B6C06:
		TYA
		STA		_scr_idxAs,X
		JMP		_scr_flags_update				; store and flush flags

; =============== S C R I P T ===============================================
_obj_scr_20D:
		NJSR_SYNC			_nsub_obj_to_obj_jump_up_test
		SBCSS				_obj_scr_20D
byte_B6C13:
		NJSR_SYNC			_nsub_obj_to_obj_jump_up_test
		SBCCS				byte_B6C13
		SRET

; =============== S U B R O U T I N E =======================================
_nsub_inc_players_lives_from_idxAs:
		LDY		_scr_idxAs,X

; =============== S U B R O U T I N E =======================================
_nsub_inc_players_lives:
		LDA		_players_lives,Y
		CMP		#$0A
		BCS		locret_B6C2A
		CLC
		ADC		#$01
		STA		_players_lives,Y
locret_B6C2A:
		RTS

; =============== S U B R O U T I N E =======================================
_nsub_increment_players_hps:
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
_nsub_set_def_max_hps_from_idxAs:
		LDY		_scr_idxAs,X
		LDA		_players_def_max_hps,Y
		STA		_obj_hps,Y
		RTS

; =============== S U B R O U T I N E =======================================
_nsub_player_exit_right_with_flip_set:
		LDY		_scr_idxAs,X
		LDA		_obj_flips,Y
		ORA		#_OBJ_FLIP_H|_OBJ_FLIPS08|_OBJ_FLIPS04
		STA		_obj_flips,Y

; !FALLTHROUGH!

; =============== S U B R O U T I N E =======================================
_nsub_player_exit_right_set:
		LDA		#$20
		JMP		_nsub_player_exit_set

; =============== S U B R O U T I N E =======================================
_nsub_player_exit_left_with_flip_set:
		LDY		_scr_idxAs,X
		LDA		_obj_flips,Y
		AND		#[~_OBJ_FLIP_H&$FF]
		ORA		#_OBJ_FLIPS08|_OBJ_FLIPS04
		STA		_obj_flips,Y
		LDA		#$E0

; !FALLTHROUGH!

; =============== S U B R O U T I N E =======================================
_nsub_player_exit_set:
		STA		_obj_x_deltas,Y
		LDA		#$04
		STA		_players_vars0A,Y
		LDA		#$40
		STA		_players_vars07,Y
		LDA		#$14
		STA		_players_states,Y
		RTS

; =============== S U B R O U T I N E =======================================
_nsub_obj_player_from_idxAs_05_state_compare:
		LDY		_scr_idxAs,X
		LDA		_players_states,Y
		CMP		#$05
		JMP		_scr_flags_update

; =============== S U B R O U T I N E =======================================
_nsub_inc_stage_room_idx:
		INC		_stage_room_idx
		RTS

; =============== S U B R O U T I N E =======================================
_nsub_sub153:
		LDY		_players_macro_overlap_test_idx
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
		JSR		_nsub_sub153_A
		STA		_obj_x_deltas,X
		SEC
		LDA		_tmp_ptr2
		SBC		_obj_y_lo_poss,X
		TAY
		LDA		_tmp_ptr2+1
		SBC		_obj_y_hi_poss,X
		JSR		_nsub_sub153_A
		STA		_obj_y_deltas,X
		JSR		_nsub_obj_hflips_set
		LDA		_obj_x_deltas,X
		BPL		loc_B6CD2
		JSR		_nsub_obj_hflip_clear
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
_nsub_sub153_A:
		STY		byte_6
		LSR
		ROR		byte_6
		LDA		byte_6
		RTS

; =============== S U B R O U T I N E =======================================
_nsub_sub16B:
		LDA		_players_lives
		BEQ		loc_B6CF4
		LDA		_players_lives+1
loc_B6CF4:
		JMP		_scr_flags_update

; =============== S U B R O U T I N E =======================================
_nsub_sub15A:
		LDY		#$01
loc_B6CF9:
		LDA		_players_states,Y
		CMP		#$04
		BNE		loc_B6D03
		JSR		_nsub_player_exit_right_set
loc_B6D03:
		DEY
		BPL		loc_B6CF9
		RTS

; =============== S U B R O U T I N E =======================================
_nsub_basket_game_basket_collision_test:
		LDY		byte_E0							; read stored previously idx of
		LDA		_obj_y_lo_poss,X				; main basket object
		CMP		#$45
		BCS		loc_B6D14						; first test if ball above some level
		INC		_obj_timerBs,X					; if not, set flag
		RTS
loc_B6D14:
		CMP		_obj_y_lo_poss,Y				; also test if we still above the basket
		BCS		loc_B6D61
		LDA		_obj_timerBs,X					; if flag clear, we already did this test, skip
		BEQ		locret_B6D68
		LDA		_obj_y_deltas,X					; test if ball's goes down
		BEQ		locret_B6D68
		BMI		locret_B6D68
		JSR		_obj_to_obj_collision_test		; after all these tests, do sys collision test routine
		BCC		locret_B6D68
		LDA		#$8B							; if passed, select what player thrown this ball
		STA		_tmp_ptr44
		LDA		#$20
		STA		_tmp_ptr44+1					; select corresponding scores ppu offset
		JSR		_nsub_get_idxBs_low_nibble
		CPY		#$00
		BEQ		loc_B6D41
		LDA		#$9D
		STA		_tmp_ptr44
		LDA		#$20
		STA		_tmp_ptr44+1
loc_B6D41:
		TYA										; now increment score
		TAX
		LDA		_tmp_bonus_games_scores,X
		CMP		#$0A
		BCS		locret_B6D68
		STA		_tmp_ptr0
		INC		_tmp_bonus_games_scores,X
		SEC
		LDA		_tmp_ptr44
		SBC		_tmp_ptr0
		STA		_tmp_ptr44
		LDA		#<[byte_B6D69]					; draw dingle [*] tile on the HUD
		STA		_tmp_ptr0
		LDA		#>[byte_B6D69]
		STA		_tmp_ptr0+1
		LDA		#$01
		JSR		_tlm_queue
loc_B6D61:
		LDX		_scr_idx
		LDA		#$00
		STA		_obj_timerBs,X					; reset flags
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
_obj_scr_s_manager_loop:
		LDX		_scr_idx
		LDA		_scr_params,X
		AND		#_OBJ_TYPE_MASK
		BEQ		loc_B6DCF
		LDY		#<[loc_B6DA4-1]
		LDX		#>[loc_B6DA4-1]
; TODO: optimization notes: loop for all 12 object, every type of objects
; need its own bank switching. players switches to bank 2, enemies and other
; scripts to bank 4, then most of active objects draws a sprite which
; switches to bank 5. even if in the mmc1 bank switch routine they used some
; sort of optimization to aviod setting the same bank twice, in this manager
; we see al banks in sequence mostly different and alterate all the time
; 2 5 4 5 2 5 4 4 5 etc...
; this may take a lot of time. to avoid this, we need to combine object types
; by its bank, two players should be done first, then all bank 4 objects, then
; separate loop should draw the sprites with just one bank 5 setting.
;
; ALSO: _players_manager handling players operation only for _scr_idx = 0.
; half of the work performed once per frame, both players handlers executed
; at once sequentially inside players_manager. so we don't have to call it
; as common object handler here and may put it before this loop starts!
; -
		JSR		_switch_param_ret
		.WORD	0
		.WORD	_far_prg4_scr_exec_priority	;	_OBJ_TYPE_AUTO
		.WORD	_far_prg2_players_manager		;	_OBJ_TYPE_PLAYER
		.WORD	_far_prg4_scr_exec_priority	;	_OBJ_TYPE_PBULLET
		.WORD	_far_prg4_scr_exec_priority	;	_OBJ_TYPE_STUNA
		.WORD	_far_prg4_scr_exec_priority	;	_OBJ_TYPE_BALL
		.WORD	_far_prg4_enemy_manager				;	_OBJ_TYPE_ENEMY
		.WORD	_far_prg4_scr_exec_priority	;	_OBJ_TYPE_EBULLET
		.WORD	_far_prg4_scr_exec_priority	;	_OBJ_TYPE_STUNB
		.WORD	_far_prg4_scr_exec_priority	;	_OBJ_TYPE_SOLID
		.WORD	_far_prg4_scr_exec_priority	;	_OBJ_TYPE_TRIGGER
loc_B6DA4:
		LDX		_scr_idx
		LDA		_scr_params,X
		AND		#_OBJ_TYPE_MASK
		BEQ		loc_B6DCF
		JSR		_obj_out_of_screen_test
		LDA		_obj_flips,X
		AND		#_OBJ_FLIPS08
		BNE		loc_B6DBA
		JSR		_obj_global_shift
loc_B6DBA:
		LDA		_scr_params,X
		BMI		loc_B6DCF
		LDA		_obj_flips,X
		AND		#_OBJ_BLINK
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
		BCC		_obj_scr_s_manager_loop
		RTS

; =============== S U B R O U T I N E =======================================
_far_prg2_players_manager:
		LDA		#$02
		JSR		_mmc1_prg_set
		JMP		_players_manager

; =============== S U B R O U T I N E =======================================
_far_prg4_enemy_manager:
		LDX		_scr_idx
		LDA		_obj_hps,X
		BEQ		loc_B6DF9
		LDA		_obj_flips,X
		AND		#_OBJ_FLIPS04
		ORA		_obj_x_hi_poss,X
		ORA		_obj_y_hi_poss,X
		BNE		loc_B6DF9
		LDA		_obj_heights,X
		BNE		loc_B6DFC
loc_B6DF9:
		JMP		_far_prg4_scr_exec_priority
loc_B6DFC:
		LDY		#$0B
loc_B6DFE:
		LDA		_scr_params,Y
		AND		#_OBJ_TYPE_MASK
		CMP		#_OBJ_TYPE_PLAYER
		BCC		loc_B6E20
		CMP		#_OBJ_TYPE_SOLID
		BEQ		loc_B6E0F
		CMP		#_OBJ_TYPE_ENEMY
		BCS		loc_B6E20
loc_B6E0F:
		LDA		_obj_flips,Y
		AND		#_OBJ_FLIPS04
		BNE		loc_B6E20
		LDA		_obj_damages,Y
		BEQ		loc_B6E20
		JSR		_obj_to_obj_collision_test
		BCS		loc_B6E25
loc_B6E20:
		DEY
		BPL		loc_B6DFE
		BMI		_far_prg4_scr_exec_priority
loc_B6E25:
		LDA		_obj_damages,Y
		BPL		loc_B6E4A
		LDA		#_OBJ_DMG_KILL
		STA		_obj_damages,Y
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
		STA		_obj_damages,Y
		JMP		_far_prg4_scr_exec_priority
loc_B6E4A:
		SEC
		LDA		_obj_hps,X
		SBC		_obj_damages,Y
		STA		_obj_hps,X
		BCS		loc_B6E5B
		LDA		#$00
		STA		_obj_hps,X
loc_B6E5B:
		LDA		_obj_damages,Y
		CMP		#_OBJ_DMG_STUN
		BEQ		loc_B6E6A
		LDA		#$00
		STA		_obj_hps,Y
		STA		_obj_damages,Y
loc_B6E6A:
		JSR		_scr_flips_04_set
		LDA		_obj_spr_libs,X
		CMP		#_spr_lib8_idx
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

; !FALLTHROUGH!

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
		LDA		_obj_heights,Y
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
		ADC		_obj_heights,Y
		RTS
loc_B6EFC:
		LDA		_tmp_ptr2
		CMP		_obj_heights,X
		BEQ		loc_B6F05
		BCS		loc_B6F07
loc_B6F05:
		SEC
		RTS
loc_B6F07:
		CLC
		RTS

; =============== S U B R O U T I N E =======================================
_obj_thrown_to_obj_collision_test:
		LDX		_scr_idx
		LDA		_obj_hps,X
		BEQ		loc_B6F86
		LDA		_obj_flips,X
		AND		#_OBJ_FLIPS08
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
		LDA		_obj_damages,X
		CMP		#_OBJ_DMG_STUN
		BNE		loc_B6F50
		LDA		_scr_params,Y
		AND		#_OBJ_TYPE_MASK
		CMP		#_OBJ_TYPE_BALL
		BEQ		loc_B6F7E
		CMP		#_OBJ_TYPE_SOLID
		BEQ		loc_B6F7E
		BNE		loc_B6F83
loc_B6F50:
		LDA		_scr_params,Y
		AND		#_OBJ_TYPE_MASK
		CMP		#_OBJ_TYPE_PLAYER
		BCC		loc_B6F83
		BEQ		loc_B6F77
		CMP		#_OBJ_TYPE_BALL
		BEQ		loc_B6F7E
		CMP		#_OBJ_TYPE_SOLID
		BEQ		loc_B6F7E
		CMP		#_OBJ_TYPE_ENEMY
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
		AND		#_OBJ_FLIPS08
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
		AND		#_OBJ_TYPE_MASK
		CMP		#_OBJ_TYPE_BALL
		BNE		loc_B6FA9
		CPY		#_OBJ_TYPE_PLAYER
		BCS		loc_B6FA9
		LDA		_obj_flips,Y
		AND		#_OBJ_FLIPS04
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
		AND		#_OBJ_TYPE_MASK
		BEQ		loc_B6FFD
		INX
		CPX		#$0C
		BCC		loc_B6FF0
		RTS
loc_B6FFD:
		CLC
loc_B6FFE:
		STX		_last_scr_slot_idx
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
		ORA		#_OBJ_MODE_HIDE
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
		STA		_obj_heights,X
		STA		_obj_hps,X
		STA		_obj_damages,X
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
		LDA		#_OBJ_MODE_HIDE
		STA		_scr_params,X
		STA		_scr_vars21,X
		JSR		_nsub_obj_disable_from_idxCs_40_flag
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
_nsub_stun_sparkles_obj_scr_run:
		LDA		_scr_idxCs,X
		ORA		#$20
		STA		_scr_idxCs,X
		LDY		#_OBJ_TYPE_AUTO
		JSR		_scr_load_param
		.WORD	_obj_scr_stun_sparkles
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
_nsub_obj_disable_from_idxCs_40_flag:
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
		LDA		#_OBJ_MODE_HIDE|_OBJ_TYPE_DISABLED
		STA		_scr_params,Y
		STA		_scr_vars21,Y
locret_B7134:
		RTS

; =============== S U B R O U T I N E =======================================
_nsub_obj_to_obj_x_concat_right:
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
_nsub_obj_to_obj_x_concat_left:
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
_nsub_obj_to_obj_y_concat_up:
		CLC
		LDA		_obj_y_lo_poss,Y
		SBC		_obj_heights,Y
		STA		_obj_y_lo_poss,X
		LDA		_obj_y_hi_poss,Y
		SBC		#$00
		STA		_obj_y_hi_poss,X
		RTS

; =============== S U B R O U T I N E =======================================
_nsub_obj_to_obj_y_concat_down:
		SEC
		LDA		_obj_y_lo_poss,Y
		ADC		_obj_heights,X
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
		SBC		_obj_heights,X
		STA		_tmpC
		LDA		_tmpC+1
		SBC		#$00
		STA		_tmpC+1
loc_B71DE:
		LDX		_spr_buf_pos
		LDY		#$00
.spr_fetch_cmd_loop:
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
.spr_fetch_data_loop:
		LDA		byte_7							; off screen, clip
		ORA		byte_9
		BEQ		.spr_fetch_data
		INY
		INY
		BNE		.spr_clip_data
.spr_fetch_data:
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
.spr_clip_data:
		LDA		_tmp_ptr4
		BMI		loc_B7298
		LDA		_tmp_ptr2+1
		AND		#$40
		BNE		loc_B7288
; TODO: optimize with JADDWB/JSUBWB
		ADDWB	#$08,byte_6
		JMP		loc_B72BB
loc_B7288:
		SUBWB	#$08,byte_6
		JMP		loc_B72BB
loc_B7298:
		LDA		_tmp_ptr2+1
		AND		#$80
		BNE		loc_B72AE
		ADDWB	#$08,byte_8
		JMP		loc_B72BB
loc_B72AE:
		SUBWB	#$08,byte_8
loc_B72BB:
		DEC		_tmp_ptr4
		LDA		_tmp_ptr4
		AND		#$7F
		BEQ		loc_B72C6
		JMP		.spr_fetch_data_loop
loc_B72C6:
		JMP		.spr_fetch_cmd_loop

; =============== S C R I P T ===============================================
_scr_capcom_logo_unused:
		SUSPEND				$78
		STORE				$00,_main_sub_idx
		SJMP				_ssub_fade_out

; =============== S C R I P T ===============================================
_scr_license:
		SUSPEND				$78
		STORE				$01,_main_sub_idx
		SJMP				_ssub_fade_out

; =============== S C R I P T ===============================================
_scr_intro:
		POS_X_SET			$C0,$00
		POS_Y_SET			$C0,$FF
		SRUN				_OBJ_TYPE_AUTO,_obj_scr_170
		NJSR				_nsub_link_to_last_obj_slot
		SRUN				_OBJ_TYPE_AUTO,_obj_scr_171
		NJSR				_nsub_link_to_last_obj_slot
		SRUN				_OBJ_TYPE_AUTO,_obj_scr_172
		NJSR				_nsub_link_to_last_obj_slot
		SJSRS				_ssub_B7360
		DELTA_X_SET			$00
		DELTA_Y_SET			$20
byte_B72FD:
		SJSRS				_ssub_B7352
		LOOP_A				$80,byte_B72FD
		DELTA_X_SET			$EA
		DELTA_Y_SET			$EA
byte_B7308:
		SJSRS				_ssub_B7352
		LOOP_A				$60,byte_B7308
		DELTA_X_SET			$20
		DELTA_Y_SET			$00
byte_B7313:
		SJSRS				_ssub_B7352
		LOOP_A				$40,byte_B7313
		DELTA_X_SET			$EA
		DELTA_Y_SET			$16
byte_B731E:
		SJSRS				_ssub_B7352
		LOOP_A				$30,byte_B731E
		DELTA_X_SET			$E0
		DELTA_Y_SET			$00
byte_B7329:
		SJSRS				_ssub_B7352
		LOOP_A				$80,byte_B7329
		APU_SE_SET			_apu_mus74
		STORE				$00,_ppu_scroll_nt_hor
		POS_Y_SET			$68,$00
		DELTA_X_SET			$20
byte_B733B:
		SJSRS				_ssub_B7352
		LOOP_A				$86,byte_B733B
		DELTA_X_SET			$C0
byte_B7344:
		SJSRS				_ssub_B7352
		LOOP_A				$10,byte_B7344
		APU_SE_SET			_apu_mus73
		SUSPEND				$3C
		SJMPS				byte_B7358

; =============== S C R I P T   R O U T I N E ===============================
_ssub_B7352:
		ANIMATE_HV_SYNC
		PADS_TEST			_PAD0_PRESS,_PAD_ANY,byte_B735F
byte_B7358:
		STORE				$02,_main_sub_idx
		SJMP				_ssub_fade_out
byte_B735F:
		SRET

; =============== S C R I P T   R O U T I N E ===============================
_ssub_B7360:
		NJSR				_nsub_obj_idxCs_C0_clear
		NJSR				_nsub_obj_under_bg_set
		SIZE_SET			$20,$20
		SPR_IDX_SET			_spr_lib0_00
		SPRITE_ON
		SRET

; =============== S C R I P T ===============================================
_obj_scr_170:
		FLIP_H_ON
		SJMPS				byte_B7373

; =============== S C R I P T ===============================================
_obj_scr_172:
		FLIP_H_ON

; =============== S C R I P T ===============================================
_obj_scr_171:
		FLIP_V_ON
byte_B7373:
		SJSRS				_ssub_B7360
byte_B7376:
		NJSR_SYNC			_nsub_sub17A
		SJMPS				byte_B7376

; =============== S U B R O U T I N E =======================================
_nsub_sub17A:
		JSR		_nsub_get_link_obj_idx_from_idxCs
		LDA		_obj_x_lo_poss,Y
		STA		_obj_x_lo_poss,X
		LDA		_obj_x_hi_poss,Y
		STA		_obj_x_hi_poss,X
		LDA		_obj_flips,X
		AND		#_OBJ_FLIP_V
		BNE		loc_B739F
		LDA		_obj_y_lo_poss,Y
		STA		_obj_y_lo_poss,X
		LDA		_obj_y_hi_poss,Y
		STA		_obj_y_hi_poss,X
		RTS
loc_B739F:
		CLC
		LDA		_obj_y_lo_poss,Y
		ADC		_obj_heights,Y
		STA		_obj_y_lo_poss,X
		LDA		_obj_y_hi_poss,Y
		ADC		#$00
		STA		_obj_y_hi_poss,X
		RTS

; =============== S C R I P T ===============================================
_scr_title:
		POS_X_SET			$C0,$00
		POS_Y_SET			$6F,$00
		SPR_IDX_SET			_spr_lib0_01
		SPRITE_ON
		NJSR				_game_vars_init
byte_B73BE:
		SYNC
		PADS_TEST			_PAD0_PRESS,_PAD_START,byte_B73BE
		APU_SE_SET			_apu_mus32
		NJSR_SYNC			_title_clear_menu_area
		NJSR_SYNC			_scr_players_num_menu_draw
		SJSRS				_ssub_title_menu_common_handler
		SSWITCH				_tmp49
		SCASE				_scr_1_player_select
		SCASE				_scr_2_players_select
_scr_1_player_select:
		NJSR_SYNC			_scr_players_sel_menu_draw
		SRUN				_OBJ_TYPE_AUTO,_obj_scr_173
		SRUN				_OBJ_TYPE_AUTO,_obj_scr_174
		SJSRS				_ssub_title_menu_common_handler
		NJSR				_scr_single_player_apply
_scr_2_players_select:
		NJSR				_players_vars_init
		STORE				$03,_main_sub_idx
		SJMP				_ssub_fade_out

; =============== S C R I P T   R O U T I N E ===============================
_ssub_title_menu_common_handler:
		NJSR				_menu_init
		MENU_CURSOR_DRAW	_menu_title_player_num
byte_B73F7:
		SYNC
		PADS_TEST			_PAD0_PRESS,_PAD_UP|_PAD_DOWN|_PAD_SELECT,byte_B7405
		APU_SE_SET			_apu_mus31
		NJSR				_title_player_select_pal_toggle
		MENU_CURSOR_DRAW	_menu_title_player_num
byte_B7405:
		PADS_TEST			_PAD0_PRESS,_PAD_START|_PAD_A,byte_B73F7
		APU_SE_SET			_apu_mus32
		SRET

; =============== S C R I P T ===============================================
_obj_scr_173:
		POS_X_SET			$30,$00
		SPR_IDX_SET			_spr_lib0_07
		SJMPS				byte_B741A

; =============== S C R I P T ===============================================
_obj_scr_174:
		POS_X_SET			$B0,$00
		SPR_IDX_SET			_spr_lib0_08
byte_B741A:
		POS_Y_SET			$BA,$00
		SPRITE_ON
		SJMP				_ssub_suspend_forever

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
		STY		_tmp4A
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
_scr_game_over:
		POS_X_SET			$80,$00
		POS_Y_SET			$60,$00
		DELTA_Y_SET			$04
		SPR_IDX_SET			_spr_lib0_14
		SPRITE_ON
byte_B748B:
		ANIMATE_HV_SYNC
		LOOP_A				$80,byte_B748B
		SUSPEND				$78
		NJSR				_get_continues
		SBEQS				byte_B74DD
		STORE				$08,_main_sub_idx
		SJMP				_ssub_fade_out

; =============== S C R I P T ===============================================
_scr_continue:
		SRUN				_OBJ_TYPE_AUTO,_obj_scr_175
		NJSR				_nsub_last_slot_idx_to_idxBs_store
		SRUN				_OBJ_TYPE_AUTO,_obj_scr_176
		NJSR				_nsub_last_slot_idx_to_idxCs_store
		NJSR				_menu_init
		NJSR				_continues_draw
byte_B74B3:
		MENU_VERT_INPUT		$00,$02
		MENU_CURSOR_DRAW	_menu_data02
		SYNC
		PADS_TEST			_PAD0_PRESS,_PAD_A,byte_B74B3
		APU_SE_SET			_apu_mus32
		NJSR				_nsub_idxBs_10_test_clear_from_idxBs
		NJSR				_nsub_idxBs_10_test_clear_from_idxCs
		SSWITCH				_tmp49
		SCASE				byte_B74CE
		SCASE				byte_B74DD
byte_B74CE:
		NJSR				_continues_decrement
		NJSR				_players_vars_init
		SUSPEND				$78
		STORE				$04,_main_sub_idx
		SJMP				_ssub_fade_out
byte_B74DD:
		SUSPEND				$3C
		STORE				$02,_main_sub_idx
		SJMP				_ssub_fade_out

; =============== S C R I P T ===============================================
_obj_scr_175:
		HP_SET				$00
		POS_X_SET			$70,$00
		SJMPS				byte_B74F3

; =============== S C R I P T ===============================================
; WARNING, both players has the same spr idxes, to switch them only lib idx
; change is used, so this and some others subs uses the same common
; idxes, but since we macrosify them here, if you change one of the libs
; other will be broken. do not change indexes or do it syncronously!
;
_obj_scr_176:
		HP_SET				$01
		POS_X_SET			$90,$00
byte_B74F3:
		NJSR				_nsub_player_spr_lib_init
		SBEQ				_ssub_suspend_forever
		POS_Y_SET			$A0,$00
		SIZE_SET			$06,$16
		NJSR				_nsub_idxBs_10_set
		NJSR				_nsub_stun_sparkles_obj_scr_run
		FLIPS_SET			$60
		SPR_IDX_SET			_spr_lib1_0D
		SPRITE_ON
byte_B750A:
		NJSR_SYNC			_nsub_idxBs_10_test
		SBNES				byte_B750A
		NJSR				_nsub_obj_disable_from_idxCs_40_flag
		SSWITCH				_tmp49
		SCASE				byte_B751A
		SCASE				byte_B752A
byte_B751A:
		SJSRS				_ssub_B7547
		SUSPEND				$05
		DELTA_X_SET			$20
		DELTA_Y_SET			$00
		SJSRS				_ssub_B7533
		SJSRS				_ssub_B7533
		KILL
byte_B752A:
		SPR_IDX_SET			_spr_lib1_0C
		DELTA_X_SET			$F0
		DELTA_Y_SET			$DF
		SJMP				_ssub_y_parabolic_delta_infinite_anim_sync

; =============== S C R I P T   R O U T I N E ===============================
; WARNING, the same case. common lib for chip and dale sprites, uses both the same
; sprite indexes, but different library indexes... macroses will threat them as
; lib1 indexes if something is changes!
;
_ssub_B7533:
		SPR_IDX_SET			_spr_lib1_01
		SJSR				_ssub_anim_sync_frames10
		SPR_IDX_SET			_spr_lib1_02
		SJSR				_ssub_anim_sync_frames10
		SPR_IDX_SET			_spr_lib1_03
		SJSR				_ssub_anim_sync_frames10
		SPR_IDX_SET			_spr_lib1_02
		SJMP				_ssub_anim_sync_frames10

; =============== S C R I P T   R O U T I N E ===============================
; WARNING, the same case. common lib for chip and dale sprites, uses both the same
; sprite indexes, but different library indexes... macroses will threat them as
; lib1 indexes if something is changes!
;
_ssub_B7547:
		DELTA_Y_SET			$DF
		SPR_IDX_SET			_spr_lib1_05
byte_B754B:
		NJSR				_nsub_obj_jump_up_anim
		NJSR_SYNC			_obj_vert_anim
		LOOP_A				$15,byte_B754B

; !FALLTHROUGH!

; =============== S C R I P T   R O U T I N E ===============================
_ssub_B7555:
		SPR_IDX_SET			_spr_lib1_04
		SUSPEND				$0A
		SPR_IDX_SET			_spr_lib1_00
		SRET

_menu_data02:
		.BYTE	$01,$02
		.BYTE	$40,$3E
		.WORD	$256A
		.WORD	$25AA

; =============== S U B R O U T I N E =======================================
_nsub_player_spr_lib_init:
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
_scr_stage_complete:
		SJSRS				_ssub_B75FB
		NJSR				_get_apu_achnls_active_flags
		SBNES				_scr_stage_complete
byte_B75D9:
		SJSRS				_ssub_B75FB
		NJSR				_nsub_sub101
		SBNES				byte_B75D9
byte_B75E2:
		NJSR_SYNC			_stage_complete_info_insert
		NJSR				_nsub_sub102
		PADS_TEST			_PAD0_PRESS,_PAD_ANY,byte_B75E2
		STORE				$06,_main_sub_idx
		SRUN				_OBJ_TYPE_AUTO,_ssub_fade_out
byte_B75F5:
		NJSR_SYNC			_stage_complete_info_insert
		SJMPS				byte_B75F5

; =============== S C R I P T   R O U T I N E ===============================
_ssub_B75FB:
		NJSR_SYNC			_stage_complete_info_insert
		LOOP_B				$04,_ssub_B75FB
		SRET

; =============== S U B R O U T I N E =======================================
_get_apu_achnls_active_flags:
		LDA		_apu_active_chnls_flags
		AND		#$0F
		JMP		_scr_flags_update

; =============== S U B R O U T I N E =======================================
_nsub_sub101:
		LDX		#$01
loc_B760C:
		LDA		_players_rr_ptss,X
		BEQ		loc_B7641
		DEC		_players_rr_ptss,X
		INC		_tmp47,X
		LDA		#_apu_mus38_idx
		JSR		_apu_se_req
		LDA		_tmp47,X
		CMP		byte_E0
		BNE		loc_B7641
		INC		_players_rr_lvls,X
		LDA		#_apu_mus20_idx
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
		LDA		#_apu_mus20_idx
		JSR		_apu_mus_req
loc_B7641:
		DEX
		BPL		loc_B760C
		LDA		_players_rr_ptss
		ORA		_players_rr_ptss+1
		JMP		_scr_flags_update

; =============== S U B R O U T I N E =======================================
_nsub_sub102:
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
_obj_scr_16D:
		FLIP_H_ON
		SPRITE_ON
		POS_X_SET			$38,$00
		POS_Y_SET			$A0,$00
		SPR_LIB_SET			_spr_lib1
		SPR_IDX_SET			_spr_lib1_1B
		SJSR				_ssub_idxBs_10_set_clear_wait
		SJSR				_ssub_6B73A
		SJSR				_ssub_6B73A

; =============== S C R I P T ===============================================
_obj_scr_16E:
		FLIP_H_ON
		SPRITE_ON
		POS_X_SET			$28,$00
		POS_Y_SET			$90,$00
		SPR_LIB_SET			_spr_lib2
		SPR_IDX_SET			_spr_lib2_1B
		SJSR				_ssub_idxBs_10_set_clear_wait
		SJSR				_ssub_6B75D
		SJSR				_ssub_6B73A
		SJSR				_ssub_6B750
		SJSR				_ssub_6B73A

; =============== S C R I P T ===============================================
_obj_scr_16F:
		FLIP_H_ON
		SPRITE_ON
		POS_X_SET			$70,$00
		POS_Y_SET			$C0,$00
		SPR_IDX_SET			_spr_lib0_1C
		TIMER_B_SET			$00
		SJSR				_ssub_monterey_static_draw
		SJSR				_ssub_6B7D1
		SJSR				_ssub_monterey_static_draw

; =============== S C R I P T ===============================================
_obj_scr_16C:
		POS_X_SET			$A0,$00
		POS_Y_SET			$70,$00
		SPRITE_ON
		DELTA_X_SET			$F8
byte_B76BD:
		SPR_IDX_SET			_spr_lib0_3D
		SJSR				_ssub_anim_sync_frames10
		SPR_IDX_SET			_spr_lib0_3E
		SJSR				_ssub_anim_sync_frames10
		LOOP_A				$08,byte_B76BD
		NJSR				_nsub_obj_hor_move_reverse
		SJMPS				byte_B76BD

; =============== S C R I P T ===============================================
_scr_cutscene0A:
		POS_Y_SET			$C0,$00
		SRUN				_OBJ_TYPE_AUTO,_obj_scr_178
		TIMER_B_SET			$00
		SRUN				_OBJ_TYPE_AUTO,_obj_scr_179
		NJSR				_nsub_cut_last_obj_slot_store
		TIMER_B_SET			$01
		SRUN				_OBJ_TYPE_AUTO,_obj_scr_17A
		NJSR_SYNC			_nsub_cut_last_obj_slot_store
		TIMER_B_SET			$00
		SJSR				_ssub_cut_char_idxBs_10_clear_set_test
		MSG_DISPLAY			_msg3F,_apu_mus56
		SJSR				_ssub_cut_char_idxBs_10_clear_set_test
		MSG_DISPLAY			_msg40,_apu_mus5D
		MSG_WAIT
		TIMER_B_SET			$01
		MSG_DISPLAY			_msg41,_apu_mus57
		SJSR				_ssub_cut_char_idxBs_10_clear_set_test
		TIMER_B_SET			$00
		MSG_DISPLAY			_msg42,_apu_mus56
		SJSR				_ssub_cut_char_idxBs_10_clear_set_test
		MSG_DISPLAY			_msg43,_apu_mus5D
		MSG_WAIT
		TIMER_B_SET			$01
		MSG_DISPLAY			_msg44,_apu_mus57
		SJSR				_ssub_cut_char_idxBs_10_clear_set_test
		TIMER_B_SET			$00
		MSG_DISPLAY			_msg45,_apu_mus56
		SJSR				_ssub_cut_char_idxBs_10_clear_set_test
		SJMP				_ssub_delayed_next_cutscene

; =============== S C R I P T ===============================================
_obj_scr_179:
		SPR_LIB_SET			_spr_lib1
		SPR_IDX_SET			_spr_lib1_16
		POS_X_SET			$70,$00
		FLIP_H_ON
		SPRITE_ON
		SRUN				_OBJ_TYPE_AUTO,_obj_scr_17B
		NJSR				_nsub_last_slot_idx_to_idxBs_store
		SUSPEND				$B4
		NJSR				_nsub_idxBs_10_test_clear_from_idxBs
		SPR_IDX_SET			_spr_lib1_09
		SUSPEND				$04
		SPR_IDX_SET			_spr_lib1_0A
		SUSPEND				$10
		SPR_IDX_SET			_spr_lib1_00
		SUSPEND				$3C
		SJSR				_ssub_idxBs_10_set_clear_wait
		SJSR				_ssub_6B73A
		SJSR				_ssub_6B744
		SJSR				_ssub_6B744
		SJMP				_ssub_suspend_forever

; =============== S C R I P T ===============================================
_obj_scr_17A:
		SPR_LIB_SET			_spr_lib2
		SPR_IDX_SET			_spr_lib2_00
		POS_X_SET			$50,$00
		FLIP_H_ON
		SPRITE_ON
		SJSR				_ssub_idxBs_10_set_clear_wait
		SJSR				_ssub_6B73A
		SJSR				_ssub_6B73A
		SJMP				_ssub_suspend_forever

; =============== S C R I P T ===============================================
_obj_scr_178:
		SPR_IDX_SET			_spr_lib0_42
		POS_X_SET			$88,$00
		SPRITE_ON
		SJMP				_ssub_suspend_forever

; =============== S C R I P T ===============================================
_obj_scr_17B:
		POS_Y_MOVE			$EA
		SPR_IDX_SET			_spr_lib0_43
		SPRITE_ON
		SJSR				_ssub_idxBs_10_set_clear_wait
		DELTA_X_SET			$0D
		DELTA_Y_SET			$E8
byte_B7781:
		ANIMATE_HV_SYNC
		DELTA_Y_INC
		DELTA_Y_INC
		LOOP_A				$1E,byte_B7781
		SJMP				_ssub_suspend_forever

; =============== S C R I P T ===============================================
_scr_cutscene0B:
		NJSR				_nsub_sub174
		STORE				$00,_tmp49
		NJSR				_extra_stage_name0_load
		SSWITCH				_tmp_ptrE+1
		SCASE				byte_B77A0
		SCASE				byte_B7828
		SCASE				byte_B7899
		SCASE				byte_B78C8
byte_B77A0:
		TIMER_B_SET			$00
		SRUN				_OBJ_TYPE_AUTO,_obj_scr_17C
		NJSR				_nsub_cut_last_obj_slot_store
		TIMER_B_SET			$01
		SRUN				_OBJ_TYPE_AUTO,_obj_scr_17D
		NJSR				_nsub_cut_last_obj_slot_store
		TIMER_B_SET			$02
		SRUN				_OBJ_TYPE_AUTO,_obj_scr_17E
		NJSR_SYNC			_nsub_cut_last_obj_slot_store
		SUSPEND				$3C
		MSG_DISPLAY			_msg46,_apu_mus5D
		MSG_WAIT
		TIMER_B_SET			$01
		MSG_DISPLAY			_msg47,_apu_mus57
		SJSR				_ssub_cut_char_idxBs_10_clear_set_test
		MSG_DISPLAY			_msg48,_apu_mus5D
		MSG_WAIT
		MSG_DISPLAY			_msg49,_apu_mus57
		SJSR				_ssub_cut_char_idxBs_10_clear_set_test
		TIMER_B_SET			$02
byte_B77D9:
		MSG_DISPLAY			_msg4A,_apu_mus59
		SJSR				_ssub_cut_char_idxBs_10_clear_set_test
		SJSRS				_ssub_B780A
		MSG_DISPLAY			_msg4B,_apu_mus59
		SJSR				_ssub_cut_char_idxBs_10_clear_set_test
		SJSR				_ssub_6BC7C
		SSWITCH				_tmp47
		SCASE				byte_B77FE
		SCASE				byte_B77F4
byte_B77F4:
		STORE				$01,byte_E1
		NJSR_SYNC			_nsub_cut_char_idxBs_10_clear
		SJMPS				byte_B77D9
byte_B77FE:
		TIMER_B_SET			$00
		MSG_DISPLAY			_msg4C,_apu_mus56
		SJSR				_ssub_cut_char_idxBs_10_clear_set_test
		SJMP				_ssub_delayed_ingame_start

; =============== S C R I P T   R O U T I N E ===============================
_ssub_B780A:
		NJSR				_menu_init
		MENU_CURSOR_DRAW	_menu_data03
byte_B7810:
		SYNC
		NJSR				_nsub_sub102
		NJSR				_nsub_sub176
		SBCCS				byte_B781D
		MENU_CURSOR_DRAW	_menu_data03
byte_B781D:
		PADS_TEST			_PAD0_PRESS,_PAD_A,byte_B7810
		APU_SE_SET			_apu_mus32
		NJSR				_extra_stage_name0_load
		SRET
byte_B7828:
		SRUN				_OBJ_TYPE_AUTO,_obj_scr_17F
		TIMER_B_SET			$01
		SRUN				_OBJ_TYPE_AUTO,_obj_scr_180
		NJSR				_nsub_cut_last_obj_slot_store
		TIMER_B_SET			$03
		SRUN				_OBJ_TYPE_AUTO,_obj_scr_181
		NJSR_SYNC			_nsub_cut_last_obj_slot_store
		SUSPEND				$3C
byte_B7840:
		STORE				$00,_tmp49
		NJSR				_extra_stage_name0_load
		NJSR				_extra_stage_name1_load
		MSG_DISPLAY			_msg4D,_apu_mus58
		SJSR				_ssub_cut_char_idxBs_10_clear_set_test
		SJSRS				_ssub_B787B
		MSG_DISPLAY			_msg1B,_apu_mus58
		SJSR				_ssub_cut_char_idxBs_10_clear_set_test
		SJSR				_ssub_6BC7C
		SSWITCH				_tmp47
		SCASE				byte_B786F
		SCASE				byte_B7865
byte_B7865:
		STORE				$01,byte_E1
		NJSR_SYNC			_nsub_cut_char_idxBs_10_clear
		SJMPS				byte_B7840
byte_B786F:
		TIMER_B_SET			$01
		MSG_DISPLAY			_msg4E,_apu_mus57
		SJSR				_ssub_cut_char_idxBs_10_clear_set_test
		SJMP				_ssub_delayed_ingame_start

; =============== S C R I P T   R O U T I N E ===============================
_ssub_B787B:
		NJSR				_menu_init
		MENU_CURSOR_DRAW	_menu_data04
byte_B7881:
		SYNC
		NJSR				_nsub_sub102
		NJSR				_nsub_sub177
		SBCCS				byte_B788E
		MENU_CURSOR_DRAW	_menu_data04
byte_B788E:
		PADS_TEST			_PAD0_PRESS,_PAD_A,byte_B7881
		APU_SE_SET			_apu_mus32
		NJSR				_extra_stage_name0_load
		SRET
byte_B7899:
		SRUN				_OBJ_TYPE_AUTO,_obj_scr_cutscene_skip_wait
		SRUN				_OBJ_TYPE_AUTO,_obj_scr_182
		TIMER_B_SET			$00
		SRUN				_OBJ_TYPE_AUTO,_obj_scr_183
		NJSR				_nsub_cut_last_obj_slot_store
		TIMER_B_SET			$02
		SRUN				_OBJ_TYPE_AUTO,_obj_scr_184
		NJSR_SYNC			_nsub_cut_last_obj_slot_store
		SUSPEND				$3C
		MSG_DISPLAY			_msg4F,_apu_mus59
		SJSR				_ssub_cut_char_idxBs_10_clear_set_test
		TIMER_B_SET			$00
		MSG_DISPLAY			_msg50,_apu_mus56
		SJSR				_ssub_cut_char_idxBs_10_clear_set_test
		SJMP				_ssub_delayed_ingame_start
byte_B78C8:
		NJSR				_nsub_sub178

; =============== S U B R O U T I N E =======================================
_nsub_sub178:
		LDA		#$08
		STA		_stage
		LDA		#$0C
		STA		_cutscene_idx
		JMP		_MAIN_START

; =============== S U B R O U T I N E =======================================
_nsub_sub174:
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
_nsub_sub176:
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
_nsub_sub177:
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
		ADC		#_Clock_Tower					; starting index for words in library
		LDX		#$00
		JMP		_extra_stage_name_load

; =============== S U B R O U T I N E =======================================
_extra_stage_name1_load:
		CLC
		LDA		byte_437
		ADC		#_Clock_Tower
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
_obj_scr_17C:
		SJSRS				_ssub_B79E1
		SJSR				_ssub_idxBs_10_set_clear_wait
		SJSR				_ssub_6B744

; =============== S C R I P T ===============================================
_obj_scr_17D:
		SJSRS				_ssub_B79ED
		SJSR				_ssub_idxBs_10_set_clear_wait
		SJSR				_ssub_6B73A
		SJSR				_ssub_6B73A

; =============== S C R I P T ===============================================
_obj_scr_17E:
		SJSR				_ssub_B79FA
		SJSR				_ssub_monterey_static_draw
byte_B7975:
		SJSR				_ssub_6B7D1
		SJSR				_ssub_6B7D1
		SJMPS				byte_B7975

; =============== S C R I P T ===============================================
_obj_scr_17F:
		SJSRS				_ssub_B79E1
		SJMP				_ssub_suspend_forever

; =============== S C R I P T ===============================================
_obj_scr_180:
		SJSRS				_ssub_B79ED
		SJSR				_ssub_idxBs_10_set_clear_wait
		SJSR				_ssub_6B73A

; =============== S C R I P T ===============================================
_obj_scr_181:
		SPR_IDX_SET			_spr_lib0_28
		TIMER_B_SET			$09
		POS_X_SET			$18,$00
		POS_Y_SET			$A0,$00
		FLIP_H_ON
		SPRITE_ON
		SRUN				_OBJ_TYPE_AUTO,_obj_scr_185
		SJSR				_ssub_gadget_static_draw
byte_B79A0:
		SJSR				_ssub_6B797
		SJSR				_ssub_6B797
		SJMPS				byte_B79A0

; =============== S C R I P T ===============================================
_obj_scr_185:
		POS_X_MOVE			$0B
		POS_Y_MOVE			$F0
byte_B79AD:
		SPR_IDX_SET			_spr_lib0_3F
		SPRITE_ON
		SJMP				_ssub_suspend_forever

; =============== S C R I P T ===============================================
_obj_scr_183:
		SJSRS				_ssub_B79E1
		SJSR				_ssub_idxBs_10_set_clear_wait
		SJSR				_ssub_6B744

; =============== S C R I P T ===============================================
_obj_scr_182:
		SJSRS				_ssub_B79ED
		SJSR				_ssub_idxBs_10_set_clear_wait

; =============== S C R I P T ===============================================
_obj_scr_184:
		SJSRS				_ssub_B79FA
		SRUN				_OBJ_TYPE_AUTO,_obj_scr_186
		TIMER_B_SET			$06
		SJSR				_ssub_monterey_static_draw
		HP_SET				$06
		DAMAGE_SET			$09
		SJSR				_ssub_monterey_talk_draw
		TIMER_B_SET			$06
		SJSR				_ssub_monterey_static_draw

; =============== S C R I P T ===============================================
_obj_scr_186:
		POS_X_MOVE			$14
		POS_Y_MOVE			$E5
		SJMPS				byte_B79AD

; =============== S C R I P T   R O U T I N E ===============================
_ssub_B79E1:
		SPR_LIB_SET			_spr_lib1
		SPR_IDX_SET			_spr_lib1_1B
		POS_X_SET			$80,$00
		POS_Y_SET			$D0,$00
		SPRITE_ON
		SRET

; =============== S C R I P T   R O U T I N E ===============================
_ssub_B79ED:
		SPR_LIB_SET			_spr_lib2
		SPR_IDX_SET			_spr_lib2_1B
		POS_X_SET			$38,$00
		POS_Y_SET			$C0,$00
		FLIP_H_ON
		SPRITE_ON
		SRET

; =============== S C R I P T   R O U T I N E ===============================
_ssub_B79FA:
		SPR_IDX_SET			_spr_lib0_1C
		TIMER_B_SET			$00
		POS_X_SET			$18,$00
		POS_Y_SET			$A0,$00
		FLIP_H_ON
		SPRITE_ON
		SRET

; =============== S C R I P T ===============================================
_scr_cutscene0C:
		SRUN				_OBJ_TYPE_AUTO,_obj_scr_cutscene_skip_wait
		SRUN				_OBJ_TYPE_AUTO,_obj_scr_187
		SRUN				_OBJ_TYPE_AUTO,_obj_scr_188
		TIMER_B_SET			$01
		SRUN				_OBJ_TYPE_AUTO,_obj_scr_189
		NJSR				_nsub_cut_last_obj_slot_store
		TIMER_B_SET			$03
		SRUN				_OBJ_TYPE_AUTO,_obj_scr_18A
		NJSR				_nsub_cut_last_obj_slot_store
		TIMER_B_SET			$04
		SRUN				_OBJ_TYPE_AUTO,_obj_scr_18B
		NJSR				_nsub_cut_last_obj_slot_store
		TIMER_B_SET			$00
		SRUN				_OBJ_TYPE_AUTO,_obj_scr_18C
		NJSR_SYNC			_nsub_cut_last_obj_slot_store
		SUSPEND				$3C
		MSG_DISPLAY			_msg51,_apu_mus56
		SJSR				_ssub_cut_char_idxBs_10_clear_set_test
		TIMER_B_SET			$03
		MSG_DISPLAY			_msg52,_apu_mus58
		SJSR				_ssub_cut_char_idxBs_10_clear_set_test
		TIMER_B_SET			$04
		NJSR_SYNC			_nsub_cut_char_idxBs_10_clear
		MSG_DISPLAY			_msg53,_apu_mus5A
		MSG_WAIT
		SJSR				_ssub_cut_char_idxBs_10_clear_set_test
		TIMER_B_SET			$03
		NJSR				_nsub_cut_char_idxBs_10_clear
		TIMER_B_SET			$04
		SJSR				_ssub_cut_char_idxBs_10_clear_set_test
		TIMER_B_SET			$00
		MSG_DISPLAY			_msg54,_apu_mus56
		SJSR				_ssub_cut_char_idxBs_10_clear_set_test
		APU_SE_SET			_apu_mus4F
		NJSR				_nsub_sub103
		SJSR				_ssub_6BECE
		SUSPEND				$10
		SJMP				_ssub_next_cutscene

; =============== S C R I P T ===============================================
_obj_scr_18C:
		SPR_LIB_SET			_spr_lib1
		SPR_IDX_SET			_spr_lib1_1B
		POS_X_SET			$70,$00
		POS_Y_SET			$C0,$00
		FLIP_H_ON
		SPRITE_ON
		SJSR				_ssub_idxBs_10_set_clear_wait
		FLIP_H_OFF
		SJSR				_ssub_6B744
		SJSR				_ssub_6B73A
		FLIP_H_ON
		SJMPS				byte_B7A9F

; =============== S C R I P T ===============================================
_obj_scr_189:
		SPR_LIB_SET			_spr_lib2
		SPR_IDX_SET			_spr_lib2_1B
		POS_X_SET			$58,$00
		POS_Y_SET			$C0,$00
		FLIP_H_ON
		SPRITE_ON
		SJSR				_ssub_idxBs_10_set_clear_wait
byte_B7A9F:
		DELTA_X_SET			$10
byte_B7AA1:
		SJSR				_ssub_B7533
		SJMPS				byte_B7AA1

; =============== S C R I P T ===============================================
_obj_scr_18A:
		SPR_IDX_SET			_spr_lib0_28
		TIMER_B_SET			$09
		POS_X_SET			$10,$00
		POS_Y_SET			$A0,$00
		FLIP_H_ON
		SPRITE_ON
		SRUN				_OBJ_TYPE_AUTO,_obj_scr_18D
		NJSR				_nsub_link_to_last_obj_slot
		SJSR				_ssub_gadget_static_draw
		SJSR				_ssub_6B797
		NJSR				_nsub_obj_disable_from_idxCs_40_flag
		TIMER_B_SET			$00
		SJSR				_ssub_gadget_static_draw

; =============== S C R I P T ===============================================
_obj_scr_18B:
		POS_X_SET			$80,$00
		POS_Y_SET			$84,$00
		FLIP_H_ON
		SPRITE_ON
		SJSR				_ssub_zipper_hover_animate
		FLIP_H_OFF
		SJSR				_ssub_zipper_hover_animate
		DELTA_X_SET			$F0
byte_B7AD9:
		SJSR				_ssub_6B825
		LOOP_A				$10,byte_B7AD9
		SJSR				_ssub_zipper_hover_animate
		FLIP_H_ON
		DELTA_X_SET			$10
byte_B7AE6:
		SJSR				_ssub_6B825
		LOOP_A				$06,byte_B7AE6
		SRUN				_OBJ_TYPE_AUTO,_obj_scr_18E
		SJSR				_ssub_zipper_hover_animate

; =============== S C R I P T ===============================================
_obj_scr_187:
		POS_X_SET			$28,$00
		SJMPS				byte_B7B0E

; =============== S C R I P T ===============================================
_obj_scr_188:
		POS_X_SET			$38,$00
		SJMPS				byte_B7B0E

; =============== S C R I P T ===============================================
_obj_scr_18D:
		POS_X_MOVE			$0B
		POS_Y_MOVE			$F0
		SPR_IDX_SET			_spr_lib0_3F
		SPRITE_ON
		SJMP				_ssub_suspend_forever

; =============== S C R I P T ===============================================
_obj_scr_18E:
		FLIP_H_OFF
		POS_X_SET			$48,$00
byte_B7B0E:
		POS_Y_SET			$64,$00
		SPR_IDX_SET			_spr_lib0_40
		SPRITE_ON
		SJMP				_ssub_suspend_forever

; =============== S U B R O U T I N E =======================================
_nsub_sub103:
		LDA		#$91
		STA		_tmp_ptr44
		LDA		#$22
		STA		_tmp_ptr44+1
		LDA		#<[_rect222]
		LDY		#>[_rect222]
		JMP		_far_prg3_rect_draw

; =============== S C R I P T ===============================================
_scr_cutscene0D:
		SRUN				_OBJ_TYPE_AUTO,_obj_scr_cutscene_skip_wait
		TIMER_B_SET			$00
		SRUN				_OBJ_TYPE_AUTO,_obj_scr_18F
		NJSR				_nsub_cut_last_obj_slot_store
		TIMER_B_SET			$01
		SRUN				_OBJ_TYPE_AUTO,_obj_scr_190
		NJSR				_nsub_cut_last_obj_slot_store
		TIMER_B_SET			$03
		SRUN				_OBJ_TYPE_AUTO,_obj_scr_191
		NJSR				_nsub_cut_last_obj_slot_store
		TIMER_B_SET			$04
		SRUN				_OBJ_TYPE_AUTO,_obj_scr_192
		NJSR_SYNC			_nsub_cut_last_obj_slot_store
		SUSPEND				$3C
		TIMER_B_SET			$00
		MSG_DISPLAY			_msg55,_apu_mus56
		SJSR				_ssub_cut_char_idxBs_10_clear_set_test
		TIMER_B_SET			$01
		MSG_DISPLAY			_msg56,_apu_mus57
		SJSR				_ssub_cut_char_idxBs_10_clear_set_test
		TIMER_B_SET			$03
		MSG_DISPLAY			_msg57,_apu_mus58
		SJSR				_ssub_cut_char_idxBs_10_clear_set_test
		TIMER_B_SET			$00
		MSG_DISPLAY			_msg58,_apu_mus56
		SJSR				_ssub_cut_char_idxBs_10_clear_set_test
		MSG_DISPLAY			_msg59,_apu_mus56
		NJSR				_nsub_cut_char_idxBs_10_clear
		TIMER_B_SET			$01
		NJSR				_nsub_cut_char_idxBs_10_clear
		TIMER_B_SET			$03
		NJSR_SYNC			_nsub_cut_char_idxBs_10_clear
		SJSR				_ssub_wait_for_wnd_msg_is_over
		SJMP				_ssub_delayed_ingame_start

; =============== S C R I P T ===============================================
_obj_scr_18F:
		SPR_LIB_SET			_spr_lib1
		SPR_IDX_SET			_spr_lib1_1B
		POS_X_SET			$70,$00
		POS_Y_SET			$C0,$00
		FLIP_H_ON
		SPRITE_ON
		SJSR				_ssub_idxBs_10_set_clear_wait
		SJSR				_ssub_6B73A
		SJMPS				byte_B7BAF

; =============== S C R I P T ===============================================
_obj_scr_190:
		SPR_LIB_SET			_spr_lib2
		SPR_IDX_SET			_spr_lib2_1B
		POS_X_SET			$58,$00
		POS_Y_SET			$C0,$00
		FLIP_H_ON
		SPRITE_ON
		SJSR				_ssub_idxBs_10_set_clear_wait
byte_B7BAF:
		SJSR				_ssub_6B744
		SJSR				_ssub_6B744

; =============== S C R I P T ===============================================
_obj_scr_191:
		SPR_IDX_SET			_spr_lib0_28
		TIMER_B_SET			$00
		POS_X_SET			$10,$00
		POS_Y_SET			$A0,$00
		FLIP_H_ON
		SPRITE_ON
		SJSR				_ssub_gadget_static_draw
		SJSR				_ssub_6B797
		SJSR				_ssub_6B797

; =============== S C R I P T ===============================================
_obj_scr_192:
		POS_X_SET			$60,$00
		POS_Y_SET			$68,$00
		FLIP_H_ON
		SPRITE_ON
byte_B7BD2:
		SJSR				_ssub_zipper_hover_animate
		SJMPS				byte_B7BD2

; =============== S C R I P T ===============================================
_scr_cutscene0E:
		SRUN				_OBJ_TYPE_AUTO,_obj_scr_cutscene_skip_wait
		TIMER_B_SET			$05
		SRUN				_OBJ_TYPE_AUTO,_obj_scr_193
		NJSR				_nsub_cut_last_obj_slot_store
		TIMER_B_SET			$01
		SRUN				_OBJ_TYPE_AUTO,_obj_scr_194
		NJSR				_nsub_cut_last_obj_slot_store
		TIMER_B_SET			$00
		SRUN				_OBJ_TYPE_AUTO,_obj_scr_195
		NJSR_SYNC			_nsub_cut_last_obj_slot_store
		SUSPEND				$60
		MSG_DISPLAY			_msg5A,_apu_mus5D
		MSG_WAIT
		MSG_DISPLAY			_msg5B,_apu_mus56
		SJSR				_ssub_cut_char_idxBs_10_clear_set_test
		TIMER_B_SET			$01
		MSG_DISPLAY			_msg5C,_apu_mus57
		SJSR				_ssub_cut_char_idxBs_10_clear_set_test
		MSG_DISPLAY			_msg5D,_apu_mus5D
		MSG_WAIT
		MSG_DISPLAY			_msg5E,_apu_mus57
		SJSR				_ssub_cut_char_idxBs_10_clear_set_test
		TIMER_B_SET			$00
		MSG_DISPLAY			_msg5F,_apu_mus56
		SJSR				_ssub_cut_char_idxBs_10_clear_set_test
		TIMER_B_SET			$05
		NJSR_SYNC			_nsub_cut_char_idxBs_10_clear
		SJMP				_ssub_delayed_ingame_start

; =============== S C R I P T ===============================================
_obj_scr_193:
		NJSR				_nsub_idxBs_10_set
byte_B7C2E:
		STORE				$00,_ppu_scroll_nt_hor+1
		SYNC
		STORE				$01,_ppu_scroll_nt_hor+1
		SYNC
		NJSR				_nsub_idxBs_10_test
		SBNES				byte_B7C2E
		KILL

; =============== S C R I P T ===============================================
_obj_scr_195:
		SPR_LIB_SET			_spr_lib1
		SPR_IDX_SET			_spr_lib1_1B
		POS_X_SET			$58,$00
		POS_Y_SET			$C0,$00
		FLIP_H_ON
		SPRITE_ON
		SJSR				_ssub_idxBs_10_set_clear_wait
		SJSR				_ssub_6B73A
		SJSR				_ssub_6B744

; =============== S C R I P T ===============================================
_obj_scr_194:
		SPR_LIB_SET			_spr_lib2
		SPR_IDX_SET			_spr_lib2_1B
		POS_X_SET			$40,$00
		POS_Y_SET			$C0,$00
		FLIP_H_ON
		SPRITE_ON
		SJSR				_ssub_idxBs_10_set_clear_wait
		SJSR				_ssub_6B73A
		SJSR				_ssub_6B744

; =============== S C R I P T ===============================================
_scr_cutscene0F:
		SRUN				_OBJ_TYPE_AUTO,_obj_scr_196
		TIMER_B_SET			$02
		SRUN				_OBJ_TYPE_AUTO,_obj_scr_197
		NJSR				_nsub_cut_last_obj_slot_store
		TIMER_B_SET			$00
		SRUN				_OBJ_TYPE_AUTO,_obj_scr_198
		NJSR_SYNC			_nsub_cut_last_obj_slot_store
		SUSPEND				$3C
		TIMER_B_SET			$02
		MSG_DISPLAY			_msg60,_apu_mus59
		SJSR				_ssub_cut_char_idxBs_10_clear_set_test
		TIMER_B_SET			$00
		MSG_DISPLAY			_msg61,_apu_mus56
		SJSR				_ssub_cut_char_idxBs_10_clear_set_test
		TIMER_B_SET			$02
		MSG_DISPLAY			_msg62,_apu_mus59
		SJSR				_ssub_cut_char_idxBs_10_clear_set_test
		SJMP				_ssub_next_cutscene

; =============== S C R I P T ===============================================
_obj_scr_198:
		SPR_LIB_SET			_spr_lib1
		SPR_IDX_SET			_spr_lib1_1B
		POS_X_SET			$B0,$00
		POS_Y_SET			$C0,$00
		SPRITE_ON
		SJSR				_ssub_idxBs_10_set_clear_wait
		SJSR				_ssub_6B73A

; =============== S C R I P T ===============================================
_obj_scr_196:
		SPR_LIB_SET			_spr_lib2
		SPR_IDX_SET			_spr_lib2_1B
		POS_X_SET			$D0,$00
		POS_Y_SET			$90,$00
		SPRITE_ON
		SJMP				_ssub_suspend_forever

; =============== S C R I P T ===============================================
_obj_scr_197:
		SPR_IDX_SET			_spr_lib0_1C
		TIMER_B_SET			$00
		POS_X_SET			$70,$00
		POS_Y_SET			$C0,$00
		FLIP_H_ON
		SPRITE_ON
		SJSR				_ssub_monterey_static_draw
		SJSR				_ssub_6B7D1
		SJSR				_ssub_6B7D1

; =============== S C R I P T ===============================================
_scr_cutscene10:
		SRUN				_OBJ_TYPE_AUTO,_obj_scr_199
		SRUN				_OBJ_TYPE_AUTO,_obj_scr_19A
		SUSPEND				$B4
		SUSPEND				$B4
		SJMP				_ssub_delayed_next_cutscene

; =============== S C R I P T ===============================================
_obj_scr_19A:
		SPR_LIB_SET			_spr_lib1
		POS_X_SET			$E0,$FF
		SJMPS				byte_B7CF2

; =============== S C R I P T ===============================================
_obj_scr_199:
		SPR_LIB_SET			_spr_lib2
		POS_X_SET			$C8,$FF
; TODO: optimize me! should be !FALLTHROUGH!
		SJMPS				byte_B7CF2
; -

; =============== S C R I P T   R O U T I N E ===============================
byte_B7CF2:
		POS_Y_SET			$C0,$00
		FLIP_H_ON
		SPRITE_ON
		DELTA_X_SET			$10
byte_B7CF9:
		SJSR				_ssub_B7533
		SJMPS				byte_B7CF9

; =============== S C R I P T ===============================================
_scr_cutscene11:
		TIMER_B_SET			$00
		SRUN				_OBJ_TYPE_AUTO,_obj_scr_cut11_chip
		NJSR				_nsub_cut_last_obj_slot_store
		TIMER_B_SET			$01
		SRUN				_OBJ_TYPE_AUTO,_obj_scr_cut11_dale
		NJSR				_nsub_cut_last_obj_slot_store
		TIMER_B_SET			$02
		SRUN				_OBJ_TYPE_AUTO,_obj_scr_cut11_monterey
		NJSR				_nsub_cut_last_obj_slot_store
		TIMER_B_SET			$03
		SRUN				_OBJ_TYPE_AUTO,_obj_scr_cut11_gadget
		NJSR_SYNC			_nsub_cut_last_obj_slot_store
		SUSPEND				$3C
		TIMER_B_SET			$02
		MSG_DISPLAY			_msg63,_apu_mus59
		SJSR				_ssub_cut_char_idxBs_10_clear_set_test
		TIMER_B_SET			$00
		NJSR				_nsub_cut_char_idxBs_10_clear
		TIMER_B_SET			$01
		SJSR				_ssub_cut_char_idxBs_10_clear_set_test
		TIMER_B_SET			$03
		MSG_DISPLAY			_msg64,_apu_mus58
		SJSR				_ssub_cut_char_idxBs_10_clear_set_test
		TIMER_B_SET			$00
		MSG_DISPLAY			_msg65,_apu_mus56
		SJSR				_ssub_cut_char_idxBs_10_clear_set_test
		TIMER_B_SET			$01
		MSG_DISPLAY			_msg66,_apu_mus57
		SJSR				_ssub_cut_char_idxBs_10_clear_set_test
		TIMER_B_SET			$03
		MSG_DISPLAY			_msg67,_apu_mus58
		SJSR				_ssub_cut_char_idxBs_10_clear_set_test
		TIMER_B_SET			$02
		MSG_DISPLAY			_msg68,_apu_mus59
		SJSR				_ssub_cut_char_idxBs_10_clear_set_test
		TIMER_B_SET			$01
		MSG_DISPLAY			_msg69,_apu_mus57
		SJSR				_ssub_cut_char_idxBs_10_clear_set_test
		TIMER_B_SET			$03
		MSG_DISPLAY			_msg6A,_apu_mus58
		SJSR				_ssub_cut_char_idxBs_10_clear_set_test
		TIMER_B_SET			$00
		MSG_DISPLAY			_msg6B,_apu_mus56
		SJSR				_ssub_cut_char_idxBs_10_clear_set_test
		MSG_DISPLAY			_msg6C,_apu_mus56
		TIMER_B_SET			$02
		NJSR_SYNC			_nsub_cut_char_idxBs_10_clear
		TIMER_B_SET			$03
		NJSR_SYNC			_nsub_cut_char_idxBs_10_clear
		SJSR				_ssub_6BECE
		SJSR				_ssub_cut_char_idxBs_10_clear_set_test
		SUSPEND				$0A
		STORE				$18,_chr0_bank_req
		STORE				$00,_ppu_scroll_nt_hor
		STORE				$F0,_spr_buf
		SUSPEND				$3C
		SRUN				_OBJ_TYPE_AUTO,_obj_scr_15A
		SUSPEND				$F0
		SUSPEND				$F0
		SJMP				_ssub_delayed_next_cutscene

; =============== S C R I P T ===============================================
_obj_scr_cut11_chip:
		SPR_LIB_SET			_spr_lib1
		SPR_IDX_SET			_spr_lib1_1B
		POS_X_SET			$70,$01
		POS_Y_SET			$E0,$00
		SPRITE_ON
		SJSR				_ssub_idxBs_10_set_clear_wait
		SJSRS				_ssub_B7DE6
		SJSR				_ssub_6B73A
		SJSR				_ssub_6B73A
		SJSR				_ssub_6B73A
		SJSR				_ssub_6B73A

; =============== S C R I P T ===============================================
_obj_scr_cut11_dale:
		SPR_LIB_SET			_spr_lib2
		SPR_IDX_SET			_spr_lib2_1B
		POS_X_SET			$40,$01
		POS_Y_SET			$E0,$00
		SPRITE_ON
		SJSR				_ssub_idxBs_10_set_clear_wait
		SJSRS				_ssub_B7DE6
		SJSR				_ssub_6B73A
		SJSR				_ssub_6B73A
		SJSR				_ssub_6B73A

; =============== S C R I P T   R O U T I N E ===============================
_ssub_B7DE6:
		DELTA_X_SET			$F0
byte_B7DE8:
		SJSR				_ssub_B7533
		LOOP_A				$06,byte_B7DE8
		SPR_IDX_SET			_spr_lib1_1B
		SJMP				_ssub_idxBs_10_set_clear_wait

; =============== S C R I P T ===============================================
_obj_scr_cut11_monterey:
		SPR_IDX_SET			_spr_lib0_1C
		TIMER_B_SET			$00
		POS_X_SET			$20,$00
		POS_Y_SET			$A0,$00
		FLIP_H_ON
		SPRITE_ON
		SJSR				_ssub_monterey_static_draw
		SJSR				_ssub_6B7D1
		SJSR				_ssub_6B7D1
		SJSR				_ssub_6B7D1

; =============== S C R I P T ===============================================
_obj_scr_cut11_gadget:
		SPR_IDX_SET			_spr_lib0_28
		TIMER_B_SET			$09
		POS_X_SET			$40,$00
		POS_Y_SET			$C0,$00
		FLIP_H_ON
		SPRITE_ON
		SJSR				_ssub_gadget_static_draw
		SJSR				_ssub_6B797
		SJSR				_ssub_6B78D
		SJSR				_ssub_6B797
		SJSR				_ssub_6B78D

; =============== S C R I P T ===============================================
_scr_cutscene12:
		SRUN				_OBJ_TYPE_AUTO,_obj_scr_cut12_chip
		SRUN				_OBJ_TYPE_AUTO,_obj_scr_cut12_dale
		SRUN				_OBJ_TYPE_AUTO,_obj_scr_cut12_monterey
		SRUN				_OBJ_TYPE_AUTO,_obj_scr_cut12_gadget
		POS_X_SET			$48,$00
		POS_Y_SET			$40,$00
		SPRITE_ON
		FLIP_H_ON
		SJSR				_ssub_zipper_hover_animate

; =============== S C R I P T ===============================================
_obj_scr_cut12_chip:
		SPR_LIB_SET			_spr_lib1
		SPR_IDX_SET			_spr_lib1_1B
		POS_X_SET			$A0,$00
		POS_Y_SET			$80,$00
		SPRITE_ON
		SJMP				_ssub_suspend_forever

; =============== S C R I P T ===============================================
_obj_scr_cut12_dale:
		SPR_LIB_SET			_spr_lib2
		SPR_IDX_SET			_spr_lib2_1B
		POS_X_SET			$60,$00
		POS_Y_SET			$80,$00
		FLIP_H_ON
		SPRITE_ON
		SJMP				_ssub_suspend_forever

; =============== S C R I P T ===============================================
_obj_scr_cut12_monterey:
		SPR_IDX_SET			_spr_lib0_1C
		TIMER_B_SET			$00
		POS_X_SET			$40,$00
		POS_Y_SET			$C8,$00
		FLIP_H_ON
		SPRITE_ON
		SJSR				_ssub_monterey_static_draw

; =============== S C R I P T ===============================================
_obj_scr_cut12_gadget:
		SPR_IDX_SET			_spr_lib0_28
		TIMER_B_SET			$00
		POS_X_SET			$C0,$00
		POS_Y_SET			$50,$00
		SPRITE_ON
		SJSR				_ssub_gadget_static_draw

; =============== S U B R O U T I N E =======================================
_nsub_cut_monterey_talk_spr_insert:
		LDA		_obj_spr_idxs,X
		CMP		#_spr_lib0_1C_idx
		BEQ		loc_B7E84
		RTS
loc_B7E84:
		LDA		#<[_spr_monterey_talk_list]
		LDY		#>[_spr_monterey_talk_list]
		JMP		_nsub_cut_talk_spr_insert_common

_spr_monterey_talk_list:
		.BYTE	_spr_lib0_1D_idx,_spr_lib0_1E_idx,$FF
		.BYTE	_spr_lib0_20_idx,_spr_lib0_1E_idx,$FF
		.BYTE	_spr_lib0_1D_idx,_spr_lib0_22_idx,$FF
		.BYTE	_spr_lib0_20_idx,_spr_lib0_1B_idx,$FF
		.BYTE	_spr_lib0_1D_idx,_spr_lib0_21_idx,$FF

; =============== S U B R O U T I N E =======================================
_nsub_cut_gadget_talk_spr_insert:
		LDA		_obj_spr_idxs,X
		CMP		#_spr_lib0_28_idx
		BEQ		loc_B7EA2
		RTS
loc_B7EA2:
		LDA		#<[_spr_gadget_talk_list]
		LDY		#>[_spr_gadget_talk_list]
		JMP		_nsub_cut_talk_spr_insert_common

_spr_gadget_talk_list:
		.BYTE	_spr_lib0_33_idx,_spr_lib0_32_idx,$FF
		.BYTE	_spr_lib0_2D_idx,_spr_lib0_32_idx,$FF
		.BYTE	_spr_lib0_2E_idx,$FF,$FF
		.BYTE	_spr_lib0_2F_idx,$FF,$FF

; =============== S U B R O U T I N E =======================================
_nsub_cut_talk_spr_insert_common:
		STA		_tmp_ptrE						; get sprites list offset
		STY		_tmp_ptrE+1
		LDA		_cur_prg_bank					; save prg bank, obj_spr_lib_insert changes it
		PHA
		LDA		_obj_spr_idxs,X
		PHA
		LDY		_obj_timerBs,X					; load desired animation frame (set externally)
loc_B7EC3:
		LDX		_scr_idx
		LDA		(_tmp_ptrE),Y					; fetch sprite index till $FF
		BMI		loc_B7ED6
		STA		_obj_spr_idxs,X
		TYA
		PHA
		JSR		_obj_spr_lib_insert				; insert additional sprites to the char
		PLA
		TAY
		INY
		BNE		loc_B7EC3
loc_B7ED6:
		PLA
		LDX		_scr_idx						; restore main char sprite to be displayed by core
		STA		_obj_spr_idxs,X
		JMP		_mmc1_prg_restore				; restore prg bank and exit

		LAST_BANK_END 7,$10000

;		DEBUG_LOG_PRINT

; total_banks	= 8
; total_size	= 8*16384
; total_free	= $394	(original)
