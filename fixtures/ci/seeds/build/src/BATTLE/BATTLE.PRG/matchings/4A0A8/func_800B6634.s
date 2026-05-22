nonmatching func_800B6634, 0x58

glabel func_800B6634
    /* 4DE34 800B6634 0F80023C */  lui        $v0, %hi(D_800F4538)
    /* 4DE38 800B6638 38454224 */  addiu      $v0, $v0, %lo(D_800F4538)
    /* 4DE3C 800B663C 80180400 */  sll        $v1, $a0, 2
    /* 4DE40 800B6640 21104300 */  addu       $v0, $v0, $v1
    /* 4DE44 800B6644 0000428C */  lw         $v0, 0x0($v0)
    /* 4DE48 800B6648 F4FFBD27 */  addiu      $sp, $sp, -0xC
    /* 4DE4C 800B664C 3C064894 */  lhu        $t0, 0x63C($v0)
    /* 4DE50 800B6650 0000BFAF */  sw         $ra, 0x0($sp)
    /* 4DE54 800B6654 80000634 */  ori        $a2, $zero, 0x80
    /* 4DE58 800B6658 8000082D */  sltiu      $t0, $t0, 0x80
    /* 4DE5C 800B665C 02000011 */  beqz       $t0, .L800B6668
    /* 4DE60 800B6660 0400A4AF */   sw        $a0, 0x4($sp)
    /* 4DE64 800B6664 20000634 */  ori        $a2, $zero, 0x20
  .L800B6668:
    /* 4DE68 800B6668 ADA7020C */  jal        func_800A9EB4
    /* 4DE6C 800B666C 0800A5AF */   sw        $a1, 0x8($sp)
  .L800B6670:
    /* 4DE70 800B6670 0400A48F */  lw         $a0, 0x4($sp)
    /* 4DE74 800B6674 2789020C */  jal        func_800A249C
    /* 4DE78 800B6678 0800A58F */   lw        $a1, 0x8($sp)
    /* 4DE7C 800B667C 0000BF8F */  lw         $ra, 0x0($sp)
    /* 4DE80 800B6680 0C00BD27 */  addiu      $sp, $sp, 0xC
    /* 4DE84 800B6684 0800E003 */  jr         $ra
    /* 4DE88 800B6688 00000000 */   nop
endlabel func_800B6634
