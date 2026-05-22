nonmatching func_8007418C, 0x48

glabel func_8007418C
    /* B98C 8007418C E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* B990 80074190 0F80023C */  lui        $v0, %hi(D_800F1910)
    /* B994 80074194 10194224 */  addiu      $v0, $v0, %lo(D_800F1910)
    /* B998 80074198 21280000 */  addu       $a1, $zero, $zero
    /* B99C 8007419C 1800BFAF */  sw         $ra, 0x18($sp)
    /* B9A0 800741A0 08004394 */  lhu        $v1, 0x8($v0)
    /* B9A4 800741A4 0A004494 */  lhu        $a0, 0xA($v0)
    /* B9A8 800741A8 0C004294 */  lhu        $v0, 0xC($v0)
    /* B9AC 800741AC 28000624 */  addiu      $a2, $zero, 0x28
    /* B9B0 800741B0 1200A4A7 */  sh         $a0, 0x12($sp)
    /* B9B4 800741B4 1000A427 */  addiu      $a0, $sp, 0x10
    /* B9B8 800741B8 1000A3A7 */  sh         $v1, 0x10($sp)
    /* B9BC 800741BC BFB7010C */  jal        _stepTowardTarget
    /* B9C0 800741C0 1400A2A7 */   sh        $v0, 0x14($sp)
    /* B9C4 800741C4 1800BF8F */  lw         $ra, 0x18($sp)
    /* B9C8 800741C8 00000000 */  nop
    /* B9CC 800741CC 0800E003 */  jr         $ra
    /* B9D0 800741D0 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_8007418C
