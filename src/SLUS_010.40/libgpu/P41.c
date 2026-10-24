#include "common.h"
#include <libgte.h>
#include <libgpu.h>

void SetDrawMode(DR_MODE* p, int dfe, int dtd, int tpage, RECT* tw)
{
    setlen(p, 2);
    p->code[0] = _get_mode(dfe, dtd, tpage);
    p->code[1] = _get_tw(tw);
}
