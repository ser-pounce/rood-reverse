nonmatching SoundVM_DC_FixNoteLength, 0x48

glabel SoundVM_DC_FixNoteLength
    /* D0E4 8001C8E4 0000828C */  lw         $v0, 0x0($a0)
    /* D0E8 8001C8E8 00000000 */  nop
    /* D0EC 8001C8EC 00004380 */  lb         $v1, 0x0($v0)
    /* D0F0 8001C8F0 01004224 */  addiu      $v0, $v0, 0x1
    /* D0F4 8001C8F4 0B006010 */  beqz       $v1, .L8001C924
    /* D0F8 8001C8F8 000082AC */   sw        $v0, 0x0($a0)
    /* D0FC 8001C8FC D4008284 */  lh         $v0, 0xD4($a0)
    /* D100 8001C900 00000000 */  nop
    /* D104 8001C904 21186200 */  addu       $v1, $v1, $v0
    /* D108 8001C908 0300601C */  bgtz       $v1, .L8001C918
    /* D10C 8001C90C 00016228 */   slti      $v0, $v1, 0x100
    /* D110 8001C910 49720008 */  j          .L8001C924
    /* D114 8001C914 01000324 */   addiu     $v1, $zero, 0x1
  .L8001C918:
    /* D118 8001C918 02004014 */  bnez       $v0, .L8001C924
    /* D11C 8001C91C 00000000 */   nop
    /* D120 8001C920 FF000324 */  addiu      $v1, $zero, 0xFF
  .L8001C924:
    /* D124 8001C924 0800E003 */  jr         $ra
    /* D128 8001C928 D60083A4 */   sh        $v1, 0xD6($a0)
endlabel SoundVM_DC_FixNoteLength
