#ifndef __DBMS2_HH__
#define __DBMS2_HH__
#include <iostream>

namespace dbms2{
    struct movie {
        unsigned long id;
        char title[50];
        unsigned short year;
        char director[50];
    };
  class AbstractDbTable{
    public:

    virtual const int rows() = 0;
    virtual bool show(const int num) = 0;
    virtual bool add(movie &a) = 0;
    virtual bool remove(unsigned long m) = 0;
    virtual movie* get(const int num) = 0;

    bool loadCSV(const char *infn);
    bool saveCSV(const char *outfn);
  };
}
#endif
