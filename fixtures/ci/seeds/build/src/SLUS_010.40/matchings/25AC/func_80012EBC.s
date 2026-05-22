nonmatching func_80012EBC, 0x34

glabel func_80012EBC
    /* 36BC 80012EBC FEFF063C */  lui        $a2, (0xFFFEFFFF >> 16)
    /* 36C0 80012EC0 FFFFC634 */  ori        $a2, $a2, (0xFFFEFFFF & 0xFFFF)
    /* 36C4 80012EC4 0480043C */  lui        $a0, %hi(g_Sound_GlobalFlags)
    /* 36C8 80012EC8 F89A8424 */  addiu      $a0, $a0, %lo(g_Sound_GlobalFlags)
    /* 36CC 80012ECC 0380053C */  lui        $a1, %hi(D_80036770)
    /* 36D0 80012ED0 0400838C */  lw         $v1, 0x4($a0)
    /* 36D4 80012ED4 7067A224 */  addiu      $v0, $a1, %lo(D_80036770)
    /* 36D8 80012ED8 040040AC */  sw         $zero, 0x4($v0)
    /* 36DC 80012EDC 21100000 */  addu       $v0, $zero, $zero
    /* 36E0 80012EE0 7067A0AC */  sw         $zero, %lo(D_80036770)($a1)
    /* 36E4 80012EE4 24186600 */  and        $v1, $v1, $a2
    /* 36E8 80012EE8 0800E003 */  jr         $ra
    /* 36EC 80012EEC 040083AC */   sw        $v1, 0x4($a0)
endlabel func_80012EBC
