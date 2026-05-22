nonmatching func_800B860C, 0xDC

glabel func_800B860C
    /* 4FE0C 800B860C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 4FE10 800B8610 1000B0AF */  sw         $s0, 0x10($sp)
    /* 4FE14 800B8614 21808000 */  addu       $s0, $a0, $zero
    /* 4FE18 800B8618 1400BFAF */  sw         $ra, 0x14($sp)
    /* 4FE1C 800B861C 03000292 */  lbu        $v0, 0x3($s0)
    /* 4FE20 800B8620 00000000 */  nop
    /* 4FE24 800B8624 82100200 */  srl        $v0, $v0, 2
    /* 4FE28 800B8628 03004330 */  andi       $v1, $v0, 0x3
    /* 4FE2C 800B862C 01000224 */  addiu      $v0, $zero, 0x1
    /* 4FE30 800B8630 14006210 */  beq        $v1, $v0, .L800B8684
    /* 4FE34 800B8634 02006228 */   slti      $v0, $v1, 0x2
    /* 4FE38 800B8638 05004010 */  beqz       $v0, .L800B8650
    /* 4FE3C 800B863C 02000224 */   addiu     $v0, $zero, 0x2
    /* 4FE40 800B8640 07006010 */  beqz       $v1, .L800B8660
    /* 4FE44 800B8644 00000000 */   nop
    /* 4FE48 800B8648 B5E10208 */  j          .L800B86D4
    /* 4FE4C 800B864C 00000000 */   nop
  .L800B8650:
    /* 4FE50 800B8650 17006210 */  beq        $v1, $v0, .L800B86B0
    /* 4FE54 800B8654 00000000 */   nop
    /* 4FE58 800B8658 B5E10208 */  j          .L800B86D4
    /* 4FE5C 800B865C 00000000 */   nop
  .L800B8660:
    /* 4FE60 800B8660 80FF020C */  jal        vs_battle_getShort
    /* 4FE64 800B8664 01000426 */   addiu     $a0, $s0, 0x1
    /* 4FE68 800B8668 00140200 */  sll        $v0, $v0, 16
    /* 4FE6C 800B866C 03000492 */  lbu        $a0, 0x3($s0)
    /* 4FE70 800B8670 032C0200 */  sra        $a1, $v0, 16
    /* 4FE74 800B8674 E1F2010C */  jal        func_8007CB84
    /* 4FE78 800B8678 03008430 */   andi      $a0, $a0, 0x3
    /* 4FE7C 800B867C B5E10208 */  j          .L800B86D4
    /* 4FE80 800B8680 00000000 */   nop
  .L800B8684:
    /* 4FE84 800B8684 80FF020C */  jal        vs_battle_getShort
    /* 4FE88 800B8688 01000426 */   addiu     $a0, $s0, 0x1
    /* 4FE8C 800B868C 00140200 */  sll        $v0, $v0, 16
    /* 4FE90 800B8690 03000692 */  lbu        $a2, 0x3($s0)
    /* 4FE94 800B8694 032C0200 */  sra        $a1, $v0, 16
    /* 4FE98 800B8698 0300C430 */  andi       $a0, $a2, 0x3
    /* 4FE9C 800B869C 02310600 */  srl        $a2, $a2, 4
    /* 4FEA0 800B86A0 F7F2010C */  jal        func_8007CBDC
    /* 4FEA4 800B86A4 1A00C624 */   addiu     $a2, $a2, 0x1A
    /* 4FEA8 800B86A8 B5E10208 */  j          .L800B86D4
    /* 4FEAC 800B86AC 00000000 */   nop
  .L800B86B0:
    /* 4FEB0 800B86B0 80FF020C */  jal        vs_battle_getShort
    /* 4FEB4 800B86B4 01000426 */   addiu     $a0, $s0, 0x1
    /* 4FEB8 800B86B8 00140200 */  sll        $v0, $v0, 16
    /* 4FEBC 800B86BC 03000692 */  lbu        $a2, 0x3($s0)
    /* 4FEC0 800B86C0 032C0200 */  sra        $a1, $v0, 16
    /* 4FEC4 800B86C4 0300C430 */  andi       $a0, $a2, 0x3
    /* 4FEC8 800B86C8 02310600 */  srl        $a2, $a2, 4
    /* 4FECC 800B86CC 06F3010C */  jal        func_8007CC18
    /* 4FED0 800B86D0 1A00C624 */   addiu     $a2, $a2, 0x1A
  .L800B86D4:
    /* 4FED4 800B86D4 1400BF8F */  lw         $ra, 0x14($sp)
    /* 4FED8 800B86D8 1000B08F */  lw         $s0, 0x10($sp)
    /* 4FEDC 800B86DC 21100000 */  addu       $v0, $zero, $zero
    /* 4FEE0 800B86E0 0800E003 */  jr         $ra
    /* 4FEE4 800B86E4 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800B860C
