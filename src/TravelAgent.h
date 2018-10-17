
/*
 * TravelAgent.h
 *
 *  Created on: 27 Sep. 2018
 *      Author: Zempire
 */

#include <iostream>
#include <string>
#include <vector>
#include "Ticket.h"
#include "FlightTicket.h"
#include "HotelVoucher.h"
#include "EventTicket.h"
#include "Event.h"
#include "ClientRequest.h"
#include "Package.h"
#include "Hotel.h"

using namespace std;

static int REQUEST_ERROR = 0;	//Used by adaptRequest and set by checkRequest.
class TravelAgent{
public:
	TravelAgent();
	// Build the events as part of the constructor.

	void doSomeWork(vector<ClientRequest> requests);
	//Do stuff as opposed to doing it in the driver file.

	Event getEvent(int position);
	//Returns the event at the requested position.

	bool checkRequest(ClientRequest & request);
	// Checks if a ClientRequest is possible.

	Package buildPackage(ClientRequest request);
	// Construct a package and add it to the TravelAgents packages array.
	//clientNo is the ClientRequest's position in array.

	void printRequests(vector<ClientRequest> requests);

	double getProfit();

	void sortRequests(vector<ClientRequest> & requests, bool (*f)(const ClientRequest &, const ClientRequest &));
	//Gives all the different ClientRequest sorters a common function.

	double calculateFlight(int direction, int day);
	// Returns the cost of a flight.

	vector<ClientRequest> generateRequestsFromFile(string file);
	// Reads all requests from a file into a vector.

	virtual ~TravelAgent();
protected:
	vector<Hotel> hotels;	//Rating is equal to position + 3.
	vector<Event> events;	// To be read from events.txt
	vector<ClientRequest> newRequests;
	vector<ClientRequest> requests[2];
	vector<Package> packages;	//An array of successfully created packages.
	double profit = 0;

};






