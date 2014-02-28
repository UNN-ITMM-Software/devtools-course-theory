#include <BinOctHexCalculator.h>

#include <stdio.h>

int main(){
	BinOctHexCalculator calc;
	Notation notation1 = Hex;
	std::string value1 = "10";
	Notation notation2 = Bin;
	std::string value2 = "1011";
	printf("Here is result of %s + %s: %s\n",value1.c_str(), value2.c_str(), calc.Add(value1, notation1, value2, notation2, Bin).c_str());
	printf("Here is result of %s - %s: %s\n",value1.c_str(), value2.c_str(), calc.Sub(value1, notation1, value2, notation2, Bin).c_str());
	printf("Here is result of %s * %s: %s\n",value1.c_str(), value2.c_str(), calc.Mult(value1, notation1, value2, notation2, Bin).c_str());
	printf("Here is result of %s / %s: %s\n",value1.c_str(), value2.c_str(), calc.Div(value1, notation1, value2, notation2, Bin).c_str());
	return 0;
}