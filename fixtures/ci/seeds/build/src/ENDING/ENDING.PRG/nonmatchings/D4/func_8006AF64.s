nonmatching func_8006AF64, 0x3C0

glabel func_8006AF64
    /* 2764 8006AF64 0E80043C */  lui        $a0, %hi(D_800DB72C)
    /* 2768 8006AF68 2CB78390 */  lbu        $v1, %lo(D_800DB72C)($a0)
    /* 276C 8006AF6C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 2770 8006AF70 1000BFAF */  sw         $ra, 0x10($sp)
    /* 2774 8006AF74 E7006010 */  beqz       $v1, .L8006B314
    /* 2778 8006AF78 21100000 */   addu      $v0, $zero, $zero
    /* 277C 8006AF7C 01000224 */  addiu      $v0, $zero, 0x1
    /* 2780 8006AF80 0A006214 */  bne        $v1, $v0, .L8006AFAC
    /* 2784 8006AF84 02000224 */   addiu     $v0, $zero, 0x2
    /* 2788 8006AF88 2CB782A0 */  sb         $v0, %lo(D_800DB72C)($a0)
    /* 278C 8006AF8C 0E80023C */  lui        $v0, %hi(D_800DC1A0)
    /* 2790 8006AF90 A0C1438C */  lw         $v1, %lo(D_800DC1A0)($v0)
    /* 2794 8006AF94 0E80023C */  lui        $v0, %hi(D_800DBB74)
    /* 2798 8006AF98 74BB43AC */  sw         $v1, %lo(D_800DBB74)($v0)
    /* 279C 8006AF9C 0E80023C */  lui        $v0, %hi(D_800DC1A4)
    /* 27A0 8006AFA0 A4C1438C */  lw         $v1, %lo(D_800DC1A4)($v0)
    /* 27A4 8006AFA4 0E80023C */  lui        $v0, %hi(D_800DBB78)
    /* 27A8 8006AFA8 78BB43AC */  sw         $v1, %lo(D_800DBB78)($v0)
  .L8006AFAC:
    /* 27AC 8006AFAC B17D000C */  jal        VSync
    /* 27B0 8006AFB0 01000424 */   addiu     $a0, $zero, 0x1
    /* 27B4 8006AFB4 0E80033C */  lui        $v1, %hi(D_800DC19A)
    /* 27B8 8006AFB8 9AC16384 */  lh         $v1, %lo(D_800DC19A)($v1)
    /* 27BC 8006AFBC 00000000 */  nop
    /* 27C0 8006AFC0 23104300 */  subu       $v0, $v0, $v1
    /* 27C4 8006AFC4 C9004228 */  slti       $v0, $v0, 0xC9
    /* 27C8 8006AFC8 03004014 */  bnez       $v0, .L8006AFD8
    /* 27CC 8006AFCC 0E80073C */   lui       $a3, %hi(D_800DBB74)
    /* 27D0 8006AFD0 C5AC0108 */  j          .L8006B314
    /* 27D4 8006AFD4 21100000 */   addu      $v0, $zero, $zero
  .L8006AFD8:
    /* 27D8 8006AFD8 74BBE58C */  lw         $a1, %lo(D_800DBB74)($a3)
    /* 27DC 8006AFDC 00000000 */  nop
    /* 27E0 8006AFE0 0000A390 */  lbu        $v1, 0x0($a1)
    /* 27E4 8006AFE4 00000000 */  nop
    /* 27E8 8006AFE8 80006230 */  andi       $v0, $v1, 0x80
    /* 27EC 8006AFEC 71004014 */  bnez       $v0, .L8006B1B4
    /* 27F0 8006AFF0 02110300 */   srl       $v0, $v1, 4
    /* 27F4 8006AFF4 FF006330 */  andi       $v1, $v1, 0xFF
    /* 27F8 8006AFF8 7F000224 */  addiu      $v0, $zero, 0x7F
    /* 27FC 8006AFFC 04006214 */  bne        $v1, $v0, .L8006B010
    /* 2800 8006B000 0E80023C */   lui       $v0, %hi(D_800DB72C)
    /* 2804 8006B004 2CB740A0 */  sb         $zero, %lo(D_800DB72C)($v0)
    /* 2808 8006B008 C5AC0108 */  j          .L8006B314
    /* 280C 8006B00C 01000224 */   addiu     $v0, $zero, 0x1
  .L8006B010:
    /* 2810 8006B010 7D000224 */  addiu      $v0, $zero, 0x7D
    /* 2814 8006B014 22006214 */  bne        $v1, $v0, .L8006B0A0
    /* 2818 8006B018 7E000224 */   addiu     $v0, $zero, 0x7E
    /* 281C 8006B01C 21300000 */  addu       $a2, $zero, $zero
    /* 2820 8006B020 0100A224 */  addiu      $v0, $a1, 0x1
    /* 2824 8006B024 74BBE2AC */  sw         $v0, %lo(D_800DBB74)($a3)
    /* 2828 8006B028 0200A224 */  addiu      $v0, $a1, 0x2
    /* 282C 8006B02C 0100A390 */  lbu        $v1, 0x1($a1)
    /* 2830 8006B030 0E80083C */  lui        $t0, %hi(D_800DBB7E)
    /* 2834 8006B034 74BBE2AC */  sw         $v0, %lo(D_800DBB74)($a3)
    /* 2838 8006B038 7EBB03A5 */  sh         $v1, %lo(D_800DBB7E)($t0)
    /* 283C 8006B03C 0200A390 */  lbu        $v1, 0x2($a1)
    /* 2840 8006B040 0300A224 */  addiu      $v0, $a1, 0x3
    /* 2844 8006B044 74BBE2AC */  sw         $v0, %lo(D_800DBB74)($a3)
    /* 2848 8006B048 7EBB0295 */  lhu        $v0, %lo(D_800DBB7E)($t0)
    /* 284C 8006B04C 0E80043C */  lui        $a0, %hi(D_800DBB7C)
    /* 2850 8006B050 00004228 */  slti       $v0, $v0, 0x0
    /* 2854 8006B054 D5FF4014 */  bnez       $v0, .L8006AFAC
    /* 2858 8006B058 7CBB83A0 */   sb        $v1, %lo(D_800DBB7C)($a0)
    /* 285C 8006B05C 0E80053C */  lui        $a1, %hi(D_800DBB78)
    /* 2860 8006B060 21388000 */  addu       $a3, $a0, $zero
    /* 2864 8006B064 0100C324 */  addiu      $v1, $a2, 0x1
  .L8006B068:
    /* 2868 8006B068 21306000 */  addu       $a2, $v1, $zero
    /* 286C 8006B06C 78BBA28C */  lw         $v0, %lo(D_800DBB78)($a1)
    /* 2870 8006B070 7CBBE490 */  lbu        $a0, %lo(D_800DBB7C)($a3)
    /* 2874 8006B074 001C0300 */  sll        $v1, $v1, 16
    /* 2878 8006B078 000044A0 */  sb         $a0, 0x0($v0)
    /* 287C 8006B07C 01004224 */  addiu      $v0, $v0, 0x1
    /* 2880 8006B080 78BBA2AC */  sw         $v0, %lo(D_800DBB78)($a1)
    /* 2884 8006B084 7EBB0295 */  lhu        $v0, %lo(D_800DBB7E)($t0)
    /* 2888 8006B088 031C0300 */  sra        $v1, $v1, 16
    /* 288C 8006B08C 2A104300 */  slt        $v0, $v0, $v1
    /* 2890 8006B090 F5FF4010 */  beqz       $v0, .L8006B068
    /* 2894 8006B094 0100C324 */   addiu     $v1, $a2, 0x1
    /* 2898 8006B098 EBAB0108 */  j          .L8006AFAC
    /* 289C 8006B09C 00000000 */   nop
  .L8006B0A0:
    /* 28A0 8006B0A0 2A006214 */  bne        $v1, $v0, .L8006B14C
    /* 28A4 8006B0A4 21300000 */   addu      $a2, $zero, $zero
    /* 28A8 8006B0A8 0100A224 */  addiu      $v0, $a1, 0x1
    /* 28AC 8006B0AC 74BBE2AC */  sw         $v0, %lo(D_800DBB74)($a3)
    /* 28B0 8006B0B0 0200A224 */  addiu      $v0, $a1, 0x2
    /* 28B4 8006B0B4 0100A390 */  lbu        $v1, 0x1($a1)
    /* 28B8 8006B0B8 0E80093C */  lui        $t1, %hi(D_800DBB7E)
    /* 28BC 8006B0BC 74BBE2AC */  sw         $v0, %lo(D_800DBB74)($a3)
    /* 28C0 8006B0C0 0300A224 */  addiu      $v0, $a1, 0x3
    /* 28C4 8006B0C4 7EBB23A5 */  sh         $v1, %lo(D_800DBB7E)($t1)
    /* 28C8 8006B0C8 0200A390 */  lbu        $v1, 0x2($a1)
    /* 28CC 8006B0CC 0E80083C */  lui        $t0, %hi(D_800DBB7C)
    /* 28D0 8006B0D0 74BBE2AC */  sw         $v0, %lo(D_800DBB74)($a3)
    /* 28D4 8006B0D4 7CBB03A1 */  sb         $v1, %lo(D_800DBB7C)($t0)
    /* 28D8 8006B0D8 0300A390 */  lbu        $v1, 0x3($a1)
    /* 28DC 8006B0DC 0400A224 */  addiu      $v0, $a1, 0x4
    /* 28E0 8006B0E0 74BBE2AC */  sw         $v0, %lo(D_800DBB74)($a3)
    /* 28E4 8006B0E4 7EBB2295 */  lhu        $v0, %lo(D_800DBB7E)($t1)
    /* 28E8 8006B0E8 0E80043C */  lui        $a0, %hi(D_800DBB7C + 0x1)
    /* 28EC 8006B0EC 00004228 */  slti       $v0, $v0, 0x0
    /* 28F0 8006B0F0 AEFF4014 */  bnez       $v0, .L8006AFAC
    /* 28F4 8006B0F4 7DBB83A0 */   sb        $v1, %lo(D_800DBB7C + 0x1)($a0)
    /* 28F8 8006B0F8 0E80053C */  lui        $a1, %hi(D_800DBB78)
    /* 28FC 8006B0FC 21388000 */  addu       $a3, $a0, $zero
    /* 2900 8006B100 0100C324 */  addiu      $v1, $a2, 0x1
  .L8006B104:
    /* 2904 8006B104 21306000 */  addu       $a2, $v1, $zero
    /* 2908 8006B108 78BBA28C */  lw         $v0, %lo(D_800DBB78)($a1)
    /* 290C 8006B10C 7CBB0491 */  lbu        $a0, %lo(D_800DBB7C)($t0)
    /* 2910 8006B110 001C0300 */  sll        $v1, $v1, 16
    /* 2914 8006B114 000044A0 */  sb         $a0, 0x0($v0)
    /* 2918 8006B118 7DBBE490 */  lbu        $a0, %lo(D_800DBB7C + 0x1)($a3)
    /* 291C 8006B11C 01004224 */  addiu      $v0, $v0, 0x1
    /* 2920 8006B120 78BBA2AC */  sw         $v0, %lo(D_800DBB78)($a1)
    /* 2924 8006B124 000044A0 */  sb         $a0, 0x0($v0)
    /* 2928 8006B128 01004224 */  addiu      $v0, $v0, 0x1
    /* 292C 8006B12C 78BBA2AC */  sw         $v0, %lo(D_800DBB78)($a1)
    /* 2930 8006B130 7EBB2295 */  lhu        $v0, %lo(D_800DBB7E)($t1)
    /* 2934 8006B134 031C0300 */  sra        $v1, $v1, 16
    /* 2938 8006B138 2A104300 */  slt        $v0, $v0, $v1
    /* 293C 8006B13C F1FF4010 */  beqz       $v0, .L8006B104
    /* 2940 8006B140 0100C324 */   addiu     $v1, $a2, 0x1
    /* 2944 8006B144 EBAB0108 */  j          .L8006AFAC
    /* 2948 8006B148 00000000 */   nop
  .L8006B14C:
    /* 294C 8006B14C 0000A290 */  lbu        $v0, 0x0($a1)
    /* 2950 8006B150 0E80093C */  lui        $t1, %hi(D_800DBB7E)
    /* 2954 8006B154 7EBB22A5 */  sh         $v0, %lo(D_800DBB7E)($t1)
    /* 2958 8006B158 FFFF4330 */  andi       $v1, $v0, 0xFFFF
    /* 295C 8006B15C 0100A224 */  addiu      $v0, $a1, 0x1
    /* 2960 8006B160 00006328 */  slti       $v1, $v1, 0x0
    /* 2964 8006B164 91FF6014 */  bnez       $v1, .L8006AFAC
    /* 2968 8006B168 74BBE2AC */   sw        $v0, %lo(D_800DBB74)($a3)
    /* 296C 8006B16C 0E80083C */  lui        $t0, %hi(D_800DBB78)
  .L8006B170:
    /* 2970 8006B170 0100C424 */  addiu      $a0, $a2, 0x1
    /* 2974 8006B174 21308000 */  addu       $a2, $a0, $zero
    /* 2978 8006B178 00240400 */  sll        $a0, $a0, 16
    /* 297C 8006B17C 03240400 */  sra        $a0, $a0, 16
    /* 2980 8006B180 74BBE28C */  lw         $v0, %lo(D_800DBB74)($a3)
    /* 2984 8006B184 78BB038D */  lw         $v1, %lo(D_800DBB78)($t0)
    /* 2988 8006B188 00004590 */  lbu        $a1, 0x0($v0)
    /* 298C 8006B18C 01004224 */  addiu      $v0, $v0, 0x1
    /* 2990 8006B190 000065A0 */  sb         $a1, 0x0($v1)
    /* 2994 8006B194 74BBE2AC */  sw         $v0, %lo(D_800DBB74)($a3)
    /* 2998 8006B198 7EBB2295 */  lhu        $v0, %lo(D_800DBB7E)($t1)
    /* 299C 8006B19C 01006324 */  addiu      $v1, $v1, 0x1
    /* 29A0 8006B1A0 2A104400 */  slt        $v0, $v0, $a0
    /* 29A4 8006B1A4 F2FF4010 */  beqz       $v0, .L8006B170
    /* 29A8 8006B1A8 78BB03AD */   sw        $v1, %lo(D_800DBB78)($t0)
    /* 29AC 8006B1AC EBAB0108 */  j          .L8006AFAC
    /* 29B0 8006B1B0 00000000 */   nop
  .L8006B1B4:
    /* 29B4 8006B1B4 07004230 */  andi       $v0, $v0, 0x7
    /* 29B8 8006B1B8 21300000 */  addu       $a2, $zero, $zero
    /* 29BC 8006B1BC 0E80093C */  lui        $t1, %hi(D_800DBB7E)
    /* 29C0 8006B1C0 03004224 */  addiu      $v0, $v0, 0x3
    /* 29C4 8006B1C4 7EBB22A5 */  sh         $v0, %lo(D_800DBB7E)($t1)
    /* 29C8 8006B1C8 0000A390 */  lbu        $v1, 0x0($a1)
    /* 29CC 8006B1CC 0100A490 */  lbu        $a0, 0x1($a1)
    /* 29D0 8006B1D0 0200A224 */  addiu      $v0, $a1, 0x2
    /* 29D4 8006B1D4 74BBE2AC */  sw         $v0, %lo(D_800DBB74)($a3)
    /* 29D8 8006B1D8 0E80023C */  lui        $v0, %hi(D_800DBB80)
    /* 29DC 8006B1DC 0E80053C */  lui        $a1, %hi(D_800DBB78)
    /* 29E0 8006B1E0 0F006330 */  andi       $v1, $v1, 0xF
    /* 29E4 8006B1E4 001A0300 */  sll        $v1, $v1, 8
    /* 29E8 8006B1E8 21208300 */  addu       $a0, $a0, $v1
    /* 29EC 8006B1EC 80BB44A4 */  sh         $a0, %lo(D_800DBB80)($v0)
    /* 29F0 8006B1F0 FFFF8330 */  andi       $v1, $a0, 0xFFFF
    /* 29F4 8006B1F4 78BBA28C */  lw         $v0, %lo(D_800DBB78)($a1)
    /* 29F8 8006B1F8 0E80043C */  lui        $a0, %hi(D_800DBB70)
    /* 29FC 8006B1FC 23104300 */  subu       $v0, $v0, $v1
    /* 2A00 8006B200 7EBB2395 */  lhu        $v1, %lo(D_800DBB7E)($t1)
    /* 2A04 8006B204 FFFF4224 */  addiu      $v0, $v0, -0x1
    /* 2A08 8006B208 12006010 */  beqz       $v1, .L8006B254
    /* 2A0C 8006B20C 70BB82AC */   sw        $v0, %lo(D_800DBB70)($a0)
    /* 2A10 8006B210 2140A000 */  addu       $t0, $a1, $zero
    /* 2A14 8006B214 21388000 */  addu       $a3, $a0, $zero
  .L8006B218:
    /* 2A18 8006B218 0100C224 */  addiu      $v0, $a2, 0x1
    /* 2A1C 8006B21C 21304000 */  addu       $a2, $v0, $zero
    /* 2A20 8006B220 00140200 */  sll        $v0, $v0, 16
    /* 2A24 8006B224 03140200 */  sra        $v0, $v0, 16
    /* 2A28 8006B228 70BBE38C */  lw         $v1, %lo(D_800DBB70)($a3)
    /* 2A2C 8006B22C 78BB048D */  lw         $a0, %lo(D_800DBB78)($t0)
    /* 2A30 8006B230 00006590 */  lbu        $a1, 0x0($v1)
    /* 2A34 8006B234 01006324 */  addiu      $v1, $v1, 0x1
    /* 2A38 8006B238 000085A0 */  sb         $a1, 0x0($a0)
    /* 2A3C 8006B23C 70BBE3AC */  sw         $v1, %lo(D_800DBB70)($a3)
    /* 2A40 8006B240 7EBB2395 */  lhu        $v1, %lo(D_800DBB7E)($t1)
    /* 2A44 8006B244 01008424 */  addiu      $a0, $a0, 0x1
    /* 2A48 8006B248 2A104300 */  slt        $v0, $v0, $v1
    /* 2A4C 8006B24C F2FF4014 */  bnez       $v0, .L8006B218
    /* 2A50 8006B250 78BB04AD */   sw        $a0, %lo(D_800DBB78)($t0)
  .L8006B254:
    /* 2A54 8006B254 0E80043C */  lui        $a0, %hi(D_800DBB74)
    /* 2A58 8006B258 74BB828C */  lw         $v0, %lo(D_800DBB74)($a0)
    /* 2A5C 8006B25C 00000000 */  nop
    /* 2A60 8006B260 00004390 */  lbu        $v1, 0x0($v0)
    /* 2A64 8006B264 7C000224 */  addiu      $v0, $zero, 0x7C
    /* 2A68 8006B268 50FF6214 */  bne        $v1, $v0, .L8006AFAC
    /* 2A6C 8006B26C 0E80083C */   lui       $t0, %hi(D_800DBB70)
    /* 2A70 8006B270 0E80073C */  lui        $a3, %hi(D_800DBB78)
    /* 2A74 8006B274 0E800C3C */  lui        $t4, %hi(D_800DBB80)
    /* 2A78 8006B278 21508000 */  addu       $t2, $a0, $zero
    /* 2A7C 8006B27C 21580000 */  addu       $t3, $zero, $zero
    /* 2A80 8006B280 0E80093C */  lui        $t1, %hi(D_800DBB7E)
  .L8006B284:
    /* 2A84 8006B284 80BB8395 */  lhu        $v1, %lo(D_800DBB80)($t4)
    /* 2A88 8006B288 78BBE28C */  lw         $v0, %lo(D_800DBB78)($a3)
    /* 2A8C 8006B28C 21300000 */  addu       $a2, $zero, $zero
    /* 2A90 8006B290 23104300 */  subu       $v0, $v0, $v1
    /* 2A94 8006B294 FFFF4224 */  addiu      $v0, $v0, -0x1
    /* 2A98 8006B298 70BB02AD */  sw         $v0, %lo(D_800DBB70)($t0)
    /* 2A9C 8006B29C 74BB428D */  lw         $v0, %lo(D_800DBB74)($t2)
    /* 2AA0 8006B2A0 7EBB2395 */  lhu        $v1, %lo(D_800DBB7E)($t1)
    /* 2AA4 8006B2A4 01004224 */  addiu      $v0, $v0, 0x1
    /* 2AA8 8006B2A8 2A186301 */  slt        $v1, $t3, $v1
    /* 2AAC 8006B2AC 10006010 */  beqz       $v1, .L8006B2F0
    /* 2AB0 8006B2B0 74BB42AD */   sw        $v0, %lo(D_800DBB74)($t2)
  .L8006B2B4:
    /* 2AB4 8006B2B4 0100C424 */  addiu      $a0, $a2, 0x1
    /* 2AB8 8006B2B8 21308000 */  addu       $a2, $a0, $zero
    /* 2ABC 8006B2BC 00240400 */  sll        $a0, $a0, 16
    /* 2AC0 8006B2C0 03240400 */  sra        $a0, $a0, 16
    /* 2AC4 8006B2C4 70BB028D */  lw         $v0, %lo(D_800DBB70)($t0)
    /* 2AC8 8006B2C8 78BBE38C */  lw         $v1, %lo(D_800DBB78)($a3)
    /* 2ACC 8006B2CC 00004590 */  lbu        $a1, 0x0($v0)
    /* 2AD0 8006B2D0 01004224 */  addiu      $v0, $v0, 0x1
    /* 2AD4 8006B2D4 000065A0 */  sb         $a1, 0x0($v1)
    /* 2AD8 8006B2D8 70BB02AD */  sw         $v0, %lo(D_800DBB70)($t0)
    /* 2ADC 8006B2DC 7EBB2295 */  lhu        $v0, %lo(D_800DBB7E)($t1)
    /* 2AE0 8006B2E0 01006324 */  addiu      $v1, $v1, 0x1
    /* 2AE4 8006B2E4 2A208200 */  slt        $a0, $a0, $v0
    /* 2AE8 8006B2E8 F2FF8014 */  bnez       $a0, .L8006B2B4
    /* 2AEC 8006B2EC 78BBE3AC */   sw        $v1, %lo(D_800DBB78)($a3)
  .L8006B2F0:
    /* 2AF0 8006B2F0 0E80043C */  lui        $a0, %hi(D_800DBB74)
    /* 2AF4 8006B2F4 74BB828C */  lw         $v0, %lo(D_800DBB74)($a0)
    /* 2AF8 8006B2F8 00000000 */  nop
    /* 2AFC 8006B2FC 00004390 */  lbu        $v1, 0x0($v0)
    /* 2B00 8006B300 7C000224 */  addiu      $v0, $zero, 0x7C
    /* 2B04 8006B304 DFFF6210 */  beq        $v1, $v0, .L8006B284
    /* 2B08 8006B308 00000000 */   nop
    /* 2B0C 8006B30C EBAB0108 */  j          .L8006AFAC
    /* 2B10 8006B310 00000000 */   nop
  .L8006B314:
    /* 2B14 8006B314 1000BF8F */  lw         $ra, 0x10($sp)
    /* 2B18 8006B318 00000000 */  nop
    /* 2B1C 8006B31C 0800E003 */  jr         $ra
    /* 2B20 8006B320 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8006AF64
