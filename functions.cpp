#include <iostream>
#include <iomanip>
#include <vector>
#include <sstream>
#include <string>

using namespace std;



// user Hour input validation
bool HRValidation(int hr) {
	bool hrValid = false;

	if ((hr >= 0) && (hr <= 23)) {
		hrValid = true;
	}
	return hrValid;
}

//user Minute & second Input Validation
bool MinSecValidation(int val) {
	bool valid = false;

	if ((val >= 0) && (val <= 59)) {
		valid = true;
	}
	return valid;
}

//Receives and returns the users menu choice
unsigned int getMenuChoice(unsigned int maxChoice) {
	bool validC = false;
	int userChoice;
	while (validC == false) {
		cout << " Please enter numer that corresponds to your desired selection." << endl;
		cin >> userChoice;
		if ((userChoice >= 1) && (userChoice <= maxChoice)) {
			validC = true;
		}
		else {
			cout << "You have enterd an invalid selection." << endl;
		}
	}
	return userChoice;
}
