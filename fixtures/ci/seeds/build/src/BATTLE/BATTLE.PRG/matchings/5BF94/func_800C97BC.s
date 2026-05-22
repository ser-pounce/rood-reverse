nonmatching func_800C97BC, 0x104

glabel func_800C97BC
    /* 60FBC 800C97BC D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 60FC0 800C97C0 0F80023C */  lui        $v0, %hi(vs_battle_menuItems)
    /* 60FC4 800C97C4 1800B2AF */  sw         $s2, 0x18($sp)
    /* 60FC8 800C97C8 C0B9528C */  lw         $s2, %lo(vs_battle_menuItems)($v0)
    /* 60FCC 800C97CC 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 60FD0 800C97D0 0F80133C */  lui        $s3, %hi(vs_battle_menuState)
    /* 60FD4 800C97D4 1000B0AF */  sw         $s0, 0x10($sp)
    /* 60FD8 800C97D8 C0517092 */  lbu        $s0, %lo(vs_battle_menuState)($s3)
    /* 60FDC 800C97DC 7F000224 */  addiu      $v0, $zero, 0x7F
    /* 60FE0 800C97E0 2000BFAF */  sw         $ra, 0x20($sp)
    /* 60FE4 800C97E4 06000216 */  bne        $s0, $v0, .L800C9800
    /* 60FE8 800C97E8 1400B1AF */   sw        $s1, 0x14($sp)
    /* 60FEC 800C97EC 0F80023C */  lui        $v0, %hi(D_800F4E98)
    /* 60FF0 800C97F0 02000324 */  addiu      $v1, $zero, 0x2
    /* 60FF4 800C97F4 984E43A4 */  sh         $v1, %lo(D_800F4E98)($v0)
    /* 60FF8 800C97F8 3F000224 */  addiu      $v0, $zero, 0x3F
    /* 60FFC 800C97FC C05162A2 */  sb         $v0, %lo(vs_battle_menuState)($s3)
  .L800C9800:
    /* 61000 800C9800 3F001132 */  andi       $s1, $s0, 0x3F
    /* 61004 800C9804 3F000224 */  addiu      $v0, $zero, 0x3F
    /* 61008 800C9808 26002212 */  beq        $s1, $v0, .L800C98A4
    /* 6100C 800C980C 00000000 */   nop
    /* 61010 800C9810 1423030C */  jal        vs_battle_loadMenuPrg
    /* 61014 800C9814 21200000 */   addu      $a0, $zero, $zero
    /* 61018 800C9818 0D004010 */  beqz       $v0, .L800C9850
    /* 6101C 800C981C 0F80023C */   lui       $v0, %hi(vs_battle_shortcutInvoked)
    /* 61020 800C9820 6A4E4390 */  lbu        $v1, %lo(vs_battle_shortcutInvoked)($v0)
    /* 61024 800C9824 05000224 */  addiu      $v0, $zero, 0x5
    /* 61028 800C9828 05006214 */  bne        $v1, $v0, .L800C9840
    /* 6102C 800C982C 00000000 */   nop
    /* 61030 800C9830 AFEB030C */  jal        func_800FAEBC
    /* 61034 800C9834 21200000 */   addu      $a0, $zero, $zero
    /* 61038 800C9838 29260308 */  j          .L800C98A4
    /* 6103C 800C983C 00000000 */   nop
  .L800C9840:
    /* 61040 800C9840 B2EA030C */  jal        vs_mainMenu_exec
    /* 61044 800C9844 21200002 */   addu      $a0, $s0, $zero
    /* 61048 800C9848 29260308 */  j          .L800C98A4
    /* 6104C 800C984C 00000000 */   nop
  .L800C9850:
    /* 61050 800C9850 0A002016 */  bnez       $s1, .L800C987C
    /* 61054 800C9854 1F00022A */   slti      $v0, $s0, 0x1F
    /* 61058 800C9858 C324030C */  jal        func_800C930C
    /* 6105C 800C985C 21200000 */   addu      $a0, $zero, $zero
    /* 61060 800C9860 05004010 */  beqz       $v0, .L800C9878
    /* 61064 800C9864 00000000 */   nop
    /* 61068 800C9868 02004018 */  blez       $v0, .L800C9874
    /* 6106C 800C986C 1F001024 */   addiu     $s0, $zero, 0x1F
    /* 61070 800C9870 40005034 */  ori        $s0, $v0, 0x40
  .L800C9874:
    /* 61074 800C9874 C05170A2 */  sb         $s0, %lo(vs_battle_menuState)($s3)
  .L800C9878:
    /* 61078 800C9878 1F00022A */  slti       $v0, $s0, 0x1F
  .L800C987C:
    /* 6107C 800C987C 03004010 */  beqz       $v0, .L800C988C
    /* 61080 800C9880 21800000 */   addu      $s0, $zero, $zero
    /* 61084 800C9884 07002016 */  bnez       $s1, .L800C98A4
    /* 61088 800C9888 00000000 */   nop
  .L800C988C:
    /* 6108C 800C988C 1E24030C */  jal        func_800C9078
    /* 61090 800C9890 21204002 */   addu      $a0, $s2, $zero
    /* 61094 800C9894 01001026 */  addiu      $s0, $s0, 0x1
    /* 61098 800C9898 0A00022A */  slti       $v0, $s0, 0xA
    /* 6109C 800C989C FBFF4014 */  bnez       $v0, .L800C988C
    /* 610A0 800C98A0 40005226 */   addiu     $s2, $s2, 0x40
  .L800C98A4:
    /* 610A4 800C98A4 2000BF8F */  lw         $ra, 0x20($sp)
    /* 610A8 800C98A8 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 610AC 800C98AC 1800B28F */  lw         $s2, 0x18($sp)
    /* 610B0 800C98B0 1400B18F */  lw         $s1, 0x14($sp)
    /* 610B4 800C98B4 1000B08F */  lw         $s0, 0x10($sp)
    /* 610B8 800C98B8 0800E003 */  jr         $ra
    /* 610BC 800C98BC 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_800C97BC
