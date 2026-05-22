nonmatching func_800CF988, 0x124

glabel func_800CF988
    /* 67188 800CF988 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 6718C 800CF98C 1400B1AF */  sw         $s1, 0x14($sp)
    /* 67190 800CF990 21888000 */  addu       $s1, $a0, $zero
    /* 67194 800CF994 1800B2AF */  sw         $s2, 0x18($sp)
    /* 67198 800CF998 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 6719C 800CF99C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 671A0 800CF9A0 0C002486 */  lh         $a0, 0xC($s1)
    /* 671A4 800CF9A4 40010324 */  addiu      $v1, $zero, 0x140
    /* 671A8 800CF9A8 2A108300 */  slt        $v0, $a0, $v1
    /* 671AC 800CF9AC 02004010 */  beqz       $v0, .L800CF9B8
    /* 671B0 800CF9B0 2190C000 */   addu      $s2, $a2, $zero
    /* 671B4 800CF9B4 21188000 */  addu       $v1, $a0, $zero
  .L800CF9B8:
    /* 671B8 800CF9B8 18002486 */  lh         $a0, 0x18($s1)
    /* 671BC 800CF9BC 00000000 */  nop
    /* 671C0 800CF9C0 2A108300 */  slt        $v0, $a0, $v1
    /* 671C4 800CF9C4 02004010 */  beqz       $v0, .L800CF9D0
    /* 671C8 800CF9C8 00000000 */   nop
    /* 671CC 800CF9CC 21188000 */  addu       $v1, $a0, $zero
  .L800CF9D0:
    /* 671D0 800CF9D0 24002486 */  lh         $a0, 0x24($s1)
    /* 671D4 800CF9D4 00000000 */  nop
    /* 671D8 800CF9D8 2A108300 */  slt        $v0, $a0, $v1
    /* 671DC 800CF9DC 02004010 */  beqz       $v0, .L800CF9E8
    /* 671E0 800CF9E0 00000000 */   nop
    /* 671E4 800CF9E4 21188000 */  addu       $v1, $a0, $zero
  .L800CF9E8:
    /* 671E8 800CF9E8 30002486 */  lh         $a0, 0x30($s1)
    /* 671EC 800CF9EC 00000000 */  nop
    /* 671F0 800CF9F0 2A108300 */  slt        $v0, $a0, $v1
    /* 671F4 800CF9F4 02004010 */  beqz       $v0, .L800CFA00
    /* 671F8 800CF9F8 C0FF0224 */   addiu     $v0, $zero, -0x40
    /* 671FC 800CF9FC 21188000 */  addu       $v1, $a0, $zero
  .L800CFA00:
    /* 67200 800CFA00 24186200 */  and        $v1, $v1, $v0
    /* 67204 800CFA04 02006104 */  bgez       $v1, .L800CFA10
    /* 67208 800CFA08 21206000 */   addu      $a0, $v1, $zero
    /* 6720C 800CFA0C 3F006424 */  addiu      $a0, $v1, 0x3F
  .L800CFA10:
    /* 67210 800CFA10 0680023C */  lui        $v0, %hi(vs_main_frameBuf)
    /* 67214 800CFA14 10E2428C */  lw         $v0, %lo(vs_main_frameBuf)($v0)
    /* 67218 800CFA18 00000000 */  nop
    /* 6721C 800CFA1C 01004230 */  andi       $v0, $v0, 0x1
    /* 67220 800CFA20 04004014 */  bnez       $v0, .L800CFA34
    /* 67224 800CFA24 83210400 */   sra       $a0, $a0, 6
    /* 67228 800CFA28 05008224 */  addiu      $v0, $a0, 0x5
    /* 6722C 800CFA2C 8E3E0308 */  j          .L800CFA38
    /* 67230 800CFA30 25104700 */   or        $v0, $v0, $a3
  .L800CFA34:
    /* 67234 800CFA34 25108700 */  or         $v0, $a0, $a3
  .L800CFA38:
    /* 67238 800CFA38 00014234 */  ori        $v0, $v0, 0x100
    /* 6723C 800CFA3C 2380A300 */  subu       $s0, $a1, $v1
    /* 67240 800CFA40 21200002 */  addu       $a0, $s0, $zero
    /* 67244 800CFA44 21284002 */  addu       $a1, $s2, $zero
    /* 67248 800CFA48 0C00268E */  lw         $a2, 0xC($s1)
    /* 6724C 800CFA4C 10002726 */  addiu      $a3, $s1, 0x10
    /* 67250 800CFA50 4B3E030C */  jal        func_800CF92C
    /* 67254 800CFA54 1E0022A6 */   sh        $v0, 0x1E($s1)
    /* 67258 800CFA58 21200002 */  addu       $a0, $s0, $zero
    /* 6725C 800CFA5C 21284002 */  addu       $a1, $s2, $zero
    /* 67260 800CFA60 1800268E */  lw         $a2, 0x18($s1)
    /* 67264 800CFA64 4B3E030C */  jal        func_800CF92C
    /* 67268 800CFA68 1C002726 */   addiu     $a3, $s1, 0x1C
    /* 6726C 800CFA6C 21200002 */  addu       $a0, $s0, $zero
    /* 67270 800CFA70 21284002 */  addu       $a1, $s2, $zero
    /* 67274 800CFA74 2400268E */  lw         $a2, 0x24($s1)
    /* 67278 800CFA78 4B3E030C */  jal        func_800CF92C
    /* 6727C 800CFA7C 28002726 */   addiu     $a3, $s1, 0x28
    /* 67280 800CFA80 21200002 */  addu       $a0, $s0, $zero
    /* 67284 800CFA84 21284002 */  addu       $a1, $s2, $zero
    /* 67288 800CFA88 3000268E */  lw         $a2, 0x30($s1)
    /* 6728C 800CFA8C 4B3E030C */  jal        func_800CF92C
    /* 67290 800CFA90 34002726 */   addiu     $a3, $s1, 0x34
    /* 67294 800CFA94 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 67298 800CFA98 1800B28F */  lw         $s2, 0x18($sp)
    /* 6729C 800CFA9C 1400B18F */  lw         $s1, 0x14($sp)
    /* 672A0 800CFAA0 1000B08F */  lw         $s0, 0x10($sp)
    /* 672A4 800CFAA4 0800E003 */  jr         $ra
    /* 672A8 800CFAA8 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_800CF988
