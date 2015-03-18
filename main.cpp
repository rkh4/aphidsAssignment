#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "main.h"
#include "bug.h"
#include "manager.h"
#include <chrono>
#include <thread>

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
float temp_Pm, temp_palB, temp_palN, temp_Pb; //Temporary floats for the aphid config file
float temp_m, temp_b, temp_n, temp_p; //Temporary floats for the ladybud config file
manager myMan;

//Reads in simulation config file
void readSimConfig(){
	cout << "Reading In file 1/3... ";
	ifstream ifs;
	ifs.open("simConfig.txt"); //Inputting text file
	
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
	//Loops through the next few lines, adding aphids positons to a vector
	while (loop_count < aphid_count) {
		ifs >> aphid_temp[0] >> aphid_temp[1]; //X then Y
		(a).setPos(aphid_temp[0], aphid_temp[1]);
		aphids.push_back(a);
		loop_count++;
	}

	//Read in Ladybugs
	ifs >> ladybug_count;
	loop_count = 0;
	while (loop_count < ladybug_count) {
		ifs >> ladybug_temp[0] >> ladybug_temp[1];
		l.setPos(ladybug_temp[0], ladybug_temp[1]);
		lBugs.push_back(l);
		loop_count++;
	}

	//Close file again
	ifs.close();
}
//Reads in aphid config file
void readAphConfig(){
	cout << "Reading in file 2/3... ";
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

	myMan.set_a_Pm(temp_Pm); //dont pass in here, later, when object of aphid created, pass in all temp variables
	myMan.set_a_pALb(temp_palB);
	myMan.set_a_pALn(temp_palN);
	myMan.set_a_Pb(temp_Pb);
};
//Reads in ladybug config file
void readlBugConfig(){
	cout << "Reading in file 3/3... ";
	ifstream ifL;
	ifL.open("lBugConfig.txt");

	if (ifL.is_open()){
		cout << "file readSuccessfully!" << endl;
	} else {
		cout << "Error reading file!" << endl;
	};

	ifL >> temp_m;
	ifL >> temp_b;
	ifL >> temp_n;
	ifL >> temp_p;

	myMan.set_l_Pm(temp_m); //dont pass here, later when ladybug called, pass in temps 
	myMan.set_l_pALb(temp_b);
	myMan.set_a_pALn(temp_n);
	myMan.set_a_Pb(temp_p);
}


//Prints board
void createBoard(){
	//Creates vector of vectors (2d board) the size the the read-in file defines
	vector<string> x(board_x, "[  ]");
	vector<vector<string> > board(board_y, x);

	int noAphids = 0;
	int nolBugs = 0;

	//Loops, and cell checks
	cout << endl<<  "---------------------------------------------------" << endl;
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

void m_update(){
	while (0 == 0) {
		for (vector<aphid>::iterator aphUD = aphids.begin(); aphUD != aphids.end(); aphUD++){
			(*aphUD).update();
		}
		/*for (vector<ladybug>::iterator lBugUD = lBugs.begin(); lBugUD != lBugs.end(); lBugUD++){
			(*lBugUD).update();
		}*/
		createBoard();
		this_thread::sleep_for(std::chrono::milliseconds(1000));
	}
}

int main(){
	readSimConfig();
	readAphConfig();
	readlBugConfig();
	createBoard();
	m_update();
	cin.get();
}



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