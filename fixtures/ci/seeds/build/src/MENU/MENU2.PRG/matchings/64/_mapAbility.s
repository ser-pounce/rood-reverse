nonmatching _mapAbility, 0x150

glabel _mapAbility
    /* 35C 80102B5C D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 360 80102B60 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 364 80102B64 2198A000 */  addu       $s3, $a1, $zero
    /* 368 80102B68 1000B0AF */  sw         $s0, 0x10($sp)
    /* 36C 80102B6C 2180C000 */  addu       $s0, $a2, $zero
    /* 370 80102B70 18000224 */  addiu      $v0, $zero, 0x18
    /* 374 80102B74 2000BFAF */  sw         $ra, 0x20($sp)
    /* 378 80102B78 1800B2AF */  sw         $s2, 0x18($sp)
    /* 37C 80102B7C 23008214 */  bne        $a0, $v0, .L80102C0C
    /* 380 80102B80 1400B1AF */   sw        $s1, 0x14($sp)
    /* 384 80102B84 1080023C */  lui        $v0, %hi(_unlockedChainAbilities)
    /* 388 80102B88 D0504224 */  addiu      $v0, $v0, %lo(_unlockedChainAbilities)
    /* 38C 80102B8C 21100202 */  addu       $v0, $s0, $v0
    /* 390 80102B90 00005090 */  lbu        $s0, 0x0($v0)
    /* 394 80102B94 0680023C */  lui        $v0, %hi(vs_main_settings)
    /* 398 80102B98 20005224 */  addiu      $s2, $v0, %lo(vs_main_settings)
    /* 39C 80102B9C 21887202 */  addu       $s1, $s3, $s2
    /* 3A0 80102BA0 0C002292 */  lbu        $v0, 0xC($s1)
    /* 3A4 80102BA4 00000000 */  nop
    /* 3A8 80102BA8 05005014 */  bne        $v0, $s0, .L80102BC0
    /* 3AC 80102BAC 7E000424 */   addiu     $a0, $zero, 0x7E
    /* 3B0 80102BB0 BA00030C */  jal        vs_battle_playMenuLeaveSfx
    /* 3B4 80102BB4 00000000 */   nop
    /* 3B8 80102BB8 240B0408 */  j          .L80102C90
    /* 3BC 80102BBC 0C0020A2 */   sb        $zero, 0xC($s1)
  .L80102BC0:
    /* 3C0 80102BC0 6216010C */  jal        vs_main_playSfxDefault
    /* 3C4 80102BC4 23000524 */   addiu     $a1, $zero, 0x23
    /* 3C8 80102BC8 21180000 */  addu       $v1, $zero, $zero
    /* 3CC 80102BCC 21284002 */  addu       $a1, $s2, $zero
    /* 3D0 80102BD0 21206500 */  addu       $a0, $v1, $a1
  .L80102BD4:
    /* 3D4 80102BD4 0C008290 */  lbu        $v0, 0xC($a0)
    /* 3D8 80102BD8 00000000 */  nop
    /* 3DC 80102BDC 02005014 */  bne        $v0, $s0, .L80102BE8
    /* 3E0 80102BE0 00000000 */   nop
    /* 3E4 80102BE4 0C0080A0 */  sb         $zero, 0xC($a0)
  .L80102BE8:
    /* 3E8 80102BE8 01006324 */  addiu      $v1, $v1, 0x1
    /* 3EC 80102BEC 03006228 */  slti       $v0, $v1, 0x3
    /* 3F0 80102BF0 F8FF4014 */  bnez       $v0, .L80102BD4
    /* 3F4 80102BF4 21206500 */   addu      $a0, $v1, $a1
    /* 3F8 80102BF8 0680023C */  lui        $v0, %hi(vs_main_settings)
    /* 3FC 80102BFC 20004224 */  addiu      $v0, $v0, %lo(vs_main_settings)
    /* 400 80102C00 21106202 */  addu       $v0, $s3, $v0
    /* 404 80102C04 240B0408 */  j          .L80102C90
    /* 408 80102C08 0C0050A0 */   sb        $s0, 0xC($v0)
  .L80102C0C:
    /* 40C 80102C0C 1080023C */  lui        $v0, %hi(_unlockedDefenseAbilities)
    /* 410 80102C10 E0504224 */  addiu      $v0, $v0, %lo(_unlockedDefenseAbilities)
    /* 414 80102C14 21100202 */  addu       $v0, $s0, $v0
    /* 418 80102C18 00005090 */  lbu        $s0, 0x0($v0)
    /* 41C 80102C1C 0680023C */  lui        $v0, %hi(vs_main_settings)
    /* 420 80102C20 20005224 */  addiu      $s2, $v0, %lo(vs_main_settings)
    /* 424 80102C24 21887202 */  addu       $s1, $s3, $s2
    /* 428 80102C28 10002292 */  lbu        $v0, 0x10($s1)
    /* 42C 80102C2C 00000000 */  nop
    /* 430 80102C30 05005014 */  bne        $v0, $s0, .L80102C48
    /* 434 80102C34 7E000424 */   addiu     $a0, $zero, 0x7E
    /* 438 80102C38 BA00030C */  jal        vs_battle_playMenuLeaveSfx
    /* 43C 80102C3C 00000000 */   nop
    /* 440 80102C40 240B0408 */  j          .L80102C90
    /* 444 80102C44 100020A2 */   sb        $zero, 0x10($s1)
  .L80102C48:
    /* 448 80102C48 6216010C */  jal        vs_main_playSfxDefault
    /* 44C 80102C4C 23000524 */   addiu     $a1, $zero, 0x23
    /* 450 80102C50 21180000 */  addu       $v1, $zero, $zero
    /* 454 80102C54 21284002 */  addu       $a1, $s2, $zero
    /* 458 80102C58 21206500 */  addu       $a0, $v1, $a1
  .L80102C5C:
    /* 45C 80102C5C 10008290 */  lbu        $v0, 0x10($a0)
    /* 460 80102C60 00000000 */  nop
    /* 464 80102C64 02005014 */  bne        $v0, $s0, .L80102C70
    /* 468 80102C68 00000000 */   nop
    /* 46C 80102C6C 100080A0 */  sb         $zero, 0x10($a0)
  .L80102C70:
    /* 470 80102C70 01006324 */  addiu      $v1, $v1, 0x1
    /* 474 80102C74 03006228 */  slti       $v0, $v1, 0x3
    /* 478 80102C78 F8FF4014 */  bnez       $v0, .L80102C5C
    /* 47C 80102C7C 21206500 */   addu      $a0, $v1, $a1
    /* 480 80102C80 0680023C */  lui        $v0, %hi(vs_main_settings)
    /* 484 80102C84 20004224 */  addiu      $v0, $v0, %lo(vs_main_settings)
    /* 488 80102C88 21106202 */  addu       $v0, $s3, $v0
    /* 48C 80102C8C 100050A0 */  sb         $s0, 0x10($v0)
  .L80102C90:
    /* 490 80102C90 2000BF8F */  lw         $ra, 0x20($sp)
    /* 494 80102C94 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 498 80102C98 1800B28F */  lw         $s2, 0x18($sp)
    /* 49C 80102C9C 1400B18F */  lw         $s1, 0x14($sp)
    /* 4A0 80102CA0 1000B08F */  lw         $s0, 0x10($sp)
    /* 4A4 80102CA4 0800E003 */  jr         $ra
    /* 4A8 80102CA8 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel _mapAbility
