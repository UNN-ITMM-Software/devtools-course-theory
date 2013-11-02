// devtools-course task 1.cpp : Defines the entry point for the console application.
//
#include "NumConverter.h"
#include <iostream>

int main(int argc, char* argv[])
{
	std::cout << "This is a number converter application" << std::endl;
	NumConverter a(hex, "1f");
	std::cout << a.GetValue() << " in hex" << std::endl;
	std::cout << "Is " << a.ToOctal() << " in oct" << std::endl;
	std::cout << "Is " << a.ToDecimal() << " in dec" << std::endl;
	std::cout << "Is " << a.ToBinary() << " in bin" << std::endl << std::endl;
	NumConverter b(oct, "17");
	std::cout << b.GetValue() << " in oct" << std::endl;
	std::cout << "Is " << b.ToHex() << " in hex" << std::endl;
	std::cout << "Is " << b.ToDecimal() << " in dec" << std::endl;
	std::cout << "Is " << b.ToBinary() << " in bin" << std::endl << std::endl;
	NumConverter c(dec, "199");
	std::cout << c.GetValue() << " in dec" << std::endl;
	std::cout << "Is " << c.ToHex() << " in hex" << std::endl;
	std::cout << "Is " << c.ToOctal() << " in oct" << std::endl;
	std::cout << "Is " << c.ToBinary() << " in bin" << std::endl << std::endl;
	NumConverter d(bin, "11101011");
	std::cout << d.GetValue() << " in bin" << std::endl;
	std::cout << "Is " << d.ToHex() << " in hex" << std::endl;
	std::cout << "Is " << d.ToOctal() << " in oct" << std::endl;
	std::cout << "Is " << d.ToDecimal() << " in dec" << std::endl << std::endl;
	return 0;
}