#ifndef _bug_h_
#define _bug_h_

using namespace std;
#include <utility>

//Base class
class bug {
private:
public:
	bug();
	int pos[2]; //Position, X then Y coordinate
	int getX(); //Returns the X coordinate
	int getY(); //Returns the Y coordinate
	void update(); //updates the object
	//~bug(); //Destructor
};

//------------------APHID CLASS ------------------------
class aphid : public bug {
private:
	
public:
	//Variable initialisation
	float moveProb = 0.0; //Probability that aphid will move
	float lbugKillProb = 0.0; //Probability that it will kill a ladybug
	float helpKillProb = 0.0; //Increase in probability depending on how many aphids
	float aphGiveBirthProb = 0.0; //Probability aphid will reproduce

	//Methods
	aphid(); //Default constructor
	aphid(int Xpos, int Ypos, float moveProb, float lbugKillProb, float helpKillProb, float aphGiveBirthProb);
	float getGiveBirthProb(); //Returns the probability of reproducing
	void moveDirection(int board_x, int board_y);
	void update(int board_x, int board_y);
	//~aphid(); //Destructor
};


//------------------LADYBUG CLASS-----------------------
class ladybug : public bug {
private:

public:
	//Variable Initialisation
	int preferredDirection = 0; //North/ East/ South/ West
	float lBugMoveProb = 0.0;	//Probability of moving
	float changeDirProb = 0.0;	//Probability that the preferred direction will change
	float aphKillProb = 0.0;	//Probability of killing aphid
	float lBugGiveBirthProb = 0.0; //Probability of giving birth

	//Methods
	ladybug(); //Defeault constructor
	ladybug(int Xpos, int Ypos, float moveProb, float changeDir, float aphKill, float giveBirthProb, int preferredDirection);
	void newPreferredDirection(); 
	float getGiveBirthProb(); //Returns the probability of giving birth
	void moveDirection(int board_x, int board_y);
	void update(int board_x, int board_y);
	//~ladybug(); //Destructor
};

#endif