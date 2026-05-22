nonmatching func_80109D64, 0x154

glabel func_80109D64
    /* 7564 80109D64 0680023C */  lui        $v0, %hi(vs_main_gametime)
    /* 7568 80109D68 7410428C */  lw         $v0, %lo(vs_main_gametime)($v0)
    /* 756C 80109D6C D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 7570 80109D70 1000A2AF */  sw         $v0, 0x10($sp)
    /* 7574 80109D74 1300A293 */  lbu        $v0, 0x13($sp)
    /* 7578 80109D78 2800BFAF */  sw         $ra, 0x28($sp)
    /* 757C 80109D7C 2400B3AF */  sw         $s3, 0x24($sp)
    /* 7580 80109D80 2000B2AF */  sw         $s2, 0x20($sp)
    /* 7584 80109D84 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 7588 80109D88 6400422C */  sltiu      $v0, $v0, 0x64
    /* 758C 80109D8C 0D004014 */  bnez       $v0, .L80109DC4
    /* 7590 80109D90 1800B0AF */   sw        $s0, 0x18($sp)
    /* 7594 80109D94 1080043C */  lui        $a0, %hi(D_80102A18)
    /* 7598 80109D98 182A8424 */  addiu      $a0, $a0, %lo(D_80102A18)
    /* 759C 80109D9C C800053C */  lui        $a1, (0xC800D8 >> 16)
    /* 75A0 80109DA0 801F023C */  lui        $v0, (0x1F800004 >> 16)
    /* 75A4 80109DA4 0400468C */  lw         $a2, (0x1F800004 & 0xFFFF)($v0)
    /* 75A8 80109DA8 D800A534 */  ori        $a1, $a1, (0xC800D8 & 0xFFFF)
    /* 75AC 80109DAC 1000A0AF */  sw         $zero, 0x10($sp)
    /* 75B0 80109DB0 1300A0A3 */  sb         $zero, 0x13($sp)
    /* 75B4 80109DB4 0A1A030C */  jal        vs_battle_renderTextRaw
    /* 75B8 80109DB8 ECFFC624 */   addiu     $a2, $a2, -0x14
    /* 75BC 80109DBC 81270408 */  j          .L80109E04
    /* 75C0 80109DC0 21880000 */   addu      $s1, $zero, $zero
  .L80109DC4:
    /* 75C4 80109DC4 2333030C */  jal        vs_battle_keystreamBits
    /* 75C8 80109DC8 0F000424 */   addiu     $a0, $zero, 0xF
    /* 75CC 80109DCC 1000A393 */  lbu        $v1, 0x10($sp)
    /* 75D0 80109DD0 00000000 */  nop
    /* 75D4 80109DD4 801B0300 */  sll        $v1, $v1, 14
    /* 75D8 80109DD8 21186200 */  addu       $v1, $v1, $v0
    /* 75DC 80109DDC 80100300 */  sll        $v0, $v1, 2
    /* 75E0 80109DE0 21104300 */  addu       $v0, $v0, $v1
    /* 75E4 80109DE4 82130200 */  srl        $v0, $v0, 14
    /* 75E8 80109DE8 AAAA033C */  lui        $v1, (0xAAAAAAAB >> 16)
    /* 75EC 80109DEC ABAA6334 */  ori        $v1, $v1, (0xAAAAAAAB & 0xFFFF)
    /* 75F0 80109DF0 19004300 */  multu      $v0, $v1
    /* 75F4 80109DF4 10380000 */  mfhi       $a3
    /* 75F8 80109DF8 42100700 */  srl        $v0, $a3, 1
    /* 75FC 80109DFC 1000A2A3 */  sb         $v0, 0x10($sp)
    /* 7600 80109E00 21880000 */  addu       $s1, $zero, $zero
  .L80109E04:
    /* 7604 80109E04 1000B327 */  addiu      $s3, $sp, 0x10
    /* 7608 80109E08 1180123C */  lui        $s2, %hi(_playTime)
    /* 760C 80109E0C 21802002 */  addu       $s0, $s1, $zero
  .L80109E10:
    /* 7610 80109E10 21107102 */  addu       $v0, $s3, $s1
    /* 7614 80109E14 00004490 */  lbu        $a0, 0x0($v0)
    /* 7618 80109E18 1533030C */  jal        vs_battle_toBCD
    /* 761C 80109E1C 01003126 */   addiu     $s1, $s1, 0x1
    /* 7620 80109E20 03190200 */  sra        $v1, $v0, 4
    /* 7624 80109E24 30006324 */  addiu      $v1, $v1, 0x30
    /* 7628 80109E28 3CAA448E */  lw         $a0, %lo(_playTime)($s2)
    /* 762C 80109E2C 0F004230 */  andi       $v0, $v0, 0xF
    /* 7630 80109E30 09008424 */  addiu      $a0, $a0, 0x9
    /* 7634 80109E34 23209000 */  subu       $a0, $a0, $s0
    /* 7638 80109E38 000083A0 */  sb         $v1, 0x0($a0)
    /* 763C 80109E3C 3CAA438E */  lw         $v1, %lo(_playTime)($s2)
    /* 7640 80109E40 30004224 */  addiu      $v0, $v0, 0x30
    /* 7644 80109E44 0A006324 */  addiu      $v1, $v1, 0xA
    /* 7648 80109E48 23187000 */  subu       $v1, $v1, $s0
    /* 764C 80109E4C 000062A0 */  sb         $v0, 0x0($v1)
    /* 7650 80109E50 0400222A */  slti       $v0, $s1, 0x4
    /* 7654 80109E54 EEFF4014 */  bnez       $v0, .L80109E10
    /* 7658 80109E58 03001026 */   addiu     $s0, $s0, 0x3
    /* 765C 80109E5C C800053C */  lui        $a1, (0xC800E0 >> 16)
    /* 7660 80109E60 E000A534 */  ori        $a1, $a1, (0xC800E0 & 0xFFFF)
    /* 7664 80109E64 1180023C */  lui        $v0, %hi(_playTime)
    /* 7668 80109E68 801F103C */  lui        $s0, %hi(D_1F800000)
    /* 766C 80109E6C 00001026 */  addiu      $s0, $s0, %lo(D_1F800000)
    /* 7670 80109E70 0400068E */  lw         $a2, 0x4($s0)
    /* 7674 80109E74 3CAA448C */  lw         $a0, %lo(_playTime)($v0)
    /* 7678 80109E78 0A1A030C */  jal        vs_battle_renderTextRaw
    /* 767C 80109E7C ECFFC624 */   addiu     $a2, $a2, -0x14
    /* 7680 80109E80 1080043C */  lui        $a0, %hi(D_80102A1C)
    /* 7684 80109E84 1C2A8424 */  addiu      $a0, $a0, %lo(D_80102A1C)
    /* 7688 80109E88 BC00053C */  lui        $a1, (0xBC00E0 >> 16)
    /* 768C 80109E8C 0400068E */  lw         $a2, 0x4($s0)
    /* 7690 80109E90 E000A534 */  ori        $a1, $a1, (0xBC00E0 & 0xFFFF)
    /* 7694 80109E94 0A1A030C */  jal        vs_battle_renderTextRaw
    /* 7698 80109E98 ECFFC624 */   addiu     $a2, $a2, -0x14
    /* 769C 80109E9C 2800BF8F */  lw         $ra, 0x28($sp)
    /* 76A0 80109EA0 2400B38F */  lw         $s3, 0x24($sp)
    /* 76A4 80109EA4 2000B28F */  lw         $s2, 0x20($sp)
    /* 76A8 80109EA8 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 76AC 80109EAC 1800B08F */  lw         $s0, 0x18($sp)
    /* 76B0 80109EB0 0800E003 */  jr         $ra
    /* 76B4 80109EB4 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel func_80109D64
