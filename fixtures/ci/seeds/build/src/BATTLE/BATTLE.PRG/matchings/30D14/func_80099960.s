nonmatching func_80099960, 0x2C

glabel func_80099960
    /* 31160 80099960 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 31164 80099964 1000BFAF */  sw         $ra, 0x10($sp)
    /* 31168 80099968 21288000 */  addu       $a1, $a0, $zero
    /* 3116C 8009996C 0F80043C */  lui        $a0, %hi(D_800F4448)
    /* 31170 80099970 48448424 */  addiu      $a0, $a0, %lo(D_800F4448)
    /* 31174 80099974 2C24010C */  jal        vs_main_memcpy
    /* 31178 80099978 E0000624 */   addiu     $a2, $zero, 0xE0
    /* 3117C 8009997C 1000BF8F */  lw         $ra, 0x10($sp)
    /* 31180 80099980 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 31184 80099984 0800E003 */  jr         $ra
    /* 31188 80099988 00000000 */   nop
endlabel func_80099960
