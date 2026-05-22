nonmatching SpuSetTransferMode, 0x30

glabel SpuSetTransferMode
    /* F424 8001EC24 05008010 */  beqz       $a0, .L8001EC3C
    /* F428 8001EC28 01000224 */   addiu     $v0, $zero, 0x1
    /* F42C 8001EC2C 04008214 */  bne        $a0, $v0, .L8001EC40
    /* F430 8001EC30 21100000 */   addu      $v0, $zero, $zero
    /* F434 8001EC34 107B0008 */  j          .L8001EC40
    /* F438 8001EC38 01000224 */   addiu     $v0, $zero, 0x1
  .L8001EC3C:
    /* F43C 8001EC3C 21100000 */  addu       $v0, $zero, $zero
  .L8001EC40:
    /* F440 8001EC40 0380013C */  lui        $at, %hi(D_800307F0)
    /* F444 8001EC44 F00724AC */  sw         $a0, %lo(D_800307F0)($at)
    /* F448 8001EC48 0380013C */  lui        $at, %hi(D_8003087C)
    /* F44C 8001EC4C 0800E003 */  jr         $ra
    /* F450 8001EC50 7C0822AC */   sw        $v0, %lo(D_8003087C)($at)
endlabel SpuSetTransferMode
