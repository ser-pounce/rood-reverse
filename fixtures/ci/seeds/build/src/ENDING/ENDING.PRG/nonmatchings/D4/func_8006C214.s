nonmatching func_8006C214, 0x1B8

glabel func_8006C214
    /* 3A14 8006C214 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 3A18 8006C218 1400B1AF */  sw         $s1, 0x14($sp)
    /* 3A1C 8006C21C 0E80113C */  lui        $s1, %hi(D_800DC210)
    /* 3A20 8006C220 10C2228E */  lw         $v0, %lo(D_800DC210)($s1)
    /* 3A24 8006C224 1800BFAF */  sw         $ra, 0x18($sp)
    /* 3A28 8006C228 37004014 */  bnez       $v0, .L8006C308
    /* 3A2C 8006C22C 1000B0AF */   sw        $s0, 0x10($sp)
    /* 3A30 8006C230 0E80103C */  lui        $s0, %hi(D_800DC20C)
    /* 3A34 8006C234 0CC2038E */  lw         $v1, %lo(D_800DC20C)($s0)
    /* 3A38 8006C238 D0000224 */  addiu      $v0, $zero, 0xD0
    /* 3A3C 8006C23C 06006214 */  bne        $v1, $v0, .L8006C258
    /* 3A40 8006C240 7E000424 */   addiu     $a0, $zero, 0x7E
    /* 3A44 8006C244 6216010C */  jal        vs_main_playSfxDefault
    /* 3A48 8006C248 77000524 */   addiu     $a1, $zero, 0x77
    /* 3A4C 8006C24C 7E000424 */  addiu      $a0, $zero, 0x7E
    /* 3A50 8006C250 6216010C */  jal        vs_main_playSfxDefault
    /* 3A54 8006C254 78000524 */   addiu     $a1, $zero, 0x78
  .L8006C258:
    /* 3A58 8006C258 0CC2048E */  lw         $a0, %lo(D_800DC20C)($s0)
    /* 3A5C 8006C25C F3B0010C */  jal        func_8006C3CC
    /* 3A60 8006C260 00000000 */   nop
    /* 3A64 8006C264 A0000424 */  addiu      $a0, $zero, 0xA0
    /* 3A68 8006C268 0CC2068E */  lw         $a2, %lo(D_800DC20C)($s0)
    /* 3A6C 8006C26C 45B1010C */  jal        func_8006C514
    /* 3A70 8006C270 28000524 */   addiu     $a1, $zero, 0x28
    /* 3A74 8006C274 A0000424 */  addiu      $a0, $zero, 0xA0
    /* 3A78 8006C278 50000524 */  addiu      $a1, $zero, 0x50
    /* 3A7C 8006C27C 0CC2068E */  lw         $a2, %lo(D_800DC20C)($s0)
    /* 3A80 8006C280 10C2278E */  lw         $a3, %lo(D_800DC210)($s1)
    /* 3A84 8006C284 D1B1010C */  jal        func_8006C744
    /* 3A88 8006C288 E0FFC624 */   addiu     $a2, $a2, -0x20
    /* 3A8C 8006C28C A0000424 */  addiu      $a0, $zero, 0xA0
    /* 3A90 8006C290 66000524 */  addiu      $a1, $zero, 0x66
    /* 3A94 8006C294 0CC2068E */  lw         $a2, %lo(D_800DC20C)($s0)
    /* 3A98 8006C298 10C2278E */  lw         $a3, %lo(D_800DC210)($s1)
    /* 3A9C 8006C29C BDB2010C */  jal        func_8006CAF4
    /* 3AA0 8006C2A0 90FFC624 */   addiu     $a2, $a2, -0x70
    /* 3AA4 8006C2A4 A0000424 */  addiu      $a0, $zero, 0xA0
    /* 3AA8 8006C2A8 0CC2068E */  lw         $a2, %lo(D_800DC20C)($s0)
    /* 3AAC 8006C2AC 8A000524 */  addiu      $a1, $zero, 0x8A
    /* 3AB0 8006C2B0 4EB3010C */  jal        func_8006CD38
    /* 3AB4 8006C2B4 40FFC624 */   addiu     $a2, $a2, -0xC0
    /* 3AB8 8006C2B8 A0000424 */  addiu      $a0, $zero, 0xA0
    /* 3ABC 8006C2BC 0CC2068E */  lw         $a2, %lo(D_800DC20C)($s0)
    /* 3AC0 8006C2C0 9A000524 */  addiu      $a1, $zero, 0x9A
    /* 3AC4 8006C2C4 65B3010C */  jal        func_8006CD94
    /* 3AC8 8006C2C8 30FFC624 */   addiu     $a2, $a2, -0xD0
    /* 3ACC 8006C2CC 0CC2028E */  lw         $v0, %lo(D_800DC20C)($s0)
    /* 3AD0 8006C2D0 00000000 */  nop
    /* 3AD4 8006C2D4 01104228 */  slti       $v0, $v0, 0x1001
    /* 3AD8 8006C2D8 04004014 */  bnez       $v0, .L8006C2EC
    /* 3ADC 8006C2DC 0680023C */   lui       $v0, %hi(vs_main_buttonsPressed)
    /* 3AE0 8006C2E0 00100224 */  addiu      $v0, $zero, 0x1000
    /* 3AE4 8006C2E4 0CC202AE */  sw         $v0, %lo(D_800DC20C)($s0)
    /* 3AE8 8006C2E8 0680023C */  lui        $v0, %hi(vs_main_buttonsPressed)
  .L8006C2EC:
    /* 3AEC 8006C2EC D0E1428C */  lw         $v0, %lo(vs_main_buttonsPressed)($v0)
    /* 3AF0 8006C2F0 00000000 */  nop
    /* 3AF4 8006C2F4 2B004010 */  beqz       $v0, .L8006C3A4
    /* 3AF8 8006C2F8 01000224 */   addiu     $v0, $zero, 0x1
    /* 3AFC 8006C2FC 10C222AE */  sw         $v0, %lo(D_800DC210)($s1)
    /* 3B00 8006C300 E9B00108 */  j          .L8006C3A4
    /* 3B04 8006C304 0CC200AE */   sw        $zero, %lo(D_800DC20C)($s0)
  .L8006C308:
    /* 3B08 8006C308 0E80103C */  lui        $s0, %hi(D_800DC20C)
    /* 3B0C 8006C30C 0CC2048E */  lw         $a0, %lo(D_800DC20C)($s0)
    /* 3B10 8006C310 08001124 */  addiu      $s1, $zero, 0x8
    /* 3B14 8006C314 F3B0010C */  jal        func_8006C3CC
    /* 3B18 8006C318 23202402 */   subu      $a0, $s1, $a0
    /* 3B1C 8006C31C A0000424 */  addiu      $a0, $zero, 0xA0
    /* 3B20 8006C320 0CC2068E */  lw         $a2, %lo(D_800DC20C)($s0)
    /* 3B24 8006C324 28000524 */  addiu      $a1, $zero, 0x28
    /* 3B28 8006C328 45B1010C */  jal        func_8006C514
    /* 3B2C 8006C32C 23302602 */   subu      $a2, $s1, $a2
    /* 3B30 8006C330 A0000424 */  addiu      $a0, $zero, 0xA0
    /* 3B34 8006C334 50000524 */  addiu      $a1, $zero, 0x50
    /* 3B38 8006C338 0CC2068E */  lw         $a2, %lo(D_800DC20C)($s0)
    /* 3B3C 8006C33C 03000724 */  addiu      $a3, $zero, 0x3
    /* 3B40 8006C340 72B1010C */  jal        func_8006C5C8
    /* 3B44 8006C344 23302602 */   subu      $a2, $s1, $a2
    /* 3B48 8006C348 A0000424 */  addiu      $a0, $zero, 0xA0
    /* 3B4C 8006C34C 66000524 */  addiu      $a1, $zero, 0x66
    /* 3B50 8006C350 0CC2068E */  lw         $a2, %lo(D_800DC20C)($s0)
    /* 3B54 8006C354 03000724 */  addiu      $a3, $zero, 0x3
    /* 3B58 8006C358 6AB2010C */  jal        func_8006C9A8
    /* 3B5C 8006C35C 23302602 */   subu      $a2, $s1, $a2
    /* 3B60 8006C360 A0000424 */  addiu      $a0, $zero, 0xA0
    /* 3B64 8006C364 0CC2068E */  lw         $a2, %lo(D_800DC20C)($s0)
    /* 3B68 8006C368 8A000524 */  addiu      $a1, $zero, 0x8A
    /* 3B6C 8006C36C 4EB3010C */  jal        func_8006CD38
    /* 3B70 8006C370 23302602 */   subu      $a2, $s1, $a2
    /* 3B74 8006C374 A0000424 */  addiu      $a0, $zero, 0xA0
    /* 3B78 8006C378 0CC2068E */  lw         $a2, %lo(D_800DC20C)($s0)
    /* 3B7C 8006C37C 9A000524 */  addiu      $a1, $zero, 0x9A
    /* 3B80 8006C380 65B3010C */  jal        func_8006CD94
    /* 3B84 8006C384 23302602 */   subu      $a2, $s1, $a2
    /* 3B88 8006C388 0CC2028E */  lw         $v0, %lo(D_800DC20C)($s0)
    /* 3B8C 8006C38C 00000000 */  nop
    /* 3B90 8006C390 2A105100 */  slt        $v0, $v0, $s1
    /* 3B94 8006C394 04004014 */  bnez       $v0, .L8006C3A8
    /* 3B98 8006C398 0E80043C */   lui       $a0, %hi(D_800DC20C)
    /* 3B9C 8006C39C EEB00108 */  j          .L8006C3B8
    /* 3BA0 8006C3A0 01000224 */   addiu     $v0, $zero, 0x1
  .L8006C3A4:
    /* 3BA4 8006C3A4 0E80043C */  lui        $a0, %hi(D_800DC20C)
  .L8006C3A8:
    /* 3BA8 8006C3A8 0CC2838C */  lw         $v1, %lo(D_800DC20C)($a0)
    /* 3BAC 8006C3AC 21100000 */  addu       $v0, $zero, $zero
    /* 3BB0 8006C3B0 01006324 */  addiu      $v1, $v1, 0x1
    /* 3BB4 8006C3B4 0CC283AC */  sw         $v1, %lo(D_800DC20C)($a0)
  .L8006C3B8:
    /* 3BB8 8006C3B8 1800BF8F */  lw         $ra, 0x18($sp)
    /* 3BBC 8006C3BC 1400B18F */  lw         $s1, 0x14($sp)
    /* 3BC0 8006C3C0 1000B08F */  lw         $s0, 0x10($sp)
    /* 3BC4 8006C3C4 0800E003 */  jr         $ra
    /* 3BC8 8006C3C8 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_8006C214
