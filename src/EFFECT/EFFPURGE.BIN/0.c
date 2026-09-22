#include "common.h"
#include "src/BATTLE/BATTLE.PRG/5BF94.h"
#include "src/BATTLE/BATTLE.PRG/6E644.h"
#include "build/src/include/lbas.h"

/** Effect entrypoints, declarations to temporarily satisfy the compiler  */
int func_800F9800(func_800D4910_t*, u_int, int);
int func_800F9818(func_800D4910_t*, u_int, int);
int func_800F98E0(func_800D4910_t*, u_int, int);
int func_800F98F8(func_800D4910_t*, u_int, int);
int func_800F9910(func_800D4910_t*, u_int, int);
int func_800F9928(func_800D4910_t*, u_int, int);
int func_800F99D8(func_800D4910_t*, u_int, int);
int func_800F99F0(func_800D4910_t*, u_int, int);
int func_800F9AE8(func_800D4910_t*, u_int, int);
int func_800FA30C(func_800D4910_t*, u_int, int);
int func_800FA324(func_800D4910_t*, u_int, int);
int func_800FA368(func_800D4910_t*, u_int, int);
int func_800FA398(func_800D4910_t*, u_int, int);
int func_800FA3B0(func_800D4910_t*, u_int, int);
int func_800FA41C(func_800D4910_t*, u_int, int);
int func_800FA424(func_800D4910_t*, u_int, int);
int func_800FA48C(func_800D4910_t*, u_int, int);
int func_800FA490(func_800D4910_t*, u_int, int);
int func_800FA4A8(func_800D4910_t*, u_int, int);
int func_800FA588(func_800D4910_t*, u_int, int);
int func_800FA6B8(func_800D4910_t*, u_int, int);
int func_800FA6BC(func_800D4910_t*, u_int, int);
int func_800FA6D0(func_800D4910_t*, u_int, int);
int func_800FA6F8(func_800D4910_t*, u_int, int);
int func_800FA710(func_800D4910_t*, u_int, int);
int func_800FA740(func_800D4910_t*, u_int, int);
int func_800FA770(func_800D4910_t*, u_int, int);
int func_800FA7B0(func_800D4910_t*, u_int, int);
int func_800FA7F0(func_800D4910_t*, u_int, int);
int func_800FA84C(func_800D4910_t*, u_int, int);
int func_800FA868(func_800D4910_t*, u_int, int);
int func_800FA8D0(func_800D4910_t*, u_int, int);
int func_800FAC78(func_800D4910_t*, u_int, int);
int func_800FAF00(func_800D4910_t*, u_int, int);
int func_800FAF30(func_800D4910_t*, u_int, int);
int func_800FB00C(func_800D4910_t*, u_int, int);
int func_800FB0CC(func_800D4910_t*, u_int, int);
int func_800FB260(func_800D4910_t*, u_int, int);
int func_800FB294(func_800D4910_t*, u_int, int);
int func_800FB2D8(func_800D4910_t*, u_int, int);
int func_800FB2DC(func_800D4910_t*, u_int, int);
int func_800FB2F4(func_800D4910_t*, u_int, int);
int func_800FB320(func_800D4910_t*, u_int, int);
int func_800FB32C(func_800D4910_t*, u_int, int);
int func_800FB338(func_800D4910_t*, u_int, int);
int func_800FB348(func_800D4910_t*, u_int, int);
int func_800FB3FC(func_800D4910_t*, u_int, int);
int func_800FB400(func_800D4910_t*, u_int, int);
int func_800FB418(func_800D4910_t*, u_int, int);
int func_800FB4B8(func_800D4910_t*, u_int, int);
int func_800FB4C0(func_800D4910_t*, u_int, int);
int func_800FB4D0(func_800D4910_t*, u_int, int);
int func_800FB4D8(func_800D4910_t*, u_int, int);
int func_800FB4E0(func_800D4910_t*, u_int, int);
int func_800FB4F8(func_800D4910_t*, u_int, int);
int func_800FB5B0(func_800D4910_t*, u_int, int);
int func_800FB5B4(func_800D4910_t*, u_int, int);
int func_800FB5CC(func_800D4910_t*, u_int, int);
int func_800FB5D0(func_800D4910_t*, u_int, int);
int func_800FB5F8(func_800D4910_t*, u_int, int);
int func_800FB62C(func_800D4910_t*, u_int, int);
int func_800FB71C(func_800D4910_t*, u_int, int);
int func_800FB720(func_800D4910_t*, u_int, int);
int func_800FB89C(func_800D4910_t*, u_int, int);
int func_800FBA00(func_800D4910_t*, u_int, int);
int func_800FBA18(func_800D4910_t*, u_int, int);
int func_800FBAC8(func_800D4910_t*, u_int, int);
int func_800FBB24(func_800D4910_t*, u_int, int);
int func_800FBD60(func_800D4910_t*, u_int, int);
int func_800FBDE4(func_800D4910_t*, u_int, int);
int func_800FBDF8(func_800D4910_t*, u_int, int);
int func_800FBE44(func_800D4910_t*, u_int, int);
int func_800FBE88(func_800D4910_t*, u_int, int);
int func_800FBEFC(func_800D4910_t*, u_int, int);
int func_800FBF4C(func_800D4910_t*, u_int, int);
int func_800FBF6C(func_800D4910_t*, u_int, int);
int func_800FBF7C(func_800D4910_t*, u_int, int);
int func_800FBF94(func_800D4910_t*, u_int, int);
int func_800FBFCC(func_800D4910_t*, u_int, int);
int func_800FBFDC(func_800D4910_t*, u_int, int);
int func_800FC0E4(func_800D4910_t*, u_int, int);
int func_800FC11C(func_800D4910_t*, u_int, int);
int func_800FC21C(func_800D4910_t*, u_int, int);
int func_800FC228(func_800D4910_t*, u_int, int);
int func_800FC29C(func_800D4910_t*, u_int, int);
int func_800FC2BC(func_800D4910_t*, u_int, int);
int func_800FC42C(func_800D4910_t*, u_int, int);
int func_800FC50C(func_800D4910_t*, u_int, int);
int func_800FC524(func_800D4910_t*, u_int, int);
int func_800FC568(func_800D4910_t*, u_int, int);
int func_800FC56C(func_800D4910_t*, u_int, int);
int func_800FC624(func_800D4910_t*, u_int, int);
int func_800FC6EC(func_800D4910_t*, u_int, int);
int func_800FC8C4(func_800D4910_t*, u_int, int);
int func_800FC8D0(func_800D4910_t*, u_int, int);
int func_800FC97C(func_800D4910_t*, u_int, int);
int func_800FCA2C(func_800D4910_t*, u_int, int);
int func_800FCA50(func_800D4910_t*, u_int, int);
int func_800FCABC(func_800D4910_t*, u_int, int);
int func_800FCB0C(func_800D4910_t*, u_int, int);
int func_800FCB38(func_800D4910_t*, u_int, int);
int func_800FCE0C(func_800D4910_t*, u_int, int);
int func_800FCE78(func_800D4910_t*, u_int, int);
int func_800FCE90(func_800D4910_t*, u_int, int);
int func_800FCF18(func_800D4910_t*, u_int, int);
int func_800FCFB4(func_800D4910_t*, u_int, int);
int func_800FCFEC(func_800D4910_t*, u_int, int);
int func_800FD074(func_800D4910_t*, u_int, int);
int func_800FD104(func_800D4910_t*, u_int, int);
int func_800FD198(func_800D4910_t*, u_int, int);
int func_800FD2E4(func_800D4910_t*, u_int, int);
int func_800FD354(func_800D4910_t*, u_int, int);
int func_800FD420(func_800D4910_t*, u_int, int);
int func_800FD4F4(func_800D4910_t*, u_int, int);
int func_800FD51C(func_800D4910_t*, u_int, int);
int func_800FD534(func_800D4910_t*, u_int, int);
int func_800FD654(func_800D4910_t*, u_int, int);
int func_800FD6C0(func_800D4910_t*, u_int, int);
int func_800FDA1C(func_800D4910_t*, u_int, int);
int func_800FDBAC(func_800D4910_t*, u_int, int);
int func_800FDC20(func_800D4910_t*, u_int, int);
int func_800FDE48(func_800D4910_t*, u_int, int);
int func_800FDEC4(func_800D4910_t*, u_int, int);
int func_800FE044(func_800D4910_t*, u_int, int);
int func_800FE3EC(func_800D4910_t*, u_int, int);
int func_800FE958(func_800D4910_t*, u_int, int);
int func_800FF334(func_800D4910_t*, u_int, int);
int func_800FF46C(func_800D4910_t*, u_int, int);
int func_800FF4E8(func_800D4910_t*, u_int, int);
int func_800FFB04(func_800D4910_t*, u_int, int);
int func_800FFFA8(func_800D4910_t*, u_int, int);

static u_char D_800FAE4C[] = { 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1,
    1, 0, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 2, 2, 1, 1, 1, 2, 2, 3,
    1, 1, 1, 1, 2, 2, 2, 2, 1, 1, 1, 1, 2, 2, 2, 2, 1, 1, 1, 1, 3, 3, 3, 3, 1, 1, 1, 1, 3,
    3, 3, 3, 1, 1, 2, 1, 2, 1, 1, 2, 1, 1, 1, 1, 1, 3, 3, 2, 0, 2, 2, 1, 1, 2, 1, 1, 1, 1,
    1, 1, 2, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 2, 1,
    1, 4, 4, 3, 1, 1, 2, 3, 2, 3, 4, 3, 3, 4, 4, 3, 1, 2, 1, 3, 1, 4, 2, 3, 3, 1, 1, 2, 1,
    2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2,
    2, 1, 1, 1, 1, 1, 1, 2, 1, 1, 2, 1, 2, 2, 1, 2, 2, 3, 3, 3, 3, 3, 2, 1, 1, 2, 3, 1, 3,
    0, 3, 3, 3, 0, 0, 2, 2, 3, 4, 0, 2, 2, 2, 3, 0, 0, 3, 0, 3, 2, 2, 0, 0, 0, 0, 0, 0, 1,
    1, 1, 2, 2, 2, 2, 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 2, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0 };

