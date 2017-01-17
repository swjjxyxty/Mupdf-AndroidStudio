#ifndef MUPDF_FITZ_OUTPUT_TGA_H
#define MUPDF_FITZ_OUTPUT_TGA_H

#include "../fitz/system.h"
#include "../fitz/context.h"
#include "../fitz/pixmap.h"

void fz_write_tga(fz_context *ctx, fz_pixmap *pixmap, const char *filename, int savealpha);

#endif
