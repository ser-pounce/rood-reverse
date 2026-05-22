nonmatching SoundVM_B3_ResetAdsr, 0x48

glabel SoundVM_B3_ResetAdsr
    /* C2B8 8001BAB8 FFE6063C */  lui        $a2, (0xE6FFFFFF >> 16)
    /* C2BC 8001BABC 0380023C */  lui        $v0, %hi(g_InstrumentInfo)
    /* C2C0 8001BAC0 6A008394 */  lhu        $v1, 0x6A($a0)
    /* C2C4 8001BAC4 88674224 */  addiu      $v0, $v0, %lo(g_InstrumentInfo)
    /* C2C8 8001BAC8 00190300 */  sll        $v1, $v1, 4
    /* C2CC 8001BACC 21186200 */  addu       $v1, $v1, $v0
    /* C2D0 8001BAD0 0C006294 */  lhu        $v0, 0xC($v1)
    /* C2D4 8001BAD4 FFFFC634 */  ori        $a2, $a2, (0xE6FFFFFF & 0xFFFF)
    /* C2D8 8001BAD8 060182A4 */  sh         $v0, 0x106($a0)
    /* C2DC 8001BADC 0E006594 */  lhu        $a1, 0xE($v1)
    /* C2E0 8001BAE0 F800828C */  lw         $v0, 0xF8($a0)
    /* C2E4 8001BAE4 3400838C */  lw         $v1, 0x34($a0)
    /* C2E8 8001BAE8 00FF4234 */  ori        $v0, $v0, 0xFF00
    /* C2EC 8001BAEC 24186600 */  and        $v1, $v1, $a2
    /* C2F0 8001BAF0 F80082AC */  sw         $v0, 0xF8($a0)
    /* C2F4 8001BAF4 340083AC */  sw         $v1, 0x34($a0)
    /* C2F8 8001BAF8 0800E003 */  jr         $ra
    /* C2FC 8001BAFC 080185A4 */   sh        $a1, 0x108($a0)
endlabel SoundVM_B3_ResetAdsr
