#include "stdio.h"
#include <vector>
#include "../include/mathquancalc.hpp"

using namespace std;

void PrintSelection(vector<MathQuanCalc::SelQuan> selection){
	printf("\n%s", "значения:    ");
	for(int i = 0; i < selection.size(); i++){
			printf("%5.2f ", selection[i].value);
	}
	printf("\n%s", "вероятности: ");
	for(int i = 0; i < selection.size(); i++){
			printf("%5.2f ", selection[i].chance);
	}
}

int main(){
	MathQuanCalc 						mqCalc;
	MathQuanCalc::SelQuan 					sq;
	vector<MathQuanCalc::SelQuan>    selection;

	//создаем и считаем значения для ряда распределения значения выпадающего на игральном кубике
	sq.chance = 1./6.;
	for(int i = 1; i <= 6; i++){
		sq.value = i;
		selection.push_back(sq);
	}
	printf("\n%s", "ряд распределения значения выпадающего на игральном кубике: ");
	PrintSelection(selection);
	if(mqCalc.PutSelection(selection)){
		double expVal = 0.;
		if(mqCalc.GetExpectedValue(&expVal)){
			printf("\n%s %5.2f","Мат. ожидание:", expVal);
		}
		double dispertion = 0.; 
		if(mqCalc.GetDispertion(&dispertion)){
			printf("\n%s %5.2f\n","Дисперсия:", dispertion);
		}
	}
	else{
		printf("\nРяд распределения некорректен!\n");
	}
	selection.clear();

	//создаем и считаем значения для некоторого некорректного ряда распределения
	sq.chance = 1./2.;
	for(int i = 1; i <= 3; i++){
		sq.value = i;
		selection.push_back(sq);
	}
	printf("\n%s", "Некоторый некорректный ряд распределения: ");
	PrintSelection(selection);
	if(mqCalc.PutSelection(selection)){
		double expVal = 0.;
		if(mqCalc.GetExpectedValue(&expVal)){
			printf("\n%s %5.2f","Мат. ожидание:", expVal);
		}
		double dispertion = 0.; 
		if(mqCalc.GetDispertion(&dispertion)){
			printf("\n%s %5.2f\n","Дисперсия:", dispertion);
		}
	}
	else{
		printf("\nРяд распределения некорректен!\n");
	}


	return 0;
}