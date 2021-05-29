#include "SeatList.h"
#include <cstddef>
#include <iostream>
SeatList::SeatList() : size(0), head(NULL) {

}
SeatList::SeatList(const SeatList& aList) : size(aList.size) {
    if (aList.head == NULL)
        head = NULL;  // original list is empty
    else {
        // copy first node
        head = new SeatListNode;
        head->seats = aList.head->seats;

        // copy rest of list
        SeatListNode* newPtr = head;  // new list ptr

        for (SeatListNode* origPtr = aList.head->next;
            origPtr != NULL;
            origPtr = origPtr->next) {
            newPtr->next = new SeatListNode;
            newPtr = newPtr->next;
            newPtr->seats = origPtr->seats;
        }
        newPtr->next = NULL;
    }
}  // end copy constructor
SeatList::~SeatList() {

    while (!isEmpty())
        remove(1);

} // end destructor
bool SeatList::isEmpty() const {

    return size == 0;

}  // end isEmpty
int SeatList::getLength() const {

    return size;

}  // end getLength
SeatList::SeatListNode* SeatList::find(int index) const {
    // Locates a specified node in a linked list.
    // Precondition: index is the number of the
    // desired node.
    // Postcondition: Returns a pointer to the 
    // desired node. If index < 1 or index > the 
    // number of nodes in the list, returns NULL.

    if ((index < 1) || (index > getLength()))
        return NULL;

    else { // count from the beginning of the list
        SeatListNode* cur = head;
        for (int skip = 1; skip < index; ++skip) {
            cur = cur->next;
        }
        return cur;
    }
}  // end find
bool SeatList::retrieve(int index, int& seats_obj) const {

    if ((index < 1) || (index > getLength()))
        return false;

    // get pointer to node, then data in node
    SeatListNode* cur = find(index);
    seats_obj = cur->seats;

    return true;

} // end retrieve
bool SeatList::insert(int index, int seats_obj) {

    int newLength = getLength() + 1;

    if ((index < 1) || (index > newLength))
        return false;

    SeatListNode* newPtr = new SeatListNode;
    size = newLength;
    newPtr->seats = seats_obj;

    if (index == 1) {
        newPtr->next = head;
        head = newPtr;
    }
    else {
        SeatListNode* prev = find(index - 1);
        newPtr->next = prev->next;
        prev->next = newPtr;
    }
    return true;

} // end insert
bool SeatList::remove(int index) {

    SeatListNode* cur;

    if ((index < 1) || (index > getLength()))
        return false;

    --size;
    if (index == 1) {
        cur = head;
        head = head->next;
    }
    else {
        SeatListNode* prev = find(index - 1);
        cur = prev->next;
        prev->next = cur->next;
    }
    cur->next = NULL;
    delete cur;
    cur = NULL;

    return true;

}  // end remove
SeatList& SeatList::operator=(const SeatList& copyList)
{
    SeatList tmp;
    SeatListNode** dst = &tmp.head;
    const SeatListNode* src = copyList.head;
    while (src)
    {
        *dst = new SeatListNode(*src);     // invoke Node copy-ctor
        src = src->next;           // advance source
        (*dst)->next = nullptr;    // break link to original next
        dst = &(*dst)->next;       // move target to next pointer
    }

    // tmp now has a copy of the source list
    //  swap its head pointer with ours.
    std::swap(tmp.head, head);

    // upon return, the tmp object that now holds our
    //  original list will clean it up. we own the
    //  new list form this point on. 
    return *this;
}