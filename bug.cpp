using namespace std;
#include <utility>
#include "bug.h"

//File in which all bug info held, has both ladybird and aphid extend it

//Default constructor values
bug::bug() {
	pos[0] = 0;
	pos[1] = 0;
}

void setX(int x_pos) {

}

void setY(int y_pos) {

}

int getX() {
	return this->pos[0];
}

int getY() {
	return this->pos[1];
}

pair<int,int> getPos() {
	tempPos(getX,getY);
	return tempPos;
}





//seudo shit
/*class bug2{  //shared creature interface
	int x, y; //The creatures current location
	update(){ //update themselves
		move(rand functions, if move, what direction);
		Tell manager where they moved to.
			which creature they have killed(in same cell), if any. delete(x, y);
		if new creature needs to be created. new(x, y);
	}
}
*/