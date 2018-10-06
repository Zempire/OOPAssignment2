/*
 * Hotel.h
 *
 *  Created on: 27 Sep. 2018
 *      Author: Zempire
 */

#include <iostream>
#include <string>

using namespace std;

class Hotel{
public:
	Hotel(double price, int quantity, int stars);
	//Base constructor for Hotel.
	void print();
	// Print out the details of a Hotel.
	int getQuantity(int day);
	// Return the quantity of rooms left for a specific day.
	void sellTicket(int day);
	//Minus one from the quantity total of a specific day.
	double getRoomPrice(int day);
	//Returns discounted price.
	double getFullPrice();
	// returns fullPrice variable.
	~Hotel();
private:
	static const int days = 9;	//9 days as no one needs a room on the 10th day.
	int roomCount;
	int rating;
	double fullPrice;
	int availableRooms[days];
};

