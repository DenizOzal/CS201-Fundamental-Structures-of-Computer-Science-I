// CS201
// HW1
// Deniz Semih Özal
// 21802414
// Section 01
#ifndef MOVIEBOOKINGSYSTEM_H
#define MOVIEBOOKINGSYSTEM_H
#include "Movie.h"

class MovieBookingSystem {
public:
	const static int numOfRow = 30;
	const static int numOfColumn = 26;
	MovieBookingSystem();
	~MovieBookingSystem();
	void addMovie(const long movieID, const int audienceRadius);
	void cancelMovie(const long movieID);
	void showAllMovies();
	void showMovie(const long movieID);
	int makeReservation(const long movieID, const int row, const char col);
	void cancelReservations(const int numRes, const int* resCode);
	void showReservation(const int resCode);
private:
	Movie* movies;
	Booking* booking;
	int numOfMovies;
	int numOfResCode;
	int uniqueResCode;
	// ...
	//you may define additional member functions and data members, if necessary.
};
#endif