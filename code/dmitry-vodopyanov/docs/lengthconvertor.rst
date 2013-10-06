Дмитрий Водопьянов: Конвертор длин
==================================

Класс ``LengthConvertor`` предназначен для конвертации одной меры длины в другую.
Каждый метод конвертирует любую величину в указанную. К примеру, метод ``ToInch`` переводит любую величину в дюймы. Каждый метод, кроме метода ``help``, имеет в параметрах число типа double, которое нужно перевести в другую единицу измерения, а также изначальную единицу измерения, выраженную строкой типа char*. Эти методы возвращает значение типа double.


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
        LengthConvertor();
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