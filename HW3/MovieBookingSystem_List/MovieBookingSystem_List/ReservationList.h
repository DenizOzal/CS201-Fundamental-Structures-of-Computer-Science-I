//ReservationList is linked list implementation of reservation codes
#pragma once
class ReservationList {
public:
	ReservationList();
	ReservationList(const ReservationList& aList);
	~ReservationList();
	bool isEmpty() const;
	int getLength() const;
	bool retrieve(int index, int& resCode) const;
	bool insert(int index, int resCode);
	bool remove(int index);
private:
	struct ReservationNode {
		int Code;
		ReservationNode* next;
	};
	int size;
	ReservationNode* head;
	ReservationNode* find(int index) const;
};