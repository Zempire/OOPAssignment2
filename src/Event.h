/*
 * Event.h
 *
 *  Created on: 27 Sep. 2018
 *      Author: Zempire
 */
#ifndef EVENT_H
#define EVENT_H

#include <iostream>
#include <string>

using namespace std;

class Event{
public:
	Event(string name, int day, double price, int quantity);

	void print();
	// Print out the details of an event.
	string getName();
	// Returns the events name.
	double getPrice();
	// Return the price of the event.
	int getDay();
	// Return the day of the event.
	int getQuantity();
	// Return the quantity of seats left.
	void sellTicket();
	//Minus one from the quantity total.
	static bool sortByDay(Event * left, Event * right);
	// Sorts a vector of Event pointers by order of day.
	static bool sortByCost(Event * left, Event * right);
	// Sorts a vector of Event pointers by order of cost.
	~Event();
private:
	string eventName;
	int eventDay;
	double eventPrice;
	int quantity;
};


#endif


