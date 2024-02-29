/* Michael Belyayev
25 January 2024
This program allows a user to manipulate and visualize a 12 Hour clock 
and a 24 Hour clock.*/


#include <iostream>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <cctype>
#include <cstring>
#include <string>
#include "functions.h"
#include <vector>
#include <sstream>



using namespace std;


// Function to receive initial userInput

void UserInput(vector<int>& times) {
	// Declaring & initializing variables for input validation
	bool hrV = false;
	bool hrM = false;
	bool hrS = false;
	int currHr;
	int currMin;
	int currS;

	// Reading in the current time from user w/ input validation checks
	while (hrV == false) {
		cout << "Please enter the current hour from 0-23?" << endl;
		cin >> currHr;
		hrV = HRValidation(currHr);
		if (hrV == false) {
			cout << "Invalid hour value entered. Enter number from 0-23." << endl;
		}
	}
	times.at(0) = currHr;// populating vector for later use
	
	while (hrM == false) {
		cout << "Please enter the current minute from 0-59" << endl;
		cin >> currMin;
		hrM = MinSecValidation(currMin);
		if (hrM == false) {
			cout << "Invalid Minute value entered. Enter number from 0-59." << endl;
		}
	}
	times.at(1) = currMin;  // populating the vector for later use
	while (hrS == false) {
		cout << "Please enter the current seconds from 0-59?" << endl;
		cin >> currS;
		hrS = MinSecValidation(currS);
		if (hrS == false) {
			cout << "Invalid Seconds value entered. Enter number from 0-59." << endl;
		}
	}
	times.at(2) = currS; // populating the vector for later use
	cout << endl << endl;
}

//Formats ints as 2 digit strings
string twoDigitString(unsigned int n) {
	stringstream ss;
	string newStr;

	if ((n <= 9) && (n >= 0)) {
		ss << std::setw(2) << std::setfill('0') << n;
		newStr = ss.str();
	}
	else {
		newStr = to_string(n);
	}
	return newStr;
}

//Function for Displayingm multiples of the same Character
string nCharString(int n, char c) {
	string newStr;
	newStr = string(n, c);
	return newStr;
}

//Formats and returns 12-hour time
string formatTime12(unsigned int h, unsigned int m, unsigned int s) {

	string designStr;
	if ((h >= 0) && (h <= 11)) {
		designStr = "A M";
	}
	else {
		designStr = "P M";
		h = h - 12;

	}
	if (h == 0) {
		h = 12;
	}

	string newStr = twoDigitString(h) + ":" + twoDigitString(m) + ":" + twoDigitString(s) + " " + designStr;
	return newStr;
}

//Formats and returns 24-hour time string
string formatTime24(unsigned int h, unsigned int m, unsigned int s) {

	string newTime = twoDigitString(h) + ":" + twoDigitString(m) + ":" + twoDigitString(s);

	return newTime;
}

//Prints the menu for user
void printMenu(string strings[], unsigned int size, unsigned char width) {

	cout << nCharString(width, '*') << endl;

	for (int i = 0; i < size; ++i) {
		int lengthOfLine = width - 7 - strings[i].size();
		cout << "* " << i + 1 << " - " << strings[i] << nCharString(lengthOfLine, ' ') << "*" << endl;
		if (i != size - 1) {
			cout << endl;
		}
	}
	cout << nCharString(width, '*') << endl;

}



//Displays the clocks for user
void displayClocks(unsigned int h, unsigned int m, unsigned int s) {

	cout << nCharString(27, '*') << "   " << nCharString(27, '*') << endl;
	cout << "*" << nCharString(6, ' ') << "12-HOUR CLOCK" << nCharString(6, ' ') << "*   ";
	cout << "*" << nCharString(6, ' ') << "24-HOUR CLOCK" << nCharString(6, ' ') << "*" << endl;
	cout << endl;
	cout << "*" << nCharString(6, ' ') << formatTime12(h, m, s) << nCharString(7, ' ') << "*   ";
	cout << "*" << nCharString(8, ' ') << formatTime24(h, m, s) << nCharString(9, ' ') << "*" << endl;
	cout << nCharString(27, '*') << "   " << nCharString(27, '*') << endl;
}

//Add one hour
void addOneHour(vector<int>& times) {
	int h = times.at(0);
	if ((h >= 0) && (h <= 22)) {
		h += 1;
	}
	else {
		h = 0;
	}
	times.at(0) = h;
}

//Adds one minute
void addOneMinute(vector<int>& times) {
	int m = times.at(1);
	if ((m >= 0) && (m <= 58)) {
		m += 1;
	}
	else {
		m = 0;
		addOneHour(times);
	}

	times.at(1) = m;
}

//Adds one second
void addOneSecond(vector<int>& times) {
	int s = times.at(2);
	if ((s >= 0) && (s <= 58)) {
		s += 1;
	}
	else {
		s = 0;

		addOneMinute(times);
	}
	times.at(2) =s;
}

int main() {
	// Delcaring Variables
	vector<int> times(3);
	string myStrings[4] = { "Add One Hour", "Add One Minute", "Add One Second", "Exit Program" };
	bool validMenu = false;
	int userSelect;

	//Calls function to get user input of current time and saves it to 
	UserInput(times);

	//Displaying the current clocks
	displayClocks(times.at(0), times.at(1), times.at(2));

	//Displaying the Menu for the user
	printMenu(myStrings,4, 27);
	
	//Calls Function to get user Selection
	userSelect = getMenuChoice(4);

	while (userSelect != 4) {
		if (userSelect == 1) {
			addOneHour(times);
		}
		else if (userSelect == 2) {
			addOneMinute(times);
		}
		else {
			addOneSecond(times);
		}

		//Displaying the current clocks
		displayClocks(times.at(0), times.at(1), times.at(2));

		//Displaying the Menu for the user
		printMenu(myStrings, 4, 27);

		//Calls Function to get user Selection
		userSelect = getMenuChoice(4);
	}
	cout << "Thank you for using this program.";

}