#include "Library.hpp"

#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
  Library LTU;

  cout << "This should print 0: " << LTU.size() << endl;
  cout << "This should print 5: " << LTU.emptySlots() << endl;
  
  return 0;
}
