nonmatching func_800D1B80, 0x264

glabel func_800D1B80
    /* 69380 800D1B80 90FFBD27 */  addiu      $sp, $sp, -0x70
    /* 69384 800D1B84 6000B2AF */  sw         $s2, 0x60($sp)
    /* 69388 800D1B88 21908000 */  addu       $s2, $a0, $zero
    /* 6938C 800D1B8C 6800BFAF */  sw         $ra, 0x68($sp)
    /* 69390 800D1B90 6400B3AF */  sw         $s3, 0x64($sp)
    /* 69394 800D1B94 5C00B1AF */  sw         $s1, 0x5C($sp)
    /* 69398 800D1B98 5800B0AF */  sw         $s0, 0x58($sp)
    /* 6939C 800D1B9C 0000518E */  lw         $s1, 0x0($s2)
    /* 693A0 800D1BA0 1000428E */  lw         $v0, 0x10($s2)
    /* 693A4 800D1BA4 0800508E */  lw         $s0, 0x8($s2)
    /* 693A8 800D1BA8 23882202 */  subu       $s1, $s1, $v0
    /* 693AC 800D1BAC 038B1100 */  sra        $s1, $s1, 12
    /* 693B0 800D1BB0 1800428E */  lw         $v0, 0x18($s2)
    /* 693B4 800D1BB4 21202002 */  addu       $a0, $s1, $zero
    /* 693B8 800D1BB8 23800202 */  subu       $s0, $s0, $v0
    /* 693BC 800D1BBC 03831000 */  sra        $s0, $s0, 12
    /* 693C0 800D1BC0 DF04010C */  jal        ratan2
    /* 693C4 800D1BC4 21280002 */   addu      $a1, $s0, $zero
    /* 693C8 800D1BC8 21984000 */  addu       $s3, $v0, $zero
    /* 693CC 800D1BCC C903010C */  jal        rcos
    /* 693D0 800D1BD0 21206002 */   addu      $a0, $s3, $zero
    /* 693D4 800D1BD4 2000438E */  lw         $v1, 0x20($s2)
    /* 693D8 800D1BD8 00000000 */  nop
    /* 693DC 800D1BDC 031B0300 */  sra        $v1, $v1, 12
    /* 693E0 800D1BE0 18004300 */  mult       $v0, $v1
    /* 693E4 800D1BE4 21206002 */  addu       $a0, $s3, $zero
    /* 693E8 800D1BE8 12180000 */  mflo       $v1
    /* 693EC 800D1BEC CA03010C */  jal        rsin
    /* 693F0 800D1BF0 1000A3AF */   sw        $v1, 0x10($sp)
    /* 693F4 800D1BF4 18003102 */  mult       $s1, $s1
    /* 693F8 800D1BF8 12280000 */  mflo       $a1
    /* 693FC 800D1BFC 00000000 */  nop
    /* 69400 800D1C00 00000000 */  nop
    /* 69404 800D1C04 18001002 */  mult       $s0, $s0
    /* 69408 800D1C08 2000438E */  lw         $v1, 0x20($s2)
    /* 6940C 800D1C0C 12200000 */  mflo       $a0
    /* 69410 800D1C10 23100200 */  negu       $v0, $v0
    /* 69414 800D1C14 031B0300 */  sra        $v1, $v1, 12
    /* 69418 800D1C18 18004300 */  mult       $v0, $v1
    /* 6941C 800D1C1C 2120A400 */  addu       $a0, $a1, $a0
    /* 69420 800D1C20 12180000 */  mflo       $v1
    /* 69424 800D1C24 E506010C */  jal        vs_gte_rsqrt
    /* 69428 800D1C28 1800A3AF */   sw        $v1, 0x18($sp)
    /* 6942C 800D1C2C 0400448E */  lw         $a0, 0x4($s2)
    /* 69430 800D1C30 1400438E */  lw         $v1, 0x14($s2)
    /* 69434 800D1C34 21284000 */  addu       $a1, $v0, $zero
    /* 69438 800D1C38 23208300 */  subu       $a0, $a0, $v1
    /* 6943C 800D1C3C DF04010C */  jal        ratan2
    /* 69440 800D1C40 03230400 */   sra       $a0, $a0, 12
    /* 69444 800D1C44 21884000 */  addu       $s1, $v0, $zero
    /* 69448 800D1C48 CA03010C */  jal        rsin
    /* 6944C 800D1C4C 21202002 */   addu      $a0, $s1, $zero
    /* 69450 800D1C50 2800438E */  lw         $v1, 0x28($s2)
    /* 69454 800D1C54 23100200 */  negu       $v0, $v0
    /* 69458 800D1C58 031B0300 */  sra        $v1, $v1, 12
    /* 6945C 800D1C5C 18004300 */  mult       $v0, $v1
    /* 69460 800D1C60 21202002 */  addu       $a0, $s1, $zero
    /* 69464 800D1C64 12180000 */  mflo       $v1
    /* 69468 800D1C68 C903010C */  jal        rcos
    /* 6946C 800D1C6C 1400A3AF */   sw        $v1, 0x14($sp)
    /* 69470 800D1C70 2800438E */  lw         $v1, 0x28($s2)
    /* 69474 800D1C74 23800200 */  negu       $s0, $v0
    /* 69478 800D1C78 031B0300 */  sra        $v1, $v1, 12
    /* 6947C 800D1C7C 18000302 */  mult       $s0, $v1
    /* 69480 800D1C80 12800000 */  mflo       $s0
    /* 69484 800D1C84 C903010C */  jal        rcos
    /* 69488 800D1C88 21202002 */   addu      $a0, $s1, $zero
    /* 6948C 800D1C8C 2400438E */  lw         $v1, 0x24($s2)
    /* 69490 800D1C90 00000000 */  nop
    /* 69494 800D1C94 031B0300 */  sra        $v1, $v1, 12
    /* 69498 800D1C98 18004300 */  mult       $v0, $v1
    /* 6949C 800D1C9C 21202002 */  addu       $a0, $s1, $zero
    /* 694A0 800D1CA0 1400A28F */  lw         $v0, 0x14($sp)
    /* 694A4 800D1CA4 12180000 */  mflo       $v1
    /* 694A8 800D1CA8 21104300 */  addu       $v0, $v0, $v1
    /* 694AC 800D1CAC CA03010C */  jal        rsin
    /* 694B0 800D1CB0 1400A2AF */   sw        $v0, 0x14($sp)
    /* 694B4 800D1CB4 2400438E */  lw         $v1, 0x24($s2)
    /* 694B8 800D1CB8 23100200 */  negu       $v0, $v0
    /* 694BC 800D1CBC 031B0300 */  sra        $v1, $v1, 12
    /* 694C0 800D1CC0 18004300 */  mult       $v0, $v1
    /* 694C4 800D1CC4 21206002 */  addu       $a0, $s3, $zero
    /* 694C8 800D1CC8 12180000 */  mflo       $v1
    /* 694CC 800D1CCC CA03010C */  jal        rsin
    /* 694D0 800D1CD0 21800302 */   addu      $s0, $s0, $v1
    /* 694D4 800D1CD4 03831000 */  sra        $s0, $s0, 12
    /* 694D8 800D1CD8 18005000 */  mult       $v0, $s0
    /* 694DC 800D1CDC 21206002 */  addu       $a0, $s3, $zero
    /* 694E0 800D1CE0 1000A28F */  lw         $v0, 0x10($sp)
    /* 694E4 800D1CE4 12180000 */  mflo       $v1
    /* 694E8 800D1CE8 21104300 */  addu       $v0, $v0, $v1
    /* 694EC 800D1CEC C903010C */  jal        rcos
    /* 694F0 800D1CF0 1000A2AF */   sw        $v0, 0x10($sp)
    /* 694F4 800D1CF4 18005000 */  mult       $v0, $s0
    /* 694F8 800D1CF8 1800A58F */  lw         $a1, 0x18($sp)
    /* 694FC 800D1CFC 12180000 */  mflo       $v1
    /* 69500 800D1D00 2128A300 */  addu       $a1, $a1, $v1
    /* 69504 800D1D04 1800A5AF */  sw         $a1, 0x18($sp)
    /* 69508 800D1D08 0000428E */  lw         $v0, 0x0($s2)
    /* 6950C 800D1D0C 1000A38F */  lw         $v1, 0x10($sp)
    /* 69510 800D1D10 00000000 */  nop
    /* 69514 800D1D14 21104300 */  addu       $v0, $v0, $v1
    /* 69518 800D1D18 2000A2AF */  sw         $v0, 0x20($sp)
    /* 6951C 800D1D1C 0400428E */  lw         $v0, 0x4($s2)
    /* 69520 800D1D20 1400A38F */  lw         $v1, 0x14($sp)
    /* 69524 800D1D24 2000B027 */  addiu      $s0, $sp, 0x20
    /* 69528 800D1D28 21104300 */  addu       $v0, $v0, $v1
    /* 6952C 800D1D2C 2400A2AF */  sw         $v0, 0x24($sp)
    /* 69530 800D1D30 0800428E */  lw         $v0, 0x8($s2)
    /* 69534 800D1D34 21200002 */  addu       $a0, $s0, $zero
    /* 69538 800D1D38 21104500 */  addu       $v0, $v0, $a1
    /* 6953C 800D1D3C 06EB010C */  jal        vs_battle_setCameraPosition
    /* 69540 800D1D40 2800A2AF */   sw        $v0, 0x28($sp)
    /* 69544 800D1D44 1000428E */  lw         $v0, 0x10($s2)
    /* 69548 800D1D48 1000A38F */  lw         $v1, 0x10($sp)
    /* 6954C 800D1D4C 00000000 */  nop
    /* 69550 800D1D50 21104300 */  addu       $v0, $v0, $v1
    /* 69554 800D1D54 2000A2AF */  sw         $v0, 0x20($sp)
    /* 69558 800D1D58 1400428E */  lw         $v0, 0x14($s2)
    /* 6955C 800D1D5C 1400A38F */  lw         $v1, 0x14($sp)
    /* 69560 800D1D60 00000000 */  nop
    /* 69564 800D1D64 21104300 */  addu       $v0, $v0, $v1
    /* 69568 800D1D68 2400A2AF */  sw         $v0, 0x24($sp)
    /* 6956C 800D1D6C 1800428E */  lw         $v0, 0x18($s2)
    /* 69570 800D1D70 1800A38F */  lw         $v1, 0x18($sp)
    /* 69574 800D1D74 21200002 */  addu       $a0, $s0, $zero
    /* 69578 800D1D78 21104300 */  addu       $v0, $v0, $v1
    /* 6957C 800D1D7C 1BEB010C */  jal        vs_battle_setCameraLookAt
    /* 69580 800D1D80 2800A2AF */   sw        $v0, 0x28($sp)
    /* 69584 800D1D84 00800324 */  addiu      $v1, $zero, -0x8000
    /* 69588 800D1D88 2C00448E */  lw         $a0, 0x2C($s2)
    /* 6958C 800D1D8C 3000428E */  lw         $v0, 0x30($s2)
    /* 69590 800D1D90 21208300 */  addu       $a0, $a0, $v1
    /* 69594 800D1D94 25EB010C */  jal        func_8007AC94
    /* 69598 800D1D98 21204400 */   addu      $a0, $v0, $a0
    /* 6959C 800D1D9C 3400448E */  lw         $a0, 0x34($s2)
    /* 695A0 800D1DA0 33F3010C */  jal        vs_battle_setNearClip
    /* 695A4 800D1DA4 00000000 */   nop
    /* 695A8 800D1DA8 3800448E */  lw         $a0, 0x38($s2)
    /* 695AC 800D1DAC 3CF3010C */  jal        vs_battle_setProjectionDistance
    /* 695B0 800D1DB0 00000000 */   nop
    /* 695B4 800D1DB4 3C00448E */  lw         $a0, 0x3C($s2)
    /* 695B8 800D1DB8 45F3010C */  jal        vs_battle_setFarClip
    /* 695BC 800D1DBC 00000000 */   nop
    /* 695C0 800D1DC0 2CEB010C */  jal        func_8007ACB0
    /* 695C4 800D1DC4 00000000 */   nop
    /* 695C8 800D1DC8 6800BF8F */  lw         $ra, 0x68($sp)
    /* 695CC 800D1DCC 6400B38F */  lw         $s3, 0x64($sp)
    /* 695D0 800D1DD0 6000B28F */  lw         $s2, 0x60($sp)
    /* 695D4 800D1DD4 5C00B18F */  lw         $s1, 0x5C($sp)
    /* 695D8 800D1DD8 5800B08F */  lw         $s0, 0x58($sp)
    /* 695DC 800D1DDC 0800E003 */  jr         $ra
    /* 695E0 800D1DE0 7000BD27 */   addiu     $sp, $sp, 0x70
endlabel func_800D1B80
