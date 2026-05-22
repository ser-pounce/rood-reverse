nonmatching func_800C0214, 0x1C

glabel func_800C0214
    /* 57A14 800C0214 801F033C */  lui        $v1, (0x1F800008 >> 16)
    /* 57A18 800C0218 21308000 */  addu       $a2, $a0, $zero
    /* 57A1C 800C021C 80000424 */  addiu      $a0, $zero, 0x80
    /* 57A20 800C0220 0800678C */  lw         $a3, (0x1F800008 & 0xFFFF)($v1)
  alabel func_800C0224
    /* 57A24 800C0224 00E1093C */  lui        $t1, (0xE100000C >> 16)
    /* 57A28 800C0228 8D000308 */  j          .L800C0234
    /* 57A2C 800C022C 0C002935 */   ori       $t1, $t1, (0xE100000C & 0xFFFF)
endlabel func_800C0214
