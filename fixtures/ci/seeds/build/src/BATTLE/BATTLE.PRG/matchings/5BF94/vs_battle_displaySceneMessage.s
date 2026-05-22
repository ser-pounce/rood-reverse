nonmatching vs_battle_displaySceneMessage, 0x1A4

glabel vs_battle_displaySceneMessage
    /* 62AB8 800CB2B8 C8FFBD27 */  addiu      $sp, $sp, -0x38
    /* 62ABC 800CB2BC 2C00B3AF */  sw         $s3, 0x2C($sp)
    /* 62AC0 800CB2C0 21988000 */  addu       $s3, $a0, $zero
    /* 62AC4 800CB2C4 2400B1AF */  sw         $s1, 0x24($sp)
    /* 62AC8 800CB2C8 2188A000 */  addu       $s1, $a1, $zero
    /* 62ACC 800CB2CC 2000B0AF */  sw         $s0, 0x20($sp)
    /* 62AD0 800CB2D0 2180C000 */  addu       $s0, $a2, $zero
    /* 62AD4 800CB2D4 70000424 */  addiu      $a0, $zero, 0x70
    /* 62AD8 800CB2D8 3000BFAF */  sw         $ra, 0x30($sp)
    /* 62ADC 800CB2DC 8F0F010C */  jal        vs_main_allocHeapR
    /* 62AE0 800CB2E0 2800B2AF */   sw        $s2, 0x28($sp)
    /* 62AE4 800CB2E4 0F80123C */  lui        $s2, %hi(D_800EB9D8)
    /* 62AE8 800CB2E8 D8B942AE */  sw         $v0, %lo(D_800EB9D8)($s2)
    /* 62AEC 800CB2EC 0F80023C */  lui        $v0, %hi(D_800F4E69)
    /* 62AF0 800CB2F0 694E50A0 */  sb         $s0, %lo(D_800F4E69)($v0)
    /* 62AF4 800CB2F4 FF001032 */  andi       $s0, $s0, 0xFF
    /* 62AF8 800CB2F8 03000012 */  beqz       $s0, .L800CB308
    /* 62AFC 800CB2FC 0F80033C */   lui       $v1, %hi(D_800F4E68)
    /* 62B00 800CB300 78000224 */  addiu      $v0, $zero, 0x78
    /* 62B04 800CB304 684E62A0 */  sb         $v0, %lo(D_800F4E68)($v1)
  .L800CB308:
    /* 62B08 800CB308 07000424 */  addiu      $a0, $zero, 0x7
    /* 62B0C 800CB30C 04030524 */  addiu      $a1, $zero, 0x304
    /* 62B10 800CB310 03000224 */  addiu      $v0, $zero, 0x3
    /* 62B14 800CB314 21300000 */  addu       $a2, $zero, $zero
    /* 62B18 800CB318 01000724 */  addiu      $a3, $zero, 0x1
    /* 62B1C 800CB31C 1000A0AF */  sw         $zero, 0x10($sp)
    /* 62B20 800CB320 1400A2AF */  sw         $v0, 0x14($sp)
    /* 62B24 800CB324 1800A0AF */  sw         $zero, 0x18($sp)
    /* 62B28 800CB328 C233030C */  jal        vs_battle_initTextBox
    /* 62B2C 800CB32C 1C00A0AF */   sw        $zero, 0x1C($sp)
    /* 62B30 800CB330 FB04033C */  lui        $v1, (0x4FB00F8 >> 16)
    /* 62B34 800CB334 D8B9428E */  lw         $v0, %lo(D_800EB9D8)($s2)
    /* 62B38 800CB338 F8006334 */  ori        $v1, $v1, (0x4FB00F8 & 0xFFFF)
    /* 62B3C 800CB33C 000043AC */  sw         $v1, 0x0($v0)
    /* 62B40 800CB340 0F80023C */  lui        $v0, %hi(vs_battle_stringContext)
    /* 62B44 800CB344 68514424 */  addiu      $a0, $v0, %lo(vs_battle_stringContext)
    /* 62B48 800CB348 40101100 */  sll        $v0, $s1, 1
    /* 62B4C 800CB34C 21105100 */  addu       $v0, $v0, $s1
    /* 62B50 800CB350 80100200 */  sll        $v0, $v0, 2
    /* 62B54 800CB354 21105100 */  addu       $v0, $v0, $s1
    /* 62B58 800CB358 80280200 */  sll        $a1, $v0, 2
    /* 62B5C 800CB35C 0580023C */  lui        $v0, %hi(D_8004B9F8)
    /* 62B60 800CB360 F8B94624 */  addiu      $a2, $v0, %lo(D_8004B9F8)
    /* 62B64 800CB364 2110A600 */  addu       $v0, $a1, $a2
    /* 62B68 800CB368 280082AC */  sw         $v0, 0x28($a0)
    /* 62B6C 800CB36C 0C000224 */  addiu      $v0, $zero, 0xC
    /* 62B70 800CB370 06006216 */  bne        $s3, $v0, .L800CB38C
    /* 62B74 800CB374 0B000224 */   addiu     $v0, $zero, 0xB
    /* 62B78 800CB378 D8B9448E */  lw         $a0, %lo(D_800EB9D8)($s2)
    /* 62B7C 800CB37C 0F80053C */  lui        $a1, %hi(D_800EBB9C)
    /* 62B80 800CB380 9CBBA524 */  addiu      $a1, $a1, %lo(D_800EBB9C)
    /* 62B84 800CB384 0A2D0308 */  j          .L800CB428
    /* 62B88 800CB388 04008424 */   addiu     $a0, $a0, 0x4
  .L800CB38C:
    /* 62B8C 800CB38C 15006216 */  bne        $s3, $v0, .L800CB3E4
    /* 62B90 800CB390 0F80033C */   lui       $v1, %hi(vs_battle_textBoxes)
    /* 62B94 800CB394 E04F6324 */  addiu      $v1, $v1, %lo(vs_battle_textBoxes)
    /* 62B98 800CB398 5001628C */  lw         $v0, 0x150($v1)
    /* 62B9C 800CB39C FFF00424 */  addiu      $a0, $zero, -0xF01
    /* 62BA0 800CB3A0 24104400 */  and        $v0, $v0, $a0
    /* 62BA4 800CB3A4 500162AC */  sw         $v0, 0x150($v1)
    /* 62BA8 800CB3A8 0F80033C */  lui        $v1, %hi(vs_battle_menuStrings)
    /* 62BAC 800CB3AC 2110C500 */  addu       $v0, $a2, $a1
    /* 62BB0 800CB3B0 DCB96324 */  addiu      $v1, $v1, %lo(vs_battle_menuStrings)
    /* 62BB4 800CB3B4 E4FF428C */  lw         $v0, -0x1C($v0)
    /* 62BB8 800CB3B8 D8B9448E */  lw         $a0, %lo(D_800EB9D8)($s2)
    /* 62BBC 800CB3BC 42140200 */  srl        $v0, $v0, 17
    /* 62BC0 800CB3C0 07004230 */  andi       $v0, $v0, 0x7
    /* 62BC4 800CB3C4 16004224 */  addiu      $v0, $v0, 0x16
    /* 62BC8 800CB3C8 40100200 */  sll        $v0, $v0, 1
    /* 62BCC 800CB3CC 21104300 */  addu       $v0, $v0, $v1
    /* 62BD0 800CB3D0 00004594 */  lhu        $a1, 0x0($v0)
    /* 62BD4 800CB3D4 04008424 */  addiu      $a0, $a0, 0x4
    /* 62BD8 800CB3D8 40280500 */  sll        $a1, $a1, 1
    /* 62BDC 800CB3DC 0A2D0308 */  j          .L800CB428
    /* 62BE0 800CB3E0 2128A300 */   addu      $a1, $a1, $v1
  .L800CB3E4:
    /* 62BE4 800CB3E4 08002012 */  beqz       $s1, .L800CB408
    /* 62BE8 800CB3E8 36FE2226 */   addiu     $v0, $s1, -0x1CA
    /* 62BEC 800CB3EC 40180200 */  sll        $v1, $v0, 1
    /* 62BF0 800CB3F0 21186200 */  addu       $v1, $v1, $v0
    /* 62BF4 800CB3F4 C0180300 */  sll        $v1, $v1, 3
    /* 62BF8 800CB3F8 0F80023C */  lui        $v0, %hi(D_800EBF58)
    /* 62BFC 800CB3FC 58BF4224 */  addiu      $v0, $v0, %lo(D_800EBF58)
    /* 62C00 800CB400 21186200 */  addu       $v1, $v1, $v0
    /* 62C04 800CB404 280083AC */  sw         $v1, 0x28($a0)
  .L800CB408:
    /* 62C08 800CB408 0F80053C */  lui        $a1, %hi(D_800EBDDC)
    /* 62C0C 800CB40C DCBDA524 */  addiu      $a1, $a1, %lo(D_800EBDDC)
    /* 62C10 800CB410 40101300 */  sll        $v0, $s3, 1
    /* 62C14 800CB414 21104500 */  addu       $v0, $v0, $a1
    /* 62C18 800CB418 00004294 */  lhu        $v0, 0x0($v0)
    /* 62C1C 800CB41C D8B9448E */  lw         $a0, %lo(D_800EB9D8)($s2)
    /* 62C20 800CB420 40100200 */  sll        $v0, $v0, 1
    /* 62C24 800CB424 21284500 */  addu       $a1, $v0, $a1
  .L800CB428:
    /* 62C28 800CB428 171A030C */  jal        vs_battle_printf
    /* 62C2C 800CB42C 00000000 */   nop
    /* 62C30 800CB430 0F80023C */  lui        $v0, %hi(D_800EB9D8)
    /* 62C34 800CB434 D8B9458C */  lw         $a1, %lo(D_800EB9D8)($v0)
    /* 62C38 800CB438 FC1A030C */  jal        vs_battle_setTextBox
    /* 62C3C 800CB43C 07000424 */   addiu     $a0, $zero, 0x7
    /* 62C40 800CB440 3000BF8F */  lw         $ra, 0x30($sp)
    /* 62C44 800CB444 2C00B38F */  lw         $s3, 0x2C($sp)
    /* 62C48 800CB448 2800B28F */  lw         $s2, 0x28($sp)
    /* 62C4C 800CB44C 2400B18F */  lw         $s1, 0x24($sp)
    /* 62C50 800CB450 2000B08F */  lw         $s0, 0x20($sp)
    /* 62C54 800CB454 0800E003 */  jr         $ra
    /* 62C58 800CB458 3800BD27 */   addiu     $sp, $sp, 0x38
endlabel vs_battle_displaySceneMessage
