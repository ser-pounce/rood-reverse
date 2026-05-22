nonmatching func_800704D8, 0x64

glabel func_800704D8
    /* 7CD8 800704D8 0F80043C */  lui        $a0, %hi(D_800F196C)
    /* 7CDC 800704DC 0F80023C */  lui        $v0, %hi(D_800F19CC)
    /* 7CE0 800704E0 CC19438C */  lw         $v1, %lo(D_800F19CC)($v0)
    /* 7CE4 800704E4 05000224 */  addiu      $v0, $zero, 0x5
    /* 7CE8 800704E8 6C1982AC */  sw         $v0, %lo(D_800F196C)($a0)
    /* 7CEC 800704EC 0F80023C */  lui        $v0, %hi(vs_battle_characterState)
    /* 7CF0 800704F0 FC19428C */  lw         $v0, %lo(vs_battle_characterState)($v0)
    /* 7CF4 800704F4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 7CF8 800704F8 1000BFAF */  sw         $ra, 0x10($sp)
    /* 7CFC 800704FC 080060A4 */  sh         $zero, 0x8($v1)
    /* 7D00 80070500 0F80033C */  lui        $v1, %hi(_cameraMode)
    /* 7D04 80070504 2000448C */  lw         $a0, 0x20($v0)
    /* 7D08 80070508 01000224 */  addiu      $v0, $zero, 0x1
    /* 7D0C 8007050C F01862AC */  sw         $v0, %lo(_cameraMode)($v1)
    /* 7D10 80070510 24208200 */  and        $a0, $a0, $v0
    /* 7D14 80070514 982D030C */  jal        func_800CB660
    /* 7D18 80070518 02008434 */   ori       $a0, $a0, 0x2
    /* 7D1C 8007051C D02A030C */  jal        func_800CAB40
    /* 7D20 80070520 00000000 */   nop
    /* 7D24 80070524 E7B0010C */  jal        func_8006C39C
    /* 7D28 80070528 00000000 */   nop
    /* 7D2C 8007052C 1000BF8F */  lw         $ra, 0x10($sp)
    /* 7D30 80070530 00000000 */  nop
    /* 7D34 80070534 0800E003 */  jr         $ra
    /* 7D38 80070538 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800704D8
