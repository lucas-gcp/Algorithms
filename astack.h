typedef struct astack astack;

astack* astack_create(int size);

void astack_destroy(astack* stack);

void astack_clear(astack* stack);

void astack_push(int value, astack* stack);

int astack_pop(astack* stack);
