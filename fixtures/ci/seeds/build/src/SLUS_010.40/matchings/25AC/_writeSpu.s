nonmatching _writeSpu, 0x50

glabel _writeSpu
    /* 3CD0 800134D0 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 3CD4 800134D4 1000B0AF */  sw         $s0, 0x10($sp)
    /* 3CD8 800134D8 21808000 */  addu       $s0, $a0, $zero
    /* 3CDC 800134DC 1400B1AF */  sw         $s1, 0x14($sp)
    /* 3CE0 800134E0 2188A000 */  addu       $s1, $a1, $zero
    /* 3CE4 800134E4 0380033C */  lui        $v1, %hi(_isSpuTransfer)
    /* 3CE8 800134E8 01000224 */  addiu      $v0, $zero, 0x1
    /* 3CEC 800134EC 0180043C */  lui        $a0, %hi(_spuWriteComplete)
    /* 3CF0 800134F0 1800BFAF */  sw         $ra, 0x18($sp)
    /* 3CF4 800134F4 F07762AC */  sw         $v0, %lo(_isSpuTransfer)($v1)
    /* 3CF8 800134F8 157B000C */  jal        SpuSetTransferCallback
    /* 3CFC 800134FC 7C348424 */   addiu     $a0, $a0, %lo(_spuWriteComplete)
    /* 3D00 80013500 21200002 */  addu       $a0, $s0, $zero
    /* 3D04 80013504 D97A000C */  jal        SpuWrite
    /* 3D08 80013508 21282002 */   addu      $a1, $s1, $zero
    /* 3D0C 8001350C 1800BF8F */  lw         $ra, 0x18($sp)
    /* 3D10 80013510 1400B18F */  lw         $s1, 0x14($sp)
    /* 3D14 80013514 1000B08F */  lw         $s0, 0x10($sp)
    /* 3D18 80013518 0800E003 */  jr         $ra
    /* 3D1C 8001351C 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel _writeSpu
