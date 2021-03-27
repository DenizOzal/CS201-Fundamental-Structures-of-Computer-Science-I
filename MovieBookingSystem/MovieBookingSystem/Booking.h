#pragma once
// CS201
// HW1
// Deniz Semih Özal
// 21802414
// Section 01
class Booking
{
public:
	Booking();
	~Booking();
	long getSpesific_movieID();
	int getSpesific_row();
	int getSpesific_col();
	int getSpesific_realRow();
	char getSpesific_realCol();
	int getSpesific_resCode();
	void setSpesific_movieID(const long movieID);
	void setSpesific_row(const int row);
	void setSpesific_col(const int col);
	void setSpesific_resCode(const int resCode);
	void setSpesific_realRow(const int realRow);
	void setSpesific_realCol(const char realCol);

private:
	long spesific_movieID;
	int spesific_row;
	int spesific_col;
	int spesific_realRow;
	char spesific_realCol;
	int spesific_resCode;
};

