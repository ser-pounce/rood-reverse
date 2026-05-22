nonmatching func_80106A04, 0x4C

glabel func_80106A04
    /* 4204 80106A04 21300000 */  addu       $a2, $zero, $zero
    /* 4208 80106A08 00220400 */  sll        $a0, $a0, 8
    /* 420C 80106A0C 0100A524 */  addiu      $a1, $a1, 0x1
    /* 4210 80106A10 25208500 */  or         $a0, $a0, $a1
    /* 4214 80106A14 1080023C */  lui        $v0, %hi(vs_menu_inventoryStorage)
    /* 4218 80106A18 5C24438C */  lw         $v1, %lo(vs_menu_inventoryStorage)($v0)
    /* 421C 80106A1C B0C30234 */  ori        $v0, $zero, 0xC3B0
    /* 4220 80106A20 21186200 */  addu       $v1, $v1, $v0
  .L80106A24:
    /* 4224 80106A24 00006294 */  lhu        $v0, 0x0($v1)
    /* 4228 80106A28 00000000 */  nop
    /* 422C 80106A2C 03004014 */  bnez       $v0, .L80106A3C
    /* 4230 80106A30 0100C624 */   addiu     $a2, $a2, 0x1
    /* 4234 80106A34 0800E003 */  jr         $ra
    /* 4238 80106A38 000064A4 */   sh        $a0, 0x0($v1)
  .L80106A3C:
    /* 423C 80106A3C 4000C228 */  slti       $v0, $a2, 0x40
    /* 4240 80106A40 F8FF4014 */  bnez       $v0, .L80106A24
    /* 4244 80106A44 02006324 */   addiu     $v1, $v1, 0x2
    /* 4248 80106A48 0800E003 */  jr         $ra
    /* 424C 80106A4C 00000000 */   nop
endlabel func_80106A04