static u_char _fbcSlots[] = { 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1 };

#define FBC_DEFAULT { VS_E000_0_FBC_LBA - VS_E000_P_LBA, VS_E000_0_FBC_SIZE }
#define FBC(x) { VS_E##x##_1_FBC_LBA - VS_E000_P_LBA, VS_E##x##_1_FBC_SIZE }

static _loadFileContext _fbcFiles[] = {
    { VS_E000_0_FBC_LBA - VS_E000_P_LBA, VS_E000_0_FBC_SIZE }, FBC(001), FBC(002),
    FBC(003), FBC(004), FBC(005), FBC_DEFAULT, FBC(007), FBC(008), FBC(009), FBC(010),
    FBC_DEFAULT, FBC_DEFAULT, FBC(013), FBC(014), FBC(015), FBC(016), FBC(017), FBC(018),
    FBC(019), FBC(020), FBC_DEFAULT, FBC(022), FBC(023), FBC(024), FBC_DEFAULT, FBC(026),
    FBC(027), FBC_DEFAULT, FBC(029), FBC(030), FBC_DEFAULT, FBC(032), FBC_DEFAULT,
    FBC(034), FBC(035), FBC(036), FBC(037), FBC(038), FBC(039), FBC(040), FBC(041),
    FBC(042), FBC(043), FBC(044), FBC(045), FBC(046), FBC(047), FBC(048), FBC(049),
    FBC(050), FBC(051), FBC(052), FBC(053), FBC(054), FBC(055), FBC(056), FBC(057),
    FBC(058), FBC(059), FBC(060), FBC(061), FBC(062), FBC(063), FBC(064), FBC(065),
    FBC(066), FBC(067), FBC(068), FBC(069), FBC(070), FBC(071), FBC(072), FBC(073),
    FBC(074), FBC(075), FBC(076), FBC(077), FBC(078), FBC(079), FBC(080), FBC(081),
    FBC(082), FBC(083), FBC(084), FBC(085), FBC(086), FBC(087), FBC(088), FBC(089),
    FBC(090), FBC(091), FBC(092), FBC(093), FBC(094), FBC(095), FBC(096), FBC_DEFAULT,
    FBC(098), FBC(099), FBC(100), FBC(101), FBC(102), FBC(103), FBC(104), FBC(105),
    FBC(106), FBC(107), FBC(108), FBC(109), FBC(110), FBC(111), FBC(112), FBC_DEFAULT,
    FBC(114), FBC(115), FBC(116), FBC(117), FBC(118), FBC(119), FBC(120), FBC(121),
    FBC_DEFAULT, FBC_DEFAULT, FBC(124), FBC(125), FBC(126), FBC(127), FBC(128), FBC(129),
    FBC_DEFAULT, FBC(131), FBC(132), FBC(133), FBC(134), FBC(135), FBC(136), FBC(137),
    FBC(138), FBC(139), FBC(140), FBC(141), FBC(142), FBC(143), FBC(144), FBC(145),
    FBC(146), FBC(147), FBC(148), FBC(149), FBC(150), FBC(151), FBC(152), FBC(153),
    FBC(154), FBC(155), FBC(156), FBC(157), FBC(158), FBC(159), FBC(160), FBC(161),
    FBC(162), FBC(163), FBC(164), FBC(165), FBC(166), FBC(167), FBC(168), FBC(169),
    FBC(170), FBC(171), FBC(172), FBC(173), FBC(174), FBC(175), FBC(176), FBC(177),
    FBC(178), FBC(179), FBC(180), FBC(181), FBC(182), FBC(183), FBC(184), FBC(185),
    FBC(186), FBC(187), FBC(188), FBC(189), FBC(190), FBC(191), FBC(192), FBC(193),
    FBC(194), FBC(195), FBC(196), FBC(197), FBC(198), FBC(199), FBC(200), FBC(201),
    FBC(202), FBC(203), FBC(204), FBC(205), FBC(206), FBC(207), FBC(208), FBC(209),
    FBC(210), FBC(211), FBC(212), FBC(213), FBC(214), FBC(215), FBC(216), FBC(217),
    FBC(218), FBC(219), FBC(220), FBC(221), FBC(222), FBC(223), FBC(224), FBC(225),
    FBC(226), FBC(227), FBC(228), FBC(229), FBC(230), FBC(231), FBC(232), FBC(233),
    FBC(234), FBC(235), FBC(236), FBC(237), FBC(238), FBC(239), FBC(240), FBC(241),
    FBC(242), FBC(243), FBC(244), FBC(245), FBC(246), FBC(247), FBC(248), FBC(249),
    FBC(250), FBC(251), FBC_DEFAULT, FBC(253), FBC(254), FBC(255), FBC_DEFAULT,
    FBC_DEFAULT, FBC(258), FBC(259), FBC(260), FBC(261), FBC_DEFAULT, FBC(263), FBC(264),
    FBC(265), FBC(266), FBC_DEFAULT, FBC_DEFAULT, FBC(269), FBC_DEFAULT, FBC(271),
    FBC(272), FBC(273), FBC_DEFAULT, FBC_DEFAULT, FBC_DEFAULT, FBC_DEFAULT, FBC_DEFAULT,
    FBC_DEFAULT, FBC(280), FBC(281), FBC(282), FBC(283), FBC(284), FBC(285), FBC(286),
    FBC(287), FBC(288), FBC(289), FBC(290), FBC(291), FBC(292), FBC(293), FBC(294),
    FBC(295), FBC(296), FBC(297), FBC(298), FBC(299), FBC(300), FBC(301), FBC(302),
    FBC_DEFAULT, FBC_DEFAULT, FBC_DEFAULT, FBC_DEFAULT, FBC_DEFAULT, FBC_DEFAULT,
    FBC_DEFAULT, FBC_DEFAULT, FBC_DEFAULT, FBC_DEFAULT, FBC_DEFAULT, FBC_DEFAULT,
    FBC_DEFAULT, FBC_DEFAULT, FBC_DEFAULT, FBC_DEFAULT, FBC_DEFAULT, FBC_DEFAULT,
    FBC_DEFAULT, FBC_DEFAULT, FBC_DEFAULT, FBC_DEFAULT, FBC_DEFAULT, FBC_DEFAULT,
    FBC_DEFAULT, FBC_DEFAULT, FBC_DEFAULT, FBC_DEFAULT, FBC_DEFAULT, FBC_DEFAULT,
    FBC_DEFAULT, FBC_DEFAULT, FBC_DEFAULT, FBC_DEFAULT, FBC_DEFAULT, FBC_DEFAULT,
    FBC_DEFAULT, FBC_DEFAULT, FBC_DEFAULT, FBC_DEFAULT, FBC_DEFAULT, FBC_DEFAULT,
    FBC_DEFAULT, FBC_DEFAULT, FBC_DEFAULT, FBC_DEFAULT, FBC_DEFAULT, FBC_DEFAULT,
    FBC_DEFAULT, FBC_DEFAULT, FBC_DEFAULT, FBC_DEFAULT, FBC_DEFAULT, FBC_DEFAULT,
    FBC_DEFAULT, FBC_DEFAULT, FBC_DEFAULT, FBC_DEFAULT, FBC_DEFAULT, FBC_DEFAULT,
    FBC_DEFAULT, FBC_DEFAULT, FBC_DEFAULT, FBC_DEFAULT, FBC_DEFAULT, FBC_DEFAULT,
    FBC_DEFAULT, FBC_DEFAULT, FBC_DEFAULT, FBC_DEFAULT, FBC_DEFAULT, FBC_DEFAULT,
    FBC_DEFAULT, FBC_DEFAULT, FBC_DEFAULT, FBC_DEFAULT, FBC_DEFAULT, FBC_DEFAULT,
    FBC_DEFAULT, FBC_DEFAULT, FBC_DEFAULT, FBC_DEFAULT, FBC_DEFAULT, FBC_DEFAULT,
    FBC_DEFAULT, FBC_DEFAULT, FBC_DEFAULT, FBC_DEFAULT, FBC_DEFAULT, FBC_DEFAULT,
    FBC_DEFAULT, FBC_DEFAULT, FBC_DEFAULT, FBC_DEFAULT, FBC_DEFAULT, FBC_DEFAULT,
    FBC_DEFAULT
};

static u_char _fbtCounts[] = { 1, 2, 2, 2, 2, 3, 0, 2, 2, 2, 2, 0, 0, 2, 2, 2, 2, 2, 2, 2,
    2, 0, 2, 2, 3, 0, 2, 2, 0, 3, 3, 0, 3, 0, 2, 3, 3, 3, 3, 3, 3, 2, 2, 2, 3, 3, 3, 3, 3,
    3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
    3, 3, 3, 3, 3, 4, 4, 3, 3, 3, 3, 1, 3, 3, 3, 3, 3, 3, 3, 0, 3, 3, 3, 3, 3, 3, 3, 3, 3,
    3, 3, 3, 2, 2, 3, 0, 2, 3, 3, 2, 3, 3, 3, 3, 0, 0, 3, 3, 3, 2, 6, 3, 0, 3, 3, 3, 3, 3,
    3, 3, 3, 3, 3, 3, 3, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 2, 3, 3, 3, 3, 3,
    3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
    2, 3, 2, 2, 3, 3, 3, 2, 2, 1, 1, 3, 2, 2, 1, 1, 3, 3, 2, 1, 2, 2, 2, 3, 1, 1, 3, 3, 3,
    3, 2, 3, 3, 3, 3, 2, 3, 2, 3, 2, 3, 3, 3, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
    0, 3, 3, 3, 0, 0, 3, 3, 3, 3, 0, 3, 3, 3, 3, 0, 0, 3, 0, 3, 7, 3, 0, 0, 0, 0, 0, 0, 3,
    1, 3, 3, 3, 3, 2, 1, 3, 3, 3, 3, 1, 1, 2, 1, 1, 3, 1, 1, 3, 3, 1, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0 };

