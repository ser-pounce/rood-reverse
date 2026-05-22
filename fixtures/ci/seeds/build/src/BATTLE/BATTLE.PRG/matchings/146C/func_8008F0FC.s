nonmatching func_8008F0FC, 0x138

glabel func_8008F0FC
    /* 268FC 8008F0FC C8FFBD27 */  addiu      $sp, $sp, -0x38
    /* 26900 8008F100 2800B0AF */  sw         $s0, 0x28($sp)
    /* 26904 8008F104 0F80103C */  lui        $s0, %hi(D_800F1DAC)
    /* 26908 8008F108 AC1D028E */  lw         $v0, %lo(D_800F1DAC)($s0)
    /* 2690C 8008F10C 3000BFAF */  sw         $ra, 0x30($sp)
    /* 26910 8008F110 2F004010 */  beqz       $v0, .L8008F1D0
    /* 26914 8008F114 2C00B1AF */   sw        $s1, 0x2C($sp)
    /* 26918 8008F118 00004384 */  lh         $v1, 0x0($v0)
    /* 2691C 8008F11C 04000224 */  addiu      $v0, $zero, 0x4
    /* 26920 8008F120 2C006214 */  bne        $v1, $v0, .L8008F1D4
    /* 26924 8008F124 0F80113C */   lui       $s1, %hi(D_800F1DB0)
    /* 26928 8008F128 0F80043C */  lui        $a0, %hi(D_800F1DD0)
    /* 2692C 8008F12C D01D838C */  lw         $v1, %lo(D_800F1DD0)($a0)
    /* 26930 8008F130 10000224 */  addiu      $v0, $zero, 0x10
    /* 26934 8008F134 000062AC */  sw         $v0, 0x0($v1)
    /* 26938 8008F138 D01D848C */  lw         $a0, %lo(D_800F1DD0)($a0)
    /* 2693C 8008F13C 0836020C */  jal        vs_battle_setTimImage
    /* 26940 8008F140 2128A203 */   addu      $a1, $sp, $v0
    /* 26944 8008F144 2000A28F */  lw         $v0, 0x20($sp)
    /* 26948 8008F148 00000000 */  nop
    /* 2694C 8008F14C 13004010 */  beqz       $v0, .L8008F19C
    /* 26950 8008F150 0F80023C */   lui       $v0, %hi(D_800F1DC8)
    /* 26954 8008F154 C81D4490 */  lbu        $a0, %lo(D_800F1DC8)($v0)
    /* 26958 8008F158 1C00A58F */  lw         $a1, 0x1C($sp)
    /* 2695C 8008F15C 0F008230 */  andi       $v0, $a0, 0xF
    /* 26960 8008F160 0000A394 */  lhu        $v1, 0x0($a1)
    /* 26964 8008F164 80110200 */  sll        $v0, $v0, 6
    /* 26968 8008F168 3F006330 */  andi       $v1, $v1, 0x3F
    /* 2696C 8008F16C 21186200 */  addu       $v1, $v1, $v0
    /* 26970 8008F170 0000A3A4 */  sh         $v1, 0x0($a1)
    /* 26974 8008F174 1C00A38F */  lw         $v1, 0x1C($sp)
    /* 26978 8008F178 10008430 */  andi       $a0, $a0, 0x10
    /* 2697C 8008F17C 02006290 */  lbu        $v0, 0x2($v1)
    /* 26980 8008F180 00210400 */  sll        $a0, $a0, 4
    /* 26984 8008F184 21104400 */  addu       $v0, $v0, $a0
    /* 26988 8008F188 020062A4 */  sh         $v0, 0x2($v1)
    /* 2698C 8008F18C 1C00A48F */  lw         $a0, 0x1C($sp)
    /* 26990 8008F190 2000A58F */  lw         $a1, 0x20($sp)
    /* 26994 8008F194 3FA2000C */  jal        LoadImage
    /* 26998 8008F198 00000000 */   nop
  .L8008F19C:
    /* 2699C 8008F19C 1800A48F */  lw         $a0, 0x18($sp)
    /* 269A0 8008F1A0 00000000 */  nop
    /* 269A4 8008F1A4 04008010 */  beqz       $a0, .L8008F1B8
    /* 269A8 8008F1A8 0E000524 */   addiu     $a1, $zero, 0xE
    /* 269AC 8008F1AC 21300000 */  addu       $a2, $zero, $zero
    /* 269B0 8008F1B0 9922010C */  jal        vs_main_loadClut
    /* 269B4 8008F1B4 00010724 */   addiu     $a3, $zero, 0x100
  .L8008F1B8:
    /* 269B8 8008F1B8 AC1D048E */  lw         $a0, %lo(D_800F1DAC)($s0)
    /* 269BC 8008F1BC E012010C */  jal        vs_main_freeCdQueueSlot
    /* 269C0 8008F1C0 00000000 */   nop
    /* 269C4 8008F1C4 21100000 */  addu       $v0, $zero, $zero
    /* 269C8 8008F1C8 883C0208 */  j          .L8008F220
    /* 269CC 8008F1CC AC1D00AE */   sw        $zero, %lo(D_800F1DAC)($s0)
  .L8008F1D0:
    /* 269D0 8008F1D0 0F80113C */  lui        $s1, %hi(D_800F1DB0)
  .L8008F1D4:
    /* 269D4 8008F1D4 B01D228E */  lw         $v0, %lo(D_800F1DB0)($s1)
    /* 269D8 8008F1D8 00000000 */  nop
    /* 269DC 8008F1DC 0F004010 */  beqz       $v0, .L8008F21C
    /* 269E0 8008F1E0 00000000 */   nop
    /* 269E4 8008F1E4 00004384 */  lh         $v1, 0x0($v0)
    /* 269E8 8008F1E8 04000224 */  addiu      $v0, $zero, 0x4
    /* 269EC 8008F1EC 0C006214 */  bne        $v1, $v0, .L8008F220
    /* 269F0 8008F1F0 21100000 */   addu      $v0, $zero, $zero
    /* 269F4 8008F1F4 0F80103C */  lui        $s0, %hi(D_800F1DD0)
    /* 269F8 8008F1F8 D01D048E */  lw         $a0, %lo(D_800F1DD0)($s0)
    /* 269FC 8008F1FC 180F010C */  jal        vs_main_freeHeapR
    /* 26A00 8008F200 00000000 */   nop
    /* 26A04 8008F204 B01D248E */  lw         $a0, %lo(D_800F1DB0)($s1)
    /* 26A08 8008F208 E012010C */  jal        vs_main_freeCdQueueSlot
    /* 26A0C 8008F20C D01D00AE */   sw        $zero, %lo(D_800F1DD0)($s0)
    /* 26A10 8008F210 01000224 */  addiu      $v0, $zero, 0x1
    /* 26A14 8008F214 883C0208 */  j          .L8008F220
    /* 26A18 8008F218 B01D20AE */   sw        $zero, %lo(D_800F1DB0)($s1)
  .L8008F21C:
    /* 26A1C 8008F21C 21100000 */  addu       $v0, $zero, $zero
  .L8008F220:
    /* 26A20 8008F220 3000BF8F */  lw         $ra, 0x30($sp)
    /* 26A24 8008F224 2C00B18F */  lw         $s1, 0x2C($sp)
    /* 26A28 8008F228 2800B08F */  lw         $s0, 0x28($sp)
    /* 26A2C 8008F22C 0800E003 */  jr         $ra
    /* 26A30 8008F230 3800BD27 */   addiu     $sp, $sp, 0x38
endlabel func_8008F0FC
