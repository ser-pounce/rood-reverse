nonmatching func_80048E68, 0x5C

glabel func_80048E68
    /* 39668 80048E68 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 3966C 80048E6C 21408000 */  addu       $t0, $a0, $zero
    /* 39670 80048E70 2148A000 */  addu       $t1, $a1, $zero
    /* 39674 80048E74 003C0700 */  sll        $a3, $a3, 16
    /* 39678 80048E78 3800A28F */  lw         $v0, 0x38($sp)
    /* 3967C 80048E7C 3C00A38F */  lw         $v1, 0x3C($sp)
    /* 39680 80048E80 033C0700 */  sra        $a3, $a3, 16
    /* 39684 80048E84 1000A7AF */  sw         $a3, 0x10($sp)
    /* 39688 80048E88 003C0600 */  sll        $a3, $a2, 16
    /* 3968C 80048E8C 08000424 */  addiu      $a0, $zero, 0x8
    /* 39690 80048E90 21280001 */  addu       $a1, $t0, $zero
    /* 39694 80048E94 21302001 */  addu       $a2, $t1, $zero
    /* 39698 80048E98 033C0700 */  sra        $a3, $a3, 16
    /* 3969C 80048E9C 2000BFAF */  sw         $ra, 0x20($sp)
    /* 396A0 80048EA0 00140200 */  sll        $v0, $v0, 16
    /* 396A4 80048EA4 03140200 */  sra        $v0, $v0, 16
    /* 396A8 80048EA8 1400A2AF */  sw         $v0, 0x14($sp)
    /* 396AC 80048EAC E322010C */  jal        func_80048B8C
    /* 396B0 80048EB0 1800A3AF */   sw        $v1, 0x18($sp)
    /* 396B4 80048EB4 2000BF8F */  lw         $ra, 0x20($sp)
    /* 396B8 80048EB8 00000000 */  nop
    /* 396BC 80048EBC 0800E003 */  jr         $ra
    /* 396C0 80048EC0 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_80048E68
