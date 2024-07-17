#include "Book.hpp"

#include <iostream>

using namespace std;

// prints out Book b (including checkout data) to stream
//   note that this uses something cool - if os (second
//   parameter) is not specified in call, then it defaults
//   to be cout.
void prettyPrint(const Book &b, ostream &os=cout)
{
  os << "    Title:" << b.title() << endl
     << "   Author:" << b.author() << endl
     << "     Year:" << b.year() << endl
     << "Checkouts:" << b.checkouts() << endl;
}


int main(int argc, char *argv[])
{
  Book hgttg("Hitchhiker's Guide to the Galaxy", "Adams", 1980);

  cout << hgttg << endl;

  Book rateotu("Restaurant at the End of the Universe", "Adams", 1982);
  cout << rateotu << endl;

  if (hgttg < rateotu) 
    cout << hgttg << " IS LESS THAN " << rateotu << endl;
  else
    cout << hgttg << " IS NOT LESS THAN " << rateotu << endl;

  if (hgttg > rateotu) 
    cout << hgttg << " IS GREATER THAN " << rateotu << endl;
  else
    cout << hgttg << " IS NOT GREATER THAN " << rateotu << endl;

  if (hgttg == rateotu) 
    cout << hgttg << " IS EQUAL TO " << rateotu << endl;
  else
    cout << hgttg << " IS NOT EQUAL TO " << rateotu << endl;

  if (hgttg != rateotu) 
    cout << hgttg << " IS INEQUAL TO " << rateotu << endl;
  else
    cout << hgttg << " IS NOT INEQUAL TO " << rateotu << endl;

  prettyPrint(hgttg);
  prettyPrint(rateotu);
  
  cout << "please enter a book (author last name, year, title)";
  Book myBook;
  cin >> myBook;
  cout << "You gave:" << endl;
  prettyPrint(myBook);

  // let's go ahead and checkout the book that was just entered. 
  ++myBook;
  prettyPrint(myBook);
  
  return 0;
}
