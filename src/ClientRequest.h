/*
 * Client.h
 *
 *  Created on: 27 Sep. 2018
 *      Author: Zempire
 */
#include <iostream>
#include<string>
#include <vector>
#include <algorithm>
#include "Event.h"


using namespace std;

class ClientRequest {
public:
	double budget;
	int hotelRating;
	vector<Event*> events;
	int firstDay = 9;
	int lastDay = 0;
	double requestTotal = 0;

	ClientRequest(double amount, int star, vector<Event*> eventList);

	void print();
	// Print a formatted version of the ClientRequest.
	static bool sortbySize (ClientRequest const & left, ClientRequest const & right);
	// Sort a vector of ClientRequests by the amount of events they have.

	static bool sortByBudget (ClientRequest const & left, ClientRequest const & right);
	// Sort a vector of ClientRequests by their budgets.

	~ClientRequest();
private:

};


