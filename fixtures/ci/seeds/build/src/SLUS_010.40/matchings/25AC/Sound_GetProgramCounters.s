nonmatching Sound_GetProgramCounters, 0x6C

glabel Sound_GetProgramCounters
    /* 70F8 800168F8 21508000 */  addu       $t2, $a0, $zero
    /* 70FC 800168FC FF03C630 */  andi       $a2, $a2, 0x3FF
    /* 7100 80016900 40300600 */  sll        $a2, $a2, 1
    /* 7104 80016904 0380043C */  lui        $a0, %hi(g_Sound_SfxProgramData)
    /* 7108 80016908 0380023C */  lui        $v0, %hi(g_Sound_SfxProgramOffsets)
    /* 710C 8001690C EC77498C */  lw         $t1, %lo(g_Sound_SfxProgramOffsets)($v0)
    /* 7110 80016910 40100600 */  sll        $v0, $a2, 1
    /* 7114 80016914 FFFF0334 */  ori        $v1, $zero, 0xFFFF
    /* 7118 80016918 21384900 */  addu       $a3, $v0, $t1
    /* 711C 8001691C 0000E294 */  lhu        $v0, 0x0($a3)
    /* 7120 80016920 F877888C */  lw         $t0, %lo(g_Sound_SfxProgramData)($a0)
    /* 7124 80016924 02004314 */  bne        $v0, $v1, .L80016930
    /* 7128 80016928 21100201 */   addu      $v0, $t0, $v0
    /* 712C 8001692C 21100000 */  addu       $v0, $zero, $zero
  .L80016930:
    /* 7130 80016930 0100C624 */  addiu      $a2, $a2, 0x1
    /* 7134 80016934 000042AD */  sw         $v0, 0x0($t2)
    /* 7138 80016938 40100600 */  sll        $v0, $a2, 1
    /* 713C 8001693C 21204900 */  addu       $a0, $v0, $t1
    /* 7140 80016940 00008394 */  lhu        $v1, 0x0($a0)
    /* 7144 80016944 FFFF0234 */  ori        $v0, $zero, 0xFFFF
    /* 7148 80016948 03006210 */  beq        $v1, $v0, .L80016958
    /* 714C 8001694C 21106000 */   addu      $v0, $v1, $zero
    /* 7150 80016950 575A0008 */  j          .L8001695C
    /* 7154 80016954 21100201 */   addu      $v0, $t0, $v0
  .L80016958:
    /* 7158 80016958 21100000 */  addu       $v0, $zero, $zero
  .L8001695C:
    /* 715C 8001695C 0800E003 */  jr         $ra
    /* 7160 80016960 0000A2AC */   sw        $v0, 0x0($a1)
endlabel Sound_GetProgramCounters
