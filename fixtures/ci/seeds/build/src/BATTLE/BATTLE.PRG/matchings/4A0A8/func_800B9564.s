nonmatching func_800B9564, 0xA4

glabel func_800B9564
    /* 50D64 800B9564 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 50D68 800B9568 1800B2AF */  sw         $s2, 0x18($sp)
    /* 50D6C 800B956C 21908000 */  addu       $s2, $a0, $zero
    /* 50D70 800B9570 02004426 */  addiu      $a0, $s2, 0x2
    /* 50D74 800B9574 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 50D78 800B9578 1400B1AF */  sw         $s1, 0x14($sp)
    /* 50D7C 800B957C 80FF020C */  jal        vs_battle_getShort
    /* 50D80 800B9580 1000B0AF */   sw        $s0, 0x10($sp)
    /* 50D84 800B9584 01004492 */  lbu        $a0, 0x1($s2)
    /* 50D88 800B9588 21804000 */  addu       $s0, $v0, $zero
    /* 50D8C 800B958C 7D33030C */  jal        vs_battle_getTextBox
    /* 50D90 800B9590 0F008430 */   andi      $a0, $a0, 0xF
    /* 50D94 800B9594 21884000 */  addu       $s1, $v0, $zero
    /* 50D98 800B9598 FFFF0432 */  andi       $a0, $s0, 0xFFFF
    /* 50D9C 800B959C 0020822C */  sltiu      $v0, $a0, 0x2000
    /* 50DA0 800B95A0 05004010 */  beqz       $v0, .L800B95B8
    /* 50DA4 800B95A4 00000000 */   nop
    /* 50DA8 800B95A8 94FF020C */  jal        func_800BFE50
    /* 50DAC 800B95AC 00000000 */   nop
    /* 50DB0 800B95B0 6FE50208 */  j          .L800B95BC
    /* 50DB4 800B95B4 21204000 */   addu      $a0, $v0, $zero
  .L800B95B8:
    /* 50DB8 800B95B8 20000424 */  addiu      $a0, $zero, 0x20
  .L800B95BC:
    /* 50DBC 800B95BC FFC0023C */  lui        $v0, (0xC0FFFFFF >> 16)
    /* 50DC0 800B95C0 0000238E */  lw         $v1, 0x0($s1)
    /* 50DC4 800B95C4 FFFF4234 */  ori        $v0, $v0, (0xC0FFFFFF & 0xFFFF)
    /* 50DC8 800B95C8 24186200 */  and        $v1, $v1, $v0
    /* 50DCC 800B95CC 3F008230 */  andi       $v0, $a0, 0x3F
    /* 50DD0 800B95D0 00160200 */  sll        $v0, $v0, 24
    /* 50DD4 800B95D4 25186200 */  or         $v1, $v1, $v0
    /* 50DD8 800B95D8 000023AE */  sw         $v1, 0x0($s1)
    /* 50DDC 800B95DC 01004392 */  lbu        $v1, 0x1($s2)
    /* 50DE0 800B95E0 00000000 */  nop
    /* 50DE4 800B95E4 02190300 */  srl        $v1, $v1, 4
    /* 50DE8 800B95E8 2E0023A6 */  sh         $v1, 0x2E($s1)
    /* 50DEC 800B95EC 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 50DF0 800B95F0 1800B28F */  lw         $s2, 0x18($sp)
    /* 50DF4 800B95F4 1400B18F */  lw         $s1, 0x14($sp)
    /* 50DF8 800B95F8 1000B08F */  lw         $s0, 0x10($sp)
    /* 50DFC 800B95FC 21100000 */  addu       $v0, $zero, $zero
    /* 50E00 800B9600 0800E003 */  jr         $ra
    /* 50E04 800B9604 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_800B9564
