#include "lqueue.h"
#include "llist.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    lqueue *queue = lqueue_create();

    lqueue_enqueue(1, queue);
    lqueue_enqueue(2, queue);
    lqueue_enqueue(3, queue);
    lqueue_enqueue(4, queue);
    int val = lqueue_dequeue(queue);
    printf("%d\n", val);
    val = lqueue_dequeue(queue);
    printf("%d\n", val);
    val = lqueue_dequeue(queue);
    printf("%d\n", val);
    lqueue_enqueue(5, queue);

    lqueue_destroy(queue);

    return 0;
}
