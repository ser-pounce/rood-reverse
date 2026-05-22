nonmatching func_8009D6F4, 0xF4

glabel func_8009D6F4
    /* 34EF4 8009D6F4 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 34EF8 8009D6F8 1400B1AF */  sw         $s1, 0x14($sp)
    /* 34EFC 8009D6FC 21880000 */  addu       $s1, $zero, $zero
    /* 34F00 8009D700 0F80023C */  lui        $v0, %hi(D_800F4538)
    /* 34F04 8009D704 1000B0AF */  sw         $s0, 0x10($sp)
    /* 34F08 8009D708 38455024 */  addiu      $s0, $v0, %lo(D_800F4538)
    /* 34F0C 8009D70C 1800BFAF */  sw         $ra, 0x18($sp)
  .L8009D710:
    /* 34F10 8009D710 0000088E */  lw         $t0, 0x0($s0)
    /* 34F14 8009D714 00000000 */  nop
    /* 34F18 8009D718 29000011 */  beqz       $t0, .L8009D7C0
    /* 34F1C 8009D71C 00000000 */   nop
    /* 34F20 8009D720 AC05038D */  lw         $v1, 0x5AC($t0)
    /* 34F24 8009D724 00000000 */  nop
    /* 34F28 8009D728 08006230 */  andi       $v0, $v1, 0x8
    /* 34F2C 8009D72C 03004010 */  beqz       $v0, .L8009D73C
    /* 34F30 8009D730 F7FF0224 */   addiu     $v0, $zero, -0x9
    /* 34F34 8009D734 24106200 */  and        $v0, $v1, $v0
    /* 34F38 8009D738 AC0502AD */  sw         $v0, 0x5AC($t0)
  .L8009D73C:
    /* 34F3C 8009D73C EFFF033C */  lui        $v1, (0xFFEFFFFF >> 16)
    /* 34F40 8009D740 FFFF6334 */  ori        $v1, $v1, (0xFFEFFFFF & 0xFFFF)
    /* 34F44 8009D744 E7FF053C */  lui        $a1, (0xFFE7FFFF >> 16)
    /* 34F48 8009D748 FFFFA534 */  ori        $a1, $a1, (0xFFE7FFFF & 0xFFFF)
    /* 34F4C 8009D74C FFFF063C */  lui        $a2, (0xFFFF7FFF >> 16)
    /* 34F50 8009D750 FF7FC634 */  ori        $a2, $a2, (0xFFFF7FFF & 0xFFFF)
    /* 34F54 8009D754 F8FF073C */  lui        $a3, (0xFFF8FFFF >> 16)
    /* 34F58 8009D758 AC05028D */  lw         $v0, 0x5AC($t0)
    /* 34F5C 8009D75C 0800048D */  lw         $a0, 0x8($t0)
    /* 34F60 8009D760 FFFFE734 */  ori        $a3, $a3, (0xFFF8FFFF & 0xFFFF)
    /* 34F64 8009D764 110000A1 */  sb         $zero, 0x11($t0)
    /* 34F68 8009D768 24104300 */  and        $v0, $v0, $v1
    /* 34F6C 8009D76C AC0502AD */  sw         $v0, 0x5AC($t0)
    /* 34F70 8009D770 F0FF0224 */  addiu      $v0, $zero, -0x10
    /* 34F74 8009D774 24208500 */  and        $a0, $a0, $a1
    /* 34F78 8009D778 0C00038D */  lw         $v1, 0xC($t0)
    /* 34F7C 8009D77C 21280000 */  addu       $a1, $zero, $zero
    /* 34F80 8009D780 24186200 */  and        $v1, $v1, $v0
    /* 34F84 8009D784 0FFF0224 */  addiu      $v0, $zero, -0xF1
    /* 34F88 8009D788 24186200 */  and        $v1, $v1, $v0
    /* 34F8C 8009D78C FFBF0224 */  addiu      $v0, $zero, -0x4001
    /* 34F90 8009D790 24208200 */  and        $a0, $a0, $v0
    /* 34F94 8009D794 0C0003AD */  sw         $v1, 0xC($t0)
    /* 34F98 8009D798 080004AD */  sw         $a0, 0x8($t0)
    /* 34F9C 8009D79C 21188000 */  addu       $v1, $a0, $zero
    /* 34FA0 8009D7A0 24186700 */  and        $v1, $v1, $a3
    /* 34FA4 8009D7A4 AC05028D */  lw         $v0, 0x5AC($t0)
    /* 34FA8 8009D7A8 48180425 */  addiu      $a0, $t0, 0x1848
    /* 34FAC 8009D7AC 080003AD */  sw         $v1, 0x8($t0)
    /* 34FB0 8009D7B0 24104600 */  and        $v0, $v0, $a2
    /* 34FB4 8009D7B4 18000624 */  addiu      $a2, $zero, 0x18
    /* 34FB8 8009D7B8 AD9B000C */  jal        memset
    /* 34FBC 8009D7BC AC0502AD */   sw        $v0, 0x5AC($t0)
  .L8009D7C0:
    /* 34FC0 8009D7C0 01003126 */  addiu      $s1, $s1, 0x1
    /* 34FC4 8009D7C4 1100222A */  slti       $v0, $s1, 0x11
    /* 34FC8 8009D7C8 D1FF4014 */  bnez       $v0, .L8009D710
    /* 34FCC 8009D7CC 04001026 */   addiu     $s0, $s0, 0x4
    /* 34FD0 8009D7D0 1800BF8F */  lw         $ra, 0x18($sp)
    /* 34FD4 8009D7D4 1400B18F */  lw         $s1, 0x14($sp)
    /* 34FD8 8009D7D8 1000B08F */  lw         $s0, 0x10($sp)
    /* 34FDC 8009D7DC 2000BD27 */  addiu      $sp, $sp, 0x20
    /* 34FE0 8009D7E0 0800E003 */  jr         $ra
    /* 34FE4 8009D7E4 00000000 */   nop
endlabel func_8009D6F4
