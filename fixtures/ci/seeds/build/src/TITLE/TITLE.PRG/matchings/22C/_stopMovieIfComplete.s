nonmatching _stopMovieIfComplete, 0x50

glabel _stopMovieIfComplete
    /* 7204 8006FA04 0E80023C */  lui        $v0, %hi(_introMoviePlaying)
    /* 7208 8006FA08 7CED428C */  lw         $v0, %lo(_introMoviePlaying)($v0)
    /* 720C 8006FA0C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 7210 8006FA10 0C004010 */  beqz       $v0, .L8006FA44
    /* 7214 8006FA14 1000BFAF */   sw        $ra, 0x10($sp)
    /* 7218 8006FA18 B17D000C */  jal        VSync
    /* 721C 8006FA1C FFFF0424 */   addiu     $a0, $zero, -0x1
    /* 7220 8006FA20 0E80033C */  lui        $v1, %hi(_introMovieDisplayedAt)
    /* 7224 8006FA24 78ED638C */  lw         $v1, %lo(_introMovieDisplayedAt)($v1)
    /* 7228 8006FA28 00000000 */  nop
    /* 722C 8006FA2C 23104300 */  subu       $v0, $v0, $v1
    /* 7230 8006FA30 3111422C */  sltiu      $v0, $v0, 0x1131
    /* 7234 8006FA34 03004014 */  bnez       $v0, .L8006FA44
    /* 7238 8006FA38 00000000 */   nop
    /* 723C 8006FA3C 55BE010C */  jal        func_8006F954
    /* 7240 8006FA40 00000000 */   nop
  .L8006FA44:
    /* 7244 8006FA44 1000BF8F */  lw         $ra, 0x10($sp)
    /* 7248 8006FA48 00000000 */  nop
    /* 724C 8006FA4C 0800E003 */  jr         $ra
    /* 7250 8006FA50 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel _stopMovieIfComplete
