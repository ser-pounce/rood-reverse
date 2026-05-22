nonmatching vs_battle_copyUiShieldStats, 0xC8

glabel vs_battle_copyUiShieldStats
    /* 31E0 8006B9E0 D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 31E4 8006B9E4 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 31E8 8006B9E8 2198A000 */  addu       $s3, $a1, $zero
    /* 31EC 8006B9EC 2800BFAF */  sw         $ra, 0x28($sp)
    /* 31F0 8006B9F0 2400B5AF */  sw         $s5, 0x24($sp)
    /* 31F4 8006B9F4 2000B4AF */  sw         $s4, 0x20($sp)
    /* 31F8 8006B9F8 1800B2AF */  sw         $s2, 0x18($sp)
    /* 31FC 8006B9FC 1400B1AF */  sw         $s1, 0x14($sp)
    /* 3200 8006BA00 1000B0AF */  sw         $s0, 0x10($sp)
    /* 3204 8006BA04 18006296 */  lhu        $v0, 0x18($s3)
    /* 3208 8006BA08 00000000 */  nop
    /* 320C 8006BA0C 1D004010 */  beqz       $v0, .L8006BA84
    /* 3210 8006BA10 21A08000 */   addu      $s4, $a0, $zero
    /* 3214 8006BA14 04008426 */  addiu      $a0, $s4, 0x4
    /* 3218 8006BA18 18006526 */  addiu      $a1, $s3, 0x18
    /* 321C 8006BA1C 21800000 */  addu       $s0, $zero, $zero
    /* 3220 8006BA20 E0006296 */  lhu        $v0, 0xE0($s3)
    /* 3224 8006BA24 DC006396 */  lhu        $v1, 0xDC($s3)
    /* 3228 8006BA28 48001224 */  addiu      $s2, $zero, 0x48
    /* 322C 8006BA2C 200062A6 */  sh         $v0, 0x20($s3)
    /* 3230 8006BA30 EFAD010C */  jal        vs_battle_copyUiEquipmentStats
    /* 3234 8006BA34 240063A6 */   sh        $v1, 0x24($s3)
    /* 3238 8006BA38 0680023C */  lui        $v0, %hi(D_80060A0C)
    /* 323C 8006BA3C 0C0A5524 */  addiu      $s5, $v0, %lo(D_80060A0C)
    /* 3240 8006BA40 21886002 */  addu       $s1, $s3, $zero
  .L8006BA44:
    /* 3244 8006BA44 48002296 */  lhu        $v0, 0x48($s1)
    /* 3248 8006BA48 00000000 */  nop
    /* 324C 8006BA4C 08004010 */  beqz       $v0, .L8006BA70
    /* 3250 8006BA50 21109002 */   addu      $v0, $s4, $s0
    /* 3254 8006BA54 2C004290 */  lbu        $v0, 0x2C($v0)
    /* 3258 8006BA58 21287202 */  addu       $a1, $s3, $s2
    /* 325C 8006BA5C C0200200 */  sll        $a0, $v0, 3
    /* 3260 8006BA60 23208200 */  subu       $a0, $a0, $v0
    /* 3264 8006BA64 80200400 */  sll        $a0, $a0, 2
    /* 3268 8006BA68 CAAD010C */  jal        vs_battle_copyUiGemStats
    /* 326C 8006BA6C 21209500 */   addu      $a0, $a0, $s5
  .L8006BA70:
    /* 3270 8006BA70 30005226 */  addiu      $s2, $s2, 0x30
    /* 3274 8006BA74 01001026 */  addiu      $s0, $s0, 0x1
    /* 3278 8006BA78 0300022A */  slti       $v0, $s0, 0x3
    /* 327C 8006BA7C F1FF4014 */  bnez       $v0, .L8006BA44
    /* 3280 8006BA80 30003126 */   addiu     $s1, $s1, 0x30
  .L8006BA84:
    /* 3284 8006BA84 2800BF8F */  lw         $ra, 0x28($sp)
    /* 3288 8006BA88 2400B58F */  lw         $s5, 0x24($sp)
    /* 328C 8006BA8C 2000B48F */  lw         $s4, 0x20($sp)
    /* 3290 8006BA90 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 3294 8006BA94 1800B28F */  lw         $s2, 0x18($sp)
    /* 3298 8006BA98 1400B18F */  lw         $s1, 0x14($sp)
    /* 329C 8006BA9C 1000B08F */  lw         $s0, 0x10($sp)
    /* 32A0 8006BAA0 0800E003 */  jr         $ra
    /* 32A4 8006BAA4 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel vs_battle_copyUiShieldStats
