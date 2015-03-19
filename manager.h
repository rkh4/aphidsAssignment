#ifndef _manager_h_
#define _manager_h_
#include <vector>
#include "bug.h"

using namespace std;

class manager {
private:
	int board_x = 0;
	int board_y = 0;
	vector<aphid> aphids;
	vector<ladybug> lBugs;
	vector<aphid> newAphids;
public:
	manager(); //Default constructor
	manager(vector<aphid> createAphids,vector<ladybug> createLadybugs, int board_x, int board_y);
	void printBoard();
	void updateGrid();
	//~manager(); //Destructor
};


#endif