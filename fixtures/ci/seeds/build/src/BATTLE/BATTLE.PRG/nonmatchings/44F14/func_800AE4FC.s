nonmatching func_800AE4FC, 0x190

glabel func_800AE4FC
    /* 45CFC 800AE4FC D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 45D00 800AE500 2800B2AF */  sw         $s2, 0x28($sp)
    /* 45D04 800AE504 21908000 */  addu       $s2, $a0, $zero
    /* 45D08 800AE508 2C00BFAF */  sw         $ra, 0x2C($sp)
    /* 45D0C 800AE50C 2400B1AF */  sw         $s1, 0x24($sp)
    /* 45D10 800AE510 2000B0AF */  sw         $s0, 0x20($sp)
    /* 45D14 800AE514 1E004286 */  lh         $v0, 0x1E($s2)
    /* 45D18 800AE518 00000000 */  nop
    /* 45D1C 800AE51C B80B4228 */  slti       $v0, $v0, 0xBB8
    /* 45D20 800AE520 53004010 */  beqz       $v0, .L800AE670
    /* 45D24 800AE524 2188A000 */   addu      $s1, $a1, $zero
    /* 45D28 800AE528 0F80033C */  lui        $v1, %hi(D_800F4538)
    /* 45D2C 800AE52C 0F004492 */  lbu        $a0, 0xF($s2)
    /* 45D30 800AE530 38456324 */  addiu      $v1, $v1, %lo(D_800F4538)
    /* 45D34 800AE534 80100400 */  sll        $v0, $a0, 2
    /* 45D38 800AE538 21104300 */  addu       $v0, $v0, $v1
    /* 45D3C 800AE53C 0000508C */  lw         $s0, 0x0($v0)
    /* 45D40 800AE540 00000000 */  nop
    /* 45D44 800AE544 E4170392 */  lbu        $v1, 0x17E4($s0)
    /* 45D48 800AE548 02000224 */  addiu      $v0, $zero, 0x2
    /* 45D4C 800AE54C 05006214 */  bne        $v1, $v0, .L800AE564
    /* 45D50 800AE550 3F00023C */   lui       $v0, (0x3F9F00 >> 16)
    /* 45D54 800AE554 80000224 */  addiu      $v0, $zero, 0x80
    /* 45D58 800AE558 1800A2AF */  sw         $v0, 0x18($sp)
    /* 45D5C 800AE55C 75B90208 */  j          .L800AE5D4
    /* 45D60 800AE560 1C00A0AF */   sw        $zero, 0x1C($sp)
  .L800AE564:
    /* 45D64 800AE564 0800038E */  lw         $v1, 0x8($s0)
    /* 45D68 800AE568 009F4234 */  ori        $v0, $v0, (0x3F9F00 & 0xFFFF)
    /* 45D6C 800AE56C 24186200 */  and        $v1, $v1, $v0
    /* 45D70 800AE570 00800234 */  ori        $v0, $zero, 0x8000
    /* 45D74 800AE574 04006210 */  beq        $v1, $v0, .L800AE588
    /* 45D78 800AE578 FF000524 */   addiu     $a1, $zero, 0xFF
    /* 45D7C 800AE57C FC060626 */  addiu      $a2, $s0, 0x6FC
    /* 45D80 800AE580 A084020C */  jal        func_800A1280
    /* 45D84 800AE584 21380000 */   addu      $a3, $zero, $zero
  .L800AE588:
    /* 45D88 800AE588 FC06048E */  lw         $a0, 0x6FC($s0)
    /* 45D8C 800AE58C 00070586 */  lh         $a1, 0x700($s0)
    /* 45D90 800AE590 6B16010C */  jal        vs_main_computeSfxPan
    /* 45D94 800AE594 00000000 */   nop
    /* 45D98 800AE598 21184000 */  addu       $v1, $v0, $zero
    /* 45D9C 800AE59C 03140300 */  sra        $v0, $v1, 16
    /* 45DA0 800AE5A0 1800A2AF */  sw         $v0, 0x18($sp)
    /* 45DA4 800AE5A4 E5170292 */  lbu        $v0, 0x17E5($s0)
    /* 45DA8 800AE5A8 00000000 */  nop
    /* 45DAC 800AE5AC 02004010 */  beqz       $v0, .L800AE5B8
    /* 45DB0 800AE5B0 00000000 */   nop
    /* 45DB4 800AE5B4 1800A2AF */  sw         $v0, 0x18($sp)
  .L800AE5B8:
    /* 45DB8 800AE5B8 FFFF6230 */  andi       $v0, $v1, 0xFFFF
    /* 45DBC 800AE5BC 1C00A2AF */  sw         $v0, 0x1C($sp)
    /* 45DC0 800AE5C0 E6170292 */  lbu        $v0, 0x17E6($s0)
    /* 45DC4 800AE5C4 00000000 */  nop
    /* 45DC8 800AE5C8 02004010 */  beqz       $v0, .L800AE5D4
    /* 45DCC 800AE5CC 00000000 */   nop
    /* 45DD0 800AE5D0 1C00A2AF */  sw         $v0, 0x1C($sp)
  .L800AE5D4:
    /* 45DD4 800AE5D4 1C00A68F */  lw         $a2, 0x1C($sp)
    /* 45DD8 800AE5D8 00000000 */  nop
    /* 45DDC 800AE5DC 2400C010 */  beqz       $a2, .L800AE670
    /* 45DE0 800AE5E0 08000224 */   addiu     $v0, $zero, 0x8
    /* 45DE4 800AE5E4 08002216 */  bne        $s1, $v0, .L800AE608
    /* 45DE8 800AE5E8 04000224 */   addiu     $v0, $zero, 0x4
    /* 45DEC 800AE5EC 6800428E */  lw         $v0, 0x68($s2)
    /* 45DF0 800AE5F0 1800A58F */  lw         $a1, 0x18($sp)
    /* 45DF4 800AE5F4 3000448C */  lw         $a0, 0x30($v0)
    /* 45DF8 800AE5F8 58B3010C */  jal        func_8006CD60
    /* 45DFC 800AE5FC 00000000 */   nop
    /* 45E00 800AE600 9CB90208 */  j          .L800AE670
    /* 45E04 800AE604 00000000 */   nop
  .L800AE608:
    /* 45E08 800AE608 12002216 */  bne        $s1, $v0, .L800AE654
    /* 45E0C 800AE60C 80010424 */   addiu     $a0, $zero, 0x180
    /* 45E10 800AE610 B19B000C */  jal        rand
    /* 45E14 800AE614 00000000 */   nop
    /* 45E18 800AE618 21404000 */  addu       $t0, $v0, $zero
    /* 45E1C 800AE61C 02000105 */  bgez       $t0, .L800AE628
    /* 45E20 800AE620 21300001 */   addu      $a2, $t0, $zero
    /* 45E24 800AE624 03000625 */  addiu      $a2, $t0, 0x3
  .L800AE628:
    /* 45E28 800AE628 7E000424 */  addiu      $a0, $zero, 0x7E
    /* 45E2C 800AE62C 83300600 */  sra        $a2, $a2, 2
    /* 45E30 800AE630 80300600 */  sll        $a2, $a2, 2
    /* 45E34 800AE634 6800438E */  lw         $v1, 0x68($s2)
    /* 45E38 800AE638 1C00A28F */  lw         $v0, 0x1C($sp)
    /* 45E3C 800AE63C 23300601 */  subu       $a2, $t0, $a2
    /* 45E40 800AE640 1000A2AF */  sw         $v0, 0x10($sp)
    /* 45E44 800AE644 3000658C */  lw         $a1, 0x30($v1)
    /* 45E48 800AE648 1800A78F */  lw         $a3, 0x18($sp)
    /* 45E4C 800AE64C 9AB90208 */  j          .L800AE668
    /* 45E50 800AE650 0400C624 */   addiu     $a2, $a2, 0x4
  .L800AE654:
    /* 45E54 800AE654 6800428E */  lw         $v0, 0x68($s2)
    /* 45E58 800AE658 1000A6AF */  sw         $a2, 0x10($sp)
    /* 45E5C 800AE65C 1800A78F */  lw         $a3, 0x18($sp)
    /* 45E60 800AE660 3000458C */  lw         $a1, 0x30($v0)
    /* 45E64 800AE664 21302002 */  addu       $a2, $s1, $zero
  .L800AE668:
    /* 45E68 800AE668 7318010C */  jal        func_800461CC
    /* 45E6C 800AE66C 00000000 */   nop
  .L800AE670:
    /* 45E70 800AE670 2C00BF8F */  lw         $ra, 0x2C($sp)
    /* 45E74 800AE674 2800B28F */  lw         $s2, 0x28($sp)
    /* 45E78 800AE678 2400B18F */  lw         $s1, 0x24($sp)
    /* 45E7C 800AE67C 2000B08F */  lw         $s0, 0x20($sp)
    /* 45E80 800AE680 3000BD27 */  addiu      $sp, $sp, 0x30
    /* 45E84 800AE684 0800E003 */  jr         $ra
    /* 45E88 800AE688 00000000 */   nop
endlabel func_800AE4FC
