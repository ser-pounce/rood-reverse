nonmatching StClearRing, 0x60

glabel StClearRing
    /* 12934 80022134 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 12938 80022138 0480053C */  lui        $a1, %hi(D_80039C4C)
    /* 1293C 8002213C 4C9CA58C */  lw         $a1, %lo(D_80039C4C)($a1)
    /* 12940 80022140 1000BFAF */  sw         $ra, 0x10($sp)
    /* 12944 80022144 0480013C */  lui        $at, %hi(D_80039C34)
    /* 12948 80022148 349C20AC */  sw         $zero, %lo(D_80039C34)($at)
    /* 1294C 8002214C 0480013C */  lui        $at, %hi(D_80039C30)
    /* 12950 80022150 309C20AC */  sw         $zero, %lo(D_80039C30)($at)
    /* 12954 80022154 0480013C */  lui        $at, %hi(D_80039C2C)
    /* 12958 80022158 2C9C20AC */  sw         $zero, %lo(D_80039C2C)($at)
    /* 1295C 8002215C 0480013C */  lui        $at, %hi(D_80039C24)
    /* 12960 80022160 249C20AC */  sw         $zero, %lo(D_80039C24)($at)
    /* 12964 80022164 1189000C */  jal        init_ring_status
    /* 12968 80022168 21200000 */   addu      $a0, $zero, $zero
    /* 1296C 8002216C 0480013C */  lui        $at, %hi(StCdIntrFlag)
    /* 12970 80022170 149C20AC */  sw         $zero, %lo(StCdIntrFlag)($at)
    /* 12974 80022174 0480013C */  lui        $at, %hi(D_80039C0C)
    /* 12978 80022178 0C9C20A4 */  sh         $zero, %lo(D_80039C0C)($at)
    /* 1297C 8002217C 0480013C */  lui        $at, %hi(D_80039C08)
    /* 12980 80022180 089C20AC */  sw         $zero, %lo(D_80039C08)($at)
    /* 12984 80022184 1000BF8F */  lw         $ra, 0x10($sp)
    /* 12988 80022188 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 1298C 8002218C 0800E003 */  jr         $ra
    /* 12990 80022190 00000000 */   nop
endlabel StClearRing
