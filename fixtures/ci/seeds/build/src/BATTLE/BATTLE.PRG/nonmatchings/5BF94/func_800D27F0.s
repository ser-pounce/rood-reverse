nonmatching func_800D27F0, 0x98

glabel func_800D27F0
    /* 69FF0 800D27F0 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 69FF4 800D27F4 1800B2AF */  sw         $s2, 0x18($sp)
    /* 69FF8 800D27F8 0F80123C */  lui        $s2, %hi(D_800F55F4)
    /* 69FFC 800D27FC 1000B0AF */  sw         $s0, 0x10($sp)
    /* 6A000 800D2800 F455508E */  lw         $s0, %lo(D_800F55F4)($s2)
    /* 6A004 800D2804 1400B1AF */  sw         $s1, 0x14($sp)
    /* 6A008 800D2808 21888000 */  addu       $s1, $a0, $zero
    /* 6A00C 800D280C 03000016 */  bnez       $s0, .L800D281C
    /* 6A010 800D2810 1C00BFAF */   sw        $ra, 0x1C($sp)
    /* 6A014 800D2814 9139030C */  jal        func_800CE644
    /* 6A018 800D2818 14000424 */   addiu     $a0, $zero, 0x14
  .L800D281C:
    /* 6A01C 800D281C 335B030C */  jal        func_800D6CCC
    /* 6A020 800D2820 3C000426 */   addiu     $a0, $s0, 0x3C
    /* 6A024 800D2824 FF000224 */  addiu      $v0, $zero, 0xFF
    /* 6A028 800D2828 770002A2 */  sb         $v0, 0x77($s0)
    /* 6A02C 800D282C 000000AE */  sw         $zero, 0x0($s0)
    /* 6A030 800D2830 1800228E */  lw         $v0, 0x18($s1)
    /* 6A034 800D2834 0400048E */  lw         $a0, 0x4($s0)
    /* 6A038 800D2838 0F80033C */  lui        $v1, %hi(D_800F55F8)
    /* 6A03C 800D283C 040002AE */  sw         $v0, 0x4($s0)
    /* 6A040 800D2840 F855628C */  lw         $v0, %lo(D_800F55F8)($v1)
    /* 6A044 800D2844 1800258E */  lw         $a1, 0x18($s1)
    /* 6A048 800D2848 F45544AE */  sw         $a0, %lo(D_800F55F4)($s2)
    /* 6A04C 800D284C 01004224 */  addiu      $v0, $v0, 0x1
    /* 6A050 800D2850 0200A010 */  beqz       $a1, .L800D285C
    /* 6A054 800D2854 F85562AC */   sw        $v0, %lo(D_800F55F8)($v1)
    /* 6A058 800D2858 0000B0AC */  sw         $s0, 0x0($a1)
  .L800D285C:
    /* 6A05C 800D285C 08002292 */  lbu        $v0, 0x8($s1)
    /* 6A060 800D2860 180030AE */  sw         $s0, 0x18($s1)
    /* 6A064 800D2864 01004224 */  addiu      $v0, $v0, 0x1
    /* 6A068 800D2868 080022A2 */  sb         $v0, 0x8($s1)
    /* 6A06C 800D286C 21100002 */  addu       $v0, $s0, $zero
    /* 6A070 800D2870 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 6A074 800D2874 1800B28F */  lw         $s2, 0x18($sp)
    /* 6A078 800D2878 1400B18F */  lw         $s1, 0x14($sp)
    /* 6A07C 800D287C 1000B08F */  lw         $s0, 0x10($sp)
    /* 6A080 800D2880 0800E003 */  jr         $ra
    /* 6A084 800D2884 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_800D27F0
