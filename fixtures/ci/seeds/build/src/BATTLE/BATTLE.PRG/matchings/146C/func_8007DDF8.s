nonmatching func_8007DDF8, 0x34

glabel func_8007DDF8
    /* 155F8 8007DDF8 0F80023C */  lui        $v0, %hi(D_800F1A68)
    /* 155FC 8007DDFC 681A4724 */  addiu      $a3, $v0, %lo(D_800F1A68)
    /* 15600 8007DE00 0000838C */  lw         $v1, 0x0($a0)
    /* 15604 8007DE04 0400858C */  lw         $a1, 0x4($a0)
    /* 15608 8007DE08 0800868C */  lw         $a2, 0x8($a0)
    /* 1560C 8007DE0C 0000E3AC */  sw         $v1, 0x0($a3)
    /* 15610 8007DE10 0400E5AC */  sw         $a1, 0x4($a3)
    /* 15614 8007DE14 0800E6AC */  sw         $a2, 0x8($a3)
    /* 15618 8007DE18 0C00838C */  lw         $v1, 0xC($a0)
    /* 1561C 8007DE1C 00000000 */  nop
    /* 15620 8007DE20 0C00E3AC */  sw         $v1, 0xC($a3)
    /* 15624 8007DE24 0800E003 */  jr         $ra
    /* 15628 8007DE28 00000000 */   nop
endlabel func_8007DDF8
