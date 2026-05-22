nonmatching func_80073554, 0x28

glabel func_80073554
    /* AD54 80073554 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* AD58 80073558 0F80033C */  lui        $v1, %hi(D_800F196C)
    /* AD5C 8007355C 01000224 */  addiu      $v0, $zero, 0x1
    /* AD60 80073560 1000BFAF */  sw         $ra, 0x10($sp)
    /* AD64 80073564 03B1010C */  jal        func_8006C40C
    /* AD68 80073568 6C1962AC */   sw        $v0, %lo(D_800F196C)($v1)
    /* AD6C 8007356C 1000BF8F */  lw         $ra, 0x10($sp)
    /* AD70 80073570 00000000 */  nop
    /* AD74 80073574 0800E003 */  jr         $ra
    /* AD78 80073578 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80073554
