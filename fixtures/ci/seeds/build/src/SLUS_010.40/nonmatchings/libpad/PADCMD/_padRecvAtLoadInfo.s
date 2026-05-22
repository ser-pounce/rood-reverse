nonmatching _padRecvAtLoadInfo, 0x270

glabel _padRecvAtLoadInfo
    /* 1D334 8002CB34 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1D338 8002CB38 1000B0AF */  sw         $s0, 0x10($sp)
    /* 1D33C 8002CB3C 21808000 */  addu       $s0, $a0, $zero
    /* 1D340 8002CB40 1400BFAF */  sw         $ra, 0x14($sp)
    /* 1D344 8002CB44 46000392 */  lbu        $v1, 0x46($s0)
    /* 1D348 8002CB48 03000224 */  addiu      $v0, $zero, 0x3
    /* 1D34C 8002CB4C 3C006210 */  beq        $v1, $v0, .L8002CC40
    /* 1D350 8002CB50 04006228 */   slti      $v0, $v1, 0x4
    /* 1D354 8002CB54 05004010 */  beqz       $v0, .L8002CB6C
    /* 1D358 8002CB58 02000224 */   addiu     $v0, $zero, 0x2
    /* 1D35C 8002CB5C 08006210 */  beq        $v1, $v0, .L8002CB80
    /* 1D360 8002CB60 01000224 */   addiu     $v0, $zero, 0x1
    /* 1D364 8002CB64 65B30008 */  j          .L8002CD94
    /* 1D368 8002CB68 00000000 */   nop
  .L8002CB6C:
    /* 1D36C 8002CB6C 04000224 */  addiu      $v0, $zero, 0x4
    /* 1D370 8002CB70 4D006210 */  beq        $v1, $v0, .L8002CCA8
    /* 1D374 8002CB74 01000224 */   addiu     $v0, $zero, 0x1
    /* 1D378 8002CB78 65B30008 */  j          .L8002CD94
    /* 1D37C 8002CB7C 00000000 */   nop
  .L8002CB80:
    /* 1D380 8002CB80 3C00048E */  lw         $a0, 0x3C($s0)
    /* 1D384 8002CB84 00000000 */  nop
    /* 1D388 8002CB88 07008290 */  lbu        $v0, 0x7($a0)
    /* 1D38C 8002CB8C 00000000 */  nop
    /* 1D390 8002CB90 80004014 */  bnez       $v0, .L8002CD94
    /* 1D394 8002CB94 21100000 */   addu      $v0, $zero, $zero
    /* 1D398 8002CB98 E3000392 */  lbu        $v1, 0xE3($s0)
    /* 1D39C 8002CB9C 03008290 */  lbu        $v0, 0x3($a0)
    /* 1D3A0 8002CBA0 00000000 */  nop
    /* 1D3A4 8002CBA4 12006214 */  bne        $v1, $v0, .L8002CBF0
    /* 1D3A8 8002CBA8 FFFF0234 */   ori       $v0, $zero, 0xFFFF
    /* 1D3AC 8002CBAC E4000392 */  lbu        $v1, 0xE4($s0)
    /* 1D3B0 8002CBB0 04008290 */  lbu        $v0, 0x4($a0)
    /* 1D3B4 8002CBB4 00000000 */  nop
    /* 1D3B8 8002CBB8 0D006214 */  bne        $v1, $v0, .L8002CBF0
    /* 1D3BC 8002CBBC FFFF0234 */   ori       $v0, $zero, 0xFFFF
    /* 1D3C0 8002CBC0 E9000392 */  lbu        $v1, 0xE9($s0)
    /* 1D3C4 8002CBC4 05008290 */  lbu        $v0, 0x5($a0)
    /* 1D3C8 8002CBC8 00000000 */  nop
    /* 1D3CC 8002CBCC 08006214 */  bne        $v1, $v0, .L8002CBF0
    /* 1D3D0 8002CBD0 FFFF0234 */   ori       $v0, $zero, 0xFFFF
    /* 1D3D4 8002CBD4 EA000392 */  lbu        $v1, 0xEA($s0)
    /* 1D3D8 8002CBD8 06008290 */  lbu        $v0, 0x6($a0)
    /* 1D3DC 8002CBDC 00000000 */  nop
    /* 1D3E0 8002CBE0 03006214 */  bne        $v1, $v0, .L8002CBF0
    /* 1D3E4 8002CBE4 FFFF0234 */   ori       $v0, $zero, 0xFFFF
    /* 1D3E8 8002CBE8 FDB20008 */  j          .L8002CBF4
    /* 1D3EC 8002CBEC EE0000A6 */   sh        $zero, 0xEE($s0)
  .L8002CBF0:
    /* 1D3F0 8002CBF0 EE0002A6 */  sh         $v0, 0xEE($s0)
  .L8002CBF4:
    /* 1D3F4 8002CBF4 3C00028E */  lw         $v0, 0x3C($s0)
    /* 1D3F8 8002CBF8 3C00038E */  lw         $v1, 0x3C($s0)
    /* 1D3FC 8002CBFC 03004290 */  lbu        $v0, 0x3($v0)
    /* 1D400 8002CC00 00000000 */  nop
    /* 1D404 8002CC04 E30002A2 */  sb         $v0, 0xE3($s0)
    /* 1D408 8002CC08 04006290 */  lbu        $v0, 0x4($v1)
    /* 1D40C 8002CC0C 3C00038E */  lw         $v1, 0x3C($s0)
    /* 1D410 8002CC10 E60000A6 */  sh         $zero, 0xE6($s0)
    /* 1D414 8002CC14 E40002A2 */  sb         $v0, 0xE4($s0)
    /* 1D418 8002CC18 05006290 */  lbu        $v0, 0x5($v1)
    /* 1D41C 8002CC1C 3C00038E */  lw         $v1, 0x3C($s0)
    /* 1D420 8002CC20 E90002A2 */  sb         $v0, 0xE9($s0)
    /* 1D424 8002CC24 06006290 */  lbu        $v0, 0x6($v1)
    /* 1D428 8002CC28 EE000396 */  lhu        $v1, 0xEE($s0)
    /* 1D42C 8002CC2C EC0000A6 */  sh         $zero, 0xEC($s0)
    /* 1D430 8002CC30 16006014 */  bnez       $v1, .L8002CC8C
    /* 1D434 8002CC34 EA0002A2 */   sb        $v0, 0xEA($s0)
    /* 1D438 8002CC38 64B30008 */  j          .L8002CD90
    /* 1D43C 8002CC3C EB0000A2 */   sb        $zero, 0xEB($s0)
  .L8002CC40:
    /* 1D440 8002CC40 3C00038E */  lw         $v1, 0x3C($s0)
    /* 1D444 8002CC44 00000000 */  nop
    /* 1D448 8002CC48 02006290 */  lbu        $v0, 0x2($v1)
    /* 1D44C 8002CC4C 00000000 */  nop
    /* 1D450 8002CC50 50004014 */  bnez       $v0, .L8002CD94
    /* 1D454 8002CC54 21100000 */   addu      $v0, $zero, $zero
    /* 1D458 8002CC58 03006290 */  lbu        $v0, 0x3($v1)
    /* 1D45C 8002CC5C 00000000 */  nop
    /* 1D460 8002CC60 4C004014 */  bnez       $v0, .L8002CD94
    /* 1D464 8002CC64 21100000 */   addu      $v0, $zero, $zero
    /* 1D468 8002CC68 04006290 */  lbu        $v0, 0x4($v1)
    /* 1D46C 8002CC6C 05006390 */  lbu        $v1, 0x5($v1)
    /* 1D470 8002CC70 00120200 */  sll        $v0, $v0, 8
    /* 1D474 8002CC74 21206200 */  addu       $a0, $v1, $v0
    /* 1D478 8002CC78 EE000396 */  lhu        $v1, 0xEE($s0)
    /* 1D47C 8002CC7C FFFF8230 */  andi       $v0, $a0, 0xFFFF
    /* 1D480 8002CC80 04006210 */  beq        $v1, $v0, .L8002CC94
    /* 1D484 8002CC84 E60004A6 */   sh        $a0, 0xE6($s0)
    /* 1D488 8002CC88 EE0004A6 */  sh         $a0, 0xEE($s0)
  .L8002CC8C:
    /* 1D48C 8002CC8C 65B30008 */  j          .L8002CD94
    /* 1D490 8002CC90 21100000 */   addu      $v0, $zero, $zero
  .L8002CC94:
    /* 1D494 8002CC94 FFFF0234 */  ori        $v0, $zero, 0xFFFF
    /* 1D498 8002CC98 EE0002A6 */  sh         $v0, 0xEE($s0)
    /* 1D49C 8002CC9C EB0000A2 */  sb         $zero, 0xEB($s0)
    /* 1D4A0 8002CCA0 64B30008 */  j          .L8002CD90
    /* 1D4A4 8002CCA4 470000A2 */   sb        $zero, 0x47($s0)
  .L8002CCA8:
    /* 1D4A8 8002CCA8 3C00038E */  lw         $v1, 0x3C($s0)
    /* 1D4AC 8002CCAC 00000000 */  nop
    /* 1D4B0 8002CCB0 02006290 */  lbu        $v0, 0x2($v1)
    /* 1D4B4 8002CCB4 00000000 */  nop
    /* 1D4B8 8002CCB8 36004014 */  bnez       $v0, .L8002CD94
    /* 1D4BC 8002CCBC 21100000 */   addu      $v0, $zero, $zero
    /* 1D4C0 8002CCC0 03006290 */  lbu        $v0, 0x3($v1)
    /* 1D4C4 8002CCC4 00000000 */  nop
    /* 1D4C8 8002CCC8 32004014 */  bnez       $v0, .L8002CD94
    /* 1D4CC 8002CCCC 21100000 */   addu      $v0, $zero, $zero
    /* 1D4D0 8002CCD0 EC000496 */  lhu        $a0, 0xEC($s0)
    /* 1D4D4 8002CCD4 04006390 */  lbu        $v1, 0x4($v1)
    /* 1D4D8 8002CCD8 47000292 */  lbu        $v0, 0x47($s0)
    /* 1D4DC 8002CCDC 08008424 */  addiu      $a0, $a0, 0x8
    /* 1D4E0 8002CCE0 03006324 */  addiu      $v1, $v1, 0x3
    /* 1D4E4 8002CCE4 FC016330 */  andi       $v1, $v1, 0x1FC
    /* 1D4E8 8002CCE8 21208300 */  addu       $a0, $a0, $v1
    /* 1D4EC 8002CCEC EA000392 */  lbu        $v1, 0xEA($s0)
    /* 1D4F0 8002CCF0 01004224 */  addiu      $v0, $v0, 0x1
    /* 1D4F4 8002CCF4 470002A2 */  sb         $v0, 0x47($s0)
    /* 1D4F8 8002CCF8 FF004230 */  andi       $v0, $v0, 0xFF
    /* 1D4FC 8002CCFC 2B104300 */  sltu       $v0, $v0, $v1
    /* 1D500 8002CD00 E2FF4014 */  bnez       $v0, .L8002CC8C
    /* 1D504 8002CD04 EC0004A6 */   sh        $a0, 0xEC($s0)
    /* 1D508 8002CD08 69B3000C */  jal        _padGetActSize
    /* 1D50C 8002CD0C 21200002 */   addu      $a0, $s0, $zero
    /* 1D510 8002CD10 81004228 */  slti       $v0, $v0, 0x81
    /* 1D514 8002CD14 0B004014 */  bnez       $v0, .L8002CD44
    /* 1D518 8002CD18 00000000 */   nop
    /* 1D51C 8002CD1C 0380023C */  lui        $v0, %hi(D_800335A0)
    /* 1D520 8002CD20 A035428C */  lw         $v0, %lo(D_800335A0)($v0)
    /* 1D524 8002CD24 00000000 */  nop
    /* 1D528 8002CD28 09F84000 */  jalr       $v0
    /* 1D52C 8002CD2C 21200002 */   addu      $a0, $s0, $zero
    /* 1D530 8002CD30 FE000224 */  addiu      $v0, $zero, 0xFE
    /* 1D534 8002CD34 460002A2 */  sb         $v0, 0x46($s0)
    /* 1D538 8002CD38 02000224 */  addiu      $v0, $zero, 0x2
    /* 1D53C 8002CD3C 23B30008 */  j          .L8002CC8C
    /* 1D540 8002CD40 490002A2 */   sb        $v0, 0x49($s0)
  .L8002CD44:
    /* 1D544 8002CD44 EC000396 */  lhu        $v1, 0xEC($s0)
    /* 1D548 8002CD48 EE000296 */  lhu        $v0, 0xEE($s0)
    /* 1D54C 8002CD4C 00000000 */  nop
    /* 1D550 8002CD50 05004310 */  beq        $v0, $v1, .L8002CD68
    /* 1D554 8002CD54 21100000 */   addu      $v0, $zero, $zero
    /* 1D558 8002CD58 EE0003A6 */  sh         $v1, 0xEE($s0)
    /* 1D55C 8002CD5C 470000A2 */  sb         $zero, 0x47($s0)
    /* 1D560 8002CD60 65B30008 */  j          .L8002CD94
    /* 1D564 8002CD64 EC0000A6 */   sh        $zero, 0xEC($s0)
  .L8002CD68:
    /* 1D568 8002CD68 21200002 */  addu       $a0, $s0, $zero
    /* 1D56C 8002CD6C FF000224 */  addiu      $v0, $zero, 0xFF
    /* 1D570 8002CD70 63000526 */  addiu      $a1, $s0, 0x63
    /* 1D574 8002CD74 EE0000A6 */  sh         $zero, 0xEE($s0)
    /* 1D578 8002CD78 EB0000A2 */  sb         $zero, 0xEB($s0)
    /* 1D57C 8002CD7C 77B3000C */  jal        _padLoadActInfo
    /* 1D580 8002CD80 460002A2 */   sb        $v0, 0x46($s0)
    /* 1D584 8002CD84 02000224 */  addiu      $v0, $zero, 0x2
    /* 1D588 8002CD88 23B30008 */  j          .L8002CC8C
    /* 1D58C 8002CD8C 460002A2 */   sb        $v0, 0x46($s0)
  .L8002CD90:
    /* 1D590 8002CD90 01000224 */  addiu      $v0, $zero, 0x1
  .L8002CD94:
    /* 1D594 8002CD94 1400BF8F */  lw         $ra, 0x14($sp)
    /* 1D598 8002CD98 1000B08F */  lw         $s0, 0x10($sp)
    /* 1D59C 8002CD9C 0800E003 */  jr         $ra
    /* 1D5A0 8002CDA0 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel _padRecvAtLoadInfo
