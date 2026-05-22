/* Handwritten function */
nonmatching _eventSpecs, 0x8

glabel _eventSpecs
    /* 7AB8 8010A2B8 04000080 */  lb         $zero, 0x4($zero)
    /* 7ABC 8010A2BC 00010020 */  addi       $zero, $zero, 0x100 /* handwritten instruction */
endlabel _eventSpecs
