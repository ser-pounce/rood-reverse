nonmatching func_80107EBC, 0x58

glabel func_80107EBC
    /* 56BC 80107EBC 0300A290 */  lbu        $v0, 0x3($a1)
    /* 56C0 80107EC0 00000000 */  nop
    /* 56C4 80107EC4 090082A0 */  sb         $v0, 0x9($a0)
    /* 56C8 80107EC8 2800A290 */  lbu        $v0, 0x28($a1)
    /* 56CC 80107ECC 00000000 */  nop
    /* 56D0 80107ED0 0C0082A0 */  sb         $v0, 0xC($a0)
    /* 56D4 80107ED4 2A00A390 */  lbu        $v1, 0x2A($a1)
    /* 56D8 80107ED8 00000000 */  nop
    /* 56DC 80107EDC 0B006010 */  beqz       $v1, .L80107F0C
    /* 56E0 80107EE0 0680023C */   lui       $v0, %hi(vs_battle_inventory)
    /* 56E4 80107EE4 68014224 */  addiu      $v0, $v0, %lo(vs_battle_inventory)
    /* 56E8 80107EE8 FFFF6324 */  addiu      $v1, $v1, -0x1
    /* 56EC 80107EEC 40190300 */  sll        $v1, $v1, 5
    /* 56F0 80107EF0 21186200 */  addu       $v1, $v1, $v0
    /* 56F4 80107EF4 03006290 */  lbu        $v0, 0x3($v1)
    /* 56F8 80107EF8 00000000 */  nop
    /* 56FC 80107EFC 02004014 */  bnez       $v0, .L80107F08
    /* 5700 80107F00 01000324 */   addiu     $v1, $zero, 0x1
    /* 5704 80107F04 02000324 */  addiu      $v1, $zero, 0x2
  .L80107F08:
    /* 5708 80107F08 0D0083A0 */  sb         $v1, 0xD($a0)
  .L80107F0C:
    /* 570C 80107F0C 0800E003 */  jr         $ra
    /* 5710 80107F10 00000000 */   nop
endlabel func_80107EBC
