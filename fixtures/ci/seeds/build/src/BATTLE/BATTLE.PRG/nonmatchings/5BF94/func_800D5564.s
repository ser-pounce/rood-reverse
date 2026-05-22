nonmatching func_800D5564, 0x40

glabel func_800D5564
    /* 6CD64 800D5564 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 6CD68 800D5568 1400B1AF */  sw         $s1, 0x14($sp)
    /* 6CD6C 800D556C 21888000 */  addu       $s1, $a0, $zero
    /* 6CD70 800D5570 1000B0AF */  sw         $s0, 0x10($sp)
    /* 6CD74 800D5574 1800BFAF */  sw         $ra, 0x18($sp)
    /* 6CD78 800D5578 5455030C */  jal        func_800D5550
    /* 6CD7C 800D557C 2180C000 */   addu      $s0, $a2, $zero
    /* 6CD80 800D5580 80801000 */  sll        $s0, $s0, 2
    /* 6CD84 800D5584 21105000 */  addu       $v0, $v0, $s0
    /* 6CD88 800D5588 06004294 */  lhu        $v0, 0x6($v0)
    /* 6CD8C 800D558C 1800BF8F */  lw         $ra, 0x18($sp)
    /* 6CD90 800D5590 1000B08F */  lw         $s0, 0x10($sp)
    /* 6CD94 800D5594 21102202 */  addu       $v0, $s1, $v0
    /* 6CD98 800D5598 1400B18F */  lw         $s1, 0x14($sp)
    /* 6CD9C 800D559C 0800E003 */  jr         $ra
    /* 6CDA0 800D55A0 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_800D5564
