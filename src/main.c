#include "bstree.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    bstree T = bstree_create_empty();
    T = bstree_insert(10, T);
    T = bstree_insert(5, T);
    T = bstree_insert(6, T);
    T = bstree_insert(1, T);
    T = bstree_insert(2, T);
    T = bstree_insert(3, T);
    T = bstree_insert(13, T);
    bstree_traverse_in(T, bstree_print_root);
    printf("\n");

    T = bstree_sremove(6, T);
    bstree_traverse_in(T, bstree_print_root);
    printf("\n");
    T = bstree_sremove(1, T);
    bstree_traverse_in(T, bstree_print_root);
    printf("\n");
    T = bstree_sremove(2, T);
    bstree_traverse_in(T, bstree_print_root);

    // printf("%d\n", btree_size(T));
    // printf("%d\n", btree_height(T));
    // printf("%d\n", btree_cost(T));

    bstree_destroy(T);
}
