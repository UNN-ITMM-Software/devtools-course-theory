#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

