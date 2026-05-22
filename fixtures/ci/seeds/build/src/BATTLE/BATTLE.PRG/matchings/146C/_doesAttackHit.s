nonmatching _doesAttackHit, 0x204

glabel _doesAttackHit
    /* 16A30 8007F230 D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 16A34 8007F234 2000B2AF */  sw         $s2, 0x20($sp)
    /* 16A38 8007F238 21908000 */  addu       $s2, $a0, $zero
    /* 16A3C 8007F23C 2800B4AF */  sw         $s4, 0x28($sp)
    /* 16A40 8007F240 21A0A000 */  addu       $s4, $a1, $zero
    /* 16A44 8007F244 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 16A48 8007F248 2188C000 */  addu       $s1, $a2, $zero
    /* 16A4C 8007F24C 2C00BFAF */  sw         $ra, 0x2C($sp)
    /* 16A50 8007F250 2400B3AF */  sw         $s3, 0x24($sp)
    /* 16A54 8007F254 1800B0AF */  sw         $s0, 0x18($sp)
    /* 16A58 8007F258 4000228E */  lw         $v0, 0x40($s1)
    /* 16A5C 8007F25C 00000000 */  nop
    /* 16A60 8007F260 10004014 */  bnez       $v0, .L8007F2A4
    /* 16A64 8007F264 2198E000 */   addu      $s3, $a3, $zero
    /* 16A68 8007F268 0F80033C */  lui        $v1, %hi(vs_battle_actors)
    /* 16A6C 8007F26C 00002292 */  lbu        $v0, 0x0($s1)
    /* 16A70 8007F270 28196324 */  addiu      $v1, $v1, %lo(vs_battle_actors)
    /* 16A74 8007F274 80100200 */  sll        $v0, $v0, 2
    /* 16A78 8007F278 21104300 */  addu       $v0, $v0, $v1
    /* 16A7C 8007F27C 0000428C */  lw         $v0, 0x0($v0)
    /* 16A80 8007F280 00000000 */  nop
    /* 16A84 8007F284 3C00428C */  lw         $v0, 0x3C($v0)
    /* 16A88 8007F288 00000000 */  nop
    /* 16A8C 8007F28C 57094390 */  lbu        $v1, 0x957($v0)
    /* 16A90 8007F290 80000224 */  addiu      $v0, $zero, 0x80
    /* 16A94 8007F294 04006214 */  bne        $v1, $v0, .L8007F2A8
    /* 16A98 8007F298 80101300 */   sll       $v0, $s3, 2
    /* 16A9C 8007F29C CFFC0108 */  j          .L8007F33C
    /* 16AA0 8007F2A0 64001024 */   addiu     $s0, $zero, 0x64
  .L8007F2A4:
    /* 16AA4 8007F2A4 80101300 */  sll        $v0, $s3, 2
  .L8007F2A8:
    /* 16AA8 8007F2A8 21104202 */  addu       $v0, $s2, $v0
    /* 16AAC 8007F2AC 21204002 */  addu       $a0, $s2, $zero
    /* 16AB0 8007F2B0 21288002 */  addu       $a1, $s4, $zero
    /* 16AB4 8007F2B4 1400428C */  lw         $v0, 0x14($v0)
    /* 16AB8 8007F2B8 4000A38F */  lw         $v1, 0x40($sp)
    /* 16ABC 8007F2BC 21302002 */  addu       $a2, $s1, $zero
    /* 16AC0 8007F2C0 1000A3AF */  sw         $v1, 0x10($sp)
    /* 16AC4 8007F2C4 0F80033C */  lui        $v1, %hi(_hitFunctions)
    /* 16AC8 8007F2C8 34826324 */  addiu      $v1, $v1, %lo(_hitFunctions)
    /* 16ACC 8007F2CC C2120200 */  srl        $v0, $v0, 11
    /* 16AD0 8007F2D0 1C004230 */  andi       $v0, $v0, 0x1C
    /* 16AD4 8007F2D4 21104300 */  addu       $v0, $v0, $v1
    /* 16AD8 8007F2D8 0000428C */  lw         $v0, 0x0($v0)
    /* 16ADC 8007F2DC 00000000 */  nop
    /* 16AE0 8007F2E0 09F84000 */  jalr       $v0
    /* 16AE4 8007F2E4 21386002 */   addu      $a3, $s3, $zero
    /* 16AE8 8007F2E8 21804000 */  addu       $s0, $v0, $zero
    /* 16AEC 8007F2EC 0000428E */  lw         $v0, 0x0($s2)
    /* 16AF0 8007F2F0 0E00033C */  lui        $v1, (0xE0000 >> 16)
    /* 16AF4 8007F2F4 24104300 */  and        $v0, $v0, $v1
    /* 16AF8 8007F2F8 0200033C */  lui        $v1, (0x20000 >> 16)
    /* 16AFC 8007F2FC 10004314 */  bne        $v0, $v1, .L8007F340
    /* 16B00 8007F300 0F80023C */   lui       $v0, %hi(D_800F1A00)
    /* 16B04 8007F304 0F80033C */  lui        $v1, %hi(vs_battle_actors)
    /* 16B08 8007F308 00002292 */  lbu        $v0, 0x0($s1)
    /* 16B0C 8007F30C 28196324 */  addiu      $v1, $v1, %lo(vs_battle_actors)
    /* 16B10 8007F310 80100200 */  sll        $v0, $v0, 2
    /* 16B14 8007F314 21104300 */  addu       $v0, $v0, $v1
    /* 16B18 8007F318 0000428C */  lw         $v0, 0x0($v0)
    /* 16B1C 8007F31C 00000000 */  nop
    /* 16B20 8007F320 3C00428C */  lw         $v0, 0x3C($v0)
    /* 16B24 8007F324 00000000 */  nop
    /* 16B28 8007F328 4809428C */  lw         $v0, 0x948($v0)
    /* 16B2C 8007F32C 00000000 */  nop
    /* 16B30 8007F330 03004104 */  bgez       $v0, .L8007F340
    /* 16B34 8007F334 0F80023C */   lui       $v0, %hi(D_800F1A00)
    /* 16B38 8007F338 21800000 */  addu       $s0, $zero, $zero
  .L8007F33C:
    /* 16B3C 8007F33C 0F80023C */  lui        $v0, %hi(D_800F1A00)
  .L8007F340:
    /* 16B40 8007F340 001A428C */  lw         $v0, %lo(D_800F1A00)($v0)
    /* 16B44 8007F344 00000000 */  nop
    /* 16B48 8007F348 02004014 */  bnez       $v0, .L8007F354
    /* 16B4C 8007F34C FF000224 */   addiu     $v0, $zero, 0xFF
    /* 16B50 8007F350 FF001024 */  addiu      $s0, $zero, 0xFF
  .L8007F354:
    /* 16B54 8007F354 18000212 */  beq        $s0, $v0, .L8007F3B8
    /* 16B58 8007F358 00000000 */   nop
    /* 16B5C 8007F35C 4000228E */  lw         $v0, 0x40($s1)
    /* 16B60 8007F360 00000000 */  nop
    /* 16B64 8007F364 11004014 */  bnez       $v0, .L8007F3AC
    /* 16B68 8007F368 6500022A */   slti      $v0, $s0, 0x65
    /* 16B6C 8007F36C 0F80033C */  lui        $v1, %hi(vs_battle_actors)
    /* 16B70 8007F370 00002292 */  lbu        $v0, 0x0($s1)
    /* 16B74 8007F374 28196324 */  addiu      $v1, $v1, %lo(vs_battle_actors)
    /* 16B78 8007F378 80100200 */  sll        $v0, $v0, 2
    /* 16B7C 8007F37C 21104300 */  addu       $v0, $v0, $v1
    /* 16B80 8007F380 0000428C */  lw         $v0, 0x0($v0)
    /* 16B84 8007F384 00000000 */  nop
    /* 16B88 8007F388 3C00428C */  lw         $v0, 0x3C($v0)
    /* 16B8C 8007F38C 00000000 */  nop
    /* 16B90 8007F390 4809428C */  lw         $v0, 0x948($v0)
    /* 16B94 8007F394 00000000 */  nop
    /* 16B98 8007F398 04004230 */  andi       $v0, $v0, 0x4
    /* 16B9C 8007F39C 03004010 */  beqz       $v0, .L8007F3AC
    /* 16BA0 8007F3A0 6500022A */   slti      $v0, $s0, 0x65
    /* 16BA4 8007F3A4 40801000 */  sll        $s0, $s0, 1
    /* 16BA8 8007F3A8 6500022A */  slti       $v0, $s0, 0x65
  .L8007F3AC:
    /* 16BAC 8007F3AC 02004014 */  bnez       $v0, .L8007F3B8
    /* 16BB0 8007F3B0 00000000 */   nop
    /* 16BB4 8007F3B4 64001024 */  addiu      $s0, $zero, 0x64
  .L8007F3B8:
    /* 16BB8 8007F3B8 05006012 */  beqz       $s3, .L8007F3D0
    /* 16BBC 8007F3BC FF000224 */   addiu     $v0, $zero, 0xFF
    /* 16BC0 8007F3C0 02002392 */  lbu        $v1, 0x2($s1)
    /* 16BC4 8007F3C4 00000000 */  nop
    /* 16BC8 8007F3C8 02006214 */  bne        $v1, $v0, .L8007F3D4
    /* 16BCC 8007F3CC 00000000 */   nop
  .L8007F3D0:
    /* 16BD0 8007F3D0 020030A2 */  sb         $s0, 0x2($s1)
  .L8007F3D4:
    /* 16BD4 8007F3D4 EA09010C */  jal        vs_main_getRand
    /* 16BD8 8007F3D8 64000424 */   addiu     $a0, $zero, 0x64
    /* 16BDC 8007F3DC 21184000 */  addu       $v1, $v0, $zero
    /* 16BE0 8007F3E0 FF000224 */  addiu      $v0, $zero, 0xFF
    /* 16BE4 8007F3E4 0B000212 */  beq        $s0, $v0, .L8007F414
    /* 16BE8 8007F3E8 21100000 */   addu      $v0, $zero, $zero
    /* 16BEC 8007F3EC 4000828E */  lw         $v0, 0x40($s4)
    /* 16BF0 8007F3F0 00000000 */  nop
    /* 16BF4 8007F3F4 07004014 */  bnez       $v0, .L8007F414
    /* 16BF8 8007F3F8 2A107000 */   slt       $v0, $v1, $s0
    /* 16BFC 8007F3FC 00008292 */  lbu        $v0, 0x0($s4)
    /* 16C00 8007F400 00000000 */  nop
    /* 16C04 8007F404 03004014 */  bnez       $v0, .L8007F414
    /* 16C08 8007F408 2A107000 */   slt       $v0, $v1, $s0
    /* 16C0C 8007F40C 0A001026 */  addiu      $s0, $s0, 0xA
    /* 16C10 8007F410 2A107000 */  slt        $v0, $v1, $s0
  .L8007F414:
    /* 16C14 8007F414 2C00BF8F */  lw         $ra, 0x2C($sp)
    /* 16C18 8007F418 2800B48F */  lw         $s4, 0x28($sp)
    /* 16C1C 8007F41C 2400B38F */  lw         $s3, 0x24($sp)
    /* 16C20 8007F420 2000B28F */  lw         $s2, 0x20($sp)
    /* 16C24 8007F424 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 16C28 8007F428 1800B08F */  lw         $s0, 0x18($sp)
    /* 16C2C 8007F42C 0800E003 */  jr         $ra
    /* 16C30 8007F430 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel _doesAttackHit
