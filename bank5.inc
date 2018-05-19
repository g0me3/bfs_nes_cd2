
		ORG $8000

		BANK_START $05

		SECTION_START	0C

_spr_lib_list:
		SPR_LIB_IDX	_spr_lib0
		SPR_LIB_IDX	_spr_lib1
		SPR_LIB_IDX	_spr_lib2
		SPR_LIB_IDX	_spr_lib3
		SPR_LIB_IDX	_spr_lib4
		SPR_LIB_IDX	_spr_lib5
		SPR_LIB_IDX	_spr_lib6
		SPR_LIB_IDX	_spr_lib7
		SPR_LIB_IDX	_spr_lib8
		SPR_LIB_IDX	_spr_lib9

		SPR_LIB_START	_spr_lib0

		SPR_IDX	_spr_lib0_00
		SPR_IDX	_spr_lib0_01
		SPR_IDX	_spr_lib0_02_hp_1
		SPR_IDX	_spr_lib0_03_hp_2
		SPR_IDX	_spr_lib0_04_hp_3
		SPR_IDX	_spr_lib0_05_hp_4
		SPR_IDX	_spr_lib0_06_hp_full
		SPR_IDX	_spr_lib0_07
		SPR_IDX	_spr_lib0_08
		SPR_IDX	_spr_lib0_09
		SPR_IDX	_spr_lib0_0A
		SPR_IDX	_spr_lib0_0B
		SPR_IDX	_spr_lib0_0C
		SPR_IDX	_spr_lib0_0D
		SPR_IDX	_spr_lib0_0E
		SPR_IDX	_spr_lib0_0F
		SPR_IDX	_spr_lib0_10		; located at _ram_buf0
		SPR_IDX	_spr_lib0_11		; located at _ram_buf1
		SPR_IDX	_spr_lib0_12		; located at _ram_buf2
		SPR_IDX	_ptr_dummy
		SPR_IDX	_spr_lib0_14_hud_C_letter
		SPR_IDX	_spr_lib0_15_hud_D_letter
		SPR_IDX	_spr_lib0_16
		SPR_IDX	_spr_lib0_17
		SPR_IDX	_spr_lib0_18
		SPR_IDX	_spr_lib0_19
		SPR_IDX	_spr_lib0_1A
		SPR_IDX	_spr_lib0_1B
		SPR_IDX	_spr_lib0_1C
		SPR_IDX	_spr_lib0_1D
		SPR_IDX	_spr_lib0_1E
		SPR_IDX	_spr_lib0_1F
		SPR_IDX	_spr_lib0_20
		SPR_IDX	_spr_lib0_21
		SPR_IDX	_spr_lib0_22
		SPR_IDX	_spr_lib0_23
		SPR_IDX	_spr_lib0_24
		SPR_IDX	_spr_lib0_25
		SPR_IDX	_spr_lib0_26
		SPR_IDX	_spr_lib0_27
		SPR_IDX	_spr_lib0_28
		SPR_IDX	_spr_lib0_29
		SPR_IDX	_spr_lib0_2A
		SPR_IDX	_spr_lib0_2B
		SPR_IDX	_spr_lib0_2C
		SPR_IDX	_spr_lib0_2D
		SPR_IDX	_spr_lib0_2E
		SPR_IDX	_spr_lib0_2F
		SPR_IDX	_spr_lib0_30
		SPR_IDX	_spr_lib0_31
		SPR_IDX	_spr_lib0_32
		SPR_IDX	_spr_lib0_33
		SPR_IDX	_spr_lib0_34
		SPR_IDX	_spr_lib0_35
		SPR_IDX	_spr_lib0_36
		SPR_IDX	_spr_lib0_37
		SPR_IDX	_spr_lib0_38
		SPR_IDX	_spr_lib0_39
		SPR_IDX	_spr_lib0_3A
		SPR_IDX	_spr_lib0_3B
		SPR_IDX	_spr_lib0_3C
		SPR_IDX	_spr_lib0_3D
		SPR_IDX	_spr_lib0_3E
		SPR_IDX	_spr_lib0_3F
		SPR_IDX	_spr_lib0_40
		SPR_IDX	_spr_lib0_41
		SPR_IDX	_spr_lib0_42
		SPR_IDX	_spr_lib0_43

		SPR_LIB_START	_spr_lib1

		SPR_IDX	_spr_lib1_00
		SPR_IDX	_spr_lib1_01
		SPR_IDX	_spr_lib1_02
		SPR_IDX	_spr_lib1_03
		SPR_IDX	_spr_lib1_04
		SPR_IDX	_spr_lib1_05
		SPR_IDX	_spr_lib1_06
		SPR_IDX	_spr_lib1_07
		SPR_IDX	_spr_lib1_08
		SPR_IDX	_spr_lib1_09
		SPR_IDX	_spr_lib1_0A
		SPR_IDX	_spr_lib1_0B
		SPR_IDX	_spr_lib1_0C
		SPR_IDX	_spr_lib1_0D
		SPR_IDX	_spr_lib1_0E
		SPR_IDX	_spr_lib1_0F
		SPR_IDX	_spr_lib1_10
		SPR_IDX	_spr_lib1_11
		SPR_IDX	_spr_lib1_12
		SPR_IDX	_spr_lib1_13
		SPR_IDX	_spr_lib1_14
		SPR_IDX	_spr_lib1_15
		SPR_IDX	_spr_lib1_16
		SPR_IDX	_spr_lib1_17
		SPR_IDX	_spr_lib1_18
		SPR_IDX	_spr_lib1_19
		SPR_IDX	_spr_lib1_1A
		SPR_IDX	_spr_lib1_1B
		SPR_IDX	_spr_lib1_1C
		SPR_IDX	_spr_lib1_1D
		SPR_IDX	_spr_lib1_1E
		SPR_IDX	_spr_lib1_1F
		SPR_IDX	_spr_lib1_20
		SPR_IDX	_spr_lib1_21
		SPR_IDX	_spr_lib1_22

		SPR_LIB_START	_spr_lib2

		SPR_IDX	_spr_lib2_00
		SPR_IDX	_spr_lib2_01
		SPR_IDX	_spr_lib2_02
		SPR_IDX	_spr_lib2_03
		SPR_IDX	_spr_lib2_04
		SPR_IDX	_spr_lib2_05
		SPR_IDX	_spr_lib2_06
		SPR_IDX	_spr_lib2_07
		SPR_IDX	_spr_lib2_08
		SPR_IDX	_spr_lib2_09
		SPR_IDX	_spr_lib2_0A
		SPR_IDX	_spr_lib2_0B
		SPR_IDX	_spr_lib2_0C
		SPR_IDX	_spr_lib2_0D
		SPR_IDX	_spr_lib2_0E
		SPR_IDX	_spr_lib2_0F
		SPR_IDX	_spr_lib2_10
		SPR_IDX	_spr_lib2_11
		SPR_IDX	_ptr_dummy
		SPR_IDX	_spr_lib2_13
		SPR_IDX	_spr_lib2_14
		SPR_IDX	_spr_lib2_15
		SPR_IDX	_spr_lib2_16
		SPR_IDX	_spr_lib2_17
		SPR_IDX	_spr_lib2_18
		SPR_IDX	_spr_lib2_19
		SPR_IDX	_spr_lib2_1A
		SPR_IDX	_spr_lib2_1B
		SPR_IDX	_spr_lib2_1C
		SPR_IDX	_spr_lib2_1D
		SPR_IDX	_spr_lib2_1E
		SPR_IDX	_spr_lib2_1F
		SPR_IDX	_spr_lib2_20		; copy of _spr_lib1_20
		SPR_IDX	_spr_lib2_21		; copy of _spr_lib1_21
		SPR_IDX	_spr_lib2_22

		SPR_LIB_START	_spr_lib3

		SPR_IDX	_spr_lib3_00	; copy of _spr_lib7_4C
		SPR_IDX	_spr_lib3_01
		SPR_IDX	_spr_lib3_02
		SPR_IDX	_spr_lib3_03
		SPR_IDX	_spr_lib3_04
		SPR_IDX	_spr_lib3_05
		SPR_IDX	_spr_lib3_06
		SPR_IDX	_spr_lib3_07
		SPR_IDX	_spr_lib3_08

		SPR_LIB_START	_spr_lib4

		SPR_IDX	_spr_lib4_00
		SPR_IDX	_spr_lib4_01
		SPR_IDX	_spr_lib4_02
		SPR_IDX	_spr_lib4_03
		SPR_IDX	_spr_lib4_04
		SPR_IDX	_spr_lib4_05
		SPR_IDX	_spr_lib4_06

		SPR_LIB_START	_spr_lib6

		SPR_IDX	_spr_lib6_00
		SPR_IDX	_spr_lib6_01
		SPR_IDX	_ptr_dummy
		SPR_IDX	_spr_lib6_03
		SPR_IDX	_spr_lib6_04
		SPR_IDX	_spr_lib6_05
		SPR_IDX	_spr_lib6_06
		SPR_IDX	_spr_lib6_07
		SPR_IDX	_spr_lib6_08

		SPR_LIB_START	_spr_lib5

		SPR_IDX	_spr_lib5_00
		SPR_IDX	_spr_lib5_01
		SPR_IDX	_spr_lib5_02
		SPR_IDX	_spr_lib5_03
		SPR_IDX	_spr_lib5_04
		SPR_IDX	_spr_lib5_05
		SPR_IDX	_spr_lib5_06
		SPR_IDX	_spr_lib5_07
		SPR_IDX	_spr_lib5_08
		SPR_IDX	_spr_lib5_09
		SPR_IDX	_spr_lib5_0A
		SPR_IDX	_spr_lib5_0B
		SPR_IDX	_spr_lib5_0C
		SPR_IDX	_spr_lib5_0D
		SPR_IDX	_spr_lib5_0E
		SPR_IDX	_spr_lib5_0F
		SPR_IDX	_spr_lib5_10
		SPR_IDX	_spr_lib5_11
		SPR_IDX	_spr_lib5_12
		SPR_IDX	_spr_lib5_13
		SPR_IDX	_spr_lib5_14
		SPR_IDX	_spr_lib5_15
		SPR_IDX	_spr_lib5_16
		SPR_IDX	_spr_lib5_17
		SPR_IDX	_spr_lib5_18
		SPR_IDX	_spr_lib5_19
		SPR_IDX	_spr_lib5_1A
		SPR_IDX	_spr_lib5_1B
		SPR_IDX	_spr_lib5_1C
		SPR_IDX	_spr_lib5_1D
		SPR_IDX	_spr_lib5_1E
		SPR_IDX	_spr_lib5_1F
		SPR_IDX	_ptr_dummy
		SPR_IDX	_ptr_dummy
		SPR_IDX	_spr_lib5_22
		SPR_IDX	_spr_lib5_23
		SPR_IDX	_spr_lib5_24
		SPR_IDX	_spr_lib5_25
		SPR_IDX	_spr_lib5_26
		SPR_IDX	_spr_lib5_27
		SPR_IDX	_spr_lib5_28
		SPR_IDX	_spr_lib5_29
		SPR_IDX	_spr_lib5_2A
		SPR_IDX	_spr_lib5_2B
		SPR_IDX	_spr_lib5_2C
		SPR_IDX	_spr_lib5_2D
		SPR_IDX	_spr_lib5_2E
		SPR_IDX	_spr_lib5_2F
		SPR_IDX	_spr_lib5_30
		SPR_IDX	_spr_lib5_31
		SPR_IDX	_spr_lib5_32
		SPR_IDX	_spr_lib5_33
		SPR_IDX	_spr_lib5_34
		SPR_IDX	_spr_lib5_35
		SPR_IDX	_spr_lib5_36
		SPR_IDX	_spr_lib5_37
		SPR_IDX	_spr_lib5_38
		SPR_IDX	_spr_lib5_39
		SPR_IDX	_spr_lib5_3A
		SPR_IDX	_spr_lib5_3B
		SPR_IDX	_spr_lib5_3C
		SPR_IDX	_spr_lib5_3D
		SPR_IDX	_spr_lib5_3E
		SPR_IDX	_spr_lib5_3F
		SPR_IDX	_spr_lib5_40
		SPR_IDX	_spr_lib5_41
		SPR_IDX	_spr_lib5_42
		SPR_IDX	_spr_lib5_43
		SPR_IDX	_spr_lib5_44
		SPR_IDX	_spr_lib5_45
		SPR_IDX	_spr_lib5_46
		SPR_IDX	_spr_lib5_47

		SPR_LIB_START	_spr_lib7

		SPR_IDX	_spr_lib7_00
		SPR_IDX	_spr_lib7_01
		SPR_IDX	_spr_lib7_02
		SPR_IDX	_spr_lib7_03
		SPR_IDX	_spr_lib7_04
		SPR_IDX	_spr_lib7_05
		SPR_IDX	_spr_lib7_06
		SPR_IDX	_spr_lib7_07
		SPR_IDX	_spr_lib7_08
		SPR_IDX	_spr_lib7_09
		SPR_IDX	_spr_lib7_0A
		SPR_IDX	_ptr_dummy
		SPR_IDX	_spr_lib7_0C
		SPR_IDX	_spr_lib7_0D
		SPR_IDX	_spr_lib7_0E
		SPR_IDX	_spr_lib7_0F
		SPR_IDX	_spr_lib7_10
		SPR_IDX	_spr_lib7_11
		SPR_IDX	_spr_lib7_12
		SPR_IDX	_spr_lib7_13
		SPR_IDX	_spr_lib7_14
		SPR_IDX	_spr_lib7_15
		SPR_IDX	_spr_lib7_16
		SPR_IDX	_spr_lib7_17
		SPR_IDX	_spr_lib7_18
		SPR_IDX	_spr_lib7_19
		SPR_IDX	_spr_lib7_1A
		SPR_IDX	_spr_lib7_1B
		SPR_IDX	_spr_lib7_1C
		SPR_IDX	_spr_lib7_1D
		SPR_IDX	_spr_lib7_1E
		SPR_IDX	_spr_lib7_1F
		SPR_IDX	_spr_lib7_20
		SPR_IDX	_ptr_dummy
		SPR_IDX	_ptr_dummy
		SPR_IDX	_spr_lib7_23
		SPR_IDX	_spr_lib7_24
		SPR_IDX	_spr_lib7_25
		SPR_IDX	_spr_lib7_26
		SPR_IDX	_spr_lib7_27
		SPR_IDX	_spr_lib7_28
		SPR_IDX	_spr_lib7_29
		SPR_IDX	_spr_lib7_2A
		SPR_IDX	_spr_lib7_2B
		SPR_IDX	_spr_lib7_2C
		SPR_IDX	_spr_lib7_2D
		SPR_IDX	_spr_lib7_2E
		SPR_IDX	_spr_lib7_2F
		SPR_IDX	_spr_lib7_30
		SPR_IDX	_spr_lib7_31
		SPR_IDX	_spr_lib7_32
		SPR_IDX	_spr_lib7_33
		SPR_IDX	_spr_lib7_34
		SPR_IDX	_spr_lib7_35
		SPR_IDX	_spr_lib7_36
		SPR_IDX	_spr_lib7_37
		SPR_IDX	_spr_lib7_38
		SPR_IDX	_spr_lib7_39
		SPR_IDX	_spr_lib7_3A
		SPR_IDX	_spr_lib7_3B
		SPR_IDX	_spr_lib7_3C
		SPR_IDX	_spr_lib7_3D
		SPR_IDX	_spr_lib7_3E
		SPR_IDX	_spr_lib7_3F
		SPR_IDX	_spr_lib7_40
		SPR_IDX	_spr_lib7_41
		SPR_IDX	_spr_lib7_42
		SPR_IDX	_spr_lib7_43
		SPR_IDX	_spr_lib7_44
		SPR_IDX	_spr_lib7_45
		SPR_IDX	_spr_lib7_46
		SPR_IDX	_spr_lib7_47
		SPR_IDX	_spr_lib7_48
		SPR_IDX	_spr_lib7_49
		SPR_IDX	_spr_lib7_4A
		SPR_IDX	_spr_lib7_4B
		SPR_IDX	_spr_lib7_4C
		SPR_IDX	_spr_lib7_4D
		SPR_IDX	_spr_lib7_4E
		SPR_IDX	_spr_lib7_4F
		SPR_IDX	_spr_lib7_50
		SPR_IDX	_spr_lib7_51
		SPR_IDX	_spr_lib7_52
		SPR_IDX	_spr_lib7_53
		SPR_IDX	_spr_lib7_54
		SPR_IDX	_spr_lib7_55
		SPR_IDX	_spr_lib7_56
		SPR_IDX	_spr_lib7_57
		SPR_IDX	_spr_lib7_58
		SPR_IDX	_spr_lib7_59
		SPR_IDX	_spr_lib7_5A
		SPR_IDX	_spr_lib7_5B
		SPR_IDX	_spr_lib7_5C
		SPR_IDX	_ptr_dummy
		SPR_IDX	_spr_lib7_5E
		SPR_IDX	_spr_lib7_5F
		SPR_IDX	_spr_lib7_60
		SPR_IDX	_spr_lib7_61
		SPR_IDX	_spr_lib7_62
		SPR_IDX	_spr_lib7_63
		SPR_IDX	_spr_lib7_64
		SPR_IDX	_spr_lib7_65
		SPR_IDX	_spr_lib7_66
		SPR_IDX	_spr_lib7_67
		SPR_IDX	_spr_lib7_68
		SPR_IDX	_spr_lib7_69
		SPR_IDX	_spr_lib7_6A
		SPR_IDX	_spr_lib7_6B
		SPR_IDX	_spr_lib7_6C
		SPR_IDX	_spr_lib7_6D
		SPR_IDX	_spr_lib7_6E
		SPR_IDX	_spr_lib7_6F
		SPR_IDX	_spr_lib7_70
		SPR_IDX	_spr_lib7_71
		SPR_IDX	_spr_lib7_72
		SPR_IDX	_spr_lib7_73
		SPR_IDX	_spr_lib7_74
		SPR_IDX	_spr_lib7_75
		SPR_IDX	_spr_lib7_76
		SPR_IDX	_spr_lib7_77
		SPR_IDX	_spr_lib7_78
		SPR_IDX	_spr_lib7_79
		SPR_IDX	_spr_lib7_7A
		SPR_IDX	_spr_lib7_7B

		SPR_LIB_START	_spr_lib9

		SPR_IDX	_spr_lib9_00
		SPR_IDX	_spr_lib9_01
		SPR_IDX	_spr_lib9_02
		SPR_IDX	_spr_lib9_03
		SPR_IDX	_spr_lib9_04
		SPR_IDX	_spr_lib9_05
		SPR_IDX	_spr_lib9_06
		SPR_IDX	_spr_lib9_07
		SPR_IDX	_spr_lib9_08
		SPR_IDX	_spr_lib9_09
		SPR_IDX	_spr_lib9_0A
		SPR_IDX	_spr_lib9_0B

		SPR_LIB_START	_spr_lib8

		SPR_IDX	_spr_lib8_00
		SPR_IDX	_spr_lib8_01
		SPR_IDX	_spr_lib8_02
		SPR_IDX	_spr_lib8_03
		SPR_IDX	_ptr_dummy
		SPR_IDX	_ptr_dummy
		SPR_IDX	_spr_lib8_06
		SPR_IDX	_spr_lib8_07
		SPR_IDX	_spr_lib8_08
		SPR_IDX	_spr_lib8_09
		SPR_IDX	_spr_lib8_0A
		SPR_IDX	_spr_lib8_0B
		SPR_IDX	_spr_lib8_0C
		SPR_IDX	_spr_lib8_0D
		SPR_IDX	_spr_lib8_0E
		SPR_IDX	_spr_lib8_0F
		SPR_IDX	_spr_lib8_10
		SPR_IDX	_spr_lib8_11
		SPR_IDX	_spr_lib8_12
		SPR_IDX	_spr_lib8_13
		SPR_IDX	_ptr_dummy
		SPR_IDX	_spr_lib8_15
		SPR_IDX	_spr_lib8_16
		SPR_IDX	_spr_lib8_17
		SPR_IDX	_spr_lib8_18
		SPR_IDX	_spr_lib8_19
		SPR_IDX	_spr_lib8_1A
		SPR_IDX	_spr_lib8_1B
		SPR_IDX	_spr_lib8_1C
		SPR_IDX	_spr_lib8_1D
		SPR_IDX	_spr_lib8_1E
		SPR_IDX	_ptr_dummy
		SPR_IDX	_spr_lib8_20
		SPR_IDX	_spr_lib8_21
		SPR_IDX	_spr_lib8_22
		SPR_IDX	_spr_lib8_23
		SPR_IDX	_spr_lib8_24
		SPR_IDX	_spr_lib8_25
		SPR_IDX	_spr_lib8_26
		SPR_IDX	_spr_lib8_27
		SPR_IDX	_spr_lib8_28
		SPR_IDX	_spr_lib8_29
		SPR_IDX	_spr_lib8_2A
		SPR_IDX	_spr_lib8_2B
		SPR_IDX	_spr_lib8_2C
		SPR_IDX	_spr_lib8_2D
		SPR_IDX	_spr_lib8_2E
		SPR_IDX	_spr_lib8_2F
		SPR_IDX	_spr_lib8_30
		SPR_IDX	_spr_lib8_31
		SPR_IDX	_spr_lib8_32
		SPR_IDX	_spr_lib8_33
		SPR_IDX	_spr_lib8_34
		SPR_IDX	_spr_lib8_35
		SPR_IDX	_spr_lib8_36
		SPR_IDX	_spr_lib8_37
		SPR_IDX	_spr_lib8_38
		SPR_IDX	_spr_lib8_39
		SPR_IDX	_spr_lib8_3A
		SPR_IDX	_spr_lib8_3B
		SPR_IDX	_spr_lib8_3C
		SPR_IDX	_spr_lib8_3D
		SPR_IDX	_spr_lib8_3E
		SPR_IDX	_spr_lib8_3F
		SPR_IDX	_spr_lib8_40
		SPR_IDX	_spr_lib8_41
		SPR_IDX	_spr_lib8_42
		SPR_IDX	_spr_lib8_43
		SPR_IDX	_spr_lib8_44
		SPR_IDX	_spr_lib8_45
		SPR_IDX	_spr_lib8_46
		SPR_IDX	_spr_lib8_47
		SPR_IDX	_spr_lib8_48
		SPR_IDX	_spr_lib8_49
		SPR_IDX	_spr_lib8_4A
		SPR_IDX	_spr_lib8_4B
		SPR_IDX	_spr_lib8_4C
		SPR_IDX	_spr_lib8_4D
		SPR_IDX	_spr_lib8_4E
		SPR_IDX	_spr_lib8_4F
		SPR_IDX	_spr_lib8_50
		SPR_IDX	_spr_lib8_51
		SPR_IDX	_spr_lib8_52
		SPR_IDX	_spr_lib8_53
		SPR_IDX	_spr_lib8_54

_spr_lib1_22:
		.BYTE	$03,$EF,$EE,$11,$00,$13,$00,$15,$00,$82,$F8,$D0,$81,$00,$83,$C0
		.BYTE	$82,$00,$D0,$83,$00,$83,$80,$02,$F4,$E6,$02,$00,$04,$00,$81,$FC
		.BYTE	$E0,$85,$00,$81,$00,$E6,$0F,$00,$81,$F5,$EE,$0D,$01,$02,$F7,$F6
		.BYTE	$17,$00,$19,$00,$00
