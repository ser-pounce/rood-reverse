nonmatching SoundVM_CB_DisableVoiceModes, 0x68

glabel SoundVM_CB_DisableVoiceModes
    /* D314 8001CB14 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* D318 8001CB18 1000B0AF */  sw         $s0, 0x10($sp)
    /* D31C 8001CB1C 21808000 */  addu       $s0, $a0, $zero
    /* D320 8001CB20 1400B1AF */  sw         $s1, 0x14($sp)
    /* D324 8001CB24 2188A000 */  addu       $s1, $a1, $zero
    /* D328 8001CB28 1800BFAF */  sw         $ra, 0x18($sp)
    /* D32C 8001CB2C 3400028E */  lw         $v0, 0x34($s0)
    /* D330 8001CB30 C8FF0324 */  addiu      $v1, $zero, -0x38
    /* D334 8001CB34 24104300 */  and        $v0, $v0, $v1
    /* D338 8001CB38 5A70000C */  jal        SoundVM_C5_DisableNoiseVoices
    /* D33C 8001CB3C 340002AE */   sw        $v0, 0x34($s0)
    /* D340 8001CB40 21200002 */  addu       $a0, $s0, $zero
    /* D344 8001CB44 9170000C */  jal        SoundVM_C7_DisableFmVoices
    /* D348 8001CB48 21282002 */   addu      $a1, $s1, $zero
    /* D34C 8001CB4C 21200002 */  addu       $a0, $s0, $zero
    /* D350 8001CB50 C370000C */  jal        SoundVM_C3_DisableReverbVoices
    /* D354 8001CB54 21282002 */   addu      $a1, $s1, $zero
    /* D358 8001CB58 9C000296 */  lhu        $v0, 0x9C($s0)
    /* D35C 8001CB5C 00000000 */  nop
    /* D360 8001CB60 FAFF4230 */  andi       $v0, $v0, 0xFFFA
    /* D364 8001CB64 9C0002A6 */  sh         $v0, 0x9C($s0)
    /* D368 8001CB68 1800BF8F */  lw         $ra, 0x18($sp)
    /* D36C 8001CB6C 1400B18F */  lw         $s1, 0x14($sp)
    /* D370 8001CB70 1000B08F */  lw         $s0, 0x10($sp)
    /* D374 8001CB74 0800E003 */  jr         $ra
    /* D378 8001CB78 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel SoundVM_CB_DisableVoiceModes
