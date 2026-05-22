nonmatching vs_battle_setRoomsUnk0, 0xB0

glabel vs_battle_setRoomsUnk0
    /* 22CD8 8008B4D8 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 22CDC 8008B4DC 1400B1AF */  sw         $s1, 0x14($sp)
    /* 22CE0 8008B4E0 04009124 */  addiu      $s1, $a0, 0x4
    /* 22CE4 8008B4E4 2400BFAF */  sw         $ra, 0x24($sp)
    /* 22CE8 8008B4E8 2000B4AF */  sw         $s4, 0x20($sp)
    /* 22CEC 8008B4EC 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 22CF0 8008B4F0 1800B2AF */  sw         $s2, 0x18($sp)
    /* 22CF4 8008B4F4 1000B0AF */  sw         $s0, 0x10($sp)
    /* 22CF8 8008B4F8 0000938C */  lw         $s3, 0x0($a0)
    /* 22CFC 8008B4FC 00000000 */  nop
    /* 22D00 8008B500 1900601A */  blez       $s3, .L8008B568
    /* 22D04 8008B504 21900000 */   addu      $s2, $zero, $zero
    /* 22D08 8008B508 0680023C */  lui        $v0, %hi(vs_main_mapStatus)
    /* 22D0C 8008B50C D8FF5424 */  addiu      $s4, $v0, %lo(vs_main_mapStatus)
    /* 22D10 8008B510 0E009024 */  addiu      $s0, $a0, 0xE
  .L8008B514:
    /* 22D14 8008B514 00000586 */  lh         $a1, 0x0($s0)
    /* 22D18 8008B518 FEFF0486 */  lh         $a0, -0x2($s0)
    /* 22D1C 8008B51C 07F2010C */  jal        _getLocationId
    /* 22D20 8008B520 FFFFA524 */   addiu     $a1, $a1, -0x1
    /* 22D24 8008B524 0A004018 */  blez       $v0, .L8008B550
    /* 22D28 8008B528 43190200 */   sra       $v1, $v0, 5
    /* 22D2C 8008B52C 80180300 */  sll        $v1, $v1, 2
    /* 22D30 8008B530 21187400 */  addu       $v1, $v1, $s4
    /* 22D34 8008B534 1F004430 */  andi       $a0, $v0, 0x1F
    /* 22D38 8008B538 01000224 */  addiu      $v0, $zero, 0x1
    /* 22D3C 8008B53C 0000638C */  lw         $v1, 0x0($v1)
    /* 22D40 8008B540 04108200 */  sllv       $v0, $v0, $a0
    /* 22D44 8008B544 24186200 */  and        $v1, $v1, $v0
    /* 22D48 8008B548 552D0208 */  j          .L8008B554
    /* 22D4C 8008B54C 000023AE */   sw        $v1, 0x0($s1)
  .L8008B550:
    /* 22D50 8008B550 000020AE */  sw         $zero, 0x0($s1)
  .L8008B554:
    /* 22D54 8008B554 01005226 */  addiu      $s2, $s2, 0x1
    /* 22D58 8008B558 0C001026 */  addiu      $s0, $s0, 0xC
    /* 22D5C 8008B55C 2A105302 */  slt        $v0, $s2, $s3
    /* 22D60 8008B560 ECFF4014 */  bnez       $v0, .L8008B514
    /* 22D64 8008B564 0C003126 */   addiu     $s1, $s1, 0xC
  .L8008B568:
    /* 22D68 8008B568 2400BF8F */  lw         $ra, 0x24($sp)
    /* 22D6C 8008B56C 2000B48F */  lw         $s4, 0x20($sp)
    /* 22D70 8008B570 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 22D74 8008B574 1800B28F */  lw         $s2, 0x18($sp)
    /* 22D78 8008B578 1400B18F */  lw         $s1, 0x14($sp)
    /* 22D7C 8008B57C 1000B08F */  lw         $s0, 0x10($sp)
    /* 22D80 8008B580 0800E003 */  jr         $ra
    /* 22D84 8008B584 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel vs_battle_setRoomsUnk0
