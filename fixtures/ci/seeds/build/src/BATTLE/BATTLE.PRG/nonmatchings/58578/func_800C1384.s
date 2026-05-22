/* Handwritten function */
nonmatching func_800C1384, 0x1E0

glabel func_800C1384
    /* 58B84 800C1384 88FFBD27 */  addiu      $sp, $sp, -0x78
    /* 58B88 800C1388 6800B2AF */  sw         $s2, 0x68($sp)
    /* 58B8C 800C138C 21908000 */  addu       $s2, $a0, $zero
    /* 58B90 800C1390 7000BFAF */  sw         $ra, 0x70($sp)
    /* 58B94 800C1394 6C00B3AF */  sw         $s3, 0x6C($sp)
    /* 58B98 800C1398 6400B1AF */  sw         $s1, 0x64($sp)
    /* 58B9C 800C139C 6000B0AF */  sw         $s0, 0x60($sp)
    /* 58BA0 800C13A0 08004296 */  lhu        $v0, 0x8($s2)
    /* 58BA4 800C13A4 2188A000 */  addu       $s1, $a1, $zero
    /* 58BA8 800C13A8 3800A2A7 */  sh         $v0, 0x38($sp)
    /* 58BAC 800C13AC 0A004296 */  lhu        $v0, 0xA($s2)
    /* 58BB0 800C13B0 2198C000 */  addu       $s3, $a2, $zero
    /* 58BB4 800C13B4 3A00A2A7 */  sh         $v0, 0x3A($sp)
    /* 58BB8 800C13B8 0C004296 */  lhu        $v0, 0xC($s2)
    /* 58BBC 800C13BC 2800B027 */  addiu      $s0, $sp, 0x28
    /* 58BC0 800C13C0 3C00A2A7 */  sh         $v0, 0x3C($sp)
    /* 58BC4 800C13C4 07004292 */  lbu        $v0, 0x7($s2)
    /* 58BC8 800C13C8 21200002 */  addu       $a0, $s0, $zero
    /* 58BCC 800C13CC 00110200 */  sll        $v0, $v0, 4
    /* 58BD0 800C13D0 2800A2A7 */  sh         $v0, 0x28($sp)
    /* 58BD4 800C13D4 02004296 */  lhu        $v0, 0x2($s2)
    /* 58BD8 800C13D8 4000A527 */  addiu      $a1, $sp, 0x40
    /* 58BDC 800C13DC 2C00A0A7 */  sh         $zero, 0x2C($sp)
    /* 58BE0 800C13E0 23100200 */  negu       $v0, $v0
    /* 58BE4 800C13E4 8004010C */  jal        RotMatrix_gte
    /* 58BE8 800C13E8 2A00A2A7 */   sh        $v0, 0x2A($sp)
    /* 58BEC 800C13EC 21200000 */  addu       $a0, $zero, $zero
    /* 58BF0 800C13F0 21300002 */  addu       $a2, $s0, $zero
    /* 58BF4 800C13F4 10000524 */  addiu      $a1, $zero, 0x10
  .L800C13F8:
    /* 58BF8 800C13F8 00002396 */  lhu        $v1, 0x0($s1)
    /* 58BFC 800C13FC 02003126 */  addiu      $s1, $s1, 0x2
    /* 58C00 800C1400 2110C500 */  addu       $v0, $a2, $a1
    /* 58C04 800C1404 0200A524 */  addiu      $a1, $a1, 0x2
    /* 58C08 800C1408 00004294 */  lhu        $v0, 0x0($v0)
    /* 58C0C 800C140C 01008424 */  addiu      $a0, $a0, 0x1
    /* 58C10 800C1410 23186200 */  subu       $v1, $v1, $v0
    /* 58C14 800C1414 000003A6 */  sh         $v1, 0x0($s0)
    /* 58C18 800C1418 03008228 */  slti       $v0, $a0, 0x3
    /* 58C1C 800C141C F6FF4014 */  bnez       $v0, .L800C13F8
    /* 58C20 800C1420 02001026 */   addiu     $s0, $s0, 0x2
    /* 58C24 800C1424 4000A427 */  addiu      $a0, $sp, 0x40
    /* 58C28 800C1428 2800A527 */  addiu      $a1, $sp, 0x28
    /* 58C2C 800C142C C905010C */  jal        ApplyMatrixSV
    /* 58C30 800C1430 3000A627 */   addiu     $a2, $sp, 0x30
    /* 58C34 800C1434 3200A397 */  lhu        $v1, 0x32($sp)
    /* 58C38 800C1438 05004292 */  lbu        $v0, 0x5($s2)
    /* 58C3C 800C143C 23180300 */  negu       $v1, $v1
    /* 58C40 800C1440 FFFF6330 */  andi       $v1, $v1, 0xFFFF
    /* 58C44 800C1444 40110200 */  sll        $v0, $v0, 5
    /* 58C48 800C1448 2A104300 */  slt        $v0, $v0, $v1
    /* 58C4C 800C144C 3E004014 */  bnez       $v0, .L800C1548
    /* 58C50 800C1450 21100000 */   addu      $v0, $zero, $zero
    /* 58C54 800C1454 04004292 */  lbu        $v0, 0x4($s2)
    /* 58C58 800C1458 06004392 */  lbu        $v1, 0x6($s2)
    /* 58C5C 800C145C 40390200 */  sll        $a3, $v0, 5
    /* 58C60 800C1460 04006012 */  beqz       $s3, .L800C1474
    /* 58C64 800C1464 40410300 */   sll       $t0, $v1, 5
    /* 58C68 800C1468 21280001 */  addu       $a1, $t0, $zero
    /* 58C6C 800C146C 1F050308 */  j          .L800C147C
    /* 58C70 800C1470 23300700 */   negu      $a2, $a3
  .L800C1474:
    /* 58C74 800C1474 21280000 */  addu       $a1, $zero, $zero
    /* 58C78 800C1478 2130A000 */  addu       $a2, $a1, $zero
  .L800C147C:
    /* 58C7C 800C147C 21200000 */  addu       $a0, $zero, $zero
    /* 58C80 800C1480 1000A927 */  addiu      $t1, $sp, 0x10
    /* 58C84 800C1484 2400AA27 */  addiu      $t2, $sp, 0x24
    /* 58C88 800C1488 23180700 */  negu       $v1, $a3
    /* 58C8C 800C148C FFFF6330 */  andi       $v1, $v1, 0xFFFF
    /* 58C90 800C1490 23100500 */  negu       $v0, $a1
    /* 58C94 800C1494 00140200 */  sll        $v0, $v0, 16
    /* 58C98 800C1498 25186200 */  or         $v1, $v1, $v0
    /* 58C9C 800C149C 1000A3AF */  sw         $v1, 0x10($sp)
    /* 58CA0 800C14A0 23180600 */  negu       $v1, $a2
    /* 58CA4 800C14A4 23100800 */  negu       $v0, $t0
    /* 58CA8 800C14A8 00140200 */  sll        $v0, $v0, 16
    /* 58CAC 800C14AC 25186200 */  or         $v1, $v1, $v0
    /* 58CB0 800C14B0 00140500 */  sll        $v0, $a1, 16
    /* 58CB4 800C14B4 2510E200 */  or         $v0, $a3, $v0
    /* 58CB8 800C14B8 1800A2AF */  sw         $v0, 0x18($sp)
    /* 58CBC 800C14BC FFFFC230 */  andi       $v0, $a2, 0xFFFF
    /* 58CC0 800C14C0 1400A3AF */  sw         $v1, 0x14($sp)
    /* 58CC4 800C14C4 001C0800 */  sll        $v1, $t0, 16
    /* 58CC8 800C14C8 25104300 */  or         $v0, $v0, $v1
    /* 58CCC 800C14CC 1C00A2AF */  sw         $v0, 0x1C($sp)
    /* 58CD0 800C14D0 3400A287 */  lh         $v0, 0x34($sp)
    /* 58CD4 800C14D4 3000A397 */  lhu        $v1, 0x30($sp)
    /* 58CD8 800C14D8 00140200 */  sll        $v0, $v0, 16
    /* 58CDC 800C14DC 25186200 */  or         $v1, $v1, $v0
    /* 58CE0 800C14E0 2000A3AF */  sw         $v1, 0x20($sp)
    /* 58CE4 800C14E4 80100400 */  sll        $v0, $a0, 2
  .L800C14E8:
    /* 58CE8 800C14E8 21102201 */  addu       $v0, $t1, $v0
    /* 58CEC 800C14EC 01008424 */  addiu      $a0, $a0, 0x1
    /* 58CF0 800C14F0 03008330 */  andi       $v1, $a0, 0x3
    /* 58CF4 800C14F4 80180300 */  sll        $v1, $v1, 2
    /* 58CF8 800C14F8 21182301 */  addu       $v1, $t1, $v1
    /* 58CFC 800C14FC 2000AB8F */  lw         $t3, 0x20($sp)
    /* 58D00 800C1500 0000428C */  lw         $v0, 0x0($v0)
    /* 58D04 800C1504 0000638C */  lw         $v1, 0x0($v1)
    /* 58D08 800C1508 00608B48 */  mtc2       $t3, $12 /* handwritten instruction */
    /* 58D0C 800C150C 00708348 */  mtc2       $v1, $14 /* handwritten instruction */
    /* 58D10 800C1510 00688248 */  mtc2       $v0, $13 /* handwritten instruction */
    /* 58D14 800C1514 00000000 */  nop
    /* 58D18 800C1518 00000000 */  nop
    /* 58D1C 800C151C 0600404B */  nclip
    /* 58D20 800C1520 000058E9 */  swc2       $24, 0x0($t2)
    /* 58D24 800C1524 2400A28F */  lw         $v0, 0x24($sp)
    /* 58D28 800C1528 00000000 */  nop
    /* 58D2C 800C152C 05004004 */  bltz       $v0, .L800C1544
    /* 58D30 800C1530 04008228 */   slti      $v0, $a0, 0x4
    /* 58D34 800C1534 ECFF4014 */  bnez       $v0, .L800C14E8
    /* 58D38 800C1538 80100400 */   sll       $v0, $a0, 2
    /* 58D3C 800C153C 52050308 */  j          .L800C1548
    /* 58D40 800C1540 01000224 */   addiu     $v0, $zero, 0x1
  .L800C1544:
    /* 58D44 800C1544 21100000 */  addu       $v0, $zero, $zero
  .L800C1548:
    /* 58D48 800C1548 7000BF8F */  lw         $ra, 0x70($sp)
    /* 58D4C 800C154C 6C00B38F */  lw         $s3, 0x6C($sp)
    /* 58D50 800C1550 6800B28F */  lw         $s2, 0x68($sp)
    /* 58D54 800C1554 6400B18F */  lw         $s1, 0x64($sp)
    /* 58D58 800C1558 6000B08F */  lw         $s0, 0x60($sp)
    /* 58D5C 800C155C 0800E003 */  jr         $ra
    /* 58D60 800C1560 7800BD27 */   addiu     $sp, $sp, 0x78
endlabel func_800C1384
