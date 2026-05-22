nonmatching SetDrawStp, 0x28

glabel SetDrawStp
    /* 1BF14 8002B714 02000224 */  addiu      $v0, $zero, 0x2
    /* 1BF18 8002B718 0400A010 */  beqz       $a1, .L8002B72C
    /* 1BF1C 8002B71C 030082A0 */   sb        $v0, 0x3($a0)
    /* 1BF20 8002B720 00E6023C */  lui        $v0, (0xE6000001 >> 16)
    /* 1BF24 8002B724 CCAD0008 */  j          .L8002B730
    /* 1BF28 8002B728 01004234 */   ori       $v0, $v0, (0xE6000001 & 0xFFFF)
  .L8002B72C:
    /* 1BF2C 8002B72C 00E6023C */  lui        $v0, (0xE6000000 >> 16)
  .L8002B730:
    /* 1BF30 8002B730 040082AC */  sw         $v0, 0x4($a0)
    /* 1BF34 8002B734 0800E003 */  jr         $ra
    /* 1BF38 8002B738 080080AC */   sw        $zero, 0x8($a0)
endlabel SetDrawStp
    /* 1BF3C 8002B73C 00000000 */  nop
    /* 1BF40 8002B740 00000000 */  nop
