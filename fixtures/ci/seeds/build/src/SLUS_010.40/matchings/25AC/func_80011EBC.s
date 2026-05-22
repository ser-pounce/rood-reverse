nonmatching func_80011EBC, 0x4C

glabel func_80011EBC
    /* 26BC 80011EBC 0380023C */  lui        $v0, %hi(g_pActiveMusicConfig)
    /* 26C0 80011EC0 2078438C */  lw         $v1, %lo(g_pActiveMusicConfig)($v0)
    /* 26C4 80011EC4 00000000 */  nop
    /* 26C8 80011EC8 6E006294 */  lhu        $v0, 0x6E($v1)
    /* 26CC 80011ECC 00000000 */  nop
    /* 26D0 80011ED0 0A004410 */  beq        $v0, $a0, .L80011EFC
    /* 26D4 80011ED4 21280000 */   addu      $a1, $zero, $zero
    /* 26D8 80011ED8 0380023C */  lui        $v0, %hi(g_pSavedMousicConfig)
    /* 26DC 80011EDC 2866438C */  lw         $v1, %lo(g_pSavedMousicConfig)($v0)
    /* 26E0 80011EE0 00000000 */  nop
    /* 26E4 80011EE4 06006010 */  beqz       $v1, .L80011F00
    /* 26E8 80011EE8 00000000 */   nop
    /* 26EC 80011EEC 6E006294 */  lhu        $v0, 0x6E($v1)
    /* 26F0 80011EF0 00000000 */  nop
    /* 26F4 80011EF4 02004414 */  bne        $v0, $a0, .L80011F00
    /* 26F8 80011EF8 00000000 */   nop
  .L80011EFC:
    /* 26FC 80011EFC 62006584 */  lh         $a1, 0x62($v1)
  .L80011F00:
    /* 2700 80011F00 0800E003 */  jr         $ra
    /* 2704 80011F04 2110A000 */   addu      $v0, $a1, $zero
endlabel func_80011EBC
