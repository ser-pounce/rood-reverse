nonmatching func_8002EBD8, 0x78

glabel func_8002EBD8
    /* 1F3D8 8002EBD8 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1F3DC 8002EBDC 1400BFAF */  sw         $ra, 0x14($sp)
    /* 1F3E0 8002EBE0 5D9A000C */  jal        EnterCriticalSection
    /* 1F3E4 8002EBE4 1000B0AF */   sw        $s0, 0x10($sp)
    /* 1F3E8 8002EBE8 01000424 */  addiu      $a0, $zero, 0x1
    /* 1F3EC 8002EBEC 0480033C */  lui        $v1, %hi(D_8003FEAC)
    /* 1F3F0 8002EBF0 ACFE6324 */  addiu      $v1, $v1, %lo(D_8003FEAC)
    /* 1F3F4 8002EBF4 FCFF7024 */  addiu      $s0, $v1, -0x4
    /* 1F3F8 8002EBF8 0380023C */  lui        $v0, %hi(func_8002EC88)
    /* 1F3FC 8002EBFC 88EC4224 */  addiu      $v0, $v0, %lo(func_8002EC88)
    /* 1F400 8002EC00 000062AC */  sw         $v0, 0x0($v1)
    /* 1F404 8002EC04 0380023C */  lui        $v0, %hi(func_8002ECF0)
    /* 1F408 8002EC08 F0EC4224 */  addiu      $v0, $v0, %lo(func_8002ECF0)
    /* 1F40C 8002EC0C 040062AC */  sw         $v0, 0x4($v1)
    /* 1F410 8002EC10 0480013C */  lui        $at, %hi(D_8003FEA8)
    /* 1F414 8002EC14 A8FE20AC */  sw         $zero, %lo(D_8003FEA8)($at)
    /* 1F418 8002EC18 0480013C */  lui        $at, %hi(D_8003FEB4)
    /* 1F41C 8002EC1C B4FE20AC */  sw         $zero, %lo(D_8003FEB4)($at)
    /* 1F420 8002EC20 A1B2000C */  jal        SysDeqIntRP
    /* 1F424 8002EC24 21280002 */   addu      $a1, $s0, $zero
    /* 1F428 8002EC28 01000424 */  addiu      $a0, $zero, 0x1
    /* 1F42C 8002EC2C 9DB2000C */  jal        SysEnqIntRP
    /* 1F430 8002EC30 21280002 */   addu      $a1, $s0, $zero
    /* 1F434 8002EC34 619A000C */  jal        ExitCriticalSection
    /* 1F438 8002EC38 00000000 */   nop
    /* 1F43C 8002EC3C 01000224 */  addiu      $v0, $zero, 0x1
    /* 1F440 8002EC40 1400BF8F */  lw         $ra, 0x14($sp)
    /* 1F444 8002EC44 1000B08F */  lw         $s0, 0x10($sp)
    /* 1F448 8002EC48 0800E003 */  jr         $ra
    /* 1F44C 8002EC4C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8002EBD8
