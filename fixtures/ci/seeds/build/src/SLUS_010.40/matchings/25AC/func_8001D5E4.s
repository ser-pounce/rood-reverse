nonmatching func_8001D5E4, 0x30

glabel func_8001D5E4
    /* DDE4 8001D5E4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* DDE8 8001D5E8 0280073C */  lui        $a3, %hi(func_8001D614)
    /* DDEC 8001D5EC 00110424 */  addiu      $a0, $zero, 0x1100
    /* DDF0 8001D5F0 00190524 */  addiu      $a1, $zero, 0x1900
    /* DDF4 8001D5F4 00100624 */  addiu      $a2, $zero, 0x1000
    /* DDF8 8001D5F8 1000BFAF */  sw         $ra, 0x10($sp)
    /* DDFC 8001D5FC 0E75000C */  jal        Sound_Cutscene_LoadNextBuffer
    /* DE00 8001D600 14D6E724 */   addiu     $a3, $a3, %lo(func_8001D614)
    /* DE04 8001D604 1000BF8F */  lw         $ra, 0x10($sp)
    /* DE08 8001D608 00000000 */  nop
    /* DE0C 8001D60C 0800E003 */  jr         $ra
    /* DE10 8001D610 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8001D5E4
