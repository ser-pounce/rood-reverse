nonmatching func_800135D8, 0xC4

glabel func_800135D8
    /* 3DD8 800135D8 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 3DDC 800135DC 1000B0AF */  sw         $s0, 0x10($sp)
    /* 3DE0 800135E0 21808000 */  addu       $s0, $a0, $zero
    /* 3DE4 800135E4 2000B4AF */  sw         $s4, 0x20($sp)
    /* 3DE8 800135E8 21A0A000 */  addu       $s4, $a1, $zero
    /* 3DEC 800135EC 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 3DF0 800135F0 2198C000 */  addu       $s3, $a2, $zero
    /* 3DF4 800135F4 1800B2AF */  sw         $s2, 0x18($sp)
    /* 3DF8 800135F8 2190E000 */  addu       $s2, $a3, $zero
    /* 3DFC 800135FC 2400BFAF */  sw         $ra, 0x24($sp)
    /* 3E00 80013600 574D000C */  jal        _waitTransferAvailable
    /* 3E04 80013604 1400B1AF */   sw        $s1, 0x14($sp)
    /* 3E08 80013608 1A4D000C */  jal        Sound_IsNotAkaoFile
    /* 3E0C 8001360C 21200002 */   addu      $a0, $s0, $zero
    /* 3E10 80013610 18004014 */  bnez       $v0, .L80013674
    /* 3E14 80013614 0380033C */   lui       $v1, %hi(_isSpuTransfer)
    /* 3E18 80013618 21204002 */  addu       $a0, $s2, $zero
    /* 3E1C 8001361C F17A000C */  jal        SpuSetTransferStartAddr
    /* 3E20 80013620 21880002 */   addu      $s1, $s0, $zero
    /* 3E24 80013624 40001026 */  addiu      $s0, $s0, 0x40
    /* 3E28 80013628 1C00248E */  lw         $a0, 0x1C($s1)
    /* 3E2C 8001362C 1400258E */  lw         $a1, 0x14($s1)
    /* 3E30 80013630 00210400 */  sll        $a0, $a0, 4
    /* 3E34 80013634 344D000C */  jal        _writeSpu
    /* 3E38 80013638 21200402 */   addu      $a0, $s0, $a0
    /* 3E3C 8001363C 21200002 */  addu       $a0, $s0, $zero
    /* 3E40 80013640 00111300 */  sll        $v0, $s3, 4
    /* 3E44 80013644 0380053C */  lui        $a1, %hi(g_InstrumentInfo)
    /* 3E48 80013648 8867A524 */  addiu      $a1, $a1, %lo(g_InstrumentInfo)
    /* 3E4C 8001364C 21284500 */  addu       $a1, $v0, $a1
    /* 3E50 80013650 1C00278E */  lw         $a3, 0x1C($s1)
    /* 3E54 80013654 064D000C */  jal        Sound_CopyAndRelocateInstruments
    /* 3E58 80013658 21304002 */   addu      $a2, $s2, $zero
    /* 3E5C 8001365C 07008012 */  beqz       $s4, .L8001367C
    /* 3E60 80013660 21100000 */   addu      $v0, $zero, $zero
    /* 3E64 80013664 574D000C */  jal        _waitTransferAvailable
    /* 3E68 80013668 00000000 */   nop
    /* 3E6C 8001366C 9F4D0008 */  j          .L8001367C
    /* 3E70 80013670 21100000 */   addu      $v0, $zero, $zero
  .L80013674:
    /* 3E74 80013674 FFFF0224 */  addiu      $v0, $zero, -0x1
    /* 3E78 80013678 F07762AC */  sw         $v0, %lo(_isSpuTransfer)($v1)
  .L8001367C:
    /* 3E7C 8001367C 2400BF8F */  lw         $ra, 0x24($sp)
    /* 3E80 80013680 2000B48F */  lw         $s4, 0x20($sp)
    /* 3E84 80013684 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 3E88 80013688 1800B28F */  lw         $s2, 0x18($sp)
    /* 3E8C 8001368C 1400B18F */  lw         $s1, 0x14($sp)
    /* 3E90 80013690 1000B08F */  lw         $s0, 0x10($sp)
    /* 3E94 80013694 0800E003 */  jr         $ra
    /* 3E98 80013698 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_800135D8
