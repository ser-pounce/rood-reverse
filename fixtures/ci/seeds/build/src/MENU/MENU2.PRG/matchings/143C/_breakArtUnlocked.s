nonmatching _breakArtUnlocked, 0x19C

glabel _breakArtUnlocked
    /* 143C 80103C3C E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 1440 80103C40 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 1444 80103C44 1800B2AF */  sw         $s2, 0x18($sp)
    /* 1448 80103C48 1400B1AF */  sw         $s1, 0x14($sp)
    /* 144C 80103C4C 49008010 */  beqz       $a0, .L80103D74
    /* 1450 80103C50 1000B0AF */   sw        $s0, 0x10($sp)
    /* 1454 80103C54 0F80023C */  lui        $v0, %hi(vs_battle_characterState)
    /* 1458 80103C58 FC19428C */  lw         $v0, %lo(vs_battle_characterState)($v0)
    /* 145C 80103C5C 6666033C */  lui        $v1, (0x66666667 >> 16)
    /* 1460 80103C60 25005090 */  lbu        $s0, 0x25($v0)
    /* 1464 80103C64 67666334 */  ori        $v1, $v1, (0x66666667 & 0xFFFF)
    /* 1468 80103C68 18000302 */  mult       $s0, $v1
    /* 146C 80103C6C 0680023C */  lui        $v0, %hi(vs_main_artsStatus)
    /* 1470 80103C70 40004424 */  addiu      $a0, $v0, %lo(vs_main_artsStatus)
    /* 1474 80103C74 C3171000 */  sra        $v0, $s0, 31
    /* 1478 80103C78 10380000 */  mfhi       $a3
    /* 147C 80103C7C 83180700 */  sra        $v1, $a3, 2
    /* 1480 80103C80 23186200 */  subu       $v1, $v1, $v0
    /* 1484 80103C84 80100300 */  sll        $v0, $v1, 2
    /* 1488 80103C88 21104300 */  addu       $v0, $v0, $v1
    /* 148C 80103C8C 40100200 */  sll        $v0, $v0, 1
    /* 1490 80103C90 23300202 */  subu       $a2, $s0, $v0
    /* 1494 80103C94 2190C400 */  addu       $s2, $a2, $a0
    /* 1498 80103C98 00005192 */  lbu        $s1, 0x0($s2)
    /* 149C 80103C9C 04000224 */  addiu      $v0, $zero, 0x4
    /* 14A0 80103CA0 43002212 */  beq        $s1, $v0, .L80103DB0
    /* 14A4 80103CA4 40280600 */   sll       $a1, $a2, 1
    /* 14A8 80103CA8 2128A400 */  addu       $a1, $a1, $a0
    /* 14AC 80103CAC 0580043C */  lui        $a0, %hi(vs_main_artsPointsRequirements)
    /* 14B0 80103CB0 E4FD8424 */  addiu      $a0, $a0, %lo(vs_main_artsPointsRequirements)
    /* 14B4 80103CB4 40181100 */  sll        $v1, $s1, 1
    /* 14B8 80103CB8 C0100600 */  sll        $v0, $a2, 3
    /* 14BC 80103CBC 21186200 */  addu       $v1, $v1, $v0
    /* 14C0 80103CC0 21186400 */  addu       $v1, $v1, $a0
    /* 14C4 80103CC4 0C00A294 */  lhu        $v0, 0xC($a1)
    /* 14C8 80103CC8 00006394 */  lhu        $v1, 0x0($v1)
    /* 14CC 80103CCC 00000000 */  nop
    /* 14D0 80103CD0 2B104300 */  sltu       $v0, $v0, $v1
    /* 14D4 80103CD4 3A004014 */  bnez       $v0, .L80103DC0
    /* 14D8 80103CD8 01000224 */   addiu     $v0, $zero, 0x1
    /* 14DC 80103CDC 8123030C */  jal        func_800C8E04
    /* 14E0 80103CE0 03000424 */   addiu     $a0, $zero, 0x3
    /* 14E4 80103CE4 01002626 */  addiu      $a2, $s1, 0x1
    /* 14E8 80103CE8 FFFF0226 */  addiu      $v0, $s0, -0x1
    /* 14EC 80103CEC 80100200 */  sll        $v0, $v0, 2
    /* 14F0 80103CF0 B8002326 */  addiu      $v1, $s1, 0xB8
    /* 14F4 80103CF4 21884300 */  addu       $s1, $v0, $v1
    /* 14F8 80103CF8 1080053C */  lui        $a1, %hi(_battleAbilityMenuStrings)
    /* 14FC 80103CFC D84EA524 */  addiu      $a1, $a1, %lo(_battleAbilityMenuStrings)
    /* 1500 80103D00 2400A424 */  addiu      $a0, $a1, 0x24
    /* 1504 80103D04 000046A2 */  sb         $a2, 0x0($s2)
    /* 1508 80103D08 0F80063C */  lui        $a2, %hi(vs_battle_stringContext)
    /* 150C 80103D0C 6851C624 */  addiu      $a2, $a2, %lo(vs_battle_stringContext)
    /* 1510 80103D10 40101000 */  sll        $v0, $s0, 1
    /* 1514 80103D14 21104500 */  addu       $v0, $v0, $a1
    /* 1518 80103D18 40801100 */  sll        $s0, $s1, 1
    /* 151C 80103D1C 21801102 */  addu       $s0, $s0, $s1
    /* 1520 80103D20 80801000 */  sll        $s0, $s0, 2
    /* 1524 80103D24 21801102 */  addu       $s0, $s0, $s1
    /* 1528 80103D28 80801000 */  sll        $s0, $s0, 2
    /* 152C 80103D2C 0580113C */  lui        $s1, %hi(D_8004B9F8)
    /* 1530 80103D30 F8B93126 */  addiu      $s1, $s1, %lo(D_8004B9F8)
    /* 1534 80103D34 00004294 */  lhu        $v0, 0x0($v0)
    /* 1538 80103D38 21181102 */  addu       $v1, $s0, $s1
    /* 153C 80103D3C 2C00C3AC */  sw         $v1, 0x2C($a2)
    /* 1540 80103D40 40100200 */  sll        $v0, $v0, 1
    /* 1544 80103D44 21104500 */  addu       $v0, $v0, $a1
    /* 1548 80103D48 01FF030C */  jal        vs_mainmenu_setInformationMessage
    /* 154C 80103D4C 2800C2AC */   sw        $v0, 0x28($a2)
    /* 1550 80103D50 E4FF3126 */  addiu      $s1, $s1, -0x1C
    /* 1554 80103D54 21801102 */  addu       $s0, $s0, $s1
    /* 1558 80103D58 1080043C */  lui        $a0, %hi(D_801050F0)
    /* 155C 80103D5C 0C00028E */  lw         $v0, 0xC($s0)
    /* 1560 80103D60 78000324 */  addiu      $v1, $zero, 0x78
    /* 1564 80103D64 F05083A0 */  sb         $v1, %lo(D_801050F0)($a0)
    /* 1568 80103D68 00804234 */  ori        $v0, $v0, 0x8000
    /* 156C 80103D6C 6F0F0408 */  j          .L80103DBC
    /* 1570 80103D70 0C0002AE */   sw        $v0, 0xC($s0)
  .L80103D74:
    /* 1574 80103D74 0F80023C */  lui        $v0, %hi(D_800F5130)
    /* 1578 80103D78 3051428C */  lw         $v0, %lo(D_800F5130)($v0)
    /* 157C 80103D7C 00000000 */  nop
    /* 1580 80103D80 82170200 */  srl        $v0, $v0, 30
    /* 1584 80103D84 01004230 */  andi       $v0, $v0, 0x1
    /* 1588 80103D88 0C004010 */  beqz       $v0, .L80103DBC
    /* 158C 80103D8C 1080043C */   lui       $a0, %hi(D_801050F0)
    /* 1590 80103D90 F0508390 */  lbu        $v1, %lo(D_801050F0)($a0)
    /* 1594 80103D94 00000000 */  nop
    /* 1598 80103D98 05006010 */  beqz       $v1, .L80103DB0
    /* 159C 80103D9C 0680023C */   lui       $v0, %hi(vs_main_buttonsPressed)
    /* 15A0 80103DA0 D0E14290 */  lbu        $v0, %lo(vs_main_buttonsPressed)($v0)
    /* 15A4 80103DA4 00000000 */  nop
    /* 15A8 80103DA8 03004010 */  beqz       $v0, .L80103DB8
    /* 15AC 80103DAC FFFF6224 */   addiu     $v0, $v1, -0x1
  .L80103DB0:
    /* 15B0 80103DB0 700F0408 */  j          .L80103DC0
    /* 15B4 80103DB4 01000224 */   addiu     $v0, $zero, 0x1
  .L80103DB8:
    /* 15B8 80103DB8 F05082A0 */  sb         $v0, %lo(D_801050F0)($a0)
  .L80103DBC:
    /* 15BC 80103DBC 21100000 */  addu       $v0, $zero, $zero
  .L80103DC0:
    /* 15C0 80103DC0 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 15C4 80103DC4 1800B28F */  lw         $s2, 0x18($sp)
    /* 15C8 80103DC8 1400B18F */  lw         $s1, 0x14($sp)
    /* 15CC 80103DCC 1000B08F */  lw         $s0, 0x10($sp)
    /* 15D0 80103DD0 0800E003 */  jr         $ra
    /* 15D4 80103DD4 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel _breakArtUnlocked
