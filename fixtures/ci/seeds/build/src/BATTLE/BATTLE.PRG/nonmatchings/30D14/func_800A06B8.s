nonmatching func_800A06B8, 0x64

glabel func_800A06B8
    /* 37EB8 800A06B8 64188624 */  addiu      $a2, $a0, 0x1864
    /* 37EBC 800A06BC 0800A014 */  bnez       $a1, .L800A06E0
    /* 37EC0 800A06C0 0500C0A0 */   sb        $zero, 0x5($a2)
    /* 37EC4 800A06C4 4E068294 */  lhu        $v0, 0x64E($a0)
    /* 37EC8 800A06C8 00000000 */  nop
    /* 37ECC 800A06CC 0C00C2A4 */  sh         $v0, 0xC($a2)
    /* 37ED0 800A06D0 50068294 */  lhu        $v0, 0x650($a0)
    /* 37ED4 800A06D4 0800C0A4 */  sh         $zero, 0x8($a2)
    /* 37ED8 800A06D8 C4810208 */  j          .L800A0710
    /* 37EDC 800A06DC 0E00C2A4 */   sh        $v0, 0xE($a2)
  .L800A06E0:
    /* 37EE0 800A06E0 4E068294 */  lhu        $v0, 0x64E($a0)
    /* 37EE4 800A06E4 0C00C394 */  lhu        $v1, 0xC($a2)
    /* 37EE8 800A06E8 00000000 */  nop
    /* 37EEC 800A06EC 23104300 */  subu       $v0, $v0, $v1
    /* 37EF0 800A06F0 1000C2A4 */  sh         $v0, 0x10($a2)
    /* 37EF4 800A06F4 50068394 */  lhu        $v1, 0x650($a0)
    /* 37EF8 800A06F8 0800C294 */  lhu        $v0, 0x8($a2)
    /* 37EFC 800A06FC 0E00C494 */  lhu        $a0, 0xE($a2)
    /* 37F00 800A0700 23100200 */  negu       $v0, $v0
    /* 37F04 800A0704 23186400 */  subu       $v1, $v1, $a0
    /* 37F08 800A0708 0A00C2A4 */  sh         $v0, 0xA($a2)
    /* 37F0C 800A070C 1200C3A4 */  sh         $v1, 0x12($a2)
  .L800A0710:
    /* 37F10 800A0710 0400C5A0 */  sb         $a1, 0x4($a2)
    /* 37F14 800A0714 0800E003 */  jr         $ra
    /* 37F18 800A0718 0500C5A0 */   sb        $a1, 0x5($a2)
endlabel func_800A06B8
