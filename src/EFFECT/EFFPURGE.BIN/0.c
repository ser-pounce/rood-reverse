#include "common.h"
#include "src/BATTLE/BATTLE.PRG/5BF94.h"
#include "src/BATTLE/BATTLE.PRG/6E644.h"
#include "build/src/include/lbas.h"

void func_800F9818(int, int, int);
void func_800F98E0(int, int, int);
void func_800F98F8(int, int, int);
void func_800F9910(int, int, int);
void func_800F9928(int, int, int);
void func_800F99D8(int, int, int);
void func_800F99F0(int, int, int);
void func_800F9AE8(int, int, int);
void func_800FA30C(int, int, int);
void func_800FA324(int, int, int);
void func_800FA368(int, int, int);
void func_800FA398(int, int, int);
void func_800FA3B0(int, int, int);
void func_800FA41C(int, int, int);
void func_800FA424(int, int, int);
void func_800FA48C(int, int, int);
void func_800FA490(int, int, int);
void func_800FA4A8(int, int, int);
void func_800FA588(int, int, int);
void func_800FA6B8(int, int, int);
void func_800FA6BC(int, int, int);
void func_800FA6D0(int, int, int);
void func_800FA6F8(int, int, int);
void func_800FA710(int, int, int);
void func_800FA740(int, int, int);
void func_800FA770(int, int, int);
void func_800FA7B0(int, int, int);
void func_800FA7F0(int, int, int);
void func_800FA84C(int, int, int);
void func_800FA868(int, int, int);
void func_800FA8D0(int, int, int);
void func_800FAC4C(void);
void func_800FAD7C(void);
void func_800FAC78(int, int, int);
void func_800FAF00(int, int, int);
void func_800FAF30(int, int, int);
void func_800FB00C(int, int, int);
void func_800FB0CC(int, int, int);
void func_800FB260(int, int, int);
void func_800FB294(int, int, int);
void func_800FB2D8(int, int, int);
void func_800FB2DC(int, int, int);
void func_800FB2F4(int, int, int);
void func_800FB320(int, int, int);
void func_800FB32C(int, int, int);
void func_800FB338(int, int, int);
void func_800FB348(int, int, int);
void func_800FB3FC(int, int, int);
void func_800FB400(int, int, int);
void func_800FB418(int, int, int);
void func_800FB4B8(int, int, int);
void func_800FB4C0(int, int, int);
void func_800FB4D0(int, int, int);
void func_800FB4D8(int, int, int);
void func_800FB4E0(int, int, int);
void func_800FB4F8(int, int, int);
void func_800FB5B0(int, int, int);
void func_800FB5B4(int, int, int);
void func_800FB5CC(int, int, int);
void func_800FB5D0(int, int, int);
void func_800FB5F8(int, int, int);
void func_800FB62C(int, int, int);
void func_800FB71C(int, int, int);
void func_800FB720(int, int, int);
void func_800FB89C(int, int, int);
void func_800FBA00(int, int, int);
void func_800FBA18(int, int, int);
void func_800FBAC8(int, int, int);
void func_800FBB24(int, int, int);
void func_800FBD60(int, int, int);
void func_800FBDE4(int, int, int);
void func_800FBDF8(int, int, int);
void func_800FBE44(int, int, int);
void func_800FBE88(int, int, int);
void func_800FBEFC(int, int, int);
void func_800FBF4C(int, int, int);
void func_800FBF6C(int, int, int);
void func_800FBF7C(int, int, int);
void func_800FBF94(int, int, int);
void func_800FBFCC(int, int, int);
void func_800FBFDC(int, int, int);
void func_800FC0E4(int, int, int);
void func_800FC11C(int, int, int);
void func_800FC21C(int, int, int);
void func_800FC228(int, int, int);
void func_800FC29C(int, int, int);
void func_800FC2BC(int, int, int);
void func_800FC42C(int, int, int);
void func_800FC50C(int, int, int);
void func_800FC524(int, int, int);
void func_800FC568(int, int, int);
void func_800FC56C(int, int, int);
void func_800FC624(int, int, int);
void func_800FC6EC(int, int, int);
void func_800FC8C4(int, int, int);
void func_800FC8D0(int, int, int);
void func_800FC97C(int, int, int);
void func_800FCA2C(int, int, int);
void func_800FCA50(int, int, int);
void func_800FCABC(int, int, int);
void func_800FCB0C(int, int, int);
void func_800FCB38(int, int, int);
void func_800FCE0C(int, int, int);
void func_800FCE78(int, int, int);
void func_800FCE90(int, int, int);
void func_800FCF18(int, int, int);
void func_800FCFB4(int, int, int);
void func_800FCFEC(int, int, int);
void func_800FD074(int, int, int);
void func_800FD104(int, int, int);
void func_800FD198(int, int, int);
void func_800FD2E4(int, int, int);
void func_800FD354(int, int, int);
void func_800FD420(int, int, int);
void func_800FD4F4(int, int, int);
void func_800FD51C(int, int, int);
void func_800FD534(int, int, int);
void func_800FD654(int, int, int);
void func_800FD6C0(int, int, int);
void func_800FDA1C(int, int, int);
void func_800FDBAC(int, int, int);
void func_800FDC20(int, int, int);
void func_800FDE48(int, int, int);
void func_800FDEC4(int, int, int);
void func_800FE044(int, int, int);
void func_800FE3EC(int, int, int);
void func_800FE958(int, int, int);
void func_800FF334(int, int, int);
void func_800FF46C(int, int, int);
void func_800FF4E8(int, int, int);
void func_800FFB04(int, int, int);
void func_800FFFA8(int, int, int);

