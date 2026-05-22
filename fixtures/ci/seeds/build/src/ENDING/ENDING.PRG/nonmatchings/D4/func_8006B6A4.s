nonmatching func_8006B6A4, 0xBC

glabel func_8006B6A4
    /* 2EA4 8006B6A4 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 2EA8 8006B6A8 2000B2AF */  sw         $s2, 0x20($sp)
    /* 2EAC 8006B6AC 21908000 */  addu       $s2, $a0, $zero
    /* 2EB0 8006B6B0 1800B0AF */  sw         $s0, 0x18($sp)
    /* 2EB4 8006B6B4 0680103C */  lui        $s0, %hi(vs_main_frameBuf)
    /* 2EB8 8006B6B8 10E2028E */  lw         $v0, %lo(vs_main_frameBuf)($s0)
    /* 2EBC 8006B6BC 21200000 */  addu       $a0, $zero, $zero
    /* 2EC0 8006B6C0 2400BFAF */  sw         $ra, 0x24($sp)
    /* 2EC4 8006B6C4 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 2EC8 8006B6C8 0100422C */  sltiu      $v0, $v0, 0x1
    /* 2ECC 8006B6CC 94A1000C */  jal        DrawSync
    /* 2ED0 8006B6D0 10E202AE */   sw        $v0, %lo(vs_main_frameBuf)($s0)
    /* 2ED4 8006B6D4 8709010C */  jal        vs_main_gametimeUpdate
    /* 2ED8 8006B6D8 21200000 */   addu      $a0, $zero, $zero
    /* 2EDC 8006B6DC 10E2048E */  lw         $a0, %lo(vs_main_frameBuf)($s0)
    /* 2EE0 8006B6E0 21884000 */  addu       $s1, $v0, $zero
    /* 2EE4 8006B6E4 80180400 */  sll        $v1, $a0, 2
    /* 2EE8 8006B6E8 21186400 */  addu       $v1, $v1, $a0
    /* 2EEC 8006B6EC 80180300 */  sll        $v1, $v1, 2
    /* 2EF0 8006B6F0 0680043C */  lui        $a0, %hi(vs_main_dispEnv)
    /* 2EF4 8006B6F4 88E18424 */  addiu      $a0, $a0, %lo(vs_main_dispEnv)
    /* 2EF8 8006B6F8 A0A3000C */  jal        PutDispEnv
    /* 2EFC 8006B6FC 21206400 */   addu      $a0, $v1, $a0
    /* 2F00 8006B700 10E2028E */  lw         $v0, %lo(vs_main_frameBuf)($s0)
    /* 2F04 8006B704 00000000 */  nop
    /* 2F08 8006B708 40200200 */  sll        $a0, $v0, 1
    /* 2F0C 8006B70C 21208200 */  addu       $a0, $a0, $v0
    /* 2F10 8006B710 C0200400 */  sll        $a0, $a0, 3
    /* 2F14 8006B714 23208200 */  subu       $a0, $a0, $v0
    /* 2F18 8006B718 80200400 */  sll        $a0, $a0, 2
    /* 2F1C 8006B71C 0680023C */  lui        $v0, %hi(vs_main_drawEnv)
    /* 2F20 8006B720 D0E04224 */  addiu      $v0, $v0, %lo(vs_main_drawEnv)
    /* 2F24 8006B724 2DA3000C */  jal        PutDrawEnv
    /* 2F28 8006B728 21208200 */   addu      $a0, $a0, $v0
    /* 2F2C 8006B72C 11A3000C */  jal        DrawOTag
    /* 2F30 8006B730 21204002 */   addu      $a0, $s2, $zero
    /* 2F34 8006B734 0680043C */  lui        $a0, %hi(_frameDuration)
    /* 2F38 8006B738 21102002 */  addu       $v0, $s1, $zero
    /* 2F3C 8006B73C D8E1838C */  lw         $v1, %lo(_frameDuration)($a0)
    /* 2F40 8006B740 2400BF8F */  lw         $ra, 0x24($sp)
    /* 2F44 8006B744 2000B28F */  lw         $s2, 0x20($sp)
    /* 2F48 8006B748 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 2F4C 8006B74C 1800B08F */  lw         $s0, 0x18($sp)
    /* 2F50 8006B750 01006324 */  addiu      $v1, $v1, 0x1
    /* 2F54 8006B754 D8E183AC */  sw         $v1, %lo(_frameDuration)($a0)
    /* 2F58 8006B758 0800E003 */  jr         $ra
    /* 2F5C 8006B75C 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_8006B6A4
