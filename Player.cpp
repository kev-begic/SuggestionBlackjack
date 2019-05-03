//
//  Player.cpp
//  Personal Blackjack Project
//
//  Created by Kevin Begic on 5/02/19.
//  Copyright © 2019 Kevin Begic. All rights reserved.
//

#include "Player.h"
#include <iostream>
using namespace std;

void Player::determinePlayerCardValues()
{
	playerCardsValue = determineCardValue(playerCard1);
	playerCardsValue += determineCardValue(playerCard2);
} // determinePlayerCardValues

void Player::playerOutput()
{
	cout << "Card value for PLAYER is " << playerCardsValue << '\n';

	if (playerSoft)
	{
		cout << "Player is SOFT! Consider HIT or STAND carefully!\n";
	}
} // playerOutput

int Player::getPlayerHandValue()
{
	return playerCardsValue;
} // getPlayerHandValue

bool Player::getPlayerIsSoft()
{
	return playerSoft;
} // getPlayerIsSoft

void Player::overallPlayer()
{
	determinePlayerCardValues();
	playerOutput();
} // overallPlayer