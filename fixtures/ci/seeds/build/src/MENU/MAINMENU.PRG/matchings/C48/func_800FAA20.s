nonmatching func_800FAA20, 0x3C

glabel func_800FAA20
    /* 1220 800FAA20 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1224 800FAA24 1080023C */  lui        $v0, %hi(D_80102034)
    /* 1228 800FAA28 1000B0AF */  sw         $s0, 0x10($sp)
    /* 122C 800FAA2C 3420508C */  lw         $s0, %lo(D_80102034)($v0)
    /* 1230 800FAA30 28000424 */  addiu      $a0, $zero, 0x28
    /* 1234 800FAA34 1400BFAF */  sw         $ra, 0x14($sp)
    /* 1238 800FAA38 01001026 */  addiu      $s0, $s0, 0x1
    /* 123C 800FAA3C 38EA030C */  jal        vs_mainMenu_clearMenuExcept
    /* 1240 800FAA40 342050AC */   sw        $s0, %lo(D_80102034)($v0)
    /* 1244 800FAA44 0500103A */  xori       $s0, $s0, 0x5
    /* 1248 800FAA48 0100022E */  sltiu      $v0, $s0, 0x1
    /* 124C 800FAA4C 1400BF8F */  lw         $ra, 0x14($sp)
    /* 1250 800FAA50 1000B08F */  lw         $s0, 0x10($sp)
    /* 1254 800FAA54 0800E003 */  jr         $ra
    /* 1258 800FAA58 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800FAA20
