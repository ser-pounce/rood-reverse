nonmatching func_80084870, 0x9C

glabel func_80084870
    /* 1C070 80084870 0F80023C */  lui        $v0, %hi(D_800F19CC)
    /* 1C074 80084874 CC19428C */  lw         $v0, %lo(D_800F19CC)($v0)
    /* 1C078 80084878 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 1C07C 8008487C 1800B0AF */  sw         $s0, 0x18($sp)
    /* 1C080 80084880 21808000 */  addu       $s0, $a0, $zero
    /* 1C084 80084884 2000BFAF */  sw         $ra, 0x20($sp)
    /* 1C088 80084888 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 1C08C 8008488C 2800428C */  lw         $v0, 0x28($v0)
    /* 1C090 80084890 00000000 */  nop
    /* 1C094 80084894 03004330 */  andi       $v1, $v0, 0x3
    /* 1C098 80084898 01000224 */  addiu      $v0, $zero, 0x1
    /* 1C09C 8008489C 04006210 */  beq        $v1, $v0, .L800848B0
    /* 1C0A0 800848A0 2188C000 */   addu      $s1, $a2, $zero
    /* 1C0A4 800848A4 03000224 */  addiu      $v0, $zero, 0x3
    /* 1C0A8 800848A8 13006214 */  bne        $v1, $v0, .L800848F8
    /* 1C0AC 800848AC 00000000 */   nop
  .L800848B0:
    /* 1C0B0 800848B0 21200002 */  addu       $a0, $s0, $zero
    /* 1C0B4 800848B4 3800A28F */  lw         $v0, 0x38($sp)
    /* 1C0B8 800848B8 21302002 */  addu       $a2, $s1, $zero
    /* 1C0BC 800848BC 3B0E020C */  jal        _calculateDamage
    /* 1C0C0 800848C0 1000A2AF */   sw        $v0, 0x10($sp)
    /* 1C0C4 800848C4 21200002 */  addu       $a0, $s0, $zero
    /* 1C0C8 800848C8 21282002 */  addu       $a1, $s1, $zero
    /* 1C0CC 800848CC 00340200 */  sll        $a2, $v0, 16
    /* 1C0D0 800848D0 03340600 */  sra        $a2, $a2, 16
    /* 1C0D4 800848D4 1C00A78C */  lw         $a3, 0x1C($a1)
    /* 1C0D8 800848D8 FCFF0324 */  addiu      $v1, $zero, -0x4
    /* 1C0DC 800848DC 2438E300 */  and        $a3, $a3, $v1
    /* 1C0E0 800848E0 0400A394 */  lhu        $v1, 0x4($a1)
    /* 1C0E4 800848E4 0200E734 */  ori        $a3, $a3, 0x2
    /* 1C0E8 800848E8 1C00A7AC */  sw         $a3, 0x1C($a1)
    /* 1C0EC 800848EC 21186200 */  addu       $v1, $v1, $v0
    /* 1C0F0 800848F0 7800020C */  jal        func_800801E0
    /* 1C0F4 800848F4 0400A3A4 */   sh        $v1, 0x4($a1)
  .L800848F8:
    /* 1C0F8 800848F8 2000BF8F */  lw         $ra, 0x20($sp)
    /* 1C0FC 800848FC 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 1C100 80084900 1800B08F */  lw         $s0, 0x18($sp)
    /* 1C104 80084904 0800E003 */  jr         $ra
    /* 1C108 80084908 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_80084870
