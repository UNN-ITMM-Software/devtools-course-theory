#include <string>
#include <stdlib.h>
#include <stack>
enum NumSystem
{
	hex,octal,decimal,binary
};
std::string dec_to_bin(int dec_number);
class NumConverter
{
private:
	NumSystem NumSys;
	std::string Value;
public:
	NumConverter(NumSystem myNumSys, std::string myValue);
	~NumConverter();
	std::string GetValue();
	int ToHex();
	int ToOctal();
	int ToDecimal();
	int ToBinary();
};
