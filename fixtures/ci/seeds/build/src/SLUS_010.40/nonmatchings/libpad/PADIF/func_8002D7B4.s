nonmatching func_8002D7B4, 0xAC

glabel func_8002D7B4
    /* 1DFB4 8002D7B4 0380023C */  lui        $v0, %hi(D_8003361C)
    /* 1DFB8 8002D7B8 1C36428C */  lw         $v0, %lo(D_8003361C)($v0)
    /* 1DFBC 8002D7BC E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1DFC0 8002D7C0 1000B0AF */  sw         $s0, 0x10($sp)
    /* 1DFC4 8002D7C4 21808000 */  addu       $s0, $a0, $zero
    /* 1DFC8 8002D7C8 0D004010 */  beqz       $v0, .L8002D800
    /* 1DFCC 8002D7CC 1400BFAF */   sw        $ra, 0x14($sp)
    /* 1DFD0 8002D7D0 0C00048E */  lw         $a0, 0xC($s0)
    /* 1DFD4 8002D7D4 0380023C */  lui        $v0, %hi(D_800335B4)
    /* 1DFD8 8002D7D8 B435428C */  lw         $v0, %lo(D_800335B4)($v0)
    /* 1DFDC 8002D7DC 00000000 */  nop
    /* 1DFE0 8002D7E0 09F84000 */  jalr       $v0
    /* 1DFE4 8002D7E4 E0018424 */   addiu     $a0, $a0, 0x1E0
    /* 1DFE8 8002D7E8 0C00048E */  lw         $a0, 0xC($s0)
    /* 1DFEC 8002D7EC 0380023C */  lui        $v0, %hi(D_800335B4)
    /* 1DFF0 8002D7F0 B435428C */  lw         $v0, %lo(D_800335B4)($v0)
    /* 1DFF4 8002D7F4 00000000 */  nop
    /* 1DFF8 8002D7F8 09F84000 */  jalr       $v0
    /* 1DFFC 8002D7FC D0028424 */   addiu     $a0, $a0, 0x2D0
  .L8002D800:
    /* 1E000 8002D800 37000292 */  lbu        $v0, 0x37($s0)
    /* 1E004 8002D804 00000000 */  nop
    /* 1E008 8002D808 03004014 */  bnez       $v0, .L8002D818
    /* 1E00C 8002D80C 21280000 */   addu      $a1, $zero, $zero
    /* 1E010 8002D810 0380053C */  lui        $a1, %hi(D_800335E8)
    /* 1E014 8002D814 E835A58C */  lw         $a1, %lo(D_800335E8)($a1)
  .L8002D818:
    /* 1E018 8002D818 CEB1000C */  jal        _padSioRW2
    /* 1E01C 8002D81C 21200002 */   addu      $a0, $s0, $zero
    /* 1E020 8002D820 0B004004 */  bltz       $v0, .L8002D850
    /* 1E024 8002D824 00000000 */   nop
    /* 1E028 8002D828 0F004230 */  andi       $v0, $v0, 0xF
    /* 1E02C 8002D82C 40100200 */  sll        $v0, $v0, 1
    /* 1E030 8002D830 0380013C */  lui        $at, %hi(D_80033614)
    /* 1E034 8002D834 143622AC */  sw         $v0, %lo(D_80033614)($at)
    /* 1E038 8002D838 05004014 */  bnez       $v0, .L8002D850
    /* 1E03C 8002D83C 21100000 */   addu      $v0, $zero, $zero
    /* 1E040 8002D840 20000224 */  addiu      $v0, $zero, 0x20
    /* 1E044 8002D844 0380013C */  lui        $at, %hi(D_80033614)
    /* 1E048 8002D848 143622AC */  sw         $v0, %lo(D_80033614)($at)
    /* 1E04C 8002D84C 21100000 */  addu       $v0, $zero, $zero
  .L8002D850:
    /* 1E050 8002D850 1400BF8F */  lw         $ra, 0x14($sp)
    /* 1E054 8002D854 1000B08F */  lw         $s0, 0x10($sp)
    /* 1E058 8002D858 0800E003 */  jr         $ra
    /* 1E05C 8002D85C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8002D7B4
