#include "lip/format.h"
#include "load_number.h"
#include "number.h"
#include <string.h>

unsigned lip_load_f32(unsigned char const buf[], float *val)
{
    *val = __lip_load_num32(buf).f;
    return 4;
}

unsigned lip_load_f32_in(unsigned char buf[])
{
    union __lip_num32 num = __lip_load_num32(buf);
    memcpy(buf, num.c, 4);
    return 4;
}

unsigned lip_load_f64(unsigned char const buf[], double *val)
{
    *val = __lip_load_num64(buf).f;
    return 8;
}

unsigned lip_load_f64_in(unsigned char buf[])
{
    union __lip_num64 num = __lip_load_num64(buf);
    memcpy(buf, num.c, 8);
    return 8;
}
