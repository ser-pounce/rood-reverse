nonmatching vs_mainmenu_drawButton, 0x74

glabel vs_mainmenu_drawButton
    /* 6468 800FFC68 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 646C 800FFC6C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 6470 800FFC70 21808000 */  addu       $s0, $a0, $zero
    /* 6474 800FFC74 2118C000 */  addu       $v1, $a2, $zero
    /* 6478 800FFC78 0300E014 */  bnez       $a3, .L800FFC88
    /* 647C 800FFC7C 1400BFAF */   sw        $ra, 0x14($sp)
    /* 6480 800FFC80 801F023C */  lui        $v0, (0x1F800008 >> 16)
    /* 6484 800FFC84 0800478C */  lw         $a3, (0x1F800008 & 0xFFFF)($v0)
  .L800FFC88:
    /* 6488 800FFC88 1000063C */  lui        $a2, (0x100010 >> 16)
    /* 648C 800FFC8C 1000C634 */  ori        $a2, $a2, (0x100010 & 0xFFFF)
    /* 6490 800FFC90 FFFFA230 */  andi       $v0, $a1, 0xFFFF
    /* 6494 800FFC94 002C0300 */  sll        $a1, $v1, 16
    /* 6498 800FFC98 80000424 */  addiu      $a0, $zero, 0x80
    /* 649C 800FFC9C 8900030C */  jal        func_800C0224
    /* 64A0 800FFCA0 25284500 */   or        $a1, $v0, $a1
    /* 64A4 800FFCA4 03000432 */  andi       $a0, $s0, 0x3
    /* 64A8 800FFCA8 00210400 */  sll        $a0, $a0, 4
    /* 64AC 800FFCAC 04000332 */  andi       $v1, $s0, 0x4
    /* 64B0 800FFCB0 80180300 */  sll        $v1, $v1, 2
    /* 64B4 800FFCB4 80006324 */  addiu      $v1, $v1, 0x80
    /* 64B8 800FFCB8 001A0300 */  sll        $v1, $v1, 8
    /* 64BC 800FFCBC 25208300 */  or         $a0, $a0, $v1
    /* 64C0 800FFCC0 FB37033C */  lui        $v1, (0x37FB0000 >> 16)
    /* 64C4 800FFCC4 25208300 */  or         $a0, $a0, $v1
    /* 64C8 800FFCC8 100044AC */  sw         $a0, 0x10($v0)
    /* 64CC 800FFCCC 1400BF8F */  lw         $ra, 0x14($sp)
    /* 64D0 800FFCD0 1000B08F */  lw         $s0, 0x10($sp)
    /* 64D4 800FFCD4 0800E003 */  jr         $ra
    /* 64D8 800FFCD8 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel vs_mainmenu_drawButton
