nonmatching func_80073718, 0x158

glabel func_80073718
    /* AF18 80073718 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* AF1C 8007371C 0F80033C */  lui        $v1, %hi(D_800F196C)
    /* AF20 80073720 03000224 */  addiu      $v0, $zero, 0x3
    /* AF24 80073724 0F80043C */  lui        $a0, %hi(_cameraMode)
    /* AF28 80073728 6C1962AC */  sw         $v0, %lo(D_800F196C)($v1)
    /* AF2C 8007372C 0F80023C */  lui        $v0, %hi(vs_battle_characterState)
    /* AF30 80073730 FC19438C */  lw         $v1, %lo(vs_battle_characterState)($v0)
    /* AF34 80073734 02000224 */  addiu      $v0, $zero, 0x2
    /* AF38 80073738 1800BFAF */  sw         $ra, 0x18($sp)
    /* AF3C 8007373C 1400B1AF */  sw         $s1, 0x14($sp)
    /* AF40 80073740 1000B0AF */  sw         $s0, 0x10($sp)
    /* AF44 80073744 F01882AC */  sw         $v0, %lo(_cameraMode)($a0)
    /* AF48 80073748 20006590 */  lbu        $a1, 0x20($v1)
    /* AF4C 8007374C AC000424 */  addiu      $a0, $zero, 0xAC
    /* AF50 80073750 05FB020C */  jal        vs_battle_setStateFlag
    /* AF54 80073754 0100A530 */   andi      $a1, $a1, 0x1
    /* AF58 80073758 0F80023C */  lui        $v0, %hi(vs_battle_cameraCurrentSpherical)
    /* AF5C 8007375C D0195024 */  addiu      $s0, $v0, %lo(vs_battle_cameraCurrentSpherical)
    /* AF60 80073760 1400058E */  lw         $a1, 0x14($s0)
    /* AF64 80073764 00000000 */  nop
    /* AF68 80073768 0200A104 */  bgez       $a1, .L80073774
    /* AF6C 8007376C AF000424 */   addiu     $a0, $zero, 0xAF
    /* AF70 80073770 FF01A524 */  addiu      $a1, $a1, 0x1FF
  .L80073774:
    /* AF74 80073774 432A0500 */  sra        $a1, $a1, 9
    /* AF78 80073778 05FB020C */  jal        vs_battle_setStateFlag
    /* AF7C 8007377C 0700A530 */   andi      $a1, $a1, 0x7
    /* AF80 80073780 2000038E */  lw         $v1, 0x20($s0)
    /* AF84 80073784 00060224 */  addiu      $v0, $zero, 0x600
    /* AF88 80073788 03006214 */  bne        $v1, $v0, .L80073798
    /* AF8C 8007378C B0000424 */   addiu     $a0, $zero, 0xB0
    /* AF90 80073790 E7CD0108 */  j          .L8007379C
    /* AF94 80073794 21280000 */   addu      $a1, $zero, $zero
  .L80073798:
    /* AF98 80073798 01000524 */  addiu      $a1, $zero, 0x1
  .L8007379C:
    /* AF9C 8007379C 05FB020C */  jal        vs_battle_setStateFlag
    /* AFA0 800737A0 21880000 */   addu      $s1, $zero, $zero
    /* AFA4 800737A4 0F80023C */  lui        $v0, %hi(vs_battle_actors)
    /* AFA8 800737A8 28195024 */  addiu      $s0, $v0, %lo(vs_battle_actors)
  .L800737AC:
    /* AFAC 800737AC 0000028E */  lw         $v0, 0x0($s0)
    /* AFB0 800737B0 00000000 */  nop
    /* AFB4 800737B4 1F004010 */  beqz       $v0, .L80073834
    /* AFB8 800737B8 FEFF0524 */   addiu     $a1, $zero, -0x2
    /* AFBC 800737BC 21202002 */  addu       $a0, $s1, $zero
    /* AFC0 800737C0 21300000 */  addu       $a2, $zero, $zero
    /* AFC4 800737C4 187F020C */  jal        func_8009FC60
    /* AFC8 800737C8 FFFF0724 */   addiu     $a3, $zero, -0x1
    /* AFCC 800737CC 0000048E */  lw         $a0, 0x0($s0)
    /* AFD0 800737D0 00000000 */  nop
    /* AFD4 800737D4 08008390 */  lbu        $v1, 0x8($a0)
    /* AFD8 800737D8 20000224 */  addiu      $v0, $zero, 0x20
    /* AFDC 800737DC 15006210 */  beq        $v1, $v0, .L80073834
    /* AFE0 800737E0 21006228 */   slti      $v0, $v1, 0x21
    /* AFE4 800737E4 06004014 */  bnez       $v0, .L80073800
    /* AFE8 800737E8 10000224 */   addiu     $v0, $zero, 0x10
    /* AFEC 800737EC 40000224 */  addiu      $v0, $zero, 0x40
    /* AFF0 800737F0 05006214 */  bne        $v1, $v0, .L80073808
    /* AFF4 800737F4 10000224 */   addiu     $v0, $zero, 0x10
    /* AFF8 800737F8 0DCE0108 */  j          .L80073834
    /* AFFC 800737FC 080082A0 */   sb        $v0, 0x8($a0)
  .L80073800:
    /* B000 80073800 0C006210 */  beq        $v1, $v0, .L80073834
    /* B004 80073804 00000000 */   nop
  .L80073808:
    /* B008 80073808 0000028E */  lw         $v0, 0x0($s0)
    /* B00C 8007380C 00000000 */  nop
    /* B010 80073810 08004390 */  lbu        $v1, 0x8($v0)
    /* B014 80073814 80000224 */  addiu      $v0, $zero, 0x80
    /* B018 80073818 03006214 */  bne        $v1, $v0, .L80073828
    /* B01C 8007381C 00000000 */   nop
    /* B020 80073820 C099030C */  jal        func_800E6700
    /* B024 80073824 21202002 */   addu      $a0, $s1, $zero
  .L80073828:
    /* B028 80073828 0000028E */  lw         $v0, 0x0($s0)
    /* B02C 8007382C 00000000 */  nop
    /* B030 80073830 080040A0 */  sb         $zero, 0x8($v0)
  .L80073834:
    /* B034 80073834 01003126 */  addiu      $s1, $s1, 0x1
    /* B038 80073838 1000222A */  slti       $v0, $s1, 0x10
    /* B03C 8007383C DBFF4014 */  bnez       $v0, .L800737AC
    /* B040 80073840 04001026 */   addiu     $s0, $s0, 0x4
    /* B044 80073844 DC56020C */  jal        func_80095B70
    /* B048 80073848 01000424 */   addiu     $a0, $zero, 0x1
    /* B04C 8007384C 0F80023C */  lui        $v0, %hi(D_800F1858)
    /* B050 80073850 01000424 */  addiu      $a0, $zero, 0x1
    /* B054 80073854 6535020C */  jal        func_8008D594
    /* B058 80073858 581840AC */   sw        $zero, %lo(D_800F1858)($v0)
    /* B05C 8007385C 1800BF8F */  lw         $ra, 0x18($sp)
    /* B060 80073860 1400B18F */  lw         $s1, 0x14($sp)
    /* B064 80073864 1000B08F */  lw         $s0, 0x10($sp)
    /* B068 80073868 0800E003 */  jr         $ra
    /* B06C 8007386C 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_80073718