static u_char _fbtSlots[] = { 0, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 3, 1, 2, 1, 2, 1, 2, 1, 2,
    1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 3, 1, 2, 1, 2, 1, 2,
    3, 1, 2, 3, 1, 2, 3, 1, 2, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2,
    1, 2, 1, 2, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1,
    2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3,
    1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2,
    3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1,
    2, 3, 1, 2, 3, 1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 1, 2, 3,
    1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2,
    3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 1, 2,
    1, 2, 3, 1, 2, 1, 2, 3, 1, 2, 3, 1, 2, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1,
    2, 3, 1, 2, 3, 1, 2, 1, 2, 3, 4, 5, 6, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1,
    2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 1, 2, 3, 1,
    2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3,
    1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3,
    1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2,
    3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1,
    2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3,
    1, 2, 1, 2, 3, 1, 2, 1, 2, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 1, 2, 1, 1, 1, 2, 3, 1, 2,
    1, 2, 1, 1, 1, 2, 3, 1, 2, 3, 1, 2, 1, 1, 2, 1, 2, 1, 2, 1, 2, 3, 1, 1, 1, 2, 3, 1, 2,
    3, 1, 2, 3, 1, 2, 3, 1, 2, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 1, 2, 3, 1, 2, 1,
    2, 3, 1, 2, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2,
    3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1,
    2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3,
    1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 4, 5, 6, 7, 1, 2, 3, 1, 2, 3, 1, 1, 2, 3, 1, 2, 3,
    1, 2, 3, 1, 2, 3, 1, 2, 1, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 1, 1, 2, 1, 1, 1, 2,
    3, 1, 1, 1, 2, 3, 1, 2, 3, 1, 0 };

#define FBT(x) { VS_E##x##_FBT_LBA - VS_E000_P_LBA, VS_E##x##_FBT_SIZE }

static _loadFileContext _fbtFiles[] = { FBT(000_0), FBT(001_1), FBT(001_2), FBT(002_1),
    FBT(002_2), FBT(003_1), FBT(003_2), FBT(004_1), FBT(004_2), FBT(005_1), FBT(005_2),
    FBT(005_3), FBT(007_1), FBT(007_2), FBT(008_1), FBT(008_2), FBT(009_1), FBT(009_2),
    FBT(010_1), FBT(010_2), FBT(013_1), FBT(013_2), FBT(014_1), FBT(014_2), FBT(015_1),
    FBT(015_2), FBT(016_1), FBT(016_2), FBT(017_1), FBT(017_2), FBT(018_1), FBT(018_2),
    FBT(019_1), FBT(019_2), FBT(020_1), FBT(020_2), FBT(022_1), FBT(022_2), FBT(023_1),
    FBT(023_2), FBT(024_1), FBT(024_2), FBT(024_3), FBT(026_1), FBT(026_2), FBT(027_1),
    FBT(027_2), FBT(029_1), FBT(029_2), FBT(029_3), FBT(030_1), FBT(030_2), FBT(030_3),
    FBT(032_1), FBT(032_2), FBT(032_3), FBT(034_1), FBT(034_2), FBT(035_1), FBT(035_2),
    FBT(035_3), FBT(036_1), FBT(036_2), FBT(036_3), FBT(037_1), FBT(037_2), FBT(037_3),
    FBT(038_1), FBT(038_2), FBT(038_3), FBT(039_1), FBT(039_2), FBT(039_3), FBT(040_1),
    FBT(040_2), FBT(040_3), FBT(041_1), FBT(041_2), FBT(042_1), FBT(042_2), FBT(043_1),
    FBT(043_2), FBT(044_1), FBT(044_2), FBT(044_3), FBT(045_1), FBT(045_2), FBT(045_3),
    FBT(046_1), FBT(046_2), FBT(046_3), FBT(047_1), FBT(047_2), FBT(047_3), FBT(048_1),
    FBT(048_2), FBT(048_3), FBT(049_1), FBT(049_2), FBT(049_3), FBT(050_1), FBT(050_2),
    FBT(050_3), FBT(051_1), FBT(051_2), FBT(051_3), FBT(052_1), FBT(052_2), FBT(052_3),
    FBT(053_1), FBT(053_2), FBT(053_3), FBT(054_1), FBT(054_2), FBT(054_3), FBT(055_1),
    FBT(055_2), FBT(055_3), FBT(056_1), FBT(056_2), FBT(056_3), FBT(057_1), FBT(057_2),
    FBT(057_3), FBT(058_1), FBT(058_2), FBT(058_3), FBT(059_1), FBT(059_2), FBT(059_3),
    FBT(060_1), FBT(060_2), FBT(060_3), FBT(061_1), FBT(061_2), FBT(061_3), FBT(062_1),
    FBT(062_2), FBT(062_3), FBT(063_1), FBT(063_2), FBT(063_3), FBT(064_1), FBT(064_2),
    FBT(064_3), FBT(065_1), FBT(065_2), FBT(065_3), FBT(066_1), FBT(066_2), FBT(066_3),
    FBT(067_1), FBT(067_2), FBT(067_3), FBT(068_1), FBT(068_2), FBT(068_3), FBT(069_1),
    FBT(069_2), FBT(069_3), FBT(070_1), FBT(070_2), FBT(070_3), FBT(071_1), FBT(071_2),
    FBT(071_3), FBT(072_1), FBT(072_2), FBT(072_3), FBT(073_1), FBT(073_2), FBT(073_3),
    FBT(074_1), FBT(074_2), FBT(074_3), FBT(075_1), FBT(075_2), FBT(075_3), FBT(076_1),
    FBT(076_2), FBT(076_3), FBT(077_1), FBT(077_2), FBT(077_3), FBT(078_1), FBT(078_2),
    FBT(078_3), FBT(079_1), FBT(079_2), FBT(079_3), FBT(080_1), FBT(080_2), FBT(080_3),
    FBT(081_1), FBT(081_2), FBT(081_3), FBT(082_1), FBT(082_2), FBT(082_3), FBT(083_1),
    FBT(083_2), FBT(083_3), FBT(083_4), FBT(084_1), FBT(084_2), FBT(084_3), FBT(084_4),
    FBT(085_1), FBT(085_2), FBT(085_3), FBT(086_1), FBT(086_2), FBT(086_3), FBT(087_1),
    FBT(087_2), FBT(087_3), FBT(088_1), FBT(088_2), FBT(088_3), FBT(089_1), FBT(090_1),
    FBT(090_2), FBT(090_3), FBT(091_1), FBT(091_2), FBT(091_3), FBT(092_1), FBT(092_2),
    FBT(092_3), FBT(093_1), FBT(093_2), FBT(093_3), FBT(094_1), FBT(094_2), FBT(094_3),
    FBT(095_1), FBT(095_2), FBT(095_3), FBT(096_1), FBT(096_2), FBT(096_3), FBT(098_1),
    FBT(098_2), FBT(098_3), FBT(099_1), FBT(099_2), FBT(099_3), FBT(100_1), FBT(100_2),
    FBT(100_3), FBT(101_1), FBT(101_2), FBT(101_3), FBT(102_1), FBT(102_2), FBT(102_3),
    FBT(103_1), FBT(103_2), FBT(103_3), FBT(104_1), FBT(104_2), FBT(104_3), FBT(105_1),
    FBT(105_2), FBT(105_3), FBT(106_1), FBT(106_2), FBT(106_3), FBT(107_1), FBT(107_2),
    FBT(107_3), FBT(108_1), FBT(108_2), FBT(108_3), FBT(109_1), FBT(109_2), FBT(109_3),
    FBT(110_1), FBT(110_2), FBT(111_1), FBT(111_2), FBT(112_1), FBT(112_2), FBT(112_3),
    FBT(114_1), FBT(114_2), FBT(115_1), FBT(115_2), FBT(115_3), FBT(116_1), FBT(116_2),
    FBT(116_3), FBT(117_1), FBT(117_2), FBT(118_1), FBT(118_2), FBT(118_3), FBT(119_1),
    FBT(119_2), FBT(119_3), FBT(120_1), FBT(120_2), FBT(120_3), FBT(121_1), FBT(121_2),
    FBT(121_3), FBT(124_1), FBT(124_2), FBT(124_3), FBT(125_1), FBT(125_2), FBT(125_3),
    FBT(126_1), FBT(126_2), FBT(126_3), FBT(127_1), FBT(127_2), FBT(128_1), FBT(128_2),
    FBT(128_3), FBT(128_4), FBT(128_5), FBT(128_6), FBT(129_1), FBT(129_2), FBT(129_3),
    FBT(131_1), FBT(131_2), FBT(131_3), FBT(132_1), FBT(132_2), FBT(132_3), FBT(133_1),
    FBT(133_2), FBT(133_3), FBT(134_1), FBT(134_2), FBT(134_3), FBT(135_1), FBT(135_2),
    FBT(135_3), FBT(136_1), FBT(136_2), FBT(136_3), FBT(137_1), FBT(137_2), FBT(137_3),
    FBT(138_1), FBT(138_2), FBT(138_3), FBT(139_1), FBT(139_2), FBT(139_3), FBT(140_1),
    FBT(140_2), FBT(140_3), FBT(141_1), FBT(141_2), FBT(141_3), FBT(142_1), FBT(142_2),
    FBT(142_3), FBT(143_1), FBT(143_2), FBT(144_1), FBT(144_2), FBT(144_3), FBT(145_1),
    FBT(145_2), FBT(145_3), FBT(146_1), FBT(146_2), FBT(146_3), FBT(147_1), FBT(147_2),
    FBT(147_3), FBT(148_1), FBT(148_2), FBT(148_3), FBT(149_1), FBT(149_2), FBT(149_3),
    FBT(150_1), FBT(150_2), FBT(150_3), FBT(151_1), FBT(151_2), FBT(151_3), FBT(152_1),
    FBT(152_2), FBT(152_3), FBT(153_1), FBT(153_2), FBT(153_3), FBT(154_1), FBT(154_2),
    FBT(154_3), FBT(155_1), FBT(155_2), FBT(155_3), FBT(156_1), FBT(156_2), FBT(156_3),
    FBT(157_1), FBT(157_2), FBT(157_3), FBT(158_1), FBT(158_2), FBT(158_3), FBT(159_1),
    FBT(159_2), FBT(160_1), FBT(160_2), FBT(160_3), FBT(161_1), FBT(161_2), FBT(161_3),
    FBT(162_1), FBT(162_2), FBT(162_3), FBT(163_1), FBT(163_2), FBT(163_3), FBT(164_1),
    FBT(164_2), FBT(164_3), FBT(165_1), FBT(165_2), FBT(165_3), FBT(166_1), FBT(166_2),
    FBT(166_3), FBT(167_1), FBT(167_2), FBT(167_3), FBT(168_1), FBT(168_2), FBT(168_3),
    FBT(169_1), FBT(169_2), FBT(169_3), FBT(170_1), FBT(170_2), FBT(170_3), FBT(171_1),
    FBT(171_2), FBT(171_3), FBT(172_1), FBT(172_2), FBT(172_3), FBT(173_1), FBT(173_2),
    FBT(173_3), FBT(174_1), FBT(174_2), FBT(174_3), FBT(175_1), FBT(175_2), FBT(175_3),
    FBT(176_1), FBT(176_2), FBT(176_3), FBT(177_1), FBT(177_2), FBT(177_3), FBT(178_1),
    FBT(178_2), FBT(178_3), FBT(179_1), FBT(179_2), FBT(179_3), FBT(180_1), FBT(180_2),
    FBT(180_3), FBT(181_1), FBT(181_2), FBT(181_3), FBT(182_1), FBT(182_2), FBT(182_3),
    FBT(183_1), FBT(183_2), FBT(183_3), FBT(184_1), FBT(184_2), FBT(184_3), FBT(185_1),
    FBT(185_2), FBT(185_3), FBT(186_1), FBT(186_2), FBT(186_3), FBT(187_1), FBT(187_2),
    FBT(187_3), FBT(188_1), FBT(188_2), FBT(188_3), FBT(189_1), FBT(189_2), FBT(189_3),
    FBT(190_1), FBT(190_2), FBT(190_3), FBT(191_1), FBT(191_2), FBT(191_3), FBT(192_1),
    FBT(192_2), FBT(192_3), FBT(193_1), FBT(193_2), FBT(193_3), FBT(194_1), FBT(194_2),
    FBT(195_1), FBT(195_2), FBT(195_3), FBT(196_1), FBT(196_2), FBT(197_1), FBT(197_2),
    FBT(198_1), FBT(198_2), FBT(198_3), FBT(199_1), FBT(199_2), FBT(199_3), FBT(200_1),
    FBT(200_2), FBT(200_3), FBT(201_1), FBT(201_2), FBT(202_1), FBT(202_2), FBT(203_1),
    FBT(204_1), FBT(205_1), FBT(205_2), FBT(205_3), FBT(206_1), FBT(206_2), FBT(207_1),
    FBT(207_2), FBT(208_1), FBT(209_1), FBT(210_1), FBT(210_2), FBT(210_3), FBT(211_1),
    FBT(211_2), FBT(211_3), FBT(212_1), FBT(212_2), FBT(213_1), FBT(214_1), FBT(214_2),
    FBT(215_1), FBT(215_2), FBT(216_1), FBT(216_2), FBT(217_1), FBT(217_2), FBT(217_3),
    FBT(218_1), FBT(219_1), FBT(220_1), FBT(220_2), FBT(220_3), FBT(221_1), FBT(221_2),
    FBT(221_3), FBT(222_1), FBT(222_2), FBT(222_3), FBT(223_1), FBT(223_2), FBT(223_3),
    FBT(224_1), FBT(224_2), FBT(225_1), FBT(225_2), FBT(225_3), FBT(226_1), FBT(226_2),
    FBT(226_3), FBT(227_1), FBT(227_2), FBT(227_3), FBT(228_1), FBT(228_2), FBT(228_3),
    FBT(229_1), FBT(229_2), FBT(230_1), FBT(230_2), FBT(230_3), FBT(231_1), FBT(231_2),
    FBT(232_1), FBT(232_2), FBT(232_3), FBT(233_1), FBT(233_2), FBT(234_1), FBT(234_2),
    FBT(234_3), FBT(235_1), FBT(235_2), FBT(235_3), FBT(236_1), FBT(236_2), FBT(236_3),
    FBT(237_1), FBT(237_2), FBT(238_1), FBT(238_2), FBT(238_3), FBT(239_1), FBT(239_2),
    FBT(239_3), FBT(240_1), FBT(240_2), FBT(240_3), FBT(241_1), FBT(241_2), FBT(241_3),
    FBT(242_1), FBT(242_2), FBT(242_3), FBT(243_1), FBT(243_2), FBT(243_3), FBT(244_1),
    FBT(244_2), FBT(244_3), FBT(245_1), FBT(245_2), FBT(245_3), FBT(246_1), FBT(246_2),
    FBT(246_3), FBT(247_1), FBT(247_2), FBT(247_3), FBT(248_1), FBT(248_2), FBT(248_3),
    FBT(249_1), FBT(249_2), FBT(249_3), FBT(250_1), FBT(250_2), FBT(250_3), FBT(251_1),
    FBT(251_2), FBT(251_3), FBT(253_1), FBT(253_2), FBT(253_3), FBT(254_1), FBT(254_2),
    FBT(254_3), FBT(255_1), FBT(255_2), FBT(255_3), FBT(258_1), FBT(258_2), FBT(258_3),
    FBT(259_1), FBT(259_2), FBT(259_3), FBT(260_1), FBT(260_2), FBT(260_3), FBT(261_1),
    FBT(261_2), FBT(261_3), FBT(263_1), FBT(263_2), FBT(263_3), FBT(264_1), FBT(264_2),
    FBT(264_3), FBT(265_1), FBT(265_2), FBT(265_3), FBT(266_1), FBT(266_2), FBT(266_3),
    FBT(269_1), FBT(269_2), FBT(269_3), FBT(271_1), FBT(271_2), FBT(271_3), FBT(272_1),
    FBT(272_2), FBT(272_3), FBT(272_4), FBT(272_5), FBT(272_6), FBT(272_7), FBT(273_1),
    FBT(273_2), FBT(273_3), FBT(280_1), FBT(280_2), FBT(280_3), FBT(281_1), FBT(282_1),
    FBT(282_2), FBT(282_3), FBT(283_1), FBT(283_2), FBT(283_3), FBT(284_1), FBT(284_2),
    FBT(284_3), FBT(285_1), FBT(285_2), FBT(285_3), FBT(286_1), FBT(286_2), FBT(287_1),
    FBT(288_1), FBT(288_2), FBT(288_3), FBT(289_1), FBT(289_2), FBT(289_3), FBT(290_1),
    FBT(290_2), FBT(290_3), FBT(291_1), FBT(291_2), FBT(291_3), FBT(292_1), FBT(293_1),
    FBT(294_1), FBT(294_2), FBT(295_1), FBT(296_1), FBT(297_1), FBT(297_2), FBT(297_3),
    FBT(298_1), FBT(299_1), FBT(300_1), FBT(300_2), FBT(300_3), FBT(301_1), FBT(301_2),
    FBT(301_3), FBT(302_1) };

