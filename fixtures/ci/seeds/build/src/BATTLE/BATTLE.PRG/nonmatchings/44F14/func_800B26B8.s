/* Handwritten function */
nonmatching func_800B26B8, 0x1F0

glabel func_800B26B8
    /* 49EB8 800B26B8 D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 49EBC 800B26BC 2400B5AF */  sw         $s5, 0x24($sp)
    /* 49EC0 800B26C0 21A88000 */  addu       $s5, $a0, $zero
    /* 49EC4 800B26C4 1400B1AF */  sw         $s1, 0x14($sp)
    /* 49EC8 800B26C8 2188A000 */  addu       $s1, $a1, $zero
    /* 49ECC 800B26CC 1800B2AF */  sw         $s2, 0x18($sp)
    /* 49ED0 800B26D0 2190C000 */  addu       $s2, $a2, $zero
    /* 49ED4 800B26D4 1000B0AF */  sw         $s0, 0x10($sp)
    /* 49ED8 800B26D8 2180E000 */  addu       $s0, $a3, $zero
    /* 49EDC 800B26DC 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 49EE0 800B26E0 801F133C */  lui        $s3, (0x1F80035C >> 16)
    /* 49EE4 800B26E4 5C037336 */  ori        $s3, $s3, (0x1F80035C & 0xFFFF)
    /* 49EE8 800B26E8 2000B4AF */  sw         $s4, 0x20($sp)
    /* 49EEC 800B26EC 801F143C */  lui        $s4, (0x1F8003C0 >> 16)
    /* 49EF0 800B26F0 C0039436 */  ori        $s4, $s4, (0x1F8003C0 & 0xFFFF)
    /* 49EF4 800B26F4 40111000 */  sll        $v0, $s0, 5
    /* 49EF8 800B26F8 21105500 */  addu       $v0, $v0, $s5
    /* 49EFC 800B26FC 2800BFAF */  sw         $ra, 0x28($sp)
    /* 49F00 800B2700 7018438C */  lw         $v1, 0x1870($v0)
    /* 49F04 800B2704 7418448C */  lw         $a0, 0x1874($v0)
    /* 49F08 800B2708 7818458C */  lw         $a1, 0x1878($v0)
    /* 49F0C 800B270C 7C18468C */  lw         $a2, 0x187C($v0)
    /* 49F10 800B2710 000083AE */  sw         $v1, 0x0($s4)
    /* 49F14 800B2714 040084AE */  sw         $a0, 0x4($s4)
    /* 49F18 800B2718 080085AE */  sw         $a1, 0x8($s4)
    /* 49F1C 800B271C 0C0086AE */  sw         $a2, 0xC($s4)
    /* 49F20 800B2720 8018438C */  lw         $v1, 0x1880($v0)
    /* 49F24 800B2724 8418448C */  lw         $a0, 0x1884($v0)
    /* 49F28 800B2728 8818458C */  lw         $a1, 0x1888($v0)
    /* 49F2C 800B272C 8C18468C */  lw         $a2, 0x188C($v0)
    /* 49F30 800B2730 100083AE */  sw         $v1, 0x10($s4)
    /* 49F34 800B2734 140084AE */  sw         $a0, 0x14($s4)
    /* 49F38 800B2738 180085AE */  sw         $a1, 0x18($s4)
    /* 49F3C 800B273C 1C0086AE */  sw         $a2, 0x1C($s4)
    /* 49F40 800B2740 801F053C */  lui        $a1, (0x1F8003C0 >> 16)
    /* 49F44 800B2744 C003A534 */  ori        $a1, $a1, (0x1F8003C0 & 0xFFFF)
    /* 49F48 800B2748 5BC6020C */  jal        func_800B196C
    /* 49F4C 800B274C 21202002 */   addu      $a0, $s1, $zero
    /* 49F50 800B2750 00002C8E */  lw         $t4, 0x0($s1)
    /* 49F54 800B2754 04002D8E */  lw         $t5, 0x4($s1)
    /* 49F58 800B2758 0000CC48 */  ctc2       $t4, $0 /* handwritten instruction */
    /* 49F5C 800B275C 0008CD48 */  ctc2       $t5, $1 /* handwritten instruction */
    /* 49F60 800B2760 08002C8E */  lw         $t4, 0x8($s1)
    /* 49F64 800B2764 0C002D8E */  lw         $t5, 0xC($s1)
    /* 49F68 800B2768 10002E8E */  lw         $t6, 0x10($s1)
    /* 49F6C 800B276C 0010CC48 */  ctc2       $t4, $2 /* handwritten instruction */
    /* 49F70 800B2770 0018CD48 */  ctc2       $t5, $3 /* handwritten instruction */
    /* 49F74 800B2774 0020CE48 */  ctc2       $t6, $4 /* handwritten instruction */
    /* 49F78 800B2778 14002C8E */  lw         $t4, 0x14($s1)
    /* 49F7C 800B277C 18002D8E */  lw         $t5, 0x18($s1)
    /* 49F80 800B2780 0028CC48 */  ctc2       $t4, $5 /* handwritten instruction */
    /* 49F84 800B2784 1C002E8E */  lw         $t6, 0x1C($s1)
    /* 49F88 800B2788 0030CD48 */  ctc2       $t5, $6 /* handwritten instruction */
    /* 49F8C 800B278C 0038CE48 */  ctc2       $t6, $7 /* handwritten instruction */
    /* 49F90 800B2790 FFFF1026 */  addiu      $s0, $s0, -0x1
    /* 49F94 800B2794 40811000 */  sll        $s0, $s0, 5
    /* 49F98 800B2798 2180B002 */  addu       $s0, $s5, $s0
    /* 49F9C 800B279C A4180296 */  lhu        $v0, 0x18A4($s0)
    /* 49FA0 800B27A0 00000000 */  nop
    /* 49FA4 800B27A4 4C0062A6 */  sh         $v0, 0x4C($s3)
    /* 49FA8 800B27A8 A8180296 */  lhu        $v0, 0x18A8($s0)
    /* 49FAC 800B27AC 00000000 */  nop
    /* 49FB0 800B27B0 4E0062A6 */  sh         $v0, 0x4E($s3)
    /* 49FB4 800B27B4 AC180296 */  lhu        $v0, 0x18AC($s0)
    /* 49FB8 800B27B8 801F033C */  lui        $v1, (0x1F8003A8 >> 16)
    /* 49FBC 800B27BC A8036334 */  ori        $v1, $v1, (0x1F8003A8 & 0xFFFF)
    /* 49FC0 800B27C0 500062A6 */  sh         $v0, 0x50($s3)
    /* 49FC4 800B27C4 000060C8 */  lwc2       $0, 0x0($v1)
    /* 49FC8 800B27C8 040061C8 */  lwc2       $1, 0x4($v1)
    /* 49FCC 800B27CC 00000000 */  nop
    /* 49FD0 800B27D0 00000000 */  nop
    /* 49FD4 800B27D4 1200484A */  mvmva      1, 0, 0, 0, 0
    /* 49FD8 800B27D8 801F033C */  lui        $v1, (0x1F8003D4 >> 16)
    /* 49FDC 800B27DC D4036334 */  ori        $v1, $v1, (0x1F8003D4 & 0xFFFF)
    /* 49FE0 800B27E0 000079E8 */  swc2       $25, 0x0($v1)
    /* 49FE4 800B27E4 04007AE8 */  swc2       $26, 0x4($v1) /* handwritten instruction */
    /* 49FE8 800B27E8 08007BE8 */  swc2       $27, 0x8($v1) /* handwritten instruction */
    /* 49FEC 800B27EC 0F80023C */  lui        $v0, %hi(D_800F3C58)
    /* 49FF0 800B27F0 583C4224 */  addiu      $v0, $v0, %lo(D_800F3C58)
    /* 49FF4 800B27F4 40911200 */  sll        $s2, $s2, 5
    /* 49FF8 800B27F8 21104202 */  addu       $v0, $s2, $v0
    /* 49FFC 800B27FC 0000838E */  lw         $v1, 0x0($s4)
    /* 4A000 800B2800 0400848E */  lw         $a0, 0x4($s4)
    /* 4A004 800B2804 0800858E */  lw         $a1, 0x8($s4)
    /* 4A008 800B2808 0C00868E */  lw         $a2, 0xC($s4)
    /* 4A00C 800B280C 000043AC */  sw         $v1, 0x0($v0)
    /* 4A010 800B2810 040044AC */  sw         $a0, 0x4($v0)
    /* 4A014 800B2814 080045AC */  sw         $a1, 0x8($v0)
    /* 4A018 800B2818 0C0046AC */  sw         $a2, 0xC($v0)
    /* 4A01C 800B281C 1000838E */  lw         $v1, 0x10($s4)
    /* 4A020 800B2820 1400848E */  lw         $a0, 0x14($s4)
    /* 4A024 800B2824 1800858E */  lw         $a1, 0x18($s4)
    /* 4A028 800B2828 1C00868E */  lw         $a2, 0x1C($s4)
    /* 4A02C 800B282C 100043AC */  sw         $v1, 0x10($v0)
    /* 4A030 800B2830 140044AC */  sw         $a0, 0x14($v0)
    /* 4A034 800B2834 180045AC */  sw         $a1, 0x18($v0)
    /* 4A038 800B2838 1C0046AC */  sw         $a2, 0x1C($v0)
    /* 4A03C 800B283C 21905502 */  addu       $s2, $s2, $s5
    /* 4A040 800B2840 0000828E */  lw         $v0, 0x0($s4)
    /* 4A044 800B2844 0400838E */  lw         $v1, 0x4($s4)
    /* 4A048 800B2848 0800848E */  lw         $a0, 0x8($s4)
    /* 4A04C 800B284C 0C00858E */  lw         $a1, 0xC($s4)
    /* 4A050 800B2850 6C0042AE */  sw         $v0, 0x6C($s2)
    /* 4A054 800B2854 700043AE */  sw         $v1, 0x70($s2)
    /* 4A058 800B2858 740044AE */  sw         $a0, 0x74($s2)
    /* 4A05C 800B285C 780045AE */  sw         $a1, 0x78($s2)
    /* 4A060 800B2860 1000828E */  lw         $v0, 0x10($s4)
    /* 4A064 800B2864 1400838E */  lw         $v1, 0x14($s4)
    /* 4A068 800B2868 1800848E */  lw         $a0, 0x18($s4)
    /* 4A06C 800B286C 1C00858E */  lw         $a1, 0x1C($s4)
    /* 4A070 800B2870 7C0042AE */  sw         $v0, 0x7C($s2)
    /* 4A074 800B2874 800043AE */  sw         $v1, 0x80($s2)
    /* 4A078 800B2878 840044AE */  sw         $a0, 0x84($s2)
    /* 4A07C 800B287C 880045AE */  sw         $a1, 0x88($s2)
    /* 4A080 800B2880 2800BF8F */  lw         $ra, 0x28($sp)
    /* 4A084 800B2884 2400B58F */  lw         $s5, 0x24($sp)
    /* 4A088 800B2888 2000B48F */  lw         $s4, 0x20($sp)
    /* 4A08C 800B288C 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 4A090 800B2890 1800B28F */  lw         $s2, 0x18($sp)
    /* 4A094 800B2894 1400B18F */  lw         $s1, 0x14($sp)
    /* 4A098 800B2898 1000B08F */  lw         $s0, 0x10($sp)
    /* 4A09C 800B289C 3000BD27 */  addiu      $sp, $sp, 0x30
    /* 4A0A0 800B28A0 0800E003 */  jr         $ra
    /* 4A0A4 800B28A4 00000000 */   nop
endlabel func_800B26B8
