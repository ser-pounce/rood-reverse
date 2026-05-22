nonmatching vs_battle_script_setFlagIfButton, 0x4C

glabel vs_battle_script_setFlagIfButton
    /* 50A54 800B9254 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 50A58 800B9258 1000BFAF */  sw         $ra, 0x10($sp)
    /* 50A5C 800B925C 80FF020C */  jal        vs_battle_getShort
    /* 50A60 800B9260 01008424 */   addiu     $a0, $a0, 0x1
    /* 50A64 800B9264 FF034430 */  andi       $a0, $v0, 0x3FF
    /* 50A68 800B9268 00804230 */  andi       $v0, $v0, 0x8000
    /* 50A6C 800B926C 04004010 */  beqz       $v0, .L800B9280
    /* 50A70 800B9270 0680023C */   lui       $v0, %hi(vs_main_buttonsPressed)
    /* 50A74 800B9274 D0E14590 */  lbu        $a1, %lo(vs_main_buttonsPressed)($v0)
    /* 50A78 800B9278 A2E40208 */  j          .L800B9288
    /* 50A7C 800B927C 00000000 */   nop
  .L800B9280:
    /* 50A80 800B9280 0680023C */  lui        $v0, %hi(vs_main_buttonsPreviousState)
    /* 50A84 800B9284 C0E14590 */  lbu        $a1, %lo(vs_main_buttonsPreviousState)($v0)
  .L800B9288:
    /* 50A88 800B9288 05FB020C */  jal        vs_battle_setStateFlag
    /* 50A8C 800B928C 00000000 */   nop
    /* 50A90 800B9290 1000BF8F */  lw         $ra, 0x10($sp)
    /* 50A94 800B9294 21100000 */  addu       $v0, $zero, $zero
    /* 50A98 800B9298 0800E003 */  jr         $ra
    /* 50A9C 800B929C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel vs_battle_script_setFlagIfButton
