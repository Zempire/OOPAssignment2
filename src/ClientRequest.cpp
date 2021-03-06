/*
 * ClientRequest.cpp
 *
 *  Created on: 30 Sep. 2018
 *      Author: Zempire
 */

#include <iostream>
#include <string>
#include "ClientRequest.h"

using namespace std;

ClientRequest::ClientRequest(double amount, int star, vector<Event*> eventList) {
	clientCount++;
	budget = amount;
	hotelRating = star;
	events = eventList;
	clientNo = clientCount;
}

void ClientRequest::print() {
	cout << "\nBUDGET: " << budget << endl;
	cout << "MIN RATING: " << hotelRating << " stars\n";
	cout << "CHOSEN EVENTS:\n";
	for (unsigned int i = 0; i < events.size(); i++) {
		cout << " - "<< events.at(i)->getName() << endl;
	}
}

bool ClientRequest::sortBySize (ClientRequest const & left, ClientRequest const & right) {
	return left.events.size() < right.events.size();
}

bool ClientRequest::sortByBudget (ClientRequest const & left, ClientRequest const & right) {
	return left.budget < right.budget;
}

bool ClientRequest::sortByRating (ClientRequest const & left, ClientRequest const & right) {
	return left.hotelRating < right.hotelRating;
}

void ClientRequest::calculateTripLength() {
	firstDay = 9;
	lastDay = 0;
	for (unsigned int i = 0; i < events.size(); i++) {
		if (events.at(i)->getDay() < firstDay)
			firstDay = events.at(i)->getDay();
		if (events.at(i)->getDay() > lastDay)
			lastDay = events.at(i)->getDay();
	}
}

ClientRequest::~ClientRequest(){

}

int ClientRequest::clientCount = 0;




