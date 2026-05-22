nonmatching func_800BAC5C, 0x11C

glabel func_800BAC5C
    /* 5245C 800BAC5C B8FFBD27 */  addiu      $sp, $sp, -0x48
    /* 52460 800BAC60 3000B0AF */  sw         $s0, 0x30($sp)
    /* 52464 800BAC64 21808000 */  addu       $s0, $a0, $zero
    /* 52468 800BAC68 06000426 */  addiu      $a0, $s0, 0x6
    /* 5246C 800BAC6C 4000BFAF */  sw         $ra, 0x40($sp)
    /* 52470 800BAC70 3C00B3AF */  sw         $s3, 0x3C($sp)
    /* 52474 800BAC74 3800B2AF */  sw         $s2, 0x38($sp)
    /* 52478 800BAC78 80FF020C */  jal        vs_battle_getShort
    /* 5247C 800BAC7C 3400B1AF */   sw        $s1, 0x34($sp)
    /* 52480 800BAC80 01000426 */  addiu      $a0, $s0, 0x1
    /* 52484 800BAC84 80FF020C */  jal        vs_battle_getShort
    /* 52488 800BAC88 21984000 */   addu      $s3, $v0, $zero
    /* 5248C 800BAC8C 94FF020C */  jal        func_800BFE50
    /* 52490 800BAC90 FFFF4430 */   andi      $a0, $v0, 0xFFFF
    /* 52494 800BAC94 21204000 */  addu       $a0, $v0, $zero
    /* 52498 800BAC98 4284020C */  jal        func_800A1108
    /* 5249C 800BAC9C 1000A527 */   addiu     $a1, $sp, 0x10
    /* 524A0 800BACA0 80FF020C */  jal        vs_battle_getShort
    /* 524A4 800BACA4 03000426 */   addiu     $a0, $s0, 0x3
    /* 524A8 800BACA8 94FF020C */  jal        func_800BFE50
    /* 524AC 800BACAC FFFF4430 */   andi      $a0, $v0, 0xFFFF
    /* 524B0 800BACB0 21204000 */  addu       $a0, $v0, $zero
    /* 524B4 800BACB4 4284020C */  jal        func_800A1108
    /* 524B8 800BACB8 2000A527 */   addiu     $a1, $sp, 0x20
    /* 524BC 800BACBC 1400A297 */  lhu        $v0, 0x14($sp)
    /* 524C0 800BACC0 2400A397 */  lhu        $v1, 0x24($sp)
    /* 524C4 800BACC4 00000000 */  nop
    /* 524C8 800BACC8 23104300 */  subu       $v0, $v0, $v1
    /* 524CC 800BACCC 00140200 */  sll        $v0, $v0, 16
    /* 524D0 800BACD0 03940200 */  sra        $s2, $v0, 16
    /* 524D4 800BACD4 18005202 */  mult       $s2, $s2
    /* 524D8 800BACD8 1800A297 */  lhu        $v0, 0x18($sp)
    /* 524DC 800BACDC 2800A397 */  lhu        $v1, 0x28($sp)
    /* 524E0 800BACE0 00000000 */  nop
    /* 524E4 800BACE4 23104300 */  subu       $v0, $v0, $v1
    /* 524E8 800BACE8 12200000 */  mflo       $a0
    /* 524EC 800BACEC 00140200 */  sll        $v0, $v0, 16
    /* 524F0 800BACF0 038C0200 */  sra        $s1, $v0, 16
    /* 524F4 800BACF4 18003102 */  mult       $s1, $s1
    /* 524F8 800BACF8 12180000 */  mflo       $v1
    /* 524FC 800BACFC E506010C */  jal        vs_gte_rsqrt
    /* 52500 800BAD00 21208300 */   addu      $a0, $a0, $v1
    /* 52504 800BAD04 05000392 */  lbu        $v1, 0x5($s0)
    /* 52508 800BAD08 00000000 */  nop
    /* 5250C 800BAD0C 1A004300 */  div        $zero, $v0, $v1
    /* 52510 800BAD10 12180000 */  mflo       $v1
    /* 52514 800BAD14 00141300 */  sll        $v0, $s3, 16
    /* 52518 800BAD18 03240200 */  sra        $a0, $v0, 16
    /* 5251C 800BAD1C 00016228 */  slti       $v0, $v1, 0x100
    /* 52520 800BAD20 02004010 */  beqz       $v0, .L800BAD2C
    /* 52524 800BAD24 FF000524 */   addiu     $a1, $zero, 0xFF
    /* 52528 800BAD28 FF006530 */  andi       $a1, $v1, 0xFF
  .L800BAD2C:
    /* 5252C 800BAD2C 05FB020C */  jal        vs_battle_setStateFlag
    /* 52530 800BAD30 00000000 */   nop
    /* 52534 800BAD34 21204002 */  addu       $a0, $s2, $zero
    /* 52538 800BAD38 DF04010C */  jal        ratan2
    /* 5253C 800BAD3C 21282002 */   addu      $a1, $s1, $zero
    /* 52540 800BAD40 01006426 */  addiu      $a0, $s3, 0x1
    /* 52544 800BAD44 00240400 */  sll        $a0, $a0, 16
    /* 52548 800BAD48 03240400 */  sra        $a0, $a0, 16
    /* 5254C 800BAD4C 03110200 */  sra        $v0, $v0, 4
    /* 52550 800BAD50 05FB020C */  jal        vs_battle_setStateFlag
    /* 52554 800BAD54 FF004530 */   andi      $a1, $v0, 0xFF
    /* 52558 800BAD58 4000BF8F */  lw         $ra, 0x40($sp)
    /* 5255C 800BAD5C 3C00B38F */  lw         $s3, 0x3C($sp)
    /* 52560 800BAD60 3800B28F */  lw         $s2, 0x38($sp)
    /* 52564 800BAD64 3400B18F */  lw         $s1, 0x34($sp)
    /* 52568 800BAD68 3000B08F */  lw         $s0, 0x30($sp)
    /* 5256C 800BAD6C 21100000 */  addu       $v0, $zero, $zero
    /* 52570 800BAD70 0800E003 */  jr         $ra
    /* 52574 800BAD74 4800BD27 */   addiu     $sp, $sp, 0x48
endlabel func_800BAC5C
