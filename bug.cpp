using namespace std;
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