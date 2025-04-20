#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

void vprint(int *v, int n) {
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", v[i]);
    printf("\n");
}

int main() {
    int n = 5;
    int v1[5] = {1, 5, 3, 2, 9};
    int v2[5] = {1, 5, 3, 2, 9};
    int v3[5] = {1, 5, 3, 2, 9};
    int v4[5] = {1, 5, 3, 2, 9};
    
    bubblesort(v1, n);
    vprint(v1, n);
    mergesort(0, n, v2);
    vprint(v2, n);
    heapsort(v3, n);
    vprint(v3, n);
    quicksort(0, n, v4);
    vprint(v4, n);
    
    return 1;
}
