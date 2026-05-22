nonmatching ChannelMaskToVoiceMaskFiltered, 0x60

glabel ChannelMaskToVoiceMaskFiltered
    /* 5F64 80015764 01000824 */  addiu      $t0, $zero, 0x1
    /* 5F68 80015768 21480001 */  addu       $t1, $t0, $zero
  .L8001576C:
    /* 5F6C 8001576C 2410C800 */  and        $v0, $a2, $t0
    /* 5F70 80015770 0B004010 */  beqz       $v0, .L800157A0
    /* 5F74 80015774 27100800 */   nor       $v0, $zero, $t0
    /* 5F78 80015778 F400838C */  lw         $v1, 0xF4($a0)
    /* 5F7C 8001577C 00000000 */  nop
    /* 5F80 80015780 1800622C */  sltiu      $v0, $v1, 0x18
    /* 5F84 80015784 05004010 */  beqz       $v0, .L8001579C
    /* 5F88 80015788 04186900 */   sllv      $v1, $t1, $v1
    /* 5F8C 8001578C 0000A28C */  lw         $v0, 0x0($a1)
    /* 5F90 80015790 00000000 */  nop
    /* 5F94 80015794 25104300 */  or         $v0, $v0, $v1
    /* 5F98 80015798 0000A2AC */  sw         $v0, 0x0($a1)
  .L8001579C:
    /* 5F9C 8001579C 27100800 */  nor        $v0, $zero, $t0
  .L800157A0:
    /* 5FA0 800157A0 2430C200 */  and        $a2, $a2, $v0
    /* 5FA4 800157A4 10018424 */  addiu      $a0, $a0, 0x110
    /* 5FA8 800157A8 F0FFC014 */  bnez       $a2, .L8001576C
    /* 5FAC 800157AC 40400800 */   sll       $t0, $t0, 1
    /* 5FB0 800157B0 0000A28C */  lw         $v0, 0x0($a1)
    /* 5FB4 800157B4 00000000 */  nop
    /* 5FB8 800157B8 24104700 */  and        $v0, $v0, $a3
    /* 5FBC 800157BC 0800E003 */  jr         $ra
    /* 5FC0 800157C0 0000A2AC */   sw        $v0, 0x0($a1)
endlabel ChannelMaskToVoiceMaskFiltered