#define P(x) { VS_E##x##_P_LBA - VS_E000_P_LBA, VS_E##x##_P_SIZE }
#define P_DEFAULT P(000)

static _loadFileContext _pFiles[] = { P_DEFAULT, P(001), P(002), P(003), P(004), P(005),
    P(006), P(007), P(008), P(009), P(010), P(011), P(012), P(013), P(014), P(015),
    P(016), P(017), P(018), P(019), P(020), P(021), P(022), P(023), P(024), P(025),
    P(026), P(027), P(028), P(029), P(030), P(031), P(032), P(033), P(034), P(035),
    P(036), P(037), P(038), P(039), P(040), P(041), P(042), P(043), P(044), P(045),
    P(046), P(047), P(048), P(049), P(050), P(051), P(052), P(053), P(054), P(055),
    P(056), P(057), P(058), P(059), P(060), P(061), P(062), P(063), P(064), P(065),
    P(066), P(067), P(068), P(069), P(070), P(071), P(072), P(073), P(074), P(075),
    P(076), P(077), P(078), P(079), P(080), P(081), P(082), P(083), P(084), P(085),
    P(086), P(087), P(088), P(089), P(090), P(091), P(092), P(093), P(094), P(095),
    P(096), P(097), P(098), P(099), P(100), P(101), P(102), P(103), P(104), P(105),
    P(106), P(107), P(108), P(109), P(110), P(111), P(112), P(113), P(114), P(115),
    P(116), P(117), P(118), P(119), P(120), P(121), P(122), P(123), P(124), P(125),
    P(126), P(127), P(128), P(129), P(130), P(131), P(132), P(133), P(134), P(135),
    P(136), P(137), P(138), P(139), P(140), P(141), P(142), P(143), P(144), P(145),
    P(146), P(147), P(148), P(149), P(150), P(151), P(152), P(153), P(154), P(155),
    P(156), P(157), P(158), P(159), P(160), P(161), P(162), P(163), P(164), P(165),
    P(166), P(167), P(168), P(169), P(170), P(171), P(172), P(173), P(174), P(175),
    P(176), P(177), P(178), P(179), P(180), P(181), P(182), P(183), P(184), P(185),
    P(186), P(187), P(188), P(189), P(190), P(191), P(192), P(193), P(194), P(195),
    P(196), P(197), P(198), P(199), P(200), P(201), P(202), P(203), P(204), P(205),
    P(206), P(207), P(208), P(209), P(210), P(211), P(212), P(213), P(214), P(215),
    P(216), P(217), P(218), P(219), P(220), P(221), P(222), P(223), P(224), P(225),
    P(226), P(227), P(228), P(229), P(230), P(231), P(232), P(233), P(234), P(235),
    P(236), P(237), P(238), P(239), P(240), P(241), P(242), P(243), P(244), P(245),
    P(246), P(247), P(248), P(249), P(250), P(251), P_DEFAULT, P(253), P(254), P(255),
    P_DEFAULT, P_DEFAULT, P(258), P(259), P(260), P(261), P_DEFAULT, P(263), P(264),
    P(265), P(266), P_DEFAULT, P_DEFAULT, P(269), P_DEFAULT, P(271), P(272), P(273),
    P_DEFAULT, P_DEFAULT, P_DEFAULT, P_DEFAULT, P_DEFAULT, P_DEFAULT, P(280), P(281),
    P(282), P(283), P(284), P(285), P(286), P(287), P(288), P(289), P(290), P(291),
    P(292), P(293), P(294), P(295), P(296), P(297), P(298), P(299), P(300), P(301),
    P(302), P_DEFAULT, P_DEFAULT, P_DEFAULT, P_DEFAULT, P_DEFAULT, P_DEFAULT, P_DEFAULT,
    P_DEFAULT, P_DEFAULT, P_DEFAULT, P_DEFAULT, P_DEFAULT, P_DEFAULT, P_DEFAULT,
    P_DEFAULT, P_DEFAULT, P_DEFAULT, P_DEFAULT, P_DEFAULT, P_DEFAULT, P_DEFAULT,
    P_DEFAULT, P_DEFAULT, P_DEFAULT, P_DEFAULT, P_DEFAULT, P_DEFAULT, P_DEFAULT,
    P_DEFAULT, P_DEFAULT, P_DEFAULT, P_DEFAULT, P_DEFAULT, P_DEFAULT, P_DEFAULT,
    P_DEFAULT, P_DEFAULT, P_DEFAULT, P_DEFAULT, P_DEFAULT, P_DEFAULT, P_DEFAULT,
    P_DEFAULT, P_DEFAULT, P_DEFAULT, P_DEFAULT, P_DEFAULT, P_DEFAULT, P_DEFAULT,
    P_DEFAULT, P_DEFAULT, P_DEFAULT, P_DEFAULT, P_DEFAULT, P_DEFAULT, P_DEFAULT,
    P_DEFAULT, P_DEFAULT, P_DEFAULT, P_DEFAULT, P_DEFAULT, P_DEFAULT, P_DEFAULT,
    P_DEFAULT, P_DEFAULT, P_DEFAULT, P_DEFAULT, P_DEFAULT, P_DEFAULT, P_DEFAULT,
    P_DEFAULT, P_DEFAULT, P_DEFAULT, P_DEFAULT, P_DEFAULT, P_DEFAULT, P_DEFAULT,
    P_DEFAULT, P_DEFAULT, P_DEFAULT, P_DEFAULT, P_DEFAULT, P_DEFAULT, P_DEFAULT,
    P_DEFAULT, P_DEFAULT, P_DEFAULT, P_DEFAULT, P_DEFAULT, P_DEFAULT, P_DEFAULT,
    P_DEFAULT, P_DEFAULT, P_DEFAULT, P_DEFAULT, P_DEFAULT, P_DEFAULT };

