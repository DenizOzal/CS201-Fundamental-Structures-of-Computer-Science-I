// CS201
// HW1
// Deniz Semih Özal
// 21802414
// Section 01
#define _CRT_SECURE_NO_WARNINGS
#include "MovieBookingSystem.h"
#include <iostream>
#include <ctime>
#include <string>
#include <cstring>
using namespace std;
MovieBookingSystem::MovieBookingSystem() {
	numOfMovies = 0;
	numOfResCode = 0;
	uniqueResCode = 0;
	movies = NULL;
	booking = NULL;
}
MovieBookingSystem::~MovieBookingSystem() {
	for (int i = 0; i < numOfMovies; i++) {
		for (int j = 0; j < movies[i].getNoOfRow() + 1; j++)
			delete[] movies[i].seatPlan[j];
		delete movies[i].seatPlan;
	}
		delete[] booking;
		delete[] movies;
}
void MovieBookingSystem::addMovie(const long movieID, const int audienceRadius) {
	int counter = 0;
	time_t movie_time = movieID;
	char* tm = ctime(&movie_time);
		if (tm[strlen(tm) - 1] == '\n') {
			tm[strlen(tm) - 1] = '\0';
		}

		// Checking movieID whether it is used before
		for (int i = 0; i < numOfMovies; i++) {
			if (movieID == movies[i].getMovie_ID()) {
				counter = 1;
			}
		}
		if (counter == 1) {
			cout << "Movie at " << tm << " already exists\n";
		}
		// Checking radius whether it is between [0,7] or not
		else if (audienceRadius < 0 && audienceRadius > 7) {
			cout << "Error " << audienceRadius << " Radius can be maximum 7!\n";
		}
		else {
			// temp_movie and movies points same base address
			Movie* temp_movie = movies;

			movies = new Movie[numOfMovies + 1];


			// Copying elements from movies into the temp_movie 
			for (int i = 0; i < numOfMovies; i++) {
				movies[i] = temp_movie[i];
			}

			// Setting new movie object at the last index of movies
			movies[numOfMovies].setMovie_ID(movieID);
			movies[numOfMovies].setAudienceRadius(audienceRadius);

			int row_number = 0;
			int col_number = 0;

			//Creating row number according to radius
			for (int i = 0; i < numOfRow; i += (audienceRadius + 1)) {
				row_number++;
			}

			//Creating column number according to radius
			for (int i = 0; i < numOfColumn; i += (audienceRadius + 1)) {
				col_number++;
			}
			movies[numOfMovies].setNoOfRow(row_number);
			movies[numOfMovies].setNoOfColumn(col_number);

			int total_seat = row_number * col_number;

			movies[numOfMovies].setNumOfSeats(total_seat);
			movies[numOfMovies].setSeatPlan(row_number, col_number); // Setting a seat plan

			// Print Adding


			cout << "Movie at " << tm << " has been added\n";

			// Increment by one number of movies
			numOfMovies++;

			// Delete temporary array
			delete[] temp_movie;
		}
}
void MovieBookingSystem::cancelMovie(const long movieID) {
	int cancelled_index = -1;
	time_t movie_time = movieID;
	char* tm = ctime(&movie_time);
		if (tm[strlen(tm) - 1] == '\n') {
			tm[strlen(tm) - 1] = '\0';
		}
		// Checking movieID whether it is used before
		for (int i = 0; i < numOfMovies; i++) {
			if (movieID == movies[i].getMovie_ID()) {
				cancelled_index = i;
			}
		}
		if (cancelled_index == -1) {
			cout << "Movie at " << tm << " does not exist\n";
		}
		else {
			// temp_movie and movies points same base address
			Movie* temp_movie = movies;

			// Created dynamic allocated array of movies
			movies = new Movie[numOfMovies - 1];

			// Copying elements from start point to cancelled index into movies
			for (int i = 0; i < cancelled_index; i++) {
				movies[i] = temp_movie[i];
			}
			// Copying elements from cancelled index point to last index into movies
			for (int i = cancelled_index; i < numOfMovies - 1; i++) {
				movies[i] = temp_movie[i + 1];
			}

			cout << "Movie at " << tm << " has been cancelled\n";

			// Decrement by one number of movies
			numOfMovies--;

			
			// Delete temporary array
			delete[] temp_movie;
		}
}
	void MovieBookingSystem::showAllMovies(){
		if ( numOfMovies == 0)
			cout << "No movie on show\n";
		else {
			cout << "Movies on show:\n";
			for (int i = 0; i < numOfMovies; i++) {
				time_t movie_time = movies[i].getMovie_ID();
				char* tm = ctime(&movie_time);

				if (tm[strlen(tm) - 1] == '\n') {
					tm[strlen(tm) - 1] = '\0';
				}

				cout << "Movie at " << tm << " (" << movies[i].getNumOfSeats() << "  available seats)\n";
			}
		}
	}
	void MovieBookingSystem::showMovie(const long movieID) {
		int movie_index = -1;
		for (int i = 0; i < numOfMovies; i++) {
			if (movieID == movies[i].getMovie_ID())
				movie_index = i;
		}
		if (movie_index == -1)
			cout << "There is no movie with movieID " << movieID << "\n\n";
		else {
			time_t movie_time = movieID;
			char* tm = ctime(&movie_time);
			if (tm[strlen(tm) - 1] == '\n') {
				tm[strlen(tm) - 1] = '\0';
			}
			cout << "Movie at " << tm << " has " << movies[movie_index].getNumOfSeats() << " available seats\n";

			for (int i = 0; i < movies[movie_index].getNoOfRow() + 1; i++) {
				for (int j = 0; j < movies[movie_index].getNoOfColumn() + 1; j++) {
						cout << movies[movie_index].getSeatPlan()[i][j] << "  ";
				}
				cout << "\n";
			}
			cout << "\n";
		}
	}
	int MovieBookingSystem::makeReservation(const long movieID, const int row, const char col) {
		int movie_index = -1;
		if (numOfMovies != 0) {
			for (int i = 0; i < numOfMovies; i++) {
				if (movieID == movies[i].getMovie_ID())
					movie_index = i;
			}
			if (movie_index == -1)
				cout << "There is no movie with movieID " << movieID << "\n";
			else {
				movies[movie_index].setReservation(movieID, row, col);
				int spesific_row = movies[movie_index].getRow();
				int spesific_col = movies[movie_index].getCol();
				
					// Creating dynamic array
					Booking* temp_booking = booking;
					// temp_booking and booking points same basea address
					booking = new Booking[numOfResCode + 1];
					// Copying array into the booking
					for (int i = 0; i < numOfResCode; i++) {
						booking[i] = temp_booking[i];
					}
					// Setting properties
					// Array index represents uniqueCode
					uniqueResCode++;

					booking[numOfResCode].setSpesific_movieID(movieID);
					booking[numOfResCode].setSpesific_realRow(row);
					booking[numOfResCode].setSpesific_realCol(col);
					booking[numOfResCode].setSpesific_row(spesific_row);
					booking[numOfResCode].setSpesific_col(spesific_col);
					booking[numOfResCode].setSpesific_resCode(uniqueResCode);
					//Delete temp
					delete[] temp_booking;
				}
				//Increment by one number of res code
				numOfResCode++;
				//Return unique resCode
				return uniqueResCode;
			}
		return 0;
		}
	
	void MovieBookingSystem::cancelReservations(const int numRes, const int* resCode) {
		int counter = 0;
		if (numOfResCode == numRes) {
			for (int i = 0; i < numRes; i++) {
				for (int j = 0; j < numOfResCode; j++) {
					if (resCode[i] == booking[j].getSpesific_resCode()) {
						for (int k = 0; k < numOfMovies; k++) {
							if (booking[j].getSpesific_movieID() == movies[k].getMovie_ID()) {
								counter++;
								movies[k].setSeat_toO(booking[j].getSpesific_row(), booking[j].getSpesific_col());
								time_t movie_time = movies[k].getMovie_ID();
								char* tm = ctime(&movie_time);
								if (tm[strlen(tm) - 1] == '\n') {
									tm[strlen(tm) - 1] = '\0';
								}
								cout << "Reservation on Code " << booking[j].getSpesific_resCode() << " is canceled: Seat " <<
									movies[k].getRealCol() << movies[k].getRealRow() << " in Movie at " << tm << "\n";
							}
						}
					}
				}
			}
			numOfResCode = 0;
		}
	
		if (counter != numRes)
			cout << "Some reservation codes do not exist. Cancelation is failed\n";
		else {
			delete[] booking;
			booking = NULL;
		}
	}
	void MovieBookingSystem::showReservation(const int resCode) {
		int resCode_index = -1;
		int counter = -1;
		for (int i = 0; i < numOfResCode; i++) {
			if (booking[i].getSpesific_resCode() == resCode) {
				resCode_index = i;
			}
		}
		if (resCode_index == -1) {
			cout << "No reservation with Code " << resCode << "\n";
		}
		else {
			for (int j = 0; j < numOfMovies; j++) {
				if (booking[resCode_index].getSpesific_movieID() == movies[j].getMovie_ID()) {
					counter++;
					time_t movie_time = movies[j].getMovie_ID();
					char* tm = ctime(&movie_time);
					if (tm[strlen(tm) - 1] == '\n') {
						tm[strlen(tm) - 1] = '\0';
					}
					char c = booking[resCode_index].getSpesific_col() + 64;
					cout << "Reservation with Code " << resCode << ": Seat " << booking[resCode_index].getSpesific_realCol()
						<< booking[resCode_index].getSpesific_realRow() << " " << tm << "\n";
				}
			}
		}
		if( resCode_index != -1 && counter == -1)
			cout << "No reservation with Code " << resCode;
	}