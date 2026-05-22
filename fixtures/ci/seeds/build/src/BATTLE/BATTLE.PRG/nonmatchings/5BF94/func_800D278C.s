nonmatching func_800D278C, 0x64

glabel func_800D278C
    /* 69F8C 800D278C E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 69F90 800D2790 1000B0AF */  sw         $s0, 0x10($sp)
    /* 69F94 800D2794 0F80103C */  lui        $s0, %hi(D_800F5600)
    /* 69F98 800D2798 0056038E */  lw         $v1, %lo(D_800F5600)($s0)
    /* 69F9C 800D279C 01000224 */  addiu      $v0, $zero, 0x1
    /* 69FA0 800D27A0 1800BFAF */  sw         $ra, 0x18($sp)
    /* 69FA4 800D27A4 0B006214 */  bne        $v1, $v0, .L800D27D4
    /* 69FA8 800D27A8 1400B1AF */   sw        $s1, 0x14($sp)
    /* 69FAC 800D27AC 0F80113C */  lui        $s1, %hi(D_800F55FC)
    /* 69FB0 800D27B0 FC55248E */  lw         $a0, %lo(D_800F55FC)($s1)
    /* 69FB4 800D27B4 00000000 */  nop
    /* 69FB8 800D27B8 04008010 */  beqz       $a0, .L800D27CC
    /* 69FBC 800D27BC 00000000 */   nop
    /* 69FC0 800D27C0 180F010C */  jal        vs_main_freeHeapR
    /* 69FC4 800D27C4 00000000 */   nop
    /* 69FC8 800D27C8 FC5520AE */  sw         $zero, %lo(D_800F55FC)($s1)
  .L800D27CC:
    /* 69FCC 800D27CC F7490308 */  j          .L800D27DC
    /* 69FD0 800D27D0 005600AE */   sw        $zero, %lo(D_800F5600)($s0)
  .L800D27D4:
    /* 69FD4 800D27D4 FFFF6224 */  addiu      $v0, $v1, -0x1
    /* 69FD8 800D27D8 005602AE */  sw         $v0, %lo(D_800F5600)($s0)
  .L800D27DC:
    /* 69FDC 800D27DC 1800BF8F */  lw         $ra, 0x18($sp)
    /* 69FE0 800D27E0 1400B18F */  lw         $s1, 0x14($sp)
    /* 69FE4 800D27E4 1000B08F */  lw         $s0, 0x10($sp)
    /* 69FE8 800D27E8 0800E003 */  jr         $ra
    /* 69FEC 800D27EC 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_800D278C
