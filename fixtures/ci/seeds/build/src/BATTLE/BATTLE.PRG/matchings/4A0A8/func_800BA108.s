nonmatching func_800BA108, 0x8C

glabel func_800BA108
    /* 51908 800BA108 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 5190C 800BA10C 1400BFAF */  sw         $ra, 0x14($sp)
    /* 51910 800BA110 1000B0AF */  sw         $s0, 0x10($sp)
    /* 51914 800BA114 01008290 */  lbu        $v0, 0x1($a0)
    /* 51918 800BA118 00000000 */  nop
    /* 5191C 800BA11C 10004010 */  beqz       $v0, .L800BA160
    /* 51920 800BA120 0F80103C */   lui       $s0, %hi(D_800F4C08)
    /* 51924 800BA124 084C0292 */  lbu        $v0, %lo(D_800F4C08)($s0)
    /* 51928 800BA128 00000000 */  nop
    /* 5192C 800BA12C 15004014 */  bnez       $v0, .L800BA184
    /* 51930 800BA130 21100000 */   addu      $v0, $zero, $zero
    /* 51934 800BA134 1C39020C */  jal        func_8008E470
    /* 51938 800BA138 00000000 */   nop
    /* 5193C 800BA13C 084C02A2 */  sb         $v0, %lo(D_800F4C08)($s0)
    /* 51940 800BA140 FF004230 */  andi       $v0, $v0, 0xFF
    /* 51944 800BA144 0F004010 */  beqz       $v0, .L800BA184
    /* 51948 800BA148 21100000 */   addu      $v0, $zero, $zero
    /* 5194C 800BA14C EF44020C */  jal        func_800913BC
    /* 51950 800BA150 FFFF0424 */   addiu     $a0, $zero, -0x1
    /* 51954 800BA154 0F80033C */  lui        $v1, %hi(D_800F4C4C)
    /* 51958 800BA158 60E80208 */  j          .L800BA180
    /* 5195C 800BA15C 4C4C62A4 */   sh        $v0, %lo(D_800F4C4C)($v1)
  .L800BA160:
    /* 51960 800BA160 084C0292 */  lbu        $v0, %lo(D_800F4C08)($s0)
    /* 51964 800BA164 00000000 */  nop
    /* 51968 800BA168 05004010 */  beqz       $v0, .L800BA180
    /* 5196C 800BA16C 0F80023C */   lui       $v0, %hi(D_800F4C4C)
    /* 51970 800BA170 4C4C4484 */  lh         $a0, %lo(D_800F4C4C)($v0)
    /* 51974 800BA174 EF44020C */  jal        func_800913BC
    /* 51978 800BA178 00000000 */   nop
    /* 5197C 800BA17C 084C00A2 */  sb         $zero, %lo(D_800F4C08)($s0)
  .L800BA180:
    /* 51980 800BA180 21100000 */  addu       $v0, $zero, $zero
  .L800BA184:
    /* 51984 800BA184 1400BF8F */  lw         $ra, 0x14($sp)
    /* 51988 800BA188 1000B08F */  lw         $s0, 0x10($sp)
    /* 5198C 800BA18C 0800E003 */  jr         $ra
    /* 51990 800BA190 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800BA108
