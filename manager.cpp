using namespace std;
#include <iostream>
#include "manager.h"

void manager::set_a_Pm(float temp_pm){
	this->a_Pm = temp_pm;
}

void manager::set_a_pALb(float temp_pALb){
	this->a_pALb = temp_pALb;
}

void manager::set_a_pALn(float temp_pALn){
	this->a_pALn = temp_pALn;
}

void manager::set_a_Pb(float temp_Pb){
	this->a_Pb = temp_Pb;
}

float manager::get_a_Pm(){
	return this->Pm;
}

float manager::get_a_pALb(){
	return this->pALb;
}

float manager::get_a_pAln(){
	return this->pALn;
}

float manager::get_a_Pb(){
	return this->Pb;
}

