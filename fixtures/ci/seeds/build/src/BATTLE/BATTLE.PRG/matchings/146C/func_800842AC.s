nonmatching func_800842AC, 0x44

glabel func_800842AC
    /* 1BAAC 800842AC 3FFF043C */  lui        $a0, (0xFF3FFFFF >> 16)
    /* 1BAB0 800842B0 FFFF8434 */  ori        $a0, $a0, (0xFF3FFFFF & 0xFFFF)
    /* 1BAB4 800842B4 0400C284 */  lh         $v0, 0x4($a2)
    /* 1BAB8 800842B8 0100C380 */  lb         $v1, 0x1($a2)
    /* 1BABC 800842BC 40100200 */  sll        $v0, $v0, 1
    /* 1BAC0 800842C0 80180300 */  sll        $v1, $v1, 2
    /* 1BAC4 800842C4 3C00C2A4 */  sh         $v0, 0x3C($a2)
    /* 1BAC8 800842C8 0400C284 */  lh         $v0, 0x4($a2)
    /* 1BACC 800842CC 2118C300 */  addu       $v1, $a2, $v1
    /* 1BAD0 800842D0 40100200 */  sll        $v0, $v0, 1
    /* 1BAD4 800842D4 220062A4 */  sh         $v0, 0x22($v1)
    /* 1BAD8 800842D8 1C00C28C */  lw         $v0, 0x1C($a2)
    /* 1BADC 800842DC 4000033C */  lui        $v1, (0x400000 >> 16)
    /* 1BAE0 800842E0 24104400 */  and        $v0, $v0, $a0
    /* 1BAE4 800842E4 25104300 */  or         $v0, $v0, $v1
    /* 1BAE8 800842E8 0800E003 */  jr         $ra
    /* 1BAEC 800842EC 1C00C2AC */   sw        $v0, 0x1C($a2)
endlabel func_800842AC
