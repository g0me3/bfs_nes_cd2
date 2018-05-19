
		ORG $8000

		BANK_START $04

		DEBUG_LOG_INIT

		SECTION_START	0B

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_unref:
		NJSR				_obj_move_hor_animate
		NJSR				_native_obj_to_tile_collision_test_hor
		SBCSS				byte_6800C
		NJSR				_j_native_complement_x_deltas
byte_6800C:
		SJSRS				_script_sub_obj_jump_calcs
		SBCSS				byte_6801F
		NJSR				_native_get_obj_y_delta
		SBMIS				byte_6801C
		NJSR				_native_sub107
		SRET
byte_6801C:
		NJSR				_scr_flags_flush_clc
byte_6801F:
		SRET

; =============== S C R I P T   R O U T I N E ===============================
_script_acorn_prize_animate:
		SYNC
		NJSR				_native_get_obj_y_delta
		SBEQS				byte_6802F
		SJSRS				_script_sub_obj_jump
		SBCCS				byte_6802F
		OBJ_X_DELTA_SET		$00
byte_6802F:
		NJSR				_native_get_obj_hp
		SBNES				_script_acorn_prize_animate
		SRET

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_obj_wait_for_jump:
		SJSRS				_script_sub_obj_jump_sync
		SBCCS				_script_sub_obj_wait_for_jump
		SRET

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_obj_jump_sync:
		SYNC

; !FALLTHROUGH!

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_obj_jump:
		NJSR				_obj_move_hor_animate
		NJSR				_native_obj_to_tile_collision_test_hor

; !FALLTHROUGH!

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_obj_jump_calcs:
		NJSR				_native_obj_y_parabolic_delta_adjust
		NJSR				_native_get_obj_y_delta
		SBPLS				byte_6805C
		NJSR				_obj_vert_animate
		NJSR				_native_obj_to_tile_collision_test_up
		SBCSS				byte_68058
		OBJ_Y_DELTA_SET		$01
byte_68058:
		NJSR				_scr_flags_flush_clc
		SRET
byte_6805C:
		NJSR				_native_sub10B
		SBCCS				byte_68064
		OBJ_Y_DELTA_SET		$00
byte_68064:
		SRET

; =============== S C R I P T   R O U T I N E ===============================
_script_obj_wait_for_pickup:
		NJSR_SYNC			_native_get_obj_idxBs
		SBPLS				_script_obj_wait_for_pickup
		SRET

; =============== S C R I P T   R O U T I N E ===============================
_script_obj_wait_for_throw:
		NJSR				_native_obj_type_change_throw
		NJSR				_native_obj_idxCs_clear_low_nibble
		NJSR				_native_sub164
byte_68075:
		NJSR				_native_get_obj_idxBs
		SBPLS				byte_68081
		NJSR_SYNC			_players_animB_sub0129_sub06_C
		SJMPS				byte_68075
byte_68081:
		NJSR				_native_obj_idxCs_80_set
		APU_LOAD			_apu_mus24
		SRET

; =============== S C R I P T   R O U T I N E ===============================
_obj_scr_common_destr:
		APU_LOAD			_apu_mus2D
		OBJ_DAMAGE_SET		_OBJ_DMG_NONE
		OBJ_X_DELTA_SET		$BD
		OBJ_Y_DELTA_SET		$BD
		NJSR				_players_animB_sub3_B_A

; !FALLTHROUGH!

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_infinite_anim_sync:
		OBJ_ANIMATE_SYNC
		SJMPS				_script_sub_infinite_anim_sync

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_y_parabolic_delta_infinite_anim_sync:
		OBJ_ANIMATE_SYNC
		NJSR				_native_obj_y_parabolic_delta_adjust
		SJMPS				_script_sub_y_parabolic_delta_infinite_anim_sync

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_6809D:
		SJSRS				_script_sub_680E7
		OBJ_X_DELTA_SET		$00
		NJSR				_scr_flips_04_clear
byte_680A5:
		SJSRS				_script_sub_680C3
		LOOPA				$3C,byte_680A5
		LOOPB				$08,byte_680A5
		NJSR				_native_obj_blink_set
byte_680B3:
		SJSRS				_script_sub_680C3
		LOOPA				$78,byte_680B3
		NJSR				_native_obj_blink_clear
		NJSR				_native_obj_disable_from_idxCs_40_flag
		OBJ_DAMAGE_SET		_OBJ_DMG_KILL
		SRET

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_680C3:
		SYNC
		NJSR				_native_get_obj_idxBs
		SBMIS				byte_680D4
		NJSR				_native_obj_to_tile_collision_test_down
		SBCSS				byte_680D3
		SJSRS				_script_sub_obj_jump_calcs
byte_680D3:
		SRET
byte_680D4:
		SJSRS				_script_sub_68102
		OBJ_DAMAGE_SET		_OBJ_DMG_STUN
		OBJ_X_DELTA_SET		$C0
		NJSR				_native_sub11B
		NJSR				_native_sub11C
		NJSR				_native_obj_type_change_stunA
		SJMPS				_script_sub_infinite_anim_sync

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_680E7:
		OBJ_DAMAGE_SET		_OBJ_DMG_NONE
		APU_LOAD			_apu_mus2E
		OBJ_X_DELTA_SET		$F0
		OBJ_Y_DELTA_SET		$D0
		NJSR				_players_animB_sub3_B_A
		NJSR				_players_animB_sub0129_sub0E_A
byte_680F5:
		SJSR				_script_sub_obj_jump_sync
		SBCSS				byte_68101
		NJSR				_native_get_obj_idxBs
		SBPLS				byte_680F5
byte_68101:
		SRET

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_68102:
		OBJ_Y_DELTA_SET		$00
		NJSR				_native_obj_idxCs_clear_low_nibble
		NJSR				_native_obj_blink_clear
byte_6810A:
		SYNC
		NJSR				_players_animB_sub0129_sub06_C
		NJSR				_native_get_obj_idxBs
		SBMIS				byte_6810A
		APU_LOAD			_apu_mus24
		SRET

; =============== O B J E C T   S C R I P T =================================
_obj_scr24_spoon_rat:
		DESTR_PC_SET		_obj_scr_24_spoon_rat_destr
		SPR_LIB_SELECT		_spr_lib7
		SPR_IDX_SELECT		_spr_lib7_00
		OBJ_SIZE_SET		$08,$18
		OBJ_HP_SET			$02
		OBJ_DAMAGE_SET		_OBJ_DMG_KILL
		SJSR				_script_sub_obj_show_wait_for_idxCs_80_set
		OBJ_X_DELTA_SET		$F0
		OBJ_Y_DELTA_SET		$00
		NJSR				_native_sub10E
		NJSR				_native_obj_hor_delta_toggle
byte_68132:
		SPR_IDX_SELECT		_spr_lib7_00				; 4-frame walk animation
		SJSRS				_script_sub_spoon_rat_ai	; fast enough delta to get all
		SPR_IDX_SELECT		_spr_lib7_01				; its path for only 4 steps here
		SJSRS				_script_sub_spoon_rat_ai
		SPR_IDX_SELECT		_spr_lib7_02
		SJSRS				_script_sub_spoon_rat_ai
		SPR_IDX_SELECT		_spr_lib7_01
		SJSRS				_script_sub_spoon_rat_ai
byte_68146:
		NJSR				_native_obj_hor_move_reverse	; when reached end of path, flip x
		SJMPS				byte_68132

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_spoon_rat_ai:
		SYNC
		NJSR				_native_obj_to_throw_collision_test_range40		; player's box watch
		SBCCS				byte_6816A
		NJSR				_obj_move_hor_animate		; if no player, just walk
		NJSR				_native_obj_to_tile_collision_test_hor
		SBCSS				byte_6815F					; auto detect obstacles
		BREAK				byte_68146					; turn back if reached any solid object
byte_6815F:
		NJSR				_native_obj_to_tile_collision_test_down
		SBCC				_script_sub_obj_wait_for_jump
		LOOPA				$08,_script_sub_spoon_rat_ai; repeat 8 times for 1 step
		SRET
byte_6816A:
		NJSR				_native_sub132
		SPR_IDX_SELECT		_spr_lib7_03
		SUSPEND				$08
		SPR_IDX_SELECT		_spr_lib7_04
		APU_LOAD			_apu_mus5E
		NJSR				_native_obj_to_throw_collision_test_range20
		SBCSS				byte_6817E
		NJSR				_native_obj_stun_from_idxAs_test
byte_6817E:
		SUSPEND				$08
		SPR_IDX_SELECT		_spr_lib7_05
		SUSPEND				$08
		SPR_IDX_SELECT		_spr_lib7_00
		SUSPEND				$08
		NJSR				_native_sub10E
		NJSR				_native_obj_hor_delta_toggle
		SRET

; =============== O B J E C T   S C R I P T =================================
_obj_scr_24_spoon_rat_destr:
		SPR_IDX_SELECT		_spr_lib7_06
		NJSR				_native_get_obj_hp
		SBEQ				_obj_scr_common_destr
		SJSR				_script_sub_6809D
		SJMPS				_obj_scr24_spoon_rat

; =============== O B J E C T   S C R I P T =================================
_obj_scr25_fork_rat:
		DESTR_PC_SET		_obj_scr_common_destr		; fork rat can be killed with throwable
		SPR_LIB_SELECT		_spr_lib7					; projectile in any ai mode, no beat off
		SPR_IDX_SELECT		_spr_lib7_07
		OBJ_HP_SET			$01
		OBJ_DAMAGE_SET		_OBJ_DMG_KILL				; deadly rat!
		OBJ_SIZE_SET		$08,$18
		SJSR				_script_sub_obj_show_wait_for_idxCs_80_set
		OBJ_X_DELTA_SET		$F0
		OBJ_Y_DELTA_SET		$00
		NJSR				_native_sub10E
		NJSR				_native_obj_hor_delta_toggle
byte_681B8:
		SPR_IDX_SELECT		_spr_lib7_08				; same 4-step path as for
		SJSRS				_script_sub_fork_rat_passive_ai	; spoon rat, passive phase
		SPR_IDX_SELECT		_spr_lib7_09
		SJSRS				_script_sub_fork_rat_passive_ai
		SPR_IDX_SELECT		_spr_lib7_0A
		SJSRS				_script_sub_fork_rat_passive_ai
		SPR_IDX_SELECT		_spr_lib7_09
		SJSRS				_script_sub_fork_rat_passive_ai
		NJSR				_native_obj_hor_move_reverse
		SJMPS				byte_681B8

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_fork_rat_passive_ai:
		OBJ_ANIMATE_SYNC								; not sure why they put this animation here
		NJSR				_native_obj_y_collision_test_from_byte_AB
		SBCSS				byte_681DF					; skip if player not on the same y pos
		NJSR				_native_obj_x_range50_test_from_byte_AB
		SBCCS				byte_681E4					; test if player get in close range
byte_681DF:
		LOOPA				$08,_script_sub_fork_rat_passive_ai	; unless loop animation as usual
		SRET
byte_681E4:
		LOOPA_RESET										; start active phase
		LOOPB_RESET
		NJSR				_native_sub10E
		NJSR				_native_obj_hor_delta_toggle
		BREAK				_obj_scr_fork_rat_throw		; exit sub, jump to new obj ai code

; =============== O B J E C T   S C R I P T =================================
_obj_scr_fork_rat_throw:
		SPR_IDX_SELECT		_spr_lib7_07				; first throw its fork
		SUSPEND				$10
		SPR_IDX_SELECT		_spr_lib7_0C				; animate 3 phases, throw
		SUSPEND				$10
		APU_LOAD			_apu_mus5F
		SPR_IDX_SELECT		_spr_lib7_0D
		SRUN				_OBJ_TYPE_ENEMY,_obj_scr_fork_rat_projectile
		SUSPEND				$10
		SPR_IDX_SELECT		_spr_lib7_07				; then one more phase to release
		SUSPEND				$10
byte_68205:
		SPR_IDX_SELECT		_spr_lib7_08				; now cycling the active animations
		SJSRS				_script_sub_fork_rat_active_ai
		SPR_IDX_SELECT		_spr_lib7_09
		SJSRS				_script_sub_fork_rat_active_ai
		SPR_IDX_SELECT		_spr_lib7_0A
		SJSRS				_script_sub_fork_rat_active_ai
		SPR_IDX_SELECT		_spr_lib7_09
		SJSRS				_script_sub_fork_rat_active_ai
		SJMPS				byte_68205

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_fork_rat_active_ai:
		SYNC
		NJSR				_obj_move_hor_animate		; move horizontally
		NJSR				_native_obj_to_tile_collision_test_hor	; when tile obstacles
		SBCCS				byte_68231					; jump up on them
		NJSR				_native_obj_to_tile_collision_test_down	; or hop off
		SBCCS				byte_68231
		LOOPA				$08,_script_sub_fork_rat_active_ai	; else, loop 8 times and
		SRET											; return for new phase
byte_68231:
		LOOPA_RESET
		SPR_IDX_SELECT		_spr_lib7_09				; jump up animation start
		OBJ_Y_DELTA_SET		$C0							; set jump speed, do common code
		SJMP				_script_sub_obj_wait_for_jump

; =============== S C R I P T ===============================================
_obj_scr_fork_rat_projectile:
		DESTR_PC_SET		_obj_scr_fork_rat_projectile_destr
		OBJ_HP_SET			$01
		OBJ_DAMAGE_SET		_OBJ_DMG_KILL				; do not fear a rat, fear its FORK!
		OBJ_SIZE_SET		$08,$04						; one hit you are in the morgue
		SPR_LIB_SELECT		_spr_lib7
		SPR_IDX_SELECT		_spr_lib7_0E
		OBJ_Y_POS_MOVE		$F0
		OBJ_X_DELTA_SET		$30
		NJSR				_native_obj_hor_bounce13
		OBJ_SHOW
		SJMP				_script_sub_infinite_anim_sync

; =============== O B J E C T   S C R I P T =================================
_obj_scr_fork_rat_projectile_destr:
		OBJ_X_DELTA_SET		$0C
		OBJ_Y_DELTA_SET		$E0
		NJSR				_players_animB_sub3_B_A
		SJMP				_script_sub_y_parabolic_delta_infinite_anim_sync

; =============== O B J E C T   S C R I P T =================================
_obj_scr26_fake_boxA:
		DESTR_PC_SET		_obj_scr_common_destr
		OBJ_X_POS_MOVE		$F8
		SPR_LIB_SELECT		_spr_lib7
		SPR_IDX_SELECT		_spr_lib7_4C
		OBJ_HP_SET			$01
		OBJ_DAMAGE_SET		_OBJ_DMG_KILL
		OBJ_SIZE_SET		$08,$0F
		OBJ_SHOW
		SJSR				_script_sub_obj_show_wait_for_idxCs_80_set
		NJSR				_native_sub10E
byte_68273:
		SYNC
		NJSR				_native_obj_x_range50_test_from_byte_AB
		SBCSS				byte_68273
		NJSR				_native_obj_y_collision_test_from_byte_AB
		SBCSS				byte_68273
		APU_LOAD			_apu_mus60
		OBJ_SIZE_SET		$08,$18
		SPR_IDX_SELECT		_spr_lib7_0F
		SUSPEND				$04
		SPR_IDX_SELECT		_spr_lib7_10
		SUSPEND				$04
		SPR_IDX_SELECT		_spr_lib7_11
		SUSPEND				$04
		SPR_IDX_SELECT		_spr_lib7_12
		SUSPEND				$08
		SPR_IDX_SELECT		_spr_lib7_14
		OBJ_Y_DELTA_SET		$D0
		SUSPEND				$08
		SJSR				_script_sub_obj_wait_for_jump
		OBJ_X_DELTA_SET		$F0
		OBJ_Y_DELTA_SET		$00
		NJSR				_native_obj_hor_delta_toggle
byte_682A5:
		SPR_IDX_SELECT		_spr_lib7_13
		SJSRS				_script_sub_682BC
		SPR_IDX_SELECT		_spr_lib7_14
		SJSRS				_script_sub_682BC
		SPR_IDX_SELECT		_spr_lib7_15
		SJSRS				_script_sub_682BC
		SPR_IDX_SELECT		_spr_lib7_14
		SJSRS				_script_sub_682BC
		SJMPS				byte_682A5

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_682BC:
		SYNC
		NJSR				_obj_move_hor_animate
		NJSR				_native_obj_to_tile_collision_test_hor
		SBCCS				byte_682D1
		NJSR				_native_obj_to_tile_collision_test_down
		SBCCS				byte_682D1
		LOOPA				$08,_script_sub_682BC
		SRET
byte_682D1:
		LOOPA_RESET
		SPR_IDX_SELECT		_spr_lib7_14
		OBJ_Y_DELTA_SET		$C0
		SJMP				_script_sub_obj_wait_for_jump

; =============== O B J E C T   S C R I P T =================================
_obj_scr27_honey_bee:
		DESTR_PC_SET		_obj_scr_common_destr
		SPR_LIB_SELECT		_spr_lib7
		SPR_IDX_SELECT		_spr_lib7_16
		OBJ_HP_SET			$01
		OBJ_DAMAGE_SET		_OBJ_DMG_KILL
		OBJ_SIZE_SET		$08,$10
		OBJ_X_DELTA_SET		$10
		OBJ_Y_DELTA_SET		$04
		SJSR				_script_sub_obj_show_wait_for_idxCs_80_set
		NJSR				_native_sub10E
		NJSR				_native_obj_hor_delta_toggle
byte_682F4:
		SPR_IDX_SELECT		_spr_lib7_16
		APU_LOAD			_apu_mus61
		SJSR				_script_animate3
		SPR_IDX_SELECT		_spr_lib7_17
		APU_LOAD			_apu_mus61
		SJSR				_script_animate3
		LOOPA				$08,byte_682F4
byte_68306:
		SPR_IDX_SELECT		_spr_lib7_18
		SJSRS				_script_sub_6833A
		SPR_IDX_SELECT		_spr_lib7_19
		SJSRS				_script_sub_6833A
		LOOPA				$02,byte_68306
byte_68314:
		SPR_IDX_SELECT		_spr_lib7_1A
		SJSRS				_script_sub_6833A
		SPR_IDX_SELECT		_spr_lib7_1B
		SJSRS				_script_sub_6833A
		LOOPA				$02,byte_68314
		SRUN				_OBJ_TYPE_STUNB,_script101
byte_68326:
		SPR_IDX_SELECT		_spr_lib7_16
		SJSRS				_script_sub_6833A
		SPR_IDX_SELECT		_spr_lib7_17
		SJSRS				_script_sub_6833A
		LOOPA				$02,byte_68326
		NJSR				_native_complement_y_deltas
		SJMPS				byte_682F4

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_6833A:
		APU_LOAD			_apu_mus61
		SUSPEND				$03
		SRET

; =============== S C R I P T ===============================================
_script101:
		NJSR				_native_obj_idxCs_80_set
		OBJ_Y_POS_MOVE		$08
		OBJ_HP_SET			$01
		OBJ_DAMAGE_SET		_OBJ_DMG_STUN
		OBJ_SIZE_SET		$02,$04
		SPR_LIB_SELECT		_spr_lib7
		SPR_IDX_SELECT		_spr_lib7_1C
		OBJ_Y_DELTA_SET		$08
		OBJ_SHOW
		SJMP				_script_sub_y_parabolic_delta_infinite_anim_sync

; =============== O B J E C T   S C R I P T =================================
_obj_scr28_green_ceiling_bat:
		DESTR_PC_SET		_obj_scr_common_destr
		OBJ_Y_POS_MOVE		$FC
		SPR_LIB_SELECT		_spr_lib7
		SPR_IDX_SELECT		_spr_lib7_28
		OBJ_SIZE_SET		$08,$18
		OBJ_HP_SET			$01
		OBJ_DAMAGE_SET		_OBJ_DMG_KILL
		SJSR				_script_sub_obj_show_wait_for_idxCs_80_set
		NJSR				_native_sub10E
byte_6836B:
		NJSR_SYNC			_native_obj_x_range60_test_from_byte_AB
		SBCSS				byte_6836B
		TARGET_DIR_SET		$00
byte_68373:
		NJSR				_native_sub10E
		SJSRS				_script_sub_68408
		LOOPA				$03,byte_68373
		NJSR				_native_sub111
		TARGET_LOCK			$20
byte_68382:
		TARGET_DIR_SET		$FF
		SJSRS				_script_sub_68408
		SJMPS				byte_68382

; =============== O B J E C T   S C R I P T =================================
_obj_scr29_green_floor_bat:
		DESTR_PC_SET		_obj_scr_common_destr
		SPR_LIB_SELECT		_spr_lib7
		SPR_IDX_SELECT		_spr_lib7_26
		OBJ_SIZE_SET		$08,$18
		OBJ_HP_SET			$01
		OBJ_DAMAGE_SET		_OBJ_DMG_KILL
		SJSR				_script_sub_obj_show_wait_for_idxCs_80_set
		OBJ_X_DELTA_SET		$F0
		OBJ_Y_DELTA_SET		$00
		NJSR				_native_sub10E
		NJSR				_native_obj_hor_delta_toggle
byte_683A5:
		SPR_IDX_SELECT		_spr_lib7_25
		SJSRS				_script_sub_683BF
		SPR_IDX_SELECT		_spr_lib7_26
		SJSRS				_script_sub_683BF
		SPR_IDX_SELECT		_spr_lib7_27
		SJSRS				_script_sub_683BF
		SPR_IDX_SELECT		_spr_lib7_26
		SJSRS				_script_sub_683BF
		NJSR				_native_obj_hor_move_reverse
		SJMPS				byte_683A5

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_683BF:
		SYNC
		NJSR				_obj_move_hor_animate
		NJSR				_native_obj_x_range60_test_from_byte_AB
		SBCCS				byte_683CE
		LOOPA				$08,_script_sub_683BF
		SRET
byte_683CE:
		LOOPA_RESET
		TARGET_SPD_SET		$30
		TARGET_LOCK			$20
		TARGET_DIR_SET		$FF
byte_683D5:
		SJSRS				_script_sub_68408
		LOOPA				$02,byte_683D5
		NJSR				_native_get_rand_flags
		SBPLS				byte_683E5
		SJSRS				_script_sub_68408
byte_683E5:
		NJSR				_native_sub10E
		OBJ_X_DELTA_SET		$20
		NJSR				_native_obj_hor_delta_toggle
byte_683ED:
		APU_LOAD			_apu_mus64
byte_683EF:
		SPR_IDX_SELECT		_spr_lib7_29
byte_683F1:
		NJSR_SYNC			_native_sub122
		LOOPA				$04,byte_683F1
		SPR_IDX_SELECT		_spr_lib7_2A
byte_683FA:
		NJSR_SYNC			_native_sub122
		LOOPA				$04,byte_683FA
		LOOPB				$02,byte_683EF
		SJMPS				byte_683ED

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_68408:
		APU_LOAD			_apu_mus64
		OBJ_SIZE_SET		$0C,$10
		SPR_IDX_SELECT		_spr_lib7_29
		SJSRS				_script_sub_6841E
		SPR_IDX_SELECT		_spr_lib7_2A
		SJSRS				_script_sub_6841E
		SPR_IDX_SELECT		_spr_lib7_29
		SJSRS				_script_sub_6841E
		SPR_IDX_SELECT		_spr_lib7_2A

; !FALLTHROUGH!

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_6841E:
		TARGET_FOLLOW
		SYNC
		LOOPB				$04,_script_sub_6841E
		SRET

; =============== O B J E C T   S C R I P T =================================
_obj_scr2A_pink_fish:
		DESTR_PC_SET		_obj_scr_common_destr
		NJSR				_scr_flips_04_set
		SPR_LIB_SELECT		_spr_lib7
		OBJ_HP_SET			$01
		OBJ_DAMAGE_SET		_OBJ_DMG_KILL
		OBJ_SIZE_SET		$08,$20
byte_68434:
		OBJ_SHOW
		APU_LOAD			_apu_mus65
		SPR_IDX_SELECT		_spr_lib7_1D
		SUSPEND				$04
		SPR_IDX_SELECT		_spr_lib7_1E
		SUSPEND				$04
		NJSR				_native_sub114
		NJSR				_scr_flips_04_clear
		OBJ_Y_DELTA_SET		$B7
		SJSRS				_script_sub_6846D
		OBJ_Y_DELTA_SET		$00
		SJSRS				_script_sub_6846D
		NJSR				_scr_flips_04_set
		NJSR				_native_sub114
		APU_LOAD			_apu_mus65
		SPR_IDX_SELECT		_spr_lib7_23
		SUSPEND				$04
		SPR_IDX_SELECT		_spr_lib7_24
		SUSPEND				$04
		OBJ_HIDE
		SUSPEND				$F0
		NJSR				_native_get_rand_flags
		SBPLS				byte_68434
		SUSPEND				$78
		SJMPS				byte_68434

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_6846D:
		SPR_IDX_SELECT		_spr_lib7_1F
		SJSRS				_script_sub_6847E
		SPR_IDX_SELECT		_spr_lib7_20
		SJSRS				_script_sub_6847E
		LOOPA				$02,_script_sub_6846D
		HFLIP_TOGGLE
		VFLIP_TOGGLE
		SRET

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_6847E:
		SYNC
		OBJ_Y_DELTA_INC
		OBJ_Y_DELTA_INC
		NJSR				_obj_vert_animate
		LOOPB				$09,_script_sub_6847E
		SRET

; =============== O B J E C T   S C R I P T =================================
_obj_scr2B_fake_boxB:
		OBJ_X_POS_MOVE		$F8
		DESTR_PC_SET		byte_68527
byte_6848E:
		SPR_LIB_SELECT		_spr_lib7
		SPR_IDX_SELECT		_spr_lib7_4C
		OBJ_HP_SET			$02
		OBJ_DAMAGE_SET		_OBJ_DMG_KILL
		OBJ_SHOW
byte_68497:
		OBJ_SIZE_SET		$08,$0F
byte_6849A:
		SJSRS				_script_sub_68514
		NJSR				_native_obj_y_collision_test_from_byte_AB
		SBCSS				byte_6849A
		NJSR				_native_obj_x_range30_test_from_byte_AB
		SBCSS				byte_6849A
		NJSR				_native_sub10E
byte_684AC:
		OBJ_Y_POS_MOVE		$FE
		SJSRS				_script_sub_6851F
		OBJ_Y_POS_MOVE		$02
		APU_LOAD			_apu_mus60
		SJSRS				_script_sub_6851F
		SJSRS				_script_sub_6851F
		LOOPA				$03,byte_684AC
		NJSR				_native_sub10E
		SPR_IDX_SELECT		_spr_lib7_2B
		SJSRS				_script_sub_6851F
		SPR_IDX_SELECT		_spr_lib7_2C
		SJSRS				_script_sub_6851F
		SPR_IDX_SELECT		_spr_lib7_2D
		SJSRS				_script_sub_6851F
		SPR_IDX_SELECT		_spr_lib7_2E
		SRUN				_OBJ_TYPE_EBULLET,_script102
		SBCSS				byte_6849A
		NJSR				_native_obj_to_obj_idxCs_link
		OBJ_SIZE_SET		$08,$28
byte_684E0:
		SJSRS				_script_sub_6851F
		SPR_IDX_SELECT		_spr_lib7_2F
		SJSRS				_script_sub_6851F
		SPR_IDX_SELECT		_spr_lib7_30
		LOOPA				$14,byte_684E0
		NJSR				_native_obj_disable_from_idxCs_40_flag
		SPR_IDX_SELECT		_spr_lib7_2E
		SJSRS				_script_sub_6851F
		SPR_IDX_SELECT		_spr_lib7_2D
		SJSRS				_script_sub_6851F
		SPR_IDX_SELECT		_spr_lib7_2C
		SJSRS				_script_sub_6851F
		SPR_IDX_SELECT		_spr_lib7_2B
		SJSRS				_script_sub_6851F
		SPR_IDX_SELECT		_spr_lib7_4C
		OBJ_SIZE_SET		$08,$10
byte_6850A:
		SJSRS				_script_sub_6851F
		LOOPA				$0A,byte_6850A
		SJMPS				byte_68497

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_68514:
		SYNC
		NJSR				_native_obj_to_tile_collision_test_down
		SBCSS				byte_6851E
		SJSR				_script_sub_obj_wait_for_jump
byte_6851E:
		SRET

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_6851F:
		SJSRS				_script_sub_68514
		LOOPB				$06,_script_sub_6851F
		SRET
byte_68527:
		NJSR				_native_obj_disable_from_idxCs_40_flag
		SPR_IDX_SELECT		_spr_lib7_31
		OBJ_SIZE_SET		$08,$1C
		NJSR				_native_get_obj_hp
		SBEQ				_obj_scr_common_destr
		SJSR				_script_sub_6809D
		SJMP				byte_6848E	; LONG

; =============== S C R I P T ===============================================
_script102:
		OBJ_HP_SET			$FF
		OBJ_DAMAGE_SET		_OBJ_DMG_STUN
		OBJ_SIZE_SET		$08,$10
byte_68542:
		NJSR				_native_obj_linked_idxCs_follow
		OBJ_Y_POS_MOVE		$18
		NJSR_SYNC			_native_obj_hor_bounce0C
		SJMPS				byte_68542

; =============== O B J E C T   S C R I P T =================================
_obj_scr2D_candle_dancing:
		DESTR_PC_SET		_obj_scr2D_candle_dancing_destr
		SPR_LIB_SELECT		_spr_lib7
		SPR_IDX_SELECT		_spr_lib7_32
		OBJ_HP_SET			$02
		OBJ_DAMAGE_SET		_OBJ_DMG_KILL
		OBJ_SIZE_SET		$05,$20
		SJSR				_script_sub_obj_show_wait_for_idxCs_80_set
		NJSR				_native_sub10E
byte_68561:
		SJSRS				_script_sub_68587
		OBJ_X_DELTA_SET		$E0
		NJSR				_native_obj_hor_delta_toggle
byte_68569:
		SJSRS				_script_sub_685AE
		LOOPA				$04,byte_68569
		SJSRS				_script_sub_6859D
		OBJ_X_DELTA_SET		$F0
		OBJ_Y_DELTA_SET		$CF
		SJSRS				_script_sub_685CD
		NJSR				_native_obj_hor_move_reverse
		OBJ_X_DELTA_SET		$10
		OBJ_Y_DELTA_SET		$CF
		SJSRS				_script_sub_685CD
		SJMPS				byte_68561

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_68587:
		OBJ_X_DELTA_SET		$00
		TARGET_DIR_SET		$18
		SJSRS				_script_sub_685AE
		TARGET_DIR_SET		$1A
		SJSRS				_script_sub_685AE
		TARGET_DIR_SET		$1C
		SJSRS				_script_sub_685AE
		TARGET_DIR_SET		$1E
		SJMPS				_script_sub_685AE

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_6859D:
		OBJ_X_DELTA_SET		$00
		TARGET_DIR_SET		$1C
		SJSRS				_script_sub_685AE
		TARGET_DIR_SET		$1A
		SJSRS				_script_sub_685AE
		TARGET_DIR_SET		$18
		SJMPS				_script_sub_685AE

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_685AE:
		SJSRS				_script_sub_685EA
		SPR_IDX_SELECT		_spr_lib7_33
		SJSRS				_script_sub_685EA
		SPR_IDX_SELECT		_spr_lib7_34
		SJSRS				_script_sub_685EA
		SPR_IDX_SELECT		_spr_lib7_35
		SJSRS				_script_sub_685EA
		SPR_IDX_SELECT		_spr_lib7_36
		SJSRS				_script_sub_685EA
		SPR_IDX_SELECT		_spr_lib7_37
		SJSRS				_script_sub_685EA
		SPR_IDX_SELECT		_spr_lib7_32
		SRET

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_685CD:
		NJSR				_native_obj_hor_delta_toggle
		SPR_IDX_SELECT		_spr_lib7_38
		SUSPEND				$06
		SPR_IDX_SELECT		_spr_lib7_39
		SUSPEND				$06
		SPR_IDX_SELECT		_spr_lib7_3A
		SUSPEND				$06
		TARGET_DIR_SET		$1E
byte_685DE:
		SJSRS				_script_sub_685AE
		NJSR				_native_get_obj_y_delta
		SBNES				byte_685DE
		OBJ_X_DELTA_SET		$00
		SRET

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_685EA:
		NJSR				_native_sub000
		NJSR				_native_get_obj_y_delta
		SBPLS				byte_685F5
		APU_LOAD			_apu_mus6B
byte_685F5:
		SYNC
		NJSR				_native_get_obj_y_delta
		SBNES				byte_68613
		NJSR				_obj_move_hor_animate
		NJSR				_native_obj_to_tile_collision_test_hor
		SBCSS				byte_6860A
		OBJ_Y_DELTA_SET		$CF
		SJMPS				byte_68638
byte_6860A:
		NJSR				_native_obj_to_tile_collision_test_down
		SBCCS				byte_68636
		SJMPS				byte_68638
byte_68613:
		NJSR				_obj_move_hor_animate
		NJSR				_native_obj_to_tile_collision_test_hor
		NJSR				_native_obj_y_parabolic_delta_adjust
		NJSR				_native_get_obj_y_delta
		SBMIS				byte_6862D
		NJSR				_native_sub10B
		SBCCS				byte_68638
		OBJ_Y_DELTA_SET		$00
		SJMPS				byte_68638
byte_6862D:
		NJSR				_obj_vert_animate
		NJSR				_native_obj_to_tile_collision_test_up
		SBCSS				byte_68638
byte_68636:
		OBJ_Y_DELTA_SET		$01
byte_68638:
		LOOPB				$20,byte_685F5
		SRET

; =============== S U B R O U T I N E =======================================
_native_sub000:
		LDA		_scr_vars19,X
		STA		_scr_loopsB,X
		RTS

; =============== O B J E C T   S C R I P T =================================
_obj_scr2D_candle_dancing_destr:
		SPR_IDX_SELECT		_spr_lib7_3B
		NJSR				_native_get_obj_hp
		SBEQ				_obj_scr_common_destr
		OBJ_SIZE_SET		$05,$18
		SJSR				_script_sub_680E7
		OBJ_X_DELTA_SET		$00
		NJSR				_scr_flips_04_clear
byte_68657:
		SPR_IDX_SELECT		_spr_lib7_3B
		SJSRS				_script_sub_6867F
		SPR_IDX_SELECT		_spr_lib7_3C
		SJSRS				_script_sub_6867F
		LOOPB				$14,byte_68657
		NJSR				_native_obj_blink_set
byte_68668:
		SPR_IDX_SELECT		_spr_lib7_3B
		SJSRS				_script_sub_6867F
		SPR_IDX_SELECT		_spr_lib7_3C
		SJSRS				_script_sub_6867F
		LOOPB				$05,byte_68668
		NJSR				_native_obj_blink_clear
		NJSR				_native_obj_disable_from_idxCs_40_flag
		SJMP				_obj_scr2D_candle_dancing

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_6867F:
		SYNC
		NJSR				_native_get_obj_idxBs
		SBMIS				byte_68694
		NJSR				_native_obj_to_tile_collision_test_down
		SBCSS				byte_6868F
		SJSR				_script_sub_obj_jump_calcs
byte_6868F:
		LOOPA				$0C,_script_sub_6867F
		SRET
byte_68694:
		SPR_IDX_SELECT		_spr_lib7_5C
		SJSR				_script_sub_68102
		OBJ_DAMAGE_SET		_OBJ_DMG_STUN
		OBJ_X_DELTA_SET		$C0
		NJSR				_native_sub11B
		NJSR				_native_sub11C
		NJSR				_native_obj_type_change_stunA
		SJMP				_script_sub_infinite_anim_sync

; =============== O B J E C T   S C R I P T =================================
_obj_scr2E_ghost_dogA:
		SJSR				_script_wait_for_idxCs_80_set
byte_686AC:
		NJSR_SYNC			_native_sub11E
		SBNES				byte_686AC
		NJSR				_native_cmp40_obj_x_lo_pos
		SBCSS				byte_686AC
		NJSR				_native_cmpC0_obj_x_lo_pos
		SBCCS				byte_686AC
		SRUN				_OBJ_TYPE_ENEMY,_script103
		SUSPEND				$3D
		SJMPS				byte_686AC

; =============== S C R I P T ===============================================
_script103:
		SUSPEND				$1E
		DESTR_PC_SET		_obj_scr_common_destr
		SPR_LIB_SELECT		_spr_lib9
		OBJ_HP_SET			$01
		OBJ_DAMAGE_SET		_OBJ_DMG_KILL
		OBJ_SHOW
		OBJ_SIZE_SET		$08,$14
		OBJ_X_DELTA_SET		$10
		OBJ_X_POS_SET		$80,$00
		NJSR				_native_sub001
		NJSR				_native_obj_hor_bounce7E
		NJSR				_native_obj_hor_move_reverse
		NJSR				_native_obj_hor_delta_toggle
byte_686E7:
		SPR_IDX_SELECT		_spr_lib9_00
		SJSRS				_script_sub_6870C
		SPR_IDX_SELECT		_spr_lib9_01
		SJSRS				_script_sub_6870C
		SPR_IDX_SELECT		_spr_lib9_02
		SJSRS				_script_sub_6870C
		LOOPA				$03,byte_686E7
		SPR_IDX_SELECT		_spr_lib9_03
		SJSRS				_script_sub_6870C
		SPR_IDX_SELECT		_spr_lib9_04
		SJSRS				_script_sub_6870C
		SPR_IDX_SELECT		_spr_lib9_05
		SJSRS				_script_sub_6870C
		SJMPS				byte_686E7

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_6870C:
		NJSR_SYNC			_native_sub122
		LOOPA				$04,_script_sub_6870C
		SRET

; =============== S U B R O U T I N E =======================================
_native_sub001:
		LDY		byte_AB
		LDA		_obj_flips,Y
		AND		#_OBJ_HFLIP
		ORA		_obj_flips,X
		STA		_obj_flips,X
		RTS

; =============== O B J E C T   S C R I P T =================================
_obj_scr2F_ghost_dogB:
		NJSR_SYNC			_native_sub11E
		SBEQS				byte_68729
		KILL
byte_68729:
		DESTR_PC_SET		_obj_scr_common_destr
		SPR_LIB_SELECT		_spr_lib9
		SPR_IDX_SELECT		_spr_lib9_00
		OBJ_HP_SET			$01
		OBJ_DAMAGE_SET		_OBJ_DMG_KILL
		OBJ_SIZE_SET		$08,$14
		SJSR				_script_sub_obj_show_wait_for_idxCs_80_set
		NJSR				_native_sub10E
		TARGET_DIR_SET		$20
byte_6873F:
		SPR_IDX_SELECT		_spr_lib9_00
		SJSRS				_script_sub_68751
		SPR_IDX_SELECT		_spr_lib9_01
		SJSRS				_script_sub_68751
		SPR_IDX_SELECT		_spr_lib9_02
		SJSRS				_script_sub_68751
		SJMPS				byte_6873F

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_68751:
		NJSR				_native_sub123
		NJSR				_native_sub124
		NJSR				_native_obj_hflip_test
		SBNES				byte_68763
		NJSR				_native_inc_vars19
		SJMPS				byte_68766
byte_68763:
		NJSR				_native_dec_vars19
byte_68766:
		NJSR				_obj_vert_animate
		OBJ_ANIMATE_SYNC
		NJSR				_native_obj_x_range40_test_from_byte_AB
		SBCSS				byte_68773
		BREAK				byte_68778
byte_68773:
		LOOPB				$04,_script_sub_68751
		SRET
byte_68778:
		TARGET_LOCK			$18
		NJSR				_native_sub10E
		NJSR				_native_sub111
		LOOPA_RESET
byte_68781:
		SPR_IDX_SELECT		_spr_lib9_00
		SJSRS				_script_sub_687A2
		SPR_IDX_SELECT		_spr_lib9_01
		SJSRS				_script_sub_687A2
		SPR_IDX_SELECT		_spr_lib9_02
		SJSRS				_script_sub_687A2
		SPR_IDX_SELECT		_spr_lib9_03
		SJSRS				_script_sub_687A2
		SPR_IDX_SELECT		_spr_lib9_04
		SJSRS				_script_sub_687A2
		SPR_IDX_SELECT		_spr_lib9_05
		SJSRS				_script_sub_687A2
		SJMPS				byte_68781

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_687A2:
		SYNC
		TARGET_DIR_SET		$FF
		TARGET_FOLLOW
		LOOPA				$04,_script_sub_687A2
		SRET

; =============== O B J E C T   S C R I P T =================================
_obj_scr2C_sailor_monkey:
		DESTR_PC_SET		_obj_scr_common_destr
		SPR_LIB_SELECT		_spr_lib7
		SPR_IDX_SELECT		_spr_lib7_4D
		OBJ_HP_SET			$02
		OBJ_DAMAGE_SET		_OBJ_DMG_KILL
		OBJ_SIZE_SET		$0C,$20
		SJSR				_script_sub_obj_show_wait_for_idxCs_80_set
		OBJ_Y_DELTA_SET		$10
byte_687BE:
		APU_LOAD			_apu_mus68
byte_687C0:
		NJSR_SYNC			_obj_vert_animate
		LOOPA				$08,byte_687C0
		LOOPB				$04,byte_687BE
		NJSR				_native_complement_y_deltas
		NJSR				_native_get_rand_scale3
		SSWITCH				_tmp_ptrE+1
		SCASE				byte_687BE
		SCASE				byte_687DA
		SCASE				byte_687DF
byte_687DA:
		SUSPEND				$78
		SJMPS				byte_687BE
byte_687DF:
		SPR_IDX_SELECT		_spr_lib7_4E
		SUSPEND				$10
		SPR_IDX_SELECT		_spr_lib7_4F
		SRUN				_OBJ_TYPE_EBULLET,_script104
		SUSPEND				$10
		SPR_IDX_SELECT		_spr_lib7_4E
		SUSPEND				$10
		SPR_IDX_SELECT		_spr_lib7_4F
		SRUN				_OBJ_TYPE_EBULLET,_script105
		SUSPEND				$10
		SPR_IDX_SELECT		_spr_lib7_4D
		SUSPEND				$10
		SJMPS				byte_687BE

; =============== S C R I P T ===============================================
_script104:
		OBJ_X_DELTA_SET		$18
		SJMPS				byte_68805

; =============== S C R I P T ===============================================
_script105:
		OBJ_X_DELTA_SET		$0C
byte_68805:
		OBJ_X_POS_MOVE		$1C
		OBJ_Y_POS_MOVE		$F8
		NJSR				_native_obj_idxCs_80_set
		SPR_LIB_SELECT		_spr_lib7
		OBJ_Y_DELTA_SET		$00
		OBJ_SHOW
		OBJ_HP_SET			$01
		OBJ_DAMAGE_SET		_OBJ_DMG_KILL
		OBJ_SIZE_SET		$06,$08
byte_68818:
		SPR_IDX_SELECT		_spr_lib7_50
byte_6881A:
		OBJ_ANIMATE_SYNC
		OBJ_Y_DELTA_INC
		OBJ_Y_DELTA_INC
		LOOPA				$08,byte_6881A
		SPR_IDX_SELECT		_spr_lib7_51
byte_68823:
		OBJ_ANIMATE_SYNC
		OBJ_Y_DELTA_INC
		OBJ_Y_DELTA_INC
		LOOPA				$08,byte_68823
		SJMPS				byte_68818

; =============== O B J E C T   S C R I P T =================================
_obj_scr30_penguin:
		DESTR_PC_SET		byte_688AC
		SPR_LIB_SELECT		_spr_lib7
		SPR_IDX_SELECT		_spr_lib7_53
		OBJ_HP_SET			$02
		OBJ_DAMAGE_SET		_OBJ_DMG_KILL
		OBJ_SIZE_SET		$0A,$20
		SJSR				_script_sub_obj_show_wait_for_idxCs_80_set
		NJSR				_native_sub10E
byte_68841:
		OBJ_X_DELTA_SET		$18
		SPR_IDX_SELECT		_spr_lib7_52
		SJSRS				_script_sub_68867
		OBJ_X_DELTA_SET		$10
		SPR_IDX_SELECT		_spr_lib7_53
		SJSRS				_script_sub_68867
		OBJ_X_DELTA_SET		$E8
		SPR_IDX_SELECT		_spr_lib7_54
		SJSRS				_script_sub_68867
		OBJ_X_DELTA_SET		$F0
		SPR_IDX_SELECT		_spr_lib7_53
		SJSRS				_script_sub_68867
byte_6885D:
		SPR_IDX_SELECT		_spr_lib7_53
		SUSPEND				$1E
		NJSR				_native_obj_hor_move_reverse
		SJMPS				byte_68841

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_68867:
		LOOPA_RESET
		APU_LOAD			_apu_mus40
		NJSR				_native_obj_hor_delta_toggle
byte_6886D:
		SYNC
		NJSR				_obj_move_hor_animate
		NJSR				_native_obj_to_tile_collision_test_hor
		SBCSS				byte_6887A
		BREAK				byte_6885D
byte_6887A:
		NJSR				_native_obj_to_tile_collision_test_down
		SBCC				_script_sub_obj_wait_for_jump
		LOOPA				$0E,byte_6886D
		NJSR				_native_obj_x_range30_test_from_byte_AB
		SBCCS				byte_6888B
		SRET
byte_6888B:
		SPR_IDX_SELECT		_spr_lib7_55
		OBJ_X_DELTA_SET		$30
		NJSR				_native_sub10E
		NJSR				_native_obj_hor_delta_toggle
byte_68895:
		SYNC
		NJSR				_obj_move_hor_animate
		NJSR				_native_obj_to_tile_collision_test_hor
		SBCCS				byte_688A9
		NJSR				_native_obj_to_tile_collision_test_down
		SBCC				_script_sub_obj_wait_for_jump
		LOOPA				$20,byte_68895
byte_688A9:
		BREAK				byte_68841
byte_688AC:
		SPR_IDX_SELECT		_spr_lib7_56
		NJSR				_native_get_obj_hp
		SBEQ				_obj_scr_common_destr
		SJSR				_script_sub_6809D
		SJMP				_obj_scr30_penguin

; =============== O B J E C T   S C R I P T =================================
_obj_scr31_ski_rat:
		DESTR_PC_SET		_obj_scr_common_destr
		SPR_LIB_SELECT		_spr_lib7
		SPR_IDX_SELECT		_spr_lib7_57
		OBJ_SIZE_SET		$0C,$18
		OBJ_HP_SET			$01
		OBJ_DAMAGE_SET		_OBJ_DMG_KILL
		SJSR				_script_sub_obj_show_wait_for_idxCs_80_set
		NJSR				_native_sub10E
byte_688CE:
		OBJ_X_DELTA_SET		$E0
		OBJ_Y_DELTA_SET		$00
		NJSR				_native_obj_hor_delta_toggle
		APU_LOAD			_apu_mus41
		SPR_IDX_SELECT		_spr_lib7_57
byte_688D9:
		SJSRS				_script_sub_688F8
		NJSR				_native_obj_x_range30_test_from_byte_AB
		SBCCS				byte_6890C
		LOOPA				$08,byte_688D9
		SPR_IDX_SELECT		_spr_lib7_58
byte_688E8:
		SJSRS				_script_sub_688F8
		NJSR				_native_obj_x_range30_test_from_byte_AB
		SBCCS				byte_6890C
		LOOPA				$08,byte_688E8
		SJMPS				byte_688CE

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_688F8:
		SYNC
		NJSR				_obj_move_hor_animate
		NJSR				_native_obj_to_tile_collision_test_hor
		SBCSS				byte_68905
		NJSR				_native_obj_hor_move_reverse
byte_68905:
		NJSR				_native_obj_to_tile_collision_test_down
		SBCC				_script_sub_obj_wait_for_jump
		SRET
byte_6890C:
		OBJ_Y_DELTA_SET		$C0
		SJSR				_script_sub_obj_wait_for_jump
byte_68911:
		NJSR				_obj_move_hor_animate
		NJSR				_native_obj_to_tile_collision_test_hor
		NJSR				_native_sub12C
		NJSR_SYNC			_native_get_obj_x_delta
		SBNES				byte_68911
		SUSPEND				$0A
		NJSR				_native_obj_hor_move_reverse
		OBJ_X_DELTA_SET		$E0
		OBJ_Y_DELTA_SET		$00
		NJSR				_native_obj_hor_delta_toggle
byte_6892C:
		APU_LOAD			_apu_mus41
		SPR_IDX_SELECT		_spr_lib7_57
byte_68930:
		SJSRS				_script_sub_688F8
		LOOPA				$08,byte_68930
		SPR_IDX_SELECT		_spr_lib7_58
byte_68939:
		SJSRS				_script_sub_688F8
		LOOPA				$08,byte_68939
		SJMPS				byte_6892C

; =============== O B J E C T   S C R I P T =================================
_obj_scr32_icicle:
		SUSPEND				$B4
		SRUN				_OBJ_TYPE_EBULLET,_script106
		SJMPS				_obj_scr32_icicle

; =============== S C R I P T ===============================================
_script106:
		NJSR				_native_obj_idxCs_80_set
		OBJ_X_POS_MOVE		$08
		OBJ_Y_POS_MOVE		$12
		SPR_LIB_SELECT		_spr_lib7
		NJSR				_scr_flips_04_set
		OBJ_SHOW
		SPR_IDX_SELECT		_spr_lib7_4B
		SUSPEND				$14
		SPR_IDX_SELECT		_spr_lib7_69
		SUSPEND				$14
		NJSR				_scr_flips_04_clear
		OBJ_SIZE_SET		$05,$10
		OBJ_HP_SET			$01
		OBJ_DAMAGE_SET		_OBJ_DMG_KILL
		SPR_IDX_SELECT		_spr_lib7_59
		SUSPEND				$3C
		APU_LOAD			_apu_mus4E
		SJMP				_script_sub_y_parabolic_delta_infinite_anim_sync

; =============== O B J E C T   S C R I P T =================================
_obj_scr33_hammer_mole:
		DESTR_PC_SET		byte_689C0
		NJSR				_scr_flips_04_set
		SPR_LIB_SELECT		_spr_lib7
		OBJ_HP_SET			$01
		OBJ_DAMAGE_SET		_OBJ_DMG_KILL
		OBJ_SIZE_SET		$08,$14
byte_68983:
		SYNC
		NJSR				_native_obj_x_range40_test_from_byte_AB
		SBCSS				byte_68983
		NJSR				_native_sub10E
		OBJ_SHOW
		SPR_IDX_SELECT		_spr_lib7_64
		SUSPEND				$08
		NJSR				_scr_flips_04_clear
		SPR_IDX_SELECT		_spr_lib7_65
		SUSPEND				$08
byte_68999:
		SRUN				_OBJ_TYPE_EBULLET,_script107
		SPR_IDX_SELECT		_spr_lib7_66
		SUSPEND				$10
		APU_LOAD			_apu_mus50
		SRUN				_OBJ_TYPE_EBULLET,_script108
		SPR_IDX_SELECT		_spr_lib7_67
		SUSPEND				$10
		LOOPA				$02,byte_68999
		SPR_IDX_SELECT		_spr_lib7_65
		SUSPEND				$08
		NJSR				_scr_flips_04_set
		SPR_IDX_SELECT		_spr_lib7_64
		SUSPEND				$08
		OBJ_HIDE
		SUSPEND				$5A
		SJMPS				byte_68983
byte_689C0:
		SPR_IDX_SELECT		_spr_lib7_40
		SJMP				_obj_scr_common_destr

; =============== S C R I P T ===============================================
_script107:
		OBJ_Y_POS_MOVE		$F2
		NJSR				_native_obj_hor_bounce0C
		OBJ_HP_SET			$01
		OBJ_DAMAGE_SET		_OBJ_DMG_KILL
		OBJ_SIZE_SET		$08,$0A
		SUSPEND				$10
		KILL

; =============== S C R I P T ===============================================
_script108:
		OBJ_HP_SET			$01
		OBJ_DAMAGE_SET		_OBJ_DMG_KILL
		OBJ_SIZE_SET		$06,$0F
		SPR_LIB_SELECT		_spr_lib7
		SPR_IDX_SELECT		_spr_lib7_68
		OBJ_X_DELTA_SET		$10
		OBJ_Y_DELTA_SET		$E0
		NJSR				_native_obj_hor_bounce13
		OBJ_SHOW
		HFLIP_CLEAR
byte_689E8:
		SJSRS				_script_sub_689FB
		VFLIP_SET
		SJSRS				_script_sub_689FB
		HFLIP_SET
		SJSRS				_script_sub_689FB
		VFLIP_CLEAR
		SJSRS				_script_sub_689FB
		HFLIP_CLEAR
		SJMPS				byte_689E8

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_689FB:
		OBJ_ANIMATE_SYNC
		NJSR				_native_obj_y_parabolic_delta_adjust
		LOOPA				$04,_script_sub_689FB
		SRET

; =============== O B J E C T   S C R I P T =================================
_obj_scr34_mecha_dog:
		DESTR_PC_SET		_obj_scr_common_destr
		SPR_LIB_SELECT		_spr_lib7
		SPR_IDX_SELECT		_spr_lib7_5E
		OBJ_SIZE_SET		$0C,$18
		OBJ_HP_SET			$01
		OBJ_DAMAGE_SET		_OBJ_DMG_KILL
		SJSR				_script_sub_obj_show_wait_for_idxCs_80_set
		NJSR				_native_sub10E
		OBJ_X_DELTA_SET		$E8
		NJSR				_native_obj_hor_delta_toggle
byte_68A1D:
		APU_LOAD			_apu_mus3E
byte_68A1F:
		SPR_IDX_SELECT		_spr_lib7_5E
		SJSRS				_script_sub_68A69
		SPR_IDX_SELECT		_spr_lib7_5F
		SJSRS				_script_sub_68A69
		SPR_IDX_SELECT		_spr_lib7_5E
		SJSRS				_script_sub_68A69
		SPR_IDX_SELECT		_spr_lib7_5F
		SJSRS				_script_sub_68A69
		LOOPB				$02,byte_68A1F
		NJSR				_native_obj_hor_move_reverse
		SJMPS				byte_68A1D
byte_68A3D:
		SPR_IDX_SELECT		_spr_lib7_60
		SUSPEND				$08
		SPR_IDX_SELECT		_spr_lib7_63
		SUSPEND				$08
		LOOPB				$04,byte_68A3D
		OBJ_X_DELTA_SET		$20
		NJSR				_native_obj_hor_delta_toggle
byte_68A4E:
		SPR_IDX_SELECT		_spr_lib7_62
		SJSRS				_script_sub_68A77
		APU_LOAD			_apu_mus68
		SPR_IDX_SELECT		_spr_lib7_63
		SJSRS				_script_sub_68A77
		SPR_IDX_SELECT		_spr_lib7_41
		SJSRS				_script_sub_68A77
		APU_LOAD			_apu_mus68
		SPR_IDX_SELECT		_spr_lib7_42
		SJSRS				_script_sub_68A77
		SJMPS				byte_68A4E

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_68A69:
		NJSR				_native_obj_x_range30_test_from_byte_AB
		SBCSS				_script_sub_68A77
		NJSR				_native_sub10E
		LOOPA_RESET
		LOOPB_RESET
		BREAK				byte_68A3D

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_68A77:
		SYNC
		NJSR				_obj_move_hor_animate
		NJSR				_native_obj_to_tile_collision_test_hor
		SBCSS				byte_68A86
		LOOPA_RESET
		LOOPB_RESET
		NJSR				_native_obj_hor_move_reverse
byte_68A86:
		NJSR				_native_obj_to_tile_collision_test_down
		SBCC				_script_sub_obj_wait_for_jump
		LOOPA				$07,_script_sub_68A77
		SRET

; =============== O B J E C T   S C R I P T =================================
_obj_scr35_red_bird_with_egg:
		SJSR				_script_wait_for_idxCs_80_set
byte_68A94:
		NJSR_SYNC			_native_sub11E
		SBNES				byte_68A94
		SUSPEND				$1E
		SRUN				_OBJ_TYPE_ENEMY,_script109
		SUSPEND				$1E
		SJMPS				byte_68A94

; =============== O B J E C T   S C R I P T =================================
_obj_scr36_red_bird:
		SJSR				_script_wait_for_idxCs_80_set
byte_68AA8:
		NJSR_SYNC			_native_sub11E
		SBNES				byte_68AA8
		SUSPEND				$1E
		SRUN				_OBJ_TYPE_ENEMY,_script10A
		SUSPEND				$1E
		SJMPS				byte_68AA8

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_68AB9:
		DESTR_PC_SET		_obj_scr_common_destr
		SPR_LIB_SELECT		_spr_lib9
		OBJ_HP_SET			$01
		OBJ_DAMAGE_SET		_OBJ_DMG_KILL
		OBJ_SHOW
		OBJ_SIZE_SET		$10,$20
		OBJ_X_POS_SET		$80,$00
		NJSR				_native_sub001
		NJSR				_native_obj_hor_bounce7E
		NJSR				_native_obj_hor_move_reverse
		NJSR				_native_obj_hor_delta_toggle
		SRET

; =============== S C R I P T ===============================================
_script109:
		OBJ_X_DELTA_SET		$18
		SJSRS				_script_sub_68AB9
byte_68ADB:
		SPR_IDX_SELECT		_spr_lib9_06
		SJSRS				_script_sub_68B01
		APU_LOAD			_apu_mus39
		SPR_IDX_SELECT		_spr_lib9_07
		SJSRS				_script_sub_68B0D
		SPR_IDX_SELECT		_spr_lib9_08
		SJSRS				_script_sub_68B0D
		NJSR				_native_obj_x_range40_test_from_byte_AB
		SBCSS				byte_68ADB
		SRUN				_OBJ_TYPE_ENEMY,_script10B
		SBCSS				byte_68ADB
		OBJ_X_DELTA_SET		$20
		NJSR				_native_obj_hor_delta_toggle
		SJMPS				byte_68B1A

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_68B01:
		OBJ_Y_DELTA_SET		$DF
byte_68B03:
		OBJ_Y_DELTA_INC
		OBJ_Y_DELTA_INC
		OBJ_ANIMATE_SYNC
		LOOPB				$20,byte_68B03
		OBJ_Y_DELTA_SET		$21
		SRET

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_68B0D:
		OBJ_Y_DELTA_DEC
		OBJ_Y_DELTA_DEC
		OBJ_ANIMATE_SYNC
		LOOPB				$10,_script_sub_68B0D
		SRET

; =============== S C R I P T ===============================================
_script10A:
		OBJ_X_DELTA_SET		$20
		SJSRS				_script_sub_68AB9
byte_68B1A:
		SPR_IDX_SELECT		_spr_lib9_09
		SJSRS				_script_sub_68B2E
		APU_LOAD			_apu_mus39
		SPR_IDX_SELECT		_spr_lib9_0A
		SJSRS				_script_sub_68B39
		SPR_IDX_SELECT		_spr_lib9_0B
		SJSRS				_script_sub_68B39
		SJMPS				byte_68B1A

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_68B2E:
		OBJ_Y_DELTA_SET		$EF
byte_68B30:
		OBJ_Y_DELTA_INC
		OBJ_ANIMATE_SYNC
		LOOPB				$20,byte_68B30
		OBJ_Y_DELTA_SET		$11
		SRET

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_68B39:
		OBJ_Y_DELTA_DEC
		OBJ_ANIMATE_SYNC
		LOOPB				$10,_script_sub_68B39
		SRET

; =============== S C R I P T ===============================================
_script10B:
		DESTR_PC_SET		_obj_scr_common_destr
		OBJ_Y_POS_MOVE		$10
		OBJ_HP_SET			$01
		OBJ_DAMAGE_SET		_OBJ_DMG_KILL
		OBJ_SIZE_SET		$06,$0C
		SPR_LIB_SELECT		_spr_lib7
		SPR_IDX_SELECT		_spr_lib7_6A
		OBJ_Y_DELTA_SET		$08
		OBJ_SHOW
byte_68B53:
		SYNC
		NJSR				_native_obj_y_parabolic_delta_adjust
		NJSR				_native_sub10B
		SBCCS				byte_68B53
		OBJ_Y_DELTA_SET		$00
		APU_LOAD			_apu_mus3B
		SPR_IDX_SELECT		_spr_lib7_6B
		SUSPEND				$08
		SPR_IDX_SELECT		_spr_lib7_6C
		SUSPEND				$08
		SPR_IDX_SELECT		_spr_lib7_6D
		SUSPEND				$08
		SPR_IDX_SELECT		_spr_lib7_6F
		SUSPEND				$08
		OBJ_X_DELTA_SET		$10
		NJSR_SYNC			_native_sub10E
		NJSR_SYNC			_native_obj_hor_delta_toggle
byte_68B79:
		SPR_IDX_SELECT		_spr_lib7_6E
		SJSRS				_script_sub_68B90
		SPR_IDX_SELECT		_spr_lib7_6F
		SJSRS				_script_sub_68B90
		SPR_IDX_SELECT		_spr_lib7_70
		SJSRS				_script_sub_68B90
		SPR_IDX_SELECT		_spr_lib7_6F
		SJSRS				_script_sub_68B90
		SJMPS				byte_68B79

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_68B90:
		SYNC
		NJSR				_obj_move_hor_animate
		NJSR				_native_obj_to_tile_collision_test_hor
		SBCCS				byte_68BA5
		NJSR				_native_obj_to_tile_collision_test_down
		SBCCS				byte_68BA5
		LOOPA				$08,_script_sub_68B90
		SRET
byte_68BA5:
		LOOPA_RESET
		SPR_IDX_SELECT		_spr_lib7_6F
		OBJ_Y_DELTA_SET		$C0
		SJSR				_script_sub_obj_wait_for_jump
		BREAK				byte_68B79

; =============== O B J E C T   S C R I P T =================================
_obj_scr37_javelin_rat:
		DESTR_PC_SET		_obj_scr_common_destr
		SPR_LIB_SELECT		_spr_lib7
		SPR_IDX_SELECT		_spr_lib7_43
		OBJ_SIZE_SET		$0C,$18
		OBJ_HP_SET			$01
		OBJ_DAMAGE_SET		_OBJ_DMG_KILL
		SJSR				_script_sub_obj_show_wait_for_idxCs_80_set
		NJSR				_native_sub10E
		OBJ_X_DELTA_SET		$10
		NJSR				_native_obj_hor_delta_toggle
byte_68BC9:
		SPR_IDX_SELECT		_spr_lib7_44
		SJSRS				_script_sub_68C0D
		SPR_IDX_SELECT		_spr_lib7_45
		SJSRS				_script_sub_68C0D
		SPR_IDX_SELECT		_spr_lib7_46
		SJSRS				_script_sub_68C0D
		SPR_IDX_SELECT		_spr_lib7_45
		SJSRS				_script_sub_68C0D
		SJMPS				byte_68BC9
byte_68BE0:
		SPR_IDX_SELECT		_spr_lib7_47
		SUSPEND				$05
		SPR_IDX_SELECT		_spr_lib7_48
		SUSPEND				$05
		LOOPA				$04,byte_68BE0
		APU_LOAD			_apu_mus6D
		SRUN				_OBJ_TYPE_EBULLET,_script10C
		SPR_IDX_SELECT		_spr_lib7_49
		SUSPEND				$2A
byte_68BF6:
		SPR_IDX_SELECT		_spr_lib7_44
		SJSRS				_script_sub_68C22
		SPR_IDX_SELECT		_spr_lib7_45
		SJSRS				_script_sub_68C22
		SPR_IDX_SELECT		_spr_lib7_46
		SJSRS				_script_sub_68C22
		SPR_IDX_SELECT		_spr_lib7_45
		SJSRS				_script_sub_68C22
		SJMPS				byte_68BF6

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_68C0D:
		NJSR				_native_obj_y_collision_test_from_byte_AB
		SBCSS				_script_sub_68C22
		NJSR				_native_obj_x_range60_test_from_byte_AB
		SBCSS				_script_sub_68C22
		NJSR				_native_sub10E
		NJSR				_native_obj_hor_delta_toggle
		BREAK				byte_68BE0

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_68C22:
		SYNC
		NJSR				_obj_move_hor_animate
		NJSR				_native_obj_to_tile_collision_test_hor
		SBCCS				byte_68C37
		NJSR				_native_obj_to_tile_collision_test_down
		SBCCS				byte_68C37
		LOOPA				$0B,_script_sub_68C22
		SRET
byte_68C37:
		LOOPA_RESET
		SPR_IDX_SELECT		_spr_lib7_45
		OBJ_Y_DELTA_SET		$C0
		SJMP				_script_sub_obj_wait_for_jump

; =============== S C R I P T ===============================================
_script10C:
		OBJ_HP_SET			$01
		OBJ_DAMAGE_SET		_OBJ_DMG_KILL
		OBJ_SIZE_SET		$04,$08
		SPR_LIB_SELECT		_spr_lib7
		SPR_IDX_SELECT		_spr_lib7_4A
		OBJ_Y_POS_MOVE		$DF
		OBJ_X_DELTA_SET		$20
		OBJ_Y_DELTA_SET		$E0
		NJSR				_native_obj_hor_bounce13
		OBJ_SHOW
		SJMP				_script_sub_y_parabolic_delta_infinite_anim_sync

; =============== O B J E C T   S C R I P T =================================
_obj_scr3C_violet_bug_fall:
		SJSRS				_script_sub_violet_bug_init	; init sprites and pos
byte_68C5A:
		NJSR_SYNC			_native_cmp20_obj_x_lo_pos	; do nothing if at the sides
		SBCSS				byte_68C5A					; of the screen
		NJSR				_native_cmpE0_obj_x_lo_pos
		SBCCS				byte_68C5A					; when in the active zone,
		OBJ_Y_DELTA_SET		$20							; start to fall
byte_68C68:
		SJSRS				_script_sub_violet_bug_anim	; fall anim draw 5 cycles
		LOOPA				$05,byte_68C68
		OBJ_Y_DELTA_SET		$00							; stop movement
byte_68C71:
		SJSRS				_script_sub_violet_bug_anim	; wait for 4 frames
		LOOPA				$04,byte_68C71
		OBJ_X_DELTA_SET		$20							; fly up and forth diagonally
		OBJ_Y_DELTA_SET		$F0							; initialization
		NJSR				_native_obj_hor_delta_toggle; also toggle hor flipping
byte_68C7F:
		SJSRS				_script_sub_violet_bug_anim	; fly for 2 frames, then
		LOOPA				$02,byte_68C7F				; drop projectile
		SRUN				_OBJ_TYPE_STUNB,_obj_scr_violet_bug_sparkle
		SJMPS				byte_68C7F					; loop until out of screen

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_violet_bug_anim:
		SPR_IDX_SELECT		_spr_lib7_71
		SJSR				_script_animate10
		SPR_IDX_SELECT		_spr_lib7_72
		SJMP				_script_animate10

; =============== O B J E C T   S C R I P T =================================
_obj_scr3D_violet_bug_float:
		SJSRS				_script_sub_violet_bug_init
		TARGET_DIR_SET		$20
byte_68C9C:
		SPR_IDX_SELECT		_spr_lib7_71
		SJSRS				_script_sub_violet_bug_float_anim
		SPR_IDX_SELECT		_spr_lib7_72
		SJSRS				_script_sub_violet_bug_float_anim
		LOOPA				$06,byte_68C9C
		SRUN				_OBJ_TYPE_STUNB,_obj_scr_violet_bug_sparkle
		SJMPS				byte_68C9C

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_violet_bug_float_anim:
		NJSR				_native_sub123
		NJSR				_native_sub124
		NJSR				_native_obj_hflip_test
		SBNES				byte_68CC3
		NJSR				_native_inc_vars19
		SJMPS				byte_68CC6
byte_68CC3:
		NJSR				_native_dec_vars19
byte_68CC6:
		OBJ_ANIMATE_SYNC
		LOOPB				$08,_script_sub_violet_bug_float_anim
		SRET

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_violet_bug_init:
		DESTR_PC_SET		_obj_scr_common_destr
		SPR_LIB_SELECT		_spr_lib7
		SPR_IDX_SELECT		_spr_lib7_71
		OBJ_HP_SET			$01
		OBJ_DAMAGE_SET		_OBJ_DMG_KILL
		OBJ_SIZE_SET		$0A,$14
		SJSR				_script_sub_obj_show_wait_for_idxCs_80_set
		NJSR				_native_sub10E
		SRET

; =============== S C R I P T ===============================================
_obj_scr_violet_bug_sparkle:
		NJSR				_native_obj_idxCs_80_set
		APU_LOAD			_apu_mus29
		OBJ_Y_POS_MOVE		$08
		OBJ_Y_DELTA_SET		$10
		SPR_LIB_SELECT		_spr_lib7
		OBJ_SHOW
		OBJ_HP_SET			$01
		OBJ_DAMAGE_SET		_OBJ_DMG_STUN
		OBJ_SIZE_SET		$04,$08
byte_68CF4:
		SPR_IDX_SELECT		_spr_lib7_73
		SJSR				_script_animate10
		SPR_IDX_SELECT		_spr_lib7_7B
		SJSR				_script_animate10
		SJMPS				byte_68CF4

; =============== O B J E C T   S C R I P T =================================
_obj_scr39_hedgehog:
		SPR_LIB_SELECT		_spr_lib7
		SPR_IDX_SELECT		_spr_lib7_77
		SJSR				_script_sub_obj_show_wait_for_idxCs_80_set
		NJSR				_native_sub10E
_script_hedgehod_main_loop:
		DESTR_PC_SET		_obj_scr_common_destr
		OBJ_SIZE_SET		$0A,$0C
		OBJ_HP_SET			$01
		OBJ_DAMAGE_SET		_OBJ_DMG_KILL
		OBJ_X_DELTA_SET		$08
		NJSR				_native_obj_hor_delta_toggle
byte_68D1A:
		LOOPA_RESET
		SPR_IDX_SELECT		_spr_lib7_77
		SJSRS				_script_obj_hedgehog_ai
		SPR_IDX_SELECT		_spr_lib7_78
		SJSRS				_script_obj_hedgehog_ai
		SPR_IDX_SELECT		_spr_lib7_77
		SJSRS				_script_obj_hedgehog_ai
		SPR_IDX_SELECT		_spr_lib7_79
		SJSRS				_script_obj_hedgehog_ai
_script_hedgehod_turn_around:
		NJSR				_native_obj_hor_move_reverse
		SJMPS				byte_68D1A

; =============== S C R I P T   R O U T I N E ===============================
_script_obj_hedgehog_ai:
		SYNC
		NJSR				_native_obj_to_throw_collision_test_range40
		SBCSS				byte_68D3F
		BREAK				_script_hedgehog_defend
byte_68D3F:
		NJSR				_obj_move_hor_animate
		NJSR				_native_obj_to_tile_collision_test_hor
		SBCSS				byte_68D4B
		BREAK				_script_hedgehod_turn_around
byte_68D4B:
		NJSR				_native_obj_to_tile_collision_test_down
		SBCC				_script_sub_obj_wait_for_jump
		LOOPA				$0E,_script_obj_hedgehog_ai
		SRET
_script_hedgehog_defend:
		DESTR_PC_SET		_obj_scr_hedgehog_destr
		OBJ_SIZE_SET		$0A,$0E
		SPR_IDX_SELECT		_spr_lib7_7A
		NJSR				_native_sub132
byte_68D61:
		OBJ_HP_SET			$02
		SYNC
		LOOPB				$1E,byte_68D61
		SJMPS				_script_hedgehod_main_loop

; =============== O B J E C T   S C R I P T =================================
_obj_scr_hedgehog_destr:
		NJSR				_native_get_obj_hp
		SBEQ				_obj_scr_common_destr
		NJSR				_scr_flips_04_clear
		SJMPS				byte_68D61

; =============== O B J E C T   S C R I P T =================================
_obj_scr3A_running_cock:
		SJSR				_script_wait_for_idxCs_80_set
byte_68D7A:
		SYNC
		NJSR				_native_cmp08_obj_x_lo_pos
		SBCCS				byte_68D7A
		DESTR_PC_SET		_obj_scr_common_destr
		SPR_LIB_SELECT		_spr_lib7
		SPR_IDX_SELECT		_spr_lib7_75
		OBJ_SIZE_SET		$08,$20
		OBJ_HP_SET			$01
		OBJ_DAMAGE_SET		_OBJ_DMG_KILL
		OBJ_SHOW
		OBJ_X_DELTA_SET		$30
		NJSR				_native_sub10E
		NJSR				_native_obj_hor_delta_toggle
byte_68D98:
		SPR_IDX_SELECT		_spr_lib7_74
		SJSRS				_script_sub_68DA5
		SPR_IDX_SELECT		_spr_lib7_76
		SJSRS				_script_sub_68DA5
		SJMPS				byte_68D98

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_68DA5:
		OBJ_Y_DELTA_SET		$E0
byte_68DA7:
		SYNC
		NJSR				_obj_move_hor_animate
		NJSR				_native_obj_to_tile_collision_test_hor
		SBCSS				byte_68DB4
		NJSR				_native_obj_hor_move_reverse
byte_68DB4:
		SJSR				_script_sub_obj_jump_calcs
		SBCCS				byte_68DA7
		SPR_IDX_SELECT		_spr_lib7_75
		SUSPEND				$04
		SRET

; =============== O B J E C T   S C R I P T =================================
_obj_scr38_electric_rat:
		DESTR_PC_SET		_script_sub_68E18
		SPR_LIB_SELECT		_spr_lib5
		SPR_IDX_SELECT		_spr_lib5_3A
		SJSR				_script_sub_obj_show_wait_for_idxCs_80_set
		NJSR				_native_sub10E
		OBJ_SIZE_SET		$06,$1C
		OBJ_DAMAGE_SET		_OBJ_DMG_KILL
byte_68DD1:
		OBJ_HP_SET			$01
		SPR_IDX_SELECT		_spr_lib5_3A
		SUSPEND				$40
		SPR_IDX_SELECT		_spr_lib5_3B
		SUSPEND				$10
byte_68DDB:
		LOOPA_RESET
		LOOPB_RESET
		NJSR				_scr_flips_04_clear
		OBJ_HP_SET			$02
		SJSRS				_script_sub_68DF9
		SJSRS				_script_sub_68DF9
		SRUN				_OBJ_TYPE_EBULLET,_script10E
		SRUN				_OBJ_TYPE_EBULLET,_script10F
		SJSRS				_script_sub_68DF9
		SJSRS				_script_sub_68DF9
		SJMPS				byte_68DD1

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_68DF9:
		APU_LOAD			_apu_mus6F
byte_68DFB:
		SPR_IDX_SELECT		_spr_lib5_3C
		SUSPEND				$02
		SPR_IDX_SELECT		_spr_lib5_3D
		SUSPEND				$02
		LOOPA				$02,byte_68DFB
byte_68E07:
		SPR_IDX_SELECT		_spr_lib5_3E
		SUSPEND				$02
		SPR_IDX_SELECT		_spr_lib5_3F
		SUSPEND				$02
		LOOPA				$02,byte_68E07
		LOOPB				$02,byte_68DFB
		SRET

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_68E18:
		NJSR				_native_get_obj_hp
		SBNES				byte_68DDB
		SPR_IDX_SELECT		_spr_lib5_3A
		SJMP				_obj_scr_common_destr

; =============== S C R I P T ===============================================
_script10F:
		OBJ_X_DELTA_SET		$30
		OBJ_X_POS_MOVE		$08
		HFLIP_CLEAR
		SJMPS				_script_sub_68E30

; =============== S C R I P T ===============================================
_script10E:
		OBJ_X_DELTA_SET		$D0
		OBJ_X_POS_MOVE		$F8
		HFLIP_SET

; !FALLTHROUGH!

; =============== S C R I P T ===============================================
_script_sub_68E30:
		NJSR				_native_obj_idxCs_80_set
		SPR_LIB_SELECT		_spr_lib5
		OBJ_SIZE_SET		$04,$08
		OBJ_HP_SET			$01
		OBJ_DAMAGE_SET		_OBJ_DMG_KILL
		OBJ_SHOW
byte_68E3D:
		SPR_IDX_SELECT		_spr_lib5_05
		SJSRS				_script_sub_68E4A
		SPR_IDX_SELECT		_spr_lib5_40
		SJSRS				_script_sub_68E4A
		SJMPS				byte_68E3D

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_68E4A:
		OBJ_ANIMATE_SYNC
		NJSR				_native_obj_to_tile_collision_test_hor
		SBCCS				byte_68E5C
		NJSR				_native_obj_to_tile_collision_test_down
		SBCCS				byte_68E5C
		LOOPA				$06,_script_sub_68E4A
		SRET
byte_68E5C:
		KILL

; =============== O B J E C T   S C R I P T =================================
_obj_scr3F_lvl1_boss_water_rabbit:
		STORE				_apu_mus1E_idx,_apu_load_idx_req
		SRUN				_OBJ_TYPE_AUTO,_script110
		DESTR_PC_SET		_obj_scr_common_small_boss_destr
		NJSR				_native_obj_idxCs_clear_low_nibble
		OBJ_X_POS_MOVE		$0A
		SPR_LIB_SELECT		_spr_lib8
		SUSPEND				$80
		OBJ_SIZE_SET		$0A,$32
		OBJ_HP_SET			$06
		OBJ_DAMAGE_SET		_OBJ_DMG_KILL
		OBJ_SHOW
		OBJ_X_DELTA_SET		$10
		NJSR				_native_sub10E
		NJSR				_native_obj_hor_delta_toggle
byte_68E81:
		SPR_IDX_SELECT		_spr_lib8_18
		SJSR				_script20A_anim_anim08_sync
		SPR_IDX_SELECT		_spr_lib8_20
		SJSR				_script20A_anim_anim08_sync
		LOOPA				$02,byte_68E81
		SJSRS				_script_sub_68F10
byte_68E92:
		NJSR				_native_get_rand_scale3
		SSWITCH				_tmp_ptrE+1
		SCASE				byte_68E9E
		SCASE				byte_68EB4
		SCASE				byte_68EB4
byte_68E9E:
		OBJ_X_DELTA_SET		$00
		OBJ_Y_DELTA_SET		$00
		NJSR				_native_sub10E
		NJSR				_native_get_rand_flags
		SBPLS				byte_68EAE
		SJSRS				_script_sub_68F2E
byte_68EAE:
		SJSRS				_script_sub_68F2E
		SJSRS				_script_sub_68F10
byte_68EB4:
		OBJ_X_DELTA_SET		$20
		NJSR				_native_obj_hor_delta_toggle
		NJSR				_native_get_rand_flags
		SBPLS				byte_68EC2
		SJSRS				_script_sub_68EC8
byte_68EC2:
		SJSRS				_script_sub_68EC8
		SJMPS				byte_68E92

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_68EC8:
		SPR_IDX_SELECT		_spr_lib8_18
		SJSRS				_script_sub_68ECF
		SPR_IDX_SELECT		_spr_lib8_20

; !FALLTHROUGH!

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_68ECF:
		SYNC
		SJSR				_script20A_anim
		NJSR				_obj_move_hor_animate
		NJSR				_native_sub135
		SBCCS				byte_68EDF
		NJSR				_native_obj_hor_move_reverse
byte_68EDF:
		NJSR				_native_obj_to_tile_collision_test_down
		SBCCS				byte_68EEA
		LOOPB				$0A,_script_sub_68ECF
		SRET
byte_68EEA:
		NJSR				_scr_reset_slot
		NJSR				_native_cmp40_obj_y_lo_pos
		SBEQS				byte_68F01
		NJSR				_native_cmpC0_obj_y_lo_pos
		SBEQS				byte_68EFF
		NJSR				_native_get_rand_flags
		SBPLS				byte_68F01
byte_68EFF:
		OBJ_Y_DELTA_SET		$AE
byte_68F01:
		SPR_IDX_SELECT		_spr_lib8_23
		OBJ_X_DELTA_SET		$00
		SJSR				_script20B
		SPR_IDX_SELECT		_spr_lib8_1E
		SJSR				_script20A_anim_anim06_sync
		SJMPS				byte_68E92

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_68F10:
		OBJ_X_DELTA_SET		$00
		OBJ_Y_DELTA_SET		$00
		SPR_IDX_SELECT		_spr_lib8_15
		SJSR				_script20A_anim_anim06_sync
		SPR_IDX_SELECT		_spr_lib8_16
		SJSR				_script20A_anim_anim06_sync
		SPR_IDX_SELECT		_spr_lib8_17
		SJSR				_script20A_anim_anim06_sync
		SJSR				_script20A_anim_anim06_sync
		SPR_IDX_SELECT		_spr_lib8_16
		SJSR				_script20A_anim_anim06_sync
		SPR_IDX_SELECT		_spr_lib8_15
		SRET

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_68F2E:
		SPR_IDX_SELECT		_spr_lib8_19
		SJSR				_script20A_anim_anim03_sync
		SPR_IDX_SELECT		_spr_lib8_1A
		SJSR				_script20A_anim_anim03_sync
		SPR_IDX_SELECT		_spr_lib8_1B
		SJSR				_script20A_anim_anim10_sync
		SPR_IDX_SELECT		_spr_lib8_1C
		SJSR				_script20A_anim_anim04_sync
		SPR_IDX_SELECT		_spr_lib8_1D
		SJSR				_script20A_anim_anim03_sync
		APU_LOAD			_apu_mus3F
		SRUN				_OBJ_TYPE_EBULLET,_script111
		SPR_IDX_SELECT		_spr_lib8_1E
		SJSR				_script20A_anim_anim06_sync
		LOOPA				$02,_script_sub_68F2E
		SRET

; =============== S C R I P T ===============================================
_script111:
		OBJ_Y_POS_MOVE		$E4
		OBJ_X_DELTA_SET		$20
		NJSR				_native_obj_hor_bounce13
		SPR_LIB_SELECT		_spr_lib8
		OBJ_SIZE_SET		$05,$08
		OBJ_HP_SET			$01
		OBJ_DAMAGE_SET		_OBJ_DMG_KILL
		OBJ_SHOW
byte_68F68:
		SPR_IDX_SELECT		_spr_lib8_21
		SJSRS				_script_sub_68F75
		SPR_IDX_SELECT		_spr_lib8_22
		SJSRS				_script_sub_68F75
		SJMPS				byte_68F68

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_68F75:
		OBJ_ANIMATE_SYNC
		NJSR				_native_obj_y_parabolic_delta_adjust
		LOOPA				$03,_script_sub_68F75
		SRET

; =============== S C R I P T ===============================================
_script110:
		SUSPEND				$F0
byte_68F80:
		NJSR_SYNC			_native_throwable_obj_num_01_cmp
		SBCSS				byte_68F80
		SUSPEND				$3C
		SRUN				_OBJ_TYPE_PBULLET,_script112
		SJMPS				_script110

; =============== S C R I P T ===============================================
_script112:
		OBJ_GRABABLE
		DESTR_PC_SET		_obj_scr_box
		NJSR				_native_get_rand_scale3
		SSWITCH				_tmp_ptrE+1
		SCASE				byte_68F9F
		SCASE				byte_68FA5
		SCASE				byte_68FAB
byte_68F9F:
		OBJ_X_POS_SET		$18,$00
		SJMPS				byte_68FB1
byte_68FA5:
		OBJ_X_POS_SET		$A8,$00
		SJMPS				byte_68FB1
byte_68FAB:
		OBJ_X_POS_SET		$98,$00
		NJSR				_native_obj_hor_move_reverse
byte_68FB1:
		OBJ_Y_POS_SET		$00,$00
		SYNC
		SPR_LIB_SELECT		_spr_lib3
		SPR_IDX_SELECT		_spr_lib3_00
		OBJ_SIZE_SET		$06,$10
		NJSR				_native_idxBs_10_set
		OBJ_SHOW
byte_68FC0:
		OBJ_HP_SET			$01
		OBJ_DAMAGE_SET		_OBJ_DMG_KILL
		OBJ_X_DELTA_SET		$00
		OBJ_Y_DELTA_SET		$01
		NJSR				_native_obj_type_change_throw
byte_68FCB:
		SYNC
		NJSR				_native_obj_y_parabolic_delta_adjust
		NJSR				_native_sub10B
		SBCSS				byte_68FDE
		NJSR				_native_get_obj_hp
		SBNES				byte_68FCB
		SJMP				byte_6A669	; LONG
byte_68FDE:
		NJSR				_native_obj_type_change_solid_no_damage
		NJSR				_native_obj_hor_move_reverse
		OBJ_X_DELTA_SET		$08
		OBJ_Y_DELTA_SET		$00
		NJSR				_native_obj_hor_delta_toggle
byte_68FEB:
		SYNC
		NJSR				_native_get_obj_idxBs
		SBMI				_obj_scr_box
		NJSR				_obj_move_hor_animate
		NJSR				_native_sub13C
		NJSR				_native_obj_to_tile_collision_test_down
		SBCSS				byte_68FEB
		SJMPS				byte_68FC0

; =============== O B J E C T   S C R I P T =================================
_obj_scr40_lvl2_boss_flying_panther:
		STORE				_apu_mus1E_idx,_apu_load_idx_req
		DESTR_PC_SET		_obj_scr_common_small_boss_destr
		NJSR				_native_obj_idxCs_clear_low_nibble
		OBJ_X_POS_MOVE		$0F
		SPR_LIB_SELECT		_spr_lib8
		SUSPEND				$80
		OBJ_SHOW
		OBJ_X_DELTA_SET		$F8
		OBJ_Y_DELTA_SET		$10
byte_69016:
		SJSR				_script_sub_690B0
		LOOPA				$04,byte_69016
		OBJ_SIZE_SET		$0E,$20
		OBJ_HP_SET			$06
		OBJ_DAMAGE_SET		_OBJ_DMG_KILL
byte_69024:
		SJSRS				_script_sub_69039
		SJSRS				_script_sub_6905E
		SJSRS				_script_sub_69039
		SJSRS				_script_sub_69076
		SJSRS				_script_sub_69039
		SJSRS				_script_sub_69076
		SJMPS				byte_69024

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_69039:
		OBJ_X_DELTA_SET		$00
		OBJ_Y_DELTA_SET		$00
byte_6903D:
		SJSRS				_script_sub_690B0
		LOOPA				$03,byte_6903D
		SRUN				_OBJ_TYPE_EBULLET,_script113
		SJSR				_script20A_anim_anim_sync
byte_6904B:
		SJSRS				_script_sub_690B0
		LOOPA				$03,byte_6904B
		SRUN				_OBJ_TYPE_EBULLET,_script113
byte_69056:
		SJSRS				_script_sub_690B0
		LOOPA				$03,byte_69056
		SRET

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_6905E:
		OBJ_X_DELTA_SET		$E0
		OBJ_Y_DELTA_SET		$19
		NJSR				_native_obj_hor_delta_toggle
byte_69065:
		SJSRS				_script_sub_690B0
		NJSR				_native_sub004
		LOOPA				$06,byte_69065
		NJSR				_native_obj_hor_move_reverse
		NJSR				_native_sub114
		SRET

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_69076:
		OBJ_X_DELTA_SET		$E0
		OBJ_Y_DELTA_SET		$20
		NJSR				_native_obj_hor_delta_toggle
byte_6907D:
		SJSRS				_script_sub_690B0
		NJSR				_native_sub004
		LOOPA				$03,byte_6907D
		NJSR				_native_sub114
		OBJ_Y_DELTA_SET		$00
		APU_LOAD			_apu_mus67
byte_6908E:
		SPR_IDX_SELECT		_spr_lib8_0C
		SJSR				_script20A_anim_anim_sync
		SJSR				_script20A_anim_anim_sync
		SPR_IDX_SELECT		_spr_lib8_0D
		SJSR				_script20A_anim_anim_sync
		SJSR				_script20A_anim_anim_sync
		LOOPA				$0C,byte_6908E
		NJSR				_native_obj_hor_move_reverse
		OBJ_X_DELTA_SET		$00
		OBJ_Y_DELTA_SET		$E0
		SJSRS				_script_sub_690B0
		SJSRS				_script_sub_690B0
		SRET

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_690B0:
		APU_LOAD			_apu_mus66
		NJSR				_native_sub002
		SPR_IDX_SELECT		_spr_lib8_09
		SJSRS				_script_sub_690CF
		NJSR				_native_sub003
		SPR_IDX_SELECT		_spr_lib8_0A
		SJSRS				_script_sub_690CF
		NJSR				_native_sub003
		SPR_IDX_SELECT		_spr_lib8_0B
		SJSRS				_script_sub_690CF
		NJSR				_native_sub002
		SPR_IDX_SELECT		_spr_lib8_0A

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_690CF:
		SJSR				_script20A_anim_anim_sync
		NJSR				_native_sub005
		LOOPB				$04,_script_sub_690CF
		SRET

; =============== S U B R O U T I N E =======================================
_native_sub002:
		CLC
		LDA		_obj_y_deltas,X
		ADC		#$10
		STA		_obj_y_deltas,X
		RTS

; =============== S U B R O U T I N E =======================================
_native_sub003:
		SEC
		LDA		_obj_y_deltas,X
		SBC		#$10
		STA		_obj_y_deltas,X
		RTS

; =============== S U B R O U T I N E =======================================
_native_sub004:
		SEC
		LDA		_obj_y_deltas,X
		SBC		#$0A
		STA		_obj_y_deltas,X
		RTS

; =============== S U B R O U T I N E =======================================
_native_sub005:
		LDA		_obj_x_deltas,X
		BNE		locret_6910C
		LDY		#$18
		LDA		_obj_flips,X
		AND		#_OBJ_HFLIP
		BNE		loc_69108
		LDY		#$E8
loc_69108:
		STY		_players_x_deltas
		STY		_players_x_deltas+1
locret_6910C:
		RTS


; =============== S C R I P T ===============================================
_script113:
		OBJ_GRABABLE
		DESTR_PC_SET		byte_6915B
		SPR_LIB_SELECT		_spr_lib8
		SPR_IDX_SELECT		_spr_lib8_0E
		OBJ_HP_SET			$01
		OBJ_DAMAGE_SET		_OBJ_DMG_KILL
		OBJ_SIZE_SET		$06,$10
		OBJ_SHOW
		NJSR_SYNC			_native_sub006
byte_69120:
		NJSR				_native_obj_y_parabolic_delta_adjust
		NJSR_SYNC			_obj_vert_animate
		LOOPA				$20,byte_69120
		TARGET_LOCK			$40
		NJSR				_native_sub111
		NJSR				_native_throwable_obj_num_02_cmp
		SBCS				_script1FE
		SJSR				_script1FF
		OBJ_X_DELTA_SET		$18
		OBJ_Y_DELTA_SET		$00
		NJSR				_native_obj_hor_delta_toggle
byte_6913F:
		SJSR				_script_animate10
		NJSR				_native_sub007
		SBCCS				byte_6913F
		NJSR				_native_obj_type_change_solid_no_damage
byte_6914B:
		SYNC
		NJSR				_native_get_obj_idxBs
		SBMIS				byte_6915B
		NJSR				_native_sub008
		SBCSS				byte_6916B
		SJMPS				byte_6914B
byte_6915B:
		SJSR				_script_obj_wait_for_throw
		NJSR				_native_obj_throw_direction_select
byte_69161:
		OBJ_ANIMATE_SYNC
		NJSR				_native_sub016
		SBNES				byte_69161
		SJMP				_script_sub_y_parabolic_delta_infinite_anim_sync
byte_6916B:
		NJSR				_native_obj_type_change_bullet
		OBJ_X_DELTA_SET		$10
		OBJ_Y_DELTA_SET		$E0
		NJSR				_players_animB_sub3_B_A
		SJMP				_script_sub_y_parabolic_delta_infinite_anim_sync

; =============== S U B R O U T I N E =======================================
_native_sub006:
		LDY		#$40
		LDA		_obj_flips,X
		AND		#_OBJ_HFLIP
		BNE		loc_69183
		LDY		#$C0
loc_69183:
		TYA
		STA		_obj_x_lo_poss,X
		LDA		#$00
		STA		_obj_y_lo_poss,X
		RTS

; =============== S U B R O U T I N E =======================================
_native_sub007:
		LDA		_obj_x_lo_poss,X
		BPL		loc_69194
		EOR		#$FF
loc_69194:
		CMP		#$10
		JMP		_scr_flags_update

; =============== S U B R O U T I N E =======================================
_native_sub008:
		LDA		#$03
		STA		_scr_idxAs,X
		TAY
		JSR		_obj_to_obj_collision_test
		JMP		_scr_flags_update


; =============== O B J E C T   S C R I P T =================================
_obj_scr41_lvl3_boss_sea_rat:
		STORE				_apu_mus1E_idx,_apu_load_idx_req
		STORE				$10,byte_9D
		DESTR_PC_SET		_obj_scr_common_small_boss_destr
		NJSR				_native_obj_idxCs_clear_low_nibble
		SRUN				_OBJ_TYPE_AUTO,_script114
		OBJ_X_POS_MOVE		$20
		SPR_LIB_SELECT		_spr_lib8
		OBJ_SIZE_SET		$08,$20
		OBJ_HP_SET			$06
		OBJ_DAMAGE_SET		_OBJ_DMG_KILL
		SUSPEND				$80
		OBJ_SHOW
		OBJ_X_DELTA_SET		$E8
		SPR_IDX_SELECT		_spr_lib8_27
		SJSR				_script20A_anim_anim10_sync
		SPR_IDX_SELECT		_spr_lib8_26
		SJSR				_script20A_anim_anim10_sync
		SJSRS				_script_sub_691E3
		NJSR				_native_sub009
byte_691D7:
		NJSR				_native_get_rand_scale3
		SSWITCH				_tmp_ptrE+1
		SCASE				byte_69223
		SCASE				byte_691EA
		SCASE				byte_69223

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_691E3:
		SPR_IDX_SELECT		_spr_lib8_24
		OBJ_X_DELTA_SET		$00
		SJMP				_script20A_anim_anim08_sync
byte_691EA:
		NJSR				_native_cmpC0_obj_y_lo_pos
		SBCCS				byte_69229
byte_691F0:
		NJSR				_native_cmp80_obj_x_lo_pos
		SBNES				byte_691FC
		SJSRS				_script_sub_691E3
		NJSR				_native_sub10E
byte_691FC:
		OBJ_X_DELTA_SET		$00
		OBJ_Y_DELTA_SET		$00
		SPR_IDX_SELECT		_spr_lib8_28
		APU_LOAD			_apu_mus3C
		SJSR				_script20A_anim_anim10_sync
		APU_LOAD			_apu_mus3C
		SJSR				_script20A_anim_anim10_sync
byte_6920C:
		SPR_IDX_SELECT		_spr_lib8_29
		APU_LOAD			_apu_mus3D
		SRUN				_OBJ_TYPE_EBULLET,_script115
		SJSR				_script20A_anim_anim03_sync
		SJSR				_script20A_anim_anim08_sync
		SPR_IDX_SELECT		_spr_lib8_24
		SJSR				_script20A_anim_anim10_sync
		LOOPA				$02,byte_6920C
byte_69223:
		NJSR				_native_cmp80_obj_y_lo_pos
		SBCSS				byte_691F0
byte_69229:
		OBJ_X_DELTA_SET		$18
		NJSR				_native_obj_hor_delta_toggle
byte_6922E:
		SYNC
		SPR_IDX_SELECT		_spr_lib8_25
		SJSRS				_script_sub_6927B
		LOOPB				$08,byte_6922E
byte_69238:
		SYNC
		SPR_IDX_SELECT		_spr_lib8_26
		SJSRS				_script_sub_6927B
		LOOPB				$08,byte_69238
byte_69242:
		SYNC
		SPR_IDX_SELECT		_spr_lib8_27
		SJSRS				_script_sub_6927B
		LOOPB				$08,byte_69242
byte_6924C:
		SYNC
		SPR_IDX_SELECT		_spr_lib8_26
		SJSRS				_script_sub_6927B
		LOOPB				$08,byte_6924C
		LOOPA				$02,byte_6922E
		OBJ_X_DELTA_SET		$00
byte_6925C:
		NJSR				_native_get_obj_y_delta
		SBEQS				byte_69269
		SYNC
		SJSRS				_script_sub_6927B
		SJMPS				byte_6925C
byte_69269:
		NJSR				_native_cmp80_obj_x_lo_pos
		SBEQ				byte_691D7
		SJSRS				_script_sub_691E3
		NJSR				_native_obj_hor_move_reverse
		SJSR				_script_sub_691E3
		SJMP				byte_691D7	; LONG

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_6927B:
		SJSR				_script20A_anim
		NJSR				_obj_move_hor_animate
		NJSR				_native_get_obj_y_delta
		SBNES				byte_69290
		NJSR				_native_obj_to_tile_collision_test_down
		SBCCS				byte_6928E
		SRET
byte_6928E:
		OBJ_Y_DELTA_SET		$B0
byte_69290:
		SPR_IDX_SELECT		_spr_lib8_26
		NJSR				_native_obj_y_parabolic_delta_adjust
		SBPLS				byte_6929C
		NJSR				_obj_vert_animate
		SRET
byte_6929C:
		NJSR				_native_sub10B
		SBCCS				byte_692A4
		OBJ_Y_DELTA_SET		$00
byte_692A4:
		SRET

; =============== S U B R O U T I N E =======================================
_native_sub009:
		LDA		_room_flags
		ORA		#$02
		STA		_room_flags
		RTS


; =============== S C R I P T ===============================================
_script114:
		OBJ_FLIPS_SET		_OBJ_FLIPS08
byte_692AE:
		NJSR_SYNC			_native_sub00A
		SBCSS				byte_692AE
		SRUN				_OBJ_TYPE_SOLID,_script116
		SJMPS				byte_692AE

; =============== S U B R O U T I N E =======================================
_native_sub00A:
		LDA		_obj_global_y_shift
		BEQ		loc_692DC
		LDY		_ppu_scroll_shadow_hi
		CPY		#$D0
		BEQ		loc_692CD
		CPY		#$80
		BEQ		loc_692CD
		CPY		#$30
		BNE		loc_692DC
loc_692CD:
		LDA		#$18
		LDY		_obj_x_lo_poss,X
		BMI		loc_692D6
		LDA		#$E8
loc_692D6:
		STA		_obj_x_lo_poss,X
		JMP		_native_throwable_obj_num_01_cmp
loc_692DC:
		SEC
		JMP		_scr_flags_update


; =============== S C R I P T ===============================================
_script116:
		OBJ_GRABABLE
		DESTR_PC_SET		_obj_scr_box
		OBJ_Y_POS_SET		$00,$00
		SPR_LIB_SELECT		_spr_lib3
		SPR_IDX_SELECT		_spr_lib3_00
		OBJ_SIZE_SET		$06,$10
		OBJ_HP_SET			$01
		OBJ_SHOW
byte_692F1:
		NJSR_SYNC			_native_get_obj_idxBs
		SBMI				_obj_scr_box
		SJMPS				byte_692F1

; =============== S C R I P T ===============================================
_script115:
		OBJ_Y_POS_MOVE		$E9
		OBJ_X_DELTA_SET		$30
		NJSR				_native_obj_hor_bounce2C
		SPR_LIB_SELECT		_spr_lib8
		OBJ_SIZE_SET		$04,$06
		OBJ_HP_SET			$01
		OBJ_DAMAGE_SET		_OBJ_DMG_KILL
		OBJ_SHOW
byte_6930B:
		SPR_IDX_SELECT		_spr_lib8_2A
		SJSR				_script_animate10
		SPR_IDX_SELECT		_spr_lib8_2B
		SJSR				_script_animate10
		SJMPS				byte_6930B

; =============== O B J E C T   S C R I P T =================================
_obj_scr42_lvl4_boss_ghost:
		STORE				_apu_mus0E_idx,_apu_load_idx_req
		DESTR_PC_SET		_script_sub_694CA
		NJSR				_native_obj_idxCs_clear_low_nibble
		OBJ_HP_SET			$07
		OBJ_DAMAGE_SET		_OBJ_DMG_KILL
		STORE				$00,byte_E0
		SJSR				_script_sub_69531
		SJMPS				byte_69350
byte_69330:
		SPR_IDX_SELECT		_spr_lib8_0F
		OBJ_SIZE_SET		$00,$00
		OBJ_X_DELTA_SET		$00
		OBJ_Y_DELTA_SET		$00
byte_69339:
		SJSR				_script_sub_69492
		SSWITCH				byte_E0
		SCASE				byte_69343
		SCASE				byte_69339
byte_69343:
		OBJ_HIDE
		PAL_FADE_OUT		$04,$87
		SUSPEND				$1E
		OBJ_HIDE
		PAL_FADE_IN			$04,$8F
		SJSR				_script_sub_69531
byte_69350:
		PAL_FADE_OUT		$04,$8F
		SUSPEND				$1E
		OBJ_X_POS_SET		$C8,$00
		OBJ_Y_POS_SET		$90,$00
		SPR_LIB_SELECT		_spr_lib8
		SPR_IDX_SELECT		_spr_lib8_0F
		NJSR				_native_sub00C
		CHR_SELECT			$00,$1B
		PAL_FADE_IN			$04,$87
		SUSPEND				$10
		OBJ_SHOW
		OBJ_SIZE_SET		$14,$30
		OBJ_Y_DELTA_SET		$10
byte_69370:
		SJSR				_script_sub_69492
		LOOPA				$30,byte_69370
		NJSR				_native_complement_y_deltas
		LOOPB				$02,byte_69370
		OBJ_Y_DELTA_SET		$00
byte_69380:
		SJSR				_script_sub_69492
		LOOPA				$1E,byte_69380
		SPR_IDX_SELECT		_spr_lib8_10
		APU_LOAD			_apu_mus6C
		NJSR_SYNC			_native_box_bonus_4prizes_shuffle
		NJSR				_native_get_rand_scale3
		SSWITCH				_tmp_ptrE+1
		SCASE				byte_69412
		SCASE				byte_693D6
		SCASE				byte_6939A
byte_6939A:
		OBJ_X_DELTA_SET		$F9
		NJSR				_native_get_rand_flags
		SBPLS				byte_693AF
byte_693A2:
		SJSRS				_script_sub_693BC
		SJSRS				_script_sub_693C9
		LOOPA				$02,byte_693A2
		SJMPS				byte_69330
byte_693AF:
		SJSRS				_script_sub_693C9
		SJSRS				_script_sub_693BC
		LOOPA				$02,byte_693AF
		SJMP				byte_69330	; LONG

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_693BC:
		OBJ_Y_DELTA_SET		$D8
byte_693BE:
		OBJ_Y_DELTA_INC
		SJSR				_script_sub_69492
		LOOPB				$4E,byte_693BE
		SJMPS				byte_6940D

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_693C9:
		OBJ_Y_DELTA_SET		$28
byte_693CB:
		OBJ_Y_DELTA_DEC
		SJSR				_script_sub_69492
		LOOPB				$4E,byte_693CB
		SJMPS				byte_6940D
byte_693D6:
		OBJ_X_DELTA_SET		$E8
		NJSR				_native_get_rand_flags
		SBPLS				byte_693E7
		SJSRS				_script_sub_693F0
		SJSRS				_script_sub_69400
		SJMP				byte_69330	; LONG
byte_693E7:
		SJSRS				_script_sub_69400
		SJSRS				_script_sub_693F0
		SJMP				byte_69330	; LONG

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_693F0:
		OBJ_Y_DELTA_SET		$E8
		SJSRS				_script_sub_693F5

; !FALLTHROUGH!

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_693F5:
		OBJ_Y_DELTA_INC
		SJSR				_script_sub_69492
		LOOPB				$17,_script_sub_693F5
		SJMPS				byte_6940D

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_69400:
		OBJ_Y_DELTA_SET		$18
		SJSRS				_script_sub_69405

; !FALLTHROUGH!

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_69405:
		OBJ_Y_DELTA_DEC
		SJSR				_script_sub_69492
		LOOPB				$17,_script_sub_69405
byte_6940D:
		SRUN				_OBJ_TYPE_EBULLET,_script118
		SRET
byte_69412:
		SRUN				_OBJ_TYPE_EBULLET,_script119
		OBJ_X_DELTA_SET		$00
		OBJ_Y_DELTA_SET		$00
byte_6941A:
		SJSRS				_script_sub_69492
		LOOPA				$78,byte_6941A
		OBJ_X_DELTA_SET		$DC
		OBJ_Y_DELTA_SET		$0A
byte_69425:
		SJSRS				_script_sub_69492
		LOOPA				$21,byte_69425
		LOOPB				$02,byte_69412
		SJMP				byte_69330	; LONG

; =============== S C R I P T ===============================================
_script118:
		OBJ_GRABABLE
		NJSR				_native_get_box_bonus_prize_from_list
		SSWITCH				_tmp_ptrE+1
		SCASE				byte_69442
		SCASE				byte_69442
		SCASE				byte_69443
		SCASE				byte_69443
byte_69442:
		KILL
byte_69443:
		APU_LOAD			_apu_mus2B
		OBJ_X_POS_MOVE		$D4
		OBJ_Y_POS_MOVE		$E5
		DESTR_PC_SET		byte_69B00
		SPR_LIB_SELECT		_spr_lib8
		SPR_IDX_SELECT		_spr_lib8_11
		OBJ_SIZE_SET		$06,$0D
		OBJ_HP_SET			$01
		OBJ_DAMAGE_SET		_OBJ_DMG_KILL
		OBJ_SHOW
		OBJ_FLIPS_SET		_OBJ_FLIPS08
		NJSR				_native_throwable_obj_num_02_cmp
		SBCS				_script_sub_y_parabolic_delta_infinite_anim_sync
		SJSR				_script_sub_obj_wait_for_jump
		OBJ_Y_DELTA_SET		$EC
		SPR_IDX_SELECT		_spr_lib8_12
		SJSR				_script_sub_obj_wait_for_jump
		SPR_IDX_SELECT		_spr_lib8_11
		SJMP				byte_69AFA	; LONG

; =============== S C R I P T ===============================================
_script119:
		OBJ_X_POS_MOVE		$0E
		OBJ_Y_POS_MOVE		$CA
		SPR_LIB_SELECT		_spr_lib8
		SPR_IDX_SELECT		_spr_lib8_13
		NJSR_SYNC			_native_sub111
		TARGET_LOCK			$30
		OBJ_SIZE_SET		$08,$10
		OBJ_HP_SET			$01
		OBJ_DAMAGE_SET		_OBJ_DMG_KILL
		OBJ_SHOW
		OBJ_FLIPS_SET		_OBJ_FLIPS08
byte_69486:
		SYNC
		TARGET_DIR_SET		$FF
		TARGET_FOLLOW
		LOOPA				$04,byte_69486
		HFLIP_TOGGLE
		SJMPS				byte_69486

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_69492:
		NJSR				_native_sub144
		SBEQS				byte_6949E
		APU_LOAD			_apu_mus2F
		SRUN				_OBJ_TYPE_AUTO,_script11A
byte_6949E:
		NJSR				_native_sub145
		SYNC
		NJSR				_native_sub146
		NJSR				_native_sub147
		NJSR				_native_sub00D
		SRET

; =============== S C R I P T ===============================================
_script11A:
		STORE				$01,byte_E0
byte_694B0:
		SUSPEND				$04
		NJSR				_load_pal_patch00
		SUSPEND				$04
		NJSR				_ppu_pal_apply
		LOOPB				$04,byte_694B0
		STORE				$00,byte_E0
		KILL

; =============== S U B R O U T I N E =======================================
_load_pal_patch00:
		LDA		#<[_pal_patch00]
		LDY		#>[_pal_patch00]
		JMP		_far_prg3_pal_patch_load

; =============== S C R I P T ===============================================
_script_sub_694CA:
		NJSR				_scr_flips_04_set
		OBJ_HIDE
		APU_LOAD			_apu_mus70
		PAL_FADE_OUT		$04,$87
		SUSPEND				$80
		SJMP				_script_sub_stage_complete_flag_set

; =============== S U B R O U T I N E =======================================
_native_sub00B:
		LDA		#$40
		LDY		#$00

; !FALLTHROUGH!

; =============== S U B R O U T I N E =======================================
_native_sub00B_ex:
		STA		_hor_menu_pos
		STY		_tmp48
		LDA		#$00
		LDY		#$01
		STA		_ppu_scroll_shadow_hi
		STY		_ppu_scroll_nt_vert
		STA		_ppu_scroll_shadow_lo
		STA		_ppu_scroll_nt_hor
		LDA		#$00
		STA		_wnd_split_ppu_ofs
		LDA		#$2B
		STA		_wnd_split_ppu_ofs+1
		RTS

; =============== S U B R O U T I N E =======================================
_native_sub00C:
		LDA		_hor_menu_pos
		STA		_ppu_scroll_shadow_hi
		LDA		_tmp48
		STA		_ppu_scroll_nt_vert
		RTS

; =============== S U B R O U T I N E =======================================
_native_sub00D:
		LDA		_nmi_frames_counter
		AND		#$3F
		BNE		locret_69520
		LDA		_nmi_frames_counter
		LSR
		LSR
		LSR
		LSR
		AND		#$0C
		TAX
		LDA		word_69521,X
		STA		_tmp_ptr44
		LDA		word_69521+1,X
		STA		_tmp_ptr44+1
		LDA		off_69523,X
		LDY		off_69523+1,X
		JMP		_far_prg3_rect_draw
locret_69520:
		RTS
word_69521:
		.WORD	$2272
off_69523:
		.WORD	_rect19
		.WORD	$223A
		.WORD	_rect1A
		.WORD	$2272
		.WORD	_rect1B
		.WORD	$223A
		.WORD	_rect1C

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_69531:
		NJSR				_native_sub00B
		CHR_SELECT			$00,$13
		SRUN				_OBJ_TYPE_AUTO,_script11B
		SRUN				_OBJ_TYPE_AUTO,_script11C
		SUSPEND				$80
		SRET

; =============== S C R I P T ===============================================
_script11B:
		OBJ_X_POS_SET		$48,$00
		SJMPS				byte_6954B

; =============== S C R I P T ===============================================
_script11C:
		OBJ_X_POS_SET		$B8,$00
byte_6954B:
		OBJ_Y_POS_SET		$6D,$00
		OBJ_SIZE_SET		$05,$0A
byte_69551:
		SPR_LIB_SELECT		_spr_lib8
		VFLIP_SET
		OBJ_SHOW
		SPR_IDX_SELECT		_spr_lib8_3F
		SYNC
		SYNC
		SPR_IDX_SELECT		_spr_lib8_54
		SYNC
		SYNC
		LOOPA				$20,byte_69551
		KILL

; =============== O B J E C T   S C R I P T =================================
_obj_scr43_lvl5B_cat_with_cards:
		STORE				_apu_mus0E_idx,_apu_load_idx_req
		DESTR_PC_SET		_obj_scr_common_small_boss_destr
		NJSR				_native_obj_idxCs_clear_low_nibble
		OBJ_X_POS_MOVE		$50
		SPR_LIB_SELECT		_spr_lib8
		OBJ_HP_SET			$08
		OBJ_DAMAGE_SET		_OBJ_DMG_KILL
		OBJ_SIZE_SET		$0C,$2C
		SUSPEND				$30
		OBJ_SHOW
		OBJ_X_DELTA_SET		$F0
byte_6957C:
		SPR_IDX_SELECT		_spr_lib8_35
		SJSR				_script20A_anim_anim0A_sync
		SPR_IDX_SELECT		_spr_lib8_36
		SJSR				_script20A_anim_anim0A_sync
		SPR_IDX_SELECT		_spr_lib8_37
		SJSR				_script20A_anim_anim0A_sync
		SPR_IDX_SELECT		_spr_lib8_36
		SJSR				_script20A_anim_anim0A_sync
		LOOPA				$02,byte_6957C
byte_69594:
		SJSR				_script_sub_6963C
		NJSR				_native_get_rand_clamp3
		SSWITCH				_tmp_ptrE+1
		SCASE				byte_695C1
		SCASE				byte_695A5
		SCASE				byte_6961F
		SCASE				byte_6961F
byte_695A5:
		NJSR				_native_cmp40_obj_y_lo_pos
		SBEQS				byte_695B9
		NJSR				_native_cmpC0_obj_y_lo_pos
		SBEQS				byte_695B7
		NJSR				_native_get_rand_flags
		SBPLS				byte_695B9
byte_695B7:
		OBJ_Y_DELTA_SET		$AE
byte_695B9:
		SPR_IDX_SELECT		_spr_lib8_36
		SJSR				_script20B
		SJMPS				byte_69594
byte_695C1:
		OBJ_X_DELTA_SET		$18
		NJSR				_native_obj_hor_delta_toggle
byte_695C6:
		SPR_IDX_SELECT		_spr_lib8_35
		SJSRS				_script_sub_695DD
		SPR_IDX_SELECT		_spr_lib8_36
		SJSRS				_script_sub_695DD
		SPR_IDX_SELECT		_spr_lib8_37
		SJSRS				_script_sub_695DD
		SPR_IDX_SELECT		_spr_lib8_36
		SJSRS				_script_sub_695DD
		SJMPS				byte_695C6

; =============== S C R I P T ===============================================
_script_sub_695DD:
		SYNC
		SJSR				_script20A_anim
		NJSR				_obj_move_hor_animate
		NJSR				_native_sub135
		SBCSS				byte_695F5
		NJSR				_native_obj_to_tile_collision_test_down
		SBCCS				byte_695FC
		LOOPA				$0A,_script_sub_695DD
		SRET
byte_695F5:
		NJSR				_native_obj_hor_move_reverse
		LOOPA_RESET
		BREAK				byte_69594
byte_695FC:
		SPR_IDX_SELECT		_spr_lib8_36
		OBJ_Y_DELTA_SET		$D8
byte_69600:
		SYNC
		SJSR				_script20A_anim
		NJSR				_obj_move_hor_animate
		NJSR				_native_obj_y_parabolic_delta_adjust
		SBPLS				byte_69613
		NJSR				_obj_vert_animate
		SJMPS				byte_69600
byte_69613:
		NJSR				_native_sub10B
		SBCCS				byte_69600
		OBJ_Y_DELTA_SET		$00
		LOOPA_RESET
		BREAK				byte_695C6
byte_6961F:
		SPR_IDX_SELECT		_spr_lib8_38
		SJSR				_script20A_anim_anim0A_sync
		SPR_IDX_SELECT		_spr_lib8_39
		SJSR				_script20A_anim_anim06_sync
		SJSR				_script20A_anim_anim_sync
		SRUN				_OBJ_TYPE_EBULLET,_script11D
		SPR_IDX_SELECT		_spr_lib8_3A
		SJSR				_script20A_anim_anim10_sync
		LOOPA				$02,byte_6961F
		SJMP				byte_69594	; LONG

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_6963C:
		SPR_IDX_SELECT		_spr_lib8_34
		OBJ_X_DELTA_SET		$00
byte_69640:
		SJSR				_script20A_anim_anim_sync
		LOOPA				$30,byte_69640
		SRET

; =============== S C R I P T ===============================================
_script11D:
		OBJ_GRABABLE
		APU_LOAD			_apu_mus6E
		OBJ_SIZE_SET		$06,$06
		OBJ_HP_SET			$01
		OBJ_DAMAGE_SET		_OBJ_DMG_KILL
		SPR_LIB_SELECT		_spr_lib8
		OBJ_SHOW
		NJSR				_native_obj_hor_bounce2C
		OBJ_Y_POS_MOVE		$EF
		TARGET_LOCK			$40
		NJSR				_native_cat_with_cards_projectile_anim_select
		NJSR				_native_throwable_obj_num_02_cmp
		SBCS				_script1FE
		SJSR				_script1FF
		SPR_IDX_SELECT		_spr_lib8_3B
		OBJ_X_DELTA_SET		$18
		OBJ_Y_DELTA_SET		$00
		NJSR				_native_obj_hor_delta_toggle
byte_69671:
		SJSR				_script_animate10
		NJSR				_native_sub007
		SBCCS				byte_69671
		DESTR_PC_SET		byte_69B00
		OBJ_X_DELTA_SET		$00
		SJMP				byte_69AFA	; LONG

; =============== S U B R O U T I N E =======================================
_native_cat_with_cards_projectile_anim_select:
		JSR		_native_sub111
		LDA		_obj_flips,X
		AND		#_OBJ_HFLIP
		BEQ		loc_69693
		LDA		#<[_cards_projectile_anim_posA_list]
		LDY		#>[_cards_projectile_anim_posA_list]
		JMP		loc_69697
loc_69693:
		LDA		#<[_cards_projectile_anim_posB_list]
		LDY		#>[_cards_projectile_anim_posB_list]
loc_69697:
		STA		_tmp_ptr0
		STY		_tmp_ptr0+1
		LDY		_scr_vars18,X
		LDA		(_tmp_ptr0),Y
		STA		_scr_vars18,X
		TAY
		LDA		_cards_projectile_anim_spr_list,Y
		STA		_obj_spr_idxs,X
		RTS

_cards_projectile_anim_posA_list:
		.BYTE	$00,$01,$02,$03,$04,$05,$06,$07,$07,$07,$07,$07,$07,$07,$07,$07
		.BYTE	$07,$07,$07,$07,$07,$07,$07,$07,$07,$07,$07,$07,$07,$07,$07,$07
		.BYTE	$38,$38,$38,$38,$38,$38,$38,$38,$38,$38,$38,$38,$38,$38,$38,$38
		.BYTE	$38,$38,$38,$38,$38,$38,$38,$38,$38,$39,$3A,$3B,$3C,$3D,$3E,$3F
_cards_projectile_anim_posB_list:
		.BYTE	$18,$18,$18,$18,$18,$18,$18,$18,$18,$18,$18,$18,$18,$18,$18,$18
		.BYTE	$18,$18,$18,$18,$18,$18,$18,$18,$18,$19,$1A,$1B,$1C,$1D,$1E,$1F
		.BYTE	$20,$21,$22,$23,$24,$25,$26,$27,$27,$27,$27,$27,$27,$27,$27,$27
		.BYTE	$27,$27,$27,$27,$27,$27,$27,$27,$27,$27,$27,$27,$27,$27,$27,$27
_cards_projectile_anim_spr_list:
		.BYTE	_spr_lib8_3B_idx
		.BYTE	_spr_lib8_3B_idx
		.BYTE	_spr_lib8_3B_idx
		.BYTE	_spr_lib8_3D_idx
		.BYTE	_spr_lib8_3D_idx
		.BYTE	_spr_lib8_3D_idx
		.BYTE	_spr_lib8_3D_idx
		.BYTE	_spr_lib8_3D_idx
		.BYTE	_spr_lib8_3D_idx
		.BYTE	_spr_lib8_3D_idx
		.BYTE	_spr_lib8_3D_idx
		.BYTE	_spr_lib8_3D_idx
		.BYTE	_spr_lib8_3D_idx
		.BYTE	_spr_lib8_3D_idx
		.BYTE	_spr_lib8_3D_idx
		.BYTE	_spr_lib8_3D_idx
		.BYTE	_spr_lib8_3D_idx
		.BYTE	_spr_lib8_3D_idx
		.BYTE	_spr_lib8_3D_idx
		.BYTE	_spr_lib8_3D_idx
		.BYTE	_spr_lib8_3D_idx
		.BYTE	_spr_lib8_3D_idx
		.BYTE	_spr_lib8_3D_idx
		.BYTE	_spr_lib8_3D_idx
		.BYTE	_spr_lib8_3D_idx
		.BYTE	_spr_lib8_3D_idx
		.BYTE	_spr_lib8_3D_idx
		.BYTE	_spr_lib8_3D_idx
		.BYTE	_spr_lib8_3D_idx
		.BYTE	_spr_lib8_3B_idx
		.BYTE	_spr_lib8_3B_idx
		.BYTE	_spr_lib8_3B_idx
		.BYTE	_spr_lib8_3B_idx
		.BYTE	_spr_lib8_3B_idx
		.BYTE	_spr_lib8_3B_idx
		.BYTE	_spr_lib8_3C_idx
		.BYTE	_spr_lib8_3C_idx
		.BYTE	_spr_lib8_3C_idx
		.BYTE	_spr_lib8_3C_idx
		.BYTE	_spr_lib8_3C_idx
		.BYTE	_spr_lib8_3C_idx
		.BYTE	_spr_lib8_3C_idx
		.BYTE	_spr_lib8_3C_idx
		.BYTE	_spr_lib8_3C_idx
		.BYTE	_spr_lib8_3C_idx
		.BYTE	_spr_lib8_3C_idx
		.BYTE	_spr_lib8_3C_idx
		.BYTE	_spr_lib8_3C_idx
		.BYTE	_spr_lib8_3C_idx
		.BYTE	_spr_lib8_3C_idx
		.BYTE	_spr_lib8_3C_idx
		.BYTE	_spr_lib8_3C_idx
		.BYTE	_spr_lib8_3C_idx
		.BYTE	_spr_lib8_3C_idx
		.BYTE	_spr_lib8_3C_idx
		.BYTE	_spr_lib8_3C_idx
		.BYTE	_spr_lib8_3C_idx
		.BYTE	_spr_lib8_3C_idx
		.BYTE	_spr_lib8_3C_idx
		.BYTE	_spr_lib8_3C_idx
		.BYTE	_spr_lib8_3C_idx
		.BYTE	_spr_lib8_3B_idx
		.BYTE	_spr_lib8_3B_idx
		.BYTE	_spr_lib8_3B_idx

; =============== O B J E C T   S C R I P T =================================
_obj_scr44_lvl5B_boss_ostrich:
		STORE				_apu_mus0E_idx,_apu_load_idx_req
		DESTR_PC_SET		_obj_scr_common_small_boss_destr
		NJSR				_native_obj_idxCs_clear_low_nibble
		OBJ_X_POS_MOVE		$60
		SPR_LIB_SELECT		_spr_lib8
		OBJ_HP_SET			$08
		OBJ_DAMAGE_SET		_OBJ_DMG_KILL
		OBJ_SIZE_SET		$08,$30
		SUSPEND				$40
		OBJ_SHOW
		OBJ_X_DELTA_SET		$F0
byte_69785:
		APU_LOAD			_apu_mus6A
		SPR_IDX_SELECT		_spr_lib8_2D
		SJSR				_script20A_anim_anim08_sync
		SPR_IDX_SELECT		_spr_lib8_2E
		SJSR				_script20A_anim_anim08_sync
		APU_LOAD			_apu_mus6A
		SPR_IDX_SELECT		_spr_lib8_2F
		SJSR				_script20A_anim_anim08_sync
		SPR_IDX_SELECT		_spr_lib8_30
		SJSR				_script20A_anim_anim08_sync
		APU_LOAD			_apu_mus6A
		SPR_IDX_SELECT		_spr_lib8_31
		SJSR				_script20A_anim_anim08_sync
		SPR_IDX_SELECT		_spr_lib8_2C
		SJSR				_script20A_anim_anim08_sync
		LOOPA				$02,byte_69785
byte_697AD:
		SJSR				_script_sub_69859
		NJSR				_native_get_rand_flags
		SBPLS				byte_697BF
		NJSR				_native_cmpC0_obj_y_lo_pos
		SBNES				byte_697BF
		SJSRS				_script_sub_697D8
byte_697BF:
		SJSRS				_script_sub_69845
		SJSRS				_script_sub_697ED
		NJSR				_native_get_rand_flags
		SBPLS				byte_697CF
		OBJ_Y_DELTA_SET		$AC
		APU_LOAD			_apu_mus54
byte_697CF:
		SJSRS				_script_sub_697ED
		NJSR				_native_obj_hor_move_reverse
		SJMPS				byte_697AD

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_697D8:
		OBJ_X_DELTA_SET		$40
		SJSRS				_script_sub_697EF
		SJSRS				_script_sub_697EF
		NJSR				_native_obj_hor_move_reverse
		SJSRS				_script_sub_697EF
		SJSRS				_script_sub_697EF
		NJSR				_native_obj_hor_move_reverse
		SRET

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_697ED:
		OBJ_X_DELTA_SET		$20

; !FALLTHROUGH!

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_697EF:
		NJSR				_native_obj_hor_delta_toggle
		SPR_IDX_SELECT		_spr_lib8_2D
		SJSRS				_script_sub_69813
		SPR_IDX_SELECT		_spr_lib8_2E
		APU_LOAD			_apu_mus6A
		SJSRS				_script_sub_69813
		SPR_IDX_SELECT		_spr_lib8_2F
		SJSRS				_script_sub_69813
		SPR_IDX_SELECT		_spr_lib8_30
		APU_LOAD			_apu_mus6A
		SJSRS				_script_sub_69813
		SPR_IDX_SELECT		_spr_lib8_31
		SJSRS				_script_sub_69813
		SPR_IDX_SELECT		_spr_lib8_2C
		APU_LOAD			_apu_mus6A

; !FALLTHROUGH!

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_69813:
		SYNC
		SJSR				_script20A_anim
		NJSR				_obj_move_hor_animate
		NJSR				_native_sub149
		SBNES				byte_69840
		NJSR				_native_get_obj_y_delta
		SBNES				byte_6982C
		NJSR				_native_obj_to_tile_collision_test_down
		SBCSS				byte_69840
byte_6982C:
		NJSR				_native_obj_y_parabolic_delta_adjust
		SBPLS				byte_69838
		NJSR				_obj_vert_animate
		SJMPS				byte_69840
byte_69838:
		NJSR				_native_sub10B
		SBCCS				byte_69840
		OBJ_Y_DELTA_SET		$00
byte_69840:
		LOOPA				$08,_script_sub_69813
		SRET

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_69845:
		OBJ_X_DELTA_SET		$00
		NJSR				_native_box_bonus_3prizes_shuffle
byte_6984A:
		APU_LOAD			_apu_mus54
		OBJ_Y_DELTA_SET		$D0
		SJSR				_script20B
		SRUN				_OBJ_TYPE_EBULLET,_script11E
		LOOPA				$03,byte_6984A

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_69859:
		OBJ_X_DELTA_SET		$00
byte_6985B:
		SJSR				_script20A_anim_anim10_sync
		LOOPA				$03,byte_6985B
		SRET

; =============== S C R I P T ===============================================
_script11E:
		OBJ_GRABABLE
		NJSR				_native_get_box_bonus_prize_from_list
		SSWITCH				_tmp_ptrE+1
		SCASE				byte_69870
		SCASE				byte_69875
		SCASE				byte_6987A
byte_69870:
		OBJ_X_DELTA_SET		$18
		SJMPS				byte_6987C
byte_69875:
		OBJ_X_DELTA_SET		$24
		SJMPS				byte_6987C
byte_6987A:
		OBJ_X_DELTA_SET		$30
byte_6987C:
		SPR_LIB_SELECT		_spr_lib8
		OBJ_SIZE_SET		$06,$10
		OBJ_HP_SET			$01
		OBJ_DAMAGE_SET		_OBJ_DMG_KILL
		OBJ_SHOW
		OBJ_Y_DELTA_SET		$D0
		NJSR				_native_obj_hor_delta_toggle
		NJSR				_native_throwable_obj_num_02_cmp
		SBCCS				byte_698A7
byte_69891:
		SPR_IDX_SELECT		_spr_lib8_32
		SJSRS				_script_sub_6989E
		SPR_IDX_SELECT		_spr_lib8_33
		SJSRS				_script_sub_6989E
		SJMPS				byte_69891

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_6989E:
		OBJ_ANIMATE_SYNC
		NJSR				_native_obj_y_parabolic_delta_adjust
		LOOPA				$06,_script_sub_6989E
		SRET
byte_698A7:
		SJSRS				_script_sub_698B5
		OBJ_Y_DELTA_SET		$E8
		SJSRS				_script_sub_698B5
		DESTR_PC_SET		byte_69B00
		SJMP				byte_69AFA	; LONG

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_698B5:
		SPR_IDX_SELECT		_spr_lib8_32
		SJSRS				_script_sub_698C9
		SBCSS				byte_698C8
		SPR_IDX_SELECT		_spr_lib8_33
		SJSRS				_script_sub_698C9
		SBCSS				byte_698C8
		SJMPS				_script_sub_698B5
byte_698C8:
		SRET

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_698C9:
		SJSR				_script_sub_obj_jump_sync
		SBCSS				byte_698D3
		LOOPA				$06,_script_sub_698C9
byte_698D3:
		LOOPA_RESET
		SRET

; =============== O B J E C T   S C R I P T =================================
_obj_scr45_lvl5C_wrecking_lizard:
		STORE				_apu_mus1E_idx,_apu_load_idx_req
		DESTR_PC_SET		byte_69981
		STORE				$40,_ppu_scroll_shadow_lo
		STORE				$05,_ppu_scroll_nt_hor
		OBJ_HP_SET			$08
		OBJ_DAMAGE_SET		_OBJ_DMG_KILL
		OBJ_X_POS_SET		$88,$01
		OBJ_Y_POS_SET		$78,$00
		SRUN				_OBJ_TYPE_EBULLET,_script11F
		SRUN				_OBJ_TYPE_ENEMY,_script120
		NJSR				_native_sub14B
		NJSR				_native_obj_idxCs_clear_low_nibble
		SPR_LIB_SELECT		_spr_lib8
		SPR_IDX_SELECT		_spr_lib8_00
		SUSPEND				$80
		OBJ_SHOW
		OBJ_SIZE_SET		$08,$20
byte_69906:
		SJSRS				_script_sub_69961
		LOOPB				$06,byte_69906
byte_6990D:
		NJSR				_native_sub010
		SBEQS				byte_69924
		OBJ_X_DELTA_SET		$E0
		SPR_IDX_SELECT		_spr_lib8_00
		STORE				$0B,_pal_anim_mode_idx
		SJSRS				_script_sub_69969
		SJSRS				_script_sub_69969
		SJMPS				byte_6994D
byte_69924:
		NJSR				_native_sub00F
		SBCCS				byte_6994D
		NJSR				_native_get_rand_scale3
		SSWITCH				_tmp_ptrE+1
		SCASE				byte_69936
		SCASE				byte_6994D
		SCASE				byte_6995B
byte_69936:
		OBJ_X_DELTA_SET		$00
		SPR_IDX_SELECT		_spr_lib8_01
		STORE				$00,_pal_anim_mode_idx
		SJSRS				_script_sub_69969
		NJSR				_native_idxBs_10_test_clear_from_idxCs
		SJSRS				_script_sub_69969
		SJSRS				_script_sub_69969
		SJSRS				_script_sub_69969
byte_6994D:
		OBJ_X_DELTA_SET		$10
		SPR_IDX_SELECT		_spr_lib8_02
		STORE				$0A,_pal_anim_mode_idx
		SJSRS				_script_sub_69969
		SJMPS				byte_6990D
byte_6995B:
		SJSRS				_script_sub_69961
		SJMPS				byte_6990D

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_69961:
		OBJ_X_DELTA_SET		$F0
		SPR_IDX_SELECT		_spr_lib8_00
		STORE				$0B,_pal_anim_mode_idx

; !FALLTHROUGH!

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_69969:
		NJSR				_native_sub011
		NJSR				_native_sub144
		SBEQS				byte_69978
		APU_LOAD			_apu_mus2F
		SRUN				_OBJ_TYPE_AUTO,_script121
byte_69978:
		NJSR				_native_sub145
		SYNC
		LOOPA				$20,_script_sub_69969
		SRET
byte_69981:
		SPR_IDX_SELECT		_spr_lib8_06
		STORE				$00,_pal_anim_mode_idx
		APU_LOAD			_apu_mus70
byte_69989:
		NJSR				_native_sub012
		SUSPEND				$20
		NJSR				_native_sub012
		SUSPEND				$20
		LOOPB				$04,byte_69989
		SJMP				_script_sub_stage_complete_flag_set

; =============== S U B R O U T I N E =======================================
_native_sub00F:
		LDA		_obj_x_lo_poss,X
		CMP		#$A9
		JMP		_scr_flags_update

; =============== S U B R O U T I N E =======================================
_native_sub010:
		LDA		_obj_x_hi_poss,X
		JMP		_scr_flags_update

; =============== S U B R O U T I N E =======================================
_native_sub011:
		JSR		_native_sub146
		LDA		_obj_x_deltas,X
		BEQ		locret_699BB
		LDA		_ppu_scroll_shadow_lo
		AND		#$03
		BNE		locret_699BB
		LDA		#_apu_mus62_idx
		JSR		_apu_se_req
locret_699BB:
		RTS

; =============== S U B R O U T I N E =======================================
_native_sub012:
		LDA		#$56
		STA		_tmp_ptr44
		LDA		#$21
		STA		_tmp_ptr44+1
		INC		_scr_loopsA,X
		LDA		_scr_loopsA,X
		ASL
		AND		#$02
		TAX
		LDA		off_699D7,X
		LDY		off_699D7+1,X
		JMP		_far_prg3_rect_draw

off_699D7:
		.WORD	_rect17
		.WORD	_rect18

; =============== S C R I P T ===============================================
_script121:
		NJSR				_native_obj_idxCs_clear_low_nibble
		OBJ_Y_POS_MOVE		$FF
		SPR_LIB_SELECT		_spr_lib8
		SPR_IDX_SELECT		_spr_lib8_03
		OBJ_SHOW
byte_699E5:
		SUSPEND				$04
		NJSR				_load_pal_patch01
		SUSPEND				$04
		NJSR				_ppu_pal_apply
		LOOPB				$04,byte_699E5
		KILL

; =============== S U B R O U T I N E =======================================
_load_pal_patch01:
		LDA		#<[_pal_patch01]
		LDY		#>[_pal_patch01]
		JMP		_far_prg3_pal_patch_load

; =============== S C R I P T ===============================================
_script11F:
		NJSR				_native_obj_idxCs_clear_low_nibble
		OBJ_Y_POS_MOVE		$3F
		OBJ_SIZE_SET		$24,$40
		OBJ_HP_SET			$01
		OBJ_DAMAGE_SET		_OBJ_DMG_KILL
byte_69A07:
		SYNC
		SJSRS				_script_sub_69A12
		SJMPS				byte_69A07

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_69A0E:
		SYNC
		NJSR				_scr_flips_04_clear

; !FALLTHROUGH!

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_69A12:
		NJSR				_native_get_obj3_hp
		SBNES				byte_69A1B
		OBJ_SIZE_SET		$00,$00
byte_69A1B:
		SRET

; =============== S C R I P T ===============================================
_script120:
		NJSR				_native_obj_idxCs_clear_low_nibble
		OBJ_X_POS_MOVE		$94
		OBJ_Y_POS_MOVE		$48
		SPR_LIB_SELECT		_spr_lib8
		SPR_IDX_SELECT		_spr_lib8_08
		OBJ_SIZE_SET		$08,$20
		OBJ_HP_SET			$FF
		OBJ_DAMAGE_SET		$FF
		OBJ_SHOW
		SJSRS				_script_sub_69A5B
byte_69A32:
		NJSR				_native_idxBs_10_set
byte_69A35:
		SJSRS				_script_sub_69A0E
		NJSR				_native_idxBs_10_test
		SBNES				byte_69A35
		SJSRS				_script_sub_69A6E
		APU_LOAD			_apu_mus63
		SRUN				_OBJ_TYPE_EBULLET,_script122
		SJSRS				_script_sub_69A0E
		SRUN				_OBJ_TYPE_EBULLET,_script123
byte_69A4E:
		SJSRS				_script_sub_69A0E
		LOOPB				$3C,byte_69A4E
		SJSRS				_script_sub_69A5B
		SJMPS				byte_69A32

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_69A5B:
		OBJ_Y_DELTA_SET		$E0
byte_69A5D:
		SJSRS				_script_sub_69A0E
		NJSR				_obj_vert_animate
		NJSR				_native_sub013
		NJSR				_native_sub014
		LOOPA				$18,byte_69A5D
		SRET

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_69A6E:
		OBJ_Y_DELTA_SET		$40
byte_69A70:
		SJSRS				_script_sub_69A0E
		NJSR				_obj_vert_animate
		NJSR				_native_sub015
		NJSR				_native_sub013
		LOOPA				$0C,byte_69A70
		SRET

; =============== S U B R O U T I N E =======================================
_native_sub013:
		SEC
		LDA		_obj_y_lo_poss,X
		SBC		#$30
		STA		_obj_heights,X
		LDA		_scr_loopsB,X
		AND		#$03
		BEQ		loc_69A92
		RTS
loc_69A92:
		LDA		#$EB
		STA		_tmp_ptr44
		LDA		#$20
		STA		_tmp_ptr44+1
		LDA		_scr_loopsB,X
		AND		#$1C
		TAX
		LDA		off_69AB9+2,X
		STA		_tmp_ptr2
		LDA		off_69AB9,X
		LDY		off_69AB9+1,X
		JMP		_far_prg3_tlm_queue

; =============== S U B R O U T I N E =======================================
_native_sub014:
		INC		_scr_loopsB,X
		RTS

; =============== S U B R O U T I N E =======================================
_native_sub015:
		DEC		_scr_loopsB,X
		DEC		_scr_loopsB,X
		RTS

off_69AB9:
		.WORD	_tlm00
		.WORD	$4F
		.WORD	_tlm01
		.WORD	$4E
		.WORD	_tlm02
		.WORD	$4D
		.WORD	_tlm03
		.WORD	$4C
		.WORD	_tlm04
		.WORD	$4B
		.WORD	_tlm05
		.WORD	$4A

; =============== S C R I P T ===============================================
_script122:
		OBJ_X_DELTA_SET		$F0
		SJMPS				byte_69AD8

; =============== S C R I P T ===============================================
_script123:
		OBJ_X_DELTA_SET		$10
byte_69AD8:
		OBJ_GRABABLE
		DESTR_PC_SET		byte_69B00
		OBJ_Y_DELTA_SET		$D0
		SPR_LIB_SELECT		_spr_lib8
		SPR_IDX_SELECT		_spr_lib8_07
		OBJ_SIZE_SET		$06,$10
		OBJ_HP_SET			$01
		OBJ_DAMAGE_SET		_OBJ_DMG_KILL
		OBJ_SHOW
		OBJ_FLIPS_SET		_OBJ_FLIPS08
		NJSR				_native_throwable_obj_num_02_cmp
		SBCS				_script_sub_y_parabolic_delta_infinite_anim_sync
		SJSR				_script_sub_obj_wait_for_jump
		OBJ_Y_DELTA_SET		$E8
		SJSR				_script_sub_obj_wait_for_jump
byte_69AFA:
		NJSR				_native_obj_type_change_solid_no_damage
		SJSR				_script_obj_wait_for_pickup
byte_69B00:
		SJSR				_script_obj_wait_for_throw
		OBJ_FLIPS_SET		_OBJ_FLIPS08
		NJSR				_native_obj_throw_direction_select
byte_69B08:
		OBJ_ANIMATE_SYNC
		NJSR				_native_sub016
		SBNES				byte_69B08
		SJMP				_script_sub_y_parabolic_delta_infinite_anim_sync

; =============== S U B R O U T I N E =======================================
_native_sub016:
		LDA		_obj_hps,X
		BNE		loc_69B28
		LDA		#$08
		LDY		_obj_x_deltas,X
		BMI		loc_69B20
		LDA		#$F8
loc_69B20:
		STA		_obj_x_deltas,X
		LDA		#$00
		STA		_obj_y_deltas,X
loc_69B28:
		JMP		_scr_flags_update

; =============== O B J E C T   S C R I P T =================================
_obj_scr46_lvl6_final_boss:
		NJSR				_native_lvl6_final_boss_init
		STORE				$00,_ppu_scroll_nt_vert
		STORE				_apu_mus1F_idx,_apu_load_idx_req
		SRUN				_OBJ_TYPE_AUTO,_script124
		SRUN				_OBJ_TYPE_AUTO,_script125
		SRUN				_OBJ_TYPE_AUTO,_script126
		SRUN				_OBJ_TYPE_AUTO,_script127
		NJSR				_native_idxBs_10_set
byte_69B49:
		NJSR_SYNC			_native_idxBs_10_test
		SBNES				byte_69B49
		CHR_SELECT			$00,$1C
		CHR_SELECT			$01,$0D
		STORE				<[_tileset05],_room_tileset_ptr
		STORE				>[_tileset05],_room_tileset_ptr+1
byte_69B5D:
		NJSR_SYNC			_native_sub14F
		LOOPA				$0F,byte_69B5D
		LOOPB				$10,byte_69B5D
		NJSR				_pal_bg003_reload
		DESTR_PC_SET		_obj_scr46_lvl6_final_boss_destr
		NJSR				_native_obj_idxCs_clear_low_nibble
		SPR_LIB_SELECT		_spr_lib8
		SPR_IDX_SELECT		_spr_lib8_51
		OBJ_HP_SET			$0A
		OBJ_DAMAGE_SET		_OBJ_DMG_KILL
		OBJ_SIZE_SET		$00,$00
		NJSR				_native_sub00C
		PAL_FADE_IN			$04,$C3
		SRUN				_OBJ_TYPE_ENEMY,_script128
		NJSR				_native_sub14B
		SRUN				_OBJ_TYPE_ENEMY,_script129
		NJSR				_native_sub150
		SUSPEND				$14
		OBJ_SHOW
		OBJ_SIZE_SET		$28,$70
		NJSR				_native_sub021
		SJSR				_script_sub_69C88
		OBJ_Y_DELTA_SET		$F0
		SRUN				_OBJ_TYPE_ENEMY,_script12A
		SJSR				_sript_sub_69C7E
byte_69BA5:
		SJSR				_script_sub_69D06
		LOOPA				$30,byte_69BA5
		OBJ_Y_DELTA_SET		$40
byte_69BAE:
		SJSR				_script_sub_69D06
		LOOPA				$10,byte_69BAE
		SJSR				_script_sub_69C4E
byte_69BB8:
		SJSR				_script_sub_69C88
byte_69BBB:
		OBJ_Y_DELTA_SET		$F0
		SRUN				_OBJ_TYPE_ENEMY,_script12A
		SJSR				_sript_sub_69C7E
byte_69BC4:
		SJSR				_script_sub_69D06
		LOOPA				$C0,byte_69BC4
		OBJ_Y_DELTA_SET		$00
		OBJ_SIZE_SET		$00,$00
byte_69BD0:
		SJSR				_script_sub_69CDC
		LOOPB				$3C,byte_69BD0
		SRUN				_OBJ_TYPE_PBULLET,_script12B
		NJSR				_native_sub01D
		SRUN				_OBJ_TYPE_AUTO,_script12C
byte_69BE2:
		SJSR				_script_sub_69CDC
		LOOPB				$B4,byte_69BE2
		OBJ_SIZE_SET		$28,$70
		OBJ_Y_DELTA_SET		$40
byte_69BEE:
		SJSR				_script_sub_69D06
		LOOPA				$34,byte_69BEE
		SJSRS				_script_sub_69C4E
		NJSR				_native_sub01C
		SBCSS				byte_69C10
		NJSR				_native_box_bonus_4prizes_shuffle
		SRUN				_OBJ_TYPE_EBULLET,_script12D
byte_69C05:
		SJSR				_script_sub_69CDC
		LOOPB				$3C,byte_69C05
		SRUN				_OBJ_TYPE_EBULLET,_script12D
byte_69C10:
		NJSR				_native_cmpC0_obj_x_lo_pos
		SBNES				byte_69BB8
		NJSR				_native_get_rand_scale3
		SSWITCH				_tmp_ptrE+1
		SCASE				byte_69C22
		SCASE				byte_69C2F
		SCASE				byte_69C3C
byte_69C22:
		SSWITCH				byte_E0
		SCASE				byte_69C2F
		SCASE				byte_69C29
byte_69C29:
		NJSR_SYNC			_native_idxBs_10_test_clear_from_idxBs
		SJMPS				byte_69C40
byte_69C2F:
		SSWITCH				byte_E1
		SCASE				byte_69C3C
		SCASE				byte_69C36
byte_69C36:
		NJSR_SYNC			_native_idxBs_10_test_clear_from_idxCs
		SJMPS				byte_69C40
byte_69C3C:
		SRUN				_OBJ_TYPE_AUTO,_script12E
byte_69C40:
		SJSR				_script_sub_69CDC
		LOOPB				$B4,byte_69C40
		LOOPA				$02,byte_69C10
		SJMP				byte_69BBB	; LONG

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_69C4E:
		APU_LOAD			_apu_mus44
		OBJ_Y_DELTA_SET		$E0
		SJSRS				_script_sub_69C76
		OBJ_Y_DELTA_SET		$E8
		SJSRS				_script_sub_69C76
		OBJ_Y_DELTA_SET		$F0
		SJSRS				_script_sub_69C76
		OBJ_Y_DELTA_SET		$F8
		SJSRS				_script_sub_69C76
		TARGET_DIR_SET		$06
		SJSRS				_script_sub_69CB5
		TARGET_DIR_SET		$04
		SJSRS				_script_sub_69CB5
		OBJ_Y_DELTA_SET		$10
		SJSRS				_script_sub_69C76
		APU_LOAD			_apu_mus44
		SRET

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_69C76:
		SJSRS				_script_sub_69D06
		LOOPA				$04,_script_sub_69C76
		SRET
_sript_sub_69C7E:
		TARGET_DIR_SET		$02
		SJSRS				_script_sub_69CB5
		TARGET_DIR_SET		$00
		SJMPS				_script_sub_69CB5

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_69C88:
		NJSR				_native_sub01C
		SBCCS				byte_69CAD
byte_69C8E:
		TARGET_DIR_SET		$08
		SJSRS				_script_sub_69CB5
byte_69C93:
		SJSRS				_script_sub_69CDC
		LOOPB				$3C,byte_69C93
		APU_LOAD			_apu_mus30
		TARGET_DIR_SET		$0A
		SJSRS				_script_sub_69CB5
byte_69CA1:
		SJSRS				_script_sub_69CDC
		LOOPB				$3C,byte_69CA1
		LOOPA				$03,byte_69C8E
		SRET
byte_69CAD:
		SJSRS				_script_sub_69CDC
		LOOPB				$F0,byte_69CAD
		SRET

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_69CB5:
		NJSR				_native_sub017
byte_69CB8:
		SJSRS				_script_sub_69CDC
		NJSR				_native_macro_patch_line_draw
		SBNES				byte_69CB8
		SRET

; =============== S U B R O U T I N E =======================================
_native_sub017:
		LDY		_scr_vars19,X
		LDA		off_69CD0,Y
		STA		_tmp_ptr4B
		LDA		off_69CD0+1,Y
		STA		_tmp_ptr4B+1
		RTS

off_69CD0:
		.WORD	tlm_patch00
		.WORD	tlm_patch01
		.WORD	tlm_patch02
		.WORD	tlm_patch03
		.WORD	tlm_patch04
		.WORD	tlm_patch05

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_69CDC:
		NJSR				_native_sub144
		SBEQS				byte_69CFC
		APU_LOAD			_apu_mus2F
		SRUN				_OBJ_TYPE_AUTO,_script12F
		NJSR				_native_sub01C
		SBCSS				byte_69CFC
		NJSR				_native_sub018
		SBEQS				byte_69CFC
		STORE				$00,byte_E2
		SRUN				_OBJ_TYPE_AUTO,_script130
byte_69CFC:
		SYNC
		NJSR				_native_sub145
		SRET

; =============== S U B R O U T I N E =======================================
_native_sub018:
		LDA		byte_E2
		JMP		_scr_flags_update

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_69D06:
		SJSRS				_script_sub_69CDC
		NJSR				_native_sub146
		NJSR				_native_sub147
		SRET

; =============== S U B R O U T I N E =======================================
_native_lvl6_final_boss_init:
		LDA		#$01
		STA		byte_E0
		STA		byte_E1
		STA		byte_E2
		LDA		#$C0
		STA		_obj_x_lo_poss,X
		STA		_obj_y_lo_poss,X
		LDA		#$2C
		LDY		#$00
		JMP		_native_sub00B_ex

; =============== S U B R O U T I N E =======================================
_pal_bg003_reload:
		LDX		#$77
		LDA		#<[_pal_bg003]
		LDY		#>[_pal_bg003]
		JMP		_far_prg3_pal_bg_reload

; =============== O B J E C T   S C R I P T =================================
_obj_scr46_lvl6_final_boss_destr:
		OBJ_Y_DELTA_SET		$00
		SRUN				_OBJ_TYPE_AUTO,_script12F
		SRUN				_OBJ_TYPE_AUTO,_script130
		SUSPEND				$B4
		APU_LOAD			_apu_mus70
		PAL_FADE_OUT		$04,$C7
		SUSPEND				$80
		SJMP				_script_sub_stage_complete_flag_set

; =============== S C R I P T ===============================================
_script130:
		NJSR				_native_sub01B
		SRUN				_OBJ_TYPE_AUTO,_script131
		SUSPEND				$13
		LOOPA				$05,_script130
		APU_LOAD			_apu_mus46
		NJSR_SYNC			_cat_boss_bg_patch0_draw
		NJSR_SYNC			_cat_boss_bg_patch1_draw
byte_69D5B:
		NJSR				_native_sub01B
		SRUN				_OBJ_TYPE_AUTO,_script131
		SUSPEND				$13
		LOOPA				$03,byte_69D5B
		KILL

; =============== S C R I P T ===============================================
_script131:
		SRUN				_OBJ_TYPE_AUTO,_script132
		SJSR				_script_sub_6A052
		KILL

; =============== S C R I P T ===============================================
_script132:
		SPR_LIB_SELECT		_spr_lib8
		SPR_IDX_SELECT		_spr_lib8_4D
		OBJ_SHOW
		NJSR_SYNC			_native_sub01A
		SJMP				byte_689E8	; LONG

; =============== S U B R O U T I N E =======================================
_native_sub01A:
		JSR		_native_get_rand3
		LDA		byte_69D98,Y
		STA		_obj_y_deltas,X
		JSR		_native_get_rand3
		LDA		byte_69F42,Y
		STA		_obj_x_deltas,X
		JSR		_rand
		LSR
		BCS		locret_69D97
		JMP		_j_native_complement_x_deltas
locret_69D97:
		RTS

byte_69D98:
		.BYTE	$E8,$E0,$DC,$D8

; =============== S U B R O U T I N E =======================================
_native_get_rand3:
		JSR		_rand
		AND		#$03
		TAY
		RTS

; =============== S U B R O U T I N E =======================================
_native_sub01B:
		JSR		_rand
		AND		#$07
		TAY
		LDA		byte_69DD1,Y
		STA		_tmp_ptr0
		LDA		byte_69DD9,Y
		STA		_tmp_ptr2
		LDY		_scr_idxAs,X
		CLC
		LDA		_obj_x_lo_poss,Y
		ADC		_tmp_ptr0
		STA		_obj_x_lo_poss,X
		CLC
		LDA		_obj_y_lo_poss,Y
		ADC		_tmp_ptr2
		STA		_obj_y_lo_poss,X
		LDA		_obj_y_hi_poss,Y
		ADC		#$FF
		STA		_obj_y_hi_poss,X
		RTS
byte_69DD1:
		.BYTE	$D0,$E0,$F8,$10,$F0,$E0,$10,$00
byte_69DD9:
		.BYTE	$B0,$C0,$B0,$C0,$D0,$E0,$E0,$A0

; =============== S U B R O U T I N E =======================================
_cat_boss_bg_patch0_draw:
		LDA		#$D6
		STA		_tmp_ptr44
		LDA		#$21
		STA		_tmp_ptr44+1
		LDA		#<[_cat_boss_bg_patch0]
		LDY		#>[_cat_boss_bg_patch0]
		JMP		_far_prg3_rect_draw

; =============== S U B R O U T I N E =======================================
_cat_boss_bg_patch1_draw:
		LDA		#$52
		STA		_tmp_ptr44
		LDA		#$22
		STA		_tmp_ptr44+1
		LDA		#<[_cat_boss_bg_patch1]
		LDY		#>[_cat_boss_bg_patch1]
		JMP		_far_prg3_rect_draw

; =============== S U B R O U T I N E =======================================
_native_sub01C:
		LDA		_obj_hps,X
		CMP		#$06
		JMP		_scr_flags_update

; =============== S U B R O U T I N E =======================================
_native_sub01D:
		LDY		#$05
		JSR		_rand_scale
		LDA		byte_69E27,Y
		STA		_ppu_scroll_shadow_lo
		SEC
		LDA		_obj_x_lo_poss,X
		SBC		byte_69E22,Y
		STA		_obj_global_x_shift
loc_69E1A:
		LDA		_obj_x_hi_poss,X
		SBC		#$00
		STA		_obj_global_x_shift+1
		RTS
byte_69E22:
		.BYTE	$50,$80,$C0,$C0,$C0
byte_69E27:
		.BYTE	$70,$40,$00,$00,$00

; =============== S C R I P T ===============================================
_script12F:
		SUSPEND				$04
		NJSR				_pal_patch02_load
		SUSPEND				$04
		NJSR				_ppu_pal_apply
		LOOPB				$04,_script12F
		KILL

; =============== S U B R O U T I N E =======================================
_pal_patch02_load:
		LDA		#<[_pal_patch02]
		LDY		#>[_pal_patch02]
		JMP		_far_prg3_pal_patch_load

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_69E42:
		SJSR				_script20A_anim_anim_sync
		SJMP				_script_sub_69A12	; LONG

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_69E48:
		OBJ_X_DELTA_SET		$00
		OBJ_Y_DELTA_SET		$00
		NJSR				_native_idxBs_10_set
byte_69E4F:
		SJSRS				_script_sub_69E42
		NJSR				_native_idxBs_10_test
		SBNES				byte_69E4F
		SRET

; =============== S C R I P T ===============================================
_script128:
		DESTR_PC_SET		byte_69E8F
		NJSR				_native_obj_idxCs_clear_low_nibble
		OBJ_HP_SET			$05
		OBJ_DAMAGE_SET		_OBJ_DMG_KILL
		OBJ_SIZE_SET		$06,$0C
		OBJ_X_POS_MOVE		$B2
		OBJ_Y_POS_MOVE		$C2
		SPR_LIB_SELECT		_spr_lib8
		SPR_IDX_SELECT		_spr_lib8_3E
		OBJ_SHOW
byte_69E6F:
		SJSRS				_script_sub_69E48
		APU_LOAD			_apu_mus45
		NJSR				_native_sub153
		HFLIP_CLEAR
		SJSRS				_script_sub_69E87
		NJSR				_j_native_complement_x_deltas
		NJSR				_native_complement_y_deltas
		SJSRS				_script_sub_69E87
		SJMPS				byte_69E6F

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_69E87:
		SJSRS				_script_sub_69E42
		LOOPA				$24,_script_sub_69E87
		SRET

; =============== S C R I P T ===============================================
byte_69E8F:
		STORE				$00,byte_E1
		SJSR				_script_sub_6A069
		KILL

; =============== S C R I P T ===============================================
_script129:
		DESTR_PC_SET		byte_69EF8
		NJSR				_native_obj_idxCs_clear_low_nibble
		OBJ_HP_SET			$05
		OBJ_DAMAGE_SET		_OBJ_DMG_KILL
		OBJ_SIZE_SET		$06,$0C
		OBJ_X_POS_MOVE		$2E
		OBJ_Y_POS_MOVE		$C0
		SPR_LIB_SELECT		_spr_lib8
		SPR_IDX_SELECT		_spr_lib8_4F
		OBJ_SHOW
byte_69EAD:
		SJSRS				_script_sub_69E48
		APU_LOAD			_apu_mus54
		OBJ_X_DELTA_SET		$C8
		OBJ_Y_DELTA_SET		$20
		SJSRS				_script_sub_69ECD
		OBJ_X_DELTA_SET		$EC
		SJSRS				_script_sub_69ED5
		OBJ_X_DELTA_SET		$14
		SJSRS				_script_sub_69ED5
		OBJ_X_DELTA_SET		$38
		OBJ_Y_DELTA_SET		$E0
		SJSRS				_script_sub_69ECD
		SJMPS				byte_69EAD

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_69ECD:
		SJSRS				_script_sub_69E42
		LOOPA				$20,_script_sub_69ECD
		SRET

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_69ED5:
		OBJ_Y_DELTA_SET		$B0
byte_69ED7:
		SJSR				_script_sub_69E42
		NJSR				_native_obj_y_parabolic_delta_adjust
		LOOPA				$14,byte_69ED7
byte_69EE1:
		NJSR				_native_complement_y_deltas
		NJSR				_native_obj_y_parabolic_delta_adjust
		SJSR				_script_sub_69E42
		NJSR				_native_complement_y_deltas
		LOOPA				$14,byte_69EE1
		APU_LOAD			_apu_mus6C
		LOOPB				$02,_script_sub_69ED5
		SRET
byte_69EF8:
		STORE				$00,byte_E0
		SJSR				_script_sub_6A069
		KILL

; =============== S C R I P T ===============================================
_script12D:
		OBJ_Y_POS_MOVE		$90
		OBJ_FLIPS_SET		_OBJ_FLIPS08
		OBJ_HP_SET			$01
		OBJ_DAMAGE_SET		_OBJ_DMG_KILL
		OBJ_SIZE_SET		$04,$10
		SPR_LIB_SELECT		_spr_lib8
		SPR_IDX_SELECT		_spr_lib8_46
		OBJ_SHOW
		OBJ_Y_DELTA_SET		$E8
		NJSR				_native_sub01E
byte_69F15:
		SJSR				_script_sub_obj_jump_sync
		SBCSS				byte_69F23
		LOOPA				$06,byte_69F15
		HFLIP_TOGGLE
		SJMPS				byte_69F15
byte_69F23:
		SPR_IDX_SELECT		_spr_lib8_47
byte_69F25:
		SUSPEND				$04
		VFLIP_SET
		SUSPEND				$04
		HFLIP_SET
		SUSPEND				$04
		VFLIP_CLEAR
		SUSPEND				$04
		HFLIP_CLEAR
		LOOPA				$02,byte_69F25
		KILL

; =============== S U B R O U T I N E =======================================
_native_sub01E:
		JSR		_native_get_box_bonus_prize_from_list
		LDY		_tmp_ptrE+1
		LDA		byte_69F42,Y
		STA		_obj_x_deltas,X
		RTS
byte_69F42:
		.BYTE	$F0,$E4,$E8,$EC

; =============== S C R I P T ===============================================
_script12C:
		OBJ_Y_POS_SET		$30,$00
		SPR_LIB_SELECT		_spr_lib8
		SPR_IDX_SELECT		_spr_lib8_49
		OBJ_SHOW
		SUSPEND				$AA
		KILL

; =============== S C R I P T ===============================================
_script12B:
		OBJ_Y_POS_MOVE		$10
		DESTR_PC_SET		byte_69F7C
		OBJ_HP_SET			$01
		OBJ_DAMAGE_SET		$FF
		OBJ_FLIPS_SET		_OBJ_FLIPS08
		OBJ_SIZE_SET		$06,$0E
		SPR_LIB_SELECT		_spr_lib8
		SPR_IDX_SELECT		_spr_lib8_4C
		OBJ_SHOW
		SJSR				_script_sub_obj_wait_for_jump
		APU_LOAD			_apu_mus2B
		OBJ_Y_DELTA_SET		$F0
		SJSR				_script_sub_obj_wait_for_jump
		APU_LOAD			_apu_mus2B
		NJSR				_native_obj_type_change_solid_no_damage
byte_69F73:
		SJSRS				_script_sub_69FB5
		NJSR				_native_get_obj_idxBs
		SBPLS				byte_69F73
byte_69F7C:
		NJSR				_native_obj_type_change_throw
		NJSR				_native_obj_idxCs_clear_low_nibble
byte_69F82:
		SJSRS				_script_sub_69FB5
		NJSR				_players_animB_sub0129_sub06_C
		NJSR				_native_get_obj_idxBs
		SBMIS				byte_69F82
		APU_LOAD			_apu_mus24
		OBJ_FLIPS_SET		_OBJ_FLIPS08
		NJSR				_native_obj_idxCs_80_set
		NJSR				_native_obj_throw_direction_select
		NJSR				_native_idxBs_20_set
		OBJ_HP_SET			$01
		OBJ_DAMAGE_SET		$FF
byte_69F9F:
		OBJ_ANIMATE
		SJSRS				_script_sub_69FB5
		NJSR				_native_sub016
		SBNES				byte_69F9F
		APU_LOAD			_apu_mus30
byte_69FAB:
		SJSRS				_script_sub_69FB5
		OBJ_ANIMATE
		NJSR				_native_obj_y_parabolic_delta_adjust
		SJMPS				byte_69FAB

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_69FB5:
		NJSR_SYNC			_native_sub01F
		SBEQS				byte_69FBC
		SRET
byte_69FBC:
		NJSR				_native_get_obj_idxBs
		SBPLS				byte_69FCA
		NJSR				_native_sub033
		OBJ_Y_POS_MOVE		$08
		NJSR				_scr_flips_04_clear
byte_69FCA:
		NJSR				_native_obj_type_change_throw
		OBJ_HP_SET			$01
		OBJ_DAMAGE_SET		_OBJ_DMG_KILL
		OBJ_SIZE_SET		$0C,$0E
		SJSR				_script_sub_6A069
		KILL

; =============== S U B R O U T I N E =======================================
_native_sub01F:
		LDA		_scr_vars20,X
		ROL
		ROL
		ROL
		AND		#$03
		TAY
		LDA		byte_69FED,Y
		STA		_obj_spr_idxs,X
		INC		_scr_vars20,X
		JMP		_scr_flags_update

byte_69FED:
		.BYTE	_spr_lib8_4C_idx,_spr_lib8_4C_idx,_spr_lib8_4B_idx,_spr_lib8_4A_idx

; =============== S C R I P T ===============================================
_script12E:
		OBJ_FLIPS_SET		_OBJ_FLIPS08
		OBJ_X_POS_MOVE		$18
		OBJ_Y_POS_MOVE		$F0
		SPR_LIB_SELECT		_spr_lib8
		SPR_IDX_SELECT		_spr_lib8_48
		SJSRS				_script_sub_6A04B
		OBJ_X_POS_MOVE		$09
		OBJ_Y_POS_MOVE		$F8
		SJSRS				_script_sub_6A04B
		OBJ_X_POS_MOVE		$09
		OBJ_Y_POS_MOVE		$08
		SJSRS				_script_sub_6A04B
		OBJ_X_POS_MOVE		$05
		OBJ_Y_POS_MOVE		$09
		SJSRS				_script_sub_6A04B
		OBJ_X_POS_MOVE		$05
		OBJ_Y_POS_MOVE		$07
		SJSRS				_script_sub_6A04B
		OBJ_X_POS_MOVE		$07
		OBJ_Y_POS_MOVE		$FE
byte_6A01E:
		SJSRS				_script_sub_6A04B
		LOOPA				$08,byte_6A01E
		SRUN				_OBJ_TYPE_EBULLET,_script133
		LOOPB				$03,byte_6A01E
		KILL

; =============== S C R I P T ===============================================
_script133:
		APU_LOAD			_apu_mus6F
		OBJ_FLIPS_SET		_OBJ_FLIPS08
		OBJ_HP_SET			$01
		OBJ_DAMAGE_SET		_OBJ_DMG_KILL
		OBJ_SIZE_SET		$04,$08
		SPR_LIB_SELECT		_spr_lib8
		SPR_IDX_SELECT		_spr_lib8_48
		OBJ_X_DELTA_SET		$40
		NJSR				_native_sub10E
		NJSR				_native_obj_hor_delta_toggle
byte_6A045:
		SJSRS				_script_sub_6A04B
		SJMPS				byte_6A045

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_6A04B:
		OBJ_SHOW
		OBJ_ANIMATE_SYNC
		OBJ_ANIMATE_SYNC
		OBJ_HIDE
		OBJ_ANIMATE_SYNC
		OBJ_ANIMATE_SYNC
		SRET

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_6A052:
		APU_LOAD			_apu_mus46
		SPR_LIB_SELECT		_spr_lib8
		OBJ_SHOW
		SPR_IDX_SELECT		_spr_lib8_40
		SUSPEND				$08
		SPR_IDX_SELECT		_spr_lib8_41
		SUSPEND				$08
		SPR_IDX_SELECT		_spr_lib8_44
		SUSPEND				$08
		SPR_IDX_SELECT		_spr_lib8_45
		SUSPEND				$08
		OBJ_HIDE
		SRET

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_6A069:
		APU_LOAD			_apu_mus46
		SPR_LIB_SELECT		_spr_lib8
		OBJ_SHOW
		SPR_IDX_SELECT		_spr_lib8_40
		SUSPEND				$08
		SPR_IDX_SELECT		_spr_lib8_41
		SUSPEND				$08
		SPR_IDX_SELECT		_spr_lib8_42
		SUSPEND				$08
		SPR_IDX_SELECT		_spr_lib8_43
		SUSPEND				$08
		OBJ_HIDE
		SRET

; =============== S C R I P T ===============================================
_script12A:
		SPR_LIB_SELECT		_spr_lib8
		OBJ_SHOW
byte_6A083:
		APU_LOAD			_apu_mus43
byte_6A085:
		SPR_IDX_SELECT		_spr_lib8_3F
		NJSR_SYNC			_native_sub020
		NJSR_SYNC			_native_sub020
		SPR_IDX_SELECT		_spr_lib8_54
		NJSR_SYNC			_native_sub020
		NJSR_SYNC			_native_sub020
		LOOPA				$0A,byte_6A085
		SJMPS				byte_6A083

; =============== S U B R O U T I N E =======================================
_native_sub020:
		LDY		_scr_idxAs,X
		LDA		_obj_y_deltas,Y
		BPL		loc_6A0C6
		CLC
		LDA		_obj_y_lo_poss,Y
		ADC		#$04
		STA		_obj_y_lo_poss,X
		LDA		_nmi_frames_counter
		LSR
		BCC		loc_6A0BC
		CLC
		LDA		_obj_x_lo_poss,Y
		ADC		#$18
		STA		_obj_x_lo_poss,X
		RTS
loc_6A0BC:
		SEC
		LDA		_obj_x_lo_poss,Y
		SBC		#$20
		STA		_obj_x_lo_poss,X
		RTS
loc_6A0C6:
		LDA		#_OBJ_MODE_HIDE
		STA		_scr_params,X
		STA		_scr_vars21,X
		RTS

; =============== S C R I P T ===============================================
_script124:
		NJSR				_native_obj_idxCs_clear_low_nibble
		OBJ_FLIPS_SET		_OBJ_FLIPS08
		SPR_LIB_SELECT		_spr_lib8
		SPR_IDX_SELECT		_spr_lib8_52
		OBJ_SHOW
		OBJ_Y_POS_SET		$BC,$00
byte_6A0DC:
		OBJ_X_POS_SET		$00,$00
		SJSRS				_script_sub_6A0F7
		OBJ_X_POS_SET		$20,$00
		SJSRS				_script_sub_6A0F7
		OBJ_X_POS_SET		$10,$00
		SJSRS				_script_sub_6A0F7
		OBJ_X_POS_SET		$30,$00
		SJSRS				_script_sub_6A0F7
		SJMPS				byte_6A0DC

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_6A0F7:
		SYNC
		OBJ_X_POS_MOVE		$40
		LOOPA				$04,_script_sub_6A0F7
		SRET

; =============== S C R I P T ===============================================
_script125:
		TARGET_DIR_SET		$04
		OBJ_X_POS_SET		$20,$00
		OBJ_Y_POS_SET		$20,$00
		SJSRS				_script_sub_6A132
		NJSR				_pal_bg000_load
		KILL

; =============== S C R I P T ===============================================
_script126:
		TARGET_DIR_SET		$02
		OBJ_X_POS_SET		$C0,$00
		OBJ_Y_POS_SET		$20,$00
		SJSRS				_script_sub_6A132
		NJSR				_pal_bg001_load
		KILL

; =============== S C R I P T ===============================================
_script127:
		TARGET_DIR_SET		$01
		OBJ_X_POS_SET		$70,$00
		OBJ_Y_POS_SET		$40,$00
		SJSRS				_script_sub_6A132
		NJSR				_pal_bg002_load
		PAL_FADE_OUT		$01,$C0
		NJSR				_native_idxBs_10_test_clear_from_idxAs
		KILL

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_6A132:
		NJSR				_native_sub000
		SPR_LIB_SELECT		_spr_lib5
		SPR_IDX_SELECT		_spr_lib5_06
byte_6A139:
		OBJ_HIDE
		SYNC
		SYNC
		OBJ_SHOW
		SYNC
		SYNC
		LOOPA				$10,byte_6A139
		LOOPB				$06,byte_6A139
		SPR_IDX_SELECT		_spr_lib5_07
		APU_LOAD			_apu_mus6D
		SUSPEND				$10
		SRET

; =============== S U B R O U T I N E =======================================
_pal_bg000_load:
		LDA		#<[_pal_bg000]
		LDY		#>[_pal_bg000]
		JMP		_far_prg3_bg_pal_load

; =============== S U B R O U T I N E =======================================
_pal_bg001_load:
		LDA		#<[_pal_bg001]
		LDY		#>[_pal_bg001]
		JMP		_far_prg3_bg_pal_load

; =============== S U B R O U T I N E =======================================
_pal_bg002_load:
		LDA		#<[_pal_bg002]
		LDY		#>[_pal_bg002]
		JMP		_far_prg3_bg_pal_load

; =============== S U B R O U T I N E =======================================
_native_sub021:
		LDX		#$01
loc_6A165:
		LDA		_players_states,X
		CMP		#$04
		BNE		loc_6A173
		LDA		#$05
		STA		_players_states,X
		LDA		#$00
		STA		_players_vars0A,X
loc_6A173:
		DEX
		BPL		loc_6A165
		RTS

; NOTE, a lot of redundancy here. copy of copy of copy of copy of subs...

; =============== O B J E C T   S C R I P T =================================
_obj_scr20_lvl_exit_left:
		SJSRS				_script_obj_exit_wait_common	; wait for player collision with object
		NJSR				_native_player_exit_left_with_flip_set	; set player parameters to exit with engine
		KILL												; nothing to do here now

; =============== O B J E C T   S C R I P T =================================
_obj_scr21_lvl_exit_right:
; TODO, optimize me!
		SJSRS				_script_obj_exit_right_wait		; call common right left test
		KILL

; =============== O B J E C T   S C R I P T =================================
_obj_scr22_lvl5C_box_bonus_entry:
_obj_scr23_lvl4_box_bonus_entry:
		SJSRS				_script_obj_exit_right_wait		; set right exit common
		NJSR				_native_inc_stage_room_idx		; skip one room ahead, manage your rooms order in _room_cfg_lib
		KILL

; =============== S C R I P T   R O U T I N E ===============================
_script_lvl2_basket_exit_right:
		SJSRS				_script_obj_exit_right_wait		; the same as for other entries, but skips two rooms ahead
		NJSR				_native_inc_stage_room_idx
		NJSR				_native_inc_stage_room_idx
		KILL

; =============== S C R I P T   R O U T I N E ===============================
_script_obj_exit_right_wait:
		SJSRS				_script_obj_exit_wait_common
		NJSR				_native_player_exit_right_with_flip_set
		SRET

; =============== S C R I P T   R O U T I N E ===============================
_script_obj_exit_wait_common:
		OBJ_SIZE_SET		$06,$10
byte_6A19D:
		OBJ_HP_SET			$01
		SJSR				_script_wait_obj_hps_turns_zero
		NJSR				_native_obj_player_from_idxAs_05_state_compare
		SBNES				byte_6A19D
		SRET
; TODO, REMOVE ME, one more redundant opcode here
		OBJ_Y_POS_MOVE		$08
; -

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_6A1AB:
		APU_LOAD			_apu_mus23
		SPR_LIB_SELECT		_spr_lib6
		OBJ_SHOW
		SPR_IDX_SELECT		_spr_lib6_04
		SUSPEND				$06
		SPR_IDX_SELECT		_spr_lib6_05
		SUSPEND				$06
		SPR_IDX_SELECT		_spr_lib6_06
		SUSPEND				$06
		SPR_IDX_SELECT		_spr_lib6_07
		SRET

; =============== O B J E C T   S C R I P T =================================
_obj_scr1B_monterey_refill:
		OBJ_X_POS_MOVE		$50					; set monerei object pos and speed
		OBJ_X_POS_MOVE		$50
		OBJ_X_DELTA_SET		$F0
		SPR_LIB_SELECT		_spr_lib0			; library select and activate
		OBJ_SHOW
byte_6A1C8:
		SPR_IDX_SELECT		_spr_lib0_23		; walk anim loop 40 cycles long
		SJSR				_script_animate10
		SPR_IDX_SELECT		_spr_lib0_24
		SJSR				_script_animate10
		SPR_IDX_SELECT		_spr_lib0_25
		SJSR				_script_animate10
		SPR_IDX_SELECT		_spr_lib0_24
		SJSR				_script_animate10
		LOOPA				$05,byte_6A1C8		; repeat 5 times (5 steps)
		SJSRS				_script_sub_6A204
		TARGET_DIR_SET		$0C
		SRUN				_OBJ_TYPE_TRIGGER,_obj_monterey_1p_prize
		SJSRS				_script_sub_6A208
		SJSRS				_script_sub_6A204
		TARGET_DIR_SET		$0C
		SRUN				_OBJ_TYPE_TRIGGER,_obj_monterey_2p_prize
		SJSRS				_script_sub_6A208
		SJSRS				_script_sub_6A204
		NJSR				_native_sub15A
byte_6A1FE:
		SJSRS				_script_sub_6A208
		SJMPS				byte_6A1FE

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_6A204:
		SPR_IDX_SELECT		_spr_lib0_1C
		TARGET_DIR_SET		$00

; !FALLTHROUGH!

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_6A208:
		NJSR_SYNC			_native_cut_monterey_talk_spr_insert
		LOOPB				$1E,_script_sub_6A208
		SRET

; =============== S C R I P T ===============================================
_obj_monterey_1p_prize:
		OBJ_X_DELTA_SET		$DE
		SJMPS				_obj_monterey_prize_common

; =============== S C R I P T ===============================================
_obj_monterey_2p_prize:
		OBJ_X_DELTA_SET		$E8

; =============== S C R I P T   R O U T I N E ===============================
_obj_monterey_prize_common:
		OBJ_X_POS_MOVE		$F2
		OBJ_Y_POS_MOVE		$F2
		OBJ_Y_DELTA_SET		$D8
		SJSRS				_script_acorn_prize_init
		SJSR				_script_acorn_prize_animate
		NJSR				_native_set_def_max_hps_from_idxAs
		KILL

; =============== O B J E C T   S C R I P T =================================
_obj_scr1F_star_prize:
		SPR_LIB_SELECT		_spr_lib6
		SPR_IDX_SELECT		_spr_lib6_01
		OBJ_SIZE_SET		$06,$0C
		OBJ_HP_SET			$01
		OBJ_SHOW
		SJSR				_script_wait_obj_hps_turns_zero
		NJSR				_native_inc_players_lives_from_idxAs

; FALLTHROUGH!

; =============== S C R I P T ===============================================
_script_sub_1up_text_float_up:
		SPR_LIB_SELECT		_spr_lib6
		SPR_IDX_SELECT		_spr_lib6_08

; FALLTHROUGH!

; =============== S C R I P T ===============================================
_script_sub_prize_text_float_animate_with_se:
		NJSR				_native_obj_type_change_auto
		APU_LOAD			_apu_mus37

; FALLTHROUGH!

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_prize_text_float_up_animate:
		OBJ_Y_POS_MOVE		$F0
		OBJ_X_DELTA_SET		$00
		OBJ_Y_DELTA_SET		$FC
		OBJ_SHOW
byte_6A247:
		SJSR				_script_animate16
		LOOPA				$04,byte_6A247
		SUSPEND				$14
		KILL
; TODO, REMOVE ME, script can't go here, because it's already killed
		OBJ_Y_DELTA_SET		$D7
;-

; =============== O B J E C T   S C R I P T =================================
; NOTE, althoug this acorn prize never moved, it uses the same functions
; as for Monterey hp refill prizes in bonus rooms
;
_obj_scr_acorn_prize:
		SJSRS				_script_acorn_prize_init
		SJSR				_script_acorn_prize_animate
		NJSR				_native_increment_players_hps
		KILL

; =============== S C R I P T   R O U T I N E ===============================
_script_acorn_prize_init:
		SPR_LIB_SELECT		_spr_lib6
		SPR_IDX_SELECT		_spr_lib6_00
		OBJ_SIZE_SET		$04,$0A
		OBJ_HP_SET			$01
		OBJ_SHOW
		SRET

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_6A268:
		SPR_LIB_SELECT		_spr_lib6
		SPR_IDX_SELECT		_spr_lib6_03
		OBJ_SIZE_SET		$10,$20
		OBJ_HP_SET			$01
		OBJ_SHOW
		SJSR				_script_wait_obj_hps_turns_zero
		SJMP				_script_sub_6A1AB	; LONG

; =============== O B J E C T   S C R I P T =================================
_obj_scr1D_big_ball_box:
		SJSRS				_script_sub_6A268
		DESTR_PC_SET		byte_6A2A0
		NJSR				_native_obj_type_change_solid_no_damage
		SPR_LIB_SELECT		_spr_lib4
		OBJ_HP_SET			$01
		OBJ_SIZE_SET		$06,$0E
		SJMPS				byte_6A2BD
byte_6A28B:
		OBJ_X_DELTA_SET		$00
		NJSR				_native_obj_type_change_solid_no_damage_idxBs_20_clear
byte_6A290:
		SYNC
		NJSR				_native_get_obj_idxBs
		SBMIS				byte_6A2A0
		SJSR				_script_sub_ballistic_throw_anim
		SBCSS				byte_6A290
		SJMPS				byte_6A2AE
byte_6A2A0:
		SJSR				_script_obj_wait_for_throw
		OBJ_X_DELTA_SET		$10
		OBJ_Y_DELTA_SET		$8C
		NJSR				_native_sub029
		OBJ_HP_SET			$01
		OBJ_DAMAGE_SET		_OBJ_DMG_STUN
byte_6A2AE:
		NJSR				_native_sub11C
		NJSR				_native_obj_type_change_ball
		SJSRS				_script_sub_6A2CF
		NJSR				_far_players_animB_sub0129_G
		SBPLS				byte_6A28B
byte_6A2BD:
		OBJ_Y_DELTA_SET		$E0
		SJSRS				_script_sub_6A2CF
		OBJ_Y_DELTA_SET		$F0
		SJSRS				_script_sub_6A2CF
		OBJ_Y_DELTA_SET		$F8
		SJSRS				_script_sub_6A2CF
		SJMPS				byte_6A28B

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_6A2CF:
		NJSR_SYNC			_native_sub022
		OBJ_HP_SET			$01
		OBJ_DAMAGE_SET		_OBJ_DMG_STUN
		NJSR				_native_obj_y_parabolic_delta_adjust
		SJSR				_script_sub_6A557
		SBCCS				_script_sub_6A2CF
		SRET

; =============== S U B R O U T I N E =======================================
_native_sub022:
		LDA		#<[byte_6A2E7]
		LDY		#>[byte_6A2E7]
		JMP		_native_sub023

byte_6A2E7:
		.BYTE	_spr_lib4_03_idx,$00
		.BYTE	_spr_lib4_04_idx,$00
		.BYTE	_spr_lib4_03_idx,$40
		.BYTE	_spr_lib4_04_idx,$C0

; =============== S U B R O U T I N E =======================================
_native_sub023:
		STA		_tmp_ptr0
		STY		_tmp_ptr0+1
		LDA		_scr_vars16,X
		INC		_scr_vars16,X
		INC		_scr_vars16,X
		LSR
		LSR
		LSR
		AND		#$06
		TAY
		LDA		(_tmp_ptr0),Y
		STA		_obj_spr_idxs,X
		INY
		LDA		_obj_flips,X
		AND		#[~[_OBJ_VFLIP|_OBJ_HFLIP]&$FF]
		ORA		(_tmp_ptr0),Y
		STA		_obj_flips,X
		RTS

; =============== O B J E C T   S C R I P T =================================
_obj_scr1E_big_zipper_box:
		SJSR				_script_sub_6A268
		NJSR				_native_obj_type_change_solid_no_damage
		NJSR				_native_idxBs_20_set
		OBJ_FLIPS_SET		_OBJ_UNDER_BG
		SPR_LIB_SELECT		_spr_lib5
		SPR_IDX_SELECT		_spr_lib5_08
		OBJ_SIZE_SET		$14,$0F
		OBJ_HP_SET			$01
		CHR_SELECT			$01,$00
		OBJ_SHOW
		OBJ_Y_DELTA_SET		$D7
		SJSR				_script_sub_obj_wait_for_jump
byte_6A330:
		NJSR_SYNC			_native_obj_to_obj_jump_up_test
		SBCCS				byte_6A330
		SRUN				_OBJ_TYPE_AUTO,_obj_scr_big_zipper_box_zipper
		SUSPEND				$B0
		SRUN				_OBJ_TYPE_AUTO,_obj_scr_big_zipper_box_water
		SJMP				_script_idle

; =============== S C R I P T ===============================================
_obj_scr_big_zipper_box_water:
		SRUN				_OBJ_TYPE_AUTO,_obj_scr_big_zipper_box_flow
		NJSR_SYNC			_native_obj_to_obj_idxCs_link
		SUSPEND				$24
		OBJ_X_POS_MOVE		$C0
		OBJ_SIZE_SET		$40,$00
byte_6A351:
		NJSR_SYNC			_native_big_zipper_box_water_anim
		SJMPS				byte_6A351

; =============== S U B R O U T I N E =======================================
_native_big_zipper_box_water_anim:
		LDA		_obj_heights,X
		BEQ		loc_6A370
		LDY		#$01
loc_6A35E:
		LDA		_obj_flips,Y
		AND		#_OBJ_FLIPS04
		BNE		loc_6A36D
		JSR		_obj_to_obj_collision_test
		BCC		loc_6A36D
		JSR		_player_kill
loc_6A36D:
		DEY
		BPL		loc_6A35E
loc_6A370:
		JSR		_native_get_link_obj_idx_from_idxCs
		LDA		_scr_loopsB,Y
		CMP		#$F6
		BCS		locret_6A3DD
		SEC
		SBC		#$26
		BCC		locret_6A3DD
		TAX
		AND		#$0F
		BNE		locret_6A3DD
		TXA
		LSR
		LSR
		LSR
		AND		#$1E
		PHA
		TAX
		LDA		word_6A3DE,X
		STA		_tmp_ptr44
		LDA		word_6A3DE+1,X
		STA		_tmp_ptr44+1
		LDA		#$12
		STA		_tmp_ptr2
		LDA		#<[_tlm15]
		LDY		#>[_tlm15]
		JSR		_far_prg3_tlm_queue
		PLA
		BEQ		locret_6A3DD
		CMP		#$06
		BCC		loc_6A3B3
		LDX		_scr_idx
		CLC
		LDA		_obj_heights,X
		ADC		#$08
		STA		_obj_heights,X
loc_6A3B3:
		CLC
		LDA		_tmp_ptr44
		ADC		#$20
		STA		_tmp_ptr44
		LDA		_tmp_ptr44+1
		ADC		#$00
		STA		_tmp_ptr44+1
		LDA		#$92
		STA		_tmp_ptr2
		LDA		#<[_tlm16]
		LDY		#>[_tlm16]
		JSR		_far_prg3_tlm_queue
		LDX		_scr_idx
		LDA		_scr_idxAs,X
		TAX
		SEC
		LDA		_obj_y_lo_poss,X
		SBC		#$08
		STA		_obj_y_lo_poss,X
		JSR		_native_players_obj_ride_y_sync
locret_6A3DD:
		RTS

word_6A3DE:
		.WORD	$2328
		.WORD	$2308
		.WORD	$22E8
		.WORD	$22C8
		.WORD	$22A8
		.WORD	$2288
		.WORD	$2268
		.WORD	$2248
		.WORD	$2228
		.WORD	$2208
		.WORD	$21E8
		.WORD	$21C8
		.WORD	$21A8
		.WORD	$2288

; =============== S C R I P T ===============================================
_obj_scr_big_zipper_box_flow:
		OBJ_X_POS_MOVE		$86
		OBJ_Y_POS_MOVE		$B0
		OBJ_Y_POS_MOVE		$AF
		SPR_LIB_SELECT		_spr_lib0
		SPR_IDX_SELECT		_spr_lib0_10
byte_6A404:
		APU_LOAD			_apu_mus4B
byte_6A406:
		NJSR_SYNC			_native_big_zipper_box_flow_anim
		SBCS				_script_idle
		LOOPA				$28,byte_6A406
		SJMPS				byte_6A404

; =============== S U B R O U T I N E =======================================
_native_big_zipper_box_flow_anim:
		LDA		_nmi_frames_counter
		AND		#$03
		TAY
		LDA		byte_6A455,Y
		STA		_tmp_ptr0
		LDA		#$94
		STA		_ram_buf0
		LDA		#$00
		STA		_ram_buf0+1
		STA		_ram_buf0+2
		LDX		#$00
loc_6A42C:
		LDA		_tmp_ptr0
		STA		_ram_buf0+3,X
		LDA		#$22
		STA		_ram_buf0+4,X
		INX
		INX
		CPX		#$28
		BCC		loc_6A42C
		LDA		#$00
		STA		_ram_buf0+3,X
		LDA		#<[_obj_spr_lib_insert]
		LDY		#>[_obj_spr_lib_insert]
		JSR		_farcall
		LDX		_scr_idx
		INC		_scr_loopsB,X
		LDA		_scr_loopsB,X
		CMP		#$F6
		JMP		_scr_flags_update

byte_6A455:
		.BYTE	$A8,$AA,$AC,$BF

; =============== S C R I P T ===============================================
_obj_scr_big_zipper_box_zipper:
		STORE				$10,_pal_anim_mode_idx
		NJSR				_native_look_for_sink_valve_obj
		OBJ_Y_POS_MOVE		$DA
		SPR_LIB_SELECT		_spr_lib0
		OBJ_SHOW
		OBJ_X_DELTA_SET		$E7
		OBJ_Y_DELTA_SET		$E8
byte_6A469:
		SJSRS				_script_sub_zipper_box_zipper_anim
		LOOPB				$0F,byte_6A469
byte_6A470:
		OBJ_X_DELTA_SET		$00
		OBJ_Y_DELTA_SET		$00
		SJSRS				_script_sub_zipper_box_zipper_anim
		SJSRS				_script_sub_zipper_box_zipper_anim
		OBJ_Y_DELTA_SET		$20
		NJSR				_native_idxBs_10_test_clear_from_idxCs
		SJSRS				_script_sub_zipper_box_zipper_anim
		OBJ_Y_DELTA_SET		$F0
		SJSRS				_script_sub_zipper_box_zipper_anim
		SJSRS				_script_sub_zipper_box_zipper_anim
		LOOPA				$03,byte_6A470
		NJSR				_native_obj_idxCs_80_set
		OBJ_X_DELTA_SET		$E8
		OBJ_Y_DELTA_SET		$E8
		SJMP				_script_sub_infinite_anim_sync

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_zipper_box_zipper_anim:
		SPR_IDX_SELECT		_spr_lib0_17
		OBJ_ANIMATE_SYNC
		OBJ_ANIMATE_SYNC
		OBJ_ANIMATE_SYNC
		SPR_IDX_SELECT		_spr_lib0_18
		OBJ_ANIMATE_SYNC
		OBJ_ANIMATE_SYNC
		OBJ_ANIMATE_SYNC
		SRET

; =============== S U B R O U T I N E =======================================
_native_look_for_sink_valve_obj:
		LDY		#$0B
loc_6A4A5:
		LDA		_scr_params,Y
		AND		#_OBJ_TYPE_MASK
		BEQ		loc_6A4BA
		LDA		_obj_spr_idxs,Y
		CMP		#_spr_lib5_09_sink_valve_idx
		BNE		loc_6A4BA
		LDA		_obj_spr_libs,Y
		CMP		#_spr_lib5_idx
		BEQ		loc_6A4BE
loc_6A4BA:
		DEY
		JMP		loc_6A4A5
loc_6A4BE:
		TYA
		STA		_scr_idxCs,X
		RTS

; =============== O B J E C T   S C R I P T =================================
_obj_scr09_sink_valve:
		NJSR				_native_idxBs_20_set
		NJSR				_scr_flips_04_set
		SPR_LIB_SELECT		_spr_lib5
		SPR_IDX_SELECT		_spr_lib5_09_sink_valve
		SJSR				_script_sub_obj_show_wait_for_idxCs_80_set
byte_6A4D0:
		NJSR				_native_idxBs_10_set
byte_6A4D3:
		NJSR_SYNC			_native_idxBs_10_test
		SBNES				byte_6A4D3
		APU_LOAD			_apu_mus69
		SUSPEND				$08
		SPR_IDX_SELECT		_spr_lib5_0A
		SUSPEND				$04
		SPR_IDX_SELECT		_spr_lib5_0B
		SUSPEND				$04
		SPR_IDX_SELECT		_spr_lib5_09_sink_valve
		SJMPS				byte_6A4D0

; =============== O B J E C T   S C R I P T =================================
_obj_scr07_concrete_brick:
		DESTR_PC_SET		_obj_scr07_concrete_brick_destr
		NJSR				_native_idxBs_10_set
		OBJ_X_POS_MOVE		$08
		SPR_LIB_SELECT		_spr_lib4
		SPR_IDX_SELECT		_spr_lib4_00
		OBJ_SIZE_SET		$06,$0E
		SJSR				_script_sub_obj_show_wait_for_idxCs_80_set
byte_6A4FC:
		SPR_IDX_SELECT		_spr_lib4_00
		OBJ_FLIPS_SET		$00
		OBJ_HP_SET			$01
		OBJ_X_DELTA_SET		$00
		NJSR				_native_obj_type_change_solid_no_damage_idxBs_20_clear
byte_6A507:
		SYNC
		NJSR				_native_get_obj_idxBs
		SBMIS				byte_6A517
		SJSRS				_script_sub_ballistic_throw_anim
		SBCSS				byte_6A507
		SJMPS				byte_6A53E
byte_6A517:
		NJSR				_native_sub164
		NJSR				_native_obj_idxCs_clear_low_nibble
byte_6A51D:
		NJSR				_native_get_obj_idxBs
		SBPLS				byte_6A535
		NJSR				_native_get_obj_hp
		SBEQS				byte_6A52F
		NJSR_SYNC			_native_sub02B
		SJMPS				byte_6A51D
byte_6A52F:
		NJSR				_native_sub032
		SJMPS				byte_6A4FC
byte_6A535:
		OBJ_X_DELTA_SET		$10
		OBJ_Y_DELTA_SET		$8C
		NJSR				_native_sub029
		APU_LOAD			_apu_mus24
byte_6A53E:
		NJSR				_native_sub11C
		NJSR				_native_obj_type_change_ball
		OBJ_HP_SET			$FF
		OBJ_DAMAGE_SET		_OBJ_DMG_STUN
		SPR_IDX_SELECT		_spr_lib4_00
byte_6A54A:
		SYNC
		NJSR				_native_obj_y_parabolic_delta_adjust
		SJSRS				_script_sub_6A557
		SBCCS				byte_6A54A
		SJMPS				byte_6A4FC

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_6A557:
		NJSR				_native_idxBs_20_set
		NJSR				_obj_move_hor_animate
		NJSR				_native_sub13C
		SBCSS				byte_6A569
		NJSR				_native_obj_to_tile_collision_test_hor
		SBCSS				byte_6A56B
byte_6A569:
		OBJ_X_DELTA_SET		$00
byte_6A56B:
		NJSR				_native_obj_y_parabolic_delta_adjust
		NJSR				_native_get_obj_y_delta
		SBPLS				_script_sub_ballistic_throw_anim
		NJSR				_obj_vert_animate
		NJSR				_native_sub165
		SBCCS				byte_6A583
		NJSR				_native_obj_to_tile_collision_test_up
		SBCSS				byte_6A585
byte_6A583:
		OBJ_Y_DELTA_SET		$01
byte_6A585:
		NJSR				_scr_flags_flush_clc
		SRET

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_ballistic_throw_anim:
		NJSR				_obj_vert_animate
		NJSR				_native_sub107
		SBCSS				byte_6A598
		NJSR				_native_obj_to_tile_collision_test_down
		SBCCS				byte_6A59A
byte_6A598:
		OBJ_Y_DELTA_SET		$00
byte_6A59A:
		SRET

; =============== O B J E C T   S C R I P T =================================
_obj_scr07_concrete_brick_destr:
		NJSR				_native_idxBs_20_set
		OBJ_X_DELTA_SET		$00
		NJSR				_native_get_obj_y_delta
		SBMIS				byte_6A5A8
		OBJ_Y_DELTA_SET		$00
byte_6A5A8:
		SJSRS				_script_sub_6A5BA
		NJSR				_native_sub027
		SBCCS				byte_6A5A8
		NJSR				_native_obj_type_change_solid
		SJSRS				_script_sub_6A5BA
		SJMPS				byte_6A5A8

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_6A5BA:
		SYNC
		NJSR				_native_get_obj_idxBs
		SBPLS				byte_6A5C4
		NJSR				_native_sub028
byte_6A5C4:
		SRET

; =============== S U B R O U T I N E =======================================
_native_sub027:
		LDA		_obj_y_deltas,X
		BPL		loc_6A5CE
		CMP		#$B0
		BCC		loc_6A5D7
loc_6A5CE:
		DEC		_obj_y_deltas,X
		DEC		_obj_y_deltas,X
		DEC		_obj_y_deltas,X
loc_6A5D7:
		JSR		_obj_vert_animate
		JSR		_players_animB_sub0129_sub12_A_B_A
		BCC		loc_6A5E3
		JSR		_players_animB_sub0129_sub12_A_B_B
		SEC
loc_6A5E3:
		JMP		_scr_flags_update

; =============== S U B R O U T I N E =======================================
_native_sub028:
		LDA		#$00
		STA		_obj_flips,X
		JMP		_native_sub033

; =============== S U B R O U T I N E =======================================
_native_sub029:
		LDA		_scr_idxBs,X
		AND		#$0F
		TAY
		LDA		_obj_flips,Y
		AND		#_OBJ_HFLIP
		STA		_obj_flips,X
		JSR		_native_obj_hor_delta_toggle
		JMP		_native_obj_hflip_clear

; =============== O B J E C T   S C R I P T =================================
_obj_scr_box:
		DESTR_PC_SET		_obj_scr_box
		NJSR				_native_obj_idxCs_clear_low_nibble
		NJSR				_native_idxBs_10_set
		SPR_LIB_SELECT		_spr_lib3
		SPR_IDX_SELECT		_spr_lib3_00
		OBJ_SIZE_SET		$06,$0F
		OBJ_HP_SET			$01
		OBJ_SHOW
byte_6A615:
		NJSR				_native_get_obj_idxBs
		SBPLS				byte_6A630
		NJSR				_native_get_obj_hp
		SBNES				byte_6A627
		NJSR				_native_sub033
		SJMPS				byte_6A669
byte_6A627:
		NJSR				_native_sub02B
		NJSR_SYNC			_native_sub02E
		SJMPS				byte_6A615
byte_6A630:
		NJSR				_native_obj_type_change_throw
		NJSR				_native_obj_idxCs_80_set
		NJSR				_native_sub02A
		SBNES				byte_6A653
		APU_LOAD			_apu_mus27
		NJSR				_native_sub02F
		OBJ_Y_DELTA_SET		$F0
byte_6A643:
		SPR_IDX_SELECT		_spr_lib3_00
		NJSR				_native_sub02E
		OBJ_ANIMATE_SYNC
		LOOPA				$08,byte_6A643
		NJSR				_native_complement_y_deltas
		SJMPS				byte_6A643
byte_6A653:
		SPR_IDX_SELECT		_spr_lib3_00
		APU_LOAD			_apu_mus24
		NJSR				_native_obj_throw_direction_select
byte_6A65A:
		OBJ_ANIMATE_SYNC
		NJSR				_native_get_obj_hp
		SBPLS				byte_6A666
		NJSR				_j_native_complement_x_deltas
		OBJ_HP_SET			$01
byte_6A666:
		SBNES				byte_6A65A
byte_6A669:
		NJSR_SYNC			_native_obj_type_change_auto
		SPR_IDX_SELECT		_spr_lib3_03
		SYNC
		SPR_IDX_SELECT		_spr_lib3_04
		SYNC
		SPR_IDX_SELECT		_spr_lib3_05
		SYNC
		SPR_IDX_SELECT		_spr_lib3_06
		SYNC
		SPR_IDX_SELECT		_spr_lib3_07
		SYNC
		KILL

; =============== S U B R O U T I N E =======================================
_native_sub02A:
		LDA		_obj_damages,X
		CMP		#_OBJ_DMG_STUN
		JMP		_scr_flags_update

; =============== S U B R O U T I N E =======================================
_native_sub02B:
		JSR		_native_sub031
		JSR		_players_animB_sub0129_sub06_C
		BMI		_native_sub02C
		BEQ		_native_sub02C
		LDA		#_OBJ_MODE_HIDE
		STA		_scr_params,X
		RTS

; =============== S U B R O U T I N E =======================================
_native_sub02C:
		LDA		_obj_heights,Y
		BEQ		_native_sub02D
		JSR		_native_obj_type_change_throw
		JMP		_scr_flips_04_set

; =============== S U B R O U T I N E =======================================
_native_sub02D:
		INC		_obj_y_lo_poss,X
		JSR		_native_obj_type_change_solid
		JMP		_scr_flips_04_clear

; =============== S U B R O U T I N E =======================================
_native_sub02E:
		LDA		_nmi_frames_counter
		AND		#$04
		BEQ		locret_6A6BA
		LDA		_obj_damages,X
		CMP		#_OBJ_DMG_STUN
		BNE		locret_6A6BA
		LDA		#$08
		STA		_obj_spr_idxs,X
locret_6A6BA:
		RTS

; =============== S U B R O U T I N E =======================================
_native_sub02F:
		LDA		_scr_idxBs,X
		AND		#$0F
		TAX
		JMP		loc_6A6E5

; =============== S U B R O U T I N E =======================================
_native_obj_throw_direction_select:
		LDA		#_OBJ_DMG_KILL
		STA		_obj_damages,X			; WARNING, if _OBJ_DMG_STUN changes,
		STA		_obj_hps,X				; fix it here! hp=1 _OBJ_DMG_KILL=$01!
		LDA		_scr_idxBs,X			; get idx who's carry throwable object
		AND		#$0F
		TAX
		LDY		#$00
loc_6A6D4:
		LDA		_pads,X					; test its pads held
		AND		byte_6A700,Y
		CMP		byte_6A700,Y
		BEQ		loc_6A6F1
		INY
		INY
		INY
		CPY		#$0F
		BCC		loc_6A6D4
loc_6A6E5:
		LDY		#$09
		LDA		_obj_flips,X
		AND		#_OBJ_HFLIP
		BEQ		loc_6A6F1
		INY
		INY
		INY
loc_6A6F1:
		LDX		_scr_idx				; when corresponding button found, pick values
		LDA		byte_6A700+1,Y			; from the tables and set the obj delta
		STA		_obj_x_deltas,X
		LDA		byte_6A700+2,Y
		STA		_obj_y_deltas,X
		RTS

byte_6A700:
		.BYTE	$50,$C0,$C0
		.BYTE	$90,$40,$C0
		.BYTE	$10,$00,$A0
		.BYTE	$40,$C0,$00
		.BYTE	$80,$40,$00

; =============== S U B R O U T I N E =======================================
_native_sub031:
		JSR		_native_get_idxBs_low_nibble
		LDA		_players_vars09,Y
		STA		_obj_spr_idxs,X
		RTS

; =============== S U B R O U T I N E =======================================
_native_sub032:
		JSR		_native_get_idxBs_low_nibble
		LDA		_obj_y_lo_poss,Y
		STA		_obj_y_lo_poss,X
		CLC
		SBC		_obj_heights,X
		STA		_obj_y_lo_poss,Y

; =============== S U B R O U T I N E =======================================
_native_sub033:
		LDA		_scr_idxBs,X
		AND		#$7F
		STA		_scr_idxBs,X
		JSR		_native_get_idxBs_low_nibble
		LDA		_scr_idxBs,Y
		AND		#$BF
		STA		_scr_idxBs,Y
		RTS

; =============== O B J E C T   S C R I P T =================================
_script40:
		SPR_LIB_SELECT		_spr_lib0
		SPR_IDX_SELECT		_spr_lib0_0F
		OBJ_FLIPS_SET		_OBJ_FLIPS08|_OBJ_FLIPS04
		OBJ_SHOW
byte_6A744:
		OBJ_X_DELTA_SET		$00
		OBJ_Y_DELTA_SET		$00
		SJSRS				_script_sub_6A77C
		OBJ_X_DELTA_SET		$C0
		OBJ_Y_DELTA_SET		$00
		SJSRS				_script_sub_6A77C
		OBJ_X_DELTA_SET		$A0
		OBJ_Y_DELTA_SET		$E0
		SJSRS				_script_sub_6A77C
		OBJ_X_DELTA_SET		$C0
		OBJ_Y_DELTA_SET		$B0
		SJSRS				_script_sub_6A77C
		OBJ_X_DELTA_SET		$00
		OBJ_Y_DELTA_SET		$B0
		SJSRS				_script_sub_6A77C
		OBJ_X_DELTA_SET		$40
		OBJ_Y_DELTA_SET		$B0
		SJSRS				_script_sub_6A77C
		OBJ_X_DELTA_SET		$60
		OBJ_Y_DELTA_SET		$E0
		SJSRS				_script_sub_6A77C
		OBJ_X_DELTA_SET		$40
		OBJ_Y_DELTA_SET		$00
		SJMPS				byte_6A744

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_6A77C:
		NJSR				_native_obj_linked_idxCs_follow
		OBJ_ANIMATE_SYNC
		LOOPA				$04,_script_sub_6A77C
		SRET

; =============== O B J E C T   S C R I P T =================================
_obj_scr08_cdv_bottle_cork:
		NJSR				_native_idxBs_20_set
		OBJ_X_POS_MOVE		$08
		SPR_LIB_SELECT		_spr_lib5
		SPR_IDX_SELECT		_spr_lib5_00
		OBJ_SIZE_SET		$08,$07
		OBJ_HP_SET			$01
		OBJ_SHOW
		SJSR				_script20D
		SPR_IDX_SELECT		_spr_lib5_01
		OBJ_SIZE_SET		$08,$04
		NJSR				_native_obj_y_adjust_by_height_from_idxAs
		SJSR				_script20D
		SPR_IDX_SELECT		_spr_lib5_02
		OBJ_SIZE_SET		$08,$02
		NJSR				_native_obj_y_adjust_by_height_from_idxAs
		SJSR				_script20D
		SPR_IDX_SELECT		_spr_lib5_03
		OBJ_SIZE_SET		$08,$0F
		NJSR				_native_obj_y_adjust_by_height_from_idxAs
		APU_LOAD			_apu_mus4A
		OBJ_X_DELTA_SET		$10
		OBJ_Y_DELTA_SET		$C0
byte_6A7BB:
		OBJ_ANIMATE_SYNC
		NJSR				_native_obj_y_parabolic_delta_adjust
		NJSR				_native_obj_to_obj_jump_up_test
		SBCCS				byte_6A7BB
		NJSR				_native_obj_y_adjust_by_height_from_idxAs
		SJMPS				byte_6A7BB

; =============== O B J E C T   S C R I P T =================================
_obj_scr0A_lvl2_blocked_path:
		SJSRS				_script_sub_obj_button_common_init	; init
		SJSRS				_script_sub_button_push_wait		; wait for jump up
		SRUN				_OBJ_TYPE_AUTO,_script_lvl2_wall_blocks_open_draw	; open the blocked path
byte_6A7D5:
		SJSRS				_script_sub_button_release_wait		; loop forever between
		SJSRS				_script_sub_button_push_wait		; two states now, does nothing more
		SJMPS				byte_6A7D5

; =============== S C R I P T ===============================================
; draws an animation of removing wall bricks blocking the entry to
; the basket game room warp
;
; BUG: there are three possible states of the blocking bricks "fully bumped",
; "half-sinked" and "fully sinked". The corresponding tiles are 80, 84 and 82
; in CHR ROM for this room.
;
; judging from script below, they planned to sink this blocking bricks in two
; frames one by one. the second drawing call does nothing because there is no
; proper data pointer initialization, and after the previous call this ptr
; points to 00.
;
; don't know wether this is a bug or they removed it on purpose, but currently
; we see one-frame anim when block sink to its "fully sinked" state.
; if we assume, the second draw should draw the "half-sink" state, the animation
; looks odd... most probably, the unused patch should go first (as an evidence,
; macro tile for "half-sink" is 45, for "fully sink" is 46) but then why
; both blocks put in the CHR ROM in reverse order... not sure how I need to fix
; it here, but assume the reverse order is a correct one.
;
; FIX, restores missing ptr setting and swapping both tiles to be animated
; in a more likely proper way.
;
_script_lvl2_wall_blocks_open_draw:
#if BUGFIXES=1
		STORE				<[_tlm_patch_06A_unused],_tmp_ptr4B	; load tlm patch ptr
		STORE				>[_tlm_patch_06A_unused],_tmp_ptr4B+1
#else
		STORE				<[tlm_patch06],_tmp_ptr4B	; load tlm patch ptr
		STORE				>[tlm_patch06],_tmp_ptr4B+1
#endif
		SJSR				_script_sub_macro_patch_draw; draw full patch
		APU_LOAD			_apu_mus4E							; start a sound and wait
		SUSPEND				$08							; for a while...
#if BUGFIXES=1
		STORE				<[tlm_patch06],_tmp_ptr4B
		STORE				>[tlm_patch06],_tmp_ptr4B+1
#endif
		SJSR				_script_sub_macro_patch_draw
		KILL

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_obj_button_common_init:
		NJSR				_native_idxBs_20_set	; init button object flags
		SPR_LIB_SELECT		_spr_lib5				; set library and sprite idxes
		SPR_IDX_SELECT		_spr_lib5_0C
		OBJ_SIZE_SET		$05,$0D					; bounding box size
		OBJ_HP_SET			$01						; hit-points
		OBJ_SHOW								; enable object
		SRET

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_button_push_wait:
		SYNC										; sync with engine code
		NJSR				_native_obj_to_obj_jump_up_test	; get jump-up event
		SBCCS				_script_sub_button_push_wait	; idle if no one jumped up
		SPR_IDX_SELECT		_spr_lib5_0D			; when jumped, display another
		OBJ_SIZE_SET		$05,$08					; sprite and set another size
		NJSR				_native_obj_y_adjust_by_height_from_idxAs
		NJSR				_native_idxBs_10_set	; adjust cur jumped obj pos y
		SRET

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_button_release_wait:
		SYNC										; same as for push but wait when
		NJSR				_native_obj_to_obj_jump_up_test	; someone jump off
		SBCSS				_script_sub_button_release_wait

; !FALLTHROUGH!

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_button_release_anim:
		NJSR				_native_idxBs_10_clear	; clear push state flag
		SUSPEND				$08						; wait a little
		SPR_IDX_SELECT		_spr_lib5_0E		; set half-released sprite and size
		OBJ_SIZE_SET		$05,$0A
		NJSR				_native_obj_to_obj_jump_up_test	; if still no one jumped up again
		SBCCS				byte_6A82D				; adjust y pos then leave
		NJSR				_native_obj_y_adjust_by_height_from_idxAs
		SRET
byte_6A82D:
		SUSPEND				$04						; second frame set full release state
		SPR_IDX_SELECT		_spr_lib5_0C
		OBJ_SIZE_SET		$05,$0D					; also test again if still free
		NJSR				_native_obj_to_obj_jump_up_test
		SBCCS				byte_6A83D				; and leave
		NJSR				_native_obj_y_adjust_by_height_from_idxAs
byte_6A83D:
		SRET

; =============== O B J E C T   S C R I P T =================================
_obj_scr0B_lvl2_basket_game_entry:
		SJSRS				_script_sub_obj_button_common_init	; one botton will controlled here
		SRUN				_OBJ_TYPE_SOLID,_obj_scr_lvl2_basket_game_2nd_button	; here is the second button
		NJSR				_native_obj_to_obj_idxCs_link
		NJSR				_native_obj_idxCs_clear_low_nibble
		OBJ_X_POS_MOVE		$50									; change position of current main button
byte_6A84D:
		SJSRS				_script_sub_button_push_wait		; wait for press
byte_6A850:
		NJSR				_native_idxBs_10_test_clear_from_idxCs	; here we test if other button pressed too
		SBNES				byte_6A863
		NJSR				_native_obj_to_obj_jump_up_test
		SYNC
		SBCSS				byte_6A850
		SJSRS				_script_sub_button_release_anim
		SJMPS				byte_6A84D
byte_6A863:
		STORE				<[tlm_patch07],_tmp_ptr4B			; if both pressed, open the door
		STORE				>[tlm_patch07],_tmp_ptr4B+1
		SJSR				_script_sub_macro_patch_draw
		SRUN				_OBJ_TYPE_TRIGGER,_obj_scr_lvl2_basket_exit_right	; insert actual door object
		APU_LOAD			_apu_mus4F									; open sound
; TODO, optimize me! redundant!
byte_6A874:
		SJSRS				_script_sub_button_release_wait		; common idle button script
		SJSRS				_script_sub_button_push_wait
		SJMPS				byte_6A874
; -

; =============== S C R I P T ===============================================
_obj_scr_lvl2_basket_exit_right:
		OBJ_X_POS_MOVE		$D0
; TODO, optimize me!
		SJMP				_script_lvl2_basket_exit_right

; =============== S C R I P T ===============================================
_obj_scr_lvl2_basket_game_2nd_button:
		SJSR				_script_sub_obj_button_common_init
		NJSR				_native_obj_idxCs_clear_low_nibble
byte_6A888:
		SJSRS				_script_sub_button_push_wait
		SJSRS				_script_sub_button_release_wait
		SJMPS				byte_6A888

; =============== O B J E C T   S C R I P T =================================
_obj_scr0C_lvl3_refill_entry:
		SJSR				_script_sub_obj_button_common_init	; there is a button
		SJSR				_script_sub_button_push_wait		; wait for it
		STORE				<[tlm_patch08],_tmp_ptr4B			; draw open cavity
		STORE				>[tlm_patch08],_tmp_ptr4B+1
		SJSR				_script_sub_macro_patch_draw
		SRUN				_OBJ_TYPE_TRIGGER,_script_lvl3_box_bonus_entry						; run cavity script
		APU_LOAD			_apu_mus4F									; play open sound
; TODO: optimize me!
byte_6A8A8:
		SJSR				_script_sub_button_release_wait		; then work as common button
		SJSR				_script_sub_button_push_wait		; again
		SJMPS				byte_6A8A8

; =============== S C R I P T ===============================================
_script_lvl3_box_bonus_entry:
		OBJ_X_POS_MOVE		$C0									; set position of a door
		OBJ_X_POS_MOVE		$B0
		SJMP				_obj_scr22_lvl5C_box_bonus_entry	; run common box bonus script

; =============== O B J E C T   S C R I P T =================================
_obj_scr0D_big_fan:
		SJSR				_script_wait_for_idxCs_80_set
byte_6A8BB:
		SRUN				_OBJ_TYPE_AUTO,_script13D
		SUSPEND				$5A
		SRUN				_OBJ_TYPE_AUTO,_script13E
		SUSPEND				$5A
		SJMPS				byte_6A8BB

; =============== S C R I P T ===============================================
_script13D:
		OBJ_X_POS_MOVE		$E0

; =============== S C R I P T ===============================================
_script13E:
		OBJ_GRABABLE
		OBJ_X_POS_MOVE		$10
		SPR_LIB_SELECT		_spr_lib5
		OBJ_SHOW
		OBJ_Y_DELTA_SET		$E0
		NJSR				_native_obj_idxCs_80_set
		NJSR				_native_throwable_obj_num_02_cmp
		SBCSS				byte_6A8EC
byte_6A8DD:
		SPR_IDX_SELECT		_spr_lib5_12
		OBJ_Y_DELTA_DEC
		OBJ_ANIMATE_SYNC
		OBJ_ANIMATE_SYNC
		OBJ_ANIMATE_SYNC
		SPR_IDX_SELECT		_spr_lib5_1A
		OBJ_Y_DELTA_DEC
		OBJ_ANIMATE_SYNC
		OBJ_ANIMATE_SYNC
		OBJ_ANIMATE_SYNC
		SJMPS				byte_6A8DD
byte_6A8EC:
		KILL

; =============== O B J E C T   S C R I P T =================================
_obj_scr0E_buttons_room:
		NJSR				_native_sub16B
		SBNES				byte_6A8FD
byte_6A8F3:
		NJSR				_native_inc_stage_room_idx
		LOOPA				$05,byte_6A8F3
		NJSR				_MAIN_START
byte_6A8FD:
		NJSR				_native_box_bonus_3prizes_shuffle
		OBJ_X_POS_SET		$38,$00
byte_6A903:
		NJSR				_native_sub034
		SRUN				_OBJ_TYPE_SOLID,_script13F
		LOOPA				$03,byte_6A903
		NJSR				_native_sub150
		NJSR				_native_box_bonus_3prizes_shuffle
		OBJ_X_POS_SET		$C8,$00
byte_6A917:
		NJSR				_native_sub034
		SRUN				_OBJ_TYPE_SOLID,_script13F
		LOOPA				$03,byte_6A917
		NJSR				_native_sub14B
byte_6A925:
		NJSR_SYNC			_native_sub035
		SBEQS				byte_6A925
		STORE				<[tlm_patch09],_tmp_ptr4B
		STORE				>[tlm_patch09],_tmp_ptr4B+1
		SJSR				_script_sub_macro_patch_draw
		NJSR				_native_obj_type_change_grab
		OBJ_X_POS_SET		$F0,$00
		OBJ_Y_POS_SET		$C0,$00
		OBJ_HIDE
		APU_LOAD			_apu_mus23
		SJMP				_obj_scr21_lvl_exit_right

; =============== S U B R O U T I N E =======================================
_native_sub034:
		JSR		_native_get_box_bonus_prize_from_list
		LDY		_tmp_ptrE+1
		LDA		byte_6A951,Y
		STA		_obj_y_lo_poss,X
		RTS
byte_6A951:
		.BYTE	$40,$80,$C0

; =============== S U B R O U T I N E =======================================
_native_sub035:
		LDY		_scr_idxBs,X
		LDA		_scr_idxBs,Y
		LDY		_scr_idxCs,X
		AND		_scr_idxBs,Y
		AND		#$10
		JMP		_scr_flags_update

; =============== S C R I P T ===============================================
_script13F:
		NJSR				_native_idxBs_20_set
		SPR_LIB_SELECT		_spr_lib5
		SPR_IDX_SELECT		_spr_lib5_14
		OBJ_SIZE_SET		$05,$0C
		OBJ_HP_SET			$01
		OBJ_SHOW
byte_6A972:
		SYNC
		NJSR				_native_obj_to_obj_jump_up_test
		SBCCS				byte_6A972
		SPR_IDX_SELECT		_spr_lib5_15
		OBJ_SIZE_SET		$05,$06
		NJSR				_native_obj_y_adjust_by_height_from_idxAs
		NJSR				_native_idxBs_10_set
byte_6A984:
		SYNC
		NJSR				_native_obj_to_obj_jump_up_test
		SBCSS				byte_6A984
		NJSR				_native_idxBs_10_clear
		SUSPEND				$08
		SPR_IDX_SELECT		_spr_lib5_16
		OBJ_SIZE_SET		$05,$08
		NJSR				_native_obj_to_obj_jump_up_test
		SBCCS				byte_6A99E
		NJSR				_native_obj_y_adjust_by_height_from_idxAs
byte_6A99E:
		SUSPEND				$04
		SPR_IDX_SELECT		_spr_lib5_14
		OBJ_SIZE_SET		$05,$0C
		NJSR				_native_obj_to_obj_jump_up_test
		SBCCS				byte_6A9AE
		NJSR				_native_obj_y_adjust_by_height_from_idxAs
byte_6A9AE:
		SJMPS				byte_6A972

; =============== O B J E C T   S C R I P T =================================
_obj_scr0F_clock_trolleyA:
		OBJ_X_POS_MOVE		$FD
		OBJ_Y_POS_MOVE		$03
		TARGET_DIR_SET		$20
		SJSRS				_script_sub_6AA22
byte_6A9BA:
		SJSRS				_script_sub_6AA11
byte_6A9BD:
		SJSRS				_script_sub_6AA31
		LOOPA				$84,byte_6A9BD
		SJSRS				_script_sub_6AA11
byte_6A9C7:
		SJSRS				_script_sub_6AA31
		LOOPA				$84,byte_6A9C7
		SJMPS				byte_6A9BA

; =============== O B J E C T   S C R I P T =================================
_obj_scr10_clock_trolleyB:
		OBJ_X_POS_MOVE		$03
		OBJ_Y_POS_MOVE		$05
		TARGET_DIR_SET		$00
		SJSRS				_script_sub_6AA22
byte_6A9DA:
		SJSRS				_script_sub_6AA11
byte_6A9DD:
		SJSRS				_script_sub_6AA31
		LOOPA				$84,byte_6A9DD
		SJSRS				_script_sub_6AA11
byte_6A9E7:
		SJSRS				_script_sub_6AA31
		LOOPA				$84,byte_6A9E7
		SJMPS				byte_6A9DA

; =============== O B J E C T   S C R I P T =================================
_obj_scr11_clock_trolleyC:
		OBJ_X_POS_MOVE		$03
		OBJ_Y_POS_MOVE		$05
		TARGET_DIR_SET		$00
		SJSRS				_script_sub_6AA22
byte_6A9FA:
		SJSRS				_script_sub_6AA11
byte_6A9FD:
		SJSRS				_script_sub_6AA31
		LOOPA				$58,byte_6A9FD
		SJSRS				_script_sub_6AA11
byte_6AA07:
		SJSRS				_script_sub_6AA31
		LOOPA				$58,byte_6AA07
		SJMPS				byte_6A9FA

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_6AA11:
		NJSR				_native_sub123
		NJSR				_native_sub124
		NJSR				_native_inc_vars19
		SJSRS				_script_sub_6AA31
		LOOPA				$40,_script_sub_6AA11
		SRET

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_6AA22:
		NJSR				_native_idxBs_20_set
		SPR_LIB_SELECT		_spr_lib5
		SPR_IDX_SELECT		_spr_lib5_13
		OBJ_SIZE_SET		$10,$0E
		OBJ_HP_SET			$01
		SJMP				_script_sub_obj_show_wait_for_idxCs_80_set

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_6AA31:
		SYNC
		OBJ_ANIMATE
		NJSR				_native_players_obj_ride_x_delta_sync
		NJSR				_native_players_obj_ride_y_sync
		SRET

; =============== O B J E C T   S C R I P T =================================
_obj_scr05_door_knob:
		OBJ_X_POS_MOVE		$08
		SPR_LIB_SELECT		_spr_lib5
		SPR_IDX_SELECT		_spr_lib5_46
		SJSR				_script_sub_obj_show_wait_for_idxCs_80_set
byte_6AA43:
		SUSPEND				$10
		SPR_IDX_SELECT		_spr_lib5_47
		SUSPEND				$10
byte_6AA49:
		SPR_IDX_SELECT		_spr_lib5_46
		APU_LOAD			_apu_mus50
		SJMPS				byte_6AA43

; =============== O B J E C T   S C R I P T =================================
_obj_scr06_light_toggle:
		NJSR				_scr_flips_04_set
		NJSR				_native_obj_idxCs_clear_low_nibble
byte_6AA56:
		SJSRS				_script_sub_6AA67
		STORE				$05,_pal_anim_mode_idx
		SJSRS				_script_sub_6AA67
		STORE				$07,_pal_anim_mode_idx
		SJMPS				byte_6AA56

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_6AA67:
		SUSPEND				$F0
		SUSPEND				$F0
		APU_LOAD			_apu_mus35
		SRET

; =============== O B J E C T   S C R I P T =================================
_obj_scr3E_ghost_painting:
		OBJ_X_POS_MOVE		$F8
		OBJ_Y_POS_MOVE		$FC
		SJSR				_script_wait_for_idxCs_80_set
byte_6AA75:
		NJSR_SYNC			_native_sub036
		SBEQS				byte_6AA75
byte_6AA7B:
		NJSR_SYNC			_native_sub036
		SBNES				byte_6AA7B
		SRUN				_OBJ_TYPE_ENEMY,_script140
		SJMPS				byte_6AA75

; =============== S U B R O U T I N E =======================================
_native_sub036:
		LDA		_pal_anim_mode_idx
		CMP		#$05
		JMP		_scr_flags_update

; =============== S C R I P T ===============================================
_script140:
		SPR_LIB_SELECT		_spr_lib7
		OBJ_SHOW
		TARGET_LOCK			$20
		OBJ_SIZE_SET		$0C,$14
byte_6AA97:
		OBJ_HP_SET			$7F
		OBJ_DAMAGE_SET		_OBJ_DMG_KILL
		TARGET_DIR_SET		$00
		SJSRS				_script_sub_6AAC1
		LOOPA				$14,byte_6AA97
		NJSR				_native_sub10E
		NJSR				_native_sub111
		APU_LOAD			_apu_mus36
byte_6AAAC:
		TARGET_DIR_SET		$FF
		SJSRS				_script_sub_6AAC1
		LOOPA				$14,byte_6AAAC
		LOOPB				$03,byte_6AA97
byte_6AAB9:
		TARGET_DIR_SET		$FF
		SJSRS				_script_sub_6AAC1
		SJMPS				byte_6AAB9

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_6AAC1:
		SPR_IDX_SELECT		_spr_lib7_5A
		SJSRS				_script_sub_6AACE
		SJSRS				_script_sub_6AACE
		SPR_IDX_SELECT		_spr_lib7_5B
		SJSRS				_script_sub_6AACE

; !FALLTHROUGH!

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_6AACE:
		NJSR				_scr_flips_04_clear
		TARGET_FOLLOW
		SYNC
		SRET

; =============== O B J E C T   S C R I P T =================================
_obj_scr12_cave_trolley:
		NJSR				_native_idxBs_20_set
		OBJ_Y_POS_MOVE		$EC
		SRUN				_OBJ_TYPE_AUTO,_script141
		NJSR				_native_obj_to_obj_idxCs_link
		OBJ_HP_SET			$01
		OBJ_SIZE_SET		$16,$01
		SPR_LIB_SELECT		_spr_lib5
		SPR_IDX_SELECT		_spr_lib5_33
		OBJ_SHOW
byte_6AAEA:
		SPR_IDX_SELECT		_spr_lib5_33
		SJSRS				_script_sub_6AAFD
		NJSR				_native_get_obj_x_delta
		SBEQS				byte_6AAEA
		SPR_IDX_SELECT		_spr_lib5_34
		SJSRS				_script_sub_6AAFD
		SJMPS				byte_6AAEA

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_6AAFD:
		SYNC
		NJSR				_native_sub038
		SBEQS				byte_6AB0A
		NJSR				_native_obj_y_parabolic_delta_adjust
		SJMPS				byte_6AB0F
byte_6AB0A:
		OBJ_Y_DELTA_SET		$00
		NJSR				_native_sub037
byte_6AB0F:
		OBJ_ANIMATE
		NJSR				_native_players_obj_ride_x_delta_sync
		LOOPA				$04,_script_sub_6AAFD
		SRET

; =============== S U B R O U T I N E =======================================
_native_sub037:
		LDA		_obj_y_lo_poss,X
		AND		#$F0
		ORA		#$0C
		STA		_obj_y_lo_poss,X
		RTS

; =============== S U B R O U T I N E =======================================
_native_sub038:
		STX		byte_E3
		SEC
		LDA		_obj_x_lo_poss,X
		SBC		#$10
		STA		_tmp_ptr0
		LDA		_obj_x_hi_poss,X
		SBC		#$00
		STA		_tmp_ptr0+1
		CLC
		LDA		_obj_y_lo_poss,X
		ADC		#$14
		STA		_tmp_ptr2
		LDA		_obj_y_hi_poss,X
		ADC		#$00
		STA		_tmp_ptr2+1
		JSR		_obj_sys_calc00
		CPX		#$8F
		JMP		_scr_flags_update

; =============== S C R I P T ===============================================
_script141:
		OBJ_FLIPS_SET		_OBJ_FLIPS08
		NJSR				_native_obj_idxCs_clear_low_nibble
		OBJ_HP_SET			$01
		OBJ_SIZE_SET		$01,$08
byte_6AB55:
		SPR_LIB_SELECT		_spr_lib1
		SPR_IDX_SELECT		_spr_lib1_12
		OBJ_SHOW
byte_6AB5A:
		SJSRs				_script_sub_6ABA9
		NJSR				_native_sub03D
		SBCCS				byte_6AB5A
		SPR_IDX_SELECT		_spr_lib1_13
		SJSRS				_script_sub_6AB98
byte_6AB68:
		SJSRS				_script_sub_6ABA9
		NJSR				_native_sub03E
		SBCCS				byte_6AB77
		NJSR				_native_sub03B
		SJMPS				byte_6AB55
byte_6AB77:
		NJSR				_native_sub03C
		SBEQS				byte_6AB90
		SBCCS				byte_6AB88
		SPR_IDX_SELECT		_spr_lib1_14
		NJSR				_native_sub039
		SJMPS				byte_6AB68
byte_6AB88:
		SPR_IDX_SELECT		_spr_lib1_15
		NJSR				_native_sub03B
		SJMPS				byte_6AB68
byte_6AB90:
		SPR_IDX_SELECT		_spr_lib1_13
		NJSR				_native_sub03A
		SJMPS				byte_6AB68

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_6AB98:
		SJSRS				_script_sub_6ABA9
		NJSR				_native_sub03E
		SBCSS				byte_6ABA6
		LOOPA				$08,_script_sub_6AB98
		SRET
byte_6ABA6:
		BREAK				byte_6AB55

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_6ABA9:
		NJSR				_native_obj_linked_idxCs_follow
		OBJ_X_POS_MOVE		$06
		SYNC
		SRET

; =============== S U B R O U T I N E =======================================
_native_sub039:
		LDA		#$30
		BNE		_native_sub03B_ex

; =============== S U B R O U T I N E =======================================
_native_sub03A:
		LDA		#$20
		BNE		_native_sub03B_ex

; =============== S U B R O U T I N E =======================================
_native_sub03B:
		LDA		#$10

; =============== S U B R O U T I N E =======================================
_native_sub03B_ex:
		PHA
		JSR		_native_get_link_obj_idx_from_idxCs
		PLA
		STA		_obj_x_deltas,Y
		RTS

; =============== S U B R O U T I N E =======================================
_native_sub03C:
		LDY		_scr_idxAs,X
		LDA		_pads,Y
		AND		#$C0
		BEQ		loc_6ABD5
		SEC
		AND		#$80
		BNE		loc_6ABD5
		CLC
		LDA		#$FF
loc_6ABD5:
		JMP		_scr_flags_update

; =============== S U B R O U T I N E =======================================
_native_sub03D:
		LDY		#$01
loc_6ABDA:
		LDA		_obj_flips,Y
		AND		#_OBJ_FLIPS04
		BNE		loc_6AC1F
		LDA		_players_vars0D,Y
		BNE		loc_6AC1F
		LDA		_scr_idxBs,Y
		AND		#$40
		BNE		loc_6AC1F
		LDA		_players_states,Y
		CMP		#$05
		BNE		loc_6AC1F
		LDA		_players_states,Y
		CMP		#$13
		BCS		loc_6AC1F
		JSR		_native_sub03E_A
		BCS		loc_6AC1F
		LDA		_obj_x_lo_poss,X
		STA		_obj_x_lo_poss,Y
		LDA		_obj_x_hi_poss,X
		STA		_obj_x_hi_poss,Y
		LDA		_obj_spr_libs,Y
		STA		_obj_spr_libs,X
		TYA
		STA		_scr_idxAs,X
		LDA		#$13
		STA		_players_states,Y
		SEC
		JMP		_scr_flags_update
loc_6AC1F:
		DEY
		BPL		loc_6ABDA
		CLC
		JMP		_scr_flags_update

; =============== S U B R O U T I N E =======================================
_native_sub03E:
		LDY		_scr_idxAs,X
		LDA		_players_states,Y
		CMP		#$13
		BNE		loc_6AC3F
		JSR		_native_sub03E_A
		BCC		loc_6AC40
		LDA		#$05
		STA		_players_states,Y
		LDA		#$00
		STA		_players_vars0A,Y
loc_6AC3F:
		SEC
loc_6AC40:
		JMP		_scr_flags_update

; =============== S U B R O U T I N E =======================================
_native_sub03E_A:
		LDA		_obj_y_lo_poss,X
		CMP		_obj_y_lo_poss,Y
		BNE		loc_6AC74
		LDA		_obj_y_hi_poss,X
		CMP		_obj_y_hi_poss,Y
		BNE		loc_6AC74
		SEC
		LDA		_obj_x_lo_poss,X
		SBC		_obj_x_lo_poss,Y
		STA		_tmp_ptr0
		LDA		_obj_x_hi_poss,X
		SBC		_obj_x_hi_poss,Y
		BEQ		loc_6AC6F
		CMP		#$FF
		BNE		loc_6AC74
		SEC
		LDA		#$00
		SBC		_tmp_ptr0
		STA		_tmp_ptr0
loc_6AC6F:
		LDA		_tmp_ptr0
		CMP		#$04
		RTS
loc_6AC74:
		SEC
		RTS

; =============== O B J E C T   S C R I P T =================================
_obj_scr13_cave_rock:
		NJSR				_native_obj_type_change_bullet
		NJSR				_native_idxBs_20_set
		OBJ_HP_SET			$01
		OBJ_DAMAGE_SET		_OBJ_DMG_KILL
		OBJ_SIZE_SET		$09,$12
		SPR_LIB_SELECT		_spr_lib5
		SPR_IDX_SELECT		_spr_lib5_38
		SJSR				_script_sub_obj_show_wait_for_idxCs_80_set
byte_6AC8A:
		NJSR_SYNC			_native_obj_x_range30_test_from_byte_AB
		SBCSS				byte_6AC8A
		OBJ_Y_DELTA_SET		$18
		APU_LOAD			_apu_mus71
		SJMP				_script_sub_y_parabolic_delta_infinite_anim_sync

; =============== O B J E C T   S C R I P T =================================
_obj_scr04_cave_pendulum:
		SPR_LIB_SELECT		_spr_lib5
		SPR_IDX_SELECT		_spr_lib5_45
		OBJ_SHOW
		SRUN				_OBJ_TYPE_EBULLET,_script142
		NJSR				_native_obj_to_obj_idxCs_link
byte_6ACA3:
		APU_LOAD			_apu_mus5E
		SPR_IDX_SELECT		_spr_lib5_45
		SUSPEND				$08
		SPR_IDX_SELECT		_spr_lib5_44
		SUSPEND				$09
		SPR_IDX_SELECT		_spr_lib5_43
		SUSPEND				$0B
		SPR_IDX_SELECT		_spr_lib5_42
		SUSPEND				$0E
		SPR_IDX_SELECT		_spr_lib5_43
		SUSPEND				$0B
		SPR_IDX_SELECT		_spr_lib5_44
		SUSPEND				$09
		HFLIP_TOGGLE
		SJMPS				byte_6ACA3

; =============== S C R I P T ===============================================
_script142:
		NJSR				_native_obj_idxCs_clear_low_nibble
		OBJ_SIZE_SET		$06,$0C
		OBJ_HP_SET			$01
		OBJ_DAMAGE_SET		_OBJ_DMG_KILL
		SPR_LIB_SELECT		_spr_lib5
		SPR_IDX_SELECT		_spr_lib5_41
		OBJ_SHOW
byte_6ACD0:
		NJSR_SYNC			_native_sub03F
		SJMPS				byte_6ACD0

; =============== S U B R O U T I N E =======================================
_native_sub03F:
		JSR		_native_get_link_obj_idx_from_idxCs
		SEC
		LDA		_obj_spr_idxs,Y
		SBC		#$42
		TAX
		LDA		byte_6AD24,X
		STA		_tmp_ptr0
		LDA		byte_6AD28,X
		LDX		_scr_idx
		CLC
		ADC		_obj_y_lo_poss,Y
		STA		_obj_y_lo_poss,X
		LDA		_obj_y_hi_poss,Y
		ADC		#$00
		STA		_obj_y_hi_poss,X
		LDA		_obj_flips,Y
		AND		#_OBJ_HFLIP
		BEQ		loc_6AD12
		CLC
		LDA		_obj_x_lo_poss,Y
		ADC		_tmp_ptr0
		STA		_obj_x_lo_poss,X
		LDA		_obj_x_hi_poss,Y
		ADC		#$00
		STA		_obj_x_hi_poss,X
		RTS
loc_6AD12:
		SEC
		LDA		_obj_x_lo_poss,Y
		SBC		_tmp_ptr0
		STA		_obj_x_lo_poss,X
		LDA		_obj_x_hi_poss,Y
		SBC		#$00
		STA		_obj_x_hi_poss,X
		RTS
byte_6AD24:
		.BYTE	$25,$20,$16,$00
byte_6AD28:
		.BYTE	$27,$2C,$34,$39

; =============== O B J E C T   S C R I P T =================================
_obj_scr16_floor_switch:
		NJSR				_native_idxBs_20_set
		OBJ_HP_SET			$01
		OBJ_SIZE_SET		$05,$08
		SPR_LIB_SELECT		_spr_lib5
		OBJ_SHOW
		NJSR				_native_sub040
		SBEQS				byte_6AD4F
		SJMPS				byte_6AD5C
byte_6AD40:
		NJSR_SYNC			_native_sub041
		SBCCS				byte_6AD40
		NJSR				_native_sub040
		SBNES				byte_6AD4F
		SJMPS				byte_6AD5C
byte_6AD4F:
		SPR_IDX_SELECT		_spr_lib5_2B
		STORE				$0C,_pal_anim_mode_idx
		STORE				$04,byte_7F
		SJMPS				byte_6AD40
byte_6AD5C:
		SPR_IDX_SELECT		_spr_lib5_2C
		STORE				$0E,_pal_anim_mode_idx
		STORE				$05,byte_7F
		SJMPS				byte_6AD40

; =============== S U B R O U T I N E =======================================
_native_sub040:
		LDA		byte_7F
		CMP		#$04
		JMP		_scr_flags_update

; =============== S U B R O U T I N E =======================================
_native_sub041:
		LDY		#$0B
loc_6AD72:
		LDA		_scr_params,Y
		AND		#_OBJ_TYPE_MASK
		CMP		#_OBJ_TYPE_PBULLET
		BNE		loc_6AD8C
		LDA		_obj_spr_libs,Y
		CMP		#_spr_lib3_idx
		BNE		loc_6AD8C
		LDA		_scr_idxBs,Y
		BMI		loc_6AD8C
		JSR		_obj_to_obj_collision_test
		BCS		loc_6AD92
loc_6AD8C:
		DEY
		BPL		loc_6AD72
		JMP		_scr_flags_flush_clc
loc_6AD92:
		LDA		_obj_damages,Y
		CMP		#_OBJ_DMG_STUN
		BEQ		loc_6AD9E
		LDA		#$00
		STA		_obj_hps,Y
loc_6AD9E:
		JMP		_scr_flags_flush_sec

; =============== O B J E C T   S C R I P T =================================
_obj_scr14_press_hammer:
		NJSR				_native_idxBs_20_set
		OBJ_X_POS_MOVE		$08
		OBJ_FLIPS_SET		_OBJ_UNDER_BG
		SPR_LIB_SELECT		_spr_lib5
		SPR_IDX_SELECT		_spr_lib5_04
		OBJ_HP_SET			$01
		OBJ_SHOW
		OBJ_SIZE_SET		$10,$0F
		SJSR				_script_sub_obj_show_wait_for_idxCs_80_set
byte_6ADB5:
		OBJ_Y_DELTA_SET		$F0
byte_6ADB7:
		SJSRS				_script_sub_6ADDD
		LOOPA				$16,byte_6ADB7
byte_6ADBE:
		NJSR_SYNC			_obj_vert_animate
		LOOPA				$0A,byte_6ADBE
		SUSPEND				$78
		OBJ_Y_DELTA_SET		$40
		NJSR_SYNC			_obj_vert_animate
		NJSR_SYNC			_obj_vert_animate
byte_6ADCF:
		SJSRS				_script_sub_6ADDD
		LOOPA				$06,byte_6ADCF
		APU_LOAD			_apu_mus51
		SUSPEND				$78
		SJMPS				byte_6ADB5

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_6ADDD:
		SYNC
		NJSR				_obj_vert_animate
		NJSR				_native_obj_x_range_width_test_from_byte_AB
		SBCSS				byte_6ADEA
		NJSR				_native_sub042
byte_6ADEA:
		SRET

; =============== S U B R O U T I N E =======================================
_native_sub042:
		LDY		byte_AB
		LDA		_obj_flips,Y
		AND		#_OBJ_FLIPS04
		BNE		locret_6ADF7
		JMP		_player_kill
locret_6ADF7:
		RTS

; =============== O B J E C T   S C R I P T =================================
_obj_scr15_floor_doors:
		NJSR				_native_idxBs_20_set
		SPR_LIB_SELECT		_spr_lib5
		OBJ_HP_SET			$01
		OBJ_SHOW
byte_6AE00:
		SPR_IDX_SELECT		_spr_lib5_2E
		OBJ_SIZE_SET		$10,$0F
byte_6AE05:
		NJSR_SYNC			_native_obj_to_obj_jump_up_test
		SBCCS				byte_6AE05
		SPR_IDX_SELECT		_spr_lib5_39
		SUSPEND				$78
		OBJ_SIZE_SET		$00,$00
		SPR_IDX_SELECT		_spr_lib5_22
		SUSPEND				$08
		SPR_IDX_SELECT		_spr_lib5_23
		SUSPEND				$1E
		SPR_IDX_SELECT		_spr_lib5_22
		SUSPEND				$04
		SPR_IDX_SELECT		_spr_lib5_39
		SUSPEND				$04
		SJMPS				byte_6AE00

; =============== O B J E C T   S C R I P T =================================
_obj_scr3B_ceiling_lazer:
		OBJ_X_POS_MOVE		$08
		SPR_LIB_SELECT		_spr_lib5
		OBJ_SIZE_SET		$02,$30
byte_6AE2C:
		OBJ_SHOW
byte_6AE2D:
		APU_LOAD			_apu_mus53
		SPR_IDX_SELECT		_spr_lib5_29
		SJSRS				_script_sub_6AE46
		SPR_IDX_SELECT		_spr_lib5_2A
		SJSRS				_script_sub_6AE46
		LOOPA				$1E,byte_6AE2D
		OBJ_HIDE
		NJSR				_scr_flips_04_set
		SUSPEND				$78
		SJMPS				byte_6AE2C

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_6AE46:
		OBJ_HP_SET			$01
		OBJ_DAMAGE_SET		_OBJ_DMG_KILL
		NJSR_SYNC			_scr_flips_04_clear
		LOOPB				$02,_script_sub_6AE46
		SRET

; =============== O B J E C T   S C R I P T =================================
_obj_scr17_ceiling_magnet:
		NJSR				_native_idxBs_20_set
		SPR_LIB_SELECT		_spr_lib5
		SPR_IDX_SELECT		_spr_lib5_2D
		OBJ_SIZE_SET		$08,$10
		SJSR				_script_sub_obj_show_wait_for_idxCs_80_set
byte_6AE5F:
		NJSR_SYNC			_native_ceiling_magnet_object_search
		SJMPS				byte_6AE5F

; =============== S U B R O U T I N E =======================================
_native_ceiling_magnet_object_search:
		LDY		#$0B
loc_6AE67:
		LDA		_scr_params,Y
		AND		#_OBJ_TYPE_MASK
		BEQ		loc_6AEC9
		LDA		_obj_spr_libs,Y
		CMP		#_spr_lib4_idx
		BNE		loc_6AEC9
		LDA		_scr_destr_hi_pcs,Y
		BEQ		locret_6AECC
		STY		byte_96
		LDX		byte_96
		JSR		_far_players_animB_sub0129_sub16_E
		LDX		_scr_idx
		LDY		byte_96
		BCS		locret_6AECC
		SEC
		LDA		_obj_y_lo_poss,Y
		SBC		_obj_heights,Y
		CMP		_obj_y_lo_poss,X
		BCC		locret_6AECC
		SEC
		LDA		_obj_x_lo_poss,X
		SBC		_obj_x_lo_poss,Y
		STA		_tmp_ptr0
		LDA		_obj_x_hi_poss,X
		SBC		_obj_x_hi_poss,Y
		BEQ		loc_6AEB1
		CMP		#$FF
		BNE		locret_6AECC
		CLC
		LDA		_tmp_ptr0
		ADC		#$0C
		BCC		locret_6AECC
		BCS		loc_6AEB7
loc_6AEB1:
		LDA		_tmp_ptr0
		CMP		#$0C
		BCS		locret_6AECC
loc_6AEB7:
		LDA		_scr_destr_hi_pcs,Y
		STA		_scr_hi_pcs,Y
		LDA		_scr_destr_lo_pcs,Y
		STA		_scr_lo_pcs,Y
		LDA		#$00
		STA		_scr_destr_hi_pcs,Y
		RTS
loc_6AEC9:
		DEY
		BPL		loc_6AE67
locret_6AECC:
		RTS

; =============== O B J E C T   S C R I P T =================================
_obj_scr18_ceiling_cannon:
		NJSR				_native_idxBs_20_set
		OBJ_HP_SET			$01
		SPR_LIB_SELECT		_spr_lib5
		SPR_IDX_SELECT		_spr_lib5_31
		SJSR				_script_sub_obj_show_wait_for_idxCs_80_set
		OBJ_X_DELTA_SET		$F0
byte_6AEDB:
		SPR_IDX_SELECT		_spr_lib5_30
		SUSPEND				$08
		SPR_IDX_SELECT		_spr_lib5_2F
		SUSPEND				$08
byte_6AEE3:
		NJSR				_native_throwable_obj_num_01_cmp
		SBCSS				byte_6AEED
		SRUN				_OBJ_TYPE_EBULLET,_obj_scr_ceiling_cannon_ball_left
byte_6AEED:
		SJSR				_script_animate32
		NJSR				_j_native_complement_x_deltas
		NJSR				_native_sub16F
		SBCSS				byte_6AEE3
		SPR_IDX_SELECT		_spr_lib5_30
		SUSPEND				$08
		SPR_IDX_SELECT		_spr_lib5_31
		SUSPEND				$08
byte_6AF01:
		NJSR				_native_throwable_obj_num_01_cmp
		SBCSS				byte_6AF0B
		SRUN				_OBJ_TYPE_EBULLET,_obj_scr_ceiling_cannon_ball_right
byte_6AF0B:
		SJSR				_script_animate32
		NJSR				_j_native_complement_x_deltas
		NJSR				_native_sub16F
		SBCCS				byte_6AF01
		SJMPS				byte_6AEDB

; =============== S C R I P T ===============================================
_obj_scr_ceiling_cannon_ball_left:
		OBJ_X_POS_MOVE		$EE
		OBJ_X_DELTA_SET		$D8
		SJMPS				_obj_scr_ceiling_cannon_ball

; =============== S C R I P T ===============================================
_obj_scr_ceiling_cannon_ball_right:
		OBJ_X_POS_MOVE		$12
		OBJ_X_DELTA_SET		$28

; !FALLTHROUGH!

; =============== S C R I P T   R O U T I N E ===============================
_obj_scr_ceiling_cannon_ball:
		OBJ_GRABABLE
		NJSR				_native_obj_idxCs_80_set
		OBJ_Y_POS_MOVE		$24
		OBJ_Y_DELTA_SET		$28
		OBJ_SIZE_SET		$07,$0E
		SPR_LIB_SELECT		_spr_lib5
		SPR_IDX_SELECT		_spr_lib5_32
		OBJ_SHOW
		OBJ_HP_SET			$FF
		OBJ_DAMAGE_SET		_OBJ_DMG_KILL
byte_6AF39:
		SYNC
		NJSR				_native_get_obj_y_delta
		SBPLS				byte_6AF4C
		NJSR				_obj_vert_animate
		NJSR				_native_obj_to_tile_collision_test_up
		SBCCS				byte_6AF52
		SJMPS				byte_6AF57
byte_6AF4C:
		NJSR				_native_sub10B
		SBCCS				byte_6AF57
byte_6AF52:
		NJSR				_native_complement_y_deltas
		APU_LOAD			_apu_mus54
byte_6AF57:
		NJSR				_obj_move_hor_animate
		NJSR				_native_obj_to_tile_collision_test_hor
		SBCSS				byte_6AF39
		NJSR				_j_native_complement_x_deltas
		APU_LOAD			_apu_mus54
		SJMPS				byte_6AF39

; =============== S C R I P T ===============================================
_script_fade_out:
		STORE				$00,_pal_anim_mode_idx
		PAL_FADE_OUT		$04,$FF
		SUSPEND				$14
		STORE				$40,_stage_flags
		SJMP				_script_idle

; =============== S C R I P T   R O U T I N E ===============================
_script_30_sec_timer_init:
		OBJ_X_POS_SET		$70,$00
		STORE				$1E,_timer_seconds_cnt
		STORE				$00,_tmp_bonus_games_scores
		STORE				$00,_tmp_bonus_games_scores+1
		SPR_LIB_SELECT		_spr_lib0
		SPR_IDX_SELECT		_spr_lib0_10
		SRET

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_timer_start:
		APU_LOAD			_apu_mus3A
		NJSR				_native_sub021
		STORE				$3B,_timer_frames_cnt
		SRET

; =============== S C R I P T   R O U T I N E ===============================
byte_6AF96:
		STORE				$FF,_timer_frames_cnt
byte_6AF9A:
		NJSR_SYNC			_native_obj_timer_spr_insert_test
		LOOPA				$F0,byte_6AF9A

; !FALLTHROUGH!

; =============== S C R I P T   R O U T I N E ===============================
_j_script_sub_stage_complete_flag_set:
		SJMP				_script_sub_stage_complete_flag_set

; =============== S U B R O U T I N E =======================================
_native_obj_timer_spr_insert_test:
		LDA		#<[_num_char_table1]
		STA		_tmp_ptr42
		LDA		#>[_num_char_table1]
		STA		_tmp_ptr42+1
		LDX		#$00
		LDY		#$00
		LDA		_timer_seconds_cnt
		JSR		_format_num99
		LDA		#<[_obj_spr_lib_insert]
		LDY		#>[_obj_spr_lib_insert]
		JSR		_farcall
		LDA		_timer_seconds_cnt
		JMP		_scr_flags_update

; =============== S C R I P T   R O U T I N E ===============================
_obj_scr_game_result_display:
		NJSR_SYNC			_native_obj_timer_spr_insert_test
		LOOPA				$3C,_obj_scr_game_result_display
		CHR_SELECT			$01,$0B
		NJSR_SYNC			_native_sub045
		SPR_LIB_SELECT		_spr_lib5
		SPR_IDX_SELECT		_spr_lib5_28
		OBJ_SHOW
		OBJ_X_POS_SET		$80,$00
		OBJ_Y_POS_SET		$68,$00
		NJSR				_native_get_bonus_game_winner
		SUSPEND				$B4
		NJSR				_native_sub047
		SJMPS				_j_script_sub_stage_complete_flag_set

; =============== S U B R O U T I N E =======================================
_native_sub045:
		LDY		#$04
		LDA		#_OBJ_MODE_HIDE|_OBJ_TYPE_DISABLED
loc_6AFE8:
		STA		_scr_params,Y
		INY
		CPY		#$0C
		BCC		loc_6AFE8
		LDY		#$01
loc_6AFF2:
		LDA		_scr_idxBs,Y
		AND		#$40
		BEQ		loc_6B00A
		LDA		_scr_idxBs,Y
		AND		#$0F
		CMP		#$02
		BCC		loc_6B00A
		LDA		_scr_idxBs,Y
		AND		#$BF
		STA		_scr_idxBs,Y
loc_6B00A:
		DEY
		BPL		loc_6AFF2
		RTS

; =============== S U B R O U T I N E =======================================
_native_get_bonus_game_winner:
		LDA		_tmp_bonus_games_scores
		CMP		_tmp_bonus_games_scores+1
		BEQ		locret_6B022
		LDY		#$00
		BCS		loc_6B019
		INY
loc_6B019:
		CLC
		LDA		_obj_spr_libs,Y
		ADC		#[_spr_lib0_26_idx-1]
		STA		_obj_spr_idxs,X
locret_6B022:
		RTS

; =============== S U B R O U T I N E =======================================
_native_sub047:
		LDA		_players_lives
		STA		_tmp_array400
		LDA		_players_lives+1
		STA		_tmp_array400+1
		LDA		_tmp_bonus_games_scores
		CMP		_tmp_bonus_games_scores+1
		BEQ		locret_6B03C
		LDX		#$00
		BCC		loc_6B038
		INX
loc_6B038:
		LDA		#$00
		STA		_players_lives,X
locret_6B03C:
		RTS

; =============== O B J E C T   S C R I P T =================================
_obj_scr00_lives_bonus:
		NJSR				_native_box_bonus_3prizes_shuffle	; random shuffle the boxes, you couldn't guess it!
		SRUN				_OBJ_TYPE_ENEMY,_lives_bonus_obj_scr_2p_star	; add objects, three bonus travelers
		SRUN				_OBJ_TYPE_ENEMY,_lives_bonus_obj_scr_1p_star
		SRUN				_OBJ_TYPE_ENEMY,_lives_bonus_obj_scr_no_star
		SRUN				_OBJ_TYPE_SOLID,_lives_bonus_obj_scr_player1_red_ball	; up to two balls for every live player
		SRUN				_OBJ_TYPE_SOLID,_lives_bonus_obj_scr_player2_red_ball
		SJSR				_script_30_sec_timer_init
		STORE				$0A,_timer_seconds_cnt				; reset timers to 10 second
		OBJ_Y_POS_SET		$38,$00
byte_6B05E:
		NJSR_SYNC			_native_obj_timer_spr_insert_test	; delay for 1 second before start
		LOOPA				$3C,byte_6B05E
		SJSR				_script_sub_timer_start
byte_6B068:
		NJSR				_native_throwable_obj_num_00_cmp	; test if all red ball are thrown
		SBEQS				byte_6B074
		NJSR_SYNC			_native_obj_timer_spr_insert_test	; or else continue the game
		SBNES				byte_6B068
byte_6B074:
		NJSR				_native_lvl_intro_cutscene_start	; init and set the cutscene handler
		SJMP				_script_fade_out					; exit with fade out

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_lives_bonus_floater_init:
		SRUN				_OBJ_TYPE_AUTO,_obj_scr_lives_bonus_floater
		NJSR				_native_obj_to_obj_idxCs_link
		NJSR				_native_obj_idxCs_clear_low_nibble
		OBJ_HP_SET			$01
		OBJ_SIZE_SET		$08,$10
		NJSR				_native_get_rand_flags
		SBPLS				byte_6B095
		OBJ_X_POS_SET		$08,$01
		SJMPS				byte_6B09B
byte_6B095:
		OBJ_X_POS_SET		$F8,$FF
		NJSR				_j_native_complement_x_deltas
byte_6B09B:
		SRET

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_lives_bonus_floater_anim:
		SJSR				_script_animate16				; every 16 frames
		NJSR				_native_complement_y_deltas		; do up-down floating anim
		SRET

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_lives_bonus_floater_bounce:
		SUSPEND				$1E					; wait before reappear, then
		NJSR_SYNC			_j_native_complement_x_deltas	; invert x delta
		SRET

; =============== S U B R O U T I N E =======================================
_native_give_players_2_lives:
		JSR		_native_give_players_1_life

; !FALLTHROUGH!

; =============== S U B R O U T I N E =======================================
_native_give_players_1_life:
		LDX		_scr_idx
		JSR		_native_get_idxBs_low_nibble_from_idxAs
		JMP		_native_inc_players_lives

; =============== S C R I P T ===============================================
_lives_bonus_obj_scr_2p_star:
		SPR_LIB_SELECT		_spr_lib5
		SPR_IDX_SELECT		_spr_lib5_1E
		OBJ_SHOW
		OBJ_Y_POS_MOVE		$40
		OBJ_X_DELTA_SET		$BC
		OBJ_Y_DELTA_SET		$F8
		DESTR_PC_SET		_lives_bonus_obj_scr_2p_star_destr
		SJSRS				_script_sub_lives_bonus_floater_init
byte_6B0C5:
		SJSRS				_script_sub_lives_bonus_floater_anim
		LOOPB				$04,byte_6B0C5
		SJSRS				_script_sub_lives_bonus_floater_bounce
		SJMPS				byte_6B0C5

; =============== S C R I P T ===============================================
_lives_bonus_obj_scr_1p_star:
		SPR_LIB_SELECT		_spr_lib6
		SPR_IDX_SELECT		_spr_lib6_01
		OBJ_SHOW
		OBJ_Y_POS_MOVE		$58
		OBJ_X_DELTA_SET		$D2
		OBJ_Y_DELTA_SET		$F8
		DESTR_PC_SET		_lives_bonus_obj_scr_1p_star_destr
		SJSRS				_script_sub_lives_bonus_floater_init
byte_6B0E3:
		SJSRS				_script_sub_lives_bonus_floater_anim
		LOOPB				$06,byte_6B0E3
		SJSRS				_script_sub_lives_bonus_floater_bounce
		SJMPS				byte_6B0E3

; =============== S C R I P T ===============================================
_lives_bonus_obj_scr_no_star:
		OBJ_Y_POS_MOVE		$7F
		OBJ_X_DELTA_SET		$E4
		OBJ_Y_DELTA_SET		$F0
		DESTR_PC_SET		_lives_bonus_obj_scr_no_star_destr
		SJSRS				_script_sub_lives_bonus_floater_init
byte_6B0FC:
		SJSRS				_script_sub_lives_bonus_floater_anim
		LOOPB				$0A,byte_6B0FC
		SJSRS				_script_sub_lives_bonus_floater_bounce
		SJMPS				byte_6B0FC

; =============== S C R I P T   R O U T I N E ===============================
; 2P bonus floater object
;
_lives_bonus_obj_scr_2p_star_destr:
		NJSR				_native_obj_disable_from_idxCs_40_flag
		NJSR				_native_give_players_2_lives
		SPR_LIB_SELECT		_spr_lib5
		SPR_IDX_SELECT		_spr_lib5_1F
		SJMP				_script_sub_prize_text_float_animate_with_se

; =============== S C R I P T   R O U T I N E ===============================
; 1P bonus floater object
;
_lives_bonus_obj_scr_1p_star_destr:
		NJSR				_native_obj_disable_from_idxCs_40_flag
		NJSR				_native_give_players_1_life
		SJMP				_script_sub_1up_text_float_up

; =============== S C R I P T   R O U T I N E ===============================
; no bonus bloater object
;
_lives_bonus_obj_scr_no_star_destr:
		NJSR				_native_obj_disable_from_idxCs_40_flag
		KILL

; =============== S C R I P T ===============================================
_obj_scr_lives_bonus_floater:
		SPR_LIB_SELECT		_spr_lib5
		OBJ_SHOW
byte_6B126:
		SPR_IDX_SELECT		_spr_lib5_1D
		SJSRS				_script_sub_6B13D
		SPR_IDX_SELECT		_spr_lib5_0F
		SJSRS				_script_sub_6B13D
		SPR_IDX_SELECT		_spr_lib5_10
		SJSRS				_script_sub_6B13D
		SPR_IDX_SELECT		_spr_lib5_11
		SJSRS				_script_sub_6B13D
		SJMPS				byte_6B126

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_6B13D:
		NJSR_SYNC			_native_lives_bonus_floater_link_follow
		LOOPB				$06,_script_sub_6B13D
		SRET

; =============== S U B R O U T I N E =======================================
_native_lives_bonus_floater_link_follow:
		JSR		_native_obj_linked_idxCs_follow ; HFLIP_SET
		CLC
		LDA		_obj_y_lo_poss,Y
		ADC		#$08
		STA		_obj_y_lo_poss,X
		RTS

; =============== S U B R O U T I N E =======================================
_native_get_player1_lives:
		LDA		_players_lives
		JMP		_scr_flags_update

; =============== S U B R O U T I N E =======================================
_native_get_player2_lives:
		LDA		_players_lives+1
		JMP		_scr_flags_update

; =============== S C R I P T ===============================================
_lives_bonus_obj_scr_player1_red_ball:
		NJSR				_native_get_player1_lives
		SBEQS				_script_j_kill
		OBJ_X_POS_SET		$10,$00
		SJMPS				_lives_bonus_obj_scr_red_ball_common

; =============== S C R I P T ===============================================
_lives_bonus_obj_scr_player2_red_ball:
		NJSR				_native_get_player2_lives
		SBEQS				_script_j_kill
		OBJ_X_POS_SET		$F0,$00

; !FALLTHROUGH!

; =============== S C R I P T ===============================================
_lives_bonus_obj_scr_red_ball_common:
		OBJ_GRABABLE
		DESTR_PC_SET		_obj_lives_bonus_red_ball_destr
		OBJ_Y_POS_SET		$C0,$00				; lives bonus ball is a special, it's
		OBJ_SIZE_SET		$06,$10				; pickable and throwable object
		SPR_LIB_SELECT		_spr_lib5
		SPR_IDX_SELECT		_spr_lib5_1B
		OBJ_SHOW
		OBJ_HP_SET			$01					; so we need to wait when it's picked up
		SJSR				_script_obj_wait_for_pickup

; !FALLTHROUGH!

; =============== S C R I P T ===============================================
_obj_lives_bonus_red_ball_destr:
		SJSR				_script_obj_wait_for_throw	; then wait it trowed
		OBJ_Y_DELTA_SET		$C0					; balls are moves directly up without bouncing
		OBJ_HP_SET			$01					; upon hittihng objects
		OBJ_DAMAGE_SET		_OBJ_DMG_KILL		; unless they fly out of the screen
		SJMP				_script_sub_infinite_anim_sync

; =============== S C R I P T ===============================================
_script_j_kill:
		KILL

; =============== O B J E C T   S C R I P T =================================
_obj_scr02_coins_game:
		NJSR				_native_coins_bonus_obstacle_init	; draw invisible obstacles
		OBJ_Y_POS_MOVE		$40
byte_6B197:
		SRUN				_OBJ_TYPE_ENEMY,_obs_scr_coins_game_coin	; insert 4 moving coins
		HFLIP_TOGGLE
		OBJ_Y_POS_MOVE		$30
		LOOPA				$04,byte_6B197
		OBJ_Y_POS_SET		$13,$00								; the main object script controls times
		SJSR				_script_30_sec_timer_init			; as usual
		SJSR				_script_sub_timer_start
byte_6B1AB:
		NJSR_SYNC			_native_obj_timer_spr_insert_test	; wait for timer expired
		SBNES				byte_6B1AB
		SJMP				_obj_scr_game_result_display		; display results

; =============== S U B R O U T I N E =======================================
; when bonus room is drawn, this code filling the particulat parts of the
; screen with obstacle meta-tiles in screen meta buffer. the screen won't be
; redrawn here, so we will see normal room, but can't go farther than
; sides of the screen.
;
_native_coins_bonus_obstacle_init:
		LDY		#$10
loc_6B1B6:
		LDA		#$D0
		STA		_screen_meta_buf+3,Y		; filling invisible objects in front of
		STA		_screen_meta_buf+$C,Y		; each player vertically ($D0)
		CMP		_screen_meta_buf+1,Y		; also filling with $D0 areas above the
		BCC		loc_6B1CE					; balls from both sides as well
		CMP		_screen_meta_buf+$11,Y		;
		BCC		loc_6B1CE
		STA		_screen_meta_buf+1,Y
		STA		_screen_meta_buf+$E,Y
loc_6B1CE:
		TYA
		CLC
		ADC		#$10
		TAY
		CMP		#$F0
		BCC		loc_6B1B6
		LDY		#$0F
loc_6B1D9:
		LDA		#$D0						; finally fill the ceiling, so we couldn't
		STA		_screen_meta_buf,Y			; escape this bonus room
		DEY
		BPL		loc_6B1D9
		RTS

; =============== S C R I P T ===============================================
_obs_scr_coins_game_coin:
		OBJ_SIZE_SET		$08,$12
		SPR_LIB_SELECT		_spr_lib5
		OBJ_SHOW
		OBJ_X_DELTA_SET		$01
		NJSR				_native_obj_hor_delta_toggle
		HFLIP_CLEAR
byte_6B1EE:
		SPR_IDX_SELECT		_spr_lib5_17
		HFLIP_CLEAR
		SJSRS				_script_sub_coins_game_coin_ai
		SPR_IDX_SELECT		_spr_lib5_18
		SJSRS				_script_sub_coins_game_coin_ai
		SPR_IDX_SELECT		_spr_lib5_19
		SJSRS				_script_sub_coins_game_coin_ai
		SPR_IDX_SELECT		_spr_lib5_18
		HFLIP_SET
		SJSRS				_script_sub_coins_game_coin_ai
		SJMPS				byte_6B1EE

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_coins_game_coin_ai:
		SYNC
		NJSR				_native_coins_game_coin_goal_test
		SBEQS				byte_6B21A
		NJSR				_obj_move_hor_animate
		NJSR				_native_get_obj_hp
		SBNES				byte_6B21A
		NJSR				_native_coins_game_coin_bounce_test
byte_6B21A:
		LOOPA				$08,_script_sub_coins_game_coin_ai
		SRET

; =============== S U B R O U T I N E =======================================
_native_coins_game_coin_bounce_test:
		JSR		_scr_flips_04_clear
		JSR		_j_native_complement_x_deltas
		INC		_obj_hps,X
		LDA		_obj_x_deltas,X
		BMI		loc_6B238
		LDA		_obj_x_deltas,X
		CMP		#$10
		BEQ		locret_6B237
		INC		_obj_x_deltas,X
locret_6B237:
		RTS
loc_6B238:
		LDA		_obj_x_deltas,X
		CMP		#$F0
		BEQ		locret_6B242
		DEC		_obj_x_deltas,X
locret_6B242:
		RTS

; =============== S U B R O U T I N E =======================================
_native_coins_game_coin_goal_test:
		LDY		_obj_x_lo_poss,X
		LDA		_obj_x_deltas,X
		BEQ		loc_6B266
		BMI		loc_6B255
		CPY		#$C0
		BNE		loc_6B266
		INC		_tmp_bonus_games_scores
		BNE		loc_6B25B
loc_6B255:
		CPY		#$40
		BNE		loc_6B266
		INC		_tmp_bonus_games_scores+1
loc_6B25B:
		JSR		_scr_flips_04_set
		LDA		#$00
		STA		_obj_x_deltas,X
		STA		_obj_hps,X
loc_6B266:
		JMP		_scr_flags_update

; =============== O B J E C T   S C R I P T =================================
_obj_scr_red_ball:
		DESTR_PC_SET		_obj_scr_red_ball				; regular red ball is a throwable carry object
		OBJ_SIZE_SET		$06,$10							; the pickup logic is tile-based
		SPR_LIB_SELECT		_spr_lib5
		SPR_IDX_SELECT		_spr_lib5_1B					; here we only get when carry it
		OBJ_SHOW
		SJSR				_script_obj_wait_for_throw
		NJSR				_native_obj_throw_direction_select
byte_6B27A:
		OBJ_ANIMATE_SYNC									; throw animate, wait it hit someone
		NJSR				_native_get_obj_hp
		SBNES				byte_6B27A						; when hit, do parabolic throw-back animation
		OBJ_X_DELTA_SET		$08
		OBJ_Y_DELTA_SET		$E8
		NJSR				_players_animB_sub67_A
		SJMP				_script_sub_y_parabolic_delta_infinite_anim_sync

; =============== O B J E C T   S C R I P T =================================
_obj_scr03_basket_game:
		SRUN				_OBJ_TYPE_AUTO,_obj_scr_basket_game_basket		; add basket object
		NJSR				_native_basket_game_init
		SJSR				_script_30_sec_timer_init			; common init timer
		STORE				$3C,_timer_seconds_cnt				; but here reset to 60 sec
		OBJ_Y_POS_SET		$18,$00
byte_6B29C:
		NJSR_SYNC			_native_obj_timer_spr_insert_test	; 3 seconds delay, just show timer
		LOOPA				$B4,byte_6B29C
		SRUN				_OBJ_TYPE_BALL,_obj_scr_basket_game_left_ball	; insert balls
		SRUN				_OBJ_TYPE_BALL,_obj_scr_basket_game_right_ball
		SJSR				_script_sub_timer_start			; game start with sound
byte_6B2AE:
		NJSR_SYNC			_native_obj_timer_spr_insert_test	; show timer
		SBNES				byte_6B2AE							; wait untill time expired
		SJMP				_obj_scr_game_result_display		; show results

; =============== S U B R O U T I N E =======================================
_native_basket_game_init:
		LDA		_scr_cur_slot_idx
		STA		byte_E0
		LDY		#$00
loc_6B2BD:
		LDA		#$D0
		STA		_screen_meta_buf,Y
		STA		_screen_meta_buf+$F,Y
		TYA
		CLC
		ADC		#$10
		TAY
		CMP		#$F0
		BCC		loc_6B2BD
		LDY		#$0F
		LDA		#$D0
loc_6B2D2:
		STA		_screen_meta_buf,Y
		DEY
		BPL		loc_6B2D2
		RTS

; =============== S C R I P T ===============================================
_obj_scr_basket_game_basket:
		OBJ_Y_POS_MOVE		$58										; set basket Y position
		SRUN				_OBJ_TYPE_SOLID,_obj_scr_basket_game_left_bouncer	; insert basket left side bouncer
		NJSR				_native_obj_to_obj_idxCs_link
		SRUN				_OBJ_TYPE_SOLID,_obj_scr_basket_game_right_bouncer	; same for right bouncer
		NJSR				_native_obj_to_obj_idxCs_link
		OBJ_SIZE_SET		$04,$04									; the main hot spot in the middle
		OBJ_X_DELTA_SET		$F0										; set default movement delta
		SPR_LIB_SELECT		_spr_lib5										; init sprite
		SPR_IDX_SELECT		_spr_lib5_1C
		OBJ_SHOW												; enable
		SUSPEND				$B4										; wait for 3 seconds as well as timer
byte_6B2F5:
		NJSR				_native_cmp40_obj_x_lo_pos				; now move left-right constantly
		SBCSS				byte_6B30D
		NJSR				_native_cmpC0_obj_x_lo_pos
		SBCCS				byte_6B30D
		NJSR				_native_get_rand_scale3					; sometimes basket may change direction
		SSWITCH				_tmp_ptrE+1								; randomly with 1/3 possibility
		SCASE				byte_6B310
		SCASE				byte_6B310
		SCASE				byte_6B30D
byte_6B30D:
		NJSR				_native_obj_hor_move_reverse			; bounce object hor movement
byte_6B310:
		OBJ_ANIMATE_SYNC
		LOOPA				$26,byte_6B310							; wait for 38 frames
		SJMPS				byte_6B2F5

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_basket_game_bouncer_init:
		OBJ_SIZE_SET		$02,$02				; basket bouncers are invisible objects
		OBJ_HP_SET			$01					; size 2x2 with collision test
		SRET

; =============== S C R I P T ===============================================
_obj_scr_basket_game_left_bouncer:
		SJSRS				_script_sub_basket_game_bouncer_init	; common init
byte_6B321:
		SYNC
		NJSR				_native_obj_linked_idxCs_follow			; sync movement with main basket object
		OBJ_X_POS_MOVE		$F1										; adjust linked positions for left side
		OBJ_Y_POS_MOVE		$F2
		SJMPS				byte_6B321								; loop forever

; =============== S C R I P T ===============================================
_obj_scr_basket_game_right_bouncer:
		SJSRS				_script_sub_basket_game_bouncer_init	; the same for right side
byte_6B32F:
		SYNC
		NJSR				_native_obj_linked_idxCs_follow
		OBJ_X_POS_MOVE		$0F
		OBJ_Y_POS_MOVE		$F2
		SJMPS				byte_6B32F

; =============== S C R I P T ===============================================
_obj_scr_basket_game_left_ball:
		OBJ_X_POS_SET		$18,$00
		SJMPS				_obj_scr_basket_game_ball_common

; =============== S C R I P T ===============================================
_obj_scr_basket_game_right_ball:
		OBJ_X_POS_SET		$E8,$00

; !FALLTHROUGH!

; =============== S C R I P T ===============================================
_obj_scr_basket_game_ball_common:
		DESTR_PC_SET		_obj_scr_basket_game_ball_destr	; collision detect handler here
		OBJ_Y_POS_SET		$40,$00
		OBJ_SIZE_SET		$06,$0D
		SPR_LIB_SELECT		_spr_lib4
		OBJ_SHOW
		SJMPS				_obj_scr_basket_game_ball_test

; =============== S C R I P T ===============================================
_obj_scr_basket_game_ball_loop:
		OBJ_X_DELTA_SET		$00
		NJSR				_native_obj_type_change_solid_no_damage_idxBs_20_clear
byte_6B357:
		SYNC
		NJSR				_native_get_obj_idxBs
		SBMIS				_obj_scr_basket_game_ball_destr
		SJSR				_script_sub_ballistic_throw_anim
		SBCSS				byte_6B357
		SJMPS				_obj_scr_basket_game_ball_test

; =============== S C R I P T ===============================================
_obj_scr_basket_game_ball_destr:
		SJSR				_script_obj_wait_for_throw
		TARGET_DIR_SET		$00
		OBJ_X_DELTA_SET		$08
		OBJ_Y_DELTA_SET		$B0
		NJSR				_native_sub029

; !FALLTHROUGH!

; =============== S C R I P T ===============================================
_obj_scr_basket_game_ball_test:
		NJSR				_native_sub11C
		NJSR				_native_obj_type_change_ball
		NJSR				_native_obj_idxCs_clear_low_nibble
byte_6B37C:
		SJSRS				_script_sub_6B393
		OBJ_Y_DELTA_SET		$E0
		NJSR				_native_cmp50_obj_y_lo_pos
		SBCSS				byte_6B37C
		NJSR				_far_players_animB_sub0129_G
		SBPLS				_obj_scr_basket_game_ball_loop
		SJSRS				_script_sub_6B393
		SJMPS				_obj_scr_basket_game_ball_loop

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_6B393:
		NJSR_SYNC			_native_sub04F
		NJSR				_native_sub100
		OBJ_HP_SET			$01
		OBJ_DAMAGE_SET		_OBJ_DMG_STUN
		SJSR				_script_sub_6A557
		SBCCS				_script_sub_6B393
		SRET

; =============== S U B R O U T I N E =======================================
_native_sub04F:
		LDA		#<[byte_6B3AB]
		LDY		#>[byte_6B3AB]
		JMP		_native_sub023

byte_6B3AB:
		.BYTE	_spr_lib4_05_idx,$00
		.BYTE	_spr_lib4_06_idx,$00
		.BYTE	_spr_lib4_05_idx,$40
		.BYTE	_spr_lib4_06_idx,$C0

; =============== O B J E C T   S C R I P T =================================
_obj_scr01_box_bonus:
		NJSR				_native_box_bonusA
		NJSR				_native_box_bonusB
		NJSR				_native_box_bonus_4prizes_shuffle
byte_6B3BC:
		NJSR				_native_box_bonus_box_obj_insert
		LOOPA				$04,byte_6B3BC
		OBJ_Y_POS_SET		$18,$00
		SJSR				_script_30_sec_timer_init
		STORE				$0A,_timer_seconds_cnt
		SJSRS				_script_sub_6B415
		NJSR				_native_idxBs_10_set
		NJSR				_native_sub051
		SJSRS				_script_sub_6B415
		SJSRS				_script_sub_6B418
		NJSR				_native_idxBs_10_clear
		SJSRS				_script_sub_6B418
		NJSR				_native_box_bonusB
		NJSR				_native_idxBs_10_set
		SJSR				_script_sub_timer_start
byte_6B3EB:
		NJSR				_native_sub056
		SBEQS				byte_6B3FA
		NJSR_SYNC			_native_obj_timer_spr_insert_test
		SBNES				byte_6B3EB
		NJSR				_native_sub057
byte_6B3FA:
		NJSR				_native_sub050
		SJMP				byte_6AF96	; LONG

; =============== S U B R O U T I N E =======================================
_native_sub050:
		LDA		_players_def_max_hps
		STA		_obj_hps
		LDA		_players_def_max_hps+1
		STA		_obj_hps+1
		LDA		_tmp_array400
		STA		_players_lives
		LDA		_tmp_array400+1
		STA		_players_lives+1
		RTS

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_6B415:
		SJSRS				_script_sub_6B418

; !FALLTHROUGH!

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_6B418:
		NJSR_SYNC			_native_obj_timer_spr_insert_test
		LOOPA				$78,_script_sub_6B418
		SRET

; =============== S U B R O U T I N E =======================================
_native_sub051:
		LDA		#$96
		STA		byte_436
		STA		byte_438
		LDA		#$97
		STA		byte_437
		STA		byte_439

; !FALLTHROUGH!

; =============== S U B R O U T I N E =======================================
_native_box_bonusB:
		LDA		#$03
loc_6B432:
		PHA
		TAY
		LDX		byte_436,Y
		LDA		byte_6B446,Y
		LDY		#$3B
		JSR		_far_sys_screen_cur_meta_draw
		PLA
		SEC
		SBC		#$01
		BPL		loc_6B432
		RTS

byte_6B446:
		.BYTE	$03,$06,$09,$0C

; =============== S U B R O U T I N E =======================================
_native_box_bonusA:
		LDY		#$03
		LDA		#$F4
loc_6B44E:
		STA		byte_436,Y
		DEY
		BPL		loc_6B44E
		RTS

; =============== S U B R O U T I N E =======================================
_native_box_bonus_box_obj_insert:
		JSR		_native_get_box_bonus_prize_from_list
		LDY		_tmp_ptrE+1
		LDA		_box_bonus_box_x_pos_list,Y
		STA		_tmp_ptr4
		LDA		#$C0
		STA		_tmp_ptr2
		LDA		#$00
		STA		_tmp_ptr2+1
		STA		_tmp_ptr4+1
		STA		byte_6
		LDY		_scr_loopsA,X
		LDA		_box_bonus_box_prize_list,Y
		PHA
		LDA		_box_bonus_box_obj_script_lib_lo,Y
		STA		_tmp_ptr0
		LDA		_box_bonus_box_obj_script_lib_hi,Y
		STA		_tmp_ptr0+1
		LDY		#_OBJ_TYPE_AUTO
		JSR		_scr_load
		PLA
		STA		_scr_vars19,X
		LDY		_tmp_ptrE+1
		LDA		_box_bonus_box_delay_list,Y
		STA		_scr_delays,X
		LDA		_box_bonus_box_anim_lib,Y
		STA		_scr_destr_lo_pcs,X
		LDA		off_6B4B2,Y
		STA		_scr_destr_hi_pcs,X
		RTS

_box_bonus_box_x_pos_list:
		.BYTE	$38,$68,$98,$C8
_box_bonus_box_delay_list:
		.BYTE	$08,$18,$28,$38
_box_bonus_box_obj_script_lib_lo:
		.BYTE	<[_obj_scr_box_bonus_boxA]
		.BYTE	<[_obj_scr_box_bonus_boxB]
		.BYTE	<[_obj_scr_box_bonus_boxC]
		.BYTE	<[_obj_scr_box_bonus_boxD]
_box_bonus_box_obj_script_lib_hi:
		.BYTE	>[_obj_scr_box_bonus_boxA]
		.BYTE	>[_obj_scr_box_bonus_boxB]
		.BYTE	>[_obj_scr_box_bonus_boxC]
		.BYTE	>[_obj_scr_box_bonus_boxD]
_box_bonus_box_prize_list:
		.BYTE	$F4,$F5,$F6,$F7
_box_bonus_box_anim_lib:
		.BYTE	<[_obj_box_bonusA_amin]
		.BYTE	<[_obj_box_bonusB_amin]
		.BYTE	<[_obj_box_bonusC_amin]
		.BYTE	<[_obj_box_bonusD_amin]
off_6B4B2:
		.BYTE	>[_obj_box_bonusA_amin]
		.BYTE	>[_obj_box_bonusB_amin]
		.BYTE	>[_obj_box_bonusC_amin]
		.BYTE	>[_obj_box_bonusD_amin]
_obj_box_bonusA_amin:
		.BYTE	$21,$11,$11,$21,$14,$31,$43,$33,$34,$12,$34,$11,$13,$32,$32,$11
		.BYTE	$41,$00
_obj_box_bonusB_amin:
		.BYTE	$03,$33,$41,$11,$12,$13,$12,$31,$41,$43,$23,$32,$14,$32,$14,$33
		.BYTE	$33,$00
_obj_box_bonusC_amin:
		.BYTE	$01,$11,$23,$33,$43,$22,$14,$44,$33,$22,$31,$11,$43,$23,$43,$41
		.BYTE	$23,$00
_obj_box_bonusD_amin:
		.BYTE	$42,$23,$33,$41,$23,$44,$33,$13,$22,$14,$12,$43,$21,$43,$24,$11
		.BYTE	$11,$00

; =============== S U B R O U T I N E =======================================
_native_sub054:
		LDY		#$03
		LDA		_obj_x_lo_poss,X
loc_6B503:
		CMP		_box_bonus_box_x_pos_list,Y
		BEQ		loc_6B50C
		DEY
		BPL		loc_6B503
		RTS
loc_6B50C:
		LDA		_scr_vars19,X
		STA		byte_436,Y
		RTS

; =============== S U B R O U T I N E =======================================
_native_sub055:
		LDA		#$00
		STA		_obj_x_deltas,X
		STA		_obj_y_deltas,X
		JSR		_scr_flags_update
		LDA		_scr_destr_hi_pcs,X
		STA		_tmp_ptr0+1
		LDA		_scr_destr_lo_pcs,X
		STA		_tmp_ptr0
		LDA		_scr_vars20,X
		LSR
		TAY
		LDA		(_tmp_ptr0),Y
		BNE		loc_6B536
		LDA		#$FF
		JMP		_scr_flags_update
loc_6B536:
		BCS		loc_6B53C
		LSR
		LSR
		LSR
		LSR
loc_6B53C:
		INC		_scr_vars20,X
		AND		#$07
		JSR		_switch
		.WORD	nullsub5
		.WORD	_native_sub055_sub0
		.WORD	_native_sub055_sub1
		.WORD	_native_sub055_sub2
		.WORD	_native_sub055_sub3

; =============== S U B R O U T I N E =======================================
_native_sub055_sub0:
		LDA		#$20
		BNE		_native_sub055_sub0_ex

; =============== S U B R O U T I N E =======================================
_native_sub055_sub2:
		LDA		#$E0

; =============== S U B R O U T I N E =======================================
_native_sub055_sub0_ex:
		STA		_obj_x_deltas,X
		RTS

; =============== S U B R O U T I N E =======================================
_native_sub055_sub1:
		LDA		#$20
		BNE		_native_sub055_sub1_ex

; =============== S U B R O U T I N E =======================================
_native_sub055_sub3:
		LDA		#$E0

; =============== S U B R O U T I N E =======================================
_native_sub055_sub1_ex:
		STA		_obj_y_deltas,X

; =============== S U B R O U T I N E =======================================
nullsub5:
		RTS

; =============== S U B R O U T I N E =======================================
_native_sub056:
		LDY		#$00
		LDX		#$01
loc_6B566:
		LDA		_players_states,X
		CMP		#$04
		BEQ		loc_6B588
		CMP		#$18
		BEQ		loc_6B588
		LDA		_scr_idxBs,X
		AND		#$40
		BEQ		loc_6B589
		LDA		_scr_idxBs,X
		AND		#$0F
		TAY
		LDA		_obj_spr_libs,Y
		CMP		#_spr_lib3_idx
		BNE		loc_6B589
		LDA		#$04
		STA		_players_states,X
loc_6B588:
		INY
loc_6B589:
		DEX
		BPL		loc_6B566
		CPY		#$02
		JMP		_scr_flags_update

; =============== S U B R O U T I N E =======================================
_native_sub057:
		LDX		#$01
loc_6B593:
		LDA		_players_states,X
		CMP		#$18
		BCS		loc_6B59D
		LDA		#$04
		STA		_players_states,X
loc_6B59D:
		DEX
		BPL		loc_6B593
		RTS

; =============== S C R I P T ===============================================
_obj_scr_box_bonus_boxA:
		SPR_LIB_SELECT		_spr_lib5
		SPR_IDX_SELECT		_spr_lib5_37
		SJMPS				_obj_scr_box_bonus_box_common

; =============== S C R I P T ===============================================
_obj_scr_box_bonus_boxB:
		SPR_LIB_SELECT		_spr_lib6
		SPR_IDX_SELECT		_spr_lib6_01
		SJMPS				_obj_scr_box_bonus_box_common

; =============== S C R I P T ===============================================
_obj_scr_box_bonus_boxC:
		SPR_LIB_SELECT		_spr_lib5
		SPR_IDX_SELECT		_spr_lib5_24
		SJMPS				_obj_scr_box_bonus_box_common

; =============== S C R I P T ===============================================
_obj_scr_box_bonus_boxD:
		SPR_LIB_SELECT		_spr_lib5
		SPR_IDX_SELECT		_spr_lib5_25

; !FALLTHROUGH!

; =============== S C R I P T ===============================================
_obj_scr_box_bonus_box_common:
		OBJ_SHOW
		OBJ_HP_SET			$01
		OBJ_SIZE_SET		$06,$0C
		OBJ_Y_DELTA_SET		$E0
		SJSR				_script_animate10
		SUSPEND				$78
		OBJ_Y_DELTA_SET		$20
		SJSR				_script_animate10
		OBJ_Y_DELTA_SET		$00
		SPR_LIB_SELECT		_spr_lib3
		SPR_IDX_SELECT		_spr_lib3_00
byte_6B5D2:
		NJSR_SYNC			_native_sub058
		SBEQS				byte_6B5D2
byte_6B5D8:
		NJSR				_native_sub055
		SJSR				_script_animate10
		NJSR				_native_sub058
		SBNES				byte_6B5D8
		NJSR				_native_sub054
byte_6B5E7:
		NJSR_SYNC			_native_sub058
		SBEQS				byte_6B5E7
		KILL

; =============== S U B R O U T I N E =======================================
_native_sub058:
		LDY		_scr_idxAs,X
		LDA		_scr_idxBs,Y
		AND		#$10
		JMP		_scr_flags_update

; =============== S C R I P T ===============================================
_obj_scr_box_bonus_prize_continue:
		SPR_LIB_SELECT		_spr_lib5
		SPR_IDX_SELECT		_spr_lib5_37
		OBJ_SHOW
		NJSR				_native_increment_continues
		SJMP				_script_idle

; =============== S C R I P T ===============================================
_obj_scr_box_bonus_prize_1up:
		SPR_LIB_SELECT		_spr_lib6
		SPR_IDX_SELECT		_spr_lib6_01
		OBJ_SHOW
		NJSR				_native_inc_tmp_player_lives
		SRUN				_OBJ_TYPE_AUTO,_script_sub_1up_text_float_up
		SJMP				_script_idle

; =============== S C R I P T ===============================================
_obj_scr_box_bonus_prize_30rrs:
		SPR_LIB_SELECT		_spr_lib5
		SPR_IDX_SELECT		_spr_lib5_24
		OBJ_SHOW
		NJSR				_native_add_players_30_rr_ptss
		SRUN				_OBJ_TYPE_AUTO,_script_sub_30_rr_pts_float_up
		SJMP				_script_idle

; =============== S C R I P T ===============================================
_script_sub_30_rr_pts_float_up:
		SPR_LIB_SELECT		_spr_lib5
		SPR_IDX_SELECT		_spr_lib5_35
		SJMP				_script_sub_prize_text_float_up_animate

; =============== S C R I P T ===============================================
_obj_scr_box_bonus_prize_10rrs:
		SPR_LIB_SELECT		_spr_lib5
		SPR_IDX_SELECT		_spr_lib5_25
		OBJ_SHOW
		NJSR				_native_add_players_10_rr_ptss
		SRUN				_OBJ_TYPE_AUTO,_script_sub_10_rr_pts_float_up
		SJMP				_script_idle

; =============== S C R I P T ===============================================
_script_sub_10_rr_pts_float_up:
		SPR_LIB_SELECT		_spr_lib5
		SPR_IDX_SELECT		_spr_lib5_36
		SJMP				_script_sub_prize_text_float_up_animate

; =============== S U B R O U T I N E =======================================
_native_increment_continues:
		LDA		_continues
		CMP		#$09
		BCS		locret_6B647
		INC		_continues
locret_6B647:
		RTS

; =============== S U B R O U T I N E =======================================
_native_inc_tmp_player_lives:
		LDY		_scr_idxAs,X
		LDA		_tmp_array400,Y
		CMP		#$0A
		BCS		locret_6B658
		CLC
		ADC		#$01
		STA		_tmp_array400,Y
locret_6B658:
		RTS

; =============== S U B R O U T I N E =======================================
_native_add_players_30_rr_ptss:
		LDA		#$1E
		BNE		_native_add_players_rr_ptss

; =============== S U B R O U T I N E =======================================
_native_add_players_10_rr_ptss:
		LDA		#$0A

; !FALLTHROUGH!

; =============== S U B R O U T I N E =======================================
_native_add_players_rr_ptss:
		CLC
		LDY		_scr_idxAs,X
		ADC		_players_rr_ptss,Y
		CMP		#$64
		BCC		loc_6B66C
		LDA		#$63
loc_6B66C:
		STA		_players_rr_ptss,Y
		RTS

; =============== S C R I P T ===============================================
_script_cutscenes_start:
		SSWITCH				_cutscene_idx
		SCASE				_script_cutscene00
		SCASE				_script_cutscene01
		SCASE				_script_cutscene02
		SCASE				_script_cutscene03
		SCASE				_script_cutscene04
		SCASE				_script_cutscene05
		SCASE				_script_cutscene06
		SCASE				_script_cutscene07
		SCASE				_script_cutscene08
		SCASE				_script_cutscene09
		SCASE				_script_cutscene0A
		SCASE				_script_cutscene0B
		SCASE				_script_cutscene0C
		SCASE				_script_cutscene0D
		SCASE				_script_cutscene0E
		SCASE				_script_cutscene0F
		SCASE				_script_cutscene10
		SCASE				_script_cutscene11
		SCASE				_script_cutscene12

; =============== S C R I P T ===============================================
_obj_scr_cutscene_skip_wait:
		SYNC
		PADS_TEST			_PAD0_PRESS,_PAD_START,_obj_scr_cutscene_skip_wait

; !FALLTHROUGH!

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_delayed_ingame_start:
		STORE				$04,_main_sub_idx
		SJMPS				_script_delayed_fade_out

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_delayed_next_cutscene:
		NJSR				_native_cut_idx_inc

; !FALLTHROUGH!

; =============== S C R I P T   R O U T I N E ===============================
_script_delayed_fade_out:
		APU_LOAD			_APU_MUS_FADE_OUT
		SUSPEND				$20
		SJMP				_script_fade_out

; =============== S C R I P T ===============================================
_script_sub_next_cutscene:
		NJSR				_native_cut_idx_inc
		SJMP				_script_fade_out

; =============== S U B R O U T I N E =======================================
_native_cut_idx_inc:
		LDX		_cutscene_idx
		INX
		CPX		#$13
		BCC		loc_6B6BF
		LDX		#$00
loc_6B6BF:
		STX		_cutscene_idx
		RTS

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_idxBs_10_set_clear_wait:
		NJSR				_native_idxBs_10_set
byte_6B6C5:
		NJSR_SYNC			_native_idxBs_10_test
		SBNES				byte_6B6C5
		SRET

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_cut_char_idxBs_10_clear_set_test:
		NJSR_SYNC			_native_cut_char_idxBs_10_clear
byte_6B6CF:
		NJSR_SYNC			_native_cut_char_idxBs_10_test
		SBEQS				byte_6B6CF
		SRET

; =============== S U B R O U T I N E =======================================
_native_cut_store_char_number:
		LDY		_scr_vars19,X
		LDA		_scr_cur_slot_idx
		STA		_tmp_array400,Y
		RTS

; =============== S U B R O U T I N E =======================================
_native_cut_char_idxBs_10_clear:
		LDY		_scr_vars19,X
		LDX		_tmp_array400,Y
		LDA		_scr_idxBs,X
		AND		#$EF
		STA		_scr_idxBs,X
		RTS

; =============== S U B R O U T I N E =======================================
_native_cut_char_idxBs_10_test:
		LDY		_scr_vars19,X
		LDX		_tmp_array400,Y
		LDA		_scr_idxBs,X
		AND		#$10
		JMP		_scr_flags_update

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_wait_for_wnd_msg_is_over:
		NJSR_SYNC			_native_test_if_wnd_msg_is_over
		SBNES				_script_sub_wait_for_wnd_msg_is_over
		SRET

; =============== S U B R O U T I N E =======================================
_native_test_if_wnd_msg_is_over:
		LDA		_wnd_msg_sub_idx
		JMP		_scr_flags_update

; =============== S C R I P T   R O U T I N E ===============================
_script_cut_obj_msg_spr_animate:
		NJSR				_native_cut_obj_spr_anim_update
		NJSR_SYNC			_native_test_if_wnd_msg_is_over
		SBNES				_script_cut_obj_msg_spr_animate
		SRET

; =============== S U B R O U T I N E =======================================
_native_cut_obj_spr_anim_update:
		LDY		_obj_hps,X
		LDA		_cur_wnd_msg_col
		AND		#$02
		BEQ		loc_6B71E
		LDY		_obj_damages,X
loc_6B71E:
		TYA
		STA		_obj_spr_idxs,X
		RTS

; =============== S U B R O U T I N E =======================================
_native_cut_obj_talk_anim_update:
		LDY		_obj_hps,X
		LDA		_cur_wnd_msg_col
		AND		#$02
		BEQ		loc_6B72F
		LDY		_obj_damages,X
loc_6B72F:
		TYA
		STA		_scr_vars19,X
		RTS

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_obj_idxCs_clear_low_nibble_flips_08_set:
		NJSR				_native_obj_idxCs_clear_low_nibble
		OBJ_FLIPS_SET		_OBJ_FLIPS08
		SRET

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_6B73A:
		OBJ_HP_SET			$1B
		OBJ_DAMAGE_SET		$1C
		SJSRS				_script_cut_obj_msg_spr_animate
		SJMPS				_script_sub_idxBs_10_set_clear_wait

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_6B744:
		OBJ_HP_SET			$1F
		OBJ_DAMAGE_SET		$1E
		SJSRS				_script_cut_obj_msg_spr_animate
		SPR_IDX_SELECT		_spr_lib1_1B
		SJMP				_script_sub_idxBs_10_set_clear_wait

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_6B750:
		SJSR				_script_sub_B7547
		SJSR				_script_sub_B7547
		SPR_IDX_SELECT		_spr_lib1_1B
		OBJ_Y_DELTA_SET		$00
		SJMP				_script_sub_idxBs_10_set_clear_wait

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_6B75D:
		SJSRS				_script_sub_6B76F
		NJSR				_players_animB_sub0129_sub0E_A
		SPR_IDX_SELECT		_spr_lib1_0D
		SUSPEND				$78
		NJSR				_native_obj_disable_from_idxCs_40_flag
		SPR_IDX_SELECT		_spr_lib1_1B
		SJMP				_script_sub_idxBs_10_set_clear_wait

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_6B76F:
		OBJ_SIZE_SET		$06,$16
		SRET

; =============== S U B R O U T I N E =======================================
_script_sub_gadget_static_draw:
		NJSR				_native_idxBs_10_set
byte_6B776:
		NJSR				_native_cut_gadget_talk_spr_insert
		NJSR_SYNC			_native_idxBs_10_test
		SBNES				byte_6B776
		SRET

; =============== S U B R O U T I N E =======================================
_script_sub_gadget_talk_draw:
		NJSR				_native_cut_obj_talk_anim_update
		NJSR				_native_cut_gadget_talk_spr_insert
		NJSR_SYNC			_native_test_if_wnd_msg_is_over
		SBNES				_script_sub_gadget_talk_draw
		SRET

; =============== S U B R O U T I N E =======================================
_script_sub_6B78D:
		OBJ_HP_SET			$00
		OBJ_DAMAGE_SET		$03
		SJSRS				_script_sub_gadget_talk_draw
		SJMPS				_script_sub_gadget_static_draw

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_6B797:
		OBJ_HP_SET			$06
		OBJ_DAMAGE_SET		$09
		SJSRS				_script_sub_gadget_talk_draw
		TARGET_DIR_SET		$06
		SJMPS				_script_sub_gadget_static_draw

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_6B7A3:
		SPR_IDX_SELECT		_spr_lib0_29
		SJSR				_script_animate10
		SPR_IDX_SELECT		_spr_lib0_2A
		SJSR				_script_animate10
		SPR_IDX_SELECT		_spr_lib0_2B
		SJSR				_script_animate10
		SPR_IDX_SELECT		_spr_lib0_2A
		SJMP				_script_animate10

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_monterey_static_draw:
		NJSR				_native_idxBs_10_set
byte_6B7BA:
		NJSR				_native_cut_monterey_talk_spr_insert
		NJSR_SYNC			_native_idxBs_10_test
		SBNES				byte_6B7BA
		SRET

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_monterey_talk_draw:
		NJSR				_native_cut_obj_talk_anim_update
		NJSR				_native_cut_monterey_talk_spr_insert
		NJSR_SYNC			_native_test_if_wnd_msg_is_over
		SBNES				_script_sub_monterey_talk_draw
		SRET

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_6B7D1:
		OBJ_HP_SET			$06
		OBJ_DAMAGE_SET		$09
		SJSRS				_script_sub_monterey_talk_draw
		TARGET_DIR_SET		$00
		SJMPS				_script_sub_monterey_static_draw

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_6B7DD:
		SPR_IDX_SELECT		_spr_lib0_23
		SJSR				_script_animate10
		SPR_IDX_SELECT		_spr_lib0_24
		SJSR				_script_animate10
		SPR_IDX_SELECT		_spr_lib0_25
		SJSR				_script_animate10
		SPR_IDX_SELECT		_spr_lib0_24
		SJMP				_script_animate10

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_zipper_hover_animate:
		NJSR				_native_idxBs_10_set
		OBJ_X_DELTA_SET		$00
		OBJ_Y_DELTA_SET		$F8
byte_6B7F8:
		SPR_IDX_SELECT		_spr_lib0_17
		OBJ_ANIMATE_SYNC
		OBJ_ANIMATE_SYNC
		OBJ_ANIMATE_SYNC
		SPR_IDX_SELECT		_spr_lib0_18
		OBJ_ANIMATE_SYNC
		OBJ_ANIMATE_SYNC
		OBJ_ANIMATE_SYNC
		NJSR				_native_complement_y_deltas
		NJSR				_native_idxBs_10_test
		SBEQS				byte_6B823
		LOOPB				$28,byte_6B7F8
byte_6B80F:
		SPR_IDX_SELECT		_spr_lib0_34
		OBJ_ANIMATE_SYNC
		OBJ_ANIMATE_SYNC
		OBJ_ANIMATE_SYNC
		SPR_IDX_SELECT		_spr_lib0_35
		OBJ_ANIMATE_SYNC
		OBJ_ANIMATE_SYNC
		OBJ_ANIMATE_SYNC
		NJSR				_native_complement_y_deltas
		LOOPB				$02,byte_6B80F
		SJMPS				byte_6B7F8
byte_6B823:
		LOOPB_RESET
		SRET

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_6B825:
		SPR_IDX_SELECT		_spr_lib0_17
		SJSRS				_script_sub_6B82C
		SPR_IDX_SELECT		_spr_lib0_18

; !FALLTHROUGH!

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_6B82C:
		NJSR_SYNC			_native_sub122
		LOOPB				$03,_script_sub_6B82C
		SRET

; =============== S C R I P T ===============================================
_script_cutscene00:
		SRUN				_OBJ_TYPE_AUTO,_obj_scr_cutscene_skip_wait
		SUSPEND				$1E
		SRUN				_OBJ_TYPE_AUTO,_script155
byte_6B83E:
		NJSR_SYNC			_native_sub064
		LOOPA				$80,byte_6B83E
		LOOPB				$02,byte_6B83E
		KILL

; =============== S U B R O U T I N E =======================================
_native_sub064:
		LDA		#$01
		LDX		#$00
		JSR		_native_sub065
		LDA		#$02
		INX

; =============== S U B R O U T I N E =======================================
_native_sub065:
		CLC
		ADC		_ppu_scroll_shadow_lo,X
		STA		_ppu_scroll_shadow_lo,X
		LDA		_ppu_scroll_nt_hor,X
		ADC		#$00
		STA		_ppu_scroll_nt_hor,X
		RTS

; =============== S C R I P T ===============================================
_script155:
		NJSR				_native_obj_idxCs_clear_low_nibble
		OBJ_X_POS_SET		$F8,$FF
		OBJ_Y_POS_SET		$30,$00
		OBJ_X_DELTA_SET		$08
		HFLIP_TOGGLE
		OBJ_SHOW
byte_6B86D:
		SJSRS				_script_sub_6B8AC
		LOOPA				$12,byte_6B86D
		SJSRS				_script_sub_6B8A0
		OBJ_Y_DELTA_SET		$08
		SJSRS				_script_sub_6B8AC
		SJSRS				_script_sub_6B8AC
		SJSRS				_script_sub_6B8A0
		OBJ_Y_DELTA_SET		$F8
		SJSRS				_script_sub_6B8AC
		SJSRS				_script_sub_6B8AC
		STORE				$12,_pal_anim_mode_idx
		SRUN				_OBJ_TYPE_AUTO,_script156
		OBJ_X_DELTA_SET		$08
		OBJ_Y_DELTA_SET		$00
byte_6B896:
		SJSRS				_script_sub_6B8AC
		LOOPA				$1E,byte_6B896
		SJMP				_script_sub_delayed_next_cutscene

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_6B8A0:
		OBJ_X_DELTA_SET		$00
		OBJ_Y_DELTA_SET		$00
byte_6B8A4:
		SJSRS				_script_sub_6B8AC
		LOOPA				$04,byte_6B8A4
		SRET

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_6B8AC:
		SPR_IDX_SELECT		_spr_lib0_19
		SJSR				_script_animate10
		SPR_IDX_SELECT		_spr_lib0_1A
		SJMP				_script_animate10

; =============== S C R I P T ===============================================
_script156:
		APU_LOAD			_apu_mus55
		SUSPEND				$30
		SJMPS				_script156

; =============== S C R I P T ===============================================
_script_cutscene01:
		SRUN				_OBJ_TYPE_AUTO,_obj_scr_cutscene_skip_wait
		OBJ_Y_POS_SET		$C0,$00
		TARGET_DIR_SET		$00
		SRUN				_OBJ_TYPE_AUTO,_script157
		NJSR_SYNC			_native_cut_store_char_number
		SUSPEND				$1E
		MSG_DISPLAY			_msg00,_apu_mus5B
		MSG_WAIT
		SJSR				_script_sub_cut_char_idxBs_10_clear_set_test
		MSG_DISPLAY			_msg01,_apu_mus56
		SJSR				_script_sub_cut_char_idxBs_10_clear_set_test
		TARGET_DIR_SET		$03
		SRUN				_OBJ_TYPE_AUTO,_script158
		NJSR_SYNC			_native_cut_store_char_number
		SJSR				_script_sub_cut_char_idxBs_10_clear_set_test
		MSG_DISPLAY			_msg02,_apu_mus58
		SJSR				_script_sub_cut_char_idxBs_10_clear_set_test
		TARGET_DIR_SET		$00
		MSG_DISPLAY			_msg03,_apu_mus56
		SJSR				_script_sub_cut_char_idxBs_10_clear_set_test
		TARGET_DIR_SET		$03
		MSG_DISPLAY			_msg04,_apu_mus58
		SJSR				_script_sub_cut_char_idxBs_10_clear_set_test
		TARGET_DIR_SET		$02
		OBJ_Y_POS_SET		$A0,$00
		SRUN				_OBJ_TYPE_AUTO,_script159
		NJSR_SYNC			_native_cut_store_char_number
		TARGET_DIR_SET		$00
		MSG_DISPLAY			_msg05,_apu_mus56
		SJSR				_script_sub_cut_char_idxBs_10_clear_set_test
		TARGET_DIR_SET		$03
		MSG_DISPLAY			_msg06,_apu_mus58
		SJSR				_script_sub_cut_char_idxBs_10_clear_set_test
		NJSR_SYNC			_native_cut_char_idxBs_10_clear
		TARGET_DIR_SET		$02
		MSG_DISPLAY			_msg07,_apu_mus59
		SJSR				_script_sub_cut_char_idxBs_10_clear_set_test
		NJSR_SYNC			_native_cut_char_idxBs_10_clear
		TARGET_DIR_SET		$04
		SRUN				_OBJ_TYPE_AUTO,_script15A
		NJSR_SYNC			_native_cut_store_char_number
		SJSR				_script_sub_cut_char_idxBs_10_clear_set_test
		MSG_DISPLAY			_msg08,_apu_mus5A
		MSG_WAIT
		NJSR_SYNC			_native_cut_char_idxBs_10_clear
		TARGET_DIR_SET		$01
		OBJ_Y_POS_SET		$C0,$00
		SRUN				_OBJ_TYPE_AUTO,_script15B
		NJSR_SYNC			_native_cut_store_char_number
		SJSR				_script_sub_cut_char_idxBs_10_clear_set_test
		TARGET_DIR_SET		$00
		MSG_DISPLAY			_msg09,_apu_mus56
		SJSR				_script_sub_cut_char_idxBs_10_clear_set_test
		TARGET_DIR_SET		$01
		SJSR				_script_sub_cut_char_idxBs_10_clear_set_test
		MSG_DISPLAY			_msg0A,_apu_mus57
		SJSR				_script_sub_cut_char_idxBs_10_clear_set_test
		TARGET_DIR_SET		$00
		MSG_DISPLAY			_msg0B,_apu_mus56
		SJSR				_script_sub_cut_char_idxBs_10_clear_set_test
		TARGET_DIR_SET		$01
		MSG_DISPLAY			_msg0C,_apu_mus57
		SJSR				_script_sub_cut_char_idxBs_10_clear_set_test
		MSG_DISPLAY			_msg0D,_apu_mus56
		TARGET_DIR_SET		$00
		NJSR				_native_cut_char_idxBs_10_clear
		TARGET_DIR_SET		$01
		NJSR				_native_cut_char_idxBs_10_clear
		MSG_WAIT
		MSG_DISPLAY			_msg0E,_apu_mus5B
		MSG_WAIT
		SJMP				_script_sub_delayed_ingame_start

; =============== S C R I P T ===============================================
_script157:
		OBJ_X_POS_SET		$B8,$00
		SPR_LIB_SELECT		_spr_lib1
		SPR_IDX_SELECT		_spr_lib1_1B
		OBJ_SHOW
		SJSR				_script_sub_idxBs_10_set_clear_wait
		SJSR				_script_sub_6B750
		SJSR				_script_sub_6B73A
		SJSR				_script_sub_6B73A
		SJSR				_script_sub_6B744
		SJSR				_script_sub_6B73A
		SJSR				_script_sub_6B73A
		HFLIP_SET
		OBJ_X_DELTA_SET		$10
		OBJ_Y_DELTA_SET		$00
		SJSR				_script_sub_B7533
		SJSR				_script_sub_B7533
		KILL

; =============== S C R I P T ===============================================
_script15B:
		SJSR				_script_sub_obj_idxCs_clear_low_nibble_flips_08_set
		HFLIP_SET
		OBJ_X_POS_SET		$D8,$FF
		SJSR				_script_sub_6B76F
		SPR_LIB_SELECT		_spr_lib2
		OBJ_SHOW
		OBJ_X_DELTA_SET		$10
		SJSR				_script_sub_B7533
		SJSR				_script_sub_B7533
		SPR_IDX_SELECT		_spr_lib2_05
		OBJ_Y_DELTA_SET		$C0
		OBJ_HP_SET			$01
		SJSR				_script_sub_obj_wait_for_jump
		SJSR				_script_sub_B7555
		SPR_IDX_SELECT		_spr_lib2_1B
		SJSR				_script_sub_idxBs_10_set_clear_wait
		SJSR				_script_sub_6B75D
		SJSR				_script_sub_6B73A
		SJSR				_script_sub_6B73A
		OBJ_X_DELTA_SET		$00
		OBJ_Y_DELTA_SET		$10
		SJSR				_script_sub_obj_wait_for_jump
		SJSR				_script_sub_B7555
		OBJ_X_DELTA_SET		$10
byte_6B9F5:
		SJSR				_script_sub_B7533
		LOOPA				$06,byte_6B9F5
		KILL

; =============== S C R I P T ===============================================
_script158:
		SJSR				_script_sub_obj_idxCs_clear_low_nibble_flips_08_set
		HFLIP_SET
		OBJ_X_POS_SET		$F0,$FF
		OBJ_SHOW
		OBJ_X_DELTA_SET		$10
byte_6BA07:
		SJSR				_script_sub_6B7A3
		LOOPA				$04,byte_6BA07
		SPR_IDX_SELECT		_spr_lib0_28
		TARGET_DIR_SET		$00
		SJSR				_script_sub_gadget_static_draw
		SJSR				_script_sub_6B78D
		SJSR				_script_sub_6B78D
		SJSR				_script_sub_6B797
		TARGET_DIR_SET		$00
byte_6BA20:
		SJSR				_script_sub_6B7A3
		LOOPA				$06,byte_6BA20
		KILL

; =============== S C R I P T ===============================================
_script159:
		SJSR				_script_sub_obj_idxCs_clear_low_nibble_flips_08_set
		HFLIP_SET
		OBJ_X_POS_SET		$B8,$FF
		SJSR				_script_sub_6B76F
		OBJ_X_DELTA_SET		$10
		OBJ_SHOW
byte_6BA35:
		SJSR				_script_sub_6B7DD
		LOOPA				$04,byte_6BA35
		OBJ_Y_DELTA_SET		$C0
		OBJ_HP_SET			$01
		SJSR				_script_sub_obj_wait_for_jump
		SPR_IDX_SELECT		_spr_lib0_1C
		TARGET_DIR_SET		$00
		SJSR				_script_sub_monterey_static_draw
		SJSR				_script_sub_6B7D1
		SPR_IDX_SELECT		_spr_lib0_24
		OBJ_Y_DELTA_SET		$C0
		OBJ_HP_SET			$01
		SJSR				_script_sub_obj_wait_for_jump
byte_6BA56:
		SJSR				_script_sub_6B7DD
		LOOPA				$08,byte_6BA56
		KILL

; =============== S C R I P T ===============================================
_script15A:
		SJSR				_script_sub_obj_idxCs_clear_low_nibble_flips_08_set
		HFLIP_SET
		OBJ_X_POS_SET		$F8,$FF
		OBJ_Y_POS_SET		$80,$00
		OBJ_SHOW
		OBJ_X_DELTA_SET		$10
byte_6BA6B:
		SJSR				_script_sub_6B825
		LOOPA				$1A,byte_6BA6B
		NJSR				_native_idxBs_10_set
		SJSR				_script_sub_zipper_hover_animate
		OBJ_X_DELTA_SET		$10
byte_6BA7A:
		SJSR				_script_sub_6B825
		LOOPA				$1A,byte_6BA7A
		KILL

; =============== S C R I P T ===============================================
_script_cutscene02:
		SRUN				_OBJ_TYPE_AUTO,_obj_scr_cutscene_skip_wait
		OBJ_Y_POS_SET		$C0,$00
		TARGET_DIR_SET		$05
		SRUN				_OBJ_TYPE_AUTO,_script15C
		NJSR_SYNC			_native_cut_store_char_number
		SUSPEND				$1E
		TARGET_DIR_SET		$00
		SRUN				_OBJ_TYPE_AUTO,_script15D
		NJSR_SYNC			_native_cut_store_char_number
		TARGET_DIR_SET		$01
		SRUN				_OBJ_TYPE_AUTO,_script15E
		NJSR_SYNC			_native_cut_store_char_number
		SJSR				_script_sub_cut_char_idxBs_10_clear_set_test
		MSG_DISPLAY			_msg0F,_apu_mus56
		MSG_WAIT
		TARGET_DIR_SET		$05
		MSG_DISPLAY			_msg10,_apu_mus5C
		SJSR				_script_sub_cut_char_idxBs_10_clear_set_test
		TARGET_DIR_SET		$01
		MSG_DISPLAY			_msg11,_apu_mus57
		NJSR_SYNC			_native_cut_char_idxBs_10_clear
		MSG_WAIT
		TARGET_DIR_SET		$05
		MSG_DISPLAY			_msg12,_apu_mus5C
		SJSR				_script_sub_cut_char_idxBs_10_clear_set_test
		TARGET_DIR_SET		$00
		MSG_DISPLAY			_msg13,_apu_mus56
		MSG_WAIT
		TARGET_DIR_SET		$05
		MSG_DISPLAY			_msg14,_apu_mus5C
		SJSR				_script_sub_cut_char_idxBs_10_clear_set_test
		NJSR_SYNC			_native_cut_char_idxBs_10_clear
		TARGET_DIR_SET		$00
		NJSR_SYNC			_native_cut_char_idxBs_10_clear
		TARGET_DIR_SET		$01
		SJSR				_script_sub_cut_char_idxBs_10_clear_set_test
		SJMP				_script_sub_delayed_ingame_start

; =============== S C R I P T ===============================================
_script15D:
		SPR_LIB_SELECT		_spr_lib1
		OBJ_X_POS_SET		$C0,$FF
		SJSRS				_script_sub_6BB08
		SJMPS				byte_6BB1B

; =============== S C R I P T ===============================================
_script15E:
		SPR_LIB_SELECT		_spr_lib2
		OBJ_X_POS_SET		$A8,$FF
		SJSRS				_script_sub_6BB08
		SJSR				_script_sub_B7547
		OBJ_Y_DELTA_SET		$00
		SJSR				_script_sub_idxBs_10_set_clear_wait
		SJMPS				byte_6BB1B

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_6BB08:
		SJSR				_script_sub_obj_idxCs_clear_low_nibble_flips_08_set
		HFLIP_SET
		OBJ_X_DELTA_SET		$10
		OBJ_SHOW
byte_6BB0F:
		SJSR				_script_sub_B7533
		LOOPA				$04,byte_6BB0F
		SPR_IDX_SELECT		_spr_lib2_00
		SJMP				_script_sub_idxBs_10_set_clear_wait
byte_6BB1B:
		SJSR				_script_sub_B7533
		LOOPA				$08,byte_6BB1B
		SJSR				_script_sub_idxBs_10_set_clear_wait

; =============== S C R I P T ===============================================
_script15C:
		OBJ_X_POS_SET		$D0,$00
		OBJ_Y_POS_SET		$90,$00
		SPR_LIB_SELECT		_spr_lib8
		SPR_IDX_SELECT		_spr_lib8_15
		OBJ_SHOW
		SJSR				_script_sub_idxBs_10_set_clear_wait
		OBJ_HP_SET			$15
		OBJ_DAMAGE_SET		$16
		SJSR				_script_cut_obj_msg_spr_animate
		SJSR				_script_sub_idxBs_10_set_clear_wait
		SJSR				_script_cut_obj_msg_spr_animate
		SJSR				_script_sub_idxBs_10_set_clear_wait
		SJSR				_script_cut_obj_msg_spr_animate
		SJSR				_script_sub_idxBs_10_set_clear_wait
		OBJ_X_DELTA_SET		$10
		HFLIP_SET
byte_6BB4C:
		SPR_IDX_SELECT		_spr_lib8_18
		SJSR				_script_animate12
		SPR_IDX_SELECT		_spr_lib8_20
		SJSR				_script_animate12
		LOOPA				$03,byte_6BB4C
		KILL

; =============== S C R I P T ===============================================
_script_cutscene03:
		SRUN				_OBJ_TYPE_AUTO,_obj_scr_cutscene_skip_wait
		TARGET_DIR_SET		$00
		SRUN				_OBJ_TYPE_AUTO,_script15F
		NJSR				_native_cut_store_char_number
		TARGET_DIR_SET		$01
		SRUN				_OBJ_TYPE_AUTO,_script160
		NJSR				_native_cut_store_char_number
		SUSPEND				$30
		TARGET_DIR_SET		$00
		SJSR				_script_sub_cut_char_idxBs_10_clear_set_test
		MSG_DISPLAY			_msg15,_apu_mus56
		SJSR				_script_sub_cut_char_idxBs_10_clear_set_test
		TARGET_DIR_SET		$03
		SRUN				_OBJ_TYPE_AUTO,_script161
		NJSR_SYNC			_native_cut_store_char_number
		SJSR				_script_sub_cut_char_idxBs_10_clear_set_test
		TARGET_DIR_SET		$05
		SRUN				_OBJ_TYPE_AUTO,_script162
		NJSR_SYNC			_native_cut_store_char_number
		TARGET_DIR_SET		$03
		MSG_DISPLAY			_msg16,_apu_mus58
		SJSR				_script_sub_cut_char_idxBs_10_clear_set_test
		TARGET_DIR_SET		$01
		MSG_DISPLAY			_msg17,_apu_mus57
		SJSR				_script_sub_cut_char_idxBs_10_clear_set_test
		TARGET_DIR_SET		$03
		MSG_DISPLAY			_msg18,_apu_mus58
		SJSR				_script_sub_cut_char_idxBs_10_clear_set_test
		TARGET_DIR_SET		$01
		MSG_DISPLAY			_msg19,_apu_mus57
		SJSR				_script_sub_cut_char_idxBs_10_clear_set_test
		TARGET_DIR_SET		$03
byte_6BBBA:
		MSG_DISPLAY			_msg1A,_apu_mus58
		SJSR				_script_sub_cut_char_idxBs_10_clear_set_test
		SJSR				_script_sub_6BC7C
		NJSR_SYNC			_native_sub066
		MSG_DISPLAY			_msg1B,_apu_mus58
		SJSR				_script_sub_cut_char_idxBs_10_clear_set_test
		SJSR				_script_sub_6BC7C
		SSWITCH				_hor_menu_pos
		SCASE				byte_6BBE2
		SCASE				byte_6BBD8
byte_6BBD8:
		STORE				$01,byte_E1
		NJSR_SYNC			_native_cut_char_idxBs_10_clear
		SJMPS				byte_6BBBA
byte_6BBE2:
		MSG_DISPLAY			_msg1C,_apu_mus58
		SJSR				_script_sub_cut_char_idxBs_10_clear_set_test
		APU_LOAD			_apu_mus4D
		SUSPEND				$3C
		SSWITCH				byte_E0
		SCASE				byte_6BBF4
		SCASE				byte_6BC47
byte_6BBF4:
		APU_LOAD			_apu_mus46
byte_6BBF6:
		NJSR				_native_sub068
		OBJ_X_DELTA_INC
		SUSPEND				$04
		LOOPA				$03,byte_6BBF6
		SUSPEND				$10
		TARGET_DIR_SET		$01
		NJSR_SYNC			_native_cut_char_idxBs_10_clear
byte_6BC07:
		OBJ_X_DELTA_DEC
		NJSR				_native_sub068
		SUSPEND				$04
		LOOPA				$03,byte_6BC07
		NJSR_SYNC			_ppu_pal_apply
		APU_LOAD			_apu_mus13
		TARGET_DIR_SET		$03
		MSG_DISPLAY			_msg1D,_apu_mus58
		SJSR				_script_sub_cut_char_idxBs_10_clear_set_test
		MSG_DISPLAY			_msg1E,_apu_mus58
		SJSR				_script_sub_cut_char_idxBs_10_clear_set_test
		TARGET_DIR_SET		$00
		SJSR				_script_sub_cut_char_idxBs_10_clear_set_test
		MSG_DISPLAY			_msg1F,_apu_mus56
		SJSR				_script_sub_cut_char_idxBs_10_clear_set_test
		TARGET_DIR_SET		$03
		MSG_DISPLAY			_msg20,_apu_mus58
		SJSR				_script_sub_cut_char_idxBs_10_clear_set_test
		TARGET_DIR_SET		$00
		MSG_DISPLAY			_msg21,_apu_mus56
		SJSR				_script_sub_cut_char_idxBs_10_clear_set_test
		SJMPS				byte_6BC5E
byte_6BC47:
		MSG_DISPLAY			_msg22,_apu_mus58
		SJSR				_script_sub_cut_char_idxBs_10_clear_set_test
		TARGET_DIR_SET		$05
		NJSR_SYNC			_native_cut_char_idxBs_10_clear
		SUSPEND				$3C
		TARGET_DIR_SET		$03
		MSG_DISPLAY			_msg23,_apu_mus58
		SJSR				_script_sub_cut_char_idxBs_10_clear_set_test
byte_6BC5E:
		TARGET_DIR_SET		$00
		MSG_DISPLAY			_msg24,_apu_mus56
		SJSR				_script_sub_cut_char_idxBs_10_clear_set_test
		TARGET_DIR_SET		$03
		MSG_DISPLAY			_msg25,_apu_mus58
		SJSR				_script_sub_cut_char_idxBs_10_clear_set_test
		TARGET_DIR_SET		$00
		MSG_DISPLAY			_msg26,_apu_mus56
		SJSR				_script_sub_cut_char_idxBs_10_clear_set_test
		SJMP				_script_sub_delayed_ingame_start

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_6BC7C:
		NJSR				_menu_init
		MENU_CURSOR_DRAW	_menu_data01
byte_6BC82:
		SYNC
		NJSR				_native_sub102
		PADS_TEST			_PAD0_PRESS,_PAD_LEFT|_PAD_RIGHT,byte_6BC93
		APU_LOAD			_apu_mus31
		NJSR				_native_sub067
		MENU_CURSOR_DRAW	_menu_data01
byte_6BC93:
		PADS_TEST			_PAD0_PRESS,_PAD_A,byte_6BC82
		APU_LOAD			_apu_mus32
		SRET

; =============== S U B R O U T I N E =======================================
_native_sub066:
		LDA		_hor_menu_pos
		STA		byte_E0
		LDA		#$00
		STA		byte_E1
		RTS

; =============== S U B R O U T I N E =======================================
_native_sub067:
		LDX		_hor_menu_pos
		STX		_tmp48
		INX
		TXA
		AND		#$01
		STA		_hor_menu_pos
		RTS
_menu_data01:
		.BYTE	$02,$01
		.BYTE	$40,$3E
		.BYTE	$E3,$24
		.BYTE	$E8,$24

; =============== S U B R O U T I N E =======================================
_native_sub068:
		LDA		_obj_x_deltas,X
		ASL
		TAX
		LDA		off_6BCC5,X
		LDY		off_6BCC5+1,X
		JMP		_far_prg3_spr_pal_load
off_6BCC5:
		.WORD	byte_53211
		.WORD	byte_53231
		.WORD	byte_53251

; =============== S C R I P T ===============================================
_script15F:
		SJSR				_script_sub_obj_idxCs_clear_low_nibble_flips_08_set
		OBJ_X_POS_SET		$1C,$01
		OBJ_Y_POS_SET		$A0,$00
		SPR_LIB_SELECT		_spr_lib1
		OBJ_SHOW
		OBJ_X_DELTA_SET		$F0
byte_6BCD9:
		SJSR				_script_sub_B7533
		LOOPA				$04,byte_6BCD9
		SPR_IDX_SELECT		_spr_lib1_1B
		SJSR				_script_sub_idxBs_10_set_clear_wait
		SJSR				_script_sub_6B73A
		SSWITCH				byte_E0
		SCASE				byte_6BCEF
		SCASE				byte_6BCF9
byte_6BCEF:
		SJSR				_script_sub_6B750
		SJSR				_script_sub_6B73A
		HFLIP_SET
		SJSR				_script_sub_6B744
byte_6BCF9:
		SJSR				_script_sub_6B73A
		SJSR				_script_sub_6B73A

; =============== S C R I P T ===============================================
_script160:
		SJSR				_script_sub_obj_idxCs_clear_low_nibble_flips_08_set
		OBJ_X_POS_SET		$10,$01
		OBJ_Y_POS_SET		$90,$00
		SPR_LIB_SELECT		_spr_lib2
		OBJ_SHOW
		OBJ_X_DELTA_SET		$F0
		SJSR				_script_sub_B7533
		SJSR				_script_sub_B7533
		SPR_IDX_SELECT		_spr_lib2_1B
		SJSR				_script_sub_idxBs_10_set_clear_wait
		SJSR				_script_sub_6B73A
		SJSR				_script_sub_6B73A
		SSWITCH				byte_E0
		SCASE				byte_6BD25
		SCASE				byte_6BD2D
byte_6BD25:
		SJSR				_script_sub_6B76F
		NJSR				_players_animB_sub0129_sub0E_A
		SPR_IDX_SELECT		_spr_lib2_0D
byte_6BD2D:
		SJMP				_script_idle

; =============== S C R I P T ===============================================
_script161:
		SJSR				_script_sub_obj_idxCs_clear_low_nibble_flips_08_set
		OBJ_X_POS_SET		$F8,$FF
		OBJ_Y_POS_SET		$C0,$00
		HFLIP_SET
		OBJ_SHOW
		OBJ_X_DELTA_SET		$10
byte_6BD3D:
		SJSR				_script_sub_6B7A3
		LOOPA				$04,byte_6BD3D
		SPR_IDX_SELECT		_spr_lib0_28
		TARGET_DIR_SET		$00
		SJSR				_script_sub_gadget_static_draw
		SJSR				_script_sub_6B78D
		SJSR				_script_sub_6B78D
byte_6BD51:
		SJSR				_script_sub_6B78D
		SJSR				_script_sub_6B78D
		SSWITCH				byte_E1
		SCASE				byte_6BD5E
		SCASE				byte_6BD51
byte_6BD5E:
		SJSR				_script_sub_6B78D
		SSWITCH				byte_E0
		SCASE				byte_6BD68
		SCASE				byte_6BD6B
byte_6BD68:
		SJSR				_script_sub_6B78D
byte_6BD6B:
		SJSR				_script_sub_6B78D
		SJSR				_script_sub_6B78D
		SJSR				_script_sub_6B78D

; =============== S C R I P T ===============================================
_script162:
		OBJ_X_POS_SET		$88,$00
		OBJ_Y_POS_SET		$A0,$00
		SPR_IDX_SELECT		_spr_lib0_38
		OBJ_SHOW
		SJSR				_script_sub_idxBs_10_set_clear_wait
		APU_LOAD			_apu_mus46
byte_6BD82:
		SPR_IDX_SELECT		_spr_lib0_39
		SUSPEND				$06
		SPR_IDX_SELECT		_spr_lib0_3A
		SUSPEND				$06
		LOOPA				$02,byte_6BD82
		SPR_IDX_SELECT		_spr_lib0_3B
		SUSPEND				$06
		KILL

; =============== S C R I P T ===============================================
_script_cutscene04:
		SRUN				_OBJ_TYPE_AUTO,_obj_scr_cutscene_skip_wait
		TARGET_DIR_SET		$00
		SRUN				_OBJ_TYPE_AUTO,_script163
		NJSR				_native_cut_store_char_number
		TARGET_DIR_SET		$01
		SRUN				_OBJ_TYPE_AUTO,_script164
		NJSR				_native_cut_store_char_number
		TARGET_DIR_SET		$02
		SRUN				_OBJ_TYPE_AUTO,_script165
		NJSR				_native_cut_store_char_number
		TARGET_DIR_SET		$04
		SRUN				_OBJ_TYPE_AUTO,_script166
		NJSR_SYNC			_native_cut_store_char_number
		SUSPEND				$1E
		TARGET_DIR_SET		$01
		MSG_DISPLAY			_msg27,_apu_mus57
		SJSR				_script_sub_cut_char_idxBs_10_clear_set_test
		SRUN				_OBJ_TYPE_AUTO,_script167
		SUSPEND				$3C
		MSG_DISPLAY			_msg28,_apu_mus5A
		MSG_WAIT
		TARGET_DIR_SET		$00
		MSG_DISPLAY			_msg29,_apu_mus56
		SJSR				_script_sub_cut_char_idxBs_10_clear_set_test
		TARGET_DIR_SET		$02
		MSG_DISPLAY			_msg2A,_apu_mus59
		SJSR				_script_sub_cut_char_idxBs_10_clear_set_test
		TARGET_DIR_SET		$00
		MSG_DISPLAY			_msg2B,_apu_mus56
		SJSR				_script_sub_cut_char_idxBs_10_clear_set_test
		MSG_DISPLAY			_msg2C,_apu_mus5A
		MSG_WAIT
		MSG_DISPLAY			_msg2D,_apu_mus56
		SJSR				_script_sub_cut_char_idxBs_10_clear_set_test
		SJMP				_script_sub_delayed_next_cutscene

; =============== S C R I P T ===============================================
_script163:
		HFLIP_SET
		OBJ_X_POS_SET		$48,$00
		OBJ_Y_POS_SET		$80,$00
		SPR_LIB_SELECT		_spr_lib1
		OBJ_SHOW
		SJSR				_script_sub_idxBs_10_set_clear_wait
		SJSR				_script_sub_6B73A
		SJSR				_script_sub_6B73A
		SJSR				_script_sub_6B744

; =============== S C R I P T ===============================================
_script164:
		HFLIP_SET
		OBJ_X_POS_SET		$30,$00
		OBJ_Y_POS_SET		$80,$00
		SPR_LIB_SELECT		_spr_lib2
		OBJ_SHOW
		SJSR				_script_sub_idxBs_10_set_clear_wait
		SJSR				_script_sub_6B73A

; =============== S C R I P T ===============================================
_script165:
		OBJ_X_POS_SET		$80,$00
		OBJ_Y_POS_SET		$D0,$00
		OBJ_SHOW
		SPR_IDX_SELECT		_spr_lib0_1C
		TARGET_DIR_SET		$00
		SJSR				_script_sub_monterey_static_draw
		HFLIP_SET
		SJSR				_script_sub_6B7D1

; =============== S C R I P T ===============================================
_script166:
		HFLIP_SET
		OBJ_SHOW
		OBJ_X_POS_SET		$70,$00
		OBJ_Y_POS_SET		$90,$00
byte_6BE3B:
		SJSR				_script_sub_zipper_hover_animate
		SJMPS				byte_6BE3B

; =============== S C R I P T ===============================================
_script167:
		SJSR				_script_sub_obj_idxCs_clear_low_nibble_flips_08_set
		OBJ_X_POS_SET		$10,$01
		OBJ_Y_POS_SET		$B0,$00
		SPR_IDX_SELECT		_spr_lib0_3C
		OBJ_SHOW
		OBJ_X_DELTA_SET		$F8
byte_6BE4F:
		OBJ_ANIMATE_SYNC
		LOOPA				$80,byte_6BE4F
		KILL

; =============== S C R I P T ===============================================
_script_cutscene05:
		SRUN				_OBJ_TYPE_AUTO,_obj_scr_cutscene_skip_wait
		TARGET_DIR_SET		$00
		SRUN				_OBJ_TYPE_AUTO,_script168
		NJSR				_native_cut_store_char_number
		TARGET_DIR_SET		$01
		SRUN				_OBJ_TYPE_AUTO,_script169
		NJSR_SYNC			_native_cut_store_char_number
		SUSPEND				$3C
		SJSR				_script_sub_cut_char_idxBs_10_clear_set_test
		MSG_DISPLAY			_msg2E,_apu_mus56
		MSG_WAIT
		APU_LOAD			_apu_mus51
		SUSPEND				$3C
		MSG_DISPLAY			_msg2F,_apu_mus57
		MSG_WAIT
byte_6BE7E:
		SJSRS				_script_sub_6BECE
		NJSR_SYNC			_ppu_pal_apply
		SUSPEND				$10
		SJSRS				_script_sub_6BECE
		NJSR_SYNC			_pal_patch03_load
		SUSPEND				$04
		LOOPA				$05,byte_6BE7E
		SUSPEND				$B4
		SJMP				_script_sub_delayed_next_cutscene

; =============== S C R I P T ===============================================
_script_cutscene07:
		SRUN				_OBJ_TYPE_AUTO,_obj_scr_cutscene_skip_wait
		TARGET_DIR_SET		$00
		SRUN				_OBJ_TYPE_AUTO,_script16A
		NJSR				_native_cut_store_char_number
		TARGET_DIR_SET		$01
		SRUN				_OBJ_TYPE_AUTO,_script16B
		NJSR_SYNC			_native_cut_store_char_number
		SUSPEND				$3C
		TARGET_DIR_SET		$01
		MSG_DISPLAY			_msg37,_apu_mus57
		SJSR				_script_sub_cut_char_idxBs_10_clear_set_test
		TARGET_DIR_SET		$00
		MSG_DISPLAY			_msg38,_apu_mus56
		SJSR				_script_sub_cut_char_idxBs_10_clear_set_test
		SJMP				_script_sub_delayed_ingame_start

; =============== S C R I P T ===============================================
_script_cutscene08:
		SUSPEND				$3C
		MSG_DISPLAY			_msg39,_apu_mus5B
		MSG_WAIT
		SJMP				_script_sub_delayed_ingame_start

; =============== S C R I P T   R O U T I N E ===============================
_script_sub_6BECE:
		TARGET_DIR_SET		$00
		NJSR				_native_cut_char_idxBs_10_clear
		TARGET_DIR_SET		$01
		NJSR				_native_cut_char_idxBs_10_clear
		SRET

; =============== S U B R O U T I N E =======================================
_pal_patch03_load:
		LDA		#<[_pal_patch03]
		LDY		#>[_pal_patch03]
		JMP		_far_prg3_pal_patch_load

; =============== S C R I P T ===============================================
_script168:
		SPR_LIB_SELECT		_spr_lib1
		OBJ_X_POS_SET		$F0,$FF
		SJMPS				byte_6BEED

; =============== S C R I P T ===============================================
_script169:
		SPR_LIB_SELECT		_spr_lib2
		OBJ_X_POS_SET		$D8,$FF
byte_6BEED:
		SPR_IDX_SELECT		_spr_lib2_20
		SJSR				_script_sub_obj_idxCs_clear_low_nibble_flips_08_set
		HFLIP_SET
		OBJ_Y_POS_SET		$C0,$00
		OBJ_X_DELTA_SET		$10
		OBJ_SHOW
byte_6BEF9:
		SJSR				_script_animate10
		LOOPA				$10,byte_6BEF9
		SJSR				_script_sub_idxBs_10_set_clear_wait
byte_6BF03:
		SJSR				_script_sub_idxBs_10_set_clear_wait
		SPR_IDX_SELECT		_spr_lib2_1B
		SJSR				_script_sub_idxBs_10_set_clear_wait
		SPR_IDX_SELECT		_spr_lib2_20
		LOOPA				$05,byte_6BF03
		SJMP				_script_idle

; =============== S C R I P T ===============================================
_script16A:
		OBJ_X_POS_SET		$70,$00
		OBJ_Y_POS_SET		$C0,$00
		SPR_LIB_SELECT		_spr_lib1
		SPR_IDX_SELECT		_spr_lib1_1B
		HFLIP_SET
		OBJ_SHOW
		SJSR				_script_sub_idxBs_10_set_clear_wait
		SJSR				_script_sub_6B744
		SJSR				_script_sub_6B73A

; =============== S C R I P T ===============================================
_script16B:
		OBJ_X_POS_SET		$58,$00
		OBJ_Y_POS_SET		$C0,$00
		SPR_LIB_SELECT		_spr_lib2
		SPR_IDX_SELECT		_spr_lib2_1B
		HFLIP_SET
		OBJ_SHOW
		SJSR				_script_sub_idxBs_10_set_clear_wait
		SJSR				_script_sub_6B73A

; =============== S C R I P T ===============================================
_script_cutscene06:
		SRUN				_OBJ_TYPE_AUTO,_obj_scr_cutscene_skip_wait
		SUSPEND				$3C
		MSG_DISPLAY			_msg30,_apu_mus5D
		MSG_WAIT
		MSG_DISPLAY			_msg31,_apu_mus57
		MSG_WAIT
		MSG_DISPLAY			_msg32,_apu_mus5D
		MSG_WAIT
		MSG_DISPLAY			_msg33,_apu_mus56
		MSG_WAIT
		MSG_DISPLAY			_msg34,_apu_mus5D
		MSG_WAIT
		MSG_DISPLAY			_msg35,_apu_mus57
		MSG_WAIT
		MSG_DISPLAY			_msg36,_apu_mus5D
		MSG_WAIT
		SJMP				_script_sub_delayed_next_cutscene

; =============== S C R I P T ===============================================
_script_cutscene09:
		SRUN				_OBJ_TYPE_AUTO,_obj_scr_cutscene_skip_wait
		SRUN				_OBJ_TYPE_AUTO,_script16C
		TARGET_DIR_SET		$00
		SRUN				_OBJ_TYPE_AUTO,_script16D
		NJSR				_native_cut_store_char_number
		TARGET_DIR_SET		$01
		SRUN				_OBJ_TYPE_AUTO,_script16E
		NJSR				_native_cut_store_char_number
		TARGET_DIR_SET		$02
		SRUN				_OBJ_TYPE_AUTO,_script16F
		NJSR_SYNC			_native_cut_store_char_number
		SUSPEND				$3C
		TARGET_DIR_SET		$02
		MSG_DISPLAY			_msg3A,_apu_mus59
		SJSR				_script_sub_cut_char_idxBs_10_clear_set_test
		TARGET_DIR_SET		$00
		MSG_DISPLAY			_msg3B,_apu_mus56
		SJSR				_script_sub_cut_char_idxBs_10_clear_set_test
		TARGET_DIR_SET		$01
		SJSR				_script_sub_cut_char_idxBs_10_clear_set_test
		MSG_DISPLAY			_msg3C,_apu_mus57
		SJSR				_script_sub_cut_char_idxBs_10_clear_set_test
		TARGET_DIR_SET		$00
		MSG_DISPLAY			_msg3D,_apu_mus56
		SJSR				_script_sub_cut_char_idxBs_10_clear_set_test
		TARGET_DIR_SET		$01
		SJSR				_script_sub_cut_char_idxBs_10_clear_set_test
		TARGET_DIR_SET		$01
		MSG_DISPLAY			_msg3E,_apu_mus57
		SJSR				_script_sub_cut_char_idxBs_10_clear_set_test
		SJMP				_script_sub_delayed_ingame_start

		SECTION_END		0B, "GAME SCRIPTS A"

		BANK_END 4,$C000
