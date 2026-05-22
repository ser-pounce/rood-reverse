nonmatching startIntrDMA, 0x4C

glabel startIntrDMA
    /* 108B4 800200B4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 108B8 800200B8 0380043C */  lui        $a0, %hi(D_80032128)
    /* 108BC 800200BC 28218424 */  addiu      $a0, $a0, %lo(D_80032128)
    /* 108C0 800200C0 1000BFAF */  sw         $ra, 0x10($sp)
    /* 108C4 800200C4 CB80000C */  jal        func_8002032C
    /* 108C8 800200C8 08000524 */   addiu     $a1, $zero, 0x8
    /* 108CC 800200CC 03000424 */  addiu      $a0, $zero, 0x3
    /* 108D0 800200D0 0380023C */  lui        $v0, %hi(D_80032124)
    /* 108D4 800200D4 2421428C */  lw         $v0, %lo(D_80032124)($v0)
    /* 108D8 800200D8 0280053C */  lui        $a1, %hi(func_80020100)
    /* 108DC 800200DC 0001A524 */  addiu      $a1, $a1, %lo(func_80020100)
    /* 108E0 800200E0 417E000C */  jal        InterruptCallback
    /* 108E4 800200E4 000040AC */   sw        $zero, 0x0($v0)
    /* 108E8 800200E8 0280023C */  lui        $v0, %hi(func_80020280)
    /* 108EC 800200EC 80024224 */  addiu      $v0, $v0, %lo(func_80020280)
    /* 108F0 800200F0 1000BF8F */  lw         $ra, 0x10($sp)
    /* 108F4 800200F4 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 108F8 800200F8 0800E003 */  jr         $ra
    /* 108FC 800200FC 00000000 */   nop
endlabel startIntrDMA
