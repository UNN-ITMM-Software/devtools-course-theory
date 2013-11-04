Смирнов Александр: Алгоритмы сортировок
=======================================

Класс ``Sorter`` предназначен для сортировки массива целых чисел. Он содержит метод ``Sort``, который позволяет сортировать массив следующими алгоритмами:

* быстрая сортировка
* пирамидальная сортировка
* сортировка слияниями

.. code-block:: cpp

    enum SortMethod {QUICKSORT, HEAPSORT, MERGESORT};
    class Sorter
    {
    public:
        Sorter(void);
        ~Sorter(void);
    
    void Sort(int *Array, int size, SortMethod method);
    };
Пример использования:
---------------------
.. code-block:: cpp

    int N = 10;
    int* a = new int[N];
    Sorter sorter;
    sorter.Sort(a, N, QUICKSORT);
