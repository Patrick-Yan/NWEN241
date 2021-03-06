#include <iostream>
#include "dbms2.hh"
#include "vdb.hh"
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
using namespace dbms2;
//using namespace vdb;
#include <cstdlib>
#include <cstring>
//using namespace dbms;
typedef struct movie movie_t;
using namespace std;

bool AbstractDbTable::loadCSV(const char *infn){
  // Input file stream to read csv
  ifstream csv;
  // Declare a vector of movie_t for holding the records
  vector<movie_t> movies;
  csv.open(infn);
  if(!csv.is_open()){
    printf("Failed to open default.csv\n" );
    return false;
  }
    // Variable to hold a record
  movie_t mo;
  // Parse CSV file and load records
  while(!csv.eof()){
    string t;
    if(!getline(csv,t,','))break;
    mo.id = atoi(t.c_str());
    if(!getline(csv,t,','))break;
    strncpy(mo.title,t.c_str(),t.length());
    if(!getline(csv,t,','))break;
    mo.year = atoi(t.c_str());
    if(!getline(csv,t))break;
    strncpy(mo.director,t.c_str(),t.length());
    add(mo);
  }

  return true;
  csv.close();
}

//I have to comment saveCSV below cause there are thousands of error ,test5 won't work unless I comment saveCSV T T

// bool saveCSV(const char *outfn){
//
//     // Input file stream to write csv
//     ofstream csv;
//     // Declare a vector of movie_t for holding the records
//     vector<movie_t> movies;
//     csv.open(outfn);
//
//     if(!csv.is_open()){
//       printf("Failed to open default.csv\n" );
//       return false;
//     }
//       // Variable to hold a record
//     movie_t mo;
//     // Parse CSV file and save records
//     while(!csv.eof()){
//       out << "13,The Shawshank Redemption,1994,Frank Darabont\n";
//       out <<"25,The Godfather,1972,Francis Ford Coppola\n"\
//       out <<"31,The Dark Knight,2008,Christopher Nolan\n"\
//       out <<"40,The Godfather: Part II,1974,Francis Ford Coppola\n"\
//       out <<"55,The Lord of the Rings: The Return of the King,2003,Peter Jackson\n"\
//       out <<"72,Pulp Fiction,1994,Quentin Tarantino"
//   }
//
//   return true;
//   csv.close();
// }
