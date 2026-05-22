nonmatching func_800A4A88, 0x304

glabel func_800A4A88
    /* 3C288 800A4A88 C0FFBD27 */  addiu      $sp, $sp, -0x40
    /* 3C28C 800A4A8C 3400B1AF */  sw         $s1, 0x34($sp)
    /* 3C290 800A4A90 21888000 */  addu       $s1, $a0, $zero
    /* 3C294 800A4A94 01000224 */  addiu      $v0, $zero, 0x1
    /* 3C298 800A4A98 3800BFAF */  sw         $ra, 0x38($sp)
    /* 3C29C 800A4A9C 4000A210 */  beq        $a1, $v0, .L800A4BA0
    /* 3C2A0 800A4AA0 3000B0AF */   sw        $s0, 0x30($sp)
    /* 3C2A4 800A4AA4 0200A228 */  slti       $v0, $a1, 0x2
    /* 3C2A8 800A4AA8 05004010 */  beqz       $v0, .L800A4AC0
    /* 3C2AC 800A4AAC 02000224 */   addiu     $v0, $zero, 0x2
    /* 3C2B0 800A4AB0 0900A010 */  beqz       $a1, .L800A4AD8
    /* 3C2B4 800A4AB4 00000000 */   nop
    /* 3C2B8 800A4AB8 54930208 */  j          .L800A4D50
    /* 3C2BC 800A4ABC 00000000 */   nop
  .L800A4AC0:
    /* 3C2C0 800A4AC0 6B00A210 */  beq        $a1, $v0, .L800A4C70
    /* 3C2C4 800A4AC4 00000000 */   nop
    /* 3C2C8 800A4AC8 54930208 */  j          .L800A4D50
    /* 3C2CC 800A4ACC 00000000 */   nop
  .L800A4AD0:
    /* 3C2D0 800A4AD0 CC920208 */  j          .L800A4B30
    /* 3C2D4 800A4AD4 21306000 */   addu      $a2, $v1, $zero
  .L800A4AD8:
    /* 3C2D8 800A4AD8 0C00228E */  lw         $v0, 0xC($s1)
    /* 3C2DC 800A4ADC 00000000 */  nop
    /* 3C2E0 800A4AE0 0F004230 */  andi       $v0, $v0, 0xF
    /* 3C2E4 800A4AE4 A3004010 */  beqz       $v0, .L800A4D74
    /* 3C2E8 800A4AE8 1000A427 */   addiu     $a0, $sp, 0x10
    /* 3C2EC 800A4AEC 0C002292 */  lbu        $v0, 0xC($s1)
    /* 3C2F0 800A4AF0 00000000 */  nop
    /* 3C2F4 800A4AF4 0F005030 */  andi       $s0, $v0, 0xF
    /* 3C2F8 800A4AF8 B034020C */  jal        func_8008D2C0
    /* 3C2FC 800A4AFC FEFF1026 */   addiu     $s0, $s0, -0x2
    /* 3C300 800A4B00 21284000 */  addu       $a1, $v0, $zero
    /* 3C304 800A4B04 0900A018 */  blez       $a1, .L800A4B2C
    /* 3C308 800A4B08 21200000 */   addu      $a0, $zero, $zero
    /* 3C30C 800A4B0C 1000A327 */  addiu      $v1, $sp, 0x10
  .L800A4B10:
    /* 3C310 800A4B10 06006284 */  lh         $v0, 0x6($v1)
    /* 3C314 800A4B14 00000000 */  nop
    /* 3C318 800A4B18 EDFF5010 */  beq        $v0, $s0, .L800A4AD0
    /* 3C31C 800A4B1C 01008424 */   addiu     $a0, $a0, 0x1
    /* 3C320 800A4B20 2A108500 */  slt        $v0, $a0, $a1
    /* 3C324 800A4B24 FAFF4014 */  bnez       $v0, .L800A4B10
    /* 3C328 800A4B28 08006324 */   addiu     $v1, $v1, 0x8
  .L800A4B2C:
    /* 3C32C 800A4B2C 21300000 */  addu       $a2, $zero, $zero
  .L800A4B30:
    /* 3C330 800A4B30 0000C290 */  lbu        $v0, 0x0($a2)
    /* 3C334 800A4B34 EC172392 */  lbu        $v1, 0x17EC($s1)
    /* 3C338 800A4B38 00000000 */  nop
    /* 3C33C 800A4B3C 23104300 */  subu       $v0, $v0, $v1
    /* 3C340 800A4B40 EE0622A2 */  sb         $v0, 0x6EE($s1)
    /* 3C344 800A4B44 21204000 */  addu       $a0, $v0, $zero
    /* 3C348 800A4B48 00260400 */  sll        $a0, $a0, 24
    /* 3C34C 800A4B4C 0400C290 */  lbu        $v0, 0x4($a2)
    /* 3C350 800A4B50 F0172392 */  lbu        $v1, 0x17F0($s1)
    /* 3C354 800A4B54 03260400 */  sra        $a0, $a0, 24
    /* 3C358 800A4B58 23104300 */  subu       $v0, $v0, $v1
    /* 3C35C 800A4B5C EF0622A2 */  sb         $v0, 0x6EF($s1)
    /* 3C360 800A4B60 1C002296 */  lhu        $v0, 0x1C($s1)
    /* 3C364 800A4B64 EF062392 */  lbu        $v1, 0x6EF($s1)
    /* 3C368 800A4B68 21104400 */  addu       $v0, $v0, $a0
    /* 3C36C 800A4B6C 001E0300 */  sll        $v1, $v1, 24
    /* 3C370 800A4B70 031E0300 */  sra        $v1, $v1, 24
    /* 3C374 800A4B74 1C0022A6 */  sh         $v0, 0x1C($s1)
    /* 3C378 800A4B78 20002296 */  lhu        $v0, 0x20($s1)
    /* 3C37C 800A4B7C EE172496 */  lhu        $a0, 0x17EE($s1)
    /* 3C380 800A4B80 21104300 */  addu       $v0, $v0, $v1
    /* 3C384 800A4B84 200022A6 */  sh         $v0, 0x20($s1)
    /* 3C388 800A4B88 0200C394 */  lhu        $v1, 0x2($a2)
    /* 3C38C 800A4B8C 1E002296 */  lhu        $v0, 0x1E($s1)
    /* 3C390 800A4B90 23186400 */  subu       $v1, $v1, $a0
    /* 3C394 800A4B94 21104300 */  addu       $v0, $v0, $v1
    /* 3C398 800A4B98 54930208 */  j          .L800A4D50
    /* 3C39C 800A4B9C 1E0022A6 */   sh        $v0, 0x1E($s1)
  .L800A4BA0:
    /* 3C3A0 800A4BA0 0800228E */  lw         $v0, 0x8($s1)
    /* 3C3A4 800A4BA4 0700033C */  lui        $v1, (0x70000 >> 16)
    /* 3C3A8 800A4BA8 24184300 */  and        $v1, $v0, $v1
    /* 3C3AC 800A4BAC 0200023C */  lui        $v0, (0x20000 >> 16)
    /* 3C3B0 800A4BB0 70006210 */  beq        $v1, $v0, .L800A4D74
    /* 3C3B4 800A4BB4 0300023C */   lui       $v0, (0x30000 >> 16)
    /* 3C3B8 800A4BB8 6E006210 */  beq        $v1, $v0, .L800A4D74
    /* 3C3BC 800A4BBC 00000000 */   nop
    /* 3C3C0 800A4BC0 0C002292 */  lbu        $v0, 0xC($s1)
    /* 3C3C4 800A4BC4 0C002392 */  lbu        $v1, 0xC($s1)
    /* 3C3C8 800A4BC8 02110200 */  srl        $v0, $v0, 4
    /* 3C3CC 800A4BCC 0F006430 */  andi       $a0, $v1, 0xF
    /* 3C3D0 800A4BD0 0F004410 */  beq        $v0, $a0, .L800A4C10
    /* 3C3D4 800A4BD4 00000000 */   nop
    /* 3C3D8 800A4BD8 0F002292 */  lbu        $v0, 0xF($s1)
    /* 3C3DC 800A4BDC 00000000 */  nop
    /* 3C3E0 800A4BE0 09004014 */  bnez       $v0, .L800A4C08
    /* 3C3E4 800A4BE4 00000000 */   nop
    /* 3C3E8 800A4BE8 07008010 */  beqz       $a0, .L800A4C08
    /* 3C3EC 800A4BEC 00000000 */   nop
    /* 3C3F0 800A4BF0 F2172286 */  lh         $v0, 0x17F2($s1)
    /* 3C3F4 800A4BF4 00000000 */  nop
    /* 3C3F8 800A4BF8 03008210 */  beq        $a0, $v0, .L800A4C08
    /* 3C3FC 800A4BFC 00000000 */   nop
    /* 3C400 800A4C00 F892030C */  jal        func_800E4BE0
    /* 3C404 800A4C04 00000000 */   nop
  .L800A4C08:
    /* 3C408 800A4C08 EE0620A2 */  sb         $zero, 0x6EE($s1)
    /* 3C40C 800A4C0C EF0620A2 */  sb         $zero, 0x6EF($s1)
  .L800A4C10:
    /* 3C410 800A4C10 0C00228E */  lw         $v0, 0xC($s1)
    /* 3C414 800A4C14 00000000 */  nop
    /* 3C418 800A4C18 0F004230 */  andi       $v0, $v0, 0xF
    /* 3C41C 800A4C1C 55004010 */  beqz       $v0, .L800A4D74
    /* 3C420 800A4C20 1000A427 */   addiu     $a0, $sp, 0x10
    /* 3C424 800A4C24 0C002292 */  lbu        $v0, 0xC($s1)
    /* 3C428 800A4C28 00000000 */  nop
    /* 3C42C 800A4C2C 0F005030 */  andi       $s0, $v0, 0xF
    /* 3C430 800A4C30 B034020C */  jal        func_8008D2C0
    /* 3C434 800A4C34 FEFF1026 */   addiu     $s0, $s0, -0x2
    /* 3C438 800A4C38 21304000 */  addu       $a2, $v0, $zero
    /* 3C43C 800A4C3C 0A00C018 */  blez       $a2, .L800A4C68
    /* 3C440 800A4C40 21200000 */   addu      $a0, $zero, $zero
    /* 3C444 800A4C44 1000A527 */  addiu      $a1, $sp, 0x10
  .L800A4C48:
    /* 3C448 800A4C48 2118A000 */  addu       $v1, $a1, $zero
    /* 3C44C 800A4C4C 06006284 */  lh         $v0, 0x6($v1)
    /* 3C450 800A4C50 00000000 */  nop
    /* 3C454 800A4C54 3D005010 */  beq        $v0, $s0, .L800A4D4C
    /* 3C458 800A4C58 01008424 */   addiu     $a0, $a0, 0x1
    /* 3C45C 800A4C5C 2A108600 */  slt        $v0, $a0, $a2
    /* 3C460 800A4C60 F9FF4014 */  bnez       $v0, .L800A4C48
    /* 3C464 800A4C64 08006524 */   addiu     $a1, $v1, 0x8
  .L800A4C68:
    /* 3C468 800A4C68 54930208 */  j          .L800A4D50
    /* 3C46C 800A4C6C 21300000 */   addu      $a2, $zero, $zero
  .L800A4C70:
    /* 3C470 800A4C70 0C002292 */  lbu        $v0, 0xC($s1)
    /* 3C474 800A4C74 0C00238E */  lw         $v1, 0xC($s1)
    /* 3C478 800A4C78 0F004630 */  andi       $a2, $v0, 0xF
    /* 3C47C 800A4C7C 02110300 */  srl        $v0, $v1, 4
    /* 3C480 800A4C80 0F004430 */  andi       $a0, $v0, 0xF
    /* 3C484 800A4C84 1400C410 */  beq        $a2, $a0, .L800A4CD8
    /* 3C488 800A4C88 0F006230 */   andi      $v0, $v1, 0xF
    /* 3C48C 800A4C8C 09004010 */  beqz       $v0, .L800A4CB4
    /* 3C490 800A4C90 FEFF8424 */   addiu     $a0, $a0, -0x2
    /* 3C494 800A4C94 0F002592 */  lbu        $a1, 0xF($s1)
    /* 3C498 800A4C98 0C002492 */  lbu        $a0, 0xC($s1)
    /* 3C49C 800A4C9C F21726A6 */  sh         $a2, 0x17F2($s1)
    /* 3C4A0 800A4CA0 0F008430 */  andi       $a0, $a0, 0xF
    /* 3C4A4 800A4CA4 2731020C */  jal        func_8008C49C
    /* 3C4A8 800A4CA8 FEFF8424 */   addiu     $a0, $a0, -0x2
    /* 3C4AC 800A4CAC 36930208 */  j          .L800A4CD8
    /* 3C4B0 800A4CB0 00000000 */   nop
  .L800A4CB4:
    /* 3C4B4 800A4CB4 2731020C */  jal        func_8008C49C
    /* 3C4B8 800A4CB8 FFFF0524 */   addiu     $a1, $zero, -0x1
    /* 3C4BC 800A4CBC 0800228E */  lw         $v0, 0x8($s1)
    /* 3C4C0 800A4CC0 0700033C */  lui        $v1, (0x70000 >> 16)
    /* 3C4C4 800A4CC4 24104300 */  and        $v0, $v0, $v1
    /* 3C4C8 800A4CC8 03004014 */  bnez       $v0, .L800A4CD8
    /* 3C4CC 800A4CCC 00000000 */   nop
    /* 3C4D0 800A4CD0 EE0620A2 */  sb         $zero, 0x6EE($s1)
    /* 3C4D4 800A4CD4 EF0620A2 */  sb         $zero, 0x6EF($s1)
  .L800A4CD8:
    /* 3C4D8 800A4CD8 0F002292 */  lbu        $v0, 0xF($s1)
    /* 3C4DC 800A4CDC 00000000 */  nop
    /* 3C4E0 800A4CE0 0F004014 */  bnez       $v0, .L800A4D20
    /* 3C4E4 800A4CE4 0FFF0224 */   addiu     $v0, $zero, -0xF1
    /* 3C4E8 800A4CE8 0800228E */  lw         $v0, 0x8($s1)
    /* 3C4EC 800A4CEC 0700033C */  lui        $v1, (0x70000 >> 16)
    /* 3C4F0 800A4CF0 24104300 */  and        $v0, $v0, $v1
    /* 3C4F4 800A4CF4 0A004014 */  bnez       $v0, .L800A4D20
    /* 3C4F8 800A4CF8 0FFF0224 */   addiu     $v0, $zero, -0xF1
    /* 3C4FC 800A4CFC 0C002292 */  lbu        $v0, 0xC($s1)
    /* 3C500 800A4D00 F2172486 */  lh         $a0, 0x17F2($s1)
    /* 3C504 800A4D04 0F004230 */  andi       $v0, $v0, 0xF
    /* 3C508 800A4D08 05004410 */  beq        $v0, $a0, .L800A4D20
    /* 3C50C 800A4D0C 0FFF0224 */   addiu     $v0, $zero, -0xF1
    /* 3C510 800A4D10 F692030C */  jal        func_800E4BD8
    /* 3C514 800A4D14 00000000 */   nop
    /* 3C518 800A4D18 F21720A6 */  sh         $zero, 0x17F2($s1)
    /* 3C51C 800A4D1C 0FFF0224 */  addiu      $v0, $zero, -0xF1
  .L800A4D20:
    /* 3C520 800A4D20 0C00248E */  lw         $a0, 0xC($s1)
    /* 3C524 800A4D24 0C002392 */  lbu        $v1, 0xC($s1)
    /* 3C528 800A4D28 24208200 */  and        $a0, $a0, $v0
    /* 3C52C 800A4D2C 0F006330 */  andi       $v1, $v1, 0xF
    /* 3C530 800A4D30 00190300 */  sll        $v1, $v1, 4
    /* 3C534 800A4D34 0C002292 */  lbu        $v0, 0xC($s1)
    /* 3C538 800A4D38 25208300 */  or         $a0, $a0, $v1
    /* 3C53C 800A4D3C 0C0024AE */  sw         $a0, 0xC($s1)
    /* 3C540 800A4D40 0F004230 */  andi       $v0, $v0, 0xF
    /* 3C544 800A4D44 5D930208 */  j          .L800A4D74
    /* 3C548 800A4D48 5D0022A2 */   sb        $v0, 0x5D($s1)
  .L800A4D4C:
    /* 3C54C 800A4D4C 2130A000 */  addu       $a2, $a1, $zero
  .L800A4D50:
    /* 3C550 800A4D50 0000C294 */  lhu        $v0, 0x0($a2)
    /* 3C554 800A4D54 00000000 */  nop
    /* 3C558 800A4D58 EC1722A6 */  sh         $v0, 0x17EC($s1)
    /* 3C55C 800A4D5C 0200C294 */  lhu        $v0, 0x2($a2)
    /* 3C560 800A4D60 00000000 */  nop
    /* 3C564 800A4D64 EE1722A6 */  sh         $v0, 0x17EE($s1)
    /* 3C568 800A4D68 0400C294 */  lhu        $v0, 0x4($a2)
    /* 3C56C 800A4D6C 00000000 */  nop
    /* 3C570 800A4D70 F01722A6 */  sh         $v0, 0x17F0($s1)
  .L800A4D74:
    /* 3C574 800A4D74 3800BF8F */  lw         $ra, 0x38($sp)
    /* 3C578 800A4D78 3400B18F */  lw         $s1, 0x34($sp)
    /* 3C57C 800A4D7C 3000B08F */  lw         $s0, 0x30($sp)
    /* 3C580 800A4D80 4000BD27 */  addiu      $sp, $sp, 0x40
    /* 3C584 800A4D84 0800E003 */  jr         $ra
    /* 3C588 800A4D88 00000000 */   nop
endlabel func_800A4A88
