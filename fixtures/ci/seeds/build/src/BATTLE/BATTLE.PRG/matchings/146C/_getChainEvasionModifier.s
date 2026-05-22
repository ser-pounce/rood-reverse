nonmatching _getChainEvasionModifier, 0x8C

glabel _getChainEvasionModifier
    /* 169A4 8007F1A4 8080053C */  lui        $a1, (0x80808081 >> 16)
    /* 169A8 8007F1A8 8180A534 */  ori        $a1, $a1, (0x80808081 & 0xFFFF)
    /* 169AC 8007F1AC 0F80023C */  lui        $v0, %hi(vs_battle_actors)
    /* 169B0 8007F1B0 28194224 */  addiu      $v0, $v0, %lo(vs_battle_actors)
    /* 169B4 8007F1B4 0000C390 */  lbu        $v1, 0x0($a2)
    /* 169B8 8007F1B8 0100C480 */  lb         $a0, 0x1($a2)
    /* 169BC 8007F1BC 80180300 */  sll        $v1, $v1, 2
    /* 169C0 8007F1C0 21186200 */  addu       $v1, $v1, $v0
    /* 169C4 8007F1C4 C0100400 */  sll        $v0, $a0, 3
    /* 169C8 8007F1C8 23104400 */  subu       $v0, $v0, $a0
    /* 169CC 8007F1CC C0100200 */  sll        $v0, $v0, 3
    /* 169D0 8007F1D0 0000638C */  lw         $v1, 0x0($v1)
    /* 169D4 8007F1D4 23104400 */  subu       $v0, $v0, $a0
    /* 169D8 8007F1D8 3C00638C */  lw         $v1, 0x3C($v1)
    /* 169DC 8007F1DC 80100200 */  sll        $v0, $v0, 2
    /* 169E0 8007F1E0 21186200 */  addu       $v1, $v1, $v0
    /* 169E4 8007F1E4 9F036390 */  lbu        $v1, 0x39F($v1)
    /* 169E8 8007F1E8 FF000424 */  addiu      $a0, $zero, 0xFF
    /* 169EC 8007F1EC 23188300 */  subu       $v1, $a0, $v1
    /* 169F0 8007F1F0 40100300 */  sll        $v0, $v1, 1
    /* 169F4 8007F1F4 21104300 */  addu       $v0, $v0, $v1
    /* 169F8 8007F1F8 C0100200 */  sll        $v0, $v0, 3
    /* 169FC 8007F1FC 21104300 */  addu       $v0, $v0, $v1
    /* 16A00 8007F200 80100200 */  sll        $v0, $v0, 2
    /* 16A04 8007F204 18004500 */  mult       $v0, $a1
    /* 16A08 8007F208 10380000 */  mfhi       $a3
    /* 16A0C 8007F20C 2118E200 */  addu       $v1, $a3, $v0
    /* 16A10 8007F210 C3190300 */  sra        $v1, $v1, 7
    /* 16A14 8007F214 C3170200 */  sra        $v0, $v0, 31
    /* 16A18 8007F218 23106200 */  subu       $v0, $v1, $v0
    /* 16A1C 8007F21C 02004414 */  bne        $v0, $a0, .L8007F228
    /* 16A20 8007F220 00000000 */   nop
    /* 16A24 8007F224 FE000224 */  addiu      $v0, $zero, 0xFE
  .L8007F228:
    /* 16A28 8007F228 0800E003 */  jr         $ra
    /* 16A2C 8007F22C 00000000 */   nop
endlabel _getChainEvasionModifier
