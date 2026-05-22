nonmatching func_800FA2CC, 0x130

glabel func_800FA2CC
    /* ACC 800FA2CC D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* AD0 800FA2D0 0F80023C */  lui        $v0, %hi(D_800F4538)
    /* AD4 800FA2D4 21280000 */  addu       $a1, $zero, $zero
    /* AD8 800FA2D8 8000073C */  lui        $a3, (0x800000 >> 16)
    /* ADC 800FA2DC 40000624 */  addiu      $a2, $zero, 0x40
    /* AE0 800FA2E0 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* AE4 800FA2E4 3845518C */  lw         $s1, %lo(D_800F4538)($v0)
    /* AE8 800FA2E8 0F80023C */  lui        $v0, %hi(D_800F4588)
    /* AEC 800FA2EC 88454424 */  addiu      $a0, $v0, %lo(D_800F4588)
    /* AF0 800FA2F0 2000BFAF */  sw         $ra, 0x20($sp)
    /* AF4 800FA2F4 1800B0AF */  sw         $s0, 0x18($sp)
  .L800FA2F8:
    /* AF8 800FA2F8 0000838C */  lw         $v1, 0x0($a0)
    /* AFC 800FA2FC 00000000 */  nop
    /* B00 800FA300 0C006010 */  beqz       $v1, .L800FA334
    /* B04 800FA304 00000000 */   nop
    /* B08 800FA308 0800228E */  lw         $v0, 0x8($s1)
    /* B0C 800FA30C 00000000 */  nop
    /* B10 800FA310 24104700 */  and        $v0, $v0, $a3
    /* B14 800FA314 06004010 */  beqz       $v0, .L800FA330
    /* B18 800FA318 00000000 */   nop
    /* B1C 800FA31C 0800628C */  lw         $v0, 0x8($v1)
    /* B20 800FA320 110066A0 */  sb         $a2, 0x11($v1)
    /* B24 800FA324 10004234 */  ori        $v0, $v0, 0x10
    /* B28 800FA328 CDE80308 */  j          .L800FA334
    /* B2C 800FA32C 080062AC */   sw        $v0, 0x8($v1)
  .L800FA330:
    /* B30 800FA330 110060A0 */  sb         $zero, 0x11($v1)
  .L800FA334:
    /* B34 800FA334 0100A524 */  addiu      $a1, $a1, 0x1
    /* B38 800FA338 0200A228 */  slti       $v0, $a1, 0x2
    /* B3C 800FA33C EEFF4014 */  bnez       $v0, .L800FA2F8
    /* B40 800FA340 04008424 */   addiu     $a0, $a0, 0x4
    /* B44 800FA344 8D79020C */  jal        func_8009E634
    /* B48 800FA348 21202002 */   addu      $a0, $s1, $zero
    /* B4C 800FA34C 0800228E */  lw         $v0, 0x8($s1)
    /* B50 800FA350 8000033C */  lui        $v1, (0x800000 >> 16)
    /* B54 800FA354 24104300 */  and        $v0, $v0, $v1
    /* B58 800FA358 02004010 */  beqz       $v0, .L800FA364
    /* B5C 800FA35C 01000524 */   addiu     $a1, $zero, 0x1
    /* B60 800FA360 65000524 */  addiu      $a1, $zero, 0x65
  .L800FA364:
    /* B64 800FA364 EFFF033C */  lui        $v1, (0xFFEFFFFF >> 16)
    /* B68 800FA368 FFFF6334 */  ori        $v1, $v1, (0xFFEFFFFF & 0xFFFF)
    /* B6C 800FA36C 21202002 */  addu       $a0, $s1, $zero
    /* B70 800FA370 AC05228E */  lw         $v0, 0x5AC($s1)
    /* B74 800FA374 1000A627 */  addiu      $a2, $sp, 0x10
    /* B78 800FA378 B80525A2 */  sb         $a1, 0x5B8($s1)
    /* B7C 800FA37C 24104300 */  and        $v0, $v0, $v1
    /* B80 800FA380 25B5020C */  jal        func_800AD494
    /* B84 800FA384 AC0522AE */   sw        $v0, 0x5AC($s1)
    /* B88 800FA388 0F80033C */  lui        $v1, %hi(D_800F49DC)
    /* B8C 800FA38C DC496390 */  lbu        $v1, %lo(D_800F49DC)($v1)
    /* B90 800FA390 21202002 */  addu       $a0, $s1, $zero
    /* B94 800FA394 7C1822AE */  sw         $v0, 0x187C($s1)
    /* B98 800FA398 E30623A2 */  sb         $v1, 0x6E3($s1)
    /* B9C 800FA39C 1000A28F */  lw         $v0, 0x10($sp)
    /* BA0 800FA3A0 540C3026 */  addiu      $s0, $s1, 0xC54
    /* BA4 800FA3A4 00004294 */  lhu        $v0, 0x0($v0)
    /* BA8 800FA3A8 21280002 */  addu       $a1, $s0, $zero
    /* BAC 800FA3AC 02B4020C */  jal        func_800AD008
    /* BB0 800FA3B0 BC0522A6 */   sh        $v0, 0x5BC($s1)
    /* BB4 800FA3B4 21202002 */  addu       $a0, $s1, $zero
    /* BB8 800FA3B8 21280002 */  addu       $a1, $s0, $zero
    /* BBC 800FA3BC 8ABE020C */  jal        func_800AFA28
    /* BC0 800FA3C0 01000624 */   addiu     $a2, $zero, 0x1
    /* BC4 800FA3C4 04072426 */  addiu      $a0, $s1, 0x704
    /* BC8 800FA3C8 21280002 */  addu       $a1, $s0, $zero
    /* BCC 800FA3CC 2C24010C */  jal        vs_main_memcpy
    /* BD0 800FA3D0 50050624 */   addiu     $a2, $zero, 0x550
    /* BD4 800FA3D4 941120A6 */  sh         $zero, 0x1194($s1)
    /* BD8 800FA3D8 E00620A2 */  sb         $zero, 0x6E0($s1)
    /* BDC 800FA3DC CD0520A2 */  sb         $zero, 0x5CD($s1)
    /* BE0 800FA3E0 CC0520A2 */  sb         $zero, 0x5CC($s1)
    /* BE4 800FA3E4 2000BF8F */  lw         $ra, 0x20($sp)
    /* BE8 800FA3E8 1C00B18F */  lw         $s1, 0x1C($sp)
    /* BEC 800FA3EC 1800B08F */  lw         $s0, 0x18($sp)
    /* BF0 800FA3F0 2800BD27 */  addiu      $sp, $sp, 0x28
    /* BF4 800FA3F4 0800E003 */  jr         $ra
    /* BF8 800FA3F8 00000000 */   nop
endlabel func_800FA2CC
