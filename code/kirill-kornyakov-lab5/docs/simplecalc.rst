Кирилл Корняков: Простой калькулятор
====================================

Класс ``SimpleCalculator`` предназначен для осуществления простых арифметических
операций. Он предоставляет методы для сложения и вычитания целых чисел.


.. code-block:: cpp

    class SimpleCalculator
    {
    public:
        SimpleCalculator();
        virtual ~SimpleCalculator();

        int Add(int a, int b);
        int Sub(int a, int b);
    };
