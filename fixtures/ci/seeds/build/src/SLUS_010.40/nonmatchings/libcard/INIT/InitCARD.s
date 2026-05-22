nonmatching InitCARD, 0x90

glabel InitCARD
    /* 1F134 8002E934 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 1F138 8002E938 1000B0AF */  sw         $s0, 0x10($sp)
    /* 1F13C 8002E93C 21808000 */  addu       $s0, $a0, $zero
    /* 1F140 8002E940 21200000 */  addu       $a0, $zero, $zero
    /* 1F144 8002E944 1800BFAF */  sw         $ra, 0x18($sp)
    /* 1F148 8002E948 819A000C */  jal        ChangeClearPAD
    /* 1F14C 8002E94C 1400B1AF */   sw        $s1, 0x14($sp)
    /* 1F150 8002E950 B17D000C */  jal        VSync
    /* 1F154 8002E954 21200000 */   addu      $a0, $zero, $zero
    /* 1F158 8002E958 5D9A000C */  jal        EnterCriticalSection
    /* 1F15C 8002E95C 00000000 */   nop
    /* 1F160 8002E960 90BA000C */  jal        ReadInitPadFlag
    /* 1F164 8002E964 21884000 */   addu      $s1, $v0, $zero
    /* 1F168 8002E968 02004014 */  bnez       $v0, .L8002E974
    /* 1F16C 8002E96C 00000000 */   nop
    /* 1F170 8002E970 21800000 */  addu       $s0, $zero, $zero
  .L8002E974:
    /* 1F174 8002E974 A1BB000C */  jal        InitCARD2
    /* 1F178 8002E978 21200002 */   addu      $a0, $s0, $zero
    /* 1F17C 8002E97C 25BC000C */  jal        _copy_memcard_patch
    /* 1F180 8002E980 00000000 */   nop
    /* 1F184 8002E984 E4BB000C */  jal        _patch_card
    /* 1F188 8002E988 00000000 */   nop
    /* 1F18C 8002E98C 09BC000C */  jal        _patch_card2
    /* 1F190 8002E990 00000000 */   nop
    /* 1F194 8002E994 ADBB000C */  jal        _patch_card_info
    /* 1F198 8002E998 00000000 */   nop
    /* 1F19C 8002E99C 01000224 */  addiu      $v0, $zero, 0x1
    /* 1F1A0 8002E9A0 03002216 */  bne        $s1, $v0, .L8002E9B0
    /* 1F1A4 8002E9A4 00000000 */   nop
    /* 1F1A8 8002E9A8 619A000C */  jal        ExitCriticalSection
    /* 1F1AC 8002E9AC 00000000 */   nop
  .L8002E9B0:
    /* 1F1B0 8002E9B0 1800BF8F */  lw         $ra, 0x18($sp)
    /* 1F1B4 8002E9B4 1400B18F */  lw         $s1, 0x14($sp)
    /* 1F1B8 8002E9B8 1000B08F */  lw         $s0, 0x10($sp)
    /* 1F1BC 8002E9BC 0800E003 */  jr         $ra
    /* 1F1C0 8002E9C0 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel InitCARD
