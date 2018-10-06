/*
 * TravelAgent.cpp
 *
 *  Created on: 28 Sep. 2018
 *      Author: Zempire
 */

#include <iostream>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include "TravelAgent.h"

using namespace std;

TravelAgent::TravelAgent() {
	//BUILD THE EVENTS ARRAY
	string eventName = "";
	int day, quantity;
	double cost;
	char ch;

	ifstream inStream("events.txt");
		if (inStream.fail()) {
			cout << "events file failed.\n";
			exit(1);
		}

		while(true) {
			getline(inStream, eventName, ',');
			inStream >> day >> ch >> cost >> ch >> quantity;
			inStream.ignore(100, '\n');
			Event event(eventName, day, cost, quantity);
			events.push_back(event);
			if (inStream.eof())
				break;
		}

	//BUILD THE HOTEL ARRAY
	// A Hotel's position in array is equal to its star ratings minus 3.
	hotels = {{160, 20, 3},{210, 25, 4},{320,30, 5}};
}

void TravelAgent::startWorking() {
	newRequests = generateRequestsFromFile("requestList.txt");

	while (!newRequests.empty()) {
		if (checkRequest(newRequests.at(0))) {
			packages.push_back(buildPackage(newRequests.at(0)));
			requests[0].push_back(newRequests.at(0));
			newRequests.erase(newRequests.begin());
		} else {
//			char answer;
//			cout << "\nWould you like us to rework your package? (y/n)";
//			cin >> answer;
//			if (answer == 'y') {
				adaptRequest(newRequests.at(0));
//			} else {
//				requests[1].push_back(clientRequests.at(i));
//			}
		}
	}

	for (unsigned int i = 0; i < hotels.size(); i++)
		hotels.at(i).print();

	for (unsigned int i = 0; i < events.size(); i++)
		events.at(i).print();

	cout << "\nPROFIT MADE: " << profit << endl;
	cout << "REQUESTS ACCEPTED: " << requests[0].size() << endl;
	cout << "REQUESTS REJECTED: " << requests[1].size() << endl;
}

Event TravelAgent::getEvent(int position) {
	return events.at(position);
}


bool TravelAgent::checkRequest(ClientRequest & request) {
	double hotelTotal = 0, flightTotal = 0, eventTotal = 0, grandTotal = 0;
	for (unsigned int i = 0; i < request.events.size(); i++) {
		// Calculate the total cost of all events.
		if (request.events.at(i)->getQuantity() < 1) {
			cout << "\nNo tickets available for ";
			cout << request.events.at(i)->getName() << endl;
			REQUEST_ERROR = 2;
			return false;
		} else
			eventTotal += request.events.at(i)->getPrice();
	}

	// Get the cost for the hotels.
	for (int i = request.firstDay; i < request.lastDay; i++) {
		if (hotels[2].getQuantity(i) > 0){
			hotelTotal += hotels[2].getRoomPrice(i);
		} else if (hotels[1].getQuantity(i) > 0) {
			hotelTotal += hotels[1].getRoomPrice(i);
		} else if (hotels[0].getQuantity(i) > 0) {
			hotelTotal += hotels[0].getRoomPrice(i);
		} else {
			cout << "\nThere are no rooms available on Day " << i << endl;
			REQUEST_ERROR = 3;
			return false;
		}
	}

	//Get the cost for flight tickets.
	flightTotal += calculateFlight(0, request.firstDay);
	flightTotal += calculateFlight(1, request.lastDay);

	grandTotal = eventTotal + hotelTotal + flightTotal;
	cout << "\nCLIENT BUDGET: " << request.budget << endl;
	cout << "PACKAGE COST: " << grandTotal << endl;
	cout << " - Flights: " << flightTotal << endl;
	cout << " - Hotels: " << hotelTotal << endl;
	cout << " - Events: " << eventTotal << endl;
	for (unsigned int i = 0; i < request.events.size(); i++) {
		cout << "   - " << request.events.at(i)->getName() << ": ";
		cout << request.events.at(i)->getPrice() << endl;
	}
	cout << "Fly in day " << request.firstDay << " and out day " << request.lastDay << endl;

	if (request.budget < grandTotal) {
		cout << "Sorry you do not have the budget for this request." << endl;
		request.requestTotal = grandTotal;
		REQUEST_ERROR = 1;
		return false;
	}
	return true;
}

void TravelAgent::adaptRequest(ClientRequest & request) {
	switch (REQUEST_ERROR) {
	case 1: // Client doesn't have enough money in their budget.
		if (request.events.size() > 1) {
			double difference = request.requestTotal - request.budget;
			cout << "DIFFERENCE: " << difference << endl;
			sort(request.events.begin(), request.events.end(), Event::sortByCost);
			for (unsigned int i = 0; i < request.events.size(); i++) {
				if (request.events.at(i)->getPrice() >= difference) {
					request.events.erase(request.events.begin() + i);
					break;
				} else if (i == request.events.size() - 1)
					request.events.pop_back();
			}
		} else {
			requests[1].push_back(newRequests.at(0));
			newRequests.erase(newRequests.begin());
		}
		break;
	case 2: // No tickets are available for a specific event.
		for (unsigned int i = 0; i < request.events.size(); i++)
			if (request.events.at(i)->getQuantity() < 1)
				request.events.erase(request.events.begin() + i);
		if (request.events.empty()) {
			requests[1].push_back(newRequests.at(0));
			newRequests.erase(newRequests.begin());
		}
		break;
	case 3:// There are no hotels available on a certain day.
		requests[1].push_back(newRequests.at(0));
		newRequests.erase(newRequests.begin());
		break;
	default:
		break;
	}
	REQUEST_ERROR = 0;
}

