#include <iostream>
#include "dbTable.hh"
//#include "vdb.hh"
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
//using namespace dbTable;
//using namespace vdb;
#include <cstdlib>
#include <cstring>
//using namespace dbms;

//typedef struct movie movie_t;

using namespace std;

bool AbstractDbTable::loadCSV(const char *infn){
  FILE *fileIn = fopen(infn, "r");
  // Input file stream to read csv
  ifstream csv;
  // Declare a vector of movie_t for holding the records
  vector<movie> movies;
  csv.open(infn);
  if(!csv.is_open()){
    printf("Failed to open default.csv\n" );
    return false;
  }
  while(!feof(fileIn)) {
    struct movie m;
    fscanf(fileIn, "%[^,] ,%[^,] ,%49s ,%49s ,%[^\n]%*[c|\n]", m.title, m.director, m.year, m.oscars, m.country);
  add(m);  // use add() function
  }
  fclose(fileIn);
  return true;
}

bool AbstractDbTable::add(movie a){
   mo.push_back(a);
   return true;
  }

string AbstractDbTable::rows(int i){
  if (i < 0 || i >= 25) {
    return "NULL";  // out of boundary
  }
  string movie = to_string(i);
  string title(mo[i].title);
  string director(mo[i].director);
  string year((mo[i].year));
  string oscars((mo[i].oscars));
  string country(mo[i].country);
  movie =movie + title + ", " + year + ", " + director + ", " + oscars + ", " + country + "\n";
  return movie;
    }
 string AbstractDbTable::get(){
   string str = "";
 	for (int i=0;i<25;i++) {
 		str += rows(i);
 	}
 	return str;
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
