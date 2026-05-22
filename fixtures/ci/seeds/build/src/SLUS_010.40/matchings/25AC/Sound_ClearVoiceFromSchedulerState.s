nonmatching Sound_ClearVoiceFromSchedulerState, 0x6C

glabel Sound_ClearVoiceFromSchedulerState
    /* B8CC 8001B0CC 0380023C */  lui        $v0, %hi(g_Sound_VoiceSchedulerState)
    /* B8D0 8001B0D0 9078438C */  lw         $v1, %lo(g_Sound_VoiceSchedulerState)($v0)
    /* B8D4 8001B0D4 27280500 */  nor        $a1, $zero, $a1
    /* B8D8 8001B0D8 24186500 */  and        $v1, $v1, $a1
    /* B8DC 8001B0DC 907843AC */  sw         $v1, %lo(g_Sound_VoiceSchedulerState)($v0)
    /* B8E0 8001B0E0 90784224 */  addiu      $v0, $v0, %lo(g_Sound_VoiceSchedulerState)
    /* B8E4 8001B0E4 1000438C */  lw         $v1, 0x10($v0)
    /* B8E8 8001B0E8 1C00468C */  lw         $a2, 0x1C($v0)
    /* B8EC 8001B0EC 24186500 */  and        $v1, $v1, $a1
    /* B8F0 8001B0F0 100043AC */  sw         $v1, 0x10($v0)
    /* B8F4 8001B0F4 2000438C */  lw         $v1, 0x20($v0)
    /* B8F8 8001B0F8 2430C500 */  and        $a2, $a2, $a1
    /* B8FC 8001B0FC 1C0046AC */  sw         $a2, 0x1C($v0)
    /* B900 8001B100 2400468C */  lw         $a2, 0x24($v0)
    /* B904 8001B104 24186500 */  and        $v1, $v1, $a1
    /* B908 8001B108 200043AC */  sw         $v1, 0x20($v0)
    /* B90C 8001B10C 0400438C */  lw         $v1, 0x4($v0)
    /* B910 8001B110 2430C500 */  and        $a2, $a2, $a1
    /* B914 8001B114 240046AC */  sw         $a2, 0x24($v0)
    /* B918 8001B118 0800468C */  lw         $a2, 0x8($v0)
    /* B91C 8001B11C 24186500 */  and        $v1, $v1, $a1
    /* B920 8001B120 2430C500 */  and        $a2, $a2, $a1
    /* B924 8001B124 040043AC */  sw         $v1, 0x4($v0)
    /* B928 8001B128 080046AC */  sw         $a2, 0x8($v0)
    /* B92C 8001B12C 280080AC */  sw         $zero, 0x28($a0)
    /* B930 8001B130 0800E003 */  jr         $ra
    /* B934 8001B134 3C0080AC */   sw        $zero, 0x3C($a0)
endlabel Sound_ClearVoiceFromSchedulerState
