nonmatching vs_battle_applyShield, 0xE4

glabel vs_battle_applyShield
    /* 282C 8006B02C D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 2830 8006B030 2400B5AF */  sw         $s5, 0x24($sp)
    /* 2834 8006B034 21A88000 */  addu       $s5, $a0, $zero
    /* 2838 8006B038 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 283C 8006B03C 2198A000 */  addu       $s3, $a1, $zero
    /* 2840 8006B040 C4000424 */  addiu      $a0, $zero, 0xC4
    /* 2844 8006B044 2800BFAF */  sw         $ra, 0x28($sp)
    /* 2848 8006B048 2000B4AF */  sw         $s4, 0x20($sp)
    /* 284C 8006B04C 1800B2AF */  sw         $s2, 0x18($sp)
    /* 2850 8006B050 1400B1AF */  sw         $s1, 0x14($sp)
    /* 2854 8006B054 8F0F010C */  jal        vs_main_allocHeapR
    /* 2858 8006B058 1000B0AF */   sw        $s0, 0x10($sp)
    /* 285C 8006B05C 21884000 */  addu       $s1, $v0, $zero
    /* 2860 8006B060 21202002 */  addu       $a0, $s1, $zero
    /* 2864 8006B064 4424010C */  jal        vs_main_bzero
    /* 2868 8006B068 C4000524 */   addiu     $a1, $zero, 0xC4
    /* 286C 8006B06C 1A006012 */  beqz       $s3, .L8006B0D8
    /* 2870 8006B070 04006526 */   addiu     $a1, $s3, 0x4
    /* 2874 8006B074 21202002 */  addu       $a0, $s1, $zero
    /* 2878 8006B078 21800000 */  addu       $s0, $zero, $zero
    /* 287C 8006B07C 00006292 */  lbu        $v0, 0x0($s3)
    /* 2880 8006B080 30001224 */  addiu      $s2, $zero, 0x30
    /* 2884 8006B084 3FAB010C */  jal        vs_battle_copyInventoryArmorStats
    /* 2888 8006B088 C20022A6 */   sh        $v0, 0xC2($s1)
    /* 288C 8006B08C 0680023C */  lui        $v0, %hi(D_80060A0C)
    /* 2890 8006B090 28006392 */  lbu        $v1, 0x28($s3)
    /* 2894 8006B094 0C0A5424 */  addiu      $s4, $v0, %lo(D_80060A0C)
    /* 2898 8006B098 C00023A2 */  sb         $v1, 0xC0($s1)
  .L8006B09C:
    /* 289C 8006B09C 21107002 */  addu       $v0, $s3, $s0
    /* 28A0 8006B0A0 2C004290 */  lbu        $v0, 0x2C($v0)
    /* 28A4 8006B0A4 00000000 */  nop
    /* 28A8 8006B0A8 07004010 */  beqz       $v0, .L8006B0C8
    /* 28AC 8006B0AC 21203202 */   addu      $a0, $s1, $s2
    /* 28B0 8006B0B0 7F004230 */  andi       $v0, $v0, 0x7F
    /* 28B4 8006B0B4 C0280200 */  sll        $a1, $v0, 3
    /* 28B8 8006B0B8 2328A200 */  subu       $a1, $a1, $v0
    /* 28BC 8006B0BC 80280500 */  sll        $a1, $a1, 2
    /* 28C0 8006B0C0 83AB010C */  jal        vs_battle_copyInventoryGemStats
    /* 28C4 8006B0C4 2128B400 */   addu      $a1, $a1, $s4
  .L8006B0C8:
    /* 28C8 8006B0C8 01001026 */  addiu      $s0, $s0, 0x1
    /* 28CC 8006B0CC 0300022A */  slti       $v0, $s0, 0x3
    /* 28D0 8006B0D0 F2FF4014 */  bnez       $v0, .L8006B09C
    /* 28D4 8006B0D4 30005226 */   addiu     $s2, $s2, 0x30
  .L8006B0D8:
    /* 28D8 8006B0D8 2120A002 */  addu       $a0, $s5, $zero
    /* 28DC 8006B0DC 97A9010C */  jal        vs_battle_applyShieldStats
    /* 28E0 8006B0E0 21282002 */   addu      $a1, $s1, $zero
    /* 28E4 8006B0E4 180F010C */  jal        vs_main_freeHeapR
    /* 28E8 8006B0E8 21202002 */   addu      $a0, $s1, $zero
    /* 28EC 8006B0EC 2800BF8F */  lw         $ra, 0x28($sp)
    /* 28F0 8006B0F0 2400B58F */  lw         $s5, 0x24($sp)
    /* 28F4 8006B0F4 2000B48F */  lw         $s4, 0x20($sp)
    /* 28F8 8006B0F8 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 28FC 8006B0FC 1800B28F */  lw         $s2, 0x18($sp)
    /* 2900 8006B100 1400B18F */  lw         $s1, 0x14($sp)
    /* 2904 8006B104 1000B08F */  lw         $s0, 0x10($sp)
    /* 2908 8006B108 0800E003 */  jr         $ra
    /* 290C 8006B10C 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel vs_battle_applyShield
