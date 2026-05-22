nonmatching func_800CF060, 0x88

glabel func_800CF060
    /* 66860 800CF060 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 66864 800CF064 01000424 */  addiu      $a0, $zero, 0x1
    /* 66868 800CF068 0F80053C */  lui        $a1, %hi(D_800EC2E4)
    /* 6686C 800CF06C E4C2A390 */  lbu        $v1, %lo(D_800EC2E4)($a1)
    /* 66870 800CF070 21108000 */  addu       $v0, $a0, $zero
    /* 66874 800CF074 1800BFAF */  sw         $ra, 0x18($sp)
    /* 66878 800CF078 1400B1AF */  sw         $s1, 0x14($sp)
    /* 6687C 800CF07C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 66880 800CF080 23104300 */  subu       $v0, $v0, $v1
    /* 66884 800CF084 245E030C */  jal        func_800D7890
    /* 66888 800CF088 E4C2A2A0 */   sb        $v0, %lo(D_800EC2E4)($a1)
    /* 6688C 800CF08C 6C3A030C */  jal        func_800CE9B0
    /* 66890 800CF090 00000000 */   nop
    /* 66894 800CF094 21200000 */  addu       $a0, $zero, $zero
    /* 66898 800CF098 245E030C */  jal        func_800D7890
    /* 6689C 800CF09C 21884000 */   addu      $s1, $v0, $zero
    /* 668A0 800CF0A0 583B030C */  jal        func_800CED60
    /* 668A4 800CF0A4 00000000 */   nop
    /* 668A8 800CF0A8 01000424 */  addiu      $a0, $zero, 0x1
    /* 668AC 800CF0AC 245E030C */  jal        func_800D7890
    /* 668B0 800CF0B0 21804000 */   addu      $s0, $v0, $zero
    /* 668B4 800CF0B4 0F80023C */  lui        $v0, %hi(D_800F531C)
    /* 668B8 800CF0B8 1C53438C */  lw         $v1, %lo(D_800F531C)($v0)
    /* 668BC 800CF0BC 04000224 */  addiu      $v0, $zero, 0x4
    /* 668C0 800CF0C0 04006214 */  bne        $v1, $v0, .L800CF0D4
    /* 668C4 800CF0C4 25103002 */   or        $v0, $s1, $s0
    /* 668C8 800CF0C8 5849030C */  jal        func_800D2560
    /* 668CC 800CF0CC 00000000 */   nop
    /* 668D0 800CF0D0 25103002 */  or         $v0, $s1, $s0
  .L800CF0D4:
    /* 668D4 800CF0D4 1800BF8F */  lw         $ra, 0x18($sp)
    /* 668D8 800CF0D8 1400B18F */  lw         $s1, 0x14($sp)
    /* 668DC 800CF0DC 1000B08F */  lw         $s0, 0x10($sp)
    /* 668E0 800CF0E0 0800E003 */  jr         $ra
    /* 668E4 800CF0E4 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_800CF060
