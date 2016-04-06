

#include <cassert>	
#include <cstdlib>
#include <string>
#include <iostream>
#include <cassert>
#include <sstream>
#include <fstream>
#include <string>
#include "Player.h"
#include "SimpleList.h"

using namespace std;

// functions
int inputOperation();
int inputPosition();
string inputLastName();
void inputTwoPositions(int *firstPosition, int *secondPosition);
void readFile(SimpleList &list1);
bool checkNumber(int num);



// main
int main() {
	int operation, position, firstPosition, secondPosition, firstPlayerPoint, secondPlayerPoint, point, currentPosition;
	string lastName, firstName, secondName;
	bool compareName = false;
	SimpleList *list= new SimpleList();
	readFile(*list);
	
	// give options to user. the program works if user does not choose 0
	do {
		//assign user input to operator. user must be integer 
		do
		{
			operation = inputOperation();
		} while ((operation < 0) || (operation > 3));

		switch (operation) {
			case 0:
				break;
			// work first operator. print the name of player whose rank is given by user
			case 1:
				position = inputPosition();

				firstName = list->retrieve(20-position).getFirstName();
				secondName = list->retrieve(20-position).getLastName();

				cout << endl << "Name of " << position << ". player is " << firstName << " " << secondName << endl;
				break;
			// work second operator. it find the player ranking with a given last name
			case 2:
				lastName = inputLastName();
				// to find the player
				for (int i = 0; i < 20; i++) {
					if (!(lastName.compare(list->retrieve(19-i).getLastName()))) {
						compareName = true;
						currentPosition = i+1;
					}
				}
				// print rank of player
				if (compareName) {
					cout << endl << "ranking of " << lastName << " is " << currentPosition << endl;
					compareName = false;
				}
				// if player does not exist, print it
				else{
					cout << endl << "player is not ranked " << endl;
				}
				break;
			// work operator 3. to Find difrence of point with two players with given positions
			case 3:
				inputTwoPositions(&firstPosition, &secondPosition);

				firstPlayerPoint = list->retrieve(20-firstPosition).getPointTotal();
				secondPlayerPoint = list->retrieve(20-secondPosition).getPointTotal();
				point = firstPlayerPoint - secondPlayerPoint;
				// if user enter player whose point is lower, this "if" works
				if (point < 0) {
					point = point * -1;
				}

				cout << endl << "there are " << point << " points between " << firstPosition << ". player and " << secondPosition << ". player" << endl;
				break;
			default:
				break;
		}
	} while (operation != 0);

	//cout << position << " " << lastName << " " << firstPosition << " " << secondPosition;
}


// to show operators to user and return user choice
int inputOperation() {
	int input;

	cout << endl << "1: Find the position of player" << endl;
	cout << "2: Find the player ranking with a given last name" << endl;
	cout << "3: Find difrence of point with two players with given positions\n" << endl;
	cout << "Chose an operation (0) for Exit: ";
	cin >> input;

	return input;
}
// if person choose first operator, this function return users rank choice. user must enter int
int inputPosition() {
	int input;

	do
	{
		cout << endl << endl << "Enter a position: ";
		cin >> input;
	} while (checkNumber(input));

	return input;
}
// if user choose second operator, this function send last name of player that user entered
string inputLastName() {
	string input;

	cout << endl << "Enter the last name of player: ";
	cin >> input;

	return input;
}
// if user choose third operator, this function asks and changes first and second player ranked
void inputTwoPositions(int * firstPosition, int * secondPosition){
	int first_Position, second_Position;
	// for first one
	do{
		cout << endl << "Enter the position of first player: ";
		cin >> first_Position;
	} while (checkNumber(first_Position));
	// for second one
	do{
		cout << endl << "Enter the position of first player: ";
		cin >> second_Position;
	} while (checkNumber(second_Position));
	// to change the values
	*firstPosition = first_Position;
	*secondPosition = second_Position;
}
// it checks number if it is between 1 and 20, send true
bool checkNumber(int num) {
	if ((num < 1) || (num >20)) {
		return true;
	}

	else {
		return false;
	}
}
// to read file and add the list
void readFile(SimpleList &list1) {
	string firstName, secondName, country, line;
	int point, rank=1;

	ifstream inFile("players.txt");

	while (!(inFile.eof())) {
		getline(inFile, firstName, ' ');
		getline(inFile, secondName, ' ');
		getline(inFile, line, ' ');
		point = atoi(line.c_str());
		getline(inFile, country, '\n');
		TennisPlayer *tennisPlayer = new TennisPlayer(firstName, secondName, rank, point, country);
		list1.insert(*tennisPlayer, rank - 1);
	}
}
