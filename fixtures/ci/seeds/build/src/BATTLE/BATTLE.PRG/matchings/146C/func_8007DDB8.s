nonmatching func_8007DDB8, 0x1C

glabel func_8007DDB8
    /* 155B8 8007DDB8 0000838C */  lw         $v1, 0x0($a0)
    /* 155BC 8007DDBC 0F80023C */  lui        $v0, %hi(D_800F1A30)
    /* 155C0 8007DDC0 301A43AC */  sw         $v1, %lo(D_800F1A30)($v0)
    /* 155C4 8007DDC4 0400838C */  lw         $v1, 0x4($a0)
    /* 155C8 8007DDC8 301A4224 */  addiu      $v0, $v0, %lo(D_800F1A30)
    /* 155CC 8007DDCC 0800E003 */  jr         $ra
    /* 155D0 8007DDD0 040043AC */   sw        $v1, 0x4($v0)
endlabel func_8007DDB8
