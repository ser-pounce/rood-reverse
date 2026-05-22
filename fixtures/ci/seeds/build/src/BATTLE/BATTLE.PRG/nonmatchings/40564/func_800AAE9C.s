nonmatching func_800AAE9C, 0x1FC

glabel func_800AAE9C
    /* 4269C 800AAE9C D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 426A0 800AAEA0 0F80033C */  lui        $v1, %hi(D_800E8F2C)
    /* 426A4 800AAEA4 0F80023C */  lui        $v0, %hi(D_800F2450)
    /* 426A8 800AAEA8 2C8F6390 */  lbu        $v1, %lo(D_800E8F2C)($v1)
    /* 426AC 800AAEAC 50244224 */  addiu      $v0, $v0, %lo(D_800F2450)
    /* 426B0 800AAEB0 2400BFAF */  sw         $ra, 0x24($sp)
    /* 426B4 800AAEB4 2000B4AF */  sw         $s4, 0x20($sp)
    /* 426B8 800AAEB8 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 426BC 800AAEBC 1800B2AF */  sw         $s2, 0x18($sp)
    /* 426C0 800AAEC0 1400B1AF */  sw         $s1, 0x14($sp)
    /* 426C4 800AAEC4 1000B0AF */  sw         $s0, 0x10($sp)
    /* 426C8 800AAEC8 21186200 */  addu       $v1, $v1, $v0
    /* 426CC 800AAECC 00006290 */  lbu        $v0, 0x0($v1)
    /* 426D0 800AAED0 00000000 */  nop
    /* 426D4 800AAED4 03004014 */  bnez       $v0, .L800AAEE4
    /* 426D8 800AAED8 21A08000 */   addu      $s4, $a0, $zero
    /* 426DC 800AAEDC 1DAC0208 */  j          .L800AB074
    /* 426E0 800AAEE0 21100000 */   addu      $v0, $zero, $zero
  .L800AAEE4:
    /* 426E4 800AAEE4 21800000 */  addu       $s0, $zero, $zero
    /* 426E8 800AAEE8 01001324 */  addiu      $s3, $zero, 0x1
    /* 426EC 800AAEEC 0F80023C */  lui        $v0, %hi(D_800E909C)
    /* 426F0 800AAEF0 9C905224 */  addiu      $s2, $v0, %lo(D_800E909C)
    /* 426F4 800AAEF4 0F80023C */  lui        $v0, %hi(D_800E916C)
    /* 426F8 800AAEF8 6C915124 */  addiu      $s1, $v0, %lo(D_800E916C)
  .L800AAEFC:
    /* 426FC 800AAEFC 80101000 */  sll        $v0, $s0, 2
    /* 42700 800AAF00 0C184224 */  addiu      $v0, $v0, 0x180C
    /* 42704 800AAF04 21288202 */  addu       $a1, $s4, $v0
    /* 42708 800AAF08 0000A490 */  lbu        $a0, 0x0($a1)
    /* 4270C 800AAF0C 00000000 */  nop
    /* 42710 800AAF10 0F008230 */  andi       $v0, $a0, 0xF
    /* 42714 800AAF14 53004010 */  beqz       $v0, .L800AB064
    /* 42718 800AAF18 02190400 */   srl       $v1, $a0, 4
    /* 4271C 800AAF1C 11007310 */  beq        $v1, $s3, .L800AAF64
    /* 42720 800AAF20 02006228 */   slti      $v0, $v1, 0x2
    /* 42724 800AAF24 05004010 */  beqz       $v0, .L800AAF3C
    /* 42728 800AAF28 02000224 */   addiu     $v0, $zero, 0x2
    /* 4272C 800AAF2C 07006010 */  beqz       $v1, .L800AAF4C
    /* 42730 800AAF30 00000000 */   nop
    /* 42734 800AAF34 14AC0208 */  j          .L800AB050
    /* 42738 800AAF38 00000000 */   nop
  .L800AAF3C:
    /* 4273C 800AAF3C 44006214 */  bne        $v1, $v0, .L800AB050
    /* 42740 800AAF40 00000000 */   nop
    /* 42744 800AAF44 1AAC0208 */  j          .L800AB068
    /* 42748 800AAF48 01001026 */   addiu     $s0, $s0, 0x1
  .L800AAF4C:
    /* 4274C 800AAF4C 0100A290 */  lbu        $v0, 0x1($a1)
    /* 42750 800AAF50 00000000 */  nop
    /* 42754 800AAF54 03005314 */  bne        $v0, $s3, .L800AAF64
    /* 42758 800AAF58 F0008230 */   andi      $v0, $a0, 0xF0
    /* 4275C 800AAF5C 19AC0208 */  j          .L800AB064
    /* 42760 800AAF60 0000A2A0 */   sb        $v0, 0x0($a1)
  .L800AAF64:
    /* 42764 800AAF64 0B000016 */  bnez       $s0, .L800AAF94
    /* 42768 800AAF68 00000000 */   nop
    /* 4276C 800AAF6C 0000A290 */  lbu        $v0, 0x0($a1)
    /* 42770 800AAF70 00000000 */  nop
    /* 42774 800AAF74 0F004230 */  andi       $v0, $v0, 0xF
    /* 42778 800AAF78 C0180200 */  sll        $v1, $v0, 3
    /* 4277C 800AAF7C 23186200 */  subu       $v1, $v1, $v0
    /* 42780 800AAF80 0200A290 */  lbu        $v0, 0x2($a1)
    /* 42784 800AAF84 C0180300 */  sll        $v1, $v1, 3
    /* 42788 800AAF88 40100200 */  sll        $v0, $v0, 1
    /* 4278C 800AAF8C EBAB0208 */  j          .L800AAFAC
    /* 42790 800AAF90 21105200 */   addu      $v0, $v0, $s2
  .L800AAF94:
    /* 42794 800AAF94 0000A390 */  lbu        $v1, 0x0($a1)
    /* 42798 800AAF98 0200A290 */  lbu        $v0, 0x2($a1)
    /* 4279C 800AAF9C 0F006330 */  andi       $v1, $v1, 0xF
    /* 427A0 800AAFA0 00190300 */  sll        $v1, $v1, 4
    /* 427A4 800AAFA4 40100200 */  sll        $v0, $v0, 1
    /* 427A8 800AAFA8 21105100 */  addu       $v0, $v0, $s1
  .L800AAFAC:
    /* 427AC 800AAFAC 21206200 */  addu       $a0, $v1, $v0
    /* 427B0 800AAFB0 0300A290 */  lbu        $v0, 0x3($a1)
    /* 427B4 800AAFB4 00000000 */  nop
    /* 427B8 800AAFB8 01004224 */  addiu      $v0, $v0, 0x1
    /* 427BC 800AAFBC 0300A2A0 */  sb         $v0, 0x3($a1)
    /* 427C0 800AAFC0 01008390 */  lbu        $v1, 0x1($a0)
    /* 427C4 800AAFC4 FF004230 */  andi       $v0, $v0, 0xFF
    /* 427C8 800AAFC8 2B186200 */  sltu       $v1, $v1, $v0
    /* 427CC 800AAFCC 19006010 */  beqz       $v1, .L800AB034
    /* 427D0 800AAFD0 00000000 */   nop
    /* 427D4 800AAFD4 0200A290 */  lbu        $v0, 0x2($a1)
    /* 427D8 800AAFD8 02008424 */  addiu      $a0, $a0, 0x2
    /* 427DC 800AAFDC 0300A0A0 */  sb         $zero, 0x3($a1)
    /* 427E0 800AAFE0 01004224 */  addiu      $v0, $v0, 0x1
    /* 427E4 800AAFE4 0200A2A0 */  sb         $v0, 0x2($a1)
    /* 427E8 800AAFE8 00008290 */  lbu        $v0, 0x0($a0)
    /* 427EC 800AAFEC 00000000 */  nop
    /* 427F0 800AAFF0 14004014 */  bnez       $v0, .L800AB044
    /* 427F4 800AAFF4 00000000 */   nop
    /* 427F8 800AAFF8 09000016 */  bnez       $s0, .L800AB020
    /* 427FC 800AAFFC 0200A0A0 */   sb        $zero, 0x2($a1)
    /* 42800 800AB000 0000A390 */  lbu        $v1, 0x0($a1)
    /* 42804 800AB004 00000000 */  nop
    /* 42808 800AB008 0F006330 */  andi       $v1, $v1, 0xF
    /* 4280C 800AB00C C0100300 */  sll        $v0, $v1, 3
    /* 42810 800AB010 23104300 */  subu       $v0, $v0, $v1
    /* 42814 800AB014 C0100200 */  sll        $v0, $v0, 3
    /* 42818 800AB018 0DAC0208 */  j          .L800AB034
    /* 4281C 800AB01C 21205200 */   addu      $a0, $v0, $s2
  .L800AB020:
    /* 42820 800AB020 0000A290 */  lbu        $v0, 0x0($a1)
    /* 42824 800AB024 00000000 */  nop
    /* 42828 800AB028 0F004230 */  andi       $v0, $v0, 0xF
    /* 4282C 800AB02C 00110200 */  sll        $v0, $v0, 4
    /* 42830 800AB030 21205100 */  addu       $a0, $v0, $s1
  .L800AB034:
    /* 42834 800AB034 00008290 */  lbu        $v0, 0x0($a0)
    /* 42838 800AB038 00000000 */  nop
    /* 4283C 800AB03C 0D004010 */  beqz       $v0, .L800AB074
    /* 42840 800AB040 00000000 */   nop
  .L800AB044:
    /* 42844 800AB044 00008290 */  lbu        $v0, 0x0($a0)
    /* 42848 800AB048 00000000 */  nop
    /* 4284C 800AB04C 0100A2A0 */  sb         $v0, 0x1($a1)
  .L800AB050:
    /* 42850 800AB050 0100A690 */  lbu        $a2, 0x1($a1)
    /* 42854 800AB054 21208002 */  addu       $a0, $s4, $zero
    /* 42858 800AB058 21280002 */  addu       $a1, $s0, $zero
    /* 4285C 800AB05C 26AC020C */  jal        func_800AB098
    /* 42860 800AB060 FFFFC624 */   addiu     $a2, $a2, -0x1
  .L800AB064:
    /* 42864 800AB064 01001026 */  addiu      $s0, $s0, 0x1
  .L800AB068:
    /* 42868 800AB068 0200022A */  slti       $v0, $s0, 0x2
    /* 4286C 800AB06C A3FF4014 */  bnez       $v0, .L800AAEFC
    /* 42870 800AB070 00000000 */   nop
  .L800AB074:
    /* 42874 800AB074 2400BF8F */  lw         $ra, 0x24($sp)
    /* 42878 800AB078 2000B48F */  lw         $s4, 0x20($sp)
    /* 4287C 800AB07C 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 42880 800AB080 1800B28F */  lw         $s2, 0x18($sp)
    /* 42884 800AB084 1400B18F */  lw         $s1, 0x14($sp)
    /* 42888 800AB088 1000B08F */  lw         $s0, 0x10($sp)
    /* 4288C 800AB08C 2800BD27 */  addiu      $sp, $sp, 0x28
    /* 42890 800AB090 0800E003 */  jr         $ra
    /* 42894 800AB094 00000000 */   nop
endlabel func_800AAE9C
