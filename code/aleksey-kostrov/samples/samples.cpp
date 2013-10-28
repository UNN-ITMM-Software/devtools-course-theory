/* Copyright 2013 Aleksey Kostrov */
#include <Dichotomy_Search.h>

#define SIZE_FOR_PRINT 25
#define LEFT_BORDER_RANDOM 1
#define RIGHT_BORDER_RANDOM 50

int main(void) {
    const int TOO_SMALL_ARRAY = -2;
    const int ELEM_NOT_FOUND = -1;
    int * array;
    int size = 20, element = 18;
    printf("Size of array = %d\n", size);
    printf("Search element = %d\n", element);
    srand(time(NULL));
    array = new int[size];
    unsigned int seed = 10;
    for (int i = 0; i < size; i++)
        array[i] = rand_r(&seed) % RIGHT_BORDER_RANDOM + LEFT_BORDER_RANDOM;
    if (size < SIZE_FOR_PRINT && size > 0) {
        printf("Generated array: ");
        for (int i = 0; i < size; i++)
            printf("%d ", array[i]);
        printf("\n");
    } else if (size > 0) {
        printf("Array was generated automatically!\n");
    }
    try {
        DichotomySearch example1;
        example1.Search(array, element, size);
    } catch(int e) {
        if (e == ELEM_NOT_FOUND)
            printf("Element not found!\n");
        else if (e == TOO_SMALL_ARRAY)
            printf("Error! Size of array < 1 \n");
        else
            printf("Index of search element: %d", e+1);
    } catch(...) {
        printf("Other Error!");
    }
    return (0);
}
