nonmatching _initMovieData, 0x68

glabel _initMovieData
    /* 68A0 8006F0A0 0F80023C */  lui        $v0, %hi(_encodedDataBuf0)
    /* 68A4 8006F0A4 0F80033C */  lui        $v1, %hi(_encodedDataBuf1)
    /* 68A8 8006F0A8 180085A4 */  sh         $a1, 0x18($a0)
    /* 68AC 8006F0AC 2C0085A4 */  sh         $a1, 0x2C($a0)
    /* 68B0 8006F0B0 0F80053C */  lui        $a1, %hi(_decodedDataBuf0)
    /* 68B4 8006F0B4 1A0086A4 */  sh         $a2, 0x1A($a0)
    /* 68B8 8006F0B8 2E0086A4 */  sh         $a2, 0x2E($a0)
    /* 68BC 8006F0BC 0F80063C */  lui        $a2, %hi(_decodedDataBuf1)
    /* 68C0 8006F0C0 080080AC */  sw         $zero, 0x8($a0)
    /* 68C4 8006F0C4 140080AC */  sw         $zero, 0x14($a0)
    /* 68C8 8006F0C8 200087A4 */  sh         $a3, 0x20($a0)
    /* 68CC 8006F0CC 280080AC */  sw         $zero, 0x28($a0)
    /* 68D0 8006F0D0 1000A88F */  lw         $t0, 0x10($sp)
    /* 68D4 8006F0D4 E8FD478C */  lw         $a3, %lo(_encodedDataBuf0)($v0)
    /* 68D8 8006F0D8 ECFD638C */  lw         $v1, %lo(_encodedDataBuf1)($v1)
    /* 68DC 8006F0DC F0FDA58C */  lw         $a1, %lo(_decodedDataBuf0)($a1)
    /* 68E0 8006F0E0 F4FDC68C */  lw         $a2, %lo(_decodedDataBuf1)($a2)
    /* 68E4 8006F0E4 18000224 */  addiu      $v0, $zero, 0x18
    /* 68E8 8006F0E8 300082A4 */  sh         $v0, 0x30($a0)
    /* 68EC 8006F0EC 340080AC */  sw         $zero, 0x34($a0)
    /* 68F0 8006F0F0 000087AC */  sw         $a3, 0x0($a0)
    /* 68F4 8006F0F4 040083AC */  sw         $v1, 0x4($a0)
    /* 68F8 8006F0F8 0C0085AC */  sw         $a1, 0xC($a0)
    /* 68FC 8006F0FC 100086AC */  sw         $a2, 0x10($a0)
    /* 6900 8006F100 0800E003 */  jr         $ra
    /* 6904 8006F104 220088A4 */   sh        $t0, 0x22($a0)
endlabel _initMovieData
