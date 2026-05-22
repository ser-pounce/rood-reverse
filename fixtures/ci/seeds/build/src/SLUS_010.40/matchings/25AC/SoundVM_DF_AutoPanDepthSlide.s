nonmatching SoundVM_DF_AutoPanDepthSlide, 0x6C

glabel SoundVM_DF_AutoPanDepthSlide
    /* C878 8001C078 0000858C */  lw         $a1, 0x0($a0)
    /* C87C 8001C07C 00000000 */  nop
    /* C880 8001C080 0000A690 */  lbu        $a2, 0x0($a1)
    /* C884 8001C084 0100A524 */  addiu      $a1, $a1, 0x1
    /* C888 8001C088 0200C014 */  bnez       $a2, .L8001C094
    /* C88C 8001C08C 000085AC */   sw        $a1, 0x0($a0)
    /* C890 8001C090 00010624 */  addiu      $a2, $zero, 0x100
  .L8001C094:
    /* C894 8001C094 0000A290 */  lbu        $v0, 0x0($a1)
    /* C898 8001C098 C6008394 */  lhu        $v1, 0xC6($a0)
    /* C89C 8001C09C C0110200 */  sll        $v0, $v0, 7
    /* C8A0 8001C0A0 23104300 */  subu       $v0, $v0, $v1
    /* C8A4 8001C0A4 1A004600 */  div        $zero, $v0, $a2
    /* C8A8 8001C0A8 0200C014 */  bnez       $a2, .L8001C0B4
    /* C8AC 8001C0AC 00000000 */   nop
    /* C8B0 8001C0B0 0D000700 */  break      7
  .L8001C0B4:
    /* C8B4 8001C0B4 FFFF0124 */  addiu      $at, $zero, -0x1
    /* C8B8 8001C0B8 0400C114 */  bne        $a2, $at, .L8001C0CC
    /* C8BC 8001C0BC 0080013C */   lui       $at, (0x80000000 >> 16)
    /* C8C0 8001C0C0 02004114 */  bne        $v0, $at, .L8001C0CC
    /* C8C4 8001C0C4 00000000 */   nop
    /* C8C8 8001C0C8 0D000600 */  break      6
  .L8001C0CC:
    /* C8CC 8001C0CC 12100000 */  mflo       $v0
    /* C8D0 8001C0D0 C80086A4 */  sh         $a2, 0xC8($a0)
    /* C8D4 8001C0D4 0100A324 */  addiu      $v1, $a1, 0x1
    /* C8D8 8001C0D8 000083AC */  sw         $v1, 0x0($a0)
    /* C8DC 8001C0DC 0800E003 */  jr         $ra
    /* C8E0 8001C0E0 CA0082A4 */   sh        $v0, 0xCA($a0)
endlabel SoundVM_DF_AutoPanDepthSlide
