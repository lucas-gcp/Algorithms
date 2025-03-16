#include "llist.h"
#include <stdlib.h>
#include <stdio.h>

struct lnode {
    int data;
    struct lnode *next;
};

llist llist_create() {
    return NULL;
}

void llist_destroy(llist list) {
    llist temp;
    while (list != NULL) {
        temp = list;
        list = list->next;
        free(temp);
    }
}

llist llist_insert(int value, llist list) {
    llist new = malloc(sizeof(*new));
    new->data = value;
    new->next = list;
    return new;
}

llist llist_insertnext(int value, llist list) {
    llist new = malloc(sizeof(*new));
    new->data = value;
    if (list != NULL) {
        new->next = list->next;
        list->next = new;
    }
    else
        list = new;
    return list;
}

llist llist_insertend(int value, llist list) {
    llist new = malloc(sizeof(*new));
    new->data = value;
    new->next = NULL;
    if (list != NULL) {
        llist temp = list;
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = new;
    } else
        list = new;
    return list;
}

void llist_setnext(llist node, llist next) {
    if (node != NULL) {
        next->next = node->next;
        node->next = next;
    }
}

llist llist_removen(llist node, llist list) {
    if (list == NULL || node == NULL) return list;
    else if (node == list) {
        list = list->next;
        free(node);
    } else {
        llist temp = node->next;
        node->next = temp->next;
        free(temp);
    }
    return list;
}

llist llist_sremove(int value, llist list) {
    if (list == NULL) return list;
    llist p = NULL, q = list;
    while (q != NULL && q->data != value) {
        p = q;
        q = q->next;
    }
    if (p == NULL) {
        list = q->next;
    }
    else if (q != NULL) {
        p->next = q->next;
    }
    free(q);
    return list;
}

llist llist_next(llist list) {
    if (list == NULL)
        return NULL;
    return list->next;
}

int llist_getvalue(llist node) {
    if (node != NULL)
        return node->data;
    exit(1);
}

void llist_print(llist list) {
    while (list != NULL) {
        printf("%d ", list->data);
        list = list->next;
    }
    printf("\n");
}