//BookingList Class is a linked list implementation of bookings
#pragma once
#include "Booking.h"
class BookingList {
public:
	BookingList();
	BookingList(const BookingList& aList);
	~BookingList();
	bool isEmpty() const;
	int getLength() const;
	bool retrieve(int index, Booking& booking_obj) const;
	bool insert(int index, Booking booking_obj);
	bool remove(int index);
private:
	struct BookingNode {
		Booking booking;
		BookingNode* next;
	};
	int size;
	BookingNode* head;
	BookingNode* find(int index) const;
};