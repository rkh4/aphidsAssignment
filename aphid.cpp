using namespace std;
#include "bug.h"
#include "manager.h"
#include <iostream>
#include <time.h>
#include <stdlib.h>

//Derived class of Bug

float Pm;

//-----------------------DEFAULT CONSTRUCTOR-----------------------
aphid::aphid(){
	pos[0] = 0;
	pos[1] = 0;

}

//--------------------SET LOCAL OBJECT VARIABLES-------------------
aphid::aphid(int Xpos, int Ypos, float moveProb, float lbugKillProb, float helpKillProb, float aphGiveBirthProb){
	this->pos[0] = Xpos;
	this->pos[1] = Ypos;
	this->moveProb = moveProb;
	this->lbugKillProb = lbugKillProb;
	this->helpKillProb = helpKillProb;
	this->aphGiveBirthProb = aphGiveBirthProb;
}

//----------------CHANGES APHID POSITION------------------------
void aphid::moveDirection(int board_x, int board_y) {
	//Random number, to determine which direction to move
	int moveNum = rand() % 8;

	//Checks if on the left border
	if (this->pos[0] == 1) {
		if (moveNum == 5 || moveNum == 6 || moveNum == 7){
			cout << "Trying to move out of spec, Re-rolling" << endl;
			moveNum = 2;
		}
	}
	//Checks if on the right border
	if (this->pos[0] == (board_x - 1)){
		if (moveNum == 1 || moveNum == 2 || moveNum == 3){
			cout << "Trying to move out of spec, Re-rolling" << endl;
			moveNum = 6;
		}
	}
	//Checks if on the bottom border
	if (this->pos[1] == (board_y - 1)){
		if (moveNum == 3 || moveNum == 4 || moveNum == 5){
			cout << "Trying to move out of spec, Re-rolling" << endl;
			moveNum = 0;
		}
	}
	//Checks if on the top border
	if (this->pos[1] == 1){
		if (moveNum == 7 || moveNum == 0 || moveNum== 1){
			cout << "Trying to move out of spec, Re-rolling" << endl;
			moveNum = 4;
		}
	}

	//Checks the random number, moves aphid accordingly
	switch (moveNum) {
	case(0) :
		//Decrement Y by 1, moving up
		this->pos[1]--;
		break;
	case(1) :
		//Decrement Y, Incriment X, move up-right
		this->pos[1]--;
		this->pos[0]++;
		break;
	case(2) :
		//Increment X, move right
		this->pos[0]++;
		break;
	case(3) :
		//move right-down
		this->pos[1]++;
		this->pos[0]++;
		break;
	case(4) :
		//move down
		this->pos[1]++;
		break;
	case(5) :
		//move left-down
		this->pos[1]++;
		this->pos[0]--;
		break;
	case(6) :
		//move left
		this->pos[0]--;
		break;
	case(7) :
		//move left-up
		this->pos[1]--;
		this->pos[0]--;
		break;
	}
};

float aphid::getlBugKillProb(){
	return this->lbugKillProb;
}

float aphid::getGiveBirthProb(){
	return this->aphGiveBirthProb;
}

//-----------------UPDATES APHID OBJECT-------------------------
void aphid::update(int board_x,int board_y){ 
	int rand1 = rand() % 10;
	if ((this->moveProb*10) >= rand1) {
		cout << "Aphid moved" << endl;
		//int randomNo = rand() % (8);
		moveDirection(board_x, board_y);
	} else {
		cout << "Aphid did not move" << endl;
	}
};