static u_char D_800FAE4C[] = { 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x01, 0x01, 0x01,
    0x01, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x01, 0x01,
    0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x00, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x02, 0x02, 0x01, 0x01, 0x01, 0x02, 0x02, 0x03, 0x01, 0x01, 0x01,
    0x01, 0x02, 0x02, 0x02, 0x02, 0x01, 0x01, 0x01, 0x01, 0x02, 0x02, 0x02, 0x02, 0x01,
    0x01, 0x01, 0x01, 0x03, 0x03, 0x03, 0x03, 0x01, 0x01, 0x01, 0x01, 0x03, 0x03, 0x03,
    0x03, 0x01, 0x01, 0x02, 0x01, 0x02, 0x01, 0x01, 0x02, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x03, 0x03, 0x02, 0x00, 0x02, 0x02, 0x01, 0x01, 0x02, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x02, 0x01, 0x01, 0x01, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x01, 0x01, 0x01, 0x02, 0x01,
    0x01, 0x04, 0x04, 0x03, 0x01, 0x01, 0x02, 0x03, 0x02, 0x03, 0x04, 0x03, 0x03, 0x04,
    0x04, 0x03, 0x01, 0x02, 0x01, 0x03, 0x01, 0x04, 0x02, 0x03, 0x03, 0x01, 0x01, 0x02,
    0x01, 0x02, 0x01, 0x01, 0x01, 0x01, 0x02, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x02, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x02, 0x02, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x02, 0x01, 0x01, 0x02,
    0x01, 0x02, 0x02, 0x01, 0x02, 0x02, 0x03, 0x03, 0x03, 0x03, 0x03, 0x02, 0x01, 0x01,
    0x02, 0x03, 0x01, 0x03, 0x00, 0x03, 0x03, 0x03, 0x00, 0x00, 0x02, 0x02, 0x03, 0x04,
    0x00, 0x02, 0x02, 0x02, 0x03, 0x00, 0x00, 0x03, 0x00, 0x03, 0x02, 0x02, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x02, 0x02, 0x02, 0x02, 0x01, 0x01, 0x02,
    0x01, 0x01, 0x02, 0x01, 0x01, 0x01, 0x01, 0x02, 0x01, 0x01, 0x01, 0x01, 0x02, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };

static u_char D_800FAFDC[] = { 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01 };

