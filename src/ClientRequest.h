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
	static int clientCount;
	double budget;
	double requestTotal = 0;
	int hotelRating;
	int firstDay = 9;
	int lastDay = 0;
	int clientNo;
	int requestError = 0;
	vector<Event*> events;

	ClientRequest(double amount, int star, vector<Event*> eventList);

	void print();
	// Print a formatted version of the ClientRequest.
	static bool sortBySize (ClientRequest const & left, ClientRequest const & right);
	// Sort a vector of ClientRequests by the amount of events they have.

	static bool sortByBudget (ClientRequest const & left, ClientRequest const & right);
	// Sort a vector of ClientRequests by their budgets.

	static bool sortByRating (ClientRequest const & left, ClientRequest const & right);
	// Sort a vector of ClientRequests by their hotel Ratings.
	void calculateTripLength();
	~ClientRequest();

};

