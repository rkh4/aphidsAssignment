#ifndef _manager_h_
#define _manager_h_
#include <vector>
#include "bug.h"

using namespace std;

class manager {
private:
	int board_x = 0;			//Initialising the board width
	int board_y = 0;			//Initialising the board height
	vector<aphid> aphids;		//Vector of all aphids
	vector<ladybug> lBugs;		//Vector of all ladybugs
	vector<aphid> newAphids;	//Temporary vector of aphids for when reproduction takes place
	vector<ladybug> newlBugs;	//Temporary ladybug vector, holding all newborns
	vector<aphid> delAphid;
	vector<ladybug> delLBug;
public:
	manager(); //Default constructor
	manager(vector<aphid> createAphids,vector<ladybug> createLadybugs, int board_x, int board_y);
	void printBoard();
	void updateGrid();
	//~manager(); //Destructor
};


#endif