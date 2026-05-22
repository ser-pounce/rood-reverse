nonmatching func_800FFB68, 0x28

glabel func_800FFB68
    /* 6368 800FFB68 06008010 */  beqz       $a0, .L800FFB84
    /* 636C 800FFB6C 1080033C */   lui       $v1, %hi(D_801022DE)
    /* 6370 800FFB70 FCFF0224 */  addiu      $v0, $zero, -0x4
    /* 6374 800FFB74 DE2262A4 */  sh         $v0, %lo(D_801022DE)($v1)
    /* 6378 800FFB78 1080033C */  lui        $v1, %hi(D_801022E0)
    /* 637C 800FFB7C 80000224 */  addiu      $v0, $zero, 0x80
    /* 6380 800FFB80 E02262A4 */  sh         $v0, %lo(D_801022E0)($v1)
  .L800FFB84:
    /* 6384 800FFB84 1080023C */  lui        $v0, %hi(D_801022DC)
    /* 6388 800FFB88 0800E003 */  jr         $ra
    /* 638C 800FFB8C DC2244A0 */   sb        $a0, %lo(D_801022DC)($v0)
endlabel func_800FFB68
