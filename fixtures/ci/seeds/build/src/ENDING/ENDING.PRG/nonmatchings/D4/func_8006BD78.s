nonmatching func_8006BD78, 0x8C

glabel func_8006BD78
    /* 3578 8006BD78 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 357C 8006BD7C 0E80023C */  lui        $v0, %hi(D_800DC208)
    /* 3580 8006BD80 01000424 */  addiu      $a0, $zero, 0x1
    /* 3584 8006BD84 1400BFAF */  sw         $ra, 0x14($sp)
    /* 3588 8006BD88 1000B0AF */  sw         $s0, 0x10($sp)
    /* 358C 8006BD8C 6EA1000C */  jal        SetDispMask
    /* 3590 8006BD90 08C240AC */   sw        $zero, %lo(D_800DC208)($v0)
  .L8006BD94:
    /* 3594 8006BD94 4CAE010C */  jal        func_8006B930
    /* 3598 8006BD98 00000000 */   nop
    /* 359C 8006BD9C 81AF010C */  jal        func_8006BE04
    /* 35A0 8006BDA0 00000000 */   nop
    /* 35A4 8006BDA4 801F043C */  lui        $a0, (0x1F800004 >> 16)
    /* 35A8 8006BDA8 0400848C */  lw         $a0, (0x1F800004 & 0xFFFF)($a0)
    /* 35AC 8006BDAC 21804000 */  addu       $s0, $v0, $zero
    /* 35B0 8006BDB0 A9AD010C */  jal        func_8006B6A4
    /* 35B4 8006BDB4 FC1F8424 */   addiu     $a0, $a0, 0x1FFC
    /* 35B8 8006BDB8 F6FF0012 */  beqz       $s0, .L8006BD94
    /* 35BC 8006BDBC 00000000 */   nop
  .L8006BDC0:
    /* 35C0 8006BDC0 4CAE010C */  jal        func_8006B930
    /* 35C4 8006BDC4 00000000 */   nop
    /* 35C8 8006BDC8 85B0010C */  jal        func_8006C214
    /* 35CC 8006BDCC 00000000 */   nop
    /* 35D0 8006BDD0 21804000 */  addu       $s0, $v0, $zero
    /* 35D4 8006BDD4 B17D000C */  jal        VSync
    /* 35D8 8006BDD8 21200000 */   addu      $a0, $zero, $zero
    /* 35DC 8006BDDC 801F043C */  lui        $a0, (0x1F800004 >> 16)
    /* 35E0 8006BDE0 0400848C */  lw         $a0, (0x1F800004 & 0xFFFF)($a0)
    /* 35E4 8006BDE4 A9AD010C */  jal        func_8006B6A4
    /* 35E8 8006BDE8 FC1F8424 */   addiu     $a0, $a0, 0x1FFC
    /* 35EC 8006BDEC F4FF0012 */  beqz       $s0, .L8006BDC0
    /* 35F0 8006BDF0 00000000 */   nop
    /* 35F4 8006BDF4 1400BF8F */  lw         $ra, 0x14($sp)
    /* 35F8 8006BDF8 1000B08F */  lw         $s0, 0x10($sp)
    /* 35FC 8006BDFC 0800E003 */  jr         $ra
    /* 3600 8006BE00 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8006BD78
