nonmatching func_800C282C, 0x80

glabel func_800C282C
    /* 5A02C 800C282C B0FFBD27 */  addiu      $sp, $sp, -0x50
    /* 5A030 800C2830 4000B0AF */  sw         $s0, 0x40($sp)
    /* 5A034 800C2834 801F103C */  lui        $s0, (0x1F800350 >> 16)
    /* 5A038 800C2838 1000A427 */  addiu      $a0, $sp, 0x10
    /* 5A03C 800C283C 4C00BFAF */  sw         $ra, 0x4C($sp)
    /* 5A040 800C2840 4800B2AF */  sw         $s2, 0x48($sp)
    /* 5A044 800C2844 14EA010C */  jal        vs_battle_syncCameraAnglesFromPosition
    /* 5A048 800C2848 4400B1AF */   sw        $s1, 0x44($sp)
    /* 5A04C 800C284C 1000B18F */  lw         $s1, 0x10($sp)
    /* 5A050 800C2850 50031036 */  ori        $s0, $s0, (0x1F800350 & 0xFFFF)
    /* 5A054 800C2854 C903010C */  jal        rcos
    /* 5A058 800C2858 21202002 */   addu      $a0, $s1, $zero
    /* 5A05C 800C285C 21202002 */  addu       $a0, $s1, $zero
    /* 5A060 800C2860 CA03010C */  jal        rsin
    /* 5A064 800C2864 21904000 */   addu      $s2, $v0, $zero
    /* 5A068 800C2868 21204000 */  addu       $a0, $v0, $zero
    /* 5A06C 800C286C 0F80033C */  lui        $v1, %hi(D_800EB9B8)
    /* 5A070 800C2870 000012A6 */  sh         $s2, 0x0($s0)
    /* 5A074 800C2874 B8B9638C */  lw         $v1, %lo(D_800EB9B8)($v1)
    /* 5A078 800C2878 801F023C */  lui        $v0, (0x1F800350 >> 16)
    /* 5A07C 800C287C 040004A6 */  sh         $a0, 0x4($s0)
    /* 5A080 800C2880 23200400 */  negu       $a0, $a0
    /* 5A084 800C2884 100004A6 */  sh         $a0, 0x10($s0)
    /* 5A088 800C2888 140012A6 */  sh         $s2, 0x14($s0)
    /* 5A08C 800C288C 220071A4 */  sh         $s1, 0x22($v1)
    /* 5A090 800C2890 4C00BF8F */  lw         $ra, 0x4C($sp)
    /* 5A094 800C2894 4800B28F */  lw         $s2, 0x48($sp)
    /* 5A098 800C2898 4400B18F */  lw         $s1, 0x44($sp)
    /* 5A09C 800C289C 4000B08F */  lw         $s0, 0x40($sp)
    /* 5A0A0 800C28A0 50034234 */  ori        $v0, $v0, (0x1F800350 & 0xFFFF)
    /* 5A0A4 800C28A4 0800E003 */  jr         $ra
    /* 5A0A8 800C28A8 5000BD27 */   addiu     $sp, $sp, 0x50
endlabel func_800C282C
