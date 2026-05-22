nonmatching func_8002D924, 0x394

glabel func_8002D924
    /* 1E124 8002D924 0380023C */  lui        $v0, %hi(D_80033620)
    /* 1E128 8002D928 2036428C */  lw         $v0, %lo(D_80033620)($v0)
    /* 1E12C 8002D92C D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 1E130 8002D930 1400B1AF */  sw         $s1, 0x14($sp)
    /* 1E134 8002D934 21888000 */  addu       $s1, $a0, $zero
    /* 1E138 8002D938 2800BFAF */  sw         $ra, 0x28($sp)
    /* 1E13C 8002D93C 2400B5AF */  sw         $s5, 0x24($sp)
    /* 1E140 8002D940 2000B4AF */  sw         $s4, 0x20($sp)
    /* 1E144 8002D944 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 1E148 8002D948 1800B2AF */  sw         $s2, 0x18($sp)
    /* 1E14C 8002D94C 06004010 */  beqz       $v0, .L8002D968
    /* 1E150 8002D950 1000B0AF */   sw        $s0, 0x10($sp)
    /* 1E154 8002D954 0380023C */  lui        $v0, %hi(D_800335A8)
    /* 1E158 8002D958 A835428C */  lw         $v0, %lo(D_800335A8)($v0)
    /* 1E15C 8002D95C 00000000 */  nop
    /* 1E160 8002D960 09F84000 */  jalr       $v0
    /* 1E164 8002D964 00000000 */   nop
  .L8002D968:
    /* 1E168 8002D968 0380143C */  lui        $s4, %hi(D_80033620)
    /* 1E16C 8002D96C 2036948E */  lw         $s4, %lo(D_80033620)($s4)
    /* 1E170 8002D970 00000000 */  nop
    /* 1E174 8002D974 25008012 */  beqz       $s4, .L8002DA0C
    /* 1E178 8002D978 FFFF1024 */   addiu     $s0, $zero, -0x1
    /* 1E17C 8002D97C 10FF1224 */  addiu      $s2, $zero, -0xF0
  .L8002D980:
    /* 1E180 8002D980 0380023C */  lui        $v0, %hi(D_80033614)
    /* 1E184 8002D984 1436428C */  lw         $v0, %lo(D_80033614)($v0)
    /* 1E188 8002D988 00000000 */  nop
    /* 1E18C 8002D98C FFFF4224 */  addiu      $v0, $v0, -0x1
    /* 1E190 8002D990 0380013C */  lui        $at, %hi(D_80033614)
    /* 1E194 8002D994 1D004018 */  blez       $v0, .L8002DA0C
    /* 1E198 8002D998 143622AC */   sw        $v0, %lo(D_80033614)($at)
    /* 1E19C 8002D99C 07000006 */  bltz       $s0, .L8002D9BC
    /* 1E1A0 8002D9A0 00000000 */   nop
    /* 1E1A4 8002D9A4 0C00248E */  lw         $a0, 0xC($s1)
    /* 1E1A8 8002D9A8 0380023C */  lui        $v0, %hi(D_800335A8)
    /* 1E1AC 8002D9AC A835428C */  lw         $v0, %lo(D_800335A8)($v0)
    /* 1E1B0 8002D9B0 00000000 */  nop
    /* 1E1B4 8002D9B4 09F84000 */  jalr       $v0
    /* 1E1B8 8002D9B8 21209200 */   addu      $a0, $a0, $s2
  .L8002D9BC:
    /* 1E1BC 8002D9BC 21202002 */  addu       $a0, $s1, $zero
    /* 1E1C0 8002D9C0 0380023C */  lui        $v0, %hi(D_800335A4)
    /* 1E1C4 8002D9C4 A435428C */  lw         $v0, %lo(D_800335A4)($v0)
    /* 1E1C8 8002D9C8 00000000 */  nop
    /* 1E1CC 8002D9CC 09F84000 */  jalr       $v0
    /* 1E1D0 8002D9D0 01000524 */   addiu     $a1, $zero, 0x1
    /* 1E1D4 8002D9D4 21202002 */  addu       $a0, $s1, $zero
    /* 1E1D8 8002D9D8 CEB1000C */  jal        _padSioRW2
    /* 1E1DC 8002D9DC FF004530 */   andi      $a1, $v0, 0xFF
    /* 1E1E0 8002D9E0 AC004004 */  bltz       $v0, .L8002DC94
    /* 1E1E4 8002D9E4 00000000 */   nop
    /* 1E1E8 8002D9E8 FDB9000C */  jal        setRC2wait
    /* 1E1EC 8002D9EC 3C000424 */   addiu     $a0, $zero, 0x3C
    /* 1E1F0 8002D9F0 6CB2000C */  jal        _padClrIntSio0
    /* 1E1F4 8002D9F4 00000000 */   nop
    /* 1E1F8 8002D9F8 62004010 */  beqz       $v0, .L8002DB84
    /* 1E1FC 8002D9FC 01001026 */   addiu     $s0, $s0, 0x1
    /* 1E200 8002DA00 0400022A */  slti       $v0, $s0, 0x4
    /* 1E204 8002DA04 DEFF4014 */  bnez       $v0, .L8002D980
    /* 1E208 8002DA08 F0005226 */   addiu     $s2, $s2, 0xF0
  .L8002DA0C:
    /* 1E20C 8002DA0C 21800000 */  addu       $s0, $zero, $zero
    /* 1E210 8002DA10 0380033C */  lui        $v1, %hi(D_800335DC)
    /* 1E214 8002DA14 DC35638C */  lw         $v1, %lo(D_800335DC)($v1)
    /* 1E218 8002DA18 0380023C */  lui        $v0, %hi(D_80033614)
    /* 1E21C 8002DA1C 1436428C */  lw         $v0, %lo(D_80033614)($v0)
    /* 1E220 8002DA20 00000000 */  nop
    /* 1E224 8002DA24 02004228 */  slti       $v0, $v0, 0x2
    /* 1E228 8002DA28 61004014 */  bnez       $v0, .L8002DBB0
    /* 1E22C 8002DA2C 0100642C */   sltiu     $a0, $v1, 0x1
    /* 1E230 8002DA30 0380033C */  lui        $v1, %hi(D_800335F4)
    /* 1E234 8002DA34 F4356324 */  addiu      $v1, $v1, %lo(D_800335F4)
    /* 1E238 8002DA38 80100400 */  sll        $v0, $a0, 2
    /* 1E23C 8002DA3C 21904300 */  addu       $s2, $v0, $v1
    /* 1E240 8002DA40 00110400 */  sll        $v0, $a0, 4
    /* 1E244 8002DA44 23104400 */  subu       $v0, $v0, $a0
    /* 1E248 8002DA48 00990200 */  sll        $s3, $v0, 4
    /* 1E24C 8002DA4C 03001524 */  addiu      $s5, $zero, 0x3
  .L8002DA50:
    /* 1E250 8002DA50 0000448E */  lw         $a0, 0x0($s2)
    /* 1E254 8002DA54 00000000 */  nop
    /* 1E258 8002DA58 55008004 */  bltz       $a0, .L8002DBB0
    /* 1E25C 8002DA5C 00000000 */   nop
    /* 1E260 8002DA60 0E008018 */  blez       $a0, .L8002DA9C
    /* 1E264 8002DA64 00110400 */   sll       $v0, $a0, 4
    /* 1E268 8002DA68 0380033C */  lui        $v1, %hi(D_800335D0)
    /* 1E26C 8002DA6C D035638C */  lw         $v1, %lo(D_800335D0)($v1)
    /* 1E270 8002DA70 23104400 */  subu       $v0, $v0, $a0
    /* 1E274 8002DA74 21186302 */  addu       $v1, $s3, $v1
    /* 1E278 8002DA78 0C00638C */  lw         $v1, 0xC($v1)
    /* 1E27C 8002DA7C 00110200 */  sll        $v0, $v0, 4
    /* 1E280 8002DA80 21186200 */  addu       $v1, $v1, $v0
    /* 1E284 8002DA84 10FF7024 */  addiu      $s0, $v1, -0xF0
    /* 1E288 8002DA88 0380023C */  lui        $v0, %hi(D_800335BC)
    /* 1E28C 8002DA8C BC35428C */  lw         $v0, %lo(D_800335BC)($v0)
    /* 1E290 8002DA90 00000000 */  nop
    /* 1E294 8002DA94 09F84000 */  jalr       $v0
    /* 1E298 8002DA98 21200002 */   addu      $a0, $s0, $zero
  .L8002DA9C:
    /* 1E29C 8002DA9C 0000438E */  lw         $v1, 0x0($s2)
    /* 1E2A0 8002DAA0 00000000 */  nop
    /* 1E2A4 8002DAA4 0F007510 */  beq        $v1, $s5, .L8002DAE4
    /* 1E2A8 8002DAA8 00000000 */   nop
    /* 1E2AC 8002DAAC 04006228 */  slti       $v0, $v1, 0x4
    /* 1E2B0 8002DAB0 07004010 */  beqz       $v0, .L8002DAD0
    /* 1E2B4 8002DAB4 02006228 */   slti      $v0, $v1, 0x2
    /* 1E2B8 8002DAB8 22004010 */  beqz       $v0, .L8002DB44
    /* 1E2BC 8002DABC 21202002 */   addu      $a0, $s1, $zero
    /* 1E2C0 8002DAC0 20006004 */  bltz       $v1, .L8002DB44
    /* 1E2C4 8002DAC4 00000000 */   nop
    /* 1E2C8 8002DAC8 C0B60008 */  j          .L8002DB00
    /* 1E2CC 8002DACC 00000000 */   nop
  .L8002DAD0:
    /* 1E2D0 8002DAD0 04000224 */  addiu      $v0, $zero, 0x4
    /* 1E2D4 8002DAD4 1B006214 */  bne        $v1, $v0, .L8002DB44
    /* 1E2D8 8002DAD8 21202002 */   addu      $a0, $s1, $zero
    /* 1E2DC 8002DADC D1B60008 */  j          .L8002DB44
    /* 1E2E0 8002DAE0 000055AE */   sw        $s5, 0x0($s2)
  .L8002DAE4:
    /* 1E2E4 8002DAE4 0380023C */  lui        $v0, %hi(D_800335BC)
    /* 1E2E8 8002DAE8 BC35428C */  lw         $v0, %lo(D_800335BC)($v0)
    /* 1E2EC 8002DAEC 00000000 */  nop
    /* 1E2F0 8002DAF0 09F84000 */  jalr       $v0
    /* 1E2F4 8002DAF4 10FF0426 */   addiu     $a0, $s0, -0xF0
    /* 1E2F8 8002DAF8 CFB60008 */  j          .L8002DB3C
    /* 1E2FC 8002DAFC 01000224 */   addiu     $v0, $zero, 0x1
  .L8002DB00:
    /* 1E300 8002DB00 0380023C */  lui        $v0, %hi(D_800335D0)
    /* 1E304 8002DB04 D035428C */  lw         $v0, %lo(D_800335D0)($v0)
    /* 1E308 8002DB08 00000000 */  nop
    /* 1E30C 8002DB0C 21805300 */  addu       $s0, $v0, $s3
    /* 1E310 8002DB10 0380023C */  lui        $v0, %hi(D_800335BC)
    /* 1E314 8002DB14 BC35428C */  lw         $v0, %lo(D_800335BC)($v0)
    /* 1E318 8002DB18 00000000 */  nop
    /* 1E31C 8002DB1C 09F84000 */  jalr       $v0
    /* 1E320 8002DB20 21200002 */   addu      $a0, $s0, $zero
    /* 1E324 8002DB24 0380023C */  lui        $v0, %hi(D_800335C0)
    /* 1E328 8002DB28 C035428C */  lw         $v0, %lo(D_800335C0)($v0)
    /* 1E32C 8002DB2C 00000000 */  nop
    /* 1E330 8002DB30 09F84000 */  jalr       $v0
    /* 1E334 8002DB34 21200002 */   addu      $a0, $s0, $zero
    /* 1E338 8002DB38 FFFF0224 */  addiu      $v0, $zero, -0x1
  .L8002DB3C:
    /* 1E33C 8002DB3C 000042AE */  sw         $v0, 0x0($s2)
    /* 1E340 8002DB40 21202002 */  addu       $a0, $s1, $zero
  .L8002DB44:
    /* 1E344 8002DB44 0380023C */  lui        $v0, %hi(D_800335A4)
    /* 1E348 8002DB48 A435428C */  lw         $v0, %lo(D_800335A4)($v0)
    /* 1E34C 8002DB4C 00000000 */  nop
    /* 1E350 8002DB50 09F84000 */  jalr       $v0
    /* 1E354 8002DB54 21288002 */   addu      $a1, $s4, $zero
    /* 1E358 8002DB58 21202002 */  addu       $a0, $s1, $zero
    /* 1E35C 8002DB5C 4AB1000C */  jal        _padSioRW
    /* 1E360 8002DB60 FF004530 */   andi      $a1, $v0, 0xFF
    /* 1E364 8002DB64 4B004004 */  bltz       $v0, .L8002DC94
    /* 1E368 8002DB68 00000000 */   nop
    /* 1E36C 8002DB6C FDB9000C */  jal        setRC2wait
    /* 1E370 8002DB70 3C000424 */   addiu     $a0, $zero, 0x3C
    /* 1E374 8002DB74 6CB2000C */  jal        _padClrIntSio0
    /* 1E378 8002DB78 00000000 */   nop
    /* 1E37C 8002DB7C 03004014 */  bnez       $v0, .L8002DB8C
    /* 1E380 8002DB80 00000000 */   nop
  .L8002DB84:
    /* 1E384 8002DB84 25B70008 */  j          .L8002DC94
    /* 1E388 8002DB88 FDFF0224 */   addiu     $v0, $zero, -0x3
  .L8002DB8C:
    /* 1E38C 8002DB8C 0380023C */  lui        $v0, %hi(D_80033614)
    /* 1E390 8002DB90 1436428C */  lw         $v0, %lo(D_80033614)($v0)
    /* 1E394 8002DB94 00000000 */  nop
    /* 1E398 8002DB98 FFFF4224 */  addiu      $v0, $v0, -0x1
    /* 1E39C 8002DB9C 0380013C */  lui        $at, %hi(D_80033614)
    /* 1E3A0 8002DBA0 143622AC */  sw         $v0, %lo(D_80033614)($at)
    /* 1E3A4 8002DBA4 02004228 */  slti       $v0, $v0, 0x2
    /* 1E3A8 8002DBA8 A9FF4010 */  beqz       $v0, .L8002DA50
    /* 1E3AC 8002DBAC 00000000 */   nop
  .L8002DBB0:
    /* 1E3B0 8002DBB0 0380023C */  lui        $v0, %hi(D_80033614)
    /* 1E3B4 8002DBB4 1436428C */  lw         $v0, %lo(D_80033614)($v0)
    /* 1E3B8 8002DBB8 00000000 */  nop
    /* 1E3BC 8002DBBC FFFF4224 */  addiu      $v0, $v0, -0x1
    /* 1E3C0 8002DBC0 0380013C */  lui        $at, %hi(D_80033614)
    /* 1E3C4 8002DBC4 21004018 */  blez       $v0, .L8002DC4C
    /* 1E3C8 8002DBC8 143622AC */   sw        $v0, %lo(D_80033614)($at)
    /* 1E3CC 8002DBCC 22001024 */  addiu      $s0, $zero, 0x22
  .L8002DBD0:
    /* 1E3D0 8002DBD0 21202002 */  addu       $a0, $s1, $zero
    /* 1E3D4 8002DBD4 0380023C */  lui        $v0, %hi(D_800335A4)
    /* 1E3D8 8002DBD8 A435428C */  lw         $v0, %lo(D_800335A4)($v0)
    /* 1E3DC 8002DBDC 00000000 */  nop
    /* 1E3E0 8002DBE0 09F84000 */  jalr       $v0
    /* 1E3E4 8002DBE4 21288002 */   addu      $a1, $s4, $zero
    /* 1E3E8 8002DBE8 21202002 */  addu       $a0, $s1, $zero
    /* 1E3EC 8002DBEC 4AB1000C */  jal        _padSioRW
    /* 1E3F0 8002DBF0 FF004530 */   andi      $a1, $v0, 0xFF
    /* 1E3F4 8002DBF4 27004004 */  bltz       $v0, .L8002DC94
    /* 1E3F8 8002DBF8 00000000 */   nop
    /* 1E3FC 8002DBFC 0380023C */  lui        $v0, %hi(D_80033618)
    /* 1E400 8002DC00 1836428C */  lw         $v0, %lo(D_80033618)($v0)
    /* 1E404 8002DC04 00000000 */  nop
    /* 1E408 8002DC08 0E004294 */  lhu        $v0, 0xE($v0)
    /* 1E40C 8002DC0C 00000000 */  nop
    /* 1E410 8002DC10 07005010 */  beq        $v0, $s0, .L8002DC30
    /* 1E414 8002DC14 00000000 */   nop
    /* 1E418 8002DC18 FDB9000C */  jal        setRC2wait
    /* 1E41C 8002DC1C 3C000424 */   addiu     $a0, $zero, 0x3C
    /* 1E420 8002DC20 6CB2000C */  jal        _padClrIntSio0
    /* 1E424 8002DC24 00000000 */   nop
    /* 1E428 8002DC28 1A004010 */  beqz       $v0, .L8002DC94
    /* 1E42C 8002DC2C FDFF0224 */   addiu     $v0, $zero, -0x3
  .L8002DC30:
    /* 1E430 8002DC30 0380023C */  lui        $v0, %hi(D_80033614)
    /* 1E434 8002DC34 1436428C */  lw         $v0, %lo(D_80033614)($v0)
    /* 1E438 8002DC38 00000000 */  nop
    /* 1E43C 8002DC3C FFFF4224 */  addiu      $v0, $v0, -0x1
    /* 1E440 8002DC40 0380013C */  lui        $at, %hi(D_80033614)
    /* 1E444 8002DC44 E2FF401C */  bgtz       $v0, .L8002DBD0
    /* 1E448 8002DC48 143622AC */   sw        $v0, %lo(D_80033614)($at)
  .L8002DC4C:
    /* 1E44C 8002DC4C 90B2000C */  jal        _padWaitRXready
    /* 1E450 8002DC50 00000000 */   nop
    /* 1E454 8002DC54 44002392 */  lbu        $v1, 0x44($s1)
    /* 1E458 8002DC58 00000000 */  nop
    /* 1E45C 8002DC5C 01006224 */  addiu      $v0, $v1, 0x1
    /* 1E460 8002DC60 440022A2 */  sb         $v0, 0x44($s1)
    /* 1E464 8002DC64 0380023C */  lui        $v0, %hi(D_80033618)
    /* 1E468 8002DC68 1836428C */  lw         $v0, %lo(D_80033618)($v0)
    /* 1E46C 8002DC6C 3C00248E */  lw         $a0, 0x3C($s1)
    /* 1E470 8002DC70 00004290 */  lbu        $v0, 0x0($v0)
    /* 1E474 8002DC74 21186400 */  addu       $v1, $v1, $a0
    /* 1E478 8002DC78 000062A0 */  sb         $v0, 0x0($v1)
    /* 1E47C 8002DC7C 0380023C */  lui        $v0, %hi(D_8003359C)
    /* 1E480 8002DC80 9C35428C */  lw         $v0, %lo(D_8003359C)($v0)
    /* 1E484 8002DC84 00000000 */  nop
    /* 1E488 8002DC88 09F84000 */  jalr       $v0
    /* 1E48C 8002DC8C 21200000 */   addu      $a0, $zero, $zero
    /* 1E490 8002DC90 21100000 */  addu       $v0, $zero, $zero
  .L8002DC94:
    /* 1E494 8002DC94 2800BF8F */  lw         $ra, 0x28($sp)
    /* 1E498 8002DC98 2400B58F */  lw         $s5, 0x24($sp)
    /* 1E49C 8002DC9C 2000B48F */  lw         $s4, 0x20($sp)
    /* 1E4A0 8002DCA0 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 1E4A4 8002DCA4 1800B28F */  lw         $s2, 0x18($sp)
    /* 1E4A8 8002DCA8 1400B18F */  lw         $s1, 0x14($sp)
    /* 1E4AC 8002DCAC 1000B08F */  lw         $s0, 0x10($sp)
    /* 1E4B0 8002DCB0 0800E003 */  jr         $ra
    /* 1E4B4 8002DCB4 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel func_8002D924
    /* 1E4B8 8002DCB8 00000000 */  nop
    /* 1E4BC 8002DCBC 00000000 */  nop
    /* 1E4C0 8002DCC0 00000000 */  nop
