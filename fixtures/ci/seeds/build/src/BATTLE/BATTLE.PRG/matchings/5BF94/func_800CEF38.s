nonmatching func_800CEF38, 0x2C

glabel func_800CEF38
    /* 66738 800CEF38 0F80033C */  lui        $v1, %hi(D_800F5228)
    /* 6673C 800CEF3C 2852628C */  lw         $v0, %lo(D_800F5228)($v1)
    /* 66740 800CEF40 0F80053C */  lui        $a1, %hi(D_800F521C)
    /* 66744 800CEF44 FFFF4224 */  addiu      $v0, $v0, -0x1
    /* 66748 800CEF48 285262AC */  sw         $v0, %lo(D_800F5228)($v1)
    /* 6674C 800CEF4C 01000224 */  addiu      $v0, $zero, 0x1
    /* 66750 800CEF50 1C52A38C */  lw         $v1, %lo(D_800F521C)($a1)
    /* 66754 800CEF54 04108200 */  sllv       $v0, $v0, $a0
    /* 66758 800CEF58 25186200 */  or         $v1, $v1, $v0
    /* 6675C 800CEF5C 0800E003 */  jr         $ra
    /* 66760 800CEF60 1C52A3AC */   sw        $v1, %lo(D_800F521C)($a1)
endlabel func_800CEF38
