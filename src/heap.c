#include <stdlib.h>
#include <stdio.h>
#include "heap.h"

#define par(i) ((i-1)/2)
#define left(i) ((2*i) + 1)
#define right(i) ((2*i) + 2)

struct heap {
    int max;
    int pos;
    int *v;
};

heap heap_create(int max) {
    heap h = malloc(sizeof(*h));
    h->max = max;
    h->pos = 0;
    h->v = malloc(max * sizeof(int));
    return h;
}

static void heap_realloc(heap h) {
    h->max *= 2;
    h->v = realloc(h->v, h->max);
}

void heap_destroy(heap h) {
    free(h->v);
    free(h);
}

static void exch(int a, int b, int *v) {
    int temp = v[a];
    v[a] = v[b];
    v[b] = temp;
}

static void heap_fixup(int pos, heap h) {
    int par = par(pos);
    while (par >= 0) {
        if (h->v[pos] > h->v[par])
            exch(pos, par, h->v);
        else
            break;
        pos = par;
        par = par(pos);
    }
}

static void heap_fixdown(int pos, heap h) {
    int next, left = left(pos), right = right(pos);
    while (left < h->pos) {
        if (right < h->pos && h->v[right] > h->v[left])
            next = right;
        else
            next = left;
        if (h->v[pos] < h->v[next])
            exch(pos, next, h->v);
        else
            break;
        pos = next;
        left = left(pos);
        right = right(pos);
    }
}

heap heap_build(int *v, int n) {
    heap h = heap_create(n);
    int i;
    for (i = 0; i < n; i++)
        h->v[i] = v[i];
    h->pos = n;
    for (i = n/2 - 1; i >=0; i--)
        heap_fixdown(i, h);
    return h;
}

void heap_insert(int value, heap h) {
    if (h->pos == h->max)
        heap_realloc(h);
    h->v[h->pos] = value;
    heap_fixup(h->pos, h);
    h->pos++;
}

int heap_pop(heap h) {
    int top = h->v[0];
    h->v[0] = h->v[--h->pos];
    heap_fixdown(0, h);
    return top;
}

int heap_top(heap h) {
    return h->v[0];
}

void heap_print(heap h) {
    int i;
    for (i = 0; i < h->pos - 1; i++)
        printf("%d ", h->v[i]);
    printf("%d", h->v[h->pos - 1]);
}