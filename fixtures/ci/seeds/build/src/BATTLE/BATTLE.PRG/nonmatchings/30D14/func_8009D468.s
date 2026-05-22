nonmatching func_8009D468, 0x28C

glabel func_8009D468
    /* 34C68 8009D468 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 34C6C 8009D46C 2000B2AF */  sw         $s2, 0x20($sp)
    /* 34C70 8009D470 21908000 */  addu       $s2, $a0, $zero
    /* 34C74 8009D474 0F80033C */  lui        $v1, %hi(D_800F4538)
    /* 34C78 8009D478 38456324 */  addiu      $v1, $v1, %lo(D_800F4538)
    /* 34C7C 8009D47C 80101200 */  sll        $v0, $s2, 2
    /* 34C80 8009D480 21104300 */  addu       $v0, $v0, $v1
    /* 34C84 8009D484 2400BFAF */  sw         $ra, 0x24($sp)
    /* 34C88 8009D488 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 34C8C 8009D48C 1800B0AF */  sw         $s0, 0x18($sp)
    /* 34C90 8009D490 0000518C */  lw         $s1, 0x0($v0)
    /* 34C94 8009D494 00000000 */  nop
    /* 34C98 8009D498 8F002012 */  beqz       $s1, .L8009D6D8
    /* 34C9C 8009D49C F8FF053C */   lui       $a1, (0xFFF8FFFF >> 16)
    /* 34CA0 8009D4A0 FFFFA534 */  ori        $a1, $a1, (0xFFF8FFFF & 0xFFFF)
    /* 34CA4 8009D4A4 FFF0073C */  lui        $a3, (0xF0FFFFFF >> 16)
    /* 34CA8 8009D4A8 FFFFE734 */  ori        $a3, $a3, (0xF0FFFFFF & 0xFFFF)
    /* 34CAC 8009D4AC FF8F063C */  lui        $a2, (0x8FFFFFFF >> 16)
    /* 34CB0 8009D4B0 FFFFC634 */  ori        $a2, $a2, (0x8FFFFFFF & 0xFFFF)
    /* 34CB4 8009D4B4 0800238E */  lw         $v1, 0x8($s1)
    /* 34CB8 8009D4B8 00100224 */  addiu      $v0, $zero, 0x1000
    /* 34CBC 8009D4BC 2C0022A6 */  sh         $v0, 0x2C($s1)
    /* 34CC0 8009D4C0 2E0022A6 */  sh         $v0, 0x2E($s1)
    /* 34CC4 8009D4C4 300022A6 */  sh         $v0, 0x30($s1)
    /* 34CC8 8009D4C8 FEFF0224 */  addiu      $v0, $zero, -0x2
    /* 34CCC 8009D4CC FC1722A2 */  sb         $v0, 0x17FC($s1)
    /* 34CD0 8009D4D0 AC05228E */  lw         $v0, 0x5AC($s1)
    /* 34CD4 8009D4D4 21202002 */  addu       $a0, $s1, $zero
    /* 34CD8 8009D4D8 110020A2 */  sb         $zero, 0x11($s1)
    /* 34CDC 8009D4DC C80520A6 */  sh         $zero, 0x5C8($s1)
    /* 34CE0 8009D4E0 180020A6 */  sh         $zero, 0x18($s1)
    /* 34CE4 8009D4E4 240020AE */  sw         $zero, 0x24($s1)
    /* 34CE8 8009D4E8 280020AE */  sw         $zero, 0x28($s1)
    /* 34CEC 8009D4EC 1A0020A6 */  sh         $zero, 0x1A($s1)
    /* 34CF0 8009D4F0 160020A6 */  sh         $zero, 0x16($s1)
    /* 34CF4 8009D4F4 140020A6 */  sh         $zero, 0x14($s1)
    /* 34CF8 8009D4F8 24186500 */  and        $v1, $v1, $a1
    /* 34CFC 8009D4FC FCFF0524 */  addiu      $a1, $zero, -0x4
    /* 34D00 8009D500 24104500 */  and        $v0, $v0, $a1
    /* 34D04 8009D504 080023AE */  sw         $v1, 0x8($s1)
    /* 34D08 8009D508 24186700 */  and        $v1, $v1, $a3
    /* 34D0C 8009D50C 24186600 */  and        $v1, $v1, $a2
    /* 34D10 8009D510 AC0522AE */  sw         $v0, 0x5AC($s1)
    /* 34D14 8009D514 4E7F020C */  jal        func_8009FD38
    /* 34D18 8009D518 080023AE */   sw        $v1, 0x8($s1)
    /* 34D1C 8009D51C 0F80033C */  lui        $v1, %hi(D_800E8F2C)
    /* 34D20 8009D520 0F80023C */  lui        $v0, %hi(D_800F2450)
    /* 34D24 8009D524 2C8F6390 */  lbu        $v1, %lo(D_800E8F2C)($v1)
    /* 34D28 8009D528 50244224 */  addiu      $v0, $v0, %lo(D_800F2450)
    /* 34D2C 8009D52C 21186200 */  addu       $v1, $v1, $v0
    /* 34D30 8009D530 00006290 */  lbu        $v0, 0x0($v1)
    /* 34D34 8009D534 00000000 */  nop
    /* 34D38 8009D538 08004010 */  beqz       $v0, .L8009D55C
    /* 34D3C 8009D53C 21202002 */   addu      $a0, $s1, $zero
    /* 34D40 8009D540 21280000 */  addu       $a1, $zero, $zero
    /* 34D44 8009D544 26AC020C */  jal        func_800AB098
    /* 34D48 8009D548 2130A000 */   addu      $a2, $a1, $zero
    /* 34D4C 8009D54C 21202002 */  addu       $a0, $s1, $zero
    /* 34D50 8009D550 01000524 */  addiu      $a1, $zero, 0x1
    /* 34D54 8009D554 26AC020C */  jal        func_800AB098
    /* 34D58 8009D558 21300000 */   addu      $a2, $zero, $zero
  .L8009D55C:
    /* 34D5C 8009D55C DFFF063C */  lui        $a2, (0xFFDFFFFF >> 16)
    /* 34D60 8009D560 FFFFC634 */  ori        $a2, $a2, (0xFFDFFFFF & 0xFFFF)
    /* 34D64 8009D564 BFFF073C */  lui        $a3, (0xFFBFFFFF >> 16)
    /* 34D68 8009D568 FFFFE734 */  ori        $a3, $a3, (0xFFBFFFFF & 0xFFFF)
    /* 34D6C 8009D56C 21204002 */  addu       $a0, $s2, $zero
    /* 34D70 8009D570 21280000 */  addu       $a1, $zero, $zero
    /* 34D74 8009D574 0C18228E */  lw         $v0, 0x180C($s1)
    /* 34D78 8009D578 AC05238E */  lw         $v1, 0x5AC($s1)
    /* 34D7C 8009D57C F0FF1024 */  addiu      $s0, $zero, -0x10
    /* 34D80 8009D580 021820A2 */  sb         $zero, 0x1802($s1)
    /* 34D84 8009D584 24105000 */  and        $v0, $v0, $s0
    /* 34D88 8009D588 0C1822AE */  sw         $v0, 0x180C($s1)
    /* 34D8C 8009D58C 1018228E */  lw         $v0, 0x1810($s1)
    /* 34D90 8009D590 24186600 */  and        $v1, $v1, $a2
    /* 34D94 8009D594 AC0523AE */  sw         $v1, 0x5AC($s1)
    /* 34D98 8009D598 24186700 */  and        $v1, $v1, $a3
    /* 34D9C 8009D59C AC0523AE */  sw         $v1, 0x5AC($s1)
    /* 34DA0 8009D5A0 24105000 */  and        $v0, $v0, $s0
    /* 34DA4 8009D5A4 FF81020C */  jal        func_800A07FC
    /* 34DA8 8009D5A8 101822AE */   sw        $v0, 0x1810($s1)
    /* 34DAC 8009D5AC FD172392 */  lbu        $v1, 0x17FD($s1)
    /* 34DB0 8009D5B0 01000224 */  addiu      $v0, $zero, 0x1
    /* 34DB4 8009D5B4 02006214 */  bne        $v1, $v0, .L8009D5C0
    /* 34DB8 8009D5B8 21204002 */   addu      $a0, $s2, $zero
    /* 34DBC 8009D5BC FD1720A2 */  sb         $zero, 0x17FD($s1)
  .L8009D5C0:
    /* 34DC0 8009D5C0 0800228E */  lw         $v0, 0x8($s1)
    /* 34DC4 8009D5C4 1000A527 */  addiu      $a1, $sp, 0x10
    /* 34DC8 8009D5C8 00804234 */  ori        $v0, $v0, 0x8000
    /* 34DCC 8009D5CC 080022AE */  sw         $v0, 0x8($s1)
    /* 34DD0 8009D5D0 647E020C */  jal        func_8009F990
    /* 34DD4 8009D5D4 1000A0A3 */   sb        $zero, 0x10($sp)
    /* 34DD8 8009D5D8 E7FF053C */  lui        $a1, (0xFFE7FFFF >> 16)
    /* 34DDC 8009D5DC FFFFA534 */  ori        $a1, $a1, (0xFFE7FFFF & 0xFFFF)
    /* 34DE0 8009D5E0 62000624 */  addiu      $a2, $zero, 0x62
    /* 34DE4 8009D5E4 0C00238E */  lw         $v1, 0xC($s1)
    /* 34DE8 8009D5E8 04000224 */  addiu      $v0, $zero, 0x4
    /* 34DEC 8009D5EC BE0522A6 */  sh         $v0, 0x5BE($s1)
    /* 34DF0 8009D5F0 0800228E */  lw         $v0, 0x8($s1)
    /* 34DF4 8009D5F4 0FFF0424 */  addiu      $a0, $zero, -0xF1
    /* 34DF8 8009D5F8 FF1720A2 */  sb         $zero, 0x17FF($s1)
    /* 34DFC 8009D5FC 640020A2 */  sb         $zero, 0x64($s1)
    /* 34E00 8009D600 601820A2 */  sb         $zero, 0x1860($s1)
    /* 34E04 8009D604 24187000 */  and        $v1, $v1, $s0
    /* 34E08 8009D608 24186400 */  and        $v1, $v1, $a0
    /* 34E0C 8009D60C 24104500 */  and        $v0, $v0, $a1
    /* 34E10 8009D610 0C0023AE */  sw         $v1, 0xC($s1)
    /* 34E14 8009D614 FFBF0324 */  addiu      $v1, $zero, -0x4001
    /* 34E18 8009D618 24104300 */  and        $v0, $v0, $v1
    /* 34E1C 8009D61C 080022AE */  sw         $v0, 0x8($s1)
    /* 34E20 8009D620 AC05228E */  lw         $v0, 0x5AC($s1)
    /* 34E24 8009D624 F7FF0324 */  addiu      $v1, $zero, -0x9
    /* 34E28 8009D628 24104300 */  and        $v0, $v0, $v1
    /* 34E2C 8009D62C AC0522AE */  sw         $v0, 0x5AC($s1)
    /* 34E30 8009D630 0800228E */  lw         $v0, 0x8($s1)
    /* 34E34 8009D634 FFF00324 */  addiu      $v1, $zero, -0xF01
    /* 34E38 8009D638 24104300 */  and        $v0, $v0, $v1
    /* 34E3C 8009D63C 02004016 */  bnez       $s2, .L8009D648
    /* 34E40 8009D640 080022AE */   sw        $v0, 0x8($s1)
    /* 34E44 8009D644 01000624 */  addiu      $a2, $zero, 0x1
  .L8009D648:
    /* 34E48 8009D648 21204002 */  addu       $a0, $s2, $zero
    /* 34E4C 8009D64C 2128C000 */  addu       $a1, $a2, $zero
    /* 34E50 8009D650 21300000 */  addu       $a2, $zero, $zero
    /* 34E54 8009D654 8180020C */  jal        func_800A0204
    /* 34E58 8009D658 2138C000 */   addu      $a3, $a2, $zero
    /* 34E5C 8009D65C FFFE033C */  lui        $v1, (0xFEFFFFFF >> 16)
    /* 34E60 8009D660 FFFF6334 */  ori        $v1, $v1, (0xFEFFFFFF & 0xFFFF)
    /* 34E64 8009D664 FFFF073C */  lui        $a3, (0xFFFF7FFF >> 16)
    /* 34E68 8009D668 FF7FE734 */  ori        $a3, $a3, (0xFFFF7FFF & 0xFFFF)
    /* 34E6C 8009D66C 64183026 */  addiu      $s0, $s1, 0x1864
    /* 34E70 8009D670 21200002 */  addu       $a0, $s0, $zero
    /* 34E74 8009D674 21280000 */  addu       $a1, $zero, $zero
    /* 34E78 8009D678 AC05228E */  lw         $v0, 0x5AC($s1)
    /* 34E7C 8009D67C 14000624 */  addiu      $a2, $zero, 0x14
    /* 34E80 8009D680 E00620A2 */  sb         $zero, 0x6E0($s1)
    /* 34E84 8009D684 EC0620A6 */  sh         $zero, 0x6EC($s1)
    /* 34E88 8009D688 EE0620A2 */  sb         $zero, 0x6EE($s1)
    /* 34E8C 8009D68C EF0620A2 */  sb         $zero, 0x6EF($s1)
    /* 34E90 8009D690 461820A2 */  sb         $zero, 0x1846($s1)
    /* 34E94 8009D694 24104300 */  and        $v0, $v0, $v1
    /* 34E98 8009D698 AC0522AE */  sw         $v0, 0x5AC($s1)
    /* 34E9C 8009D69C 0800228E */  lw         $v0, 0x8($s1)
    /* 34EA0 8009D6A0 AC05238E */  lw         $v1, 0x5AC($s1)
    /* 34EA4 8009D6A4 07004234 */  ori        $v0, $v0, 0x7
    /* 34EA8 8009D6A8 24186700 */  and        $v1, $v1, $a3
    /* 34EAC 8009D6AC 080022AE */  sw         $v0, 0x8($s1)
    /* 34EB0 8009D6B0 AD9B000C */  jal        memset
    /* 34EB4 8009D6B4 AC0523AE */   sw        $v1, 0x5AC($s1)
    /* 34EB8 8009D6B8 48182426 */  addiu      $a0, $s1, 0x1848
    /* 34EBC 8009D6BC 4E062296 */  lhu        $v0, 0x64E($s1)
    /* 34EC0 8009D6C0 21280000 */  addu       $a1, $zero, $zero
    /* 34EC4 8009D6C4 0C0002A6 */  sh         $v0, 0xC($s0)
    /* 34EC8 8009D6C8 50062296 */  lhu        $v0, 0x650($s1)
    /* 34ECC 8009D6CC 18000624 */  addiu      $a2, $zero, 0x18
    /* 34ED0 8009D6D0 AD9B000C */  jal        memset
    /* 34ED4 8009D6D4 0E0002A6 */   sh        $v0, 0xE($s0)
  .L8009D6D8:
    /* 34ED8 8009D6D8 2400BF8F */  lw         $ra, 0x24($sp)
    /* 34EDC 8009D6DC 2000B28F */  lw         $s2, 0x20($sp)
    /* 34EE0 8009D6E0 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 34EE4 8009D6E4 1800B08F */  lw         $s0, 0x18($sp)
    /* 34EE8 8009D6E8 2800BD27 */  addiu      $sp, $sp, 0x28
    /* 34EEC 8009D6EC 0800E003 */  jr         $ra
    /* 34EF0 8009D6F0 00000000 */   nop
endlabel func_8009D468
