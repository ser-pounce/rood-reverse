nonmatching func_8006A9C0, 0xAC

glabel func_8006A9C0
    /* 21C0 8006A9C0 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 21C4 8006A9C4 1800B0AF */  sw         $s0, 0x18($sp)
    /* 21C8 8006A9C8 21808000 */  addu       $s0, $a0, $zero
    /* 21CC 8006A9CC 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 21D0 8006A9D0 0400028E */  lw         $v0, 0x4($s0)
    /* 21D4 8006A9D4 00000000 */  nop
    /* 21D8 8006A9D8 08004230 */  andi       $v0, $v0, 0x8
    /* 21DC 8006A9DC 12004010 */  beqz       $v0, .L8006AA28
    /* 21E0 8006A9E0 08000526 */   addiu     $a1, $s0, 0x8
    /* 21E4 8006A9E4 0400A294 */  lhu        $v0, 0x4($a1)
    /* 21E8 8006A9E8 00000000 */  nop
    /* 21EC 8006A9EC 1000A2A7 */  sh         $v0, 0x10($sp)
    /* 21F0 8006A9F0 0600A294 */  lhu        $v0, 0x6($a1)
    /* 21F4 8006A9F4 00000000 */  nop
    /* 21F8 8006A9F8 1200A2A7 */  sh         $v0, 0x12($sp)
    /* 21FC 8006A9FC 0800A294 */  lhu        $v0, 0x8($a1)
    /* 2200 8006AA00 1000A427 */  addiu      $a0, $sp, 0x10
    /* 2204 8006AA04 1400A2A7 */  sh         $v0, 0x14($sp)
    /* 2208 8006AA08 0A00A294 */  lhu        $v0, 0xA($a1)
    /* 220C 8006AA0C 14000526 */  addiu      $a1, $s0, 0x14
    /* 2210 8006AA10 3FA2000C */  jal        LoadImage
    /* 2214 8006AA14 1600A2A7 */   sh        $v0, 0x16($sp)
    /* 2218 8006AA18 0800028E */  lw         $v0, 0x8($s0)
    /* 221C 8006AA1C 00000000 */  nop
    /* 2220 8006AA20 08004224 */  addiu      $v0, $v0, 0x8
    /* 2224 8006AA24 21280202 */  addu       $a1, $s0, $v0
  .L8006AA28:
    /* 2228 8006AA28 0400A294 */  lhu        $v0, 0x4($a1)
    /* 222C 8006AA2C 00000000 */  nop
    /* 2230 8006AA30 1000A2A7 */  sh         $v0, 0x10($sp)
    /* 2234 8006AA34 0600A294 */  lhu        $v0, 0x6($a1)
    /* 2238 8006AA38 00000000 */  nop
    /* 223C 8006AA3C 1200A2A7 */  sh         $v0, 0x12($sp)
    /* 2240 8006AA40 0800A294 */  lhu        $v0, 0x8($a1)
    /* 2244 8006AA44 1000A427 */  addiu      $a0, $sp, 0x10
    /* 2248 8006AA48 1400A2A7 */  sh         $v0, 0x14($sp)
    /* 224C 8006AA4C 0A00A294 */  lhu        $v0, 0xA($a1)
    /* 2250 8006AA50 0C00A524 */  addiu      $a1, $a1, 0xC
    /* 2254 8006AA54 3FA2000C */  jal        LoadImage
    /* 2258 8006AA58 1600A2A7 */   sh        $v0, 0x16($sp)
    /* 225C 8006AA5C 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 2260 8006AA60 1800B08F */  lw         $s0, 0x18($sp)
    /* 2264 8006AA64 0800E003 */  jr         $ra
    /* 2268 8006AA68 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_8006A9C0
