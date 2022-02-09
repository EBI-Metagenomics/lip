#ifndef LIP_PACK_FLOAT_H
#define LIP_PACK_FLOAT_H

#include "store_float.h"

#define __lip_pack_float(buf, val)                                             \
    _Generic((val), float : __lip_pack_f32, double : __lip_pack_f64)(buf, val)

static inline unsigned long __lip_pack_f32(uint8_t buf[static 5], float val)
{
    return __lip_store_f32(buf, val);
}

static inline unsigned long __lip_pack_f64(uint8_t buf[static 9], double val)
{
    return __lip_store_f64(buf, val);
}

#endif
