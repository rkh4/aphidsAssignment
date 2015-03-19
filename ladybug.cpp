using namespace std;
#include "bug.h"

//Derived class of bug

//-----------------------DEFAULT CONSTRUCTOR--------------------
ladybug::ladybug(){
	pos[0] = 0;
	pos[1] = 0;
};

//-----------------SET LOCAL OBJECT VARIABLES-------------------
ladybug::ladybug(int Xpos, int Ypos, float moveProb, float changeDir, float aphKill, float giveBirthProb, int preferredDirection){
	this->pos[0] = Xpos;
	this->pos[1] = Ypos;
	this->lBugMoveProb = moveProb;
	this->changeDirProb = changeDir;
	this->aphKillProb = aphKill;
	this->lBugGiveBirthProb = giveBirthProb;
	this->preferredDirection = preferredDirection;
}

//--------------SETS LADYBUG PREFERRED DIRECTION---------------
void ladybug::newPreferredDirection(){
	int randNo = rand() % 4;
	switch (randNo) {
	case(0) :
		//North
		this->preferredDirection = 1;
		break;
	case(1) :
		//East
		this->preferredDirection = 2;
		break;
	case(2) :
		//South
		this->preferredDirection = 3;
		break;
	case(3) :
		//West
		this->preferredDirection = 4;
		break;
	}
};


//-------------------UPDATES LADYBUG POSITION------------------
void ladybug::moveDirection(int board_x, int board_y){
	//------------------------NORTH-------------------------
	if (this->preferredDirection == 1){
		int subDirection = rand() % 3;
		switch (subDirection) {
		case(0) :
			//Check if on the top border
			if (this->pos[1] <= 0) {
				this->pos[1]++;
				break;
			}
			else {
				//Decrement Y by 1, moving up
				this->pos[1]--;
				break;
			}
			
		case(1) :
			//check if on top border, or right border
			if (this->pos[1] <= 0 || this->pos[0] >= (board_x -1)) {
				this->pos[1]++;
				this->pos[0]--;
				break;
			}
			else {
				//Decrement Y, Incriment X, move up-right
				this->pos[1]--;
				this->pos[0]++;
				break;
			}
	
		case(2) :
			//Check if on top border, or left border
			if (this->pos[1] <= 0 || this->pos[0] <= 0) {
				this->pos[1]++;
				this->pos[0]++;
				break;
			}
			else {
				//Move up-left
				this->pos[1]--;
				this->pos[0]--;
				break;
			}
			
		}
	}

	//------------------------EAST--------------------------
	else if (this->preferredDirection == 2){
		int subDirection = rand() % 3;
		switch (subDirection) {
		case(0) :
			//Check if on right border
			if (this->pos[0] >= (board_y - 1)) {
				this->pos[0]--;
				break;
			}
			else {
				//Move right
				this->pos[0]++;
				break;
			}
			
		case(1) :
			//Check if on right border, or bottom border
			if (this->pos[0] >= (board_y - 1) || this->pos[1] >= (board_x -1)) {
				this->pos[0]--;
				this->pos[1]--;
				break;
			}
			else {
				//Move down-right 
				this->pos[1]++;
				this->pos[0]++;
				break;
			}
			
		case(2) :
			//Check if on right border, or top border
			if (this->pos[0] >= (board_y - 1) || this->pos[1] <= 0) {
				this->pos[0]--;
				this->pos[1]++;
				break;
			}
			else {
				//Move up-right
				this->pos[1]--;
				this->pos[0]++;
				break;
			}
			
		}
	}
	//---------------------SOUTH----------------------------
	else if (this->preferredDirection == 3){
		int subDirection = rand() % 3;
		switch (subDirection) {
		case(0) :
			//Check if on right border, or top border
			if (this->pos[1] >= (board_y -1)) {
				this->pos[1]--;
				break;
			}
			else {
				//Move down
				this->pos[1]++;
				break;
			}
			
		case(1) :
			//Check if on right border, or bottom border
			if (this->pos[0] >= (board_x-1) || this->pos[1] >= (board_y-1)) {
				this->pos[0]--;
				this->pos[1]--;
				break;
			}
			else {
				//Move down-right
				this->pos[0]++;
				this->pos[1]++;
				break;
			}
			
		case(2) :
			//Check if on left border, or bottom border
			if (this->pos[0] <= 0 || this->pos[1] >= (board_y - 1)) {
				this->pos[0]++;
				this->pos[1]--;
				break;
			}
			else {
				//Move down-left
				this->pos[0]--;
				this->pos[1]++;
				break;
			}
			
		}
	}
	//------------------------WEST--------------------------
	else if (this->preferredDirection == 4){
		int subDirection = rand() % 3;
		switch (subDirection) {
		case(0) :
			//Check if on left border
			if (this->pos[0] <= 0) {
				this->pos[0]++;
			}
			else {
				//Move left
				this->pos[0]--;
				break;
			}
			
		case(1) :
			//Check if on left border, or top border
			if (this->pos[0] <= 0 || this->pos[1] <= 0) {
				this->pos[0]++;
				this->pos[1]++;
			}
			else {
				//Move up-left
				this->pos[0]--;
				this->pos[1]--;
				break;
			}
			
		case(2) :
			//Check if on left border, or bottom border
			if (this->pos[0] <= 0 || this->pos[1] >= (board_y - 1)) {
				this->pos[0]++;
				this->pos[1]--;
			}
			else {
				//Move down-left
				this->pos[0]--;
				this->pos[1]++;
				break;
			}
			
		}
	}
}

//Function that returns the probability of giving birth
float ladybug::getGiveBirthProb(){
	return this->lBugGiveBirthProb;
}

//Function that removes life turn-by-turn
//	also checks if the bug is dead or not
bool ladybug::isDead(){
	this->lBugLife -= 10;
	if (this->lBugLife <= 0){
		this->lBugDead = true;
		return true;
	}
	else {
		return false;
	}
}

void ladybug::update(int board_x, int board_y){
	//Checking the probability of the bug moving
	int tempMoveProb = rand() % 10;
	if ((this->lBugMoveProb*10) >= tempMoveProb) {
		//Checking probability that preffered direction changes
		tempMoveProb = rand() % 10;
		if ((this->changeDirProb*10) >= tempMoveProb){
			newPreferredDirection();
			moveDirection(board_x,board_y);
		}
		else {
			moveDirection(board_x,board_y);
		}
	}
}