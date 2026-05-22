nonmatching _cursorFileOpSaturation, 0x10

glabel _cursorFileOpSaturation
    /* 7AD4 8010A2D4 00C89098 */  lwr        $s0, -0x3800($a0)
    /* 7AD8 8010A2D8 A0A8B0B8 */  swr        $s0, -0x5760($a1)
    /* 7ADC 8010A2DC C0C8D0D8 */  ldc2       $16, -0x3740($a2)
    /* 7AE0 8010A2E0 E0E8F0F8 */  sdc2       $16, -0x1720($a3)
endlabel _cursorFileOpSaturation
