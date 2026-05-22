nonmatching func_80073F7C, 0xD4

glabel func_80073F7C
    /* B77C 80073F7C D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* B780 80073F80 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* B784 80073F84 21988000 */  addu       $s3, $a0, $zero
    /* B788 80073F88 1000B0AF */  sw         $s0, 0x10($sp)
    /* B78C 80073F8C 2180A000 */  addu       $s0, $a1, $zero
    /* B790 80073F90 1400B1AF */  sw         $s1, 0x14($sp)
    /* B794 80073F94 2188C000 */  addu       $s1, $a2, $zero
    /* B798 80073F98 0F80033C */  lui        $v1, %hi(D_800F196C)
    /* B79C 80073F9C 08000224 */  addiu      $v0, $zero, 0x8
    /* B7A0 80073FA0 6C1962AC */  sw         $v0, %lo(D_800F196C)($v1)
    /* B7A4 80073FA4 0F80033C */  lui        $v1, %hi(_cameraMode)
    /* B7A8 80073FA8 01000224 */  addiu      $v0, $zero, 0x1
    /* B7AC 80073FAC 2000BFAF */  sw         $ra, 0x20($sp)
    /* B7B0 80073FB0 1800B2AF */  sw         $s2, 0x18($sp)
    /* B7B4 80073FB4 C4BB010C */  jal        func_8006EF10
    /* B7B8 80073FB8 F01862AC */   sw        $v0, %lo(_cameraMode)($v1)
    /* B7BC 80073FBC 21900000 */  addu       $s2, $zero, $zero
    /* B7C0 80073FC0 0F80023C */  lui        $v0, %hi(D_800F1910)
    /* B7C4 80073FC4 101953AC */  sw         $s3, %lo(D_800F1910)($v0)
    /* B7C8 80073FC8 10194224 */  addiu      $v0, $v0, %lo(D_800F1910)
    /* B7CC 80073FCC 0000078E */  lw         $a3, 0x0($s0)
    /* B7D0 80073FD0 0400088E */  lw         $t0, 0x4($s0)
    /* B7D4 80073FD4 0800098E */  lw         $t1, 0x8($s0)
    /* B7D8 80073FD8 040047AC */  sw         $a3, 0x4($v0)
    /* B7DC 80073FDC 080048AC */  sw         $t0, 0x8($v0)
    /* B7E0 80073FE0 0C0049AC */  sw         $t1, 0xC($v0)
    /* B7E4 80073FE4 100051AC */  sw         $s1, 0x10($v0)
  .L80073FE8:
    /* B7E8 80073FE8 7179020C */  jal        func_8009E5C4
    /* B7EC 80073FEC 21204002 */   addu      $a0, $s2, $zero
    /* B7F0 80073FF0 01005226 */  addiu      $s2, $s2, 0x1
    /* B7F4 80073FF4 1000422A */  slti       $v0, $s2, 0x10
    /* B7F8 80073FF8 FBFF4014 */  bnez       $v0, .L80073FE8
    /* B7FC 80073FFC 0680023C */   lui       $v0, %hi(D_80060028)
    /* B800 80074000 28004290 */  lbu        $v0, %lo(D_80060028)($v0)
    /* B804 80074004 00000000 */  nop
    /* B808 80074008 05004010 */  beqz       $v0, .L80074020
    /* B80C 8007400C 0B000424 */   addiu     $a0, $zero, 0xB
    /* B810 80074010 06006586 */  lh         $a1, 0x6($s3)
    /* B814 80074014 01000624 */  addiu      $a2, $zero, 0x1
    /* B818 80074018 AE2C030C */  jal        vs_battle_displaySceneMessage
    /* B81C 8007401C 0600A524 */   addiu     $a1, $a1, 0x6
  .L80074020:
    /* B820 80074020 0F80023C */  lui        $v0, %hi(D_800F19CC)
    /* B824 80074024 CC19428C */  lw         $v0, %lo(D_800F19CC)($v0)
    /* B828 80074028 00000000 */  nop
    /* B82C 8007402C 040040AC */  sw         $zero, 0x4($v0)
    /* B830 80074030 080040A4 */  sh         $zero, 0x8($v0)
    /* B834 80074034 2000BF8F */  lw         $ra, 0x20($sp)
    /* B838 80074038 1C00B38F */  lw         $s3, 0x1C($sp)
    /* B83C 8007403C 1800B28F */  lw         $s2, 0x18($sp)
    /* B840 80074040 1400B18F */  lw         $s1, 0x14($sp)
    /* B844 80074044 1000B08F */  lw         $s0, 0x10($sp)
    /* B848 80074048 0800E003 */  jr         $ra
    /* B84C 8007404C 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_80073F7C
