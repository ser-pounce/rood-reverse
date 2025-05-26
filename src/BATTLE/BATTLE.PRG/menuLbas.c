#include "lbas.h"
#include "lbaMacros.h"

int _menuLbas[] = { VS_MAINMENU_PRG_LBA << 8 | (VS_MAINMENU_PRG_SIZE >> 11) + 12, // Wat
    squashLba(VS_MENU0_PRG), squashLba(VS_MENU1_PRG), squashLba(VS_MENU2_PRG),
    squashLba(VS_MENU3_PRG), squashLba(VS_MENU4_PRG), squashLba(VS_MENU5_PRG),
    squashLba(VS_MENU7_PRG), squashLba(VS_MENU8_PRG), squashLba(VS_MENU9_PRG),
    squashLba(VS_MENUE_PRG), squashLba(VS_MENUA_PRG), squashLba(VS_MENUB_PRG),
    squashLba(VS_MENUC_PRG), squashLba(VS_MENUD_PRG), squashLba(VS_MENUF_PRG) };