using namespace std;
#include "bug.h"

int randNo = 0;

//Derived class of bug
ladybug::ladybug(){
	//hold positions
	int initialDirection = 0; //set default value
	int moveDirection = 0;
};


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