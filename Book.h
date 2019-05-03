//
//  Book.h
//  Personal Blackjack Project
//
//  Created by Kevin Begic on 5/02/19.
//  Copyright © 2019 Kevin Begic. All rights reserved.
//

#ifndef BOOK_H
#define BOOK_H

#include "Utility.h"
#include <iostream>
#include <vector>

using namespace std;

class Strategy {
public:

	/**** Constructors for Book Strategy (Las Vegas Strategy)****/
	// Default constructor
	Strategy(int playerValue, int dealerValue, bool softPlayer, bool dealerAce, bool split) {
		playerHandValue = playerValue;
		dealerUpCard = dealerValue;
		playerSoft = softPlayer;
		dealerHasAce = dealerAce;
		playerSplit = split;
	}
	/**** End of Constructors ****/

	/**** Extensive Functions ****/

	// Determines row and column for specific Matrix suggestion is to be found
	void calculatePlayerMatrixLocation();
	void calculateDealerMatrixLocation();
	// Determines specific action based of row, column, and specified matrix
	void determineActionInMatrix();
	// Outputs suggestions for player
	void suggestedPlayerAction();

	/**** End Extensive ****/

	/*  General Functions   */

	// Runs strategy for a round
	void overallStrategy();

	/*  End General   */

private:

	// { HIT = 'H', STAND = 'S', DOUBLE = 'D', SPLIT = 'B', SURRENDER_HIT = 'G', SURRENDER_STAND = 'I'}

	vector<vector<char>> playerHardMatrix{					// Values of Player
		{'H', 'H', 'H', 'H', 'H', 'H', 'H', 'H', 'H', 'H'}, // 4-8 (Always hit)
		{'H', 'D', 'D', 'D', 'D', 'H', 'H', 'H', 'H', 'H'}, // 9 (Double dealer up 3-6)
		{'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'H', 'H'}, // 10 (Double unless dealer 10 or A)
		{'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D'}, // 11 (Always Double)
		{'H', 'H', 'S', 'S', 'S', 'H', 'H', 'H', 'H', 'H'}, // 12 (Stand if Dealer 4-6)
		{'S', 'S', 'S', 'S', 'S', 'H', 'H', 'H', 'H', 'H'}, // 13 (Stand if Dealer 2-6)
		{'S', 'S', 'S', 'S', 'S', 'H', 'H', 'H', 'H', 'H'}, // 14 (Stand if Dealer 2-6)
		{'S', 'S', 'S', 'S', 'S', 'H', 'H', 'H', 'G', 'G'}, // 15 (Stand if Dealer 2-6, Surrender/Hit if 10 or A)
		{'S', 'S', 'S', 'S', 'S', 'H', 'H', 'G', 'G', 'G'}, // 16 (Stand if Dealer 2-6, Surrender/Hit if 10 or A)
		{'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S', 'I'}, // 17 (Stand if Dealer 2-6, Surrender/Stand if 10 or A)
		{'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S'}  // 18+ (Always Stand)
	};
	vector<vector<char>> playerSoftMatrix{					// Values of Player
		{'H', 'H', 'H', 'D', 'D', 'H', 'H', 'H', 'H', 'H'}, // 13 (Double hit on Dealer 5, 6)
		{'H', 'H', 'H', 'D', 'D', 'H', 'H', 'H', 'H', 'H'}, // 14 (Double hit on Dealer 5, 6)
		{'H', 'H', 'D', 'D', 'D', 'H', 'H', 'H', 'H', 'H'}, // 15 (Double hit on Dealer 4-6)
		{'H', 'H', 'D', 'D', 'D', 'H', 'H', 'H', 'H', 'H'}, // 16 (Double hit on Dealer 4-6)
		{'H', 'D', 'D', 'D', 'D', 'H', 'H', 'H', 'H', 'H'}, // 17 (Double hit on Dealer 3-6)
		{'D', 'D', 'D', 'D', 'D', 'S', 'S', 'H', 'H', 'H'}, // 18 (Double Dealer2-6, Stand 7-8, Hit 9-A)
		{'S', 'S', 'S', 'S', 'D', 'S', 'S', 'S', 'S', 'S'}, // 19 (Double Dealer 6, Else stand)
		{'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S'}  // 20+ (Always Stand)
	};
	
	// Mark true if dealer has an ace
	bool dealerHasAce = false;
	// If dealt an ace, player has a soft hand. Else, player has a hard hand
	bool playerSoft = false;
	// If have two of same card, determine if split
	bool playerSplit = false;


	// Sum value for player's two cards, 
	int playerHandValue;
	// Value for dealer's one up card;
	int dealerUpCard;

	/* Matrix Variables */
	int playerMatrixLocation;
	int dealerMatrixLocation;

	/* Output Variables */
	char suggestedAction;
};

#endif