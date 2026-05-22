nonmatching func_8007B410, 0x60

glabel func_8007B410
    /* 12C10 8007B410 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 12C14 8007B414 0D000424 */  addiu      $a0, $zero, 0xD
    /* 12C18 8007B418 04000524 */  addiu      $a1, $zero, 0x4
    /* 12C1C 8007B41C FCFF0624 */  addiu      $a2, $zero, -0x4
    /* 12C20 8007B420 2138C000 */  addu       $a3, $a2, $zero
    /* 12C24 8007B424 1800BFAF */  sw         $ra, 0x18($sp)
    /* 12C28 8007B428 43EC010C */  jal        func_8007B10C
    /* 12C2C 8007B42C 1000A0AF */   sw        $zero, 0x10($sp)
    /* 12C30 8007B430 FB23010C */  jal        vs_main_setClutState
    /* 12C34 8007B434 21200000 */   addu      $a0, $zero, $zero
    /* 12C38 8007B438 A8B0010C */  jal        func_8006C2A0
    /* 12C3C 8007B43C 00000000 */   nop
    /* 12C40 8007B440 2F2D020C */  jal        func_8008B4BC
    /* 12C44 8007B444 01000424 */   addiu     $a0, $zero, 0x1
    /* 12C48 8007B448 322D020C */  jal        func_8008B4C8
    /* 12C4C 8007B44C 21200000 */   addu      $a0, $zero, $zero
    /* 12C50 8007B450 2039020C */  jal        func_8008E480
    /* 12C54 8007B454 01000424 */   addiu     $a0, $zero, 0x1
    /* 12C58 8007B458 0F80033C */  lui        $v1, %hi(D_800F1968)
    /* 12C5C 8007B45C 1800BF8F */  lw         $ra, 0x18($sp)
    /* 12C60 8007B460 01000224 */  addiu      $v0, $zero, 0x1
    /* 12C64 8007B464 681962AC */  sw         $v0, %lo(D_800F1968)($v1)
    /* 12C68 8007B468 0800E003 */  jr         $ra
    /* 12C6C 8007B46C 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_8007B410
