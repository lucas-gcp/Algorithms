#include "btree.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    btree T = btree_create(34,
        btree_create(24, 
            btree_create(11,
                btree_create(5,
                    btree_create_empty(),
                    btree_create_empty()),
                btree_create_empty()),
            btree_create(19,
                btree_create_empty(),
                btree_create_empty())
        ),
        btree_create(17, 
            btree_create(7,
                btree_create_empty(),
                btree_create_empty()),
            btree_create(9,
                btree_create_empty(),
                btree_create_empty())
        )
    );

    printf("%d\n", btree_size(T));
    printf("%d\n", btree_height(T));
    printf("%d\n", btree_cost(T));

    btree_destroy(T);
}
