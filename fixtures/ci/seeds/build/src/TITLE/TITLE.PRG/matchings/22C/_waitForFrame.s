nonmatching _waitForFrame, 0x94

glabel _waitForFrame
    /* 6C2C 8006F42C F8FFBD27 */  addiu      $sp, $sp, -0x8
    /* 6C30 8006F430 3400838C */  lw         $v1, 0x34($a0)
    /* 6C34 8006F434 8000023C */  lui        $v0, (0x800000 >> 16)
    /* 6C38 8006F438 0000A2AF */  sw         $v0, 0x0($sp)
    /* 6C3C 8006F43C 1D006014 */  bnez       $v1, .L8006F4B4
    /* 6C40 8006F440 00000000 */   nop
    /* 6C44 8006F444 01000524 */  addiu      $a1, $zero, 0x1
  .L8006F448:
    /* 6C48 8006F448 0000A28F */  lw         $v0, 0x0($sp)
    /* 6C4C 8006F44C 00000000 */  nop
    /* 6C50 8006F450 FFFF4224 */  addiu      $v0, $v0, -0x1
    /* 6C54 8006F454 0000A2AF */  sw         $v0, 0x0($sp)
    /* 6C58 8006F458 0000A28F */  lw         $v0, 0x0($sp)
    /* 6C5C 8006F45C 00000000 */  nop
    /* 6C60 8006F460 10004014 */  bnez       $v0, .L8006F4A4
    /* 6C64 8006F464 00000000 */   nop
    /* 6C68 8006F468 2800828C */  lw         $v0, 0x28($a0)
    /* 6C6C 8006F46C 340085AC */  sw         $a1, 0x34($a0)
    /* 6C70 8006F470 0100422C */  sltiu      $v0, $v0, 0x1
    /* 6C74 8006F474 280082AC */  sw         $v0, 0x28($a0)
    /* 6C78 8006F478 C0100200 */  sll        $v0, $v0, 3
    /* 6C7C 8006F47C 21108200 */  addu       $v0, $a0, $v0
    /* 6C80 8006F480 18004394 */  lhu        $v1, 0x18($v0)
    /* 6C84 8006F484 2800828C */  lw         $v0, 0x28($a0)
    /* 6C88 8006F488 00000000 */  nop
    /* 6C8C 8006F48C C0100200 */  sll        $v0, $v0, 3
    /* 6C90 8006F490 21108200 */  addu       $v0, $a0, $v0
    /* 6C94 8006F494 2C0083A4 */  sh         $v1, 0x2C($a0)
    /* 6C98 8006F498 1A004294 */  lhu        $v0, 0x1A($v0)
    /* 6C9C 8006F49C 00000000 */  nop
    /* 6CA0 8006F4A0 2E0082A4 */  sh         $v0, 0x2E($a0)
  .L8006F4A4:
    /* 6CA4 8006F4A4 3400828C */  lw         $v0, 0x34($a0)
    /* 6CA8 8006F4A8 00000000 */  nop
    /* 6CAC 8006F4AC E6FF4010 */  beqz       $v0, .L8006F448
    /* 6CB0 8006F4B0 00000000 */   nop
  .L8006F4B4:
    /* 6CB4 8006F4B4 340080AC */  sw         $zero, 0x34($a0)
    /* 6CB8 8006F4B8 0800E003 */  jr         $ra
    /* 6CBC 8006F4BC 0800BD27 */   addiu     $sp, $sp, 0x8
endlabel _waitForFrame
