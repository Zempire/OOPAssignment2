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

int main() {
	int userChoice = 0;

	cout << "WELCOME to Eugene's Travel Agent.\n";
	cout << "Please choose from one of the following options:\n";

	while(true) {
		cout << "\n1. Test Simple Agent.\n";
		cout << "2. Test Request Generator.\n";
		cout << "3. Test Smart Agent.\n";
		cout << "4. Exit Program.\n";

		cin >> userChoice;

		switch(userChoice) {
		case 1: {
			TravelAgent agent;
			agent.doSomeWork(agent.generateRequestsFromFile("requestList2.txt"));
			break;
		}
		case 2: {
			//TODO: Add some code here once requestGenerator is built.
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
			return 0;
			break;
		}
		default:
			break;
		}
	}
	return 0;
}




