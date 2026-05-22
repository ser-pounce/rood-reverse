nonmatching func_800C86AC, 0xCC

glabel func_800C86AC
    /* 5FEAC 800C86AC D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 5FEB0 800C86B0 1800B2AF */  sw         $s2, 0x18($sp)
    /* 5FEB4 800C86B4 0F80123C */  lui        $s2, %hi(D_800EB9BC)
    /* 5FEB8 800C86B8 1000B0AF */  sw         $s0, 0x10($sp)
    /* 5FEBC 800C86BC BCB9508E */  lw         $s0, %lo(D_800EB9BC)($s2)
    /* 5FEC0 800C86C0 2000BFAF */  sw         $ra, 0x20($sp)
    /* 5FEC4 800C86C4 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 5FEC8 800C86C8 24000012 */  beqz       $s0, .L800C875C
    /* 5FECC 800C86CC 1400B1AF */   sw        $s1, 0x14($sp)
    /* 5FED0 800C86D0 0000058E */  lw         $a1, 0x0($s0)
    /* 5FED4 800C86D4 03000324 */  addiu      $v1, $zero, 0x3
    /* 5FED8 800C86D8 82110500 */  srl        $v0, $a1, 6
    /* 5FEDC 800C86DC 07004230 */  andi       $v0, $v0, 0x7
    /* 5FEE0 800C86E0 1E004314 */  bne        $v0, $v1, .L800C875C
    /* 5FEE4 800C86E4 422A0500 */   srl       $a1, $a1, 9
    /* 5FEE8 800C86E8 02000492 */  lbu        $a0, 0x2($s0)
    /* 5FEEC 800C86EC 0700A530 */  andi       $a1, $a1, 0x7
    /* 5FEF0 800C86F0 06000624 */  addiu      $a2, $zero, 0x6
    /* 5FEF4 800C86F4 21880000 */  addu       $s1, $zero, $zero
    /* 5FEF8 800C86F8 2AF8010C */  jal        func_8007E0A8
    /* 5FEFC 800C86FC 21986000 */   addu      $s3, $v1, $zero
  .L800C8700:
    /* 5FF00 800C8700 0000028E */  lw         $v0, 0x0($s0)
    /* 5FF04 800C8704 00000000 */  nop
    /* 5FF08 800C8708 C2100200 */  srl        $v0, $v0, 3
    /* 5FF0C 800C870C 07004230 */  andi       $v0, $v0, 0x7
    /* 5FF10 800C8710 09005314 */  bne        $v0, $s3, .L800C8738
    /* 5FF14 800C8714 01000524 */   addiu     $a1, $zero, 0x1
    /* 5FF18 800C8718 BCB9428E */  lw         $v0, %lo(D_800EB9BC)($s2)
    /* 5FF1C 800C871C 06000624 */  addiu      $a2, $zero, 0x6
    /* 5FF20 800C8720 0000448C */  lw         $a0, 0x0($v0)
    /* 5FF24 800C8724 02004290 */  lbu        $v0, 0x2($v0)
    /* 5FF28 800C8728 42220400 */  srl        $a0, $a0, 9
    /* 5FF2C 800C872C 07008430 */  andi       $a0, $a0, 0x7
    /* 5FF30 800C8730 2AF8010C */  jal        func_8007E0A8
    /* 5FF34 800C8734 21204400 */   addu      $a0, $v0, $a0
  .L800C8738:
    /* 5FF38 800C8738 01003126 */  addiu      $s1, $s1, 0x1
    /* 5FF3C 800C873C 0300222A */  slti       $v0, $s1, 0x3
    /* 5FF40 800C8740 EFFF4014 */  bnez       $v0, .L800C8700
    /* 5FF44 800C8744 F8031026 */   addiu     $s0, $s0, 0x3F8
    /* 5FF48 800C8748 0F80103C */  lui        $s0, %hi(D_800EB9BC)
    /* 5FF4C 800C874C BCB9048E */  lw         $a0, %lo(D_800EB9BC)($s0)
    /* 5FF50 800C8750 180F010C */  jal        vs_main_freeHeapR
    /* 5FF54 800C8754 00000000 */   nop
    /* 5FF58 800C8758 BCB900AE */  sw         $zero, %lo(D_800EB9BC)($s0)
  .L800C875C:
    /* 5FF5C 800C875C 2000BF8F */  lw         $ra, 0x20($sp)
    /* 5FF60 800C8760 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 5FF64 800C8764 1800B28F */  lw         $s2, 0x18($sp)
    /* 5FF68 800C8768 1400B18F */  lw         $s1, 0x14($sp)
    /* 5FF6C 800C876C 1000B08F */  lw         $s0, 0x10($sp)
    /* 5FF70 800C8770 0800E003 */  jr         $ra
    /* 5FF74 800C8774 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_800C86AC
