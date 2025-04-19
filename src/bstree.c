#include <stdlib.h>
#include <stdio.h>
#include "bstree.h"

struct bsnode {
    int data;
    struct bsnode *l;
    struct bsnode *r;
};

bstree bstree_create_empty() {
    return NULL;
}

void bstree_destroy(bstree t) {
    if (t != NULL) {
        bstree_destroy(t->l);
        bstree_destroy(t->r);
        free(t);
    }
}

bstree bstree_insert(int data, bstree t) {
    if (t == NULL) {
        t = malloc(sizeof(*t));
        t->data = data;
        t->l = bstree_create_empty();
        t->r = bstree_create_empty();
    }
    else if (data > t->data)
        t->r = bstree_insert(data, t->r);
    else
        t->l = bstree_insert(data, t->l);
    return t;
}

bstree bstree_remove(bstree node) {
    if (node != NULL) {
        bstree temp = node;
        if (node->l == NULL)
            node = node->r;
        else {
            bstree p = node;
            temp = node->l;
            while (temp->r != NULL) {
                p = temp;
                temp = temp->r;
            }
            node->data = temp->data;
            p->r = NULL;
        }
        free(temp);
    }
    return node;
}

bstree bstree_search(int value, bstree t) {
    if (t == NULL || value == t->data)
        return t;
    if (value > t->data)
        return bstree_search(value, t->r);
    return bstree_search(value, t->l);
}

bstree bstree_sremove(int value, bstree t) {
    if (t != NULL) {
        bstree node = t, p = node;
        while (node != NULL && value != node->data) {
            p = node;
            if (value > node->data)
                node = node->r;
            else
                node = node->l;
        }
        if (value > p->data)
            p->r = bstree_remove(p->r);
        else if (value < p->data)
            p->l = bstree_remove(p->l);
        else
            t = bstree_remove(t);
    }
    return t;
}

void bstree_traverse_pre(bstree t, void (*visit)(bstree)) {
    if (t != NULL) {
        (*visit)(t);
        bstree_traverse_pre(t->l, visit);
        bstree_traverse_pre(t->r, visit);
    }
}

void bstree_traverse_in(bstree t, void (*visit)(bstree)) {
    if (t != NULL) {
        bstree_traverse_in(t->l, visit);
        (*visit)(t);
        bstree_traverse_in(t->r, visit);
    }
}

void bstree_traverse_post(bstree t, void (*visit)(bstree)) {
    if (t != NULL) {
        bstree_traverse_post(t->l, visit);
        bstree_traverse_post(t->r, visit);
        (*visit)(t);
    }
}

void bstree_print_root(bstree t) {
    printf("%d ", t->data);
}