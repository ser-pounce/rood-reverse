nonmatching func_800B9F90, 0x30

glabel func_800B9F90
    /* 51790 800B9F90 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 51794 800B9F94 1000BFAF */  sw         $ra, 0x10($sp)
    /* 51798 800B9F98 8D3C020C */  jal        func_8008F234
    /* 5179C 800B9F9C 00000000 */   nop
    /* 517A0 800B9FA0 0F80023C */  lui        $v0, %hi(D_800F4C2C)
    /* 517A4 800B9FA4 2C4C4290 */  lbu        $v0, %lo(D_800F4C2C)($v0)
    /* 517A8 800B9FA8 1000BF8F */  lw         $ra, 0x10($sp)
    /* 517AC 800B9FAC 02004238 */  xori       $v0, $v0, 0x2
    /* 517B0 800B9FB0 0100422C */  sltiu      $v0, $v0, 0x1
    /* 517B4 800B9FB4 80100200 */  sll        $v0, $v0, 2
    /* 517B8 800B9FB8 0800E003 */  jr         $ra
    /* 517BC 800B9FBC 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800B9F90
