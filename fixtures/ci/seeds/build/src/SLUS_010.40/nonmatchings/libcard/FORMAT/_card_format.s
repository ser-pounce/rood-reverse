nonmatching _card_format, 0x28C

glabel _card_format
    /* 1FA84 8002F284 C8FFBD27 */  addiu      $sp, $sp, -0x38
    /* 1FA88 8002F288 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 1FA8C 8002F28C 21988000 */  addu       $s3, $a0, $zero
    /* 1FA90 8002F290 1800B2AF */  sw         $s2, 0x18($sp)
    /* 1FA94 8002F294 21900000 */  addu       $s2, $zero, $zero
    /* 1FA98 8002F298 2000B4AF */  sw         $s4, 0x20($sp)
    /* 1FA9C 8002F29C 0480143C */  lui        $s4, %hi(D_80040128)
    /* 1FAA0 8002F2A0 28019426 */  addiu      $s4, $s4, %lo(D_80040128)
    /* 1FAA4 8002F2A4 3000BEAF */  sw         $fp, 0x30($sp)
    /* 1FAA8 8002F2A8 04801E3C */  lui        $fp, %hi(D_8003FEF8)
    /* 1FAAC 8002F2AC F8FEDE27 */  addiu      $fp, $fp, %lo(D_8003FEF8)
    /* 1FAB0 8002F2B0 2C00B7AF */  sw         $s7, 0x2C($sp)
    /* 1FAB4 8002F2B4 A0001724 */  addiu      $s7, $zero, 0xA0
    /* 1FAB8 8002F2B8 2800B6AF */  sw         $s6, 0x28($sp)
    /* 1FABC 8002F2BC FFFF1634 */  ori        $s6, $zero, 0xFFFF
    /* 1FAC0 8002F2C0 2400B5AF */  sw         $s5, 0x24($sp)
    /* 1FAC4 8002F2C4 01001524 */  addiu      $s5, $zero, 0x1
    /* 1FAC8 8002F2C8 3400BFAF */  sw         $ra, 0x34($sp)
    /* 1FACC 8002F2CC 1400B1AF */  sw         $s1, 0x14($sp)
    /* 1FAD0 8002F2D0 1000B0AF */  sw         $s0, 0x10($sp)
    /* 1FAD4 8002F2D4 21208002 */  addu       $a0, $s4, $zero
  .L8002F2D8:
    /* 1FAD8 8002F2D8 C9B8000C */  jal        bzero
    /* 1FADC 8002F2DC 80000524 */   addiu     $a1, $zero, 0x80
    /* 1FAE0 8002F2E0 40811200 */  sll        $s0, $s2, 5
    /* 1FAE4 8002F2E4 21881E02 */  addu       $s1, $s0, $fp
    /* 1FAE8 8002F2E8 21202002 */  addu       $a0, $s1, $zero
    /* 1FAEC 8002F2EC C9B8000C */  jal        bzero
    /* 1FAF0 8002F2F0 20000524 */   addiu     $a1, $zero, 0x20
    /* 1FAF4 8002F2F4 0480013C */  lui        $at, %hi(D_8003FEF8)
    /* 1FAF8 8002F2F8 21083000 */  addu       $at, $at, $s0
    /* 1FAFC 8002F2FC F8FE37AC */  sw         $s7, %lo(D_8003FEF8)($at)
    /* 1FB00 8002F300 0480013C */  lui        $at, %hi(D_8003FEFC)
    /* 1FB04 8002F304 21083000 */  addu       $at, $at, $s0
    /* 1FB08 8002F308 FCFE20AC */  sw         $zero, %lo(D_8003FEFC)($at)
    /* 1FB0C 8002F30C 0480013C */  lui        $at, %hi(D_8003FF00)
    /* 1FB10 8002F310 21083000 */  addu       $at, $at, $s0
    /* 1FB14 8002F314 00FF36A4 */  sh         $s6, %lo(D_8003FF00)($at)
    /* 1FB18 8002F318 0300228A */  lwl        $v0, 0x3($s1)
    /* 1FB1C 8002F31C 0000229A */  lwr        $v0, 0x0($s1)
    /* 1FB20 8002F320 0700238A */  lwl        $v1, 0x7($s1)
    /* 1FB24 8002F324 0400239A */  lwr        $v1, 0x4($s1)
    /* 1FB28 8002F328 0B00248A */  lwl        $a0, 0xB($s1)
    /* 1FB2C 8002F32C 0800249A */  lwr        $a0, 0x8($s1)
    /* 1FB30 8002F330 0F00258A */  lwl        $a1, 0xF($s1)
    /* 1FB34 8002F334 0C00259A */  lwr        $a1, 0xC($s1)
    /* 1FB38 8002F338 030082AA */  swl        $v0, 0x3($s4)
    /* 1FB3C 8002F33C 000082BA */  swr        $v0, 0x0($s4)
    /* 1FB40 8002F340 070083AA */  swl        $v1, 0x7($s4)
    /* 1FB44 8002F344 040083BA */  swr        $v1, 0x4($s4)
    /* 1FB48 8002F348 0B0084AA */  swl        $a0, 0xB($s4)
    /* 1FB4C 8002F34C 080084BA */  swr        $a0, 0x8($s4)
    /* 1FB50 8002F350 0F0085AA */  swl        $a1, 0xF($s4)
    /* 1FB54 8002F354 0C0085BA */  swr        $a1, 0xC($s4)
    /* 1FB58 8002F358 1300228A */  lwl        $v0, 0x13($s1)
    /* 1FB5C 8002F35C 1000229A */  lwr        $v0, 0x10($s1)
    /* 1FB60 8002F360 1700238A */  lwl        $v1, 0x17($s1)
    /* 1FB64 8002F364 1400239A */  lwr        $v1, 0x14($s1)
    /* 1FB68 8002F368 1B00248A */  lwl        $a0, 0x1B($s1)
    /* 1FB6C 8002F36C 1800249A */  lwr        $a0, 0x18($s1)
    /* 1FB70 8002F370 1F00258A */  lwl        $a1, 0x1F($s1)
    /* 1FB74 8002F374 1C00259A */  lwr        $a1, 0x1C($s1)
    /* 1FB78 8002F378 130082AA */  swl        $v0, 0x13($s4)
    /* 1FB7C 8002F37C 100082BA */  swr        $v0, 0x10($s4)
    /* 1FB80 8002F380 170083AA */  swl        $v1, 0x17($s4)
    /* 1FB84 8002F384 140083BA */  swr        $v1, 0x14($s4)
    /* 1FB88 8002F388 1B0084AA */  swl        $a0, 0x1B($s4)
    /* 1FB8C 8002F38C 180084BA */  swr        $a0, 0x18($s4)
    /* 1FB90 8002F390 1F0085AA */  swl        $a1, 0x1F($s4)
    /* 1FB94 8002F394 1C0085BA */  swr        $a1, 0x1C($s4)
    /* 1FB98 8002F398 21206002 */  addu       $a0, $s3, $zero
    /* 1FB9C 8002F39C 01005026 */  addiu      $s0, $s2, 0x1
    /* 1FBA0 8002F3A0 21280002 */  addu       $a1, $s0, $zero
    /* 1FBA4 8002F3A4 55BC000C */  jal        func_8002F154
    /* 1FBA8 8002F3A8 21308002 */   addu      $a2, $s4, $zero
    /* 1FBAC 8002F3AC 45005514 */  bne        $v0, $s5, .L8002F4C4
    /* 1FBB0 8002F3B0 21900002 */   addu      $s2, $s0, $zero
    /* 1FBB4 8002F3B4 0F00422A */  slti       $v0, $s2, 0xF
    /* 1FBB8 8002F3B8 C7FF4014 */  bnez       $v0, .L8002F2D8
    /* 1FBBC 8002F3BC 21208002 */   addu      $a0, $s4, $zero
    /* 1FBC0 8002F3C0 21900000 */  addu       $s2, $zero, $zero
    /* 1FBC4 8002F3C4 FFFF1524 */  addiu      $s5, $zero, -0x1
    /* 1FBC8 8002F3C8 21888002 */  addu       $s1, $s4, $zero
    /* 1FBCC 8002F3CC 01001424 */  addiu      $s4, $zero, 0x1
    /* 1FBD0 8002F3D0 0480103C */  lui        $s0, %hi(D_800400D8)
    /* 1FBD4 8002F3D4 D8001026 */  addiu      $s0, $s0, %lo(D_800400D8)
  .L8002F3D8:
    /* 1FBD8 8002F3D8 000015AE */  sw         $s5, 0x0($s0)
    /* 1FBDC 8002F3DC 21202002 */  addu       $a0, $s1, $zero
    /* 1FBE0 8002F3E0 C9B8000C */  jal        bzero
    /* 1FBE4 8002F3E4 80000524 */   addiu     $a1, $zero, 0x80
    /* 1FBE8 8002F3E8 0300028A */  lwl        $v0, 0x3($s0)
    /* 1FBEC 8002F3EC 0000029A */  lwr        $v0, 0x0($s0)
    /* 1FBF0 8002F3F0 00000000 */  nop
    /* 1FBF4 8002F3F4 030022AA */  swl        $v0, 0x3($s1)
    /* 1FBF8 8002F3F8 000022BA */  swr        $v0, 0x0($s1)
    /* 1FBFC 8002F3FC 21206002 */  addu       $a0, $s3, $zero
    /* 1FC00 8002F400 10004526 */  addiu      $a1, $s2, 0x10
    /* 1FC04 8002F404 55BC000C */  jal        func_8002F154
    /* 1FC08 8002F408 21302002 */   addu      $a2, $s1, $zero
    /* 1FC0C 8002F40C 2D005414 */  bne        $v0, $s4, .L8002F4C4
    /* 1FC10 8002F410 01005226 */   addiu     $s2, $s2, 0x1
    /* 1FC14 8002F414 1400422A */  slti       $v0, $s2, 0x14
    /* 1FC18 8002F418 EFFF4014 */  bnez       $v0, .L8002F3D8
    /* 1FC1C 8002F41C 04001026 */   addiu     $s0, $s0, 0x4
    /* 1FC20 8002F420 21802002 */  addu       $s0, $s1, $zero
    /* 1FC24 8002F424 21200002 */  addu       $a0, $s0, $zero
    /* 1FC28 8002F428 C9B8000C */  jal        bzero
    /* 1FC2C 8002F42C 80000524 */   addiu     $a1, $zero, 0x80
    /* 1FC30 8002F430 21206002 */  addu       $a0, $s3, $zero
    /* 1FC34 8002F434 21280000 */  addu       $a1, $zero, $zero
    /* 1FC38 8002F438 21300002 */  addu       $a2, $s0, $zero
    /* 1FC3C 8002F43C 4D000224 */  addiu      $v0, $zero, 0x4D
    /* 1FC40 8002F440 0000C2A0 */  sb         $v0, 0x0($a2)
    /* 1FC44 8002F444 43000224 */  addiu      $v0, $zero, 0x43
    /* 1FC48 8002F448 55BC000C */  jal        func_8002F154
    /* 1FC4C 8002F44C 0100C2A0 */   sb        $v0, 0x1($a2)
    /* 1FC50 8002F450 21804000 */  addu       $s0, $v0, $zero
    /* 1FC54 8002F454 01000224 */  addiu      $v0, $zero, 0x1
    /* 1FC58 8002F458 21000216 */  bne        $s0, $v0, .L8002F4E0
    /* 1FC5C 8002F45C 21100000 */   addu      $v0, $zero, $zero
    /* 1FC60 8002F460 21202002 */  addu       $a0, $s1, $zero
    /* 1FC64 8002F464 C9B8000C */  jal        bzero
    /* 1FC68 8002F468 80000524 */   addiu     $a1, $zero, 0x80
    /* 1FC6C 8002F46C 49BA000C */  jal        _new_card
    /* 1FC70 8002F470 00000000 */   nop
    /* 1FC74 8002F474 21206002 */  addu       $a0, $s3, $zero
    /* 1FC78 8002F478 21280000 */  addu       $a1, $zero, $zero
    /* 1FC7C 8002F47C 45BD000C */  jal        _card_read
    /* 1FC80 8002F480 21302002 */   addu      $a2, $s1, $zero
    /* 1FC84 8002F484 06005014 */  bne        $v0, $s0, .L8002F4A0
    /* 1FC88 8002F488 21800000 */   addu      $s0, $zero, $zero
  .L8002F48C:
    /* 1FC8C 8002F48C 49BD000C */  jal        _card_status
    /* 1FC90 8002F490 03211300 */   sra       $a0, $s3, 4
    /* 1FC94 8002F494 01004230 */  andi       $v0, $v0, 0x1
    /* 1FC98 8002F498 FCFF4010 */  beqz       $v0, .L8002F48C
    /* 1FC9C 8002F49C 01001024 */   addiu     $s0, $zero, 0x1
  .L8002F4A0:
    /* 1FCA0 8002F4A0 01000224 */  addiu      $v0, $zero, 0x1
    /* 1FCA4 8002F4A4 0E000216 */  bne        $s0, $v0, .L8002F4E0
    /* 1FCA8 8002F4A8 21100000 */   addu      $v0, $zero, $zero
    /* 1FCAC 8002F4AC 49BA000C */  jal        _new_card
    /* 1FCB0 8002F4B0 00000000 */   nop
    /* 1FCB4 8002F4B4 31BA000C */  jal        _card_load
    /* 1FCB8 8002F4B8 21206002 */   addu      $a0, $s3, $zero
    /* 1FCBC 8002F4BC 03005010 */  beq        $v0, $s0, .L8002F4CC
    /* 1FCC0 8002F4C0 00000000 */   nop
  .L8002F4C4:
    /* 1FCC4 8002F4C4 38BD0008 */  j          .L8002F4E0
    /* 1FCC8 8002F4C8 21100000 */   addu      $v0, $zero, $zero
  .L8002F4CC:
    /* 1FCCC 8002F4CC 49BD000C */  jal        _card_status
    /* 1FCD0 8002F4D0 03211300 */   sra       $a0, $s3, 4
    /* 1FCD4 8002F4D4 01004230 */  andi       $v0, $v0, 0x1
    /* 1FCD8 8002F4D8 FCFF4010 */  beqz       $v0, .L8002F4CC
    /* 1FCDC 8002F4DC 01000224 */   addiu     $v0, $zero, 0x1
  .L8002F4E0:
    /* 1FCE0 8002F4E0 3400BF8F */  lw         $ra, 0x34($sp)
    /* 1FCE4 8002F4E4 3000BE8F */  lw         $fp, 0x30($sp)
    /* 1FCE8 8002F4E8 2C00B78F */  lw         $s7, 0x2C($sp)
    /* 1FCEC 8002F4EC 2800B68F */  lw         $s6, 0x28($sp)
    /* 1FCF0 8002F4F0 2400B58F */  lw         $s5, 0x24($sp)
    /* 1FCF4 8002F4F4 2000B48F */  lw         $s4, 0x20($sp)
    /* 1FCF8 8002F4F8 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 1FCFC 8002F4FC 1800B28F */  lw         $s2, 0x18($sp)
    /* 1FD00 8002F500 1400B18F */  lw         $s1, 0x14($sp)
    /* 1FD04 8002F504 1000B08F */  lw         $s0, 0x10($sp)
    /* 1FD08 8002F508 0800E003 */  jr         $ra
    /* 1FD0C 8002F50C 3800BD27 */   addiu     $sp, $sp, 0x38
endlabel _card_format
    /* 1FD10 8002F510 00000000 */  nop
