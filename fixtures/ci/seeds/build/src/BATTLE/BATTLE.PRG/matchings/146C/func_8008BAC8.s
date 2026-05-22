nonmatching func_8008BAC8, 0x13C

glabel func_8008BAC8
    /* 232C8 8008BAC8 D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 232CC 8008BACC 2000B4AF */  sw         $s4, 0x20($sp)
    /* 232D0 8008BAD0 21A08000 */  addu       $s4, $a0, $zero
    /* 232D4 8008BAD4 2400B5AF */  sw         $s5, 0x24($sp)
    /* 232D8 8008BAD8 21A8A000 */  addu       $s5, $a1, $zero
    /* 232DC 8008BADC 0F80023C */  lui        $v0, %hi(vs_battle_roomData)
    /* 232E0 8008BAE0 F81B4224 */  addiu      $v0, $v0, %lo(vs_battle_roomData)
    /* 232E4 8008BAE4 2800BFAF */  sw         $ra, 0x28($sp)
    /* 232E8 8008BAE8 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 232EC 8008BAEC 1800B2AF */  sw         $s2, 0x18($sp)
    /* 232F0 8008BAF0 1400B1AF */  sw         $s1, 0x14($sp)
    /* 232F4 8008BAF4 1000B0AF */  sw         $s0, 0x10($sp)
    /* 232F8 8008BAF8 7000448C */  lw         $a0, 0x70($v0)
    /* 232FC 8008BAFC 00000000 */  nop
    /* 23300 8008BB00 36008010 */  beqz       $a0, .L8008BBDC
    /* 23304 8008BB04 2198C000 */   addu      $s3, $a2, $zero
    /* 23308 8008BB08 1000438C */  lw         $v1, 0x10($v0)
    /* 2330C 8008BB0C AAAA023C */  lui        $v0, (0xAAAAAAAB >> 16)
    /* 23310 8008BB10 ABAA4234 */  ori        $v0, $v0, (0xAAAAAAAB & 0xFFFF)
    /* 23314 8008BB14 19006200 */  multu      $v1, $v0
    /* 23318 8008BB18 21808000 */  addu       $s0, $a0, $zero
    /* 2331C 8008BB1C 0F80123C */  lui        $s2, %hi(D_800F1D08)
    /* 23320 8008BB20 081D40AE */  sw         $zero, %lo(D_800F1D08)($s2)
    /* 23324 8008BB24 10480000 */  mfhi       $t1
    /* 23328 8008BB28 B19B000C */  jal        rand
    /* 2332C 8008BB2C C2880900 */   srl       $s1, $t1, 3
    /* 23330 8008BB30 21280000 */  addu       $a1, $zero, $zero
    /* 23334 8008BB34 0680033C */  lui        $v1, %hi(vs_main_stateFlags + 0xB3)
    /* 23338 8008BB38 25002012 */  beqz       $s1, .L8008BBD0
    /* 2333C 8008BB3C 4B1662A0 */   sb        $v0, %lo(vs_main_stateFlags + 0xB3)($v1)
    /* 23340 8008BB40 0200682A */  slti       $t0, $s3, 0x2
    /* 23344 8008BB44 21304002 */  addu       $a2, $s2, $zero
    /* 23348 8008BB48 081DC724 */  addiu      $a3, $a2, %lo(D_800F1D08)
    /* 2334C 8008BB4C 02000426 */  addiu      $a0, $s0, 0x2
  .L8008BB50:
    /* 23350 8008BB50 07000015 */  bnez       $t0, .L8008BB70
    /* 23354 8008BB54 00000000 */   nop
    /* 23358 8008BB58 00008294 */  lhu        $v0, 0x0($a0)
    /* 2335C 8008BB5C 00000000 */  nop
    /* 23360 8008BB60 82120200 */  srl        $v0, $v0, 10
    /* 23364 8008BB64 07004230 */  andi       $v0, $v0, 0x7
    /* 23368 8008BB68 0D005310 */  beq        $v0, $s3, .L8008BBA0
    /* 2336C 8008BB6C 00000000 */   nop
  .L8008BB70:
    /* 23370 8008BB70 00008394 */  lhu        $v1, 0x0($a0)
    /* 23374 8008BB74 00000000 */  nop
    /* 23378 8008BB78 1F006230 */  andi       $v0, $v1, 0x1F
    /* 2337C 8008BB7C 0F005414 */  bne        $v0, $s4, .L8008BBBC
    /* 23380 8008BB80 FFFF6330 */   andi      $v1, $v1, 0xFFFF
    /* 23384 8008BB84 42110300 */  srl        $v0, $v1, 5
    /* 23388 8008BB88 1F004230 */  andi       $v0, $v0, 0x1F
    /* 2338C 8008BB8C 0B005514 */  bne        $v0, $s5, .L8008BBBC
    /* 23390 8008BB90 82120300 */   srl       $v0, $v1, 10
    /* 23394 8008BB94 07004230 */  andi       $v0, $v0, 0x7
    /* 23398 8008BB98 08005314 */  bne        $v0, $s3, .L8008BBBC
    /* 2339C 8008BB9C 00000000 */   nop
  .L8008BBA0:
    /* 233A0 8008BBA0 081DC38C */  lw         $v1, %lo(D_800F1D08)($a2)
    /* 233A4 8008BBA4 00000000 */  nop
    /* 233A8 8008BBA8 80100300 */  sll        $v0, $v1, 2
    /* 233AC 8008BBAC 01006324 */  addiu      $v1, $v1, 0x1
    /* 233B0 8008BBB0 21104700 */  addu       $v0, $v0, $a3
    /* 233B4 8008BBB4 040050AC */  sw         $s0, 0x4($v0)
    /* 233B8 8008BBB8 081DC3AC */  sw         $v1, %lo(D_800F1D08)($a2)
  .L8008BBBC:
    /* 233BC 8008BBBC 0100A524 */  addiu      $a1, $a1, 0x1
    /* 233C0 8008BBC0 0C008424 */  addiu      $a0, $a0, 0xC
    /* 233C4 8008BBC4 2A10B100 */  slt        $v0, $a1, $s1
    /* 233C8 8008BBC8 E1FF4014 */  bnez       $v0, .L8008BB50
    /* 233CC 8008BBCC 0C001026 */   addiu     $s0, $s0, 0xC
  .L8008BBD0:
    /* 233D0 8008BBD0 0F80023C */  lui        $v0, %hi(D_800F1D08)
    /* 233D4 8008BBD4 F82E0208 */  j          .L8008BBE0
    /* 233D8 8008BBD8 081D4224 */   addiu     $v0, $v0, %lo(D_800F1D08)
  .L8008BBDC:
    /* 233DC 8008BBDC 21100000 */  addu       $v0, $zero, $zero
  .L8008BBE0:
    /* 233E0 8008BBE0 2800BF8F */  lw         $ra, 0x28($sp)
    /* 233E4 8008BBE4 2400B58F */  lw         $s5, 0x24($sp)
    /* 233E8 8008BBE8 2000B48F */  lw         $s4, 0x20($sp)
    /* 233EC 8008BBEC 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 233F0 8008BBF0 1800B28F */  lw         $s2, 0x18($sp)
    /* 233F4 8008BBF4 1400B18F */  lw         $s1, 0x14($sp)
    /* 233F8 8008BBF8 1000B08F */  lw         $s0, 0x10($sp)
    /* 233FC 8008BBFC 0800E003 */  jr         $ra
    /* 23400 8008BC00 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel func_8008BAC8
