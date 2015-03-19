#include <iostream>
#include <vector>
#include "manager.h"
#include "bug.h"
using namespace std;

//-----------------------DEFEAULT CONSTRUCTOR--------------------
manager::manager(){

}

//--------------------SETTING LOCAL VARIABLES--------------------
//Takes parameters from main, sets the local variables & creates local vectors
manager::manager(vector<aphid> createAphids, vector<ladybug> createLadybugs, int board_x, int board_y){
	this->board_x = board_x; //The width of the board
	this->board_y = board_y; //The height of the board
	aphids = createAphids;	 //Creates a local instance of the aphids vector
	lBugs = createLadybugs;	 //Creates a local instance of the ladybugs vector
	//Initialises the preffered direction of all ladybugs
	for (vector<ladybug>::iterator lBugIt = this->lBugs.begin(); lBugIt != this->lBugs.end(); lBugIt++){
		(*lBugIt).newPreferredDirection();
	}
}

//----------------------PRINTS BOARD-----------------------------
void manager::printBoard(){
	//Creates vector of vectors (2d board) the size the the read-in file defines
	vector<string> x(board_x, "");
	vector<vector<string> > board(board_y, x);

	//Variables hold how many of each bug, in the current cell
	int noAphids = 0;
	int nolBugs = 0;

	//Prints the top line of the board
	cout << endl << "---------------------------------------------------" << endl;
	//Loops through each cell
	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[i].size(); j++){

			//--------------------------APHIDS CHECK---------------------------------------
			//Iterates through vector of aphids, checking if their coordinates match the current cell
			for (vector<aphid>::iterator ai = aphids.begin(); ai != aphids.end(); ai++){
				if ((*ai).getX() == i && (*ai).getY() == j){
					noAphids++; //..if so, they increase the number of aphids in that cell

					//The chance for two aphids to give birth
					if (noAphids > 1) {
						float giveBirthProb = (*ai).getGiveBirthProb();
						int randomChance = rand() % 10;
						if ((giveBirthProb * 10) >= randomChance){
							//Adds the new aphid to a temporary array to be added later
							aphid tempAphid((*ai).pos[0], (*ai).pos[1], (*ai).moveProb,
								(*ai).lbugKillProb, (*ai).helpKillProb, (*ai).aphGiveBirthProb);
							newAphids.push_back(tempAphid);
						}
					}
				}
			}
			//--------------------------LADYBUGS CHECK---------------------------------------
			//Iterates through vector of ladybugs, checking coordinates against current cell
			for (vector<ladybug>::iterator li = lBugs.begin(); li != lBugs.end(); li++){
				if ((*li).getX() == i && (*li).getY() == j){
					nolBugs++;
					if (nolBugs > 1) {
						float giveBirth = (*li).getGiveBirthProb();
						int random = rand() % 10;
						if ((giveBirth * 10) >= random){
							//Adds new aphid to a temporary array
							ladybug templBug((*li).pos[0], (*li).pos[1], (*li).lBugMoveProb,
								(*li).changeDirProb, (*li).aphKillProb, (*li).lBugGiveBirthProb,(*li).preferredDirection);
							newlBugs.push_back(templBug);
						}
					}
				}
			}
			//if (noAphids >= 1 && nolBugs >= 1){
				//kill method( Pass in noAphids, noLbugs){
				//kill method stored in bug.
			/* bool AphKill:+
				checks number of aphids
				if (== 1){ checks probability to kill lbug
					if (prob == true) {
						return true;
					} else {return false; }
				}
				if ( > 1) { checks probability to kill bug, 

				if AphKill (returns true) { iterator erase (*ai); }
				*/

			//-------------------------BOARD PRINTING---------------------
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
	//Iterates through ladybug vector, updating each in turn
	for (vector<ladybug>::iterator lBugIt = this->lBugs.begin(); lBugIt != this->lBugs.end(); lBugIt++){
		(*lBugIt).update(board_x,board_y);
	}

	//Temporary vector, holds the values of new aphids, ready to be added next turn
	for (vector<aphid>::iterator newAphIt = newAphids.begin(); newAphIt != newAphids.end(); newAphIt++){
		aphids.push_back(*newAphIt);
	}
	newAphids.clear(); //Clears the vector, so aphids are only added once

	//Temporary vector, holds values of new ladybugs that are to be added next turn
	for (vector<ladybug>::iterator newlBugIt = newlBugs.begin(); newlBugIt != newlBugs.end(); newlBugIt++){
		lBugs.push_back(*newlBugIt);
	}
	newlBugs.clear(); //Clears the vector ready for the next turn

	printBoard();
	cin.get();
	updateGrid();
}