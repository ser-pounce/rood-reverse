nonmatching func_800A0618, 0xA0

glabel func_800A0618
    /* 37E18 800A0618 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 37E1C 800A061C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 37E20 800A0620 21808000 */  addu       $s0, $a0, $zero
    /* 37E24 800A0624 1400B1AF */  sw         $s1, 0x14($sp)
    /* 37E28 800A0628 2188E000 */  addu       $s1, $a3, $zero
    /* 37E2C 800A062C 2138C000 */  addu       $a3, $a2, $zero
    /* 37E30 800A0630 1800BFAF */  sw         $ra, 0x18($sp)
    /* 37E34 800A0634 8180020C */  jal        func_800A0204
    /* 37E38 800A0638 21300000 */   addu      $a2, $zero, $zero
    /* 37E3C 800A063C 18004004 */  bltz       $v0, .L800A06A0
    /* 37E40 800A0640 00000000 */   nop
    /* 37E44 800A0644 16002012 */  beqz       $s1, .L800A06A0
    /* 37E48 800A0648 21100000 */   addu      $v0, $zero, $zero
    /* 37E4C 800A064C 0680023C */  lui        $v0, %hi(vs_gametime_tickspeed)
    /* 37E50 800A0650 4CE2428C */  lw         $v0, %lo(vs_gametime_tickspeed)($v0)
    /* 37E54 800A0654 00000000 */  nop
    /* 37E58 800A0658 C21F0200 */  srl        $v1, $v0, 31
    /* 37E5C 800A065C 21104300 */  addu       $v0, $v0, $v1
    /* 37E60 800A0660 43100200 */  sra        $v0, $v0, 1
    /* 37E64 800A0664 23882202 */  subu       $s1, $s1, $v0
    /* 37E68 800A0668 0F80033C */  lui        $v1, %hi(D_800F4538)
    /* 37E6C 800A066C 38456324 */  addiu      $v1, $v1, %lo(D_800F4538)
    /* 37E70 800A0670 80101000 */  sll        $v0, $s0, 2
    /* 37E74 800A0674 21104300 */  addu       $v0, $v0, $v1
    /* 37E78 800A0678 0000508C */  lw         $s0, 0x0($v0)
    /* 37E7C 800A067C 0500201A */  blez       $s1, .L800A0694
    /* 37E80 800A0680 21200002 */   addu      $a0, $s0, $zero
    /* 37E84 800A0684 B20511A2 */  sb         $s1, 0x5B2($s0)
    /* 37E88 800A0688 540C0526 */  addiu      $a1, $s0, 0xC54
    /* 37E8C 800A068C 8ABE020C */  jal        func_800AFA28
    /* 37E90 800A0690 01000624 */   addiu     $a2, $zero, 0x1
  .L800A0694:
    /* 37E94 800A0694 01000224 */  addiu      $v0, $zero, 0x1
    /* 37E98 800A0698 B20502A2 */  sb         $v0, 0x5B2($s0)
    /* 37E9C 800A069C 21100000 */  addu       $v0, $zero, $zero
  .L800A06A0:
    /* 37EA0 800A06A0 1800BF8F */  lw         $ra, 0x18($sp)
    /* 37EA4 800A06A4 1400B18F */  lw         $s1, 0x14($sp)
    /* 37EA8 800A06A8 1000B08F */  lw         $s0, 0x10($sp)
    /* 37EAC 800A06AC 2000BD27 */  addiu      $sp, $sp, 0x20
    /* 37EB0 800A06B0 0800E003 */  jr         $ra
    /* 37EB4 800A06B4 00000000 */   nop
endlabel func_800A0618
