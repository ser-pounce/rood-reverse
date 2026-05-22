nonmatching _SpuIsInAllocateArea, 0x80

glabel _SpuIsInAllocateArea
    /* F004 8001E804 0380023C */  lui        $v0, %hi(D_800308C8)
    /* F008 8001E808 C808428C */  lw         $v0, %lo(D_800308C8)($v0)
    /* F00C 8001E80C 00000000 */  nop
    /* F010 8001E810 03004014 */  bnez       $v0, .L8001E820
    /* F014 8001E814 0080083C */   lui       $t0, (0x80000000 >> 16)
    /* F018 8001E818 1F7A0008 */  j          .L8001E87C
    /* F01C 8001E81C 21100000 */   addu      $v0, $zero, $zero
  .L8001E820:
    /* F020 8001E820 0040073C */  lui        $a3, (0x40000000 >> 16)
    /* F024 8001E824 FF0F063C */  lui        $a2, (0xFFFFFFF >> 16)
    /* F028 8001E828 FFFFC634 */  ori        $a2, $a2, (0xFFFFFFF & 0xFFFF)
    /* F02C 8001E82C 21284000 */  addu       $a1, $v0, $zero
  .L8001E830:
    /* F030 8001E830 0000A38C */  lw         $v1, 0x0($a1)
    /* F034 8001E834 00000000 */  nop
    /* F038 8001E838 24106800 */  and        $v0, $v1, $t0
    /* F03C 8001E83C 0C004014 */  bnez       $v0, .L8001E870
    /* F040 8001E840 24106700 */   and       $v0, $v1, $a3
    /* F044 8001E844 0C004014 */  bnez       $v0, .L8001E878
    /* F048 8001E848 24186600 */   and       $v1, $v1, $a2
    /* F04C 8001E84C 2B106400 */  sltu       $v0, $v1, $a0
    /* F050 8001E850 0A004010 */  beqz       $v0, .L8001E87C
    /* F054 8001E854 01000224 */   addiu     $v0, $zero, 0x1
    /* F058 8001E858 0400A28C */  lw         $v0, 0x4($a1)
    /* F05C 8001E85C 00000000 */  nop
    /* F060 8001E860 21106200 */  addu       $v0, $v1, $v0
    /* F064 8001E864 2B108200 */  sltu       $v0, $a0, $v0
    /* F068 8001E868 04004014 */  bnez       $v0, .L8001E87C
    /* F06C 8001E86C 01000224 */   addiu     $v0, $zero, 0x1
  .L8001E870:
    /* F070 8001E870 0C7A0008 */  j          .L8001E830
    /* F074 8001E874 0800A524 */   addiu     $a1, $a1, 0x8
  .L8001E878:
    /* F078 8001E878 21100000 */  addu       $v0, $zero, $zero
  .L8001E87C:
    /* F07C 8001E87C 0800E003 */  jr         $ra
    /* F080 8001E880 00000000 */   nop
endlabel _SpuIsInAllocateArea
