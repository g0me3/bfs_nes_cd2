
		ORG $8000

		BANK_START $04

		DEBUG_LOG_INIT

		SECTION_START	0B

; =============== S C R I P T   R O U T I N E ===============================
_ssub_unref:
		NJSR				_obj_move_hor_animate
		NJSR				_nsub_obj_to_tile_collision_test_hor
		SBCSS				byte_6800C
		NJSR				_j_nsub_complement_x_deltas
byte_6800C:
		SJSRS				_ssub_obj_jump_calcs
		SBCSS				byte_6801F
		NJSR				_nsub_get_obj_y_delta
		SBMIS				byte_6801C
		NJSR				_nsub_sub107
		SRET
byte_6801C:
		NJSR				_scr_cmd_clear_carry
byte_6801F:
		SRET

; =============== S C R I P T   R O U T I N E ===============================
_ssub_acorn_prize_animate:
		SYNC
		NJSR				_nsub_get_obj_y_delta
		SBEQS				byte_6802F
		SJSRS				_ssub_obj_jump
		SBCCS				byte_6802F
		DELTA_X_SET			$00
byte_6802F:
		NJSR				_nsub_get_obj_hp
		SBNES				_ssub_acorn_prize_animate
		SRET

; =============== S C R I P T   R O U T I N E ===============================
_ssub_obj_wait_for_jump:
		SJSRS				_ssub_obj_jump_sync
		SBCCS				_ssub_obj_wait_for_jump
		SRET

; =============== S C R I P T   R O U T I N E ===============================
_ssub_obj_jump_sync:
		SYNC

; !FALLTHROUGH!

; =============== S C R I P T   R O U T I N E ===============================
_ssub_obj_jump:
		NJSR				_obj_move_hor_animate
		NJSR				_nsub_obj_to_tile_collision_test_hor

; !FALLTHROUGH!

; =============== S C R I P T   R O U T I N E ===============================
_ssub_obj_jump_calcs:
		NJSR				_nsub_obj_jump_up_anim
		NJSR				_nsub_get_obj_y_delta
		SBPLS				byte_6805C
		NJSR				_obj_vert_anim
		NJSR				_nsub_obj_to_tile_collision_test_up
		SBCSS				byte_68058
		DELTA_Y_SET			$01
byte_68058:
		NJSR				_scr_cmd_clear_carry
		SRET
byte_6805C:
		NJSR				_obj_to_tile_grid_collision_test_down
		SBCCS				byte_68064
		DELTA_Y_SET			$00
byte_68064:
		SRET

; =============== S C R I P T   R O U T I N E ===============================
_ssub_obj_wait_for_pickup:
		NJSR_SYNC			_nsub_get_obj_idxBs
		SBPLS				_ssub_obj_wait_for_pickup
		SRET

; =============== S C R I P T   R O U T I N E ===============================
_ssub_obj_wait_for_throw:
		NJSR				_nsub_obj_type_change_throw
		NJSR				_nsub_obj_idxCs_C0_clear
		NJSR				_nsub_sub164
byte_68075:
		NJSR				_nsub_get_obj_idxBs
		SBPLS				byte_68081
		NJSR_SYNC			_players_state06_C
		SJMPS				byte_68075
byte_68081:
		NJSR				_nsub_obj_idxCs_80_set
		APU_SE_SET			_apu_mus24
		SRET

; =============== S C R I P T   R O U T I N E ===============================
_obj_scr_common_destr:
		APU_SE_SET			_apu_mus2D
		DAMAGE_SET			_OBJ_DMG_NONE
		DELTA_X_SET			$BD
		DELTA_Y_SET			$BD
		NJSR				_nsub_obj_from_idxAs_hor_delta_toggle

; !FALLTHROUGH!

; =============== S C R I P T   R O U T I N E ===============================
_ssub_infinite_anim_sync:
		ANIMATE_HV_SYNC
		SJMPS				_ssub_infinite_anim_sync

; =============== S C R I P T   R O U T I N E ===============================
_ssub_y_parabolic_delta_infinite_anim_sync:
		ANIMATE_HV_SYNC
		NJSR				_nsub_obj_jump_up_anim
		SJMPS				_ssub_y_parabolic_delta_infinite_anim_sync

; =============== S C R I P T   R O U T I N E ===============================
_ssub_common_stun_mode:
		SJSRS				_ssub_common_stun_init	; so init stun and jump off animation
		DELTA_X_SET			$00
		NJSR				_scr_flips_04_clear		; stop movement
byte_680A5:
		SJSRS				_ssub_common_stun_obj_ai; wait for grab by player
		LOOP_A				$3C,byte_680A5			; about 8 seconds (8x60 frames)
		LOOP_B				$08,byte_680A5
		NJSR				_nsub_obj_blink_set		; if no grab, start blinking and
byte_680B3:
		SJSRS				_ssub_common_stun_obj_ai; wait some more time (2 sec = 120 frames)
		LOOP_A				$78,byte_680B3
		NJSR				_nsub_obj_blink_clear	; disable blink
		NJSR				_nsub_obj_disable_from_idxCs_40_flag	; return back to original state
		DAMAGE_SET			_OBJ_DMG_KILL
		SRET

; =============== S C R I P T   R O U T I N E ===============================
_ssub_common_stun_obj_ai:
		SYNC
		NJSR				_nsub_get_obj_idxBs
		SBMIS				byte_680D4
		NJSR				_nsub_obj_to_tile_collision_test_down
		SBCSS				byte_680D3
		SJSRS				_ssub_obj_jump_calcs
byte_680D3:
		SRET
byte_680D4:
		SJSRS				_ssub_68102
		DAMAGE_SET			_OBJ_DMG_STUN
		DELTA_X_SET			$C0
		NJSR				_nsub_sub11B
		NJSR				_nsub_sub11C
		NJSR				_nsub_obj_type_change_stunA
		SJMPS				_ssub_infinite_anim_sync

; =============== S C R I P T   R O U T I N E ===============================
_ssub_common_stun_init:
		DAMAGE_SET			_OBJ_DMG_NONE		; stunned objects harmless
		APU_SE_SET			_apu_mus2E			; also stun sparkle sound
		DELTA_X_SET			$F0					; jump off a little
		DELTA_Y_SET			$D0					; now toggle hot delta according to
		NJSR				_nsub_obj_from_idxAs_hor_delta_toggle	; projectile direction
		NJSR				_nsub_stun_sparkles_obj_scr_run	; start sparkles object
byte_680F5:
		SJSR				_ssub_obj_jump_sync	; animate jump-off
		SBCSS				byte_68101
		NJSR				_nsub_get_obj_idxBs
		SBPLS				byte_680F5
byte_68101:
		SRET

; =============== S C R I P T   R O U T I N E ===============================
_ssub_68102:
		DELTA_Y_SET			$00
		NJSR				_nsub_obj_idxCs_C0_clear
		NJSR				_nsub_obj_blink_clear
byte_6810A:
		SYNC
		NJSR				_players_state06_C
		NJSR				_nsub_get_obj_idxBs
		SBMIS				byte_6810A
		APU_SE_SET			_apu_mus24
		SRET

; =============== O B J E C T   S C R I P T =================================
_obj_scr24_spoon_rat:
		DESTR_PC_SET		_obj_scr_24_spoon_rat_destr
		SPR_LIB_SET			_spr_lib7
		SPR_IDX_SET			_spr_lib7_00
		SIZE_SET			$08,$18
		HP_SET				$02
		DAMAGE_SET			_OBJ_DMG_KILL
		SJSR				_ssub_obj_show_wait_for_idxCs_80_set
		DELTA_X_SET			$F0
		DELTA_Y_SET			$00
		NJSR				_nsub_sub10E
		NJSR				_nsub_obj_hor_delta_toggle
byte_68132:
		SPR_IDX_SET			_spr_lib7_00				; 4-frame walk animation
		SJSRS				_ssub_spoon_rat_ai	; fast enough delta to get all
		SPR_IDX_SET			_spr_lib7_01				; its path for only 4 steps here
		SJSRS				_ssub_spoon_rat_ai
		SPR_IDX_SET			_spr_lib7_02
		SJSRS				_ssub_spoon_rat_ai
		SPR_IDX_SET			_spr_lib7_01
		SJSRS				_ssub_spoon_rat_ai
byte_68146:
		NJSR				_nsub_obj_hor_move_reverse	; when reached end of path, flip x
		SJMPS				byte_68132

; =============== S C R I P T   R O U T I N E ===============================
_ssub_spoon_rat_ai:
		SYNC
		NJSR				_nsub_obj_to_throw_collision_test_range40		; player's box watch
		SBCCS				byte_6816A
		NJSR				_obj_move_hor_animate		; if no player, just walk
		NJSR				_nsub_obj_to_tile_collision_test_hor
		SBCSS				byte_6815F					; auto detect obstacles
		BREAK				byte_68146					; turn back if reached any solid object
byte_6815F:
		NJSR				_nsub_obj_to_tile_collision_test_down
		SBCC				_ssub_obj_wait_for_jump
		LOOP_A				$08,_ssub_spoon_rat_ai; repeat 8 times for 1 step
		SRET
byte_6816A:
		NJSR				_nsub_sub132
		SPR_IDX_SET			_spr_lib7_03
		SUSPEND				$08
		SPR_IDX_SET			_spr_lib7_04
		APU_SE_SET			_apu_mus5E
		NJSR				_nsub_obj_to_throw_collision_test_range20
		SBCSS				byte_6817E
		NJSR				_nsub_obj_stun_from_idxAs_test
byte_6817E:
		SUSPEND				$08
		SPR_IDX_SET			_spr_lib7_05
		SUSPEND				$08
		SPR_IDX_SET			_spr_lib7_00
		SUSPEND				$08
		NJSR				_nsub_sub10E
		NJSR				_nsub_obj_hor_delta_toggle
		SRET

; =============== O B J E C T   S C R I P T =================================
_obj_scr_24_spoon_rat_destr:
		SPR_IDX_SET			_spr_lib7_06
		NJSR				_nsub_get_obj_hp
		SBEQ				_obj_scr_common_destr
		SJSR				_ssub_common_stun_mode
		SJMPS				_obj_scr24_spoon_rat

; =============== O B J E C T   S C R I P T =================================
_obj_scr25_fork_rat:
		DESTR_PC_SET		_obj_scr_common_destr		; fork rat can be killed with throwable
		SPR_LIB_SET			_spr_lib7					; projectile in any ai mode, no beat off
		SPR_IDX_SET			_spr_lib7_07
		HP_SET				$01
		DAMAGE_SET			_OBJ_DMG_KILL				; deadly rat!
		SIZE_SET			$08,$18
		SJSR				_ssub_obj_show_wait_for_idxCs_80_set
		DELTA_X_SET			$F0
		DELTA_Y_SET			$00
		NJSR				_nsub_sub10E
		NJSR				_nsub_obj_hor_delta_toggle
byte_681B8:
		SPR_IDX_SET			_spr_lib7_08				; same 4-step path as for
		SJSRS				_ssub_fork_rat_passive_ai	; spoon rat, passive phase
		SPR_IDX_SET			_spr_lib7_09
		SJSRS				_ssub_fork_rat_passive_ai
		SPR_IDX_SET			_spr_lib7_0A
		SJSRS				_ssub_fork_rat_passive_ai
		SPR_IDX_SET			_spr_lib7_09
		SJSRS				_ssub_fork_rat_passive_ai
		NJSR				_nsub_obj_hor_move_reverse
		SJMPS				byte_681B8

; =============== S C R I P T   R O U T I N E ===============================
_ssub_fork_rat_passive_ai:
		ANIMATE_HV_SYNC								; not sure why they put this animation here
		NJSR				_nsub_obj_y_collision_test_from_players_macro_overlap_test_idx
		SBCSS				byte_681DF					; skip if player not on the same y pos
		NJSR				_nsub_obj_x_range50_test_from_players_macro_overlap_test_idx
		SBCCS				byte_681E4					; test if player get in close range
byte_681DF:
		LOOP_A				$08,_ssub_fork_rat_passive_ai	; unless loop animation as usual
		SRET
byte_681E4:
		LOOP_A_STOP										; start active phase
		LOOP_B_STOP
		NJSR				_nsub_sub10E
		NJSR				_nsub_obj_hor_delta_toggle
		BREAK				_obj_scr_fork_rat_throw		; exit sub, jump to new obj ai code

; =============== O B J E C T   S C R I P T =================================
_obj_scr_fork_rat_throw:
		SPR_IDX_SET			_spr_lib7_07				; first throw its fork
		SUSPEND				$10
		SPR_IDX_SET			_spr_lib7_0C				; animate 3 phases, throw
		SUSPEND				$10
		APU_SE_SET			_apu_mus5F
		SPR_IDX_SET			_spr_lib7_0D
		SRUN				_OBJ_TYPE_ENEMY,_obj_scr_fork_rat_projectile
		SUSPEND				$10
		SPR_IDX_SET			_spr_lib7_07				; then one more phase to release
		SUSPEND				$10
byte_68205:
		SPR_IDX_SET			_spr_lib7_08				; now cycling the active animations
		SJSRS				_ssub_fork_rat_active_ai
		SPR_IDX_SET			_spr_lib7_09
		SJSRS				_ssub_fork_rat_active_ai
		SPR_IDX_SET			_spr_lib7_0A
		SJSRS				_ssub_fork_rat_active_ai
		SPR_IDX_SET			_spr_lib7_09
		SJSRS				_ssub_fork_rat_active_ai
		SJMPS				byte_68205

; =============== S C R I P T   R O U T I N E ===============================
_ssub_fork_rat_active_ai:
		SYNC
		NJSR				_obj_move_hor_animate		; move horizontally
		NJSR				_nsub_obj_to_tile_collision_test_hor	; when tile obstacles
		SBCCS				byte_68231					; jump up on them
		NJSR				_nsub_obj_to_tile_collision_test_down	; or hop off
		SBCCS				byte_68231
		LOOP_A				$08,_ssub_fork_rat_active_ai	; else, loop 8 times and
		SRET											; return for new phase
byte_68231:
		LOOP_A_STOP
		SPR_IDX_SET			_spr_lib7_09				; jump up animation start
		DELTA_Y_SET			$C0							; set jump speed, do common code
		SJMP				_ssub_obj_wait_for_jump

; =============== S C R I P T ===============================================
_obj_scr_fork_rat_projectile:
		DESTR_PC_SET		_obj_scr_fork_rat_projectile_destr
		HP_SET				$01
		DAMAGE_SET			_OBJ_DMG_KILL				; do not fear a rat, fear its FORK!
		SIZE_SET			$08,$04						; one hit you are in the morgue
		SPR_LIB_SET			_spr_lib7
		SPR_IDX_SET			_spr_lib7_0E
		POS_Y_MOVE			$F0
		DELTA_X_SET			$30
		NJSR				_nsub_obj_hor_bounce13
		SPRITE_ON
		SJMP				_ssub_infinite_anim_sync

; =============== O B J E C T   S C R I P T =================================
_obj_scr_fork_rat_projectile_destr:
		DELTA_X_SET			$0C
		DELTA_Y_SET			$E0
		NJSR				_nsub_obj_from_idxAs_hor_delta_toggle
		SJMP				_ssub_y_parabolic_delta_infinite_anim_sync

; =============== O B J E C T   S C R I P T =================================
_obj_scr26_fake_boxA:
		DESTR_PC_SET		_obj_scr_common_destr	; like a common enemy
		POS_X_MOVE			$F8						; adjust hor pos
		SPR_LIB_SET			_spr_lib7				; select box sprite
		SPR_IDX_SET			_spr_lib7_4C
		HP_SET				$01						; one hit to destroy it
		DAMAGE_SET			_OBJ_DMG_KILL			; deadly
		SIZE_SET			$08,$0F
		SPRITE_ON
		SJSR				_ssub_obj_show_wait_for_idxCs_80_set
		NJSR				_nsub_sub10E
byte_68273:
		SYNC										; sit still and wait when player get in range
		NJSR				_nsub_obj_x_range50_test_from_players_macro_overlap_test_idx
		SBCSS				byte_68273				; also player should be on the same ground level
		NJSR				_nsub_obj_y_collision_test_from_players_macro_overlap_test_idx
		SBCSS				byte_68273
		APU_SE_SET			_apu_mus60				; box open sound
		SIZE_SET			$08,$18					; adjust sbounding box size
		SPR_IDX_SET			_spr_lib7_0F			; animate opening
		SUSPEND				$04
		SPR_IDX_SET			_spr_lib7_10
		SUSPEND				$04
		SPR_IDX_SET			_spr_lib7_11
		SUSPEND				$04
		SPR_IDX_SET			_spr_lib7_12
		SUSPEND				$08
		SPR_IDX_SET			_spr_lib7_14
		DELTA_Y_SET			$D0						; little jump up upon opening
		SUSPEND				$08
		SJSR				_ssub_obj_wait_for_jump
		DELTA_X_SET			$F0						; now set the hor speed to this object
		DELTA_Y_SET			$00						; and face to the player
		NJSR				_nsub_obj_hor_delta_toggle
byte_682A5:
		SPR_IDX_SET			_spr_lib7_13			; now repeat 4-frames running animation forever
		SJSRS				_ssub_fake_boxA_anim_sync
		SPR_IDX_SET			_spr_lib7_14
		SJSRS				_ssub_fake_boxA_anim_sync
		SPR_IDX_SET			_spr_lib7_15
		SJSRS				_ssub_fake_boxA_anim_sync
		SPR_IDX_SET			_spr_lib7_14
		SJSRS				_ssub_fake_boxA_anim_sync
		SJMPS				byte_682A5

; =============== S C R I P T   R O U T I N E ===============================
_ssub_fake_boxA_anim_sync:
		SYNC
		NJSR				_obj_move_hor_animate					; move object horizontally
		NJSR				_nsub_obj_to_tile_collision_test_hor	; keep tracking of obstacles
		SBCCS				byte_682D1
		NJSR				_nsub_obj_to_tile_collision_test_down	; also floor tiles
		SBCCS				byte_682D1
		LOOP_A				$08,_ssub_fake_boxA_anim_sync			; animate for 8 frames
		SRET
byte_682D1:
		LOOP_A_STOP													; when any obstacle detected, do jump
		SPR_IDX_SET			_spr_lib7_14
		DELTA_Y_SET			$C0
		SJMP				_ssub_obj_wait_for_jump

; =============== O B J E C T   S C R I P T =================================
_obj_scr27_honey_bee:
		DESTR_PC_SET		_obj_scr_common_destr					; regular enemy
		SPR_LIB_SET			_spr_lib7
		SPR_IDX_SET			_spr_lib7_16							; select sprite
		HP_SET				$01
		DAMAGE_SET			_OBJ_DMG_KILL							; regular damage and deadly status
		SIZE_SET			$08,$10
		DELTA_X_SET			$10										; move fast horizontally with small
		DELTA_Y_SET			$04										; movement down, so move diagonally
		SJSR				_ssub_obj_show_wait_for_idxCs_80_set
		NJSR				_nsub_sub10E
		NJSR				_nsub_obj_hor_delta_toggle
byte_682F4:
		SPR_IDX_SET			_spr_lib7_16							; buzz animation and se
		APU_SE_SET			_apu_mus61								; while moving
		SJSR				_ssub_anim_sync_frames3
		SPR_IDX_SET			_spr_lib7_17
		APU_SE_SET			_apu_mus61
		SJSR				_ssub_anim_sync_frames3
		LOOP_A				$08,byte_682F4
byte_68306:
		SPR_IDX_SET			_spr_lib7_18							; then stop and spit some honey anim
		SJSRS				_ssub_honey_bee_anim_delay_with_se
		SPR_IDX_SET			_spr_lib7_19
		SJSRS				_ssub_honey_bee_anim_delay_with_se
		LOOP_A				$02,byte_68306
byte_68314:
		SPR_IDX_SET			_spr_lib7_1A							; another part of anim
		SJSRS				_ssub_honey_bee_anim_delay_with_se
		SPR_IDX_SET			_spr_lib7_1B
		SJSRS				_ssub_honey_bee_anim_delay_with_se
		LOOP_A				$02,byte_68314
		SRUN				_OBJ_TYPE_STUNB,_obj_scr_honey_bee_projectile	; release projectile down
byte_68326:
		SPR_IDX_SET			_spr_lib7_16							; little more still animations
		SJSRS				_ssub_honey_bee_anim_delay_with_se		; then continue to move, repeat
		SPR_IDX_SET			_spr_lib7_17
		SJSRS				_ssub_honey_bee_anim_delay_with_se
		LOOP_A				$02,byte_68326
		NJSR				_nsub_complement_y_deltas				; invert diagonal moving, so it will be
		SJMPS				byte_682F4								; saw-lipe pattern

; =============== S C R I P T   R O U T I N E ===============================
_ssub_honey_bee_anim_delay_with_se:
		APU_SE_SET			_apu_mus61
		SUSPEND				$03
		SRET

; =============== S C R I P T ===============================================
_obj_scr_honey_bee_projectile:
		NJSR				_nsub_obj_idxCs_80_set					; projectile does stunning
		POS_Y_MOVE			$08
		HP_SET				$01
		DAMAGE_SET			_OBJ_DMG_STUN							; with positive delta set
		SIZE_SET			$02,$04									; it will fall straight down
		SPR_LIB_SET			_spr_lib7								; until reach out of screen area
		SPR_IDX_SET			_spr_lib7_1C
		DELTA_Y_SET			$08
		SPRITE_ON
		SJMP				_ssub_y_parabolic_delta_infinite_anim_sync

; =============== O B J E C T   S C R I P T =================================
_obj_scr28_green_ceiling_bat:
		DESTR_PC_SET		_obj_scr_common_destr				; usual initialization
		POS_Y_MOVE			$FC
		SPR_LIB_SET			_spr_lib7
		SPR_IDX_SET			_spr_lib7_28
		SIZE_SET			$08,$18
		HP_SET				$01
		DAMAGE_SET			_OBJ_DMG_KILL
		SJSR				_ssub_obj_show_wait_for_idxCs_80_set
		NJSR				_nsub_sub10E
byte_6836B:
		NJSR_SYNC			_nsub_obj_x_range60_test_from_players_macro_overlap_test_idx
		SBCSS				byte_6836B							; wait for player in hor range
		TIMER_B_SET			$00									; take off direction
byte_68373:
		NJSR				_nsub_sub10E						; animate prepare to follow target
		SJSRS				_ssub_green_bat_flying_anim
		LOOP_A				$03,byte_68373
		NJSR				_nsub_sub111						; lock on target
		TARGET_LOCK			$20
byte_68382:
		TIMER_B_SET			$FF									; now animate following target
		SJSRS				_ssub_green_bat_flying_anim
		SJMPS				byte_68382

; =============== O B J E C T   S C R I P T =================================
_obj_scr29_green_floor_bat:
		DESTR_PC_SET		_obj_scr_common_destr				; init same as for seiling rat
		SPR_LIB_SET			_spr_lib7							; as most of other objects also
		SPR_IDX_SET			_spr_lib7_26
		SIZE_SET			$08,$18
		HP_SET				$01
		DAMAGE_SET			_OBJ_DMG_KILL
		SJSR				_ssub_obj_show_wait_for_idxCs_80_set	; floor bat does not stand still
		DELTA_X_SET			$F0									; but moving constantly horizontally
		DELTA_Y_SET			$00
		NJSR				_nsub_sub10E
		NJSR				_nsub_obj_hor_delta_toggle
byte_683A5:
		SPR_IDX_SET			_spr_lib7_25
		SJSRS				_ssub_green_gloor_bat_ai
		SPR_IDX_SET			_spr_lib7_26
		SJSRS				_ssub_green_gloor_bat_ai
		SPR_IDX_SET			_spr_lib7_27
		SJSRS				_ssub_green_gloor_bat_ai
		SPR_IDX_SET			_spr_lib7_26
		SJSRS				_ssub_green_gloor_bat_ai
		NJSR				_nsub_obj_hor_move_reverse			; walk back after one cycle
		SJMPS				byte_683A5

; =============== S C R I P T   R O U T I N E ===============================
_ssub_green_gloor_bat_ai:
		SYNC													; while moving horizontally
		NJSR				_obj_move_hor_animate				; wait for player get in range
		NJSR				_nsub_obj_x_range60_test_from_players_macro_overlap_test_idx
		SBCCS				byte_683CE
		LOOP_A				$08,_ssub_green_gloor_bat_ai
		SRET
byte_683CE:
		LOOP_A_STOP
		TIMER_A_SET			$30									; immediately start to take off
		TARGET_LOCK			$20									; and lock on target
		TIMER_B_SET			$FF
byte_683D5:
		SJSRS				_ssub_green_bat_flying_anim			; common anims for all bats
		LOOP_A				$02,byte_683D5
		NJSR				_nsub_get_rand_flags				; add an extra random take off cycle
		SBPLS				byte_683E5							; to appear higher sometimes
		SJSRS				_ssub_green_bat_flying_anim
byte_683E5:
		NJSR				_nsub_sub10E						; when target point reached,
		DELTA_X_SET			$20									; change movement to horiaontal
		NJSR				_nsub_obj_hor_delta_toggle			; without targeting
byte_683ED:
		APU_SE_SET			_apu_mus64
byte_683EF:
		SPR_IDX_SET			_spr_lib7_29
byte_683F1:
		NJSR_SYNC			_nsub_obj_hor_move_with_wave_patternt	; also animate in wavy pattern vertically
		LOOP_A				$04,byte_683F1
		SPR_IDX_SET			_spr_lib7_2A
byte_683FA:
		NJSR_SYNC			_nsub_obj_hor_move_with_wave_patternt	; repeat untill out of the screen
		LOOP_A				$04,byte_683FA
		LOOP_B				$02,byte_683EF
		SJMPS				byte_683ED

; =============== S C R I P T   R O U T I N E ===============================
_ssub_green_bat_flying_anim:
		APU_SE_SET			_apu_mus64							; alying anim with following target
		SIZE_SET			$0C,$10
		SPR_IDX_SET			_spr_lib7_29
		SJSRS				_ssub_green_bat_target_follow_sync
		SPR_IDX_SET			_spr_lib7_2A
		SJSRS				_ssub_green_bat_target_follow_sync
		SPR_IDX_SET			_spr_lib7_29
		SJSRS				_ssub_green_bat_target_follow_sync
		SPR_IDX_SET			_spr_lib7_2A

; !FALLTHROUGH!

; =============== S C R I P T   R O U T I N E ===============================
_ssub_green_bat_target_follow_sync:
		TARGET_FOLLOW											; routine to optimize script for size
		SYNC
		LOOP_B				$04,_ssub_green_bat_target_follow_sync
		SRET

; =============== O B J E C T   S C R I P T =================================
_obj_scr2A_pink_fish:
		DESTR_PC_SET		_obj_scr_common_destr				; disable movement
		NJSR				_scr_flips_04_set
		SPR_LIB_SET			_spr_lib7
		HP_SET				$01
		DAMAGE_SET			_OBJ_DMG_KILL
		SIZE_SET			$08,$20
byte_68434:
		SPRITE_ON
		APU_SE_SET			_apu_mus65							; splash sound
		SPR_IDX_SET			_spr_lib7_1D						; splash anim display
		SUSPEND				$04
		SPR_IDX_SET			_spr_lib7_1E
		SUSPEND				$04
		NJSR				_nsub_obj_y_lo_maskF0				; trim y pos by macro-tile grid
		NJSR				_scr_flips_04_clear					; enable movement
		DELTA_Y_SET			$B7									; set jump up
		SJSRS				_ssub_pink_fish_anim
		DELTA_Y_SET			$00
		SJSRS				_ssub_pink_fish_anim				; now we fall down
		NJSR				_scr_flips_04_set					; when hit the water, disable again
		NJSR				_nsub_obj_y_lo_maskF0
		APU_SE_SET			_apu_mus65							; splash se and animation one more time
		SPR_IDX_SET			_spr_lib7_23
		SUSPEND				$04
		SPR_IDX_SET			_spr_lib7_24
		SUSPEND				$04
		SPRITE_OFF												; disable obj
		SUSPEND				$F0
		NJSR				_nsub_get_rand_flags				; now with probability 50/50 jump again
		SBPLS				byte_68434							; or suspend for 2 seconds
		SUSPEND				$78
		SJMPS				byte_68434

; =============== S C R I P T   R O U T I N E ===============================
_ssub_pink_fish_anim:
		SPR_IDX_SET			_spr_lib7_1F
		SJSRS				_ssub_pink_fish_move_sync
		SPR_IDX_SET			_spr_lib7_20
		SJSRS				_ssub_pink_fish_move_sync	; two frame cycle twice
		LOOP_A				$02,_ssub_pink_fish_anim	; when finish to jump up
		FLIP_H_TOGGLE
		FLIP_V_TOGGLE								; mirror sprite to return back
		SRET

; =============== S C R I P T   R O U T I N E ===============================
_ssub_pink_fish_move_sync:
		SYNC											; each cycle 9 frames long
		DELTA_Y_INC									; vertical move with acceleration
		DELTA_Y_INC
		NJSR				_obj_vert_anim
		LOOP_B				$09,_ssub_pink_fish_move_sync
		SRET

; =============== O B J E C T   S C R I P T =================================
_obj_scr2B_fake_boxB:
		POS_X_MOVE			$F8								; adjust hor position
		DESTR_PC_SET		_obj_scr_fake_boxB_destr		; set collision handler
_sloc_fake_boxB_main_loop:
		SPR_LIB_SET			_spr_lib7						; set small box sprite
		SPR_IDX_SET			_spr_lib7_4C
		HP_SET				$02
		DAMAGE_SET			_OBJ_DMG_KILL					; deadly
		SPRITE_ON
byte_68497:
		SIZE_SET			$08,$0F							; size 16x15
byte_6849A:
		SJSRS				_ssub_fake_boxB_sync_anim		; anim and tile collision test
		NJSR				_nsub_obj_y_collision_test_from_players_macro_overlap_test_idx
		SBCSS				byte_6849A						; test if player is on the same line
		NJSR				_nsub_obj_x_range30_test_from_players_macro_overlap_test_idx
		SBCSS				byte_6849A						; test if player in close range
		NJSR				_nsub_sub10E
byte_684AC:
		POS_Y_MOVE			$FE								; player appears
		SJSRS				_ssub_fake_boxB_sync_anim06		; start shaking, 6 frames up
		POS_Y_MOVE			$02								; 6 frames down shifts
		APU_SE_SET			_apu_mus60						; play box bouncing sound
		SJSRS				_ssub_fake_boxB_sync_anim06		; wait for more 12 frames
		SJSRS				_ssub_fake_boxB_sync_anim06
		LOOP_A				$03,byte_684AC					; repeat 3 times
		NJSR				_nsub_sub10E
		SPR_IDX_SET			_spr_lib7_2B					; now open the box anim
		SJSRS				_ssub_fake_boxB_sync_anim06
		SPR_IDX_SET			_spr_lib7_2C
		SJSRS				_ssub_fake_boxB_sync_anim06
		SPR_IDX_SET			_spr_lib7_2D
		SJSRS				_ssub_fake_boxB_sync_anim06
		SPR_IDX_SET			_spr_lib7_2E
		SRUN				_OBJ_TYPE_EBULLET,_obj_scr_fake_box_head	; add additional projectile-like object
		SBCSS				byte_6849A						; to expand damaging bounding box
		NJSR				_nsub_obj_to_obj_idxCs_link		; link new object to current object
		SIZE_SET			$08,$28
byte_684E0:
		SJSRS				_ssub_fake_boxB_sync_anim06		; now animate snake tongue
		SPR_IDX_SET			_spr_lib7_2F
		SJSRS				_ssub_fake_boxB_sync_anim06
		SPR_IDX_SET			_spr_lib7_30
		LOOP_A				$14,byte_684E0
		NJSR				_nsub_obj_disable_from_idxCs_40_flag	; when over, close box back
		SPR_IDX_SET			_spr_lib7_2E
		SJSRS				_ssub_fake_boxB_sync_anim06
		SPR_IDX_SET			_spr_lib7_2D
		SJSRS				_ssub_fake_boxB_sync_anim06
		SPR_IDX_SET			_spr_lib7_2C
		SJSRS				_ssub_fake_boxB_sync_anim06
		SPR_IDX_SET			_spr_lib7_2B
		SJSRS				_ssub_fake_boxB_sync_anim06
		SPR_IDX_SET			_spr_lib7_4C
		SIZE_SET			$08,$10							; shring object size
byte_6850A:
		SJSRS				_ssub_fake_boxB_sync_anim06		; delay between cycles
		LOOP_A				$0A,byte_6850A					; then repeat algo again
		SJMPS				byte_68497

; =============== S C R I P T   R O U T I N E ===============================
; NOTE, as against the other fake box object, this one can fall down to the ground.
; however, there is no such objects in the game that positioned above the ground
; and may fall from somewhere...
;
_ssub_fake_boxB_sync_anim:
		SYNC								; sync with core and perform ground collision test
		NJSR				_nsub_obj_to_tile_collision_test_down
		SBCSS				byte_6851E		; since vert delta is zero, when no ground under...
		SJSR				_ssub_obj_wait_for_jump		; ...jump call causes falling down
byte_6851E:
		SRET

; =============== S C R I P T   R O U T I N E ===============================
_ssub_fake_boxB_sync_anim06:
		SJSRS				_ssub_fake_boxB_sync_anim
		LOOP_B				$06,_ssub_fake_boxB_sync_anim06
		SRET

; =============== O B J E C T   S C R I P T =================================
_obj_scr_fake_boxB_destr:
		NJSR				_nsub_obj_disable_from_idxCs_40_flag	; disable special link
		SPR_IDX_SET			_spr_lib7_31			; choose stunned sprite
		SIZE_SET			$08,$1C
		NJSR				_nsub_get_obj_hp		; if hp still not zero go stun
		SBEQ				_obj_scr_common_destr	; or go to the common destructor
		SJSR				_ssub_common_stun_mode	; if exit blinking mode, then no one grab it
		SJMP				_sloc_fake_boxB_main_loop	; return back to main loop

; =============== S C R I P T ===============================================
_obj_scr_fake_box_head:
		HP_SET				$FF					; not sure why obj in STUN mode
		DAMAGE_SET			_OBJ_DMG_STUN		; still damages like KILL, seems HP=$FF causes it
		SIZE_SET			$08,$10
byte_68542:
		NJSR				_nsub_obj_linked_idxCs_follow	; follow the main object position
		POS_Y_MOVE			$18					; adjust to head area
		NJSR_SYNC			_nsub_obj_hor_bounce0C	; invisible object bouncing... odd
		SJMPS				byte_68542

; =============== O B J E C T   S C R I P T =================================
_obj_scr2D_candle_dancing:
		DESTR_PC_SET		_obj_scr2D_candle_dancing_destr
		SPR_LIB_SET			_spr_lib7
		SPR_IDX_SET			_spr_lib7_32		; usual init with special collision handler
		HP_SET				$02
		DAMAGE_SET			_OBJ_DMG_KILL		; two hp enemy, also may be stunned
		SIZE_SET			$05,$20
		SJSR				_ssub_obj_show_wait_for_idxCs_80_set
		NJSR				_nsub_sub10E
_sloc_68561:
		SJSRS				_ssub_candle_dancing_rotate_up	; first of all it's rotate
		DELTA_X_SET			$E0									; with targeting
		NJSR				_nsub_obj_hor_delta_toggle			; then start to move horizontally
byte_68569:
		SJSRS				_ssub_candle_dancing_rotate_anim	; moving animation for 4 cycles
		LOOP_A				$04,byte_68569
		SJSRS				_ssub_candle_dancing_rotate_down	; slow rotate and retarget
		DELTA_X_SET			$F0
		DELTA_Y_SET			$CF
		SJSRS				_ssub_candle_dancing_jump_up		; now jump up to the left once
		NJSR				_nsub_obj_hor_move_reverse
		DELTA_X_SET			$10									; and final jump to the right
		DELTA_Y_SET			$CF
		SJSRS				_ssub_candle_dancing_jump_up
		SJMPS				_sloc_68561							; repeat

; =============== S C R I P T   R O U T I N E ===============================
_ssub_candle_dancing_rotate_up:
		DELTA_X_SET			$00
		TIMER_B_SET			$18									; timer values are latched values for
		SJSRS				_ssub_candle_dancing_rotate_anim	; loopB counter overwrite to increase
		TIMER_B_SET			$1A									; or decrease the loops count
		SJSRS				_ssub_candle_dancing_rotate_anim
		TIMER_B_SET			$1C
		SJSRS				_ssub_candle_dancing_rotate_anim
		TIMER_B_SET			$1E
		SJMPS				_ssub_candle_dancing_rotate_anim

; =============== S C R I P T   R O U T I N E ===============================
_ssub_candle_dancing_rotate_down:
		DELTA_X_SET			$00
		TIMER_B_SET			$1C
		SJSRS				_ssub_candle_dancing_rotate_anim
		TIMER_B_SET			$1A
		SJSRS				_ssub_candle_dancing_rotate_anim
		TIMER_B_SET			$18
		SJMPS				_ssub_candle_dancing_rotate_anim

; =============== S C R I P T   R O U T I N E ===============================
_ssub_candle_dancing_rotate_anim:
		SJSRS				_ssub_candle_dancing_sync_ai	; on every animation frame
		SPR_IDX_SET			_spr_lib7_33					; candle can track obstacles and do
		SJSRS				_ssub_candle_dancing_sync_ai	; a number of neccessary jumps or
		SPR_IDX_SET			_spr_lib7_34					; jump offs in addition to scripted ones
		SJSRS				_ssub_candle_dancing_sync_ai
		SPR_IDX_SET			_spr_lib7_35
		SJSRS				_ssub_candle_dancing_sync_ai
		SPR_IDX_SET			_spr_lib7_36
		SJSRS				_ssub_candle_dancing_sync_ai
		SPR_IDX_SET			_spr_lib7_37
		SJSRS				_ssub_candle_dancing_sync_ai
		SPR_IDX_SET			_spr_lib7_32
		SRET

; =============== S C R I P T   R O U T I N E ===============================
_ssub_candle_dancing_jump_up:
		NJSR				_nsub_obj_hor_delta_toggle		; final jump up attack
		SPR_IDX_SET			_spr_lib7_38
		SUSPEND				$06
		SPR_IDX_SET			_spr_lib7_39
		SUSPEND				$06
		SPR_IDX_SET			_spr_lib7_3A
		SUSPEND				$06
		TIMER_B_SET			$1E
byte_685DE:
		SJSRS				_ssub_candle_dancing_rotate_anim; wait for final land after jump up
		NJSR				_nsub_get_obj_y_delta
		SBNES				byte_685DE
		DELTA_X_SET			$00
		SRET

