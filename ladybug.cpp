using namespace std;
#include "bug.h"
#include <stdlib.h>
#include <iostream>
//#include <time.h>
#include <stdlib.h>
#include <stdio.h>
//#include <random>
//#include <ctime>

//Derived class of bug

ladybug::ladybug(){
	pos[0] = 0;
	pos[1] = 0;
};

ladybug::ladybug(int Xpos, int Ypos, float moveProb, float changeDir, float aphKill, float giveBirthProb){
	this->pos[0] = Xpos;
	this->pos[1] = Ypos;
	this->lBugMoveProb = moveProb;
	this->changeDirProb = changeDir;
	this->aphKillProb = aphKill;
	this->lBugGiveBirthProb = giveBirthProb;
}


//Chosing ladybugs initial direction, N/E/S/W
int ladybug::newPreferredDirection(){
	int randNo = rand();
	switch (randNo) {
		case(0):
			return 1; //North
			break;
		case(1):
			return 2; //East
			break;
		case(2):
			return 3; //South
			break;
		case(3):
			return 4; //West
			break;
	}
};


//Selects which of the three preffered directions (based on initial) to move.
void ladybug::moveDirection(){
	if (this->preferredDirection == 1){

	}
	else if (this->preferredDirection == 2){

	}
	else if (this->preferredDirection == 3){

	}
	else if (this->preferredDirection == 4){

	}

	/*randNo = rand() % 3;
	switch(randNo){
		case(1):
			return 1; 
			break;
		case(2):
			return 2;
			break;
		case(3):
			return 3;
			break;
	}*/	
}

void ladybug::update(){
	


}