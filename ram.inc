
		INCLUDE		"..\macroses.inc"

;--------------------R-A-M----------------------

		ORG $0000

; here we put dummy ptrs to be used with macroses and
; produce $0000 offset
;
_obj_scr19	EQU	.
_obj_scr1A	EQU	.
_ptr_dummy	EQU	.
; -

_tmp_ptr0:
		.BYTE	0,0
_tmp_ptr2:
		.BYTE	0,0
_tmp_ptr4:
		.BYTE	0,0
byte_6:
		.BYTE	0
byte_7:
		.BYTE	0
byte_8:
		.BYTE	0
byte_9:
		.BYTE	0
_tmpA:
		.BYTE	0,0
_tmpC:
		.BYTE	0,0
_tmp_ptrE:
		.BYTE	0,0
_ppu_scroll_shadow_lo:
		.BYTE	0,0
_scroll_lo_backup:
		.BYTE	$00
_ppu_scroll_nt_hor:
		.BYTE	0,0
_scroll_shadow_lo_backup:
		.BYTE	0
_ppu_scroll_shadow_hi:
		.BYTE	0,0
_scroll_hi_backup:
		.BYTE	$00
_ppu_scroll_nt_vert:
		.BYTE	0,0
_scroll_shadow_hi_backup:
		.BYTE	0
_tmp1C:
		.BYTE	0
_chr0_bank_req:
		.BYTE	0
_chr1_bank_req:
		.BYTE	0
_wnd_split_chr0_bank:
		.BYTE	0
_wnd_split_chr1_bank:
		.BYTE	0
_chr0_backup:
		.BYTE	0
_chr1_backup:
		.BYTE	0
_mmc1_ctrl_shadow:
		.BYTE	$00
_unused_3:
		.BYTE	0
_unused_4:
		.BYTE	0
_cur_prg_bank:
		.BYTE	0
_mmc1_busy:
		.BYTE	0
byte_28:
		.BYTE	0
_ppu_ctrl_shadow:
		.BYTE	0
_ppu_mask_shadow:
		.BYTE	0
_wnd_split_flag:
		.BYTE	0
_split_pos:
		.BYTE	0
_nmi_frames_counter:
		.BYTE	0,0
_nmi_sync_req:
		.BYTE	0
byte_30:
		.BYTE	0
_spr_buf_start:
		.BYTE	0
_spr_buf_pos:
		.BYTE	0
_scr_idx:
		.BYTE	0
_scr_pc:
		.BYTE	0,0
_pads_tmp:
		.BYTE	0,0
_pads:
		.BYTE	0,0,0,0,0,0
_unref_1:
		.BYTE	0,0
_main_sub_idx:
		.BYTE	0
_ingame_mode_idx:
		.BYTE	0
_tmp_ptr42:
		.BYTE	0,0
_tmp_ptr44:
		.BYTE	0,0
byte_46:
		.BYTE	0
_hor_menu_pos:
		.BYTE	0
_tmp48:
		.BYTE	0
_tmp49:
		.BYTE	0
_vert_menu_idx:
		.BYTE	0
_tmp_ptr4B:
		.BYTE	0,0
_wnd_msg_sub_idx:
		.BYTE	0
_wnd_msg_ptr:
		.BYTE	0,0
_wnd_msg_ptr_backup:
		.BYTE	0,0
_wnd_msg_ppu_ofs:
		.BYTE	0,0
_wnd_msg_area_heigth:
		.BYTE	0
_wnd_msg_area_width:
		.BYTE	0
_wnd_msg_delay_default:
		.BYTE	0
_wnd_msg_se_idx:
		.BYTE	0
_wnd_msg_dict_idx:
		.BYTE	$00
_wnd_msg_next_dict_idx:
		.BYTE	0
_wnd_msg_dict_in_use_flag:
		.BYTE	$00
_cur_wnd_msg_row:
		.BYTE	0
_cur_wnd_msg_col:
		.BYTE	0
_wnd_msg_delay_timer:
		.BYTE	0
_wnd_msg_char_send_flag:
		.BYTE	0
_wnd_msg_skip_delay:
		.BYTE	0
_ppu_queue0_done_flag:
		.BYTE	0
