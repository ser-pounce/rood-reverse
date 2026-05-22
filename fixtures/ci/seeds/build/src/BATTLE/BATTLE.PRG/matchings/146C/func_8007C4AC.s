nonmatching func_8007C4AC, 0x28

glabel func_8007C4AC
    /* 13CAC 8007C4AC 0F80033C */  lui        $v1, %hi(vs_battle_screenTransitionStep)
    /* 13CB0 8007C4B0 07000224 */  addiu      $v0, $zero, 0x7
    /* 13CB4 8007C4B4 481A62AC */  sw         $v0, %lo(vs_battle_screenTransitionStep)($v1)
    /* 13CB8 8007C4B8 0F80023C */  lui        $v0, %hi(vs_battle_screenTransitionEffect)
    /* 13CBC 8007C4BC 981A44AC */  sw         $a0, %lo(vs_battle_screenTransitionEffect)($v0)
    /* 13CC0 8007C4C0 0F80023C */  lui        $v0, %hi(vs_battle_screenTransitionSpeed)
    /* 13CC4 8007C4C4 A81A45AC */  sw         $a1, %lo(vs_battle_screenTransitionSpeed)($v0)
    /* 13CC8 8007C4C8 0F80023C */  lui        $v0, %hi(vs_battle_screenTransitionWipeAngle)
    /* 13CCC 8007C4CC 0800E003 */  jr         $ra
    /* 13CD0 8007C4D0 A41A46AC */   sw        $a2, %lo(vs_battle_screenTransitionWipeAngle)($v0)
endlabel func_8007C4AC
