#include "llist.h"
#include "dllist.h"
#include <stdio.h>

int main() {
    dllist list = dllist_create();

    int i;
    for (i = 0; i < 5; i++)
        list = dllist_insert(i, list);  
    
    dllist_print(list);
    
    dllist second = dllist_next(list);

    list = dllist_removen(second, list);

    dllist_print(list);

    list = dllist_sremove(4, list);

    dllist_print(list);

    dllist_destroy(list);

    return 0;
}
