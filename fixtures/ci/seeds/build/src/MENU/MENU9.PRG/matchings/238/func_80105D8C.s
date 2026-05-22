nonmatching func_80105D8C, 0x174

glabel func_80105D8C
    /* 358C 80105D8C 21280000 */  addu       $a1, $zero, $zero
    /* 3590 80105D90 1180023C */  lui        $v0, %hi(_monBinData)
    /* 3594 80105D94 70A4438C */  lw         $v1, %lo(_monBinData)($v0)
    /* 3598 80105D98 0680023C */  lui        $v0, %hi(vs_main_scoredata)
    /* 359C 80105D9C A0FE4924 */  addiu      $t1, $v0, %lo(vs_main_scoredata)
    /* 35A0 80105DA0 01000824 */  addiu      $t0, $zero, 0x1
    /* 35A4 80105DA4 0C006624 */  addiu      $a2, $v1, 0xC
  .L80105DA8:
    /* 35A8 80105DA8 F8FFC484 */  lh         $a0, -0x8($a2)
    /* 35AC 80105DAC FAFFC284 */  lh         $v0, -0x6($a2)
    /* 35B0 80105DB0 00000000 */  nop
    /* 35B4 80105DB4 21188200 */  addu       $v1, $a0, $v0
    /* 35B8 80105DB8 2A108300 */  slt        $v0, $a0, $v1
    /* 35BC 80105DBC 14004010 */  beqz       $v0, .L80105E10
    /* 35C0 80105DC0 0000C0A0 */   sb        $zero, 0x0($a2)
    /* 35C4 80105DC4 21386000 */  addu       $a3, $v1, $zero
  .L80105DC8:
    /* 35C8 80105DC8 02008104 */  bgez       $a0, .L80105DD4
    /* 35CC 80105DCC 21108000 */   addu      $v0, $a0, $zero
    /* 35D0 80105DD0 1F008224 */  addiu      $v0, $a0, 0x1F
  .L80105DD4:
    /* 35D4 80105DD4 43110200 */  sra        $v0, $v0, 5
    /* 35D8 80105DD8 80180200 */  sll        $v1, $v0, 2
    /* 35DC 80105DDC 21186900 */  addu       $v1, $v1, $t1
    /* 35E0 80105DE0 40110200 */  sll        $v0, $v0, 5
    /* 35E4 80105DE4 23108200 */  subu       $v0, $a0, $v0
    /* 35E8 80105DE8 9C00638C */  lw         $v1, 0x9C($v1)
    /* 35EC 80105DEC 04104800 */  sllv       $v0, $t0, $v0
    /* 35F0 80105DF0 24186200 */  and        $v1, $v1, $v0
    /* 35F4 80105DF4 03006010 */  beqz       $v1, .L80105E04
    /* 35F8 80105DF8 01008424 */   addiu     $a0, $a0, 0x1
    /* 35FC 80105DFC 84170408 */  j          .L80105E10
    /* 3600 80105E00 0000C8A0 */   sb        $t0, 0x0($a2)
  .L80105E04:
    /* 3604 80105E04 2A108700 */  slt        $v0, $a0, $a3
    /* 3608 80105E08 EFFF4014 */  bnez       $v0, .L80105DC8
    /* 360C 80105E0C 00000000 */   nop
  .L80105E10:
    /* 3610 80105E10 0100A524 */  addiu      $a1, $a1, 0x1
    /* 3614 80105E14 4E00A228 */  slti       $v0, $a1, 0x4E
    /* 3618 80105E18 E3FF4014 */  bnez       $v0, .L80105DA8
    /* 361C 80105E1C 2C00C624 */   addiu     $a2, $a2, 0x2C
    /* 3620 80105E20 21280000 */  addu       $a1, $zero, $zero
    /* 3624 80105E24 1180023C */  lui        $v0, %hi(_monBinData)
    /* 3628 80105E28 70A4438C */  lw         $v1, %lo(_monBinData)($v0)
    /* 362C 80105E2C FF000424 */  addiu      $a0, $zero, 0xFF
    /* 3630 80105E30 0D006324 */  addiu      $v1, $v1, 0xD
  .L80105E34:
    /* 3634 80105E34 FFFF6290 */  lbu        $v0, -0x1($v1)
    /* 3638 80105E38 00000000 */  nop
    /* 363C 80105E3C 03004010 */  beqz       $v0, .L80105E4C
    /* 3640 80105E40 00000000 */   nop
    /* 3644 80105E44 000064A0 */  sb         $a0, 0x0($v1)
    /* 3648 80105E48 2120A000 */  addu       $a0, $a1, $zero
  .L80105E4C:
    /* 364C 80105E4C 0100A524 */  addiu      $a1, $a1, 0x1
    /* 3650 80105E50 4E00A228 */  slti       $v0, $a1, 0x4E
    /* 3654 80105E54 F7FF4014 */  bnez       $v0, .L80105E34
    /* 3658 80105E58 2C006324 */   addiu     $v1, $v1, 0x2C
    /* 365C 80105E5C 1180023C */  lui        $v0, %hi(_monBinData)
    /* 3660 80105E60 70A4438C */  lw         $v1, %lo(_monBinData)($v0)
    /* 3664 80105E64 21280000 */  addu       $a1, $zero, $zero
    /* 3668 80105E68 0D006324 */  addiu      $v1, $v1, 0xD
  .L80105E6C:
    /* 366C 80105E6C FFFF6290 */  lbu        $v0, -0x1($v1)
    /* 3670 80105E70 00000000 */  nop
    /* 3674 80105E74 03004010 */  beqz       $v0, .L80105E84
    /* 3678 80105E78 0100A524 */   addiu     $a1, $a1, 0x1
    /* 367C 80105E7C A4170408 */  j          .L80105E90
    /* 3680 80105E80 000064A0 */   sb        $a0, 0x0($v1)
  .L80105E84:
    /* 3684 80105E84 4E00A228 */  slti       $v0, $a1, 0x4E
    /* 3688 80105E88 F8FF4014 */  bnez       $v0, .L80105E6C
    /* 368C 80105E8C 2C006324 */   addiu     $v1, $v1, 0x2C
  .L80105E90:
    /* 3690 80105E90 4D000524 */  addiu      $a1, $zero, 0x4D
    /* 3694 80105E94 1180023C */  lui        $v0, %hi(_monBinData)
    /* 3698 80105E98 70A4428C */  lw         $v0, %lo(_monBinData)($v0)
    /* 369C 80105E9C FF000424 */  addiu      $a0, $zero, 0xFF
    /* 36A0 80105EA0 4A0D4324 */  addiu      $v1, $v0, 0xD4A
  .L80105EA4:
    /* 36A4 80105EA4 FEFF6290 */  lbu        $v0, -0x2($v1)
    /* 36A8 80105EA8 00000000 */  nop
    /* 36AC 80105EAC 03004010 */  beqz       $v0, .L80105EBC
    /* 36B0 80105EB0 00000000 */   nop
    /* 36B4 80105EB4 000064A0 */  sb         $a0, 0x0($v1)
    /* 36B8 80105EB8 2120A000 */  addu       $a0, $a1, $zero
  .L80105EBC:
    /* 36BC 80105EBC FFFFA524 */  addiu      $a1, $a1, -0x1
    /* 36C0 80105EC0 F8FFA104 */  bgez       $a1, .L80105EA4
    /* 36C4 80105EC4 D4FF6324 */   addiu     $v1, $v1, -0x2C
    /* 36C8 80105EC8 1180023C */  lui        $v0, %hi(_monBinData)
    /* 36CC 80105ECC 70A4428C */  lw         $v0, %lo(_monBinData)($v0)
    /* 36D0 80105ED0 4D000524 */  addiu      $a1, $zero, 0x4D
    /* 36D4 80105ED4 4A0D4324 */  addiu      $v1, $v0, 0xD4A
  .L80105ED8:
    /* 36D8 80105ED8 FEFF6290 */  lbu        $v0, -0x2($v1)
    /* 36DC 80105EDC 00000000 */  nop
    /* 36E0 80105EE0 03004010 */  beqz       $v0, .L80105EF0
    /* 36E4 80105EE4 FFFFA524 */   addiu     $a1, $a1, -0x1
    /* 36E8 80105EE8 0800E003 */  jr         $ra
    /* 36EC 80105EEC 000064A0 */   sb        $a0, 0x0($v1)
  .L80105EF0:
    /* 36F0 80105EF0 F9FFA104 */  bgez       $a1, .L80105ED8
    /* 36F4 80105EF4 D4FF6324 */   addiu     $v1, $v1, -0x2C
    /* 36F8 80105EF8 0800E003 */  jr         $ra
    /* 36FC 80105EFC 00000000 */   nop
endlabel func_80105D8C
