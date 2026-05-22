nonmatching func_80092A18, 0xEC

glabel func_80092A18
    /* 2A218 80092A18 0F80033C */  lui        $v1, %hi(D_800F225B)
    /* 2A21C 80092A1C 5B226290 */  lbu        $v0, %lo(D_800F225B)($v1)
    /* 2A220 80092A20 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 2A224 80092A24 2000BFAF */  sw         $ra, 0x20($sp)
    /* 2A228 80092A28 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 2A22C 80092A2C 1800B2AF */  sw         $s2, 0x18($sp)
    /* 2A230 80092A30 1400B1AF */  sw         $s1, 0x14($sp)
    /* 2A234 80092A34 03004014 */  bnez       $v0, .L80092A44
    /* 2A238 80092A38 1000B0AF */   sw        $s0, 0x10($sp)
    /* 2A23C 80092A3C BA4A0208 */  j          .L80092AE8
    /* 2A240 80092A40 21100000 */   addu      $v0, $zero, $zero
  .L80092A44:
    /* 2A244 80092A44 5B226290 */  lbu        $v0, %lo(D_800F225B)($v1)
    /* 2A248 80092A48 00000000 */  nop
    /* 2A24C 80092A4C 17004010 */  beqz       $v0, .L80092AAC
    /* 2A250 80092A50 21800000 */   addu      $s0, $zero, $zero
    /* 2A254 80092A54 0F80023C */  lui        $v0, %hi(D_800F1DD8)
    /* 2A258 80092A58 D81D5324 */  addiu      $s3, $v0, %lo(D_800F1DD8)
    /* 2A25C 80092A5C 21906000 */  addu       $s2, $v1, $zero
    /* 2A260 80092A60 00031124 */  addiu      $s1, $zero, 0x300
  .L80092A64:
    /* 2A264 80092A64 21283302 */  addu       $a1, $s1, $s3
    /* 2A268 80092A68 0000A290 */  lbu        $v0, 0x0($a1)
    /* 2A26C 80092A6C 00000000 */  nop
    /* 2A270 80092A70 06004014 */  bnez       $v0, .L80092A8C
    /* 2A274 80092A74 00000000 */   nop
    /* 2A278 80092A78 0400A38C */  lw         $v1, 0x4($a1)
    /* 2A27C 80092A7C 0800A28C */  lw         $v0, 0x8($a1)
    /* 2A280 80092A80 00000000 */  nop
    /* 2A284 80092A84 04006210 */  beq        $v1, $v0, .L80092A98
    /* 2A288 80092A88 00000000 */   nop
  .L80092A8C:
    /* 2A28C 80092A8C 0400A48C */  lw         $a0, 0x4($a1)
    /* 2A290 80092A90 540F010C */  jal        vs_main_freeHeap
    /* 2A294 80092A94 0000A0A0 */   sb        $zero, 0x0($a1)
  .L80092A98:
    /* 2A298 80092A98 5B224292 */  lbu        $v0, %lo(D_800F225B)($s2)
    /* 2A29C 80092A9C 01001026 */  addiu      $s0, $s0, 0x1
    /* 2A2A0 80092AA0 2A100202 */  slt        $v0, $s0, $v0
    /* 2A2A4 80092AA4 EFFF4014 */  bnez       $v0, .L80092A64
    /* 2A2A8 80092AA8 0C003126 */   addiu     $s1, $s1, 0xC
  .L80092AAC:
    /* 2A2AC 80092AAC 0F80113C */  lui        $s1, %hi(D_800F2258)
    /* 2A2B0 80092AB0 58222686 */  lh         $a2, %lo(D_800F2258)($s1)
    /* 2A2B4 80092AB4 FFFF1024 */  addiu      $s0, $zero, -0x1
    /* 2A2B8 80092AB8 0800D010 */  beq        $a2, $s0, .L80092ADC
    /* 2A2BC 80092ABC 0F80023C */   lui       $v0, %hi(vs_battle_roomData + 0xB0)
    /* 2A2C0 80092AC0 A81C458C */  lw         $a1, %lo(vs_battle_roomData + 0xB0)($v0)
    /* 2A2C4 80092AC4 00000000 */  nop
    /* 2A2C8 80092AC8 0500A010 */  beqz       $a1, .L80092AE0
    /* 2A2CC 80092ACC 0F80023C */   lui       $v0, %hi(D_800F225B)
    /* 2A2D0 80092AD0 1319010C */  jal        func_8004644C
    /* 2A2D4 80092AD4 00020424 */   addiu     $a0, $zero, 0x200
    /* 2A2D8 80092AD8 582230A6 */  sh         $s0, %lo(D_800F2258)($s1)
  .L80092ADC:
    /* 2A2DC 80092ADC 0F80023C */  lui        $v0, %hi(D_800F225B)
  .L80092AE0:
    /* 2A2E0 80092AE0 5B2240A0 */  sb         $zero, %lo(D_800F225B)($v0)
    /* 2A2E4 80092AE4 01000224 */  addiu      $v0, $zero, 0x1
  .L80092AE8:
    /* 2A2E8 80092AE8 2000BF8F */  lw         $ra, 0x20($sp)
    /* 2A2EC 80092AEC 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 2A2F0 80092AF0 1800B28F */  lw         $s2, 0x18($sp)
    /* 2A2F4 80092AF4 1400B18F */  lw         $s1, 0x14($sp)
    /* 2A2F8 80092AF8 1000B08F */  lw         $s0, 0x10($sp)
    /* 2A2FC 80092AFC 0800E003 */  jr         $ra
    /* 2A300 80092B00 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_80092A18
