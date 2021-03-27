// CS201
// HW1
// Deniz Semih Özal
// 21802414
// Section 01
#ifndef MOVIE_H
#define MOVIE_H
#include<string> 
#include <iostream>
#include "Booking.h"
using namespace std;
class Movie{
public:
	Movie();
	~Movie();
	long getMovie_ID();
	int getAudienceRadius();
	int getNumOfSeats();
	int getNoOfRow();
	int getNoOfColumn();
	int getRealRow();
	char getRealCol();
	string getReservation(const int movie_row, const char movie_col);
	string** getSeatPlan();
	int getRow();
	int getCol();
	void setRow(const int row);
	void setCol(const int col);
	void setMovie_ID( const long movie_id);
	void setAudienceRadius( const int movie_radius);
	void setNumOfSeats(const int movie_total_seat);
	void setNoOfRow( const int movie_noOfRow);
	void setNoOfColumn( const int movie_noOfColumn);
	void setSeatPlan(const int movie_noOfRow, const int movie_noOfColumn);
	void setReservation(const int movie_id, const int movie_row, const char movie_col);
	void setSeat_toO(const int row, const int col);
	void setRealRow(const int real_row);
	void setRealCol(const char real_col);
	string** seatPlan;

private:
	long movie_ID;
	int numOfSeats;
	int audienceRadius;
	int noOfRow;
	int noOfColumn;
	int resCode;
	int row;
	int col;
	int realRow;
	char realCol;
};
#endif 

