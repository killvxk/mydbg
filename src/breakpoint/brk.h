#ifndef BRKP_H
#define BRKP_H

#include <stdint.h>

#include "dbg.h"

struct brkp {
    size_t id;
    uint64_t *addr;
    uint8_t byte;
};

typedef struct brkp brkp_t;

/* Create a new struct representing a breakpoint and add it to the brkptable*/
brkp_t *brkp_new(ctx_t *ctx, uint64_t *addr);

/* Set the brkp in the memory of the tracee */
int brkp_set(ctx_t *ctx, brkp_t *brkp);
/* Replace interupt by real code of brkp in the memory of the tracee */
int brkp_unset(ctx_t *ctx, brkp_t *brkp);
/* Remove a breakpoint in a htab */
/* void brkp_set(htab_t *htab); */

#endif
