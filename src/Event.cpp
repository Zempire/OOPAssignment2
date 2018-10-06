/*
 * Event.cpp
 *
 *  Created on: 29 Sep. 2018
 *      Author: Zempire
 */

#include <iostream>
#include <string>
#include "Event.h"

using namespace std;

Event::Event(string name, int day, double price, int count) {
	eventName = name;
	eventDay = day;
	eventPrice = price;
	quantity = count;
}

void Event::print() {
	cout << "\nEVENT: " << eventName << endl;
	cout << " - Day: " << eventDay << endl;
	cout << " - Price: " << eventPrice << endl;
	cout << " - Available: " << quantity << endl;
}

string Event::getName() {
	return eventName;
}

double Event::getPrice() {
	return eventPrice;
}

int Event::getDay() {
	return eventDay;
}

int Event::getQuantity() {
	return quantity;
}

void Event::sellTicket() {
	quantity--;
}

bool Event::sortByDay(Event * left, Event * right) {
	return left->eventDay < right->eventDay;
}

bool Event::sortByCost(Event * left, Event * right) {
	return left->eventPrice < right->eventPrice;
}



Event::~Event(){};
