nonmatching func_800AE6C0, 0x118

glabel func_800AE6C0
    /* 45EC0 800AE6C0 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 45EC4 800AE6C4 2000B2AF */  sw         $s2, 0x20($sp)
    /* 45EC8 800AE6C8 2190A000 */  addu       $s2, $a1, $zero
    /* 45ECC 800AE6CC 0F80033C */  lui        $v1, %hi(D_800F4538)
    /* 45ED0 800AE6D0 2400BFAF */  sw         $ra, 0x24($sp)
    /* 45ED4 800AE6D4 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 45ED8 800AE6D8 1800B0AF */  sw         $s0, 0x18($sp)
    /* 45EDC 800AE6DC 0F008490 */  lbu        $a0, 0xF($a0)
    /* 45EE0 800AE6E0 38456324 */  addiu      $v1, $v1, %lo(D_800F4538)
    /* 45EE4 800AE6E4 80100400 */  sll        $v0, $a0, 2
    /* 45EE8 800AE6E8 21104300 */  addu       $v0, $v0, $v1
    /* 45EEC 800AE6EC 0000508C */  lw         $s0, 0x0($v0)
    /* 45EF0 800AE6F0 00000000 */  nop
    /* 45EF4 800AE6F4 E4170392 */  lbu        $v1, 0x17E4($s0)
    /* 45EF8 800AE6F8 02000224 */  addiu      $v0, $zero, 0x2
    /* 45EFC 800AE6FC 05006214 */  bne        $v1, $v0, .L800AE714
    /* 45F00 800AE700 2188C000 */   addu      $s1, $a2, $zero
    /* 45F04 800AE704 80000224 */  addiu      $v0, $zero, 0x80
    /* 45F08 800AE708 1000A2AF */  sw         $v0, 0x10($sp)
    /* 45F0C 800AE70C E2B90208 */  j          .L800AE788
    /* 45F10 800AE710 1400A0AF */   sw        $zero, 0x14($sp)
  .L800AE714:
    /* 45F14 800AE714 3F00023C */  lui        $v0, (0x3F9F00 >> 16)
    /* 45F18 800AE718 0800038E */  lw         $v1, 0x8($s0)
    /* 45F1C 800AE71C 009F4234 */  ori        $v0, $v0, (0x3F9F00 & 0xFFFF)
    /* 45F20 800AE720 24186200 */  and        $v1, $v1, $v0
    /* 45F24 800AE724 00800234 */  ori        $v0, $zero, 0x8000
    /* 45F28 800AE728 04006210 */  beq        $v1, $v0, .L800AE73C
    /* 45F2C 800AE72C FF000524 */   addiu     $a1, $zero, 0xFF
    /* 45F30 800AE730 FC060626 */  addiu      $a2, $s0, 0x6FC
    /* 45F34 800AE734 A084020C */  jal        func_800A1280
    /* 45F38 800AE738 21380000 */   addu      $a3, $zero, $zero
  .L800AE73C:
    /* 45F3C 800AE73C FC06048E */  lw         $a0, 0x6FC($s0)
    /* 45F40 800AE740 00070586 */  lh         $a1, 0x700($s0)
    /* 45F44 800AE744 6B16010C */  jal        vs_main_computeSfxPan
    /* 45F48 800AE748 00000000 */   nop
    /* 45F4C 800AE74C 21184000 */  addu       $v1, $v0, $zero
    /* 45F50 800AE750 03140300 */  sra        $v0, $v1, 16
    /* 45F54 800AE754 1000A2AF */  sw         $v0, 0x10($sp)
    /* 45F58 800AE758 E5170292 */  lbu        $v0, 0x17E5($s0)
    /* 45F5C 800AE75C 00000000 */  nop
    /* 45F60 800AE760 02004010 */  beqz       $v0, .L800AE76C
    /* 45F64 800AE764 00000000 */   nop
    /* 45F68 800AE768 1000A2AF */  sw         $v0, 0x10($sp)
  .L800AE76C:
    /* 45F6C 800AE76C FFFF6230 */  andi       $v0, $v1, 0xFFFF
    /* 45F70 800AE770 1400A2AF */  sw         $v0, 0x14($sp)
    /* 45F74 800AE774 E6170292 */  lbu        $v0, 0x17E6($s0)
    /* 45F78 800AE778 00000000 */  nop
    /* 45F7C 800AE77C 02004010 */  beqz       $v0, .L800AE788
    /* 45F80 800AE780 00000000 */   nop
    /* 45F84 800AE784 1400A2AF */  sw         $v0, 0x14($sp)
  .L800AE788:
    /* 45F88 800AE788 1400A78F */  lw         $a3, 0x14($sp)
    /* 45F8C 800AE78C 00000000 */  nop
    /* 45F90 800AE790 0A00E010 */  beqz       $a3, .L800AE7BC
    /* 45F94 800AE794 7E000424 */   addiu     $a0, $zero, 0x7E
    /* 45F98 800AE798 1000A68F */  lw         $a2, 0x10($sp)
    /* 45F9C 800AE79C D515010C */  jal        vs_main_playSfx
    /* 45FA0 800AE7A0 21284002 */   addu      $a1, $s2, $zero
    /* 45FA4 800AE7A4 05002012 */  beqz       $s1, .L800AE7BC
    /* 45FA8 800AE7A8 7E000424 */   addiu     $a0, $zero, 0x7E
    /* 45FAC 800AE7AC 1000A68F */  lw         $a2, 0x10($sp)
    /* 45FB0 800AE7B0 1400A78F */  lw         $a3, 0x14($sp)
    /* 45FB4 800AE7B4 D515010C */  jal        vs_main_playSfx
    /* 45FB8 800AE7B8 21282002 */   addu      $a1, $s1, $zero
  .L800AE7BC:
    /* 45FBC 800AE7BC 2400BF8F */  lw         $ra, 0x24($sp)
    /* 45FC0 800AE7C0 2000B28F */  lw         $s2, 0x20($sp)
    /* 45FC4 800AE7C4 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 45FC8 800AE7C8 1800B08F */  lw         $s0, 0x18($sp)
    /* 45FCC 800AE7CC 2800BD27 */  addiu      $sp, $sp, 0x28
    /* 45FD0 800AE7D0 0800E003 */  jr         $ra
    /* 45FD4 800AE7D4 00000000 */   nop
endlabel func_800AE6C0
