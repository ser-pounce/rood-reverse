nonmatching func_8009E5C4, 0x50

glabel func_8009E5C4
    /* 35DC4 8009E5C4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 35DC8 8009E5C8 0F80033C */  lui        $v1, %hi(D_800F4538)
    /* 35DCC 8009E5CC 38456324 */  addiu      $v1, $v1, %lo(D_800F4538)
    /* 35DD0 8009E5D0 80100400 */  sll        $v0, $a0, 2
    /* 35DD4 8009E5D4 21104300 */  addu       $v0, $v0, $v1
    /* 35DD8 8009E5D8 1000BFAF */  sw         $ra, 0x10($sp)
    /* 35DDC 8009E5DC 0000428C */  lw         $v0, 0x0($v0)
    /* 35DE0 8009E5E0 00000000 */  nop
    /* 35DE4 8009E5E4 B8054390 */  lbu        $v1, 0x5B8($v0)
    /* 35DE8 8009E5E8 63000224 */  addiu      $v0, $zero, 0x63
    /* 35DEC 8009E5EC 05006210 */  beq        $v1, $v0, .L8009E604
    /* 35DF0 8009E5F0 C7000224 */   addiu     $v0, $zero, 0xC7
    /* 35DF4 8009E5F4 03006210 */  beq        $v1, $v0, .L8009E604
    /* 35DF8 8009E5F8 00000000 */   nop
    /* 35DFC 8009E5FC C079020C */  jal        func_8009E700
    /* 35E00 8009E600 01000524 */   addiu     $a1, $zero, 0x1
  .L8009E604:
    /* 35E04 8009E604 1000BF8F */  lw         $ra, 0x10($sp)
    /* 35E08 8009E608 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 35E0C 8009E60C 0800E003 */  jr         $ra
    /* 35E10 8009E610 00000000 */   nop
endlabel func_8009E5C4
