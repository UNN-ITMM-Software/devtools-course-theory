#pragma once

enum INPUT_TYPE { RANDOM, MANUAL };
class Dichotomy_Search
{
public:
	Dichotomy_Search();
	Dichotomy_Search(INPUT_TYPE Type, int Array_Size, int Search_Element);
	virtual ~Dichotomy_Search();
    void Count_Sort();
    int Search();
private:
	int ** Array, Array_Size, Search_Element;
	int Array_Size;
	void Array_Initialization(int ** Array, int Array_Size, INPUT_TYPE Type);
};

