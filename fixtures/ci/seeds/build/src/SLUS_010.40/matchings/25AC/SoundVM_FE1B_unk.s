nonmatching SoundVM_FE1B_unk, 0x14

glabel SoundVM_FE1B_unk
    /* BEF8 8001B6F8 3400828C */  lw         $v0, 0x34($a0)
    /* BEFC 8001B6FC BFFF0324 */  addiu      $v1, $zero, -0x41
    /* BF00 8001B700 24104300 */  and        $v0, $v0, $v1
    /* BF04 8001B704 0800E003 */  jr         $ra
    /* BF08 8001B708 340082AC */   sw        $v0, 0x34($a0)
endlabel SoundVM_FE1B_unk
