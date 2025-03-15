#include "lqueue.h"
#include "llist.h"
#include <stdlib.h>

struct lqueue {
    llist s;
    llist e;
};

lqueue* lqueue_create() {
    lqueue *queue = malloc(sizeof(queue));
    queue->s = queue->e = NULL;
}

void lqueue_destroy(lqueue* queue) {
    llsit_destroy(queue->s);
    free(queue);
}

void lqueue_clear(lqueue* queue) {
    llist_destroy(queue->s);
    queue->s = queue->e = NULL;
}

void lqueue_enqueue(int value, lqueue* queue) {
    queue->e = llist_insert(value, queue->e);
}

int lqueue_dequeue(lqueue* queue) {
    int value = llist_getvalue(queue->s);
    queue->s = llist_removen(queue->s, queue->s);
    return value;
}