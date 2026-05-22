nonmatching Sound_Cmd_30_unk, 0x80

glabel Sound_Cmd_30_unk
    /* 7A54 80017254 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 7A58 80017258 1800B0AF */  sw         $s0, 0x18($sp)
    /* 7A5C 8001725C 21808000 */  addu       $s0, $a0, $zero
    /* 7A60 80017260 1000A427 */  addiu      $a0, $sp, 0x10
    /* 7A64 80017264 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 7A68 80017268 0000068E */  lw         $a2, 0x0($s0)
    /* 7A6C 8001726C 3E5A000C */  jal        Sound_GetProgramCounters
    /* 7A70 80017270 1400A527 */   addiu     $a1, $sp, 0x14
    /* 7A74 80017274 0002023C */  lui        $v0, (0x2000000 >> 16)
    /* 7A78 80017278 040002AE */  sw         $v0, 0x4($s0)
    /* 7A7C 8001727C 80000224 */  addiu      $v0, $zero, 0x80
    /* 7A80 80017280 080002AE */  sw         $v0, 0x8($s0)
    /* 7A84 80017284 7F000224 */  addiu      $v0, $zero, 0x7F
    /* 7A88 80017288 0380033C */  lui        $v1, %hi(g_Sound_SfxMetadataTable)
    /* 7A8C 8001728C 0C0002AE */  sw         $v0, 0xC($s0)
    /* 7A90 80017290 0000028E */  lw         $v0, 0x0($s0)
    /* 7A94 80017294 F477638C */  lw         $v1, %lo(g_Sound_SfxMetadataTable)($v1)
    /* 7A98 80017298 40100200 */  sll        $v0, $v0, 1
    /* 7A9C 8001729C 21104300 */  addu       $v0, $v0, $v1
    /* 7AA0 800172A0 00004494 */  lhu        $a0, 0x0($v0)
    /* 7AA4 800172A4 6A5B000C */  jal        func_80016DA8
    /* 7AA8 800172A8 00000000 */   nop
    /* 7AAC 800172AC 21200002 */  addu       $a0, $s0, $zero
    /* 7AB0 800172B0 1000A58F */  lw         $a1, 0x10($sp)
    /* 7AB4 800172B4 1400A68F */  lw         $a2, 0x14($sp)
    /* 7AB8 800172B8 21380000 */  addu       $a3, $zero, $zero
    /* 7ABC 800172BC D159000C */  jal        Sound_PlaySfxProgram
    /* 7AC0 800172C0 100082AC */   sw        $v0, 0x10($a0)
    /* 7AC4 800172C4 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 7AC8 800172C8 1800B08F */  lw         $s0, 0x18($sp)
    /* 7ACC 800172CC 0800E003 */  jr         $ra
    /* 7AD0 800172D0 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel Sound_Cmd_30_unk
