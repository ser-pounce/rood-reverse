nonmatching DS_cw_system, 0x40

glabel DS_cw_system
    /* 151C4 800249C4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 151C8 800249C8 0380033C */  lui        $v1, %hi(D_800326C0)
    /* 151CC 800249CC C0266324 */  addiu      $v1, $v1, %lo(D_800326C0)
    /* 151D0 800249D0 1000BFAF */  sw         $ra, 0x10($sp)
    /* 151D4 800249D4 0000628C */  lw         $v0, 0x0($v1)
    /* 151D8 800249D8 00000000 */  nop
    /* 151DC 800249DC 0500401C */  bgtz       $v0, .L800249F4
    /* 151E0 800249E0 21100000 */   addu      $v0, $zero, $zero
    /* 151E4 800249E4 20000224 */  addiu      $v0, $zero, 0x20
    /* 151E8 800249E8 D8FF62AC */  sw         $v0, -0x28($v1)
    /* 151EC 800249EC 8192000C */  jal        func_80024A04
    /* 151F0 800249F0 FF008430 */   andi      $a0, $a0, 0xFF
  .L800249F4:
    /* 151F4 800249F4 1000BF8F */  lw         $ra, 0x10($sp)
    /* 151F8 800249F8 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 151FC 800249FC 0800E003 */  jr         $ra
    /* 15200 80024A00 00000000 */   nop
endlabel DS_cw_system
