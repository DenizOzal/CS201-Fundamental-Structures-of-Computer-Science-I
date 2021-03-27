// CS201
// HW1
// Deniz Semih Özal
// 21802414
// Section 01
#define _CRT_SECURE_NO_WARNINGS
#include "Movie.h"
#include <iostream>
#include <string> 
#include <ctime>
#include <cstring>
#include <sstream>
using namespace std;
Movie::Movie() {
	movie_ID = 0;
	numOfSeats = 0;
	audienceRadius = 0;
	noOfRow = 0;
	noOfColumn = 0;
	resCode = 0;
	row = 0;
	col = 0;
	realRow = 0;
	realCol = ' ';
	seatPlan == NULL;
}

Movie::~Movie() {
	
}
long Movie::getMovie_ID() {
	return movie_ID;
}
int Movie::getAudienceRadius() {
	return audienceRadius;
}
int Movie::getNumOfSeats() {
	return numOfSeats;
}
int Movie::getNoOfRow() {
	return noOfRow;
}
int Movie::getNoOfColumn() {
	return noOfColumn;
}
string** Movie::getSeatPlan() {
	return seatPlan;
}
string Movie::getReservation(const int movie_row, const char movie_col) {
	return seatPlan[movie_row][(movie_col) - 64];
}
int Movie::getRow() {
	return row;
}
int Movie::getCol() {
	return col;
}
int Movie::getRealRow() {
	return realRow;
}
char Movie::getRealCol() {
	return realCol;
}
void Movie::setMovie_ID( const long movie_id) {
	movie_ID = movie_id;
}
void Movie::setAudienceRadius( const int radius_id) {
	audienceRadius = radius_id;
}
void Movie::setNumOfSeats(const int movie_total_seat) {
	numOfSeats = movie_total_seat;
}
void Movie::setNoOfRow(const int movie_noOfRow) {
	noOfRow = movie_noOfRow;
}
void Movie::setNoOfColumn(const int movie_noOfColumn) {
	noOfColumn = movie_noOfColumn;
}
void Movie::setRow(const int seat_row) {
	row = seat_row;
}
void Movie::setCol(const int seat_col) {
	col = seat_col;
}
void Movie::setRealRow(const int real_row) {
	realRow = real_row;
}
void Movie::setRealCol(const char real_col) {
	realCol = real_col;
}


void Movie::setSeatPlan(const int movie_noOfRow, const int movie_noOfColumn){
	// temp_seatPlan and seatPlan points same base address
	
		seatPlan = new string * [movie_noOfRow + 1];
		for (int i = 0; i < movie_noOfRow + 1; i++) {
			seatPlan[i] = new string[movie_noOfColumn + 1];
		}

		// Creating dynamic memory allocation
		 // creating one row extra for letters 

		// Creating 2d array for seatPlan

		int ch_column = 0; // int ch_column counter start from 65
		string ch = " ";  // temp char to store corresponding int according to ASCII Table
		int ch_row = 1; // for row numbers
		string c = " ";
		char c_ascii = 'A';
		// Creating portrait of a movie theatre
		for (int i = 0; i < movie_noOfRow + 1; i++) {
			for (int j = 0; j < movie_noOfColumn + 1; j++) {
				if (i == 0 && j == 0) // seatPlan[0][0] will be empty
					seatPlan[i][j] = "  ";
				else if (i == 0 && j > 0) { // seatPlan[0][j] j>0 will be letters
					ch = c_ascii;
					seatPlan[i][j] = ch;
					c_ascii = c_ascii + (getAudienceRadius() + 1);
				}
				else if (i > 0 && j == 0) { // seatPlan[i][0] i>0 will be numbers
					stringstream ss;
					ss << ch_row;
					string s;
					ss >> s;
					c = s;
					if (ch_row < 10)
						seatPlan[i][j] = " " + c;
					else
						seatPlan[i][j] = c;
					ch_row = ch_row + (getAudienceRadius() + 1);
				}
				else {	// other seats will be filled 'O'
					seatPlan[i][j] = "O";
				}
			}
		}
		this->seatPlan = seatPlan;
}
void Movie::setReservation(const int movie_id, const int movie_row, const char movie_col) {
	time_t movie_time = movie_id;
	char* tm = ctime(&movie_time);

	if (tm[strlen(tm) - 1] == '\n') {
		tm[strlen(tm) - 1] = '\0';
	}
	int temp = 0;
	int row = 0;
	int col = 0;
	int empty = 0;
	string column; 
	column = column + movie_col;
	// Changing a seat to occupied
	for (int i = 0; i < getNoOfRow() + 1; i++){
		for (int j = 0; j < getNoOfColumn() + 1; j++) {
			string s = seatPlan[i][j];
			stringstream ss(s);
			int temp2 = 0;
			ss >> temp2;
			if ((i > 0 && j == 0) && (movie_row == temp2)) { // Choosing row
				row = i;
				temp++;
			}
			else if (column == seatPlan[i][j]) { // Choosing col
				col = j;
				temp++;
			}
			else
				empty = 0;
		} 
	}
	if (temp == 2 && seatPlan[row][col] == "O") {
		seatPlan[row][col] = "X"; // Changing a seat to occupied
		setRow(row);
		setCol(col);
		setRealRow(movie_row);
		setRealCol(movie_col);
		temp = 0;
		numOfSeats--;
		setNumOfSeats(numOfSeats);
		cout << "Reservation done for " << movie_col << movie_row << " in Movie at " << tm << "\n";
	}
	else
		cout << "Seat " << movie_col << movie_row << " is not available in Movie at " << tm << "\n";
	// Decrement number of seats by one
	
}
void Movie::setSeat_toO(const int row, const int col){
	seatPlan[row][col] = "O";
	string s = seatPlan[row][0];
	stringstream ss(s);
	int temp = 0;
	ss >> temp;
	setRealRow(temp);
	char c = col + 64;
	setRealCol(c);
	numOfSeats++;
	setNumOfSeats(numOfSeats);
	this->seatPlan = seatPlan;
}


