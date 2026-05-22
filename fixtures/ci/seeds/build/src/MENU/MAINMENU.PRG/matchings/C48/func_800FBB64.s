nonmatching func_800FBB64, 0x28

glabel func_800FBB64
    /* 2364 800FBB64 1080023C */  lui        $v0, %hi(D_80102544)
    /* 2368 800FBB68 44254390 */  lbu        $v1, %lo(D_80102544)($v0)
    /* 236C 800FBB6C 01008224 */  addiu      $v0, $a0, 0x1
  .L800FBB70:
    /* 2370 800FBB70 03004430 */  andi       $a0, $v0, 0x3
    /* 2374 800FBB74 07108300 */  srav       $v0, $v1, $a0
    /* 2378 800FBB78 01004230 */  andi       $v0, $v0, 0x1
    /* 237C 800FBB7C FCFF4010 */  beqz       $v0, .L800FBB70
    /* 2380 800FBB80 01008224 */   addiu     $v0, $a0, 0x1
    /* 2384 800FBB84 0800E003 */  jr         $ra
    /* 2388 800FBB88 21108000 */   addu      $v0, $a0, $zero
endlabel func_800FBB64
