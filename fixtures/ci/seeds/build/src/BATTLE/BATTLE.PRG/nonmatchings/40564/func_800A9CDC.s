nonmatching func_800A9CDC, 0x48

glabel func_800A9CDC
    /* 414DC 800A9CDC E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 414E0 800A9CE0 2138C000 */  addu       $a3, $a2, $zero
    /* 414E4 800A9CE4 0F80023C */  lui        $v0, %hi(D_800F4538)
    /* 414E8 800A9CE8 38454224 */  addiu      $v0, $v0, %lo(D_800F4538)
    /* 414EC 800A9CEC 80180400 */  sll        $v1, $a0, 2
    /* 414F0 800A9CF0 21186200 */  addu       $v1, $v1, $v0
    /* 414F4 800A9CF4 FFFF0224 */  addiu      $v0, $zero, -0x1
    /* 414F8 800A9CF8 1000BFAF */  sw         $ra, 0x10($sp)
    /* 414FC 800A9CFC 0000638C */  lw         $v1, 0x0($v1)
    /* 41500 800A9D00 0200E214 */  bne        $a3, $v0, .L800A9D0C
    /* 41504 800A9D04 00000000 */   nop
    /* 41508 800A9D08 C0056794 */  lhu        $a3, 0x5C0($v1)
  .L800A9D0C:
    /* 4150C 800A9D0C 24A9020C */  jal        func_800AA490
    /* 41510 800A9D10 FFFF0624 */   addiu     $a2, $zero, -0x1
    /* 41514 800A9D14 1000BF8F */  lw         $ra, 0x10($sp)
    /* 41518 800A9D18 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 4151C 800A9D1C 0800E003 */  jr         $ra
    /* 41520 800A9D20 00000000 */   nop
endlabel func_800A9CDC
