nonmatching func_800D2698, 0xF4

glabel func_800D2698
    /* 69E98 800D2698 0F80033C */  lui        $v1, %hi(D_800F5600)
    /* 69E9C 800D269C 0056628C */  lw         $v0, %lo(D_800F5600)($v1)
    /* 69EA0 800D26A0 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 69EA4 800D26A4 1000B0AF */  sw         $s0, 0x10($sp)
    /* 69EA8 800D26A8 21808000 */  addu       $s0, $a0, $zero
    /* 69EAC 800D26AC 04004010 */  beqz       $v0, .L800D26C0
    /* 69EB0 800D26B0 1400BFAF */   sw        $ra, 0x14($sp)
    /* 69EB4 800D26B4 01004224 */  addiu      $v0, $v0, 0x1
    /* 69EB8 800D26B8 DF490308 */  j          .L800D277C
    /* 69EBC 800D26BC 005662AC */   sw        $v0, %lo(D_800F5600)($v1)
  .L800D26C0:
    /* 69EC0 800D26C0 00211000 */  sll        $a0, $s0, 4
    /* 69EC4 800D26C4 23209000 */  subu       $a0, $a0, $s0
    /* 69EC8 800D26C8 8F0F010C */  jal        vs_main_allocHeapR
    /* 69ECC 800D26CC C0200400 */   sll       $a0, $a0, 3
    /* 69ED0 800D26D0 01000724 */  addiu      $a3, $zero, 0x1
    /* 69ED4 800D26D4 0F80033C */  lui        $v1, %hi(D_800F55FC)
    /* 69ED8 800D26D8 21204000 */  addu       $a0, $v0, $zero
    /* 69EDC 800D26DC FC5564AC */  sw         $a0, %lo(D_800F55FC)($v1)
    /* 69EE0 800D26E0 78008324 */  addiu      $v1, $a0, 0x78
    /* 69EE4 800D26E4 FFFF0926 */  addiu      $t1, $s0, -0x1
    /* 69EE8 800D26E8 2A10E900 */  slt        $v0, $a3, $t1
    /* 69EEC 800D26EC 000080AC */  sw         $zero, 0x0($a0)
    /* 69EF0 800D26F0 0F004010 */  beqz       $v0, .L800D2730
    /* 69EF4 800D26F4 040083AC */   sw        $v1, 0x4($a0)
    /* 69EF8 800D26F8 21408000 */  addu       $t0, $a0, $zero
    /* 69EFC 800D26FC F0000624 */  addiu      $a2, $zero, 0xF0
    /* 69F00 800D2700 21206000 */  addu       $a0, $v1, $zero
    /* 69F04 800D2704 21280000 */  addu       $a1, $zero, $zero
  .L800D2708:
    /* 69F08 800D2708 21100601 */  addu       $v0, $t0, $a2
    /* 69F0C 800D270C 7800C624 */  addiu      $a2, $a2, 0x78
    /* 69F10 800D2710 21180501 */  addu       $v1, $t0, $a1
    /* 69F14 800D2714 000083AC */  sw         $v1, 0x0($a0)
    /* 69F18 800D2718 040082AC */  sw         $v0, 0x4($a0)
    /* 69F1C 800D271C 78008424 */  addiu      $a0, $a0, 0x78
    /* 69F20 800D2720 0100E724 */  addiu      $a3, $a3, 0x1
    /* 69F24 800D2724 2A10E900 */  slt        $v0, $a3, $t1
    /* 69F28 800D2728 F7FF4014 */  bnez       $v0, .L800D2708
    /* 69F2C 800D272C 7800A524 */   addiu     $a1, $a1, 0x78
  .L800D2730:
    /* 69F30 800D2730 0F80023C */  lui        $v0, %hi(D_800F55F8)
    /* 69F34 800D2734 F85540AC */  sw         $zero, %lo(D_800F55F8)($v0)
    /* 69F38 800D2738 0F80023C */  lui        $v0, %hi(D_800F55F0)
    /* 69F3C 800D273C 0F80033C */  lui        $v1, %hi(D_800F5600)
    /* 69F40 800D2740 F05550AC */  sw         $s0, %lo(D_800F55F0)($v0)
    /* 69F44 800D2744 01000224 */  addiu      $v0, $zero, 0x1
    /* 69F48 800D2748 005662AC */  sw         $v0, %lo(D_800F5600)($v1)
    /* 69F4C 800D274C 0F80033C */  lui        $v1, %hi(D_800F55FC)
    /* 69F50 800D2750 00110700 */  sll        $v0, $a3, 4
    /* 69F54 800D2754 23104700 */  subu       $v0, $v0, $a3
    /* 69F58 800D2758 FC55638C */  lw         $v1, %lo(D_800F55FC)($v1)
    /* 69F5C 800D275C C0100200 */  sll        $v0, $v0, 3
    /* 69F60 800D2760 21204300 */  addu       $a0, $v0, $v1
    /* 69F64 800D2764 88FF4224 */  addiu      $v0, $v0, -0x78
    /* 69F68 800D2768 21106200 */  addu       $v0, $v1, $v0
    /* 69F6C 800D276C 000082AC */  sw         $v0, 0x0($a0)
    /* 69F70 800D2770 0F80023C */  lui        $v0, %hi(D_800F55F4)
    /* 69F74 800D2774 040080AC */  sw         $zero, 0x4($a0)
    /* 69F78 800D2778 F45543AC */  sw         $v1, %lo(D_800F55F4)($v0)
  .L800D277C:
    /* 69F7C 800D277C 1400BF8F */  lw         $ra, 0x14($sp)
    /* 69F80 800D2780 1000B08F */  lw         $s0, 0x10($sp)
    /* 69F84 800D2784 0800E003 */  jr         $ra
    /* 69F88 800D2788 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800D2698
