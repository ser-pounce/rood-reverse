nonmatching func_80074314, 0x60

glabel func_80074314
    /* BB14 80074314 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* BB18 80074318 0F80033C */  lui        $v1, %hi(_cameraMode)
    /* BB1C 8007431C 04000224 */  addiu      $v0, $zero, 0x4
    /* BB20 80074320 F01862AC */  sw         $v0, %lo(_cameraMode)($v1)
    /* BB24 80074324 0680033C */  lui        $v1, %hi(vs_gametime_tickspeed)
    /* BB28 80074328 02000224 */  addiu      $v0, $zero, 0x2
    /* BB2C 8007432C 1400BFAF */  sw         $ra, 0x14($sp)
    /* BB30 80074330 1000B0AF */  sw         $s0, 0x10($sp)
    /* BB34 80074334 432D030C */  jal        func_800CB50C
    /* BB38 80074338 4CE262AC */   sw        $v0, %lo(vs_gametime_tickspeed)($v1)
    /* BB3C 8007433C 0F80103C */  lui        $s0, %hi(D_800F1910)
    /* BB40 80074340 1019048E */  lw         $a0, %lo(D_800F1910)($s0)
    /* BB44 80074344 AB37020C */  jal        func_8008DEAC
    /* BB48 80074348 01000524 */   addiu     $a1, $zero, 0x1
    /* BB4C 8007434C 1019028E */  lw         $v0, %lo(D_800F1910)($s0)
    /* BB50 80074350 00000000 */  nop
    /* BB54 80074354 00004484 */  lh         $a0, 0x0($v0)
    /* BB58 80074358 02004584 */  lh         $a1, 0x2($v0)
    /* BB5C 8007435C 3B9A030C */  jal        func_800E68EC
    /* BB60 80074360 00000000 */   nop
    /* BB64 80074364 1400BF8F */  lw         $ra, 0x14($sp)
    /* BB68 80074368 1000B08F */  lw         $s0, 0x10($sp)
    /* BB6C 8007436C 0800E003 */  jr         $ra
    /* BB70 80074370 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80074314
