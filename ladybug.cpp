using namespace std;
#include "bug.h"

int randNo = 0;

//Derived class of bug
ladybug::ladybug(){
	//hold positions
	//int initialDirection = 0; //set default value
	//int moveDirection = 0;
};

void ladybug::setPos(int temp_x, int temp_y)
{
	this->pos[0] = temp_x;
	this->pos[1] = temp_y;
}

int ladybug::getX(){
	return this->pos[0];
}

int ladybug::getY(){
	return this->pos[1];
}


//Chosing ladybugs initial direction, N/E/S/W
int ladybug::initialDirection(){
	/*randNo = rand() % 4;
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
	}*/
	return 0;
};


//Selects which of the three preffered directions (based on initial) to move.
int ladybug::moveDirection(){
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
	return 0;
}

void update(){

}