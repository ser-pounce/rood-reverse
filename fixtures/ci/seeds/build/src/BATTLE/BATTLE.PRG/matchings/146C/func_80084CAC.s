nonmatching func_80084CAC, 0x98

glabel func_80084CAC
    /* 1C4AC 80084CAC D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 1C4B0 80084CB0 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 1C4B4 80084CB4 2188C000 */  addu       $s1, $a2, $zero
    /* 1C4B8 80084CB8 0F80033C */  lui        $v1, %hi(vs_battle_actors)
    /* 1C4BC 80084CBC 2000BFAF */  sw         $ra, 0x20($sp)
    /* 1C4C0 80084CC0 1800B0AF */  sw         $s0, 0x18($sp)
    /* 1C4C4 80084CC4 00002292 */  lbu        $v0, 0x0($s1)
    /* 1C4C8 80084CC8 28196324 */  addiu      $v1, $v1, %lo(vs_battle_actors)
    /* 1C4CC 80084CCC 80100200 */  sll        $v0, $v0, 2
    /* 1C4D0 80084CD0 21104300 */  addu       $v0, $v0, $v1
    /* 1C4D4 80084CD4 0000428C */  lw         $v0, 0x0($v0)
    /* 1C4D8 80084CD8 3800A38F */  lw         $v1, 0x38($sp)
    /* 1C4DC 80084CDC 3C00508C */  lw         $s0, 0x3C($v0)
    /* 1C4E0 80084CE0 3B0E020C */  jal        _calculateDamage
    /* 1C4E4 80084CE4 1000A3AF */   sw        $v1, 0x10($sp)
    /* 1C4E8 80084CE8 21204000 */  addu       $a0, $v0, $zero
    /* 1C4EC 80084CEC 00140400 */  sll        $v0, $a0, 16
    /* 1C4F0 80084CF0 03140200 */  sra        $v0, $v0, 16
    /* 1C4F4 80084CF4 1C000586 */  lh         $a1, 0x1C($s0)
    /* 1C4F8 80084CF8 1C000396 */  lhu        $v1, 0x1C($s0)
    /* 1C4FC 80084CFC 2A10A200 */  slt        $v0, $a1, $v0
    /* 1C500 80084D00 03004010 */  beqz       $v0, .L80084D10
    /* 1C504 80084D04 0F80023C */   lui       $v0, %hi(D_800F1A08)
    /* 1C508 80084D08 21206000 */  addu       $a0, $v1, $zero
    /* 1C50C 80084D0C 081A45AC */  sw         $a1, %lo(D_800F1A08)($v0)
  .L80084D10:
    /* 1C510 80084D10 1C00238E */  lw         $v1, 0x1C($s1)
    /* 1C514 80084D14 F3FF0224 */  addiu      $v0, $zero, -0xD
    /* 1C518 80084D18 24186200 */  and        $v1, $v1, $v0
    /* 1C51C 80084D1C 06002296 */  lhu        $v0, 0x6($s1)
    /* 1C520 80084D20 04006334 */  ori        $v1, $v1, 0x4
    /* 1C524 80084D24 1C0023AE */  sw         $v1, 0x1C($s1)
    /* 1C528 80084D28 21104400 */  addu       $v0, $v0, $a0
    /* 1C52C 80084D2C 060022A6 */  sh         $v0, 0x6($s1)
    /* 1C530 80084D30 2000BF8F */  lw         $ra, 0x20($sp)
    /* 1C534 80084D34 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 1C538 80084D38 1800B08F */  lw         $s0, 0x18($sp)
    /* 1C53C 80084D3C 0800E003 */  jr         $ra
    /* 1C540 80084D40 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_80084CAC
