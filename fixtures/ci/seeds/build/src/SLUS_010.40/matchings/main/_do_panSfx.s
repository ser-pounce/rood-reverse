nonmatching _do_panSfx, 0x50

glabel _do_panSfx
    /* 36258 80045A58 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 3625C 80045A5C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 36260 80045A60 21808000 */  addu       $s0, $a0, $zero
    /* 36264 80045A64 1400B1AF */  sw         $s1, 0x14($sp)
    /* 36268 80045A68 2188A000 */  addu       $s1, $a1, $zero
    /* 3626C 80045A6C 2120C000 */  addu       $a0, $a2, $zero
    /* 36270 80045A70 1800BFAF */  sw         $ra, 0x18($sp)
    /* 36274 80045A74 6B16010C */  jal        vs_main_computeSfxPan
    /* 36278 80045A78 2128E000 */   addu      $a1, $a3, $zero
    /* 3627C 80045A7C FFFF4730 */  andi       $a3, $v0, 0xFFFF
    /* 36280 80045A80 0400E018 */  blez       $a3, .L80045A94
    /* 36284 80045A84 03340200 */   sra       $a2, $v0, 16
    /* 36288 80045A88 21200002 */  addu       $a0, $s0, $zero
    /* 3628C 80045A8C D515010C */  jal        vs_main_playSfx
    /* 36290 80045A90 21282002 */   addu      $a1, $s1, $zero
  .L80045A94:
    /* 36294 80045A94 1800BF8F */  lw         $ra, 0x18($sp)
    /* 36298 80045A98 1400B18F */  lw         $s1, 0x14($sp)
    /* 3629C 80045A9C 1000B08F */  lw         $s0, 0x10($sp)
    /* 362A0 80045AA0 0800E003 */  jr         $ra
    /* 362A4 80045AA4 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel _do_panSfx