_spr_lib2_22:
		.BYTE	$82,$F8,$D0,$81,$00,$83,$C0,$82,$00,$D0,$83,$00,$83,$80,$81,$FC
		.BYTE	$E0,$85,$00,$82,$F5,$E6,$57,$00,$0D,$01,$81,$FD,$E6,$50,$00,$81
		.BYTE	$00,$E6,$0F,$00,$81,$F4,$EE,$59,$00,$82,$F7,$EE,$5B,$00,$5F,$00
		.BYTE	$82,$FF,$EE,$5D,$00,$60,$00,$00
_spr_lib0_01:
		.BYTE	$82,$B6,$CD,$EC,$00,$FC,$00,$82,$BE,$CD,$ED,$00,$FD,$00,$82,$0E
		.BYTE	$F5,$DC,$00,$EE,$00,$81,$FC,$FA,$CE,$00,$83,$F8,$05,$B8,$00,$B7
		.BYTE	$00,$B6,$00,$83,$00,$05,$B5,$00,$B4,$00,$B3,$00,$83,$08,$05,$EF
		.BYTE	$00,$FE,$00,$FF,$00,$82,$F0,$06,$CF,$00,$B9,$00,$82,$10,$0A,$B0
		.BYTE	$00,$B1,$00,$81,$18,$0E,$B2,$00,$00
_spr_lib0_00:
		.BYTE	$04,$E0,$E0,$C5,$02,$C7,$02,$C9,$02,$D5,$02,$04,$E0,$F0,$D7,$02
		.BYTE	$D9,$02,$D9,$02,$D9,$02,$00
_spr_lib1_00:
		.BYTE	$82,$F7,$E7,$02,$00,$06,$00,$82,$FF,$E7,$04,$00,$08,$00,$82,$F8
		.BYTE	$EF,$00,$01,$0A,$00,$81,$00,$F7,$0C,$00,$00
_spr_lib1_01:
		.BYTE	$02,$F3,$EF,$0E,$00,$10,$00,$02,$F4,$E7,$02,$00,$04,$00,$81,$F5
		.BYTE	$EF,$00,$01,$02,$F8,$F7,$12,$00,$14,$00,$00
_spr_lib1_02:
		.BYTE	$02,$F3,$EE,$0E,$00,$16,$00,$02,$F4,$E6,$02,$00,$04,$00,$81,$F5
		.BYTE	$EE,$00,$01,$02,$F8,$F6,$18,$00,$1A,$00,$81,$FF,$FE,$1C,$00,$00
_spr_lib1_03:
		.BYTE	$81,$F4,$E7,$02,$00,$81,$FC,$E7,$04,$00,$81,$F3,$EF,$0E,$00,$81
		.BYTE	$F5,$EF,$00,$01,$02,$F6,$F7,$03,$00,$05,$00,$02,$F8,$EF,$1E,$00
		.BYTE	$01,$00,$00
_spr_lib1_04:
		.BYTE	$81,$F1,$ED,$02,$00,$81,$F9,$ED,$04,$00,$82,$F8,$EF,$07,$00,$09
		.BYTE	$00,$81,$F0,$F5,$0E,$00,$81,$F2,$F5,$00,$01,$81,$00,$F7,$0B,$00
		.BYTE	$00
_spr_lib1_05:
		.BYTE	$03,$EF,$EE,$11,$00,$13,$00,$15,$00,$02,$F4,$E6,$02,$00,$04,$00
		.BYTE	$81,$00,$E6,$0F,$00,$81,$F5,$EE,$0D,$01,$02,$F7,$F6,$17,$00,$19
		.BYTE	$00,$00
_spr_lib1_06:
		.BYTE	$82,$F5,$E7,$1B,$00,$06,$00,$82,$FD,$E7,$1D,$00,$1F,$00,$81,$F6
		.BYTE	$EF,$00,$01,$02,$F8,$F7,$24,$00,$26,$00,$00
_spr_lib1_07:
		.BYTE	$82,$F5,$E6,$1B,$00,$06,$00,$82,$FD,$E6,$1D,$00,$1F,$00,$81,$F6
		.BYTE	$EE,$00,$01,$02,$F8,$F6,$28,$00,$2A,$00,$81,$FF,$FE,$1C,$00,$00
_spr_lib1_08:
		.BYTE	$82,$F5,$E7,$1B,$00,$06,$00,$82,$FD,$E7,$1D,$00,$1F,$00,$81,$F6
		.BYTE	$EF,$00,$01,$02,$F8,$F7,$2C,$00,$2E,$00,$00
_spr_lib1_09:
		.BYTE	$82,$F7,$E7,$1B,$00,$06,$00,$82,$FF,$E7,$1D,$00,$1F,$00,$82,$F8
		.BYTE	$EF,$00,$01,$20,$00,$81,$00,$F7,$22,$00,$00
_spr_lib1_0A:
		.BYTE	$84,$ED,$DF,$02,$00,$30,$00,$0D,$01,$3E,$00,$84,$F5,$DF,$04,$00
		.BYTE	$32,$00,$3A,$00,$21,$00,$81,$F4,$E6,$36,$00,$82,$FD,$E7,$34,$00
		.BYTE	$3C,$00,$81,$ED,$EF,$38,$00,$00
_spr_lib1_0B:
		.BYTE	$82,$F6,$E7,$1B,$00,$23,$00,$82,$FE,$E7,$1D,$00,$1F,$00,$81,$F7
		.BYTE	$EF,$0D,$01,$02,$F8,$F7,$17,$00,$19,$00,$00
_spr_lib1_0C:
		.BYTE	$83,$F8,$E5,$25,$00,$2D,$01,$35,$00,$83,$00,$E5,$04,$00,$33,$00
		.BYTE	$37,$00,$81,$F8,$ED,$31,$00,$00
_spr_lib1_0D:
		.BYTE	$82,$F5,$E7,$25,$00,$27,$00,$82,$FD,$E7,$04,$00,$08,$00,$82,$F8
		.BYTE	$EF,$2F,$01,$29,$00,$81,$00,$F7,$2B,$00,$00
_spr_lib0_0F:
		.BYTE	$81,$FC,$F8,$5E,$01,$00
_spr_lib1_1A:
		.BYTE	$03,$F4,$F5,$3F,$40,$3D,$40,$00,$41,$02,$F4,$FD,$42,$40,$40,$40
		.BYTE	$02,$FD,$ED,$04,$40,$02,$40,$82,$04,$EE,$39,$40,$3B,$40,$00
_spr_lib1_0E:
		.BYTE	$02,$F3,$ED,$02,$00,$04,$00,$82,$F4,$EE,$39,$00,$3B,$00,$03,$F4
		.BYTE	$F5,$00,$01,$3D,$00,$3F,$00,$02,$FC,$FD,$40,$00,$42,$00,$00
_spr_lib1_0F:
		.BYTE	$84,$F8,$E6,$44,$00,$46,$00,$4A,$00,$4C,$00,$82,$00,$F5,$3F,$00
		.BYTE	$42,$00,$81,$F0,$F7,$48,$00,$00
_spr_lib1_16:
		.BYTE	$82,$F6,$E7,$1B,$00,$06,$00,$82,$FE,$E7,$1D,$00,$1F,$00,$81,$F7
		.BYTE	$EF,$00,$01,$02,$F8,$F7,$20,$00,$22,$00,$00
_spr_lib1_17:
		.BYTE	$82,$F7,$E7,$02,$00,$4E,$00,$82,$FF,$E7,$04,$00,$08,$00,$82,$F8
		.BYTE	$EF,$82,$01,$0A,$00,$81,$00,$F7,$0C,$00,$00
_spr_lib1_10:
		.BYTE	$02,$F3,$EE,$0E,$01,$16,$01,$02,$F4,$E6,$02,$01,$04,$01,$81,$F5
		.BYTE	$EE,$00,$01,$02,$F8,$F6,$18,$01,$1A,$01,$81,$FF,$FE,$1C,$01,$00
_spr_lib1_11:
		.BYTE	$02,$EF,$ED,$02,$01,$04,$01,$82,$F0,$EE,$39,$01,$3B,$01,$03,$F0
		.BYTE	$F5,$00,$01,$3D,$01,$3F,$01,$02,$F8,$FD,$40,$01,$42,$01,$00
_spr_lib1_18:
		.BYTE	$83,$F8,$ED,$F4,$00,$F6,$00,$F8,$00,$83,$00,$ED,$F4,$40,$F6,$40
		.BYTE	$F8,$40,$81,$FC,$F5,$86,$01,$00
_spr_lib1_19:
		.BYTE	$83,$F8,$ED,$F4,$00,$FA,$00,$F3,$00,$83,$00,$ED,$F4,$40,$FA,$40
		.BYTE	$F3,$40,$00
_spr_lib2_00:
		.BYTE	$83,$F8,$E7,$30,$00,$00,$01,$56,$00,$02,$F7,$EF,$52,$00,$54,$00
		.BYTE	$81,$00,$E7,$50,$00,$81,$00,$F7,$58,$00,$00
_spr_lib2_01:
		.BYTE	$82,$F5,$E7,$30,$00,$00,$01,$02,$F3,$EF,$5A,$00,$5C,$00,$02,$F8
		.BYTE	$F7,$41,$00,$43,$00,$81,$FD,$E7,$50,$00,$00
_spr_lib2_02:
		.BYTE	$82,$F5,$E6,$30,$00,$00,$01,$02,$F3,$EE,$5A,$00,$45,$00,$02,$F8
		.BYTE	$F6,$47,$00,$1A,$00,$81,$FD,$E6,$50,$00,$81,$FF,$FE,$1C,$00,$00
_spr_lib2_03:
		.BYTE	$82,$F5,$E7,$30,$00,$00,$01,$81,$FD,$E7,$50,$00,$81,$F3,$EF,$5A
		.BYTE	$00,$02,$F6,$F7,$4D,$00,$4F,$00,$02,$F8,$EF,$49,$00,$4B,$00,$00
_spr_lib2_04:
		.BYTE	$82,$F2,$ED,$30,$00,$00,$01,$81,$FA,$ED,$50,$00,$82,$F8,$EF,$51
		.BYTE	$00,$53,$00,$81,$F0,$F5,$5A,$00,$81,$00,$F7,$55,$00,$00
_spr_lib2_05:
		.BYTE	$82,$F5,$E6,$57,$00,$0D,$01,$81,$FD,$E6,$50,$00,$81,$00,$E6,$0F
		.BYTE	$00,$81,$F4,$EE,$59,$00,$82,$F7,$EE,$5B,$00,$5F,$00,$82,$FF,$EE
		.BYTE	$5D,$00,$60,$00,$00
_spr_lib2_06:
		.BYTE	$82,$F5,$E7,$62,$00,$52,$00,$82,$FD,$E7,$64,$00,$66,$00,$81,$F6
		.BYTE	$EF,$00,$01,$02,$F8,$F7,$6C,$00,$6E,$00,$00
_spr_lib2_07:
		.BYTE	$82,$F5,$E6,$62,$00,$52,$00,$82,$FD,$E6,$64,$00,$66,$00,$81,$F6
		.BYTE	$EE,$00,$01,$02,$F8,$F6,$70,$00,$72,$00,$81,$FF,$FE,$1C,$00,$00
_spr_lib2_08:
		.BYTE	$82,$F5,$E7,$62,$00,$52,$00,$82,$FD,$E7,$64,$00,$66,$00,$81,$F6
		.BYTE	$EF,$00,$01,$02,$F8,$F7,$74,$00,$76,$00,$00
_spr_lib2_09:
		.BYTE	$82,$F7,$E7,$62,$00,$52,$00,$82,$FF,$E7,$64,$00,$66,$00,$82,$F8
		.BYTE	$EF,$00,$01,$68,$00,$81,$00,$F7,$6A,$00,$00
_spr_lib2_0A:
		.BYTE	$83,$ED,$E7,$30,$00,$7A,$00,$3E,$00,$83,$F5,$E7,$78,$00,$7C,$00
		.BYTE	$21,$00,$82,$FD,$E7,$34,$00,$3C,$00,$81,$ED,$EF,$0D,$01,$00
_spr_lib2_0B:
		.BYTE	$82,$F6,$E7,$62,$00,$59,$00,$82,$FE,$E7,$64,$00,$66,$00,$81,$F7
		.BYTE	$EF,$0D,$01,$02,$F8,$F7,$5F,$00,$60,$00,$00
_spr_lib2_0C:
		.BYTE	$02,$F8,$ED,$2D,$01,$6F,$00,$81,$FB,$E5,$63,$00,$81,$01,$E5,$50
		.BYTE	$00,$82,$F8,$ED,$6D,$00,$71,$00,$81,$00,$F5,$73,$00,$00
_spr_lib2_0D:
		.BYTE	$83,$F8,$E7,$63,$00,$2F,$01,$67,$00,$02,$F5,$EF,$65,$00,$54,$00
		.BYTE	$81,$FE,$E7,$50,$00,$81,$00,$F7,$69,$00,$00
_spr_lib2_1A:
		.BYTE	$83,$FC,$ED,$50,$40,$77,$40,$40,$40,$82,$04,$ED,$30,$40,$00,$41
		.BYTE	$82,$04,$EE,$39,$40,$75,$40,$82,$F4,$F5,$3F,$40,$42,$40,$00
_spr_lib2_0E:
		.BYTE	$82,$F4,$ED,$30,$00,$00,$01,$83,$FC,$ED,$50,$00,$77,$00,$40,$00
		.BYTE	$82,$F4,$EE,$39,$00,$75,$00,$82,$04,$F5,$3F,$00,$42,$00,$00
_spr_lib2_0F:
		.BYTE	$84,$F8,$E6,$79,$00,$7B,$00,$7D,$00,$4C,$00,$82,$00,$F5,$3F,$00
		.BYTE	$42,$00,$81,$F0,$F7,$48,$00,$00
_spr_lib2_16:
		.BYTE	$82,$F6,$E7,$62,$00,$52,$00,$82,$FE,$E7,$64,$00,$66,$00,$81,$F7
		.BYTE	$EF,$00,$01,$02,$F8,$F7,$68,$00,$6A,$00,$00
_spr_lib2_17:
		.BYTE	$83,$F8,$E7,$7F,$00,$82,$01,$56,$00,$02,$F7,$EF,$6B,$00,$54,$00
		.BYTE	$81,$00,$E7,$50,$00,$81,$00,$F7,$58,$00,$00
_spr_lib2_10:
		.BYTE	$82,$F5,$E6,$30,$01,$00,$01,$02,$F3,$EE,$5A,$01,$45,$01,$02,$F8
		.BYTE	$F6,$47,$01,$1A,$01,$81,$FD,$E6,$50,$01,$81,$FF,$FE,$1C,$01,$00
_spr_lib2_11:
		.BYTE	$82,$F0,$ED,$30,$01,$00,$01,$83,$F8,$ED,$50,$01,$77,$01,$40,$01
		.BYTE	$82,$F0,$EE,$39,$01,$75,$01,$82,$00,$F5,$3F,$01,$42,$01,$00
_spr_lib2_18:
		.BYTE	$83,$F8,$ED,$F5,$00,$F6,$00,$F8,$00,$83,$00,$ED,$F5,$40,$F6,$40
		.BYTE	$F8,$40,$81,$FC,$F5,$86,$01,$00
_spr_lib2_19:
		.BYTE	$83,$F8,$ED,$F7,$00,$FA,$00,$F3,$00,$83,$00,$ED,$F7,$40,$FA,$40
		.BYTE	$F3,$40,$00
_spr_lib6_00:
		.BYTE	$82,$F8,$F0,$9B,$00,$9D,$00,$82,$00,$F0,$9B,$40,$9F,$00,$00
_spr_lib6_01:
		.BYTE	$82,$F8,$F0,$A0,$01,$A2,$01,$82,$00,$F0,$A0,$41,$A2,$41,$00
_spr_lib3_00:
_spr_lib7_4C:
		.BYTE	$82,$F8,$EF,$8C,$00,$8D,$00,$82,$00,$EF,$8E,$00,$8F,$00,$00
_spr_lib3_01:
		.BYTE	$82,$F8,$EF,$8C,$00,$8D,$00,$82,$00,$EF,$8E,$00,$8F,$00,$81,$FA
		.BYTE	$F4,$7E,$01,$00
_spr_lib3_02:
		.BYTE	$82,$F8,$EF,$8C,$00,$8D,$00,$82,$00,$EF,$8E,$00,$8F,$00,$81,$FE
		.BYTE	$F4,$7E,$01,$00
_spr_lib3_08:
		.BYTE	$82,$F8,$EF,$8C,$01,$8D,$01,$82,$00,$EF,$8E,$01,$8F,$01,$00
_spr_lib4_00:
		.BYTE	$82,$F8,$F1,$90,$01,$91,$01,$82,$00,$F1,$92,$01,$93,$01,$00
_spr_lib4_01:
		.BYTE	$82,$F8,$F1,$90,$01,$91,$01,$82,$00,$F1,$92,$01,$93,$01,$81,$FA
		.BYTE	$F4,$7E,$01,$00
_spr_lib4_02:
		.BYTE	$82,$F8,$F1,$90,$01,$91,$01,$82,$00,$F1,$92,$01,$93,$01,$81,$FE
		.BYTE	$F4,$7E,$01,$00
_spr_lib6_03:
		.BYTE	$84,$F0,$E0,$95,$00,$94,$00,$94,$00,$95,$00,$84,$F8,$E0,$97,$00
		.BYTE	$99,$00,$96,$00,$97,$00,$84,$00,$E0,$97,$00,$99,$40,$96,$40,$97
		.BYTE	$40,$84,$08,$E0,$95,$40,$94,$40,$94,$40,$95,$40,$00
_spr_lib6_04:
		.BYTE	$82,$F8,$E8,$98,$01,$98,$81,$82,$00,$E8,$98,$41,$98,$C1,$00
_spr_lib6_05:
		.BYTE	$82,$F8,$E8,$9A,$01,$9A,$81,$82,$00,$E8,$9A,$41,$9A,$C1,$00
_spr_lib6_06:
		.BYTE	$82,$F8,$E8,$9C,$01,$9C,$81,$82,$00,$E8,$9C,$41,$9C,$C1,$00
_spr_lib6_07:
		.BYTE	$82,$F8,$E8,$9E,$01,$9E,$81,$82,$00,$E8,$9E,$41,$9E,$C1,$00
_spr_lib6_08:
		.BYTE	$02,$F8,$F8,$A4,$01,$A6,$01,$00
_spr_lib0_02_hp_1:
		.BYTE	$81,$00,$00,$88,$00,$00
_spr_lib0_03_hp_2:
		.BYTE	$02,$00,$00,$88,$00,$88,$00,$00
_spr_lib0_04_hp_3:
		.BYTE	$03,$00,$00,$88,$00,$88,$00,$88,$00,$00
_spr_lib0_05_hp_4:
		.BYTE	$04,$00,$00,$88,$00,$88,$00,$88,$00,$88,$00,$00
_spr_lib0_06_hp_full:
		.BYTE	$82,$00,$00,$8A,$00,$8B,$00,$82,$08,$00,$8A,$40,$8B,$40,$00
_spr_lib0_07:
		.BYTE	$04,$00,$08,$21,$01,$22,$01,$23,$01,$24,$01,$04,$00,$10,$25,$01
		.BYTE	$26,$02,$27,$02,$28,$02,$02,$03,$18,$29,$02,$2A,$02,$02,$08,$00
		.BYTE	$1F,$01,$20,$01,$81,$12,$18,$2B,$02,$00
_spr_lib0_08:
		.BYTE	$04,$00,$10,$18,$03,$19,$03,$1A,$03,$1B,$03,$03,$02,$18,$1C,$03
		.BYTE	$1D,$03,$1E,$03,$82,$08,$00,$13,$03,$15,$03,$82,$10,$00,$14,$03
		.BYTE	$16,$03,$81,$18,$08,$17,$03,$00
_spr_lib0_09:
		.BYTE	$03,$F6,$10,$0F,$00,$10,$00,$11,$02,$03,$FA,$08,$0C,$00,$0D,$00
		.BYTE	$0E,$02,$02,$FE,$00,$0A,$00,$0B,$00,$81,$FE,$18,$12,$00,$00
_spr_lib0_0A:
		.BYTE	$82,$00,$00,$06,$00,$08,$00,$82,$08,$00,$07,$00,$09,$00,$00
_spr_lib0_0B:
		.BYTE	$04,$00,$00,$43,$00,$72,$00,$73,$00,$82,$00,$81,$18,$08,$92,$00
		.BYTE	$00
_spr_lib0_0C:
		.BYTE	$04,$00,$00,$44,$00,$66,$00,$75,$00,$6A,$00,$00
_spr_lib0_0D:
		.BYTE	$05,$00,$00,$53,$00,$54,$00,$41,$00,$47,$00,$45,$00,$05,$18,$09
		.BYTE	$43,$00,$4C,$00,$45,$00,$41,$00,$52,$00,$00
_spr_lib0_0E:
		.BYTE	$81,$00,$00,$50,$00,$00
_spr_lib0_15_hud_D_letter:
		.BYTE	$81,$00,$F8,$87,$00,$00
_spr_lib0_16:
		.BYTE	$81,$00,$F8,$89,$00,$00
_spr_lib7_00:
		.BYTE	$82,$F3,$DF,$A8,$02,$AE,$02,$81,$F6,$E6,$AA,$03,$81,$FB,$E7,$B0
		.BYTE	$02,$81,$00,$E7,$B2,$01,$81,$07,$E8,$B4,$01,$81,$F0,$EF,$BC,$01
		.BYTE	$03,$F1,$EF,$B6,$02,$B8,$02,$BA,$02,$03,$F8,$F7,$BE,$02,$C1,$02
		.BYTE	$C3,$02,$81,$FD,$EF,$AC,$03,$00
_spr_lib7_01:
		.BYTE	$82,$F3,$DE,$A8,$02,$AE,$02,$81,$F6,$E5,$AA,$03,$81,$FB,$E6,$B0
		.BYTE	$02,$81,$00,$E6,$B2,$01,$81,$07,$E7,$B4,$01,$81,$F0,$EE,$BC,$01
		.BYTE	$03,$F1,$EE,$B6,$02,$B8,$02,$BA,$02,$81,$FD,$EE,$AC,$03,$02,$00
		.BYTE	$F6,$AD,$02,$AF,$02,$81,$01,$FE,$CB,$02,$00
_spr_lib7_02:
		.BYTE	$82,$F3,$DF,$A8,$02,$AE,$02,$81,$F6,$E6,$AA,$03,$81,$FB,$E7,$B0
		.BYTE	$02,$81,$00,$E7,$B2,$01,$81,$07,$E8,$B4,$01,$81,$F0,$EF,$BC,$01
		.BYTE	$03,$F1,$EF,$B6,$02,$B8,$02,$BA,$02,$03,$F8,$F7,$C5,$02,$C7,$02
		.BYTE	$C9,$02,$81,$FD,$EF,$AC,$03,$00
