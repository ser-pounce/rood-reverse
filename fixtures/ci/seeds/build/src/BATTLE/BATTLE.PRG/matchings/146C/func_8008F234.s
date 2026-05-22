nonmatching func_8008F234, 0x68

glabel func_8008F234
    /* 26A34 8008F234 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 26A38 8008F238 1000B0AF */  sw         $s0, 0x10($sp)
    /* 26A3C 8008F23C 0F80103C */  lui        $s0, %hi(D_800F1DCC)
    /* 26A40 8008F240 CC1D028E */  lw         $v0, %lo(D_800F1DCC)($s0)
    /* 26A44 8008F244 0F80033C */  lui        $v1, %hi(D_800F1DC9)
    /* 26A48 8008F248 1400BFAF */  sw         $ra, 0x14($sp)
    /* 26A4C 8008F24C 03004014 */  bnez       $v0, .L8008F25C
    /* 26A50 8008F250 C91D60A0 */   sb        $zero, %lo(D_800F1DC9)($v1)
    /* 26A54 8008F254 A33C0208 */  j          .L8008F28C
    /* 26A58 8008F258 21100000 */   addu      $v0, $zero, $zero
  .L8008F25C:
    /* 26A5C 8008F25C 0F80023C */  lui        $v0, %hi(D_800F1DC8)
    /* 26A60 8008F260 C81D4490 */  lbu        $a0, %lo(D_800F1DC8)($v0)
    /* 26A64 8008F264 0F80023C */  lui        $v0, %hi(D_800F1DBE)
    /* 26A68 8008F268 BE1D4584 */  lh         $a1, %lo(D_800F1DBE)($v0)
    /* 26A6C 8008F26C 05000624 */  addiu      $a2, $zero, 0x5
    /* 26A70 8008F270 2AF8010C */  jal        func_8007E0A8
    /* 26A74 8008F274 C91D60A0 */   sb        $zero, %lo(D_800F1DC9)($v1)
    /* 26A78 8008F278 CC1D048E */  lw         $a0, %lo(D_800F1DCC)($s0)
    /* 26A7C 8008F27C 180F010C */  jal        vs_main_freeHeapR
    /* 26A80 8008F280 00000000 */   nop
    /* 26A84 8008F284 01000224 */  addiu      $v0, $zero, 0x1
    /* 26A88 8008F288 CC1D00AE */  sw         $zero, %lo(D_800F1DCC)($s0)
  .L8008F28C:
    /* 26A8C 8008F28C 1400BF8F */  lw         $ra, 0x14($sp)
    /* 26A90 8008F290 1000B08F */  lw         $s0, 0x10($sp)
    /* 26A94 8008F294 0800E003 */  jr         $ra
    /* 26A98 8008F298 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8008F234
