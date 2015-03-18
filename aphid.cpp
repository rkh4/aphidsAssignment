using namespace std;
#include "bug.h"
#include "manager.h"
#include <stdlib.h>
#include <iostream>

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

int aphid::getX() {
	return this->pos[0];
}

int aphid::getY() {
	return this->pos[1];
}

void aphid::moveDirection() {
	int rand2 = rand() % 8;
	switch (rand2) {
	case(0) :
		//Decrement Y by 1, moving up
		this->pos[0]--;
		break;
	case(1) :
		//Decrement Y, Incriment X, move up-right
		this->pos[0]--;
		this->pos[1]++;
		break;
	case(2) :
		//Increment X, move right
		this->pos[1]++;
		break;
	case(3) :
		//move right-down
		this->pos[0]++;
		this->pos[1]++;
		break;
	case(4) :
		//move down
		this->pos[0]++;
		break;
	case(5) :
		//move left-down
		this->pos[0]++;
		this->pos[1]--;
	case(6) :
		//move left
		this->pos[1]--;
	case(7) :
		//move left-up
		this->pos[0]--;
		this->pos[1]--;
	}
};

void aphid::update(){
	//Pm = Man.get_a_Pm(); //hold own probability
	//int rand1 = rand() % (10);
	//if ((Pm) <= rand1) {
	//	cout << "Aphid moved" << endl;
		moveDirection();
	//}
	//else {
	//	cout << "Aphid did not move" << endl;
	//}
};