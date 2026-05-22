nonmatching UpdateCdVolume, 0x20

glabel UpdateCdVolume
    /* 9934 80019134 0380023C */  lui        $v0, %hi(D_800378E2)
    /* 9938 80019138 E2784284 */  lh         $v0, %lo(D_800378E2)($v0)
    /* 993C 8001913C 801F013C */  lui        $at, (0x1F801DB0 >> 16)
    /* 9940 80019140 B01D22A4 */  sh         $v0, (0x1F801DB0 & 0xFFFF)($at)
    /* 9944 80019144 801F013C */  lui        $at, (0x1F801DB2 >> 16)
    /* 9948 80019148 B21D22A4 */  sh         $v0, (0x1F801DB2 & 0xFFFF)($at)
    /* 994C 8001914C 0800E003 */  jr         $ra
    /* 9950 80019150 00000000 */   nop
endlabel UpdateCdVolume
