#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <chrono>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <thread>
#include "bug.h"
#include "manager.h"
using namespace std;


//Initialisation for aphids
int aphid_count; //Aphid count
vector<aphid> createAphids; //Vector of aphid objects
int aphid_temp_pos[2]; //Array that holds the x and y co-ords of an aphid

//Initialisation for ladybugs
int ladybug_count; //Ladybug count
vector<ladybug> createLBugs; //Vector of ladybug objects
int ladybug_temp_pos[2]; //Arrat holding x and y coordinates

//Temporary variable initialisation
int board_x; //Width of the board
int board_y; //Height of the board
float aphMoveProb, lbugKillProb, helpKillProb, aphGiveBirthProb; //Temporary floats for the aphid config file
float lbugMoveProb, changeDirProb, aphKillProb, lbugGiveBithProb; //Temporary floats for the ladybud config file


//---------------------APHID FILE READ IN-------------------------
void readAphConfig(){
	cout << "Reading in file 1/3... ";
	ifstream inputFileA; //File input object
	inputFileA.open("aphConfig.txt");

	if (inputFileA.is_open()){
		cout << "File read successfully!" << endl;
	} else {
		cout << "Error reading file!" << endl;
	};

	inputFileA >> aphMoveProb;
	inputFileA >> lbugKillProb;
	inputFileA >> helpKillProb;
	inputFileA >> aphGiveBirthProb;
};

//--------------------LADYBUG FILE READ IN------------------------
void readlBugConfig(){
	cout << "Reading in file 2/3... ";
	ifstream ifL;
	ifL.open("lBugConfig.txt");

	if (ifL.is_open()){
		cout << "File read successfully!" << endl;
	}
	else {
		cout << "Error reading file!" << endl;
	};

	ifL >> lbugMoveProb; //Probability of moving
	ifL >> changeDirProb; //Probability of changing direction
	ifL >> aphKillProb; //Probability to kill an aphid
	ifL >> lbugGiveBithProb; //Probability to reproduce
}

//----------------------CONFIG FILE READ IN------------------------
void readSimConfig(){
	cout << "Reading in file 3/3... ";
	ifstream ifs; //Input file onject
	ifs.open("simConfig.txt"); //Opening text file

	//Checks if file has been read correctly
	if (ifs.is_open()){
		cout << "File read successfully!" << endl;
	}
	else {
		cout << "Error Reading File!" << endl;
	}

	//Read in board size
	ifs >> board_x;
	ifs >> board_y;


	//----------------------APHIDS READ IN------------------------------
	ifs >> aphid_count;
	int loop_count = 0; //Temporary loop variable
	while (loop_count < aphid_count) {
		//Creates temporary aphid object, fills parameters, and pushes to the vector
		ifs >> aphid_temp_pos[0] >> aphid_temp_pos[1]; //X then Y
		aphid tmpAphid(aphid_temp_pos[0],aphid_temp_pos[1],aphMoveProb,lbugKillProb,helpKillProb, aphGiveBirthProb);
		createAphids.push_back(tmpAphid);
		loop_count++;
	}


	//-------------------LADYBUGS READ IN --------------------------------
	ifs >> ladybug_count;
	loop_count = 0; //Temoporary loop variable
	while (loop_count < ladybug_count) {
		ifs >> ladybug_temp_pos[0] >> ladybug_temp_pos[1];
		ladybug tmpLBug(ladybug_temp_pos[0], ladybug_temp_pos[1], lbugMoveProb,changeDirProb,aphKillProb,lbugGiveBithProb);
		createLBugs.push_back(tmpLBug);
		loop_count++;
	}

	//Close current file
	ifs.close();
}

//-------------------------MAIN FUNCTION---------------------------
int main(){
	readAphConfig();
	readlBugConfig();
	readSimConfig();
	srand(time(0)); //Ensures rand fuction makes new random numbers every time
	manager myMan(createAphids, createLBugs, board_x, board_y);
	myMan.printBoard();
	myMan.updateGrid();
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