typedef struct lstack lstack;

lstack* lstack_create();

void lstack_destroy(lstack* stack);

void lstack_clear(lstack* stack);

void lstack_push(int value, lstack* stack);

int lstack_pop(lstack* stack);
