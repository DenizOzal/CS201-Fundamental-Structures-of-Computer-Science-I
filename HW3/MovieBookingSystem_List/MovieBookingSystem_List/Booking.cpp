#include "Booking.h"
Booking::Booking() {
	spesific_movieID = 0;
	spesific_row = 0;
	spesific_col = 0;
	spesific_resCode = 0;
	spesific_indexElement = 0;
}
Booking::~Booking() {
}
long Booking::getSpesific_movieID() {
	return spesific_movieID;
}
int Booking::getSpesific_row() {
	return spesific_row;
}
char Booking::getSpesific_col() {
	return spesific_col;
}
int Booking::getSpesific_resCode() {
	return spesific_resCode;
}
int Booking::getSpesific_indexElement() {
	return spesific_indexElement;
}

void Booking::setSpesific_movieID(const long movieID) {
	spesific_movieID = movieID;
}
void Booking::setSpesific_row(const int row) {
	spesific_row = row;
}
void Booking::setSpesific_col(const char col) {
	spesific_col = col;
}
void Booking::setSpesific_resCode(const int resCode) {
	spesific_resCode = resCode;
}
void Booking::setSpesific_indexElement(const int indexElement) {
	spesific_indexElement = indexElement;
}