_ppu_queue0_increment_mode:
		.BYTE	0
_pal_fade_req:
		.BYTE	0
_pal_fade_lvl:
		.BYTE	0
_pal_fade_mask:
		.BYTE	0
_pal_fade_speed:
		.BYTE	0
_pal_fade_delay:
		.BYTE	0
_debug_invulnerability_flag:
		.BYTE	0
_timer_minutes_cnt:
		.BYTE	0
_timer_seconds_cnt:
		.BYTE	0
_timer_frames_cnt:
		.BYTE	0
_rand_seed:
		.BYTE	0
_box_bonus_prizes_order_list:
		.BYTE	0,0,0,0
byte_70:
		.BYTE	0
_cutscene_idx:
		.BYTE	0
_stage:
		.BYTE	0
_stage_room_idx:
		.BYTE	0
_room_flags:
		.BYTE	0
_stage_flags:
		.BYTE	0
_continues:
		.BYTE	0
_room_prizes_ptr:
		.BYTE	0,0
_room_enemies_ptr:
		.BYTE	$00,0
_room_layout_ptr:
		.BYTE	0,0
_room_scrolls_ptr:
		.BYTE	$00,0
byte_7F:
		.BYTE	0
_room_tileset_ptr:
		.BYTE	$00,0
byte_82:
		.BYTE	0
byte_83:
		.BYTE	0
byte_84:
		.BYTE	0,0,0,0,0,0
byte_8A:
		.BYTE	0,0,0,0,0,0
_room_drawB_sub_idx:
		.BYTE	0
byte_91:
		.BYTE	0
byte_92:
		.BYTE	0
byte_93:
		.BYTE	0
byte_94:
		.BYTE	0
byte_95:
		.BYTE	0
byte_96:
		.BYTE	0
byte_97:
		.BYTE	0
_pal_anim_mode_idx:
		.BYTE	0
_pal_anim_timer:
		.BYTE	0
_pal_anim_tbl_pos:
		.BYTE	$00
_pal_anim_tbl_cnt:
		.BYTE	$00
_pal_anim_cnt:
		.BYTE	0
byte_9D:
		.BYTE	0
byte_9E:
		.BYTE	0
_obj_global_x_shift:
		.BYTE	0,0
_obj_global_y_shift:
		.BYTE	0,0
_players_rr_ptss:
		.BYTE	0,0
_players_rr_lvls:
		.BYTE	0,0
_players_lives:
		.BYTE	0,0
_players_def_max_hps:
		.BYTE	0,0
byte_AB:
		.BYTE	0
byte_AC:
		.BYTE	0
byte_AD:
		.BYTE	0
_lvl_start_scroll_hor:
		.BYTE	0,0
byte_B0:
		.BYTE	0
byte_B1:
		.BYTE	0
_lvl_start_scroll_vert:
		.BYTE	0,0
_wnd_split_ppu_ofs:
		.BYTE	0,0
_cur_mus_playing:
		.BYTE	0
_apu_load_idx_req:
		.BYTE	$00
_players_states:
		.BYTE	0,0
_players_x_speeds:
		.BYTE	$00,0
_players_x_shifs:
		.BYTE	0,0
_players_y_shifs_unused:
		.BYTE	0,0
_players_x_poss:
		.BYTE	0,0
_players_y_poss:
		.BYTE	0,0
_players_nums:
		.BYTE	0,0
_players_anim_idxs:
		.BYTE	0,0
_players_vars07:
		.BYTE	0,0
_players_vars08:
		.BYTE	0,0
_players_vars09:
		.BYTE	0,0
_players_vars0A:
		.BYTE	0,0
_players_vars0B:
		.BYTE	0,0
_players_vars0C:
		.BYTE	0,0
_players_vars0D:
		.BYTE	0,0
_players_vars0E:
		.BYTE	0,0
_players_vars0F:
		.BYTE	0,0
_players_vars10:
		.BYTE	0,0
_players_max_hps:
		.BYTE	0,0
byte_DE:
		.BYTE	0
byte_DF:
		.BYTE	0
byte_E0:
		.BYTE	0
byte_E1:
		.BYTE	0
