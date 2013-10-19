Костров Алексей: Поиск методом "Дихотомии"
===========================================

Класс ``Dichotomy_Search`` предназначен для поиска элемента в массиве методом "Дихотомии".
Он предоставляет метод для предподготовки(сортировка массива) и 
последующей обработки(поиск индекса желаемого элемента) входящих данных, а именно числового массива.
В результате работы, данный метод класса выводит на экран индекс искомого элемента поиска или сообщает что такого нет.

.. code-block:: cpp

	class Dichotomy_Search
	{
	public:
		Dichotomy_Search();
		Dichotomy_Search(int size, int elem);
		virtual ~Dichotomy_Search();
		void Sort_Count();
		int Search();
	private:
		int ** Array, array_size, search_element;
	};

Пример использования класса:

.. code-block:: cpp
	
	try
	{
		Dichotomy_Search example_1(30,9);
		example_1.Search();
	}
	catch (int e)
	{
		if (e==-1) printf("Element not found!\n");
		else if(e==-2) printf("Error! Size of array < 1 \n");
		else printf("Index of search element: %d",e+1);
	}


