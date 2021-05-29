#define _CRT_SECURE_NO_WARNINGS
#include "MovieBookingSystem.h"
#include <cstddef>
#include <string> 
#include <ctime>
#include <iostream>
#include "Movie.h"
using namespace std;
MovieBookingSystem::MovieBookingSystem() {
	numOfMovies = 0;
	numOfResCode = 0;
	uniqueResCode = 0;
}
MovieBookingSystem::~MovieBookingSystem() {
}
void MovieBookingSystem::addMovie(const long movieID, const int audienceRadius) {
	int counter = 0;

	// Creating seat_flag for seat availability
	int seat_flag = 1;

	// Creating a temp movie object
	Movie temp_movieObj;

	// Temp seats
	SeatList temp_seats;

	// Setting movieID to corresponding date
	time_t movie_time = movieID;
	char* tm = ctime(&movie_time);
	if (tm[strlen(tm) - 1] == '\n') {
		tm[strlen(tm) - 1] = '\0';
	}

	// Checking movieID whether it is used before
	for (int i = 1; i <= numOfMovies; i++) {
		movies.retrieve(i, temp_movieObj);
		if (movieID == temp_movieObj.getMovie_ID()) {
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
		int row_number = 0;
		int col_number = 0;
		//Creating row number according to radius
		for (int i = 1; i <= numOfRow; i += (audienceRadius + 1)) {
			row_number++;
		}

		//Creating column number according to radius
		for (int i = 1; i <= numOfColumn; i += (audienceRadius + 1)) {
			col_number++;
		}
		//Adding properties of new movie object
		temp_movieObj.setAudienceRadius(audienceRadius);
		temp_movieObj.setMovie_ID(movieID);
		temp_movieObj.setNoOfRow(row_number);
		temp_movieObj.setNoOfColumn(col_number);
		temp_movieObj.setNumOfSeats(row_number * col_number);

		temp_seats = temp_movieObj.getSeatList();
		//Creating a seat plan for new movie object
		//Every seat is set to available firstly

		for (int i = 1; i <= temp_movieObj.getNumOfSeats(); i++) {
			//cout << "ANAN";
			temp_seats.insert(temp_seats.getLength() + 1, seat_flag);
		}
		//cout << "Baban";
		// Inserting new movie into the movies
		temp_movieObj.setSeatList(temp_seats);
		//temp_movieObj.setSeats(temp_seats);
		movies.insert(movies.getLength() + 1, temp_movieObj);

		// Print Adding
		cout << "Movie at " << tm << " has been added\n";

		// Increment by one number of movies
		numOfMovies++;
	}
}
void MovieBookingSystem::cancelMovie(const long movieID) {
	int cancelled_index = -1;

	// Setting movieID to corresponding date
	time_t movie_time = movieID;
	char* tm = ctime(&movie_time);
	if (tm[strlen(tm) - 1] == '\n') {
		tm[strlen(tm) - 1] = '\0';
	}

	// Creating a temp movie object
	Movie temp_movieObj;

	// Checking movieID whether it is used before
	for (int i = 1; i <= numOfMovies; i++) {
		movies.retrieve(i, temp_movieObj);
		if (movieID == temp_movieObj.getMovie_ID()) {
			cancelled_index = i;
		}
	}
	if (cancelled_index == -1) {
		cout << "Movie at " << tm << " does not exist\n";
	}
	else {
		// Removing cancelled item from movies list
		movies.remove(cancelled_index);

		// Print Removing
		cout << "Movie at " << tm << " has been cancelled\n";

		// Decrement by one number of movies
		numOfMovies--;
	}
}
void MovieBookingSystem::showAllMovies() const {
	// Creating a temp movie object
	Movie temp_movieObj;

	if (numOfMovies == 0)
		cout << "No movie on show\n";
	else {
		cout << "Movies on show:\n";
		for (int i = 1; i <= numOfMovies; i++) {
			movies.retrieve(i, temp_movieObj);
			time_t movie_time = temp_movieObj.getMovie_ID();
			char* tm = ctime(&movie_time);

			if (tm[strlen(tm) - 1] == '\n') {
				tm[strlen(tm) - 1] = '\0';
			}

			cout << "Movie at " << tm << " (" << temp_movieObj.getNumOfSeats() << "  available seats)\n";
		}
	}
}
void MovieBookingSystem::showMovie(const long movieID) const {
	// Creating a temp movie object
	Movie temp_movieObj;

	// Creting a temp seatPLan
	SeatList temp_seats;

	int movie_index = -1;
	for (int i = 1; i <= numOfMovies; i++) {
		movies.retrieve(i, temp_movieObj);
		if (movieID == temp_movieObj.getMovie_ID())
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
		movies.retrieve(movie_index, temp_movieObj);
		cout << "TEMP: " << temp_seats.getLength();
		cout << "Movie at " << tm << " has " << temp_movieObj.getNumOfSeats() << " available seats\n";
		cout << "   ";
		// Printing column characters
		for (int i = 1; i <= numOfColumn; i += temp_movieObj.getAudienceRadius() + 1) {
			char column = i + 64;
			cout << column << " ";
		}
		cout << endl;
		for (int i = 1; i <= numOfRow; i += temp_movieObj.getAudienceRadius() + 1) {
			if (i < 10)
				cout << " " << i << " ";
			else
				cout << i << " ";
			int row_beginning = (i / (temp_movieObj.getAudienceRadius() + 1)) + (i % (temp_movieObj.getAudienceRadius() + 1)); // Row Beginning
			int element = ((row_beginning - 1) * temp_movieObj.getNoOfColumn()) + 1;// Traversing element
			// Creating a temp boolean
			int temp_seatFlag;
			for (int j = element; j <= temp_movieObj.getNoOfColumn() * row_beginning; j++) {
				temp_seats.retrieve(j, temp_seatFlag);
				if (temp_seatFlag == 0)
					cout << "X" << " ";
				else
					cout << "O" << " ";
			}
			//cout << temp_seatFlag;
			cout << "\n";
		}
	}
}
int MovieBookingSystem::makeReservation(const long movieID, const int row, const char col) {
	// Creating a temp boolean
	int temp_seatFlag;
	bool column_flag = false;
	bool row_flag = false;;
	// Creating a temp movie object
	Movie temp_movieObj;
	SeatList temp_seats;

	int movie_index = -1;
	if (numOfMovies != 0) {
		for (int i = 0; i < numOfMovies; i++) {
			movies.retrieve(i, temp_movieObj);
			if (movieID == temp_movieObj.getMovie_ID())
				movie_index = i;
		}
		if (movie_index == -1)
			cout << "There is no movie with movieID " << movieID << "\n";
		else {
			time_t movie_time = movieID;
			char* tm = ctime(&movie_time);
			if (tm[strlen(tm) - 1] == '\n') {
				tm[strlen(tm) - 1] = '\0';
			}
			movies.retrieve(movie_index, temp_movieObj);
			temp_seats = temp_movieObj.getSeatList();

			// Checking column is available or not
			for (int i = 1; i <= numOfColumn; i += temp_movieObj.getAudienceRadius() + 1) {
				char column = i + 64;
				if (column == col)
					column_flag = true;
			}
			// CHecking row is available or not
			for (int i = 1; i <= numOfRow; i += temp_movieObj.getAudienceRadius() + 1) {
				if (i == row)
					row_flag = true;
			}
			if (row_flag != true || column_flag != true) {
				string col_string(1, col);
				cout << "Seat " << col_string << row << " is not available in Movie at " << tm << "\n";
			}
			else {
				// Creating integer equivalents of row and column
				int real_column;
				int real_row;
				int index_element;
				//cout << "YARRRAKKKKK";
				// Finding column
				char column = col;
				real_column = column - 64; // A = 1, B = 2 ...
				real_column = (real_column / temp_movieObj.getAudienceRadius() + 1) + (real_column % temp_movieObj.getAudienceRadius() + 1);

				// Finding row
				real_row = (row / temp_movieObj.getAudienceRadius() + 1) + (row % temp_movieObj.getAudienceRadius() + 1);
				index_element = (temp_movieObj.getNoOfRow() * (real_row - 1)) + real_column;

				// Retrieve desired seat
				temp_seats.retrieve(index_element, temp_seatFlag);
				//cout << "TEMP" << temp_seats.getLength();

				if (temp_seatFlag == false) {
					string col_string(1, col);
					cout << "Seat " << col_string << row << " is not available in Movie at " << tm << "\n";
				}
				else {
					// Change flag to false
					temp_seatFlag = false;

					// Remove & Insert to change the element to occupied
					temp_seats.remove(index_element);
					temp_seats.insert(index_element, temp_seatFlag);
					temp_movieObj.setNumOfSeats(temp_movieObj.getNumOfSeats() - 1);

					// Remove & Insert to change the movie element in the movie list
					movies.remove(movie_index);
					movies.insert(movie_index, temp_movieObj);


					// ResCode starts from zero to infinite
					uniqueResCode++;

					// Creating Reservation
					Booking booking;
					booking.setSpesific_movieID(movieID);
					booking.setSpesific_row(row);
					booking.setSpesific_col(col);
					booking.setSpesific_resCode(uniqueResCode);
					booking.setSpesific_indexElement(index_element);

					// Add booking element to the BookingList
					bookingList.insert(bookingList.getLength() + 1, booking);

					// Adding Code to the reservation list
					reservationCodes.insert(reservationCodes.getLength() + 1, uniqueResCode);

					string col_string(1, col);
					cout << "Reservation done for " << col_string << row << " in Movie at " << tm << "\n";

					//Increment by one number of res code
					numOfResCode++;

					//Return unique resCode
					return uniqueResCode;
				}
			}
		}
	}
	return -1;
}
void MovieBookingSystem::cancelReservations(ReservationList resCode) {
	// Creating a temp movie object
	Movie temp_movieObj;
	SeatList temp_seats;
	int temp_resCode;
	bool temp_flag = true;
	Booking booking_temp;
	int counter = 0;
	for (int i = 1; i <= resCode.getLength(); i++) {
		for (int j = 1; j <= bookingList.getLength(); j++) {
			resCode.retrieve(i, temp_resCode);
			bookingList.retrieve(j, booking_temp);
			if (temp_resCode == booking_temp.getSpesific_resCode()) {
				for (int k = 1; k <= movies.getLength(); k++) {
					movies.retrieve(k, temp_movieObj);
					temp_seats = temp_movieObj.getSeatList();
					if (booking_temp.getSpesific_movieID() == temp_movieObj.getMovie_ID()) {
						counter++;
						time_t movie_time = temp_movieObj.getMovie_ID();
						char* tm = ctime(&movie_time);
						if (tm[strlen(tm) - 1] == '\n') {
							tm[strlen(tm) - 1] = '\0';
						}
						cout << "Reservation on Code " << booking_temp.getSpesific_resCode() << " is canceled: Seat " <<
							booking_temp.getSpesific_col() << booking_temp.getSpesific_row() << " in Movie at " << tm << "\n";
						temp_seats.remove(booking_temp.getSpesific_indexElement());
						temp_seats.insert(booking_temp.getSpesific_indexElement(), temp_flag);
						movies.remove(k);
						movies.insert(k, temp_movieObj);
						bookingList.remove(j);
						reservationCodes.remove(j);
						numOfResCode--;
					}
				}
			}
		}
	}
	if (counter != resCode.getLength()) {
		cout << "Some reservation codes do not exist. Cancelation is failed\n";
	}
}
void MovieBookingSystem::showReservation(const int resCode) const {
	// Creating temp boooking list object
	BookingList bookingList;

	// Creating temp boooking object
	Booking booking_temp;

	int resCode_index = -1;
	for (int i = 1; i <= numOfResCode; i++) {
		bookingList.retrieve(i, booking_temp);
		if (booking_temp.getSpesific_resCode() == resCode) {
			resCode_index = i;
		}
	}
	if (resCode_index == -1) {
		cout << "No reservation with Code " << resCode << "\n";
	}
	else {
		bookingList.retrieve(resCode_index, booking_temp);
		time_t movie_time = booking_temp.getSpesific_movieID();
		char* tm = ctime(&movie_time);
		if (tm[strlen(tm) - 1] == '\n') {
			tm[strlen(tm) - 1] = '\0';
		}
		cout << "Reservation with Code " << resCode << ": Seat " << booking_temp.getSpesific_col()
			<< booking_temp.getSpesific_row() << " " << tm << "\n";
	}
	if (resCode_index != -1)
		cout << "No reservation with Code " << resCode;
}