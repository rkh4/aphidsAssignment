using namespace std;
#include <iostream>
#include "manager.h"

void manager::setPm(float temp_pm){
	this->Pm = temp_pm;
}

void manager::setpALb(float temp_pALb){
	this->pALb = temp_pALb;
}

void manager::setpALn(float temp_pALn){
	this->pALn = temp_pALn;
}

void manager::setPb(float temp_Pb){
	this->Pb = temp_Pb;
}

float manager::getPm(){
	return this->Pm;
}

float manager::getpALb(){
	return this->pALb;
}

float manager::getpAln(){
	return this->pALn;
}

float manager::getPb(){
	return this->Pb;
}

	//.	..listOfCreatuesAlive
	/*
	update(); //each creature one at a time (loop)
	delete(x, y); //(kill) creature(pass x,y, kill that one. later pass ID no?)
	new();	  //create creature
	moveCreatureWhenToldTo(setLocation_x, setLocation_y);
	*/