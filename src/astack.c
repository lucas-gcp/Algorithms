#include "astack.h"
#include <stdlib.h>

struct astack {
    int max_size;
    int n;
    int* stack;
};

astack* astack_create(int max_size) {
    astack* stack = malloc(sizeof(astack));
    stack->max_size = max_size;
    stack->n = 0;
    stack->stack = malloc(max_size * sizeof(int));
    return stack;
}

void astack_destroy(astack* stack) {
    free(stack->stack);
    free(stack);
}

void astack_clear(astack* stack) {
    stack->n = 0;
}

void astack_push(int value, astack* stack) {
    if (stack->n < stack->max_size)
        stack->stack[stack->n++] = value;
}

int astack_pop(astack* stack) {
    if (stack->n != 0)
        return stack->stack[--stack->n];
    astack_destroy(stack);
    exit(1);
}
