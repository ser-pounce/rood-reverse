nonmatching func_8008DF14, 0x288

glabel func_8008DF14
    /* 25714 8008DF14 C8FFBD27 */  addiu      $sp, $sp, -0x38
    /* 25718 8008DF18 0F80023C */  lui        $v0, %hi(vs_battle_roomData)
    /* 2571C 8008DF1C F81B4224 */  addiu      $v0, $v0, %lo(vs_battle_roomData)
    /* 25720 8008DF20 3400BFAF */  sw         $ra, 0x34($sp)
    /* 25724 8008DF24 3000BEAF */  sw         $fp, 0x30($sp)
    /* 25728 8008DF28 2C00B7AF */  sw         $s7, 0x2C($sp)
    /* 2572C 8008DF2C 2800B6AF */  sw         $s6, 0x28($sp)
    /* 25730 8008DF30 2400B5AF */  sw         $s5, 0x24($sp)
    /* 25734 8008DF34 2000B4AF */  sw         $s4, 0x20($sp)
    /* 25738 8008DF38 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 2573C 8008DF3C 1800B2AF */  sw         $s2, 0x18($sp)
    /* 25740 8008DF40 1400B1AF */  sw         $s1, 0x14($sp)
    /* 25744 8008DF44 1000B0AF */  sw         $s0, 0x10($sp)
    /* 25748 8008DF48 8400448C */  lw         $a0, 0x84($v0)
    /* 2574C 8008DF4C 00000000 */  nop
    /* 25750 8008DF50 86008010 */  beqz       $a0, .L8008E16C
    /* 25754 8008DF54 21988000 */   addu      $s3, $a0, $zero
    /* 25758 8008DF58 2400438C */  lw         $v1, 0x24($v0)
    /* 2575C 8008DF5C AAAA023C */  lui        $v0, (0xAAAAAAAB >> 16)
    /* 25760 8008DF60 ABAA4234 */  ori        $v0, $v0, (0xAAAAAAAB & 0xFFFF)
    /* 25764 8008DF64 19006200 */  multu      $v1, $v0
    /* 25768 8008DF68 01001224 */  addiu      $s2, $zero, 0x1
    /* 2576C 8008DF6C 10480000 */  mfhi       $t1
    /* 25770 8008DF70 C2A80900 */  srl        $s5, $t1, 3
    /* 25774 8008DF74 7D00A012 */  beqz       $s5, .L8008E16C
    /* 25778 8008DF78 21A00000 */   addu      $s4, $zero, $zero
    /* 2577C 8008DF7C 0680023C */  lui        $v0, %hi(vs_main_stateFlags)
    /* 25780 8008DF80 98155E24 */  addiu      $fp, $v0, %lo(vs_main_stateFlags)
    /* 25784 8008DF84 0680173C */  lui        $s7, %hi(vs_gametime_tickspeed)
    /* 25788 8008DF88 0F80163C */  lui        $s6, %hi(D_800F1D6C)
    /* 2578C 8008DF8C 0B007126 */  addiu      $s1, $s3, 0xB
  .L8008DF90:
    /* 25790 8008DF90 2000C293 */  lbu        $v0, 0x20($fp)
    /* 25794 8008DF94 00000000 */  nop
    /* 25798 8008DF98 1C004014 */  bnez       $v0, .L8008E00C
    /* 2579C 8008DF9C 00000000 */   nop
    /* 257A0 8008DFA0 4000C293 */  lbu        $v0, 0x40($fp)
    /* 257A4 8008DFA4 00000000 */  nop
    /* 257A8 8008DFA8 18004014 */  bnez       $v0, .L8008E00C
    /* 257AC 8008DFAC 00000000 */   nop
    /* 257B0 8008DFB0 FFFF2292 */  lbu        $v0, -0x1($s1)
    /* 257B4 8008DFB4 00000000 */  nop
    /* 257B8 8008DFB8 14004010 */  beqz       $v0, .L8008E00C
    /* 257BC 8008DFBC 00000000 */   nop
    /* 257C0 8008DFC0 4CE2E28E */  lw         $v0, %lo(vs_gametime_tickspeed)($s7)
    /* 257C4 8008DFC4 00000000 */  nop
    /* 257C8 8008DFC8 40100200 */  sll        $v0, $v0, 1
    /* 257CC 8008DFCC 1E004018 */  blez       $v0, .L8008E048
    /* 257D0 8008DFD0 21300000 */   addu      $a2, $zero, $zero
    /* 257D4 8008DFD4 0680043C */  lui        $a0, %hi(vs_gametime_tickspeed)
  .L8008DFD8:
    /* 257D8 8008DFD8 00002282 */  lb         $v0, 0x0($s1)
    /* 257DC 8008DFDC 00002392 */  lbu        $v1, 0x0($s1)
    /* 257E0 8008DFE0 02004004 */  bltz       $v0, .L8008DFEC
    /* 257E4 8008DFE4 01006224 */   addiu     $v0, $v1, 0x1
    /* 257E8 8008DFE8 000022A2 */  sb         $v0, 0x0($s1)
  .L8008DFEC:
    /* 257EC 8008DFEC 4CE2828C */  lw         $v0, %lo(vs_gametime_tickspeed)($a0)
    /* 257F0 8008DFF0 0100C624 */  addiu      $a2, $a2, 0x1
    /* 257F4 8008DFF4 40100200 */  sll        $v0, $v0, 1
    /* 257F8 8008DFF8 2A10C200 */  slt        $v0, $a2, $v0
    /* 257FC 8008DFFC 12004010 */  beqz       $v0, .L8008E048
    /* 25800 8008E000 00000000 */   nop
    /* 25804 8008E004 F6370208 */  j          .L8008DFD8
    /* 25808 8008E008 00000000 */   nop
  .L8008E00C:
    /* 2580C 8008E00C 4CE2E28E */  lw         $v0, %lo(vs_gametime_tickspeed)($s7)
    /* 25810 8008E010 00000000 */  nop
    /* 25814 8008E014 0C004018 */  blez       $v0, .L8008E048
    /* 25818 8008E018 21300000 */   addu      $a2, $zero, $zero
    /* 2581C 8008E01C 0680033C */  lui        $v1, %hi(vs_gametime_tickspeed)
  .L8008E020:
    /* 25820 8008E020 00002292 */  lbu        $v0, 0x0($s1)
    /* 25824 8008E024 00000000 */  nop
    /* 25828 8008E028 02004010 */  beqz       $v0, .L8008E034
    /* 2582C 8008E02C FFFF4224 */   addiu     $v0, $v0, -0x1
    /* 25830 8008E030 000022A2 */  sb         $v0, 0x0($s1)
  .L8008E034:
    /* 25834 8008E034 4CE2628C */  lw         $v0, %lo(vs_gametime_tickspeed)($v1)
    /* 25838 8008E038 0100C624 */  addiu      $a2, $a2, 0x1
    /* 2583C 8008E03C 2A10C200 */  slt        $v0, $a2, $v0
    /* 25840 8008E040 F7FF4014 */  bnez       $v0, .L8008E020
    /* 25844 8008E044 00000000 */   nop
  .L8008E048:
    /* 25848 8008E048 00002292 */  lbu        $v0, 0x0($s1)
    /* 2584C 8008E04C 00000000 */  nop
    /* 25850 8008E050 41004010 */  beqz       $v0, .L8008E158
    /* 25854 8008E054 00000000 */   nop
    /* 25858 8008E058 FBFF2286 */  lh         $v0, -0x5($s1)
    /* 2585C 8008E05C 00000000 */  nop
    /* 25860 8008E060 10004228 */  slti       $v0, $v0, 0x10
    /* 25864 8008E064 3C004010 */  beqz       $v0, .L8008E158
    /* 25868 8008E068 00000000 */   nop
    /* 2586C 8008E06C 2D004012 */  beqz       $s2, .L8008E124
    /* 25870 8008E070 0F80043C */   lui       $a0, %hi(D_800E856C)
    /* 25874 8008E074 6C858424 */  addiu      $a0, $a0, %lo(D_800E856C)
    /* 25878 8008E078 801F053C */  lui        $a1, (0x1F800014 >> 16)
    /* 2587C 8008E07C 1400A534 */  ori        $a1, $a1, (0x1F800014 & 0xFFFF)
    /* 25880 8008E080 2C24010C */  jal        vs_main_memcpy
    /* 25884 8008E084 20000624 */   addiu     $a2, $zero, 0x20
    /* 25888 8008E088 6C1DC396 */  lhu        $v1, %lo(D_800F1D6C)($s6)
    /* 2588C 8008E08C 4CE2E296 */  lhu        $v0, %lo(vs_gametime_tickspeed)($s7)
    /* 25890 8008E090 00000000 */  nop
    /* 25894 8008E094 21186200 */  addu       $v1, $v1, $v0
    /* 25898 8008E098 FFFF6230 */  andi       $v0, $v1, 0xFFFF
    /* 2589C 8008E09C 0800422C */  sltiu      $v0, $v0, 0x8
    /* 258A0 8008E0A0 1F004014 */  bnez       $v0, .L8008E120
    /* 258A4 8008E0A4 6C1DC3A6 */   sh        $v1, %lo(D_800F1D6C)($s6)
    /* 258A8 8008E0A8 0F80023C */  lui        $v0, %hi(D_800F1CDC)
    /* 258AC 8008E0AC DC1C4794 */  lhu        $a3, %lo(D_800F1CDC)($v0)
    /* 258B0 8008E0B0 CCCC023C */  lui        $v0, (0xCCCCCCCD >> 16)
    /* 258B4 8008E0B4 CDCC4234 */  ori        $v0, $v0, (0xCCCCCCCD & 0xFFFF)
    /* 258B8 8008E0B8 C2380700 */  srl        $a3, $a3, 3
    /* 258BC 8008E0BC 1900E200 */  multu      $a3, $v0
    /* 258C0 8008E0C0 0F80083C */  lui        $t0, %hi(D_800E85BC)
    /* 258C4 8008E0C4 BC850425 */  addiu      $a0, $t0, %lo(D_800E85BC)
    /* 258C8 8008E0C8 40000524 */  addiu      $a1, $zero, 0x40
    /* 258CC 8008E0CC 80010624 */  addiu      $a2, $zero, 0x180
    /* 258D0 8008E0D0 0F80103C */  lui        $s0, %hi(D_800E85C4)
    /* 258D4 8008E0D4 F8FF6224 */  addiu      $v0, $v1, -0x8
    /* 258D8 8008E0D8 6C1DC2A6 */  sh         $v0, %lo(D_800F1D6C)($s6)
    /* 258DC 8008E0DC 10480000 */  mfhi       $t1
    /* 258E0 8008E0E0 82180900 */  srl        $v1, $t1, 2
    /* 258E4 8008E0E4 80100300 */  sll        $v0, $v1, 2
    /* 258E8 8008E0E8 21104300 */  addu       $v0, $v0, $v1
    /* 258EC 8008E0EC 2338E200 */  subu       $a3, $a3, $v0
    /* 258F0 8008E0F0 FFFFF230 */  andi       $s2, $a3, 0xFFFF
    /* 258F4 8008E0F4 C0101200 */  sll        $v0, $s2, 3
    /* 258F8 8008E0F8 48004224 */  addiu      $v0, $v0, 0x48
    /* 258FC 8008E0FC BC8502A5 */  sh         $v0, %lo(D_800E85BC)($t0)
    /* 25900 8008E100 80101200 */  sll        $v0, $s2, 2
    /* 25904 8008E104 04004224 */  addiu      $v0, $v0, 0x4
    /* 25908 8008E108 6FA2000C */  jal        MoveImage
    /* 2590C 8008E10C C48502A6 */   sh        $v0, %lo(D_800E85C4)($s0)
    /* 25910 8008E110 C4850426 */  addiu      $a0, $s0, %lo(D_800E85C4)
    /* 25914 8008E114 21280000 */  addu       $a1, $zero, $zero
    /* 25918 8008E118 6FA2000C */  jal        MoveImage
    /* 2591C 8008E11C 40010624 */   addiu     $a2, $zero, 0x140
  .L8008E120:
    /* 25920 8008E120 21900000 */  addu       $s2, $zero, $zero
  .L8008E124:
    /* 25924 8008E124 00006486 */  lh         $a0, 0x0($s3)
    /* 25928 8008E128 F7FF2586 */  lh         $a1, -0x9($s1)
    /* 2592C 8008E12C C0210400 */  sll        $a0, $a0, 7
    /* 25930 8008E130 1F37020C */  jal        func_8008DC7C
    /* 25934 8008E134 C0290500 */   sll       $a1, $a1, 7
    /* 25938 8008E138 40340200 */  sll        $a2, $v0, 17
    /* 2593C 8008E13C 43340600 */  sra        $a2, $a2, 17
    /* 25940 8008E140 00006486 */  lh         $a0, 0x0($s3)
    /* 25944 8008E144 F7FF2586 */  lh         $a1, -0x9($s1)
    /* 25948 8008E148 00002792 */  lbu        $a3, 0x0($s1)
    /* 2594C 8008E14C C0210400 */  sll        $a0, $a0, 7
    /* 25950 8008E150 6738020C */  jal        func_8008E19C
    /* 25954 8008E154 C0290500 */   sll       $a1, $a1, 7
  .L8008E158:
    /* 25958 8008E158 01009426 */  addiu      $s4, $s4, 0x1
    /* 2595C 8008E15C 0C003126 */  addiu      $s1, $s1, 0xC
    /* 25960 8008E160 2A109502 */  slt        $v0, $s4, $s5
    /* 25964 8008E164 8AFF4014 */  bnez       $v0, .L8008DF90
    /* 25968 8008E168 0C007326 */   addiu     $s3, $s3, 0xC
  .L8008E16C:
    /* 2596C 8008E16C 3400BF8F */  lw         $ra, 0x34($sp)
    /* 25970 8008E170 3000BE8F */  lw         $fp, 0x30($sp)
    /* 25974 8008E174 2C00B78F */  lw         $s7, 0x2C($sp)
    /* 25978 8008E178 2800B68F */  lw         $s6, 0x28($sp)
    /* 2597C 8008E17C 2400B58F */  lw         $s5, 0x24($sp)
    /* 25980 8008E180 2000B48F */  lw         $s4, 0x20($sp)
    /* 25984 8008E184 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 25988 8008E188 1800B28F */  lw         $s2, 0x18($sp)
    /* 2598C 8008E18C 1400B18F */  lw         $s1, 0x14($sp)
    /* 25990 8008E190 1000B08F */  lw         $s0, 0x10($sp)
    /* 25994 8008E194 0800E003 */  jr         $ra
    /* 25998 8008E198 3800BD27 */   addiu     $sp, $sp, 0x38
endlabel func_8008DF14