; =============== S C R I P T   R O U T I N E ===============================
_ssub_candle_dancing_sync_ai:
		NJSR				_nsub_loopB_reload_from_timerBs	; here reload specified in timerBs loobB counter
		NJSR				_nsub_get_obj_y_delta		; start crunching se when jump up
		SBPLS				byte_685F5
		APU_SE_SET			_apu_mus6B
byte_685F5:
		SYNC
		NJSR				_nsub_get_obj_y_delta		; then not jumping, go horizontal
		SBNES				_sloc_68613					; or else do vertical anim
		NJSR				_obj_move_hor_animate		; animate unless see any obstacle
		NJSR				_nsub_obj_to_tile_collision_test_hor
		SBCSS				byte_6860A					; then start to jump up
		DELTA_Y_SET			$CF
		SJMPS				byte_68638
byte_6860A:
		NJSR				_nsub_obj_to_tile_collision_test_down	; if no obstacles, test if ground is over
		SBCCS				byte_68636					; if yes, fall down
		SJMPS				byte_68638					; otherwise continue moving
_sloc_68613:
		NJSR				_obj_move_hor_animate		; hor move while jump up
		NJSR				_nsub_obj_to_tile_collision_test_hor	; also test hor collisions to jum more if any
		NJSR				_nsub_obj_jump_up_anim
		NJSR				_nsub_get_obj_y_delta		; if sump up in progress, just animate
		SBMIS				byte_6862D					; or else start to test ground collisions
		NJSR				_obj_to_tile_grid_collision_test_down
		SBCCS				byte_68638					; stop if ground detected
		DELTA_Y_SET			$00
		SJMPS				byte_68638
byte_6862D:
		NJSR				_obj_vert_anim				; can't also jump up inside obstacles
		NJSR				_nsub_obj_to_tile_collision_test_up
		SBCSS				byte_68638
byte_68636:
		DELTA_Y_SET			$01
byte_68638:
		LOOP_B				$20,byte_685F5				; redefined with the timerBs value here
		SRET

; =============== S U B R O U T I N E =======================================
_nsub_loopB_reload_from_timerBs:
		LDA		_obj_timerBs,X
		STA		_scr_loopsB,X
		RTS

; =============== O B J E C T   S C R I P T =================================
_obj_scr2D_candle_dancing_destr:
		SPR_IDX_SET			_spr_lib7_3B
		NJSR				_nsub_get_obj_hp
		SBEQ				_obj_scr_common_destr
		SIZE_SET			$05,$18
		SJSR				_ssub_common_stun_init
		DELTA_X_SET			$00
		NJSR				_scr_flips_04_clear
byte_68657:
		SPR_IDX_SET			_spr_lib7_3B
		SJSRS				_ssub_6867F
		SPR_IDX_SET			_spr_lib7_3C
		SJSRS				_ssub_6867F
		LOOP_B				$14,byte_68657
		NJSR				_nsub_obj_blink_set
byte_68668:
		SPR_IDX_SET			_spr_lib7_3B
		SJSRS				_ssub_6867F
		SPR_IDX_SET			_spr_lib7_3C
		SJSRS				_ssub_6867F
		LOOP_B				$05,byte_68668
		NJSR				_nsub_obj_blink_clear
		NJSR				_nsub_obj_disable_from_idxCs_40_flag
		SJMP				_obj_scr2D_candle_dancing

; =============== S C R I P T   R O U T I N E ===============================
_ssub_6867F:
		SYNC
		NJSR				_nsub_get_obj_idxBs
		SBMIS				byte_68694
		NJSR				_nsub_obj_to_tile_collision_test_down
		SBCSS				byte_6868F
		SJSR				_ssub_obj_jump_calcs
byte_6868F:
		LOOP_A				$0C,_ssub_6867F
		SRET
byte_68694:
		SPR_IDX_SET			_spr_lib7_5C
		SJSR				_ssub_68102
		DAMAGE_SET			_OBJ_DMG_STUN
		DELTA_X_SET			$C0
		NJSR				_nsub_sub11B
		NJSR				_nsub_sub11C
		NJSR				_nsub_obj_type_change_stunA
		SJMP				_ssub_infinite_anim_sync

; =============== O B J E C T   S C R I P T =================================
_obj_scr2E_ghost_dogA:
		SJSR				_ssub_wait_for_idxCs_80_set
byte_686AC:
		NJSR_SYNC			_nsub_sub11E
		SBNES				byte_686AC
		NJSR				_nsub_cmp40_obj_x_lo_pos
		SBCSS				byte_686AC
		NJSR				_nsub_cmpC0_obj_x_lo_pos
		SBCCS				byte_686AC
		SRUN				_OBJ_TYPE_ENEMY,_obj_scr_103
		SUSPEND				$3D
		SJMPS				byte_686AC

; =============== S C R I P T ===============================================
_obj_scr_103:
		SUSPEND				$1E
		DESTR_PC_SET		_obj_scr_common_destr
		SPR_LIB_SET			_spr_lib9
		HP_SET				$01
		DAMAGE_SET			_OBJ_DMG_KILL
		SPRITE_ON
		SIZE_SET			$08,$14
		DELTA_X_SET			$10
		POS_X_SET			$80,$00
		NJSR				_nsub_sub001
		NJSR				_nsub_obj_hor_bounce7E
		NJSR				_nsub_obj_hor_move_reverse
		NJSR				_nsub_obj_hor_delta_toggle
byte_686E7:
		SPR_IDX_SET			_spr_lib9_00
		SJSRS				_ssub_6870C
		SPR_IDX_SET			_spr_lib9_01
		SJSRS				_ssub_6870C
		SPR_IDX_SET			_spr_lib9_02
		SJSRS				_ssub_6870C
		LOOP_A				$03,byte_686E7
		SPR_IDX_SET			_spr_lib9_03
		SJSRS				_ssub_6870C
		SPR_IDX_SET			_spr_lib9_04
		SJSRS				_ssub_6870C
		SPR_IDX_SET			_spr_lib9_05
		SJSRS				_ssub_6870C
		SJMPS				byte_686E7

; =============== S C R I P T   R O U T I N E ===============================
_ssub_6870C:
		NJSR_SYNC			_nsub_obj_hor_move_with_wave_patternt
		LOOP_A				$04,_ssub_6870C
		SRET

; =============== S U B R O U T I N E =======================================
_nsub_sub001:
		LDY		_players_macro_overlap_test_idx
		LDA		_obj_flips,Y
		AND		#_OBJ_HFLIP
		ORA		_obj_flips,X
		STA		_obj_flips,X
		RTS

; =============== O B J E C T   S C R I P T =================================
_obj_scr2F_ghost_dogB:
		NJSR_SYNC			_nsub_sub11E
		SBEQS				byte_68729
		KILL
byte_68729:
		DESTR_PC_SET		_obj_scr_common_destr
		SPR_LIB_SET			_spr_lib9
		SPR_IDX_SET			_spr_lib9_00
		HP_SET				$01
		DAMAGE_SET			_OBJ_DMG_KILL
		SIZE_SET			$08,$14
		SJSR				_ssub_obj_show_wait_for_idxCs_80_set
		NJSR				_nsub_sub10E
		TIMER_B_SET			$20
byte_6873F:
		SPR_IDX_SET			_spr_lib9_00
		SJSRS				_ssub_68751
		SPR_IDX_SET			_spr_lib9_01
		SJSRS				_ssub_68751
		SPR_IDX_SET			_spr_lib9_02
		SJSRS				_ssub_68751
		SJMPS				byte_6873F

; =============== S C R I P T   R O U T I N E ===============================
_ssub_68751:
		NJSR				_nsub_sub123
		NJSR				_nsub_sub124
		NJSR				_nsub_obj_hflip_test
		SBNES				byte_68763
		NJSR				_nsub_inc_vars19
		SJMPS				byte_68766
byte_68763:
		NJSR				_nsub_dec_vars19
byte_68766:
		NJSR				_obj_vert_anim
		ANIMATE_HV_SYNC
		NJSR				_nsub_obj_x_range40_test_from_players_macro_overlap_test_idx
		SBCSS				byte_68773
		BREAK				byte_68778
byte_68773:
		LOOP_B				$04,_ssub_68751
		SRET
byte_68778:
		TARGET_LOCK			$18
		NJSR				_nsub_sub10E
		NJSR				_nsub_sub111
		LOOP_A_STOP
byte_68781:
		SPR_IDX_SET			_spr_lib9_00
		SJSRS				_ssub_687A2
		SPR_IDX_SET			_spr_lib9_01
		SJSRS				_ssub_687A2
		SPR_IDX_SET			_spr_lib9_02
		SJSRS				_ssub_687A2
		SPR_IDX_SET			_spr_lib9_03
		SJSRS				_ssub_687A2
		SPR_IDX_SET			_spr_lib9_04
		SJSRS				_ssub_687A2
		SPR_IDX_SET			_spr_lib9_05
		SJSRS				_ssub_687A2
		SJMPS				byte_68781

; =============== S C R I P T   R O U T I N E ===============================
_ssub_687A2:
		SYNC
		TIMER_B_SET			$FF
		TARGET_FOLLOW
		LOOP_A				$04,_ssub_687A2
		SRET

; =============== O B J E C T   S C R I P T =================================
_obj_scr2C_sailor_monkey:
		DESTR_PC_SET		_obj_scr_common_destr
		SPR_LIB_SET			_spr_lib7
		SPR_IDX_SET			_spr_lib7_4D
		HP_SET				$02
		DAMAGE_SET			_OBJ_DMG_KILL
		SIZE_SET			$0C,$20
		SJSR				_ssub_obj_show_wait_for_idxCs_80_set
		DELTA_Y_SET			$10
byte_687BE:
		APU_SE_SET			_apu_mus68
byte_687C0:
		NJSR_SYNC			_obj_vert_anim
		LOOP_A				$08,byte_687C0
		LOOP_B				$04,byte_687BE
		NJSR				_nsub_complement_y_deltas
		NJSR				_nsub_get_rand_scale3
		SSWITCH				_tmp_ptrE+1
		SCASE				byte_687BE
		SCASE				byte_687DA
		SCASE				byte_687DF
byte_687DA:
		SUSPEND				$78
		SJMPS				byte_687BE
byte_687DF:
		SPR_IDX_SET			_spr_lib7_4E
		SUSPEND				$10
		SPR_IDX_SET			_spr_lib7_4F
		SRUN				_OBJ_TYPE_EBULLET,_obj_scr_104
		SUSPEND				$10
		SPR_IDX_SET			_spr_lib7_4E
		SUSPEND				$10
		SPR_IDX_SET			_spr_lib7_4F
		SRUN				_OBJ_TYPE_EBULLET,_obj_scr_105
		SUSPEND				$10
		SPR_IDX_SET			_spr_lib7_4D
		SUSPEND				$10
		SJMPS				byte_687BE

; =============== S C R I P T ===============================================
_obj_scr_104:
		DELTA_X_SET			$18
		SJMPS				byte_68805

; =============== S C R I P T ===============================================
_obj_scr_105:
		DELTA_X_SET			$0C
byte_68805:
		POS_X_MOVE			$1C
		POS_Y_MOVE			$F8
		NJSR				_nsub_obj_idxCs_80_set
		SPR_LIB_SET			_spr_lib7
		DELTA_Y_SET			$00
		SPRITE_ON
		HP_SET				$01
		DAMAGE_SET			_OBJ_DMG_KILL
		SIZE_SET			$06,$08
byte_68818:
		SPR_IDX_SET			_spr_lib7_50
byte_6881A:
		ANIMATE_HV_SYNC
		DELTA_Y_INC
		DELTA_Y_INC
		LOOP_A				$08,byte_6881A
		SPR_IDX_SET			_spr_lib7_51
byte_68823:
		ANIMATE_HV_SYNC
		DELTA_Y_INC
		DELTA_Y_INC
		LOOP_A				$08,byte_68823
		SJMPS				byte_68818

; =============== O B J E C T   S C R I P T =================================
_obj_scr30_penguin:
		DESTR_PC_SET		_obj_scr_penguin_destr
		SPR_LIB_SET			_spr_lib7
		SPR_IDX_SET			_spr_lib7_53
		HP_SET				$02
		DAMAGE_SET			_OBJ_DMG_KILL
		SIZE_SET			$0A,$20
		SJSR				_ssub_obj_show_wait_for_idxCs_80_set
		NJSR				_nsub_sub10E
byte_68841:
		DELTA_X_SET			$18
		SPR_IDX_SET			_spr_lib7_52
		SJSRS				_ssub_68867
		DELTA_X_SET			$10
		SPR_IDX_SET			_spr_lib7_53
		SJSRS				_ssub_68867
		DELTA_X_SET			$E8
		SPR_IDX_SET			_spr_lib7_54
		SJSRS				_ssub_68867
		DELTA_X_SET			$F0
		SPR_IDX_SET			_spr_lib7_53
		SJSRS				_ssub_68867
byte_6885D:
		SPR_IDX_SET			_spr_lib7_53
		SUSPEND				$1E
		NJSR				_nsub_obj_hor_move_reverse
		SJMPS				byte_68841

; =============== S C R I P T   R O U T I N E ===============================
_ssub_68867:
		LOOP_A_STOP
		APU_SE_SET			_apu_mus40
		NJSR				_nsub_obj_hor_delta_toggle
byte_6886D:
		SYNC
		NJSR				_obj_move_hor_animate
		NJSR				_nsub_obj_to_tile_collision_test_hor
		SBCSS				byte_6887A
		BREAK				byte_6885D
byte_6887A:
		NJSR				_nsub_obj_to_tile_collision_test_down
		SBCC				_ssub_obj_wait_for_jump
		LOOP_A				$0E,byte_6886D
		NJSR				_nsub_obj_x_range30_test_from_players_macro_overlap_test_idx
		SBCCS				byte_6888B
		SRET
byte_6888B:
		SPR_IDX_SET			_spr_lib7_55
		DELTA_X_SET			$30
		NJSR				_nsub_sub10E
		NJSR				_nsub_obj_hor_delta_toggle
byte_68895:
		SYNC
		NJSR				_obj_move_hor_animate
		NJSR				_nsub_obj_to_tile_collision_test_hor
		SBCCS				byte_688A9
		NJSR				_nsub_obj_to_tile_collision_test_down
		SBCC				_ssub_obj_wait_for_jump
		LOOP_A				$20,byte_68895
byte_688A9:
		BREAK				byte_68841

; =============== O B J E C T   S C R I P T =================================
_obj_scr_penguin_destr:
		SPR_IDX_SET			_spr_lib7_56
		NJSR				_nsub_get_obj_hp
		SBEQ				_obj_scr_common_destr
		SJSR				_ssub_common_stun_mode
		SJMP				_obj_scr30_penguin

; =============== O B J E C T   S C R I P T =================================
_obj_scr31_ski_rat:
		DESTR_PC_SET		_obj_scr_common_destr
		SPR_LIB_SET			_spr_lib7
		SPR_IDX_SET			_spr_lib7_57
		SIZE_SET			$0C,$18
		HP_SET				$01
		DAMAGE_SET			_OBJ_DMG_KILL
		SJSR				_ssub_obj_show_wait_for_idxCs_80_set
		NJSR				_nsub_sub10E
byte_688CE:
		DELTA_X_SET			$E0
		DELTA_Y_SET			$00
		NJSR				_nsub_obj_hor_delta_toggle
		APU_SE_SET			_apu_mus41
		SPR_IDX_SET			_spr_lib7_57
byte_688D9:
		SJSRS				_ssub_688F8
		NJSR				_nsub_obj_x_range30_test_from_players_macro_overlap_test_idx
		SBCCS				byte_6890C
		LOOP_A				$08,byte_688D9
		SPR_IDX_SET			_spr_lib7_58
byte_688E8:
		SJSRS				_ssub_688F8
		NJSR				_nsub_obj_x_range30_test_from_players_macro_overlap_test_idx
		SBCCS				byte_6890C
		LOOP_A				$08,byte_688E8
		SJMPS				byte_688CE

; =============== S C R I P T   R O U T I N E ===============================
_ssub_688F8:
		SYNC
		NJSR				_obj_move_hor_animate
		NJSR				_nsub_obj_to_tile_collision_test_hor
		SBCSS				byte_68905
		NJSR				_nsub_obj_hor_move_reverse
byte_68905:
		NJSR				_nsub_obj_to_tile_collision_test_down
		SBCC				_ssub_obj_wait_for_jump
		SRET
byte_6890C:
		DELTA_Y_SET			$C0
		SJSR				_ssub_obj_wait_for_jump
byte_68911:
		NJSR				_obj_move_hor_animate
		NJSR				_nsub_obj_to_tile_collision_test_hor
		NJSR				_nsub_sub12C
		NJSR_SYNC			_nsub_get_obj_x_delta
		SBNES				byte_68911
		SUSPEND				$0A
		NJSR				_nsub_obj_hor_move_reverse
		DELTA_X_SET			$E0
		DELTA_Y_SET			$00
		NJSR				_nsub_obj_hor_delta_toggle
byte_6892C:
		APU_SE_SET			_apu_mus41
		SPR_IDX_SET			_spr_lib7_57
byte_68930:
		SJSRS				_ssub_688F8
		LOOP_A				$08,byte_68930
		SPR_IDX_SET			_spr_lib7_58
byte_68939:
		SJSRS				_ssub_688F8
		LOOP_A				$08,byte_68939
		SJMPS				byte_6892C

; =============== O B J E C T   S C R I P T =================================
_obj_scr32_icicle:
		SUSPEND				$B4
		SRUN				_OBJ_TYPE_EBULLET,_obj_scr_106
		SJMPS				_obj_scr32_icicle

; =============== S C R I P T ===============================================
_obj_scr_106:
		NJSR				_nsub_obj_idxCs_80_set
		POS_X_MOVE			$08
		POS_Y_MOVE			$12
		SPR_LIB_SET			_spr_lib7
		NJSR				_scr_flips_04_set
		SPRITE_ON
		SPR_IDX_SET			_spr_lib7_4B
		SUSPEND				$14
		SPR_IDX_SET			_spr_lib7_69
		SUSPEND				$14
		NJSR				_scr_flips_04_clear
		SIZE_SET			$05,$10
		HP_SET				$01
		DAMAGE_SET			_OBJ_DMG_KILL
		SPR_IDX_SET			_spr_lib7_59
		SUSPEND				$3C
		APU_SE_SET			_apu_mus4E
		SJMP				_ssub_y_parabolic_delta_infinite_anim_sync

; =============== O B J E C T   S C R I P T =================================
_obj_scr33_hammer_mole:
		DESTR_PC_SET		_obj_scr_hammer_mole_destr
		NJSR				_scr_flips_04_set
		SPR_LIB_SET			_spr_lib7
		HP_SET				$01
		DAMAGE_SET			_OBJ_DMG_KILL
		SIZE_SET			$08,$14
byte_68983:
		SYNC
		NJSR				_nsub_obj_x_range40_test_from_players_macro_overlap_test_idx
		SBCSS				byte_68983
		NJSR				_nsub_sub10E
		SPRITE_ON
		SPR_IDX_SET			_spr_lib7_64
		SUSPEND				$08
		NJSR				_scr_flips_04_clear
		SPR_IDX_SET			_spr_lib7_65
		SUSPEND				$08
byte_68999:
		SRUN				_OBJ_TYPE_EBULLET,_obj_scr_107
		SPR_IDX_SET			_spr_lib7_66
		SUSPEND				$10
		APU_SE_SET			_apu_mus50
		SRUN				_OBJ_TYPE_EBULLET,_obj_scr_108
		SPR_IDX_SET			_spr_lib7_67
		SUSPEND				$10
		LOOP_A				$02,byte_68999
		SPR_IDX_SET			_spr_lib7_65
		SUSPEND				$08
		NJSR				_scr_flips_04_set
		SPR_IDX_SET			_spr_lib7_64
		SUSPEND				$08
		SPRITE_OFF
		SUSPEND				$5A
		SJMPS				byte_68983

; =============== O B J E C T   S C R I P T =================================
_obj_scr_hammer_mole_destr:
		SPR_IDX_SET			_spr_lib7_40
		SJMP				_obj_scr_common_destr

; =============== S C R I P T ===============================================
_obj_scr_107:
		POS_Y_MOVE			$F2
		NJSR				_nsub_obj_hor_bounce0C
		HP_SET				$01
		DAMAGE_SET			_OBJ_DMG_KILL
		SIZE_SET			$08,$0A
		SUSPEND				$10
		KILL

; =============== S C R I P T ===============================================
_obj_scr_108:
		HP_SET				$01
		DAMAGE_SET			_OBJ_DMG_KILL
		SIZE_SET			$06,$0F
		SPR_LIB_SET			_spr_lib7
		SPR_IDX_SET			_spr_lib7_68
		DELTA_X_SET			$10
		DELTA_Y_SET			$E0
		NJSR				_nsub_obj_hor_bounce13
		SPRITE_ON
		FLIP_H_OFF
byte_689E8:
		SJSRS				_ssub_689FB
		FLIP_V_ON
		SJSRS				_ssub_689FB
		FLIP_H_ON
		SJSRS				_ssub_689FB
		FLIP_V_OFF
		SJSRS				_ssub_689FB
		FLIP_H_OFF
		SJMPS				byte_689E8

; =============== S C R I P T   R O U T I N E ===============================
_ssub_689FB:
		ANIMATE_HV_SYNC
		NJSR				_nsub_obj_jump_up_anim
		LOOP_A				$04,_ssub_689FB
		SRET

; =============== O B J E C T   S C R I P T =================================
_obj_scr34_mecha_dog:
		DESTR_PC_SET		_obj_scr_common_destr
		SPR_LIB_SET			_spr_lib7
		SPR_IDX_SET			_spr_lib7_5E
		SIZE_SET			$0C,$18
		HP_SET				$01
		DAMAGE_SET			_OBJ_DMG_KILL
		SJSR				_ssub_obj_show_wait_for_idxCs_80_set
		NJSR				_nsub_sub10E
		DELTA_X_SET			$E8
		NJSR				_nsub_obj_hor_delta_toggle
byte_68A1D:
		APU_SE_SET			_apu_mus3E
byte_68A1F:
		SPR_IDX_SET			_spr_lib7_5E
		SJSRS				_ssub_68A69
		SPR_IDX_SET			_spr_lib7_5F
		SJSRS				_ssub_68A69
		SPR_IDX_SET			_spr_lib7_5E
		SJSRS				_ssub_68A69
		SPR_IDX_SET			_spr_lib7_5F
		SJSRS				_ssub_68A69
		LOOP_B				$02,byte_68A1F
		NJSR				_nsub_obj_hor_move_reverse
		SJMPS				byte_68A1D
byte_68A3D:
		SPR_IDX_SET			_spr_lib7_60
		SUSPEND				$08
		SPR_IDX_SET			_spr_lib7_63
		SUSPEND				$08
		LOOP_B				$04,byte_68A3D
		DELTA_X_SET			$20
		NJSR				_nsub_obj_hor_delta_toggle
byte_68A4E:
		SPR_IDX_SET			_spr_lib7_62
		SJSRS				_ssub_68A77
		APU_SE_SET			_apu_mus68
		SPR_IDX_SET			_spr_lib7_63
		SJSRS				_ssub_68A77
		SPR_IDX_SET			_spr_lib7_41
		SJSRS				_ssub_68A77
		APU_SE_SET			_apu_mus68
		SPR_IDX_SET			_spr_lib7_42
		SJSRS				_ssub_68A77
		SJMPS				byte_68A4E

; =============== S C R I P T   R O U T I N E ===============================
_ssub_68A69:
		NJSR				_nsub_obj_x_range30_test_from_players_macro_overlap_test_idx
		SBCSS				_ssub_68A77
		NJSR				_nsub_sub10E
		LOOP_A_STOP
		LOOP_B_STOP
		BREAK				byte_68A3D

; =============== S C R I P T   R O U T I N E ===============================
_ssub_68A77:
		SYNC
		NJSR				_obj_move_hor_animate
		NJSR				_nsub_obj_to_tile_collision_test_hor
		SBCSS				byte_68A86
		LOOP_A_STOP
		LOOP_B_STOP
		NJSR				_nsub_obj_hor_move_reverse
byte_68A86:
		NJSR				_nsub_obj_to_tile_collision_test_down
		SBCC				_ssub_obj_wait_for_jump
		LOOP_A				$07,_ssub_68A77
		SRET

; =============== O B J E C T   S C R I P T =================================
_obj_scr35_red_bird_with_egg:
		SJSR				_ssub_wait_for_idxCs_80_set
byte_68A94:
		NJSR_SYNC			_nsub_sub11E
		SBNES				byte_68A94
		SUSPEND				$1E
		SRUN				_OBJ_TYPE_ENEMY,_obj_scr_109
		SUSPEND				$1E
		SJMPS				byte_68A94

; =============== O B J E C T   S C R I P T =================================
_obj_scr36_red_bird:
		SJSR				_ssub_wait_for_idxCs_80_set
byte_68AA8:
		NJSR_SYNC			_nsub_sub11E
		SBNES				byte_68AA8
		SUSPEND				$1E
		SRUN				_OBJ_TYPE_ENEMY,_obj_scr_10A
		SUSPEND				$1E
		SJMPS				byte_68AA8

; =============== S C R I P T   R O U T I N E ===============================
_ssub_68AB9:
		DESTR_PC_SET		_obj_scr_common_destr
		SPR_LIB_SET			_spr_lib9
		HP_SET				$01
		DAMAGE_SET			_OBJ_DMG_KILL
		SPRITE_ON
		SIZE_SET			$10,$20
		POS_X_SET			$80,$00
		NJSR				_nsub_sub001
		NJSR				_nsub_obj_hor_bounce7E
		NJSR				_nsub_obj_hor_move_reverse
		NJSR				_nsub_obj_hor_delta_toggle
		SRET

; =============== S C R I P T ===============================================
_obj_scr_109:
		DELTA_X_SET			$18
		SJSRS				_ssub_68AB9
byte_68ADB:
		SPR_IDX_SET			_spr_lib9_06
		SJSRS				_ssub_68B01
		APU_SE_SET			_apu_mus39
		SPR_IDX_SET			_spr_lib9_07
		SJSRS				_ssub_68B0D
		SPR_IDX_SET			_spr_lib9_08
		SJSRS				_ssub_68B0D
		NJSR				_nsub_obj_x_range40_test_from_players_macro_overlap_test_idx
		SBCSS				byte_68ADB
		SRUN				_OBJ_TYPE_ENEMY,_obj_scr_10B
		SBCSS				byte_68ADB
		DELTA_X_SET			$20
		NJSR				_nsub_obj_hor_delta_toggle
		SJMPS				byte_68B1A

; =============== S C R I P T   R O U T I N E ===============================
_ssub_68B01:
		DELTA_Y_SET			$DF
byte_68B03:
		DELTA_Y_INC
		DELTA_Y_INC
		ANIMATE_HV_SYNC
		LOOP_B				$20,byte_68B03
		DELTA_Y_SET			$21
		SRET

; =============== S C R I P T   R O U T I N E ===============================
_ssub_68B0D:
		DELTA_Y_DEC
		DELTA_Y_DEC
		ANIMATE_HV_SYNC
		LOOP_B				$10,_ssub_68B0D
		SRET

; =============== S C R I P T ===============================================
_obj_scr_10A:
		DELTA_X_SET			$20
		SJSRS				_ssub_68AB9
byte_68B1A:
		SPR_IDX_SET			_spr_lib9_09
		SJSRS				_ssub_68B2E
		APU_SE_SET			_apu_mus39
		SPR_IDX_SET			_spr_lib9_0A
		SJSRS				_ssub_68B39
		SPR_IDX_SET			_spr_lib9_0B
		SJSRS				_ssub_68B39
		SJMPS				byte_68B1A

; =============== S C R I P T   R O U T I N E ===============================
_ssub_68B2E:
		DELTA_Y_SET			$EF
byte_68B30:
		DELTA_Y_INC
		ANIMATE_HV_SYNC
		LOOP_B				$20,byte_68B30
		DELTA_Y_SET			$11
		SRET

; =============== S C R I P T   R O U T I N E ===============================
_ssub_68B39:
		DELTA_Y_DEC
		ANIMATE_HV_SYNC
		LOOP_B				$10,_ssub_68B39
		SRET

; =============== S C R I P T ===============================================
_obj_scr_10B:
		DESTR_PC_SET		_obj_scr_common_destr
		POS_Y_MOVE			$10
		HP_SET				$01
		DAMAGE_SET			_OBJ_DMG_KILL
		SIZE_SET			$06,$0C
		SPR_LIB_SET			_spr_lib7
		SPR_IDX_SET			_spr_lib7_6A
		DELTA_Y_SET			$08
		SPRITE_ON
byte_68B53:
		SYNC
		NJSR				_nsub_obj_jump_up_anim
		NJSR				_obj_to_tile_grid_collision_test_down
		SBCCS				byte_68B53
		DELTA_Y_SET			$00
		APU_SE_SET			_apu_mus3B
		SPR_IDX_SET			_spr_lib7_6B
		SUSPEND				$08
		SPR_IDX_SET			_spr_lib7_6C
		SUSPEND				$08
		SPR_IDX_SET			_spr_lib7_6D
		SUSPEND				$08
		SPR_IDX_SET			_spr_lib7_6F
		SUSPEND				$08
		DELTA_X_SET			$10
		NJSR_SYNC			_nsub_sub10E
		NJSR_SYNC			_nsub_obj_hor_delta_toggle
byte_68B79:
		SPR_IDX_SET			_spr_lib7_6E
		SJSRS				_ssub_68B90
		SPR_IDX_SET			_spr_lib7_6F
		SJSRS				_ssub_68B90
		SPR_IDX_SET			_spr_lib7_70
		SJSRS				_ssub_68B90
		SPR_IDX_SET			_spr_lib7_6F
		SJSRS				_ssub_68B90
		SJMPS				byte_68B79

; =============== S C R I P T   R O U T I N E ===============================
_ssub_68B90:
		SYNC
		NJSR				_obj_move_hor_animate
		NJSR				_nsub_obj_to_tile_collision_test_hor
		SBCCS				byte_68BA5
		NJSR				_nsub_obj_to_tile_collision_test_down
		SBCCS				byte_68BA5
		LOOP_A				$08,_ssub_68B90
		SRET
byte_68BA5:
		LOOP_A_STOP
		SPR_IDX_SET			_spr_lib7_6F
		DELTA_Y_SET			$C0
		SJSR				_ssub_obj_wait_for_jump
		BREAK				byte_68B79

; =============== O B J E C T   S C R I P T =================================
_obj_scr37_javelin_rat:
		DESTR_PC_SET		_obj_scr_common_destr
		SPR_LIB_SET			_spr_lib7
		SPR_IDX_SET			_spr_lib7_43
		SIZE_SET			$0C,$18
		HP_SET				$01
		DAMAGE_SET			_OBJ_DMG_KILL
		SJSR				_ssub_obj_show_wait_for_idxCs_80_set
		NJSR				_nsub_sub10E
		DELTA_X_SET			$10
		NJSR				_nsub_obj_hor_delta_toggle
byte_68BC9:
		SPR_IDX_SET			_spr_lib7_44
		SJSRS				_ssub_68C0D
		SPR_IDX_SET			_spr_lib7_45
		SJSRS				_ssub_68C0D
		SPR_IDX_SET			_spr_lib7_46
		SJSRS				_ssub_68C0D
		SPR_IDX_SET			_spr_lib7_45
		SJSRS				_ssub_68C0D
		SJMPS				byte_68BC9
byte_68BE0:
		SPR_IDX_SET			_spr_lib7_47
		SUSPEND				$05
		SPR_IDX_SET			_spr_lib7_48
		SUSPEND				$05
		LOOP_A				$04,byte_68BE0
		APU_SE_SET			_apu_mus6D
		SRUN				_OBJ_TYPE_EBULLET,_obj_scr_10C
		SPR_IDX_SET			_spr_lib7_49
		SUSPEND				$2A
byte_68BF6:
		SPR_IDX_SET			_spr_lib7_44
		SJSRS				_ssub_68C22
		SPR_IDX_SET			_spr_lib7_45
		SJSRS				_ssub_68C22
		SPR_IDX_SET			_spr_lib7_46
		SJSRS				_ssub_68C22
		SPR_IDX_SET			_spr_lib7_45
		SJSRS				_ssub_68C22
		SJMPS				byte_68BF6

; =============== S C R I P T   R O U T I N E ===============================
_ssub_68C0D:
		NJSR				_nsub_obj_y_collision_test_from_players_macro_overlap_test_idx
		SBCSS				_ssub_68C22
		NJSR				_nsub_obj_x_range60_test_from_players_macro_overlap_test_idx
		SBCSS				_ssub_68C22
		NJSR				_nsub_sub10E
		NJSR				_nsub_obj_hor_delta_toggle
		BREAK				byte_68BE0

; =============== S C R I P T   R O U T I N E ===============================
_ssub_68C22:
		SYNC
		NJSR				_obj_move_hor_animate
		NJSR				_nsub_obj_to_tile_collision_test_hor
		SBCCS				byte_68C37
		NJSR				_nsub_obj_to_tile_collision_test_down
		SBCCS				byte_68C37
		LOOP_A				$0B,_ssub_68C22
		SRET
byte_68C37:
		LOOP_A_STOP
		SPR_IDX_SET			_spr_lib7_45
		DELTA_Y_SET			$C0
		SJMP				_ssub_obj_wait_for_jump

; =============== S C R I P T ===============================================
_obj_scr_10C:
		HP_SET				$01
		DAMAGE_SET			_OBJ_DMG_KILL
		SIZE_SET			$04,$08
		SPR_LIB_SET			_spr_lib7
		SPR_IDX_SET			_spr_lib7_4A
		POS_Y_MOVE			$DF
		DELTA_X_SET			$20
		DELTA_Y_SET			$E0
		NJSR				_nsub_obj_hor_bounce13
		SPRITE_ON
		SJMP				_ssub_y_parabolic_delta_infinite_anim_sync

; =============== O B J E C T   S C R I P T =================================
_obj_scr3C_violet_bug_fall:
		SJSRS				_ssub_violet_bug_init	; init sprites and pos
byte_68C5A:
		NJSR_SYNC			_nsub_cmp20_obj_x_lo_pos	; do nothing if at the sides
		SBCSS				byte_68C5A					; of the screen
		NJSR				_nsub_cmpE0_obj_x_lo_pos
		SBCCS				byte_68C5A					; when in the active zone,
		DELTA_Y_SET			$20							; start to fall
byte_68C68:
		SJSRS				_ssub_violet_bug_anim	; fall anim draw 5 cycles
		LOOP_A				$05,byte_68C68
		DELTA_Y_SET			$00							; stop movement
byte_68C71:
		SJSRS				_ssub_violet_bug_anim	; wait for 4 frames
		LOOP_A				$04,byte_68C71
		DELTA_X_SET			$20							; fly up and forth diagonally
		DELTA_Y_SET			$F0							; initialization
		NJSR				_nsub_obj_hor_delta_toggle; also toggle hor flipping
byte_68C7F:
		SJSRS				_ssub_violet_bug_anim	; fly for 2 frames, then
		LOOP_A				$02,byte_68C7F				; drop projectile
		SRUN				_OBJ_TYPE_STUNB,_obj_scr_violet_bug_sparkle
		SJMPS				byte_68C7F					; loop until out of screen

; =============== S C R I P T   R O U T I N E ===============================
_ssub_violet_bug_anim:
		SPR_IDX_SET			_spr_lib7_71
		SJSR				_ssub_anim_sync_frames10
		SPR_IDX_SET			_spr_lib7_72
		SJMP				_ssub_anim_sync_frames10

; =============== O B J E C T   S C R I P T =================================
_obj_scr3D_violet_bug_float:
		SJSRS				_ssub_violet_bug_init
		TIMER_B_SET			$20
byte_68C9C:
		SPR_IDX_SET			_spr_lib7_71
		SJSRS				_ssub_violet_bug_float_anim
		SPR_IDX_SET			_spr_lib7_72
		SJSRS				_ssub_violet_bug_float_anim
		LOOP_A				$06,byte_68C9C
		SRUN				_OBJ_TYPE_STUNB,_obj_scr_violet_bug_sparkle
		SJMPS				byte_68C9C

; =============== S C R I P T   R O U T I N E ===============================
_ssub_violet_bug_float_anim:
		NJSR				_nsub_sub123
		NJSR				_nsub_sub124
		NJSR				_nsub_obj_hflip_test
		SBNES				byte_68CC3
		NJSR				_nsub_inc_vars19
		SJMPS				byte_68CC6
byte_68CC3:
		NJSR				_nsub_dec_vars19
byte_68CC6:
		ANIMATE_HV_SYNC
		LOOP_B				$08,_ssub_violet_bug_float_anim
		SRET

; =============== S C R I P T   R O U T I N E ===============================
_ssub_violet_bug_init:
		DESTR_PC_SET		_obj_scr_common_destr
		SPR_LIB_SET			_spr_lib7
		SPR_IDX_SET			_spr_lib7_71
		HP_SET				$01
		DAMAGE_SET			_OBJ_DMG_KILL
		SIZE_SET			$0A,$14
		SJSR				_ssub_obj_show_wait_for_idxCs_80_set
		NJSR				_nsub_sub10E
		SRET

; =============== S C R I P T ===============================================
_obj_scr_violet_bug_sparkle:
		NJSR				_nsub_obj_idxCs_80_set
		APU_SE_SET			_apu_mus29
		POS_Y_MOVE			$08
		DELTA_Y_SET			$10
		SPR_LIB_SET			_spr_lib7
		SPRITE_ON
		HP_SET				$01
		DAMAGE_SET			_OBJ_DMG_STUN
		SIZE_SET			$04,$08
byte_68CF4:
		SPR_IDX_SET			_spr_lib7_73
		SJSR				_ssub_anim_sync_frames10
		SPR_IDX_SET			_spr_lib7_7B
		SJSR				_ssub_anim_sync_frames10
		SJMPS				byte_68CF4

; =============== O B J E C T   S C R I P T =================================
_obj_scr39_hedgehog:
		SPR_LIB_SET			_spr_lib7
		SPR_IDX_SET			_spr_lib7_77
		SJSR				_ssub_obj_show_wait_for_idxCs_80_set
		NJSR				_nsub_sub10E
_obj_scr_hedgehog_main_loop:
		DESTR_PC_SET		_obj_scr_common_destr
		SIZE_SET			$0A,$0C
		HP_SET				$01
		DAMAGE_SET			_OBJ_DMG_KILL
		DELTA_X_SET			$08
		NJSR				_nsub_obj_hor_delta_toggle
byte_68D1A:
		LOOP_A_STOP
		SPR_IDX_SET			_spr_lib7_77
		SJSRS				_ssub_hedgehog_ai
		SPR_IDX_SET			_spr_lib7_78
		SJSRS				_ssub_hedgehog_ai
		SPR_IDX_SET			_spr_lib7_77
		SJSRS				_ssub_hedgehog_ai
		SPR_IDX_SET			_spr_lib7_79
		SJSRS				_ssub_hedgehog_ai
