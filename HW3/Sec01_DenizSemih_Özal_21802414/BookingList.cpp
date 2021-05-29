#include "BookingList.h"
#include <cstddef>
#include "Booking.h"
BookingList::BookingList() : size(0), head(NULL) {

}
BookingList::BookingList(const BookingList& aList) : size(aList.size) {
    if (aList.head == NULL)
        head = NULL;  // original list is empty
    else {
        // copy first node
        head = new BookingNode;
        head->booking = aList.head->booking;

        // copy rest of list
        BookingNode* newPtr = head;  // new list ptr

        for (BookingNode* origPtr = aList.head->next;
            origPtr != NULL;
            origPtr = origPtr->next) {
            newPtr->next = new BookingNode;
            newPtr = newPtr->next;
            newPtr->booking = origPtr->booking;
        }
        newPtr->next = NULL;
    }
}  // end copy constructor
BookingList::~BookingList() {

    while (!isEmpty())
        remove(1);

} // end destructor
bool BookingList::isEmpty() const {

    return size == 0;

}  // end isEmpty
int BookingList::getLength() const {

    return size;

}  // end getLength
BookingList::BookingNode* BookingList::find(int index) const {
    // Locates a specified node in a linked list.
    // Precondition: index is the number of the
    // desired node.
    // Postcondition: Returns a pointer to the 
    // desired node. If index < 1 or index > the 
    // number of nodes in the list, returns NULL.

    if ((index < 1) || (index > getLength()))
        return NULL;

    else { // count from the beginning of the list
        BookingNode* cur = head;
        for (int skip = 1; skip < index; ++skip)
            cur = cur->next;
        return cur;
    }
}  // end find
bool BookingList::retrieve(int index, Booking& booking_obj) const {

    if ((index < 1) || (index > getLength()))
        return false;

    // get pointer to node, then data in node
    BookingNode* cur = find(index);
    booking_obj = cur->booking;

    return true;

} // end retrieve
bool BookingList::insert(int index, Booking booking_obj) {

    int newLength = getLength() + 1;

    if ((index < 1) || (index > newLength))
        return false;

    BookingNode* newPtr = new BookingNode;
    size = newLength;
    newPtr->booking = booking_obj;

    if (index == 1) {
        newPtr->next = head;
        head = newPtr;
    }
    else {
        BookingNode* prev = find(index - 1);
        newPtr->next = prev->next;
        prev->next = newPtr;
    }
    return true;

} // end insert
bool BookingList::remove(int index) {

    BookingNode* cur;

    if ((index < 1) || (index > getLength()))
        return false;

    --size;
    if (index == 1) {
        cur = head;
        head = head->next;
    }
    else {
        BookingNode* prev = find(index - 1);
        cur = prev->next;
        prev->next = cur->next;
    }
    cur->next = NULL;
    delete cur;
    cur = NULL;

    return true;

}  // end remove
