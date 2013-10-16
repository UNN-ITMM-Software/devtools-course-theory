#include "stdio.h"
#include <vector>
#include "../include/mathquancalc.hpp"

using namespace std;

int main(){
	MathQuanCalc 						mqCalc;
	MathQuanCalc::SelQuan 					sq;
	vector<MathQuanCalc::SelQuan>    selection;

	sq.chance = 1./6.;
	for(int i = 1; i <= 6; i++){
		sq.value = i;
		selection.push_back(sq);
	}
	if(mqCalc.PutSelection(selection)){
		double expVal = 0.;
		if(mqCalc.GetExpectedValue(&expVal)){
			printf("\n%s %5.2f\n","Expected value:", expVal);
		}
		double dispertion = 0.; 
		if(mqCalc.GetDispertion(&dispertion)){
			printf("\n%s %5.2f\n","Dispertion value:", dispertion);
		}
	}
	else{
		printf("\nSomething went wrong!\n");
	}
	return 0;
}