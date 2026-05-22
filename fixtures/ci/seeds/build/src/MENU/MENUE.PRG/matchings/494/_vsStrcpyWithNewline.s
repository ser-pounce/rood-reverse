nonmatching _vsStrcpyWithNewline, 0x54

glabel _vsStrcpyWithNewline
    /* 149C 80103C9C 0000A390 */  lbu        $v1, 0x0($a1)
    /* 14A0 80103CA0 E7000224 */  addiu      $v0, $zero, 0xE7
    /* 14A4 80103CA4 0E006210 */  beq        $v1, $v0, .L80103CE0
    /* 14A8 80103CA8 21304000 */   addu      $a2, $v0, $zero
  .L80103CAC:
    /* 14AC 80103CAC EC00622C */  sltiu      $v0, $v1, 0xEC
    /* 14B0 80103CB0 04004014 */  bnez       $v0, .L80103CC4
    /* 14B4 80103CB4 00000000 */   nop
    /* 14B8 80103CB8 000083A0 */  sb         $v1, 0x0($a0)
    /* 14BC 80103CBC 0100A524 */  addiu      $a1, $a1, 0x1
    /* 14C0 80103CC0 01008424 */  addiu      $a0, $a0, 0x1
  .L80103CC4:
    /* 14C4 80103CC4 0000A290 */  lbu        $v0, 0x0($a1)
    /* 14C8 80103CC8 0100A524 */  addiu      $a1, $a1, 0x1
    /* 14CC 80103CCC 000082A0 */  sb         $v0, 0x0($a0)
    /* 14D0 80103CD0 0000A390 */  lbu        $v1, 0x0($a1)
    /* 14D4 80103CD4 00000000 */  nop
    /* 14D8 80103CD8 F4FF6614 */  bne        $v1, $a2, .L80103CAC
    /* 14DC 80103CDC 01008424 */   addiu     $a0, $a0, 0x1
  .L80103CE0:
    /* 14E0 80103CE0 E8000224 */  addiu      $v0, $zero, 0xE8
    /* 14E4 80103CE4 000082A0 */  sb         $v0, 0x0($a0)
    /* 14E8 80103CE8 0800E003 */  jr         $ra
    /* 14EC 80103CEC 01008224 */   addiu     $v0, $a0, 0x1
endlabel _vsStrcpyWithNewline
