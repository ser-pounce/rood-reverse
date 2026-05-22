nonmatching _loadMpdLootSection, 0x34

glabel _loadMpdLootSection
    /* 25EA8 8008E6A8 21288000 */  addu       $a1, $a0, $zero
    /* 25EAC 8008E6AC 0F80023C */  lui        $v0, %hi(vs_battle_roomData + 0xAC)
    /* 25EB0 8008E6B0 A41C448C */  lw         $a0, %lo(vs_battle_roomData + 0xAC)($v0)
    /* 25EB4 8008E6B4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 25EB8 8008E6B8 04008010 */  beqz       $a0, .L8008E6CC
    /* 25EBC 8008E6BC 1000BFAF */   sw        $ra, 0x10($sp)
    /* 25EC0 8008E6C0 14008424 */  addiu      $a0, $a0, 0x14
    /* 25EC4 8008E6C4 2C24010C */  jal        vs_main_memcpy
    /* 25EC8 8008E6C8 20020624 */   addiu     $a2, $zero, 0x220
  .L8008E6CC:
    /* 25ECC 8008E6CC 1000BF8F */  lw         $ra, 0x10($sp)
    /* 25ED0 8008E6D0 00000000 */  nop
    /* 25ED4 8008E6D4 0800E003 */  jr         $ra
    /* 25ED8 8008E6D8 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel _loadMpdLootSection
