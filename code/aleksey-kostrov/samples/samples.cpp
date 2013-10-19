#include "Dichotomy_Search.h"
int main()
{
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
	catch (...)
	{
		printf("Other Error!");
	}
    return 0;
}
