//
//  Dealer.cpp
//  Personal Blackjack Project
//
//  Created by Kevin Begic on 5/02/19.
//  Copyright © 2019 Kevin Begic. All rights reserved.
//

#include "Dealer.h"
#include "Utility.h"
#include <iostream>
using namespace std;

void Dealer::determineUpCardValue()
{
	dealerUpCardValue = determineCardValue(dealerUpCardRank);
} // determineUpCardValue

void Dealer::dealerOutput()
{
	cout << "Card value for DEALER is " << dealerUpCardValue << '\n';

	if (dealerSoft)
	{
		cout << "Dealer has Soft 11, therefore dealer will HIT!\n";
	}
} // dealerOutput

int Dealer::getDealerUpCardValue()
{
	return dealerUpCardValue;
} // getDealerUpCardValue

bool Dealer::getDealerHasAce()
{
	return dealerSoft;
} // getDealerHasAce()
void Dealer::overallDealer()
{
	determineUpCardValue();
	dealerOutput();
} // getOverallDealer