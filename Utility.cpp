//
//  Utility.cpp
//  Personal Blackjack Project
//
//  Created by Kevin Begic on 5/02/19.
//  Copyright © 2019 Kevin Begic. All rights reserved.
//

#include "Utility.h"
#include <iostream>
#include <ctype.h>
using namespace std;

// used in various modules
void throw_input_error() {
	throw Error("Invalid Input! Card Values 1-9 or J,Q,K,A! Face Values D,H,S,C");
}

bool isValidCard(char card)
{
	if (isupper(card))
	{
		if (card == 'T' || card == 'J' || card == 'Q' ||
			card == 'K' || card == 'A')
		{
			return true;
		} // Jack, Queen, King, Ace
	} // 
	else if (int(card) - '0' >= 2 && int(card) - '0' <= 10)
	{
		return true;
	}

	return false;
} //isValidChar

int determineCardValue(char card)
{
	if (isValidCard(card))
	{
		// Up Card is an Ace
		if (card == 'A')
		{
			return 11;
		}
		// Up Card is Jack, Queen, or King
		else if (isalpha(card))
		{
			return 10;
		}
		// Up Card is a Number
		else
		{
			return int(card) - '0';
		}
	}
	// Up Card is Invalid
	else
	{
		throw_input_error();
	}

	return 0;
} //determineCardValue

