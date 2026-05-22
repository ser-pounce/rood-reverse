nonmatching func_800D47C8, 0x2C

glabel func_800D47C8
    /* 6BFC8 800D47C8 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 6BFCC 800D47CC 1000BFAF */  sw         $ra, 0x10($sp)
    /* 6BFD0 800D47D0 5C54030C */  jal        func_800D5170
    /* 6BFD4 800D47D4 00000000 */   nop
    /* 6BFD8 800D47D8 0F80033C */  lui        $v1, %hi(D_800F5610)
    /* 6BFDC 800D47DC 1000BF8F */  lw         $ra, 0x10($sp)
    /* 6BFE0 800D47E0 FF004230 */  andi       $v0, $v0, 0xFF
    /* 6BFE4 800D47E4 105662AC */  sw         $v0, %lo(D_800F5610)($v1)
    /* 6BFE8 800D47E8 01000224 */  addiu      $v0, $zero, 0x1
    /* 6BFEC 800D47EC 0800E003 */  jr         $ra
    /* 6BFF0 800D47F0 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800D47C8
