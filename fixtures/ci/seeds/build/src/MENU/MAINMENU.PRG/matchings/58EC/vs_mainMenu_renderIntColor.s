nonmatching vs_mainMenu_renderIntColor, 0xBC

glabel vs_mainMenu_renderIntColor
    /* 6564 800FFD64 D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 6568 800FFD68 2000B2AF */  sw         $s2, 0x20($sp)
    /* 656C 800FFD6C 21908000 */  addu       $s2, $a0, $zero
    /* 6570 800FFD70 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 6574 800FFD74 2188A000 */  addu       $s1, $a1, $zero
    /* 6578 800FFD78 2400B3AF */  sw         $s3, 0x24($sp)
    /* 657C 800FFD7C 2198C000 */  addu       $s3, $a2, $zero
    /* 6580 800FFD80 2800B4AF */  sw         $s4, 0x28($sp)
    /* 6584 800FFD84 21A0E000 */  addu       $s4, $a3, $zero
    /* 6588 800FFD88 1800B0AF */  sw         $s0, 0x18($sp)
    /* 658C 800FFD8C 21804002 */  addu       $s0, $s2, $zero
    /* 6590 800FFD90 02004106 */  bgez       $s2, .L800FFD9C
    /* 6594 800FFD94 2C00BFAF */   sw        $ra, 0x2C($sp)
    /* 6598 800FFD98 23801200 */  negu       $s0, $s2
  .L800FFD9C:
    /* 659C 800FFD9C 1533030C */  jal        vs_battle_toBCD
    /* 65A0 800FFDA0 21200002 */   addu      $a0, $s0, $zero
    /* 65A4 800FFDA4 21804000 */  addu       $s0, $v0, $zero
    /* 65A8 800FFDA8 0F000232 */  andi       $v0, $s0, 0xF
    /* 65AC 800FFDAC 00120200 */  sll        $v0, $v0, 8
    /* 65B0 800FFDB0 23304234 */  ori        $v0, $v0, 0x3023
    /* 65B4 800FFDB4 1000A2AF */  sw         $v0, 0x10($sp)
    /* 65B8 800FFDB8 1000A427 */  addiu      $a0, $sp, 0x10
    /* 65BC 800FFDBC 21282002 */  addu       $a1, $s1, $zero
    /* 65C0 800FFDC0 21306002 */  addu       $a2, $s3, $zero
    /* 65C4 800FFDC4 5019030C */  jal        vs_battle_renderTextRawColor
    /* 65C8 800FFDC8 21388002 */   addu      $a3, $s4, $zero
    /* 65CC 800FFDCC 03811000 */  sra        $s0, $s0, 4
    /* 65D0 800FFDD0 F2FF0016 */  bnez       $s0, .L800FFD9C
    /* 65D4 800FFDD4 F8FF3126 */   addiu     $s1, $s1, -0x8
    /* 65D8 800FFDD8 09004106 */  bgez       $s2, .L800FFE00
    /* 65DC 800FFDDC 21102002 */   addu      $v0, $s1, $zero
    /* 65E0 800FFDE0 232D0224 */  addiu      $v0, $zero, 0x2D23
    /* 65E4 800FFDE4 1000A2AF */  sw         $v0, 0x10($sp)
    /* 65E8 800FFDE8 1000A427 */  addiu      $a0, $sp, 0x10
    /* 65EC 800FFDEC 01002526 */  addiu      $a1, $s1, 0x1
    /* 65F0 800FFDF0 21306002 */  addu       $a2, $s3, $zero
    /* 65F4 800FFDF4 5019030C */  jal        vs_battle_renderTextRawColor
    /* 65F8 800FFDF8 21388002 */   addu      $a3, $s4, $zero
    /* 65FC 800FFDFC 21102002 */  addu       $v0, $s1, $zero
  .L800FFE00:
    /* 6600 800FFE00 2C00BF8F */  lw         $ra, 0x2C($sp)
    /* 6604 800FFE04 2800B48F */  lw         $s4, 0x28($sp)
    /* 6608 800FFE08 2400B38F */  lw         $s3, 0x24($sp)
    /* 660C 800FFE0C 2000B28F */  lw         $s2, 0x20($sp)
    /* 6610 800FFE10 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 6614 800FFE14 1800B08F */  lw         $s0, 0x18($sp)
    /* 6618 800FFE18 0800E003 */  jr         $ra
    /* 661C 800FFE1C 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel vs_mainMenu_renderIntColor
