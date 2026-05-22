nonmatching vs_mainmenu_setInformationMessage, 0x64

glabel vs_mainmenu_setInformationMessage
    /* 6404 800FFC04 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 6408 800FFC08 21288000 */  addu       $a1, $a0, $zero
    /* 640C 800FFC0C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 6410 800FFC10 1080103C */  lui        $s0, %hi(D_8010231A)
    /* 6414 800FFC14 1A231026 */  addiu      $s0, $s0, %lo(D_8010231A)
    /* 6418 800FFC18 21200002 */  addu       $a0, $s0, $zero
    /* 641C 800FFC1C 1400BFAF */  sw         $ra, 0x14($sp)
    /* 6420 800FFC20 7800030C */  jal        vs_battle_memcpy
    /* 6424 800FFC24 60000624 */   addiu     $a2, $zero, 0x60
    /* 6428 800FFC28 FFC0033C */  lui        $v1, (0xC0FFFFFF >> 16)
    /* 642C 800FFC2C FFFF6334 */  ori        $v1, $v1, (0xC0FFFFFF & 0xFFFF)
    /* 6430 800FFC30 07000424 */  addiu      $a0, $zero, 0x7
    /* 6434 800FFC34 0F80063C */  lui        $a2, %hi(vs_battle_textBoxes)
    /* 6438 800FFC38 E04FC624 */  addiu      $a2, $a2, %lo(vs_battle_textBoxes)
    /* 643C 800FFC3C 5001C28C */  lw         $v0, 0x150($a2)
    /* 6440 800FFC40 FEFF0526 */  addiu      $a1, $s0, -0x2
    /* 6444 800FFC44 24104300 */  and        $v0, $v0, $v1
    /* 6448 800FFC48 0020033C */  lui        $v1, (0x20000000 >> 16)
    /* 644C 800FFC4C 25104300 */  or         $v0, $v0, $v1
    /* 6450 800FFC50 FC1A030C */  jal        vs_battle_setTextBox
    /* 6454 800FFC54 5001C2AC */   sw        $v0, 0x150($a2)
    /* 6458 800FFC58 1400BF8F */  lw         $ra, 0x14($sp)
    /* 645C 800FFC5C 1000B08F */  lw         $s0, 0x10($sp)
    /* 6460 800FFC60 0800E003 */  jr         $ra
    /* 6464 800FFC64 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel vs_mainmenu_setInformationMessage
