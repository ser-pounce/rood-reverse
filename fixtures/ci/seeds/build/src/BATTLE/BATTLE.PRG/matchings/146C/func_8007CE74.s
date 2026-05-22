nonmatching func_8007CE74, 0x2C

glabel func_8007CE74
    /* 14674 8007CE74 00FD0224 */  addiu      $v0, $zero, -0x300
    /* 14678 8007CE78 03008210 */  beq        $a0, $v0, .L8007CE88
    /* 1467C 8007CE7C 80FF0224 */   addiu     $v0, $zero, -0x80
    /* 14680 8007CE80 04008214 */  bne        $a0, $v0, .L8007CE94
    /* 14684 8007CE84 0F80033C */   lui       $v1, %hi(D_800F19D4)
  .L8007CE88:
    /* 14688 8007CE88 0F80023C */  lui        $v0, %hi(D_800F19D4)
    /* 1468C 8007CE8C 0800E003 */  jr         $ra
    /* 14690 8007CE90 D41944AC */   sw        $a0, %lo(D_800F19D4)($v0)
  .L8007CE94:
    /* 14694 8007CE94 80FE0224 */  addiu      $v0, $zero, -0x180
    /* 14698 8007CE98 0800E003 */  jr         $ra
    /* 1469C 8007CE9C D41962AC */   sw        $v0, %lo(D_800F19D4)($v1)
endlabel func_8007CE74
