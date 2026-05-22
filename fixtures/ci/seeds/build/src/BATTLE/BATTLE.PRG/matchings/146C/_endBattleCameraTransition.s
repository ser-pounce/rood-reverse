nonmatching _endBattleCameraTransition, 0x14C

glabel _endBattleCameraTransition
    /* AAAC 800732AC E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* AAB0 800732B0 0F80023C */  lui        $v0, %hi(vs_battle_cameraTransition)
    /* AAB4 800732B4 0419448C */  lw         $a0, %lo(vs_battle_cameraTransition)($v0)
    /* AAB8 800732B8 801F023C */  lui        $v0, %hi(D_1F800000)
    /* AABC 800732BC 00004224 */  addiu      $v0, $v0, %lo(D_1F800000)
    /* AAC0 800732C0 34004524 */  addiu      $a1, $v0, 0x34
    /* AAC4 800732C4 1400BFAF */  sw         $ra, 0x14($sp)
    /* AAC8 800732C8 1000B0AF */  sw         $s0, 0x10($sp)
    /* AACC 800732CC 30008224 */  addiu      $v0, $a0, 0x30
  .L800732D0:
    /* AAD0 800732D0 0000868C */  lw         $a2, 0x0($a0)
    /* AAD4 800732D4 0400878C */  lw         $a3, 0x4($a0)
    /* AAD8 800732D8 0800888C */  lw         $t0, 0x8($a0)
    /* AADC 800732DC 0C00898C */  lw         $t1, 0xC($a0)
    /* AAE0 800732E0 0000A6AC */  sw         $a2, 0x0($a1)
    /* AAE4 800732E4 0400A7AC */  sw         $a3, 0x4($a1)
    /* AAE8 800732E8 0800A8AC */  sw         $t0, 0x8($a1)
    /* AAEC 800732EC 0C00A9AC */  sw         $t1, 0xC($a1)
    /* AAF0 800732F0 10008424 */  addiu      $a0, $a0, 0x10
    /* AAF4 800732F4 F6FF8214 */  bne        $a0, $v0, .L800732D0
    /* AAF8 800732F8 1000A524 */   addiu     $a1, $a1, 0x10
    /* AAFC 800732FC 0F80033C */  lui        $v1, %hi(vs_battle_cameraCurrentSpherical)
    /* AB00 80073300 0F80023C */  lui        $v0, %hi(vs_battle_cameraTransition)
    /* AB04 80073304 0419428C */  lw         $v0, %lo(vs_battle_cameraTransition)($v0)
    /* AB08 80073308 D0196324 */  addiu      $v1, $v1, %lo(vs_battle_cameraCurrentSpherical)
    /* AB0C 8007330C 0000868C */  lw         $a2, 0x0($a0)
    /* AB10 80073310 00000000 */  nop
    /* AB14 80073314 0000A6AC */  sw         $a2, 0x0($a1)
    /* AB18 80073318 34004424 */  addiu      $a0, $v0, 0x34
    /* AB1C 8007331C 54004224 */  addiu      $v0, $v0, 0x54
  .L80073320:
    /* AB20 80073320 0000868C */  lw         $a2, 0x0($a0)
    /* AB24 80073324 0400878C */  lw         $a3, 0x4($a0)
    /* AB28 80073328 0800888C */  lw         $t0, 0x8($a0)
    /* AB2C 8007332C 0C00898C */  lw         $t1, 0xC($a0)
    /* AB30 80073330 000066AC */  sw         $a2, 0x0($v1)
    /* AB34 80073334 040067AC */  sw         $a3, 0x4($v1)
    /* AB38 80073338 080068AC */  sw         $t0, 0x8($v1)
    /* AB3C 8007333C 0C0069AC */  sw         $t1, 0xC($v1)
    /* AB40 80073340 10008424 */  addiu      $a0, $a0, 0x10
    /* AB44 80073344 F6FF8214 */  bne        $a0, $v0, .L80073320
    /* AB48 80073348 10006324 */   addiu     $v1, $v1, 0x10
    /* AB4C 8007334C 0F80023C */  lui        $v0, %hi(vs_battle_cameraCurrentSpherical)
    /* AB50 80073350 0F80103C */  lui        $s0, %hi(vs_battle_cameraTransition)
    /* AB54 80073354 0000868C */  lw         $a2, 0x0($a0)
    /* AB58 80073358 0400878C */  lw         $a3, 0x4($a0)
    /* AB5C 8007335C 0800888C */  lw         $t0, 0x8($a0)
    /* AB60 80073360 000066AC */  sw         $a2, 0x0($v1)
    /* AB64 80073364 040067AC */  sw         $a3, 0x4($v1)
    /* AB68 80073368 080068AC */  sw         $t0, 0x8($v1)
    /* AB6C 8007336C D019438C */  lw         $v1, %lo(vs_battle_cameraCurrentSpherical)($v0)
    /* AB70 80073370 0419048E */  lw         $a0, %lo(vs_battle_cameraTransition)($s0)
    /* AB74 80073374 D0194224 */  addiu      $v0, $v0, %lo(vs_battle_cameraCurrentSpherical)
    /* AB78 80073378 140043AC */  sw         $v1, 0x14($v0)
    /* AB7C 8007337C 6000848C */  lw         $a0, 0x60($a0)
    /* AB80 80073380 33F3010C */  jal        vs_battle_setNearClip
    /* AB84 80073384 00000000 */   nop
    /* AB88 80073388 0419028E */  lw         $v0, %lo(vs_battle_cameraTransition)($s0)
    /* AB8C 8007338C 00000000 */  nop
    /* AB90 80073390 6400448C */  lw         $a0, 0x64($v0)
    /* AB94 80073394 3CF3010C */  jal        vs_battle_setProjectionDistance
    /* AB98 80073398 00000000 */   nop
    /* AB9C 8007339C 0419048E */  lw         $a0, %lo(vs_battle_cameraTransition)($s0)
    /* ABA0 800733A0 00000000 */  nop
    /* ABA4 800733A4 04008010 */  beqz       $a0, .L800733B8
    /* ABA8 800733A8 00000000 */   nop
    /* ABAC 800733AC 180F010C */  jal        vs_main_freeHeapR
    /* ABB0 800733B0 00000000 */   nop
    /* ABB4 800733B4 041900AE */  sw         $zero, %lo(vs_battle_cameraTransition)($s0)
  .L800733B8:
    /* ABB8 800733B8 952D030C */  jal        func_800CB654
    /* ABBC 800733BC 21200000 */   addu      $a0, $zero, $zero
    /* ABC0 800733C0 322D020C */  jal        func_8008B4C8
    /* ABC4 800733C4 01000424 */   addiu     $a0, $zero, 0x1
    /* ABC8 800733C8 6535020C */  jal        func_8008D594
    /* ABCC 800733CC 21200000 */   addu      $a0, $zero, $zero
    /* ABD0 800733D0 DC56020C */  jal        func_80095B70
    /* ABD4 800733D4 21200000 */   addu      $a0, $zero, $zero
    /* ABD8 800733D8 1C82020C */  jal        func_800A0870
    /* ABDC 800733DC 21200000 */   addu      $a0, $zero, $zero
    /* ABE0 800733E0 73BD010C */  jal        func_8006F5CC
    /* ABE4 800733E4 00000000 */   nop
    /* ABE8 800733E8 1400BF8F */  lw         $ra, 0x14($sp)
    /* ABEC 800733EC 1000B08F */  lw         $s0, 0x10($sp)
    /* ABF0 800733F0 0800E003 */  jr         $ra
    /* ABF4 800733F4 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel _endBattleCameraTransition
