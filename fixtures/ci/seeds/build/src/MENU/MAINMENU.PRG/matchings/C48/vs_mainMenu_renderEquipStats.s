nonmatching vs_mainMenu_renderEquipStats, 0x364

glabel vs_mainMenu_renderEquipStats
    /* 26A4 800FBEA4 C8FFBD27 */  addiu      $sp, $sp, -0x38
    /* 26A8 800FBEA8 21288000 */  addu       $a1, $a0, $zero
    /* 26AC 800FBEAC 1800B2AF */  sw         $s2, 0x18($sp)
    /* 26B0 800FBEB0 7E00123C */  lui        $s2, (0x7E00F8 >> 16)
    /* 26B4 800FBEB4 F8005236 */  ori        $s2, $s2, (0x7E00F8 & 0xFFFF)
    /* 26B8 800FBEB8 0F80033C */  lui        $v1, %hi(vs_battle_actors)
    /* 26BC 800FBEBC 1080023C */  lui        $v0, %hi(D_8010248E)
    /* 26C0 800FBEC0 8E244284 */  lh         $v0, %lo(D_8010248E)($v0)
    /* 26C4 800FBEC4 28196324 */  addiu      $v1, $v1, %lo(vs_battle_actors)
    /* 26C8 800FBEC8 3400BFAF */  sw         $ra, 0x34($sp)
    /* 26CC 800FBECC 3000BEAF */  sw         $fp, 0x30($sp)
    /* 26D0 800FBED0 2C00B7AF */  sw         $s7, 0x2C($sp)
    /* 26D4 800FBED4 2800B6AF */  sw         $s6, 0x28($sp)
    /* 26D8 800FBED8 2400B5AF */  sw         $s5, 0x24($sp)
    /* 26DC 800FBEDC 2000B4AF */  sw         $s4, 0x20($sp)
    /* 26E0 800FBEE0 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 26E4 800FBEE4 1400B1AF */  sw         $s1, 0x14($sp)
    /* 26E8 800FBEE8 1000B0AF */  sw         $s0, 0x10($sp)
    /* 26EC 800FBEEC 80100200 */  sll        $v0, $v0, 2
    /* 26F0 800FBEF0 21104300 */  addu       $v0, $v0, $v1
    /* 26F4 800FBEF4 801F033C */  lui        $v1, (0x1F800004 >> 16)
    /* 26F8 800FBEF8 0400638C */  lw         $v1, (0x1F800004 & 0xFFFF)($v1)
    /* 26FC 800FBEFC 0000428C */  lw         $v0, 0x0($v0)
    /* 2700 800FBF00 00000000 */  nop
    /* 2704 800FBF04 3C00568C */  lw         $s6, 0x3C($v0)
    /* 2708 800FBF08 0C00A010 */  beqz       $a1, .L800FBF3C
    /* 270C 800FBF0C E8FF7424 */   addiu     $s4, $v1, -0x18
    /* 2710 800FBF10 1080033C */  lui        $v1, %hi(D_80102130)
    /* 2714 800FBF14 30216290 */  lbu        $v0, %lo(D_80102130)($v1)
    /* 2718 800FBF18 00000000 */  nop
    /* 271C 800FBF1C AE004510 */  beq        $v0, $a1, .L800FC1D8
    /* 2720 800FBF20 1080043C */   lui       $a0, %hi(D_80102131)
    /* 2724 800FBF24 302165A0 */  sb         $a1, %lo(D_80102130)($v1)
    /* 2728 800FBF28 80180500 */  sll        $v1, $a1, 2
    /* 272C 800FBF2C 0F000224 */  addiu      $v0, $zero, 0xF
    /* 2730 800FBF30 23104300 */  subu       $v0, $v0, $v1
    /* 2734 800FBF34 76F00308 */  j          .L800FC1D8
    /* 2738 800FBF38 312182A0 */   sb        $v0, %lo(D_80102131)($a0)
  .L800FBF3C:
    /* 273C 800FBF3C 1080043C */  lui        $a0, %hi(D_801024AE)
    /* 2740 800FBF40 1080023C */  lui        $v0, %hi(D_80102130)
    /* 2744 800FBF44 01000324 */  addiu      $v1, $zero, 0x1
    /* 2748 800FBF48 30214290 */  lbu        $v0, %lo(D_80102130)($v0)
    /* 274C 800FBF4C AE249E84 */  lh         $fp, %lo(D_801024AE)($a0)
    /* 2750 800FBF50 0D004314 */  bne        $v0, $v1, .L800FBF88
    /* 2754 800FBF54 1080043C */   lui       $a0, %hi(D_80102131)
    /* 2758 800FBF58 31218290 */  lbu        $v0, %lo(D_80102131)($a0)
    /* 275C 800FBF5C 00000000 */  nop
    /* 2760 800FBF60 13004010 */  beqz       $v0, .L800FBFB0
    /* 2764 800FBF64 0F80023C */   lui       $v0, %hi(vs_battle_rowAnimationSteps)
    /* 2768 800FBF68 31218390 */  lbu        $v1, %lo(D_80102131)($a0)
    /* 276C 800FBF6C C8BB4224 */  addiu      $v0, $v0, %lo(vs_battle_rowAnimationSteps)
    /* 2770 800FBF70 21106200 */  addu       $v0, $v1, $v0
    /* 2774 800FBF74 00004290 */  lbu        $v0, 0x0($v0)
    /* 2778 800FBF78 FFFF6324 */  addiu      $v1, $v1, -0x1
    /* 277C 800FBF7C 312183A0 */  sb         $v1, %lo(D_80102131)($a0)
    /* 2780 800FBF80 ECEF0308 */  j          .L800FBFB0
    /* 2784 800FBF84 21905200 */   addu      $s2, $v0, $s2
  .L800FBF88:
    /* 2788 800FBF88 31218290 */  lbu        $v0, %lo(D_80102131)($a0)
    /* 278C 800FBF8C 00000000 */  nop
    /* 2790 800FBF90 91004010 */  beqz       $v0, .L800FC1D8
    /* 2794 800FBF94 21184000 */   addu      $v1, $v0, $zero
    /* 2798 800FBF98 08000224 */  addiu      $v0, $zero, 0x8
    /* 279C 800FBF9C 23104300 */  subu       $v0, $v0, $v1
    /* 27A0 800FBFA0 40110200 */  sll        $v0, $v0, 5
    /* 27A4 800FBFA4 21905200 */  addu       $s2, $v0, $s2
    /* 27A8 800FBFA8 FFFF6324 */  addiu      $v1, $v1, -0x1
    /* 27AC 800FBFAC 312183A0 */  sb         $v1, %lo(D_80102131)($a0)
  .L800FBFB0:
    /* 27B0 800FBFB0 1080023C */  lui        $v0, %hi(D_80102480)
    /* 27B4 800FBFB4 80245024 */  addiu      $s0, $v0, %lo(D_80102480)
    /* 27B8 800FBFB8 03000292 */  lbu        $v0, 0x3($s0)
    /* 27BC 800FBFBC 00000000 */  nop
    /* 27C0 800FBFC0 34004010 */  beqz       $v0, .L800FC094
    /* 27C4 800FBFC4 1080043C */   lui       $a0, %hi(D_800F9918)
    /* 27C8 800FBFC8 18998424 */  addiu      $a0, $a0, %lo(D_800F9918)
    /* 27CC 800FBFCC 04004526 */  addiu      $a1, $s2, 0x4
    /* 27D0 800FBFD0 0A1A030C */  jal        vs_battle_renderTextRaw
    /* 27D4 800FBFD4 21308002 */   addu      $a2, $s4, $zero
    /* 27D8 800FBFD8 21980000 */  addu       $s3, $zero, $zero
    /* 27DC 800FBFDC 21B80002 */  addu       $s7, $s0, $zero
    /* 27E0 800FBFE0 1080023C */  lui        $v0, %hi(D_800F9920)
    /* 27E4 800FBFE4 20995524 */  addiu      $s5, $v0, %lo(D_800F9920)
    /* 27E8 800FBFE8 1080023C */  lui        $v0, %hi(D_801020FC)
    /* 27EC 800FBFEC FC205124 */  addiu      $s1, $v0, %lo(D_801020FC)
  .L800FBFF0:
    /* 27F0 800FBFF0 0A00023C */  lui        $v0, %hi(D_A001C)
    /* 27F4 800FBFF4 21904202 */  addu       $s2, $s2, $v0
    /* 27F8 800FBFF8 0000248E */  lw         $a0, 0x0($s1)
    /* 27FC 800FBFFC 21284002 */  addu       $a1, $s2, $zero
    /* 2800 800FC000 0A1A030C */  jal        vs_battle_renderTextRaw
    /* 2804 800FC004 21308002 */   addu      $a2, $s4, $zero
    /* 2808 800FC008 1300C013 */  beqz       $fp, .L800FC058
    /* 280C 800FC00C 21107702 */   addu      $v0, $s3, $s7
    /* 2810 800FC010 00005090 */  lbu        $s0, 0x0($v0)
    /* 2814 800FC014 1C004526 */  addiu      $a1, $s2, %lo(D_A001C)
    /* 2818 800FC018 21308002 */  addu       $a2, $s4, $zero
    /* 281C 800FC01C 9CFF030C */  jal        func_800FFE70
    /* 2820 800FC020 21200002 */   addu      $a0, $s0, $zero
    /* 2824 800FC024 07006016 */  bnez       $s3, .L800FC044
    /* 2828 800FC028 21200002 */   addu      $a0, $s0, $zero
    /* 282C 800FC02C 3800C292 */  lbu        $v0, 0x38($s6)
    /* 2830 800FC030 6001C392 */  lbu        $v1, 0x160($s6)
    /* 2834 800FC034 00000000 */  nop
    /* 2838 800FC038 23104300 */  subu       $v0, $v0, $v1
    /* 283C 800FC03C 21800202 */  addu       $s0, $s0, $v0
    /* 2840 800FC040 21200002 */  addu       $a0, $s0, $zero
  .L800FC044:
    /* 2844 800FC044 3C004526 */  addiu      $a1, $s2, %lo(D_A003C)
    /* 2848 800FC048 9CFF030C */  jal        func_800FFE70
    /* 284C 800FC04C 21308002 */   addu      $a2, $s4, $zero
    /* 2850 800FC050 1FF00308 */  j          .L800FC07C
    /* 2854 800FC054 04003126 */   addiu     $s1, $s1, 0x4
  .L800FC058:
    /* 2858 800FC058 2120A002 */  addu       $a0, $s5, $zero
    /* 285C 800FC05C 1C004526 */  addiu      $a1, $s2, %lo(D_A001C)
    /* 2860 800FC060 0A1A030C */  jal        vs_battle_renderTextRaw
    /* 2864 800FC064 21308002 */   addu      $a2, $s4, $zero
    /* 2868 800FC068 2120A002 */  addu       $a0, $s5, $zero
    /* 286C 800FC06C 3C004526 */  addiu      $a1, $s2, %lo(D_A003C)
    /* 2870 800FC070 0A1A030C */  jal        vs_battle_renderTextRaw
    /* 2874 800FC074 21308002 */   addu      $a2, $s4, $zero
    /* 2878 800FC078 04003126 */  addiu      $s1, $s1, 0x4
  .L800FC07C:
    /* 287C 800FC07C 01007326 */  addiu      $s3, $s3, 0x1
    /* 2880 800FC080 0200622A */  slti       $v0, $s3, 0x2
    /* 2884 800FC084 DAFF4014 */  bnez       $v0, .L800FBFF0
    /* 2888 800FC088 00000000 */   nop
    /* 288C 800FC08C 2CF00308 */  j          .L800FC0B0
    /* 2890 800FC090 21980000 */   addu      $s3, $zero, $zero
  .L800FC094:
    /* 2894 800FC094 1400023C */  lui        $v0, %hi(D_140004)
    /* 2898 800FC098 21904202 */  addu       $s2, $s2, $v0
    /* 289C 800FC09C 18998424 */  addiu      $a0, $a0, %lo(D_800F9918)
    /* 28A0 800FC0A0 04004526 */  addiu      $a1, $s2, %lo(D_140004)
    /* 28A4 800FC0A4 0A1A030C */  jal        vs_battle_renderTextRaw
    /* 28A8 800FC0A8 21308002 */   addu      $a2, $s4, $zero
    /* 28AC 800FC0AC 21980000 */  addu       $s3, $zero, $zero
  .L800FC0B0:
    /* 28B0 800FC0B0 1080173C */  lui        $s7, %hi(D_80102488)
    /* 28B4 800FC0B4 8824F726 */  addiu      $s7, $s7, %lo(D_80102488)
    /* 28B8 800FC0B8 08001524 */  addiu      $s5, $zero, 0x8
    /* 28BC 800FC0BC 1080163C */  lui        $s6, %hi(vs_mainMenu_strIntAgi)
    /* 28C0 800FC0C0 A824D626 */  addiu      $s6, $s6, %lo(vs_mainMenu_strIntAgi)
  .L800FC0C4:
    /* 28C4 800FC0C4 0A00043C */  lui        $a0, (0xA0000 >> 16)
    /* 28C8 800FC0C8 1080023C */  lui        $v0, %hi(vs_mainMenu_equipmentSubtype)
    /* 28CC 800FC0CC 45254390 */  lbu        $v1, %lo(vs_mainMenu_equipmentSubtype)($v0)
    /* 28D0 800FC0D0 21904402 */  addu       $s2, $s2, $a0
    /* 28D4 800FC0D4 07006230 */  andi       $v0, $v1, 0x7
    /* 28D8 800FC0D8 2B100200 */  sltu       $v0, $zero, $v0
    /* 28DC 800FC0DC 80200200 */  sll        $a0, $v0, 2
    /* 28E0 800FC0E0 18006330 */  andi       $v1, $v1, 0x18
    /* 28E4 800FC0E4 04006010 */  beqz       $v1, .L800FC0F8
    /* 28E8 800FC0E8 21108000 */   addu      $v0, $a0, $zero
    /* 28EC 800FC0EC 08006226 */  addiu      $v0, $s3, 0x8
    /* 28F0 800FC0F0 3FF00308 */  j          .L800FC0FC
    /* 28F4 800FC0F4 21108200 */   addu      $v0, $a0, $v0
  .L800FC0F8:
    /* 28F8 800FC0F8 21105300 */  addu       $v0, $v0, $s3
  .L800FC0FC:
    /* 28FC 800FC0FC 80100200 */  sll        $v0, $v0, 2
    /* 2900 800FC100 1080083C */  lui        $t0, %hi(D_80102104)
    /* 2904 800FC104 04210825 */  addiu      $t0, $t0, %lo(D_80102104)
    /* 2908 800FC108 21100201 */  addu       $v0, $t0, $v0
    /* 290C 800FC10C 0000448C */  lw         $a0, 0x0($v0)
    /* 2910 800FC110 21284002 */  addu       $a1, $s2, $zero
    /* 2914 800FC114 0A1A030C */  jal        vs_battle_renderTextRaw
    /* 2918 800FC118 21308002 */   addu      $a2, $s4, $zero
    /* 291C 800FC11C 1F00C013 */  beqz       $fp, .L800FC19C
    /* 2920 800FC120 1C004526 */   addiu     $a1, $s2, %lo(D_14001C)
    /* 2924 800FC124 21388002 */  addu       $a3, $s4, $zero
    /* 2928 800FC128 1080083C */  lui        $t0, %hi(vs_mainMenu_strIntAgi)
    /* 292C 800FC12C A8240825 */  addiu      $t0, $t0, %lo(vs_mainMenu_strIntAgi)
    /* 2930 800FC130 2110A802 */  addu       $v0, $s5, $t0
    /* 2934 800FC134 0000D086 */  lh         $s0, 0x0($s6)
    /* 2938 800FC138 00004684 */  lh         $a2, 0x0($v0)
    /* 293C 800FC13C 88FF030C */  jal        func_800FFE20
    /* 2940 800FC140 21200002 */   addu      $a0, $s0, $zero
    /* 2944 800FC144 0100C733 */  andi       $a3, $fp, 0x1
    /* 2948 800FC148 1080083C */  lui        $t0, %hi(D_80102488)
    /* 294C 800FC14C 88240825 */  addiu      $t0, $t0, %lo(D_80102488)
    /* 2950 800FC150 2110A802 */  addu       $v0, $s5, $t0
    /* 2954 800FC154 40881300 */  sll        $s1, $s3, 1
    /* 2958 800FC158 00004284 */  lh         $v0, 0x0($v0)
    /* 295C 800FC15C 0000E386 */  lh         $v1, 0x0($s7)
    /* 2960 800FC160 21300202 */  addu       $a2, $s0, $v0
    /* 2964 800FC164 0500E010 */  beqz       $a3, .L800FC17C
    /* 2968 800FC168 21800302 */   addu      $s0, $s0, $v1
    /* 296C 800FC16C 1080023C */  lui        $v0, %hi(D_80102498)
    /* 2970 800FC170 98244224 */  addiu      $v0, $v0, %lo(D_80102498)
    /* 2974 800FC174 21102202 */  addu       $v0, $s1, $v0
    /* 2978 800FC178 00004784 */  lh         $a3, 0x0($v0)
  .L800FC17C:
    /* 297C 800FC17C 00000000 */  nop
    /* 2980 800FC180 21200702 */  addu       $a0, $s0, $a3
    /* 2984 800FC184 3C004526 */  addiu      $a1, $s2, %lo(D_14003C)
    /* 2988 800FC188 2130C700 */  addu       $a2, $a2, $a3
    /* 298C 800FC18C 88FF030C */  jal        func_800FFE20
    /* 2990 800FC190 21388002 */   addu      $a3, $s4, $zero
    /* 2994 800FC194 71F00308 */  j          .L800FC1C4
    /* 2998 800FC198 0200F726 */   addiu     $s7, $s7, 0x2
  .L800FC19C:
    /* 299C 800FC19C 1080043C */  lui        $a0, %hi(D_800F9920)
    /* 29A0 800FC1A0 20998424 */  addiu      $a0, $a0, %lo(D_800F9920)
    /* 29A4 800FC1A4 0A1A030C */  jal        vs_battle_renderTextRaw
    /* 29A8 800FC1A8 21308002 */   addu      $a2, $s4, $zero
    /* 29AC 800FC1AC 1080043C */  lui        $a0, %hi(D_800F9920)
    /* 29B0 800FC1B0 20998424 */  addiu      $a0, $a0, %lo(D_800F9920)
    /* 29B4 800FC1B4 3C004526 */  addiu      $a1, $s2, %lo(D_14003C)
    /* 29B8 800FC1B8 0A1A030C */  jal        vs_battle_renderTextRaw
    /* 29BC 800FC1BC 21308002 */   addu      $a2, $s4, $zero
    /* 29C0 800FC1C0 0200F726 */  addiu      $s7, $s7, 0x2
  .L800FC1C4:
    /* 29C4 800FC1C4 0200B526 */  addiu      $s5, $s5, 0x2
    /* 29C8 800FC1C8 01007326 */  addiu      $s3, $s3, 0x1
    /* 29CC 800FC1CC 0300622A */  slti       $v0, $s3, 0x3
    /* 29D0 800FC1D0 BCFF4014 */  bnez       $v0, .L800FC0C4
    /* 29D4 800FC1D4 0200D626 */   addiu     $s6, $s6, 0x2
  .L800FC1D8:
    /* 29D8 800FC1D8 3400BF8F */  lw         $ra, 0x34($sp)
    /* 29DC 800FC1DC 3000BE8F */  lw         $fp, 0x30($sp)
    /* 29E0 800FC1E0 2C00B78F */  lw         $s7, 0x2C($sp)
    /* 29E4 800FC1E4 2800B68F */  lw         $s6, 0x28($sp)
    /* 29E8 800FC1E8 2400B58F */  lw         $s5, 0x24($sp)
    /* 29EC 800FC1EC 2000B48F */  lw         $s4, 0x20($sp)
    /* 29F0 800FC1F0 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 29F4 800FC1F4 1800B28F */  lw         $s2, 0x18($sp)
    /* 29F8 800FC1F8 1400B18F */  lw         $s1, 0x14($sp)
    /* 29FC 800FC1FC 1000B08F */  lw         $s0, 0x10($sp)
    /* 2A00 800FC200 0800E003 */  jr         $ra
    /* 2A04 800FC204 3800BD27 */   addiu     $sp, $sp, 0x38
endlabel vs_mainMenu_renderEquipStats
