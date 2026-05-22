nonmatching vs_mainMenu_setUiGrip, 0xDC

glabel vs_mainMenu_setUiGrip
    /* 340C 800FCC0C D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 3410 800FCC10 1000B0AF */  sw         $s0, 0x10($sp)
    /* 3414 800FCC14 21808000 */  addu       $s0, $a0, $zero
    /* 3418 800FCC18 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 341C 800FCC1C 2198A000 */  addu       $s3, $a1, $zero
    /* 3420 800FCC20 2000B4AF */  sw         $s4, 0x20($sp)
    /* 3424 800FCC24 21A0C000 */  addu       $s4, $a2, $zero
    /* 3428 800FCC28 1400B1AF */  sw         $s1, 0x14($sp)
    /* 342C 800FCC2C 1080113C */  lui        $s1, %hi(vs_mainMenu_itemHelp)
    /* 3430 800FCC30 2400BFAF */  sw         $ra, 0x24($sp)
    /* 3434 800FCC34 1800B2AF */  sw         $s2, 0x18($sp)
    /* 3438 800FCC38 03000292 */  lbu        $v0, 0x3($s0)
    /* 343C 800FCC3C 4025238E */  lw         $v1, %lo(vs_mainMenu_itemHelp)($s1)
    /* 3440 800FCC40 40100200 */  sll        $v0, $v0, 1
    /* 3444 800FCC44 21104300 */  addu       $v0, $v0, $v1
    /* 3448 800FCC48 00054294 */  lhu        $v0, 0x500($v0)
    /* 344C 800FCC4C 0F80043C */  lui        $a0, %hi(D_800F51A4)
    /* 3450 800FCC50 40100200 */  sll        $v0, $v0, 1
    /* 3454 800FCC54 21106200 */  addu       $v0, $v1, $v0
    /* 3458 800FCC58 A45182AC */  sw         $v0, %lo(D_800F51A4)($a0)
    /* 345C 800FCC5C 00000296 */  lhu        $v0, 0x0($s0)
    /* 3460 800FCC60 2190E000 */  addu       $s2, $a3, $zero
    /* 3464 800FCC64 40100200 */  sll        $v0, $v0, 1
    /* 3468 800FCC68 21104300 */  addu       $v0, $v0, $v1
    /* 346C 800FCC6C F4FF4594 */  lhu        $a1, -0xC($v0)
    /* 3470 800FCC70 21204002 */  addu       $a0, $s2, $zero
    /* 3474 800FCC74 40280500 */  sll        $a1, $a1, 1
    /* 3478 800FCC78 171A030C */  jal        vs_battle_printf
    /* 347C 800FCC7C 21286500 */   addu      $a1, $v1, $a1
    /* 3480 800FCC80 4025258E */  lw         $a1, %lo(vs_mainMenu_itemHelp)($s1)
    /* 3484 800FCC84 21204000 */  addu       $a0, $v0, $zero
    /* 3488 800FCC88 171A030C */  jal        vs_battle_printf
    /* 348C 800FCC8C 0A68A524 */   addiu     $a1, $a1, 0x680A
    /* 3490 800FCC90 00000396 */  lhu        $v1, 0x0($s0)
    /* 3494 800FCC94 1080043C */  lui        $a0, %hi(vs_mainMenu_itemNames)
    /* 3498 800FCC98 040072AE */  sw         $s2, 0x4($s3)
    /* 349C 800FCC9C 40100300 */  sll        $v0, $v1, 1
    /* 34A0 800FCCA0 21104300 */  addu       $v0, $v0, $v1
    /* 34A4 800FCCA4 9C22838C */  lw         $v1, %lo(vs_mainMenu_itemNames)($a0)
    /* 34A8 800FCCA8 C0100200 */  sll        $v0, $v0, 3
    /* 34AC 800FCCAC 21186200 */  addu       $v1, $v1, $v0
    /* 34B0 800FCCB0 000063AE */  sw         $v1, 0x0($s3)
    /* 34B4 800FCCB4 03000292 */  lbu        $v0, 0x3($s0)
    /* 34B8 800FCCB8 00000000 */  nop
    /* 34BC 800FCCBC 0A004224 */  addiu      $v0, $v0, 0xA
    /* 34C0 800FCCC0 80160200 */  sll        $v0, $v0, 26
    /* 34C4 800FCCC4 000082AE */  sw         $v0, 0x0($s4)
    /* 34C8 800FCCC8 2400BF8F */  lw         $ra, 0x24($sp)
    /* 34CC 800FCCCC 2000B48F */  lw         $s4, 0x20($sp)
    /* 34D0 800FCCD0 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 34D4 800FCCD4 1800B28F */  lw         $s2, 0x18($sp)
    /* 34D8 800FCCD8 1400B18F */  lw         $s1, 0x14($sp)
    /* 34DC 800FCCDC 1000B08F */  lw         $s0, 0x10($sp)
    /* 34E0 800FCCE0 0800E003 */  jr         $ra
    /* 34E4 800FCCE4 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel vs_mainMenu_setUiGrip