_obj_scr_hedgehog_turn_around:
		NJSR				_nsub_obj_hor_move_reverse
		SJMPS				byte_68D1A

; =============== S C R I P T   R O U T I N E ===============================
_ssub_hedgehog_ai:
		SYNC
		NJSR				_nsub_obj_to_throw_collision_test_range40
		SBCSS				byte_68D3F
		BREAK				_ssub_hedgehog_defend
byte_68D3F:
		NJSR				_obj_move_hor_animate
		NJSR				_nsub_obj_to_tile_collision_test_hor
		SBCSS				byte_68D4B
		BREAK				_obj_scr_hedgehog_turn_around
byte_68D4B:
		NJSR				_nsub_obj_to_tile_collision_test_down
		SBCC				_ssub_obj_wait_for_jump
		LOOP_A				$0E,_ssub_hedgehog_ai
		SRET
_ssub_hedgehog_defend:
		DESTR_PC_SET		_obj_scr_hedgehog_destr
		SIZE_SET			$0A,$0E
		SPR_IDX_SET			_spr_lib7_7A
		NJSR				_nsub_sub132
byte_68D61:
		HP_SET				$02
		SYNC
		LOOP_B				$1E,byte_68D61
		SJMPS				_obj_scr_hedgehog_main_loop

; =============== O B J E C T   S C R I P T =================================
_obj_scr_hedgehog_destr:
		NJSR				_nsub_get_obj_hp
		SBEQ				_obj_scr_common_destr
		NJSR				_scr_flips_04_clear
		SJMPS				byte_68D61

; =============== O B J E C T   S C R I P T =================================
_obj_scr3A_running_cock:
		SJSR				_ssub_wait_for_idxCs_80_set
byte_68D7A:
		SYNC
		NJSR				_nsub_cmp08_obj_x_lo_pos
		SBCCS				byte_68D7A
		DESTR_PC_SET		_obj_scr_common_destr
		SPR_LIB_SET			_spr_lib7
		SPR_IDX_SET			_spr_lib7_75
		SIZE_SET			$08,$20
		HP_SET				$01
		DAMAGE_SET			_OBJ_DMG_KILL
		SPRITE_ON
		DELTA_X_SET			$30
		NJSR				_nsub_sub10E
		NJSR				_nsub_obj_hor_delta_toggle
byte_68D98:
		SPR_IDX_SET			_spr_lib7_74
		SJSRS				_ssub_68DA5
		SPR_IDX_SET			_spr_lib7_76
		SJSRS				_ssub_68DA5
		SJMPS				byte_68D98

; =============== S C R I P T   R O U T I N E ===============================
_ssub_68DA5:
		DELTA_Y_SET			$E0
byte_68DA7:
		SYNC
		NJSR				_obj_move_hor_animate
		NJSR				_nsub_obj_to_tile_collision_test_hor
		SBCSS				byte_68DB4
		NJSR				_nsub_obj_hor_move_reverse
byte_68DB4:
		SJSR				_ssub_obj_jump_calcs
		SBCCS				byte_68DA7
		SPR_IDX_SET			_spr_lib7_75
		SUSPEND				$04
		SRET

; =============== O B J E C T   S C R I P T =================================
_obj_scr38_electric_rat:
		DESTR_PC_SET		_obj_scr_electric_rat_destr
		SPR_LIB_SET			_spr_lib5
		SPR_IDX_SET			_spr_lib5_3A
		SJSR				_ssub_obj_show_wait_for_idxCs_80_set
		NJSR				_nsub_sub10E
		SIZE_SET			$06,$1C
		DAMAGE_SET			_OBJ_DMG_KILL
byte_68DD1:
		HP_SET				$01
		SPR_IDX_SET			_spr_lib5_3A
		SUSPEND				$40
		SPR_IDX_SET			_spr_lib5_3B
		SUSPEND				$10
byte_68DDB:
		LOOP_A_STOP
		LOOP_B_STOP
		NJSR				_scr_flips_04_clear
		HP_SET				$02
		SJSRS				_ssub_68DF9
		SJSRS				_ssub_68DF9
		SRUN				_OBJ_TYPE_EBULLET,_obj_scr_10E
		SRUN				_OBJ_TYPE_EBULLET,_obj_scr_10F
		SJSRS				_ssub_68DF9
		SJSRS				_ssub_68DF9
		SJMPS				byte_68DD1

; =============== S C R I P T   R O U T I N E ===============================
_ssub_68DF9:
		APU_SE_SET			_apu_mus6F
byte_68DFB:
		SPR_IDX_SET			_spr_lib5_3C
		SUSPEND				$02
		SPR_IDX_SET			_spr_lib5_3D
		SUSPEND				$02
		LOOP_A				$02,byte_68DFB
byte_68E07:
		SPR_IDX_SET			_spr_lib5_3E
		SUSPEND				$02
		SPR_IDX_SET			_spr_lib5_3F
		SUSPEND				$02
		LOOP_A				$02,byte_68E07
		LOOP_B				$02,byte_68DFB
		SRET

; =============== S C R I P T   R O U T I N E ===============================
_obj_scr_electric_rat_destr:
		NJSR				_nsub_get_obj_hp
		SBNES				byte_68DDB
		SPR_IDX_SET			_spr_lib5_3A
		SJMP				_obj_scr_common_destr

; =============== S C R I P T ===============================================
_obj_scr_10F:
		DELTA_X_SET			$30
		POS_X_MOVE			$08
		FLIP_H_OFF
		SJMPS				_ssub_68E30

; =============== S C R I P T ===============================================
_obj_scr_10E:
		DELTA_X_SET			$D0
		POS_X_MOVE			$F8
		FLIP_H_ON

; !FALLTHROUGH!

; =============== S C R I P T ===============================================
_ssub_68E30:
		NJSR				_nsub_obj_idxCs_80_set
		SPR_LIB_SET			_spr_lib5
		SIZE_SET			$04,$08
		HP_SET				$01
		DAMAGE_SET			_OBJ_DMG_KILL
		SPRITE_ON
byte_68E3D:
		SPR_IDX_SET			_spr_lib5_05
		SJSRS				_ssub_68E4A
		SPR_IDX_SET			_spr_lib5_40
		SJSRS				_ssub_68E4A
		SJMPS				byte_68E3D

; =============== S C R I P T   R O U T I N E ===============================
_ssub_68E4A:
		ANIMATE_HV_SYNC
		NJSR				_nsub_obj_to_tile_collision_test_hor
		SBCCS				byte_68E5C
		NJSR				_nsub_obj_to_tile_collision_test_down
		SBCCS				byte_68E5C
		LOOP_A				$06,_ssub_68E4A
		SRET
byte_68E5C:
		KILL

; =============== O B J E C T   S C R I P T =================================
_obj_scr3F_lvl1_boss_water_rabbit:
		STORE				_apu_mus1E_idx,_apu_load_idx_req
		SRUN				_OBJ_TYPE_AUTO,_obj_scr_110
		DESTR_PC_SET		_obj_scr_common_small_boss_destr
		NJSR				_nsub_obj_idxCs_C0_clear
		POS_X_MOVE			$0A
		SPR_LIB_SET			_spr_lib8
		SUSPEND				$80
		SIZE_SET			$0A,$32
		HP_SET				$06
		DAMAGE_SET			_OBJ_DMG_KILL
		SPRITE_ON
		DELTA_X_SET			$10
		NJSR				_nsub_sub10E
		NJSR				_nsub_obj_hor_delta_toggle
byte_68E81:
		SPR_IDX_SET			_spr_lib8_18
		SJSR				_obj_scr_20A_anim_anim08_sync
		SPR_IDX_SET			_spr_lib8_20
		SJSR				_obj_scr_20A_anim_anim08_sync
		LOOP_A				$02,byte_68E81
		SJSRS				_ssub_68F10
byte_68E92:
		NJSR				_nsub_get_rand_scale3
		SSWITCH				_tmp_ptrE+1
		SCASE				byte_68E9E
		SCASE				byte_68EB4
		SCASE				byte_68EB4
byte_68E9E:
		DELTA_X_SET			$00
		DELTA_Y_SET			$00
		NJSR				_nsub_sub10E
		NJSR				_nsub_get_rand_flags
		SBPLS				byte_68EAE
		SJSRS				_ssub_68F2E
byte_68EAE:
		SJSRS				_ssub_68F2E
		SJSRS				_ssub_68F10
byte_68EB4:
		DELTA_X_SET			$20
		NJSR				_nsub_obj_hor_delta_toggle
		NJSR				_nsub_get_rand_flags
		SBPLS				byte_68EC2
		SJSRS				_ssub_68EC8
byte_68EC2:
		SJSRS				_ssub_68EC8
		SJMPS				byte_68E92

; =============== S C R I P T   R O U T I N E ===============================
_ssub_68EC8:
		SPR_IDX_SET			_spr_lib8_18
		SJSRS				_ssub_68ECF
		SPR_IDX_SET			_spr_lib8_20

; !FALLTHROUGH!

; =============== S C R I P T   R O U T I N E ===============================
_ssub_68ECF:
		SYNC
		SJSR				_obj_scr_20A_anim
		NJSR				_obj_move_hor_animate
		NJSR				_nsub_sub135
		SBCCS				byte_68EDF
		NJSR				_nsub_obj_hor_move_reverse
byte_68EDF:
		NJSR				_nsub_obj_to_tile_collision_test_down
		SBCCS				byte_68EEA
		LOOP_B				$0A,_ssub_68ECF
		SRET
byte_68EEA:
		NJSR				_scr_reset_slot
		NJSR				_nsub_cmp40_obj_y_lo_pos
		SBEQS				byte_68F01
		NJSR				_nsub_cmpC0_obj_y_lo_pos
		SBEQS				byte_68EFF
		NJSR				_nsub_get_rand_flags
		SBPLS				byte_68F01
byte_68EFF:
		DELTA_Y_SET			$AE
byte_68F01:
		SPR_IDX_SET			_spr_lib8_23
		DELTA_X_SET			$00
		SJSR				_obj_scr_20B
		SPR_IDX_SET			_spr_lib8_1E
		SJSR				_obj_scr_20A_anim_anim06_sync
		SJMPS				byte_68E92

; =============== S C R I P T   R O U T I N E ===============================
_ssub_68F10:
		DELTA_X_SET			$00
		DELTA_Y_SET			$00
		SPR_IDX_SET			_spr_lib8_15
		SJSR				_obj_scr_20A_anim_anim06_sync
		SPR_IDX_SET			_spr_lib8_16
		SJSR				_obj_scr_20A_anim_anim06_sync
		SPR_IDX_SET			_spr_lib8_17
		SJSR				_obj_scr_20A_anim_anim06_sync
		SJSR				_obj_scr_20A_anim_anim06_sync
		SPR_IDX_SET			_spr_lib8_16
		SJSR				_obj_scr_20A_anim_anim06_sync
		SPR_IDX_SET			_spr_lib8_15
		SRET

; =============== S C R I P T   R O U T I N E ===============================
_ssub_68F2E:
		SPR_IDX_SET			_spr_lib8_19
		SJSR				_obj_scr_20A_anim_anim03_sync
		SPR_IDX_SET			_spr_lib8_1A
		SJSR				_obj_scr_20A_anim_anim03_sync
		SPR_IDX_SET			_spr_lib8_1B
		SJSR				_obj_scr_20A_anim_anim10_sync
		SPR_IDX_SET			_spr_lib8_1C
		SJSR				_obj_scr_20A_anim_anim04_sync
		SPR_IDX_SET			_spr_lib8_1D
		SJSR				_obj_scr_20A_anim_anim03_sync
		APU_SE_SET			_apu_mus3F
		SRUN				_OBJ_TYPE_EBULLET,_obj_scr_111
		SPR_IDX_SET			_spr_lib8_1E
		SJSR				_obj_scr_20A_anim_anim06_sync
		LOOP_A				$02,_ssub_68F2E
		SRET

; =============== S C R I P T ===============================================
_obj_scr_111:
		POS_Y_MOVE			$E4
		DELTA_X_SET			$20
		NJSR				_nsub_obj_hor_bounce13
		SPR_LIB_SET			_spr_lib8
		SIZE_SET			$05,$08
		HP_SET				$01
		DAMAGE_SET			_OBJ_DMG_KILL
		SPRITE_ON
byte_68F68:
		SPR_IDX_SET			_spr_lib8_21
		SJSRS				_ssub_68F75
		SPR_IDX_SET			_spr_lib8_22
		SJSRS				_ssub_68F75
		SJMPS				byte_68F68

; =============== S C R I P T   R O U T I N E ===============================
_ssub_68F75:
		ANIMATE_HV_SYNC
		NJSR				_nsub_obj_jump_up_anim
		LOOP_A				$03,_ssub_68F75
		SRET

; =============== S C R I P T ===============================================
_obj_scr_110:
		SUSPEND				$F0
byte_68F80:
		NJSR_SYNC			_nsub_grabable_obj_num_01_cmp
		SBCSS				byte_68F80
		SUSPEND				$3C
		SRUN				_OBJ_TYPE_PBULLET,_obj_scr_112
		SJMPS				_obj_scr_110

; =============== S C R I P T ===============================================
_obj_scr_112:
		GRABABLE_ON
		DESTR_PC_SET		_obj_scr_box
		NJSR				_nsub_get_rand_scale3
		SSWITCH				_tmp_ptrE+1
		SCASE				byte_68F9F
		SCASE				byte_68FA5
		SCASE				byte_68FAB
byte_68F9F:
		POS_X_SET			$18,$00
		SJMPS				byte_68FB1
byte_68FA5:
		POS_X_SET			$A8,$00
		SJMPS				byte_68FB1
byte_68FAB:
		POS_X_SET			$98,$00
		NJSR				_nsub_obj_hor_move_reverse
byte_68FB1:
		POS_Y_SET			$00,$00
		SYNC
		SPR_LIB_SET			_spr_lib3
		SPR_IDX_SET			_spr_lib3_00
		SIZE_SET			$06,$10
		NJSR				_nsub_idxBs_10_set
		SPRITE_ON
byte_68FC0:
		HP_SET				$01
		DAMAGE_SET			_OBJ_DMG_KILL
		DELTA_X_SET			$00
		DELTA_Y_SET			$01
		NJSR				_nsub_obj_type_change_throw
byte_68FCB:
		SYNC
		NJSR				_nsub_obj_jump_up_anim
		NJSR				_obj_to_tile_grid_collision_test_down
		SBCSS				byte_68FDE
		NJSR				_nsub_get_obj_hp
		SBNES				byte_68FCB
		SJMP				byte_6A669	; LONG
byte_68FDE:
		NJSR				_nsub_obj_type_change_solid_no_damage
		NJSR				_nsub_obj_hor_move_reverse
		DELTA_X_SET			$08
		DELTA_Y_SET			$00
		NJSR				_nsub_obj_hor_delta_toggle
byte_68FEB:
		SYNC
		NJSR				_nsub_get_obj_idxBs
		SBMI				_obj_scr_box
		NJSR				_obj_move_hor_animate
		NJSR				_nsub_sub13C
		NJSR				_nsub_obj_to_tile_collision_test_down
		SBCSS				byte_68FEB
		SJMPS				byte_68FC0

; =============== O B J E C T   S C R I P T =================================
_obj_scr40_lvl2_boss_flying_panther:
		STORE				_apu_mus1E_idx,_apu_load_idx_req
		DESTR_PC_SET		_obj_scr_common_small_boss_destr
		NJSR				_nsub_obj_idxCs_C0_clear
		POS_X_MOVE			$0F
		SPR_LIB_SET			_spr_lib8
		SUSPEND				$80
		SPRITE_ON
		DELTA_X_SET			$F8
		DELTA_Y_SET			$10
byte_69016:
		SJSR				_ssub_690B0
		LOOP_A				$04,byte_69016
		SIZE_SET			$0E,$20
		HP_SET				$06
		DAMAGE_SET			_OBJ_DMG_KILL
byte_69024:
		SJSRS				_ssub_69039
		SJSRS				_ssub_6905E
		SJSRS				_ssub_69039
		SJSRS				_ssub_69076
		SJSRS				_ssub_69039
		SJSRS				_ssub_69076
		SJMPS				byte_69024

; =============== S C R I P T   R O U T I N E ===============================
_ssub_69039:
		DELTA_X_SET			$00
		DELTA_Y_SET			$00
byte_6903D:
		SJSRS				_ssub_690B0
		LOOP_A				$03,byte_6903D
		SRUN				_OBJ_TYPE_EBULLET,_obj_scr_boss_flying_panther_stone
		SJSR				_obj_scr_20A_anim_anim_sync
byte_6904B:
		SJSRS				_ssub_690B0
		LOOP_A				$03,byte_6904B
		SRUN				_OBJ_TYPE_EBULLET,_obj_scr_boss_flying_panther_stone
byte_69056:
		SJSRS				_ssub_690B0
		LOOP_A				$03,byte_69056
		SRET

; =============== S C R I P T   R O U T I N E ===============================
_ssub_6905E:
		DELTA_X_SET			$E0
		DELTA_Y_SET			$19
		NJSR				_nsub_obj_hor_delta_toggle
byte_69065:
		SJSRS				_ssub_690B0
		NJSR				_nsub_sub004
		LOOP_A				$06,byte_69065
		NJSR				_nsub_obj_hor_move_reverse
		NJSR				_nsub_obj_y_lo_maskF0
		SRET

; =============== S C R I P T   R O U T I N E ===============================
_ssub_69076:
		DELTA_X_SET			$E0
		DELTA_Y_SET			$20
		NJSR				_nsub_obj_hor_delta_toggle
byte_6907D:
		SJSRS				_ssub_690B0
		NJSR				_nsub_sub004
		LOOP_A				$03,byte_6907D
		NJSR				_nsub_obj_y_lo_maskF0
		DELTA_Y_SET			$00
		APU_SE_SET			_apu_mus67
byte_6908E:
		SPR_IDX_SET			_spr_lib8_0C
		SJSR				_obj_scr_20A_anim_anim_sync
		SJSR				_obj_scr_20A_anim_anim_sync
		SPR_IDX_SET			_spr_lib8_0D
		SJSR				_obj_scr_20A_anim_anim_sync
		SJSR				_obj_scr_20A_anim_anim_sync
		LOOP_A				$0C,byte_6908E
		NJSR				_nsub_obj_hor_move_reverse
		DELTA_X_SET			$00
		DELTA_Y_SET			$E0
		SJSRS				_ssub_690B0
		SJSRS				_ssub_690B0
		SRET

; =============== S C R I P T   R O U T I N E ===============================
_ssub_690B0:
		APU_SE_SET			_apu_mus66
		NJSR				_nsub_sub002
		SPR_IDX_SET			_spr_lib8_09
		SJSRS				_ssub_690CF
		NJSR				_nsub_sub003
		SPR_IDX_SET			_spr_lib8_0A
		SJSRS				_ssub_690CF
		NJSR				_nsub_sub003
		SPR_IDX_SET			_spr_lib8_0B
		SJSRS				_ssub_690CF
		NJSR				_nsub_sub002
		SPR_IDX_SET			_spr_lib8_0A

; =============== S C R I P T   R O U T I N E ===============================
_ssub_690CF:
		SJSR				_obj_scr_20A_anim_anim_sync
		NJSR				_nsub_sub005
		LOOP_B				$04,_ssub_690CF
		SRET

; =============== S U B R O U T I N E =======================================
_nsub_sub002:
		CLC
		LDA		_obj_y_deltas,X
		ADC		#$10
		STA		_obj_y_deltas,X
		RTS

; =============== S U B R O U T I N E =======================================
_nsub_sub003:
		SEC
		LDA		_obj_y_deltas,X
		SBC		#$10
		STA		_obj_y_deltas,X
		RTS

; =============== S U B R O U T I N E =======================================
_nsub_sub004:
		SEC
		LDA		_obj_y_deltas,X
		SBC		#$0A
		STA		_obj_y_deltas,X
		RTS

; =============== S U B R O U T I N E =======================================
_nsub_sub005:
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

; =============== O B J E C T   S C R I P T =================================
_obj_scr_boss_flying_panther_stone:
		GRABABLE_ON
		DESTR_PC_SET		_obj_scr_boss_flying_panther_stone_destr
		SPR_LIB_SET			_spr_lib8
		SPR_IDX_SET			_spr_lib8_0E
		HP_SET				$01
		DAMAGE_SET			_OBJ_DMG_KILL
		SIZE_SET			$06,$10
		SPRITE_ON
		NJSR_SYNC			_nsub_sub006
byte_69120:
		NJSR				_nsub_obj_jump_up_anim
		NJSR_SYNC			_obj_vert_anim
		LOOP_A				$20,byte_69120
		TARGET_LOCK			$40
		NJSR				_nsub_sub111
		NJSR				_nsub_grabable_obj_num_02_cmp
		SBCS				_ssub_target_follow_down_infinite
		SJSR				_ssub_target_follow_down_to_ground
		DELTA_X_SET			$18
		DELTA_Y_SET			$00
		NJSR				_nsub_obj_hor_delta_toggle
byte_6913F:
		SJSR				_ssub_anim_sync_frames10
		NJSR				_nsub_sub007
		SBCCS				byte_6913F
		NJSR				_nsub_obj_type_change_solid_no_damage
byte_6914B:
		SYNC
		NJSR				_nsub_get_obj_idxBs
		SBMIS				_obj_scr_boss_flying_panther_stone_destr
		NJSR				_nsub_sub008
		SBCSS				byte_6916B
		SJMPS				byte_6914B

; =============== O B J E C T   S C R I P T =================================
_obj_scr_boss_flying_panther_stone_destr:
		SJSR				_ssub_obj_wait_for_throw
		NJSR				_nsub_obj_throw_direction_select
byte_69161:
		ANIMATE_HV_SYNC
		NJSR				_nsub_sub016
		SBNES				byte_69161
		SJMP				_ssub_y_parabolic_delta_infinite_anim_sync
byte_6916B:
		NJSR				_nsub_obj_type_change_bullet
		DELTA_X_SET			$10
		DELTA_Y_SET			$E0
		NJSR				_nsub_obj_from_idxAs_hor_delta_toggle
		SJMP				_ssub_y_parabolic_delta_infinite_anim_sync

; =============== S U B R O U T I N E =======================================
_nsub_sub006:
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
_nsub_sub007:
		LDA		_obj_x_lo_poss,X
		BPL		loc_69194
		EOR		#$FF
loc_69194:
		CMP		#$10
		JMP		_scr_flags_update

; =============== S U B R O U T I N E =======================================
_nsub_sub008:
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
		NJSR				_nsub_obj_idxCs_C0_clear
		SRUN				_OBJ_TYPE_AUTO,_obj_scr_lvl3_boss_sea_rat_bg
		POS_X_MOVE			$20
		SPR_LIB_SET			_spr_lib8
		SIZE_SET			$08,$20
		HP_SET				$06
		DAMAGE_SET			_OBJ_DMG_KILL
		SUSPEND				$80
		SPRITE_ON
		DELTA_X_SET			$E8
		SPR_IDX_SET			_spr_lib8_27
		SJSR				_obj_scr_20A_anim_anim10_sync
		SPR_IDX_SET			_spr_lib8_26
		SJSR				_obj_scr_20A_anim_anim10_sync
		SJSRS				_ssub_boss_sea_rat_anim24
		NJSR				_nsub_sub009
byte_691D7:
		NJSR				_nsub_get_rand_scale3
		SSWITCH				_tmp_ptrE+1
		SCASE				_obj_scr_boss_sea_rat_ai_modeA
		SCASE				_obj_scr_boss_sea_rat_ai_modeB
		SCASE				_obj_scr_boss_sea_rat_ai_modeA

; =============== S C R I P T   R O U T I N E ===============================
_ssub_boss_sea_rat_anim24:
		SPR_IDX_SET			_spr_lib8_24
		DELTA_X_SET			$00
		SJMP				_obj_scr_20A_anim_anim08_sync

; =============== O B J E C T   S C R I P T =================================
_obj_scr_boss_sea_rat_ai_modeB:
		NJSR				_nsub_cmpC0_obj_y_lo_pos
		SBCCS				byte_69229
byte_691F0:
		NJSR				_nsub_cmp80_obj_x_lo_pos
		SBNES				byte_691FC
		SJSRS				_ssub_boss_sea_rat_anim24
		NJSR				_nsub_sub10E
byte_691FC:
		DELTA_X_SET			$00
		DELTA_Y_SET			$00
		SPR_IDX_SET			_spr_lib8_28
		APU_SE_SET			_apu_mus3C
		SJSR				_obj_scr_20A_anim_anim10_sync
		APU_SE_SET			_apu_mus3C
		SJSR				_obj_scr_20A_anim_anim10_sync
byte_6920C:
		SPR_IDX_SET			_spr_lib8_29
		APU_SE_SET			_apu_mus3D
		SRUN				_OBJ_TYPE_EBULLET,_obj_scr_boss_sea_rat_projectile
		SJSR				_obj_scr_20A_anim_anim03_sync
		SJSR				_obj_scr_20A_anim_anim08_sync
		SPR_IDX_SET			_spr_lib8_24
		SJSR				_obj_scr_20A_anim_anim10_sync
		LOOP_A				$02,byte_6920C

; !FALLTHROUGH!

; =============== O B J E C T   S C R I P T =================================
_obj_scr_boss_sea_rat_ai_modeA:
		NJSR				_nsub_cmp80_obj_y_lo_pos
		SBCSS				byte_691F0
byte_69229:
		DELTA_X_SET			$18
		NJSR				_nsub_obj_hor_delta_toggle
byte_6922E:
		SYNC
		SPR_IDX_SET			_spr_lib8_25
		SJSRS				_ssub_boss_sea_rat_move_ai
		LOOP_B				$08,byte_6922E
byte_69238:
		SYNC
		SPR_IDX_SET			_spr_lib8_26
		SJSRS				_ssub_boss_sea_rat_move_ai
		LOOP_B				$08,byte_69238
byte_69242:
		SYNC
		SPR_IDX_SET			_spr_lib8_27
		SJSRS				_ssub_boss_sea_rat_move_ai
		LOOP_B				$08,byte_69242
byte_6924C:
		SYNC
		SPR_IDX_SET			_spr_lib8_26
		SJSRS				_ssub_boss_sea_rat_move_ai
		LOOP_B				$08,byte_6924C
		LOOP_A				$02,byte_6922E
		DELTA_X_SET			$00
byte_6925C:
		NJSR				_nsub_get_obj_y_delta
		SBEQS				byte_69269
		SYNC
		SJSRS				_ssub_boss_sea_rat_move_ai
		SJMPS				byte_6925C
byte_69269:
		NJSR				_nsub_cmp80_obj_x_lo_pos
		SBEQ				byte_691D7
		SJSRS				_ssub_boss_sea_rat_anim24
		NJSR				_nsub_obj_hor_move_reverse
		SJSR				_ssub_boss_sea_rat_anim24
		SJMP				byte_691D7	; LONG

; =============== S C R I P T   R O U T I N E ===============================
_ssub_boss_sea_rat_move_ai:
		SJSR				_obj_scr_20A_anim
		NJSR				_obj_move_hor_animate
		NJSR				_nsub_get_obj_y_delta
		SBNES				byte_69290
		NJSR				_nsub_obj_to_tile_collision_test_down
		SBCCS				byte_6928E
		SRET
byte_6928E:
		DELTA_Y_SET			$B0
byte_69290:
		SPR_IDX_SET			_spr_lib8_26
		NJSR				_nsub_obj_jump_up_anim
		SBPLS				byte_6929C
		NJSR				_obj_vert_anim
		SRET
byte_6929C:
		NJSR				_obj_to_tile_grid_collision_test_down
		SBCCS				byte_692A4
		DELTA_Y_SET			$00
byte_692A4:
		SRET

; =============== S U B R O U T I N E =======================================
_nsub_sub009:
		LDA		_room_flags
		ORA		#$02
		STA		_room_flags
		RTS

; =============== S C R I P T ===============================================
_obj_scr_lvl3_boss_sea_rat_bg:
		FLIPS_SET			_OBJ_FLIPS08
byte_692AE:
		NJSR_SYNC			_nsub_sub00A
		SBCSS				byte_692AE
		SRUN				_OBJ_TYPE_SOLID,_obj_scr_116
		SJMPS				byte_692AE

; =============== S U B R O U T I N E =======================================
_nsub_sub00A:
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
		JMP		_nsub_grabable_obj_num_01_cmp
loc_692DC:
		SEC
		JMP		_scr_flags_update


; =============== S C R I P T ===============================================
_obj_scr_116:
		GRABABLE_ON
		DESTR_PC_SET		_obj_scr_box
		POS_Y_SET			$00,$00
		SPR_LIB_SET			_spr_lib3
		SPR_IDX_SET			_spr_lib3_00
		SIZE_SET			$06,$10
		HP_SET				$01
		SPRITE_ON
byte_692F1:
		NJSR_SYNC			_nsub_get_obj_idxBs
		SBMI				_obj_scr_box
		SJMPS				byte_692F1

; =============== S C R I P T ===============================================
_obj_scr_boss_sea_rat_projectile:
		POS_Y_MOVE			$E9
		DELTA_X_SET			$30
		NJSR				_nsub_obj_hor_bounce2C
		SPR_LIB_SET			_spr_lib8
		SIZE_SET			$04,$06
		HP_SET				$01
		DAMAGE_SET			_OBJ_DMG_KILL
		SPRITE_ON
byte_6930B:
		SPR_IDX_SET			_spr_lib8_2A
		SJSR				_ssub_anim_sync_frames10
		SPR_IDX_SET			_spr_lib8_2B
		SJSR				_ssub_anim_sync_frames10
		SJMPS				byte_6930B

; =============== O B J E C T   S C R I P T =================================
_obj_scr42_lvl4_boss_ghost:
		STORE				_apu_mus0E_idx,_apu_load_idx_req
		DESTR_PC_SET		_obj_scr_boss_ghost_destr
		NJSR				_nsub_obj_idxCs_C0_clear
		HP_SET				$07
		DAMAGE_SET			_OBJ_DMG_KILL
		STORE				$00,byte_E0
		SJSR				_ssub_69531
		SJMPS				byte_69350
byte_69330:
		SPR_IDX_SET			_spr_lib8_0F
		SIZE_SET			$00,$00
		DELTA_X_SET			$00
		DELTA_Y_SET			$00
byte_69339:
		SJSR				_ssub_69492
		SSWITCH				byte_E0
		SCASE				byte_69343
		SCASE				byte_69339
byte_69343:
		SPRITE_OFF
		PAL_FADE_OUT		$04,$87
		SUSPEND				$1E
		SPRITE_OFF
		PAL_FADE_IN			$04,$8F
		SJSR				_ssub_69531
byte_69350:
		PAL_FADE_OUT		$04,$8F
		SUSPEND				$1E
		POS_X_SET			$C8,$00
		POS_Y_SET			$90,$00
		SPR_LIB_SET			_spr_lib8
		SPR_IDX_SET			_spr_lib8_0F
		NJSR				_nsub_sub00C
		CHR_SET				$00,$1B
		PAL_FADE_IN			$04,$87
		SUSPEND				$10
		SPRITE_ON
		SIZE_SET			$14,$30
		DELTA_Y_SET			$10
byte_69370:
		SJSR				_ssub_69492
		LOOP_A				$30,byte_69370
		NJSR				_nsub_complement_y_deltas
		LOOP_B				$02,byte_69370
		DELTA_Y_SET			$00
byte_69380:
		SJSR				_ssub_69492
		LOOP_A				$1E,byte_69380
		SPR_IDX_SET			_spr_lib8_10
		APU_SE_SET			_apu_mus6C
		NJSR_SYNC			_nsub_box_bonus_4prizes_shuffle
		NJSR				_nsub_get_rand_scale3
		SSWITCH				_tmp_ptrE+1
		SCASE				byte_69412
		SCASE				byte_693D6
		SCASE				byte_6939A
byte_6939A:
		DELTA_X_SET			$F9
		NJSR				_nsub_get_rand_flags
		SBPLS				byte_693AF
byte_693A2:
		SJSRS				_ssub_693BC
		SJSRS				_ssub_693C9
		LOOP_A				$02,byte_693A2
		SJMPS				byte_69330
byte_693AF:
		SJSRS				_ssub_693C9
		SJSRS				_ssub_693BC
		LOOP_A				$02,byte_693AF
		SJMP				byte_69330	; LONG

; =============== S C R I P T   R O U T I N E ===============================
_ssub_693BC:
		DELTA_Y_SET			$D8
byte_693BE:
		DELTA_Y_INC
		SJSR				_ssub_69492
		LOOP_B				$4E,byte_693BE
		SJMPS				byte_6940D

; =============== S C R I P T   R O U T I N E ===============================
_ssub_693C9:
		DELTA_Y_SET			$28
byte_693CB:
		DELTA_Y_DEC
		SJSR				_ssub_69492
		LOOP_B				$4E,byte_693CB
		SJMPS				byte_6940D
byte_693D6:
		DELTA_X_SET			$E8
		NJSR				_nsub_get_rand_flags
		SBPLS				byte_693E7
		SJSRS				_ssub_693F0
		SJSRS				_ssub_69400
		SJMP				byte_69330	; LONG
byte_693E7:
		SJSRS				_ssub_69400
		SJSRS				_ssub_693F0
		SJMP				byte_69330	; LONG

; =============== S C R I P T   R O U T I N E ===============================
_ssub_693F0:
		DELTA_Y_SET			$E8
		SJSRS				_ssub_693F5

; !FALLTHROUGH!

; =============== S C R I P T   R O U T I N E ===============================
_ssub_693F5:
		DELTA_Y_INC
		SJSR				_ssub_69492
		LOOP_B				$17,_ssub_693F5
		SJMPS				byte_6940D

; =============== S C R I P T   R O U T I N E ===============================
_ssub_69400:
		DELTA_Y_SET			$18
		SJSRS				_ssub_69405

; !FALLTHROUGH!

; =============== S C R I P T   R O U T I N E ===============================
_ssub_69405:
		DELTA_Y_DEC
		SJSR				_ssub_69492
		LOOP_B				$17,_ssub_69405
byte_6940D:
		SRUN				_OBJ_TYPE_EBULLET,_obj_scr_118
		SRET

; =============== O B J E C T   S C R I P T =================================
byte_69412:
		SRUN				_OBJ_TYPE_EBULLET,_obj_scr_119
		DELTA_X_SET			$00
		DELTA_Y_SET			$00
byte_6941A:
		SJSRS				_ssub_69492
		LOOP_A				$78,byte_6941A
		DELTA_X_SET			$DC
		DELTA_Y_SET			$0A
byte_69425:
		SJSRS				_ssub_69492
		LOOP_A				$21,byte_69425
		LOOP_B				$02,byte_69412
		SJMP				byte_69330	; LONG

; =============== S C R I P T ===============================================
_obj_scr_118:
		GRABABLE_ON
		NJSR				_nsub_get_box_bonus_prize_from_list
		SSWITCH				_tmp_ptrE+1
		SCASE				byte_69442
		SCASE				byte_69442
		SCASE				byte_69443
		SCASE				byte_69443
byte_69442:
		KILL
byte_69443:
		APU_SE_SET			_apu_mus2B
		POS_X_MOVE			$D4
		POS_Y_MOVE			$E5
		DESTR_PC_SET		_obj_scr_118_destr
		SPR_LIB_SET			_spr_lib8
		SPR_IDX_SET			_spr_lib8_11
		SIZE_SET			$06,$0D
		HP_SET				$01
		DAMAGE_SET			_OBJ_DMG_KILL
		SPRITE_ON
		FLIPS_SET			_OBJ_FLIPS08
		NJSR				_nsub_grabable_obj_num_02_cmp
		SBCS				_ssub_y_parabolic_delta_infinite_anim_sync
		SJSR				_ssub_obj_wait_for_jump
		DELTA_Y_SET			$EC
		SPR_IDX_SET			_spr_lib8_12
		SJSR				_ssub_obj_wait_for_jump
		SPR_IDX_SET			_spr_lib8_11
		SJMP				byte_69AFA	; LONG

; =============== S C R I P T ===============================================
_obj_scr_119:
		POS_X_MOVE			$0E
		POS_Y_MOVE			$CA
		SPR_LIB_SET			_spr_lib8
		SPR_IDX_SET			_spr_lib8_13
		NJSR_SYNC			_nsub_sub111
		TARGET_LOCK			$30
		SIZE_SET			$08,$10
		HP_SET				$01
		DAMAGE_SET			_OBJ_DMG_KILL
		SPRITE_ON
		FLIPS_SET			_OBJ_FLIPS08
byte_69486:
		SYNC
		TIMER_B_SET			$FF
		TARGET_FOLLOW
		LOOP_A				$04,byte_69486
		FLIP_H_TOGGLE
		SJMPS				byte_69486

; =============== S C R I P T   R O U T I N E ===============================
_ssub_69492:
		NJSR				_nsub_sub144
		SBEQS				byte_6949E
		APU_SE_SET			_apu_mus2F
		SRUN				_OBJ_TYPE_AUTO,_obj_scr_11A
byte_6949E:
		NJSR				_nsub_sub145
		SYNC
		NJSR				_nsub_sub146
		NJSR				_nsub_sub147
		NJSR				_nsub_sub00D
		SRET

; =============== S C R I P T ===============================================
_obj_scr_11A:
		STORE				$01,byte_E0
byte_694B0:
		SUSPEND				$04
		NJSR				_load_pal_patch00
		SUSPEND				$04
		NJSR				_ppu_pal_apply
		LOOP_B				$04,byte_694B0
		STORE				$00,byte_E0
		KILL

; =============== S U B R O U T I N E =======================================
_load_pal_patch00:
		LDA		#<[_pal_patch00]
		LDY		#>[_pal_patch00]
		JMP		_far_prg3_pal_patch_load

; =============== S C R I P T ===============================================
_obj_scr_boss_ghost_destr:
		NJSR				_scr_flips_04_set
		SPRITE_OFF
		APU_SE_SET			_apu_mus70
		PAL_FADE_OUT		$04,$87
		SUSPEND				$80
		SJMP				_ssub_stage_complete_flag_set

; =============== S U B R O U T I N E =======================================
_nsub_sub00B:
		LDA		#$40
		LDY		#$00

; !FALLTHROUGH!

; =============== S U B R O U T I N E =======================================
_nsub_sub00B_ex:
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
_nsub_sub00C:
		LDA		_hor_menu_pos
		STA		_ppu_scroll_shadow_hi
		LDA		_tmp48
		STA		_ppu_scroll_nt_vert
		RTS

