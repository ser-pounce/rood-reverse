nonmatching func_8002D6DC, 0xD8

glabel func_8002D6DC
    /* 1DEDC 8002D6DC 0380033C */  lui        $v1, %hi(D_800335DC)
    /* 1DEE0 8002D6E0 DC35638C */  lw         $v1, %lo(D_800335DC)($v1)
    /* 1DEE4 8002D6E4 0380023C */  lui        $v0, %hi(D_800335EC)
    /* 1DEE8 8002D6E8 EC35428C */  lw         $v0, %lo(D_800335EC)($v0)
    /* 1DEEC 8002D6EC E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1DEF0 8002D6F0 1000B0AF */  sw         $s0, 0x10($sp)
    /* 1DEF4 8002D6F4 21808000 */  addu       $s0, $a0, $zero
    /* 1DEF8 8002D6F8 10006214 */  bne        $v1, $v0, .L8002D73C
    /* 1DEFC 8002D6FC 1400BFAF */   sw        $ra, 0x14($sp)
    /* 1DF00 8002D700 0380023C */  lui        $v0, %hi(D_800335D8)
    /* 1DF04 8002D704 D835428C */  lw         $v0, %lo(D_800335D8)($v0)
    /* 1DF08 8002D708 00000000 */  nop
    /* 1DF0C 8002D70C 0B004010 */  beqz       $v0, .L8002D73C
    /* 1DF10 8002D710 00000000 */   nop
    /* 1DF14 8002D714 0380023C */  lui        $v0, %hi(D_800335CC)
    /* 1DF18 8002D718 CC35428C */  lw         $v0, %lo(D_800335CC)($v0)
    /* 1DF1C 8002D71C 00000000 */  nop
    /* 1DF20 8002D720 09F84000 */  jalr       $v0
    /* 1DF24 8002D724 00000000 */   nop
    /* 1DF28 8002D728 0380023C */  lui        $v0, %hi(D_800335C8)
    /* 1DF2C 8002D72C C835428C */  lw         $v0, %lo(D_800335C8)($v0)
    /* 1DF30 8002D730 00000000 */  nop
    /* 1DF34 8002D734 09F84000 */  jalr       $v0
    /* 1DF38 8002D738 00000000 */   nop
  .L8002D73C:
    /* 1DF3C 8002D73C 0380023C */  lui        $v0, %hi(D_8003361C)
    /* 1DF40 8002D740 1C36428C */  lw         $v0, %lo(D_8003361C)($v0)
    /* 1DF44 8002D744 00000000 */  nop
    /* 1DF48 8002D748 0D004010 */  beqz       $v0, .L8002D780
    /* 1DF4C 8002D74C 00000000 */   nop
    /* 1DF50 8002D750 0C00048E */  lw         $a0, 0xC($s0)
    /* 1DF54 8002D754 0380023C */  lui        $v0, %hi(D_800335B4)
    /* 1DF58 8002D758 B435428C */  lw         $v0, %lo(D_800335B4)($v0)
    /* 1DF5C 8002D75C 00000000 */  nop
    /* 1DF60 8002D760 09F84000 */  jalr       $v0
    /* 1DF64 8002D764 00000000 */   nop
    /* 1DF68 8002D768 0C00048E */  lw         $a0, 0xC($s0)
    /* 1DF6C 8002D76C 0380023C */  lui        $v0, %hi(D_800335B4)
    /* 1DF70 8002D770 B435428C */  lw         $v0, %lo(D_800335B4)($v0)
    /* 1DF74 8002D774 00000000 */  nop
    /* 1DF78 8002D778 09F84000 */  jalr       $v0
    /* 1DF7C 8002D77C F0008424 */   addiu     $a0, $a0, 0xF0
  .L8002D780:
    /* 1DF80 8002D780 37000292 */  lbu        $v0, 0x37($s0)
    /* 1DF84 8002D784 00000000 */  nop
    /* 1DF88 8002D788 03004014 */  bnez       $v0, .L8002D798
    /* 1DF8C 8002D78C 21200002 */   addu      $a0, $s0, $zero
    /* 1DF90 8002D790 E7B50008 */  j          .L8002D79C
    /* 1DF94 8002D794 42000524 */   addiu     $a1, $zero, 0x42
  .L8002D798:
    /* 1DF98 8002D798 37000592 */  lbu        $a1, 0x37($s0)
  .L8002D79C:
    /* 1DF9C 8002D79C CEB1000C */  jal        _padSioRW2
    /* 1DFA0 8002D7A0 00000000 */   nop
    /* 1DFA4 8002D7A4 1400BF8F */  lw         $ra, 0x14($sp)
    /* 1DFA8 8002D7A8 1000B08F */  lw         $s0, 0x10($sp)
    /* 1DFAC 8002D7AC 0800E003 */  jr         $ra
    /* 1DFB0 8002D7B0 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8002D6DC
