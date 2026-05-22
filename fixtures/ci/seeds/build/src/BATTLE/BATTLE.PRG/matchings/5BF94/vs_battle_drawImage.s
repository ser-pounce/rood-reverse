nonmatching vs_battle_drawImage, 0x4C

glabel vs_battle_drawImage
    /* 645A8 800CCDA8 0F80073C */  lui        $a3, %hi(D_800EC280)
    /* 645AC 800CCDAC 80C2E38C */  lw         $v1, %lo(D_800EC280)($a3)
    /* 645B0 800CCDB0 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 645B4 800CCDB4 1000BFAF */  sw         $ra, 0x10($sp)
    /* 645B8 800CCDB8 01006224 */  addiu      $v0, $v1, 0x1
    /* 645BC 800CCDBC 07004230 */  andi       $v0, $v0, 0x7
    /* 645C0 800CCDC0 C0180300 */  sll        $v1, $v1, 3
    /* 645C4 800CCDC4 80C2E2AC */  sw         $v0, %lo(D_800EC280)($a3)
    /* 645C8 800CCDC8 0F80023C */  lui        $v0, %hi(D_800F51D0)
    /* 645CC 800CCDCC D0514224 */  addiu      $v0, $v0, %lo(D_800F51D0)
    /* 645D0 800CCDD0 21186200 */  addu       $v1, $v1, $v0
    /* 645D4 800CCDD4 000064AC */  sw         $a0, 0x0($v1)
    /* 645D8 800CCDD8 21206000 */  addu       $a0, $v1, $zero
    /* 645DC 800CCDDC 3FA2000C */  jal        LoadImage
    /* 645E0 800CCDE0 040066AC */   sw        $a2, 0x4($v1)
    /* 645E4 800CCDE4 1000BF8F */  lw         $ra, 0x10($sp)
    /* 645E8 800CCDE8 00000000 */  nop
    /* 645EC 800CCDEC 0800E003 */  jr         $ra
    /* 645F0 800CCDF0 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel vs_battle_drawImage
