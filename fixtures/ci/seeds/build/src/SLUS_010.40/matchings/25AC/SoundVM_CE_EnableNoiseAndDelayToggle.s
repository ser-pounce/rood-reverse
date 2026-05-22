nonmatching SoundVM_CE_EnableNoiseAndDelayToggle, 0x44

glabel SoundVM_CE_EnableNoiseAndDelayToggle
    /* D22C 8001CA2C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* D230 8001CA30 1000BFAF */  sw         $ra, 0x10($sp)
    /* D234 8001CA34 0000828C */  lw         $v0, 0x0($a0)
    /* D238 8001CA38 00000000 */  nop
    /* D23C 8001CA3C 00004390 */  lbu        $v1, 0x0($v0)
    /* D240 8001CA40 01004224 */  addiu      $v0, $v0, 0x1
    /* D244 8001CA44 03006010 */  beqz       $v1, .L8001CA54
    /* D248 8001CA48 000082AC */   sw        $v0, 0x0($a0)
    /* D24C 8001CA4C 96720008 */  j          .L8001CA58
    /* D250 8001CA50 01006224 */   addiu     $v0, $v1, 0x1
  .L8001CA54:
    /* D254 8001CA54 01010224 */  addiu      $v0, $zero, 0x101
  .L8001CA58:
    /* D258 8001CA58 4270000C */  jal        SoundVM_C4_EnableNoiseVoices
    /* D25C 8001CA5C CC0082A4 */   sh        $v0, 0xCC($a0)
    /* D260 8001CA60 1000BF8F */  lw         $ra, 0x10($sp)
    /* D264 8001CA64 00000000 */  nop
    /* D268 8001CA68 0800E003 */  jr         $ra
    /* D26C 8001CA6C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel SoundVM_CE_EnableNoiseAndDelayToggle
