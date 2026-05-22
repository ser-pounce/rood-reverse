nonmatching vs_sound_setCdVol, 0x94

glabel vs_sound_setCdVol
    /* 3A30 80013230 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 3A34 80013234 0480023C */  lui        $v0, %hi(D_80039AFC)
    /* 3A38 80013238 FC9A428C */  lw         $v0, %lo(D_80039AFC)($v0)
    /* 3A3C 8001323C 21308000 */  addu       $a2, $a0, $zero
    /* 3A40 80013240 02004230 */  andi       $v0, $v0, 0x2
    /* 3A44 80013244 12004010 */  beqz       $v0, .L80013290
    /* 3A48 80013248 1000BFAF */   sw        $ra, 0x10($sp)
    /* 3A4C 8001324C 0380053C */  lui        $a1, %hi(_cdlAtv)
    /* 3A50 80013250 D065A424 */  addiu      $a0, $a1, %lo(_cdlAtv)
    /* 3A54 80013254 40100600 */  sll        $v0, $a2, 1
    /* 3A58 80013258 21104600 */  addu       $v0, $v0, $a2
    /* 3A5C 8001325C 80100200 */  sll        $v0, $v0, 2
    /* 3A60 80013260 23104600 */  subu       $v0, $v0, $a2
    /* 3A64 80013264 40190200 */  sll        $v1, $v0, 5
    /* 3A68 80013268 21104300 */  addu       $v0, $v0, $v1
    /* 3A6C 8001326C C0100200 */  sll        $v0, $v0, 3
    /* 3A70 80013270 23104600 */  subu       $v0, $v0, $a2
    /* 3A74 80013274 00110200 */  sll        $v0, $v0, 4
    /* 3A78 80013278 42140200 */  srl        $v0, $v0, 17
    /* 3A7C 8001327C 030082A0 */  sb         $v0, 0x3($a0)
    /* 3A80 80013280 010082A0 */  sb         $v0, 0x1($a0)
    /* 3A84 80013284 020082A0 */  sb         $v0, 0x2($a0)
    /* 3A88 80013288 AA4C0008 */  j          .L800132A8
    /* 3A8C 8001328C D065A2A0 */   sb        $v0, %lo(_cdlAtv)($a1)
  .L80013290:
    /* 3A90 80013290 0380033C */  lui        $v1, %hi(_cdlAtv)
    /* 3A94 80013294 D0656224 */  addiu      $v0, $v1, %lo(_cdlAtv)
    /* 3A98 80013298 020046A0 */  sb         $a2, 0x2($v0)
    /* 3A9C 8001329C D06566A0 */  sb         $a2, %lo(_cdlAtv)($v1)
    /* 3AA0 800132A0 030040A0 */  sb         $zero, 0x3($v0)
    /* 3AA4 800132A4 010040A0 */  sb         $zero, 0x1($v0)
  .L800132A8:
    /* 3AA8 800132A8 0380043C */  lui        $a0, %hi(_cdlAtv)
    /* 3AAC 800132AC 4782000C */  jal        CdMix
    /* 3AB0 800132B0 D0658424 */   addiu     $a0, $a0, %lo(_cdlAtv)
    /* 3AB4 800132B4 1000BF8F */  lw         $ra, 0x10($sp)
    /* 3AB8 800132B8 21100000 */  addu       $v0, $zero, $zero
    /* 3ABC 800132BC 0800E003 */  jr         $ra
    /* 3AC0 800132C0 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel vs_sound_setCdVol
