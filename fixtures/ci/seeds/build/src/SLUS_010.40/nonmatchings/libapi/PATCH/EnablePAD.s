nonmatching EnablePAD, 0x14

glabel EnablePAD
    /* 1F574 8002ED74 0480093C */  lui        $t1, %hi(jtbl_8003FEC0)
    /* 1F578 8002ED78 C0FE298D */  lw         $t1, %lo(jtbl_8003FEC0)($t1)
    /* 1F57C 8002ED7C 00000000 */  nop
    /* 1F580 8002ED80 08002001 */  jr         $t1
    /* 1F584 8002ED84 00000000 */   nop
endlabel EnablePAD
