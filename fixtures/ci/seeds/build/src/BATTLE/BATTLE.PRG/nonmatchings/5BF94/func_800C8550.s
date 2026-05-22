nonmatching func_800C8550, 0x15C

glabel func_800C8550
    /* 5FD50 800C8550 D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 5FD54 800C8554 0F80033C */  lui        $v1, %hi(D_800EB9BC)
    /* 5FD58 800C8558 C0110400 */  sll        $v0, $a0, 7
    /* 5FD5C 800C855C 23104400 */  subu       $v0, $v0, $a0
    /* 5FD60 800C8560 BCB9638C */  lw         $v1, %lo(D_800EB9BC)($v1)
    /* 5FD64 800C8564 C0100200 */  sll        $v0, $v0, 3
    /* 5FD68 800C8568 2800BFAF */  sw         $ra, 0x28($sp)
    /* 5FD6C 800C856C 2400B5AF */  sw         $s5, 0x24($sp)
    /* 5FD70 800C8570 2000B4AF */  sw         $s4, 0x20($sp)
    /* 5FD74 800C8574 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 5FD78 800C8578 1800B2AF */  sw         $s2, 0x18($sp)
    /* 5FD7C 800C857C 1400B1AF */  sw         $s1, 0x14($sp)
    /* 5FD80 800C8580 1000B0AF */  sw         $s0, 0x10($sp)
    /* 5FD84 800C8584 21A86200 */  addu       $s5, $v1, $v0
    /* 5FD88 800C8588 0000A28E */  lw         $v0, 0x0($s5)
    /* 5FD8C 800C858C 02000324 */  addiu      $v1, $zero, 0x2
    /* 5FD90 800C8590 01004234 */  ori        $v0, $v0, 0x1
    /* 5FD94 800C8594 0000A2AE */  sw         $v0, 0x0($s5)
    /* 5FD98 800C8598 C2100200 */  srl        $v0, $v0, 3
    /* 5FD9C 800C859C 07004230 */  andi       $v0, $v0, 0x7
    /* 5FDA0 800C85A0 2A004314 */  bne        $v0, $v1, .L800C864C
    /* 5FDA4 800C85A4 00000000 */   nop
    /* 5FDA8 800C85A8 2333030C */  jal        vs_battle_keystreamBits
    /* 5FDAC 800C85AC 09000424 */   addiu     $a0, $zero, 0x9
    /* 5FDB0 800C85B0 21804000 */  addu       $s0, $v0, $zero
    /* 5FDB4 800C85B4 2333030C */  jal        vs_battle_keystreamBits
    /* 5FDB8 800C85B8 0A000424 */   addiu     $a0, $zero, 0xA
    /* 5FDBC 800C85BC 21904000 */  addu       $s2, $v0, $zero
    /* 5FDC0 800C85C0 21A00000 */  addu       $s4, $zero, $zero
    /* 5FDC4 800C85C4 1800A226 */  addiu      $v0, $s5, 0x18
    /* 5FDC8 800C85C8 21984000 */  addu       $s3, $v0, $zero
  .L800C85CC:
    /* 5FDCC 800C85CC CA03010C */  jal        rsin
    /* 5FDD0 800C85D0 21200002 */   addu      $a0, $s0, $zero
    /* 5FDD4 800C85D4 C3100200 */  sra        $v0, $v0, 3
    /* 5FDD8 800C85D8 40014224 */  addiu      $v0, $v0, 0x140
    /* 5FDDC 800C85DC 000062A6 */  sh         $v0, 0x0($s3)
    /* 5FDE0 800C85E0 2333030C */  jal        vs_battle_keystreamBits
    /* 5FDE4 800C85E4 08000424 */   addiu     $a0, $zero, 0x8
    /* 5FDE8 800C85E8 0A000424 */  addiu      $a0, $zero, 0xA
    /* 5FDEC 800C85EC 2333030C */  jal        vs_battle_keystreamBits
    /* 5FDF0 800C85F0 C0FF5124 */   addiu     $s1, $v0, -0x40
    /* 5FDF4 800C85F4 21184000 */  addu       $v1, $v0, $zero
    /* 5FDF8 800C85F8 2A105002 */  slt        $v0, $s2, $s0
    /* 5FDFC 800C85FC 04004010 */  beqz       $v0, .L800C8610
    /* 5FE00 800C8600 00000000 */   nop
    /* 5FE04 800C8604 23801102 */  subu       $s0, $s0, $s1
    /* 5FE08 800C8608 86210308 */  j          .L800C8618
    /* 5FE0C 800C860C 2A105002 */   slt       $v0, $s2, $s0
  .L800C8610:
    /* 5FE10 800C8610 21801102 */  addu       $s0, $s0, $s1
    /* 5FE14 800C8614 2A101202 */  slt        $v0, $s0, $s2
  .L800C8618:
    /* 5FE18 800C8618 02004014 */  bnez       $v0, .L800C8624
    /* 5FE1C 800C861C 00000000 */   nop
    /* 5FE20 800C8620 21906000 */  addu       $s2, $v1, $zero
  .L800C8624:
    /* 5FE24 800C8624 05000106 */  bgez       $s0, .L800C863C
    /* 5FE28 800C8628 00000000 */   nop
    /* 5FE2C 800C862C 80001024 */  addiu      $s0, $zero, 0x80
    /* 5FE30 800C8630 2333030C */  jal        vs_battle_keystreamBits
    /* 5FE34 800C8634 0A000424 */   addiu     $a0, $zero, 0xA
    /* 5FE38 800C8638 21904000 */  addu       $s2, $v0, $zero
  .L800C863C:
    /* 5FE3C 800C863C 01009426 */  addiu      $s4, $s4, 0x1
    /* 5FE40 800C8640 F000822A */  slti       $v0, $s4, 0xF0
    /* 5FE44 800C8644 E1FF4014 */  bnez       $v0, .L800C85CC
    /* 5FE48 800C8648 02007326 */   addiu     $s3, $s3, 0x2
  .L800C864C:
    /* 5FE4C 800C864C 0000A28E */  lw         $v0, 0x0($s5)
    /* 5FE50 800C8650 03000324 */  addiu      $v1, $zero, 0x3
    /* 5FE54 800C8654 C2100200 */  srl        $v0, $v0, 3
    /* 5FE58 800C8658 07004230 */  andi       $v0, $v0, 0x7
    /* 5FE5C 800C865C 0A004314 */  bne        $v0, $v1, .L800C8688
    /* 5FE60 800C8660 0F80023C */   lui       $v0, %hi(D_800EB9BC)
    /* 5FE64 800C8664 01000524 */  addiu      $a1, $zero, 0x1
    /* 5FE68 800C8668 BCB9428C */  lw         $v0, %lo(D_800EB9BC)($v0)
    /* 5FE6C 800C866C 06000624 */  addiu      $a2, $zero, 0x6
    /* 5FE70 800C8670 0000448C */  lw         $a0, 0x0($v0)
    /* 5FE74 800C8674 02004290 */  lbu        $v0, 0x2($v0)
    /* 5FE78 800C8678 42220400 */  srl        $a0, $a0, 9
    /* 5FE7C 800C867C 07008430 */  andi       $a0, $a0, 0x7
    /* 5FE80 800C8680 FCF7010C */  jal        func_8007DFF0
    /* 5FE84 800C8684 21204400 */   addu      $a0, $v0, $a0
  .L800C8688:
    /* 5FE88 800C8688 2800BF8F */  lw         $ra, 0x28($sp)
    /* 5FE8C 800C868C 2400B58F */  lw         $s5, 0x24($sp)
    /* 5FE90 800C8690 2000B48F */  lw         $s4, 0x20($sp)
    /* 5FE94 800C8694 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 5FE98 800C8698 1800B28F */  lw         $s2, 0x18($sp)
    /* 5FE9C 800C869C 1400B18F */  lw         $s1, 0x14($sp)
    /* 5FEA0 800C86A0 1000B08F */  lw         $s0, 0x10($sp)
    /* 5FEA4 800C86A4 0800E003 */  jr         $ra
    /* 5FEA8 800C86A8 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel func_800C8550
