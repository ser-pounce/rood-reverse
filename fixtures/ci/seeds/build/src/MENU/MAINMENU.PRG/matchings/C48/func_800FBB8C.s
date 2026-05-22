nonmatching func_800FBB8C, 0x48

glabel func_800FBB8C
    /* 238C 800FBB8C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 2390 800FBB90 1000B0AF */  sw         $s0, 0x10($sp)
    /* 2394 800FBB94 1080103C */  lui        $s0, %hi(D_801024B9)
    /* 2398 800FBB98 B9240392 */  lbu        $v1, %lo(D_801024B9)($s0)
    /* 239C 800FBB9C 1080023C */  lui        $v0, %hi(D_80102544)
    /* 23A0 800FBBA0 1400BFAF */  sw         $ra, 0x14($sp)
    /* 23A4 800FBBA4 442544A0 */  sb         $a0, %lo(D_80102544)($v0)
    /* 23A8 800FBBA8 07206400 */  srav       $a0, $a0, $v1
    /* 23AC 800FBBAC 01008430 */  andi       $a0, $a0, 0x1
    /* 23B0 800FBBB0 04008014 */  bnez       $a0, .L800FBBC4
    /* 23B4 800FBBB4 00000000 */   nop
    /* 23B8 800FBBB8 D9EE030C */  jal        func_800FBB64
    /* 23BC 800FBBBC 21206000 */   addu      $a0, $v1, $zero
    /* 23C0 800FBBC0 B92402A2 */  sb         $v0, %lo(D_801024B9)($s0)
  .L800FBBC4:
    /* 23C4 800FBBC4 1400BF8F */  lw         $ra, 0x14($sp)
    /* 23C8 800FBBC8 1000B08F */  lw         $s0, 0x10($sp)
    /* 23CC 800FBBCC 0800E003 */  jr         $ra
    /* 23D0 800FBBD0 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800FBB8C
