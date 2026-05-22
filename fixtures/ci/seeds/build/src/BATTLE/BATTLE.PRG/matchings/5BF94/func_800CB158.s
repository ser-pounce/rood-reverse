nonmatching func_800CB158, 0x34

glabel func_800CB158
    /* 62958 800CB158 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 6295C 800CB15C 0F80023C */  lui        $v0, %hi(D_800EB9C4)
    /* 62960 800CB160 C4B944AC */  sw         $a0, %lo(D_800EB9C4)($v0)
    /* 62964 800CB164 0F80023C */  lui        $v0, %hi(D_800EB9C8)
    /* 62968 800CB168 0C000424 */  addiu      $a0, $zero, 0xC
    /* 6296C 800CB16C 02000524 */  addiu      $a1, $zero, 0x2
    /* 62970 800CB170 1000BFAF */  sw         $ra, 0x10($sp)
    /* 62974 800CB174 342B030C */  jal        func_800CACD0
    /* 62978 800CB178 C8B940AC */   sw        $zero, %lo(D_800EB9C8)($v0)
    /* 6297C 800CB17C 1000BF8F */  lw         $ra, 0x10($sp)
    /* 62980 800CB180 00000000 */  nop
    /* 62984 800CB184 0800E003 */  jr         $ra
    /* 62988 800CB188 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800CB158