#define FBC_NONE { VS_E000_0_FBC_LBA - VS_E000_P_LBA, VS_E000_0_FBC_SIZE }
#define FBC(x) { VS_E##x##_1_FBC_LBA - VS_E000_P_LBA, VS_E##x##_1_FBC_SIZE }

static _loadFileContext D_800FB16C[] = {
    { VS_E000_0_FBC_LBA - VS_E000_P_LBA, VS_E000_0_FBC_SIZE }, FBC(001), FBC(002),
    FBC(003), FBC(004), FBC(005), FBC_NONE, FBC(007), FBC(008), FBC(009), FBC(010),
    FBC_NONE, FBC_NONE, FBC(013), FBC(014), FBC(015), FBC(016), FBC(017), FBC(018),
    FBC(019), FBC(020), FBC_NONE, FBC(022), FBC(023), FBC(024), FBC_NONE, FBC(026),
    FBC(027), FBC_NONE, FBC(029), FBC(030), FBC_NONE, FBC(032), FBC_NONE, FBC(034),
    FBC(035), FBC(036), FBC(037), FBC(038), FBC(039), FBC(040), FBC(041), FBC(042),
    FBC(043), FBC(044), FBC(045), FBC(046), FBC(047), FBC(048), FBC(049), FBC(050),
    FBC(051), FBC(052), FBC(053), FBC(054), FBC(055), FBC(056), FBC(057), FBC(058),
    FBC(059), FBC(060), FBC(061), FBC(062), FBC(063), FBC(064), FBC(065), FBC(066),
    FBC(067), FBC(068), FBC(069), FBC(070), FBC(071), FBC(072), FBC(073), FBC(074),
    FBC(075), FBC(076), FBC(077), FBC(078), FBC(079), FBC(080), FBC(081), FBC(082),
    FBC(083), FBC(084), FBC(085), FBC(086), FBC(087), FBC(088), FBC(089), FBC(090),
    FBC(091), FBC(092), FBC(093), FBC(094), FBC(095), FBC(096), FBC_NONE, FBC(098),
    FBC(099), FBC(100), FBC(101), FBC(102), FBC(103), FBC(104), FBC(105), FBC(106),
    FBC(107), FBC(108), FBC(109), FBC(110), FBC(111), FBC(112), FBC_NONE, FBC(114),
    FBC(115), FBC(116), FBC(117), FBC(118), FBC(119), FBC(120), FBC(121), FBC_NONE,
    FBC_NONE, FBC(124), FBC(125), FBC(126), FBC(127), FBC(128), FBC(129), FBC_NONE,
    FBC(131), FBC(132), FBC(133), FBC(134), FBC(135), FBC(136), FBC(137), FBC(138),
    FBC(139), FBC(140), FBC(141), FBC(142), FBC(143), FBC(144), FBC(145), FBC(146),
    FBC(147), FBC(148), FBC(149), FBC(150), FBC(151), FBC(152), FBC(153), FBC(154),
    FBC(155), FBC(156), FBC(157), FBC(158), FBC(159), FBC(160), FBC(161), FBC(162),
    FBC(163), FBC(164), FBC(165), FBC(166), FBC(167), FBC(168), FBC(169), FBC(170),
    FBC(171), FBC(172), FBC(173), FBC(174), FBC(175), FBC(176), FBC(177), FBC(178),
    FBC(179), FBC(180), FBC(181), FBC(182), FBC(183), FBC(184), FBC(185), FBC(186),
    FBC(187), FBC(188), FBC(189), FBC(190), FBC(191), FBC(192), FBC(193), FBC(194),
    FBC(195), FBC(196), FBC(197), FBC(198), FBC(199), FBC(200), FBC(201), FBC(202),
    FBC(203), FBC(204), FBC(205), FBC(206), FBC(207), FBC(208), FBC(209), FBC(210),
    FBC(211), FBC(212), FBC(213), FBC(214), FBC(215), FBC(216), FBC(217), FBC(218),
    FBC(219), FBC(220), FBC(221), FBC(222), FBC(223), FBC(224), FBC(225), FBC(226),
    FBC(227), FBC(228), FBC(229), FBC(230), FBC(231), FBC(232), FBC(233), FBC(234),
    FBC(235), FBC(236), FBC(237), FBC(238), FBC(239), FBC(240), FBC(241), FBC(242),
    FBC(243), FBC(244), FBC(245), FBC(246), FBC(247), FBC(248), FBC(249), FBC(250),
    FBC(251), FBC_NONE, FBC(253), FBC(254), FBC(255), FBC_NONE, FBC_NONE, FBC(258),
    FBC(259), FBC(260), FBC(261), FBC_NONE, FBC(263), FBC(264), FBC(265), FBC(266),
    FBC_NONE, FBC_NONE, FBC(269), FBC_NONE, FBC(271), FBC(272), FBC(273), FBC_NONE,
    FBC_NONE, FBC_NONE, FBC_NONE, FBC_NONE, FBC_NONE, FBC(280), FBC(281), FBC(282),
    FBC(283), FBC(284), FBC(285), FBC(286), FBC(287), FBC(288), FBC(289), FBC(290),
    FBC(291), FBC(292), FBC(293), FBC(294), FBC(295), FBC(296), FBC(297), FBC(298),
    FBC(299), FBC(300), FBC(301), FBC(302), FBC_NONE, FBC_NONE, FBC_NONE, FBC_NONE,
    FBC_NONE, FBC_NONE, FBC_NONE, FBC_NONE, FBC_NONE, FBC_NONE, FBC_NONE, FBC_NONE,
    FBC_NONE, FBC_NONE, FBC_NONE, FBC_NONE, FBC_NONE, FBC_NONE, FBC_NONE, FBC_NONE,
    FBC_NONE, FBC_NONE, FBC_NONE, FBC_NONE, FBC_NONE, FBC_NONE, FBC_NONE, FBC_NONE,
    FBC_NONE, FBC_NONE, FBC_NONE, FBC_NONE, FBC_NONE, FBC_NONE, FBC_NONE, FBC_NONE,
    FBC_NONE, FBC_NONE, FBC_NONE, FBC_NONE, FBC_NONE, FBC_NONE, FBC_NONE, FBC_NONE,
    FBC_NONE, FBC_NONE, FBC_NONE, FBC_NONE, FBC_NONE, FBC_NONE, FBC_NONE, FBC_NONE,
    FBC_NONE, FBC_NONE, FBC_NONE, FBC_NONE, FBC_NONE, FBC_NONE, FBC_NONE, FBC_NONE,
    FBC_NONE, FBC_NONE, FBC_NONE, FBC_NONE, FBC_NONE, FBC_NONE, FBC_NONE, FBC_NONE,
    FBC_NONE, FBC_NONE, FBC_NONE, FBC_NONE, FBC_NONE, FBC_NONE, FBC_NONE, FBC_NONE,
    FBC_NONE, FBC_NONE, FBC_NONE, FBC_NONE, FBC_NONE, FBC_NONE, FBC_NONE, FBC_NONE,
    FBC_NONE, FBC_NONE, FBC_NONE, FBC_NONE, FBC_NONE, FBC_NONE, FBC_NONE, FBC_NONE,
    FBC_NONE, FBC_NONE, FBC_NONE, FBC_NONE, FBC_NONE
};
extern u_char D_800FB7AC[];
extern u_char D_800FB93C[];
extern _loadFileContext D_800FBC30[];
extern _loadFileContext D_800FC7FC[];
extern u_short D_800FCE3C[];
extern int (*D_800FD15C[])(func_800D4910_t*, int, int);
extern _loadFileContext D_800FD6B8[];

