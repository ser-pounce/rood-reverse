nonmatching func_8008DDA8, 0x104

glabel func_8008DDA8
    /* 255A8 8008DDA8 D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 255AC 8008DDAC 0080023C */  lui        $v0, (0x80008000 >> 16)
    /* 255B0 8008DDB0 00804234 */  ori        $v0, $v0, (0x80008000 & 0xFFFF)
    /* 255B4 8008DDB4 1000A2AF */  sw         $v0, 0x10($sp)
    /* 255B8 8008DDB8 0F80023C */  lui        $v0, %hi(vs_battle_roomData + 0x68)
    /* 255BC 8008DDBC 2000B2AF */  sw         $s2, 0x20($sp)
    /* 255C0 8008DDC0 601C528C */  lw         $s2, %lo(vs_battle_roomData + 0x68)($v0)
    /* 255C4 8008DDC4 2400B3AF */  sw         $s3, 0x24($sp)
    /* 255C8 8008DDC8 1000B327 */  addiu      $s3, $sp, 0x10
    /* 255CC 8008DDCC 2800BFAF */  sw         $ra, 0x28($sp)
    /* 255D0 8008DDD0 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 255D4 8008DDD4 2D004012 */  beqz       $s2, .L8008DE8C
    /* 255D8 8008DDD8 1800B0AF */   sw        $s0, 0x18($sp)
    /* 255DC 8008DDDC 00004386 */  lh         $v1, 0x0($s2)
    /* 255E0 8008DDE0 C3110400 */  sra        $v0, $a0, 7
    /* 255E4 8008DDE4 2B104300 */  sltu       $v0, $v0, $v1
    /* 255E8 8008DDE8 28004010 */  beqz       $v0, .L8008DE8C
    /* 255EC 8008DDEC C3110500 */   sra       $v0, $a1, 7
    /* 255F0 8008DDF0 02004386 */  lh         $v1, 0x2($s2)
    /* 255F4 8008DDF4 00000000 */  nop
    /* 255F8 8008DDF8 2B104300 */  sltu       $v0, $v0, $v1
    /* 255FC 8008DDFC 23004010 */  beqz       $v0, .L8008DE8C
    /* 25600 8008DE00 43890400 */   sra       $s1, $a0, 5
    /* 25604 8008DE04 21202002 */  addu       $a0, $s1, $zero
    /* 25608 8008DE08 43810500 */  sra        $s0, $a1, 5
    /* 2560C 8008DE0C 21280002 */  addu       $a1, $s0, $zero
    /* 25610 8008DE10 4565020C */  jal        func_80099514
    /* 25614 8008DE14 21300000 */   addu      $a2, $zero, $zero
    /* 25618 8008DE18 FF004730 */  andi       $a3, $v0, 0xFF
    /* 2561C 8008DE1C 21202002 */  addu       $a0, $s1, $zero
    /* 25620 8008DE20 21280002 */  addu       $a1, $s0, $zero
    /* 25624 8008DE24 01000624 */  addiu      $a2, $zero, 0x1
    /* 25628 8008DE28 7F00E230 */  andi       $v0, $a3, 0x7F
    /* 2562C 8008DE2C 04004386 */  lh         $v1, 0x4($s2)
    /* 25630 8008DE30 0410C200 */  sllv       $v0, $v0, $a2
    /* 25634 8008DE34 23186200 */  subu       $v1, $v1, $v0
    /* 25638 8008DE38 C0180300 */  sll        $v1, $v1, 3
    /* 2563C 8008DE3C FF7F6330 */  andi       $v1, $v1, 0x7FFF
    /* 25640 8008DE40 8000E230 */  andi       $v0, $a3, 0x80
    /* 25644 8008DE44 00120200 */  sll        $v0, $v0, 8
    /* 25648 8008DE48 25386200 */  or         $a3, $v1, $v0
    /* 2564C 8008DE4C 4565020C */  jal        func_80099514
    /* 25650 8008DE50 1000A7A7 */   sh        $a3, 0x10($sp)
    /* 25654 8008DE54 FF004730 */  andi       $a3, $v0, 0xFF
    /* 25658 8008DE58 7F00E230 */  andi       $v0, $a3, 0x7F
    /* 2565C 8008DE5C 04004386 */  lh         $v1, 0x4($s2)
    /* 25660 8008DE60 40100200 */  sll        $v0, $v0, 1
    /* 25664 8008DE64 23186200 */  subu       $v1, $v1, $v0
    /* 25668 8008DE68 C0180300 */  sll        $v1, $v1, 3
    /* 2566C 8008DE6C 03006018 */  blez       $v1, .L8008DE7C
    /* 25670 8008DE70 FF7F6330 */   andi      $v1, $v1, 0x7FFF
    /* 25674 8008DE74 A2370208 */  j          .L8008DE88
    /* 25678 8008DE78 10F80734 */   ori       $a3, $zero, 0xF810
  .L8008DE7C:
    /* 2567C 8008DE7C 8000E230 */  andi       $v0, $a3, 0x80
    /* 25680 8008DE80 00120200 */  sll        $v0, $v0, 8
    /* 25684 8008DE84 25386200 */  or         $a3, $v1, $v0
  .L8008DE88:
    /* 25688 8008DE88 020067A6 */  sh         $a3, 0x2($s3)
  .L8008DE8C:
    /* 2568C 8008DE8C 1000A28F */  lw         $v0, 0x10($sp)
    /* 25690 8008DE90 2800BF8F */  lw         $ra, 0x28($sp)
    /* 25694 8008DE94 2400B38F */  lw         $s3, 0x24($sp)
    /* 25698 8008DE98 2000B28F */  lw         $s2, 0x20($sp)
    /* 2569C 8008DE9C 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 256A0 8008DEA0 1800B08F */  lw         $s0, 0x18($sp)
    /* 256A4 8008DEA4 0800E003 */  jr         $ra
    /* 256A8 8008DEA8 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel func_8008DDA8
