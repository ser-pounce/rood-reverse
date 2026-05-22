nonmatching StartCARD, 0x48

glabel StartCARD
    /* 1F1C4 8002E9C4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1F1C8 8002E9C8 1400BFAF */  sw         $ra, 0x14($sp)
    /* 1F1CC 8002E9CC 5D9A000C */  jal        EnterCriticalSection
    /* 1F1D0 8002E9D0 1000B0AF */   sw        $s0, 0x10($sp)
    /* 1F1D4 8002E9D4 A5BB000C */  jal        StartCARD2
    /* 1F1D8 8002E9D8 21804000 */   addu      $s0, $v0, $zero
    /* 1F1DC 8002E9DC 819A000C */  jal        ChangeClearPAD
    /* 1F1E0 8002E9E0 21200000 */   addu      $a0, $zero, $zero
    /* 1F1E4 8002E9E4 01000224 */  addiu      $v0, $zero, 0x1
    /* 1F1E8 8002E9E8 04000216 */  bne        $s0, $v0, .L8002E9FC
    /* 1F1EC 8002E9EC 21100000 */   addu      $v0, $zero, $zero
    /* 1F1F0 8002E9F0 619A000C */  jal        ExitCriticalSection
    /* 1F1F4 8002E9F4 00000000 */   nop
    /* 1F1F8 8002E9F8 21100000 */  addu       $v0, $zero, $zero
  .L8002E9FC:
    /* 1F1FC 8002E9FC 1400BF8F */  lw         $ra, 0x14($sp)
    /* 1F200 8002EA00 1000B08F */  lw         $s0, 0x10($sp)
    /* 1F204 8002EA04 0800E003 */  jr         $ra
    /* 1F208 8002EA08 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel StartCARD
