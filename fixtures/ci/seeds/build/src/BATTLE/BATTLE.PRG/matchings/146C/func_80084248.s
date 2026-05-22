nonmatching func_80084248, 0x64

glabel func_80084248
    /* 1BA48 80084248 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1BA4C 8008424C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 1BA50 80084250 2180C000 */  addu       $s0, $a2, $zero
    /* 1BA54 80084254 1E000424 */  addiu      $a0, $zero, 0x1E
    /* 1BA58 80084258 1400BFAF */  sw         $ra, 0x14($sp)
    /* 1BA5C 8008425C 3304020C */  jal        func_800810CC
    /* 1BA60 80084260 21280002 */   addu      $a1, $s0, $zero
    /* 1BA64 80084264 0F80033C */  lui        $v1, %hi(vs_battle_actors)
    /* 1BA68 80084268 28196324 */  addiu      $v1, $v1, %lo(vs_battle_actors)
    /* 1BA6C 8008426C 00000292 */  lbu        $v0, 0x0($s0)
    /* 1BA70 80084270 FCFF0424 */  addiu      $a0, $zero, -0x4
    /* 1BA74 80084274 80100200 */  sll        $v0, $v0, 2
    /* 1BA78 80084278 21104300 */  addu       $v0, $v0, $v1
    /* 1BA7C 8008427C 0000438C */  lw         $v1, 0x0($v0)
    /* 1BA80 80084280 1C00028E */  lw         $v0, 0x1C($s0)
    /* 1BA84 80084284 3C00638C */  lw         $v1, 0x3C($v1)
    /* 1BA88 80084288 24104400 */  and        $v0, $v0, $a0
    /* 1BA8C 8008428C 18006394 */  lhu        $v1, 0x18($v1)
    /* 1BA90 80084290 01004234 */  ori        $v0, $v0, 0x1
    /* 1BA94 80084294 1C0002AE */  sw         $v0, 0x1C($s0)
    /* 1BA98 80084298 040003A6 */  sh         $v1, 0x4($s0)
    /* 1BA9C 8008429C 1400BF8F */  lw         $ra, 0x14($sp)
    /* 1BAA0 800842A0 1000B08F */  lw         $s0, 0x10($sp)
    /* 1BAA4 800842A4 0800E003 */  jr         $ra
    /* 1BAA8 800842A8 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80084248
