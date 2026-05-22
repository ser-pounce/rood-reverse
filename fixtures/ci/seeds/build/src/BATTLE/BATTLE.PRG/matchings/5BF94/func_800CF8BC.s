nonmatching func_800CF8BC, 0x64

glabel func_800CF8BC
    /* 670BC 800CF8BC 00FFBD27 */  addiu      $sp, $sp, -0x100
    /* 670C0 800CF8C0 38000224 */  addiu      $v0, $zero, 0x38
    /* 670C4 800CF8C4 1000A2A7 */  sh         $v0, 0x10($sp)
    /* 670C8 800CF8C8 01000224 */  addiu      $v0, $zero, 0x1
    /* 670CC 800CF8CC 1200A2A3 */  sb         $v0, 0x12($sp)
    /* 670D0 800CF8D0 04000224 */  addiu      $v0, $zero, 0x4
    /* 670D4 800CF8D4 1400A2A7 */  sh         $v0, 0x14($sp)
    /* 670D8 800CF8D8 0F80023C */  lui        $v0, %hi(D_800F5238)
    /* 670DC 800CF8DC 38524390 */  lbu        $v1, %lo(D_800F5238)($v0)
    /* 670E0 800CF8E0 05000224 */  addiu      $v0, $zero, 0x5
    /* 670E4 800CF8E4 1000A427 */  addiu      $a0, $sp, 0x10
    /* 670E8 800CF8E8 21280000 */  addu       $a1, $zero, $zero
    /* 670EC 800CF8EC F800BFAF */  sw         $ra, 0xF8($sp)
    /* 670F0 800CF8F0 1A00A0A3 */  sb         $zero, 0x1A($sp)
    /* 670F4 800CF8F4 2000A2A7 */  sh         $v0, 0x20($sp)
    /* 670F8 800CF8F8 2400A0A7 */  sh         $zero, 0x24($sp)
    /* 670FC 800CF8FC 2600A0A7 */  sh         $zero, 0x26($sp)
    /* 67100 800CF900 2800A0A7 */  sh         $zero, 0x28($sp)
    /* 67104 800CF904 1300A0A3 */  sb         $zero, 0x13($sp)
    /* 67108 800CF908 FE3C030C */  jal        func_800CF3F8
    /* 6710C 800CF90C 1800A3A3 */   sb        $v1, 0x18($sp)
    /* 67110 800CF910 F800BF8F */  lw         $ra, 0xF8($sp)
    /* 67114 800CF914 00000000 */  nop
    /* 67118 800CF918 0800E003 */  jr         $ra
    /* 6711C 800CF91C 0001BD27 */   addiu     $sp, $sp, 0x100
endlabel func_800CF8BC
