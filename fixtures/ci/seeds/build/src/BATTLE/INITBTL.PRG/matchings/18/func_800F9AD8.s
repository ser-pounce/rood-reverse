nonmatching func_800F9AD8, 0x1F4

glabel func_800F9AD8
    /* 2D8 800F9AD8 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 2DC 800F9ADC 0F80023C */  lui        $v0, %hi(vs_battle_characterState)
    /* 2E0 800F9AE0 FC19428C */  lw         $v0, %lo(vs_battle_characterState)($v0)
    /* 2E4 800F9AE4 0680033C */  lui        $v1, %hi(D_80060068)
    /* 2E8 800F9AE8 1400B1AF */  sw         $s1, 0x14($sp)
    /* 2EC 800F9AEC 68007124 */  addiu      $s1, $v1, %lo(D_80060068)
    /* 2F0 800F9AF0 1800BFAF */  sw         $ra, 0x18($sp)
    /* 2F4 800F9AF4 1000B0AF */  sw         $s0, 0x10($sp)
    /* 2F8 800F9AF8 3C00508C */  lw         $s0, 0x3C($v0)
    /* 2FC 800F9AFC 04002296 */  lhu        $v0, 0x4($s1)
    /* 300 800F9B00 00000000 */  nop
    /* 304 800F9B04 180002A6 */  sh         $v0, 0x18($s0)
    /* 308 800F9B08 06002296 */  lhu        $v0, 0x6($s1)
    /* 30C 800F9B0C 00000000 */  nop
    /* 310 800F9B10 1A0002A6 */  sh         $v0, 0x1A($s0)
    /* 314 800F9B14 08002296 */  lhu        $v0, 0x8($s1)
    /* 318 800F9B18 00000000 */  nop
    /* 31C 800F9B1C 1C0002A6 */  sh         $v0, 0x1C($s0)
    /* 320 800F9B20 0A002296 */  lhu        $v0, 0xA($s1)
    /* 324 800F9B24 00000000 */  nop
    /* 328 800F9B28 1E0002A6 */  sh         $v0, 0x1E($s0)
    /* 32C 800F9B2C 0C002296 */  lhu        $v0, 0xC($s1)
    /* 330 800F9B30 00000000 */  nop
    /* 334 800F9B34 220002A6 */  sh         $v0, 0x22($s0)
    /* 338 800F9B38 0E002296 */  lhu        $v0, 0xE($s1)
    /* 33C 800F9B3C 00000000 */  nop
    /* 340 800F9B40 240002A6 */  sh         $v0, 0x24($s0)
    /* 344 800F9B44 10002296 */  lhu        $v0, 0x10($s1)
    /* 348 800F9B48 00000000 */  nop
    /* 34C 800F9B4C 260002A6 */  sh         $v0, 0x26($s0)
    /* 350 800F9B50 12002296 */  lhu        $v0, 0x12($s1)
    /* 354 800F9B54 00000000 */  nop
    /* 358 800F9B58 280002A6 */  sh         $v0, 0x28($s0)
    /* 35C 800F9B5C 14002296 */  lhu        $v0, 0x14($s1)
    /* 360 800F9B60 00000000 */  nop
    /* 364 800F9B64 2A0002A6 */  sh         $v0, 0x2A($s0)
    /* 368 800F9B68 16002296 */  lhu        $v0, 0x16($s1)
    /* 36C 800F9B6C 00000000 */  nop
    /* 370 800F9B70 2C0002A6 */  sh         $v0, 0x2C($s0)
    /* 374 800F9B74 18002296 */  lhu        $v0, 0x18($s1)
    /* 378 800F9B78 00000000 */  nop
    /* 37C 800F9B7C 200002A6 */  sh         $v0, 0x20($s0)
    /* 380 800F9B80 1A002296 */  lhu        $v0, 0x1A($s1)
    /* 384 800F9B84 00000000 */  nop
    /* 388 800F9B88 540902A6 */  sh         $v0, 0x954($s0)
    /* 38C 800F9B8C 1C00248E */  lw         $a0, 0x1C($s1)
    /* 390 800F9B90 EA1B020C */  jal        func_80086FA8
    /* 394 800F9B94 21280002 */   addu      $a1, $s0, $zero
    /* 398 800F9B98 21380000 */  addu       $a3, $zero, $zero
    /* 39C 800F9B9C 21180702 */  addu       $v1, $s0, $a3
  .L800F9BA0:
    /* 3A0 800F9BA0 21102702 */  addu       $v0, $s1, $a3
    /* 3A4 800F9BA4 20004290 */  lbu        $v0, 0x20($v0)
    /* 3A8 800F9BA8 0100E724 */  addiu      $a3, $a3, 0x1
    /* 3AC 800F9BAC 4C0962A0 */  sb         $v0, 0x94C($v1)
    /* 3B0 800F9BB0 0800E228 */  slti       $v0, $a3, 0x8
    /* 3B4 800F9BB4 FAFF4014 */  bnez       $v0, .L800F9BA0
    /* 3B8 800F9BB8 21180702 */   addu      $v1, $s0, $a3
    /* 3BC 800F9BBC 21380000 */  addu       $a3, $zero, $zero
    /* 3C0 800F9BC0 2158E000 */  addu       $t3, $a3, $zero
    /* 3C4 800F9BC4 2150E000 */  addu       $t2, $a3, $zero
    /* 3C8 800F9BC8 21482002 */  addu       $t1, $s1, $zero
    /* 3CC 800F9BCC 21400002 */  addu       $t0, $s0, $zero
  .L800F9BD0:
    /* 3D0 800F9BD0 21280000 */  addu       $a1, $zero, $zero
    /* 3D4 800F9BD4 28002295 */  lhu        $v0, 0x28($t1)
    /* 3D8 800F9BD8 21306001 */  addu       $a2, $t3, $zero
    /* 3DC 800F9BDC 980302A5 */  sh         $v0, 0x398($t0)
    /* 3E0 800F9BE0 2A002295 */  lhu        $v0, 0x2A($t1)
    /* 3E4 800F9BE4 21204001 */  addu       $a0, $t2, $zero
    /* 3E8 800F9BE8 9A0302A5 */  sh         $v0, 0x39A($t0)
  .L800F9BEC:
    /* 3EC 800F9BEC 21102602 */  addu       $v0, $s1, $a2
    /* 3F0 800F9BF0 0200C624 */  addiu      $a2, $a2, 0x2
    /* 3F4 800F9BF4 21180402 */  addu       $v1, $s0, $a0
    /* 3F8 800F9BF8 2C004294 */  lhu        $v0, 0x2C($v0)
    /* 3FC 800F9BFC 0100A524 */  addiu      $a1, $a1, 0x1
    /* 400 800F9C00 A00362A4 */  sh         $v0, 0x3A0($v1)
    /* 404 800F9C04 0400A228 */  slti       $v0, $a1, 0x4
    /* 408 800F9C08 F8FF4014 */  bnez       $v0, .L800F9BEC
    /* 40C 800F9C0C 02008424 */   addiu     $a0, $a0, 0x2
    /* 410 800F9C10 21280000 */  addu       $a1, $zero, $zero
    /* 414 800F9C14 21306001 */  addu       $a2, $t3, $zero
    /* 418 800F9C18 21204001 */  addu       $a0, $t2, $zero
  .L800F9C1C:
    /* 41C 800F9C1C 21102602 */  addu       $v0, $s1, $a2
    /* 420 800F9C20 0200C624 */  addiu      $a2, $a2, 0x2
    /* 424 800F9C24 21180402 */  addu       $v1, $s0, $a0
    /* 428 800F9C28 34004294 */  lhu        $v0, 0x34($v0)
    /* 42C 800F9C2C 0100A524 */  addiu      $a1, $a1, 0x1
    /* 430 800F9C30 A80362A4 */  sh         $v0, 0x3A8($v1)
    /* 434 800F9C34 0800A228 */  slti       $v0, $a1, 0x8
    /* 438 800F9C38 F8FF4014 */  bnez       $v0, .L800F9C1C
    /* 43C 800F9C3C 02008424 */   addiu     $a0, $a0, 0x2
    /* 440 800F9C40 1C006B25 */  addiu      $t3, $t3, 0x1C
    /* 444 800F9C44 DC004A25 */  addiu      $t2, $t2, 0xDC
    /* 448 800F9C48 1C002925 */  addiu      $t1, $t1, 0x1C
    /* 44C 800F9C4C 0100E724 */  addiu      $a3, $a3, 0x1
    /* 450 800F9C50 0600E228 */  slti       $v0, $a3, 0x6
    /* 454 800F9C54 DEFF4014 */  bnez       $v0, .L800F9BD0
    /* 458 800F9C58 DC000825 */   addiu     $t0, $t0, 0xDC
    /* 45C 800F9C5C 0F80023C */  lui        $v0, %hi(vs_battle_characterState)
    /* 460 800F9C60 FC19438C */  lw         $v1, %lo(vs_battle_characterState)($v0)
    /* 464 800F9C64 D000228E */  lw         $v0, 0xD0($s1)
    /* 468 800F9C68 00000000 */  nop
    /* 46C 800F9C6C 200062AC */  sw         $v0, 0x20($v1)
    /* 470 800F9C70 D000228E */  lw         $v0, 0xD0($s1)
    /* 474 800F9C74 00000000 */  nop
    /* 478 800F9C78 01004230 */  andi       $v0, $v0, 0x1
    /* 47C 800F9C7C 06004010 */  beqz       $v0, .L800F9C98
    /* 480 800F9C80 21200000 */   addu      $a0, $zero, $zero
    /* 484 800F9C84 01000524 */  addiu      $a1, $zero, 0x1
    /* 488 800F9C88 4D76020C */  jal        func_8009D934
    /* 48C 800F9C8C 02000624 */   addiu     $a2, $zero, 0x2
    /* 490 800F9C90 982D030C */  jal        func_800CB660
    /* 494 800F9C94 01000424 */   addiu     $a0, $zero, 0x1
  .L800F9C98:
    /* 498 800F9C98 0680023C */  lui        $v0, %hi(D_80060068)
    /* 49C 800F9C9C 680040AC */  sw         $zero, %lo(D_80060068)($v0)
    /* 4A0 800F9CA0 0F80023C */  lui        $v0, %hi(vs_battle_cameraCurrentSpherical)
    /* 4A4 800F9CA4 D400238E */  lw         $v1, 0xD4($s1)
    /* 4A8 800F9CA8 D800248E */  lw         $a0, 0xD8($s1)
    /* 4AC 800F9CAC D0194224 */  addiu      $v0, $v0, %lo(vs_battle_cameraCurrentSpherical)
    /* 4B0 800F9CB0 140043AC */  sw         $v1, 0x14($v0)
    /* 4B4 800F9CB4 200044AC */  sw         $a0, 0x20($v0)
    /* 4B8 800F9CB8 1800BF8F */  lw         $ra, 0x18($sp)
    /* 4BC 800F9CBC 1400B18F */  lw         $s1, 0x14($sp)
    /* 4C0 800F9CC0 1000B08F */  lw         $s0, 0x10($sp)
    /* 4C4 800F9CC4 0800E003 */  jr         $ra
    /* 4C8 800F9CC8 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_800F9AD8
