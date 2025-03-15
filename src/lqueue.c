#include "lqueue.h"
#include "llist.h"
#include <stdlib.h>

struct lqueue {
    llist s;
    llist e;
};

lqueue* lqueue_create() {
    lqueue* queue = malloc(sizeof(lqueue));
    queue->s = queue->e = NULL;
    return queue;
}

void lqueue_destroy(lqueue* queue) {
    llist_destroy(queue->s);
    free(queue);
}

void lqueue_clear(lqueue* queue) {
    llist_destroy(queue->s);
    queue->s = queue->e = NULL;
}

void lqueue_enqueue(int value, lqueue* queue) {
    llist new = llist_create();
    new = llist_insert(value, new);
    if (queue->s != NULL)
        llist_setnext(queue->s, new);
    else
        queue->s = new;
    queue->e = new;
}

int lqueue_dequeue(lqueue* queue) {
    if (queue->s != NULL) {
        int value = llist_getvalue(queue->s);
        queue->s = llist_removen(queue->s, queue->s);
        if (queue->s == NULL)
            queue->e = NULL;
        return value;
    }
    lqueue_destroy(queue);
    exit(1);
}