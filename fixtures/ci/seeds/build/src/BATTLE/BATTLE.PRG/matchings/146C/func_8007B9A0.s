nonmatching func_8007B9A0, 0x2C

glabel func_8007B9A0
    /* 131A0 8007B9A0 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 131A4 8007B9A4 0F80023C */  lui        $v0, %hi(D_800F1860)
    /* 131A8 8007B9A8 601840AC */  sw         $zero, %lo(D_800F1860)($v0)
    /* 131AC 8007B9AC 0F80023C */  lui        $v0, %hi(D_800F1864)
    /* 131B0 8007B9B0 1000BFAF */  sw         $ra, 0x10($sp)
    /* 131B4 8007B9B4 F7ED010C */  jal        func_8007B7DC
    /* 131B8 8007B9B8 641840AC */   sw        $zero, %lo(D_800F1864)($v0)
    /* 131BC 8007B9BC 1000BF8F */  lw         $ra, 0x10($sp)
    /* 131C0 8007B9C0 00000000 */  nop
    /* 131C4 8007B9C4 0800E003 */  jr         $ra
    /* 131C8 8007B9C8 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8007B9A0
