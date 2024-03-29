#ifndef LIP_LOAD_EXT_H
#define LIP_LOAD_EXT_H

#include "first_byte.h"
#include "load_number.h"
#include "number.h"

unsigned lip_load_fixext(unsigned char const buf[], uint8_t *type)
{
    *type = __lip_load_num8(buf).u;
    return 1;
}

unsigned lip_load_ext8(unsigned char const buf[], unsigned *size, uint8_t *type)
{
    *size = __lip_load_num8(buf).u;
    *type = __lip_load_num8(buf + 1).u;
    return 2;
}

unsigned lip_load_ext16(unsigned char const buf[], unsigned *size,
                        uint8_t *type)
{
    *size = __lip_load_num16(buf).u;
    *type = __lip_load_num8(buf + 2).u;
    return 3;
}

unsigned lip_load_ext32(unsigned char const buf[], unsigned *size,
                        uint8_t *type)
{
    *size = __lip_load_num32(buf).u;
    *type = __lip_load_num8(buf + 4).u;
    return 5;
}

#endif
