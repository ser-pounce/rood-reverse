nonmatching func_800128D8, 0x40

glabel func_800128D8
    /* 30D8 800128D8 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 30DC 800128DC 0380023C */  lui        $v0, %hi(D_800378C0)
    /* 30E0 800128E0 C07844AC */  sw         $a0, %lo(D_800378C0)($v0)
    /* 30E4 800128E4 C0784224 */  addiu      $v0, $v0, %lo(D_800378C0)
    /* 30E8 800128E8 7F00C630 */  andi       $a2, $a2, 0x7F
    /* 30EC 800128EC 7F00E730 */  andi       $a3, $a3, 0x7F
    /* 30F0 800128F0 C2000424 */  addiu      $a0, $zero, 0xC2
    /* 30F4 800128F4 1000BFAF */  sw         $ra, 0x10($sp)
    /* 30F8 800128F8 040045AC */  sw         $a1, 0x4($v0)
    /* 30FC 800128FC 080046AC */  sw         $a2, 0x8($v0)
    /* 3100 80012900 0C63000C */  jal        func_80018C30
    /* 3104 80012904 0C0047AC */   sw        $a3, 0xC($v0)
    /* 3108 80012908 1000BF8F */  lw         $ra, 0x10($sp)
    /* 310C 8001290C 00000000 */  nop
    /* 3110 80012910 0800E003 */  jr         $ra
    /* 3114 80012914 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800128D8
