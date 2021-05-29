//SeatList is a linked list implementation of seats
#pragma once
class SeatList{
public:
	SeatList();
	SeatList(const SeatList& aList);
	~SeatList();
	bool isEmpty() const;
	int getLength() const;
	bool retrieve(int index, int& seats_obj) const;
	bool insert(int index, int seats_obj);
	bool remove(int index);
	SeatList& operator=(const SeatList& copyList);
private:
	struct SeatListNode {
		int seats;
		SeatListNode* next;
	};
	int size;
	SeatListNode* head;
	SeatListNode* find(int index) const;
};