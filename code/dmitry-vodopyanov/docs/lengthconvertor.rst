Дмитрий Водопьянов: Конвертор длин
==================================

Класс ``LengthConvertor`` предназначен для конвертации одной меры длины в другую.
Каждый метод конвертирует любую величину в указанную. К примеру, метод ``ToInch`` переводит любую величину в дюймы. Каждый метод, кроме метода ``help``, имеет в параметрах число типа double, которое нужно перевести в другую единицу измерения, а также изначальную единицу измерения, выраженную строкой типа char*. Эти методы возвращает значение типа double.


.. code-block:: cpp

    class SimpleCalculator
    #pragma once

    using namespace std;

    class LengthConvertor
    {
    public:
	    LengthConvertor();
	    ~LengthConvertor();

	    void help();
	    double ToInch(double num, char* unit);
	    double ToFoot(double num, char* unit);
	    double ToYard(double num, char* unit);
	    double ToMile(double num, char* unit);
	    double ToMeter(double num, char* unit);
	    double ToKMeter(double num, char* unit);
	    double ToCMeter(double num, char* unit);
    };


Примером использования класса в пользовательском C++ коде может служить нижеследующий код:


.. code-block:: cpp

    LenghtConvertor* convertor;
    double num = 30;
    char* unit = "ML";
    convertor->ToFoot(num, unit);