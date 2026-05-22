nonmatching func_800CD3E4, 0x8D8

glabel func_800CD3E4
    /* 64BE4 800CD3E4 A0FFBD27 */  addiu      $sp, $sp, -0x60
    /* 64BE8 800CD3E8 5400B7AF */  sw         $s7, 0x54($sp)
    /* 64BEC 800CD3EC 801F173C */  lui        $s7, (0x1F800088 >> 16)
    /* 64BF0 800CD3F0 8800F736 */  ori        $s7, $s7, (0x1F800088 & 0xFFFF)
    /* 64BF4 800CD3F4 40180400 */  sll        $v1, $a0, 1
    /* 64BF8 800CD3F8 21186400 */  addu       $v1, $v1, $a0
    /* 64BFC 800CD3FC 00190300 */  sll        $v1, $v1, 4
    /* 64C00 800CD400 0F80023C */  lui        $v0, %hi(vs_battle_textBoxes)
    /* 64C04 800CD404 E04F4224 */  addiu      $v0, $v0, %lo(vs_battle_textBoxes)
    /* 64C08 800CD408 21186200 */  addu       $v1, $v1, $v0
    /* 64C0C 800CD40C 5C00BFAF */  sw         $ra, 0x5C($sp)
    /* 64C10 800CD410 5800BEAF */  sw         $fp, 0x58($sp)
    /* 64C14 800CD414 5000B6AF */  sw         $s6, 0x50($sp)
    /* 64C18 800CD418 4C00B5AF */  sw         $s5, 0x4C($sp)
    /* 64C1C 800CD41C 4800B4AF */  sw         $s4, 0x48($sp)
    /* 64C20 800CD420 4400B3AF */  sw         $s3, 0x44($sp)
    /* 64C24 800CD424 4000B2AF */  sw         $s2, 0x40($sp)
    /* 64C28 800CD428 3C00B1AF */  sw         $s1, 0x3C($sp)
    /* 64C2C 800CD42C 3800B0AF */  sw         $s0, 0x38($sp)
    /* 64C30 800CD430 1800A3AF */  sw         $v1, 0x18($sp)
    /* 64C34 800CD434 24007384 */  lh         $s3, 0x24($v1)
    /* 64C38 800CD438 26007284 */  lh         $s2, 0x26($v1)
    /* 64C3C 800CD43C 28006B84 */  lh         $t3, 0x28($v1)
    /* 64C40 800CD440 2A006884 */  lh         $t0, 0x2A($v1)
    /* 64C44 800CD444 1800AF8F */  lw         $t7, 0x18($sp)
    /* 64C48 800CD448 0F80033C */  lui        $v1, %hi(D_800EB588)
    /* 64C4C 800CD44C 0000E58D */  lw         $a1, 0x0($t7)
    /* 64C50 800CD450 88B56324 */  addiu      $v1, $v1, %lo(D_800EB588)
    /* 64C54 800CD454 82110500 */  srl        $v0, $a1, 6
    /* 64C58 800CD458 3C004230 */  andi       $v0, $v0, 0x3C
    /* 64C5C 800CD45C 21104300 */  addu       $v0, $v0, $v1
    /* 64C60 800CD460 0000428C */  lw         $v0, 0x0($v0)
    /* 64C64 800CD464 00210400 */  sll        $a0, $a0, 4
    /* 64C68 800CD468 1C00A2AF */  sw         $v0, 0x1C($sp)
    /* 64C6C 800CD46C 0F80023C */  lui        $v0, %hi(D_800F51B8)
    /* 64C70 800CD470 B851428C */  lw         $v0, %lo(D_800F51B8)($v0)
    /* 64C74 800CD474 1C00AF8F */  lw         $t7, 0x1C($sp)
    /* 64C78 800CD478 21104400 */  addu       $v0, $v0, $a0
    /* 64C7C 800CD47C 0302E011 */  beqz       $t7, .L800CDC8C
    /* 64C80 800CD480 1000A2AF */   sw        $v0, 0x10($sp)
    /* 64C84 800CD484 801F103C */  lui        $s0, (0x1F800088 >> 16)
    /* 64C88 800CD488 88001036 */  ori        $s0, $s0, (0x1F800088 & 0xFFFF)
    /* 64C8C 800CD48C 82610500 */  srl        $t4, $a1, 6
    /* 64C90 800CD490 03008C31 */  andi       $t4, $t4, 0x3
    /* 64C94 800CD494 82120500 */  srl        $v0, $a1, 10
    /* 64C98 800CD498 3C004230 */  andi       $v0, $v0, 0x3C
    /* 64C9C 800CD49C 21104F00 */  addu       $v0, $v0, $t7
    /* 64CA0 800CD4A0 2000AFAF */  sw         $t7, 0x20($sp)
    /* 64CA4 800CD4A4 0100E391 */  lbu        $v1, 0x1($t7)
    /* 64CA8 800CD4A8 0000428C */  lw         $v0, 0x0($v0)
    /* 64CAC 800CD4AC 01006324 */  addiu      $v1, $v1, 0x1
    /* 64CB0 800CD4B0 80180300 */  sll        $v1, $v1, 2
    /* 64CB4 800CD4B4 2118E301 */  addu       $v1, $t7, $v1
    /* 64CB8 800CD4B8 1400A2AF */  sw         $v0, 0x14($sp)
    /* 64CBC 800CD4BC 1C00A3AF */  sw         $v1, 0x1C($sp)
    /* 64CC0 800CD4C0 0200E291 */  lbu        $v0, 0x2($t7)
    /* 64CC4 800CD4C4 0000EF8D */  lw         $t7, 0x0($t7)
    /* 64CC8 800CD4C8 21B00000 */  addu       $s6, $zero, $zero
    /* 64CCC 800CD4CC 1F004010 */  beqz       $v0, .L800CD54C
    /* 64CD0 800CD4D0 2400AFAF */   sw        $t7, 0x24($sp)
    /* 64CD4 800CD4D4 21A84000 */  addu       $s5, $v0, $zero
    /* 64CD8 800CD4D8 21A06000 */  addu       $s4, $v1, $zero
  .L800CD4DC:
    /* 64CDC 800CD4DC 00008496 */  lhu        $a0, 0x0($s4)
    /* 64CE0 800CD4E0 21288001 */  addu       $a1, $t4, $zero
    /* 64CE4 800CD4E4 2800A8AF */  sw         $t0, 0x28($sp)
    /* 64CE8 800CD4E8 2C00ABAF */  sw         $t3, 0x2C($sp)
    /* 64CEC 800CD4EC E834030C */  jal        func_800CD3A0
    /* 64CF0 800CD4F0 3000ACAF */   sw        $t4, 0x30($sp)
    /* 64CF4 800CD4F4 21884000 */  addu       $s1, $v0, $zero
    /* 64CF8 800CD4F8 2C00AB8F */  lw         $t3, 0x2C($sp)
    /* 64CFC 800CD4FC FF002232 */  andi       $v0, $s1, 0xFF
    /* 64D00 800CD500 18004B00 */  mult       $v0, $t3
    /* 64D04 800CD504 12480000 */  mflo       $t1
    /* 64D08 800CD508 2800A88F */  lw         $t0, 0x28($sp)
    /* 64D0C 800CD50C 03121100 */  sra        $v0, $s1, 8
    /* 64D10 800CD510 18004800 */  mult       $v0, $t0
    /* 64D14 800CD514 02009426 */  addiu      $s4, $s4, 0x2
    /* 64D18 800CD518 0100D626 */  addiu      $s6, $s6, 0x1
    /* 64D1C 800CD51C 03120900 */  sra        $v0, $t1, 8
    /* 64D20 800CD520 21106202 */  addu       $v0, $s3, $v0
    /* 64D24 800CD524 000002A6 */  sh         $v0, 0x0($s0)
    /* 64D28 800CD528 02001026 */  addiu      $s0, $s0, 0x2
    /* 64D2C 800CD52C 12180000 */  mflo       $v1
    /* 64D30 800CD530 03120300 */  sra        $v0, $v1, 8
    /* 64D34 800CD534 21104202 */  addu       $v0, $s2, $v0
    /* 64D38 800CD538 000002A6 */  sh         $v0, 0x0($s0)
    /* 64D3C 800CD53C 2A10D502 */  slt        $v0, $s6, $s5
    /* 64D40 800CD540 3000AC8F */  lw         $t4, 0x30($sp)
    /* 64D44 800CD544 E5FF4014 */  bnez       $v0, .L800CD4DC
    /* 64D48 800CD548 02001026 */   addiu     $s0, $s0, 0x2
  .L800CD54C:
    /* 64D4C 800CD54C 1800AF8F */  lw         $t7, 0x18($sp)
    /* 64D50 800CD550 00000000 */  nop
    /* 64D54 800CD554 0000E28D */  lw         $v0, 0x0($t7)
    /* 64D58 800CD558 2400AF8F */  lw         $t7, 0x24($sp)
    /* 64D5C 800CD55C 02130200 */  srl        $v0, $v0, 12
    /* 64D60 800CD560 0F004230 */  andi       $v0, $v0, 0xF
    /* 64D64 800CD564 FFFF4224 */  addiu      $v0, $v0, -0x1
    /* 64D68 800CD568 031A0F00 */  sra        $v1, $t7, 8
    /* 64D6C 800CD56C FF006330 */  andi       $v1, $v1, 0xFF
    /* 64D70 800CD570 2B104300 */  sltu       $v0, $v0, $v1
    /* 64D74 800CD574 43004010 */  beqz       $v0, .L800CD684
    /* 64D78 800CD578 21288001 */   addu      $a1, $t4, $zero
    /* 64D7C 800CD57C 1400AF8F */  lw         $t7, 0x14($sp)
    /* 64D80 800CD580 00000000 */  nop
    /* 64D84 800CD584 FF00E231 */  andi       $v0, $t7, 0xFF
    /* 64D88 800CD588 1C00AF8F */  lw         $t7, 0x1C($sp)
    /* 64D8C 800CD58C 40100200 */  sll        $v0, $v0, 1
    /* 64D90 800CD590 21104F00 */  addu       $v0, $v0, $t7
    /* 64D94 800CD594 00004494 */  lhu        $a0, 0x0($v0)
    /* 64D98 800CD598 2800A8AF */  sw         $t0, 0x28($sp)
    /* 64D9C 800CD59C 2C00ABAF */  sw         $t3, 0x2C($sp)
    /* 64DA0 800CD5A0 E834030C */  jal        func_800CD3A0
    /* 64DA4 800CD5A4 3000ACAF */   sw        $t4, 0x30($sp)
    /* 64DA8 800CD5A8 21884000 */  addu       $s1, $v0, $zero
    /* 64DAC 800CD5AC 2400AF8F */  lw         $t7, 0x24($sp)
    /* 64DB0 800CD5B0 2800A88F */  lw         $t0, 0x28($sp)
    /* 64DB4 800CD5B4 2C00AB8F */  lw         $t3, 0x2C($sp)
    /* 64DB8 800CD5B8 3000AC8F */  lw         $t4, 0x30($sp)
    /* 64DBC 800CD5BC FF00E231 */  andi       $v0, $t7, 0xFF
    /* 64DC0 800CD5C0 2A10C202 */  slt        $v0, $s6, $v0
    /* 64DC4 800CD5C4 32004010 */  beqz       $v0, .L800CD690
    /* 64DC8 800CD5C8 40101600 */   sll       $v0, $s6, 1
    /* 64DCC 800CD5CC 1C00AF8F */  lw         $t7, 0x1C($sp)
    /* 64DD0 800CD5D0 00000000 */  nop
    /* 64DD4 800CD5D4 21F04F00 */  addu       $fp, $v0, $t7
  .L800CD5D8:
    /* 64DD8 800CD5D8 0000C497 */  lhu        $a0, 0x0($fp)
    /* 64DDC 800CD5DC 21288001 */  addu       $a1, $t4, $zero
    /* 64DE0 800CD5E0 2800A8AF */  sw         $t0, 0x28($sp)
    /* 64DE4 800CD5E4 2C00ABAF */  sw         $t3, 0x2C($sp)
    /* 64DE8 800CD5E8 E834030C */  jal        func_800CD3A0
    /* 64DEC 800CD5EC 3000ACAF */   sw        $t4, 0x30($sp)
    /* 64DF0 800CD5F0 21A84000 */  addu       $s5, $v0, $zero
    /* 64DF4 800CD5F4 03A21500 */  sra        $s4, $s5, 8
    /* 64DF8 800CD5F8 FF00B532 */  andi       $s5, $s5, 0xFF
    /* 64DFC 800CD5FC 8000A22A */  slti       $v0, $s5, 0x80
    /* 64E00 800CD600 2800A88F */  lw         $t0, 0x28($sp)
    /* 64E04 800CD604 2C00AB8F */  lw         $t3, 0x2C($sp)
    /* 64E08 800CD608 3000AC8F */  lw         $t4, 0x30($sp)
    /* 64E0C 800CD60C 02004014 */  bnez       $v0, .L800CD618
    /* 64E10 800CD610 8000822A */   slti      $v0, $s4, 0x80
    /* 64E14 800CD614 00FFB526 */  addiu      $s5, $s5, -0x100
  .L800CD618:
    /* 64E18 800CD618 02004014 */  bnez       $v0, .L800CD624
    /* 64E1C 800CD61C FF002232 */   andi      $v0, $s1, 0xFF
    /* 64E20 800CD620 00FF9426 */  addiu      $s4, $s4, -0x100
  .L800CD624:
    /* 64E24 800CD624 2110A202 */  addu       $v0, $s5, $v0
    /* 64E28 800CD628 18004B00 */  mult       $v0, $t3
    /* 64E2C 800CD62C 12480000 */  mflo       $t1
    /* 64E30 800CD630 03121100 */  sra        $v0, $s1, 8
    /* 64E34 800CD634 21108202 */  addu       $v0, $s4, $v0
    /* 64E38 800CD638 18004800 */  mult       $v0, $t0
    /* 64E3C 800CD63C 0200DE27 */  addiu      $fp, $fp, 0x2
    /* 64E40 800CD640 0100D626 */  addiu      $s6, $s6, 0x1
    /* 64E44 800CD644 03120900 */  sra        $v0, $t1, 8
    /* 64E48 800CD648 21106202 */  addu       $v0, $s3, $v0
    /* 64E4C 800CD64C 000002A6 */  sh         $v0, 0x0($s0)
    /* 64E50 800CD650 02001026 */  addiu      $s0, $s0, 0x2
    /* 64E54 800CD654 12180000 */  mflo       $v1
    /* 64E58 800CD658 03120300 */  sra        $v0, $v1, 8
    /* 64E5C 800CD65C 21104202 */  addu       $v0, $s2, $v0
    /* 64E60 800CD660 000002A6 */  sh         $v0, 0x0($s0)
    /* 64E64 800CD664 2400AF8F */  lw         $t7, 0x24($sp)
    /* 64E68 800CD668 00000000 */  nop
    /* 64E6C 800CD66C FF00E231 */  andi       $v0, $t7, 0xFF
    /* 64E70 800CD670 2A10C202 */  slt        $v0, $s6, $v0
    /* 64E74 800CD674 D8FF4014 */  bnez       $v0, .L800CD5D8
    /* 64E78 800CD678 02001026 */   addiu     $s0, $s0, 0x2
    /* 64E7C 800CD67C A6350308 */  j          .L800CD698
    /* 64E80 800CD680 FF00E231 */   andi      $v0, $t7, 0xFF
  .L800CD684:
    /* 64E84 800CD684 FFFF0F34 */  ori        $t7, $zero, 0xFFFF
    /* 64E88 800CD688 1400AFAF */  sw         $t7, 0x14($sp)
    /* 64E8C 800CD68C 2400AF8F */  lw         $t7, 0x24($sp)
  .L800CD690:
    /* 64E90 800CD690 00000000 */  nop
    /* 64E94 800CD694 FF00E231 */  andi       $v0, $t7, 0xFF
  .L800CD698:
    /* 64E98 800CD698 1C00AF8F */  lw         $t7, 0x1C($sp)
    /* 64E9C 800CD69C 40100200 */  sll        $v0, $v0, 1
    /* 64EA0 800CD6A0 2178E201 */  addu       $t7, $t7, $v0
    /* 64EA4 800CD6A4 1C00AFAF */  sw         $t7, 0x1C($sp)
    /* 64EA8 800CD6A8 2400AF8F */  lw         $t7, 0x24($sp)
    /* 64EAC 800CD6AC 00000000 */  nop
    /* 64EB0 800CD6B0 03140F00 */  sra        $v0, $t7, 16
    /* 64EB4 800CD6B4 FF005630 */  andi       $s6, $v0, 0xFF
    /* 64EB8 800CD6B8 5B00C012 */  beqz       $s6, .L800CD828
    /* 64EBC 800CD6BC 21A80000 */   addu      $s5, $zero, $zero
  .L800CD6C0:
    /* 64EC0 800CD6C0 1400AF8F */  lw         $t7, 0x14($sp)
    /* 64EC4 800CD6C4 00000000 */  nop
    /* 64EC8 800CD6C8 FF00E231 */  andi       $v0, $t7, 0xFF
    /* 64ECC 800CD6CC 4500A216 */  bne        $s5, $v0, .L800CD7E4
    /* 64ED0 800CD6D0 0100A326 */   addiu     $v1, $s5, 0x1
    /* 64ED4 800CD6D4 1800AF8F */  lw         $t7, 0x18($sp)
    /* 64ED8 800CD6D8 21880000 */  addu       $s1, $zero, $zero
    /* 64EDC 800CD6DC 0000E28D */  lw         $v0, 0x0($t7)
    /* 64EE0 800CD6E0 00000000 */  nop
    /* 64EE4 800CD6E4 02130200 */  srl        $v0, $v0, 12
    /* 64EE8 800CD6E8 0F004230 */  andi       $v0, $v0, 0xF
    /* 64EEC 800CD6EC 0B004010 */  beqz       $v0, .L800CD71C
    /* 64EF0 800CD6F0 21A02002 */   addu      $s4, $s1, $zero
    /* 64EF4 800CD6F4 21204000 */  addu       $a0, $v0, $zero
    /* 64EF8 800CD6F8 2000A38F */  lw         $v1, 0x20($sp)
  .L800CD6FC:
    /* 64EFC 800CD6FC 00000000 */  nop
    /* 64F00 800CD700 02006290 */  lbu        $v0, 0x2($v1)
    /* 64F04 800CD704 01009426 */  addiu      $s4, $s4, 0x1
    /* 64F08 800CD708 21882202 */  addu       $s1, $s1, $v0
    /* 64F0C 800CD70C 2A108402 */  slt        $v0, $s4, $a0
    /* 64F10 800CD710 FAFF4014 */  bnez       $v0, .L800CD6FC
    /* 64F14 800CD714 04006324 */   addiu     $v1, $v1, 0x4
    /* 64F18 800CD718 1800AF8F */  lw         $t7, 0x18($sp)
  .L800CD71C:
    /* 64F1C 800CD71C 00000000 */  nop
    /* 64F20 800CD720 0000E28D */  lw         $v0, 0x0($t7)
    /* 64F24 800CD724 2000AF8F */  lw         $t7, 0x20($sp)
    /* 64F28 800CD728 82120200 */  srl        $v0, $v0, 10
    /* 64F2C 800CD72C 3C004230 */  andi       $v0, $v0, 0x3C
    /* 64F30 800CD730 21104F00 */  addu       $v0, $v0, $t7
    /* 64F34 800CD734 02004290 */  lbu        $v0, 0x2($v0)
    /* 64F38 800CD738 00000000 */  nop
    /* 64F3C 800CD73C 19004010 */  beqz       $v0, .L800CD7A4
    /* 64F40 800CD740 21A00000 */   addu      $s4, $zero, $zero
  .L800CD744:
    /* 64F44 800CD744 3040053C */  lui        $a1, (0x40303030 >> 16)
    /* 64F48 800CD748 80101500 */  sll        $v0, $s5, 2
    /* 64F4C 800CD74C 21105700 */  addu       $v0, $v0, $s7
    /* 64F50 800CD750 21803402 */  addu       $s0, $s1, $s4
    /* 64F54 800CD754 0000468C */  lw         $a2, 0x0($v0)
    /* 64F58 800CD758 80101000 */  sll        $v0, $s0, 2
    /* 64F5C 800CD75C 21105700 */  addu       $v0, $v0, $s7
    /* 64F60 800CD760 3030A534 */  ori        $a1, $a1, (0x40303030 & 0xFFFF)
    /* 64F64 800CD764 1000AF8F */  lw         $t7, 0x10($sp)
    /* 64F68 800CD768 0000478C */  lw         $a3, 0x0($v0)
    /* 64F6C 800CD76C 2E33030C */  jal        func_800CCCB8
    /* 64F70 800CD770 0800E425 */   addiu     $a0, $t7, 0x8
    /* 64F74 800CD774 1800AF8F */  lw         $t7, 0x18($sp)
    /* 64F78 800CD778 00000000 */  nop
    /* 64F7C 800CD77C 0000E28D */  lw         $v0, 0x0($t7)
    /* 64F80 800CD780 2000AF8F */  lw         $t7, 0x20($sp)
    /* 64F84 800CD784 82120200 */  srl        $v0, $v0, 10
    /* 64F88 800CD788 3C004230 */  andi       $v0, $v0, 0x3C
    /* 64F8C 800CD78C 21104F00 */  addu       $v0, $v0, $t7
    /* 64F90 800CD790 02004290 */  lbu        $v0, 0x2($v0)
    /* 64F94 800CD794 01009426 */  addiu      $s4, $s4, 0x1
    /* 64F98 800CD798 2A108202 */  slt        $v0, $s4, $v0
    /* 64F9C 800CD79C E9FF4014 */  bnez       $v0, .L800CD744
    /* 64FA0 800CD7A0 21A80002 */   addu      $s5, $s0, $zero
  .L800CD7A4:
    /* 64FA4 800CD7A4 2188A002 */  addu       $s1, $s5, $zero
    /* 64FA8 800CD7A8 3040053C */  lui        $a1, (0x40303030 >> 16)
    /* 64FAC 800CD7AC 1400AF8F */  lw         $t7, 0x14($sp)
    /* 64FB0 800CD7B0 3030A534 */  ori        $a1, $a1, (0x40303030 & 0xFFFF)
    /* 64FB4 800CD7B4 02120F00 */  srl        $v0, $t7, 8
    /* 64FB8 800CD7B8 FF005530 */  andi       $s5, $v0, 0xFF
    /* 64FBC 800CD7BC 80101500 */  sll        $v0, $s5, 2
    /* 64FC0 800CD7C0 21105700 */  addu       $v0, $v0, $s7
    /* 64FC4 800CD7C4 0000468C */  lw         $a2, 0x0($v0)
    /* 64FC8 800CD7C8 80101100 */  sll        $v0, $s1, 2
    /* 64FCC 800CD7CC 21105700 */  addu       $v0, $v0, $s7
    /* 64FD0 800CD7D0 1000AF8F */  lw         $t7, 0x10($sp)
    /* 64FD4 800CD7D4 0000478C */  lw         $a3, 0x0($v0)
    /* 64FD8 800CD7D8 2E33030C */  jal        func_800CCCB8
    /* 64FDC 800CD7DC 0800E425 */   addiu     $a0, $t7, 0x8
    /* 64FE0 800CD7E0 0100A326 */  addiu      $v1, $s5, 0x1
  .L800CD7E4:
    /* 64FE4 800CD7E4 1A007600 */  div        $zero, $v1, $s6
    /* 64FE8 800CD7E8 10880000 */  mfhi       $s1
    /* 64FEC 800CD7EC 3040053C */  lui        $a1, (0x40303030 >> 16)
    /* 64FF0 800CD7F0 3030A534 */  ori        $a1, $a1, (0x40303030 & 0xFFFF)
    /* 64FF4 800CD7F4 80101500 */  sll        $v0, $s5, 2
    /* 64FF8 800CD7F8 21105700 */  addu       $v0, $v0, $s7
    /* 64FFC 800CD7FC 21A86000 */  addu       $s5, $v1, $zero
    /* 65000 800CD800 1000AF8F */  lw         $t7, 0x10($sp)
    /* 65004 800CD804 0000468C */  lw         $a2, 0x0($v0)
    /* 65008 800CD808 80101100 */  sll        $v0, $s1, 2
    /* 6500C 800CD80C 21105700 */  addu       $v0, $v0, $s7
    /* 65010 800CD810 0000478C */  lw         $a3, 0x0($v0)
    /* 65014 800CD814 2E33030C */  jal        func_800CCCB8
    /* 65018 800CD818 0800E425 */   addiu     $a0, $t7, 0x8
    /* 6501C 800CD81C 2A10B602 */  slt        $v0, $s5, $s6
    /* 65020 800CD820 A7FF4014 */  bnez       $v0, .L800CD6C0
    /* 65024 800CD824 00000000 */   nop
  .L800CD828:
    /* 65028 800CD828 1000AF8F */  lw         $t7, 0x10($sp)
    /* 6502C 800CD82C 00E2043C */  lui        $a0, (0xE2000000 >> 16)
    /* 65030 800CD830 4033030C */  jal        func_800CCD00
    /* 65034 800CD834 0800E525 */   addiu     $a1, $t7, 0x8
    /* 65038 800CD838 21A80000 */  addu       $s5, $zero, $zero
    /* 6503C 800CD83C 801F023C */  lui        $v0, (0x1F800000 >> 16)
    /* 65040 800CD840 1800AF8F */  lw         $t7, 0x18($sp)
    /* 65044 800CD844 0000478C */  lw         $a3, (0x1F800000 & 0xFFFF)($v0)
    /* 65048 800CD848 1E00EC91 */  lbu        $t4, 0x1E($t7)
    /* 6504C 800CD84C 2000AF8F */  lw         $t7, 0x20($sp)
    /* 65050 800CD850 001A0C00 */  sll        $v1, $t4, 8
    /* 65054 800CD854 25188301 */  or         $v1, $t4, $v1
    /* 65058 800CD858 00240C00 */  sll        $a0, $t4, 16
    /* 6505C 800CD85C 0100E291 */  lbu        $v0, 0x1($t7)
    /* 65060 800CD860 00000000 */  nop
    /* 65064 800CD864 2A105500 */  slt        $v0, $v0, $s5
    /* 65068 800CD868 FE004014 */  bnez       $v0, .L800CDC64
    /* 6506C 800CD86C 25606400 */   or        $t4, $v1, $a0
    /* 65070 800CD870 FF000E3C */  lui        $t6, (0xFFFFFF >> 16)
    /* 65074 800CD874 FFFFCE35 */  ori        $t6, $t6, (0xFFFFFF & 0xFFFF)
    /* 65078 800CD878 2168E001 */  addu       $t5, $t7, $zero
  .L800CD87C:
    /* 6507C 800CD87C 0300A291 */  lbu        $v0, 0x3($t5)
    /* 65080 800CD880 00000000 */  nop
    /* 65084 800CD884 F0004010 */  beqz       $v0, .L800CDC48
    /* 65088 800CD888 21A00000 */   addu      $s4, $zero, $zero
    /* 6508C 800CD88C 1C00AF8F */  lw         $t7, 0x1C($sp)
    /* 65090 800CD890 00000000 */  nop
    /* 65094 800CD894 0300EA25 */  addiu      $t2, $t7, 0x3
  .L800CD898:
    /* 65098 800CD898 0E00A012 */  beqz       $s5, .L800CD8D4
    /* 6509C 800CD89C 00000000 */   nop
    /* 650A0 800CD8A0 1800AF8F */  lw         $t7, 0x18($sp)
    /* 650A4 800CD8A4 00000000 */  nop
    /* 650A8 800CD8A8 0000E28D */  lw         $v0, 0x0($t7)
    /* 650AC 800CD8AC 00000000 */  nop
    /* 650B0 800CD8B0 02130200 */  srl        $v0, $v0, 12
    /* 650B4 800CD8B4 0F004230 */  andi       $v0, $v0, 0xF
    /* 650B8 800CD8B8 0600A212 */  beq        $s5, $v0, .L800CD8D4
    /* 650BC 800CD8BC 00000000 */   nop
    /* 650C0 800CD8C0 1C00AF8F */  lw         $t7, 0x1C($sp)
    /* 650C4 800CD8C4 04004A25 */  addiu      $t2, $t2, 0x4
    /* 650C8 800CD8C8 0400EF25 */  addiu      $t7, $t7, 0x4
    /* 650CC 800CD8CC 0D370308 */  j          .L800CDC34
    /* 650D0 800CD8D0 1C00AFAF */   sw        $t7, 0x1C($sp)
  .L800CD8D4:
    /* 650D4 800CD8D4 1C00AF8F */  lw         $t7, 0x1C($sp)
    /* 650D8 800CD8D8 FEFF5691 */  lbu        $s6, -0x2($t2)
    /* 650DC 800CD8DC FFFF4B91 */  lbu        $t3, -0x1($t2)
    /* 650E0 800CD8E0 00004891 */  lbu        $t0, 0x0($t2)
    /* 650E4 800CD8E4 0000F191 */  lbu        $s1, 0x0($t7)
    /* 650E8 800CD8E8 04004A25 */  addiu      $t2, $t2, 0x4
    /* 650EC 800CD8EC 80101100 */  sll        $v0, $s1, 2
    /* 650F0 800CD8F0 21305700 */  addu       $a2, $v0, $s7
    /* 650F4 800CD8F4 80101600 */  sll        $v0, $s6, 2
    /* 650F8 800CD8F8 21205700 */  addu       $a0, $v0, $s7
    /* 650FC 800CD8FC 0000D384 */  lh         $s3, 0x0($a2)
    /* 65100 800CD900 00008384 */  lh         $v1, 0x0($a0)
    /* 65104 800CD904 0400EF25 */  addiu      $t7, $t7, 0x4
    /* 65108 800CD908 2A107300 */  slt        $v0, $v1, $s3
    /* 6510C 800CD90C 02004010 */  beqz       $v0, .L800CD918
    /* 65110 800CD910 1C00AFAF */   sw        $t7, 0x1C($sp)
    /* 65114 800CD914 21986000 */  addu       $s3, $v1, $zero
  .L800CD918:
    /* 65118 800CD918 80100B00 */  sll        $v0, $t3, 2
    /* 6511C 800CD91C 21285700 */  addu       $a1, $v0, $s7
    /* 65120 800CD920 0000A384 */  lh         $v1, 0x0($a1)
    /* 65124 800CD924 00000000 */  nop
    /* 65128 800CD928 2A107300 */  slt        $v0, $v1, $s3
    /* 6512C 800CD92C 02004010 */  beqz       $v0, .L800CD938
    /* 65130 800CD930 00000000 */   nop
    /* 65134 800CD934 21986000 */  addu       $s3, $v1, $zero
  .L800CD938:
    /* 65138 800CD938 0200C294 */  lhu        $v0, 0x2($a2)
    /* 6513C 800CD93C 02008394 */  lhu        $v1, 0x2($a0)
    /* 65140 800CD940 00140200 */  sll        $v0, $v0, 16
    /* 65144 800CD944 03940200 */  sra        $s2, $v0, 16
    /* 65148 800CD948 001C0300 */  sll        $v1, $v1, 16
    /* 6514C 800CD94C 031C0300 */  sra        $v1, $v1, 16
    /* 65150 800CD950 2A107200 */  slt        $v0, $v1, $s2
    /* 65154 800CD954 02004010 */  beqz       $v0, .L800CD960
    /* 65158 800CD958 00000000 */   nop
    /* 6515C 800CD95C 21906000 */  addu       $s2, $v1, $zero
  .L800CD960:
    /* 65160 800CD960 0200A294 */  lhu        $v0, 0x2($a1)
    /* 65164 800CD964 00000000 */  nop
    /* 65168 800CD968 00140200 */  sll        $v0, $v0, 16
    /* 6516C 800CD96C 031C0200 */  sra        $v1, $v0, 16
    /* 65170 800CD970 2A107200 */  slt        $v0, $v1, $s2
    /* 65174 800CD974 02004010 */  beqz       $v0, .L800CD980
    /* 65178 800CD978 FF000239 */   xori      $v0, $t0, 0xFF
    /* 6517C 800CD97C 21906000 */  addu       $s2, $v1, $zero
  .L800CD980:
    /* 65180 800CD980 2B100200 */  sltu       $v0, $zero, $v0
    /* 65184 800CD984 40480200 */  sll        $t1, $v0, 1
    /* 65188 800CD988 11002011 */  beqz       $t1, .L800CD9D0
    /* 6518C 800CD98C 80100800 */   sll       $v0, $t0, 2
    /* 65190 800CD990 21205700 */  addu       $a0, $v0, $s7
    /* 65194 800CD994 00008384 */  lh         $v1, 0x0($a0)
    /* 65198 800CD998 00000000 */  nop
    /* 6519C 800CD99C 2A107300 */  slt        $v0, $v1, $s3
    /* 651A0 800CD9A0 02004010 */  beqz       $v0, .L800CD9AC
    /* 651A4 800CD9A4 00000000 */   nop
    /* 651A8 800CD9A8 21986000 */  addu       $s3, $v1, $zero
  .L800CD9AC:
    /* 651AC 800CD9AC 02008294 */  lhu        $v0, 0x2($a0)
    /* 651B0 800CD9B0 00000000 */  nop
    /* 651B4 800CD9B4 00140200 */  sll        $v0, $v0, 16
    /* 651B8 800CD9B8 031C0200 */  sra        $v1, $v0, 16
    /* 651BC 800CD9BC 2A107200 */  slt        $v0, $v1, $s2
    /* 651C0 800CD9C0 05004010 */  beqz       $v0, .L800CD9D8
    /* 651C4 800CD9C4 09002225 */   addiu     $v0, $t1, 0x9
    /* 651C8 800CD9C8 76360308 */  j          .L800CD9D8
    /* 651CC 800CD9CC 21906000 */   addu      $s2, $v1, $zero
  .L800CD9D0:
    /* 651D0 800CD9D0 21400000 */  addu       $t0, $zero, $zero
    /* 651D4 800CD9D4 09002225 */  addiu      $v0, $t1, 0x9
  .L800CD9D8:
    /* 651D8 800CD9D8 80160200 */  sll        $v0, $v0, 26
    /* 651DC 800CD9DC 25108201 */  or         $v0, $t4, $v0
    /* 651E0 800CD9E0 80201100 */  sll        $a0, $s1, 2
    /* 651E4 800CD9E4 21209700 */  addu       $a0, $a0, $s7
    /* 651E8 800CD9E8 80301600 */  sll        $a2, $s6, 2
    /* 651EC 800CD9EC 1000AF8F */  lw         $t7, 0x10($sp)
    /* 651F0 800CD9F0 2130D700 */  addu       $a2, $a2, $s7
    /* 651F4 800CD9F4 0800E38D */  lw         $v1, 0x8($t7)
    /* 651F8 800CD9F8 80280B00 */  sll        $a1, $t3, 2
    /* 651FC 800CD9FC 0400E2AC */  sw         $v0, 0x4($a3)
    /* 65200 800CDA00 07002225 */  addiu      $v0, $t1, 0x7
    /* 65204 800CDA04 00160200 */  sll        $v0, $v0, 24
    /* 65208 800CDA08 24186E00 */  and        $v1, $v1, $t6
    /* 6520C 800CDA0C 25186200 */  or         $v1, $v1, $v0
    /* 65210 800CDA10 0000E3AC */  sw         $v1, 0x0($a3)
    /* 65214 800CDA14 83191300 */  sra        $v1, $s3, 6
    /* 65218 800CDA18 0000828C */  lw         $v0, 0x0($a0)
    /* 6521C 800CDA1C 80990300 */  sll        $s3, $v1, 6
    /* 65220 800CDA20 0800E2AC */  sw         $v0, 0x8($a3)
    /* 65224 800CDA24 83111200 */  sra        $v0, $s2, 6
    /* 65228 800CDA28 80910200 */  sll        $s2, $v0, 6
    /* 6522C 800CDA2C 00008384 */  lh         $v1, 0x0($a0)
    /* 65230 800CDA30 02008294 */  lhu        $v0, 0x2($a0)
    /* 65234 800CDA34 23187300 */  subu       $v1, $v1, $s3
    /* 65238 800CDA38 FF006330 */  andi       $v1, $v1, 0xFF
    /* 6523C 800CDA3C 00140200 */  sll        $v0, $v0, 16
    /* 65240 800CDA40 03140200 */  sra        $v0, $v0, 16
    /* 65244 800CDA44 23105200 */  subu       $v0, $v0, $s2
    /* 65248 800CDA48 00120200 */  sll        $v0, $v0, 8
    /* 6524C 800CDA4C 00FF4230 */  andi       $v0, $v0, 0xFF00
    /* 65250 800CDA50 25186200 */  or         $v1, $v1, $v0
    /* 65254 800CDA54 3E37023C */  lui        $v0, (0x373E0000 >> 16)
    /* 65258 800CDA58 25186200 */  or         $v1, $v1, $v0
    /* 6525C 800CDA5C 0C00E3AC */  sw         $v1, 0xC($a3)
    /* 65260 800CDA60 0000C28C */  lw         $v0, 0x0($a2)
    /* 65264 800CDA64 2128B700 */  addu       $a1, $a1, $s7
    /* 65268 800CDA68 1000E2AC */  sw         $v0, 0x10($a3)
    /* 6526C 800CDA6C 0000C384 */  lh         $v1, 0x0($a2)
    /* 65270 800CDA70 0200C294 */  lhu        $v0, 0x2($a2)
    /* 65274 800CDA74 23187300 */  subu       $v1, $v1, $s3
    /* 65278 800CDA78 FF006330 */  andi       $v1, $v1, 0xFF
    /* 6527C 800CDA7C 00140200 */  sll        $v0, $v0, 16
    /* 65280 800CDA80 03140200 */  sra        $v0, $v0, 16
    /* 65284 800CDA84 23105200 */  subu       $v0, $v0, $s2
    /* 65288 800CDA88 00120200 */  sll        $v0, $v0, 8
    /* 6528C 800CDA8C 00FF4230 */  andi       $v0, $v0, 0xFF00
    /* 65290 800CDA90 25186200 */  or         $v1, $v1, $v0
    /* 65294 800CDA94 1700023C */  lui        $v0, (0x170000 >> 16)
    /* 65298 800CDA98 25186200 */  or         $v1, $v1, $v0
    /* 6529C 800CDA9C 1400E3AC */  sw         $v1, 0x14($a3)
    /* 652A0 800CDAA0 0000A28C */  lw         $v0, 0x0($a1)
    /* 652A4 800CDAA4 00000000 */  nop
    /* 652A8 800CDAA8 1800E2AC */  sw         $v0, 0x18($a3)
    /* 652AC 800CDAAC 0000A384 */  lh         $v1, 0x0($a1)
    /* 652B0 800CDAB0 0200A294 */  lhu        $v0, 0x2($a1)
    /* 652B4 800CDAB4 23187300 */  subu       $v1, $v1, $s3
    /* 652B8 800CDAB8 FF006330 */  andi       $v1, $v1, 0xFF
    /* 652BC 800CDABC 00140200 */  sll        $v0, $v0, 16
    /* 652C0 800CDAC0 03140200 */  sra        $v0, $v0, 16
    /* 652C4 800CDAC4 23105200 */  subu       $v0, $v0, $s2
    /* 652C8 800CDAC8 00120200 */  sll        $v0, $v0, 8
    /* 652CC 800CDACC 00FF4230 */  andi       $v0, $v0, 0xFF00
    /* 652D0 800CDAD0 25186200 */  or         $v1, $v1, $v0
    /* 652D4 800CDAD4 80100800 */  sll        $v0, $t0, 2
    /* 652D8 800CDAD8 21405700 */  addu       $t0, $v0, $s7
    /* 652DC 800CDADC 1C00E3AC */  sw         $v1, 0x1C($a3)
    /* 652E0 800CDAE0 0000028D */  lw         $v0, 0x0($t0)
    /* 652E4 800CDAE4 00000000 */  nop
    /* 652E8 800CDAE8 2000E2AC */  sw         $v0, 0x20($a3)
    /* 652EC 800CDAEC 00000385 */  lh         $v1, 0x0($t0)
    /* 652F0 800CDAF0 02000295 */  lhu        $v0, 0x2($t0)
    /* 652F4 800CDAF4 23187300 */  subu       $v1, $v1, $s3
    /* 652F8 800CDAF8 FF006330 */  andi       $v1, $v1, 0xFF
    /* 652FC 800CDAFC 00140200 */  sll        $v0, $v0, 16
    /* 65300 800CDB00 03140200 */  sra        $v0, $v0, 16
    /* 65304 800CDB04 23105200 */  subu       $v0, $v0, $s2
    /* 65308 800CDB08 00120200 */  sll        $v0, $v0, 8
    /* 6530C 800CDB0C 00FF4230 */  andi       $v0, $v0, 0xFF00
    /* 65310 800CDB10 25186200 */  or         $v1, $v1, $v0
    /* 65314 800CDB14 2400E3AC */  sw         $v1, 0x24($a3)
    /* 65318 800CDB18 001A0700 */  sll        $v1, $a3, 8
    /* 6531C 800CDB1C 80100900 */  sll        $v0, $t1, 2
    /* 65320 800CDB20 20004224 */  addiu      $v0, $v0, 0x20
    /* 65324 800CDB24 2138E200 */  addu       $a3, $a3, $v0
    /* 65328 800CDB28 021A0300 */  srl        $v1, $v1, 8
    /* 6532C 800CDB2C 08002225 */  addiu      $v0, $t1, 0x8
    /* 65330 800CDB30 0800E3AD */  sw         $v1, 0x8($t7)
    /* 65334 800CDB34 0400E38D */  lw         $v1, 0x4($t7)
    /* 65338 800CDB38 80160200 */  sll        $v0, $v0, 26
    /* 6533C 800CDB3C 0400E2AC */  sw         $v0, 0x4($a3)
    /* 65340 800CDB40 000C023C */  lui        $v0, (0xC000000 >> 16)
    /* 65344 800CDB44 24186E00 */  and        $v1, $v1, $t6
    /* 65348 800CDB48 25186200 */  or         $v1, $v1, $v0
    /* 6534C 800CDB4C 0000E3AC */  sw         $v1, 0x0($a3)
    /* 65350 800CDB50 00008384 */  lh         $v1, 0x0($a0)
    /* 65354 800CDB54 02008294 */  lhu        $v0, 0x2($a0)
    /* 65358 800CDB58 0200043C */  lui        $a0, (0x20000 >> 16)
    /* 6535C 800CDB5C 02006324 */  addiu      $v1, $v1, 0x2
    /* 65360 800CDB60 FFFF6330 */  andi       $v1, $v1, 0xFFFF
    /* 65364 800CDB64 00140200 */  sll        $v0, $v0, 16
    /* 65368 800CDB68 21104400 */  addu       $v0, $v0, $a0
    /* 6536C 800CDB6C 25186200 */  or         $v1, $v1, $v0
    /* 65370 800CDB70 0800E3AC */  sw         $v1, 0x8($a3)
    /* 65374 800CDB74 0000C384 */  lh         $v1, 0x0($a2)
    /* 65378 800CDB78 0200C294 */  lhu        $v0, 0x2($a2)
    /* 6537C 800CDB7C 02006324 */  addiu      $v1, $v1, 0x2
    /* 65380 800CDB80 FFFF6330 */  andi       $v1, $v1, 0xFFFF
    /* 65384 800CDB84 00140200 */  sll        $v0, $v0, 16
    /* 65388 800CDB88 21104400 */  addu       $v0, $v0, $a0
    /* 6538C 800CDB8C 25186200 */  or         $v1, $v1, $v0
    /* 65390 800CDB90 0C00E3AC */  sw         $v1, 0xC($a3)
    /* 65394 800CDB94 0000A384 */  lh         $v1, 0x0($a1)
    /* 65398 800CDB98 0200A294 */  lhu        $v0, 0x2($a1)
    /* 6539C 800CDB9C 02006324 */  addiu      $v1, $v1, 0x2
    /* 653A0 800CDBA0 FFFF6330 */  andi       $v1, $v1, 0xFFFF
    /* 653A4 800CDBA4 00140200 */  sll        $v0, $v0, 16
    /* 653A8 800CDBA8 21104400 */  addu       $v0, $v0, $a0
    /* 653AC 800CDBAC 25186200 */  or         $v1, $v1, $v0
    /* 653B0 800CDBB0 0A002011 */  beqz       $t1, .L800CDBDC
    /* 653B4 800CDBB4 1000E3AC */   sw        $v1, 0x10($a3)
    /* 653B8 800CDBB8 00000285 */  lh         $v0, 0x0($t0)
    /* 653BC 800CDBBC 02000395 */  lhu        $v1, 0x2($t0)
    /* 653C0 800CDBC0 02004224 */  addiu      $v0, $v0, 0x2
    /* 653C4 800CDBC4 FFFF4230 */  andi       $v0, $v0, 0xFFFF
    /* 653C8 800CDBC8 001C0300 */  sll        $v1, $v1, 16
    /* 653CC 800CDBCC 21186400 */  addu       $v1, $v1, $a0
    /* 653D0 800CDBD0 25104300 */  or         $v0, $v0, $v1
    /* 653D4 800CDBD4 F8360308 */  j          .L800CDBE0
    /* 653D8 800CDBD8 1400E2AC */   sw        $v0, 0x14($a3)
  .L800CDBDC:
    /* 653DC 800CDBDC 1400E0AC */  sw         $zero, 0x14($a3)
  .L800CDBE0:
    /* 653E0 800CDBE0 5555053C */  lui        $a1, (0x55555555 >> 16)
    /* 653E4 800CDBE4 0048023C */  lui        $v0, (0x48000000 >> 16)
    /* 653E8 800CDBE8 1800E2AC */  sw         $v0, 0x18($a3)
    /* 653EC 800CDBEC 80100900 */  sll        $v0, $t1, 2
    /* 653F0 800CDBF0 0800E38C */  lw         $v1, 0x8($a3)
    /* 653F4 800CDBF4 0C00E48C */  lw         $a0, 0xC($a3)
    /* 653F8 800CDBF8 21104700 */  addu       $v0, $v0, $a3
    /* 653FC 800CDBFC 1C00E3AC */  sw         $v1, 0x1C($a3)
    /* 65400 800CDC00 2000E4AC */  sw         $a0, 0x20($a3)
    /* 65404 800CDC04 0C00448C */  lw         $a0, 0xC($v0)
    /* 65408 800CDC08 1000E28C */  lw         $v0, 0x10($a3)
    /* 6540C 800CDC0C 5555A534 */  ori        $a1, $a1, (0x55555555 & 0xFFFF)
    /* 65410 800CDC10 2C00E3AC */  sw         $v1, 0x2C($a3)
    /* 65414 800CDC14 3000E5AC */  sw         $a1, 0x30($a3)
    /* 65418 800CDC18 2800E2AC */  sw         $v0, 0x28($a3)
    /* 6541C 800CDC1C 00120700 */  sll        $v0, $a3, 8
    /* 65420 800CDC20 2400E4AC */  sw         $a0, 0x24($a3)
    /* 65424 800CDC24 3400E724 */  addiu      $a3, $a3, 0x34
    /* 65428 800CDC28 1000AF8F */  lw         $t7, 0x10($sp)
    /* 6542C 800CDC2C 02120200 */  srl        $v0, $v0, 8
    /* 65430 800CDC30 0400E2AD */  sw         $v0, 0x4($t7)
  .L800CDC34:
    /* 65434 800CDC34 0300A291 */  lbu        $v0, 0x3($t5)
    /* 65438 800CDC38 01009426 */  addiu      $s4, $s4, 0x1
    /* 6543C 800CDC3C 2A108202 */  slt        $v0, $s4, $v0
    /* 65440 800CDC40 15FF4014 */  bnez       $v0, .L800CD898
    /* 65444 800CDC44 00000000 */   nop
  .L800CDC48:
    /* 65448 800CDC48 2000AF8F */  lw         $t7, 0x20($sp)
    /* 6544C 800CDC4C 00000000 */  nop
    /* 65450 800CDC50 0100E291 */  lbu        $v0, 0x1($t7)
    /* 65454 800CDC54 0100B526 */  addiu      $s5, $s5, 0x1
    /* 65458 800CDC58 2A105500 */  slt        $v0, $v0, $s5
    /* 6545C 800CDC5C 07FF4010 */  beqz       $v0, .L800CD87C
    /* 65460 800CDC60 0400AD25 */   addiu     $t5, $t5, 0x4
  .L800CDC64:
    /* 65464 800CDC64 801F023C */  lui        $v0, (0x1F800000 >> 16)
    /* 65468 800CDC68 00E1053C */  lui        $a1, (0xE1000017 >> 16)
    /* 6546C 800CDC6C 1700A534 */  ori        $a1, $a1, (0xE1000017 & 0xFFFF)
    /* 65470 800CDC70 00E2063C */  lui        $a2, (0xE2000318 >> 16)
    /* 65474 800CDC74 1000AF8F */  lw         $t7, 0x10($sp)
    /* 65478 800CDC78 1803C634 */  ori        $a2, $a2, (0xE2000318 & 0xFFFF)
    /* 6547C 800CDC7C 000047AC */  sw         $a3, (0x1F800000 & 0xFFFF)($v0)
    /* 65480 800CDC80 21380000 */  addu       $a3, $zero, $zero
    /* 65484 800CDC84 2E33030C */  jal        func_800CCCB8
    /* 65488 800CDC88 0800E425 */   addiu     $a0, $t7, 0x8
  .L800CDC8C:
    /* 6548C 800CDC8C 5C00BF8F */  lw         $ra, 0x5C($sp)
    /* 65490 800CDC90 5800BE8F */  lw         $fp, 0x58($sp)
    /* 65494 800CDC94 5400B78F */  lw         $s7, 0x54($sp)
    /* 65498 800CDC98 5000B68F */  lw         $s6, 0x50($sp)
    /* 6549C 800CDC9C 4C00B58F */  lw         $s5, 0x4C($sp)
    /* 654A0 800CDCA0 4800B48F */  lw         $s4, 0x48($sp)
    /* 654A4 800CDCA4 4400B38F */  lw         $s3, 0x44($sp)
    /* 654A8 800CDCA8 4000B28F */  lw         $s2, 0x40($sp)
    /* 654AC 800CDCAC 3C00B18F */  lw         $s1, 0x3C($sp)
    /* 654B0 800CDCB0 3800B08F */  lw         $s0, 0x38($sp)
    /* 654B4 800CDCB4 0800E003 */  jr         $ra
    /* 654B8 800CDCB8 6000BD27 */   addiu     $sp, $sp, 0x60
endlabel func_800CD3E4
