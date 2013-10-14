Костров Алексей: Поиск методом "Дихотомии"
===========================================

Класс ``Dichotomy_Search`` предназначен для поиска элемента в массиве методом "Дихотомии".
Он предоставляет метод для предподготовки(сортировка массива реализована внутри метода ``Sort_Search``) и 
последующей обработки(поиск индекса желаемого элемента) входящих данных, а именно числового массива.
В результате работы, данный метод класса выводит на экран индекс искомого элемента поиска.

.. code-block:: cpp

	enum INPUT_TYPE { RANDOM, MANUAL };

	class Dichotomy_Search
	{
	public:
		Dichotomy_Search();
		Dichotomy_Search(INPUT_TYPE Type, int Array_Size, int Search_Element);
		virtual ~Dichotomy_Search();
		int Sort_Search();
	private:
		int ** Array, Array_Size, Search_Element; 		
	};

Пример использования класса:

.. code-block:: cpp

	INPUT_TYPE Type;
	int Array_Size, Search_Element;
	printf("Select the type of input: 0-RANDOM, 1-MANUAL\n);
	scanf("%d\n",&Type);
	printf("Enter the size of the array: Array_Size = ");
	scanf("%d\n",&Array_Size);
	printf("Enter element to search ");
        scanf("%d\n",&Search_Element);
	Dichotomy_Search example_of_use(Type, Array_Size, Search_Element);
	printf("Index of search element: %d",example_of_use.Sort_Search());


