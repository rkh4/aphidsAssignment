#ifndef _bug_h_
#define _bug_h_

using namespace std;
#include <utility>

//Base class
class bug {
private:
public:
	bug();
	int pos[2]; //x,y
	int x_pos = pos[0]; //x
	int y_pos = pos[1]; //y
	void setX(int x_pos);
	void setY(int y_pos);
	int getX();
	int getY();
	void update();
	//~bug(); //got to impliment if you include
};


class aphid : public bug {
private:
	float moveProb = 0.0;
	float lbugKillProb = 0.0;
	float helpKillProb = 0.0;
	float aphGiveBirthProb = 0.0;
public:
	aphid(); //Default constructor
	//~aphid(); //Destructor
	aphid(int Xpos, int Ypos, float moveProb, float lbugKillProb, float helpKillProb, float aphGiveBirthProb);
	int getX();
	int getY();
	void setPos(int, int);
	void moveDirection();
	void update();
	//~aphid();
};

class ladybug : public bug {
//private:
//	int pos[2];
public:
	ladybug();
	void setPos(int, int);
	int getX();
	int getY();
	int initialDirection();
	void moveDirection();
	void update();	
	//~ladybug();
};

#endif