Package TravelAgent::buildPackage(ClientRequest request) {
	vector<HotelVoucher> hotelVouchers;
	vector<EventTicket> eventTickets;

	//Create the Flight Tickets.
	vector<FlightTicket> flightTickets = {{2000, calculateFlight(0, request.firstDay), request.firstDay},
		 {2000, calculateFlight(1, request.lastDay), request.lastDay}};
//	profit += (flightTickets.at(0).getDiscount() * .03);
//	profit += (flightTickets.at(1).getDiscount() * .03);
//	cout << "\n+Profit: $" << profit << endl;


//	Create the Hotel Vouchers.
	for (int i = request.firstDay; i < request.lastDay; i++) {
		double discountPrice, fullPrice;
		int stars;
		if (hotels.at(2).getQuantity(i) > 0){
			fullPrice = hotels.at(2).getFullPrice();
			discountPrice = hotels.at(2).getRoomPrice(i);
			stars = 5;
			hotels.at(2).sellTicket(i);
		} else if (hotels.at(1).getQuantity(i) > 0) {
			fullPrice = hotels.at(1).getFullPrice();
			discountPrice = hotels.at(1).getRoomPrice(i);
			stars = 4;
			hotels.at(1).sellTicket(i);
		} else if (hotels.at(0).getQuantity(i) > 0){
			fullPrice = hotels.at(0).getFullPrice();
			discountPrice = hotels.at(0).getRoomPrice(i);
			stars = 3;
			hotels.at(0).sellTicket(i);
		}
		HotelVoucher voucher(fullPrice, discountPrice, i, stars);
		hotelVouchers.push_back(voucher);
//		profit += (voucher.getDiscount() * .03);
//		cout << "\n+Profit: $" << profit << endl;
	}
	// Create the EventTickets
	for (unsigned int i = 0; i < request.events.size(); i++) {
		EventTicket ticket(request.events.at(i)->getPrice(),
				request.events.at(i)->getPrice(),
				request.events.at(i)->getDay(),
				request.events.at(i)->getName(), i);
		eventTickets.push_back(ticket);
		request.events.at(i)->sellTicket();
		cout << request.events.at(i)->getName() << " Tickets left: ";
		cout << request.events.at(i)->getQuantity() << endl;
		profit += (ticket.getDiscount() * .1);
//		cout << "TICKET DISCOUNT: " << ticket.getDiscount() << endl;
//		cout << "\n+Profit: $" << profit << endl;
	}

	Package newPackage(flightTickets, eventTickets, hotelVouchers);
	return newPackage;
}

void TravelAgent::printRequests(vector<ClientRequest> requests) {
	for (unsigned int i = 0; i < requests.size(); i++) {
		requests[i].print();
	}
}

double TravelAgent::calculateFlight(int direction, int day) {
	switch(direction) {
	case 0:
		return 2000 * (1 - (day * .05));
		break;
	case 1:
		return 2000 * (1 - ((9 - day) * .05));
		break;
	default:
		return 2000;
		break;

	}
}

vector<ClientRequest> TravelAgent::generateRequestsFromFile(string file) {
	vector<ClientRequest> requests;
	double budget;
	int rating, event;
	char ch;
	ifstream inStream(file);
	if (inStream.fail()) {
		cout << "Requests file failed.\n";
		exit(1);
	}

	while(true) {
		vector<Event*> requestEvents;
		inStream >> budget >> ch >> rating >> ch;
		while (ch != ']') {
			inStream >> event >> ch;
			// The following loop removes any multiples.
			for (unsigned int i = 0; i < requestEvents.size(); i++)
				if (&events.at(event) == requestEvents.at(i))
					requestEvents.erase(requestEvents.begin() + i);

			requestEvents.push_back(&events.at(event));
		}
		if (inStream.eof())
			break;
		sort(requestEvents.begin(), requestEvents.end(), Event::sortByCost);
		ClientRequest request(budget, rating, requestEvents);
		requests.push_back(request);

	}
	/*
	 * Sort all the requests by putting the highest budgets at the top of the list.
	 * Theory is that if they appear later in the list and get rejected there's a lot
	 * of potentially lost profit for the Travel Agent.
	 */
//	sort(requests.begin(), requests.end(), ClientRequest::sortByBudget);
//	reverse(requests.begin(), requests.end());

	/*Another theory is that in general flights seem to generate the most profit so
	 * if I try and make sure all the single events requests get flights then I
	 * potentially maximizing the amount of flights sold.
	 */
	sort(requests.begin(), requests.end(), ClientRequest::sortbySize);
	return requests;
}

TravelAgent::~TravelAgent() {}

