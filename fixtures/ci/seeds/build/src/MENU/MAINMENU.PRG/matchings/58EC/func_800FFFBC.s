nonmatching func_800FFFBC, 0x48

glabel func_800FFFBC
    /* 67BC 800FFFBC E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 67C0 800FFFC0 1000B0AF */  sw         $s0, 0x10($sp)
    /* 67C4 800FFFC4 21808000 */  addu       $s0, $a0, $zero
    /* 67C8 800FFFC8 1000043C */  lui        $a0, (0x100010 >> 16)
    /* 67CC 800FFFCC 1400BFAF */  sw         $ra, 0x14($sp)
    /* 67D0 800FFFD0 8500030C */  jal        func_800C0214
    /* 67D4 800FFFD4 10008434 */   ori       $a0, $a0, (0x100010 & 0xFFFF)
    /* 67D8 800FFFD8 FD37043C */  lui        $a0, (0x37FD8000 >> 16)
    /* 67DC 800FFFDC 00808434 */  ori        $a0, $a0, (0x37FD8000 & 0xFFFF)
    /* 67E0 800FFFE0 00811000 */  sll        $s0, $s0, 4
    /* 67E4 800FFFE4 60000324 */  addiu      $v1, $zero, 0x60
    /* 67E8 800FFFE8 23187000 */  subu       $v1, $v1, $s0
    /* 67EC 800FFFEC 25186400 */  or         $v1, $v1, $a0
    /* 67F0 800FFFF0 100043AC */  sw         $v1, 0x10($v0)
    /* 67F4 800FFFF4 1400BF8F */  lw         $ra, 0x14($sp)
    /* 67F8 800FFFF8 1000B08F */  lw         $s0, 0x10($sp)
    /* 67FC 800FFFFC 0800E003 */  jr         $ra
    /* 6800 80100000 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800FFFBC
