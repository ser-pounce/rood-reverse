nonmatching _currentPp

dlabel _currentPp
    /* 8938 80102138 */ .short 0x0000
enddlabel _currentPp

nonmatching _maxPp

dlabel _maxPp
    /* 893A 8010213A */ .short 0x0000
    /* 893C 8010213C */ .byte 0x01
enddlabel _maxPp

nonmatching D_8010213D

dlabel D_8010213D
    /* 893D 8010213D */ .byte 0x00
    /* 893E 8010213E */ .short 0x0000
enddlabel D_8010213D
