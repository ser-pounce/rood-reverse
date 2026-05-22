nonmatching func_800F9818, 0x84

glabel func_800F9818
    /* 18 800F9818 21280000 */  addu       $a1, $zero, $zero
    /* 1C 800F981C 0680023C */  lui        $v0, %hi(vs_main_skillsLearned)
    /* 20 800F9820 B8FF4824 */  addiu      $t0, $v0, %lo(vs_main_skillsLearned)
    /* 24 800F9824 80000724 */  addiu      $a3, $zero, 0x80
    /* 28 800F9828 FFFF063C */  lui        $a2, (0xFFFF7FFF >> 16)
    /* 2C 800F982C FF7FC634 */  ori        $a2, $a2, (0xFFFF7FFF & 0xFFFF)
    /* 30 800F9830 0580023C */  lui        $v0, %hi(vs_main_skills)
    /* 34 800F9834 DCB94424 */  addiu      $a0, $v0, %lo(vs_main_skills)
  .L800F9838:
    /* 38 800F9838 0200A104 */  bgez       $a1, .L800F9844
    /* 3C 800F983C 2110A000 */   addu      $v0, $a1, $zero
    /* 40 800F9840 0700A224 */  addiu      $v0, $a1, 0x7
  .L800F9844:
    /* 44 800F9844 C3100200 */  sra        $v0, $v0, 3
    /* 48 800F9848 21184800 */  addu       $v1, $v0, $t0
    /* 4C 800F984C 00006390 */  lbu        $v1, 0x0($v1)
    /* 50 800F9850 C0100200 */  sll        $v0, $v0, 3
    /* 54 800F9854 2310A200 */  subu       $v0, $a1, $v0
    /* 58 800F9858 07104700 */  srav       $v0, $a3, $v0
    /* 5C 800F985C 24186200 */  and        $v1, $v1, $v0
    /* 60 800F9860 04006010 */  beqz       $v1, .L800F9874
    /* 64 800F9864 00000000 */   nop
    /* 68 800F9868 0C00828C */  lw         $v0, 0xC($a0)
    /* 6C 800F986C 20E60308 */  j          .L800F9880
    /* 70 800F9870 00804234 */   ori       $v0, $v0, 0x8000
  .L800F9874:
    /* 74 800F9874 0C00828C */  lw         $v0, 0xC($a0)
    /* 78 800F9878 00000000 */  nop
    /* 7C 800F987C 24104600 */  and        $v0, $v0, $a2
  .L800F9880:
    /* 80 800F9880 0C0082AC */  sw         $v0, 0xC($a0)
    /* 84 800F9884 0100A524 */  addiu      $a1, $a1, 0x1
    /* 88 800F9888 0001A228 */  slti       $v0, $a1, 0x100
    /* 8C 800F988C EAFF4014 */  bnez       $v0, .L800F9838
    /* 90 800F9890 34008424 */   addiu     $a0, $a0, 0x34
    /* 94 800F9894 0800E003 */  jr         $ra
    /* 98 800F9898 00000000 */   nop
endlabel func_800F9818
