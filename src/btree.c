#include <stdlib.h>
#include <stdio.h>
#include "btree.h"

struct tnode {
    int data;
    struct tnode *l;
    struct tnode *r;
};

btree btree_create_empty() {
    return NULL;
}

btree btree_create(int data, btree l, btree r) {
    btree t = malloc(sizeof(*t));
    t->data = data;
    t->l = l;
    t->r = r;
    return t;
}

void btree_destroy(btree t) {
    if (t != NULL) {
        btree_destroy(t->l);
        btree_destroy(t->r);
        free(t);
    }
}

void btree_traverse_pre(btree t, void (*visit)(btree)) {
    if (t != NULL) {
        (*visit)(t);
        btree_traverse_pre(t->l, visit);
        btree_traverse_pre(t->r, visit);
    }
}

void btree_traverse_in(btree t, void (*visit)(btree)) {
    if (t != NULL) {
        btree_traverse_in(t->l, visit);
        (*visit)(t);
        btree_traverse_in(t->r, visit);
    }
}

void btree_traverse_post(btree t, void (*visit)(btree)) {
    if (t != NULL) {
        btree_traverse_post(t->l, visit);
        btree_traverse_post(t->r, visit);
        (*visit)(t);
    }
}

void btree_print_root(btree t) {
    printf("%d ", t->data);
}

int btree_size(btree t) {
    if (t == NULL)
        return 0;
    return 1 + btree_size(t->l) + btree_size(t->r);
}

int btree_height(btree t) {
    if (t == NULL)
        return 0;
    int hl = btree_height(t->l);
    int hr = btree_height(t->r);
    if (hl > hr)
        return 1 + hl;
    return 1 + hr;
}

int btree_cost(btree t) {
    if (t == NULL)
        return 0;
    int cl = btree_cost(t->l);
    int cr = btree_cost(t->r);
    if (cl > cr)
        return t->data + cl;
    return t->data + cr;
}
