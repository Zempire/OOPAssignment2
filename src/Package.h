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
	Package(int clientNumber, vector<FlightTicket> flights, vector<EventTicket> events, vector<HotelVoucher> hotels){
		flightTickets = flights;
		eventTickets = events;
		hotelVouchers = hotels;
		clientNo = clientNumber;
	}

	void print() {
		cout << "\nCLIENT NO: " << clientNo << endl;
		cout << "FLIGHTS:" << endl;
		for (unsigned int i = 0; i < flightTickets.size(); i++)
			flightTickets.at(i).print();
		cout << "HOTELS:" << endl;
		for (unsigned int i = 0; i < hotelVouchers.size(); i++)
			hotelVouchers.at(i).print();
		cout << "EVENTS:" << endl;
		for (unsigned int i = 0; i < eventTickets.size(); i++)
			eventTickets.at(i).print();

	}

	~Package(){}
private:
	int clientNo;
	vector<FlightTicket> flightTickets;	// 0 is to TOKYO. 1 is from TOKYO.
	vector<EventTicket> eventTickets;
	vector<HotelVoucher> hotelVouchers;
};






