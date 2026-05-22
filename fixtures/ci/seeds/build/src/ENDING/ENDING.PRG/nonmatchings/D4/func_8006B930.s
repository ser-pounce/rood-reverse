nonmatching func_8006B930, 0x84

glabel func_8006B930
    /* 3130 8006B930 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 3134 8006B934 1800BFAF */  sw         $ra, 0x18($sp)
    /* 3138 8006B938 1400B1AF */  sw         $s1, 0x14($sp)
    /* 313C 8006B93C 500E010C */  jal        vs_main_processPadState
    /* 3140 8006B940 1000B0AF */   sw        $s0, 0x10($sp)
    /* 3144 8006B944 0580033C */  lui        $v1, %hi(D_80055C80)
    /* 3148 8006B948 0680103C */  lui        $s0, %hi(vs_main_frameBuf)
    /* 314C 8006B94C 805C6324 */  addiu      $v1, $v1, %lo(D_80055C80)
    /* 3150 8006B950 801F113C */  lui        $s1, (0x1F800000 >> 16)
    /* 3154 8006B954 10E2028E */  lw         $v0, %lo(vs_main_frameBuf)($s0)
    /* 3158 8006B958 22080524 */  addiu      $a1, $zero, 0x822
    /* 315C 8006B95C 80100200 */  sll        $v0, $v0, 2
    /* 3160 8006B960 21104300 */  addu       $v0, $v0, $v1
    /* 3164 8006B964 0000448C */  lw         $a0, 0x0($v0)
    /* 3168 8006B968 00002326 */  addiu      $v1, $s1, %lo(D_1F800000)
    /* 316C 8006B96C 08008224 */  addiu      $v0, $a0, 0x8
    /* 3170 8006B970 080062AC */  sw         $v0, 0x8($v1)
    /* 3174 8006B974 48008224 */  addiu      $v0, $a0, 0x48
    /* 3178 8006B978 CFA2000C */  jal        ClearOTagR
    /* 317C 8006B97C 040062AC */   sw        $v0, 0x4($v1)
    /* 3180 8006B980 0680033C */  lui        $v1, %hi(D_8005E0C0)
    /* 3184 8006B984 C0E06324 */  addiu      $v1, $v1, %lo(D_8005E0C0)
    /* 3188 8006B988 10E2028E */  lw         $v0, %lo(vs_main_frameBuf)($s0)
    /* 318C 8006B98C 1800BF8F */  lw         $ra, 0x18($sp)
    /* 3190 8006B990 1000B08F */  lw         $s0, 0x10($sp)
    /* 3194 8006B994 80100200 */  sll        $v0, $v0, 2
    /* 3198 8006B998 21104300 */  addu       $v0, $v0, $v1
    /* 319C 8006B99C 0000428C */  lw         $v0, 0x0($v0)
    /* 31A0 8006B9A0 00000000 */  nop
    /* 31A4 8006B9A4 000022AE */  sw         $v0, (0x1F800000 & 0xFFFF)($s1)
    /* 31A8 8006B9A8 1400B18F */  lw         $s1, 0x14($sp)
    /* 31AC 8006B9AC 0800E003 */  jr         $ra
    /* 31B0 8006B9B0 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_8006B930
