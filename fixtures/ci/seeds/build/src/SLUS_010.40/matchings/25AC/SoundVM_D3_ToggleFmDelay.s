nonmatching SoundVM_D3_ToggleFmDelay, 0x30

glabel SoundVM_D3_ToggleFmDelay
    /* D2E4 8001CAE4 0000828C */  lw         $v0, 0x0($a0)
    /* D2E8 8001CAE8 00000000 */  nop
    /* D2EC 8001CAEC 00004390 */  lbu        $v1, 0x0($v0)
    /* D2F0 8001CAF0 01004224 */  addiu      $v0, $v0, 0x1
    /* D2F4 8001CAF4 04006010 */  beqz       $v1, .L8001CB08
    /* D2F8 8001CAF8 000082AC */   sw        $v0, 0x0($a0)
    /* D2FC 8001CAFC 01006224 */  addiu      $v0, $v1, 0x1
    /* D300 8001CB00 0800E003 */  jr         $ra
    /* D304 8001CB04 CE0082A4 */   sh        $v0, 0xCE($a0)
  .L8001CB08:
    /* D308 8001CB08 01010224 */  addiu      $v0, $zero, 0x101
    /* D30C 8001CB0C 0800E003 */  jr         $ra
    /* D310 8001CB10 CE0082A4 */   sh        $v0, 0xCE($a0)
endlabel SoundVM_D3_ToggleFmDelay
