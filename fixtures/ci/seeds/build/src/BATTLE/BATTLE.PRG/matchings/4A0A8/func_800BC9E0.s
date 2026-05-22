nonmatching func_800BC9E0, 0xAC

glabel func_800BC9E0
    /* 541E0 800BC9E0 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 541E4 800BC9E4 1000B0AF */  sw         $s0, 0x10($sp)
    /* 541E8 800BC9E8 0F80103C */  lui        $s0, %hi(D_800F4BA4)
    /* 541EC 800BC9EC A44B048E */  lw         $a0, %lo(D_800F4BA4)($s0)
    /* 541F0 800BC9F0 1400BFAF */  sw         $ra, 0x14($sp)
    /* 541F4 800BC9F4 9400828C */  lw         $v0, 0x94($a0)
    /* 541F8 800BC9F8 9800838C */  lw         $v1, 0x98($a0)
    /* 541FC 800BC9FC 9C00868C */  lw         $a2, 0x9C($a0)
    /* 54200 800BCA00 4801878C */  lw         $a3, 0x148($a0)
    /* 54204 800BCA04 4C01888C */  lw         $t0, 0x14C($a0)
    /* 54208 800BCA08 5001898C */  lw         $t1, 0x150($a0)
    /* 5420C 800BCA0C B4008524 */  addiu      $a1, $a0, 0xB4
    /* 54210 800BCA10 580182AC */  sw         $v0, 0x158($a0)
    /* 54214 800BCA14 5C0183AC */  sw         $v1, 0x15C($a0)
    /* 54218 800BCA18 600186AC */  sw         $a2, 0x160($a0)
    /* 5421C 800BCA1C A40087AC */  sw         $a3, 0xA4($a0)
    /* 54220 800BCA20 A80088AC */  sw         $t0, 0xA8($a0)
    /* 54224 800BCA24 A3F2020C */  jal        func_800BCA8C
    /* 54228 800BCA28 AC0089AC */   sw        $t1, 0xAC($a0)
    /* 5422C 800BCA2C A44B058E */  lw         $a1, %lo(D_800F4BA4)($s0)
    /* 54230 800BCA30 A3F2020C */  jal        func_800BCA8C
    /* 54234 800BCA34 B400A424 */   addiu     $a0, $a1, 0xB4
    /* 54238 800BCA38 A44B048E */  lw         $a0, %lo(D_800F4BA4)($s0)
    /* 5423C 800BCA3C 5FF5020C */  jal        func_800BD57C
    /* 54240 800BCA40 68018424 */   addiu     $a0, $a0, 0x168
    /* 54244 800BCA44 A44B048E */  lw         $a0, %lo(D_800F4BA4)($s0)
    /* 54248 800BCA48 5FF5020C */  jal        func_800BD57C
    /* 5424C 800BCA4C 74018424 */   addiu     $a0, $a0, 0x174
    /* 54250 800BCA50 A44B048E */  lw         $a0, %lo(D_800F4BA4)($s0)
    /* 54254 800BCA54 DBF7020C */  jal        func_800BDF6C
    /* 54258 800BCA58 80018424 */   addiu     $a0, $a0, 0x180
    /* 5425C 800BCA5C A44B048E */  lw         $a0, %lo(D_800F4BA4)($s0)
    /* 54260 800BCA60 DBF7020C */  jal        func_800BDF6C
    /* 54264 800BCA64 8C018424 */   addiu     $a0, $a0, 0x18C
    /* 54268 800BCA68 A44B048E */  lw         $a0, %lo(D_800F4BA4)($s0)
    /* 5426C 800BCA6C DBF7020C */  jal        func_800BDF6C
    /* 54270 800BCA70 98018424 */   addiu     $a0, $a0, 0x198
    /* 54274 800BCA74 60F8020C */  jal        func_800BE180
    /* 54278 800BCA78 00000000 */   nop
    /* 5427C 800BCA7C 1400BF8F */  lw         $ra, 0x14($sp)
    /* 54280 800BCA80 1000B08F */  lw         $s0, 0x10($sp)
    /* 54284 800BCA84 0800E003 */  jr         $ra
    /* 54288 800BCA88 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800BC9E0
