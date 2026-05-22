nonmatching func_800770FC, 0x34

glabel func_800770FC
    /* E8FC 800770FC D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* E900 80077100 07000224 */  addiu      $v0, $zero, 0x7
    /* E904 80077104 1000A427 */  addiu      $a0, $sp, 0x10
    /* E908 80077108 2800BFAF */  sw         $ra, 0x28($sp)
    /* E90C 8007710C 1000A2A3 */  sb         $v0, 0x10($sp)
    /* E910 80077110 1100A5A3 */  sb         $a1, 0x11($sp)
    /* E914 80077114 1200A0A7 */  sh         $zero, 0x12($sp)
    /* E918 80077118 7A65020C */  jal        vs_battle_populateDataSlot
    /* E91C 8007711C 2000A0A3 */   sb        $zero, 0x20($sp)
    /* E920 80077120 2800BF8F */  lw         $ra, 0x28($sp)
    /* E924 80077124 00000000 */  nop
    /* E928 80077128 0800E003 */  jr         $ra
    /* E92C 8007712C 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel func_800770FC
