nonmatching vs_main_loadClutTransition, 0x48

glabel vs_main_loadClutTransition
    /* 37480 80046C80 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 37484 80046C84 1000B0AF */  sw         $s0, 0x10($sp)
    /* 37488 80046C88 0580103C */  lui        $s0, %hi(_clutState)
    /* 3748C 80046C8C 585D0226 */  addiu      $v0, $s0, %lo(_clutState)
    /* 37490 80046C90 1400BFAF */  sw         $ra, 0x14($sp)
    /* 37494 80046C94 02004294 */  lhu        $v0, 0x2($v0)
    /* 37498 80046C98 00000000 */  nop
    /* 3749C 80046C9C 06004010 */  beqz       $v0, .L80046CB8
    /* 374A0 80046CA0 2118C000 */   addu      $v1, $a2, $zero
    /* 374A4 80046CA4 40310700 */  sll        $a2, $a3, 5
    /* 374A8 80046CA8 CF1A010C */  jal        _loadClutTransition
    /* 374AC 80046CAC 21306600 */   addu      $a2, $v1, $a2
    /* 374B0 80046CB0 01000224 */  addiu      $v0, $zero, 0x1
    /* 374B4 80046CB4 585D02A6 */  sh         $v0, %lo(_clutState)($s0)
  .L80046CB8:
    /* 374B8 80046CB8 1400BF8F */  lw         $ra, 0x14($sp)
    /* 374BC 80046CBC 1000B08F */  lw         $s0, 0x10($sp)
    /* 374C0 80046CC0 0800E003 */  jr         $ra
    /* 374C4 80046CC4 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel vs_main_loadClutTransition
