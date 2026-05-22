nonmatching _padCmdParaMode, 0x20

glabel _padCmdParaMode
    /* 1DDE8 8002D5E8 43000224 */  addiu      $v0, $zero, 0x43
    /* 1DDEC 8002D5EC 370082A0 */  sb         $v0, 0x37($a0)
    /* 1DDF0 8002D5F0 24008224 */  addiu      $v0, $a0, 0x24
    /* 1DDF4 8002D5F4 2C0082AC */  sw         $v0, 0x2C($a0)
    /* 1DDF8 8002D5F8 01000224 */  addiu      $v0, $zero, 0x1
    /* 1DDFC 8002D5FC 240085A0 */  sb         $a1, 0x24($a0)
    /* 1DE00 8002D600 0800E003 */  jr         $ra
    /* 1DE04 8002D604 360082A0 */   sb        $v0, 0x36($a0)
endlabel _padCmdParaMode
