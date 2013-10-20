#include <sort.h>
    
    Sort::Sort(){}
   
    Sort::~Sort(){
      delete []elements;
    }
    
    void Sort::Sorter(int *Array, int size, SortMethod method){
      switch (method){
       case QuickSort: quickSort(Array, size); break;
       case HeapSort: heapSort(Array, size); break;
       case MergeSort: mergeSort(Array, size); break;
      }	
    }
    
    void Sort::quickSort(int *Array, int size){	
      elements = new int[size];
      elements = Array;
      q_Sort_process(0, size - 1);
    }
    
    void Sort::q_Sort_process(int l, int r){
      int x = elements[l + (r - l) / 2];
      int i = l;
      int j = r;
      while (i <= j){
        while (elements[i] < x) 
          i++;
        while (elements[j] > x) 
          j--;
        if (i <= j){
          int z = elements[i];
          elements[i] = elements[j];
          elements[j] = z;
          i++;
          j--;
        }
      }
      if (i < r)
      q_Sort_process(i, r);
      if (l < j)
      q_Sort_process(l, j);
    }
    
    void Sort::heapSort(int *Array, int size){
      elements = new int[size];
      elements = Array;
      int i, tmp;
      for(i = size/2 - 1; i >= 0; i--)
        downHeap(elements, i, size-1);
      for(i = size - 1; i > 0; i--){
        tmp = elements[i]; 
        elements[i] = elements[0]; 
        elements[0] = tmp;
        downHeap(elements, 0, i-1); 
      }
    }
    
    void Sort::downHeap(int *mass, long K, int N){
      int new_elem = mass[K], child;
      while( K <= N/2 ){
        child = 2 * K;
        if( child < N && mass[child] < mass[child+1] ) 
          child ++;
        if( new_elem >= mass[child] )
          break; 
        mass[K] = mass[child];
        K = child;
      }
      mass[K] = new_elem;
    }
    
    void Sort::mergeSort(int *Array, int size){
      elements = new int[size];
      elements = Array;
      mergeSort_proc(elements, 0, size-1);
    }
    
    void Sort::mergeSort_proc(int *mass, long L, long R){ 
      long Pivot;
      if( L < R ){
        Pivot = (L + R) / 2;
        mergeSort_proc(elements, L, Pivot); 
        mergeSort_proc(elements, Pivot + 1, R);
        merge(elements, L, Pivot, R);
      }
    }
    
    void Sort::merge(int *a, int L, int Pivot, long R){
      int pos1 = L, pos2 = Pivot + 1, pos3 = 0;  
      int *temp = new int[R-L+1];
      while( pos1 <= Pivot && pos2 <= R ){
        if (a[pos1] < a[pos2])
          temp[pos3++] = a[pos1++];
        else
          temp[pos3++] = a[pos2++];
      }
      while( pos2 <= R )
        temp[pos3++] = a[pos2++];
      while( pos1 <= Pivot )
        temp[pos3++] = a[pos1++];
      for( pos3 = 0; pos3 < R-L+1; pos3++ )
        a[L+pos3] = temp[pos3];
    }
