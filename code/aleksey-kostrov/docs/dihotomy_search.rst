Костров Алексей: Поиск методом "Дихотомии"
===========================================

Класс ``Dichotomy_Search`` предназначен для поиска элемента в массиве методом "Дихотомии".
Он предоставляет метод для предподготовки(сортировка массива) и 
последующей обработки(поиск индекса желаемого элемента) входящих данных, а именно числового массива.
В результате работы, данный метод класса выводит на экран индекс искомого элемента поиска или сообщает что такого нет.

.. code-block:: cpp

	class DichotomySearch {
 	public:
		DichotomySearch();
		~DichotomySearch();
		int **Preprocess(int *array, int size);
		int Search(int *array, int element, int size);
	};

Пример использования класса:

.. code-block:: cpp
	
	try {
        	DichotomySearch example1;
        	example1.Search(array, element, size);
    	} catch (int e) {
        	if (e == ELEM_NOT_FOUND)
            		printf("Element not found!\n");
        	else if(e == TOO_SMALL_ARRAY)
            		printf("Error! Size of array < 1 \n");
        	else
            		printf("Index of search element: %d",e+1);
    	} catch (...) {
        	printf("Other Error!");
   	}


