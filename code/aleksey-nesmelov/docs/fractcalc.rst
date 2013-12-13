Несмелов Алексей:  Калькулятор дробей (с использованием НОД)
============================================================

Класс ``Fraction`` предназначен для осуществления простых арифметических
операций над обыкновенными дробями. Он предоставляет возможность складывать,вычитать,умножать и делить обыкновенные дроби.


 .. code-block:: cpp

       class Fraction
    {
        public:
            Fraction(int numenator, int denominator);
            Fraction();
            ~Fraction();

            int GetNumenator();
            int GetDenominator();
            void SetNumenator(int value);
            void SetDenominator(int value);

            Fraction operator+(const Fraction& a) const;
            Fraction operator-(const Fraction& a) const;
            Fraction operator*(const Fraction& a) const;
            Fraction operator/(const Fraction& a) const;

            bool operator==(const Fraction& a) const;
        private :
            int numenator; 
            int denominator;
            int NOD() ;
            void CutFraction();
   
    };


Пример использования класса ``Fraction`` в пользовательском С++ коде:


 .. code-block:: cpp

    Fraction fract1(5, 6);
    Fraction fract2(-10, 7);
    Fraction resultFract(0, 1);
    resultFract = fract1 + fract2;