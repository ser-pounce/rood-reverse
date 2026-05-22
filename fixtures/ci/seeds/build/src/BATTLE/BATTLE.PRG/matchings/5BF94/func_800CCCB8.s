nonmatching func_800CCCB8, 0x48

glabel func_800CCCB8
    /* 644B8 800CCCB8 FF00033C */  lui        $v1, (0xFFFFFF >> 16)
    /* 644BC 800CCCBC FFFF6334 */  ori        $v1, $v1, (0xFFFFFF & 0xFFFF)
    /* 644C0 800CCCC0 801F093C */  lui        $t1, (0x1F800000 >> 16)
    /* 644C4 800CCCC4 0000828C */  lw         $v0, 0x0($a0)
    /* 644C8 800CCCC8 0003083C */  lui        $t0, (0x3000000 >> 16)
    /* 644CC 800CCCCC 24104300 */  and        $v0, $v0, $v1
    /* 644D0 800CCCD0 0000238D */  lw         $v1, (0x1F800000 & 0xFFFF)($t1)
    /* 644D4 800CCCD4 25104800 */  or         $v0, $v0, $t0
    /* 644D8 800CCCD8 000062AC */  sw         $v0, 0x0($v1)
    /* 644DC 800CCCDC 00120300 */  sll        $v0, $v1, 8
    /* 644E0 800CCCE0 02120200 */  srl        $v0, $v0, 8
    /* 644E4 800CCCE4 040065AC */  sw         $a1, 0x4($v1)
    /* 644E8 800CCCE8 080066AC */  sw         $a2, 0x8($v1)
    /* 644EC 800CCCEC 0C0067AC */  sw         $a3, 0xC($v1)
    /* 644F0 800CCCF0 10006324 */  addiu      $v1, $v1, 0x10
    /* 644F4 800CCCF4 000082AC */  sw         $v0, 0x0($a0)
    /* 644F8 800CCCF8 0800E003 */  jr         $ra
    /* 644FC 800CCCFC 000023AD */   sw        $v1, (0x1F800000 & 0xFFFF)($t1)
endlabel func_800CCCB8
