/* Handwritten function */
nonmatching func_800C0B50, 0x228

glabel func_800C0B50
    /* 58350 800C0B50 B8FFBD27 */  addiu      $sp, $sp, -0x48
    /* 58354 800C0B54 3C00B7AF */  sw         $s7, 0x3C($sp)
    /* 58358 800C0B58 21B88000 */  addu       $s7, $a0, $zero
    /* 5835C 800C0B5C 4000BEAF */  sw         $fp, 0x40($sp)
    /* 58360 800C0B60 21F0A000 */  addu       $fp, $a1, $zero
    /* 58364 800C0B64 2000B0AF */  sw         $s0, 0x20($sp)
    /* 58368 800C0B68 0F80103C */  lui        $s0, %hi(D_800EB9B8)
    /* 5836C 800C0B6C B8B9028E */  lw         $v0, %lo(D_800EB9B8)($s0)
    /* 58370 800C0B70 0400E426 */  addiu      $a0, $s7, 0x4
    /* 58374 800C0B74 4400BFAF */  sw         $ra, 0x44($sp)
    /* 58378 800C0B78 3800B6AF */  sw         $s6, 0x38($sp)
    /* 5837C 800C0B7C 3400B5AF */  sw         $s5, 0x34($sp)
    /* 58380 800C0B80 3000B4AF */  sw         $s4, 0x30($sp)
    /* 58384 800C0B84 2C00B3AF */  sw         $s3, 0x2C($sp)
    /* 58388 800C0B88 2800B2AF */  sw         $s2, 0x28($sp)
    /* 5838C 800C0B8C 2400B1AF */  sw         $s1, 0x24($sp)
    /* 58390 800C0B90 0200E586 */  lh         $a1, 0x2($s7)
    /* 58394 800C0B94 1702030C */  jal        func_800C085C
    /* 58398 800C0B98 48005624 */   addiu     $s6, $v0, 0x48
    /* 5839C 800C0B9C 801F053C */  lui        $a1, (0x1F800398 >> 16)
    /* 583A0 800C0BA0 9803A534 */  ori        $a1, $a1, (0x1F800398 & 0xFFFF)
    /* 583A4 800C0BA4 B8B9048E */  lw         $a0, %lo(D_800EB9B8)($s0)
    /* 583A8 800C0BA8 21884000 */  addu       $s1, $v0, $zero
    /* 583AC 800C0BAC E303010C */  jal        func_80040F8C
    /* 583B0 800C0BB0 24008424 */   addiu     $a0, $a0, 0x24
    /* 583B4 800C0BB4 B8B9028E */  lw         $v0, %lo(D_800EB9B8)($s0)
    /* 583B8 800C0BB8 801F133C */  lui        $s3, (0x1F800398 >> 16)
    /* 583BC 800C0BBC 2A004484 */  lh         $a0, 0x2A($v0)
    /* 583C0 800C0BC0 98037336 */  ori        $s3, $s3, (0x1F800398 & 0xFFFF)
    /* 583C4 800C0BC4 C903010C */  jal        rcos
    /* 583C8 800C0BC8 80210400 */   sll       $a0, $a0, 6
    /* 583CC 800C0BCC 21904000 */  addu       $s2, $v0, $zero
    /* 583D0 800C0BD0 801F043C */  lui        $a0, (0x1F800398 >> 16)
    /* 583D4 800C0BD4 98038434 */  ori        $a0, $a0, (0x1F800398 & 0xFFFF)
    /* 583D8 800C0BD8 1000A527 */  addiu      $a1, $sp, 0x10
    /* 583DC 800C0BDC 1000B2AF */  sw         $s2, 0x10($sp)
    /* 583E0 800C0BE0 1400B2AF */  sw         $s2, 0x14($sp)
    /* 583E4 800C0BE4 0305010C */  jal        func_8004140C
    /* 583E8 800C0BE8 1800B2AF */   sw        $s2, 0x18($sp)
    /* 583EC 800C0BEC 21202002 */  addu       $a0, $s1, $zero
    /* 583F0 800C0BF0 801F053C */  lui        $a1, (0x1F800398 >> 16)
    /* 583F4 800C0BF4 1A07010C */  jal        func_80041C68
    /* 583F8 800C0BF8 9803A534 */   ori       $a1, $a1, (0x1F800398 & 0xFFFF)
    /* 583FC 800C0BFC AA00030C */  jal        func_800C02A8
    /* 58400 800C0C00 00000000 */   nop
    /* 58404 800C0C04 0400668E */  lw         $a2, 0x4($s3)
    /* 58408 800C0C08 0800758E */  lw         $s5, 0x8($s3)
    /* 5840C 800C0C0C 0C00718E */  lw         $s1, 0xC($s3)
    /* 58410 800C0C10 1000748E */  lw         $s4, 0x10($s3)
    /* 58414 800C0C14 0000688E */  lw         $t0, 0x0($s3)
    /* 58418 800C0C18 00000000 */  nop
    /* 5841C 800C0C1C 0040C848 */  ctc2       $t0, $8 /* handwritten instruction */
    /* 58420 800C0C20 0048C648 */  ctc2       $a2, $9 /* handwritten instruction */
    /* 58424 800C0C24 0050D548 */  ctc2       $s5, $10 /* handwritten instruction */
    /* 58428 800C0C28 0058D148 */  ctc2       $s1, $11 /* handwritten instruction */
    /* 5842C 800C0C2C 0060D448 */  ctc2       $s4, $12 /* handwritten instruction */
    /* 58430 800C0C30 0800F286 */  lh         $s2, 0x8($s7)
    /* 58434 800C0C34 0A00E686 */  lh         $a2, 0xA($s7)
    /* 58438 800C0C38 0C00F586 */  lh         $s5, 0xC($s7)
    /* 5843C 800C0C3C 0068D248 */  ctc2       $s2, $13 /* handwritten instruction */
    /* 58440 800C0C40 0070C648 */  ctc2       $a2, $14 /* handwritten instruction */
    /* 58444 800C0C44 0078D548 */  ctc2       $s5, $15 /* handwritten instruction */
    /* 58448 800C0C48 0044023C */  lui        $v0, (0x44000000 >> 16)
    /* 5844C 800C0C4C 25F0C203 */  or         $fp, $fp, $v0
    /* 58450 800C0C50 0400E492 */  lbu        $a0, 0x4($s7)
    /* 58454 800C0C54 0600E292 */  lbu        $v0, 0x6($s7)
    /* 58458 800C0C58 B8B9038E */  lw         $v1, %lo(D_800EB9B8)($s0)
    /* 5845C 800C0C5C 2B104400 */  sltu       $v0, $v0, $a0
    /* 58460 800C0C60 32007194 */  lhu        $s1, 0x32($v1)
    /* 58464 800C0C64 02004014 */  bnez       $v0, .L800C0C70
    /* 58468 800C0C68 21A08000 */   addu      $s4, $a0, $zero
    /* 5846C 800C0C6C 0600F492 */  lbu        $s4, 0x6($s7)
  .L800C0C70:
    /* 58470 800C0C70 0F80023C */  lui        $v0, %hi(D_800EB9B8)
    /* 58474 800C0C74 B8B9428C */  lw         $v0, %lo(D_800EB9B8)($v0)
    /* 58478 800C0C78 00000000 */  nop
    /* 5847C 800C0C7C 20004284 */  lh         $v0, 0x20($v0)
    /* 58480 800C0C80 00000000 */  nop
    /* 58484 800C0C84 40800200 */  sll        $s0, $v0, 1
  .L800C0C88:
    /* 58488 800C0C88 0000C0CA */  lwc2       $0, 0x0($s6)
    /* 5848C 800C0C8C 0400C1CA */  lwc2       $1, 0x4($s6)
    /* 58490 800C0C90 2D002012 */  beqz       $s1, .L800C0D48
    /* 58494 800C0C94 FFFF3126 */   addiu     $s1, $s1, -0x1
    /* 58498 800C0C98 12204A4A */  mvmva      1, 1, 0, 1, 0
    /* 5849C 800C0C9C 00481248 */  mfc2       $s2, $9 /* handwritten instruction */
    /* 584A0 800C0CA0 00500648 */  mfc2       $a2, $10 /* handwritten instruction */
    /* 584A4 800C0CA4 00581548 */  mfc2       $s5, $11 /* handwritten instruction */
    /* 584A8 800C0CA8 FFFF4232 */  andi       $v0, $s2, 0xFFFF
    /* 584AC 800C0CAC 001C0600 */  sll        $v1, $a2, 16
    /* 584B0 800C0CB0 25904300 */  or         $s2, $v0, $v1
    /* 584B4 800C0CB4 00009248 */  mtc2       $s2, $0 /* handwritten instruction */
    /* 584B8 800C0CB8 00089548 */  mtc2       $s5, $1 /* handwritten instruction */
    /* 584BC 800C0CBC 0600C686 */  lh         $a2, 0x6($s6)
    /* 584C0 800C0CC0 0800D626 */  addiu      $s6, $s6, 0x8
    /* 584C4 800C0CC4 0100184A */  rtps
    /* 584C8 800C0CC8 00006EEA */  swc2       $14, 0x0($s3)
    /* 584CC 800C0CCC 04006226 */  addiu      $v0, $s3, 0x4
    /* 584D0 800C0CD0 00980C48 */  mfc2       $t4, $19 /* handwritten instruction */
    /* 584D4 800C0CD4 00000000 */  nop
    /* 584D8 800C0CD8 83600C00 */  sra        $t4, $t4, 2
    /* 584DC 800C0CDC 00004CAC */  sw         $t4, 0x0($v0)
    /* 584E0 800C0CE0 0F00C010 */  beqz       $a2, .L800C0D20
    /* 584E4 800C0CE4 21206002 */   addu      $a0, $s3, $zero
    /* 584E8 800C0CE8 04006796 */  lhu        $a3, 0x4($s3)
    /* 584EC 800C0CEC 0C006286 */  lh         $v0, 0xC($s3)
    /* 584F0 800C0CF0 003C0700 */  sll        $a3, $a3, 16
    /* 584F4 800C0CF4 033C0700 */  sra        $a3, $a3, 16
    /* 584F8 800C0CF8 2138E200 */  addu       $a3, $a3, $v0
    /* 584FC 800C0CFC 2338F000 */  subu       $a3, $a3, $s0
    /* 58500 800C0D00 1A00F400 */  div        $zero, $a3, $s4
    /* 58504 800C0D04 12380000 */  mflo       $a3
    /* 58508 800C0D08 08006526 */  addiu      $a1, $s3, 0x8
    /* 5850C 800C0D0C 40360600 */  sll        $a2, $a2, 25
    /* 58510 800C0D10 2330C603 */  subu       $a2, $fp, $a2
    /* 58514 800C0D14 20000224 */  addiu      $v0, $zero, 0x20
    /* 58518 800C0D18 6402030C */  jal        func_800C0990
    /* 5851C 800C0D1C 23384700 */   subu      $a3, $v0, $a3
  .L800C0D20:
    /* 58520 800C0D20 21300000 */  addu       $a2, $zero, $zero
    /* 58524 800C0D24 21186002 */  addu       $v1, $s3, $zero
  .L800C0D28:
    /* 58528 800C0D28 00006294 */  lhu        $v0, 0x0($v1)
    /* 5852C 800C0D2C 0100C624 */  addiu      $a2, $a2, 0x1
    /* 58530 800C0D30 080062A4 */  sh         $v0, 0x8($v1)
    /* 58534 800C0D34 0300C228 */  slti       $v0, $a2, 0x3
    /* 58538 800C0D38 FBFF4014 */  bnez       $v0, .L800C0D28
    /* 5853C 800C0D3C 02006324 */   addiu     $v1, $v1, 0x2
    /* 58540 800C0D40 22030308 */  j          .L800C0C88
    /* 58544 800C0D44 00000000 */   nop
  .L800C0D48:
    /* 58548 800C0D48 4400BF8F */  lw         $ra, 0x44($sp)
    /* 5854C 800C0D4C 4000BE8F */  lw         $fp, 0x40($sp)
    /* 58550 800C0D50 3C00B78F */  lw         $s7, 0x3C($sp)
    /* 58554 800C0D54 3800B68F */  lw         $s6, 0x38($sp)
    /* 58558 800C0D58 3400B58F */  lw         $s5, 0x34($sp)
    /* 5855C 800C0D5C 3000B48F */  lw         $s4, 0x30($sp)
    /* 58560 800C0D60 2C00B38F */  lw         $s3, 0x2C($sp)
    /* 58564 800C0D64 2800B28F */  lw         $s2, 0x28($sp)
    /* 58568 800C0D68 2400B18F */  lw         $s1, 0x24($sp)
    /* 5856C 800C0D6C 2000B08F */  lw         $s0, 0x20($sp)
    /* 58570 800C0D70 0800E003 */  jr         $ra
    /* 58574 800C0D74 4800BD27 */   addiu     $sp, $sp, 0x48
endlabel func_800C0B50
