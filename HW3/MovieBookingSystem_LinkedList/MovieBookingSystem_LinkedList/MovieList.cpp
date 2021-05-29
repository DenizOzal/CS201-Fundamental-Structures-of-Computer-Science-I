#include "MovieList.h"
#include <cstddef>
#include <iostream>
MovieList::MovieList() : size(0), head(NULL) {

}
MovieList::MovieList(const MovieList& aList) : size(aList.size) {
    if (aList.head == NULL)
        head = NULL;  // original list is empty
    else {
        // copy first node
        head = new MovieNode;
        head->movie = aList.head->movie;
     
        // copy rest of list
        MovieNode* newPtr = head;  // new list ptr

        for (MovieNode* origPtr = aList.head->next;
            origPtr != NULL;
            origPtr = origPtr->next) {
            newPtr->next = new MovieNode;
            newPtr = newPtr->next;
            newPtr->movie = origPtr->movie;
        }
        newPtr->next = NULL;
    }
}  // end copy constructor
MovieList::~MovieList() {

    while (!isEmpty())
        remove(1);

} // end destructor
bool MovieList::isEmpty() const {

    return size == 0;

}  // end isEmpty
int MovieList::getLength() const {

    return size;

}  // end getLength
MovieList::MovieNode* MovieList::find(int index) const {
    // Locates a specified node in a linked list.
    // Precondition: index is the number of the
    // desired node.
    // Postcondition: Returns a pointer to the 
    // desired node. If index < 1 or index > the 
    // number of nodes in the list, returns NULL.

    if ((index < 1) || (index > getLength()))
        return NULL;

    else { // count from the beginning of the list
        MovieNode* cur = head;
        for (int skip = 1; skip < index; ++skip)
            cur = cur->next;
        return cur;
    }
}  // end find
bool MovieList::retrieve(int index, Movie& movie_obj) const {

    if ((index < 1) || (index > getLength()))
        return false;

    // get pointer to node, then data in node
    MovieNode* cur = find(index);
    movie_obj = cur->movie;
    return true;
} 
bool MovieList::insert(int index, Movie movie_obj) {

    int newLength = getLength() + 1;

    if ((index < 1) || (index > newLength))
        return false;

    MovieNode* newPtr = new MovieNode;
    size = newLength;
    newPtr->movie = movie_obj;

    if (index == 1) {
        newPtr->next = head;
        head = newPtr;
    }
    else {
        MovieNode* prev = find(index - 1);
        newPtr->next = prev->next;
        prev->next = newPtr;
    }
    return true;

} // end insert
bool MovieList::remove(int index) {

    MovieNode* cur;

    if ((index < 1) || (index > getLength()))
        return false;

    --size;
    if (index == 1) {
        cur = head;
        head = head->next;
    }
    else {
        MovieNode* prev = find(index - 1);
        cur = prev->next;
        prev->next = cur->next;
    }
    cur->next = NULL;
    delete cur;
    cur = NULL;

    return true;

}  // end remove