_spr_lib7_03:
		.BYTE	$02,$F8,$DE,$B1,$01,$B3,$01,$03,$F8,$F7,$C0,$02,$C2,$02,$C4,$02
		.BYTE	$82,$01,$DF,$A8,$02,$AE,$02,$02,$00,$EF,$BD,$02,$BF,$02,$81,$08
		.BYTE	$DF,$B5,$01,$82,$10,$E3,$B7,$02,$B9,$02,$81,$04,$E6,$AA,$03,$81
		.BYTE	$09,$E7,$B0,$02,$81,$07,$F1,$BB,$03,$00
_spr_lib7_04:
		.BYTE	$81,$F0,$DF,$D4,$01,$82,$F3,$DF,$A8,$02,$AE,$02,$81,$F8,$DF,$D6
		.BYTE	$01,$81,$07,$DF,$CC,$01,$81,$00,$E0,$CA,$01,$83,$E8,$E1,$CE,$01
		.BYTE	$D0,$01,$D2,$01,$81,$F6,$E6,$AA,$03,$81,$FB,$E7,$B0,$02,$82,$F0
		.BYTE	$EF,$C8,$01,$D8,$01,$03,$F1,$EF,$C6,$02,$B8,$02,$BA,$02,$02,$F7
		.BYTE	$F3,$D6,$C1,$D4,$C1,$03,$F8,$F7,$BE,$02,$C1,$02,$C3,$02,$81,$FD
		.BYTE	$EF,$AC,$03,$00
_spr_lib7_05:
		.BYTE	$82,$F3,$DF,$A8,$02,$AE,$02,$81,$07,$DF,$CC,$01,$81,$00,$E0,$CA
		.BYTE	$01,$81,$F6,$E6,$AA,$03,$81,$FB,$E7,$B0,$02,$81,$F0,$EF,$C8,$01
		.BYTE	$03,$F1,$EF,$C6,$02,$B8,$02,$BA,$02,$03,$F8,$F7,$BE,$02,$C1,$02
		.BYTE	$C3,$02,$81,$FD,$EF,$AC,$03,$00
_spr_lib7_06:
		.BYTE	$82,$F3,$DF,$A8,$02,$AE,$02,$81,$F6,$E6,$AA,$03,$81,$FB,$E7,$DA
		.BYTE	$02,$81,$00,$E7,$B2,$01,$81,$07,$E8,$B4,$01,$81,$F0,$EF,$BC,$01
		.BYTE	$03,$F1,$EF,$B6,$02,$DC,$02,$BA,$02,$03,$F8,$F7,$BE,$02,$C1,$02
		.BYTE	$C3,$02,$81,$FD,$EF,$AC,$03,$00
_spr_lib7_07:
		.BYTE	$02,$EB,$DF,$C1,$01,$C3,$01,$81,$00,$DF,$C5,$02,$81,$F3,$E7,$C9
		.BYTE	$01,$03,$F8,$EF,$D1,$02,$D3,$02,$D5,$02,$03,$F8,$F7,$D7,$02,$D9
		.BYTE	$02,$DB,$02,$02,$FC,$E7,$CB,$02,$CD,$02,$81,$FF,$E7,$C7,$03,$81
		.BYTE	$02,$F1,$CF,$03,$00
_spr_lib7_08:
		.BYTE	$02,$EA,$DF,$C1,$01,$C3,$01,$81,$FF,$DF,$C5,$02,$81,$F2,$E7,$C9
		.BYTE	$01,$03,$F7,$EF,$D1,$02,$D3,$02,$D5,$02,$03,$F7,$F7,$D7,$02,$DD
		.BYTE	$02,$DF,$02,$02,$FB,$E7,$CB,$02,$CD,$02,$81,$FE,$E7,$C7,$03,$81
		.BYTE	$01,$F1,$CF,$03,$00
_spr_lib7_09:
		.BYTE	$02,$EA,$DE,$C1,$01,$C3,$01,$81,$FF,$DE,$C5,$02,$81,$F2,$E6,$C9
		.BYTE	$01,$03,$F7,$EE,$D1,$02,$D3,$02,$E0,$02,$03,$F7,$F6,$D7,$02,$E4
		.BYTE	$02,$E6,$02,$02,$FB,$E6,$CB,$02,$CD,$02,$81,$FE,$E6,$C7,$03,$81
		.BYTE	$01,$F0,$CF,$03,$81,$06,$FE,$E2,$02,$00
_spr_lib7_0A:
		.BYTE	$02,$EA,$DF,$C1,$01,$C3,$01,$81,$FF,$DF,$C5,$02,$81,$F2,$E7,$C9
		.BYTE	$01,$03,$F7,$EF,$D1,$02,$D3,$02,$D5,$02,$03,$F7,$F7,$D7,$02,$E8
		.BYTE	$02,$EA,$02,$02,$FB,$E7,$CB,$02,$CD,$02,$81,$FE,$E7,$C7,$03,$81
		.BYTE	$01,$F1,$CF,$03,$00
_spr_lib7_0C:
		.BYTE	$85,$08,$D7,$F0,$01,$F4,$01,$FA,$02,$E1,$02,$DB,$02,$84,$00,$DF
		.BYTE	$F2,$01,$F8,$02,$FE,$02,$E3,$02,$81,$01,$E6,$C7,$03,$82,$F8,$E7
		.BYTE	$F6,$02,$FC,$02,$81,$03,$F2,$E5,$03,$00
_spr_lib7_0D:
		.BYTE	$83,$F8,$E7,$AE,$02,$E7,$02,$ED,$02,$83,$00,$E7,$B0,$02,$E9,$02
		.BYTE	$EF,$02,$81,$FB,$E9,$C7,$03,$82,$08,$EF,$EB,$02,$DB,$02,$81,$02
		.BYTE	$F3,$F1,$03,$00
_spr_lib7_0E:
		.BYTE	$04,$F0,$F8,$F3,$01,$F5,$01,$F7,$01,$B8,$01,$00
_spr_lib7_0F:
		.BYTE	$02,$F8,$ED,$CD,$00,$CF,$00,$82,$F8,$EF,$8C,$00,$8D,$00,$82,$00
		.BYTE	$EF,$8E,$00,$8F,$00,$00
_spr_lib7_10:
		.BYTE	$02,$F8,$EB,$CD,$00,$CF,$00,$82,$F8,$EF,$8C,$00,$8D,$00,$82,$00
		.BYTE	$EF,$8E,$00,$8F,$00,$00
_spr_lib7_11:
		.BYTE	$02,$F8,$E9,$CD,$00,$CF,$00,$82,$F8,$EF,$8C,$00,$8D,$00,$82,$00
		.BYTE	$EF,$8E,$00,$8F,$00,$00
_spr_lib7_12:
		.BYTE	$83,$F8,$E7,$CD,$00,$8C,$00,$8D,$00,$81,$FB,$E7,$DE,$01,$83,$00
		.BYTE	$E7,$CF,$00,$8E,$00,$8F,$00,$00
_spr_lib7_13:
		.BYTE	$03,$F3,$F7,$BE,$02,$C1,$02,$C3,$02,$82,$F8,$E7,$8C,$00,$8D,$00
		.BYTE	$82,$00,$E7,$8E,$00,$8F,$00,$00
_spr_lib7_14:
		.BYTE	$82,$F8,$E6,$8C,$00,$8D,$00,$82,$00,$E6,$8E,$00,$8F,$00,$02,$FB
		.BYTE	$F6,$AD,$02,$AF,$02,$81,$FC,$FE,$CB,$02,$00
_spr_lib7_15:
		.BYTE	$03,$F3,$F7,$C5,$02,$C7,$02,$C9,$02,$82,$F8,$E7,$8C,$00,$8D,$00
		.BYTE	$82,$00,$E7,$8E,$00,$8F,$00,$00
_spr_lib5_00:
		.BYTE	$02,$F8,$F8,$D5,$02,$D5,$42,$00
_spr_lib5_01:
		.BYTE	$02,$F8,$F8,$D1,$02,$D1,$42,$00
_spr_lib5_02:
		.BYTE	$02,$F8,$F8,$D3,$02,$D3,$42,$00
_spr_lib5_03:
		.BYTE	$82,$F8,$F0,$D5,$02,$D7,$02,$82,$00,$F0,$D5,$42,$D7,$42,$00
_spr_lib5_08:
		.BYTE	$81,$E9,$EE,$AD,$01,$03,$F1,$F0,$AF,$01,$B1,$01,$B3,$01,$03,$F1
		.BYTE	$F8,$B7,$01,$B9,$01,$BB,$01,$82,$09,$EF,$B5,$01,$BD,$01,$00
_spr_lib7_16:
		.BYTE	$02,$F8,$E8,$CC,$01,$C2,$02,$81,$FF,$E6,$CE,$01,$83,$F8,$E8,$C0
		.BYTE	$02,$C4,$02,$C8,$02,$82,$00,$F0,$C6,$02,$CA,$02,$81,$F8,$F5,$D2
		.BYTE	$03,$81,$00,$F6,$D4,$03,$00
_spr_lib7_17:
		.BYTE	$83,$F8,$E8,$C0,$02,$C4,$02,$C8,$02,$02,$F8,$E8,$CC,$01,$C2,$02
		.BYTE	$83,$00,$E8,$D0,$01,$C6,$02,$CA,$02,$81,$F8,$F5,$D2,$03,$81,$00
		.BYTE	$F6,$D4,$03,$00
_spr_lib7_18:
		.BYTE	$02,$F8,$E8,$CC,$01,$C2,$02,$81,$FF,$E6,$CE,$01,$83,$F8,$E8,$C0
		.BYTE	$02,$C4,$02,$D6,$02,$82,$00,$F0,$C6,$02,$CA,$02,$81,$F8,$F5,$D2
		.BYTE	$03,$81,$00,$F6,$D4,$03,$00
_spr_lib7_19:
		.BYTE	$83,$F8,$E8,$C0,$02,$C4,$02,$D6,$02,$02,$F8,$E8,$CC,$01,$C2,$02
		.BYTE	$83,$00,$E8,$D0,$01,$C6,$02,$CA,$02,$81,$F8,$F5,$D2,$03,$81,$00
		.BYTE	$F6,$D4,$03,$00
_spr_lib7_1A:
		.BYTE	$02,$F8,$E8,$CC,$01,$C2,$02,$81,$FF,$E6,$CE,$01,$83,$F8,$E8,$C0
		.BYTE	$02,$C4,$02,$D8,$02,$82,$00,$F0,$C6,$02,$CA,$02,$81,$F8,$F5,$D2
		.BYTE	$03,$81,$00,$F6,$D4,$03,$00
_spr_lib7_1B:
		.BYTE	$83,$F8,$E8,$C0,$02,$C4,$02,$D8,$02,$02,$F8,$E8,$CC,$01,$C2,$02
		.BYTE	$83,$00,$E8,$D0,$01,$C6,$02,$CA,$02,$81,$F8,$F5,$D2,$03,$81,$00
		.BYTE	$F6,$D4,$03,$00
_spr_lib7_1C:
		.BYTE	$82,$F9,$F8,$DA,$02,$B6,$02,$00
_spr_lib8_00:
		.BYTE	$82,$F3,$F0,$A8,$02,$A9,$02,$81,$04,$F0,$AC,$02,$81,$F3,$F5,$AA
		.BYTE	$00,$02,$FB,$F8,$AB,$02,$AD,$02,$00
_spr_lib8_01:
		.BYTE	$03,$F8,$F0,$AE,$02,$B0,$02,$B2,$02,$82,$F8,$F0,$AA,$00,$AF,$02
		.BYTE	$81,$FE,$F0,$AA,$00,$02,$00,$F8,$B1,$02,$B3,$02,$00
_spr_lib8_02:
		.BYTE	$82,$F0,$F0,$B4,$02,$B5,$02,$82,$F8,$F0,$B6,$02,$B7,$02,$82,$00
		.BYTE	$F0,$B8,$02,$B9,$02,$82,$08,$F0,$A1,$02,$A3,$02,$81,$04,$F4,$AA
		.BYTE	$00,$81,$EF,$F5,$AA,$00,$00
_spr_lib8_03:
		.BYTE	$81,$00,$E0,$BC,$02,$81,$F8,$E8,$BA,$02,$81,$08,$E8,$BB,$02,$00
_spr_lib8_06:
		.BYTE	$83,$08,$E8,$C0,$02,$B2,$02,$B3,$02,$02,$F8,$F0,$91,$02,$B0,$02
		.BYTE	$81,$08,$E8,$C2,$00,$82,$F8,$F0,$AA,$00,$D4,$02,$81,$FE,$F0,$AA
		.BYTE	$00,$81,$00,$F8,$B1,$02,$00
_spr_lib8_08:
		.BYTE	$84,$F0,$E0,$C6,$43,$CC,$03,$CC,$83,$C6,$C3,$84,$F8,$E0,$C4,$43
		.BYTE	$CE,$03,$A5,$03,$C8,$43,$84,$00,$E0,$C4,$03,$D0,$03,$A7,$03,$C8
		.BYTE	$03,$84,$08,$E0,$C6,$03,$CA,$03,$CA,$83,$C6,$83,$00
_spr_lib8_07:
		.BYTE	$82,$F8,$F0,$86,$01,$BD,$01,$82,$00,$F0,$A0,$01,$BF,$01,$00
_spr_lib7_1D:
		.BYTE	$03,$F4,$F0,$A8,$03,$AA,$03,$AC,$03,$03,$F4,$F8,$AF,$01,$B0,$03
		.BYTE	$B3,$01,$03,$F4,$F8,$AE,$03,$B1,$01,$B2,$03,$00
_spr_lib7_1E:
		.BYTE	$84,$F4,$E0,$A8,$03,$AE,$03,$B4,$03,$AF,$01,$84,$FC,$E0,$AA,$03
		.BYTE	$B0,$03,$B6,$03,$B1,$01,$84,$04,$E0,$AC,$03,$B2,$03,$B8,$03,$B3
		.BYTE	$01,$02,$F5,$F8,$BA,$03,$BC,$03,$00
_spr_lib7_1F:
		.BYTE	$83,$F4,$D8,$A8,$03,$AE,$03,$B4,$03,$83,$FC,$D8,$AA,$03,$B0,$03
		.BYTE	$B6,$03,$83,$04,$D8,$AC,$03,$B2,$03,$B8,$03,$02,$F4,$F8,$BE,$03
		.BYTE	$A1,$03,$02,$F5,$F0,$BA,$03,$BC,$03,$00
_spr_lib7_20:
		.BYTE	$84,$F4,$D8,$A5,$03,$A7,$03,$B4,$03,$A9,$03,$85,$FC,$D8,$AA,$03
		.BYTE	$B0,$03,$B6,$03,$AB,$03,$AD,$03,$83,$04,$D8,$AC,$03,$B2,$03,$B8
		.BYTE	$03,$81,$EC,$D9,$A3,$03,$81,$F7,$F8,$BE,$43,$00
_spr_lib7_23:
		.BYTE	$84,$FC,$E0,$AD,$C3,$AB,$C3,$B6,$C3,$B1,$01,$81,$01,$E0,$BE,$83
		.BYTE	$83,$04,$E8,$A9,$C3,$B4,$C3,$AE,$C3,$82,$F4,$F0,$B8,$C3,$B2,$C3
		.BYTE	$03,$F4,$F8,$AF,$01,$B0,$C3,$B3,$01,$00
_spr_lib7_24:
		.BYTE	$03,$F4,$F8,$AF,$01,$B1,$01,$B3,$01,$02,$FB,$F8,$BC,$C3,$BA,$C3
		.BYTE	$02,$FC,$F0,$A1,$C3,$BE,$C3,$00
_spr_lib8_09:
		.BYTE	$83,$F0,$D5,$BB,$03,$C4,$03,$CC,$03,$85,$F8,$D6,$BD,$03,$C6,$03
		.BYTE	$CE,$03,$AF,$02,$B7,$02,$81,$FE,$D8,$BC,$01,$85,$00,$D8,$AA,$02
		.BYTE	$B4,$02,$D0,$03,$D6,$03,$B9,$02,$84,$08,$D8,$BF,$03,$C8,$03,$D2
		.BYTE	$01,$D8,$03,$82,$10,$DA,$C0,$03,$CA,$01,$81,$FC,$E0,$BE,$01,$82
		.BYTE	$F0,$EC,$D4,$02,$B5,$02,$81,$E8,$F0,$AB,$02,$00
_spr_lib8_0A:
		.BYTE	$83,$F8,$D8,$A8,$03,$B2,$03,$A3,$03,$81,$FE,$D8,$BC,$01,$85,$00
		.BYTE	$D8,$AA,$02,$B4,$02,$A5,$03,$B1,$03,$B9,$02,$84,$08,$D8,$AC,$03
		.BYTE	$B6,$03,$A7,$01,$B3,$03,$82,$F0,$DD,$B0,$03,$A1,$01,$81,$E8,$DE
		.BYTE	$AE,$01,$81,$FC,$E0,$BE,$01,$82,$10,$E0,$B8,$03,$A9,$01,$81,$18
		.BYTE	$E3,$BA,$01,$82,$F0,$EC,$AD,$02,$B5,$02,$82,$F8,$EE,$AF,$02,$B7
		.BYTE	$02,$81,$E8,$F0,$AB,$02,$00
_spr_lib8_0B:
		.BYTE	$83,$F8,$D8,$DA,$03,$C3,$03,$CB,$03,$02,$E8,$F0,$D3,$02,$D5,$02
		.BYTE	$81,$FE,$D8,$BC,$01,$85,$00,$D8,$AA,$02,$B4,$02,$CD,$03,$D7,$03
		.BYTE	$B9,$02,$84,$08,$D8,$DC,$03,$C5,$03,$CF,$03,$D9,$03,$82,$F0,$E0
		.BYTE	$C1,$01,$C9,$03,$81,$FC,$E0,$BE,$01,$82,$E9,$E3,$DE,$01,$C7,$03
		.BYTE	$82,$10,$EB,$D1,$01,$DB,$03,$82,$F8,$EE,$AF,$02,$B7,$02,$81,$F0
		.BYTE	$F4,$B5,$02,$02,$06,$F8,$DD,$03,$DF,$03,$00
_spr_lib8_0C:
		.BYTE	$04,$E8,$F0,$F2,$02,$F4,$02,$F6,$03,$F8,$01,$04,$E8,$F8,$FA,$02
		.BYTE	$FC,$02,$FE,$03,$E1,$01,$04,$EF,$E8,$EA,$02,$EC,$01,$EE,$01,$F0
		.BYTE	$03,$03,$F8,$E0,$E4,$03,$E6,$01,$E8,$03,$81,$F8,$E3,$E0,$02,$81
		.BYTE	$00,$E4,$E2,$02,$00
_spr_lib8_0D:
		.BYTE	$05,$E8,$F0,$F2,$02,$F4,$02,$F6,$03,$E3,$01,$E5,$01,$05,$E8,$F8
		.BYTE	$FA,$02,$FC,$02,$E9,$03,$EB,$01,$ED,$01,$04,$EF,$E8,$EA,$02,$EC
		.BYTE	$01,$EE,$01,$F0,$03,$03,$F8,$E0,$E4,$03,$E6,$01,$E8,$03,$81,$F8
		.BYTE	$E3,$E0,$02,$81,$00,$E4,$E2,$02,$81,$10,$EE,$E7,$01,$00
_spr_lib8_0E:
		.BYTE	$82,$F8,$F0,$90,$01,$91,$01,$82,$00,$F0,$92,$01,$93,$01,$00
_spr_lib7_25:
		.BYTE	$81,$F8,$E0,$CE,$02,$03,$F8,$E7,$C7,$02,$C9,$02,$CB,$02,$02,$F8
		.BYTE	$EF,$CD,$02,$CF,$02,$81,$00,$E1,$D0,$02,$81,$08,$E1,$D2,$02,$81
		.BYTE	$FC,$E7,$CA,$01,$81,$F8,$EF,$CC,$01,$02,$FA,$F7,$D1,$02,$D3,$02
		.BYTE	$00
_spr_lib7_26:
		.BYTE	$81,$F8,$DF,$CE,$02,$03,$F8,$E6,$C7,$02,$C9,$02,$CB,$02,$02,$F8
		.BYTE	$EE,$CD,$02,$CF,$02,$81,$00,$E0,$D0,$02,$81,$08,$E0,$D2,$02,$81
		.BYTE	$FC,$E6,$CA,$01,$81,$F8,$EE,$CC,$01,$02,$FA,$F6,$D5,$02,$D7,$02
		.BYTE	$81,$FF,$FD,$D9,$02,$00
_spr_lib7_27:
		.BYTE	$81,$F8,$E0,$CE,$02,$03,$F8,$E7,$C7,$02,$C9,$02,$CB,$02,$02,$F8
		.BYTE	$EF,$CD,$02,$CF,$02,$81,$00,$E1,$D0,$02,$81,$08,$E1,$D2,$02,$81
		.BYTE	$FC,$E7,$CA,$01,$81,$F8,$EF,$CC,$01,$02,$FA,$F7,$DB,$02,$DD,$02
		.BYTE	$00
_spr_lib7_28:
		.BYTE	$02,$F8,$EB,$CC,$81,$CF,$82,$81,$FF,$DC,$E2,$82,$81,$FA,$E3,$D5
		.BYTE	$82,$81,$02,$E3,$D7,$82,$82,$F8,$EB,$CD,$82,$DF,$82,$81,$00,$F3
		.BYTE	$E0,$82,$81,$08,$F3,$CB,$82,$81,$00,$F9,$D0,$82,$81,$08,$F9,$D2
		.BYTE	$82,$81,$F8,$FA,$CE,$82,$00
_spr_lib7_29:
		.BYTE	$83,$F0,$E8,$B5,$02,$BD,$02,$C4,$02,$81,$07,$E8,$BB,$02,$83,$F8
		.BYTE	$E9,$B7,$02,$BF,$02,$C6,$02,$83,$00,$E9,$B9,$02,$C0,$02,$C8,$02
		.BYTE	$81,$F4,$EF,$CA,$01,$81,$08,$F0,$C2,$02,$81,$F0,$F6,$CC,$01,$00
_spr_lib7_2A:
		.BYTE	$83,$F0,$E8,$CE,$02,$D4,$02,$DE,$02,$83,$F8,$E9,$D0,$02,$D6,$02
		.BYTE	$C1,$02,$83,$00,$E9,$D2,$02,$D8,$02,$C3,$02,$81,$F4,$EF,$CA,$01
		.BYTE	$82,$08,$F2,$DA,$02,$C5,$02,$81,$F0,$F6,$CC,$01,$81,$E8,$F9,$DC
		.BYTE	$02,$00
_spr_lib7_2B:
		.BYTE	$83,$F8,$E7,$E4,$03,$8C,$00,$8D,$00,$02,$F8,$E7,$E8,$00,$E6,$00
		.BYTE	$82,$00,$EF,$8E,$00,$8F,$00,$00
_spr_lib7_2C:
		.BYTE	$81,$F8,$E5,$EE,$00,$83,$F8,$E7,$EA,$03,$8C,$00,$8D,$00,$83,$00
		.BYTE	$E7,$EC,$00,$8E,$00,$8F,$00,$00
