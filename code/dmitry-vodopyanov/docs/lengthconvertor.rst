Дмитрий Водопьянов: Конвертор длин
==================================

Класс ``LengthConvertor`` предназначен для конвертации одной меры длины в другую.
Метод ``Convertor`` переводит из любой единицы измерения в любую. Он имеет один параметр - структуру ``Length``, состоящую из числа типа double и двух переменных перечисляемого типа - изначальная единица измерения, и единица измерения, в которую нужно перевести.


.. code-block:: cpp

    #pragma once
    enum Unit {Inch, Foot, Yard, Mile, Meter, KMeter, CMeter};
    struct Length
    {
        double num;
        Unit UnitInput;
        Unit UnitOutput;
    };
    class LengthConvertor
    {
    public:
        LengthConvertor(void);
        virtual ~LengthConvertor(void);
        static Length Convertor(Length data);
    };


Примером использования класса в пользовательском C++ коде может служить нижеследующий код:


.. code-block:: cpp

    LengthConvertor convertor;
    Length lengthconv;
    lengthconv.num = 10;
    lengthconv.UnitInput = Inch;
    lengthconv.UnitOutput = Meter;
    convertor.Convertor(lengthconv);