/* Handwritten function */
nonmatching func_800B4B14, 0x658

glabel func_800B4B14
    /* 4C314 800B4B14 801F083C */  lui        $t0, (0x1F800348 >> 16)
    /* 4C318 800B4B18 200310AD */  sw         $s0, (0x1F800320 & 0xFFFF)($t0)
    /* 4C31C 800B4B1C 240311AD */  sw         $s1, (0x1F800324 & 0xFFFF)($t0)
    /* 4C320 800B4B20 280312AD */  sw         $s2, (0x1F800328 & 0xFFFF)($t0)
    /* 4C324 800B4B24 2C0313AD */  sw         $s3, (0x1F80032C & 0xFFFF)($t0)
    /* 4C328 800B4B28 300314AD */  sw         $s4, (0x1F800330 & 0xFFFF)($t0)
    /* 4C32C 800B4B2C 340315AD */  sw         $s5, (0x1F800334 & 0xFFFF)($t0)
    /* 4C330 800B4B30 380316AD */  sw         $s6, (0x1F800338 & 0xFFFF)($t0)
    /* 4C334 800B4B34 3C0317AD */  sw         $s7, (0x1F80033C & 0xFFFF)($t0)
    /* 4C338 800B4B38 40031FAD */  sw         $ra, (0x1F800340 & 0xFFFF)($t0)
    /* 4C33C 800B4B3C 44031CAD */  sw         $gp, (0x1F800344 & 0xFFFF)($t0)
    /* 4C340 800B4B40 48031EAD */  sw         $fp, (0x1F800348 & 0xFFFF)($t0)
    /* 4C344 800B4B44 801F173C */  lui        $s7, (0x1F8003E4 >> 16)
    /* 4C348 800B4B48 25800400 */  or         $s0, $zero, $a0
    /* 4C34C 800B4B4C 1C00918C */  lw         $s1, 0x1C($a0)
    /* 4C350 800B4B50 20009484 */  lh         $s4, 0x20($a0)
    /* 4C354 800B4B54 FFFF3332 */  andi       $s3, $s1, 0xFFFF
    /* 4C358 800B4B58 1C008420 */  addi       $a0, $a0, 0x1C /* handwritten instruction */
    /* 4C35C 800B4B5C 25280000 */  or         $a1, $zero, $zero
    /* 4C360 800B4B60 25300000 */  or         $a2, $zero, $zero
    /* 4C364 800B4B64 BA9B020C */  jal        func_800A6EE8
    /* 4C368 800B4B68 03000734 */   ori       $a3, $zero, 0x3
    /* 4C36C 800B4B6C 25F04000 */  or         $fp, $v0, $zero
    /* 4C370 800B4B70 031C1100 */  sra        $v1, $s1, 16
    /* 4C374 800B4B74 22106200 */  sub        $v0, $v1, $v0 /* handwritten instruction */
    /* 4C378 800B4B78 02004018 */  blez       $v0, .L800B4B84
    /* 4C37C 800B4B7C 00000000 */   nop
    /* 4C380 800B4B80 03F41100 */  sra        $fp, $s1, 16
  .L800B4B84:
    /* 4C384 800B4B84 B203E286 */  lh         $v0, (0x1F8003B2 & 0xFFFF)($s7)
    /* 4C388 800B4B88 4C061296 */  lhu        $s2, 0x64C($s0)
    /* 4C38C 800B4B8C 22105E00 */  sub        $v0, $v0, $fp /* handwritten instruction */
    /* 4C390 800B4B90 C3100200 */  sra        $v0, $v0, 3
    /* 4C394 800B4B94 20105200 */  add        $v0, $v0, $s2 /* handwritten instruction */
    /* 4C398 800B4B98 14004328 */  slti       $v1, $v0, 0x14
    /* 4C39C 800B4B9C 02006010 */  beqz       $v1, .L800B4BA8
    /* 4C3A0 800B4BA0 00000000 */   nop
    /* 4C3A4 800B4BA4 14000234 */  ori        $v0, $zero, 0x14
  .L800B4BA8:
    /* 4C3A8 800B4BA8 0F80153C */  lui        $s5, %hi(D_800F49F4)
    /* 4C3AC 800B4BAC F449B526 */  addiu      $s5, $s5, %lo(D_800F49F4)
    /* 4C3B0 800B4BB0 00000000 */  nop
    /* 4C3B4 800B4BB4 0000A882 */  lb         $t0, 0x0($s5)
    /* 4C3B8 800B4BB8 C0B10200 */  sll        $s6, $v0, 7
    /* 4C3BC 800B4BBC 5800001D */  bgtz       $t0, .L800B4D20
    /* 4C3C0 800B4BC0 C2211300 */   srl       $a0, $s3, 7
    /* 4C3C4 800B4BC4 C2291400 */  srl        $a1, $s4, 7
    /* 4C3C8 800B4BC8 E403E0AE */  sw         $zero, (0x1F8003E4 & 0xFFFF)($s7)
    /* 4C3CC 800B4BCC 1C000422 */  addi       $a0, $s0, 0x1C /* handwritten instruction */
    /* 4C3D0 800B4BD0 25284002 */  or         $a1, $s2, $zero
    /* 4C3D4 800B4BD4 25300000 */  or         $a2, $zero, $zero
    /* 4C3D8 800B4BD8 BA9B020C */  jal        func_800A6EE8
    /* 4C3DC 800B4BDC 03000734 */   ori       $a3, $zero, 0x3
    /* 4C3E0 800B4BE0 0000A882 */  lb         $t0, 0x0($s5)
    /* 4C3E4 800B4BE4 25884000 */  or         $s1, $v0, $zero
    /* 4C3E8 800B4BE8 4D00001D */  bgtz       $t0, .L800B4D20
    /* 4C3EC 800B4BEC 1C000426 */   addiu     $a0, $s0, 0x1C
    /* 4C3F0 800B4BF0 22281200 */  neg        $a1, $s2 /* handwritten instruction */
    /* 4C3F4 800B4BF4 25300000 */  or         $a2, $zero, $zero
    /* 4C3F8 800B4BF8 BA9B020C */  jal        func_800A6EE8
    /* 4C3FC 800B4BFC 03000734 */   ori       $a3, $zero, 0x3
    /* 4C400 800B4C00 0000A882 */  lb         $t0, 0x0($s5)
    /* 4C404 800B4C04 25184000 */  or         $v1, $v0, $zero
    /* 4C408 800B4C08 4500001D */  bgtz       $t0, .L800B4D20
    /* 4C40C 800B4C0C 22207100 */   sub       $a0, $v1, $s1 /* handwritten instruction */
    /* 4C410 800B4C10 17008010 */  beqz       $a0, .L800B4C70
    /* 4C414 800B4C14 2220C303 */   sub       $a0, $fp, $v1 /* handwritten instruction */
    /* 4C418 800B4C18 22283E02 */  sub        $a1, $s1, $fp /* handwritten instruction */
    /* 4C41C 800B4C1C 02008104 */  bgez       $a0, .L800B4C28
    /* 4C420 800B4C20 25100400 */   or        $v0, $zero, $a0
    /* 4C424 800B4C24 22100400 */  neg        $v0, $a0 /* handwritten instruction */
  .L800B4C28:
    /* 4C428 800B4C28 0200A104 */  bgez       $a1, .L800B4C34
    /* 4C42C 800B4C2C 25180500 */   or        $v1, $zero, $a1
    /* 4C430 800B4C30 22180500 */  neg        $v1, $a1 /* handwritten instruction */
  .L800B4C34:
    /* 4C434 800B4C34 22104300 */  sub        $v0, $v0, $v1 /* handwritten instruction */
    /* 4C438 800B4C38 02004018 */  blez       $v0, .L800B4C44
    /* 4C43C 800B4C3C 00000000 */   nop
    /* 4C440 800B4C40 25200500 */  or         $a0, $zero, $a1
  .L800B4C44:
    /* 4C444 800B4C44 DF04010C */  jal        ratan2
    /* 4C448 800B4C48 25281200 */   or        $a1, $zero, $s2
    /* 4C44C 800B4C4C 80FD4328 */  slti       $v1, $v0, -0x280
    /* 4C450 800B4C50 0500601C */  bgtz       $v1, .L800B4C68
    /* 4C454 800B4C54 80024828 */   slti      $t0, $v0, 0x280
    /* 4C458 800B4C58 03000011 */  beqz       $t0, .L800B4C68
    /* 4C45C 800B4C5C 00000000 */   nop
    /* 4C460 800B4C60 1CD30208 */  j          .L800B4C70
    /* 4C464 800B4C64 E403E2A6 */   sh        $v0, (0x1F8003E4 & 0xFFFF)($s7)
  .L800B4C68:
    /* 4C468 800B4C68 25100000 */  or         $v0, $zero, $zero
    /* 4C46C 800B4C6C E403E2A6 */  sh         $v0, (0x1F8003E4 & 0xFFFF)($s7)
  .L800B4C70:
    /* 4C470 800B4C70 E003E0A6 */  sh         $zero, (0x1F8003E0 & 0xFFFF)($s7)
    /* 4C474 800B4C74 1C000426 */  addiu      $a0, $s0, 0x1C
    /* 4C478 800B4C78 25280000 */  or         $a1, $zero, $zero
    /* 4C47C 800B4C7C 22301200 */  neg        $a2, $s2 /* handwritten instruction */
    /* 4C480 800B4C80 BA9B020C */  jal        func_800A6EE8
    /* 4C484 800B4C84 03000734 */   ori       $a3, $zero, 0x3
    /* 4C488 800B4C88 0000A882 */  lb         $t0, 0x0($s5)
    /* 4C48C 800B4C8C 25884000 */  or         $s1, $v0, $zero
    /* 4C490 800B4C90 2300001D */  bgtz       $t0, .L800B4D20
    /* 4C494 800B4C94 1C000426 */   addiu     $a0, $s0, 0x1C
    /* 4C498 800B4C98 25280000 */  or         $a1, $zero, $zero
    /* 4C49C 800B4C9C 25301200 */  or         $a2, $zero, $s2
    /* 4C4A0 800B4CA0 BA9B020C */  jal        func_800A6EE8
    /* 4C4A4 800B4CA4 03000734 */   ori       $a3, $zero, 0x3
    /* 4C4A8 800B4CA8 0000A882 */  lb         $t0, 0x0($s5)
    /* 4C4AC 800B4CAC 25184000 */  or         $v1, $v0, $zero
    /* 4C4B0 800B4CB0 1B00001D */  bgtz       $t0, .L800B4D20
    /* 4C4B4 800B4CB4 22207100 */   sub       $a0, $v1, $s1 /* handwritten instruction */
    /* 4C4B8 800B4CB8 17008010 */  beqz       $a0, .L800B4D18
    /* 4C4BC 800B4CBC 2220C303 */   sub       $a0, $fp, $v1 /* handwritten instruction */
    /* 4C4C0 800B4CC0 22283E02 */  sub        $a1, $s1, $fp /* handwritten instruction */
    /* 4C4C4 800B4CC4 02008104 */  bgez       $a0, .L800B4CD0
    /* 4C4C8 800B4CC8 25100400 */   or        $v0, $zero, $a0
    /* 4C4CC 800B4CCC 22100400 */  neg        $v0, $a0 /* handwritten instruction */
  .L800B4CD0:
    /* 4C4D0 800B4CD0 0200A104 */  bgez       $a1, .L800B4CDC
    /* 4C4D4 800B4CD4 25180500 */   or        $v1, $zero, $a1
    /* 4C4D8 800B4CD8 22180500 */  neg        $v1, $a1 /* handwritten instruction */
  .L800B4CDC:
    /* 4C4DC 800B4CDC 22104300 */  sub        $v0, $v0, $v1 /* handwritten instruction */
    /* 4C4E0 800B4CE0 02004018 */  blez       $v0, .L800B4CEC
    /* 4C4E4 800B4CE4 00000000 */   nop
    /* 4C4E8 800B4CE8 25200500 */  or         $a0, $zero, $a1
  .L800B4CEC:
    /* 4C4EC 800B4CEC DF04010C */  jal        ratan2
    /* 4C4F0 800B4CF0 25281200 */   or        $a1, $zero, $s2
    /* 4C4F4 800B4CF4 80FD4328 */  slti       $v1, $v0, -0x280
    /* 4C4F8 800B4CF8 0500601C */  bgtz       $v1, .L800B4D10
    /* 4C4FC 800B4CFC 80024828 */   slti      $t0, $v0, 0x280
    /* 4C500 800B4D00 03000011 */  beqz       $t0, .L800B4D10
    /* 4C504 800B4D04 00000000 */   nop
    /* 4C508 800B4D08 46D30208 */  j          .L800B4D18
    /* 4C50C 800B4D0C E003E2A6 */   sh        $v0, (0x1F8003E0 & 0xFFFF)($s7)
  .L800B4D10:
    /* 4C510 800B4D10 25100000 */  or         $v0, $zero, $zero
    /* 4C514 800B4D14 E003E2A6 */  sh         $v0, (0x1F8003E0 & 0xFFFF)($s7)
  .L800B4D18:
    /* 4C518 800B4D18 51D30208 */  j          .L800B4D44
    /* 4C51C 800B4D1C E203E0A6 */   sh        $zero, (0x1F8003E2 & 0xFFFF)($s7)
  .L800B4D20:
    /* 4C520 800B4D20 00100234 */  ori        $v0, $zero, 0x1000
    /* 4C524 800B4D24 C003E2AE */  sw         $v0, (0x1F8003C0 & 0xFFFF)($s7)
    /* 4C528 800B4D28 C403E0AE */  sw         $zero, (0x1F8003C4 & 0xFFFF)($s7)
    /* 4C52C 800B4D2C C803E2AE */  sw         $v0, (0x1F8003C8 & 0xFFFF)($s7)
    /* 4C530 800B4D30 CC03E0AE */  sw         $zero, (0x1F8003CC & 0xFFFF)($s7)
    /* 4C534 800B4D34 E003E0AE */  sw         $zero, (0x1F8003E0 & 0xFFFF)($s7)
    /* 4C538 800B4D38 E403E0AE */  sw         $zero, (0x1F8003E4 & 0xFFFF)($s7)
    /* 4C53C 800B4D3C 54D30208 */  j          .L800B4D50
    /* 4C540 800B4D40 D003E2AE */   sw        $v0, (0x1F8003D0 & 0xFFFF)($s7)
  .L800B4D44:
    /* 4C544 800B4D44 E003E426 */  addiu      $a0, $s7, %lo(D_1F8003E0)
    /* 4C548 800B4D48 E303010C */  jal        func_80040F8C
    /* 4C54C 800B4D4C C003E526 */   addiu     $a1, $s7, %lo(D_1F8003C0)
  .L800B4D50:
    /* 4C550 800B4D50 1400E426 */  addiu      $a0, $s7, %lo(D_1F800014_mat)
    /* 4C554 800B4D54 5BC6020C */  jal        func_800B196C
    /* 4C558 800B4D58 C003E526 */   addiu     $a1, $s7, %lo(D_1F8003C0)
    /* 4C55C 800B4D5C 2400028E */  lw         $v0, 0x24($s0)
    /* 4C560 800B4D60 2800048E */  lw         $a0, 0x28($s0)
    /* 4C564 800B4D64 6C180686 */  lh         $a2, 0x186C($s0)
    /* 4C568 800B4D68 E003E2AE */  sw         $v0, (0x1F8003E0 & 0xFFFF)($s7)
    /* 4C56C 800B4D6C E403E4AE */  sw         $a0, (0x1F8003E4 & 0xFFFF)($s7)
    /* 4C570 800B4D70 032C0200 */  sra        $a1, $v0, 16
    /* 4C574 800B4D74 2028A600 */  add        $a1, $a1, $a2 /* handwritten instruction */
    /* 4C578 800B4D78 E203E5A6 */  sh         $a1, (0x1F8003E2 & 0xFFFF)($s7)
    /* 4C57C 800B4D7C E003E426 */  addiu      $a0, $s7, %lo(D_1F8003E0)
    /* 4C580 800B4D80 E303010C */  jal        func_80040F8C
    /* 4C584 800B4D84 5003E526 */   addiu     $a1, $s7, %lo(D_1F800350)
    /* 4C588 800B4D88 C003E426 */  addiu      $a0, $s7, %lo(D_1F8003C0)
    /* 4C58C 800B4D8C 5BC6020C */  jal        func_800B196C
    /* 4C590 800B4D90 5003E526 */   addiu     $a1, $s7, %lo(D_1F800350)
    /* 4C594 800B4D94 C003E426 */  addiu      $a0, $s7, %lo(D_1F8003C0)
    /* 4C598 800B4D98 5003E526 */  addiu      $a1, $s7, %lo(D_1F800350)
    /* 4C59C 800B4D9C 2C24010C */  jal        vs_main_memcpy
    /* 4C5A0 800B4DA0 20000634 */   ori       $a2, $zero, 0x20
    /* 4C5A4 800B4DA4 2C00088E */  lw         $t0, 0x2C($s0)
    /* 4C5A8 800B4DA8 3000098E */  lw         $t1, 0x30($s0)
    /* 4C5AC 800B4DAC 02140800 */  srl        $v0, $t0, 16
    /* 4C5B0 800B4DB0 1900C202 */  multu      $s6, $v0
    /* 4C5B4 800B4DB4 70180A86 */  lh         $t2, 0x1870($s0)
    /* 4C5B8 800B4DB8 72180B86 */  lh         $t3, 0x1872($s0)
    /* 4C5BC 800B4DBC 42500A00 */  srl        $t2, $t2, 1
    /* 4C5C0 800B4DC0 42580B00 */  srl        $t3, $t3, 1
    /* 4C5C4 800B4DC4 EC03E9AE */  sw         $t1, (0x1F8003EC & 0xFFFF)($s7)
    /* 4C5C8 800B4DC8 12180000 */  mflo       $v1
    /* 4C5CC 800B4DCC FFFF0231 */  andi       $v0, $t0, 0xFFFF
    /* 4C5D0 800B4DD0 021B0300 */  srl        $v1, $v1, 12
    /* 4C5D4 800B4DD4 19006B00 */  multu      $v1, $t3
    /* 4C5D8 800B4DD8 12180000 */  mflo       $v1
    /* 4C5DC 800B4DDC 00000000 */  nop
    /* 4C5E0 800B4DE0 021B0300 */  srl        $v1, $v1, 12
    /* 4C5E4 800B4DE4 1900C202 */  multu      $s6, $v0
    /* 4C5E8 800B4DE8 E803E3AE */  sw         $v1, (0x1F8003E8 & 0xFFFF)($s7)
    /* 4C5EC 800B4DEC 12180000 */  mflo       $v1
    /* 4C5F0 800B4DF0 00000000 */  nop
    /* 4C5F4 800B4DF4 021B0300 */  srl        $v1, $v1, 12
    /* 4C5F8 800B4DF8 19006A00 */  multu      $v1, $t2
    /* 4C5FC 800B4DFC 00000000 */  nop
    /* 4C600 800B4E00 12180000 */  mflo       $v1
    /* 4C604 800B4E04 00000000 */  nop
    /* 4C608 800B4E08 021B0300 */  srl        $v1, $v1, 12
    /* 4C60C 800B4E0C F003E3AE */  sw         $v1, (0x1F8003F0 & 0xFFFF)($s7)
    /* 4C610 800B4E10 C003E426 */  addiu      $a0, $s7, %lo(D_1F8003C0)
    /* 4C614 800B4E14 5BCE020C */  jal        func_800B396C
    /* 4C618 800B4E18 E803E526 */   addiu     $a1, $s7, %lo(D_1F8003E8)
    /* 4C61C 800B4E1C 1400E88E */  lw         $t0, (0x1F800014 & 0xFFFF)($s7)
    /* 4C620 800B4E20 1800E98E */  lw         $t1, (0x1F800018 & 0xFFFF)($s7)
    /* 4C624 800B4E24 1C00EA8E */  lw         $t2, (0x1F80001C & 0xFFFF)($s7)
    /* 4C628 800B4E28 2000EB8E */  lw         $t3, (0x1F800020 & 0xFFFF)($s7)
    /* 4C62C 800B4E2C 0000C848 */  ctc2       $t0, $0 /* handwritten instruction */
    /* 4C630 800B4E30 0008C948 */  ctc2       $t1, $1 /* handwritten instruction */
    /* 4C634 800B4E34 0010CA48 */  ctc2       $t2, $2 /* handwritten instruction */
    /* 4C638 800B4E38 0018CB48 */  ctc2       $t3, $3 /* handwritten instruction */
    /* 4C63C 800B4E3C 2400E88E */  lw         $t0, (0x1F800024 & 0xFFFF)($s7)
    /* 4C640 800B4E40 2800E98E */  lw         $t1, (0x1F800028 & 0xFFFF)($s7)
    /* 4C644 800B4E44 2C00EA8E */  lw         $t2, (0x1F80002C & 0xFFFF)($s7)
    /* 4C648 800B4E48 3000EB8E */  lw         $t3, (0x1F800030 & 0xFFFF)($s7)
    /* 4C64C 800B4E4C 0020C848 */  ctc2       $t0, $4 /* handwritten instruction */
    /* 4C650 800B4E50 0028C948 */  ctc2       $t1, $5 /* handwritten instruction */
    /* 4C654 800B4E54 0030CA48 */  ctc2       $t2, $6 /* handwritten instruction */
    /* 4C658 800B4E58 0038CB48 */  ctc2       $t3, $7 /* handwritten instruction */
    /* 4C65C 800B4E5C B003E28E */  lw         $v0, (0x1F8003B0 & 0xFFFF)($s7)
    /* 4C660 800B4E60 B403E88E */  lw         $t0, (0x1F8003B4 & 0xFFFF)($s7)
    /* 4C664 800B4E64 001C1E00 */  sll        $v1, $fp, 16
    /* 4C668 800B4E68 FFFF4230 */  andi       $v0, $v0, 0xFFFF
    /* 4C66C 800B4E6C 25104300 */  or         $v0, $v0, $v1
    /* 4C670 800B4E70 00008248 */  mtc2       $v0, $0 /* handwritten instruction */
    /* 4C674 800B4E74 00088848 */  mtc2       $t0, $1 /* handwritten instruction */
    /* 4C678 800B4E78 C003EA8E */  lw         $t2, (0x1F8003C0 & 0xFFFF)($s7)
    /* 4C67C 800B4E7C C403EB8E */  lw         $t3, (0x1F8003C4 & 0xFFFF)($s7)
    /* 4C680 800B4E80 1200484A */  mvmva      1, 0, 0, 0, 0
    /* 4C684 800B4E84 C803EC8E */  lw         $t4, (0x1F8003C8 & 0xFFFF)($s7)
    /* 4C688 800B4E88 CC03ED8E */  lw         $t5, (0x1F8003CC & 0xFFFF)($s7)
    /* 4C68C 800B4E8C D003EE8E */  lw         $t6, (0x1F8003D0 & 0xFFFF)($s7)
    /* 4C690 800B4E90 7003F326 */  addiu      $s3, $s7, %lo(D_1F800370)
    /* 4C694 800B4E94 B803F426 */  addiu      $s4, $s7, %lo(D_1F8003B8)
    /* 4C698 800B4E98 05001534 */  ori        $s5, $zero, 0x5
    /* 4C69C 800B4E9C 0F80163C */  lui        $s6, %hi(D_800E9A68)
    /* 4C6A0 800B4EA0 689AD626 */  addiu      $s6, $s6, %lo(D_800E9A68)
    /* 4C6A4 800B4EA4 00C80F48 */  mfc2       $t7, $25 /* handwritten instruction */
    /* 4C6A8 800B4EA8 00D01848 */  mfc2       $t8, $26 /* handwritten instruction */
    /* 4C6AC 800B4EAC 00D81948 */  mfc2       $t9, $27 /* handwritten instruction */
    /* 4C6B0 800B4EB0 0000CA48 */  ctc2       $t2, $0 /* handwritten instruction */
    /* 4C6B4 800B4EB4 0008CB48 */  ctc2       $t3, $1 /* handwritten instruction */
    /* 4C6B8 800B4EB8 0010CC48 */  ctc2       $t4, $2 /* handwritten instruction */
    /* 4C6BC 800B4EBC 0018CD48 */  ctc2       $t5, $3 /* handwritten instruction */
    /* 4C6C0 800B4EC0 0020CE48 */  ctc2       $t6, $4 /* handwritten instruction */
    /* 4C6C4 800B4EC4 0028CF48 */  ctc2       $t7, $5 /* handwritten instruction */
    /* 4C6C8 800B4EC8 0030D848 */  ctc2       $t8, $6 /* handwritten instruction */
    /* 4C6CC 800B4ECC 0038D948 */  ctc2       $t9, $7 /* handwritten instruction */
    /* 4C6D0 800B4ED0 0000C98E */  lw         $t1, 0x0($s6)
    /* 4C6D4 800B4ED4 0400CB8E */  lw         $t3, 0x4($s6)
    /* 4C6D8 800B4ED8 0800CD8E */  lw         $t5, 0x8($s6)
    /* 4C6DC 800B4EDC FFFF2831 */  andi       $t0, $t1, 0xFFFF
    /* 4C6E0 800B4EE0 024C0900 */  srl        $t1, $t1, 16
    /* 4C6E4 800B4EE4 FFFF6A31 */  andi       $t2, $t3, 0xFFFF
    /* 4C6E8 800B4EE8 025C0B00 */  srl        $t3, $t3, 16
    /* 4C6EC 800B4EEC FFFFAC31 */  andi       $t4, $t5, 0xFFFF
    /* 4C6F0 800B4EF0 026C0D00 */  srl        $t5, $t5, 16
  .L800B4EF4:
    /* 4C6F4 800B4EF4 00008848 */  mtc2       $t0, $0 /* handwritten instruction */
    /* 4C6F8 800B4EF8 00088948 */  mtc2       $t1, $1 /* handwritten instruction */
    /* 4C6FC 800B4EFC 00108A48 */  mtc2       $t2, $2 /* handwritten instruction */
    /* 4C700 800B4F00 00188B48 */  mtc2       $t3, $3 /* handwritten instruction */
    /* 4C704 800B4F04 00208C48 */  mtc2       $t4, $4 /* handwritten instruction */
    /* 4C708 800B4F08 00288D48 */  mtc2       $t5, $5 /* handwritten instruction */
    /* 4C70C 800B4F0C 0C00D626 */  addiu      $s6, $s6, 0xC
    /* 4C710 800B4F10 FFFFB522 */  addi       $s5, $s5, -0x1 /* handwritten instruction */
    /* 4C714 800B4F14 3000284A */  rtpt
    /* 4C718 800B4F18 0000C98E */  lw         $t1, 0x0($s6)
    /* 4C71C 800B4F1C 0400CB8E */  lw         $t3, 0x4($s6)
    /* 4C720 800B4F20 0800CD8E */  lw         $t5, 0x8($s6)
    /* 4C724 800B4F24 64180E8E */  lw         $t6, 0x1864($s0)
    /* 4C728 800B4F28 FFFF2831 */  andi       $t0, $t1, 0xFFFF
    /* 4C72C 800B4F2C 024C0900 */  srl        $t1, $t1, 16
    /* 4C730 800B4F30 FFFF6A31 */  andi       $t2, $t3, 0xFFFF
    /* 4C734 800B4F34 025C0B00 */  srl        $t3, $t3, 16
    /* 4C738 800B4F38 FFFFAC31 */  andi       $t4, $t5, 0xFFFF
    /* 4C73C 800B4F3C 026C0D00 */  srl        $t5, $t5, 16
    /* 4C740 800B4F40 027A0E00 */  srl        $t7, $t6, 8
    /* 4C744 800B4F44 FF00EF31 */  andi       $t7, $t7, 0xFF
    /* 4C748 800B4F48 40780F00 */  sll        $t7, $t7, 1
    /* 4C74C 800B4F4C 02C40E00 */  srl        $t8, $t6, 16
    /* 4C750 800B4F50 FF00CE31 */  andi       $t6, $t6, 0xFF
    /* 4C754 800B4F54 00006CEA */  swc2       $12, 0x0($s3)
    /* 4C758 800B4F58 04006DEA */  swc2       $13, 0x4($s3)
    /* 4C75C 800B4F5C 08006EEA */  swc2       $14, 0x8($s3)
    /* 4C760 800B4F60 000091EA */  swc2       $17, 0x0($s4)
    /* 4C764 800B4F64 040092EA */  swc2       $18, 0x4($s4)
    /* 4C768 800B4F68 080093EA */  swc2       $19, 0x8($s4)
    /* 4C76C 800B4F6C 0C007326 */  addiu      $s3, $s3, 0xC
    /* 4C770 800B4F70 E0FFA106 */  bgez       $s5, .L800B4EF4
    /* 4C774 800B4F74 0C009426 */   addiu     $s4, $s4, 0xC
    /* 4C778 800B4F78 F2060882 */  lb         $t0, 0x6F2($s0)
    /* 4C77C 800B4F7C 2070CF01 */  add        $t6, $t6, $t7 /* handwritten instruction */
    /* 4C780 800B4F80 2070D801 */  add        $t6, $t6, $t8 /* handwritten instruction */
    /* 4C784 800B4F84 82700E00 */  srl        $t6, $t6, 2
    /* 4C788 800B4F88 4000CE21 */  addi       $t6, $t6, 0x40 /* handwritten instruction */
    /* 4C78C 800B4F8C 80400800 */  sll        $t0, $t0, 2
    /* 4C790 800B4F90 2270C801 */  sub        $t6, $t6, $t0 /* handwritten instruction */
    /* 4C794 800B4F94 0300C01D */  bgtz       $t6, .L800B4FA4
    /* 4C798 800B4F98 00FF0D3C */   lui       $t5, (0xFF000000 >> 16)
    /* 4C79C 800B4F9C 25700000 */  or         $t6, $zero, $zero
    /* 4C7A0 800B4FA0 EDD30208 */  j          .L800B4FB4
  .L800B4FA4:
    /* 4C7A4 800B4FA4 FF00C229 */   slti      $v0, $t6, 0xFF
    /* 4C7A8 800B4FA8 0200401C */  bgtz       $v0, .L800B4FB4
    /* 4C7AC 800B4FAC 00FF0D3C */   lui       $t5, (0xFF000000 >> 16)
    /* 4C7B0 800B4FB0 FF000E34 */  ori        $t6, $zero, 0xFF
  .L800B4FB4:
    /* 4C7B4 800B4FB4 0032CF35 */  ori        $t7, $t6, 0x3200
    /* 4C7B8 800B4FB8 007A0F00 */  sll        $t7, $t7, 8
    /* 4C7BC 800B4FBC 2578EE01 */  or         $t7, $t7, $t6
    /* 4C7C0 800B4FC0 007A0F00 */  sll        $t7, $t7, 8
    /* 4C7C4 800B4FC4 2578EE01 */  or         $t7, $t7, $t6
    /* 4C7C8 800B4FC8 FF00F831 */  andi       $t8, $t7, 0xFF
    /* 4C7CC 800B4FCC 42C01800 */  srl        $t8, $t8, 1
    /* 4C7D0 800B4FD0 00721800 */  sll        $t6, $t8, 8
    /* 4C7D4 800B4FD4 25C00E03 */  or         $t8, $t8, $t6
    /* 4C7D8 800B4FD8 00720E00 */  sll        $t6, $t6, 8
    /* 4C7DC 800B4FDC 25C00E03 */  or         $t8, $t8, $t6
    /* 4C7E0 800B4FE0 00E1123C */  lui        $s2, (0xE1000640 >> 16)
    /* 4C7E4 800B4FE4 40065236 */  ori        $s2, $s2, (0xE1000640 & 0xFFFF)
    /* 4C7E8 800B4FE8 FF000E3C */  lui        $t6, (0xFFFFFF >> 16)
    /* 4C7EC 800B4FEC FFFFCE35 */  ori        $t6, $t6, (0xFFFFFF & 0xFFFF)
    /* 4C7F0 800B4FF0 00FF143C */  lui        $s4, (0xFF000000 >> 16)
    /* 4C7F4 800B4FF4 7003F98E */  lw         $t9, (0x1F800370 & 0xFFFF)($s7)
    /* 4C7F8 800B4FF8 B803FF8E */  lw         $ra, (0x1F8003B8 & 0xFFFF)($s7)
    /* 4C7FC 800B4FFC FC0619AE */  sw         $t9, 0x6FC($s0)
    /* 4C800 800B5000 00071FAE */  sw         $ra, 0x700($s0)
    /* 4C804 800B5004 17001534 */  ori        $s5, $zero, 0x17
    /* 4C808 800B5008 0F80163C */  lui        $s6, %hi(D_800E9AD4)
    /* 4C80C 800B500C D49AD626 */  addiu      $s6, $s6, %lo(D_800E9AD4)
    /* 4C810 800B5010 0000F18E */  lw         $s1, (0x1F800000 & 0xFFFF)($s7)
    /* 4C814 800B5014 0400FE8E */  lw         $fp, (0x1F800004 & 0xFFFF)($s7)
    /* 4C818 800B5018 00071C3C */  lui        $gp, (0x7000000 >> 16)
  .L800B501C:
    /* 4C81C 800B501C 0000D98E */  lw         $t9, 0x0($s6)
    /* 4C820 800B5020 0400D626 */  addiu      $s6, $s6, 0x4
    /* 4C824 800B5024 FF002833 */  andi       $t0, $t9, 0xFF
    /* 4C828 800B5028 024A1900 */  srl        $t1, $t9, 8
    /* 4C82C 800B502C FF002931 */  andi       $t1, $t1, 0xFF
    /* 4C830 800B5030 02541900 */  srl        $t2, $t9, 16
    /* 4C834 800B5034 FF004A31 */  andi       $t2, $t2, 0xFF
    /* 4C838 800B5038 20401701 */  add        $t0, $t0, $s7 /* handwritten instruction */
    /* 4C83C 800B503C 20483701 */  add        $t1, $t1, $s7 /* handwritten instruction */
    /* 4C840 800B5040 20505701 */  add        $t2, $t2, $s7 /* handwritten instruction */
    /* 4C844 800B5044 70030B8D */  lw         $t3, 0x370($t0)
    /* 4C848 800B5048 70032C8D */  lw         $t4, 0x370($t1)
    /* 4C84C 800B504C 70034D8D */  lw         $t5, 0x370($t2)
    /* 4C850 800B5050 00608B48 */  mtc2       $t3, $12 /* handwritten instruction */
    /* 4C854 800B5054 00688C48 */  mtc2       $t4, $13 /* handwritten instruction */
    /* 4C858 800B5058 00708D48 */  mtc2       $t5, $14 /* handwritten instruction */
    /* 4C85C 800B505C B803028D */  lw         $v0, 0x3B8($t0)
    /* 4C860 800B5060 B803298D */  lw         $t1, 0x3B8($t1)
    /* 4C864 800B5064 0600404B */  nclip
    /* 4C868 800B5068 B8034A8D */  lw         $t2, 0x3B8($t2)
    /* 4C86C 800B506C 2A184900 */  slt        $v1, $v0, $t1
    /* 4C870 800B5070 0200601C */  bgtz       $v1, .L800B507C
    /* 4C874 800B5074 00000000 */   nop
    /* 4C878 800B5078 25102001 */  or         $v0, $t1, $zero
  .L800B507C:
    /* 4C87C 800B507C 2A184A00 */  slt        $v1, $v0, $t2
    /* 4C880 800B5080 0200601C */  bgtz       $v1, .L800B508C
    /* 4C884 800B5084 00000000 */   nop
    /* 4C888 800B5088 25104001 */  or         $v0, $t2, $zero
  .L800B508C:
    /* 4C88C 800B508C 00C00348 */  mfc2       $v1, $24 /* handwritten instruction */
    /* 4C890 800B5090 00000000 */  nop
    /* 4C894 800B5094 1600601C */  bgtz       $v1, .L800B50F0
    /* 4C898 800B5098 040032AE */   sw        $s2, 0x4($s1)
    /* 4C89C 800B509C 08002FAE */  sw         $t7, 0x8($s1)
    /* 4C8A0 800B50A0 0C002BAE */  sw         $t3, 0xC($s1)
    /* 4C8A4 800B50A4 100038AE */  sw         $t8, 0x10($s1)
    /* 4C8A8 800B50A8 14002CAE */  sw         $t4, 0x14($s1)
    /* 4C8AC 800B50AC 180038AE */  sw         $t8, 0x18($s1)
    /* 4C8B0 800B50B0 82100200 */  srl        $v0, $v0, 2
    /* 4C8B4 800B50B4 1C002DAE */  sw         $t5, 0x1C($s1)
    /* 4C8B8 800B50B8 FEFF4220 */  addi       $v0, $v0, -0x2 /* handwritten instruction */
    /* 4C8BC 800B50BC C007432C */  sltiu      $v1, $v0, 0x7C0
    /* 4C8C0 800B50C0 0B006010 */  beqz       $v1, .L800B50F0
    /* 4C8C4 800B50C4 80100200 */   sll       $v0, $v0, 2
    /* 4C8C8 800B50C8 2010C203 */  add        $v0, $fp, $v0 /* handwritten instruction */
    /* 4C8CC 800B50CC 00004A8C */  lw         $t2, 0x0($v0)
    /* 4C8D0 800B50D0 24482E02 */  and        $t1, $s1, $t6
    /* 4C8D4 800B50D4 24404E01 */  and        $t0, $t2, $t6
    /* 4C8D8 800B50D8 25401C01 */  or         $t0, $t0, $gp
    /* 4C8DC 800B50DC 000028AE */  sw         $t0, 0x0($s1)
    /* 4C8E0 800B50E0 24405401 */  and        $t0, $t2, $s4
    /* 4C8E4 800B50E4 25400901 */  or         $t0, $t0, $t1
    /* 4C8E8 800B50E8 000048AC */  sw         $t0, 0x0($v0)
    /* 4C8EC 800B50EC 20003126 */  addiu      $s1, $s1, 0x20
  .L800B50F0:
    /* 4C8F0 800B50F0 FFFFB522 */  addi       $s5, $s5, -0x1 /* handwritten instruction */
    /* 4C8F4 800B50F4 0F00A006 */  bltz       $s5, .L800B5134
    /* 4C8F8 800B50F8 F1FFA222 */   addi      $v0, $s5, -0xF /* handwritten instruction */
    /* 4C8FC 800B50FC 05004010 */  beqz       $v0, .L800B5114
    /* 4C900 800B5100 F9FFA222 */   addi      $v0, $s5, -0x7 /* handwritten instruction */
    /* 4C904 800B5104 08004010 */  beqz       $v0, .L800B5128
    /* 4C908 800B5108 00000000 */   nop
    /* 4C90C 800B510C 07D40208 */  j          .L800B501C
    /* 4C910 800B5110 00000000 */   nop
  .L800B5114:
    /* 4C914 800B5114 25780003 */  or         $t7, $t8, $zero
    /* 4C918 800B5118 0032183C */  lui        $t8, (0x32000000 >> 16)
    /* 4C91C 800B511C 2578F801 */  or         $t7, $t7, $t8
    /* 4C920 800B5120 07D40208 */  j          .L800B501C
    /* 4C924 800B5124 25C00000 */   or        $t8, $zero, $zero
  .L800B5128:
    /* 4C928 800B5128 25C0E001 */  or         $t8, $t7, $zero
    /* 4C92C 800B512C 07D40208 */  j          .L800B501C
    /* 4C930 800B5130 00320F3C */   lui       $t7, (0x32000000 >> 16)
  .L800B5134:
    /* 4C934 800B5134 0000F1AE */  sw         $s1, (0x1F800000 & 0xFFFF)($s7)
    /* 4C938 800B5138 801F083C */  lui        $t0, (0x1F800348 >> 16)
    /* 4C93C 800B513C 2003108D */  lw         $s0, (0x1F800320 & 0xFFFF)($t0)
    /* 4C940 800B5140 2403118D */  lw         $s1, (0x1F800324 & 0xFFFF)($t0)
    /* 4C944 800B5144 2803128D */  lw         $s2, (0x1F800328 & 0xFFFF)($t0)
    /* 4C948 800B5148 2C03138D */  lw         $s3, (0x1F80032C & 0xFFFF)($t0)
    /* 4C94C 800B514C 3003148D */  lw         $s4, (0x1F800330 & 0xFFFF)($t0)
    /* 4C950 800B5150 3403158D */  lw         $s5, (0x1F800334 & 0xFFFF)($t0)
    /* 4C954 800B5154 3803168D */  lw         $s6, (0x1F800338 & 0xFFFF)($t0)
    /* 4C958 800B5158 3C03178D */  lw         $s7, (0x1F80033C & 0xFFFF)($t0)
    /* 4C95C 800B515C 40031F8D */  lw         $ra, (0x1F800340 & 0xFFFF)($t0)
    /* 4C960 800B5160 44031C8D */  lw         $gp, (0x1F800344 & 0xFFFF)($t0)
    /* 4C964 800B5164 0800E003 */  jr         $ra
    /* 4C968 800B5168 48031E8D */   lw        $fp, (0x1F800348 & 0xFFFF)($t0)
endlabel func_800B4B14
