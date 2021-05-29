#include "Movie.h"
#include <cstddef>
#include <iostream>
using namespace std;
Movie::Movie() {

	movie_ID = 0;
	numOfSeats = 0;
	audienceRadius = 0;
	noOfRow = 0;
	noOfColumn = 0;
	resCode = 0;
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
int Movie::getResCode() {
	return resCode;
}
SeatList Movie::getSeatList() {
	return seats;
}
void Movie::setMovie_ID(const long movie_id) {
	movie_ID = movie_id;
}
void Movie::setAudienceRadius(const int radius_id) {
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
void Movie::setResCode(const int res_code) {
	resCode = res_code;
}
void Movie::setSeatList(const SeatList movie_seatList) {
	seats = movie_seatList;
}