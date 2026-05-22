nonmatching vs_main_freeMusic, 0x70

glabel vs_main_freeMusic
    /* 35C40 80045440 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 35C44 80045444 1000B0AF */  sw         $s0, 0x10($sp)
    /* 35C48 80045448 21808000 */  addu       $s0, $a0, $zero
    /* 35C4C 8004544C 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 35C50 80045450 1800B2AF */  sw         $s2, 0x18($sp)
    /* 35C54 80045454 7D13010C */  jal        func_80044DF4
    /* 35C58 80045458 1400B1AF */   sw        $s1, 0x14($sp)
    /* 35C5C 8004545C 0680023C */  lui        $v0, %hi(vs_main_soundData)
    /* 35C60 80045460 38E05224 */  addiu      $s2, $v0, %lo(vs_main_soundData)
    /* 35C64 80045464 FFFF1126 */  addiu      $s1, $s0, -0x1
    /* 35C68 80045468 80101100 */  sll        $v0, $s1, 2
    /* 35C6C 8004546C 21805200 */  addu       $s0, $v0, $s2
    /* 35C70 80045470 2400048E */  lw         $a0, 0x24($s0)
    /* 35C74 80045474 00000000 */  nop
    /* 35C78 80045478 07008010 */  beqz       $a0, .L80045498
    /* 35C7C 8004547C 21100000 */   addu      $v0, $zero, $zero
    /* 35C80 80045480 180F010C */  jal        vs_main_freeHeapR
    /* 35C84 80045484 00000000 */   nop
    /* 35C88 80045488 01000224 */  addiu      $v0, $zero, 0x1
    /* 35C8C 8004548C 21183202 */  addu       $v1, $s1, $s2
    /* 35C90 80045490 240000AE */  sw         $zero, 0x24($s0)
    /* 35C94 80045494 100060A0 */  sb         $zero, 0x10($v1)
  .L80045498:
    /* 35C98 80045498 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 35C9C 8004549C 1800B28F */  lw         $s2, 0x18($sp)
    /* 35CA0 800454A0 1400B18F */  lw         $s1, 0x14($sp)
    /* 35CA4 800454A4 1000B08F */  lw         $s0, 0x10($sp)
    /* 35CA8 800454A8 0800E003 */  jr         $ra
    /* 35CAC 800454AC 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel vs_main_freeMusic
