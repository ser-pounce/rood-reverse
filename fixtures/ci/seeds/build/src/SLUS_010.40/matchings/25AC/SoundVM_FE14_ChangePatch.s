nonmatching SoundVM_FE14_ChangePatch, 0x94

glabel SoundVM_FE14_ChangePatch
    /* C224 8001BA24 21308000 */  addu       $a2, $a0, $zero
    /* C228 8001BA28 0380033C */  lui        $v1, %hi(g_pActiveMusicConfig)
    /* C22C 8001BA2C 0000C28C */  lw         $v0, 0x0($a2)
    /* C230 8001BA30 2078638C */  lw         $v1, %lo(g_pActiveMusicConfig)($v1)
    /* C234 8001BA34 00004490 */  lbu        $a0, 0x0($v0)
    /* C238 8001BA38 01004224 */  addiu      $v0, $v0, 0x1
    /* C23C 8001BA3C 0000C2AC */  sw         $v0, 0x0($a2)
    /* C240 8001BA40 3C00658C */  lw         $a1, 0x3C($v1)
    /* C244 8001BA44 00000000 */  nop
    /* C248 8001BA48 1900A010 */  beqz       $a1, .L8001BAB0
    /* C24C 8001BA4C FF008230 */   andi      $v0, $a0, 0xFF
    /* C250 8001BA50 40100200 */  sll        $v0, $v0, 1
    /* C254 8001BA54 21384500 */  addu       $a3, $v0, $a1
    /* C258 8001BA58 0000E394 */  lhu        $v1, 0x0($a3)
    /* C25C 8001BA5C 00800234 */  ori        $v0, $zero, 0x8000
    /* C260 8001BA60 2B104300 */  sltu       $v0, $v0, $v1
    /* C264 8001BA64 07004010 */  beqz       $v0, .L8001BA84
    /* C268 8001BA68 FFE6043C */   lui       $a0, (0xE6FFEFF7 >> 16)
    /* C26C 8001BA6C 3400C28C */  lw         $v0, 0x34($a2)
    /* C270 8001BA70 FFEF0324 */  addiu      $v1, $zero, -0x1001
    /* C274 8001BA74 0A01C0A4 */  sh         $zero, 0x10A($a2)
    /* C278 8001BA78 24104300 */  and        $v0, $v0, $v1
    /* C27C 8001BA7C 0800E003 */  jr         $ra
    /* C280 8001BA80 3400C2AC */   sw        $v0, 0x34($a2)
  .L8001BA84:
    /* C284 8001BA84 F7EF8434 */  ori        $a0, $a0, (0xE6FFEFF7 & 0xFFFF)
    /* C288 8001BA88 0000E394 */  lhu        $v1, 0x0($a3)
    /* C28C 8001BA8C FF000224 */  addiu      $v0, $zero, 0xFF
    /* C290 8001BA90 E600C2A4 */  sh         $v0, 0xE6($a2)
    /* C294 8001BA94 3400C28C */  lw         $v0, 0x34($a2)
    /* C298 8001BA98 2118A300 */  addu       $v1, $a1, $v1
    /* C29C 8001BA9C 20006324 */  addiu      $v1, $v1, 0x20
    /* C2A0 8001BAA0 24104400 */  and        $v0, $v0, $a0
    /* C2A4 8001BAA4 00104234 */  ori        $v0, $v0, 0x1000
    /* C2A8 8001BAA8 1800C3AC */  sw         $v1, 0x18($a2)
    /* C2AC 8001BAAC 3400C2AC */  sw         $v0, 0x34($a2)
  .L8001BAB0:
    /* C2B0 8001BAB0 0800E003 */  jr         $ra
    /* C2B4 8001BAB4 00000000 */   nop
endlabel SoundVM_FE14_ChangePatch