_spr_lib7_2D:
		.BYTE	$82,$F0,$DF,$F0,$03,$F6,$03,$84,$F8,$DF,$F2,$03,$F8,$03,$8C,$00
		.BYTE	$8D,$00,$81,$F8,$DF,$FC,$01,$81,$FF,$DF,$F4,$00,$83,$00,$E7,$FA
		.BYTE	$00,$8E,$00,$8F,$00,$00
_spr_lib7_2E:
		.BYTE	$82,$E8,$D7,$F0,$03,$F6,$03,$82,$F0,$D7,$F2,$03,$F8,$03,$81,$F0
		.BYTE	$D7,$FC,$01,$02,$F3,$E7,$FE,$03,$E1,$03,$02,$F8,$EF,$8C,$00,$8E
		.BYTE	$00,$02,$F8,$F7,$8D,$00,$8F,$00,$81,$FF,$DF,$F4,$00,$81,$00,$E7
		.BYTE	$FA,$00,$00
_spr_lib7_2F:
		.BYTE	$82,$E8,$D7,$F0,$03,$E7,$03,$82,$F0,$D7,$E3,$03,$E9,$03,$81,$F0
		.BYTE	$D7,$FC,$01,$81,$FF,$DF,$F4,$00,$81,$E0,$E1,$E5,$03,$02,$F3,$E7
		.BYTE	$FE,$03,$E1,$03,$83,$00,$E7,$FA,$00,$8E,$00,$8F,$00,$82,$F8,$EF
		.BYTE	$8C,$00,$8D,$00,$00
_spr_lib7_30:
		.BYTE	$03,$E0,$DF,$EB,$03,$ED,$03,$E9,$03,$02,$E8,$D7,$F0,$03,$E3,$03
		.BYTE	$81,$F0,$D7,$FC,$01,$02,$F3,$E7,$FE,$03,$E1,$03,$02,$F8,$EF,$8C
		.BYTE	$00,$8E,$00,$02,$F8,$F7,$8D,$00,$8F,$00,$81,$FF,$DF,$F4,$00,$81
		.BYTE	$00,$E7,$FA,$00,$00
_spr_lib7_31:
		.BYTE	$04,$E8,$E7,$F1,$03,$F3,$03,$E8,$00,$E6,$00,$02,$EC,$DF,$F0,$03
		.BYTE	$EF,$03,$83,$F8,$E7,$F5,$03,$8C,$00,$8D,$00,$81,$EF,$EF,$F7,$03
		.BYTE	$82,$00,$EF,$8E,$00,$8F,$00,$00
_spr_lib7_32:
		.BYTE	$82,$FC,$D8,$A8,$03,$AA,$03,$84,$F8,$E0,$B4,$03,$B6,$01,$BA,$01
		.BYTE	$B1,$02,$83,$00,$E8,$B8,$01,$BC,$01,$B3,$02,$00
_spr_lib7_33:
		.BYTE	$82,$FB,$D8,$AC,$03,$AE,$03,$84,$F8,$E0,$B4,$03,$BE,$01,$A3,$01
		.BYTE	$B5,$02,$83,$00,$E8,$A1,$01,$A5,$01,$B7,$02,$00
_spr_lib7_34:
		.BYTE	$82,$FB,$D8,$B0,$03,$B2,$03,$84,$F8,$E0,$B4,$03,$A7,$01,$AB,$01
		.BYTE	$B3,$42,$83,$00,$E8,$A9,$01,$AD,$01,$B1,$42,$81,$F8,$F0,$AF,$00
		.BYTE	$00
_spr_lib7_35:
		.BYTE	$82,$FC,$D8,$A8,$43,$AA,$43,$84,$00,$E0,$B4,$43,$A7,$41,$AB,$41
		.BYTE	$B3,$02,$83,$F8,$E8,$A9,$41,$AD,$41,$B1,$02,$81,$00,$F0,$AF,$40
		.BYTE	$00
_spr_lib7_36:
		.BYTE	$82,$FD,$D8,$AC,$43,$AE,$43,$84,$00,$E0,$B4,$43,$BE,$41,$A3,$41
		.BYTE	$B7,$02,$83,$F8,$E8,$A1,$41,$A5,$41,$B5,$02,$00
_spr_lib7_37:
		.BYTE	$82,$FD,$D8,$B0,$43,$B2,$43,$84,$00,$E0,$B4,$43,$B6,$41,$BA,$41
		.BYTE	$B1,$42,$83,$F8,$E8,$B8,$41,$BC,$41,$B3,$42,$00
_spr_lib7_38:
		.BYTE	$03,$F0,$E8,$B9,$01,$BB,$01,$BD,$01,$82,$F1,$DE,$A8,$03,$AA,$03
		.BYTE	$02,$F7,$F0,$BF,$01,$C0,$01,$02,$F8,$F8,$B3,$42,$B1,$42,$00
_spr_lib7_39:
		.BYTE	$82,$F0,$DE,$AC,$03,$AE,$03,$03,$F0,$E8,$B9,$01,$BB,$01,$BD,$01
		.BYTE	$02,$F7,$F0,$BF,$01,$C0,$01,$02,$F8,$F8,$B3,$42,$B1,$42,$00
_spr_lib7_3A:
		.BYTE	$82,$F0,$DE,$B0,$03,$B2,$03,$03,$F0,$E8,$B9,$01,$BB,$01,$BD,$01
		.BYTE	$02,$F7,$F0,$BF,$01,$C0,$01,$02,$F8,$F8,$B3,$42,$B1,$42,$00
_spr_lib7_3B:
		.BYTE	$82,$F0,$DA,$C2,$01,$C2,$01,$03,$F0,$E8,$B9,$01,$C4,$01,$C6,$01
		.BYTE	$02,$F7,$F0,$C8,$01,$CA,$01,$02,$F8,$F8,$B3,$42,$B1,$42,$00
_spr_lib7_3C:
		.BYTE	$82,$F0,$DA,$C2,$41,$C2,$41,$03,$F0,$E8,$B9,$01,$C4,$01,$C6,$01
		.BYTE	$02,$F7,$F0,$C8,$01,$CA,$01,$02,$F8,$F8,$B3,$42,$B1,$42,$00
_spr_lib7_3D:
		.BYTE	$82,$FC,$F0,$A8,$03,$AA,$03,$81,$F8,$F8,$B4,$03,$00
_spr_lib7_3E:
		.BYTE	$82,$FB,$F0,$AC,$03,$AE,$03,$81,$F8,$F8,$B4,$03,$00
_spr_lib7_3F:
		.BYTE	$82,$FB,$F0,$B0,$03,$B2,$03,$81,$F8,$F8,$B4,$03,$00
_spr_lib7_5C:
		.BYTE	$03,$F0,$E8,$B9,$01,$C4,$01,$C6,$01,$02,$F7,$F0,$C8,$01,$CA,$01
		.BYTE	$02,$F8,$F8,$B3,$42,$B1,$42,$00
_spr_lib9_00:
		.BYTE	$82,$E4,$D5,$E4,$02,$E8,$02,$82,$EC,$D5,$E6,$02,$EA,$02,$03,$EC
		.BYTE	$E8,$CC,$02,$CE,$02,$D0,$02,$03,$EC,$F0,$D6,$02,$D8,$02,$DA,$02
		.BYTE	$81,$F4,$D9,$EC,$02,$81,$FC,$D9,$EE,$02,$82,$04,$EC,$D2,$02,$DC
		.BYTE	$02,$82,$0C,$EC,$D4,$02,$DE,$02,$81,$EC,$F7,$C1,$02,$02,$F0,$04
		.BYTE	$F8,$02,$FA,$02,$02,$F0,$0C,$FC,$02,$FE,$02,$02,$F4,$F8,$C3,$02
		.BYTE	$C5,$02,$02,$00,$08,$F4,$02,$F6,$02,$00
_spr_lib9_01:
		.BYTE	$82,$E4,$D5,$E4,$02,$E8,$02,$82,$EC,$D5,$E6,$02,$EA,$02,$03,$EC
		.BYTE	$E8,$CC,$02,$CE,$02,$C7,$02,$03,$EC,$F0,$D6,$02,$D8,$02,$DA,$02
		.BYTE	$81,$F4,$D9,$F0,$02,$81,$FC,$D9,$F2,$02,$82,$04,$EC,$C9,$02,$CD
		.BYTE	$02,$82,$0C,$EC,$CB,$02,$CF,$02,$81,$EC,$F7,$C1,$02,$02,$F0,$04
		.BYTE	$F8,$02,$FA,$02,$02,$F0,$0C,$FC,$02,$FE,$02,$02,$F4,$F8,$C3,$02
		.BYTE	$D1,$02,$02,$00,$08,$EC,$02,$EE,$02,$00
_spr_lib9_02:
		.BYTE	$82,$E4,$D5,$E4,$02,$E8,$02,$82,$EC,$D5,$E6,$02,$EA,$02,$03,$EC
		.BYTE	$E8,$CC,$02,$CE,$02,$D3,$02,$03,$EC,$F0,$D6,$02,$D8,$02,$DA,$02
		.BYTE	$81,$F4,$D9,$F4,$02,$81,$FC,$D9,$F6,$02,$82,$04,$EC,$D5,$02,$D9
		.BYTE	$02,$82,$0C,$EC,$D7,$02,$DB,$02,$81,$EC,$F7,$C1,$02,$02,$F0,$04
		.BYTE	$F8,$02,$FA,$02,$02,$F0,$0C,$FC,$02,$FE,$02,$02,$F4,$F8,$C3,$02
		.BYTE	$DD,$02,$02,$00,$08,$F0,$02,$F2,$02,$00
_spr_lib9_03:
		.BYTE	$82,$E4,$D5,$E4,$02,$E8,$02,$82,$EC,$D5,$E6,$02,$EA,$02,$03,$EC
		.BYTE	$E8,$CC,$02,$CE,$02,$D0,$02,$03,$EC,$F0,$D6,$02,$DF,$02,$DA,$02
		.BYTE	$81,$F4,$D9,$EC,$02,$81,$FC,$D9,$EE,$02,$82,$04,$EC,$D2,$02,$DC
		.BYTE	$02,$82,$0C,$EC,$D4,$02,$DE,$02,$81,$EC,$F7,$E0,$02,$02,$F0,$04
		.BYTE	$F8,$02,$FA,$02,$02,$F0,$0C,$FC,$02,$FE,$02,$02,$F4,$F8,$E2,$02
		.BYTE	$C5,$02,$02,$00,$08,$F4,$02,$F6,$02,$00
_spr_lib9_04:
		.BYTE	$82,$E4,$D5,$E4,$02,$E8,$02,$82,$EC,$D5,$E6,$02,$EA,$02,$03,$EC
		.BYTE	$E8,$CC,$02,$CE,$02,$C7,$02,$03,$EC,$F0,$D6,$02,$DF,$02,$DA,$02
		.BYTE	$81,$F4,$D9,$F0,$02,$81,$FC,$D9,$F2,$02,$82,$04,$EC,$C9,$02,$CD
		.BYTE	$02,$82,$0C,$EC,$CB,$02,$CF,$02,$81,$EC,$F7,$E0,$02,$02,$F0,$04
		.BYTE	$F8,$02,$FA,$02,$02,$F0,$0C,$FC,$02,$FE,$02,$02,$F4,$F8,$E2,$02
		.BYTE	$D1,$02,$02,$00,$08,$EC,$02,$EE,$02,$00
_spr_lib9_05:
		.BYTE	$82,$E4,$D5,$E4,$02,$E8,$02,$82,$EC,$D5,$E6,$02,$EA,$02,$03,$EC
		.BYTE	$E8,$CC,$02,$CE,$02,$D3,$02,$03,$EC,$F0,$D6,$02,$DF,$02,$DA,$02
		.BYTE	$81,$F4,$D9,$F4,$02,$81,$FC,$D9,$F6,$02,$82,$04,$EC,$D5,$02,$D9
		.BYTE	$02,$82,$0C,$EC,$D7,$02,$DB,$02,$81,$EC,$F7,$E0,$02,$02,$F0,$04
		.BYTE	$F8,$02,$FA,$02,$02,$F0,$0C,$FC,$02,$FE,$02,$02,$F4,$F8,$E2,$02
		.BYTE	$DD,$02,$02,$00,$08,$F0,$02,$F2,$02,$00
_spr_lib3_03:
		.BYTE	$81,$F9,$F1,$8C,$00,$81,$FF,$F1,$8E,$00,$81,$F9,$F7,$8D,$00,$81
		.BYTE	$FF,$F7,$8F,$00,$00
_spr_lib3_04:
		.BYTE	$81,$F7,$EF,$8C,$00,$81,$01,$EF,$8E,$00,$81,$F7,$F9,$8D,$00,$81
		.BYTE	$01,$F9,$8F,$00,$00
_spr_lib3_05:
		.BYTE	$81,$F5,$ED,$8C,$00,$81,$03,$ED,$8E,$00,$81,$F5,$FB,$8D,$00,$81
		.BYTE	$03,$FB,$8F,$00,$00
_spr_lib3_06:
		.BYTE	$81,$F3,$EB,$8C,$00,$81,$05,$EB,$8E,$00,$81,$F3,$FD,$8D,$00,$81
		.BYTE	$05,$FD,$8F,$00,$00
_spr_lib3_07:
		.BYTE	$81,$F1,$E9,$8C,$00,$81,$07,$E9,$8E,$00,$81,$F1,$FF,$8D,$00,$81
		.BYTE	$07,$FF,$8F,$00,$00
_spr_lib0_17:
		.BYTE	$82,$F8,$F0,$A1,$03,$A5,$03,$82,$00,$F0,$A3,$03,$A7,$03,$81,$FE
		.BYTE	$F8,$A9,$00,$00
_spr_lib0_18:
		.BYTE	$82,$F8,$F0,$A1,$03,$A5,$03,$82,$00,$F0,$AB,$03,$A7,$03,$81,$FE
		.BYTE	$F8,$A9,$00,$00
_spr_lib5_0C:
		.BYTE	$82,$F8,$F0,$F9,$01,$FD,$01,$82,$00,$F0,$FB,$01,$FF,$01,$00
_spr_lib5_0D:
		.BYTE	$02,$F8,$F5,$F9,$01,$FB,$01,$02,$F8,$F8,$FD,$01,$FF,$01,$00
_spr_lib5_0E:
		.BYTE	$02,$F8,$F3,$F9,$01,$FB,$01,$02,$F8,$F8,$FD,$01,$FF,$01,$00
_spr_lib5_13:
		.BYTE	$04,$F0,$F0,$F2,$01,$F9,$01,$FB,$01,$F2,$41,$02,$F8,$F8,$FD,$01
		.BYTE	$FF,$01,$00
_spr_lib8_0F:
		.BYTE	$02,$EA,$CF,$8C,$03,$8D,$03,$82,$ED,$E2,$90,$00,$93,$00,$00
_spr_lib8_10:
		.BYTE	$02,$EA,$CF,$8C,$03,$8D,$03,$84,$EC,$DE,$95,$00,$A2,$00,$9C,$00
		.BYTE	$9D,$00,$82,$F4,$EE,$9E,$00,$9F,$00,$00
_spr_lib8_11:
		.BYTE	$82,$F8,$EF,$98,$02,$99,$02,$82,$00,$EF,$9A,$02,$9B,$02,$00
_spr_lib8_12:
		.BYTE	$82,$F8,$F1,$98,$02,$A4,$02,$82,$00,$F1,$9A,$02,$A6,$02,$00
_spr_lib8_13:
		.BYTE	$82,$F8,$F0,$8F,$C3,$8E,$C3,$82,$00,$F0,$8E,$03,$8F,$03,$00
_spr_lib8_15:
		.BYTE	$81,$F8,$C7,$A8,$02,$81,$00,$C9,$AA,$02,$81,$F2,$CF,$AC,$02,$81
		.BYTE	$FA,$CF,$AE,$02,$81,$F7,$D5,$B6,$01,$84,$F0,$D7,$B0,$02,$BE,$02
		.BYTE	$A5,$01,$AD,$01,$85,$F8,$D7,$B2,$02,$A1,$02,$A7,$02,$AF,$01,$B9
		.BYTE	$03,$85,$00,$D7,$B4,$02,$A3,$02,$A9,$02,$B1,$01,$BB,$03,$81,$E8
		.BYTE	$DC,$BC,$01,$81,$F0,$DD,$B8,$01,$81,$FD,$DD,$BA,$01,$81,$FC,$E7
		.BYTE	$AB,$03,$81,$F6,$F7,$B3,$00,$00
_spr_lib8_16:
		.BYTE	$81,$F8,$C7,$A8,$02,$81,$00,$C9,$AA,$02,$81,$F2,$CF,$AC,$02,$81
		.BYTE	$FA,$CF,$AE,$02,$81,$F7,$D5,$B6,$01,$84,$F0,$D7,$B0,$02,$BE,$02
		.BYTE	$A5,$01,$AD,$01,$85,$F8,$D7,$CA,$02,$A1,$02,$A7,$02,$AF,$01,$B9
		.BYTE	$03,$85,$00,$D7,$B4,$02,$A3,$02,$A9,$02,$B1,$01,$BB,$03,$81,$E8
		.BYTE	$DC,$BC,$01,$81,$F0,$DD,$B8,$01,$81,$FD,$DD,$BA,$01,$81,$FC,$E7
		.BYTE	$AB,$03,$81,$F6,$F7,$B3,$00,$00
_spr_lib8_17:
		.BYTE	$81,$F8,$C7,$A8,$02,$81,$00,$C9,$AA,$02,$81,$F2,$CF,$AC,$02,$81
		.BYTE	$FA,$CF,$AE,$02,$81,$F7,$D5,$B6,$01,$84,$F0,$D7,$B0,$02,$BE,$02
		.BYTE	$A5,$01,$AD,$01,$85,$F8,$D7,$D6,$02,$CF,$02,$A7,$02,$AF,$01,$B9
		.BYTE	$03,$85,$00,$D7,$B4,$02,$A3,$02,$A9,$02,$B1,$01,$BB,$03,$81,$E8
		.BYTE	$DC,$BC,$01,$81,$F0,$DD,$B8,$01,$81,$FD,$DD,$BA,$01,$81,$FC,$E7
		.BYTE	$AB,$03,$81,$F6,$F7,$B3,$00,$00
_spr_lib8_18:
		.BYTE	$81,$F8,$C7,$A8,$02,$81,$00,$C9,$AA,$02,$81,$F2,$CF,$AC,$02,$81
		.BYTE	$FA,$CF,$AE,$02,$81,$F7,$D5,$B6,$01,$84,$F0,$D7,$B0,$02,$BE,$02
		.BYTE	$A5,$01,$AD,$01,$85,$F8,$D7,$B2,$02,$A1,$02,$A7,$02,$AF,$01,$B5
		.BYTE	$03,$85,$00,$D7,$B4,$02,$A3,$02,$A9,$02,$B1,$01,$B7,$03,$81,$E8
		.BYTE	$DC,$BC,$01,$81,$F0,$DD,$B8,$01,$81,$FD,$DD,$BA,$01,$81,$FC,$E7
		.BYTE	$AB,$03,$81,$F6,$F7,$B3,$00,$00
_spr_lib8_19:
		.BYTE	$81,$F3,$C7,$BD,$02,$81,$FE,$C7,$BF,$02,$81,$F2,$CC,$AC,$02,$81
		.BYTE	$FA,$CC,$AE,$02,$81,$F7,$D2,$B6,$01,$82,$F0,$D4,$B0,$02,$BE,$02
		.BYTE	$83,$F8,$D4,$B2,$02,$A1,$02,$A7,$02,$83,$00,$D4,$B4,$02,$A3,$02
		.BYTE	$A9,$02,$81,$E8,$D9,$BC,$01,$81,$F0,$DA,$B8,$01,$81,$FD,$DA,$BA
		.BYTE	$01,$82,$F0,$E5,$C0,$01,$C2,$01,$81,$FC,$E7,$C4,$03,$82,$F8,$EF
		.BYTE	$AF,$01,$B9,$03,$82,$00,$EF,$B1,$01,$BB,$03,$81,$F6,$F7,$B3,$00
		.BYTE	$00
_spr_lib8_1A:
		.BYTE	$81,$F3,$C4,$BD,$02,$81,$FE,$C4,$BF,$02,$81,$F2,$C9,$AC,$02,$81
		.BYTE	$FA,$C9,$AE,$02,$81,$00,$CF,$B6,$01,$82,$F0,$D1,$B0,$02,$BE,$02
		.BYTE	$83,$F8,$D1,$CA,$02,$A1,$02,$A7,$02,$83,$00,$D1,$B4,$02,$A3,$02
		.BYTE	$A9,$02,$81,$E8,$D6,$BC,$01,$84,$F0,$D7,$B8,$01,$CC,$01,$CE,$01
		.BYTE	$D0,$01,$81,$FD,$D7,$BA,$01,$82,$FC,$DF,$D2,$03,$D4,$03,$82,$F8
		.BYTE	$EF,$AF,$01,$B9,$03,$82,$00,$EF,$B1,$01,$BB,$03,$81,$F6,$F7,$B3
		.BYTE	$00,$00
_spr_lib8_1B:
		.BYTE	$81,$F1,$BB,$BD,$02,$81,$FC,$BB,$BF,$02,$81,$F0,$C0,$AC,$02,$81
		.BYTE	$F8,$C0,$AE,$02,$81,$F5,$C6,$B6,$01,$82,$EE,$C8,$B0,$02,$BE,$02
		.BYTE	$81,$F6,$C8,$D6,$02,$81,$FE,$C8,$B4,$02,$81,$E6,$CD,$BC,$01,$81
		.BYTE	$EE,$CE,$B8,$01,$81,$FB,$CE,$BA,$01,$81,$F6,$CF,$D8,$02,$81,$FE
		.BYTE	$CF,$DA,$02,$84,$F1,$D6,$C5,$01,$C7,$01,$C9,$01,$CB,$01,$82,$F8
		.BYTE	$D7,$DC,$02,$C1,$02,$82,$00,$D7,$DE,$02,$C3,$02,$82,$FC,$DF,$D2
		.BYTE	$03,$D4,$03,$82,$F8,$EF,$AF,$01,$B9,$03,$82,$00,$EF,$B1,$01,$BB
		.BYTE	$03,$81,$F6,$F7,$B3,$00,$00
_spr_lib8_1C:
		.BYTE	$81,$F8,$C1,$A8,$02,$81,$00,$C3,$AA,$02,$81,$F2,$C9,$AC,$02,$81
		.BYTE	$FA,$C9,$AE,$02,$81,$F7,$CF,$B6,$01,$82,$F0,$D1,$B0,$02,$BE,$02
		.BYTE	$83,$F8,$D1,$D6,$02,$CF,$02,$A7,$02,$83,$00,$D1,$B4,$02,$A3,$02
		.BYTE	$A9,$02,$81,$E8,$D6,$BC,$01,$81,$E0,$D7,$CD,$01,$84,$F0,$D7,$B8
		.BYTE	$01,$CC,$01,$CE,$01,$D0,$01,$81,$FD,$D7,$BA,$01,$82,$FC,$DF,$D2
		.BYTE	$03,$D4,$03,$82,$F8,$EF,$AF,$01,$B9,$03,$82,$00,$EF,$B1,$01,$BB
		.BYTE	$03,$81,$F6,$F7,$B3,$00,$00
