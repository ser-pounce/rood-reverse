nonmatching setRC2wait, 0x20

glabel setRC2wait
    /* 1EFF4 8002E7F4 801F023C */  lui        $v0, (0x1F801120 >> 16)
    /* 1EFF8 8002E7F8 20114234 */  ori        $v0, $v0, (0x1F801120 & 0xFFFF)
    /* 1EFFC 8002E7FC 00004294 */  lhu        $v0, 0x0($v0)
    /* 1F000 8002E800 0480013C */  lui        $at, %hi(D_8003FEA4)
    /* 1F004 8002E804 A4FE24AC */  sw         $a0, %lo(D_8003FEA4)($at)
    /* 1F008 8002E808 0480013C */  lui        $at, %hi(D_8003FEA0)
    /* 1F00C 8002E80C 0800E003 */  jr         $ra
    /* 1F010 8002E810 A0FE22AC */   sw        $v0, %lo(D_8003FEA0)($at)
endlabel setRC2wait
