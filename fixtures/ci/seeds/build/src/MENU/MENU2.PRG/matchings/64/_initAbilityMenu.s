nonmatching _initAbilityMenu, 0x234

glabel _initAbilityMenu
    /* 128 80102928 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 12C 8010292C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 130 80102930 21808000 */  addu       $s0, $a0, $zero
    /* 134 80102934 1400B1AF */  sw         $s1, 0x14($sp)
    /* 138 80102938 2188C000 */  addu       $s1, $a2, $zero
    /* 13C 8010293C 21400000 */  addu       $t0, $zero, $zero
    /* 140 80102940 1080023C */  lui        $v0, %hi(_abilityText)
    /* 144 80102944 B44E428C */  lw         $v0, %lo(_abilityText)($v0)
    /* 148 80102948 21380001 */  addu       $a3, $t0, $zero
    /* 14C 8010294C 03004010 */  beqz       $v0, .L8010295C
    /* 150 80102950 1800BFAF */   sw        $ra, 0x18($sp)
    /* 154 80102954 D20A0408 */  j          .L80102B48
    /* 158 80102958 21100001 */   addu      $v0, $t0, $zero
  .L8010295C:
    /* 15C 8010295C 0680023C */  lui        $v0, %hi(D_80060021)
    /* 160 80102960 21004390 */  lbu        $v1, %lo(D_80060021)($v0)
    /* 164 80102964 1080023C */  lui        $v0, %hi(_selectedAbilityType)
    /* 168 80102968 09006010 */  beqz       $v1, .L80102990
    /* 16C 8010296C C04E45A0 */   sb        $a1, %lo(_selectedAbilityType)($v0)
    /* 170 80102970 0F80023C */  lui        $v0, %hi(D_800F4EE8)
    /* 174 80102974 E84E4224 */  addiu      $v0, $v0, %lo(D_800F4EE8)
    /* 178 80102978 40180500 */  sll        $v1, $a1, 1
    /* 17C 8010297C 21206200 */  addu       $a0, $v1, $v0
    /* 180 80102980 01006324 */  addiu      $v1, $v1, 0x1
    /* 184 80102984 21186200 */  addu       $v1, $v1, $v0
    /* 188 80102988 00008890 */  lbu        $t0, 0x0($a0)
    /* 18C 8010298C 00006790 */  lbu        $a3, 0x0($v1)
  .L80102990:
    /* 190 80102990 F8FF0326 */  addiu      $v1, $s0, -0x8
    /* 194 80102994 07006104 */  bgez       $v1, .L801029B4
    /* 198 80102998 2A106700 */   slt       $v0, $v1, $a3
    /* 19C 8010299C 21400701 */  addu       $t0, $t0, $a3
    /* 1A0 801029A0 2A101001 */  slt        $v0, $t0, $s0
    /* 1A4 801029A4 1A004014 */  bnez       $v0, .L80102A10
    /* 1A8 801029A8 21380000 */   addu      $a3, $zero, $zero
    /* 1AC 801029AC 840A0408 */  j          .L80102A10
    /* 1B0 801029B0 2140E000 */   addu      $t0, $a3, $zero
  .L801029B4:
    /* 1B4 801029B4 09004010 */  beqz       $v0, .L801029DC
    /* 1B8 801029B8 21100701 */   addu      $v0, $t0, $a3
    /* 1BC 801029BC 2A105000 */  slt        $v0, $v0, $s0
    /* 1C0 801029C0 04004014 */  bnez       $v0, .L801029D4
    /* 1C4 801029C4 2310E300 */   subu      $v0, $a3, $v1
    /* 1C8 801029C8 21400000 */  addu       $t0, $zero, $zero
    /* 1CC 801029CC 770A0408 */  j          .L801029DC
    /* 1D0 801029D0 21380001 */   addu      $a3, $t0, $zero
  .L801029D4:
    /* 1D4 801029D4 21400201 */  addu       $t0, $t0, $v0
    /* 1D8 801029D8 21386000 */  addu       $a3, $v1, $zero
  .L801029DC:
    /* 1DC 801029DC 0600E018 */  blez       $a3, .L801029F8
    /* 1E0 801029E0 2A10E300 */   slt       $v0, $a3, $v1
    /* 1E4 801029E4 04000015 */  bnez       $t0, .L801029F8
    /* 1E8 801029E8 00000000 */   nop
    /* 1EC 801029EC 01000824 */  addiu      $t0, $zero, 0x1
    /* 1F0 801029F0 FFFFE724 */  addiu      $a3, $a3, -0x1
    /* 1F4 801029F4 2A10E300 */  slt        $v0, $a3, $v1
  .L801029F8:
    /* 1F8 801029F8 05004010 */  beqz       $v0, .L80102A10
    /* 1FC 801029FC 07000224 */   addiu     $v0, $zero, 0x7
    /* 200 80102A00 04000215 */  bne        $t0, $v0, .L80102A14
    /* 204 80102A04 1080023C */   lui       $v0, %hi(_highlightedAbility)
    /* 208 80102A08 06000824 */  addiu      $t0, $zero, 0x6
    /* 20C 80102A0C 0100E724 */  addiu      $a3, $a3, 0x1
  .L80102A10:
    /* 210 80102A10 1080023C */  lui        $v0, %hi(_highlightedAbility)
  .L80102A14:
    /* 214 80102A14 B84E48AC */  sw         $t0, %lo(_highlightedAbility)($v0)
    /* 218 80102A18 1080023C */  lui        $v0, %hi(_firstAbility)
    /* 21C 80102A1C C24E47A0 */  sb         $a3, %lo(_firstAbility)($v0)
    /* 220 80102A20 18000224 */  addiu      $v0, $zero, 0x18
    /* 224 80102A24 0300A214 */  bne        $a1, $v0, .L80102A34
    /* 228 80102A28 1080033C */   lui       $v1, %hi(_unlockedChainAbilities)
    /* 22C 80102A2C 8F0A0408 */  j          .L80102A3C
    /* 230 80102A30 D0506324 */   addiu     $v1, $v1, %lo(_unlockedChainAbilities)
  .L80102A34:
    /* 234 80102A34 1080033C */  lui        $v1, %hi(_unlockedDefenseAbilities)
    /* 238 80102A38 E0506324 */  addiu      $v1, $v1, %lo(_unlockedDefenseAbilities)
  .L80102A3C:
    /* 23C 80102A3C 21100701 */  addu       $v0, $t0, $a3
    /* 240 80102A40 21104300 */  addu       $v0, $v0, $v1
    /* 244 80102A44 00004490 */  lbu        $a0, 0x0($v0)
    /* 248 80102A48 190A040C */  jal        _setAbilityCost
    /* 24C 80102A4C 00000000 */   nop
    /* 250 80102A50 C0211000 */  sll        $a0, $s0, 7
    /* 254 80102A54 1080023C */  lui        $v0, %hi(_abilityCount)
    /* 258 80102A58 C14E50A0 */  sb         $s0, %lo(_abilityCount)($v0)
    /* 25C 80102A5C 1080023C */  lui        $v0, %hi(_abilityMenuState)
    /* 260 80102A60 8F0F010C */  jal        vs_main_allocHeapR
    /* 264 80102A64 BC4E40AC */   sw        $zero, %lo(_abilityMenuState)($v0)
    /* 268 80102A68 21400000 */  addu       $t0, $zero, $zero
    /* 26C 80102A6C 1080033C */  lui        $v1, %hi(_abilityText)
    /* 270 80102A70 3400001A */  blez       $s0, .L80102B44
    /* 274 80102A74 B44E62AC */   sw        $v0, %lo(_abilityText)($v1)
    /* 278 80102A78 E7E70C34 */  ori        $t4, $zero, 0xE7E7
    /* 27C 80102A7C 21584000 */  addu       $t3, $v0, $zero
    /* 280 80102A80 21286001 */  addu       $a1, $t3, $zero
    /* 284 80102A84 21500001 */  addu       $t2, $t0, $zero
    /* 288 80102A88 21302002 */  addu       $a2, $s1, $zero
  .L80102A8C:
    /* 28C 80102A8C 0000C38C */  lw         $v1, 0x0($a2)
    /* 290 80102A90 00000000 */  nop
    /* 294 80102A94 10006010 */  beqz       $v1, .L80102AD8
    /* 298 80102A98 FA100224 */   addiu     $v0, $zero, 0x10FA
    /* 29C 80102A9C 0000A2A4 */  sh         $v0, 0x0($a1)
    /* 2A0 80102AA0 21380000 */  addu       $a3, $zero, $zero
    /* 2A4 80102AA4 21484001 */  addu       $t1, $t2, $zero
    /* 2A8 80102AA8 21206000 */  addu       $a0, $v1, $zero
  .L80102AAC:
    /* 2AC 80102AAC 00008294 */  lhu        $v0, 0x0($a0)
    /* 2B0 80102AB0 21182701 */  addu       $v1, $t1, $a3
    /* 2B4 80102AB4 0100E724 */  addiu      $a3, $a3, 0x1
    /* 2B8 80102AB8 40180300 */  sll        $v1, $v1, 1
    /* 2BC 80102ABC 21186B00 */  addu       $v1, $v1, $t3
    /* 2C0 80102AC0 020062A4 */  sh         $v0, 0x2($v1)
    /* 2C4 80102AC4 0E00E228 */  slti       $v0, $a3, 0xE
    /* 2C8 80102AC8 F8FF4014 */  bnez       $v0, .L80102AAC
    /* 2CC 80102ACC 02008424 */   addiu     $a0, $a0, 0x2
    /* 2D0 80102AD0 B70A0408 */  j          .L80102ADC
    /* 2D4 80102AD4 1E00ACA4 */   sh        $t4, 0x1E($a1)
  .L80102AD8:
    /* 2D8 80102AD8 0000ACA4 */  sh         $t4, 0x0($a1)
  .L80102ADC:
    /* 2DC 80102ADC 0400C38C */  lw         $v1, 0x4($a2)
    /* 2E0 80102AE0 00000000 */  nop
    /* 2E4 80102AE4 10006010 */  beqz       $v1, .L80102B28
    /* 2E8 80102AE8 F8000224 */   addiu     $v0, $zero, 0xF8
    /* 2EC 80102AEC 2000A2A4 */  sh         $v0, 0x20($a1)
    /* 2F0 80102AF0 21380000 */  addu       $a3, $zero, $zero
    /* 2F4 80102AF4 21484001 */  addu       $t1, $t2, $zero
    /* 2F8 80102AF8 21206000 */  addu       $a0, $v1, $zero
  .L80102AFC:
    /* 2FC 80102AFC 00008294 */  lhu        $v0, 0x0($a0)
    /* 300 80102B00 21182701 */  addu       $v1, $t1, $a3
    /* 304 80102B04 0100E724 */  addiu      $a3, $a3, 0x1
    /* 308 80102B08 40180300 */  sll        $v1, $v1, 1
    /* 30C 80102B0C 21186B00 */  addu       $v1, $v1, $t3
    /* 310 80102B10 220062A4 */  sh         $v0, 0x22($v1)
    /* 314 80102B14 2E00E228 */  slti       $v0, $a3, 0x2E
    /* 318 80102B18 F8FF4014 */  bnez       $v0, .L80102AFC
    /* 31C 80102B1C 02008424 */   addiu     $a0, $a0, 0x2
    /* 320 80102B20 CB0A0408 */  j          .L80102B2C
    /* 324 80102B24 7E00ACA4 */   sh        $t4, 0x7E($a1)
  .L80102B28:
    /* 328 80102B28 2000ACA4 */  sh         $t4, 0x20($a1)
  .L80102B2C:
    /* 32C 80102B2C 8000A524 */  addiu      $a1, $a1, 0x80
    /* 330 80102B30 40004A25 */  addiu      $t2, $t2, 0x40
    /* 334 80102B34 01000825 */  addiu      $t0, $t0, 0x1
    /* 338 80102B38 2A101001 */  slt        $v0, $t0, $s0
    /* 33C 80102B3C D3FF4014 */  bnez       $v0, .L80102A8C
    /* 340 80102B40 0800C624 */   addiu     $a2, $a2, 0x8
  .L80102B44:
    /* 344 80102B44 01000224 */  addiu      $v0, $zero, 0x1
  .L80102B48:
    /* 348 80102B48 1800BF8F */  lw         $ra, 0x18($sp)
    /* 34C 80102B4C 1400B18F */  lw         $s1, 0x14($sp)
    /* 350 80102B50 1000B08F */  lw         $s0, 0x10($sp)
    /* 354 80102B54 0800E003 */  jr         $ra
    /* 358 80102B58 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel _initAbilityMenu
