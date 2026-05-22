nonmatching func_800231E4, 0x30

glabel func_800231E4
    /* 139E4 800231E4 03000324 */  addiu      $v1, $zero, 0x3
    /* 139E8 800231E8 03008224 */  addiu      $v0, $a0, 0x3
    /* 139EC 800231EC 000080AC */  sw         $zero, 0x0($a0)
    /* 139F0 800231F0 040080A0 */  sb         $zero, 0x4($a0)
  .L800231F4:
    /* 139F4 800231F4 050040A0 */  sb         $zero, 0x5($v0)
    /* 139F8 800231F8 FFFF6324 */  addiu      $v1, $v1, -0x1
    /* 139FC 800231FC FDFF6104 */  bgez       $v1, .L800231F4
    /* 13A00 80023200 FFFF4224 */   addiu     $v0, $v0, -0x1
    /* 13A04 80023204 0C0080AC */  sw         $zero, 0xC($a0)
    /* 13A08 80023208 100080AC */  sw         $zero, 0x10($a0)
    /* 13A0C 8002320C 0800E003 */  jr         $ra
    /* 13A10 80023210 140080AC */   sw        $zero, 0x14($a0)
endlabel func_800231E4
