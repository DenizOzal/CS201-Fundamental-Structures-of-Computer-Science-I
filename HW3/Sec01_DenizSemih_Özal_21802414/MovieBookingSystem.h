//MovieBookingSystem Class has fundamental functions that create a movie booking system 
#pragma once
#include "MovieList.h"
#include "ReservationList.h"
#include "BookingList.h"
#include "SeatList.h"
class MovieBookingSystem {
public:
	const static int numOfRow = 30;
	const static int numOfColumn = 26;
	MovieBookingSystem();
	~MovieBookingSystem();
	void addMovie(const long movieID, const int audienceRadius);
	void cancelMovie(const long movieID);
	void showAllMovies() const;
	void showMovie(const long movieID) const;
	int makeReservation(const long movieID, const int row, const char col);
	void cancelReservations(ReservationList resCode);
	void showReservation(const int resCode) const;
private:
	MovieList movies;
	BookingList bookingList;
	SeatList seatList;
	int numOfMovies;
	int numOfResCode;
	int uniqueResCode;
};
