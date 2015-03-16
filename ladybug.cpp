using namespace std;
#include "bug.h"

int initialDirection = 1; //set defeualt value
int moveDirection = 1;
int randNo = 0;

ladybug::ladybug(){
	//hold positions
};


//Chosing ladybugs initial direction, N/E/S/W
ladybug::initialDirection(){
	randNo = math.floor((math.rand()*4)+1);
	switch (randNo) {
		case(1):
			initialDirection = 1; //North
			break;
		case(2):
			initialDirection = 2; //East
			break;
		case(3);
			initialDirection = 3; //South
			break;
		case(4):
			initialDirection = 4; //West
			break;
	}
};

//Selects which of the three preffered directions (based on initial) to move.
ladybug::moveDirection(){
	randNo = math.floor((math.rand()*3)+1);
	switch(randNo){
		case(1):
			moveDirection = 1; 
			break;
		case(2):
			moveDirection = 2;
			break;
		case(3):
			moveDirection = 3;
			break;
	}	
}