_spr_lib8_1D:
		.BYTE	$81,$F8,$C4,$A8,$02,$81,$00,$C6,$AA,$02,$81,$F2,$CC,$AC,$02,$81
		.BYTE	$FA,$CC,$AE,$02,$81,$F7,$D2,$B6,$01,$82,$F0,$D4,$B0,$02,$BE,$02
		.BYTE	$83,$F8,$D4,$D6,$02,$CF,$02,$A7,$02,$83,$00,$D4,$B4,$02,$A3,$02
		.BYTE	$A9,$02,$81,$DE,$D8,$D1,$01,$81,$E8,$D9,$BC,$01,$81,$F0,$DA,$B8
		.BYTE	$01,$81,$FD,$DA,$BA,$01,$82,$F0,$E5,$C0,$01,$C2,$01,$81,$FC,$E7
		.BYTE	$C4,$03,$82,$F8,$EF,$AF,$01,$B9,$03,$82,$00,$EF,$B1,$01,$BB,$03
		.BYTE	$81,$F6,$F7,$B3,$00,$00
_spr_lib8_1E:
		.BYTE	$81,$F3,$CB,$BD,$02,$81,$FE,$CB,$BF,$02,$81,$F2,$D0,$AC,$02,$81
		.BYTE	$FA,$D0,$AE,$02,$81,$F7,$D6,$B6,$01,$84,$F0,$D8,$B0,$02,$BE,$02
		.BYTE	$A5,$01,$AD,$01,$83,$F8,$D8,$CA,$02,$A1,$02,$A7,$02,$83,$00,$D8
		.BYTE	$B4,$02,$A3,$02,$A9,$02,$81,$E8,$DD,$BC,$01,$81,$F0,$DE,$B8,$01
		.BYTE	$81,$FD,$DE,$BA,$01,$81,$FC,$E7,$D3,$03,$82,$F8,$EF,$AF,$01,$B9
		.BYTE	$03,$82,$00,$EF,$B1,$01,$BB,$03,$81,$F6,$F7,$B3,$00,$00
_spr_lib8_20:
		.BYTE	$81,$F3,$C7,$BD,$02,$81,$FE,$C7,$BF,$02,$81,$F2,$CC,$AC,$02,$81
		.BYTE	$FA,$CC,$AE,$02,$81,$F7,$D2,$B6,$01,$82,$F0,$D4,$B0,$02,$BE,$02
		.BYTE	$83,$F8,$D4,$B2,$02,$A1,$02,$A7,$02,$83,$00,$D4,$B4,$02,$A3,$02
		.BYTE	$A9,$02,$81,$E8,$D9,$BC,$01,$81,$F0,$DA,$B8,$01,$81,$FD,$DA,$BA
		.BYTE	$01,$82,$F0,$E5,$C0,$01,$C2,$01,$81,$FC,$E7,$C4,$03,$82,$F8,$EF
		.BYTE	$AF,$01,$C6,$03,$82,$00,$EF,$B1,$01,$C8,$03,$81,$F6,$F7,$B3,$00
		.BYTE	$00
_spr_lib8_21:
		.BYTE	$02,$F8,$F8,$D5,$01,$D7,$01,$00
_spr_lib8_22:
		.BYTE	$02,$F8,$F7,$D9,$01,$DB,$01,$00
_spr_lib8_23:
		.BYTE	$81,$00,$C4,$A8,$02,$81,$08,$C6,$AA,$02,$81,$FA,$CC,$AC,$02,$81
		.BYTE	$02,$CC,$AE,$02,$81,$FF,$D2,$B6,$01,$82,$F8,$D4,$B0,$02,$BE,$02
		.BYTE	$83,$00,$D4,$CA,$02,$A1,$02,$A7,$02,$83,$08,$D4,$B4,$02,$A3,$02
		.BYTE	$A9,$02,$81,$F0,$D9,$BC,$01,$81,$F8,$DA,$B8,$01,$81,$05,$DA,$BA
		.BYTE	$01,$82,$F8,$E5,$C0,$01,$C2,$01,$81,$04,$E7,$C4,$03,$83,$00,$EF
		.BYTE	$AF,$01,$DD,$03,$E0,$03,$83,$08,$EF,$B1,$01,$DF,$03,$E2,$03,$81
		.BYTE	$FE,$F7,$B3,$00,$81,$00,$F7,$DD,$03,$00
_spr_lib7_4D:
		.BYTE	$85,$F8,$D8,$A8,$01,$AE,$01,$B4,$01,$A3,$01,$A9,$01,$85,$00,$D8
		.BYTE	$AA,$02,$B3,$03,$B6,$02,$A5,$01,$AB,$01,$81,$08,$DC,$AC,$03,$82
		.BYTE	$00,$E0,$B0,$02,$AF,$01,$84,$08,$E0,$B2,$02,$B8,$02,$A7,$01,$AD
		.BYTE	$01,$81,$08,$E8,$B1,$01,$81,$F1,$ED,$A1,$02,$00
_spr_lib7_4E:
		.BYTE	$04,$F0,$E8,$A1,$02,$C6,$02,$C8,$02,$CA,$02,$81,$0E,$D1,$B5,$02
		.BYTE	$81,$08,$D3,$AC,$03,$81,$00,$D7,$B3,$03,$82,$00,$D8,$B9,$02,$C0
		.BYTE	$02,$82,$08,$D8,$BB,$02,$C2,$02,$81,$08,$D8,$CC,$01,$81,$0F,$D8
		.BYTE	$BD,$03,$82,$F8,$DB,$B7,$03,$BF,$03,$03,$F8,$F0,$A3,$01,$A5,$01
		.BYTE	$A7,$01,$03,$F8,$F8,$A9,$01,$AB,$01,$AD,$01,$02,$FE,$E8,$CE,$01
		.BYTE	$D0,$01,$81,$10,$E0,$C4,$03,$00
_spr_lib7_4F:
		.BYTE	$85,$00,$D8,$D2,$02,$D6,$02,$C8,$02,$DE,$01,$AB,$01,$85,$08,$D8
		.BYTE	$D4,$02,$C3,$00,$DC,$02,$C1,$01,$AD,$01,$03,$F0,$E8,$A1,$02,$C6
		.BYTE	$02,$DA,$01,$82,$08,$D8,$CC,$01,$D8,$02,$82,$F8,$DB,$B7,$03,$BF
		.BYTE	$03,$81,$08,$E0,$C3,$00,$81,$FE,$E8,$CE,$01,$81,$08,$E9,$C5,$03
		.BYTE	$82,$F8,$F0,$A3,$01,$A9,$01,$81,$02,$F0,$C7,$02,$00
_spr_lib7_50:
		.BYTE	$03,$F4,$F8,$BA,$03,$BC,$03,$BE,$03,$00
_spr_lib7_51:
		.BYTE	$81,$FC,$F8,$BC,$03,$81,$04,$F8,$BE,$03,$81,$F4,$FB,$BA,$83,$00
_spr_lib7_52:
		.BYTE	$02,$F0,$DB,$B0,$02,$B2,$02,$03,$F0,$E8,$B4,$01,$B6,$01,$B8,$01
		.BYTE	$81,$F2,$E0,$A8,$01,$81,$FA,$E0,$AA,$01,$81,$FF,$E0,$AC,$03,$81
		.BYTE	$F1,$E7,$AE,$02,$03,$F1,$F0,$BC,$01,$BE,$01,$A1,$01,$81,$F7,$E7
		.BYTE	$BA,$03,$81,$06,$F4,$A9,$02,$81,$08,$F4,$A7,$01,$81,$F9,$F8,$A5
		.BYTE	$02,$81,$FA,$F8,$A3,$01,$00
_spr_lib7_53:
		.BYTE	$02,$F0,$DA,$B0,$02,$B2,$02,$03,$F0,$E7,$B4,$01,$B6,$01,$B8,$01
		.BYTE	$81,$F2,$DF,$A8,$01,$81,$FA,$DF,$AA,$01,$81,$FF,$E1,$AB,$03,$81
		.BYTE	$F1,$E6,$AE,$02,$03,$F1,$EF,$BC,$01,$AD,$01,$AF,$01,$81,$F7,$E6
		.BYTE	$BA,$03,$02,$F8,$F7,$B1,$01,$B3,$01,$81,$FC,$F8,$A5,$02,$81,$FE
		.BYTE	$F8,$A5,$02,$00
_spr_lib7_54:
		.BYTE	$02,$F0,$DB,$B0,$02,$B2,$02,$03,$F0,$E8,$B4,$01,$B6,$01,$B8,$01
		.BYTE	$81,$F2,$E0,$A8,$01,$81,$FA,$E0,$AA,$01,$81,$FF,$E0,$AC,$03,$81
		.BYTE	$F1,$E7,$AE,$02,$03,$F1,$F0,$BC,$01,$B5,$01,$B7,$01,$81,$F7,$E7
		.BYTE	$BA,$03,$81,$07,$F4,$A9,$02,$81,$09,$F4,$A7,$01,$81,$F8,$F8,$A5
		.BYTE	$02,$81,$F9,$F8,$A3,$01,$00
_spr_lib7_55:
		.BYTE	$02,$F0,$E7,$B0,$02,$B2,$02,$81,$FE,$EA,$C6,$03,$81,$F2,$EC,$A8
		.BYTE	$01,$81,$FA,$EC,$AA,$01,$82,$F8,$EF,$B9,$01,$C0,$01,$82,$00,$EF
		.BYTE	$BB,$01,$CA,$02,$82,$08,$EF,$BD,$01,$C4,$01,$81,$08,$EF,$C8,$02
		.BYTE	$81,$10,$F0,$DF,$01,$81,$F1,$F3,$AE,$02,$81,$F7,$F3,$BA,$03,$81
		.BYTE	$F0,$F5,$BF,$01,$81,$00,$F7,$C2,$01,$00
_spr_lib7_56:
		.BYTE	$02,$F0,$DA,$B0,$02,$B2,$02,$03,$F0,$E7,$D0,$01,$B6,$01,$B8,$01
		.BYTE	$81,$F2,$DF,$CC,$01,$81,$FA,$DF,$AA,$01,$81,$FF,$E1,$AB,$03,$81
		.BYTE	$F1,$E6,$CE,$02,$03,$F1,$EF,$BC,$01,$AD,$01,$AF,$01,$81,$F7,$E6
		.BYTE	$BA,$03,$02,$F8,$F7,$B1,$01,$B3,$01,$81,$FC,$F8,$A5,$02,$81,$FE
		.BYTE	$F8,$A5,$02,$00
_spr_lib8_24:
		.BYTE	$82,$E7,$D0,$A8,$03,$AE,$02,$82,$EF,$D0,$AA,$03,$B0,$02,$81,$EE
		.BYTE	$D4,$B4,$01,$81,$DF,$D7,$AC,$02,$03,$F1,$E7,$BC,$03,$BE,$03,$A1
		.BYTE	$03,$03,$F2,$EF,$A5,$02,$A7,$02,$A9,$02,$02,$F5,$DF,$B6,$02,$BA
		.BYTE	$03,$81,$F7,$D7,$B2,$03,$81,$F5,$DF,$B8,$03,$81,$F7,$E6,$A3,$01
		.BYTE	$03,$F7,$F7,$AB,$02,$AD,$02,$AF,$02,$00
_spr_lib8_25:
		.BYTE	$82,$E7,$CF,$A8,$03,$AE,$02,$82,$EF,$CF,$AA,$03,$B0,$02,$81,$EE
		.BYTE	$D3,$B4,$01,$81,$DF,$D6,$AC,$02,$04,$EF,$EE,$BB,$02,$BD,$02,$BF
		.BYTE	$02,$C0,$02,$03,$F0,$E6,$B5,$02,$B7,$03,$B9,$03,$04,$F3,$F6,$C2
		.BYTE	$02,$C4,$02,$C6,$02,$C8,$02,$03,$F5,$DE,$B8,$03,$B1,$03,$B3,$02
		.BYTE	$81,$F7,$D6,$B2,$03,$81,$F5,$DE,$B6,$02,$81,$F7,$E5,$A3,$01,$81
		.BYTE	$03,$FE,$CA,$02,$00
_spr_lib8_26:
		.BYTE	$82,$E7,$CE,$A8,$03,$AE,$02,$82,$EF,$CE,$AA,$03,$B0,$02,$81,$EE
		.BYTE	$D2,$B4,$01,$81,$DF,$D5,$AC,$02,$03,$F1,$E5,$BC,$03,$BE,$03,$A1
		.BYTE	$03,$03,$F2,$ED,$A5,$02,$A7,$02,$A9,$02,$02,$F5,$DD,$B6,$02,$BA
		.BYTE	$03,$81,$F7,$D5,$B2,$03,$81,$F5,$DD,$B8,$03,$81,$F7,$E4,$A3,$01
		.BYTE	$03,$F7,$F5,$CC,$02,$CE,$02,$AF,$02,$02,$F7,$FD,$D0,$02,$D2,$02
		.BYTE	$00
_spr_lib8_27:
		.BYTE	$82,$E7,$CF,$A8,$03,$AE,$02,$82,$EF,$CF,$AA,$03,$B0,$02,$81,$EE
		.BYTE	$D3,$B4,$01,$81,$DF,$D6,$AC,$02,$05,$E7,$E6,$D8,$02,$DA,$02,$DC
		.BYTE	$03,$DE,$03,$C1,$02,$81,$F7,$D6,$B2,$03,$81,$F5,$DE,$B6,$02,$81
		.BYTE	$F5,$DE,$B8,$03,$81,$FD,$DE,$D4,$03,$81,$05,$DE,$D6,$02,$81,$F7
		.BYTE	$E5,$A3,$01,$81,$0E,$E9,$C3,$02,$81,$EF,$EE,$C5,$02,$03,$F6,$EE
		.BYTE	$C7,$02,$C9,$03,$CB,$02,$03,$F7,$F6,$CD,$02,$CF,$02,$D1,$02,$81
		.BYTE	$FF,$FE,$D3,$02,$00
_spr_lib8_28:
		.BYTE	$81,$E6,$CD,$DB,$02,$81,$E9,$CF,$DF,$02,$81,$F1,$CF,$E0,$03,$81
		.BYTE	$E1,$D2,$DD,$02,$03,$E7,$D7,$E2,$02,$E4,$02,$E6,$03,$03,$ED,$DF
		.BYTE	$E8,$02,$EA,$03,$EC,$03,$81,$F1,$D2,$D9,$01,$03,$F2,$EF,$F2,$02
		.BYTE	$F4,$02,$F6,$02,$03,$F7,$F7,$AB,$02,$F8,$02,$AF,$02,$02,$F8,$E7
		.BYTE	$EE,$03,$F0,$03,$81,$F9,$E8,$A3,$01,$00
_spr_lib8_29:
		.BYTE	$02,$D7,$D7,$FB,$02,$FD,$03,$82,$E7,$D9,$FC,$03,$E3,$02,$82,$EF
		.BYTE	$DD,$E5,$03,$EB,$03,$02,$D8,$DF,$FE,$02,$E1,$02,$03,$F2,$EF,$F3
		.BYTE	$02,$F4,$02,$F6,$02,$82,$F7,$DF,$E7,$03,$ED,$03,$03,$F7,$F7,$AB
		.BYTE	$02,$F8,$02,$AF,$02,$82,$FF,$DF,$E9,$02,$EF,$03,$81,$07,$E7,$F1
		.BYTE	$02,$00
_spr_lib8_2A:
		.BYTE	$02,$F8,$F8,$D5,$00,$D7,$00,$00
_spr_lib8_2B:
		.BYTE	$02,$F8,$F8,$D5,$80,$D7,$80,$00
_spr_lib8_2C:
		.BYTE	$04,$EC,$CF,$94,$02,$96,$02,$98,$00,$9A,$01,$04,$EC,$D7,$91,$01
		.BYTE	$93,$00,$95,$00,$97,$01,$02,$EE,$C7,$90,$02,$92,$02,$81,$F4,$C7
		.BYTE	$9E,$01,$81,$0C,$D3,$9C,$01,$81,$F0,$DF,$99,$01,$84,$F4,$DF,$9B
		.BYTE	$00,$F9,$03,$FD,$03,$EA,$83,$84,$FC,$DF,$9D,$02,$FB,$03,$FF,$03
		.BYTE	$EC,$83,$84,$04,$DF,$9F,$02,$E8,$02,$F4,$03,$EE,$83,$81,$FC,$E7
		.BYTE	$E6,$02,$81,$04,$E7,$EE,$03,$81,$F9,$EA,$E4,$02,$00
_spr_lib8_2D:
		.BYTE	$04,$EC,$CF,$94,$02,$96,$02,$98,$00,$9A,$01,$04,$EC,$D7,$91,$01
		.BYTE	$93,$00,$95,$00,$97,$01,$02,$EE,$C7,$90,$02,$92,$02,$81,$F4,$C7
		.BYTE	$9E,$01,$81,$0C,$D3,$9C,$01,$81,$F0,$DF,$99,$01,$84,$F4,$DF,$9B
		.BYTE	$00,$E5,$03,$EB,$03,$E5,$83,$84,$FC,$DF,$FA,$02,$E7,$03,$F2,$03
		.BYTE	$E7,$83,$84,$04,$DF,$FC,$02,$E9,$03,$ED,$03,$E9,$83,$81,$01,$E7
		.BYTE	$FE,$02,$82,$00,$EF,$E1,$02,$E3,$02,$00
_spr_lib8_2E:
		.BYTE	$04,$EC,$CF,$94,$02,$96,$02,$98,$00,$9A,$01,$04,$EC,$D7,$91,$01
		.BYTE	$93,$00,$95,$00,$97,$01,$02,$EE,$C7,$90,$02,$92,$02,$81,$F4,$C7
		.BYTE	$9E,$01,$81,$0C,$D3,$9C,$01,$81,$F0,$DF,$99,$01,$84,$F4,$DF,$9B
		.BYTE	$00,$EA,$03,$F0,$03,$EA,$83,$84,$FC,$DF,$EF,$02,$EC,$03,$F2,$03
		.BYTE	$EC,$83,$84,$04,$DF,$F1,$02,$EE,$03,$F4,$03,$EE,$83,$02,$FC,$E7
		.BYTE	$F3,$02,$F5,$02,$81,$03,$EF,$F7,$02,$00
_spr_lib8_2F:
		.BYTE	$04,$EC,$CF,$A4,$02,$A6,$02,$98,$00,$9A,$01,$04,$EC,$D7,$91,$01
		.BYTE	$93,$00,$95,$00,$97,$01,$02,$EE,$C7,$90,$02,$92,$02,$81,$F4,$C7
		.BYTE	$9E,$01,$81,$0C,$D3,$9C,$01,$81,$F0,$DF,$99,$01,$84,$F4,$DF,$9B
		.BYTE	$00,$E5,$03,$EB,$03,$E5,$83,$84,$FC,$DF,$9D,$02,$E7,$03,$F2,$03
		.BYTE	$E7,$83,$84,$04,$DF,$9F,$02,$E9,$03,$ED,$03,$E9,$83,$81,$FC,$E7
		.BYTE	$E6,$02,$81,$04,$E7,$E8,$02,$81,$F9,$EA,$E4,$02,$00
_spr_lib8_30:
		.BYTE	$04,$EC,$CF,$94,$02,$96,$02,$98,$00,$9A,$01,$04,$EC,$D7,$91,$01
		.BYTE	$93,$00,$95,$00,$97,$01,$02,$EE,$C7,$90,$02,$92,$02,$81,$F4,$C7
		.BYTE	$9E,$01,$81,$0C,$D3,$9C,$01,$81,$F0,$DF,$99,$01,$84,$F4,$DF,$9B
		.BYTE	$00,$EA,$03,$F0,$03,$EA,$83,$84,$FC,$DF,$FA,$02,$EC,$03,$F2,$03
		.BYTE	$EC,$83,$84,$04,$DF,$FC,$02,$EE,$03,$F4,$03,$EE,$83,$81,$01,$E7
		.BYTE	$FE,$02,$82,$00,$EF,$E1,$02,$E3,$02,$00
_spr_lib8_31:
		.BYTE	$04,$EC,$CF,$94,$02,$96,$02,$98,$00,$9A,$01,$04,$EC,$D7,$91,$01
		.BYTE	$93,$00,$95,$00,$97,$01,$02,$EE,$C7,$A0,$02,$A2,$02,$81,$0C,$D3
		.BYTE	$9C,$01,$81,$F0,$DF,$99,$01,$84,$F4,$DF,$9B,$00,$E5,$03,$EB,$03
		.BYTE	$E5,$83,$84,$FC,$DF,$EF,$02,$E7,$03,$F2,$03,$E7,$83,$84,$04,$DF
		.BYTE	$F1,$02,$E9,$03,$ED,$03,$E9,$83,$02,$FC,$E7,$F3,$02,$F5,$02,$81
		.BYTE	$03,$EF,$F7,$02,$00
_spr_lib8_32:
		.BYTE	$82,$F8,$F0,$F6,$01,$F6,$81,$82,$00,$F0,$F6,$41,$F6,$C1,$00
_spr_lib8_33:
		.BYTE	$82,$F8,$F0,$F8,$01,$F8,$81,$82,$00,$F0,$F8,$41,$F8,$C1,$00
_spr_lib4_03:
		.BYTE	$02,$F8,$F1,$EA,$80,$84,$80,$02,$F8,$F8,$EA,$00,$84,$00,$81,$FD
		.BYTE	$F4,$E8,$01,$00
_spr_lib4_04:
		.BYTE	$82,$F8,$F0,$86,$00,$E6,$00,$82,$00,$F0,$86,$40,$E6,$40,$81,$FA
		.BYTE	$F8,$E8,$01,$00
_spr_lib7_5A:
		.BYTE	$03,$F4,$F0,$E1,$02,$E3,$02,$E5,$02,$03,$F4,$F8,$E7,$02,$E9,$02
		.BYTE	$EB,$02,$81,$FC,$F2,$ED,$01,$00
_spr_lib7_5B:
		.BYTE	$03,$F4,$F0,$EB,$C2,$E9,$C2,$E7,$C2,$03,$F4,$F8,$E5,$C2,$E3,$C2
		.BYTE	$E1,$C2,$81,$FC,$F2,$ED,$01,$00
_spr_lib5_14:
		.BYTE	$02,$F8,$F8,$EF,$00,$F1,$00,$81,$FC,$F3,$F3,$00,$00
_spr_lib5_15:
		.BYTE	$02,$F8,$F8,$EF,$00,$F1,$00,$81,$FC,$F3,$F7,$00,$00
_spr_lib5_16:
		.BYTE	$02,$F8,$F8,$EF,$00,$F1,$00,$81,$FC,$F3,$F5,$00,$00
