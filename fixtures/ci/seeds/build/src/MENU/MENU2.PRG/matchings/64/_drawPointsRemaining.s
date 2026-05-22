nonmatching _drawPointsRemaining, 0xF0

glabel _drawPointsRemaining
    /* FE4 801037E4 D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* FE8 801037E8 21288000 */  addu       $a1, $a0, $zero
    /* FEC 801037EC 0680023C */  lui        $v0, %hi(vs_main_artsStatus)
    /* FF0 801037F0 40004224 */  addiu      $v0, $v0, %lo(vs_main_artsStatus)
    /* FF4 801037F4 2C00BFAF */  sw         $ra, 0x2C($sp)
    /* FF8 801037F8 2800B2AF */  sw         $s2, 0x28($sp)
    /* FFC 801037FC 2400B1AF */  sw         $s1, 0x24($sp)
    /* 1000 80103800 2000B0AF */  sw         $s0, 0x20($sp)
    /* 1004 80103804 22004494 */  lhu        $a0, 0x22($v0)
    /* 1008 80103808 20005194 */  lhu        $s1, 0x20($v0)
    /* 100C 8010380C 16000224 */  addiu      $v0, $zero, 0x16
    /* 1010 80103810 2A002212 */  beq        $s1, $v0, .L801038BC
    /* 1014 80103814 0580023C */   lui       $v0, %hi(vs_main_battleAbilitiesPointsRequirements)
    /* 1018 80103818 5CFE4224 */  addiu      $v0, $v0, %lo(vs_main_battleAbilitiesPointsRequirements)
    /* 101C 8010381C 40181100 */  sll        $v1, $s1, 1
    /* 1020 80103820 21186200 */  addu       $v1, $v1, $v0
    /* 1024 80103824 00006294 */  lhu        $v0, 0x0($v1)
    /* 1028 80103828 00000000 */  nop
    /* 102C 8010382C 23204400 */  subu       $a0, $v0, $a0
    /* 1030 80103830 02008104 */  bgez       $a0, .L8010383C
    /* 1034 80103834 CE00A324 */   addiu     $v1, $a1, 0xCE
    /* 1038 80103838 21200000 */  addu       $a0, $zero, $zero
  .L8010383C:
    /* 103C 8010383C 4200023C */  lui        $v0, %hi(D_420060)
    /* 1040 80103840 25906200 */  or         $s2, $v1, $v0
    /* 1044 80103844 0C001124 */  addiu      $s1, $zero, 0xC
    /* 1048 80103848 1000B027 */  addiu      $s0, $sp, 0x10
    /* 104C 8010384C 54000224 */  addiu      $v0, $zero, 0x54
    /* 1050 80103850 1E00A2A3 */  sb         $v0, 0x1E($sp)
    /* 1054 80103854 50000224 */  addiu      $v0, $zero, 0x50
    /* 1058 80103858 1F00A0A3 */  sb         $zero, 0x1F($sp)
    /* 105C 8010385C 1D00A2A3 */  sb         $v0, 0x1D($sp)
  .L80103860:
    /* 1060 80103860 1533030C */  jal        vs_battle_toBCD
    /* 1064 80103864 00000000 */   nop
    /* 1068 80103868 21204000 */  addu       $a0, $v0, $zero
    /* 106C 8010386C 21181102 */  addu       $v1, $s0, $s1
    /* 1070 80103870 0F008230 */  andi       $v0, $a0, 0xF
    /* 1074 80103874 30004224 */  addiu      $v0, $v0, 0x30
    /* 1078 80103878 000062A0 */  sb         $v0, 0x0($v1)
    /* 107C 8010387C 03210400 */  sra        $a0, $a0, 4
    /* 1080 80103880 F7FF8014 */  bnez       $a0, .L80103860
    /* 1084 80103884 FFFF3126 */   addiu     $s1, $s1, -0x1
    /* 1088 80103888 1000B027 */  addiu      $s0, $sp, 0x10
    /* 108C 8010388C 21801102 */  addu       $s0, $s0, $s1
    /* 1090 80103890 23000224 */  addiu      $v0, $zero, 0x23
    /* 1094 80103894 000002A2 */  sb         $v0, 0x0($s0)
    /* 1098 80103898 1080043C */  lui        $a0, %hi(D_80102808)
    /* 109C 8010389C 08288424 */  addiu      $a0, $a0, %lo(D_80102808)
    /* 10A0 801038A0 21284002 */  addu       $a1, $s2, $zero
    /* 10A4 801038A4 0A1A030C */  jal        vs_battle_renderTextRaw
    /* 10A8 801038A8 21300000 */   addu      $a2, $zero, $zero
    /* 10AC 801038AC 21200002 */  addu       $a0, $s0, $zero
    /* 10B0 801038B0 60004526 */  addiu      $a1, $s2, %lo(D_420060)
    /* 10B4 801038B4 0A1A030C */  jal        vs_battle_renderTextRaw
    /* 10B8 801038B8 21300000 */   addu      $a2, $zero, $zero
  .L801038BC:
    /* 10BC 801038BC 2C00BF8F */  lw         $ra, 0x2C($sp)
    /* 10C0 801038C0 2800B28F */  lw         $s2, 0x28($sp)
    /* 10C4 801038C4 2400B18F */  lw         $s1, 0x24($sp)
    /* 10C8 801038C8 2000B08F */  lw         $s0, 0x20($sp)
    /* 10CC 801038CC 0800E003 */  jr         $ra
    /* 10D0 801038D0 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel _drawPointsRemaining
