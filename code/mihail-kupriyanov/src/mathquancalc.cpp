#include "stdio.h"
#include "../include/mathquancalc.hpp"
#include <math.h>

MathQuanCalc::MathQuanCalc(){
	selection_status = false;
}
MathQuanCalc::MathQuanCalc(const MathQuanCalc& mqcalc){
	selection = mqcalc.selection;
}
MathQuanCalc::~MathQuanCalc(){

}
bool MathQuanCalc::PutSelection(const std::vector<SelQuan>& in_selection){
	selection = in_selection;

	if(!selection.size())
		return selection_status = false;

	double chance = 0.;
	for(int i = 0; i < selection.size(); i++){
		chance += selection[i].chance;
		if(chance > 1)
			return selection_status = false;

		for(int j = 0; j < selection.size(); j++){
			if(j == i)
				continue;
			if(selection[j].value == selection[i].value)
				return selection_status = false;
		}
	}
	if(fabs(chance - 1.) > 1.0E-10)
		return selection_status = false;
	return selection_status = true;
}
std::vector<MathQuanCalc::SelQuan> MathQuanCalc::GetSelection(){
	return selection;
}
bool MathQuanCalc::GetExpectedValue(double* value){
	return GetPrimaryMoment(value, 1);
}
bool MathQuanCalc::GetDispertion(double* value){
	return GetCentralMoment(value, 2);
}
bool MathQuanCalc::GetPrimaryMoment(double* value, int level){
	if(!GetSelectionStatus())
		return false;

	double moment = 0;
	for(int i = 0; i < selection.size(); i++){
		moment += pow(selection[i].value, (double)level) * selection[i].chance; 
	}
	*value = moment;
	return true;
}
bool MathQuanCalc::GetCentralMoment(double* value, int level){
	double moment = 0;
	double expVal = 0;
	if(!GetPrimaryMoment(&expVal, 1))
		return false;

	for(int i = 0; i < selection.size(); i++){
		moment += pow(selection[i].value - expVal, (double)level) * selection[i].chance; 
	}
	*value = moment;
	return true;
}
bool MathQuanCalc::GetSelectionStatus(){
	return selection_status;
}
