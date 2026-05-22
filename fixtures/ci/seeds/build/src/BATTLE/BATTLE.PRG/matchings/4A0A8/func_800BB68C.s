nonmatching func_800BB68C, 0xFC

glabel func_800BB68C
    /* 52E8C 800BB68C D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 52E90 800BB690 1400B1AF */  sw         $s1, 0x14($sp)
    /* 52E94 800BB694 2188A000 */  addu       $s1, $a1, $zero
    /* 52E98 800BB698 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 52E9C 800BB69C 21980000 */  addu       $s3, $zero, $zero
    /* 52EA0 800BB6A0 21188000 */  addu       $v1, $a0, $zero
    /* 52EA4 800BB6A4 00208430 */  andi       $a0, $a0, 0x2000
    /* 52EA8 800BB6A8 2000BFAF */  sw         $ra, 0x20($sp)
    /* 52EAC 800BB6AC 1800B2AF */  sw         $s2, 0x18($sp)
    /* 52EB0 800BB6B0 1000B0AF */  sw         $s0, 0x10($sp)
    /* 52EB4 800BB6B4 000020A2 */  sb         $zero, 0x0($s1)
    /* 52EB8 800BB6B8 26008010 */  beqz       $a0, .L800BB754
    /* 52EBC 800BB6BC 010020A2 */   sb        $zero, 0x1($s1)
    /* 52EC0 800BB6C0 FFFF6330 */  andi       $v1, $v1, 0xFFFF
    /* 52EC4 800BB6C4 03200224 */  addiu      $v0, $zero, 0x2003
    /* 52EC8 800BB6C8 02006214 */  bne        $v1, $v0, .L800BB6D4
    /* 52ECC 800BB6CC FFFF0424 */   addiu     $a0, $zero, -0x1
    /* 52ED0 800BB6D0 04000424 */  addiu      $a0, $zero, 0x4
  .L800BB6D4:
    /* 52ED4 800BB6D4 21800000 */  addu       $s0, $zero, $zero
    /* 52ED8 800BB6D8 00140400 */  sll        $v0, $a0, 16
    /* 52EDC 800BB6DC 03940200 */  sra        $s2, $v0, 16
    /* 52EE0 800BB6E0 00241000 */  sll        $a0, $s0, 16
  .L800BB6E4:
    /* 52EE4 800BB6E4 D9F3010C */  jal        func_8007CF64
    /* 52EE8 800BB6E8 03240400 */   sra       $a0, $a0, 16
    /* 52EEC 800BB6EC 10004010 */  beqz       $v0, .L800BB730
    /* 52EF0 800BB6F0 00000000 */   nop
    /* 52EF4 800BB6F4 05004006 */  bltz       $s2, .L800BB70C
    /* 52EF8 800BB6F8 00000000 */   nop
    /* 52EFC 800BB6FC 1C004294 */  lhu        $v0, 0x1C($v0)
    /* 52F00 800BB700 00000000 */  nop
    /* 52F04 800BB704 0B005214 */  bne        $v0, $s2, .L800BB734
    /* 52F08 800BB708 01000226 */   addiu     $v0, $s0, 0x1
  .L800BB70C:
    /* 52F0C 800BB70C 21106002 */  addu       $v0, $s3, $zero
    /* 52F10 800BB710 00140200 */  sll        $v0, $v0, 16
    /* 52F14 800BB714 03140200 */  sra        $v0, $v0, 16
    /* 52F18 800BB718 21102202 */  addu       $v0, $s1, $v0
    /* 52F1C 800BB71C 020050A0 */  sb         $s0, 0x2($v0)
    /* 52F20 800BB720 00002292 */  lbu        $v0, 0x0($s1)
    /* 52F24 800BB724 01007326 */  addiu      $s3, $s3, 0x1
    /* 52F28 800BB728 01004224 */  addiu      $v0, $v0, 0x1
    /* 52F2C 800BB72C 000022A2 */  sb         $v0, 0x0($s1)
  .L800BB730:
    /* 52F30 800BB730 01000226 */  addiu      $v0, $s0, 0x1
  .L800BB734:
    /* 52F34 800BB734 21804000 */  addu       $s0, $v0, $zero
    /* 52F38 800BB738 00140200 */  sll        $v0, $v0, 16
    /* 52F3C 800BB73C 03140200 */  sra        $v0, $v0, 16
    /* 52F40 800BB740 11004228 */  slti       $v0, $v0, 0x11
    /* 52F44 800BB744 E7FF4014 */  bnez       $v0, .L800BB6E4
    /* 52F48 800BB748 00241000 */   sll       $a0, $s0, 16
    /* 52F4C 800BB74C DBED0208 */  j          .L800BB76C
    /* 52F50 800BB750 00000000 */   nop
  .L800BB754:
    /* 52F54 800BB754 00002292 */  lbu        $v0, 0x0($s1)
    /* 52F58 800BB758 FFFF6430 */  andi       $a0, $v1, 0xFFFF
    /* 52F5C 800BB75C 01004224 */  addiu      $v0, $v0, 0x1
    /* 52F60 800BB760 94FF020C */  jal        func_800BFE50
    /* 52F64 800BB764 000022A2 */   sb        $v0, 0x0($s1)
    /* 52F68 800BB768 020022A2 */  sb         $v0, 0x2($s1)
  .L800BB76C:
    /* 52F6C 800BB76C 2000BF8F */  lw         $ra, 0x20($sp)
    /* 52F70 800BB770 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 52F74 800BB774 1800B28F */  lw         $s2, 0x18($sp)
    /* 52F78 800BB778 1400B18F */  lw         $s1, 0x14($sp)
    /* 52F7C 800BB77C 1000B08F */  lw         $s0, 0x10($sp)
    /* 52F80 800BB780 0800E003 */  jr         $ra
    /* 52F84 800BB784 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_800BB68C
