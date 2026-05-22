nonmatching _hasBlade2, 0x64

glabel _hasBlade2
    /* 171D0 8007F9D0 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 171D4 8007F9D4 1000B0AF */  sw         $s0, 0x10($sp)
    /* 171D8 8007F9D8 2180A000 */  addu       $s0, $a1, $zero
    /* 171DC 8007F9DC 1400BFAF */  sw         $ra, 0x14($sp)
    /* 171E0 8007F9E0 2CFD010C */  jal        func_8007F4B0
    /* 171E4 8007F9E4 17000424 */   addiu     $a0, $zero, 0x17
    /* 171E8 8007F9E8 0D004014 */  bnez       $v0, .L8007FA20
    /* 171EC 8007F9EC 0F80033C */   lui       $v1, %hi(vs_battle_actors)
    /* 171F0 8007F9F0 00000292 */  lbu        $v0, 0x0($s0)
    /* 171F4 8007F9F4 28196324 */  addiu      $v1, $v1, %lo(vs_battle_actors)
    /* 171F8 8007F9F8 80100200 */  sll        $v0, $v0, 2
    /* 171FC 8007F9FC 21104300 */  addu       $v0, $v0, $v1
    /* 17200 8007FA00 0000428C */  lw         $v0, 0x0($v0)
    /* 17204 8007FA04 00000000 */  nop
    /* 17208 8007FA08 3C00428C */  lw         $v0, 0x3C($v0)
    /* 1720C 8007FA0C 00000000 */  nop
    /* 17210 8007FA10 54004394 */  lhu        $v1, 0x54($v0)
    /* 17214 8007FA14 00000000 */  nop
    /* 17218 8007FA18 02006014 */  bnez       $v1, .L8007FA24
    /* 1721C 8007FA1C 01000224 */   addiu     $v0, $zero, 0x1
  .L8007FA20:
    /* 17220 8007FA20 21100000 */  addu       $v0, $zero, $zero
  .L8007FA24:
    /* 17224 8007FA24 1400BF8F */  lw         $ra, 0x14($sp)
    /* 17228 8007FA28 1000B08F */  lw         $s0, 0x10($sp)
    /* 1722C 8007FA2C 0800E003 */  jr         $ra
    /* 17230 8007FA30 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel _hasBlade2
