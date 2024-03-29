#include "lip/stdio_unlocked.h"
#include "lip/config.h"

#ifdef __APPLE__
#include <stdio.h>

// Found in
// https://github.com/nox/apple-libc/blob/21e2eb189b013050d6145d35f095d536fc7cd919/stdio/FreeBSD/fread.c#L143
extern size_t __fread(void *restrict buf, size_t size, size_t count,
                      FILE *restrict fp);

#if defined(LIP_THREAD_SAFE)
static inline size_t fread_unlocked(void *restrict buf, size_t size,
                                    size_t count, FILE *restrict fp)
{
    return __fread(buf, size, count, fp);
}
#endif

#else

// I want unlocked functions.
#define _GNU_SOURCE
#include <stdio.h>

#if defined(LIP_THREAD_SAFE)
extern size_t fread_unlocked(void *, size_t, size_t, FILE *);
#endif

#endif

#if defined(LIP_THREAD_SAFE)
size_t lip_fread(void *restrict buf, size_t size, size_t count,
                 FILE *restrict fp)
{
    return fread_unlocked(buf, size, count, fp);
}
#else
size_t lip_fread(void *restrict buf, size_t size, size_t count,
                 FILE *restrict fp)
{
    return fread(buf, size, count, fp);
}
#endif
