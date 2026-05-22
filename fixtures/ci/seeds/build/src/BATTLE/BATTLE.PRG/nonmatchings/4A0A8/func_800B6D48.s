nonmatching func_800B6D48, 0x244

glabel func_800B6D48
    /* 4E548 800B6D48 88FFBD27 */  addiu      $sp, $sp, -0x78
    /* 4E54C 800B6D4C 6400B3AF */  sw         $s3, 0x64($sp)
    /* 4E550 800B6D50 21988000 */  addu       $s3, $a0, $zero
    /* 4E554 800B6D54 6000B2AF */  sw         $s2, 0x60($sp)
    /* 4E558 800B6D58 21900000 */  addu       $s2, $zero, $zero
    /* 4E55C 800B6D5C 02006426 */  addiu      $a0, $s3, 0x2
    /* 4E560 800B6D60 7400BFAF */  sw         $ra, 0x74($sp)
    /* 4E564 800B6D64 7000B6AF */  sw         $s6, 0x70($sp)
    /* 4E568 800B6D68 6C00B5AF */  sw         $s5, 0x6C($sp)
    /* 4E56C 800B6D6C 6800B4AF */  sw         $s4, 0x68($sp)
    /* 4E570 800B6D70 5C00B1AF */  sw         $s1, 0x5C($sp)
    /* 4E574 800B6D74 80FF020C */  jal        vs_battle_getShort
    /* 4E578 800B6D78 5800B0AF */   sw        $s0, 0x58($sp)
    /* 4E57C 800B6D7C 94FF020C */  jal        func_800BFE50
    /* 4E580 800B6D80 FFFF4430 */   andi      $a0, $v0, 0xFFFF
    /* 4E584 800B6D84 21204000 */  addu       $a0, $v0, $zero
    /* 4E588 800B6D88 F1ED020C */  jal        func_800BB7C4
    /* 4E58C 800B6D8C 5000A527 */   addiu     $a1, $sp, 0x50
    /* 4E590 800B6D90 21884002 */  addu       $s1, $s2, $zero
    /* 4E594 800B6D94 2000B427 */  addiu      $s4, $sp, 0x20
    /* 4E598 800B6D98 0F80033C */  lui        $v1, %hi(D_800E9BEC)
    /* 4E59C 800B6D9C 5400A287 */  lh         $v0, 0x54($sp)
    /* 4E5A0 800B6DA0 EC9B7524 */  addiu      $s5, $v1, %lo(D_800E9BEC)
    /* 4E5A4 800B6DA4 00FC4224 */  addiu      $v0, $v0, -0x400
    /* 4E5A8 800B6DA8 000C4230 */  andi       $v0, $v0, 0xC00
    /* 4E5AC 800B6DAC 83120200 */  sra        $v0, $v0, 10
    /* 4E5B0 800B6DB0 5400A2A7 */  sh         $v0, 0x54($sp)
    /* 4E5B4 800B6DB4 5000A427 */  addiu      $a0, $sp, 0x50
  .L800B6DB8:
    /* 4E5B8 800B6DB8 21286002 */  addu       $a1, $s3, $zero
    /* 4E5BC 800B6DBC 001C1100 */  sll        $v1, $s1, 16
    /* 4E5C0 800B6DC0 031C0300 */  sra        $v1, $v1, 16
    /* 4E5C4 800B6DC4 21107500 */  addu       $v0, $v1, $s5
    /* 4E5C8 800B6DC8 00004790 */  lbu        $a3, 0x0($v0)
    /* 4E5CC 800B6DCC 40100300 */  sll        $v0, $v1, 1
    /* 4E5D0 800B6DD0 21104300 */  addu       $v0, $v0, $v1
    /* 4E5D4 800B6DD4 80100200 */  sll        $v0, $v0, 2
    /* 4E5D8 800B6DD8 21808202 */  addu       $s0, $s4, $v0
    /* 4E5DC 800B6DDC E6DA020C */  jal        func_800B6B98
    /* 4E5E0 800B6DE0 21300002 */   addu      $a2, $s0, $zero
    /* 4E5E4 800B6DE4 03004010 */  beqz       $v0, .L800B6DF4
    /* 4E5E8 800B6DE8 01002226 */   addiu     $v0, $s1, 0x1
    /* 4E5EC 800B6DEC 83DB0208 */  j          .L800B6E0C
    /* 4E5F0 800B6DF0 21900002 */   addu      $s2, $s0, $zero
  .L800B6DF4:
    /* 4E5F4 800B6DF4 21884000 */  addu       $s1, $v0, $zero
    /* 4E5F8 800B6DF8 00140200 */  sll        $v0, $v0, 16
    /* 4E5FC 800B6DFC 03140200 */  sra        $v0, $v0, 16
    /* 4E600 800B6E00 04004228 */  slti       $v0, $v0, 0x4
    /* 4E604 800B6E04 ECFF4014 */  bnez       $v0, .L800B6DB8
    /* 4E608 800B6E08 5000A427 */   addiu     $a0, $sp, 0x50
  .L800B6E0C:
    /* 4E60C 800B6E0C 16004016 */  bnez       $s2, .L800B6E68
    /* 4E610 800B6E10 01001124 */   addiu     $s1, $zero, 0x1
    /* 4E614 800B6E14 2000B227 */  addiu      $s2, $sp, 0x20
    /* 4E618 800B6E18 21284002 */  addu       $a1, $s2, $zero
    /* 4E61C 800B6E1C 001C1100 */  sll        $v1, $s1, 16
  .L800B6E20:
    /* 4E620 800B6E20 031C0300 */  sra        $v1, $v1, 16
    /* 4E624 800B6E24 40100300 */  sll        $v0, $v1, 1
    /* 4E628 800B6E28 21104300 */  addu       $v0, $v0, $v1
    /* 4E62C 800B6E2C 80100200 */  sll        $v0, $v0, 2
    /* 4E630 800B6E30 2120A200 */  addu       $a0, $a1, $v0
    /* 4E634 800B6E34 0800438E */  lw         $v1, 0x8($s2)
    /* 4E638 800B6E38 0800828C */  lw         $v0, 0x8($a0)
    /* 4E63C 800B6E3C 00000000 */  nop
    /* 4E640 800B6E40 2A104300 */  slt        $v0, $v0, $v1
    /* 4E644 800B6E44 02004010 */  beqz       $v0, .L800B6E50
    /* 4E648 800B6E48 01002226 */   addiu     $v0, $s1, 0x1
    /* 4E64C 800B6E4C 21908000 */  addu       $s2, $a0, $zero
  .L800B6E50:
    /* 4E650 800B6E50 21884000 */  addu       $s1, $v0, $zero
    /* 4E654 800B6E54 00140200 */  sll        $v0, $v0, 16
    /* 4E658 800B6E58 03140200 */  sra        $v0, $v0, 16
    /* 4E65C 800B6E5C 04004228 */  slti       $v0, $v0, 0x4
    /* 4E660 800B6E60 EFFF4014 */  bnez       $v0, .L800B6E20
    /* 4E664 800B6E64 001C1100 */   sll       $v1, $s1, 16
  .L800B6E68:
    /* 4E668 800B6E68 06006292 */  lbu        $v0, 0x6($s3)
    /* 4E66C 800B6E6C 04006426 */  addiu      $a0, $s3, 0x4
    /* 4E670 800B6E70 40880200 */  sll        $s1, $v0, 1
    /* 4E674 800B6E74 21882202 */  addu       $s1, $s1, $v0
    /* 4E678 800B6E78 80881100 */  sll        $s1, $s1, 2
    /* 4E67C 800B6E7C 07006292 */  lbu        $v0, 0x7($s3)
    /* 4E680 800B6E80 08003126 */  addiu      $s1, $s1, 0x8
    /* 4E684 800B6E84 40800200 */  sll        $s0, $v0, 1
    /* 4E688 800B6E88 21800202 */  addu       $s0, $s0, $v0
    /* 4E68C 800B6E8C 80801000 */  sll        $s0, $s0, 2
    /* 4E690 800B6E90 21800202 */  addu       $s0, $s0, $v0
    /* 4E694 800B6E94 80FF020C */  jal        vs_battle_getShort
    /* 4E698 800B6E98 04001026 */   addiu     $s0, $s0, 0x4
    /* 4E69C 800B6E9C 00140200 */  sll        $v0, $v0, 16
    /* 4E6A0 800B6EA0 032C0200 */  sra        $a1, $v0, 16
    /* 4E6A4 800B6EA4 06006292 */  lbu        $v0, 0x6($s3)
    /* 4E6A8 800B6EA8 01006492 */  lbu        $a0, 0x1($s3)
    /* 4E6AC 800B6EAC 04004686 */  lh         $a2, 0x4($s2)
    /* 4E6B0 800B6EB0 06004786 */  lh         $a3, 0x6($s2)
    /* 4E6B4 800B6EB4 1000A2AF */  sw         $v0, 0x10($sp)
    /* 4E6B8 800B6EB8 07006292 */  lbu        $v0, 0x7($s3)
    /* 4E6BC 800B6EBC 00000000 */  nop
    /* 4E6C0 800B6EC0 1400A2AF */  sw         $v0, 0x14($sp)
    /* 4E6C4 800B6EC4 04004286 */  lh         $v0, 0x4($s2)
    /* 4E6C8 800B6EC8 42881100 */  srl        $s1, $s1, 1
    /* 4E6CC 800B6ECC 21105100 */  addu       $v0, $v0, $s1
    /* 4E6D0 800B6ED0 1800A2AF */  sw         $v0, 0x18($sp)
    /* 4E6D4 800B6ED4 06004286 */  lh         $v0, 0x6($s2)
    /* 4E6D8 800B6ED8 42801000 */  srl        $s0, $s0, 1
    /* 4E6DC 800B6EDC 21105000 */  addu       $v0, $v0, $s0
    /* 4E6E0 800B6EE0 C233030C */  jal        vs_battle_initTextBox
    /* 4E6E4 800B6EE4 1C00A2AF */   sw        $v0, 0x1C($sp)
    /* 4E6E8 800B6EE8 01006492 */  lbu        $a0, 0x1($s3)
    /* 4E6EC 800B6EEC 7D33030C */  jal        vs_battle_getTextBox
    /* 4E6F0 800B6EF0 00000000 */   nop
    /* 4E6F4 800B6EF4 FFC0043C */  lui        $a0, (0xC0FFFFFF >> 16)
    /* 4E6F8 800B6EF8 FFFF8434 */  ori        $a0, $a0, (0xC0FFFFFF & 0xFFFF)
    /* 4E6FC 800B6EFC FFFF063C */  lui        $a2, (0xFFFF0FFF >> 16)
    /* 4E700 800B6F00 21284000 */  addu       $a1, $v0, $zero
    /* 4E704 800B6F04 FF0FC634 */  ori        $a2, $a2, (0xFFFF0FFF & 0xFFFF)
    /* 4E708 800B6F08 3F00C232 */  andi       $v0, $s6, 0x3F
    /* 4E70C 800B6F0C 0000A38C */  lw         $v1, 0x0($a1)
    /* 4E710 800B6F10 00160200 */  sll        $v0, $v0, 24
    /* 4E714 800B6F14 24186400 */  and        $v1, $v1, $a0
    /* 4E718 800B6F18 25186200 */  or         $v1, $v1, $v0
    /* 4E71C 800B6F1C 3FFF0424 */  addiu      $a0, $zero, -0xC1
    /* 4E720 800B6F20 0000A3AC */  sw         $v1, 0x0($a1)
    /* 4E724 800B6F24 03004292 */  lbu        $v0, 0x3($s2)
    /* 4E728 800B6F28 24186400 */  and        $v1, $v1, $a0
    /* 4E72C 800B6F2C 03004230 */  andi       $v0, $v0, 0x3
    /* 4E730 800B6F30 80110200 */  sll        $v0, $v0, 6
    /* 4E734 800B6F34 25186200 */  or         $v1, $v1, $v0
    /* 4E738 800B6F38 0000A3AC */  sw         $v1, 0x0($a1)
    /* 4E73C 800B6F3C 0000428E */  lw         $v0, 0x0($s2)
    /* 4E740 800B6F40 24186600 */  and        $v1, $v1, $a2
    /* 4E744 800B6F44 82130200 */  srl        $v0, $v0, 14
    /* 4E748 800B6F48 00F04230 */  andi       $v0, $v0, 0xF000
    /* 4E74C 800B6F4C 25186200 */  or         $v1, $v1, $v0
    /* 4E750 800B6F50 0000A3AC */  sw         $v1, 0x0($a1)
    /* 4E754 800B6F54 08006392 */  lbu        $v1, 0x8($s3)
    /* 4E758 800B6F58 00000000 */  nop
    /* 4E75C 800B6F5C 2E00A3A4 */  sh         $v1, 0x2E($a1)
    /* 4E760 800B6F60 7400BF8F */  lw         $ra, 0x74($sp)
    /* 4E764 800B6F64 7000B68F */  lw         $s6, 0x70($sp)
    /* 4E768 800B6F68 6C00B58F */  lw         $s5, 0x6C($sp)
    /* 4E76C 800B6F6C 6800B48F */  lw         $s4, 0x68($sp)
    /* 4E770 800B6F70 6400B38F */  lw         $s3, 0x64($sp)
    /* 4E774 800B6F74 6000B28F */  lw         $s2, 0x60($sp)
    /* 4E778 800B6F78 5C00B18F */  lw         $s1, 0x5C($sp)
    /* 4E77C 800B6F7C 5800B08F */  lw         $s0, 0x58($sp)
    /* 4E780 800B6F80 21100000 */  addu       $v0, $zero, $zero
    /* 4E784 800B6F84 0800E003 */  jr         $ra
    /* 4E788 800B6F88 7800BD27 */   addiu     $sp, $sp, 0x78
endlabel func_800B6D48
