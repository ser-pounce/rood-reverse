nonmatching SoundVM_unused2, 0x8C

glabel SoundVM_unused2
    /* BF78 8001B778 21388000 */  addu       $a3, $a0, $zero
    /* BF7C 8001B77C 0000E28C */  lw         $v0, 0x0($a3)
    /* BF80 8001B780 00000000 */  nop
    /* BF84 8001B784 00004390 */  lbu        $v1, 0x0($v0)
    /* BF88 8001B788 01004224 */  addiu      $v0, $v0, 0x1
    /* BF8C 8001B78C 0000E2AC */  sw         $v0, 0x0($a3)
    /* BF90 8001B790 03006014 */  bnez       $v1, .L8001B7A0
    /* BF94 8001B794 8C00E3A4 */   sh        $v1, 0x8C($a3)
    /* BF98 8001B798 00010224 */  addiu      $v0, $zero, 0x100
    /* BF9C 8001B79C 8C00E2A4 */  sh         $v0, 0x8C($a3)
  .L8001B7A0:
    /* BFA0 8001B7A0 0000E68C */  lw         $a2, 0x0($a3)
    /* BFA4 8001B7A4 DC00E594 */  lhu        $a1, 0xDC($a3)
    /* BFA8 8001B7A8 8C00E494 */  lhu        $a0, 0x8C($a3)
    /* BFAC 8001B7AC 00FFA530 */  andi       $a1, $a1, 0xFF00
    /* BFB0 8001B7B0 00140500 */  sll        $v0, $a1, 16
    /* BFB4 8001B7B4 0000C390 */  lbu        $v1, 0x0($a2)
    /* BFB8 8001B7B8 03140200 */  sra        $v0, $v0, 16
    /* BFBC 8001B7BC 001A0300 */  sll        $v1, $v1, 8
    /* BFC0 8001B7C0 23186200 */  subu       $v1, $v1, $v0
    /* BFC4 8001B7C4 1A006400 */  div        $zero, $v1, $a0
    /* BFC8 8001B7C8 02008014 */  bnez       $a0, .L8001B7D4
    /* BFCC 8001B7CC 00000000 */   nop
    /* BFD0 8001B7D0 0D000700 */  break      7
  .L8001B7D4:
    /* BFD4 8001B7D4 FFFF0124 */  addiu      $at, $zero, -0x1
    /* BFD8 8001B7D8 04008114 */  bne        $a0, $at, .L8001B7EC
    /* BFDC 8001B7DC 0080013C */   lui       $at, (0x80000000 >> 16)
    /* BFE0 8001B7E0 02006114 */  bne        $v1, $at, .L8001B7EC
    /* BFE4 8001B7E4 00000000 */   nop
    /* BFE8 8001B7E8 0D000600 */  break      6
  .L8001B7EC:
    /* BFEC 8001B7EC 12180000 */  mflo       $v1
    /* BFF0 8001B7F0 0100C624 */  addiu      $a2, $a2, 0x1
    /* BFF4 8001B7F4 0000E6AC */  sw         $a2, 0x0($a3)
    /* BFF8 8001B7F8 DC00E5A4 */  sh         $a1, 0xDC($a3)
    /* BFFC 8001B7FC 0800E003 */  jr         $ra
    /* C000 8001B800 DE00E3A4 */   sh        $v1, 0xDE($a3)
endlabel SoundVM_unused2
