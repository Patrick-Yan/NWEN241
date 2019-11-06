
#ifndef __DBMS_HH__
#define __DBMS_HH__
#include <iostream>

namespace dbms{
struct album{
  unsigned long id;
  char title[100];
  unsigned short year;
  char artist[100];
};

class DbTable{
private:
  album* table;
  unsigned int rowsTotal;
  unsigned int rowsUsed;
public:
  unsigned int rows();
  unsigned int allocated();
  ~DbTable();//destructors
  DbTable();
  bool add(album &a);
  bool show(unsigned int num);
};
}
#endif
