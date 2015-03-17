#ifndef _manager_h_
#define _manager_h_

class manager {
public:
	//Variable Initialisation
	float a_Pm = 0;	//Probability for the creature to move
	float a_pALb = 0; //Base prob for aphid to kill ladybug
	float a_pALn = 0; //Additional prob, per aphid to help kill a ladybug
	float a_Pb = 0;	//Prob for two aphids to give birth when they meet in a cell
	float l_Pm = 0, lpALb = 0, l_pALn = 0, l_Pb = 0; //Same variables, but for ladybug

	//Set functions for manager
	void set_a_Pm(float temp_pm);
	void set_a_pALb(float temp_pALb);
	void set_a_pALn(float temp_pALn);
	void set_a_Pb(float temp_Pb);
	
	//Get functions, for the bug/aphid/ladybug files
	float get_a_Pm();
	float get_a_pALb();
	float get_a_pAln();
	float get_a_Pb();
};





#endif