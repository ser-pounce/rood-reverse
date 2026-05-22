nonmatching _sortEquipmentByStat, 0x1A0

glabel _sortEquipmentByStat
    /* 312C 8010592C 90FFBD27 */  addiu      $sp, $sp, -0x70
    /* 3130 80105930 6800BEAF */  sw         $fp, 0x68($sp)
    /* 3134 80105934 21F0A003 */  addu       $fp, $sp, $zero
    /* 3138 80105938 6000B6AF */  sw         $s6, 0x60($sp)
    /* 313C 8010593C 21B00000 */  addu       $s6, $zero, $zero
    /* 3140 80105940 1180023C */  lui        $v0, %hi(_containerItemCapacities)
    /* 3144 80105944 44994224 */  addiu      $v0, $v0, %lo(_containerItemCapacities)
    /* 3148 80105948 6C00BFAF */  sw         $ra, 0x6C($sp)
    /* 314C 8010594C 6400B7AF */  sw         $s7, 0x64($sp)
    /* 3150 80105950 5C00B5AF */  sw         $s5, 0x5C($sp)
    /* 3154 80105954 5800B4AF */  sw         $s4, 0x58($sp)
    /* 3158 80105958 5400B3AF */  sw         $s3, 0x54($sp)
    /* 315C 8010595C 5000B2AF */  sw         $s2, 0x50($sp)
    /* 3160 80105960 4C00B1AF */  sw         $s1, 0x4C($sp)
    /* 3164 80105964 4800B0AF */  sw         $s0, 0x48($sp)
    /* 3168 80105968 7000C4AF */  sw         $a0, 0x70($fp)
    /* 316C 8010596C 40180400 */  sll        $v1, $a0, 1
    /* 3170 80105970 21186200 */  addu       $v1, $v1, $v0
    /* 3174 80105974 00007594 */  lhu        $s5, 0x0($v1)
    /* 3178 80105978 1180023C */  lui        $v0, %hi(vs_menuD_containerData)
    /* 317C 8010597C 7400C5AF */  sw         $a1, 0x74($fp)
    /* 3180 80105980 8C9A458C */  lw         $a1, %lo(vs_menuD_containerData)($v0)
    /* 3184 80105984 40101500 */  sll        $v0, $s5, 1
    /* 3188 80105988 07004224 */  addiu      $v0, $v0, 0x7
    /* 318C 8010598C C2100200 */  srl        $v0, $v0, 3
    /* 3190 80105990 C0100200 */  sll        $v0, $v0, 3
    /* 3194 80105994 23E8A203 */  subu       $sp, $sp, $v0
    /* 3198 80105998 1000A727 */  addiu      $a3, $sp, 0x10
    /* 319C 8010599C 250B040C */  jal        _getContainerIndicesOffset
    /* 31A0 801059A0 4000C7AF */   sw        $a3, 0x40($fp)
    /* 31A4 801059A4 40281500 */  sll        $a1, $s5, 1
    /* 31A8 801059A8 4000C48F */  lw         $a0, 0x40($fp)
    /* 31AC 801059AC 0733030C */  jal        vs_battle_rMemzero
    /* 31B0 801059B0 21B84000 */   addu      $s7, $v0, $zero
  .L801059B4:
    /* 31B4 801059B4 0080143C */  lui        $s4, (0x80000000 >> 16)
  .L801059B8:
    /* 31B8 801059B8 1500A012 */  beqz       $s5, .L80105A10
    /* 31BC 801059BC 21880000 */   addu      $s1, $zero, $zero
    /* 31C0 801059C0 2190E002 */  addu       $s2, $s7, $zero
  .L801059C4:
    /* 31C4 801059C4 00005096 */  lhu        $s0, 0x0($s2)
    /* 31C8 801059C8 00000000 */  nop
    /* 31CC 801059CC 0C000012 */  beqz       $s0, .L80105A00
    /* 31D0 801059D0 1000C427 */   addiu     $a0, $fp, 0x10
    /* 31D4 801059D4 7000C58F */  lw         $a1, 0x70($fp)
    /* 31D8 801059D8 1116040C */  jal        _copyEquipmentStats
    /* 31DC 801059DC FFFF0626 */   addiu     $a2, $s0, -0x1
    /* 31E0 801059E0 7400C48F */  lw         $a0, 0x74($fp)
    /* 31E4 801059E4 D315040C */  jal        _getEquipmentStat
    /* 31E8 801059E8 1000C527 */   addiu     $a1, $fp, 0x10
    /* 31EC 801059EC 21184000 */  addu       $v1, $v0, $zero
    /* 31F0 801059F0 2A108302 */  slt        $v0, $s4, $v1
    /* 31F4 801059F4 02004010 */  beqz       $v0, .L80105A00
    /* 31F8 801059F8 00000000 */   nop
    /* 31FC 801059FC 21A06000 */  addu       $s4, $v1, $zero
  .L80105A00:
    /* 3200 80105A00 01003126 */  addiu      $s1, $s1, 0x1
    /* 3204 80105A04 2A103502 */  slt        $v0, $s1, $s5
    /* 3208 80105A08 EEFF4014 */  bnez       $v0, .L801059C4
    /* 320C 80105A0C 02005226 */   addiu     $s2, $s2, 0x2
  .L80105A10:
    /* 3210 80105A10 0080023C */  lui        $v0, (0x80000000 >> 16)
    /* 3214 80105A14 1D008212 */  beq        $s4, $v0, .L80105A8C
    /* 3218 80105A18 2120E002 */   addu      $a0, $s7, $zero
    /* 321C 80105A1C E5FFA012 */  beqz       $s5, .L801059B4
    /* 3220 80105A20 21880000 */   addu      $s1, $zero, $zero
    /* 3224 80105A24 2190E002 */  addu       $s2, $s7, $zero
    /* 3228 80105A28 4000C78F */  lw         $a3, 0x40($fp)
    /* 322C 80105A2C 40101600 */  sll        $v0, $s6, 1
    /* 3230 80105A30 21984700 */  addu       $s3, $v0, $a3
  .L80105A34:
    /* 3234 80105A34 00005096 */  lhu        $s0, 0x0($s2)
    /* 3238 80105A38 00000000 */  nop
    /* 323C 80105A3C 0D000012 */  beqz       $s0, .L80105A74
    /* 3240 80105A40 1000C427 */   addiu     $a0, $fp, 0x10
    /* 3244 80105A44 7000C58F */  lw         $a1, 0x70($fp)
    /* 3248 80105A48 1116040C */  jal        _copyEquipmentStats
    /* 324C 80105A4C FFFF0626 */   addiu     $a2, $s0, -0x1
    /* 3250 80105A50 7400C48F */  lw         $a0, 0x74($fp)
    /* 3254 80105A54 D315040C */  jal        _getEquipmentStat
    /* 3258 80105A58 1000C527 */   addiu     $a1, $fp, 0x10
    /* 325C 80105A5C 05005414 */  bne        $v0, $s4, .L80105A74
    /* 3260 80105A60 00000000 */   nop
    /* 3264 80105A64 000070A6 */  sh         $s0, 0x0($s3)
    /* 3268 80105A68 02007326 */  addiu      $s3, $s3, 0x2
    /* 326C 80105A6C 0100D626 */  addiu      $s6, $s6, 0x1
    /* 3270 80105A70 000040A6 */  sh         $zero, 0x0($s2)
  .L80105A74:
    /* 3274 80105A74 01003126 */  addiu      $s1, $s1, 0x1
    /* 3278 80105A78 2A103502 */  slt        $v0, $s1, $s5
    /* 327C 80105A7C EDFF4014 */  bnez       $v0, .L80105A34
    /* 3280 80105A80 02005226 */   addiu     $s2, $s2, 0x2
    /* 3284 80105A84 6E160408 */  j          .L801059B8
    /* 3288 80105A88 0080143C */   lui       $s4, (0x80000000 >> 16)
  .L80105A8C:
    /* 328C 80105A8C 4000C58F */  lw         $a1, 0x40($fp)
    /* 3290 80105A90 7800030C */  jal        vs_battle_memcpy
    /* 3294 80105A94 40301500 */   sll       $a2, $s5, 1
    /* 3298 80105A98 21E8C003 */  addu       $sp, $fp, $zero
    /* 329C 80105A9C 6C00BF8F */  lw         $ra, 0x6C($sp)
    /* 32A0 80105AA0 6800BE8F */  lw         $fp, 0x68($sp)
    /* 32A4 80105AA4 6400B78F */  lw         $s7, 0x64($sp)
    /* 32A8 80105AA8 6000B68F */  lw         $s6, 0x60($sp)
    /* 32AC 80105AAC 5C00B58F */  lw         $s5, 0x5C($sp)
    /* 32B0 80105AB0 5800B48F */  lw         $s4, 0x58($sp)
    /* 32B4 80105AB4 5400B38F */  lw         $s3, 0x54($sp)
    /* 32B8 80105AB8 5000B28F */  lw         $s2, 0x50($sp)
    /* 32BC 80105ABC 4C00B18F */  lw         $s1, 0x4C($sp)
    /* 32C0 80105AC0 4800B08F */  lw         $s0, 0x48($sp)
    /* 32C4 80105AC4 0800E003 */  jr         $ra
    /* 32C8 80105AC8 7000BD27 */   addiu     $sp, $sp, 0x70
endlabel _sortEquipmentByStat
