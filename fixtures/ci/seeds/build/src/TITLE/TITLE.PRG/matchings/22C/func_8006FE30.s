nonmatching func_8006FE30, 0x94

glabel func_8006FE30
    /* 7630 8006FE30 68FFBD27 */  addiu      $sp, $sp, -0x98
    /* 7634 8006FE34 1800A427 */  addiu      $a0, $sp, 0x18
    /* 7638 8006FE38 00020524 */  addiu      $a1, $zero, 0x200
    /* 763C 8006FE3C 10000624 */  addiu      $a2, $zero, 0x10
    /* 7640 8006FE40 2138A000 */  addu       $a3, $a1, $zero
    /* 7644 8006FE44 9000B0AF */  sw         $s0, 0x90($sp)
    /* 7648 8006FE48 E0011024 */  addiu      $s0, $zero, 0x1E0
    /* 764C 8006FE4C 9400BFAF */  sw         $ra, 0x94($sp)
    /* 7650 8006FE50 0DAD000C */  jal        SetDefDispEnv
    /* 7654 8006FE54 1000B0AF */   sw        $s0, 0x10($sp)
    /* 7658 8006FE58 3000A427 */  addiu      $a0, $sp, 0x30
    /* 765C 8006FE5C 00020524 */  addiu      $a1, $zero, 0x200
    /* 7660 8006FE60 21300000 */  addu       $a2, $zero, $zero
    /* 7664 8006FE64 2138A000 */  addu       $a3, $a1, $zero
    /* 7668 8006FE68 08000224 */  addiu      $v0, $zero, 0x8
    /* 766C 8006FE6C 2200A2A7 */  sh         $v0, 0x22($sp)
    /* 7670 8006FE70 E0000224 */  addiu      $v0, $zero, 0xE0
    /* 7674 8006FE74 2600A2A7 */  sh         $v0, 0x26($sp)
    /* 7678 8006FE78 01000224 */  addiu      $v0, $zero, 0x1
    /* 767C 8006FE7C 2800A2A3 */  sb         $v0, 0x28($sp)
    /* 7680 8006FE80 DDAC000C */  jal        SetDefDrawEnv
    /* 7684 8006FE84 1000B0AF */   sw        $s0, 0x10($sp)
  .L8006FE88:
    /* 7688 8006FE88 B17D000C */  jal        VSync
    /* 768C 8006FE8C 01000424 */   addiu     $a0, $zero, 0x1
    /* 7690 8006FE90 F8004228 */  slti       $v0, $v0, 0xF8
    /* 7694 8006FE94 FCFF4014 */  bnez       $v0, .L8006FE88
    /* 7698 8006FE98 00000000 */   nop
    /* 769C 8006FE9C A0A3000C */  jal        PutDispEnv
    /* 76A0 8006FEA0 1800A427 */   addiu     $a0, $sp, 0x18
    /* 76A4 8006FEA4 2DA3000C */  jal        PutDrawEnv
    /* 76A8 8006FEA8 3000A427 */   addiu     $a0, $sp, 0x30
    /* 76AC 8006FEAC B17D000C */  jal        VSync
    /* 76B0 8006FEB0 21200000 */   addu      $a0, $zero, $zero
    /* 76B4 8006FEB4 9400BF8F */  lw         $ra, 0x94($sp)
    /* 76B8 8006FEB8 9000B08F */  lw         $s0, 0x90($sp)
    /* 76BC 8006FEBC 0800E003 */  jr         $ra
    /* 76C0 8006FEC0 9800BD27 */   addiu     $sp, $sp, 0x98
endlabel func_8006FE30
