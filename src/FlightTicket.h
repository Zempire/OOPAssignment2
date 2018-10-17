/*
 * FlightTicket.h
 *
 *  Created on: 27 Sep. 2018
 *      Author: Zempire
 */
#ifndef FLIGHTTICKET_H
#define FLIGHTTICKET_H

#include <iostream>
#include <string>
#include "Ticket.h"
using namespace std;

class FlightTicket: public Ticket {
public:
	FlightTicket(double price, double discount, int date)
	: Ticket(price, discount, date){}

	void print() {
		cout << "Date of Flight: " << ticketDate;
		cout << ", Cost: $" << discount << endl;
	}
	~FlightTicket(){}
};

#endif

