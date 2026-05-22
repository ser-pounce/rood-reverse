nonmatching func_800CBBCC, 0x55C

glabel func_800CBBCC
    /* 633CC 800CBBCC 90FFBD27 */  addiu      $sp, $sp, -0x70
    /* 633D0 800CBBD0 801F033C */  lui        $v1, (0x1F800400 >> 16)
    /* 633D4 800CBBD4 00046334 */  ori        $v1, $v1, (0x1F800400 & 0xFFFF)
    /* 633D8 800CBBD8 4C00B1AF */  sw         $s1, 0x4C($sp)
    /* 633DC 800CBBDC 21880000 */  addu       $s1, $zero, $zero
    /* 633E0 800CBBE0 6C00BFAF */  sw         $ra, 0x6C($sp)
    /* 633E4 800CBBE4 6800BEAF */  sw         $fp, 0x68($sp)
    /* 633E8 800CBBE8 6400B7AF */  sw         $s7, 0x64($sp)
    /* 633EC 800CBBEC 6000B6AF */  sw         $s6, 0x60($sp)
    /* 633F0 800CBBF0 5C00B5AF */  sw         $s5, 0x5C($sp)
    /* 633F4 800CBBF4 5800B4AF */  sw         $s4, 0x58($sp)
    /* 633F8 800CBBF8 5400B3AF */  sw         $s3, 0x54($sp)
    /* 633FC 800CBBFC 5000B2AF */  sw         $s2, 0x50($sp)
    /* 63400 800CBC00 4800B0AF */  sw         $s0, 0x48($sp)
    /* 63404 800CBC04 7000A4AF */  sw         $a0, 0x70($sp)
    /* 63408 800CBC08 7400A5AF */  sw         $a1, 0x74($sp)
    /* 6340C 800CBC0C 7800A6AF */  sw         $a2, 0x78($sp)
    /* 63410 800CBC10 08008284 */  lh         $v0, 0x8($a0)
    /* 63414 800CBC14 03008A90 */  lbu        $t2, 0x3($a0)
    /* 63418 800CBC18 00028B24 */  addiu      $t3, $a0, 0x200
    /* 6341C 800CBC1C 1C00ABAF */  sw         $t3, 0x1C($sp)
    /* 63420 800CBC20 A0005E24 */  addiu      $fp, $v0, 0xA0
    /* 63424 800CBC24 1000AAAF */  sw         $t2, 0x10($sp)
    /* 63428 800CBC28 0C008294 */  lhu        $v0, 0xC($a0)
    /* 6342C 800CBC2C 04008A90 */  lbu        $t2, 0x4($a0)
    /* 63430 800CBC30 FF3F4230 */  andi       $v0, $v0, 0x3FFF
    /* 63434 800CBC34 2000A2AF */  sw         $v0, 0x20($sp)
    /* 63438 800CBC38 01004225 */  addiu      $v0, $t2, 0x1
    /* 6343C 800CBC3C 40100200 */  sll        $v0, $v0, 1
    /* 63440 800CBC40 2400AAAF */  sw         $t2, 0x24($sp)
    /* 63444 800CBC44 05008B90 */  lbu        $t3, 0x5($a0)
    /* 63448 800CBC48 23186200 */  subu       $v1, $v1, $v0
    /* 6344C 800CBC4C 3000A3AF */  sw         $v1, 0x30($sp)
    /* 63450 800CBC50 40100B00 */  sll        $v0, $t3, 1
    /* 63454 800CBC54 02004224 */  addiu      $v0, $v0, 0x2
    /* 63458 800CBC58 23806200 */  subu       $s0, $v1, $v0
    /* 6345C 800CBC5C 2A105101 */  slt        $v0, $t2, $s1
    /* 63460 800CBC60 11004014 */  bnez       $v0, .L800CBCA8
    /* 63464 800CBC64 2800ABAF */   sw        $t3, 0x28($sp)
    /* 63468 800CBC68 2400AA8F */  lw         $t2, 0x24($sp)
  .L800CBC6C:
    /* 6346C 800CBC6C 40101100 */  sll        $v0, $s1, 1
    /* 63470 800CBC70 23104A00 */  subu       $v0, $v0, $t2
    /* 63474 800CBC74 2000AA8F */  lw         $t2, 0x20($sp)
    /* 63478 800CBC78 00000000 */  nop
    /* 6347C 800CBC7C 18004A00 */  mult       $v0, $t2
    /* 63480 800CBC80 01003126 */  addiu      $s1, $s1, 0x1
    /* 63484 800CBC84 12580000 */  mflo       $t3
    /* 63488 800CBC88 C3110B00 */  sra        $v0, $t3, 7
    /* 6348C 800CBC8C 21105E00 */  addu       $v0, $v0, $fp
    /* 63490 800CBC90 000062A4 */  sh         $v0, 0x0($v1)
    /* 63494 800CBC94 2400AA8F */  lw         $t2, 0x24($sp)
    /* 63498 800CBC98 00000000 */  nop
    /* 6349C 800CBC9C 2A105101 */  slt        $v0, $t2, $s1
    /* 634A0 800CBCA0 F2FF4010 */  beqz       $v0, .L800CBC6C
    /* 634A4 800CBCA4 02006324 */   addiu     $v1, $v1, 0x2
  .L800CBCA8:
    /* 634A8 800CBCA8 7000AB8F */  lw         $t3, 0x70($sp)
    /* 634AC 800CBCAC 21880000 */  addu       $s1, $zero, $zero
    /* 634B0 800CBCB0 0A006285 */  lh         $v0, 0xA($t3)
    /* 634B4 800CBCB4 2800AA8F */  lw         $t2, 0x28($sp)
    /* 634B8 800CBCB8 78005E24 */  addiu      $fp, $v0, 0x78
    /* 634BC 800CBCBC 2A105101 */  slt        $v0, $t2, $s1
    /* 634C0 800CBCC0 11004014 */  bnez       $v0, .L800CBD08
    /* 634C4 800CBCC4 21200002 */   addu      $a0, $s0, $zero
  .L800CBCC8:
    /* 634C8 800CBCC8 40181100 */  sll        $v1, $s1, 1
    /* 634CC 800CBCCC 2800AB8F */  lw         $t3, 0x28($sp)
    /* 634D0 800CBCD0 2000AA8F */  lw         $t2, 0x20($sp)
    /* 634D4 800CBCD4 23186B00 */  subu       $v1, $v1, $t3
    /* 634D8 800CBCD8 18006A00 */  mult       $v1, $t2
    /* 634DC 800CBCDC 01003126 */  addiu      $s1, $s1, 0x1
    /* 634E0 800CBCE0 12180000 */  mflo       $v1
    /* 634E4 800CBCE4 00110300 */  sll        $v0, $v1, 4
    /* 634E8 800CBCE8 23104300 */  subu       $v0, $v0, $v1
    /* 634EC 800CBCEC 43130200 */  sra        $v0, $v0, 13
    /* 634F0 800CBCF0 21105E00 */  addu       $v0, $v0, $fp
    /* 634F4 800CBCF4 000082A4 */  sh         $v0, 0x0($a0)
    /* 634F8 800CBCF8 2A107101 */  slt        $v0, $t3, $s1
    /* 634FC 800CBCFC F2FF4010 */  beqz       $v0, .L800CBCC8
    /* 63500 800CBD00 02008424 */   addiu     $a0, $a0, 0x2
    /* 63504 800CBD04 7000AB8F */  lw         $t3, 0x70($sp)
  .L800CBD08:
    /* 63508 800CBD08 00000000 */  nop
    /* 6350C 800CBD0C 0E006B95 */  lhu        $t3, 0xE($t3)
    /* 63510 800CBD10 00000000 */  nop
    /* 63514 800CBD14 4D006011 */  beqz       $t3, .L800CBE4C
    /* 63518 800CBD18 2C00ABAF */   sw        $t3, 0x2C($sp)
    /* 6351C 800CBD1C C0100B00 */  sll        $v0, $t3, 3
    /* 63520 800CBD20 1000AA8F */  lw         $t2, 0x10($sp)
    /* 63524 800CBD24 F8004230 */  andi       $v0, $v0, 0xF8
    /* 63528 800CBD28 18004A00 */  mult       $v0, $t2
    /* 6352C 800CBD2C 12200000 */  mflo       $a0
    /* 63530 800CBD30 83100B00 */  sra        $v0, $t3, 2
    /* 63534 800CBD34 F8004230 */  andi       $v0, $v0, 0xF8
    /* 63538 800CBD38 18004A00 */  mult       $v0, $t2
    /* 6353C 800CBD3C 12400000 */  mflo       $t0
    /* 63540 800CBD40 C3110B00 */  sra        $v0, $t3, 7
    /* 63544 800CBD44 F8004230 */  andi       $v0, $v0, 0xF8
    /* 63548 800CBD48 18004A00 */  mult       $v0, $t2
    /* 6354C 800CBD4C C3210400 */  sra        $a0, $a0, 7
    /* 63550 800CBD50 C3110800 */  sra        $v0, $t0, 7
    /* 63554 800CBD54 00120200 */  sll        $v0, $v0, 8
    /* 63558 800CBD58 25208200 */  or         $a0, $a0, $v0
    /* 6355C 800CBD5C 0F80023C */  lui        $v0, %hi(D_800F51C8)
    /* 63560 800CBD60 C8514290 */  lbu        $v0, %lo(D_800F51C8)($v0)
    /* 63564 800CBD64 00001186 */  lh         $s1, 0x0($s0)
    /* 63568 800CBD68 30004224 */  addiu      $v0, $v0, 0x30
    /* 6356C 800CBD6C 40160200 */  sll        $v0, $v0, 25
    /* 63570 800CBD70 12180000 */  mflo       $v1
    /* 63574 800CBD74 C3190300 */  sra        $v1, $v1, 7
    /* 63578 800CBD78 001C0300 */  sll        $v1, $v1, 16
    /* 6357C 800CBD7C 25208300 */  or         $a0, $a0, $v1
    /* 63580 800CBD80 25208200 */  or         $a0, $a0, $v0
    /* 63584 800CBD84 0700201A */  blez       $s1, .L800CBDA4
    /* 63588 800CBD88 1400A4AF */   sw        $a0, 0x14($sp)
    /* 6358C 800CBD8C 21300000 */  addu       $a2, $zero, $zero
    /* 63590 800CBD90 003C1100 */  sll        $a3, $s1, 16
    /* 63594 800CBD94 7800A48F */  lw         $a0, 0x78($sp)
    /* 63598 800CBD98 1400A58F */  lw         $a1, 0x14($sp)
    /* 6359C 800CBD9C 2E33030C */  jal        func_800CCCB8
    /* 635A0 800CBDA0 4001E734 */   ori       $a3, $a3, 0x140
  .L800CBDA4:
    /* 635A4 800CBDA4 2800AA8F */  lw         $t2, 0x28($sp)
    /* 635A8 800CBDA8 00000000 */  nop
    /* 635AC 800CBDAC 40100A00 */  sll        $v0, $t2, 1
    /* 635B0 800CBDB0 21105000 */  addu       $v0, $v0, $s0
    /* 635B4 800CBDB4 00005184 */  lh         $s1, 0x0($v0)
    /* 635B8 800CBDB8 00000000 */  nop
    /* 635BC 800CBDBC F000222A */  slti       $v0, $s1, 0xF0
    /* 635C0 800CBDC0 07004010 */  beqz       $v0, .L800CBDE0
    /* 635C4 800CBDC4 00341100 */   sll       $a2, $s1, 16
    /* 635C8 800CBDC8 F000073C */  lui        $a3, (0xF00000 >> 16)
    /* 635CC 800CBDCC 2338E600 */  subu       $a3, $a3, $a2
    /* 635D0 800CBDD0 7800A48F */  lw         $a0, 0x78($sp)
    /* 635D4 800CBDD4 1400A58F */  lw         $a1, 0x14($sp)
    /* 635D8 800CBDD8 2E33030C */  jal        func_800CCCB8
    /* 635DC 800CBDDC 4001E734 */   ori       $a3, $a3, 0x140
  .L800CBDE0:
    /* 635E0 800CBDE0 3000AB8F */  lw         $t3, 0x30($sp)
    /* 635E4 800CBDE4 00000000 */  nop
    /* 635E8 800CBDE8 00007185 */  lh         $s1, 0x0($t3)
    /* 635EC 800CBDEC 00000000 */  nop
    /* 635F0 800CBDF0 0600201A */  blez       $s1, .L800CBE0C
    /* 635F4 800CBDF4 21300000 */   addu      $a2, $zero, $zero
    /* 635F8 800CBDF8 F000073C */  lui        $a3, (0xF00000 >> 16)
    /* 635FC 800CBDFC 7800A48F */  lw         $a0, 0x78($sp)
    /* 63600 800CBE00 1400A58F */  lw         $a1, 0x14($sp)
    /* 63604 800CBE04 2E33030C */  jal        func_800CCCB8
    /* 63608 800CBE08 25382702 */   or        $a3, $s1, $a3
  .L800CBE0C:
    /* 6360C 800CBE0C 2400AA8F */  lw         $t2, 0x24($sp)
    /* 63610 800CBE10 3000AB8F */  lw         $t3, 0x30($sp)
    /* 63614 800CBE14 40100A00 */  sll        $v0, $t2, 1
    /* 63618 800CBE18 21104B00 */  addu       $v0, $v0, $t3
    /* 6361C 800CBE1C 00005184 */  lh         $s1, 0x0($v0)
    /* 63620 800CBE20 00000000 */  nop
    /* 63624 800CBE24 4001222A */  slti       $v0, $s1, 0x140
    /* 63628 800CBE28 08004010 */  beqz       $v0, .L800CBE4C
    /* 6362C 800CBE2C FFFF2632 */   andi      $a2, $s1, 0xFFFF
    /* 63630 800CBE30 40010724 */  addiu      $a3, $zero, 0x140
    /* 63634 800CBE34 2338F100 */  subu       $a3, $a3, $s1
    /* 63638 800CBE38 F000023C */  lui        $v0, (0xF00000 >> 16)
    /* 6363C 800CBE3C 7800A48F */  lw         $a0, 0x78($sp)
    /* 63640 800CBE40 1400A58F */  lw         $a1, 0x14($sp)
    /* 63644 800CBE44 2E33030C */  jal        func_800CCCB8
    /* 63648 800CBE48 2538E200 */   or        $a3, $a3, $v0
  .L800CBE4C:
    /* 6364C 800CBE4C 21F00000 */  addu       $fp, $zero, $zero
    /* 63650 800CBE50 0F80023C */  lui        $v0, %hi(D_800F51C8)
    /* 63654 800CBE54 1000AA8F */  lw         $t2, 0x10($sp)
    /* 63658 800CBE58 C8514290 */  lbu        $v0, %lo(D_800F51C8)($v0)
    /* 6365C 800CBE5C 2800AB8F */  lw         $t3, 0x28($sp)
    /* 63660 800CBE60 00220A00 */  sll        $a0, $t2, 8
    /* 63664 800CBE64 25204401 */  or         $a0, $t2, $a0
    /* 63668 800CBE68 002C0A00 */  sll        $a1, $t2, 16
    /* 6366C 800CBE6C 001A0200 */  sll        $v1, $v0, 8
    /* 63670 800CBE70 25504301 */  or         $t2, $t2, $v1
    /* 63674 800CBE74 25208500 */  or         $a0, $a0, $a1
    /* 63678 800CBE78 16004224 */  addiu      $v0, $v0, 0x16
    /* 6367C 800CBE7C 40160200 */  sll        $v0, $v0, 25
    /* 63680 800CBE80 25208200 */  or         $a0, $a0, $v0
    /* 63684 800CBE84 1000AAAF */  sw         $t2, 0x10($sp)
    /* 63688 800CBE88 9B006011 */  beqz       $t3, .L800CC0F8
    /* 6368C 800CBE8C 1800A4AF */   sw        $a0, 0x18($sp)
    /* 63690 800CBE90 3800A0AF */  sw         $zero, 0x38($sp)
    /* 63694 800CBE94 21480002 */  addu       $t1, $s0, $zero
  .L800CBE98:
    /* 63698 800CBE98 00003785 */  lh         $s7, 0x0($t1)
    /* 6369C 800CBE9C 00000000 */  nop
    /* 636A0 800CBEA0 F000E22A */  slti       $v0, $s7, 0xF0
    /* 636A4 800CBEA4 8A004010 */  beqz       $v0, .L800CC0D0
    /* 636A8 800CBEA8 00000000 */   nop
    /* 636AC 800CBEAC 02003685 */  lh         $s6, 0x2($t1)
    /* 636B0 800CBEB0 00000000 */  nop
    /* 636B4 800CBEB4 8600C006 */  bltz       $s6, .L800CC0D0
    /* 636B8 800CBEB8 00000000 */   nop
    /* 636BC 800CBEBC 2400AA8F */  lw         $t2, 0x24($sp)
    /* 636C0 800CBEC0 00000000 */  nop
    /* 636C4 800CBEC4 82004011 */  beqz       $t2, .L800CC0D0
    /* 636C8 800CBEC8 21880000 */   addu      $s1, $zero, $zero
    /* 636CC 800CBECC 00AC1700 */  sll        $s5, $s7, 16
    /* 636D0 800CBED0 3000B48F */  lw         $s4, 0x30($sp)
    /* 636D4 800CBED4 005C1600 */  sll        $t3, $s6, 16
    /* 636D8 800CBED8 3400ABAF */  sw         $t3, 0x34($sp)
  .L800CBEDC:
    /* 636DC 800CBEDC 00008786 */  lh         $a3, 0x0($s4)
    /* 636E0 800CBEE0 00000000 */  nop
    /* 636E4 800CBEE4 4001E228 */  slti       $v0, $a3, 0x140
    /* 636E8 800CBEE8 74004010 */  beqz       $v0, .L800CC0BC
    /* 636EC 800CBEEC 00000000 */   nop
    /* 636F0 800CBEF0 02008886 */  lh         $t0, 0x2($s4)
    /* 636F4 800CBEF4 00000000 */  nop
    /* 636F8 800CBEF8 70000005 */  bltz       $t0, .L800CC0BC
    /* 636FC 800CBEFC 00000000 */   nop
    /* 63700 800CBF00 3800AA8F */  lw         $t2, 0x38($sp)
    /* 63704 800CBF04 00000000 */  nop
    /* 63708 800CBF08 21102A02 */  addu       $v0, $s1, $t2
    /* 6370C 800CBF0C 1C00AB8F */  lw         $t3, 0x1C($sp)
    /* 63710 800CBF10 40100200 */  sll        $v0, $v0, 1
    /* 63714 800CBF14 21104B00 */  addu       $v0, $v0, $t3
    /* 63718 800CBF18 00004594 */  lhu        $a1, 0x0($v0)
    /* 6371C 800CBF1C 00000000 */  nop
    /* 63720 800CBF20 5100A010 */  beqz       $a1, .L800CC068
    /* 63724 800CBF24 80810500 */   sll       $s0, $a1, 6
    /* 63728 800CBF28 C0001332 */  andi       $s3, $s0, 0xC0
    /* 6372C 800CBF2C 001F0232 */  andi       $v0, $s0, 0x1F00
    /* 63730 800CBF30 00190200 */  sll        $v1, $v0, 4
    /* 63734 800CBF34 23806200 */  subu       $s0, $v1, $v0
    /* 63738 800CBF38 83180500 */  sra        $v1, $a1, 2
    /* 6373C 800CBF3C C0016330 */  andi       $v1, $v1, 0x1C0
    /* 63740 800CBF40 7000AA8F */  lw         $t2, 0x70($sp)
    /* 63744 800CBF44 2000AB8F */  lw         $t3, 0x20($sp)
    /* 63748 800CBF48 0000448D */  lw         $a0, 0x0($t2)
    /* 6374C 800CBF4C 02004291 */  lbu        $v0, 0x2($t2)
    /* 63750 800CBF50 40210400 */  sll        $a0, $a0, 5
    /* 63754 800CBF54 80008430 */  andi       $a0, $a0, 0x80
    /* 63758 800CBF58 EEFF4224 */  addiu      $v0, $v0, -0x12
    /* 6375C 800CBF5C 80110200 */  sll        $v0, $v0, 6
    /* 63760 800CBF60 21104300 */  addu       $v0, $v0, $v1
    /* 63764 800CBF64 FF034230 */  andi       $v0, $v0, 0x3FF
    /* 63768 800CBF68 83110200 */  sra        $v0, $v0, 6
    /* 6376C 800CBF6C 30004234 */  ori        $v0, $v0, 0x30
    /* 63770 800CBF70 25908200 */  or         $s2, $a0, $v0
    /* 63774 800CBF74 00100224 */  addiu      $v0, $zero, 0x1000
    /* 63778 800CBF78 0B006215 */  bne        $t3, $v0, .L800CBFA8
    /* 6377C 800CBF7C 40006526 */   addiu     $a1, $s3, 0x40
    /* 63780 800CBF80 2528F500 */  or         $a1, $a3, $s5
    /* 63784 800CBF84 0F00063C */  lui        $a2, (0xF0040 >> 16)
    /* 63788 800CBF88 1000A48F */  lw         $a0, 0x10($sp)
    /* 6378C 800CBF8C 7800A78F */  lw         $a3, 0x78($sp)
    /* 63790 800CBF90 4000C634 */  ori        $a2, $a2, (0xF0040 & 0xFFFF)
    /* 63794 800CBF94 8C00030C */  jal        vs_battle_setSprite
    /* 63798 800CBF98 4000A9AF */   sw        $t1, 0x40($sp)
    /* 6379C 800CBF9C 4000A98F */  lw         $t1, 0x40($sp)
    /* 637A0 800CBFA0 12300308 */  j          .L800CC048
    /* 637A4 800CBFA4 21304000 */   addu      $a2, $v0, $zero
  .L800CBFA8:
    /* 637A8 800CBFA8 03120500 */  sra        $v0, $a1, 8
    /* 637AC 800CBFAC 2328A200 */  subu       $a1, $a1, $v0
    /* 637B0 800CBFB0 FF00033C */  lui        $v1, (0xFFFFFF >> 16)
    /* 637B4 800CBFB4 FFFF6334 */  ori        $v1, $v1, (0xFFFFFF & 0xFFFF)
    /* 637B8 800CBFB8 801F0B3C */  lui        $t3, (0x1F800000 >> 16)
    /* 637BC 800CBFBC 7800AA8F */  lw         $t2, 0x78($sp)
    /* 637C0 800CBFC0 FFFFE430 */  andi       $a0, $a3, 0xFFFF
    /* 637C4 800CBFC4 0000428D */  lw         $v0, 0x0($t2)
    /* 637C8 800CBFC8 0000668D */  lw         $a2, (0x1F800000 & 0xFFFF)($t3)
    /* 637CC 800CBFCC 24104300 */  and        $v0, $v0, $v1
    /* 637D0 800CBFD0 000A033C */  lui        $v1, (0xA000000 >> 16)
    /* 637D4 800CBFD4 25104300 */  or         $v0, $v0, $v1
    /* 637D8 800CBFD8 0000C2AC */  sw         $v0, 0x0($a2)
    /* 637DC 800CBFDC 1800AA8F */  lw         $t2, 0x18($sp)
    /* 637E0 800CBFE0 25109500 */  or         $v0, $a0, $s5
    /* 637E4 800CBFE4 0C00C2AC */  sw         $v0, 0xC($a2)
    /* 637E8 800CBFE8 25101501 */  or         $v0, $t0, $s5
    /* 637EC 800CBFEC 1400C2AC */  sw         $v0, 0x14($a2)
    /* 637F0 800CBFF0 2510B000 */  or         $v0, $a1, $s0
    /* 637F4 800CBFF4 001C1200 */  sll        $v1, $s2, 16
    /* 637F8 800CBFF8 25104300 */  or         $v0, $v0, $v1
    /* 637FC 800CBFFC 000F0326 */  addiu      $v1, $s0, 0xF00
    /* 63800 800CC000 1800C2AC */  sw         $v0, 0x18($a2)
    /* 63804 800CC004 25106302 */  or         $v0, $s3, $v1
    /* 63808 800CC008 0800CAAC */  sw         $t2, 0x8($a2)
    /* 6380C 800CC00C 3400AB8F */  lw         $t3, 0x34($sp)
    /* 63810 800CC010 2528A300 */  or         $a1, $a1, $v1
    /* 63814 800CC014 2000C2AC */  sw         $v0, 0x20($a2)
    /* 63818 800CC018 2800C5AC */  sw         $a1, 0x28($a2)
    /* 6381C 800CC01C 25208B00 */  or         $a0, $a0, $t3
    /* 63820 800CC020 25100B01 */  or         $v0, $t0, $t3
    /* 63824 800CC024 2400C2AC */  sw         $v0, 0x24($a2)
    /* 63828 800CC028 00120600 */  sll        $v0, $a2, 8
    /* 6382C 800CC02C 02120200 */  srl        $v0, $v0, 8
    /* 63830 800CC030 1C00C4AC */  sw         $a0, 0x1C($a2)
    /* 63834 800CC034 7800AA8F */  lw         $t2, 0x78($sp)
    /* 63838 800CC038 801F0B3C */  lui        $t3, (0x1F800000 >> 16)
    /* 6383C 800CC03C 000042AD */  sw         $v0, 0x0($t2)
    /* 63840 800CC040 2C00C224 */  addiu      $v0, $a2, 0x2C
    /* 63844 800CC044 000062AD */  sw         $v0, (0x1F800000 & 0xFFFF)($t3)
  .L800CC048:
    /* 63848 800CC048 00E1023C */  lui        $v0, (0xE1000000 >> 16)
    /* 6384C 800CC04C 25104202 */  or         $v0, $s2, $v0
    /* 63850 800CC050 0400C2AC */  sw         $v0, 0x4($a2)
    /* 63854 800CC054 7400AA8F */  lw         $t2, 0x74($sp)
    /* 63858 800CC058 25107002 */  or         $v0, $s3, $s0
    /* 6385C 800CC05C 25104A00 */  or         $v0, $v0, $t2
    /* 63860 800CC060 2F300308 */  j          .L800CC0BC
    /* 63864 800CC064 1000C2AC */   sw        $v0, 0x10($a2)
  .L800CC068:
    /* 63868 800CC068 2C00AB8F */  lw         $t3, 0x2C($sp)
    /* 6386C 800CC06C 00000000 */  nop
    /* 63870 800CC070 12006011 */  beqz       $t3, .L800CC0BC
    /* 63874 800CC074 00800234 */   ori       $v0, $zero, 0x8000
    /* 63878 800CC078 06006215 */  bne        $t3, $v0, .L800CC094
    /* 6387C 800CC07C FFFFE630 */   andi      $a2, $a3, 0xFFFF
    /* 63880 800CC080 0F80023C */  lui        $v0, %hi(D_800F51C8)
    /* 63884 800CC084 C8514290 */  lbu        $v0, %lo(D_800F51C8)($v0)
    /* 63888 800CC088 00000000 */  nop
    /* 6388C 800CC08C 0B004014 */  bnez       $v0, .L800CC0BC
    /* 63890 800CC090 00000000 */   nop
  .L800CC094:
    /* 63894 800CC094 2530D500 */  or         $a2, $a2, $s5
    /* 63898 800CC098 23100701 */  subu       $v0, $t0, $a3
    /* 6389C 800CC09C 2338D702 */  subu       $a3, $s6, $s7
    /* 638A0 800CC0A0 003C0700 */  sll        $a3, $a3, 16
    /* 638A4 800CC0A4 7800A48F */  lw         $a0, 0x78($sp)
    /* 638A8 800CC0A8 1400A58F */  lw         $a1, 0x14($sp)
    /* 638AC 800CC0AC 25384700 */  or         $a3, $v0, $a3
    /* 638B0 800CC0B0 2E33030C */  jal        func_800CCCB8
    /* 638B4 800CC0B4 4000A9AF */   sw        $t1, 0x40($sp)
    /* 638B8 800CC0B8 4000A98F */  lw         $t1, 0x40($sp)
  .L800CC0BC:
    /* 638BC 800CC0BC 2400AA8F */  lw         $t2, 0x24($sp)
    /* 638C0 800CC0C0 01003126 */  addiu      $s1, $s1, 0x1
    /* 638C4 800CC0C4 2A102A02 */  slt        $v0, $s1, $t2
    /* 638C8 800CC0C8 84FF4014 */  bnez       $v0, .L800CBEDC
    /* 638CC 800CC0CC 02009426 */   addiu     $s4, $s4, 0x2
  .L800CC0D0:
    /* 638D0 800CC0D0 3800AB8F */  lw         $t3, 0x38($sp)
    /* 638D4 800CC0D4 2400AA8F */  lw         $t2, 0x24($sp)
    /* 638D8 800CC0D8 00000000 */  nop
    /* 638DC 800CC0DC 21586A01 */  addu       $t3, $t3, $t2
    /* 638E0 800CC0E0 3800ABAF */  sw         $t3, 0x38($sp)
    /* 638E4 800CC0E4 2800AB8F */  lw         $t3, 0x28($sp)
    /* 638E8 800CC0E8 0100DE27 */  addiu      $fp, $fp, 0x1
    /* 638EC 800CC0EC 2A10CB03 */  slt        $v0, $fp, $t3
    /* 638F0 800CC0F0 69FF4014 */  bnez       $v0, .L800CBE98
    /* 638F4 800CC0F4 02002925 */   addiu     $t1, $t1, 0x2
  .L800CC0F8:
    /* 638F8 800CC0F8 6C00BF8F */  lw         $ra, 0x6C($sp)
    /* 638FC 800CC0FC 6800BE8F */  lw         $fp, 0x68($sp)
    /* 63900 800CC100 6400B78F */  lw         $s7, 0x64($sp)
    /* 63904 800CC104 6000B68F */  lw         $s6, 0x60($sp)
    /* 63908 800CC108 5C00B58F */  lw         $s5, 0x5C($sp)
    /* 6390C 800CC10C 5800B48F */  lw         $s4, 0x58($sp)
    /* 63910 800CC110 5400B38F */  lw         $s3, 0x54($sp)
    /* 63914 800CC114 5000B28F */  lw         $s2, 0x50($sp)
    /* 63918 800CC118 4C00B18F */  lw         $s1, 0x4C($sp)
    /* 6391C 800CC11C 4800B08F */  lw         $s0, 0x48($sp)
    /* 63920 800CC120 0800E003 */  jr         $ra
    /* 63924 800CC124 7000BD27 */   addiu     $sp, $sp, 0x70
endlabel func_800CBBCC
