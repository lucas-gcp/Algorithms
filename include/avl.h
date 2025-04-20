typedef struct avlnode *avl;

avl avl_create_empty();

avl avl_create(int data);

void avl_destroy(avl t);

avl avl_insert(int data, avl t);

avl avl_sremove(int data, avl t);

void avl_traverse_pre(avl t, void (*visit)(avl));

void avl_traverse_in(avl t, void (*visit)(avl));

void avl_traverse_post(avl t, void (*visit)(avl));

void avl_print_root(avl t);
