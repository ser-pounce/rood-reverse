nonmatching func_8007424C, 0x48

glabel func_8007424C
    /* BA4C 8007424C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* BA50 80074250 1000B0AF */  sw         $s0, 0x10($sp)
    /* BA54 80074254 21800000 */  addu       $s0, $zero, $zero
    /* BA58 80074258 1400BFAF */  sw         $ra, 0x14($sp)
    /* BA5C 8007425C F882020C */  jal        func_800A0BE0
    /* BA60 80074260 21200002 */   addu      $a0, $s0, $zero
    /* BA64 80074264 0008033C */  lui        $v1, (0x8000000 >> 16)
    /* BA68 80074268 24104300 */  and        $v0, $v0, $v1
    /* BA6C 8007426C 05004010 */  beqz       $v0, .L80074284
    /* BA70 80074270 21100002 */   addu      $v0, $s0, $zero
    /* BA74 80074274 172D030C */  jal        func_800CB45C
    /* BA78 80074278 00000000 */   nop
    /* BA7C 8007427C 0100502C */  sltiu      $s0, $v0, 0x1
    /* BA80 80074280 21100002 */  addu       $v0, $s0, $zero
  .L80074284:
    /* BA84 80074284 1400BF8F */  lw         $ra, 0x14($sp)
    /* BA88 80074288 1000B08F */  lw         $s0, 0x10($sp)
    /* BA8C 8007428C 0800E003 */  jr         $ra
    /* BA90 80074290 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8007424C
