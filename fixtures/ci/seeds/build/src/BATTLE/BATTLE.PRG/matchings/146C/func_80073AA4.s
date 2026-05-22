nonmatching func_80073AA4, 0x28

glabel func_80073AA4
    /* B2A4 80073AA4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* B2A8 80073AA8 0F80033C */  lui        $v1, %hi(D_800F196C)
    /* B2AC 80073AAC 0B000224 */  addiu      $v0, $zero, 0xB
    /* B2B0 80073AB0 1000BFAF */  sw         $ra, 0x10($sp)
    /* B2B4 80073AB4 D4B0010C */  jal        func_8006C350
    /* B2B8 80073AB8 6C1962AC */   sw        $v0, %lo(D_800F196C)($v1)
    /* B2BC 80073ABC 1000BF8F */  lw         $ra, 0x10($sp)
    /* B2C0 80073AC0 00000000 */  nop
    /* B2C4 80073AC4 0800E003 */  jr         $ra
    /* B2C8 80073AC8 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80073AA4
