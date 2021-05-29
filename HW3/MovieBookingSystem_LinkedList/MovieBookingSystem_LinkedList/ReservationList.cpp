#include "ReservationList.h" // header file   
#include <cstddef>    // for NULL

ReservationList::ReservationList() : size(0), head(NULL) {

}
ReservationList::ReservationList(const ReservationList& aList) : size(aList.size) {
    if (aList.head == NULL)
        head = NULL;  // original list is empty
    else {
        // copy first node
        head = new ReservationNode;
        head->Code = aList.head->Code;
        // copy rest of list
        ReservationNode* newPtr = head;  // new list ptr

        for (ReservationNode* origPtr = aList.head->next;
            origPtr != NULL;
            origPtr = origPtr->next) {
            newPtr->next = new ReservationNode;
            newPtr = newPtr->next;
            newPtr->Code = origPtr->Code;
        }
        newPtr->next = NULL;
    }
}  // end copy constructor
ReservationList::~ReservationList() {

    while (!isEmpty())
        remove(1);

} // end destructor
bool ReservationList::isEmpty() const {

    return size == 0;

}  // end isEmpty
int ReservationList::getLength() const {

    return size;

}  // end getLength
ReservationList::ReservationNode* ReservationList::find(int index) const {
    // Locates a specified node in a linked list.
    // Precondition: index is the number of the
    // desired node.
    // Postcondition: Returns a pointer to the 
    // desired node. If index < 1 or index > the 
    // number of nodes in the list, returns NULL.

    if ((index < 1) || (index > getLength()))
        return NULL;

    else { // count from the beginning of the list
        ReservationNode* cur = head;
        for (int skip = 1; skip < index; ++skip)
            cur = cur->next;
        return cur;
    }
}  // end find
bool ReservationList::retrieve(int index, int& resCode) const {

    if ((index < 1) || (index > getLength()))
        return false;

    // get pointer to node, then data in node
    ReservationNode* cur = find(index);
    resCode = cur->Code;

    return true;

} // end retrieve
bool ReservationList::insert( int index, int resCode) {

    int newLength = getLength() + 1;

    if ((index < 1) || (index > newLength))
        return false;

    ReservationNode* newPtr = new ReservationNode;
    size = newLength;
    newPtr->Code = resCode;

    if (index == 1) {
        newPtr->next = head;
        head = newPtr;
    }
    else {
        ReservationNode* prev = find(index - 1);
        newPtr->next = prev->next;
        prev->next = newPtr;
    }
    return true;

} // end insert
bool ReservationList::remove(int index) {

    ReservationNode* cur;

    if ((index < 1) || (index > getLength()))
        return false;

    --size;
    if (index == 1) {
        cur = head;
        head = head->next;
    }
    else {
        ReservationNode* prev = find(index - 1);
        cur = prev->next;
        prev->next = cur->next;
    }
    cur->next = NULL;
    delete cur;
    cur = NULL;

    return true;

}  // end remove

