/*
 * HotelVoucher.h
 *
 *  Created on: 27 Sep. 2018
 *      Author: Zempire
 */
#ifndef HOTELVOUCHER_H
#define HOTELVOUCHER_H

#include <iostream>
#include <string>
#include "Ticket.h"

using namespace std;

class HotelVoucher: public Ticket {
public:
	HotelVoucher(double price, double discount, int date, int stars)
	: Ticket(price, discount, date){
		rating = stars;
	}

	void print() {
		cout << rating << " star hotel on day " << ticketDate << ": $" << discount << endl;
	}
	~HotelVoucher(){}
private:
	int rating;
};

#endif
