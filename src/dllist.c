#include "dllist.h"
#include <stdlib.h>
#include <stdio.h>

struct dlnode {
    int data;
    struct dlnode *prev;
    struct dlnode *next;
};

dllist dllist_create() {
    return NULL;
}

void dllist_destroy(dllist list) {
    dllist temp;
    while (list != NULL) {
        temp = list;
        list = list->next;
        free(temp);
    }
}

dllist dllist_insert(int value, dllist list) {
    dllist new = malloc(sizeof(*new));
    new->data = value;
    new->prev = NULL;
    new->next = list;

    if (list != NULL)
        list->prev = new;

    return new;
}

dllist dllist_removen(dllist node, dllist list) {
    if (node->prev != NULL)
        node->prev->next = node->next;
    else
        list = node->next;
    if (node->next != NULL)
        node->next->prev = node->prev;
    free(node);

    return list;
}

dllist dllist_sremove(int value, dllist list) {
    dllist node = dllist_search(value, list);
    if (node != NULL) {
        list = dllist_removen(node, list); }
    return list;
}

dllist dllist_search(int value, dllist list) {
    while (list != NULL && list->data != value) {
        list = list->next;
    }
    return list;
}

dllist dllist_next(dllist list) {
    if (list != NULL)
        return list->next;
    dllist_destroy(list);
    exit(1);
}

dllist dllist_prev(dllist list) {
    if (list != NULL)
        return list->prev;
    dllist_destroy(list);
    exit(1);
}

int dllist_getvalue(dllist node) {
    if (node != NULL)
        return node->data;
    exit(1);
}

void dllist_print(dllist list) {
    while (list != NULL) {
        printf("%d ", list->data);
        list = list->next;
    }
    printf("\n");
}