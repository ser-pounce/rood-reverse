nonmatching func_800CC128, 0xDC

glabel func_800CC128
    /* 63928 800CC128 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 6392C 800CC12C 1800B2AF */  sw         $s2, 0x18($sp)
    /* 63930 800CC130 2000BFAF */  sw         $ra, 0x20($sp)
    /* 63934 800CC134 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 63938 800CC138 1400B1AF */  sw         $s1, 0x14($sp)
    /* 6393C 800CC13C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 63940 800CC140 03009090 */  lbu        $s0, 0x3($a0)
    /* 63944 800CC144 80001324 */  addiu      $s3, $zero, 0x80
    /* 63948 800CC148 05001316 */  bne        $s0, $s3, .L800CC160
    /* 6394C 800CC14C 2190C000 */   addu      $s2, $a2, $zero
    /* 63950 800CC150 F32E030C */  jal        func_800CBBCC
    /* 63954 800CC154 00000000 */   nop
    /* 63958 800CC158 7A300308 */  j          .L800CC1E8
    /* 6395C 800CC15C 00000000 */   nop
  .L800CC160:
    /* 63960 800CC160 21304002 */  addu       $a2, $s2, $zero
    /* 63964 800CC164 0F80033C */  lui        $v1, %hi(D_800F51C8)
    /* 63968 800CC168 01000224 */  addiu      $v0, $zero, 0x1
    /* 6396C 800CC16C F32E030C */  jal        func_800CBBCC
    /* 63970 800CC170 C85162A0 */   sb        $v0, %lo(D_800F51C8)($v1)
    /* 63974 800CC174 0680023C */  lui        $v0, %hi(vs_main_frameBuf)
    /* 63978 800CC178 10E2428C */  lw         $v0, %lo(vs_main_frameBuf)($v0)
    /* 6397C 800CC17C 00000000 */  nop
    /* 63980 800CC180 02004014 */  bnez       $v0, .L800CC18C
    /* 63984 800CC184 21880000 */   addu      $s1, $zero, $zero
    /* 63988 800CC188 40011124 */  addiu      $s1, $zero, 0x140
  .L800CC18C:
    /* 6398C 800CC18C 23807002 */  subu       $s0, $s3, $s0
    /* 63990 800CC190 21200002 */  addu       $a0, $s0, $zero
    /* 63994 800CC194 21280000 */  addu       $a1, $zero, $zero
    /* 63998 800CC198 F000063C */  lui        $a2, (0xF00100 >> 16)
    /* 6399C 800CC19C 0001C634 */  ori        $a2, $a2, (0xF00100 & 0xFFFF)
    /* 639A0 800CC1A0 8C00030C */  jal        vs_battle_setSprite
    /* 639A4 800CC1A4 21384002 */   addu      $a3, $s2, $zero
    /* 639A8 800CC1A8 21200002 */  addu       $a0, $s0, $zero
    /* 639AC 800CC1AC 00010524 */  addiu      $a1, $zero, 0x100
    /* 639B0 800CC1B0 F000063C */  lui        $a2, (0xF00040 >> 16)
    /* 639B4 800CC1B4 4000C634 */  ori        $a2, $a2, (0xF00040 & 0xFFFF)
    /* 639B8 800CC1B8 21384002 */  addu       $a3, $s2, $zero
    /* 639BC 800CC1BC 82191100 */  srl        $v1, $s1, 6
    /* 639C0 800CC1C0 20016334 */  ori        $v1, $v1, 0x120
    /* 639C4 800CC1C4 00E1103C */  lui        $s0, (0xE1000000 >> 16)
    /* 639C8 800CC1C8 25187000 */  or         $v1, $v1, $s0
    /* 639CC 800CC1CC 8C00030C */  jal        vs_battle_setSprite
    /* 639D0 800CC1D0 040043AC */   sw        $v1, 0x4($v0)
    /* 639D4 800CC1D4 00012326 */  addiu      $v1, $s1, 0x100
    /* 639D8 800CC1D8 83190300 */  sra        $v1, $v1, 6
    /* 639DC 800CC1DC 20016334 */  ori        $v1, $v1, 0x120
    /* 639E0 800CC1E0 25187000 */  or         $v1, $v1, $s0
    /* 639E4 800CC1E4 040043AC */  sw         $v1, 0x4($v0)
  .L800CC1E8:
    /* 639E8 800CC1E8 2000BF8F */  lw         $ra, 0x20($sp)
    /* 639EC 800CC1EC 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 639F0 800CC1F0 1800B28F */  lw         $s2, 0x18($sp)
    /* 639F4 800CC1F4 1400B18F */  lw         $s1, 0x14($sp)
    /* 639F8 800CC1F8 1000B08F */  lw         $s0, 0x10($sp)
    /* 639FC 800CC1FC 0800E003 */  jr         $ra
    /* 63A00 800CC200 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_800CC128
