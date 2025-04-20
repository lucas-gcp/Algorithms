#include <stdlib.h>
#include <stdio.h>
#include "avl.h"

struct avlnode {
    int data;
    struct avlnode *l;
    struct avlnode *r;
    int h;
};

avl avl_create_empty() {
    return NULL;
}

avl avl_create(int data) {
    avl t = malloc(sizeof(*t));
    t->data = data;
    t->l = NULL;
    t->r = NULL;
    t->h = 1;
    return t;
}

void avl_destroy(avl t) {
    if (t != NULL) {
        avl_destroy(t->l);
        avl_destroy(t->r);
        free(t);
    }
}

static int avl_height(avl t) {
    if (t == NULL)
        return 0;
    return t->h;
}

static void avl_update_height(avl t) {
    if (t != NULL) {
        int hl = avl_height(t->l);
        int hr = avl_height(t->r);
        if (hl > hr)
            t->h = 1 + hl;
        else
            t->h = 1 + hr;
    }
}

static int avl_balancing_factor(avl t) {
    if (t == NULL)
        return 0;
    return avl_height(t->l) - avl_height(t->r);
}

static avl avl_rotl(avl t) {
    avl pivot = t->r;
    t->r = pivot->l;
    pivot->l = t;
    
    avl_update_height(t);
    avl_update_height(pivot);
    
    return pivot;
}

static avl avl_rotr(avl t) {
    avl pivot = t->l;
    t->l = pivot->r;
    pivot->r = t;

    avl_update_height(t);
    avl_update_height(pivot);
    
    return pivot;
}

static avl avl_rotlr(avl t) {
    t->l = avl_rotl(t->l);
    return avl_rotr(t);
}

static avl avl_rotrl(avl t) {
    t->r = avl_rotr(t->r);
    return avl_rotl(t);
}

static avl avl_rebalance(avl t) {
    avl_update_height(t);
    int bf = avl_balancing_factor(t);
    if (bf > 1) {
        if (avl_balancing_factor(t->l) < 0)
            t = avl_rotlr(t);
        else
            t = avl_rotr(t);
    } else if (bf < -1) {
        if (avl_balancing_factor(t->r) > 0)
            t = avl_rotrl(t);
        else
            t = avl_rotl(t);
    }
    return t;
}

avl avl_insert(int data, avl t) {
    if (t == NULL)
        t = avl_create(data);
    else if (data > t->data)
        t->r = avl_insert(data, t->r);
    else
        t->l = avl_insert(data, t->l);
    return avl_rebalance(t);
}

static avl avl_remove_root(avl t) {
    if (t != NULL) {
        avl temp = t;
        if (t->l == NULL)
            t = t->r;
        else {
            avl p;
            for (; temp->r != NULL; p = temp, temp = temp->r) ;
            t->data = temp->data;
            p->r = NULL;
        }      
        free(temp);
    }
    return t;
}

avl avl_sremove(int data, avl t) {
    if (t == NULL)
        return NULL;
    if (data > t->data)
        t->r = avl_sremove(data, t->r);
    else if (data < t->data)
        t->l = avl_sremove(data, t->l);
    else
        t = avl_remove_root(t);

    if (t == NULL)
        return NULL;
    return avl_rebalance(t);
}

void avl_traverse_pre(avl t, void (*visit)(avl)) {
    if (t != NULL) {
        (*visit)(t);
        avl_traverse_pre(t->l, visit);
        avl_traverse_pre(t->r, visit);
    }
}

void avl_traverse_in(avl t, void (*visit)(avl)) {
    if (t != NULL) {
        avl_traverse_in(t->l, visit);
        (*visit)(t);
        avl_traverse_in(t->r, visit);
    }
}

void avl_traverse_post(avl t, void (*visit)(avl)) {
    if (t != NULL) {
        avl_traverse_post(t->l, visit);
        avl_traverse_post(t->r, visit);
        (*visit)(t);
    }
}

void avl_print_root(avl t) {
    printf("%d ", t->data);
}
