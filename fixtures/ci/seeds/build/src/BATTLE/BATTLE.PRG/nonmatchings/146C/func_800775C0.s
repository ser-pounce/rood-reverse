nonmatching func_800775C0, 0x830

glabel func_800775C0
    /* EDC0 800775C0 A0FFBD27 */  addiu      $sp, $sp, -0x60
    /* EDC4 800775C4 4C00B5AF */  sw         $s5, 0x4C($sp)
    /* EDC8 800775C8 21A88000 */  addu       $s5, $a0, $zero
    /* EDCC 800775CC 4800B4AF */  sw         $s4, 0x48($sp)
    /* EDD0 800775D0 21A0A000 */  addu       $s4, $a1, $zero
    /* EDD4 800775D4 0F80023C */  lui        $v0, %hi(vs_battle_actors)
    /* EDD8 800775D8 28194224 */  addiu      $v0, $v0, %lo(vs_battle_actors)
    /* EDDC 800775DC 80181500 */  sll        $v1, $s5, 2
    /* EDE0 800775E0 21186200 */  addu       $v1, $v1, $v0
    /* EDE4 800775E4 5C00BFAF */  sw         $ra, 0x5C($sp)
    /* EDE8 800775E8 5800BEAF */  sw         $fp, 0x58($sp)
    /* EDEC 800775EC 5400B7AF */  sw         $s7, 0x54($sp)
    /* EDF0 800775F0 5000B6AF */  sw         $s6, 0x50($sp)
    /* EDF4 800775F4 4400B3AF */  sw         $s3, 0x44($sp)
    /* EDF8 800775F8 4000B2AF */  sw         $s2, 0x40($sp)
    /* EDFC 800775FC 3C00B1AF */  sw         $s1, 0x3C($sp)
    /* EE00 80077600 3800B0AF */  sw         $s0, 0x38($sp)
    /* EE04 80077604 6C00A7AF */  sw         $a3, 0x6C($sp)
    /* EE08 80077608 0000628C */  lw         $v0, 0x0($v1)
    /* EE0C 8007760C 00000000 */  nop
    /* EE10 80077610 EA014014 */  bnez       $v0, .L80077DBC
    /* EE14 80077614 21B0C000 */   addu      $s6, $a2, $zero
    /* EE18 80077618 0580023C */  lui        $v0, %hi(D_8004FE88)
    /* EE1C 8007761C 88FE4224 */  addiu      $v0, $v0, %lo(D_8004FE88)
    /* EE20 80077620 0200C392 */  lbu        $v1, 0x2($s6)
    /* EE24 80077624 6004D38E */  lw         $s3, 0x460($s6)
    /* EE28 80077628 3700D792 */  lbu        $s7, 0x37($s6)
    /* EE2C 8007762C 21186200 */  addu       $v1, $v1, $v0
    /* EE30 80077630 00006290 */  lbu        $v0, 0x0($v1)
    /* EE34 80077634 4301DE92 */  lbu        $fp, 0x143($s6)
    /* EE38 80077638 0D004010 */  beqz       $v0, .L80077670
    /* EE3C 8007763C 00000000 */   nop
    /* EE40 80077640 B10F010C */  jal        vs_main_allocHeap
    /* EE44 80077644 B43B0424 */   addiu     $a0, $zero, 0x3BB4
    /* EE48 80077648 21884000 */  addu       $s1, $v0, $zero
    /* EE4C 8007764C 50002226 */  addiu      $v0, $s1, 0x50
    /* EE50 80077650 3C0022AE */  sw         $v0, 0x3C($s1)
    /* EE54 80077654 02000224 */  addiu      $v0, $zero, 0x2
    /* EE58 80077658 400022AE */  sw         $v0, 0x40($s1)
    /* EE5C 8007765C B4092226 */  addiu      $v0, $s1, 0x9B4
    /* EE60 80077660 440022AE */  sw         $v0, 0x44($s1)
    /* EE64 80077664 B4222226 */  addiu      $v0, $s1, 0x22B4
    /* EE68 80077668 A9DD0108 */  j          .L800776A4
    /* EE6C 8007766C 480022AE */   sw        $v0, 0x48($s1)
  .L80077670:
    /* EE70 80077670 B10F010C */  jal        vs_main_allocHeap
    /* EE74 80077674 842E0424 */   addiu     $a0, $zero, 0x2E84
    /* EE78 80077678 21884000 */  addu       $s1, $v0, $zero
    /* EE7C 8007767C 50002226 */  addiu      $v0, $s1, 0x50
    /* EE80 80077680 3C0022AE */  sw         $v0, 0x3C($s1)
    /* EE84 80077684 01000224 */  addiu      $v0, $zero, 0x1
    /* EE88 80077688 400022AE */  sw         $v0, 0x40($s1)
    /* EE8C 8007768C B4092226 */  addiu      $v0, $s1, 0x9B4
    /* EE90 80077690 440022AE */  sw         $v0, 0x44($s1)
    /* EE94 80077694 B4222226 */  addiu      $v0, $s1, 0x22B4
    /* EE98 80077698 480022AE */  sw         $v0, 0x48($s1)
    /* EE9C 8007769C 9C282226 */  addiu      $v0, $s1, 0x289C
    /* EEA0 800776A0 4C0022AE */  sw         $v0, 0x4C($s1)
  .L800776A4:
    /* EEA4 800776A4 0200E012 */  beqz       $s7, .L800776B0
    /* EEA8 800776A8 0A000224 */   addiu     $v0, $zero, 0xA
    /* EEAC 800776AC 3800C292 */  lbu        $v0, 0x38($s6)
  .L800776B0:
    /* EEB0 800776B0 00000000 */  nop
    /* EEB4 800776B4 250022A2 */  sb         $v0, 0x25($s1)
    /* EEB8 800776B8 0F80023C */  lui        $v0, %hi(_zoneContext)
    /* EEBC 800776BC 80185024 */  addiu      $s0, $v0, %lo(_zoneContext)
    /* EEC0 800776C0 1C00048E */  lw         $a0, 0x1C($s0)
    /* EEC4 800776C4 00000000 */  nop
    /* EEC8 800776C8 0B008010 */  beqz       $a0, .L800776F8
    /* EECC 800776CC 21900000 */   addu      $s2, $zero, $zero
    /* EED0 800776D0 1400038E */  lw         $v1, 0x14($s0)
    /* EED4 800776D4 01006226 */  addiu      $v0, $s3, 0x1
    /* EED8 800776D8 03004314 */  bne        $v0, $v1, .L800776E8
    /* EEDC 800776DC 00000000 */   nop
    /* EEE0 800776E0 BEDD0108 */  j          .L800776F8
    /* EEE4 800776E4 01001224 */   addiu     $s2, $zero, 0x1
  .L800776E8:
    /* EEE8 800776E8 180F010C */  jal        vs_main_freeHeapR
    /* EEEC 800776EC 00000000 */   nop
    /* EEF0 800776F0 1C0000AE */  sw         $zero, 0x1C($s0)
    /* EEF4 800776F4 140000AE */  sw         $zero, 0x14($s0)
  .L800776F8:
    /* EEF8 800776F8 32004016 */  bnez       $s2, .L800777C4
    /* EEFC 800776FC 0F80053C */   lui       $a1, %hi(_zoneContext)
    /* EF00 80077700 0F80023C */  lui        $v0, %hi(_zoneContext)
    /* EF04 80077704 80185024 */  addiu      $s0, $v0, %lo(_zoneContext)
    /* EF08 80077708 1000038E */  lw         $v1, 0x10($s0)
    /* EF0C 8007770C C0101300 */  sll        $v0, $s3, 3
    /* EF10 80077710 21104300 */  addu       $v0, $v0, $v1
    /* EF14 80077714 0000438C */  lw         $v1, 0x0($v0)
    /* EF18 80077718 00000000 */  nop
    /* EF1C 8007771C 3000A3AF */  sw         $v1, 0x30($sp)
    /* EF20 80077720 0400428C */  lw         $v0, 0x4($v0)
    /* EF24 80077724 1800038E */  lw         $v1, 0x18($s0)
    /* EF28 80077728 00000000 */  nop
    /* EF2C 8007772C 04006010 */  beqz       $v1, .L80077740
    /* EF30 80077730 3400A2AF */   sw        $v0, 0x34($sp)
    /* EF34 80077734 A7000424 */  addiu      $a0, $zero, 0xA7
    /* EF38 80077738 2624010C */  jal        vs_main_nop9
    /* EF3C 8007773C 21280000 */   addu      $a1, $zero, $zero
  .L80077740:
    /* EF40 80077740 C412010C */  jal        vs_main_allocateCdQueueSlot
    /* EF44 80077744 3000A427 */   addiu     $a0, $sp, 0x30
    /* EF48 80077748 3400A48F */  lw         $a0, 0x34($sp)
    /* EF4C 8007774C 8F0F010C */  jal        vs_main_allocHeapR
    /* EF50 80077750 180002AE */   sw        $v0, 0x18($s0)
    /* EF54 80077754 1800048E */  lw         $a0, 0x18($s0)
    /* EF58 80077758 21284000 */  addu       $a1, $v0, $zero
    /* EF5C 8007775C FD12010C */  jal        vs_main_cdEnqueuePriority
    /* EF60 80077760 1C0005AE */   sw        $a1, 0x1C($s0)
    /* EF64 80077764 1800028E */  lw         $v0, 0x18($s0)
    /* EF68 80077768 00000000 */  nop
    /* EF6C 8007776C 00004384 */  lh         $v1, 0x0($v0)
    /* EF70 80077770 04000224 */  addiu      $v0, $zero, 0x4
    /* EF74 80077774 0A006210 */  beq        $v1, $v0, .L800777A0
    /* EF78 80077778 21900002 */   addu      $s2, $s0, $zero
    /* EF7C 8007777C 21804000 */  addu       $s0, $v0, $zero
  .L80077780:
    /* EF80 80077780 8709010C */  jal        vs_main_gametimeUpdate
    /* EF84 80077784 21200000 */   addu      $a0, $zero, $zero
    /* EF88 80077788 1800428E */  lw         $v0, 0x18($s2)
    /* EF8C 8007778C 00000000 */  nop
    /* EF90 80077790 00004284 */  lh         $v0, 0x0($v0)
    /* EF94 80077794 00000000 */  nop
    /* EF98 80077798 F9FF5014 */  bne        $v0, $s0, .L80077780
    /* EF9C 8007779C 00000000 */   nop
  .L800777A0:
    /* EFA0 800777A0 0F80103C */  lui        $s0, %hi(_zoneContext)
    /* EFA4 800777A4 80181026 */  addiu      $s0, $s0, %lo(_zoneContext)
    /* EFA8 800777A8 1800048E */  lw         $a0, 0x18($s0)
    /* EFAC 800777AC E012010C */  jal        vs_main_freeCdQueueSlot
    /* EFB0 800777B0 00000000 */   nop
    /* EFB4 800777B4 01006226 */  addiu      $v0, $s3, 0x1
    /* EFB8 800777B8 180000AE */  sw         $zero, 0x18($s0)
    /* EFBC 800777BC 140002AE */  sw         $v0, 0x14($s0)
    /* EFC0 800777C0 0F80053C */  lui        $a1, %hi(_zoneContext)
  .L800777C4:
    /* EFC4 800777C4 8018A624 */  addiu      $a2, $a1, %lo(_zoneContext)
    /* EFC8 800777C8 1C00D28C */  lw         $s2, 0x1C($a2)
    /* EFCC 800777CC 02000224 */  addiu      $v0, $zero, 0x2
    /* EFD0 800777D0 1800A2A3 */  sb         $v0, 0x18($sp)
    /* EFD4 800777D4 1900B5A3 */  sb         $s5, 0x19($sp)
    /* EFD8 800777D8 0800428E */  lw         $v0, 0x8($s2)
    /* EFDC 800777DC 00000000 */  nop
    /* EFE0 800777E0 21105200 */  addu       $v0, $v0, $s2
    /* EFE4 800777E4 2000A2AF */  sw         $v0, 0x20($sp)
    /* EFE8 800777E8 C0101300 */  sll        $v0, $s3, 3
    /* EFEC 800777EC 21105300 */  addu       $v0, $v0, $s3
    /* EFF0 800777F0 80100200 */  sll        $v0, $v0, 2
    /* EFF4 800777F4 23105300 */  subu       $v0, $v0, $s3
    /* EFF8 800777F8 C0100200 */  sll        $v0, $v0, 3
    /* EFFC 800777FC 21105300 */  addu       $v0, $v0, $s3
    /* F000 80077800 0C00C38C */  lw         $v1, 0xC($a2)
    /* F004 80077804 80100200 */  sll        $v0, $v0, 2
    /* F008 80077808 21104300 */  addu       $v0, $v0, $v1
    /* F00C 8007780C 02004290 */  lbu        $v0, 0x2($v0)
    /* F010 80077810 0680043C */  lui        $a0, %hi(D_80061078)
    /* F014 80077814 1A00A2A7 */  sh         $v0, 0x1A($sp)
    /* F018 80077818 0680023C */  lui        $v0, %hi(D_80060064)
    /* F01C 8007781C 6400438C */  lw         $v1, %lo(D_80060064)($v0)
    /* F020 80077820 78108424 */  addiu      $a0, $a0, %lo(D_80061078)
    /* F024 80077824 80100300 */  sll        $v0, $v1, 2
    /* F028 80077828 21104300 */  addu       $v0, $v0, $v1
    /* F02C 8007782C C0100200 */  sll        $v0, $v0, 3
    /* F030 80077830 21104300 */  addu       $v0, $v0, $v1
    /* F034 80077834 C0100200 */  sll        $v0, $v0, 3
    /* F038 80077838 21204400 */  addu       $a0, $v0, $a0
    /* F03C 8007783C 01008390 */  lbu        $v1, 0x1($a0)
    /* F040 80077840 8018A28C */  lw         $v0, %lo(_zoneContext)($a1)
    /* F044 80077844 00000000 */  nop
    /* F048 80077848 19006214 */  bne        $v1, $v0, .L800778B0
    /* F04C 8007784C 00000000 */   nop
    /* F050 80077850 02008394 */  lhu        $v1, 0x2($a0)
    /* F054 80077854 3400C28C */  lw         $v0, 0x34($a2)
    /* F058 80077858 00000000 */  nop
    /* F05C 8007785C 14006214 */  bne        $v1, $v0, .L800778B0
    /* F060 80077860 00000000 */   nop
    /* F064 80077864 01008492 */  lbu        $a0, 0x1($s4)
    /* F068 80077868 A0A7010C */  jal        func_80069E80
    /* F06C 8007786C 00000000 */   nop
    /* F070 80077870 21804000 */  addu       $s0, $v0, $zero
    /* F074 80077874 0E000012 */  beqz       $s0, .L800778B0
    /* F078 80077878 00000000 */   nop
    /* F07C 8007787C 24000292 */  lbu        $v0, 0x24($s0)
    /* F080 80077880 00000000 */  nop
    /* F084 80077884 2400A2A3 */  sb         $v0, 0x24($sp)
    /* F088 80077888 26000292 */  lbu        $v0, 0x26($s0)
    /* F08C 8007788C 00000000 */  nop
    /* F090 80077890 2600A2A3 */  sb         $v0, 0x26($sp)
    /* F094 80077894 25000292 */  lbu        $v0, 0x25($s0)
    /* F098 80077898 00000000 */  nop
    /* F09C 8007789C 2500A2A3 */  sb         $v0, 0x25($sp)
    /* F0A0 800778A0 27000392 */  lbu        $v1, 0x27($s0)
    /* F0A4 800778A4 01004230 */  andi       $v0, $v0, 0x1
    /* F0A8 800778A8 39DE0108 */  j          .L800778E4
    /* F0AC 800778AC 2500A2A3 */   sb        $v0, 0x25($sp)
  .L800778B0:
    /* F0B0 800778B0 0C008292 */  lbu        $v0, 0xC($s4)
    /* F0B4 800778B4 00000000 */  nop
    /* F0B8 800778B8 2400A2A3 */  sb         $v0, 0x24($sp)
    /* F0BC 800778BC 0E008292 */  lbu        $v0, 0xE($s4)
    /* F0C0 800778C0 00000000 */  nop
    /* F0C4 800778C4 2600A2A3 */  sb         $v0, 0x26($sp)
    /* F0C8 800778C8 0D008292 */  lbu        $v0, 0xD($s4)
    /* F0CC 800778CC 00000000 */  nop
    /* F0D0 800778D0 2500A2A3 */  sb         $v0, 0x25($sp)
    /* F0D4 800778D4 0F008392 */  lbu        $v1, 0xF($s4)
    /* F0D8 800778D8 01004230 */  andi       $v0, $v0, 0x1
    /* F0DC 800778DC 2500A2A3 */  sb         $v0, 0x25($sp)
    /* F0E0 800778E0 80190300 */  sll        $v1, $v1, 6
  .L800778E4:
    /* F0E4 800778E4 2700A3A3 */  sb         $v1, 0x27($sp)
    /* F0E8 800778E8 4400238E */  lw         $v1, 0x44($s1)
    /* F0EC 800778EC FF000224 */  addiu      $v0, $zero, 0xFF
    /* F0F0 800778F0 2800A2A3 */  sb         $v0, 0x28($sp)
    /* F0F4 800778F4 1C00A3AF */  sw         $v1, 0x1C($sp)
    /* F0F8 800778F8 25008292 */  lbu        $v0, 0x25($s4)
    /* F0FC 800778FC 00000000 */  nop
    /* F100 80077900 01004230 */  andi       $v0, $v0, 0x1
    /* F104 80077904 2B00A2A3 */  sb         $v0, 0x2B($sp)
    /* F108 80077908 2400C292 */  lbu        $v0, 0x24($s6)
    /* F10C 8007790C 1800A427 */  addiu      $a0, $sp, 0x18
    /* F110 80077910 7A65020C */  jal        vs_battle_populateDataSlot
    /* F114 80077914 2A00A2A3 */   sb        $v0, 0x2A($sp)
    /* F118 80077918 0200C392 */  lbu        $v1, 0x2($s6)
    /* F11C 8007791C 7F000224 */  addiu      $v0, $zero, 0x7F
    /* F120 80077920 68006210 */  beq        $v1, $v0, .L80077AC4
    /* F124 80077924 0580023C */   lui       $v0, %hi(D_8004FE88)
    /* F128 80077928 88FE4224 */  addiu      $v0, $v0, %lo(D_8004FE88)
    /* F12C 8007792C 21186200 */  addu       $v1, $v1, $v0
    /* F130 80077930 00006290 */  lbu        $v0, 0x0($v1)
    /* F134 80077934 00000000 */  nop
    /* F138 80077938 19004010 */  beqz       $v0, .L800779A0
    /* F13C 8007793C 01000224 */   addiu     $v0, $zero, 0x1
    /* F140 80077940 1800A2A3 */  sb         $v0, 0x18($sp)
    /* F144 80077944 0400A226 */  addiu      $v0, $s5, 0x4
    /* F148 80077948 0F80033C */  lui        $v1, %hi(D_800F188C)
    /* F14C 8007794C 1900A2A3 */  sb         $v0, 0x19($sp)
    /* F150 80077950 C0101300 */  sll        $v0, $s3, 3
    /* F154 80077954 21105300 */  addu       $v0, $v0, $s3
    /* F158 80077958 80100200 */  sll        $v0, $v0, 2
    /* F15C 8007795C 23105300 */  subu       $v0, $v0, $s3
    /* F160 80077960 C0100200 */  sll        $v0, $v0, 3
    /* F164 80077964 21105300 */  addu       $v0, $v0, $s3
    /* F168 80077968 8C18638C */  lw         $v1, %lo(D_800F188C)($v1)
    /* F16C 8007796C 80100200 */  sll        $v0, $v0, 2
    /* F170 80077970 21104300 */  addu       $v0, $v0, $v1
    /* F174 80077974 02004290 */  lbu        $v0, 0x2($v0)
    /* F178 80077978 1800A427 */  addiu      $a0, $sp, 0x18
    /* F17C 8007797C 01004224 */  addiu      $v0, $v0, 0x1
    /* F180 80077980 1A00A2A7 */  sh         $v0, 0x1A($sp)
    /* F184 80077984 4800238E */  lw         $v1, 0x48($s1)
    /* F188 80077988 FC000224 */  addiu      $v0, $zero, 0xFC
    /* F18C 8007798C 2800B5A3 */  sb         $s5, 0x28($sp)
    /* F190 80077990 2900A2A3 */  sb         $v0, 0x29($sp)
    /* F194 80077994 2B00A0A3 */  sb         $zero, 0x2B($sp)
    /* F198 80077998 8CDE0108 */  j          .L80077A30
    /* F19C 8007799C 1C00A3AF */   sw        $v1, 0x1C($sp)
  .L800779A0:
    /* F1A0 800779A0 1100E012 */  beqz       $s7, .L800779E8
    /* F1A4 800779A4 04000224 */   addiu     $v0, $zero, 0x4
    /* F1A8 800779A8 1800A2A3 */  sb         $v0, 0x18($sp)
    /* F1AC 800779AC 40101500 */  sll        $v0, $s5, 1
    /* F1B0 800779B0 1900A2A3 */  sb         $v0, 0x19($sp)
    /* F1B4 800779B4 1000428E */  lw         $v0, 0x10($s2)
    /* F1B8 800779B8 1A00B7A7 */  sh         $s7, 0x1A($sp)
    /* F1BC 800779BC 21105200 */  addu       $v0, $v0, $s2
    /* F1C0 800779C0 2000A2AF */  sw         $v0, 0x20($sp)
    /* F1C4 800779C4 4800238E */  lw         $v1, 0x48($s1)
    /* F1C8 800779C8 F0000224 */  addiu      $v0, $zero, 0xF0
    /* F1CC 800779CC 2800B5A3 */  sb         $s5, 0x28($sp)
    /* F1D0 800779D0 2900A2A3 */  sb         $v0, 0x29($sp)
    /* F1D4 800779D4 1C00A3AF */  sw         $v1, 0x1C($sp)
    /* F1D8 800779D8 2401C292 */  lbu        $v0, 0x124($s6)
    /* F1DC 800779DC 1800A427 */  addiu      $a0, $sp, 0x18
    /* F1E0 800779E0 7A65020C */  jal        vs_battle_populateDataSlot
    /* F1E4 800779E4 2A00A2A3 */   sb        $v0, 0x2A($sp)
  .L800779E8:
    /* F1E8 800779E8 1300C013 */  beqz       $fp, .L80077A38
    /* F1EC 800779EC 04000224 */   addiu     $v0, $zero, 0x4
    /* F1F0 800779F0 1800A2A3 */  sb         $v0, 0x18($sp)
    /* F1F4 800779F4 40101500 */  sll        $v0, $s5, 1
    /* F1F8 800779F8 01004224 */  addiu      $v0, $v0, 0x1
    /* F1FC 800779FC 1900A2A3 */  sb         $v0, 0x19($sp)
    /* F200 80077A00 1800428E */  lw         $v0, 0x18($s2)
    /* F204 80077A04 1A00BEA7 */  sh         $fp, 0x1A($sp)
    /* F208 80077A08 21105200 */  addu       $v0, $v0, $s2
    /* F20C 80077A0C 2000A2AF */  sw         $v0, 0x20($sp)
    /* F210 80077A10 4C00238E */  lw         $v1, 0x4C($s1)
    /* F214 80077A14 F1000224 */  addiu      $v0, $zero, 0xF1
    /* F218 80077A18 2800B5A3 */  sb         $s5, 0x28($sp)
    /* F21C 80077A1C 2900A2A3 */  sb         $v0, 0x29($sp)
    /* F220 80077A20 1C00A3AF */  sw         $v1, 0x1C($sp)
    /* F224 80077A24 0002C292 */  lbu        $v0, 0x200($s6)
    /* F228 80077A28 1800A427 */  addiu      $a0, $sp, 0x18
    /* F22C 80077A2C 2A00A2A3 */  sb         $v0, 0x2A($sp)
  .L80077A30:
    /* F230 80077A30 7A65020C */  jal        vs_battle_populateDataSlot
    /* F234 80077A34 00000000 */   nop
  .L80077A38:
    /* F238 80077A38 0200A22A */  slti       $v0, $s5, 0x2
    /* F23C 80077A3C 06004014 */  bnez       $v0, .L80077A58
    /* F240 80077A40 01000224 */   addiu     $v0, $zero, 0x1
    /* F244 80077A44 6C00A88F */  lw         $t0, 0x6C($sp)
    /* F248 80077A48 00000000 */  nop
    /* F24C 80077A4C 03000331 */  andi       $v1, $t0, 0x3
    /* F250 80077A50 0F006214 */  bne        $v1, $v0, .L80077A90
    /* F254 80077A54 00000000 */   nop
  .L80077A58:
    /* F258 80077A58 2C00428E */  lw         $v0, 0x2C($s2)
    /* F25C 80077A5C 00000000 */  nop
    /* F260 80077A60 0B004010 */  beqz       $v0, .L80077A90
    /* F264 80077A64 08000224 */   addiu     $v0, $zero, 0x8
    /* F268 80077A68 1800A2A3 */  sb         $v0, 0x18($sp)
    /* F26C 80077A6C 1900B5A3 */  sb         $s5, 0x19($sp)
    /* F270 80077A70 2800428E */  lw         $v0, 0x28($s2)
    /* F274 80077A74 2800A0A3 */  sb         $zero, 0x28($sp)
    /* F278 80077A78 21105200 */  addu       $v0, $v0, $s2
    /* F27C 80077A7C 2000A2AF */  sw         $v0, 0x20($sp)
    /* F280 80077A80 25002292 */  lbu        $v0, 0x25($s1)
    /* F284 80077A84 1800A427 */  addiu      $a0, $sp, 0x18
    /* F288 80077A88 7A65020C */  jal        vs_battle_populateDataSlot
    /* F28C 80077A8C 1A00A2A7 */   sh        $v0, 0x1A($sp)
  .L80077A90:
    /* F290 80077A90 2400428E */  lw         $v0, 0x24($s2)
    /* F294 80077A94 00000000 */  nop
    /* F298 80077A98 0A004010 */  beqz       $v0, .L80077AC4
    /* F29C 80077A9C 08000224 */   addiu     $v0, $zero, 0x8
    /* F2A0 80077AA0 1800A2A3 */  sb         $v0, 0x18($sp)
    /* F2A4 80077AA4 1900B5A3 */  sb         $s5, 0x19($sp)
    /* F2A8 80077AA8 2000428E */  lw         $v0, 0x20($s2)
    /* F2AC 80077AAC 1800A427 */  addiu      $a0, $sp, 0x18
    /* F2B0 80077AB0 2800A0A3 */  sb         $zero, 0x28($sp)
    /* F2B4 80077AB4 1A00A0A7 */  sh         $zero, 0x1A($sp)
    /* F2B8 80077AB8 21105200 */  addu       $v0, $v0, $s2
    /* F2BC 80077ABC 7A65020C */  jal        vs_battle_populateDataSlot
    /* F2C0 80077AC0 2000A2AF */   sw        $v0, 0x20($sp)
  .L80077AC4:
    /* F2C4 80077AC4 6C65020C */  jal        vs_battle_getEmptyObjectDataSlot
    /* F2C8 80077AC8 00000000 */   nop
    /* F2CC 80077ACC 07004010 */  beqz       $v0, .L80077AEC
    /* F2D0 80077AD0 2120A002 */   addu      $a0, $s5, $zero
    /* F2D4 80077AD4 9F65020C */  jal        vs_battle_processObjectDataQueue
    /* F2D8 80077AD8 00000000 */   nop
    /* F2DC 80077ADC 8709010C */  jal        vs_main_gametimeUpdate
    /* F2E0 80077AE0 21200000 */   addu      $a0, $zero, $zero
    /* F2E4 80077AE4 B1DE0108 */  j          .L80077AC4
    /* F2E8 80077AE8 00000000 */   nop
  .L80077AEC:
    /* F2EC 80077AEC 2128C002 */  addu       $a1, $s6, $zero
    /* F2F0 80077AF0 2130E002 */  addu       $a2, $s7, $zero
    /* F2F4 80077AF4 2138C003 */  addu       $a3, $fp, $zero
    /* F2F8 80077AF8 0F80033C */  lui        $v1, %hi(vs_battle_actors)
    /* F2FC 80077AFC 28196324 */  addiu      $v1, $v1, %lo(vs_battle_actors)
    /* F300 80077B00 80101500 */  sll        $v0, $s5, 2
    /* F304 80077B04 21104300 */  addu       $v0, $v0, $v1
    /* F308 80077B08 000051AC */  sw         $s1, 0x0($v0)
    /* F30C 80077B0C 6C00A98F */  lw         $t1, 0x6C($sp)
    /* F310 80077B10 01000224 */  addiu      $v0, $zero, 0x1
    /* F314 80077B14 1400A2AF */  sw         $v0, 0x14($sp)
    /* F318 80077B18 C9DB010C */  jal        func_80076F24
    /* F31C 80077B1C 1000A9AF */   sw        $t1, 0x10($sp)
    /* F320 80077B20 2000228E */  lw         $v0, 0x20($s1)
    /* F324 80077B24 00000000 */  nop
    /* F328 80077B28 01004230 */  andi       $v0, $v0, 0x1
    /* F32C 80077B2C 03004010 */  beqz       $v0, .L80077B3C
    /* F330 80077B30 2120A002 */   addu      $a0, $s5, $zero
    /* F334 80077B34 D0DE0108 */  j          .L80077B40
    /* F338 80077B38 46180524 */   addiu     $a1, $zero, 0x1846
  .L80077B3C:
    /* F33C 80077B3C 46000524 */  addiu      $a1, $zero, 0x46
  .L80077B40:
    /* F340 80077B40 1F82020C */  jal        func_800A087C
    /* F344 80077B44 00000000 */   nop
    /* F348 80077B48 2120A002 */  addu       $a0, $s5, $zero
    /* F34C 80077B4C 21280000 */  addu       $a1, $zero, $zero
    /* F350 80077B50 2130A000 */  addu       $a2, $a1, $zero
    /* F354 80077B54 8180020C */  jal        func_800A0204
    /* F358 80077B58 2138A000 */   addu      $a3, $a1, $zero
    /* F35C 80077B5C 3C00228E */  lw         $v0, 0x3C($s1)
    /* F360 80077B60 2120A002 */  addu       $a0, $s5, $zero
    /* F364 80077B64 31004590 */  lbu        $a1, 0x31($v0)
    /* F368 80077B68 33004690 */  lbu        $a2, 0x33($v0)
    /* F36C 80077B6C 002B0500 */  sll        $a1, $a1, 12
    /* F370 80077B70 BF82020C */  jal        func_800A0AFC
    /* F374 80077B74 00330600 */   sll       $a2, $a2, 12
    /* F378 80077B78 1C002296 */  lhu        $v0, 0x1C($s1)
    /* F37C 80077B7C 00000000 */  nop
    /* F380 80077B80 07004230 */  andi       $v0, $v0, 0x7
    /* F384 80077B84 09004010 */  beqz       $v0, .L80077BAC
    /* F388 80077B88 0F80033C */   lui       $v1, %hi(vs_battle_actors)
    /* F38C 80077B8C 2819628C */  lw         $v0, %lo(vs_battle_actors)($v1)
    /* F390 80077B90 00000000 */  nop
    /* F394 80077B94 0000428C */  lw         $v0, 0x0($v0)
    /* F398 80077B98 00000000 */  nop
    /* F39C 80077B9C 000022AE */  sw         $v0, 0x0($s1)
    /* F3A0 80077BA0 2819628C */  lw         $v0, %lo(vs_battle_actors)($v1)
    /* F3A4 80077BA4 00000000 */  nop
    /* F3A8 80077BA8 000051AC */  sw         $s1, 0x0($v0)
  .L80077BAC:
    /* F3AC 80077BAC 23008292 */  lbu        $v0, 0x23($s4)
    /* F3B0 80077BB0 3C00238E */  lw         $v1, 0x3C($s1)
    /* F3B4 80077BB4 1E0022A2 */  sb         $v0, 0x1E($s1)
    /* F3B8 80077BB8 26008292 */  lbu        $v0, 0x26($s4)
    /* F3BC 80077BBC 00000000 */  nop
    /* F3C0 80077BC0 1F0022A2 */  sb         $v0, 0x1F($s1)
    /* F3C4 80077BC4 01008292 */  lbu        $v0, 0x1($s4)
    /* F3C8 80077BC8 290020A2 */  sb         $zero, 0x29($s1)
    /* F3CC 80077BCC 280020A2 */  sb         $zero, 0x28($s1)
    /* F3D0 80077BD0 270022A2 */  sb         $v0, 0x27($s1)
    /* F3D4 80077BD4 1A008296 */  lhu        $v0, 0x1A($s4)
    /* F3D8 80077BD8 00000000 */  nop
    /* F3DC 80077BDC 580962A4 */  sh         $v0, 0x958($v1)
    /* F3E0 80077BE0 3C00238E */  lw         $v1, 0x3C($s1)
    /* F3E4 80077BE4 20008292 */  lbu        $v0, 0x20($s4)
    /* F3E8 80077BE8 00000000 */  nop
    /* F3EC 80077BEC 5A0962A0 */  sb         $v0, 0x95A($v1)
    /* F3F0 80077BF0 3C00238E */  lw         $v1, 0x3C($s1)
    /* F3F4 80077BF4 1C008296 */  lhu        $v0, 0x1C($s4)
    /* F3F8 80077BF8 00000000 */  nop
    /* F3FC 80077BFC 5C0962A4 */  sh         $v0, 0x95C($v1)
    /* F400 80077C00 3C00238E */  lw         $v1, 0x3C($s1)
    /* F404 80077C04 21008292 */  lbu        $v0, 0x21($s4)
    /* F408 80077C08 00000000 */  nop
    /* F40C 80077C0C 5E0962A0 */  sb         $v0, 0x95E($v1)
    /* F410 80077C10 3C00238E */  lw         $v1, 0x3C($s1)
    /* F414 80077C14 1E008296 */  lhu        $v0, 0x1E($s4)
    /* F418 80077C18 00000000 */  nop
    /* F41C 80077C1C 600962A4 */  sh         $v0, 0x960($v1)
    /* F420 80077C20 3C00238E */  lw         $v1, 0x3C($s1)
    /* F424 80077C24 22008292 */  lbu        $v0, 0x22($s4)
    /* F428 80077C28 00000000 */  nop
    /* F42C 80077C2C 620962A0 */  sb         $v0, 0x962($v1)
    /* F430 80077C30 13008A8A */  lwl        $t2, 0x13($s4)
    /* F434 80077C34 10008A9A */  lwr        $t2, 0x10($s4)
    /* F438 80077C38 17008B8A */  lwl        $t3, 0x17($s4)
    /* F43C 80077C3C 14008B9A */  lwr        $t3, 0x14($s4)
    /* F440 80077C40 33002AAA */  swl        $t2, 0x33($s1)
    /* F444 80077C44 30002ABA */  swr        $t2, 0x30($s1)
    /* F448 80077C48 37002BAA */  swl        $t3, 0x37($s1)
    /* F44C 80077C4C 34002BBA */  swr        $t3, 0x34($s1)
    /* F450 80077C50 2C00C28E */  lw         $v0, 0x2C($s6)
    /* F454 80077C54 0680043C */  lui        $a0, %hi(D_80061078)
    /* F458 80077C58 380022AE */  sw         $v0, 0x38($s1)
    /* F45C 80077C5C 0680023C */  lui        $v0, %hi(D_80060064)
    /* F460 80077C60 6400438C */  lw         $v1, %lo(D_80060064)($v0)
    /* F464 80077C64 78108424 */  addiu      $a0, $a0, %lo(D_80061078)
    /* F468 80077C68 80100300 */  sll        $v0, $v1, 2
    /* F46C 80077C6C 21104300 */  addu       $v0, $v0, $v1
    /* F470 80077C70 C0100200 */  sll        $v0, $v0, 3
    /* F474 80077C74 21104300 */  addu       $v0, $v0, $v1
    /* F478 80077C78 C0100200 */  sll        $v0, $v0, 3
    /* F47C 80077C7C 21284400 */  addu       $a1, $v0, $a0
    /* F480 80077C80 0F80023C */  lui        $v0, %hi(_zoneContext)
    /* F484 80077C84 0100A490 */  lbu        $a0, 0x1($a1)
    /* F488 80077C88 8018438C */  lw         $v1, %lo(_zoneContext)($v0)
    /* F48C 80077C8C 00000000 */  nop
    /* F490 80077C90 3B008314 */  bne        $a0, $v1, .L80077D80
    /* F494 80077C94 80184224 */   addiu     $v0, $v0, %lo(_zoneContext)
    /* F498 80077C98 0200A394 */  lhu        $v1, 0x2($a1)
    /* F49C 80077C9C 3400428C */  lw         $v0, 0x34($v0)
    /* F4A0 80077CA0 00000000 */  nop
    /* F4A4 80077CA4 37006214 */  bne        $v1, $v0, .L80077D84
    /* F4A8 80077CA8 21202002 */   addu      $a0, $s1, $zero
    /* F4AC 80077CAC 01008492 */  lbu        $a0, 0x1($s4)
    /* F4B0 80077CB0 A0A7010C */  jal        func_80069E80
    /* F4B4 80077CB4 00000000 */   nop
    /* F4B8 80077CB8 21804000 */  addu       $s0, $v0, $zero
    /* F4BC 80077CBC 30000012 */  beqz       $s0, .L80077D80
    /* F4C0 80077CC0 21280000 */   addu      $a1, $zero, $zero
    /* F4C4 80077CC4 3C00238E */  lw         $v1, 0x3C($s1)
    /* F4C8 80077CC8 04000296 */  lhu        $v0, 0x4($s0)
    /* F4CC 80077CCC 00000000 */  nop
    /* F4D0 80077CD0 180062A4 */  sh         $v0, 0x18($v1)
    /* F4D4 80077CD4 3C00238E */  lw         $v1, 0x3C($s1)
    /* F4D8 80077CD8 06000296 */  lhu        $v0, 0x6($s0)
    /* F4DC 80077CDC 00000000 */  nop
    /* F4E0 80077CE0 1A0062A4 */  sh         $v0, 0x1A($v1)
    /* F4E4 80077CE4 3C00238E */  lw         $v1, 0x3C($s1)
    /* F4E8 80077CE8 08000296 */  lhu        $v0, 0x8($s0)
    /* F4EC 80077CEC 00000000 */  nop
    /* F4F0 80077CF0 1C0062A4 */  sh         $v0, 0x1C($v1)
    /* F4F4 80077CF4 3C00238E */  lw         $v1, 0x3C($s1)
    /* F4F8 80077CF8 0A000296 */  lhu        $v0, 0xA($s0)
    /* F4FC 80077CFC 00000000 */  nop
    /* F500 80077D00 1E0062A4 */  sh         $v0, 0x1E($v1)
    /* F504 80077D04 3C00238E */  lw         $v1, 0x3C($s1)
    /* F508 80077D08 0C000296 */  lhu        $v0, 0xC($s0)
    /* F50C 80077D0C 00000000 */  nop
    /* F510 80077D10 240062A4 */  sh         $v0, 0x24($v1)
    /* F514 80077D14 220062A4 */  sh         $v0, 0x22($v1)
    /* F518 80077D18 3C00238E */  lw         $v1, 0x3C($s1)
    /* F51C 80077D1C 0E000296 */  lhu        $v0, 0xE($s0)
    /* F520 80077D20 21300002 */  addu       $a2, $s0, $zero
    /* F524 80077D24 280062A4 */  sh         $v0, 0x28($v1)
    /* F528 80077D28 260062A4 */  sh         $v0, 0x26($v1)
    /* F52C 80077D2C 3C00238E */  lw         $v1, 0x3C($s1)
    /* F530 80077D30 10000296 */  lhu        $v0, 0x10($s0)
    /* F534 80077D34 2120A000 */  addu       $a0, $a1, $zero
    /* F538 80077D38 2C0062A4 */  sh         $v0, 0x2C($v1)
    /* F53C 80077D3C 2A0062A4 */  sh         $v0, 0x2A($v1)
  .L80077D40:
    /* F540 80077D40 1200C394 */  lhu        $v1, 0x12($a2)
    /* F544 80077D44 0200C624 */  addiu      $a2, $a2, 0x2
    /* F548 80077D48 3C00228E */  lw         $v0, 0x3C($s1)
    /* F54C 80077D4C 0100A524 */  addiu      $a1, $a1, 0x1
    /* F550 80077D50 21104400 */  addu       $v0, $v0, $a0
    /* F554 80077D54 980343A4 */  sh         $v1, 0x398($v0)
    /* F558 80077D58 0600A228 */  slti       $v0, $a1, 0x6
    /* F55C 80077D5C F8FF4014 */  bnez       $v0, .L80077D40
    /* F560 80077D60 DC008424 */   addiu     $a0, $a0, 0xDC
    /* F564 80077D64 2000048E */  lw         $a0, 0x20($s0)
    /* F568 80077D68 3C00258E */  lw         $a1, 0x3C($s1)
    /* F56C 80077D6C EA1B020C */  jal        func_80086FA8
    /* F570 80077D70 00000000 */   nop
    /* F574 80077D74 02000586 */  lh         $a1, 0x2($s0)
    /* F578 80077D78 62DF0108 */  j          .L80077D88
    /* F57C 80077D7C 21202002 */   addu      $a0, $s1, $zero
  .L80077D80:
    /* F580 80077D80 21202002 */  addu       $a0, $s1, $zero
  .L80077D84:
    /* F584 80077D84 FFFF0524 */  addiu      $a1, $zero, -0x1
  .L80077D88:
    /* F588 80077D88 5E98030C */  jal        func_800E6178
    /* F58C 80077D8C 00000000 */   nop
    /* F590 80077D90 21284000 */  addu       $a1, $v0, $zero
    /* F594 80077D94 0400A014 */  bnez       $a1, .L80077DA8
    /* F598 80077D98 2120A002 */   addu      $a0, $s5, $zero
    /* F59C 80077D9C 26008592 */  lbu        $a1, 0x26($s4)
    /* F5A0 80077DA0 6BDF0108 */  j          .L80077DAC
    /* F5A4 80077DA4 00000000 */   nop
  .L80077DA8:
    /* F5A8 80077DA8 21280000 */  addu       $a1, $zero, $zero
  .L80077DAC:
    /* F5AC 80077DAC CF77020C */  jal        func_8009DF3C
    /* F5B0 80077DB0 00000000 */   nop
    /* F5B4 80077DB4 70DF0108 */  j          .L80077DC0
    /* F5B8 80077DB8 21102002 */   addu      $v0, $s1, $zero
  .L80077DBC:
    /* F5BC 80077DBC 21100000 */  addu       $v0, $zero, $zero
  .L80077DC0:
    /* F5C0 80077DC0 5C00BF8F */  lw         $ra, 0x5C($sp)
    /* F5C4 80077DC4 5800BE8F */  lw         $fp, 0x58($sp)
    /* F5C8 80077DC8 5400B78F */  lw         $s7, 0x54($sp)
    /* F5CC 80077DCC 5000B68F */  lw         $s6, 0x50($sp)
    /* F5D0 80077DD0 4C00B58F */  lw         $s5, 0x4C($sp)
    /* F5D4 80077DD4 4800B48F */  lw         $s4, 0x48($sp)
    /* F5D8 80077DD8 4400B38F */  lw         $s3, 0x44($sp)
    /* F5DC 80077DDC 4000B28F */  lw         $s2, 0x40($sp)
    /* F5E0 80077DE0 3C00B18F */  lw         $s1, 0x3C($sp)
    /* F5E4 80077DE4 3800B08F */  lw         $s0, 0x38($sp)
    /* F5E8 80077DE8 0800E003 */  jr         $ra
    /* F5EC 80077DEC 6000BD27 */   addiu     $sp, $sp, 0x60
endlabel func_800775C0
