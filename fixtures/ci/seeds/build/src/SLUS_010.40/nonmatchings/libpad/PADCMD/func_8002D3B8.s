nonmatching func_8002D3B8, 0x1C

glabel func_8002D3B8
    /* 1DBB8 8002D3B8 2000838C */  lw         $v1, 0x20($a0)
    /* 1DBBC 8002D3BC 4D000224 */  addiu      $v0, $zero, 0x4D
    /* 1DBC0 8002D3C0 370082A0 */  sb         $v0, 0x37($a0)
    /* 1DBC4 8002D3C4 06000224 */  addiu      $v0, $zero, 0x6
    /* 1DBC8 8002D3C8 360082A0 */  sb         $v0, 0x36($a0)
    /* 1DBCC 8002D3CC 0800E003 */  jr         $ra
    /* 1DBD0 8002D3D0 2C0083AC */   sw        $v1, 0x2C($a0)
endlabel func_8002D3B8
