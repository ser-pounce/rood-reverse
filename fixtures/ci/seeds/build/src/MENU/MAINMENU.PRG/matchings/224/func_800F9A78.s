nonmatching func_800F9A78, 0x238

glabel func_800F9A78
    /* 278 800F9A78 B8FFBD27 */  addiu      $sp, $sp, -0x48
    /* 27C 800F9A7C 3800B4AF */  sw         $s4, 0x38($sp)
    /* 280 800F9A80 21A08000 */  addu       $s4, $a0, $zero
    /* 284 800F9A84 0F80023C */  lui        $v0, %hi(D_800F4538)
    /* 288 800F9A88 2800B0AF */  sw         $s0, 0x28($sp)
    /* 28C 800F9A8C 38455024 */  addiu      $s0, $v0, %lo(D_800F4538)
    /* 290 800F9A90 80101400 */  sll        $v0, $s4, 2
    /* 294 800F9A94 21105000 */  addu       $v0, $v0, $s0
    /* 298 800F9A98 4000BFAF */  sw         $ra, 0x40($sp)
    /* 29C 800F9A9C 3C00B5AF */  sw         $s5, 0x3C($sp)
    /* 2A0 800F9AA0 3400B3AF */  sw         $s3, 0x34($sp)
    /* 2A4 800F9AA4 3000B2AF */  sw         $s2, 0x30($sp)
    /* 2A8 800F9AA8 2C00B1AF */  sw         $s1, 0x2C($sp)
    /* 2AC 800F9AAC 0000528C */  lw         $s2, 0x0($v0)
    /* 2B0 800F9AB0 B10F010C */  jal        vs_main_allocHeap
    /* 2B4 800F9AB4 00190424 */   addiu     $a0, $zero, 0x1900
    /* 2B8 800F9AB8 02001124 */  addiu      $s1, $zero, 0x2
    /* 2BC 800F9ABC 01001524 */  addiu      $s5, $zero, 0x1
    /* 2C0 800F9AC0 21984000 */  addu       $s3, $v0, $zero
    /* 2C4 800F9AC4 1000B1A3 */  sb         $s1, 0x10($sp)
    /* 2C8 800F9AC8 1100B5A3 */  sb         $s5, 0x11($sp)
    /* 2CC 800F9ACC E6064396 */  lhu        $v1, 0x6E6($s2)
    /* 2D0 800F9AD0 FF000224 */  addiu      $v0, $zero, 0xFF
    /* 2D4 800F9AD4 1800B4AF */  sw         $s4, 0x18($sp)
    /* 2D8 800F9AD8 1400B3AF */  sw         $s3, 0x14($sp)
    /* 2DC 800F9ADC 2000A2A3 */  sb         $v0, 0x20($sp)
    /* 2E0 800F9AE0 1200A3A7 */  sh         $v1, 0x12($sp)
    /* 2E4 800F9AE4 10004292 */  lbu        $v0, 0x10($s2)
    /* 2E8 800F9AE8 1000A427 */  addiu      $a0, $sp, 0x10
    /* 2EC 800F9AEC 2200A0A3 */  sb         $zero, 0x22($sp)
    /* 2F0 800F9AF0 7A65020C */  jal        vs_battle_populateDataSlot
    /* 2F4 800F9AF4 2300A2A3 */   sb        $v0, 0x23($sp)
    /* 2F8 800F9AF8 FD174292 */  lbu        $v0, 0x17FD($s2)
    /* 2FC 800F9AFC 00000000 */  nop
    /* 300 800F9B00 0200422C */  sltiu      $v0, $v0, 0x2
    /* 304 800F9B04 19004014 */  bnez       $v0, .L800F9B6C
    /* 308 800F9B08 00000000 */   nop
    /* 30C 800F9B0C FD174292 */  lbu        $v0, 0x17FD($s2)
    /* 310 800F9B10 00000000 */  nop
    /* 314 800F9B14 80100200 */  sll        $v0, $v0, 2
    /* 318 800F9B18 21105000 */  addu       $v0, $v0, $s0
    /* 31C 800F9B1C 0000508C */  lw         $s0, 0x0($v0)
    /* 320 800F9B20 B10F010C */  jal        vs_main_allocHeap
    /* 324 800F9B24 00190424 */   addiu     $a0, $zero, 0x1900
    /* 328 800F9B28 10000324 */  addiu      $v1, $zero, 0x10
    /* 32C 800F9B2C 1000B1A3 */  sb         $s1, 0x10($sp)
    /* 330 800F9B30 1100A3A3 */  sb         $v1, 0x11($sp)
    /* 334 800F9B34 E6060396 */  lhu        $v1, 0x6E6($s0)
    /* 338 800F9B38 00000000 */  nop
    /* 33C 800F9B3C 1200A3A7 */  sh         $v1, 0x12($sp)
    /* 340 800F9B40 FD174392 */  lbu        $v1, 0x17FD($s2)
    /* 344 800F9B44 1400A2AF */  sw         $v0, 0x14($sp)
    /* 348 800F9B48 FC000224 */  addiu      $v0, $zero, 0xFC
    /* 34C 800F9B4C 2000B5A3 */  sb         $s5, 0x20($sp)
    /* 350 800F9B50 2100A2A3 */  sb         $v0, 0x21($sp)
    /* 354 800F9B54 1800A3AF */  sw         $v1, 0x18($sp)
    /* 358 800F9B58 10004292 */  lbu        $v0, 0x10($s2)
    /* 35C 800F9B5C 1000A427 */  addiu      $a0, $sp, 0x10
    /* 360 800F9B60 2200A0A3 */  sb         $zero, 0x22($sp)
    /* 364 800F9B64 7A65020C */  jal        vs_battle_populateDataSlot
    /* 368 800F9B68 2300A2A3 */   sb        $v0, 0x23($sp)
  .L800F9B6C:
    /* 36C 800F9B6C 21880000 */  addu       $s1, $zero, $zero
    /* 370 800F9B70 0F80023C */  lui        $v0, %hi(D_800F4588)
    /* 374 800F9B74 88455524 */  addiu      $s5, $v0, %lo(D_800F4588)
  .L800F9B78:
    /* 378 800F9B78 0F004292 */  lbu        $v0, 0xF($s2)
    /* 37C 800F9B7C 00000000 */  nop
    /* 380 800F9B80 40100200 */  sll        $v0, $v0, 1
    /* 384 800F9B84 21105100 */  addu       $v0, $v0, $s1
    /* 388 800F9B88 80100200 */  sll        $v0, $v0, 2
    /* 38C 800F9B8C 21105500 */  addu       $v0, $v0, $s5
    /* 390 800F9B90 0000508C */  lw         $s0, 0x0($v0)
    /* 394 800F9B94 00000000 */  nop
    /* 398 800F9B98 18000012 */  beqz       $s0, .L800F9BFC
    /* 39C 800F9B9C 00000000 */   nop
    /* 3A0 800F9BA0 B10F010C */  jal        vs_main_allocHeap
    /* 3A4 800F9BA4 E8050424 */   addiu     $a0, $zero, 0x5E8
    /* 3A8 800F9BA8 04000324 */  addiu      $v1, $zero, 0x4
    /* 3AC 800F9BAC 1000A3A3 */  sb         $v1, 0x10($sp)
    /* 3B0 800F9BB0 02002326 */  addiu      $v1, $s1, 0x2
    /* 3B4 800F9BB4 1100A3A3 */  sb         $v1, 0x11($sp)
    /* 3B8 800F9BB8 40181400 */  sll        $v1, $s4, 1
    /* 3BC 800F9BBC 0E000492 */  lbu        $a0, 0xE($s0)
    /* 3C0 800F9BC0 21187100 */  addu       $v1, $v1, $s1
    /* 3C4 800F9BC4 1400A2AF */  sw         $v0, 0x14($sp)
    /* 3C8 800F9BC8 01000224 */  addiu      $v0, $zero, 0x1
    /* 3CC 800F9BCC 1800A3AF */  sw         $v1, 0x18($sp)
    /* 3D0 800F9BD0 2000A2A3 */  sb         $v0, 0x20($sp)
    /* 3D4 800F9BD4 1200A4A7 */  sh         $a0, 0x12($sp)
    /* 3D8 800F9BD8 0C000292 */  lbu        $v0, 0xC($s0)
    /* 3DC 800F9BDC 00000000 */  nop
    /* 3E0 800F9BE0 2100A2A3 */  sb         $v0, 0x21($sp)
    /* 3E4 800F9BE4 0800028E */  lw         $v0, 0x8($s0)
    /* 3E8 800F9BE8 1000A427 */  addiu      $a0, $sp, 0x10
    /* 3EC 800F9BEC 02130200 */  srl        $v0, $v0, 12
    /* 3F0 800F9BF0 0F004230 */  andi       $v0, $v0, 0xF
    /* 3F4 800F9BF4 7A65020C */  jal        vs_battle_populateDataSlot
    /* 3F8 800F9BF8 2200A2A3 */   sb        $v0, 0x22($sp)
  .L800F9BFC:
    /* 3FC 800F9BFC 01003126 */  addiu      $s1, $s1, 0x1
    /* 400 800F9C00 0200222A */  slti       $v0, $s1, 0x2
    /* 404 800F9C04 DCFF4014 */  bnez       $v0, .L800F9B78
    /* 408 800F9C08 00000000 */   nop
  .L800F9C0C:
    /* 40C 800F9C0C 9F65020C */  jal        vs_battle_processObjectDataQueue
    /* 410 800F9C10 00000000 */   nop
    /* 414 800F9C14 FDFF4014 */  bnez       $v0, .L800F9C0C
    /* 418 800F9C18 00000000 */   nop
    /* 41C 800F9C1C D405428E */  lw         $v0, 0x5D4($s2)
    /* 420 800F9C20 00000000 */  nop
    /* 424 800F9C24 D40562AE */  sw         $v0, 0x5D4($s3)
    /* 428 800F9C28 0F004292 */  lbu        $v0, 0xF($s2)
    /* 42C 800F9C2C 00000000 */  nop
    /* 430 800F9C30 09004014 */  bnez       $v0, .L800F9C58
    /* 434 800F9C34 00000000 */   nop
    /* 438 800F9C38 B10F010C */  jal        vs_main_allocHeap
    /* 43C 800F9C3C 00780424 */   addiu     $a0, $zero, 0x7800
    /* 440 800F9C40 D80562AE */  sw         $v0, 0x5D8($s3)
    /* 444 800F9C44 D805458E */  lw         $a1, 0x5D8($s2)
    /* 448 800F9C48 DE70020C */  jal        func_8009C378
    /* 44C 800F9C4C 21204000 */   addu      $a0, $v0, $zero
    /* 450 800F9C50 19E70308 */  j          .L800F9C64
    /* 454 800F9C54 00000000 */   nop
  .L800F9C58:
    /* 458 800F9C58 D805428E */  lw         $v0, 0x5D8($s2)
    /* 45C 800F9C5C 00000000 */  nop
    /* 460 800F9C60 D80562AE */  sw         $v0, 0x5D8($s3)
  .L800F9C64:
    /* 464 800F9C64 B1054292 */  lbu        $v0, 0x5B1($s2)
    /* 468 800F9C68 00000000 */  nop
    /* 46C 800F9C6C B10562A2 */  sb         $v0, 0x5B1($s3)
    /* 470 800F9C70 B4054292 */  lbu        $v0, 0x5B4($s2)
    /* 474 800F9C74 00000000 */  nop
    /* 478 800F9C78 B40562A2 */  sb         $v0, 0x5B4($s3)
    /* 47C 800F9C7C B5054292 */  lbu        $v0, 0x5B5($s2)
    /* 480 800F9C80 00000000 */  nop
    /* 484 800F9C84 B50562A2 */  sb         $v0, 0x5B5($s3)
    /* 488 800F9C88 4000BF8F */  lw         $ra, 0x40($sp)
    /* 48C 800F9C8C 3C00B58F */  lw         $s5, 0x3C($sp)
    /* 490 800F9C90 3800B48F */  lw         $s4, 0x38($sp)
    /* 494 800F9C94 3400B38F */  lw         $s3, 0x34($sp)
    /* 498 800F9C98 3000B28F */  lw         $s2, 0x30($sp)
    /* 49C 800F9C9C 2C00B18F */  lw         $s1, 0x2C($sp)
    /* 4A0 800F9CA0 2800B08F */  lw         $s0, 0x28($sp)
    /* 4A4 800F9CA4 4800BD27 */  addiu      $sp, $sp, 0x48
    /* 4A8 800F9CA8 0800E003 */  jr         $ra
    /* 4AC 800F9CAC 00000000 */   nop
endlabel func_800F9A78
