nonmatching func_80103A6C, 0x5C

glabel func_80103A6C
    /* 126C 80103A6C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1270 80103A70 0300C014 */  bnez       $a2, .L80103A80
    /* 1274 80103A74 1000BFAF */   sw        $ra, 0x10($sp)
    /* 1278 80103A78 21280000 */  addu       $a1, $zero, $zero
    /* 127C 80103A7C 01000624 */  addiu      $a2, $zero, 0x1
  .L80103A80:
    /* 1280 80103A80 03120400 */  sra        $v0, $a0, 8
    /* 1284 80103A84 03004014 */  bnez       $v0, .L80103A94
    /* 1288 80103A88 80290500 */   sll       $a1, $a1, 6
    /* 128C 80103A8C 2128C000 */  addu       $a1, $a2, $zero
    /* 1290 80103A90 80290500 */  sll        $a1, $a1, 6
  .L80103A94:
    /* 1294 80103A94 2128A600 */  addu       $a1, $a1, $a2
    /* 1298 80103A98 FFFFA524 */  addiu      $a1, $a1, -0x1
    /* 129C 80103A9C 1A00A600 */  div        $zero, $a1, $a2
    /* 12A0 80103AA0 12280000 */  mflo       $a1
    /* 12A4 80103AA4 801F023C */  lui        $v0, (0x1F800004 >> 16)
    /* 12A8 80103AA8 0400468C */  lw         $a2, (0x1F800004 & 0xFFFF)($v0)
    /* 12AC 80103AAC FF008430 */  andi       $a0, $a0, 0xFF
    /* 12B0 80103AB0 7726030C */  jal        vs_battle_drawStatBar
    /* 12B4 80103AB4 F4FFC624 */   addiu     $a2, $a2, -0xC
    /* 12B8 80103AB8 1000BF8F */  lw         $ra, 0x10($sp)
    /* 12BC 80103ABC 00000000 */  nop
    /* 12C0 80103AC0 0800E003 */  jr         $ra
    /* 12C4 80103AC4 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80103A6C
