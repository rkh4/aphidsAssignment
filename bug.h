#ifndef _bug_h_
#define _bug_h_

using namespace std;
#include <utility>

//Base class
class bug {
private:
public:
	bug();
	int pos[2]; //X then Y
	int getX();
	int getY();
	void update();
	//~bug(); //Destructor
};

//------------------APHID CLASS ------------------------
class aphid : public bug {
private:
	
public:
	float moveProb = 0.0;
	float lbugKillProb = 0.0;
	float helpKillProb = 0.0;
	float aphGiveBirthProb = 0.0;
	aphid(); //Default constructor
	aphid(int Xpos, int Ypos, float moveProb, float lbugKillProb, float helpKillProb, float aphGiveBirthProb);
	float getlBugKillProb(); //pointless now?  check
	float getGiveBirthProb(); 
	void moveDirection(int board_x, int board_y);
	void update(int board_x, int board_y);
	//~aphid(); //Destructor
};


//------------------LADYBUG CLASS-----------------------
class ladybug : public bug {
private:
	int preferredDirection = 0;
public:
	float lBugMoveProb = 0.0;
	float changeDirProb = 0.0;
	float aphKillProb = 0.0;
	float lBugGiveBirthProb = 0.0;
	ladybug(); //Defeault constructor
	ladybug(int Xpos, int Ypos, float moveProb, float changeDir, float aphKill, float giveBirthProb);
	void newPreferredDirection();
	float getGiveBirthProb();
	void moveDirection(int board_x, int board_y);
	void update(int board_x, int board_y);
	//~ladybug(); //Destructor
};

#endif