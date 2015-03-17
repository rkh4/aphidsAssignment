#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "bug.h"
#include "manager.h"
using namespace std;

int board_x;
int board_y;
int aphid_count;
int aphid_temp[2];
aphid a;
vector<aphid> aphids;
int ladybug_count;
int ladybug_temp[2];
ladybug l;
vector<ladybug> lBugs;
float temp_Pm;
float temp_palB;
float temp_palN;
float temp_Pb;
manager myMan;

//Reads in text file
void readSimConfig(){
	cout << "Reading In file..." << endl;
	ifstream ifs;
	ifs.open("simConfig.txt");
	
	//Checks if file has been read correctly
	if (ifs.is_open()){
		cout << "File Read Successfully!" << endl;
	} else {
		cout << "Error Reading File!" << endl;
	}

	//Read in board size
	ifs >> board_x;
	ifs >> board_y;
	

	//Read in Aphids
	ifs >> aphid_count;
	int loop_count = 0;
	while (loop_count < aphid_count) {
		ifs >> aphid_temp[0] >> aphid_temp[1];
		a.setPos(aphid_temp[0], aphid_temp[1]);
		aphids.push_back(a);
		loop_count++;
	}


	//Read in Ladybugs
	ifs >> ladybug_count;
	loop_count = 0;
	while (loop_count < ladybug_count) {
		ifs >> ladybug_temp[0] >> ladybug_temp[1];
		//l.getPos(ladybug_temp[0], ladybug_temp[1]);
		lBugs.push_back(l);
		loop_count++;
	}

	//Close file again
	ifs.close();
}

void readAphConfig(){
	cout << "Reading in file \"aphConfig.txt\"..." << endl;
	ifstream ifC;
	ifC.open("aphConfig.txt");

	if (ifC.is_open()){
		cout << "File read Successfully!" << endl;
	} else {
		cout << "Error reading file!" << endl;
	};

	ifC >> temp_Pm;
	ifC >> temp_palB;
	ifC >> temp_palN;
	ifC >> temp_Pb;
};


//Prints board
void createBoard(){

	//Creates vector of vectors (2d board) the size the the read-in file defines
	vector<string> x(board_x,"[  ]");
	vector<vector<string> > board(board_y, x);

	int noAphids = 0;
	int nolBugs = 0;

	//Loops, and cell checks
	for (vector<aphid>::iterator ai = aphids.begin(); ai != aphids.end(); ai++){ //standard for loop, with vector iterator
		for (int i = 0; i < board.size(); i++) {
			for (int j = 0; j < board[i].size(); j++){
				if ((*ai).getX() == i && (*ai).getY() == j){
					noAphids++;
				}
			}
			/*for (vector<ladybug>::iterator li = lBugs.begin(); li != lBugs.end(); li++){
				if ((*li).getX() == i && (*li).getY() == j){
					nolBugs++;
				}
				
			}*/
			if (noAphids >= 1 && nolBugs >= 1) {
				cout << "[" << noAphids << "A" << nolBugs << " L]";
			} else if(noAphids >= 1) {
				cout << "[" << noAphids << "A]";
			} else if (nolBugs >= 1){
				cout << "[" << nolBugs << "L]";
			} else {
				cout << "[  ]";
			}
			noAphids = 0;
			nolBugs = 0;
		}
		cout << endl;
	}
}

int main(){
	readSimConfig();
	readAphConfig();
	myMan.setPm(temp_Pm);
	myMan.setpALb(temp_palB);
	myMan.setpALn(temp_palN);
	myMan.setPb(temp_Pb);
	createBoard();
	cin.get();
}



//VECTOR NOTES
//board.insert (board.begin() + 5, "name"); //insert "name" at position 5
//board.remove (board.begin() + 3);   //Remove element at position 3
//vector<string>::iterator i;
//i->length   or     (*i).length     //get length of string (can use similar method to get value later? )


/* -----------------------------------------
			OLD STUFF MAY NOT NEED
   -----------------------------------------
*/
/*   string board[10][10] = {
   { "-", "-", "-", "-", "-", "-", "-", "-", "-", "-" },
   { "-", "-", "-", "-", "-", "-", "-", "-", "-", "-" },
   { "-", "-", "-", "-", "-", "-", "-", "-", "-", "-" },
   { "-", "-", "-", "-", "-", "-", "-", "-", "-", "-" },
   { "-", "-", "-", "-", "-", "-", "-", "-", "-", "-" },
   { "-", "-", "-", "-", "-", "-", "-", "-", "-", "-" },
   { "-", "-", "-", "-", "-", "-", "-", "-", "-", "-" },
   { "-", "-", "-", "-", "-", "-", "-", "-", "-", "-" },
   { "-", "-", "-", "-", "-", "-", "-", "-", "-", "-" },
   { "-", "-", "-", "-", "-", "-", "-", "-", "-", "-" },
   };

   //Prints Board
   for (int i = 0; i < board_x; i++){
   for (int j = 0; j < board_y; j++){
   cout << board[i][j];
   cout << " ";
   }
   cout << endl;
   }


   vector<int>::iterator i;
   for (vector<string>::iterator i = board.begin(); i != board.end(); ++i) {
   	cout << *i << endl;
   }

*/