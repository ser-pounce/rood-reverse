nonmatching SpuStart, 0x70

glabel SpuStart
    /* E1DC 8001D9DC 0380023C */  lui        $v0, %hi(D_80030850)
    /* E1E0 8001D9E0 5008428C */  lw         $v0, %lo(D_80030850)($v0)
    /* E1E4 8001D9E4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* E1E8 8001D9E8 14004014 */  bnez       $v0, .L8001DA3C
    /* E1EC 8001D9EC 1000BFAF */   sw        $ra, 0x10($sp)
    /* E1F0 8001D9F0 01000224 */  addiu      $v0, $zero, 0x1
    /* E1F4 8001D9F4 0380013C */  lui        $at, %hi(D_80030850)
    /* E1F8 8001D9F8 5D9A000C */  jal        EnterCriticalSection
    /* E1FC 8001D9FC 500822AC */   sw        $v0, %lo(D_80030850)($at)
    /* E200 8001DA00 0280043C */  lui        $a0, %hi(_spu_FiDMA)
    /* E204 8001DA04 6579000C */  jal        _SpuDataCallback
    /* E208 8001DA08 94DE8424 */   addiu     $a0, $a0, %lo(_spu_FiDMA)
    /* E20C 8001DA0C 00F0043C */  lui        $a0, (0xF0000009 >> 16)
    /* E210 8001DA10 09008434 */  ori        $a0, $a0, (0xF0000009 & 0xFFFF)
    /* E214 8001DA14 20000524 */  addiu      $a1, $zero, 0x20
    /* E218 8001DA18 00200624 */  addiu      $a2, $zero, 0x2000
    /* E21C 8001DA1C 359A000C */  jal        OpenEvent
    /* E220 8001DA20 21380000 */   addu      $a3, $zero, $zero
    /* E224 8001DA24 21204000 */  addu       $a0, $v0, $zero
    /* E228 8001DA28 0380013C */  lui        $at, %hi(D_800307E8)
    /* E22C 8001DA2C 459A000C */  jal        EnableEvent
    /* E230 8001DA30 E80724AC */   sw        $a0, %lo(D_800307E8)($at)
    /* E234 8001DA34 619A000C */  jal        ExitCriticalSection
    /* E238 8001DA38 00000000 */   nop
  .L8001DA3C:
    /* E23C 8001DA3C 1000BF8F */  lw         $ra, 0x10($sp)
    /* E240 8001DA40 1800BD27 */  addiu      $sp, $sp, 0x18
    /* E244 8001DA44 0800E003 */  jr         $ra
    /* E248 8001DA48 00000000 */   nop
endlabel SpuStart
    /* E24C 8001DA4C 00000000 */  nop
    /* E250 8001DA50 00000000 */  nop
