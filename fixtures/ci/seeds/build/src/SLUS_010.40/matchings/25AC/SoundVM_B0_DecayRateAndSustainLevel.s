nonmatching SoundVM_B0_DecayRateAndSustainLevel, 0x3C

glabel SoundVM_B0_DecayRateAndSustainLevel
    /* D1F0 8001C9F0 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* D1F4 8001C9F4 1000B0AF */  sw         $s0, 0x10($sp)
    /* D1F8 8001C9F8 21808000 */  addu       $s0, $a0, $zero
    /* D1FC 8001C9FC 1400B1AF */  sw         $s1, 0x14($sp)
    /* D200 8001CA00 1800BFAF */  sw         $ra, 0x18($sp)
    /* D204 8001CA04 2171000C */  jal        SoundVM_AE_DecayRate
    /* D208 8001CA08 2188A000 */   addu      $s1, $a1, $zero
    /* D20C 8001CA0C 21200002 */  addu       $a0, $s0, $zero
    /* D210 8001CA10 2E71000C */  jal        SoundVM_AF_SustainLevel
    /* D214 8001CA14 21282002 */   addu      $a1, $s1, $zero
    /* D218 8001CA18 1800BF8F */  lw         $ra, 0x18($sp)
    /* D21C 8001CA1C 1400B18F */  lw         $s1, 0x14($sp)
    /* D220 8001CA20 1000B08F */  lw         $s0, 0x10($sp)
    /* D224 8001CA24 0800E003 */  jr         $ra
    /* D228 8001CA28 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel SoundVM_B0_DecayRateAndSustainLevel
