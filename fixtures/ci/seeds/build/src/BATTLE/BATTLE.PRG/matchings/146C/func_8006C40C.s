nonmatching func_8006C40C, 0x6C

glabel func_8006C40C
    /* 3C0C 8006C40C E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 3C10 8006C410 1800BFAF */  sw         $ra, 0x18($sp)
    /* 3C14 8006C414 FB23010C */  jal        vs_main_setClutState
    /* 3C18 8006C418 01000424 */   addiu     $a0, $zero, 0x1
    /* 3C1C 8006C41C 08000424 */  addiu      $a0, $zero, 0x8
    /* 3C20 8006C420 04000524 */  addiu      $a1, $zero, 0x4
    /* 3C24 8006C424 21300000 */  addu       $a2, $zero, $zero
    /* 3C28 8006C428 2138C000 */  addu       $a3, $a2, $zero
    /* 3C2C 8006C42C 6EEC010C */  jal        func_8007B1B8
    /* 3C30 8006C430 1000A0AF */   sw        $zero, 0x10($sp)
    /* 3C34 8006C434 94B0010C */  jal        func_8006C250
    /* 3C38 8006C438 00000000 */   nop
    /* 3C3C 8006C43C 2F2D020C */  jal        func_8008B4BC
    /* 3C40 8006C440 21200000 */   addu      $a0, $zero, $zero
    /* 3C44 8006C444 6535020C */  jal        func_8008D594
    /* 3C48 8006C448 21200000 */   addu      $a0, $zero, $zero
    /* 3C4C 8006C44C 322D020C */  jal        func_8008B4C8
    /* 3C50 8006C450 01000424 */   addiu     $a0, $zero, 0x1
    /* 3C54 8006C454 2039020C */  jal        func_8008E480
    /* 3C58 8006C458 21200000 */   addu      $a0, $zero, $zero
    /* 3C5C 8006C45C DC56020C */  jal        func_80095B70
    /* 3C60 8006C460 21200000 */   addu      $a0, $zero, $zero
    /* 3C64 8006C464 1800BF8F */  lw         $ra, 0x18($sp)
    /* 3C68 8006C468 0F80023C */  lui        $v0, %hi(D_800F1968)
    /* 3C6C 8006C46C 681940AC */  sw         $zero, %lo(D_800F1968)($v0)
    /* 3C70 8006C470 0800E003 */  jr         $ra
    /* 3C74 8006C474 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_8006C40C
