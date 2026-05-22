nonmatching _hasBlade1, 0x64

glabel _hasBlade1
    /* 1716C 8007F96C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 17170 8007F970 1000B0AF */  sw         $s0, 0x10($sp)
    /* 17174 8007F974 2180A000 */  addu       $s0, $a1, $zero
    /* 17178 8007F978 1400BFAF */  sw         $ra, 0x14($sp)
    /* 1717C 8007F97C 2CFD010C */  jal        func_8007F4B0
    /* 17180 8007F980 16000424 */   addiu     $a0, $zero, 0x16
    /* 17184 8007F984 0D004014 */  bnez       $v0, .L8007F9BC
    /* 17188 8007F988 0F80033C */   lui       $v1, %hi(vs_battle_actors)
    /* 1718C 8007F98C 00000292 */  lbu        $v0, 0x0($s0)
    /* 17190 8007F990 28196324 */  addiu      $v1, $v1, %lo(vs_battle_actors)
    /* 17194 8007F994 80100200 */  sll        $v0, $v0, 2
    /* 17198 8007F998 21104300 */  addu       $v0, $v0, $v1
    /* 1719C 8007F99C 0000428C */  lw         $v0, 0x0($v0)
    /* 171A0 8007F9A0 00000000 */  nop
    /* 171A4 8007F9A4 3C00428C */  lw         $v0, 0x3C($v0)
    /* 171A8 8007F9A8 00000000 */  nop
    /* 171AC 8007F9AC 54004394 */  lhu        $v1, 0x54($v0)
    /* 171B0 8007F9B0 00000000 */  nop
    /* 171B4 8007F9B4 02006014 */  bnez       $v1, .L8007F9C0
    /* 171B8 8007F9B8 01000224 */   addiu     $v0, $zero, 0x1
  .L8007F9BC:
    /* 171BC 8007F9BC 21100000 */  addu       $v0, $zero, $zero
  .L8007F9C0:
    /* 171C0 8007F9C0 1400BF8F */  lw         $ra, 0x14($sp)
    /* 171C4 8007F9C4 1000B08F */  lw         $s0, 0x10($sp)
    /* 171C8 8007F9C8 0800E003 */  jr         $ra
    /* 171CC 8007F9CC 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel _hasBlade1
