#include <stdlib.h>
#include "sort.h"

static void exch(int a, int b, int *v) {
    int temp = v[a];
    v[a] = v[b];
    v[b] = temp;
}

void bubblesort(int *v, int n) {
    int i, j, stop;
    for (i = 0; i < n; i++) {
        stop = 1;
        for (j = n-1; j > i; j--)
            if (v[j] < v[j-1]) {
                exch(j, j-1, v);
                stop = 0;
            }
        if (stop) return;
    }
}

static void merge(int s, int m, int e, int *v) {
    int *w = malloc((e-s) * sizeof(int));
    int i = s, j = m, k = 0;
    while (i < m && j < e) {
        w[k++] = (v[i] <= v[j]) ? v[i++] : v[j++];
    }
    while (i < m) w[k++] = v[i++];
    while (j < e) w[k++] = v[j++];

    for (i = s; i < e; i++)
        v[i] = w[i-s];

    free(w);
}

void mergesort(int s, int e, int *v) {
    if (s < e-1) {
        int m = (s+e)/2;
        mergesort(s, m, v);
        mergesort(m, e, v);
        merge(s, m, e, v);
    }
}

static void fix_down(int pos, int *v, int n) {
    int l = pos*2 + 1, r = pos*2 + 2;
    while (l < n) {
        if (r < n && v[r] > v[l])
            l = r;

        if (v[pos] < v[l])
            exch(pos, l, v);
        else
            break;

        pos = l;
        l = pos*2 + 1;
        r = pos*2 + 2;
    } 
}

static void heapify(int *v, int n) {
    int i;
    for (i = n/2 - 1; i >= 0; i--)
        fix_down(i, v, n);
}

void heapsort(int *v, int n) {
    heapify(v, n);
    while (n > 0) {
        exch(0, --n, v);
        fix_down(0, v, n);
    }
}

static int partition(int s, int e, int *v) {
    int i = s;
    int j = e;
    int x = v[s];
    while (1) {
        while(v[++i] < x)
            if (j == e-1) break;
        while(v[--j] > x) ;
        if (i >= j) break;
        exch(i, j, v);
    }
    exch(s, j, v);
    return j;
}

void quicksort(int s, int e, int *v) {
    if (s < e-1) {
        int x = partition(s, e, v);
        quicksort(s, x, v);
        quicksort(x+1, e, v);
    }
}