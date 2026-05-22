nonmatching func_8006F630, 0x130

glabel func_8006F630
    /* 6E30 8006F630 21388000 */  addu       $a3, $a0, $zero
    /* 6E34 8006F634 0580043C */  lui        $a0, %hi(vs_main_skills)
    /* 6E38 8006F638 0000A394 */  lhu        $v1, 0x0($a1)
    /* 6E3C 8006F63C DCB98424 */  addiu      $a0, $a0, %lo(vs_main_skills)
    /* 6E40 8006F640 40100300 */  sll        $v0, $v1, 1
    /* 6E44 8006F644 21104300 */  addu       $v0, $v0, $v1
    /* 6E48 8006F648 80100200 */  sll        $v0, $v0, 2
    /* 6E4C 8006F64C 21104300 */  addu       $v0, $v0, $v1
    /* 6E50 8006F650 80100200 */  sll        $v0, $v0, 2
    /* 6E54 8006F654 21104400 */  addu       $v0, $v0, $a0
    /* 6E58 8006F658 1400428C */  lw         $v0, 0x14($v0)
    /* 6E5C 8006F65C 00000000 */  nop
    /* 6E60 8006F660 7F004330 */  andi       $v1, $v0, 0x7F
    /* 6E64 8006F664 3B000224 */  addiu      $v0, $zero, 0x3B
    /* 6E68 8006F668 11006210 */  beq        $v1, $v0, .L8006F6B0
    /* 6E6C 8006F66C 3C006228 */   slti      $v0, $v1, 0x3C
    /* 6E70 8006F670 05004010 */  beqz       $v0, .L8006F688
    /* 6E74 8006F674 3A000224 */   addiu     $v0, $zero, 0x3A
    /* 6E78 8006F678 0A006210 */  beq        $v1, $v0, .L8006F6A4
    /* 6E7C 8006F67C 00000000 */   nop
    /* 6E80 8006F680 AFBD0108 */  j          .L8006F6BC
    /* 6E84 8006F684 0B00E3A0 */   sb        $v1, 0xB($a3)
  .L8006F688:
    /* 6E88 8006F688 3E000224 */  addiu      $v0, $zero, 0x3E
    /* 6E8C 8006F68C 05006210 */  beq        $v1, $v0, .L8006F6A4
    /* 6E90 8006F690 3F000224 */   addiu     $v0, $zero, 0x3F
    /* 6E94 8006F694 06006210 */  beq        $v1, $v0, .L8006F6B0
    /* 6E98 8006F698 00000000 */   nop
    /* 6E9C 8006F69C AFBD0108 */  j          .L8006F6BC
    /* 6EA0 8006F6A0 0B00E3A0 */   sb        $v1, 0xB($a3)
  .L8006F6A4:
    /* 6EA4 8006F6A4 0400C294 */  lhu        $v0, 0x4($a2)
    /* 6EA8 8006F6A8 AEBD0108 */  j          .L8006F6B8
    /* 6EAC 8006F6AC 0B00E3A0 */   sb        $v1, 0xB($a3)
  .L8006F6B0:
    /* 6EB0 8006F6B0 0600C294 */  lhu        $v0, 0x6($a2)
    /* 6EB4 8006F6B4 0B00E3A0 */  sb         $v1, 0xB($a3)
  .L8006F6B8:
    /* 6EB8 8006F6B8 0C00E2A4 */  sh         $v0, 0xC($a3)
  .L8006F6BC:
    /* 6EBC 8006F6BC FF1F033C */  lui        $v1, (0x1FFFFFE0 >> 16)
    /* 6EC0 8006F6C0 0200C290 */  lbu        $v0, 0x2($a2)
    /* 6EC4 8006F6C4 E0FF6334 */  ori        $v1, $v1, (0x1FFFFFE0 & 0xFFFF)
    /* 6EC8 8006F6C8 0E00E2A4 */  sh         $v0, 0xE($a3)
    /* 6ECC 8006F6CC 1400C28C */  lw         $v0, 0x14($a2)
    /* 6ED0 8006F6D0 0580043C */  lui        $a0, %hi(vs_main_skills)
    /* 6ED4 8006F6D4 24104300 */  and        $v0, $v0, $v1
    /* 6ED8 8006F6D8 1000E2AC */  sw         $v0, 0x10($a3)
    /* 6EDC 8006F6DC 0000A394 */  lhu        $v1, 0x0($a1)
    /* 6EE0 8006F6E0 DCB98424 */  addiu      $a0, $a0, %lo(vs_main_skills)
    /* 6EE4 8006F6E4 40100300 */  sll        $v0, $v1, 1
    /* 6EE8 8006F6E8 21104300 */  addu       $v0, $v0, $v1
    /* 6EEC 8006F6EC 80100200 */  sll        $v0, $v0, 2
    /* 6EF0 8006F6F0 21104300 */  addu       $v0, $v0, $v1
    /* 6EF4 8006F6F4 80100200 */  sll        $v0, $v0, 2
    /* 6EF8 8006F6F8 21104400 */  addu       $v0, $v0, $a0
    /* 6EFC 8006F6FC 0000428C */  lw         $v0, 0x0($v0)
    /* 6F00 8006F700 00000000 */  nop
    /* 6F04 8006F704 02150200 */  srl        $v0, $v0, 20
    /* 6F08 8006F708 0F004230 */  andi       $v0, $v0, 0xF
    /* 6F0C 8006F70C 1400E2A0 */  sb         $v0, 0x14($a3)
    /* 6F10 8006F710 0300A290 */  lbu        $v0, 0x3($a1)
    /* 6F14 8006F714 00000000 */  nop
    /* 6F18 8006F718 1500E2A0 */  sb         $v0, 0x15($a3)
    /* 6F1C 8006F71C 0200A290 */  lbu        $v0, 0x2($a1)
    /* 6F20 8006F720 0F80033C */  lui        $v1, %hi(vs_battle_actors)
    /* 6F24 8006F724 1600E2A0 */  sb         $v0, 0x16($a3)
    /* 6F28 8006F728 0000C290 */  lbu        $v0, 0x0($a2)
    /* 6F2C 8006F72C 28196324 */  addiu      $v1, $v1, %lo(vs_battle_actors)
    /* 6F30 8006F730 0F004230 */  andi       $v0, $v0, 0xF
    /* 6F34 8006F734 80100200 */  sll        $v0, $v0, 2
    /* 6F38 8006F738 21104300 */  addu       $v0, $v0, $v1
    /* 6F3C 8006F73C 0000428C */  lw         $v0, 0x0($v0)
    /* 6F40 8006F740 00000000 */  nop
    /* 6F44 8006F744 3C00428C */  lw         $v0, 0x3C($v0)
    /* 6F48 8006F748 00000000 */  nop
    /* 6F4C 8006F74C 37004290 */  lbu        $v0, 0x37($v0)
    /* 6F50 8006F750 00000000 */  nop
    /* 6F54 8006F754 07004230 */  andi       $v0, $v0, 0x7
    /* 6F58 8006F758 0800E003 */  jr         $ra
    /* 6F5C 8006F75C 1700E2A0 */   sb        $v0, 0x17($a3)
endlabel func_8006F630
