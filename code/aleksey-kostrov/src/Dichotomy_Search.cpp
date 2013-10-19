#include "Dichotomy_Search.h"

Dichotomy_Search::Dichotomy_Search()
{
}
Dichotomy_Search::Dichotomy_Search(int array_size, int search_element)
{
	if (array_size < 1) throw -2;
	this->array_size = array_size;
	this->search_element = search_element;
	srand(time(NULL));
	Array = new int *[array_size];
	for (int i = 0; i < array_size; i++)
	{
		Array[i] = new int[2];
		Array[i][0] = i;
		Array[i][1] = rand()%50+1;
	}
	if(array_size < 21)
	{
		printf("Generated array: ");
		for (int i = 0; i < array_size; i++)
		{
			printf("%d ",Array[i][1]);
		}
		printf("\n");
	}
	printf("Search element: %d\n",search_element);
}

Dichotomy_Search::~Dichotomy_Search()
{
}

void Dichotomy_Search::Sort_Count()
{
	int min = Array[0][1], max = Array[0][1];
	for (int i = 1; i < array_size; i++) 
	{
		if (Array[i][1] < min)
			min = Array[i][1];
		else if (Array[i][1] > max)
			max = Array[i][1];
	}
	int *C = new int[max - min + 1];
	int **B = new int*[array_size];
	for(int i = 0; i < array_size; i++)
		B[i] = new int[2];

	for (int i = 0; i < (max - min + 1); i++)
		C[i] = 0;
	for (int i = 0; i < array_size; i++)
		C[ Array[i][1] - min ]++;
	for (int i = 1; i < (max - min + 1); i++)
		C[i] += C[i - 1];
	for (int i = 0; i < array_size; i++)
	{
		B[ C[ Array[i][1] - min ] - 1 ][1] = Array[i][1];
		B[ C[ Array[i][1] - min ]-- - 1 ][0] = Array[i][0];
	}
	for (int i = 0; i < array_size; i++)
	{
		Array[i][1] = B[i][1];
		Array[i][0] = B[i][0];
	}
	for(int i = 0; i < array_size; i++)
		delete [] B[i];
	delete [] B;
	delete [] C;
}
int Dichotomy_Search::Search()
{
	Sort_Count();
	int left_border, right_border, middle;
	left_border = 0;
	right_border = array_size - 1;
	while(1)
	{
		middle = (left_border + right_border)/2;
		if(search_element < Array[middle][1])
			right_border = middle - 1;
		else if(search_element > Array[middle][1])
			left_border = middle + 1;
		else
			throw Array[middle][0];
		if (left_border > right_border)
			throw  -1;
	}
}

