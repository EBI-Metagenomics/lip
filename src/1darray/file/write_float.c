#include "lip/1darray/file/write_float.h"
#include "1darray/pack_float.h"
#include "lip/1darray/1darray.h"
#include "lip/1darray/type.h"
#include "lip/file/file.h"
#include "lip/store_float.h"

bool lip_write_1darray_f32(struct lip_file *file, unsigned size,
                           float const arr[])
{
    if (file->error) return false;

    lip_write_1darray_size_type(file, size, LIP_1DARRAY_F32);
    for (unsigned i = 0; i < size; ++i)
        lip_write_1darray_f32_item(file, arr[i]);

    return !file->error;
}

bool lip_write_1darray_f64(struct lip_file *file, unsigned size,
                           double const arr[])
{
    if (file->error) return false;

    lip_write_1darray_size_type(file, size, LIP_1DARRAY_F64);
    for (unsigned i = 0; i < size; ++i)
        lip_write_1darray_f64_item(file, arr[i]);

    return !file->error;
}

bool lip_write_1darray_f32_data(struct lip_file *file, unsigned size,
                                float const arr[])
{
    if (file->error) return false;

    for (unsigned i = 0; i < size; ++i)
        lip_write_1darray_f32_item(file, arr[i]);

    return !file->error;
}

bool lip_write_1darray_f64_data(struct lip_file *file, unsigned size,
                                double const arr[])
{
    if (file->error) return false;

    for (unsigned i = 0; i < size; ++i)
        lip_write_1darray_f64_item(file, arr[i]);

    return !file->error;
}

bool lip_write_1darray_f32_data_in(struct lip_file *file, unsigned size,
                                   float arr[])
{
    if (file->error) return false;

    pack_1darray_f32_data_in((unsigned char *)arr, size);
    file->error = fwrite(arr, size * sizeof(float), 1, file->fp) != 1;

    return !file->error;
}

bool lip_write_1darray_f64_data_in(struct lip_file *file, unsigned size,
                                   double arr[])
{
    if (file->error) return false;

    pack_1darray_f64_data_in((unsigned char *)arr, size);
    file->error = fwrite(arr, size * sizeof(double), 1, file->fp) != 1;

    return !file->error;
}
