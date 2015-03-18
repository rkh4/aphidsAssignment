using namespace std;
#include <utility>
#include "bug.h"

//Base class for Aphid & Ladybug

//Default constructor values
bug::bug() {

}

int bug::getX() {
	return this->pos[0];
}

int bug::getY() {
	return this->pos[1];
}

/*pair<int,int> getPos() {
	pair<int,int> tempPos(getX(),getY());
	return tempPos;

}*/