; =============== S U B R O U T I N E =======================================
_nsub_sub00D:
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
_ssub_69531:
		NJSR				_nsub_sub00B
		CHR_SET				$00,$13
		SRUN				_OBJ_TYPE_AUTO,_obj_scr_11B
		SRUN				_OBJ_TYPE_AUTO,_obj_scr_11C
		SUSPEND				$80
		SRET

; =============== S C R I P T ===============================================
_obj_scr_11B:
		POS_X_SET			$48,$00
		SJMPS				byte_6954B

; =============== S C R I P T ===============================================
_obj_scr_11C:
		POS_X_SET			$B8,$00
byte_6954B:
		POS_Y_SET			$6D,$00
		SIZE_SET			$05,$0A
byte_69551:
		SPR_LIB_SET			_spr_lib8
		FLIP_V_ON
		SPRITE_ON
		SPR_IDX_SET			_spr_lib8_3F
		SYNC
		SYNC
		SPR_IDX_SET			_spr_lib8_54
		SYNC
		SYNC
		LOOP_A				$20,byte_69551
		KILL

; =============== O B J E C T   S C R I P T =================================
_obj_scr43_lvl5B_cat_with_cards:
		STORE				_apu_mus0E_idx,_apu_load_idx_req
		DESTR_PC_SET		_obj_scr_common_small_boss_destr
		NJSR				_nsub_obj_idxCs_C0_clear
		POS_X_MOVE			$50
		SPR_LIB_SET			_spr_lib8
		HP_SET				$08
		DAMAGE_SET			_OBJ_DMG_KILL
		SIZE_SET			$0C,$2C
		SUSPEND				$30
		SPRITE_ON
		DELTA_X_SET			$F0
byte_6957C:
		SPR_IDX_SET			_spr_lib8_35
		SJSR				_obj_scr_20A_anim_anim0A_sync
		SPR_IDX_SET			_spr_lib8_36
		SJSR				_obj_scr_20A_anim_anim0A_sync
		SPR_IDX_SET			_spr_lib8_37
		SJSR				_obj_scr_20A_anim_anim0A_sync
		SPR_IDX_SET			_spr_lib8_36
		SJSR				_obj_scr_20A_anim_anim0A_sync
		LOOP_A				$02,byte_6957C
byte_69594:
		SJSR				_ssub_6963C
		NJSR				_nsub_get_rand_clamp3
		SSWITCH				_tmp_ptrE+1
		SCASE				byte_695C1
		SCASE				byte_695A5
		SCASE				byte_6961F
		SCASE				byte_6961F
byte_695A5:
		NJSR				_nsub_cmp40_obj_y_lo_pos
		SBEQS				byte_695B9
		NJSR				_nsub_cmpC0_obj_y_lo_pos
		SBEQS				byte_695B7
		NJSR				_nsub_get_rand_flags
		SBPLS				byte_695B9
byte_695B7:
		DELTA_Y_SET			$AE
byte_695B9:
		SPR_IDX_SET			_spr_lib8_36
		SJSR				_obj_scr_20B
		SJMPS				byte_69594
byte_695C1:
		DELTA_X_SET			$18
		NJSR				_nsub_obj_hor_delta_toggle
byte_695C6:
		SPR_IDX_SET			_spr_lib8_35
		SJSRS				_ssub_boss_cat_with_cards_ai
		SPR_IDX_SET			_spr_lib8_36
		SJSRS				_ssub_boss_cat_with_cards_ai
		SPR_IDX_SET			_spr_lib8_37
		SJSRS				_ssub_boss_cat_with_cards_ai
		SPR_IDX_SET			_spr_lib8_36
		SJSRS				_ssub_boss_cat_with_cards_ai
		SJMPS				byte_695C6

; =============== S C R I P T ===============================================
_ssub_boss_cat_with_cards_ai:
		SYNC
		SJSR				_obj_scr_20A_anim
		NJSR				_obj_move_hor_animate
		NJSR				_nsub_sub135
		SBCSS				byte_695F5
		NJSR				_nsub_obj_to_tile_collision_test_down
		SBCCS				byte_695FC
		LOOP_A				$0A,_ssub_boss_cat_with_cards_ai
		SRET
byte_695F5:
		NJSR				_nsub_obj_hor_move_reverse
		LOOP_A_STOP
		BREAK				byte_69594
byte_695FC:
		SPR_IDX_SET			_spr_lib8_36
		DELTA_Y_SET			$D8
byte_69600:
		SYNC
		SJSR				_obj_scr_20A_anim
		NJSR				_obj_move_hor_animate
		NJSR				_nsub_obj_jump_up_anim
		SBPLS				byte_69613
		NJSR				_obj_vert_anim
		SJMPS				byte_69600
byte_69613:
		NJSR				_obj_to_tile_grid_collision_test_down
		SBCCS				byte_69600
		DELTA_Y_SET			$00
		LOOP_A_STOP
		BREAK				byte_695C6
byte_6961F:
		SPR_IDX_SET			_spr_lib8_38
		SJSR				_obj_scr_20A_anim_anim0A_sync
		SPR_IDX_SET			_spr_lib8_39
		SJSR				_obj_scr_20A_anim_anim06_sync
		SJSR				_obj_scr_20A_anim_anim_sync
		SRUN				_OBJ_TYPE_EBULLET,_obj_scr_boss_cat_with_cards_projectile
		SPR_IDX_SET			_spr_lib8_3A
		SJSR				_obj_scr_20A_anim_anim10_sync
		LOOP_A				$02,byte_6961F
		SJMP				byte_69594	; LONG

; =============== S C R I P T   R O U T I N E ===============================
_ssub_6963C:
		SPR_IDX_SET			_spr_lib8_34
		DELTA_X_SET			$00
byte_69640:
		SJSR				_obj_scr_20A_anim_anim_sync
		LOOP_A				$30,byte_69640
		SRET

; =============== S C R I P T ===============================================
_obj_scr_boss_cat_with_cards_projectile:
		GRABABLE_ON
		APU_SE_SET			_apu_mus6E
		SIZE_SET			$06,$06
		HP_SET				$01
		DAMAGE_SET			_OBJ_DMG_KILL
		SPR_LIB_SET			_spr_lib8
		SPRITE_ON
		NJSR				_nsub_obj_hor_bounce2C
		POS_Y_MOVE			$EF
		TARGET_LOCK			$40
		NJSR				_nsub_cat_with_cards_projectile_anim_select
		NJSR				_nsub_grabable_obj_num_02_cmp
		SBCS				_ssub_target_follow_down_infinite
		SJSR				_ssub_target_follow_down_to_ground
		SPR_IDX_SET			_spr_lib8_3B
		DELTA_X_SET			$18
		DELTA_Y_SET			$00
		NJSR				_nsub_obj_hor_delta_toggle
byte_69671:
		SJSR				_ssub_anim_sync_frames10
		NJSR				_nsub_sub007
		SBCCS				byte_69671
		DESTR_PC_SET		_obj_scr_118_destr
		DELTA_X_SET			$00
		SJMP				byte_69AFA	; LONG

; =============== S U B R O U T I N E =======================================
_nsub_cat_with_cards_projectile_anim_select:
		JSR		_nsub_sub111
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
		LDY		_scr_timerAs,X
		LDA		(_tmp_ptr0),Y
		STA		_scr_timerAs,X
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
		NJSR				_nsub_obj_idxCs_C0_clear
		POS_X_MOVE			$60
		SPR_LIB_SET			_spr_lib8
		HP_SET				$08
		DAMAGE_SET			_OBJ_DMG_KILL
		SIZE_SET			$08,$30
		SUSPEND				$40
		SPRITE_ON
		DELTA_X_SET			$F0
byte_69785:
		APU_SE_SET			_apu_mus6A
		SPR_IDX_SET			_spr_lib8_2D
		SJSR				_obj_scr_20A_anim_anim08_sync
		SPR_IDX_SET			_spr_lib8_2E
		SJSR				_obj_scr_20A_anim_anim08_sync
		APU_SE_SET			_apu_mus6A
		SPR_IDX_SET			_spr_lib8_2F
		SJSR				_obj_scr_20A_anim_anim08_sync
		SPR_IDX_SET			_spr_lib8_30
		SJSR				_obj_scr_20A_anim_anim08_sync
		APU_SE_SET			_apu_mus6A
		SPR_IDX_SET			_spr_lib8_31
		SJSR				_obj_scr_20A_anim_anim08_sync
		SPR_IDX_SET			_spr_lib8_2C
		SJSR				_obj_scr_20A_anim_anim08_sync
		LOOP_A				$02,byte_69785
byte_697AD:
		SJSR				_ssub_69859
		NJSR				_nsub_get_rand_flags
		SBPLS				byte_697BF
		NJSR				_nsub_cmpC0_obj_y_lo_pos
		SBNES				byte_697BF
		SJSRS				_ssub_697D8
byte_697BF:
		SJSRS				_ssub_69845
		SJSRS				_ssub_697ED
		NJSR				_nsub_get_rand_flags
		SBPLS				byte_697CF
		DELTA_Y_SET			$AC
		APU_SE_SET			_apu_mus54
byte_697CF:
		SJSRS				_ssub_697ED
		NJSR				_nsub_obj_hor_move_reverse
		SJMPS				byte_697AD

; =============== S C R I P T   R O U T I N E ===============================
_ssub_697D8:
		DELTA_X_SET			$40
		SJSRS				_ssub_697EF
		SJSRS				_ssub_697EF
		NJSR				_nsub_obj_hor_move_reverse
		SJSRS				_ssub_697EF
		SJSRS				_ssub_697EF
		NJSR				_nsub_obj_hor_move_reverse
		SRET

; =============== S C R I P T   R O U T I N E ===============================
_ssub_697ED:
		DELTA_X_SET			$20

; !FALLTHROUGH!

; =============== S C R I P T   R O U T I N E ===============================
_ssub_697EF:
		NJSR				_nsub_obj_hor_delta_toggle
		SPR_IDX_SET			_spr_lib8_2D
		SJSRS				_ssub_69813
		SPR_IDX_SET			_spr_lib8_2E
		APU_SE_SET			_apu_mus6A
		SJSRS				_ssub_69813
		SPR_IDX_SET			_spr_lib8_2F
		SJSRS				_ssub_69813
		SPR_IDX_SET			_spr_lib8_30
		APU_SE_SET			_apu_mus6A
		SJSRS				_ssub_69813
		SPR_IDX_SET			_spr_lib8_31
		SJSRS				_ssub_69813
		SPR_IDX_SET			_spr_lib8_2C
		APU_SE_SET			_apu_mus6A

; !FALLTHROUGH!

; =============== S C R I P T   R O U T I N E ===============================
_ssub_69813:
		SYNC
		SJSR				_obj_scr_20A_anim
		NJSR				_obj_move_hor_animate
		NJSR				_nsub_sub149
		SBNES				byte_69840
		NJSR				_nsub_get_obj_y_delta
		SBNES				byte_6982C
		NJSR				_nsub_obj_to_tile_collision_test_down
		SBCSS				byte_69840
byte_6982C:
		NJSR				_nsub_obj_jump_up_anim
		SBPLS				byte_69838
		NJSR				_obj_vert_anim
		SJMPS				byte_69840
byte_69838:
		NJSR				_obj_to_tile_grid_collision_test_down
		SBCCS				byte_69840
		DELTA_Y_SET			$00
byte_69840:
		LOOP_A				$08,_ssub_69813
		SRET

; =============== S C R I P T   R O U T I N E ===============================
_ssub_69845:
		DELTA_X_SET			$00
		NJSR				_nsub_box_bonus_3prizes_shuffle
byte_6984A:
		APU_SE_SET			_apu_mus54
		DELTA_Y_SET			$D0
		SJSR				_obj_scr_20B
		SRUN				_OBJ_TYPE_EBULLET,_obj_scr_11E
		LOOP_A				$03,byte_6984A

; =============== S C R I P T   R O U T I N E ===============================
_ssub_69859:
		DELTA_X_SET			$00
byte_6985B:
		SJSR				_obj_scr_20A_anim_anim10_sync
		LOOP_A				$03,byte_6985B
		SRET

; =============== S C R I P T ===============================================
_obj_scr_11E:
		GRABABLE_ON
		NJSR				_nsub_get_box_bonus_prize_from_list
		SSWITCH				_tmp_ptrE+1
		SCASE				byte_69870
		SCASE				byte_69875
		SCASE				byte_6987A
byte_69870:
		DELTA_X_SET			$18
		SJMPS				byte_6987C
byte_69875:
		DELTA_X_SET			$24
		SJMPS				byte_6987C
byte_6987A:
		DELTA_X_SET			$30
byte_6987C:
		SPR_LIB_SET			_spr_lib8
		SIZE_SET			$06,$10
		HP_SET				$01
		DAMAGE_SET			_OBJ_DMG_KILL
		SPRITE_ON
		DELTA_Y_SET			$D0
		NJSR				_nsub_obj_hor_delta_toggle
		NJSR				_nsub_grabable_obj_num_02_cmp
		SBCCS				byte_698A7
byte_69891:
		SPR_IDX_SET			_spr_lib8_32
		SJSRS				_ssub_6989E
		SPR_IDX_SET			_spr_lib8_33
		SJSRS				_ssub_6989E
		SJMPS				byte_69891

; =============== S C R I P T   R O U T I N E ===============================
_ssub_6989E:
		ANIMATE_HV_SYNC
		NJSR				_nsub_obj_jump_up_anim
		LOOP_A				$06,_ssub_6989E
		SRET
byte_698A7:
		SJSRS				_ssub_698B5
		DELTA_Y_SET			$E8
		SJSRS				_ssub_698B5
		DESTR_PC_SET		_obj_scr_118_destr
		SJMP				byte_69AFA	; LONG

; =============== S C R I P T   R O U T I N E ===============================
_ssub_698B5:
		SPR_IDX_SET			_spr_lib8_32
		SJSRS				_ssub_698C9
		SBCSS				byte_698C8
		SPR_IDX_SET			_spr_lib8_33
		SJSRS				_ssub_698C9
		SBCSS				byte_698C8
		SJMPS				_ssub_698B5
byte_698C8:
		SRET

; =============== S C R I P T   R O U T I N E ===============================
_ssub_698C9:
		SJSR				_ssub_obj_jump_sync
		SBCSS				byte_698D3
		LOOP_A				$06,_ssub_698C9
byte_698D3:
		LOOP_A_STOP
		SRET

; =============== O B J E C T   S C R I P T =================================
_obj_scr45_lvl5C_wrecking_lizard:
		STORE				_apu_mus1E_idx,_apu_load_idx_req
		DESTR_PC_SET		_obj_scr_wrecking_lizard_destr
		STORE				$40,_ppu_scroll_shadow_lo
		STORE				$05,_ppu_scroll_nt_hor
		HP_SET				$08
		DAMAGE_SET			_OBJ_DMG_KILL
		POS_X_SET			$88,$01
		POS_Y_SET			$78,$00
		SRUN				_OBJ_TYPE_EBULLET,_obj_scr_11F
		SRUN				_OBJ_TYPE_ENEMY,_obj_scr_120
		NJSR				_nsub_cur_obj_idx_to_idxCs_store
		NJSR				_nsub_obj_idxCs_C0_clear
		SPR_LIB_SET			_spr_lib8
		SPR_IDX_SET			_spr_lib8_00
		SUSPEND				$80
		SPRITE_ON
		SIZE_SET			$08,$20
byte_69906:
		SJSRS				_ssub_69961
		LOOP_B				$06,byte_69906
byte_6990D:
		NJSR				_nsub_sub010
		SBEQS				byte_69924
		DELTA_X_SET			$E0
		SPR_IDX_SET			_spr_lib8_00
		STORE				$0B,_pal_anim_mode_idx
		SJSRS				_ssub_69969
		SJSRS				_ssub_69969
		SJMPS				byte_6994D
byte_69924:
		NJSR				_nsub_sub00F
		SBCCS				byte_6994D
		NJSR				_nsub_get_rand_scale3
		SSWITCH				_tmp_ptrE+1
		SCASE				byte_69936
		SCASE				byte_6994D
		SCASE				byte_6995B
byte_69936:
		DELTA_X_SET			$00
		SPR_IDX_SET			_spr_lib8_01
		STORE				$00,_pal_anim_mode_idx
		SJSRS				_ssub_69969
		NJSR				_nsub_idxBs_10_test_clear_from_idxCs
		SJSRS				_ssub_69969
		SJSRS				_ssub_69969
		SJSRS				_ssub_69969
byte_6994D:
		DELTA_X_SET			$10
		SPR_IDX_SET			_spr_lib8_02
		STORE				$0A,_pal_anim_mode_idx
		SJSRS				_ssub_69969
		SJMPS				byte_6990D
byte_6995B:
		SJSRS				_ssub_69961
		SJMPS				byte_6990D

; =============== S C R I P T   R O U T I N E ===============================
_ssub_69961:
		DELTA_X_SET			$F0
		SPR_IDX_SET			_spr_lib8_00
		STORE				$0B,_pal_anim_mode_idx

; !FALLTHROUGH!

; =============== S C R I P T   R O U T I N E ===============================
_ssub_69969:
		NJSR				_nsub_sub011
		NJSR				_nsub_sub144
		SBEQS				byte_69978
		APU_SE_SET			_apu_mus2F
		SRUN				_OBJ_TYPE_AUTO,_obj_scr_121
byte_69978:
		NJSR				_nsub_sub145
		SYNC
		LOOP_A				$20,_ssub_69969
		SRET

; =============== S C R I P T ===============================================
_obj_scr_wrecking_lizard_destr:
		SPR_IDX_SET			_spr_lib8_06
		STORE				$00,_pal_anim_mode_idx
		APU_SE_SET			_apu_mus70
byte_69989:
		NJSR				_nsub_sub012
		SUSPEND				$20
		NJSR				_nsub_sub012
		SUSPEND				$20
		LOOP_B				$04,byte_69989
		SJMP				_ssub_stage_complete_flag_set

; =============== S U B R O U T I N E =======================================
_nsub_sub00F:
		LDA		_obj_x_lo_poss,X
		CMP		#$A9
		JMP		_scr_flags_update

; =============== S U B R O U T I N E =======================================
_nsub_sub010:
		LDA		_obj_x_hi_poss,X
		JMP		_scr_flags_update

; =============== S U B R O U T I N E =======================================
_nsub_sub011:
		JSR		_nsub_sub146
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
_nsub_sub012:
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
_obj_scr_121:
		NJSR				_nsub_obj_idxCs_C0_clear
		POS_Y_MOVE			$FF
		SPR_LIB_SET			_spr_lib8
		SPR_IDX_SET			_spr_lib8_03
		SPRITE_ON
byte_699E5:
		SUSPEND				$04
		NJSR				_nsub_pal_patch01_load
		SUSPEND				$04
		NJSR				_ppu_pal_apply
		LOOP_B				$04,byte_699E5
		KILL

; =============== S U B R O U T I N E =======================================
_nsub_pal_patch01_load:
		LDA		#<[_pal_patch01]
		LDY		#>[_pal_patch01]
		JMP		_far_prg3_pal_patch_load

; =============== S C R I P T ===============================================
_obj_scr_11F:
		NJSR				_nsub_obj_idxCs_C0_clear
		POS_Y_MOVE			$3F
		SIZE_SET			$24,$40
		HP_SET				$01
		DAMAGE_SET			_OBJ_DMG_KILL
byte_69A07:
		SYNC
		SJSRS				_ssub_69A12
		SJMPS				byte_69A07

; =============== S C R I P T   R O U T I N E ===============================
_ssub_69A0E:
		SYNC
		NJSR				_scr_flips_04_clear

; !FALLTHROUGH!

; =============== S C R I P T   R O U T I N E ===============================
_ssub_69A12:
		NJSR				_nsub_get_obj3_hp
		SBNES				byte_69A1B
		SIZE_SET			$00,$00
byte_69A1B:
		SRET

; =============== S C R I P T ===============================================
_obj_scr_120:
		NJSR				_nsub_obj_idxCs_C0_clear
		POS_X_MOVE			$94
		POS_Y_MOVE			$48
		SPR_LIB_SET			_spr_lib8
		SPR_IDX_SET			_spr_lib8_08
		SIZE_SET			$08,$20
		HP_SET				$FF
		DAMAGE_SET			$FF
		SPRITE_ON
		SJSRS				_ssub_69A5B
byte_69A32:
		NJSR				_nsub_idxBs_10_set
byte_69A35:
		SJSRS				_ssub_69A0E
		NJSR				_nsub_idxBs_10_test
		SBNES				byte_69A35
		SJSRS				_ssub_69A6E
		APU_SE_SET			_apu_mus63
		SRUN				_OBJ_TYPE_EBULLET,_obj_scr_122
		SJSRS				_ssub_69A0E
		SRUN				_OBJ_TYPE_EBULLET,_obj_scr_123
byte_69A4E:
		SJSRS				_ssub_69A0E
		LOOP_B				$3C,byte_69A4E
		SJSRS				_ssub_69A5B
		SJMPS				byte_69A32

; =============== S C R I P T   R O U T I N E ===============================
_ssub_69A5B:
		DELTA_Y_SET			$E0
byte_69A5D:
		SJSRS				_ssub_69A0E
		NJSR				_obj_vert_anim
		NJSR				_nsub_sub013
		NJSR				_nsub_sub014
		LOOP_A				$18,byte_69A5D
		SRET

; =============== S C R I P T   R O U T I N E ===============================
_ssub_69A6E:
		DELTA_Y_SET			$40
byte_69A70:
		SJSRS				_ssub_69A0E
		NJSR				_obj_vert_anim
		NJSR				_nsub_sub015
		NJSR				_nsub_sub013
		LOOP_A				$0C,byte_69A70
		SRET

; =============== S U B R O U T I N E =======================================
_nsub_sub013:
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
_nsub_sub014:
		INC		_scr_loopsB,X
		RTS

; =============== S U B R O U T I N E =======================================
_nsub_sub015:
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
_obj_scr_122:
		DELTA_X_SET			$F0
		SJMPS				byte_69AD8

; =============== S C R I P T ===============================================
_obj_scr_123:
		DELTA_X_SET			$10
byte_69AD8:
		GRABABLE_ON
		DESTR_PC_SET		_obj_scr_118_destr
		DELTA_Y_SET			$D0
		SPR_LIB_SET			_spr_lib8
		SPR_IDX_SET			_spr_lib8_07
		SIZE_SET			$06,$10
		HP_SET				$01
		DAMAGE_SET			_OBJ_DMG_KILL
		SPRITE_ON
		FLIPS_SET			_OBJ_FLIPS08
		NJSR				_nsub_grabable_obj_num_02_cmp
		SBCS				_ssub_y_parabolic_delta_infinite_anim_sync
		SJSR				_ssub_obj_wait_for_jump
		DELTA_Y_SET			$E8
		SJSR				_ssub_obj_wait_for_jump
byte_69AFA:
		NJSR				_nsub_obj_type_change_solid_no_damage
		SJSR				_ssub_obj_wait_for_pickup
_obj_scr_118_destr:
		SJSR				_ssub_obj_wait_for_throw
		FLIPS_SET			_OBJ_FLIPS08
		NJSR				_nsub_obj_throw_direction_select
byte_69B08:
		ANIMATE_HV_SYNC
		NJSR				_nsub_sub016
		SBNES				byte_69B08
		SJMP				_ssub_y_parabolic_delta_infinite_anim_sync

; =============== S U B R O U T I N E =======================================
_nsub_sub016:
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
		NJSR				_nsub_lvl6_final_boss_init
		STORE				$00,_ppu_scroll_nt_vert
		STORE				_apu_mus1F_idx,_apu_load_idx_req
		SRUN				_OBJ_TYPE_AUTO,_obj_scr_124
		SRUN				_OBJ_TYPE_AUTO,_obj_scr_125
		SRUN				_OBJ_TYPE_AUTO,_obj_scr_126
		SRUN				_OBJ_TYPE_AUTO,_obj_scr_127
		NJSR				_nsub_idxBs_10_set
byte_69B49:
		NJSR_SYNC			_nsub_idxBs_10_test
		SBNES				byte_69B49
		CHR_SET				$00,$1C
		CHR_SET				$01,$0D
		STORE				<[_tileset05],_room_tileset_ptr
		STORE				>[_tileset05],_room_tileset_ptr+1
byte_69B5D:
		NJSR_SYNC			_nsub_sub14F
		LOOP_A				$0F,byte_69B5D
		LOOP_B				$10,byte_69B5D
		NJSR				_pal_bg003_reload
		DESTR_PC_SET		_obj_scr46_lvl6_final_boss_destr
		NJSR				_nsub_obj_idxCs_C0_clear
		SPR_LIB_SET			_spr_lib8
		SPR_IDX_SET			_spr_lib8_51
		HP_SET				$0A
		DAMAGE_SET			_OBJ_DMG_KILL
		SIZE_SET			$00,$00
		NJSR				_nsub_sub00C
		PAL_FADE_IN			$04,$C3
		SRUN				_OBJ_TYPE_ENEMY,_obj_scr_128
		NJSR				_nsub_cur_obj_idx_to_idxCs_store
		SRUN				_OBJ_TYPE_ENEMY,_obj_scr_129
		NJSR				_nsub_cur_obj_idx_to_idxBs_store
		SUSPEND				$14
		SPRITE_ON
		SIZE_SET			$28,$70
		NJSR				_nsub_sub021
		SJSR				_ssub_69C88
		DELTA_Y_SET			$F0
		SRUN				_OBJ_TYPE_ENEMY,_obj_scr_12A
		SJSR				_sript_sub_69C7E
byte_69BA5:
		SJSR				_ssub_69D06
		LOOP_A				$30,byte_69BA5
		DELTA_Y_SET			$40
byte_69BAE:
		SJSR				_ssub_69D06
		LOOP_A				$10,byte_69BAE
		SJSR				_ssub_69C4E
byte_69BB8:
		SJSR				_ssub_69C88
byte_69BBB:
		DELTA_Y_SET			$F0
		SRUN				_OBJ_TYPE_ENEMY,_obj_scr_12A
		SJSR				_sript_sub_69C7E
byte_69BC4:
		SJSR				_ssub_69D06
		LOOP_A				$C0,byte_69BC4
		DELTA_Y_SET			$00
		SIZE_SET			$00,$00
byte_69BD0:
		SJSR				_ssub_69CDC
		LOOP_B				$3C,byte_69BD0
		SRUN				_OBJ_TYPE_PBULLET,_obj_scr_12B
		NJSR				_nsub_sub01D
		SRUN				_OBJ_TYPE_AUTO,_obj_scr_12C
byte_69BE2:
		SJSR				_ssub_69CDC
		LOOP_B				$B4,byte_69BE2
		SIZE_SET			$28,$70
		DELTA_Y_SET			$40
byte_69BEE:
		SJSR				_ssub_69D06
		LOOP_A				$34,byte_69BEE
		SJSRS				_ssub_69C4E
		NJSR				_nsub_sub01C
		SBCSS				byte_69C10
		NJSR				_nsub_box_bonus_4prizes_shuffle
		SRUN				_OBJ_TYPE_EBULLET,_obj_scr_12D
byte_69C05:
		SJSR				_ssub_69CDC
		LOOP_B				$3C,byte_69C05
		SRUN				_OBJ_TYPE_EBULLET,_obj_scr_12D
byte_69C10:
		NJSR				_nsub_cmpC0_obj_x_lo_pos
		SBNES				byte_69BB8
		NJSR				_nsub_get_rand_scale3
		SSWITCH				_tmp_ptrE+1
		SCASE				byte_69C22
		SCASE				byte_69C2F
		SCASE				byte_69C3C
byte_69C22:
		SSWITCH				byte_E0
		SCASE				byte_69C2F
		SCASE				byte_69C29
byte_69C29:
		NJSR_SYNC			_nsub_idxBs_10_test_clear_from_idxBs
		SJMPS				byte_69C40
byte_69C2F:
		SSWITCH				byte_E1
		SCASE				byte_69C3C
		SCASE				byte_69C36
byte_69C36:
		NJSR_SYNC			_nsub_idxBs_10_test_clear_from_idxCs
		SJMPS				byte_69C40
byte_69C3C:
		SRUN				_OBJ_TYPE_AUTO,_obj_scr_12E
byte_69C40:
		SJSR				_ssub_69CDC
		LOOP_B				$B4,byte_69C40
		LOOP_A				$02,byte_69C10
		SJMP				byte_69BBB	; LONG

; =============== S C R I P T   R O U T I N E ===============================
_ssub_69C4E:
		APU_SE_SET			_apu_mus44
		DELTA_Y_SET			$E0
		SJSRS				_ssub_69C76
		DELTA_Y_SET			$E8
		SJSRS				_ssub_69C76
		DELTA_Y_SET			$F0
		SJSRS				_ssub_69C76
		DELTA_Y_SET			$F8
		SJSRS				_ssub_69C76
		TIMER_B_SET			$06
		SJSRS				_ssub_69CB5
		TIMER_B_SET			$04
		SJSRS				_ssub_69CB5
		DELTA_Y_SET			$10
		SJSRS				_ssub_69C76
		APU_SE_SET			_apu_mus44
		SRET

; =============== S C R I P T   R O U T I N E ===============================
_ssub_69C76:
		SJSRS				_ssub_69D06
		LOOP_A				$04,_ssub_69C76
		SRET
_sript_sub_69C7E:
		TIMER_B_SET			$02
		SJSRS				_ssub_69CB5
		TIMER_B_SET			$00
		SJMPS				_ssub_69CB5

; =============== S C R I P T   R O U T I N E ===============================
_ssub_69C88:
		NJSR				_nsub_sub01C
		SBCCS				byte_69CAD
byte_69C8E:
		TIMER_B_SET			$08
		SJSRS				_ssub_69CB5
byte_69C93:
		SJSRS				_ssub_69CDC
		LOOP_B				$3C,byte_69C93
		APU_SE_SET			_apu_mus30
		TIMER_B_SET			$0A
		SJSRS				_ssub_69CB5
byte_69CA1:
		SJSRS				_ssub_69CDC
		LOOP_B				$3C,byte_69CA1
		LOOP_A				$03,byte_69C8E
		SRET
byte_69CAD:
		SJSRS				_ssub_69CDC
		LOOP_B				$F0,byte_69CAD
		SRET

; =============== S C R I P T   R O U T I N E ===============================
_ssub_69CB5:
		NJSR				_nsub_sub017
byte_69CB8:
		SJSRS				_ssub_69CDC
		NJSR				_nsub_macro_patch_line_draw
		SBNES				byte_69CB8
		SRET

; =============== S U B R O U T I N E =======================================
_nsub_sub017:
		LDY		_obj_timerBs,X
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
_ssub_69CDC:
		NJSR				_nsub_sub144
		SBEQS				byte_69CFC
		APU_SE_SET			_apu_mus2F
		SRUN				_OBJ_TYPE_AUTO,_obj_scr_12F
		NJSR				_nsub_sub01C
		SBCSS				byte_69CFC
		NJSR				_nsub_sub018
		SBEQS				byte_69CFC
		STORE				$00,byte_E2
		SRUN				_OBJ_TYPE_AUTO,_obj_scr_130
byte_69CFC:
		SYNC
		NJSR				_nsub_sub145
		SRET

; =============== S U B R O U T I N E =======================================
_nsub_sub018:
		LDA		byte_E2
		JMP		_scr_flags_update

; =============== S C R I P T   R O U T I N E ===============================
_ssub_69D06:
		SJSRS				_ssub_69CDC
		NJSR				_nsub_sub146
		NJSR				_nsub_sub147
		SRET

; =============== S U B R O U T I N E =======================================
_nsub_lvl6_final_boss_init:
		LDA		#$01
		STA		byte_E0
		STA		byte_E1
		STA		byte_E2
		LDA		#$C0
		STA		_obj_x_lo_poss,X
		STA		_obj_y_lo_poss,X
		LDA		#$2C
		LDY		#$00
		JMP		_nsub_sub00B_ex

; =============== S U B R O U T I N E =======================================
_pal_bg003_reload:
		LDX		#$77
		LDA		#<[_pal_bg003]
		LDY		#>[_pal_bg003]
		JMP		_far_prg3_pal_bg_reload

; =============== O B J E C T   S C R I P T =================================
_obj_scr46_lvl6_final_boss_destr:
		DELTA_Y_SET			$00
		SRUN				_OBJ_TYPE_AUTO,_obj_scr_12F
		SRUN				_OBJ_TYPE_AUTO,_obj_scr_130
		SUSPEND				$B4
		APU_SE_SET			_apu_mus70
		PAL_FADE_OUT		$04,$C7
		SUSPEND				$80
		SJMP				_ssub_stage_complete_flag_set

; =============== S C R I P T ===============================================
_obj_scr_130:
		NJSR				_nsub_sub01B
		SRUN				_OBJ_TYPE_AUTO,_obj_scr_131
		SUSPEND				$13
		LOOP_A				$05,_obj_scr_130
		APU_SE_SET			_apu_mus46
		NJSR_SYNC			_cat_boss_bg_patch0_draw
		NJSR_SYNC			_cat_boss_bg_patch1_draw
byte_69D5B:
		NJSR				_nsub_sub01B
		SRUN				_OBJ_TYPE_AUTO,_obj_scr_131
		SUSPEND				$13
		LOOP_A				$03,byte_69D5B
		KILL

; =============== S C R I P T ===============================================
_obj_scr_131:
		SRUN				_OBJ_TYPE_AUTO,_obj_scr_132
		SJSR				_ssub_6A052
		KILL

; =============== S C R I P T ===============================================
_obj_scr_132:
		SPR_LIB_SET			_spr_lib8
		SPR_IDX_SET			_spr_lib8_4D
		SPRITE_ON
		NJSR_SYNC			_nsub_sub01A
		SJMP				byte_689E8	; LONG

; =============== S U B R O U T I N E =======================================
_nsub_sub01A:
		JSR		_nsub_get_rand3
		LDA		byte_69D98,Y
		STA		_obj_y_deltas,X
		JSR		_nsub_get_rand3
		LDA		byte_69F42,Y
		STA		_obj_x_deltas,X
		JSR		_rand
		LSR
		BCS		locret_69D97
		JMP		_j_nsub_complement_x_deltas
locret_69D97:
		RTS

byte_69D98:
		.BYTE	$E8,$E0,$DC,$D8

; =============== S U B R O U T I N E =======================================
_nsub_get_rand3:
		JSR		_rand
		AND		#$03
		TAY
		RTS

; =============== S U B R O U T I N E =======================================
_nsub_sub01B:
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
_nsub_sub01C:
		LDA		_obj_hps,X
		CMP		#$06
		JMP		_scr_flags_update

; =============== S U B R O U T I N E =======================================
_nsub_sub01D:
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
_obj_scr_12F:
		SUSPEND				$04
		NJSR				_pal_patch02_load
		SUSPEND				$04
		NJSR				_ppu_pal_apply
		LOOP_B				$04,_obj_scr_12F
		KILL

; =============== S U B R O U T I N E =======================================
_pal_patch02_load:
		LDA		#<[_pal_patch02]
		LDY		#>[_pal_patch02]
		JMP		_far_prg3_pal_patch_load

; =============== S C R I P T   R O U T I N E ===============================
_ssub_69E42:
		SJSR				_obj_scr_20A_anim_anim_sync
		SJMP				_ssub_69A12	; LONG

; =============== S C R I P T   R O U T I N E ===============================
_ssub_69E48:
		DELTA_X_SET			$00
		DELTA_Y_SET			$00
		NJSR				_nsub_idxBs_10_set
byte_69E4F:
		SJSRS				_ssub_69E42
		NJSR				_nsub_idxBs_10_test
		SBNES				byte_69E4F
		SRET

; =============== S C R I P T ===============================================
_obj_scr_128:
		DESTR_PC_SET		_obj_scr_128_destr
		NJSR				_nsub_obj_idxCs_C0_clear
		HP_SET				$05
		DAMAGE_SET			_OBJ_DMG_KILL
		SIZE_SET			$06,$0C
		POS_X_MOVE			$B2
		POS_Y_MOVE			$C2
		SPR_LIB_SET			_spr_lib8
		SPR_IDX_SET			_spr_lib8_3E
		SPRITE_ON
byte_69E6F:
		SJSRS				_ssub_69E48
		APU_SE_SET			_apu_mus45
		NJSR				_nsub_sub153
		FLIP_H_OFF
		SJSRS				_ssub_69E87
		NJSR				_j_nsub_complement_x_deltas
		NJSR				_nsub_complement_y_deltas
		SJSRS				_ssub_69E87
		SJMPS				byte_69E6F

; =============== S C R I P T   R O U T I N E ===============================
_ssub_69E87:
		SJSRS				_ssub_69E42
		LOOP_A				$24,_ssub_69E87
		SRET

; =============== S C R I P T ===============================================
_obj_scr_128_destr:
		STORE				$00,byte_E1
		SJSR				_ssub_6A069
		KILL

; =============== S C R I P T ===============================================
_obj_scr_129:
		DESTR_PC_SET		_obj_scr_129_destr
		NJSR				_nsub_obj_idxCs_C0_clear
		HP_SET				$05
		DAMAGE_SET			_OBJ_DMG_KILL
		SIZE_SET			$06,$0C
		POS_X_MOVE			$2E
		POS_Y_MOVE			$C0
		SPR_LIB_SET			_spr_lib8
		SPR_IDX_SET			_spr_lib8_4F
		SPRITE_ON
byte_69EAD:
		SJSRS				_ssub_69E48
		APU_SE_SET			_apu_mus54
		DELTA_X_SET			$C8
		DELTA_Y_SET			$20
		SJSRS				_ssub_69ECD
		DELTA_X_SET			$EC
		SJSRS				_ssub_69ED5
		DELTA_X_SET			$14
		SJSRS				_ssub_69ED5
		DELTA_X_SET			$38
		DELTA_Y_SET			$E0
		SJSRS				_ssub_69ECD
		SJMPS				byte_69EAD

; =============== S C R I P T   R O U T I N E ===============================
_ssub_69ECD:
		SJSRS				_ssub_69E42
		LOOP_A				$20,_ssub_69ECD
		SRET

; =============== S C R I P T   R O U T I N E ===============================
_ssub_69ED5:
		DELTA_Y_SET			$B0
byte_69ED7:
		SJSR				_ssub_69E42
		NJSR				_nsub_obj_jump_up_anim
		LOOP_A				$14,byte_69ED7
byte_69EE1:
		NJSR				_nsub_complement_y_deltas
		NJSR				_nsub_obj_jump_up_anim
		SJSR				_ssub_69E42
		NJSR				_nsub_complement_y_deltas
		LOOP_A				$14,byte_69EE1
		APU_SE_SET			_apu_mus6C
		LOOP_B				$02,_ssub_69ED5
		SRET
_obj_scr_129_destr:
		STORE				$00,byte_E0
		SJSR				_ssub_6A069
		KILL

