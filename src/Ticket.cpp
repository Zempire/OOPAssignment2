/*
 * Ticket.cpp
 *
 *  Created on: 29 Sep. 2018
 *      Author: Zempire
 */

#include <iostream>
#include <fstream>
#include <string>
#include "Ticket.h"

using namespace std;

Ticket::Ticket(double price, double disc, int date)
	: ticketPrice(price), discount(disc), ticketDate(date){}

double Ticket::getDiscount() {
	return discount;
}
Ticket::~Ticket(){};
