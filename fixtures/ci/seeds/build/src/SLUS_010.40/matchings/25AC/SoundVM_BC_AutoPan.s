nonmatching SoundVM_BC_AutoPan, 0x6C

glabel SoundVM_BC_AutoPan
    /* C7EC 8001BFEC 3400828C */  lw         $v0, 0x34($a0)
    /* C7F0 8001BFF0 0000838C */  lw         $v1, 0x0($a0)
    /* C7F4 8001BFF4 04004234 */  ori        $v0, $v0, 0x4
    /* C7F8 8001BFF8 340082AC */  sw         $v0, 0x34($a0)
    /* C7FC 8001BFFC 00006290 */  lbu        $v0, 0x0($v1)
    /* C800 8001C000 01006324 */  addiu      $v1, $v1, 0x1
    /* C804 8001C004 000083AC */  sw         $v1, 0x0($a0)
    /* C808 8001C008 03004014 */  bnez       $v0, .L8001C018
    /* C80C 8001C00C C00082A4 */   sh        $v0, 0xC0($a0)
    /* C810 8001C010 00010224 */  addiu      $v0, $zero, 0x100
    /* C814 8001C014 C00082A4 */  sh         $v0, 0xC0($a0)
  .L8001C018:
    /* C818 8001C018 0000828C */  lw         $v0, 0x0($a0)
    /* C81C 8001C01C 00000000 */  nop
    /* C820 8001C020 00004390 */  lbu        $v1, 0x0($v0)
    /* C824 8001C024 01004224 */  addiu      $v0, $v0, 0x1
    /* C828 8001C028 000082AC */  sw         $v0, 0x0($a0)
    /* C82C 8001C02C C40083A4 */  sh         $v1, 0xC4($a0)
    /* C830 8001C030 0380033C */  lui        $v1, %hi(g_Sound_LfoTable)
    /* C834 8001C034 C4008294 */  lhu        $v0, 0xC4($a0)
    /* C838 8001C038 A0016324 */  addiu      $v1, $v1, %lo(g_Sound_LfoTable)
    /* C83C 8001C03C 80100200 */  sll        $v0, $v0, 2
    /* C840 8001C040 21104300 */  addu       $v0, $v0, $v1
    /* C844 8001C044 0000438C */  lw         $v1, 0x0($v0)
    /* C848 8001C048 01000224 */  addiu      $v0, $zero, 0x1
    /* C84C 8001C04C C20082A4 */  sh         $v0, 0xC2($a0)
    /* C850 8001C050 0800E003 */  jr         $ra
    /* C854 8001C054 240083AC */   sw        $v1, 0x24($a0)
endlabel SoundVM_BC_AutoPan
