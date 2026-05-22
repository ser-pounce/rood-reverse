nonmatching _padStartCom, 0xCC

glabel _padStartCom
    /* 1C7F4 8002BFF4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1C7F8 8002BFF8 1400BFAF */  sw         $ra, 0x14($sp)
    /* 1C7FC 8002BFFC 1000B0AF */  sw         $s0, 0x10($sp)
    /* 1C800 8002C000 0380013C */  lui        $at, %hi(D_800335D4)
    /* 1C804 8002C004 5D9A000C */  jal        EnterCriticalSection
    /* 1C808 8002C008 D43520AC */   sw        $zero, %lo(D_800335D4)($at)
    /* 1C80C 8002C00C 02000424 */  addiu      $a0, $zero, 0x2
    /* 1C810 8002C010 0480103C */  lui        $s0, %hi(D_8003FC00)
    /* 1C814 8002C014 00FC1026 */  addiu      $s0, $s0, %lo(D_8003FC00)
    /* 1C818 8002C018 A1B2000C */  jal        SysDeqIntRP
    /* 1C81C 8002C01C 21280002 */   addu      $a1, $s0, $zero
    /* 1C820 8002C020 02000424 */  addiu      $a0, $zero, 0x2
    /* 1C824 8002C024 9DB2000C */  jal        SysEnqIntRP
    /* 1C828 8002C028 21280002 */   addu      $a1, $s0, $zero
    /* 1C82C 8002C02C 03000424 */  addiu      $a0, $zero, 0x3
    /* 1C830 8002C030 0380033C */  lui        $v1, %hi(D_800335FC)
    /* 1C834 8002C034 FC35638C */  lw         $v1, %lo(D_800335FC)($v1)
    /* 1C838 8002C038 FEFF0224 */  addiu      $v0, $zero, -0x2
    /* 1C83C 8002C03C 000062AC */  sw         $v0, 0x0($v1)
    /* 1C840 8002C040 0400628C */  lw         $v0, 0x4($v1)
    /* 1C844 8002C044 21280000 */  addu       $a1, $zero, $zero
    /* 1C848 8002C048 01004234 */  ori        $v0, $v0, 0x1
    /* 1C84C 8002C04C 859A000C */  jal        ChangeClearRCnt
    /* 1C850 8002C050 040062AC */   sw        $v0, 0x4($v1)
    /* 1C854 8002C054 619A000C */  jal        ExitCriticalSection
    /* 1C858 8002C058 00000000 */   nop
    /* 1C85C 8002C05C 0380043C */  lui        $a0, %hi(D_800335D0)
    /* 1C860 8002C060 D035848C */  lw         $a0, %lo(D_800335D0)($a0)
    /* 1C864 8002C064 0380023C */  lui        $v0, %hi(D_800335A0)
    /* 1C868 8002C068 A035428C */  lw         $v0, %lo(D_800335A0)($v0)
    /* 1C86C 8002C06C 00000000 */  nop
    /* 1C870 8002C070 09F84000 */  jalr       $v0
    /* 1C874 8002C074 00000000 */   nop
    /* 1C878 8002C078 0380043C */  lui        $a0, %hi(D_800335D0)
    /* 1C87C 8002C07C D035848C */  lw         $a0, %lo(D_800335D0)($a0)
    /* 1C880 8002C080 0380023C */  lui        $v0, %hi(D_800335A0)
    /* 1C884 8002C084 A035428C */  lw         $v0, %lo(D_800335A0)($v0)
    /* 1C888 8002C088 00000000 */  nop
    /* 1C88C 8002C08C 09F84000 */  jalr       $v0
    /* 1C890 8002C090 F0008424 */   addiu     $a0, $a0, 0xF0
    /* 1C894 8002C094 0480023C */  lui        $v0, %hi(D_8003FC10)
    /* 1C898 8002C098 10FC4224 */  addiu      $v0, $v0, %lo(D_8003FC10)
    /* 1C89C 8002C09C 040040AC */  sw         $zero, 0x4($v0)
    /* 1C8A0 8002C0A0 000040AC */  sw         $zero, 0x0($v0)
    /* 1C8A4 8002C0A4 01000224 */  addiu      $v0, $zero, 0x1
    /* 1C8A8 8002C0A8 0380013C */  lui        $at, %hi(D_800335D4)
    /* 1C8AC 8002C0AC D43522AC */  sw         $v0, %lo(D_800335D4)($at)
    /* 1C8B0 8002C0B0 1400BF8F */  lw         $ra, 0x14($sp)
    /* 1C8B4 8002C0B4 1000B08F */  lw         $s0, 0x10($sp)
    /* 1C8B8 8002C0B8 0800E003 */  jr         $ra
    /* 1C8BC 8002C0BC 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel _padStartCom
