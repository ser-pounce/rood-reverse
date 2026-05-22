nonmatching func_80080F78, 0xA8

glabel func_80080F78
    /* 18778 80080F78 D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 1877C 80080F7C 2000B2AF */  sw         $s2, 0x20($sp)
    /* 18780 80080F80 21908000 */  addu       $s2, $a0, $zero
    /* 18784 80080F84 1800B0AF */  sw         $s0, 0x18($sp)
    /* 18788 80080F88 2180A000 */  addu       $s0, $a1, $zero
    /* 1878C 80080F8C 2400B3AF */  sw         $s3, 0x24($sp)
    /* 18790 80080F90 2800BFAF */  sw         $ra, 0x28($sp)
    /* 18794 80080F94 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 18798 80080F98 0000428E */  lw         $v0, 0x0($s2)
    /* 1879C 80080F9C 0E00033C */  lui        $v1, (0xE0000 >> 16)
    /* 187A0 80080FA0 24104300 */  and        $v0, $v0, $v1
    /* 187A4 80080FA4 0200033C */  lui        $v1, (0x20000 >> 16)
    /* 187A8 80080FA8 16004310 */  beq        $v0, $v1, .L80081004
    /* 187AC 80080FAC 2198E000 */   addu      $s3, $a3, $zero
    /* 187B0 80080FB0 54000296 */  lhu        $v0, 0x54($s0)
    /* 187B4 80080FB4 00000000 */  nop
    /* 187B8 80080FB8 10004010 */  beqz       $v0, .L80080FFC
    /* 187BC 80080FBC 54001126 */   addiu     $s1, $s0, 0x54
    /* 187C0 80080FC0 0600C010 */  beqz       $a2, .L80080FDC
    /* 187C4 80080FC4 21282002 */   addu      $a1, $s1, $zero
    /* 187C8 80080FC8 FFFFC624 */  addiu      $a2, $a2, -0x1
    /* 187CC 80080FCC 57090292 */  lbu        $v0, 0x957($s0)
    /* 187D0 80080FD0 F0000724 */  addiu      $a3, $zero, 0xF0
    /* 187D4 80080FD4 A702020C */  jal        func_80080A9C
    /* 187D8 80080FD8 1000A2AF */   sw        $v0, 0x10($sp)
  .L80080FDC:
    /* 187DC 80080FDC 07006012 */  beqz       $s3, .L80080FFC
    /* 187E0 80080FE0 21204002 */   addu      $a0, $s2, $zero
    /* 187E4 80080FE4 21282002 */  addu       $a1, $s1, $zero
    /* 187E8 80080FE8 FFFF6626 */  addiu      $a2, $s3, -0x1
    /* 187EC 80080FEC 57090292 */  lbu        $v0, 0x957($s0)
    /* 187F0 80080FF0 F0000724 */  addiu      $a3, $zero, 0xF0
    /* 187F4 80080FF4 4D01020C */  jal        func_80080534
    /* 187F8 80080FF8 1000A2AF */   sw        $v0, 0x10($sp)
  .L80080FFC:
    /* 187FC 80080FFC E0F8010C */  jal        _calculateWeaponClassAffinity
    /* 18800 80081000 21200002 */   addu      $a0, $s0, $zero
  .L80081004:
    /* 18804 80081004 2800BF8F */  lw         $ra, 0x28($sp)
    /* 18808 80081008 2400B38F */  lw         $s3, 0x24($sp)
    /* 1880C 8008100C 2000B28F */  lw         $s2, 0x20($sp)
    /* 18810 80081010 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 18814 80081014 1800B08F */  lw         $s0, 0x18($sp)
    /* 18818 80081018 0800E003 */  jr         $ra
    /* 1881C 8008101C 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel func_80080F78
