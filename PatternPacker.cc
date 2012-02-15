#include <TreeSearch.h>
#include <iostream>
#include<vector>
#include<map>
#include <cmath>
#include<fstream>
using namespace std;


#define levels 6

// this program reads a list of these
typedef  unsigned int patType;

// and compiles a pattern

typedef TreeSearch<patType,levels>::entry entry;





map<patType,vector<patType> > tree[levels];

patType masks[levels];

vector<entry>entries;

void writekey(int lv,patType pat)
{
  int pos;
  cout<<"In Writekey level "<<lv<<endl;
  if (lv==0)
    {
      for (int i=0;i<tree[0][pat].size();i++)
	{
	  entry e;
	  e.pattern=pat;
	  e.skipto=entries.size();
	  entries.push_back(e);
	}
      entries[entries.size()-1].skipto=0;
      return;
    }
  cout<<"At level "<<lv<<" will go through "<<tree[lv][pat].size()<<endl;
  for (int i=0;i<tree[lv][pat].size();i++)
    {
      entry e;
      e.pattern=tree[lv][pat][i];
      entries.push_back(e);
      pos=entries.size()-1;
      writekey(lv-1,e.pattern);
      entries[pos].skipto=entries.size();
    }
  entries[pos].skipto=0;
}

int main()
{
  patType pat;
  // first, read all patterns (HEX CODE!)
  while (cin.good())
    {
      cin>>hex>> pat;
      tree[0][pat].push_back(pat);
    }

  // create masks
  patType mask=1;
  cout<<hex<<showbase<<"Masks:"<<endl;

  for (int i=levels-1;i>=0;i--)
    {
      masks[i]=mask;
      cout<<i<<" "<<mask<<endl;
      mask|=mask<<((int) pow(2.0,i-1));
    }
  unsigned int shift=1;

  for (int i=0;i<levels-1;i++)
    {
      for (map<patType,vector<patType> >::iterator iter=tree[i].begin() ;iter!=tree[i].end();iter++)
	{
	  patType b=iter->first;
	  patType a=(b | (b>>shift)) & masks[i+1];
	  cout<< i<< " "<<shift<<" B -> A: "<<b<<" -> "<<a<<endl;
	  tree[i+1][a].push_back(b);
	  //      tree[i+1].insert(pair<patType,patType>(a,b))
	}
      shift*=2;
      cout<<endl;
    }

  //now we have to assemble the entry list.
  cout<<"Starting writekey"<<endl;
  writekey(levels-1,1);
  cout<<dec<<endl;
  for (int i=0;i<entries.size();i++)
    cout<<i<< " "<<hex<<entries[i].pattern<<dec<<" "<<entries[i].skipto<<endl;
  //dumping 
  ofstream off("pattern.dat");

  for (int i=0;i<entries.size();i++)
    off.write((const char *)&entries[i],sizeof(entry));
  off.close();
  

}
