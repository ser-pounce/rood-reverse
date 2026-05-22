nonmatching SoundVM_CF_ToggleNoiseOnDelay, 0x30

glabel SoundVM_CF_ToggleNoiseOnDelay
    /* D270 8001CA70 0000828C */  lw         $v0, 0x0($a0)
    /* D274 8001CA74 00000000 */  nop
    /* D278 8001CA78 00004390 */  lbu        $v1, 0x0($v0)
    /* D27C 8001CA7C 01004224 */  addiu      $v0, $v0, 0x1
    /* D280 8001CA80 04006010 */  beqz       $v1, .L8001CA94
    /* D284 8001CA84 000082AC */   sw        $v0, 0x0($a0)
    /* D288 8001CA88 01006224 */  addiu      $v0, $v1, 0x1
    /* D28C 8001CA8C 0800E003 */  jr         $ra
    /* D290 8001CA90 CC0082A4 */   sh        $v0, 0xCC($a0)
  .L8001CA94:
    /* D294 8001CA94 01010224 */  addiu      $v0, $zero, 0x101
    /* D298 8001CA98 0800E003 */  jr         $ra
    /* D29C 8001CA9C CC0082A4 */   sh        $v0, 0xCC($a0)
endlabel SoundVM_CF_ToggleNoiseOnDelay
