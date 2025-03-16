typedef struct lnode* llist;

llist llist_create();

void llist_destroy(llist node);

llist llist_insert(int value, llist list);

llist llist_insertnext(int value, llist list);

llist llist_insertend(int value, llist list);

llist llist_removen(llist node, llist list);

llist llist_sremove(int value, llist list);

llist llist_next(llist list);

void llist_setnext(llist list, llist next);

int llist_getvalue(llist node);

void llist_print(llist list);