nonmatching func_80072B9C, 0xC

glabel func_80072B9C
    /* A39C 80072B9C 0F80023C */  lui        $v0, %hi(_cameraMode)
    /* A3A0 80072BA0 0800E003 */  jr         $ra
    /* A3A4 80072BA4 F01840AC */   sw        $zero, %lo(_cameraMode)($v0)
endlabel func_80072B9C
