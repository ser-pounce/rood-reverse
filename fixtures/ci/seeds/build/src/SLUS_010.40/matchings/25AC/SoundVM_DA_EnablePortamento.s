nonmatching SoundVM_DA_EnablePortamento, 0x38

glabel SoundVM_DA_EnablePortamento
    /* C398 8001BB98 0000828C */  lw         $v0, 0x0($a0)
    /* C39C 8001BB9C 00000000 */  nop
    /* C3A0 8001BBA0 00004390 */  lbu        $v1, 0x0($v0)
    /* C3A4 8001BBA4 01004224 */  addiu      $v0, $v0, 0x1
    /* C3A8 8001BBA8 000082AC */  sw         $v0, 0x0($a0)
    /* C3AC 8001BBAC 03006014 */  bnez       $v1, .L8001BBBC
    /* C3B0 8001BBB0 9A0083A4 */   sh        $v1, 0x9A($a0)
    /* C3B4 8001BBB4 00010224 */  addiu      $v0, $zero, 0x100
    /* C3B8 8001BBB8 9A0082A4 */  sh         $v0, 0x9A($a0)
  .L8001BBBC:
    /* C3BC 8001BBBC 01000224 */  addiu      $v0, $zero, 0x1
    /* C3C0 8001BBC0 EA0080A4 */  sh         $zero, 0xEA($a0)
    /* C3C4 8001BBC4 980080A4 */  sh         $zero, 0x98($a0)
    /* C3C8 8001BBC8 0800E003 */  jr         $ra
    /* C3CC 8001BBCC 9C0082A4 */   sh        $v0, 0x9C($a0)
endlabel SoundVM_DA_EnablePortamento
