nonmatching func_800D5F8C, 0xBC

glabel func_800D5F8C
    /* 6D78C 800D5F8C D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 6D790 800D5F90 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 6D794 800D5F94 21888000 */  addu       $s1, $a0, $zero
    /* 6D798 800D5F98 2000B2AF */  sw         $s2, 0x20($sp)
    /* 6D79C 800D5F9C 2190A000 */  addu       $s2, $a1, $zero
    /* 6D7A0 800D5FA0 2400BFAF */  sw         $ra, 0x24($sp)
    /* 6D7A4 800D5FA4 1800B0AF */  sw         $s0, 0x18($sp)
    /* 6D7A8 800D5FA8 06004286 */  lh         $v0, 0x6($s2)
    /* 6D7AC 800D5FAC 0000438E */  lw         $v1, 0x0($s2)
    /* 6D7B0 800D5FB0 C0100200 */  sll        $v0, $v0, 3
    /* 6D7B4 800D5FB4 21806200 */  addu       $s0, $v1, $v0
    /* 6D7B8 800D5FB8 4C0D228E */  lw         $v0, 0xD4C($s1)
    /* 6D7BC 800D5FBC 00000386 */  lh         $v1, 0x0($s0)
    /* 6D7C0 800D5FC0 02004284 */  lh         $v0, 0x2($v0)
    /* 6D7C4 800D5FC4 00000000 */  nop
    /* 6D7C8 800D5FC8 19006214 */  bne        $v1, $v0, .L800D6030
    /* 6D7CC 800D5FCC 01000224 */   addiu     $v0, $zero, 0x1
    /* 6D7D0 800D5FD0 280D2396 */  lhu        $v1, 0xD28($s1)
    /* 6D7D4 800D5FD4 04000224 */  addiu      $v0, $zero, 0x4
    /* 6D7D8 800D5FD8 13006214 */  bne        $v1, $v0, .L800D6028
    /* 6D7DC 800D5FDC 00000000 */   nop
    /* 6D7E0 800D5FE0 2C0D2492 */  lbu        $a0, 0xD2C($s1)
    /* 6D7E4 800D5FE4 F882020C */  jal        func_800A0BE0
    /* 6D7E8 800D5FE8 00000000 */   nop
    /* 6D7EC 800D5FEC 02004230 */  andi       $v0, $v0, 0x2
    /* 6D7F0 800D5FF0 0D004010 */  beqz       $v0, .L800D6028
    /* 6D7F4 800D5FF4 00000000 */   nop
    /* 6D7F8 800D5FF8 07000492 */  lbu        $a0, 0x7($s0)
    /* 6D7FC 800D5FFC 02000586 */  lh         $a1, 0x2($s0)
    /* 6D800 800D6000 2C0D2692 */  lbu        $a2, 0xD2C($s1)
    /* 6D804 800D6004 05000292 */  lbu        $v0, 0x5($s0)
    /* 6D808 800D6008 04000792 */  lbu        $a3, 0x4($s0)
    /* 6D80C 800D600C 80FF4224 */  addiu      $v0, $v0, -0x80
    /* 6D810 800D6010 1000A2AF */  sw         $v0, 0x10($sp)
    /* 6D814 800D6014 06000292 */  lbu        $v0, 0x6($s0)
    /* 6D818 800D6018 80FFE724 */  addiu      $a3, $a3, -0x80
    /* 6D81C 800D601C 80FF4224 */  addiu      $v0, $v0, -0x80
    /* 6D820 800D6020 A7EC010C */  jal        func_8007B29C
    /* 6D824 800D6024 1400A2AF */   sw        $v0, 0x14($sp)
  .L800D6028:
    /* 6D828 800D6028 E055030C */  jal        func_800D5780
    /* 6D82C 800D602C 21204002 */   addu      $a0, $s2, $zero
  .L800D6030:
    /* 6D830 800D6030 2400BF8F */  lw         $ra, 0x24($sp)
    /* 6D834 800D6034 2000B28F */  lw         $s2, 0x20($sp)
    /* 6D838 800D6038 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 6D83C 800D603C 1800B08F */  lw         $s0, 0x18($sp)
    /* 6D840 800D6040 0800E003 */  jr         $ra
    /* 6D844 800D6044 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_800D5F8C
