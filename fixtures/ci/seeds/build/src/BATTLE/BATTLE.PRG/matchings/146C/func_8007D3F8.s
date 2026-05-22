nonmatching func_8007D3F8, 0x24

glabel func_8007D3F8
    /* 14BF8 8007D3F8 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 14BFC 8007D3FC 0F80023C */  lui        $v0, %hi(D_800F1ABC)
    /* 14C00 8007D400 1000BFAF */  sw         $ra, 0x10($sp)
    /* 14C04 8007D404 D8F4010C */  jal        func_8007D360
    /* 14C08 8007D408 BC1A40AC */   sw        $zero, %lo(D_800F1ABC)($v0)
    /* 14C0C 8007D40C 1000BF8F */  lw         $ra, 0x10($sp)
    /* 14C10 8007D410 00000000 */  nop
    /* 14C14 8007D414 0800E003 */  jr         $ra
    /* 14C18 8007D418 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8007D3F8
