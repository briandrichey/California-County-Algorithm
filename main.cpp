/*
Final Project
Brian Richey
CS111 sect 3
*/

using namespace std;
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "library.h"
int main() {
	string wordkey;
	float numkey;
	int menu, numofcounties, index;
	 index = 0;
	 int size = 57;
	County newCounty, targetCounty;
	County countyArr[size], searchArr[index];

	ifstream fin("inputData.txt");

	if (fin.is_open()) {
		readCounty(fin, countyArr, size, numofcounties);
	}
	else {
		cout << endl << "ERROR: Cannot open file." << endl;
	}
	fin.close();


	do {
		cout << endl << "Welcome to the main menu!" << endl << endl;
		cout << "1) Overall Summary of Data" << endl;
		cout << "2) Search the Data by population size" << endl;
		cout << "3) Search the Data by word or letter" << endl;
		cout << "4) Add a new Data member" << endl;
		cout << "5) Delete a Data member" << endl;
		cout << "6) Exit Program" << endl << endl;
		cout << "Select an option by entering a number: ";
		cin >> menu;
		cin.ignore();

		switch (menu) {
		case 1:
			printCounty(countyArr, numofcounties);
			break;

		case 2:
			int answer1, answer2;
			cout << endl << "Would you like to search counties by:" << endl;
			cout << "1) 1979 population size" << endl;
			cout << "2) 2019 population size" << endl;
			cout << "Enter number(1 or 2): ";
			cin >> answer1;
			cin.ignore();
			cout << "Enter a population number to search by: ";
			cin >> numkey;
			cin.ignore();
			cout << endl << "Would you like to see counties with populations:" << endl;
			cout << "1)Equal or Larger than search value" << endl;
			cout << "2)Equal or Smaller than search value" << endl;
			cout << "Enter number(1 or 2): ";
			cin >> answer2;
			cin.ignore();
			searchByPop(countyArr, searchArr, answer1, answer2, numkey, numofcounties, index);

			printSearch(searchArr, index);
			break;

		case 3:
			cout << endl << "Enter a word or letter to search by: ";
			getline(cin, wordkey);
			searchByWord(countyArr, searchArr, numofcounties, wordkey, index);
			printSearch(searchArr, index);
			break;

		case 4:
			getCounty(newCounty);
			addCounty(countyArr, numofcounties, size, newCounty);
			cout << endl << "New County: " << newCounty.name << " successfully added." << endl;
			printCounty(countyArr, numofcounties);
			break;

		case 5:
			deleteCounty(countyArr, numofcounties, size, newCounty);
			cout << endl << "County: " << newCounty.name << " successfully removed from data." << endl;
			printCounty(countyArr, numofcounties);
			break;

		case 6:
			cout << "You have exited the program.";
			return 0;
			break;

		default:
			cout << endl << "Invalid input" << endl;

		}


	} while (menu != 6);
}