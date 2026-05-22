nonmatching _initCubePuzzleQuit, 0x228

glabel _initCubePuzzleQuit
    /* 5598 80107D98 C0FFBD27 */  addiu      $sp, $sp, -0x40
    /* 559C 80107D9C 2C00B1AF */  sw         $s1, 0x2C($sp)
    /* 55A0 80107DA0 0F80113C */  lui        $s1, %hi(_submenuState)
    /* 55A4 80107DA4 D81C238E */  lw         $v1, %lo(_submenuState)($s1)
    /* 55A8 80107DA8 3800BFAF */  sw         $ra, 0x38($sp)
    /* 55AC 80107DAC 3400B3AF */  sw         $s3, 0x34($sp)
    /* 55B0 80107DB0 3000B2AF */  sw         $s2, 0x30($sp)
    /* 55B4 80107DB4 18006014 */  bnez       $v1, .L80107E18
    /* 55B8 80107DB8 2800B0AF */   sw        $s0, 0x28($sp)
    /* 55BC 80107DBC 1D000424 */  addiu      $a0, $zero, 0x1D
    /* 55C0 80107DC0 01000524 */  addiu      $a1, $zero, 0x1
    /* 55C4 80107DC4 FCF7010C */  jal        func_8007DFF0
    /* 55C8 80107DC8 05000624 */   addiu     $a2, $zero, 0x5
    /* 55CC 80107DCC 1080103C */  lui        $s0, %hi(_disFiles)
    /* 55D0 80107DD0 E02A1026 */  addiu      $s0, $s0, %lo(_disFiles)
    /* 55D4 80107DD4 2400048E */  lw         $a0, 0x24($s0)
    /* 55D8 80107DD8 8F0F010C */  jal        vs_main_allocHeapR
    /* 55DC 80107DDC 00000000 */   nop
    /* 55E0 80107DE0 20000426 */  addiu      $a0, $s0, 0x20
    /* 55E4 80107DE4 1180103C */  lui        $s0, %hi(_escDisData)
    /* 55E8 80107DE8 C412010C */  jal        vs_main_allocateCdQueueSlot
    /* 55EC 80107DEC 749802AE */   sw        $v0, %lo(_escDisData)($s0)
    /* 55F0 80107DF0 21204000 */  addu       $a0, $v0, $zero
    /* 55F4 80107DF4 7498058E */  lw         $a1, %lo(_escDisData)($s0)
    /* 55F8 80107DF8 1180023C */  lui        $v0, %hi(_escDisCdSLot)
    /* 55FC 80107DFC F112010C */  jal        vs_main_cdEnqueue
    /* 5600 80107E00 709844AC */   sw        $a0, %lo(_escDisCdSLot)($v0)
    /* 5604 80107E04 D81C228E */  lw         $v0, %lo(_submenuState)($s1)
    /* 5608 80107E08 00000000 */  nop
    /* 560C 80107E0C 01004224 */  addiu      $v0, $v0, 0x1
    /* 5610 80107E10 E81F0408 */  j          .L80107FA0
    /* 5614 80107E14 D81C22AE */   sw        $v0, %lo(_submenuState)($s1)
  .L80107E18:
    /* 5618 80107E18 01000224 */  addiu      $v0, $zero, 0x1
    /* 561C 80107E1C 4E006214 */  bne        $v1, $v0, .L80107F58
    /* 5620 80107E20 1180023C */   lui       $v0, %hi(_escDisData)
    /* 5624 80107E24 1180023C */  lui        $v0, %hi(_escDisCdSLot)
    /* 5628 80107E28 7098428C */  lw         $v0, %lo(_escDisCdSLot)($v0)
    /* 562C 80107E2C 00000000 */  nop
    /* 5630 80107E30 00004384 */  lh         $v1, 0x0($v0)
    /* 5634 80107E34 04000224 */  addiu      $v0, $zero, 0x4
    /* 5638 80107E38 5A006214 */  bne        $v1, $v0, .L80107FA4
    /* 563C 80107E3C 21100000 */   addu      $v0, $zero, $zero
    /* 5640 80107E40 21800000 */  addu       $s0, $zero, $zero
    /* 5644 80107E44 1180133C */  lui        $s3, %hi(_escDisData)
    /* 5648 80107E48 40031224 */  addiu      $s2, $zero, 0x340
    /* 564C 80107E4C 21880002 */  addu       $s1, $s0, $zero
  .L80107E50:
    /* 5650 80107E50 7498648E */  lw         $a0, %lo(_escDisData)($s3)
    /* 5654 80107E54 1000A527 */  addiu      $a1, $sp, 0x10
    /* 5658 80107E58 0836020C */  jal        vs_battle_setTimImage
    /* 565C 80107E5C 21209100 */   addu      $a0, $a0, $s1
    /* 5660 80107E60 2000A28F */  lw         $v0, 0x20($sp)
    /* 5664 80107E64 00000000 */  nop
    /* 5668 80107E68 0E004010 */  beqz       $v0, .L80107EA4
    /* 566C 80107E6C 00000000 */   nop
    /* 5670 80107E70 1C00A28F */  lw         $v0, 0x1C($sp)
    /* 5674 80107E74 00000000 */  nop
    /* 5678 80107E78 000052A4 */  sh         $s2, 0x0($v0)
    /* 567C 80107E7C 1C00A38F */  lw         $v1, 0x1C($sp)
    /* 5680 80107E80 00010224 */  addiu      $v0, $zero, 0x100
    /* 5684 80107E84 020062A4 */  sh         $v0, 0x2($v1)
    /* 5688 80107E88 1C00A38F */  lw         $v1, 0x1C($sp)
    /* 568C 80107E8C FF000224 */  addiu      $v0, $zero, 0xFF
    /* 5690 80107E90 060062A4 */  sh         $v0, 0x6($v1)
    /* 5694 80107E94 1C00A48F */  lw         $a0, 0x1C($sp)
    /* 5698 80107E98 2000A58F */  lw         $a1, 0x20($sp)
    /* 569C 80107E9C 3FA2000C */  jal        LoadImage
    /* 56A0 80107EA0 00000000 */   nop
  .L80107EA4:
    /* 56A4 80107EA4 1D000016 */  bnez       $s0, .L80107F1C
    /* 56A8 80107EA8 00000000 */   nop
    /* 56AC 80107EAC 1800A28F */  lw         $v0, 0x18($sp)
    /* 56B0 80107EB0 00000000 */  nop
    /* 56B4 80107EB4 19004010 */  beqz       $v0, .L80107F1C
    /* 56B8 80107EB8 00030224 */   addiu     $v0, $zero, 0x300
    /* 56BC 80107EBC 1400A38F */  lw         $v1, 0x14($sp)
    /* 56C0 80107EC0 00000000 */  nop
    /* 56C4 80107EC4 000062A4 */  sh         $v0, 0x0($v1)
    /* 56C8 80107EC8 1400A38F */  lw         $v1, 0x14($sp)
    /* 56CC 80107ECC FF010224 */  addiu      $v0, $zero, 0x1FF
    /* 56D0 80107ED0 020062A4 */  sh         $v0, 0x2($v1)
    /* 56D4 80107ED4 1400A38F */  lw         $v1, 0x14($sp)
    /* 56D8 80107ED8 A0000224 */  addiu      $v0, $zero, 0xA0
    /* 56DC 80107EDC 040062A4 */  sh         $v0, 0x4($v1)
    /* 56E0 80107EE0 1400A38F */  lw         $v1, 0x14($sp)
    /* 56E4 80107EE4 01000224 */  addiu      $v0, $zero, 0x1
    /* 56E8 80107EE8 060062A4 */  sh         $v0, 0x6($v1)
    /* 56EC 80107EEC 1800A28F */  lw         $v0, 0x18($sp)
    /* 56F0 80107EF0 00000000 */  nop
    /* 56F4 80107EF4 000040AC */  sw         $zero, 0x0($v0)
    /* 56F8 80107EF8 1400A48F */  lw         $a0, 0x14($sp)
    /* 56FC 80107EFC 1800A58F */  lw         $a1, 0x18($sp)
    /* 5700 80107F00 3FA2000C */  jal        LoadImage
    /* 5704 80107F04 00000000 */   nop
    /* 5708 80107F08 1180043C */  lui        $a0, %hi(D_801098AC)
    /* 570C 80107F0C AC988424 */  addiu      $a0, $a0, %lo(D_801098AC)
    /* 5710 80107F10 1800A58F */  lw         $a1, 0x18($sp)
    /* 5714 80107F14 2C24010C */  jal        vs_main_memcpy
    /* 5718 80107F18 40010624 */   addiu     $a2, $zero, 0x140
  .L80107F1C:
    /* 571C 80107F1C 40005226 */  addiu      $s2, $s2, 0x40
    /* 5720 80107F20 20820234 */  ori        $v0, $zero, 0x8220
    /* 5724 80107F24 01001026 */  addiu      $s0, $s0, 0x1
    /* 5728 80107F28 C9FF001A */  blez       $s0, .L80107E50
    /* 572C 80107F2C 21882202 */   addu      $s1, $s1, $v0
    /* 5730 80107F30 1180023C */  lui        $v0, %hi(_escDisCdSLot)
    /* 5734 80107F34 7098448C */  lw         $a0, %lo(_escDisCdSLot)($v0)
    /* 5738 80107F38 E012010C */  jal        vs_main_freeCdQueueSlot
    /* 573C 80107F3C 00000000 */   nop
    /* 5740 80107F40 0F80033C */  lui        $v1, %hi(_submenuState)
    /* 5744 80107F44 D81C628C */  lw         $v0, %lo(_submenuState)($v1)
    /* 5748 80107F48 00000000 */  nop
    /* 574C 80107F4C 01004224 */  addiu      $v0, $v0, 0x1
    /* 5750 80107F50 E81F0408 */  j          .L80107FA0
    /* 5754 80107F54 D81C62AC */   sw        $v0, %lo(_submenuState)($v1)
  .L80107F58:
    /* 5758 80107F58 7498448C */  lw         $a0, %lo(_escDisData)($v0)
    /* 575C 80107F5C 180F010C */  jal        vs_main_freeHeapR
    /* 5760 80107F60 00000000 */   nop
    /* 5764 80107F64 01000224 */  addiu      $v0, $zero, 0x1
    /* 5768 80107F68 1180033C */  lui        $v1, %hi(D_80109894)
    /* 576C 80107F6C 949860AC */  sw         $zero, %lo(D_80109894)($v1)
    /* 5770 80107F70 1180033C */  lui        $v1, %hi(D_80109898)
    /* 5774 80107F74 989860AC */  sw         $zero, %lo(D_80109898)($v1)
    /* 5778 80107F78 1180033C */  lui        $v1, %hi(D_8010989C)
    /* 577C 80107F7C 9C9860AC */  sw         $zero, %lo(D_8010989C)($v1)
    /* 5780 80107F80 1180033C */  lui        $v1, %hi(D_801098A0)
    /* 5784 80107F84 A09860AC */  sw         $zero, %lo(D_801098A0)($v1)
    /* 5788 80107F88 1180033C */  lui        $v1, %hi(D_8010988C)
    /* 578C 80107F8C 8C9860AC */  sw         $zero, %lo(D_8010988C)($v1)
    /* 5790 80107F90 1180033C */  lui        $v1, %hi(_buffReelSelection)
    /* 5794 80107F94 789860AC */  sw         $zero, %lo(_buffReelSelection)($v1)
    /* 5798 80107F98 E91F0408 */  j          .L80107FA4
    /* 579C 80107F9C D81C20AE */   sw        $zero, %lo(_submenuState)($s1)
  .L80107FA0:
    /* 57A0 80107FA0 21100000 */  addu       $v0, $zero, $zero
  .L80107FA4:
    /* 57A4 80107FA4 3800BF8F */  lw         $ra, 0x38($sp)
    /* 57A8 80107FA8 3400B38F */  lw         $s3, 0x34($sp)
    /* 57AC 80107FAC 3000B28F */  lw         $s2, 0x30($sp)
    /* 57B0 80107FB0 2C00B18F */  lw         $s1, 0x2C($sp)
    /* 57B4 80107FB4 2800B08F */  lw         $s0, 0x28($sp)
    /* 57B8 80107FB8 0800E003 */  jr         $ra
    /* 57BC 80107FBC 4000BD27 */   addiu     $sp, $sp, 0x40
endlabel _initCubePuzzleQuit
