using namespace std;
#include <iostream>
#include "manager.h"

//Set functions
void manager::set_a_Pm(float temp_pm){
	this->a_Pm = temp_pm;
}

void manager::set_a_pALb(float temp_pALb){
	this->a_pALb = temp_pALb;
}

void manager::set_a_pALn(float temp_pALn){
	this->a_pALn = temp_pALn;
}

void manager::set_a_Pb(float temp_Pb){
	this->a_Pb = temp_Pb;
}

void manager::set_l_Pm(float temp_m){
	this->l_Pm = temp_m;
}

void manager::set_l_pALb(float temp_b){
	this->l_pALb = temp_b;
}

void manager::set_l_pALn(float temp_n){
	this->l_pALn = temp_n;
}

void manager::set_l_Pb(float temp_p){
	this->l_Pb = temp_p;
}

//Get functions for the bug, aphid & ladybug cpp files
float manager::get_a_Pm(){
	return this->a_Pm;
}

float manager::get_a_pALb(){
	return this->a_pALb;
}

float manager::get_a_pAln(){
	return this->a_pALn;
}

float manager::get_a_Pb(){
	return this->a_Pb;
}

float manager::get_l_Pm(){
	return this->l_Pm;
}

float manager::get_l_pALb(){
	return this->l_pALb;
}

float manager::get_l_pAln(){
	return this->l_pALn;
}

float manager::get_l_Pb(){
	return this->l_Pb;
}

/*//Prints board
void createBoard(){
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
}*/