/* Handwritten function */
nonmatching func_800B3A68, 0x288

glabel func_800B3A68
    /* 4B268 800B3A68 2540E000 */  or         $t0, $a3, $zero
    /* 4B26C 800B3A6C 801F073C */  lui        $a3, (0x1F800378 >> 16)
    /* 4B270 800B3A70 5803F0AC */  sw         $s0, (0x1F800358 & 0xFFFF)($a3)
    /* 4B274 800B3A74 5C03F1AC */  sw         $s1, (0x1F80035C & 0xFFFF)($a3)
    /* 4B278 800B3A78 6003F2AC */  sw         $s2, (0x1F800360 & 0xFFFF)($a3)
    /* 4B27C 800B3A7C 6403F3AC */  sw         $s3, (0x1F800364 & 0xFFFF)($a3)
    /* 4B280 800B3A80 6803F4AC */  sw         $s4, (0x1F800368 & 0xFFFF)($a3)
    /* 4B284 800B3A84 6C03F5AC */  sw         $s5, (0x1F80036C & 0xFFFF)($a3)
    /* 4B288 800B3A88 7003F6AC */  sw         $s6, (0x1F800370 & 0xFFFF)($a3)
    /* 4B28C 800B3A8C 7403F7AC */  sw         $s7, (0x1F800374 & 0xFFFF)($a3)
    /* 4B290 800B3A90 7803FCAC */  sw         $gp, (0x1F800378 & 0xFFFF)($a3)
    /* 4B294 800B3A94 01008790 */  lbu        $a3, 0x1($a0)
    /* 4B298 800B3A98 34000A8D */  lw         $t2, 0x34($t0)
    /* 4B29C 800B3A9C 38000D8D */  lw         $t5, 0x38($t0)
    /* 4B2A0 800B3AA0 25700000 */  or         $t6, $zero, $zero
    /* 4B2A4 800B3AA4 25B0A001 */  or         $s6, $t5, $zero
    /* 4B2A8 800B3AA8 25B80000 */  or         $s7, $zero, $zero
    /* 4B2AC 800B3AAC 0000D08E */  lw         $s0, 0x0($s6)
    /* 4B2B0 800B3AB0 0400D18E */  lw         $s1, 0x4($s6)
    /* 4B2B4 800B3AB4 0800D28E */  lw         $s2, 0x8($s6)
    /* 4B2B8 800B3AB8 0C00D38E */  lw         $s3, 0xC($s6)
    /* 4B2BC 800B3ABC 1000D48E */  lw         $s4, 0x10($s6)
    /* 4B2C0 800B3AC0 1400D58E */  lw         $s5, 0x14($s6)
    /* 4B2C4 800B3AC4 00004B8D */  lw         $t3, 0x0($t2)
    /* 4B2C8 800B3AC8 0F801C3C */  lui        $gp, %hi(D_800F2458)
    /* 4B2CC 800B3ACC 58249C27 */  addiu      $gp, $gp, %lo(D_800F2458)
  .L800B3AD0:
    /* 4B2D0 800B3AD0 02640B00 */  srl        $t4, $t3, 16
  .L800B3AD4:
    /* 4B2D4 800B3AD4 FFFF8C21 */  addi       $t4, $t4, -0x1 /* handwritten instruction */
    /* 4B2D8 800B3AD8 FFFF6B31 */  andi       $t3, $t3, 0xFFFF
    /* 4B2DC 800B3ADC 40590B00 */  sll        $t3, $t3, 5
  .L800B3AE0:
    /* 4B2E0 800B3AE0 20586501 */  add        $t3, $t3, $a1 /* handwritten instruction */
    /* 4B2E4 800B3AE4 0000628D */  lw         $v0, 0x0($t3)
    /* 4B2E8 800B3AE8 0400638D */  lw         $v1, 0x4($t3)
    /* 4B2EC 800B3AEC 0800788D */  lw         $t8, 0x8($t3)
    /* 4B2F0 800B3AF0 0C00798D */  lw         $t9, 0xC($t3)
    /* 4B2F4 800B3AF4 0000C248 */  ctc2       $v0, $0 /* handwritten instruction */
    /* 4B2F8 800B3AF8 0008C348 */  ctc2       $v1, $1 /* handwritten instruction */
    /* 4B2FC 800B3AFC 0010D848 */  ctc2       $t8, $2 /* handwritten instruction */
    /* 4B300 800B3B00 0018D948 */  ctc2       $t9, $3 /* handwritten instruction */
    /* 4B304 800B3B04 1000628D */  lw         $v0, 0x10($t3)
    /* 4B308 800B3B08 1400638D */  lw         $v1, 0x14($t3)
    /* 4B30C 800B3B0C 1800788D */  lw         $t8, 0x18($t3)
    /* 4B310 800B3B10 1C00798D */  lw         $t9, 0x1C($t3)
    /* 4B314 800B3B14 0020C248 */  ctc2       $v0, $4 /* handwritten instruction */
    /* 4B318 800B3B18 0028C348 */  ctc2       $v1, $5 /* handwritten instruction */
    /* 4B31C 800B3B1C 0030D848 */  ctc2       $t8, $6 /* handwritten instruction */
    /* 4B320 800B3B20 0038D948 */  ctc2       $t9, $7 /* handwritten instruction */
    /* 4B324 800B3B24 22108E01 */  sub        $v0, $t4, $t6 /* handwritten instruction */
  .L800B3B28:
    /* 4B328 800B3B28 FEFF4220 */  addi       $v0, $v0, -0x2 /* handwritten instruction */
    /* 4B32C 800B3B2C 28004004 */  bltz       $v0, .L800B3BD0
    /* 4B330 800B3B30 00009048 */   mtc2      $s0, $0 /* handwritten instruction */
    /* 4B334 800B3B34 00089148 */  mtc2       $s1, $1 /* handwritten instruction */
    /* 4B338 800B3B38 00109248 */  mtc2       $s2, $2 /* handwritten instruction */
    /* 4B33C 800B3B3C 00189348 */  mtc2       $s3, $3 /* handwritten instruction */
    /* 4B340 800B3B40 00209448 */  mtc2       $s4, $4 /* handwritten instruction */
    /* 4B344 800B3B44 00289548 */  mtc2       $s5, $5 /* handwritten instruction */
    /* 4B348 800B3B48 80100E00 */  sll        $v0, $t6, 2
    /* 4B34C 800B3B4C 000C4320 */  addi       $v1, $v0, 0xC00 /* handwritten instruction */
    /* 4B350 800B3B50 3000284A */  rtpt
    /* 4B354 800B3B54 20485C00 */  add        $t1, $v0, $gp /* handwritten instruction */
    /* 4B358 800B3B58 1800D08E */  lw         $s0, 0x18($s6)
    /* 4B35C 800B3B5C 1C00D18E */  lw         $s1, 0x1C($s6)
    /* 4B360 800B3B60 2000D28E */  lw         $s2, 0x20($s6)
    /* 4B364 800B3B64 2400D38E */  lw         $s3, 0x24($s6)
    /* 4B368 800B3B68 2800D48E */  lw         $s4, 0x28($s6)
    /* 4B36C 800B3B6C 2C00D58E */  lw         $s5, 0x2C($s6)
    /* 4B370 800B3B70 0300CE21 */  addi       $t6, $t6, 0x3 /* handwritten instruction */
    /* 4B374 800B3B74 22108E01 */  sub        $v0, $t4, $t6 /* handwritten instruction */
    /* 4B378 800B3B78 03004104 */  bgez       $v0, .L800B3B88
    /* 4B37C 800B3B7C 20187C00 */   add       $v1, $v1, $gp /* handwritten instruction */
    /* 4B380 800B3B80 04004A21 */  addi       $t2, $t2, 0x4 /* handwritten instruction */
    /* 4B384 800B3B84 00004B8D */  lw         $t3, 0x0($t2)
  .L800B3B88:
    /* 4B388 800B3B88 00880F48 */  mfc2       $t7, $17 /* handwritten instruction */
    /* 4B38C 800B3B8C 00901848 */  mfc2       $t8, $18 /* handwritten instruction */
    /* 4B390 800B3B90 00981948 */  mfc2       $t9, $19 /* handwritten instruction */
    /* 4B394 800B3B94 25B8EF02 */  or         $s7, $s7, $t7
    /* 4B398 800B3B98 00006FAC */  sw         $t7, 0x0($v1)
    /* 4B39C 800B3B9C 25B8F802 */  or         $s7, $s7, $t8
    /* 4B3A0 800B3BA0 040078AC */  sw         $t8, 0x4($v1)
    /* 4B3A4 800B3BA4 25B8F902 */  or         $s7, $s7, $t9
    /* 4B3A8 800B3BA8 080079AC */  sw         $t9, 0x8($v1)
    /* 4B3AC 800B3BAC 00002CE9 */  swc2       $12, 0x0($t1)
    /* 4B3B0 800B3BB0 04002DE9 */  swc2       $13, 0x4($t1)
    /* 4B3B4 800B3BB4 08002EE9 */  swc2       $14, 0x8($t1)
    /* 4B3B8 800B3BB8 DBFF4104 */  bgez       $v0, .L800B3B28
    /* 4B3BC 800B3BBC 1800D622 */   addi      $s6, $s6, 0x18 /* handwritten instruction */
    /* 4B3C0 800B3BC0 FFFFE720 */  addi       $a3, $a3, -0x1 /* handwritten instruction */
    /* 4B3C4 800B3BC4 3E00E010 */  beqz       $a3, .L800B3CC0
    /* 4B3C8 800B3BC8 02640B00 */   srl       $t4, $t3, 16
    /* 4B3CC 800B3BCC B5CE0208 */  j          .L800B3AD4
  .L800B3BD0:
    /* 4B3D0 800B3BD0 01004220 */   addi      $v0, $v0, 0x1 /* handwritten instruction */
    /* 4B3D4 800B3BD4 22004004 */  bltz       $v0, .L800B3C60
    /* 4B3D8 800B3BD8 00009048 */   mtc2      $s0, $0 /* handwritten instruction */
    /* 4B3DC 800B3BDC 00089148 */  mtc2       $s1, $1 /* handwritten instruction */
    /* 4B3E0 800B3BE0 00109248 */  mtc2       $s2, $2 /* handwritten instruction */
    /* 4B3E4 800B3BE4 00189348 */  mtc2       $s3, $3 /* handwritten instruction */
    /* 4B3E8 800B3BE8 80100E00 */  sll        $v0, $t6, 2
    /* 4B3EC 800B3BEC 000C4320 */  addi       $v1, $v0, 0xC00 /* handwritten instruction */
    /* 4B3F0 800B3BF0 3000284A */  rtpt
    /* 4B3F4 800B3BF4 20105C00 */  add        $v0, $v0, $gp /* handwritten instruction */
    /* 4B3F8 800B3BF8 20187C00 */  add        $v1, $v1, $gp /* handwritten instruction */
    /* 4B3FC 800B3BFC 25808002 */  or         $s0, $s4, $zero
    /* 4B400 800B3C00 2588A002 */  or         $s1, $s5, $zero
    /* 4B404 800B3C04 1800D28E */  lw         $s2, 0x18($s6)
    /* 4B408 800B3C08 1C00D38E */  lw         $s3, 0x1C($s6)
    /* 4B40C 800B3C0C 2000D48E */  lw         $s4, 0x20($s6)
    /* 4B410 800B3C10 2400D58E */  lw         $s5, 0x24($s6)
    /* 4B414 800B3C14 0200CE21 */  addi       $t6, $t6, 0x2 /* handwritten instruction */
    /* 4B418 800B3C18 04004A21 */  addi       $t2, $t2, 0x4 /* handwritten instruction */
    /* 4B41C 800B3C1C 00004B8D */  lw         $t3, 0x0($t2)
    /* 4B420 800B3C20 1000D622 */  addi       $s6, $s6, 0x10 /* handwritten instruction */
    /* 4B424 800B3C24 02640B00 */  srl        $t4, $t3, 16
    /* 4B428 800B3C28 FFFF8C21 */  addi       $t4, $t4, -0x1 /* handwritten instruction */
    /* 4B42C 800B3C2C FFFF6B31 */  andi       $t3, $t3, 0xFFFF
    /* 4B430 800B3C30 00880F48 */  mfc2       $t7, $17 /* handwritten instruction */
    /* 4B434 800B3C34 00901848 */  mfc2       $t8, $18 /* handwritten instruction */
    /* 4B438 800B3C38 25B8EF02 */  or         $s7, $s7, $t7
    /* 4B43C 800B3C3C 00006FAC */  sw         $t7, 0x0($v1)
    /* 4B440 800B3C40 25B8F802 */  or         $s7, $s7, $t8
    /* 4B444 800B3C44 040078AC */  sw         $t8, 0x4($v1)
    /* 4B448 800B3C48 00004CE8 */  swc2       $12, 0x0($v0)
    /* 4B44C 800B3C4C 04004DE8 */  swc2       $13, 0x4($v0)
    /* 4B450 800B3C50 FFFFE720 */  addi       $a3, $a3, -0x1 /* handwritten instruction */
    /* 4B454 800B3C54 1A00E010 */  beqz       $a3, .L800B3CC0
    /* 4B458 800B3C58 40590B00 */   sll       $t3, $t3, 5
    /* 4B45C 800B3C5C B8CE0208 */  j          .L800B3AE0
  .L800B3C60:
    /* 4B460 800B3C60 00009048 */   mtc2      $s0, $0 /* handwritten instruction */
    /* 4B464 800B3C64 00089148 */  mtc2       $s1, $1 /* handwritten instruction */
    /* 4B468 800B3C68 80100E00 */  sll        $v0, $t6, 2
    /* 4B46C 800B3C6C 000C4320 */  addi       $v1, $v0, 0xC00 /* handwritten instruction */
    /* 4B470 800B3C70 0100184A */  rtps
    /* 4B474 800B3C74 20105C00 */  add        $v0, $v0, $gp /* handwritten instruction */
    /* 4B478 800B3C78 20187C00 */  add        $v1, $v1, $gp /* handwritten instruction */
    /* 4B47C 800B3C7C 25804002 */  or         $s0, $s2, $zero
    /* 4B480 800B3C80 25886002 */  or         $s1, $s3, $zero
    /* 4B484 800B3C84 25908002 */  or         $s2, $s4, $zero
    /* 4B488 800B3C88 2598A002 */  or         $s3, $s5, $zero
    /* 4B48C 800B3C8C 1800D48E */  lw         $s4, 0x18($s6)
    /* 4B490 800B3C90 1C00D58E */  lw         $s5, 0x1C($s6)
    /* 4B494 800B3C94 04004A21 */  addi       $t2, $t2, 0x4 /* handwritten instruction */
    /* 4B498 800B3C98 00004B8D */  lw         $t3, 0x0($t2)
    /* 4B49C 800B3C9C 00980F48 */  mfc2       $t7, $19 /* handwritten instruction */
    /* 4B4A0 800B3CA0 00004EE8 */  swc2       $14, 0x0($v0)
    /* 4B4A4 800B3CA4 25B8EF02 */  or         $s7, $s7, $t7
    /* 4B4A8 800B3CA8 00006FAC */  sw         $t7, 0x0($v1)
    /* 4B4AC 800B3CAC FFFFE720 */  addi       $a3, $a3, -0x1 /* handwritten instruction */
    /* 4B4B0 800B3CB0 0300E010 */  beqz       $a3, .L800B3CC0
    /* 4B4B4 800B3CB4 0800D622 */   addi      $s6, $s6, 0x8 /* handwritten instruction */
    /* 4B4B8 800B3CB8 B4CE0208 */  j          .L800B3AD0
    /* 4B4BC 800B3CBC 0100CE21 */   addi      $t6, $t6, 0x1 /* handwritten instruction */
  .L800B3CC0:
    /* 4B4C0 800B3CC0 2510E002 */  or         $v0, $s7, $zero
    /* 4B4C4 800B3CC4 801F073C */  lui        $a3, (0x1F800378 >> 16)
    /* 4B4C8 800B3CC8 5803F08C */  lw         $s0, (0x1F800358 & 0xFFFF)($a3)
    /* 4B4CC 800B3CCC 5C03F18C */  lw         $s1, (0x1F80035C & 0xFFFF)($a3)
    /* 4B4D0 800B3CD0 6003F28C */  lw         $s2, (0x1F800360 & 0xFFFF)($a3)
    /* 4B4D4 800B3CD4 6403F38C */  lw         $s3, (0x1F800364 & 0xFFFF)($a3)
    /* 4B4D8 800B3CD8 6803F48C */  lw         $s4, (0x1F800368 & 0xFFFF)($a3)
    /* 4B4DC 800B3CDC 6C03F58C */  lw         $s5, (0x1F80036C & 0xFFFF)($a3)
    /* 4B4E0 800B3CE0 7003F68C */  lw         $s6, (0x1F800370 & 0xFFFF)($a3)
    /* 4B4E4 800B3CE4 7403F78C */  lw         $s7, (0x1F800374 & 0xFFFF)($a3)
    /* 4B4E8 800B3CE8 0800E003 */  jr         $ra
    /* 4B4EC 800B3CEC 7803FC8C */   lw        $gp, (0x1F800378 & 0xFFFF)($a3)
endlabel func_800B3A68
