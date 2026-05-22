nonmatching _getRoundedLineCount, 0x5C

glabel _getRoundedLineCount
    /* 136C 80103B6C 1080023C */  lui        $v0, %hi(_helpText)
    /* 1370 80103B70 5452428C */  lw         $v0, %lo(_helpText)($v0)
    /* 1374 80103B74 6666033C */  lui        $v1, (0x66666667 >> 16)
    /* 1378 80103B78 10004494 */  lhu        $a0, 0x10($v0)
    /* 137C 80103B7C 67666334 */  ori        $v1, $v1, (0x66666667 & 0xFFFF)
    /* 1380 80103B80 18008300 */  mult       $a0, $v1
    /* 1384 80103B84 C3170400 */  sra        $v0, $a0, 31
    /* 1388 80103B88 10280000 */  mfhi       $a1
    /* 138C 80103B8C 83180500 */  sra        $v1, $a1, 2
    /* 1390 80103B90 23186200 */  subu       $v1, $v1, $v0
    /* 1394 80103B94 80100300 */  sll        $v0, $v1, 2
    /* 1398 80103B98 21104300 */  addu       $v0, $v0, $v1
    /* 139C 80103B9C 40100200 */  sll        $v0, $v0, 1
    /* 13A0 80103BA0 23188200 */  subu       $v1, $a0, $v0
    /* 13A4 80103BA4 02006018 */  blez       $v1, .L80103BB0
    /* 13A8 80103BA8 0A008224 */   addiu     $v0, $a0, 0xA
    /* 13AC 80103BAC 23204300 */  subu       $a0, $v0, $v1
  .L80103BB0:
    /* 13B0 80103BB0 F6FF8424 */  addiu      $a0, $a0, -0xA
    /* 13B4 80103BB4 02008104 */  bgez       $a0, .L80103BC0
    /* 13B8 80103BB8 00000000 */   nop
    /* 13BC 80103BBC 21200000 */  addu       $a0, $zero, $zero
  .L80103BC0:
    /* 13C0 80103BC0 0800E003 */  jr         $ra
    /* 13C4 80103BC4 21108000 */   addu      $v0, $a0, $zero
endlabel _getRoundedLineCount
