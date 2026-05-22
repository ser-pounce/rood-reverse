nonmatching func_800CE714, 0x128

glabel func_800CE714
    /* 65F14 800CE714 1C00828C */  lw         $v0, 0x1C($a0)
    /* 65F18 800CE718 0800A0A0 */  sb         $zero, 0x8($a1)
    /* 65F1C 800CE71C 0400A2AC */  sw         $v0, 0x4($a1)
    /* 65F20 800CE720 10008290 */  lbu        $v0, 0x10($a0)
    /* 65F24 800CE724 00000000 */  nop
    /* 65F28 800CE728 0900A2A0 */  sb         $v0, 0x9($a1)
    /* 65F2C 800CE72C 18008294 */  lhu        $v0, 0x18($a0)
    /* 65F30 800CE730 FFFF033C */  lui        $v1, (0xFFFF07FF >> 16)
    /* 65F34 800CE734 0A00A2A4 */  sh         $v0, 0xA($a1)
    /* 65F38 800CE738 1400828C */  lw         $v0, 0x14($a0)
    /* 65F3C 800CE73C FF076334 */  ori        $v1, $v1, (0xFFFF07FF & 0xFFFF)
    /* 65F40 800CE740 1000A0AC */  sw         $zero, 0x10($a1)
    /* 65F44 800CE744 0C00A2AC */  sw         $v0, 0xC($a1)
    /* 65F48 800CE748 20008290 */  lbu        $v0, 0x20($a0)
    /* 65F4C 800CE74C 21380000 */  addu       $a3, $zero, $zero
    /* 65F50 800CE750 1400A2A0 */  sb         $v0, 0x14($a1)
    /* 65F54 800CE754 1400A28C */  lw         $v0, 0x14($a1)
    /* 65F58 800CE758 2130A000 */  addu       $a2, $a1, $zero
    /* 65F5C 800CE75C 1800A0AC */  sw         $zero, 0x18($a1)
    /* 65F60 800CE760 24104300 */  and        $v0, $v0, $v1
    /* 65F64 800CE764 1400A2AC */  sw         $v0, 0x14($a1)
    /* 65F68 800CE768 1600A0A4 */  sh         $zero, 0x16($a1)
  .L800CE76C:
    /* 65F6C 800CE76C 2200C0A4 */  sh         $zero, 0x22($a2)
    /* 65F70 800CE770 2000C0AC */  sw         $zero, 0x20($a2)
    /* 65F74 800CE774 1C00C0AC */  sw         $zero, 0x1C($a2)
    /* 65F78 800CE778 2800C0AC */  sw         $zero, 0x28($a2)
    /* 65F7C 800CE77C 2400C0AC */  sw         $zero, 0x24($a2)
    /* 65F80 800CE780 3400C0AC */  sw         $zero, 0x34($a2)
    /* 65F84 800CE784 3000C0AC */  sw         $zero, 0x30($a2)
    /* 65F88 800CE788 2C00C0AC */  sw         $zero, 0x2C($a2)
    /* 65F8C 800CE78C 4C00C0AC */  sw         $zero, 0x4C($a2)
    /* 65F90 800CE790 4800C0AC */  sw         $zero, 0x48($a2)
    /* 65F94 800CE794 4400C0AC */  sw         $zero, 0x44($a2)
    /* 65F98 800CE798 5000C0AC */  sw         $zero, 0x50($a2)
    /* 65F9C 800CE79C 0100E724 */  addiu      $a3, $a3, 0x1
    /* 65FA0 800CE7A0 1000E228 */  slti       $v0, $a3, 0x10
    /* 65FA4 800CE7A4 F1FF4014 */  bnez       $v0, .L800CE76C
    /* 65FA8 800CE7A8 D000C624 */   addiu     $a2, $a2, 0xD0
    /* 65FAC 800CE7AC 0000828C */  lw         $v0, 0x0($a0)
    /* 65FB0 800CE7B0 00000000 */  nop
    /* 65FB4 800CE7B4 0000488C */  lw         $t0, 0x0($v0)
    /* 65FB8 800CE7B8 0400498C */  lw         $t1, 0x4($v0)
    /* 65FBC 800CE7BC 08004A8C */  lw         $t2, 0x8($v0)
    /* 65FC0 800CE7C0 1C0DA8AC */  sw         $t0, 0xD1C($a1)
    /* 65FC4 800CE7C4 200DA9AC */  sw         $t1, 0xD20($a1)
    /* 65FC8 800CE7C8 240DAAAC */  sw         $t2, 0xD24($a1)
    /* 65FCC 800CE7CC 0400828C */  lw         $v0, 0x4($a0)
    /* 65FD0 800CE7D0 00000000 */  nop
    /* 65FD4 800CE7D4 0000488C */  lw         $t0, 0x0($v0)
    /* 65FD8 800CE7D8 0400498C */  lw         $t1, 0x4($v0)
    /* 65FDC 800CE7DC 08004A8C */  lw         $t2, 0x8($v0)
    /* 65FE0 800CE7E0 280DA8AC */  sw         $t0, 0xD28($a1)
    /* 65FE4 800CE7E4 2C0DA9AC */  sw         $t1, 0xD2C($a1)
    /* 65FE8 800CE7E8 300DAAAC */  sw         $t2, 0xD30($a1)
    /* 65FEC 800CE7EC 0800828C */  lw         $v0, 0x8($a0)
    /* 65FF0 800CE7F0 00000000 */  nop
    /* 65FF4 800CE7F4 0000488C */  lw         $t0, 0x0($v0)
    /* 65FF8 800CE7F8 0400498C */  lw         $t1, 0x4($v0)
    /* 65FFC 800CE7FC 08004A8C */  lw         $t2, 0x8($v0)
    /* 66000 800CE800 340DA8AC */  sw         $t0, 0xD34($a1)
    /* 66004 800CE804 380DA9AC */  sw         $t1, 0xD38($a1)
    /* 66008 800CE808 3C0DAAAC */  sw         $t2, 0xD3C($a1)
    /* 6600C 800CE80C 0C00828C */  lw         $v0, 0xC($a0)
    /* 66010 800CE810 00000000 */  nop
    /* 66014 800CE814 0000488C */  lw         $t0, 0x0($v0)
    /* 66018 800CE818 0400498C */  lw         $t1, 0x4($v0)
    /* 6601C 800CE81C 08004A8C */  lw         $t2, 0x8($v0)
    /* 66020 800CE820 400DA8AC */  sw         $t0, 0xD40($a1)
    /* 66024 800CE824 440DA9AC */  sw         $t1, 0xD44($a1)
    /* 66028 800CE828 480DAAAC */  sw         $t2, 0xD48($a1)
    /* 6602C 800CE82C 4C0DA0AC */  sw         $zero, 0xD4C($a1)
    /* 66030 800CE830 500DA0AC */  sw         $zero, 0xD50($a1)
    /* 66034 800CE834 0800E003 */  jr         $ra
    /* 66038 800CE838 580DA0AC */   sw        $zero, 0xD58($a1)
endlabel func_800CE714
