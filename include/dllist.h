typedef struct dlnode *dllist;

dllist dllist_create();

void dllist_destroy(dllist list);

dllist dllist_insert(int value, dllist list);

dllist dllist_removen(dllist node, dllist list);

dllist dllist_sremove(int value, dllist list);

dllist dllist_search(int value, dllist list);

dllist dllist_next(dllist list);

dllist dllist_prev(dllist list);

int dllist_getvalue(dllist node);

void dllist_print(dllist list);