nonmatching _getWeaponGemCount, 0x60

glabel _getWeaponGemCount
    /* 3E24 80106624 1180023C */  lui        $v0, %hi(vs_menuD_containerData)
    /* 3E28 80106628 8C9A438C */  lw         $v1, %lo(vs_menuD_containerData)($v0)
    /* 3E2C 8010662C 40210400 */  sll        $a0, $a0, 5
    /* 3E30 80106630 21286400 */  addu       $a1, $v1, $a0
    /* 3E34 80106634 0200A290 */  lbu        $v0, 0x2($a1)
    /* 3E38 80106638 21200000 */  addu       $a0, $zero, $zero
    /* 3E3C 8010663C FFFF4224 */  addiu      $v0, $v0, -0x1
    /* 3E40 80106640 00110200 */  sll        $v0, $v0, 4
    /* 3E44 80106644 21186200 */  addu       $v1, $v1, $v0
    /* 3E48 80106648 04156290 */  lbu        $v0, 0x1504($v1)
    /* 3E4C 8010664C 00000000 */  nop
    /* 3E50 80106650 0A004010 */  beqz       $v0, .L8010667C
    /* 3E54 80106654 21188000 */   addu      $v1, $a0, $zero
    /* 3E58 80106658 21304000 */  addu       $a2, $v0, $zero
    /* 3E5C 8010665C 2110A400 */  addu       $v0, $a1, $a0
  .L80106660:
    /* 3E60 80106660 04004290 */  lbu        $v0, 0x4($v0)
    /* 3E64 80106664 01008424 */  addiu      $a0, $a0, 0x1
    /* 3E68 80106668 2B100200 */  sltu       $v0, $zero, $v0
    /* 3E6C 8010666C 21186200 */  addu       $v1, $v1, $v0
    /* 3E70 80106670 2A108600 */  slt        $v0, $a0, $a2
    /* 3E74 80106674 FAFF4014 */  bnez       $v0, .L80106660
    /* 3E78 80106678 2110A400 */   addu      $v0, $a1, $a0
  .L8010667C:
    /* 3E7C 8010667C 0800E003 */  jr         $ra
    /* 3E80 80106680 21106000 */   addu      $v0, $v1, $zero
endlabel _getWeaponGemCount
