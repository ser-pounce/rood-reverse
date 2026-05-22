nonmatching SoundVM_D9_ChannelFineTune_Relative, 0x64

glabel SoundVM_D9_ChannelFineTune_Relative
    /* C438 8001BC38 0000828C */  lw         $v0, 0x0($a0)
    /* C43C 8001BC3C 2C00858C */  lw         $a1, 0x2C($a0)
    /* C440 8001BC40 00004390 */  lbu        $v1, 0x0($v0)
    /* C444 8001BC44 01004224 */  addiu      $v0, $v0, 0x1
    /* C448 8001BC48 000082AC */  sw         $v0, 0x0($a0)
    /* C44C 8001BC4C E4008294 */  lhu        $v0, 0xE4($a0)
    /* C450 8001BC50 001E0300 */  sll        $v1, $v1, 24
    /* C454 8001BC54 031E0300 */  sra        $v1, $v1, 24
    /* C458 8001BC58 21104300 */  addu       $v0, $v0, $v1
    /* C45C 8001BC5C E40082A4 */  sh         $v0, 0xE4($a0)
    /* C460 8001BC60 E4008390 */  lbu        $v1, 0xE4($a0)
    /* C464 8001BC64 00000000 */  nop
    /* C468 8001BC68 1800A300 */  mult       $a1, $v1
    /* C46C 8001BC6C E4008284 */  lh         $v0, 0xE4($a0)
    /* C470 8001BC70 12180000 */  mflo       $v1
    /* C474 8001BC74 03004104 */  bgez       $v0, .L8001BC84
    /* C478 8001BC78 02120300 */   srl       $v0, $v1, 8
    /* C47C 8001BC7C 226F0008 */  j          .L8001BC88
    /* C480 8001BC80 23184500 */   subu      $v1, $v0, $a1
  .L8001BC84:
    /* C484 8001BC84 C2190300 */  srl        $v1, $v1, 7
  .L8001BC88:
    /* C488 8001BC88 F800828C */  lw         $v0, 0xF8($a0)
    /* C48C 8001BC8C 540083AC */  sw         $v1, 0x54($a0)
    /* C490 8001BC90 10004234 */  ori        $v0, $v0, 0x10
    /* C494 8001BC94 0800E003 */  jr         $ra
    /* C498 8001BC98 F80082AC */   sw        $v0, 0xF8($a0)
endlabel SoundVM_D9_ChannelFineTune_Relative
