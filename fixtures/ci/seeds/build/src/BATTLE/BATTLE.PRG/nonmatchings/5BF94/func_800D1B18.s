nonmatching func_800D1B18, 0x68

glabel func_800D1B18
    /* 69318 800D1B18 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 6931C 800D1B1C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 69320 800D1B20 1400BFAF */  sw         $ra, 0x14($sp)
    /* 69324 800D1B24 FBEA010C */  jal        vs_battle_getCameraPosition
    /* 69328 800D1B28 21808000 */   addu      $s0, $a0, $zero
    /* 6932C 800D1B2C 10EB010C */  jal        vs_battle_getCameraLookAt
    /* 69330 800D1B30 10000426 */   addiu     $a0, $s0, 0x10
    /* 69334 800D1B34 28EB010C */  jal        func_8007ACA0
    /* 69338 800D1B38 00000000 */   nop
    /* 6933C 800D1B3C 00800534 */  ori        $a1, $zero, 0x8000
    /* 69340 800D1B40 0680033C */  lui        $v1, %hi(vs_main_nearClip)
    /* 69344 800D1B44 0680043C */  lui        $a0, %hi(vs_main_projectionDistance)
    /* 69348 800D1B48 C8E0638C */  lw         $v1, %lo(vs_main_nearClip)($v1)
    /* 6934C 800D1B4C 48E2848C */  lw         $a0, %lo(vs_main_projectionDistance)($a0)
    /* 69350 800D1B50 21104500 */  addu       $v0, $v0, $a1
    /* 69354 800D1B54 300002AE */  sw         $v0, 0x30($s0)
    /* 69358 800D1B58 801F023C */  lui        $v0, (0x1F800064 >> 16)
    /* 6935C 800D1B5C 340003AE */  sw         $v1, 0x34($s0)
    /* 69360 800D1B60 380004AE */  sw         $a0, 0x38($s0)
    /* 69364 800D1B64 6400428C */  lw         $v0, (0x1F800064 & 0xFFFF)($v0)
    /* 69368 800D1B68 00000000 */  nop
    /* 6936C 800D1B6C 3C0002AE */  sw         $v0, 0x3C($s0)
    /* 69370 800D1B70 1400BF8F */  lw         $ra, 0x14($sp)
    /* 69374 800D1B74 1000B08F */  lw         $s0, 0x10($sp)
    /* 69378 800D1B78 0800E003 */  jr         $ra
    /* 6937C 800D1B7C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800D1B18
