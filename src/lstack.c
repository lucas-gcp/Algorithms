#include "lstack.h"
#include "llist.h"
#include <stdlib.h>

struct lstack {
    llist beg;
};

lstack* lstack_create() {
    lstack* stack = malloc(sizeof(lstack));
    stack->beg = NULL;
    return stack;
}

void lstack_destroy(lstack* stack) {
    llist_destroy(stack->beg);
    free(stack);
}

void lstack_clear(lstack* stack) {
    llist_destroy(stack->beg);
    stack->beg = NULL;
}

void lstack_push(int value, lstack* stack) {
    stack->beg = llist_insert(value, stack->beg);
}

int lstack_pop(lstack* stack) {
    if (stack->beg != NULL) {
        int value = llist_getvalue(stack->beg);
        stack->beg = llist_removenode(stack->beg, stack->beg);
        return value;
    }
    lstack_destroy(stack);
    exit(1);
}