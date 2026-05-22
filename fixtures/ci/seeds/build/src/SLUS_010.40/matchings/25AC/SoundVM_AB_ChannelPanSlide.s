nonmatching SoundVM_AB_ChannelPanSlide, 0x8C

glabel SoundVM_AB_ChannelPanSlide
    /* C038 8001B838 21308000 */  addu       $a2, $a0, $zero
    /* C03C 8001B83C 0000C28C */  lw         $v0, 0x0($a2)
    /* C040 8001B840 00000000 */  nop
    /* C044 8001B844 00004390 */  lbu        $v1, 0x0($v0)
    /* C048 8001B848 01004224 */  addiu      $v0, $v0, 0x1
    /* C04C 8001B84C 0000C2AC */  sw         $v0, 0x0($a2)
    /* C050 8001B850 03006014 */  bnez       $v1, .L8001B860
    /* C054 8001B854 9000C3A4 */   sh        $v1, 0x90($a2)
    /* C058 8001B858 00010224 */  addiu      $v0, $zero, 0x100
    /* C05C 8001B85C 9000C2A4 */  sh         $v0, 0x90($a2)
  .L8001B860:
    /* C060 8001B860 0000C58C */  lw         $a1, 0x0($a2)
    /* C064 8001B864 8E00C494 */  lhu        $a0, 0x8E($a2)
    /* C068 8001B868 9000C394 */  lhu        $v1, 0x90($a2)
    /* C06C 8001B86C 0000A290 */  lbu        $v0, 0x0($a1)
    /* C070 8001B870 00FF8430 */  andi       $a0, $a0, 0xFF00
    /* C074 8001B874 40004224 */  addiu      $v0, $v0, 0x40
    /* C078 8001B878 FF004230 */  andi       $v0, $v0, 0xFF
    /* C07C 8001B87C 00120200 */  sll        $v0, $v0, 8
    /* C080 8001B880 23104400 */  subu       $v0, $v0, $a0
    /* C084 8001B884 1A004300 */  div        $zero, $v0, $v1
    /* C088 8001B888 02006014 */  bnez       $v1, .L8001B894
    /* C08C 8001B88C 00000000 */   nop
    /* C090 8001B890 0D000700 */  break      7
  .L8001B894:
    /* C094 8001B894 FFFF0124 */  addiu      $at, $zero, -0x1
    /* C098 8001B898 04006114 */  bne        $v1, $at, .L8001B8AC
    /* C09C 8001B89C 0080013C */   lui       $at, (0x80000000 >> 16)
    /* C0A0 8001B8A0 02004114 */  bne        $v0, $at, .L8001B8AC
    /* C0A4 8001B8A4 00000000 */   nop
    /* C0A8 8001B8A8 0D000600 */  break      6
  .L8001B8AC:
    /* C0AC 8001B8AC 12100000 */  mflo       $v0
    /* C0B0 8001B8B0 0100A524 */  addiu      $a1, $a1, 0x1
    /* C0B4 8001B8B4 0000C5AC */  sw         $a1, 0x0($a2)
    /* C0B8 8001B8B8 8E00C4A4 */  sh         $a0, 0x8E($a2)
    /* C0BC 8001B8BC 0800E003 */  jr         $ra
    /* C0C0 8001B8C0 E000C2A4 */   sh        $v0, 0xE0($a2)
endlabel SoundVM_AB_ChannelPanSlide
