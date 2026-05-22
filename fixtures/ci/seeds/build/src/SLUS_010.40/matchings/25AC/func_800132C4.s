nonmatching func_800132C4, 0x64

glabel func_800132C4
    /* 3AC4 800132C4 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 3AC8 800132C8 1000B0AF */  sw         $s0, 0x10($sp)
    /* 3ACC 800132CC 21808000 */  addu       $s0, $a0, $zero
    /* 3AD0 800132D0 1400B1AF */  sw         $s1, 0x14($sp)
    /* 3AD4 800132D4 2188A000 */  addu       $s1, $a1, $zero
    /* 3AD8 800132D8 1800B2AF */  sw         $s2, 0x18($sp)
    /* 3ADC 800132DC 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 3AE0 800132E0 1A4D000C */  jal        Sound_IsNotAkaoFile
    /* 3AE4 800132E4 2190C000 */   addu      $s2, $a2, $zero
    /* 3AE8 800132E8 09004014 */  bnez       $v0, .L80013310
    /* 3AEC 800132EC E0000424 */   addiu     $a0, $zero, 0xE0
    /* 3AF0 800132F0 0380033C */  lui        $v1, %hi(D_800378C0)
    /* 3AF4 800132F4 C07870AC */  sw         $s0, %lo(D_800378C0)($v1)
    /* 3AF8 800132F8 C0786324 */  addiu      $v1, $v1, %lo(D_800378C0)
    /* 3AFC 800132FC FF002232 */  andi       $v0, $s1, 0xFF
    /* 3B00 80013300 00120200 */  sll        $v0, $v0, 8
    /* 3B04 80013304 040062AC */  sw         $v0, 0x4($v1)
    /* 3B08 80013308 0C63000C */  jal        func_80018C30
    /* 3B0C 8001330C 080072AC */   sw        $s2, 0x8($v1)
  .L80013310:
    /* 3B10 80013310 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 3B14 80013314 1800B28F */  lw         $s2, 0x18($sp)
    /* 3B18 80013318 1400B18F */  lw         $s1, 0x14($sp)
    /* 3B1C 8001331C 1000B08F */  lw         $s0, 0x10($sp)
    /* 3B20 80013320 0800E003 */  jr         $ra
    /* 3B24 80013324 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_800132C4
