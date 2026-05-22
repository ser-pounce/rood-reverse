nonmatching func_800CD3A0, 0x44

glabel func_800CD3A0
    /* 64BA0 800CD3A0 0100A230 */  andi       $v0, $a1, 0x1
    /* 64BA4 800CD3A4 07004010 */  beqz       $v0, .L800CD3C4
    /* 64BA8 800CD3A8 21188000 */   addu      $v1, $a0, $zero
    /* 64BAC 800CD3AC FF006430 */  andi       $a0, $v1, 0xFF
    /* 64BB0 800CD3B0 031A0300 */  sra        $v1, $v1, 8
    /* 64BB4 800CD3B4 FF000224 */  addiu      $v0, $zero, 0xFF
    /* 64BB8 800CD3B8 23104300 */  subu       $v0, $v0, $v1
    /* 64BBC 800CD3BC 00120200 */  sll        $v0, $v0, 8
    /* 64BC0 800CD3C0 25188200 */  or         $v1, $a0, $v0
  .L800CD3C4:
    /* 64BC4 800CD3C4 0200A230 */  andi       $v0, $a1, 0x2
    /* 64BC8 800CD3C8 04004010 */  beqz       $v0, .L800CD3DC
    /* 64BCC 800CD3CC 27100300 */   nor       $v0, $zero, $v1
    /* 64BD0 800CD3D0 FF004230 */  andi       $v0, $v0, 0xFF
    /* 64BD4 800CD3D4 00FF6330 */  andi       $v1, $v1, 0xFF00
    /* 64BD8 800CD3D8 25184300 */  or         $v1, $v0, $v1
  .L800CD3DC:
    /* 64BDC 800CD3DC 0800E003 */  jr         $ra
    /* 64BE0 800CD3E0 21106000 */   addu      $v0, $v1, $zero
endlabel func_800CD3A0
