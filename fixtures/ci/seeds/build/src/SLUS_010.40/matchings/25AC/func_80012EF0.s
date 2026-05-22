nonmatching func_80012EF0, 0x20

glabel func_80012EF0
    /* 36F0 80012EF0 0480023C */  lui        $v0, %hi(g_Sound_GlobalFlags)
    /* 36F4 80012EF4 F89A438C */  lw         $v1, %lo(g_Sound_GlobalFlags)($v0)
    /* 36F8 80012EF8 0480043C */  lui        $a0, %hi(D_80039BCC)
    /* 36FC 80012EFC CC9B80AC */  sw         $zero, %lo(D_80039BCC)($a0)
    /* 3700 80012F00 01006334 */  ori        $v1, $v1, 0x1
    /* 3704 80012F04 F89A43AC */  sw         $v1, %lo(g_Sound_GlobalFlags)($v0)
    /* 3708 80012F08 0800E003 */  jr         $ra
    /* 370C 80012F0C 21100000 */   addu      $v0, $zero, $zero
endlabel func_80012EF0
