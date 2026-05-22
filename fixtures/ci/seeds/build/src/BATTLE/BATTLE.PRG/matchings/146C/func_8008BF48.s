nonmatching func_8008BF48, 0x128

glabel func_8008BF48
    /* 23748 8008BF48 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 2374C 8008BF4C 1400B1AF */  sw         $s1, 0x14($sp)
    /* 23750 8008BF50 21888000 */  addu       $s1, $a0, $zero
    /* 23754 8008BF54 1800BFAF */  sw         $ra, 0x18($sp)
    /* 23758 8008BF58 1000B0AF */  sw         $s0, 0x10($sp)
    /* 2375C 8008BF5C 0E002286 */  lh         $v0, 0xE($s1)
    /* 23760 8008BF60 00000000 */  nop
    /* 23764 8008BF64 06004014 */  bnez       $v0, .L8008BF80
    /* 23768 8008BF68 7E000424 */   addiu     $a0, $zero, 0x7E
    /* 2376C 8008BF6C 6216010C */  jal        vs_main_playSfxDefault
    /* 23770 8008BF70 1D000524 */   addiu     $a1, $zero, 0x1D
    /* 23774 8008BF74 7E000424 */  addiu      $a0, $zero, 0x7E
    /* 23778 8008BF78 E42F0208 */  j          .L8008BF90
    /* 2377C 8008BF7C 1E000524 */   addiu     $a1, $zero, 0x1E
  .L8008BF80:
    /* 23780 8008BF80 6216010C */  jal        vs_main_playSfxDefault
    /* 23784 8008BF84 16000524 */   addiu     $a1, $zero, 0x16
    /* 23788 8008BF88 7E000424 */  addiu      $a0, $zero, 0x7E
    /* 2378C 8008BF8C 17000524 */  addiu      $a1, $zero, 0x17
  .L8008BF90:
    /* 23790 8008BF90 6216010C */  jal        vs_main_playSfxDefault
    /* 23794 8008BF94 00000000 */   nop
    /* 23798 8008BF98 09002492 */  lbu        $a0, 0x9($s1)
    /* 2379C 8008BF9C 474A020C */  jal        func_8009291C
    /* 237A0 8008BFA0 00000000 */   nop
    /* 237A4 8008BFA4 0E002286 */  lh         $v0, 0xE($s1)
    /* 237A8 8008BFA8 00000000 */  nop
    /* 237AC 8008BFAC 03004010 */  beqz       $v0, .L8008BFBC
    /* 237B0 8008BFB0 00000000 */   nop
    /* 237B4 8008BFB4 5D2F020C */  jal        func_8008BD74
    /* 237B8 8008BFB8 21202002 */   addu      $a0, $s1, $zero
  .L8008BFBC:
    /* 237BC 8008BFBC 10002486 */  lh         $a0, 0x10($s1)
    /* 237C0 8008BFC0 FFFF0224 */  addiu      $v0, $zero, -0x1
    /* 237C4 8008BFC4 21008210 */  beq        $a0, $v0, .L8008C04C
    /* 237C8 8008BFC8 0F80023C */   lui       $v0, %hi(vs_battle_roomData + 0x88)
    /* 237CC 8008BFCC 80180400 */  sll        $v1, $a0, 2
    /* 237D0 8008BFD0 21186400 */  addu       $v1, $v1, $a0
    /* 237D4 8008BFD4 801C508C */  lw         $s0, %lo(vs_battle_roomData + 0x88)($v0)
    /* 237D8 8008BFD8 80180300 */  sll        $v1, $v1, 2
    /* 237DC 8008BFDC 21187000 */  addu       $v1, $v1, $s0
    /* 237E0 8008BFE0 0A006290 */  lbu        $v0, 0xA($v1)
    /* 237E4 8008BFE4 00000000 */  nop
    /* 237E8 8008BFE8 19004010 */  beqz       $v0, .L8008C050
    /* 237EC 8008BFEC 01000424 */   addiu     $a0, $zero, 0x1
    /* 237F0 8008BFF0 09006490 */  lbu        $a0, 0x9($v1)
    /* 237F4 8008BFF4 474A020C */  jal        func_8009291C
    /* 237F8 8008BFF8 00000000 */   nop
    /* 237FC 8008BFFC 10002286 */  lh         $v0, 0x10($s1)
    /* 23800 8008C000 00000000 */  nop
    /* 23804 8008C004 80180200 */  sll        $v1, $v0, 2
    /* 23808 8008C008 21186200 */  addu       $v1, $v1, $v0
    /* 2380C 8008C00C 80180300 */  sll        $v1, $v1, 2
    /* 23810 8008C010 21207000 */  addu       $a0, $v1, $s0
    /* 23814 8008C014 0E008284 */  lh         $v0, 0xE($a0)
    /* 23818 8008C018 00000000 */  nop
    /* 2381C 8008C01C 03004010 */  beqz       $v0, .L8008C02C
    /* 23820 8008C020 00000000 */   nop
    /* 23824 8008C024 5D2F020C */  jal        func_8008BD74
    /* 23828 8008C028 00000000 */   nop
  .L8008C02C:
    /* 2382C 8008C02C 10002286 */  lh         $v0, 0x10($s1)
    /* 23830 8008C030 00000000 */  nop
    /* 23834 8008C034 80180200 */  sll        $v1, $v0, 2
    /* 23838 8008C038 21186200 */  addu       $v1, $v1, $v0
    /* 2383C 8008C03C 80180300 */  sll        $v1, $v1, 2
    /* 23840 8008C040 21187000 */  addu       $v1, $v1, $s0
    /* 23844 8008C044 01000224 */  addiu      $v0, $zero, 0x1
    /* 23848 8008C048 120062A0 */  sb         $v0, 0x12($v1)
  .L8008C04C:
    /* 2384C 8008C04C 01000424 */  addiu      $a0, $zero, 0x1
  .L8008C050:
    /* 23850 8008C050 1C30020C */  jal        func_8008C070
    /* 23854 8008C054 21282002 */   addu      $a1, $s1, $zero
    /* 23858 8008C058 1800BF8F */  lw         $ra, 0x18($sp)
    /* 2385C 8008C05C 1400B18F */  lw         $s1, 0x14($sp)
    /* 23860 8008C060 1000B08F */  lw         $s0, 0x10($sp)
    /* 23864 8008C064 01000224 */  addiu      $v0, $zero, 0x1
    /* 23868 8008C068 0800E003 */  jr         $ra
    /* 2386C 8008C06C 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_8008BF48
