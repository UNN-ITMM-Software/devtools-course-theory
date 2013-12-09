/* Copyright 2013 Alexandr Smirnov */

#include <sort.h>

class Sorter::SortImplementation {
 public :
    void quickSort(int *Array, int size);
    void heapSort(int *Array, int size);
    void mergeSort(int *Array, int size);
    void quickSortProcess(int l, int r);
    void downHeap(int *mass, int K, int N);
    void mergeSortProcess(int L, int R);
    void merge(int *a, int L, int Pivot, int R);
 private :
    int *elements;
};

Sorter::Sorter(void): pImpl(new SortImplementation) {
}

Sorter::Sorter(const Sorter& sorter): pImpl(new SortImplementation) {
    pImpl = sorter.pImpl;
}

Sorter::~Sorter(void) {
    delete pImpl;
}

void Sorter::Sort(int *Array, int size, SortMethod method) {
    switch (method) {
        case QUICKSORT:
        pImpl -> quickSort(Array, size);
        break;

        case HEAPSORT:
        pImpl -> heapSort(Array, size);
        break;

        case MERGESORT:
        pImpl -> mergeSort(Array, size);
        break;
    }
}

const Sorter& Sorter::operator=(const Sorter& sorter) {
    if (this != &sorter) {
      delete pImpl;
      pImpl = sorter.pImpl;
    }
    return *this;
}

void Sorter::SortImplementation::quickSort(int *Array, int size) {
    elements = Array;
    quickSortProcess(0, size - 1);
}

void Sorter::SortImplementation::quickSortProcess(int l, int r) {
    int x = elements[l + (r - l) / 2];
    int i = l;
    int j = r;
    while (i <= j) {
        while (elements[i] < x)
            i++;
        while (elements[j] > x)
            j--;
        if (i <= j) {
            int z = elements[i];
            elements[i] = elements[j];
            elements[j] = z;
            i++;
            j--;
        }
    }
    if (i < r)
        quickSortProcess(i, r);
    if (l < j)
        quickSortProcess(l, j);
}

void Sorter::SortImplementation::heapSort(int *Array, int size) {
    elements = Array;
    int i, tmp;
    for (i = size / 2; i >= 0; i--)
        downHeap(elements, i, size-1);
    for (i = size / 2 - 1; i >= 0; i--)
        downHeap(elements, i, size-1);
    for (i = size - 1; i > 0; i--) {
        tmp = elements[i];
        elements[i] = elements[0];
        elements[0] = tmp;
        downHeap(elements, 0, i - 1);
    }
}

void Sorter::SortImplementation::downHeap(int *mass, int K, int N) {
    int new_elem = mass[K], child;
    while (K <= N / 2) {
        child = 2 * K;
        if (child < N && mass[child] < mass[child + 1])
            child++;
        if (new_elem >= mass[child])
            break;
        mass[K] = mass[child];
        K = child;
    }
    mass[K] = new_elem;
}

void Sorter::SortImplementation::mergeSort(int *Array, int size) {
    elements = Array;
    mergeSortProcess(0, size - 1);
}

void Sorter::SortImplementation::mergeSortProcess(int L, int R) {
    int Pivot;
    if (L < R) {
        Pivot = (L + R) / 2;
        mergeSortProcess(L, Pivot);
        mergeSortProcess(Pivot + 1, R);
        merge(elements, L, Pivot, R);
    }
}

void Sorter::SortImplementation::merge(int *a, int L, int Pivot, int R) {
    int pos1 = L, pos2 = Pivot + 1, pos3 = 0;
    int* temp = new int[R - L + 1];
    while (pos1 <= Pivot && pos2 <= R) {
        if (a[pos1] < a[pos2])
            temp[pos3++] = a[pos1++];
        else
            temp[pos3++] = a[pos2++];
    }
    while (pos2 <= R)
        temp[pos3++] = a[pos2++];
    while ( pos1 <= Pivot )
        temp[pos3++] = a[pos1++];
    for (pos3 = 0; pos3 < R - L + 1; pos3++ )
        a[L + pos3] = temp[pos3];
}
