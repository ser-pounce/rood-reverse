nonmatching func_8007C460, 0xC

glabel func_8007C460
    /* 13C60 8007C460 0F80023C */  lui        $v0, %hi(vs_battle_screenTransitionWipeAngle)
    /* 13C64 8007C464 0800E003 */  jr         $ra
    /* 13C68 8007C468 A41A44AC */   sw        $a0, %lo(vs_battle_screenTransitionWipeAngle)($v0)
endlabel func_8007C460
