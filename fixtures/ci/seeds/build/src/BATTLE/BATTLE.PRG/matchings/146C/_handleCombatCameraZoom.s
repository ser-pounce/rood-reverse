nonmatching _handleCombatCameraZoom, 0x29C

glabel _handleCombatCameraZoom
    /* FCAC 800784AC B0FFBD27 */  addiu      $sp, $sp, -0x50
    /* FCB0 800784B0 0F80023C */  lui        $v0, %hi(vs_battle_cameraCurrentSpherical)
    /* FCB4 800784B4 4000B0AF */  sw         $s0, 0x40($sp)
    /* FCB8 800784B8 D0195024 */  addiu      $s0, $v0, %lo(vs_battle_cameraCurrentSpherical)
    /* FCBC 800784BC 4800BFAF */  sw         $ra, 0x48($sp)
    /* FCC0 800784C0 4400B1AF */  sw         $s1, 0x44($sp)
    /* FCC4 800784C4 1C00048E */  lw         $a0, 0x1C($s0)
    /* FCC8 800784C8 01001124 */  addiu      $s1, $zero, 0x1
    /* FCCC 800784CC 03009110 */  beq        $a0, $s1, .L800784DC
    /* FCD0 800784D0 03000224 */   addiu     $v0, $zero, 0x3
    /* FCD4 800784D4 97008214 */  bne        $a0, $v0, .L80078734
    /* FCD8 800784D8 00000000 */   nop
  .L800784DC:
    /* FCDC 800784DC 0F80023C */  lui        $v0, %hi(D_800F19CC)
    /* FCE0 800784E0 CC19428C */  lw         $v0, %lo(D_800F19CC)($v0)
    /* FCE4 800784E4 00000000 */  nop
    /* FCE8 800784E8 0E2C4384 */  lh         $v1, 0x2C0E($v0)
    /* FCEC 800784EC 00000000 */  nop
    /* FCF0 800784F0 1D006014 */  bnez       $v1, .L80078568
    /* FCF4 800784F4 00000000 */   nop
    /* FCF8 800784F8 83E0010C */  jal        func_8007820C
    /* FCFC 800784FC 01000424 */   addiu     $a0, $zero, 0x1
    /* FD00 80078500 2AE0010C */  jal        func_800780A8
    /* FD04 80078504 1800A427 */   addiu     $a0, $sp, 0x18
    /* FD08 80078508 1800A427 */  addiu      $a0, $sp, 0x18
    /* FD0C 8007850C 3000A527 */  addiu      $a1, $sp, 0x30
    /* FD10 80078510 2000A627 */  addiu      $a2, $sp, 0x20
    /* FD14 80078514 01000724 */  addiu      $a3, $zero, 0x1
    /* FD18 80078518 28000224 */  addiu      $v0, $zero, 0x28
    /* FD1C 8007851C E6B6010C */  jal        _computeStepAndDisplacement
    /* FD20 80078520 1000A2AF */   sw        $v0, 0x10($sp)
    /* FD24 80078524 2000A28F */  lw         $v0, 0x20($sp)
    /* FD28 80078528 2400A38F */  lw         $v1, 0x24($sp)
    /* FD2C 8007852C 2800A48F */  lw         $a0, 0x28($sp)
    /* FD30 80078530 25104300 */  or         $v0, $v0, $v1
    /* FD34 80078534 25104400 */  or         $v0, $v0, $a0
    /* FD38 80078538 7E004014 */  bnez       $v0, .L80078734
    /* FD3C 8007853C 00000000 */   nop
    /* FD40 80078540 1000028E */  lw         $v0, 0x10($s0)
    /* FD44 80078544 00000000 */  nop
    /* FD48 80078548 7A004014 */  bnez       $v0, .L80078734
    /* FD4C 8007854C 00000000 */   nop
    /* FD50 80078550 1C00038E */  lw         $v1, 0x1C($s0)
    /* FD54 80078554 00000000 */  nop
    /* FD58 80078558 74007110 */  beq        $v1, $s1, .L8007872C
    /* FD5C 8007855C 03000224 */   addiu     $v0, $zero, 0x3
    /* FD60 80078560 BFE10108 */  j          .L800786FC
    /* FD64 80078564 00000000 */   nop
  .L80078568:
    /* FD68 80078568 37007114 */  bne        $v1, $s1, .L80078648
    /* FD6C 8007856C 02000224 */   addiu     $v0, $zero, 0x2
    /* FD70 80078570 83E0010C */  jal        func_8007820C
    /* FD74 80078574 01000424 */   addiu     $a0, $zero, 0x1
    /* FD78 80078578 0680033C */  lui        $v1, %hi(vs_main_projectionDistance)
    /* FD7C 8007857C 48E2628C */  lw         $v0, %lo(vs_main_projectionDistance)($v1)
    /* FD80 80078580 00000000 */  nop
    /* FD84 80078584 40004224 */  addiu      $v0, $v0, 0x40
    /* FD88 80078588 48E262AC */  sw         $v0, %lo(vs_main_projectionDistance)($v1)
    /* FD8C 8007858C 00034228 */  slti       $v0, $v0, 0x300
    /* FD90 80078590 02004014 */  bnez       $v0, .L8007859C
    /* FD94 80078594 00030224 */   addiu     $v0, $zero, 0x300
    /* FD98 80078598 48E262AC */  sw         $v0, %lo(vs_main_projectionDistance)($v1)
  .L8007859C:
    /* FD9C 8007859C 48E2648C */  lw         $a0, %lo(vs_main_projectionDistance)($v1)
    /* FDA0 800785A0 4D05010C */  jal        SetGeomScreen
    /* FDA4 800785A4 00000000 */   nop
    /* FDA8 800785A8 0800038E */  lw         $v1, 0x8($s0)
    /* FDAC 800785AC 00000000 */  nop
    /* FDB0 800785B0 01066228 */  slti       $v0, $v1, 0x601
    /* FDB4 800785B4 08004014 */  bnez       $v0, .L800785D8
    /* FDB8 800785B8 0680023C */   lui       $v0, %hi(vs_main_projectionDistance)
    /* FDBC 800785BC 40FF6224 */  addiu      $v0, $v1, -0xC0
    /* FDC0 800785C0 080002AE */  sw         $v0, 0x8($s0)
    /* FDC4 800785C4 00064228 */  slti       $v0, $v0, 0x600
    /* FDC8 800785C8 02004010 */  beqz       $v0, .L800785D4
    /* FDCC 800785CC 00060224 */   addiu     $v0, $zero, 0x600
    /* FDD0 800785D0 080002AE */  sw         $v0, 0x8($s0)
  .L800785D4:
    /* FDD4 800785D4 0680023C */  lui        $v0, %hi(vs_main_projectionDistance)
  .L800785D8:
    /* FDD8 800785D8 48E2438C */  lw         $v1, %lo(vs_main_projectionDistance)($v0)
    /* FDDC 800785DC 00030224 */  addiu      $v0, $zero, 0x300
    /* FDE0 800785E0 54006214 */  bne        $v1, $v0, .L80078734
    /* FDE4 800785E4 00000000 */   nop
    /* FDE8 800785E8 2AE0010C */  jal        func_800780A8
    /* FDEC 800785EC 1800A427 */   addiu     $a0, $sp, 0x18
    /* FDF0 800785F0 1800A427 */  addiu      $a0, $sp, 0x18
    /* FDF4 800785F4 3000A527 */  addiu      $a1, $sp, 0x30
    /* FDF8 800785F8 2000A627 */  addiu      $a2, $sp, 0x20
    /* FDFC 800785FC 01000724 */  addiu      $a3, $zero, 0x1
    /* FE00 80078600 28000224 */  addiu      $v0, $zero, 0x28
    /* FE04 80078604 E6B6010C */  jal        _computeStepAndDisplacement
    /* FE08 80078608 1000A2AF */   sw        $v0, 0x10($sp)
    /* FE0C 8007860C 2000A28F */  lw         $v0, 0x20($sp)
    /* FE10 80078610 2400A38F */  lw         $v1, 0x24($sp)
    /* FE14 80078614 2800A48F */  lw         $a0, 0x28($sp)
    /* FE18 80078618 25104300 */  or         $v0, $v0, $v1
    /* FE1C 8007861C 25104400 */  or         $v0, $v0, $a0
    /* FE20 80078620 44004014 */  bnez       $v0, .L80078734
    /* FE24 80078624 0F80023C */   lui       $v0, %hi(vs_battle_cameraCurrentSpherical)
    /* FE28 80078628 D0194324 */  addiu      $v1, $v0, %lo(vs_battle_cameraCurrentSpherical)
    /* FE2C 8007862C 1000628C */  lw         $v0, 0x10($v1)
    /* FE30 80078630 00000000 */  nop
    /* FE34 80078634 3F004014 */  bnez       $v0, .L80078734
    /* FE38 80078638 01000224 */   addiu     $v0, $zero, 0x1
    /* FE3C 8007863C 1C00638C */  lw         $v1, 0x1C($v1)
    /* FE40 80078640 BCE10108 */  j          .L800786F0
    /* FE44 80078644 00000000 */   nop
  .L80078648:
    /* FE48 80078648 30006214 */  bne        $v1, $v0, .L8007870C
    /* FE4C 8007864C 00000000 */   nop
    /* FE50 80078650 83E0010C */  jal        func_8007820C
    /* FE54 80078654 01000424 */   addiu     $a0, $zero, 0x1
    /* FE58 80078658 0800038E */  lw         $v1, 0x8($s0)
    /* FE5C 8007865C 00000000 */  nop
    /* FE60 80078660 00096228 */  slti       $v0, $v1, 0x900
    /* FE64 80078664 07004010 */  beqz       $v0, .L80078684
    /* FE68 80078668 C0006224 */   addiu     $v0, $v1, 0xC0
    /* FE6C 8007866C 080002AE */  sw         $v0, 0x8($s0)
    /* FE70 80078670 01094228 */  slti       $v0, $v0, 0x901
    /* FE74 80078674 04004014 */  bnez       $v0, .L80078688
    /* FE78 80078678 0F80023C */   lui       $v0, %hi(vs_battle_cameraCurrentSpherical)
    /* FE7C 8007867C 00090224 */  addiu      $v0, $zero, 0x900
    /* FE80 80078680 080002AE */  sw         $v0, 0x8($s0)
  .L80078684:
    /* FE84 80078684 0F80023C */  lui        $v0, %hi(vs_battle_cameraCurrentSpherical)
  .L80078688:
    /* FE88 80078688 D0195024 */  addiu      $s0, $v0, %lo(vs_battle_cameraCurrentSpherical)
    /* FE8C 8007868C 0800038E */  lw         $v1, 0x8($s0)
    /* FE90 80078690 00090224 */  addiu      $v0, $zero, 0x900
    /* FE94 80078694 27006214 */  bne        $v1, $v0, .L80078734
    /* FE98 80078698 00000000 */   nop
    /* FE9C 8007869C 2AE0010C */  jal        func_800780A8
    /* FEA0 800786A0 1800A427 */   addiu     $a0, $sp, 0x18
    /* FEA4 800786A4 1800A427 */  addiu      $a0, $sp, 0x18
    /* FEA8 800786A8 3000A527 */  addiu      $a1, $sp, 0x30
    /* FEAC 800786AC 2000A627 */  addiu      $a2, $sp, 0x20
    /* FEB0 800786B0 01000724 */  addiu      $a3, $zero, 0x1
    /* FEB4 800786B4 28000224 */  addiu      $v0, $zero, 0x28
    /* FEB8 800786B8 E6B6010C */  jal        _computeStepAndDisplacement
    /* FEBC 800786BC 1000A2AF */   sw        $v0, 0x10($sp)
    /* FEC0 800786C0 2000A28F */  lw         $v0, 0x20($sp)
    /* FEC4 800786C4 2400A38F */  lw         $v1, 0x24($sp)
    /* FEC8 800786C8 2800A48F */  lw         $a0, 0x28($sp)
    /* FECC 800786CC 25104300 */  or         $v0, $v0, $v1
    /* FED0 800786D0 25104400 */  or         $v0, $v0, $a0
    /* FED4 800786D4 17004014 */  bnez       $v0, .L80078734
    /* FED8 800786D8 00000000 */   nop
    /* FEDC 800786DC 1000028E */  lw         $v0, 0x10($s0)
    /* FEE0 800786E0 00000000 */  nop
    /* FEE4 800786E4 13004014 */  bnez       $v0, .L80078734
    /* FEE8 800786E8 01000224 */   addiu     $v0, $zero, 0x1
    /* FEEC 800786EC 1C00038E */  lw         $v1, 0x1C($s0)
  .L800786F0:
    /* FEF0 800786F0 00000000 */  nop
    /* FEF4 800786F4 0D006210 */  beq        $v1, $v0, .L8007872C
    /* FEF8 800786F8 03000224 */   addiu     $v0, $zero, 0x3
  .L800786FC:
    /* FEFC 800786FC 0B006210 */  beq        $v1, $v0, .L8007872C
    /* FF00 80078700 00000000 */   nop
    /* FF04 80078704 CDE10108 */  j          .L80078734
    /* FF08 80078708 00000000 */   nop
  .L8007870C:
    /* FF0C 8007870C 1000028E */  lw         $v0, 0x10($s0)
    /* FF10 80078710 00000000 */  nop
    /* FF14 80078714 07004014 */  bnez       $v0, .L80078734
    /* FF18 80078718 00000000 */   nop
    /* FF1C 8007871C 03009110 */  beq        $a0, $s1, .L8007872C
    /* FF20 80078720 03000224 */   addiu     $v0, $zero, 0x3
    /* FF24 80078724 03008214 */  bne        $a0, $v0, .L80078734
    /* FF28 80078728 00000000 */   nop
  .L8007872C:
    /* FF2C 8007872C E3C4010C */  jal        func_8007138C
    /* FF30 80078730 00000000 */   nop
  .L80078734:
    /* FF34 80078734 4800BF8F */  lw         $ra, 0x48($sp)
    /* FF38 80078738 4400B18F */  lw         $s1, 0x44($sp)
    /* FF3C 8007873C 4000B08F */  lw         $s0, 0x40($sp)
    /* FF40 80078740 0800E003 */  jr         $ra
    /* FF44 80078744 5000BD27 */   addiu     $sp, $sp, 0x50
endlabel _handleCombatCameraZoom
