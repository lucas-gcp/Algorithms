typedef struct heap *heap;

heap heap_create(int max);

void heap_destroy(heap h);

heap heap_build(int *v, int n);

void heap_insert(int value, heap h);

int heap_pop(heap h);

int heap_top(heap h);

void heap_print(heap h);
