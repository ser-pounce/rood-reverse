nonmatching _decode, 0x38

glabel _decode
    /* 75C 80068F5C 0B00C010 */  beqz       $a2, .L80068F8C
    /* 760 80068F60 1900073C */   lui       $a3, (0x19660D >> 16)
    /* 764 80068F64 0D66E734 */  ori        $a3, $a3, (0x19660D & 0xFFFF)
  .L80068F68:
    /* 768 80068F68 18008700 */  mult       $a0, $a3
    /* 76C 80068F6C FFFFC624 */  addiu      $a2, $a2, -0x1
    /* 770 80068F70 0000A290 */  lbu        $v0, 0x0($a1)
    /* 774 80068F74 12200000 */  mflo       $a0
    /* 778 80068F78 021E0400 */  srl        $v1, $a0, 24
    /* 77C 80068F7C 23104300 */  subu       $v0, $v0, $v1
    /* 780 80068F80 0000A2A0 */  sb         $v0, 0x0($a1)
    /* 784 80068F84 F8FFC014 */  bnez       $a2, .L80068F68
    /* 788 80068F88 0100A524 */   addiu     $a1, $a1, 0x1
  .L80068F8C:
    /* 78C 80068F8C 0800E003 */  jr         $ra
    /* 790 80068F90 00000000 */   nop
endlabel _decode
