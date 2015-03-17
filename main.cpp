#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "bug.h"
using namespace std;

int board_x;
int board_y;
int aphid_count;
int aphid[2];
int ladybird_count;
int ladybird[2];
float temp_Pm;
float temp_palB;
float temp_palN;
float temp_Pb;

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
		ifs >> aphid[0] >> aphid[1];
		loop_count++;
	}

	//Read in Ladybirds
	ifs >> ladybird_count;
	loop_count = 0;
	while (loop_count < ladybird_count) {
		ifs >> ladybird[0] >> ladybird[1];
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


void createBoard(){

	//Creates vector of vectors (2d board) the size the the read-in file defines
	vector<string> x(board_x,"[  ]");
	vector<vector<string> > board(board_y, x);

	//Prints playing board
	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[i].size(); j++){
			cout << board[i][j] << " ";
		}
		cout << endl << endl;
	}
		//May still be issue to move around board, insert etc


	//VECTOR NOTES
	//board.insert (board.begin() + 5, "name"); //insert "name" at position 5
	//board.remove (board.begin() + 3);   //Remove element at position 3
	//vector<string>::iterator i;
	//i->length   or     (*i).length     //get length of string (can use similar method to get value later? )
 
}

int main() {
	readSimConfig();
	createBoard();
	readAphConfig();
	cin.get();
}



//create manager object. manager myman;
//myman.setmove(pm);




/* -----------------------------------------
			OLD STUFF MAY NOT NEED
   -----------------------------------------

   string board[10][10] = {
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