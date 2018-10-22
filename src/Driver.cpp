/*
 * Driver.cpp
 *
 *  Created on: 29 Sep. 2018
 *      Author: Zempire
 */

#include <iostream>
#include <string>
#include <vector>
#include "SmartAgent.h"
#include "RequestGenerator.h"

int main() {
	srand(time(NULL));
	int userChoice = 0;

	cout << "WELCOME to Eugene's Travel Agent.\n";
	cout << "Please choose from one of the following options:\n";

	while(true) {
		cout << "\n1. Test Classes.\n";
		cout << "2. Test Request Generator.\n";
		cout << "3. Test Smart Agent.\n";
		cout << "4. Test Simple Agent.\n";
		cout << "5. Exit Program.\n";

		cin >> userChoice;

		switch(userChoice) {
		case 1: {
			Event event("Test Event", 9, 3000, 1);
			cout << "Event Test: \n";
			event.print();
			vector<Event*> events = {&event};

			ClientRequest cr(8500, 5, events);
			cout << "\nClientRequest Test: \n";
			cr.print();

			FlightTicket ft(2000, 1600, 4);
			vector<FlightTicket> flights = {ft};
			cout << "\nFlightTicket Test: \n";
			ft.print();

			HotelVoucher hv(360, 180, 7, 5);
			vector<HotelVoucher> hotelVouchers = {hv};
			cout << "\nHotelVoucher Test: \n";
			hv.print();

			EventTicket et(2000, 0, 9, "Test Event", 0);
			vector<EventTicket> eventTickets = {et};
			cout << "\nEventTicket Test: \n";
			et.print();

			Package p(1, flights, eventTickets, hotelVouchers);
			cout << "\nPackage Test: \n";
			p.print();
			break;
		}
		case 2: {
			RequestGenerator rg;
			rg.requestsToFile();
			break;
		}
		case 3: {
			SmartAgent agents[4];
			for (int i = 0 ; i < 4; i++) {
				cout << "\nAGENT " << i << ":\n";
				agents[i].doSomeWork(agents[i].generateRequestsFromFile("requestList2.txt"), i);
			}
			break;
		}
		case 4: {
			TravelAgent agent;
			agent.doSomeWork(agent.generateRequestsFromFile("requestList2.txt"));
			break;
		}
		case 5: {
			return 0;
			break;
		}
		default:
			break;
		}
	}
	return 0;
}




