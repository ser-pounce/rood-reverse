nonmatching _padInitDirSeq, 0x34

glabel _padInitDirSeq
    /* 1EB34 8002E334 0380023C */  lui        $v0, %hi(func_8002E368)
    /* 1EB38 8002E338 68E34224 */  addiu      $v0, $v0, %lo(func_8002E368)
    /* 1EB3C 8002E33C 0380013C */  lui        $at, %hi(D_800335B4)
    /* 1EB40 8002E340 B43522AC */  sw         $v0, %lo(D_800335B4)($at)
    /* 1EB44 8002E344 0380023C */  lui        $v0, %hi(func_8002E7BC)
    /* 1EB48 8002E348 BCE74224 */  addiu      $v0, $v0, %lo(func_8002E7BC)
    /* 1EB4C 8002E34C 0380013C */  lui        $at, %hi(D_800335B8)
    /* 1EB50 8002E350 B83522AC */  sw         $v0, %lo(D_800335B8)($at)
    /* 1EB54 8002E354 0380023C */  lui        $v0, %hi(func_8002E478)
    /* 1EB58 8002E358 78E44224 */  addiu      $v0, $v0, %lo(func_8002E478)
    /* 1EB5C 8002E35C 0380013C */  lui        $at, %hi(D_800335BC)
    /* 1EB60 8002E360 0800E003 */  jr         $ra
    /* 1EB64 8002E364 BC3522AC */   sw        $v0, %lo(D_800335BC)($at)
endlabel _padInitDirSeq
