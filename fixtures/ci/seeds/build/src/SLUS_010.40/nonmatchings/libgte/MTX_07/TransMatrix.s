nonmatching TransMatrix, 0x20

glabel TransMatrix
    /* 320BC 800418BC 0000A88C */  lw         $t0, 0x0($a1)
    /* 320C0 800418C0 0400A98C */  lw         $t1, 0x4($a1)
    /* 320C4 800418C4 0800AA8C */  lw         $t2, 0x8($a1)
    /* 320C8 800418C8 140088AC */  sw         $t0, 0x14($a0)
    /* 320CC 800418CC 180089AC */  sw         $t1, 0x18($a0)
    /* 320D0 800418D0 1C008AAC */  sw         $t2, 0x1C($a0)
    /* 320D4 800418D4 0800E003 */  jr         $ra
    /* 320D8 800418D8 21108000 */   addu      $v0, $a0, $zero
endlabel TransMatrix