void func_800F9800(int arg0, int arg1, int arg2)
{
    func_800F9818(0, 2, 0);
    func_800F9800(0, 2, 0);
    func_800FB320(0, 2, 0);
    func_800F9800(0, 2, 0);
    func_800F9800(0, 2, 0);
    func_800FB4C0(0, 2, 0);
    func_800FBA00(0, 2, 0);
    func_800FC624(0, 2, 0);
    func_800FD51C(0, 2, 0);
    func_800F98E0(0, 2, 0);
    func_800FC0E4(0, 2, 0);
    func_800F9800(0, 2, 0);
    func_800F9800(0, 2, 0);
    func_800F9818(0, 2, 0);
    func_800FA368(0, 2, 0);
    func_800F9818(0, 2, 0);
    func_800FA368(0, 2, 0);
    func_800F9818(0, 2, 0);
    func_800FA368(0, 2, 0);
    func_800F9818(0, 2, 0);
    func_800FA368(0, 2, 0);
    func_800FB4E0(0, 2, 0);
    func_800FD354(0, 2, 0);
    func_800FF46C(0, 2, 0);
    func_800FB4E0(0, 2, 0);
    func_800FD354(0, 2, 0);
    func_800FF46C(0, 2, 0);
    func_800FB4E0(0, 2, 0);
    func_800FD354(0, 2, 0);
    func_800FF46C(0, 2, 0);
    func_800FB4E0(0, 2, 0);
    func_800FD354(0, 2, 0);
    func_800FF46C(0, 2, 0);
    func_800F9818(0, 2, 0);
    func_800FA3B0(0, 2, 0);
    func_800FAF00(0, 2, 0);
    func_800FBB24(0, 2, 0);
    func_800F9818(0, 2, 0);
    func_800FA3B0(0, 2, 0);
    func_800FAF00(0, 2, 0);
    func_800FBB24(0, 2, 0);
    func_800F9818(0, 2, 0);
    func_800FA3B0(0, 2, 0);
    func_800FAF00(0, 2, 0);
    func_800FBB24(0, 2, 0);
    func_800F9818(0, 2, 0);
    func_800FA3B0(0, 2, 0);
    func_800FAF00(0, 2, 0);
    func_800FBB24(0, 2, 0);
    func_800F98F8(0, 2, 0);
    func_800FA7B0(0, 2, 0);
    func_800FB71C(0, 2, 0);
    func_800FD6C0(0, 2, 0);
    func_800F98F8(0, 2, 0);
    func_800FA7B0(0, 2, 0);
    func_800FB71C(0, 2, 0);
    func_800FD6C0(0, 2, 0);
    func_800F98F8(0, 2, 0);
    func_800FA7B0(0, 2, 0);
    func_800FB71C(0, 2, 0);
    func_800FD6C0(0, 2, 0);
    func_800F98F8(0, 2, 0);
    func_800FA7B0(0, 2, 0);
    func_800FB71C(0, 2, 0);
    func_800FD6C0(0, 2, 0);
    func_800F98E0(0, 2, 0);
    func_800FBFCC(0, 2, 0);
    func_800FC50C(0, 2, 0);
    func_800F98E0(0, 2, 0);
    func_800FBFCC(0, 2, 0);
    func_800FC50C(0, 2, 0);
    func_800F98E0(0, 2, 0);
    func_800FBFCC(0, 2, 0);
    func_800FC50C(0, 2, 0);
    func_800F98E0(0, 2, 0);
    func_800FBFCC(0, 2, 0);
    func_800FC50C(0, 2, 0);
    func_800F98F8(0, 2, 0);
    func_800FA7F0(0, 2, 0);
    func_800FCFEC(0, 2, 0);
    func_800FD534(0, 2, 0);
    func_800FE3EC(0, 2, 0);
    func_800F98F8(0, 2, 0);
    func_800FA7F0(0, 2, 0);
    func_800FCFEC(0, 2, 0);
    func_800FD534(0, 2, 0);
    func_800FE3EC(0, 2, 0);
    func_800F98F8(0, 2, 0);
    func_800FA7F0(0, 2, 0);
    func_800FCFEC(0, 2, 0);
    func_800FD534(0, 2, 0);
    func_800FE3EC(0, 2, 0);
    func_800F98F8(0, 2, 0);
    func_800FA7F0(0, 2, 0);
    func_800FCFEC(0, 2, 0);
    func_800FD534(0, 2, 0);
    func_800FE3EC(0, 2, 0);
    func_800F9818(0, 2, 0);
    func_800FA324(0, 2, 0);
    func_800FB294(0, 2, 0);
    func_800FBDE4(0, 2, 0);
    func_800FC97C(0, 2, 0);
    func_800F9818(0, 2, 0);
    func_800FA324(0, 2, 0);
    func_800FB294(0, 2, 0);
    func_800FBDE4(0, 2, 0);
    func_800FC97C(0, 2, 0);
    func_800F9818(0, 2, 0);
    func_800FA324(0, 2, 0);
    func_800FB294(0, 2, 0);
    func_800FBDE4(0, 2, 0);
    func_800FC97C(0, 2, 0);
    func_800F9818(0, 2, 0);
    func_800FA324(0, 2, 0);
    func_800FB294(0, 2, 0);
    func_800FBDE4(0, 2, 0);
    func_800FC97C(0, 2, 0);
    func_800F9800(0, 2, 0);
    func_800FA6B8(0, 2, 0);
    func_800FB2DC(0, 2, 0);
    func_800FB338(0, 2, 0);
    func_800FB5CC(0, 2, 0);
    func_800FC11C(0, 2, 0);
    func_800F9800(0, 2, 0);
    func_800F9818(0, 2, 0);
    func_800FA368(0, 2, 0);
    func_800F9818(0, 2, 0);
    func_800FA368(0, 2, 0);
    func_800F98F8(0, 2, 0);
    func_800FA868(0, 2, 0);
    func_800FB720(0, 2, 0);
    func_800FDE48(0, 2, 0);
    func_800F99F0(0, 2, 0);
    func_800FA588(0, 2, 0);
    func_800FB4F8(0, 2, 0);
    func_800FDC20(0, 2, 0);
    func_800FF4E8(0, 2, 0);
    func_800FB320(0, 2, 0);
    func_800FB418(0, 2, 0);
    func_800FCA2C(0, 2, 0);
    func_800F98F8(0, 2, 0);
    func_800FA490(0, 2, 0);
    func_800FB400(0, 2, 0);
    func_800FC2BC(0, 2, 0);
    func_800FCE0C(0, 2, 0);
    func_800FDEC4(0, 2, 0);
    func_800FFFA8(0, 2, 0);
    func_800F9800(0, 2, 0);
    func_800FA424(0, 2, 0);
    func_800FAF30(0, 2, 0);
    func_800FBAC8(0, 2, 0);
    func_800FC6EC(0, 2, 0);
    func_800F9800(0, 2, 0);
    func_800F9800(0, 2, 0);
    func_800FB4B8(0, 2, 0);
    func_800FBA00(0, 2, 0);
    func_800F98E0(0, 2, 0);
    func_800FC42C(0, 2, 0);
    func_800F9818(0, 2, 0);
    func_800FA368(0, 2, 0);
    func_800F98F8(0, 2, 0);
    func_800FBFDC(0, 2, 0);
    func_800FC524(0, 2, 0);
    func_800FD074(0, 2, 0);
    func_800F9818(0, 2, 0);
    func_800FA6D0(0, 2, 0);
    func_800FB2F4(0, 2, 0);
    func_800FBE44(0, 2, 0);
    func_800F9818(0, 2, 0);
    func_800FA710(0, 2, 0);
    func_800FB320(0, 2, 0);
    func_800FB4B8(0, 2, 0);
    func_800F9818(0, 2, 0);
    func_800FA368(0, 2, 0);
    func_800FB2D8(0, 2, 0);
    func_800FBEFC(0, 2, 0);
    func_800F9800(0, 2, 0);
    func_800FA6F8(0, 2, 0);
    func_800F9800(0, 2, 0);
    func_800F9800(0, 2, 0);
    func_800F99D8(0, 2, 0);
    func_800FA8D0(0, 2, 0);
    func_800FC8C4(0, 2, 0);
    func_800FCB38(0, 2, 0);
    func_800FF334(0, 2, 0);
    func_800F98F8(0, 2, 0);
    func_800FB89C(0, 2, 0);
    func_800FB4B8(0, 2, 0);
    func_800FBA00(0, 2, 0);
    func_800F9800(0, 2, 0);
    func_800F9818(0, 2, 0);
    func_800FA710(0, 2, 0);
    func_800FB260(0, 2, 0);
    func_800FBDF8(0, 2, 0);
    func_800F9800(0, 2, 0);
    func_800F9928(0, 2, 0);
    func_800FBE88(0, 2, 0);
    func_800FC11C(0, 2, 0);
    func_800F9910(0, 2, 0);
    func_800FA41C(0, 2, 0);
    func_800FCA50(0, 2, 0);
    func_800F9800(0, 2, 0);
    func_800FA30C(0, 2, 0);
    func_800F9818(0, 2, 0);
    func_800FA710(0, 2, 0);
    func_800FB338(0, 2, 0);
    func_800FB5CC(0, 2, 0);
    func_800F9800(0, 2, 0);
    func_800F9800(0, 2, 0);
    func_800FA398(0, 2, 0);
    func_800FB00C(0, 2, 0);
    func_800FBF7C(0, 2, 0);
    func_800F9818(0, 2, 0);
    func_800FA710(0, 2, 0);
    func_800F9800(0, 2, 0);
    func_800FA6F8(0, 2, 0);
    func_800F98F8(0, 2, 0);
    func_800FA7B0(0, 2, 0);
    func_800FCFB4(0, 2, 0);
    func_800FD4F4(0, 2, 0);
    func_800FE044(0, 2, 0);
    func_800F9800(0, 2, 0);
    func_800FA740(0, 2, 0);
    func_800FB5F8(0, 2, 0);
    func_800FC21C(0, 2, 0);
    func_800FB320(0, 2, 0);
    func_800FB4D8(0, 2, 0);
    func_800FBA18(0, 2, 0);
    func_800FC8D0(0, 2, 0);
    func_800FD420(0, 2, 0);
    func_800F9800(0, 2, 0);
    func_800FA6B8(0, 2, 0);
    func_800FB32C(0, 2, 0);
    func_800FC29C(0, 2, 0);
    func_800F98E0(0, 2, 0);
    func_800FA84C(0, 2, 0);
    func_800FD2E4(0, 2, 0);
    func_800FB5D0(0, 2, 0);
    func_800FCE90(0, 2, 0);
    func_800FD104(0, 2, 0);
    func_800FB4C0(0, 2, 0);
    func_800FBA00(0, 2, 0);
    func_800FC624(0, 2, 0);
    func_800F9818(0, 2, 0);
    func_800FA48C(0, 2, 0);
    func_800FB348(0, 2, 0);
    func_800FBF6C(0, 2, 0);
    func_800FCABC(0, 2, 0);
    func_800FD654(0, 2, 0);
    func_800F9800(0, 2, 0);
    func_800F9800(0, 2, 0);
    func_800F9818(0, 2, 0);
    func_800FA710(0, 2, 0);
    func_800FAC78(0, 2, 0);
    func_800FB4C0(0, 2, 0);
    func_800F9800(0, 2, 0);
    func_800FA770(0, 2, 0);
    func_800FB62C(0, 2, 0);
    func_800FC56C(0, 2, 0);
    func_800FAC78(0, 2, 0);
    func_800FAC78(0, 2, 0);
    func_800F98F8(0, 2, 0);
    func_800FA7F0(0, 2, 0);
    func_800FCF18(0, 2, 0);
    func_800FB4B8(0, 2, 0);
    func_800F9800(0, 2, 0);
    func_800F9800(0, 2, 0);
    func_800F9800(0, 2, 0);
    func_800FA6B8(0, 2, 0);
    func_800FB2DC(0, 2, 0);
    func_800F9800(0, 2, 0);
    func_800F9800(0, 2, 0);
    func_800FA6BC(0, 2, 0);
    func_800F9800(0, 2, 0);
    func_800FB5B0(0, 2, 0);
    func_800FCE78(0, 2, 0);
    func_800F9800(0, 2, 0);
    func_800F9800(0, 2, 0);
    func_800F9800(0, 2, 0);
    func_800F9910(0, 2, 0);
    func_800FA4A8(0, 2, 0);
    func_800FB0CC(0, 2, 0);
    func_800FDA1C(0, 2, 0);
    func_800F9AE8(0, 2, 0);
    func_800FBD60(0, 2, 0);
    func_800FDBAC(0, 2, 0);
    func_800FFB04(0, 2, 0);
    func_800FB4F8(0, 2, 0);
    func_800FCB0C(0, 2, 0);
    func_800FE958(0, 2, 0);
    func_800FB4B8(0, 2, 0);
    func_800FB5B0(0, 2, 0);
    func_800FCE78(0, 2, 0);
    func_800F9818(0, 2, 0);
    func_800FA368(0, 2, 0);
    func_800FB2D8(0, 2, 0);
    func_800F9800(0, 2, 0);
    func_800FB338(0, 2, 0);
    func_800FB5CC(0, 2, 0);
    func_800FC11C(0, 2, 0);
    func_800FB320(0, 2, 0);
    func_800FB4D0(0, 2, 0);
    func_800FBA18(0, 2, 0);
    func_800FC568(0, 2, 0);
    func_800F9818(0, 2, 0);
    func_800FA48C(0, 2, 0);
    func_800FB3FC(0, 2, 0);
    func_800FBF4C(0, 2, 0);
    func_800F9910(0, 2, 0);
    func_800FBF94(0, 2, 0);
    func_800FC228(0, 2, 0);
    func_800FD198(0, 2, 0);
    func_800FB320(0, 2, 0);
    func_800FB5B4(0, 2, 0);
}

