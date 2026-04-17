#include "common.h"
#include "../../SLUS_010.40/main.h"
#include "../BATTLE.PRG/4A0A8.h"
#include "../BATTLE.PRG/573B8.h"

static int (*D_800FAF7C[])(u_char*, short) = { _invalidOpcode, _invalidOpcode,
    _invalidOpcode, _invalidOpcode, _invalidOpcode, _invalidOpcode, _invalidOpcode,
    _invalidOpcode, _invalidOpcode, _invalidOpcode, func_800B66F4, _invalidOpcode,
    func_800B6724, func_800B6744, func_800B6868, func_800B68C4, func_800B66E4,
    func_800B66E4, func_800B6B74, func_800B66E4, func_800B66EC, func_800B66EC,
    vs_battle_script_loadGim, func_800B7014, func_800B70E8, func_800B71C4, func_800B66EC,
    vs_battle_script_setStringContextInt, _invalidOpcode, func_800B7358, func_800B7428,
    func_800B7490, func_800B7574, func_800B75F4, func_800B66E4, func_800B770C,
    func_800B77DC, func_800B784C, func_800B792C, func_800B7A98, func_800B7B58,
    func_800B7C90, func_800B7D10, func_800B7DC4, func_800B7EF0, func_800B7F84,
    func_800B804C, func_800B80B4, func_800B66EC, func_800B81A0, func_800B66E4,
    func_800B8290, func_800B8360, func_800B66E4, func_800B66E4, func_800B849C,
    func_800B8510, func_800B8590, func_800B860C, func_800B86E8, func_800B8708,
    func_800B8764, func_800B8788, func_800B884C, vs_battle_script_jumpFwdIfFlag,
    vs_battle_script_jumpFwdIfFlags, vs_battle_script_jumpFwd, func_800B66E4,
    func_800B66E4, vs_battle_script_jumpFwd2, vs_battle_script_setFlagImmContext,
    vs_battle_script_jumpFwdIfFlagContext, func_800B66E4, func_800B8C54,
    vs_battle_script_jumpBackIf, vs_battle_script_jumpFwd4, vs_battle_script_jumpFwd3,
    _invalidOpcode, _invalidOpcode, _invalidOpcode, vs_battle_script_setFlagImm,
    vs_battle_script_setFlag, vs_battle_script_setFlagIfItemInInventory, func_800B91C4,
    func_800B66E4, func_800B9230, vs_battle_script_setFlagIfButton, func_800B92A0,
    func_800B92D0, func_800B92F4, func_800B94D8, func_800B9564, func_800B9608,
    func_800B9670, func_800B66EC, func_800B9724, func_800B9770, func_800B979C,
    func_800B97E4, func_800B97F8, func_800B9818, func_800B983C, func_800B9860,
    func_800B988C, func_800B98C0, func_800B66E4, func_800B66E4, func_800B9AC4,
    func_800B9AE8, func_800B66E4, func_800B66EC, func_800B9C18, func_800B9C58,
    func_800B9D74, func_800B9DB4, func_800B9F28, func_800B9F4C, func_800B9F70,
    func_800B9F90, func_800B9FC0, func_800BA0E4, func_800BA194, func_800BA108,
    func_800BA218, func_800BA264, func_800BA288, func_800BA2B4, _invalidOpcode,
    func_800B66E4, func_800B66E4, func_800B66E4, func_800BA3E4, func_800BA404,
    vs_battle_script_loadSfxSlot, vs_battle_script_freeSfxSlot, vs_battle_script_freeSfx,
    vs_battle_script_setCurrentSfx, vs_battle_script_loadSoundFile, _invalidOpcode,
    _invalidOpcode, _invalidOpcode, _invalidOpcode, _invalidOpcode, func_800B66E4,
    vs_battle_script_loadMusicSlot, vs_battle_script_freeMusic, func_800B66E4,
    func_800B66E4, func_800B66E4, func_800B66E4, func_800B66E4, func_800B66E4,
    func_800B66E4, vs_battle_script_clearMusicLoadSlot, func_800B66EC, func_800B66E4,
    func_800B66E4, vs_battle_script_loadSoundFile2, vs_battle_script_processSoundQueue,
    func_800B66E4, func_800BA8BC, func_800BA90C, func_800BA94C, func_800BAA04,
    func_800BAA34, func_800BAA58, func_800BAACC, _invalidOpcode, func_800BAAF0,
    func_800B66E4, func_800BABCC, _invalidOpcode, _invalidOpcode, _invalidOpcode,
    _invalidOpcode, _invalidOpcode, _invalidOpcode, func_800BAC38, func_800BAC5C,
    func_800BAD78, _invalidOpcode, func_800BAE74, func_800BAEA0,
    vs_battle_script_specialOp, func_800BB288, func_800BD6C4, func_800BD6C4,
    func_800B66E4, func_800BB2E4, func_800BB304, func_800BB30C, func_800BD6C4,
    func_800BC2E8, func_800BC2E8, func_800BC2E8, func_800BC2E8, func_800BC2E8,
    func_800BC2E8, _invalidOpcode, func_800BC2E8, func_800BC2E8, func_800BC2E8,
    func_800BC2E8, func_800BC2E8, _invalidOpcode, _invalidOpcode, _invalidOpcode,
    _invalidOpcode, func_800BC2E8, func_800BC2E8, func_800BC2E8, func_800BC2E8,
    func_800BC2E8, func_800BC2E8, _invalidOpcode, func_800BC2E8, func_800BC2E8,
    func_800BC2E8, func_800BC2E8, func_800BC2E8, _invalidOpcode, _invalidOpcode,
    func_800BB33C, func_800BB35C, func_800B66EC, func_800BB450, func_800BD444,
    func_800BD444, func_800BD6C4, func_800BD6C4, func_800BD6C4, func_800BD6C4,
    func_800BB38C, func_800BB3BC, func_800BDC9C, func_800BDC9C, func_800BDC9C,
    func_800BD6C4, func_800BDC9C, func_800BDC9C, func_800B66EC, func_800BB4CC,
    vs_battle_script_playMenuSelectSfx, func_800BB4F0, func_800BB504, func_800BB554,
    func_800BB5A4, func_800BB5AC, _invalidOpcode, _invalidOpcode, _invalidOpcode,
    _invalidOpcode, _invalidOpcode, _invalidOpcode, func_800BB604, func_800BB604 };

void _initScriptFunctionTable(void)
{
    D_800F4C08 = 0;
    D_800F4BE2 = 0;
    D_800F4C30 = vs_main_allocHeap(0x1800);
    D_800F4C48 = vs_main_allocHeap(0x80);
    D_800F4C28 = vs_main_allocHeap(0x400);
    vs_main_memcpy(D_800F4C28, D_800FAF7C, 0x400);
}
