nonmatching _menuElementStops, 0x14

glabel _menuElementStops
    /* 7AC0 8010A2C0 00010204 */  bltzl      $zero, .L8010A6C4
    /* 7AC4 8010A2C4 08102038 */   xori      $zero, $at, 0x1008
    /* 7AC8 8010A2C8 50688098 */  lwr        $zero, 0x6850($a0)
    /* 7ACC 8010A2CC B0C8E0F8 */  sdc2       $0, -0x3750($a3)
    /* 7AD0 8010A2D0 FFFFFFFF */  sd         $ra, -0x1($ra)
endlabel _menuElementStops
