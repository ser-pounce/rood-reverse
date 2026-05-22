nonmatching SoundVM_DD_VibratoDepthSlide, 0x6C

glabel SoundVM_DD_VibratoDepthSlide
    /* C5F4 8001BDF4 0000858C */  lw         $a1, 0x0($a0)
    /* C5F8 8001BDF8 00000000 */  nop
    /* C5FC 8001BDFC 0000A690 */  lbu        $a2, 0x0($a1)
    /* C600 8001BE00 0100A524 */  addiu      $a1, $a1, 0x1
    /* C604 8001BE04 0200C014 */  bnez       $a2, .L8001BE10
    /* C608 8001BE08 000085AC */   sw        $a1, 0x0($a0)
    /* C60C 8001BE0C 00010624 */  addiu      $a2, $zero, 0x100
  .L8001BE10:
    /* C610 8001BE10 0000A290 */  lbu        $v0, 0x0($a1)
    /* C614 8001BE14 AA008394 */  lhu        $v1, 0xAA($a0)
    /* C618 8001BE18 00120200 */  sll        $v0, $v0, 8
    /* C61C 8001BE1C 23104300 */  subu       $v0, $v0, $v1
    /* C620 8001BE20 1A004600 */  div        $zero, $v0, $a2
    /* C624 8001BE24 0200C014 */  bnez       $a2, .L8001BE30
    /* C628 8001BE28 00000000 */   nop
    /* C62C 8001BE2C 0D000700 */  break      7
  .L8001BE30:
    /* C630 8001BE30 FFFF0124 */  addiu      $at, $zero, -0x1
    /* C634 8001BE34 0400C114 */  bne        $a2, $at, .L8001BE48
    /* C638 8001BE38 0080013C */   lui       $at, (0x80000000 >> 16)
    /* C63C 8001BE3C 02004114 */  bne        $v0, $at, .L8001BE48
    /* C640 8001BE40 00000000 */   nop
    /* C644 8001BE44 0D000600 */  break      6
  .L8001BE48:
    /* C648 8001BE48 12100000 */  mflo       $v0
    /* C64C 8001BE4C AC0086A4 */  sh         $a2, 0xAC($a0)
    /* C650 8001BE50 0100A324 */  addiu      $v1, $a1, 0x1
    /* C654 8001BE54 000083AC */  sw         $v1, 0x0($a0)
    /* C658 8001BE58 0800E003 */  jr         $ra
    /* C65C 8001BE5C AE0082A4 */   sh        $v0, 0xAE($a0)
endlabel SoundVM_DD_VibratoDepthSlide
