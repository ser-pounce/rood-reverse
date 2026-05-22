nonmatching func_800D5260, 0x34

glabel func_800D5260
    /* 6CA60 800D5260 0F80023C */  lui        $v0, %hi(D_800F5620)
    /* 6CA64 800D5264 20564724 */  addiu      $a3, $v0, %lo(D_800F5620)
    /* 6CA68 800D5268 0000838C */  lw         $v1, 0x0($a0)
    /* 6CA6C 800D526C 0400858C */  lw         $a1, 0x4($a0)
    /* 6CA70 800D5270 0800868C */  lw         $a2, 0x8($a0)
    /* 6CA74 800D5274 0000E3AC */  sw         $v1, 0x0($a3)
    /* 6CA78 800D5278 0400E5AC */  sw         $a1, 0x4($a3)
    /* 6CA7C 800D527C 0800E6AC */  sw         $a2, 0x8($a3)
    /* 6CA80 800D5280 0C00838C */  lw         $v1, 0xC($a0)
    /* 6CA84 800D5284 00000000 */  nop
    /* 6CA88 800D5288 0C00E3AC */  sw         $v1, 0xC($a3)
    /* 6CA8C 800D528C 0800E003 */  jr         $ra
    /* 6CA90 800D5290 00000000 */   nop
endlabel func_800D5260
