nonmatching SoundVM_D0_EnableSustainedNote, 0x1C

glabel SoundVM_D0_EnableSustainedNote
    /* CB80 8001C380 64008294 */  lhu        $v0, 0x64($a0)
    /* CB84 8001C384 00000000 */  nop
    /* CB88 8001C388 02004010 */  beqz       $v0, .L8001C394
    /* CB8C 8001C38C 04000224 */   addiu     $v0, $zero, 0x4
    /* CB90 8001C390 9C0082A4 */  sh         $v0, 0x9C($a0)
  .L8001C394:
    /* CB94 8001C394 0800E003 */  jr         $ra
    /* CB98 8001C398 00000000 */   nop
endlabel SoundVM_D0_EnableSustainedNote
