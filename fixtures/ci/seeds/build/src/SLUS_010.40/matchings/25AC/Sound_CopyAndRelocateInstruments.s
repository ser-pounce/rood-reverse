nonmatching Sound_CopyAndRelocateInstruments, 0x50

glabel Sound_CopyAndRelocateInstruments
    /* 3C18 80013418 0C00A824 */  addiu      $t0, $a1, 0xC
    /* 3C1C 8001341C 0C008324 */  addiu      $v1, $a0, 0xC
  .L80013420:
    /* 3C20 80013420 0000828C */  lw         $v0, 0x0($a0)
    /* 3C24 80013424 10008424 */  addiu      $a0, $a0, 0x10
    /* 3C28 80013428 21104600 */  addu       $v0, $v0, $a2
    /* 3C2C 8001342C 0000A2AC */  sw         $v0, 0x0($a1)
    /* 3C30 80013430 F8FF628C */  lw         $v0, -0x8($v1)
    /* 3C34 80013434 FFFFE724 */  addiu      $a3, $a3, -0x1
    /* 3C38 80013438 21104600 */  addu       $v0, $v0, $a2
    /* 3C3C 8001343C F8FF02AD */  sw         $v0, -0x8($t0)
    /* 3C40 80013440 FCFF628C */  lw         $v0, -0x4($v1)
    /* 3C44 80013444 1000A524 */  addiu      $a1, $a1, 0x10
    /* 3C48 80013448 FCFF02AD */  sw         $v0, -0x4($t0)
    /* 3C4C 8001344C 0000628C */  lw         $v0, 0x0($v1)
    /* 3C50 80013450 10006324 */  addiu      $v1, $v1, 0x10
    /* 3C54 80013454 000002AD */  sw         $v0, 0x0($t0)
    /* 3C58 80013458 F1FFE014 */  bnez       $a3, .L80013420
    /* 3C5C 8001345C 10000825 */   addiu     $t0, $t0, 0x10
    /* 3C60 80013460 0800E003 */  jr         $ra
    /* 3C64 80013464 00000000 */   nop
endlabel Sound_CopyAndRelocateInstruments
