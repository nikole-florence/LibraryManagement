#include "Library.hpp"
#include "Book.hpp"

#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
  string fname;

  if (argc!=2)
    fname="lib1.data";
  else
    fname=argv[1];

  ifstream inputStream(fname);

  if (!inputStream)
    cout << "ERROR: Could not find data file: '" << fname << "'" << endl
         << "  make sure to place file in proper directory (folder.)" << endl;
  else
  {
    Library fromFile(inputStream);
    cout << fromFile;
  }

  return 0;
}
