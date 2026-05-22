nonmatching func_80103270, 0x3C

glabel func_80103270
    /* A70 80103270 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* A74 80103274 1400BFAF */  sw         $ra, 0x14($sp)
    /* A78 80103278 680C040C */  jal        func_801031A0
    /* A7C 8010327C 1000B0AF */   sw        $s0, 0x10($sp)
    /* A80 80103280 1080023C */  lui        $v0, %hi(vs_menu_inventoryStorage)
    /* A84 80103284 5C24458C */  lw         $a1, %lo(vs_menu_inventoryStorage)($v0)
    /* A88 80103288 06000424 */  addiu      $a0, $zero, 0x6
    /* A8C 8010328C 1C0C040C */  jal        _countContainerItems
    /* A90 80103290 B04BA524 */   addiu     $a1, $a1, 0x4BB0
    /* A94 80103294 1400BF8F */  lw         $ra, 0x14($sp)
    /* A98 80103298 1180103C */  lui        $s0, %hi(D_80109A82)
    /* A9C 8010329C 829A02A6 */  sh         $v0, %lo(D_80109A82)($s0)
    /* AA0 801032A0 1000B08F */  lw         $s0, 0x10($sp)
    /* AA4 801032A4 0800E003 */  jr         $ra
    /* AA8 801032A8 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80103270
