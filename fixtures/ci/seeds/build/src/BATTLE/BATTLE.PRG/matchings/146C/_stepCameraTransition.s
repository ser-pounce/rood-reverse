nonmatching _stepCameraTransition, 0x24C

glabel _stepCameraTransition
    /* 6A04 8006F204 0F80023C */  lui        $v0, %hi(vs_battle_cameraTransition)
    /* 6A08 8006F208 0419448C */  lw         $a0, %lo(vs_battle_cameraTransition)($v0)
    /* 6A0C 8006F20C D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 6A10 8006F210 2400BFAF */  sw         $ra, 0x24($sp)
    /* 6A14 8006F214 2000B0AF */  sw         $s0, 0x20($sp)
    /* 6A18 8006F218 C800838C */  lw         $v1, 0xC8($a0)
    /* 6A1C 8006F21C F000828C */  lw         $v0, 0xF0($a0)
    /* 6A20 8006F220 00000000 */  nop
    /* 6A24 8006F224 18006200 */  mult       $v1, $v0
    /* 6A28 8006F228 A800848C */  lw         $a0, 0xA8($a0)
    /* 6A2C 8006F22C 801F023C */  lui        $v0, (0x1F800038 >> 16)
    /* 6A30 8006F230 00F00324 */  addiu      $v1, $zero, -0x1000
    /* 6A34 8006F234 3800428C */  lw         $v0, (0x1F800038 & 0xFFFF)($v0)
    /* 6A38 8006F238 24208300 */  and        $a0, $a0, $v1
    /* 6A3C 8006F23C 24284300 */  and        $a1, $v0, $v1
    /* 6A40 8006F240 12380000 */  mflo       $a3
    /* 6A44 8006F244 21104700 */  addu       $v0, $v0, $a3
    /* 6A48 8006F248 24184300 */  and        $v1, $v0, $v1
    /* 6A4C 8006F24C 2A10A400 */  slt        $v0, $a1, $a0
    /* 6A50 8006F250 04004014 */  bnez       $v0, .L8006F264
    /* 6A54 8006F254 2A108500 */   slt       $v0, $a0, $a1
    /* 6A58 8006F258 2A108300 */  slt        $v0, $a0, $v1
    /* 6A5C 8006F25C 06004010 */  beqz       $v0, .L8006F278
    /* 6A60 8006F260 2A108500 */   slt       $v0, $a0, $a1
  .L8006F264:
    /* 6A64 8006F264 3A004014 */  bnez       $v0, .L8006F350
    /* 6A68 8006F268 0F80103C */   lui       $s0, %hi(vs_battle_cameraTransition)
    /* 6A6C 8006F26C 2A106400 */  slt        $v0, $v1, $a0
    /* 6A70 8006F270 37004014 */  bnez       $v0, .L8006F350
    /* 6A74 8006F274 00000000 */   nop
  .L8006F278:
    /* 6A78 8006F278 0F80023C */  lui        $v0, %hi(vs_battle_cameraTransition)
    /* 6A7C 8006F27C 0419438C */  lw         $v1, %lo(vs_battle_cameraTransition)($v0)
    /* 6A80 8006F280 801F043C */  lui        $a0, %hi(D_1F800000)
    /* 6A84 8006F284 A400628C */  lw         $v0, 0xA4($v1)
    /* 6A88 8006F288 00008424 */  addiu      $a0, $a0, %lo(D_1F800000)
    /* 6A8C 8006F28C 340082AC */  sw         $v0, 0x34($a0)
    /* 6A90 8006F290 AC00628C */  lw         $v0, 0xAC($v1)
    /* 6A94 8006F294 00000000 */  nop
    /* 6A98 8006F298 3C0082AC */  sw         $v0, 0x3C($a0)
    /* 6A9C 8006F29C A800628C */  lw         $v0, 0xA8($v1)
    /* 6AA0 8006F2A0 00000000 */  nop
    /* 6AA4 8006F2A4 380082AC */  sw         $v0, 0x38($a0)
    /* 6AA8 8006F2A8 0F80023C */  lui        $v0, %hi(vs_battle_cameraCurrentSpherical)
    /* 6AAC 8006F2AC B400658C */  lw         $a1, 0xB4($v1)
    /* 6AB0 8006F2B0 D0194624 */  addiu      $a2, $v0, %lo(vs_battle_cameraCurrentSpherical)
    /* 6AB4 8006F2B4 440085AC */  sw         $a1, 0x44($a0)
    /* 6AB8 8006F2B8 BC00628C */  lw         $v0, 0xBC($v1)
    /* 6ABC 8006F2BC 6C006524 */  addiu      $a1, $v1, 0x6C
    /* 6AC0 8006F2C0 4C0082AC */  sw         $v0, 0x4C($a0)
    /* 6AC4 8006F2C4 B800628C */  lw         $v0, 0xB8($v1)
    /* 6AC8 8006F2C8 8C006324 */  addiu      $v1, $v1, 0x8C
    /* 6ACC 8006F2CC 480082AC */  sw         $v0, 0x48($a0)
  .L8006F2D0:
    /* 6AD0 8006F2D0 0000A88C */  lw         $t0, 0x0($a1)
    /* 6AD4 8006F2D4 0400A98C */  lw         $t1, 0x4($a1)
    /* 6AD8 8006F2D8 0800AA8C */  lw         $t2, 0x8($a1)
    /* 6ADC 8006F2DC 0C00A78C */  lw         $a3, 0xC($a1)
    /* 6AE0 8006F2E0 0000C8AC */  sw         $t0, 0x0($a2)
    /* 6AE4 8006F2E4 0400C9AC */  sw         $t1, 0x4($a2)
    /* 6AE8 8006F2E8 0800CAAC */  sw         $t2, 0x8($a2)
    /* 6AEC 8006F2EC 0C00C7AC */  sw         $a3, 0xC($a2)
    /* 6AF0 8006F2F0 1000A524 */  addiu      $a1, $a1, 0x10
    /* 6AF4 8006F2F4 F6FFA314 */  bne        $a1, $v1, .L8006F2D0
    /* 6AF8 8006F2F8 1000C624 */   addiu     $a2, $a2, 0x10
    /* 6AFC 8006F2FC 0F80103C */  lui        $s0, %hi(vs_battle_cameraTransition)
    /* 6B00 8006F300 0419048E */  lw         $a0, %lo(vs_battle_cameraTransition)($s0)
    /* 6B04 8006F304 0000A88C */  lw         $t0, 0x0($a1)
    /* 6B08 8006F308 0400A98C */  lw         $t1, 0x4($a1)
    /* 6B0C 8006F30C 0800AA8C */  lw         $t2, 0x8($a1)
    /* 6B10 8006F310 0000C8AC */  sw         $t0, 0x0($a2)
    /* 6B14 8006F314 0400C9AC */  sw         $t1, 0x4($a2)
    /* 6B18 8006F318 0800CAAC */  sw         $t2, 0x8($a2)
    /* 6B1C 8006F31C A000838C */  lw         $v1, 0xA0($a0)
    /* 6B20 8006F320 801F023C */  lui        $v0, (0x1F800064 >> 16)
    /* 6B24 8006F324 640043AC */  sw         $v1, (0x1F800064 & 0xFFFF)($v0)
    /* 6B28 8006F328 9800848C */  lw         $a0, 0x98($a0)
    /* 6B2C 8006F32C 33F3010C */  jal        vs_battle_setNearClip
    /* 6B30 8006F330 00000000 */   nop
    /* 6B34 8006F334 0419028E */  lw         $v0, %lo(vs_battle_cameraTransition)($s0)
    /* 6B38 8006F338 00000000 */  nop
    /* 6B3C 8006F33C 9C00448C */  lw         $a0, 0x9C($v0)
    /* 6B40 8006F340 3CF3010C */  jal        vs_battle_setProjectionDistance
    /* 6B44 8006F344 00000000 */   nop
    /* 6B48 8006F348 10BD0108 */  j          .L8006F440
    /* 6B4C 8006F34C 01000224 */   addiu     $v0, $zero, 0x1
  .L8006F350:
    /* 6B50 8006F350 0419058E */  lw         $a1, %lo(vs_battle_cameraTransition)($s0)
    /* 6B54 8006F354 00000000 */  nop
    /* 6B58 8006F358 C400A38C */  lw         $v1, 0xC4($a1)
    /* 6B5C 8006F35C F000A28C */  lw         $v0, 0xF0($a1)
    /* 6B60 8006F360 00000000 */  nop
    /* 6B64 8006F364 18006200 */  mult       $v1, $v0
    /* 6B68 8006F368 801F033C */  lui        $v1, %hi(D_1F800000)
    /* 6B6C 8006F36C 00006324 */  addiu      $v1, $v1, %lo(D_1F800000)
    /* 6B70 8006F370 3400628C */  lw         $v0, 0x34($v1)
    /* 6B74 8006F374 12380000 */  mflo       $a3
    /* 6B78 8006F378 21104700 */  addu       $v0, $v0, $a3
    /* 6B7C 8006F37C 340062AC */  sw         $v0, 0x34($v1)
    /* 6B80 8006F380 CC00A48C */  lw         $a0, 0xCC($a1)
    /* 6B84 8006F384 F000A28C */  lw         $v0, 0xF0($a1)
    /* 6B88 8006F388 00000000 */  nop
    /* 6B8C 8006F38C 18008200 */  mult       $a0, $v0
    /* 6B90 8006F390 3C00628C */  lw         $v0, 0x3C($v1)
    /* 6B94 8006F394 12380000 */  mflo       $a3
    /* 6B98 8006F398 21104700 */  addu       $v0, $v0, $a3
    /* 6B9C 8006F39C 3C0062AC */  sw         $v0, 0x3C($v1)
    /* 6BA0 8006F3A0 C800A48C */  lw         $a0, 0xC8($a1)
    /* 6BA4 8006F3A4 F000A28C */  lw         $v0, 0xF0($a1)
    /* 6BA8 8006F3A8 00000000 */  nop
    /* 6BAC 8006F3AC 18008200 */  mult       $a0, $v0
    /* 6BB0 8006F3B0 3800628C */  lw         $v0, 0x38($v1)
    /* 6BB4 8006F3B4 12380000 */  mflo       $a3
    /* 6BB8 8006F3B8 21104700 */  addu       $v0, $v0, $a3
    /* 6BBC 8006F3BC 380062AC */  sw         $v0, 0x38($v1)
    /* 6BC0 8006F3C0 4400628C */  lw         $v0, 0x44($v1)
    /* 6BC4 8006F3C4 D400A48C */  lw         $a0, 0xD4($a1)
    /* 6BC8 8006F3C8 00000000 */  nop
    /* 6BCC 8006F3CC 21104400 */  addu       $v0, $v0, $a0
    /* 6BD0 8006F3D0 440062AC */  sw         $v0, 0x44($v1)
    /* 6BD4 8006F3D4 4C00628C */  lw         $v0, 0x4C($v1)
    /* 6BD8 8006F3D8 DC00A48C */  lw         $a0, 0xDC($a1)
    /* 6BDC 8006F3DC 00000000 */  nop
    /* 6BE0 8006F3E0 21104400 */  addu       $v0, $v0, $a0
    /* 6BE4 8006F3E4 4C0062AC */  sw         $v0, 0x4C($v1)
    /* 6BE8 8006F3E8 4800628C */  lw         $v0, 0x48($v1)
    /* 6BEC 8006F3EC D800A48C */  lw         $a0, 0xD8($a1)
    /* 6BF0 8006F3F0 00000000 */  nop
    /* 6BF4 8006F3F4 21104400 */  addu       $v0, $v0, $a0
    /* 6BF8 8006F3F8 480062AC */  sw         $v0, 0x48($v1)
    /* 6BFC 8006F3FC 6400628C */  lw         $v0, 0x64($v1)
    /* 6C00 8006F400 E400A48C */  lw         $a0, 0xE4($a1)
    /* 6C04 8006F404 00000000 */  nop
    /* 6C08 8006F408 21104400 */  addu       $v0, $v0, $a0
    /* 6C0C 8006F40C 640062AC */  sw         $v0, 0x64($v1)
    /* 6C10 8006F410 0680023C */  lui        $v0, %hi(vs_main_nearClip)
    /* 6C14 8006F414 C8E0428C */  lw         $v0, %lo(vs_main_nearClip)($v0)
    /* 6C18 8006F418 E800A48C */  lw         $a0, 0xE8($a1)
    /* 6C1C 8006F41C 33F3010C */  jal        vs_battle_setNearClip
    /* 6C20 8006F420 21204400 */   addu      $a0, $v0, $a0
    /* 6C24 8006F424 0680023C */  lui        $v0, %hi(vs_main_projectionDistance)
    /* 6C28 8006F428 0419038E */  lw         $v1, %lo(vs_battle_cameraTransition)($s0)
    /* 6C2C 8006F42C 48E2428C */  lw         $v0, %lo(vs_main_projectionDistance)($v0)
    /* 6C30 8006F430 EC00648C */  lw         $a0, 0xEC($v1)
    /* 6C34 8006F434 3CF3010C */  jal        vs_battle_setProjectionDistance
    /* 6C38 8006F438 21204400 */   addu      $a0, $v0, $a0
    /* 6C3C 8006F43C 21100000 */  addu       $v0, $zero, $zero
  .L8006F440:
    /* 6C40 8006F440 2400BF8F */  lw         $ra, 0x24($sp)
    /* 6C44 8006F444 2000B08F */  lw         $s0, 0x20($sp)
    /* 6C48 8006F448 0800E003 */  jr         $ra
    /* 6C4C 8006F44C 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel _stepCameraTransition
