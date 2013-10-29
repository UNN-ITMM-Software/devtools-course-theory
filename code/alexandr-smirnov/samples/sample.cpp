/* Copyright 2013 Alexandr Smirnov */

#include <sort.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
    printf("This is the program of sorting arrays\n");
	
    int N = 10;
    int* a = new int[N];
    int* b = new int[N];
    int* c = new int[N];
    unsigned int* r;

    for (int i = 0; i < N; i++) {
        a[i] = rand_r(r) % 10;
        b[i] = rand_r(r) % 10;
        c[i] = rand_r(r) % 10;
    }
    Sorter sorter;

    printf("Here are array A and result of sorting it by QuickSort\n");
    for (int i = 0; i < N; i++)
        printf("%d ", a[i]);
    printf("\n");
    sorter.Sort(a, N, QUICKSORT);
    for (int i = 0; i < N; i++)
        printf("%d ", a[i]);
    printf("\n");

    printf("Here are array B and result of sorting it by HeapSort\n");
    for (int i = 0; i < N; i++)
        printf("%d ", b[i]);
    printf("\n");
    sorter.Sort(b, N, HEAPSORT);
    for (int i = 0; i < N; i++)
        printf("%d ", b[i]);
    printf("\n");

    printf("Here are array C and result of sorting it by MergeSort\n");
    for (int i = 0; i < N; i++)
        printf("%d ", c[i]);
    printf("\n");
    sorter.Sort(c, N, MERGESORT);
    for (int i = 0; i < N; i++)
        printf("%d ", c[i]);

    delete a, b, c;

    return 0;
}
