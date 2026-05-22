nonmatching _removeActorAtIndex, 0x10C

glabel _removeActorAtIndex
    /* 1A28 8006A228 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 1A2C 8006A22C 1400B1AF */  sw         $s1, 0x14($sp)
    /* 1A30 8006A230 21888000 */  addu       $s1, $a0, $zero
    /* 1A34 8006A234 1000222E */  sltiu      $v0, $s1, 0x10
    /* 1A38 8006A238 1800BFAF */  sw         $ra, 0x18($sp)
    /* 1A3C 8006A23C 37004010 */  beqz       $v0, .L8006A31C
    /* 1A40 8006A240 1000B0AF */   sw        $s0, 0x10($sp)
    /* 1A44 8006A244 0F80033C */  lui        $v1, %hi(vs_battle_actors)
    /* 1A48 8006A248 28196324 */  addiu      $v1, $v1, %lo(vs_battle_actors)
    /* 1A4C 8006A24C 80101100 */  sll        $v0, $s1, 2
    /* 1A50 8006A250 21104300 */  addu       $v0, $v0, $v1
    /* 1A54 8006A254 0000508C */  lw         $s0, 0x0($v0)
    /* 1A58 8006A258 00000000 */  nop
    /* 1A5C 8006A25C 30000012 */  beqz       $s0, .L8006A320
    /* 1A60 8006A260 01000224 */   addiu     $v0, $zero, 0x1
    /* 1A64 8006A264 F1A7010C */  jal        func_80069FC4
    /* 1A68 8006A268 00000000 */   nop
    /* 1A6C 8006A26C 1C000396 */  lhu        $v1, 0x1C($s0)
    /* 1A70 8006A270 10000224 */  addiu      $v0, $zero, 0x10
    /* 1A74 8006A274 0A006214 */  bne        $v1, $v0, .L8006A2A0
    /* 1A78 8006A278 00000000 */   nop
    /* 1A7C 8006A27C 4C7D020C */  jal        func_8009F530
    /* 1A80 8006A280 21202002 */   addu      $a0, $s1, $zero
    /* 1A84 8006A284 5B67020C */  jal        func_80099D6C
    /* 1A88 8006A288 21202002 */   addu      $a0, $s1, $zero
    /* 1A8C 8006A28C B0A80108 */  j          .L8006A2C0
    /* 1A90 8006A290 00000000 */   nop
  .L8006A294:
    /* 1A94 8006A294 0000028E */  lw         $v0, 0x0($s0)
    /* 1A98 8006A298 BEA80108 */  j          .L8006A2F8
    /* 1A9C 8006A29C 000062AC */   sw        $v0, 0x0($v1)
  .L8006A2A0:
    /* 1AA0 8006A2A0 EC73020C */  jal        func_8009CFB0
    /* 1AA4 8006A2A4 21202002 */   addu      $a0, $s1, $zero
    /* 1AA8 8006A2A8 4000038E */  lw         $v1, 0x40($s0)
    /* 1AAC 8006A2AC 02000224 */  addiu      $v0, $zero, 0x2
    /* 1AB0 8006A2B0 03006214 */  bne        $v1, $v0, .L8006A2C0
    /* 1AB4 8006A2B4 00000000 */   nop
    /* 1AB8 8006A2B8 EC73020C */  jal        func_8009CFB0
    /* 1ABC 8006A2BC 04002426 */   addiu     $a0, $s1, 0x4
  .L8006A2C0:
    /* 1AC0 8006A2C0 159D030C */  jal        func_800E7454
    /* 1AC4 8006A2C4 21200002 */   addu      $a0, $s0, $zero
    /* 1AC8 8006A2C8 21280000 */  addu       $a1, $zero, $zero
    /* 1ACC 8006A2CC 0F80023C */  lui        $v0, %hi(vs_battle_actors)
    /* 1AD0 8006A2D0 28194424 */  addiu      $a0, $v0, %lo(vs_battle_actors)
  .L8006A2D4:
    /* 1AD4 8006A2D4 0000838C */  lw         $v1, 0x0($a0)
    /* 1AD8 8006A2D8 00000000 */  nop
    /* 1ADC 8006A2DC 0000628C */  lw         $v0, 0x0($v1)
    /* 1AE0 8006A2E0 00000000 */  nop
    /* 1AE4 8006A2E4 EBFF5010 */  beq        $v0, $s0, .L8006A294
    /* 1AE8 8006A2E8 0100A524 */   addiu     $a1, $a1, 0x1
    /* 1AEC 8006A2EC 1000A228 */  slti       $v0, $a1, 0x10
    /* 1AF0 8006A2F0 F8FF4014 */  bnez       $v0, .L8006A2D4
    /* 1AF4 8006A2F4 04008424 */   addiu     $a0, $a0, 0x4
  .L8006A2F8:
    /* 1AF8 8006A2F8 540F010C */  jal        vs_main_freeHeap
    /* 1AFC 8006A2FC 21200002 */   addu      $a0, $s0, $zero
    /* 1B00 8006A300 0F80033C */  lui        $v1, %hi(vs_battle_actors)
    /* 1B04 8006A304 28196324 */  addiu      $v1, $v1, %lo(vs_battle_actors)
    /* 1B08 8006A308 80101100 */  sll        $v0, $s1, 2
    /* 1B0C 8006A30C 21104300 */  addu       $v0, $v0, $v1
    /* 1B10 8006A310 000040AC */  sw         $zero, 0x0($v0)
    /* 1B14 8006A314 C8A80108 */  j          .L8006A320
    /* 1B18 8006A318 01000224 */   addiu     $v0, $zero, 0x1
  .L8006A31C:
    /* 1B1C 8006A31C 21100000 */  addu       $v0, $zero, $zero
  .L8006A320:
    /* 1B20 8006A320 1800BF8F */  lw         $ra, 0x18($sp)
    /* 1B24 8006A324 1400B18F */  lw         $s1, 0x14($sp)
    /* 1B28 8006A328 1000B08F */  lw         $s0, 0x10($sp)
    /* 1B2C 8006A32C 0800E003 */  jr         $ra
    /* 1B30 8006A330 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel _removeActorAtIndex
