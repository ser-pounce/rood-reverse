nonmatching func_800B770C, 0xD0

glabel func_800B770C
    /* 4EF0C 800B770C C0FFBD27 */  addiu      $sp, $sp, -0x40
    /* 4EF10 800B7710 3400B3AF */  sw         $s3, 0x34($sp)
    /* 4EF14 800B7714 21988000 */  addu       $s3, $a0, $zero
    /* 4EF18 800B7718 01006426 */  addiu      $a0, $s3, 0x1
    /* 4EF1C 800B771C 3800BFAF */  sw         $ra, 0x38($sp)
    /* 4EF20 800B7720 3000B2AF */  sw         $s2, 0x30($sp)
    /* 4EF24 800B7724 2C00B1AF */  sw         $s1, 0x2C($sp)
    /* 4EF28 800B7728 80FF020C */  jal        vs_battle_getShort
    /* 4EF2C 800B772C 2800B0AF */   sw        $s0, 0x28($sp)
    /* 4EF30 800B7730 FFFF4430 */  andi       $a0, $v0, 0xFFFF
    /* 4EF34 800B7734 A3ED020C */  jal        func_800BB68C
    /* 4EF38 800B7738 1000A527 */   addiu     $a1, $sp, 0x10
  .L800B773C:
    /* 4EF3C 800B773C E2ED020C */  jal        func_800BB788
    /* 4EF40 800B7740 1000A427 */   addiu     $a0, $sp, 0x10
    /* 4EF44 800B7744 FFFF5030 */  andi       $s0, $v0, 0xFFFF
    /* 4EF48 800B7748 01000224 */  addiu      $v0, $zero, 0x1
    /* 4EF4C 800B774C 1C000212 */  beq        $s0, $v0, .L800B77C0
    /* 4EF50 800B7750 21100000 */   addu      $v0, $zero, $zero
    /* 4EF54 800B7754 F882020C */  jal        func_800A0BE0
    /* 4EF58 800B7758 21200002 */   addu      $a0, $s0, $zero
    /* 4EF5C 800B775C 00085230 */  andi       $s2, $v0, 0x800
    /* 4EF60 800B7760 04006592 */  lbu        $a1, 0x4($s3)
    /* 4EF64 800B7764 00105130 */  andi       $s1, $v0, 0x1000
    /* 4EF68 800B7768 0200A230 */  andi       $v0, $a1, 0x2
    /* 4EF6C 800B776C 04004014 */  bnez       $v0, .L800B7780
    /* 4EF70 800B7770 0800A230 */   andi      $v0, $a1, 0x8
    /* 4EF74 800B7774 0100A230 */  andi       $v0, $a1, 0x1
    /* 4EF78 800B7778 C0920200 */  sll        $s2, $v0, 11
    /* 4EF7C 800B777C 0800A230 */  andi       $v0, $a1, 0x8
  .L800B7780:
    /* 4EF80 800B7780 03004014 */  bnez       $v0, .L800B7790
    /* 4EF84 800B7784 21200002 */   addu      $a0, $s0, $zero
    /* 4EF88 800B7788 80120500 */  sll        $v0, $a1, 10
    /* 4EF8C 800B778C 00105130 */  andi       $s1, $v0, 0x1000
  .L800B7790:
    /* 4EF90 800B7790 42290500 */  srl        $a1, $a1, 5
    /* 4EF94 800B7794 6AF4010C */  jal        func_8007D1A8
    /* 4EF98 800B7798 0100A530 */   andi      $a1, $a1, 0x1
    /* 4EF9C 800B779C 21200002 */  addu       $a0, $s0, $zero
    /* 4EFA0 800B77A0 03006292 */  lbu        $v0, 0x3($s3)
    /* 4EFA4 800B77A4 25285102 */  or         $a1, $s2, $s1
    /* 4EFA8 800B77A8 1F82020C */  jal        func_800A087C
    /* 4EFAC 800B77AC 2528A200 */   or        $a1, $a1, $v0
    /* 4EFB0 800B77B0 2376020C */  jal        func_8009D88C
    /* 4EFB4 800B77B4 21200002 */   addu      $a0, $s0, $zero
    /* 4EFB8 800B77B8 CFDD0208 */  j          .L800B773C
    /* 4EFBC 800B77BC 00000000 */   nop
  .L800B77C0:
    /* 4EFC0 800B77C0 3800BF8F */  lw         $ra, 0x38($sp)
    /* 4EFC4 800B77C4 3400B38F */  lw         $s3, 0x34($sp)
    /* 4EFC8 800B77C8 3000B28F */  lw         $s2, 0x30($sp)
    /* 4EFCC 800B77CC 2C00B18F */  lw         $s1, 0x2C($sp)
    /* 4EFD0 800B77D0 2800B08F */  lw         $s0, 0x28($sp)
    /* 4EFD4 800B77D4 0800E003 */  jr         $ra
    /* 4EFD8 800B77D8 4000BD27 */   addiu     $sp, $sp, 0x40
endlabel func_800B770C