static u_short _effectEntryPointIndices[] = { 0x000, 0x000, 0x000, 0x000, 0x000, 0x000,
    0x001, 0x001, 0x001, 0x001, 0x001, 0x001, 0x001, 0x001, 0x001, 0x001, 0x001, 0x001,
    0x001, 0x001, 0x001, 0x001, 0x001, 0x001, 0x001, 0x001, 0x001, 0x001, 0x001, 0x001,
    0x001, 0x001, 0x001, 0x001, 0x001, 0x001, 0x001, 0x001, 0x001, 0x001, 0x001, 0x001,
    0x001, 0x001, 0x001, 0x002, 0x003, 0x003, 0x004, 0x005, 0x009, 0x00C, 0x00D, 0x00E,
    0x010, 0x012, 0x014, 0x016, 0x01A, 0x01E, 0x022, 0x026, 0x02A, 0x02E, 0x032, 0x036,
    0x03A, 0x03E, 0x042, 0x046, 0x049, 0x04C, 0x04F, 0x052, 0x057, 0x05C, 0x061, 0x066,
    0x06B, 0x070, 0x075, 0x07A, 0x07F, 0x082, 0x083, 0x085, 0x087, 0x08B, 0x090, 0x090,
    0x090, 0x090, 0x090, 0x090, 0x090, 0x090, 0x090, 0x090, 0x090, 0x090, 0x090, 0x090,
    0x090, 0x091, 0x091, 0x091, 0x091, 0x091, 0x091, 0x091, 0x091, 0x091, 0x091, 0x091,
    0x091, 0x093, 0x093, 0x093, 0x093, 0x093, 0x093, 0x093, 0x093, 0x093, 0x093, 0x093,
    0x093, 0x093, 0x093, 0x09B, 0x0A1, 0x0A1, 0x0A2, 0x0A2, 0x0A3, 0x0A5, 0x0A9, 0x0AB,
    0x0AF, 0x0B3, 0x0B5, 0x0B6, 0x0B7, 0x0BB, 0x0BD, 0x0BE, 0x0BF, 0x0C4, 0x0C6, 0x0C8,
    0x0C9, 0x0CD, 0x0CE, 0x0D1, 0x0D5, 0x0D7, 0x0D9, 0x0DC, 0x0DD, 0x0E1, 0x0E3, 0x0E5,
    0x0EB, 0x0F0, 0x0F0, 0x0F1, 0x0F6, 0x0FA, 0x0FE, 0x102, 0x106, 0x10C, 0x10C, 0x10C,
    0x10C, 0x10C, 0x10C, 0x10C, 0x10C, 0x10C, 0x10C, 0x10C, 0x10C, 0x10C, 0x10C, 0x10C,
    0x10C, 0x10C, 0x10C, 0x10C, 0x10C, 0x10C, 0x10C, 0x10C, 0x10C, 0x10C, 0x10C, 0x10C,
    0x10C, 0x10D, 0x10E, 0x10E, 0x10E, 0x10E, 0x10E, 0x10E, 0x10E, 0x10E, 0x10E, 0x10E,
    0x10E, 0x10E, 0x10E, 0x10E, 0x10E, 0x10E, 0x10E, 0x10E, 0x10E, 0x10E, 0x10E, 0x10E,
    0x110, 0x110, 0x110, 0x111, 0x111, 0x111, 0x111, 0x111, 0x111, 0x111, 0x111, 0x112,
    0x112, 0x112, 0x112, 0x116, 0x116, 0x116, 0x116, 0x117, 0x118, 0x11B, 0x11E, 0x11E,
    0x11F, 0x122, 0x127, 0x128, 0x128, 0x12A, 0x12B, 0x12B, 0x12B, 0x12B, 0x12D, 0x12D,
    0x12D, 0x12E, 0x12F, 0x130, 0x130, 0x130, 0x135, 0x135, 0x139, 0x13C, 0x13C, 0x13C,
    0x13F, 0x13F, 0x141, 0x144, 0x145, 0x145, 0x145, 0x145, 0x145, 0x145, 0x145, 0x148,
    0x148, 0x148, 0x148, 0x148, 0x148, 0x148, 0x148, 0x148, 0x148, 0x149, 0x14C, 0x14C,
    0x14C, 0x14C, 0x14C, 0x14C, 0x150, 0x150, 0x150, 0x154, 0x157, 0x157, 0x157, 0x157,
    0x157, 0x157, 0x157, 0x157, 0x157, 0x157, 0x157, 0x157, 0x157, 0x157, 0x157, 0x157,
    0x157, 0x157, 0x157, 0x157, 0x157, 0x157, 0x157, 0x157, 0x157, 0x157, 0x157, 0x157,
    0x157, 0x157, 0x157, 0x157, 0x157, 0x157, 0x157, 0x157, 0x157, 0x157, 0x157, 0x157,
    0x157, 0x157, 0x157, 0x157, 0x157, 0x157, 0x157, 0x157, 0x157, 0x157, 0x157, 0x157,
    0x157, 0x157, 0x157, 0x157, 0x157, 0x157, 0x157, 0x157, 0x157, 0x157, 0x157, 0x157,
    0x157, 0x157, 0x157, 0x157, 0x157, 0x157, 0x157, 0x157, 0x157, 0x157, 0x157, 0x157,
    0x157, 0x157, 0x157, 0x157, 0x157, 0x157, 0x157, 0x157, 0x157, 0x157, 0x157, 0x157,
    0x157, 0x157, 0x157, 0x157, 0x157, 0x157, 0x157, 0x157, 0x157, 0x157 };

