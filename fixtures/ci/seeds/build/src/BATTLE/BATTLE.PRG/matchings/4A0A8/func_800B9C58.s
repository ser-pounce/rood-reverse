nonmatching func_800B9C58, 0x11C

glabel func_800B9C58
    /* 51458 800B9C58 C0FFBD27 */  addiu      $sp, $sp, -0x40
    /* 5145C 800B9C5C 3000B0AF */  sw         $s0, 0x30($sp)
    /* 51460 800B9C60 21808000 */  addu       $s0, $a0, $zero
    /* 51464 800B9C64 3800BFAF */  sw         $ra, 0x38($sp)
    /* 51468 800B9C68 3400B1AF */  sw         $s1, 0x34($sp)
    /* 5146C 800B9C6C 01000492 */  lbu        $a0, 0x1($s0)
    /* 51470 800B9C70 01000624 */  addiu      $a2, $zero, 0x1
    /* 51474 800B9C74 02190400 */  srl        $v1, $a0, 4
    /* 51478 800B9C78 23006610 */  beq        $v1, $a2, .L800B9D08
    /* 5147C 800B9C7C 02006228 */   slti      $v0, $v1, 0x2
    /* 51480 800B9C80 05004010 */  beqz       $v0, .L800B9C98
    /* 51484 800B9C84 02000224 */   addiu     $v0, $zero, 0x2
    /* 51488 800B9C88 07006010 */  beqz       $v1, .L800B9CA8
    /* 5148C 800B9C8C 00000000 */   nop
    /* 51490 800B9C90 57E70208 */  j          .L800B9D5C
    /* 51494 800B9C94 00000000 */   nop
  .L800B9C98:
    /* 51498 800B9C98 28006210 */  beq        $v1, $v0, .L800B9D3C
    /* 5149C 800B9C9C 0F008430 */   andi      $a0, $a0, 0xF
    /* 514A0 800B9CA0 57E70208 */  j          .L800B9D5C
    /* 514A4 800B9CA4 00000000 */   nop
  .L800B9CA8:
    /* 514A8 800B9CA8 80FF020C */  jal        vs_battle_getShort
    /* 514AC 800B9CAC 02000426 */   addiu     $a0, $s0, 0x2
    /* 514B0 800B9CB0 FFFF4430 */  andi       $a0, $v0, 0xFFFF
    /* 514B4 800B9CB4 A3ED020C */  jal        func_800BB68C
    /* 514B8 800B9CB8 1800A527 */   addiu     $a1, $sp, 0x18
    /* 514BC 800B9CBC 01001124 */  addiu      $s1, $zero, 0x1
  .L800B9CC0:
    /* 514C0 800B9CC0 E2ED020C */  jal        func_800BB788
    /* 514C4 800B9CC4 1800A427 */   addiu     $a0, $sp, 0x18
    /* 514C8 800B9CC8 FFFF4630 */  andi       $a2, $v0, 0xFFFF
    /* 514CC 800B9CCC 2300D110 */  beq        $a2, $s1, .L800B9D5C
    /* 514D0 800B9CD0 00000000 */   nop
    /* 514D4 800B9CD4 01000492 */  lbu        $a0, 0x1($s0)
    /* 514D8 800B9CD8 04000592 */  lbu        $a1, 0x4($s0)
    /* 514DC 800B9CDC 05000782 */  lb         $a3, 0x5($s0)
    /* 514E0 800B9CE0 06000282 */  lb         $v0, 0x6($s0)
    /* 514E4 800B9CE4 0F008430 */  andi       $a0, $a0, 0xF
    /* 514E8 800B9CE8 0428B100 */  sllv       $a1, $s1, $a1
    /* 514EC 800B9CEC 1000A2AF */  sw         $v0, 0x10($sp)
    /* 514F0 800B9CF0 07000282 */  lb         $v0, 0x7($s0)
    /* 514F4 800B9CF4 1F00A530 */  andi       $a1, $a1, 0x1F
    /* 514F8 800B9CF8 A7EC010C */  jal        func_8007B29C
    /* 514FC 800B9CFC 1400A2AF */   sw        $v0, 0x14($sp)
    /* 51500 800B9D00 30E70208 */  j          .L800B9CC0
    /* 51504 800B9D04 00000000 */   nop
  .L800B9D08:
    /* 51508 800B9D08 01000524 */  addiu      $a1, $zero, 0x1
    /* 5150C 800B9D0C 01000492 */  lbu        $a0, 0x1($s0)
    /* 51510 800B9D10 04000292 */  lbu        $v0, 0x4($s0)
    /* 51514 800B9D14 05000682 */  lb         $a2, 0x5($s0)
    /* 51518 800B9D18 06000782 */  lb         $a3, 0x6($s0)
    /* 5151C 800B9D1C 0F008430 */  andi       $a0, $a0, 0xF
    /* 51520 800B9D20 04284500 */  sllv       $a1, $a1, $v0
    /* 51524 800B9D24 07000282 */  lb         $v0, 0x7($s0)
    /* 51528 800B9D28 1F00A530 */  andi       $a1, $a1, 0x1F
    /* 5152C 800B9D2C 6EEC010C */  jal        func_8007B1B8
    /* 51530 800B9D30 1000A2AF */   sw        $v0, 0x10($sp)
    /* 51534 800B9D34 57E70208 */  j          .L800B9D5C
    /* 51538 800B9D38 00000000 */   nop
  .L800B9D3C:
    /* 5153C 800B9D3C 04000592 */  lbu        $a1, 0x4($s0)
    /* 51540 800B9D40 06000782 */  lb         $a3, 0x6($s0)
    /* 51544 800B9D44 07000282 */  lb         $v0, 0x7($s0)
    /* 51548 800B9D48 0428A600 */  sllv       $a1, $a2, $a1
    /* 5154C 800B9D4C 05000682 */  lb         $a2, 0x5($s0)
    /* 51550 800B9D50 1F00A530 */  andi       $a1, $a1, 0x1F
    /* 51554 800B9D54 D1EC010C */  jal        func_8007B344
    /* 51558 800B9D58 1000A2AF */   sw        $v0, 0x10($sp)
  .L800B9D5C:
    /* 5155C 800B9D5C 3800BF8F */  lw         $ra, 0x38($sp)
    /* 51560 800B9D60 3400B18F */  lw         $s1, 0x34($sp)
    /* 51564 800B9D64 3000B08F */  lw         $s0, 0x30($sp)
    /* 51568 800B9D68 21100000 */  addu       $v0, $zero, $zero
    /* 5156C 800B9D6C 0800E003 */  jr         $ra
    /* 51570 800B9D70 4000BD27 */   addiu     $sp, $sp, 0x40
endlabel func_800B9C58
