#ifndef HARD_H
#define HARD_H

/*	if player choses hard mode, this class keeps track of house 
 *	wins and losses, then increases or decreases house values based 
 *	in the overloaded spin method based on that on that
*/

class Hard : public Wheel {
	private:
		int incr = 1;		// amount to increase or decrease values by
		int winLoss;		// house wins or losses of previous round(s)

		int playerValue;	// player value -- to determine min house value
	public:
		Hard() { }
		Hard(int playerVal);

		void win();				// house wins
		void loss();			// house loses

		int spin(int playerResult);		// overload of spin method
};

#endif