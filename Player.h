
#ifndef TENNISPLAYER
#define TENNISPLAYER

#include <iostream>
using namespace std;

class TennisPlayer {
public:
	TennisPlayer();
	// create TennisPlayer object
	TennisPlayer(string initFirstName, string initLastName, int initRanking, int initPointTotal, string initCountry);

	string getFirstName() const;
	// to get first name
	string getLastName() const;
	// to get lastname
	int getRanking() const;
	// to get rank
	int getPointTotal() const;
	// to get point
	string getCountry() const;
	// to get country
	void setRanking(int newRanking);
	// to change rank
	void setPointTotal(int newPointTotal);
	// to change point
	friend ostream& operator<< (ostream & out, const TennisPlayer & f);
	// to access private values

private:
	string firstName;
	string lastName;
	int ranking;
	int pointTotal;
	string country;
};
#endif
