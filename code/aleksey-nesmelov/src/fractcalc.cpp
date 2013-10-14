#include "iostream"

using namespace std;

class Fraction
{
 private :
   int numenator;
   int denominator;

   int NOD()
  {
     int a=abs(numenator);
     int b=abs(denominator);

     if(a!=0&&b!=0)
     { 
	 while(a%b!=0&&b%a!=0)
         {
	    if(a>b) 
               a=a%b;
            else 
               b=b%a;
         }

            if(a>b)
            return b;
            return a;
     }
      else
      {
       if(a==0&&b==0)
       return 1;
       else
	if(a==0)
		return b;
	else
		return a;

      }
   }

void Cut_Fraction()
{
 int nod=NOD();

 numenator=numenator/nod;
 denominator=denominator/nod;
}

 public:

Fraction (int _numenator=0,int _denominator=1)
{
 numenator=_numenator;
 denominator=_denominator;

if(denominator<0)
{numenator=-numenator;
 denominator=abs(denominator);}
}

virtual ~Fraction() {}

int GetNumenator()
 {
	return numenator;
 }
int GetDenominator()
 {
	 return denominator;
 }
void SetNumenator(int new_numenator)
 {
	 numenator=new_numenator;
 }
void SetDenominator(int new_denominator)
 {
	 denominator=new_denominator;
 }



static Fraction Add(Fraction a,Fraction b)
{
 Fraction res(a.numenator*b.denominator+a.denominator*b.numenator,a.denominator*b.denominator);
 res.Cut_Fraction();
 return res;

}

static Fraction Subtract(Fraction a,Fraction b)
{
 Fraction res(a.numenator*b.denominator-a.denominator*b.numenator,a.denominator*b.denominator);
 res.Cut_Fraction();
 return res;
}


static Fraction Multiply(Fraction a,Fraction b)
{
 Fraction res(a.numenator*b.numenator,a.denominator*b.denominator);
 res.Cut_Fraction();
 if(res.denominator<0)
 {res.numenator=-res.numenator;
 res.denominator=abs(res.denominator);}
 return res;
}

static Fraction Divide(Fraction a,Fraction b)
{
Fraction res(a.numenator*b.denominator,a.denominator*b.numenator);
res.Cut_Fraction();
if(res.denominator<0)
{res.numenator=-res.numenator;
 res.denominator=abs(res.denominator);}
return res;
}

};




