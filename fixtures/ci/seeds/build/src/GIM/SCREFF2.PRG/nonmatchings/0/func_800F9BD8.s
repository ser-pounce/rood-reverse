/* Handwritten function */
nonmatching func_800F9BD8, 0x210

glabel func_800F9BD8
    /* 3D8 800F9BD8 F8FFBD27 */  addiu      $sp, $sp, -0x8
    /* 3DC 800F9BDC 801F0D3C */  lui        $t5, (0x1F800088 >> 16)
    /* 3E0 800F9BE0 8800AD35 */  ori        $t5, $t5, (0x1F800088 & 0xFFFF)
    /* 3E4 800F9BE4 21480000 */  addu       $t1, $zero, $zero
    /* 3E8 800F9BE8 21382001 */  addu       $a3, $t1, $zero
    /* 3EC 800F9BEC 801F053C */  lui        $a1, (0x1F800088 >> 16)
    /* 3F0 800F9BF0 801F023C */  lui        $v0, (0x1F800004 >> 16)
    /* 3F4 800F9BF4 04004B8C */  lw         $t3, (0x1F800004 & 0xFFFF)($v0)
    /* 3F8 800F9BF8 8800A534 */  ori        $a1, $a1, (0x1F800088 & 0xFFFF)
    /* 3FC 800F9BFC 0000B0AF */  sw         $s0, 0x0($sp)
    /* 400 800F9C00 0000798D */  lw         $t9, 0x0($t3)
    /* 404 800F9C04 FFFF0224 */  addiu      $v0, $zero, -0x1
    /* 408 800F9C08 000062AD */  sw         $v0, 0x0($t3)
    /* 40C 800F9C0C 0F80023C */  lui        $v0, %hi(D_800EB9B4)
    /* 410 800F9C10 B4B9428C */  lw         $v0, %lo(D_800EB9B4)($v0)
    /* 414 800F9C14 F81F6A25 */  addiu      $t2, $t3, 0x1FF8
    /* 418 800F9C18 04004394 */  lhu        $v1, 0x4($v0)
    /* 41C 800F9C1C 06004284 */  lh         $v0, 0x6($v0)
    /* 420 800F9C20 00310300 */  sll        $a2, $v1, 4
    /* 424 800F9C24 00104424 */  addiu      $a0, $v0, 0x1000
  .L800F9C28:
    /* 428 800F9C28 1800C400 */  mult       $a2, $a0
    /* 42C 800F9C2C C3100600 */  sra        $v0, $a2, 3
    /* 430 800F9C30 0000A2A4 */  sh         $v0, 0x0($a1)
    /* 434 800F9C34 0200A524 */  addiu      $a1, $a1, 0x2
    /* 438 800F9C38 0100E724 */  addiu      $a3, $a3, 0x1
    /* 43C 800F9C3C BC01E22C */  sltiu      $v0, $a3, 0x1BC
    /* 440 800F9C40 12800000 */  mflo       $s0
    /* 444 800F9C44 F8FF4014 */  bnez       $v0, .L800F9C28
    /* 448 800F9C48 03331000 */   sra       $a2, $s0, 12
    /* 44C 800F9C4C FEFF1824 */  addiu      $t8, $zero, -0x2
    /* 450 800F9C50 1F000F24 */  addiu      $t7, $zero, 0x1F
    /* 454 800F9C54 0480023C */  lui        $v0, %hi(D_80040C18)
    /* 458 800F9C58 180C4E24 */  addiu      $t6, $v0, %lo(D_80040C18)
  .L800F9C5C:
    /* 45C 800F9C5C 01000424 */  addiu      $a0, $zero, 0x1
    /* 460 800F9C60 03004791 */  lbu        $a3, %lo(D_80000003)($t2)
    /* 464 800F9C64 04004325 */  addiu      $v1, $t2, %lo(D_80000004)
  .L800F9C68:
    /* 468 800F9C68 0000628C */  lw         $v0, 0x0($v1)
    /* 46C 800F9C6C 04006324 */  addiu      $v1, $v1, 0x4
    /* 470 800F9C70 82160200 */  srl        $v0, $v0, 26
    /* 474 800F9C74 F8FF4624 */  addiu      $a2, $v0, -0x8
    /* 478 800F9C78 3000C22C */  sltiu      $v0, $a2, 0x30
    /* 47C 800F9C7C 04004014 */  bnez       $v0, .L800F9C90
    /* 480 800F9C80 01008424 */   addiu     $a0, $a0, 0x1
    /* 484 800F9C84 2A10E400 */  slt        $v0, $a3, $a0
    /* 488 800F9C88 F7FF4010 */  beqz       $v0, .L800F9C68
    /* 48C 800F9C8C 00000000 */   nop
  .L800F9C90:
    /* 490 800F9C90 0800C22C */  sltiu      $v0, $a2, 0x8
    /* 494 800F9C94 08004010 */  beqz       $v0, .L800F9CB8
    /* 498 800F9C98 0100C230 */   andi      $v0, $a2, 0x1
    /* 49C 800F9C9C 83180600 */  sra        $v1, $a2, 2
    /* 4A0 800F9CA0 01006330 */  andi       $v1, $v1, 0x1
    /* 4A4 800F9CA4 21104300 */  addu       $v0, $v0, $v1
    /* 4A8 800F9CA8 01004C24 */  addiu      $t4, $v0, 0x1
    /* 4AC 800F9CAC 43100600 */  sra        $v0, $a2, 1
    /* 4B0 800F9CB0 01004230 */  andi       $v0, $v0, 0x1
    /* 4B4 800F9CB4 03004924 */  addiu      $t1, $v0, 0x3
  .L800F9CB8:
    /* 4B8 800F9CB8 3C002011 */  beqz       $t1, .L800F9DAC
    /* 4BC 800F9CBC 80100400 */   sll       $v0, $a0, 2
    /* 4C0 800F9CC0 21404A00 */  addu       $t0, $v0, $t2
  .L800F9CC4:
    /* 4C4 800F9CC4 0000078D */  lw         $a3, %lo(D_80000000)($t0)
    /* 4C8 800F9CC8 00000000 */  nop
    /* 4CC 800F9CCC 03140700 */  sra        $v0, $a3, 16
    /* 4D0 800F9CD0 90FF4624 */  addiu      $a2, $v0, -0x70
    /* 4D4 800F9CD4 00140700 */  sll        $v0, $a3, 16
    /* 4D8 800F9CD8 03140200 */  sra        $v0, $v0, 16
    /* 4DC 800F9CDC 60FF4724 */  addiu      $a3, $v0, -0xA0
    /* 4E0 800F9CE0 00488748 */  mtc2       $a3, $9 /* handwritten instruction */
    /* 4E4 800F9CE4 00508648 */  mtc2       $a2, $10 /* handwritten instruction */
    /* 4E8 800F9CE8 FFFF2925 */  addiu      $t1, $t1, -0x1
    /* 4EC 800F9CEC 00000000 */  nop
    /* 4F0 800F9CF0 2804A04A */  sqr        0
    /* 4F4 800F9CF4 00C80348 */  mfc2       $v1, $25 /* handwritten instruction */
    /* 4F8 800F9CF8 00D00248 */  mfc2       $v0, $26 /* handwritten instruction */
    /* 4FC 800F9CFC 00000000 */  nop
    /* 500 800F9D00 21206200 */  addu       $a0, $v1, $v0
    /* 504 800F9D04 00F08448 */  mtc2       $a0, $30 /* handwritten instruction */
    /* 508 800F9D08 14008010 */  beqz       $a0, .L800F9D5C
    /* 50C 800F9D0C 40100400 */   sll       $v0, $a0, 1
    /* 510 800F9D10 00F80348 */  mfc2       $v1, $31 /* handwritten instruction */
    /* 514 800F9D14 00000000 */  nop
    /* 518 800F9D18 24287800 */  and        $a1, $v1, $t8
    /* 51C 800F9D1C 2318E501 */  subu       $v1, $t7, $a1
    /* 520 800F9D20 18000224 */  addiu      $v0, $zero, 0x18
    /* 524 800F9D24 23104500 */  subu       $v0, $v0, $a1
    /* 528 800F9D28 07104400 */  srav       $v0, $a0, $v0
    /* 52C 800F9D2C C0FF4224 */  addiu      $v0, $v0, -0x40
    /* 530 800F9D30 40100200 */  sll        $v0, $v0, 1
    /* 534 800F9D34 21104E00 */  addu       $v0, $v0, $t6
    /* 538 800F9D38 00004594 */  lhu        $a1, 0x0($v0)
    /* 53C 800F9D3C 43100300 */  sra        $v0, $v1, 1
    /* 540 800F9D40 04104500 */  sllv       $v0, $a1, $v0
    /* 544 800F9D44 03230200 */  sra        $a0, $v0, 12
    /* 548 800F9D48 BC01822C */  sltiu      $v0, $a0, 0x1BC
    /* 54C 800F9D4C 03004014 */  bnez       $v0, .L800F9D5C
    /* 550 800F9D50 40100400 */   sll       $v0, $a0, 1
    /* 554 800F9D54 BB010424 */  addiu      $a0, $zero, 0x1BB
    /* 558 800F9D58 40100400 */  sll        $v0, $a0, 1
  .L800F9D5C:
    /* 55C 800F9D5C 21104D00 */  addu       $v0, $v0, $t5
    /* 560 800F9D60 00004494 */  lhu        $a0, 0x0($v0)
    /* 564 800F9D64 00000000 */  nop
    /* 568 800F9D68 1800E400 */  mult       $a3, $a0
    /* 56C 800F9D6C 12180000 */  mflo       $v1
    /* 570 800F9D70 00000000 */  nop
    /* 574 800F9D74 00000000 */  nop
    /* 578 800F9D78 1800C400 */  mult       $a2, $a0
    /* 57C 800F9D7C 431B0300 */  sra        $v1, $v1, 13
    /* 580 800F9D80 A0006324 */  addiu      $v1, $v1, 0xA0
    /* 584 800F9D84 FFFF6330 */  andi       $v1, $v1, 0xFFFF
    /* 588 800F9D88 12100000 */  mflo       $v0
    /* 58C 800F9D8C 43130200 */  sra        $v0, $v0, 13
    /* 590 800F9D90 70004224 */  addiu      $v0, $v0, 0x70
    /* 594 800F9D94 00140200 */  sll        $v0, $v0, 16
    /* 598 800F9D98 25186200 */  or         $v1, $v1, $v0
    /* 59C 800F9D9C 80100C00 */  sll        $v0, $t4, 2
    /* 5A0 800F9DA0 000003AD */  sw         $v1, %lo(D_80000000)($t0)
    /* 5A4 800F9DA4 C7FF2015 */  bnez       $t1, .L800F9CC4
    /* 5A8 800F9DA8 21400201 */   addu      $t0, $t0, $v0
  .L800F9DAC:
    /* 5AC 800F9DAC FF00043C */  lui        $a0, (0xFFFFFF >> 16)
    /* 5B0 800F9DB0 FFFF8434 */  ori        $a0, $a0, (0xFFFFFF & 0xFFFF)
    /* 5B4 800F9DB4 0000438D */  lw         $v1, %lo(D_80000000)($t2)
    /* 5B8 800F9DB8 0080023C */  lui        $v0, %hi(D_80000000)
    /* 5BC 800F9DBC 24186400 */  and        $v1, $v1, $a0
    /* 5C0 800F9DC0 25506200 */  or         $t2, $v1, $v0
    /* 5C4 800F9DC4 0000428D */  lw         $v0, %lo(D_80000000)($t2)
    /* 5C8 800F9DC8 00000000 */  nop
    /* 5CC 800F9DCC 24104400 */  and        $v0, $v0, $a0
    /* 5D0 800F9DD0 A2FF4414 */  bne        $v0, $a0, .L800F9C5C
    /* 5D4 800F9DD4 00000000 */   nop
    /* 5D8 800F9DD8 000079AD */  sw         $t9, 0x0($t3)
    /* 5DC 800F9DDC 0000B08F */  lw         $s0, 0x0($sp)
    /* 5E0 800F9DE0 0800E003 */  jr         $ra
    /* 5E4 800F9DE4 0800BD27 */   addiu     $sp, $sp, 0x8
endlabel func_800F9BD8
