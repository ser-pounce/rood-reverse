nonmatching SoundVM_D8_ChannelFineTune_Absolute, 0x60

glabel SoundVM_D8_ChannelFineTune_Absolute
    /* C3D8 8001BBD8 0000828C */  lw         $v0, 0x0($a0)
    /* C3DC 8001BBDC 00000000 */  nop
    /* C3E0 8001BBE0 00004390 */  lbu        $v1, 0x0($v0)
    /* C3E4 8001BBE4 2C00858C */  lw         $a1, 0x2C($a0)
    /* C3E8 8001BBE8 001E0300 */  sll        $v1, $v1, 24
    /* C3EC 8001BBEC 031E0300 */  sra        $v1, $v1, 24
    /* C3F0 8001BBF0 E40083A4 */  sh         $v1, 0xE4($a0)
    /* C3F4 8001BBF4 E4008390 */  lbu        $v1, 0xE4($a0)
    /* C3F8 8001BBF8 00000000 */  nop
    /* C3FC 8001BBFC 1800A300 */  mult       $a1, $v1
    /* C400 8001BC00 01004224 */  addiu      $v0, $v0, 0x1
    /* C404 8001BC04 000082AC */  sw         $v0, 0x0($a0)
    /* C408 8001BC08 E4008284 */  lh         $v0, 0xE4($a0)
    /* C40C 8001BC0C 12180000 */  mflo       $v1
    /* C410 8001BC10 03004104 */  bgez       $v0, .L8001BC20
    /* C414 8001BC14 02120300 */   srl       $v0, $v1, 8
    /* C418 8001BC18 096F0008 */  j          .L8001BC24
    /* C41C 8001BC1C 23184500 */   subu      $v1, $v0, $a1
  .L8001BC20:
    /* C420 8001BC20 C2190300 */  srl        $v1, $v1, 7
  .L8001BC24:
    /* C424 8001BC24 F800828C */  lw         $v0, 0xF8($a0)
    /* C428 8001BC28 540083AC */  sw         $v1, 0x54($a0)
    /* C42C 8001BC2C 10004234 */  ori        $v0, $v0, 0x10
    /* C430 8001BC30 0800E003 */  jr         $ra
    /* C434 8001BC34 F80082AC */   sw        $v0, 0xF8($a0)
endlabel SoundVM_D8_ChannelFineTune_Absolute
