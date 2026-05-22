nonmatching _spu_FsetRXX, 0x44

glabel _spu_FsetRXX
    /* EB60 8001E360 0700C014 */  bnez       $a2, .L8001E380
    /* EB64 8001E364 40100400 */   sll       $v0, $a0, 1
    /* EB68 8001E368 0380033C */  lui        $v1, %hi(D_80030860)
    /* EB6C 8001E36C 6008638C */  lw         $v1, %lo(D_80030860)($v1)
    /* EB70 8001E370 00000000 */  nop
    /* EB74 8001E374 21104300 */  addu       $v0, $v0, $v1
    /* EB78 8001E378 E7780008 */  j          .L8001E39C
    /* EB7C 8001E37C 000045A4 */   sh        $a1, 0x0($v0)
  .L8001E380:
    /* EB80 8001E380 0380043C */  lui        $a0, %hi(D_80030860)
    /* EB84 8001E384 6008848C */  lw         $a0, %lo(D_80030860)($a0)
    /* EB88 8001E388 0380033C */  lui        $v1, %hi(D_80030888)
    /* EB8C 8001E38C 8808638C */  lw         $v1, %lo(D_80030888)($v1)
    /* EB90 8001E390 21104400 */  addu       $v0, $v0, $a0
    /* EB94 8001E394 06186500 */  srlv       $v1, $a1, $v1
    /* EB98 8001E398 000043A4 */  sh         $v1, 0x0($v0)
  .L8001E39C:
    /* EB9C 8001E39C 0800E003 */  jr         $ra
    /* EBA0 8001E3A0 00000000 */   nop
endlabel _spu_FsetRXX
