#include "Booking.h"
// CS201
// HW1
// Deniz Semih Özal
// 21802414
// Section 01

Booking::Booking() {
	spesific_movieID = 0;
	spesific_row = 0;
	spesific_col = 0;
	spesific_resCode = 0;
}
Booking::~Booking() {
}
long Booking::getSpesific_movieID() {
	return spesific_movieID;
}
int Booking::getSpesific_row() {
	return spesific_row;
}
int Booking::getSpesific_col() {
	return spesific_col;
}
int Booking::getSpesific_resCode() {
	return spesific_resCode;
}
int Booking::getSpesific_realRow() {
	return spesific_realRow;
}
char Booking::getSpesific_realCol() {
	return spesific_realCol;
}
void Booking::setSpesific_movieID(const long movieID) {
	spesific_movieID = movieID;
}
void Booking::setSpesific_row(const int row) {
	spesific_row = row;
}
void Booking::setSpesific_col(const int col) {
	spesific_col = col;
}
void Booking::setSpesific_resCode(const int resCode){
	spesific_resCode = resCode;
}
void Booking::setSpesific_realRow(const int realRow) {
	spesific_realRow = realRow;
}
void Booking::setSpesific_realCol(const char realCol) {
	spesific_realCol = realCol;
}
