nonmatching _copy_memcard_patch, 0x34

glabel _copy_memcard_patch
    /* 1F894 8002F094 80DF0234 */  ori        $v0, $zero, 0xDF80
    /* 1F898 8002F098 03800A3C */  lui        $t2, %hi(func_8002EEF8)
    /* 1F89C 8002F09C F8EE4A25 */  addiu      $t2, $t2, %lo(func_8002EEF8)
    /* 1F8A0 8002F0A0 0380093C */  lui        $t1, %hi(func_8002EF68)
    /* 1F8A4 8002F0A4 68EF2925 */  addiu      $t1, $t1, %lo(func_8002EF68)
  .L8002F0A8:
    /* 1F8A8 8002F0A8 0000438D */  lw         $v1, 0x0($t2)
    /* 1F8AC 8002F0AC 00000000 */  nop
    /* 1F8B0 8002F0B0 000043AC */  sw         $v1, 0x0($v0)
    /* 1F8B4 8002F0B4 04004A25 */  addiu      $t2, $t2, 0x4
    /* 1F8B8 8002F0B8 FBFF4915 */  bne        $t2, $t1, .L8002F0A8
    /* 1F8BC 8002F0BC 04004224 */   addiu     $v0, $v0, 0x4
    /* 1F8C0 8002F0C0 0800E003 */  jr         $ra
    /* 1F8C4 8002F0C4 00000000 */   nop
endlabel _copy_memcard_patch
    /* 1F8C8 8002F0C8 00000000 */  nop
    /* 1F8CC 8002F0CC 00000000 */  nop
    /* 1F8D0 8002F0D0 00000000 */  nop
