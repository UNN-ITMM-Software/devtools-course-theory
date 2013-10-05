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

   Fraction operator +(Fraction a);
   Fraction operator -(Fraction a);
   Fraction operator *(Fraction a);
   Fraction operator /(Fraction a);  
   
};

