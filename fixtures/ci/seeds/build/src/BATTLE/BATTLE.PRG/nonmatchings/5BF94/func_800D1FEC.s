nonmatching func_800D1FEC, 0x80

glabel func_800D1FEC
    /* 697EC 800D1FEC D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 697F0 800D1FF0 2000B4AF */  sw         $s4, 0x20($sp)
    /* 697F4 800D1FF4 21A08000 */  addu       $s4, $a0, $zero
    /* 697F8 800D1FF8 1000B0AF */  sw         $s0, 0x10($sp)
    /* 697FC 800D1FFC 21800000 */  addu       $s0, $zero, $zero
    /* 69800 800D2000 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 69804 800D2004 FF001324 */  addiu      $s3, $zero, 0xFF
    /* 69808 800D2008 1800B2AF */  sw         $s2, 0x18($sp)
    /* 6980C 800D200C 01001224 */  addiu      $s2, $zero, 0x1
    /* 69810 800D2010 0F80023C */  lui        $v0, %hi(D_800F54B8)
    /* 69814 800D2014 1400B1AF */  sw         $s1, 0x14($sp)
    /* 69818 800D2018 B8545124 */  addiu      $s1, $v0, %lo(D_800F54B8)
    /* 6981C 800D201C 2400BFAF */  sw         $ra, 0x24($sp)
  .L800D2020:
    /* 69820 800D2020 07101402 */  srav       $v0, $s4, $s0
    /* 69824 800D2024 01004230 */  andi       $v0, $v0, 0x1
    /* 69828 800D2028 04004010 */  beqz       $v0, .L800D203C
    /* 6982C 800D202C 00000000 */   nop
    /* 69830 800D2030 000033A2 */  sb         $s3, 0x0($s1)
    /* 69834 800D2034 7F47030C */  jal        func_800D1DFC
    /* 69838 800D2038 04201202 */   sllv      $a0, $s2, $s0
  .L800D203C:
    /* 6983C 800D203C 01001026 */  addiu      $s0, $s0, 0x1
    /* 69840 800D2040 0400022A */  slti       $v0, $s0, 0x4
    /* 69844 800D2044 F6FF4014 */  bnez       $v0, .L800D2020
    /* 69848 800D2048 06003126 */   addiu     $s1, $s1, 0x6
    /* 6984C 800D204C 2400BF8F */  lw         $ra, 0x24($sp)
    /* 69850 800D2050 2000B48F */  lw         $s4, 0x20($sp)
    /* 69854 800D2054 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 69858 800D2058 1800B28F */  lw         $s2, 0x18($sp)
    /* 6985C 800D205C 1400B18F */  lw         $s1, 0x14($sp)
    /* 69860 800D2060 1000B08F */  lw         $s0, 0x10($sp)
    /* 69864 800D2064 0800E003 */  jr         $ra
    /* 69868 800D2068 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_800D1FEC
