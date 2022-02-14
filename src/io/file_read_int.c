#include "lite_pack/io/file_read_int.h"
#include "lite_pack/format.h"
#include "lite_pack/io/file_ctx.h"
#include "lite_pack/unpack_int.h"

static inline unsigned int_size(enum lip_format fmt)
{
    unsigned sz = 0;
    switch (fmt)
    {
    case LIP_FMT_INT_64:
    case LIP_FMT_UINT_64:
        sz += 2;
        fallthrough;
    case LIP_FMT_INT_32:
    case LIP_FMT_UINT_32:
        sz += 2;
        fallthrough;
    case LIP_FMT_INT_16:
    case LIP_FMT_UINT_16:
        sz += 1;
        fallthrough;
    case LIP_FMT_INT_8:
    case LIP_FMT_UINT_8:
        sz += 1;
        fallthrough;
    default:
        return 0;
    }
}

/* SIGNED INTEGER */

static inline void read_int(struct lip_ctx_file *ctx)
{
    ctx->error = fread(ctx->buf, 1, 1, ctx->fp) != 1;
    if (ctx->error) return;

    unsigned sz = 0;
    switch (lip_format(ctx->buf))
    {
    case LIP_FMT_INT_64:
    case LIP_FMT_UINT_64:
        sz += 4;
        fallthrough;

    case LIP_FMT_INT_32:
    case LIP_FMT_UINT_32:
        sz += 2;

        fallthrough;
    case LIP_FMT_INT_16:
    case LIP_FMT_UINT_16:
        sz += 1;
        fallthrough;

    case LIP_FMT_INT_8:
    case LIP_FMT_UINT_8:
        sz += 1;
        ctx->error = fread(ctx->buf + 1, sz, 1, ctx->fp) != 1;
        if (ctx->error) return;
        fallthrough;

    case LIP_FMT_POSITIVE_FIXINT:
    case LIP_FMT_NEGATIVE_FIXINT:
        break;

    default:
        ctx->error = true;
        return;
    }
}

void __lip_read_i8(struct lip_ctx_file *ctx, int8_t *val)
{
    if (ctx->error) return;

    read_int(ctx);
    if (ctx->error) return;

    ctx->error = __lip_unpack_i8(ctx->buf, val) == 0;
}

void __lip_read_i16(struct lip_ctx_file *ctx, int16_t *val)
{
    if (ctx->error) return;

    read_int(ctx);
    if (ctx->error) return;

    ctx->error = __lip_unpack_i16(ctx->buf, val) == 0;
}

void __lip_read_i32(struct lip_ctx_file *ctx, int32_t *val)
{
    if (ctx->error) return;

    read_int(ctx);
    if (ctx->error) return;

    ctx->error = __lip_unpack_i32(ctx->buf, val) == 0;
}

void __lip_read_i64(struct lip_ctx_file *ctx, int64_t *val)
{
    if (ctx->error) return;

    read_int(ctx);
    if (ctx->error) return;

    ctx->error = __lip_unpack_i64(ctx->buf, val) == 0;
}

/* UNSIGNED INTEGER */

void __lip_read_u8(struct lip_ctx_file *ctx, uint8_t *val)
{
    if (ctx->error) return;

    read_int(ctx);
    if (ctx->error) return;

    ctx->error = __lip_unpack_u8(ctx->buf, val) == 0;
}

void __lip_read_u16(struct lip_ctx_file *ctx, uint16_t *val)
{
    if (ctx->error) return;

    read_int(ctx);
    if (ctx->error) return;

    ctx->error = __lip_unpack_u16(ctx->buf, val) == 0;
}

void __lip_read_u32(struct lip_ctx_file *ctx, uint32_t *val)
{
    if (ctx->error) return;

    read_int(ctx);
    if (ctx->error) return;

    ctx->error = __lip_unpack_u32(ctx->buf, val) == 0;
}

void __lip_read_u64(struct lip_ctx_file *ctx, uint64_t *val)
{
    if (ctx->error) return;

    read_int(ctx);
    if (ctx->error) return;

    ctx->error = __lip_unpack_u64(ctx->buf, val) == 0;
}
