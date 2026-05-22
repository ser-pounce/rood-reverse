nonmatching func_8002A3E8, 0x2B0

glabel func_8002A3E8
    /* 1ABE8 8002A3E8 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 1ABEC 8002A3EC 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 1ABF0 8002A3F0 21988000 */  addu       $s3, $a0, $zero
    /* 1ABF4 8002A3F4 1000B0AF */  sw         $s0, 0x10($sp)
    /* 1ABF8 8002A3F8 2180A000 */  addu       $s0, $a1, $zero
    /* 1ABFC 8002A3FC 1400B1AF */  sw         $s1, 0x14($sp)
    /* 1AC00 8002A400 2188C000 */  addu       $s1, $a2, $zero
    /* 1AC04 8002A404 1800B2AF */  sw         $s2, 0x18($sp)
    /* 1AC08 8002A408 2000BFAF */  sw         $ra, 0x20($sp)
    /* 1AC0C 8002A40C E1AA000C */  jal        func_8002AB84
    /* 1AC10 8002A410 2190E000 */   addu      $s2, $a3, $zero
    /* 1AC14 8002A414 0DA90008 */  j          .L8002A434
    /* 1AC18 8002A418 00000000 */   nop
  .L8002A41C:
    /* 1AC1C 8002A41C EEAA000C */  jal        func_8002ABB8
    /* 1AC20 8002A420 00000000 */   nop
    /* 1AC24 8002A424 95004014 */  bnez       $v0, .L8002A67C
    /* 1AC28 8002A428 FFFF0224 */   addiu     $v0, $zero, -0x1
    /* 1AC2C 8002A42C A6A9000C */  jal        func_8002A698
    /* 1AC30 8002A430 00000000 */   nop
  .L8002A434:
    /* 1AC34 8002A434 0380023C */  lui        $v0, %hi(D_8003356C)
    /* 1AC38 8002A438 6C35428C */  lw         $v0, %lo(D_8003356C)($v0)
    /* 1AC3C 8002A43C 0380033C */  lui        $v1, %hi(D_80033570)
    /* 1AC40 8002A440 7035638C */  lw         $v1, %lo(D_80033570)($v1)
    /* 1AC44 8002A444 01004224 */  addiu      $v0, $v0, 0x1
    /* 1AC48 8002A448 3F004230 */  andi       $v0, $v0, 0x3F
    /* 1AC4C 8002A44C F3FF4310 */  beq        $v0, $v1, .L8002A41C
    /* 1AC50 8002A450 00000000 */   nop
    /* 1AC54 8002A454 947E000C */  jal        SetIntrMask
    /* 1AC58 8002A458 21200000 */   addu      $a0, $zero, $zero
    /* 1AC5C 8002A45C 0380043C */  lui        $a0, %hi(D_80033444)
    /* 1AC60 8002A460 44348424 */  addiu      $a0, $a0, %lo(D_80033444)
    /* 1AC64 8002A464 0380013C */  lui        $at, %hi(D_80033574)
    /* 1AC68 8002A468 743522AC */  sw         $v0, %lo(D_80033574)($at)
    /* 1AC6C 8002A46C 01008390 */  lbu        $v1, 0x1($a0)
    /* 1AC70 8002A470 01000224 */  addiu      $v0, $zero, 0x1
    /* 1AC74 8002A474 14006010 */  beqz       $v1, .L8002A4C8
    /* 1AC78 8002A478 080082AC */   sw        $v0, 0x8($a0)
    /* 1AC7C 8002A47C 0380033C */  lui        $v1, %hi(D_8003356C)
    /* 1AC80 8002A480 6C35638C */  lw         $v1, %lo(D_8003356C)($v1)
    /* 1AC84 8002A484 0380023C */  lui        $v0, %hi(D_80033570)
    /* 1AC88 8002A488 7035428C */  lw         $v0, %lo(D_80033570)($v0)
    /* 1AC8C 8002A48C 00000000 */  nop
    /* 1AC90 8002A490 1E006214 */  bne        $v1, $v0, .L8002A50C
    /* 1AC94 8002A494 00000000 */   nop
    /* 1AC98 8002A498 0380023C */  lui        $v0, %hi(D_80033558)
    /* 1AC9C 8002A49C 5835428C */  lw         $v0, %lo(D_80033558)($v0)
    /* 1ACA0 8002A4A0 00000000 */  nop
    /* 1ACA4 8002A4A4 0000428C */  lw         $v0, 0x0($v0)
    /* 1ACA8 8002A4A8 0001033C */  lui        $v1, (0x1000000 >> 16)
    /* 1ACAC 8002A4AC 24104300 */  and        $v0, $v0, $v1
    /* 1ACB0 8002A4B0 16004014 */  bnez       $v0, .L8002A50C
    /* 1ACB4 8002A4B4 00000000 */   nop
    /* 1ACB8 8002A4B8 0C00828C */  lw         $v0, 0xC($a0)
    /* 1ACBC 8002A4BC 00000000 */  nop
    /* 1ACC0 8002A4C0 12004014 */  bnez       $v0, .L8002A50C
    /* 1ACC4 8002A4C4 00000000 */   nop
  .L8002A4C8:
    /* 1ACC8 8002A4C8 0380033C */  lui        $v1, %hi(D_8003354C)
    /* 1ACCC 8002A4CC 4C35638C */  lw         $v1, %lo(D_8003354C)($v1)
    /* 1ACD0 8002A4D0 0004043C */  lui        $a0, (0x4000000 >> 16)
  .L8002A4D4:
    /* 1ACD4 8002A4D4 0000628C */  lw         $v0, 0x0($v1)
    /* 1ACD8 8002A4D8 00000000 */  nop
    /* 1ACDC 8002A4DC 24104400 */  and        $v0, $v0, $a0
    /* 1ACE0 8002A4E0 FCFF4010 */  beqz       $v0, .L8002A4D4
    /* 1ACE4 8002A4E4 00000000 */   nop
    /* 1ACE8 8002A4E8 21200002 */  addu       $a0, $s0, $zero
    /* 1ACEC 8002A4EC 09F86002 */  jalr       $s3
    /* 1ACF0 8002A4F0 21284002 */   addu      $a1, $s2, $zero
    /* 1ACF4 8002A4F4 0380043C */  lui        $a0, %hi(D_80033574)
    /* 1ACF8 8002A4F8 7435848C */  lw         $a0, %lo(D_80033574)($a0)
    /* 1ACFC 8002A4FC 947E000C */  jal        SetIntrMask
    /* 1AD00 8002A500 00000000 */   nop
    /* 1AD04 8002A504 9FA90008 */  j          .L8002A67C
    /* 1AD08 8002A508 21100000 */   addu      $v0, $zero, $zero
  .L8002A50C:
    /* 1AD0C 8002A50C 0380053C */  lui        $a1, %hi(func_8002A698)
    /* 1AD10 8002A510 98A6A524 */  addiu      $a1, $a1, %lo(func_8002A698)
    /* 1AD14 8002A514 4D7E000C */  jal        DMACallback
    /* 1AD18 8002A518 02000424 */   addiu     $a0, $zero, 0x2
    /* 1AD1C 8002A51C 2A002012 */  beqz       $s1, .L8002A5C8
    /* 1AD20 8002A520 21300000 */   addu      $a2, $zero, $zero
    /* 1AD24 8002A524 0480083C */  lui        $t0, %hi(D_8003E40C)
    /* 1AD28 8002A528 0CE40825 */  addiu      $t0, $t0, %lo(D_8003E40C)
    /* 1AD2C 8002A52C 21380002 */  addu       $a3, $s0, $zero
    /* 1AD30 8002A530 21102002 */  addu       $v0, $s1, $zero
  .L8002A534:
    /* 1AD34 8002A534 02004104 */  bgez       $v0, .L8002A540
    /* 1AD38 8002A538 00000000 */   nop
    /* 1AD3C 8002A53C 03004224 */  addiu      $v0, $v0, 0x3
  .L8002A540:
    /* 1AD40 8002A540 83100200 */  sra        $v0, $v0, 2
    /* 1AD44 8002A544 2A10C200 */  slt        $v0, $a2, $v0
    /* 1AD48 8002A548 0E004010 */  beqz       $v0, .L8002A584
    /* 1AD4C 8002A54C 80200600 */   sll       $a0, $a2, 2
    /* 1AD50 8002A550 0000E58C */  lw         $a1, 0x0($a3)
    /* 1AD54 8002A554 0400E724 */  addiu      $a3, $a3, 0x4
    /* 1AD58 8002A558 0380033C */  lui        $v1, %hi(D_8003356C)
    /* 1AD5C 8002A55C 6C35638C */  lw         $v1, %lo(D_8003356C)($v1)
    /* 1AD60 8002A560 0100C624 */  addiu      $a2, $a2, 0x1
    /* 1AD64 8002A564 40100300 */  sll        $v0, $v1, 1
    /* 1AD68 8002A568 21104300 */  addu       $v0, $v0, $v1
    /* 1AD6C 8002A56C 40110200 */  sll        $v0, $v0, 5
    /* 1AD70 8002A570 21104800 */  addu       $v0, $v0, $t0
    /* 1AD74 8002A574 21208200 */  addu       $a0, $a0, $v0
    /* 1AD78 8002A578 000085AC */  sw         $a1, 0x0($a0)
    /* 1AD7C 8002A57C 4DA90008 */  j          .L8002A534
    /* 1AD80 8002A580 21102002 */   addu      $v0, $s1, $zero
  .L8002A584:
    /* 1AD84 8002A584 0380023C */  lui        $v0, %hi(D_8003356C)
    /* 1AD88 8002A588 6C35428C */  lw         $v0, %lo(D_8003356C)($v0)
    /* 1AD8C 8002A58C 0380033C */  lui        $v1, %hi(D_8003356C)
    /* 1AD90 8002A590 6C35638C */  lw         $v1, %lo(D_8003356C)($v1)
    /* 1AD94 8002A594 40200200 */  sll        $a0, $v0, 1
    /* 1AD98 8002A598 21208200 */  addu       $a0, $a0, $v0
    /* 1AD9C 8002A59C 40210400 */  sll        $a0, $a0, 5
    /* 1ADA0 8002A5A0 40100300 */  sll        $v0, $v1, 1
    /* 1ADA4 8002A5A4 21104300 */  addu       $v0, $v0, $v1
    /* 1ADA8 8002A5A8 40110200 */  sll        $v0, $v0, 5
    /* 1ADAC 8002A5AC 0480033C */  lui        $v1, %hi(D_8003E40C)
    /* 1ADB0 8002A5B0 0CE46324 */  addiu      $v1, $v1, %lo(D_8003E40C)
    /* 1ADB4 8002A5B4 21104300 */  addu       $v0, $v0, $v1
    /* 1ADB8 8002A5B8 0480013C */  lui        $at, %hi(D_8003E404)
    /* 1ADBC 8002A5BC 21082400 */  addu       $at, $at, $a0
    /* 1ADC0 8002A5C0 7BA90008 */  j          .L8002A5EC
    /* 1ADC4 8002A5C4 04E422AC */   sw        $v0, %lo(D_8003E404)($at)
  .L8002A5C8:
    /* 1ADC8 8002A5C8 0380033C */  lui        $v1, %hi(D_8003356C)
    /* 1ADCC 8002A5CC 6C35638C */  lw         $v1, %lo(D_8003356C)($v1)
    /* 1ADD0 8002A5D0 00000000 */  nop
    /* 1ADD4 8002A5D4 40100300 */  sll        $v0, $v1, 1
    /* 1ADD8 8002A5D8 21104300 */  addu       $v0, $v0, $v1
    /* 1ADDC 8002A5DC 40110200 */  sll        $v0, $v0, 5
    /* 1ADE0 8002A5E0 0480013C */  lui        $at, %hi(D_8003E404)
    /* 1ADE4 8002A5E4 21082200 */  addu       $at, $at, $v0
    /* 1ADE8 8002A5E8 04E430AC */  sw         $s0, %lo(D_8003E404)($at)
  .L8002A5EC:
    /* 1ADEC 8002A5EC 0380033C */  lui        $v1, %hi(D_8003356C)
    /* 1ADF0 8002A5F0 6C35638C */  lw         $v1, %lo(D_8003356C)($v1)
    /* 1ADF4 8002A5F4 00000000 */  nop
    /* 1ADF8 8002A5F8 40100300 */  sll        $v0, $v1, 1
    /* 1ADFC 8002A5FC 21104300 */  addu       $v0, $v0, $v1
    /* 1AE00 8002A600 40110200 */  sll        $v0, $v0, 5
    /* 1AE04 8002A604 0480013C */  lui        $at, %hi(D_8003E408)
    /* 1AE08 8002A608 21082200 */  addu       $at, $at, $v0
    /* 1AE0C 8002A60C 08E432AC */  sw         $s2, %lo(D_8003E408)($at)
    /* 1AE10 8002A610 0380033C */  lui        $v1, %hi(D_8003356C)
    /* 1AE14 8002A614 6C35638C */  lw         $v1, %lo(D_8003356C)($v1)
    /* 1AE18 8002A618 00000000 */  nop
    /* 1AE1C 8002A61C 40100300 */  sll        $v0, $v1, 1
    /* 1AE20 8002A620 21104300 */  addu       $v0, $v0, $v1
    /* 1AE24 8002A624 40110200 */  sll        $v0, $v0, 5
    /* 1AE28 8002A628 0480013C */  lui        $at, %hi(D_8003E400)
    /* 1AE2C 8002A62C 21082200 */  addu       $at, $at, $v0
    /* 1AE30 8002A630 00E433AC */  sw         $s3, %lo(D_8003E400)($at)
    /* 1AE34 8002A634 0380023C */  lui        $v0, %hi(D_8003356C)
    /* 1AE38 8002A638 6C35428C */  lw         $v0, %lo(D_8003356C)($v0)
    /* 1AE3C 8002A63C 0380043C */  lui        $a0, %hi(D_80033574)
    /* 1AE40 8002A640 7435848C */  lw         $a0, %lo(D_80033574)($a0)
    /* 1AE44 8002A644 01004224 */  addiu      $v0, $v0, 0x1
    /* 1AE48 8002A648 3F004230 */  andi       $v0, $v0, 0x3F
    /* 1AE4C 8002A64C 0380013C */  lui        $at, %hi(D_8003356C)
    /* 1AE50 8002A650 947E000C */  jal        SetIntrMask
    /* 1AE54 8002A654 6C3522AC */   sw        $v0, %lo(D_8003356C)($at)
    /* 1AE58 8002A658 A6A9000C */  jal        func_8002A698
    /* 1AE5C 8002A65C 00000000 */   nop
    /* 1AE60 8002A660 0380023C */  lui        $v0, %hi(D_8003356C)
    /* 1AE64 8002A664 6C35428C */  lw         $v0, %lo(D_8003356C)($v0)
    /* 1AE68 8002A668 0380033C */  lui        $v1, %hi(D_80033570)
    /* 1AE6C 8002A66C 7035638C */  lw         $v1, %lo(D_80033570)($v1)
    /* 1AE70 8002A670 00000000 */  nop
    /* 1AE74 8002A674 23104300 */  subu       $v0, $v0, $v1
    /* 1AE78 8002A678 3F004230 */  andi       $v0, $v0, 0x3F
  .L8002A67C:
    /* 1AE7C 8002A67C 2000BF8F */  lw         $ra, 0x20($sp)
    /* 1AE80 8002A680 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 1AE84 8002A684 1800B28F */  lw         $s2, 0x18($sp)
    /* 1AE88 8002A688 1400B18F */  lw         $s1, 0x14($sp)
    /* 1AE8C 8002A68C 1000B08F */  lw         $s0, 0x10($sp)
    /* 1AE90 8002A690 0800E003 */  jr         $ra
    /* 1AE94 8002A694 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_8002A3E8
