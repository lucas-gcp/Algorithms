typedef struct tnode *btree;

btree btree_create_empty();

btree btree_create(int data, btree l, btree r);

void btree_destroy(btree t);

void btree_traverse_pre(btree t, void (*visit)(btree));

void btree_traverse_in(btree t, void (*visit)(btree));

void btree_traverse_post(btree t, void (*visit)(btree));

void btree_print_root(btree t);

int btree_size(btree t);

int btree_height(btree t);

int btree_cost(btree t);
