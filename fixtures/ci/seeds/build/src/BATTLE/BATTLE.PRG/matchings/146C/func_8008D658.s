nonmatching func_8008D658, 0xB8

glabel func_8008D658
    /* 24E58 8008D658 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 24E5C 8008D65C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 24E60 8008D660 21808000 */  addu       $s0, $a0, $zero
    /* 24E64 8008D664 1400BFAF */  sw         $ra, 0x14($sp)
    /* 24E68 8008D668 08000286 */  lh         $v0, 0x8($s0)
    /* 24E6C 8008D66C 00000000 */  nop
    /* 24E70 8008D670 06004014 */  bnez       $v0, .L8008D68C
    /* 24E74 8008D674 7E000424 */   addiu     $a0, $zero, 0x7E
    /* 24E78 8008D678 6216010C */  jal        vs_main_playSfxDefault
    /* 24E7C 8008D67C 3B000524 */   addiu     $a1, $zero, 0x3B
    /* 24E80 8008D680 7E000424 */  addiu      $a0, $zero, 0x7E
    /* 24E84 8008D684 A7350208 */  j          .L8008D69C
    /* 24E88 8008D688 3C000524 */   addiu     $a1, $zero, 0x3C
  .L8008D68C:
    /* 24E8C 8008D68C 6216010C */  jal        vs_main_playSfxDefault
    /* 24E90 8008D690 3D000524 */   addiu     $a1, $zero, 0x3D
    /* 24E94 8008D694 7E000424 */  addiu      $a0, $zero, 0x7E
    /* 24E98 8008D698 3E000524 */  addiu      $a1, $zero, 0x3E
  .L8008D69C:
    /* 24E9C 8008D69C 6216010C */  jal        vs_main_playSfxDefault
    /* 24EA0 8008D6A0 00000000 */   nop
    /* 24EA4 8008D6A4 06000486 */  lh         $a0, 0x6($s0)
    /* 24EA8 8008D6A8 474A020C */  jal        func_8009291C
    /* 24EAC 8008D6AC 00000000 */   nop
    /* 24EB0 8008D6B0 00000486 */  lh         $a0, 0x0($s0)
    /* 24EB4 8008D6B4 02000586 */  lh         $a1, 0x2($s0)
    /* 24EB8 8008D6B8 08000286 */  lh         $v0, 0x8($s0)
    /* 24EBC 8008D6BC 04000686 */  lh         $a2, 0x4($s0)
    /* 24EC0 8008D6C0 0B0000A2 */  sb         $zero, 0xB($s0)
    /* 24EC4 8008D6C4 0100422C */  sltiu      $v0, $v0, 0x1
    /* 24EC8 8008D6C8 D92D020C */  jal        func_8008B764
    /* 24ECC 8008D6CC 080002A6 */   sh        $v0, 0x8($s0)
    /* 24ED0 8008D6D0 21284000 */  addu       $a1, $v0, $zero
    /* 24ED4 8008D6D4 0A00A010 */  beqz       $a1, .L8008D700
    /* 24ED8 8008D6D8 FFE30224 */   addiu     $v0, $zero, -0x1C01
    /* 24EDC 8008D6DC 0000A38C */  lw         $v1, 0x0($a1)
    /* 24EE0 8008D6E0 08000486 */  lh         $a0, 0x8($s0)
    /* 24EE4 8008D6E4 24186200 */  and        $v1, $v1, $v0
    /* 24EE8 8008D6E8 80100400 */  sll        $v0, $a0, 2
    /* 24EEC 8008D6EC 21104400 */  addu       $v0, $v0, $a0
    /* 24EF0 8008D6F0 07004230 */  andi       $v0, $v0, 0x7
    /* 24EF4 8008D6F4 80120200 */  sll        $v0, $v0, 10
    /* 24EF8 8008D6F8 25186200 */  or         $v1, $v1, $v0
    /* 24EFC 8008D6FC 0000A3AC */  sw         $v1, 0x0($a1)
  .L8008D700:
    /* 24F00 8008D700 1400BF8F */  lw         $ra, 0x14($sp)
    /* 24F04 8008D704 1000B08F */  lw         $s0, 0x10($sp)
    /* 24F08 8008D708 0800E003 */  jr         $ra
    /* 24F0C 8008D70C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8008D658