static effectExec _effectEntryPoints[] = { func_800F9818, func_800F9800, func_800FB320,
    func_800F9800, func_800F9800, func_800FB4C0, func_800FBA00, func_800FC624,
    func_800FD51C, func_800F98E0, func_800FC0E4, NULL, func_800F9800, func_800F9800,
    func_800F9818, func_800FA368, func_800F9818, func_800FA368, func_800F9818,
    func_800FA368, func_800F9818, func_800FA368, func_800FB4E0, NULL, func_800FD354,
    func_800FF46C, func_800FB4E0, NULL, func_800FD354, func_800FF46C, func_800FB4E0, NULL,
    func_800FD354, func_800FF46C, func_800FB4E0, NULL, func_800FD354, func_800FF46C,
    func_800F9818, func_800FA3B0, func_800FAF00, func_800FBB24, func_800F9818,
    func_800FA3B0, func_800FAF00, func_800FBB24, func_800F9818, func_800FA3B0,
    func_800FAF00, func_800FBB24, func_800F9818, func_800FA3B0, func_800FAF00,
    func_800FBB24, func_800F98F8, func_800FA7B0, func_800FB71C, func_800FD6C0,
    func_800F98F8, func_800FA7B0, func_800FB71C, func_800FD6C0, func_800F98F8,
    func_800FA7B0, func_800FB71C, func_800FD6C0, func_800F98F8, func_800FA7B0,
    func_800FB71C, func_800FD6C0, func_800F98E0, func_800FBFCC, func_800FC50C,
    func_800F98E0, func_800FBFCC, func_800FC50C, func_800F98E0, func_800FBFCC,
    func_800FC50C, func_800F98E0, func_800FBFCC, func_800FC50C, func_800F98F8,
    func_800FA7F0, func_800FCFEC, func_800FD534, func_800FE3EC, func_800F98F8,
    func_800FA7F0, func_800FCFEC, func_800FD534, func_800FE3EC, func_800F98F8,
    func_800FA7F0, func_800FCFEC, func_800FD534, func_800FE3EC, func_800F98F8,
    func_800FA7F0, func_800FCFEC, func_800FD534, func_800FE3EC, func_800F9818,
    func_800FA324, func_800FB294, func_800FBDE4, func_800FC97C, func_800F9818,
    func_800FA324, func_800FB294, func_800FBDE4, func_800FC97C, func_800F9818,
    func_800FA324, func_800FB294, func_800FBDE4, func_800FC97C, func_800F9818,
    func_800FA324, func_800FB294, func_800FBDE4, func_800FC97C, NULL, NULL, func_800F9800,
    func_800FA6B8, func_800FB2DC, func_800FB338, func_800FB5CC, func_800FC11C,
    func_800F9800, func_800F9818, func_800FA368, func_800F9818, func_800FA368,
    func_800F98F8, func_800FA868, func_800FB720, func_800FDE48, func_800F99F0,
    func_800FA588, func_800FB4F8, func_800FDC20, func_800FF4E8, func_800FB320,
    func_800FB418, func_800FCA2C, func_800F98F8, func_800FA490, func_800FB400,
    func_800FC2BC, func_800FCE0C, NULL, func_800FDEC4, func_800FFFA8, func_800F9800, NULL,
    func_800FA424, func_800FAF30, func_800FBAC8, func_800FC6EC, func_800F9800,
    func_800F9800, func_800FB4B8, func_800FBA00, NULL, func_800F98E0, NULL, func_800FC42C,
    func_800F9818, func_800FA368, func_800F98F8, func_800FBFDC, func_800FC524,
    func_800FD074, func_800F9818, func_800FA6D0, func_800FB2F4, func_800FBE44,
    func_800F9818, func_800FA710, func_800FB320, func_800FB4B8, func_800F9818,
    func_800FA368, func_800FB2D8, func_800FBEFC, func_800F9800, func_800FA6F8,
    func_800F9800, func_800F9800, func_800F99D8, func_800FA8D0, func_800FC8C4,
    func_800FCB38, func_800FF334, func_800F98F8, func_800FB89C, func_800FB4B8,
    func_800FBA00, func_800F9800, func_800F9818, func_800FA710, func_800FB260,
    func_800FBDF8, func_800F9800, func_800F9928, func_800FBE88, func_800FC11C, NULL,
    func_800F9910, func_800FA41C, func_800FCA50, func_800F9800, func_800FA30C,
    func_800F9818, func_800FA710, func_800FB338, NULL, func_800FB5CC, func_800F9800,
    func_800F9800, func_800FA398, func_800FB00C, func_800FBF7C, func_800F9818,
    func_800FA710, func_800F9800, func_800FA6F8, NULL, func_800F98F8, func_800FA7B0,
    func_800FCFB4, func_800FD4F4, func_800FE044, NULL, func_800F9800, func_800FA740,
    func_800FB5F8, func_800FC21C, func_800FB320, func_800FB4D8, NULL, func_800FBA18,
    func_800FC8D0, func_800FD420, func_800F9800, func_800FA6B8, func_800FB32C,
    func_800FC29C, NULL, func_800F98E0, func_800FA84C, func_800FD2E4, NULL, func_800FB5D0,
    func_800FCE90, func_800FD104, func_800FB4C0, NULL, func_800FBA00, func_800FC624,
    func_800F9818, func_800FA48C, func_800FB348, func_800FBF6C, func_800FCABC,
    func_800FD654, func_800F9800, func_800F9800, func_800F9818, func_800FA710,
    func_800FAC78, func_800FB4C0, func_800F9800, func_800FA770, func_800FB62C,
    func_800FC56C, func_800FAC78, func_800FAC78, func_800F98F8, func_800FA7F0,
    func_800FCF18, NULL, NULL, func_800FB4B8, func_800F9800, NULL, NULL, func_800F9800,
    NULL, NULL, func_800F9800, func_800FA6B8, func_800FB2DC, func_800F9800, func_800F9800,
    func_800FA6BC, func_800F9800, func_800FB5B0, func_800FCE78, func_800F9800,
    func_800F9800, func_800F9800, NULL, func_800F9910, func_800FA4A8, func_800FB0CC,
    func_800FDA1C, func_800F9AE8, func_800FBD60, func_800FDBAC, func_800FFB04,
    func_800FB4F8, func_800FCB0C, func_800FE958, NULL, NULL, func_800FB4B8, func_800FB5B0,
    func_800FCE78, func_800F9818, func_800FA368, func_800FB2D8, func_800F9800,
    func_800FB338, func_800FB5CC, func_800FC11C, func_800FB320, func_800FB4D0,
    func_800FBA18, func_800FC568, func_800F9818, func_800FA48C, func_800FB3FC,
    func_800FBF4C, func_800F9910, func_800FBF94, func_800FC228, func_800FD198,
    func_800FB320, NULL, func_800FB5B4 };

#define PLG(x) { VS_PLG##x##_BIN_LBA - VS_E000_P_LBA, VS_PLG##x##_BIN_SIZE }
#define PLG_NONE { 0x0000, 0x0000 }

static _loadFileContext _plgFiles[] = { PLG_NONE, PLG_NONE, PLG_NONE, PLG_NONE, PLG_NONE,
    PLG(005), PLG_NONE, PLG_NONE, PLG_NONE, PLG_NONE, PLG_NONE, PLG_NONE, PLG_NONE,
    PLG_NONE, PLG_NONE, PLG_NONE, PLG_NONE, PLG_NONE, PLG_NONE, PLG_NONE, PLG_NONE,
    PLG_NONE, PLG_NONE, PLG_NONE, PLG_NONE, PLG_NONE, PLG_NONE, PLG_NONE, PLG_NONE,
    PLG_NONE, PLG_NONE, PLG_NONE, PLG_NONE, PLG_NONE, PLG_NONE, PLG_NONE, PLG_NONE,
    PLG_NONE, PLG_NONE, PLG_NONE, PLG_NONE, PLG_NONE, PLG_NONE, PLG_NONE, PLG(044),
    PLG(045), PLG_NONE, PLG(047), PLG(048), PLG(049), PLG(050), PLG(051), PLG(052),
    PLG(053), PLG(054), PLG(055), PLG(056), PLG(057), PLG(058), PLG(059), PLG(060),
    PLG(061), PLG(062), PLG(063), PLG(064), PLG(065), PLG(066), PLG(067), PLG(068),
    PLG(069), PLG(070), PLG(071), PLG(072), PLG(073), PLG(074), PLG(075), PLG(076),
    PLG(077), PLG(078), PLG(079), PLG(080), PLG(081), PLG(082), PLG(083), PLG(084),
    PLG(085), PLG(086), PLG(087), PLG_NONE, PLG_NONE, PLG_NONE, PLG_NONE, PLG_NONE,
    PLG_NONE, PLG_NONE, PLG_NONE, PLG_NONE, PLG_NONE, PLG_NONE, PLG_NONE, PLG_NONE,
    PLG_NONE, PLG(102), PLG_NONE, PLG_NONE, PLG_NONE, PLG_NONE, PLG_NONE, PLG_NONE,
    PLG_NONE, PLG_NONE, PLG_NONE, PLG_NONE, PLG_NONE, PLG(114), PLG_NONE, PLG_NONE,
    PLG_NONE, PLG_NONE, PLG_NONE, PLG_NONE, PLG_NONE, PLG_NONE, PLG_NONE, PLG_NONE,
    PLG_NONE, PLG_NONE, PLG_NONE, PLG(128), PLG(129), PLG_NONE, PLG(131), PLG_NONE,
    PLG(133), PLG(134), PLG(135), PLG(136), PLG(137), PLG(138), PLG(139), PLG(140),
    PLG(141), PLG(142), PLG(143), PLG(144), PLG(145), PLG(146), PLG(147), PLG(148),
    PLG(149), PLG(150), PLG(151), PLG(152), PLG(153), PLG(154), PLG(155), PLG(156),
    PLG(157), PLG(158), PLG(159), PLG(160), PLG(161), PLG(162), PLG_NONE, PLG(164),
    PLG(165), PLG(166), PLG(167), PLG(168), PLG(169), PLG(170), PLG_NONE, PLG_NONE,
    PLG_NONE, PLG_NONE, PLG_NONE, PLG_NONE, PLG_NONE, PLG_NONE, PLG_NONE, PLG_NONE,
    PLG_NONE, PLG_NONE, PLG_NONE, PLG_NONE, PLG_NONE, PLG_NONE, PLG_NONE, PLG_NONE,
    PLG_NONE, PLG_NONE, PLG_NONE, PLG_NONE, PLG_NONE, PLG_NONE, PLG_NONE, PLG_NONE,
    PLG_NONE, PLG(198), PLG(199), PLG_NONE, PLG_NONE, PLG_NONE, PLG_NONE, PLG_NONE,
    PLG_NONE, PLG_NONE, PLG_NONE, PLG_NONE, PLG_NONE, PLG_NONE, PLG_NONE, PLG_NONE,
    PLG_NONE, PLG_NONE, PLG_NONE, PLG_NONE, PLG_NONE, PLG_NONE, PLG_NONE, PLG_NONE,
    PLG(221), PLG_NONE, PLG_NONE, PLG(224), PLG_NONE, PLG_NONE, PLG_NONE, PLG_NONE,
    PLG_NONE, PLG_NONE, PLG_NONE, PLG(232), PLG_NONE, PLG_NONE, PLG_NONE, PLG(236),
    PLG_NONE, PLG_NONE, PLG_NONE, PLG(240), PLG(241), PLG(242), PLG(243), PLG_NONE,
    PLG(245), PLG(246), PLG(247), PLG(248), PLG_NONE, PLG(250), PLG(251), PLG_NONE,
    PLG_NONE, PLG_NONE, PLG(255), PLG_NONE, PLG_NONE, PLG(258), PLG(259), PLG(260),
    PLG_NONE, PLG_NONE, PLG(263), PLG_NONE, PLG(265), PLG(266), PLG_NONE, PLG_NONE,
    PLG(269), PLG_NONE, PLG(271), PLG(272), PLG(273), PLG_NONE, PLG_NONE, PLG_NONE,
    PLG_NONE, PLG_NONE, PLG_NONE, PLG(280), PLG_NONE, PLG_NONE, PLG_NONE, PLG_NONE,
    PLG_NONE, PLG_NONE, PLG_NONE, PLG_NONE, PLG_NONE, PLG(290), PLG(291), PLG_NONE,
    PLG_NONE, PLG_NONE, PLG_NONE, PLG_NONE, PLG(297), PLG_NONE, PLG_NONE, PLG(300),
    PLG(301) };

