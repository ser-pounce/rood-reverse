nonmatching func_8007352C, 0x28

glabel func_8007352C
    /* AD2C 8007352C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* AD30 80073530 0F80033C */  lui        $v1, %hi(D_800F196C)
    /* AD34 80073534 06000224 */  addiu      $v0, $zero, 0x6
    /* AD38 80073538 1000BFAF */  sw         $ra, 0x10($sp)
    /* AD3C 8007353C E7B0010C */  jal        func_8006C39C
    /* AD40 80073540 6C1962AC */   sw        $v0, %lo(D_800F196C)($v1)
    /* AD44 80073544 1000BF8F */  lw         $ra, 0x10($sp)
    /* AD48 80073548 00000000 */  nop
    /* AD4C 8007354C 0800E003 */  jr         $ra
    /* AD50 80073550 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8007352C
