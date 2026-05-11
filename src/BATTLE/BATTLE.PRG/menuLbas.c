#include "build/src/include/lbas.h"
#include "lbaMacros.h"

// MENUBG must immediately follow MAINMENU on the disk
int _menuLbas[] = { squashLba(VS_MAINMENU_PRG) + (VS_MENUBG_BIN_SIZE >> 11),
    squashLba(VS_MENU0_PRG), squashLba(VS_MENU1_PRG), squashLba(VS_MENU2_PRG),
    squashLba(VS_MENU3_PRG), squashLba(VS_MENU4_PRG), squashLba(VS_MENU5_PRG),
    squashLba(VS_MENU7_PRG), squashLba(VS_MENU8_PRG), squashLba(VS_MENU9_PRG),
    squashLba(VS_MENUE_PRG), squashLbaVal(VS_MENUA_PRG_LBA, 0), squashLba(VS_MENUB_PRG),
    squashLba(VS_MENUC_PRG), squashLba(VS_MENUD_PRG), squashLba(VS_MENUF_PRG) };