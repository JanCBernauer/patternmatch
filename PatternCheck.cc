#include <TreeSearch.h>
#include <iostream>
using namespace std;



TreeSearch<unsigned int,6> ts("pattern.dat");

int main (int argc , char **argv)
{
  unsigned int pat=1;
  while (pat!=0)
    {
      cin>>hex>> pat;
      //cout<<pat<<endl;
      //      cout<<ts.hasMatch(pat)<<endl;
      for (int i=0;i<100000;i++)
	ts.hasMatch(pat);

    }
}
