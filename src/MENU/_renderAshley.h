#include "src/BATTLE/BATTLE.PRG/146C.h"
#include "src/BATTLE/BATTLE.PRG/5BF94.h"
#include "src/MENU/MAINMENU.PRG/224.h"
#include "src/MENU/MAINMENU.PRG/2D10.h"
#include <libgpu.h>

extern int _ashleyYOffset;
extern int _ashleyRenderState;
extern void* D_1F800000[];

enum ashleyRenderMode {
    ashleyRenderModeRender,
    ashleyRenderModeInit,
    ashleyRenderModeRestore
};

/**
 * Responsible for rendering 3D model.
 *
 * @param mode
 * - ashleyRenderModeInit Called when entering menu
 *
 * - ashleyRenderModeRender Called each frame while in menu
 *
 * - ashleyRenderModeRestore Called when leaving menu
 */
static void _renderAshley(int mode)
{
    static int render = 0;
    static char skipFrame = 0;

    static int projectionDistance;
#ifdef _ITEMMENU
    static int _[3] __attribute__((unused));
#else
    static int _ __attribute__((unused));
#endif
    static MATRIX viewMatrixBackup;
    static camera_t2 cameraBackup;

    int yOffset;
    camera_t2* camera = &((camera_t*)&D_1F800000)->t2;

    switch (mode) {
    case ashleyRenderModeRender:
        yOffset = _ashleyYOffset;

        switch (_ashleyRenderState) {
        case 0:
            if (yOffset < 10) {
                _ashleyYOffset = ++yOffset;
            }

            yOffset = 128 - vs_battle_rowAnimationSteps[10 - yOffset];
            break;

        case 1:
            if (yOffset > 0) {
                _ashleyYOffset = --yOffset;
            }

            yOffset = vs_battle_rowAnimationSteps[yOffset];
            break;

        case 2:
            if (yOffset < 10) {
                _ashleyYOffset = ++yOffset;
            } else {
                _ashleyRenderState = 0;
            }

            yOffset = vs_battle_rowAnimationSteps[10 - yOffset] + 128;
            break;

        case 3:
            if (yOffset > 0) {
                _ashleyYOffset = --yOffset;
            }

            yOffset = 608 - yOffset * 48;
            break;
        }

        if (skipFrame != 0) {
            skipFrame = 0;
            return;
        }

        if (render != 0) {
            int scaledDistance;
            int offsetX;
            int offsetZ;
            int cameraDistance = D_800F4538[1]->cameraDistance;

            setVector(&camera->lookAt, ((-rsin(0xB00) * yOffset) >> 8) * cameraDistance,
                -(D_800F4538[1]->cameraHeightOffset << 0xB),
                ((rcos(0xB00) * yOffset) >> 8) * cameraDistance);

            scaledDistance = cameraDistance * 4;
            offsetX = rcos(0xB00) * scaledDistance;

            camera->position.vx = camera->lookAt.vx + offsetX;
            camera->position.vy = camera->lookAt.vy;

            offsetZ = rsin(0xB00) * scaledDistance;

            setVector(&camera->angles, 0, 0, 0);
            camera->farClip = 0x1000;
            camera->position.vz = camera->lookAt.vz + offsetZ;

            func_8007ACB0();
            func_800F9EB8(&D_1F800000[5]);
        }
        break;

    case ashleyRenderModeInit:
        if (render == 0) {
            _ashleyYOffset = 0;
            _ashleyRenderState = 2;
            skipFrame = 1;
            render = 1;
            projectionDistance = vs_main_projectionDistance;

            vs_battle_setProjectionDistance(512);

            viewMatrixBackup = ((camera_t*)((void*)camera - 0x34))->viewMatrix;
            cameraBackup = *camera;
            setVector(&camera->angles, 0, 0, 0);
            camera->farClip = 0x1000;

            func_8007ACB0();
            vs_mainMenu_setBackgroundRenderPriority(2046, 128);
            func_800F9A24(0);
        }
        break;

    case ashleyRenderModeRestore:
        if (render != 0) {

            func_800F9E0C();
            vs_mainMenu_setBackgroundRenderPriority(-4, 128);
            vs_battle_setProjectionDistance(projectionDistance);

            ((camera_t*)((void*)camera - 0x34))->viewMatrix = viewMatrixBackup;
            *camera = cameraBackup;
            render = 0;
        }

        break;
    }
}
