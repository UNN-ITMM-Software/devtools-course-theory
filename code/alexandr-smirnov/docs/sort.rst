Смирнов Александр: Алгоритмы сортировок 
=======================================

Класс ``Sort`` предназначен для сортировки массива целых чисел тремя алгоритмами.Он содержит методы:
* быстрая сортировка
* пирамидальная сортировка
* сортировка слияниями

.. code-block:: cpp

class Sort{
public:
	Sort();
	virtual ~Sort();
	
	void quickSort(int *Array,int size);
	void heapSort(int *Array,int size);
	void mergeSort(int *Array,int size);
private:
	int *elements;

	void q_Sort_process(int l, int r);
	void downHeap(int *mass, long K, int N);
	void mergeSort_proc(int *mass, long L, long R);
	void merge(int *a, int L, int Pivot, long R);
};

Пример использования:
---------------------
.. code-block:: cpp

int N = 10;

int *a = new int[N];

Sort massiv;

massiv.quickSort(a, N);

massiv.heapSort(a, N);

massiv.mergeSort(a, N);
