nonmatching _renderScreen, 0xAC

glabel _renderScreen
    /* 9268 80071A68 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 926C 80071A6C 2000B2AF */  sw         $s2, 0x20($sp)
    /* 9270 80071A70 21908000 */  addu       $s2, $a0, $zero
    /* 9274 80071A74 1800B0AF */  sw         $s0, 0x18($sp)
    /* 9278 80071A78 0680103C */  lui        $s0, %hi(vs_main_frameBuf)
    /* 927C 80071A7C 10E2028E */  lw         $v0, %lo(vs_main_frameBuf)($s0)
    /* 9280 80071A80 21200000 */  addu       $a0, $zero, $zero
    /* 9284 80071A84 2400BFAF */  sw         $ra, 0x24($sp)
    /* 9288 80071A88 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 928C 80071A8C 0100422C */  sltiu      $v0, $v0, 0x1
    /* 9290 80071A90 94A1000C */  jal        DrawSync
    /* 9294 80071A94 10E202AE */   sw        $v0, %lo(vs_main_frameBuf)($s0)
    /* 9298 80071A98 8709010C */  jal        vs_main_gametimeUpdate
    /* 929C 80071A9C 21200000 */   addu      $a0, $zero, $zero
    /* 92A0 80071AA0 10E2048E */  lw         $a0, %lo(vs_main_frameBuf)($s0)
    /* 92A4 80071AA4 21884000 */  addu       $s1, $v0, $zero
    /* 92A8 80071AA8 80180400 */  sll        $v1, $a0, 2
    /* 92AC 80071AAC 21186400 */  addu       $v1, $v1, $a0
    /* 92B0 80071AB0 80180300 */  sll        $v1, $v1, 2
    /* 92B4 80071AB4 0680043C */  lui        $a0, %hi(vs_main_dispEnv)
    /* 92B8 80071AB8 88E18424 */  addiu      $a0, $a0, %lo(vs_main_dispEnv)
    /* 92BC 80071ABC A0A3000C */  jal        PutDispEnv
    /* 92C0 80071AC0 21206400 */   addu      $a0, $v1, $a0
    /* 92C4 80071AC4 10E2028E */  lw         $v0, %lo(vs_main_frameBuf)($s0)
    /* 92C8 80071AC8 00000000 */  nop
    /* 92CC 80071ACC 40200200 */  sll        $a0, $v0, 1
    /* 92D0 80071AD0 21208200 */  addu       $a0, $a0, $v0
    /* 92D4 80071AD4 C0200400 */  sll        $a0, $a0, 3
    /* 92D8 80071AD8 23208200 */  subu       $a0, $a0, $v0
    /* 92DC 80071ADC 80200400 */  sll        $a0, $a0, 2
    /* 92E0 80071AE0 0680023C */  lui        $v0, %hi(vs_main_drawEnv)
    /* 92E4 80071AE4 D0E04224 */  addiu      $v0, $v0, %lo(vs_main_drawEnv)
    /* 92E8 80071AE8 2DA3000C */  jal        PutDrawEnv
    /* 92EC 80071AEC 21208200 */   addu      $a0, $a0, $v0
    /* 92F0 80071AF0 11A3000C */  jal        DrawOTag
    /* 92F4 80071AF4 21204002 */   addu      $a0, $s2, $zero
    /* 92F8 80071AF8 21102002 */  addu       $v0, $s1, $zero
    /* 92FC 80071AFC 2400BF8F */  lw         $ra, 0x24($sp)
    /* 9300 80071B00 2000B28F */  lw         $s2, 0x20($sp)
    /* 9304 80071B04 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 9308 80071B08 1800B08F */  lw         $s0, 0x18($sp)
    /* 930C 80071B0C 0800E003 */  jr         $ra
    /* 9310 80071B10 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel _renderScreen
