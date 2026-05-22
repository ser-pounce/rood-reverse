nonmatching SoundVM_CC_EnableLegato, 0xC

glabel SoundVM_CC_EnableLegato
    /* CB6C 8001C36C 01000224 */  addiu      $v0, $zero, 0x1
    /* CB70 8001C370 0800E003 */  jr         $ra
    /* CB74 8001C374 9C0082A4 */   sh        $v0, 0x9C($a0)
endlabel SoundVM_CC_EnableLegato
