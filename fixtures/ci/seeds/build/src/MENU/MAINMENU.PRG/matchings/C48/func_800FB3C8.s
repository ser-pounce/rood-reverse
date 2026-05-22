nonmatching func_800FB3C8, 0x79C

glabel func_800FB3C8
    /* 1BC8 800FB3C8 801F023C */  lui        $v0, (0x1F800004 >> 16)
    /* 1BCC 800FB3CC 0400428C */  lw         $v0, (0x1F800004 & 0xFFFF)($v0)
    /* 1BD0 800FB3D0 A8FFBD27 */  addiu      $sp, $sp, -0x58
    /* 1BD4 800FB3D4 4400B5AF */  sw         $s5, 0x44($sp)
    /* 1BD8 800FB3D8 4000B4AF */  sw         $s4, 0x40($sp)
    /* 1BDC 800FB3DC F4FF5424 */  addiu      $s4, $v0, -0xC
    /* 1BE0 800FB3E0 1080023C */  lui        $v0, %hi(D_801024B9)
    /* 1BE4 800FB3E4 B9244290 */  lbu        $v0, %lo(D_801024B9)($v0)
    /* 1BE8 800FB3E8 5400BFAF */  sw         $ra, 0x54($sp)
    /* 1BEC 800FB3EC 5000BEAF */  sw         $fp, 0x50($sp)
    /* 1BF0 800FB3F0 4C00B7AF */  sw         $s7, 0x4C($sp)
    /* 1BF4 800FB3F4 4800B6AF */  sw         $s6, 0x48($sp)
    /* 1BF8 800FB3F8 3C00B3AF */  sw         $s3, 0x3C($sp)
    /* 1BFC 800FB3FC 3800B2AF */  sw         $s2, 0x38($sp)
    /* 1C00 800FB400 3400B1AF */  sw         $s1, 0x34($sp)
    /* 1C04 800FB404 3000B0AF */  sw         $s0, 0x30($sp)
    /* 1C08 800FB408 1000A2AF */  sw         $v0, 0x10($sp)
    /* 1C0C 800FB40C 1000AC8F */  lw         $t4, 0x10($sp)
    /* 1C10 800FB410 01000224 */  addiu      $v0, $zero, 0x1
    /* 1C14 800FB414 14008211 */  beq        $t4, $v0, .L800FB468
    /* 1C18 800FB418 21A88000 */   addu      $s5, $a0, $zero
    /* 1C1C 800FB41C 02008229 */  slti       $v0, $t4, 0x2
    /* 1C20 800FB420 05004010 */  beqz       $v0, .L800FB438
    /* 1C24 800FB424 00000000 */   nop
    /* 1C28 800FB428 08008011 */  beqz       $t4, .L800FB44C
    /* 1C2C 800FB42C 1080023C */   lui       $v0, %hi(vs_mainMenu_equipmentStats)
    /* 1C30 800FB430 37ED0308 */  j          .L800FB4DC
    /* 1C34 800FB434 00000000 */   nop
  .L800FB438:
    /* 1C38 800FB438 02000224 */  addiu      $v0, $zero, 0x2
    /* 1C3C 800FB43C 23008211 */  beq        $t4, $v0, .L800FB4CC
    /* 1C40 800FB440 1080023C */   lui       $v0, %hi(D_80102502)
    /* 1C44 800FB444 37ED0308 */  j          .L800FB4DC
    /* 1C48 800FB448 00000000 */   nop
  .L800FB44C:
    /* 1C4C 800FB44C C0245724 */  addiu      $s7, $v0, %lo(vs_mainMenu_equipmentStats)
    /* 1C50 800FB450 1000EC26 */  addiu      $t4, $s7, 0x10
    /* 1C54 800FB454 2000ACAF */  sw         $t4, 0x20($sp)
    /* 1C58 800FB458 6000EC26 */  addiu      $t4, $s7, 0x60
    /* 1C5C 800FB45C 2400ACAF */  sw         $t4, 0x24($sp)
    /* 1C60 800FB460 36ED0308 */  j          .L800FB4D8
    /* 1C64 800FB464 60000C24 */   addiu     $t4, $zero, 0x60
  .L800FB468:
    /* 1C68 800FB468 1080023C */  lui        $v0, %hi(D_801024E0)
    /* 1C6C 800FB46C E0245724 */  addiu      $s7, $v0, %lo(D_801024E0)
    /* 1C70 800FB470 1000EC26 */  addiu      $t4, $s7, 0x10
    /* 1C74 800FB474 2000ACAF */  sw         $t4, 0x20($sp)
    /* 1C78 800FB478 5000EC26 */  addiu      $t4, $s7, 0x50
    /* 1C7C 800FB47C 2400ACAF */  sw         $t4, 0x24($sp)
    /* 1C80 800FB480 70000C24 */  addiu      $t4, $zero, 0x70
    /* 1C84 800FB484 21880000 */  addu       $s1, $zero, $zero
    /* 1C88 800FB488 E0244284 */  lh         $v0, %lo(D_801024E0)($v0)
    /* 1C8C 800FB48C 2120E002 */  addu       $a0, $s7, $zero
    /* 1C90 800FB490 1800ACAF */  sw         $t4, 0x18($sp)
    /* 1C94 800FB494 1C00A2AF */  sw         $v0, 0x1C($sp)
  .L800FB498:
    /* 1C98 800FB498 00008384 */  lh         $v1, 0x0($a0)
    /* 1C9C 800FB49C 1C00AC8F */  lw         $t4, 0x1C($sp)
    /* 1CA0 800FB4A0 00000000 */  nop
    /* 1CA4 800FB4A4 2A108301 */  slt        $v0, $t4, $v1
    /* 1CA8 800FB4A8 02004010 */  beqz       $v0, .L800FB4B4
    /* 1CAC 800FB4AC 00000000 */   nop
    /* 1CB0 800FB4B0 1C00A3AF */  sw         $v1, 0x1C($sp)
  .L800FB4B4:
    /* 1CB4 800FB4B4 01003126 */  addiu      $s1, $s1, 0x1
    /* 1CB8 800FB4B8 0700222A */  slti       $v0, $s1, 0x7
    /* 1CBC 800FB4BC F6FF4014 */  bnez       $v0, .L800FB498
    /* 1CC0 800FB4C0 02008424 */   addiu     $a0, $a0, 0x2
    /* 1CC4 800FB4C4 37ED0308 */  j          .L800FB4DC
    /* 1CC8 800FB4C8 00000000 */   nop
  .L800FB4CC:
    /* 1CCC 800FB4CC 02255724 */  addiu      $s7, $v0, %lo(D_80102502)
    /* 1CD0 800FB4D0 2000B7AF */  sw         $s7, 0x20($sp)
    /* 1CD4 800FB4D4 30000C24 */  addiu      $t4, $zero, 0x30
  .L800FB4D8:
    /* 1CD8 800FB4D8 1800ACAF */  sw         $t4, 0x18($sp)
  .L800FB4DC:
    /* 1CDC 800FB4DC 1800AC8F */  lw         $t4, 0x18($sp)
    /* 1CE0 800FB4E0 00000000 */  nop
    /* 1CE4 800FB4E4 50018019 */  blez       $t4, .L800FBA28
    /* 1CE8 800FB4E8 21B00000 */   addu      $s6, $zero, $zero
    /* 1CEC 800FB4EC 7400A226 */  addiu      $v0, $s5, 0x74
    /* 1CF0 800FB4F0 FFFF4230 */  andi       $v0, $v0, 0xFFFF
    /* 1CF4 800FB4F4 1400A2AF */  sw         $v0, 0x14($sp)
    /* 1CF8 800FB4F8 5800A226 */  addiu      $v0, $s5, 0x58
    /* 1CFC 800FB4FC FFFF4230 */  andi       $v0, $v0, 0xFFFF
    /* 1D00 800FB500 40001E3C */  lui        $fp, (0x400000 >> 16)
    /* 1D04 800FB504 2800A2AF */  sw         $v0, 0x28($sp)
  .L800FB508:
    /* 1D08 800FB508 1080023C */  lui        $v0, %hi(D_8010253E)
    /* 1D0C 800FB50C 3E254284 */  lh         $v0, %lo(D_8010253E)($v0)
    /* 1D10 800FB510 00000000 */  nop
    /* 1D14 800FB514 2E004010 */  beqz       $v0, .L800FB5D0
    /* 1D18 800FB518 03911600 */   sra       $s2, $s6, 4
    /* 1D1C 800FB51C 1080023C */  lui        $v0, %hi(D_80102544)
    /* 1D20 800FB520 44254390 */  lbu        $v1, %lo(D_80102544)($v0)
    /* 1D24 800FB524 07000224 */  addiu      $v0, $zero, 0x7
    /* 1D28 800FB528 2A006214 */  bne        $v1, $v0, .L800FB5D4
    /* 1D2C 800FB52C 8000113C */   lui       $s1, (0x808080 >> 16)
    /* 1D30 800FB530 1000AC8F */  lw         $t4, 0x10($sp)
    /* 1D34 800FB534 02000224 */  addiu      $v0, $zero, 0x2
    /* 1D38 800FB538 26008211 */  beq        $t4, $v0, .L800FB5D4
    /* 1D3C 800FB53C A400A526 */   addiu     $a1, $s5, 0xA4
    /* 1D40 800FB540 FFFFA530 */  andi       $a1, $a1, 0xFFFF
    /* 1D44 800FB544 2528BE00 */  or         $a1, $a1, $fp
    /* 1D48 800FB548 21300000 */  addu       $a2, $zero, $zero
    /* 1D4C 800FB54C 40101200 */  sll        $v0, $s2, 1
    /* 1D50 800FB550 2400AC8F */  lw         $t4, 0x24($sp)
    /* 1D54 800FB554 21805700 */  addu       $s0, $v0, $s7
    /* 1D58 800FB558 21984C00 */  addu       $s3, $v0, $t4
    /* 1D5C 800FB55C 00000286 */  lh         $v0, 0x0($s0)
    /* 1D60 800FB560 00006486 */  lh         $a0, 0x0($s3)
    /* 1D64 800FB564 21388002 */  addu       $a3, $s4, $zero
    /* 1D68 800FB568 88FF030C */  jal        func_800FFE20
    /* 1D6C 800FB56C 23204400 */   subu      $a0, $v0, $a0
    /* 1D70 800FB570 00000486 */  lh         $a0, 0x0($s0)
    /* 1D74 800FB574 00006386 */  lh         $v1, 0x0($s3)
    /* 1D78 800FB578 00000000 */  nop
    /* 1D7C 800FB57C 2A186400 */  slt        $v1, $v1, $a0
    /* 1D80 800FB580 08006010 */  beqz       $v1, .L800FB5A4
    /* 1D84 800FB584 21884000 */   addu      $s1, $v0, $zero
    /* 1D88 800FB588 1080043C */  lui        $a0, %hi(D_800F98A0)
    /* 1D8C 800FB58C A0988424 */  addiu      $a0, $a0, %lo(D_800F98A0)
    /* 1D90 800FB590 01002526 */  addiu      $a1, $s1, 0x1
    /* 1D94 800FB594 8000063C */  lui        $a2, (0x804020 >> 16)
    /* 1D98 800FB598 2040C634 */  ori        $a2, $a2, (0x804020 & 0xFFFF)
    /* 1D9C 800FB59C 5019030C */  jal        vs_battle_renderTextRawColor
    /* 1DA0 800FB5A0 21388002 */   addu      $a3, $s4, $zero
  .L800FB5A4:
    /* 1DA4 800FB5A4 00000386 */  lh         $v1, 0x0($s0)
    /* 1DA8 800FB5A8 00006286 */  lh         $v0, 0x0($s3)
    /* 1DAC 800FB5AC 00000000 */  nop
    /* 1DB0 800FB5B0 07006214 */  bne        $v1, $v0, .L800FB5D0
    /* 1DB4 800FB5B4 1080043C */   lui       $a0, %hi(D_800F98A4)
    /* 1DB8 800FB5B8 A4988424 */  addiu      $a0, $a0, %lo(D_800F98A4)
    /* 1DBC 800FB5BC 01002526 */  addiu      $a1, $s1, 0x1
    /* 1DC0 800FB5C0 8000063C */  lui        $a2, (0x808080 >> 16)
    /* 1DC4 800FB5C4 8080C634 */  ori        $a2, $a2, (0x808080 & 0xFFFF)
    /* 1DC8 800FB5C8 5019030C */  jal        vs_battle_renderTextRawColor
    /* 1DCC 800FB5CC 21388002 */   addu      $a3, $s4, $zero
  .L800FB5D0:
    /* 1DD0 800FB5D0 8000113C */  lui        $s1, (0x808080 >> 16)
  .L800FB5D4:
    /* 1DD4 800FB5D4 1080023C */  lui        $v0, %hi(vs_mainMenu_equipmentSubtype)
    /* 1DD8 800FB5D8 45254490 */  lbu        $a0, %lo(vs_mainMenu_equipmentSubtype)($v0)
    /* 1DDC 800FB5DC 01000224 */  addiu      $v0, $zero, 0x1
    /* 1DE0 800FB5E0 44008214 */  bne        $a0, $v0, .L800FB6F4
    /* 1DE4 800FB5E4 80803136 */   ori       $s1, $s1, (0x808080 & 0xFFFF)
    /* 1DE8 800FB5E8 1080023C */  lui        $v0, %hi(D_80102544)
    /* 1DEC 800FB5EC 44254390 */  lbu        $v1, %lo(D_80102544)($v0)
    /* 1DF0 800FB5F0 07000224 */  addiu      $v0, $zero, 0x7
    /* 1DF4 800FB5F4 40006214 */  bne        $v1, $v0, .L800FB6F8
    /* 1DF8 800FB5F8 40181200 */   sll       $v1, $s2, 1
    /* 1DFC 800FB5FC 1000AC8F */  lw         $t4, 0x10($sp)
    /* 1E00 800FB600 00000000 */  nop
    /* 1E04 800FB604 3C008011 */  beqz       $t4, .L800FB6F8
    /* 1E08 800FB608 00000000 */   nop
    /* 1E0C 800FB60C 29008415 */  bne        $t4, $a0, .L800FB6B4
    /* 1E10 800FB610 1080023C */   lui       $v0, %hi(D_80102508)
    /* 1E14 800FB614 2000AC8F */  lw         $t4, 0x20($sp)
    /* 1E18 800FB618 40101200 */  sll        $v0, $s2, 1
    /* 1E1C 800FB61C 21184C00 */  addu       $v1, $v0, $t4
    /* 1E20 800FB620 21105700 */  addu       $v0, $v0, $s7
    /* 1E24 800FB624 00006384 */  lh         $v1, 0x0($v1)
    /* 1E28 800FB628 00004284 */  lh         $v0, 0x0($v0)
    /* 1E2C 800FB62C 00000000 */  nop
    /* 1E30 800FB630 07006210 */  beq        $v1, $v0, .L800FB650
    /* 1E34 800FB634 2A106200 */   slt       $v0, $v1, $v0
    /* 1E38 800FB638 2000113C */  lui        $s1, (0x204080 >> 16)
    /* 1E3C 800FB63C 0A004010 */  beqz       $v0, .L800FB668
    /* 1E40 800FB640 80403136 */   ori       $s1, $s1, (0x204080 & 0xFFFF)
    /* 1E44 800FB644 8000113C */  lui        $s1, (0x804020 >> 16)
    /* 1E48 800FB648 9AED0308 */  j          .L800FB668
    /* 1E4C 800FB64C 20403136 */   ori       $s1, $s1, (0x804020 & 0xFFFF)
  .L800FB650:
    /* 1E50 800FB650 1C00AC8F */  lw         $t4, 0x1C($sp)
    /* 1E54 800FB654 00000000 */  nop
    /* 1E58 800FB658 04006C10 */  beq        $v1, $t4, .L800FB66C
    /* 1E5C 800FB65C 21302002 */   addu      $a2, $s1, $zero
    /* 1E60 800FB660 4000113C */  lui        $s1, (0x404040 >> 16)
    /* 1E64 800FB664 40403136 */  ori        $s1, $s1, (0x404040 & 0xFFFF)
  .L800FB668:
    /* 1E68 800FB668 21302002 */  addu       $a2, $s1, $zero
  .L800FB66C:
    /* 1E6C 800FB66C 21388002 */  addu       $a3, $s4, $zero
    /* 1E70 800FB670 40801200 */  sll        $s0, $s2, 1
    /* 1E74 800FB674 21801702 */  addu       $s0, $s0, $s7
    /* 1E78 800FB678 4000113C */  lui        $s1, (0x404040 >> 16)
    /* 1E7C 800FB67C 2800AC8F */  lw         $t4, 0x28($sp)
    /* 1E80 800FB680 00000486 */  lh         $a0, 0x0($s0)
    /* 1E84 800FB684 59FF030C */  jal        vs_mainMenu_renderIntColor
    /* 1E88 800FB688 25289E01 */   or        $a1, $t4, $fp
    /* 1E8C 800FB68C 00000286 */  lh         $v0, 0x0($s0)
    /* 1E90 800FB690 1C00AC8F */  lw         $t4, 0x1C($sp)
    /* 1E94 800FB694 00000000 */  nop
    /* 1E98 800FB698 20004C14 */  bne        $v0, $t4, .L800FB71C
    /* 1E9C 800FB69C 40403136 */   ori       $s1, $s1, (0x404040 & 0xFFFF)
    /* 1EA0 800FB6A0 8000113C */  lui        $s1, (0x808080 >> 16)
    /* 1EA4 800FB6A4 80803136 */  ori        $s1, $s1, (0x808080 & 0xFFFF)
    /* 1EA8 800FB6A8 FFFF0C34 */  ori        $t4, $zero, 0xFFFF
    /* 1EAC 800FB6AC C7ED0308 */  j          .L800FB71C
    /* 1EB0 800FB6B0 1C00ACAF */   sw        $t4, 0x1C($sp)
  .L800FB6B4:
    /* 1EB4 800FB6B4 08254284 */  lh         $v0, %lo(D_80102508)($v0)
    /* 1EB8 800FB6B8 00000000 */  nop
    /* 1EBC 800FB6BC FFFF4224 */  addiu      $v0, $v0, -0x1
    /* 1EC0 800FB6C0 03004212 */  beq        $s2, $v0, .L800FB6D0
    /* 1EC4 800FB6C4 40101200 */   sll       $v0, $s2, 1
    /* 1EC8 800FB6C8 4000113C */  lui        $s1, (0x404040 >> 16)
    /* 1ECC 800FB6CC 40403136 */  ori        $s1, $s1, (0x404040 & 0xFFFF)
  .L800FB6D0:
    /* 1ED0 800FB6D0 21105700 */  addu       $v0, $v0, $s7
    /* 1ED4 800FB6D4 21302002 */  addu       $a2, $s1, $zero
    /* 1ED8 800FB6D8 21388002 */  addu       $a3, $s4, $zero
    /* 1EDC 800FB6DC 2800AC8F */  lw         $t4, 0x28($sp)
    /* 1EE0 800FB6E0 00004484 */  lh         $a0, 0x0($v0)
    /* 1EE4 800FB6E4 59FF030C */  jal        vs_mainMenu_renderIntColor
    /* 1EE8 800FB6E8 25289E01 */   or        $a1, $t4, $fp
    /* 1EEC 800FB6EC C8ED0308 */  j          .L800FB720
    /* 1EF0 800FB6F0 4000A526 */   addiu     $a1, $s5, 0x40
  .L800FB6F4:
    /* 1EF4 800FB6F4 40181200 */  sll        $v1, $s2, 1
  .L800FB6F8:
    /* 1EF8 800FB6F8 2800AC8F */  lw         $t4, 0x28($sp)
    /* 1EFC 800FB6FC 21107700 */  addu       $v0, $v1, $s7
    /* 1F00 800FB700 25289E01 */  or         $a1, $t4, $fp
    /* 1F04 800FB704 2000AC8F */  lw         $t4, 0x20($sp)
    /* 1F08 800FB708 00004484 */  lh         $a0, 0x0($v0)
    /* 1F0C 800FB70C 21186C00 */  addu       $v1, $v1, $t4
    /* 1F10 800FB710 00006684 */  lh         $a2, 0x0($v1)
    /* 1F14 800FB714 88FF030C */  jal        func_800FFE20
    /* 1F18 800FB718 21388002 */   addu      $a3, $s4, $zero
  .L800FB71C:
    /* 1F1C 800FB71C 4000A526 */  addiu      $a1, $s5, 0x40
  .L800FB720:
    /* 1F20 800FB720 FFFFA530 */  andi       $a1, $a1, 0xFFFF
    /* 1F24 800FB724 2528BE00 */  or         $a1, $a1, $fp
    /* 1F28 800FB728 21302002 */  addu       $a2, $s1, $zero
    /* 1F2C 800FB72C 1080033C */  lui        $v1, %hi(D_80102068)
    /* 1F30 800FB730 1000AC8F */  lw         $t4, 0x10($sp)
    /* 1F34 800FB734 68206324 */  addiu      $v1, $v1, %lo(D_80102068)
    /* 1F38 800FB738 C0100C00 */  sll        $v0, $t4, 3
    /* 1F3C 800FB73C 21104202 */  addu       $v0, $s2, $v0
    /* 1F40 800FB740 80100200 */  sll        $v0, $v0, 2
    /* 1F44 800FB744 21104300 */  addu       $v0, $v0, $v1
    /* 1F48 800FB748 0000448C */  lw         $a0, 0x0($v0)
    /* 1F4C 800FB74C 5019030C */  jal        vs_battle_renderTextRawColor
    /* 1F50 800FB750 21388002 */   addu      $a3, $s4, $zero
    /* 1F54 800FB754 21208002 */  addu       $a0, $s4, $zero
    /* 1F58 800FB758 D040053C */  lui        $a1, (0x40D0E030 >> 16)
    /* 1F5C 800FB75C 30E0A534 */  ori        $a1, $a1, (0x40D0E030 & 0xFFFF)
    /* 1F60 800FB760 4200C626 */  addiu      $a2, $s6, 0x42
    /* 1F64 800FB764 00340600 */  sll        $a2, $a2, 16
    /* 1F68 800FB768 4500C726 */  addiu      $a3, $s6, 0x45
    /* 1F6C 800FB76C 1400AC8F */  lw         $t4, 0x14($sp)
    /* 1F70 800FB770 003C0700 */  sll        $a3, $a3, 16
    /* 1F74 800FB774 25308601 */  or         $a2, $t4, $a2
    /* 1F78 800FB778 2E33030C */  jal        func_800CCCB8
    /* 1F7C 800FB77C 25388701 */   or        $a3, $t4, $a3
    /* 1F80 800FB780 21208002 */  addu       $a0, $s4, $zero
    /* 1F84 800FB784 9740053C */  lui        $a1, (0x40978918 >> 16)
    /* 1F88 800FB788 1889A534 */  ori        $a1, $a1, (0x40978918 & 0xFFFF)
    /* 1F8C 800FB78C 4700C726 */  addiu      $a3, $s6, 0x47
    /* 1F90 800FB790 1400AC8F */  lw         $t4, 0x14($sp)
    /* 1F94 800FB794 003C0700 */  sll        $a3, $a3, 16
    /* 1F98 800FB798 25309E01 */  or         $a2, $t4, $fp
    /* 1F9C 800FB79C 2E33030C */  jal        func_800CCCB8
    /* 1FA0 800FB7A0 25388701 */   or        $a3, $t4, $a3
    /* 1FA4 800FB7A4 EB51043C */  lui        $a0, (0x51EB851F >> 16)
    /* 1FA8 800FB7A8 40101200 */  sll        $v0, $s2, 1
    /* 1FAC 800FB7AC 21105700 */  addu       $v0, $v0, $s7
    /* 1FB0 800FB7B0 00004384 */  lh         $v1, 0x0($v0)
    /* 1FB4 800FB7B4 1F858434 */  ori        $a0, $a0, (0x51EB851F & 0xFFFF)
    /* 1FB8 800FB7B8 40100300 */  sll        $v0, $v1, 1
    /* 1FBC 800FB7BC 21104300 */  addu       $v0, $v0, $v1
    /* 1FC0 800FB7C0 C0100200 */  sll        $v0, $v0, 3
    /* 1FC4 800FB7C4 18004400 */  mult       $v0, $a0
    /* 1FC8 800FB7C8 C3170200 */  sra        $v0, $v0, 31
    /* 1FCC 800FB7CC 10600000 */  mfhi       $t4
    /* 1FD0 800FB7D0 43190C00 */  sra        $v1, $t4, 5
    /* 1FD4 800FB7D4 23906200 */  subu       $s2, $v1, $v0
    /* 1FD8 800FB7D8 1900422A */  slti       $v0, $s2, 0x19
    /* 1FDC 800FB7DC 03004014 */  bnez       $v0, .L800FB7EC
    /* 1FE0 800FB7E0 E8FF422A */   slti      $v0, $s2, -0x18
    /* 1FE4 800FB7E4 18001224 */  addiu      $s2, $zero, 0x18
    /* 1FE8 800FB7E8 E8FF422A */  slti       $v0, $s2, -0x18
  .L800FB7EC:
    /* 1FEC 800FB7EC 02004010 */  beqz       $v0, .L800FB7F8
    /* 1FF0 800FB7F0 00000000 */   nop
    /* 1FF4 800FB7F4 E8FF1224 */  addiu      $s2, $zero, -0x18
  .L800FB7F8:
    /* 1FF8 800FB7F8 1A004006 */  bltz       $s2, .L800FB864
    /* 1FFC 800FB7FC 21880000 */   addu      $s1, $zero, $zero
    /* 2000 800FB800 1080023C */  lui        $v0, %hi(D_801020B4)
    /* 2004 800FB804 B4205024 */  addiu      $s0, $v0, %lo(D_801020B4)
  .L800FB808:
    /* 2008 800FB808 21208002 */  addu       $a0, $s4, $zero
    /* 200C 800FB80C 2110D102 */  addu       $v0, $s6, $s1
    /* 2010 800FB810 42004224 */  addiu      $v0, $v0, 0x42
    /* 2014 800FB814 00140200 */  sll        $v0, $v0, 16
    /* 2018 800FB818 2138B202 */  addu       $a3, $s5, $s2
    /* 201C 800FB81C 7400E724 */  addiu      $a3, $a3, 0x74
    /* 2020 800FB820 FFFFE730 */  andi       $a3, $a3, 0xFFFF
    /* 2024 800FB824 2538E200 */  or         $a3, $a3, $v0
    /* 2028 800FB828 1400AC8F */  lw         $t4, 0x14($sp)
    /* 202C 800FB82C 0000058E */  lw         $a1, 0x0($s0)
    /* 2030 800FB830 2E33030C */  jal        func_800CCCB8
    /* 2034 800FB834 25308201 */   or        $a2, $t4, $v0
    /* 2038 800FB838 18000224 */  addiu      $v0, $zero, 0x18
    /* 203C 800FB83C 23105100 */  subu       $v0, $v0, $s1
    /* 2040 800FB840 02004216 */  bne        $s2, $v0, .L800FB84C
    /* 2044 800FB844 00000000 */   nop
    /* 2048 800FB848 FFFF5226 */  addiu      $s2, $s2, -0x1
  .L800FB84C:
    /* 204C 800FB84C 01003126 */  addiu      $s1, $s1, 0x1
    /* 2050 800FB850 0400222A */  slti       $v0, $s1, 0x4
    /* 2054 800FB854 ECFF4014 */  bnez       $v0, .L800FB808
    /* 2058 800FB858 04001026 */   addiu     $s0, $s0, 0x4
    /* 205C 800FB85C 30EE0308 */  j          .L800FB8C0
    /* 2060 800FB860 02001224 */   addiu     $s2, $zero, 0x2
  .L800FB864:
    /* 2064 800FB864 1080023C */  lui        $v0, %hi(D_801020C4)
    /* 2068 800FB868 C4205024 */  addiu      $s0, $v0, %lo(D_801020C4)
  .L800FB86C:
    /* 206C 800FB86C 21208002 */  addu       $a0, $s4, $zero
    /* 2070 800FB870 2310D102 */  subu       $v0, $s6, $s1
    /* 2074 800FB874 45004224 */  addiu      $v0, $v0, 0x45
    /* 2078 800FB878 00140200 */  sll        $v0, $v0, 16
    /* 207C 800FB87C 2138B202 */  addu       $a3, $s5, $s2
    /* 2080 800FB880 7400E724 */  addiu      $a3, $a3, 0x74
    /* 2084 800FB884 FFFFE730 */  andi       $a3, $a3, 0xFFFF
    /* 2088 800FB888 2538E200 */  or         $a3, $a3, $v0
    /* 208C 800FB88C 1400AC8F */  lw         $t4, 0x14($sp)
    /* 2090 800FB890 0000058E */  lw         $a1, 0x0($s0)
    /* 2094 800FB894 2E33030C */  jal        func_800CCCB8
    /* 2098 800FB898 25308201 */   or        $a2, $t4, $v0
    /* 209C 800FB89C E8FF2226 */  addiu      $v0, $s1, -0x18
    /* 20A0 800FB8A0 02004216 */  bne        $s2, $v0, .L800FB8AC
    /* 20A4 800FB8A4 00000000 */   nop
    /* 20A8 800FB8A8 E9FF3226 */  addiu      $s2, $s1, -0x17
  .L800FB8AC:
    /* 20AC 800FB8AC 01003126 */  addiu      $s1, $s1, 0x1
    /* 20B0 800FB8B0 0400222A */  slti       $v0, $s1, 0x4
    /* 20B4 800FB8B4 EDFF4014 */  bnez       $v0, .L800FB86C
    /* 20B8 800FB8B8 04001026 */   addiu     $s0, $s0, 0x4
    /* 20BC 800FB8BC 02001224 */  addiu      $s2, $zero, 0x2
  .L800FB8C0:
    /* 20C0 800FB8C0 21208002 */  addu       $a0, $s4, $zero
  .L800FB8C4:
    /* 20C4 800FB8C4 3340053C */  lui        $a1, (0x40330500 >> 16)
    /* 20C8 800FB8C8 0005A534 */  ori        $a1, $a1, (0x40330500 & 0xFFFF)
    /* 20CC 800FB8CC 9FFF4626 */  addiu      $a2, $s2, -0x61
    /* 20D0 800FB8D0 2330A602 */  subu       $a2, $s5, $a2
    /* 20D4 800FB8D4 FFFFC630 */  andi       $a2, $a2, 0xFFFF
    /* 20D8 800FB8D8 2110D202 */  addu       $v0, $s6, $s2
    /* 20DC 800FB8DC 40004224 */  addiu      $v0, $v0, 0x40
    /* 20E0 800FB8E0 00140200 */  sll        $v0, $v0, 16
    /* 20E4 800FB8E4 2530C200 */  or         $a2, $a2, $v0
    /* 20E8 800FB8E8 72FF4726 */  addiu      $a3, $s2, -0x8E
    /* 20EC 800FB8EC 2338A702 */  subu       $a3, $s5, $a3
    /* 20F0 800FB8F0 FFFFE730 */  andi       $a3, $a3, 0xFFFF
    /* 20F4 800FB8F4 2E33030C */  jal        func_800CCCB8
    /* 20F8 800FB8F8 2538E200 */   or        $a3, $a3, $v0
    /* 20FC 800FB8FC 01005226 */  addiu      $s2, $s2, 0x1
    /* 2100 800FB900 0600422A */  slti       $v0, $s2, 0x6
    /* 2104 800FB904 EFFF4014 */  bnez       $v0, .L800FB8C4
    /* 2108 800FB908 21208002 */   addu      $a0, $s4, $zero
    /* 210C 800FB90C 21900000 */  addu       $s2, $zero, $zero
  .L800FB910:
    /* 2110 800FB910 5D40053C */  lui        $a1, (0x405D3200 >> 16)
    /* 2114 800FB914 0032A534 */  ori        $a1, $a1, (0x405D3200 & 0xFFFF)
    /* 2118 800FB918 9FFF4626 */  addiu      $a2, $s2, -0x61
    /* 211C 800FB91C 2330A602 */  subu       $a2, $s5, $a2
    /* 2120 800FB920 FFFFC630 */  andi       $a2, $a2, 0xFFFF
    /* 2124 800FB924 2110D202 */  addu       $v0, $s6, $s2
    /* 2128 800FB928 40004224 */  addiu      $v0, $v0, 0x40
    /* 212C 800FB92C 00140200 */  sll        $v0, $v0, 16
    /* 2130 800FB930 2530C200 */  or         $a2, $a2, $v0
    /* 2134 800FB934 6FFF4726 */  addiu      $a3, $s2, -0x91
    /* 2138 800FB938 2338A702 */  subu       $a3, $s5, $a3
    /* 213C 800FB93C FFFFE730 */  andi       $a3, $a3, 0xFFFF
    /* 2140 800FB940 2E33030C */  jal        func_800CCCB8
    /* 2144 800FB944 2538E200 */   or        $a3, $a3, $v0
    /* 2148 800FB948 01005226 */  addiu      $s2, $s2, 0x1
    /* 214C 800FB94C 0800422A */  slti       $v0, $s2, 0x8
    /* 2150 800FB950 EFFF4014 */  bnez       $v0, .L800FB910
    /* 2154 800FB954 21208002 */   addu      $a0, $s4, $zero
    /* 2158 800FB958 00E1043C */  lui        $a0, (0xE1000000 >> 16)
    /* 215C 800FB95C 4033030C */  jal        func_800CCD00
    /* 2160 800FB960 21288002 */   addu      $a1, $s4, $zero
    /* 2164 800FB964 801F023C */  lui        $v0, (0x1F800000 >> 16)
    /* 2168 800FB968 0000468C */  lw         $a2, (0x1F800000 & 0xFFFF)($v0)
    /* 216C 800FB96C 21900000 */  addu       $s2, $zero, $zero
    /* 2170 800FB970 FF000A3C */  lui        $t2, (0xFFFFFF >> 16)
    /* 2174 800FB974 FFFF4A35 */  ori        $t2, $t2, (0xFFFFFF & 0xFFFF)
    /* 2178 800FB978 00040B3C */  lui        $t3, (0x4000000 >> 16)
    /* 217C 800FB97C 3350093C */  lui        $t1, (0x50330500 >> 16)
    /* 2180 800FB980 00052935 */  ori        $t1, $t1, (0x50330500 & 0xFFFF)
    /* 2184 800FB984 FFFFA832 */  andi       $t0, $s5, 0xFFFF
    /* 2188 800FB988 5D00073C */  lui        $a3, (0x5D3200 >> 16)
    /* 218C 800FB98C 0032E734 */  ori        $a3, $a3, (0x5D3200 & 0xFFFF)
    /* 2190 800FB990 1000C524 */  addiu      $a1, $a2, 0x10
  .L800FB994:
    /* 2194 800FB994 2120D202 */  addu       $a0, $s6, $s2
    /* 2198 800FB998 A0FF4326 */  addiu      $v1, $s2, -0x60
    /* 219C 800FB99C 01005226 */  addiu      $s2, $s2, 0x1
    /* 21A0 800FB9A0 40008424 */  addiu      $a0, $a0, 0x40
    /* 21A4 800FB9A4 00240400 */  sll        $a0, $a0, 16
    /* 21A8 800FB9A8 2318A302 */  subu       $v1, $s5, $v1
    /* 21AC 800FB9AC FFFF6330 */  andi       $v1, $v1, 0xFFFF
    /* 21B0 800FB9B0 0000828E */  lw         $v0, 0x0($s4)
    /* 21B4 800FB9B4 25186400 */  or         $v1, $v1, $a0
    /* 21B8 800FB9B8 24104A00 */  and        $v0, $v0, $t2
    /* 21BC 800FB9BC 25104B00 */  or         $v0, $v0, $t3
    /* 21C0 800FB9C0 0000C2AC */  sw         $v0, 0x0($a2)
    /* 21C4 800FB9C4 25100401 */  or         $v0, $t0, $a0
    /* 21C8 800FB9C8 F4FFA9AC */  sw         $t1, -0xC($a1)
    /* 21CC 800FB9CC F8FFA2AC */  sw         $v0, -0x8($a1)
    /* 21D0 800FB9D0 FCFFA7AC */  sw         $a3, -0x4($a1)
    /* 21D4 800FB9D4 0000A3AC */  sw         $v1, 0x0($a1)
    /* 21D8 800FB9D8 1400A524 */  addiu      $a1, $a1, 0x14
    /* 21DC 800FB9DC 00120600 */  sll        $v0, $a2, 8
    /* 21E0 800FB9E0 02120200 */  srl        $v0, $v0, 8
    /* 21E4 800FB9E4 000082AE */  sw         $v0, 0x0($s4)
    /* 21E8 800FB9E8 0B00422A */  slti       $v0, $s2, 0xB
    /* 21EC 800FB9EC E9FF4014 */  bnez       $v0, .L800FB994
    /* 21F0 800FB9F0 1400C624 */   addiu     $a2, $a2, 0x14
    /* 21F4 800FB9F4 801F023C */  lui        $v0, (0x1F800000 >> 16)
    /* 21F8 800FB9F8 00E1043C */  lui        $a0, (0xE1000200 >> 16)
    /* 21FC 800FB9FC 00028434 */  ori        $a0, $a0, (0xE1000200 & 0xFFFF)
    /* 2200 800FBA00 21288002 */  addu       $a1, $s4, $zero
    /* 2204 800FBA04 4033030C */  jal        func_800CCD00
    /* 2208 800FBA08 000046AC */   sw        $a2, (0x1F800000 & 0xFFFF)($v0)
    /* 220C 800FBA0C 1000023C */  lui        $v0, (0x100000 >> 16)
    /* 2210 800FBA10 21F0C203 */  addu       $fp, $fp, $v0
    /* 2214 800FBA14 1800AC8F */  lw         $t4, 0x18($sp)
    /* 2218 800FBA18 1000D626 */  addiu      $s6, $s6, 0x10
    /* 221C 800FBA1C 2A10CC02 */  slt        $v0, $s6, $t4
    /* 2220 800FBA20 B9FE4014 */  bnez       $v0, .L800FB508
    /* 2224 800FBA24 00000000 */   nop
  .L800FBA28:
    /* 2228 800FBA28 1800A426 */  addiu      $a0, $s5, 0x18
    /* 222C 800FBA2C 30000524 */  addiu      $a1, $zero, 0x30
    /* 2230 800FBA30 87000624 */  addiu      $a2, $zero, 0x87
    /* 2234 800FBA34 D100040C */  jal        vs_mainMenu_drawButtonUiBackground
    /* 2238 800FBA38 0C000724 */   addiu     $a3, $zero, 0xC
    /* 223C 800FBA3C 01000424 */  addiu      $a0, $zero, 0x1
    /* 2240 800FBA40 1000A526 */  addiu      $a1, $s5, 0x10
    /* 2244 800FBA44 2E000624 */  addiu      $a2, $zero, 0x2E
    /* 2248 800FBA48 1AFF030C */  jal        vs_mainmenu_drawButton
    /* 224C 800FBA4C FCFF8726 */   addiu     $a3, $s4, -0x4
    /* 2250 800FBA50 FFFFA232 */  andi       $v0, $s5, 0xFFFF
    /* 2254 800FBA54 22005524 */  addiu      $s5, $v0, 0x22
    /* 2258 800FBA58 21900000 */  addu       $s2, $zero, $zero
    /* 225C 800FBA5C 1080023C */  lui        $v0, %hi(D_801020D4)
    /* 2260 800FBA60 D4204724 */  addiu      $a3, $v0, %lo(D_801020D4)
    /* 2264 800FBA64 1800053C */  lui        $a1, (0x180B01 >> 16)
    /* 2268 800FBA68 010BA534 */  ori        $a1, $a1, (0x180B01 & 0xFFFF)
    /* 226C 800FBA6C 1080063C */  lui        $a2, %hi(D_80102544)
    /* 2270 800FBA70 21200000 */  addu       $a0, $zero, $zero
  .L800FBA74:
    /* 2274 800FBA74 C0101200 */  sll        $v0, $s2, 3
    /* 2278 800FBA78 07104500 */  srav       $v0, $a1, $v0
    /* 227C 800FBA7C FF004230 */  andi       $v0, $v0, 0xFF
    /* 2280 800FBA80 4425C390 */  lbu        $v1, %lo(D_80102544)($a2)
    /* 2284 800FBA84 00000000 */  nop
    /* 2288 800FBA88 07184302 */  srav       $v1, $v1, $s2
    /* 228C 800FBA8C 01006330 */  andi       $v1, $v1, 0x1
    /* 2290 800FBA90 02006014 */  bnez       $v1, .L800FBA9C
    /* 2294 800FBA94 21104700 */   addu      $v0, $v0, $a3
    /* 2298 800FBA98 03000424 */  addiu      $a0, $zero, 0x3
  .L800FBA9C:
    /* 229C 800FBA9C 000044A0 */  sb         $a0, 0x0($v0)
    /* 22A0 800FBAA0 01005226 */  addiu      $s2, $s2, 0x1
    /* 22A4 800FBAA4 0300422A */  slti       $v0, $s2, 0x3
    /* 22A8 800FBAA8 F2FF4014 */  bnez       $v0, .L800FBA74
    /* 22AC 800FBAAC 21200000 */   addu      $a0, $zero, $zero
    /* 22B0 800FBAB0 1800033C */  lui        $v1, (0x180B01 >> 16)
    /* 22B4 800FBAB4 010B6334 */  ori        $v1, $v1, (0x180B01 & 0xFFFF)
    /* 22B8 800FBAB8 1080023C */  lui        $v0, %hi(D_801020D4)
    /* 22BC 800FBABC D4204224 */  addiu      $v0, $v0, %lo(D_801020D4)
    /* 22C0 800FBAC0 21804000 */  addu       $s0, $v0, $zero
    /* 22C4 800FBAC4 1080023C */  lui        $v0, %hi(D_801024B9)
    /* 22C8 800FBAC8 B9244290 */  lbu        $v0, %lo(D_801024B9)($v0)
    /* 22CC 800FBACC 1D001226 */  addiu      $s2, $s0, 0x1D
    /* 22D0 800FBAD0 C0100200 */  sll        $v0, $v0, 3
    /* 22D4 800FBAD4 07184300 */  srav       $v1, $v1, $v0
    /* 22D8 800FBAD8 FF006330 */  andi       $v1, $v1, 0xFF
    /* 22DC 800FBADC 21187000 */  addu       $v1, $v1, $s0
    /* 22E0 800FBAE0 01000224 */  addiu      $v0, $zero, 0x1
    /* 22E4 800FBAE4 000062A0 */  sb         $v0, 0x0($v1)
  .L800FBAE8:
    /* 22E8 800FBAE8 00001192 */  lbu        $s1, 0x0($s0)
    /* 22EC 800FBAEC FB000224 */  addiu      $v0, $zero, 0xFB
    /* 22F0 800FBAF0 07002216 */  bne        $s1, $v0, .L800FBB10
    /* 22F4 800FBAF4 21202002 */   addu      $a0, $s1, $zero
    /* 22F8 800FBAF8 01001026 */  addiu      $s0, $s0, 0x1
    /* 22FC 800FBAFC 00000492 */  lbu        $a0, 0x0($s0)
    /* 2300 800FBB00 841C030C */  jal        func_800C7210
    /* 2304 800FBB04 04008424 */   addiu     $a0, $a0, 0x4
    /* 2308 800FBB08 CAEE0308 */  j          .L800FBB28
    /* 230C 800FBB0C 01001026 */   addiu     $s0, $s0, 0x1
  .L800FBB10:
    /* 2310 800FBB10 2128A002 */  addu       $a1, $s5, $zero
    /* 2314 800FBB14 30000624 */  addiu      $a2, $zero, 0x30
    /* 2318 800FBB18 3E1C030C */  jal        vs_battle_printVariableWidthFontChar
    /* 231C 800FBB1C F0FF8726 */   addiu     $a3, $s4, -0x10
    /* 2320 800FBB20 21A84000 */  addu       $s5, $v0, $zero
    /* 2324 800FBB24 01001026 */  addiu      $s0, $s0, 0x1
  .L800FBB28:
    /* 2328 800FBB28 2A101202 */  slt        $v0, $s0, $s2
    /* 232C 800FBB2C EEFF4014 */  bnez       $v0, .L800FBAE8
    /* 2330 800FBB30 00000000 */   nop
    /* 2334 800FBB34 5400BF8F */  lw         $ra, 0x54($sp)
    /* 2338 800FBB38 5000BE8F */  lw         $fp, 0x50($sp)
    /* 233C 800FBB3C 4C00B78F */  lw         $s7, 0x4C($sp)
    /* 2340 800FBB40 4800B68F */  lw         $s6, 0x48($sp)
    /* 2344 800FBB44 4400B58F */  lw         $s5, 0x44($sp)
    /* 2348 800FBB48 4000B48F */  lw         $s4, 0x40($sp)
    /* 234C 800FBB4C 3C00B38F */  lw         $s3, 0x3C($sp)
    /* 2350 800FBB50 3800B28F */  lw         $s2, 0x38($sp)
    /* 2354 800FBB54 3400B18F */  lw         $s1, 0x34($sp)
    /* 2358 800FBB58 3000B08F */  lw         $s0, 0x30($sp)
    /* 235C 800FBB5C 0800E003 */  jr         $ra
    /* 2360 800FBB60 5800BD27 */   addiu     $sp, $sp, 0x58
endlabel func_800FB3C8
