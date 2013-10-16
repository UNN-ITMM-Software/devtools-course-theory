#include <string>
#include <stdlib.h>
#include <stack>
enum NumSystem
{
	hex,oct,dec,bin
};
std::string dec_to_bin(int dec_number);
class NumConverter
{
private:
	NumSystem NumSys;
	std::string Value;
public:
	NumConverter(NumSystem numsys, std::string value);
	~NumConverter();
	std::string GetValue();
	void ToHex();
	void ToOctal();
	void ToDecimal();
	void ToBinary();
};
