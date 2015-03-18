#ifndef _bug_h_
#define _bug_h_

using namespace std;
#include <utility>

//Base class
class bug {
public:
	bug();
	int pos[2]; //x,y
	int x_pos = pos[0]; //x
	int y_pos = pos[1]; //y
	void setX(int x_pos);
	void setY(int y_pos);
	int getX();
	int getY();
	pair<int, int> getPos();
	void update();
	//~bug(); //got to impliment if you include
};


class aphid : public bug {
private:

public:
	aphid();
	void setPos(int,int);
	int getX();
	int getY();
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
	int moveDirection();
	void update();	
	//~ladybug();
};

#endif