; =============== S C R I P T ===============================================
_obj_scr_12D:
		POS_Y_MOVE			$90
		FLIPS_SET			_OBJ_FLIPS08
		HP_SET				$01
		DAMAGE_SET			_OBJ_DMG_KILL
		SIZE_SET			$04,$10
		SPR_LIB_SET			_spr_lib8
		SPR_IDX_SET			_spr_lib8_46
		SPRITE_ON
		DELTA_Y_SET			$E8
		NJSR				_nsub_sub01E
byte_69F15:
		SJSR				_ssub_obj_jump_sync
		SBCSS				byte_69F23
		LOOP_A				$06,byte_69F15
		FLIP_H_TOGGLE
		SJMPS				byte_69F15
byte_69F23:
		SPR_IDX_SET			_spr_lib8_47
byte_69F25:
		SUSPEND				$04
		FLIP_V_ON
		SUSPEND				$04
		FLIP_H_ON
		SUSPEND				$04
		FLIP_V_OFF
		SUSPEND				$04
		FLIP_H_OFF
		LOOP_A				$02,byte_69F25
		KILL

; =============== S U B R O U T I N E =======================================
_nsub_sub01E:
		JSR		_nsub_get_box_bonus_prize_from_list
		LDY		_tmp_ptrE+1
		LDA		byte_69F42,Y
		STA		_obj_x_deltas,X
		RTS
byte_69F42:
		.BYTE	$F0,$E4,$E8,$EC

; =============== S C R I P T ===============================================
_obj_scr_12C:
		POS_Y_SET			$30,$00
		SPR_LIB_SET			_spr_lib8
		SPR_IDX_SET			_spr_lib8_49
		SPRITE_ON
		SUSPEND				$AA
		KILL

; =============== S C R I P T ===============================================
_obj_scr_12B:
		POS_Y_MOVE			$10
		DESTR_PC_SET		_obj_scr_12B_destr
		HP_SET				$01
		DAMAGE_SET			$FF
		FLIPS_SET			_OBJ_FLIPS08
		SIZE_SET			$06,$0E
		SPR_LIB_SET			_spr_lib8
		SPR_IDX_SET			_spr_lib8_4C
		SPRITE_ON
		SJSR				_ssub_obj_wait_for_jump
		APU_SE_SET			_apu_mus2B
		DELTA_Y_SET			$F0
		SJSR				_ssub_obj_wait_for_jump
		APU_SE_SET			_apu_mus2B
		NJSR				_nsub_obj_type_change_solid_no_damage
byte_69F73:
		SJSRS				_ssub_69FB5
		NJSR				_nsub_get_obj_idxBs
		SBPLS				byte_69F73
_obj_scr_12B_destr:
		NJSR				_nsub_obj_type_change_throw
		NJSR				_nsub_obj_idxCs_C0_clear
byte_69F82:
		SJSRS				_ssub_69FB5
		NJSR				_players_state06_C
		NJSR				_nsub_get_obj_idxBs
		SBMIS				byte_69F82
		APU_SE_SET			_apu_mus24
		FLIPS_SET			_OBJ_FLIPS08
		NJSR				_nsub_obj_idxCs_80_set
		NJSR				_nsub_obj_throw_direction_select
		NJSR				_nsub_idxBs_20_set
		HP_SET				$01
		DAMAGE_SET			$FF
byte_69F9F:
		ANIMATE_HV
		SJSRS				_ssub_69FB5
		NJSR				_nsub_sub016
		SBNES				byte_69F9F
		APU_SE_SET			_apu_mus30
byte_69FAB:
		SJSRS				_ssub_69FB5
		ANIMATE_HV
		NJSR				_nsub_obj_jump_up_anim
		SJMPS				byte_69FAB

; =============== S C R I P T   R O U T I N E ===============================
_ssub_69FB5:
		NJSR_SYNC			_nsub_sub01F
		SBEQS				byte_69FBC
		SRET
byte_69FBC:
		NJSR				_nsub_get_obj_idxBs
		SBPLS				byte_69FCA
		NJSR				_nsub_sub033
		POS_Y_MOVE			$08
		NJSR				_scr_flips_04_clear
byte_69FCA:
		NJSR				_nsub_obj_type_change_throw
		HP_SET				$01
		DAMAGE_SET			_OBJ_DMG_KILL
		SIZE_SET			$0C,$0E
		SJSR				_ssub_6A069
		KILL

; =============== S U B R O U T I N E =======================================
_nsub_sub01F:
		LDA		_scr_vars20,X
		ROL
		ROL
		ROL
		AND		#$03
		TAY
		LDA		_sub01F_spr_list,Y
		STA		_obj_spr_idxs,X
		INC		_scr_vars20,X
		JMP		_scr_flags_update

_sub01F_spr_list:
		.BYTE	_spr_lib8_4C_idx,_spr_lib8_4C_idx,_spr_lib8_4B_idx,_spr_lib8_4A_idx

; =============== S C R I P T ===============================================
_obj_scr_12E:
		FLIPS_SET			_OBJ_FLIPS08
		POS_X_MOVE			$18
		POS_Y_MOVE			$F0
		SPR_LIB_SET			_spr_lib8
		SPR_IDX_SET			_spr_lib8_48
		SJSRS				_ssub_6A04B
		POS_X_MOVE			$09
		POS_Y_MOVE			$F8
		SJSRS				_ssub_6A04B
		POS_X_MOVE			$09
		POS_Y_MOVE			$08
		SJSRS				_ssub_6A04B
		POS_X_MOVE			$05
		POS_Y_MOVE			$09
		SJSRS				_ssub_6A04B
		POS_X_MOVE			$05
		POS_Y_MOVE			$07
		SJSRS				_ssub_6A04B
		POS_X_MOVE			$07
		POS_Y_MOVE			$FE
byte_6A01E:
		SJSRS				_ssub_6A04B
		LOOP_A				$08,byte_6A01E
		SRUN				_OBJ_TYPE_EBULLET,_obj_scr_133
		LOOP_B				$03,byte_6A01E
		KILL

; =============== S C R I P T ===============================================
_obj_scr_133:
		APU_SE_SET			_apu_mus6F
		FLIPS_SET			_OBJ_FLIPS08
		HP_SET				$01
		DAMAGE_SET			_OBJ_DMG_KILL
		SIZE_SET			$04,$08
		SPR_LIB_SET			_spr_lib8
		SPR_IDX_SET			_spr_lib8_48
		DELTA_X_SET			$40
		NJSR				_nsub_sub10E
		NJSR				_nsub_obj_hor_delta_toggle
byte_6A045:
		SJSRS				_ssub_6A04B
		SJMPS				byte_6A045

; =============== S C R I P T   R O U T I N E ===============================
_ssub_6A04B:
		SPRITE_ON
		ANIMATE_HV_SYNC
		ANIMATE_HV_SYNC
		SPRITE_OFF
		ANIMATE_HV_SYNC
		ANIMATE_HV_SYNC
		SRET

; =============== S C R I P T   R O U T I N E ===============================
_ssub_6A052:
		APU_SE_SET			_apu_mus46
		SPR_LIB_SET			_spr_lib8
		SPRITE_ON
		SPR_IDX_SET			_spr_lib8_40
		SUSPEND				$08
		SPR_IDX_SET			_spr_lib8_41
		SUSPEND				$08
		SPR_IDX_SET			_spr_lib8_44
		SUSPEND				$08
		SPR_IDX_SET			_spr_lib8_45
		SUSPEND				$08
		SPRITE_OFF
		SRET

; =============== S C R I P T   R O U T I N E ===============================
_ssub_6A069:
		APU_SE_SET			_apu_mus46
		SPR_LIB_SET			_spr_lib8
		SPRITE_ON
		SPR_IDX_SET			_spr_lib8_40
		SUSPEND				$08
		SPR_IDX_SET			_spr_lib8_41
		SUSPEND				$08
		SPR_IDX_SET			_spr_lib8_42
		SUSPEND				$08
		SPR_IDX_SET			_spr_lib8_43
		SUSPEND				$08
		SPRITE_OFF
		SRET

; =============== S C R I P T ===============================================
_obj_scr_12A:
		SPR_LIB_SET			_spr_lib8
		SPRITE_ON
byte_6A083:
		APU_SE_SET			_apu_mus43
byte_6A085:
		SPR_IDX_SET			_spr_lib8_3F
		NJSR_SYNC			_nsub_sub020
		NJSR_SYNC			_nsub_sub020
		SPR_IDX_SET			_spr_lib8_54
		NJSR_SYNC			_nsub_sub020
		NJSR_SYNC			_nsub_sub020
		LOOP_A				$0A,byte_6A085
		SJMPS				byte_6A083

; =============== S U B R O U T I N E =======================================
_nsub_sub020:
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
_obj_scr_124:
		NJSR				_nsub_obj_idxCs_C0_clear
		FLIPS_SET			_OBJ_FLIPS08
		SPR_LIB_SET			_spr_lib8
		SPR_IDX_SET			_spr_lib8_52
		SPRITE_ON
		POS_Y_SET			$BC,$00
byte_6A0DC:
		POS_X_SET			$00,$00
		SJSRS				_ssub_6A0F7
		POS_X_SET			$20,$00
		SJSRS				_ssub_6A0F7
		POS_X_SET			$10,$00
		SJSRS				_ssub_6A0F7
		POS_X_SET			$30,$00
		SJSRS				_ssub_6A0F7
		SJMPS				byte_6A0DC

; =============== S C R I P T   R O U T I N E ===============================
_ssub_6A0F7:
		SYNC
		POS_X_MOVE			$40
		LOOP_A				$04,_ssub_6A0F7
		SRET

; =============== S C R I P T ===============================================
_obj_scr_125:
		TIMER_B_SET			$04
		POS_X_SET			$20,$00
		POS_Y_SET			$20,$00
		SJSRS				_ssub_6A132
		NJSR				_pal_bg000_load
		KILL

; =============== S C R I P T ===============================================
_obj_scr_126:
		TIMER_B_SET			$02
		POS_X_SET			$C0,$00
		POS_Y_SET			$20,$00
		SJSRS				_ssub_6A132
		NJSR				_pal_bg001_load
		KILL

; =============== S C R I P T ===============================================
_obj_scr_127:
		TIMER_B_SET			$01
		POS_X_SET			$70,$00
		POS_Y_SET			$40,$00
		SJSRS				_ssub_6A132
		NJSR				_pal_bg002_load
		PAL_FADE_OUT		$01,$C0
		NJSR				_nsub_idxBs_10_test_clear_from_idxAs
		KILL

; =============== S C R I P T   R O U T I N E ===============================
_ssub_6A132:
		NJSR				_nsub_loopB_reload_from_timerBs
		SPR_LIB_SET			_spr_lib5
		SPR_IDX_SET			_spr_lib5_06
byte_6A139:
		SPRITE_OFF
		SYNC
		SYNC
		SPRITE_ON
		SYNC
		SYNC
		LOOP_A				$10,byte_6A139
		LOOP_B				$06,byte_6A139
		SPR_IDX_SET			_spr_lib5_07
		APU_SE_SET			_apu_mus6D
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
_nsub_sub021:
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
		SJSRS				_ssub_obj_exit_wait_common		; wait for player collision with object
		NJSR				_nsub_player_exit_left_with_flip_set	; set player parameters to exit with engine
		KILL												; nothing to do here now

; =============== O B J E C T   S C R I P T =================================
_obj_scr21_lvl_exit_right:
; TODO, optimize me!
		SJSRS				_ssub_obj_exit_right_wait		; call common right left test
		KILL

; =============== O B J E C T   S C R I P T =================================
_obj_scr22_lvl5C_box_bonus_entry:
_obj_scr23_lvl4_box_bonus_entry:
		SJSRS				_ssub_obj_exit_right_wait		; set right exit common
		NJSR				_nsub_inc_stage_room_idx		; skip one room ahead, manage your rooms order in _room_cfg_lib
		KILL

; =============== S C R I P T   R O U T I N E ===============================
_obj_scr_lvl2_basket_exit_right_A:
		SJSRS				_ssub_obj_exit_right_wait		; the same as for other entries, but skips two rooms ahead
		NJSR				_nsub_inc_stage_room_idx
		NJSR				_nsub_inc_stage_room_idx
		KILL

; =============== S C R I P T   R O U T I N E ===============================
_ssub_obj_exit_right_wait:
		SJSRS				_ssub_obj_exit_wait_common
		NJSR				_nsub_player_exit_right_with_flip_set
		SRET

; =============== S C R I P T   R O U T I N E ===============================
_ssub_obj_exit_wait_common:
		SIZE_SET			$06,$10
byte_6A19D:
		HP_SET				$01
		SJSR				_ssub_wait_obj_hps_turns_zero
		NJSR				_nsub_obj_player_from_idxAs_05_state_compare
		SBNES				byte_6A19D
		SRET
; TODO, REMOVE ME, one more redundant opcode here
		POS_Y_MOVE			$08
; -

; =============== S C R I P T   R O U T I N E ===============================
_ssub_big_box_opens_anim:
		APU_SE_SET			_apu_mus23
		SPR_LIB_SET			_spr_lib6
		SPRITE_ON
		SPR_IDX_SET			_spr_lib6_04
		SUSPEND				$06
		SPR_IDX_SET			_spr_lib6_05
		SUSPEND				$06
		SPR_IDX_SET			_spr_lib6_06
		SUSPEND				$06
		SPR_IDX_SET			_spr_lib6_07
		SRET

; =============== O B J E C T   S C R I P T =================================
_obj_scr1B_monterey_refill:
		POS_X_MOVE			$50					; set monerei object pos and speed
		POS_X_MOVE			$50
		DELTA_X_SET			$F0
		SPR_LIB_SET			_spr_lib0			; library select and activate
		SPRITE_ON
byte_6A1C8:
		SPR_IDX_SET			_spr_lib0_23		; walk anim loop 40 cycles long
		SJSR				_ssub_anim_sync_frames10
		SPR_IDX_SET			_spr_lib0_24
		SJSR				_ssub_anim_sync_frames10
		SPR_IDX_SET			_spr_lib0_25
		SJSR				_ssub_anim_sync_frames10
		SPR_IDX_SET			_spr_lib0_24
		SJSR				_ssub_anim_sync_frames10
		LOOP_A				$05,byte_6A1C8		; repeat 5 times (5 steps)
		SJSRS				_ssub_6A204
		TIMER_B_SET			$0C
		SRUN				_OBJ_TYPE_TRIGGER,_obj_monterey_1p_prize
		SJSRS				_ssub_6A208
		SJSRS				_ssub_6A204
		TIMER_B_SET			$0C
		SRUN				_OBJ_TYPE_TRIGGER,_obj_monterey_2p_prize
		SJSRS				_ssub_6A208
		SJSRS				_ssub_6A204
		NJSR				_nsub_sub15A
byte_6A1FE:
		SJSRS				_ssub_6A208
		SJMPS				byte_6A1FE

; =============== S C R I P T   R O U T I N E ===============================
_ssub_6A204:
		SPR_IDX_SET			_spr_lib0_1C
		TIMER_B_SET			$00

; !FALLTHROUGH!

; =============== S C R I P T   R O U T I N E ===============================
_ssub_6A208:
		NJSR_SYNC			_nsub_cut_monterey_talk_spr_insert
		LOOP_B				$1E,_ssub_6A208
		SRET

; =============== S C R I P T ===============================================
_obj_monterey_1p_prize:
		DELTA_X_SET			$DE
		SJMPS				_obj_monterey_prize_common

; =============== S C R I P T ===============================================
_obj_monterey_2p_prize:
		DELTA_X_SET			$E8

; =============== S C R I P T   R O U T I N E ===============================
_obj_monterey_prize_common:
		POS_X_MOVE			$F2
		POS_Y_MOVE			$F2
		DELTA_Y_SET			$D8
		SJSRS				_ssub_acorn_prize_init
		SJSR				_ssub_acorn_prize_animate
		NJSR				_nsub_set_def_max_hps_from_idxAs
		KILL

; =============== O B J E C T   S C R I P T =================================
_obj_scr1F_star_prize:
		SPR_LIB_SET			_spr_lib6
		SPR_IDX_SET			_spr_lib6_01
		SIZE_SET			$06,$0C
		HP_SET				$01
		SPRITE_ON
		SJSR				_ssub_wait_obj_hps_turns_zero
		NJSR				_nsub_inc_players_lives_from_idxAs

; FALLTHROUGH!

; =============== S C R I P T ===============================================
_ssub_1up_text_float_up:
		SPR_LIB_SET			_spr_lib6
		SPR_IDX_SET			_spr_lib6_08

; FALLTHROUGH!

; =============== S C R I P T ===============================================
_ssub_prize_text_float_animate_with_se:
		NJSR				_nsub_obj_type_change_auto
		APU_SE_SET			_apu_mus37

; FALLTHROUGH!

; =============== S C R I P T   R O U T I N E ===============================
_ssub_prize_text_float_up_animate:
		POS_Y_MOVE			$F0
		DELTA_X_SET			$00
		DELTA_Y_SET			$FC
		SPRITE_ON
byte_6A247:
		SJSR				_ssub_anim_sync_frames16
		LOOP_A				$04,byte_6A247
		SUSPEND				$14
		KILL
; TODO, REMOVE ME, script can't go here, because it's already killed
		DELTA_Y_SET			$D7
;-

; =============== O B J E C T   S C R I P T =================================
; NOTE, althoug this acorn prize never moved, it uses the same functions
; as for Monterey hp refill prizes in bonus rooms
;
_obj_scr_acorn_prize:
		SJSRS				_ssub_acorn_prize_init
		SJSR				_ssub_acorn_prize_animate
		NJSR				_nsub_increment_players_hps
		KILL

; =============== S C R I P T   R O U T I N E ===============================
_ssub_acorn_prize_init:
		SPR_LIB_SET			_spr_lib6
		SPR_IDX_SET			_spr_lib6_00
		SIZE_SET			$04,$0A
		HP_SET				$01
		SPRITE_ON
		SRET

; =============== S C R I P T   R O U T I N E ===============================
_ssub_big_box_wait_for_trigger:
		SPR_LIB_SET			_spr_lib6
		SPR_IDX_SET			_spr_lib6_03
		SIZE_SET			$10,$20
		HP_SET				$01
		SPRITE_ON
		SJSR				_ssub_wait_obj_hps_turns_zero
		SJMP				_ssub_big_box_opens_anim	; LONG
; TODO: fix me, one time used sub as far sub!

; =============== O B J E C T   S C R I P T =================================
_obj_scr1D_ball_in_box:
		SJSRS				_ssub_big_box_wait_for_trigger
		DESTR_PC_SET		_obj_scr_big_ball_box_destr
		NJSR				_nsub_obj_type_change_solid_no_damage
		SPR_LIB_SET			_spr_lib4
		HP_SET				$01
		SIZE_SET			$06,$0E
		SJMPS				byte_6A2BD
byte_6A28B:
		DELTA_X_SET			$00
		NJSR				_nsub_obj_type_change_solid_no_damage_idxBs_20_clear
byte_6A290:
		SYNC
		NJSR				_nsub_get_obj_idxBs
		SBMIS				_obj_scr_big_ball_box_destr
		SJSR				_ssub_ballistic_throw_anim
		SBCSS				byte_6A290
		SJMPS				byte_6A2AE
_obj_scr_big_ball_box_destr:
		SJSR				_ssub_obj_wait_for_throw
		DELTA_X_SET			$10
		DELTA_Y_SET			$8C
		NJSR				_nsub_sub029
		HP_SET				$01
		DAMAGE_SET			_OBJ_DMG_STUN
byte_6A2AE:
		NJSR				_nsub_sub11C
		NJSR				_nsub_obj_type_change_ball
		SJSRS				_ssub_6A2CF
		NJSR				_far_players_default_state_select_G
		SBPLS				byte_6A28B
byte_6A2BD:
		DELTA_Y_SET			$E0
		SJSRS				_ssub_6A2CF
		DELTA_Y_SET			$F0
		SJSRS				_ssub_6A2CF
		DELTA_Y_SET			$F8
		SJSRS				_ssub_6A2CF
		SJMPS				byte_6A28B

; =============== S C R I P T   R O U T I N E ===============================
_ssub_6A2CF:
		NJSR_SYNC			_nsub_sub022
		HP_SET				$01
		DAMAGE_SET			_OBJ_DMG_STUN
		NJSR				_nsub_obj_jump_up_anim
		SJSR				_ssub_6A557
		SBCCS				_ssub_6A2CF
		SRET

; =============== S U B R O U T I N E =======================================
_nsub_sub022:
		LDA		#<[byte_6A2E7]
		LDY		#>[byte_6A2E7]
		JMP		_nsub_sub023

byte_6A2E7:
		.BYTE	_spr_lib4_03_idx,$00
		.BYTE	_spr_lib4_04_idx,$00
		.BYTE	_spr_lib4_03_idx,$40
		.BYTE	_spr_lib4_04_idx,$C0

; =============== S U B R O U T I N E =======================================
_nsub_sub023:
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
_obj_scr1E_zipper_in_box:
		SJSR				_ssub_big_box_wait_for_trigger
		NJSR				_nsub_obj_type_change_solid_no_damage
		NJSR				_nsub_idxBs_20_set
		FLIPS_SET			_OBJ_UNDER_BG
		SPR_LIB_SET			_spr_lib5
		SPR_IDX_SET			_spr_lib5_08
		SIZE_SET			$14,$0F
		HP_SET				$01
		CHR_SET				$01,$00
		SPRITE_ON
		DELTA_Y_SET			$D7
		SJSR				_ssub_obj_wait_for_jump
byte_6A330:
		NJSR_SYNC			_nsub_obj_to_obj_jump_up_test
		SBCCS				byte_6A330
		SRUN				_OBJ_TYPE_AUTO,_obj_scr_big_zipper_box_zipper
		SUSPEND				$B0
		SRUN				_OBJ_TYPE_AUTO,_obj_scr_big_zipper_box_water
		SJMP				_ssub_suspend_forever

; =============== S C R I P T ===============================================
_obj_scr_big_zipper_box_water:
		SRUN				_OBJ_TYPE_AUTO,_obj_scr_big_zipper_box_flow
		NJSR_SYNC			_nsub_obj_to_obj_idxCs_link
		SUSPEND				$24
		POS_X_MOVE			$C0
		SIZE_SET			$40,$00
byte_6A351:
		NJSR_SYNC			_nsub_big_zipper_box_water_anim
		SJMPS				byte_6A351

; =============== S U B R O U T I N E =======================================
_nsub_big_zipper_box_water_anim:
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
		JSR		_nsub_get_link_obj_idx_from_idxCs
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
		ADDWB	#$20,_tmp_ptr44
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
		JSR		_nsub_players_obj_ride_y_sync
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
		POS_X_MOVE			$86
		POS_Y_MOVE			$B0
		POS_Y_MOVE			$AF
		SPR_LIB_SET			_spr_lib0
		SPR_IDX_SET			_spr_lib0_10
byte_6A404:
		APU_SE_SET			_apu_mus4B
byte_6A406:
		NJSR_SYNC			_nsub_big_zipper_box_flow_anim
		SBCS				_ssub_suspend_forever
		LOOP_A				$28,byte_6A406
		SJMPS				byte_6A404

; =============== S U B R O U T I N E =======================================
_nsub_big_zipper_box_flow_anim:
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
		NJSR				_nsub_look_for_sink_valve_obj
		POS_Y_MOVE			$DA
		SPR_LIB_SET			_spr_lib0
		SPRITE_ON
		DELTA_X_SET			$E7
		DELTA_Y_SET			$E8
byte_6A469:
		SJSRS				_ssub_zipper_box_zipper_anim
		LOOP_B				$0F,byte_6A469
byte_6A470:
		DELTA_X_SET			$00
		DELTA_Y_SET			$00
		SJSRS				_ssub_zipper_box_zipper_anim
		SJSRS				_ssub_zipper_box_zipper_anim
		DELTA_Y_SET			$20
		NJSR				_nsub_idxBs_10_test_clear_from_idxCs
		SJSRS				_ssub_zipper_box_zipper_anim
		DELTA_Y_SET			$F0
		SJSRS				_ssub_zipper_box_zipper_anim
		SJSRS				_ssub_zipper_box_zipper_anim
		LOOP_A				$03,byte_6A470
		NJSR				_nsub_obj_idxCs_80_set
		DELTA_X_SET			$E8
		DELTA_Y_SET			$E8
		SJMP				_ssub_infinite_anim_sync

; =============== S C R I P T   R O U T I N E ===============================
_ssub_zipper_box_zipper_anim:
		SPR_IDX_SET			_spr_lib0_17
		ANIMATE_HV_SYNC
		ANIMATE_HV_SYNC
		ANIMATE_HV_SYNC
		SPR_IDX_SET			_spr_lib0_18
		ANIMATE_HV_SYNC
		ANIMATE_HV_SYNC
		ANIMATE_HV_SYNC
		SRET

; =============== S U B R O U T I N E =======================================
_nsub_look_for_sink_valve_obj:
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
		NJSR				_nsub_idxBs_20_set
		NJSR				_scr_flips_04_set
		SPR_LIB_SET			_spr_lib5
		SPR_IDX_SET			_spr_lib5_09_sink_valve
		SJSR				_ssub_obj_show_wait_for_idxCs_80_set
byte_6A4D0:
		NJSR				_nsub_idxBs_10_set
byte_6A4D3:
		NJSR_SYNC			_nsub_idxBs_10_test
		SBNES				byte_6A4D3
		APU_SE_SET			_apu_mus69
		SUSPEND				$08
		SPR_IDX_SET			_spr_lib5_0A
		SUSPEND				$04
		SPR_IDX_SET			_spr_lib5_0B
		SUSPEND				$04
		SPR_IDX_SET			_spr_lib5_09_sink_valve
		SJMPS				byte_6A4D0

; =============== O B J E C T   S C R I P T =================================
_obj_scr07_concrete_brick:
		DESTR_PC_SET		_obj_scr07_concrete_brick_destr
		NJSR				_nsub_idxBs_10_set
		POS_X_MOVE			$08
		SPR_LIB_SET			_spr_lib4
		SPR_IDX_SET			_spr_lib4_00
		SIZE_SET			$06,$0E
		SJSR				_ssub_obj_show_wait_for_idxCs_80_set
byte_6A4FC:
		SPR_IDX_SET			_spr_lib4_00
		FLIPS_SET			$00
		HP_SET				$01
		DELTA_X_SET			$00
		NJSR				_nsub_obj_type_change_solid_no_damage_idxBs_20_clear
byte_6A507:
		SYNC
		NJSR				_nsub_get_obj_idxBs
		SBMIS				byte_6A517
		SJSRS				_ssub_ballistic_throw_anim
		SBCSS				byte_6A507
		SJMPS				byte_6A53E
byte_6A517:
		NJSR				_nsub_sub164
		NJSR				_nsub_obj_idxCs_C0_clear
byte_6A51D:
		NJSR				_nsub_get_obj_idxBs
		SBPLS				byte_6A535
		NJSR				_nsub_get_obj_hp
		SBEQS				byte_6A52F
		NJSR_SYNC			_nsub_sub02B
		SJMPS				byte_6A51D
byte_6A52F:
		NJSR				_nsub_sub032
		SJMPS				byte_6A4FC
byte_6A535:
		DELTA_X_SET			$10
		DELTA_Y_SET			$8C
		NJSR				_nsub_sub029
		APU_SE_SET			_apu_mus24
byte_6A53E:
		NJSR				_nsub_sub11C
		NJSR				_nsub_obj_type_change_ball
		HP_SET				$FF
		DAMAGE_SET			_OBJ_DMG_STUN
		SPR_IDX_SET			_spr_lib4_00
byte_6A54A:
		SYNC
		NJSR				_nsub_obj_jump_up_anim
		SJSRS				_ssub_6A557
		SBCCS				byte_6A54A
		SJMPS				byte_6A4FC

; =============== S C R I P T   R O U T I N E ===============================
_ssub_6A557:
		NJSR				_nsub_idxBs_20_set
		NJSR				_obj_move_hor_animate
		NJSR				_nsub_sub13C
		SBCSS				byte_6A569
		NJSR				_nsub_obj_to_tile_collision_test_hor
		SBCSS				byte_6A56B
byte_6A569:
		DELTA_X_SET			$00
byte_6A56B:
		NJSR				_nsub_obj_jump_up_anim
		NJSR				_nsub_get_obj_y_delta
		SBPLS				_ssub_ballistic_throw_anim
		NJSR				_obj_vert_anim
		NJSR				_nsub_sub165
		SBCCS				byte_6A583
		NJSR				_nsub_obj_to_tile_collision_test_up
		SBCSS				byte_6A585
byte_6A583:
		DELTA_Y_SET			$01
byte_6A585:
		NJSR				_scr_cmd_clear_carry
		SRET

; =============== S C R I P T   R O U T I N E ===============================
_ssub_ballistic_throw_anim:
		NJSR				_obj_vert_anim
		NJSR				_nsub_sub107
		SBCSS				byte_6A598
		NJSR				_nsub_obj_to_tile_collision_test_down
		SBCCS				byte_6A59A
byte_6A598:
		DELTA_Y_SET			$00
byte_6A59A:
		SRET

; =============== O B J E C T   S C R I P T =================================
_obj_scr07_concrete_brick_destr:
		NJSR				_nsub_idxBs_20_set
		DELTA_X_SET			$00
		NJSR				_nsub_get_obj_y_delta
		SBMIS				byte_6A5A8
		DELTA_Y_SET			$00
byte_6A5A8:
		SJSRS				_ssub_6A5BA
		NJSR				_nsub_sub027
		SBCCS				byte_6A5A8
		NJSR				_nsub_obj_type_change_solid
		SJSRS				_ssub_6A5BA
		SJMPS				byte_6A5A8

; =============== S C R I P T   R O U T I N E ===============================
_ssub_6A5BA:
		SYNC
		NJSR				_nsub_get_obj_idxBs
		SBPLS				byte_6A5C4
		NJSR				_nsub_sub028
byte_6A5C4:
		SRET

; =============== S U B R O U T I N E =======================================
_nsub_sub027:
		LDA		_obj_y_deltas,X
		BPL		loc_6A5CE
		CMP		#$B0
		BCC		loc_6A5D7
loc_6A5CE:
		DEC		_obj_y_deltas,X
		DEC		_obj_y_deltas,X
		DEC		_obj_y_deltas,X
loc_6A5D7:
		JSR		_obj_vert_anim
		JSR		_players_state12_A_B_A
		BCC		loc_6A5E3
		JSR		_nsub_obj_to_obj_y_concat_down
		SEC
loc_6A5E3:
		JMP		_scr_flags_update

; =============== S U B R O U T I N E =======================================
_nsub_sub028:
		LDA		#$00
		STA		_obj_flips,X
		JMP		_nsub_sub033

; =============== S U B R O U T I N E =======================================
_nsub_sub029:
		LDA		_scr_idxBs,X
		AND		#$0F
		TAY
		LDA		_obj_flips,Y
		AND		#_OBJ_HFLIP
		STA		_obj_flips,X
		JSR		_nsub_obj_hor_delta_toggle
		JMP		_nsub_obj_hflip_clear

; =============== O B J E C T   S C R I P T =================================
_obj_scr_box:
		DESTR_PC_SET		_obj_scr_box
		NJSR				_nsub_obj_idxCs_C0_clear
		NJSR				_nsub_idxBs_10_set
		SPR_LIB_SET			_spr_lib3
		SPR_IDX_SET			_spr_lib3_00
		SIZE_SET			$06,$0F
		HP_SET				$01
		SPRITE_ON
byte_6A615:
		NJSR				_nsub_get_obj_idxBs
		SBPLS				byte_6A630
		NJSR				_nsub_get_obj_hp
		SBNES				byte_6A627
		NJSR				_nsub_sub033
		SJMPS				byte_6A669
byte_6A627:
		NJSR				_nsub_sub02B
		NJSR_SYNC			_nsub_sub02E
		SJMPS				byte_6A615
byte_6A630:
		NJSR				_nsub_obj_type_change_throw
		NJSR				_nsub_obj_idxCs_80_set
		NJSR				_nsub_sub02A
		SBNES				byte_6A653
		APU_SE_SET			_apu_mus27
		NJSR				_nsub_sub02F
		DELTA_Y_SET			$F0
byte_6A643:
		SPR_IDX_SET			_spr_lib3_00
		NJSR				_nsub_sub02E
		ANIMATE_HV_SYNC
		LOOP_A				$08,byte_6A643
		NJSR				_nsub_complement_y_deltas
		SJMPS				byte_6A643
byte_6A653:
		SPR_IDX_SET			_spr_lib3_00
		APU_SE_SET			_apu_mus24
		NJSR				_nsub_obj_throw_direction_select
byte_6A65A:
		ANIMATE_HV_SYNC
		NJSR				_nsub_get_obj_hp
		SBPLS				byte_6A666
		NJSR				_j_nsub_complement_x_deltas
		HP_SET				$01
byte_6A666:
		SBNES				byte_6A65A
byte_6A669:
		NJSR_SYNC			_nsub_obj_type_change_auto
		SPR_IDX_SET			_spr_lib3_03
		SYNC
		SPR_IDX_SET			_spr_lib3_04
		SYNC
		SPR_IDX_SET			_spr_lib3_05
		SYNC
		SPR_IDX_SET			_spr_lib3_06
		SYNC
		SPR_IDX_SET			_spr_lib3_07
		SYNC
		KILL

; =============== S U B R O U T I N E =======================================
_nsub_sub02A:
		LDA		_obj_damages,X
		CMP		#_OBJ_DMG_STUN
		JMP		_scr_flags_update

; =============== S U B R O U T I N E =======================================
_nsub_sub02B:
		JSR		_nsub_sub031
		JSR		_players_state06_C
		BMI		_nsub_sub02C
		BEQ		_nsub_sub02C
		LDA		#_OBJ_MODE_HIDE
		STA		_scr_params,X
		RTS

; =============== S U B R O U T I N E =======================================
_nsub_sub02C:
		LDA		_obj_heights,Y
		BEQ		_nsub_sub02D
		JSR		_nsub_obj_type_change_throw
		JMP		_scr_flips_04_set

; =============== S U B R O U T I N E =======================================
_nsub_sub02D:
		INC		_obj_y_lo_poss,X
		JSR		_nsub_obj_type_change_solid
		JMP		_scr_flips_04_clear

; =============== S U B R O U T I N E =======================================
_nsub_sub02E:
		LDA		_nmi_frames_counter
		AND		#$04
		BEQ		locret_6A6BA
		LDA		_obj_damages,X
		CMP		#_OBJ_DMG_STUN
		BNE		locret_6A6BA
		LDA		#_spr_lib3_08_idx
		STA		_obj_spr_idxs,X
locret_6A6BA:
		RTS

; =============== S U B R O U T I N E =======================================
_nsub_sub02F:
		LDA		_scr_idxBs,X
		AND		#$0F
		TAX
		JMP		loc_6A6E5

; =============== S U B R O U T I N E =======================================
_nsub_obj_throw_direction_select:
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
		.BYTE	_PAD_UP|_PAD_LEFT,	$C0,$C0
		.BYTE	_PAD_UP|_PAD_RIGHT,	$40,$C0
		.BYTE	_PAD_UP,			$00,$A0
		.BYTE	_PAD_LEFT,			$C0,$00
		.BYTE	_PAD_RIGHT,			$40,$00

; =============== S U B R O U T I N E =======================================
_nsub_sub031:
		JSR		_nsub_get_idxBs_low_nibble
		LDA		_players_vars09,Y
		STA		_obj_spr_idxs,X
		RTS

; =============== S U B R O U T I N E =======================================
_nsub_sub032:
		JSR		_nsub_get_idxBs_low_nibble
		LDA		_obj_y_lo_poss,Y
		STA		_obj_y_lo_poss,X
		CLC
		SBC		_obj_heights,X
		STA		_obj_y_lo_poss,Y

; =============== S U B R O U T I N E =======================================
_nsub_sub033:
		LDA		_scr_idxBs,X
		AND		#$7F
		STA		_scr_idxBs,X
		JSR		_nsub_get_idxBs_low_nibble
		LDA		_scr_idxBs,Y
		AND		#$BF
		STA		_scr_idxBs,Y
		RTS

; =============== O B J E C T   S C R I P T =================================
_obj_scr_stun_sparkles:
		SPR_LIB_SET			_spr_lib0
		SPR_IDX_SET			_spr_lib0_0F
		FLIPS_SET			_OBJ_FLIPS08|_OBJ_FLIPS04
		SPRITE_ON
byte_6A744:
		DELTA_X_SET			$00
		DELTA_Y_SET			$00
		SJSRS				_ssub_6A77C
		DELTA_X_SET			$C0
		DELTA_Y_SET			$00
		SJSRS				_ssub_6A77C
		DELTA_X_SET			$A0
		DELTA_Y_SET			$E0
		SJSRS				_ssub_6A77C
		DELTA_X_SET			$C0
		DELTA_Y_SET			$B0
		SJSRS				_ssub_6A77C
		DELTA_X_SET			$00
		DELTA_Y_SET			$B0
		SJSRS				_ssub_6A77C
		DELTA_X_SET			$40
		DELTA_Y_SET			$B0
		SJSRS				_ssub_6A77C
		DELTA_X_SET			$60
		DELTA_Y_SET			$E0
		SJSRS				_ssub_6A77C
		DELTA_X_SET			$40
		DELTA_Y_SET			$00
		SJMPS				byte_6A744

; =============== S C R I P T   R O U T I N E ===============================
_ssub_6A77C:
		NJSR				_nsub_obj_linked_idxCs_follow
		ANIMATE_HV_SYNC
		LOOP_A				$04,_ssub_6A77C
		SRET

; =============== O B J E C T   S C R I P T =================================
_obj_scr08_cdv_bottle_cork:
		NJSR				_nsub_idxBs_20_set
		POS_X_MOVE			$08
		SPR_LIB_SET			_spr_lib5
		SPR_IDX_SET			_spr_lib5_00
		SIZE_SET			$08,$07
		HP_SET				$01
		SPRITE_ON
		SJSR				_obj_scr_20D
		SPR_IDX_SET			_spr_lib5_01
		SIZE_SET			$08,$04
		NJSR				_nsub_obj_y_adjust_by_height_from_idxAs
		SJSR				_obj_scr_20D
		SPR_IDX_SET			_spr_lib5_02
		SIZE_SET			$08,$02
		NJSR				_nsub_obj_y_adjust_by_height_from_idxAs
		SJSR				_obj_scr_20D
		SPR_IDX_SET			_spr_lib5_03
		SIZE_SET			$08,$0F
		NJSR				_nsub_obj_y_adjust_by_height_from_idxAs
		APU_SE_SET			_apu_mus4A
		DELTA_X_SET			$10
		DELTA_Y_SET			$C0
