Смирнов Александр: Алгоритмы сортировок
=======================================

Класс ``Sort`` предназначен для сортировки массива целых чисел. Он содержит метод ``Sorter``, который позволяет сортировать массив следующими алгоритмами:

* быстрая сортировка
* пирамидальная сортировка
* сортировка слияниями

.. code-block:: cpp
	
    enum SortMethod{QuickSort, HeapSort, MergeSort};
    class Sort
    {
    public:
    Sort();
    virtual ~Sort();
    void Sorter(int *Array, int size, SortMethod method);
    };
Пример использования:
---------------------
.. code-block:: cpp

    int N = 10;
    int *a = new int[N];
    Sort sorter;
    sorter.Sorter(a , N, QuickSort);
