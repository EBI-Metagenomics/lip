#include "lip/file/file.h"
#include "lip/format.h"
#include "lip/stdio_unlocked.h"
#include "lip/unpack_str.h"

/**
 * lip_read_str_size(): Read string size.
 * @file: Stream.
 * @size: Number of bytes in the string.
 *
 * String in this context is simply a sequence of bytes. In particular,
 * it might contain zero or more null bytes.
 *
 * Return:
 * * true       - Success.
 * * false      - Failure.
 */
bool lip_read_str_size(struct lip_file *file, unsigned *size)
{
    if (file->error) return false;

    file->error = lip_fread(file->buf, 1, 1, file->fp) != 1;
    if (file->error) return false;

    unsigned sz = 0;
    switch (lip_format(file->buf[0]))
    {
    case LIP_FMT_STR_32:
        sz += 2;
        fallthrough;

    case LIP_FMT_STR_16:
        sz += 1;
        fallthrough;

    case LIP_FMT_STR_8:
        sz += 1;
        file->error = lip_fread(file->buf + 1, sz, 1, file->fp) != 1;
        if (file->error) return false;
        fallthrough;

    case LIP_FMT_FIXSTR:
        break;

    default:
        file->error = true;
        return false;
    }

    return !(file->error = lip_unpack_str_size(file->buf, size) == 0);
}

/**
 * lip_read_str_data(): Reading a string.
 * @file: Context.
 * @size: Size of @str.
 * @str: Destination of the string.
 *
 * String in this context is simply a sequence of bytes. Null termination
 * is not required. In particular, multiple null bytes might be present
 * in @str.
 *
 * Return:
 * * true       - Success.
 * * false      - Failure.
 */
bool lip_read_str_data(struct lip_file *file, unsigned size, char str[])
{
    if (file->error) return false;

    return !(file->error = lip_fread(str, size, 1, file->fp) * size != size);
}