_spr_lib7_5E:
		.BYTE	$84,$E8,$DF,$A8,$01,$A9,$01,$B4,$01,$B5,$01,$84,$F0,$DF,$AA,$01
		.BYTE	$AB,$01,$B6,$01,$A1,$01,$84,$F8,$DF,$AC,$01,$AD,$01,$B8,$01,$A3
		.BYTE	$01,$84,$00,$DF,$AE,$01,$AF,$01,$A5,$01,$BB,$01,$81,$08,$E3,$B0
		.BYTE	$01,$83,$08,$E7,$B1,$01,$A7,$01,$BD,$01,$81,$01,$F1,$B2,$00,$81
		.BYTE	$EF,$F8,$B9,$00,$81,$F9,$F8,$B9,$00,$00
_spr_lib7_5F:
		.BYTE	$84,$E8,$DF,$A8,$01,$A9,$01,$B4,$01,$B5,$01,$84,$F0,$DF,$AA,$01
		.BYTE	$AB,$01,$B6,$01,$B9,$00,$84,$F8,$DF,$AC,$01,$AD,$01,$B8,$01,$A3
		.BYTE	$01,$84,$00,$DF,$AE,$01,$AF,$01,$A5,$01,$BB,$01,$81,$08,$E3,$B0
		.BYTE	$01,$83,$08,$E7,$B1,$01,$A7,$01,$BD,$01,$81,$07,$F0,$B7,$00,$81
		.BYTE	$F0,$F7,$A1,$01,$81,$FA,$F7,$B9,$00,$00
_spr_lib7_60:
		.BYTE	$05,$E8,$E7,$A8,$01,$AA,$01,$C0,$01,$C2,$01,$C4,$01,$05,$E8,$EF
		.BYTE	$A9,$01,$AB,$01,$C1,$01,$C3,$01,$A7,$01,$05,$E8,$F7,$C5,$01,$C7
		.BYTE	$01,$C9,$01,$CB,$01,$BD,$01,$81,$0B,$E7,$B0,$01,$81,$01,$F1,$B2
		.BYTE	$00,$81,$FA,$F8,$B9,$00,$00
_spr_lib7_63:
		.BYTE	$05,$E8,$E7,$CA,$01,$CC,$01,$CE,$01,$D0,$01,$B1,$01,$05,$E8,$EF
		.BYTE	$A9,$01,$AB,$01,$C1,$01,$C8,$01,$A7,$01,$05,$E8,$F7,$C5,$01,$C7
		.BYTE	$01,$C9,$01,$CB,$01,$BD,$01,$81,$08,$E4,$B0,$01,$81,$07,$F0,$B7
		.BYTE	$00,$81,$FB,$F7,$B9,$00,$00
_spr_lib7_62:
		.BYTE	$05,$E8,$E7,$CA,$01,$CC,$01,$CE,$01,$D0,$01,$B1,$01,$05,$E8,$EF
		.BYTE	$CD,$01,$CF,$01,$D1,$01,$C3,$01,$A7,$01,$05,$E8,$F7,$BF,$01,$BE
		.BYTE	$01,$C6,$01,$CB,$01,$BD,$01,$81,$08,$E3,$B0,$01,$81,$01,$F1,$B2
		.BYTE	$00,$81,$FA,$F8,$B9,$00,$00
_spr_lib7_61:
		.BYTE	$05,$E8,$E7,$CA,$01,$CC,$01,$CE,$01,$D0,$01,$B1,$01,$05,$E8,$EF
		.BYTE	$CD,$01,$CF,$01,$D1,$01,$C8,$01,$A7,$01,$05,$E8,$F7,$BF,$01,$BE
		.BYTE	$01,$C6,$01,$CB,$01,$BD,$01,$81,$08,$E4,$B0,$01,$81,$07,$F0,$B7
		.BYTE	$00,$81,$FB,$F7,$B9,$00,$00
_spr_lib7_41:
		.BYTE	$05,$E8,$E7,$CA,$01,$CC,$01,$CE,$01,$D0,$01,$B1,$01,$05,$E8,$EF
		.BYTE	$CD,$01,$CF,$01,$D1,$01,$C3,$01,$A7,$01,$05,$E8,$F7,$BF,$01,$BE
		.BYTE	$01,$C6,$01,$CB,$01,$BD,$01,$81,$02,$E3,$B0,$41,$81,$01,$F1,$B2
		.BYTE	$00,$81,$FA,$F8,$B9,$00,$00
_spr_lib7_42:
		.BYTE	$05,$E8,$E7,$A8,$01,$AA,$01,$C0,$01,$C2,$01,$C4,$01,$05,$E8,$EF
		.BYTE	$A9,$01,$AB,$01,$C1,$01,$C8,$01,$A7,$01,$05,$E8,$F7,$C5,$01,$C7
		.BYTE	$01,$C9,$01,$CB,$01,$BD,$01,$81,$0B,$E7,$B0,$01,$81,$07,$F0,$B7
		.BYTE	$00,$81,$FB,$F7,$B9,$00,$00
_spr_lib7_64:
		.BYTE	$04,$F0,$F8,$A8,$01,$A1,$00,$A3,$00,$A5,$00,$81,$FE,$F0,$A9,$03
		.BYTE	$81,$00,$F0,$A7,$00,$81,$06,$F0,$AB,$03,$81,$00,$F3,$BB,$01,$81
		.BYTE	$F8,$F8,$AA,$01,$81,$08,$F8,$AF,$02,$00
_spr_lib7_65:
		.BYTE	$04,$EB,$F0,$A8,$01,$A1,$00,$A3,$00,$A5,$00,$81,$F9,$E8,$A9,$03
		.BYTE	$81,$FB,$E8,$A7,$00,$81,$01,$E8,$AB,$03,$81,$FB,$EB,$BB,$01,$82
		.BYTE	$F3,$F0,$AA,$01,$AC,$02,$82,$03,$F0,$AF,$02,$AD,$02,$81,$FB,$F8
		.BYTE	$AE,$02,$00
_spr_lib7_66:
		.BYTE	$83,$00,$E8,$B0,$00,$BA,$02,$F8,$02,$83,$08,$E8,$B2,$00,$B9,$03
		.BYTE	$FA,$02,$82,$08,$E8,$B8,$03,$B3,$00,$82,$1A,$EA,$B6,$01,$B7,$01
		.BYTE	$81,$10,$EF,$B4,$00,$81,$00,$F0,$B1,$00,$81,$12,$F2,$B5,$01,$81
		.BYTE	$F8,$F8,$F7,$02,$00
_spr_lib7_67:
		.BYTE	$05,$DE,$F0,$C0,$01,$C2,$01,$A1,$00,$BC,$00,$A5,$00,$05,$DE,$F8
		.BYTE	$C1,$01,$C3,$01,$BF,$02,$AE,$02,$AD,$02,$81,$F4,$E8,$A9,$03,$81
		.BYTE	$F6,$E8,$A7,$00,$81,$FC,$E8,$AB,$03,$81,$F6,$EB,$BB,$01,$81,$F8
		.BYTE	$F0,$BE,$01,$81,$FE,$F0,$AF,$02,$81,$E6,$F8,$BD,$00,$00
_spr_lib7_40:
		.BYTE	$04,$F0,$E8,$A8,$01,$AA,$01,$BC,$00,$AF,$02,$04,$F0,$F8,$C4,$00
		.BYTE	$C6,$00,$C5,$00,$C7,$00,$81,$FE,$E0,$A9,$03,$81,$00,$E0,$A7,$00
		.BYTE	$81,$06,$E0,$AB,$03,$81,$00,$E3,$BB,$01,$82,$F8,$E8,$A1,$00,$AC
		.BYTE	$02,$02,$00,$F0,$AE,$02,$AD,$02,$81,$02,$E8,$BE,$01,$81,$08,$E8
		.BYTE	$A5,$00,$00
_spr_lib7_68:
		.BYTE	$81,$F9,$F0,$F5,$01,$81,$FD,$F8,$F6,$01,$00
_spr_lib8_34:
		.BYTE	$81,$F4,$C7,$A8,$01,$83,$EC,$CF,$BA,$02,$AE,$01,$B4,$02,$04,$EC
		.BYTE	$EF,$AF,$02,$B1,$02,$B3,$02,$B5,$02,$02,$EF,$E7,$A3,$02,$A5,$02
		.BYTE	$81,$F0,$CF,$AA,$01,$81,$F8,$CF,$AC,$01,$81,$FA,$CF,$BC,$02,$81
		.BYTE	$F1,$D7,$BE,$02,$83,$F4,$D7,$B0,$01,$B6,$02,$AD,$03,$81,$F9,$D7
		.BYTE	$A1,$02,$82,$FC,$D7,$B2,$01,$B8,$02,$81,$00,$E0,$AB,$01,$81,$04
		.BYTE	$E7,$A9,$01,$81,$FC,$E8,$A7,$01,$81,$09,$EF,$B7,$02,$81,$EF,$F7
		.BYTE	$BD,$42,$03,$F4,$F7,$B9,$02,$BB,$02,$BD,$02,$00
_spr_lib8_35:
		.BYTE	$81,$F1,$C6,$A8,$01,$83,$E9,$CE,$BA,$02,$AE,$01,$B4,$02,$02,$EC
		.BYTE	$EF,$C0,$02,$C2,$02,$02,$ED,$CE,$AA,$01,$AC,$01,$02,$EE,$D6,$BE
		.BYTE	$02,$A1,$02,$81,$F7,$CE,$BC,$02,$82,$F1,$D6,$B0,$01,$B6,$02,$82
		.BYTE	$F9,$D6,$B2,$01,$B8,$02,$81,$FE,$DF,$AB,$01,$81,$F2,$E6,$AD,$03
		.BYTE	$81,$F5,$E6,$A5,$02,$81,$02,$E6,$A9,$01,$81,$F3,$E7,$BF,$02,$81
		.BYTE	$FA,$E7,$A7,$01,$82,$FB,$EE,$C4,$02,$CC,$02,$82,$03,$EE,$C6,$02
		.BYTE	$CE,$02,$81,$08,$EF,$C8,$02,$81,$EF,$F7,$BD,$42,$81,$F4,$F7,$CA
		.BYTE	$02,$00
_spr_lib8_36:
		.BYTE	$81,$F2,$C4,$A8,$01,$83,$EA,$CC,$BA,$02,$AE,$01,$B4,$02,$03,$EC
		.BYTE	$EF,$D8,$02,$DA,$02,$DC,$02,$81,$EE,$CC,$AA,$01,$81,$F6,$CC,$AC
		.BYTE	$01,$81,$F8,$CC,$BC,$02,$81,$EF,$D4,$BE,$02,$83,$F2,$D4,$B0,$01
		.BYTE	$B6,$02,$AD,$03,$81,$F7,$D4,$A1,$02,$82,$FA,$D4,$B2,$01,$B8,$02
		.BYTE	$81,$FE,$DD,$AB,$01,$81,$ED,$DF,$D0,$02,$02,$F2,$E7,$D2,$02,$D4
		.BYTE	$02,$02,$F4,$F7,$C1,$02,$C3,$02,$81,$F5,$E4,$A5,$02,$82,$02,$E4
		.BYTE	$A9,$01,$DE,$02,$81,$FA,$E5,$A7,$01,$81,$08,$E7,$D6,$02,$00
_spr_lib8_37:
		.BYTE	$04,$E4,$EF,$C9,$02,$CB,$02,$CD,$02,$CF,$02,$81,$F1,$C6,$A8,$01
		.BYTE	$83,$E9,$CE,$BA,$02,$AE,$01,$B4,$02,$02,$ED,$CE,$AA,$01,$AC,$01
		.BYTE	$02,$ED,$E7,$C5,$02,$C7,$02,$02,$EE,$D6,$BE,$02,$A1,$02,$02,$F1
		.BYTE	$D6,$B0,$01,$B2,$01,$02,$F1,$DE,$B6,$02,$B8,$02,$81,$F7,$CE,$BC
		.BYTE	$02,$81,$FE,$DF,$AB,$01,$81,$F2,$E6,$AD,$03,$02,$F2,$F7,$BD,$42
		.BYTE	$D3,$02,$81,$F5,$E6,$A5,$02,$83,$02,$E6,$A9,$01,$D1,$02,$D5,$02
		.BYTE	$81,$FA,$E7,$A7,$01,$81,$07,$EF,$C8,$02,$00
_spr_lib8_38:
		.BYTE	$81,$03,$C9,$A8,$01,$83,$FB,$D1,$BA,$02,$AE,$01,$B4,$02,$81,$FF
		.BYTE	$D1,$AA,$01,$81,$07,$D1,$AC,$01,$81,$09,$D1,$BC,$02,$81,$00,$D9
		.BYTE	$BE,$02,$81,$03,$D9,$B0,$01,$81,$08,$D9,$A1,$02,$81,$0B,$D9,$B2
		.BYTE	$01,$81,$03,$DF,$D7,$02,$81,$0B,$DF,$D9,$02,$82,$0B,$E5,$DF,$01
		.BYTE	$E6,$01,$82,$13,$E5,$E0,$01,$E8,$01,$81,$FC,$E7,$DB,$02,$81,$04
		.BYTE	$E7,$DD,$02,$81,$03,$E9,$AD,$03,$81,$F3,$EC,$D6,$42,$04,$F3,$F7
		.BYTE	$EA,$02,$EC,$02,$EE,$02,$F0,$02,$02,$FB,$EF,$E2,$02,$E4,$02,$00
_spr_lib8_39:
		.BYTE	$81,$EC,$C9,$A8,$01,$83,$E4,$D1,$BA,$02,$AE,$01,$B4,$02,$81,$E8
		.BYTE	$D1,$AA,$01,$81,$F0,$D1,$AC,$01,$81,$F2,$D1,$BC,$02,$81,$E9,$D9
		.BYTE	$BE,$02,$81,$EC,$D9,$B0,$01,$81,$F1,$D9,$A1,$02,$82,$F4,$D9,$B2
		.BYTE	$01,$B8,$02,$81,$DB,$DF,$F2,$01,$81,$EC,$DF,$F4,$02,$81,$F9,$E2
		.BYTE	$AB,$01,$81,$E3,$E4,$F8,$02,$81,$ED,$E5,$FE,$03,$81,$DC,$E7,$F6
		.BYTE	$01,$81,$EB,$E7,$FA,$02,$81,$F3,$E7,$FC,$02,$81,$E4,$E8,$E1,$01
		.BYTE	$04,$E9,$F7,$F0,$42,$EE,$42,$EC,$42,$EA,$42,$03,$EC,$EF,$E3,$02
		.BYTE	$E5,$02,$E7,$02,$81,$FD,$E9,$A9,$01,$81,$F5,$EA,$A7,$01,$81,$04
		.BYTE	$EC,$D6,$02,$00
_spr_lib8_3A:
		.BYTE	$81,$EC,$C9,$A8,$01,$83,$E4,$D1,$BA,$02,$AE,$01,$B4,$02,$81,$E8
		.BYTE	$D1,$AA,$01,$81,$F0,$D1,$AC,$01,$81,$F2,$D1,$BC,$02,$81,$E9,$D9
		.BYTE	$BE,$02,$81,$EC,$D9,$B0,$01,$81,$F1,$D9,$A1,$02,$82,$F4,$D9,$B2
		.BYTE	$01,$B8,$02,$81,$DC,$DF,$E9,$02,$81,$EC,$DF,$F4,$02,$81,$F9,$E2
		.BYTE	$AB,$01,$81,$E3,$E4,$F8,$02,$04,$E9,$F7,$F0,$42,$EE,$42,$EC,$42
		.BYTE	$EA,$42,$02,$EB,$E7,$FA,$02,$FC,$02,$03,$EC,$EF,$EF,$02,$E5,$02
		.BYTE	$E7,$02,$81,$ED,$E5,$FE,$03,$81,$FD,$E9,$A9,$01,$81,$F5,$EA,$A7
		.BYTE	$01,$81,$04,$EC,$D6,$02,$00
_spr_lib8_3B:
		.BYTE	$81,$F8,$F8,$EB,$01,$81,$FF,$F9,$EB,$C1,$00
_spr_lib8_3C:
		.BYTE	$81,$F8,$F7,$ED,$01,$81,$00,$F8,$ED,$C1,$00
_spr_lib8_3D:
		.BYTE	$81,$00,$F7,$ED,$41,$81,$F8,$F8,$ED,$81,$00
_spr_lib9_06:
		.BYTE	$04,$EB,$E8,$A8,$02,$CE,$03,$AC,$02,$AE,$02,$02,$EB,$E8,$CC,$03
		.BYTE	$AA,$02,$04,$EB,$F0,$A9,$02,$AB,$02,$AD,$02,$AF,$02,$81,$EF,$E0
		.BYTE	$A1,$02,$81,$FB,$E0,$A3,$02,$81,$03,$E0,$A5,$02,$81,$EC,$EC,$A7
		.BYTE	$01,$81,$EB,$F1,$B8,$03,$02,$F7,$FE,$D2,$02,$D2,$42,$02,$F7,$06
		.BYTE	$FF,$02,$FF,$42,$02,$FA,$F8,$B0,$02,$B2,$02,$81,$FA,$F8,$B1,$03
		.BYTE	$00
_spr_lib9_07:
		.BYTE	$82,$EB,$E6,$A8,$02,$A9,$02,$02,$EB,$E6,$CC,$03,$B9,$02,$83,$F3
		.BYTE	$E6,$CE,$03,$BA,$02,$BB,$02,$81,$EC,$EA,$A7,$01,$82,$FB,$EE,$BC
		.BYTE	$02,$BD,$02,$81,$03,$EE,$BE,$02,$81,$EB,$EF,$B8,$03,$02,$F7,$FC
		.BYTE	$D2,$02,$D2,$42,$02,$F7,$04,$FF,$02,$FF,$42,$81,$FC,$F6,$B1,$03
		.BYTE	$81,$02,$F6,$BF,$02,$00
_spr_lib9_08:
		.BYTE	$04,$EB,$E7,$CC,$03,$CE,$03,$B4,$02,$B6,$02,$04,$EB,$EF,$A9,$02
		.BYTE	$AB,$02,$B5,$02,$B7,$02,$81,$F1,$E7,$B3,$02,$81,$EC,$EB,$A7,$01
		.BYTE	$81,$EB,$F0,$B8,$03,$02,$F7,$FD,$D2,$02,$D2,$42,$02,$F7,$05,$FF
		.BYTE	$02,$FF,$42,$02,$FA,$F7,$B0,$02,$B2,$02,$81,$FA,$F7,$B1,$03,$00
_spr_lib9_09:
		.BYTE	$04,$EB,$E8,$A8,$02,$CE,$03,$AC,$02,$AE,$02,$02,$EB,$E8,$CC,$03
		.BYTE	$AA,$02,$04,$EB,$F0,$A9,$02,$AB,$02,$AD,$02,$AF,$02,$81,$EF,$E0
		.BYTE	$A1,$02,$81,$FB,$E0,$A3,$02,$81,$03,$E0,$A5,$02,$81,$EC,$EC,$A7
		.BYTE	$01,$81,$EB,$F1,$B8,$03,$02,$FA,$F8,$B0,$02,$B2,$02,$81,$FA,$F8
		.BYTE	$B1,$03,$00
_spr_lib9_0A:
		.BYTE	$82,$EB,$E6,$A8,$02,$A9,$02,$02,$EB,$E6,$CC,$03,$B9,$02,$83,$F3
		.BYTE	$E6,$CE,$03,$BA,$02,$BB,$02,$81,$EC,$EA,$A7,$01,$81,$FB,$EE,$BC
		.BYTE	$02,$81,$03,$EE,$BE,$02,$81,$EB,$EF,$B8,$03,$02,$FA,$F6,$BD,$02
		.BYTE	$BF,$02,$81,$FA,$F7,$B1,$03,$00
_spr_lib9_0B:
		.BYTE	$04,$EB,$E7,$CC,$03,$CE,$03,$B4,$02,$B6,$02,$04,$EB,$EF,$A9,$02
		.BYTE	$AB,$02,$B5,$02,$B7,$02,$81,$F1,$E7,$B3,$02,$81,$EC,$EB,$A7,$01
		.BYTE	$81,$EB,$F0,$B8,$03,$02,$FA,$F7,$B0,$02,$B2,$02,$81,$FA,$F7,$B1
		.BYTE	$03,$00
_spr_lib7_6A:
		.BYTE	$82,$F8,$F0,$D2,$02,$FF,$02,$82,$00,$F0,$D2,$42,$FF,$42,$00
_spr_lib7_6B:
		.BYTE	$02,$F8,$E9,$D0,$02,$D0,$42,$02,$F8,$EE,$CA,$01,$C2,$02,$81,$FD
		.BYTE	$EA,$CF,$03,$81,$F8,$EE,$C0,$02,$82,$F8,$EF,$C4,$02,$C5,$02,$82
		.BYTE	$00,$EF,$C6,$02,$C7,$02,$02,$F8,$F7,$D1,$02,$D1,$42,$00
_spr_lib7_6C:
		.BYTE	$02,$F8,$E3,$D0,$02,$D0,$42,$02,$F8,$ED,$CA,$01,$C2,$02,$81,$FD
		.BYTE	$E9,$CF,$03,$81,$F8,$ED,$C0,$02,$82,$F8,$EE,$C4,$02,$C5,$02,$82
		.BYTE	$00,$EE,$C6,$02,$C7,$02,$02,$F8,$F7,$D1,$02,$D1,$42,$00
_spr_lib7_6D:
		.BYTE	$02,$F8,$DE,$D0,$02,$D0,$42,$02,$F8,$EC,$CA,$01,$C2,$02,$81,$FD
		.BYTE	$E8,$CF,$03,$81,$F8,$EC,$C0,$02,$82,$F8,$ED,$C4,$02,$C5,$02,$82
		.BYTE	$00,$ED,$C6,$02,$C7,$02,$02,$F8,$F7,$D1,$02,$D1,$42,$00
_spr_lib7_6E:
		.BYTE	$02,$F8,$EF,$CA,$01,$C2,$02,$81,$FD,$EB,$CF,$03,$82,$F8,$EF,$C0
		.BYTE	$02,$C1,$02,$81,$00,$F7,$C3,$02,$00
_spr_lib7_6F:
		.BYTE	$02,$F8,$EE,$CA,$01,$C2,$02,$81,$FD,$EA,$CF,$03,$81,$F8,$EE,$C0
		.BYTE	$02,$82,$F8,$EF,$C4,$02,$C5,$02,$82,$00,$EF,$C6,$02,$C7,$02,$00
_spr_lib7_70:
		.BYTE	$02,$F8,$F0,$C0,$02,$C2,$02,$81,$FD,$EC,$CF,$03,$82,$F8,$F0,$CA
		.BYTE	$01,$C9,$02,$81,$00,$F8,$CB,$02,$00
_spr_lib5_17:
		.BYTE	$82,$F8,$EF,$90,$02,$91,$02,$82,$00,$EF,$90,$42,$91,$42,$00
_spr_lib5_18:
		.BYTE	$82,$FC,$EF,$94,$02,$95,$02,$00
_spr_lib5_19:
		.BYTE	$82,$F9,$EF,$96,$02,$96,$82,$00
_spr_lib5_1B:
		.BYTE	$82,$F8,$F0,$81,$00,$83,$C0,$82,$00,$F0,$83,$00,$83,$80,$00
_spr_lib5_1C:
		.BYTE	$04,$F0,$E8,$97,$00,$99,$00,$99,$40,$97,$40,$04,$F0,$F0,$9A,$41
		.BYTE	$9C,$41,$9C,$01,$9A,$01,$04,$F0,$F8,$9E,$41,$9C,$41,$9C,$01,$9E
		.BYTE	$01,$81,$FC,$E0,$FE,$01,$00
