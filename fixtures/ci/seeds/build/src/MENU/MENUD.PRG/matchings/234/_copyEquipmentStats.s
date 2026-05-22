nonmatching _copyEquipmentStats, 0xE8

glabel _copyEquipmentStats
    /* 3044 80105844 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 3048 80105848 02000224 */  addiu      $v0, $zero, 0x2
    /* 304C 8010584C 1A00A210 */  beq        $a1, $v0, .L801058B8
    /* 3050 80105850 1000BFAF */   sw        $ra, 0x10($sp)
    /* 3054 80105854 0300A228 */  slti       $v0, $a1, 0x3
    /* 3058 80105858 05004010 */  beqz       $v0, .L80105870
    /* 305C 8010585C 01000224 */   addiu     $v0, $zero, 0x1
    /* 3060 80105860 0A00A210 */  beq        $a1, $v0, .L8010588C
    /* 3064 80105864 1180023C */   lui       $v0, %hi(vs_menuD_containerData)
    /* 3068 80105868 47160408 */  j          .L8010591C
    /* 306C 8010586C 00000000 */   nop
  .L80105870:
    /* 3070 80105870 04000224 */  addiu      $v0, $zero, 0x4
    /* 3074 80105874 1800A210 */  beq        $a1, $v0, .L801058D8
    /* 3078 80105878 05000224 */   addiu     $v0, $zero, 0x5
    /* 307C 8010587C 2000A210 */  beq        $a1, $v0, .L80105900
    /* 3080 80105880 1180023C */   lui       $v0, %hi(vs_menuD_containerData)
    /* 3084 80105884 47160408 */  j          .L8010591C
    /* 3088 80105888 00000000 */   nop
  .L8010588C:
    /* 308C 8010588C 40280600 */  sll        $a1, $a2, 1
    /* 3090 80105890 2128A600 */  addu       $a1, $a1, $a2
    /* 3094 80105894 80280500 */  sll        $a1, $a1, 2
    /* 3098 80105898 2328A600 */  subu       $a1, $a1, $a2
    /* 309C 8010589C 80280500 */  sll        $a1, $a1, 2
    /* 30A0 801058A0 8C9A428C */  lw         $v0, %lo(vs_menuD_containerData)($v0)
    /* 30A4 801058A4 000AA524 */  addiu      $a1, $a1, 0xA00
    /* 30A8 801058A8 D1AA010C */  jal        vs_battle_copyInventoryBladeStats
    /* 30AC 801058AC 21284500 */   addu      $a1, $v0, $a1
    /* 30B0 801058B0 47160408 */  j          .L8010591C
    /* 30B4 801058B4 00000000 */   nop
  .L801058B8:
    /* 30B8 801058B8 1180023C */  lui        $v0, %hi(vs_menuD_containerData)
    /* 30BC 801058BC 00290600 */  sll        $a1, $a2, 4
    /* 30C0 801058C0 8C9A428C */  lw         $v0, %lo(vs_menuD_containerData)($v0)
    /* 30C4 801058C4 0015A524 */  addiu      $a1, $a1, 0x1500
    /* 30C8 801058C8 1DAB010C */  jal        vs_battle_copyInventoryGripStats
    /* 30CC 801058CC 21284500 */   addu      $a1, $v0, $a1
    /* 30D0 801058D0 47160408 */  j          .L8010591C
    /* 30D4 801058D4 00000000 */   nop
  .L801058D8:
    /* 30D8 801058D8 1180023C */  lui        $v0, %hi(vs_menuD_containerData)
    /* 30DC 801058DC 80280600 */  sll        $a1, $a2, 2
    /* 30E0 801058E0 2128A600 */  addu       $a1, $a1, $a2
    /* 30E4 801058E4 C0280500 */  sll        $a1, $a1, 3
    /* 30E8 801058E8 8C9A428C */  lw         $v0, %lo(vs_menuD_containerData)($v0)
    /* 30EC 801058EC 0019A524 */  addiu      $a1, $a1, 0x1900
    /* 30F0 801058F0 3FAB010C */  jal        vs_battle_copyInventoryArmorStats
    /* 30F4 801058F4 21284500 */   addu      $a1, $v0, $a1
    /* 30F8 801058F8 47160408 */  j          .L8010591C
    /* 30FC 801058FC 00000000 */   nop
  .L80105900:
    /* 3100 80105900 C0280600 */  sll        $a1, $a2, 3
    /* 3104 80105904 2328A600 */  subu       $a1, $a1, $a2
    /* 3108 80105908 80280500 */  sll        $a1, $a1, 2
    /* 310C 8010590C 8C9A428C */  lw         $v0, %lo(vs_menuD_containerData)($v0)
    /* 3110 80105910 0023A524 */  addiu      $a1, $a1, 0x2300
    /* 3114 80105914 83AB010C */  jal        vs_battle_copyInventoryGemStats
    /* 3118 80105918 21284500 */   addu      $a1, $v0, $a1
  .L8010591C:
    /* 311C 8010591C 1000BF8F */  lw         $ra, 0x10($sp)
    /* 3120 80105920 00000000 */  nop
    /* 3124 80105924 0800E003 */  jr         $ra
    /* 3128 80105928 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel _copyEquipmentStats
