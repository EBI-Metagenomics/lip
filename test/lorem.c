#include "lorem.h"
#include <stdlib.h>

static char const paragraph[] =
    "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod "
    "tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim "
    "veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea "
    "commodo consequat. Duis aute irure dolor in reprehenderit in voluptate "
    "velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint "
    "occaecat cupidatat non proident, sunt in culpa qui officia deserunt "
    "mollit anim id est laborum.";

char *lorem_new(unsigned long length)
{
    char *lorem = malloc(length + 1);
    if (!lorem) exit(1);

    for (unsigned long i = 0; i < length; ++i)
        lorem[i] = paragraph[i % (sizeof(paragraph) - 1)];

    lorem[length] = 0;

    return lorem;
}
