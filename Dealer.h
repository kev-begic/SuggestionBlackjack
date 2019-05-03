//
//  Dealer.h
//  Personal Blackjack Project
//
//  Created by Kevin Begic on 5/02/19.
//  Copyright © 2019 Kevin Begic. All rights reserved.
//

#ifndef DEALER_H
#define DEALER_H

#include "Utility.h"

class Dealer {
public:

	/**** Constructors for Dealer ****/
	// Default constructor
	Dealer(char card) {
		dealerUpCardRank = card;

		if (card == 'A')
		{
			dealerSoft = true;
		}
	}
	/**** End of Constructors ****/

	/**** Extensive Functions ****/

	// Gets Card Value of Dealer Up Card
	void determineUpCardValue();
	// Outputs dealer 
	void dealerOutput();

	/**** End Extensive ****/

	/*  General Functions   */

	// Get Value of UpCard
	int getDealerUpCardValue();
	// Determine if dealer has Ace
	bool getDealerHasAce();
	// Get's Dealer for the Round
	void overallDealer();

	/*  End General   */


private:
	// Only one card is revealed for dealer
	char dealerUpCardRank;
	// Value for dealer Card
	int dealerUpCardValue;
	// If upcard is Ace, dealer has soft Ace
	bool dealerSoft = false;
};

#endif
