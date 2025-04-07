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

llist llist_concat(llist l1, llist l2) {
    if (l1 == NULL)
        l1 = l2;
    else {
        llist temp;
        for (temp = l1; temp->next != NULL; temp = temp->next);
        temp->next = l2;
    }
    return l1;
}

llist llist_union(llist l1, llist l2) {
    llist u = llist_create();

    for (; l1 != NULL; l1 = l1->next)
        if (llist_search(l1->data, u) == NULL)
            u = llist_insert(l1->data, u);

    for (; l2 != NULL; l2 = l2->next)
        if (llist_search(l2->data, u) == NULL)
            u = llist_insert(l2->data, u);

    return u;
}

llist llist_intersection(llist l1, llist l2) {
    llist u = llist_create();
    for (; l1 != NULL; l1 = l1->next)
        if (llist_search(l1->data, l2) != NULL && llist_search(l1->data, u) == NULL)
            u = llist_insert(l1->data, u);
    return u;
}

llist llist_greater(int v, llist l) {
    llist u = llist_create();
    for (; l != NULL; l = l->next)
        if (l->data > v)
            u = llist_insert(l->data, u);
    return u;
}

llist llist_removenode(llist node, llist list) {
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

llist llist_sort(llist list) {
    llist curr, cmp, sorted = llist_create();
    sorted = llist_insert(0, sorted);

    while (list != NULL) {
        curr = list;
        list = list->next;
        for (cmp = sorted; cmp->next != NULL; cmp = cmp->next)
            if (cmp->next->data > curr->data) break;
        curr->next = cmp->next;
        cmp->next = curr;
    }
    list = sorted->next;
    free(sorted);
    return list;
}

llist llist_reverse(llist list) {
    llist curr, next, prev = NULL;
    for (curr = list; curr != NULL; curr = next) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
    }
    return prev;
}

llist llist_search(int value, llist list) {
    while (list != NULL && list->data != value) {
        list = list->next;
    }
    return list;
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