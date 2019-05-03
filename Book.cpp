//
//  Book.cpp
//  Personal Blackjack Project
//
//  Created by Kevin Begic on 5/02/19.
//  Copyright © 2019 Kevin Begic. All rights reserved.
//

#include "Book.h"
#include <iostream>
using namespace std;

void Strategy::calculatePlayerMatrixLocation()
{
	// Calculate Location in Soft Matrix
	if (playerSoft)
	{
		// Location is last row in matrix if value >= 20
		if (playerHandValue >= 20)
		{
			playerMatrixLocation = 7;
		}
		else if (playerHandValue >= 13)
		{
			playerMatrixLocation = playerHandValue - 13;
		}
	}
	// Calculate Location in Hard Matrix
	else
	{
		if (playerHandValue >= 4 && playerHandValue <= 8)
		{
			playerMatrixLocation = 0;
		} // Values 4-8 first row
		else if (playerHandValue >= 17)
		{
			playerMatrixLocation = 10;
		} // Values 17+ last row
		else
		{
			playerMatrixLocation = playerHandValue - 8;
		}
	}
} // calculatePlayerLocation

void Strategy::calculateDealerMatrixLocation()
{
	if (dealerHasAce)
	{
		dealerMatrixLocation = 9;
	}
	else
	{
		dealerMatrixLocation = dealerUpCard - 2;
	}
} // calculateDealerMatrixLocation

void Strategy::determineActionInMatrix()
{
	if (playerSoft)
	{
		suggestedAction = playerSoftMatrix[playerMatrixLocation][dealerMatrixLocation];
	}
	else
	{
		suggestedAction = playerHardMatrix[playerMatrixLocation][dealerMatrixLocation];
	}
} // determineActionInMatrix
void Strategy::suggestedPlayerAction()
{
	switch (suggestedAction)
	{
	case 'H':
	{
		cout << "Player Suggestion: HIT!\nPlayer should HIT against Dealer Value "
			<< dealerUpCard << " with your value " << playerHandValue << "\n\n";
		break;
	}
	case 'S':
	{
		cout << "Player Suggestion: STAND!\nPlayer should STAND against Dealer Value "
			<< dealerUpCard << " with your value " << playerHandValue << "\n\n";
		break;
	}
	case 'D':
	{
		cout << "Player Suggestion: DOUBLE!\nPlayer should DOUBLE against Dealer Value "
			<< dealerUpCard << " with your value " << playerHandValue << "\n\n";
		break;
	}
	case 'G':
	{
		cout << "Player Suggestion: SURRENDER!\nPlayer should SURRENDER against Dealer Value "
			<< dealerUpCard << " with your value " << playerHandValue << '\n'
			<< "If Player cannot surrender, HIT!" << "\n\n";
		break;
	}
	case 'I':
	{
		cout << "\nPlayer Suggestion: SURRENDER!\nPlayer should SURRENDER against Dealer Value "
			<< dealerUpCard << " with your value " << playerHandValue << '\n'
			<< "If Player cannot surrender, STAND!" << "\n\n";
		break;
	}
	default :
	{
		cout << "\nSuggestiont not found! Do your best and follow your gut!";
	}
	}
}
void Strategy::overallStrategy()
{
	calculatePlayerMatrixLocation();
	calculateDealerMatrixLocation();
	determineActionInMatrix();
	suggestedPlayerAction();
} // overallStrategy