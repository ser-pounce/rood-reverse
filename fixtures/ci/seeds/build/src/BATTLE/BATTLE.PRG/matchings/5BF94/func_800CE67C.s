nonmatching func_800CE67C, 0x98

glabel func_800CE67C
    /* 65E7C 800CE67C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 65E80 800CE680 1000BFAF */  sw         $ra, 0x10($sp)
    /* 65E84 800CE684 1E3D030C */  jal        func_800CF478
    /* 65E88 800CE688 21200000 */   addu      $a0, $zero, $zero
    /* 65E8C 800CE68C 03000424 */  addiu      $a0, $zero, 0x3
    /* 65E90 800CE690 0F80023C */  lui        $v0, %hi(D_800F5320)
    /* 65E94 800CE694 20534224 */  addiu      $v0, $v0, %lo(D_800F5320)
    /* 65E98 800CE698 0C004324 */  addiu      $v1, $v0, 0xC
    /* 65E9C 800CE69C 0F80023C */  lui        $v0, %hi(D_800F5228)
    /* 65EA0 800CE6A0 285240AC */  sw         $zero, %lo(D_800F5228)($v0)
    /* 65EA4 800CE6A4 0F80023C */  lui        $v0, %hi(D_800F5224)
    /* 65EA8 800CE6A8 245240AC */  sw         $zero, %lo(D_800F5224)($v0)
    /* 65EAC 800CE6AC 0F80023C */  lui        $v0, %hi(D_800F54A8)
    /* 65EB0 800CE6B0 A85440A0 */  sb         $zero, %lo(D_800F54A8)($v0)
    /* 65EB4 800CE6B4 0F80023C */  lui        $v0, %hi(D_800F5318)
    /* 65EB8 800CE6B8 185340A0 */  sb         $zero, %lo(D_800F5318)($v0)
    /* 65EBC 800CE6BC 0F80023C */  lui        $v0, %hi(D_800F54B0)
    /* 65EC0 800CE6C0 B05440AC */  sw         $zero, %lo(D_800F54B0)($v0)
    /* 65EC4 800CE6C4 0F80023C */  lui        $v0, %hi(D_800F53BC)
    /* 65EC8 800CE6C8 BC5340AC */  sw         $zero, %lo(D_800F53BC)($v0)
    /* 65ECC 800CE6CC 0F80023C */  lui        $v0, %hi(D_800F53B4)
    /* 65ED0 800CE6D0 B45340AC */  sw         $zero, %lo(D_800F53B4)($v0)
    /* 65ED4 800CE6D4 0F80023C */  lui        $v0, %hi(D_800F53B8)
    /* 65ED8 800CE6D8 B85340AC */  sw         $zero, %lo(D_800F53B8)($v0)
    /* 65EDC 800CE6DC 0F80023C */  lui        $v0, %hi(D_800F5330)
    /* 65EE0 800CE6E0 305340AC */  sw         $zero, %lo(D_800F5330)($v0)
    /* 65EE4 800CE6E4 0F80023C */  lui        $v0, %hi(D_800F522C)
    /* 65EE8 800CE6E8 2C5240A0 */  sb         $zero, %lo(D_800F522C)($v0)
    /* 65EEC 800CE6EC 0F80023C */  lui        $v0, %hi(D_800F5218)
    /* 65EF0 800CE6F0 185240AC */  sw         $zero, %lo(D_800F5218)($v0)
  .L800CE6F4:
    /* 65EF4 800CE6F4 000060AC */  sw         $zero, 0x0($v1)
    /* 65EF8 800CE6F8 FFFF8424 */  addiu      $a0, $a0, -0x1
    /* 65EFC 800CE6FC FDFF8104 */  bgez       $a0, .L800CE6F4
    /* 65F00 800CE700 FCFF6324 */   addiu     $v1, $v1, -0x4
    /* 65F04 800CE704 1000BF8F */  lw         $ra, 0x10($sp)
    /* 65F08 800CE708 00000000 */  nop
    /* 65F0C 800CE70C 0800E003 */  jr         $ra
    /* 65F10 800CE710 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800CE67C
