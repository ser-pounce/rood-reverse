nonmatching func_80104114, 0x5C

glabel func_80104114
    /* 1914 80104114 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1918 80104118 1000B0AF */  sw         $s0, 0x10($sp)
    /* 191C 8010411C 2180A000 */  addu       $s0, $a1, $zero
    /* 1920 80104120 0F80053C */  lui        $a1, %hi(D_800F4EE8)
    /* 1924 80104124 E84EA524 */  addiu      $a1, $a1, %lo(D_800F4EE8)
    /* 1928 80104128 51008224 */  addiu      $v0, $a0, 0x51
    /* 192C 8010412C 40100200 */  sll        $v0, $v0, 1
    /* 1930 80104130 21184500 */  addu       $v1, $v0, $a1
    /* 1934 80104134 01004224 */  addiu      $v0, $v0, 0x1
    /* 1938 80104138 21104500 */  addu       $v0, $v0, $a1
    /* 193C 8010413C 1400BFAF */  sw         $ra, 0x14($sp)
    /* 1940 80104140 000060A0 */  sb         $zero, 0x0($v1)
    /* 1944 80104144 000050A0 */  sb         $s0, 0x0($v0)
    /* 1948 80104148 1180023C */  lui        $v0, %hi(vs_menuD_containerData)
    /* 194C 8010414C 8C9A458C */  lw         $a1, %lo(vs_menuD_containerData)($v0)
    /* 1950 80104150 250B040C */  jal        _getContainerIndicesOffset
    /* 1954 80104154 40801000 */   sll       $s0, $s0, 1
    /* 1958 80104158 21800202 */  addu       $s0, $s0, $v0
    /* 195C 8010415C 00000296 */  lhu        $v0, 0x0($s0)
    /* 1960 80104160 1400BF8F */  lw         $ra, 0x14($sp)
    /* 1964 80104164 1000B08F */  lw         $s0, 0x10($sp)
    /* 1968 80104168 0800E003 */  jr         $ra
    /* 196C 8010416C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80104114
