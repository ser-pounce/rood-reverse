/* Handwritten function */
nonmatching ApplyMatrixLV, 0x15C

glabel ApplyMatrixLV
    /* 31DC8 800415C8 0000888C */  lw         $t0, 0x0($a0)
    /* 31DCC 800415CC 0400898C */  lw         $t1, 0x4($a0)
    /* 31DD0 800415D0 08008A8C */  lw         $t2, 0x8($a0)
    /* 31DD4 800415D4 0C008B8C */  lw         $t3, 0xC($a0)
    /* 31DD8 800415D8 10008C8C */  lw         $t4, 0x10($a0)
    /* 31DDC 800415DC 0000C848 */  ctc2       $t0, $0 /* handwritten instruction */
    /* 31DE0 800415E0 0008C948 */  ctc2       $t1, $1 /* handwritten instruction */
    /* 31DE4 800415E4 0010CA48 */  ctc2       $t2, $2 /* handwritten instruction */
    /* 31DE8 800415E8 0018CB48 */  ctc2       $t3, $3 /* handwritten instruction */
    /* 31DEC 800415EC 0020CC48 */  ctc2       $t4, $4 /* handwritten instruction */
    /* 31DF0 800415F0 0000A88C */  lw         $t0, 0x0($a1)
    /* 31DF4 800415F4 0800AA8C */  lw         $t2, 0x8($a1)
    /* 31DF8 800415F8 07000105 */  bgez       $t0, .L80041618
    /* 31DFC 800415FC 0400A98C */   lw        $t1, 0x4($a1)
    /* 31E00 80041600 23400800 */  negu       $t0, $t0
    /* 31E04 80041604 C35B0800 */  sra        $t3, $t0, 15
    /* 31E08 80041608 23580B00 */  negu       $t3, $t3
    /* 31E0C 8004160C FF7F0831 */  andi       $t0, $t0, 0x7FFF
    /* 31E10 80041610 03000010 */  b          .L80041620
    /* 31E14 80041614 23400800 */   negu      $t0, $t0
  .L80041618:
    /* 31E18 80041618 C35B0800 */  sra        $t3, $t0, 15
    /* 31E1C 8004161C FF7F0831 */  andi       $t0, $t0, 0x7FFF
  .L80041620:
    /* 31E20 80041620 07002105 */  bgez       $t1, .L80041640
    /* 31E24 80041624 00000000 */   nop
    /* 31E28 80041628 23480900 */  negu       $t1, $t1
    /* 31E2C 8004162C C3630900 */  sra        $t4, $t1, 15
    /* 31E30 80041630 23600C00 */  negu       $t4, $t4
    /* 31E34 80041634 FF7F2931 */  andi       $t1, $t1, 0x7FFF
    /* 31E38 80041638 03000010 */  b          .L80041648
    /* 31E3C 8004163C 23480900 */   negu      $t1, $t1
  .L80041640:
    /* 31E40 80041640 C3630900 */  sra        $t4, $t1, 15
    /* 31E44 80041644 FF7F2931 */  andi       $t1, $t1, 0x7FFF
  .L80041648:
    /* 31E48 80041648 07004105 */  bgez       $t2, .L80041668
    /* 31E4C 8004164C 00000000 */   nop
    /* 31E50 80041650 23500A00 */  negu       $t2, $t2
    /* 31E54 80041654 C36B0A00 */  sra        $t5, $t2, 15
    /* 31E58 80041658 23680D00 */  negu       $t5, $t5
    /* 31E5C 8004165C FF7F4A31 */  andi       $t2, $t2, 0x7FFF
    /* 31E60 80041660 03000010 */  b          .L80041670
    /* 31E64 80041664 23500A00 */   negu      $t2, $t2
  .L80041668:
    /* 31E68 80041668 C36B0A00 */  sra        $t5, $t2, 15
    /* 31E6C 8004166C FF7F4A31 */  andi       $t2, $t2, 0x7FFF
  .L80041670:
    /* 31E70 80041670 00488B48 */  mtc2       $t3, $9 /* handwritten instruction */
    /* 31E74 80041674 00508C48 */  mtc2       $t4, $10 /* handwritten instruction */
    /* 31E78 80041678 00588D48 */  mtc2       $t5, $11 /* handwritten instruction */
    /* 31E7C 8004167C 00000000 */  nop
    /* 31E80 80041680 12E0414A */  mvmva      0, 0, 3, 3, 0
    /* 31E84 80041684 00C80B48 */  mfc2       $t3, $25 /* handwritten instruction */
    /* 31E88 80041688 00D00C48 */  mfc2       $t4, $26 /* handwritten instruction */
    /* 31E8C 8004168C 00D80D48 */  mfc2       $t5, $27 /* handwritten instruction */
    /* 31E90 80041690 00488848 */  mtc2       $t0, $9 /* handwritten instruction */
    /* 31E94 80041694 00508948 */  mtc2       $t1, $10 /* handwritten instruction */
    /* 31E98 80041698 00588A48 */  mtc2       $t2, $11 /* handwritten instruction */
    /* 31E9C 8004169C 00000000 */  nop
    /* 31EA0 800416A0 12E0494A */  mvmva      1, 0, 3, 3, 0
    /* 31EA4 800416A4 05006105 */  bgez       $t3, .L800416BC
    /* 31EA8 800416A8 00000000 */   nop
    /* 31EAC 800416AC 23580B00 */  negu       $t3, $t3
    /* 31EB0 800416B0 C0580B00 */  sll        $t3, $t3, 3
    /* 31EB4 800416B4 02000010 */  b          .L800416C0
    /* 31EB8 800416B8 23580B00 */   negu      $t3, $t3
  .L800416BC:
    /* 31EBC 800416BC C0580B00 */  sll        $t3, $t3, 3
  .L800416C0:
    /* 31EC0 800416C0 05008105 */  bgez       $t4, .L800416D8
    /* 31EC4 800416C4 00000000 */   nop
    /* 31EC8 800416C8 23600C00 */  negu       $t4, $t4
    /* 31ECC 800416CC C0600C00 */  sll        $t4, $t4, 3
    /* 31ED0 800416D0 02000010 */  b          .L800416DC
    /* 31ED4 800416D4 23600C00 */   negu      $t4, $t4
  .L800416D8:
    /* 31ED8 800416D8 C0600C00 */  sll        $t4, $t4, 3
  .L800416DC:
    /* 31EDC 800416DC 0500A105 */  bgez       $t5, .L800416F4
    /* 31EE0 800416E0 00000000 */   nop
    /* 31EE4 800416E4 23680D00 */  negu       $t5, $t5
    /* 31EE8 800416E8 C0680D00 */  sll        $t5, $t5, 3
    /* 31EEC 800416EC 02000010 */  b          .L800416F8
    /* 31EF0 800416F0 23680D00 */   negu      $t5, $t5
  .L800416F4:
    /* 31EF4 800416F4 C0680D00 */  sll        $t5, $t5, 3
  .L800416F8:
    /* 31EF8 800416F8 00C80848 */  mfc2       $t0, $25 /* handwritten instruction */
    /* 31EFC 800416FC 00D00948 */  mfc2       $t1, $26 /* handwritten instruction */
    /* 31F00 80041700 00D80A48 */  mfc2       $t2, $27 /* handwritten instruction */
    /* 31F04 80041704 21400B01 */  addu       $t0, $t0, $t3
    /* 31F08 80041708 21482C01 */  addu       $t1, $t1, $t4
    /* 31F0C 8004170C 21504D01 */  addu       $t2, $t2, $t5
    /* 31F10 80041710 0000C8AC */  sw         $t0, 0x0($a2)
    /* 31F14 80041714 0400C9AC */  sw         $t1, 0x4($a2)
    /* 31F18 80041718 0800CAAC */  sw         $t2, 0x8($a2)
    /* 31F1C 8004171C 0800E003 */  jr         $ra
    /* 31F20 80041720 2110C000 */   addu      $v0, $a2, $zero
endlabel ApplyMatrixLV
