nonmatching _hasBlade3, 0x64

glabel _hasBlade3
    /* 17234 8007FA34 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 17238 8007FA38 1000B0AF */  sw         $s0, 0x10($sp)
    /* 1723C 8007FA3C 2180A000 */  addu       $s0, $a1, $zero
    /* 17240 8007FA40 1400BFAF */  sw         $ra, 0x14($sp)
    /* 17244 8007FA44 2CFD010C */  jal        func_8007F4B0
    /* 17248 8007FA48 18000424 */   addiu     $a0, $zero, 0x18
    /* 1724C 8007FA4C 0D004014 */  bnez       $v0, .L8007FA84
    /* 17250 8007FA50 0F80033C */   lui       $v1, %hi(vs_battle_actors)
    /* 17254 8007FA54 00000292 */  lbu        $v0, 0x0($s0)
    /* 17258 8007FA58 28196324 */  addiu      $v1, $v1, %lo(vs_battle_actors)
    /* 1725C 8007FA5C 80100200 */  sll        $v0, $v0, 2
    /* 17260 8007FA60 21104300 */  addu       $v0, $v0, $v1
    /* 17264 8007FA64 0000428C */  lw         $v0, 0x0($v0)
    /* 17268 8007FA68 00000000 */  nop
    /* 1726C 8007FA6C 3C00428C */  lw         $v0, 0x3C($v0)
    /* 17270 8007FA70 00000000 */  nop
    /* 17274 8007FA74 54004394 */  lhu        $v1, 0x54($v0)
    /* 17278 8007FA78 00000000 */  nop
    /* 1727C 8007FA7C 02006014 */  bnez       $v1, .L8007FA88
    /* 17280 8007FA80 01000224 */   addiu     $v0, $zero, 0x1
  .L8007FA84:
    /* 17284 8007FA84 21100000 */  addu       $v0, $zero, $zero
  .L8007FA88:
    /* 17288 8007FA88 1400BF8F */  lw         $ra, 0x14($sp)
    /* 1728C 8007FA8C 1000B08F */  lw         $s0, 0x10($sp)
    /* 17290 8007FA90 0800E003 */  jr         $ra
    /* 17294 8007FA94 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel _hasBlade3
