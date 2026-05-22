nonmatching func_800704B0, 0x28

glabel func_800704B0
    /* 7CB0 800704B0 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 7CB4 800704B4 0F80033C */  lui        $v1, %hi(_cameraMode)
    /* 7CB8 800704B8 06000224 */  addiu      $v0, $zero, 0x6
    /* 7CBC 800704BC 1000BFAF */  sw         $ra, 0x10($sp)
    /* 7CC0 800704C0 483E030C */  jal        func_800CF920
    /* 7CC4 800704C4 F01862AC */   sw        $v0, %lo(_cameraMode)($v1)
    /* 7CC8 800704C8 1000BF8F */  lw         $ra, 0x10($sp)
    /* 7CCC 800704CC 00000000 */  nop
    /* 7CD0 800704D0 0800E003 */  jr         $ra
    /* 7CD4 800704D4 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800704B0
