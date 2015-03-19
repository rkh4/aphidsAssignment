
	CS22510 Assignment 1
	Aphids and Ladybugs
	by Fred Labrosse & Neil Snooke
	
	Author: Rhys Howard (rkh4) 13005197
	Date: 19/03/2015
	
	Language: C++
	Standard: C++11
	Github repo: https://github.com/rkh4/aphidsAssignment


//--------------------FILES----------------------------------
	"main.cpp" -  Main file
		The file that runs the program initially.
		- Reads all 3 config files
		- Creates vectors of aphid and ladybug objects
		- passes all information including the size of the board, and all vectors,
			into a new manager object .
		- Prints the initial board
		- Runs the manager 'updateGrid' method
	
	
	"manager.h" -
		The header that holds manager class.
		
	"manager.cpp" - 
		The manager holds all objects, and is in control of the program
		- Upon creation has been passed aphid and ladybug vectors,
			creates local vectors of these
		- prints board
		- Updates all bugs
		- continually updates after a user input "cin.get();"
		
	"bug.cpp" -
		The bass class for Aphid & ladybug
		- Returns the X and Y of the bug when requested
	
	"bug.h" - 
		Holds the classes for the base class bug, and derived classes
			aphid and ladybug
		- Holds and initiates variables
		- Holds class methods
		
	"aphid.cpp" - 
		Holds completed methods for the aphid objects
		- Changing position
		- Fighting a ladybug
		- updating itself
	
	"ladybug.cpp" -	
		Hold completed methods for ladybug objects
		- newPreferred direction class 
		- changes position
		- updates itself
		
	"simConfig.txt" - 
		Simulation configuration file
		- holds board data
		- aphid data
		- ladybug data
		
	"aphConfig.txt" -
		Aphid configuration file
		- Holds various probabilities for an Aphid object
		
	"lBugConfig.txt" -
		Ladybug configuration file
		- Holds probabilities for ladybug objects


//-----------------LIBRARIES INCLUDED----------------------
#include <fstream> 	- File stream, allowed me to input the config text files
#include <vector> 	- Allows me to use vectors
#include <iostream> - Input/Output stream, can use commands like 'cout' and 'cin'
#include <string>	- Allows the use of the datatype string
#include <time.h>	- For the rand() function to create new random functions every time
						this library is required
	
	
//-----------------BUILDING CODE--------------------------
	1. Add all files in the same directory
	2. Compile main.cpp
	
	