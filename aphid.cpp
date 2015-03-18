using namespace std;
#include "bug.h"
#include "manager.h"
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <random>
#include <ctime>
//#include <stdlib.h>

//Derived class of Bug

float Pm;

aphid::aphid(){
	pos[0] = 0;
	pos[1] = 0;

}

aphid::aphid(int Xpos, int Ypos, float moveProb, float lbugKillProb, float helpKillProb, float aphGiveBirthProb){
	this->pos[0] = Xpos;
	this->pos[1] = Ypos;
	this->moveProb = moveProb;
	this->lbugKillProb = lbugKillProb;
	this->helpKillProb = helpKillProb;
	this->aphGiveBirthProb = aphGiveBirthProb;
}

void aphid::moveDirection(int board_x, int board_y, int randomNo) {
	//unsigned int randomNum = randomNo;
	randomNo = rand() % 8;

	//Checks if on the left border
	if (this->pos[0] == 1) {
		if (randomNo == 5 || randomNo == 6 || randomNo == 7){
			cout << "Trying to move out of spec, Re-rolling" << endl;
			moveDirection(board_x,board_y, randomNo);
		}
	}
	//Checks if on the right border
	if (this->pos[0] == (board_x - 1)){
		if (randomNo == 1 || randomNo == 2 || randomNo == 3){
			cout << "Trying to move out of spec, Re-rolling" << endl;
			moveDirection(board_x,board_y, randomNo);
		}
	}
	//Checks if on the bottom border
	if (this->pos[1] == (board_y - 1)){
		if (randomNo == 3 || randomNo == 4 || randomNo == 5){
			cout << "Trying to move out of spec, Re-rolling" << endl;
			moveDirection(board_x,board_y, randomNo);
		}
	}
	//Checks if on the top border
	if (this->pos[1] == 1){
		if (randomNo == 7 || randomNo == 0 || randomNo == 1){
			cout << "Trying to move out of spec, Re-rolling" << endl;
			moveDirection(board_x,board_y, randomNo);
		}
	}

	switch (randomNo) {
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

void aphid::update(int board_x,int board_y){ //get update method to take in a value (x,y) so that you can check if at edge of board
	int rand1 = rand() % (10);
	if ((this->moveProb*10) >= rand1) {
		cout << "Aphid moved" << endl;
		int randomNo = rand() % (8);
		moveDirection(board_x, board_y, randomNo);
	} else {
		cout << "Aphid did not move" << endl;
	}
};