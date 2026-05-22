nonmatching _spu_FiDMA, 0xBC

glabel _spu_FiDMA
    /* E694 8001DE94 0380023C */  lui        $v0, %hi(D_800308B0)
    /* E698 8001DE98 B008428C */  lw         $v0, %lo(D_800308B0)($v0)
    /* E69C 8001DE9C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* E6A0 8001DEA0 03004014 */  bnez       $v0, .L8001DEB0
    /* E6A4 8001DEA4 1000BFAF */   sw        $ra, 0x10($sp)
    /* E6A8 8001DEA8 4B79000C */  jal        _spu_Fw1ts
    /* E6AC 8001DEAC 00000000 */   nop
  .L8001DEB0:
    /* E6B0 8001DEB0 0380043C */  lui        $a0, %hi(D_80030860)
    /* E6B4 8001DEB4 6008848C */  lw         $a0, %lo(D_80030860)($a0)
    /* E6B8 8001DEB8 00000000 */  nop
    /* E6BC 8001DEBC AA018294 */  lhu        $v0, 0x1AA($a0)
    /* E6C0 8001DEC0 00000000 */  nop
    /* E6C4 8001DEC4 CFFF4230 */  andi       $v0, $v0, 0xFFCF
    /* E6C8 8001DEC8 AA0182A4 */  sh         $v0, 0x1AA($a0)
    /* E6CC 8001DECC AA018294 */  lhu        $v0, 0x1AA($a0)
    /* E6D0 8001DED0 00000000 */  nop
    /* E6D4 8001DED4 30004230 */  andi       $v0, $v0, 0x30
    /* E6D8 8001DED8 0A004010 */  beqz       $v0, .L8001DF04
    /* E6DC 8001DEDC 21180000 */   addu      $v1, $zero, $zero
    /* E6E0 8001DEE0 01006324 */  addiu      $v1, $v1, 0x1
  .L8001DEE4:
    /* E6E4 8001DEE4 010F622C */  sltiu      $v0, $v1, 0xF01
    /* E6E8 8001DEE8 06004010 */  beqz       $v0, .L8001DF04
    /* E6EC 8001DEEC 00000000 */   nop
    /* E6F0 8001DEF0 AA018294 */  lhu        $v0, 0x1AA($a0)
    /* E6F4 8001DEF4 00000000 */  nop
    /* E6F8 8001DEF8 30004230 */  andi       $v0, $v0, 0x30
    /* E6FC 8001DEFC F9FF4014 */  bnez       $v0, .L8001DEE4
    /* E700 8001DF00 01006324 */   addiu     $v1, $v1, 0x1
  .L8001DF04:
    /* E704 8001DF04 0380023C */  lui        $v0, %hi(D_80030898)
    /* E708 8001DF08 9808428C */  lw         $v0, %lo(D_80030898)($v0)
    /* E70C 8001DF0C 00000000 */  nop
    /* E710 8001DF10 08004010 */  beqz       $v0, .L8001DF34
    /* E714 8001DF14 00F0043C */   lui       $a0, (0xF0000009 >> 16)
    /* E718 8001DF18 0380023C */  lui        $v0, %hi(D_80030898)
    /* E71C 8001DF1C 9808428C */  lw         $v0, %lo(D_80030898)($v0)
    /* E720 8001DF20 00000000 */  nop
    /* E724 8001DF24 09F84000 */  jalr       $v0
    /* E728 8001DF28 00000000 */   nop
    /* E72C 8001DF2C D0770008 */  j          .L8001DF40
    /* E730 8001DF30 00000000 */   nop
  .L8001DF34:
    /* E734 8001DF34 09008434 */  ori        $a0, $a0, (0xF0000009 & 0xFFFF)
    /* E738 8001DF38 319A000C */  jal        DeliverEvent
    /* E73C 8001DF3C 20000524 */   addiu     $a1, $zero, 0x20
  .L8001DF40:
    /* E740 8001DF40 1000BF8F */  lw         $ra, 0x10($sp)
    /* E744 8001DF44 1800BD27 */  addiu      $sp, $sp, 0x18
    /* E748 8001DF48 0800E003 */  jr         $ra
    /* E74C 8001DF4C 00000000 */   nop
endlabel _spu_FiDMA
