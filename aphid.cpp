using namespace std;
#include "bug.h"
#include "manager.h"

//Derived class of Bug

float Pm;
manager Man;

aphid::aphid(){
	pos[0] = 0;
	pos[1] = 0;
};




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