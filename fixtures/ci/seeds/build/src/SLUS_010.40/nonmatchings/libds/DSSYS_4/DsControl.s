nonmatching DsControl, 0x68

glabel DsControl
    /* 1637C 80025B7C E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 16380 80025B80 1400B1AF */  sw         $s1, 0x14($sp)
    /* 16384 80025B84 2188C000 */  addu       $s1, $a2, $zero
    /* 16388 80025B88 FF008430 */  andi       $a0, $a0, 0xFF
    /* 1638C 80025B8C 21300000 */  addu       $a2, $zero, $zero
    /* 16390 80025B90 21380000 */  addu       $a3, $zero, $zero
    /* 16394 80025B94 1800BFAF */  sw         $ra, 0x18($sp)
    /* 16398 80025B98 CD8E000C */  jal        DsCommand
    /* 1639C 80025B9C 1000B0AF */   sw        $s0, 0x10($sp)
    /* 163A0 80025BA0 21804000 */  addu       $s0, $v0, $zero
    /* 163A4 80025BA4 03000016 */  bnez       $s0, .L80025BB4
    /* 163A8 80025BA8 21200002 */   addu      $a0, $s0, $zero
    /* 163AC 80025BAC F4960008 */  j          .L80025BD0
    /* 163B0 80025BB0 21100000 */   addu      $v0, $zero, $zero
  .L80025BB4:
    /* 163B4 80025BB4 4790000C */  jal        DsSync
    /* 163B8 80025BB8 21282002 */   addu      $a1, $s1, $zero
    /* 163BC 80025BBC FF004230 */  andi       $v0, $v0, 0xFF
    /* 163C0 80025BC0 FCFF4010 */  beqz       $v0, .L80025BB4
    /* 163C4 80025BC4 21200002 */   addu      $a0, $s0, $zero
    /* 163C8 80025BC8 02004238 */  xori       $v0, $v0, 0x2
    /* 163CC 80025BCC 0100422C */  sltiu      $v0, $v0, 0x1
  .L80025BD0:
    /* 163D0 80025BD0 1800BF8F */  lw         $ra, 0x18($sp)
    /* 163D4 80025BD4 1400B18F */  lw         $s1, 0x14($sp)
    /* 163D8 80025BD8 1000B08F */  lw         $s0, 0x10($sp)
    /* 163DC 80025BDC 0800E003 */  jr         $ra
    /* 163E0 80025BE0 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel DsControl
