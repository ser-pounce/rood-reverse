nonmatching vs_menuD_initUiShield, 0xE4

glabel vs_menuD_initUiShield
    /* 3B0 80102BB0 D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 3B4 80102BB4 2400B5AF */  sw         $s5, 0x24($sp)
    /* 3B8 80102BB8 21A88000 */  addu       $s5, $a0, $zero
    /* 3BC 80102BBC 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 3C0 80102BC0 2198A000 */  addu       $s3, $a1, $zero
    /* 3C4 80102BC4 2000B4AF */  sw         $s4, 0x20($sp)
    /* 3C8 80102BC8 21A0C000 */  addu       $s4, $a2, $zero
    /* 3CC 80102BCC C4000424 */  addiu      $a0, $zero, 0xC4
    /* 3D0 80102BD0 2800BFAF */  sw         $ra, 0x28($sp)
    /* 3D4 80102BD4 1800B2AF */  sw         $s2, 0x18($sp)
    /* 3D8 80102BD8 1400B1AF */  sw         $s1, 0x14($sp)
    /* 3DC 80102BDC 8F0F010C */  jal        vs_main_allocHeapR
    /* 3E0 80102BE0 1000B0AF */   sw        $s0, 0x10($sp)
    /* 3E4 80102BE4 21904000 */  addu       $s2, $v0, $zero
    /* 3E8 80102BE8 21204002 */  addu       $a0, $s2, $zero
    /* 3EC 80102BEC 4424010C */  jal        vs_main_bzero
    /* 3F0 80102BF0 C4000524 */   addiu     $a1, $zero, 0xC4
    /* 3F4 80102BF4 19006012 */  beqz       $s3, .L80102C5C
    /* 3F8 80102BF8 04006526 */   addiu     $a1, $s3, 0x4
    /* 3FC 80102BFC 21204002 */  addu       $a0, $s2, $zero
    /* 400 80102C00 00006292 */  lbu        $v0, 0x0($s3)
    /* 404 80102C04 21800000 */  addu       $s0, $zero, $zero
    /* 408 80102C08 3FAB010C */  jal        vs_battle_copyInventoryArmorStats
    /* 40C 80102C0C C20042A6 */   sh        $v0, 0xC2($s2)
    /* 410 80102C10 28006292 */  lbu        $v0, 0x28($s3)
    /* 414 80102C14 30001124 */  addiu      $s1, $zero, 0x30
    /* 418 80102C18 C00042A2 */  sb         $v0, 0xC0($s2)
  .L80102C1C:
    /* 41C 80102C1C 21107002 */  addu       $v0, $s3, $s0
    /* 420 80102C20 2C004290 */  lbu        $v0, 0x2C($v0)
    /* 424 80102C24 00000000 */  nop
    /* 428 80102C28 08004010 */  beqz       $v0, .L80102C4C
    /* 42C 80102C2C 21205102 */   addu      $a0, $s2, $s1
    /* 430 80102C30 7F004230 */  andi       $v0, $v0, 0x7F
    /* 434 80102C34 C0280200 */  sll        $a1, $v0, 3
    /* 438 80102C38 2328A200 */  subu       $a1, $a1, $v0
    /* 43C 80102C3C 80280500 */  sll        $a1, $a1, 2
    /* 440 80102C40 E422A524 */  addiu      $a1, $a1, 0x22E4
    /* 444 80102C44 83AB010C */  jal        vs_battle_copyInventoryGemStats
    /* 448 80102C48 21288502 */   addu      $a1, $s4, $a1
  .L80102C4C:
    /* 44C 80102C4C 01001026 */  addiu      $s0, $s0, 0x1
    /* 450 80102C50 0300022A */  slti       $v0, $s0, 0x3
    /* 454 80102C54 F1FF4014 */  bnez       $v0, .L80102C1C
    /* 458 80102C58 30003126 */   addiu     $s1, $s1, 0x30
  .L80102C5C:
    /* 45C 80102C5C 2120A002 */  addu       $a0, $s5, $zero
    /* 460 80102C60 97A9010C */  jal        vs_battle_applyShieldStats
    /* 464 80102C64 21284002 */   addu      $a1, $s2, $zero
    /* 468 80102C68 180F010C */  jal        vs_main_freeHeapR
    /* 46C 80102C6C 21204002 */   addu      $a0, $s2, $zero
    /* 470 80102C70 2800BF8F */  lw         $ra, 0x28($sp)
    /* 474 80102C74 2400B58F */  lw         $s5, 0x24($sp)
    /* 478 80102C78 2000B48F */  lw         $s4, 0x20($sp)
    /* 47C 80102C7C 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 480 80102C80 1800B28F */  lw         $s2, 0x18($sp)
    /* 484 80102C84 1400B18F */  lw         $s1, 0x14($sp)
    /* 488 80102C88 1000B08F */  lw         $s0, 0x10($sp)
    /* 48C 80102C8C 0800E003 */  jr         $ra
    /* 490 80102C90 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel vs_menuD_initUiShield
