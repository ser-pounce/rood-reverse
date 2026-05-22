nonmatching func_80093788, 0x9C

glabel func_80093788
    /* 2AF88 80093788 40008228 */  slti       $v0, $a0, 0x40
    /* 2AF8C 8009378C 23004010 */  beqz       $v0, .L8009381C
    /* 2AF90 80093790 0F80033C */   lui       $v1, %hi(D_800F1DD8)
    /* 2AF94 80093794 D81D6324 */  addiu      $v1, $v1, %lo(D_800F1DD8)
    /* 2AF98 80093798 40100400 */  sll        $v0, $a0, 1
    /* 2AF9C 8009379C 21104400 */  addu       $v0, $v0, $a0
    /* 2AFA0 800937A0 80100200 */  sll        $v0, $v0, 2
    /* 2AFA4 800937A4 21384300 */  addu       $a3, $v0, $v1
    /* 2AFA8 800937A8 0100E390 */  lbu        $v1, 0x1($a3)
    /* 2AFAC 800937AC 06000224 */  addiu      $v0, $zero, 0x6
    /* 2AFB0 800937B0 1A006214 */  bne        $v1, $v0, .L8009381C
    /* 2AFB4 800937B4 0F80033C */   lui       $v1, %hi(vs_battle_roomData + 0x64)
    /* 2AFB8 800937B8 0400E68C */  lw         $a2, 0x4($a3)
    /* 2AFBC 800937BC 0000E290 */  lbu        $v0, 0x0($a3)
    /* 2AFC0 800937C0 5C1C648C */  lw         $a0, %lo(vs_battle_roomData + 0x64)($v1)
    /* 2AFC4 800937C4 15004010 */  beqz       $v0, .L8009381C
    /* 2AFC8 800937C8 00000000 */   nop
    /* 2AFCC 800937CC 0000C38C */  lw         $v1, 0x0($a2)
    /* 2AFD0 800937D0 00000000 */  nop
    /* 2AFD4 800937D4 21188300 */  addu       $v1, $a0, $v1
    /* 2AFD8 800937D8 0000628C */  lw         $v0, 0x0($v1)
    /* 2AFDC 800937DC 1800C48C */  lw         $a0, 0x18($a2)
    /* 2AFE0 800937E0 00604234 */  ori        $v0, $v0, 0x6000
    /* 2AFE4 800937E4 140064AC */  sw         $a0, 0x14($v1)
    /* 2AFE8 800937E8 000062AC */  sw         $v0, 0x0($v1)
    /* 2AFEC 800937EC 2000C28C */  lw         $v0, 0x20($a2)
    /* 2AFF0 800937F0 1C00C58C */  lw         $a1, 0x1C($a2)
    /* 2AFF4 800937F4 1800C48C */  lw         $a0, 0x18($a2)
    /* 2AFF8 800937F8 0C00C38C */  lw         $v1, 0xC($a2)
    /* 2AFFC 800937FC 23100200 */  negu       $v0, $v0
    /* 2B000 80093800 23180300 */  negu       $v1, $v1
    /* 2B004 80093804 2000C2AC */  sw         $v0, 0x20($a2)
    /* 2B008 80093808 0800C2AC */  sw         $v0, 0x8($a2)
    /* 2B00C 8009380C 1C00C4AC */  sw         $a0, 0x1C($a2)
    /* 2B010 80093810 1800C5AC */  sw         $a1, 0x18($a2)
    /* 2B014 80093814 0C00C3AC */  sw         $v1, 0xC($a2)
    /* 2B018 80093818 0000E0A0 */  sb         $zero, 0x0($a3)
  .L8009381C:
    /* 2B01C 8009381C 0800E003 */  jr         $ra
    /* 2B020 80093820 00000000 */   nop
endlabel func_80093788
