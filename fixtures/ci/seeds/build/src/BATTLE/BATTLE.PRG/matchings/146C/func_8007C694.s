nonmatching func_8007C694, 0x188

glabel func_8007C694
    /* 13E94 8007C694 C8FFBD27 */  addiu      $sp, $sp, -0x38
    /* 13E98 8007C698 3000B4AF */  sw         $s4, 0x30($sp)
    /* 13E9C 8007C69C 21A0E000 */  addu       $s4, $a3, $zero
    /* 13EA0 8007C6A0 40180400 */  sll        $v1, $a0, 1
    /* 13EA4 8007C6A4 21200000 */  addu       $a0, $zero, $zero
    /* 13EA8 8007C6A8 1F00A730 */  andi       $a3, $a1, 0x1F
    /* 13EAC 8007C6AC 1000A527 */  addiu      $a1, $sp, 0x10
    /* 13EB0 8007C6B0 0580023C */  lui        $v0, %hi(vs_main_locationZoneMapIds)
    /* 13EB4 8007C6B4 CCF04224 */  addiu      $v0, $v0, %lo(vs_main_locationZoneMapIds)
    /* 13EB8 8007C6B8 21406200 */  addu       $t0, $v1, $v0
    /* 13EBC 8007C6BC 01006324 */  addiu      $v1, $v1, 0x1
    /* 13EC0 8007C6C0 21186200 */  addu       $v1, $v1, $v0
    /* 13EC4 8007C6C4 2C00B3AF */  sw         $s3, 0x2C($sp)
    /* 13EC8 8007C6C8 0F80133C */  lui        $s3, %hi(D_800F1AB0)
    /* 13ECC 8007C6CC 2000B0AF */  sw         $s0, 0x20($sp)
    /* 13ED0 8007C6D0 B01A7026 */  addiu      $s0, $s3, %lo(D_800F1AB0)
    /* 13ED4 8007C6D4 003A0700 */  sll        $a3, $a3, 8
    /* 13ED8 8007C6D8 1F00C630 */  andi       $a2, $a2, 0x1F
    /* 13EDC 8007C6DC 80320600 */  sll        $a2, $a2, 10
    /* 13EE0 8007C6E0 3400BFAF */  sw         $ra, 0x34($sp)
    /* 13EE4 8007C6E4 2800B2AF */  sw         $s2, 0x28($sp)
    /* 13EE8 8007C6E8 2400B1AF */  sw         $s1, 0x24($sp)
    /* 13EEC 8007C6EC 04000296 */  lhu        $v0, 0x4($s0)
    /* 13EF0 8007C6F0 00001191 */  lbu        $s1, 0x0($t0)
    /* 13EF4 8007C6F4 00007290 */  lbu        $s2, 0x0($v1)
    /* 13EF8 8007C6F8 02000396 */  lhu        $v1, 0x2($s0)
    /* 13EFC 8007C6FC FFE04230 */  andi       $v0, $v0, 0xE0FF
    /* 13F00 8007C700 25104700 */  or         $v0, $v0, $a3
    /* 13F04 8007C704 040002A6 */  sh         $v0, 0x4($s0)
    /* 13F08 8007C708 06000296 */  lhu        $v0, 0x6($s0)
    /* 13F0C 8007C70C FF1F6330 */  andi       $v1, $v1, 0x1FFF
    /* 13F10 8007C710 020003A6 */  sh         $v1, 0x2($s0)
    /* 13F14 8007C714 FF834230 */  andi       $v0, $v0, 0x83FF
    /* 13F18 8007C718 25104600 */  or         $v0, $v0, $a2
    /* 13F1C 8007C71C 4284020C */  jal        func_800A1108
    /* 13F20 8007C720 060002A6 */   sh        $v0, 0x6($s0)
    /* 13F24 8007C724 1A00A487 */  lh         $a0, 0x1A($sp)
    /* 13F28 8007C728 00000000 */  nop
    /* 13F2C 8007C72C 00028324 */  addiu      $v1, $a0, 0x200
    /* 13F30 8007C730 02006104 */  bgez       $v1, .L8007C73C
    /* 13F34 8007C734 21106000 */   addu      $v0, $v1, $zero
    /* 13F38 8007C738 FF118224 */  addiu      $v0, $a0, 0x11FF
  .L8007C73C:
    /* 13F3C 8007C73C 03130200 */  sra        $v0, $v0, 12
    /* 13F40 8007C740 00130200 */  sll        $v0, $v0, 12
    /* 13F44 8007C744 23206200 */  subu       $a0, $v1, $v0
    /* 13F48 8007C748 02008104 */  bgez       $a0, .L8007C754
    /* 13F4C 8007C74C 0F80053C */   lui       $a1, %hi(vs_battle_screenTransitionStep)
    /* 13F50 8007C750 FF038424 */  addiu      $a0, $a0, 0x3FF
  .L8007C754:
    /* 13F54 8007C754 01000624 */  addiu      $a2, $zero, 0x1
    /* 13F58 8007C758 0F80023C */  lui        $v0, %hi(vs_battle_screenTransitionEffect)
    /* 13F5C 8007C75C 981A54AC */  sw         $s4, %lo(vs_battle_screenTransitionEffect)($v0)
    /* 13F60 8007C760 4800A28F */  lw         $v0, 0x48($sp)
    /* 13F64 8007C764 0F80033C */  lui        $v1, %hi(vs_battle_screenTransitionSpeed)
    /* 13F68 8007C768 481AA6AC */  sw         $a2, %lo(vs_battle_screenTransitionStep)($a1)
    /* 13F6C 8007C76C A81A62AC */  sw         $v0, %lo(vs_battle_screenTransitionSpeed)($v1)
    /* 13F70 8007C770 C0180400 */  sll        $v1, $a0, 3
    /* 13F74 8007C774 04000296 */  lhu        $v0, 0x4($s0)
    /* 13F78 8007C778 00606330 */  andi       $v1, $v1, 0x6000
    /* 13F7C 8007C77C FF9F4230 */  andi       $v0, $v0, 0x9FFF
    /* 13F80 8007C780 25104300 */  or         $v0, $v0, $v1
    /* 13F84 8007C784 040002A6 */  sh         $v0, 0x4($s0)
    /* 13F88 8007C788 06000296 */  lhu        $v0, 0x6($s0)
    /* 13F8C 8007C78C B01A6392 */  lbu        $v1, %lo(D_800F1AB0)($s3)
    /* 13F90 8007C790 FF7F4230 */  andi       $v0, $v0, 0x7FFF
    /* 13F94 8007C794 07002312 */  beq        $s1, $v1, .L8007C7B4
    /* 13F98 8007C798 060002A6 */   sh        $v0, 0x6($s0)
    /* 13F9C 8007C79C 02000224 */  addiu      $v0, $zero, 0x2
    /* 13FA0 8007C7A0 481AA2AC */  sw         $v0, %lo(vs_battle_screenTransitionStep)($a1)
    /* 13FA4 8007C7A4 8223020C */  jal        _loadZnd
    /* 13FA8 8007C7A8 21202002 */   addu      $a0, $s1, $zero
    /* 13FAC 8007C7AC F5F10108 */  j          .L8007C7D4
    /* 13FB0 8007C7B0 0F80023C */   lui       $v0, %hi(D_800F1AB0)
  .L8007C7B4:
    /* 13FB4 8007C7B4 01000292 */  lbu        $v0, 0x1($s0)
    /* 13FB8 8007C7B8 00000000 */  nop
    /* 13FBC 8007C7BC 05004212 */  beq        $s2, $v0, .L8007C7D4
    /* 13FC0 8007C7C0 0F80023C */   lui       $v0, %hi(D_800F1AB0)
    /* 13FC4 8007C7C4 481AA6AC */  sw         $a2, %lo(vs_battle_screenTransitionStep)($a1)
    /* 13FC8 8007C7C8 4927020C */  jal        _loadMpd
    /* 13FCC 8007C7CC 21204002 */   addu      $a0, $s2, $zero
    /* 13FD0 8007C7D0 0F80023C */  lui        $v0, %hi(D_800F1AB0)
  .L8007C7D4:
    /* 13FD4 8007C7D4 B01A51A0 */  sb         $s1, %lo(D_800F1AB0)($v0)
    /* 13FD8 8007C7D8 B01A4224 */  addiu      $v0, $v0, %lo(D_800F1AB0)
    /* 13FDC 8007C7DC 94B0010C */  jal        func_8006C250
    /* 13FE0 8007C7E0 010052A0 */   sb        $s2, 0x1($v0)
    /* 13FE4 8007C7E4 21200000 */  addu       $a0, $zero, $zero
    /* 13FE8 8007C7E8 8782020C */  jal        func_800A0A1C
    /* 13FEC 8007C7EC 01000524 */   addiu     $a1, $zero, 0x1
    /* 13FF0 8007C7F0 3E2E020C */  jal        func_8008B8F8
    /* 13FF4 8007C7F4 21200000 */   addu      $a0, $zero, $zero
    /* 13FF8 8007C7F8 3400BF8F */  lw         $ra, 0x34($sp)
    /* 13FFC 8007C7FC 3000B48F */  lw         $s4, 0x30($sp)
    /* 14000 8007C800 2C00B38F */  lw         $s3, 0x2C($sp)
    /* 14004 8007C804 2800B28F */  lw         $s2, 0x28($sp)
    /* 14008 8007C808 2400B18F */  lw         $s1, 0x24($sp)
    /* 1400C 8007C80C 2000B08F */  lw         $s0, 0x20($sp)
    /* 14010 8007C810 01000224 */  addiu      $v0, $zero, 0x1
    /* 14014 8007C814 0800E003 */  jr         $ra
    /* 14018 8007C818 3800BD27 */   addiu     $sp, $sp, 0x38
endlabel func_8007C694
