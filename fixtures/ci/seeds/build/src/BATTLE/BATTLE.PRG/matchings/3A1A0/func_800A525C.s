nonmatching func_800A525C, 0x24

glabel func_800A525C
    /* 3CA5C 800A525C 0F008390 */  lbu        $v1, 0xF($a0)
    /* 3CA60 800A5260 01000224 */  addiu      $v0, $zero, 0x1
    /* 3CA64 800A5264 02006014 */  bnez       $v1, .L800A5270
    /* 3CA68 800A5268 481882A0 */   sb        $v0, 0x1848($a0)
    /* 3CA6C 800A526C 481880A0 */  sb         $zero, 0x1848($a0)
  .L800A5270:
    /* 3CA70 800A5270 4C1880A4 */  sh         $zero, 0x184C($a0)
    /* 3CA74 800A5274 501880AC */  sw         $zero, 0x1850($a0)
    /* 3CA78 800A5278 0800E003 */  jr         $ra
    /* 3CA7C 800A527C 4E1880A4 */   sh        $zero, 0x184E($a0)
endlabel func_800A525C
