nonmatching vs_battle_getTextLineLength, 0xE8

glabel vs_battle_getTextLineLength
    /* 5E810 800C7010 21280000 */  addu       $a1, $zero, $zero
    /* 5E814 800C7014 0F80023C */  lui        $v0, %hi(vs_battle_characterWidths)
    /* 5E818 800C7018 10B84724 */  addiu      $a3, $v0, %lo(vs_battle_characterWidths)
    /* 5E81C 800C701C E5000624 */  addiu      $a2, $zero, 0xE5
  .L800C7020:
    /* 5E820 800C7020 00008290 */  lbu        $v0, 0x0($a0)
    /* 5E824 800C7024 00000000 */  nop
    /* 5E828 800C7028 FF004330 */  andi       $v1, $v0, 0xFF
    /* 5E82C 800C702C E500622C */  sltiu      $v0, $v1, 0xE5
    /* 5E830 800C7030 05004010 */  beqz       $v0, .L800C7048
    /* 5E834 800C7034 01008424 */   addiu     $a0, $a0, 0x1
    /* 5E838 800C7038 21106700 */  addu       $v0, $v1, $a3
    /* 5E83C 800C703C 00004290 */  lbu        $v0, 0x0($v0)
    /* 5E840 800C7040 081C0308 */  j          .L800C7020
    /* 5E844 800C7044 2128A200 */   addu      $a1, $a1, $v0
  .L800C7048:
    /* 5E848 800C7048 07006610 */  beq        $v1, $a2, .L800C7068
    /* 5E84C 800C704C AA2A023C */   lui       $v0, (0x2AAAAAAB >> 16)
    /* 5E850 800C7050 E7000224 */  addiu      $v0, $zero, 0xE7
    /* 5E854 800C7054 04006210 */  beq        $v1, $v0, .L800C7068
    /* 5E858 800C7058 AA2A023C */   lui       $v0, (0x2AAAAAAB >> 16)
    /* 5E85C 800C705C E8000224 */  addiu      $v0, $zero, 0xE8
    /* 5E860 800C7060 07006214 */  bne        $v1, $v0, .L800C7080
    /* 5E864 800C7064 AA2A023C */   lui       $v0, (0x2AAAAAAB >> 16)
  .L800C7068:
    /* 5E868 800C7068 ABAA4234 */  ori        $v0, $v0, (0x2AAAAAAB & 0xFFFF)
    /* 5E86C 800C706C 1800A200 */  mult       $a1, $v0
    /* 5E870 800C7070 C3170500 */  sra        $v0, $a1, 31
    /* 5E874 800C7074 10400000 */  mfhi       $t0
    /* 5E878 800C7078 0800E003 */  jr         $ra
    /* 5E87C 800C707C 23100201 */   subu      $v0, $t0, $v0
  .L800C7080:
    /* 5E880 800C7080 FA000224 */  addiu      $v0, $zero, 0xFA
    /* 5E884 800C7084 05006214 */  bne        $v1, $v0, .L800C709C
    /* 5E888 800C7088 FE000224 */   addiu     $v0, $zero, 0xFE
    /* 5E88C 800C708C 00008290 */  lbu        $v0, 0x0($a0)
    /* 5E890 800C7090 01008424 */  addiu      $a0, $a0, 0x1
    /* 5E894 800C7094 081C0308 */  j          .L800C7020
    /* 5E898 800C7098 2128A200 */   addu      $a1, $a1, $v0
  .L800C709C:
    /* 5E89C 800C709C 12006214 */  bne        $v1, $v0, .L800C70E8
    /* 5E8A0 800C70A0 F800622C */   sltiu     $v0, $v1, 0xF8
    /* 5E8A4 800C70A4 00008290 */  lbu        $v0, 0x0($a0)
    /* 5E8A8 800C70A8 00000000 */  nop
    /* 5E8AC 800C70AC FF004330 */  andi       $v1, $v0, 0xFF
    /* 5E8B0 800C70B0 0A00622C */  sltiu      $v0, $v1, 0xA
    /* 5E8B4 800C70B4 DAFF4014 */  bnez       $v0, .L800C7020
    /* 5E8B8 800C70B8 01008424 */   addiu     $a0, $a0, 0x1
    /* 5E8BC 800C70BC CCCC023C */  lui        $v0, (0xCCCCCCCD >> 16)
    /* 5E8C0 800C70C0 CDCC4234 */  ori        $v0, $v0, (0xCCCCCCCD & 0xFFFF)
    /* 5E8C4 800C70C4 19006200 */  multu      $v1, $v0
    /* 5E8C8 800C70C8 10400000 */  mfhi       $t0
    /* 5E8CC 800C70CC C2180800 */  srl        $v1, $t0, 3
    /* 5E8D0 800C70D0 FF006330 */  andi       $v1, $v1, 0xFF
    /* 5E8D4 800C70D4 40100300 */  sll        $v0, $v1, 1
    /* 5E8D8 800C70D8 21104300 */  addu       $v0, $v0, $v1
    /* 5E8DC 800C70DC 40100200 */  sll        $v0, $v0, 1
    /* 5E8E0 800C70E0 081C0308 */  j          .L800C7020
    /* 5E8E4 800C70E4 2128A200 */   addu      $a1, $a1, $v0
  .L800C70E8:
    /* 5E8E8 800C70E8 CDFF4014 */  bnez       $v0, .L800C7020
    /* 5E8EC 800C70EC 00000000 */   nop
    /* 5E8F0 800C70F0 081C0308 */  j          .L800C7020
    /* 5E8F4 800C70F4 01008424 */   addiu     $a0, $a0, 0x1
endlabel vs_battle_getTextLineLength
