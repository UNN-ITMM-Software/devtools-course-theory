Несмелов Алексей:  Калькулятор дробей (с использованием НОД)
============================================================

Класс ``Fraction`` предназначен для осуществления простых арифметических
операций над обыкновенными дробями. Он предоставляет возможность складывать,вычитать,умножать и делить обыкновенные дроби.


 .. code-block:: cpp

       class Fraction
    {
      private :

       int numenator;
       int denominator;
       int NOD() ;
       void Cut_Fraction();

      public:

       Fraction (int _numenator=0,int _denominator=1);
       virtual ~Fraction();

       int GetNumenator();
       int GetDenominator();
       void SetNumenator(int new_numenator);
       void SetDenominator(int new_denominator);

       static Fraction Add(Fraction a,Fraction b);
       static Fraction Subtract(Fraction a,Fraction b);
       static Fraction Multiply(Fraction a,Fraction b);
       static Fraction Divide(Fraction a,Fraction b);
   
    };


Пример использования класса ``Fraction`` в пользовательском С++ коде:


 .. code-block:: cpp

    Fraction fract_1(5,6);
    Fraction fract_2(-10,7);
    Fraction result_fract;
    result_fract=Fraction::Add(d1,d2);