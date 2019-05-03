//
//  Game.cpp
//  Personal Blackjack Project
//
//  Created by Kevin Begic on 5/02/19.
//  Copyright © 2019 Kevin Begic. All rights reserved.
//

#include "Game.h"
#include <locale>
using namespace std;

void startingOutput()
{
	cout << "Welcome to Suggestion BlackJack! Input is done using numbers.\n"
		<< "For instance, valid card values integers 2 through 9,"
		<< " T for 10, J for Jack, Q for Queen, K for King, and A for Ace.\n"
		<< "Starting input is for player, then dealer thereafter. Good luck!\n\n";
}
void runSuggestionBlackJack()
{
	startingOutput();

	// Integer Card Rank {2, 3, 4, 5, 6, 7, 8, 9 }
	// Face Card Rank {T(10),J, Q, K, A}
	char playerCard1, playerCard2, dealerCard;

	// Player ends the game
	bool quitGame = false;
	while (!quitGame)
	{
		cout << "Player Card: ";
		cin >> playerCard1;

		cout << "Dealer Up Card: ";
		cin >> dealerCard;

		cout << "Second Player Card: ";
		cin >> playerCard2;
		cout << '\n';

		playerCard1 = toupper(playerCard1);
		playerCard2 = toupper(playerCard2);
		dealerCard = toupper(dealerCard);

		Player firstPlayer(playerCard1, playerCard2);
		firstPlayer.overallPlayer();

		Dealer dealer(dealerCard);
		dealer.overallDealer();

		cout << '\n';

		Strategy strat(firstPlayer.getPlayerHandValue(), dealer.getDealerUpCardValue(),
			firstPlayer.getPlayerIsSoft(), dealer.getDealerHasAce(), false);
		strat.overallStrategy();

		cout << "TESTING!" << endl;
		quitGame = false;
	}
}