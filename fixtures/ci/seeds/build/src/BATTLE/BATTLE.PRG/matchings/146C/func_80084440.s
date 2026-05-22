nonmatching func_80084440, 0xB0

glabel func_80084440
    /* 1BC40 80084440 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 1BC44 80084444 1800B0AF */  sw         $s0, 0x18($sp)
    /* 1BC48 80084448 21808000 */  addu       $s0, $a0, $zero
    /* 1BC4C 8008444C 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 1BC50 80084450 0F80023C */  lui        $v0, %hi(D_800F19CC)
    /* 1BC54 80084454 CC19428C */  lw         $v0, %lo(D_800F19CC)($v0)
    /* 1BC58 80084458 0580043C */  lui        $a0, %hi(vs_main_skills)
    /* 1BC5C 8008445C 2000BFAF */  sw         $ra, 0x20($sp)
    /* 1BC60 80084460 08004394 */  lhu        $v1, 0x8($v0)
    /* 1BC64 80084464 DCB98424 */  addiu      $a0, $a0, %lo(vs_main_skills)
    /* 1BC68 80084468 40100300 */  sll        $v0, $v1, 1
    /* 1BC6C 8008446C 21104300 */  addu       $v0, $v0, $v1
    /* 1BC70 80084470 80100200 */  sll        $v0, $v0, 2
    /* 1BC74 80084474 21104300 */  addu       $v0, $v0, $v1
    /* 1BC78 80084478 80100200 */  sll        $v0, $v0, 2
    /* 1BC7C 8008447C 21104400 */  addu       $v0, $v0, $a0
    /* 1BC80 80084480 0000428C */  lw         $v0, 0x0($v0)
    /* 1BC84 80084484 01000324 */  addiu      $v1, $zero, 0x1
    /* 1BC88 80084488 42140200 */  srl        $v0, $v0, 17
    /* 1BC8C 8008448C 07004230 */  andi       $v0, $v0, 0x7
    /* 1BC90 80084490 12004310 */  beq        $v0, $v1, .L800844DC
    /* 1BC94 80084494 2188C000 */   addu      $s1, $a2, $zero
    /* 1BC98 80084498 21200002 */  addu       $a0, $s0, $zero
    /* 1BC9C 8008449C 3800A28F */  lw         $v0, 0x38($sp)
    /* 1BCA0 800844A0 3B0E020C */  jal        _calculateDamage
    /* 1BCA4 800844A4 1000A2AF */   sw        $v0, 0x10($sp)
    /* 1BCA8 800844A8 21200002 */  addu       $a0, $s0, $zero
    /* 1BCAC 800844AC 21282002 */  addu       $a1, $s1, $zero
    /* 1BCB0 800844B0 00340200 */  sll        $a2, $v0, 16
    /* 1BCB4 800844B4 03340600 */  sra        $a2, $a2, 16
    /* 1BCB8 800844B8 1C00A78C */  lw         $a3, 0x1C($a1)
    /* 1BCBC 800844BC FCFF0324 */  addiu      $v1, $zero, -0x4
    /* 1BCC0 800844C0 2438E300 */  and        $a3, $a3, $v1
    /* 1BCC4 800844C4 0400A394 */  lhu        $v1, 0x4($a1)
    /* 1BCC8 800844C8 0200E734 */  ori        $a3, $a3, 0x2
    /* 1BCCC 800844CC 1C00A7AC */  sw         $a3, 0x1C($a1)
    /* 1BCD0 800844D0 21186200 */  addu       $v1, $v1, $v0
    /* 1BCD4 800844D4 7800020C */  jal        func_800801E0
    /* 1BCD8 800844D8 0400A3A4 */   sh        $v1, 0x4($a1)
  .L800844DC:
    /* 1BCDC 800844DC 2000BF8F */  lw         $ra, 0x20($sp)
    /* 1BCE0 800844E0 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 1BCE4 800844E4 1800B08F */  lw         $s0, 0x18($sp)
    /* 1BCE8 800844E8 0800E003 */  jr         $ra
    /* 1BCEC 800844EC 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_80084440
