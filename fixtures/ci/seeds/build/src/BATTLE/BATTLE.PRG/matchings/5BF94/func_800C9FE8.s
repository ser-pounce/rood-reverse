nonmatching func_800C9FE8, 0x2F4

glabel func_800C9FE8
    /* 617E8 800C9FE8 0F80023C */  lui        $v0, %hi(D_800EBC78)
    /* 617EC 800C9FEC 78BC4290 */  lbu        $v0, %lo(D_800EBC78)($v0)
    /* 617F0 800C9FF0 C8FFBD27 */  addiu      $sp, $sp, -0x38
    /* 617F4 800C9FF4 3000BFAF */  sw         $ra, 0x30($sp)
    /* 617F8 800C9FF8 2C00B7AF */  sw         $s7, 0x2C($sp)
    /* 617FC 800C9FFC 2800B6AF */  sw         $s6, 0x28($sp)
    /* 61800 800CA000 2400B5AF */  sw         $s5, 0x24($sp)
    /* 61804 800CA004 2000B4AF */  sw         $s4, 0x20($sp)
    /* 61808 800CA008 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 6180C 800CA00C 1800B2AF */  sw         $s2, 0x18($sp)
    /* 61810 800CA010 1400B1AF */  sw         $s1, 0x14($sp)
    /* 61814 800CA014 08004010 */  beqz       $v0, .L800CA038
    /* 61818 800CA018 1000B0AF */   sw        $s0, 0x10($sp)
    /* 6181C 800CA01C 0F80033C */  lui        $v1, %hi(D_800EBCE8)
    /* 61820 800CA020 E8BC6290 */  lbu        $v0, %lo(D_800EBCE8)($v1)
    /* 61824 800CA024 00000000 */  nop
    /* 61828 800CA028 0B004010 */  beqz       $v0, .L800CA058
    /* 6182C 800CA02C FFFF4224 */   addiu     $v0, $v0, -0x1
    /* 61830 800CA030 16280308 */  j          .L800CA058
    /* 61834 800CA034 E8BC62A0 */   sb        $v0, %lo(D_800EBCE8)($v1)
  .L800CA038:
    /* 61838 800CA038 0F80043C */  lui        $a0, %hi(D_800EBCE8)
    /* 6183C 800CA03C 0F80023C */  lui        $v0, %hi(vs_battle_animationIndices)
    /* 61840 800CA040 E8BC8390 */  lbu        $v1, %lo(D_800EBCE8)($a0)
    /* 61844 800CA044 7CBC4224 */  addiu      $v0, $v0, %lo(vs_battle_animationIndices)
    /* 61848 800CA048 21186200 */  addu       $v1, $v1, $v0
    /* 6184C 800CA04C 00006290 */  lbu        $v0, 0x0($v1)
    /* 61850 800CA050 00000000 */  nop
    /* 61854 800CA054 E8BC82A0 */  sb         $v0, %lo(D_800EBCE8)($a0)
  .L800CA058:
    /* 61858 800CA058 0F80043C */  lui        $a0, %hi(D_800EBCE8)
    /* 6185C 800CA05C E8BC8390 */  lbu        $v1, %lo(D_800EBCE8)($a0)
    /* 61860 800CA060 0A000224 */  addiu      $v0, $zero, 0xA
    /* 61864 800CA064 90006210 */  beq        $v1, $v0, .L800CA2A8
    /* 61868 800CA068 21900000 */   addu      $s2, $zero, $zero
    /* 6186C 800CA06C 0F80023C */  lui        $v0, %hi(D_800EBC98)
    /* 61870 800CA070 98BC5624 */  addiu      $s6, $v0, %lo(D_800EBC98)
    /* 61874 800CA074 0F80023C */  lui        $v0, %hi(D_800EBCA0)
    /* 61878 800CA078 A0BC5524 */  addiu      $s5, $v0, %lo(D_800EBCA0)
    /* 6187C 800CA07C 801F023C */  lui        $v0, %hi(D_1F800000)
    /* 61880 800CA080 00005724 */  addiu      $s7, $v0, %lo(D_1F800000)
    /* 61884 800CA084 0F80023C */  lui        $v0, %hi(vs_battle_rowAnimationSteps)
    /* 61888 800CA088 C8BB4224 */  addiu      $v0, $v0, %lo(vs_battle_rowAnimationSteps)
    /* 6188C 800CA08C 21186200 */  addu       $v1, $v1, $v0
    /* 61890 800CA090 0F80023C */  lui        $v0, %hi(D_800EBCA8)
    /* 61894 800CA094 00006390 */  lbu        $v1, 0x0($v1)
    /* 61898 800CA098 A8BC5424 */  addiu      $s4, $v0, %lo(D_800EBCA8)
    /* 6189C 800CA09C 23980300 */  negu       $s3, $v1
  .L800CA0A0:
    /* 618A0 800CA0A0 04005026 */  addiu      $s0, $s2, 0x4
    /* 618A4 800CA0A4 AE27030C */  jal        func_800C9EB8
    /* 618A8 800CA0A8 21200002 */   addu      $a0, $s0, $zero
    /* 618AC 800CA0AC 21884000 */  addu       $s1, $v0, $zero
    /* 618B0 800CA0B0 22002012 */  beqz       $s1, .L800CA13C
    /* 618B4 800CA0B4 21105602 */   addu      $v0, $s2, $s6
    /* 618B8 800CA0B8 21282002 */  addu       $a1, $s1, $zero
    /* 618BC 800CA0BC 00004390 */  lbu        $v1, 0x0($v0)
    /* 618C0 800CA0C0 21101602 */  addu       $v0, $s0, $s6
    /* 618C4 800CA0C4 00004490 */  lbu        $a0, 0x0($v0)
    /* 618C8 800CA0C8 21186302 */  addu       $v1, $s3, $v1
    /* 618CC 800CA0CC FFFF6330 */  andi       $v1, $v1, 0xFFFF
    /* 618D0 800CA0D0 00240400 */  sll        $a0, $a0, 16
    /* 618D4 800CA0D4 E627030C */  jal        func_800C9F98
    /* 618D8 800CA0D8 25206400 */   or        $a0, $v1, $a0
    /* 618DC 800CA0DC 21202002 */  addu       $a0, $s1, $zero
    /* 618E0 800CA0E0 21105502 */  addu       $v0, $s2, $s5
    /* 618E4 800CA0E4 00004390 */  lbu        $v1, 0x0($v0)
    /* 618E8 800CA0E8 21101502 */  addu       $v0, $s0, $s5
    /* 618EC 800CA0EC 0000868E */  lw         $a2, 0x0($s4)
    /* 618F0 800CA0F0 0800E78E */  lw         $a3, 0x8($s7)
    /* 618F4 800CA0F4 00004590 */  lbu        $a1, 0x0($v0)
    /* 618F8 800CA0F8 21186302 */  addu       $v1, $s3, $v1
    /* 618FC 800CA0FC FFFF6330 */  andi       $v1, $v1, 0xFFFF
    /* 61900 800CA100 002C0500 */  sll        $a1, $a1, 16
    /* 61904 800CA104 8900030C */  jal        func_800C0224
    /* 61908 800CA108 25286500 */   or        $a1, $v1, $a1
    /* 6190C 800CA10C 21204000 */  addu       $a0, $v0, $zero
    /* 61910 800CA110 00E1023C */  lui        $v0, (0xE1000017 >> 16)
    /* 61914 800CA114 17004234 */  ori        $v0, $v0, (0xE1000017 & 0xFFFF)
    /* 61918 800CA118 0F80033C */  lui        $v1, %hi(D_800EBCB8)
    /* 6191C 800CA11C B8BC6324 */  addiu      $v1, $v1, %lo(D_800EBCB8)
    /* 61920 800CA120 040082AC */  sw         $v0, 0x4($a0)
    /* 61924 800CA124 40101200 */  sll        $v0, $s2, 1
    /* 61928 800CA128 21104300 */  addu       $v0, $v0, $v1
    /* 6192C 800CA12C 00004294 */  lhu        $v0, 0x0($v0)
    /* 61930 800CA130 3D37033C */  lui        $v1, (0x373D0000 >> 16)
    /* 61934 800CA134 25104300 */  or         $v0, $v0, $v1
    /* 61938 800CA138 100082AC */  sw         $v0, 0x10($a0)
  .L800CA13C:
    /* 6193C 800CA13C 01005226 */  addiu      $s2, $s2, 0x1
    /* 61940 800CA140 0400422A */  slti       $v0, $s2, 0x4
    /* 61944 800CA144 D6FF4014 */  bnez       $v0, .L800CA0A0
    /* 61948 800CA148 04009426 */   addiu     $s4, $s4, 0x4
    /* 6194C 800CA14C 80010424 */  addiu      $a0, $zero, 0x180
    /* 61950 800CA150 48006526 */  addiu      $a1, $s3, 0x48
    /* 61954 800CA154 FFFFA530 */  andi       $a1, $a1, 0xFFFF
    /* 61958 800CA158 6600023C */  lui        $v0, (0x660000 >> 16)
    /* 6195C 800CA15C 2528A200 */  or         $a1, $a1, $v0
    /* 61960 800CA160 1E00063C */  lui        $a2, (0x1E001E >> 16)
    /* 61964 800CA164 1E00C634 */  ori        $a2, $a2, (0x1E001E & 0xFFFF)
    /* 61968 800CA168 21900000 */  addu       $s2, $zero, $zero
    /* 6196C 800CA16C 801F023C */  lui        $v0, %hi(D_1F800000)
    /* 61970 800CA170 00004224 */  addiu      $v0, $v0, %lo(D_1F800000)
    /* 61974 800CA174 0800478C */  lw         $a3, 0x8($v0)
    /* 61978 800CA178 8900030C */  jal        func_800C0224
    /* 6197C 800CA17C 21B84000 */   addu      $s7, $v0, $zero
    /* 61980 800CA180 FB37043C */  lui        $a0, (0x37FBA0B8 >> 16)
    /* 61984 800CA184 B8A08434 */  ori        $a0, $a0, (0x37FBA0B8 & 0xFFFF)
    /* 61988 800CA188 A0000324 */  addiu      $v1, $zero, 0xA0
    /* 6198C 800CA18C 23987300 */  subu       $s3, $v1, $s3
    /* 61990 800CA190 0F80033C */  lui        $v1, %hi(D_800EBCC0)
    /* 61994 800CA194 C0BC7624 */  addiu      $s6, $v1, %lo(D_800EBCC0)
    /* 61998 800CA198 0F80033C */  lui        $v1, %hi(D_800EBCC8)
    /* 6199C 800CA19C C8BC7524 */  addiu      $s5, $v1, %lo(D_800EBCC8)
    /* 619A0 800CA1A0 0F80033C */  lui        $v1, %hi(D_800EBCD0)
    /* 619A4 800CA1A4 D0BC7424 */  addiu      $s4, $v1, %lo(D_800EBCD0)
    /* 619A8 800CA1A8 100044AC */  sw         $a0, 0x10($v0)
  .L800CA1AC:
    /* 619AC 800CA1AC AE27030C */  jal        func_800C9EB8
    /* 619B0 800CA1B0 21204002 */   addu      $a0, $s2, $zero
    /* 619B4 800CA1B4 21884000 */  addu       $s1, $v0, $zero
    /* 619B8 800CA1B8 24002012 */  beqz       $s1, .L800CA24C
    /* 619BC 800CA1BC 21105602 */   addu      $v0, $s2, $s6
    /* 619C0 800CA1C0 21282002 */  addu       $a1, $s1, $zero
    /* 619C4 800CA1C4 04005026 */  addiu      $s0, $s2, 0x4
    /* 619C8 800CA1C8 00004390 */  lbu        $v1, 0x0($v0)
    /* 619CC 800CA1CC 21101602 */  addu       $v0, $s0, $s6
    /* 619D0 800CA1D0 00004490 */  lbu        $a0, 0x0($v0)
    /* 619D4 800CA1D4 21186302 */  addu       $v1, $s3, $v1
    /* 619D8 800CA1D8 FFFF6330 */  andi       $v1, $v1, 0xFFFF
    /* 619DC 800CA1DC 00240400 */  sll        $a0, $a0, 16
    /* 619E0 800CA1E0 E627030C */  jal        func_800C9F98
    /* 619E4 800CA1E4 25206400 */   or        $a0, $v1, $a0
    /* 619E8 800CA1E8 21202002 */  addu       $a0, $s1, $zero
    /* 619EC 800CA1EC 21105502 */  addu       $v0, $s2, $s5
    /* 619F0 800CA1F0 21801502 */  addu       $s0, $s0, $s5
    /* 619F4 800CA1F4 0000868E */  lw         $a2, 0x0($s4)
    /* 619F8 800CA1F8 00004590 */  lbu        $a1, 0x0($v0)
    /* 619FC 800CA1FC 0800E78E */  lw         $a3, 0x8($s7)
    /* 61A00 800CA200 00000292 */  lbu        $v0, 0x0($s0)
    /* 61A04 800CA204 21286502 */  addu       $a1, $s3, $a1
    /* 61A08 800CA208 FEFFA524 */  addiu      $a1, $a1, -0x2
    /* 61A0C 800CA20C FFFFA530 */  andi       $a1, $a1, 0xFFFF
    /* 61A10 800CA210 00140200 */  sll        $v0, $v0, 16
    /* 61A14 800CA214 8900030C */  jal        func_800C0224
    /* 61A18 800CA218 2528A200 */   or        $a1, $a1, $v0
    /* 61A1C 800CA21C 21204000 */  addu       $a0, $v0, $zero
    /* 61A20 800CA220 00E1023C */  lui        $v0, (0xE1000017 >> 16)
    /* 61A24 800CA224 17004234 */  ori        $v0, $v0, (0xE1000017 & 0xFFFF)
    /* 61A28 800CA228 0F80033C */  lui        $v1, %hi(D_800EBCE0)
    /* 61A2C 800CA22C E0BC6324 */  addiu      $v1, $v1, %lo(D_800EBCE0)
    /* 61A30 800CA230 040082AC */  sw         $v0, 0x4($a0)
    /* 61A34 800CA234 40101200 */  sll        $v0, $s2, 1
    /* 61A38 800CA238 21104300 */  addu       $v0, $v0, $v1
    /* 61A3C 800CA23C 00004294 */  lhu        $v0, 0x0($v0)
    /* 61A40 800CA240 3D37033C */  lui        $v1, (0x373D0000 >> 16)
    /* 61A44 800CA244 25104300 */  or         $v0, $v0, $v1
    /* 61A48 800CA248 100082AC */  sw         $v0, 0x10($a0)
  .L800CA24C:
    /* 61A4C 800CA24C 80000424 */  addiu      $a0, $zero, 0x80
    /* 61A50 800CA250 1000063C */  lui        $a2, (0x100010 >> 16)
    /* 61A54 800CA254 1000C634 */  ori        $a2, $a2, (0x100010 & 0xFFFF)
    /* 61A58 800CA258 04009426 */  addiu      $s4, $s4, 0x4
    /* 61A5C 800CA25C 03001024 */  addiu      $s0, $zero, 0x3
    /* 61A60 800CA260 23801202 */  subu       $s0, $s0, $s2
    /* 61A64 800CA264 01005226 */  addiu      $s2, $s2, 0x1
    /* 61A68 800CA268 0F80033C */  lui        $v1, %hi(D_800EBC88)
    /* 61A6C 800CA26C 88BC6324 */  addiu      $v1, $v1, %lo(D_800EBC88)
    /* 61A70 800CA270 80101000 */  sll        $v0, $s0, 2
    /* 61A74 800CA274 21104300 */  addu       $v0, $v0, $v1
    /* 61A78 800CA278 0000458C */  lw         $a1, 0x0($v0)
    /* 61A7C 800CA27C 0800E78E */  lw         $a3, 0x8($s7)
    /* 61A80 800CA280 8900030C */  jal        func_800C0224
    /* 61A84 800CA284 21286502 */   addu      $a1, $s3, $a1
    /* 61A88 800CA288 FB37033C */  lui        $v1, (0x37FB8000 >> 16)
    /* 61A8C 800CA28C 00806334 */  ori        $v1, $v1, (0x37FB8000 & 0xFFFF)
    /* 61A90 800CA290 00811000 */  sll        $s0, $s0, 4
    /* 61A94 800CA294 25800302 */  or         $s0, $s0, $v1
    /* 61A98 800CA298 100050AC */  sw         $s0, 0x10($v0)
    /* 61A9C 800CA29C 0400422A */  slti       $v0, $s2, 0x4
    /* 61AA0 800CA2A0 C2FF4014 */  bnez       $v0, .L800CA1AC
    /* 61AA4 800CA2A4 00000000 */   nop
  .L800CA2A8:
    /* 61AA8 800CA2A8 3000BF8F */  lw         $ra, 0x30($sp)
    /* 61AAC 800CA2AC 2C00B78F */  lw         $s7, 0x2C($sp)
    /* 61AB0 800CA2B0 2800B68F */  lw         $s6, 0x28($sp)
    /* 61AB4 800CA2B4 2400B58F */  lw         $s5, 0x24($sp)
    /* 61AB8 800CA2B8 2000B48F */  lw         $s4, 0x20($sp)
    /* 61ABC 800CA2BC 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 61AC0 800CA2C0 1800B28F */  lw         $s2, 0x18($sp)
    /* 61AC4 800CA2C4 1400B18F */  lw         $s1, 0x14($sp)
    /* 61AC8 800CA2C8 1000B08F */  lw         $s0, 0x10($sp)
    /* 61ACC 800CA2CC 0F80023C */  lui        $v0, %hi(D_800EBC78)
    /* 61AD0 800CA2D0 78BC40A0 */  sb         $zero, %lo(D_800EBC78)($v0)
    /* 61AD4 800CA2D4 0800E003 */  jr         $ra
    /* 61AD8 800CA2D8 3800BD27 */   addiu     $sp, $sp, 0x38
endlabel func_800C9FE8
