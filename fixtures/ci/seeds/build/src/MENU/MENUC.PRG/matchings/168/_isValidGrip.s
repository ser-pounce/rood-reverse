nonmatching _isValidGrip, 0x44

glabel _isValidGrip
    /* B3C 8010333C 21308000 */  addu       $a2, $a0, $zero
    /* B40 80103340 0300C010 */  beqz       $a2, .L80103350
    /* B44 80103344 00000000 */   nop
    /* B48 80103348 0300A014 */  bnez       $a1, .L80103358
    /* B4C 8010334C 01000424 */   addiu     $a0, $zero, 0x1
  .L80103350:
    /* B50 80103350 0800E003 */  jr         $ra
    /* B54 80103354 01000224 */   addiu     $v0, $zero, 0x1
  .L80103358:
    /* B58 80103358 1180033C */  lui        $v1, %hi(_validGripFlags)
    /* B5C 8010335C 0300A290 */  lbu        $v0, 0x3($a1)
    /* B60 80103360 24BB6324 */  addiu      $v1, $v1, %lo(_validGripFlags)
    /* B64 80103364 04108200 */  sllv       $v0, $v0, $a0
    /* B68 80103368 21104300 */  addu       $v0, $v0, $v1
    /* B6C 8010336C 0300C390 */  lbu        $v1, 0x3($a2)
    /* B70 80103370 00004294 */  lhu        $v0, 0x0($v0)
    /* B74 80103374 04206400 */  sllv       $a0, $a0, $v1
    /* B78 80103378 0800E003 */  jr         $ra
    /* B7C 8010337C 24108200 */   and       $v0, $a0, $v0
endlabel _isValidGrip
