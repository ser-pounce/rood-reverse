nonmatching func_8006F954, 0xB0

glabel func_8006F954
    /* 7154 8006F954 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 7158 8006F958 21200000 */  addu       $a0, $zero, $zero
    /* 715C 8006F95C 1000BFAF */  sw         $ra, 0x10($sp)
    /* 7160 8006F960 297B000C */  jal        SpuSetCommonMasterVolume
    /* 7164 8006F964 21288000 */   addu      $a1, $a0, $zero
    /* 7168 8006F968 0E80023C */  lui        $v0, %hi(_introMoviePlaying)
    /* 716C 8006F96C 21200000 */  addu       $a0, $zero, $zero
    /* 7170 8006F970 0BC8010C */  jal        DecDCToutCallback
    /* 7174 8006F974 7CED40AC */   sw        $zero, %lo(_introMoviePlaying)($v0)
    /* 7178 8006F978 6588000C */  jal        StUnSetRing
    /* 717C 8006F97C 00000000 */   nop
    /* 7180 8006F980 09000424 */  addiu      $a0, $zero, 0x9
  .L8006F984:
    /* 7184 8006F984 21280000 */  addu       $a1, $zero, $zero
    /* 7188 8006F988 F996000C */  jal        DsControlB
    /* 718C 8006F98C 2130A000 */   addu      $a2, $a1, $zero
    /* 7190 8006F990 FCFF4010 */  beqz       $v0, .L8006F984
    /* 7194 8006F994 09000424 */   addiu     $a0, $zero, 0x9
    /* 7198 8006F998 0F80023C */  lui        $v0, %hi(_decodedDataBuf1)
    /* 719C 8006F99C F4FD448C */  lw         $a0, %lo(_decodedDataBuf1)($v0)
    /* 71A0 8006F9A0 540F010C */  jal        vs_main_freeHeap
    /* 71A4 8006F9A4 00000000 */   nop
    /* 71A8 8006F9A8 0F80023C */  lui        $v0, %hi(_decodedDataBuf0)
    /* 71AC 8006F9AC F0FD448C */  lw         $a0, %lo(_decodedDataBuf0)($v0)
    /* 71B0 8006F9B0 540F010C */  jal        vs_main_freeHeap
    /* 71B4 8006F9B4 00000000 */   nop
    /* 71B8 8006F9B8 0F80023C */  lui        $v0, %hi(_encodedDataBuf1)
    /* 71BC 8006F9BC ECFD448C */  lw         $a0, %lo(_encodedDataBuf1)($v0)
    /* 71C0 8006F9C0 540F010C */  jal        vs_main_freeHeap
    /* 71C4 8006F9C4 00000000 */   nop
    /* 71C8 8006F9C8 0F80023C */  lui        $v0, %hi(_encodedDataBuf0)
    /* 71CC 8006F9CC E8FD448C */  lw         $a0, %lo(_encodedDataBuf0)($v0)
    /* 71D0 8006F9D0 540F010C */  jal        vs_main_freeHeap
    /* 71D4 8006F9D4 00000000 */   nop
    /* 71D8 8006F9D8 0E80023C */  lui        $v0, %hi(_movieRingBuf)
    /* 71DC 8006F9DC E0ED448C */  lw         $a0, %lo(_movieRingBuf)($v0)
    /* 71E0 8006F9E0 540F010C */  jal        vs_main_freeHeap
    /* 71E4 8006F9E4 00000000 */   nop
    /* 71E8 8006F9E8 FF3F0424 */  addiu      $a0, $zero, 0x3FFF
    /* 71EC 8006F9EC 297B000C */  jal        SpuSetCommonMasterVolume
    /* 71F0 8006F9F0 21288000 */   addu      $a1, $a0, $zero
    /* 71F4 8006F9F4 1000BF8F */  lw         $ra, 0x10($sp)
    /* 71F8 8006F9F8 00000000 */  nop
    /* 71FC 8006F9FC 0800E003 */  jr         $ra
    /* 7200 8006FA00 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8006F954
