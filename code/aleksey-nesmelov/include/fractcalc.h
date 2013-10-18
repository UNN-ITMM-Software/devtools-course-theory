class Fraction
{
 private :

   int numenator;
   int denominator;
   int NOD() ;
   void Cut_Fraction();

 public:

   Fraction (int _numenator,int _denominator);
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

