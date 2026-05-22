nonmatching _initScriptFunctionTable, 0x6C

glabel _initScriptFunctionTable
    /* 12AC 800FAAAC E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 12B0 800FAAB0 00180424 */  addiu      $a0, $zero, 0x1800
    /* 12B4 800FAAB4 0F80023C */  lui        $v0, %hi(D_800F4C08)
    /* 12B8 800FAAB8 084C40A0 */  sb         $zero, %lo(D_800F4C08)($v0)
    /* 12BC 800FAABC 0F80023C */  lui        $v0, %hi(D_800F4BE2)
    /* 12C0 800FAAC0 1000BFAF */  sw         $ra, 0x10($sp)
    /* 12C4 800FAAC4 B10F010C */  jal        vs_main_allocHeap
    /* 12C8 800FAAC8 E24B40A4 */   sh        $zero, %lo(D_800F4BE2)($v0)
    /* 12CC 800FAACC 80000424 */  addiu      $a0, $zero, 0x80
    /* 12D0 800FAAD0 0F80033C */  lui        $v1, %hi(D_800F4C30)
    /* 12D4 800FAAD4 B10F010C */  jal        vs_main_allocHeap
    /* 12D8 800FAAD8 304C62AC */   sw        $v0, %lo(D_800F4C30)($v1)
    /* 12DC 800FAADC 00040424 */  addiu      $a0, $zero, 0x400
    /* 12E0 800FAAE0 0F80033C */  lui        $v1, %hi(D_800F4C48)
    /* 12E4 800FAAE4 B10F010C */  jal        vs_main_allocHeap
    /* 12E8 800FAAE8 484C62AC */   sw        $v0, %lo(D_800F4C48)($v1)
    /* 12EC 800FAAEC 21204000 */  addu       $a0, $v0, $zero
    /* 12F0 800FAAF0 0F80023C */  lui        $v0, %hi(D_800F4C28)
    /* 12F4 800FAAF4 1080053C */  lui        $a1, %hi(D_800FAF7C)
    /* 12F8 800FAAF8 7CAFA524 */  addiu      $a1, $a1, %lo(D_800FAF7C)
    /* 12FC 800FAAFC 00040624 */  addiu      $a2, $zero, 0x400
    /* 1300 800FAB00 2C24010C */  jal        vs_main_memcpy
    /* 1304 800FAB04 284C44AC */   sw        $a0, %lo(D_800F4C28)($v0)
    /* 1308 800FAB08 1000BF8F */  lw         $ra, 0x10($sp)
    /* 130C 800FAB0C 00000000 */  nop
    /* 1310 800FAB10 0800E003 */  jr         $ra
    /* 1314 800FAB14 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel _initScriptFunctionTable
