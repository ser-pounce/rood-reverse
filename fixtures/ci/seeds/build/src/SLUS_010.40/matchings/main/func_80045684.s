nonmatching func_80045684, 0x68

glabel func_80045684
    /* 35E84 80045684 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 35E88 80045688 1000B0AF */  sw         $s0, 0x10($sp)
    /* 35E8C 8004568C 21808000 */  addu       $s0, $a0, $zero
    /* 35E90 80045690 1400B1AF */  sw         $s1, 0x14($sp)
    /* 35E94 80045694 2188C000 */  addu       $s1, $a2, $zero
    /* 35E98 80045698 1800B2AF */  sw         $s2, 0x18($sp)
    /* 35E9C 8004569C 2190E000 */  addu       $s2, $a3, $zero
    /* 35EA0 800456A0 00020224 */  addiu      $v0, $zero, 0x200
    /* 35EA4 800456A4 0700A214 */  bne        $a1, $v0, .L800456C4
    /* 35EA8 800456A8 1C00BFAF */   sw        $ra, 0x1C($sp)
    /* 35EAC 800456AC D648000C */  jal        func_80012358
    /* 35EB0 800456B0 21204000 */   addu      $a0, $v0, $zero
    /* 35EB4 800456B4 07000212 */  beq        $s0, $v0, .L800456D4
    /* 35EB8 800456B8 21200002 */   addu      $a0, $s0, $zero
    /* 35EBC 800456BC B2150108 */  j          .L800456C8
    /* 35EC0 800456C0 00020524 */   addiu     $a1, $zero, 0x200
  .L800456C4:
    /* 35EC4 800456C4 21200002 */  addu       $a0, $s0, $zero
  .L800456C8:
    /* 35EC8 800456C8 21302002 */  addu       $a2, $s1, $zero
    /* 35ECC 800456CC 5F48000C */  jal        func_8001217C
    /* 35ED0 800456D0 21384002 */   addu      $a3, $s2, $zero
  .L800456D4:
    /* 35ED4 800456D4 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 35ED8 800456D8 1800B28F */  lw         $s2, 0x18($sp)
    /* 35EDC 800456DC 1400B18F */  lw         $s1, 0x14($sp)
    /* 35EE0 800456E0 1000B08F */  lw         $s0, 0x10($sp)
    /* 35EE4 800456E4 0800E003 */  jr         $ra
    /* 35EE8 800456E8 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_80045684
