#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "bug.h"
#include "manager.h"
#include <chrono>
#include <thread>
using namespace std;


//Initialisation for aphids
int aphid_count; //Aphid count
aphid aphid_obj;
vector<aphid> aphids; //Vector of aphid objects
int aphid_temp_pos[2]; //Array that holds the x and y co-ords of an aphid

//Initialisation for ladybugs
int ladybug_count; //Ladybug count
ladybug lBug_obj;
vector<ladybug> lBugs; //Vector of ladybug objects
int ladybug_temp_pos[2]; //Arrat holding x and y coordinates

//Temporary variable initialisation
float aphMoveProb, lbugKillProb, helpKillProb, aphGiveBirthProb; //Temporary floats for the aphid config file
float lbugMoveProb, changeDirProb, aphKillProb, lbugGiveBithProb; //Temporary floats for the ladybud config file


//----------------------CONFIG FILE READ IN------------------------
void readSimConfig(){
	cout << "Reading In file 1/3... ";
	ifstream ifs; //Input file onject
	ifs.open("simConfig.txt"); //Opening text file
	
	//Checks if file has been read correctly
	if (ifs.is_open()){
		cout << "File Read Successfully!" << endl;
	} else {
		cout << "Error Reading File!" << endl;
	}

	//Read in board size
	int board_x; //Width of the board
	int board_y; //Height of the board
	ifs >> board_x;
	ifs >> board_y;
	

//----------------------APHIDS READ IN------------------------------
	ifs >> aphid_count;
	int loop_count = 0; //Temporary loop variable
	while (loop_count < aphid_count) {
		ifs >> aphid_temp_pos[0] >> aphid_temp_pos[1]; //X then Y
		(aphid_obj).setPos(aphid_temp_pos[0], aphid_temp_pos[1]);
		aphids.push_back(aphid_obj);
		loop_count++;
	}


//-------------------LADYBUGS READ IN --------------------------------
	ifs >> ladybug_count;
	loop_count = 0; //Temoporary loop variable
	while (loop_count < ladybug_count) {
		ifs >> ladybug_temp_pos[0] >> ladybug_temp_pos[1];
		lBug_obj.setPos(ladybug_temp_pos[0], ladybug_temp_pos[1]);
		lBugs.push_back(lBug_obj);
		loop_count++;
	}

	//Close current file
	ifs.close();
}

//---------------------APHID FILE READ IN------------------------
void readAphConfig(){
	cout << "Reading in file 2/3... ";
	ifstream inputFileA; //File input object
	inputFileA.open("aphConfig.txt");

	if (inputFileA.is_open()){
		cout << "File read Successfully!" << endl;
	} else {
		cout << "Error reading file!" << endl;
	};

	inputFileA >> aphMoveProb;
	inputFileA >> lbugKillProb;
	inputFileA >> helpKillProb;
	inputFileA >> aphGiveBirthProb;
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

	ifL >> lbugMoveProb; //Probability of moving
	ifL >> changeDirProb; //Probability of changing direction
	ifL >> aphKillProb; //Probability to kill an aphid
	ifL >> lbugGiveBithProb; //Probability to reproduce
}

int main(){
	readSimConfig();
	readAphConfig();
	readlBugConfig();

	//m_update();
	cin.get();
}




/*
void m_update(){
while (0 == 0) {
for (vector<aphid>::iterator aphUD = aphids.begin(); aphUD != aphids.end(); aphUD++){
(*aphUD).update();
}
for (vector<ladybug>::iterator lBugUD = lBugs.begin(); lBugUD != lBugs.end(); lBugUD++){
(*lBugUD).update();
}
createBoard();
this_thread::sleep_for(std::chrono::milliseconds(1000));
}
}*/