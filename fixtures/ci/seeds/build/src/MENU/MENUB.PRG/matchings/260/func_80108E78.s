nonmatching func_80108E78, 0x22C

glabel func_80108E78
    /* 6678 80108E78 C8FFBD27 */  addiu      $sp, $sp, -0x38
    /* 667C 80108E7C 2000B0AF */  sw         $s0, 0x20($sp)
    /* 6680 80108E80 0680103C */  lui        $s0, %hi(vs_battle_inventory)
    /* 6684 80108E84 68011026 */  addiu      $s0, $s0, %lo(vs_battle_inventory)
    /* 6688 80108E88 21280002 */  addu       $a1, $s0, $zero
    /* 668C 80108E8C 2800B2AF */  sw         $s2, 0x28($sp)
    /* 6690 80108E90 1180123C */  lui        $s2, %hi(D_8010A6A0)
    /* 6694 80108E94 2400B1AF */  sw         $s1, 0x24($sp)
    /* 6698 80108E98 80880400 */  sll        $s1, $a0, 2
    /* 669C 80108E9C 1180033C */  lui        $v1, %hi(D_8010A6AC)
    /* 66A0 80108EA0 A0A6428E */  lw         $v0, %lo(D_8010A6A0)($s2)
    /* 66A4 80108EA4 ACA6648C */  lw         $a0, %lo(D_8010A6AC)($v1)
    /* 66A8 80108EA8 3000BFAF */  sw         $ra, 0x30($sp)
    /* 66AC 80108EAC 2C00B3AF */  sw         $s3, 0x2C($sp)
    /* 66B0 80108EB0 21102202 */  addu       $v0, $s1, $v0
    /* 66B4 80108EB4 01005390 */  lbu        $s3, 0x1($v0)
    /* 66B8 80108EB8 7800030C */  jal        vs_battle_memcpy
    /* 66BC 80108EBC 000F0624 */   addiu     $a2, $zero, 0xF00
    /* 66C0 80108EC0 21200002 */  addu       $a0, $s0, $zero
    /* 66C4 80108EC4 1180023C */  lui        $v0, %hi(_inventory)
    /* 66C8 80108EC8 A8A6458C */  lw         $a1, %lo(_inventory)($v0)
    /* 66CC 80108ECC 7800030C */  jal        vs_battle_memcpy
    /* 66D0 80108ED0 000F0624 */   addiu     $a2, $zero, 0xF00
    /* 66D4 80108ED4 A0A6428E */  lw         $v0, %lo(D_8010A6A0)($s2)
    /* 66D8 80108ED8 00000000 */  nop
    /* 66DC 80108EDC 21882202 */  addu       $s1, $s1, $v0
    /* 66E0 80108EE0 00002392 */  lbu        $v1, 0x0($s1)
    /* 66E4 80108EE4 00000000 */  nop
    /* 66E8 80108EE8 0700622C */  sltiu      $v0, $v1, 0x7
    /* 66EC 80108EEC 5D004010 */  beqz       $v0, .L80109064
    /* 66F0 80108EF0 1080023C */   lui       $v0, %hi(jtbl_801029E0)
    /* 66F4 80108EF4 E0294224 */  addiu      $v0, $v0, %lo(jtbl_801029E0)
    /* 66F8 80108EF8 80180300 */  sll        $v1, $v1, 2
    /* 66FC 80108EFC 21186200 */  addu       $v1, $v1, $v0
    /* 6700 80108F00 0000628C */  lw         $v0, 0x0($v1)
    /* 6704 80108F04 00000000 */  nop
    /* 6708 80108F08 08004000 */  jr         $v0
    /* 670C 80108F0C 00000000 */   nop
    /* 6710 80108F10 40111300 */  sll        $v0, $s3, 5
    /* 6714 80108F14 0680043C */  lui        $a0, %hi(vs_battle_inventory)
    /* 6718 80108F18 68018424 */  addiu      $a0, $a0, %lo(vs_battle_inventory)
    /* 671C 80108F1C 21204400 */  addu       $a0, $v0, $a0
    /* 6720 80108F20 1000A527 */  addiu      $a1, $sp, 0x10
    /* 6724 80108F24 0F80023C */  lui        $v0, %hi(vs_battle_stringBuf)
    /* 6728 80108F28 8C4E478C */  lw         $a3, %lo(vs_battle_stringBuf)($v0)
    /* 672C 80108F2C 82F2030C */  jal        vs_mainMenu_initUiWeapon
    /* 6730 80108F30 1800A627 */   addiu     $a2, $sp, 0x18
    /* 6734 80108F34 19240408 */  j          .L80109064
    /* 6738 80108F38 00000000 */   nop
    /* 673C 80108F3C 40201300 */  sll        $a0, $s3, 1
    /* 6740 80108F40 21209300 */  addu       $a0, $a0, $s3
    /* 6744 80108F44 80200400 */  sll        $a0, $a0, 2
    /* 6748 80108F48 23209300 */  subu       $a0, $a0, $s3
    /* 674C 80108F4C 80200400 */  sll        $a0, $a0, 2
    /* 6750 80108F50 0680023C */  lui        $v0, %hi(D_800603E8)
    /* 6754 80108F54 E8034224 */  addiu      $v0, $v0, %lo(D_800603E8)
    /* 6758 80108F58 21208200 */  addu       $a0, $a0, $v0
    /* 675C 80108F5C 1000A527 */  addiu      $a1, $sp, 0x10
    /* 6760 80108F60 0F80023C */  lui        $v0, %hi(vs_battle_stringBuf)
    /* 6764 80108F64 8C4E478C */  lw         $a3, %lo(vs_battle_stringBuf)($v0)
    /* 6768 80108F68 A9F2030C */  jal        vs_mainMenu_setUiBlade
    /* 676C 80108F6C 1800A627 */   addiu     $a2, $sp, 0x18
    /* 6770 80108F70 19240408 */  j          .L80109064
    /* 6774 80108F74 00000000 */   nop
    /* 6778 80108F78 00111300 */  sll        $v0, $s3, 4
    /* 677C 80108F7C 0680043C */  lui        $a0, %hi(D_800606A8)
    /* 6780 80108F80 A8068424 */  addiu      $a0, $a0, %lo(D_800606A8)
    /* 6784 80108F84 21204400 */  addu       $a0, $v0, $a0
    /* 6788 80108F88 1000A527 */  addiu      $a1, $sp, 0x10
    /* 678C 80108F8C 0F80023C */  lui        $v0, %hi(vs_battle_stringBuf)
    /* 6790 80108F90 8C4E478C */  lw         $a3, %lo(vs_battle_stringBuf)($v0)
    /* 6794 80108F94 03F3030C */  jal        vs_mainMenu_setUiGrip
    /* 6798 80108F98 1800A627 */   addiu     $a2, $sp, 0x18
    /* 679C 80108F9C 19240408 */  j          .L80109064
    /* 67A0 80108FA0 00000000 */   nop
    /* 67A4 80108FA4 40101300 */  sll        $v0, $s3, 1
    /* 67A8 80108FA8 21105300 */  addu       $v0, $v0, $s3
    /* 67AC 80108FAC 00110200 */  sll        $v0, $v0, 4
    /* 67B0 80108FB0 0680043C */  lui        $a0, %hi(D_80060268)
    /* 67B4 80108FB4 68028424 */  addiu      $a0, $a0, %lo(D_80060268)
    /* 67B8 80108FB8 21204400 */  addu       $a0, $v0, $a0
    /* 67BC 80108FBC 1000A527 */  addiu      $a1, $sp, 0x10
    /* 67C0 80108FC0 0F80023C */  lui        $v0, %hi(vs_battle_stringBuf)
    /* 67C4 80108FC4 8C4E478C */  lw         $a3, %lo(vs_battle_stringBuf)($v0)
    /* 67C8 80108FC8 90F3030C */  jal        vs_mainMenu_initUiShield
    /* 67CC 80108FCC 1800A627 */   addiu     $a2, $sp, 0x18
    /* 67D0 80108FD0 19240408 */  j          .L80109064
    /* 67D4 80108FD4 00000000 */   nop
    /* 67D8 80108FD8 80101300 */  sll        $v0, $s3, 2
    /* 67DC 80108FDC 21105300 */  addu       $v0, $v0, $s3
    /* 67E0 80108FE0 C0100200 */  sll        $v0, $v0, 3
    /* 67E4 80108FE4 0680043C */  lui        $a0, %hi(D_800607A8)
    /* 67E8 80108FE8 A8078424 */  addiu      $a0, $a0, %lo(D_800607A8)
    /* 67EC 80108FEC 21204400 */  addu       $a0, $v0, $a0
    /* 67F0 80108FF0 1000A527 */  addiu      $a1, $sp, 0x10
    /* 67F4 80108FF4 0F80023C */  lui        $v0, %hi(vs_battle_stringBuf)
    /* 67F8 80108FF8 8C4E478C */  lw         $a3, %lo(vs_battle_stringBuf)($v0)
    /* 67FC 80108FFC 21F4030C */  jal        vs_mainMenu_initUiArmor
    /* 6800 80109000 1800A627 */   addiu     $a2, $sp, 0x18
    /* 6804 80109004 19240408 */  j          .L80109064
    /* 6808 80109008 00000000 */   nop
    /* 680C 8010900C C0101300 */  sll        $v0, $s3, 3
    /* 6810 80109010 23105300 */  subu       $v0, $v0, $s3
    /* 6814 80109014 80100200 */  sll        $v0, $v0, 2
    /* 6818 80109018 0680043C */  lui        $a0, %hi(D_80060A28)
    /* 681C 8010901C 280A8424 */  addiu      $a0, $a0, %lo(D_80060A28)
    /* 6820 80109020 21204400 */  addu       $a0, $v0, $a0
    /* 6824 80109024 1000A527 */  addiu      $a1, $sp, 0x10
    /* 6828 80109028 0F80023C */  lui        $v0, %hi(vs_battle_stringBuf)
    /* 682C 8010902C 8C4E478C */  lw         $a3, %lo(vs_battle_stringBuf)($v0)
    /* 6830 80109030 38F4030C */  jal        vs_mainMenu_setUiGem
    /* 6834 80109034 1800A627 */   addiu     $a2, $sp, 0x18
    /* 6838 80109038 19240408 */  j          .L80109064
    /* 683C 8010903C 00000000 */   nop
    /* 6840 80109040 80101300 */  sll        $v0, $s3, 2
    /* 6844 80109044 0680043C */  lui        $a0, %hi(D_80060F68)
    /* 6848 80109048 680F8424 */  addiu      $a0, $a0, %lo(D_80060F68)
    /* 684C 8010904C 21204400 */  addu       $a0, $v0, $a0
    /* 6850 80109050 1000A527 */  addiu      $a1, $sp, 0x10
    /* 6854 80109054 0F80023C */  lui        $v0, %hi(vs_battle_stringBuf)
    /* 6858 80109058 8C4E478C */  lw         $a3, %lo(vs_battle_stringBuf)($v0)
    /* 685C 8010905C 5FF4030C */  jal        vs_mainMenu_setUiItem
    /* 6860 80109060 1800A627 */   addiu     $a2, $sp, 0x18
  .L80109064:
    /* 6864 80109064 1400A48F */  lw         $a0, 0x14($sp)
    /* 6868 80109068 01FF030C */  jal        vs_mainmenu_setInformationMessage
    /* 686C 8010906C 00000000 */   nop
    /* 6870 80109070 0680043C */  lui        $a0, %hi(vs_battle_inventory)
    /* 6874 80109074 68018424 */  addiu      $a0, $a0, %lo(vs_battle_inventory)
    /* 6878 80109078 1180023C */  lui        $v0, %hi(D_8010A6AC)
    /* 687C 8010907C ACA6458C */  lw         $a1, %lo(D_8010A6AC)($v0)
    /* 6880 80109080 7800030C */  jal        vs_battle_memcpy
    /* 6884 80109084 000F0624 */   addiu     $a2, $zero, 0xF00
    /* 6888 80109088 3000BF8F */  lw         $ra, 0x30($sp)
    /* 688C 8010908C 2C00B38F */  lw         $s3, 0x2C($sp)
    /* 6890 80109090 2800B28F */  lw         $s2, 0x28($sp)
    /* 6894 80109094 2400B18F */  lw         $s1, 0x24($sp)
    /* 6898 80109098 2000B08F */  lw         $s0, 0x20($sp)
    /* 689C 8010909C 0800E003 */  jr         $ra
    /* 68A0 801090A0 3800BD27 */   addiu     $sp, $sp, 0x38
endlabel func_80108E78
