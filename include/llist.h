typedef struct lnode* llist;

llist llist_create();

void llist_destroy(llist node);

llist llist_insert(int value, llist list);

llist llist_insertnext(int value, llist list);

llist llist_insertend(int value, llist list);

void llist_setnext(llist list, llist next);

llist llist_concat(llist l1, llist l2);

llist llist_union(llist l1, llist l2);

llist llist_intersection(llist l1, llist l2);

llist llist_greater(int v, llist l);

llist llist_removenode(llist node, llist list);

llist llist_sremove(int value, llist list);

llist llist_next(llist list);

llist llist_sort(llist list);

llist llist_reverse(llist list);

llist llist_search(int value, llist list);

int llist_getvalue(llist node);

void llist_print(llist list);