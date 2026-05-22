nonmatching func_80046494, 0x48

glabel func_80046494
    /* 36C94 80046494 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 36C98 80046498 80100600 */  sll        $v0, $a2, 2
    /* 36C9C 8004649C 21104500 */  addu       $v0, $v0, $a1
    /* 36CA0 800464A0 1000BFAF */  sw         $ra, 0x10($sp)
    /* 36CA4 800464A4 0400428C */  lw         $v0, 0x4($v0)
    /* 36CA8 800464A8 21188000 */  addu       $v1, $a0, $zero
    /* 36CAC 800464AC 2120A200 */  addu       $a0, $a1, $v0
    /* 36CB0 800464B0 2800A28F */  lw         $v0, 0x28($sp)
    /* 36CB4 800464B4 0300C014 */  bnez       $a2, .L800464C4
    /* 36CB8 800464B8 21280000 */   addu      $a1, $zero, $zero
    /* 36CBC 800464BC 21200000 */  addu       $a0, $zero, $zero
    /* 36CC0 800464C0 21286000 */  addu       $a1, $v1, $zero
  .L800464C4:
    /* 36CC4 800464C4 9349000C */  jal        func_8001264C
    /* 36CC8 800464C8 FF004630 */   andi      $a2, $v0, 0xFF
    /* 36CCC 800464CC 1000BF8F */  lw         $ra, 0x10($sp)
    /* 36CD0 800464D0 00000000 */  nop
    /* 36CD4 800464D4 0800E003 */  jr         $ra
    /* 36CD8 800464D8 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80046494
