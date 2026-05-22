nonmatching Sound_Cmd_20_unk, 0x68

glabel Sound_Cmd_20_unk
    /* 7AD4 800172D4 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 7AD8 800172D8 1800B0AF */  sw         $s0, 0x18($sp)
    /* 7ADC 800172DC 21808000 */  addu       $s0, $a0, $zero
    /* 7AE0 800172E0 1000A427 */  addiu      $a0, $sp, 0x10
    /* 7AE4 800172E4 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 7AE8 800172E8 0000068E */  lw         $a2, 0x0($s0)
    /* 7AEC 800172EC 3E5A000C */  jal        Sound_GetProgramCounters
    /* 7AF0 800172F0 1400A527 */   addiu     $a1, $sp, 0x14
    /* 7AF4 800172F4 0380033C */  lui        $v1, %hi(g_Sound_SfxMetadataTable)
    /* 7AF8 800172F8 0000028E */  lw         $v0, 0x0($s0)
    /* 7AFC 800172FC F477638C */  lw         $v1, %lo(g_Sound_SfxMetadataTable)($v1)
    /* 7B00 80017300 40100200 */  sll        $v0, $v0, 1
    /* 7B04 80017304 21104300 */  addu       $v0, $v0, $v1
    /* 7B08 80017308 00004494 */  lhu        $a0, 0x0($v0)
    /* 7B0C 8001730C 6A5B000C */  jal        func_80016DA8
    /* 7B10 80017310 00000000 */   nop
    /* 7B14 80017314 21200002 */  addu       $a0, $s0, $zero
    /* 7B18 80017318 1000A58F */  lw         $a1, 0x10($sp)
    /* 7B1C 8001731C 1400A68F */  lw         $a2, 0x14($sp)
    /* 7B20 80017320 21380000 */  addu       $a3, $zero, $zero
    /* 7B24 80017324 D159000C */  jal        Sound_PlaySfxProgram
    /* 7B28 80017328 100082AC */   sw        $v0, 0x10($a0)
    /* 7B2C 8001732C 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 7B30 80017330 1800B08F */  lw         $s0, 0x18($sp)
    /* 7B34 80017334 0800E003 */  jr         $ra
    /* 7B38 80017338 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel Sound_Cmd_20_unk
