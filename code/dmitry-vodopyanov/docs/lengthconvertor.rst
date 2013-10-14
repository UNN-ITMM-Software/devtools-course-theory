Дмитрий Водопьянов: Конвертор длин
==================================

Класс ``LengthConvertor`` предназначен для конвертации одной меры длины в другую.
Метод ``Convertor`` переводит из любой единицы измерения в любую. Он имеет один параметр -
структуру ``Length``, состоящую из числа типа double и двух переменных перечисляемого типа -
изначальная единица измерения, и единица измерения, в которую нужно перевести.


.. code-block:: cpp

    enum Unit {Inch, Foot, Yard, Mile, Meter, KMeter, CMeter};
    struct Length
    {
        double value;
        Unit UnitInput;
    };
    class LengthConvertor
    {
    public:
        LengthConvertor(void);
        virtual ~LengthConvertor(void);
        Length Convert(Length length, Unit UnitOutput);
    };


Примером использования класса в пользовательском C++ коде может служить нижеследующий код:


.. code-block:: cpp

    LengthConvertor convertor;
    Length length;
    length.value = 10;
    length.UnitInput = Inch;
    Unit UnitOutput = Meter;
    Length temperatureOutput = convertor.Convert(length, UnitOutput);