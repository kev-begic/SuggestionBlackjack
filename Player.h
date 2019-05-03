//
//  Player.h
//  Personal Blackjack Project
//
//  Created by Kevin Begic on 5/02/19.
//  Copyright © 2019 Kevin Begic. All rights reserved.
//

#ifndef PLAYER_H
#define PLAYER_H

#include "Utility.h"

class Player {
public:
	/**** Constructors for Dealer ****/
	// Default constructor
	Player(char card1, char card2) {
		playerCard1 = card1;
		playerCard2 = card2;

		if (card1 == 'A' || card2 == 'A')
		{
			playerSoft = true;
		}
	}
	/**** End of Constructors ****/

	/**** Extensive Functions ****/

	// Gets Card Value of Dealer Up Card
	void determinePlayerCardValues();
	// Outputs dealer 
	void playerOutput();

	/**** End Extensive ****/

	/*  General Functions   */

	// Get value of player hand
	int getPlayerHandValue();
	// Return if player has an ace
	bool getPlayerIsSoft();

	// Get's Dealer for the Round
	void overallPlayer();

	/*  End General   */
private:
	// Two cards for player
	char playerCard1;
	char playerCard2;

	// Value for player's two cards
	int playerCardsValue;
	// If any one card is ace, player has soft value
	bool playerSoft = false;

};
#endif
