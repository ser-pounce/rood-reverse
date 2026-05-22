nonmatching _getIntelligenceDifference, 0x254

glabel _getIntelligenceDifference
    /* 164A8 8007ECA8 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 164AC 8007ECAC 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 164B0 8007ECB0 21988000 */  addu       $s3, $a0, $zero
    /* 164B4 8007ECB4 2000B4AF */  sw         $s4, 0x20($sp)
    /* 164B8 8007ECB8 21A0E000 */  addu       $s4, $a3, $zero
    /* 164BC 8007ECBC 21480000 */  addu       $t1, $zero, $zero
    /* 164C0 8007ECC0 0F80043C */  lui        $a0, %hi(vs_battle_actors)
    /* 164C4 8007ECC4 3800AB8F */  lw         $t3, 0x38($sp)
    /* 164C8 8007ECC8 28198424 */  addiu      $a0, $a0, %lo(vs_battle_actors)
    /* 164CC 8007ECCC 2400BFAF */  sw         $ra, 0x24($sp)
    /* 164D0 8007ECD0 1800B2AF */  sw         $s2, 0x18($sp)
    /* 164D4 8007ECD4 1400B1AF */  sw         $s1, 0x14($sp)
    /* 164D8 8007ECD8 1000B0AF */  sw         $s0, 0x10($sp)
    /* 164DC 8007ECDC 0100CA80 */  lb         $t2, 0x1($a2)
    /* 164E0 8007ECE0 0000A390 */  lbu        $v1, 0x0($a1)
    /* 164E4 8007ECE4 0000C290 */  lbu        $v0, 0x0($a2)
    /* 164E8 8007ECE8 80180300 */  sll        $v1, $v1, 2
    /* 164EC 8007ECEC 21186400 */  addu       $v1, $v1, $a0
    /* 164F0 8007ECF0 80100200 */  sll        $v0, $v0, 2
    /* 164F4 8007ECF4 21104400 */  addu       $v0, $v0, $a0
    /* 164F8 8007ECF8 0000428C */  lw         $v0, 0x0($v0)
    /* 164FC 8007ECFC 0000638C */  lw         $v1, 0x0($v1)
    /* 16500 8007ED00 3C00518C */  lw         $s1, 0x3C($v0)
    /* 16504 8007ED04 3C00728C */  lw         $s2, 0x3C($v1)
    /* 16508 8007ED08 21382002 */  addu       $a3, $s1, $zero
    /* 1650C 8007ED0C 21304002 */  addu       $a2, $s2, $zero
    /* 16510 8007ED10 26004596 */  lhu        $a1, 0x26($s2)
    /* 16514 8007ED14 6A034386 */  lh         $v1, 0x36A($s2)
    /* 16518 8007ED18 26002496 */  lhu        $a0, 0x26($s1)
    /* 1651C 8007ED1C 6A032286 */  lh         $v0, 0x36A($s1)
    /* 16520 8007ED20 2140A300 */  addu       $t0, $a1, $v1
    /* 16524 8007ED24 21288200 */  addu       $a1, $a0, $v0
  .L8007ED28:
    /* 16528 8007ED28 F003E384 */  lh         $v1, 0x3F0($a3)
    /* 1652C 8007ED2C DC00E724 */  addiu      $a3, $a3, 0xDC
    /* 16530 8007ED30 F003C284 */  lh         $v0, 0x3F0($a2)
    /* 16534 8007ED34 DC00C624 */  addiu      $a2, $a2, 0xDC
    /* 16538 8007ED38 01002925 */  addiu      $t1, $t1, 0x1
    /* 1653C 8007ED3C 21400201 */  addu       $t0, $t0, $v0
    /* 16540 8007ED40 06002229 */  slti       $v0, $t1, 0x6
    /* 16544 8007ED44 F8FF4014 */  bnez       $v0, .L8007ED28
    /* 16548 8007ED48 2128A300 */   addu      $a1, $a1, $v1
    /* 1654C 8007ED4C 0F80033C */  lui        $v1, %hi(vs_battle_actors)
    /* 16550 8007ED50 57094292 */  lbu        $v0, 0x957($s2)
    /* 16554 8007ED54 28196424 */  addiu      $a0, $v1, %lo(vs_battle_actors)
    /* 16558 8007ED58 80100200 */  sll        $v0, $v0, 2
    /* 1655C 8007ED5C 21104400 */  addu       $v0, $v0, $a0
    /* 16560 8007ED60 0000428C */  lw         $v0, 0x0($v0)
    /* 16564 8007ED64 00000000 */  nop
    /* 16568 8007ED68 2000428C */  lw         $v0, 0x20($v0)
    /* 1656C 8007ED6C 00000000 */  nop
    /* 16570 8007ED70 01004230 */  andi       $v0, $v0, 0x1
    /* 16574 8007ED74 06004010 */  beqz       $v0, .L8007ED90
    /* 16578 8007ED78 00000000 */   nop
    /* 1657C 8007ED7C 58014286 */  lh         $v0, 0x158($s2)
    /* 16580 8007ED80 BC024386 */  lh         $v1, 0x2BC($s2)
    /* 16584 8007ED84 00000000 */  nop
    /* 16588 8007ED88 21104300 */  addu       $v0, $v0, $v1
    /* 1658C 8007ED8C 21400201 */  addu       $t0, $t0, $v0
  .L8007ED90:
    /* 16590 8007ED90 57092292 */  lbu        $v0, 0x957($s1)
    /* 16594 8007ED94 00000000 */  nop
    /* 16598 8007ED98 80100200 */  sll        $v0, $v0, 2
    /* 1659C 8007ED9C 21104400 */  addu       $v0, $v0, $a0
    /* 165A0 8007EDA0 0000428C */  lw         $v0, 0x0($v0)
    /* 165A4 8007EDA4 00000000 */  nop
    /* 165A8 8007EDA8 2000428C */  lw         $v0, 0x20($v0)
    /* 165AC 8007EDAC 00000000 */  nop
    /* 165B0 8007EDB0 01004230 */  andi       $v0, $v0, 0x1
    /* 165B4 8007EDB4 07004010 */  beqz       $v0, .L8007EDD4
    /* 165B8 8007EDB8 C0100A00 */   sll       $v0, $t2, 3
    /* 165BC 8007EDBC 58012286 */  lh         $v0, 0x158($s1)
    /* 165C0 8007EDC0 BC022386 */  lh         $v1, 0x2BC($s1)
    /* 165C4 8007EDC4 00000000 */  nop
    /* 165C8 8007EDC8 21104300 */  addu       $v0, $v0, $v1
    /* 165CC 8007EDCC 2128A200 */  addu       $a1, $a1, $v0
    /* 165D0 8007EDD0 C0100A00 */  sll        $v0, $t2, 3
  .L8007EDD4:
    /* 165D4 8007EDD4 23104A00 */  subu       $v0, $v0, $t2
    /* 165D8 8007EDD8 C0100200 */  sll        $v0, $v0, 3
    /* 165DC 8007EDDC 23104A00 */  subu       $v0, $v0, $t2
    /* 165E0 8007EDE0 80100200 */  sll        $v0, $v0, 2
    /* 165E4 8007EDE4 21102202 */  addu       $v0, $s1, $v0
    /* 165E8 8007EDE8 9C034280 */  lb         $v0, 0x39C($v0)
    /* 165EC 8007EDEC 00000000 */  nop
    /* 165F0 8007EDF0 2128A200 */  addu       $a1, $a1, $v0
    /* 165F4 8007EDF4 20002296 */  lhu        $v0, 0x20($s1)
    /* 165F8 8007EDF8 64000324 */  addiu      $v1, $zero, 0x64
    /* 165FC 8007EDFC 23106200 */  subu       $v0, $v1, $v0
    /* 16600 8007EE00 1800A200 */  mult       $a1, $v0
    /* 16604 8007EE04 12100000 */  mflo       $v0
    /* 16608 8007EE08 EB51063C */  lui        $a2, (0x51EB851F >> 16)
    /* 1660C 8007EE0C 1F85C634 */  ori        $a2, $a2, (0x51EB851F & 0xFFFF)
    /* 16610 8007EE10 18004600 */  mult       $v0, $a2
    /* 16614 8007EE14 18002486 */  lh         $a0, 0x18($s1)
    /* 16618 8007EE18 C3170200 */  sra        $v0, $v0, 31
    /* 1661C 8007EE1C 10480000 */  mfhi       $t1
    /* 16620 8007EE20 43290900 */  sra        $a1, $t1, 5
    /* 16624 8007EE24 2328A200 */  subu       $a1, $a1, $v0
    /* 16628 8007EE28 1800A400 */  mult       $a1, $a0
    /* 1662C 8007EE2C 12480000 */  mflo       $t1
    /* 16630 8007EE30 1A002286 */  lh         $v0, 0x1A($s1)
    /* 16634 8007EE34 00000000 */  nop
    /* 16638 8007EE38 1A002201 */  div        $zero, $t1, $v0
    /* 1663C 8007EE3C 12280000 */  mflo       $a1
    /* 16640 8007EE40 20004296 */  lhu        $v0, 0x20($s2)
    /* 16644 8007EE44 00000000 */  nop
    /* 16648 8007EE48 23186200 */  subu       $v1, $v1, $v0
    /* 1664C 8007EE4C 18000301 */  mult       $t0, $v1
    /* 16650 8007EE50 12180000 */  mflo       $v1
    /* 16654 8007EE54 00000000 */  nop
    /* 16658 8007EE58 00000000 */  nop
    /* 1665C 8007EE5C 18006600 */  mult       $v1, $a2
    /* 16660 8007EE60 C31F0300 */  sra        $v1, $v1, 31
    /* 16664 8007EE64 10400000 */  mfhi       $t0
    /* 16668 8007EE68 43110800 */  sra        $v0, $t0, 5
    /* 1666C 8007EE6C 23404300 */  subu       $t0, $v0, $v1
    /* 16670 8007EE70 05006011 */  beqz       $t3, .L8007EE88
    /* 16674 8007EE74 23800501 */   subu      $s0, $t0, $a1
    /* 16678 8007EE78 180A010C */  jal        vs_main_getRandSmoothed
    /* 1667C 8007EE7C 0B000424 */   addiu     $a0, $zero, 0xB
    /* 16680 8007EE80 FBFF0326 */  addiu      $v1, $s0, -0x5
    /* 16684 8007EE84 21806200 */  addu       $s0, $v1, $v0
  .L8007EE88:
    /* 16688 8007EE88 21206002 */  addu       $a0, $s3, $zero
    /* 1668C 8007EE8C 78F9010C */  jal        _getAttackGemBuff
    /* 16690 8007EE90 21284002 */   addu      $a1, $s2, $zero
    /* 16694 8007EE94 00140200 */  sll        $v0, $v0, 16
    /* 16698 8007EE98 03140200 */  sra        $v0, $v0, 16
    /* 1669C 8007EE9C 21800202 */  addu       $s0, $s0, $v0
    /* 166A0 8007EEA0 21206002 */  addu       $a0, $s3, $zero
    /* 166A4 8007EEA4 21282002 */  addu       $a1, $s1, $zero
    /* 166A8 8007EEA8 A8F9010C */  jal        _getDefenseGemBuff
    /* 166AC 8007EEAC 21308002 */   addu      $a2, $s4, $zero
    /* 166B0 8007EEB0 00140200 */  sll        $v0, $v0, 16
    /* 166B4 8007EEB4 03140200 */  sra        $v0, $v0, 16
    /* 166B8 8007EEB8 23800202 */  subu       $s0, $s0, $v0
    /* 166BC 8007EEBC 03000106 */  bgez       $s0, .L8007EECC
    /* 166C0 8007EEC0 FF000224 */   addiu     $v0, $zero, 0xFF
    /* 166C4 8007EEC4 B6FB0108 */  j          .L8007EED8
    /* 166C8 8007EEC8 21800000 */   addu      $s0, $zero, $zero
  .L8007EECC:
    /* 166CC 8007EECC 03000216 */  bne        $s0, $v0, .L8007EEDC
    /* 166D0 8007EED0 21100002 */   addu      $v0, $s0, $zero
    /* 166D4 8007EED4 FE001024 */  addiu      $s0, $zero, 0xFE
  .L8007EED8:
    /* 166D8 8007EED8 21100002 */  addu       $v0, $s0, $zero
  .L8007EEDC:
    /* 166DC 8007EEDC 2400BF8F */  lw         $ra, 0x24($sp)
    /* 166E0 8007EEE0 2000B48F */  lw         $s4, 0x20($sp)
    /* 166E4 8007EEE4 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 166E8 8007EEE8 1800B28F */  lw         $s2, 0x18($sp)
    /* 166EC 8007EEEC 1400B18F */  lw         $s1, 0x14($sp)
    /* 166F0 8007EEF0 1000B08F */  lw         $s0, 0x10($sp)
    /* 166F4 8007EEF4 0800E003 */  jr         $ra
    /* 166F8 8007EEF8 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel _getIntelligenceDifference
