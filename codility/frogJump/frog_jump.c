#include "frog_jump.h"
#include <cmath>

long unsigned solution (long unsigned x, long unsigned y, long unsigned D)
{
    long unsigned diff = y - x;
    unsigned int jumps = std::ceil((double)diff / (double)D);

    return jumps;
}
