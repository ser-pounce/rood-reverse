nonmatching func_800B822C, 0x64

glabel func_800B822C
    /* 4FA2C 800B822C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 4FA30 800B8230 1000B0AF */  sw         $s0, 0x10($sp)
    /* 4FA34 800B8234 21808000 */  addu       $s0, $a0, $zero
    /* 4FA38 800B8238 1400BFAF */  sw         $ra, 0x14($sp)
    /* 4FA3C 800B823C 80FF020C */  jal        vs_battle_getShort
    /* 4FA40 800B8240 01000426 */   addiu     $a0, $s0, 0x1
    /* 4FA44 800B8244 94FF020C */  jal        func_800BFE50
    /* 4FA48 800B8248 FFFF4430 */   andi      $a0, $v0, 0xFFFF
    /* 4FA4C 800B824C 0F80043C */  lui        $a0, %hi(D_800E9B58)
    /* 4FA50 800B8250 589B8424 */  addiu      $a0, $a0, %lo(D_800E9B58)
    /* 4FA54 800B8254 21380000 */  addu       $a3, $zero, $zero
    /* 4FA58 800B8258 05000692 */  lbu        $a2, 0x5($s0)
    /* 4FA5C 800B825C 03000592 */  lbu        $a1, 0x3($s0)
    /* 4FA60 800B8260 82190600 */  srl        $v1, $a2, 6
    /* 4FA64 800B8264 21186400 */  addu       $v1, $v1, $a0
    /* 4FA68 800B8268 21204000 */  addu       $a0, $v0, $zero
    /* 4FA6C 800B826C 00006390 */  lbu        $v1, 0x0($v1)
    /* 4FA70 800B8270 3F00C630 */  andi       $a2, $a2, 0x3F
    /* 4FA74 800B8274 7280020C */  jal        func_800A01C8
    /* 4FA78 800B8278 21286500 */   addu      $a1, $v1, $a1
    /* 4FA7C 800B827C 1400BF8F */  lw         $ra, 0x14($sp)
    /* 4FA80 800B8280 1000B08F */  lw         $s0, 0x10($sp)
    /* 4FA84 800B8284 21100000 */  addu       $v0, $zero, $zero
    /* 4FA88 800B8288 0800E003 */  jr         $ra
    /* 4FA8C 800B828C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800B822C