_spr_lib4_05:
		.BYTE	$82,$F8,$F0,$E4,$00,$E5,$00,$82,$00,$F0,$84,$00,$93,$00,$00
_spr_lib4_06:
		.BYTE	$02,$F8,$F1,$E3,$C0,$E1,$C0,$02,$F8,$F8,$E3,$40,$E1,$40,$00
_spr_lib5_26:
		.BYTE	$04,$DC,$F8,$90,$00,$92,$00,$94,$00,$96,$00,$04,$04,$F8,$98,$00
		.BYTE	$9A,$00,$9C,$00,$9B,$00,$00
_spr_lib5_27:
		.BYTE	$04,$DC,$F8,$91,$00,$93,$00,$95,$00,$97,$00,$04,$04,$F8,$98,$00
		.BYTE	$9A,$00,$9C,$00,$9B,$00,$00
_spr_lib5_28:
		.BYTE	$04,$F0,$F8,$91,$00,$99,$00,$93,$00,$98,$00,$00
_spr_lib5_1D:
		.BYTE	$02,$F8,$F8,$E0,$00,$E0,$C0,$00
_spr_lib5_0F:
		.BYTE	$81,$F8,$F8,$E2,$00,$81,$00,$F9,$E2,$C0,$00
_spr_lib5_10:
		.BYTE	$02,$F8,$F8,$E0,$80,$E0,$40,$00
_spr_lib5_11:
		.BYTE	$81,$00,$F8,$E2,$40,$81,$F8,$F9,$E2,$80,$00
_spr_lib5_1E:
		.BYTE	$82,$F8,$F0,$A0,$00,$A2,$00,$82,$00,$F0,$A0,$40,$A2,$40,$00
_spr_lib5_1F:
		.BYTE	$02,$F8,$F8,$92,$01,$A6,$01,$00
_spr_lib5_24:
		.BYTE	$82,$F8,$F0,$98,$00,$9D,$00,$82,$00,$F0,$9B,$00,$9F,$00,$00
_spr_lib5_25:
		.BYTE	$82,$F8,$F0,$98,$01,$9D,$01,$82,$00,$F0,$9B,$01,$9F,$01,$00
_spr_lib5_35:
		.BYTE	$02,$F8,$F8,$EB,$01,$E8,$01,$00
_spr_lib5_36:
		.BYTE	$02,$F8,$F8,$E9,$01,$E8,$01,$00
_spr_lib5_37:
		.BYTE	$82,$F8,$F0,$FC,$00,$FD,$01,$82,$00,$F0,$FF,$00,$FD,$41,$00
_spr_lib5_41:
		.BYTE	$82,$F8,$F0,$E1,$01,$E3,$C1,$82,$00,$F0,$E3,$01,$E3,$81,$00
_spr_lib5_42:
		.BYTE	$81,$FC,$01,$E5,$01,$81,$F5,$06,$E5,$01,$81,$EE,$0B,$E5,$01,$81
		.BYTE	$E7,$10,$E5,$01,$81,$E0,$15,$E5,$01,$00
_spr_lib5_43:
		.BYTE	$81,$FC,$01,$E5,$01,$81,$F6,$07,$E5,$01,$81,$F0,$0D,$E5,$01,$81
		.BYTE	$EA,$13,$E5,$01,$81,$E4,$19,$E5,$01,$00
_spr_lib5_44:
		.BYTE	$81,$FC,$01,$E5,$01,$81,$F8,$08,$E5,$01,$81,$F4,$0F,$E5,$01,$81
		.BYTE	$F0,$16,$E5,$01,$81,$EC,$1D,$E5,$01,$00
_spr_lib5_45:
		.BYTE	$84,$FC,$01,$E5,$01,$E5,$01,$E5,$01,$E5,$01,$81,$FC,$20,$E5,$01
		.BYTE	$00
_spr_lib7_43:
		.BYTE	$04,$F0,$E7,$D8,$02,$DA,$02,$DC,$02,$DE,$02,$03,$F0,$EF,$D7,$02
		.BYTE	$D9,$02,$DB,$02,$02,$F6,$DF,$D4,$02,$D6,$02,$02,$F7,$F7,$DF,$02
		.BYTE	$E0,$02,$81,$F8,$E7,$D3,$01,$81,$0A,$EF,$DD,$01,$81,$FB,$F2,$D5
		.BYTE	$03,$02,$07,$F6,$E2,$01,$E4,$01,$00
_spr_lib7_44:
		.BYTE	$03,$EE,$E7,$D8,$02,$D3,$01,$DC,$02,$81,$F4,$DF,$D4,$02,$81,$FC
		.BYTE	$DF,$D6,$02,$81,$F6,$E7,$DA,$02,$81,$06,$E9,$E6,$02,$81,$EE,$EF
		.BYTE	$D7,$02,$04,$F2,$F7,$EC,$02,$EE,$02,$F0,$02,$F2,$01,$02,$F5,$EF
		.BYTE	$E8,$02,$EA,$02,$81,$08,$F1,$DD,$01,$81,$F9,$F2,$BA,$03,$00
_spr_lib7_45:
		.BYTE	$04,$EE,$E6,$D8,$02,$D3,$01,$DC,$02,$DE,$02,$03,$EE,$EE,$D7,$02
		.BYTE	$D9,$02,$DB,$02,$02,$F4,$DE,$D4,$02,$D6,$02,$02,$F5,$F6,$F4,$02
		.BYTE	$F6,$02,$81,$F6,$E6,$DA,$02,$81,$08,$ED,$DD,$01,$81,$F9,$F1,$D5
		.BYTE	$03,$81,$05,$F4,$E2,$01,$81,$0D,$F4,$E4,$01,$81,$FD,$FE,$F8,$02
		.BYTE	$00
_spr_lib7_46:
		.BYTE	$03,$EE,$E7,$D8,$02,$D3,$01,$DC,$02,$81,$F4,$DF,$D4,$02,$81,$FC
		.BYTE	$DF,$D6,$02,$81,$F6,$E7,$DA,$02,$81,$06,$E9,$E6,$02,$81,$EE,$EF
		.BYTE	$D7,$02,$04,$F2,$F7,$FE,$02,$E1,$02,$E3,$02,$F2,$01,$02,$F5,$EF
		.BYTE	$FA,$02,$FC,$02,$81,$F8,$F0,$E5,$03,$81,$08,$F1,$DD,$01,$00
_spr_lib7_47:
		.BYTE	$02,$E7,$EE,$D8,$02,$D3,$01,$02,$E7,$F6,$D7,$02,$F3,$02,$02,$ED
		.BYTE	$E6,$D4,$02,$D6,$02,$83,$F7,$E7,$E7,$02,$ED,$02,$F5,$02,$81,$FF
		.BYTE	$E7,$E9,$02,$81,$02,$E9,$EB,$02,$81,$EF,$EE,$DA,$02,$82,$07,$EF
		.BYTE	$EF,$02,$F9,$02,$82,$0F,$EF,$F1,$01,$FB,$01,$81,$F5,$F3,$BC,$03
		.BYTE	$81,$FF,$F7,$F7,$02,$00
_spr_lib7_48:
		.BYTE	$02,$E7,$EE,$D8,$02,$D3,$01,$02,$E7,$F6,$D7,$02,$F3,$02,$02,$ED
		.BYTE	$E6,$D4,$02,$D6,$02,$83,$F7,$E7,$E7,$02,$ED,$02,$F5,$02,$81,$FF
		.BYTE	$E7,$E9,$02,$81,$02,$E9,$EB,$02,$81,$EF,$EE,$DA,$02,$82,$0E,$EE
		.BYTE	$F1,$01,$FB,$01,$82,$07,$EF,$EF,$02,$F9,$02,$81,$F5,$F3,$BC,$03
		.BYTE	$81,$FF,$F7,$F7,$02,$00
_spr_lib7_49:
		.BYTE	$02,$E7,$EE,$D8,$02,$D3,$01,$02,$E7,$F6,$D7,$02,$F3,$02,$02,$ED
		.BYTE	$E6,$D4,$02,$D6,$02,$81,$F5,$DF,$FD,$02,$81,$FD,$E0,$FF,$02,$83
		.BYTE	$F7,$E7,$9E,$02,$ED,$02,$F5,$02,$81,$FF,$E7,$E9,$02,$81,$EF,$EE
		.BYTE	$DA,$02,$81,$F5,$F3,$BC,$03,$03,$FF,$F7,$F7,$02,$F9,$02,$9C,$02
		.BYTE	$00
_spr_lib7_4A:
		.BYTE	$81,$FB,$F8,$B3,$01,$00
_spr_lib7_74:
		.BYTE	$82,$F0,$DF,$D9,$02,$DD,$02,$82,$F8,$DF,$DB,$02,$DF,$02,$81,$F8
		.BYTE	$DF,$EF,$00,$82,$00,$DF,$E0,$00,$E1,$02,$82,$08,$DF,$E2,$02,$E3
		.BYTE	$02,$81,$00,$E0,$86,$01,$82,$F6,$EF,$E4,$02,$E5,$02,$82,$FE,$EF
		.BYTE	$E6,$02,$E7,$02,$82,$06,$EF,$E8,$02,$E9,$02,$81,$EE,$F4,$EC,$02
		.BYTE	$00
_spr_lib7_75:
		.BYTE	$85,$F8,$DC,$EA,$02,$F8,$02,$F9,$02,$FC,$02,$FD,$02,$81,$F8,$DC
		.BYTE	$EF,$00,$85,$00,$DC,$E0,$00,$ED,$02,$FB,$02,$FE,$02,$FF,$02,$81
		.BYTE	$00,$DD,$86,$01,$82,$F0,$E4,$F6,$02,$F7,$02,$81,$08,$EC,$FA,$02
		.BYTE	$00
_spr_lib7_76:
		.BYTE	$84,$F8,$DF,$EA,$02,$EB,$02,$F0,$02,$F1,$02,$81,$F8,$DF,$EF,$00
		.BYTE	$84,$00,$DF,$E0,$00,$ED,$02,$F2,$02,$F3,$02,$81,$00,$E0,$86,$01
		.BYTE	$81,$F0,$EF,$EE,$02,$82,$08,$EF,$F4,$02,$F5,$02,$81,$F0,$F6,$EC
		.BYTE	$02,$00
_spr_lib7_77:
		.BYTE	$82,$FC,$EF,$F8,$02,$FE,$02,$82,$04,$EF,$FA,$02,$E1,$02,$81,$F4
		.BYTE	$F3,$F6,$02,$81,$F4,$F7,$FC,$02,$81,$F4,$F7,$F7,$01,$00
_spr_lib7_78:
		.BYTE	$82,$FC,$EF,$F8,$02,$E5,$02,$82,$04,$EF,$FA,$02,$E7,$02,$81,$F4
		.BYTE	$F3,$F6,$02,$81,$F4,$F7,$E3,$02,$81,$F4,$F7,$F7,$01,$00
_spr_lib7_79:
		.BYTE	$82,$FC,$EF,$F8,$02,$E9,$02,$82,$04,$EF,$FA,$02,$EB,$02,$81,$F4
		.BYTE	$F3,$F6,$02,$81,$F4,$F7,$E3,$02,$81,$F4,$F7,$F7,$01,$00
_spr_lib7_7A:
		.BYTE	$82,$01,$EF,$ED,$02,$F3,$02,$82,$09,$EF,$EF,$02,$F5,$02,$81,$F9
		.BYTE	$F5,$F6,$02,$81,$F9,$F7,$F1,$02,$81,$F9,$F9,$F7,$01,$00
_spr_lib5_29:
		.BYTE	$86,$FC,$D0,$9B,$01,$9B,$01,$9B,$01,$9B,$01,$9B,$01,$9B,$01,$00
_spr_lib5_2A:
		.BYTE	$86,$FC,$D0,$9B,$41,$9B,$41,$9B,$41,$9B,$41,$9B,$41,$9B,$41,$00
_spr_lib5_2B:
		.BYTE	$81,$F6,$F0,$9D,$00,$02,$F8,$F7,$94,$01,$94,$41,$00
_spr_lib5_2C:
		.BYTE	$02,$F8,$F7,$94,$01,$94,$41,$81,$02,$F0,$9D,$40,$00
_spr_lib5_2D:
		.BYTE	$02,$F8,$F0,$9F,$00,$95,$01,$81,$FA,$E1,$9A,$01,$82,$FC,$E5,$9B
		.BYTE	$02,$9B,$02,$81,$F8,$F3,$97,$01,$81,$01,$F3,$97,$01,$81,$F8,$F8
		.BYTE	$99,$00,$81,$01,$F8,$99,$01,$00
_spr_lib5_2E:
		.BYTE	$04,$F0,$F0,$96,$03,$98,$01,$98,$01,$96,$03,$00
_spr_lib5_39:
		.BYTE	$04,$F0,$F0,$96,$00,$98,$01,$98,$01,$96,$00,$00
_spr_lib5_22:
		.BYTE	$81,$F0,$F0,$96,$00,$81,$08,$F0,$96,$00,$81,$F5,$F6,$84,$01,$81
		.BYTE	$03,$F6,$84,$41,$00
_spr_lib5_23:
		.BYTE	$82,$F0,$F0,$96,$00,$86,$01,$82,$08,$F0,$96,$00,$86,$41,$00
_spr_lib5_2F:
		.BYTE	$83,$F8,$00,$94,$01,$95,$01,$9B,$01,$83,$00,$00,$96,$01,$97,$01
		.BYTE	$9D,$01,$82,$F0,$08,$98,$01,$99,$01,$81,$F8,$08,$9A,$01,$81,$F7
		.BYTE	$18,$9C,$01,$00
_spr_lib5_30:
		.BYTE	$82,$F8,$00,$94,$01,$95,$01,$82,$00,$00,$96,$01,$97,$01,$82,$F8
		.BYTE	$0C,$A4,$01,$FD,$01,$82,$00,$0C,$A6,$01,$FF,$01,$00
_spr_lib5_31:
		.BYTE	$83,$F8,$00,$94,$01,$95,$01,$9D,$41,$83,$00,$00,$96,$01,$97,$01
		.BYTE	$9B,$41,$02,$00,$08,$9A,$41,$98,$41,$81,$08,$10,$99,$41,$81,$01
		.BYTE	$18,$9C,$41,$00
_spr_lib5_32:
		.BYTE	$82,$F8,$F0,$9E,$02,$9F,$02,$82,$00,$F0,$A0,$02,$A2,$02,$00
_spr_lib5_33:
		.BYTE	$06,$E8,$FD,$E0,$00,$E2,$00,$E4,$00,$E4,$00,$E2,$00,$E6,$00,$06
		.BYTE	$E8,$05,$E8,$00,$EA,$00,$EC,$00,$EC,$00,$EA,$00,$EE,$00,$04,$F0
		.BYTE	$0D,$F0,$01,$F2,$01,$F4,$01,$F6,$01,$04,$F0,$15,$F8,$01,$FA,$01
		.BYTE	$FC,$01,$FE,$01,$00
_spr_lib5_34:
		.BYTE	$06,$E8,$FD,$E0,$00,$E2,$00,$E4,$00,$E4,$00,$E2,$00,$E6,$00,$06
		.BYTE	$E8,$05,$E8,$00,$EA,$00,$EC,$00,$EC,$00,$EA,$00,$EE,$00,$04,$F0
		.BYTE	$0C,$F6,$41,$F4,$41,$F2,$41,$F0,$41,$04,$F0,$14,$FE,$41,$FC,$41
		.BYTE	$FA,$41,$F8,$41,$00
_spr_lib5_38:
		.BYTE	$83,$F4,$E8,$ED,$00,$F3,$00,$F9,$00,$83,$FC,$E8,$EF,$00,$F5,$00
		.BYTE	$FB,$00,$83,$04,$E8,$F1,$00,$F7,$00,$FD,$00,$00
_spr_lib5_3A:
		.BYTE	$83,$F0,$E7,$C8,$03,$D1,$00,$D5,$00,$81,$F2,$E7,$D0,$00,$83,$F8
		.BYTE	$E7,$CA,$03,$CB,$01,$D7,$00,$81,$FA,$E7,$D2,$00,$81,$F7,$EC,$C9
		.BYTE	$01,$81,$F8,$EF,$D3,$00,$82,$00,$EF,$CE,$01,$CF,$01,$81,$F1,$F7
		.BYTE	$CD,$01,$81,$00,$F7,$D8,$00,$00
_spr_lib5_3B:
		.BYTE	$82,$F0,$E7,$C8,$03,$D1,$00,$81,$F2,$E7,$D0,$00,$83,$F8,$E7,$CA
		.BYTE	$03,$D3,$00,$DB,$00,$81,$FA,$E7,$D2,$00,$81,$F7,$EC,$C9,$01,$81
		.BYTE	$F8,$EF,$CB,$01,$82,$00,$EF,$CE,$01,$DD,$00,$81,$F1,$F7,$D9,$01
		.BYTE	$81,$00,$F7,$DA,$01,$00
_spr_lib5_3C:
		.BYTE	$03,$EF,$EF,$DF,$00,$E2,$00,$CE,$01,$81,$F6,$E1,$CC,$03,$81,$F1
		.BYTE	$E7,$DC,$00,$81,$F9,$E7,$DE,$00,$81,$F5,$E9,$D6,$01,$82,$F7,$EF
		.BYTE	$D4,$01,$DB,$00,$81,$F0,$F7,$D9,$01,$81,$FF,$F7,$E0,$00,$81,$FF
		.BYTE	$F7,$DA,$01,$00
_spr_lib5_3D:
		.BYTE	$84,$ED,$DF,$EA,$03,$E8,$03,$E6,$03,$E7,$03,$03,$EF,$EF,$DF,$00
		.BYTE	$D4,$01,$CE,$01,$81,$F5,$DF,$EC,$03,$83,$FD,$DF,$EA,$43,$E8,$43
		.BYTE	$EE,$03,$81,$F6,$E1,$CC,$03,$81,$F1,$E7,$DC,$00,$81,$F9,$E7,$DE
		.BYTE	$00,$81,$F5,$E9,$D6,$01,$82,$F7,$EF,$E2,$00,$DB,$00,$82,$05,$EF
		.BYTE	$EA,$43,$E7,$43,$81,$F0,$F7,$D9,$01,$81,$FF,$F7,$E0,$00,$81,$FF
		.BYTE	$F7,$DA,$01,$00
_spr_lib5_3E:
		.BYTE	$03,$F1,$EF,$DF,$00,$E2,$00,$CE,$01,$03,$F1,$F7,$E4,$01,$E3,$00
		.BYTE	$DA,$01,$81,$F8,$E1,$CC,$03,$81,$F3,$E7,$DC,$00,$81,$FB,$E7,$DE
		.BYTE	$00,$81,$F7,$E9,$D6,$01,$81,$F9,$EF,$D4,$01,$81,$F1,$F7,$E1,$00
		.BYTE	$81,$01,$F7,$DD,$00,$00
_spr_lib5_3F:
		.BYTE	$84,$EF,$DF,$EA,$03,$E8,$03,$E6,$03,$E7,$03,$03,$F1,$EF,$DF,$00
		.BYTE	$D4,$01,$CE,$01,$03,$F1,$F7,$E1,$00,$E3,$00,$DD,$00,$81,$F7,$DF
		.BYTE	$EC,$03,$83,$FF,$DF,$EA,$43,$E8,$43,$EE,$03,$81,$F8,$E1,$CC,$03
		.BYTE	$81,$F3,$E7,$DC,$00,$81,$FB,$E7,$DE,$00,$81,$F7,$E9,$D6,$01,$81
		.BYTE	$F9,$EF,$E2,$00,$82,$07,$EF,$EA,$43,$E7,$43,$81,$F1,$F7,$E4,$01
		.BYTE	$81,$01,$F7,$DA,$01,$00
_spr_lib5_40:
		.BYTE	$02,$F8,$F7,$F1,$03,$F3,$03,$00
_spr_lib5_05:
		.BYTE	$02,$F8,$F7,$EB,$03,$ED,$03,$00
_spr_lib0_19:
		.BYTE	$04,$F0,$E8,$CE,$03,$CF,$03,$EE,$03,$EF,$03,$04,$F0,$F0,$DE,$02
		.BYTE	$DF,$02,$FE,$02,$FF,$02,$02,$F8,$F8,$CD,$02,$CD,$42,$81,$10,$EB
		.BYTE	$C0,$02,$00
_spr_lib0_1A:
		.BYTE	$04,$F0,$E8,$CE,$03,$CF,$03,$EE,$03,$EF,$03,$04,$F0,$F0,$DE,$02
		.BYTE	$DF,$02,$FE,$02,$FF,$02,$02,$F8,$F8,$CD,$02,$CD,$42,$81,$10,$ED
		.BYTE	$C0,$82,$00
_spr_lib1_1B:
		.BYTE	$02,$F8,$E7,$31,$00,$33,$00,$02,$F8,$F7,$0A,$00,$0C,$00,$81,$F9
		.BYTE	$EF,$3B,$00,$81,$FA,$EF,$35,$01,$81,$00,$EF,$3D,$00,$00
_spr_lib1_1C:
		.BYTE	$02,$F8,$E7,$31,$00,$33,$00,$02,$F8,$F7,$0A,$00,$0C,$00,$81,$F9
		.BYTE	$EF,$3F,$00,$81,$FA,$EF,$37,$01,$81,$00,$EF,$3D,$00,$00
_spr_lib1_1D:
		.BYTE	$83,$F8,$E7,$31,$00,$40,$00,$0A,$00,$83,$00,$E7,$33,$00,$42,$00
		.BYTE	$0C,$00,$81,$FA,$EF,$39,$01,$00
_spr_lib1_1E:
		.BYTE	$81,$F8,$E7,$31,$00,$83,$00,$E7,$33,$00,$3D,$00,$0C,$00,$81,$F1
		.BYTE	$EE,$44,$00,$81,$F9,$EF,$46,$00,$81,$FA,$EF,$37,$01,$81,$F8,$F7
		.BYTE	$48,$00,$00
_spr_lib1_1F:
		.BYTE	$81,$F8,$E7,$31,$00,$83,$00,$E7,$33,$00,$3D,$00,$0C,$00,$81,$F1
		.BYTE	$EE,$44,$00,$81,$F9,$EF,$4A,$00,$81,$FA,$EF,$35,$01,$81,$F8,$F7
		.BYTE	$48,$00,$00
_spr_lib1_20:
_spr_lib2_20:
		.BYTE	$81,$FB,$EE,$7D,$01,$00
_spr_lib1_21:
_spr_lib2_21:
		.BYTE	$81,$FB,$EE,$2D,$00,$00
_spr_lib2_1B:
		.BYTE	$02,$F8,$E7,$4C,$00,$7E,$00,$02,$F8,$F7,$56,$00,$58,$00,$81,$F9
		.BYTE	$EF,$61,$00,$81,$FA,$EF,$35,$01,$81,$00,$EF,$2B,$00,$00