/**
 * Invokes all effect entry points.
 * Probably a dev artifact, calling this in-game will presumably crash.
 */
int func_800F9800(func_800D4910_t* arg0, u_int arg1, int arg2) __attribute__((unused));
int func_800F9800(func_800D4910_t* arg0, u_int arg1, int arg2)
{
    func_800F9818(NULL, 2, 0);
    func_800F9800(NULL, 2, 0);
    func_800FB320(NULL, 2, 0);
    func_800F9800(NULL, 2, 0);
    func_800F9800(NULL, 2, 0);
    func_800FB4C0(NULL, 2, 0);
    func_800FBA00(NULL, 2, 0);
    func_800FC624(NULL, 2, 0);
    func_800FD51C(NULL, 2, 0);
    func_800F98E0(NULL, 2, 0);
    func_800FC0E4(NULL, 2, 0);
    func_800F9800(NULL, 2, 0);
    func_800F9800(NULL, 2, 0);
    func_800F9818(NULL, 2, 0);
    func_800FA368(NULL, 2, 0);
    func_800F9818(NULL, 2, 0);
    func_800FA368(NULL, 2, 0);
    func_800F9818(NULL, 2, 0);
    func_800FA368(NULL, 2, 0);
    func_800F9818(NULL, 2, 0);
    func_800FA368(NULL, 2, 0);
    func_800FB4E0(NULL, 2, 0);
    func_800FD354(NULL, 2, 0);
    func_800FF46C(NULL, 2, 0);
    func_800FB4E0(NULL, 2, 0);
    func_800FD354(NULL, 2, 0);
    func_800FF46C(NULL, 2, 0);
    func_800FB4E0(NULL, 2, 0);
    func_800FD354(NULL, 2, 0);
    func_800FF46C(NULL, 2, 0);
    func_800FB4E0(NULL, 2, 0);
    func_800FD354(NULL, 2, 0);
    func_800FF46C(NULL, 2, 0);
    func_800F9818(NULL, 2, 0);
    func_800FA3B0(NULL, 2, 0);
    func_800FAF00(NULL, 2, 0);
    func_800FBB24(NULL, 2, 0);
    func_800F9818(NULL, 2, 0);
    func_800FA3B0(NULL, 2, 0);
    func_800FAF00(NULL, 2, 0);
    func_800FBB24(NULL, 2, 0);
    func_800F9818(NULL, 2, 0);
    func_800FA3B0(NULL, 2, 0);
    func_800FAF00(NULL, 2, 0);
    func_800FBB24(NULL, 2, 0);
    func_800F9818(NULL, 2, 0);
    func_800FA3B0(NULL, 2, 0);
    func_800FAF00(NULL, 2, 0);
    func_800FBB24(NULL, 2, 0);
    func_800F98F8(NULL, 2, 0);
    func_800FA7B0(NULL, 2, 0);
    func_800FB71C(NULL, 2, 0);
    func_800FD6C0(NULL, 2, 0);
    func_800F98F8(NULL, 2, 0);
    func_800FA7B0(NULL, 2, 0);
    func_800FB71C(NULL, 2, 0);
    func_800FD6C0(NULL, 2, 0);
    func_800F98F8(NULL, 2, 0);
    func_800FA7B0(NULL, 2, 0);
    func_800FB71C(NULL, 2, 0);
    func_800FD6C0(NULL, 2, 0);
    func_800F98F8(NULL, 2, 0);
    func_800FA7B0(NULL, 2, 0);
    func_800FB71C(NULL, 2, 0);
    func_800FD6C0(NULL, 2, 0);
    func_800F98E0(NULL, 2, 0);
    func_800FBFCC(NULL, 2, 0);
    func_800FC50C(NULL, 2, 0);
    func_800F98E0(NULL, 2, 0);
    func_800FBFCC(NULL, 2, 0);
    func_800FC50C(NULL, 2, 0);
    func_800F98E0(NULL, 2, 0);
    func_800FBFCC(NULL, 2, 0);
    func_800FC50C(NULL, 2, 0);
    func_800F98E0(NULL, 2, 0);
    func_800FBFCC(NULL, 2, 0);
    func_800FC50C(NULL, 2, 0);
    func_800F98F8(NULL, 2, 0);
    func_800FA7F0(NULL, 2, 0);
    func_800FCFEC(NULL, 2, 0);
    func_800FD534(NULL, 2, 0);
    func_800FE3EC(NULL, 2, 0);
    func_800F98F8(NULL, 2, 0);
    func_800FA7F0(NULL, 2, 0);
    func_800FCFEC(NULL, 2, 0);
    func_800FD534(NULL, 2, 0);
    func_800FE3EC(NULL, 2, 0);
    func_800F98F8(NULL, 2, 0);
    func_800FA7F0(NULL, 2, 0);
    func_800FCFEC(NULL, 2, 0);
    func_800FD534(NULL, 2, 0);
    func_800FE3EC(NULL, 2, 0);
    func_800F98F8(NULL, 2, 0);
    func_800FA7F0(NULL, 2, 0);
    func_800FCFEC(NULL, 2, 0);
    func_800FD534(NULL, 2, 0);
    func_800FE3EC(NULL, 2, 0);
    func_800F9818(NULL, 2, 0);
    func_800FA324(NULL, 2, 0);
    func_800FB294(NULL, 2, 0);
    func_800FBDE4(NULL, 2, 0);
    func_800FC97C(NULL, 2, 0);
    func_800F9818(NULL, 2, 0);
    func_800FA324(NULL, 2, 0);
    func_800FB294(NULL, 2, 0);
    func_800FBDE4(NULL, 2, 0);
    func_800FC97C(NULL, 2, 0);
    func_800F9818(NULL, 2, 0);
    func_800FA324(NULL, 2, 0);
    func_800FB294(NULL, 2, 0);
    func_800FBDE4(NULL, 2, 0);
    func_800FC97C(NULL, 2, 0);
    func_800F9818(NULL, 2, 0);
    func_800FA324(NULL, 2, 0);
    func_800FB294(NULL, 2, 0);
    func_800FBDE4(NULL, 2, 0);
    func_800FC97C(NULL, 2, 0);
    func_800F9800(NULL, 2, 0);
    func_800FA6B8(NULL, 2, 0);
    func_800FB2DC(NULL, 2, 0);
    func_800FB338(NULL, 2, 0);
    func_800FB5CC(NULL, 2, 0);
    func_800FC11C(NULL, 2, 0);
    func_800F9800(NULL, 2, 0);
    func_800F9818(NULL, 2, 0);
    func_800FA368(NULL, 2, 0);
    func_800F9818(NULL, 2, 0);
    func_800FA368(NULL, 2, 0);
    func_800F98F8(NULL, 2, 0);
    func_800FA868(NULL, 2, 0);
    func_800FB720(NULL, 2, 0);
    func_800FDE48(NULL, 2, 0);
    func_800F99F0(NULL, 2, 0);
    func_800FA588(NULL, 2, 0);
    func_800FB4F8(NULL, 2, 0);
    func_800FDC20(NULL, 2, 0);
    func_800FF4E8(NULL, 2, 0);
    func_800FB320(NULL, 2, 0);
    func_800FB418(NULL, 2, 0);
    func_800FCA2C(NULL, 2, 0);
    func_800F98F8(NULL, 2, 0);
    func_800FA490(NULL, 2, 0);
    func_800FB400(NULL, 2, 0);
    func_800FC2BC(NULL, 2, 0);
    func_800FCE0C(NULL, 2, 0);
    func_800FDEC4(NULL, 2, 0);
    func_800FFFA8(NULL, 2, 0);
    func_800F9800(NULL, 2, 0);
    func_800FA424(NULL, 2, 0);
    func_800FAF30(NULL, 2, 0);
    func_800FBAC8(NULL, 2, 0);
    func_800FC6EC(NULL, 2, 0);
    func_800F9800(NULL, 2, 0);
    func_800F9800(NULL, 2, 0);
    func_800FB4B8(NULL, 2, 0);
    func_800FBA00(NULL, 2, 0);
    func_800F98E0(NULL, 2, 0);
    func_800FC42C(NULL, 2, 0);
    func_800F9818(NULL, 2, 0);
    func_800FA368(NULL, 2, 0);
    func_800F98F8(NULL, 2, 0);
    func_800FBFDC(NULL, 2, 0);
    func_800FC524(NULL, 2, 0);
    func_800FD074(NULL, 2, 0);
    func_800F9818(NULL, 2, 0);
    func_800FA6D0(NULL, 2, 0);
    func_800FB2F4(NULL, 2, 0);
    func_800FBE44(NULL, 2, 0);
    func_800F9818(NULL, 2, 0);
    func_800FA710(NULL, 2, 0);
    func_800FB320(NULL, 2, 0);
    func_800FB4B8(NULL, 2, 0);
    func_800F9818(NULL, 2, 0);
    func_800FA368(NULL, 2, 0);
    func_800FB2D8(NULL, 2, 0);
    func_800FBEFC(NULL, 2, 0);
    func_800F9800(NULL, 2, 0);
    func_800FA6F8(NULL, 2, 0);
    func_800F9800(NULL, 2, 0);
    func_800F9800(NULL, 2, 0);
    func_800F99D8(NULL, 2, 0);
    func_800FA8D0(NULL, 2, 0);
    func_800FC8C4(NULL, 2, 0);
    func_800FCB38(NULL, 2, 0);
    func_800FF334(NULL, 2, 0);
    func_800F98F8(NULL, 2, 0);
    func_800FB89C(NULL, 2, 0);
    func_800FB4B8(NULL, 2, 0);
    func_800FBA00(NULL, 2, 0);
    func_800F9800(NULL, 2, 0);
    func_800F9818(NULL, 2, 0);
    func_800FA710(NULL, 2, 0);
    func_800FB260(NULL, 2, 0);
    func_800FBDF8(NULL, 2, 0);
    func_800F9800(NULL, 2, 0);
    func_800F9928(NULL, 2, 0);
    func_800FBE88(NULL, 2, 0);
    func_800FC11C(NULL, 2, 0);
    func_800F9910(NULL, 2, 0);
    func_800FA41C(NULL, 2, 0);
    func_800FCA50(NULL, 2, 0);
    func_800F9800(NULL, 2, 0);
    func_800FA30C(NULL, 2, 0);
    func_800F9818(NULL, 2, 0);
    func_800FA710(NULL, 2, 0);
    func_800FB338(NULL, 2, 0);
    func_800FB5CC(NULL, 2, 0);
    func_800F9800(NULL, 2, 0);
    func_800F9800(NULL, 2, 0);
    func_800FA398(NULL, 2, 0);
    func_800FB00C(NULL, 2, 0);
    func_800FBF7C(NULL, 2, 0);
    func_800F9818(NULL, 2, 0);
    func_800FA710(NULL, 2, 0);
    func_800F9800(NULL, 2, 0);
    func_800FA6F8(NULL, 2, 0);
    func_800F98F8(NULL, 2, 0);
    func_800FA7B0(NULL, 2, 0);
    func_800FCFB4(NULL, 2, 0);
    func_800FD4F4(NULL, 2, 0);
    func_800FE044(NULL, 2, 0);
    func_800F9800(NULL, 2, 0);
    func_800FA740(NULL, 2, 0);
    func_800FB5F8(NULL, 2, 0);
    func_800FC21C(NULL, 2, 0);
    func_800FB320(NULL, 2, 0);
    func_800FB4D8(NULL, 2, 0);
    func_800FBA18(NULL, 2, 0);
    func_800FC8D0(NULL, 2, 0);
    func_800FD420(NULL, 2, 0);
    func_800F9800(NULL, 2, 0);
    func_800FA6B8(NULL, 2, 0);
    func_800FB32C(NULL, 2, 0);
    func_800FC29C(NULL, 2, 0);
    func_800F98E0(NULL, 2, 0);
    func_800FA84C(NULL, 2, 0);
    func_800FD2E4(NULL, 2, 0);
    func_800FB5D0(NULL, 2, 0);
    func_800FCE90(NULL, 2, 0);
    func_800FD104(NULL, 2, 0);
    func_800FB4C0(NULL, 2, 0);
    func_800FBA00(NULL, 2, 0);
    func_800FC624(NULL, 2, 0);
    func_800F9818(NULL, 2, 0);
    func_800FA48C(NULL, 2, 0);
    func_800FB348(NULL, 2, 0);
    func_800FBF6C(NULL, 2, 0);
    func_800FCABC(NULL, 2, 0);
    func_800FD654(NULL, 2, 0);
    func_800F9800(NULL, 2, 0);
    func_800F9800(NULL, 2, 0);
    func_800F9818(NULL, 2, 0);
    func_800FA710(NULL, 2, 0);
    func_800FAC78(NULL, 2, 0);
    func_800FB4C0(NULL, 2, 0);
    func_800F9800(NULL, 2, 0);
    func_800FA770(NULL, 2, 0);
    func_800FB62C(NULL, 2, 0);
    func_800FC56C(NULL, 2, 0);
    func_800FAC78(NULL, 2, 0);
    func_800FAC78(NULL, 2, 0);
    func_800F98F8(NULL, 2, 0);
    func_800FA7F0(NULL, 2, 0);
    func_800FCF18(NULL, 2, 0);
    func_800FB4B8(NULL, 2, 0);
    func_800F9800(NULL, 2, 0);
    func_800F9800(NULL, 2, 0);
    func_800F9800(NULL, 2, 0);
    func_800FA6B8(NULL, 2, 0);
    func_800FB2DC(NULL, 2, 0);
    func_800F9800(NULL, 2, 0);
    func_800F9800(NULL, 2, 0);
    func_800FA6BC(NULL, 2, 0);
    func_800F9800(NULL, 2, 0);
    func_800FB5B0(NULL, 2, 0);
    func_800FCE78(NULL, 2, 0);
    func_800F9800(NULL, 2, 0);
    func_800F9800(NULL, 2, 0);
    func_800F9800(NULL, 2, 0);
    func_800F9910(NULL, 2, 0);
    func_800FA4A8(NULL, 2, 0);
    func_800FB0CC(NULL, 2, 0);
    func_800FDA1C(NULL, 2, 0);
    func_800F9AE8(NULL, 2, 0);
    func_800FBD60(NULL, 2, 0);
    func_800FDBAC(NULL, 2, 0);
    func_800FFB04(NULL, 2, 0);
    func_800FB4F8(NULL, 2, 0);
    func_800FCB0C(NULL, 2, 0);
    func_800FE958(NULL, 2, 0);
    func_800FB4B8(NULL, 2, 0);
    func_800FB5B0(NULL, 2, 0);
    func_800FCE78(NULL, 2, 0);
    func_800F9818(NULL, 2, 0);
    func_800FA368(NULL, 2, 0);
    func_800FB2D8(NULL, 2, 0);
    func_800F9800(NULL, 2, 0);
    func_800FB338(NULL, 2, 0);
    func_800FB5CC(NULL, 2, 0);
    func_800FC11C(NULL, 2, 0);
    func_800FB320(NULL, 2, 0);
    func_800FB4D0(NULL, 2, 0);
    func_800FBA18(NULL, 2, 0);
    func_800FC568(NULL, 2, 0);
    func_800F9818(NULL, 2, 0);
    func_800FA48C(NULL, 2, 0);
    func_800FB3FC(NULL, 2, 0);
    func_800FBF4C(NULL, 2, 0);
    func_800F9910(NULL, 2, 0);
    func_800FBF94(NULL, 2, 0);
    func_800FC228(NULL, 2, 0);
    func_800FD198(NULL, 2, 0);
    func_800FB320(NULL, 2, 0);
    return func_800FB5B4(NULL, 2, 0);
}

