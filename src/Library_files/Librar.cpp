#include "Library.hpp"

#include <iostream>
#include <fstream>
using namespace std;

//create library with a capacity of 5 books
Library::Library(istream &is)
{
    _books = new Book[5];
    _numBooks = 0;
    _capacity = 5;
    is >> *this;   
}


//search for value in array
Book* Library::find(const Book &b) 
{
    for(int i = 0; i < _numBooks; i++){
        if(_books[i] == b){
            return &_books[i];
        }
    }
    return nullptr;
}

//if book is found, add to bookFound
Book* Library::checkOut(const Book &b) 
{
   Book* bookFound = find(b);
   if(bookFound)
   {
        bookFound->operator++();
        return bookFound;
   }
return nullptr;
}

//copies book from "libr" to *this library
//returns a reference to *this library
Library& Library::operator=(const Library &libr)
{
    clear(); 
        for(int i = 0; i < libr._numBooks; i++)
        {
            _numBooks += libr._numBooks; 
            _books[i] = libr._books[i];
        }
    
    return *this;
}


Library& Library::operator+=(const Book &b)
{
//see if book already exists, if so dont add
for(int i = 0; i < _numBooks; i++)
{
    if(_books[i] == b)
    {
        return *this;
    }
}

//allocate more space for the library and delete old array
if(_numBooks >= _capacity)
{
    int size = _capacity * 2;
    Book* moreBooks = new Book[size];
    for(int i = 0; i < _numBooks; i++)
    {
        moreBooks[i] = _books[i];
    }

    moreBooks[_numBooks] = b;
    delete[] _books;
    _books = moreBooks;
    _capacity = size;
} else {
    _books[_numBooks] = b;
}

_numBooks++;
return *this;

}

//add books to new library
Library& Library::operator+=(const Library &libr)
{
    for(int i = 0; i < libr._numBooks; i++)
    {
        *this += libr._books[i];
    }
    return *this;
}

//removes book from library and shifts all the other books to fill the gap
Library& Library::operator-=(const Book &b)
{
    for(int i = 0; i < _numBooks; i++)
    {
        if(_books[i] == b)
        {
            for(int j = i; j < _numBooks - 1; j++)
            {
                _books[j] = _books[j + 1];
            }
            _numBooks--;
            break;
        }
        
    }
    return *this;
}

//adds book from other library to this library
Library& Library::operator+(const Library &libr)
{
    Library added = *this;
    for(int i = 0; i < libr._numBooks; i++)
    {
        added += libr._books[i];
    }
    return *this;
}

//reading in library books
istream& Library::read(istream &is)
{
    Book b;
    is >> b;
    while(is)
    {
       (*this) += b;
       is >> b;
    }
    return(is);
}

//outputs library books
ostream& Library::print(ostream &os) const
{
    for(int i = 0; i < _numBooks; i++)
    {
        os << _books[i] << endl;
    }
    return(os);
}

//Overload >> operator
istream& operator>>(istream &is, Library &libr)
{
    return libr.read(is);
}

//Overload << operator
ostream& operator<<(ostream &os, const Library &libr)
{
    return libr.print(os);
}
