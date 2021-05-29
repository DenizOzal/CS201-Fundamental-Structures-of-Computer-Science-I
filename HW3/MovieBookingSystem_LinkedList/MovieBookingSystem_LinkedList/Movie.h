#pragma once
#include "SeatList.h"
using namespace std;
class Movie {
public:
	Movie();
	~Movie();
	long getMovie_ID();
	int getAudienceRadius();
	int getNumOfSeats();
	int getNoOfRow();
	int getNoOfColumn();
	int getResCode();
	SeatList getSeatList();
	void setMovie_ID(const long movie_id);
	void setAudienceRadius(const int movie_radius);
	void setNumOfSeats(const int movie_total_seat);
	void setNoOfRow(const int movie_noOfRow);
	void setNoOfColumn(const int movie_noOfColumn);
	void setResCode(const int res_code);
	void setSeatList(const SeatList movie_seatList);

private:
	SeatList seats;
	long movie_ID;
	int numOfSeats;
	int audienceRadius;
	int noOfRow;
	int noOfColumn;
	int resCode;
};

