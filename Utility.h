//
//  Utility.cpp
//  Personal Blackjack Project
//
//  Created by Kevin Begic on 5/02/19.
//  Copyright © 2019 Kevin Begic. All rights reserved.
//

#ifndef UTILITY_H
#define UTILITY_H

// Error Message Class
struct Error {
	Error(const char* msg_ = "") : msg(msg_) {}
	const char* msg;
};

// Throws Error if Invalid Input
void throw_input_error();

// Determines if general card input is invalid for player/dealer
bool isValidCard(char card);

// Calculates value of card value for player/dealer
int determineCardValue(char card);

#endif
