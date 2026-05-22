nonmatching func_8007357C, 0x50

glabel func_8007357C
    /* AD7C 8007357C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* AD80 80073580 0F80033C */  lui        $v1, %hi(D_800F196C)
    /* AD84 80073584 05000224 */  addiu      $v0, $zero, 0x5
    /* AD88 80073588 6C1962AC */  sw         $v0, %lo(D_800F196C)($v1)
    /* AD8C 8007358C 0F80023C */  lui        $v0, %hi(vs_battle_characterState)
    /* AD90 80073590 FC19428C */  lw         $v0, %lo(vs_battle_characterState)($v0)
    /* AD94 80073594 0F80033C */  lui        $v1, %hi(_cameraMode)
    /* AD98 80073598 1000BFAF */  sw         $ra, 0x10($sp)
    /* AD9C 8007359C 2000448C */  lw         $a0, 0x20($v0)
    /* ADA0 800735A0 01000224 */  addiu      $v0, $zero, 0x1
    /* ADA4 800735A4 F01862AC */  sw         $v0, %lo(_cameraMode)($v1)
    /* ADA8 800735A8 24208200 */  and        $a0, $a0, $v0
    /* ADAC 800735AC 982D030C */  jal        func_800CB660
    /* ADB0 800735B0 02008434 */   ori       $a0, $a0, 0x2
    /* ADB4 800735B4 E7B0010C */  jal        func_8006C39C
    /* ADB8 800735B8 00000000 */   nop
    /* ADBC 800735BC 1000BF8F */  lw         $ra, 0x10($sp)
    /* ADC0 800735C0 00000000 */  nop
    /* ADC4 800735C4 0800E003 */  jr         $ra
    /* ADC8 800735C8 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8007357C
