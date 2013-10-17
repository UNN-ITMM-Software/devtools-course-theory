#pragma once

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

