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