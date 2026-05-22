nonmatching func_80044DF4, 0xD4

glabel func_80044DF4
    /* 355F4 80044DF4 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 355F8 80044DF8 1800B2AF */  sw         $s2, 0x18($sp)
    /* 355FC 80044DFC 21908000 */  addu       $s2, $a0, $zero
    /* 35600 80044E00 2400BFAF */  sw         $ra, 0x24($sp)
    /* 35604 80044E04 2000B4AF */  sw         $s4, 0x20($sp)
    /* 35608 80044E08 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 3560C 80044E0C 1400B1AF */  sw         $s1, 0x14($sp)
    /* 35610 80044E10 15004012 */  beqz       $s2, .L80044E68
    /* 35614 80044E14 1000B0AF */   sw        $s0, 0x10($sp)
    /* 35618 80044E18 0680133C */  lui        $s3, %hi(vs_main_soundData)
    /* 3561C 80044E1C 38E07426 */  addiu      $s4, $s3, %lo(vs_main_soundData)
    /* 35620 80044E20 FFFF4226 */  addiu      $v0, $s2, -0x1
    /* 35624 80044E24 80100200 */  sll        $v0, $v0, 2
    /* 35628 80044E28 21805400 */  addu       $s0, $v0, $s4
    /* 3562C 80044E2C 1400048E */  lw         $a0, 0x14($s0)
    /* 35630 80044E30 FFFF1134 */  ori        $s1, $zero, 0xFFFF
    /* 35634 80044E34 04009110 */  beq        $a0, $s1, .L80044E48
    /* 35638 80044E38 00000000 */   nop
    /* 3563C 80044E3C F747000C */  jal        func_80011FDC
    /* 35640 80044E40 00000000 */   nop
    /* 35644 80044E44 140011AE */  sw         $s1, 0x14($s0)
  .L80044E48:
    /* 35648 80044E48 38E0628E */  lw         $v0, %lo(vs_main_soundData)($s3)
    /* 3564C 80044E4C 00000000 */  nop
    /* 35650 80044E50 15005214 */  bne        $v0, $s2, .L80044EA8
    /* 35654 80044E54 01000224 */   addiu     $v0, $zero, 0x1
    /* 35658 80044E58 38E060AE */  sw         $zero, %lo(vs_main_soundData)($s3)
    /* 3565C 80044E5C 0C0080AE */  sw         $zero, 0xC($s4)
    /* 35660 80044E60 AA130108 */  j          .L80044EA8
    /* 35664 80044E64 040091AE */   sw        $s1, 0x4($s4)
  .L80044E68:
    /* 35668 80044E68 DE4A000C */  jal        func_80012B78
    /* 3566C 80044E6C 00000000 */   nop
    /* 35670 80044E70 FFFF0634 */  ori        $a2, $zero, 0xFFFF
    /* 35674 80044E74 03000524 */  addiu      $a1, $zero, 0x3
    /* 35678 80044E78 0680023C */  lui        $v0, %hi(vs_main_soundData)
    /* 3567C 80044E7C 38E04324 */  addiu      $v1, $v0, %lo(vs_main_soundData)
    /* 35680 80044E80 0C006424 */  addiu      $a0, $v1, 0xC
    /* 35684 80044E84 38E040AC */  sw         $zero, %lo(vs_main_soundData)($v0)
    /* 35688 80044E88 2110C000 */  addu       $v0, $a2, $zero
    /* 3568C 80044E8C 0C0060AC */  sw         $zero, 0xC($v1)
    /* 35690 80044E90 040062AC */  sw         $v0, 0x4($v1)
  .L80044E94:
    /* 35694 80044E94 140086AC */  sw         $a2, 0x14($a0)
    /* 35698 80044E98 FFFFA524 */  addiu      $a1, $a1, -0x1
    /* 3569C 80044E9C FDFFA104 */  bgez       $a1, .L80044E94
    /* 356A0 80044EA0 FCFF8424 */   addiu     $a0, $a0, -0x4
    /* 356A4 80044EA4 01000224 */  addiu      $v0, $zero, 0x1
  .L80044EA8:
    /* 356A8 80044EA8 2400BF8F */  lw         $ra, 0x24($sp)
    /* 356AC 80044EAC 2000B48F */  lw         $s4, 0x20($sp)
    /* 356B0 80044EB0 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 356B4 80044EB4 1800B28F */  lw         $s2, 0x18($sp)
    /* 356B8 80044EB8 1400B18F */  lw         $s1, 0x14($sp)
    /* 356BC 80044EBC 1000B08F */  lw         $s0, 0x10($sp)
    /* 356C0 80044EC0 0800E003 */  jr         $ra
    /* 356C4 80044EC4 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_80044DF4
