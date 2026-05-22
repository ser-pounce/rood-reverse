nonmatching _copyNextPageText, 0xD4

glabel _copyNextPageText
    /* 13C8 80103BC8 D8FBBD27 */  addiu      $sp, $sp, -0x428
    /* 13CC 80103BCC F8000224 */  addiu      $v0, $zero, 0xF8
    /* 13D0 80103BD0 1000A2A3 */  sb         $v0, 0x10($sp)
    /* 13D4 80103BD4 FB000224 */  addiu      $v0, $zero, 0xFB
    /* 13D8 80103BD8 1200A2A3 */  sb         $v0, 0x12($sp)
    /* 13DC 80103BDC 06000224 */  addiu      $v0, $zero, 0x6
    /* 13E0 80103BE0 1300A2A3 */  sb         $v0, 0x13($sp)
    /* 13E4 80103BE4 E8000224 */  addiu      $v0, $zero, 0xE8
    /* 13E8 80103BE8 1080033C */  lui        $v1, %hi(_helpText)
    /* 13EC 80103BEC 1400A2A3 */  sb         $v0, 0x14($sp)
    /* 13F0 80103BF0 1080023C */  lui        $v0, %hi(_scrollPosition)
    /* 13F4 80103BF4 4452458C */  lw         $a1, %lo(_scrollPosition)($v0)
    /* 13F8 80103BF8 5452628C */  lw         $v0, %lo(_helpText)($v1)
    /* 13FC 80103BFC 2004BFAF */  sw         $ra, 0x420($sp)
    /* 1400 80103C00 1C04B3AF */  sw         $s3, 0x41C($sp)
    /* 1404 80103C04 1804B2AF */  sw         $s2, 0x418($sp)
    /* 1408 80103C08 1404B1AF */  sw         $s1, 0x414($sp)
    /* 140C 80103C0C 1004B0AF */  sw         $s0, 0x410($sp)
    /* 1410 80103C10 1100A0A3 */  sb         $zero, 0x11($sp)
    /* 1414 80103C14 0A00B224 */  addiu      $s2, $a1, 0xA
    /* 1418 80103C18 10004394 */  lhu        $v1, 0x10($v0)
    /* 141C 80103C1C 10005324 */  addiu      $s3, $v0, 0x10
    /* 1420 80103C20 2A107200 */  slt        $v0, $v1, $s2
    /* 1424 80103C24 02004010 */  beqz       $v0, .L80103C30
    /* 1428 80103C28 1400A427 */   addiu     $a0, $sp, 0x14
    /* 142C 80103C2C 21906000 */  addu       $s2, $v1, $zero
  .L80103C30:
    /* 1430 80103C30 2180A000 */  addu       $s0, $a1, $zero
    /* 1434 80103C34 2A101202 */  slt        $v0, $s0, $s2
    /* 1438 80103C38 0C004010 */  beqz       $v0, .L80103C6C
    /* 143C 80103C3C 40101000 */   sll       $v0, $s0, 1
    /* 1440 80103C40 21885300 */  addu       $s1, $v0, $s3
  .L80103C44:
    /* 1444 80103C44 02002596 */  lhu        $a1, 0x2($s1)
    /* 1448 80103C48 02003126 */  addiu      $s1, $s1, 0x2
    /* 144C 80103C4C 01001026 */  addiu      $s0, $s0, 0x1
    /* 1450 80103C50 40280500 */  sll        $a1, $a1, 1
    /* 1454 80103C54 270F040C */  jal        _vsStrcpyWithNewline
    /* 1458 80103C58 21286502 */   addu      $a1, $s3, $a1
    /* 145C 80103C5C 21204000 */  addu       $a0, $v0, $zero
    /* 1460 80103C60 2A101202 */  slt        $v0, $s0, $s2
    /* 1464 80103C64 F7FF4014 */  bnez       $v0, .L80103C44
    /* 1468 80103C68 00000000 */   nop
  .L80103C6C:
    /* 146C 80103C6C E7000224 */  addiu      $v0, $zero, 0xE7
    /* 1470 80103C70 FFFF82A0 */  sb         $v0, -0x1($a0)
    /* 1474 80103C74 21200000 */  addu       $a0, $zero, $zero
    /* 1478 80103C78 FC1A030C */  jal        vs_battle_setTextBox
    /* 147C 80103C7C 1000A527 */   addiu     $a1, $sp, 0x10
    /* 1480 80103C80 2004BF8F */  lw         $ra, 0x420($sp)
    /* 1484 80103C84 1C04B38F */  lw         $s3, 0x41C($sp)
    /* 1488 80103C88 1804B28F */  lw         $s2, 0x418($sp)
    /* 148C 80103C8C 1404B18F */  lw         $s1, 0x414($sp)
    /* 1490 80103C90 1004B08F */  lw         $s0, 0x410($sp)
    /* 1494 80103C94 0800E003 */  jr         $ra
    /* 1498 80103C98 2804BD27 */   addiu     $sp, $sp, 0x428
endlabel _copyNextPageText
