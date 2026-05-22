nonmatching func_8007B29C, 0xA8

glabel func_8007B29C
    /* 12A9C 8007B29C C8FFBD27 */  addiu      $sp, $sp, -0x38
    /* 12AA0 8007B2A0 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 12AA4 8007B2A4 4800B18F */  lw         $s1, 0x48($sp)
    /* 12AA8 8007B2A8 2800B4AF */  sw         $s4, 0x28($sp)
    /* 12AAC 8007B2AC 21A08000 */  addu       $s4, $a0, $zero
    /* 12AB0 8007B2B0 2C00B5AF */  sw         $s5, 0x2C($sp)
    /* 12AB4 8007B2B4 21A8A000 */  addu       $s5, $a1, $zero
    /* 12AB8 8007B2B8 2400B3AF */  sw         $s3, 0x24($sp)
    /* 12ABC 8007B2BC 2198C000 */  addu       $s3, $a2, $zero
    /* 12AC0 8007B2C0 1800B0AF */  sw         $s0, 0x18($sp)
    /* 12AC4 8007B2C4 4C00B08F */  lw         $s0, 0x4C($sp)
    /* 12AC8 8007B2C8 0900622A */  slti       $v0, $s3, 0x9
    /* 12ACC 8007B2CC 3000BFAF */  sw         $ra, 0x30($sp)
    /* 12AD0 8007B2D0 13004010 */  beqz       $v0, .L8007B320
    /* 12AD4 8007B2D4 2000B2AF */   sw        $s2, 0x20($sp)
    /* 12AD8 8007B2D8 04006626 */  addiu      $a2, $s3, 0x4
    /* 12ADC 8007B2DC 00940700 */  sll        $s2, $a3, 16
    /* 12AE0 8007B2E0 03941200 */  sra        $s2, $s2, 16
    /* 12AE4 8007B2E4 21384002 */  addu       $a3, $s2, $zero
    /* 12AE8 8007B2E8 008C1100 */  sll        $s1, $s1, 16
    /* 12AEC 8007B2EC 038C1100 */  sra        $s1, $s1, 16
    /* 12AF0 8007B2F0 00841000 */  sll        $s0, $s0, 16
    /* 12AF4 8007B2F4 03841000 */  sra        $s0, $s0, 16
    /* 12AF8 8007B2F8 1000B1AF */  sw         $s1, 0x10($sp)
    /* 12AFC 8007B2FC A01C010C */  jal        vs_main_transformClutSlot
    /* 12B00 8007B300 1400B0AF */   sw        $s0, 0x14($sp)
    /* 12B04 8007B304 21208002 */  addu       $a0, $s4, $zero
    /* 12B08 8007B308 2128A002 */  addu       $a1, $s5, $zero
    /* 12B0C 8007B30C 01006626 */  addiu      $a2, $s3, 0x1
    /* 12B10 8007B310 21384002 */  addu       $a3, $s2, $zero
    /* 12B14 8007B314 1000B1AF */  sw         $s1, 0x10($sp)
    /* 12B18 8007B318 F01F010C */  jal        func_80047FC0
    /* 12B1C 8007B31C 1400B0AF */   sw        $s0, 0x14($sp)
  .L8007B320:
    /* 12B20 8007B320 3000BF8F */  lw         $ra, 0x30($sp)
    /* 12B24 8007B324 2C00B58F */  lw         $s5, 0x2C($sp)
    /* 12B28 8007B328 2800B48F */  lw         $s4, 0x28($sp)
    /* 12B2C 8007B32C 2400B38F */  lw         $s3, 0x24($sp)
    /* 12B30 8007B330 2000B28F */  lw         $s2, 0x20($sp)
    /* 12B34 8007B334 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 12B38 8007B338 1800B08F */  lw         $s0, 0x18($sp)
    /* 12B3C 8007B33C 0800E003 */  jr         $ra
    /* 12B40 8007B340 3800BD27 */   addiu     $sp, $sp, 0x38
endlabel func_8007B29C
