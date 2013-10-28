/* Copyright 2013 Alexandr Smirnov */

#ifndef CODE_ALEXANDR_SMIRNOV_INCLUDE_SORT_H_
#define CODE_ALEXANDR_SMIRNOV_INCLUDE_SORT_H_
    
enum SortMethod {QUICKSORT, HEAPSORT, MERGESORT};
    
class Sorter {
 public :
    Sorter(void);
    ~Sorter(void);
    
    void Sort(int *Array, int size, SortMethod method);
 private :
    class SortImplementation;
    SortImplementation* pImpl;
};
    
#endif  // CODE_ALEXANDR_SMIRNOV_INCLUDE_SORT_H_
    