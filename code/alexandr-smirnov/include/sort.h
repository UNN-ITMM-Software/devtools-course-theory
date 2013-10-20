#ifndef H_SORT
#define H_SORT
    
enum SortMethod{QuickSort, HeapSort, MergeSort};
    
class Sort{
public:
    Sort();
    virtual ~Sort();
    void Sorter(int *Array, int size, SortMethod method);
private:
    int *elements;

    void quickSort(int *Array, int size);
    void heapSort(int *Array, int size);
    void mergeSort(int *Array, int size);
    void q_Sort_process(int l, int r);
    void downHeap(int *mass, long K, int N); 
    void mergeSort_proc(int *mass, long L, long R);
    void merge(int *a, int L, int Pivot, long R);
};
#endif
