nonmatching func_80074294, 0x10

glabel func_80074294
    /* BA94 80074294 0F80023C */  lui        $v0, %hi(D_800F1868)
    /* BA98 80074298 6818428C */  lw         $v0, %lo(D_800F1868)($v0)
    /* BA9C 8007429C 0800E003 */  jr         $ra
    /* BAA0 800742A0 03004230 */   andi      $v0, $v0, 0x3
endlabel func_80074294