_spr_lib2_1C:
		.BYTE	$02,$F8,$E7,$4C,$00,$7E,$00,$02,$F8,$F7,$56,$00,$58,$00,$81,$F9
		.BYTE	$EF,$6D,$00,$81,$FA,$EF,$37,$01,$81,$00,$EF,$2B,$00,$00
_spr_lib2_1D:
		.BYTE	$83,$F8,$E7,$6F,$00,$73,$00,$56,$00,$83,$00,$E7,$71,$00,$75,$00
		.BYTE	$58,$00,$81,$FA,$EF,$39,$01,$00
_spr_lib2_1E:
		.BYTE	$81,$F8,$E7,$4C,$00,$83,$00,$E7,$7E,$00,$2B,$00,$58,$00,$81,$F1
		.BYTE	$EE,$44,$00,$81,$F9,$EF,$77,$00,$81,$FA,$EF,$37,$01,$81,$F8,$F7
		.BYTE	$79,$00,$00
_spr_lib2_1F:
		.BYTE	$81,$F8,$E7,$4C,$00,$83,$00,$E7,$7E,$00,$2B,$00,$58,$00,$81,$F1
		.BYTE	$EE,$44,$00,$81,$F9,$EF,$7B,$00,$81,$FA,$EF,$35,$01,$81,$F8,$F7
		.BYTE	$79,$00,$00
_spr_lib0_14_hud_C_letter:
		.BYTE	$08,$E0,$F8,$A0,$02,$A2,$02,$A4,$02,$A6,$02,$FA,$02,$F5,$02,$F7
		.BYTE	$02,$F9,$02,$02,$E2,$00,$9D,$02,$9F,$02,$81,$E3,$00,$9E,$02,$81
		.BYTE	$F6,$00,$9E,$02,$81,$04,$00,$9D,$02,$81,$07,$00,$9E,$02,$81,$10
		.BYTE	$00,$9F,$02,$81,$17,$00,$9E,$02,$00
_spr_lib5_09:
		.BYTE	$82,$FC,$FD,$DC,$01,$DE,$01,$00
_spr_lib5_0A:
		.BYTE	$82,$FC,$FD,$BE,$81,$BC,$81,$00
_spr_lib5_0B:
		.BYTE	$82,$FC,$FD,$BC,$01,$BE,$01,$00
_spr_lib8_3E:
		.BYTE	$03,$F1,$F2,$D6,$03,$D8,$03,$DA,$03,$81,$F1,$FA,$DC,$03,$81,$01
		.BYTE	$FA,$DE,$03,$00
_spr_lib8_3F:
		.BYTE	$82,$F8,$F0,$C3,$00,$E2,$00,$82,$00,$F0,$C3,$40,$E2,$40,$00
_spr_lib8_40:
		.BYTE	$81,$FB,$F3,$C5,$00,$00
_spr_lib8_41:
		.BYTE	$82,$F8,$F0,$C7,$00,$E6,$00,$82,$00,$F0,$E6,$C0,$C7,$C0,$00
_spr_lib8_42:
		.BYTE	$82,$F8,$F0,$C9,$00,$E8,$00,$82,$00,$F0,$E8,$C0,$C9,$C0,$00
_spr_lib8_43:
		.BYTE	$82,$F8,$F0,$E4,$00,$E4,$80,$82,$00,$F0,$E4,$40,$E4,$C0,$00
_spr_lib8_44:
		.BYTE	$83,$F8,$E3,$CD,$00,$EC,$00,$CF,$00,$83,$00,$E3,$CD,$40,$EC,$40
		.BYTE	$CF,$40,$82,$F0,$E8,$CB,$00,$EA,$00,$82,$08,$E8,$CB,$40,$EA,$40
		.BYTE	$00
_spr_lib8_45:
		.BYTE	$81,$F8,$E0,$D1,$00,$81,$00,$E0,$D1,$40,$82,$F0,$E8,$EE,$00,$EE
		.BYTE	$80,$82,$08,$E8,$EE,$40,$EE,$C0,$02,$F8,$F8,$D1,$80,$D1,$C0,$00
_spr_lib8_46:
		.BYTE	$83,$F8,$E8,$D5,$00,$D3,$00,$F2,$00,$82,$00,$F0,$F0,$00,$F2,$40
		.BYTE	$00,$83,$00,$E8,$D5,$40,$D3,$40,$F2,$40,$82,$F8,$F0,$F0,$40,$F2
		.BYTE	$00,$00
_spr_lib8_47:
		.BYTE	$82,$F8,$F0,$D7,$00,$F6,$00,$82,$00,$F0,$F4,$00,$F8,$00,$00
_spr_lib8_48:
		.BYTE	$82,$F8,$F0,$D9,$02,$DB,$02,$82,$00,$F0,$DB,$C2,$D9,$C2,$00
_spr_lib8_49:
		.BYTE	$04,$F1,$F8,$94,$00,$96,$00,$97,$00,$7E,$00,$82,$F8,$E7,$FD,$02
		.BYTE	$FF,$02,$82,$00,$E7,$FD,$42,$FF,$42,$00
_spr_lib8_4A:
		.BYTE	$82,$F8,$EF,$DD,$03,$FC,$03,$82,$00,$EF,$DF,$03,$FE,$03,$00
_spr_lib8_4B:
		.BYTE	$82,$F8,$EF,$DD,$03,$FC,$03,$82,$00,$EF,$DF,$03,$FE,$03,$81,$FA
		.BYTE	$F2,$E0,$01,$00
_spr_lib8_4C:
		.BYTE	$82,$F8,$EF,$DD,$03,$FC,$03,$82,$00,$EF,$DF,$03,$FE,$03,$81,$FA
		.BYTE	$F2,$BE,$01,$00
_spr_lib8_4D:
		.BYTE	$81,$F8,$F0,$E5,$01,$81,$FB,$F8,$E7,$01,$00
_spr_lib8_4E:
		.BYTE	$84,$F0,$E0,$04,$40,$33,$40,$E9,$03,$EF,$03,$84,$F8,$E0,$25,$40
		.BYTE	$31,$40,$EB,$03,$F1,$03,$81,$F8,$E8,$2D,$41,$81,$00,$F7,$F3,$03
		.BYTE	$00
_spr_lib8_4F:
		.BYTE	$82,$F8,$F0,$F5,$03,$F9,$03,$82,$00,$F0,$F7,$03,$FB,$03,$00
_spr_lib8_50:
		.BYTE	$81,$EF,$E0,$50,$40,$02,$F0,$E8,$6F,$40,$6D,$40,$02,$F0,$F0,$E9
		.BYTE	$03,$EB,$03,$02,$F0,$F8,$EF,$03,$F1,$03,$81,$F5,$E0,$63,$40,$81
		.BYTE	$F8,$E8,$2D,$41,$81,$00,$F7,$F3,$03,$00
_spr_lib8_51:
		.BYTE	$81,$E0,$94,$C1,$02,$81,$D8,$9B,$FA,$02,$00
_spr_lib8_52:
		.BYTE	$02,$00,$03,$92,$00,$92,$40,$00
_spr_lib8_53:
		.BYTE	$02,$F8,$F8,$E1,$03,$E3,$03,$00
_spr_lib8_54:
		.BYTE	$82,$F8,$F0,$ED,$00,$84,$00,$82,$00,$F0,$ED,$40,$84,$40,$00
_spr_lib1_12:
		.BYTE	$81,$07,$F3,$97,$40,$81,$0A,$F7,$9A,$41,$00
_spr_lib1_13:
		.BYTE	$02,$F7,$F7,$98,$40,$96,$40,$02,$FB,$E7,$04,$40,$02,$40,$02,$FC
		.BYTE	$EF,$10,$40,$94,$40,$81,$02,$EF,$00,$41,$81,$07,$F3,$97,$40,$81
		.BYTE	$0A,$F7,$9A,$41,$00
_spr_lib1_14:
		.BYTE	$82,$FF,$E6,$04,$40,$DA,$40,$82,$07,$E6,$02,$40,$D8,$40,$81,$06
		.BYTE	$EE,$00,$41,$81,$0D,$F2,$D4,$40,$81,$FD,$F6,$DB,$40,$81,$05,$F6
		.BYTE	$D9,$40,$81,$0A,$F7,$9A,$41,$81,$FC,$FE,$1C,$40,$00
_spr_lib1_15:
		.BYTE	$03,$F7,$F7,$D7,$40,$D5,$40,$D3,$40,$82,$F9,$E7,$04,$40,$D6,$40
		.BYTE	$82,$01,$E7,$02,$40,$06,$40,$81,$00,$EF,$00,$41,$81,$0A,$F7,$9A
		.BYTE	$41,$00
_spr_lib2_13:
		.BYTE	$02,$F7,$F7,$98,$40,$96,$40,$02,$FA,$E7,$50,$40,$30,$40,$02,$FC
		.BYTE	$EF,$5C,$40,$95,$40,$81,$02,$EF,$00,$41,$81,$07,$F3,$97,$40,$81
		.BYTE	$0A,$F7,$9A,$41,$00
_spr_lib2_14:
		.BYTE	$81,$FE,$E6,$50,$40,$82,$06,$E6,$30,$40,$00,$41,$81,$FF,$EE,$9E
		.BYTE	$40,$81,$07,$EE,$9C,$40,$81,$0D,$F2,$D4,$40,$81,$FD,$F6,$99,$40
		.BYTE	$81,$05,$F6,$D9,$40,$81,$0A,$F7,$9A,$41,$81,$FC,$FE,$1C,$40,$00
_spr_lib2_15:
		.BYTE	$03,$F7,$F7,$DD,$40,$D5,$40,$D3,$40,$02,$F8,$E7,$50,$40,$30,$40
		.BYTE	$02,$F9,$EF,$DC,$40,$52,$40,$81,$00,$EF,$00,$41,$81,$0A,$F7,$9A
		.BYTE	$41,$00
_spr_lib7_57:
		.BYTE	$03,$EF,$E7,$D6,$03,$D8,$03,$DA,$03,$02,$F0,$E9,$DC,$00,$DE,$00
		.BYTE	$02,$F4,$DF,$D2,$03,$D4,$03,$83,$FC,$E7,$C1,$00,$C5,$03,$D3,$01
		.BYTE	$82,$F4,$EF,$C3,$03,$C9,$03,$04,$F4,$F7,$D1,$01,$CB,$03,$CD,$01
		.BYTE	$CF,$01,$81,$04,$EF,$C7,$03,$00
_spr_lib7_58:
		.BYTE	$03,$EB,$E8,$D6,$03,$D8,$03,$DA,$03,$02,$EC,$EA,$DC,$00,$DE,$00
		.BYTE	$03,$EF,$EF,$D5,$03,$D7,$03,$D9,$03,$02,$F0,$E0,$D2,$03,$D4,$03
		.BYTE	$04,$F4,$F7,$DB,$03,$CB,$03,$DD,$01,$CF,$01,$02,$F4,$F7,$D1,$01
		.BYTE	$D3,$01,$81,$F8,$E8,$C1,$00,$00
_spr_lib7_59:
		.BYTE	$82,$FC,$F0,$E6,$01,$E7,$01,$00
_spr_lib7_4B:
		.BYTE	$81,$FC,$F0,$F9,$01,$00
_spr_lib7_69:
		.BYTE	$81,$FC,$F0,$FB,$01,$00
_spr_lib5_04:
		.BYTE	$04,$F0,$F0,$90,$01,$E5,$01,$90,$01,$E5,$01,$04,$F0,$F8,$91,$01
		.BYTE	$93,$01,$91,$01,$93,$01,$83,$FC,$D0,$F4,$01,$F4,$01,$F4,$01,$02
		.BYTE	$F8,$E8,$FC,$01,$FE,$01,$00
_spr_lib0_1C:
		.BYTE	$81,$F0,$DF,$8C,$02,$04,$F0,$F7,$B3,$03,$98,$03,$A2,$02,$9C,$03
		.BYTE	$81,$00,$DF,$27,$02,$83,$00,$E4,$94,$03,$95,$03,$9A,$03,$82,$08
		.BYTE	$E7,$96,$03,$97,$03,$82,$F8,$EF,$93,$03,$A0,$02,$81,$07,$EF,$99
		.BYTE	$02,$00
_spr_lib0_1D:
		.BYTE	$82,$F8,$DF,$9E,$03,$8F,$02,$82,$F8,$DF,$8E,$02,$92,$03,$81,$F0
		.BYTE	$E7,$8D,$02,$00
_spr_lib0_1E:
		.BYTE	$82,$F0,$E7,$90,$03,$91,$03,$00
_spr_lib0_1F:
		.BYTE	$82,$F8,$DF,$29,$03,$92,$03,$82,$F8,$DF,$AC,$02,$8F,$02,$81,$F0
		.BYTE	$E7,$8D,$02,$00
_spr_lib0_20:
		.BYTE	$82,$F8,$DF,$9E,$03,$AD,$02,$81,$F8,$DF,$8E,$02,$81,$F0,$E7,$DF
		.BYTE	$02,$00
_spr_lib0_21:
		.BYTE	$82,$F0,$E7,$90,$03,$B2,$03,$81,$E8,$F1,$B0,$02,$00
_spr_lib0_22:
		.BYTE	$81,$E8,$E1,$AE,$02,$02,$E8,$E7,$AF,$03,$B1,$03,$81,$F0,$EF,$ED
		.BYTE	$03,$00
_spr_lib0_23:
		.BYTE	$84,$F0,$DF,$8C,$02,$8D,$02,$91,$03,$B3,$03,$84,$F8,$DF,$8E,$02
		.BYTE	$8F,$02,$93,$03,$A4,$03,$82,$F8,$DF,$9E,$03,$92,$03,$81,$00,$DF
		.BYTE	$27,$02,$83,$00,$E4,$94,$03,$95,$03,$9A,$03,$81,$F0,$E7,$90,$03
		.BYTE	$83,$08,$E7,$96,$03,$97,$03,$9C,$03,$03,$F5,$F7,$DA,$02,$DB,$02
		.BYTE	$DC,$02,$81,$07,$EF,$99,$02,$00
_spr_lib0_24:
		.BYTE	$84,$F0,$DE,$8C,$02,$8D,$02,$91,$03,$B3,$03,$84,$F8,$DE,$8E,$02
		.BYTE	$8F,$02,$93,$03,$98,$03,$82,$F8,$DE,$9E,$03,$92,$03,$81,$00,$DE
		.BYTE	$27,$02,$83,$00,$E3,$94,$03,$95,$03,$9A,$03,$81,$F0,$E6,$90,$03
		.BYTE	$83,$08,$E6,$96,$03,$97,$03,$9C,$03,$02,$F8,$F7,$A6,$02,$A8,$02
		.BYTE	$81,$07,$EE,$99,$02,$00
_spr_lib0_25:
		.BYTE	$84,$F0,$DF,$8C,$02,$8D,$02,$91,$03,$B3,$03,$84,$F8,$DF,$8E,$02
		.BYTE	$8F,$02,$93,$03,$DD,$02,$82,$F8,$DF,$9E,$03,$92,$03,$81,$00,$DF
		.BYTE	$27,$02,$83,$00,$E4,$94,$03,$95,$03,$9A,$03,$81,$F0,$E7,$90,$03
		.BYTE	$83,$08,$E7,$96,$03,$97,$03,$9C,$03,$02,$F8,$F7,$AA,$03,$DE,$02
		.BYTE	$81,$07,$EF,$99,$02,$00
_spr_lib0_26:
		.BYTE	$81,$F6,$DE,$B4,$04,$00
_spr_lib0_27:
		.BYTE	$81,$F6,$DE,$B5,$04,$00
_spr_lib0_1B:
		.BYTE	$81,$E8,$E1,$AE,$02,$02,$E8,$E7,$AF,$03,$84,$03,$81,$F0,$EF,$ED
		.BYTE	$03,$00
_spr_lib0_28:
		.BYTE	$03,$F0,$DF,$B6,$02,$B8,$02,$BA,$02,$81,$F8,$DF,$C2,$03,$83,$00
		.BYTE	$E7,$BB,$02,$EE,$02,$EF,$02,$81,$F8,$F7,$BF,$00,$81,$F8,$F7,$C1
		.BYTE	$01,$00
_spr_lib0_29:
		.BYTE	$83,$F0,$DF,$B6,$02,$B7,$02,$BC,$02,$84,$F8,$DF,$B8,$02,$B9,$02
		.BYTE	$BE,$02,$C6,$01,$83,$F8,$DF,$C2,$03,$C3,$01,$C0,$01,$83,$00,$DF
		.BYTE	$BA,$02,$BB,$02,$EE,$02,$02,$F4,$F7,$C5,$00,$C7,$00,$00
_spr_lib0_2A:
		.BYTE	$84,$F8,$DE,$C2,$03,$C3,$01,$C0,$01,$CC,$01,$83,$F8,$DE,$B8,$02
		.BYTE	$B9,$02,$BE,$02,$83,$00,$DE,$BA,$02,$BB,$02,$EE,$02,$81,$F0,$E1
		.BYTE	$C8,$02,$82,$F0,$E6,$B7,$02,$BC,$02,$82,$F7,$F6,$C9,$00,$CA,$02
		.BYTE	$81,$FF,$F6,$CB,$00,$00
_spr_lib0_2B:
		.BYTE	$83,$F0,$DF,$B6,$02,$B7,$02,$BC,$02,$84,$F8,$DF,$B8,$02,$B9,$02
		.BYTE	$BE,$02,$CE,$01,$83,$F8,$DF,$C2,$03,$C3,$01,$C0,$01,$83,$00,$DF
		.BYTE	$BA,$02,$BB,$02,$EE,$02,$02,$F5,$F7,$CD,$00,$CF,$00,$00
_spr_lib0_2C:
		.BYTE	$02,$F0,$E7,$D0,$02,$D2,$02,$81,$F8,$EF,$C0,$01,$81,$F8,$EF,$BE
		.BYTE	$02,$00
_spr_lib0_2D:
		.BYTE	$02,$F0,$E7,$B7,$02,$B9,$02,$82,$F8,$E7,$C3,$01,$F0,$01,$81,$F8
		.BYTE	$EF,$D4,$02,$00
_spr_lib0_2E:
		.BYTE	$02,$F0,$E7,$B7,$02,$C3,$01,$82,$F8,$E7,$B9,$02,$D5,$01,$81,$F0
		.BYTE	$EC,$D1,$02,$81,$F8,$EF,$D3,$02,$00
_spr_lib0_2F:
		.BYTE	$02,$F0,$E7,$B7,$02,$C3,$01,$82,$F8,$E7,$B9,$02,$D6,$02,$81,$F0
		.BYTE	$EC,$D1,$02,$81,$F8,$EF,$F1,$01,$00
_spr_lib0_30:
		.BYTE	$81,$F8,$E8,$D7,$01,$00
_spr_lib0_31:
		.BYTE	$81,$F7,$E8,$D8,$02,$00
_spr_lib0_34:
		.BYTE	$82,$F8,$F0,$D9,$03,$A5,$03,$82,$00,$F0,$A3,$03,$A7,$03,$81,$FE
		.BYTE	$F8,$A9,$00,$00
_spr_lib0_35:
		.BYTE	$82,$F8,$F0,$D9,$03,$A5,$03,$82,$00,$F0,$AB,$03,$A7,$03,$81,$FE
		.BYTE	$F8,$A9,$00,$00
_spr_lib0_36:
		.BYTE	$81,$F9,$F0,$E0,$01,$00
_spr_lib0_37:
		.BYTE	$81,$F9,$F0,$E1,$03,$00
_spr_lib0_38:
		.BYTE	$82,$F8,$EF,$E2,$00,$E3,$00,$82,$00,$EF,$E4,$00,$E5,$00,$00
_spr_lib0_39:
		.BYTE	$82,$F8,$EF,$E6,$01,$E7,$01,$82,$00,$EF,$E7,$C1,$E6,$C1,$00
_spr_lib0_3A:
		.BYTE	$82,$F8,$EF,$E8,$01,$E9,$01,$82,$00,$EF,$E8,$41,$E9,$41,$00
_spr_lib0_3B:
		.BYTE	$82,$F8,$EF,$EA,$01,$EB,$01,$82,$00,$EF,$EA,$41,$EB,$41,$00
_spr_lib0_3C:
		.BYTE	$81,$00,$F7,$F2,$01,$00
_spr_lib0_3D:
		.BYTE	$02,$F8,$F8,$F3,$03,$F5,$03,$00
_spr_lib0_3E:
		.BYTE	$02,$F8,$F8,$F3,$83,$F5,$83,$00
_spr_lib0_3F:
		.BYTE	$82,$F8,$F2,$F4,$00,$FF,$00,$00
_spr_lib0_40:
		.BYTE	$81,$F8,$F8,$F4,$00,$00
_spr_lib0_41:
		.BYTE	$82,$F8,$F0,$F6,$01,$F7,$01,$82,$00,$F0,$F8,$01,$F9,$01,$00
_spr_lib0_42:
		.BYTE	$82,$F8,$EF,$FA,$02,$FB,$02,$82,$00,$EF,$FC,$02,$FD,$02,$00
_spr_lib0_43:
		.BYTE	$02,$F8,$F7,$85,$02,$25,$02,$00
_spr_lib0_32:
		.BYTE	$82,$F0,$EF,$BC,$02,$BD,$02,$00
_spr_lib0_33:
		.BYTE	$02,$F0,$E7,$B7,$02,$B9,$02,$82,$F8,$E7,$C3,$01,$C0,$01,$81,$F8
		.BYTE	$EF,$BE,$02,$00
_spr_lib5_46:
		.BYTE	$82,$F8,$F0,$F9,$01,$FB,$01,$82,$00,$F0,$F9,$41,$FB,$41,$00
_spr_lib5_47:
		.BYTE	$82,$F8,$F0,$FD,$01,$FF,$01,$82,$00,$F0,$FD,$41,$FF,$41,$00
_spr_lib7_71:
		.BYTE	$03,$F4,$E8,$C9,$03,$CB,$03,$CD,$03,$03,$F4,$F0,$CF,$03,$D1,$03
		.BYTE	$D3,$03,$81,$F5,$F0,$D9,$01,$02,$F8,$F8,$D5,$03,$D7,$03,$00
_spr_lib7_72:
		.BYTE	$82,$F4,$E8,$DB,$03,$CF,$03,$81,$F5,$F0,$D9,$01,$02,$F8,$F8,$D5
		.BYTE	$03,$E0,$03,$02,$FC,$F0,$DD,$03,$DF,$03,$00
_spr_lib7_73:
		.BYTE	$81,$FC,$F8,$E2,$02,$00
_spr_lib7_7B:
		.BYTE	$81,$FC,$F8,$E4,$02,$00
_spr_lib5_06:
		.BYTE	$04,$00,$08,$E9,$01,$EF,$01,$EF,$01,$E9,$41,$00
_spr_lib5_07:
		.BYTE	$02,$00,$08,$86,$01,$F0,$01,$81,$10,$07,$F0,$C1,$81,$18,$08,$86
		.BYTE	$41,$00
_spr_lib5_12:
		.BYTE	$81,$FF,$F7,$F2,$81,$00
_spr_lib5_1A:
		.BYTE	$81,$FA,$FB,$F2,$41,$00

		SECTION_END		0C, "SPRITES DATA"

		BANK_END 5,$C000
