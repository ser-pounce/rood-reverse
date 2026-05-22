nonmatching func_8006A5C0, 0x2A0

glabel func_8006A5C0
    /* 1DC0 8006A5C0 C8FFBD27 */  addiu      $sp, $sp, -0x38
    /* 1DC4 8006A5C4 3000BFAF */  sw         $ra, 0x30($sp)
    /* 1DC8 8006A5C8 2C00B5AF */  sw         $s5, 0x2C($sp)
    /* 1DCC 8006A5CC 2800B4AF */  sw         $s4, 0x28($sp)
    /* 1DD0 8006A5D0 2400B3AF */  sw         $s3, 0x24($sp)
    /* 1DD4 8006A5D4 2000B2AF */  sw         $s2, 0x20($sp)
    /* 1DD8 8006A5D8 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 1DDC 8006A5DC 21AE010C */  jal        func_8006B884
    /* 1DE0 8006A5E0 1800B0AF */   sw        $s0, 0x18($sp)
    /* 1DE4 8006A5E4 A0000424 */  addiu      $a0, $zero, 0xA0
    /* 1DE8 8006A5E8 5005010C */  jal        SetGeomOffset
    /* 1DEC 8006A5EC 70000524 */   addiu     $a1, $zero, 0x70
    /* 1DF0 8006A5F0 4D05010C */  jal        SetGeomScreen
    /* 1DF4 8006A5F4 00020424 */   addiu     $a0, $zero, 0x200
    /* 1DF8 8006A5F8 0680103C */  lui        $s0, %hi(vs_main_drawEnv)
    /* 1DFC 8006A5FC D0E01026 */  addiu      $s0, $s0, %lo(vs_main_drawEnv)
    /* 1E00 8006A600 18AA010C */  jal        func_8006A860
    /* 1E04 8006A604 21200002 */   addu      $a0, $s0, $zero
    /* 1E08 8006A608 18AA010C */  jal        func_8006A860
    /* 1E0C 8006A60C 5C000426 */   addiu     $a0, $s0, 0x5C
    /* 1E10 8006A610 0780043C */  lui        $a0, %hi(D_8007005C)
    /* 1E14 8006A614 5C008424 */  addiu      $a0, $a0, %lo(D_8007005C)
    /* 1E18 8006A618 0680023C */  lui        $v0, %hi(vs_main_dispEnv)
    /* 1E1C 8006A61C 88E14224 */  addiu      $v0, $v0, %lo(vs_main_dispEnv)
    /* 1E20 8006A620 240040A0 */  sb         $zero, 0x24($v0)
    /* 1E24 8006A624 70AA010C */  jal        func_8006A9C0
    /* 1E28 8006A628 100040A0 */   sb        $zero, 0x10($v0)
    /* 1E2C 8006A62C 0D80043C */  lui        $a0, %hi(D_800CF33C)
    /* 1E30 8006A630 70AA010C */  jal        func_8006A9C0
    /* 1E34 8006A634 3CF38424 */   addiu     $a0, $a0, %lo(D_800CF33C)
    /* 1E38 8006A638 0D80043C */  lui        $a0, %hi(D_800D7F7C)
    /* 1E3C 8006A63C 70AA010C */  jal        func_8006A9C0
    /* 1E40 8006A640 7C7F8424 */   addiu     $a0, $a0, %lo(D_800D7F7C)
    /* 1E44 8006A644 0E80043C */  lui        $a0, %hi(D_800D975C)
    /* 1E48 8006A648 70AA010C */  jal        func_8006A9C0
    /* 1E4C 8006A64C 5C978424 */   addiu     $a0, $a0, %lo(D_800D975C)
    /* 1E50 8006A650 0E80043C */  lui        $a0, %hi(D_800D837C)
    /* 1E54 8006A654 70AA010C */  jal        func_8006A9C0
    /* 1E58 8006A658 7C838424 */   addiu     $a0, $a0, %lo(D_800D837C)
    /* 1E5C 8006A65C 0E80043C */  lui        $a0, %hi(D_800DB09C)
    /* 1E60 8006A660 70AA010C */  jal        func_8006A9C0
    /* 1E64 8006A664 9CB08424 */   addiu     $a0, $a0, %lo(D_800DB09C)
    /* 1E68 8006A668 0E80043C */  lui        $a0, %hi(D_800DB26C)
    /* 1E6C 8006A66C 70AA010C */  jal        func_8006A9C0
    /* 1E70 8006A670 6CB28424 */   addiu     $a0, $a0, %lo(D_800DB26C)
    /* 1E74 8006A674 0780043C */  lui        $a0, %hi(D_8007709C)
    /* 1E78 8006A678 70AA010C */  jal        func_8006A9C0
    /* 1E7C 8006A67C 9C708424 */   addiu     $a0, $a0, %lo(D_8007709C)
    /* 1E80 8006A680 0980043C */  lui        $a0, %hi(D_80088ABC)
    /* 1E84 8006A684 70AA010C */  jal        func_8006A9C0
    /* 1E88 8006A688 BC8A8424 */   addiu     $a0, $a0, %lo(D_80088ABC)
    /* 1E8C 8006A68C 0A80043C */  lui        $a0, %hi(D_8009A4DC)
    /* 1E90 8006A690 70AA010C */  jal        func_8006A9C0
    /* 1E94 8006A694 DCA48424 */   addiu     $a0, $a0, %lo(D_8009A4DC)
    /* 1E98 8006A698 0B80043C */  lui        $a0, %hi(D_800ABEFC)
    /* 1E9C 8006A69C 70AA010C */  jal        func_8006A9C0
    /* 1EA0 8006A6A0 FCBE8424 */   addiu     $a0, $a0, %lo(D_800ABEFC)
    /* 1EA4 8006A6A4 0C80043C */  lui        $a0, %hi(D_800BD91C)
    /* 1EA8 8006A6A8 70AA010C */  jal        func_8006A9C0
    /* 1EAC 8006A6AC 1CD98424 */   addiu     $a0, $a0, %lo(D_800BD91C)
    /* 1EB0 8006A6B0 05001124 */  addiu      $s1, $zero, 0x5
    /* 1EB4 8006A6B4 0E80023C */  lui        $v0, %hi(_illustLbas)
    /* 1EB8 8006A6B8 30B75524 */  addiu      $s5, $v0, %lo(_illustLbas)
    /* 1EBC 8006A6BC 0E80023C */  lui        $v0, %hi(_illustSizes)
    /* 1EC0 8006A6C0 70B75424 */  addiu      $s4, $v0, %lo(_illustSizes)
    /* 1EC4 8006A6C4 0E80023C */  lui        $v0, %hi(D_800DC1A8)
    /* 1EC8 8006A6C8 A8C15324 */  addiu      $s3, $v0, %lo(D_800DC1A8)
    /* 1ECC 8006A6CC 04001224 */  addiu      $s2, $zero, 0x4
    /* 1ED0 8006A6D0 00841100 */  sll        $s0, $s1, 16
  .L8006A6D4:
    /* 1ED4 8006A6D4 03841000 */  sra        $s0, $s0, 16
    /* 1ED8 8006A6D8 FBFF0326 */  addiu      $v1, $s0, -0x5
    /* 1EDC 8006A6DC 80180300 */  sll        $v1, $v1, 2
    /* 1EE0 8006A6E0 21107500 */  addu       $v0, $v1, $s5
    /* 1EE4 8006A6E4 0000428C */  lw         $v0, 0x0($v0)
    /* 1EE8 8006A6E8 21187400 */  addu       $v1, $v1, $s4
    /* 1EEC 8006A6EC 1000A2AF */  sw         $v0, 0x10($sp)
    /* 1EF0 8006A6F0 0000648C */  lw         $a0, 0x0($v1)
    /* 1EF4 8006A6F4 8F0F010C */  jal        vs_main_allocHeapR
    /* 1EF8 8006A6F8 1400A4AF */   sw        $a0, 0x14($sp)
    /* 1EFC 8006A6FC 1000A427 */  addiu      $a0, $sp, 0x10
    /* 1F00 8006A700 80801000 */  sll        $s0, $s0, 2
    /* 1F04 8006A704 21801302 */  addu       $s0, $s0, $s3
    /* 1F08 8006A708 C412010C */  jal        vs_main_allocateCdQueueSlot
    /* 1F0C 8006A70C 000002AE */   sw        $v0, 0x0($s0)
    /* 1F10 8006A710 0000058E */  lw         $a1, 0x0($s0)
    /* 1F14 8006A714 21804000 */  addu       $s0, $v0, $zero
    /* 1F18 8006A718 FD12010C */  jal        vs_main_cdEnqueuePriority
    /* 1F1C 8006A71C 21200002 */   addu      $a0, $s0, $zero
  .L8006A720:
    /* 1F20 8006A720 8709010C */  jal        vs_main_gametimeUpdate
    /* 1F24 8006A724 21200000 */   addu      $a0, $zero, $zero
    /* 1F28 8006A728 00000286 */  lh         $v0, 0x0($s0)
    /* 1F2C 8006A72C 00000000 */  nop
    /* 1F30 8006A730 FBFF5214 */  bne        $v0, $s2, .L8006A720
    /* 1F34 8006A734 00000000 */   nop
    /* 1F38 8006A738 E012010C */  jal        vs_main_freeCdQueueSlot
    /* 1F3C 8006A73C 21200002 */   addu      $a0, $s0, $zero
    /* 1F40 8006A740 01002226 */  addiu      $v0, $s1, 0x1
    /* 1F44 8006A744 21884000 */  addu       $s1, $v0, $zero
    /* 1F48 8006A748 00140200 */  sll        $v0, $v0, 16
    /* 1F4C 8006A74C 03140200 */  sra        $v0, $v0, 16
    /* 1F50 8006A750 10004228 */  slti       $v0, $v0, 0x10
    /* 1F54 8006A754 DFFF4014 */  bnez       $v0, .L8006A6D4
    /* 1F58 8006A758 00841100 */   sll       $s0, $s1, 16
    /* 1F5C 8006A75C 0E80023C */  lui        $v0, %hi(D_800DC19C)
    /* 1F60 8006A760 9CC140A4 */  sh         $zero, %lo(D_800DC19C)($v0)
    /* 1F64 8006A764 0E80023C */  lui        $v0, %hi(D_800DC18A)
    /* 1F68 8006A768 9BAA010C */  jal        func_8006AA6C
    /* 1F6C 8006A76C 8AC140A0 */   sb        $zero, %lo(D_800DC18A)($v0)
    /* 1F70 8006A770 0780043C */  lui        $a0, %hi(func_8006A0D8)
    /* 1F74 8006A774 D1AA010C */  jal        func_8006AB44
    /* 1F78 8006A778 D8A08424 */   addiu     $a0, $a0, %lo(func_8006A0D8)
    /* 1F7C 8006A77C 94A1000C */  jal        DrawSync
    /* 1F80 8006A780 21200000 */   addu      $a0, $zero, $zero
    /* 1F84 8006A784 6EA1000C */  jal        SetDispMask
    /* 1F88 8006A788 01000424 */   addiu     $a0, $zero, 0x1
    /* 1F8C 8006A78C 0E80033C */  lui        $v1, %hi(D_800DC194)
    /* 1F90 8006A790 0780023C */  lui        $v0, %hi(D_8006E3FC)
    /* 1F94 8006A794 FCE34224 */  addiu      $v0, $v0, %lo(D_8006E3FC)
    /* 1F98 8006A798 94C162AC */  sw         $v0, %lo(D_800DC194)($v1)
    /* 1F9C 8006A79C 0E80033C */  lui        $v1, %hi(D_800DC198)
    /* 1FA0 8006A7A0 80FF0224 */  addiu      $v0, $zero, -0x80
    /* 1FA4 8006A7A4 98C162A4 */  sh         $v0, %lo(D_800DC198)($v1)
    /* 1FA8 8006A7A8 0E80023C */  lui        $v0, %hi(D_800DC188)
    /* 1FAC 8006A7AC 88C140A0 */  sb         $zero, %lo(D_800DC188)($v0)
    /* 1FB0 8006A7B0 0E80023C */  lui        $v0, %hi(D_800DC190)
    /* 1FB4 8006A7B4 90C140AC */  sw         $zero, %lo(D_800DC190)($v0)
    /* 1FB8 8006A7B8 0E80023C */  lui        $v0, %hi(D_800DC18C)
    /* 1FBC 8006A7BC 0E80033C */  lui        $v1, %hi(D_800DC189)
    /* 1FC0 8006A7C0 8CC140AC */  sw         $zero, %lo(D_800DC18C)($v0)
    /* 1FC4 8006A7C4 01000224 */  addiu      $v0, $zero, 0x1
    /* 1FC8 8006A7C8 6DAE010C */  jal        func_8006B9B4
    /* 1FCC 8006A7CC 89C162A0 */   sb        $v0, %lo(D_800DC189)($v1)
    /* 1FD0 8006A7D0 22AA010C */  jal        func_8006A888
    /* 1FD4 8006A7D4 05001124 */   addiu     $s1, $zero, 0x5
    /* 1FD8 8006A7D8 8E12010C */  jal        vs_main_checkStreamXaEnd
    /* 1FDC 8006A7DC 00000000 */   nop
    /* 1FE0 8006A7E0 6EA1000C */  jal        SetDispMask
    /* 1FE4 8006A7E4 21200000 */   addu      $a0, $zero, $zero
    /* 1FE8 8006A7E8 0E80023C */  lui        $v0, %hi(D_800DC1A8)
    /* 1FEC 8006A7EC A8C15024 */  addiu      $s0, $v0, %lo(D_800DC1A8)
    /* 1FF0 8006A7F0 00141100 */  sll        $v0, $s1, 16
  .L8006A7F4:
    /* 1FF4 8006A7F4 83130200 */  sra        $v0, $v0, 14
    /* 1FF8 8006A7F8 21105000 */  addu       $v0, $v0, $s0
    /* 1FFC 8006A7FC 0000448C */  lw         $a0, 0x0($v0)
    /* 2000 8006A800 180F010C */  jal        vs_main_freeHeapR
    /* 2004 8006A804 00000000 */   nop
    /* 2008 8006A808 01002226 */  addiu      $v0, $s1, 0x1
    /* 200C 8006A80C 21884000 */  addu       $s1, $v0, $zero
    /* 2010 8006A810 00140200 */  sll        $v0, $v0, 16
    /* 2014 8006A814 03140200 */  sra        $v0, $v0, 16
    /* 2018 8006A818 10004228 */  slti       $v0, $v0, 0x10
    /* 201C 8006A81C F5FF4014 */  bnez       $v0, .L8006A7F4
    /* 2020 8006A820 00141100 */   sll       $v0, $s1, 16
    /* 2024 8006A824 77AE010C */  jal        func_8006B9DC
    /* 2028 8006A828 00000000 */   nop
    /* 202C 8006A82C 44AE010C */  jal        func_8006B910
    /* 2030 8006A830 00000000 */   nop
    /* 2034 8006A834 5EAF010C */  jal        func_8006BD78
    /* 2038 8006A838 00000000 */   nop
    /* 203C 8006A83C 3000BF8F */  lw         $ra, 0x30($sp)
    /* 2040 8006A840 2C00B58F */  lw         $s5, 0x2C($sp)
    /* 2044 8006A844 2800B48F */  lw         $s4, 0x28($sp)
    /* 2048 8006A848 2400B38F */  lw         $s3, 0x24($sp)
    /* 204C 8006A84C 2000B28F */  lw         $s2, 0x20($sp)
    /* 2050 8006A850 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 2054 8006A854 1800B08F */  lw         $s0, 0x18($sp)
    /* 2058 8006A858 0800E003 */  jr         $ra
    /* 205C 8006A85C 3800BD27 */   addiu     $sp, $sp, 0x38
endlabel func_8006A5C0
