/*
 * Package.h
 *
 *  Created on: 28 Sep. 2018
 *      Author: Zempire
 */

#include <iostream>
#include <string>
#include <vector>
#include "EventTicket.h"
#include "FlightTicket.h"
#include "HotelVoucher.h"

using namespace std;

class Package{
public:
	Package(vector<FlightTicket> flights, vector<EventTicket> events, vector<HotelVoucher> hotels){
		flightTickets = flights;
		eventTickets = events;
		hotelVouchers = hotels;
		cout << "\nPACKAGE CREATED!!!\n";
	}

	~Package(){}
private:
	int clientNo = 0;
	vector<FlightTicket> flightTickets;	// 0 is to TOKYO. 1 is from TOKYO.
	vector<EventTicket> eventTickets;
	vector<HotelVoucher> hotelVouchers;
};