byte_E2:
		.BYTE	0
byte_E3:
		.BYTE	0
_extra_stages_complete_flags:
		.BYTE	0
_unref_3:
		.BYTE	0,0,0,0,0,0,0,0
_scr_cur_slot_idx:
		.BYTE	$00
_unref_6:
		.BYTE	0,0
_apu_load_idx:
		.BYTE	0
_apu_active_chnls_flags:
		.BYTE	0
_apu_chnl_flags:
		.BYTE	0
_apu_tmpF2:
		.BYTE	0
_apu_tmpF3:
		.BYTE	0
_apu_cur_pc:
		.BYTE	0,0
_apu_tmpF7:
		.BYTE	0
_apu_snd0_allow_flag:
		.BYTE	0
_apu_snd1_allow_flag:
		.BYTE	0
_apu_tmpFA:
		.BYTE	0
_apu_tmpFB:
		.BYTE	0
_apu_mus_allow_flag:
		.BYTE	0
_apu_tmpFD:
		.BYTE	0

		ECHO "-------------"
		ECHO "zero ram free:",[$100-.]
		ECHO "-------------"

		ORG		$100

byte_100:
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
_pal_backup:
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
_stack_slot0:
		.BYTE	0,0,0,0,0,0,0,0,0,0
_stack_slot1:
		.BYTE	0,0,0,0,0,0,0,0,0,0
_stack_slot2:
		.BYTE	0,0,0,0,0,0,0,0,0,0
_stack_slot3:
		.BYTE	0,0,0,0,0,0,0,0,0,0
_stack_slot4:
		.BYTE	0,0,0,0,0,0,0,0,0,0
_stack_slot5:
		.BYTE	0,0,0,0,0,0,0,0,0,0
_stack_slot6:
		.BYTE	0,0,0,0,0,0,0,0,0,0
_stack_slot7:
		.BYTE	0,0,0,0,0,0,0,0,0,0
_stack_slot8:
		.BYTE	0,0,0,0,0,0,0,0,0,0
_stack_slot9:
		.BYTE	0,0,0,0,0,0,0,0,0,0
_stack_slotA:
		.BYTE	0,0,0,0,0,0,0,0,0,0
_stack_slotB:
		.BYTE	0,0,0,0,0,0,0,0,0,0
_scr_sps:
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0
_scr_lo_pcs:
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0
_scr_hi_pcs:
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0
_scr_delays:
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0
_scr_flags:
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0
_scr_destr_lo_pcs:
		.BYTE	$00,0,0,0,0,0,0,0,0,0,0,0
_scr_destr_hi_pcs:
		.BYTE	$00,0,0,0,0,0,0,0,0,0,0,0
_scr_loopsA:
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0
_scr_loopsB:
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0
_scr_idxBs:
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0
_scr_params:
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0
_obj_y_lo_poss:
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0
_obj_y_hi_poss:
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0
_obj_x_lo_poss:
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0
_obj_x_hi_poss:
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0
_obj_spr_libs:
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0
_obj_spr_idxs:
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0
_obj_flips:
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0
_obj_x_deltas:
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0
_obj_y_deltas:
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0
_obj_x_accel:
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0
_obj_y_accel:
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0
_scr_vars16:
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0
_scr_vars17:
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0
_scr_vars18:
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0
_scr_vars19:
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0
_obj_widths:
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0
_obj_heights:
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0
_scr_vars1C:
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0
_obj_hps:
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0
_scr_idxCs:
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0
_scr_idxAs:
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0
_scr_vars20:
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0
_scr_vars21:
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0
_tmp_players_lives:
		.BYTE	0,0
_unused_344:
		.BYTE	0,0,0,0
_dict80_ptr:
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
_dict81_ptr:
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
byte_436:
		.BYTE	0
byte_437:
		.BYTE	0
byte_438:
		.BYTE	0
byte_439:
		.BYTE	0
byte_43A:
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
_room_tiles_tmp_buf:
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
_ppu_queue0_flag:
		.BYTE	0
_ppu_queue0_buf:
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE	0,0,0
_pal_buf:
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
_pal_tmp_buf:
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
_spr_lib0_10:
_ram_buf0:
		.BYTE	0,0,0,0,0,0,0,0,0,0
