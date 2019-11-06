
#ifndef __VDB_HH__
#define __VDB_HH__
#include <vector>
#include <iostream>
#include <string.h>
#include "dbms2.hh"

//using namespace dbms2;
using namespace std;
namespace dbms2 {

class VectorDbTable : public AbstractDbTable{
private:
  vector<movie> m;
public:
//  vector<movie> m;

  // VectorDbTable();
  // ~VectorDbTable();
  const int rows();
  bool show(const int num);
  bool add(movie &a);
  bool remove(unsigned long l);
  movie* get(const int num);

  //void addMovies(VectorDbTable *db);
  //void dumpFile(const char *fn);
};
}
#endif
