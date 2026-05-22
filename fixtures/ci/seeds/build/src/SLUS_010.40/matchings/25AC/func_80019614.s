nonmatching func_80019614, 0xF0

glabel func_80019614
    /* 9E14 80019614 0480053C */  lui        $a1, %hi(g_Sound_GlobalFlags)
    /* 9E18 80019618 F89AA48C */  lw         $a0, %lo(g_Sound_GlobalFlags)($a1)
    /* 9E1C 8001961C 00000000 */  nop
    /* 9E20 80019620 00668230 */  andi       $v0, $a0, 0x6600
    /* 9E24 80019624 35004010 */  beqz       $v0, .L800196FC
    /* 9E28 80019628 0380023C */   lui       $v0, %hi(g_pActiveMusicConfig)
    /* 9E2C 8001962C 2078468C */  lw         $a2, %lo(g_pActiveMusicConfig)($v0)
    /* 9E30 80019630 00000000 */  nop
    /* 9E34 80019634 7600C294 */  lhu        $v0, 0x76($a2)
    /* 9E38 80019638 7A00C394 */  lhu        $v1, 0x7A($a2)
    /* 9E3C 8001963C 00140200 */  sll        $v0, $v0, 16
    /* 9E40 80019640 21186200 */  addu       $v1, $v1, $v0
    /* 9E44 80019644 0380023C */  lui        $v0, %hi(D_800378D4)
    /* 9E48 80019648 2C006014 */  bnez       $v1, .L800196FC
    /* 9E4C 8001964C D47843AC */   sw        $v1, %lo(D_800378D4)($v0)
    /* 9E50 80019650 00018230 */  andi       $v0, $a0, 0x100
    /* 9E54 80019654 17004010 */  beqz       $v0, .L800196B4
    /* 9E58 80019658 00408230 */   andi      $v0, $a0, 0x4000
    /* 9E5C 8001965C 06004010 */  beqz       $v0, .L80019678
    /* 9E60 80019660 FFDE0224 */   addiu     $v0, $zero, -0x2101
    /* 9E64 80019664 FFBF0224 */  addiu      $v0, $zero, -0x4001
    /* 9E68 80019668 24108200 */  and        $v0, $a0, $v0
    /* 9E6C 8001966C 00204234 */  ori        $v0, $v0, 0x2000
    /* 9E70 80019670 0800E003 */  jr         $ra
    /* 9E74 80019674 F89AA2AC */   sw        $v0, %lo(g_Sound_GlobalFlags)($a1)
  .L80019678:
    /* 9E78 80019678 24108200 */  and        $v0, $a0, $v0
    /* 9E7C 8001967C 00104234 */  ori        $v0, $v0, 0x1000
    /* 9E80 80019680 F89AA2AC */  sw         $v0, %lo(g_Sound_GlobalFlags)($a1)
    /* 9E84 80019684 3000C28C */  lw         $v0, 0x30($a2)
    /* 9E88 80019688 0400C48C */  lw         $a0, 0x4($a2)
    /* 9E8C 8001968C 1400C38C */  lw         $v1, 0x14($a2)
    /* 9E90 80019690 3000C58C */  lw         $a1, 0x30($a2)
    /* 9E94 80019694 27100200 */  nor        $v0, $zero, $v0
    /* 9E98 80019698 24208200 */  and        $a0, $a0, $v0
    /* 9E9C 8001969C 1800C28C */  lw         $v0, 0x18($a2)
    /* 9EA0 800196A0 24186500 */  and        $v1, $v1, $a1
    /* 9EA4 800196A4 1400C3AC */  sw         $v1, 0x14($a2)
    /* 9EA8 800196A8 25104400 */  or         $v0, $v0, $a0
    /* 9EAC 800196AC 0800E003 */  jr         $ra
    /* 9EB0 800196B0 1800C2AC */   sw        $v0, 0x18($a2)
  .L800196B4:
    /* 9EB4 800196B4 00048230 */  andi       $v0, $a0, 0x400
    /* 9EB8 800196B8 06004010 */  beqz       $v0, .L800196D4
    /* 9EBC 800196BC FFED0224 */   addiu     $v0, $zero, -0x1201
    /* 9EC0 800196C0 FFFB0224 */  addiu      $v0, $zero, -0x401
    /* 9EC4 800196C4 24108200 */  and        $v0, $a0, $v0
    /* 9EC8 800196C8 00024234 */  ori        $v0, $v0, 0x200
    /* 9ECC 800196CC 0800E003 */  jr         $ra
    /* 9ED0 800196D0 F89AA2AC */   sw        $v0, %lo(g_Sound_GlobalFlags)($a1)
  .L800196D4:
    /* 9ED4 800196D4 24108200 */  and        $v0, $a0, $v0
    /* 9ED8 800196D8 0380033C */  lui        $v1, %hi(g_pSavedMousicConfig)
    /* 9EDC 800196DC 2866638C */  lw         $v1, %lo(g_pSavedMousicConfig)($v1)
    /* 9EE0 800196E0 00014234 */  ori        $v0, $v0, 0x100
    /* 9EE4 800196E4 F89AA2AC */  sw         $v0, %lo(g_Sound_GlobalFlags)($a1)
    /* 9EE8 800196E8 1800628C */  lw         $v0, 0x18($v1)
    /* 9EEC 800196EC 0400648C */  lw         $a0, 0x4($v1)
    /* 9EF0 800196F0 140060AC */  sw         $zero, 0x14($v1)
    /* 9EF4 800196F4 25104400 */  or         $v0, $v0, $a0
    /* 9EF8 800196F8 180062AC */  sw         $v0, 0x18($v1)
  .L800196FC:
    /* 9EFC 800196FC 0800E003 */  jr         $ra
    /* 9F00 80019700 00000000 */   nop
endlabel func_80019614
