#include "aqueue.h"
#include <stdlib.h>

struct aqueue {
    int max_size;
    int n;
    int s;
    int *queue;
};

aqueue* aqueue_create(int max_size) {
    aqueue* queue = malloc(sizeof(aqueue));
    queue->max_size = max_size;
    queue->n = 0;
    queue->s = 0;
    queue->queue = malloc(max_size * sizeof(int));
    return queue;
}

void aqueue_destroy(aqueue* queue) {
    free(queue->queue);
    free(queue);
}

void aqueue_clear(aqueue* queue) {
    queue->n = 0;
    queue->s = 0;
}

void aqueue_enqueue(int value, aqueue* queue) {
    if (queue->n < queue->max_size) {
        int end = (queue->s + queue->n) % queue->max_size;
        queue->queue[end] = value;
        queue->n++;
    }
}

int aqueue_dequeue(aqueue* queue) {
    if (queue->n != 0) {
        int value = queue->queue[queue->s];
        queue->s = (queue->s + 1) % queue->max_size;
        queue->n--;
        return value;
    }
    exit(1);
}