nonmatching func_80084390, 0xB0

glabel func_80084390
    /* 1BB90 80084390 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 1BB94 80084394 1800B0AF */  sw         $s0, 0x18($sp)
    /* 1BB98 80084398 21808000 */  addu       $s0, $a0, $zero
    /* 1BB9C 8008439C 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 1BBA0 800843A0 0F80023C */  lui        $v0, %hi(D_800F19CC)
    /* 1BBA4 800843A4 CC19428C */  lw         $v0, %lo(D_800F19CC)($v0)
    /* 1BBA8 800843A8 0580043C */  lui        $a0, %hi(vs_main_skills)
    /* 1BBAC 800843AC 2000BFAF */  sw         $ra, 0x20($sp)
    /* 1BBB0 800843B0 08004394 */  lhu        $v1, 0x8($v0)
    /* 1BBB4 800843B4 DCB98424 */  addiu      $a0, $a0, %lo(vs_main_skills)
    /* 1BBB8 800843B8 40100300 */  sll        $v0, $v1, 1
    /* 1BBBC 800843BC 21104300 */  addu       $v0, $v0, $v1
    /* 1BBC0 800843C0 80100200 */  sll        $v0, $v0, 2
    /* 1BBC4 800843C4 21104300 */  addu       $v0, $v0, $v1
    /* 1BBC8 800843C8 80100200 */  sll        $v0, $v0, 2
    /* 1BBCC 800843CC 21104400 */  addu       $v0, $v0, $a0
    /* 1BBD0 800843D0 0000428C */  lw         $v0, 0x0($v0)
    /* 1BBD4 800843D4 01000324 */  addiu      $v1, $zero, 0x1
    /* 1BBD8 800843D8 42140200 */  srl        $v0, $v0, 17
    /* 1BBDC 800843DC 07004230 */  andi       $v0, $v0, 0x7
    /* 1BBE0 800843E0 12004314 */  bne        $v0, $v1, .L8008442C
    /* 1BBE4 800843E4 2188C000 */   addu      $s1, $a2, $zero
    /* 1BBE8 800843E8 21200002 */  addu       $a0, $s0, $zero
    /* 1BBEC 800843EC 3800A28F */  lw         $v0, 0x38($sp)
    /* 1BBF0 800843F0 3B0E020C */  jal        _calculateDamage
    /* 1BBF4 800843F4 1000A2AF */   sw        $v0, 0x10($sp)
    /* 1BBF8 800843F8 21200002 */  addu       $a0, $s0, $zero
    /* 1BBFC 800843FC 21282002 */  addu       $a1, $s1, $zero
    /* 1BC00 80084400 00340200 */  sll        $a2, $v0, 16
    /* 1BC04 80084404 03340600 */  sra        $a2, $a2, 16
    /* 1BC08 80084408 1C00A78C */  lw         $a3, 0x1C($a1)
    /* 1BC0C 8008440C FCFF0324 */  addiu      $v1, $zero, -0x4
    /* 1BC10 80084410 2438E300 */  and        $a3, $a3, $v1
    /* 1BC14 80084414 0400A394 */  lhu        $v1, 0x4($a1)
    /* 1BC18 80084418 0200E734 */  ori        $a3, $a3, 0x2
    /* 1BC1C 8008441C 1C00A7AC */  sw         $a3, 0x1C($a1)
    /* 1BC20 80084420 21186200 */  addu       $v1, $v1, $v0
    /* 1BC24 80084424 7800020C */  jal        func_800801E0
    /* 1BC28 80084428 0400A3A4 */   sh        $v1, 0x4($a1)
  .L8008442C:
    /* 1BC2C 8008442C 2000BF8F */  lw         $ra, 0x20($sp)
    /* 1BC30 80084430 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 1BC34 80084434 1800B08F */  lw         $s0, 0x18($sp)
    /* 1BC38 80084438 0800E003 */  jr         $ra
    /* 1BC3C 8008443C 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_80084390
