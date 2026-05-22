nonmatching SoundVM_FE07_JumpRelativeWithThreshold, 0x58

glabel SoundVM_FE07_JumpRelativeWithThreshold
    /* BC50 8001B450 0380023C */  lui        $v0, %hi(g_pActiveMusicConfig)
    /* BC54 8001B454 0000858C */  lw         $a1, 0x0($a0)
    /* BC58 8001B458 2078428C */  lw         $v0, %lo(g_pActiveMusicConfig)($v0)
    /* BC5C 8001B45C 0000A390 */  lbu        $v1, 0x0($a1)
    /* BC60 8001B460 0100A524 */  addiu      $a1, $a1, 0x1
    /* BC64 8001B464 000085AC */  sw         $a1, 0x0($a0)
    /* BC68 8001B468 70004294 */  lhu        $v0, 0x70($v0)
    /* BC6C 8001B46C 00000000 */  nop
    /* BC70 8001B470 2A104300 */  slt        $v0, $v0, $v1
    /* BC74 8001B474 0A004014 */  bnez       $v0, .L8001B4A0
    /* BC78 8001B478 0200A224 */   addiu     $v0, $a1, 0x2
    /* BC7C 8001B47C 0100A390 */  lbu        $v1, 0x1($a1)
    /* BC80 8001B480 0000A290 */  lbu        $v0, 0x0($a1)
    /* BC84 8001B484 001A0300 */  sll        $v1, $v1, 8
    /* BC88 8001B488 25104300 */  or         $v0, $v0, $v1
    /* BC8C 8001B48C 00140200 */  sll        $v0, $v0, 16
    /* BC90 8001B490 03140200 */  sra        $v0, $v0, 16
    /* BC94 8001B494 2110A200 */  addu       $v0, $a1, $v0
    /* BC98 8001B498 0800E003 */  jr         $ra
    /* BC9C 8001B49C 000082AC */   sw        $v0, 0x0($a0)
  .L8001B4A0:
    /* BCA0 8001B4A0 0800E003 */  jr         $ra
    /* BCA4 8001B4A4 000082AC */   sw        $v0, 0x0($a0)
endlabel SoundVM_FE07_JumpRelativeWithThreshold
