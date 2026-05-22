nonmatching _printFixedWidthFontChar, 0x1CC

glabel _printFixedWidthFontChar
    /* 5F1D8 800C79D8 F8FFBD27 */  addiu      $sp, $sp, -0x8
    /* 5F1DC 800C79DC 21788000 */  addu       $t7, $a0, $zero
    /* 5F1E0 800C79E0 2158A000 */  addu       $t3, $a1, $zero
    /* 5F1E4 800C79E4 2140C000 */  addu       $t0, $a2, $zero
    /* 5F1E8 800C79E8 2168E000 */  addu       $t5, $a3, $zero
    /* 5F1EC 800C79EC 801F193C */  lui        $t9, (0x1F800000 >> 16)
    /* 5F1F0 800C79F0 1800AE8F */  lw         $t6, 0x18($sp)
    /* 5F1F4 800C79F4 1C00B88F */  lw         $t8, 0x1C($sp)
    /* 5F1F8 800C79F8 00002C8F */  lw         $t4, (0x1F800000 & 0xFFFF)($t9)
    /* 5F1FC 800C79FC 8F000224 */  addiu      $v0, $zero, 0x8F
    /* 5F200 800C7A00 6100E211 */  beq        $t7, $v0, .L800C7B88
    /* 5F204 800C7A04 0000B0AF */   sw        $s0, 0x0($sp)
    /* 5F208 800C7A08 2168AB01 */  addu       $t5, $t5, $t3
    /* 5F20C 800C7A0C 2170C801 */  addu       $t6, $t6, $t0
    /* 5F210 800C7A10 026C0D00 */  srl        $t5, $t5, 16
    /* 5F214 800C7A14 03140800 */  sra        $v0, $t0, 16
    /* 5F218 800C7A18 00440200 */  sll        $t0, $v0, 16
    /* 5F21C 800C7A1C 03140E00 */  sra        $v0, $t6, 16
    /* 5F220 800C7A20 00740200 */  sll        $t6, $v0, 16
    /* 5F224 800C7A24 FF00053C */  lui        $a1, (0xFFFFFF >> 16)
    /* 5F228 800C7A28 0F80023C */  lui        $v0, %hi(_fontTable)
    /* 5F22C 800C7A2C FFFFA534 */  ori        $a1, $a1, (0xFFFFFF & 0xFFFF)
    /* 5F230 800C7A30 0F800A3C */  lui        $t2, %hi(D_800F51B8)
    /* 5F234 800C7A34 0F80043C */  lui        $a0, %hi(D_800F4CB8)
    /* 5F238 800C7A38 B94C4290 */  lbu        $v0, %lo(_fontTable)($v0)
    /* 5F23C 800C7A3C B84C8690 */  lbu        $a2, %lo(D_800F4CB8)($a0)
    /* 5F240 800C7A40 40180200 */  sll        $v1, $v0, 1
    /* 5F244 800C7A44 21186200 */  addu       $v1, $v1, $v0
    /* 5F248 800C7A48 80110300 */  sll        $v0, $v1, 6
    /* 5F24C 800C7A4C 23104300 */  subu       $v0, $v0, $v1
    /* 5F250 800C7A50 2178E201 */  addu       $t7, $t7, $v0
    /* 5F254 800C7A54 0F80023C */  lui        $v0, %hi(vs_battle_characterWidths)
    /* 5F258 800C7A58 10B84224 */  addiu      $v0, $v0, %lo(vs_battle_characterWidths)
    /* 5F25C 800C7A5C 2110E201 */  addu       $v0, $t7, $v0
    /* 5F260 800C7A60 0F80033C */  lui        $v1, %hi(D_800F4E80)
    /* 5F264 800C7A64 00310600 */  sll        $a2, $a2, 4
    /* 5F268 800C7A68 4003C624 */  addiu      $a2, $a2, 0x340
    /* 5F26C 800C7A6C 02310600 */  srl        $a2, $a2, 4
    /* 5F270 800C7A70 3F00C630 */  andi       $a2, $a2, 0x3F
    /* 5F274 800C7A74 8037C634 */  ori        $a2, $a2, 0x3780
    /* 5F278 800C7A78 00004290 */  lbu        $v0, 0x0($v0)
    /* 5F27C 800C7A7C 804E6790 */  lbu        $a3, %lo(D_800F4E80)($v1)
    /* 5F280 800C7A80 18005800 */  mult       $v0, $t8
    /* 5F284 800C7A84 00340600 */  sll        $a2, $a2, 16
    /* 5F288 800C7A88 00390700 */  sll        $a3, $a3, 4
    /* 5F28C 800C7A8C B851428D */  lw         $v0, %lo(D_800F51B8)($t2)
    /* 5F290 800C7A90 0C00E734 */  ori        $a3, $a3, 0xC
    /* 5F294 800C7A94 2110E200 */  addu       $v0, $a3, $v0
    /* 5F298 800C7A98 0000438C */  lw         $v1, 0x0($v0)
    /* 5F29C 800C7A9C 2510A801 */  or         $v0, $t5, $t0
    /* 5F2A0 800C7AA0 100082AD */  sw         $v0, 0x10($t4)
    /* 5F2A4 800C7AA4 0009023C */  lui        $v0, (0x9000000 >> 16)
    /* 5F2A8 800C7AA8 24186500 */  and        $v1, $v1, $a1
    /* 5F2AC 800C7AAC 1886053C */  lui        $a1, (0x86186187 >> 16)
    /* 5F2B0 800C7AB0 8761A534 */  ori        $a1, $a1, (0x86186187 & 0xFFFF)
    /* 5F2B4 800C7AB4 12480000 */  mflo       $t1
    /* 5F2B8 800C7AB8 25186200 */  or         $v1, $v1, $v0
    /* 5F2BC 800C7ABC 0F80023C */  lui        $v0, %hi(_fontBrightness)
    /* 5F2C0 800C7AC0 1900E501 */  multu      $t7, $a1
    /* 5F2C4 800C7AC4 000083AD */  sw         $v1, 0x0($t4)
    /* 5F2C8 800C7AC8 BC4C438C */  lw         $v1, %lo(_fontBrightness)($v0)
    /* 5F2CC 800C7ACC 2510AE01 */  or         $v0, $t5, $t6
    /* 5F2D0 800C7AD0 200082AD */  sw         $v0, 0x20($t4)
    /* 5F2D4 800C7AD4 040083AD */  sw         $v1, 0x4($t4)
    /* 5F2D8 800C7AD8 21C06901 */  addu       $t8, $t3, $t1
    /* 5F2DC 800C7ADC 025C0B00 */  srl        $t3, $t3, 16
    /* 5F2E0 800C7AE0 25406801 */  or         $t0, $t3, $t0
    /* 5F2E4 800C7AE4 25486E01 */  or         $t1, $t3, $t6
    /* 5F2E8 800C7AE8 080088AD */  sw         $t0, 0x8($t4)
    /* 5F2EC 800C7AEC 180089AD */  sw         $t1, 0x18($t4)
    /* 5F2F0 800C7AF0 10280000 */  mfhi       $a1
    /* 5F2F4 800C7AF4 2310E501 */  subu       $v0, $t7, $a1
    /* 5F2F8 800C7AF8 42100200 */  srl        $v0, $v0, 1
    /* 5F2FC 800C7AFC 2128A200 */  addu       $a1, $a1, $v0
    /* 5F300 800C7B00 02290500 */  srl        $a1, $a1, 4
    /* 5F304 800C7B04 80100500 */  sll        $v0, $a1, 2
    /* 5F308 800C7B08 21104500 */  addu       $v0, $v0, $a1
    /* 5F30C 800C7B0C 80100200 */  sll        $v0, $v0, 2
    /* 5F310 800C7B10 21104500 */  addu       $v0, $v0, $a1
    /* 5F314 800C7B14 2310E201 */  subu       $v0, $t7, $v0
    /* 5F318 800C7B18 40180200 */  sll        $v1, $v0, 1
    /* 5F31C 800C7B1C 21186200 */  addu       $v1, $v1, $v0
    /* 5F320 800C7B20 80580300 */  sll        $t3, $v1, 2
    /* 5F324 800C7B24 0C006D25 */  addiu      $t5, $t3, 0xC
    /* 5F328 800C7B28 40200500 */  sll        $a0, $a1, 1
    /* 5F32C 800C7B2C 21208500 */  addu       $a0, $a0, $a1
    /* 5F330 800C7B30 80220400 */  sll        $a0, $a0, 10
    /* 5F334 800C7B34 000C8E24 */  addiu      $t6, $a0, 0xC00
    /* 5F338 800C7B38 21100003 */  addu       $v0, $t8, $zero
    /* 5F33C 800C7B3C 25186401 */  or         $v1, $t3, $a0
    /* 5F340 800C7B40 25186600 */  or         $v1, $v1, $a2
    /* 5F344 800C7B44 2520A401 */  or         $a0, $t5, $a0
    /* 5F348 800C7B48 0C0083AD */  sw         $v1, 0xC($t4)
    /* 5F34C 800C7B4C 0D00033C */  lui        $v1, (0xD0000 >> 16)
    /* 5F350 800C7B50 25208300 */  or         $a0, $a0, $v1
    /* 5F354 800C7B54 25186E01 */  or         $v1, $t3, $t6
    /* 5F358 800C7B58 1C0083AD */  sw         $v1, 0x1C($t4)
    /* 5F35C 800C7B5C 2518AE01 */  or         $v1, $t5, $t6
    /* 5F360 800C7B60 240083AD */  sw         $v1, 0x24($t4)
    /* 5F364 800C7B64 001A0C00 */  sll        $v1, $t4, 8
    /* 5F368 800C7B68 140084AD */  sw         $a0, 0x14($t4)
    /* 5F36C 800C7B6C B851448D */  lw         $a0, %lo(D_800F51B8)($t2)
    /* 5F370 800C7B70 021A0300 */  srl        $v1, $v1, 8
    /* 5F374 800C7B74 2138E400 */  addu       $a3, $a3, $a0
    /* 5F378 800C7B78 0000E3AC */  sw         $v1, 0x0($a3)
    /* 5F37C 800C7B7C 28008325 */  addiu      $v1, $t4, 0x28
    /* 5F380 800C7B80 E61E0308 */  j          .L800C7B98
    /* 5F384 800C7B84 000023AF */   sw        $v1, (0x1F800000 & 0xFFFF)($t9)
  .L800C7B88:
    /* 5F388 800C7B88 40101800 */  sll        $v0, $t8, 1
    /* 5F38C 800C7B8C 21105800 */  addu       $v0, $v0, $t8
    /* 5F390 800C7B90 40100200 */  sll        $v0, $v0, 1
    /* 5F394 800C7B94 21106201 */  addu       $v0, $t3, $v0
  .L800C7B98:
    /* 5F398 800C7B98 0000B08F */  lw         $s0, 0x0($sp)
    /* 5F39C 800C7B9C 0800E003 */  jr         $ra
    /* 5F3A0 800C7BA0 0800BD27 */   addiu     $sp, $sp, 0x8
endlabel _printFixedWidthFontChar
