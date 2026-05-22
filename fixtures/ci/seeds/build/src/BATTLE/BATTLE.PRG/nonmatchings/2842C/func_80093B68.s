nonmatching func_80093B68, 0x2FC

glabel func_80093B68
    /* 2B368 80093B68 C0FFBD27 */  addiu      $sp, $sp, -0x40
    /* 2B36C 80093B6C 2000B2AF */  sw         $s2, 0x20($sp)
    /* 2B370 80093B70 21908000 */  addu       $s2, $a0, $zero
    /* 2B374 80093B74 3400B7AF */  sw         $s7, 0x34($sp)
    /* 2B378 80093B78 21B8C000 */  addu       $s7, $a2, $zero
    /* 2B37C 80093B7C 3000B6AF */  sw         $s6, 0x30($sp)
    /* 2B380 80093B80 21B0E000 */  addu       $s6, $a3, $zero
    /* 2B384 80093B84 FFFF0224 */  addiu      $v0, $zero, -0x1
    /* 2B388 80093B88 3800BFAF */  sw         $ra, 0x38($sp)
    /* 2B38C 80093B8C 2C00B5AF */  sw         $s5, 0x2C($sp)
    /* 2B390 80093B90 2800B4AF */  sw         $s4, 0x28($sp)
    /* 2B394 80093B94 2400B3AF */  sw         $s3, 0x24($sp)
    /* 2B398 80093B98 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 2B39C 80093B9C 0A00A210 */  beq        $a1, $v0, .L80093BC8
    /* 2B3A0 80093BA0 1800B0AF */   sw        $s0, 0x18($sp)
    /* 2B3A4 80093BA4 4B85020C */  jal        func_800A152C
    /* 2B3A8 80093BA8 02000624 */   addiu     $a2, $zero, 0x2
    /* 2B3AC 80093BAC 21804000 */  addu       $s0, $v0, $zero
    /* 2B3B0 80093BB0 07000106 */  bgez       $s0, .L80093BD0
    /* 2B3B4 80093BB4 21200000 */   addu      $a0, $zero, $zero
    /* 2B3B8 80093BB8 8E4F0208 */  j          .L80093E38
    /* 2B3BC 80093BBC FEFF0224 */   addiu     $v0, $zero, -0x2
  .L80093BC0:
    /* 2B3C0 80093BC0 2F4F0208 */  j          .L80093CBC
    /* 2B3C4 80093BC4 80001524 */   addiu     $s5, $zero, 0x80
  .L80093BC8:
    /* 2B3C8 80093BC8 FF001024 */  addiu      $s0, $zero, 0xFF
    /* 2B3CC 80093BCC 21200000 */  addu       $a0, $zero, $zero
  .L80093BD0:
    /* 2B3D0 80093BD0 21988000 */  addu       $s3, $a0, $zero
    /* 2B3D4 80093BD4 0F80033C */  lui        $v1, %hi(D_800F1BAC)
    /* 2B3D8 80093BD8 0F80023C */  lui        $v0, %hi(D_800F227E)
    /* 2B3DC 80093BDC 7E224284 */  lh         $v0, %lo(D_800F227E)($v0)
    /* 2B3E0 80093BE0 AC1B718C */  lw         $s1, %lo(D_800F1BAC)($v1)
    /* 2B3E4 80093BE4 16004018 */  blez       $v0, .L80093C40
    /* 2B3E8 80093BE8 21A08000 */   addu      $s4, $a0, $zero
    /* 2B3EC 80093BEC 01000524 */  addiu      $a1, $zero, 0x1
    /* 2B3F0 80093BF0 21184000 */  addu       $v1, $v0, $zero
    /* 2B3F4 80093BF4 0B002626 */  addiu      $a2, $s1, 0xB
  .L80093BF8:
    /* 2B3F8 80093BF8 FDFFC290 */  lbu        $v0, -0x3($a2)
    /* 2B3FC 80093BFC 00000000 */  nop
    /* 2B400 80093C00 0B004514 */  bne        $v0, $a1, .L80093C30
    /* 2B404 80093C04 00000000 */   nop
    /* 2B408 80093C08 FEFFC290 */  lbu        $v0, -0x2($a2)
    /* 2B40C 80093C0C 00000000 */  nop
    /* 2B410 80093C10 07005214 */  bne        $v0, $s2, .L80093C30
    /* 2B414 80093C14 00000000 */   nop
    /* 2B418 80093C18 FBFFC284 */  lh         $v0, -0x5($a2)
    /* 2B41C 80093C1C 00000000 */  nop
    /* 2B420 80093C20 03004004 */  bltz       $v0, .L80093C30
    /* 2B424 80093C24 00000000 */   nop
    /* 2B428 80093C28 0000D490 */  lbu        $s4, 0x0($a2)
    /* 2B42C 80093C2C 01007326 */  addiu      $s3, $s3, 0x1
  .L80093C30:
    /* 2B430 80093C30 01008424 */  addiu      $a0, $a0, 0x1
    /* 2B434 80093C34 2A108300 */  slt        $v0, $a0, $v1
    /* 2B438 80093C38 EFFF4014 */  bnez       $v0, .L80093BF8
    /* 2B43C 80093C3C 1800C624 */   addiu     $a2, $a2, 0x18
  .L80093C40:
    /* 2B440 80093C40 21200000 */  addu       $a0, $zero, $zero
    /* 2B444 80093C44 0F80033C */  lui        $v1, %hi(D_800F1BAC)
    /* 2B448 80093C48 0F80023C */  lui        $v0, %hi(D_800F227E)
    /* 2B44C 80093C4C 7E224284 */  lh         $v0, %lo(D_800F227E)($v0)
    /* 2B450 80093C50 AC1B718C */  lw         $s1, %lo(D_800F1BAC)($v1)
    /* 2B454 80093C54 19004018 */  blez       $v0, .L80093CBC
    /* 2B458 80093C58 21A88000 */   addu      $s5, $a0, $zero
    /* 2B45C 80093C5C 01000724 */  addiu      $a3, $zero, 0x1
    /* 2B460 80093C60 FFFF6526 */  addiu      $a1, $s3, -0x1
    /* 2B464 80093C64 21184000 */  addu       $v1, $v0, $zero
    /* 2B468 80093C68 06002626 */  addiu      $a2, $s1, 0x6
  .L80093C6C:
    /* 2B46C 80093C6C 0200C290 */  lbu        $v0, 0x2($a2)
    /* 2B470 80093C70 00000000 */  nop
    /* 2B474 80093C74 0D004714 */  bne        $v0, $a3, .L80093CAC
    /* 2B478 80093C78 00000000 */   nop
    /* 2B47C 80093C7C 0300C290 */  lbu        $v0, 0x3($a2)
    /* 2B480 80093C80 00000000 */  nop
    /* 2B484 80093C84 09005214 */  bne        $v0, $s2, .L80093CAC
    /* 2B488 80093C88 00000000 */   nop
    /* 2B48C 80093C8C 0400C290 */  lbu        $v0, 0x4($a2)
    /* 2B490 80093C90 00000000 */  nop
    /* 2B494 80093C94 05005014 */  bne        $v0, $s0, .L80093CAC
    /* 2B498 80093C98 00000000 */   nop
    /* 2B49C 80093C9C 0000C284 */  lh         $v0, 0x0($a2)
    /* 2B4A0 80093CA0 00000000 */  nop
    /* 2B4A4 80093CA4 C6FF4510 */  beq        $v0, $a1, .L80093BC0
    /* 2B4A8 80093CA8 00000000 */   nop
  .L80093CAC:
    /* 2B4AC 80093CAC 01008424 */  addiu      $a0, $a0, 0x1
    /* 2B4B0 80093CB0 2A108300 */  slt        $v0, $a0, $v1
    /* 2B4B4 80093CB4 EDFF4014 */  bnez       $v0, .L80093C6C
    /* 2B4B8 80093CB8 1800C624 */   addiu     $a2, $a2, 0x18
  .L80093CBC:
    /* 2B4BC 80093CBC B958020C */  jal        func_800962E4
    /* 2B4C0 80093CC0 00000000 */   nop
    /* 2B4C4 80093CC4 21884000 */  addu       $s1, $v0, $zero
    /* 2B4C8 80093CC8 FF000224 */  addiu      $v0, $zero, 0xFF
    /* 2B4CC 80093CCC 07000212 */  beq        $s0, $v0, .L80093CEC
    /* 2B4D0 80093CD0 21204002 */   addu      $a0, $s2, $zero
    /* 2B4D4 80093CD4 21280002 */  addu       $a1, $s0, $zero
    /* 2B4D8 80093CD8 21302002 */  addu       $a2, $s1, $zero
    /* 2B4DC 80093CDC BE86020C */  jal        func_800A1AF8
    /* 2B4E0 80093CE0 02000724 */   addiu     $a3, $zero, 0x2
    /* 2B4E4 80093CE4 3F4F0208 */  j          .L80093CFC
    /* 2B4E8 80093CE8 00000000 */   nop
  .L80093CEC:
    /* 2B4EC 80093CEC FF000524 */  addiu      $a1, $zero, 0xFF
    /* 2B4F0 80093CF0 21302002 */  addu       $a2, $s1, $zero
    /* 2B4F4 80093CF4 4386020C */  jal        func_800A190C
    /* 2B4F8 80093CF8 02000724 */   addiu     $a3, $zero, 0x2
  .L80093CFC:
    /* 2B4FC 80093CFC 4E004014 */  bnez       $v0, .L80093E38
    /* 2B500 80093D00 FEFF0224 */   addiu     $v0, $zero, -0x2
    /* 2B504 80093D04 8000C232 */  andi       $v0, $s6, 0x80
    /* 2B508 80093D08 11004010 */  beqz       $v0, .L80093D50
    /* 2B50C 80093D0C 21204002 */   addu      $a0, $s2, $zero
    /* 2B510 80093D10 FB000524 */  addiu      $a1, $zero, 0xFB
    /* 2B514 80093D14 1000A627 */  addiu      $a2, $sp, 0x10
    /* 2B518 80093D18 A084020C */  jal        func_800A1280
    /* 2B51C 80093D1C 21380000 */   addu      $a3, $zero, $zero
    /* 2B520 80093D20 45004014 */  bnez       $v0, .L80093E38
    /* 2B524 80093D24 21100000 */   addu      $v0, $zero, $zero
    /* 2B528 80093D28 1000A297 */  lhu        $v0, 0x10($sp)
    /* 2B52C 80093D2C 00000000 */  nop
    /* 2B530 80093D30 4101422C */  sltiu      $v0, $v0, 0x141
    /* 2B534 80093D34 40004010 */  beqz       $v0, .L80093E38
    /* 2B538 80093D38 21100000 */   addu      $v0, $zero, $zero
    /* 2B53C 80093D3C 1200A297 */  lhu        $v0, 0x12($sp)
    /* 2B540 80093D40 00000000 */  nop
    /* 2B544 80093D44 F100422C */  sltiu      $v0, $v0, 0xF1
    /* 2B548 80093D48 3B004010 */  beqz       $v0, .L80093E38
    /* 2B54C 80093D4C 21100000 */   addu      $v0, $zero, $zero
  .L80093D50:
    /* 2B550 80093D50 7F00D632 */  andi       $s6, $s6, 0x7F
    /* 2B554 80093D54 21204002 */  addu       $a0, $s2, $zero
    /* 2B558 80093D58 FB000524 */  addiu      $a1, $zero, 0xFB
    /* 2B55C 80093D5C 1000A627 */  addiu      $a2, $sp, 0x10
    /* 2B560 80093D60 4386020C */  jal        func_800A190C
    /* 2B564 80093D64 21380000 */   addu      $a3, $zero, $zero
    /* 2B568 80093D68 33004014 */  bnez       $v0, .L80093E38
    /* 2B56C 80093D6C FEFF0224 */   addiu     $v0, $zero, -0x2
    /* 2B570 80093D70 00100224 */  addiu      $v0, $zero, 0x1000
    /* 2B574 80093D74 100022A6 */  sh         $v0, 0x10($s1)
    /* 2B578 80093D78 120022A6 */  sh         $v0, 0x12($s1)
    /* 2B57C 80093D7C 00002296 */  lhu        $v0, 0x0($s1)
    /* 2B580 80093D80 1000A397 */  lhu        $v1, 0x10($sp)
    /* 2B584 80093D84 00000000 */  nop
    /* 2B588 80093D88 23104300 */  subu       $v0, $v0, $v1
    /* 2B58C 80093D8C 000022A6 */  sh         $v0, 0x0($s1)
    /* 2B590 80093D90 02002296 */  lhu        $v0, 0x2($s1)
    /* 2B594 80093D94 1200A397 */  lhu        $v1, 0x12($sp)
    /* 2B598 80093D98 00000000 */  nop
    /* 2B59C 80093D9C 23104300 */  subu       $v0, $v0, $v1
    /* 2B5A0 80093DA0 020022A6 */  sh         $v0, 0x2($s1)
    /* 2B5A4 80093DA4 1400A497 */  lhu        $a0, 0x14($sp)
    /* 2B5A8 80093DA8 01000224 */  addiu      $v0, $zero, 0x1
    /* 2B5AC 80093DAC 080022A2 */  sb         $v0, 0x8($s1)
    /* 2B5B0 80093DB0 04002296 */  lhu        $v0, 0x4($s1)
    /* 2B5B4 80093DB4 2518D502 */  or         $v1, $s6, $s5
    /* 2B5B8 80093DB8 0E0023A2 */  sb         $v1, 0xE($s1)
    /* 2B5BC 80093DBC FF7FE332 */  andi       $v1, $s7, 0x7FFF
    /* 2B5C0 80093DC0 060033A6 */  sh         $s3, 0x6($s1)
    /* 2B5C4 80093DC4 0B0034A2 */  sb         $s4, 0xB($s1)
    /* 2B5C8 80093DC8 090032A2 */  sb         $s2, 0x9($s1)
    /* 2B5CC 80093DCC 0A0030A2 */  sb         $s0, 0xA($s1)
    /* 2B5D0 80093DD0 23104400 */  subu       $v0, $v0, $a0
    /* 2B5D4 80093DD4 040022A6 */  sh         $v0, 0x4($s1)
    /* 2B5D8 80093DD8 E8036228 */  slti       $v0, $v1, 0x3E8
    /* 2B5DC 80093DDC 04004014 */  bnez       $v0, .L80093DF0
    /* 2B5E0 80093DE0 02141700 */   srl       $v0, $s7, 16
    /* 2B5E4 80093DE4 00804230 */  andi       $v0, $v0, 0x8000
    /* 2B5E8 80093DE8 7E4F0208 */  j          .L80093DF8
    /* 2B5EC 80093DEC E7034234 */   ori       $v0, $v0, 0x3E7
  .L80093DF0:
    /* 2B5F0 80093DF0 00804230 */  andi       $v0, $v0, 0x8000
    /* 2B5F4 80093DF4 25106200 */  or         $v0, $v1, $v0
  .L80093DF8:
    /* 2B5F8 80093DF8 0C0022A6 */  sh         $v0, 0xC($s1)
    /* 2B5FC 80093DFC 14003026 */  addiu      $s0, $s1, 0x14
    /* 2B600 80093E00 21200002 */  addu       $a0, $s0, $zero
    /* 2B604 80093E04 0780053C */  lui        $a1, %hi(D_800691E4)
    /* 2B608 80093E08 0C002696 */  lhu        $a2, 0xC($s1)
    /* 2B60C 80093E0C E491A524 */  addiu      $a1, $a1, %lo(D_800691E4)
    /* 2B610 80093E10 BD9B000C */  jal        sprintf
    /* 2B614 80093E14 FF7FC630 */   andi      $a2, $a2, 0x7FFF
    /* 2B618 80093E18 A59B000C */  jal        strlen
    /* 2B61C 80093E1C 21200002 */   addu      $a0, $s0, $zero
    /* 2B620 80093E20 0F80043C */  lui        $a0, %hi(D_800F227E)
    /* 2B624 80093E24 0F0022A2 */  sb         $v0, 0xF($s1)
    /* 2B628 80093E28 7E228394 */  lhu        $v1, %lo(D_800F227E)($a0)
    /* 2B62C 80093E2C 21100000 */  addu       $v0, $zero, $zero
    /* 2B630 80093E30 01006324 */  addiu      $v1, $v1, 0x1
    /* 2B634 80093E34 7E2283A4 */  sh         $v1, %lo(D_800F227E)($a0)
  .L80093E38:
    /* 2B638 80093E38 3800BF8F */  lw         $ra, 0x38($sp)
    /* 2B63C 80093E3C 3400B78F */  lw         $s7, 0x34($sp)
    /* 2B640 80093E40 3000B68F */  lw         $s6, 0x30($sp)
    /* 2B644 80093E44 2C00B58F */  lw         $s5, 0x2C($sp)
    /* 2B648 80093E48 2800B48F */  lw         $s4, 0x28($sp)
    /* 2B64C 80093E4C 2400B38F */  lw         $s3, 0x24($sp)
    /* 2B650 80093E50 2000B28F */  lw         $s2, 0x20($sp)
    /* 2B654 80093E54 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 2B658 80093E58 1800B08F */  lw         $s0, 0x18($sp)
    /* 2B65C 80093E5C 0800E003 */  jr         $ra
    /* 2B660 80093E60 4000BD27 */   addiu     $sp, $sp, 0x40
endlabel func_80093B68
