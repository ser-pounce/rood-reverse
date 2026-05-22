nonmatching func_800B7EF0, 0x94

glabel func_800B7EF0
    /* 4F6F0 800B7EF0 D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 4F6F4 800B7EF4 2400B1AF */  sw         $s1, 0x24($sp)
    /* 4F6F8 800B7EF8 21888000 */  addu       $s1, $a0, $zero
    /* 4F6FC 800B7EFC 01002426 */  addiu      $a0, $s1, 0x1
    /* 4F700 800B7F00 2800BFAF */  sw         $ra, 0x28($sp)
    /* 4F704 800B7F04 80FF020C */  jal        vs_battle_getShort
    /* 4F708 800B7F08 2000B0AF */   sw        $s0, 0x20($sp)
    /* 4F70C 800B7F0C 94FF020C */  jal        func_800BFE50
    /* 4F710 800B7F10 FFFF4430 */   andi      $a0, $v0, 0xFFFF
    /* 4F714 800B7F14 03002426 */  addiu      $a0, $s1, 0x3
    /* 4F718 800B7F18 80FF020C */  jal        vs_battle_getShort
    /* 4F71C 800B7F1C 21804000 */   addu      $s0, $v0, $zero
    /* 4F720 800B7F20 94FF020C */  jal        func_800BFE50
    /* 4F724 800B7F24 FFFF4430 */   andi      $a0, $v0, 0xFFFF
    /* 4F728 800B7F28 21204000 */  addu       $a0, $v0, $zero
    /* 4F72C 800B7F2C 4284020C */  jal        func_800A1108
    /* 4F730 800B7F30 1000A527 */   addiu     $a1, $sp, 0x10
    /* 4F734 800B7F34 FFFF0624 */  addiu      $a2, $zero, -0x1
    /* 4F738 800B7F38 05002392 */  lbu        $v1, 0x5($s1)
    /* 4F73C 800B7F3C FF000224 */  addiu      $v0, $zero, 0xFF
    /* 4F740 800B7F40 02006210 */  beq        $v1, $v0, .L800B7F4C
    /* 4F744 800B7F44 FFFF1032 */   andi      $s0, $s0, 0xFFFF
    /* 4F748 800B7F48 21306000 */  addu       $a2, $v1, $zero
  .L800B7F4C:
    /* 4F74C 800B7F4C 21200002 */  addu       $a0, $s0, $zero
    /* 4F750 800B7F50 37A7020C */  jal        func_800A9CDC
    /* 4F754 800B7F54 1000A527 */   addiu     $a1, $sp, 0x10
    /* 4F758 800B7F58 0F80023C */  lui        $v0, %hi(D_800F4B70)
    /* 4F75C 800B7F5C 704B4224 */  addiu      $v0, $v0, %lo(D_800F4B70)
    /* 4F760 800B7F60 21100202 */  addu       $v0, $s0, $v0
    /* 4F764 800B7F64 01000324 */  addiu      $v1, $zero, 0x1
    /* 4F768 800B7F68 000043A0 */  sb         $v1, 0x0($v0)
    /* 4F76C 800B7F6C 2800BF8F */  lw         $ra, 0x28($sp)
    /* 4F770 800B7F70 2400B18F */  lw         $s1, 0x24($sp)
    /* 4F774 800B7F74 2000B08F */  lw         $s0, 0x20($sp)
    /* 4F778 800B7F78 21100000 */  addu       $v0, $zero, $zero
    /* 4F77C 800B7F7C 0800E003 */  jr         $ra
    /* 4F780 800B7F80 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel func_800B7EF0
