nonmatching func_800B71C4, 0x30

glabel func_800B71C4
    /* 4E9C4 800B71C4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 4E9C8 800B71C8 1000BFAF */  sw         $ra, 0x10($sp)
    /* 4E9CC 800B71CC AB21030C */  jal        func_800C86AC
    /* 4E9D0 800B71D0 00000000 */   nop
    /* 4E9D4 800B71D4 0F80023C */  lui        $v0, %hi(D_800F4C2C)
    /* 4E9D8 800B71D8 2C4C4290 */  lbu        $v0, %lo(D_800F4C2C)($v0)
    /* 4E9DC 800B71DC 1000BF8F */  lw         $ra, 0x10($sp)
    /* 4E9E0 800B71E0 02004238 */  xori       $v0, $v0, 0x2
    /* 4E9E4 800B71E4 0100422C */  sltiu      $v0, $v0, 0x1
    /* 4E9E8 800B71E8 80100200 */  sll        $v0, $v0, 2
    /* 4E9EC 800B71EC 0800E003 */  jr         $ra
    /* 4E9F0 800B71F0 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800B71C4
