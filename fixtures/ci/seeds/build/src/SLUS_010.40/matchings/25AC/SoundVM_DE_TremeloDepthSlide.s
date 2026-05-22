nonmatching SoundVM_DE_TremeloDepthSlide, 0x70

glabel SoundVM_DE_TremeloDepthSlide
    /* C758 8001BF58 0000858C */  lw         $a1, 0x0($a0)
    /* C75C 8001BF5C 00000000 */  nop
    /* C760 8001BF60 0000A690 */  lbu        $a2, 0x0($a1)
    /* C764 8001BF64 0100A524 */  addiu      $a1, $a1, 0x1
    /* C768 8001BF68 0200C014 */  bnez       $a2, .L8001BF74
    /* C76C 8001BF6C 000085AC */   sw        $a1, 0x0($a0)
    /* C770 8001BF70 00010624 */  addiu      $a2, $zero, 0x100
  .L8001BF74:
    /* C774 8001BF74 0000A290 */  lbu        $v0, 0x0($a1)
    /* C778 8001BF78 BA008394 */  lhu        $v1, 0xBA($a0)
    /* C77C 8001BF7C 7F004230 */  andi       $v0, $v0, 0x7F
    /* C780 8001BF80 00120200 */  sll        $v0, $v0, 8
    /* C784 8001BF84 23104300 */  subu       $v0, $v0, $v1
    /* C788 8001BF88 1A004600 */  div        $zero, $v0, $a2
    /* C78C 8001BF8C 0200C014 */  bnez       $a2, .L8001BF98
    /* C790 8001BF90 00000000 */   nop
    /* C794 8001BF94 0D000700 */  break      7
  .L8001BF98:
    /* C798 8001BF98 FFFF0124 */  addiu      $at, $zero, -0x1
    /* C79C 8001BF9C 0400C114 */  bne        $a2, $at, .L8001BFB0
    /* C7A0 8001BFA0 0080013C */   lui       $at, (0x80000000 >> 16)
    /* C7A4 8001BFA4 02004114 */  bne        $v0, $at, .L8001BFB0
    /* C7A8 8001BFA8 00000000 */   nop
    /* C7AC 8001BFAC 0D000600 */  break      6
  .L8001BFB0:
    /* C7B0 8001BFB0 12100000 */  mflo       $v0
    /* C7B4 8001BFB4 BC0086A4 */  sh         $a2, 0xBC($a0)
    /* C7B8 8001BFB8 0100A324 */  addiu      $v1, $a1, 0x1
    /* C7BC 8001BFBC 000083AC */  sw         $v1, 0x0($a0)
    /* C7C0 8001BFC0 0800E003 */  jr         $ra
    /* C7C4 8001BFC4 BE0082A4 */   sh        $v0, 0xBE($a0)
endlabel SoundVM_DE_TremeloDepthSlide
