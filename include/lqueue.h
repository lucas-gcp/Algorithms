typedef struct lqueue lqueue;

lqueue* lqueue_create();

void lqueue_destroy(lqueue* queue);

void lqueue_clear(lqueue* queue);

void lqueue_enqueue(int value, lqueue* queue);

int lqueue_dequeue(lqueue* queue);