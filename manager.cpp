#include <iostream>
#include <vector>
#include "manager.h"
#include "bug.h"
using namespace std;

//-----------------------DEFEAULT CONSTRUCTOR--------------------
manager::manager(){

}

//--------------------SETTING LOCAL VARIABLES--------------------
//Takes parameters from main, sets the local variables
manager::manager(vector<aphid> createAphids, vector<ladybug> createLadybugs, int board_x, int board_y){
	this->board_x = board_x; //The width of the board
	this->board_y = board_y; //The height of the board
	aphids = createAphids;	 //Creates a local instance of the aphids vector
	lBugs = createLadybugs;	 //Creates a local instance of the ladybugs vector
}

//----------------------PRINTS BOARD-----------------------------
void manager::printBoard(){
	//Creates vector of vectors (2d board) the size the the read-in file defines
	vector<string> x(board_x, "[  ]");
	vector<vector<string> > board(board_y, x);

	int noAphids = 0;
	int nolBugs = 0;

	//Loops, and cell checks
	cout << endl << "---------------------------------------------------" << endl;
	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[i].size(); j++){
			for (vector<aphid>::iterator ai = aphids.begin(); ai != aphids.end(); ai++){
				if ((*ai).getX() == i && (*ai).getY() == j){
					noAphids++;
				}
			}
			for (vector<ladybug>::iterator li = lBugs.begin(); li != lBugs.end(); li++){
				if ((*li).getX() == i && (*li).getY() == j){
					nolBugs++;
				}

			}
			if (noAphids >= 1 && nolBugs >= 1) {
				cout << "|" << noAphids << "A" << nolBugs << "L";
			}
			else if (noAphids >= 1) {
				cout << "|" << noAphids << "A  ";
			}
			else if (nolBugs >= 1){
				cout << "|  " << nolBugs << "L";
			}
			else {
				cout << "|    ";
			}
			noAphids = 0;
			nolBugs = 0;
		}
		cout << "|" << endl << "---------------------------------------------------" << endl;
	}
}

//----------------------UPDATE METHOD----------------------------
void manager::updateGrid(){
	//Iterates through vector of aphid objects, updating each in turn
	for (vector<aphid>::iterator AphIt = this->aphids.begin(); AphIt != this->aphids.end(); AphIt++){
		(*AphIt).update(board_x,board_y);
	}
	for (vector<ladybug>::iterator lBugIt = this->lBugs.begin(); lBugIt != this->lBugs.end(); lBugIt++){
		(*lBugIt).newPreferredDirection();
	}
	//iterate through ladybugs
	//call newPreferredDirection
	//call update
	printBoard();
	cin.get();
	updateGrid();
}