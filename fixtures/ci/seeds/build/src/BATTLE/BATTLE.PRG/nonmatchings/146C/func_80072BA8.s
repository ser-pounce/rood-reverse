nonmatching func_80072BA8, 0x31C

glabel func_80072BA8
    /* A3A8 80072BA8 B8FFBD27 */  addiu      $sp, $sp, -0x48
    /* A3AC 80072BAC 3800B4AF */  sw         $s4, 0x38($sp)
    /* A3B0 80072BB0 0F80143C */  lui        $s4, %hi(D_800F19CC)
    /* A3B4 80072BB4 CC19828E */  lw         $v0, %lo(D_800F19CC)($s4)
    /* A3B8 80072BB8 2800B0AF */  sw         $s0, 0x28($sp)
    /* A3BC 80072BBC 21808000 */  addu       $s0, $a0, $zero
    /* A3C0 80072BC0 4000BFAF */  sw         $ra, 0x40($sp)
    /* A3C4 80072BC4 3C00B5AF */  sw         $s5, 0x3C($sp)
    /* A3C8 80072BC8 3400B3AF */  sw         $s3, 0x34($sp)
    /* A3CC 80072BCC 3000B2AF */  sw         $s2, 0x30($sp)
    /* A3D0 80072BD0 2C00B1AF */  sw         $s1, 0x2C($sp)
    /* A3D4 80072BD4 B705030C */  jal        func_800C16DC
    /* A3D8 80072BD8 080050A4 */   sh        $s0, 0x8($v0)
    /* A3DC 80072BDC B801030C */  jal        func_800C06E0
    /* A3E0 80072BE0 00000000 */   nop
    /* A3E4 80072BE4 CE01030C */  jal        func_800C0738
    /* A3E8 80072BE8 00000000 */   nop
    /* A3EC 80072BEC 6E000016 */  bnez       $s0, .L80072DA8
    /* A3F0 80072BF0 0580033C */   lui       $v1, %hi(vs_main_skills)
    /* A3F4 80072BF4 21200000 */  addu       $a0, $zero, $zero
    /* A3F8 80072BF8 1800B227 */  addiu      $s2, $sp, 0x18
    /* A3FC 80072BFC 21284002 */  addu       $a1, $s2, $zero
    /* A400 80072C00 21988000 */  addu       $s3, $a0, $zero
    /* A404 80072C04 CC19838E */  lw         $v1, %lo(D_800F19CC)($s4)
    /* A408 80072C08 01000224 */  addiu      $v0, $zero, 0x1
    /* A40C 80072C0C A02962A0 */  sb         $v0, 0x29A0($v1)
    /* A410 80072C10 CC19828E */  lw         $v0, %lo(D_800F19CC)($s4)
    /* A414 80072C14 03001124 */  addiu      $s1, $zero, 0x3
    /* A418 80072C18 4284020C */  jal        func_800A1108
    /* A41C 80072C1C A12951A0 */   sb        $s1, 0x29A1($v0)
    /* A420 80072C20 CC19838E */  lw         $v1, %lo(D_800F19CC)($s4)
    /* A424 80072C24 2200A497 */  lhu        $a0, 0x22($sp)
    /* A428 80072C28 04001024 */  addiu      $s0, $zero, 0x4
    /* A42C 80072C2C A42970A0 */  sb         $s0, 0x29A4($v1)
    /* A430 80072C30 CC19828E */  lw         $v0, %lo(D_800F19CC)($s4)
    /* A434 80072C34 21A80000 */  addu       $s5, $zero, $zero
    /* A438 80072C38 A22964A4 */  sh         $a0, 0x29A2($v1)
    /* A43C 80072C3C A52950A0 */  sb         $s0, 0x29A5($v0)
    /* A440 80072C40 CC19828E */  lw         $v0, %lo(D_800F19CC)($s4)
    /* A444 80072C44 FA000524 */  addiu      $a1, $zero, 0xFA
    /* A448 80072C48 A62950A0 */  sb         $s0, 0x29A6($v0)
    /* A44C 80072C4C CC19828E */  lw         $v0, %lo(D_800F19CC)($s4)
    /* A450 80072C50 2138A002 */  addu       $a3, $s5, $zero
    /* A454 80072C54 A72940A0 */  sb         $zero, 0x29A7($v0)
    /* A458 80072C58 CC19868E */  lw         $a2, %lo(D_800F19CC)($s4)
    /* A45C 80072C5C 2120A002 */  addu       $a0, $s5, $zero
    /* A460 80072C60 4386020C */  jal        func_800A190C
    /* A464 80072C64 A829C624 */   addiu     $a2, $a2, 0x29A8
    /* A468 80072C68 2128A002 */  addu       $a1, $s5, $zero
    /* A46C 80072C6C 2130A002 */  addu       $a2, $s5, $zero
    /* A470 80072C70 CC19848E */  lw         $a0, %lo(D_800F19CC)($s4)
    /* A474 80072C74 2138A002 */  addu       $a3, $s5, $zero
    /* A478 80072C78 7B01030C */  jal        func_800C05EC
    /* A47C 80072C7C A0298424 */   addiu     $a0, $a0, 0x29A0
    /* A480 80072C80 01000424 */  addiu      $a0, $zero, 0x1
    /* A484 80072C84 CC19838E */  lw         $v1, %lo(D_800F19CC)($s4)
    /* A488 80072C88 02000224 */  addiu      $v0, $zero, 0x2
    /* A48C 80072C8C B02962A0 */  sb         $v0, 0x29B0($v1)
    /* A490 80072C90 CC19828E */  lw         $v0, %lo(D_800F19CC)($s4)
    /* A494 80072C94 21284002 */  addu       $a1, $s2, $zero
    /* A498 80072C98 4284020C */  jal        func_800A1108
    /* A49C 80072C9C B12951A0 */   sb        $s1, 0x29B1($v0)
    /* A4A0 80072CA0 CC19838E */  lw         $v1, %lo(D_800F19CC)($s4)
    /* A4A4 80072CA4 2200A497 */  lhu        $a0, 0x22($sp)
    /* A4A8 80072CA8 21908002 */  addu       $s2, $s4, $zero
    /* A4AC 80072CAC B42970A0 */  sb         $s0, 0x29B4($v1)
    /* A4B0 80072CB0 CC19428E */  lw         $v0, %lo(D_800F19CC)($s2)
    /* A4B4 80072CB4 C0291424 */  addiu      $s4, $zero, 0x29C0
    /* A4B8 80072CB8 B22964A4 */  sh         $a0, 0x29B2($v1)
    /* A4BC 80072CBC B52950A0 */  sb         $s0, 0x29B5($v0)
    /* A4C0 80072CC0 CC19428E */  lw         $v0, %lo(D_800F19CC)($s2)
    /* A4C4 80072CC4 FA000524 */  addiu      $a1, $zero, 0xFA
    /* A4C8 80072CC8 B62950A0 */  sb         $s0, 0x29B6($v0)
    /* A4CC 80072CCC CC19428E */  lw         $v0, %lo(D_800F19CC)($s2)
    /* A4D0 80072CD0 2138A002 */  addu       $a3, $s5, $zero
    /* A4D4 80072CD4 B72940A0 */  sb         $zero, 0x29B7($v0)
    /* A4D8 80072CD8 CC19468E */  lw         $a2, %lo(D_800F19CC)($s2)
    /* A4DC 80072CDC 01000424 */  addiu      $a0, $zero, 0x1
    /* A4E0 80072CE0 4386020C */  jal        func_800A190C
    /* A4E4 80072CE4 B829C624 */   addiu     $a2, $a2, 0x29B8
    /* A4E8 80072CE8 CC19448E */  lw         $a0, %lo(D_800F19CC)($s2)
    /* A4EC 80072CEC 2188A002 */  addu       $s1, $s5, $zero
    /* A4F0 80072CF0 C001030C */  jal        func_800C0700
    /* A4F4 80072CF4 B0298424 */   addiu     $a0, $a0, 0x29B0
    /* A4F8 80072CF8 01000424 */  addiu      $a0, $zero, 0x1
  .L80072CFC:
    /* A4FC 80072CFC 21286002 */  addu       $a1, $s3, $zero
    /* A500 80072D00 4B85020C */  jal        func_800A152C
    /* A504 80072D04 02000624 */   addiu     $a2, $zero, 0x2
    /* A508 80072D08 21804000 */  addu       $s0, $v0, $zero
    /* A50C 80072D0C 17000006 */  bltz       $s0, .L80072D6C
    /* A510 80072D10 01000424 */   addiu     $a0, $zero, 0x1
    /* A514 80072D14 21286002 */  addu       $a1, $s3, $zero
    /* A518 80072D18 CC19468E */  lw         $a2, %lo(D_800F19CC)($s2)
    /* A51C 80072D1C 21380000 */  addu       $a3, $zero, $zero
    /* A520 80072D20 E786020C */  jal        func_800A1B9C
    /* A524 80072D24 2130D400 */   addu      $a2, $a2, $s4
    /* A528 80072D28 01000424 */  addiu      $a0, $zero, 0x1
    /* A52C 80072D2C 21280002 */  addu       $a1, $s0, $zero
    /* A530 80072D30 9285020C */  jal        func_800A1648
    /* A534 80072D34 21300000 */   addu      $a2, $zero, $zero
    /* A538 80072D38 CC19438E */  lw         $v1, %lo(D_800F19CC)($s2)
    /* A53C 80072D3C 0100B526 */  addiu      $s5, $s5, 0x1
    /* A540 80072D40 21187100 */  addu       $v1, $v1, $s1
    /* A544 80072D44 C82962A0 */  sb         $v0, 0x29C8($v1)
    /* A548 80072D48 CC19428E */  lw         $v0, %lo(D_800F19CC)($s2)
    /* A54C 80072D4C 18009426 */  addiu      $s4, $s4, 0x18
    /* A550 80072D50 21105100 */  addu       $v0, $v0, $s1
    /* A554 80072D54 CA2953A0 */  sb         $s3, 0x29CA($v0)
    /* A558 80072D58 CC19438E */  lw         $v1, %lo(D_800F19CC)($s2)
    /* A55C 80072D5C 01000224 */  addiu      $v0, $zero, 0x1
    /* A560 80072D60 21187100 */  addu       $v1, $v1, $s1
    /* A564 80072D64 18003126 */  addiu      $s1, $s1, 0x18
    /* A568 80072D68 C92962A0 */  sb         $v0, 0x29C9($v1)
  .L80072D6C:
    /* A56C 80072D6C 01007326 */  addiu      $s3, $s3, 0x1
    /* A570 80072D70 0600622A */  slti       $v0, $s3, 0x6
    /* A574 80072D74 E1FF4014 */  bnez       $v0, .L80072CFC
    /* A578 80072D78 01000424 */   addiu     $a0, $zero, 0x1
    /* A57C 80072D7C 2120A002 */  addu       $a0, $s5, $zero
    /* A580 80072D80 0F80023C */  lui        $v0, %hi(D_800F19CC)
    /* A584 80072D84 CC19428C */  lw         $v0, %lo(D_800F19CC)($v0)
    /* A588 80072D88 21300000 */  addu       $a2, $zero, $zero
    /* A58C 80072D8C C0294524 */  addiu      $a1, $v0, 0x29C0
    /* A590 80072D90 9905030C */  jal        func_800C1664
    /* A594 80072D94 002C44A4 */   sh        $a0, 0x2C00($v0)
    /* A598 80072D98 0F80033C */  lui        $v1, %hi(_cameraMode)
    /* A59C 80072D9C 01000224 */  addiu      $v0, $zero, 0x1
    /* A5A0 80072DA0 A8CB0108 */  j          .L80072EA0
    /* A5A4 80072DA4 F01862AC */   sw        $v0, %lo(_cameraMode)($v1)
  .L80072DA8:
    /* A5A8 80072DA8 DCB96324 */  addiu      $v1, $v1, %lo(vs_main_skills)
    /* A5AC 80072DAC 40101000 */  sll        $v0, $s0, 1
    /* A5B0 80072DB0 21105000 */  addu       $v0, $v0, $s0
    /* A5B4 80072DB4 80100200 */  sll        $v0, $v0, 2
    /* A5B8 80072DB8 21105000 */  addu       $v0, $v0, $s0
    /* A5BC 80072DBC 80100200 */  sll        $v0, $v0, 2
    /* A5C0 80072DC0 21104300 */  addu       $v0, $v0, $v1
    /* A5C4 80072DC4 0F80033C */  lui        $v1, %hi(D_800E8184)
    /* A5C8 80072DC8 02004290 */  lbu        $v0, 0x2($v0)
    /* A5CC 80072DCC 84816324 */  addiu      $v1, $v1, %lo(D_800E8184)
    /* A5D0 80072DD0 02210200 */  srl        $a0, $v0, 4
    /* A5D4 80072DD4 21188300 */  addu       $v1, $a0, $v1
    /* A5D8 80072DD8 00006290 */  lbu        $v0, 0x0($v1)
    /* A5DC 80072DDC 00000000 */  nop
    /* A5E0 80072DE0 23004010 */  beqz       $v0, .L80072E70
    /* A5E4 80072DE4 0F80023C */   lui       $v0, %hi(D_800E8194)
    /* A5E8 80072DE8 94814224 */  addiu      $v0, $v0, %lo(D_800E8194)
    /* A5EC 80072DEC 21108200 */  addu       $v0, $a0, $v0
    /* A5F0 80072DF0 00004290 */  lbu        $v0, 0x0($v0)
    /* A5F4 80072DF4 00000000 */  nop
    /* A5F8 80072DF8 0F004010 */  beqz       $v0, .L80072E38
    /* A5FC 80072DFC 0F80023C */   lui       $v0, %hi(D_800E81C4)
    /* A600 80072E00 C4814224 */  addiu      $v0, $v0, %lo(D_800E81C4)
    /* A604 80072E04 21108200 */  addu       $v0, $a0, $v0
    /* A608 80072E08 00004290 */  lbu        $v0, 0x0($v0)
    /* A60C 80072E0C 00000000 */  nop
    /* A610 80072E10 05004014 */  bnez       $v0, .L80072E28
    /* A614 80072E14 00000000 */   nop
    /* A618 80072E18 CDC9010C */  jal        func_80072734
    /* A61C 80072E1C 21200000 */   addu      $a0, $zero, $zero
    /* A620 80072E20 A8CB0108 */  j          .L80072EA0
    /* A624 80072E24 00000000 */   nop
  .L80072E28:
    /* A628 80072E28 CDC9010C */  jal        func_80072734
    /* A62C 80072E2C 01000424 */   addiu     $a0, $zero, 0x1
    /* A630 80072E30 A8CB0108 */  j          .L80072EA0
    /* A634 80072E34 00000000 */   nop
  .L80072E38:
    /* A638 80072E38 C4814224 */  addiu      $v0, $v0, %lo(D_800E81C4)
    /* A63C 80072E3C 21108200 */  addu       $v0, $a0, $v0
    /* A640 80072E40 00004290 */  lbu        $v0, 0x0($v0)
    /* A644 80072E44 00000000 */  nop
    /* A648 80072E48 05004014 */  bnez       $v0, .L80072E60
    /* A64C 80072E4C 00000000 */   nop
    /* A650 80072E50 DAC7010C */  jal        func_80071F68
    /* A654 80072E54 02000424 */   addiu     $a0, $zero, 0x2
    /* A658 80072E58 A8CB0108 */  j          .L80072EA0
    /* A65C 80072E5C 00000000 */   nop
  .L80072E60:
    /* A660 80072E60 DAC7010C */  jal        func_80071F68
    /* A664 80072E64 03000424 */   addiu     $a0, $zero, 0x3
    /* A668 80072E68 A8CB0108 */  j          .L80072EA0
    /* A66C 80072E6C 00000000 */   nop
  .L80072E70:
    /* A670 80072E70 94814224 */  addiu      $v0, $v0, %lo(D_800E8194)
    /* A674 80072E74 21108200 */  addu       $v0, $a0, $v0
    /* A678 80072E78 00004290 */  lbu        $v0, 0x0($v0)
    /* A67C 80072E7C 00000000 */  nop
    /* A680 80072E80 05004010 */  beqz       $v0, .L80072E98
    /* A684 80072E84 00000000 */   nop
    /* A688 80072E88 7FC6010C */  jal        func_800719FC
    /* A68C 80072E8C 04000424 */   addiu     $a0, $zero, 0x4
    /* A690 80072E90 A8CB0108 */  j          .L80072EA0
    /* A694 80072E94 00000000 */   nop
  .L80072E98:
    /* A698 80072E98 77C6010C */  jal        func_800719DC
    /* A69C 80072E9C 06000424 */   addiu     $a0, $zero, 0x6
  .L80072EA0:
    /* A6A0 80072EA0 4000BF8F */  lw         $ra, 0x40($sp)
    /* A6A4 80072EA4 3C00B58F */  lw         $s5, 0x3C($sp)
    /* A6A8 80072EA8 3800B48F */  lw         $s4, 0x38($sp)
    /* A6AC 80072EAC 3400B38F */  lw         $s3, 0x34($sp)
    /* A6B0 80072EB0 3000B28F */  lw         $s2, 0x30($sp)
    /* A6B4 80072EB4 2C00B18F */  lw         $s1, 0x2C($sp)
    /* A6B8 80072EB8 2800B08F */  lw         $s0, 0x28($sp)
    /* A6BC 80072EBC 0800E003 */  jr         $ra
    /* A6C0 80072EC0 4800BD27 */   addiu     $sp, $sp, 0x48
endlabel func_80072BA8
