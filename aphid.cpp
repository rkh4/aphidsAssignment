using namespace std;
#include "bug.h"
#include "manager.h"

//Derived class of Bug

float Pm;
manager Man;

aphid::aphid(){
	pos[0] = 0; //X
	pos[1] = 0; //Y
};

void aphid::setPos(int temp_x,int temp_y) {
	temp_x = pos[0]; //X
	temp_y = pos[1]; //Y
}

int aphid::getX() {
	return this->pos[0];
}

int aphid::getY() {
	return this->pos[1];
}

int aphid::moveDirection() {
	/*Pm = Man.getPm();
	if (Pm) {
		int randNo = rand() % 8;
		switch (randNo) {
			case(0) :
				//move up things
				return 0;
				break;
			case(1) :
				//move up-right things
				return 0;
				break;
			case(2) :
				//move right things
				return 0;
			case(3) :
				//move right-down things
				return 0;
			case(4) :
				//move down things
				return 0;
			case(5) :
				//move left-down things
				return 0;
			case(6) :
				//move left things
				return 0;
			case(7) :
				//move left-right things
				return 0;
			default:
				return 0;
		}
	}*/
	return 0;
};

void aphid::update(){
		
};