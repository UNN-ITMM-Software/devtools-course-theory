#include "stdio.h"
#include "mathquancalc.hpp"

using namespace std;

void PrintSample(vector<MathQuanCalc::Event> sample){
	printf("\n%s", "значения:    ");
	for(int i = 0; i < sample.size(); i++){
			printf("%5.2f ", sample[i].value);
	}
	printf("\n%s", "вероятности: ");
	for(int i = 0; i < sample.size(); i++){
			printf("%5.2f ", sample[i].probability);
	}
}

void MakeCalc(MathQuanCalc& mqCalc, vector<MathQuanCalc::Event>& sample){
	try{
		mqCalc.PutSample(sample);
		double expVal = 0.;
		try{
			expVal = mqCalc.GetExpectedValue();
			printf("\n%s %5.2f","Мат. ожидание:", expVal);
		}
		catch(string& str){
			printf("\n%s\n", str.c_str());			
		}
		double dispersion = 0.; 
		try{
			dispersion = mqCalc.GetDispersion();
			printf("\n%s %5.2f\n","Дисперсия:", dispersion);
		}
		catch(string& str){
			printf("\n%s\n", str.c_str());			
		}
	}
	catch(string& str){
			printf("\n%s\n", str.c_str());			
	}
}

int main(){
	MathQuanCalc mqCalc;
	MathQuanCalc::Event	event;
	vector<MathQuanCalc::Event>	sample;

	//создаем и считаем значения для ряда распределения значения выпадающего на игральном кубике
	event.probability = 1./6.;
	for(int i = 1; i <= 6; i++){
		event.value = i;
		sample.push_back(event);
	}
	printf("\n%s", "ряд распределения значения выпадающего на игральном кубике: ");
	PrintSample(sample);
	MakeCalc(mqCalc, sample);
	sample.clear();

	//создаем и считаем значения для некоторого некорректного ряда распределения
	event.probability = 1./2.;
	for(int i = 1; i <= 3; i++){
		event.value = i;
		sample.push_back(event);
	}
	printf("\n%s", "Некоторый некорректный ряд распределения: ");
	PrintSample(sample);
	MakeCalc(mqCalc, sample);
	return 0;
}