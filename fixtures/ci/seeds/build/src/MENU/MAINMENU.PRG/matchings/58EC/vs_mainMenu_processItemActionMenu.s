nonmatching vs_mainMenu_processItemActionMenu, 0x5A8

glabel vs_mainMenu_processItemActionMenu
    /* 5C3C 800FF43C C8FFBD27 */  addiu      $sp, $sp, -0x38
    /* 5C40 800FF440 1000B0AF */  sw         $s0, 0x10($sp)
    /* 5C44 800FF444 1080103C */  lui        $s0, %hi(D_801022C4)
    /* 5C48 800FF448 C4220292 */  lbu        $v0, %lo(D_801022C4)($s0)
    /* 5C4C 800FF44C 2C00BEAF */  sw         $fp, 0x2C($sp)
    /* 5C50 800FF450 21F0A003 */  addu       $fp, $sp, $zero
    /* 5C54 800FF454 3000BFAF */  sw         $ra, 0x30($sp)
    /* 5C58 800FF458 2800B6AF */  sw         $s6, 0x28($sp)
    /* 5C5C 800FF45C 2400B5AF */  sw         $s5, 0x24($sp)
    /* 5C60 800FF460 2000B4AF */  sw         $s4, 0x20($sp)
    /* 5C64 800FF464 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 5C68 800FF468 1800B2AF */  sw         $s2, 0x18($sp)
    /* 5C6C 800FF46C 0A00422C */  sltiu      $v0, $v0, 0xA
    /* 5C70 800FF470 20004010 */  beqz       $v0, .L800FF4F4
    /* 5C74 800FF474 1400B1AF */   sw        $s1, 0x14($sp)
    /* 5C78 800FF478 C4220492 */  lbu        $a0, %lo(D_801022C4)($s0)
    /* 5C7C 800FF47C E2FC030C */  jal        func_800FF388
    /* 5C80 800FF480 3EFF0524 */   addiu     $a1, $zero, -0xC2
    /* 5C84 800FF484 21884000 */  addu       $s1, $v0, $zero
    /* 5C88 800FF488 05000224 */  addiu      $v0, $zero, 0x5
    /* 5C8C 800FF48C 1080043C */  lui        $a0, %hi(D_801022D1)
    /* 5C90 800FF490 000022A2 */  sb         $v0, 0x0($s1)
    /* 5C94 800FF494 C4220292 */  lbu        $v0, %lo(D_801022C4)($s0)
    /* 5C98 800FF498 D1228390 */  lbu        $v1, %lo(D_801022D1)($a0)
    /* 5C9C 800FF49C 180020A6 */  sh         $zero, 0x18($s1)
    /* 5CA0 800FF4A0 01004224 */  addiu      $v0, $v0, 0x1
    /* 5CA4 800FF4A4 C42202A2 */  sb         $v0, %lo(D_801022C4)($s0)
    /* 5CA8 800FF4A8 FF004230 */  andi       $v0, $v0, 0xFF
    /* 5CAC 800FF4AC 02004314 */  bne        $v0, $v1, .L800FF4B8
    /* 5CB0 800FF4B0 10000224 */   addiu     $v0, $zero, 0x10
    /* 5CB4 800FF4B4 C42202A2 */  sb         $v0, %lo(D_801022C4)($s0)
  .L800FF4B8:
    /* 5CB8 800FF4B8 C4220392 */  lbu        $v1, %lo(D_801022C4)($s0)
    /* 5CBC 800FF4BC 07000224 */  addiu      $v0, $zero, 0x7
    /* 5CC0 800FF4C0 3C016214 */  bne        $v1, $v0, .L800FF9B4
    /* 5CC4 800FF4C4 1080033C */   lui       $v1, %hi(D_801022D2)
    /* 5CC8 800FF4C8 C4220292 */  lbu        $v0, %lo(D_801022C4)($s0)
    /* 5CCC 800FF4CC D2226390 */  lbu        $v1, %lo(D_801022D2)($v1)
    /* 5CD0 800FF4D0 D1228490 */  lbu        $a0, %lo(D_801022D1)($a0)
    /* 5CD4 800FF4D4 21104300 */  addu       $v0, $v0, $v1
    /* 5CD8 800FF4D8 2A104400 */  slt        $v0, $v0, $a0
    /* 5CDC 800FF4DC 02004010 */  beqz       $v0, .L800FF4E8
    /* 5CE0 800FF4E0 02000224 */   addiu     $v0, $zero, 0x2
    /* 5CE4 800FF4E4 050022A2 */  sb         $v0, 0x5($s1)
  .L800FF4E8:
    /* 5CE8 800FF4E8 10000224 */  addiu      $v0, $zero, 0x10
    /* 5CEC 800FF4EC 6DFE0308 */  j          .L800FF9B4
    /* 5CF0 800FF4F0 C42202A2 */   sb        $v0, %lo(D_801022C4)($s0)
  .L800FF4F4:
    /* 5CF4 800FF4F4 1080133C */  lui        $s3, %hi(D_801022CC)
    /* 5CF8 800FF4F8 CC22648E */  lw         $a0, %lo(D_801022CC)($s3)
    /* 5CFC 800FF4FC 9223030C */  jal        vs_battle_getMenuItem
    /* 5D00 800FF500 20008424 */   addiu     $a0, $a0, 0x20
    /* 5D04 800FF504 21884000 */  addu       $s1, $v0, $zero
    /* 5D08 800FF508 1080143C */  lui        $s4, %hi(D_801022D2)
    /* 5D0C 800FF50C D2228292 */  lbu        $v0, %lo(D_801022D2)($s4)
    /* 5D10 800FF510 CC22648E */  lw         $a0, %lo(D_801022CC)($s3)
    /* 5D14 800FF514 1080123C */  lui        $s2, %hi(D_801022C8)
    /* 5D18 800FF518 21208200 */  addu       $a0, $a0, $v0
    /* 5D1C 800FF51C C0210400 */  sll        $a0, $a0, 7
    /* 5D20 800FF520 C822428E */  lw         $v0, %lo(D_801022C8)($s2)
    /* 5D24 800FF524 20008424 */  addiu      $a0, $a0, 0x20
    /* 5D28 800FF528 01FF030C */  jal        vs_mainmenu_setInformationMessage
    /* 5D2C 800FF52C 21204400 */   addu      $a0, $v0, $a0
    /* 5D30 800FF530 C4220392 */  lbu        $v1, %lo(D_801022C4)($s0)
    /* 5D34 800FF534 10000224 */  addiu      $v0, $zero, 0x10
    /* 5D38 800FF538 05006210 */  beq        $v1, $v0, .L800FF550
    /* 5D3C 800FF53C 11000224 */   addiu     $v0, $zero, 0x11
    /* 5D40 800FF540 09006210 */  beq        $v1, $v0, .L800FF568
    /* 5D44 800FF544 00000000 */   nop
    /* 5D48 800FF548 6DFE0308 */  j          .L800FF9B4
    /* 5D4C 800FF54C 00000000 */   nop
  .L800FF550:
    /* 5D50 800FF550 74EA030C */  jal        vs_mainmenu_ready
    /* 5D54 800FF554 00000000 */   nop
    /* 5D58 800FF558 16014010 */  beqz       $v0, .L800FF9B4
    /* 5D5C 800FF55C 11000224 */   addiu     $v0, $zero, 0x11
    /* 5D60 800FF560 6DFE0308 */  j          .L800FF9B4
    /* 5D64 800FF564 C42202A2 */   sb        $v0, %lo(D_801022C4)($s0)
  .L800FF568:
    /* 5D68 800FF568 D2228392 */  lbu        $v1, %lo(D_801022D2)($s4)
    /* 5D6C 800FF56C CC22628E */  lw         $v0, %lo(D_801022CC)($s3)
    /* 5D70 800FF570 00000000 */  nop
    /* 5D74 800FF574 21B04300 */  addu       $s6, $v0, $v1
    /* 5D78 800FF578 0680023C */  lui        $v0, %hi(vs_main_buttonsPressed)
    /* 5D7C 800FF57C D0E1448C */  lw         $a0, %lo(vs_main_buttonsPressed)($v0)
    /* 5D80 800FF580 00000000 */  nop
    /* 5D84 800FF584 10008230 */  andi       $v0, $a0, 0x10
    /* 5D88 800FF588 16004010 */  beqz       $v0, .L800FF5E4
    /* 5D8C 800FF58C 21A86000 */   addu      $s5, $v1, $zero
    /* 5D90 800FF590 C822448E */  lw         $a0, %lo(D_801022C8)($s2)
    /* 5D94 800FF594 180F010C */  jal        vs_main_freeHeapR
    /* 5D98 800FF598 00000000 */   nop
    /* 5D9C 800FF59C 0F80043C */  lui        $a0, %hi(D_800F4EE8)
    /* 5DA0 800FF5A0 1080053C */  lui        $a1, %hi(D_801022D0)
    /* 5DA4 800FF5A4 D022A290 */  lbu        $v0, %lo(D_801022D0)($a1)
    /* 5DA8 800FF5A8 CC226392 */  lbu        $v1, %lo(D_801022CC)($s3)
    /* 5DAC 800FF5AC E84E8424 */  addiu      $a0, $a0, %lo(D_800F4EE8)
    /* 5DB0 800FF5B0 C82240AE */  sw         $zero, %lo(D_801022C8)($s2)
    /* 5DB4 800FF5B4 40100200 */  sll        $v0, $v0, 1
    /* 5DB8 800FF5B8 21104400 */  addu       $v0, $v0, $a0
    /* 5DBC 800FF5BC 000043A0 */  sb         $v1, 0x0($v0)
    /* 5DC0 800FF5C0 D022A290 */  lbu        $v0, %lo(D_801022D0)($a1)
    /* 5DC4 800FF5C4 D2228392 */  lbu        $v1, %lo(D_801022D2)($s4)
    /* 5DC8 800FF5C8 40100200 */  sll        $v0, $v0, 1
    /* 5DCC 800FF5CC 01004224 */  addiu      $v0, $v0, 0x1
    /* 5DD0 800FF5D0 21104400 */  addu       $v0, $v0, $a0
    /* 5DD4 800FF5D4 000043A0 */  sb         $v1, 0x0($v0)
    /* 5DD8 800FF5D8 FDFF0224 */  addiu      $v0, $zero, -0x3
    /* 5DDC 800FF5DC 6DFE0308 */  j          .L800FF9B4
    /* 5DE0 800FF5E0 CC2262AE */   sw        $v0, %lo(D_801022CC)($s3)
  .L800FF5E4:
    /* 5DE4 800FF5E4 20008230 */  andi       $v0, $a0, 0x20
    /* 5DE8 800FF5E8 1D004010 */  beqz       $v0, .L800FF660
    /* 5DEC 800FF5EC 0680023C */   lui       $v0, %hi(vs_main_buttonsPressed)
    /* 5DF0 800FF5F0 07002292 */  lbu        $v0, 0x7($s1)
    /* 5DF4 800FF5F4 00000000 */  nop
    /* 5DF8 800FF5F8 16004014 */  bnez       $v0, .L800FF654
    /* 5DFC 800FF5FC 01000224 */   addiu     $v0, $zero, 0x1
    /* 5E00 800FF600 060022A2 */  sb         $v0, 0x6($s1)
    /* 5E04 800FF604 C822448E */  lw         $a0, %lo(D_801022C8)($s2)
    /* 5E08 800FF608 180F010C */  jal        vs_main_freeHeapR
    /* 5E0C 800FF60C 00000000 */   nop
    /* 5E10 800FF610 0F80043C */  lui        $a0, %hi(D_800F4EE8)
    /* 5E14 800FF614 1080053C */  lui        $a1, %hi(D_801022D0)
    /* 5E18 800FF618 D022A290 */  lbu        $v0, %lo(D_801022D0)($a1)
    /* 5E1C 800FF61C CC226392 */  lbu        $v1, %lo(D_801022CC)($s3)
    /* 5E20 800FF620 E84E8424 */  addiu      $a0, $a0, %lo(D_800F4EE8)
    /* 5E24 800FF624 C82240AE */  sw         $zero, %lo(D_801022C8)($s2)
    /* 5E28 800FF628 40100200 */  sll        $v0, $v0, 1
    /* 5E2C 800FF62C 21104400 */  addu       $v0, $v0, $a0
    /* 5E30 800FF630 000043A0 */  sb         $v1, 0x0($v0)
    /* 5E34 800FF634 D022A290 */  lbu        $v0, %lo(D_801022D0)($a1)
    /* 5E38 800FF638 D2228392 */  lbu        $v1, %lo(D_801022D2)($s4)
    /* 5E3C 800FF63C 40100200 */  sll        $v0, $v0, 1
    /* 5E40 800FF640 01004224 */  addiu      $v0, $v0, 0x1
    /* 5E44 800FF644 21104400 */  addu       $v0, $v0, $a0
    /* 5E48 800FF648 000043A0 */  sb         $v1, 0x0($v0)
    /* 5E4C 800FF64C 6DFE0308 */  j          .L800FF9B4
    /* 5E50 800FF650 CC2276AE */   sw        $s6, %lo(D_801022CC)($s3)
  .L800FF654:
    /* 5E54 800FF654 B800030C */  jal        vs_battle_playInvalidSfx
    /* 5E58 800FF658 00000000 */   nop
    /* 5E5C 800FF65C 0680023C */  lui        $v0, %hi(vs_main_buttonsPressed)
  .L800FF660:
    /* 5E60 800FF660 060020A2 */  sb         $zero, 0x6($s1)
    /* 5E64 800FF664 D0E1478C */  lw         $a3, %lo(vs_main_buttonsPressed)($v0)
    /* 5E68 800FF668 00000000 */  nop
    /* 5E6C 800FF66C 4000E230 */  andi       $v0, $a3, 0x40
    /* 5E70 800FF670 18004010 */  beqz       $v0, .L800FF6D4
    /* 5E74 800FF674 1080103C */   lui       $s0, %hi(D_801022C8)
    /* 5E78 800FF678 C822048E */  lw         $a0, %lo(D_801022C8)($s0)
    /* 5E7C 800FF67C 180F010C */  jal        vs_main_freeHeapR
    /* 5E80 800FF680 00000000 */   nop
    /* 5E84 800FF684 0F80043C */  lui        $a0, %hi(D_800F4EE8)
    /* 5E88 800FF688 1080053C */  lui        $a1, %hi(D_801022D0)
    /* 5E8C 800FF68C 1080063C */  lui        $a2, %hi(D_801022CC)
    /* 5E90 800FF690 D022A290 */  lbu        $v0, %lo(D_801022D0)($a1)
    /* 5E94 800FF694 CC22C390 */  lbu        $v1, %lo(D_801022CC)($a2)
    /* 5E98 800FF698 E84E8424 */  addiu      $a0, $a0, %lo(D_800F4EE8)
    /* 5E9C 800FF69C C82200AE */  sw         $zero, %lo(D_801022C8)($s0)
    /* 5EA0 800FF6A0 40100200 */  sll        $v0, $v0, 1
    /* 5EA4 800FF6A4 21104400 */  addu       $v0, $v0, $a0
    /* 5EA8 800FF6A8 000043A0 */  sb         $v1, 0x0($v0)
    /* 5EAC 800FF6AC 1080033C */  lui        $v1, %hi(D_801022D2)
    /* 5EB0 800FF6B0 D022A290 */  lbu        $v0, %lo(D_801022D0)($a1)
    /* 5EB4 800FF6B4 D2226390 */  lbu        $v1, %lo(D_801022D2)($v1)
    /* 5EB8 800FF6B8 40100200 */  sll        $v0, $v0, 1
    /* 5EBC 800FF6BC 01004224 */  addiu      $v0, $v0, 0x1
    /* 5EC0 800FF6C0 21104400 */  addu       $v0, $v0, $a0
    /* 5EC4 800FF6C4 000043A0 */  sb         $v1, 0x0($v0)
    /* 5EC8 800FF6C8 FEFF0224 */  addiu      $v0, $zero, -0x2
    /* 5ECC 800FF6CC 6DFE0308 */  j          .L800FF9B4
    /* 5ED0 800FF6D0 CC22C2AC */   sw        $v0, %lo(D_801022CC)($a2)
  .L800FF6D4:
    /* 5ED4 800FF6D4 0680023C */  lui        $v0, %hi(vs_main_buttonRepeat)
    /* 5ED8 800FF6D8 DCDF428C */  lw         $v0, %lo(vs_main_buttonRepeat)($v0)
    /* 5EDC 800FF6DC 00000000 */  nop
    /* 5EE0 800FF6E0 00104230 */  andi       $v0, $v0, 0x1000
    /* 5EE4 800FF6E4 29004010 */  beqz       $v0, .L800FF78C
    /* 5EE8 800FF6E8 1080043C */   lui       $a0, %hi(D_801022D1)
    /* 5EEC 800FF6EC D1228590 */  lbu        $a1, %lo(D_801022D1)($a0)
    /* 5EF0 800FF6F0 00000000 */  nop
    /* 5EF4 800FF6F4 0800A22C */  sltiu      $v0, $a1, 0x8
    /* 5EF8 800FF6F8 07004010 */  beqz       $v0, .L800FF718
    /* 5EFC 800FF6FC 1080033C */   lui       $v1, %hi(D_801022CC)
    /* 5F00 800FF700 CC22628C */  lw         $v0, %lo(D_801022CC)($v1)
    /* 5F04 800FF704 00000000 */  nop
    /* 5F08 800FF708 15004014 */  bnez       $v0, .L800FF760
    /* 5F0C 800FF70C FFFF4224 */   addiu     $v0, $v0, -0x1
    /* 5F10 800FF710 D7FD0308 */  j          .L800FF75C
    /* 5F14 800FF714 FF00A230 */   andi      $v0, $a1, 0xFF
  .L800FF718:
    /* 5F18 800FF718 1080063C */  lui        $a2, %hi(D_801022D2)
    /* 5F1C 800FF71C D222C490 */  lbu        $a0, %lo(D_801022D2)($a2)
    /* 5F20 800FF720 00000000 */  nop
    /* 5F24 800FF724 10008014 */  bnez       $a0, .L800FF768
    /* 5F28 800FF728 01000224 */   addiu     $v0, $zero, 0x1
    /* 5F2C 800FF72C 1080033C */  lui        $v1, %hi(D_801022CC)
    /* 5F30 800FF730 CC22628C */  lw         $v0, %lo(D_801022CC)($v1)
    /* 5F34 800FF734 00000000 */  nop
    /* 5F38 800FF738 09004014 */  bnez       $v0, .L800FF760
    /* 5F3C 800FF73C FFFF4224 */   addiu     $v0, $v0, -0x1
    /* 5F40 800FF740 0010E230 */  andi       $v0, $a3, 0x1000
    /* 5F44 800FF744 11004010 */  beqz       $v0, .L800FF78C
    /* 5F48 800FF748 06000224 */   addiu     $v0, $zero, 0x6
    /* 5F4C 800FF74C CC2262AC */  sw         $v0, %lo(D_801022CC)($v1)
    /* 5F50 800FF750 F9FFA224 */  addiu      $v0, $a1, -0x7
    /* 5F54 800FF754 E3FD0308 */  j          .L800FF78C
    /* 5F58 800FF758 D222C2A0 */   sb        $v0, %lo(D_801022D2)($a2)
  .L800FF75C:
    /* 5F5C 800FF75C FFFF4224 */  addiu      $v0, $v0, -0x1
  .L800FF760:
    /* 5F60 800FF760 E3FD0308 */  j          .L800FF78C
    /* 5F64 800FF764 CC2262AC */   sw        $v0, %lo(D_801022CC)($v1)
  .L800FF768:
    /* 5F68 800FF768 1080053C */  lui        $a1, %hi(D_801022CC)
    /* 5F6C 800FF76C CC22A38C */  lw         $v1, %lo(D_801022CC)($a1)
    /* 5F70 800FF770 00000000 */  nop
    /* 5F74 800FF774 04006214 */  bne        $v1, $v0, .L800FF788
    /* 5F78 800FF778 FFFF6224 */   addiu     $v0, $v1, -0x1
    /* 5F7C 800FF77C FFFF8224 */  addiu      $v0, $a0, -0x1
    /* 5F80 800FF780 E3FD0308 */  j          .L800FF78C
    /* 5F84 800FF784 D222C2A0 */   sb        $v0, %lo(D_801022D2)($a2)
  .L800FF788:
    /* 5F88 800FF788 CC22A2AC */  sw         $v0, %lo(D_801022CC)($a1)
  .L800FF78C:
    /* 5F8C 800FF78C 0680023C */  lui        $v0, %hi(vs_main_buttonRepeat)
    /* 5F90 800FF790 DCDF428C */  lw         $v0, %lo(vs_main_buttonRepeat)($v0)
    /* 5F94 800FF794 00000000 */  nop
    /* 5F98 800FF798 00404230 */  andi       $v0, $v0, 0x4000
    /* 5F9C 800FF79C 2B004010 */  beqz       $v0, .L800FF84C
    /* 5FA0 800FF7A0 1080033C */   lui       $v1, %hi(D_801022D1)
    /* 5FA4 800FF7A4 D1226290 */  lbu        $v0, %lo(D_801022D1)($v1)
    /* 5FA8 800FF7A8 00000000 */  nop
    /* 5FAC 800FF7AC 0800422C */  sltiu      $v0, $v0, 0x8
    /* 5FB0 800FF7B0 08004010 */  beqz       $v0, .L800FF7D4
    /* 5FB4 800FF7B4 1080043C */   lui       $a0, %hi(D_801022CC)
    /* 5FB8 800FF7B8 D1226290 */  lbu        $v0, %lo(D_801022D1)($v1)
    /* 5FBC 800FF7BC CC22838C */  lw         $v1, %lo(D_801022CC)($a0)
    /* 5FC0 800FF7C0 FFFF4224 */  addiu      $v0, $v0, -0x1
    /* 5FC4 800FF7C4 17006214 */  bne        $v1, $v0, .L800FF824
    /* 5FC8 800FF7C8 01006224 */   addiu     $v0, $v1, 0x1
    /* 5FCC 800FF7CC 13FE0308 */  j          .L800FF84C
    /* 5FD0 800FF7D0 CC2280AC */   sw        $zero, %lo(D_801022CC)($a0)
  .L800FF7D4:
    /* 5FD4 800FF7D4 1080063C */  lui        $a2, %hi(D_801022D2)
    /* 5FD8 800FF7D8 D1226290 */  lbu        $v0, %lo(D_801022D1)($v1)
    /* 5FDC 800FF7DC D222C490 */  lbu        $a0, %lo(D_801022D2)($a2)
    /* 5FE0 800FF7E0 F9FF4224 */  addiu      $v0, $v0, -0x7
    /* 5FE4 800FF7E4 11008214 */  bne        $a0, $v0, .L800FF82C
    /* 5FE8 800FF7E8 1080053C */   lui       $a1, %hi(D_801022CC)
    /* 5FEC 800FF7EC 1080043C */  lui        $a0, %hi(D_801022CC)
    /* 5FF0 800FF7F0 CC22838C */  lw         $v1, %lo(D_801022CC)($a0)
    /* 5FF4 800FF7F4 06000224 */  addiu      $v0, $zero, 0x6
    /* 5FF8 800FF7F8 0A006214 */  bne        $v1, $v0, .L800FF824
    /* 5FFC 800FF7FC 01006224 */   addiu     $v0, $v1, 0x1
    /* 6000 800FF800 0680023C */  lui        $v0, %hi(vs_main_buttonsPressed)
    /* 6004 800FF804 D0E1428C */  lw         $v0, %lo(vs_main_buttonsPressed)($v0)
    /* 6008 800FF808 00000000 */  nop
    /* 600C 800FF80C 00404230 */  andi       $v0, $v0, 0x4000
    /* 6010 800FF810 0F004010 */  beqz       $v0, .L800FF850
    /* 6014 800FF814 1080023C */   lui       $v0, %hi(D_801022CC)
    /* 6018 800FF818 CC2280AC */  sw         $zero, %lo(D_801022CC)($a0)
    /* 601C 800FF81C 14FE0308 */  j          .L800FF850
    /* 6020 800FF820 D222C0A0 */   sb        $zero, %lo(D_801022D2)($a2)
  .L800FF824:
    /* 6024 800FF824 13FE0308 */  j          .L800FF84C
    /* 6028 800FF828 CC2282AC */   sw        $v0, %lo(D_801022CC)($a0)
  .L800FF82C:
    /* 602C 800FF82C CC22A38C */  lw         $v1, %lo(D_801022CC)($a1)
    /* 6030 800FF830 05000224 */  addiu      $v0, $zero, 0x5
    /* 6034 800FF834 04006214 */  bne        $v1, $v0, .L800FF848
    /* 6038 800FF838 01006224 */   addiu     $v0, $v1, 0x1
    /* 603C 800FF83C 01008224 */  addiu      $v0, $a0, 0x1
    /* 6040 800FF840 13FE0308 */  j          .L800FF84C
    /* 6044 800FF844 D222C2A0 */   sb        $v0, %lo(D_801022D2)($a2)
  .L800FF848:
    /* 6048 800FF848 CC22A2AC */  sw         $v0, %lo(D_801022CC)($a1)
  .L800FF84C:
    /* 604C 800FF84C 1080023C */  lui        $v0, %hi(D_801022CC)
  .L800FF850:
    /* 6050 800FF850 1080103C */  lui        $s0, %hi(D_801022D2)
    /* 6054 800FF854 D2220392 */  lbu        $v1, %lo(D_801022D2)($s0)
    /* 6058 800FF858 CC22428C */  lw         $v0, %lo(D_801022CC)($v0)
    /* 605C 800FF85C 00000000 */  nop
    /* 6060 800FF860 21104300 */  addu       $v0, $v0, $v1
    /* 6064 800FF864 4600C212 */  beq        $s6, $v0, .L800FF980
    /* 6068 800FF868 1080023C */   lui       $v0, %hi(D_801022CC)
    /* 606C 800FF86C BE00030C */  jal        vs_battle_playMenuChangeSfx
    /* 6070 800FF870 00000000 */   nop
    /* 6074 800FF874 D2220292 */  lbu        $v0, %lo(D_801022D2)($s0)
    /* 6078 800FF878 00000000 */  nop
    /* 607C 800FF87C 3F005510 */  beq        $v0, $s5, .L800FF97C
    /* 6080 800FF880 21800000 */   addu      $s0, $zero, $zero
    /* 6084 800FF884 1080043C */  lui        $a0, %hi(D_801022D1)
    /* 6088 800FF888 D1228390 */  lbu        $v1, %lo(D_801022D1)($a0)
    /* 608C 800FF88C 21B0A003 */  addu       $s6, $sp, $zero
    /* 6090 800FF890 07006224 */  addiu      $v0, $v1, 0x7
    /* 6094 800FF894 F8014230 */  andi       $v0, $v0, 0x1F8
    /* 6098 800FF898 23E8A203 */  subu       $sp, $sp, $v0
    /* 609C 800FF89C 08006010 */  beqz       $v1, .L800FF8C0
    /* 60A0 800FF8A0 1000B227 */   addiu     $s2, $sp, 0x10
    /* 60A4 800FF8A4 21105002 */  addu       $v0, $s2, $s0
  .L800FF8A8:
    /* 60A8 800FF8A8 000040A0 */  sb         $zero, 0x0($v0)
    /* 60AC 800FF8AC D1228290 */  lbu        $v0, %lo(D_801022D1)($a0)
    /* 60B0 800FF8B0 01001026 */  addiu      $s0, $s0, 0x1
    /* 60B4 800FF8B4 2A100202 */  slt        $v0, $s0, $v0
    /* 60B8 800FF8B8 FBFF4014 */  bnez       $v0, .L800FF8A8
    /* 60BC 800FF8BC 21105002 */   addu      $v0, $s2, $s0
  .L800FF8C0:
    /* 60C0 800FF8C0 1080023C */  lui        $v0, %hi(D_801022D1)
    /* 60C4 800FF8C4 D1225190 */  lbu        $s1, %lo(D_801022D1)($v0)
    /* 60C8 800FF8C8 00000000 */  nop
    /* 60CC 800FF8CC 0800222E */  sltiu      $v0, $s1, 0x8
    /* 60D0 800FF8D0 02004014 */  bnez       $v0, .L800FF8DC
    /* 60D4 800FF8D4 00000000 */   nop
    /* 60D8 800FF8D8 07001124 */  addiu      $s1, $zero, 0x7
  .L800FF8DC:
    /* 60DC 800FF8DC 0B002012 */  beqz       $s1, .L800FF90C
    /* 60E0 800FF8E0 21800000 */   addu      $s0, $zero, $zero
  .L800FF8E4:
    /* 60E4 800FF8E4 9223030C */  jal        vs_battle_getMenuItem
    /* 60E8 800FF8E8 20000426 */   addiu     $a0, $s0, 0x20
    /* 60EC 800FF8EC 21181502 */  addu       $v1, $s0, $s5
    /* 60F0 800FF8F0 01001026 */  addiu      $s0, $s0, 0x1
    /* 60F4 800FF8F4 04004290 */  lbu        $v0, 0x4($v0)
    /* 60F8 800FF8F8 21184302 */  addu       $v1, $s2, $v1
    /* 60FC 800FF8FC 000062A0 */  sb         $v0, 0x0($v1)
    /* 6100 800FF900 2A101102 */  slt        $v0, $s0, $s1
    /* 6104 800FF904 F7FF4014 */  bnez       $v0, .L800FF8E4
    /* 6108 800FF908 00000000 */   nop
  .L800FF90C:
    /* 610C 800FF90C 21800000 */  addu       $s0, $zero, $zero
    /* 6110 800FF910 1080133C */  lui        $s3, %hi(D_801022D2)
    /* 6114 800FF914 1080153C */  lui        $s5, %hi(D_801022D1)
    /* 6118 800FF918 07001424 */  addiu      $s4, $zero, 0x7
    /* 611C 800FF91C 21200002 */  addu       $a0, $s0, $zero
  .L800FF920:
    /* 6120 800FF920 E2FC030C */  jal        func_800FF388
    /* 6124 800FF924 21280000 */   addu      $a1, $zero, $zero
    /* 6128 800FF928 D2226392 */  lbu        $v1, %lo(D_801022D2)($s3)
    /* 612C 800FF92C 00000000 */  nop
    /* 6130 800FF930 21180302 */  addu       $v1, $s0, $v1
    /* 6134 800FF934 21184302 */  addu       $v1, $s2, $v1
    /* 6138 800FF938 00006390 */  lbu        $v1, 0x0($v1)
    /* 613C 800FF93C 21884000 */  addu       $s1, $v0, $zero
    /* 6140 800FF940 040023A2 */  sb         $v1, 0x4($s1)
    /* 6144 800FF944 D122A392 */  lbu        $v1, %lo(D_801022D1)($s5)
    /* 6148 800FF948 01001026 */  addiu      $s0, $s0, 0x1
    /* 614C 800FF94C 0A000312 */  beq        $s0, $v1, .L800FF978
    /* 6150 800FF950 00000000 */   nop
    /* 6154 800FF954 F2FF1416 */  bne        $s0, $s4, .L800FF920
    /* 6158 800FF958 21200002 */   addu      $a0, $s0, $zero
    /* 615C 800FF95C D2226292 */  lbu        $v0, %lo(D_801022D2)($s3)
    /* 6160 800FF960 00000000 */  nop
    /* 6164 800FF964 07004224 */  addiu      $v0, $v0, 0x7
    /* 6168 800FF968 2A104300 */  slt        $v0, $v0, $v1
    /* 616C 800FF96C 02004010 */  beqz       $v0, .L800FF978
    /* 6170 800FF970 02000224 */   addiu     $v0, $zero, 0x2
    /* 6174 800FF974 050022A2 */  sb         $v0, 0x5($s1)
  .L800FF978:
    /* 6178 800FF978 21E8C002 */  addu       $sp, $s6, $zero
  .L800FF97C:
    /* 617C 800FF97C 1080023C */  lui        $v0, %hi(D_801022CC)
  .L800FF980:
    /* 6180 800FF980 CC22448C */  lw         $a0, %lo(D_801022CC)($v0)
    /* 6184 800FF984 9223030C */  jal        vs_battle_getMenuItem
    /* 6188 800FF988 20008424 */   addiu     $a0, $a0, 0x20
    /* 618C 800FF98C 21884000 */  addu       $s1, $v0, $zero
    /* 6190 800FF990 01000224 */  addiu      $v0, $zero, 0x1
    /* 6194 800FF994 16002586 */  lh         $a1, 0x16($s1)
    /* 6198 800FF998 1080103C */  lui        $s0, %hi(D_801022D3)
    /* 619C 800FF99C 060022A2 */  sb         $v0, 0x6($s1)
    /* 61A0 800FF9A0 D3220492 */  lbu        $a0, %lo(D_801022D3)($s0)
    /* 61A4 800FF9A4 F8FFA524 */  addiu      $a1, $a1, -0x8
    /* 61A8 800FF9A8 37FF030C */  jal        func_800FFCDC
    /* 61AC 800FF9AC 002C0500 */   sll       $a1, $a1, 16
    /* 61B0 800FF9B0 D32202A2 */  sb         $v0, %lo(D_801022D3)($s0)
  .L800FF9B4:
    /* 61B4 800FF9B4 21E8C003 */  addu       $sp, $fp, $zero
    /* 61B8 800FF9B8 3000BF8F */  lw         $ra, 0x30($sp)
    /* 61BC 800FF9BC 2C00BE8F */  lw         $fp, 0x2C($sp)
    /* 61C0 800FF9C0 2800B68F */  lw         $s6, 0x28($sp)
    /* 61C4 800FF9C4 2400B58F */  lw         $s5, 0x24($sp)
    /* 61C8 800FF9C8 2000B48F */  lw         $s4, 0x20($sp)
    /* 61CC 800FF9CC 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 61D0 800FF9D0 1800B28F */  lw         $s2, 0x18($sp)
    /* 61D4 800FF9D4 1400B18F */  lw         $s1, 0x14($sp)
    /* 61D8 800FF9D8 1000B08F */  lw         $s0, 0x10($sp)
    /* 61DC 800FF9DC 0800E003 */  jr         $ra
    /* 61E0 800FF9E0 3800BD27 */   addiu     $sp, $sp, 0x38
endlabel vs_mainMenu_processItemActionMenu
