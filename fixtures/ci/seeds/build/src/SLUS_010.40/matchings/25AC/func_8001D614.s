nonmatching func_8001D614, 0x30

glabel func_8001D614
    /* DE14 8001D614 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* DE18 8001D618 0280073C */  lui        $a3, %hi(func_8001D5E4)
    /* DE1C 8001D61C 00210424 */  addiu      $a0, $zero, 0x2100
    /* DE20 8001D620 00290524 */  addiu      $a1, $zero, 0x2900
    /* DE24 8001D624 00100624 */  addiu      $a2, $zero, 0x1000
    /* DE28 8001D628 1000BFAF */  sw         $ra, 0x10($sp)
    /* DE2C 8001D62C 0E75000C */  jal        Sound_Cutscene_LoadNextBuffer
    /* DE30 8001D630 E4D5E724 */   addiu     $a3, $a3, %lo(func_8001D5E4)
    /* DE34 8001D634 1000BF8F */  lw         $ra, 0x10($sp)
    /* DE38 8001D638 00000000 */  nop
    /* DE3C 8001D63C 0800E003 */  jr         $ra
    /* DE40 8001D640 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8001D614