static void _configureFb(void);
static void _configurePlg(void);

void vs_effpurge_exec(void)
{
    func_800D8038(0);
    _configureFb();
    _configurePlg();
    vs_battle_pFileLoadContext = _pFiles[D_800F5230.effectId];
    func_800D2698(255);
    D_800F569C->block9Data = NULL;
    D_800F56C8.block4Data = NULL;
    D_800F56C8.unkC0 = NULL;
    D_800F56C8.unkC4 = 0;
    D_800F56C8.unkC8 = 0;
}

static void _configureFb(void)
{
    int i;
    int texCount;
    u_char* a2;

    int new_var = D_800FAE4C[D_800F5230.effectId];
    int var_s2 = 0;

    for (i = 0; i < D_800F5230.effectId; ++i) {
        var_s2 += _fbtCounts[i];
    }

    texCount = _fbtCounts[D_800F5230.effectId];

    func_800D7FFC(texCount + (new_var != 0));

    a2 = &_fbcSlots[D_800F5230.effectId];

    vs_battle_configureEffectFbLoad(_fbcFiles[D_800F5230.effectId].lba,
        _fbcFiles[D_800F5230.effectId].size, *a2, 1, 0);

    for (i = 0; i < texCount; ++i) {
        vs_battle_configureEffectFbLoad(_fbtFiles[var_s2 + i].lba,
            _fbtFiles[var_s2 + i].size, _fbtSlots[var_s2 + i], 0, i + 1);
    }
}

static void _configurePlg(void)
{
    int i;
    int firstindex = _effectEntryPointIndices[D_800F5230.effectId];
    int count = _effectEntryPointIndices[D_800F5230.effectId + 1] - firstindex;

    vs_battle_configurePlg(
        _plgFiles[D_800F5230.effectId].lba, _plgFiles[D_800F5230.effectId].size, count);

    for (i = 0; i < count; ++i) {
        vs_battle_setEffectExec(_effectEntryPoints[firstindex + i], i);
    }

    if (count != 0) {
        vs_battle_setPlgLoadState(1);
    } else {
        vs_battle_setPlgLoadState(0);
    }
}
