nonmatching func_8006FD0C, 0x10

glabel func_8006FD0C
    /* 750C 8006FD0C 0F80033C */  lui        $v1, %hi(_cameraMode)
    /* 7510 8006FD10 09000224 */  addiu      $v0, $zero, 0x9
    /* 7514 8006FD14 0800E003 */  jr         $ra
    /* 7518 8006FD18 F01862AC */   sw        $v0, %lo(_cameraMode)($v1)
endlabel func_8006FD0C
