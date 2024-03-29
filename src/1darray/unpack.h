#ifndef _1DARRAY_UNPACK_H
#define _1DARRAY_UNPACK_H

#include "1darray/item_size.h"
#include "lip/1darray/type.h"
#include "lip/unpack_ext.h"

static inline unsigned unpack_1darray_size_type(unsigned char buf[],
                                                unsigned *size,
                                                enum lip_1darray_type *type)
{
    uint8_t typ = 0;
    unsigned sz = lip_unpack_ext_size_type(buf, size, &typ);
    if (typ > LIP_1DARRAY_F64) return 0;
    *type = typ;
    if (*size % _1darray_item_size(*type)) return 0;
    *size /= _1darray_item_size(*type);
    return sz;
}

#endif
