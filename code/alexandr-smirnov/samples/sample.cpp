/* Copyright 2013 Alexandr Smirnov */

#include <sort.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
    printf("This is the program of sorting arrays\n");

    int N = 3;
    int* a = new int[N];
    int* b = new int[N];
    int* c = new int[N];

    a[0]=5;
    a[1]=3;
    a[2]=-8;
    b[0]=4;
    b[1]=-2;
    b[2]=0;
    c[0]=1;
    c[1]=-3;
    c[2]=-3;

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
