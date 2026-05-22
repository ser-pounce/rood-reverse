nonmatching SpuSetTransferStartAddr, 0x5C

glabel SpuSetTransferStartAddr
    /* F3C4 8001EBC4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* F3C8 8001EBC8 21288000 */  addu       $a1, $a0, $zero
    /* F3CC 8001EBCC 0700023C */  lui        $v0, (0x7EFE8 >> 16)
    /* F3D0 8001EBD0 E8EF4234 */  ori        $v0, $v0, (0x7EFE8 & 0xFFFF)
    /* F3D4 8001EBD4 F0EFA324 */  addiu      $v1, $a1, -0x1010
    /* F3D8 8001EBD8 2B104300 */  sltu       $v0, $v0, $v1
    /* F3DC 8001EBDC 0B004014 */  bnez       $v0, .L8001EC0C
    /* F3E0 8001EBE0 1000BFAF */   sw        $ra, 0x10($sp)
    /* F3E4 8001EBE4 E978000C */  jal        _spu_FsetRXXa
    /* F3E8 8001EBE8 FFFF0424 */   addiu     $a0, $zero, -0x1
    /* F3EC 8001EBEC 0380013C */  lui        $at, %hi(D_80030878)
    /* F3F0 8001EBF0 780822A4 */  sh         $v0, %lo(D_80030878)($at)
    /* F3F4 8001EBF4 0380033C */  lui        $v1, %hi(D_80030878)
    /* F3F8 8001EBF8 78086394 */  lhu        $v1, %lo(D_80030878)($v1)
    /* F3FC 8001EBFC 0380023C */  lui        $v0, %hi(D_80030888)
    /* F400 8001EC00 8808428C */  lw         $v0, %lo(D_80030888)($v0)
    /* F404 8001EC04 047B0008 */  j          .L8001EC10
    /* F408 8001EC08 04104300 */   sllv      $v0, $v1, $v0
  .L8001EC0C:
    /* F40C 8001EC0C 21100000 */  addu       $v0, $zero, $zero
  .L8001EC10:
    /* F410 8001EC10 1000BF8F */  lw         $ra, 0x10($sp)
    /* F414 8001EC14 1800BD27 */  addiu      $sp, $sp, 0x18
    /* F418 8001EC18 0800E003 */  jr         $ra
    /* F41C 8001EC1C 00000000 */   nop
endlabel SpuSetTransferStartAddr
    /* F420 8001EC20 00000000 */  nop
