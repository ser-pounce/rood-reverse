nonmatching vs_mainMenu_drawDpPpbars, 0x2A8

glabel vs_mainMenu_drawDpPpbars
    /* 2A68 800FC268 801F023C */  lui        $v0, (0x1F800004 >> 16)
    /* 2A6C 800FC26C 0400428C */  lw         $v0, (0x1F800004 & 0xFFFF)($v0)
    /* 2A70 800FC270 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 2A74 800FC274 2000BFAF */  sw         $ra, 0x20($sp)
    /* 2A78 800FC278 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 2A7C 800FC27C 1800B2AF */  sw         $s2, 0x18($sp)
    /* 2A80 800FC280 1400B1AF */  sw         $s1, 0x14($sp)
    /* 2A84 800FC284 1000B0AF */  sw         $s0, 0x10($sp)
    /* 2A88 800FC288 0A008010 */  beqz       $a0, .L800FC2B4
    /* 2A8C 800FC28C F4FF5224 */   addiu     $s2, $v0, -0xC
    /* 2A90 800FC290 1080033C */  lui        $v1, %hi(D_8010213C)
    /* 2A94 800FC294 83100400 */  sra        $v0, $a0, 2
    /* 2A98 800FC298 3C2162A0 */  sb         $v0, %lo(D_8010213C)($v1)
    /* 2A9C 800FC29C 01004230 */  andi       $v0, $v0, 0x1
    /* 2AA0 800FC2A0 94004014 */  bnez       $v0, .L800FC4F4
    /* 2AA4 800FC2A4 1080033C */   lui       $v1, %hi(D_8010213D)
    /* 2AA8 800FC2A8 03008230 */  andi       $v0, $a0, 0x3
    /* 2AAC 800FC2AC 3DF10308 */  j          .L800FC4F4
    /* 2AB0 800FC2B0 3D2162A0 */   sb        $v0, %lo(D_8010213D)($v1)
  .L800FC2B4:
    /* 2AB4 800FC2B4 1080043C */  lui        $a0, %hi(D_80102132)
    /* 2AB8 800FC2B8 1080023C */  lui        $v0, %hi(D_8010213C)
    /* 2ABC 800FC2BC 3C214390 */  lbu        $v1, %lo(D_8010213C)($v0)
    /* 2AC0 800FC2C0 01000224 */  addiu      $v0, $zero, 0x1
    /* 2AC4 800FC2C4 32219094 */  lhu        $s0, %lo(D_80102132)($a0)
    /* 2AC8 800FC2C8 10006210 */  beq        $v1, $v0, .L800FC30C
    /* 2ACC 800FC2CC 02006228 */   slti      $v0, $v1, 0x2
    /* 2AD0 800FC2D0 05004010 */  beqz       $v0, .L800FC2E8
    /* 2AD4 800FC2D4 02000224 */   addiu     $v0, $zero, 0x2
    /* 2AD8 800FC2D8 07006010 */  beqz       $v1, .L800FC2F8
    /* 2ADC 800FC2DC 1080033C */   lui       $v1, %hi(D_80102132)
    /* 2AE0 800FC2E0 CAF00308 */  j          .L800FC328
    /* 2AE4 800FC2E4 00000000 */   nop
  .L800FC2E8:
    /* 2AE8 800FC2E8 0C006210 */  beq        $v1, $v0, .L800FC31C
    /* 2AEC 800FC2EC 1080033C */   lui       $v1, %hi(D_80102132)
    /* 2AF0 800FC2F0 CAF00308 */  j          .L800FC328
    /* 2AF4 800FC2F4 00000000 */   nop
  .L800FC2F8:
    /* 2AF8 800FC2F8 0500022A */  slti       $v0, $s0, 0x5
    /* 2AFC 800FC2FC 09004010 */  beqz       $v0, .L800FC324
    /* 2B00 800FC300 01000226 */   addiu     $v0, $s0, 0x1
    /* 2B04 800FC304 C9F00308 */  j          .L800FC324
    /* 2B08 800FC308 322182A4 */   sh        $v0, %lo(D_80102132)($a0)
  .L800FC30C:
    /* 2B0C 800FC30C 05000012 */  beqz       $s0, .L800FC324
    /* 2B10 800FC310 FFFF0226 */   addiu     $v0, $s0, -0x1
    /* 2B14 800FC314 C9F00308 */  j          .L800FC324
    /* 2B18 800FC318 322182A4 */   sh        $v0, %lo(D_80102132)($a0)
  .L800FC31C:
    /* 2B1C 800FC31C 05000224 */  addiu      $v0, $zero, 0x5
    /* 2B20 800FC320 322182A4 */  sh         $v0, %lo(D_80102132)($a0)
  .L800FC324:
    /* 2B24 800FC324 1080033C */  lui        $v1, %hi(D_80102132)
  .L800FC328:
    /* 2B28 800FC328 32216294 */  lhu        $v0, %lo(D_80102132)($v1)
    /* 2B2C 800FC32C 00000000 */  nop
    /* 2B30 800FC330 70004010 */  beqz       $v0, .L800FC4F4
    /* 2B34 800FC334 21184000 */   addu      $v1, $v0, $zero
    /* 2B38 800FC338 C0180300 */  sll        $v1, $v1, 3
    /* 2B3C 800FC33C F8FF6324 */  addiu      $v1, $v1, -0x8
    /* 2B40 800FC340 1080133C */  lui        $s3, %hi(D_8010213D)
    /* 2B44 800FC344 3D216292 */  lbu        $v0, %lo(D_8010213D)($s3)
    /* 2B48 800FC348 00000000 */  nop
    /* 2B4C 800FC34C 01004230 */  andi       $v0, $v0, 0x1
    /* 2B50 800FC350 1C004010 */  beqz       $v0, .L800FC3C4
    /* 2B54 800FC354 008C0300 */   sll       $s1, $v1, 16
    /* 2B58 800FC358 1080043C */  lui        $a0, %hi(D_800F9924)
    /* 2B5C 800FC35C 24998424 */  addiu      $a0, $a0, %lo(D_800F9924)
    /* 2B60 800FC360 FFFF053C */  lui        $a1, (0xFFFF000A >> 16)
    /* 2B64 800FC364 21282502 */  addu       $a1, $s1, $a1
    /* 2B68 800FC368 0A00A534 */  ori        $a1, $a1, (0xFFFF000A & 0xFFFF)
    /* 2B6C 800FC36C 0A1A030C */  jal        vs_battle_renderTextRaw
    /* 2B70 800FC370 21304002 */   addu      $a2, $s2, $zero
    /* 2B74 800FC374 21200000 */  addu       $a0, $zero, $zero
    /* 2B78 800FC378 42002536 */  ori        $a1, $s1, 0x42
    /* 2B7C 800FC37C 1080023C */  lui        $v0, %hi(_maxDp)
    /* 2B80 800FC380 36214694 */  lhu        $a2, %lo(_maxDp)($v0)
    /* 2B84 800FC384 5426030C */  jal        vs_battle_renderValue
    /* 2B88 800FC388 21384002 */   addu      $a3, $s2, $zero
    /* 2B8C 800FC38C 21804000 */  addu       $s0, $v0, $zero
    /* 2B90 800FC390 02000424 */  addiu      $a0, $zero, 0x2
    /* 2B94 800FC394 21280002 */  addu       $a1, $s0, $zero
    /* 2B98 800FC398 21300000 */  addu       $a2, $zero, $zero
    /* 2B9C 800FC39C 5426030C */  jal        vs_battle_renderValue
    /* 2BA0 800FC3A0 21384002 */   addu      $a3, $s2, $zero
    /* 2BA4 800FC3A4 FEFF053C */  lui        $a1, (0xFFFEFFF9 >> 16)
    /* 2BA8 800FC3A8 F9FFA534 */  ori        $a1, $a1, (0xFFFEFFF9 & 0xFFFF)
    /* 2BAC 800FC3AC 01000424 */  addiu      $a0, $zero, 0x1
    /* 2BB0 800FC3B0 21280502 */  addu       $a1, $s0, $a1
    /* 2BB4 800FC3B4 1080023C */  lui        $v0, %hi(_currentDp)
    /* 2BB8 800FC3B8 34214694 */  lhu        $a2, %lo(_currentDp)($v0)
    /* 2BBC 800FC3BC 5426030C */  jal        vs_battle_renderValue
    /* 2BC0 800FC3C0 21384002 */   addu      $a3, $s2, $zero
  .L800FC3C4:
    /* 2BC4 800FC3C4 3D216292 */  lbu        $v0, %lo(D_8010213D)($s3)
    /* 2BC8 800FC3C8 00000000 */  nop
    /* 2BCC 800FC3CC 02004230 */  andi       $v0, $v0, 0x2
    /* 2BD0 800FC3D0 1B004010 */  beqz       $v0, .L800FC440
    /* 2BD4 800FC3D4 1080043C */   lui       $a0, %hi(D_800F9928)
    /* 2BD8 800FC3D8 28998424 */  addiu      $a0, $a0, %lo(D_800F9928)
    /* 2BDC 800FC3DC FFFF053C */  lui        $a1, (0xFFFF0050 >> 16)
    /* 2BE0 800FC3E0 21282502 */  addu       $a1, $s1, $a1
    /* 2BE4 800FC3E4 5000A534 */  ori        $a1, $a1, (0xFFFF0050 & 0xFFFF)
    /* 2BE8 800FC3E8 0A1A030C */  jal        vs_battle_renderTextRaw
    /* 2BEC 800FC3EC 21304002 */   addu      $a2, $s2, $zero
    /* 2BF0 800FC3F0 21200000 */  addu       $a0, $zero, $zero
    /* 2BF4 800FC3F4 88002536 */  ori        $a1, $s1, 0x88
    /* 2BF8 800FC3F8 1080023C */  lui        $v0, %hi(_maxPp)
    /* 2BFC 800FC3FC 3A214694 */  lhu        $a2, %lo(_maxPp)($v0)
    /* 2C00 800FC400 5426030C */  jal        vs_battle_renderValue
    /* 2C04 800FC404 21384002 */   addu      $a3, $s2, $zero
    /* 2C08 800FC408 21804000 */  addu       $s0, $v0, $zero
    /* 2C0C 800FC40C 02000424 */  addiu      $a0, $zero, 0x2
    /* 2C10 800FC410 21280002 */  addu       $a1, $s0, $zero
    /* 2C14 800FC414 21300000 */  addu       $a2, $zero, $zero
    /* 2C18 800FC418 5426030C */  jal        vs_battle_renderValue
    /* 2C1C 800FC41C 21384002 */   addu      $a3, $s2, $zero
    /* 2C20 800FC420 FEFF053C */  lui        $a1, (0xFFFEFFF9 >> 16)
    /* 2C24 800FC424 F9FFA534 */  ori        $a1, $a1, (0xFFFEFFF9 & 0xFFFF)
    /* 2C28 800FC428 01000424 */  addiu      $a0, $zero, 0x1
    /* 2C2C 800FC42C 21280502 */  addu       $a1, $s0, $a1
    /* 2C30 800FC430 1080023C */  lui        $v0, %hi(_currentPp)
    /* 2C34 800FC434 38214694 */  lhu        $a2, %lo(_currentPp)($v0)
    /* 2C38 800FC438 5426030C */  jal        vs_battle_renderValue
    /* 2C3C 800FC43C 21384002 */   addu      $a3, $s2, $zero
  .L800FC440:
    /* 2C40 800FC440 0800033C */  lui        $v1, (0x80050 >> 16)
    /* 2C44 800FC444 3D216292 */  lbu        $v0, %lo(D_8010213D)($s3)
    /* 2C48 800FC448 00000000 */  nop
    /* 2C4C 800FC44C 01004230 */  andi       $v0, $v0, 0x1
    /* 2C50 800FC450 12004010 */  beqz       $v0, .L800FC49C
    /* 2C54 800FC454 21882302 */   addu      $s1, $s1, $v1
    /* 2C58 800FC458 1080023C */  lui        $v0, %hi(_maxDp)
    /* 2C5C 800FC45C 36215094 */  lhu        $s0, %lo(_maxDp)($v0)
    /* 2C60 800FC460 00000000 */  nop
    /* 2C64 800FC464 02000016 */  bnez       $s0, .L800FC470
    /* 2C68 800FC468 1080023C */   lui       $v0, %hi(_currentDp)
    /* 2C6C 800FC46C 01001024 */  addiu      $s0, $zero, 0x1
  .L800FC470:
    /* 2C70 800FC470 34214594 */  lhu        $a1, %lo(_currentDp)($v0)
    /* 2C74 800FC474 00000000 */  nop
    /* 2C78 800FC478 80290500 */  sll        $a1, $a1, 6
    /* 2C7C 800FC47C 2128B000 */  addu       $a1, $a1, $s0
    /* 2C80 800FC480 FFFFA524 */  addiu      $a1, $a1, -0x1
    /* 2C84 800FC484 1A00B000 */  div        $zero, $a1, $s0
    /* 2C88 800FC488 12280000 */  mflo       $a1
    /* 2C8C 800FC48C 21200000 */  addu       $a0, $zero, $zero
    /* 2C90 800FC490 21304002 */  addu       $a2, $s2, $zero
    /* 2C94 800FC494 7726030C */  jal        vs_battle_drawStatBar
    /* 2C98 800FC498 0A002736 */   ori       $a3, $s1, (0x8000A & 0xFFFF)
  .L800FC49C:
    /* 2C9C 800FC49C 1080023C */  lui        $v0, %hi(D_8010213D)
    /* 2CA0 800FC4A0 3D214290 */  lbu        $v0, %lo(D_8010213D)($v0)
    /* 2CA4 800FC4A4 00000000 */  nop
    /* 2CA8 800FC4A8 02004230 */  andi       $v0, $v0, 0x2
    /* 2CAC 800FC4AC 11004010 */  beqz       $v0, .L800FC4F4
    /* 2CB0 800FC4B0 1080023C */   lui       $v0, %hi(_maxPp)
    /* 2CB4 800FC4B4 3A215094 */  lhu        $s0, %lo(_maxPp)($v0)
    /* 2CB8 800FC4B8 00000000 */  nop
    /* 2CBC 800FC4BC 02000016 */  bnez       $s0, .L800FC4C8
    /* 2CC0 800FC4C0 1080023C */   lui       $v0, %hi(_currentPp)
    /* 2CC4 800FC4C4 01001024 */  addiu      $s0, $zero, 0x1
  .L800FC4C8:
    /* 2CC8 800FC4C8 38214594 */  lhu        $a1, %lo(_currentPp)($v0)
    /* 2CCC 800FC4CC 00000000 */  nop
    /* 2CD0 800FC4D0 80290500 */  sll        $a1, $a1, 6
    /* 2CD4 800FC4D4 2128B000 */  addu       $a1, $a1, $s0
    /* 2CD8 800FC4D8 FFFFA524 */  addiu      $a1, $a1, -0x1
    /* 2CDC 800FC4DC 1A00B000 */  div        $zero, $a1, $s0
    /* 2CE0 800FC4E0 12280000 */  mflo       $a1
    /* 2CE4 800FC4E4 01000424 */  addiu      $a0, $zero, 0x1
    /* 2CE8 800FC4E8 21304002 */  addu       $a2, $s2, $zero
    /* 2CEC 800FC4EC 7726030C */  jal        vs_battle_drawStatBar
    /* 2CF0 800FC4F0 50002736 */   ori       $a3, $s1, (0x80050 & 0xFFFF)
  .L800FC4F4:
    /* 2CF4 800FC4F4 2000BF8F */  lw         $ra, 0x20($sp)
    /* 2CF8 800FC4F8 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 2CFC 800FC4FC 1800B28F */  lw         $s2, 0x18($sp)
    /* 2D00 800FC500 1400B18F */  lw         $s1, 0x14($sp)
    /* 2D04 800FC504 1000B08F */  lw         $s0, 0x10($sp)
    /* 2D08 800FC508 0800E003 */  jr         $ra
    /* 2D0C 800FC50C 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel vs_mainMenu_drawDpPpbars
