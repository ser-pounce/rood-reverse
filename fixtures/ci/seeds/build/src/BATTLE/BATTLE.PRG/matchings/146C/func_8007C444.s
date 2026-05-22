nonmatching func_8007C444, 0x1C

glabel func_8007C444
    /* 13C44 8007C444 0F80023C */  lui        $v0, %hi(vs_battle_screenTransitionEffect)
    /* 13C48 8007C448 981A44AC */  sw         $a0, %lo(vs_battle_screenTransitionEffect)($v0)
    /* 13C4C 8007C44C 0F80023C */  lui        $v0, %hi(vs_battle_screenTransitionSpeed)
    /* 13C50 8007C450 A81A45AC */  sw         $a1, %lo(vs_battle_screenTransitionSpeed)($v0)
    /* 13C54 8007C454 0F80023C */  lui        $v0, %hi(vs_battle_screenTransitionWipeAngle)
    /* 13C58 8007C458 0800E003 */  jr         $ra
    /* 13C5C 8007C45C A41A46AC */   sw        $a2, %lo(vs_battle_screenTransitionWipeAngle)($v0)
endlabel func_8007C444