byte_6A7BB:
		ANIMATE_HV_SYNC
		NJSR				_nsub_obj_jump_up_anim
		NJSR				_nsub_obj_to_obj_jump_up_test
		SBCCS				byte_6A7BB
		NJSR				_nsub_obj_y_adjust_by_height_from_idxAs
		SJMPS				byte_6A7BB

; =============== O B J E C T   S C R I P T =================================
_obj_scr0A_lvl2_blocked_path:
		SJSRS				_ssub_obj_button_common_init	; init
		SJSRS				_ssub_button_push_wait		; wait for jump up
		SRUN				_OBJ_TYPE_AUTO,_obj_scr_lvl2_wall_blocks_open_draw	; open the blocked path
byte_6A7D5:
		SJSRS				_ssub_button_release_wait		; loop forever between
		SJSRS				_ssub_button_push_wait		; two states now, does nothing more
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
_obj_scr_lvl2_wall_blocks_open_draw:
#if BUGFIXES=1
		STORE				<[_tlm_patch_06A_unused],_tmp_ptr4B	; load tlm patch ptr
		STORE				>[_tlm_patch_06A_unused],_tmp_ptr4B+1
#else
		STORE				<[tlm_patch06],_tmp_ptr4B			; load tlm patch ptr
		STORE				>[tlm_patch06],_tmp_ptr4B+1
#endif
		SJSR				_ssub_macro_patch_draw		; draw full patch
		APU_SE_SET			_apu_mus4E							; start a sound and wait
		SUSPEND				$08									; for a while...
#if BUGFIXES=1
		STORE				<[tlm_patch06],_tmp_ptr4B
		STORE				>[tlm_patch06],_tmp_ptr4B+1
#endif
		SJSR				_ssub_macro_patch_draw
		KILL

; =============== S C R I P T   R O U T I N E ===============================
_ssub_obj_button_common_init:
		NJSR				_nsub_idxBs_20_set	; init button object flags
		SPR_LIB_SET			_spr_lib5				; set library and sprite idxes
		SPR_IDX_SET			_spr_lib5_0C
		SIZE_SET			$05,$0D					; bounding box size
		HP_SET				$01						; hit-points
		SPRITE_ON									; enable object
		SRET

; =============== S C R I P T   R O U T I N E ===============================
_ssub_button_push_wait:
		SYNC										; sync with engine code
		NJSR				_nsub_obj_to_obj_jump_up_test	; get jump-up event
		SBCCS				_ssub_button_push_wait	; idle if no one jumped up
		SPR_IDX_SET			_spr_lib5_0D			; when jumped, display another
		SIZE_SET			$05,$08					; sprite and set another size
		NJSR				_nsub_obj_y_adjust_by_height_from_idxAs
		NJSR				_nsub_idxBs_10_set	; adjust cur jumped obj pos y
		SRET

; =============== S C R I P T   R O U T I N E ===============================
_ssub_button_release_wait:
		SYNC										; same as for push but wait when
		NJSR				_nsub_obj_to_obj_jump_up_test	; someone jump off
		SBCSS				_ssub_button_release_wait

; !FALLTHROUGH!

; =============== S C R I P T   R O U T I N E ===============================
_ssub_button_release_anim:
		NJSR				_nsub_idxBs_10_clear	; clear push state flag
		SUSPEND				$08						; wait a little
		SPR_IDX_SET			_spr_lib5_0E		; set half-released sprite and size
		SIZE_SET			$05,$0A
		NJSR				_nsub_obj_to_obj_jump_up_test	; if still no one jumped up again
		SBCCS				byte_6A82D				; adjust y pos then leave
		NJSR				_nsub_obj_y_adjust_by_height_from_idxAs
		SRET
byte_6A82D:
		SUSPEND				$04						; second frame set full release state
		SPR_IDX_SET			_spr_lib5_0C
		SIZE_SET			$05,$0D					; also test again if still free
		NJSR				_nsub_obj_to_obj_jump_up_test
		SBCCS				byte_6A83D				; and leave
		NJSR				_nsub_obj_y_adjust_by_height_from_idxAs
byte_6A83D:
		SRET

; =============== O B J E C T   S C R I P T =================================
_obj_scr0B_lvl2_basket_game_entry:
		SJSRS				_ssub_obj_button_common_init	; one botton will controlled here
		SRUN				_OBJ_TYPE_SOLID,_obj_scr_lvl2_basket_game_2nd_button	; here is the second button
		NJSR				_nsub_obj_to_obj_idxCs_link
		NJSR				_nsub_obj_idxCs_C0_clear
		POS_X_MOVE			$50									; change position of current main button
byte_6A84D:
		SJSRS				_ssub_button_push_wait		; wait for press
byte_6A850:
		NJSR				_nsub_idxBs_10_test_clear_from_idxCs	; here we test if other button pressed too
		SBNES				byte_6A863
		NJSR				_nsub_obj_to_obj_jump_up_test
		SYNC
		SBCSS				byte_6A850
		SJSRS				_ssub_button_release_anim
		SJMPS				byte_6A84D
byte_6A863:
		STORE				<[tlm_patch07],_tmp_ptr4B			; if both pressed, open the door
		STORE				>[tlm_patch07],_tmp_ptr4B+1
		SJSR				_ssub_macro_patch_draw
		SRUN				_OBJ_TYPE_TRIGGER,_obj_scr_lvl2_basket_exit_right	; insert actual door object
		APU_SE_SET			_apu_mus4F							; open sound
; TODO, optimize me! redundant!
byte_6A874:
		SJSRS				_ssub_button_release_wait		; common idle button script
		SJSRS				_ssub_button_push_wait
		SJMPS				byte_6A874
; -

; =============== S C R I P T ===============================================
_obj_scr_lvl2_basket_exit_right:
		POS_X_MOVE			$D0
; TODO, optimize me!
		SJMP				_obj_scr_lvl2_basket_exit_right_A

; =============== S C R I P T ===============================================
_obj_scr_lvl2_basket_game_2nd_button:
		SJSR				_ssub_obj_button_common_init
		NJSR				_nsub_obj_idxCs_C0_clear
byte_6A888:
		SJSRS				_ssub_button_push_wait
		SJSRS				_ssub_button_release_wait
		SJMPS				byte_6A888

; =============== O B J E C T   S C R I P T =================================
_obj_scr0C_lvl3_refill_entry:
		SJSR				_ssub_obj_button_common_init	; there is a button
		SJSR				_ssub_button_push_wait		; wait for it
		STORE				<[tlm_patch08],_tmp_ptr4B			; draw open cavity
		STORE				>[tlm_patch08],_tmp_ptr4B+1
		SJSR				_ssub_macro_patch_draw
		SRUN				_OBJ_TYPE_TRIGGER,_obj_scr_lvl3_box_bonus_entry	; run cavity script
		APU_SE_SET			_apu_mus4F							; play open sound
; TODO: optimize me!
byte_6A8A8:
		SJSR				_ssub_button_release_wait		; then work as common button
		SJSR				_ssub_button_push_wait		; again
		SJMPS				byte_6A8A8

; =============== S C R I P T ===============================================
_obj_scr_lvl3_box_bonus_entry:
		POS_X_MOVE			$C0									; set position of a door
		POS_X_MOVE			$B0
		SJMP				_obj_scr22_lvl5C_box_bonus_entry	; run common box bonus script

; =============== O B J E C T   S C R I P T =================================
_obj_scr0D_big_fan:
		SJSR				_ssub_wait_for_idxCs_80_set
byte_6A8BB:
		SRUN				_OBJ_TYPE_AUTO,_obj_scr_13D
		SUSPEND				$5A
		SRUN				_OBJ_TYPE_AUTO,_obj_scr_13E
		SUSPEND				$5A
		SJMPS				byte_6A8BB

; =============== S C R I P T ===============================================
_obj_scr_13D:
		POS_X_MOVE			$E0

; =============== S C R I P T ===============================================
_obj_scr_13E:
		GRABABLE_ON
		POS_X_MOVE			$10
		SPR_LIB_SET			_spr_lib5
		SPRITE_ON
		DELTA_Y_SET			$E0
		NJSR				_nsub_obj_idxCs_80_set
		NJSR				_nsub_grabable_obj_num_02_cmp
		SBCSS				byte_6A8EC
byte_6A8DD:
		SPR_IDX_SET			_spr_lib5_12
		DELTA_Y_DEC
		ANIMATE_HV_SYNC
		ANIMATE_HV_SYNC
		ANIMATE_HV_SYNC
		SPR_IDX_SET			_spr_lib5_1A
		DELTA_Y_DEC
		ANIMATE_HV_SYNC
		ANIMATE_HV_SYNC
		ANIMATE_HV_SYNC
		SJMPS				byte_6A8DD
byte_6A8EC:
		KILL

; =============== O B J E C T   S C R I P T =================================
_obj_scr0E_buttons_room:
		NJSR				_nsub_sub16B
		SBNES				byte_6A8FD
byte_6A8F3:
		NJSR				_nsub_inc_stage_room_idx
		LOOP_A				$05,byte_6A8F3
		NJSR				_MAIN_START
byte_6A8FD:
		NJSR				_nsub_box_bonus_3prizes_shuffle
		POS_X_SET			$38,$00
byte_6A903:
		NJSR				_nsub_sub034
		SRUN				_OBJ_TYPE_SOLID,_obj_scr_13F
		LOOP_A				$03,byte_6A903
		NJSR				_nsub_cur_obj_idx_to_idxBs_store
		NJSR				_nsub_box_bonus_3prizes_shuffle
		POS_X_SET			$C8,$00
byte_6A917:
		NJSR				_nsub_sub034
		SRUN				_OBJ_TYPE_SOLID,_obj_scr_13F
		LOOP_A				$03,byte_6A917
		NJSR				_nsub_cur_obj_idx_to_idxCs_store
byte_6A925:
		NJSR_SYNC			_nsub_sub035
		SBEQS				byte_6A925
		STORE				<[tlm_patch09],_tmp_ptr4B
		STORE				>[tlm_patch09],_tmp_ptr4B+1
		SJSR				_ssub_macro_patch_draw
		NJSR				_nsub_obj_type_change_grab
		POS_X_SET			$F0,$00
		POS_Y_SET			$C0,$00
		SPRITE_OFF
		APU_SE_SET			_apu_mus23
		SJMP				_obj_scr21_lvl_exit_right

; =============== S U B R O U T I N E =======================================
_nsub_sub034:
		JSR		_nsub_get_box_bonus_prize_from_list
		LDY		_tmp_ptrE+1
		LDA		byte_6A951,Y
		STA		_obj_y_lo_poss,X
		RTS
byte_6A951:
		.BYTE	$40,$80,$C0

; =============== S U B R O U T I N E =======================================
_nsub_sub035:
		LDY		_scr_idxBs,X
		LDA		_scr_idxBs,Y
		LDY		_scr_idxCs,X
		AND		_scr_idxBs,Y
		AND		#$10
		JMP		_scr_flags_update

; =============== S C R I P T ===============================================
_obj_scr_13F:
		NJSR				_nsub_idxBs_20_set
		SPR_LIB_SET			_spr_lib5
		SPR_IDX_SET			_spr_lib5_14
		SIZE_SET			$05,$0C
		HP_SET				$01
		SPRITE_ON
byte_6A972:
		SYNC
		NJSR				_nsub_obj_to_obj_jump_up_test
		SBCCS				byte_6A972
		SPR_IDX_SET			_spr_lib5_15
		SIZE_SET			$05,$06
		NJSR				_nsub_obj_y_adjust_by_height_from_idxAs
		NJSR				_nsub_idxBs_10_set
byte_6A984:
		SYNC
		NJSR				_nsub_obj_to_obj_jump_up_test
		SBCSS				byte_6A984
		NJSR				_nsub_idxBs_10_clear
		SUSPEND				$08
		SPR_IDX_SET			_spr_lib5_16
		SIZE_SET			$05,$08
		NJSR				_nsub_obj_to_obj_jump_up_test
		SBCCS				byte_6A99E
		NJSR				_nsub_obj_y_adjust_by_height_from_idxAs
byte_6A99E:
		SUSPEND				$04
		SPR_IDX_SET			_spr_lib5_14
		SIZE_SET			$05,$0C
		NJSR				_nsub_obj_to_obj_jump_up_test
		SBCCS				byte_6A9AE
		NJSR				_nsub_obj_y_adjust_by_height_from_idxAs
byte_6A9AE:
		SJMPS				byte_6A972

; =============== O B J E C T   S C R I P T =================================
_obj_scr0F_clock_trolleyA:
		POS_X_MOVE			$FD
		POS_Y_MOVE			$03
		TIMER_B_SET			$20
		SJSRS				_ssub_6AA22
byte_6A9BA:
		SJSRS				_ssub_6AA11
byte_6A9BD:
		SJSRS				_ssub_6AA31
		LOOP_A				$84,byte_6A9BD
		SJSRS				_ssub_6AA11
byte_6A9C7:
		SJSRS				_ssub_6AA31
		LOOP_A				$84,byte_6A9C7
		SJMPS				byte_6A9BA

; =============== O B J E C T   S C R I P T =================================
_obj_scr10_clock_trolleyB:
		POS_X_MOVE			$03
		POS_Y_MOVE			$05
		TIMER_B_SET			$00
		SJSRS				_ssub_6AA22
byte_6A9DA:
		SJSRS				_ssub_6AA11
byte_6A9DD:
		SJSRS				_ssub_6AA31
		LOOP_A				$84,byte_6A9DD
		SJSRS				_ssub_6AA11
byte_6A9E7:
		SJSRS				_ssub_6AA31
		LOOP_A				$84,byte_6A9E7
		SJMPS				byte_6A9DA

; =============== O B J E C T   S C R I P T =================================
_obj_scr11_clock_trolleyC:
		POS_X_MOVE			$03
		POS_Y_MOVE			$05
		TIMER_B_SET			$00
		SJSRS				_ssub_6AA22
byte_6A9FA:
		SJSRS				_ssub_6AA11
byte_6A9FD:
		SJSRS				_ssub_6AA31
		LOOP_A				$58,byte_6A9FD
		SJSRS				_ssub_6AA11
byte_6AA07:
		SJSRS				_ssub_6AA31
		LOOP_A				$58,byte_6AA07
		SJMPS				byte_6A9FA

; =============== S C R I P T   R O U T I N E ===============================
_ssub_6AA11:
		NJSR				_nsub_sub123
		NJSR				_nsub_sub124
		NJSR				_nsub_inc_vars19
		SJSRS				_ssub_6AA31
		LOOP_A				$40,_ssub_6AA11
		SRET

; =============== S C R I P T   R O U T I N E ===============================
_ssub_6AA22:
		NJSR				_nsub_idxBs_20_set
		SPR_LIB_SET			_spr_lib5
		SPR_IDX_SET			_spr_lib5_13
		SIZE_SET			$10,$0E
		HP_SET				$01
		SJMP				_ssub_obj_show_wait_for_idxCs_80_set

; =============== S C R I P T   R O U T I N E ===============================
_ssub_6AA31:
		SYNC
		ANIMATE_HV
		NJSR				_nsub_players_obj_ride_x_delta_sync
		NJSR				_nsub_players_obj_ride_y_sync
		SRET

; =============== O B J E C T   S C R I P T =================================
_obj_scr05_door_knob:
		POS_X_MOVE			$08
		SPR_LIB_SET			_spr_lib5
		SPR_IDX_SET			_spr_lib5_46
		SJSR				_ssub_obj_show_wait_for_idxCs_80_set
byte_6AA43:
		SUSPEND				$10
		SPR_IDX_SET			_spr_lib5_47
		SUSPEND				$10
byte_6AA49:
		SPR_IDX_SET			_spr_lib5_46
		APU_SE_SET			_apu_mus50
		SJMPS				byte_6AA43

; =============== O B J E C T   S C R I P T =================================
_obj_scr06_light_toggle:
		NJSR				_scr_flips_04_set
		NJSR				_nsub_obj_idxCs_C0_clear
byte_6AA56:
		SJSRS				_ssub_6AA67
		STORE				$05,_pal_anim_mode_idx
		SJSRS				_ssub_6AA67
		STORE				$07,_pal_anim_mode_idx
		SJMPS				byte_6AA56

; =============== S C R I P T   R O U T I N E ===============================
_ssub_6AA67:
		SUSPEND				$F0
		SUSPEND				$F0
		APU_SE_SET			_apu_mus35
		SRET

; =============== O B J E C T   S C R I P T =================================
_obj_scr3E_ghost_painting:
		POS_X_MOVE			$F8
		POS_Y_MOVE			$FC
		SJSR				_ssub_wait_for_idxCs_80_set
byte_6AA75:
		NJSR_SYNC			_nsub_sub036
		SBEQS				byte_6AA75
byte_6AA7B:
		NJSR_SYNC			_nsub_sub036
		SBNES				byte_6AA7B
		SRUN				_OBJ_TYPE_ENEMY,_obj_scr_140
		SJMPS				byte_6AA75

; =============== S U B R O U T I N E =======================================
_nsub_sub036:
		LDA		_pal_anim_mode_idx
		CMP		#$05
		JMP		_scr_flags_update

; =============== S C R I P T ===============================================
_obj_scr_140:
		SPR_LIB_SET			_spr_lib7
		SPRITE_ON
		TARGET_LOCK			$20
		SIZE_SET			$0C,$14
byte_6AA97:
		HP_SET				$7F
		DAMAGE_SET			_OBJ_DMG_KILL
		TIMER_B_SET			$00
		SJSRS				_ssub_6AAC1
		LOOP_A				$14,byte_6AA97
		NJSR				_nsub_sub10E
		NJSR				_nsub_sub111
		APU_SE_SET			_apu_mus36
byte_6AAAC:
		TIMER_B_SET			$FF
		SJSRS				_ssub_6AAC1
		LOOP_A				$14,byte_6AAAC
		LOOP_B				$03,byte_6AA97
byte_6AAB9:
		TIMER_B_SET			$FF
		SJSRS				_ssub_6AAC1
		SJMPS				byte_6AAB9

; =============== S C R I P T   R O U T I N E ===============================
_ssub_6AAC1:
		SPR_IDX_SET			_spr_lib7_5A
		SJSRS				_ssub_6AACE
		SJSRS				_ssub_6AACE
		SPR_IDX_SET			_spr_lib7_5B
		SJSRS				_ssub_6AACE

; !FALLTHROUGH!

; =============== S C R I P T   R O U T I N E ===============================
_ssub_6AACE:
		NJSR				_scr_flips_04_clear
		TARGET_FOLLOW
		SYNC
		SRET

; =============== O B J E C T   S C R I P T =================================
_obj_scr12_cave_trolley:
		NJSR				_nsub_idxBs_20_set
		POS_Y_MOVE			$EC
		SRUN				_OBJ_TYPE_AUTO,_obj_scr_141
		NJSR				_nsub_obj_to_obj_idxCs_link
		HP_SET				$01
		SIZE_SET			$16,$01
		SPR_LIB_SET			_spr_lib5
		SPR_IDX_SET			_spr_lib5_33
		SPRITE_ON
byte_6AAEA:
		SPR_IDX_SET			_spr_lib5_33
		SJSRS				_ssub_6AAFD
		NJSR				_nsub_get_obj_x_delta
		SBEQS				byte_6AAEA
		SPR_IDX_SET			_spr_lib5_34
		SJSRS				_ssub_6AAFD
		SJMPS				byte_6AAEA

; =============== S C R I P T   R O U T I N E ===============================
_ssub_6AAFD:
		SYNC
		NJSR				_nsub_sub038
		SBEQS				byte_6AB0A
		NJSR				_nsub_obj_jump_up_anim
		SJMPS				byte_6AB0F
byte_6AB0A:
		DELTA_Y_SET			$00
		NJSR				_nsub_sub037
byte_6AB0F:
		ANIMATE_HV
		NJSR				_nsub_players_obj_ride_x_delta_sync
		LOOP_A				$04,_ssub_6AAFD
		SRET

; =============== S U B R O U T I N E =======================================
_nsub_sub037:
		LDA		_obj_y_lo_poss,X
		AND		#$F0
		ORA		#$0C
		STA		_obj_y_lo_poss,X
		RTS

; =============== S U B R O U T I N E =======================================
_nsub_sub038:
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
_obj_scr_141:
		FLIPS_SET			_OBJ_FLIPS08
		NJSR				_nsub_obj_idxCs_C0_clear
		HP_SET				$01
		SIZE_SET			$01,$08
byte_6AB55:
		SPR_LIB_SET			_spr_lib1
		SPR_IDX_SET			_spr_lib1_12
		SPRITE_ON
byte_6AB5A:
		SJSRs				_ssub_6ABA9
		NJSR				_nsub_sub03D
		SBCCS				byte_6AB5A
		SPR_IDX_SET			_spr_lib1_13
		SJSRS				_ssub_6AB98
byte_6AB68:
		SJSRS				_ssub_6ABA9
		NJSR				_nsub_sub03E
		SBCCS				byte_6AB77
		NJSR				_nsub_sub03B
		SJMPS				byte_6AB55
byte_6AB77:
		NJSR				_nsub_sub03C
		SBEQS				byte_6AB90
		SBCCS				byte_6AB88
		SPR_IDX_SET			_spr_lib1_14
		NJSR				_nsub_sub039
		SJMPS				byte_6AB68
byte_6AB88:
		SPR_IDX_SET			_spr_lib1_15
		NJSR				_nsub_sub03B
		SJMPS				byte_6AB68
byte_6AB90:
		SPR_IDX_SET			_spr_lib1_13
		NJSR				_nsub_sub03A
		SJMPS				byte_6AB68

; =============== S C R I P T   R O U T I N E ===============================
_ssub_6AB98:
		SJSRS				_ssub_6ABA9
		NJSR				_nsub_sub03E
		SBCSS				byte_6ABA6
		LOOP_A				$08,_ssub_6AB98
		SRET
byte_6ABA6:
		BREAK				byte_6AB55

; =============== S C R I P T   R O U T I N E ===============================
_ssub_6ABA9:
		NJSR				_nsub_obj_linked_idxCs_follow
		POS_X_MOVE			$06
		SYNC
		SRET

; =============== S U B R O U T I N E =======================================
_nsub_sub039:
		LDA		#$30
		BNE		_nsub_sub03B_ex

; =============== S U B R O U T I N E =======================================
_nsub_sub03A:
		LDA		#$20
		BNE		_nsub_sub03B_ex

; =============== S U B R O U T I N E =======================================
_nsub_sub03B:
		LDA		#$10

; =============== S U B R O U T I N E =======================================
_nsub_sub03B_ex:
		PHA
		JSR		_nsub_get_link_obj_idx_from_idxCs
		PLA
		STA		_obj_x_deltas,Y
		RTS

; =============== S U B R O U T I N E =======================================
_nsub_sub03C:
		LDY		_scr_idxAs,X
		LDA		_pads,Y
		AND		#_PAD_LEFT|_PAD_RIGHT
		BEQ		loc_6ABD5
		SEC
		AND		#_PAD_RIGHT
		BNE		loc_6ABD5
		CLC
		LDA		#$FF
loc_6ABD5:
		JMP		_scr_flags_update

; =============== S U B R O U T I N E =======================================
_nsub_sub03D:
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
		JSR		_nsub_sub03E_A
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
_nsub_sub03E:
		LDY		_scr_idxAs,X
		LDA		_players_states,Y
		CMP		#$13
		BNE		loc_6AC3F
		JSR		_nsub_sub03E_A
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
_nsub_sub03E_A:
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
		NJSR				_nsub_obj_type_change_bullet
		NJSR				_nsub_idxBs_20_set
		HP_SET				$01
		DAMAGE_SET			_OBJ_DMG_KILL
		SIZE_SET			$09,$12
		SPR_LIB_SET			_spr_lib5
		SPR_IDX_SET			_spr_lib5_38
		SJSR				_ssub_obj_show_wait_for_idxCs_80_set
byte_6AC8A:
		NJSR_SYNC			_nsub_obj_x_range30_test_from_players_macro_overlap_test_idx
		SBCSS				byte_6AC8A
		DELTA_Y_SET			$18
		APU_SE_SET			_apu_mus71
		SJMP				_ssub_y_parabolic_delta_infinite_anim_sync

; =============== O B J E C T   S C R I P T =================================
_obj_scr04_cave_pendulum:
		SPR_LIB_SET			_spr_lib5
		SPR_IDX_SET			_spr_lib5_45
		SPRITE_ON
		SRUN				_OBJ_TYPE_EBULLET,_obj_scr_142
		NJSR				_nsub_obj_to_obj_idxCs_link
byte_6ACA3:
		APU_SE_SET			_apu_mus5E
		SPR_IDX_SET			_spr_lib5_45
		SUSPEND				$08
		SPR_IDX_SET			_spr_lib5_44
		SUSPEND				$09
		SPR_IDX_SET			_spr_lib5_43
		SUSPEND				$0B
		SPR_IDX_SET			_spr_lib5_42
		SUSPEND				$0E
		SPR_IDX_SET			_spr_lib5_43
		SUSPEND				$0B
		SPR_IDX_SET			_spr_lib5_44
		SUSPEND				$09
		FLIP_H_TOGGLE
		SJMPS				byte_6ACA3

; =============== S C R I P T ===============================================
_obj_scr_142:
		NJSR				_nsub_obj_idxCs_C0_clear
		SIZE_SET			$06,$0C
		HP_SET				$01
		DAMAGE_SET			_OBJ_DMG_KILL
		SPR_LIB_SET			_spr_lib5
		SPR_IDX_SET			_spr_lib5_41
		SPRITE_ON
byte_6ACD0:
		NJSR_SYNC			_nsub_sub03F
		SJMPS				byte_6ACD0

; =============== S U B R O U T I N E =======================================
_nsub_sub03F:
		JSR		_nsub_get_link_obj_idx_from_idxCs
		SEC
		LDA		_obj_spr_idxs,Y
		SBC		#_spr_lib5_42_idx
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
		NJSR				_nsub_idxBs_20_set
		HP_SET				$01
		SIZE_SET			$05,$08
		SPR_LIB_SET			_spr_lib5
		SPRITE_ON
		NJSR				_nsub_sub040
		SBEQS				byte_6AD4F
		SJMPS				byte_6AD5C
byte_6AD40:
		NJSR_SYNC			_nsub_sub041
		SBCCS				byte_6AD40
		NJSR				_nsub_sub040
		SBNES				byte_6AD4F
		SJMPS				byte_6AD5C
byte_6AD4F:
		SPR_IDX_SET			_spr_lib5_2B
		STORE				$0C,_pal_anim_mode_idx
		STORE				$04,byte_7F
		SJMPS				byte_6AD40
byte_6AD5C:
		SPR_IDX_SET			_spr_lib5_2C
		STORE				$0E,_pal_anim_mode_idx
		STORE				$05,byte_7F
		SJMPS				byte_6AD40

; =============== S U B R O U T I N E =======================================
_nsub_sub040:
		LDA		byte_7F
		CMP		#$04
		JMP		_scr_flags_update

; =============== S U B R O U T I N E =======================================
_nsub_sub041:
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
		JMP		_scr_cmd_clear_carry
loc_6AD92:
		LDA		_obj_damages,Y
		CMP		#_OBJ_DMG_STUN
		BEQ		loc_6AD9E
		LDA		#$00
		STA		_obj_hps,Y
loc_6AD9E:
		JMP		_scr_cmd_set_carry

; =============== O B J E C T   S C R I P T =================================
_obj_scr14_press_hammer:
		NJSR				_nsub_idxBs_20_set
		POS_X_MOVE			$08
		FLIPS_SET			_OBJ_UNDER_BG
		SPR_LIB_SET			_spr_lib5
		SPR_IDX_SET			_spr_lib5_04
		HP_SET				$01
		SPRITE_ON
		SIZE_SET			$10,$0F
		SJSR				_ssub_obj_show_wait_for_idxCs_80_set
byte_6ADB5:
		DELTA_Y_SET			$F0
byte_6ADB7:
		SJSRS				_ssub_6ADDD
		LOOP_A				$16,byte_6ADB7
byte_6ADBE:
		NJSR_SYNC			_obj_vert_anim
		LOOP_A				$0A,byte_6ADBE
		SUSPEND				$78
		DELTA_Y_SET			$40
		NJSR_SYNC			_obj_vert_anim
		NJSR_SYNC			_obj_vert_anim
byte_6ADCF:
		SJSRS				_ssub_6ADDD
		LOOP_A				$06,byte_6ADCF
		APU_SE_SET			_apu_mus51
		SUSPEND				$78
		SJMPS				byte_6ADB5

; =============== S C R I P T   R O U T I N E ===============================
_ssub_6ADDD:
		SYNC
		NJSR				_obj_vert_anim
		NJSR				_nsub_obj_x_range_width_test_from_players_macro_overlap_test_idx
		SBCSS				byte_6ADEA
		NJSR				_nsub_sub042
byte_6ADEA:
		SRET

; =============== S U B R O U T I N E =======================================
_nsub_sub042:
		LDY		_players_macro_overlap_test_idx
		LDA		_obj_flips,Y
		AND		#_OBJ_FLIPS04
		BNE		locret_6ADF7
		JMP		_player_kill
locret_6ADF7:
		RTS

; =============== O B J E C T   S C R I P T =================================
_obj_scr15_floor_doors:
		NJSR				_nsub_idxBs_20_set
		SPR_LIB_SET			_spr_lib5
		HP_SET				$01
		SPRITE_ON
byte_6AE00:
		SPR_IDX_SET			_spr_lib5_2E
		SIZE_SET			$10,$0F
byte_6AE05:
		NJSR_SYNC			_nsub_obj_to_obj_jump_up_test
		SBCCS				byte_6AE05
		SPR_IDX_SET			_spr_lib5_39
		SUSPEND				$78
		SIZE_SET			$00,$00
		SPR_IDX_SET			_spr_lib5_22
		SUSPEND				$08
		SPR_IDX_SET			_spr_lib5_23
		SUSPEND				$1E
		SPR_IDX_SET			_spr_lib5_22
		SUSPEND				$04
		SPR_IDX_SET			_spr_lib5_39
		SUSPEND				$04
		SJMPS				byte_6AE00

; =============== O B J E C T   S C R I P T =================================
_obj_scr3B_ceiling_lazer:
		POS_X_MOVE			$08
		SPR_LIB_SET			_spr_lib5
		SIZE_SET			$02,$30
byte_6AE2C:
		SPRITE_ON
byte_6AE2D:
		APU_SE_SET			_apu_mus53
		SPR_IDX_SET			_spr_lib5_29
		SJSRS				_ssub_6AE46
		SPR_IDX_SET			_spr_lib5_2A
		SJSRS				_ssub_6AE46
		LOOP_A				$1E,byte_6AE2D
		SPRITE_OFF
		NJSR				_scr_flips_04_set
		SUSPEND				$78
		SJMPS				byte_6AE2C

; =============== S C R I P T   R O U T I N E ===============================
_ssub_6AE46:
		HP_SET				$01
		DAMAGE_SET			_OBJ_DMG_KILL
		NJSR_SYNC			_scr_flips_04_clear
		LOOP_B				$02,_ssub_6AE46
		SRET

; =============== O B J E C T   S C R I P T =================================
_obj_scr17_ceiling_magnet:
		NJSR				_nsub_idxBs_20_set
		SPR_LIB_SET			_spr_lib5
		SPR_IDX_SET			_spr_lib5_2D
		SIZE_SET			$08,$10
		SJSR				_ssub_obj_show_wait_for_idxCs_80_set
byte_6AE5F:
		NJSR_SYNC			_nsub_ceiling_magnet_object_search
		SJMPS				byte_6AE5F

; =============== S U B R O U T I N E =======================================
_nsub_ceiling_magnet_object_search:
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
		JSR		_far_players_state16_E
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
		NJSR				_nsub_idxBs_20_set
		HP_SET				$01
		SPR_LIB_SET			_spr_lib5
		SPR_IDX_SET			_spr_lib5_31
		SJSR				_ssub_obj_show_wait_for_idxCs_80_set
		DELTA_X_SET			$F0
byte_6AEDB:
		SPR_IDX_SET			_spr_lib5_30
		SUSPEND				$08
		SPR_IDX_SET			_spr_lib5_2F
		SUSPEND				$08
byte_6AEE3:
		NJSR				_nsub_grabable_obj_num_01_cmp
		SBCSS				byte_6AEED
		SRUN				_OBJ_TYPE_EBULLET,_obj_scr_ceiling_cannon_ball_left
byte_6AEED:
		SJSR				_ssub_anim_sync_frames32
		NJSR				_j_nsub_complement_x_deltas
		NJSR				_nsub_sub16F
		SBCSS				byte_6AEE3
		SPR_IDX_SET			_spr_lib5_30
		SUSPEND				$08
		SPR_IDX_SET			_spr_lib5_31
		SUSPEND				$08
byte_6AF01:
		NJSR				_nsub_grabable_obj_num_01_cmp
		SBCSS				byte_6AF0B
		SRUN				_OBJ_TYPE_EBULLET,_obj_scr_ceiling_cannon_ball_right
byte_6AF0B:
		SJSR				_ssub_anim_sync_frames32
		NJSR				_j_nsub_complement_x_deltas
		NJSR				_nsub_sub16F
		SBCCS				byte_6AF01
		SJMPS				byte_6AEDB

; =============== S C R I P T ===============================================
_obj_scr_ceiling_cannon_ball_left:
		POS_X_MOVE			$EE
		DELTA_X_SET			$D8
		SJMPS				_obj_scr_ceiling_cannon_ball

; =============== S C R I P T ===============================================
_obj_scr_ceiling_cannon_ball_right:
		POS_X_MOVE			$12
		DELTA_X_SET			$28

; !FALLTHROUGH!

; =============== S C R I P T   R O U T I N E ===============================
_obj_scr_ceiling_cannon_ball:
		GRABABLE_ON
		NJSR				_nsub_obj_idxCs_80_set
		POS_Y_MOVE			$24
		DELTA_Y_SET			$28
		SIZE_SET			$07,$0E
		SPR_LIB_SET			_spr_lib5
		SPR_IDX_SET			_spr_lib5_32
		SPRITE_ON
		HP_SET				$FF
		DAMAGE_SET			_OBJ_DMG_KILL
byte_6AF39:
		SYNC
		NJSR				_nsub_get_obj_y_delta
		SBPLS				byte_6AF4C
		NJSR				_obj_vert_anim
		NJSR				_nsub_obj_to_tile_collision_test_up
		SBCCS				byte_6AF52
		SJMPS				byte_6AF57
byte_6AF4C:
		NJSR				_obj_to_tile_grid_collision_test_down
		SBCCS				byte_6AF57
byte_6AF52:
		NJSR				_nsub_complement_y_deltas
		APU_SE_SET			_apu_mus54
byte_6AF57:
		NJSR				_obj_move_hor_animate
		NJSR				_nsub_obj_to_tile_collision_test_hor
		SBCSS				byte_6AF39
		NJSR				_j_nsub_complement_x_deltas
		APU_SE_SET			_apu_mus54
		SJMPS				byte_6AF39

; =============== S C R I P T ===============================================
_ssub_fade_out:
		STORE				$00,_pal_anim_mode_idx
		PAL_FADE_OUT		$04,$FF
		SUSPEND				$14
		STORE				$40,_stage_flags
		SJMP				_ssub_suspend_forever

; =============== S C R I P T   R O U T I N E ===============================
_ssub_game_timer_init:
		POS_X_SET			$70,$00
		STORE				$1E,_timer_seconds_cnt
		STORE				$00,_tmp_bonus_games_scores
		STORE				$00,_tmp_bonus_games_scores+1
		SPR_LIB_SET			_spr_lib0
		SPR_IDX_SET			_spr_lib0_10
		SRET

; =============== S C R I P T   R O U T I N E ===============================
_ssub_timer_start:
		APU_SE_SET			_apu_mus3A
		NJSR				_nsub_sub021
		STORE				$3B,_timer_frames_cnt
		SRET

; =============== S C R I P T   R O U T I N E ===============================
_ssub_delay_before_stage_complete:
		STORE				$FF,_timer_frames_cnt
byte_6AF9A:
		NJSR_SYNC			_nsub_obj_timer_spr_insert_test
		LOOP_A				$F0,byte_6AF9A

; !FALLTHROUGH!

; =============== S C R I P T   R O U T I N E ===============================
_j_ssub_stage_complete_flag_set:
		SJMP				_ssub_stage_complete_flag_set

; =============== S U B R O U T I N E =======================================
_nsub_obj_timer_spr_insert_test:
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
		NJSR_SYNC			_nsub_obj_timer_spr_insert_test
		LOOP_A				$3C,_obj_scr_game_result_display
		CHR_SET				$01,$0B
		NJSR_SYNC			_nsub_sub045
		SPR_LIB_SET			_spr_lib5
		SPR_IDX_SET			_spr_lib5_28
		SPRITE_ON
		POS_X_SET			$80,$00
		POS_Y_SET			$68,$00
		NJSR				_nsub_get_bonus_game_winner
		SUSPEND				$B4
		NJSR				_nsub_sub047
		SJMPS				_j_ssub_stage_complete_flag_set

; =============== S U B R O U T I N E =======================================
_nsub_sub045:
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
_nsub_get_bonus_game_winner:
		LDA		_tmp_bonus_games_scores
		CMP		_tmp_bonus_games_scores+1
		BEQ		locret_6B022
		LDY		#$00
		BCS		loc_6B019
		INY
loc_6B019:
		CLC
		LDA		_obj_spr_libs,Y
		ADC		#[_spr_lib5_26_idx-1]
		STA		_obj_spr_idxs,X
locret_6B022:
		RTS

; =============== S U B R O U T I N E =======================================
_nsub_sub047:
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
		NJSR				_nsub_box_bonus_3prizes_shuffle	; random shuffle the boxes, you couldn't guess it!
		SRUN				_OBJ_TYPE_ENEMY,_obj_scr_lives_bonus_2p_star	; add objects, three bonus travelers
		SRUN				_OBJ_TYPE_ENEMY,_obj_scr_lives_bonus_1p_star
		SRUN				_OBJ_TYPE_ENEMY,_obj_scr_lives_bonus_no_star
		SRUN				_OBJ_TYPE_SOLID,_obj_scr_lives_bonus_player1_red_ball	; up to two balls for every live player
		SRUN				_OBJ_TYPE_SOLID,_obj_scr_lives_bonus_player2_red_ball
		SJSR				_ssub_game_timer_init
		STORE				$0A,_timer_seconds_cnt				; reset timers to 10 second
		POS_Y_SET			$38,$00
byte_6B05E:
		NJSR_SYNC			_nsub_obj_timer_spr_insert_test	; delay for 1 second before start
		LOOP_A				$3C,byte_6B05E
		SJSR				_ssub_timer_start
byte_6B068:
		NJSR				_nsub_grabable_obj_num_00_cmp	; test if all red ball are thrown
		SBEQS				byte_6B074
		NJSR_SYNC			_nsub_obj_timer_spr_insert_test	; or else continue the game
		SBNES				byte_6B068
