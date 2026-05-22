nonmatching _drawHPMP, 0x290

glabel _drawHPMP
    /* 2128 8006A928 C8FFBD27 */  addiu      $sp, $sp, -0x38
    /* 212C 8006A92C 1800B2AF */  sw         $s2, 0x18($sp)
    /* 2130 8006A930 21908000 */  addu       $s2, $a0, $zero
    /* 2134 8006A934 2800B6AF */  sw         $s6, 0x28($sp)
    /* 2138 8006A938 21B0A000 */  addu       $s6, $a1, $zero
    /* 213C 8006A93C 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 2140 8006A940 2198C000 */  addu       $s3, $a2, $zero
    /* 2144 8006A944 2400B5AF */  sw         $s5, 0x24($sp)
    /* 2148 8006A948 21A8E000 */  addu       $s5, $a3, $zero
    /* 214C 8006A94C 3400BFAF */  sw         $ra, 0x34($sp)
    /* 2150 8006A950 3000BEAF */  sw         $fp, 0x30($sp)
    /* 2154 8006A954 2C00B7AF */  sw         $s7, 0x2C($sp)
    /* 2158 8006A958 2000B4AF */  sw         $s4, 0x20($sp)
    /* 215C 8006A95C 1400B1AF */  sw         $s1, 0x14($sp)
    /* 2160 8006A960 0800A012 */  beqz       $s5, .L8006A984
    /* 2164 8006A964 1000B0AF */   sw        $s0, 0x10($sp)
    /* 2168 8006A968 80111300 */  sll        $v0, $s3, 6
    /* 216C 8006A96C 21105500 */  addu       $v0, $v0, $s5
    /* 2170 8006A970 FFFF4224 */  addiu      $v0, $v0, -0x1
    /* 2174 8006A974 1B005500 */  divu       $zero, $v0, $s5
    /* 2178 8006A978 12880000 */  mflo       $s1
    /* 217C 8006A97C 63AA0108 */  j          .L8006A98C
    /* 2180 8006A980 CF00143C */   lui       $s4, (0xCFE02D >> 16)
  .L8006A984:
    /* 2184 8006A984 21880000 */  addu       $s1, $zero, $zero
    /* 2188 8006A988 CF00143C */  lui        $s4, (0xCFE02D >> 16)
  .L8006A98C:
    /* 218C 8006A98C 0300C012 */  beqz       $s6, .L8006A99C
    /* 2190 8006A990 2DE09436 */   ori       $s4, $s4, (0xCFE02D & 0xFFFF)
    /* 2194 8006A994 9F00143C */  lui        $s4, (0x9F78DC >> 16)
    /* 2198 8006A998 DC789436 */  ori        $s4, $s4, (0x9F78DC & 0xFFFF)
  .L8006A99C:
    /* 219C 8006A99C FF008232 */  andi       $v0, $s4, 0xFF
    /* 21A0 8006A9A0 40000524 */  addiu      $a1, $zero, 0x40
    /* 21A4 8006A9A4 2328B100 */  subu       $a1, $a1, $s1
    /* 21A8 8006A9A8 18004500 */  mult       $v0, $a1
    /* 21AC 8006A9AC 12180000 */  mflo       $v1
    /* 21B0 8006A9B0 02121400 */  srl        $v0, $s4, 8
    /* 21B4 8006A9B4 FF004230 */  andi       $v0, $v0, 0xFF
    /* 21B8 8006A9B8 18004500 */  mult       $v0, $a1
    /* 21BC 8006A9BC 21200000 */  addu       $a0, $zero, $zero
    /* 21C0 8006A9C0 F4371E3C */  lui        $fp, (0x37F40000 >> 16)
    /* 21C4 8006A9C4 CCCC173C */  lui        $s7, (0xCCCCCCCD >> 16)
    /* 21C8 8006A9C8 CDCCF736 */  ori        $s7, $s7, (0xCCCCCCCD & 0xFFFF)
    /* 21CC 8006A9CC 00821100 */  sll        $s0, $s1, 8
    /* 21D0 8006A9D0 23801102 */  subu       $s0, $s0, $s1
    /* 21D4 8006A9D4 21800302 */  addu       $s0, $s0, $v1
    /* 21D8 8006A9D8 82811000 */  srl        $s0, $s0, 6
    /* 21DC 8006A9DC 12300000 */  mflo       $a2
    /* 21E0 8006A9E0 00111100 */  sll        $v0, $s1, 4
    /* 21E4 8006A9E4 021C1400 */  srl        $v1, $s4, 16
    /* 21E8 8006A9E8 18006500 */  mult       $v1, $a1
    /* 21EC 8006A9EC 23105100 */  subu       $v0, $v0, $s1
    /* 21F0 8006A9F0 00110200 */  sll        $v0, $v0, 4
    /* 21F4 8006A9F4 21104600 */  addu       $v0, $v0, $a2
    /* 21F8 8006A9F8 82110200 */  srl        $v0, $v0, 6
    /* 21FC 8006A9FC 00120200 */  sll        $v0, $v0, 8
    /* 2200 8006AA00 25800202 */  or         $s0, $s0, $v0
    /* 2204 8006AA04 80101100 */  sll        $v0, $s1, 2
    /* 2208 8006AA08 21105100 */  addu       $v0, $v0, $s1
    /* 220C 8006AA0C 00110200 */  sll        $v0, $v0, 4
    /* 2210 8006AA10 23105100 */  subu       $v0, $v0, $s1
    /* 2214 8006AA14 40100200 */  sll        $v0, $v0, 1
    /* 2218 8006AA18 12180000 */  mflo       $v1
    /* 221C 8006AA1C 21104300 */  addu       $v0, $v0, $v1
    /* 2220 8006AA20 82110200 */  srl        $v0, $v0, 6
    /* 2224 8006AA24 00140200 */  sll        $v0, $v0, 16
    /* 2228 8006AA28 94A1000C */  jal        DrawSync
    /* 222C 8006AA2C 25800202 */   or        $s0, $s0, $v0
    /* 2230 8006AA30 00E1083C */  lui        $t0, (0xE1000200 >> 16)
    /* 2234 8006AA34 00020835 */  ori        $t0, $t0, (0xE1000200 & 0xFFFF)
    /* 2238 8006AA38 4060063C */  lui        $a2, (0x60402800 >> 16)
    /* 223C 8006AA3C 0028C634 */  ori        $a2, $a2, (0x60402800 & 0xFFFF)
    /* 2240 8006AA40 0500073C */  lui        $a3, (0x50042 >> 16)
    /* 2244 8006AA44 4200E734 */  ori        $a3, $a3, (0x50042 & 0xFFFF)
    /* 2248 8006AA48 0800033C */  lui        $v1, (0x80000 >> 16)
    /* 224C 8006AA4C 21184302 */  addu       $v1, $s2, $v1
    /* 2250 8006AA50 01005226 */  addiu      $s2, $s2, 0x1
    /* 2254 8006AA54 0E80053C */  lui        $a1, %hi(_primBuf)
    /* 2258 8006AA58 28EDA424 */  addiu      $a0, $a1, %lo(_primBuf)
    /* 225C 8006AA5C 000C023C */  lui        $v0, (0xC000000 >> 16)
    /* 2260 8006AA60 28EDA2AC */  sw         $v0, %lo(_primBuf)($a1)
    /* 2264 8006AA64 0038023C */  lui        $v0, (0x38000000 >> 16)
    /* 2268 8006AA68 25100202 */  or         $v0, $s0, $v0
    /* 226C 8006AA6C 140082AC */  sw         $v0, 0x14($a0)
    /* 2270 8006AA70 0900023C */  lui        $v0, (0x90000 >> 16)
    /* 2274 8006AA74 0C0083AC */  sw         $v1, 0xC($a0)
    /* 2278 8006AA78 21184202 */  addu       $v1, $s2, $v0
    /* 227C 8006AA7C 21102202 */  addu       $v0, $s1, $v0
    /* 2280 8006AA80 21104202 */  addu       $v0, $s2, $v0
    /* 2284 8006AA84 200082AC */  sw         $v0, 0x20($a0)
    /* 2288 8006AA88 0C00023C */  lui        $v0, (0xC0000 >> 16)
    /* 228C 8006AA8C 180083AC */  sw         $v1, 0x18($a0)
    /* 2290 8006AA90 21184202 */  addu       $v1, $s2, $v0
    /* 2294 8006AA94 21102202 */  addu       $v0, $s1, $v0
    /* 2298 8006AA98 21104202 */  addu       $v0, $s2, $v0
    /* 229C 8006AA9C 040088AC */  sw         $t0, 0x4($a0)
    /* 22A0 8006AAA0 080086AC */  sw         $a2, 0x8($a0)
    /* 22A4 8006AAA4 100087AC */  sw         $a3, 0x10($a0)
    /* 22A8 8006AAA8 1C0094AC */  sw         $s4, 0x1C($a0)
    /* 22AC 8006AAAC 240090AC */  sw         $s0, 0x24($a0)
    /* 22B0 8006AAB0 280083AC */  sw         $v1, 0x28($a0)
    /* 22B4 8006AAB4 2C0094AC */  sw         $s4, 0x2C($a0)
    /* 22B8 8006AAB8 FAA2000C */  jal        DrawPrim
    /* 22BC 8006AABC 300082AC */   sw        $v0, 0x30($a0)
    /* 22C0 8006AAC0 3EAA010C */  jal        _countDigits
    /* 22C4 8006AAC4 21206002 */   addu      $a0, $s3, $zero
    /* 22C8 8006AAC8 21884000 */  addu       $s1, $v0, $zero
    /* 22CC 8006AACC 3EAA010C */  jal        _countDigits
    /* 22D0 8006AAD0 2120A002 */   addu      $a0, $s5, $zero
    /* 22D4 8006AAD4 FFFF4426 */  addiu      $a0, $s2, -0x1
    /* 22D8 8006AAD8 0700C526 */  addiu      $a1, $s6, 0x7
    /* 22DC 8006AADC 07AA010C */  jal        _drawSaveInfoUI
    /* 22E0 8006AAE0 21A04000 */   addu      $s4, $v0, $zero
    /* 22E4 8006AAE4 40101100 */  sll        $v0, $s1, 1
    /* 22E8 8006AAE8 21105100 */  addu       $v0, $v0, $s1
    /* 22EC 8006AAEC 40100200 */  sll        $v0, $v0, 1
    /* 22F0 8006AAF0 C9FF4224 */  addiu      $v0, $v0, -0x37
    /* 22F4 8006AAF4 23104202 */  subu       $v0, $s2, $v0
    /* 22F8 8006AAF8 80181400 */  sll        $v1, $s4, 2
    /* 22FC 8006AAFC 21187400 */  addu       $v1, $v1, $s4
    /* 2300 8006AB00 23904300 */  subu       $s2, $v0, $v1
    /* 2304 8006AB04 0780023C */  lui        $v0, %hi(_digitDivisors)
    /* 2308 8006AB08 10294224 */  addiu      $v0, $v0, %lo(_digitDivisors)
    /* 230C 8006AB0C 21102202 */  addu       $v0, $s1, $v0
    /* 2310 8006AB10 00005190 */  lbu        $s1, 0x0($v0)
  .L8006AB14:
    /* 2314 8006AB14 00000000 */  nop
    /* 2318 8006AB18 1B007102 */  divu       $zero, $s3, $s1
    /* 231C 8006AB1C 12280000 */  mflo       $a1
    /* 2320 8006AB20 10800000 */  mfhi       $s0
    /* 2324 8006AB24 FFFF093C */  lui        $t1, (0xFFFF0000 >> 16)
    /* 2328 8006AB28 21204902 */  addu       $a0, $s2, $t1
    /* 232C 8006AB2C 0C00063C */  lui        $a2, (0xC0007 >> 16)
    /* 2330 8006AB30 0700C634 */  ori        $a2, $a2, (0xC0007 & 0xFFFF)
    /* 2334 8006AB34 0C000724 */  addiu      $a3, $zero, 0xC
    /* 2338 8006AB38 C0280500 */  sll        $a1, $a1, 3
    /* 233C 8006AB3C 4000A524 */  addiu      $a1, $a1, 0x40
    /* 2340 8006AB40 DEA9010C */  jal        _drawSprt
    /* 2344 8006AB44 2528BE00 */   or        $a1, $a1, $fp
    /* 2348 8006AB48 19003702 */  multu      $s1, $s7
    /* 234C 8006AB4C 21980002 */  addu       $s3, $s0, $zero
    /* 2350 8006AB50 10180000 */  mfhi       $v1
    /* 2354 8006AB54 C2880300 */  srl        $s1, $v1, 3
    /* 2358 8006AB58 EEFF2016 */  bnez       $s1, .L8006AB14
    /* 235C 8006AB5C 06005226 */   addiu     $s2, $s2, 0x6
    /* 2360 8006AB60 01004426 */  addiu      $a0, $s2, 0x1
    /* 2364 8006AB64 07AA010C */  jal        _drawSaveInfoUI
    /* 2368 8006AB68 09000524 */   addiu     $a1, $zero, 0x9
    /* 236C 8006AB6C 06004426 */  addiu      $a0, $s2, 0x6
    /* 2370 8006AB70 0780023C */  lui        $v0, %hi(_digitDivisors)
    /* 2374 8006AB74 10294224 */  addiu      $v0, $v0, %lo(_digitDivisors)
    /* 2378 8006AB78 21108202 */  addu       $v0, $s4, $v0
    /* 237C 8006AB7C 00004690 */  lbu        $a2, 0x0($v0)
    /* 2380 8006AB80 18AA010C */  jal        _drawInteger
    /* 2384 8006AB84 2128A002 */   addu      $a1, $s5, $zero
    /* 2388 8006AB88 3400BF8F */  lw         $ra, 0x34($sp)
    /* 238C 8006AB8C 3000BE8F */  lw         $fp, 0x30($sp)
    /* 2390 8006AB90 2C00B78F */  lw         $s7, 0x2C($sp)
    /* 2394 8006AB94 2800B68F */  lw         $s6, 0x28($sp)
    /* 2398 8006AB98 2400B58F */  lw         $s5, 0x24($sp)
    /* 239C 8006AB9C 2000B48F */  lw         $s4, 0x20($sp)
    /* 23A0 8006ABA0 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 23A4 8006ABA4 1800B28F */  lw         $s2, 0x18($sp)
    /* 23A8 8006ABA8 1400B18F */  lw         $s1, 0x14($sp)
    /* 23AC 8006ABAC 1000B08F */  lw         $s0, 0x10($sp)
    /* 23B0 8006ABB0 0800E003 */  jr         $ra
    /* 23B4 8006ABB4 3800BD27 */   addiu     $sp, $sp, 0x38
endlabel _drawHPMP
