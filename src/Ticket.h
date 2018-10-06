/*
 * Ticket.h
 *
 *  Created on: 27 Sep. 2018
 *      Author: Zempire
 */
#ifndef TICKET_H
#define TICKET_H

#include <iostream>
#include <string>
using namespace std;

class Ticket {
protected:
	double ticketPrice = 0;
	double discount = 0;
	int ticketDate;
public:
	Ticket(double price, double disc, int date);
	double getDiscount();
	virtual ~Ticket();
private:

};

#endif
