nonmatching func_800A38E0, 0x2E4

glabel func_800A38E0
    /* 3B0E0 800A38E0 C8FFBD27 */  addiu      $sp, $sp, -0x38
    /* 3B0E4 800A38E4 0F80023C */  lui        $v0, %hi(D_800F4538)
    /* 3B0E8 800A38E8 38454224 */  addiu      $v0, $v0, %lo(D_800F4538)
    /* 3B0EC 800A38EC 80200400 */  sll        $a0, $a0, 2
    /* 3B0F0 800A38F0 21208200 */  addu       $a0, $a0, $v0
    /* 3B0F4 800A38F4 3000BFAF */  sw         $ra, 0x30($sp)
    /* 3B0F8 800A38F8 2C00B7AF */  sw         $s7, 0x2C($sp)
    /* 3B0FC 800A38FC 2800B6AF */  sw         $s6, 0x28($sp)
    /* 3B100 800A3900 2400B5AF */  sw         $s5, 0x24($sp)
    /* 3B104 800A3904 2000B4AF */  sw         $s4, 0x20($sp)
    /* 3B108 800A3908 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 3B10C 800A390C 1800B2AF */  sw         $s2, 0x18($sp)
    /* 3B110 800A3910 1400B1AF */  sw         $s1, 0x14($sp)
    /* 3B114 800A3914 1000B0AF */  sw         $s0, 0x10($sp)
    /* 3B118 800A3918 0000918C */  lw         $s1, 0x0($a0)
    /* 3B11C 800A391C 00000000 */  nop
    /* 3B120 800A3920 9C002012 */  beqz       $s1, .L800A3B94
    /* 3B124 800A3924 FFFF0224 */   addiu     $v0, $zero, -0x1
    /* 3B128 800A3928 AC05228E */  lw         $v0, 0x5AC($s1)
    /* 3B12C 800A392C 00000000 */  nop
    /* 3B130 800A3930 03004230 */  andi       $v0, $v0, 0x3
    /* 3B134 800A3934 97004014 */  bnez       $v0, .L800A3B94
    /* 3B138 800A3938 FFFF0224 */   addiu     $v0, $zero, -0x1
    /* 3B13C 800A393C 0800238E */  lw         $v1, 0x8($s1)
    /* 3B140 800A3940 0700023C */  lui        $v0, (0x70000 >> 16)
    /* 3B144 800A3944 24106200 */  and        $v0, $v1, $v0
    /* 3B148 800A3948 92004014 */  bnez       $v0, .L800A3B94
    /* 3B14C 800A394C FFFF0224 */   addiu     $v0, $zero, -0x1
    /* 3B150 800A3950 1800023C */  lui        $v0, (0x180000 >> 16)
    /* 3B154 800A3954 24106200 */  and        $v0, $v1, $v0
    /* 3B158 800A3958 8D004014 */  bnez       $v0, .L800A3B90
    /* 3B15C 800A395C 00000000 */   nop
    /* 3B160 800A3960 26002286 */  lh         $v0, 0x26($s1)
    /* 3B164 800A3964 00000000 */  nop
    /* 3B168 800A3968 00025024 */  addiu      $s0, $v0, 0x200
    /* 3B16C 800A396C FF0F1032 */  andi       $s0, $s0, 0xFFF
    /* 3B170 800A3970 02000106 */  bgez       $s0, .L800A397C
    /* 3B174 800A3974 21100002 */   addu      $v0, $s0, $zero
    /* 3B178 800A3978 FF030226 */  addiu      $v0, $s0, 0x3FF
  .L800A397C:
    /* 3B17C 800A397C 83820200 */  sra        $s0, $v0, 10
    /* 3B180 800A3980 01000424 */  addiu      $a0, $zero, 0x1
    /* 3B184 800A3984 0F80023C */  lui        $v0, %hi(D_800F49E8)
    /* 3B188 800A3988 E84950AC */  sw         $s0, %lo(D_800F49E8)($v0)
    /* 3B18C 800A398C 0200022A */  slti       $v0, $s0, 0x2
    /* 3B190 800A3990 5C003392 */  lbu        $s3, 0x5C($s1)
    /* 3B194 800A3994 5E003492 */  lbu        $s4, 0x5E($s1)
    /* 3B198 800A3998 21A86002 */  addu       $s5, $s3, $zero
    /* 3B19C 800A399C 21B08002 */  addu       $s6, $s4, $zero
    /* 3B1A0 800A39A0 21286002 */  addu       $a1, $s3, $zero
    /* 3B1A4 800A39A4 02004010 */  beqz       $v0, .L800A39B0
    /* 3B1A8 800A39A8 21188002 */   addu      $v1, $s4, $zero
    /* 3B1AC 800A39AC FFFF0424 */  addiu      $a0, $zero, -0x1
  .L800A39B0:
    /* 3B1B0 800A39B0 01000232 */  andi       $v0, $s0, 0x1
    /* 3B1B4 800A39B4 04004010 */  beqz       $v0, .L800A39C8
    /* 3B1B8 800A39B8 40100400 */   sll       $v0, $a0, 1
    /* 3B1BC 800A39BC 21986402 */  addu       $s3, $s3, $a0
    /* 3B1C0 800A39C0 748E0208 */  j          .L800A39D0
    /* 3B1C4 800A39C4 21A8A200 */   addu      $s5, $a1, $v0
  .L800A39C8:
    /* 3B1C8 800A39C8 21A08402 */  addu       $s4, $s4, $a0
    /* 3B1CC 800A39CC 21B06200 */  addu       $s6, $v1, $v0
  .L800A39D0:
    /* 3B1D0 800A39D0 70006006 */  bltz       $s3, .L800A3B94
    /* 3B1D4 800A39D4 FFFF0224 */   addiu     $v0, $zero, -0x1
    /* 3B1D8 800A39D8 6E008006 */  bltz       $s4, .L800A3B94
    /* 3B1DC 800A39DC 00000000 */   nop
    /* 3B1E0 800A39E0 AC05228E */  lw         $v0, 0x5AC($s1)
    /* 3B1E4 800A39E4 00000000 */  nop
    /* 3B1E8 800A39E8 08004230 */  andi       $v0, $v0, 0x8
    /* 3B1EC 800A39EC 23004010 */  beqz       $v0, .L800A3A7C
    /* 3B1F0 800A39F0 C0111300 */   sll       $v0, $s3, 7
    /* 3B1F4 800A39F4 40005324 */  addiu      $s3, $v0, 0x40
    /* 3B1F8 800A39F8 0F80033C */  lui        $v1, %hi(D_800F45E0)
    /* 3B1FC 800A39FC 13003792 */  lbu        $s7, 0x13($s1)
    /* 3B200 800A3A00 E0456324 */  addiu      $v1, $v1, %lo(D_800F45E0)
    /* 3B204 800A3A04 80101700 */  sll        $v0, $s7, 2
    /* 3B208 800A3A08 21104300 */  addu       $v0, $v0, $v1
    /* 3B20C 800A3A0C 0000528C */  lw         $s2, 0x0($v0)
    /* 3B210 800A3A10 C0111400 */  sll        $v0, $s4, 7
    /* 3B214 800A3A14 1A004386 */  lh         $v1, 0x1A($s2)
    /* 3B218 800A3A18 00000000 */  nop
    /* 3B21C 800A3A1C 5C006014 */  bnez       $v1, .L800A3B90
    /* 3B220 800A3A20 40005424 */   addiu     $s4, $v0, 0x40
    /* 3B224 800A3A24 21206002 */  addu       $a0, $s3, $zero
    /* 3B228 800A3A28 1E002686 */  lh         $a2, 0x1E($s1)
    /* 3B22C 800A3A2C 21288002 */  addu       $a1, $s4, $zero
    /* 3B230 800A3A30 6D8F020C */  jal        func_800A3DB4
    /* 3B234 800A3A34 80FFC624 */   addiu     $a2, $a2, -0x80
    /* 3B238 800A3A38 56004010 */  beqz       $v0, .L800A3B94
    /* 3B23C 800A3A3C FFFF0224 */   addiu     $v0, $zero, -0x1
    /* 3B240 800A3A40 1C002486 */  lh         $a0, 0x1C($s1)
    /* 3B244 800A3A44 1E002286 */  lh         $v0, 0x1E($s1)
    /* 3B248 800A3A48 20002586 */  lh         $a1, 0x20($s1)
    /* 3B24C 800A3A4C F18E020C */  jal        func_800A3BC4
    /* 3B250 800A3A50 80FE5024 */   addiu     $s0, $v0, -0x180
    /* 3B254 800A3A54 2A100202 */  slt        $v0, $s0, $v0
    /* 3B258 800A3A58 4D004014 */  bnez       $v0, .L800A3B90
    /* 3B25C 800A3A5C 21206002 */   addu      $a0, $s3, $zero
    /* 3B260 800A3A60 F18E020C */  jal        func_800A3BC4
    /* 3B264 800A3A64 21288002 */   addu      $a1, $s4, $zero
    /* 3B268 800A3A68 2A180202 */  slt        $v1, $s0, $v0
    /* 3B26C 800A3A6C 49006014 */  bnez       $v1, .L800A3B94
    /* 3B270 800A3A70 FFFF0224 */   addiu     $v0, $zero, -0x1
    /* 3B274 800A3A74 E58E0208 */  j          .L800A3B94
    /* 3B278 800A3A78 2110E002 */   addu      $v0, $s7, $zero
  .L800A3A7C:
    /* 3B27C 800A3A7C 21206002 */  addu       $a0, $s3, $zero
    /* 3B280 800A3A80 21288002 */  addu       $a1, $s4, $zero
    /* 3B284 800A3A84 77A4020C */  jal        func_800A91DC
    /* 3B288 800A3A88 21300000 */   addu      $a2, $zero, $zero
    /* 3B28C 800A3A8C 21204000 */  addu       $a0, $v0, $zero
    /* 3B290 800A3A90 3F008010 */  beqz       $a0, .L800A3B90
    /* 3B294 800A3A94 0F80033C */   lui       $v1, %hi(D_800F45E0)
    /* 3B298 800A3A98 E0456324 */  addiu      $v1, $v1, %lo(D_800F45E0)
    /* 3B29C 800A3A9C 80100400 */  sll        $v0, $a0, 2
    /* 3B2A0 800A3AA0 21104300 */  addu       $v0, $v0, $v1
    /* 3B2A4 800A3AA4 0000528C */  lw         $s2, 0x0($v0)
    /* 3B2A8 800A3AA8 00000000 */  nop
    /* 3B2AC 800A3AAC 6C01428E */  lw         $v0, 0x16C($s2)
    /* 3B2B0 800A3AB0 10000324 */  addiu      $v1, $zero, 0x10
    /* 3B2B4 800A3AB4 30004230 */  andi       $v0, $v0, 0x30
    /* 3B2B8 800A3AB8 35004310 */  beq        $v0, $v1, .L800A3B90
    /* 3B2BC 800A3ABC 21B88000 */   addu      $s7, $a0, $zero
    /* 3B2C0 800A3AC0 1A004286 */  lh         $v0, 0x1A($s2)
    /* 3B2C4 800A3AC4 00000000 */  nop
    /* 3B2C8 800A3AC8 32004014 */  bnez       $v0, .L800A3B94
    /* 3B2CC 800A3ACC FFFF0224 */   addiu     $v0, $zero, -0x1
    /* 3B2D0 800A3AD0 C0111300 */  sll        $v0, $s3, 7
    /* 3B2D4 800A3AD4 40005324 */  addiu      $s3, $v0, 0x40
    /* 3B2D8 800A3AD8 C0111400 */  sll        $v0, $s4, 7
    /* 3B2DC 800A3ADC 40005424 */  addiu      $s4, $v0, 0x40
    /* 3B2E0 800A3AE0 C0111500 */  sll        $v0, $s5, 7
    /* 3B2E4 800A3AE4 40005524 */  addiu      $s5, $v0, 0x40
    /* 3B2E8 800A3AE8 C0111600 */  sll        $v0, $s6, 7
    /* 3B2EC 800A3AEC 40005624 */  addiu      $s6, $v0, 0x40
    /* 3B2F0 800A3AF0 1E002386 */  lh         $v1, 0x1E($s1)
    /* 3B2F4 800A3AF4 1E004686 */  lh         $a2, 0x1E($s2)
    /* 3B2F8 800A3AF8 80FF6224 */  addiu      $v0, $v1, -0x80
    /* 3B2FC 800A3AFC 2A10C200 */  slt        $v0, $a2, $v0
    /* 3B300 800A3B00 24004014 */  bnez       $v0, .L800A3B94
    /* 3B304 800A3B04 FFFF0224 */   addiu     $v0, $zero, -0x1
    /* 3B308 800A3B08 40006224 */  addiu      $v0, $v1, 0x40
    /* 3B30C 800A3B0C 2A104600 */  slt        $v0, $v0, $a2
    /* 3B310 800A3B10 20004014 */  bnez       $v0, .L800A3B94
    /* 3B314 800A3B14 FFFF0224 */   addiu     $v0, $zero, -0x1
    /* 3B318 800A3B18 6C014292 */  lbu        $v0, 0x16C($s2)
    /* 3B31C 800A3B1C 00000000 */  nop
    /* 3B320 800A3B20 07004230 */  andi       $v0, $v0, 0x7
    /* 3B324 800A3B24 0400422C */  sltiu      $v0, $v0, 0x4
    /* 3B328 800A3B28 07004010 */  beqz       $v0, .L800A3B48
    /* 3B32C 800A3B2C 2120A002 */   addu      $a0, $s5, $zero
    /* 3B330 800A3B30 6D8F020C */  jal        func_800A3DB4
    /* 3B334 800A3B34 2128C002 */   addu      $a1, $s6, $zero
    /* 3B338 800A3B38 10004014 */  bnez       $v0, .L800A3B7C
    /* 3B33C 800A3B3C 21204002 */   addu      $a0, $s2, $zero
    /* 3B340 800A3B40 E58E0208 */  j          .L800A3B94
    /* 3B344 800A3B44 FFFF0224 */   addiu     $v0, $zero, -0x1
  .L800A3B48:
    /* 3B348 800A3B48 1C002486 */  lh         $a0, 0x1C($s1)
    /* 3B34C 800A3B4C 20002586 */  lh         $a1, 0x20($s1)
    /* 3B350 800A3B50 F18E020C */  jal        func_800A3BC4
    /* 3B354 800A3B54 80FE7024 */   addiu     $s0, $v1, -0x180
    /* 3B358 800A3B58 2A100202 */  slt        $v0, $s0, $v0
    /* 3B35C 800A3B5C 0D004014 */  bnez       $v0, .L800A3B94
    /* 3B360 800A3B60 FFFF0224 */   addiu     $v0, $zero, -0x1
    /* 3B364 800A3B64 21206002 */  addu       $a0, $s3, $zero
    /* 3B368 800A3B68 F18E020C */  jal        func_800A3BC4
    /* 3B36C 800A3B6C 21288002 */   addu      $a1, $s4, $zero
    /* 3B370 800A3B70 2A100202 */  slt        $v0, $s0, $v0
    /* 3B374 800A3B74 06004014 */  bnez       $v0, .L800A3B90
    /* 3B378 800A3B78 21204002 */   addu      $a0, $s2, $zero
  .L800A3B7C:
    /* 3B37C 800A3B7C 008F020C */  jal        func_800A3C00
    /* 3B380 800A3B80 01000524 */   addiu     $a1, $zero, 0x1
    /* 3B384 800A3B84 21184000 */  addu       $v1, $v0, $zero
    /* 3B388 800A3B88 02006010 */  beqz       $v1, .L800A3B94
    /* 3B38C 800A3B8C 2110E002 */   addu      $v0, $s7, $zero
  .L800A3B90:
    /* 3B390 800A3B90 FFFF0224 */  addiu      $v0, $zero, -0x1
  .L800A3B94:
    /* 3B394 800A3B94 3000BF8F */  lw         $ra, 0x30($sp)
    /* 3B398 800A3B98 2C00B78F */  lw         $s7, 0x2C($sp)
    /* 3B39C 800A3B9C 2800B68F */  lw         $s6, 0x28($sp)
    /* 3B3A0 800A3BA0 2400B58F */  lw         $s5, 0x24($sp)
    /* 3B3A4 800A3BA4 2000B48F */  lw         $s4, 0x20($sp)
    /* 3B3A8 800A3BA8 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 3B3AC 800A3BAC 1800B28F */  lw         $s2, 0x18($sp)
    /* 3B3B0 800A3BB0 1400B18F */  lw         $s1, 0x14($sp)
    /* 3B3B4 800A3BB4 1000B08F */  lw         $s0, 0x10($sp)
    /* 3B3B8 800A3BB8 3800BD27 */  addiu      $sp, $sp, 0x38
    /* 3B3BC 800A3BBC 0800E003 */  jr         $ra
    /* 3B3C0 800A3BC0 00000000 */   nop
endlabel func_800A38E0
