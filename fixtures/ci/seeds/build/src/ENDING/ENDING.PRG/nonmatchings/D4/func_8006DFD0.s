nonmatching func_8006DFD0, 0xA4

glabel func_8006DFD0
    /* 57D0 8006DFD0 21180000 */  addu       $v1, $zero, $zero
    /* 57D4 8006DFD4 21306000 */  addu       $a2, $v1, $zero
    /* 57D8 8006DFD8 01000524 */  addiu      $a1, $zero, 0x1
    /* 57DC 8006DFDC 0680023C */  lui        $v0, %hi(vs_main_scoredata)
    /* 57E0 8006DFE0 A0FE448C */  lw         $a0, %lo(vs_main_scoredata)($v0)
    /* 57E4 8006DFE4 04106500 */  sllv       $v0, $a1, $v1
  .L8006DFE8:
    /* 57E8 8006DFE8 24108200 */  and        $v0, $a0, $v0
    /* 57EC 8006DFEC 02004010 */  beqz       $v0, .L8006DFF8
    /* 57F0 8006DFF0 00000000 */   nop
    /* 57F4 8006DFF4 0100C624 */  addiu      $a2, $a2, 0x1
  .L8006DFF8:
    /* 57F8 8006DFF8 01006324 */  addiu      $v1, $v1, 0x1
    /* 57FC 8006DFFC 10006228 */  slti       $v0, $v1, 0x10
    /* 5800 8006E000 F9FF4014 */  bnez       $v0, .L8006DFE8
    /* 5804 8006E004 04106500 */   sllv      $v0, $a1, $v1
    /* 5808 8006E008 21180000 */  addu       $v1, $zero, $zero
    /* 580C 8006E00C 0E80023C */  lui        $v0, %hi(D_800DC1F8)
    /* 5810 8006E010 F8C1478C */  lw         $a3, %lo(D_800DC1F8)($v0)
    /* 5814 8006E014 0E80083C */  lui        $t0, %hi(D_800DC1F0)
    /* 5818 8006E018 0E80023C */  lui        $v0, %hi(D_800DBAD8)
    /* 581C 8006E01C D8BA4524 */  addiu      $a1, $v0, %lo(D_800DBAD8)
    /* 5820 8006E020 0E80023C */  lui        $v0, %hi(D_800DBAB8)
    /* 5824 8006E024 B8BA4424 */  addiu      $a0, $v0, %lo(D_800DBAB8)
  .L8006E028:
    /* 5828 8006E028 00008284 */  lh         $v0, 0x0($a0)
    /* 582C 8006E02C 00000000 */  nop
    /* 5830 8006E030 2A10C200 */  slt        $v0, $a2, $v0
    /* 5834 8006E034 08004014 */  bnez       $v0, .L8006E058
    /* 5838 8006E038 00000000 */   nop
    /* 583C 8006E03C 0000A28C */  lw         $v0, 0x0($a1)
    /* 5840 8006E040 00000000 */  nop
    /* 5844 8006E044 2B10E200 */  sltu       $v0, $a3, $v0
    /* 5848 8006E048 04004014 */  bnez       $v0, .L8006E05C
    /* 584C 8006E04C 0400A524 */   addiu     $a1, $a1, 0x4
    /* 5850 8006E050 0800E003 */  jr         $ra
    /* 5854 8006E054 F0C103AD */   sw        $v1, %lo(D_800DC1F0)($t0)
  .L8006E058:
    /* 5858 8006E058 0400A524 */  addiu      $a1, $a1, 0x4
  .L8006E05C:
    /* 585C 8006E05C 01006324 */  addiu      $v1, $v1, 0x1
    /* 5860 8006E060 10006228 */  slti       $v0, $v1, 0x10
    /* 5864 8006E064 F0FF4014 */  bnez       $v0, .L8006E028
    /* 5868 8006E068 02008424 */   addiu     $a0, $a0, 0x2
    /* 586C 8006E06C 0800E003 */  jr         $ra
    /* 5870 8006E070 00000000 */   nop
endlabel func_8006DFD0
