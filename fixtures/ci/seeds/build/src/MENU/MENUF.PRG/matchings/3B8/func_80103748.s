nonmatching func_80103748, 0x58

glabel func_80103748
    /* F48 80103748 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* F4C 8010374C 0680023C */  lui        $v0, %hi(vs_main_soundData + 0x8)
    /* F50 80103750 40E0448C */  lw         $a0, %lo(vs_main_soundData + 0x8)($v0)
    /* F54 80103754 07000224 */  addiu      $v0, $zero, 0x7
    /* F58 80103758 0A008210 */  beq        $a0, $v0, .L80103784
    /* F5C 8010375C 1000BFAF */   sw        $ra, 0x10($sp)
    /* F60 80103760 E1FF8224 */  addiu      $v0, $a0, -0x1F
    /* F64 80103764 0900422C */  sltiu      $v0, $v0, 0x9
    /* F68 80103768 04004014 */  bnez       $v0, .L8010377C
    /* F6C 8010376C D3FF8224 */   addiu     $v0, $a0, -0x2D
    /* F70 80103770 0500422C */  sltiu      $v0, $v0, 0x5
    /* F74 80103774 03004010 */  beqz       $v0, .L80103784
    /* F78 80103778 00000000 */   nop
  .L8010377C:
    /* F7C 8010377C E20D0408 */  j          .L80103788
    /* F80 80103780 64008424 */   addiu     $a0, $a0, 0x64
  .L80103784:
    /* F84 80103784 80000424 */  addiu      $a0, $zero, 0x80
  .L80103788:
    /* F88 80103788 4414010C */  jal        vs_main_loadMusicSlot
    /* F8C 8010378C 02000524 */   addiu     $a1, $zero, 0x2
    /* F90 80103790 1000BF8F */  lw         $ra, 0x10($sp)
    /* F94 80103794 00000000 */  nop
    /* F98 80103798 0800E003 */  jr         $ra
    /* F9C 8010379C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80103748