byte_6B074:
		NJSR				_nsub_lvl_intro_cutscene_start	; init and set the cutscene handler
		SJMP				_ssub_fade_out					; exit with fade out

; =============== S C R I P T   R O U T I N E ===============================
_ssub_lives_bonus_floater_init:
		SRUN				_OBJ_TYPE_AUTO,_obj_scr_lives_bonus_floater
		NJSR				_nsub_obj_to_obj_idxCs_link
		NJSR				_nsub_obj_idxCs_C0_clear
		HP_SET				$01
		SIZE_SET			$08,$10
		NJSR				_nsub_get_rand_flags
		SBPLS				byte_6B095
		POS_X_SET			$08,$01
		SJMPS				byte_6B09B
byte_6B095:
		POS_X_SET			$F8,$FF
		NJSR				_j_nsub_complement_x_deltas
byte_6B09B:
		SRET

; =============== S C R I P T   R O U T I N E ===============================
_ssub_lives_bonus_floater_anim:
		SJSR				_ssub_anim_sync_frames16				; every 16 frames
		NJSR				_nsub_complement_y_deltas		; do up-down floating anim
		SRET

; =============== S C R I P T   R O U T I N E ===============================
_ssub_lives_bonus_floater_bounce:
		SUSPEND				$1E					; wait before reappear, then
		NJSR_SYNC			_j_nsub_complement_x_deltas	; invert x delta
		SRET

; =============== S U B R O U T I N E =======================================
_nsub_give_players_2_lives:
		JSR		_nsub_give_players_1_life

; !FALLTHROUGH!

; =============== S U B R O U T I N E =======================================
_nsub_give_players_1_life:
		LDX		_scr_idx
		JSR		_nsub_get_idxBs_low_nibble_from_idxAs
		JMP		_nsub_inc_players_lives

; =============== S C R I P T ===============================================
_obj_scr_lives_bonus_2p_star:
		SPR_LIB_SET			_spr_lib5
		SPR_IDX_SET			_spr_lib5_1E
		SPRITE_ON
		POS_Y_MOVE			$40
		DELTA_X_SET			$BC
		DELTA_Y_SET			$F8
		DESTR_PC_SET		_obj_scr_lives_bonus_2p_star_destr
		SJSRS				_ssub_lives_bonus_floater_init
byte_6B0C5:
		SJSRS				_ssub_lives_bonus_floater_anim
		LOOP_B				$04,byte_6B0C5
		SJSRS				_ssub_lives_bonus_floater_bounce
		SJMPS				byte_6B0C5

; =============== S C R I P T ===============================================
_obj_scr_lives_bonus_1p_star:
		SPR_LIB_SET			_spr_lib6
		SPR_IDX_SET			_spr_lib6_01
		SPRITE_ON
		POS_Y_MOVE			$58
		DELTA_X_SET			$D2
		DELTA_Y_SET			$F8
		DESTR_PC_SET		_obj_scr_lives_bonus_1p_star_destr
		SJSRS				_ssub_lives_bonus_floater_init
byte_6B0E3:
		SJSRS				_ssub_lives_bonus_floater_anim
		LOOP_B				$06,byte_6B0E3
		SJSRS				_ssub_lives_bonus_floater_bounce
		SJMPS				byte_6B0E3

; =============== S C R I P T ===============================================
_obj_scr_lives_bonus_no_star:
		POS_Y_MOVE			$7F
		DELTA_X_SET			$E4
		DELTA_Y_SET			$F0
		DESTR_PC_SET		_obj_scr_lives_bonus_no_star_destr
		SJSRS				_ssub_lives_bonus_floater_init
byte_6B0FC:
		SJSRS				_ssub_lives_bonus_floater_anim
		LOOP_B				$0A,byte_6B0FC
		SJSRS				_ssub_lives_bonus_floater_bounce
		SJMPS				byte_6B0FC

; =============== S C R I P T   R O U T I N E ===============================
; 2P bonus floater object
;
_obj_scr_lives_bonus_2p_star_destr:
		NJSR				_nsub_obj_disable_from_idxCs_40_flag
		NJSR				_nsub_give_players_2_lives
		SPR_LIB_SET			_spr_lib5
		SPR_IDX_SET			_spr_lib5_1F
		SJMP				_ssub_prize_text_float_animate_with_se

; =============== S C R I P T   R O U T I N E ===============================
; 1P bonus floater object
;
_obj_scr_lives_bonus_1p_star_destr:
		NJSR				_nsub_obj_disable_from_idxCs_40_flag
		NJSR				_nsub_give_players_1_life
		SJMP				_ssub_1up_text_float_up

; =============== S C R I P T   R O U T I N E ===============================
; no bonus bloater object
;
_obj_scr_lives_bonus_no_star_destr:
		NJSR				_nsub_obj_disable_from_idxCs_40_flag
		KILL

; =============== S C R I P T ===============================================
_obj_scr_lives_bonus_floater:
		SPR_LIB_SET			_spr_lib5
		SPRITE_ON
byte_6B126:
		SPR_IDX_SET			_spr_lib5_1D
		SJSRS				_ssub_6B13D
		SPR_IDX_SET			_spr_lib5_0F
		SJSRS				_ssub_6B13D
		SPR_IDX_SET			_spr_lib5_10
		SJSRS				_ssub_6B13D
		SPR_IDX_SET			_spr_lib5_11
		SJSRS				_ssub_6B13D
		SJMPS				byte_6B126

; =============== S C R I P T   R O U T I N E ===============================
_ssub_6B13D:
		NJSR_SYNC			_nsub_lives_bonus_floater_link_follow
		LOOP_B				$06,_ssub_6B13D
		SRET

; =============== S U B R O U T I N E =======================================
_nsub_lives_bonus_floater_link_follow:
		JSR		_nsub_obj_linked_idxCs_follow ; FLIP_H_ON
		CLC
		LDA		_obj_y_lo_poss,Y
		ADC		#$08
		STA		_obj_y_lo_poss,X
		RTS

; =============== S U B R O U T I N E =======================================
_nsub_get_player1_lives:
		LDA		_players_lives
		JMP		_scr_flags_update

; =============== S U B R O U T I N E =======================================
_nsub_get_player2_lives:
		LDA		_players_lives+1
		JMP		_scr_flags_update

; =============== S C R I P T ===============================================
_obj_scr_lives_bonus_player1_red_ball:
		NJSR				_nsub_get_player1_lives
		SBEQS				_ssub_j_kill
		POS_X_SET			$10,$00
		SJMPS				_obj_scr_lives_bonus_red_ball_common

; =============== S C R I P T ===============================================
_obj_scr_lives_bonus_player2_red_ball:
		NJSR				_nsub_get_player2_lives
		SBEQS				_ssub_j_kill
		POS_X_SET			$F0,$00

; !FALLTHROUGH!

; =============== S C R I P T ===============================================
_obj_scr_lives_bonus_red_ball_common:
		GRABABLE_ON
		DESTR_PC_SET		_obj_lives_bonus_red_ball_destr
		POS_Y_SET			$C0,$00				; lives bonus ball is a special, it's
		SIZE_SET			$06,$10				; pickable and throwable object
		SPR_LIB_SET			_spr_lib5
		SPR_IDX_SET			_spr_lib5_1B
		SPRITE_ON
		HP_SET				$01					; so we need to wait when it's picked up
		SJSR				_ssub_obj_wait_for_pickup

; !FALLTHROUGH!

; =============== S C R I P T ===============================================
_obj_lives_bonus_red_ball_destr:
		SJSR				_ssub_obj_wait_for_throw	; then wait it trowed
		DELTA_Y_SET			$C0					; balls are moves directly up without bouncing
		HP_SET				$01					; upon hittihng objects
		DAMAGE_SET			_OBJ_DMG_KILL		; unless they fly out of the screen
		SJMP				_ssub_infinite_anim_sync

; =============== S C R I P T ===============================================
_ssub_j_kill:
		KILL

; =============== O B J E C T   S C R I P T =================================
_obj_scr02_coins_game:
		NJSR				_nsub_coins_bonus_obstacle_init	; draw invisible obstacles
		POS_Y_MOVE			$40
byte_6B197:
		SRUN				_OBJ_TYPE_ENEMY,_obs_scr_coins_game_coin	; insert 4 moving coins
		FLIP_H_TOGGLE
		POS_Y_MOVE			$30
		LOOP_A				$04,byte_6B197
		POS_Y_SET			$13,$00								; the main object script controls times
		SJSR				_ssub_game_timer_init			; as usual
		SJSR				_ssub_timer_start
byte_6B1AB:
		NJSR_SYNC			_nsub_obj_timer_spr_insert_test	; wait for timer expired
		SBNES				byte_6B1AB
		SJMP				_obj_scr_game_result_display		; display results

; =============== S U B R O U T I N E =======================================
; when bonus room is drawn, this code filling the particulat parts of the
; screen with obstacle meta-tiles in screen meta buffer. the screen won't be
; redrawn here, so we will see normal room, but can't go farther than
; sides of the screen.
;
_nsub_coins_bonus_obstacle_init:
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
		SIZE_SET			$08,$12
		SPR_LIB_SET			_spr_lib5
		SPRITE_ON
		DELTA_X_SET			$01
		NJSR				_nsub_obj_hor_delta_toggle
		FLIP_H_OFF
byte_6B1EE:
		SPR_IDX_SET			_spr_lib5_17
		FLIP_H_OFF
		SJSRS				_ssub_coins_game_coin_ai
		SPR_IDX_SET			_spr_lib5_18
		SJSRS				_ssub_coins_game_coin_ai
		SPR_IDX_SET			_spr_lib5_19
		SJSRS				_ssub_coins_game_coin_ai
		SPR_IDX_SET			_spr_lib5_18
		FLIP_H_ON
		SJSRS				_ssub_coins_game_coin_ai
		SJMPS				byte_6B1EE

; =============== S C R I P T   R O U T I N E ===============================
_ssub_coins_game_coin_ai:
		SYNC
		NJSR				_nsub_coins_game_coin_goal_test
		SBEQS				byte_6B21A
		NJSR				_obj_move_hor_animate
		NJSR				_nsub_get_obj_hp
		SBNES				byte_6B21A
		NJSR				_nsub_coins_game_coin_bounce_test
byte_6B21A:
		LOOP_A				$08,_ssub_coins_game_coin_ai
		SRET

; =============== S U B R O U T I N E =======================================
_nsub_coins_game_coin_bounce_test:
		JSR		_scr_flips_04_clear
		JSR		_j_nsub_complement_x_deltas
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
_nsub_coins_game_coin_goal_test:
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
		SIZE_SET			$06,$10							; the pickup logic is tile-based
		SPR_LIB_SET			_spr_lib5
		SPR_IDX_SET			_spr_lib5_1B					; here we only get when carry it
		SPRITE_ON
		SJSR				_ssub_obj_wait_for_throw
		NJSR				_nsub_obj_throw_direction_select
byte_6B27A:
		ANIMATE_HV_SYNC									; throw animate, wait it hit someone
		NJSR				_nsub_get_obj_hp
		SBNES				byte_6B27A						; when hit, do parabolic throw-back animation
		DELTA_X_SET			$08
		DELTA_Y_SET			$E8
		NJSR				_players_damaged_state_select_A
		SJMP				_ssub_y_parabolic_delta_infinite_anim_sync

; =============== O B J E C T   S C R I P T =================================
_obj_scr03_basket_game:
		SRUN				_OBJ_TYPE_AUTO,_obj_scr_basket_game_basket		; add basket object
		NJSR				_nsub_basket_game_init
		SJSR				_ssub_game_timer_init			; common init timer
		STORE				$3C,_timer_seconds_cnt				; but here reset to 60 sec
		POS_Y_SET			$18,$00
byte_6B29C:
		NJSR_SYNC			_nsub_obj_timer_spr_insert_test	; 3 seconds delay, just show timer
		LOOP_A				$B4,byte_6B29C
		SRUN				_OBJ_TYPE_BALL,_obj_scr_basket_game_left_ball	; insert balls
		SRUN				_OBJ_TYPE_BALL,_obj_scr_basket_game_right_ball
		SJSR				_ssub_timer_start			; game start with sound
byte_6B2AE:
		NJSR_SYNC			_nsub_obj_timer_spr_insert_test	; show timer
		SBNES				byte_6B2AE							; wait untill time expired
		SJMP				_obj_scr_game_result_display		; show results

; =============== S U B R O U T I N E =======================================
_nsub_basket_game_init:
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
		POS_Y_MOVE			$58										; set basket Y position
		SRUN				_OBJ_TYPE_SOLID,_obj_scr_basket_game_left_bouncer	; insert basket left side bouncer
		NJSR				_nsub_obj_to_obj_idxCs_link
		SRUN				_OBJ_TYPE_SOLID,_obj_scr_basket_game_right_bouncer	; same for right bouncer
		NJSR				_nsub_obj_to_obj_idxCs_link
		SIZE_SET			$04,$04									; the main hot spot in the middle
		DELTA_X_SET			$F0										; set default movement delta
		SPR_LIB_SET			_spr_lib5										; init sprite
		SPR_IDX_SET			_spr_lib5_1C
		SPRITE_ON												; enable
		SUSPEND				$B4										; wait for 3 seconds as well as timer
byte_6B2F5:
		NJSR				_nsub_cmp40_obj_x_lo_pos				; now move left-right constantly
		SBCSS				byte_6B30D
		NJSR				_nsub_cmpC0_obj_x_lo_pos
		SBCCS				byte_6B30D
		NJSR				_nsub_get_rand_scale3					; sometimes basket may change direction
		SSWITCH				_tmp_ptrE+1								; randomly with 1/3 possibility
		SCASE				byte_6B310
		SCASE				byte_6B310
		SCASE				byte_6B30D
byte_6B30D:
		NJSR				_nsub_obj_hor_move_reverse			; bounce object hor movement
byte_6B310:
		ANIMATE_HV_SYNC
		LOOP_A				$26,byte_6B310							; wait for 38 frames
		SJMPS				byte_6B2F5

; =============== S C R I P T   R O U T I N E ===============================
_ssub_basket_game_bouncer_init:
		SIZE_SET			$02,$02				; basket bouncers are invisible objects
		HP_SET				$01					; size 2x2 with collision test
		SRET

; =============== S C R I P T ===============================================
_obj_scr_basket_game_left_bouncer:
		SJSRS				_ssub_basket_game_bouncer_init	; common init
byte_6B321:
		SYNC
		NJSR				_nsub_obj_linked_idxCs_follow			; sync movement with main basket object
		POS_X_MOVE			$F1										; adjust linked positions for left side
		POS_Y_MOVE			$F2
		SJMPS				byte_6B321								; loop forever

; =============== S C R I P T ===============================================
_obj_scr_basket_game_right_bouncer:
		SJSRS				_ssub_basket_game_bouncer_init	; the same for right side
byte_6B32F:
		SYNC
		NJSR				_nsub_obj_linked_idxCs_follow
		POS_X_MOVE			$0F
		POS_Y_MOVE			$F2
		SJMPS				byte_6B32F

; =============== S C R I P T ===============================================
_obj_scr_basket_game_left_ball:
		POS_X_SET			$18,$00
		SJMPS				_obj_scr_basket_game_ball_common

; =============== S C R I P T ===============================================
_obj_scr_basket_game_right_ball:
		POS_X_SET			$E8,$00

; !FALLTHROUGH!

; =============== S C R I P T ===============================================
_obj_scr_basket_game_ball_common:
		DESTR_PC_SET		_obj_scr_basket_game_ball_destr	; collision detect handler here
		POS_Y_SET			$40,$00
		SIZE_SET			$06,$0D
		SPR_LIB_SET			_spr_lib4
		SPRITE_ON
		SJMPS				_obj_scr_basket_game_ball_test

; =============== S C R I P T ===============================================
_obj_scr_basket_game_ball_loop:
		DELTA_X_SET			$00
		NJSR				_nsub_obj_type_change_solid_no_damage_idxBs_20_clear
byte_6B357:
		SYNC
		NJSR				_nsub_get_obj_idxBs
		SBMIS				_obj_scr_basket_game_ball_destr
		SJSR				_ssub_ballistic_throw_anim
		SBCSS				byte_6B357
		SJMPS				_obj_scr_basket_game_ball_test

; =============== S C R I P T ===============================================
_obj_scr_basket_game_ball_destr:
		SJSR				_ssub_obj_wait_for_throw
		TIMER_B_SET			$00
		DELTA_X_SET			$08
		DELTA_Y_SET			$B0
		NJSR				_nsub_sub029

; !FALLTHROUGH!

; =============== S C R I P T ===============================================
_obj_scr_basket_game_ball_test:
		NJSR				_nsub_sub11C
		NJSR				_nsub_obj_type_change_ball
		NJSR				_nsub_obj_idxCs_C0_clear
byte_6B37C:
		SJSRS				_ssub_6B393
		DELTA_Y_SET			$E0
		NJSR				_nsub_cmp50_obj_y_lo_pos
		SBCSS				byte_6B37C
		NJSR				_far_players_default_state_select_G
		SBPLS				_obj_scr_basket_game_ball_loop
		SJSRS				_ssub_6B393
		SJMPS				_obj_scr_basket_game_ball_loop

; =============== S C R I P T   R O U T I N E ===============================
_ssub_6B393:
		NJSR_SYNC			_nsub_sub04F
		NJSR				_nsub_sub100
		HP_SET				$01
		DAMAGE_SET			_OBJ_DMG_STUN
		SJSR				_ssub_6A557
		SBCCS				_ssub_6B393
		SRET

; =============== S U B R O U T I N E =======================================
_nsub_sub04F:
		LDA		#<[byte_6B3AB]
		LDY		#>[byte_6B3AB]
		JMP		_nsub_sub023

byte_6B3AB:
		.BYTE	_spr_lib4_05_idx,$00
		.BYTE	_spr_lib4_06_idx,$00
		.BYTE	_spr_lib4_05_idx,$40
		.BYTE	_spr_lib4_06_idx,$C0

; =============== O B J E C T   S C R I P T =================================
_obj_scr01_box_bonus:
		NJSR				_nsub_box_bonusA
		NJSR				_nsub_box_bonusB
		NJSR				_nsub_box_bonus_4prizes_shuffle
byte_6B3BC:
		NJSR				_nsub_box_bonus_box_obj_insert
		LOOP_A				$04,byte_6B3BC
		POS_Y_SET			$18,$00
		SJSR				_ssub_game_timer_init
		STORE				$0A,_timer_seconds_cnt
		SJSRS				_ssub_show_still_timer_4sec
		NJSR				_nsub_idxBs_10_set
		NJSR				_nsub_sub051
		SJSRS				_ssub_show_still_timer_4sec
		SJSRS				_ssub_show_still_timer_2sec
		NJSR				_nsub_idxBs_10_clear
		SJSRS				_ssub_show_still_timer_2sec
		NJSR				_nsub_box_bonusB
		NJSR				_nsub_idxBs_10_set
		SJSR				_ssub_timer_start
byte_6B3EB:
		NJSR				_nsub_sub056
		SBEQS				byte_6B3FA
		NJSR_SYNC			_nsub_obj_timer_spr_insert_test
		SBNES				byte_6B3EB
		NJSR				_nsub_sub057
byte_6B3FA:
		NJSR				_nsub_sub050
		SJMP				_ssub_delay_before_stage_complete	; LONG
; TODO, same long jump to once used sub, move here, remove jump

; =============== S U B R O U T I N E =======================================
_nsub_sub050:
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
_ssub_show_still_timer_4sec:
		SJSRS				_ssub_show_still_timer_2sec

; !FALLTHROUGH!

; =============== S C R I P T   R O U T I N E ===============================
_ssub_show_still_timer_2sec:
		NJSR_SYNC			_nsub_obj_timer_spr_insert_test
		LOOP_A				$78,_ssub_show_still_timer_2sec
		SRET

; =============== S U B R O U T I N E =======================================
_nsub_sub051:
		LDA		#$96
		STA		byte_436
		STA		byte_438
		LDA		#$97
		STA		byte_437
		STA		byte_439

; !FALLTHROUGH!

; =============== S U B R O U T I N E =======================================
_nsub_box_bonusB:
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
_nsub_box_bonusA:
		LDY		#$03
		LDA		#$F4
loc_6B44E:
		STA		byte_436,Y
		DEY
		BPL		loc_6B44E
		RTS

; =============== S U B R O U T I N E =======================================
_nsub_box_bonus_box_obj_insert:
		JSR		_nsub_get_box_bonus_prize_from_list
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
		LDA		_box_bonus_box_obj_scr_lib_lo,Y
		STA		_tmp_ptr0
		LDA		_box_bonus_box_obj_scr_lib_hi,Y
		STA		_tmp_ptr0+1
		LDY		#_OBJ_TYPE_AUTO
		JSR		_scr_load
		PLA
		STA		_obj_timerBs,X
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
_box_bonus_box_obj_scr_lib_lo:
		.BYTE	<[_obj_scr_box_bonus_boxA]
		.BYTE	<[_obj_scr_box_bonus_boxB]
		.BYTE	<[_obj_scr_box_bonus_boxC]
		.BYTE	<[_obj_scr_box_bonus_boxD]
_box_bonus_box_obj_scr_lib_hi:
		.BYTE	>[_obj_scr_box_bonus_boxA]
		.BYTE	>[_obj_scr_box_bonus_boxB]
		.BYTE	>[_obj_scr_box_bonus_boxC]
		.BYTE	>[_obj_scr_box_bonus_boxD]
_box_bonus_box_prize_list:
		.BYTE	$F4,$F5,$F6,$F7
_box_bonus_box_anim_lib:
		.BYTE	<[_obj_box_bonusA_anim]
		.BYTE	<[_obj_box_bonusB_anim]
		.BYTE	<[_obj_box_bonusC_anim]
		.BYTE	<[_obj_box_bonusD_anim]
off_6B4B2:
		.BYTE	>[_obj_box_bonusA_anim]
		.BYTE	>[_obj_box_bonusB_anim]
		.BYTE	>[_obj_box_bonusC_anim]
		.BYTE	>[_obj_box_bonusD_anim]
_obj_box_bonusA_anim:
		.BYTE	$21,$11,$11,$21,$14,$31,$43,$33,$34,$12,$34,$11,$13,$32,$32,$11
		.BYTE	$41,$00
_obj_box_bonusB_anim:
		.BYTE	$03,$33,$41,$11,$12,$13,$12,$31,$41,$43,$23,$32,$14,$32,$14,$33
		.BYTE	$33,$00
_obj_box_bonusC_anim:
		.BYTE	$01,$11,$23,$33,$43,$22,$14,$44,$33,$22,$31,$11,$43,$23,$43,$41
		.BYTE	$23,$00
_obj_box_bonusD_anim:
		.BYTE	$42,$23,$33,$41,$23,$44,$33,$13,$22,$14,$12,$43,$21,$43,$24,$11
		.BYTE	$11,$00

; =============== S U B R O U T I N E =======================================
_nsub_sub054:
		LDY		#$03
		LDA		_obj_x_lo_poss,X
loc_6B503:
		CMP		_box_bonus_box_x_pos_list,Y
		BEQ		loc_6B50C
		DEY
		BPL		loc_6B503
		RTS
loc_6B50C:
		LDA		_obj_timerBs,X
		STA		byte_436,Y
		RTS

; =============== S U B R O U T I N E =======================================
_nsub_sub055:
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
		.WORD	_nsub_sub055_sub0
		.WORD	_nsub_sub055_sub1
		.WORD	_nsub_sub055_sub2
		.WORD	_nsub_sub055_sub3

; =============== S U B R O U T I N E =======================================
_nsub_sub055_sub0:
		LDA		#$20
		BNE		_nsub_sub055_sub0_ex

; =============== S U B R O U T I N E =======================================
_nsub_sub055_sub2:
		LDA		#$E0

; =============== S U B R O U T I N E =======================================
_nsub_sub055_sub0_ex:
		STA		_obj_x_deltas,X
		RTS

; =============== S U B R O U T I N E =======================================
_nsub_sub055_sub1:
		LDA		#$20
		BNE		_nsub_sub055_sub1_ex

; =============== S U B R O U T I N E =======================================
_nsub_sub055_sub3:
		LDA		#$E0

; =============== S U B R O U T I N E =======================================
_nsub_sub055_sub1_ex:
		STA		_obj_y_deltas,X

; =============== S U B R O U T I N E =======================================
nullsub5:
		RTS

; =============== S U B R O U T I N E =======================================
_nsub_sub056:
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
_nsub_sub057:
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
		SPR_LIB_SET			_spr_lib5
		SPR_IDX_SET			_spr_lib5_37
		SJMPS				_obj_scr_box_bonus_box_common

; =============== S C R I P T ===============================================
_obj_scr_box_bonus_boxB:
		SPR_LIB_SET			_spr_lib6
		SPR_IDX_SET			_spr_lib6_01
		SJMPS				_obj_scr_box_bonus_box_common

; =============== S C R I P T ===============================================
_obj_scr_box_bonus_boxC:
		SPR_LIB_SET			_spr_lib5
		SPR_IDX_SET			_spr_lib5_24
		SJMPS				_obj_scr_box_bonus_box_common

; =============== S C R I P T ===============================================
_obj_scr_box_bonus_boxD:
		SPR_LIB_SET			_spr_lib5
		SPR_IDX_SET			_spr_lib5_25

; !FALLTHROUGH!

; =============== S C R I P T ===============================================
_obj_scr_box_bonus_box_common:
		SPRITE_ON
		HP_SET				$01
		SIZE_SET			$06,$0C
		DELTA_Y_SET			$E0
		SJSR				_ssub_anim_sync_frames10
		SUSPEND				$78
		DELTA_Y_SET			$20
		SJSR				_ssub_anim_sync_frames10
		DELTA_Y_SET			$00
		SPR_LIB_SET			_spr_lib3
		SPR_IDX_SET			_spr_lib3_00
byte_6B5D2:
		NJSR_SYNC			_nsub_sub058
		SBEQS				byte_6B5D2
byte_6B5D8:
		NJSR				_nsub_sub055
		SJSR				_ssub_anim_sync_frames10
		NJSR				_nsub_sub058
		SBNES				byte_6B5D8
		NJSR				_nsub_sub054
byte_6B5E7:
		NJSR_SYNC			_nsub_sub058
		SBEQS				byte_6B5E7
		KILL

; =============== S U B R O U T I N E =======================================
_nsub_sub058:
		LDY		_scr_idxAs,X
		LDA		_scr_idxBs,Y
		AND		#$10
		JMP		_scr_flags_update

; =============== S C R I P T ===============================================
_obj_scr_box_bonus_prize_continue:
		SPR_LIB_SET			_spr_lib5
		SPR_IDX_SET			_spr_lib5_37
		SPRITE_ON
		NJSR				_nsub_increment_continues
		SJMP				_ssub_suspend_forever

; =============== S C R I P T ===============================================
_obj_scr_box_bonus_prize_1up:
		SPR_LIB_SET			_spr_lib6
		SPR_IDX_SET			_spr_lib6_01
		SPRITE_ON
		NJSR				_nsub_inc_tmp_player_lives
		SRUN				_OBJ_TYPE_AUTO,_ssub_1up_text_float_up
		SJMP				_ssub_suspend_forever

; =============== S C R I P T ===============================================
_obj_scr_box_bonus_prize_30rrs:
		SPR_LIB_SET			_spr_lib5
		SPR_IDX_SET			_spr_lib5_24
		SPRITE_ON
		NJSR				_nsub_add_players_30_rr_ptss
		SRUN				_OBJ_TYPE_AUTO,_ssub_30_rr_pts_float_up
		SJMP				_ssub_suspend_forever

; =============== S C R I P T ===============================================
_ssub_30_rr_pts_float_up:
		SPR_LIB_SET			_spr_lib5
		SPR_IDX_SET			_spr_lib5_35
		SJMP				_ssub_prize_text_float_up_animate

; =============== S C R I P T ===============================================
_obj_scr_box_bonus_prize_10rrs:
		SPR_LIB_SET			_spr_lib5
		SPR_IDX_SET			_spr_lib5_25
		SPRITE_ON
		NJSR				_nsub_add_players_10_rr_ptss
		SRUN				_OBJ_TYPE_AUTO,_ssub_10_rr_pts_float_up
		SJMP				_ssub_suspend_forever

; =============== S C R I P T ===============================================
_ssub_10_rr_pts_float_up:
		SPR_LIB_SET			_spr_lib5
		SPR_IDX_SET			_spr_lib5_36
		SJMP				_ssub_prize_text_float_up_animate

; =============== S U B R O U T I N E =======================================
_nsub_increment_continues:
		LDA		_continues
		CMP		#$09
		BCS		locret_6B647
		INC		_continues
locret_6B647:
		RTS

; =============== S U B R O U T I N E =======================================
_nsub_inc_tmp_player_lives:
		LDY		_scr_idxAs,X
		LDA		_tmp_array400,Y
		CMP		#$0A
		BCS		locret_6B658
; TODO: CLC not needed here, C=0 already if branch not taken
		CLC
		ADC		#$01
		STA		_tmp_array400,Y
locret_6B658:
		RTS

; =============== S U B R O U T I N E =======================================
_nsub_add_players_30_rr_ptss:
		LDA		#$1E
		BNE		_nsub_add_players_rr_ptss

; =============== S U B R O U T I N E =======================================
_nsub_add_players_10_rr_ptss:
		LDA		#$0A

; !FALLTHROUGH!

; =============== S U B R O U T I N E =======================================
_nsub_add_players_rr_ptss:
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
_scr_cutscenes_start:
		SSWITCH				_cutscene_idx
		SCASE				_scr_cutscene00
		SCASE				_scr_cutscene01
		SCASE				_scr_cutscene02
		SCASE				_scr_cutscene03
		SCASE				_scr_cutscene04
		SCASE				_scr_cutscene05
		SCASE				_scr_cutscene06
		SCASE				_scr_cutscene07
		SCASE				_scr_cutscene08
		SCASE				_scr_cutscene09
		SCASE				_scr_cutscene0A
		SCASE				_scr_cutscene0B
		SCASE				_scr_cutscene0C
		SCASE				_scr_cutscene0D
		SCASE				_scr_cutscene0E
		SCASE				_scr_cutscene0F
		SCASE				_scr_cutscene10
		SCASE				_scr_cutscene11
		SCASE				_scr_cutscene12

; =============== S C R I P T ===============================================
_obj_scr_cutscene_skip_wait:
		SYNC
		PADS_TEST			_PAD0_PRESS,_PAD_START,_obj_scr_cutscene_skip_wait

; !FALLTHROUGH!

; =============== S C R I P T   R O U T I N E ===============================
_ssub_delayed_ingame_start:
		STORE				$04,_main_sub_idx
		SJMPS				_ssub_delayed_fade_out

; =============== S C R I P T   R O U T I N E ===============================
_ssub_delayed_next_cutscene:
		NJSR				_nsub_cut_idx_inc

; !FALLTHROUGH!

; =============== S C R I P T   R O U T I N E ===============================
_ssub_delayed_fade_out:
		APU_SE_SET			_APU_MUS_FADE_OUT
		SUSPEND				$20
		SJMP				_ssub_fade_out

; =============== S C R I P T ===============================================
_ssub_next_cutscene:
		NJSR				_nsub_cut_idx_inc
		SJMP				_ssub_fade_out

; =============== S U B R O U T I N E =======================================
_nsub_cut_idx_inc:
		LDX		_cutscene_idx
		INX
		CPX		#$13
		BCC		loc_6B6BF
		LDX		#$00
loc_6B6BF:
		STX		_cutscene_idx
		RTS

; =============== S C R I P T   R O U T I N E ===============================
_ssub_idxBs_10_set_clear_wait:
		NJSR				_nsub_idxBs_10_set
byte_6B6C5:
		NJSR_SYNC			_nsub_idxBs_10_test
		SBNES				byte_6B6C5
		SRET

; =============== S C R I P T   R O U T I N E ===============================
_ssub_cut_char_idxBs_10_clear_set_test:
		NJSR_SYNC			_nsub_cut_char_idxBs_10_clear
byte_6B6CF:
		NJSR_SYNC			_nsub_cut_char_idxBs_10_test
		SBEQS				byte_6B6CF
		SRET

; =============== S U B R O U T I N E =======================================
_nsub_cut_store_char_number:
		LDY		_obj_timerBs,X
		LDA		_scr_cur_slot_idx
		STA		_tmp_array400,Y
		RTS

; =============== S U B R O U T I N E =======================================
_nsub_cut_char_idxBs_10_clear:
		LDY		_obj_timerBs,X
		LDX		_tmp_array400,Y
		LDA		_scr_idxBs,X
		AND		#$EF
		STA		_scr_idxBs,X
		RTS

; =============== S U B R O U T I N E =======================================
_nsub_cut_char_idxBs_10_test:
		LDY		_obj_timerBs,X
		LDX		_tmp_array400,Y
		LDA		_scr_idxBs,X
		AND		#$10
		JMP		_scr_flags_update

; =============== S C R I P T   R O U T I N E ===============================
_ssub_wait_for_wnd_msg_is_over:
		NJSR_SYNC			_nsub_test_if_wnd_msg_is_over
		SBNES				_ssub_wait_for_wnd_msg_is_over
		SRET

; =============== S U B R O U T I N E =======================================
_nsub_test_if_wnd_msg_is_over:
		LDA		_wnd_msg_sub_idx
		JMP		_scr_flags_update

; =============== S C R I P T   R O U T I N E ===============================
_ssub_cut_obj_msg_spr_animate:
		NJSR				_nsub_cut_obj_spr_anim_update
		NJSR_SYNC			_nsub_test_if_wnd_msg_is_over
		SBNES				_ssub_cut_obj_msg_spr_animate
		SRET

; =============== S U B R O U T I N E =======================================
_nsub_cut_obj_spr_anim_update:
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
_nsub_cut_obj_talk_anim_update:
		LDY		_obj_hps,X
		LDA		_cur_wnd_msg_col
		AND		#$02
		BEQ		loc_6B72F
		LDY		_obj_damages,X
loc_6B72F:
		TYA
		STA		_obj_timerBs,X
		RTS

; =============== S C R I P T   R O U T I N E ===============================
_ssub_obj_idxCs_clear_low_nibble_flips_08_set:
		NJSR				_nsub_obj_idxCs_C0_clear
		FLIPS_SET			_OBJ_FLIPS08
		SRET

; =============== S C R I P T   R O U T I N E ===============================
_ssub_6B73A:
		HP_SET				$1B
		DAMAGE_SET			$1C
		SJSRS				_ssub_cut_obj_msg_spr_animate
		SJMPS				_ssub_idxBs_10_set_clear_wait

; =============== S C R I P T   R O U T I N E ===============================
_ssub_6B744:
		HP_SET				$1F
		DAMAGE_SET			$1E
		SJSRS				_ssub_cut_obj_msg_spr_animate
		SPR_IDX_SET			_spr_lib1_1B
		SJMP				_ssub_idxBs_10_set_clear_wait

; =============== S C R I P T   R O U T I N E ===============================
_ssub_6B750:
		SJSR				_ssub_B7547
		SJSR				_ssub_B7547
		SPR_IDX_SET			_spr_lib1_1B
		DELTA_Y_SET			$00
		SJMP				_ssub_idxBs_10_set_clear_wait

; =============== S C R I P T   R O U T I N E ===============================
_ssub_6B75D:
		SJSRS				_ssub_6B76F
		NJSR				_nsub_stun_sparkles_obj_scr_run
		SPR_IDX_SET			_spr_lib1_0D
		SUSPEND				$78
		NJSR				_nsub_obj_disable_from_idxCs_40_flag
		SPR_IDX_SET			_spr_lib1_1B
		SJMP				_ssub_idxBs_10_set_clear_wait

; =============== S C R I P T   R O U T I N E ===============================
_ssub_6B76F:
		SIZE_SET			$06,$16
		SRET

; =============== S U B R O U T I N E =======================================
_ssub_gadget_static_draw:
		NJSR				_nsub_idxBs_10_set
byte_6B776:
		NJSR				_nsub_cut_gadget_talk_spr_insert
		NJSR_SYNC			_nsub_idxBs_10_test
		SBNES				byte_6B776
		SRET

; =============== S U B R O U T I N E =======================================
_ssub_gadget_talk_draw:
		NJSR				_nsub_cut_obj_talk_anim_update
		NJSR				_nsub_cut_gadget_talk_spr_insert
		NJSR_SYNC			_nsub_test_if_wnd_msg_is_over
		SBNES				_ssub_gadget_talk_draw
		SRET

; =============== S U B R O U T I N E =======================================
_ssub_6B78D:
		HP_SET				$00
		DAMAGE_SET			$03
		SJSRS				_ssub_gadget_talk_draw
		SJMPS				_ssub_gadget_static_draw

; =============== S C R I P T   R O U T I N E ===============================
_ssub_6B797:
		HP_SET				$06
		DAMAGE_SET			$09
		SJSRS				_ssub_gadget_talk_draw
		TIMER_B_SET			$06
		SJMPS				_ssub_gadget_static_draw

; =============== S C R I P T   R O U T I N E ===============================
_ssub_6B7A3:
		SPR_IDX_SET			_spr_lib0_29
		SJSR				_ssub_anim_sync_frames10
		SPR_IDX_SET			_spr_lib0_2A
		SJSR				_ssub_anim_sync_frames10
		SPR_IDX_SET			_spr_lib0_2B
		SJSR				_ssub_anim_sync_frames10
		SPR_IDX_SET			_spr_lib0_2A
		SJMP				_ssub_anim_sync_frames10

; =============== S C R I P T   R O U T I N E ===============================
_ssub_monterey_static_draw:
		NJSR				_nsub_idxBs_10_set
byte_6B7BA:
		NJSR				_nsub_cut_monterey_talk_spr_insert
		NJSR_SYNC			_nsub_idxBs_10_test
		SBNES				byte_6B7BA
		SRET

; =============== S C R I P T   R O U T I N E ===============================
_ssub_monterey_talk_draw:
		NJSR				_nsub_cut_obj_talk_anim_update
		NJSR				_nsub_cut_monterey_talk_spr_insert
		NJSR_SYNC			_nsub_test_if_wnd_msg_is_over
		SBNES				_ssub_monterey_talk_draw
		SRET

; =============== S C R I P T   R O U T I N E ===============================
_ssub_6B7D1:
		HP_SET				$06
		DAMAGE_SET			$09
		SJSRS				_ssub_monterey_talk_draw
		TIMER_B_SET			$00
		SJMPS				_ssub_monterey_static_draw

; =============== S C R I P T   R O U T I N E ===============================
_ssub_6B7DD:
		SPR_IDX_SET			_spr_lib0_23
		SJSR				_ssub_anim_sync_frames10
		SPR_IDX_SET			_spr_lib0_24
		SJSR				_ssub_anim_sync_frames10
		SPR_IDX_SET			_spr_lib0_25
		SJSR				_ssub_anim_sync_frames10
		SPR_IDX_SET			_spr_lib0_24
		SJMP				_ssub_anim_sync_frames10

