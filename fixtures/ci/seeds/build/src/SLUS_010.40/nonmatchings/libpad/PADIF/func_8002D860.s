nonmatching func_8002D860, 0xC4

glabel func_8002D860
    /* 1E060 8002D860 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1E064 8002D864 1000B0AF */  sw         $s0, 0x10($sp)
    /* 1E068 8002D868 21808000 */  addu       $s0, $a0, $zero
    /* 1E06C 8002D86C 0380023C */  lui        $v0, %hi(D_800335E8)
    /* 1E070 8002D870 E835428C */  lw         $v0, %lo(D_800335E8)($v0)
    /* 1E074 8002D874 21200000 */  addu       $a0, $zero, $zero
    /* 1E078 8002D878 0B004010 */  beqz       $v0, .L8002D8A8
    /* 1E07C 8002D87C 1400BFAF */   sw        $ra, 0x14($sp)
    /* 1E080 8002D880 3C00028E */  lw         $v0, 0x3C($s0)
    /* 1E084 8002D884 00000000 */  nop
    /* 1E088 8002D888 00004290 */  lbu        $v0, 0x0($v0)
    /* 1E08C 8002D88C 08000324 */  addiu      $v1, $zero, 0x8
    /* 1E090 8002D890 02110200 */  srl        $v0, $v0, 4
    /* 1E094 8002D894 04004314 */  bne        $v0, $v1, .L8002D8A8
    /* 1E098 8002D898 00000000 */   nop
    /* 1E09C 8002D89C 37000292 */  lbu        $v0, 0x37($s0)
    /* 1E0A0 8002D8A0 00000000 */  nop
    /* 1E0A4 8002D8A4 0100442C */  sltiu      $a0, $v0, 0x1
  .L8002D8A8:
    /* 1E0A8 8002D8A8 0380013C */  lui        $at, %hi(D_80033620)
    /* 1E0AC 8002D8AC 06008014 */  bnez       $a0, .L8002D8C8
    /* 1E0B0 8002D8B0 203624AC */   sw        $a0, %lo(D_80033620)($at)
    /* 1E0B4 8002D8B4 0380023C */  lui        $v0, %hi(D_800335A8)
    /* 1E0B8 8002D8B8 A835428C */  lw         $v0, %lo(D_800335A8)($v0)
    /* 1E0BC 8002D8BC 00000000 */  nop
    /* 1E0C0 8002D8C0 09F84000 */  jalr       $v0
    /* 1E0C4 8002D8C4 21200002 */   addu      $a0, $s0, $zero
  .L8002D8C8:
    /* 1E0C8 8002D8C8 0380053C */  lui        $a1, %hi(D_80033620)
    /* 1E0CC 8002D8CC 2036A58C */  lw         $a1, %lo(D_80033620)($a1)
    /* 1E0D0 8002D8D0 0380023C */  lui        $v0, %hi(D_800335A4)
    /* 1E0D4 8002D8D4 A435428C */  lw         $v0, %lo(D_800335A4)($v0)
    /* 1E0D8 8002D8D8 00000000 */  nop
    /* 1E0DC 8002D8DC 09F84000 */  jalr       $v0
    /* 1E0E0 8002D8E0 21200002 */   addu      $a0, $s0, $zero
    /* 1E0E4 8002D8E4 21200002 */  addu       $a0, $s0, $zero
    /* 1E0E8 8002D8E8 CEB1000C */  jal        _padSioRW2
    /* 1E0EC 8002D8EC FF004530 */   andi      $a1, $v0, 0xFF
    /* 1E0F0 8002D8F0 21184000 */  addu       $v1, $v0, $zero
    /* 1E0F4 8002D8F4 5A000224 */  addiu      $v0, $zero, 0x5A
    /* 1E0F8 8002D8F8 06006210 */  beq        $v1, $v0, .L8002D914
    /* 1E0FC 8002D8FC 21106000 */   addu      $v0, $v1, $zero
    /* 1E100 8002D900 04006010 */  beqz       $v1, .L8002D914
    /* 1E104 8002D904 00000000 */   nop
    /* 1E108 8002D908 02006104 */  bgez       $v1, .L8002D914
    /* 1E10C 8002D90C FCFF0224 */   addiu     $v0, $zero, -0x4
    /* 1E110 8002D910 21106000 */  addu       $v0, $v1, $zero
  .L8002D914:
    /* 1E114 8002D914 1400BF8F */  lw         $ra, 0x14($sp)
    /* 1E118 8002D918 1000B08F */  lw         $s0, 0x10($sp)
    /* 1E11C 8002D91C 0800E003 */  jr         $ra
    /* 1E120 8002D920 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8002D860
