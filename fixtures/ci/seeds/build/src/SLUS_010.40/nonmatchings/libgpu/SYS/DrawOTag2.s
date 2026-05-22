nonmatching DrawOTag2, 0xFC

glabel DrawOTag2
    /* 1B8B8 8002B0B8 0380023C */  lui        $v0, %hi(D_80033446)
    /* 1B8BC 8002B0BC 46344290 */  lbu        $v0, %lo(D_80033446)($v0)
    /* 1B8C0 8002B0C0 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1B8C4 8002B0C4 1000B0AF */  sw         $s0, 0x10($sp)
    /* 1B8C8 8002B0C8 21808000 */  addu       $s0, $a0, $zero
    /* 1B8CC 8002B0CC 0200422C */  sltiu      $v0, $v0, 0x2
    /* 1B8D0 8002B0D0 08004014 */  bnez       $v0, .L8002B0F4
    /* 1B8D4 8002B0D4 1400BFAF */   sw        $ra, 0x14($sp)
    /* 1B8D8 8002B0D8 0180043C */  lui        $a0, %hi(D_800109E4)
    /* 1B8DC 8002B0DC E4098424 */  addiu      $a0, $a0, %lo(D_800109E4)
    /* 1B8E0 8002B0E0 0380023C */  lui        $v0, %hi(D_80033440)
    /* 1B8E4 8002B0E4 4034428C */  lw         $v0, %lo(D_80033440)($v0)
    /* 1B8E8 8002B0E8 00000000 */  nop
    /* 1B8EC 8002B0EC 09F84000 */  jalr       $v0
    /* 1B8F0 8002B0F0 21280002 */   addu      $a1, $s0, $zero
  .L8002B0F4:
    /* 1B8F4 8002B0F4 B17D000C */  jal        VSync
    /* 1B8F8 8002B0F8 FFFF0424 */   addiu     $a0, $zero, -0x1
    /* 1B8FC 8002B0FC 0380033C */  lui        $v1, %hi(D_80033558)
    /* 1B900 8002B100 5835638C */  lw         $v1, %lo(D_80033558)($v1)
    /* 1B904 8002B104 F0004224 */  addiu      $v0, $v0, 0xF0
    /* 1B908 8002B108 0380013C */  lui        $at, %hi(D_80033580)
    /* 1B90C 8002B10C 803522AC */  sw         $v0, %lo(D_80033580)($at)
    /* 1B910 8002B110 0380013C */  lui        $at, %hi(D_80033584)
    /* 1B914 8002B114 843520AC */  sw         $zero, %lo(D_80033584)($at)
    /* 1B918 8002B118 0000628C */  lw         $v0, 0x0($v1)
    /* 1B91C 8002B11C 52AC0008 */  j          .L8002B148
    /* 1B920 8002B120 0001033C */   lui       $v1, (0x1000000 >> 16)
  .L8002B124:
    /* 1B924 8002B124 EEAA000C */  jal        func_8002ABB8
    /* 1B928 8002B128 00000000 */   nop
    /* 1B92C 8002B12C 1D004014 */  bnez       $v0, .L8002B1A4
    /* 1B930 8002B130 FFFF0224 */   addiu     $v0, $zero, -0x1
    /* 1B934 8002B134 0380023C */  lui        $v0, %hi(D_80033558)
    /* 1B938 8002B138 5835428C */  lw         $v0, %lo(D_80033558)($v0)
    /* 1B93C 8002B13C 00000000 */  nop
    /* 1B940 8002B140 0000428C */  lw         $v0, 0x0($v0)
    /* 1B944 8002B144 0001033C */  lui        $v1, (0x1000000 >> 16)
  .L8002B148:
    /* 1B948 8002B148 24104300 */  and        $v0, $v0, $v1
    /* 1B94C 8002B14C F5FF4014 */  bnez       $v0, .L8002B124
    /* 1B950 8002B150 00000000 */   nop
    /* 1B954 8002B154 0380023C */  lui        $v0, %hi(D_8003354C)
    /* 1B958 8002B158 4C35428C */  lw         $v0, %lo(D_8003354C)($v0)
    /* 1B95C 8002B15C 00000000 */  nop
    /* 1B960 8002B160 0000428C */  lw         $v0, 0x0($v0)
    /* 1B964 8002B164 0004033C */  lui        $v1, (0x4000000 >> 16)
    /* 1B968 8002B168 24104300 */  and        $v0, $v0, $v1
    /* 1B96C 8002B16C EDFF4010 */  beqz       $v0, .L8002B124
    /* 1B970 8002B170 00000000 */   nop
    /* 1B974 8002B174 0380053C */  lui        $a1, %hi(_GPU_ResetCallback)
    /* 1B978 8002B178 B4B1A524 */  addiu      $a1, $a1, %lo(_GPU_ResetCallback)
    /* 1B97C 8002B17C 4D7E000C */  jal        DMACallback
    /* 1B980 8002B180 02000424 */   addiu     $a0, $zero, 0x2
    /* 1B984 8002B184 0380023C */  lui        $v0, %hi(D_8003343C)
    /* 1B988 8002B188 3C34428C */  lw         $v0, %lo(D_8003343C)($v0)
    /* 1B98C 8002B18C 00000000 */  nop
    /* 1B990 8002B190 1800428C */  lw         $v0, 0x18($v0)
    /* 1B994 8002B194 00000000 */  nop
    /* 1B998 8002B198 09F84000 */  jalr       $v0
    /* 1B99C 8002B19C 21200002 */   addu      $a0, $s0, $zero
    /* 1B9A0 8002B1A0 21100000 */  addu       $v0, $zero, $zero
  .L8002B1A4:
    /* 1B9A4 8002B1A4 1400BF8F */  lw         $ra, 0x14($sp)
    /* 1B9A8 8002B1A8 1000B08F */  lw         $s0, 0x10($sp)
    /* 1B9AC 8002B1AC 0800E003 */  jr         $ra
    /* 1B9B0 8002B1B0 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel DrawOTag2
