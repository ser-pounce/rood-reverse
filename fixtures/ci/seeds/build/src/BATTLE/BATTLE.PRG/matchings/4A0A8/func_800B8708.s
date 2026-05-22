nonmatching func_800B8708, 0x5C

glabel func_800B8708
    /* 4FF08 800B8708 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 4FF0C 800B870C 21188000 */  addu       $v1, $a0, $zero
    /* 4FF10 800B8710 1000BFAF */  sw         $ra, 0x10($sp)
    /* 4FF14 800B8714 01006490 */  lbu        $a0, 0x1($v1)
    /* 4FF18 800B8718 00000000 */  nop
    /* 4FF1C 800B871C 04008230 */  andi       $v0, $a0, 0x4
    /* 4FF20 800B8720 05004010 */  beqz       $v0, .L800B8738
    /* 4FF24 800B8724 00000000 */   nop
    /* 4FF28 800B8728 13F3010C */  jal        func_8007CC4C
    /* 4FF2C 800B872C 03008430 */   andi      $a0, $a0, 0x3
    /* 4FF30 800B8730 D2E10208 */  j          .L800B8748
    /* 4FF34 800B8734 0F80023C */   lui       $v0, %hi(D_800F4C2C)
  .L800B8738:
    /* 4FF38 800B8738 01006490 */  lbu        $a0, 0x1($v1)
    /* 4FF3C 800B873C EFF2010C */  jal        func_8007CBBC
    /* 4FF40 800B8740 00000000 */   nop
    /* 4FF44 800B8744 0F80023C */  lui        $v0, %hi(D_800F4C2C)
  .L800B8748:
    /* 4FF48 800B8748 2C4C4290 */  lbu        $v0, %lo(D_800F4C2C)($v0)
    /* 4FF4C 800B874C 1000BF8F */  lw         $ra, 0x10($sp)
    /* 4FF50 800B8750 02004238 */  xori       $v0, $v0, 0x2
    /* 4FF54 800B8754 0100422C */  sltiu      $v0, $v0, 0x1
    /* 4FF58 800B8758 80100200 */  sll        $v0, $v0, 2
    /* 4FF5C 800B875C 0800E003 */  jr         $ra
    /* 4FF60 800B8760 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800B8708
