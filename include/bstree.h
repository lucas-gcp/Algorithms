typedef struct bsnode *bstree;

bstree bstree_create_empty();

void bstree_destroy(bstree t);

bstree bstree_insert(int data, bstree t);

bstree bstree_remove(bstree node);

bstree bstree_search(int value, bstree t);

bstree bstree_sremove(int value, bstree t);

void bstree_traverse_pre(bstree t, void (*visit)(bstree));

void bstree_traverse_in(bstree t, void (*visit)(bstree));

void bstree_traverse_post(bstree t, void (*visit)(bstree));

void bstree_print_root(bstree t);