; =============== S C R I P T   R O U T I N E ===============================
_ssub_zipper_hover_animate:
		NJSR				_nsub_idxBs_10_set
		DELTA_X_SET			$00
		DELTA_Y_SET			$F8
byte_6B7F8:
		SPR_IDX_SET			_spr_lib0_17
		ANIMATE_HV_SYNC
		ANIMATE_HV_SYNC
		ANIMATE_HV_SYNC
		SPR_IDX_SET			_spr_lib0_18
		ANIMATE_HV_SYNC
		ANIMATE_HV_SYNC
		ANIMATE_HV_SYNC
		NJSR				_nsub_complement_y_deltas
		NJSR				_nsub_idxBs_10_test
		SBEQS				byte_6B823
		LOOP_B				$28,byte_6B7F8
byte_6B80F:
		SPR_IDX_SET			_spr_lib0_34
		ANIMATE_HV_SYNC
		ANIMATE_HV_SYNC
		ANIMATE_HV_SYNC
		SPR_IDX_SET			_spr_lib0_35
		ANIMATE_HV_SYNC
		ANIMATE_HV_SYNC
		ANIMATE_HV_SYNC
		NJSR				_nsub_complement_y_deltas
		LOOP_B				$02,byte_6B80F
		SJMPS				byte_6B7F8
byte_6B823:
		LOOP_B_STOP
		SRET

; =============== S C R I P T   R O U T I N E ===============================
_ssub_6B825:
		SPR_IDX_SET			_spr_lib0_17
		SJSRS				_ssub_6B82C
		SPR_IDX_SET			_spr_lib0_18

; !FALLTHROUGH!

; =============== S C R I P T   R O U T I N E ===============================
_ssub_6B82C:
		NJSR_SYNC			_nsub_obj_hor_move_with_wave_patternt
		LOOP_B				$03,_ssub_6B82C
		SRET

; =============== S C R I P T ===============================================
_scr_cutscene00:
		SRUN				_OBJ_TYPE_AUTO,_obj_scr_cutscene_skip_wait
		SUSPEND				$1E
		SRUN				_OBJ_TYPE_AUTO,_obj_scr_155
byte_6B83E:
		NJSR_SYNC			_nsub_sub064
		LOOP_A				$80,byte_6B83E
		LOOP_B				$02,byte_6B83E
		KILL

; =============== S U B R O U T I N E =======================================
_nsub_sub064:
		LDA		#$01
		LDX		#$00
		JSR		_nsub_sub065
		LDA		#$02
		INX

; =============== S U B R O U T I N E =======================================
_nsub_sub065:
		CLC
		ADC		_ppu_scroll_shadow_lo,X
		STA		_ppu_scroll_shadow_lo,X
		LDA		_ppu_scroll_nt_hor,X
		ADC		#$00
		STA		_ppu_scroll_nt_hor,X
		RTS

; =============== S C R I P T ===============================================
_obj_scr_155:
		NJSR				_nsub_obj_idxCs_C0_clear
		POS_X_SET			$F8,$FF
		POS_Y_SET			$30,$00
		DELTA_X_SET			$08
		FLIP_H_TOGGLE
		SPRITE_ON
byte_6B86D:
		SJSRS				_ssub_6B8AC
		LOOP_A				$12,byte_6B86D
		SJSRS				_ssub_6B8A0
		DELTA_Y_SET			$08
		SJSRS				_ssub_6B8AC
		SJSRS				_ssub_6B8AC
		SJSRS				_ssub_6B8A0
		DELTA_Y_SET			$F8
		SJSRS				_ssub_6B8AC
		SJSRS				_ssub_6B8AC
		STORE				$12,_pal_anim_mode_idx
		SRUN				_OBJ_TYPE_AUTO,_obj_scr_156
		DELTA_X_SET			$08
		DELTA_Y_SET			$00
byte_6B896:
		SJSRS				_ssub_6B8AC
		LOOP_A				$1E,byte_6B896
		SJMP				_ssub_delayed_next_cutscene

; =============== S C R I P T   R O U T I N E ===============================
_ssub_6B8A0:
		DELTA_X_SET			$00
		DELTA_Y_SET			$00
byte_6B8A4:
		SJSRS				_ssub_6B8AC
		LOOP_A				$04,byte_6B8A4
		SRET

; =============== S C R I P T   R O U T I N E ===============================
_ssub_6B8AC:
		SPR_IDX_SET			_spr_lib0_19
		SJSR				_ssub_anim_sync_frames10
		SPR_IDX_SET			_spr_lib0_1A
		SJMP				_ssub_anim_sync_frames10

; =============== S C R I P T ===============================================
_obj_scr_156:
		APU_SE_SET			_apu_mus55
		SUSPEND				$30
		SJMPS				_obj_scr_156

; =============== S C R I P T ===============================================
_scr_cutscene01:
		SRUN				_OBJ_TYPE_AUTO,_obj_scr_cutscene_skip_wait
		POS_Y_SET			$C0,$00
		TIMER_B_SET			$00
		SRUN				_OBJ_TYPE_AUTO,_obj_scr_157
		NJSR_SYNC			_nsub_cut_store_char_number
		SUSPEND				$1E
		MSG_DISPLAY			_msg00,_apu_mus5B
		MSG_WAIT
		SJSR				_ssub_cut_char_idxBs_10_clear_set_test
		MSG_DISPLAY			_msg01,_apu_mus56
		SJSR				_ssub_cut_char_idxBs_10_clear_set_test
		TIMER_B_SET			$03
		SRUN				_OBJ_TYPE_AUTO,_obj_scr_158
		NJSR_SYNC			_nsub_cut_store_char_number
		SJSR				_ssub_cut_char_idxBs_10_clear_set_test
		MSG_DISPLAY			_msg02,_apu_mus58
		SJSR				_ssub_cut_char_idxBs_10_clear_set_test
		TIMER_B_SET			$00
		MSG_DISPLAY			_msg03,_apu_mus56
		SJSR				_ssub_cut_char_idxBs_10_clear_set_test
		TIMER_B_SET			$03
		MSG_DISPLAY			_msg04,_apu_mus58
		SJSR				_ssub_cut_char_idxBs_10_clear_set_test
		TIMER_B_SET			$02
		POS_Y_SET			$A0,$00
		SRUN				_OBJ_TYPE_AUTO,_obj_scr_159
		NJSR_SYNC			_nsub_cut_store_char_number
		TIMER_B_SET			$00
		MSG_DISPLAY			_msg05,_apu_mus56
		SJSR				_ssub_cut_char_idxBs_10_clear_set_test
		TIMER_B_SET			$03
		MSG_DISPLAY			_msg06,_apu_mus58
		SJSR				_ssub_cut_char_idxBs_10_clear_set_test
		NJSR_SYNC			_nsub_cut_char_idxBs_10_clear
		TIMER_B_SET			$02
		MSG_DISPLAY			_msg07,_apu_mus59
		SJSR				_ssub_cut_char_idxBs_10_clear_set_test
		NJSR_SYNC			_nsub_cut_char_idxBs_10_clear
		TIMER_B_SET			$04
		SRUN				_OBJ_TYPE_AUTO,_obj_scr_15A
		NJSR_SYNC			_nsub_cut_store_char_number
		SJSR				_ssub_cut_char_idxBs_10_clear_set_test
		MSG_DISPLAY			_msg08,_apu_mus5A
		MSG_WAIT
		NJSR_SYNC			_nsub_cut_char_idxBs_10_clear
		TIMER_B_SET			$01
		POS_Y_SET			$C0,$00
		SRUN				_OBJ_TYPE_AUTO,_obj_scr_15B
		NJSR_SYNC			_nsub_cut_store_char_number
		SJSR				_ssub_cut_char_idxBs_10_clear_set_test
		TIMER_B_SET			$00
		MSG_DISPLAY			_msg09,_apu_mus56
		SJSR				_ssub_cut_char_idxBs_10_clear_set_test
		TIMER_B_SET			$01
		SJSR				_ssub_cut_char_idxBs_10_clear_set_test
		MSG_DISPLAY			_msg0A,_apu_mus57
		SJSR				_ssub_cut_char_idxBs_10_clear_set_test
		TIMER_B_SET			$00
		MSG_DISPLAY			_msg0B,_apu_mus56
		SJSR				_ssub_cut_char_idxBs_10_clear_set_test
		TIMER_B_SET			$01
		MSG_DISPLAY			_msg0C,_apu_mus57
		SJSR				_ssub_cut_char_idxBs_10_clear_set_test
		MSG_DISPLAY			_msg0D,_apu_mus56
		TIMER_B_SET			$00
		NJSR				_nsub_cut_char_idxBs_10_clear
		TIMER_B_SET			$01
		NJSR				_nsub_cut_char_idxBs_10_clear
		MSG_WAIT
		MSG_DISPLAY			_msg0E,_apu_mus5B
		MSG_WAIT
		SJMP				_ssub_delayed_ingame_start

; =============== S C R I P T ===============================================
_obj_scr_157:
		POS_X_SET			$B8,$00
		SPR_LIB_SET			_spr_lib1
		SPR_IDX_SET			_spr_lib1_1B
		SPRITE_ON
		SJSR				_ssub_idxBs_10_set_clear_wait
		SJSR				_ssub_6B750
		SJSR				_ssub_6B73A
		SJSR				_ssub_6B73A
		SJSR				_ssub_6B744
		SJSR				_ssub_6B73A
		SJSR				_ssub_6B73A
		FLIP_H_ON
		DELTA_X_SET			$10
		DELTA_Y_SET			$00
		SJSR				_ssub_B7533
		SJSR				_ssub_B7533
		KILL

; =============== S C R I P T ===============================================
_obj_scr_15B:
		SJSR				_ssub_obj_idxCs_clear_low_nibble_flips_08_set
		FLIP_H_ON
		POS_X_SET			$D8,$FF
		SJSR				_ssub_6B76F
		SPR_LIB_SET			_spr_lib2
		SPRITE_ON
		DELTA_X_SET			$10
		SJSR				_ssub_B7533
		SJSR				_ssub_B7533
		SPR_IDX_SET			_spr_lib2_05
		DELTA_Y_SET			$C0
		HP_SET				$01
		SJSR				_ssub_obj_wait_for_jump
		SJSR				_ssub_B7555
		SPR_IDX_SET			_spr_lib2_1B
		SJSR				_ssub_idxBs_10_set_clear_wait
		SJSR				_ssub_6B75D
		SJSR				_ssub_6B73A
		SJSR				_ssub_6B73A
		DELTA_X_SET			$00
		DELTA_Y_SET			$10
		SJSR				_ssub_obj_wait_for_jump
		SJSR				_ssub_B7555
		DELTA_X_SET			$10
byte_6B9F5:
		SJSR				_ssub_B7533
		LOOP_A				$06,byte_6B9F5
		KILL

; =============== S C R I P T ===============================================
_obj_scr_158:
		SJSR				_ssub_obj_idxCs_clear_low_nibble_flips_08_set
		FLIP_H_ON
		POS_X_SET			$F0,$FF
		SPRITE_ON
		DELTA_X_SET			$10
byte_6BA07:
		SJSR				_ssub_6B7A3
		LOOP_A				$04,byte_6BA07
		SPR_IDX_SET			_spr_lib0_28
		TIMER_B_SET			$00
		SJSR				_ssub_gadget_static_draw
		SJSR				_ssub_6B78D
		SJSR				_ssub_6B78D
		SJSR				_ssub_6B797
		TIMER_B_SET			$00
byte_6BA20:
		SJSR				_ssub_6B7A3
		LOOP_A				$06,byte_6BA20
		KILL

; =============== S C R I P T ===============================================
_obj_scr_159:
		SJSR				_ssub_obj_idxCs_clear_low_nibble_flips_08_set
		FLIP_H_ON
		POS_X_SET			$B8,$FF
		SJSR				_ssub_6B76F
		DELTA_X_SET			$10
		SPRITE_ON
byte_6BA35:
		SJSR				_ssub_6B7DD
		LOOP_A				$04,byte_6BA35
		DELTA_Y_SET			$C0
		HP_SET				$01
		SJSR				_ssub_obj_wait_for_jump
		SPR_IDX_SET			_spr_lib0_1C
		TIMER_B_SET			$00
		SJSR				_ssub_monterey_static_draw
		SJSR				_ssub_6B7D1
		SPR_IDX_SET			_spr_lib0_24
		DELTA_Y_SET			$C0
		HP_SET				$01
		SJSR				_ssub_obj_wait_for_jump
byte_6BA56:
		SJSR				_ssub_6B7DD
		LOOP_A				$08,byte_6BA56
		KILL

; =============== S C R I P T ===============================================
_obj_scr_15A:
		SJSR				_ssub_obj_idxCs_clear_low_nibble_flips_08_set
		FLIP_H_ON
		POS_X_SET			$F8,$FF
		POS_Y_SET			$80,$00
		SPRITE_ON
		DELTA_X_SET			$10
byte_6BA6B:
		SJSR				_ssub_6B825
		LOOP_A				$1A,byte_6BA6B
		NJSR				_nsub_idxBs_10_set
		SJSR				_ssub_zipper_hover_animate
		DELTA_X_SET			$10
byte_6BA7A:
		SJSR				_ssub_6B825
		LOOP_A				$1A,byte_6BA7A
		KILL

; =============== S C R I P T ===============================================
_scr_cutscene02:
		SRUN				_OBJ_TYPE_AUTO,_obj_scr_cutscene_skip_wait
		POS_Y_SET			$C0,$00
		TIMER_B_SET			$05
		SRUN				_OBJ_TYPE_AUTO,_obj_scr_15C
		NJSR_SYNC			_nsub_cut_store_char_number
		SUSPEND				$1E
		TIMER_B_SET			$00
		SRUN				_OBJ_TYPE_AUTO,_obj_scr_15D
		NJSR_SYNC			_nsub_cut_store_char_number
		TIMER_B_SET			$01
		SRUN				_OBJ_TYPE_AUTO,_obj_scr_15E
		NJSR_SYNC			_nsub_cut_store_char_number
		SJSR				_ssub_cut_char_idxBs_10_clear_set_test
		MSG_DISPLAY			_msg0F,_apu_mus56
		MSG_WAIT
		TIMER_B_SET			$05
		MSG_DISPLAY			_msg10,_apu_mus5C
		SJSR				_ssub_cut_char_idxBs_10_clear_set_test
		TIMER_B_SET			$01
		MSG_DISPLAY			_msg11,_apu_mus57
		NJSR_SYNC			_nsub_cut_char_idxBs_10_clear
		MSG_WAIT
		TIMER_B_SET			$05
		MSG_DISPLAY			_msg12,_apu_mus5C
		SJSR				_ssub_cut_char_idxBs_10_clear_set_test
		TIMER_B_SET			$00
		MSG_DISPLAY			_msg13,_apu_mus56
		MSG_WAIT
		TIMER_B_SET			$05
		MSG_DISPLAY			_msg14,_apu_mus5C
		SJSR				_ssub_cut_char_idxBs_10_clear_set_test
		NJSR_SYNC			_nsub_cut_char_idxBs_10_clear
		TIMER_B_SET			$00
		NJSR_SYNC			_nsub_cut_char_idxBs_10_clear
		TIMER_B_SET			$01
		SJSR				_ssub_cut_char_idxBs_10_clear_set_test
		SJMP				_ssub_delayed_ingame_start

; =============== S C R I P T ===============================================
_obj_scr_15D:
		SPR_LIB_SET			_spr_lib1
		POS_X_SET			$C0,$FF
		SJSRS				_ssub_6BB08
		SJMPS				byte_6BB1B

; =============== S C R I P T ===============================================
_obj_scr_15E:
		SPR_LIB_SET			_spr_lib2
		POS_X_SET			$A8,$FF
		SJSRS				_ssub_6BB08
		SJSR				_ssub_B7547
		DELTA_Y_SET			$00
		SJSR				_ssub_idxBs_10_set_clear_wait
		SJMPS				byte_6BB1B

; =============== S C R I P T   R O U T I N E ===============================
_ssub_6BB08:
		SJSR				_ssub_obj_idxCs_clear_low_nibble_flips_08_set
		FLIP_H_ON
		DELTA_X_SET			$10
		SPRITE_ON
byte_6BB0F:
		SJSR				_ssub_B7533
		LOOP_A				$04,byte_6BB0F
		SPR_IDX_SET			_spr_lib2_00
		SJMP				_ssub_idxBs_10_set_clear_wait
byte_6BB1B:
		SJSR				_ssub_B7533
		LOOP_A				$08,byte_6BB1B
		SJSR				_ssub_idxBs_10_set_clear_wait

; =============== S C R I P T ===============================================
_obj_scr_15C:
		POS_X_SET			$D0,$00
		POS_Y_SET			$90,$00
		SPR_LIB_SET			_spr_lib8
		SPR_IDX_SET			_spr_lib8_15
		SPRITE_ON
		SJSR				_ssub_idxBs_10_set_clear_wait
		HP_SET				$15
		DAMAGE_SET			$16
		SJSR				_ssub_cut_obj_msg_spr_animate
		SJSR				_ssub_idxBs_10_set_clear_wait
		SJSR				_ssub_cut_obj_msg_spr_animate
		SJSR				_ssub_idxBs_10_set_clear_wait
		SJSR				_ssub_cut_obj_msg_spr_animate
		SJSR				_ssub_idxBs_10_set_clear_wait
		DELTA_X_SET			$10
		FLIP_H_ON
byte_6BB4C:
		SPR_IDX_SET			_spr_lib8_18
		SJSR				_ssub_anim_sync_frames12
		SPR_IDX_SET			_spr_lib8_20
		SJSR				_ssub_anim_sync_frames12
		LOOP_A				$03,byte_6BB4C
		KILL

; =============== S C R I P T ===============================================
_scr_cutscene03:
		SRUN				_OBJ_TYPE_AUTO,_obj_scr_cutscene_skip_wait
		TIMER_B_SET			$00
		SRUN				_OBJ_TYPE_AUTO,_obj_scr_15F
		NJSR				_nsub_cut_store_char_number
		TIMER_B_SET			$01
		SRUN				_OBJ_TYPE_AUTO,_obj_scr_160
		NJSR				_nsub_cut_store_char_number
		SUSPEND				$30
		TIMER_B_SET			$00
		SJSR				_ssub_cut_char_idxBs_10_clear_set_test
		MSG_DISPLAY			_msg15,_apu_mus56
		SJSR				_ssub_cut_char_idxBs_10_clear_set_test
		TIMER_B_SET			$03
		SRUN				_OBJ_TYPE_AUTO,_obj_scr_161
		NJSR_SYNC			_nsub_cut_store_char_number
		SJSR				_ssub_cut_char_idxBs_10_clear_set_test
		TIMER_B_SET			$05
		SRUN				_OBJ_TYPE_AUTO,_obj_scr_162
		NJSR_SYNC			_nsub_cut_store_char_number
		TIMER_B_SET			$03
		MSG_DISPLAY			_msg16,_apu_mus58
		SJSR				_ssub_cut_char_idxBs_10_clear_set_test
		TIMER_B_SET			$01
		MSG_DISPLAY			_msg17,_apu_mus57
		SJSR				_ssub_cut_char_idxBs_10_clear_set_test
		TIMER_B_SET			$03
		MSG_DISPLAY			_msg18,_apu_mus58
		SJSR				_ssub_cut_char_idxBs_10_clear_set_test
		TIMER_B_SET			$01
		MSG_DISPLAY			_msg19,_apu_mus57
		SJSR				_ssub_cut_char_idxBs_10_clear_set_test
		TIMER_B_SET			$03
byte_6BBBA:
		MSG_DISPLAY			_msg1A,_apu_mus58
		SJSR				_ssub_cut_char_idxBs_10_clear_set_test
		SJSR				_ssub_6BC7C
		NJSR_SYNC			_nsub_sub066
		MSG_DISPLAY			_msg1B,_apu_mus58
		SJSR				_ssub_cut_char_idxBs_10_clear_set_test
		SJSR				_ssub_6BC7C
		SSWITCH				_hor_menu_pos
		SCASE				byte_6BBE2
		SCASE				byte_6BBD8
byte_6BBD8:
		STORE				$01,byte_E1
		NJSR_SYNC			_nsub_cut_char_idxBs_10_clear
		SJMPS				byte_6BBBA
byte_6BBE2:
		MSG_DISPLAY			_msg1C,_apu_mus58
		SJSR				_ssub_cut_char_idxBs_10_clear_set_test
		APU_SE_SET			_apu_mus4D
		SUSPEND				$3C
		SSWITCH				byte_E0
		SCASE				byte_6BBF4
		SCASE				byte_6BC47
byte_6BBF4:
		APU_SE_SET			_apu_mus46
byte_6BBF6:
		NJSR				_nsub_sub068
		DELTA_X_INC
		SUSPEND				$04
		LOOP_A				$03,byte_6BBF6
		SUSPEND				$10
		TIMER_B_SET			$01
		NJSR_SYNC			_nsub_cut_char_idxBs_10_clear
byte_6BC07:
		DELTA_X_DEC
		NJSR				_nsub_sub068
		SUSPEND				$04
		LOOP_A				$03,byte_6BC07
		NJSR_SYNC			_ppu_pal_apply
		APU_SE_SET			_apu_mus13
		TIMER_B_SET			$03
		MSG_DISPLAY			_msg1D,_apu_mus58
		SJSR				_ssub_cut_char_idxBs_10_clear_set_test
		MSG_DISPLAY			_msg1E,_apu_mus58
		SJSR				_ssub_cut_char_idxBs_10_clear_set_test
		TIMER_B_SET			$00
		SJSR				_ssub_cut_char_idxBs_10_clear_set_test
		MSG_DISPLAY			_msg1F,_apu_mus56
		SJSR				_ssub_cut_char_idxBs_10_clear_set_test
		TIMER_B_SET			$03
		MSG_DISPLAY			_msg20,_apu_mus58
		SJSR				_ssub_cut_char_idxBs_10_clear_set_test
		TIMER_B_SET			$00
		MSG_DISPLAY			_msg21,_apu_mus56
		SJSR				_ssub_cut_char_idxBs_10_clear_set_test
		SJMPS				byte_6BC5E
byte_6BC47:
		MSG_DISPLAY			_msg22,_apu_mus58
		SJSR				_ssub_cut_char_idxBs_10_clear_set_test
		TIMER_B_SET			$05
		NJSR_SYNC			_nsub_cut_char_idxBs_10_clear
		SUSPEND				$3C
		TIMER_B_SET			$03
		MSG_DISPLAY			_msg23,_apu_mus58
		SJSR				_ssub_cut_char_idxBs_10_clear_set_test
byte_6BC5E:
		TIMER_B_SET			$00
		MSG_DISPLAY			_msg24,_apu_mus56
		SJSR				_ssub_cut_char_idxBs_10_clear_set_test
		TIMER_B_SET			$03
		MSG_DISPLAY			_msg25,_apu_mus58
		SJSR				_ssub_cut_char_idxBs_10_clear_set_test
		TIMER_B_SET			$00
		MSG_DISPLAY			_msg26,_apu_mus56
		SJSR				_ssub_cut_char_idxBs_10_clear_set_test
		SJMP				_ssub_delayed_ingame_start

; =============== S C R I P T   R O U T I N E ===============================
_ssub_6BC7C:
		NJSR				_menu_init
		MENU_CURSOR_DRAW	_menu_data01
byte_6BC82:
		SYNC
		NJSR				_nsub_sub102
		PADS_TEST			_PAD0_PRESS,_PAD_LEFT|_PAD_RIGHT,byte_6BC93
		APU_SE_SET			_apu_mus31
		NJSR				_nsub_sub067
		MENU_CURSOR_DRAW	_menu_data01
byte_6BC93:
		PADS_TEST			_PAD0_PRESS,_PAD_A,byte_6BC82
		APU_SE_SET			_apu_mus32
		SRET

; =============== S U B R O U T I N E =======================================
_nsub_sub066:
		LDA		_hor_menu_pos
		STA		byte_E0
		LDA		#$00
		STA		byte_E1
		RTS

; =============== S U B R O U T I N E =======================================
_nsub_sub067:
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
_nsub_sub068:
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
_obj_scr_15F:
		SJSR				_ssub_obj_idxCs_clear_low_nibble_flips_08_set
		POS_X_SET			$1C,$01
		POS_Y_SET			$A0,$00
		SPR_LIB_SET			_spr_lib1
		SPRITE_ON
		DELTA_X_SET			$F0
byte_6BCD9:
		SJSR				_ssub_B7533
		LOOP_A				$04,byte_6BCD9
		SPR_IDX_SET			_spr_lib1_1B
		SJSR				_ssub_idxBs_10_set_clear_wait
		SJSR				_ssub_6B73A
		SSWITCH				byte_E0
		SCASE				byte_6BCEF
		SCASE				byte_6BCF9
byte_6BCEF:
		SJSR				_ssub_6B750
		SJSR				_ssub_6B73A
		FLIP_H_ON
		SJSR				_ssub_6B744
byte_6BCF9:
		SJSR				_ssub_6B73A
		SJSR				_ssub_6B73A

; =============== S C R I P T ===============================================
_obj_scr_160:
		SJSR				_ssub_obj_idxCs_clear_low_nibble_flips_08_set
		POS_X_SET			$10,$01
		POS_Y_SET			$90,$00
		SPR_LIB_SET			_spr_lib2
		SPRITE_ON
		DELTA_X_SET			$F0
		SJSR				_ssub_B7533
		SJSR				_ssub_B7533
		SPR_IDX_SET			_spr_lib2_1B
		SJSR				_ssub_idxBs_10_set_clear_wait
		SJSR				_ssub_6B73A
		SJSR				_ssub_6B73A
		SSWITCH				byte_E0
		SCASE				byte_6BD25
		SCASE				byte_6BD2D
byte_6BD25:
		SJSR				_ssub_6B76F
		NJSR				_nsub_stun_sparkles_obj_scr_run
		SPR_IDX_SET			_spr_lib2_0D
byte_6BD2D:
		SJMP				_ssub_suspend_forever

; =============== S C R I P T ===============================================
_obj_scr_161:
		SJSR				_ssub_obj_idxCs_clear_low_nibble_flips_08_set
		POS_X_SET			$F8,$FF
		POS_Y_SET			$C0,$00
		FLIP_H_ON
		SPRITE_ON
		DELTA_X_SET			$10
byte_6BD3D:
		SJSR				_ssub_6B7A3
		LOOP_A				$04,byte_6BD3D
		SPR_IDX_SET			_spr_lib0_28
		TIMER_B_SET			$00
		SJSR				_ssub_gadget_static_draw
		SJSR				_ssub_6B78D
		SJSR				_ssub_6B78D
byte_6BD51:
		SJSR				_ssub_6B78D
		SJSR				_ssub_6B78D
		SSWITCH				byte_E1
		SCASE				byte_6BD5E
		SCASE				byte_6BD51
byte_6BD5E:
		SJSR				_ssub_6B78D
		SSWITCH				byte_E0
		SCASE				byte_6BD68
		SCASE				byte_6BD6B
byte_6BD68:
		SJSR				_ssub_6B78D
byte_6BD6B:
		SJSR				_ssub_6B78D
		SJSR				_ssub_6B78D
		SJSR				_ssub_6B78D

; =============== S C R I P T ===============================================
_obj_scr_162:
		POS_X_SET			$88,$00
		POS_Y_SET			$A0,$00
		SPR_IDX_SET			_spr_lib0_38
		SPRITE_ON
		SJSR				_ssub_idxBs_10_set_clear_wait
		APU_SE_SET			_apu_mus46
byte_6BD82:
		SPR_IDX_SET			_spr_lib0_39
		SUSPEND				$06
		SPR_IDX_SET			_spr_lib0_3A
		SUSPEND				$06
		LOOP_A				$02,byte_6BD82
		SPR_IDX_SET			_spr_lib0_3B
		SUSPEND				$06
		KILL

; =============== S C R I P T ===============================================
_scr_cutscene04:
		SRUN				_OBJ_TYPE_AUTO,_obj_scr_cutscene_skip_wait
		TIMER_B_SET			$00
		SRUN				_OBJ_TYPE_AUTO,_obj_scr_163
		NJSR				_nsub_cut_store_char_number
		TIMER_B_SET			$01
		SRUN				_OBJ_TYPE_AUTO,_obj_scr_164
		NJSR				_nsub_cut_store_char_number
		TIMER_B_SET			$02
		SRUN				_OBJ_TYPE_AUTO,_obj_scr_165
		NJSR				_nsub_cut_store_char_number
		TIMER_B_SET			$04
		SRUN				_OBJ_TYPE_AUTO,_obj_scr_166
		NJSR_SYNC			_nsub_cut_store_char_number
		SUSPEND				$1E
		TIMER_B_SET			$01
		MSG_DISPLAY			_msg27,_apu_mus57
		SJSR				_ssub_cut_char_idxBs_10_clear_set_test
		SRUN				_OBJ_TYPE_AUTO,_obj_scr_167
		SUSPEND				$3C
		MSG_DISPLAY			_msg28,_apu_mus5A
		MSG_WAIT
		TIMER_B_SET			$00
		MSG_DISPLAY			_msg29,_apu_mus56
		SJSR				_ssub_cut_char_idxBs_10_clear_set_test
		TIMER_B_SET			$02
		MSG_DISPLAY			_msg2A,_apu_mus59
		SJSR				_ssub_cut_char_idxBs_10_clear_set_test
		TIMER_B_SET			$00
		MSG_DISPLAY			_msg2B,_apu_mus56
		SJSR				_ssub_cut_char_idxBs_10_clear_set_test
		MSG_DISPLAY			_msg2C,_apu_mus5A
		MSG_WAIT
		MSG_DISPLAY			_msg2D,_apu_mus56
		SJSR				_ssub_cut_char_idxBs_10_clear_set_test
		SJMP				_ssub_delayed_next_cutscene

; =============== S C R I P T ===============================================
_obj_scr_163:
		FLIP_H_ON
		POS_X_SET			$48,$00
		POS_Y_SET			$80,$00
		SPR_LIB_SET			_spr_lib1
		SPRITE_ON
		SJSR				_ssub_idxBs_10_set_clear_wait
		SJSR				_ssub_6B73A
		SJSR				_ssub_6B73A
		SJSR				_ssub_6B744

; =============== S C R I P T ===============================================
_obj_scr_164:
		FLIP_H_ON
		POS_X_SET			$30,$00
		POS_Y_SET			$80,$00
		SPR_LIB_SET			_spr_lib2
		SPRITE_ON
		SJSR				_ssub_idxBs_10_set_clear_wait
		SJSR				_ssub_6B73A

; =============== S C R I P T ===============================================
_obj_scr_165:
		POS_X_SET			$80,$00
		POS_Y_SET			$D0,$00
		SPRITE_ON
		SPR_IDX_SET			_spr_lib0_1C
		TIMER_B_SET			$00
		SJSR				_ssub_monterey_static_draw
		FLIP_H_ON
		SJSR				_ssub_6B7D1

; =============== S C R I P T ===============================================
_obj_scr_166:
		FLIP_H_ON
		SPRITE_ON
		POS_X_SET			$70,$00
		POS_Y_SET			$90,$00
byte_6BE3B:
		SJSR				_ssub_zipper_hover_animate
		SJMPS				byte_6BE3B

; =============== S C R I P T ===============================================
_obj_scr_167:
		SJSR				_ssub_obj_idxCs_clear_low_nibble_flips_08_set
		POS_X_SET			$10,$01
		POS_Y_SET			$B0,$00
		SPR_IDX_SET			_spr_lib0_3C
		SPRITE_ON
		DELTA_X_SET			$F8
byte_6BE4F:
		ANIMATE_HV_SYNC
		LOOP_A				$80,byte_6BE4F
		KILL

; =============== S C R I P T ===============================================
_scr_cutscene05:
		SRUN				_OBJ_TYPE_AUTO,_obj_scr_cutscene_skip_wait
		TIMER_B_SET			$00
		SRUN				_OBJ_TYPE_AUTO,_obj_scr_168
		NJSR				_nsub_cut_store_char_number
		TIMER_B_SET			$01
		SRUN				_OBJ_TYPE_AUTO,_obj_scr_169
		NJSR_SYNC			_nsub_cut_store_char_number
		SUSPEND				$3C
		SJSR				_ssub_cut_char_idxBs_10_clear_set_test
		MSG_DISPLAY			_msg2E,_apu_mus56
		MSG_WAIT
		APU_SE_SET			_apu_mus51
		SUSPEND				$3C
		MSG_DISPLAY			_msg2F,_apu_mus57
		MSG_WAIT
byte_6BE7E:
		SJSRS				_ssub_6BECE
		NJSR_SYNC			_ppu_pal_apply
		SUSPEND				$10
		SJSRS				_ssub_6BECE
		NJSR_SYNC			_pal_patch03_load
		SUSPEND				$04
		LOOP_A				$05,byte_6BE7E
		SUSPEND				$B4
		SJMP				_ssub_delayed_next_cutscene

; =============== S C R I P T ===============================================
_scr_cutscene07:
		SRUN				_OBJ_TYPE_AUTO,_obj_scr_cutscene_skip_wait
		TIMER_B_SET			$00
		SRUN				_OBJ_TYPE_AUTO,_obj_scr_16A
		NJSR				_nsub_cut_store_char_number
		TIMER_B_SET			$01
		SRUN				_OBJ_TYPE_AUTO,_obj_scr_16B
		NJSR_SYNC			_nsub_cut_store_char_number
		SUSPEND				$3C
		TIMER_B_SET			$01
		MSG_DISPLAY			_msg37,_apu_mus57
		SJSR				_ssub_cut_char_idxBs_10_clear_set_test
		TIMER_B_SET			$00
		MSG_DISPLAY			_msg38,_apu_mus56
		SJSR				_ssub_cut_char_idxBs_10_clear_set_test
		SJMP				_ssub_delayed_ingame_start

; =============== S C R I P T ===============================================
_scr_cutscene08:
		SUSPEND				$3C
		MSG_DISPLAY			_msg39,_apu_mus5B
		MSG_WAIT
		SJMP				_ssub_delayed_ingame_start

; =============== S C R I P T   R O U T I N E ===============================
_ssub_6BECE:
		TIMER_B_SET			$00
		NJSR				_nsub_cut_char_idxBs_10_clear
		TIMER_B_SET			$01
		NJSR				_nsub_cut_char_idxBs_10_clear
		SRET

; =============== S U B R O U T I N E =======================================
_pal_patch03_load:
		LDA		#<[_pal_patch03]
		LDY		#>[_pal_patch03]
		JMP		_far_prg3_pal_patch_load

; =============== S C R I P T ===============================================
_obj_scr_168:
		SPR_LIB_SET			_spr_lib1
		POS_X_SET			$F0,$FF
		SJMPS				byte_6BEED

; =============== S C R I P T ===============================================
_obj_scr_169:
		SPR_LIB_SET			_spr_lib2
		POS_X_SET			$D8,$FF
byte_6BEED:
		SPR_IDX_SET			_spr_lib2_20
		SJSR				_ssub_obj_idxCs_clear_low_nibble_flips_08_set
		FLIP_H_ON
		POS_Y_SET			$C0,$00
		DELTA_X_SET			$10
		SPRITE_ON
byte_6BEF9:
		SJSR				_ssub_anim_sync_frames10
		LOOP_A				$10,byte_6BEF9
		SJSR				_ssub_idxBs_10_set_clear_wait
byte_6BF03:
		SJSR				_ssub_idxBs_10_set_clear_wait
		SPR_IDX_SET			_spr_lib2_1B
		SJSR				_ssub_idxBs_10_set_clear_wait
		SPR_IDX_SET			_spr_lib2_20
		LOOP_A				$05,byte_6BF03
		SJMP				_ssub_suspend_forever

; =============== S C R I P T ===============================================
_obj_scr_16A:
		POS_X_SET			$70,$00
		POS_Y_SET			$C0,$00
		SPR_LIB_SET			_spr_lib1
		SPR_IDX_SET			_spr_lib1_1B
		FLIP_H_ON
		SPRITE_ON
		SJSR				_ssub_idxBs_10_set_clear_wait
		SJSR				_ssub_6B744
		SJSR				_ssub_6B73A

; =============== S C R I P T ===============================================
_obj_scr_16B:
		POS_X_SET			$58,$00
		POS_Y_SET			$C0,$00
		SPR_LIB_SET			_spr_lib2
		SPR_IDX_SET			_spr_lib2_1B
		FLIP_H_ON
		SPRITE_ON
		SJSR				_ssub_idxBs_10_set_clear_wait
		SJSR				_ssub_6B73A

; =============== S C R I P T ===============================================
_scr_cutscene06:
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
		SJMP				_ssub_delayed_next_cutscene

; =============== S C R I P T ===============================================
_scr_cutscene09:
		SRUN				_OBJ_TYPE_AUTO,_obj_scr_cutscene_skip_wait
		SRUN				_OBJ_TYPE_AUTO,_obj_scr_16C
		TIMER_B_SET			$00
		SRUN				_OBJ_TYPE_AUTO,_obj_scr_16D
		NJSR				_nsub_cut_store_char_number
		TIMER_B_SET			$01
		SRUN				_OBJ_TYPE_AUTO,_obj_scr_16E
		NJSR				_nsub_cut_store_char_number
		TIMER_B_SET			$02
		SRUN				_OBJ_TYPE_AUTO,_obj_scr_16F
		NJSR_SYNC			_nsub_cut_store_char_number
		SUSPEND				$3C
		TIMER_B_SET			$02
		MSG_DISPLAY			_msg3A,_apu_mus59
		SJSR				_ssub_cut_char_idxBs_10_clear_set_test
		TIMER_B_SET			$00
		MSG_DISPLAY			_msg3B,_apu_mus56
		SJSR				_ssub_cut_char_idxBs_10_clear_set_test
		TIMER_B_SET			$01
		SJSR				_ssub_cut_char_idxBs_10_clear_set_test
		MSG_DISPLAY			_msg3C,_apu_mus57
		SJSR				_ssub_cut_char_idxBs_10_clear_set_test
		TIMER_B_SET			$00
		MSG_DISPLAY			_msg3D,_apu_mus56
		SJSR				_ssub_cut_char_idxBs_10_clear_set_test
		TIMER_B_SET			$01
		SJSR				_ssub_cut_char_idxBs_10_clear_set_test
		TIMER_B_SET			$01
		MSG_DISPLAY			_msg3E,_apu_mus57
		SJSR				_ssub_cut_char_idxBs_10_clear_set_test
		SJMP				_ssub_delayed_ingame_start

		SECTION_END		0B, "GAME SCRIPTS A"

		BANK_END 4,$C000
