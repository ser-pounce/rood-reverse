nonmatching _padSetVsyncParam, 0x2C

glabel _padSetVsyncParam
    /* 1C5BC 8002BDBC 0480023C */  lui        $v0, %hi(D_8003FC04)
    /* 1C5C0 8002BDC0 04FC4224 */  addiu      $v0, $v0, %lo(D_8003FC04)
    /* 1C5C4 8002BDC4 0380033C */  lui        $v1, %hi(func_8002BE50)
    /* 1C5C8 8002BDC8 50BE6324 */  addiu      $v1, $v1, %lo(func_8002BE50)
    /* 1C5CC 8002BDCC 000043AC */  sw         $v1, 0x0($v0)
    /* 1C5D0 8002BDD0 0380033C */  lui        $v1, %hi(func_8002BDE8)
    /* 1C5D4 8002BDD4 E8BD6324 */  addiu      $v1, $v1, %lo(func_8002BDE8)
    /* 1C5D8 8002BDD8 040043AC */  sw         $v1, 0x4($v0)
    /* 1C5DC 8002BDDC FCFF40AC */  sw         $zero, -0x4($v0)
    /* 1C5E0 8002BDE0 0800E003 */  jr         $ra
    /* 1C5E4 8002BDE4 080040AC */   sw        $zero, 0x8($v0)
endlabel _padSetVsyncParam
