nonmatching func_800D4BD0, 0x48

glabel func_800D4BD0
    /* 6C3D0 800D4BD0 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 6C3D4 800D4BD4 1800B0AF */  sw         $s0, 0x18($sp)
    /* 6C3D8 800D4BD8 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 6C3DC 800D4BDC 5C54030C */  jal        func_800D5170
    /* 6C3E0 800D4BE0 21808000 */   addu      $s0, $a0, $zero
    /* 6C3E4 800D4BE4 FF004230 */  andi       $v0, $v0, 0xFF
    /* 6C3E8 800D4BE8 21100202 */  addu       $v0, $s0, $v0
    /* 6C3EC 800D4BEC 21200002 */  addu       $a0, $s0, $zero
    /* 6C3F0 800D4BF0 21300000 */  addu       $a2, $zero, $zero
    /* 6C3F4 800D4BF4 10004590 */  lbu        $a1, 0x10($v0)
    /* 6C3F8 800D4BF8 2138C000 */  addu       $a3, $a2, $zero
    /* 6C3FC 800D4BFC B74A030C */  jal        func_800D2ADC
    /* 6C400 800D4C00 1000A0AF */   sw        $zero, 0x10($sp)
    /* 6C404 800D4C04 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 6C408 800D4C08 1800B08F */  lw         $s0, 0x18($sp)
    /* 6C40C 800D4C0C 01000224 */  addiu      $v0, $zero, 0x1
    /* 6C410 800D4C10 0800E003 */  jr         $ra
    /* 6C414 800D4C14 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_800D4BD0
