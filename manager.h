#ifndef _manager_h_
#define _manager_h_

class manager {
public:
	//Variable Initialisation
	float a_Pm = 0;	//Probability for the creature to move
	float a_pALb = 0; //Base prob for aphid to kill ladybug
	float a_pALn = 0; //Additional prob, per aphid to help kill a ladybug
	float a_Pb = 0;	//Prob for two aphids to give birth when they meet in a cell
	float l_Pm = 0, l_pALb = 0, l_pALn = 0, l_Pb = 0; //Same variables, but for ladybug

	//set functions
	void set_a_Pm(float temp_pm), set_a_pALb(float temp_pALb), 
		set_a_pALn(float temp_pALn), set_a_Pb(float temp_Pb);
	void set_l_Pm(float temp_m), set_l_pALb(float temp_b), 
		set_l_pALn(float temp_n), set_l_Pb(float temp_p);

	//Get functions, for the bug/aphid/ladybug files
	float get_a_Pm(), get_a_pALb(), get_a_pAln(), get_a_Pb();
	float get_l_Pm(), get_l_pALb(), get_l_pAln(), get_l_Pb();
};





#endif