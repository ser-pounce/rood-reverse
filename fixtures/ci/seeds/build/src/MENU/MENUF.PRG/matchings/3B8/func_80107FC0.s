nonmatching func_80107FC0, 0x124

glabel func_80107FC0
    /* 57C0 80107FC0 1180023C */  lui        $v0, %hi(D_801098A0)
    /* 57C4 80107FC4 A098428C */  lw         $v0, %lo(D_801098A0)($v0)
    /* 57C8 80107FC8 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 57CC 80107FCC 1400BFAF */  sw         $ra, 0x14($sp)
    /* 57D0 80107FD0 3F004014 */  bnez       $v0, .L801080D0
    /* 57D4 80107FD4 1000B0AF */   sw        $s0, 0x10($sp)
    /* 57D8 80107FD8 1180103C */  lui        $s0, %hi(D_8010989C)
    /* 57DC 80107FDC 9C98028E */  lw         $v0, %lo(D_8010989C)($s0)
    /* 57E0 80107FE0 00000000 */  nop
    /* 57E4 80107FE4 03004014 */  bnez       $v0, .L80107FF4
    /* 57E8 80107FE8 7E000424 */   addiu     $a0, $zero, 0x7E
    /* 57EC 80107FEC 6216010C */  jal        vs_main_playSfxDefault
    /* 57F0 80107FF0 7D000524 */   addiu     $a1, $zero, 0x7D
  .L80107FF4:
    /* 57F4 80107FF4 9C98038E */  lw         $v1, %lo(D_8010989C)($s0)
    /* 57F8 80107FF8 1E000224 */  addiu      $v0, $zero, 0x1E
    /* 57FC 80107FFC 05006214 */  bne        $v1, $v0, .L80108014
    /* 5800 80108000 A0000424 */   addiu     $a0, $zero, 0xA0
    /* 5804 80108004 7E000424 */  addiu      $a0, $zero, 0x7E
    /* 5808 80108008 6216010C */  jal        vs_main_playSfxDefault
    /* 580C 8010800C 7D000524 */   addiu     $a1, $zero, 0x7D
    /* 5810 80108010 A0000424 */  addiu      $a0, $zero, 0xA0
  .L80108014:
    /* 5814 80108014 9C98068E */  lw         $a2, %lo(D_8010989C)($s0)
    /* 5818 80108018 7521040C */  jal        func_801085D4
    /* 581C 8010801C 40000524 */   addiu     $a1, $zero, 0x40
    /* 5820 80108020 80000424 */  addiu      $a0, $zero, 0x80
    /* 5824 80108024 9C98068E */  lw         $a2, %lo(D_8010989C)($s0)
    /* 5828 80108028 74000524 */  addiu      $a1, $zero, 0x74
    /* 582C 8010802C CF21040C */  jal        func_8010873C
    /* 5830 80108030 F1FFC624 */   addiu     $a2, $a2, -0xF
    /* 5834 80108034 C0000424 */  addiu      $a0, $zero, 0xC0
    /* 5838 80108038 9C98068E */  lw         $a2, %lo(D_8010989C)($s0)
    /* 583C 8010803C 90000524 */  addiu      $a1, $zero, 0x90
    /* 5840 80108040 E121040C */  jal        func_80108784
    /* 5844 80108044 E2FFC624 */   addiu     $a2, $a2, -0x1E
    /* 5848 80108048 D6000424 */  addiu      $a0, $zero, 0xD6
    /* 584C 8010804C 9C98078E */  lw         $a3, %lo(D_8010989C)($s0)
    /* 5850 80108050 BB000524 */  addiu      $a1, $zero, 0xBB
    /* 5854 80108054 3519040C */  jal        func_801064D4
    /* 5858 80108058 E2FFE624 */   addiu     $a2, $a3, -0x1E
    /* 585C 8010805C 9C98038E */  lw         $v1, %lo(D_8010989C)($s0)
    /* 5860 80108060 00000000 */  nop
    /* 5864 80108064 FF7F6228 */  slti       $v0, $v1, 0x7FFF
    /* 5868 80108068 02004010 */  beqz       $v0, .L80108074
    /* 586C 8010806C 01006224 */   addiu     $v0, $v1, 0x1
    /* 5870 80108070 9C9802AE */  sw         $v0, %lo(D_8010989C)($s0)
  .L80108074:
    /* 5874 80108074 0680023C */  lui        $v0, %hi(vs_main_buttonsPressed)
    /* 5878 80108078 D0E1428C */  lw         $v0, %lo(vs_main_buttonsPressed)($v0)
    /* 587C 8010807C 00000000 */  nop
    /* 5880 80108080 20004230 */  andi       $v0, $v0, 0x20
    /* 5884 80108084 13004010 */  beqz       $v0, .L801080D4
    /* 5888 80108088 21100000 */   addu      $v0, $zero, $zero
    /* 588C 8010808C 9C98028E */  lw         $v0, %lo(D_8010989C)($s0)
    /* 5890 80108090 00000000 */  nop
    /* 5894 80108094 4E004228 */  slti       $v0, $v0, 0x4E
    /* 5898 80108098 09004014 */  bnez       $v0, .L801080C0
    /* 589C 8010809C 7E000424 */   addiu     $a0, $zero, 0x7E
    /* 58A0 801080A0 5917010C */  jal        func_80045D64
    /* 58A4 801080A4 21280000 */   addu      $a1, $zero, $zero
    /* 58A8 801080A8 1D000424 */  addiu      $a0, $zero, 0x1D
    /* 58AC 801080AC 02000524 */  addiu      $a1, $zero, 0x2
    /* 58B0 801080B0 2AF8010C */  jal        func_8007E0A8
    /* 58B4 801080B4 05000624 */   addiu     $a2, $zero, 0x5
    /* 58B8 801080B8 35200408 */  j          .L801080D4
    /* 58BC 801080BC 01000224 */   addiu     $v0, $zero, 0x1
  .L801080C0:
    /* 58C0 801080C0 5917010C */  jal        func_80045D64
    /* 58C4 801080C4 21280000 */   addu      $a1, $zero, $zero
    /* 58C8 801080C8 4E000224 */  addiu      $v0, $zero, 0x4E
    /* 58CC 801080CC 9C9802AE */  sw         $v0, %lo(D_8010989C)($s0)
  .L801080D0:
    /* 58D0 801080D0 21100000 */  addu       $v0, $zero, $zero
  .L801080D4:
    /* 58D4 801080D4 1400BF8F */  lw         $ra, 0x14($sp)
    /* 58D8 801080D8 1000B08F */  lw         $s0, 0x10($sp)
    /* 58DC 801080DC 0800E003 */  jr         $ra
    /* 58E0 801080E0 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80107FC0
