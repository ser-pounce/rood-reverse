nonmatching func_80078248, 0x9C

glabel func_80078248
    /* FA48 80078248 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* FA4C 8007824C 1000B0AF */  sw         $s0, 0x10($sp)
    /* FA50 80078250 0F80103C */  lui        $s0, %hi(D_800F19CC)
    /* FA54 80078254 CC19048E */  lw         $a0, %lo(D_800F19CC)($s0)
    /* FA58 80078258 1400BFAF */  sw         $ra, 0x14($sp)
    /* FA5C 8007825C 8429828C */  lw         $v0, 0x2984($a0)
    /* FA60 80078260 00000000 */  nop
    /* FA64 80078264 18004010 */  beqz       $v0, .L800782C8
    /* FA68 80078268 00000000 */   nop
    /* FA6C 8007826C 0C008290 */  lbu        $v0, 0xC($a0)
    /* FA70 80078270 00000000 */  nop
    /* FA74 80078274 0B004010 */  beqz       $v0, .L800782A4
    /* FA78 80078278 00000000 */   nop
    /* FA7C 8007827C 8E298290 */  lbu        $v0, 0x298E($a0)
    /* FA80 80078280 00000000 */  nop
    /* FA84 80078284 01004224 */  addiu      $v0, $v0, 0x1
    /* FA88 80078288 8E2982A0 */  sb         $v0, 0x298E($a0)
    /* FA8C 8007828C FF004230 */  andi       $v0, $v0, 0xFF
    /* FA90 80078290 1F00422C */  sltiu      $v0, $v0, 0x1F
    /* FA94 80078294 0F004014 */  bnez       $v0, .L800782D4
    /* FA98 80078298 01000424 */   addiu     $a0, $zero, 0x1
    /* FA9C 8007829C B3E00108 */  j          .L800782CC
    /* FAA0 800782A0 00000000 */   nop
  .L800782A4:
    /* FAA4 800782A4 3E16030C */  jal        func_800C58F8
    /* FAA8 800782A8 8D298424 */   addiu     $a0, $a0, 0x298D
    /* FAAC 800782AC 09004010 */  beqz       $v0, .L800782D4
    /* FAB0 800782B0 01000424 */   addiu     $a0, $zero, 0x1
    /* FAB4 800782B4 CC19028E */  lw         $v0, %lo(D_800F19CC)($s0)
    /* FAB8 800782B8 00000000 */  nop
    /* FABC 800782BC 8D294390 */  lbu        $v1, 0x298D($v0)
    /* FAC0 800782C0 B3E00108 */  j          .L800782CC
    /* FAC4 800782C4 8C2943A0 */   sb        $v1, 0x298C($v0)
  .L800782C8:
    /* FAC8 800782C8 01000424 */  addiu      $a0, $zero, 0x1
  .L800782CC:
    /* FACC 800782CC CAC3010C */  jal        func_80070F28
    /* FAD0 800782D0 00000000 */   nop
  .L800782D4:
    /* FAD4 800782D4 1400BF8F */  lw         $ra, 0x14($sp)
    /* FAD8 800782D8 1000B08F */  lw         $s0, 0x10($sp)
    /* FADC 800782DC 0800E003 */  jr         $ra
    /* FAE0 800782E0 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80078248
