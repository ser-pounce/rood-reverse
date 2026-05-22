nonmatching func_800CC204, 0x37C

glabel func_800CC204
    /* 63A04 800CC204 E8FBBD27 */  addiu      $sp, $sp, -0x418
    /* 63A08 800CC208 F403B1AF */  sw         $s1, 0x3F4($sp)
    /* 63A0C 800CC20C 21888000 */  addu       $s1, $a0, $zero
    /* 63A10 800CC210 2158C000 */  addu       $t3, $a2, $zero
    /* 63A14 800CC214 00022C26 */  addiu      $t4, $s1, 0x200
    /* 63A18 800CC218 1404BFAF */  sw         $ra, 0x414($sp)
    /* 63A1C 800CC21C 1004BEAF */  sw         $fp, 0x410($sp)
    /* 63A20 800CC220 0C04B7AF */  sw         $s7, 0x40C($sp)
    /* 63A24 800CC224 0804B6AF */  sw         $s6, 0x408($sp)
    /* 63A28 800CC228 0404B5AF */  sw         $s5, 0x404($sp)
    /* 63A2C 800CC22C 0004B4AF */  sw         $s4, 0x400($sp)
    /* 63A30 800CC230 FC03B3AF */  sw         $s3, 0x3FC($sp)
    /* 63A34 800CC234 F803B2AF */  sw         $s2, 0x3F8($sp)
    /* 63A38 800CC238 F003B0AF */  sw         $s0, 0x3F0($sp)
    /* 63A3C 800CC23C 1C04A5AF */  sw         $a1, 0x41C($sp)
    /* 63A40 800CC240 0000228E */  lw         $v0, 0x0($s1)
    /* 63A44 800CC244 03003692 */  lbu        $s6, 0x3($s1)
    /* 63A48 800CC248 82500200 */  srl        $t2, $v0, 2
    /* 63A4C 800CC24C 0C002296 */  lhu        $v0, 0xC($s1)
    /* 63A50 800CC250 18002726 */  addiu      $a3, $s1, 0x18
    /* 63A54 800CC254 D003ACAF */  sw         $t4, 0x3D0($sp)
    /* 63A58 800CC258 FF3F5030 */  andi       $s0, $v0, 0x3FFF
    /* 63A5C 800CC25C 02002292 */  lbu        $v0, 0x2($s1)
    /* 63A60 800CC260 00000000 */  nop
    /* 63A64 800CC264 EEFF4224 */  addiu      $v0, $v0, -0x12
    /* 63A68 800CC268 D403A2AF */  sw         $v0, 0x3D4($sp)
    /* 63A6C 800CC26C 00100224 */  addiu      $v0, $zero, 0x1000
    /* 63A70 800CC270 0E002896 */  lhu        $t0, 0xE($s1)
    /* 63A74 800CC274 06000216 */  bne        $s0, $v0, .L800CC290
    /* 63A78 800CC278 01004A31 */   andi      $t2, $t2, 0x1
    /* 63A7C 800CC27C 80000224 */  addiu      $v0, $zero, 0x80
    /* 63A80 800CC280 F32E030C */  jal        func_800CBBCC
    /* 63A84 800CC284 030022A2 */   sb        $v0, 0x3($s1)
    /* 63A88 800CC288 54310308 */  j          .L800CC550
    /* 63A8C 800CC28C 030036A2 */   sb        $s6, 0x3($s1)
  .L800CC290:
    /* 63A90 800CC290 0010022A */  slti       $v0, $s0, 0x1000
    /* 63A94 800CC294 19004010 */  beqz       $v0, .L800CC2FC
    /* 63A98 800CC298 21980000 */   addu      $s3, $zero, $zero
    /* 63A9C 800CC29C 40010624 */  addiu      $a2, $zero, 0x140
    /* 63AA0 800CC2A0 F001A427 */  addiu      $a0, $sp, 0x1F0
    /* 63AA4 800CC2A4 1000A327 */  addiu      $v1, $sp, 0x10
    /* 63AA8 800CC2A8 2128E000 */  addu       $a1, $a3, $zero
  .L800CC2AC:
    /* 63AAC 800CC2AC 0000A294 */  lhu        $v0, 0x0($a1)
    /* 63AB0 800CC2B0 00000000 */  nop
    /* 63AB4 800CC2B4 18005000 */  mult       $v0, $s0
    /* 63AB8 800CC2B8 12600000 */  mflo       $t4
    /* 63ABC 800CC2BC 0500C012 */  beqz       $s6, .L800CC2D4
    /* 63AC0 800CC2C0 03930C00 */   sra       $s2, $t4, 12
    /* 63AC4 800CC2C4 2310D200 */  subu       $v0, $a2, $s2
    /* 63AC8 800CC2C8 000062A4 */  sh         $v0, 0x0($v1)
    /* 63ACC 800CC2CC B7300308 */  j          .L800CC2DC
    /* 63AD0 800CC2D0 000086A4 */   sh        $a2, 0x0($a0)
  .L800CC2D4:
    /* 63AD4 800CC2D4 000060A4 */  sh         $zero, 0x0($v1)
    /* 63AD8 800CC2D8 000092A4 */  sh         $s2, 0x0($a0)
  .L800CC2DC:
    /* 63ADC 800CC2DC 02008424 */  addiu      $a0, $a0, 0x2
    /* 63AE0 800CC2E0 02006324 */  addiu      $v1, $v1, 0x2
    /* 63AE4 800CC2E4 01007326 */  addiu      $s3, $s3, 0x1
    /* 63AE8 800CC2E8 F000622A */  slti       $v0, $s3, 0xF0
    /* 63AEC 800CC2EC EFFF4014 */  bnez       $v0, .L800CC2AC
    /* 63AF0 800CC2F0 0200A524 */   addiu     $a1, $a1, 0x2
    /* 63AF4 800CC2F4 D6300308 */  j          .L800CC358
    /* 63AF8 800CC2F8 21980000 */   addu      $s3, $zero, $zero
  .L800CC2FC:
    /* 63AFC 800CC2FC 00F00326 */  addiu      $v1, $s0, -0x1000
    /* 63B00 800CC300 40010924 */  addiu      $t1, $zero, 0x140
    /* 63B04 800CC304 F001A527 */  addiu      $a1, $sp, 0x1F0
    /* 63B08 800CC308 1000A427 */  addiu      $a0, $sp, 0x10
  .L800CC30C:
    /* 63B0C 800CC30C 0000E294 */  lhu        $v0, 0x0($a3)
    /* 63B10 800CC310 00000000 */  nop
    /* 63B14 800CC314 18004300 */  mult       $v0, $v1
    /* 63B18 800CC318 12600000 */  mflo       $t4
    /* 63B1C 800CC31C 0500C012 */  beqz       $s6, .L800CC334
    /* 63B20 800CC320 03930C00 */   sra       $s2, $t4, 12
    /* 63B24 800CC324 23103201 */  subu       $v0, $t1, $s2
    /* 63B28 800CC328 000080A4 */  sh         $zero, 0x0($a0)
    /* 63B2C 800CC32C CF300308 */  j          .L800CC33C
    /* 63B30 800CC330 0000A2A4 */   sh        $v0, 0x0($a1)
  .L800CC334:
    /* 63B34 800CC334 000092A4 */  sh         $s2, 0x0($a0)
    /* 63B38 800CC338 0000A9A4 */  sh         $t1, 0x0($a1)
  .L800CC33C:
    /* 63B3C 800CC33C 0200A524 */  addiu      $a1, $a1, 0x2
    /* 63B40 800CC340 02008424 */  addiu      $a0, $a0, 0x2
    /* 63B44 800CC344 01007326 */  addiu      $s3, $s3, 0x1
    /* 63B48 800CC348 F000622A */  slti       $v0, $s3, 0xF0
    /* 63B4C 800CC34C EFFF4014 */  bnez       $v0, .L800CC30C
    /* 63B50 800CC350 0200E724 */   addiu     $a3, $a3, 0x2
    /* 63B54 800CC354 21980000 */  addu       $s3, $zero, $zero
  .L800CC358:
    /* 63B58 800CC358 88880C3C */  lui        $t4, (0x88888889 >> 16)
    /* 63B5C 800CC35C 89888C35 */  ori        $t4, $t4, (0x88888889 & 0xFFFF)
    /* 63B60 800CC360 03004231 */  andi       $v0, $t2, 0x3
    /* 63B64 800CC364 C0110200 */  sll        $v0, $v0, 7
    /* 63B68 800CC368 21B86002 */  addu       $s7, $s3, $zero
    /* 63B6C 800CC36C DC03ACAF */  sw         $t4, 0x3DC($sp)
    /* 63B70 800CC370 E003A2AF */  sw         $v0, 0x3E0($sp)
  .L800CC374:
    /* 63B74 800CC374 DC03AC8F */  lw         $t4, 0x3DC($sp)
    /* 63B78 800CC378 00000000 */  nop
    /* 63B7C 800CC37C 18006C02 */  mult       $s3, $t4
    /* 63B80 800CC380 21900000 */  addu       $s2, $zero, $zero
    /* 63B84 800CC384 40001424 */  addiu      $s4, $zero, 0x40
    /* 63B88 800CC388 C31F1300 */  sra        $v1, $s3, 31
    /* 63B8C 800CC38C 40601300 */  sll        $t4, $s3, 1
    /* 63B90 800CC390 D803ACAF */  sw         $t4, 0x3D8($sp)
    /* 63B94 800CC394 10600000 */  mfhi       $t4
    /* 63B98 800CC398 21109301 */  addu       $v0, $t4, $s3
    /* 63B9C 800CC39C C3100200 */  sra        $v0, $v0, 3
    /* 63BA0 800CC3A0 23A84300 */  subu       $s5, $v0, $v1
  .L800CC3A4:
    /* 63BA4 800CC3A4 D803AC8F */  lw         $t4, 0x3D8($sp)
    /* 63BA8 800CC3A8 00000000 */  nop
    /* 63BAC 800CC3AC 2110AC03 */  addu       $v0, $sp, $t4
    /* 63BB0 800CC3B0 10005084 */  lh         $s0, 0x10($v0)
    /* 63BB4 800CC3B4 00000000 */  nop
    /* 63BB8 800CC3B8 2A101402 */  slt        $v0, $s0, $s4
    /* 63BBC 800CC3BC 5A004010 */  beqz       $v0, .L800CC528
    /* 63BC0 800CC3C0 2110AC03 */   addu      $v0, $sp, $t4
    /* 63BC4 800CC3C4 F0015684 */  lh         $s6, 0x1F0($v0)
    /* 63BC8 800CC3C8 80191200 */  sll        $v1, $s2, 6
    /* 63BCC 800CC3CC 2A107600 */  slt        $v0, $v1, $s6
    /* 63BD0 800CC3D0 55004010 */  beqz       $v0, .L800CC528
    /* 63BD4 800CC3D4 2A100302 */   slt       $v0, $s0, $v1
    /* 63BD8 800CC3D8 02004010 */  beqz       $v0, .L800CC3E4
    /* 63BDC 800CC3DC 2A109602 */   slt       $v0, $s4, $s6
    /* 63BE0 800CC3E0 21806000 */  addu       $s0, $v1, $zero
  .L800CC3E4:
    /* 63BE4 800CC3E4 02004010 */  beqz       $v0, .L800CC3F0
    /* 63BE8 800CC3E8 80101500 */   sll       $v0, $s5, 2
    /* 63BEC 800CC3EC 21B08002 */  addu       $s6, $s4, $zero
  .L800CC3F0:
    /* 63BF0 800CC3F0 21105500 */  addu       $v0, $v0, $s5
    /* 63BF4 800CC3F4 21105200 */  addu       $v0, $v0, $s2
    /* 63BF8 800CC3F8 D003AC8F */  lw         $t4, 0x3D0($sp)
    /* 63BFC 800CC3FC 40100200 */  sll        $v0, $v0, 1
    /* 63C00 800CC400 21104C00 */  addu       $v0, $v0, $t4
    /* 63C04 800CC404 00005194 */  lhu        $s1, 0x0($v0)
    /* 63C08 800CC408 00000000 */  nop
    /* 63C0C 800CC40C 31002012 */  beqz       $s1, .L800CC4D4
    /* 63C10 800CC410 03121100 */   sra       $v0, $s1, 8
    /* 63C14 800CC414 D403AC8F */  lw         $t4, 0x3D4($sp)
    /* 63C18 800CC418 00000000 */  nop
    /* 63C1C 800CC41C 21108201 */  addu       $v0, $t4, $v0
    /* 63C20 800CC420 0F004230 */  andi       $v0, $v0, 0xF
    /* 63C24 800CC424 E003AC8F */  lw         $t4, 0x3E0($sp)
    /* 63C28 800CC428 30004234 */  ori        $v0, $v0, 0x30
    /* 63C2C 800CC42C 25F08201 */  or         $fp, $t4, $v0
    /* 63C30 800CC430 01000232 */  andi       $v0, $s0, 0x1
  .L800CC434:
    /* 63C34 800CC434 05004014 */  bnez       $v0, .L800CC44C
    /* 63C38 800CC438 25281702 */   or        $a1, $s0, $s7
    /* 63C3C 800CC43C 2318D002 */  subu       $v1, $s6, $s0
    /* 63C40 800CC440 0100023C */  lui        $v0, (0x10000 >> 16)
    /* 63C44 800CC444 15310308 */  j          .L800CC454
    /* 63C48 800CC448 25306200 */   or        $a2, $v1, $v0
  .L800CC44C:
    /* 63C4C 800CC44C 0100063C */  lui        $a2, (0x10001 >> 16)
    /* 63C50 800CC450 0100C634 */  ori        $a2, $a2, (0x10001 & 0xFFFF)
  .L800CC454:
    /* 63C54 800CC454 80000424 */  addiu      $a0, $zero, 0x80
    /* 63C58 800CC458 21386001 */  addu       $a3, $t3, $zero
    /* 63C5C 800CC45C E803A8AF */  sw         $t0, 0x3E8($sp)
    /* 63C60 800CC460 8C00030C */  jal        vs_battle_setSprite
    /* 63C64 800CC464 EC03ABAF */   sw        $t3, 0x3EC($sp)
    /* 63C68 800CC468 00E1033C */  lui        $v1, (0xE1000000 >> 16)
    /* 63C6C 800CC46C 2518C303 */  or         $v1, $fp, $v1
    /* 63C70 800CC470 03002532 */  andi       $a1, $s1, 0x3
    /* 63C74 800CC474 80290500 */  sll        $a1, $a1, 6
    /* 63C78 800CC478 040043AC */  sw         $v1, 0x4($v0)
    /* 63C7C 800CC47C 3F000332 */  andi       $v1, $s0, 0x3F
    /* 63C80 800CC480 2128A300 */  addu       $a1, $a1, $v1
    /* 63C84 800CC484 83181100 */  sra        $v1, $s1, 2
    /* 63C88 800CC488 1F006330 */  andi       $v1, $v1, 0x1F
    /* 63C8C 800CC48C 00210300 */  sll        $a0, $v1, 4
    /* 63C90 800CC490 23208300 */  subu       $a0, $a0, $v1
    /* 63C94 800CC494 00191500 */  sll        $v1, $s5, 4
    /* 63C98 800CC498 23187500 */  subu       $v1, $v1, $s5
    /* 63C9C 800CC49C 23186302 */  subu       $v1, $s3, $v1
    /* 63CA0 800CC4A0 21208300 */  addu       $a0, $a0, $v1
    /* 63CA4 800CC4A4 00220400 */  sll        $a0, $a0, 8
    /* 63CA8 800CC4A8 1C04AC8F */  lw         $t4, 0x41C($sp)
    /* 63CAC 800CC4AC 2528A400 */  or         $a1, $a1, $a0
    /* 63CB0 800CC4B0 2528AC00 */  or         $a1, $a1, $t4
    /* 63CB4 800CC4B4 100045AC */  sw         $a1, 0x10($v0)
    /* 63CB8 800CC4B8 01000232 */  andi       $v0, $s0, 0x1
    /* 63CBC 800CC4BC E803A88F */  lw         $t0, 0x3E8($sp)
    /* 63CC0 800CC4C0 EC03AB8F */  lw         $t3, 0x3EC($sp)
    /* 63CC4 800CC4C4 18004010 */  beqz       $v0, .L800CC528
    /* 63CC8 800CC4C8 01001026 */   addiu     $s0, $s0, 0x1
    /* 63CCC 800CC4CC 0D310308 */  j          .L800CC434
    /* 63CD0 800CC4D0 01000232 */   andi      $v0, $s0, 0x1
  .L800CC4D4:
    /* 63CD4 800CC4D4 14000011 */  beqz       $t0, .L800CC528
    /* 63CD8 800CC4D8 21206001 */   addu      $a0, $t3, $zero
    /* 63CDC 800CC4DC 1F000331 */  andi       $v1, $t0, 0x1F
    /* 63CE0 800CC4E0 C0180300 */  sll        $v1, $v1, 3
    /* 63CE4 800CC4E4 E0030231 */  andi       $v0, $t0, 0x3E0
    /* 63CE8 800CC4E8 80110200 */  sll        $v0, $v0, 6
    /* 63CEC 800CC4EC 25186200 */  or         $v1, $v1, $v0
    /* 63CF0 800CC4F0 007C0231 */  andi       $v0, $t0, 0x7C00
    /* 63CF4 800CC4F4 40120200 */  sll        $v0, $v0, 9
    /* 63CF8 800CC4F8 25186200 */  or         $v1, $v1, $v0
    /* 63CFC 800CC4FC 0040053C */  lui        $a1, (0x40000000 >> 16)
    /* 63D00 800CC500 25286500 */  or         $a1, $v1, $a1
    /* 63D04 800CC504 FFFF0632 */  andi       $a2, $s0, 0xFFFF
    /* 63D08 800CC508 2530D700 */  or         $a2, $a2, $s7
    /* 63D0C 800CC50C FFFFC726 */  addiu      $a3, $s6, -0x1
    /* 63D10 800CC510 2538F700 */  or         $a3, $a3, $s7
    /* 63D14 800CC514 E803A8AF */  sw         $t0, 0x3E8($sp)
    /* 63D18 800CC518 2E33030C */  jal        func_800CCCB8
    /* 63D1C 800CC51C EC03ABAF */   sw        $t3, 0x3EC($sp)
    /* 63D20 800CC520 EC03AB8F */  lw         $t3, 0x3EC($sp)
    /* 63D24 800CC524 E803A88F */  lw         $t0, 0x3E8($sp)
  .L800CC528:
    /* 63D28 800CC528 01005226 */  addiu      $s2, $s2, 0x1
    /* 63D2C 800CC52C 0500422A */  slti       $v0, $s2, 0x5
    /* 63D30 800CC530 9CFF4014 */  bnez       $v0, .L800CC3A4
    /* 63D34 800CC534 40009426 */   addiu     $s4, $s4, 0x40
    /* 63D38 800CC538 0100023C */  lui        $v0, (0x10000 >> 16)
    /* 63D3C 800CC53C 21B8E202 */  addu       $s7, $s7, $v0
    /* 63D40 800CC540 01007326 */  addiu      $s3, $s3, 0x1
    /* 63D44 800CC544 F000622A */  slti       $v0, $s3, 0xF0
    /* 63D48 800CC548 8AFF4014 */  bnez       $v0, .L800CC374
    /* 63D4C 800CC54C 00000000 */   nop
  .L800CC550:
    /* 63D50 800CC550 1404BF8F */  lw         $ra, 0x414($sp)
    /* 63D54 800CC554 1004BE8F */  lw         $fp, 0x410($sp)
    /* 63D58 800CC558 0C04B78F */  lw         $s7, 0x40C($sp)
    /* 63D5C 800CC55C 0804B68F */  lw         $s6, 0x408($sp)
    /* 63D60 800CC560 0404B58F */  lw         $s5, 0x404($sp)
    /* 63D64 800CC564 0004B48F */  lw         $s4, 0x400($sp)
    /* 63D68 800CC568 FC03B38F */  lw         $s3, 0x3FC($sp)
    /* 63D6C 800CC56C F803B28F */  lw         $s2, 0x3F8($sp)
    /* 63D70 800CC570 F403B18F */  lw         $s1, 0x3F4($sp)
    /* 63D74 800CC574 F003B08F */  lw         $s0, 0x3F0($sp)
    /* 63D78 800CC578 0800E003 */  jr         $ra
    /* 63D7C 800CC57C 1804BD27 */   addiu     $sp, $sp, 0x418
endlabel func_800CC204
