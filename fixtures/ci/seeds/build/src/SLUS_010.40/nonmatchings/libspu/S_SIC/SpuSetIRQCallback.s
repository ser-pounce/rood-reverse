nonmatching SpuSetIRQCallback, 0x3C

glabel SpuSetIRQCallback
    /* F294 8001EA94 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* F298 8001EA98 1000B0AF */  sw         $s0, 0x10($sp)
    /* F29C 8001EA9C 0380103C */  lui        $s0, %hi(D_8003089C)
    /* F2A0 8001EAA0 9C08108E */  lw         $s0, %lo(D_8003089C)($s0)
    /* F2A4 8001EAA4 00000000 */  nop
    /* F2A8 8001EAA8 04009010 */  beq        $a0, $s0, .L8001EABC
    /* F2AC 8001EAAC 1400BFAF */   sw        $ra, 0x14($sp)
    /* F2B0 8001EAB0 0380013C */  lui        $at, %hi(D_8003089C)
    /* F2B4 8001EAB4 B57A000C */  jal        _SpuCallback
    /* F2B8 8001EAB8 9C0824AC */   sw        $a0, %lo(D_8003089C)($at)
  .L8001EABC:
    /* F2BC 8001EABC 21100002 */  addu       $v0, $s0, $zero
    /* F2C0 8001EAC0 1400BF8F */  lw         $ra, 0x14($sp)
    /* F2C4 8001EAC4 1000B08F */  lw         $s0, 0x10($sp)
    /* F2C8 8001EAC8 0800E003 */  jr         $ra
    /* F2CC 8001EACC 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel SpuSetIRQCallback
    /* F2D0 8001EAD0 00000000 */  nop
