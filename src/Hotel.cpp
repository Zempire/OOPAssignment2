/*
 * Hotel.cpp
 *
 *  Created on: 29 Sep. 2018
 *      Author: Zempire
 */

#include <iostream>
#include <string>
#include "Hotel.h"

using namespace std;

Hotel::Hotel(double price, int quantity, int stars) : roomCount(quantity) {
	fullPrice = price;
	for (int i = 0; i < days; i++) {
		availableRooms[i] = quantity;
	}
	rating = stars;
}

void Hotel::print() {
	cout << "\n" << rating << " STAR HOTEL: ";
	cout << "$" << fullPrice << " a night.\n";
	for (int i = 0; i < days; i++) {
		cout << "Day " << i << ": " << availableRooms[i]
			 << " tickets available.\n";
	}
}

int Hotel::getQuantity(int day) {
	return availableRooms[day];
}

void Hotel::sellTicket(int day) {
	availableRooms[day]--;
}

double Hotel::getRoomPrice(int day) {

	if (availableRooms[day] > (roomCount / 2)) {
		if (rating == 5)
			return fullPrice * 0.6;
		else if (rating == 4)
			return fullPrice * 0.8;
		else
			return fullPrice;
	} else if (availableRooms[day] > roomCount * 0.8 && rating == 5) {
		return fullPrice * 0.8;
	} else
		return fullPrice;
}

double Hotel::getFullPrice() {
	return fullPrice;
}

Hotel::~Hotel(){};



