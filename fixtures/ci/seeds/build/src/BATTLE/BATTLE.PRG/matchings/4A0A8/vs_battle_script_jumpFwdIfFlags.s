nonmatching vs_battle_script_jumpFwdIfFlags, 0x14C

glabel vs_battle_script_jumpFwdIfFlags
    /* 50210 800B8A10 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 50214 800B8A14 1400B1AF */  sw         $s1, 0x14($sp)
    /* 50218 800B8A18 21888000 */  addu       $s1, $a0, $zero
    /* 5021C 800B8A1C 1800BFAF */  sw         $ra, 0x18($sp)
    /* 50220 800B8A20 1000B0AF */  sw         $s0, 0x10($sp)
    /* 50224 800B8A24 02002292 */  lbu        $v0, 0x2($s1)
    /* 50228 800B8A28 01002492 */  lbu        $a0, 0x1($s1)
    /* 5022C 800B8A2C 82100200 */  srl        $v0, $v0, 2
    /* 50230 800B8A30 0F008430 */  andi       $a0, $a0, 0xF
    /* 50234 800B8A34 80210400 */  sll        $a0, $a0, 6
    /* 50238 800B8A38 FDFA020C */  jal        vs_battle_getStateFlag
    /* 5023C 800B8A3C 25204400 */   or        $a0, $v0, $a0
    /* 50240 800B8A40 21804000 */  addu       $s0, $v0, $zero
    /* 50244 800B8A44 02002492 */  lbu        $a0, 0x2($s1)
    /* 50248 800B8A48 03002392 */  lbu        $v1, 0x3($s1)
    /* 5024C 800B8A4C 03008430 */  andi       $a0, $a0, 0x3
    /* 50250 800B8A50 00220400 */  sll        $a0, $a0, 8
    /* 50254 800B8A54 FDFA020C */  jal        vs_battle_getStateFlag
    /* 50258 800B8A58 25206400 */   or        $a0, $v1, $a0
    /* 5025C 800B8A5C 21204000 */  addu       $a0, $v0, $zero
    /* 50260 800B8A60 01002392 */  lbu        $v1, 0x1($s1)
    /* 50264 800B8A64 20000224 */  addiu      $v0, $zero, 0x20
    /* 50268 800B8A68 F0006330 */  andi       $v1, $v1, 0xF0
    /* 5026C 800B8A6C 1F006210 */  beq        $v1, $v0, .L800B8AEC
    /* 50270 800B8A70 21006228 */   slti      $v0, $v1, 0x21
    /* 50274 800B8A74 07004010 */  beqz       $v0, .L800B8A94
    /* 50278 800B8A78 40000224 */   addiu     $v0, $zero, 0x40
    /* 5027C 800B8A7C 12006010 */  beqz       $v1, .L800B8AC8
    /* 50280 800B8A80 10000224 */   addiu     $v0, $zero, 0x10
    /* 50284 800B8A84 13006210 */  beq        $v1, $v0, .L800B8AD4
    /* 50288 800B8A88 FF000232 */   andi      $v0, $s0, 0xFF
    /* 5028C 800B8A8C CDE20208 */  j          .L800B8B34
    /* 50290 800B8A90 00000000 */   nop
  .L800B8A94:
    /* 50294 800B8A94 20006210 */  beq        $v1, $v0, .L800B8B18
    /* 50298 800B8A98 41006228 */   slti      $v0, $v1, 0x41
    /* 5029C 800B8A9C 05004010 */  beqz       $v0, .L800B8AB4
    /* 502A0 800B8AA0 30000224 */   addiu     $v0, $zero, 0x30
    /* 502A4 800B8AA4 17006210 */  beq        $v1, $v0, .L800B8B04
    /* 502A8 800B8AA8 FF000332 */   andi      $v1, $s0, 0xFF
    /* 502AC 800B8AAC CDE20208 */  j          .L800B8B34
    /* 502B0 800B8AB0 00000000 */   nop
  .L800B8AB4:
    /* 502B4 800B8AB4 50000224 */  addiu      $v0, $zero, 0x50
    /* 502B8 800B8AB8 1A006210 */  beq        $v1, $v0, .L800B8B24
    /* 502BC 800B8ABC FF000332 */   andi      $v1, $s0, 0xFF
    /* 502C0 800B8AC0 CDE20208 */  j          .L800B8B34
    /* 502C4 800B8AC4 00000000 */   nop
  .L800B8AC8:
    /* 502C8 800B8AC8 FF000332 */  andi       $v1, $s0, 0xFF
    /* 502CC 800B8ACC B6E20208 */  j          .L800B8AD8
    /* 502D0 800B8AD0 FF008230 */   andi      $v0, $a0, 0xFF
  .L800B8AD4:
    /* 502D4 800B8AD4 FF008330 */  andi       $v1, $a0, 0xFF
  .L800B8AD8:
    /* 502D8 800B8AD8 2B104300 */  sltu       $v0, $v0, $v1
    /* 502DC 800B8ADC 15004014 */  bnez       $v0, .L800B8B34
    /* 502E0 800B8AE0 21100000 */   addu      $v0, $zero, $zero
    /* 502E4 800B8AE4 D2E20208 */  j          .L800B8B48
    /* 502E8 800B8AE8 00000000 */   nop
  .L800B8AEC:
    /* 502EC 800B8AEC FF000332 */  andi       $v1, $s0, 0xFF
    /* 502F0 800B8AF0 FF008230 */  andi       $v0, $a0, 0xFF
    /* 502F4 800B8AF4 0F006214 */  bne        $v1, $v0, .L800B8B34
    /* 502F8 800B8AF8 21100000 */   addu      $v0, $zero, $zero
    /* 502FC 800B8AFC D2E20208 */  j          .L800B8B48
    /* 50300 800B8B00 00000000 */   nop
  .L800B8B04:
    /* 50304 800B8B04 FF008230 */  andi       $v0, $a0, 0xFF
    /* 50308 800B8B08 0A006210 */  beq        $v1, $v0, .L800B8B34
    /* 5030C 800B8B0C 21100000 */   addu      $v0, $zero, $zero
    /* 50310 800B8B10 D2E20208 */  j          .L800B8B48
    /* 50314 800B8B14 00000000 */   nop
  .L800B8B18:
    /* 50318 800B8B18 FF000232 */  andi       $v0, $s0, 0xFF
    /* 5031C 800B8B1C CAE20208 */  j          .L800B8B28
    /* 50320 800B8B20 FF008330 */   andi      $v1, $a0, 0xFF
  .L800B8B24:
    /* 50324 800B8B24 FF008230 */  andi       $v0, $a0, 0xFF
  .L800B8B28:
    /* 50328 800B8B28 2B104300 */  sltu       $v0, $v0, $v1
    /* 5032C 800B8B2C 06004014 */  bnez       $v0, .L800B8B48
    /* 50330 800B8B30 21100000 */   addu      $v0, $zero, $zero
  .L800B8B34:
    /* 50334 800B8B34 80FF020C */  jal        vs_battle_getShort
    /* 50338 800B8B38 04002426 */   addiu     $a0, $s1, 0x4
    /* 5033C 800B8B3C 00140200 */  sll        $v0, $v0, 16
    /* 50340 800B8B40 03140200 */  sra        $v0, $v0, 16
    /* 50344 800B8B44 21102202 */  addu       $v0, $s1, $v0
  .L800B8B48:
    /* 50348 800B8B48 1800BF8F */  lw         $ra, 0x18($sp)
    /* 5034C 800B8B4C 1400B18F */  lw         $s1, 0x14($sp)
    /* 50350 800B8B50 1000B08F */  lw         $s0, 0x10($sp)
    /* 50354 800B8B54 0800E003 */  jr         $ra
    /* 50358 800B8B58 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel vs_battle_script_jumpFwdIfFlags
