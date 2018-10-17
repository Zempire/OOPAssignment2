/*
 * EventTicket.h
 *
 *  Created on: 27 Sep. 2018
 *      Author: Zempire
 */
#ifndef EVENTTICKET_H
#define EVENTTICKET_H

#include <iostream>
#include <string>
#include "Ticket.h"

using namespace std;

class EventTicket: public Ticket {
public:
	EventTicket(double price, double discount, int date, string name, int number)
	: Ticket(price, discount, date) {
		eventName = name;
		eventNo = number;
	}
	void print() {
		cout << eventName << " on day " << ticketDate << ": $" << discount << endl;
	}
	~EventTicket(){}

private:
	string eventName;
	int eventNo;

};

#endif




