nonmatching func_80088CAC, 0x38

glabel func_80088CAC
    /* 204AC 80088CAC E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 204B0 80088CB0 0580023C */  lui        $v0, %hi(D_8005046A)
    /* 204B4 80088CB4 6A044394 */  lhu        $v1, %lo(D_8005046A)($v0)
    /* 204B8 80088CB8 02000224 */  addiu      $v0, $zero, 0x2
    /* 204BC 80088CBC 03006214 */  bne        $v1, $v0, .L80088CCC
    /* 204C0 80088CC0 1000BFAF */   sw        $ra, 0x10($sp)
    /* 204C4 80088CC4 33EF010C */  jal        func_8007BCCC
    /* 204C8 80088CC8 00000000 */   nop
  .L80088CCC:
    /* 204CC 80088CCC 6FA7010C */  jal        func_80069DBC
    /* 204D0 80088CD0 00000000 */   nop
    /* 204D4 80088CD4 1000BF8F */  lw         $ra, 0x10($sp)
    /* 204D8 80088CD8 00000000 */  nop
    /* 204DC 80088CDC 0800E003 */  jr         $ra
    /* 204E0 80088CE0 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80088CAC
