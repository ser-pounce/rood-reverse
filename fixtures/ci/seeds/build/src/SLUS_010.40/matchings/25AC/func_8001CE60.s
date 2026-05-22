nonmatching func_8001CE60, 0x48

glabel func_8001CE60
    /* D660 8001CE60 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* D664 8001CE64 0480023C */  lui        $v0, %hi(g_Sound_Cutscene_StreamState)
    /* D668 8001CE68 1000B0AF */  sw         $s0, 0x10($sp)
    /* D66C 8001CE6C 089B508C */  lw         $s0, %lo(g_Sound_Cutscene_StreamState)($v0)
    /* D670 8001CE70 00210424 */  addiu      $a0, $zero, 0x2100
    /* D674 8001CE74 1400BFAF */  sw         $ra, 0x14($sp)
    /* D678 8001CE78 F17A000C */  jal        SpuSetTransferStartAddr
    /* D67C 8001CE7C 00081026 */   addiu     $s0, $s0, 0x800
    /* D680 8001CE80 0280043C */  lui        $a0, %hi(Sound_Cutscene_OnInitialTransferComplete)
    /* D684 8001CE84 157B000C */  jal        SpuSetTransferCallback
    /* D688 8001CE88 70D38424 */   addiu     $a0, $a0, %lo(Sound_Cutscene_OnInitialTransferComplete)
    /* D68C 8001CE8C 21200002 */  addu       $a0, $s0, $zero
    /* D690 8001CE90 D97A000C */  jal        SpuWrite
    /* D694 8001CE94 00080524 */   addiu     $a1, $zero, 0x800
    /* D698 8001CE98 1400BF8F */  lw         $ra, 0x14($sp)
    /* D69C 8001CE9C 1000B08F */  lw         $s0, 0x10($sp)
    /* D6A0 8001CEA0 0800E003 */  jr         $ra
    /* D6A4 8001CEA4 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8001CE60
