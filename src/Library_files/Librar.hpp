#ifndef _LIBRARY_HPP_
#define _LIBRARY_HPP_
#include "Book.hpp"

#include <iostream>
#include <string>

using namespace std;

//set variables for the class Library
class Library{
private:
Book* _books;
int _numBooks;
int _capacity;

//initialize library
public:
Library(): _books(new Book[5]), _numBooks(0), _capacity(5){}
Library(istream &is);

//functions and what they return
int size() const {return _numBooks;}
int emptySlots() const {return _capacity - _numBooks;}
void clear(){_numBooks = 0;}
Book*find(const Book &b);
Book*checkOut(const Book &b);

//overload operators
Library& operator=(const Library &libr);
Library& operator+=(const Book &b);
Library& operator+=(const Library &libr);
Library& operator-=(const Book &b);
Library& operator+(const Library &libr);


//read and print functions
istream& read(istream &is);
ostream& print(ostream &os) const;
};

//Overload >> operator
istream& operator>>(istream &is, Library &libr);

//Overload << operator
ostream& operator<<(ostream &os, const Library &libr);

#endif

