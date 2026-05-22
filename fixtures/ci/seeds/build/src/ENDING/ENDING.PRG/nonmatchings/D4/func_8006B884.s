nonmatching func_8006B884, 0x8C

glabel func_8006B884
    /* 3084 8006B884 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 3088 8006B888 40010424 */  addiu      $a0, $zero, 0x140
    /* 308C 8006B88C F0000524 */  addiu      $a1, $zero, 0xF0
    /* 3090 8006B890 00020624 */  addiu      $a2, $zero, 0x200
    /* 3094 8006B894 21380000 */  addu       $a3, $zero, $zero
    /* 3098 8006B898 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 309C 8006B89C 1800B0AF */  sw         $s0, 0x18($sp)
    /* 30A0 8006B8A0 1000A0AF */  sw         $zero, 0x10($sp)
    /* 30A4 8006B8A4 14AD010C */  jal        func_8006B450
    /* 30A8 8006B8A8 1400A0AF */   sw        $zero, 0x14($sp)
    /* 30AC 8006B8AC 1080043C */  lui        $a0, (0x8010C000 >> 16)
    /* 30B0 8006B8B0 00C08434 */  ori        $a0, $a0, (0x8010C000 & 0xFFFF)
    /* 30B4 8006B8B4 0F00053C */  lui        $a1, (0xF2000 >> 16)
    /* 30B8 8006B8B8 DD0F010C */  jal        vs_main_initHeap
    /* 30BC 8006B8BC 0020A534 */   ori       $a1, $a1, (0xF2000 & 0xFFFF)
    /* 30C0 8006B8C0 B10F010C */  jal        vs_main_allocHeap
    /* 30C4 8006B8C4 0200043C */   lui       $a0, (0x20000 >> 16)
    /* 30C8 8006B8C8 0200043C */  lui        $a0, (0x20000 >> 16)
    /* 30CC 8006B8CC 0680103C */  lui        $s0, %hi(D_8005E0C0)
    /* 30D0 8006B8D0 C0E002AE */  sw         $v0, %lo(D_8005E0C0)($s0)
    /* 30D4 8006B8D4 B10F010C */  jal        vs_main_allocHeap
    /* 30D8 8006B8D8 C0E01026 */   addiu     $s0, $s0, %lo(D_8005E0C0)
    /* 30DC 8006B8DC 88200424 */  addiu      $a0, $zero, 0x2088
    /* 30E0 8006B8E0 B10F010C */  jal        vs_main_allocHeap
    /* 30E4 8006B8E4 040002AE */   sw        $v0, 0x4($s0)
    /* 30E8 8006B8E8 88200424 */  addiu      $a0, $zero, 0x2088
    /* 30EC 8006B8EC 0580103C */  lui        $s0, %hi(D_80055C80)
    /* 30F0 8006B8F0 805C02AE */  sw         $v0, %lo(D_80055C80)($s0)
    /* 30F4 8006B8F4 B10F010C */  jal        vs_main_allocHeap
    /* 30F8 8006B8F8 805C1026 */   addiu     $s0, $s0, %lo(D_80055C80)
    /* 30FC 8006B8FC 040002AE */  sw         $v0, 0x4($s0)
    /* 3100 8006B900 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 3104 8006B904 1800B08F */  lw         $s0, 0x18($sp)
    /* 3108 8006B908 0800E003 */  jr         $ra
    /* 310C 8006B90C 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_8006B884
