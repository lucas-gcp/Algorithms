typedef struct aqueue aqueue;

aqueue* aqueue_create(int max_size);

void aqueue_destroy(aqueue* queue);

void aqueue_clear(aqueue* queue);

void aqueue_enqueue(int value, aqueue* queue);

int aqueue_dequeue(aqueue* queue);