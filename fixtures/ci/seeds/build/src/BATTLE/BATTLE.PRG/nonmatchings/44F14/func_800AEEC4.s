nonmatching func_800AEEC4, 0xD0

glabel func_800AEEC4
    /* 466C4 800AEEC4 E4178390 */  lbu        $v1, 0x17E4($a0)
    /* 466C8 800AEEC8 01000224 */  addiu      $v0, $zero, 0x1
    /* 466CC 800AEECC 2E006214 */  bne        $v1, $v0, .L800AEF88
    /* 466D0 800AEED0 F8FFBD27 */   addiu     $sp, $sp, -0x8
    /* 466D4 800AEED4 E7178290 */  lbu        $v0, 0x17E7($a0)
    /* 466D8 800AEED8 00000000 */  nop
    /* 466DC 800AEEDC 2A004010 */  beqz       $v0, .L800AEF88
    /* 466E0 800AEEE0 0680023C */   lui       $v0, %hi(vs_gametime_tickspeed)
    /* 466E4 800AEEE4 4CE2428C */  lw         $v0, %lo(vs_gametime_tickspeed)($v0)
    /* 466E8 800AEEE8 E7178590 */  lbu        $a1, 0x17E7($a0)
    /* 466EC 800AEEEC C21F0200 */  srl        $v1, $v0, 31
    /* 466F0 800AEEF0 21104300 */  addu       $v0, $v0, $v1
    /* 466F4 800AEEF4 43300200 */  sra        $a2, $v0, 1
    /* 466F8 800AEEF8 2A10A600 */  slt        $v0, $a1, $a2
    /* 466FC 800AEEFC 02004010 */  beqz       $v0, .L800AEF08
    /* 46700 800AEF00 00000000 */   nop
    /* 46704 800AEF04 2130A000 */  addu       $a2, $a1, $zero
  .L800AEF08:
    /* 46708 800AEF08 EA178290 */  lbu        $v0, 0x17EA($a0)
    /* 4670C 800AEF0C E6178790 */  lbu        $a3, 0x17E6($a0)
    /* 46710 800AEF10 00000000 */  nop
    /* 46714 800AEF14 23184700 */  subu       $v1, $v0, $a3
    /* 46718 800AEF18 09006010 */  beqz       $v1, .L800AEF40
    /* 4671C 800AEF1C 18006600 */   mult      $v1, $a2
    /* 46720 800AEF20 12180000 */  mflo       $v1
    /* 46724 800AEF24 00000000 */  nop
    /* 46728 800AEF28 00000000 */  nop
    /* 4672C 800AEF2C 1A006500 */  div        $zero, $v1, $a1
    /* 46730 800AEF30 12180000 */  mflo       $v1
    /* 46734 800AEF34 00000000 */  nop
    /* 46738 800AEF38 2110E300 */  addu       $v0, $a3, $v1
    /* 4673C 800AEF3C E61782A0 */  sb         $v0, 0x17E6($a0)
  .L800AEF40:
    /* 46740 800AEF40 E9178290 */  lbu        $v0, 0x17E9($a0)
    /* 46744 800AEF44 E5178590 */  lbu        $a1, 0x17E5($a0)
    /* 46748 800AEF48 00000000 */  nop
    /* 4674C 800AEF4C 23184500 */  subu       $v1, $v0, $a1
    /* 46750 800AEF50 09006010 */  beqz       $v1, .L800AEF78
    /* 46754 800AEF54 18006600 */   mult      $v1, $a2
    /* 46758 800AEF58 12180000 */  mflo       $v1
    /* 4675C 800AEF5C E7178290 */  lbu        $v0, 0x17E7($a0)
    /* 46760 800AEF60 00000000 */  nop
    /* 46764 800AEF64 1A006200 */  div        $zero, $v1, $v0
    /* 46768 800AEF68 12180000 */  mflo       $v1
    /* 4676C 800AEF6C 00000000 */  nop
    /* 46770 800AEF70 2110A300 */  addu       $v0, $a1, $v1
    /* 46774 800AEF74 E51782A0 */  sb         $v0, 0x17E5($a0)
  .L800AEF78:
    /* 46778 800AEF78 E7178290 */  lbu        $v0, 0x17E7($a0)
    /* 4677C 800AEF7C 00000000 */  nop
    /* 46780 800AEF80 23104600 */  subu       $v0, $v0, $a2
    /* 46784 800AEF84 E71782A0 */  sb         $v0, 0x17E7($a0)
  .L800AEF88:
    /* 46788 800AEF88 0800BD27 */  addiu      $sp, $sp, 0x8
    /* 4678C 800AEF8C 0800E003 */  jr         $ra
    /* 46790 800AEF90 00000000 */   nop
endlabel func_800AEEC4
