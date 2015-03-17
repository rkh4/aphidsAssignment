#ifndef _manager_h_
#define _manager_h_

class manager {
	//Variable Initialisation
	float Pm = 0;	//Probability for the creature to move
	float pALb = 0; //Base prob for aphid to kill ladybug
	float pALn = 0; //Additional prob, per aphid to help kill a ladybug
	float Pb = 0;	//Prob for two aphids to give birth when they meet in a cell

	//Set functions for manager
	void setPm(float temp_pm);
	void setpALb(float temp_pALb);
	void setpALn(float temp_pALn);
	void setPb(float temp_Pb);
	
	//Get functions, for the bug/aphid/ladybug files
	void getPm();
	void getpALb();
	void getpAln();
	void getPb();


	//voidSetProb(float...temp) 
	//{
	//	this->moveprob = float...temp; 
	//}

	//void getProb();
};

//set probability variables


#endif