_spr_lib0_11:
_ram_buf1:
		.BYTE	0,0,0,0,0,0,0,0,0,0
_spr_lib0_12:
_ram_buf2:
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0
_spr_buf:
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
_apu_chnl_sp:
		.BYTE	0,0,0,0,0,0
_apu_chnl_stack:
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
_apu_chnl_pc_lo:
		.BYTE	0,0,0,0,0,0
_apu_chnl_pc_hi:
		.BYTE	0,0,0,0,0,0
_apu_vars10:
		.BYTE	0,0,0,0,0,0
_apu_vars11:
		.BYTE	0,0,0,0,0,0
_apu_vars3:
		.BYTE	0,0,0,0,0,0
_apu_vars4:
		.BYTE	0,0,0,0,0,0
_apu_chnl_delay:
		.BYTE	0,0,0,0,0,0
_apu_vars12:
		.BYTE	0,0,0,0,0,0
_apu_vars1:
		.BYTE	0,0,0,0,0,0
_apu_varsD:
		.BYTE	0,0,0,0,0,0
_apu_vars9:
		.BYTE	0,0,0,0,0,0
_apu_varsA:
		.BYTE	0,0,0,0,0,0
_apu_vars13:
		.BYTE	0,0,0,0,0,0
_apu_vars8:
		.BYTE	0,0,0,0,0,0
_apu_vars14:
		.BYTE	0,0,0,0,0,0
_apu_vars15:
		.BYTE	0,0,0,0,0,0
_apu_vars6:
		.BYTE	0,0,0,0,0,0
_apu_vars7:
		.BYTE	0,0,0,0,0,0
_apu_varsE:
		.BYTE	0,0,0,0,0,0
_apu_varsC:
		.BYTE	0,0,0,0,0,0
_apu_varsB:
		.BYTE	0,0,0,0,0,0
_apu_vars2:
		.BYTE	0,0,0,0,0,0
_apu_ptr0:
		.BYTE	0,0
_apu_var10:
		.BYTE	0
_apu_var11:
		.BYTE	0
_apu_var12:
		.BYTE	0
_apu_var13:
		.BYTE	0
_apu_varsF:
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE	0,0,0,0

;--------------------P-P-U----------------------

		ORG $2000

_PPU_CTRL:
		.BYTE 0
_PPU_MASK:
		.BYTE 0
_PPU_STATUS:
		.BYTE 0
_PPU_OAM_ADDR:
		.BYTE 0
_PPU_OAM_DATA:
		.BYTE 0
_PPU_SCROLL:
		.BYTE 0
_PPU_ADDR:
		.BYTE 0
_PPU_DATA:
		.BYTE 0

;--------------------A-P-U----------------------

		ORG $4000

_APU_PULSE1_ENV:
		.BYTE 0
_APU_PULSE1_SWEEP:
		.BYTE	0
_APU_PULSE1_TIME:
		.BYTE 0
_APU_PULSE1_LEN:
		.BYTE 0
_APU_PULSE2_ENV:
		.BYTE 0
_APU_PULSE2_SWEEP:
		.BYTE	0
_APU_PULSE2_TIME:
		.BYTE 0
_APU_PULSE2_LEN:
		.BYTE 0
_APU_TRI_COUNT:
		.BYTE 0
_APU_TRI_UNUSED:
		.BYTE 0
_APU_TRI_TIME:
		.BYTE 0
_APU_TRI_LEN:
		.BYTE 0
_APU_NOISE_ENV:
		.BYTE 0
_APU_NOISE_UNUSED:
		.BYTE 0
_APU_NOISE_LOOP:
		.BYTE 0
_APU_NOISE_LEN:
		.BYTE 0
_APU_DMC_FREQ:
		.BYTE 0
_APU_DMC_LOAD:
		.BYTE 0
_APU_DMC_ADDR:
		.BYTE 0
_APU_DMC_LEN:
		.BYTE 0
_PPU_OAM_DMA:
		.BYTE 0
_APU_STATUS:
		.BYTE 0
_PAD0_REG:
		.BYTE 0
_PAD1_REG:
		.BYTE 0
