nonmatching func_800F9CCC, 0x420

glabel func_800F9CCC
    /* 4CC 800F9CCC B0FFBD27 */  addiu      $sp, $sp, -0x50
    /* 4D0 800F9CD0 00FF043C */  lui        $a0, (0xFF00FFFF >> 16)
    /* 4D4 800F9CD4 FFFF8434 */  ori        $a0, $a0, (0xFF00FFFF & 0xFFFF)
    /* 4D8 800F9CD8 FFFF063C */  lui        $a2, (0xFFFF00FF >> 16)
    /* 4DC 800F9CDC FF00C634 */  ori        $a2, $a2, (0xFFFF00FF & 0xFFFF)
    /* 4E0 800F9CE0 FF00053C */  lui        $a1, (0xFFFFFF >> 16)
    /* 4E4 800F9CE4 FFFFA534 */  ori        $a1, $a1, (0xFFFFFF & 0xFFFF)
    /* 4E8 800F9CE8 21480000 */  addu       $t1, $zero, $zero
    /* 4EC 800F9CEC 3000B2AF */  sw         $s2, 0x30($sp)
    /* 4F0 800F9CF0 21902001 */  addu       $s2, $t1, $zero
    /* 4F4 800F9CF4 2C00B1AF */  sw         $s1, 0x2C($sp)
    /* 4F8 800F9CF8 21882001 */  addu       $s1, $t1, $zero
    /* 4FC 800F9CFC 0680023C */  lui        $v0, %hi(vs_battle_inventory)
    /* 500 800F9D00 68014824 */  addiu      $t0, $v0, %lo(vs_battle_inventory)
    /* 504 800F9D04 21580001 */  addu       $t3, $t0, $zero
    /* 508 800F9D08 2000A28F */  lw         $v0, 0x20($sp)
    /* 50C 800F9D0C 00FF0324 */  addiu      $v1, $zero, -0x100
    /* 510 800F9D10 4C00BFAF */  sw         $ra, 0x4C($sp)
    /* 514 800F9D14 4800BEAF */  sw         $fp, 0x48($sp)
    /* 518 800F9D18 4400B7AF */  sw         $s7, 0x44($sp)
    /* 51C 800F9D1C 4000B6AF */  sw         $s6, 0x40($sp)
    /* 520 800F9D20 3C00B5AF */  sw         $s5, 0x3C($sp)
    /* 524 800F9D24 3800B4AF */  sw         $s4, 0x38($sp)
    /* 528 800F9D28 3400B3AF */  sw         $s3, 0x34($sp)
    /* 52C 800F9D2C 2800B0AF */  sw         $s0, 0x28($sp)
    /* 530 800F9D30 24104300 */  and        $v0, $v0, $v1
    /* 534 800F9D34 04004234 */  ori        $v0, $v0, 0x4
    /* 538 800F9D38 24104400 */  and        $v0, $v0, $a0
    /* 53C 800F9D3C 0200033C */  lui        $v1, (0x20000 >> 16)
    /* 540 800F9D40 25104300 */  or         $v0, $v0, $v1
    /* 544 800F9D44 24104600 */  and        $v0, $v0, $a2
    /* 548 800F9D48 24104500 */  and        $v0, $v0, $a1
    /* 54C 800F9D4C 0080033C */  lui        $v1, (0x80000000 >> 16)
    /* 550 800F9D50 25104300 */  or         $v0, $v0, $v1
    /* 554 800F9D54 2000A2AF */  sw         $v0, 0x20($sp)
  .L800F9D58:
    /* 558 800F9D58 03000291 */  lbu        $v0, 0x3($t0)
    /* 55C 800F9D5C 00000000 */  nop
    /* 560 800F9D60 0C004010 */  beqz       $v0, .L800F9D94
    /* 564 800F9D64 00000000 */   nop
    /* 568 800F9D68 01000391 */  lbu        $v1, 0x1($t0)
    /* 56C 800F9D6C 01003226 */  addiu      $s2, $s1, 0x1
    /* 570 800F9D70 FFFF6324 */  addiu      $v1, $v1, -0x1
    /* 574 800F9D74 40100300 */  sll        $v0, $v1, 1
    /* 578 800F9D78 21104300 */  addu       $v0, $v0, $v1
    /* 57C 800F9D7C 80100200 */  sll        $v0, $v0, 2
    /* 580 800F9D80 23104300 */  subu       $v0, $v0, $v1
    /* 584 800F9D84 80100200 */  sll        $v0, $v0, 2
    /* 588 800F9D88 21104B00 */  addu       $v0, $v0, $t3
    /* 58C 800F9D8C 82024990 */  lbu        $t1, 0x282($v0)
    /* 590 800F9D90 A8024794 */  lhu        $a3, 0x2A8($v0)
  .L800F9D94:
    /* 594 800F9D94 01003126 */  addiu      $s1, $s1, 0x1
    /* 598 800F9D98 0800222A */  slti       $v0, $s1, 0x8
    /* 59C 800F9D9C EEFF4014 */  bnez       $v0, .L800F9D58
    /* 5A0 800F9DA0 20000825 */   addiu     $t0, $t0, 0x20
    /* 5A4 800F9DA4 21400000 */  addu       $t0, $zero, $zero
    /* 5A8 800F9DA8 21980001 */  addu       $s3, $t0, $zero
    /* 5AC 800F9DAC 21880001 */  addu       $s1, $t0, $zero
    /* 5B0 800F9DB0 0680023C */  lui        $v0, %hi(vs_battle_inventory)
    /* 5B4 800F9DB4 68014324 */  addiu      $v1, $v0, %lo(vs_battle_inventory)
  .L800F9DB8:
    /* 5B8 800F9DB8 01016290 */  lbu        $v0, 0x101($v1)
    /* 5BC 800F9DBC 00000000 */  nop
    /* 5C0 800F9DC0 04004010 */  beqz       $v0, .L800F9DD4
    /* 5C4 800F9DC4 00000000 */   nop
    /* 5C8 800F9DC8 01003326 */  addiu      $s3, $s1, 0x1
    /* 5CC 800F9DCC 06016890 */  lbu        $t0, 0x106($v1)
    /* 5D0 800F9DD0 28016A94 */  lhu        $t2, 0x128($v1)
  .L800F9DD4:
    /* 5D4 800F9DD4 01003126 */  addiu      $s1, $s1, 0x1
    /* 5D8 800F9DD8 0800222A */  slti       $v0, $s1, 0x8
    /* 5DC 800F9DDC F6FF4014 */  bnez       $v0, .L800F9DB8
    /* 5E0 800F9DE0 30006324 */   addiu     $v1, $v1, 0x30
    /* 5E4 800F9DE4 21200000 */  addu       $a0, $zero, $zero
    /* 5E8 800F9DE8 21288000 */  addu       $a1, $a0, $zero
    /* 5EC 800F9DEC 21302001 */  addu       $a2, $t1, $zero
    /* 5F0 800F9DF0 2000A227 */  addiu      $v0, $sp, 0x20
    /* 5F4 800F9DF4 1000A8AF */  sw         $t0, 0x10($sp)
    /* 5F8 800F9DF8 1400AAAF */  sw         $t2, 0x14($sp)
    /* 5FC 800F9DFC 1800A2AF */  sw         $v0, 0x18($sp)
    /* 600 800F9E00 3FDD010C */  jal        func_800774FC
    /* 604 800F9E04 1C00A0AF */   sw        $zero, 0x1C($sp)
    /* 608 800F9E08 21200000 */  addu       $a0, $zero, $zero
    /* 60C 800F9E0C 1080053C */  lui        $a1, %hi(D_800FAB18)
    /* 610 800F9E10 18ABA524 */  addiu      $a1, $a1, %lo(D_800FAB18)
    /* 614 800F9E14 10000624 */  addiu      $a2, $zero, 0x10
    /* 618 800F9E18 21388000 */  addu       $a3, $a0, $zero
    /* 61C 800F9E1C 0F80103C */  lui        $s0, %hi(vs_battle_characterState)
    /* 620 800F9E20 FC1902AE */  sw         $v0, %lo(vs_battle_characterState)($s0)
    /* 624 800F9E24 80000224 */  addiu      $v0, $zero, 0x80
    /* 628 800F9E28 1000A2AF */  sw         $v0, 0x10($sp)
    /* 62C 800F9E2C C9DB010C */  jal        func_80076F24
    /* 630 800F9E30 1400A0AF */   sw        $zero, 0x14($sp)
    /* 634 800F9E34 07004012 */  beqz       $s2, .L800F9E54
    /* 638 800F9E38 40191200 */   sll       $v1, $s2, 5
    /* 63C 800F9E3C 0680053C */  lui        $a1, %hi(D_80060148)
    /* 640 800F9E40 FC19028E */  lw         $v0, %lo(vs_battle_characterState)($s0)
    /* 644 800F9E44 4801A524 */  addiu      $a1, $a1, %lo(D_80060148)
    /* 648 800F9E48 3C00448C */  lw         $a0, 0x3C($v0)
    /* 64C 800F9E4C 99E70308 */  j          .L800F9E64
    /* 650 800F9E50 21286500 */   addu      $a1, $v1, $a1
  .L800F9E54:
    /* 654 800F9E54 FC19028E */  lw         $v0, %lo(vs_battle_characterState)($s0)
    /* 658 800F9E58 00000000 */  nop
    /* 65C 800F9E5C 3C00448C */  lw         $a0, 0x3C($v0)
    /* 660 800F9E60 21280000 */  addu       $a1, $zero, $zero
  .L800F9E64:
    /* 664 800F9E64 ABAB010C */  jal        vs_battle_applyWeapon
    /* 668 800F9E68 3C008424 */   addiu     $a0, $a0, 0x3C
    /* 66C 800F9E6C 0F80053C */  lui        $a1, %hi(vs_battle_characterState)
    /* 670 800F9E70 FC19A28C */  lw         $v0, %lo(vs_battle_characterState)($a1)
    /* 674 800F9E74 00000000 */  nop
    /* 678 800F9E78 3C00448C */  lw         $a0, 0x3C($v0)
    /* 67C 800F9E7C 00000000 */  nop
    /* 680 800F9E80 3400828C */  lw         $v0, 0x34($a0)
    /* 684 800F9E84 60018390 */  lbu        $v1, 0x160($a0)
    /* 688 800F9E88 C2160200 */  srl        $v0, $v0, 27
    /* 68C 800F9E8C 21186200 */  addu       $v1, $v1, $v0
    /* 690 800F9E90 380083A0 */  sb         $v1, 0x38($a0)
    /* 694 800F9E94 FC19A28C */  lw         $v0, %lo(vs_battle_characterState)($a1)
    /* 698 800F9E98 00000000 */  nop
    /* 69C 800F9E9C 3C00448C */  lw         $a0, 0x3C($v0)
    /* 6A0 800F9EA0 00000000 */  nop
    /* 6A4 800F9EA4 3400828C */  lw         $v0, 0x34($a0)
    /* 6A8 800F9EA8 61018390 */  lbu        $v1, 0x161($a0)
    /* 6AC 800F9EAC C2160200 */  srl        $v0, $v0, 27
    /* 6B0 800F9EB0 21186200 */  addu       $v1, $v1, $v0
    /* 6B4 800F9EB4 390083A0 */  sb         $v1, 0x39($a0)
    /* 6B8 800F9EB8 FC19A28C */  lw         $v0, %lo(vs_battle_characterState)($a1)
    /* 6BC 800F9EBC 00000000 */  nop
    /* 6C0 800F9EC0 3C00448C */  lw         $a0, 0x3C($v0)
    /* 6C4 800F9EC4 00000000 */  nop
    /* 6C8 800F9EC8 3400828C */  lw         $v0, 0x34($a0)
    /* 6CC 800F9ECC 62018390 */  lbu        $v1, 0x162($a0)
    /* 6D0 800F9ED0 C2160200 */  srl        $v0, $v0, 27
    /* 6D4 800F9ED4 21186200 */  addu       $v1, $v1, $v0
    /* 6D8 800F9ED8 3A0083A0 */  sb         $v1, 0x3A($a0)
    /* 6DC 800F9EDC FC19A68C */  lw         $a2, %lo(vs_battle_characterState)($a1)
    /* 6E0 800F9EE0 FF07053C */  lui        $a1, (0x7FFFFFF >> 16)
    /* 6E4 800F9EE4 3C00C48C */  lw         $a0, 0x3C($a2)
    /* 6E8 800F9EE8 FFFFA534 */  ori        $a1, $a1, (0x7FFFFFF & 0xFFFF)
    /* 6EC 800F9EEC 3800838C */  lw         $v1, 0x38($a0)
    /* 6F0 800F9EF0 6001828C */  lw         $v0, 0x160($a0)
    /* 6F4 800F9EF4 24186500 */  and        $v1, $v1, $a1
    /* 6F8 800F9EF8 C2160200 */  srl        $v0, $v0, 27
    /* 6FC 800F9EFC C0160200 */  sll        $v0, $v0, 27
    /* 700 800F9F00 25186200 */  or         $v1, $v1, $v0
    /* 704 800F9F04 380083AC */  sw         $v1, 0x38($a0)
    /* 708 800F9F08 3C00C48C */  lw         $a0, 0x3C($a2)
    /* 70C 800F9F0C FFF8033C */  lui        $v1, (0xF8FFFFFF >> 16)
    /* 710 800F9F10 3800828C */  lw         $v0, 0x38($a0)
    /* 714 800F9F14 FFFF6334 */  ori        $v1, $v1, (0xF8FFFFFF & 0xFFFF)
    /* 718 800F9F18 24104300 */  and        $v0, $v0, $v1
    /* 71C 800F9F1C 0001033C */  lui        $v1, (0x1000000 >> 16)
    /* 720 800F9F20 25104300 */  or         $v0, $v0, $v1
    /* 724 800F9F24 09006012 */  beqz       $s3, .L800F9F4C
    /* 728 800F9F28 380082AC */   sw        $v0, 0x38($a0)
    /* 72C 800F9F2C 3C00C48C */  lw         $a0, 0x3C($a2)
    /* 730 800F9F30 40101300 */  sll        $v0, $s3, 1
    /* 734 800F9F34 21105300 */  addu       $v0, $v0, $s3
    /* 738 800F9F38 00110200 */  sll        $v0, $v0, 4
    /* 73C 800F9F3C 0680053C */  lui        $a1, %hi(D_80060238)
    /* 740 800F9F40 3802A524 */  addiu      $a1, $a1, %lo(D_80060238)
    /* 744 800F9F44 D5E70308 */  j          .L800F9F54
    /* 748 800F9F48 21284500 */   addu      $a1, $v0, $a1
  .L800F9F4C:
    /* 74C 800F9F4C 3C00C48C */  lw         $a0, 0x3C($a2)
    /* 750 800F9F50 21280000 */  addu       $a1, $zero, $zero
  .L800F9F54:
    /* 754 800F9F54 0BAC010C */  jal        vs_battle_applyShield
    /* 758 800F9F58 D4018424 */   addiu     $a0, $a0, 0x1D4
    /* 75C 800F9F5C 21880000 */  addu       $s1, $zero, $zero
    /* 760 800F9F60 0F80173C */  lui        $s7, %hi(vs_battle_characterState)
    /* 764 800F9F64 0680023C */  lui        $v0, %hi(vs_battle_inventory)
    /* 768 800F9F68 68015E24 */  addiu      $fp, $v0, %lo(vs_battle_inventory)
    /* 76C 800F9F6C 98031524 */  addiu      $s5, $zero, 0x398
  .L800F9F70:
    /* 770 800F9F70 21280000 */  addu       $a1, $zero, $zero
    /* 774 800F9F74 21A0A000 */  addu       $s4, $a1, $zero
    /* 778 800F9F78 21B0A002 */  addu       $s6, $s5, $zero
    /* 77C 800F9F7C FC19E28E */  lw         $v0, %lo(vs_battle_characterState)($s7)
    /* 780 800F9F80 0680123C */  lui        $s2, %hi(D_800607A8)
    /* 784 800F9F84 A8075226 */  addiu      $s2, $s2, %lo(D_800607A8)
    /* 788 800F9F88 3C00448C */  lw         $a0, 0x3C($v0)
    /* 78C 800F9F8C 2180C003 */  addu       $s0, $fp, $zero
    /* 790 800F9F90 21209500 */  addu       $a0, $a0, $s5
    /* 794 800F9F94 44AC010C */  jal        vs_battle_applyArmor
    /* 798 800F9F98 20008424 */   addiu     $a0, $a0, 0x20
  .L800F9F9C:
    /* 79C 800F9F9C 66060292 */  lbu        $v0, 0x666($s0)
    /* 7A0 800F9FA0 01003326 */  addiu      $s3, $s1, 0x1
    /* 7A4 800F9FA4 08005314 */  bne        $v0, $s3, .L800F9FC8
    /* 7A8 800F9FA8 21284002 */   addu      $a1, $s2, $zero
    /* 7AC 800F9FAC FC19E28E */  lw         $v0, %lo(vs_battle_characterState)($s7)
    /* 7B0 800F9FB0 00000000 */  nop
    /* 7B4 800F9FB4 3C00448C */  lw         $a0, 0x3C($v0)
    /* 7B8 800F9FB8 00000000 */  nop
    /* 7BC 800F9FBC 21209600 */  addu       $a0, $a0, $s6
    /* 7C0 800F9FC0 44AC010C */  jal        vs_battle_applyArmor
    /* 7C4 800F9FC4 20008424 */   addiu     $a0, $a0, 0x20
  .L800F9FC8:
    /* 7C8 800F9FC8 28005226 */  addiu      $s2, $s2, 0x28
    /* 7CC 800F9FCC 01009426 */  addiu      $s4, $s4, 0x1
    /* 7D0 800F9FD0 1000822A */  slti       $v0, $s4, 0x10
    /* 7D4 800F9FD4 F1FF4014 */  bnez       $v0, .L800F9F9C
    /* 7D8 800F9FD8 28001026 */   addiu     $s0, $s0, 0x28
    /* 7DC 800F9FDC 21886002 */  addu       $s1, $s3, $zero
    /* 7E0 800F9FE0 0600222A */  slti       $v0, $s1, 0x6
    /* 7E4 800F9FE4 E2FF4014 */  bnez       $v0, .L800F9F70
    /* 7E8 800F9FE8 DC00B526 */   addiu     $s5, $s5, 0xDC
    /* 7EC 800F9FEC 21280000 */  addu       $a1, $zero, $zero
    /* 7F0 800F9FF0 0F80023C */  lui        $v0, %hi(vs_battle_characterState)
    /* 7F4 800F9FF4 FC19428C */  lw         $v0, %lo(vs_battle_characterState)($v0)
    /* 7F8 800F9FF8 2188A000 */  addu       $s1, $a1, $zero
    /* 7FC 800F9FFC 3C00448C */  lw         $a0, 0x3C($v0)
    /* 800 800FA000 07001324 */  addiu      $s3, $zero, 0x7
    /* 804 800FA004 65AC010C */  jal        vs_battle_applyAccessory
    /* 808 800FA008 38038424 */   addiu     $a0, $a0, 0x338
    /* 80C 800FA00C 0680023C */  lui        $v0, %hi(vs_battle_inventory)
    /* 810 800FA010 68014224 */  addiu      $v0, $v0, %lo(vs_battle_inventory)
    /* 814 800FA014 40065224 */  addiu      $s2, $v0, 0x640
    /* 818 800FA018 21804000 */  addu       $s0, $v0, $zero
  .L800FA01C:
    /* 81C 800FA01C 66060292 */  lbu        $v0, 0x666($s0)
    /* 820 800FA020 00000000 */  nop
    /* 824 800FA024 07005314 */  bne        $v0, $s3, .L800FA044
    /* 828 800FA028 0F80023C */   lui       $v0, %hi(vs_battle_characterState)
    /* 82C 800FA02C FC19428C */  lw         $v0, %lo(vs_battle_characterState)($v0)
    /* 830 800FA030 00000000 */  nop
    /* 834 800FA034 3C00448C */  lw         $a0, 0x3C($v0)
    /* 838 800FA038 21284002 */  addu       $a1, $s2, $zero
    /* 83C 800FA03C 65AC010C */  jal        vs_battle_applyAccessory
    /* 840 800FA040 38038424 */   addiu     $a0, $a0, 0x338
  .L800FA044:
    /* 844 800FA044 28005226 */  addiu      $s2, $s2, 0x28
    /* 848 800FA048 01003126 */  addiu      $s1, $s1, 0x1
    /* 84C 800FA04C 1000222A */  slti       $v0, $s1, 0x10
    /* 850 800FA050 F2FF4014 */  bnez       $v0, .L800FA01C
    /* 854 800FA054 28001026 */   addiu     $s0, $s0, 0x28
    /* 858 800FA058 0F80023C */  lui        $v0, %hi(vs_battle_characterState)
    /* 85C 800FA05C FC19428C */  lw         $v0, %lo(vs_battle_characterState)($v0)
    /* 860 800FA060 00000000 */  nop
    /* 864 800FA064 3C00448C */  lw         $a0, 0x3C($v0)
    /* 868 800FA068 83AC010C */  jal        vs_battle_nop0
    /* 86C 800FA06C 00000000 */   nop
    /* 870 800FA070 0680023C */  lui        $v0, %hi(D_80060068)
    /* 874 800FA074 6800428C */  lw         $v0, %lo(D_80060068)($v0)
    /* 878 800FA078 00000000 */  nop
    /* 87C 800FA07C 03004010 */  beqz       $v0, .L800FA08C
    /* 880 800FA080 00000000 */   nop
    /* 884 800FA084 B6E6030C */  jal        func_800F9AD8
    /* 888 800FA088 00000000 */   nop
  .L800FA08C:
    /* 88C 800FA08C ACE6030C */  jal        func_800F9AB0
    /* 890 800FA090 00000000 */   nop
  .L800FA094:
    /* 894 800FA094 AEE6030C */  jal        func_800F9AB8
    /* 898 800FA098 00000000 */   nop
    /* 89C 800FA09C 07004010 */  beqz       $v0, .L800FA0BC
    /* 8A0 800FA0A0 00000000 */   nop
    /* 8A4 800FA0A4 9F65020C */  jal        vs_battle_processObjectDataQueue
    /* 8A8 800FA0A8 00000000 */   nop
    /* 8AC 800FA0AC 8709010C */  jal        vs_main_gametimeUpdate
    /* 8B0 800FA0B0 21200000 */   addu      $a0, $zero, $zero
    /* 8B4 800FA0B4 25E80308 */  j          .L800FA094
    /* 8B8 800FA0B8 00000000 */   nop
  .L800FA0BC:
    /* 8BC 800FA0BC 4C00BF8F */  lw         $ra, 0x4C($sp)
    /* 8C0 800FA0C0 4800BE8F */  lw         $fp, 0x48($sp)
    /* 8C4 800FA0C4 4400B78F */  lw         $s7, 0x44($sp)
    /* 8C8 800FA0C8 4000B68F */  lw         $s6, 0x40($sp)
    /* 8CC 800FA0CC 3C00B58F */  lw         $s5, 0x3C($sp)
    /* 8D0 800FA0D0 3800B48F */  lw         $s4, 0x38($sp)
    /* 8D4 800FA0D4 3400B38F */  lw         $s3, 0x34($sp)
    /* 8D8 800FA0D8 3000B28F */  lw         $s2, 0x30($sp)
    /* 8DC 800FA0DC 2C00B18F */  lw         $s1, 0x2C($sp)
    /* 8E0 800FA0E0 2800B08F */  lw         $s0, 0x28($sp)
    /* 8E4 800FA0E4 0800E003 */  jr         $ra
    /* 8E8 800FA0E8 5000BD27 */   addiu     $sp, $sp, 0x50
endlabel func_800F9CCC
