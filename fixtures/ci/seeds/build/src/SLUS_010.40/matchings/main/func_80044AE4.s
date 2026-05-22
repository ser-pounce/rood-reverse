nonmatching func_80044AE4, 0x2C

glabel func_80044AE4
    /* 352E4 80044AE4 1F000324 */  addiu      $v1, $zero, 0x1F
    /* 352E8 80044AE8 0580023C */  lui        $v0, %hi(_cdQueue)
    /* 352EC 80044AEC E0014224 */  addiu      $v0, $v0, %lo(_cdQueue)
    /* 352F0 80044AF0 6C024224 */  addiu      $v0, $v0, 0x26C
  .L80044AF4:
    /* 352F4 80044AF4 000040A4 */  sh         $zero, 0x0($v0)
    /* 352F8 80044AF8 FFFF6324 */  addiu      $v1, $v1, -0x1
    /* 352FC 80044AFC FDFF6104 */  bgez       $v1, .L80044AF4
    /* 35300 80044B00 ECFF4224 */   addiu     $v0, $v0, -0x14
    /* 35304 80044B04 0580023C */  lui        $v0, %hi(_cdQueueCount)
    /* 35308 80044B08 0800E003 */  jr         $ra
    /* 3530C 80044B0C 600440AC */   sw        $zero, %lo(_cdQueueCount)($v0)
endlabel func_80044AE4
