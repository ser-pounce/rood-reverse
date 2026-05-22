nonmatching _decode, 0x38

glabel _decode
    /* 6BC 80102EBC 0B00C010 */  beqz       $a2, .L80102EEC
    /* 6C0 80102EC0 1900073C */   lui       $a3, (0x19660D >> 16)
    /* 6C4 80102EC4 0D66E734 */  ori        $a3, $a3, (0x19660D & 0xFFFF)
  .L80102EC8:
    /* 6C8 80102EC8 18008700 */  mult       $a0, $a3
    /* 6CC 80102ECC FFFFC624 */  addiu      $a2, $a2, -0x1
    /* 6D0 80102ED0 0000A290 */  lbu        $v0, 0x0($a1)
    /* 6D4 80102ED4 12200000 */  mflo       $a0
    /* 6D8 80102ED8 021E0400 */  srl        $v1, $a0, 24
    /* 6DC 80102EDC 23104300 */  subu       $v0, $v0, $v1
    /* 6E0 80102EE0 0000A2A0 */  sb         $v0, 0x0($a1)
    /* 6E4 80102EE4 F8FFC014 */  bnez       $a2, .L80102EC8
    /* 6E8 80102EE8 0100A524 */   addiu     $a1, $a1, 0x1
  .L80102EEC:
    /* 6EC 80102EEC 0800E003 */  jr         $ra
    /* 6F0 80102EF0 00000000 */   nop
endlabel _decode
