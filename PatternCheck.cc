#include <TreeSearch.h>
#include <iostream>
using namespace std;



TreeSearch<unsigned int,6> ts("pattern.dat");

int main (int argc , char **argv)
{
  unsigned int pat;
  cin>>hex>> pat;
  cout<< ts.hasMatch(pat)<<endl;

}
