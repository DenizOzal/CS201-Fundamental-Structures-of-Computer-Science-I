#pragma once
class Booking{
public:
	Booking();
	~Booking();
	long getSpesific_movieID();
	int getSpesific_row();
	char getSpesific_col();
	int getSpesific_resCode();
	int getSpesific_indexElement();
	void setSpesific_movieID(const long movieID);
	void setSpesific_row(const int row);
	void setSpesific_col(const char col);
	void setSpesific_resCode(const int resCode);
	void setSpesific_indexElement(const int indexElement);
private:
	long spesific_movieID;
	int spesific_row;
	char spesific_col;
	int spesific_resCode;
	int spesific_indexElement;
};
