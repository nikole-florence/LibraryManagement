#include "Library.hpp"
#include "Book.hpp"

#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
  Library LTU;
  cout << "=======Should Be Empty==========" << endl
       << LTU
       << "================================" << endl; 

  cout << "This should print 0: " << LTU.size() << endl;
  cout << "This should print 5: " << LTU.emptySlots() << endl;

  Book hgttg("Hitchhiker's Guide to the Galaxy", "Adams", 1980);
  Book rateotu("Restaurant at the End of the Universe", "Adams", 1982);

  LTU+=hgttg;
  LTU+=rateotu;

  cout << "=======Should Have 2 Books==========" << endl
       << LTU
       << "====================================" << endl; 
  cout << "This should print 2: " << LTU.size() << endl;
  cout << "This should print 3: " << LTU.emptySlots() << endl;

  Book slatfatf("So Long and Thanks for All the Fish", "Adams", 1986);
  Book mh("Mostly Harmless", "Adams", 1989); 
  Book dg("Dirk Genty's Holistic Detective Agency", "Adams", 1987);

  LTU +=slatfatf;
  LTU +=mh;
  LTU +=dg;

  cout << "=======Should Have 5 Books==========" << endl
       << LTU
       << "====================================" << endl; 
  cout << "This should print 5: " << LTU.size() << endl;
  cout << "This should print 0: " << LTU.emptySlots() << endl;

  Book ldtots("Long Dark Teatime of the Soul", "Adams", 1990);

  LTU += ldtots;

  cout << "=======Should Have 6 Books==========" << endl
       << LTU
       << "====================================" << endl; 
  cout << "This should print 6: " << LTU.size() << endl;
  cout << "This should print 4: " << LTU.emptySlots() << endl;

  return 0;
}
