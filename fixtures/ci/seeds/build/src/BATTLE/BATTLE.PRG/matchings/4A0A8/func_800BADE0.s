nonmatching func_800BADE0, 0x94

glabel func_800BADE0
    /* 525E0 800BADE0 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 525E4 800BADE4 1800B2AF */  sw         $s2, 0x18($sp)
    /* 525E8 800BADE8 0F80123C */  lui        $s2, %hi(D_800F4BF8)
    /* 525EC 800BADEC F84B4292 */  lbu        $v0, %lo(D_800F4BF8)($s2)
    /* 525F0 800BADF0 1400B1AF */  sw         $s1, 0x14($sp)
    /* 525F4 800BADF4 21888000 */  addu       $s1, $a0, $zero
    /* 525F8 800BADF8 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 525FC 800BADFC 11004014 */  bnez       $v0, .L800BAE44
    /* 52600 800BAE00 1000B0AF */   sw        $s0, 0x10($sp)
    /* 52604 800BAE04 80FF020C */  jal        vs_battle_getShort
    /* 52608 800BAE08 01002426 */   addiu     $a0, $s1, 0x1
    /* 5260C 800BAE0C 04002426 */  addiu      $a0, $s1, 0x4
    /* 52610 800BAE10 00840200 */  sll        $s0, $v0, 16
    /* 52614 800BAE14 80FF020C */  jal        vs_battle_getShort
    /* 52618 800BAE18 03841000 */   sra       $s0, $s0, 16
    /* 5261C 800BAE1C 21200002 */  addu       $a0, $s0, $zero
    /* 52620 800BAE20 00140200 */  sll        $v0, $v0, 16
    /* 52624 800BAE24 03002592 */  lbu        $a1, 0x3($s1)
    /* 52628 800BAE28 06002792 */  lbu        $a3, 0x6($s1)
    /* 5262C 800BAE2C A6EE010C */  jal        func_8007BA98
    /* 52630 800BAE30 03340200 */   sra       $a2, $v0, 16
    /* 52634 800BAE34 01000224 */  addiu      $v0, $zero, 0x1
    /* 52638 800BAE38 21184000 */  addu       $v1, $v0, $zero
    /* 5263C 800BAE3C 97EB0208 */  j          .L800BAE5C
    /* 52640 800BAE40 F84B43A2 */   sb        $v1, %lo(D_800F4BF8)($s2)
  .L800BAE44:
    /* 52644 800BAE44 7FEE010C */  jal        func_8007B9FC
    /* 52648 800BAE48 00000000 */   nop
    /* 5264C 800BAE4C 03004014 */  bnez       $v0, .L800BAE5C
    /* 52650 800BAE50 01000224 */   addiu     $v0, $zero, 0x1
    /* 52654 800BAE54 F84B40A2 */  sb         $zero, %lo(D_800F4BF8)($s2)
    /* 52658 800BAE58 04000224 */  addiu      $v0, $zero, 0x4
  .L800BAE5C:
    /* 5265C 800BAE5C 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 52660 800BAE60 1800B28F */  lw         $s2, 0x18($sp)
    /* 52664 800BAE64 1400B18F */  lw         $s1, 0x14($sp)
    /* 52668 800BAE68 1000B08F */  lw         $s0, 0x10($sp)
    /* 5266C 800BAE6C 0800E003 */  jr         $ra
    /* 52670 800BAE70 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_800BADE0
