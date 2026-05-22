nonmatching func_800D6628, 0xA4

glabel func_800D6628
    /* 6DE28 800D6628 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 6DE2C 800D662C 1400B1AF */  sw         $s1, 0x14($sp)
    /* 6DE30 800D6630 21888000 */  addu       $s1, $a0, $zero
    /* 6DE34 800D6634 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 6DE38 800D6638 1800B2AF */  sw         $s2, 0x18($sp)
    /* 6DE3C 800D663C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 6DE40 800D6640 280D2396 */  lhu        $v1, 0xD28($s1)
    /* 6DE44 800D6644 04000224 */  addiu      $v0, $zero, 0x4
    /* 6DE48 800D6648 1A006214 */  bne        $v1, $v0, .L800D66B4
    /* 6DE4C 800D664C FF00A530 */   andi      $a1, $a1, 0xFF
    /* 6DE50 800D6650 2B10A200 */  sltu       $v0, $a1, $v0
    /* 6DE54 800D6654 04004010 */  beqz       $v0, .L800D6668
    /* 6DE58 800D6658 5555103C */   lui       $s0, (0x55555556 >> 16)
    /* 6DE5C 800D665C 2C0D2492 */  lbu        $a0, 0xD2C($s1)
    /* 6DE60 800D6660 AB590308 */  j          .L800D66AC
    /* 6DE64 800D6664 00000000 */   nop
  .L800D6668:
    /* 6DE68 800D6668 56551036 */  ori        $s0, $s0, (0x55555556 & 0xFFFF)
    /* 6DE6C 800D666C 0F80123C */  lui        $s2, %hi(D_800EC4B8)
  .L800D6670:
    /* 6DE70 800D6670 B19B000C */  jal        rand
    /* 6DE74 800D6674 00000000 */   nop
    /* 6DE78 800D6678 18005000 */  mult       $v0, $s0
    /* 6DE7C 800D667C C31F0200 */  sra        $v1, $v0, 31
    /* 6DE80 800D6680 B8C44492 */  lbu        $a0, %lo(D_800EC4B8)($s2)
    /* 6DE84 800D6684 10380000 */  mfhi       $a3
    /* 6DE88 800D6688 2330E300 */  subu       $a2, $a3, $v1
    /* 6DE8C 800D668C 40180600 */  sll        $v1, $a2, 1
    /* 6DE90 800D6690 21186600 */  addu       $v1, $v1, $a2
    /* 6DE94 800D6694 23304300 */  subu       $a2, $v0, $v1
    /* 6DE98 800D6698 F5FFC410 */  beq        $a2, $a0, .L800D6670
    /* 6DE9C 800D669C FF00C530 */   andi      $a1, $a2, 0xFF
    /* 6DEA0 800D66A0 2C0D2492 */  lbu        $a0, 0xD2C($s1)
    /* 6DEA4 800D66A4 0F80023C */  lui        $v0, %hi(D_800EC4B8)
    /* 6DEA8 800D66A8 B8C446A0 */  sb         $a2, %lo(D_800EC4B8)($v0)
  .L800D66AC:
    /* 6DEAC 800D66AC A3B9020C */  jal        func_800AE68C
    /* 6DEB0 800D66B0 00000000 */   nop
  .L800D66B4:
    /* 6DEB4 800D66B4 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 6DEB8 800D66B8 1800B28F */  lw         $s2, 0x18($sp)
    /* 6DEBC 800D66BC 1400B18F */  lw         $s1, 0x14($sp)
    /* 6DEC0 800D66C0 1000B08F */  lw         $s0, 0x10($sp)
    /* 6DEC4 800D66C4 0800E003 */  jr         $ra
    /* 6DEC8 800D66C8 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_800D6628
