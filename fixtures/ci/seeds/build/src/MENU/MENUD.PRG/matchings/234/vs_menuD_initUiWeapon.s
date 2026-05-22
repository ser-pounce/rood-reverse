nonmatching vs_menuD_initUiWeapon, 0x17C

glabel vs_menuD_initUiWeapon
    /* 234 80102A34 D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 238 80102A38 2400B5AF */  sw         $s5, 0x24($sp)
    /* 23C 80102A3C 21A88000 */  addu       $s5, $a0, $zero
    /* 240 80102A40 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 244 80102A44 2198A000 */  addu       $s3, $a1, $zero
    /* 248 80102A48 2000B4AF */  sw         $s4, 0x20($sp)
    /* 24C 80102A4C 21A0C000 */  addu       $s4, $a2, $zero
    /* 250 80102A50 0C010424 */  addiu      $a0, $zero, 0x10C
    /* 254 80102A54 2800BFAF */  sw         $ra, 0x28($sp)
    /* 258 80102A58 1800B2AF */  sw         $s2, 0x18($sp)
    /* 25C 80102A5C 1400B1AF */  sw         $s1, 0x14($sp)
    /* 260 80102A60 8F0F010C */  jal        vs_main_allocHeapR
    /* 264 80102A64 1000B0AF */   sw        $s0, 0x10($sp)
    /* 268 80102A68 21904000 */  addu       $s2, $v0, $zero
    /* 26C 80102A6C 21204002 */  addu       $a0, $s2, $zero
    /* 270 80102A70 4424010C */  jal        vs_main_bzero
    /* 274 80102A74 0C010524 */   addiu     $a1, $zero, 0x10C
    /* 278 80102A78 37006012 */  beqz       $s3, .L80102B58
    /* 27C 80102A7C 21800000 */   addu      $s0, $zero, $zero
    /* 280 80102A80 00006292 */  lbu        $v0, 0x0($s3)
    /* 284 80102A84 00000000 */  nop
    /* 288 80102A88 F20042A6 */  sh         $v0, 0xF2($s2)
    /* 28C 80102A8C 01006292 */  lbu        $v0, 0x1($s3)
    /* 290 80102A90 00000000 */  nop
    /* 294 80102A94 15004010 */  beqz       $v0, .L80102AEC
    /* 298 80102A98 21204002 */   addu      $a0, $s2, $zero
    /* 29C 80102A9C 40280200 */  sll        $a1, $v0, 1
    /* 2A0 80102AA0 2128A200 */  addu       $a1, $a1, $v0
    /* 2A4 80102AA4 80280500 */  sll        $a1, $a1, 2
    /* 2A8 80102AA8 2328A200 */  subu       $a1, $a1, $v0
    /* 2AC 80102AAC 80280500 */  sll        $a1, $a1, 2
    /* 2B0 80102AB0 D409A524 */  addiu      $a1, $a1, 0x9D4
    /* 2B4 80102AB4 D1AA010C */  jal        vs_battle_copyInventoryBladeStats
    /* 2B8 80102AB8 21288502 */   addu      $a1, $s4, $a1
    /* 2BC 80102ABC 01006392 */  lbu        $v1, 0x1($s3)
    /* 2C0 80102AC0 00000000 */  nop
    /* 2C4 80102AC4 FFFF6324 */  addiu      $v1, $v1, -0x1
    /* 2C8 80102AC8 40100300 */  sll        $v0, $v1, 1
    /* 2CC 80102ACC 21104300 */  addu       $v0, $v0, $v1
    /* 2D0 80102AD0 80100200 */  sll        $v0, $v0, 2
    /* 2D4 80102AD4 23104300 */  subu       $v0, $v0, $v1
    /* 2D8 80102AD8 80100200 */  sll        $v0, $v0, 2
    /* 2DC 80102ADC 21108202 */  addu       $v0, $s4, $v0
    /* 2E0 80102AE0 280A4290 */  lbu        $v0, 0xA28($v0)
    /* 2E4 80102AE4 00000000 */  nop
    /* 2E8 80102AE8 F00042A2 */  sb         $v0, 0xF0($s2)
  .L80102AEC:
    /* 2EC 80102AEC 02006292 */  lbu        $v0, 0x2($s3)
    /* 2F0 80102AF0 00000000 */  nop
    /* 2F4 80102AF4 06004010 */  beqz       $v0, .L80102B10
    /* 2F8 80102AF8 30004426 */   addiu     $a0, $s2, 0x30
    /* 2FC 80102AFC 21284000 */  addu       $a1, $v0, $zero
    /* 300 80102B00 00290500 */  sll        $a1, $a1, 4
    /* 304 80102B04 F014A524 */  addiu      $a1, $a1, 0x14F0
    /* 308 80102B08 1DAB010C */  jal        vs_battle_copyInventoryGripStats
    /* 30C 80102B0C 21288502 */   addu      $a1, $s4, $a1
  .L80102B10:
    /* 310 80102B10 21800000 */  addu       $s0, $zero, $zero
    /* 314 80102B14 60001124 */  addiu      $s1, $zero, 0x60
  .L80102B18:
    /* 318 80102B18 21187002 */  addu       $v1, $s3, $s0
    /* 31C 80102B1C 04006290 */  lbu        $v0, 0x4($v1)
    /* 320 80102B20 00000000 */  nop
    /* 324 80102B24 07004010 */  beqz       $v0, .L80102B44
    /* 328 80102B28 21205102 */   addu      $a0, $s2, $s1
    /* 32C 80102B2C C0280200 */  sll        $a1, $v0, 3
    /* 330 80102B30 2328A200 */  subu       $a1, $a1, $v0
    /* 334 80102B34 80280500 */  sll        $a1, $a1, 2
    /* 338 80102B38 E422A524 */  addiu      $a1, $a1, 0x22E4
    /* 33C 80102B3C 83AB010C */  jal        vs_battle_copyInventoryGemStats
    /* 340 80102B40 21288502 */   addu      $a1, $s4, $a1
  .L80102B44:
    /* 344 80102B44 01001026 */  addiu      $s0, $s0, 0x1
    /* 348 80102B48 0300022A */  slti       $v0, $s0, 0x3
    /* 34C 80102B4C F2FF4014 */  bnez       $v0, .L80102B18
    /* 350 80102B50 30003126 */   addiu     $s1, $s1, 0x30
    /* 354 80102B54 21800000 */  addu       $s0, $zero, $zero
  .L80102B58:
    /* 358 80102B58 21185002 */  addu       $v1, $s2, $s0
  .L80102B5C:
    /* 35C 80102B5C 21107002 */  addu       $v0, $s3, $s0
    /* 360 80102B60 08004290 */  lbu        $v0, 0x8($v0)
    /* 364 80102B64 01001026 */  addiu      $s0, $s0, 0x1
    /* 368 80102B68 F40062A0 */  sb         $v0, 0xF4($v1)
    /* 36C 80102B6C 1800022A */  slti       $v0, $s0, 0x18
    /* 370 80102B70 FAFF4014 */  bnez       $v0, .L80102B5C
    /* 374 80102B74 21185002 */   addu      $v1, $s2, $s0
    /* 378 80102B78 2120A002 */  addu       $a0, $s5, $zero
    /* 37C 80102B7C CDA8010C */  jal        vs_battle_applyWeaponStats
    /* 380 80102B80 21284002 */   addu      $a1, $s2, $zero
    /* 384 80102B84 180F010C */  jal        vs_main_freeHeapR
    /* 388 80102B88 21204002 */   addu      $a0, $s2, $zero
    /* 38C 80102B8C 2800BF8F */  lw         $ra, 0x28($sp)
    /* 390 80102B90 2400B58F */  lw         $s5, 0x24($sp)
    /* 394 80102B94 2000B48F */  lw         $s4, 0x20($sp)
    /* 398 80102B98 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 39C 80102B9C 1800B28F */  lw         $s2, 0x18($sp)
    /* 3A0 80102BA0 1400B18F */  lw         $s1, 0x14($sp)
    /* 3A4 80102BA4 1000B08F */  lw         $s0, 0x10($sp)
    /* 3A8 80102BA8 0800E003 */  jr         $ra
    /* 3AC 80102BAC 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel vs_menuD_initUiWeapon
