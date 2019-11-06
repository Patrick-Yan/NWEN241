/**
 * t6test.cc
 * Sample test program for Task 6
 * This test assumes that you have completed implementation of VectorDbTable in Task 4.
 *
 * To compile with your implementation:
 * g++ t6test.cc dbms2.cc vdb.cc -o t6test
 *
 * If successful, executable file t5test should have been
 * created.
 */

#include <iostream>
#include <fstream>
#include "vdb.hh"


using namespace std;
using namespace dbms2;


struct movie movies[] = {
    { 13, "The Shawshank Redemption", 1994, "Frank Darabont" },
    { 25, "The Godfather", 1972, "Francis Ford Coppola" },
    { 31, "The Dark Knight", 2008, "Christopher Nolan" },
    { 40, "The Godfather: Part II", 1974, "Francis Ford Coppola" },
    { 55, "The Lord of the Rings: The Return of the King", 2003, "Peter Jackson" },
    { 72, "Pulp Fiction", 1994, "Quentin Tarantino" }
};

#define CSV_CONTENTS    "13,The Shawshank Redemption,1994,Frank Darabont\n"\
                        "25,The Godfather,1972,Francis Ford Coppola\n"\
                        "31,The Dark Knight,2008,Christopher Nolan\n"\
                        "40,The Godfather: Part II,1974,Francis Ford Coppola\n"\
                        "55,The Lord of the Rings: The Return of the King,2003,Peter Jackson\n"\
                        "72,Pulp Fiction,1994,Quentin Tarantino"  


void addMovies(VectorDbTable *db)
{
    for(unsigned long i=0; i<sizeof(movies)/sizeof(movie); i++)
        db->add(movies[i]);
}

void dumpFile(const char *fn)
{
    string line;
    ifstream inf(fn);

    if (inf.is_open()) {
        while ( getline (inf, line) ) {
            cout << line << endl;
        }
        inf.close();
    }    
}


int main(void)
{
    VectorDbTable *db;
    bool r;
    
    cout << "Instantiating VectorDbTable..." << endl;
    db = new VectorDbTable();
    
    cout << "Adding 6 entries..." << endl;
    addMovies(db);
    cout << "Expected : rows = 6" << endl;
    cout << "Actual   : rows = " << db->rows() << endl;
    
    cout << "Invoking saveCSV(\"testsave.csv\")..." << endl;
    r = db->saveCSV("testsave.csv");
    cout << "Expected return value: 1" << endl;
    cout << "Actual return value  : " << r << endl;   
    
    cout << endl << "Expected contents of testsave.csv file: " << endl;
    cout << CSV_CONTENTS << endl;
        
    cout << endl << "Actual contents of testsave.csv file: " << endl;
    dumpFile("testsave.csv");
    
    cout << endl << "Freeing VectorDbTable..." << endl;
    delete db;
    
    return 0;
}
