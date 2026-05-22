nonmatching vs_mainMenu_copyItem, 0x558

glabel vs_mainMenu_copyItem
    /* 5394 800FEB94 C8FFBD27 */  addiu      $sp, $sp, -0x38
    /* 5398 800FEB98 1000B0AF */  sw         $s0, 0x10($sp)
    /* 539C 800FEB9C 21808000 */  addu       $s0, $a0, $zero
    /* 53A0 800FEBA0 2800B6AF */  sw         $s6, 0x28($sp)
    /* 53A4 800FEBA4 21B0A000 */  addu       $s6, $a1, $zero
    /* 53A8 800FEBA8 1400B1AF */  sw         $s1, 0x14($sp)
    /* 53AC 800FEBAC 2188C000 */  addu       $s1, $a2, $zero
    /* 53B0 800FEBB0 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 53B4 800FEBB4 039A1000 */  sra        $s3, $s0, 8
    /* 53B8 800FEBB8 03111000 */  sra        $v0, $s0, 4
    /* 53BC 800FEBBC 0F001032 */  andi       $s0, $s0, 0xF
    /* 53C0 800FEBC0 2400B5AF */  sw         $s5, 0x24($sp)
    /* 53C4 800FEBC4 21A80000 */  addu       $s5, $zero, $zero
    /* 53C8 800FEBC8 21200002 */  addu       $a0, $s0, $zero
    /* 53CC 800FEBCC 3000BEAF */  sw         $fp, 0x30($sp)
    /* 53D0 800FEBD0 01005E30 */  andi       $fp, $v0, 0x1
    /* 53D4 800FEBD4 3400BFAF */  sw         $ra, 0x34($sp)
    /* 53D8 800FEBD8 2C00B7AF */  sw         $s7, 0x2C($sp)
    /* 53DC 800FEBDC 2000B4AF */  sw         $s4, 0x20($sp)
    /* 53E0 800FEBE0 1800B2AF */  sw         $s2, 0x18($sp)
    /* 53E4 800FEBE4 9BFA030C */  jal        vs_mainMenu_getItemCount
    /* 53E8 800FEBE8 4400A7AF */   sw        $a3, 0x44($sp)
    /* 53EC 800FEBEC 21200002 */  addu       $a0, $s0, $zero
    /* 53F0 800FEBF0 2128C002 */  addu       $a1, $s6, $zero
    /* 53F4 800FEBF4 C2FA030C */  jal        vs_mainMenu_getFirstEmptyItemSlot
    /* 53F8 800FEBF8 21B84000 */   addu      $s7, $v0, $zero
    /* 53FC 800FEBFC 21904000 */  addu       $s2, $v0, $zero
    /* 5400 800FEC00 0700022E */  sltiu      $v0, $s0, 0x7
    /* 5404 800FEC04 2C014010 */  beqz       $v0, .L800FF0B8
    /* 5408 800FEC08 1080023C */   lui       $v0, %hi(jtbl_800F99DC)
    /* 540C 800FEC0C DC994224 */  addiu      $v0, $v0, %lo(jtbl_800F99DC)
    /* 5410 800FEC10 80181000 */  sll        $v1, $s0, 2
    /* 5414 800FEC14 21186200 */  addu       $v1, $v1, $v0
    /* 5418 800FEC18 0000628C */  lw         $v0, 0x0($v1)
    /* 541C 800FEC1C 00000000 */  nop
    /* 5420 800FEC20 08004000 */  jr         $v0
    /* 5424 800FEC24 00000000 */   nop
    /* 5428 800FEC28 4400A88F */  lw         $t0, 0x44($sp)
    /* 542C 800FEC2C 40111100 */  sll        $v0, $s1, 5
    /* 5430 800FEC30 21A00201 */  addu       $s4, $t0, $v0
    /* 5434 800FEC34 40111200 */  sll        $v0, $s2, 5
    /* 5438 800FEC38 2198C202 */  addu       $s3, $s6, $v0
    /* 543C 800FEC3C 08000224 */  addiu      $v0, $zero, 0x8
    /* 5440 800FEC40 1D01E212 */  beq        $s7, $v0, .L800FF0B8
    /* 5444 800FEC44 01000424 */   addiu     $a0, $zero, 0x1
    /* 5448 800FEC48 9BFA030C */  jal        vs_mainMenu_getItemCount
    /* 544C 800FEC4C 2128C002 */   addu      $a1, $s6, $zero
    /* 5450 800FEC50 10001024 */  addiu      $s0, $zero, 0x10
    /* 5454 800FEC54 18015010 */  beq        $v0, $s0, .L800FF0B8
    /* 5458 800FEC58 02000424 */   addiu     $a0, $zero, 0x2
    /* 545C 800FEC5C 9BFA030C */  jal        vs_mainMenu_getItemCount
    /* 5460 800FEC60 2128C002 */   addu      $a1, $s6, $zero
    /* 5464 800FEC64 14015010 */  beq        $v0, $s0, .L800FF0B8
    /* 5468 800FEC68 21880000 */   addu      $s1, $zero, $zero
    /* 546C 800FEC6C 21802002 */  addu       $s0, $s1, $zero
    /* 5470 800FEC70 21109002 */  addu       $v0, $s4, $s0
  .L800FEC74:
    /* 5474 800FEC74 04004290 */  lbu        $v0, 0x4($v0)
    /* 5478 800FEC78 00000000 */  nop
    /* 547C 800FEC7C 02004010 */  beqz       $v0, .L800FEC88
    /* 5480 800FEC80 00000000 */   nop
    /* 5484 800FEC84 01003126 */  addiu      $s1, $s1, 0x1
  .L800FEC88:
    /* 5488 800FEC88 01001026 */  addiu      $s0, $s0, 0x1
    /* 548C 800FEC8C 0300022A */  slti       $v0, $s0, 0x3
    /* 5490 800FEC90 F8FF4014 */  bnez       $v0, .L800FEC74
    /* 5494 800FEC94 21109002 */   addu      $v0, $s4, $s0
    /* 5498 800FEC98 05000424 */  addiu      $a0, $zero, 0x5
    /* 549C 800FEC9C 9BFA030C */  jal        vs_mainMenu_getItemCount
    /* 54A0 800FECA0 2128C002 */   addu      $a1, $s6, $zero
    /* 54A4 800FECA4 21105100 */  addu       $v0, $v0, $s1
    /* 54A8 800FECA8 31004228 */  slti       $v0, $v0, 0x31
    /* 54AC 800FECAC 03014010 */  beqz       $v0, .L800FF0BC
    /* 54B0 800FECB0 2110A002 */   addu      $v0, $s5, $zero
    /* 54B4 800FECB4 0001C013 */  beqz       $fp, .L800FF0B8
    /* 54B8 800FECB8 01005526 */   addiu     $s5, $s2, 0x1
    /* 54BC 800FECBC 21206002 */  addu       $a0, $s3, $zero
    /* 54C0 800FECC0 0733030C */  jal        vs_battle_rMemzero
    /* 54C4 800FECC4 20000524 */   addiu     $a1, $zero, 0x20
    /* 54C8 800FECC8 00121500 */  sll        $v0, $s5, 8
    /* 54CC 800FECCC 11004434 */  ori        $a0, $v0, 0x11
    /* 54D0 800FECD0 2128C002 */  addu       $a1, $s6, $zero
    /* 54D4 800FECD4 4400A78F */  lw         $a3, 0x44($sp)
    /* 54D8 800FECD8 21800000 */  addu       $s0, $zero, $zero
    /* 54DC 800FECDC 000075A2 */  sb         $s5, 0x0($s3)
    /* 54E0 800FECE0 01008692 */  lbu        $a2, 0x1($s4)
    /* 54E4 800FECE4 21884000 */  addu       $s1, $v0, $zero
    /* 54E8 800FECE8 E5FA030C */  jal        vs_mainMenu_copyItem
    /* 54EC 800FECEC FFFFC624 */   addiu     $a2, $a2, -0x1
    /* 54F0 800FECF0 12002436 */  ori        $a0, $s1, 0x12
    /* 54F4 800FECF4 2128C002 */  addu       $a1, $s6, $zero
    /* 54F8 800FECF8 010062A2 */  sb         $v0, 0x1($s3)
    /* 54FC 800FECFC 02008692 */  lbu        $a2, 0x2($s4)
    /* 5500 800FED00 4400A78F */  lw         $a3, 0x44($sp)
    /* 5504 800FED04 E5FA030C */  jal        vs_mainMenu_copyItem
    /* 5508 800FED08 FFFFC624 */   addiu     $a2, $a2, -0x1
    /* 550C 800FED0C 020062A2 */  sb         $v0, 0x2($s3)
    /* 5510 800FED10 21189002 */  addu       $v1, $s4, $s0
  .L800FED14:
    /* 5514 800FED14 04006290 */  lbu        $v0, 0x4($v1)
    /* 5518 800FED18 00000000 */  nop
    /* 551C 800FED1C 08004010 */  beqz       $v0, .L800FED40
    /* 5520 800FED20 15002436 */   ori       $a0, $s1, 0x15
    /* 5524 800FED24 2128C002 */  addu       $a1, $s6, $zero
    /* 5528 800FED28 21304000 */  addu       $a2, $v0, $zero
    /* 552C 800FED2C 4400A78F */  lw         $a3, 0x44($sp)
    /* 5530 800FED30 E5FA030C */  jal        vs_mainMenu_copyItem
    /* 5534 800FED34 FFFFC624 */   addiu     $a2, $a2, -0x1
    /* 5538 800FED38 21187002 */  addu       $v1, $s3, $s0
    /* 553C 800FED3C 040062A0 */  sb         $v0, 0x4($v1)
  .L800FED40:
    /* 5540 800FED40 01001026 */  addiu      $s0, $s0, 0x1
    /* 5544 800FED44 0300022A */  slti       $v0, $s0, 0x3
    /* 5548 800FED48 F2FF4014 */  bnez       $v0, .L800FED14
    /* 554C 800FED4C 21189002 */   addu      $v1, $s4, $s0
    /* 5550 800FED50 08006426 */  addiu      $a0, $s3, 0x8
    /* 5554 800FED54 08008526 */  addiu      $a1, $s4, 0x8
    /* 5558 800FED58 0D33030C */  jal        vs_battle_rMemcpy
    /* 555C 800FED5C 18000624 */   addiu     $a2, $zero, 0x18
    /* 5560 800FED60 2FFC0308 */  j          .L800FF0BC
    /* 5564 800FED64 2110A002 */   addu      $v0, $s5, $zero
    /* 5568 800FED68 40101100 */  sll        $v0, $s1, 1
    /* 556C 800FED6C 21105100 */  addu       $v0, $v0, $s1
    /* 5570 800FED70 80100200 */  sll        $v0, $v0, 2
    /* 5574 800FED74 23105100 */  subu       $v0, $v0, $s1
    /* 5578 800FED78 80100200 */  sll        $v0, $v0, 2
    /* 557C 800FED7C 4400A88F */  lw         $t0, 0x44($sp)
    /* 5580 800FED80 80024224 */  addiu      $v0, $v0, 0x280
    /* 5584 800FED84 21280201 */  addu       $a1, $t0, $v0
    /* 5588 800FED88 40101200 */  sll        $v0, $s2, 1
    /* 558C 800FED8C 21105200 */  addu       $v0, $v0, $s2
    /* 5590 800FED90 80100200 */  sll        $v0, $v0, 2
    /* 5594 800FED94 23105200 */  subu       $v0, $v0, $s2
    /* 5598 800FED98 80100200 */  sll        $v0, $v0, 2
    /* 559C 800FED9C 80024224 */  addiu      $v0, $v0, 0x280
    /* 55A0 800FEDA0 2180C202 */  addu       $s0, $s6, $v0
    /* 55A4 800FEDA4 10000224 */  addiu      $v0, $zero, 0x10
    /* 55A8 800FEDA8 C400E212 */  beq        $s7, $v0, .L800FF0BC
    /* 55AC 800FEDAC 2110A002 */   addu      $v0, $s5, $zero
    /* 55B0 800FEDB0 C100C013 */  beqz       $fp, .L800FF0B8
    /* 55B4 800FEDB4 01005526 */   addiu     $s5, $s2, 0x1
    /* 55B8 800FEDB8 21200002 */  addu       $a0, $s0, $zero
    /* 55BC 800FEDBC 7000030C */  jal        vs_battle_copyAligned
    /* 55C0 800FEDC0 2C000624 */   addiu     $a2, $zero, 0x2C
    /* 55C4 800FEDC4 2B0015A2 */  sb         $s5, 0x2B($s0)
    /* 55C8 800FEDC8 2EFC0308 */  j          .L800FF0B8
    /* 55CC 800FEDCC 2A0013A2 */   sb        $s3, 0x2A($s0)
    /* 55D0 800FEDD0 00111100 */  sll        $v0, $s1, 4
    /* 55D4 800FEDD4 4400A88F */  lw         $t0, 0x44($sp)
    /* 55D8 800FEDD8 40054224 */  addiu      $v0, $v0, 0x540
    /* 55DC 800FEDDC 21280201 */  addu       $a1, $t0, $v0
    /* 55E0 800FEDE0 00111200 */  sll        $v0, $s2, 4
    /* 55E4 800FEDE4 40054224 */  addiu      $v0, $v0, 0x540
    /* 55E8 800FEDE8 2180C202 */  addu       $s0, $s6, $v0
    /* 55EC 800FEDEC 10000224 */  addiu      $v0, $zero, 0x10
    /* 55F0 800FEDF0 B100E212 */  beq        $s7, $v0, .L800FF0B8
    /* 55F4 800FEDF4 00000000 */   nop
    /* 55F8 800FEDF8 AF00C013 */  beqz       $fp, .L800FF0B8
    /* 55FC 800FEDFC 01005526 */   addiu     $s5, $s2, 0x1
    /* 5600 800FEE00 21200002 */  addu       $a0, $s0, $zero
    /* 5604 800FEE04 7000030C */  jal        vs_battle_copyAligned
    /* 5608 800FEE08 21304000 */   addu      $a2, $v0, $zero
    /* 560C 800FEE0C 0E0015A6 */  sh         $s5, 0xE($s0)
    /* 5610 800FEE10 2EFC0308 */  j          .L800FF0B8
    /* 5614 800FEE14 0C0013A6 */   sh        $s3, 0xC($s0)
    /* 5618 800FEE18 40101100 */  sll        $v0, $s1, 1
    /* 561C 800FEE1C 21105100 */  addu       $v0, $v0, $s1
    /* 5620 800FEE20 00110200 */  sll        $v0, $v0, 4
    /* 5624 800FEE24 4400A88F */  lw         $t0, 0x44($sp)
    /* 5628 800FEE28 00014224 */  addiu      $v0, $v0, 0x100
    /* 562C 800FEE2C 21A00201 */  addu       $s4, $t0, $v0
    /* 5630 800FEE30 40101200 */  sll        $v0, $s2, 1
    /* 5634 800FEE34 21105200 */  addu       $v0, $v0, $s2
    /* 5638 800FEE38 00110200 */  sll        $v0, $v0, 4
    /* 563C 800FEE3C 00014224 */  addiu      $v0, $v0, 0x100
    /* 5640 800FEE40 2198C202 */  addu       $s3, $s6, $v0
    /* 5644 800FEE44 08000224 */  addiu      $v0, $zero, 0x8
    /* 5648 800FEE48 9B00E212 */  beq        $s7, $v0, .L800FF0B8
    /* 564C 800FEE4C 21880000 */   addu      $s1, $zero, $zero
    /* 5650 800FEE50 21802002 */  addu       $s0, $s1, $zero
    /* 5654 800FEE54 21109002 */  addu       $v0, $s4, $s0
  .L800FEE58:
    /* 5658 800FEE58 2C004290 */  lbu        $v0, 0x2C($v0)
    /* 565C 800FEE5C 00000000 */  nop
    /* 5660 800FEE60 02004010 */  beqz       $v0, .L800FEE6C
    /* 5664 800FEE64 00000000 */   nop
    /* 5668 800FEE68 01003126 */  addiu      $s1, $s1, 0x1
  .L800FEE6C:
    /* 566C 800FEE6C 01001026 */  addiu      $s0, $s0, 0x1
    /* 5670 800FEE70 0300022A */  slti       $v0, $s0, 0x3
    /* 5674 800FEE74 F8FF4014 */  bnez       $v0, .L800FEE58
    /* 5678 800FEE78 21109002 */   addu      $v0, $s4, $s0
    /* 567C 800FEE7C 05000424 */  addiu      $a0, $zero, 0x5
    /* 5680 800FEE80 9BFA030C */  jal        vs_mainMenu_getItemCount
    /* 5684 800FEE84 2128C002 */   addu      $a1, $s6, $zero
    /* 5688 800FEE88 21105100 */  addu       $v0, $v0, $s1
    /* 568C 800FEE8C 31004228 */  slti       $v0, $v0, 0x31
    /* 5690 800FEE90 8A004010 */  beqz       $v0, .L800FF0BC
    /* 5694 800FEE94 2110A002 */   addu      $v0, $s5, $zero
    /* 5698 800FEE98 8700C013 */  beqz       $fp, .L800FF0B8
    /* 569C 800FEE9C 01005526 */   addiu     $s5, $s2, 0x1
    /* 56A0 800FEEA0 21206002 */  addu       $a0, $s3, $zero
    /* 56A4 800FEEA4 0733030C */  jal        vs_battle_rMemzero
    /* 56A8 800FEEA8 30000524 */   addiu     $a1, $zero, 0x30
    /* 56AC 800FEEAC 04006426 */  addiu      $a0, $s3, 0x4
    /* 56B0 800FEEB0 04008526 */  addiu      $a1, $s4, 0x4
    /* 56B4 800FEEB4 7000030C */  jal        vs_battle_copyAligned
    /* 56B8 800FEEB8 28000624 */   addiu     $a2, $zero, 0x28
    /* 56BC 800FEEBC 000075A2 */  sb         $s5, 0x0($s3)
    /* 56C0 800FEEC0 21800000 */  addu       $s0, $zero, $zero
    /* 56C4 800FEEC4 8000A236 */  ori        $v0, $s5, 0x80
    /* 56C8 800FEEC8 008A0200 */  sll        $s1, $v0, 8
    /* 56CC 800FEECC 21189002 */  addu       $v1, $s4, $s0
  .L800FEED0:
    /* 56D0 800FEED0 2C006290 */  lbu        $v0, 0x2C($v1)
    /* 56D4 800FEED4 00000000 */  nop
    /* 56D8 800FEED8 08004010 */  beqz       $v0, .L800FEEFC
    /* 56DC 800FEEDC 15002436 */   ori       $a0, $s1, 0x15
    /* 56E0 800FEEE0 2128C002 */  addu       $a1, $s6, $zero
    /* 56E4 800FEEE4 21304000 */  addu       $a2, $v0, $zero
    /* 56E8 800FEEE8 4400A78F */  lw         $a3, 0x44($sp)
    /* 56EC 800FEEEC E5FA030C */  jal        vs_mainMenu_copyItem
    /* 56F0 800FEEF0 FFFFC624 */   addiu     $a2, $a2, -0x1
    /* 56F4 800FEEF4 21187002 */  addu       $v1, $s3, $s0
    /* 56F8 800FEEF8 2C0062A0 */  sb         $v0, 0x2C($v1)
  .L800FEEFC:
    /* 56FC 800FEEFC 01001026 */  addiu      $s0, $s0, 0x1
    /* 5700 800FEF00 0300022A */  slti       $v0, $s0, 0x3
    /* 5704 800FEF04 F2FF4014 */  bnez       $v0, .L800FEED0
    /* 5708 800FEF08 21189002 */   addu      $v1, $s4, $s0
    /* 570C 800FEF0C 2FFC0308 */  j          .L800FF0BC
    /* 5710 800FEF10 2110A002 */   addu      $v0, $s5, $zero
    /* 5714 800FEF14 80101100 */  sll        $v0, $s1, 2
    /* 5718 800FEF18 21105100 */  addu       $v0, $v0, $s1
    /* 571C 800FEF1C C0100200 */  sll        $v0, $v0, 3
    /* 5720 800FEF20 4400A88F */  lw         $t0, 0x44($sp)
    /* 5724 800FEF24 40064224 */  addiu      $v0, $v0, 0x640
    /* 5728 800FEF28 21280201 */  addu       $a1, $t0, $v0
    /* 572C 800FEF2C 80101200 */  sll        $v0, $s2, 2
    /* 5730 800FEF30 21105200 */  addu       $v0, $v0, $s2
    /* 5734 800FEF34 C0100200 */  sll        $v0, $v0, 3
    /* 5738 800FEF38 40064224 */  addiu      $v0, $v0, 0x640
    /* 573C 800FEF3C 2180C202 */  addu       $s0, $s6, $v0
    /* 5740 800FEF40 10000224 */  addiu      $v0, $zero, 0x10
    /* 5744 800FEF44 5D00E212 */  beq        $s7, $v0, .L800FF0BC
    /* 5748 800FEF48 2110A002 */   addu      $v0, $s5, $zero
    /* 574C 800FEF4C 5A00C013 */  beqz       $fp, .L800FF0B8
    /* 5750 800FEF50 01005526 */   addiu     $s5, $s2, 0x1
    /* 5754 800FEF54 21200002 */  addu       $a0, $s0, $zero
    /* 5758 800FEF58 7000030C */  jal        vs_battle_copyAligned
    /* 575C 800FEF5C 28000624 */   addiu     $a2, $zero, 0x28
    /* 5760 800FEF60 2EFC0308 */  j          .L800FF0B8
    /* 5764 800FEF64 270015A2 */   sb        $s5, 0x27($s0)
    /* 5768 800FEF68 C0101100 */  sll        $v0, $s1, 3
    /* 576C 800FEF6C 23105100 */  subu       $v0, $v0, $s1
    /* 5770 800FEF70 80100200 */  sll        $v0, $v0, 2
    /* 5774 800FEF74 4400A88F */  lw         $t0, 0x44($sp)
    /* 5778 800FEF78 C0084224 */  addiu      $v0, $v0, 0x8C0
    /* 577C 800FEF7C 21280201 */  addu       $a1, $t0, $v0
    /* 5780 800FEF80 C0101200 */  sll        $v0, $s2, 3
    /* 5784 800FEF84 23105200 */  subu       $v0, $v0, $s2
    /* 5788 800FEF88 80100200 */  sll        $v0, $v0, 2
    /* 578C 800FEF8C C0084224 */  addiu      $v0, $v0, 0x8C0
    /* 5790 800FEF90 2180C202 */  addu       $s0, $s6, $v0
    /* 5794 800FEF94 30000224 */  addiu      $v0, $zero, 0x30
    /* 5798 800FEF98 4800E212 */  beq        $s7, $v0, .L800FF0BC
    /* 579C 800FEF9C 2110A002 */   addu      $v0, $s5, $zero
    /* 57A0 800FEFA0 4500C013 */  beqz       $fp, .L800FF0B8
    /* 57A4 800FEFA4 01005526 */   addiu     $s5, $s2, 0x1
    /* 57A8 800FEFA8 21200002 */  addu       $a0, $s0, $zero
    /* 57AC 800FEFAC 7000030C */  jal        vs_battle_copyAligned
    /* 57B0 800FEFB0 1C000624 */   addiu     $a2, $zero, 0x1C
    /* 57B4 800FEFB4 1A0015A6 */  sh         $s5, 0x1A($s0)
    /* 57B8 800FEFB8 2EFC0308 */  j          .L800FF0B8
    /* 57BC 800FEFBC 180013A6 */   sh        $s3, 0x18($s0)
    /* 57C0 800FEFC0 80101100 */  sll        $v0, $s1, 2
    /* 57C4 800FEFC4 000E4224 */  addiu      $v0, $v0, 0xE00
    /* 57C8 800FEFC8 06000424 */  addiu      $a0, $zero, 0x6
    /* 57CC 800FEFCC 4400A88F */  lw         $t0, 0x44($sp)
    /* 57D0 800FEFD0 00000000 */  nop
    /* 57D4 800FEFD4 21980201 */  addu       $s3, $t0, $v0
    /* 57D8 800FEFD8 02007192 */  lbu        $s1, 0x2($s3)
    /* 57DC 800FEFDC 2CFA030C */  jal        vs_mainMenu_rebuildInventory
    /* 57E0 800FEFE0 000ED426 */   addiu     $s4, $s6, 0xE00
    /* 57E4 800FEFE4 21800000 */  addu       $s0, $zero, $zero
    /* 57E8 800FEFE8 0680023C */  lui        $v0, %hi(vs_main_inventoryIndices)
    /* 57EC 800FEFEC D8194624 */  addiu      $a2, $v0, %lo(vs_main_inventoryIndices)
    /* 57F0 800FEFF0 64000524 */  addiu      $a1, $zero, 0x64
    /* 57F4 800FEFF4 21100602 */  addu       $v0, $s0, $a2
  .L800FEFF8:
    /* 57F8 800FEFF8 70004290 */  lbu        $v0, 0x70($v0)
    /* 57FC 800FEFFC 00000000 */  nop
    /* 5800 800FF000 1C004010 */  beqz       $v0, .L800FF074
    /* 5804 800FF004 80100200 */   sll       $v0, $v0, 2
    /* 5808 800FF008 FCFF4224 */  addiu      $v0, $v0, -0x4
    /* 580C 800FF00C 21208202 */  addu       $a0, $s4, $v0
    /* 5810 800FF010 00008394 */  lhu        $v1, 0x0($a0)
    /* 5814 800FF014 00006296 */  lhu        $v0, 0x0($s3)
    /* 5818 800FF018 00000000 */  nop
    /* 581C 800FF01C 15006214 */  bne        $v1, $v0, .L800FF074
    /* 5820 800FF020 00000000 */   nop
    /* 5824 800FF024 0D00C013 */  beqz       $fp, .L800FF05C
    /* 5828 800FF028 9CFF2226 */   addiu     $v0, $s1, -0x64
    /* 582C 800FF02C 02008390 */  lbu        $v1, 0x2($a0)
    /* 5830 800FF030 00000000 */  nop
    /* 5834 800FF034 2310A300 */  subu       $v0, $a1, $v1
    /* 5838 800FF038 2A105100 */  slt        $v0, $v0, $s1
    /* 583C 800FF03C 04004014 */  bnez       $v0, .L800FF050
    /* 5840 800FF040 9CFF2226 */   addiu     $v0, $s1, -0x64
    /* 5844 800FF044 21107100 */  addu       $v0, $v1, $s1
    /* 5848 800FF048 1CFC0308 */  j          .L800FF070
    /* 584C 800FF04C 020082A0 */   sb        $v0, 0x2($a0)
  .L800FF050:
    /* 5850 800FF050 21884300 */  addu       $s1, $v0, $v1
    /* 5854 800FF054 1DFC0308 */  j          .L800FF074
    /* 5858 800FF058 020085A0 */   sb        $a1, 0x2($a0)
  .L800FF05C:
    /* 585C 800FF05C 02008390 */  lbu        $v1, 0x2($a0)
    /* 5860 800FF060 00000000 */  nop
    /* 5864 800FF064 21884300 */  addu       $s1, $v0, $v1
    /* 5868 800FF068 02002106 */  bgez       $s1, .L800FF074
    /* 586C 800FF06C 00000000 */   nop
  .L800FF070:
    /* 5870 800FF070 21880000 */  addu       $s1, $zero, $zero
  .L800FF074:
    /* 5874 800FF074 01001026 */  addiu      $s0, $s0, 0x1
    /* 5878 800FF078 4000022A */  slti       $v0, $s0, 0x40
    /* 587C 800FF07C DEFF4014 */  bnez       $v0, .L800FEFF8
    /* 5880 800FF080 21100602 */   addu      $v0, $s0, $a2
    /* 5884 800FF084 03002016 */  bnez       $s1, .L800FF094
    /* 5888 800FF088 40000224 */   addiu     $v0, $zero, 0x40
    /* 588C 800FF08C 2EFC0308 */  j          .L800FF0B8
    /* 5890 800FF090 01001524 */   addiu     $s5, $zero, 0x1
  .L800FF094:
    /* 5894 800FF094 0900E212 */  beq        $s7, $v0, .L800FF0BC
    /* 5898 800FF098 2110A002 */   addu      $v0, $s5, $zero
    /* 589C 800FF09C 0600C013 */  beqz       $fp, .L800FF0B8
    /* 58A0 800FF0A0 01005526 */   addiu     $s5, $s2, 0x1
    /* 58A4 800FF0A4 80101200 */  sll        $v0, $s2, 2
    /* 58A8 800FF0A8 00006396 */  lhu        $v1, 0x0($s3)
    /* 58AC 800FF0AC 21105400 */  addu       $v0, $v0, $s4
    /* 58B0 800FF0B0 020051A0 */  sb         $s1, 0x2($v0)
    /* 58B4 800FF0B4 000043A4 */  sh         $v1, 0x0($v0)
  .L800FF0B8:
    /* 58B8 800FF0B8 2110A002 */  addu       $v0, $s5, $zero
  .L800FF0BC:
    /* 58BC 800FF0BC 3400BF8F */  lw         $ra, 0x34($sp)
    /* 58C0 800FF0C0 3000BE8F */  lw         $fp, 0x30($sp)
    /* 58C4 800FF0C4 2C00B78F */  lw         $s7, 0x2C($sp)
    /* 58C8 800FF0C8 2800B68F */  lw         $s6, 0x28($sp)
    /* 58CC 800FF0CC 2400B58F */  lw         $s5, 0x24($sp)
    /* 58D0 800FF0D0 2000B48F */  lw         $s4, 0x20($sp)
    /* 58D4 800FF0D4 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 58D8 800FF0D8 1800B28F */  lw         $s2, 0x18($sp)
    /* 58DC 800FF0DC 1400B18F */  lw         $s1, 0x14($sp)
    /* 58E0 800FF0E0 1000B08F */  lw         $s0, 0x10($sp)
    /* 58E4 800FF0E4 0800E003 */  jr         $ra
    /* 58E8 800FF0E8 3800BD27 */   addiu     $sp, $sp, 0x38
endlabel vs_mainMenu_copyItem
