#include "Movie.h"
class MovieList {
public:
	MovieList();
	MovieList(const MovieList& aList);
	~MovieList();
	bool isEmpty() const;
	int getLength() const;
	bool retrieve(int index, Movie& movie_obj) const;
	bool insert(int index, Movie movie_obj);
	bool remove(int index);
private:
	struct MovieNode {
		Movie movie;
		MovieNode* next;
	};
	int size;
	MovieNode* head;
	MovieNode* find(int index) const;
};