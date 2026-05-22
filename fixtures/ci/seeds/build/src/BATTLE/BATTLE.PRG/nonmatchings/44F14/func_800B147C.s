/* Handwritten function */
nonmatching func_800B147C, 0x278

glabel func_800B147C
    /* 48C7C 800B147C 1000A88F */  lw         $t0, 0x10($sp)
    /* 48C80 800B1480 00130700 */  sll        $v0, $a3, 12
    /* 48C84 800B1484 9300E810 */  beq        $a3, $t0, .L800B16D4
    /* 48C88 800B1488 42180800 */   srl       $v1, $t0, 1
    /* 48C8C 800B148C 8A00E310 */  beq        $a3, $v1, .L800B16B8
    /* 48C90 800B1490 1A004800 */   div       $zero, $v0, $t0
    /* 48C94 800B1494 4801898C */  lw         $t1, 0x148($a0)
    /* 48C98 800B1498 4C018B84 */  lh         $t3, 0x14C($a0)
    /* 48C9C 800B149C 4801AC8C */  lw         $t4, 0x148($a1)
    /* 48CA0 800B14A0 4C01AE84 */  lh         $t6, 0x14C($a1)
    /* 48CA4 800B14A4 03540900 */  sra        $t2, $t1, 16
    /* 48CA8 800B14A8 036C0C00 */  sra        $t5, $t4, 16
    /* 48CAC 800B14AC 22C0AA01 */  sub        $t8, $t5, $t2 /* handwritten instruction */
    /* 48CB0 800B14B0 004C0900 */  sll        $t1, $t1, 16
    /* 48CB4 800B14B4 034C0900 */  sra        $t1, $t1, 16
    /* 48CB8 800B14B8 00640C00 */  sll        $t4, $t4, 16
    /* 48CBC 800B14BC 03640C00 */  sra        $t4, $t4, 16
    /* 48CC0 800B14C0 22788901 */  sub        $t7, $t4, $t1 /* handwritten instruction */
    /* 48CC4 800B14C4 12100000 */  mflo       $v0
    /* 48CC8 800B14C8 22C8CB01 */  sub        $t9, $t6, $t3 /* handwritten instruction */
    /* 48CCC 800B14CC 00408248 */  mtc2       $v0, $8 /* handwritten instruction */
    /* 48CD0 800B14D0 00488F48 */  mtc2       $t7, $9 /* handwritten instruction */
    /* 48CD4 800B14D4 00509848 */  mtc2       $t8, $10 /* handwritten instruction */
    /* 48CD8 800B14D8 00589948 */  mtc2       $t9, $11 /* handwritten instruction */
    /* 48CDC 800B14DC 2510F801 */  or         $v0, $t7, $t8
    /* 48CE0 800B14E0 25105900 */  or         $v0, $v0, $t9
    /* 48CE4 800B14E4 3D00984B */  gpf        1
    /* 48CE8 800B14E8 0000838C */  lw         $v1, 0x0($a0)
    /* 48CEC 800B14EC 0E004010 */  beqz       $v0, .L800B1528
    /* 48CF0 800B14F0 00C80F48 */   mfc2      $t7, $25 /* handwritten instruction */
    /* 48CF4 800B14F4 00D01848 */  mfc2       $t8, $26 /* handwritten instruction */
    /* 48CF8 800B14F8 00D81948 */  mfc2       $t9, $27 /* handwritten instruction */
    /* 48CFC 800B14FC 2510F801 */  or         $v0, $t7, $t8
    /* 48D00 800B1500 06004010 */  beqz       $v0, .L800B151C
    /* 48D04 800B1504 20482F01 */   add       $t1, $t1, $t7 /* handwritten instruction */
    /* 48D08 800B1508 20505801 */  add        $t2, $t2, $t8 /* handwritten instruction */
    /* 48D0C 800B150C FFFF2931 */  andi       $t1, $t1, 0xFFFF
    /* 48D10 800B1510 00540A00 */  sll        $t2, $t2, 16
    /* 48D14 800B1514 25482A01 */  or         $t1, $t1, $t2
    /* 48D18 800B1518 480189AC */  sw         $t1, 0x148($a0)
  .L800B151C:
    /* 48D1C 800B151C 02002013 */  beqz       $t9, .L800B1528
    /* 48D20 800B1520 20587901 */   add       $t3, $t3, $t9 /* handwritten instruction */
    /* 48D24 800B1524 4C018BAC */  sw         $t3, 0x14C($a0)
  .L800B1528:
    /* 48D28 800B1528 04008B84 */  lh         $t3, 0x4($a0)
    /* 48D2C 800B152C 0000AC8C */  lw         $t4, 0x0($a1)
    /* 48D30 800B1530 0400AE84 */  lh         $t6, 0x4($a1)
    /* 48D34 800B1534 03540300 */  sra        $t2, $v1, 16
    /* 48D38 800B1538 036C0C00 */  sra        $t5, $t4, 16
    /* 48D3C 800B153C 23C0AA01 */  subu       $t8, $t5, $t2
    /* 48D40 800B1540 004C0300 */  sll        $t1, $v1, 16
    /* 48D44 800B1544 034C0900 */  sra        $t1, $t1, 16
    /* 48D48 800B1548 00640C00 */  sll        $t4, $t4, 16
    /* 48D4C 800B154C 03640C00 */  sra        $t4, $t4, 16
    /* 48D50 800B1550 23788901 */  subu       $t7, $t4, $t1
    /* 48D54 800B1554 23C8CB01 */  subu       $t9, $t6, $t3
    /* 48D58 800B1558 0800E011 */  beqz       $t7, .L800B157C
    /* 48D5C 800B155C 0010E229 */   slti      $v0, $t7, 0x1000
    /* 48D60 800B1560 03004014 */  bnez       $v0, .L800B1570
    /* 48D64 800B1564 00F0E229 */   slti      $v0, $t7, -0x1000
    /* 48D68 800B1568 5FC50208 */  j          .L800B157C
    /* 48D6C 800B156C 00E0EF21 */   addi      $t7, $t7, -0x2000 /* handwritten instruction */
  .L800B1570:
    /* 48D70 800B1570 02004010 */  beqz       $v0, .L800B157C
    /* 48D74 800B1574 00000000 */   nop
    /* 48D78 800B1578 0020EF21 */  addi       $t7, $t7, 0x2000 /* handwritten instruction */
  .L800B157C:
    /* 48D7C 800B157C 00488F48 */  mtc2       $t7, $9 /* handwritten instruction */
    /* 48D80 800B1580 08000013 */  beqz       $t8, .L800B15A4
    /* 48D84 800B1584 0010022B */   slti      $v0, $t8, 0x1000
    /* 48D88 800B1588 03004014 */  bnez       $v0, .L800B1598
    /* 48D8C 800B158C 00F0022B */   slti      $v0, $t8, -0x1000
    /* 48D90 800B1590 69C50208 */  j          .L800B15A4
    /* 48D94 800B1594 00E01823 */   addi      $t8, $t8, -0x2000 /* handwritten instruction */
  .L800B1598:
    /* 48D98 800B1598 02004010 */  beqz       $v0, .L800B15A4
    /* 48D9C 800B159C 00000000 */   nop
    /* 48DA0 800B15A0 00201823 */  addi       $t8, $t8, 0x2000 /* handwritten instruction */
  .L800B15A4:
    /* 48DA4 800B15A4 00509848 */  mtc2       $t8, $10 /* handwritten instruction */
    /* 48DA8 800B15A8 09002013 */  beqz       $t9, .L800B15D0
    /* 48DAC 800B15AC 0010222B */   slti      $v0, $t9, 0x1000
    /* 48DB0 800B15B0 03004014 */  bnez       $v0, .L800B15C0
    /* 48DB4 800B15B4 00F0222B */   slti      $v0, $t9, -0x1000
    /* 48DB8 800B15B8 73C50208 */  j          .L800B15CC
    /* 48DBC 800B15BC 00E03923 */   addi      $t9, $t9, -0x2000 /* handwritten instruction */
  .L800B15C0:
    /* 48DC0 800B15C0 02004010 */  beqz       $v0, .L800B15CC
    /* 48DC4 800B15C4 00000000 */   nop
    /* 48DC8 800B15C8 00203923 */  addi       $t9, $t9, 0x2000 /* handwritten instruction */
  .L800B15CC:
    /* 48DCC 800B15CC 00589948 */  mtc2       $t9, $11 /* handwritten instruction */
  .L800B15D0:
    /* 48DD0 800B15D0 2510F801 */  or         $v0, $t7, $t8
    /* 48DD4 800B15D4 25105900 */  or         $v0, $v0, $t9
    /* 48DD8 800B15D8 3D00984B */  gpf        1
    /* 48DDC 800B15DC 5001838C */  lw         $v1, 0x150($a0)
    /* 48DE0 800B15E0 0E004010 */  beqz       $v0, .L800B161C
    /* 48DE4 800B15E4 00C80F48 */   mfc2      $t7, $25 /* handwritten instruction */
    /* 48DE8 800B15E8 00D01848 */  mfc2       $t8, $26 /* handwritten instruction */
    /* 48DEC 800B15EC 00D81948 */  mfc2       $t9, $27 /* handwritten instruction */
    /* 48DF0 800B15F0 2510F801 */  or         $v0, $t7, $t8
    /* 48DF4 800B15F4 06004010 */  beqz       $v0, .L800B1610
    /* 48DF8 800B15F8 20482F01 */   add       $t1, $t1, $t7 /* handwritten instruction */
    /* 48DFC 800B15FC 20505801 */  add        $t2, $t2, $t8 /* handwritten instruction */
    /* 48E00 800B1600 00540A00 */  sll        $t2, $t2, 16
    /* 48E04 800B1604 FFFF2931 */  andi       $t1, $t1, 0xFFFF
    /* 48E08 800B1608 25482A01 */  or         $t1, $t1, $t2
    /* 48E0C 800B160C 000089AC */  sw         $t1, 0x0($a0)
  .L800B1610:
    /* 48E10 800B1610 02002013 */  beqz       $t9, .L800B161C
    /* 48E14 800B1614 20587901 */   add       $t3, $t3, $t9 /* handwritten instruction */
    /* 48E18 800B1618 04008BAC */  sw         $t3, 0x4($a0)
  .L800B161C:
    /* 48E1C 800B161C 54018B84 */  lh         $t3, 0x154($a0)
    /* 48E20 800B1620 5001AC8C */  lw         $t4, 0x150($a1)
    /* 48E24 800B1624 5401AE84 */  lh         $t6, 0x154($a1)
    /* 48E28 800B1628 03540300 */  sra        $t2, $v1, 16
    /* 48E2C 800B162C 036C0C00 */  sra        $t5, $t4, 16
    /* 48E30 800B1630 23C0AA01 */  subu       $t8, $t5, $t2
    /* 48E34 800B1634 FFFF6930 */  andi       $t1, $v1, 0xFFFF
    /* 48E38 800B1638 FFFF8C31 */  andi       $t4, $t4, 0xFFFF
    /* 48E3C 800B163C 23788901 */  subu       $t7, $t4, $t1
    /* 48E40 800B1640 23C8CB01 */  subu       $t9, $t6, $t3
    /* 48E44 800B1644 00488F48 */  mtc2       $t7, $9 /* handwritten instruction */
    /* 48E48 800B1648 00509848 */  mtc2       $t8, $10 /* handwritten instruction */
    /* 48E4C 800B164C 00589948 */  mtc2       $t9, $11 /* handwritten instruction */
    /* 48E50 800B1650 2510F801 */  or         $v0, $t7, $t8
    /* 48E54 800B1654 25105900 */  or         $v0, $v0, $t9
    /* 48E58 800B1658 3D00984B */  gpf        1
    /* 48E5C 800B165C 0800838C */  lw         $v1, 0x8($a0)
    /* 48E60 800B1660 0E004010 */  beqz       $v0, .L800B169C
    /* 48E64 800B1664 00C80F48 */   mfc2      $t7, $25 /* handwritten instruction */
    /* 48E68 800B1668 00D01848 */  mfc2       $t8, $26 /* handwritten instruction */
    /* 48E6C 800B166C 00D81948 */  mfc2       $t9, $27 /* handwritten instruction */
    /* 48E70 800B1670 2510F801 */  or         $v0, $t7, $t8
    /* 48E74 800B1674 06004010 */  beqz       $v0, .L800B1690
    /* 48E78 800B1678 20482F01 */   add       $t1, $t1, $t7 /* handwritten instruction */
    /* 48E7C 800B167C 20505801 */  add        $t2, $t2, $t8 /* handwritten instruction */
    /* 48E80 800B1680 FFFF2931 */  andi       $t1, $t1, 0xFFFF
    /* 48E84 800B1684 00540A00 */  sll        $t2, $t2, 16
    /* 48E88 800B1688 25482A01 */  or         $t1, $t1, $t2
    /* 48E8C 800B168C 500189AC */  sw         $t1, 0x150($a0)
  .L800B1690:
    /* 48E90 800B1690 02002013 */  beqz       $t9, .L800B169C
    /* 48E94 800B1694 20587901 */   add       $t3, $t3, $t9 /* handwritten instruction */
    /* 48E98 800B1698 54018BAC */  sw         $t3, 0x154($a0)
  .L800B169C:
    /* 48E9C 800B169C 08008420 */  addi       $a0, $a0, 0x8 /* handwritten instruction */
    /* 48EA0 800B16A0 0800A520 */  addi       $a1, $a1, 0x8 /* handwritten instruction */
    /* 48EA4 800B16A4 FFFFC620 */  addi       $a2, $a2, -0x1 /* handwritten instruction */
    /* 48EA8 800B16A8 9FFFC014 */  bnez       $a2, .L800B1528
    /* 48EAC 800B16AC 00000000 */   nop
    /* 48EB0 800B16B0 0800E003 */  jr         $ra
    /* 48EB4 800B16B4 00000000 */   nop
  .L800B16B8:
    /* 48EB8 800B16B8 0000BFAF */  sw         $ra, 0x0($sp)
    /* 48EBC 800B16BC 60BA020C */  jal        func_800AE980
    /* 48EC0 800B16C0 00000000 */   nop
    /* 48EC4 800B16C4 0000BF8F */  lw         $ra, 0x0($sp)
    /* 48EC8 800B16C8 00000000 */  nop
    /* 48ECC 800B16CC 0800E003 */  jr         $ra
    /* 48ED0 800B16D0 00000000 */   nop
  .L800B16D4:
    /* 48ED4 800B16D4 0000BFAF */  sw         $ra, 0x0($sp)
    /* 48ED8 800B16D8 2C24010C */  jal        vs_main_memcpy
    /* 48EDC 800B16DC 0C060634 */   ori       $a2, $zero, 0x60C
    /* 48EE0 800B16E0 00000000 */  nop
    /* 48EE4 800B16E4 0000BF8F */  lw         $ra, 0x0($sp)
    /* 48EE8 800B16E8 00000000 */  nop
    /* 48EEC 800B16EC 0800E003 */  jr         $ra
    /* 48EF0 800B16F0 00000000 */   nop
endlabel func_800B147C
