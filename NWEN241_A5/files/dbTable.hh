//#ifndef __DBTABLE_HH__
//#define __DBTABLE_HH__
#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
//namespace dbTable{
  typedef struct  movie{
  char title[50];
  char director[50];
  char  year[50];
  char oscars[50];
  char country[50];
}movie;

  class AbstractDbTable{
    public:
     string rows(int i);
    //virtual bool show(const int num) = 0;
     bool add(movie a);
    //virtual bool remove(unsigned long m) = 0;
     string get();

    //bool loadCSV();
    bool loadCSV(const char *infn);
    //bool saveCSV(const char *outfn);
    vector<movie> mo;
  };
//}
//#endif
