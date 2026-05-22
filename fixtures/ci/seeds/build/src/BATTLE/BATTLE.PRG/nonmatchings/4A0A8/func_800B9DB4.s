nonmatching func_800B9DB4, 0x174

glabel func_800B9DB4
    /* 515B4 800B9DB4 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 515B8 800B9DB8 1400B1AF */  sw         $s1, 0x14($sp)
    /* 515BC 800B9DBC 0F80113C */  lui        $s1, %hi(D_800F4C4E)
    /* 515C0 800B9DC0 4E4C2292 */  lbu        $v0, %lo(D_800F4C4E)($s1)
    /* 515C4 800B9DC4 1000B0AF */  sw         $s0, 0x10($sp)
    /* 515C8 800B9DC8 21808000 */  addu       $s0, $a0, $zero
    /* 515CC 800B9DCC 3A004014 */  bnez       $v0, .L800B9EB8
    /* 515D0 800B9DD0 1800BFAF */   sw        $ra, 0x18($sp)
    /* 515D4 800B9DD4 FDFA020C */  jal        vs_battle_getStateFlag
    /* 515D8 800B9DD8 AC000424 */   addiu     $a0, $zero, 0xAC
    /* 515DC 800B9DDC FF004230 */  andi       $v0, $v0, 0xFF
    /* 515E0 800B9DE0 03004014 */  bnez       $v0, .L800B9DF0
    /* 515E4 800B9DE4 0F80033C */   lui       $v1, %hi(D_800E9B4C)
    /* 515E8 800B9DE8 C5E70208 */  j          .L800B9F14
    /* 515EC 800B9DEC 21100000 */   addu      $v0, $zero, $zero
  .L800B9DF0:
    /* 515F0 800B9DF0 01000292 */  lbu        $v0, 0x1($s0)
    /* 515F4 800B9DF4 4C9B6324 */  addiu      $v1, $v1, %lo(D_800E9B4C)
    /* 515F8 800B9DF8 80100200 */  sll        $v0, $v0, 2
    /* 515FC 800B9DFC 21104300 */  addu       $v0, $v0, $v1
    /* 51600 800B9E00 0000458C */  lw         $a1, 0x0($v0)
    /* 51604 800B9E04 2BF0010C */  jal        func_8007C0AC
    /* 51608 800B9E08 21200000 */   addu      $a0, $zero, $zero
    /* 5160C 800B9E0C 0F80023C */  lui        $v0, %hi(D_800F4C2C)
    /* 51610 800B9E10 2C4C4390 */  lbu        $v1, %lo(D_800F4C2C)($v0)
    /* 51614 800B9E14 02000224 */  addiu      $v0, $zero, 0x2
    /* 51618 800B9E18 05006210 */  beq        $v1, $v0, .L800B9E30
    /* 5161C 800B9E1C 00000000 */   nop
    /* 51620 800B9E20 02000292 */  lbu        $v0, 0x2($s0)
    /* 51624 800B9E24 00000000 */  nop
    /* 51628 800B9E28 12004014 */  bnez       $v0, .L800B9E74
    /* 5162C 800B9E2C 21200000 */   addu      $a0, $zero, $zero
  .L800B9E30:
    /* 51630 800B9E30 F882020C */  jal        func_800A0BE0
    /* 51634 800B9E34 21200000 */   addu      $a0, $zero, $zero
    /* 51638 800B9E38 21184000 */  addu       $v1, $v0, $zero
    /* 5163C 800B9E3C 01000292 */  lbu        $v0, 0x1($s0)
    /* 51640 800B9E40 00000000 */  nop
    /* 51644 800B9E44 04004010 */  beqz       $v0, .L800B9E58
    /* 51648 800B9E48 21286000 */   addu      $a1, $v1, $zero
    /* 5164C 800B9E4C 00186234 */  ori        $v0, $v1, 0x1800
    /* 51650 800B9E50 97E70208 */  j          .L800B9E5C
    /* 51654 800B9E54 FFFF4530 */   andi      $a1, $v0, 0xFFFF
  .L800B9E58:
    /* 51658 800B9E58 FFE7A530 */  andi       $a1, $a1, 0xE7FF
  .L800B9E5C:
    /* 5165C 800B9E5C 1F82020C */  jal        func_800A087C
    /* 51660 800B9E60 21200000 */   addu      $a0, $zero, $zero
    /* 51664 800B9E64 2376020C */  jal        func_8009D88C
    /* 51668 800B9E68 21200000 */   addu      $a0, $zero, $zero
    /* 5166C 800B9E6C C5E70208 */  j          .L800B9F14
    /* 51670 800B9E70 21100000 */   addu      $v0, $zero, $zero
  .L800B9E74:
    /* 51674 800B9E74 21308000 */  addu       $a2, $a0, $zero
    /* 51678 800B9E78 0A000724 */  addiu      $a3, $zero, 0xA
    /* 5167C 800B9E7C 02000292 */  lbu        $v0, 0x2($s0)
    /* 51680 800B9E80 01000592 */  lbu        $a1, 0x1($s0)
    /* 51684 800B9E84 FFFF4224 */  addiu      $v0, $v0, -0x1
    /* 51688 800B9E88 40100200 */  sll        $v0, $v0, 1
    /* 5168C 800B9E8C 0100A538 */  xori       $a1, $a1, 0x1
    /* 51690 800B9E90 6D00A524 */  addiu      $a1, $a1, 0x6D
    /* 51694 800B9E94 8180020C */  jal        func_800A0204
    /* 51698 800B9E98 21284500 */   addu      $a1, $v0, $a1
    /* 5169C 800B9E9C 01000592 */  lbu        $a1, 0x1($s0)
    /* 516A0 800B9EA0 21200000 */  addu       $a0, $zero, $zero
    /* 516A4 800B9EA4 F776020C */  jal        func_8009DBDC
    /* 516A8 800B9EA8 0100A538 */   xori      $a1, $a1, 0x1
    /* 516AC 800B9EAC 01000224 */  addiu      $v0, $zero, 0x1
    /* 516B0 800B9EB0 C5E70208 */  j          .L800B9F14
    /* 516B4 800B9EB4 4E4C22A2 */   sb        $v0, %lo(D_800F4C4E)($s1)
  .L800B9EB8:
    /* 516B8 800B9EB8 0F80023C */  lui        $v0, %hi(D_800F4C2C)
    /* 516BC 800B9EBC 2C4C4390 */  lbu        $v1, %lo(D_800F4C2C)($v0)
    /* 516C0 800B9EC0 02000224 */  addiu      $v0, $zero, 0x2
    /* 516C4 800B9EC4 03006214 */  bne        $v1, $v0, .L800B9ED4
    /* 516C8 800B9EC8 00000000 */   nop
    /* 516CC 800B9ECC 8CE70208 */  j          .L800B9E30
    /* 516D0 800B9ED0 4E4C20A2 */   sb        $zero, %lo(D_800F4C4E)($s1)
  .L800B9ED4:
    /* 516D4 800B9ED4 F882020C */  jal        func_800A0BE0
    /* 516D8 800B9ED8 21200000 */   addu      $a0, $zero, $zero
    /* 516DC 800B9EDC 80004230 */  andi       $v0, $v0, 0x80
    /* 516E0 800B9EE0 0C004010 */  beqz       $v0, .L800B9F14
    /* 516E4 800B9EE4 01000224 */   addiu     $v0, $zero, 0x1
    /* 516E8 800B9EE8 01000292 */  lbu        $v0, 0x1($s0)
    /* 516EC 800B9EEC 00000000 */  nop
    /* 516F0 800B9EF0 02004010 */  beqz       $v0, .L800B9EFC
    /* 516F4 800B9EF4 06000524 */   addiu     $a1, $zero, 0x6
    /* 516F8 800B9EF8 65000524 */  addiu      $a1, $zero, 0x65
  .L800B9EFC:
    /* 516FC 800B9EFC 21200000 */  addu       $a0, $zero, $zero
    /* 51700 800B9F00 21308000 */  addu       $a2, $a0, $zero
    /* 51704 800B9F04 8180020C */  jal        func_800A0204
    /* 51708 800B9F08 0A000724 */   addiu     $a3, $zero, 0xA
    /* 5170C 800B9F0C 4E4C20A2 */  sb         $zero, %lo(D_800F4C4E)($s1)
    /* 51710 800B9F10 21100000 */  addu       $v0, $zero, $zero
  .L800B9F14:
    /* 51714 800B9F14 1800BF8F */  lw         $ra, 0x18($sp)
    /* 51718 800B9F18 1400B18F */  lw         $s1, 0x14($sp)
    /* 5171C 800B9F1C 1000B08F */  lw         $s0, 0x10($sp)
    /* 51720 800B9F20 0800E003 */  jr         $ra
    /* 51724 800B9F24 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_800B9DB4
