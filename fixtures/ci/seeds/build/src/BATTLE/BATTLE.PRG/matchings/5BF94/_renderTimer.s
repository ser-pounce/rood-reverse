nonmatching _renderTimer, 0xE8

glabel _renderTimer
    /* 62D6C 800CB56C D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 62D70 800CB570 2800BFAF */  sw         $ra, 0x28($sp)
    /* 62D74 800CB574 2400B3AF */  sw         $s3, 0x24($sp)
    /* 62D78 800CB578 2000B2AF */  sw         $s2, 0x20($sp)
    /* 62D7C 800CB57C 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 62D80 800CB580 1800B0AF */  sw         $s0, 0x18($sp)
    /* 62D84 800CB584 0000828C */  lw         $v0, 0x0($a0)
    /* 62D88 800CB588 00000000 */  nop
    /* 62D8C 800CB58C 1000A2AF */  sw         $v0, 0x10($sp)
    /* 62D90 800CB590 0680023C */  lui        $v0, %hi(vs_main_stateFlags + 0xA0)
    /* 62D94 800CB594 38164290 */  lbu        $v0, %lo(vs_main_stateFlags + 0xA0)($v0)
    /* 62D98 800CB598 1300A393 */  lbu        $v1, 0x13($sp)
    /* 62D9C 800CB59C 00000000 */  nop
    /* 62DA0 800CB5A0 06006010 */  beqz       $v1, .L800CB5BC
    /* 62DA4 800CB5A4 1000A2A3 */   sb        $v0, 0x10($sp)
    /* 62DA8 800CB5A8 3B000224 */  addiu      $v0, $zero, 0x3B
    /* 62DAC 800CB5AC 1200A2A3 */  sb         $v0, 0x12($sp)
    /* 62DB0 800CB5B0 1100A2A3 */  sb         $v0, 0x11($sp)
    /* 62DB4 800CB5B4 63000224 */  addiu      $v0, $zero, 0x63
    /* 62DB8 800CB5B8 1000A2A3 */  sb         $v0, 0x10($sp)
  .L800CB5BC:
    /* 62DBC 800CB5BC 21880000 */  addu       $s1, $zero, $zero
    /* 62DC0 800CB5C0 1000B327 */  addiu      $s3, $sp, 0x10
    /* 62DC4 800CB5C4 0F80123C */  lui        $s2, %hi(D_800EC258)
    /* 62DC8 800CB5C8 21802002 */  addu       $s0, $s1, $zero
  .L800CB5CC:
    /* 62DCC 800CB5CC 21107102 */  addu       $v0, $s3, $s1
    /* 62DD0 800CB5D0 00004490 */  lbu        $a0, 0x0($v0)
    /* 62DD4 800CB5D4 1533030C */  jal        vs_battle_toBCD
    /* 62DD8 800CB5D8 01003126 */   addiu     $s1, $s1, 0x1
    /* 62DDC 800CB5DC 03190200 */  sra        $v1, $v0, 4
    /* 62DE0 800CB5E0 30006324 */  addiu      $v1, $v1, 0x30
    /* 62DE4 800CB5E4 58C2448E */  lw         $a0, %lo(D_800EC258)($s2)
    /* 62DE8 800CB5E8 0F004230 */  andi       $v0, $v0, 0xF
    /* 62DEC 800CB5EC 06008424 */  addiu      $a0, $a0, 0x6
    /* 62DF0 800CB5F0 23209000 */  subu       $a0, $a0, $s0
    /* 62DF4 800CB5F4 000083A0 */  sb         $v1, 0x0($a0)
    /* 62DF8 800CB5F8 58C2438E */  lw         $v1, %lo(D_800EC258)($s2)
    /* 62DFC 800CB5FC 30004224 */  addiu      $v0, $v0, 0x30
    /* 62E00 800CB600 07006324 */  addiu      $v1, $v1, 0x7
    /* 62E04 800CB604 23187000 */  subu       $v1, $v1, $s0
    /* 62E08 800CB608 000062A0 */  sb         $v0, 0x0($v1)
    /* 62E0C 800CB60C 0300222A */  slti       $v0, $s1, 0x3
    /* 62E10 800CB610 EEFF4014 */  bnez       $v0, .L800CB5CC
    /* 62E14 800CB614 03001026 */   addiu     $s0, $s0, 0x3
    /* 62E18 800CB618 C800053C */  lui        $a1, (0xC80080 >> 16)
    /* 62E1C 800CB61C 8000A534 */  ori        $a1, $a1, (0xC80080 & 0xFFFF)
    /* 62E20 800CB620 0F80023C */  lui        $v0, %hi(D_800EC258)
    /* 62E24 800CB624 801F033C */  lui        $v1, (0x1F800004 >> 16)
    /* 62E28 800CB628 0400668C */  lw         $a2, (0x1F800004 & 0xFFFF)($v1)
    /* 62E2C 800CB62C 58C2448C */  lw         $a0, %lo(D_800EC258)($v0)
    /* 62E30 800CB630 0A1A030C */  jal        vs_battle_renderTextRaw
    /* 62E34 800CB634 FCFFC624 */   addiu     $a2, $a2, -0x4
    /* 62E38 800CB638 2800BF8F */  lw         $ra, 0x28($sp)
    /* 62E3C 800CB63C 2400B38F */  lw         $s3, 0x24($sp)
    /* 62E40 800CB640 2000B28F */  lw         $s2, 0x20($sp)
    /* 62E44 800CB644 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 62E48 800CB648 1800B08F */  lw         $s0, 0x18($sp)
    /* 62E4C 800CB64C 0800E003 */  jr         $ra
    /* 62E50 800CB650 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel _renderTimer