void func_800FABB8(void)
{
    func_800D8038(0);
    func_800FAC4C();
    func_800FAD7C();
    _loadEffContext = D_800FC7FC[D_800F5230.unk0];
    func_800D2698(0xFF);
    D_800F569C->unkB4 = 0;
    D_800F56C8.unk8C = 0;
    D_800F56C8.unkC0 = 0;
    D_800F56C8.unkC4 = 0;
    D_800F56C8.unkC8 = 0;
}

void func_800FAC4C(void)
{
    int i;
    int temp_s1;
    u_char* a2;

    int new_var = D_800FAE4C[D_800F5230.unk0];
    int var_s2 = 0;

    for (i = 0; i < D_800F5230.unk0; ++i) {
        var_s2 += D_800FB7AC[i];
    }

    temp_s1 = D_800FB7AC[D_800F5230.unk0];

    func_800D7FFC(temp_s1 + (new_var != 0));

    a2 = &D_800FAFDC[D_800F5230.unk0];

    func_800D8008(
        D_800FB16C[D_800F5230.unk0].lba, D_800FB16C[D_800F5230.unk0].size, *a2, 1, 0);

    for (i = 0; i < temp_s1; ++i) {
        func_800D8008(D_800FBC30[var_s2 + i].lba, D_800FBC30[var_s2 + i].size,
            D_800FB93C[var_s2 + i], 0, i + 1);
    }
}

void func_800FAD7C(void)
{
    int temp_s1;
    int i;
    int temp_s2;

    temp_s2 = D_800FCE3C[D_800F5230.unk0];
    temp_s1 = D_800FCE3C[D_800F5230.unk0 + 1] - temp_s2;

    func_800D7FC8(
        D_800FD6B8[D_800F5230.unk0].lba, D_800FD6B8[D_800F5230.unk0].size, temp_s1);

    for (i = 0; i < temp_s1; ++i) {
        func_800D7FE4(D_800FD15C[temp_s2 + i], i);
    }

    if (temp_s1 != 0) {
        func_800D8054(1);
    } else {
        func_800D8054(0);
    }
}
