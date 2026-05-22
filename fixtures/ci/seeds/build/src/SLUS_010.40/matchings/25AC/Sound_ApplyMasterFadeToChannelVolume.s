nonmatching Sound_ApplyMasterFadeToChannelVolume, 0x50

glabel Sound_ApplyMasterFadeToChannelVolume
    /* 59C0 800151C0 0380033C */  lui        $v1, %hi(g_Sound_MasterFadeTimer)
    /* 59C4 800151C4 6000858C */  lw         $a1, 0x60($a0)
    /* 59C8 800151C8 38786224 */  addiu      $v0, $v1, %lo(g_Sound_MasterFadeTimer)
    /* 59CC 800151CC 0C0045AC */  sw         $a1, 0xC($v0)
    /* 59D0 800151D0 3878628C */  lw         $v0, %lo(g_Sound_MasterFadeTimer)($v1)
    /* 59D4 800151D4 032C0500 */  sra        $a1, $a1, 16
    /* 59D8 800151D8 03120200 */  sra        $v0, $v0, 8
    /* 59DC 800151DC 1800A200 */  mult       $a1, $v0
    /* 59E0 800151E0 12280000 */  mflo       $a1
    /* 59E4 800151E4 0281023C */  lui        $v0, (0x81020409 >> 16)
    /* 59E8 800151E8 09044234 */  ori        $v0, $v0, (0x81020409 & 0xFFFF)
    /* 59EC 800151EC 1800A200 */  mult       $a1, $v0
    /* 59F0 800151F0 C31F0500 */  sra        $v1, $a1, 31
    /* 59F4 800151F4 10100000 */  mfhi       $v0
    /* 59F8 800151F8 21104500 */  addu       $v0, $v0, $a1
    /* 59FC 800151FC 83110200 */  sra        $v0, $v0, 6
    /* 5A00 80015200 23104300 */  subu       $v0, $v0, $v1
    /* 5A04 80015204 002A0200 */  sll        $a1, $v0, 8
    /* 5A08 80015208 0800E003 */  jr         $ra
    /* 5A0C 8001520C 600085AC */   sw        $a1, 0x60($a0)
endlabel Sound_ApplyMasterFadeToChannelVolume
