#include <string>
#include <stdlib.h>
#include <stack>
#include <cmath>
#include <cstdio>

enum NumSystem
{
	hex,oct,dec,bin
};

std::string DecToBin(int decNum);

class NumConverter
{
public:
	NumConverter(NumSystem numsys, std::string value);
	~NumConverter();
	std::string GetValue();
	std::string ToHex();
	std::string ToOctal();
	std::string ToDecimal();
	std::string ToBinary();
private:
	NumSystem NumSys;
	std::string Value;
};
