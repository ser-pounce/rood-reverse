nonmatching func_800D48E4, 0x2C

glabel func_800D48E4
    /* 6C0E4 800D48E4 21288000 */  addu       $a1, $a0, $zero
    /* 6C0E8 800D48E8 0F80023C */  lui        $v0, %hi(D_800F522C)
    /* 6C0EC 800D48EC 2C524490 */  lbu        $a0, %lo(D_800F522C)($v0)
    /* 6C0F0 800D48F0 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 6C0F4 800D48F4 1000BFAF */  sw         $ra, 0x10($sp)
    /* 6C0F8 800D48F8 B751030C */  jal        func_800D46DC
    /* 6C0FC 800D48FC 0100842C */   sltiu     $a0, $a0, 0x1
    /* 6C100 800D4900 1000BF8F */  lw         $ra, 0x10($sp)
    /* 6C104 800D4904 01000224 */  addiu      $v0, $zero, 0x1
    /* 6C108 800D4908 0800E003 */  jr         $ra
    /* 6C10C 800D490C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800D48E4
