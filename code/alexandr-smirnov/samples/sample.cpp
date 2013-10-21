/* Copyright 2013 Alexandr Smirnov */
#include <sort.h>
#include <stdlib.h>
#include <stdio.h>

int main(){
 printf("This is the program of sorting arrays\n");
 int N=10;
 int *a = new int[N];
 int *b = new int[N];
 int *c = new int[N];
 for(int i = 0; i < N; i++){
   a[i] = rand() % 20;
   b[i] = rand() % 20;
   c[i] = rand() % 20;
 }
 Sort sorter;
 
 printf("Here are array A and result of sorting it by QuickSort\n");
 for(int i = 0; i < N; i++)
   printf("%d ", a[i]);
 printf("\n");
 sorter.Sorter(a , N, QuickSort);
 for(int i = 0; i < N; i++)
   printf("%d ", a[i]);
   printf("\n");
   
 printf("Here are array B and result of sorting it by HeapSort\n");
 for(int i = 0; i < N; i++)
   printf("%d ", b[i]);
 printf("\n");
 sorter.Sorter(b , N, HeapSort);
 for(int i = 0; i < N; i++)
   printf("%d ", b[i]);
   printf("\n");
   
 printf("Here are array C and result of sorting it by MergeSort\n");
 for(int i = 0; i < N; i++)
   printf("%d ", c[i]);
 printf("\n");
 sorter.Sorter(c , N, MergeSort);
 for(int i = 0; i < N; i++)
   printf("%d ", c[i]);
   
 delete a,b,c;
   
 return 0;
}
