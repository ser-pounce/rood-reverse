nonmatching RotMatrix_gte, 0x38

glabel RotMatrix_gte
    /* 31A00 80041200 0000828C */  lw         $v0, 0x0($a0)
    /* 31A04 80041204 0400988C */  lw         $t8, 0x4($a0)
    /* 31A08 80041208 0480063C */  lui        $a2, %hi(_trig_table)
    /* 31A0C 8004120C 1002C624 */  addiu      $a2, $a2, %lo(_trig_table)
    /* 31A10 80041210 04800F3C */  lui        $t7, %hi(func_80041104)
    /* 31A14 80041214 0411EF25 */  addiu      $t7, $t7, %lo(func_80041104)
    /* 31A18 80041218 0008C724 */  addiu      $a3, $a2, 0x800
  alabel D_8004121C
    /* 31A1C 8004121C 02491800 */  srl        $t1, $t8, 4
    /* 31A20 80041220 E0002931 */  andi       $t1, $t1, 0xE0
    /* 31A24 80041224 21482F01 */  addu       $t1, $t1, $t7
    /* 31A28 80041228 0480193C */  lui        $t9, %hi(D_8004121C)
    /* 31A2C 8004122C 1C123927 */  addiu      $t9, $t9, %lo(D_8004121C)
    /* 31A30 80041230 80C01800 */  sll        $t8, $t8, 2
    /* 31A34 80041234 08002001 */  jr         $t1
endlabel RotMatrix_gte
