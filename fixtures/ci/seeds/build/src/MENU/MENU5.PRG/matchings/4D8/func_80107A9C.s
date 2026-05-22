nonmatching func_80107A9C, 0x74

glabel func_80107A9C
    /* 529C 80107A9C E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 52A0 80107AA0 1400B1AF */  sw         $s1, 0x14($sp)
    /* 52A4 80107AA4 801F113C */  lui        $s1, (0x1F800000 >> 16)
    /* 52A8 80107AA8 1800BFAF */  sw         $ra, 0x18($sp)
    /* 52AC 80107AAC 1000B0AF */  sw         $s0, 0x10($sp)
    /* 52B0 80107AB0 0000308E */  lw         $s0, (0x1F800000 & 0xFFFF)($s1)
    /* 52B4 80107AB4 03000224 */  addiu      $v0, $zero, 0x3
    /* 52B8 80107AB8 030002A2 */  sb         $v0, 0x3($s0)
    /* 52BC 80107ABC 40000224 */  addiu      $v0, $zero, 0x40
    /* 52C0 80107AC0 070002A2 */  sb         $v0, 0x7($s0)
    /* 52C4 80107AC4 80000224 */  addiu      $v0, $zero, 0x80
    /* 52C8 80107AC8 0A0005A6 */  sh         $a1, 0xA($s0)
    /* 52CC 80107ACC 21280002 */  addu       $a1, $s0, $zero
    /* 52D0 80107AD0 080004A6 */  sh         $a0, 0x8($s0)
    /* 52D4 80107AD4 0C0006A6 */  sh         $a2, 0xC($s0)
    /* 52D8 80107AD8 0E0007A6 */  sh         $a3, 0xE($s0)
    /* 52DC 80107ADC 040002A2 */  sb         $v0, 0x4($s0)
    /* 52E0 80107AE0 050002A2 */  sb         $v0, 0x5($s0)
    /* 52E4 80107AE4 060002A2 */  sb         $v0, 0x6($s0)
    /* 52E8 80107AE8 0400248E */  lw         $a0, (0x1F800004 & 0xFFFF)($s1)
    /* 52EC 80107AEC 10001026 */  addiu      $s0, $s0, 0x10
    /* 52F0 80107AF0 35AD000C */  jal        AddPrim
    /* 52F4 80107AF4 20008424 */   addiu     $a0, $a0, 0x20
    /* 52F8 80107AF8 000030AE */  sw         $s0, (0x1F800000 & 0xFFFF)($s1)
    /* 52FC 80107AFC 1800BF8F */  lw         $ra, 0x18($sp)
    /* 5300 80107B00 1400B18F */  lw         $s1, 0x14($sp)
    /* 5304 80107B04 1000B08F */  lw         $s0, 0x10($sp)
    /* 5308 80107B08 0800E003 */  jr         $ra
    /* 530C 80107B0C 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_80107A9C
