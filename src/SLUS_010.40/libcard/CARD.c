#include "common.h"
#include <libapi.h>

long _card_clear(long chan)
{
    _new_card();
    return _card_write(chan, 0x3F, NULL);
}
