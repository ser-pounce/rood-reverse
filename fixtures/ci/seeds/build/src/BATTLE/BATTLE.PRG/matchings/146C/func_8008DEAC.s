nonmatching func_8008DEAC, 0x68

glabel func_8008DEAC
    /* 256AC 8008DEAC 16008014 */  bnez       $a0, .L8008DF08
    /* 256B0 8008DEB0 0F80023C */   lui       $v0, %hi(vs_battle_roomData)
    /* 256B4 8008DEB4 F81B4224 */  addiu      $v0, $v0, %lo(vs_battle_roomData)
    /* 256B8 8008DEB8 8400468C */  lw         $a2, 0x84($v0)
    /* 256BC 8008DEBC 00000000 */  nop
    /* 256C0 8008DEC0 1200C010 */  beqz       $a2, .L8008DF0C
    /* 256C4 8008DEC4 00000000 */   nop
    /* 256C8 8008DEC8 2400438C */  lw         $v1, 0x24($v0)
    /* 256CC 8008DECC AAAA023C */  lui        $v0, (0xAAAAAAAB >> 16)
    /* 256D0 8008DED0 ABAA4234 */  ori        $v0, $v0, (0xAAAAAAAB & 0xFFFF)
    /* 256D4 8008DED4 19006200 */  multu      $v1, $v0
    /* 256D8 8008DED8 10400000 */  mfhi       $t0
    /* 256DC 8008DEDC C2380800 */  srl        $a3, $t0, 3
    /* 256E0 8008DEE0 2A108700 */  slt        $v0, $a0, $a3
    /* 256E4 8008DEE4 06004010 */  beqz       $v0, .L8008DF00
    /* 256E8 8008DEE8 21180000 */   addu      $v1, $zero, $zero
  .L8008DEEC:
    /* 256EC 8008DEEC 0A00C5A0 */  sb         $a1, 0xA($a2)
    /* 256F0 8008DEF0 01006324 */  addiu      $v1, $v1, 0x1
    /* 256F4 8008DEF4 2A106700 */  slt        $v0, $v1, $a3
    /* 256F8 8008DEF8 FCFF4014 */  bnez       $v0, .L8008DEEC
    /* 256FC 8008DEFC 0C00C624 */   addiu     $a2, $a2, 0xC
  .L8008DF00:
    /* 25700 8008DF00 0800E003 */  jr         $ra
    /* 25704 8008DF04 00000000 */   nop
  .L8008DF08:
    /* 25708 8008DF08 0A0085A0 */  sb         $a1, 0xA($a0)
  .L8008DF0C:
    /* 2570C 8008DF0C 0800E003 */  jr         $ra
    /* 25710 8008DF10 00000000 */   nop
endlabel func_8008DEAC
