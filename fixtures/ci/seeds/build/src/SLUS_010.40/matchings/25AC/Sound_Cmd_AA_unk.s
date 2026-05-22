nonmatching Sound_Cmd_AA_unk, 0x78

glabel Sound_Cmd_AA_unk
    /* 8674 80017E74 00100724 */  addiu      $a3, $zero, 0x1000
    /* 8678 80017E78 0380023C */  lui        $v0, %hi(g_Sound_VoiceSchedulerState)
    /* 867C 80017E7C 9078488C */  lw         $t0, %lo(g_Sound_VoiceSchedulerState)($v0)
    /* 8680 80017E80 21300000 */  addu       $a2, $zero, $zero
    /* 8684 80017E84 0002093C */  lui        $t1, (0x2000000 >> 16)
    /* 8688 80017E88 0380023C */  lui        $v0, %hi(D_80035910)
    /* 868C 80017E8C 10594224 */  addiu      $v0, $v0, %lo(D_80035910)
    /* 8690 80017E90 F8004524 */  addiu      $a1, $v0, 0xF8
  .L80017E94:
    /* 8694 80017E94 24100701 */  and        $v0, $t0, $a3
    /* 8698 80017E98 0D004010 */  beqz       $v0, .L80017ED0
    /* 869C 80017E9C 00000000 */   nop
    /* 86A0 80017EA0 30FFA28C */  lw         $v0, -0xD0($a1)
    /* 86A4 80017EA4 00000000 */  nop
    /* 86A8 80017EA8 24104900 */  and        $v0, $v0, $t1
    /* 86AC 80017EAC 08004014 */  bnez       $v0, .L80017ED0
    /* 86B0 80017EB0 00000000 */   nop
    /* 86B4 80017EB4 00008290 */  lbu        $v0, 0x0($a0)
    /* 86B8 80017EB8 0000A38C */  lw         $v1, 0x0($a1)
    /* 86BC 80017EBC 76FFA0A4 */  sh         $zero, -0x8A($a1)
    /* 86C0 80017EC0 00120200 */  sll        $v0, $v0, 8
    /* 86C4 80017EC4 03006334 */  ori        $v1, $v1, 0x3
    /* 86C8 80017EC8 74FFA2A4 */  sh         $v0, -0x8C($a1)
    /* 86CC 80017ECC 0000A3AC */  sw         $v1, 0x0($a1)
  .L80017ED0:
    /* 86D0 80017ED0 0100C624 */  addiu      $a2, $a2, 0x1
    /* 86D4 80017ED4 1001A524 */  addiu      $a1, $a1, 0x110
    /* 86D8 80017ED8 0C00C22C */  sltiu      $v0, $a2, 0xC
    /* 86DC 80017EDC EDFF4014 */  bnez       $v0, .L80017E94
    /* 86E0 80017EE0 40380700 */   sll       $a3, $a3, 1
    /* 86E4 80017EE4 0800E003 */  jr         $ra
    /* 86E8 80017EE8 00000000 */   nop
endlabel Sound_Cmd_AA_unk
