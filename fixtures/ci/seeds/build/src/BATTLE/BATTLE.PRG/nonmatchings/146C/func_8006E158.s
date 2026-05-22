nonmatching func_8006E158, 0x4E8

glabel func_8006E158
    /* 5958 8006E158 0F80063C */  lui        $a2, %hi(vs_battle_cameraCurrentSpherical)
    /* 595C 8006E15C D019C724 */  addiu      $a3, $a2, %lo(vs_battle_cameraCurrentSpherical)
    /* 5960 8006E160 1000E58C */  lw         $a1, 0x10($a3)
    /* 5964 8006E164 00000000 */  nop
    /* 5968 8006E168 2500A014 */  bnez       $a1, .L8006E200
    /* 596C 8006E16C 01000224 */   addiu     $v0, $zero, 0x1
    /* 5970 8006E170 0F80023C */  lui        $v0, %hi(D_800F196C)
    /* 5974 8006E174 6C19438C */  lw         $v1, %lo(D_800F196C)($v0)
    /* 5978 8006E178 03000224 */  addiu      $v0, $zero, 0x3
    /* 597C 8006E17C 9C006210 */  beq        $v1, $v0, .L8006E3F0
    /* 5980 8006E180 02000424 */   addiu     $a0, $zero, 0x2
    /* 5984 8006E184 08006414 */  bne        $v1, $a0, .L8006E1A8
    /* 5988 8006E188 0680023C */   lui       $v0, %hi(vs_main_buttonsPreviousState)
    /* 598C 8006E18C 0F80023C */  lui        $v0, %hi(_cameraMode)
    /* 5990 8006E190 F018438C */  lw         $v1, %lo(_cameraMode)($v0)
    /* 5994 8006E194 04000224 */  addiu      $v0, $zero, 0x4
    /* 5998 8006E198 95006210 */  beq        $v1, $v0, .L8006E3F0
    /* 599C 8006E19C 0B000224 */   addiu     $v0, $zero, 0xB
    /* 59A0 8006E1A0 93006210 */  beq        $v1, $v0, .L8006E3F0
    /* 59A4 8006E1A4 0680023C */   lui       $v0, %hi(vs_main_buttonsPreviousState)
  .L8006E1A8:
    /* 59A8 8006E1A8 C0E1428C */  lw         $v0, %lo(vs_main_buttonsPreviousState)($v0)
    /* 59AC 8006E1AC 00000000 */  nop
    /* 59B0 8006E1B0 0C004330 */  andi       $v1, $v0, 0xC
    /* 59B4 8006E1B4 08000224 */  addiu      $v0, $zero, 0x8
    /* 59B8 8006E1B8 07006214 */  bne        $v1, $v0, .L8006E1D8
    /* 59BC 8006E1BC 00000000 */   nop
    /* 59C0 8006E1C0 D019C28C */  lw         $v0, %lo(vs_battle_cameraCurrentSpherical)($a2)
    /* 59C4 8006E1C4 01000324 */  addiu      $v1, $zero, 0x1
    /* 59C8 8006E1C8 1000E3AC */  sw         $v1, 0x10($a3)
    /* 59CC 8006E1CC 00FE0324 */  addiu      $v1, $zero, -0x200
    /* 59D0 8006E1D0 7DB80108 */  j          .L8006E1F4
    /* 59D4 8006E1D4 00FE4224 */   addiu     $v0, $v0, -0x200
  .L8006E1D8:
    /* 59D8 8006E1D8 04000224 */  addiu      $v0, $zero, 0x4
    /* 59DC 8006E1DC 85006214 */  bne        $v1, $v0, .L8006E3F4
    /* 59E0 8006E1E0 0680023C */   lui       $v0, %hi(vs_main_buttonsPressed)
    /* 59E4 8006E1E4 D019C28C */  lw         $v0, %lo(vs_battle_cameraCurrentSpherical)($a2)
    /* 59E8 8006E1E8 00FE0324 */  addiu      $v1, $zero, -0x200
    /* 59EC 8006E1EC 1000E4AC */  sw         $a0, 0x10($a3)
    /* 59F0 8006E1F0 00024224 */  addiu      $v0, $v0, 0x200
  .L8006E1F4:
    /* 59F4 8006E1F4 24104300 */  and        $v0, $v0, $v1
    /* 59F8 8006E1F8 FCB80108 */  j          .L8006E3F0
    /* 59FC 8006E1FC 1400E2AC */   sw        $v0, 0x14($a3)
  .L8006E200:
    /* 5A00 8006E200 0500A210 */  beq        $a1, $v0, .L8006E218
    /* 5A04 8006E204 02000224 */   addiu     $v0, $zero, 0x2
    /* 5A08 8006E208 3C00A210 */  beq        $a1, $v0, .L8006E2FC
    /* 5A0C 8006E20C 0680023C */   lui       $v0, %hi(vs_main_buttonsPressed)
    /* 5A10 8006E210 FDB80108 */  j          .L8006E3F4
    /* 5A14 8006E214 00000000 */   nop
  .L8006E218:
    /* 5A18 8006E218 D019C38C */  lw         $v1, %lo(vs_battle_cameraCurrentSpherical)($a2)
    /* 5A1C 8006E21C 1800E48C */  lw         $a0, 0x18($a3)
    /* 5A20 8006E220 1400E58C */  lw         $a1, 0x14($a3)
    /* 5A24 8006E224 23186400 */  subu       $v1, $v1, $a0
    /* 5A28 8006E228 7800A224 */  addiu      $v0, $a1, 0x78
    /* 5A2C 8006E22C 2A104300 */  slt        $v0, $v0, $v1
    /* 5A30 8006E230 22004014 */  bnez       $v0, .L8006E2BC
    /* 5A34 8006E234 D019C3AC */   sw        $v1, %lo(vs_battle_cameraCurrentSpherical)($a2)
    /* 5A38 8006E238 0680023C */  lui        $v0, %hi(vs_main_buttonsPreviousState)
    /* 5A3C 8006E23C C0E1428C */  lw         $v0, %lo(vs_main_buttonsPreviousState)($v0)
    /* 5A40 8006E240 08000324 */  addiu      $v1, $zero, 0x8
    /* 5A44 8006E244 0C004230 */  andi       $v0, $v0, 0xC
    /* 5A48 8006E248 13004314 */  bne        $v0, $v1, .L8006E298
    /* 5A4C 8006E24C 0F80023C */   lui       $v0, %hi(vs_battle_cameraCurrentSpherical)
    /* 5A50 8006E250 0F80023C */  lui        $v0, %hi(D_800F196C)
    /* 5A54 8006E254 6C19438C */  lw         $v1, %lo(D_800F196C)($v0)
    /* 5A58 8006E258 03000224 */  addiu      $v0, $zero, 0x3
    /* 5A5C 8006E25C 0D006210 */  beq        $v1, $v0, .L8006E294
    /* 5A60 8006E260 02000224 */   addiu     $v0, $zero, 0x2
    /* 5A64 8006E264 08006214 */  bne        $v1, $v0, .L8006E288
    /* 5A68 8006E268 00FEA224 */   addiu     $v0, $a1, -0x200
    /* 5A6C 8006E26C 0F80023C */  lui        $v0, %hi(_cameraMode)
    /* 5A70 8006E270 F018438C */  lw         $v1, %lo(_cameraMode)($v0)
    /* 5A74 8006E274 04000224 */  addiu      $v0, $zero, 0x4
    /* 5A78 8006E278 06006210 */  beq        $v1, $v0, .L8006E294
    /* 5A7C 8006E27C 0B000224 */   addiu     $v0, $zero, 0xB
    /* 5A80 8006E280 04006210 */  beq        $v1, $v0, .L8006E294
    /* 5A84 8006E284 00FEA224 */   addiu     $v0, $a1, -0x200
  .L8006E288:
    /* 5A88 8006E288 00FE0324 */  addiu      $v1, $zero, -0x200
    /* 5A8C 8006E28C 24104300 */  and        $v0, $v0, $v1
    /* 5A90 8006E290 1400E2AC */  sw         $v0, 0x14($a3)
  .L8006E294:
    /* 5A94 8006E294 0F80023C */  lui        $v0, %hi(vs_battle_cameraCurrentSpherical)
  .L8006E298:
    /* 5A98 8006E298 D0194424 */  addiu      $a0, $v0, %lo(vs_battle_cameraCurrentSpherical)
    /* 5A9C 8006E29C 1800838C */  lw         $v1, 0x18($a0)
    /* 5AA0 8006E2A0 00000000 */  nop
    /* 5AA4 8006E2A4 09006228 */  slti       $v0, $v1, 0x9
    /* 5AA8 8006E2A8 0E004014 */  bnez       $v0, .L8006E2E4
    /* 5AAC 8006E2AC 00000000 */   nop
    /* 5AB0 8006E2B0 F8FF6224 */  addiu      $v0, $v1, -0x8
    /* 5AB4 8006E2B4 B9B80108 */  j          .L8006E2E4
    /* 5AB8 8006E2B8 180082AC */   sw        $v0, 0x18($a0)
  .L8006E2BC:
    /* 5ABC 8006E2BC 28008228 */  slti       $v0, $a0, 0x28
    /* 5AC0 8006E2C0 08004010 */  beqz       $v0, .L8006E2E4
    /* 5AC4 8006E2C4 00000000 */   nop
    /* 5AC8 8006E2C8 08008224 */  addiu      $v0, $a0, 0x8
    /* 5ACC 8006E2CC 1800E2AC */  sw         $v0, 0x18($a3)
    /* 5AD0 8006E2D0 29004228 */  slti       $v0, $v0, 0x29
    /* 5AD4 8006E2D4 04004014 */  bnez       $v0, .L8006E2E8
    /* 5AD8 8006E2D8 0F80043C */   lui       $a0, %hi(vs_battle_cameraCurrentSpherical)
    /* 5ADC 8006E2DC 28000224 */  addiu      $v0, $zero, 0x28
    /* 5AE0 8006E2E0 1800E2AC */  sw         $v0, 0x18($a3)
  .L8006E2E4:
    /* 5AE4 8006E2E4 0F80043C */  lui        $a0, %hi(vs_battle_cameraCurrentSpherical)
  .L8006E2E8:
    /* 5AE8 8006E2E8 D0198524 */  addiu      $a1, $a0, %lo(vs_battle_cameraCurrentSpherical)
    /* 5AEC 8006E2EC D019838C */  lw         $v1, %lo(vs_battle_cameraCurrentSpherical)($a0)
    /* 5AF0 8006E2F0 1400A28C */  lw         $v0, 0x14($a1)
    /* 5AF4 8006E2F4 F7B80108 */  j          .L8006E3DC
    /* 5AF8 8006E2F8 2A104300 */   slt       $v0, $v0, $v1
  .L8006E2FC:
    /* 5AFC 8006E2FC D019C28C */  lw         $v0, %lo(vs_battle_cameraCurrentSpherical)($a2)
    /* 5B00 8006E300 1800E48C */  lw         $a0, 0x18($a3)
    /* 5B04 8006E304 1400E88C */  lw         $t0, 0x14($a3)
    /* 5B08 8006E308 21104400 */  addu       $v0, $v0, $a0
    /* 5B0C 8006E30C 88FF0325 */  addiu      $v1, $t0, -0x78
    /* 5B10 8006E310 D019C2AC */  sw         $v0, %lo(vs_battle_cameraCurrentSpherical)($a2)
    /* 5B14 8006E314 2A104300 */  slt        $v0, $v0, $v1
    /* 5B18 8006E318 22004014 */  bnez       $v0, .L8006E3A4
    /* 5B1C 8006E31C 28008228 */   slti      $v0, $a0, 0x28
    /* 5B20 8006E320 0680023C */  lui        $v0, %hi(vs_main_buttonsPreviousState)
    /* 5B24 8006E324 C0E1428C */  lw         $v0, %lo(vs_main_buttonsPreviousState)($v0)
    /* 5B28 8006E328 00000000 */  nop
    /* 5B2C 8006E32C 0C004430 */  andi       $a0, $v0, 0xC
    /* 5B30 8006E330 04000224 */  addiu      $v0, $zero, 0x4
    /* 5B34 8006E334 13008214 */  bne        $a0, $v0, .L8006E384
    /* 5B38 8006E338 0F80023C */   lui       $v0, %hi(vs_battle_cameraCurrentSpherical)
    /* 5B3C 8006E33C 0F80023C */  lui        $v0, %hi(D_800F196C)
    /* 5B40 8006E340 6C19438C */  lw         $v1, %lo(D_800F196C)($v0)
    /* 5B44 8006E344 03000224 */  addiu      $v0, $zero, 0x3
    /* 5B48 8006E348 0E006210 */  beq        $v1, $v0, .L8006E384
    /* 5B4C 8006E34C 0F80023C */   lui       $v0, %hi(vs_battle_cameraCurrentSpherical)
    /* 5B50 8006E350 08006514 */  bne        $v1, $a1, .L8006E374
    /* 5B54 8006E354 00020225 */   addiu     $v0, $t0, 0x200
    /* 5B58 8006E358 0F80023C */  lui        $v0, %hi(_cameraMode)
    /* 5B5C 8006E35C F018438C */  lw         $v1, %lo(_cameraMode)($v0)
    /* 5B60 8006E360 00000000 */  nop
    /* 5B64 8006E364 06006410 */  beq        $v1, $a0, .L8006E380
    /* 5B68 8006E368 0B000224 */   addiu     $v0, $zero, 0xB
    /* 5B6C 8006E36C 04006210 */  beq        $v1, $v0, .L8006E380
    /* 5B70 8006E370 00020225 */   addiu     $v0, $t0, 0x200
  .L8006E374:
    /* 5B74 8006E374 00FE0324 */  addiu      $v1, $zero, -0x200
    /* 5B78 8006E378 24104300 */  and        $v0, $v0, $v1
    /* 5B7C 8006E37C 1400E2AC */  sw         $v0, 0x14($a3)
  .L8006E380:
    /* 5B80 8006E380 0F80023C */  lui        $v0, %hi(vs_battle_cameraCurrentSpherical)
  .L8006E384:
    /* 5B84 8006E384 D0194424 */  addiu      $a0, $v0, %lo(vs_battle_cameraCurrentSpherical)
    /* 5B88 8006E388 1800838C */  lw         $v1, 0x18($a0)
    /* 5B8C 8006E38C 00000000 */  nop
    /* 5B90 8006E390 09006228 */  slti       $v0, $v1, 0x9
    /* 5B94 8006E394 0B004014 */  bnez       $v0, .L8006E3C4
    /* 5B98 8006E398 F8FF6224 */   addiu     $v0, $v1, -0x8
    /* 5B9C 8006E39C F1B80108 */  j          .L8006E3C4
    /* 5BA0 8006E3A0 180082AC */   sw        $v0, 0x18($a0)
  .L8006E3A4:
    /* 5BA4 8006E3A4 07004010 */  beqz       $v0, .L8006E3C4
    /* 5BA8 8006E3A8 08008224 */   addiu     $v0, $a0, 0x8
    /* 5BAC 8006E3AC 1800E2AC */  sw         $v0, 0x18($a3)
    /* 5BB0 8006E3B0 29004228 */  slti       $v0, $v0, 0x29
    /* 5BB4 8006E3B4 04004014 */  bnez       $v0, .L8006E3C8
    /* 5BB8 8006E3B8 0F80043C */   lui       $a0, %hi(vs_battle_cameraCurrentSpherical)
    /* 5BBC 8006E3BC 28000224 */  addiu      $v0, $zero, 0x28
    /* 5BC0 8006E3C0 1800E2AC */  sw         $v0, 0x18($a3)
  .L8006E3C4:
    /* 5BC4 8006E3C4 0F80043C */  lui        $a0, %hi(vs_battle_cameraCurrentSpherical)
  .L8006E3C8:
    /* 5BC8 8006E3C8 D0198524 */  addiu      $a1, $a0, %lo(vs_battle_cameraCurrentSpherical)
    /* 5BCC 8006E3CC D019838C */  lw         $v1, %lo(vs_battle_cameraCurrentSpherical)($a0)
    /* 5BD0 8006E3D0 1400A28C */  lw         $v0, 0x14($a1)
    /* 5BD4 8006E3D4 00000000 */  nop
    /* 5BD8 8006E3D8 2A106200 */  slt        $v0, $v1, $v0
  .L8006E3DC:
    /* 5BDC 8006E3DC 05004014 */  bnez       $v0, .L8006E3F4
    /* 5BE0 8006E3E0 0680023C */   lui       $v0, %hi(vs_main_buttonsPressed)
    /* 5BE4 8006E3E4 000E6230 */  andi       $v0, $v1, 0xE00
    /* 5BE8 8006E3E8 D01982AC */  sw         $v0, %lo(vs_battle_cameraCurrentSpherical)($a0)
    /* 5BEC 8006E3EC 1000A0AC */  sw         $zero, 0x10($a1)
  .L8006E3F0:
    /* 5BF0 8006E3F0 0680023C */  lui        $v0, %hi(vs_main_buttonsPressed)
  .L8006E3F4:
    /* 5BF4 8006E3F4 D0E1428C */  lw         $v0, %lo(vs_main_buttonsPressed)($v0)
    /* 5BF8 8006E3F8 00000000 */  nop
    /* 5BFC 8006E3FC 00014230 */  andi       $v0, $v0, 0x100
    /* 5C00 8006E400 26004010 */  beqz       $v0, .L8006E49C
    /* 5C04 8006E404 0F80023C */   lui       $v0, %hi(D_800F196C)
    /* 5C08 8006E408 6C19438C */  lw         $v1, %lo(D_800F196C)($v0)
    /* 5C0C 8006E40C 03000224 */  addiu      $v0, $zero, 0x3
    /* 5C10 8006E410 16006210 */  beq        $v1, $v0, .L8006E46C
    /* 5C14 8006E414 02000524 */   addiu     $a1, $zero, 0x2
    /* 5C18 8006E418 08006514 */  bne        $v1, $a1, .L8006E43C
    /* 5C1C 8006E41C 0F80023C */   lui       $v0, %hi(vs_battle_cameraCurrentSpherical)
    /* 5C20 8006E420 0F80023C */  lui        $v0, %hi(_cameraMode)
    /* 5C24 8006E424 F018438C */  lw         $v1, %lo(_cameraMode)($v0)
    /* 5C28 8006E428 04000224 */  addiu      $v0, $zero, 0x4
    /* 5C2C 8006E42C 0F006210 */  beq        $v1, $v0, .L8006E46C
    /* 5C30 8006E430 0B000224 */   addiu     $v0, $zero, 0xB
    /* 5C34 8006E434 0D006210 */  beq        $v1, $v0, .L8006E46C
    /* 5C38 8006E438 0F80023C */   lui       $v0, %hi(vs_battle_cameraCurrentSpherical)
  .L8006E43C:
    /* 5C3C 8006E43C D0194424 */  addiu      $a0, $v0, %lo(vs_battle_cameraCurrentSpherical)
    /* 5C40 8006E440 1C00838C */  lw         $v1, 0x1C($a0)
    /* 5C44 8006E444 00000000 */  nop
    /* 5C48 8006E448 08006004 */  bltz       $v1, .L8006E46C
    /* 5C4C 8006E44C 02006228 */   slti      $v0, $v1, 0x2
    /* 5C50 8006E450 03004010 */  beqz       $v0, .L8006E460
    /* 5C54 8006E454 04006228 */   slti      $v0, $v1, 0x4
    /* 5C58 8006E458 1BB90108 */  j          .L8006E46C
    /* 5C5C 8006E45C 1C0085AC */   sw        $a1, 0x1C($a0)
  .L8006E460:
    /* 5C60 8006E460 03004010 */  beqz       $v0, .L8006E470
    /* 5C64 8006E464 0F80023C */   lui       $v0, %hi(vs_battle_cameraCurrentSpherical)
    /* 5C68 8006E468 1C0080AC */  sw         $zero, 0x1C($a0)
  .L8006E46C:
    /* 5C6C 8006E46C 0F80023C */  lui        $v0, %hi(vs_battle_cameraCurrentSpherical)
  .L8006E470:
    /* 5C70 8006E470 D0194424 */  addiu      $a0, $v0, %lo(vs_battle_cameraCurrentSpherical)
    /* 5C74 8006E474 1C00838C */  lw         $v1, 0x1C($a0)
    /* 5C78 8006E478 00000000 */  nop
    /* 5C7C 8006E47C 07006004 */  bltz       $v1, .L8006E49C
    /* 5C80 8006E480 02006228 */   slti      $v0, $v1, 0x2
    /* 5C84 8006E484 04004014 */  bnez       $v0, .L8006E498
    /* 5C88 8006E488 00060224 */   addiu     $v0, $zero, 0x600
    /* 5C8C 8006E48C 04006228 */  slti       $v0, $v1, 0x4
    /* 5C90 8006E490 02004010 */  beqz       $v0, .L8006E49C
    /* 5C94 8006E494 00090224 */   addiu     $v0, $zero, 0x900
  .L8006E498:
    /* 5C98 8006E498 200082AC */  sw         $v0, 0x20($a0)
  .L8006E49C:
    /* 5C9C 8006E49C 0F80023C */  lui        $v0, %hi(vs_battle_cameraCurrentSpherical)
    /* 5CA0 8006E4A0 D0194424 */  addiu      $a0, $v0, %lo(vs_battle_cameraCurrentSpherical)
    /* 5CA4 8006E4A4 1C00838C */  lw         $v1, 0x1C($a0)
    /* 5CA8 8006E4A8 01000524 */  addiu      $a1, $zero, 0x1
    /* 5CAC 8006E4AC 05006510 */  beq        $v1, $a1, .L8006E4C4
    /* 5CB0 8006E4B0 02006228 */   slti      $v0, $v1, 0x2
    /* 5CB4 8006E4B4 05004010 */  beqz       $v0, .L8006E4CC
    /* 5CB8 8006E4B8 00000000 */   nop
    /* 5CBC 8006E4BC 08006010 */  beqz       $v1, .L8006E4E0
    /* 5CC0 8006E4C0 00000000 */   nop
  .L8006E4C4:
    /* 5CC4 8006E4C4 0800E003 */  jr         $ra
    /* 5CC8 8006E4C8 00000000 */   nop
  .L8006E4CC:
    /* 5CCC 8006E4CC 02000224 */  addiu      $v0, $zero, 0x2
    /* 5CD0 8006E4D0 2C006210 */  beq        $v1, $v0, .L8006E584
    /* 5CD4 8006E4D4 00000000 */   nop
    /* 5CD8 8006E4D8 0800E003 */  jr         $ra
    /* 5CDC 8006E4DC 00000000 */   nop
  .L8006E4E0:
    /* 5CE0 8006E4E0 0800838C */  lw         $v1, 0x8($a0)
    /* 5CE4 8006E4E4 00000000 */  nop
    /* 5CE8 8006E4E8 01066228 */  slti       $v0, $v1, 0x601
    /* 5CEC 8006E4EC 04004010 */  beqz       $v0, .L8006E500
    /* 5CF0 8006E4F0 00060224 */   addiu     $v0, $zero, 0x600
    /* 5CF4 8006E4F4 080082AC */  sw         $v0, 0x8($a0)
    /* 5CF8 8006E4F8 0800E003 */  jr         $ra
    /* 5CFC 8006E4FC 1C0085AC */   sw        $a1, 0x1C($a0)
  .L8006E500:
    /* 5D00 8006E500 2000828C */  lw         $v0, 0x20($a0)
    /* 5D04 8006E504 00000000 */  nop
    /* 5D08 8006E508 A0004224 */  addiu      $v0, $v0, 0xA0
    /* 5D0C 8006E50C 2A104300 */  slt        $v0, $v0, $v1
    /* 5D10 8006E510 0A004014 */  bnez       $v0, .L8006E53C
    /* 5D14 8006E514 00000000 */   nop
    /* 5D18 8006E518 2400838C */  lw         $v1, 0x24($a0)
    /* 5D1C 8006E51C 00000000 */  nop
    /* 5D20 8006E520 F0FF6228 */  slti       $v0, $v1, -0x10
    /* 5D24 8006E524 03004010 */  beqz       $v0, .L8006E534
    /* 5D28 8006E528 00000000 */   nop
    /* 5D2C 8006E52C 5AB90108 */  j          .L8006E568
    /* 5D30 8006E530 10006224 */   addiu     $v0, $v1, 0x10
  .L8006E534:
    /* 5D34 8006E534 5AB90108 */  j          .L8006E568
    /* 5D38 8006E538 F0FF0224 */   addiu     $v0, $zero, -0x10
  .L8006E53C:
    /* 5D3C 8006E53C 2400838C */  lw         $v1, 0x24($a0)
    /* 5D40 8006E540 00000000 */  nop
    /* 5D44 8006E544 C1FF6228 */  slti       $v0, $v1, -0x3F
    /* 5D48 8006E548 09004014 */  bnez       $v0, .L8006E570
    /* 5D4C 8006E54C 0F80023C */   lui       $v0, %hi(vs_battle_cameraCurrentSpherical)
    /* 5D50 8006E550 F0FF6224 */  addiu      $v0, $v1, -0x10
    /* 5D54 8006E554 240082AC */  sw         $v0, 0x24($a0)
    /* 5D58 8006E558 C0FF4228 */  slti       $v0, $v0, -0x40
    /* 5D5C 8006E55C 03004010 */  beqz       $v0, .L8006E56C
    /* 5D60 8006E560 00000000 */   nop
    /* 5D64 8006E564 C0FF0224 */  addiu      $v0, $zero, -0x40
  .L8006E568:
    /* 5D68 8006E568 240082AC */  sw         $v0, 0x24($a0)
  .L8006E56C:
    /* 5D6C 8006E56C 0F80023C */  lui        $v0, %hi(vs_battle_cameraCurrentSpherical)
  .L8006E570:
    /* 5D70 8006E570 D0194324 */  addiu      $v1, $v0, %lo(vs_battle_cameraCurrentSpherical)
    /* 5D74 8006E574 0800648C */  lw         $a0, 0x8($v1)
    /* 5D78 8006E578 2000628C */  lw         $v0, 0x20($v1)
    /* 5D7C 8006E57C 88B90108 */  j          .L8006E620
    /* 5D80 8006E580 2A104400 */   slt       $v0, $v0, $a0
  .L8006E584:
    /* 5D84 8006E584 0800838C */  lw         $v1, 0x8($a0)
    /* 5D88 8006E588 00000000 */  nop
    /* 5D8C 8006E58C 00096228 */  slti       $v0, $v1, 0x900
    /* 5D90 8006E590 05004014 */  bnez       $v0, .L8006E5A8
    /* 5D94 8006E594 00090224 */   addiu     $v0, $zero, 0x900
    /* 5D98 8006E598 080082AC */  sw         $v0, 0x8($a0)
    /* 5D9C 8006E59C 03000224 */  addiu      $v0, $zero, 0x3
    /* 5DA0 8006E5A0 0800E003 */  jr         $ra
    /* 5DA4 8006E5A4 1C0082AC */   sw        $v0, 0x1C($a0)
  .L8006E5A8:
    /* 5DA8 8006E5A8 2000828C */  lw         $v0, 0x20($a0)
    /* 5DAC 8006E5AC 00000000 */  nop
    /* 5DB0 8006E5B0 60FF4224 */  addiu      $v0, $v0, -0xA0
    /* 5DB4 8006E5B4 2A106200 */  slt        $v0, $v1, $v0
    /* 5DB8 8006E5B8 08004014 */  bnez       $v0, .L8006E5DC
    /* 5DBC 8006E5BC 00000000 */   nop
    /* 5DC0 8006E5C0 2400838C */  lw         $v1, 0x24($a0)
    /* 5DC4 8006E5C4 00000000 */  nop
    /* 5DC8 8006E5C8 11006228 */  slti       $v0, $v1, 0x11
    /* 5DCC 8006E5CC 0D004014 */  bnez       $v0, .L8006E604
    /* 5DD0 8006E5D0 10000224 */   addiu     $v0, $zero, 0x10
    /* 5DD4 8006E5D4 81B90108 */  j          .L8006E604
    /* 5DD8 8006E5D8 F0FF6224 */   addiu     $v0, $v1, -0x10
  .L8006E5DC:
    /* 5DDC 8006E5DC 2400838C */  lw         $v1, 0x24($a0)
    /* 5DE0 8006E5E0 00000000 */  nop
    /* 5DE4 8006E5E4 40006228 */  slti       $v0, $v1, 0x40
    /* 5DE8 8006E5E8 07004010 */  beqz       $v0, .L8006E608
    /* 5DEC 8006E5EC 10006224 */   addiu     $v0, $v1, 0x10
    /* 5DF0 8006E5F0 240082AC */  sw         $v0, 0x24($a0)
    /* 5DF4 8006E5F4 41004228 */  slti       $v0, $v0, 0x41
    /* 5DF8 8006E5F8 04004014 */  bnez       $v0, .L8006E60C
    /* 5DFC 8006E5FC 0F80023C */   lui       $v0, %hi(vs_battle_cameraCurrentSpherical)
    /* 5E00 8006E600 40000224 */  addiu      $v0, $zero, 0x40
  .L8006E604:
    /* 5E04 8006E604 240082AC */  sw         $v0, 0x24($a0)
  .L8006E608:
    /* 5E08 8006E608 0F80023C */  lui        $v0, %hi(vs_battle_cameraCurrentSpherical)
  .L8006E60C:
    /* 5E0C 8006E60C D0194324 */  addiu      $v1, $v0, %lo(vs_battle_cameraCurrentSpherical)
    /* 5E10 8006E610 0800648C */  lw         $a0, 0x8($v1)
    /* 5E14 8006E614 2000628C */  lw         $v0, 0x20($v1)
    /* 5E18 8006E618 00000000 */  nop
    /* 5E1C 8006E61C 2A108200 */  slt        $v0, $a0, $v0
  .L8006E620:
    /* 5E20 8006E620 05004010 */  beqz       $v0, .L8006E638
    /* 5E24 8006E624 00000000 */   nop
    /* 5E28 8006E628 2400628C */  lw         $v0, 0x24($v1)
    /* 5E2C 8006E62C 00000000 */  nop
    /* 5E30 8006E630 21108200 */  addu       $v0, $a0, $v0
    /* 5E34 8006E634 080062AC */  sw         $v0, 0x8($v1)
  .L8006E638:
    /* 5E38 8006E638 0800E003 */  jr         $ra
    /* 5E3C 8006E63C 00000000 */   nop
endlabel func_8006E158
