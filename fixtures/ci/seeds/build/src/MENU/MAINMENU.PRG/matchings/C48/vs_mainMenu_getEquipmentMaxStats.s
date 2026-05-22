nonmatching vs_mainMenu_getEquipmentMaxStats, 0x278

glabel vs_mainMenu_getEquipmentMaxStats
    /* D98 800FA598 21500000 */  addu       $t2, $zero, $zero
    /* D9C 800FA59C 21484001 */  addu       $t1, $t2, $zero
    /* DA0 800FA5A0 21384001 */  addu       $a3, $t2, $zero
    /* DA4 800FA5A4 01000224 */  addiu      $v0, $zero, 0x1
    /* DA8 800FA5A8 2900A210 */  beq        $a1, $v0, .L800FA650
    /* DAC 800FA5AC 21304001 */   addu      $a2, $t2, $zero
    /* DB0 800FA5B0 5100A014 */  bnez       $a1, .L800FA6F8
    /* DB4 800FA5B4 21280000 */   addu      $a1, $zero, $zero
    /* DB8 800FA5B8 21284001 */  addu       $a1, $t2, $zero
    /* DBC 800FA5BC 21408000 */  addu       $t0, $a0, $zero
  .L800FA5C0:
    /* DC0 800FA5C0 38010385 */  lh         $v1, 0x138($t0)
    /* DC4 800FA5C4 00000000 */  nop
    /* DC8 800FA5C8 2A10E300 */  slt        $v0, $a3, $v1
    /* DCC 800FA5CC 05004010 */  beqz       $v0, .L800FA5E4
    /* DD0 800FA5D0 2A10C300 */   slt       $v0, $a2, $v1
    /* DD4 800FA5D4 2130E000 */  addu       $a2, $a3, $zero
    /* DD8 800FA5D8 21386000 */  addu       $a3, $v1, $zero
    /* DDC 800FA5DC 7CE90308 */  j          .L800FA5F0
    /* DE0 800FA5E0 2148A000 */   addu      $t1, $a1, $zero
  .L800FA5E4:
    /* DE4 800FA5E4 02004010 */  beqz       $v0, .L800FA5F0
    /* DE8 800FA5E8 00000000 */   nop
    /* DEC 800FA5EC 21306000 */  addu       $a2, $v1, $zero
  .L800FA5F0:
    /* DF0 800FA5F0 0100A524 */  addiu      $a1, $a1, 0x1
    /* DF4 800FA5F4 0600A228 */  slti       $v0, $a1, 0x6
    /* DF8 800FA5F8 F1FF4014 */  bnez       $v0, .L800FA5C0
    /* DFC 800FA5FC 02000825 */   addiu     $t0, $t0, 0x2
    /* E00 800FA600 21280000 */  addu       $a1, $zero, $zero
  .L800FA604:
    /* E04 800FA604 58018384 */  lh         $v1, 0x158($a0)
    /* E08 800FA608 00000000 */  nop
    /* E0C 800FA60C 2A10E300 */  slt        $v0, $a3, $v1
    /* E10 800FA610 06004010 */  beqz       $v0, .L800FA62C
    /* E14 800FA614 2A10C300 */   slt       $v0, $a2, $v1
    /* E18 800FA618 2130E000 */  addu       $a2, $a3, $zero
    /* E1C 800FA61C 21386000 */  addu       $a3, $v1, $zero
    /* E20 800FA620 2148A000 */  addu       $t1, $a1, $zero
    /* E24 800FA624 8EE90308 */  j          .L800FA638
    /* E28 800FA628 01000A24 */   addiu     $t2, $zero, 0x1
  .L800FA62C:
    /* E2C 800FA62C 02004010 */  beqz       $v0, .L800FA638
    /* E30 800FA630 00000000 */   nop
    /* E34 800FA634 21306000 */  addu       $a2, $v1, $zero
  .L800FA638:
    /* E38 800FA638 0100A524 */  addiu      $a1, $a1, 0x1
    /* E3C 800FA63C 0700A228 */  slti       $v0, $a1, 0x7
    /* E40 800FA640 F0FF4014 */  bnez       $v0, .L800FA604
    /* E44 800FA644 02008424 */   addiu     $a0, $a0, 0x2
    /* E48 800FA648 E2E90308 */  j          .L800FA788
    /* E4C 800FA64C 21400000 */   addu      $t0, $zero, $zero
  .L800FA650:
    /* E50 800FA650 21280000 */  addu       $a1, $zero, $zero
    /* E54 800FA654 21408000 */  addu       $t0, $a0, $zero
  .L800FA658:
    /* E58 800FA658 04010385 */  lh         $v1, 0x104($t0)
    /* E5C 800FA65C 00000000 */  nop
    /* E60 800FA660 2A10E300 */  slt        $v0, $a3, $v1
    /* E64 800FA664 05004010 */  beqz       $v0, .L800FA67C
    /* E68 800FA668 2A10C300 */   slt       $v0, $a2, $v1
    /* E6C 800FA66C 2130E000 */  addu       $a2, $a3, $zero
    /* E70 800FA670 21386000 */  addu       $a3, $v1, $zero
    /* E74 800FA674 A2E90308 */  j          .L800FA688
    /* E78 800FA678 2148A000 */   addu      $t1, $a1, $zero
  .L800FA67C:
    /* E7C 800FA67C 02004010 */  beqz       $v0, .L800FA688
    /* E80 800FA680 00000000 */   nop
    /* E84 800FA684 21306000 */  addu       $a2, $v1, $zero
  .L800FA688:
    /* E88 800FA688 0100A524 */  addiu      $a1, $a1, 0x1
    /* E8C 800FA68C 0600A228 */  slti       $v0, $a1, 0x6
    /* E90 800FA690 F1FF4014 */  bnez       $v0, .L800FA658
    /* E94 800FA694 02000825 */   addiu     $t0, $t0, 0x2
    /* E98 800FA698 21280000 */  addu       $a1, $zero, $zero
  .L800FA69C:
    /* E9C 800FA69C 24018384 */  lh         $v1, 0x124($a0)
    /* EA0 800FA6A0 00000000 */  nop
    /* EA4 800FA6A4 2A10E300 */  slt        $v0, $a3, $v1
    /* EA8 800FA6A8 06004010 */  beqz       $v0, .L800FA6C4
    /* EAC 800FA6AC 2A10C300 */   slt       $v0, $a2, $v1
    /* EB0 800FA6B0 2130E000 */  addu       $a2, $a3, $zero
    /* EB4 800FA6B4 21386000 */  addu       $a3, $v1, $zero
    /* EB8 800FA6B8 2148A000 */  addu       $t1, $a1, $zero
    /* EBC 800FA6BC B4E90308 */  j          .L800FA6D0
    /* EC0 800FA6C0 01000A24 */   addiu     $t2, $zero, 0x1
  .L800FA6C4:
    /* EC4 800FA6C4 02004010 */  beqz       $v0, .L800FA6D0
    /* EC8 800FA6C8 00000000 */   nop
    /* ECC 800FA6CC 21306000 */  addu       $a2, $v1, $zero
  .L800FA6D0:
    /* ED0 800FA6D0 0100A524 */  addiu      $a1, $a1, 0x1
    /* ED4 800FA6D4 0700A228 */  slti       $v0, $a1, 0x7
    /* ED8 800FA6D8 F0FF4014 */  bnez       $v0, .L800FA69C
    /* EDC 800FA6DC 02008424 */   addiu     $a0, $a0, 0x2
    /* EE0 800FA6E0 E2E90308 */  j          .L800FA788
    /* EE4 800FA6E4 21400000 */   addu      $t0, $zero, $zero
  .L800FA6E8:
    /* EE8 800FA6E8 EEE90308 */  j          .L800FA7B8
    /* EEC 800FA6EC 2140A000 */   addu      $t0, $a1, $zero
  .L800FA6F0:
    /* EF0 800FA6F0 FBE90308 */  j          .L800FA7EC
    /* EF4 800FA6F4 2118A000 */   addu      $v1, $a1, $zero
  .L800FA6F8:
    /* EF8 800FA6F8 21408000 */  addu       $t0, $a0, $zero
  .L800FA6FC:
    /* EFC 800FA6FC 58000385 */  lh         $v1, 0x58($t0)
    /* F00 800FA700 00000000 */  nop
    /* F04 800FA704 2A10E300 */  slt        $v0, $a3, $v1
    /* F08 800FA708 05004010 */  beqz       $v0, .L800FA720
    /* F0C 800FA70C 2A10C300 */   slt       $v0, $a2, $v1
    /* F10 800FA710 2130E000 */  addu       $a2, $a3, $zero
    /* F14 800FA714 21386000 */  addu       $a3, $v1, $zero
    /* F18 800FA718 CBE90308 */  j          .L800FA72C
    /* F1C 800FA71C 2148A000 */   addu      $t1, $a1, $zero
  .L800FA720:
    /* F20 800FA720 02004010 */  beqz       $v0, .L800FA72C
    /* F24 800FA724 00000000 */   nop
    /* F28 800FA728 21306000 */  addu       $a2, $v1, $zero
  .L800FA72C:
    /* F2C 800FA72C 0100A524 */  addiu      $a1, $a1, 0x1
    /* F30 800FA730 0600A228 */  slti       $v0, $a1, 0x6
    /* F34 800FA734 F1FF4014 */  bnez       $v0, .L800FA6FC
    /* F38 800FA738 02000825 */   addiu     $t0, $t0, 0x2
    /* F3C 800FA73C 21280000 */  addu       $a1, $zero, $zero
  .L800FA740:
    /* F40 800FA740 78008384 */  lh         $v1, 0x78($a0)
    /* F44 800FA744 00000000 */  nop
    /* F48 800FA748 2A10E300 */  slt        $v0, $a3, $v1
    /* F4C 800FA74C 06004010 */  beqz       $v0, .L800FA768
    /* F50 800FA750 2A10C300 */   slt       $v0, $a2, $v1
    /* F54 800FA754 2130E000 */  addu       $a2, $a3, $zero
    /* F58 800FA758 21386000 */  addu       $a3, $v1, $zero
    /* F5C 800FA75C 2148A000 */  addu       $t1, $a1, $zero
    /* F60 800FA760 DDE90308 */  j          .L800FA774
    /* F64 800FA764 01000A24 */   addiu     $t2, $zero, 0x1
  .L800FA768:
    /* F68 800FA768 02004010 */  beqz       $v0, .L800FA774
    /* F6C 800FA76C 00000000 */   nop
    /* F70 800FA770 21306000 */  addu       $a2, $v1, $zero
  .L800FA774:
    /* F74 800FA774 0100A524 */  addiu      $a1, $a1, 0x1
    /* F78 800FA778 0700A228 */  slti       $v0, $a1, 0x7
    /* F7C 800FA77C F0FF4014 */  bnez       $v0, .L800FA740
    /* F80 800FA780 02008424 */   addiu     $a0, $a0, 0x2
    /* F84 800FA784 21400000 */  addu       $t0, $zero, $zero
  .L800FA788:
    /* F88 800FA788 21280001 */  addu       $a1, $t0, $zero
    /* F8C 800FA78C 1080023C */  lui        $v0, %hi(_weaponTitleSubmaxThresholds)
    /* F90 800FA790 14204324 */  addiu      $v1, $v0, %lo(_weaponTitleSubmaxThresholds)
  .L800FA794:
    /* F94 800FA794 00006284 */  lh         $v0, 0x0($v1)
    /* F98 800FA798 00000000 */  nop
    /* F9C 800FA79C 2A10C200 */  slt        $v0, $a2, $v0
    /* FA0 800FA7A0 D1FF4014 */  bnez       $v0, .L800FA6E8
    /* FA4 800FA7A4 00000000 */   nop
    /* FA8 800FA7A8 0100A524 */  addiu      $a1, $a1, 0x1
    /* FAC 800FA7AC 0B00A228 */  slti       $v0, $a1, 0xB
    /* FB0 800FA7B0 F8FF4014 */  bnez       $v0, .L800FA794
    /* FB4 800FA7B4 02006324 */   addiu     $v1, $v1, 0x2
  .L800FA7B8:
    /* FB8 800FA7B8 21180000 */  addu       $v1, $zero, $zero
    /* FBC 800FA7BC 21286000 */  addu       $a1, $v1, $zero
    /* FC0 800FA7C0 1080023C */  lui        $v0, %hi(_weaponTitleMaxThresholds)
    /* FC4 800FA7C4 2C204424 */  addiu      $a0, $v0, %lo(_weaponTitleMaxThresholds)
  .L800FA7C8:
    /* FC8 800FA7C8 00008284 */  lh         $v0, 0x0($a0)
    /* FCC 800FA7CC 00000000 */  nop
    /* FD0 800FA7D0 2A10E200 */  slt        $v0, $a3, $v0
    /* FD4 800FA7D4 C6FF4014 */  bnez       $v0, .L800FA6F0
    /* FD8 800FA7D8 00000000 */   nop
    /* FDC 800FA7DC 0100A524 */  addiu      $a1, $a1, 0x1
    /* FE0 800FA7E0 0300A228 */  slti       $v0, $a1, 0x3
    /* FE4 800FA7E4 F8FF4014 */  bnez       $v0, .L800FA7C8
    /* FE8 800FA7E8 02008424 */   addiu     $a0, $a0, 0x2
  .L800FA7EC:
    /* FEC 800FA7EC 40100A00 */  sll        $v0, $t2, 1
    /* FF0 800FA7F0 21104A00 */  addu       $v0, $v0, $t2
    /* FF4 800FA7F4 40100200 */  sll        $v0, $v0, 1
    /* FF8 800FA7F8 21104900 */  addu       $v0, $v0, $t1
    /* FFC 800FA7FC 001A0300 */  sll        $v1, $v1, 8
    /* 1000 800FA800 21180301 */  addu       $v1, $t0, $v1
    /* 1004 800FA804 00140200 */  sll        $v0, $v0, 16
    /* 1008 800FA808 0800E003 */  jr         $ra
    /* 100C 800FA80C 21106200 */   addu      $v0, $v1, $v0
endlabel vs_mainMenu_getEquipmentMaxStats
